// Question Link: https://leetcode.com/problems/3sum

// 48ms More Optimized Solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> result;
        if (N < 2) {
            result;
        }
        sort(begin(nums), end(nums));
        for (int i = 0; i < N - 2 && nums[i] <= 0; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = N - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    k--;
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
            }
        }
        return result;
    }
};

// 56ms without BinarySearch
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> result;
        if (N < 2) {
            result;
        }
        sort(begin(nums), end(nums));
        for (int i = 0; i < N - 2 && nums[i] <= 0; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = N - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    k--;
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }
        return result;
    }
};

// 336ms Without Using Set
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> result;
        if (N < 2) {
            result;
        }
        sort(begin(nums), end(nums));
        for (int i = 0; i < N - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            int k = N - 1;
            while (i < k - 1) {
                int find = -(nums[i] + nums[k]);
                if (binary_search(nums.begin() + i + 1, nums.begin() + k, find)) {
                    result.push_back({nums[i], find, nums[k]});
                }
                k--;
                while (i < k - 1 && nums[k] == nums[k + 1]) {
                    k--;
                }
            }
            while (i < N - 2 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return result;
    }
};

// 1100ms Using Set
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> result;
        if (N < 2) {
            result;
        }
        set<vector<int>> seen;
        sort(begin(nums), end(nums));
        for (int i = 0; i < N - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            int j = i + 1;
            int k = N - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    seen.insert({nums[i], nums[j++], nums[k--]});
                }
                else if (sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        for (auto &answer : seen) {
            result.push_back(answer);
        }
        return result;
    }
};
