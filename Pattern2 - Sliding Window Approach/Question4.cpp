Given an array arr[]  and a positive integer k, 
find the first negative integer for each and every window(contiguous subarray) of size k.

arr[] = [-8, 2, 3, -6, 10] , k = 2

Output:
ans [-8 0 -6 -6]
First Window  [-8,2]  : -8
second Window [2,3]  :  0
third window  [3 ,-6]  : -6
fourth window [ -6 ,10] : -6


step1: Question convert into your language
1.array diya hai jisme positive aur negative element dono hai
2.fixed size window k diya gaya hai
3.har window ko check krna hai
4.har window mein pehla negative element find karna hai
5. agar negative nahi hai to 0 answer mein add kr dena hai
6.return ans array

step2:Input dekho
arr = [-8, 2, 3, -6, 10]
k = 2

Possible windows:
[-8, 2]   → -8
[2, 3]    → 0
[3, -6]   → -6
[-6, 10]  → -6

[-8, 0, -6, -6]

Observation:
1. hume maximum sum nhi chiye / minimum sum nahi chiye /average nahi chiye
2. hume window ke andar first negative number chiye

let suppose window :  [-8,2]  
                      [2, 3]
       jab bhi window slide hua humra  to humra -8 bahar chala gaya window se 
       to hume pata kaise chalega ki current window ka first negative element kun hai??
       
Inout Observation: - Window me kaunsi information maintain karni padegi?
                   - hume negative element maintain karna padega
                   
                   Bas yahin se Queue/Deque ka idea niklega.




step3:Brute Force socho

arr = [-8, 2, 3, -6, 10]
        0  1  2  3   4
k = 2

1.Har window ko check kro
2.window ke andar se left to right traverse karo
3.jaisa h pehla negative element mihl jaye 
   answer mein save kro
   break kar do
4.agar puuri window mein koi negative nahi mila 
   0 store kr do
5.Agli window per jao

for(int i=0;i<=n-k;i++){
    bool found=false;

    for(int j=i;j<i+k;j++){
        if(arr[j]<0){
            ans.push_back(arr[j]);
            found=true;
            break;
        }
    }

           if(!found){
            ans.push_back(0);
        }
}
      [12, -1, -7, 8, -15, 30, 16, 28]   k=3
        0   1   2  3   4   5    6   7
 
 Dry Run:
 i    n  k  condition1 found   j   i+k condition2  condition3    true/false      ans[]
 0    8  3   8-3=5     false   0    3    0<3       arr[0]<0        12<0 (f)        []
 0    8  3   8-3=5     false   1    3    1<3       arr[1]<0        -1<0 (t)        [-1]  break lagte h inner loop khtm

 1    8  3   8-3=5     false   1    4    0<3       arr[0]<0        -1<0(t)        [-1 ,-1]  break lagte j inner loop khtm

 2    8  3   8-3=5     false   2    5    2<5       arr[2]<0         -7<0(t)       [-1,-1,-7]  break lagte j inner loop khtm

 3    8  3   8-3=5     false   3    6     3<6      arr[3]<0           (f)          [-1 ,-1,-7]
 3    8  3   8-3=5     false   4    6     4<6      arr[4]<0          -15<0(t)      [-1,-1,-7,-15]  break lagte j inner loop khtm

 4    8  3   8-3=5     false   4    7     4<7      arr[4]<0          -15<0(t)     [-1,-1,-7,-15,-15]  break lagte j inner loop khtm

 5    8  3   8-3=5     false    5   8     5<8       arr[5]<0            (f)
                                                    arr[6]<0            (f)
                                                    arr[7]<0            (f)
                   
                                                    0 store kro
      ans= [-1,-1,-7,-15,-15,0]


 class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
      vector<int> ans;
      int n=arr.size();
      
      for(int i=0;i<=n-k;i++){
          bool need=false;
          
          for(int j=i;j<i+k;j++){
              if(arr[j]<0){
                  ans.push_back(arr[j]);
                  need=true;
                  break;
              }
          }
          
          if(!need){
              ans.push_back(0);
          }
      }
      return ans;
        
    }
};


step4:Brute Force mein kya repeat ho rha hai

Har window mein hume left se right tak puuri window traverse kr rhe hai aur 
 negative number ko baar baar dhoondhna pad rha hai

Window1 = [-8, 2]
Window2 = [2, 3]
Window3 = [3, -6]
Window4 = [-6, 10]

