#include <iostream>
using namespace std;

class Node
{
public:
	Node();
	Node(int);
	Node(Node, int);
	Node* next;
	int Data();
	bool HasParentCheck();
	void ProveParent(Node &other);

private:
	int _data;
	bool _noParent;
};

Node::Node()
{
	_data = 0;
	_noParent = true;
}

Node::Node(int d)
{
	_data = d;
	_noParent = true;
}

Node::Node(Node n, int d)
{
	next = &n;
	_data = d;
	_noParent = true;
}

int Node::Data()
{
	return _data;
}

bool Node::HasParentCheck()
{
	return _data;
}

void Node::ProveParent(Node &other)
{
	if (other.next == this)
	{
		_noParent = false;
	}
}

bool NodeSwap(Node &hNode, Node &lNode, Node &fNode)
{
	Node nPtr1 = Node();
	nPtr1.next = lNode.next;
	if (hNode.next == &lNode)
		lNode.next = &hNode;
	else
		lNode.next = hNode.next;

	Node nPtr2 = Node();
	nPtr2.next = &nPtr2;
	bool looped = false;

	while (nPtr2.next->next != &lNode)
	{
		if (!looped)
			nPtr2.next = &fNode;
		else
			nPtr2.next = nPtr2.next->next;

		looped = true;
	}
	nPtr2.next->next = &hNode;
	nPtr2.next = &nPtr2;
	looped = false;

	if (&hNode != &fNode)
	{
		while (nPtr2.next->next != &hNode)
		{
			if (!looped)
				nPtr2.next = &fNode;
			else
				nPtr2.next = nPtr2.next->next;

			looped = true;
		}
		nPtr2.next->next = &lNode;
		hNode.next = nPtr1.next;
	}
	else
	{

	}

	return true;
}

int main()
{
	Node node1(1);
	Node node2(2);
	Node node3(3);
	Node node4(4);
	Node node5(5);

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	Node nPtr = Node();
	nPtr.next = &node1;

	while (nPtr.next != nullptr)
	{
		cout << nPtr.next->Data() << endl;
		nPtr.next = nPtr.next->next;
	}

	nPtr.next = &node1;

	NodeSwap(node1, *node1.next->next->next, node1);

	//node1.next->next->next = node1.next;
	//node1.next = node1.next->next;
	//node1.next->next->next = nullptr;

	cout << endl;
	 
	while (nPtr.next != nullptr)
	{
		cout << nPtr.next->Data() << endl;
		nPtr.next = nPtr.next->next;
	}

	system("pause");
	return 0;
}