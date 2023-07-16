#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};


//input tree
Node* input_tree(){
    int val;
    cin>>val;
    Node* root;
    if(val==-1) root = NULL;
    else root = new Node(val);

    queue<Node*> q;
    if(root) q.push(root);
    while (!q.empty())
    {
        //ber kore ano
        Node* p=q.front();
        q.pop();

        // jabotio kaj
        int l,r;
        cin>>l>>r;
        Node* Myleft;
        Node* Myright;
        if(l==-1) Myleft=NULL;
        else Myleft= new Node(l);

        if(r==-1) Myright=NULL;
        else Myright = new Node(r);

        p->left =Myleft;
        p->right=Myright;
        //children push koro

        if(p->left)q.push(p->left);
        if(p->right)q.push(p->right);


    }
    return root;
}



//leaf node
int mymin=1000, mymax=0;

void count_leaf(Node* root){
    if(root==NULL) return ;
    if(root->left == NULL && root->right==NULL){
        if(root->val<mymin) mymin=root->val;
        if(root->val>mymax) mymax=root->val;
    }
    else{
        count_leaf(root->left);
        count_leaf(root->right);
        // return l+r;
    }
}
 int main()
{
    
    Node* root = input_tree();
    count_leaf(root);
    cout<<mymax<<" "<<mymin;
    return 0;
}