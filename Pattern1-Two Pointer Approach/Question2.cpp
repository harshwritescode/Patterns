Given an array arr[] consisting of only 0's and 1's.

Modify the array in-place to segregate 0s onto the left side
and 1s onto the right side.

arr = [0,1,0,1,1,0]   
output :  [0,0,0,1,1,1]

Step1: Question convert into your language 

Array mein 2 types ke element hai
0 
1

mujhe saare 0 left side mein rakhne hai
mujhe saare 1 right side mein rakhne hai

Array ko modify krna hai new array nhi bana sakte hai ish code mein 

Step2: Input dekho
0
1
0
1
1
0

Observe : 0 1 (sirf do values hai)
Question humse count nahi mang rha hai??
Question humse return  nahi mang rha hai??
Question humse index nahi mang rha hai??

Question humse sirf rearrangement  mang rha hai??

Step3: Brute Force socho

pehle count karo
kitne 0 hai humre pass array mein = 3
[0,1,0,1,1,0]  0 = 3

First 3 positions pe 0 bhar do  
Remaining positions pe 1 bhar do


step4: Pattern Analysed

hume left side pe kya chiye : 0
hume right side pe 1 chiye : 1

matlab :  left side verify karni hai 
          right side verify karni hai

Agar left pe 1 ur right pe 0 mihl gaya 

to ye dono galat psotion pe hai 
swap kar do 
pattern yahi hai

step5: Question ko ur todh sakte hai 

Two Pointer Rakenge 
Hum do pointer rakenge 

Initially

left =0;
right=n-1;

case1:  arr[left]==0  already correct left ++
case2: arr[right]==1  already correct right --
case3: arr[right]=0 && arr[left]=1  wrong 
 swap(arr[left],arr[right])


Pattern Analysed hua mujhe

Left se correct value dhundo
Right se correct value dhundo
Galat mil jaye
Swap kar do

Note:  Ye hi Two Pointer ka actual pattern hai



Step6: Generic Template
1.left pointer rakho
2.right pointer rakho
3.left correct ho left++
4.right correct ho right--
5. agar dono galat ho swap kr do
6. repeat tab tk hoga jbh tk left < right se peeche hai


Dry Run:

arr = [1,0,1,0,1,0]

left=0
right=5

[1,0,1,0,1,0]       arr[left]=1 arr[right]=0  swap  wrong position
 L         R

 [0,0,1,0,1,1]       left++ right--
 [0,0,1,0,1,1]       arr[left]=1 arr[right]=0  swap  wrong position
      L R

 [0,0,0,1,1,1]




class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
     int n=arr.size();
     int left=0;
     int right=n-1;
     
     while(left<right){
         if(arr[left]==0){
             left++;
         }
         else if(arr[right]==1){
             right--;
         }
         else{
             swap(arr[left],arr[right]);
             left++;
             right--;
         }
     }
        
    }
};

