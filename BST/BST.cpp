#include"BST.h"

template<class T>
void BST<T>::clear(BSTNode<T>* nd)
{
	if(nd)
	{
		delete nd;
		nd = NULL;
	}
}

template<class T>
void BST<T>::breadthFirst()
{
	Queue<BSTNode<T>*> queue;
	BSTNode<T> *p = root;
	if(p!=0)
	{
		queue.enqueue(p);
		while(!queue.empty())
		{
			p = queue.dequeue();
			visit(p);
			if(p->left!=0)
				queue.enqueue(p->left);
			if(p->right!=0)
					queue.enqueue(p->right);
		}
	}
}


