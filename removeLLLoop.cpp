#include <iostream>
using namespace std;
struct node
{
	struct node *next = NULL;
	int data;
};
void insertLL(struct node **root, int data)
{
	if ((*root) == NULL)
	{
		(*root) = new struct node;
		(*root)->data = data;
	}
	else
	{
		struct node *temp = (*root);
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = new struct node;
		temp->next->data = data;
	}
}

void RemoveLoop(struct node*temp, struct node*root)
{
	struct node*temp2 = temp, *temp1 = root;
	while (1)
	{
		temp2 = temp;
		while (temp2->next != temp && temp2->next != temp1)
			temp2 = temp2->next;
		if (temp2->next != temp)
			break;
		temp1 = temp1->next;
	}
	temp2->next = NULL;

}

void PrintLL(struct node*root)
{
	while (root != NULL)
	{
		cout << root->data << " ";
		root = root->next;
	}
}
int DetectAndRemoveLoop(struct node *root)
{
	struct node *temp1 = root, *temp2 = root;
	while ((temp1 != NULL) && (temp2 != NULL) && (temp2->next != NULL))
	{
		temp1 = temp1->next;
		temp2 = temp2->next->next;
		if (temp1 == temp2)
		{
			RemoveLoop(temp1, root);
			return 1;
		}
	}
	return 0;
}

int main()
{
	struct node *root = NULL;
	insertLL(&root, 1); insertLL(&root, 3); insertLL(&root, 10); insertLL(&root, 11); insertLL(&root, 21); insertLL(&root, 111); insertLL(&root, 17); insertLL(&root, -1); insertLL(&root, 15);
	cout << "Linked List without loop" << endl;
	if (DetectAndRemoveLoop(root))
		cout << "Loop Exists" << endl;
	else
		cout << "Loop doesnt exist" << endl;
	PrintLL(root);
	struct node*temp = root, *temp2 = root;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp2->data != 21)
		temp2 = temp2->next;

	temp->next = temp2;

	cout << "Linked List with loop now" << endl;
	if (DetectAndRemoveLoop(root))
		cout << "Loop Exists" << endl;
	else
		cout << "Loop doesnt exist" << endl;

	cout << "Loop removed now" << endl;
	if (DetectAndRemoveLoop(root))
		cout << "Loop Exists" << endl;
	else
		cout << "Loop doesnt exist" << endl;

	PrintLL(root);
}
