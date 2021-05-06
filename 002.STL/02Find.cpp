#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int arr[] = {2,3,4,5,6,7,8};

    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    cin>>key;
    auto it = find(arr,arr+n,key);
    cout<<it-arr<<"\n";


}
//if n then not present, n-1 last