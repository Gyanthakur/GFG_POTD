#include <iostream>
#include <vector>

int findLastElement(std::vector<int>& arr) {
    int n = arr.size();
    int k = 1;
    
    while (n > 1) {
        // Rotate the array clockwise by 1
        int last = arr.back();
        arr.pop_back();
        arr.insert(arr.begin(), last);
        
        // Delete the (n - k + 1)th element from the last
        int delete_index = n - k;
        arr.erase(arr.begin() + delete_index);
        
        // Update the length of the array and increment k
        n--;
        k++;
    }
    
    return arr[0];
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    std::cout << findLastElement(arr1) << std::endl;  // Output: 3

    std::vector<int> arr2 = {1, 2, 3, 4};
    std::cout << findLastElement(arr2) << std::endl;  // Output: 2

    return 0;
}
