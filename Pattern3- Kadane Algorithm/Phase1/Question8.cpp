You are given two 0-indexed integer arrays nums1 and nums2, both of length n.
You can choose two integers left and right where 0 <= left <= right < n and swap the subarray nums1[left...right] with the subarray nums2[left...right].
For example, if nums1 = [1,2,3,4,5] and nums2 = [11,12,13,14,15] and you choose left = 1 and right = 2, nums1 becomes [1,12,13,4,5] and nums2 becomes [11,2,3,14,15].
You may choose to apply the mentioned operation once or not do anything.
The score of the arrays is the maximum of sum(nums1) and sum(nums2), where sum(arr) is the sum of all the elements in the array arr.
Return the maximum possible score.
A subarray is a contiguous sequence of elements within an array. arr[left...right] 
denotes the subarray that contains the elements of nums between indices left and right (inclusive).


step1:Question convert into your form
1.humre pass 2 array diye hai jisme integer value dhi hai hume ur jiski indexing 0 based hai
2.dono ki length same h hai
3.hume do integer select krne hai left aur right   left ur right aise select krne hai ki 0<=left<=right<=n
 iska mtlb n=5
 0<= left<=right<5
 it means left ur right =[0,4] h honge 
4.hume dono array ke andar ushe swap kr sakte hai
5.
    nums1 = [1,2,3,4,5]
             0 1 2 3 4
    nums2 = [11,12,13,14,15]
             0  1  2  3  4
    n=5
    suppose : - left=1  and right=2
     hume swap kr liya 
        nums1: [1,12,3,4,5]
        nums2: [11,2,13,14,15]
6. ye operation hum ek baar ya ek baar bhi na use kre to bhi issue nhi hoga
7. maximum sum(nums1)         maximum sum(nums2)
8. hume possible maximum score return krna hai

step2:Input Observe karo
nums1 = [60,60,60]   nums2 = [10,90,10]
         0  1  2               0  1  2

   Option hai ya to operation kre ya na kre 
   nahi krte hai:
     max(score1):-180
     max(score2):-110
     
     ans=180

     1. aab operation krte hai
              i                     j
     nums1 = [60,60,60]   nums2 = [10,90,10]
              0  1  2               0  1  2
            
              1.swap(nums[i],nums[j])
              nums1:[10,60,60] =130
              nums2:[60,90,10] =160

              i                       j
    nums1 = [60,60,60]   nums2 = [10,90,10]
              0  1  2             0  1  2    
              
              2.swap(nums[i],nums[j])
              nums1:[90,60,60] = 210
              nums2:[10,60,10] = 80

              i                          j
    nums1 = [60,60,60]   nums2 = [10,90,10]
              0  1  2             0  1  2    

              3.swap(nums[i],nums[j])
              nums1;[10,60,60] =130
              nums2:[10,90,60] =160

     
    2.Phir se loop chla   
    
                  i                 j
     nums1 = [60,60,60]   nums2 = [10,90,10]
              0  1  2               0  1  2

            1.swap(nums[i],nums[j])
              nums1:[60,10,60] =130
              nums2:[60,90,10] =160

                  i                   j
     nums1 = [60,60,60]   nums2 = [10,90,10]
              0  1  2               0  1  2  
              
              2.swap(nums[i],nums[j])
              nums1:[60,90,10]=160
              nums2:[10,60,10]=80

 
                  i                      j
     nums1 = [60,60,60]   nums2 = [10,90,10]
              0  1  2               0  1  2  
              
              3.swap(nums[i],nums[j])
              nums1:[60,60,10]=130
              nums2:[10,90,60]=160


 Observation:-
 1.Hume n jo hai dono h array mein same diya jayega
 2.left right 0<=n ke beech ya iske eual hoga
 3.hume swap krne ke baad sum niklna hai individual nums1 ur nums2 
 4. jo usme maximum hoga usko return kr denge
 
Step 3: Brute Force socho
1.Hum do pointer lenge ek left jo hum nums1 mein laga denge ek right lenge jo nums2 ke liye laga denge
2.left ke andar se hum right ka nested loop laga denge
3. swap krenge  swap(nums1[0..2], nums2[0..2])
4.sum calculate krenge dono array ka 
5.maximum sum return kr denge


