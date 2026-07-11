Question: Sum of Array using Recursion
Given an integer array arr of size n, return the sum of all its elements using recursion only.

arr = [2, 4, 6, 8, 10]
30
int arraySum(vector<int>& arr, int index);

Constraints:-
1 <= n <= 10^5
-10^9 <= arr[i] <= 10^9
Do not use loops (for, while, etc.).
Solve only using recursion.

step1:Question Convert into your form
1.Hume ek integer array diya gaya hai jiska size n mentinoed hai
2.Hume sabhi array ke element ka sum niklna hai bina kisi loop ko lagaye
3.Jo sum nikal kr aayega ushe hume return kr dena hai


step2:-Input dekho:-
arr = [2, 4, 6, 8, 10]          sum=0;
       0  1  2  3   4
  Phase 1:-    
       i 
     sum=sum+arr[0]=0+2=2
     (arr,sum,i+1)
  Phase 2:-   
arr = [2, 4, 6, 8, 10]
       0  1  2  3   4
          i
   Phase 3:-       
      sum=2+arr[1]=2+4=6
      (arr,sum,i+1)
   Phase 4:-
arr = [2, 4, 6, 8, 10]
       0  1  2  3   4
             i
      sum=6+6=12
      (arr,sum,i+1)
   Phase 5:-
arr = [2, 4, 6, 8, 10]
       0  1  2  3   4
                i
       sum=12+8=20
       (arr,sum,i+1)
       
   Phase 6:-
arr = [2, 4, 6, 8, 10]
       0  1  2  3   4
                    i
        sum=20+10=30
        (arr,sum,i+1)
        
 step3:-Recursion ki soch:-
 1.Hum kya Optimized krne ka try kr rhe hai ?? - sum
 2.Hum rukna kab chthe hai ??  (i>=n) 
 3.Humeri Problem kaise choti hogi ?? (arr,sum,i+1)  krke 
 4.Humre pass recursion call krne ke kitne options hai ?? only 1 (index+1) h to kr rhe hai
 5.Hum answer kaise generate kaise kr rhe hai ?? sum maintain kr rhe hai aur recursion call kr rhe hai
 
 int arraySum(vector<int>& arr,int sum, int index){
     int n=arr.size();

     if(index>=n){
        return sum;
     }
     return arraysum(arr,sum+arr[index],index+1);
 }

    ([2,4,6,8,10],0,0);
           |
    ([2,4,6,8,10],2,1); 
           |
    ([2,4,6,8,10],6,2);
           |
    ([2,4,6,8,10],12,3);
           |
    ([2,4,6,8,10],20,4);
           |
    ([2,4,6,8,10],30,5);



step4:-Optimized the function signature
int arraySum(vector<int>& arr, int index){
     int n=arr.size();
     
    if(i>=n){
        return 0;
    }

    return arr[index]+arraySum(arr,index+1);
}

[2,4,6,8,10]
 0 1 2 3  4

   2+arraySum(arr,1)                                                      2+28=30
           |
             4+arraySum(arr,2)                                           4+24=28
                           | 
                           6+arraySum(arr,3)                             6+18=24
                                       |
                                        8+arraySum(arr,4)                 10+8=18     
                                                    |
                                                    10+arraySum(arr,5)     10+0=10
                                                          |
                                                          0
                                                
                                                
           
           