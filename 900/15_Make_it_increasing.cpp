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

Editorial
We will process the elements of the sequence starting from the end of the sequence. Each element ai (1≤i≤n−1) will be divided by 2
 until it is less than ai+1. If at some point it turns out that ai+1=0, it is impossible to obtain the desired sequence.


Idea 

It was simple even I spotted it very easily but somehow implementation was giving me tle re... why i dont know  

idea is make a[i-1] < a[i] until this is achieved keep on  divinding and also check before dividing if [a-1] is already 0 we shouldnt divide further 

only when a[i] becomes zero and i != 0 then it is impossible to make the array strictly increasing cause if a[i]=0 how will i make a[i-1]<a[i].

*/

const int N = 200005;


void solve() {
    int n;cin>>n;
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    //print(a);
    int ops=0;
    for(int i=n-1;i>0;i--){    //this loop also handles n=1 then i=-1 and the loop never iterates and ops remains at 0
        if(a[i]==0){        //this check doesnt happen for a[0] since we are iterating for i=n-1 to 1 so for all other i if a[i]=0 then it is impossible to make the array increasing            cout<<-1<<endl;
            cout<<-1<<endl;
            return;
        }
        while(a[i-1]>=a[i] and a[i-1]>0){       //we should not iterating after a[i-1] becomes zero we should stop or else we will go on dividing 0/2 and into an infinite loop
            a[i-1]/=2;
            ops++;
        }
        //herein a[i-1] could be zero and we are check it in the next iteration
        //a[i-1]=0 is only acceptable when i=0 and for i=0 we are not putting the check 
        
    }

    cout<<ops<<endl;

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
