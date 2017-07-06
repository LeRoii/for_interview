#include"BST.h"

template<class T>
void breadth(BSTNode<T> *r)
{
	Queue<BSTNode<T>*> queue;
	BSTNode<T> *p = r;
	if(p!=0)
	{
		queue.enqueue(p);
		while(!queue.empty())
		{
			p = queue.dequeue();
			cout<<p->el<<' ';
			if(p->left!=0)
				queue.enqueue(p->left);
			if(p->right!=0)
					queue.enqueue(p->right);
		}
	}
}

int main()
{
	BSTNode<int> *rll = new BSTNode<int>(2);
	BSTNode<int> *rlr = new BSTNode<int>(12);
	BSTNode<int> *rrl = new BSTNode<int>(20);
	BSTNode<int> *rrrl = new BSTNode<int>(29);
	BSTNode<int> *rrr = new BSTNode<int>(31,rrrl);
	BSTNode<int> *rr = new BSTNode<int>(25,rrl,rrr);	
	BSTNode<int> *rl = new BSTNode<int>(10,rll,rlr);
	BSTNode<int> *r = new BSTNode<int>(13,rl,rr);

	BST<int> *BT = new BST<int>(r);

	//BT->visit(r);
	breadth<int>(r);
}