Kaunsi information maintain kar sakte hain taaki dobara search na karna pade? Yahi optimization ka key point hai.

let suppose: 
 Window3:  
[3, -6]   -6 find kiya 

Window4:
[-6, 10]  -6 again find kiya


Negative numbers baar-baar scan ho rahe hain.

Important Observation: Hume puure window ke elements ya sum maintain nahi krna hai  
hume sirf ye maintain krna hai  --- (Current window ke negative elements)  --  (Sabse pehla negative)

Idea :  Jab naya element agar window mein aaye to ushe store kr lo
        Jab window se koi element bahar jaye -- Agar wahi first negative tha ushe remove kr do
        Jo sabse pehla negative bacha hoga Wahi answer hoga


[-8, -2, 3]  k=3  answer=-8

// window1:  [-8,-2,3]  negative elements  [-8,-2]  store kr lo queue mein  front -> [-8,-2] <- Back ->
// Answer  Front= -8  Kyunki first negative wahi hai.

// window slide: 
//    [-8,-2,3]   new window  [-2,3,-6] 
//    aab jo mera element bahar gaya hai vo mera queue ke front ke equal hai  :  Queue se bhi hata dhiya humne
//    [-2,3,-6]   front -> [-2] <- Back 

//    aur naya element negative aaya hai -6 ushe queue mein add kr do
//    [-2,3,-6]   front -> [-2,-6] <- Back 



step5: Pattern Analysed krna 

Hashmap nhi lagega 
Hume frequency count nahi karni.
Hume duplicate track nahi karna.

Two pointer approach
Window size hamesha k hai.
--Window ko bada nahi kar rahe
--Window ko chhota nahi kar rahe


Fixed Sliding Window kyu?

Har valid subarray ki size exactly k hai.

Aur har step par
1 element bahar
1 element andar

Ye Fixed Size Sliding Window ka classic signal hai.


aab isme question abhi bhi arrised hai ki hum negative number kaise maitain krenge

Jaie aap ek sadhi mein ho
EGG tray aayi hai starting se end tk line by line egg lage hume usme se defective vhle pehle nikalne hai
ye serial number likh rha hu

10 se 11 baje -  3 7 9 defective aaye hai
11 se 12 baje - 10 11 12 defective aaye hai 

yha hum kya maitain krenge

pehle 3 7 9 10 11 12 pehle 3 number vhla defective aaya  as so on

agar mai 11 se 12 baje slot pe hu 10 se 11 baje vhle slot ke egg hat gaye agar to hum 
10 number vhla defective tha

queue - first in first out 
jo order humne maintain kr diya ki 3 7 9 10 11 12  aur front se remove krte rahenge jo window se bahar ja rha hoga 

jo element bahar ja rha hai ur queue ke front mein hai to ushe pop kr denge
new element ko peeche se add kr denge


step6: Generic Template
1. Window mein agar naya element aaya 
2. agar vo negative hai
    queue mein push kr do
3. window size agar k se choti hai
    right ko aage badhao
4. jab window size k ke equal ho jaye
        Agar Queue empty hai:  Answer me 0 store karo
        warna : Answer me Queue.front() store karo
5.window ko slide karna hai
6.check kro 
   kya outgoing element queue.front() hai???
   agar haan pop kro
7. left ko aage badhao
8. right ko aage badhao
9. Repeat                   


step7:Dry Run-
arr = [-8, 2, 3, -6, 10]
        0  1  2   3   4
k = 2

queue=[] ans=[]  right=0 left=0

right=0

arr[0]=-8
negative hai - push in queue
window size:1
queue=[-8]  

right=1
arr[1]=2
window size:2==k

queue.front()=-8
ans=[-8]

window slide krni hai
queue.front() = arr[left] agar hai 
 to pop kro
 queue=[]  
 move left=1

 left=1
 right=2
 arr[2]=3
 negative nahi : queue = []
 window size:2
 ans.push_back(0)

 ans:[-8,0]

 window slide
queue empty hai -- kuch nhi krna
left=2
right=3

arr[3]=-6
negative hai -6 puch in queue
queue=[-6]

[3,-6]
windowsize=2
Queue.front() = -6

ans = [-8,0,-6]


slide
arr[left]=3 Queue.front():=-6
same nhi hai kuch touch nhi karenge

queue:[-6]  left=3
right=4
arr[right]=10
negative nahi
[-6,10]

Queue.front() = -6
ans = [-8,0,-6,-6]
















