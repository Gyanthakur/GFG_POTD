# POTD: Sort Colors
# URL: https://practice.geeksforgeeks.org/problems/sort-colors
# Github username: <BhuwanSKumar>

def sort_colors(nums):
    """
    Sort an array containing 0s, 1s, and 2s (representing colors) in-place.
    Uses Dutch National Flag algorithm.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    low, mid, high = 0, 0, len(nums) - 1

    while mid <= high:
        if nums[mid] == 0:
            nums[low], nums[mid] = nums[mid], nums[low]
            low += 1
            mid += 1
        elif nums[mid] == 1:
            mid += 1
        else:  # nums[mid] == 2
            nums[mid], nums[high] = nums[high], nums[mid]
            high -= 1
    return nums

# Example Tests
if __name__ == "__main__":
    assert sort_colors([2,0,2,1,1,0]) == [0,0,1,1,2,2]
    assert sort_colors([]) == []
    assert sort_colors([0,0,0]) == [0,0,0]
    print("All test cases passed!")
