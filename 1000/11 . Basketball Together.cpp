/*
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
For a team of c players with a biggest power of b, the total power of the team is b×c. So for a team with a biggest power of b
to win, it needs to have at least ⌈D+1/b⌉ players.
For each player i, we can calculate a value f(i) which means a team that has player i as its biggest power needs to have at least f(i)
players to win. We can see that the bigger the value of Pi, the smaller the value of f(i).
We can also see that if a formed team is said to have a fixed biggest power and a fixed number of players, the powers of the players 
that are less than the biggest power do not affect the total power of the team. So those players can be anyone.
Using the information above, we can form the teams using a greedy method. We iterate through each candidate player starting from the biggest Pi
and form new teams with each next biggest candidate player power as each team's biggest power. We do that while maintaining the total number of 
extra players required to make all formed teams win. We stop once the number of remaining players is not enough for the total number of extra 
players required.

Time complexity: O(NlogN)

The editorial is a greedy based approach , and i have also used a nice greedy based approach kinda two pointer approach learned from CSES
*/

const int N = 200005;


void solve() {
    int n,d;cin>>n>>d;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);

    if(a[0]>d){
        cout<<n<<endl;// all go alone
        return;
    }
    int ans=0;
    int l=0;
    int r=n-1;
    int sum=a[r];//sum always denotes the power of the most power guy in the current team we are considering.
    //print(a);

    while(l<r){
        //when a[r]>d -> r goes alone as the team r--
        //when a[r]+a[r]>d  -> r and l makes up the team ans++ r--, l++;
        //when a[r]+a[r]<=d -> add more player into the team -> l++

        if(a[r]>d){ //r can along form a team , then why to waste the player l
            ans++;
            r--;
            continue;   //skips this iteration of the while loop.
        }



        //(sum,a[l],a[r]);

        sum+=a[r];  //adding the contri of l which is a[r] i.e. l gets added to the team increasing its power by a[r]
        if(sum>d){ //after contri of l they are able to beat d so we got a team here 
            ans++;
            r--;
            sum=a[r];
            l++;
        }
        else{  //still cant beat d so adding more members (l++) to the team
            l++;
        }
    }
    cout<<ans<<endl;

    
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
    // cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;


/*-------------------------------------------------------------------------------------------------*/
}
