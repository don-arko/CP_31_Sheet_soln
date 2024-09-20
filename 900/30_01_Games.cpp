/*

https://codeforces.com/contest/1373/problem/B

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
My Idea

-The idea is to count the min no. of 1s or 0s in the string cause as long as two diff char are there we could always select two diff adjacent chars and delete them.
now you can think that whats the gurantee the chars will be adjacent . So my point is as long as two diff chars are there , there will be atleast 
one surface of seperation between these chars and hence at every moment (until diff chars exist) atelast one pair of adjacent elemetns exist at the 
surface of seperation , as atleast one surface of seperation always exists.

eg:-   1111000 --> 11100 --> 110 --> 1    clearly total possible moves = 3 = min(4,3)
          __         __       __

-In each ops one 0 and one 1 gets deleted so the total possible moves= min(count-1, Count_0)

- Now in each round there are two moves and and alice makes the first move in each round so alive makes the odd no. of moves always,
-So if the moves is odd then after alices, move the when its turn for bob (who places even moves), the moves shall get exhausted and alice will win ,
  if the moves is even , then after bob's move when its alice's turn (who plays even move) , the moves gets exhausted and alice will lose.



Editorial (me pura ediorial jaisa socha)

If there is at least one character 0 and at least one character 1, 
then current player can always make a move. After the move the number 
of character 0 decreases by one, and the number of character 1 decreases 
by one too. So the number of moves is always min(c0,c1), where c0 is the 
number of characters 0 in string s, and c1 is the number of characters 1 
in string s.
So if min(c0,c1) is odd then Alice wins, otherwise Bob wins.


*/
const int N = 200005;


void solve() {
    string s;cin>>s;
    int count_1=0;
    int count_0=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            count_0++;
        }
        else{
            count_1++;
        }
    }

    int moves=min(count_0,count_1);

    //alice wins when moves possible is odd or else  bob wins.

    if(moves%2!=0){
        cout<<"DA\n";
    }
    else{
        cout<<"NET\n";
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
