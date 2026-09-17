class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
    // best[i] = minimum length of a valid subarray
    // whose ending index is <= i
    vector<int> best(n, INT_MAX);
    int left = 0;
    long long sum = 0;
    int answer = INT_MAX;
    for (int right = 0; right < n; right++) {
        sum += arr[right];
        // Remove elements from left if sum becomes greater than target
        while (sum > target && left <= right) {
            sum -= arr[left];
            left++;
        }
        // Current subarray has sum = target
        if (sum == target) {
            int currentLength = right - left + 1;
            // If there is a previous non-overlapping subarray
            if (left > 0 && best[left - 1] != INT_MAX) {
                answer = min(answer,
                best[left - 1] + currentLength);
            }
        }
        // Store the best subarray found up to 'right'
        if (right == 0) {
            if (sum == target){best[right] = right - left + 1;}
        }
        else {
            best[right] = best[right - 1];
            if (sum == target) {
                best[right] = min(best[right],right - left + 1);
            }
        }
    }
    if (answer == INT_MAX)
        return -1;
    return answer;
    }
};