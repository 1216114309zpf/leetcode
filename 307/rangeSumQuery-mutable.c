class NumArray {
public:
    struct Node{
        int start,end,sum;
        Node* left;
        Node* right;
        Node(int start,int end):start(start),end(end),sum(0),left(NULL), right(NULL){}
    };
    Node*root;
    vector<int> vec;
    NumArray(vector<int> nums) {
        root=construct(nums,0,nums.size()-1);
        vec=nums;
    }
    
    void update(int i, int val) {
        int diff=val-vec[i];
        vec[i]=val;
        Node* ptr=root;
        while(ptr){
            ptr->sum+=diff;
            int mid=ptr->start+(ptr->end - ptr->start)/2;
            if(i<=mid){
                ptr=ptr->left;
            }else{
                ptr=ptr->right;
            }
        }
    }
    
    
    int sumRange(int i, int j) {
        return getSum(root,i,j);
    }
    
    int getSum(Node* root,int i,int j){
        if(i==root->start and j==root->end){
            return root->sum;
        }
        
        int result=0;
        int mid=root->start + (root->end - root->start)/2;
        if(j<=mid){
            result+=getSum(root->left,i,j);
        }else{
            if(i>mid){
                result+=getSum(root->right,i,j);
            }else{
                result+=getSum(root->left,i,mid)+getSum(root->right,mid+1,j);
            }
        }
        return result;
    }
    
    Node* construct(vector<int>& nums, int left, int right){
        if(left>right){
            return NULL;
        }
        Node*root=new Node(left,right);
        if(left==right){
            root->sum=nums[left];
            return root;
        }
        int mid=left+(right-left)/2;
        root->left=construct(nums,left,mid);
        root->right=construct(nums,mid+1,right);
        if(root->left){
            root->sum+=root->left->sum;
        }
        if(root->right){
            root->sum+=root->right->sum;
        }
        return root;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
