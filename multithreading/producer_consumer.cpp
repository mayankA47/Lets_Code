/*
Producer Consumer problem
1. Have a buffer queue for tasks.
2. Only one of producers or consumers can access queue at a given time.
3. Producers can add to queue only if size < MAX_BUFFER_SIZE. Consumers can consume only when size > 0.
*/
#include<bits/stdc++.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

queue<int> buffer;
int MAX_BUFFER_SIZE = 10;
mutex sharedMutex;
condition_variable cv;


void produceTask(int producer_id, int task_id) {
    // acquire the lock
    unique_lock<mutex> lock(sharedMutex);
    cout << "Acquired lock by producer " << producer_id << endl;
    // wait unless queue is full
    cv.wait(lock, []{ return buffer.size() < MAX_BUFFER_SIZE; });
    
    buffer.push(task_id);
    cout << "Producer " << producer_id << " added task " << task_id << endl;
    
    cout << "Releasing lock " << endl;
    lock.unlock();
    cv.notify_one();
}

void consumeTask(int consumer_id) {
    // acquire the lock
    unique_lock<mutex> lock(sharedMutex);
    cout << "Acquired lock by consumer " << consumer_id << endl;
    // wait unless queue has some element
    cv.wait(lock, []{return buffer.size() > 0; });
    
    int task = buffer.front();
    buffer.pop();
    cout << "Consumer " << consumer_id << " consuming task " << task << endl;
    
    cout << "Releasing lock " << endl;
    lock.unlock();
    cv.notify_one();
}

int main() {
    // initialise 2 threads each for producer and consumer
    thread producer1([] {
        for (int task = 1; task <= 15; task++)
            produceTask(1, task);
    });
    thread producer2([] {
        for (int task = 16; task <= 30; task++)
            produceTask(2, task);
    });
    
    thread consumer1([] {
        for (int task = 1; task <= 15; task++)
            consumeTask(1);
    });
    thread consumer2([] {
        for (int task = 1; task <= 15; task++)
            consumeTask(2);
    });
    
    producer1.join();
    producer2.join();
    consumer1.join();
    consumer2.join();
    
    return 0;
}


