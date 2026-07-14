Given an array of integers nums which is sorted in ascending order,
and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4

step1:Question convert into your form
1.Hume ek integer array diya gaya hai jo sorted hai ascending order mein
2.Aur Hume ek target bhi diya gaya hai
3.Hume puure array mein target find out krke dena hai
4.Agar nhi mila to return -1 kr dena hai
5.Lekin issue ye hai ki hum Linear nhi check kr sakte hai kyuki linear check krne mein Tc : O(n) hoti hai
6.Hume to  O(log n) mein solve krna hai 
7.Agar hum search krne ki space ko aadha kr de to mera O(log n ) mein solve ho jayega

step2:Input dekho
nums = [-1,0,3,5,9,12], target = 9
         0 1 2 3 4 5

Observation: 
1.Humra array sorted hai
2.Iska Middle element niaklo/ya uska index nikalo
  Step 1  : Middle dekho

  [10,20,30,40 | 50,60,70,80]  n=8
  Aadha hata diya.
  Remaining : 4

  step 2 : Fir divide 
  [10,20 |  30,40]
  Aadha hata diya
  Remaining : 2


  Observation:
   8 - 4 - 2 - 1  Humne teen baar divide kiya sirf
Pattern:

n=8   → 3

n=16  → 4

n=32  → 5

n=64  → 6  

Ye numbers kis jaise lag rahe hain?
2³ = 8
2⁴ =16
2⁵ =32
2⁶ =64

Yahi logarithm hai.
 
n

↓

n/2

↓

n/4

↓

n/8

↓

n/16


n / 2ᵏ = 1
n = 2ᵏ
log₂ n = log₂(2ᵏ)
log₂ n = k
Aur k kya tha?  Iterations

Iterations = log₂(n)
Time Complexity = O(log n)


step3:Brute force socho loop vhli
1.Hum puure array mein sabse pehle middle index nikal kr layenge
2.vo middle index ke teen condition ban sakti hai
   index==x  return index
   index > x  update end=mid-1
   index < x  update start=mid+1
3.Ye tab tk contiue krenge jbh tk humre pass space h khtm na ho jaye ur jab tk hume answer h na mile


step4:Code
    int search(vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            else if (nums[mid] > target) {
                end = mid - 1;
            }

            else {
                start = mid + 1;
            }
        }

        return -1;
    }
};


