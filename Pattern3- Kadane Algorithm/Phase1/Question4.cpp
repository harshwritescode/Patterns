You are given an integer array nums. 
The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.
Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.

nums = [1,-3,2,3,-4]
Output:5
The subarray [2,3] has absolute sum=abs(2+3)=abs(5)=5

step1:Question convert into your form
1.hume ek array diya gaya hai jisme positive negative number dono diye hai
2.hume sum of subarray nikalana hai
3.jo bhi maximum absolute sum of subarray hai vo return kr dena hai
4. agar x negative integer hai  then abs(x)=-x
   agar x non-negative integer hai then abs(x)=x

step2:Input dekho
nums = [1,-3,2,3,-4]
        0  1 2 3  4

      Possible subarray:-
      at index 0:-
        [1] =   1        abs(1)   =1
        [1,-3] = (-2)    abs(2)   =2
        [1,-3,2] = 0     abs(0)   =0
        [1,-3,2,3] = 3   abs(3)   =3
        [1,-3,2,3,-4] = (-1)      =1

        at index 1:
        [-3] = (-3)               =3
        [-3,2] = (-1)             =1
        [-3,2,3] = 2              =2
        [-3,2,3,-4] =  (-2)       =2

        at index 2:
        [2] = 2                   =2
        [2,3] = 5                 =5
        [2,3,-4] = 1              =1

        at index 3:
        [3] =3                    =3
        [3,-4] =-1                =1

        at index 4:
        [-4] =-4                  =4
        ans=5

  step3:Brute Force socho:-
  1.Har index ke liye hum ek subarray nikalenge 
  2.jo bhi subarray hai uska sum nikal lenge
  3.jo bhi sum aayega uska absoulte sum niakl denge
  4.ans update krenge maximum sum vhla
  5. return ans kr denge
  
  step4:Dry Run-
  nums = [2,-5,1,-4,3,-2]
          0  1 2  3 4  5

          at index 0:-
           current element=2
           subarray/window= [2]
           sum=2
           abs(sum)=2
           ans=2

           at index 1:-
           current element=-5
           subarray/window=[2,-5]
           sum=-3
           abs(sum)=3
           ans=3

           at index 2:-
           current element=1
           subarray/window=[2,-5,1]
           sum=-2
           abs(sum)=2
           ans=3

           at index 3:-
           current element=-4
           subarray/window=[2,-5,1,-4]
           sum=-6
           abs(sum)=6
           ans=6

           at index 4:-
           current element=3
           subarray/window=[2,-5,1,-4,3]
           sum=-3
           abs(sum)=3
           ans=6


class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();
       

        for(int i=0;i<n;i++){
             int sum=0;  
            for(int j=i;j<n;j++){
                sum+=nums[j];
                int value=abs(sum);
                ans=max(ans,value);
            } 
        }
        return ans;
    }
};

step5:Repeat work analysed kro

  nums = [2,-5,1,-4,3,-2]
          0  1 2  3 4  5


           at index 2:-
           current element=1
           subarray/window=[2,-5,1]
           sum=-2
           abs(sum)=2
           ans=3

           at index 3:-
           current element=-4
           subarray/window=[2,-5,1,-4]
           sum=-6
           abs(sum)=6
           ans=6

1. Hum har index se ek subarray nikal rhe hai ur unka sum add kr rhe hai
2. baar baar sum count krna pad rha hai 
3. dekha jaye -
    [2,5,-1]  iska sum  aa rha hai (-2)
    jab next iteration mein jaate hai hum 
    [2,5,-1,-4]  to hum puurane sum mein -2+(-4) = -6
    hi kr rhe hai 

    ek running sum se kaam chl jayega humra
4.  ek observation ur smjh aayi 
    humre liye yha pe 
     minimum sum bhi utna hi benefical hai 
     jitna positive sum benefical hai 
     kyuki sum ke baad hum uska absoulte nikal rhe hai

5.
  at index 2:       
  subarray/window=[2,-5,1] 
  sum=-2

  jbh next index pe jaate hai hum [2,-5,1,-4] 
  sum=-6
  yha do option the humre pass 

  ya isko jod kr iska bestsum nikale 
  ya ishe exclude krke 


  step6:Pattern ientify kro
  1.Kadane Algorithm lag jayegi
  2.Maximum sum maintain krna hai running mein vo bhi
  3.har index ko select krke 
    hum ya to bestMinSum bana sakte hai
    ya to bestMaxSum bana sakte hai
  4.jo inh dono mein se best answer hoga vhi humra answer


  step7:Dry Run-
  [2,-5,1,-4,3,-2]
   0 1  2  3 4  5
  currentmin=2      bestmin=2
  currentmax=2      bestmax=2

  i=1
  nums[i]=-5
  currentmax=max(-5,-5+2)=-3
  bestmax=max(-3,2)=2
  currentmin=min(-5,-3)=-5
  bestmin=min(-5,2)=-5
 
  i=2
  nums[i]=1
  currentmax=max(1,-2)=1
  bestmax=(1,2)=2
  currentmin=(1,-4)=-4
  bestmin=min(-5,-4)=-5

  i=3
  nums[i]=-4
  currentmax=max(-4,-4+1)=-3
  bestmax=max(2,-3)=2
  currentmin=min(-4,-8)=-8
  bestmin=-8

  i=4
  nums[i]=3
  currentmax=max(3,3+-3)=3
  bestmax=max(2,3)=3
  currentmin=min(3,-8+3)=-5
  bestmin=-8

  i=5
  nums[i]=-2
  currentmax(=2,1)=2
  bestmax=max(2,3)=3
  currentmin=-7
  bestmin=-8

  ans=max(abs(bestmin),abs(bestmax))
     =max(8,3)
     =abs(4)
     =4


  class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int currentmax=nums[0];
        int currentmin=nums[0];

        int bestmin=nums[0];
        int bestmax=nums[0];


        for(int i=1;i<n;i++){
             currentmax=max(nums[i],currentmax+nums[i]);
             bestmax=max(bestmax,currentmax);

             currentmin=min(nums[i],currentmin+nums[i]);
             bestmin=min(bestmin,currentmin);
        }

        return max(abs(bestmax), abs(bestmin));
    }
};



