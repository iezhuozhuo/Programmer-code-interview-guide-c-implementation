class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
	    int right = nums.size() - 1;
	    while (left <= right) {
		    int mid = left + ((right - left) >> 1);//防止出现数组越界
		    if (nums[mid] == target) {
			    return mid;
		    }
		    if (nums[mid] < nums[right]) {
			    if (nums[mid] < target && target <= nums[right]) {
				    left = mid + 1;
			    }
			    else {
				    right = mid - 1;
			    }
		    }
		    else {
			    if (nums[left] <= target && target < nums[mid]) {
				    right = mid - 1;
			    }
			    else {
				    left = mid + 1;
			    }
		    }
	    }
	    return -1; 
    }
};
