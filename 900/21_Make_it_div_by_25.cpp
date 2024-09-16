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
A number is divisible by 25 if and only if its last two digits represent one of the following strings: "00", "25", "50", "75".

Let's solve for each string the following subtask: what is the minimum number of characters to be deleted 
so that the string becomes a suffix of the number. Then, choosing the minimum of the answers for all
subtasks, we solve the whole problem.

Let's solve the subtask for a string "X Y" where 'X' and 'Y' are digits. We can do it using the following 
algorithm: let's delete the last digit of the number until it is equal to 'Y', then the second to last digit of the number 
until it is equal to 'X'. If it is not possible, then this subtask has no solution (i.e. its result will not affect the answer).

One Doubt Resolution: Why should we delete last and second last , first of all this is a brute force approach now since we need 
to make the suffix of the string as XY i.e. very  "last" of the string should be XY in order to be divisible by 25 , the intitution is 
we need to modify the last the places so that they become XY so deletion at any other place wont modify the last two places it would remain unaltered 
so we should delete elemets from the last . and the order should be last and then second last so that , because by contradiction method if we do it otherwise
then the last place never gets options to make it equal to Y , but we we do it last then second last then both the places gets to see options at first the last 
place is set then we start deleting fromm the second last position 

In Implementation we actually doesnt delete elements but we move idx forward and count the number of deletion required to reach the final 
states s[idx]=Y and then s[idx]=X and if these states cant be reached then for that subtask no solution exists and we should return +infinity so as the keep the original
answer unaffected.
*/

const int N = 200005;
const string Subseq [] = {"00","25","50","75"};


int subtask(string s, string t){
    int idx=s.length()-1;
    int ops =0;
    //we are trying to make s[idx]=t[1] ... and we need to make it till index>=1 because if we go beyond this there wont be any place left for making s[idx]==t[0]
    //now we we could make s[idx]==t[1] on or before idx>=1
    //then in the worst case s[idx] == t[1] at idx = 1 and the condition withing while wont be true so idx remains at 1 i.e. final value of idx =1 while exiting the while loop so its ok we have an valid ans in this case 
    //also observe that idx remains at the index wherein s[idx]==t[1] becuase s[idx+1]!=t[1] and then idx-- make s[idx]=t[1]
    //but if we cannot make s[idx]==t[1] on or before idx>=1
    //then at worst case idx=1 and s[idx]!=s[1] and while loop gets execute in this case making i-- and ops ++but we are beyond search space here we should stop.. so here final value of i while exiting while loop is 0 
    while(s[idx]!=t[1] and idx>=1){
        idx--;     //moving idx ahead means we need one deletion
        ops++;     //hence ops ++
    }

    //so if idx<1 or idx becomes 0 it means we have exhausted the seach space and we cannot make s[idx]== t[1] and hence we do not have a valid ans hence we should return INT_MAX so the it doesnt affect the original ans

    if(idx<1) return INT_MAX;

    // idx remains at the pos where s[idx]==t[1]
    //now we should start serach from the prev index and trynna make s[idx]==t[0]
    idx--;


    //similar type of story in term of logic as we did for the prev while loop
    while(idx>=0 and s[idx]!=t[0]){
        idx--;
        ops++;
    }
    if(idx<0) return INT_MAX;

    return ops;


}
void solve() {
   
    int ans=INT_MAX;

    string s;cin>>s;
    for(auto x: Subseq ){
        ans=min(ans,subtask(s,x));
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
