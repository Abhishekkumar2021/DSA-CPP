#include <bits/stdc++.h>
using namespace std;

class HashTable
{
    int *arr;
    int size;
    int capacity;

public:
    HashTable(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = -1;
        }
    }
    int hash(int key)
    {
        return key % capacity;
    }
    void insert(int key)
    {
        int index = hash(key);
        while (arr[index] != -1)
        {
            index = (index + 1) % capacity;
        }
        arr[index] = key;
        size++;
    }
    void erase(int key)
    {
        int index = hash(key);
        while (arr[index] != key)
        {
            index = (index + 1) % capacity;
        }
        arr[index] = -1;
        size--;
    }
    bool find(int key)
    {
        int index = hash(key);
        while (arr[index] != key)
        {
            index = (index + 1) % capacity;
        }
        return arr[index] == key;
    }
    int getSize()
    {
        return size;
    }
    bool empty()
    {
        return size == 0;
    }
};

int main()
{
    HashTable ht(10);
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(40);
    ht.insert(50);
    ht.insert(60);
    ht.insert(70);
    ht.insert(80);
    ht.insert(90);
    ht.insert(100);
    ht.insert(110);
    ht.insert(120);
    ht.insert(130);
    ht.insert(140);
    ht.insert(150);
    ht.insert(160);
    ht.insert(170);
    ht.insert(180);
    ht.insert(190);
    ht.insert(200);
    ht.insert(210);
    ht.insert(220);
    ht.insert(230);
    ht.insert(240);
    ht.insert(250);
    ht.insert(260);
    ht.insert(270);
    ht.insert(280);
    ht.insert(290);
    ht.insert(300);
    ht.insert(310);
    ht.insert(320);
    ht.insert(330);
    ht.insert(340);
    ht.insert(350);
    ht.insert(360);
    ht.insert(370);
    ht.insert(380);
    ht.insert(390);
    ht.insert(400);
    ht.insert(410);
    ht.insert(420);
    ht.insert(430);
    ht.insert(440);
    ht.insert(450);
    ht.insert(460);
    ht.insert(470);
    ht.insert(480);
    ht.insert(490);
    ht.insert(500);
    ht.insert(510);
    ht.insert(520);
    ht.insert(530);
    ht.insert(540);
    ht.insert(550);
    ht.insert(560);
    ht.insert(570);
    ht.insert(580);
    ht.insert(590);
    ht.insert(600);
    ht.insert(610);
    ht.insert(620);
    ht.insert(630);
    ht.insert(640);
    ht.insert(650);
    ht.insert(660);
    ht.insert(670);
    ht.insert(680);
    ht.insert(690);
    ht.insert(700);
    ht.insert(710);
    ht.insert(720);
    ht.insert(730);
    ht.insert(740);
    ht.insert(750);
    ht.insert(760);
    ht.insert(770);
    ht.insert(780);
    ht.insert(790);
    ht.insert(800);
    ht.insert(810);

    cout << ht.find(10) << endl;
    cout << ht.find(20) << endl;
    cout << ht.find(810) << endl;
    cout << ht.find(811) << endl;
    cout << ht.find(812) << endl;
    return 0;
}