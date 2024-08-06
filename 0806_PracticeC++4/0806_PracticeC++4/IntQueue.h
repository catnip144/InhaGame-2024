#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

struct IntQueue
{
	int max = 0;
	int num = 0;
	int front = 0;
	int rear = 0;
	int* que = NULL;
};

int Initialize(IntQueue* q, int max);
int Enque(IntQueue* q, int x);
int Deque(IntQueue* q, int* x);
int Peek(const IntQueue* q, int* x);
void Clear(IntQueue* q);
int Capacity(const IntQueue* q);
int Size(const IntQueue* q);
bool IsEmpty(const IntQueue* q);
bool IsFull(const IntQueue* q);
int Search(const IntQueue* q, int x);
void Print(const IntQueue* q);
void Terminate(IntQueue* q);