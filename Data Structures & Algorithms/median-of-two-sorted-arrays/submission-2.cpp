class Solution {
public:
    void merge(vector<int>& nums1, vector<int>& nums2, vector<int>& res) {
        int n = nums1.size();
        int m = nums2.size();

        int i = 0, j = 0, k = 0;
        while (j < n && k < m) {
            if (nums1[j] <= nums2[k]) {
                res[i++] =  nums1[j++];
            }
            else {
                res[i++] =  nums2[k++];
            }
        }

        while (j < n) {
            res[i++] = nums1[j++];
        }

        while (k < m) {
            res[i++] = nums2[k++];
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res(n + m);
        
        merge(nums1, nums2, res);

        if ((m + n) % 2) {
            return (double) res[(m + n) / 2];
        }

        return ((double) res[(m + n) / 2] + (double) res[(m + n) / 2 - 1]) / 2; 
    }
};
