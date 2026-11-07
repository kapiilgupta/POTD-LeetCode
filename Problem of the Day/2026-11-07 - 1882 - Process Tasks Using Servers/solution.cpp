class Solution {
    using pii = pair<int, int>;
    using arr3 = array<long long, 3>;

public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // {weight, index} for available servers.
        priority_queue<pii, vector<pii>, greater<pii>> free;

        // {finish time, weight, index} for busy servers.
        priority_queue<arr3, vector<arr3>, greater<arr3>> busy;

        for (int i = 0; i < (int)servers.size(); ++i) {
            free.push({servers[i], i});
        }

        int m = tasks.size();
        vector<int> ans(m);

        for (int j = 0; j < m; ++j) {
            // Release every server that is free by task j's arrival.
            while (!busy.empty() && busy.top()[0] <= j) {
                auto [ft, w, i] = busy.top();
                busy.pop();
                free.push({(int)w, (int)i});
            }

            long long startTime = j;

            // If no server is available, advance to the earliest finish time.
            if (free.empty()) {
                startTime = busy.top()[0];

                // Release ALL servers finishing at this same time so that
                // the weight/index priority is respected.
                while (!busy.empty() && busy.top()[0] <= startTime) {
                    auto [ft, w, i] = busy.top();
                    busy.pop();
                    free.push({(int)w, (int)i});
                }
            }

            auto [w, i] = free.top();
            free.pop();

            ans[j] = i;
            busy.push({startTime + tasks[j], w, i});
        }

        return ans;
    }
};