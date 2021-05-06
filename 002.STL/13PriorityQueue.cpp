//push,pop -> O(logN), top->O(1), empty

#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int> pq; //maxHeap
    priority_queue<int,vector<int>,greater<int>> pq1;

    for(int i=0;i<10;i++){
        pq.push(i);
        pq1.push(i);
    }
    for(int i=0;i<10;i++)
    {
        int pqe = pq.top();
        int pqe1 = pq1.top();
        cout<<"maxHEap "<<pqe<<"\n";
        cout<<"minHEap "<<pqe1<<"\n";

        pq.pop();
        pq1.pop();
    }



    return 0;
}