2016. Maximum Difference Between Increasing Elements
Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].
Return the maximum difference. If no such i and j exists, return -1.

nums = [1,5,2,10]
        0 1  2 3
Output:
maimum difference between 10-1=9


step1:Question convert into your form
1.array diya gaya hai hume jo 0 based indexing ko hold krta hai
2.hume ek condition dhi gayi hai
    0 < = i <j <n
    iska mtlb ye hua humre 
    [0,1,2,3 ........n]
    humra array index isme lie krta hai
    i aur j jo bhi variable hai vo hamesa array se bahar nhi ja payenge

    let suppose array size n=5
    [0,1,2,3,4]  
 3. ek condition ur likhi hai nums[i] < nums[j]
    iska mtlb hume nums[i] hamesa chota h dhundna hai
    nums[j] hame bada dhundna hai
 4. ye condition array hai ur isme order bhi matter krta hai
 5. hume jo pointer k beech mein maximum differnce dind out krke lana hai 
 6. maximum element ko return kr denge
 
 step2:Input dekho-

 nums = [1,5,2,10]
        0 1  2 3


     1. dekhho hume maximum differnce nikalna hai
     2. agar hume maximum differnce ke indexes return krne hote to hume sort karne se pehle original vhle array ke index store krne padte
     3.  at index 0
         [1,5] = nums[j]-nums[i]=4
         [1,2] = nums[j]-nums[i]=1
         [1,10] =nums[j]-nums[i]=9

         at index 1
         [5,2]= nums[j]-nums[i]=3
         [2,10]=nums[j]-nums[i]=8

         at index 2
         [5,10]=nums[j]-nums[i]=5

         ans=max(all one)=9

  step3:Brute force socho-
   1. sort krenge
   2.Hum 0 index se start krenge 
   3.ushi ke nadar ek nested loop J=i+1 ke liye use krenge    
   4. maximum difference nikal lenge
   5. ans mein update krenge
   6. return ans kr denge
   
  step4:Dry Run:-
nums = [1,5,2,10]
        0 1 2 3

ans = -1

i  n  condition1(i<n)   j  n  condition2(j<n)  nums[j]  nums[i]  valid(nums[i]<nums[j])  difference=nums[j]-nums[i]  ans=max(ans,difference)

0  4      0<4           1  4       1<4            5         1              true                    4                     4

                                2<4            2         1              true                    1                     4

                                3<4           10         1              true                    9                     9


1  4      1<4           2  4       2<4            2         5              false                  -                     9

                                3<4           10         5              true                    5                     9


2  4      2<4           3  4       3<4           10         2              true                    8                     9


3  4      3<4           4  4       4<4  (false)


4  4      4<4 (false)


class Solution {
public:
    int maximumDifference(vector<int>& nums) {
       int ans=-1;

       for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]<nums[j]){
            int difference=nums[j]-nums[i];
            ans=max(ans,difference);
            }
        }
       } 
       return ans;
    }
};

step4:Brute Force Repeat kya ho rha hai
1. Hum har index se previous element ko subtract kr rhe hai agar vo valid hota hai to
let suppose  :   [7,1,5,4]
                  0 1 2 3

                  at index j=2 value=5
                  agar maximum difference nikalna hai 
                  7,1 dono ki zarurat hai kya ???
                  ya sirf pichle element
                

                  10-1=9
                  10-2=8
                  10-5=5

                  hume 10 ke saath maximum difference nikalne ke liye mujhe kya 1,5,2 teeeno yaad rakne ki need hai??
                   NAHI,Sabse bada answer hamesha sabse chhote previous element se aaya.

 step5: Pattern Analysis kro
 jab bhi question mein pattern ho
   current Element+ Prevois Element

aur brute force baar baar previous element ko scan kare
toh socho,
  Kya previous elements ki koi useful information
  maintain karke rakhi ja sakti hai?

 step6:Generic template:-
 1. Left side ka minimum element maintain karo.

2. Har current element par:
      current - minimum_left
   se answer improve ho sakta hai ya nahi dekho.

3. Fir minimum_left update karo.

4. End me answer return karo. 


class Solution {
public:
    int maximumDifference(vector<int>& nums) {
       int n=nums.size();
       int min_left=nums[0];
       int ans=-1;
        for(int i=1;i<n;i++){
            if(nums[i]>min_left){
                ans=max(ans,nums[i]-min_left);
            }

            min_left=min(min_left,nums[i]);
        } 
        return ans;
    }
};
 





