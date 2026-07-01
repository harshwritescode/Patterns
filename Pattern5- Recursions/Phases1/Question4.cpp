The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, 
such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

step1:-Question convert into your form
1.Hume ek integer number diya gaya hai
2.Hume ek fibonacci sequence niklna hai
3.iska mtlb har ek number jo hai uske peeche ke do sum ke barabar hoga 
4. f(5)= f(4)+f(3)
5. its means hume jo bhi number diya gaya hai  unke peeche ke do number ka sum h humra answer hai

step2:Input dekho:-
n=3
f(2)+f(1)
f(1)+f(0)+f(1)
1 + 0 +1
=2

step3:Brute Force Socho:-
1.Hume ek integer number diya gaya hai 
2.Hume ek loop chlna pad rha hai
3.Loop mein hum n mein check kr rhe hai kya humre pass f(0)=0 aur f(1)=1 ho jaye to hum answer banane ke liye ready ho jayenge

class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
       
        int prev2=0;
        int prev1=1;
        int curr;

        for(int i=2;i<=n;i++){
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr
        }
        return curr;
    }
};

Dry Run:-
n = 5

prev2=0
prev1=1;

i=2
curr=1
prev2=1;
prev2=1

i=3
curr=2
prev2=1
prev1=2

i=4
curr=3
prev2=2
prev1=3

i=5
curr=5
prev2=3
prev1=5

answer=5

step5:-
Recursion Approach:-
                           F(5)
                        /        \
                    F(4)         F(3)
                   /    \        /    \
               F(3)   F(2)    F(2)   F(1)
              /   \    /  \    /  \
           F(2) F(1) F(1) F(0) F(1) F(0)
          /   \
       F(1) F(0)

Base Cases:
F(0) = 0
F(1) = 1

 f(2)=1+0=1
 f(3)=1+1=2
 f(4)=2+1=3
 f(5)=3+2=5


 Q1.Hum kya optimized kr rhe hai :- n ko optiized kr rhe hai
 Q2.Base case ya rukna kab hau :- n==0 ur n==1 pe answer hume already pta hai
 Q3.Hum problem ko kaise chota kr sakte hai :-humre answer f(n-1)+f(n-2) ko todh todh kr jbh tk n==0 ya n==1 nhi jho jata tab tk ishe diide krenge
 Q4.Hum pass call krne ke kitne option hai :- 2 hai (n-1) + (n-2) dono h krna hai hume
 Q5.Answer kaise generate hoga jbh hum return krenge tab h answer ban jayega 
 Q6.Lekin ye optimized kr sakte hai Dynamic Programming laga kr kyuki left side mein vhi tree jo right side mein bhi hai ye duplicate work hai


 class Solution {
public:
    int fib(int n) {
        if(n==0)   return 0;
        if(n==1)   return 1;

        return fib(n-1)+fib(n-2);
        
        
    }
};

step6:-
Step 1 : DP ki zarurat hi kyu padi?
Maan lo tumhare paas recursion hai.
fib(5)
                5
             /     \
           4         3
         /   \      / \
       3      2    2   1
      / \    / \  / \
     2   1  1  0 1  0

     Kitni baar fib(2) calculate hua?  3 baar
     fib(3) -2 baar
Yahi problem hai.
Hum same answer baar-baar nikal rahe hain 
DP ka matlab hai   
Ek baar calculate karo, store karo, dobara mat calculate karo.


DP ke do tarike hote hain
1.Top Down (Memoization)
fib(5)

↓

fib(4)

↓

fib(3)

↓

fib(2)

↓

fib(1)

Bilkul recursion ki tarah.
Difference sirf itna hai
Answer store kar dete hain.


Dry Run:-
fib(5)
sabse pehle
fib(4)
fir
fib(3)
fir
fib(2)
Aab 
 fib(2)=1
 to hum
 dp[2]=1
 store kr denge
 Fir maan lo baad me recursion fir se
 Recursion kare?  nahi
 Seedha return dp[2]; kr denge
 Isliye Memoization ko bolte hain

Recursion + Memory


Structure:-
int solve(...){

    // Base Case

    // Agar pehle se answer hai
    // return dp

    // Answer calculate karo

    // Store karo

    // Return karo
}

int solve(int n ,vector<int> &dp){
    if(n==0) return 0;
    if(n==1) return 1;

    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n]=solve(n-1,dp)+solve(n-1,dp);

    return dp[n];
}


2.Bottom Up (Tabulation)
Ab maan lo kisi ne bola
Recursion hi mat use karo.
Fir?
Hum sochte hain

F(5)
Banane ke liye kya chahiye?
F(4)
F(3)

Achha
F(4) banane ke liye?
F(3)
F(2)


Sabse pehle kiski value already pata hai?
F(0)=0
F(1)=1
To wahi se start karte hain.
0
1

fir:-
2

↓

3

↓

4

↓

5

Ye niche se upar banana
Bottom Up kehlata hai.

Dry Run:-
dp
 0 1
 i=2
 0 1 1
 i=3
 0 1 1 2
 i=4
 0 1 1 2 3
 i=5
 0 1 1 2 3 5

 Pattern:-
 Har DP me lagbhag same hota hai.
 // DP array

// Base Case Fill

// Loop

// Transition

// Return

vector<int> dp(n+1);
dp[0]=0;
dp[1]=1;
for(int i=2i<=n;i++){
    dp[n]=dp[i-1]+dp[i-2];
}

return dp[n];