Question 10: Maximum Element in an Array using Recursion
Given an integer array arr of size n, return the maximum element present in the array using recursion only.

arr = [7, 2, 15, 9, 11]
Output:15
Function Signature: int maxElement(vector<int>& arr, int index);
Constraints:- 1 <= n <= 10^5
             -10^9 <= arr[i] <= 10^9
              Do not use loops (for, while, etc.).
              Solve only using recursion.

step1:-Question Convert into your form
1.Humre pass ek integer array diya gaya hai jiska size n mentinoed hai
2.Hume puure array mein maximum element niklna hai
3.Hum loop use nhi kr sakte hai

step2:-Input dekho:-
arr = [7, 2, 15, 9, 11]     n=5
       0  1   2  3   4

  Phase 1:-
     maxi=7
    maxElement(arr,7,1)
  Phase 2:- 
 arr = [7, 2, 15, 9, 11]     
       0   1   2  3   4   
           i
     maxi(7,2)=7

     maxElement(arr,7,2)

    Phase 3:- 
 arr = [7, 2, 15, 9, 11]     
       0   1   2  3   4   
               i
     maxi(7,15)=15

     maxElement(arr,15,3)

    Phase 4:- 
 arr = [7, 2, 15, 9, 11]     
       0   1   2  3   4   
                  i
     maxi(15,9)=15

     maxElement(arr,15,4)

    Phase 5:- 
 arr = [7, 2, 15, 9, 11]     
       0   1   2  3   4   
                      i
     maxi(15,11)=15

     maxElement(arr,15,5)

     i>=n   return maxi;  

 step3:-Recursion ki soch:-
 1.Hum kya optimized krne ka try kr rhe hai ???  maximumElement
 2.Hume rukna kab hai ??  (i>=n) return maxi;
 3.Hum kitni baar recursion call kr rhe hai ?? (index+1)
 4.Hum problem ko chota kaise kr rhe hai (arr,maxi,index+1)
 5.Hum answer kaise generate kaise kr rhe hai  ??  har index pe maximum element nikal kr aage ke liye call kr rhe hai
 
 
int maxElement(vector<int>& arr, int maxi ,int index){
    int n=arr.size();

    if(index>=n){
        return maxi;
    }

    int maximumelement=max(arr[index],maxi);

    return  maxElement(arr,maximumelement,index+1);
}
      i
   ( [7,2,15,9,11]| 7 | 1 )
               |
        i       
   ( [7,2,15,9,11]| 7 | 2 )
               |
           i    
   ( [7,2,15,9,11]| 15 | 3 ) 
               |
             i  
   ( [7,2,15,9,11]| 15 | 4 ) 
               |
                i
   ( [7,2,15,9,11]| 15 | 5 )

    Ye Tail Recursion hai.
    
    Current Answer Update

           ↓

     Recursive Call

  step4:Function Signature Optimized kaise kre

int maxElement(vector<int>& arr, int index){
    int n=arr.size();
    if(index>=n)  return arr[index];

    return max(arr[index],maxElement(arr,index+1));
}


   max(7,maxElement(arr,1))                                                max(7,15)=15
            |
            max(2,maxElement(arr,2))                                        max(2,15)=15
                      | 
                      max(15,maxElement(arr,3))                             max(15,11)=15
                                 |
                                 max(9,maxElement(arr,4))                    max(9,11)=11
                                          |
                                          max(11,maxElement(arr,5))           max(11,11)=11
                                                     |
                                                     if(index==n-1)  return 11
           


Ab tak tumne recursion ke do major patterns seekh liye hain:

✅ Accumulator / Tail Recursion
Array Sum
Maximum Element (with maxi parameter)
✅ Return Value / Head Recursion
Array Sum
Maximum Element (without maxi parameter)                                                     