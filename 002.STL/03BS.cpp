#include<iostream>
#include<algorithm>

using namespace std;
//all the algos implemented here are O(NlogN)
int main()
{
    int arr[] = {2,3,4,4,4,4,4,4,4,4,5,6,7,8};

    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    cin>>key;
    bool it = binary_search(arr,arr+n,key);
    cout<<it<<"\n";

    //to get index, or no. of occurrence of an element we use 
    //lower_bound -> No. equal to or greater than given 
    //uppwer_bound -> First occurence of no. greater 
    //up-lb = No. of same elements

    auto lb = lower_bound(arr,arr+n,4);
    auto ub = upper_bound(arr,arr+n,4);

    cout<<"lb "<<lb-arr<<"\n"<<"ub "<<ub-arr<<"\nOcc "<<ub-lb;
}