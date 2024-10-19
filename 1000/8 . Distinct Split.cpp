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


Let's check all splitting points i for all (1≤i≤n−1). We denote a splitting point as the last 
index of the first string we take (and all the remaining characters will go to the second string). 
We need to keep a dynamic count of the number of distinct characters in both strings a (the first string) 
and b (the second string). We can do this using two frequency arrays (and adding one to the distinct count of either string a or b
when the frequency of a character is greater than zero.



My Explaination: Have done this question completely on my own and editorial code has use arrays for frequency counting while i have used maps so it feels like my code is better.

*/

const int N = 200005;


void solve() {
    int n;cin>>n;
    string s;cin>>s;
    map<char,int> m; //map which keeps the record of elements to the right of the split 
    for(int i=0;i<n;i++){
        m[s[i]]++;
    }
    /*
    auto it=m.begin();
    while(it!=m.end()){
        cout<<(*it).first<<" "<<(*it).second<<endl;
        it++;
    }
    //cout<<m.size();
    */

    //idea is to iterate the split starting from btw s[0] | s[1] to finally btw s[n-2] | s[n-1] so that both sides are non empty
    //i=0                    i=1              ...         i=n-2
    //s[0]|s[1]....s[n-1] -> s[0]s[1]|s[2]..s[n-1] -> ... s[0]....s[n-2]|s[n-1]

    // as the split iterate from i=0 to i=n-1 we instantly add 1 to the frequency of s[i] in map aux (as it moves to the left of split) and remove 1 frequncy of s[i]
  //from m and as soon as f=0 delete the key-value so the the size of the map gives us the no. of distint element.
    
    //lets say initially | is on the left of s[0] i.e. |s[0]
    int l=0;        //distinct chars on left of |
    int r=m.size(); //distinct chars on right of |
    int ans=0; //actually min ans =2
    map<char,int> aux; //map which keeps the record / frequency of all the elements to the left of split.
    //bug(l,r);
    for(int i=0;i<n-1;i++){ // i=0 means split |s[0] s[1] -> s[0] | s[1]
        aux[s[i]]++;
        l=aux.size();

        m[s[i]]--;
        //frequncy zero matlab wo element delete kr do jo map apne se nei karega
        if(m[s[i]]==0){
            m.erase(s[i]);
        }
        r=m.size();
        //bug(l,r);

        ans=max(ans,r+l);
    }
    /*
    it=m.begin();
    while(it!=m.end()){
        cout<<(*it).first<<" "<<(*it).second<<endl;
        it++;
    }
    */


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
