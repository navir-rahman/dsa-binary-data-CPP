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
//level order 
void lavel_order(Node* root){
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        //ber kore ano
        Node* p=q.front();
        q.pop();

        // jabotio kaj
        cout<<p->val<<" ";
        //children push koro

        if(p->left)q.push(p->left);
        if(p->right)q.push(p->right);
    }
}


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
int count_leaf(Node* root){
    if(root==NULL) return 0;
    if(root->left == NULL && root->right==NULL){
        return 1;
    }
    else{
        int l=count_leaf(root->left);
        int r= count_leaf(root->right);
        return l+r;
    }
}

//leaf node min max
int mymin=1000, mymax=0;

void count_leaf2(Node* root){
    if(root==NULL) return ;
    if(root->left == NULL && root->right==NULL){
        if(root->val<mymin) mymin=root->val;
        if(root->val>mymax) mymax=root->val;
    }
    else{
        count_leaf2(root->left);
        count_leaf2(root->right);
        // return l+r;
    }
}

//reverse print
vector<int>  reverse_print( Node* root){
    vector<int> v;
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        Node* nod=q.front();
        q.pop();
        v.push_back(nod->val);
        if(nod->left) q.push(nod->left);
        if(nod->right) q.push(nod->right);
    }
    reverse(v.begin(), v.end());
}

//max height
int maxheight(Node* root){
    if(root==NULL)return 0;
    int l=maxheight(root->left);
    int r=maxheight(root->right);
    return max(l,r)+1;
}

 int main()
{
    Node* root = input_tree();
    // lavel_order(root);
    vector<int> prnt= reverse_print(root);
    for(auto v: prnt){
        cout<<v<<" ";
    }

    return 0;
}