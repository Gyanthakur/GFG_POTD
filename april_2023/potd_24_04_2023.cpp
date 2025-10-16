#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    vector<int> nextSmallerToLeft(vector<int> &arr, int n)
    {

        vector<int> left(n, -1);
        stack<int> st;
        st.push(0);
        int i = 1;
        while (i < n)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty())
                left[i] = st.top();
            st.push(i);
            i++;
        }
        return left;
    }

    vector<int> nextSmallerToRight(vector<int> &arr, int n)
    {

        vector<int> right(n, -1);
        stack<int> st;
        st.push(n - 1);
        int i = n - 2;

        while (i >= 0)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty())
                right[i] = st.top();
            st.push(i);
            i--;
        }
        return right;
    }

    vector<int> nearestSmallerTower(vector<int> &arr)
    {
        // code here

        int n = arr.size();
        vector<int> left = nextSmallerToLeft(arr, n);
        vector<int> right = nextSmallerToRight(arr, n);
        vector<int> res(n, -1);

        for (int i = 0; i < n; i++)
        {

            if (left[i] == -1 && right[i] == -1)
                continue;
            else if (left[i] == -1)
                res[i] = right[i];
            else if (right[i] == -1)
                res[i] = left[i];

            else
            {
                int distLeft = abs(left[i] - i);
                int distRight = abs(right[i] - i);

                if (distLeft < distRight)
                    res[i] = left[i];
                else if (distLeft > distRight)
                    res[i] = right[i];

                else
                {
                    int heightLeft = arr[left[i]];
                    int heightRight = arr[right[i]];

                    if (heightLeft < heightRight)
                        res[i] = left[i];
                    else if (heightLeft > heightRight)
                        res[i] = right[i];
                    else
                        res[i] = min(left[i], right[i]);
                }
            }
        }
        return res;
    }
};