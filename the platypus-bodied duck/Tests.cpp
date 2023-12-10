#include <iostream>
#include <string>
#include "Playlist.h"

void test_push_back() {
    std::cout << "Test push_back..." << std::endl;
    Playlist pl;
    pl.push_back(Playlist::Song_Entry(1, "Song 1"));
    pl.push_back(Playlist::Song_Entry(2, "Song 2"));

    std::cout << "Expected playlist size: 2, Actual: " << pl.get_size() << std::endl;
    std::cout << "Expected current song: Song 1, Actual: " << pl.get_current_song().get_name() << std::endl;
}

void test_remove_at_cursor() {
    std::cout << "Test remove_at_cursor..." << std::endl;
    Playlist pl;
    pl.push_back(Playlist::Song_Entry(1, "Song 1"));
    pl.push_back(Playlist::Song_Entry(2, "Song 2"));
    pl.remove_at_cursor();

    std::cout << "Expected playlist size after removal: 1, Actual: " << pl.get_size() << std::endl;
}

void test_find_by_name() {
    std::cout << "Test find_by_name..." << std::endl;
    Playlist pl;
    pl.push_back(Playlist::Song_Entry(1, "Song 1"));
    pl.push_back(Playlist::Song_Entry(2, "Song 2"));

    std::string songName = "Song 2";
    Playlist::Song_Entry& foundSong = pl.find_by_name(songName);

    std::cout << "Expected found song name: " << songName << ", Actual: " << foundSong.get_name() << std::endl;
}

int main() {
    test_push_back();
    test_remove_at_cursor();
    test_find_by_name();

    return 0;
}
