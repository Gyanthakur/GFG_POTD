// 👉🏻 Q.Given a square grid of size N, each cell of which contains an integer cost that represents a cost to traverse through that cell, we need to find a path from the top left cell to the bottom right cell by which the total cost incurred is minimum.
//   From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Cell
{
public:
    int i, j, x;
    Cell(int i, int j, int x)
    {
        this->i = i;
        this->j = j;
        this->x = x;
    }
};

class Comparator
{
public:
    bool operator()(Cell &c1, Cell &c2)
    {
        // This should be "less than" for min-heap behavior
        return c1.x > c2.x;
    }
};

class Solution
{
public:
    int minimumCostPath(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        // Min-heap priority queue
        priority_queue<Cell, vector<Cell>, Comparator> pq;

        // DP table to store the minimum cost to reach each cell
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        // Possible directions for movement (left, right, up, down)
        vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        // Start with the top-left corner (0,0)
        pq.push(Cell(0, 0, grid[0][0]));
        dp[0][0] = grid[0][0];

        while (!pq.empty())
        {
            Cell temp = pq.top();
            pq.pop();

            // Explore neighbors in 4 directions
            for (auto d : dir)
            {
                int ni = temp.i + d[0];
                int nj = temp.j + d[1];

                // Check if the new coordinates are valid
                if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                    continue;

                int newCost = grid[ni][nj] + temp.x;

                // If a cheaper path to the neighbor is found, update it
                if (dp[ni][nj] > newCost)
                {
                    dp[ni][nj] = newCost;
                    pq.push(Cell(ni, nj, newCost));
                }
            }
        }

        // 👉🏻 logic
        //  A.Initialization-
        //  The algorithm starts with the assumption that the first element a[0] is already sorted.
        //  It begins iterating from the second element (i = 1) to the last element (i = n-1).

        // B .Key Selection-
        // The current element, a[i], is picked as the key. This is the element that we need to insert into the correct position within the sorted portion of the array (which is to the left of i).

        // C. Comparison and Shifting-
        //  The inner loop compares the key with the elements in the sorted portion of the array (i.e., the elements to the left of i).
        //  If an element in the sorted portion is greater than the key, it is shifted one position to the right to make space for the key.
        //  This shifting process continues until we find the correct position where the key can be inserted.

        // D. Insertion-
        //  Once the correct position is found (i.e., when we find an element smaller than or equal to the key), the key is inserted into that position (a[j + 1] = key).

        // E.Continue to the Next Element-
        // The process repeats for the next element, gradually growing the sorted portion of the array.

        // 👉🏻 Time complexcity
        //   -The algorithm processes each cell at most once using a priority queue. In a grid of size n × m, the number of cells is -𝑂((n*m)log(n*m))

        // 👉🏻 space complexcity
        //  -The space complexity is 𝑂((n*m),due to the DP table (dp) and the priority queue (pq), which store information for each cells.
    }
};