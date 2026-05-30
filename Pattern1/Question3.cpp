Given an array arr[] consisting of only 0s, 1s, and 2s. 
The objective is to sort the array, i.e., put all 0s first, 
then all 1s and all 2s in last.


arr[] = [0, 1, 2, 0, 1, 2]  
output:  [0, 0, 1, 1, 2, 2]

Step1: Question convert into your language

array diya hai
array mein sirf teen element hai
0
1
2
mujhe arrange krna hai

0 0 0 0 0 0-----
1 1 1 1 1 1 ----
2 2 2 2 2 2-----

Saare 0 left mein  saare 1 middle mein saare  2 right mein

step2: Input dekho 
2
0
2
1
1
0

Sirf 3 values hain  0 1 2
hume rearrange krna hai sirf  

step3: Brute force
count kro 0 kitne hai??
count kro 1 kitne hai??
count kro 2 kitne hai??

[2,0,2,1,1,0]   0:2 1:2 2:2

aab refill kr do
[0,0,1,1,2,2]


Step4: Brute Force mein repeat kya ho raha hai?

1.pehle hum traverse karke count kr rhe hai
2.uske baad phir traverse kr rhe hai 

jisme hum 0 fill krte hai 
jisme hum 1 fill krte hai
jisme hum 2 fill krte hai 

Yaani array ko multiple baar process kar rahe ho.

Note:  Yaani 2 pointers kaafi nahi hain.

step5: pattern optimised karenge

hum teen zone bana lenge  0zone,1zone,2zone  
                           left  mid   high


left = next 0 ki position
mid= current element
high -next 2 ki position

Yehi Dutch National Flag Pattern hai.

step6:pattern analysed

Case 1:
arr[mid]==0  To 0 ko left region mein bhejo
swap(low,mid)
low++;
mid++

case2:
arr[mid]==1  Already middle mein rehna hai
mid++;

case3:
arr[mid]==2  to 2 ko right region mein bhejo
high--
Kyuki swap ke baad naya element aaya hai.



step7:Generic Template
1:low= 0
2:mid =0
3:high= n-1;

4: if(arr[mid]==0)
  then swap(arr(mid),arr(low))
  low++
  mid++

   if(arr[mid]==1)
   mid++

   if(arr[mid]==2){
    swap(arr[mid],arr[high])  right mein 2 aa gaya hai 
    high --

   }


   step8: Dry Run
   
   [2,0,2,1,1,0]

   Initially

   left=0
   mid=0
   high=5

   current : arr[mid]=2
             swap(arr[mid],arr[high])
             high--

             [0,0,2,1,1,2]
             low=0
             mid=0
             high=4

             arr[mid]=0
             swap(arr[low],arr[mid])
             low++
             mid++
             
             [0,0,2,1,1,2]                                                                                                                              
                l       h 
                m             
             low=1
             mid=1
             high=4

             arr[mid]==0
             swap(arr[low],arr[mid])
             low++
             mid++

             [0,0,2,1,1,2] 
                  l     h
                  m
             arr[mid]==2
             swap(arr[mid],arr[high])
             high--

             [0,0,2,1,1,2]
                  l   h
                  m
             arr[mid]==2
              swap(arr[mid],arr[high])
              high--

            [0,0,1,1,2,2]
                 l   h
                 m
            arr[mid]==1
            mid++

            [0,0,1,1,2,2]
                 l   h
                   m
            arr[mid]==1
            mid++

             [0,0,1,1,2,2]
                  l   h
                      m  
            While(mid <= high)
            
 class Solution {
  public:
    void sort012(vector<int>& arr) {
     int n=arr.size();
     
     int low=0;
     int mid=0;
     int high=n-1;
     
     while(mid<=high){
         if(arr[mid]==0){
             swap(arr[low],arr[mid]);
             low++;
             mid++;
         }
         else if(arr[mid]==1){
             mid++;
         }
         else{
             swap(arr[mid],arr[high]);
             high--;
         }
     }
        
    }
};           

