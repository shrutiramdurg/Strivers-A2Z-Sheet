#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }

        // Max heap to store task frequencies
        priority_queue<int> pq;
        for (auto& [ch, f] : freq) {
            pq.push(f);
        }

        int time = 0;

        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> temp;

            while (cycle > 0 && !pq.empty()) {
                int current = pq.top(); pq.pop();
                current--;
                if (current > 0)
                    temp.push_back(current);
                time++;
                cycle--;
            }

            for (int f : temp)
                pq.push(f);

            // If there are still tasks left, we must account for idle time
            if (!pq.empty())
                time += cycle; // idle slots
        }

        return time;
    }
};
