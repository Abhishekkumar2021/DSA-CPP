#include <bits/stdc++.h>
using namespace std;

template <typename V>
class ourmapNode
{
public:
    string key;
    V value;
    ourmapNode *next;
    ourmapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    ~ourmapNode()
    {
        delete this->next;
        cout << "Deleted : " << this->key << " , " << this->value << endl;
    }
};

template <typename V>
class ourmap
{
    ourmapNode<V> **buckets;
    int size;
    int numBuckets;
    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int p = 37;
        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += currentCoeff * key[i];
            hashCode = hashCode % numBuckets;
            currentCoeff *= p;
            currentCoeff = currentCoeff % numBuckets;
        }
        return hashCode % numBuckets;
    }
    void rehash()
    {
        ourmapNode<V> **temp = buckets;
        buckets = new ourmapNode<V> *[numBuckets * 2];
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
        size = 0;
        for (int i = 0; i < oldBucketCount; i++)
        {
            ourmapNode<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for (int i = 0; i < oldBucketCount; i++)
        {
            delete temp[i];
        }
        delete[] temp;
    }

public:
    ourmap()
    {
        size = 0;
        numBuckets = 5;
        buckets = new ourmapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
            buckets[i] = NULL;
    }
    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }
    int currentSize()
    {
        return size;
    }
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        ourmapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        ourmapNode<V> *newNode = new ourmapNode<V>(key, value);
        newNode->next = head;
        buckets[bucketIndex] = newNode;
        size++;
        double loadFactor = (size * 1.0) / numBuckets;
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }
    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        ourmapNode<V> *head = buckets[bucketIndex];
        while (head)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    double getLoadFactor()
    {
        return (size * 1.0) / numBuckets;
    }
    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        ourmapNode<V> *head = buckets[bucketIndex];
        ourmapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                    prev->next = head->next;
                V value = head->value;
                head->next = NULL;
                delete head;
                size--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0; // not found
    }
};