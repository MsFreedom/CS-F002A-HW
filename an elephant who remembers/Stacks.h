// Student ID: 20511457
// TODO - Replace the number above with your actual student ID
//
#ifndef Stacks_h
#define Stacks_h

#include <vector>
#include <sstream>

class Stack_Int {
private:
    std::vector<int> _data;

public:
    // No explicit constructor or destructor
    size_t size() const {
        return _data.size();
    }

    bool is_empty() const {
        return _data.empty();
    }

    void push(int val) {
        _data.push_back(val);
    }

    int top(bool& success) const {
        if (_data.empty()) {
            success = false;
            return 0;
        }
        success = true;
        return _data.back();
    }

    bool pop() {
        if (_data.empty()) {
            return false;
        }
        _data.pop_back();
        return true;
    }

    bool pop(int& val) {
        if (_data.empty()) {
            return false;
        }
        val = _data.back();
        _data.pop_back();
        return true;
    }

    std::string to_string() const {
    std::stringstream ss;
    ss << "Stack (" << _data.size() << " elements):\n";
    size_t count = 0;
    for (auto it = _data.rbegin(); it != _data.rend() && count < 10; ++it, ++count) {
        ss << *it << "\n";
    }
    if (_data.size() > 10) {
        ss << "...\n";
    }
    ss << "Elements, if listed above, are in increasing order of age.";
    return ss.str();
}
    friend class Tests;
};

class Stack_String {
private:
    std::vector<std::string> _data;

public:
    // Methods are analogous to Stack_Int
    size_t size() const {
        return _data.size();
    }

    bool is_empty() const {
        return _data.empty();
    }

    void push(const std::string& val) {
        _data.push_back(val);
    }

    std::string top(bool& success) const {
        if (_data.empty()) {
            success = false;
            return "";
        }
        success = true;
        return _data.back();
    }

    bool pop() {
        if (_data.empty()) {
            return false;
        }
        _data.pop_back();
        return true;
    }

    bool pop(std::string& val) {
        if (_data.empty()) {
            return false;
        }
        val = _data.back();
        _data.pop_back();
        return true;
    }

    std::string to_string() const {
        std::stringstream ss;
        ss << "Stack (" << _data.size() << " elements):\n";
        size_t count = 0;
        for (auto it = _data.rbegin(); it != _data.rend() && count < 10; ++it, ++count) {
            ss << *it << "\n";
        }
        if (_data.size() > 10) {
            ss << "...\n";
        }
        return ss.str();
    }

    friend class Tests;
};

#endif /* Stacks_h */
