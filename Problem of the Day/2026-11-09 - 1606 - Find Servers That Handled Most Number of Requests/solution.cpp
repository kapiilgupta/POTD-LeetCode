class Solution {
public:
    typedef pair<int, int> P; // {finishTime, serverId}

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available_servers;
        for (int i = 0; i < k; i++) {
            available_servers.insert(i);
        }

        priority_queue<P, vector<P>, greater<P>> busyServers;
        vector<int> countRequests(k, 0);

        for (int i = 0; i < (int)arrival.size(); i++) {
            int time = arrival[i];

            while (!busyServers.empty() && busyServers.top().first <= time) {
                int server = busyServers.top().second;
                busyServers.pop();
                available_servers.insert(server);
            }

            if (available_servers.empty()) {
                continue;
            }

            int target = i % k;
            auto it = available_servers.lower_bound(target);

            if (it == available_servers.end()) {
                it = available_servers.begin();
            }

            int targetServer = *it;
            available_servers.erase(it);

            busyServers.push({time + load[i], targetServer});
            countRequests[targetServer]++;
        }

        int maxNumberOfRequests =
            *max_element(countRequests.begin(), countRequests.end());

        vector<int> result;
        for (int i = 0; i < k; i++) {
            if (countRequests[i] == maxNumberOfRequests) {
                result.push_back(i);
            }
        }

        return result;
    }
};