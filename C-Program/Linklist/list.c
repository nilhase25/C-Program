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
	public:
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

	void reverseList()
	{
		Node *prev,*curr,*next;
		prev=next=NULL;
		curr=head;
		if(head==tail)
		{
			return;
		}
		tail=curr;
		while(curr)
		{
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
		head=prev;
	}
	
	void reverseList(int reverseNodeCount)
	{
		Node *prev,*curr,*next,*temp;
		int cnt=0;
		if(reverseNodeCount>count())
		{
			cout<<"reverse node count greater than list node count"<<endl;
		}
		prev=next=NULL;
		curr=temp=head;
		if(head==tail)
		{
			return;
		}
		tail=curr;
		while(curr && cnt<reverseNodeCount)
		{
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
			cnt++;
		}
		temp->next=next;
		head=prev;
	}
	
	void splitList(Node *frontNode,Node **lFrontNode, Node **rFrontNode)
	{
		Node *slowNode,*fastNode;
		fastNode=frontNode;
		while(fastNode)
		{
			slowNode=frontNode;
			fastNode=fastNode->next;
			if(fastNode)
			{
				fastNode=fastNode->next;
			}
		}
		*lFrontNode=frontNode;
		*rFrontNode=slowNode->next;
		slowNode->next=NULL;
	}

	Node* sortMergeList(Node *lFrontNode, Node *rFrontNode)
	{
		Node *mergeHead=NULL;
		if(lFrontNode==NULL)
		{
			return rFrontNode;
		}
		if(rFrontNode==NULL)
		{
			return lFrontNode;
		}
		if(lFrontNode->data<=rFrontNode->data)
		{
			mergeHead=lFrontNode;
			mergeHead->next=sortMergeList(lFrontNode->next,rFrontNode);
		}
		else
		{
			mergeHead=rFrontNode;
			mergeHead->next=sortMergeList(lFrontNode,rFrontNode->next);
		}
		return mergeHead;
	}

	Node* tailOfList()
	{
		Node *trav=head;
		if(trav==NULL)
		{
			return NULL;
		}
		while(trav->next!=NULL)
		{
			trav=trav->next;
		}
		return trav;
	}		

	void mergeListSort(Node **listHead)
	{
		Node *frontNode=*listHead;
		Node *lFrontNode=NULL,*rFrontNode=NULL;
		if(frontNode==NULL || frontNode->next==NULL)
		{
			return;
		}

		splitList(frontNode,&lFrontNode,&rFrontNode);
		mergeListSort(&lFrontNode);
		mergeListSort(&rFrontNode);
		*listHead=sortMergeList(lFrontNode,rFrontNode);
		tail=tailOfList();
		
	}



};	
int main()
{
	Linklist list;

	list.addListBeg(92);
	list.addListBeg(18);
	list.addListEnd(30);
	list.addListPos(85,4);
	list.addListPos(0,6);
	list.addListPos(4,4);
	list.print();
	list.mergeListSort(&list.head);
	cout<<endl<<"tail:"<<list.tail->data<<endl;
	list.print();
	list.reverseList();
	list.print();
	list.reverseList(3);
	list.print();
	list.reverseList(7);
	list.deleteListBeg();
	list.deleteListEnd();
	list.deleteListPos(6);
	list.deleteListPos(2);
	list.print();
	list.deleteListPos(1);
	list.print();
	return 0;
}
