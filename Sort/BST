#include <iostream>
#include<string>
#include <queue>
#include  "SortHelper.h"
 using namespace std;
 
 template <typename Key,typename Value=string>
 class BST{
 	private:
 	struct Node{
       Key key;
       Value value;
       Node * left;
       Node *right;
       Node(Key key, Value value){
       	this->key=key;
       	this->value=value;
       	this->left=this->right=NULL;
       	}
      Node(Node* node){
      	this->key=node->key;
      	this->value=node->value;
      	this->left=node->left;
      	this->right=node->right;
      	}     
 		};
 	Node *root;
 	int count;
 	
 	//insert a item(key,value) and return to root
 	Node * insert(Node * root1,Key key,Value value)
 	{
 		if (root1==NULL)   {count++;return new Node(key,value);}
     	if (key<=root1->key)  root1->left =insert(root1->left,key,value);
 		
 		else  root1->right=insert(root1->right,key,value);
 		return root1;
 		}
 		
 	void print(Node *node){
if (node==NULL) return;
 	
 		print(node->left);
 			 cout<<node->key<<"   ";
 		print(node->right);
 	}
 	
 	void printLevel(Node*node){
 		queue<Node *> q;
 		q.push(node);
 		while(!q.empty()){
 			Node * n=q.front();
 			if (n->left)  q.push(n->left);
 			if(n->right)  q.push(n->right);
 			cout<<n->key<<"  ";
 		   q.pop();
 			}
 		
 		}
 	void destroy(Node* node){
 		if(node==NULL) return;
 	   destroy(node->left);
 	   destroy(node->right);
 	   delete node;
 		count--;
 		}
 	
 	public:
 	BST(){
 		root=NULL;
 		count=0;}
 	~BST(){
 	 destroy(root);
 		}
 	int size(){
 		return count;
 		}
 	bool isEmpty(){
 		return   count==0;
 		}
 void insert(Key key,Value value){
 	root=insert(root,key,value);
 	}
 	void remove(Key key){
 		root=remove(root,key);
 		}
 void print(){
print(root);
  }
  
  void printLevel(){
  	printLevel(root);}
  	
 void  removeMin(){
 	root=removeMin(root);
 	}
  
  bool contain(Key key){
  	return contain(root,key);
  	}
  Value * search(Key key){
  	return  search(root,key);
  	}	
 void bstSort(Key arr[],int n){
  root=bstSort(root,arr ,n);
  	
  	}	
  	
  private:
 bool contain(Node* node,Key key){
  		if(node==NULL) return false;
  		if (node->key=key) return true;
  		if(node->key>key) return contain(node->left,key);
  		if (node->key<key) return contain(node->right,key);
 		
  		}
//return to a point that points the minimum node
    Node * minimum(Node * node)
    {
  	if (node->left==NULL) return node;
  	   return  minimum(node->left);
  	
  	}		
  	
  	Node* removeMin(Node* node){
  		if (node==NULL)return NULL;  		if (node->left==NULL){
  			Node *rightNode=node->right;
  			delete node;
  			count--;
  			return rightNode;
  			}
  		node->left=removeMin(node->left);
  		return node;
  		}
  	
  /*delete the node whose key=key and return the point that  point the new root*/
 Node * remove(Node *node,Key key){
 	if(node==NULL) return NULL;
 	if (node->key>key)  {node->left=remove(node->left,key);return node;}
 	  else if(node->key<key)  {node->right=remove(node->right,key) ;return node;}
 	    else{
 	    	if (node->left==NULL)  
{ 	    	Node * rightNode=node->right;delete node;count--;
      if(rightNode)    rightNode=remove(rightNode,key);return rightNode;}
 	    	if (node->right==NULL) { Node * leftNode=node->left;delete node;count--;
 	    	if (leftNode) leftNode=remove(leftNode,key);    return leftNode;}
 	    
 	   
 	    Node * successor=minimum(node->right);
 	    Node * successorCopy=new Node(successor);
 	          count++;
 	      successorCopy->right=    removeMin(node->right);
 	          	
 	    successorCopy->left=node->left;
 	    delete node;
 	    count--;
       successorCopy= remove(successorCopy,key);
 	    	return successorCopy;
 	    	}
 	
 	}
 Value * search(Node *node,Key key){
 	
 	if(node==NULL) return NULL;
 	if (node->key=key)  return *node->value;
 	else if(node->key>key)  return search(node->left,key);
 	    else  return search(node->right,key);
 	} 		
  
 Node * bstSort(Node*node,Key arr[],int n){
 	Value value;
 	for (int i=0;i<n;i++)  insert(arr[i],value);
//insert (arr[1],value);
 	return  root;
 	} 		
  						
 	};
 	int main(){
 	BST<int>  test;
 	
	int n=1000;
  	int *arr=SortTestHelper::generateRandomArray(n,1,9);
 	//SortTestHelper::printArray(arr,n);
  	//SortTestHelper::testSort("BST Sort",test.bstSort,arr,n);
  	test.bstSort(arr,n);

    //    test.print();
  //  test.printLevel();
//cout<<  test.minimum(test.root)->key;
test.remove(1);
test.remove(2);
test.remove(3);
test.print();
              cout<<test.size();
    	delete[] arr;
 		
 		
 		}