#ifndef Tests_h
#define Tests_h

#include "Playlist.h"

class Tests {
public:
    // 测试添加歌曲到播放列表
    static bool test_push_back(const Playlist& playlist);

    // 测试从播放列表中移除歌曲
    static bool test_remove_at_cursor(Playlist& playlist);

    // 测试通过歌曲名查找歌曲
    static bool test_find_by_name(const Playlist& playlist, const std::string& songName);

    // 测试播放列表的遍历功能
    static bool test_traverse(const Playlist& playlist);

    // 您可以添加更多的测试函数
};

#endif /* Tests_h */