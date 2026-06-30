class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int num:nums){
            pq.push(num);
            // Keep the heap size capped at k during initialization
            if(pq.size()>size){
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        // If we exceed k elements, remove the smallest
        if(pq.size()>size){
            pq.pop();
        }
        // The top of the min-heap is the k-th largest element
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */