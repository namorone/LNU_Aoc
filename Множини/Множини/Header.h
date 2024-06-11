#pragma once
#define BITCOUNT 8

#include <iostream>

using namespace std;


class Set
{
private:
    char arr[8];
public:
    Set() {
        for (int i = 0; i < 8; i++)
            arr[i] = '\0';
    }
    Set(Set const&) = default;
    Set& operator=(Set const&) = default;

    void append(char const& chr) {
        if (47 < chr && chr < 58)
            arr[(chr - '0') / BITCOUNT] |= 1 << ((chr - '0') % BITCOUNT);       //arr[(56-48)/8( number of bit)] |= 00000001 << ((56-48) % 8); 58 ASCII for '8';

        else if (64 < chr && chr < 92)
            arr[(chr - 'A' + 10) / BITCOUNT] |= 1 << ((chr - 'A' + 10) % BITCOUNT);

        else if (96 < chr && chr < 124)
            arr[(chr - 'a' + 36) / BITCOUNT] |= 1 << ((chr - 'a' + 36) % BITCOUNT);

        else
            cout << "Invalid char value" << chr;
    }
    void remove(char const& chr) {
        if (47 < chr && chr < 58)
            arr[(chr - '0') / BITCOUNT] &= ~(1 << ((chr - '0') % BITCOUNT));

        else if (64 < chr && chr < 92)
            arr[(chr - 'A' + 10) / BITCOUNT] &= ~(1 << ((chr - 'A' + 10) % BITCOUNT));

        else if (96 < chr && chr < 124)
            arr[(chr - 'a' + 36) / BITCOUNT] &= ~(1 << ((chr - 'a' + 36) % BITCOUNT));

        else
            cout << "Invalid char value" << chr;
    }
    bool inSet(char const& chr) {
        if (47 < chr && chr < 58)
            return bool(arr[(chr - '0') / BITCOUNT] & 1 << ((chr - '0') % BITCOUNT));

        else if (64 < chr && chr < 92)
            return bool(arr[(chr - 'A' + 10) / BITCOUNT] & 1 << ((chr - 'A' + 10) % BITCOUNT));

        else if (96 < chr && chr < 124)
            return bool(arr[(chr - 'a' + 36) / BITCOUNT] & 1 << ((chr - 'a' + 36) % BITCOUNT));

        else
            cout << "Invalid char value" << chr;
    }
    void unit(Set const& s) {
        for (unsigned i = 0; i < 8; ++i)
            arr[i] |= s.arr[i];
    }
    void across(Set const& s) {
        for (unsigned i = 0; i < 8; ++i)
            arr[i] &= s.arr[i];
    }
    void print() {
        for (unsigned i = 0; i < 8; ++i) {
            for (unsigned j = 0; j < 8; ++j) {
                cout << bool(arr[i] & (1 << j)) << " ";
            }
        }
    }
};
