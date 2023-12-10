#ifndef String_List_h
#define String_List_h

#include <iostream>
#include <sstream>
#include <string>

class String_List {
private:
    struct Node {
        std::string data;
        Node *next;
        Node(std::string s = "") : data(s), next(nullptr) {}
    };
    Node *_head, *_tail, *_prev_to_current;
    size_t _size;

public:
    String_List() {
        _head = new Node("_SENTINEL_");
        _tail = _head;
        _prev_to_current = _head;
        _size = 0;
    }

    ~String_List() {
        clear();
        delete _head;
    }

    String_List *insert_at_current(std::string s) {
        Node *new_node = new Node(s);
        new_node->next = _prev_to_current->next;
        _prev_to_current->next = new_node;
        if (_prev_to_current == _tail) {
            _tail = new_node;
        }
        _size++;
        return this;
    }

    String_List *push_back(std::string s) {
        _prev_to_current = _tail;
        insert_at_current(s);
        _prev_to_current = _head;
        return this;
    }

    String_List *push_front(std::string s) {
        _prev_to_current = _head;
        insert_at_current(s);
        _prev_to_current = _head;
        return this;
    }

    String_List *advance_current() {
        if (_prev_to_current != _tail) {
            _prev_to_current = _prev_to_current->next;
        }
        return this;
    }

    std::string get_current() const {
        if (_prev_to_current->next) {
            return _prev_to_current->next->data;
        }
        return "_SENTINEL_";
    }

    String_List *remove_at_current() {
        if (_prev_to_current->next) {
            Node *temp = _prev_to_current->next;
            _prev_to_current->next = temp->next;
            if (temp == _tail) {
                _tail = _prev_to_current;
            }
            delete temp;
            _size--;
        }
        return this;
    }

    size_t get_size() const {
        return _size;
    }

    String_List *rewind() {
        _prev_to_current = _head;
        return this;
    }

    void clear() {
        while (_head->next) {
            Node *temp = _head->next;
            _head->next = temp->next;
            delete temp;
        }
        _tail = _head;
        _prev_to_current = _head;
        _size = 0;
    }

    std::string& find_item(std::string s) const {
        static std::string sentinel = "_SENTINEL_";
        Node *current = _head->next;
        while (current) {
            if (current->data == s) {
                return current->data;
            }
            current = current->next;
        }
        return sentinel;
    }

    std::string to_string() const {
        std::stringstream ss;
        ss << "# String_List - " << _size << " entries total. Starting at cursor:\n";
        Node *current = _head->next;
        size_t count = 0;
        const size_t max_lines = 25;
        while (current && count < max_lines) {
            ss << current->data << "\n";
            current = current->next;
            count++;
        }
        if (_size > max_lines) {
            ss << "...\n";
        }
        return ss.str();
    }

    friend class Tests; // Don't remove this line
};

#endif /* String_List_h */