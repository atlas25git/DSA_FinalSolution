#include<bits/stdc++.h>
using namespace std:

int main()
{
    int t;
    int n;
    cin >> t;

    while(t--)
    {
        cin>>n;
        double ans = 0;

        for(int i=0; i<=n; i++)
            ans += n/(i*1.0);

        cout<< fixed << setprecision(6) << ans << endl;
    }
    return 0;
}