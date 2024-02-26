#pragma once

#include "my_vector.hpp"
#include <cstring>

const int CAR_NUMBER_SIZE = 6;
const int CAR_STRING_SIZE = 9;


class TCarNumber {
    private:
        char _symbs[7];
    public:
        friend std::ostream& operator<<(std::ostream &os, const TCarNumber &num); 

        TCarNumber() = default;
        TCarNumber(char fp, char sp[3], char tp[2]);

        TCarNumber &operator=(const TCarNumber &other);

        char &operator[](size_t idx);
        const char &operator[](size_t idx) const;

};