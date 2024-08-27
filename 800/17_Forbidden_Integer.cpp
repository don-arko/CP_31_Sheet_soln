/*

https://codeforces.com/problemset/problem/1845/A

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




const int N = 200005;

/*
The problem is about considering the least amount of cases possible. I propose the following options.

If x≠1, then you can always print n ones. So the answer is YES.

when x=1
If k=1, then no integer is available, so the answer is NO.

If k=2, then only 2 is available, so you can only collect even n. So if it's odd, the answer is NO.

Otherwise, you can always collect n with the following construction: if n is even 
then take 2, otherwise take 3. Then take (⌊n2⌋−1) twos. You can see that an even n
 only uses twos, so it fits the previous check. If it's odd, then k is at least 3, so 3 is allowed to take.

Overall complexity: O(n) per testcase.


*/
void solve() {
    int n, k,x;
    cin>>n>>k>>x;


    if(x!=1){       //one is available then we can always construct.
        cout<<"YES\n";
        cout<<n<<endl;
        for(int i=1;i<=n;i++){
            cout<<1<<" ";
        }
        cout<<endl;
    }
    //one is not available i.e. x=1
    //under this condition we shall consider values of k 
    else {
        if(k==1){   //range is 1 to 1 and x =1 is forbidden hence no integer available
            cout<<"NO\n";
        }
        //k!=1
        else if(k==2){    //range is 1 to 2 and x =1 is forbidden hence only integer 2 is available
            //when i have only 2 then no. n must be even or else i cant make it up 
            if(n%2==0){
                cout<<"YES\n";
                cout<<n/2<<endl;
                for(int i=1;i<=n/2;i++){
                    cout<<2<<" ";
                }
                cout<<endl;
            }
            else{
                cout<<"NO\n";
            }
        }
        else{   //x = 1 (is forbidden) and k>2 => k>=3 => n>=3 as per constraint of Q
            //range is atleasst 1-> k(>=3)
            //can always construct cause we have the smallest even and odd primes i.e. 2 and 3 
            if(n%2==0){ // n is even 
                cout<<"YES\n";
                cout<<n/2<<endl;
                for(int i=1;i<=n/2;i++){
                    cout<<2<<" ";
                }
                cout<<endl;
            }
            else{ // n is odd 
                cout<<"YES\n";
                cout<<1+(n-3)/2<<endl;
                cout<<3<<" ";
                for(int i=1; i<=(n-3)/2;i++){
                    cout<<2<<" ";
                }
                cout<<endl;

            }
        }
    }
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
