// C++ program to compute sum of digits in
#include <bits/stdc++.h>
using namespace std;

class addSum
{
public:
	int getSum(int n)
	{
		int total = 0;
		while (n != 0)
		{
			total = total + n % 10;
			n = n / 10;
		}
		return total;
	}
};

int main()
{
	addSum g;
	int n = 687;

	// Function call
	cout << g.getSum(n);
	return 0;
}