class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        int n = tasks.size();

        // {enqueueTime, processingTime, originalIndex}
        vector<array<long long, 3>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({
                tasks[i][0],
                tasks[i][1],
                i
            });
        }

        // Sort tasks by arrival time
        sort(jobs.begin(), jobs.end());

        /*
            Min Heap stores:
            {processingTime, index}

            Priority:
            1. Smaller processing time
            2. Smaller index
        */
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> ans;

        long long time = 0;
        int i = 0;

        while (i < n || !pq.empty()) {

            // If CPU is idle, jump to next arriving task
            if (pq.empty()) {
                time = max(time, jobs[i][0]);
            }

            // Add all tasks that have arrived by current time
            while (i < n && jobs[i][0] <= time) {

                long long processingTime = jobs[i][1];
                long long index = jobs[i][2];

                pq.push({processingTime, index});

                i++;
            }

            // Pick shortest available task
            auto [processingTime, index] = pq.top();
            pq.pop();

            ans.push_back(index);

            // CPU processes this task
            time += processingTime;
        }

        return ans;
    }
};