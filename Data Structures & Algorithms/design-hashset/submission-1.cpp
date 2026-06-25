class MyHashSet {
private:
    int numBuckets=10007;
    vector<vector<int>> buckets = vector<vector<int>> (10007);

    int hash(int key){
        return key % numBuckets;
    }
public:
    MyHashSet() {}
    
    void add(int key) {
        int index=hash(key);
        if(!contains(key)){
            buckets[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index=hash(key);
        auto& bucket= buckets[index];

        for(auto it=bucket.begin(); it != bucket.end();it++){
            if(*it == key){
                bucket.erase(it); // as erase accepts only iterators and not actual key
                return;
            }
        }
        
    }
    
    bool contains(int key) {
        int index=hash(key);
        auto& bucket = buckets[index];
        for(auto it:bucket){
             if (it == key) return true;
        
        }
        return false;
        
    }
};

/*
 📊 C++ ITERATOR & AUTO LOOP CHEAT SHEET
 ┌─────────────────┬───────────────────┬──────────────────────────────────┐
 │ Syntax          │ Mechanism         │ Best LeetCode Use Case           │
 ├─────────────────┼───────────────────┼──────────────────────────────────┤
 │ const auto& x   │ Read-only Ref     │ DEFAULT: Strings, Matrix Rows    │
 │ auto& x         │ Modifiable Ref    │ In-place updates (nums[i] *= 2)  │
 │ auto x          │ Pass-by-Value     │ Primitives (int, char), Map pairs│
 │ auto it         │ Pointer Copy      │ Iterators (.begin(), .end())     │
 └─────────────────┴───────────────────┴──────────────────────────────────┘
 ⚠️ TRAP: Plain 'auto row : grid' deeply copies entire arrays -> Causes TLE!
*/
