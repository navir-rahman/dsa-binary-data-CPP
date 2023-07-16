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



void nodeLevel(Node* root, int searchedlavel)
{
    // Write your code here.
    queue<pair<Node*,int> > q;
    q.push({root,1});
    bool flag=false;

    while(!q.empty()){
        //first q er data and pop koro
        pair<Node*,int> pr=q.front();
        Node* node = pr.first;
        int level = pr.second;
        q.pop();

        //check koro search valeu node val er soman naki
        // cout<<level<<" ";
        if(level == searchedlavel)
        {
            // return level;
            cout<<node->val<<" ";
            flag=true;
        }
        //node left thakle pair e oi node ar tar level rakho
        if(node->left){
             q.push({node->left,level+1}); //porer node er jonno level er shaty 1 plus koro
        }
        if(node->right){
            q.push({node->right, level+1});
        }

    }
    if(flag==false){
        cout<<"Invalid";
    }
}


 int main()
{
    Node* root = input_tree();
    int level;
    cin>>level;
    nodeLevel(root, level+1);

    return 0;
}