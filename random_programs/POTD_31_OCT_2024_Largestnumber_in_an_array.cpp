#include <iostream>
using namespace std;

void largestnumber(int data, int arr[], int &loc, int &max)
{

	loc = 1;
	max = arr[1];
	for (int k = 1; k < data; k++)
	{
		if (max < arr[k])
		{
			max = arr[k];
			loc = k;
		}
	}
}

int main()
{
	int data;

	cout << "How many numbers you want to add in a array?" << endl;
	cin >> data;

	int arr[data];
	cout << "Enter the numbers to be stored in array: " << endl;
	for (int i = 0; i < data; i++)
	{
		cin >> arr[i];
	}

	int loc;
	int max;
	largestnumber(data, arr, loc, max);
	cout << "The largest element is " << max << " at position " << loc << "\n";

	return 0;
}