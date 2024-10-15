/*
https://codeforces.com/problemset/problem/1876/A

     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात् ||
*/

#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}


/*-------------------------------------------------------------------------------------------------*/

/*
Editorial:-

Notice that since there are n residents, there must be n shares.There are two types of shares. 
A share directly by Pak Chanek to a resident, and a share by a resident to another resident. 
A share by Pak Chanek is unlimited, while a share by a resident is limited by ai. So there 
are unlimited shares with cost p and for each i, there are ai shares with cost bi.

In the beginning, no residents are notified about the announcement, so Pak Chanek must share 
once to some resident in the beginning.After that, since there are n−1 residents remaining,
there must be n−1 shares. Theoretically, the lowerbound of the minimum cost is the n−1 cheapest 
shares (including Pak Chanek's shares). Turns out, there is always a strategy to use the n−1
 cheapest shares to notify all n residents after the first share by Pak Chanek.

The strategy is we share the announcement to the residents with the smallest values of bi first. 
Using the fact that ai≥1, we can deduce that we will always have a resident with an available share.

We can solve this using a simple sorting or a priority queue. Keep in mind about the unlimited shares with cost p.

Time complexity for each test case: O(nlogn)
*/


const int N = 200005;


void solve() {
    int n,p;cin>>n>>p;
    int a[n],b[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<pair<int,int>> cost_cap;
    for(int i=0;i<n;i++){
        cost_cap.pb({b[i],a[i]});
    }
    //inserting cheif Pak chanek into this vec of pair with cost =p and cap = inf (although we req atmost n)
    cost_cap.pb({p,n+1});
    sort(all(cost_cap));

    //initially pak chanaek has to notify one of the residents and we greedily notify the resident whose cost of sharing is minimum.
    int total=1;
    
    int cost=p;
    //now all the costs for sharing(inc p) is within the vec of pair with two guys aware of the notification the guy with min cost and the chief pak chanek
    //now they are the only two probable only two probablel candidates who will be at the begining of the array.
    //pak chanek will be at the begining if p< cost min or else the guy to whom pak shared the info with having min cost will be at the begining of the vec
    //main point of who will be at the beggining is that whoever is at the beggining has the minimum cost of sharing , so we will try to pick him for sharing so he must be already aware of the accouncement or else he can't share it , so its seen that the first guy is always aware

    //we will greedy use all the limit of the current guy and only share info the next guy with min cost ; after exhaustion of limit of the current guy that guy can continue sharing, cause he has the next lowest cost.
    int i=0;
    while(total<n){
        int left=n-total;
        //if the ith guy can alone share the announcement to all the left guys alone.
        if(cost_cap[i].second>=left){
            total=n;
            cost+=left*cost_cap[i].first;
        }
        else{ //cap[i]<left when the i-th guy alone cant share the announcement with all the left residents he will share till his limit .
            total+=cost_cap[i].second; //nos shared.
            cost+= cost_cap[i].second*cost_cap[i].first; //nos shared * cost
        }

        i++;
    }

    cout<<cost<<endl;
}



/*-------------------------------------------------------------------------------------------------*/



int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

/*-------------------------------------------------------------------------------------------------*/


    int t = 1;
    cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;


/*-------------------------------------------------------------------------------------------------*/
}
