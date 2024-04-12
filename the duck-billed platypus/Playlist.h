// Student ID: 20511457
// Important implementation note: With the exception of to_string() and find...()
// all Playlist methods below should operate in a constant amount of time
// regardless of the size of the Playlist instance.
//
// The semantics of prev_to_current is such that it always points to the
// node *BEFORE* the cursor (current). This makes the manipulations easy because
// we can only look forward (and not back) in singly linked lists.
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>

class Playlist {
public:
    class Song_Entry {
    private:
        int _id;
        std::string _name;

    public:
        Song_Entry(int id = 0, std::string name = "Unnamed");
        int get_id() const;
        std::string get_name() const;
        bool set_id(int id);
        bool set_name(const std::string& name);
    };

    class Node {
    public:
        Song_Entry _song;
        Node* _next;

        Node(const Song_Entry& song = Song_Entry(), Node* next = nullptr);
        Node* get_next() const;
        void set_next(Node* next);
        Song_Entry& get_song();
        Node* insert_next(Node* p);
        Node* remove_next();
    };

private:
    Node* _head, *_tail, *_prev_to_current;
    size_t _size;

public:
    Playlist();
    ~Playlist();
    size_t get_size() const;
    Song_Entry& get_current_song() const;
    Playlist* clear();
    Playlist* rewind();
    Playlist* push_back(const Song_Entry& s);
    Playlist* push_front(const Song_Entry& s);
    Playlist* insert_at_cursor(const Song_Entry& s);
    Playlist* remove_at_cursor();
    Playlist* advance_cursor();
    Playlist* circular_advance_cursor();
    Song_Entry& find_by_id(int id) const;
    Song_Entry& find_by_name(const std::string& songName) const;
    std::string to_string() const;

    friend class Tests; // For testing purposes, if needed
};

#endif // PLAYLIST_H