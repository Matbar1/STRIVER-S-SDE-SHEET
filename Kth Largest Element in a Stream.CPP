class KthLargest {
private:
    priority_queue<int, vector<int>, greater<>> pq;
    int k;
public:
    KthLargest(int k, vector<int> A): k(k) {
        for (int n : A) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }
    }
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */