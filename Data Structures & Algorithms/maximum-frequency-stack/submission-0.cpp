class FreqStack {
public:

    priority_queue<vector<int>> heap; // {frequency, index, value}
    unordered_map<int, int> cnt;
    int index=0;

    FreqStack() {
        
    }
    
    void push(int val) {
        cnt[val]++;
        heap.push({cnt[val], index++, val});
    }
    
    int pop() {
        auto top = heap.top();
        heap.pop();
        int val = top[2];
        cnt[val]--;
        return val;
    }
};