You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value.
Any answer with a calculation error less than 10-5 will be accepted.

nums = [1,12,-5,-6,50,3], k = 4
Possible outcomes

(1,12,-5-6)= 2/4 =0.50000
(12,-5,-6,50)=51/4= 12.750000
(-5,-6,50,3)=42/4=10.50000

return maximun average=12.750000

step1:Question convert into your language
1.Array diya hai jisme positive aur negative numbers dono ho sakte hain.
2.Mujhe contiguous subarray find karni hai.
3.Har valid subarray ki length exactly k honi chahiye.
4.Har size k wali subarray ka average nikalna hai.
5.Sabhi averages me se maximum average find karna hai.
6.Final answer double value me return karna hai.

step2:input dekho
nums = [1,12,-5,-6,50,3], k = 4
        0  1  2  3  4  5
(1,12,-5-6)= 2/4 =0.50000
(12,-5,-6,50)=51/4= 12.750000
(-5,-6,50,3)=42/4=10.50000


Observation
1)Subarray contiguous honi chahiye.
2)Har subarray ki size exactly k hai.
3)k fixed hai.
4)Average = Sum / k.
5)Kyunki k fixed hai, maximum average nikalna = maximum sum nikalna.



step3:Brute Force socho
1.Har index se start kro
2.wahan se k element tak sum nikalo
3.har window ka sum calculate karo
4.mujhe maximum sum chiye hai
5.sab window check hone ke baad average nikalo
6.average return kr do


step4:Dry Run:

nums = [1,12,-5,-6,50,3], k = 4
        0  1  2  3  4  5

 window size==k
 hume window size bhi maintain karna padega 
 hume maximumsum bhi maintain karna padega


i=0
  [1 ]  sum=1  (condition =k ) (1!=4)
  [1 , 12] sum=13 (2!=4)
  [1,12,-5] sum=8 (3!=4)
  [1,12,-5,-6] sum=2 (4==4)

i=1  
  [12]  sum=12 (1!=4)
  [12,-5] sum=7  (2!=4)
  [12,-5,-6] sum=1 (3!=4)
  [12,-5,-6,50] sum=50  (4==4)  condition satisfied 

i=2
 also same
 [-5,-6,50,3]
sum=42
maxsum=51

avg=maxsum/k=12.75000


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int maxsum = INT_MIN;

        for(int i=0;i<=nums.size()-k;i++) {

            int sum = 0;

            for(int j=i;j<i+k;j++) {
                sum += nums[j];
            }

            maxsum = max(maxsum,sum);
        }

        return (double)maxsum/k;
    }
};



Step4: Brute Force mein repeat kya ho raha hai?

1. maine ye dekha ki hum sum ko baar baar calculate kr rhe hai 
2.  [1,12,-5,-6] sum=2
3.  next iteration ke liye phir se hum  [12,-5,-6] ko phir se calculate kr rhe hai
4.  [12,-5,-6,50] sum=51
5.  newsum=oldsum-arr[i-k]+arr[i] to bhi mera sum 51 h aayega

Observation:
  a) average =maxmimumsum/ k hai aur k humra fixed hai
    isliye agar hume maximum average agar nikalna hai to hume maximum sum nikalna padega  pehle
  b) hum kya kre pehle first window ki calculation nikal le
  c) jisme mujhe sum milega ur mai first window ka answer nikal lunga
  d) sum ko maintain krna bhi jaruri hai 
  e) phir next window ke liye iterate krenge
  f) jbh bhi hum window ko aage badhne vhle hai to hum maintainsum se first index ki value ko subtract krna padega 
  g) humre pass pehle window se sum aaya
      sum=2
      nextsum=51 aana chiye 
      i=4
      newsum=oldsum-arr[i-k]+arr[i]=2-arr[0]+arr[i]=2-1+50=51

      maxsum hai to check kr lenge 
      phir answer calculate kr lenge

step5: Kis pattern se optimised hoga 
 
a)HashMap kyu nahi?

HashMap tab use hota hai jab hume:

Frequency count karna ho
Duplicate check karna ho
Character/element tracking karni ho

Na frequency count karni hai  
Na duplicate dekhna hai
Na kisi element ko track karna hai

b)Two Pointer kyu nahi?
Normal Two Pointer/Variable Window tab lagti hai jab:  Window size badh ya chhoti ho sakti ho
Window ko expand ya shrink nahi karna.

c)Sliding Window
Fixed Size Sliding Window
Subarray size exactly k hai.

step6:Generic Template
1.first window ki information nikalo
2.answer initalized karo
3.window slide kro
4.ans mein se (i-k) element ka element subtract kro
5. left++ karo 
6. ans mein new window ka current element save kro




class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<k;i++){
             sum+=nums[i];
        } 

        int maxsum=sum;

        for(int i=k;i<n;i++){
            sum=sum-nums[i-k]+nums[i];
            maxsum=max(sum,maxsum);
        }

        return double(maxsum)/k;
    }
};














