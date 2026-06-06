Given an array of integers arr[], 
find the contiguous subarray with the maximum sum that contains only non-negative numbers.
If multiple subarrays have the same maximum sum return the one with longest length. 
If there is still a tie, 
return the subarray with the smallest starting index. If the array contains only negative numbers,
 return -1.

 arr[] = [1, 2, 5, -7, 2, 6]
          0  1  2   3  4  5
 output:[1,2,5]

 index=0
 [1]   =1
 [1,2] =3
 [1,2,5] =8
 [1,2,5,-7] = 1
 [1,2,5,-7,2] = 3
 [1,2,5,-7,2,6] =9   

 index=1
 [2] =2
 [2,5] =7
 [2,5,-7] =0
 [2,5,-7,2] =2
 [2,5,-7,2,6] =8

 index=2
 [5] =5 
 [5,-7] =-2
 [5,-7,2] =0
 [5,-7,2,6] =6

 index=3
 [-7] = -7
 [-7,2] =-5
 [-7,2,6] =1

 index=4
 [2] =2
 [2,6] =8

 index=5
 [6]=6 


ans=[1,2,5]

step1:Question convert into your form
1. array diya gaya hai with positive and negative numbers
2. contigous subarray find krna hai 
3. ur vo contigous subarray ka answer hum tab calculate krenge agar usme koi bhi negative element na ho
4. humne select kr liya hai aab mere valid window aa gaye hai
    unh window ka sum nikal lenge jo maximum hoga sum 
    uska window return kar denge
5.  aisa bhi ho sakta hai 3 ya 4 subarray aise aa jaye usse jada bhi ho sakte hai jinka sum apas mein equal ho
     aise case mein     
      1. jinki length sabse longest ho vo rerurn kr do
      2. agar tab bhi tie ho rha hai
         samllest starting index vhla subaaray return kr do

         Possible subaaray:-
        a.[1,2,5] =8 
        b.[1,2,5,-7,2,6] =9  
        c.[2,5,-7,2,6] =8 
        d.[2,6] =8

        a and d valid hai kyuki isme koi bhi negative elemnet nhi hai subarray ke andar
        b and c mein negative element hai
        a and d mein hum return longest length vhli subarray return karenge

step2:Input dekho        

 arr[] = [1, 2, 5, -7, 2, 6]
          0  1  2   3  4  5
 output:[1,2,5]

 Observation:
  1.hume window h vhi pick krni hai jisme negative element present na ho
  2.chliye humne valid window/subarray find kr liya
  3.aab jo bhi window /subaaray aaye hai unka sum calculate krenge
  4.mujhe length bhi calculate krni padegi 
  5. kyuki tie hone pe hume longest length return vhla subaaray vaps krna hai'
  6. phir bhi tie hua jo smallest starting index se start hua ushe return krna padega
  7. length maintain krna jruri hai running sum maintian krna padega


step3:Brute Force:
1.Har index se start krke mai valid window find krke launga
2. jo valid window ya subaaray hogi unka sum calculate krke denge
4.sum return krne se pehle uski length bhi store jarur kr lenge uska starting point ur ending point
5. agar tie hua humre pass condition hai ushe match krke return krenge
6.last mein ans array/vector vapas kr denge

