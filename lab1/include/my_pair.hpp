#pragma once

#include <iostream>
#include <string>

template <typename K, typename V>
class TPair {
    private:
        K _key;
        V _value;
    public:
        friend std::ostream& operator<<(std::ostream &os, const TPair &pair) {
            os << pair.Key() << ' ' << pair.Value() << '\n';
            return os;
        }
        TPair() = default;
        TPair(const K &k, const V &v);
        const K& Key() const;
        const V& Value() const;
        K& Key();
        V& Value();
        TPair<K,V> &operator=(const TPair<K,V> &other);
        TPair<K,V> &operator=(TPair<K,V> &&other) noexcept;
};

template <typename K, typename V> 
TPair<K,V>::TPair(const K &k, const V &v) : _key(k) {
    _value = v;
}

template <typename K, typename V>
const K &TPair<K,V>::Key() const {
    return _key;
}

template <typename K, typename V>
const V &TPair<K,V>::Value() const {
    return _value;
}

template <typename K, typename V>
K &TPair<K,V>::Key() {
    return _key;
}

template <typename K, typename V>
V &TPair<K,V>::Value() {
    return _value;
}

template <typename K, typename V>
TPair<K,V> &TPair<K,V>::operator=(const TPair<K,V> &other) {
    _key = other._key;
    _value = other._value;
    // std::cout << "copyied val in pair\n";
    std::cout << _value << std::endl;
    return *this;
}

template <typename K, typename V>
TPair<K,V> &TPair<K,V>::operator=(TPair<K,V> &&other) noexcept{
    // std::cout << "swapped val in pair\n";
    std::swap(_key,other._key);
    std::swap(_value,other._value);
    return *this;
}