class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();

        int ans=0;

        int sum1=0,sum2=0;

        //for no operations
        for(int i=0;i<n;i++){
            sum1+=nums1[i];
            sum2+=nums2[i];
        }

        ans=max(sum1,sum2);

        for(int left=0;left<n;left++){
            for(int right=left;right<n;right++){
                vector<int> a=nums1;
                vector<int> b=nums2;

                for(int k=left;k<=right;k++){
                    swap(a[k],b[k]);
                }

                int curr1sum=0;
                int curr2sum=0;

                for (int k = 0; k < n; k++) {
                    curr1sum += a[k];
                    curr2sum += b[k];
                }
     
                ans = max(ans, max(curr1sum, curr2sum));
            }
        }
        return ans;
    }
};
step4:Dry Run:-
nums1 = [60,60,60]   nums2 = [10,90,10]   n = 3  
Iteration 1:
            left=0,right=0
            Swap Loop:
| k | Operation       | a          | b          |
| - | --------------- | ---------- | ---------- |
| 0 | swap(a[0],b[0]) | [10,60,60] | [60,90,10] |

| sum(a) | sum(b) | score |
| ------ | ------ | ----- |
| 130    | 160    | 160   |

Iteration2:
         left = 0, right = 1
         Swap Loop:
| k | Operation       | a          | b          |
| - | --------------- | ---------- | ---------- |
| 0 | swap(a[0],b[0]) | [10,60,60] | [60,90,10] |
| 1 | swap(a[1],b[1]) | [10,90,60] | [60,60,10] |

| sum(a) | sum(b) | score |
| ------ | ------ | ----- |
| 160    | 130    | 160   |

Iteration 3
         left = 0, right = 2
| k | Operation       | a          | b          |
| - | --------------- | ---------- | ---------- |
| 0 | swap(a[0],b[0]) | [10,60,60] | [60,90,10] |
| 1 | swap(a[1],b[1]) | [10,90,60] | [60,60,10] |
| 2 | swap(a[2],b[2]) | [10,90,10] | [60,60,60] |

| sum(a) | sum(b) | score |
| ------ | ------ | ----- |
| 110    | 180    | 180   |

Iteration 4
         left = 1, right = 1
| k | Operation       | a          | b          |
| - | --------------- | ---------- | ---------- |
| 1 | swap(a[1],b[1]) | [60,90,60] | [10,60,10] |

| sum(a) | sum(b) | score |
| ------ | ------ | ----- |
| 210    | 80     | 210 ✅ |

Iteration 5
       left = 1, right = 2
| k | Operation       | a          | b          |
| - | --------------- | ---------- | ---------- |
| 1 | swap(a[1],b[1]) | [60,90,60] | [10,60,10] |
| 2 | swap(a[2],b[2]) | [60,90,10] | [10,60,60] |

| sum(a) | sum(b) | score |
| ------ | ------ | ----- |
| 160    | 130    | 160   |

Iteration 6
      left = 2, right = 2
| k | Operation       | a          | b          |
| - | --------------- | ---------- | ---------- |
| 2 | swap(a[2],b[2]) | [60,60,10] | [10,90,60] |

| sum(a) | sum(b) | score |
| ------ | ------ | ----- |
| 130    | 160    | 160   |


Step 5: Repeat Work Identify Karo

1. Hum har (left,right) ke liye nayi arrays bana rahe hain.

2. Har subarray ke liye same indices ko baar-baar swap kar rahe hain.

3. Sabse bada repeat work:
   Har baar poora sum(nums1) aur sum(nums2)
   dobara calculate kar rahe hain.

4. Agar left,right thoda sa change ho raha hai,
   tab bhi hum poori array ka sum fir se nikal rahe hain.

5. Hume observe karna chahiye ki swap ke baad
   sum mein exactly kitna change aa raha hai,
   instead of poora sum dobara nikalna.

              
step6:Pattern identify karo:-

Har baar subarray swap kar rahe hain
Phir poora sum(nums1) aur sum(nums2) nikal rahe hain

Kya poora sum dobara nikalna zaroori hai?  Nahi
         0  1  2              0  1  2
nums1 = [60,60,60]  nums2 = [10,90,10]
       -50  30 -50           50 -30  50
