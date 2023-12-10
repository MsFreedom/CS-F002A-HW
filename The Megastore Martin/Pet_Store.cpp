// Pet_Store.cpp
#include "Pet_Store.h"
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

Pet_Store::Pet_Store(size_t n) {
    _pets.resize(n);
    _sort_order = NONE;
}

void Pet_Store::set_size(size_t n) {
    _pets.resize(n);
}

size_t Pet_Store::get_size() const {
    return _pets.size();
}

void Pet_Store::clear() {
    _pets.clear();
}

void Pet_Store::populate_with_n_random_pets(size_t n) {
    Pet::get_n_pets(n, _pets, 7);
    _sort_order = BY_ID;
}

bool Pet_Store::_id_compare(const Pet& p1, const Pet& p2) {
    return p1.get_id() < p2.get_id();
}

bool Pet_Store::_name_compare(const Pet& p1, const Pet& p2) {
    return p1.get_name() < p2.get_name();
}

void Pet_Store::_sort_pets_by_id() {
    std::sort(_pets.begin(), _pets.end(), Pet_Store::_id_compare);
    _sort_order = BY_ID;
}

void Pet_Store::_sort_pets_by_name() {
    std::sort(_pets.begin(), _pets.end(), Pet_Store::_name_compare);
    _sort_order = BY_NAME;
}

bool Pet_Store::find_pet_by_id_lin(long id, Pet& pet) {
    for (const auto& p : _pets) {
        if (p.get_id() == id) {
            pet = p;
            return true;
        }
    }
    return false;
}

bool Pet_Store::find_pet_by_name_lin(string name, Pet& pet) {
    for (const auto& p : _pets) {
        if (p.get_name() == name) {
            pet = p;
            return true;
        }
    }
    return false;
}

bool Pet_Store::find_pet_by_id_bin(long id, Pet& pet) {
    if (_sort_order != BY_ID) {
        _sort_pets_by_id();
    }
    int left = 0, right = _pets.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (_pets[mid].get_id() < id) {
            left = mid + 1;
        } else if (_pets[mid].get_id() > id) {
            right = mid - 1;
        } else {
            pet = _pets[mid];
            return true;
        }
    }
    return false;
}

bool Pet_Store::find_pet_by_name_bin(string name, Pet& pet) {
    if (_sort_order != BY_NAME) {
        _sort_pets_by_name();
    }
    int left = 0, right = _pets.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (_pets[mid].get_name() < name) {
            left = mid + 1;
        } else if (_pets[mid].get_name() > name) {
            right = mid - 1;
        } else {
            pet = _pets[mid];
            return true;
        }
    }
    return false;
}

string Pet_Store::to_string(size_t n1, size_t n2) {
    stringstream ss;
    for (size_t i = n1; i <= n2 && i < _pets.size(); ++i) {
        ss << _pets[i].to_string() << "\n";
    }
    return ss.str();
}
