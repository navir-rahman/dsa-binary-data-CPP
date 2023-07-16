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



//max height
bool flag=true;
int maxheight(Node* root){
    if(root==NULL)return 0;
    if(root->left == NULL && root->right==NULL)return 1;
    // if(root->left != NULL || root->right!=NULL)return false;
    
    int l=maxheight(root->left);
    int r=maxheight(root->right);
    // cout<<l<<" "<<r<<endl;
    
    if(l!=r) {flag=false;  return 0;}
    else return 1;
}
 int main()
{
    flag=true;
    Node* root = input_tree();
    // lavel_order(root);

    maxheight(root);
    if(flag)cout<<"YES";
    else cout<<"NO";
    return 0;
}