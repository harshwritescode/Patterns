The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days.
You are given an array arr[] representing daily stock prices, 
the stock span for the i-th day is the number of consecutive days up to day i (including day i itself) 
for which the price of the stock is less than or equal to the price on day i. Return the span of stock prices for each day in the given sequence.

Input: arr[] = [100, 80, 90, 120]
Output: [1, 1, 2, 4]

step1:Question convert into your form
1.humre pass ek array diya gaya hai jisme vo har ith index represent ush stock ka price kr rhi hai
2.hume har ek index ke liye span of stock price calculate krna hai
3.stock span kisi bhi ith day ka matlab ye hai ki numbers of consecutive days up to day (jisme uska current index bhi include hoga)
4.saath h saath jo price hai stock ka vo less than equal to price hona chiye ush day ka
5.hume same sequnece mein span return krna hai
6.ans return kr do vector/array mein

step2:Input dekho:-
arr[] = [100, 80, 90, 120]
          0   1    2    3

Observation:-
1. Hum apne index se peech ye check krna hai ki isse pehle peeche humre current price se ye chota ya uske equal hai
2. current element ko bhi include krke niklna hai
3.  [100, 80]
      0   1

      condition pehli ye hai:-
       1) Pehle sirf khud ko dekho 100>=100 ur saath h saath ye dekho iske peeche iske kitne element aise hai jo humre abhi current price se chote hai ya iske equal hai
          ( 100>=100  ||  )
          and operator lagne se agar second condition false huyi to if ke andar nhi jayega
           span=1

       2)   80>=80  ||  80<arr[i-1] 
       span=1

       3)  [100, 80, 90]
             0   1   2

             90>=90 || 90<80  90>100(stop condition)
             span=2

       4)    [100, 80, 90, 120]
               0   1    2    3  
               
               120>=120 true 1
               120<=90  true 1
               120<80   true 1
               120<100  true 1

               4

               [1,1,2,4]
       5)Count maitain krna padega

step3:Brute Force socho:-
1.Hum index 1 se start krenge n tk
2. nested loop hum right to left chla lenge
3. vha condition check krnege
4. count niakl lenge
5.ans mein store kr denge  return kr denge

step4:Dry Run:-
arr[] = [10, 4, 5, 90, 120, 80]
         0   1  2  3    4    5
                   i 
               j-1
                   j
ans[0]=1

i    n      i<n    j=i    j>0     (arr[i]>=arr[i])    true/false         count         (arr[i]>=arr[j-1])          true/false          count      ans[]         
1    6      0<6    1      1>0        4>=4               true              1                4>=10                     false                1         ans[1,1]
                          0>0
    
2    6      2<6    2      2>0        5>=5               true              1                 5>=4                      true               2        
                          1>0                                                               5>=10                     false              2

                          inner loop ke bahar ans[1,1,2]

3    6      3<6     3     3>0        90>=90             true              1                 90>=5                     true               2
                    2     2>0                                                               90>=4                     true               3
                          1>0                                                               90>=10                    true               4
                          
                          inner loop ke bahar ans[1,1,2,4]

4    6      4<6     4    4>0        120>=120                              1                  120>=90                  true               2
                         3>0                                                                 120>=5                   true               3
                         2>0                                                                 120>=4                   true               4
                         1>0                                                                 120>=10                  true               5
                         
                         
                         inner loop ke bahar ans[1,1,2,4,5,1]

Main kuch elements ko baar-baar compare kar raha hoon.

Ek baar jab koi bada element aa jata hai,
to usse chote elements future me kabhi answer nahi denge.

Isliye unhe permanently remove kiya ja sakta hai.
                         
step5: Repeat Work Analysis:-

1. Hum jab bhi inner loop chala rahe hain tab hum baar-baar left side jaakar same elements ko compare kar rahe hain.

   Example:

   [10, 4, 5, 90]
   0  1  2   3

   Jab current element 90 hai:

   90 >= 5  ✔
   90 >= 4  ✔
   90 >= 10 ✔

   Future me agar 120 aata hai:

   120 >= 90 ✔
   120 >= 5  ✔
   120 >= 4  ✔
   120 >= 10 ✔

   Yahan 5 aur 4 ko baar-baar check kiya ja raha hai. Ye repeat work hai.

2. Observe karo ki jab 90 aa gaya to 5 aur 4 dono usse chote hain.

   [10, 4, 5, 90]

   Ab future me jo bhi element aayega, uske liye 5 aur 4 kabhi Previous Greater Element nahi ban sakte.

   Isliye 5 aur 4 useless candidates hain aur inhe permanently remove kiya ja sakta hai.

3. Hume aise candidates maintain karne hain jo future me answer dene ki possibility rakhte hain.

   Jo current element se chote ya equal hain wo future me answer nahi banenge, isliye unhe discard kar denge.

4. Hume span bhi calculate karna hai, isliye element ke saath uska index maintain karna useful rahega.



step6:Pattern analysis:-
1.Monotonic stack lag jayega
2. hume usefull candidate maintain krna hai
   -- jisme mujhe mere price se chote ya uske barabar element jitne element hai unka count store krna hai
   humre liye jo useless candidate hai unhe remove kr dena hai
3. stack h kyu queue kyu nhi ??
    hume order maintain nhi krna hai 
     ki kun pehle hai kun baad mein jab order maintain krna hota to stack na lagate
4. sliding window - window valid hai ya nahi
   kadane - continue karu ya restart karu
   monotonic - useful hai useless 
5. monotinic stack

step7:Dry Run:-

arr[] = [10, 4, 5, 90, 120, 80]
         0   1  2  3    4    5

ans:[1,1,2,1,1,1]
     0 1 2 3 4 5

 i = 0 (10)
 Stack empty hai. 
span = 1
st = [0]
ans = [1]

i=1 (4)
4>=10 false
Pop nahi hoga.
span=1-0=1
st = [0,1]

i = 2 (5)
5>=4 true
pop 1
st = [0]
10>5 true
span=2-0=2
push:[0,2]

i=3
90>=5 true
pop 2
st=[0]
90>=10 tru
pop 0

stack empty : i+1=5
st = [3]


class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
       int n=arr.size();
       vector<int> ans(n,1);
       stack<int> st;
       st.push(0);
       
       for(int i=1;i<n;i++){
           while(!st.empty() && arr[i]>=arr[st.top()]){
               st.pop();
           }
           
           if(st.empty()){
               ans[i]=i+1;
           }
           else{
               ans[i]=i-st.top();
           }
           st.push(i);
       }
        return ans;         

    }
};
    



     

     








      
      
