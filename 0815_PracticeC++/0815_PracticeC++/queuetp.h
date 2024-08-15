#pragma once

template <class T>
class QueueTp
{
private:
	enum {SIZE = 10};
	int queueSize;
	int front;
	int rear;
	T* items;

public:
	explicit QueueTp(int size = SIZE);
	QueueTp(const QueueTp& qt);
	~QueueTp();

	bool Enqueue(const T& item);
	bool Dequeue();

	bool IsEmpty() { return queueSize == 0; }
	bool IsFull() { return queueSize == SIZE; }

	T& Front() { return items[front]; }
	T& Rear();

	int FrontIndex() { return front; }
	int RearIndex() { return rear; }
	int MaxSize() { return SIZE; }

	T* GetItems() { return items; }
};

template <class T>
QueueTp<T>::QueueTp(int size) : front(0), rear(0)
{
	items = new T[SIZE];
	queueSize = 0;
}

template <class T>
QueueTp<T>::QueueTp(const QueueTp& qt)
{
	queueSize = qt.queueSize;
	front = qt.front;
	rear = qt.rear;
	items = new T[SIZE];

	int start = front;
	int end = rear;

	while (start != end)
	{
		items[start] = qt.items[start];
		start = (start + 1) % SIZE;
	}
}

template<class T>
inline QueueTp<T>::~QueueTp()
{
	int start = front;
	int end = rear;

	while (start != end)
	{
		delete items[start];
		start = (start + 1) % SIZE;
	}
	delete[] items;
}

template <class T>
bool QueueTp<T>::Enqueue(const T& item)
{
	if (IsFull())
		return false;

	items[rear] = item;
	queueSize++;
	rear = (rear + 1) % SIZE;
	return true;
}

template <class T>
bool QueueTp<T>::Dequeue()
{
	if (IsEmpty())
		return false;

	items[front] = NULL;
	queueSize--;
	front = (front + 1) % SIZE;
	return true;
}

template<class T>
inline T& QueueTp<T>::Rear()
{
	if (rear == 0)
		return items[SIZE - 1];
	else
		return items[rear - 1];
}
