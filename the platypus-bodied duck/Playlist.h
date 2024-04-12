// Student ID:20511457
#ifndef Playlist_h
#define Playlist_h

#include <iostream>
#include <sstream>
#include <string>

class Playlist {
public:
    class Song_Entry {
    private:
        int _id;
        std::string _name;

    public:
        Song_Entry(int id = 0, std::string name = "Unnamed") : _id(id), _name(name) {}

        int get_id() const { return _id; }
        std::string get_name() const { return _name; }

        bool set_id(int id) {
            if (id < 0) return false;
            _id = id;
            return true;
        }

        bool set_name(std::string name) {
            if (name.empty()) return false;
            _name = name;
            return true;
        }

        bool operator==(const Song_Entry& that) const {
            return this->_id == that._id && this->_name == that._name;
        }

        bool operator!=(const Song_Entry& that) const {
            return !(*this == that);
        }

        friend std::ostream& operator<<(std::ostream& os, const Song_Entry& s) {
            return os << "{ id: " << s.get_id() << ", name: " << s.get_name() << " }";
        }

        friend class Tests;
    };

private:
    class Node {
    private:
        Song_Entry _song;
        Node* _next;

    public:
        Node(const Song_Entry& song = Song_Entry()) : _song(song), _next(nullptr) {}
        ~Node(); // Implement non-recursive destructor

        Song_Entry& get_song() { return _song; }
        Node* get_next() { return _next; }
        Node* insert_next(Node* p);
        Node* remove_next();

        friend class Tests;
    };

    Node* _head, *_tail, *_prev_to_current;
    size_t _size;

public:
    Playlist();
    ~Playlist();
    // Other methods...

    friend class Tests;
};

#endif /* Playlist_h */