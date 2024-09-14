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

Let's iterate over the number that we want to multiply by m.

How can we check that we can multiply the current number so that an AP is formed?

Note that those 2 numbers that we do not touch should form an AP themselves. For instance, let at the current operation we want somehow
multiply the number c. Then a=x1, and b=x2=x1+d.

Note that b−a=x1+d−x1=d. Thus, we know what d is. Also we know that c=x1+2⋅d=a+2⋅d. Let's check if a+2⋅d is divisible by c. 
If yes, then we have found the answer, if not, then move on to the next number.

We do the same for a and b.

Be careful with non positive numbers, integer divisions and other edge cases.
*/

const int N = 200005;


void solve() {
    int a,b,c;      //a,b,c >=1 


    cin>>a>>b>>c;
    //bug(a,b,c);
    //trying to change c to mc ; mc>=c i.e. m>=1 (cause m has to be a positive integer -> m starts from 1 ) and mc/c= m (<- I) 
        //a and b are in AP
    //using seperate blocks so as to reuse variables with same names
    {
        int d=b-a;
        //bug(d);
        int c_=b+d;
        //bug(c_);
        //c_ should be greater than equal to c for m>=1 and c to should divide c_ for m to be an integer and since a,b,c>=1 therefore c_>=c -> c_ >0 so c_%c is never 0 because of c_ is 0
        if(c_>=c and c_%c==0){
            cout<<"YES\n";
            return;
        }
    }
    

    //cout<<"outside first if\n";

    //trying to change b to mb
    {
        int d_2 = c-a;
        //bug(d_2);
        if(d_2%2==0){
            int d=d_2/2;
            int b_=a+d;
            if(b_>=b and b_%b==0){
                cout<<"YES\n";
                return;
            }
        }

    }
    //cout<<"OUTSIDE 2nd if\n";
    
    


    //trying to change a to ma ; ma>=a i.e. m>=1
        //a and b are in AP
    int d=c-b;

    int a_=b-d;
    if(a_>=a and a_%a==0){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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
