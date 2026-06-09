Given an integer array arr and an integer k, modify the array by repeating it k times.

arr = [1,2], k = 3
Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.
As the answer can be very large, return the answer modulo 109 + 7.

arr=[1,2,1,2,1,2]
maximum sum=9

step1:Question convert into your form
1.Ek array diya gaya hai jisme poitive and negative number dono hai
2.hum array ko modify kr sakte hai k times
3.modify mein hum sirf ur copy kr sakte hai same element
  [1,2] k=3
  n=3

  [1,2,1,2,1,2]
  n=6
4.jo modify subarray niklegi usme hum maximum sum subarray nikal lenge
5. length of subaaray 0 bhi ho sakta hai 
   to ush case mein direct hum 0 return kr denge
6. return answer % (10^9 + 7)
   
 step2:Input dekho
  arr = [-1,-2], k = 7
  modifiedarr=[-1,-2,-1,-2,-1,-2,-1,-2,-1,-2,-1,-2] 
                0  1  2  3  4  5  6  7  8  9  10 11

   0: [-1]
   1:  [-1,-2]
   2: [-1,-2,-1]
   3: [-1,-2,-1,-2]
   4: [-1,-2,-1,-2,-1]
   5: [-1,-2,-1,-2,-1,-2]
   6: [-1,-2,-1,-2,-1,-2,-1]
   7: [-1,-2,-1,-2,-1,-2,-1,-2]
   8: [-1,-2,-1,-2,-1,-2,-1,-2,-1]
   9: [-1,-2,-1,-2,-1,-2,-1,-2,-1,-2]
   10: [-1,-2,-1,-2,-1,-2,-1,-2,-1,-2,-1]
   11: [-1,-2,-1,-2,-1,-2,-1,-2,-1,-2,-1,-2]
   12: []   =0

   max(all,0)=0
 Observation:
  1. agar array ke andar saare negative number h present hai 
  2. to hum direct h 0 return kr sakte hai
  3. agar positive negative dono number hai 
  4. to maximum sum find krna hai ush particular window/subarray ke andar
  5. return kr denge maximum sum %(10^9+7) ke saath

step3: Brute force socho
1.Hum pehle array ke andar ye check kr le kya saare number negative to nhi hai 
   haa - to 0 return kr do
   naa - to hum aage proceed kr lenge
2. k number time copy krenge modified array ke andar    
3.hum har index se window/subaaray find krenge
4.window/subarray tk sum  nikal lenge
5.maximum sum update krenge
6. last mein  %(10^9+7) ke saath return kr denge   


class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
       
       bool allnegative=true;

       for(auto it:arr){
          if(it>0){
            allnegative=false;
            break;
          }
       }

       if(allnegative){
           return 0;
       }

       vector<int> ans;
       for(int i=0;i<k;i++){
          for(auto it:arr){
             ans.push_back(it);
          }
       }

       long long ans1=0;
       int n=ans.size();

       for(int i=0;i<n;i++){
         long long  sum=0;
           for(int j=i;j<n;j++){
            sum+=ans[j];
            ans1=max(ans1,sum);
           }
       }

       return ans1%(10^9+7);
    }
};

