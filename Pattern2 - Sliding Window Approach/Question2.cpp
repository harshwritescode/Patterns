Given an array of positive integers nums and a positive integer target, 
return the minimal length of a subarray whose sum is greater than or equal to target.
 If there is no such subarray, return 0 instead.

nums = [2,3,1,2,4,3]
target = 7

condition:
maximal length subarray whose sum >= target

Possible Subarray:
[2,3,1,2] =8  length =4
[3,1,2,4] =10  length =4
[1,2,4] =7   length =3
[2,4,3] =9   length =3
[4,3]= 7  length =2


step1: Question Convert into your lanmguage
1. array of positive integers
2. target diya hai
3. subarray chiye (contigous )
4. aisa subarray chiye jiska sum>=target 
5. Length minimal honi chiye 
6. koi subarray nahi return 0

step2: Input dekho
nums = [2,3,1,2,4,3]  target=7
possible subarray :
[2,3,1,2] =8  (length:4)
[3,1,2,4]=10  (length:4)
[1,2,4]=7 (length:3)
[2,4,3]=9 (length:3)
[4,3]=7   (length:2)

observation:
1.hume minimal length chiye
2.saare positive number hai
   iska mtlb ye hua 
   right pointer agar aage badhaoge to hamesa sum badega
   left pointer aagr aage badhaoge to hamesa sum kam ghatega

[2,3,1] sum=6
right++
[2,3,1,2] sum=8 (increase)

[2,3,1,2] sum=8  
left++
[3,1,2] sum=6 (decrease)

Ye property negative numbers mein nahi hoti.
Isi wajah se Sliding Window use kar sakte hain.


step3:Brute Force socho
1.Har index se start karo
2.Uske aage sum calculate karo
3.jab bhi sum >= target
4.length calculate karo

step4: Dry Run-
[2,3,1,2,4,3]    target=7
 0 1 2 3 4 5

 start from 0
 2
 2+3=5
 2+3+1=6
 2+3+1+2=8  condition satisfied (target mihl gaya)

 length=4

 start from 1
 3
 3+1=4
 3+1+2=6
 3+1+2+4=10  condition satisfied (target mihl gaya)

 length=4

 start from 2
 1
 1+2=3
 1+2+4=7     condition satisfied (target mihl gaya)

 length=3

aise h sab check krenge

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        int ans=INT_MAX;

        for(int left=0;left<n;left++){
            int sum=0;

            for(int right=left;right<n;right++){

                sum+=nums[right];

                if(sum>=target){
                    ans=min(ans,right-left+1);
                }
            }
        }
        return (ans==INT_MAX)?0:ans;
    }
};


step5: Brute Force mein repeat kya ho rha hai ??
Hum baar baar same element add kr rhe hai

 2+3+1+2=8 
 fir next iteration
 3+1+2=6
 fir
 1+2=3

 Same elements repeatedly process ho rahe hain.

Question :  Kya mujhe har baar starting se sum banana zaruri hai?
Answer : Nahi , Ek running sum maintain kar sakte hain.


step6: Pattern nikalo
sum>=target aur minimallength chiye 

jab target mihl jaye : window ko ur chota karne ki koshish karo  ( minimallength chiye )
its means target milte hi left ko aaage badha do aur window shrink karo

step7:Sliding window discovery
[left........................right]

Initially - 1)left:0 &&b sum=0
            2) right ko move karte jao 
            3) jab tak condition satisfied na ho jaye
            4) jaise h condition shi ho jaye  to answer humra update ho jana chiye
            5) left ko aage move kr do
            6) taaki window choti ho jaye

step8: Dry Run

nums=[2,3,1,2,4,3] target=7
      0 1 2 3 4 5
left=0
right=0
sum=0

initially sum=2
left=0 right=1 sum=2+3=5
left=0 right=2 sum=2+3+1=6
left=0 right=3 sum=2+3+1+2=8   ans=4

condition satisfied mein hume window shrink krna hai
left=1 right=3 sum=sum-arr[left]=8-2=6
left=1 right=4 sum=6+arr[right]=10 ans=4
left=2 right=4 sum=sum-arr[left]=10-3=7
left=2 right=4 sum=7 condition satisfied ans=right-left+1=4-2+1=3

left=3 right=4 sum=sum-arr[left]=7-1=6
left=3 right=5 sum=sum+arr[right]=6+3=9 condition satisfied ans=right-left+1=5-2+1=3 left++

left=4 right=5 sum=sum-arr[left]=9-2=7  condition satisfied ans=right-left+1=5-4+1=2 left++
left=5 right=5 sum=7-4=3 
left=5 right=6 (condition failed)


step9:Generic Template

a)right expand karo
b)condition satisfy hote hi
c)left shrink karo


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int left=0;
        int sum=0;

        for(int right=0;right<n;right++){
            sum+=nums[right];

             while(sum>=target){
                ans=min(ans,right-left+1);
                sum=sum-nums[left];
                left++;
             }


        }
         return ans==INT_MAX ? 0 : ans;
    } 
};

