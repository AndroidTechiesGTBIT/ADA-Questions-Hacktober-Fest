#include <iostream>

struct ListNode{
	int data;
	struct ListNode* next;
};

struct Queue
{
	struct ListNode* front;
	struct ListNode* rear;
};

struct Queue* CreateQueue(){
	struct Queue* Q;
	struct ListNode* temp;
	Q = (struct Queue*)malloc(sizeof(struct Queue));

	if(!Q)
		return NULL;

	temp = (struct ListNode*)malloc(sizeof(struct ListNode));
	Q->front = Q->rear = NULL;
	return Q;
}

int isEmptyQueue(struct Queue* Q){
	return (Q->front == NULL);
}

void Enqueue(struct Queue* Q, int data){
	struct ListNode* newNode;
	newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	
	if(!newNode)
		return;

	newNode->data = data;
	newNode->next = NULL;
	if(Q->rear)
		Q->rear->next = newNode;
	Q->rear = newNode;

	if(Q->front == NULL)
		Q->front = Q->rear;
}

int Dequeue(struct Queue* Q){
	int data = 0;
	struct ListNode* temp;

	if(isEmptyQueue(Q)){
		printf("Queue is empty\n");
		return 0;
	}
	else{
		temp = Q->front;
		data = Q->front->data;
		Q->front = Q->front->next;
		free(temp);
	}
	return data;
}

void DeleteQueue(struct Queue* Q){
	struct ListNode* temp;
	while(Q){
		temp = Q->front;
		Q->front = Q->front->next;
		free(temp);
	}
	free(Q);
}
