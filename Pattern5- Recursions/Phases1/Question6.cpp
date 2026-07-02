Given an integer num, return the number of digits in num that divide num.
An integer val divides nums if nums % val == 0.

Input: num = 121
Output: 2


step1:Question convert into your form
1.Hume ek integer number diya gya hai
2.hume number of digits return krne hai jo humre num ko puura divide kr sake
3.basically hume vo count retun krne hai jo humre number ko puura divide kr rha ho 

step2:-Input dekho:-
num=121
basically humre pass kitne digits hai ish number pe
  1-2
  2-1

121%1==0 hai
121%2==0 nahi hai
ans=2  kyuki 1 do baar repeat hua hai

step3:Brute Force socho:-
1.Hume ek variable banana padega jo humre num ki value ko store krega
2.uske baad hum ek ek krke digit nikalne ka try krenge
3.ur jo digit nikal kr aayega ushe hum apne original num se diivide krke check krenge agar vo ==0 ho gya to ek humra valid answer banega
5.count ++ kr denge
6.last mein count return kr denge

step4:Dry run:-
num=1248
n=1248
int cnt=0;

Case: n>0  yes
      int digit=n%10 =8
      n=n/10;
      if(num%digit==0){
        cnt++:
      } 
     cnt=1

case : n>0  yes
       int digit=124%10=4
       n=n/10;
       if(1248%4==0)  cnt++:
       cnt=2
       
case : n>0   yes
       int digit=12%10=2
       n=n/10;
       if(1248%2==0)  cnt++;
       cnt=3
   
case:  n>0    yes
       int digit=1%10=1
       n=n/10;
       if(1248%1==0) cnt++:
       cnt=4;
       
case n>0 false

       return cnt;

       class Solution {
public:
    int countDigits(int num) {
        int n=num;
        int count=0;

        while(n>0){
            int digit=n%10;
            n=n/10;
            if(num%digit==0){
                count++;
            }
        }
        return count;
    }
};


step5:Recursion ki soch:-
num=522
n=522
 |
n=52      2
 |
n=5       2
 |
n=0       5 

Q1.Hum kya optimized kr rhe hai :- (n%10)  krke hum n ko optimized kr rhe hai
Q2.Hume rukna kab hai :- (n==0) 
Q3.Hum Problem ko kauise chota kr rhe hai: n/10
Q4.Humre pass call krne ke kitne options hai :- sirf ek (n%10)
Q5.Hum answer kaise generate krenge :- global b=variable cnt=0
  agar (num% (n%10)==0) hua to cnt++


  class Solution {
public:
    int solve(int num, int n) {
        if (n == 0) {
            return 0;
        }

        int digit = n % 10;

        return (digit != 0 && num % digit == 0) + solve(num, n / 10);
    }

    int countDigits(int num) {
        return solve(num, num);
    }
};