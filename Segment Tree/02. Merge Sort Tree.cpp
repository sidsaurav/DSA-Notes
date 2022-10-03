//Author: Siddharth Saurav
//cf @ sidd_11

/*
MERGE SORT TREE (Seg Tree + Binary Search)

Here each node of the tree will contain vector of numbers falling inside
that node in sorted order.
Now we can use binary search to get numbers of elements greater than or
smaller than a given value.
In the following code, number of elements greater than equal to K is
implemented.



Space Complexity -> O(n*log(n))
(total number of elements in each level of seg tree * number of levels)
*/




#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> seg;

vector<int> merge(vector<int>& v1, vector<int>& v2){
    int n = v1.size();
    int m = v2.size();

    vector<int> temp(n+m);
    int i = 0;
    int j = 0;

    int k = 0;
    while(i<n and j<m){
        if(v1[i] < v2[j]){
            temp[k++] = v1[i++];
        }
        else{
            temp[k++] = v2[j++];
        }
    }

    while(i<n){
        temp[k++] = v1[i++];
    }

    while(j<m){
        temp[k++] = v2[j++];
    }

    return temp;
}

void build_tree(int N, int l, int r, vector<int>& v){
    if(l == r){
        seg[N].push_back(v[l]);
        return;
    }

    int mid = (l+r)/2;

    build_tree(2*N, l, mid, v);
    build_tree(2*N+1, mid+1, r, v);

    seg[N] = merge(seg[2*N], seg[2*N + 1]);
}


int query_tree(int i, int j, int num, int N, int l, int r){
    if(i>r or j<l) return 0;
    if(l>=i and r<=j){
        int idx = lower_bound(seg[N].begin(), seg[N].end(), num) - seg[N].begin();
        return (r-l+1) - idx; // total - numbers smaller than num
    }

    int mid = (l+r) >> 1;
    int n1 = query_tree(i, j, num, 2*N, l, mid);
    int n2 = query_tree(i, j, num, 2*N+1, mid+1, r);
    
    return n1 + n2; 
}

int32_t main(){
    vector<int> v = {5,1,1,8,3};
    int n = v.size();
    seg.resize(4*n);
    build_tree(1, 0, n-1, v);
    cout << query_tree(0, n-1, 2, 1, 0, n-1); //(i, j, K, node, tree_i, tree_j)
}    
