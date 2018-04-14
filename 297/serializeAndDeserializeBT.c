/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result="";
        if(!root){
            result.push_back('$');
            result.push_back(' ');
            return result;
        }
        result+=toString(root->val);
        result.push_back(' ');
        result+=serialize(root->left);
        result+=serialize(root->right);
        return result; 
    }
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int current=0;
        return helpDeserialize(data,current);
    }
    
    TreeNode* helpDeserialize(string &data, int &current){
        if(current==data.size())
            return NULL;
        string str="";
        while(data[current]!=' '){
            str.push_back(data[current++]);
        }
        
        if(str=="$"){
            return NULL;
        }
        TreeNode* root=new TreeNode(toInt(str));
        ++current;
        root->left=helpDeserialize(data,current);
        ++current;
        root->right=helpDeserialize(data,current);
        return root;
    }
    
    string toString(int num){
        if(num==0)
            return "0";
        string result="";
        while(num){
            result.push_back('0'+num%10);
            num/=10;
        }
        reverse(result.begin(),result.end());
        return result;
    }
    
    int toInt(string str){
        int result=0;
        for(int i=0;i<str.size();++i){
            result*=10;
            result+=(str[i]-'0');
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
