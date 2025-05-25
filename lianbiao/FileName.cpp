#include<stdio.h>
#include <malloc.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct node
{
	ElementType data;
	struct node* Next;

}Node;

Node* Initial()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->Next = NULL;
	return head;
}

void InsertElement(Node* L, ElementType e)
{
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = e;
	q->Next = L->Next;
	L->Next = q;
}

void ListNode(Node* L)
{
	Node* q = L->Next;
	while (q != NULL)
	{
		printf("%d", q->data);
		q = q->Next;
	}
	printf("\n");
}

Node* InsertTail(Node* L, ElementType e)
{
	Node* q = (Node*)malloc(sizeof(Node));
	q= L->Next;
	while (q->Next != NULL)
	{
		q = q->Next;

	}
	Node* r = (Node*)malloc(sizeof(Node));
	r->data = e;
	r->Next = NULL;
	q->Next = r;

	return r;
}

int InsertPos(Node* L, int pos, ElementType e)
{
	int i = 0;
	Node* q = L;
	while (i < pos - 1)
	{
		q = q->Next;
		i++;

		if (q == NULL)
		{
			return 0;
		}
	}

	Node* r = (Node*)malloc(sizeof(Node));
	r->data = e;
	r->Next = q->Next;
	q->Next = r;

	return 1;
}

int DeleteNode(Node* L, int pos)
{
	Node* q = L;
	int i = 0;

	while (i <pos - 1)
	{
		q = q->Next;
		i++;
		if (q == NULL)
		{
			return 0;
		}
	}
	if (q->Next == NULL)
	{
		printf("É¾³ýÎ»ÖÃ´íÎó\n");
		return 0;
	}
	Node* r = (Node*)malloc(sizeof(Node));
	r = q->Next;
	q->Next = r->Next;
	free(r);
	
	return 1;
}


int FindDNode(Node* L, int k)
{
	Node* qlow = (Node*)malloc(sizeof(Node));
	Node* qfast = (Node*)malloc(sizeof(Node));
	qfast = L->Next;
	qlow = L->Next;
	int i = 0;
	while (i < k)
	{
		qfast = qfast->Next;
		i++;
	}
	while (qfast != NULL)
	{
		qfast = qfast->Next;
		qlow = qlow->Next;
	}
	printf("%d", qlow->data);
	return 1;
}

Node* FindSameNode(Node* L, Node* M)
{
	int m, n;
	m = 0, n = 0;
	Node* q1 = (Node*)malloc(sizeof(Node));
	Node* q2 = (Node*)malloc(sizeof(Node));
	q1 = L->Next;
	q2 = M->Next;
	int l = 0;
	while (q1 != NULL)
	{
		q1 = q1->Next;
		m++;
	}
	while (q2 != NULL)
	{
		q2 = q2->Next;
		n++;
	}
	if (m >= n)
	{
		l = m - n;
	}
	else
	{
		l = n - m;
	}
	int i = 0;
	Node* q3= (Node*)malloc(sizeof(Node));
	Node* q4= (Node*)malloc(sizeof(Node));
	q3 = L->Next;
	q4 = L->Next;
	while (i < l)
	{
		if (m > n)
		{
			q3 = q3->Next;
			i++;
		}
		else
		{
			q4 = q4->Next;
			i++;
		}
	}
	while (q3 != q4)
	{
		q3 = q3->Next;
		q4 = q4->Next;
	}
	return q3;
}

void DeleteSameData(Node* L, int n)
{
	Node* Q = L;
	
	int index;
	int* data1 = (int*)malloc(sizeof(n + 1));
	for (int i = 0;i <= n;i++)
	{
		data1[i] = 0;
	}
	while (Q->Next != NULL)
	{
		index = Q->Next->data;
		if (data1[index] == 0)
		{
			data1[index] = 1;
		}
		else
		{
			Node* K = Q->Next;
			Q->Next = K->Next;
			free(K);
		}
	}
	free(data1);
}


Node* ReverseList(Node*L)
{
	Node * q1 = NULL;
	Node* q2 = L->Next;
	Node* q3 ;

	while (q2 != NULL)
	{
		q3 = q2->Next;
		q2->Next = q1;
		q1 = q2;
		q2 = q3;
	}
	Node* q4 = Initial();
	q4->Next = q1;
	return q4;
}


void Reorder(Node* L)
{
	Node* fast = L;
	Node* slow = L;

	while (fast != NULL && fast->Next != NULL)
	{
		fast = fast->Next->Next;
		slow = slow->Next;
	}
	Node* q1 = NULL;
	Node* q2 = slow->Next;
	slow->Next = NULL;
	Node* q3 = NULL;
	while (q2 != NULL)
	{
	   q3 = q2->Next;
	   q2->Next = q1;
	   q1 = q2;
	   q2 = q3;
    }
	Node* q4 = L->Next;
	Node* q5 = q1;
	Node* q6;
	Node* q7;
	while (q4 != NULL && q5 != NULL)
	{
		q6 = q4->Next;
		q7 = q5->Next;

		q4->Next = q5;
		q5->Next = q6;

		q4 = q6;
		q5 = q7;
	}
}

int Judge(Node* L)
{
	Node* fast = L;
	Node* low = L;
	while (fast != NULL && fast->Next != NULL)
	{
		fast = fast->Next->Next;
		low = low->Next;
		if (fast == low)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	

}


int main()
{
	Node* M;
	M = Initial();
	Node* Two = (Node*)malloc(sizeof(Node));
	Node* Term = (Node*)malloc(sizeof(Node));
	Two->data = 1;
	Two->Next = NULL;
	M->Next = Two;
	Term = InsertTail(M, 10);
	Term = InsertTail(M, 20);
	Term = InsertTail(M, 30);
	ListNode(M);
	InsertPos(M, 2, 12);
	ListNode(M);
	Reorder(M);
	ListNode(M);
	DeleteNode(M, 2);
	ListNode(M);
	Node* N;
	N= ReverseList(M);
	ListNode(N);
	FindDNode(M, 1);
	return 0;
}