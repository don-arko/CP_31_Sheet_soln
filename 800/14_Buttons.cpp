/*

https://codeforces.com/contest/1858/problem/A
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
Concept 
- Idea is since anna has to press first she has some disadvantage and and katie who as to press second has some advanatage

-both have to exhaust the c buttons first in order to play optimally


-Now when c(common botton) is odd anna get one more botton to press and katie from the common buttons since she starts first 
-c=odd
        cc  
        cc
        cc
        cb  
        ab
        ab
        ab
      --------- standing at this point observations are thinkings could be easily done
        
        --clearly in order for katie to win katie must have atleast one(1) button more than anna or else annna wins
        
    b>=a+1 => katie wins        b>=a+1 => b>a                                
        
        cc  
        cc
        cc
        cb       
        ab
        ab
    ----------- proceeding to next round are either no buttons left or only b buttons are left => katie or second wins

    else b< a+1 => Anna wins    
        
        cc  
        cc
        cc
        cb       
        ab
        a
    ----------- here in both b and a buttons exhausted hence katie loses or anna wins


    



-Now when c(common botton) is even anna  and katie gets equal buttons 
-c=even
        cc  
        cc
        cc
        cc      
        ab
        ab
        ab
        ab
      --------- standing at this point observations are thinkings could be easily done
        
        --clearly in order for anna to win she should have more button than katie
        
    a>b => Anna wins                                 
        
        cc  
        cc
        cc
        cb       
        ab
        ab
    ----------- proceeding to next round are only a buttons left => anna wins
        a


    else  a<=b => Katie wins
        
        cc  
        cc
        cc
        cb       
        ab
        ab
    ----------- proceeding to next round there are only 'a' buttons left  or 0 buttons left => anna wins

==========================================================================================================================================================================================




Simple Gist

c=odd :- Anna press 1 common button more 


        cc
        cc
        c
    ---------- c buttons exhausted ,now the following  can be observed or conluded 

    if both have equal buttons left then Katie loses cause she has the disadvatage due to odd c buttons gettin one less than anna so she need strictly greater button than anna to win or else she loses  

--if katie has strictly more buttons 'b' than anna 'a' then she wins or else loses =>if anna has n buttons left then katie has n+1 buttons left

   



c=odd :- Both anna and katie presses equal equal c buttons 

        cc
        cc
        cc
    ---------- c buttons exhausted now the follow can be observed or conluded 

     if both have equal buttons left then anna loses cause she need to press first (natural disadvatage)  so she need strict more buttons than katie to win it or else she loses

--if anna has strictly more buttons 'a' than Katie 'b' then she wins or else loses => if katie has n buttons left then anna has n+1 buttons left

*/
void solve() {
    
    int a,b,c;
    cin>>a>>b>>c;
    if(c%2!=0){ //odd
        if(b>a) cout<<"Second\n";
        else cout<< "First\n";
    }
    else{  //even
        if(a>b) cout<<"First\n";
        else cout<< "Second\n";
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
