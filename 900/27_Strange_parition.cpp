/*

https://codeforces.com/problemset/problem/1471/A

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

Note that, ⌈a+bx⌉≤⌈ax⌉+⌈bx⌉. It means that the maximal sum is attained if we do not apply any operations, and 
the minimal one is attained if we replace all the element with a single one, equal to the sum of all elements.


Implementation of Ceil (without making variables as float which is required when we try to use the inbuilt ceil function.)

mn=sum/x + (sum%x!=0)        when sum is not divisible by x (sum%x!=0) is true which means it becomes 1 and 1 is added to floor of sum/x;
will implement mn= ceil(sum/x);                              _________
                                                                  |
                                                                  |=> acts as condition due to the '!=' hence outputs only 0 and 1 and serves out purpose 

                                                            if instead we use (sum&x) it wont act condition due to the mere presence of the parenthesis, hence its gives >1 values 
                                                            as output and is unfit to serve our purpose
                                                            but if(sum%x)  will act as condition cause its only only mere parenthesis but it is present beside the if statement where 
                                                            there condition is meant to be .
*/

const int N = 200005;


void solve() {
    int n,x;cin>>n>>x;
    //bug(n,x);
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum+=a[i];    
    }
    //way to calculate ceil
    int mn=sum/x + (sum%x!=0) ;  //when sum is not divisible by x (sum%x!=0) is true which means it becomes 1 and 1 is added to floor of sum/x;
    //mind we just cant use (sum%x) cause it doesnt return true or false hence 0 and 1 so it could add >1 vals and adversely afftect the result .

  
    int mx=0;
    for(int i=0;i<n;i++){
        int z=a[i]/x+(a[i]%x!=0);
        mx+=z;
    }

    cout<<mn<<" "<<mx<<endl;





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
