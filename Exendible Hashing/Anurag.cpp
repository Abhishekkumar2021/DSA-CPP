#include<bits/stdc++.h>

using namespace std;

class Bucket{
    public:
        int local_depth;
        int occupancy; // no. of items currently present in buket
        int creation_index; // records order of bucket creation
        vector<int> list; // actual array of bucket items

        Bucket(int ld,int bucket_size,int ci){
            local_depth=ld;
            occupancy=0;
            creation_index=ci;
            list.resize(bucket_size); // at time of creation of bucket, we resize the size of bucket to what was provided as size value
        }
};

bool compareBucket(Bucket b1, Bucket b2)
{
    return (b1.creation_index < b2.creation_index);
}

class HashTable{
    private:
        int global_depth_initial;
        int creation_count; // records in total how many buckets were created
        int bucket_size; // records what is max size of each bucket
        vector<Bucket*> directory;

        // identity hash function
        int hash(int value){
            return value % (int)pow(2,global_depth);
        }

    public:
        int global_depth;
        int bucket_count; // records in total how many buckets are there
        // consructor
        HashTable(int gd,int bs){
            global_depth = gd;
            global_depth_initial = gd;
            creation_count = 0;
            bucket_count = 0;
            bucket_size = bs;
            int dirs = pow(2,gd);
            // directory.resize(dirs);
            // initially creating all the buckets
            for (int i = 0; i < dirs; i++)
            {
                directory.push_back(new Bucket(gd,bs,i));
                creation_count++;
                bucket_count++;
            }
        }

        void insert(int value){
            // calculate bucket number by hash function
            int bucket_num = hash(value);

            // calculate bucket address by looking into directory
            auto bucket = directory[bucket_num];

            // if the bucket is not full then simply insert the value in bucket and increment the occupancy.
            if(bucket->occupancy < bucket_size){
                bucket->list.push_back(value);
                bucket->occupancy++;
            } 

            // if bucket is full then check if local depth is less than global depth, if so then create a new bucket and re-arrange the elements of filled bucket to self and the newly created bucket,      dont forget to update occupancy of each bucket
            else if(bucket->local_depth < global_depth){
                // first we increase local depth of current bucket
                bucket->local_depth++;

                // then create a new empty bucket and update the directory pointer to point to new bucket
                bucket_count++;
                directory[bucket_num] = new Bucket(bucket->local_depth,bucket_size,creation_count++);

                // store elements of old bucket in temporary array
                vector<int> temp(bucket_size + 1);
                for(auto item:bucket->list){
                    temp.push_back(item);
                }
                temp.push_back(value);

                // clear old bucket and reset its occupancy to 0
                bucket->list.clear();
                bucket->occupancy = 0;

                // again insert elements in those two buckets based on hash value
                for(auto item:temp){
                    int bucket_no = hash(item);
                    auto new_bucket = directory[bucket_no];
                    new_bucket->occupancy++;
                    new_bucket->list.push_back(item);
                }

            }
            // if bucket is full then check if local depth is less than global depth, if not then double the directory size, increase the global depth, then follow the steps of else-if code part above .
            else {
                // double the directory
                int size = directory.size();
                for (int i = 0; i < size; i++)
                {
                    directory.push_back(directory[i]);
                }

                // increment gloal depth
                global_depth++;
                
                // repeat steps of else-if block

                // first we increase local depth of current bucket
                bucket->local_depth++;
                bucket_count++;

                // then create a new empty bucket update the directory pointer to point to new bucket
                directory[bucket_num + (int)pow(2,global_depth-1)] = new Bucket(bucket->local_depth,bucket_size,creation_count++);

                // store elements of old bucket in temporary array
                vector<int> temp(bucket_size + 1);
                for(auto item:bucket->list){
                    temp.push_back(item);
                }
                temp.push_back(value);

                // clear old bucket and reset its occupancy to 0
                bucket->list.clear();
                bucket->occupancy = 0;

                // again insert elements in those two buckets based on hash value
                for(auto item:temp){
                    int bucket_no = hash(item);
                    auto new_bucket = directory[bucket_no];
                    new_bucket->occupancy++;
                    new_bucket->list.push_back(item);
                }
                
            }
        }

        pair<bool,vector<int>::iterator> search(int value){
            // calculate bucket based on hash function
            int bucket_num = hash(value);
            auto bucket = directory[bucket_num];

            // find the element in the bucket
            auto itr = find(bucket->list.begin(),bucket->list.end(),value);

            // return the found status and the value
            if(itr == bucket->list.end()){
                return {false,itr};
            }
            return {true,itr};
        }

        bool del(int value){
            // calculate bucket based on hash function
            int bucket_num = hash(value);
            auto bucket = directory[bucket_num];
            
            // find the iterator of element to be deleted
            auto res = search(value);
            if(!res.first) return false;

            // delete the element from that bucket
            bucket->list.erase(res.second);

            // decrement the occupancy of the bucket
            bucket->occupancy--;

            // if occupancy is 0 => bucket is empty
            if(bucket->occupancy != 0) return true;

            // check if current global depth is initial global depth then no need to delete the bucket
            if(global_depth == global_depth_initial) return true;

            // else delete the bucket and reset the pointer
            delete bucket;
            bucket_count--;
            directory[bucket_num] = directory[bucket_num - (int)pow(2,global_depth-1)];

            // check if directory is duplicate along half
            bool isDuplicate = true;
            for (int i = 0; i < (directory.size())/2; i++)
            {
                if(directory[i] != directory[i + (int)pow(2,global_depth-1)]) isDuplicate = false;
            }
            
            // if directory is duplicate then delete half of it and decremwnt global depth
            global_depth--;
            for (int i = 0; i < (directory.size())/2; i++)
            {
                directory.pop_back();
            }


            return true;
        }

        void print_bucket(){
            unordered_set<Bucket*> s;
            for(auto pointer:directory){
                s.insert(pointer);
            }
            vector<Bucket> temp;
            for(auto bucket:s){
                temp.push_back(*bucket);
            }
            sort(temp.begin(),temp.end(),compareBucket);
            for(auto b:temp){
                cout<<b.occupancy<<" "<<b.local_depth<<endl;
            }
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int globalDepth,bucketCapacity,code,input;
    cin>>globalDepth;
    cin>>bucketCapacity;
    HashTable table = HashTable(globalDepth,bucketCapacity);
    while (true)
    {
        cin>>code;
        switch (code)
        {
            case 2:
                cin>>input;
                table.insert(input);
                break;
            case 3:
                cin>>input;
                table.search(input);
                break;
            case 4:
                cin>>input;
                table.del(input);
                break;
            case 5:
                cout<<table.global_depth<<endl;
                cout<<table.bucket_count<<endl;
                table.print_bucket();
                break;
            case 6:
                return 0;
                break;
            default:
                break;
        }
    }
    

    return 0;
}