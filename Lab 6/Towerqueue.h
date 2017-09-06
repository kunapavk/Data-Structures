#ifndef Towerqueue_H
#define Towerqueue_H
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Towerqueue{
    private:
    vector<T> data_store;
    int Back;
    int Front;
    int Length;
    public:
    Towerqueue();
    void enqueue(T d);
    T dequeue();
    T peek();
	int length();
    bool isEmpty();
    bool isFull();//not sure vector will full since it can change its size automaticallys
    void makeEmpty();

};

template <class T>
Towerqueue<T>::Towerqueue(){
    Front = 0;
    data_store = {};
    Back = data_store.size();//vector has a build-in size function to get the size
    Length = data_store.size();
}

template <class T>
void Towerqueue<T>::enqueue(T d){
    data_store.push_back(d);
    Back = ((Back+1)%data_store.size());
    Length++;
}

template <class T>
T Towerqueue<T>::dequeue(){
    T ret_val = data_store[Front];
	data_store.erase(data_store.begin());
    Length--;
	return ret_val;
}

template <class T>
T Towerqueue<T>::peek(){
    return data_store[Front];
}

template <class T>
int Towerqueue<T>::length() {
	return data_store.size();
}

template <class T>
bool Towerqueue<T>::isEmpty(){
    return (data_store.size() == 0);
}

template <class T>
bool Towerqueue<T>::isFull(){
    return (Length == data_store.size());
}

template <class T>
void Towerqueue<T>::makeEmpty(){
    Front = 0;
    Back = 0;
    Length = 0;
	data_store = {};
}

#endif