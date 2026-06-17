Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
A circular array means the end of the array connects to the beginning of the array. 
Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. 
Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.


nums = [1,-2,3,-2]
Output:3
subarray [3] has maximum sum=3

step1:Question convert into your form
1. hume ek circular integer type ka array diya hai jisme poitive, negative number hai
2. humre non-empty subarray ka matlab hai ki
    hume aise subarray nikalne hai jisme atleast ek element to ho h 
    jo subarray nikal kr aayenge 
    usme hume maximum sun find out krna hai ur ushe return kr dena hai
3.  nums = [1,-2,3,-2]
            0  1 2  3
            
            agar next element pe jana hai hume to kaise jate hai circular mein
             arr[3] = arr[(3+1)%4]
             arr[3] = arr[0]
            agar previous element pe jana hai circular mein
             arr[3]=arr[(i-1+n)%n]
                   =arr[6%4]
                   arr[2]
 4.subarray mein har original index sirf 1 baar use ho sakta hai  

step2:Input dekho
   nums = [5,-3,5] | [5,-3,5] | 
           0  1 2     0  1 2              

         at index 0:
           [5] = 5
           [5,-3] =2
           [5,-3,5]=7
        at index 1:
           [-3] = -3
           [-3,5] =2
        at index 2: 
            [5]=5
        circular movement ho gayi
         at index 2 se index 0
          [5,5]=10   valid
           2  0 
          [5,5,-3]=7  valid 
           2 0  1

          [5,5,-3,5]=12 invalid
           2 0  1  2   

      Observation:
      1.jab bhi hum circular array move kr rhe hai 
      2. to hume ek cheej check jarur kr lena hai 
      3.har subarray me har index at most once use ho sakta ha

    
step3:Brute force soco
  nums = [5,-3,5]
          0  1 2
  1. Hum array/vector ko left to right traverse krenge
  2. hum har index se start hoke subarray ka sum niaklenge
  3. lekin ye circular array/vector hai to iske elememt ko hum direct access nhi krenge
     normal array-
      at index 2 :-
       nums[2] yha pe h loop se bahar aana padta hume 
        circular array :- nums[(2+2)%n]
                         nums[4%4]
                         nums[0]

       at index 1:-
        nums[1] direct access ho jata 
       agar hume 0 se 1 index pe jana hai to kaise jaate
       nums[(0+1)%4]
       nums[1%4]
       nums[1]

       nums[(i+j)%n]
    4.running sum maintain kr lenge
    5.ans update kr lenge   

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){   //offset pehle index se kitna aage chle ye mtlb hai
                int index=(i+j)%n;
                sum+=nums[index];
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};

STEP4:Dry run -

      nums = [5,-3,5]
              0  1 2    
              n=3

   sum har i=0 pe reset ho jaata hai
        i=0   j=0   sum=0  index=0  sum=5  ans=5
              j=1   sum=5  index=1  sum=2  ans=5
              j=2   sum=2  index=2  sum=7  ans=7 

        i=1   j=0   sum=0  index=1  sum=-3 ans=7
              j=1   sum=-3 index=2  sum=2  ans=7
              j=2   sum=2  index=0  sum=7  ans=7
              
        i=2   j=0   sum=0  index=2  sum=5  ans=7
              j=1   sum=5  index=0  sum=10 ans=10
              j=2   sum=10 index=1  sum=7  ans=10
              j=3 3<3  false

          Repeated Full sum: 
           i=0 se full sum :7
           i=1 se full sum :7
           i=2 se full sum: 7
           
           Partial sum bhi repeat ho rha
           i=0 5+(-3)=2
           i=1 -3+5=2

step5: Repeat work analysis kro
1. har baar i se sum hum baar baar reset kr rhe hai
2. har baar partially sum bhi update ho rha hai
3. normal kadane laga de agar to sayad kaam chl jayega

      nums = [5,-3,5]
              0  1  2

           bestmaxans=nums[0]=5
           
           i=1
             option1: include:- bestmaxans,nums[i+j]%n;
             option2: exclude:- nums[i+j]%n
             bestmaxans=max(include,exclude)

             return bestmaxans

             issue ye hai 
             i=0 j=0 , j=1 ,j=2 tk chl rha hai
             phir j reset ho jata hai
             ishe kaise solve kre
             
             Normal Kadane's i ko sirf aage badhata hai. Woh idx=2 ke baad idx=0 pe wrap nahi kar sakta.
              
             Normal kadane simple array pe lag jayegea easily 
             Circular mein kaise lagega:-
               [5,5]=10

               Agar best circular subaaray =10
               toh jo bahar ja raha hai =-3

               10=7-(-3)
                 =total sum - (minimum subarray sum)

                 ans = max(
               max_subarray_sum,           ← Case 1: Kadane's normal
               total_sum - min_subarray_sum ← Case 2: wrap wala
            )

 class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int bestmaxsum=nums[0];
        int currentmaxsum=nums[0];
        int bestminsum=nums[0];
        int currentminsum=nums[0];

        int total_sum=0;
        for(int i=0;i<n;i++){
            total_sum+=nums[i];
        }

        for(int i=1;i<n;i++){
            currentmaxsum=max(currentmaxsum+nums[i],nums[i]);
            bestmaxsum=max(currentmaxsum,bestmaxsum);
            currentminsum=min(currentminsum+nums[i],nums[i]);
            bestminsum=min(currentminsum,bestminsum);
        }

        if(bestmaxsum<0) return bestmaxsum;
         return max(bestmaxsum, total_sum - bestminsum);
    }
};           