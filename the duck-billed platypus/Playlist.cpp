#include "Playlist.h"

bool Playlist::Song_Entry::set_id(int id) {
    _id = id;
    return true; // 假设总是成功，根据实际需求调整
}

bool Playlist::Song_Entry::set_name(const std::string& name) {
    _name = name;
    return true; // 假设总是成功，根据实际需求调整
}

// Implement Node's insert_next and remove_next methods
Playlist::Node* Playlist::Node::insert_next(Node* p) {
    p->_next = this->_next;
    this->_next = p;
    return p;
}

Playlist::Node* Playlist::Node::remove_next() {
    if (!_next) return nullptr;
    Node* toRemove = _next;
    _next = _next->_next;
    delete toRemove; // Free the memory
    return this; // Return the current node after removal
}

// Playlist constructor
Playlist::Playlist() : _size(0) {
    _head = new Node(); // Creates a sentinel node
    _tail = _head;
    _prev_to_current = _head;
}

// Playlist destructor
Playlist::~Playlist() {
    clear(); // Clears the list
    delete _head; // Deletes the sentinel node
}

// Clear the playlist
Playlist* Playlist::clear() {
    // Corrected to use get_next() instead of non-existent _getnext
    while (_head->get_next() != nullptr) {
        remove_at_cursor(); // This function needs to adjust _size accordingly
    }
    return this;
}

// Rewind the playlist cursor to the start
Playlist* Playlist::rewind() {
    _prev_to_current = _head;
    return this;
}

// Push a song to the back of the playlist
Playlist* Playlist::push_back(const Song_Entry& s) {
    Node* newNode = new Node(s);
    _tail->insert_next(newNode);
    _tail = newNode;
    _size++;
    return this;
}

// Push a song to the front of the playlist
Playlist* Playlist::push_front(const Song_Entry& s) {
    Node* newNode = new Node(s);
    newNode->set_next(_head->get_next()); // Modified to use set_next()
    if (_head->get_next() == nullptr) { // Modified to use get_next()
        _tail = newNode;
    }
    _head->set_next(newNode); // Modified to use set_next()
    _size++;
    return this;
}

// Insert a song at the cursor's position
Playlist* Playlist::insert_at_cursor(const Song_Entry& s) {
    if (_prev_to_current == _tail) {
        return push_back(s);
    }
    Node* newNode = new Node(s);
    _prev_to_current->insert_next(newNode);
    if (_prev_to_current == _tail) {
        _tail = newNode;
    }
    _size++;
    return this;
}

// Remove the song at the cursor's position
Playlist* Playlist::remove_at_cursor() {
    // Use get_next() for checking and accessing the _next node
    if (_prev_to_current->get_next() == nullptr) return this; // Nothing to remove

    Node* toRemove = _prev_to_current->get_next();
    if (toRemove == _tail) {
        _tail = _prev_to_current;
    }
    _prev_to_current->set_next(toRemove->get_next()); // Adjust the next pointer to skip the removed node
    delete toRemove; // Free the removed node
    _size--;

    return this;
}

// Advance the cursor in the playlist
Playlist* Playlist::advance_cursor() {
    // 使用 get_next() 替代直接访问 _next
    if (_prev_to_current->get_next() == _tail) return nullptr; // 无法前进到列表末尾之后
    _prev_to_current = _prev_to_current->get_next();
    return this;
}

// Advance the cursor in the playlist circularly
Playlist* Playlist::circular_advance_cursor() {
    // 使用 get_next() 替代直接访问 _next
    if (_prev_to_current->get_next() == _tail) {
        _prev_to_current = _head; // 循环移动
    } else {
        _prev_to_current = _prev_to_current->get_next();
    }
    return this;
}

// Find a song by ID
Playlist::Song_Entry& Playlist::find_by_id(int id) const {
    Node* current = _head->get_next(); // 使用 get_next()
    while (current != nullptr) {
        if (current->get_song().get_id() == id) {
            return current->get_song();
        }
        current = current->get_next();
    }
    return _head->get_song(); // 如果未找到，返回哨兵节点中的歌曲
}

// Find a song by name
Playlist::Song_Entry& Playlist::find_by_name(const string& songName) const {
    Node* current = _head->get_next(); // 使用 get_next()
    while (current != nullptr) {
        if (current->get_song().get_name() == songName) {
            return current->get_song();
        }
        current = current->get_next();
    }
    return _head->get_song(); // 如果未找到，返回哨兵节点中的歌曲
}

//get current song
Playlist::Song_Entry& Playlist::get_current_song() const {
    // 假设 _prev_to_current 指向当前歌曲的前一个节点
    if (_prev_to_current->get_next() != nullptr && _prev_to_current->get_next() != _tail) {
        return _prev_to_current->get_next()->get_song();
    } else {
        // 如果当前没有有效的歌曲（比如列表为空），则应返回一个哨兵值或抛出异常
        // 这里，我们返回头节点的歌曲，它可以被配置为哨兵值
        return _head->get_song();
    }
}


// Convert the playlist to a string representation
   string Playlist::to_string() const {
   string result = "Playlist: ";

    // 使用 get_next() 替代直接访问 _next
    Node* current = _head->get_next(); // Start at the first real entry after the sentinel
    size_t count = 0;

    while (current != nullptr && count < 25) { // Limit to 25 entries as specified
        result += "{ id: " + std::to_string(current->get_song().get_id()) +
                  " name: \"" + current->get_song().get_name() + "\" }";
        if (current == _prev_to_current->get_next()) {
            result += " [P]";
        }
        if (current == _tail) {
            result += " [T]";
        }
        result += "\n";

        // 使用 get_next() 替代直接访问 _next
        current = current->get_next();
        count++;
    }

    if (_size > 25) {
        result += "...\n"; // Indicate more entries are present beyond the first 25
    }

    return result;
}