step4:Repeat work analysis-
1.hum array ko modify kr rhe hai yha pe jisme duplicate k times hum array mein value insert kr rhe hai
2.running time sum to bana rhe hai 
3.har window/subarray ke liye hume sum calculate krna pad rha hai
  arr = [1,2], k = 3
  [1,2,1,2,1,2]
   0 1 2 3 4 5

   let suppose index 2:
     [1,2,1] =sum=4
     at index 3:-
     [1,2,1,2] = sum= puurane sum + new element

     ur hume maximum element find out krna hai 
     ya to puurane element mein add hoke ban sakta hai
     ya add na hoke ban sakta hai

     arr = [1,-2,1], k = 5
     arr=[1,-2,1,1,2,-1,1,2,-1,1,2,-1,  1,  2,-1]
          0  1 2 3 4  5 6 7  8 9 10 11 12 13 14
     index 2: 
      [1,-2,1]=sum=0
      index 3:
      [1,-2,1,1]=sum=puurane sum+1=0+1
      index 4:
      [1,-2,1,1,2]=sum=puuana sum+new element=1+2=3
      index 5:
      [1,-2,1,1,2,-1]=sum=puurana sum+new element=3+(-1)=2

      continue krte krte khi pe sum negative hua ur 0 bhi hua to hume aage se lena chiye tha subaaray/window i mean reset kr sakte the 
      kadane lag jayega 

   4. k agar bhuat bada hua to memeory hum dubra bana de rhe hai   
    arr = [1,-2,1]  k=2
    Modified array:  [1,-2,1 | 1,-2,1]
    [1,-2,1 | 1,-2,1]
      0  1 2   3 4 5

      [1,-2,1]
      Ye sirf first copy ke andar hai. 
       start=0
       end=2
      [1,-2,1 | 1]
      start=0
      end=3
      Ye bhi contiguous hai.
      Beech me koi gap nahi hai.
      Bas ye first copy se start hua aur second copy me enter kar gaya.

    5.Maximum subarray repeated oart ko cross kr sakte hai
      agar total array sum positive hai to zyada copies useful ho sakti hai
      agar total array sum non-negative hai to bhuat saari copies ka useful benefit nhi hai
      isliye k copies physically banana jaruri nhi hai   

      [1,-2,5 | 1,-2,5 | 1,-2,5 | 1,-2,5]
      maximum subarray agar beech me kahin se start ho aur kahin pe end ho, to uska structure kaisa hoga?

       [5 | 1,-2,5 | 1,-2,5 | 1]

       (last part of first array) + (middle mein kuch complete array ) + (first part of last array)

       1.maximum prefix sum
       2.maximum suffix sum
       3.total sum

        arr = [1,-2,5]
        1. Maximum Prefix Sum
          [1]       = 1
          [1,-2]    = -1
          [1,-2,5]  = 4
          max(1,-1,4) = 4
       2. Maximum Suffix Sum
          Suffix matlab end tak jana hai.
          [5]=5
          [-2,5] =3
          [1,-2,5] =4
          max(5,3,4) = 5
       3.Total sum:
          1 + (-2) + 5 = 4

          Ab ek interesting cheez dekh.
          k = 4
          [1,-2,5 | 1,-2,5 | 1,-2,5 | 1,-2,5]
          Agar koi maximum subarray pehli copy ke end se start ho aur aakhri copy ke beginning pe khatam ho, to uska structure ho sakta hai:
                    best suffix+ middle complete arrays + best prefix
                    suffix + (middle copies)*sum(arr) + prefix

                    suffix = 5
                    sum(arr)=4
                    prefix = 4
                    Aur k = 4 hai.
                    Beech me kitni complete copies hain?
                    k-2 = 2

                    5 + 2*4 + 4
                    = 17


                    Thik hai. Ab main seedha intuition batata hoon.
                    Case 1
                    sum(arr) > 0

                    arr = [1,-2,5]
                    sum = 4
                    Har poori copy tumhe:+4 degi

                    To agar maximum subarray pehli copy ke end se start hui aur aakhri copy ke start tak gayi, to beech ki har complete copy fayda de rahi hai.
                    suffix + copy + copy + prefix
                    5 + 4 + 4 + 4 

                    jitni copies badhengi utna sum bahega

Agar total sum positive hai, to beech ki complete copies rakhna beneficial hai.


                   Case 2
                    sum(arr) <= 0
                    arr = [1,-2,1]
                    sum = 0
                    

step5:Dry Run-
arr = [1,-2,1]
k = 5 

step 1: Total Sum=0
step2:Maximum prefix sum=[1],[1,-2],[1,-2,1]=max(1,-1,0)=1
step3:Maximum suffix sum=[1],[1,-2],[1,-2,1]=max(1,-1,0)=1

[1,-2,1 | 1,-2,1 | 1,-2,1 | 1,-2,1 | 1,-2,1]

Best Suffix + Middle Copies + Best Prefix
Middle copies:k-2=3
Contribution : 3*totalsum
               3*0=0
               1 + 0 + 1 = 2

step6:Generic Template-
Step 1: Kadane (single array max subarray)
Step 2: prefix sum max
Step 3: suffix sum max
Step 4: total sum
Step 5: combine cases

