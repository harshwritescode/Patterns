Given an integer array nums, find the subarray with the largest sum, and return its sum.
nums = [-2,1,-3,4,-1,2,1,-5,4]
         0 1  2 3  4 5 6  7 8
Output:6
Har index se start karke subarray ka sum nikalte hai
start=0
[-2]                    = -2
[-2,1]                  = -1
[-2,1,-3]               = -4
[-2,1,-3,4]             = 0
[-2,1,-3,4,-1]          = -1
[-2,1,-3,4,-1,2]        = 1
[-2,1,-3,4,-1,2,1]      = 2
[-2,1,-3,4,-1,2,1,-5]   = -3
[-2,1,-3,4,-1,2,1,-5,4] = 1

start=1
[1]                   = 1
[1,-3]                = -2
[1,-3,4]              = 2
[1,-3,4,-1]           = 1
[1,-3,4,-1,2]         = 3
[1,-3,4,-1,2,1]       = 4
[1,-3,4,-1,2,1,-5]    = -1
[1,-3,4,-1,2,1,-5,4]  = 3

start=2
[-3]                 = -3
[-3,4]               = 1
[-3,4,-1]            = 0
[-3,4,-1,2]          = 2
[-3,4,-1,2,1]        = 3
[-3,4,-1,2,1,-5]     = -2
[-3,4,-1,2,1,-5,4]   = 2

start=3
[4]                = 4
[4,-1]             = 3
[4,-1,2]           = 5
[4,-1,2,1]         = 6   <-- Maximum
[4,-1,2,1,-5]      = 1
[4,-1,2,1,-5,4]    = 5

Start = 4
[-1]            = -1
[-1,2]          = 1
[-1,2,1]        = 2
[-1,2,1,-5]     = -3
[-1,2,1,-5,4]   = 1


start=5
[2]          = 2
[2,1]        = 3
[2,1,-5]     = -2
[2,1,-5,4]   = 2

start=6
[1]        = 1
[1,-5]     = -4
[1,-5,4]   = 0


start=7
[-5]      = -5
[-5,4]    = -1


start=8
[4] = 4

return ans =maximum=6

step1:Question convert into your form
1. ek array diya gya hai hume jisme positive negative number dono hai
2. hume maximum sum vhla subarray find krna hai
3.  uska sum hume return kr dena hai

step2:Input dekho
nums = [-2,1,-3,4,-1,2,1,-5,4]
         0 1  2 3  4 5 6  7 8

Observation:
1.Hume contigous subarray find krna hai
2. [-2,2,-5,4]   ye array ka sum nhi nikalna hai hume 
    [2,1,-5,4]   continity mein hona chiye subarray
3. Total subarray =n*(n+1)/2 =45

step3:Brute force socho
1.Har index se start karke possible subarray ya window nikal lo
2.jo possible window aayi hai humre pass uska sum nikal lo
3.ans update kro kyuki hume maximum answer chiye
4. last mein answer return kr do

step4:Dry Run--

i  n   ans[]  sum=0  condition1(i<n)  j   condition(j<n)    ans[]                          sum    result
0  9    []      0          0<9        0        0<9           [-2]                           -2     -2
                                      1        1<9           [-2,1]                         -1     -2
                                      2        2<9           [-2,1,-3]                      -4     -2
                                      3        3<9           [-2,1,-3,4]                     0      0
                                      4        4<9           [-2,1,-3,4,-1]                 -1      0
                                      5        5<9           [-2,1,-3,4,-1,2]                1      1
                                      6        6<9           [-2,1,-3,4,-1,2,1]              2      2
                                      7        7<9           [-2,1,-3,4,-1,2,1,-5]          -3      2
                                      8        8<9           [-2,1,-3,4,-1,2,1,-5,4]         1      2
                                      9        9<9(f)

                                      Its means hume pehle starting point se last tk jab gaye hai 
                                     usme se ek window aise mili hai jiska sum humra maximum hai vo 2 hai
                                     result=2   ans=[-2,1,-3,4,-1,2,1]


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int result=INT_MIN;
        for(int i=0;i<n;i++){
            vector<int> ans;
            int sum=0;
          
            for(int j=i;j<n;j++){
                ans.push_back(nums[j]);
                sum+=nums[j];
                result=max(result,sum);
            }
           

        }
        return result;
    }
};                                      

step5:Brute Force mein kya repeat ho rha hai??

i=0
sum=-2=-2
sum=-2+1=-1
sum=-2+1+-3=-4
sum=-2+1+(-3)+(4)=0

observe karo
Previoussum+currentElement
window nikalne ke baad sum nhi nikal rhe hai hum
saath h saath nikal rhe hai sum 
Hum continuously ek running sum maintain kar rahe ho.
Agar previous sum negative hai
to usse carry karna hamesha nuksan karega


[-2,1,-3,4] =0
Agar next se start kare:
[1,-3,4]
sum = 2


Kya mujhe pura [-2,1,-3] saath lekar chalna zaroori hai?
Ya kabhi aisa point aata hai jahan purana sum burden ban jata hai?

Index 3 pe:
[-2,1,-3,4] =0
Agar next se start kare:
[1,-3,4]
sum = 2

Iske pass 2 option hai 
  1.puuranasum+currentelemet =0
  2.currentelemnt h lo sirf  =4

  aab inh dono mein compare kro kun sa best answer hai   4 better hai
 
step6:Pattern identify kro
Aab har element ke liye sirf 2 choices hai humre pass
 1. Purane subarray ko extend karo
 2. Naya subarray yahin se start karo

 Example:
 Current = 2

Choice 1:
 PreviousSum + 2
Choice 2:
 Sirf 2

 Kadane Algorithm yhi kehti hai
 1. mai optimized sum ko kr rha hu
 2.kya cuurent segemnt continue karke bemefical hai
    ya remove krke
 3.Har index pe meri currentstate kya hai 
   currenetsum
 4.bestanswer jo hai vo nikal kr dena hai hume
 
 step7:Generic template likho
1. Array ko left to right traverse karenge.

2. currentSum = nums[0]
   bestSum    = nums[0]

3. Har index par 2 choices hongi:
   Choice 1:
   Previous subarray extend karo
   previousSum + currentElement

   Choice 2:
   Naya subarray start karo

   currentElement

4. Dono mein jo maximum hoga
   wahi currentSum banega.
5. bestSum ko update karte rahenge.
6. Last mein bestSum return kar denge.
 step8:Dry Run-
nums = [-2,1,-3,4,-1,2,1,-5,4]
         0 1  2 3  4 5 6  7 8

currentsum=-2
bestsum=-2

i=1
extend=-2+1=-1
new=1
bestchoice=1

currentsum=1
bestsum=1

i=2
extend=1-3--2
new=-3

best choice = -2
currentsum=-2
bestsum=max(-2,1)=1

i=3
extend=-2+4=2
new=4
bestchoice=4
currentsum=4
bestsum=max(4,1)=4

contine.....



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int currentsum=nums[0];
        int bestsum=nums[0];

        for(int i=1;i<n;i++){
            int extendarray=currentsum+nums[i];
            int newarray=nums[i];

            currentsum=max(extendarray,newarray);
            bestsum=max(currentsum,bestsum);
        }
        return bestsum;
    }
};