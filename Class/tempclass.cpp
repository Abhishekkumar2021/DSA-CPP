#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
class pairs
{
    T first;
    U second;

public:
    void set_first(T first)
    {
        this->first = first;
    }
    void set_second(U second)
    {
        this->second = second;
    }
    T get_first()
    {
        return first;
    }
    U get_second()
    {
        return second;
    }
};