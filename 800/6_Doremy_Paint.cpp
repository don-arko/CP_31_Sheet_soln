

/*

https://codeforces.com/problemset/problem/1890/A

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


void solve() {
    int n;
    cin>>n;
    vi v(n);


    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(n<3){
        cout<<"yes\n";
        return;
    }

    //total only two disntint elements should be present 
    //and the nos of one of them should be one more or one less the the other so that they can form alternate pairs like  12121212..

    sort(all(v));
    int d_s=1;
    int count_d1=1;
    int count_d2=1;
    bool flag=true;
    for(int i=1;i<n;i++){
        if(v[i]!=v[i-1]){
            //cout<<"if\n";
            bool flag=false;
            d_s++;
        }
        else{
            //cout<<"else\n";
            if(d_s==1){
                count_d1++;
            }
            else if(d_s==2){
                count_d2++;
            }
            
        }
        //bug(i,count_d1,count_d2);
    }
    //bug(d_s,count_d1,count_d2);
    if(d_s==2 and abs(count_d1-count_d2)<=1 or d_s==1){
        cout<<"yes\n";
    }
    else{
        cout<<"no\n";
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
