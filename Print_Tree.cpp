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
    vector<int> v;
void lavel_order(Node* root){
    queue<Node*> q;
    if(root) q.push(root);
    while (!q.empty())
    {
        //ber kore ano
        Node* p=q.front();
        q.pop();

        // jabotio kaj
        // cout<<p->val<<" ";
        v.push_back(p->val);
        //children push koro

        if(p->right)q.push(p->right);
        if(p->left)q.push(p->left);
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

void reverse_print(Node* root){
    if(root == NULL) return;
    reverse_print(root->left);
    reverse_print(root->right);
    cout<<root->val<<" ";
}

 int main()
{
    Node* root = input_tree();

    lavel_order(root);
    reverse(v.begin(), v.end());
    for (size_t i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    

    return 0;
}