/*
    https://codeforces.com/contest/1831/problem/B
    
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
//#define print0(a)      while(it!=a.end()) {cout<<*it<< " "; it++;}
//#define print3(a)      while(it!=a.end()) {cout<<*it.first<< " "<<*it.second<<endl; it++;}
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

Hint - 1
When we merge two arrays a and b, we can force the resulting array to have [al1,al1+1,…,ar1,bl2,bl2+1,…,br1] as a subarray, for some 1≤l1≤r1≤n and 1 ≤ l2 ≤ r2 ≤n.

Hint - 2
If al1 = bl1, then we can achieve a contiguous sequence of (r1−l1+1)+(r2−l2+1) equal elements in the resulting array.

 Editorial:-

Let maxa(x) be the length of the longest subarray from a containing only elements equal to x. If x doesn't appear in a, then maxa(x)=0.
Similarly, let maxb(x) be the length of the longest subarray from b containing only elements equal to x. If x doesn't appear in b, then maxb(x)=0.
maxa and maxb can be computed in O(N) by scanning the array while updating current maximal subarray.
When merging two arrays, it is possible to force a particular subarray [al1,al1+1,…,ar1] to be adjacent to another particular
subarray [bl2,bl2+1,…,br2] in the merged array.

Proof
If al1=bl2, then the merged array will have a subarray consisting of (r1−l1+1)+(r2−l2+1) equal elements.

Therefore, the answer is equal to: max  i=1->2⋅n (maxa(i)+maxb(i))

Time complexity per testcase: O(N).




My Explaination : 
-Editorial me sab likh to diya ... ham koi bhi particular subarray from A ko koi bhi particular subarray from B k hamesha contiguous bana sakte hain while merging.
-Then, ans is what max(max_A(e)+max_B(e)) for all e belongs to both the arrays A and B (e is an element)


*/

const int N = 200005;


void solve() {
    int n;cin>>n;
    set <int> elements;//stores all the unique elements present in both the arrays combined
    int a[n], b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        elements.insert(a[i]);
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        elements.insert(b[i]);
    }
    /*
    auto it= elements.begin() ;
    while(it!=elements.end()){
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
    */



    map<int ,int> m1,m2;  //these maps store the unique element and their longest run for both the arrays   
    int cnt=1;
    m1[a[0]]=1; //initially the longest run of a[0] is 1 only , it further gets updated if it has more longer run somewhere else.
    //counting the longest runs in the array and updating the maps accordingly.
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            cnt++;
        }else{
            cnt=1;
        }
        m1[a[i]]=max(m1[a[i]],cnt); //this updation here makes it redundant we could have updated before making cnt =1 but then loop k firse ekbar update krna prta 
    }

    cnt=1;
    m2[b[0]]=1; //initially the longest run of b[0] is 1 only.
    //counting the longest runs in the array and updating the maps accordingly.
    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]){
            cnt++;
        }else{
            cnt=1;
        }
        //at eac step updating the map with the current longest run of a[i]/b[i]
        //key of map = b[i] and value is its longest run which gets on updated every iteration.
        m2[b[i]]=max(m2[b[i]],cnt); //this updation here makes it redundant we could have updated before making cnt =1 but then loop k bahar firse ekbar update krna prta 
    }

/*
    auto it1=m1.begin();
    while(it1!=m1.end()){
        cout<<it1->first<<" "<<it1->second<<endl;
        it1++;
    }
    cout<<"_____\n";
    

    auto it2=m2.begin();
    while(it2!=m2.end()){
        cout<<it2->first<<" "<<it2->second<<endl;
        it2++;
    }
    */

    



   

    //now findind the ans which is max(max(e)in a + max(e) in b)
    int ans=1;//this is the min value of ans;
    for(auto e : elements){
        //bug(m1[e]+m2[e]);
        ans=max(m1[e]+m2[e],ans);
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