Initial Sum:-  sum1=180  sum2=110
Index 0 swap: 60 change to 10 and 10 change to 60
            
    nums1 mein kya change hua = (+10-60)=-50
    nums2 mein kya change hua =(-10+60)=50

Index 1 Swap: 60 se 90 aur 90 se 60
   
nums1 mein kya change hua = +(90-60) =30
nums2 mein kya change hua = -(90+60) =-30

Index 2 swap: 60 se 10 aur 90 se 10

nums1 mein kya change hua = +(10-60) =-50
nums2 mein kya change hua = -(10+60) =-50


Difference ka array= nums2[i] - nums1[i]
                    [-50, 30, -50]


Observation:-  Agar kisi range ko swap krte hai  to nums1 ka sum  =>   sum1 + (ush range ka diff sum)  ban jata hai
Kaunsi contiguous subarray ka diff sum maximum hai?

Matlab:

[-50, 30, -50]

mein maximum subarray sum find karo. 30


Case2: Ho sakta hai best answer nums2 mein aaye.

nums1[i] - nums2[i]
wali difference array banegi.
Aur uska maximum subarray sum nikalenge.


step7:Final Pattern

1. Swap ke baad poora sum calculate karne ki zaroorat nahi.
2. Har index par sirf gain/loss matter karta hai.
3. Gain/Loss ko difference array mein store kar sakte hain.              
4. Hume maximum gain wali contiguous range chahiye.
5. Maximum gain wali contiguous range
   = Maximum Subarray Sum
6. Maximum Subarray Sum
   = Kadane Algorithm

step8:Generic template
1. Question mein operation ke baad
   kisi value (sum, profit, score, etc.)
   mein kitna gain/loss aa raha hai
   ushe identify karo.

2. Har index ka individual gain/loss
   difference array mein convert karo.

      diff[i] = NewValue - OldValue

3. Operation contiguous range par apply ho raha hai,
   isliye kisi range ka total gain

      diff[left] + diff[left+1] + ... + diff[right]

   hoga.

4. Ab problem convert ho gayi:

      "Kaunsi contiguous range maximum gain degi?"

5. Contiguous range ka maximum gain
   = Maximum Subarray Sum

6. Maximum Subarray Sum nikalne ke liye
   Kadane Algorithm use karo.

7. Final Answer:

      BaseValue + MaximumGain

8. Agar operation dono directions mein
   possible ho (jaise nums1 → nums2
   aur nums2 → nums1),

   to dono cases ke liye:

      diff1 = nums2[i] - nums1[i]
      diff2 = nums1[i] - nums2[i]

   Kadane chalao aur maximum answer lo.


   class Solution {
public:
    int kadane(vector<int> &diff){
        int currsum=0;
        int bestsum=0;

        for(int x:diff){
            currsum=max(currsum+x,x);
            bestsum=max(bestsum,currsum);
        }
        return bestsum;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();

        int sum1=0,sum2=0;
        vector<int> diff1(n),diff2(n);

        for(int i=0;i<n;i++){
            sum1+=nums1[i];
            sum2+=nums2[i];

            diff1[i]=nums2[i]-nums1[i];
            diff2[i]=nums1[i]-nums2[i];
        }

        int answer1=sum1+kadane(diff1);
        int answer2=sum2+kadane(diff2);

        return max(answer1,answer2);

        // int ans=0;

        // int sum1=0,sum2=0;

        // //for no operations
        // for(int i=0;i<n;i++){
        //     sum1+=nums1[i];
        //     sum2+=nums2[i];
        // }

        // ans=max(sum1,sum2);

        // for(int left=0;left<n;left++){
        //     for(int right=left;right<n;right++){
        //         vector<int> a=nums1;
        //         vector<int> b=nums2;

        //         for(int k=left;k<=right;k++){
        //             swap(a[k],b[k]);
        //         }

        //         int curr1sum=0;
        //         int curr2sum=0;

        //         for (int k = 0; k < n; k++) {
        //             curr1sum += a[k];
        //             curr2sum += b[k];
        //         }
     
        //         ans = max(ans, max(curr1sum, curr2sum));
        //     }
        // }
        // return ans;
    }
};
