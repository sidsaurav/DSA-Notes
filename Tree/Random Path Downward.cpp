class Solution {
public:
    int cnt = 0;
    int tar;
    
    void f(TreeNode* root, vector<int>& vec){
        if(root == NULL) return;
    
        vec.push_back(root->val);
        
        f(root->left, vec);
        f(root->right, vec);
        
        //We can write logic here but remember to traverse v from end.
        
        long long sum = 0;
        for(int i = vec.size()-1; i>=0; i--){
            sum += vec[i];
            if(sum == tar) cnt++;
        }
        
        /*
        We traverse from back because at every time we encounter this block of code
        the sequence will start from a new node but if we traverse from beginning it will
        traverse from root node and always product path from root to that node. But for reverse it 
        will produce all different downward paths possible.
        */
        
        vec.pop_back();
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        tar = targetSum;
        vector<int> vec;
        f(root, vec);
        return cnt;
    }
};
