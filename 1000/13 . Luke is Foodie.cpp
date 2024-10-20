/*

https://codeforces.com/problemset/problem/1704/B

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
Editorial:- Wonderful execution of intersection.

For ai, if |v−ai|≤x, then ai−x≤v≤ai+x.

Then consider using the greedy strategy. We will only change v when we cannot find any possible v to satisfy the current conditions.

Therefore, we can determine the range of v. Initially, set l=a1−x,r=a1+x, then v∈[l,r]. For ai, change l=max(l,ai−x),r=min(r,ai+x). 
Once l>r, which means from the last time that we changed v to the current ai we cannot find any possible v to satisfy the all the 
conditions between the two positions, we should change l=ai−x,r=ai+x, and add 1 to answer.




Explaination of editorial.

Idea was that as long as the ranges for  the a[i]s are having a common intersection we can always chose a optimal v , and when intersection was null we need to change our v
Idea is to find the intersection of valid ranges of v for each of a[i] , as long as they are having a common intersection we dont need to change our v(we optimally chose such v)
the moment the intersection is NULL we have to change our v, hence ans++ and then again we set the range of v for this a[i] and again go on for checking interestion of the range of v.


Implementaion Details
For a[0] range of v is [a[0]-x,a[0]+x] = [l1,r1] = say (3,8)
For a[1] range of v is [a[1]-x],a[1]+x] = [l2,r2]  = say(5,10)
Their intersection is obvio [max(l1,l2),min(r1,r2)]=[l,r] general intution rightmost from left and leftmost from right on number line is the intersection
Also if l > r this means actually no intersection exists eg (3,8) A (10,15) = (10,8) 
Proof l>r => intersection = NULL
we know if intersection = NULL => r1<l2  and as l1<r1 and l2<=r2 =>l1<r1<l2<r2 =>  max(l1,l2)=l2 and min(r1,r2)=r1 clearly l=l2> r=r1 for NULL intersections
*/



const int N = 200005;


void solve() {
    int n,x;cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    } 
    int l=a[0]-x;
    int r=a[0]+x;
    int ans=0;
    for(int i=1;i<n;i++){
        l=max(l,a[i]-x); 
        r=min(r,a[i]+x);
        if(l>r){
            ans++;
            l=a[i]-x;
            r=a[i]+x;
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
     cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;


/*-------------------------------------------------------------------------------------------------*/
}
