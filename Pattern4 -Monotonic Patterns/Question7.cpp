Largest Rectangle in Histogram
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
 Input:-heights = [2,1,5,6,2,3]
 output:10

step1:Question convert into your form
1.hume ek integer array diya hai jo histogram ki height represent kr rha hai
2.har height ki jo width hai vo 1
3.hume maximum/largest area of rectangle find out krna hai ur return kr dena hai
4.hume return mein ans chiye jiska maximum rectangle ho

step2:Input dekho:-
heights = [2,1,5,6,2,3]
           0 1 2 3 4 5      
           
6|           █
5 |       █  █
4 |       █  █
3 |       █  █     █
2 | █     █  █  █  █
1 | █  █  █  █  █  █
   ------------------
    0  1  2  3  4  5

Hume isme area nikalna hai kaise nikalenge???

At index 0:-
iski height 2 hai
hum left mein tab tak jana hai jbh tk iski height >= currentheight na ho jaye
aise h same hume right mein jab tk jana hai jbh tak iski height >=5 currentheight se na ho jaye
Area=2*1=2

At index 1:-
left=2>=1
Aur left me aur kuch nahi hai.
To left side poori cover ho gayi.
right=5>=1
index 3:-6>=1
index 4:- 2>=1
index 5:- 3>=1
Sab bars ki height 1 se badi ya barabar hai.

width=right-left+1=5-0+1=6
area=6*1=6

At index 2:-
left:-1>=5 false not extend
right=6>=5 true extend 
index 4:- 2>=5 false not extend

width=right-left+1=3-2+1=2
area=2*currentheight[i]=2*5=10

At index=3:-
left:- 5>=6 not extend 
right:- 2>=6 not extend 
width=right-left+1=1
area=1*6=6

At index 4:-
left=6>=2 true extend
     5>=2 true extend 
     1>=2 not extend

     left=2

right:-3>=2 true
right=5

width=5-2+1=4
area=4*2=8


At index 5:-
left:-2>=5 not extend
right: not extend

width=5-5+2=1
area=1*3=3

max(2,6,10,6,8)=10

step3:Brute force socho:-
1. Hum outer loop ko 0 se n ki taraf chla lenge
2. do while loop chlenge
   -- jo mujhe left mein kitna extend ho sakta hai
   -- jo mujhe right mein kitna extend ho sakta hai 
3. vo index lekr aayenge
4. then width calculate krenge area niakl lenge
5. jo maximum area hoga vo return kr denge


step4:Dry Run:-
heights = [6,2,5,4,5,1,6]
           0 1 2 3 4 5 6

 i    n    i<n    maxi=INT_MIN       left=i         left(>=0 && height[left]>=heights[i])    true/false  left--   right=i  right(<n && height[right]>=heights[i])   true/false     left  right   width         heights[i]  area  maxi
 0    7    0<7      INT_MIN              0                   0>=0     6>=6                      true      -1         0        0<7 && 6>=6                             true         -1     1      1-(-1)=2-1=1     6         6     6
 1    7    1<7         6                 1                   2>=0     2>=2                      true       0         1        1<7  2>=2                               true         -1     4      4-(-1)-1=4       2         8     8                  
                                                             0>=0     6>=2                      true      -1                  2<7  5>=2                               true
                                                                                                                              3<7  4>=2                               true
                                                                                                                              4<7  5>=2                               true
                                                                                                                              5<7  1>=2                               false
continue so on...

step5:Repeat work analysis:-
1.Hum har index ke liye 2 kaam kr rhe hai
2. ek to left mein vo kitna extend ho sakta hai
   dusra right mein vo kitna extend ho sakta hai
3.   heights = [6,2,5,4,5,1,6]
                0 1 2 3 4 5 6

                let suppose tum index 5 pe kadhe ho 

                left mein  tum ye check kr rhe ho ye dekh ho kbh tk iska pichla element bada hai

                 | [6  2    5   4  5  1 ]
                     2nd part


   Basically, hum bade element ko maintain kr rhe hai    
   jaise h hume smaller element milta hai hum ush array ko divide kr dete hai
