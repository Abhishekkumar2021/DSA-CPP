#include<iostream>
using namespace std;
template <typename T>
class ArrayADT
{
    T *data;
    int size;
    int capacity;

public:
    ArrayADT()
    {
        data = NULL;
        size = 0;
        capacity = 0;
    }
    void createNewArray(int capacity)   // Theta(1)
    {
        data = new T[capacity];
        this->capacity = capacity;
        cout << "Created succesfully\n";
    }
    void storeValue(T value, int index)    // Theta(1)
    {   if(index<size)
        data[index] = value;
        else{
            data[index] = value;
            size++;
        }
    }
    T accessValue(int index)            // Theta(1)
    {
        return data[index];
    }
    void initializeArray(T value)          // Theta(n)
    {
        for (int i = 0; i < capacity; i++){
            data[i] = value;
            size++;
        }
           
    }
    int searchValue(T value)            //Theta(n)
    {
        int ans = -1;
        for (int i = 0; i < size; i++)
            if (data[i] == value)
                ans = i;
        return ans;
    }
    int getCapacity(){           //Theta(1)
        return capacity;
    }
    int  getSize(){                // Theta(1)
        return size;
    }
    bool isEmpty(){             //Theta(1)
        return size == 0;
    }
    bool isFull(){          //Theta(1)
        return size == capacity;
    }
    void decreaseSize(){          //Theta(1)
        size--;
    }
    void increaseSize()           //Theta(1)
    {
        size++;
    }
};
