#include "IntQueue.h"

int Initialize(IntQueue* q, int max)
{
	q->que = (int*)calloc(max, sizeof(int));

	if (q->que == NULL)
		return -1;

	q->max = max;
	return 0;
}

int Enque(IntQueue* q, int x)
{
	if (IsFull(q))
		return -1;

	q->que[q->rear] = x;
	q->num++;
	q->rear = (q->rear + 1) % q->max;
	return 0;
}

int Deque(IntQueue* q, int* x)
{
	if (IsEmpty(q))
		return -1;

	*x = q->que[q->front];
	q->que[q->front] = 0;
	q->num--;
	q->front = (q->front + 1) % q->max;
	return 0;
}

int Peek(const IntQueue* q, int* x)
{
	if (IsEmpty(q))
		return -1;

	*x = q->que[q->front];
	return 0;
}

void Clear(IntQueue* q)
{
	for (int i = 0; i < q->max; i++)
		q->que[i] = 0;
	q->front = 0;
	q->rear = 0;
	q->num = 0;
}

int Capacity(const IntQueue* q)
{
	return q->max;
}

int Size(const IntQueue* q)
{
	return q->num;
}

bool IsEmpty(const IntQueue* q)
{
	return Size(q) == 0;
}

bool IsFull(const IntQueue* q)
{
	return Size(q) == q->max;
}

int Search(const IntQueue* q, int x)
{
	int start = q->front;
	int end = q->rear;

	if (start > end)
		end += q->max;

	for (int i = start, index = 0; i < end; i++, index++)
	{
		if (q->que[i % q->max] == x)
			return index;
	}
	return -1;
}

void Print(const IntQueue* q)
{
	int start = q->front;
	int end = q->rear;

	if (start > end)
		end += q->max;

	cout << "\n==== ÇöÀç Å¥ ====\n";
	for (int i = start; i < end; i++)
		cout << q->que[i % q->max] << " ";
	cout << endl;
}

void Terminate(IntQueue* q)
{
	free(q->que);
}