4. hum apne current height se jab tk pehla smaller element nhi mihl jata hai tab tk hum ishe left-- krte rehte hai
5. hum basically smaller element maintain kr rhe hai
6. useful candidate humre liye smaller element hai
   useless candidatehumre liye greater element hai

   [  2  1 5 6 2  3  ]
      0  1 2 3 4  5   
                  i

      hum index 5 pe hai 
       
      left mein kab tk hume smaller element nhi mihl rha ye check kro
      stack:(5)
      2>=3 2 chota hai humra 
      pop()
      stack:() empty
      stack:(4)

      humre liye 3 useless ho gaya ur 2 useful ho gaya
7. aise h same hum next smaller index bhi find krenge'
8. width calculate krenge
9. area of rectangle nikal lenhge
10. ans return kr denge


step6:Pattern Analysis:-
1.Monotonic Stack lag jayega
2.hume smaller element maintain krna hai
  jo mere liye useful candidate bana denge
3.humre liye bade element maintain krne ki need nhi hai
 jo mere liye useless candidate ban rhe hai
4. stack use kre ye queue aab ye sawal aaya 
   hume sirf smaller element h maintain krna hai ur bade element ko pop krna hai
    stack:(2,3,4)
     let suppose humre pass 1 aaya 
     to automatic mujhe maximum element to top mein mihl jayega
     jo hum easily remove kr sakte hai
    
     stack best option hai

step7: Dry Run:-
 heights = [2,1,5,6,2,3]
            0 1 2 3 4 5      
            
            [-1,-1,1,5,1,4]
     left extension:-                                                                                            rightextension:-
      At index 0                                                                                                   i = 5 (height = 3)
      leftextension[0]=-1                                                                                          right[5] = 6;   // n
      stack:-(0)                                                                                                   stack:(5)
      
      At index 1:-                                                                                                i = 4 (height = 2)
       currentelement=1                                                                                           3 >= 2  pop
       heights[st.top()]>=currentelement                                                                          Stack empty.
            2>=1  pop kro                                                                                         right[4]=6
       stack:-() empty                                                                                            stack:(4)
       stack:-(1)
       leftextension[1]=-1 

     At index 2:-                                                                                                  i = 3 (height = 6)
      currentelement:-5                                                                                            2 >= 6
     heights[st.top()]>=currentelement                                                                             right[3] = 4;
       1>=5  false                                                                                                 stcak:(4,3)
      leftextension[2]=1 
       stack(1,2)

     At index 3:-  
     currentelement:- 6
     heights[st.top()]>=currentelement
     5>=6  false
     leftextension[3]=2
     stack(1,2,3)

     At index 4:-
     currentelement=2
      heights[st.top()]>=currentelement
      6>=2  pop
      stack:(1,2)
      5>=2  pop
      stack:(1)
      1>=2  false
      leftextension[4]=1
      stack:(1,4)
     
      At index 5:-
      currentelement=3
      heights[st.top()]>=currentelement
      2>=3 
      leftextension[5]=4
      stack:- (1,4,5)

      leftextension:- [-1,-1,1,2,1,4]
      rightextension:- [1,6,4,4,6,6]
       

       heights = [2,1,5,6,2,3]
                  0 1 2 3 4 5    


                  at index 2:-
                   width=4-1-1=2
                   area=width*height=2*5=10

Yahi arrays monotonic stack ka final goal hain. PSE aur NSE mil gaye to har index ka rectangle O(1) me nikal jaata hai.
   
class Solution {
public:
    vector<int> leftextension(vector<int> &arr){
        int n=arr.size();
        stack<int> st;
        vector<int> pse(n,-1);
        st.push(0);

        for(int i=1;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
            }else{
                pse[i]=st.top();
            }
            st.push(i);
        }
        return pse;
    }

        vector<int> rightextension(vector<int> &arr){
        int n=arr.size();
        stack<int> st;
        vector<int> nse(n);
        st.push(n-1);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }else{
                nse[i]=st.top();
            }
            st.push(i);
        }
        return nse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxi_area=INT_MIN;
        vector<int> left=leftextension(heights);
         vector<int> right=rightextension(heights);

         for(int i=0;i<n;i++){
           int width=right[i]-left[i]-1;
           int area=width*heights[i];
           maxi_area=max(maxi_area,area);
         }
        return maxi_area;
    }
};

