#include "car_number.hpp"

TCarNumber::TCarNumber(char fp, char sp[3], char tp[2]) {
    _symbs[0] = fp;
    for (size_t i = 1; i < 4; ++i) {
        _symbs[i] = sp[i - 1];
    }
    for (size_t i = 4; i < 6; ++i) {
        _symbs[i] = tp[i - 4];
    }
    _symbs[6] = '\0';
}

TCarNumber &TCarNumber::operator=(const TCarNumber &other) {
    memcpy(_symbs, other._symbs, 6);
    return *this;
}

char &TCarNumber::operator[](size_t idx) {
    return _symbs[idx];
}

const char &TCarNumber::operator[](size_t idx) const {
    return _symbs[idx];
}

std::ostream &operator<<(std::ostream & os, const TCarNumber &num) {
    os << num[0] << ' ';
    for (size_t i = 1; i < 4; ++i) {
        os << num[i];
    }
    os << ' ';
    for (size_t i = 4; i < 6; ++i) {
        os << num[i];
    }
    return os;
}