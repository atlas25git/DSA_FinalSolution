 map<pair<int,int>,int> mp;
        cin>>m;
        for(i=0;i<m;i++){
            point temp;
            cin>>temp.x>>temp.y;
            mp[{temp.x,temp.y}]++;
            p.pb(temp);
        }