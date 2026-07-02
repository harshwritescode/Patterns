Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
Input: num = 38
Output: 2

step1:Question convert into your form
1.Hume ek integer num diya gaya hai
2.hume ush integer num mein jitne bhi digit hai unko apas mein add krna hai
3.add bhi tab tak krna hai jab tak vo ek single number na bana de

step2:-Input dekho
num = 38

First Step:-  pehla number  :- 8
              first number  :- 3
              add:- 8+3=11
              check kiya sum hone ke badd number kitne digit ka hai agar ek digit hua to hume answer mihl gaya
              1+1=2

Observation:-
1.Agar num=0 hua to hume return 0 kr dena hai

step3:-Brute Force:
num=38
1.Pehli cheej hume num ko tab tak todna hai jab tk humra num khtm nhi ho jata hai
2.todte time hum sum bhi add krte jayenge
3.saath h hume yha digit bhi count krni padegi agar digit==1 hua to hume answer mihl jayega

Step4:Dry Run:-
num=123456
n=num
n=123456
isme hum aage se bhi add kr sakte hai ur peeche se bhi
Remainder kiya
1 -- n%10  6
2--  sum=6
3--  check it is single digit or not after adding the sum
yes it is 

Remainder nikla
1--  n%10   5
2--  sum=11
3--  check it is single digit or not after adding the sum
 No,
     again same thing we will do that with sum 
       1-- n%10  1
       2-- sum=1
       3-- check it is single digit or not after adding the sum
       Yes,

      again same thing we will do that with sum 
       1-- n%10  1
       2-- sum=2
       3-- check it is single digit or not after adding the sum
       Yes,  
       
 Remainder nikala 
 1-- n%10   4
 2--  sum=6
 3-- check it is single digit or not after adding the sum 
yes,

Remainder nikala 
1-- n%10   3
2-- sum=9
3-- check it is single digit or not after adding the sum 
yes,

Remainer nikala
1-- n%10   2
2-- sum=11
3-- check it is single digit or not after adding the sum
 No,
     again same thing we will do that with sum 
       1-- n%10  1
       2-- sum=1
       3-- check it is single digit or not after adding the sum
       Yes,

      again same thing we will do that with sum 
       1-- n%10  1
       2-- sum=2
       3-- check it is single digit or not after adding the sum
       Yes,  
       
Remainder nikala
1-- n%10 1
2-- sum=3
3-- check it is single digit or not after adding the sum 
yes,


return sum;

class Solution {
public:
    int addDigits(int num) {
        if(num==0) return 0;

         int sum=0;
         while(num>0){
            sum+=num%10;
            num/=10;

            while(sum>=10){
                int temp=0;

                while(sum>0){
                    temp+=sum%10;
                    sum/=10;
                }
                sum=temp;
            }
         }
         return sum;
    }
};


step5:Recursion ki soch:-
              num=123456
                    |
              num=12345           6
                    |
              num=1234            5
                    |
              num=123             4
                    |
              num=12              3
                    |
              num=1               2    
                    |
              num=0               1          
              
              
1.num%10 krke hume ek remainer mihl rha hai 
2.sum mein remainder add kr diya
3.phir num chota ho gaya hai
4.phir ushe chota kr diya humne

Q1.Hum kya optimizdd krne ka try kr rhe hai -  num ko 
Q2.Hum problem ko kaise chota kr sakte hai  - num/10
Q3.Hum rukna kab chthe hai -  num==0
Q4.Hum Kitni call kr rhe hai - ek h option hai humre pass
Q5.Hum answer kaise maintain kr rhe hai - sum krke  vapas aate samay krte hai to jada shi rahega agar sum  bhi double digit mein gaya to vhi ushe todh lenge

class Solution {
public:
    int addDigits(int num) {
        if(num<10){
            return num;
        }
       
       int sum=0;

       while(num>0){
          sum+=num%10;
          num=num/10;
       }

       return addDigits(sum);
       
    }
};