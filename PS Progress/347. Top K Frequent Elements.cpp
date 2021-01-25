// Question Link: https://leetcode.com/problems/top-k-frequent-elements

// O(log k)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> Map; // Counts
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> PQ; // Min Heap
        for (int &n : nums) {
            Map[n]++;
        }
        for (auto it : Map) {
            PQ.push({it.second, it.first});
            if (PQ.size() > k) {
                PQ.pop();
            }  
        }
        vector<int> result;
        while (!PQ.empty()) {
            result.push_back(PQ.top()[1]);
            PQ.pop();
        }
        return result;
    }
};

// O(log n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> Map; // Counts
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> PQ; // Min Heap
        for (int &n : nums) {
            Map[n]++;
        }
        for (auto it : Map) {
            if (PQ.size() < k) {
                PQ.push({it.second, it.first});
            } else {
                if (it.second > PQ.top()[0]) {
                    PQ.pop();
                    PQ.push({it.second, it.first});
                }  
            }
        }
        vector<int> result;
        while (!PQ.empty()) {
            result.push_back(PQ.top()[1]);
            PQ.pop();
        }
        return result;
    }
};
