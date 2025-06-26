#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define f0(i, n) for(int i=0;i<=n;i++)
#define f1(i, n) for(int i=1;i<=n;i++)

#define randivec(n, a) vector<int> a(n); srand(time(NULL)); f0(i, n-1) a[i] = rand()%100;
#define maxn 10000

struct Node{
    int val;
    Node *left, *right;

    Node(int x): val(x), left(nullptr), right(nullptr) {}
};


class BST{
private: 
    Node* root=nullptr;
    int size = 0;
public:
    Node* insert(Node* root, int x){
        if(!root) return new Node(x);
        if(root->val==x) return root;
        if(x>root->val) root->right=insert(root->right, x);
        else root->left=insert(root->left, x);
        return root;
    }

    Node* getMax(Node* node){
        Node* cur = node;
        while(cur->right) cur = cur->right;
        return cur;
    }

    Node* rm(Node* root, int x){
        if(!root) return root;

        if(root->val>x){
            root->left = rm(root->left, x);
        }else if(root->val<x){
            root->right = rm(root->right, x);
        }else{
            if(!root->left){
                Node* tmp = root->right;
                delete root; root = tmp;
            }else if(!root->right){
                Node* tmp = root->left;
                delete root; root = tmp;
            }else{
                Node* min = getMax(root->left);
                root->val = min->val;
                root->left = rm(root->left, min->val);
                return root;
            }
        }

        return root;
    }

    void insert(int x){
        root = insert(root, x);
        size++;
    }
    void rm(int x){
        root = rm(root, x);
    }

    void MorrisTraversal(Node* root){
        Node* cur = root;

        while(cur){
            if(!cur->left){
                cout<<cur->val<<" ";
                cur = cur->right;
            }else{
                Node* prev = cur->left;
                while(prev->right && prev->right!=cur) prev = prev->right;

                if(!prev->right){
                    prev->right = cur; cur = cur->left;
                }

                if(prev->right == cur){
                    cout<<cur->val<<" ";
                    prev->right = nullptr;
                    cur = cur->right; 
                }
            }
        }
        cout<<endl;
    }

    void preorder(Node* root){
        Node* cur = root;

        while(cur){
            if(!cur->left){
                cout<<cur->val<<" ";
                cur = cur->right;
            }else{
                Node* prev = cur->left;
                while(prev->right && prev->right!=cur) prev=prev->right;

                if(!prev->right){
                    cout<<cur->val<<" ";
                    prev->right = cur;
                    cur = cur->left;
                }else{
                    prev->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        cout<<endl;
    }
    // int cnt = 0;
    // int res = INT_MAX;
    // void findKSmallestNode(Node* root, int k){
    //     if(!root || cnt>=k) return;

    //     findKSmallestNode(root->left, k);

    //     cnt++;
    //     if(cnt == k){
    //         res = root->val;
    //         return;
    //     }

    //     findKSmallestNode(root->right, k);
    // }
    // int kSmallest(int k){
    //     cnt = 0; res = INT_MAX;
    //     findKSmallestNode(root, k);
    //     return res;
    // }

    void foo(Node* root, int k, int& cnt, int& res){
        if(!root || cnt>=k) return;
        foo(root->left, k, cnt, res);
        cnt++;
        if(cnt == k){
            res = root->val;
        }

        foo(root->right, k, cnt, res);
    }

    int kSmallest(int k){
        int res = INT_MAX;
        int cnt = 0;
        foo(root, k, cnt, res);
        return res;
    }


    void query(Node* root, int l, int r, vector<int>& res){
        if(!root) return;
        if(root->val > l) query(root->left, l, r, res);
        if(root->val>=l && root->val<=r) res.push_back(root->val);
        if(root->val < r) query(root->right, l, r, res);
    }
    vector<int> queryInRange(int l, int r){
        vector<int> a;
        query(root, l, r, a);
        return a;
    }

    ~BST(){
        while(root){
            root=rm(root, root->val);
        }
    }

    void inorder(){
        MorrisTraversal(root);
    }

    void preorder(){
        preorder(root);
    }

    
};




int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef MYIO
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif    

    BST tree;
    // randivec(100, a)
    vector<int> a = {20, 1, 21, 3, 5, 9, 15, 4, 28};
    for(int x:a) tree.insert(x);

    tree.inorder();
    vector<int> b = tree.queryInRange(5, 20);
    for(int x:b) cout<<x<<" ";
    return 0;
}
