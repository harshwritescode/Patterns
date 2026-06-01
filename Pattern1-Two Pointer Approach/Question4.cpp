Given an array arr[] and an integer target,

find the sum of three integers in arr[]
such that the sum is closest to target.

arr = [-1,2,1,-4]
target = 1  

output:2
  
Reason :  (-1+2+1) =2
           target=1;
           difference=|2-1|=1

step1: Question convert into your language

1.array diya hai
2.3 number dhundne hai
3.jiska sum equal hona jaruri nahi hai target ke barabar
4.target ke sabse pass hona chiye
5.number return nahi karne hai
6.indexe return nhi karne hai  
7.closetsum retun karna hai hume

step2: Input dekho

arr = [-1,2,1,-4]
target = 1  

observe: 1)positive ,negative dono number hai 
         2) 3 number dhundne hai
         3) Array unsorted hai
        
step3: Brute Force socho

Mai har 3 number ko check krunga 
(-1,2,1)
(-1,2,-4)
(-1,1,-4)
(2,1,-4)

Har triplet ka sum nikal lunga 
(-1,2,1) = 2
(-1,2,-4) =-3
(-1,1,-4) =-4
(2,1,-4) = 1

Ab har sum ka difference nikalunga
abs(sum-target)

abs(2-1)=1
abs(-3-1)=4
abs(-4-1)=5
abs(-1-1)=2

jiska minimum difference vahi answer hai humre ans=2


step4: Pattern Analysed kro

let suppose humre pass target=10 hai

currentElement=3;
Ab mujhe poora target nahi chahiye

Mujhe chiye 10-3= 7  (Yaani Remaining 2 numbers ka sum  7 ke aas pass hona chiye)

Pattern Analysed hua mujhe

1. Ek element fixed kro
2. remaining target nikalo
3. bache huye array mein 2 number ka best sum dhundo

Ye hi Three Sum Closest ka actual pattern hai


Step5: Question ko aur todh sakte hain
let suppose humne  sorted array kar liya 
[-4,-1,1,2]
target =1

currentElement=-4;
RemainingTarget=target - currentElement
               = 1- (-4)
               =5

 aab mujhe 2 number ka sum 5 ke aas pass chiye 
 
 iske liye hum two pointer approach use kr lenge

   left ,right use karke

   currentSum store kr lo pehle = -4-1+2 =-3
   currentdifference bhi store kr lo = abs(1--3)=4

   currentsum chota hai agar left ++;
   currentsum agar bada hai right --;



step6: Generic Template

1. Array sort karo
2. ek element fixed karo
3. left pointer rakho
4. right pointer rakho
5. currentsum nikalo
6. difference nikalo
7. Better answer mile to update karo  // chota difference h best answer hai
8. Sum < target
      left++
9. Sum > target
      right--
      
      

step7: Dry Run

arr=[-1,2,1,-4]
target=1

after sorted
[-4,-1,1,2]

i=0 
 fixed=-4 arr[0]
 left=1;
 right=3

 currentSum=arr[fixed]+arr[left]+arr[right]
            =-4+-1+2
            =-3
 difference=abs(target-currentsum)
            = |1--3|
            =4
            
 bestsum=-3

 sum target se chota hai  left++;

 [-4,-1,1,2]
        l  r
   
 fixed=-4
 left=2
 right=3

 currentSum=arr[fixed]+arr[left]+arr[right]
           = -4+1+2
           =-1
   
  difference=abs(target-currentsum)
            =|1--1|
            =2

   bestsum=-1

i=1

fixed=-1
left=2
right=3

currentSum = -1 + 1 + 2
           = 2
differencesum =|2-1|
            = 1

            bestsum=2



  class Solution {
  public:
    int closest3Sum(vector<int> &arr, int target) {
       sort(arr.begin(),arr.end());
       int n=arr.size();
       
       int bestsum=arr[0]+arr[1]+arr[2];
       
       for(int i=0;i<n-2;i++){
           int left=i+1;
           int right=n-1;
           
           while(left<right){
              int currentsum=arr[i]+arr[left]+arr[right];
              if(abs(target-currentsum) < abs(target-bestsum) ||
   (abs(target-currentsum) == abs(target-bestsum) &&
    currentsum > bestsum)){
                  bestsum=currentsum;
              }
              
              if(currentsum<target){
                  left++;
              }
              else if(currentsum>target){
                  right--;
              }
              else{
                  return currentsum;
              }
           }
       }
       
       return bestsum;
       
    }
};
   
 






         