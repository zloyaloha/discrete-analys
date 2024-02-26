#include "my_pair.hpp"
#include "my_vector.hpp"
#include "car_number.hpp"

using TPairString = TPair<TCarNumber, char *>;

const int KEY_SIZE = 6;
const int AMOUNT_OF_LETTERS = 26;
const int AMOUNT_OF_DIGITS = 10;

void Print(const TVector<TPairString> vec) {
    for (size_t i = 0; i < vec.Size(); ++i) {
        std::cout << vec[i].Key() << '\t' << vec[i].Value() << '\n';
    }
    std::cout << '\n';
}

void SetZeros(TVector<int> &vec) {
    for (int i = 0; i < vec.Size(); ++i) {
        vec[i] = 0;
    }
}

bool IsDigit(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

void RadixSort(TVector<TPairString> &vec) {
    TVector<int> count;
    TVector<TPairString> out;
    out.Reserve(vec.Size());
    count.Reserve(AMOUNT_OF_LETTERS);
    int i, j, sizeCount;
    for (i = KEY_SIZE - 1; i >= 0; --i) {
        sizeCount = (IsDigit(vec[0].Key()[i]) ? AMOUNT_OF_DIGITS : AMOUNT_OF_LETTERS);
        SetZeros(count);
        for (j = 0; j < vec.Size(); ++j) {
            if (isdigit(vec[j].Key()[i])) {
                ++count[vec[j].Key()[i] - '0'];
            } else {
                ++count[vec[j].Key()[i] - 'A'];
            }
        }
        for (j = 1; j < sizeCount; ++j) {
            count[j] += count[j - 1];
        }
        for (j = vec.Size() - 1; j >= 0; --j) {
            if (isdigit(vec[j].Key()[i])) {
                out[--count[vec[j].Key()[i] - '0']] = vec[j];
            } else {
                out[--count[vec[j].Key()[i] - 'A']] = vec[j];
            }
        }
        vec = out;
    }  
}


int main() {
    char tmp1;
    char tmp2[4];
    char tmp3[3];
    char tmpStr[2048];
    TVector<TPairString> a;
    a.Reserve(10);
    TPairString tmpPair;
    while (std::cin >> tmp1 >> tmp2 >> tmp3 >> tmpStr) {
        std::cout << "making new pair\n";
        tmpPair = TPairString(TCarNumber(tmp1, tmp2, tmp3), tmpStr);
        a.Push_back(tmpPair);
        // Print(a);
    }
    Print(a);
    // std::cout << std::endl;
    // RadixSort(a);
    // Print(a);
} 