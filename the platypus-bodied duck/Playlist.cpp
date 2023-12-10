#include "Playlist.h"

// Constructor
Playlist::Playlist() {
    _head = new Node(); // Sentinel node
    _tail = _head;
    _prev_to_current = _head;
    _size = 0;
}

// Destructor
Playlist::~Playlist() {
    clear(); // Clear all nodes
    delete _head; // Delete sentinel node
}

// Other methods implementation

// Insert a song at the cursor position
Playlist* Playlist::insert_at_cursor(const Song_Entry& s) {
    Node* new_node = new Node(s);
    new_node->_next = _prev_to_current->_next;
    _prev_to_current->_next = new_node;
    if (_prev_to_current == _tail) {
        _tail = new_node;
    }
    _size++;
    return this;
}

// Push a song to the back of the playlist
Playlist* Playlist::push_back(const Song_Entry& s) {
    _tail->insert_next(new Node(s));
    _tail = _tail->_next;
    _size++;
    return this;
}

// Push a song to the front of the playlist
Playlist* Playlist::push_front(const Song_Entry& s) {
    return insert_at_cursor(s);
}

// Advance the cursor to the next song
Playlist* Playlist::advance_cursor() {
    if (_prev_to_current != _tail) {
        _prev_to_current = _prev_to_current->_next;
    }
    return this;
}

// Clear the playlist
Playlist* Playlist::clear() {
    while (_head->_next) {
        Node* temp = _head->_next;
        _head->_next = _head->_next->_next;
        delete temp;
    }
    _tail = _head;
    _prev_to_current = _head;
    _size = 0;
    return this;
}

// Get the current song
Song_Entry& Playlist::get_current_song() const {
    if (_prev_to_current->_next) {
        return _prev_to_current->_next->_song;
    } else {
        static Song_Entry sentinel(-1, "_SENTINEL_");
        return sentinel;
    }
}

// Additional methods like remove_at_cursor, find_by_id, find_by_name, to_string, etc.
