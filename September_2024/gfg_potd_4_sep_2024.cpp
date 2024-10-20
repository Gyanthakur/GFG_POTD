// 👉🏻Q.There are n stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).
// Note: Order does not matter means for n = 4:- {1 2 1},{2 1 1},{1 1 2} are considered same.


class Solution{
	public:
		int nthStair(int n){
		    return 1+n/2;
		}
};


// 👉🏻Time Complexity (TC):
//  -The function performs a simple arithmetic operation: 1 + n / 2. This operation takes constant time, meaning it does not depend on the size of n. Therefore, the time complexity is O(1).

//👉🏻Space Complexity (SC):
// -The function uses a constant amount of space for storing the  return value and a few local variables, regardless of the input size n. Therefore, the space complexity is O(1).

//👉🏻 logic of the code.
// -The logic of the code is based on counting the number of possible combinations of taking 1 or 2 steps to reach the n-th stair. The formula 1 + n / 2 effectively counts all the unique ways you can balance 1-stair and 2-stair steps to reach the top.