step4:Dry Run-
 arr[] = [1, 2, 5, -7, 2, 6]
          0  1  2   3  4  5

 i    n     i<n      ans[]   currentElement   j   n    j<n     if(window is positive(ans[])       ans[]            currentsum=0      
 0    6     0<6      []         1             0   6    0<6               arr[0]= 1(true)            [1]                 1
                                              1   6    1<6               arr[1]=2(true)             [1,2]               3                                   
                                              2   6    2<6               arr[2]=5(true)             [1,2,5]             8
                                              3   6    3<6               arr[3]=-7(false)
                                              
                                              inner loop se bahar aana padega break krke aa sakte hai
                                              staring index=0
                                              ending index=3
                                              ans=[1,2,5]
                                              currentsum=8
                                              totalsum=8
                                              ans ko phir se empty krna padega 
                                              currentsum=0

 1    6     1<6       []         2            1     6    1<6              arr[1]=2                  [2]                2                          
                                              2     6    2<6              arr[2]=5                  [2,5]              7
                                              3     6    3<6              arr[3]=-7(false)

                                               inner loop se bahar aana padega break krke aa sakte hai
                                               check kro  currentsum bada hai ya totalsum bada hai
                                               if(currentsum>=totalsum)  7>8false kuch update nhi hoga

 2    6     2<6      []          5            2     6    2<6              arr[2]=5                    [5]               5
                                              3     6    3<6              arr[3]=-7(false)

                                               inner loop se bahar aana padega break krke aa sakte hai
                                               check kro  currentsum bada hai ya totalsum bada hai
                                               if(currentsum>totalsum)  5>8false kuch update nhi hoga


 3    6      3<6     []          -7           3     6    3<6             arr[3]=-6(false)            

                                                inner loop se bahar aana padega break krke aa sakte hai
                                               check kro  currentsum bada hai ya totalsum bada hai
                                               if(currentsum>=totalsum)  5>8false kuch update nhi hoga
                                                
                                               yaha bug nikala currentsum calculate h nhi kiya to check kaise krega
                                               kyuki hum ans mein h tab daal rhe jbh vo positive hoga
   
                                                ek condition kuch lagna padega

  4    6     4<6     []          2            4      6     4<6           arr[4]=2                     [2]                2
                                              5      6     5<6           arr[5]=6                     [2,6]               8                      
                                              6      6     6<6(false)      
                                              
                                                inner loop se bahar aana padega break krke aa sakte hai
                                               check kro  currentsum bada hai ya totalsum bada hai
                                               if(currentsum>=totalsum)  8>=8false kuch update nhi hoga
                                                  int length=5-4+1=2
                                                  length compare kr lenge

                                                  maximum length vhla h return krenge to pta chla puurna vhla h return krna hai

                                                    
                                                
// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
      int n=arr.size();
      
      long long bestSum = -1;
        int bestLen = 0;
        int bestStart = -1;
      
      for(int i=0;i<n;i++){
             long long currSum = 0;
             int currLen = 0;
             
                  for (int j = i; j < n; j++) {
                      

                if (arr[j] < 0) {
                    break;
                }
                
                
                currSum += arr[j];
                currLen++;
                
                                // update best answer
                if (currSum > bestSum ||
                   (currSum == bestSum && currLen > bestLen) ||
                   (currSum == bestSum && currLen == bestLen && i < bestStart)) {

                    bestSum = currSum;
                    bestLen = currLen;
                    bestStart = i;
                }
                  }   
      }
      
      if (bestSum == -1) return {-1};
        
        
                // result build karo
        vector<int> result;
        for (int i = bestStart; i < bestStart + bestLen; i++) {
            result.push_back(arr[i]);
        }
        
                return result;
      
        
    }
};


step5:Repeat work identify karo

1.Same subaaray sum repeatly calculate ho rha hai
i = 0
[1] = 1
[1,2] = 3
[1,2,5] = 8

i = 1
[2] = 2
[2,5] = 7   ❌ (5 already part of previous computation)

i=2
[5] = 5   ❌ again recomputing

2. arr[j]<0
  this check happen for evey i and j n^2 times
  Negative check is repeatedly performed for every (i, j) pair

  “Same subarray sums are recomputed multiple times due to overlapping subarrays, 
  and negative element checks are repeatedly performed for every (i, j) pair, leading to redundant computations.”

step6:Pattern Analysed karo
  Jab tum [1,2,5] par ho aur next element aata hai: -7
   to hum keh rhe hai break kr do 
   iska mtlb ye hua abhi tk tumne jo compute kiya vo “current subarray ab useless ho gaya”

   Step 1: Ab real Kadane intuition aata hai
     Ab socho:
    Instead of recomputing everything…
    tum bas track kar rahe ho:
    “current best running segment kya hai?”
       option1: extend current subarray
       option2: new subarray start from here
       currSum = max(arr[i], currSum + arr[i])

   Ab tumhare problem me twist kya hai?    
  negative allowed nahi hai
  negative aaya ⇒ segment break
  That means:
   currSum = 0 restart

  step7:Generic Tempalte
    1.    currsum=0
           start=0
           bestsum=-1
           beststart=-1
           bestlen=0
     
    2. for i in arr
    3. if(arr[i]<0)
        currsum=0
        start=i+1
        continue  (negative yaha se hat gaya)
     
    4.  currSum += arr[i]  

    5.  if currSum > bestSum
   OR (currSum == bestSum and length longer)
   OR (tie and smaller start index):

    update answer



// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        int n=arr.size();
        int currlength=0;
        int currentsum=0;
        int start=0;
        int bestsum=-1;
        int beststart=-1;
        int bestlen=0;
        
        for(int i=0;i<n;i++){
            int currentlen=0;
            if(arr[i]<0){
                currentsum = 0;
                currlength = 0;
                start = i + 1;
                continue;
            }
            
            currentsum+=arr[i];
            currlength++;
            
            if(currentsum>bestsum || (currentsum==bestsum && currlength>bestlen) || (currentsum==bestsum && currlength==bestlen && i<beststart))
            {
                bestsum=currentsum;
                bestlen=currlength;
                beststart=start;
            }            
            
        }
         if (bestsum == -1) return {-1};
         
    vector<int> result;
        for (int i = beststart; i < beststart + bestlen; i++) {
            result.push_back(arr[i]);
        }
        
        return result;
        
        
    }
};