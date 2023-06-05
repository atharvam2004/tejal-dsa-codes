#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode{
	string data;
	vector<TreeNode*> children;
};

TreeNode* GetNewNode(string data){
	TreeNode* newnode=new TreeNode();
	newnode->data=data;
	return newnode;
}
void addChild(TreeNode* node,string data){
	TreeNode* newnode=GetNewNode(data);
	node->children.push_back(newnode);
}
void preorderTraversal(TreeNode* root)
{
    stack<TreeNode*> Stack;
    vector<string> Preorder;
 
    Stack.push(root);
 
    while (!Stack.empty()) {
        TreeNode* temp = Stack.top();
        Stack.pop();
        Preorder.push_back(temp->data);
        for (int i = temp->children.size() - 1; i >= 0; i--) {
            Stack.push(temp->children[i]);
        }
    }
    for(int i=0;i<Preorder.size();i++){
    	cout<<Preorder[i]<<"\n\t";
	}
    cout << endl;
}
int main(){
	int choice;
	TreeNode* root=GetNewNode("book");
	string name;
	int chap,sec;
	do{
		cout<<"\n1.Insert Chapter\n2.Insert Section\n3.Insert Subsection\n4.print\n5.Exit";
		cout<<"\nEnter your choice:";
		cin>>choice;
		switch(choice){
			case 1: cout<<"\nEnter Chapter:";
					cin>>name;
					addChild(root,name);
					break;
			case 2: cout<<"\nEnter section:";
					cin>>name;
					cout<<"\nEnter The number of chapter in which you want to insert a section";
					cin>>chap;
					addChild(root->children[chap-1],name);
					break;
			case 3: cout<<"\nEnter sub section:";
					cin>>name;
					cout<<"\nIn which Chapter & section you want to add subsection";
					cin>>chap>>sec;
					addChild(root->children[chap-1]->children[sec-1],name);
					break;
			case 4: cout<<"\n\n";
					preorderTraversal(root);
					cout<<"\n\n";
					break;
			case 5: cout<<"Thanks for using!!!!";
					break;
			default: cout<<"Enter valid choice";
		}
	}while(choice!=5);
}

