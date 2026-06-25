class MyHashMap {
private:
    int numBuckets = 10007; // Optimal prime number for hash distribution
    // A vector of buckets, where each bucket holds key-value pairs
    vector<vector<pair<int, int>>> buckets = vector<vector<pair<int, int>>>(10007);

    int hash(int key) {
        return key % numBuckets;
    }

public:
    MyHashMap() {}
    
    void put(int key, int value) {
        int index = hash(key);
        auto& bucket = buckets[index];
        
        // 1. Check if the key already exists. If yes, update its value.
        for (auto& kv : bucket) {
            if (kv.first == key) {
                kv.second = value;
                return;
            }
        }
        
        // 2. If it's a completely new key, push the {key, value} pair into the bucket
        bucket.push_back({key, value});
    }
    
    int get(int key) {
        int index = hash(key);
        const auto& bucket = buckets[index]; // Use const auto& for safe read-only access
        
        // Search for the key inside the matching bucket
        for (const auto& kv : bucket) {
            if (kv.first == key) {
                return kv.second; // Return the associated value
            }
        }
        
        return -1; // Per problem constraints: return -1 if the key doesn't exist
    }
    
    void remove(int key) {
        int index = hash(key);
        auto& bucket = buckets[index];
        
        // Use a traditional iterator loop to safely erase from the vector
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};
