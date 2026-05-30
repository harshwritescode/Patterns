Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.
Note: A subarray is a contiguous part of any given array.

arr = [100,200,300,400]
k = 2

Possible Subarray :

[100,200] =300
[200,300] =500
[300,400] =700

maximumsum=700

step1:Question convert into your form
1.array diya hai
2.size fixed hai =k
3.mujhe har possible subarray of size k ka sum nikalana hai
4.aur maximun sum retun karna hai
5. subarray= contigous

100+300 = allowed nhi hai

step2:input dekho
arr = [100,200,300,400]
k = 2

100 200 300 400
Observation:
yaha pe window size fixed hai 

[100 200]
[200 300]
[300 400]


step3: Brute force socho

Har index se k element tk ka sum nikalo
i=0  [100,200] sum=300
i=1; [200,300] sum=500
i=2  [300,400] sum=700

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int maxi=INT_MIN;
        for(int i=0;i<=n-k;i++){
            int sum=0;
            
            for(int j=i;j<i+k;j++){
                sum+=arr[j];
            }
            
             maxi=max(maxi,sum);
        }
        
        return maxi;
    }
};

step4: Brute Force mein repeat kya ho raha hai?

Observe clear hai 
window1: [100 200]  =300
window2: [200 300]  =500

Humne dobara pura sum nikala.
Lekin kya iski zarurat thi dimag lagao agar hum isme mathematics shi krte
window1: [100 200]  =300
window2: [200 300]  =500

Notice:  100 remove hua aur 300 add hua humra
Baaki element same hai

Newsum= oldsum-removedelement+added element

step5: Kis pattern se optimised hoga ???
Ye HashMap pattern nahi hai.

Ye hai: Sliding Window Pattern (Window fixed size ki hai.)

Har baar: 1 element bahar ja raha hai
          1 element andar aa raha hai


Pattern
Current Window
 [100 200]
sum=300

Next Window
[200 300]
newsum=oldsum-100+300
      =300-100+300
      =500
Next Window
[300 400]
newsum=oldsum-200+400      
    =500-200+400
    =700


step6: Generic Template
    Subarray + Fixed size k + Maximum/Minimum/Sum

    sliding window 

    1.first window ki information nikal kr save kr lo ( sum,diff,product)
    2.answer update kro
    3.window slide karo
    4.left element subtract karo
    5.right elemnet add karo
    6.answer update kro

step7: Dry Run
arr=[100,200,300,400]
k=2

First Window: 300
maxi=300
     
      0   1   2   3
arr=[100,200,300,400]
              k   n
second window=windowsum+arr[i-k]+arr[i];
             =300-100+300
             =500

      0   1   2   3
arr=[100,200,300,400]    
                  k
                  n
Third Window=windowsum+arr[i-k]+arr[i];                        
             =500-200+400
             =700



class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {

    int n=arr.size();
    int windowsum=0;
    
    for(int i=0;i<k;i++){
        windowsum+=arr[i];
    }
    
    int maxi=windowsum;
    
    for(int i=k;i<n;i++){
        windowsum=windowsum-arr[i-k]+arr[i];
        
        maxi=max(maxi,windowsum);
    }
    return maxi;
    }
};             