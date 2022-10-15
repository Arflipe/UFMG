#include "LimitedQueue.hpp"
#include "Exceptions.hpp"

LimitedQueue::LimitedQueue(int max_size){
	if(max_size <= 0){
		throw InvalidSizeException();
	}
	maxsize = max_size;
}

void LimitedQueue::push_back(int k){
	if(queue.size() >= maxsize){
		throw QueueFullException();
	}
	queue.push_back(k);
}

void LimitedQueue::pop_front(){
	if(queue.size() == 0){
		throw QueueEmptyException();
	}
	queue.pop_front();
}

int LimitedQueue::front(){
	if(queue.size() == 0){
		throw QueueEmptyException();
	}
	return queue.front();
}

int LimitedQueue::back(){
	if(queue.size() == 0){
		throw QueueEmptyException();
	}
	return queue.back();
}

int LimitedQueue::find(int k){
	if(queue.size() == 0){
		throw QueueEmptyException();
	}
	list<int>::iterator findIter;
	int posicao = 0;
	for(findIter = queue.begin(); findIter != queue.end(); findIter++, posicao++)
	{
		if(*findIter == k){
			return posicao;
		}
	}
	throw ItemNotFoundException();
}

void LimitedQueue::print(){
	if(queue.size() == 0){
		throw QueueEmptyException();
	}
	list<int>::iterator it;
	for(it = queue.begin(); it != queue.end(); it++){
		cout << *it << endl;
	}
}

int LimitedQueue::get_max_size(){
	return maxsize;
}