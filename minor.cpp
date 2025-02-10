#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include<limits.h>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <cstring>


using namespace std;

int OR(int data[], int sz)
{
	int mOR = 0;
	for (int i = 0; i < sz; ++i) {
		mOR |= data[i];
	}

	return mOR;
}

int minSubset(int data[], int sz, int maxOR)
{

	vector<vector<int> > count(sz + 1, vector<int>(maxOR + 1, 1e9));

	count[0][0] = 0;

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j <= maxOR; j++) {

			count[i + 1][j] = min(count[i + 1][j], count[i][j]);

			if (count[i][j] != 1e9) {
				count[i + 1][j | data[i]] = min( count[i + 1][j | data[i]], count[i][j] + 1);
			}
            
		}
	}

	return count[sz][maxOR];
}

// Driver code
int main()
{
	int data[] = { 2,1,17,14,18 };
	int sz = sizeof(data) / sizeof(0);
	int maxOR = OR(data, sz);

	// Function Call
	cout << minSubset(data, sz, maxOR) << '\n';
}
