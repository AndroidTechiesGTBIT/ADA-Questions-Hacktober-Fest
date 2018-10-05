#include<iostream.h>
#include<conio.h>
class node
{
	int data;
	node *next;
public:
	node* insbeg(node *head);
	node* insend(node *head);
	node* insbefele(node *head);
	node* insaftele(node *head);
	node* deleteele(node *head);
	void traverse(node *head);
	node* reverse(node *head);
	node* sort(node *head);
	node* deletealt(node *head);
	node* inssorted(node *head);
	void display(node *head);

};
node *node::insbeg(node* head)
{
	 node *temp = new node();
	 cout<<"Enter element\n";
	 cin>>temp->data;
	 temp->next = head;
	 head = temp;
	 return head;
}
node *node::insend(node* head)
{
	node *temp = new node();
	node *cur = head;
	cout<<"Enter element\n";
	cin>>temp->data;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
		return head;
	}
	while((cur->next) != NULL)
		cur = cur->next;
	cur->next = temp;
	return head;
}
node* node::insbefele(node* head)
{
	int f;
	node *temp = new node();
	node *cur = head;
	cout<<"Enter element\n";
	cin>>temp->data;
	temp->next = NULL;
	cout<<"Enter element to insert before\n";
	cin>>f;
	if(head == NULL)
	{
		cout<<"Empty list\nInserting...\n";
		head = temp;
		return head;
	}
	else if(cur->data == f)
	{
		temp->next = head;
		head = temp;
		return head;
	}
	while(((cur->next)->data) != f && (cur->next) != NULL)
		cur = cur->next;
	if((cur->next) == NULL)
	{
		cout<<"Element not found\n";
		return head;
	}
	else
	{
		temp->next = cur->next;
		cur->next = temp;
	}
	return head;
}
node* node::insaftele(node* head)
{
	int f;
	node *temp = new node();
	node *cur = head;
	cout<<"Enter element\n";
	cin>>temp->data;
	temp->next = NULL;
	cout<<"Enter element to insert after\n";
	cin>>f;
	if(head == NULL)
	{
		cout<<"Empty list\nInserting...\n";
		head = temp;
		return head;
	}
	while((cur->data) != f && (cur->next) != NULL)
		cur = cur->next;
	if((cur->next) == NULL)
	{
		cout<<"Element not found\n";
		return head;
	}
	else
	{
		temp->next = cur->next;
		cur->next = temp;
	}
	return head;
}
node* node::deleteele(node* head)
{
	int f;
	node *prev, *temp;
	node *cur = head;
	node *p;
	if(head == NULL)
	{
		cout<<"Empty list\n";
		return head;
	}
	cout<<"Enter element to delete\n";
	cin>>f;
	while(cur != NULL && cur->data != f)
	{
		prev = cur;
		cur = cur->next;
	}
	if(cur == head)
	{
		temp = head;
		head = head->next;
		delete(temp);
		return head;
	}
	else if(cur == NULL)
	{
		cout<<"Element not found\n";
		return head;
	}
	else if(cur->next == NULL)
	{
		prev->next = NULL;
		delete(cur);
		return head;
	}
	else
	{
		prev->next = cur->next;
		delete(cur);
		return head;
	}
}
void node::traverse(node *head)
{
	int pos, c = 1;
	node *cur = head;
	cout<<"Enter the node you want to traverse to\n";
	cin>>pos;
	while((cur->next) != NULL && c <= pos)
	{
		cur = cur->next;
		c++;
	}
	if(c == pos)
	{
		cout<<"Data: "<<cur->data<<endl;
		return;
	}
	else if((cur->next) == NULL)
	{
		cout<<"Position not in list\n";
		return;
	}
}
node* node::reverse(node *head)
{
	node *p, *q, *r;
	q = NULL;
	p = head;
	while(p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	head = q;
	return head;
}
node* node::sort(node *head)
{
	node *p, *q;
	int temp;
	q = head;
	while(q != NULL)
	{
		p = q->next;
		while(p != NULL)
		{
			if(q->data > p->data)
			{
				temp = q->data;
				q->data = p->data;
				p->data = temp;
			}
			p = p->next;
		}
		q = q->next;
	}
	return head;
}
node* node::deletealt(node *head)
{
	return head;
}
node* node::inssorted(node *head)
{
	node *cur = head;
	node *temp = new node();
	cout<<"Enter element\n";
	cin>>temp->data;
	temp->next = NULL;
	if(head == NULL)
	{
		cout<<"Empty list\nInserting...\n";
		head = temp;
		return head;
	}
	while((cur->next)->data <= temp->data && cur->next != NULL)
		cur = cur->next;
	temp->next = cur->next;
	cur->next = temp;
	return head;
}
void node::display(node *head)
{
	node *cur = head;
	if(head == NULL)
	{
		cout<<"Empty list\n";
		return;
	}
	cout<<cur->data<<endl;
	while((cur->next) != NULL)
	{
		cur = cur->next;
		cout<<cur->data<<endl;
	}
}

void main()
{
	clrscr();
	node *head = NULL;
	node obj;
	int c;
	char d;
	do
	{
		cout<<"1.Insert at start\n2.Insert at end\n3.Insert before element\n4.Insert after element\n";
		cout<<"5.Insert sorted\n6.Delete element\n7.Delete alternate\n8.Traverse\n9.Reverse\n10.Sort\n11.Display\n";
		cin>>c;
		switch(c)
		{
			case 1:
				head = obj.insbeg(head);
				break;
			case 2:
				head = obj.insend(head);
				break;
			case 3:
				head = obj.insbefele(head);
				break;
			case 4:
				head = obj.insaftele(head);
				break;
			case 5:
				head = obj.inssorted(head);
				break;
			case 6:
				head = obj.deleteele(head);
				break;
			case 7:
				head = obj.deletealt(head);
			case 8:
				obj.traverse(head);
				break;
			case 9:
				head = obj.reverse(head);
				break;
			case 10:
				head = obj.sort(head);
				break;
			case 11:
				obj.display(head);
		}
		cout<<"Do you want to continue? (y/n)\n";
		cin>>d;
	}
	while(d != 'n');
	getch();
}