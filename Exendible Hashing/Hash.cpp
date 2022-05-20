#include<bits/stdc++.h>
using namespace std;
class Bucket{
    public:
    int* arr;
    int LD;
    bool isFull;
    int buckSize;
    int size;
    Bucket(){
        LD = 1;
        size = 0;
        isFull = false;
        buckSize = 2;
        arr = new int[buckSize];
    }
    ~Bucket(){
        delete []arr;
    }
    void insert(int x){
        if(size<buckSize){
            arr[size] = x;
            size++;
            if(size==buckSize)
            isFull = true;
        }
          
    }
    void printBucket(){
        for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";
    }
};
class HashTable{
    int numDir;
    int numBuck;
    int GD;
    Bucket *dir;
    vector<Bucket> buckets;
    public:
    HashTable(){
        numDir = 2;
        numBuck= 2;
        GD = 1;
        dir = new Bucket*[numDir];
        for(int i=0; i<numBuck; i++){   
            buckets.push_back(Bucket());
        }
        for(int i=0; i<numDir; i++)
            dir[i] = &buckets[i];
    }
    int hash(int x,int bits){
        int h = 0;
        int pow = 1;
        for(int i=0; i<bits; i++){
            int bit  = (1<<i & x)?1:0;
            h+=pow*bit;
            pow*=2;
        }
        return h;
    }
    void insert(int x){
        int h = hash(x,GD);
        int id = dir[h];
        if(buckets[id].isFull){
            cout<<"Bucket Full\n";
            if(buckets[id].LD==GD){
                int *temp = dir;
                numDir*=2;
                dir = new int[numDir];
                for(int i=0; i<numDir; i++)
                    dir[i] = i;
                delete []temp;
            }else{

            }
            
           
        }else{
            buckets[id].insert(x);
        }
        
    }


};
int main(){
    HashTable h;
    h.insert(10);
    h.insert(20);
    h.insert(30);

}