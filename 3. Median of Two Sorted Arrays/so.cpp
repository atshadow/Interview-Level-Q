#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the shorter array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        
        while (left <= right) {
            int partitionX = (left + right) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;
            
            double maxLeftX = (partitionX == 0) ? numeric_limits<int>::min() : nums1[partitionX - 1];
            double minRightX = (partitionX == m) ? numeric_limits<int>::max() : nums1[partitionX];
            
            double maxLeftY = (partitionY == 0) ? numeric_limits<int>::min() : nums2[partitionY - 1];
            double minRightY = (partitionY == n) ? numeric_limits<int>::max() : nums2[partitionY];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
                } else {
                    return max(maxLeftX, maxLeftY);
                }
            }
            else if (maxLeftX > minRightY) {
                right = partitionX - 1;
            }
            else {
                left = partitionX + 1;
            }
        }
        return 0.0; // for compilation, should never reach here
    }
};

// Function to get array input from user
vector<int> getArrayInput(const string& arrayName) {
    vector<int> result;
    string line;
    
    while (true) {
        cout << "Enter " << arrayName << " (space-separated numbers): ";
        getline(cin, line);
        
        stringstream ss(line);
        int num;
        bool validInput = true;
        result.clear();
        
        while (ss >> num) {
            result.push_back(num);
        }
        
        if (!ss.eof() && ss.fail()) {
            cout << "Invalid input. Please enter numbers only.\n";
            continue;
        }
        
        break;
    }
    
    return result;
}

int main() {
    Solution solution;
    
    vector<int> nums1 = getArrayInput("first array");
    vector<int> nums2 = getArrayInput("second array");
    
    double median = solution.findMedianSortedArrays(nums1, nums2);
    cout << "The median is: " << median << endl;
    
    return 0;
}
