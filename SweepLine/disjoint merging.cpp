/*
    We have two kind of merging - 
        a. {{1,3}, {3,5},{6,9}} -> {{1,5}, {6,9}}
        b. {{1,3}, {3,5},{6,9}} -> {{1,9}} 
*/

#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int main()
{
	vector<vector<int>> ranges = {{1,3}, {3,5},{6,9}};
	map<int, int>mp;
	for(auto &x : ranges) {
		mp[x[0]]++;
// 		mp[x[1]]--; (for a)
        mp[x[1]+1]--; // (for b)
	}
	vector<pair<int, int>> v;
	v.reserve(100001);
	int last = -1;
	int sum = 0;
	for(auto &x : mp) {
		if(last == -1) {
			last = x.ff;
		}
		sum += x.ss;
		if(sum == 0) {
		  //  v.push_back({last, x.ff}); (for a)
			v.push_back({last, x.ff-1}); // (for b)
			last = -1;
		}
	}
	if(sum > 0) {
		v.push_back({last, (*(--mp.end())).ff});
	}
	for(auto &x : v) {
		cout << x.first << " " << x.second << endl;
	}
}