class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());

        if ((m + n) % 2) {
            return (double) nums1[(m + n) / 2];
        }

        return ((double) nums1[(m + n) / 2] + (double) nums1[(m + n) / 2 - 1]) / 2;
    }
};
