#include<queue>
#include<stack>
#include<iostream>

using namespace std;

#ifndef BST_H
#define BST_H

template<class T>
class Queue:public queue<T>{
	public:
		T dequeue(){
			T tmp = queue<T>::front();
			queue<T>::pop();
			return tmp;
		}
		void enqueue(const T& el){
			queue<T>::push(el);
		}
};

template<class T>
class BSTNode{
	public:
		BSTNode(){
			left = right =0;
		}
		BSTNode(const T& e,BSTNode<T> *l = 0,BSTNode<T> *r = 0){
			el = e;
			left = l;
			right = r;
		}
		T el;
		BSTNode<T> *left,*right;
};

template<class T>
class BST{
	public:
		BST(){
			root =0;
		}
		BST(BSTNode<T> *r){
			root = r;
		}
		~BST(){
			clear();
		}
		void clear(){
			clear(root);
			root = 0;
		}

		bool isEmpty(){
			return root == 0;
		}
		void preorder(){
			preorder(root);
		}
		void inorder(){
			inorder(root);
		}
		void postorder(){
			postorder(root);
		}
		void breadthFirst();

	protected:
		BSTNode<T> *root;
		void clear(BSTNode<T>*);
		void preorder(BSTNode<T>*);
		void inorder(BSTNode<T>*);
		void postorder(BSTNode<T>*);
	public:
		virtual void visit(BSTNode<T>* p){
			std::cout<<p->el<<' ';
		}
};
#endif
