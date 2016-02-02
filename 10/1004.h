#include <iostream>
using namespace std;

template <class T>
struct Node {
	T data;
	Node* next;
};

template <class T>
struct qll {
	Node<T>* front = NULL;
	Node<T>* rear = NULL;

	void enqueue(T val) {
		Node<T>* temp = new Node<T>;
		temp->data = val;
		temp->next = NULL;
		if (front == NULL && rear == NULL) front = rear = temp;
		else {
			rear->next = temp;
			rear = temp;
		}
	}

	T dequeue() {
		Node<T>* temp = front;
		T val = temp->data;
		if (front == NULL) return NULL;
		if (front == rear) front = rear = NULL;
		else front = front->next;
		delete temp;
		return val;
	}

	void show() {
		if (front && rear) {
			Node<T>* current = front;
			while (current != rear) {
				cout << current->data << " ";
				current = current->next;
			}
			cout << current->data << endl;

		}
	}
};

template <class T>
struct qarr{
    T* queue;
    int len;
    int front;
    int rear;
    bool isEmpty(){
        if(front == -1 || rear == -1) return true;
        return false;
    }
    
    bool isFull(){
        if((rear+1)%len == front) return true;
        return false;
    }
    
    bool contains(T val){
        int it = front;
        while(it != rear){
            if(queue[it] == val) return true;
            it = (it+1)%len;
        }
        if(queue[it] == val) return true;
        return false;
    }
    
    void enqueue(T val){
        if(isFull()){ 
            cout << "Ful";
            return;
        }
        else if(isEmpty()){
            front = 0;
            rear = 0;
        }
        else rear = (rear+1)%len;
        queue[rear] = val;
    }

    void dequeue(){
        if(isEmpty()) return;
        else if(front == rear){
            front = -1;
            rear = -1;
        }
        else front  = (front+1)%len;
    }

    void show(){
        int i = front;
        while(i != rear){
            cout << queue[i] << " ";
            i = (i+1)%len;
        }
        cout << queue[i];
    }
    
    void construct(int length){
        front = -1;
        rear = -1;
        queue = new T[length];
        len = length;
    }
};

// can contain constructor:

// Queue(int x){
//     // set length
// }

// calling: Queue q(parameter)[array];