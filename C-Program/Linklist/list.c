#include<iostream>
using namespace std;

class Node
{
	public:
	int data;
	class Node *next;

	Node(int data)
	{
		this->data=data;
		this->next=NULL;
	}
};

class Linklist
{
	Node *head;
	Node *tail;

	public:
	Linklist()
	{
		head=NULL;
		tail=NULL;
	}
	~Linklist()
	{
		Node *trav=head;
		while(head)
		{
			head=head->next;
			delete trav;
		}
		head=NULL;
		tail=NULL;
	}

	void print()
	{
		Node *trav=head;

		while(trav)
		{
			cout<< trav->data << "->";
			trav=trav->next;
		}
		cout<< " NULL" <<endl;
	}

	void addListBeg(int data)
	{
		if(head==NULL&&tail==NULL)
		{
			head= new Node(data);
			tail=head;
		}
		else
		{
			Node *temp=new Node(data);
			temp->next=head;
			head=temp;
		}
	}

	void addListEnd(int data)
	{
		if(head==NULL&&tail==NULL)
		{
			addListBeg(data);
		}
		else
		{
			Node *temp=new Node(data);
			tail->next=temp;
			tail=temp;
		}
	}

	int count()
	{

		int cnt=0;
		Node *trav=head;
		while(trav)
		{
			cnt++;
			trav=trav->next;
		}
		return cnt;
	}

	void addListPos(int data, int pos)
	{
		if(pos==1)
		{
			addListBeg(data);
		}
		else if(pos <= (count()+1))
		{
			if(pos==(count()+1))
			{
				addListEnd(data);
			}
			else
			{
				Node *trav=head;
				int cnt=1;
				while(trav && cnt < (pos-1))
				{
					cnt++;
					trav=trav->next;
				}
				Node *temp=new Node(data);
				temp->next=trav->next;
				trav->next=temp;
			}
		}
		else
		{
			cout << "\nplease enter valid position\n";
		}
	}

	void deleteListBeg()
	{
		if(head==NULL&&tail==NULL)
		{
			cout<<"\nlist is empty\n";
		}
		else
		{
			if(head==tail)
			{
				cout <<"\n"<<head->data<<" deleted\n";
				delete head;
				head=NULL;
				tail=NULL;
			}
			else
			{
				Node *temp=head;
				head=head->next;
				cout << "\n"<<temp->data<<" deleted\n";
				delete temp;
			}
		}
	}

	void deleteListEnd()
	{
		if(head==tail)
		{
			deleteListBeg();
		}
		else
		{
			Node *trav=head;
			while(trav->next!=tail)
			{
				trav=trav->next;
			}

			trav->next=NULL;
			cout <<"\n"<<tail->data<<" deleted\n";
			delete tail;
			tail=trav;
		}
	}

	void deleteListPos(int pos)
	{
		if(pos==1)
		{
			deleteListBeg();
		}
		else if(pos <= count())
		{
			if(pos == count())
			{
				deleteListEnd();
			}
			else
			{
				Node *trav=head;
				int cnt=1;
				while(trav && cnt < (pos-1))
				{
					cnt++;
					trav=trav->next;
				}
				Node *temp=trav->next;
				trav->next=temp->next;
				cout <<"\n"<<temp->data<<" deleted\n";
				delete temp;
			}
		}
		else
		{
			cout << "\nplease enter valid position\n";
		}
	}

};	
int main()
{
	Linklist list;

	list.addListBeg(2);
	list.addListBeg(1);
	list.addListEnd(3);
	list.addListPos(5,4);
	list.addListPos(0,6);
	list.addListPos(4,4);
	list.print();
	list.deleteListBeg();
	list.deleteListEnd();
	list.deleteListPos(6);
	list.deleteListPos(2);
	list.print();
	list.deleteListPos(1);
	list.print();
	return 0;
}
