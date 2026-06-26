Given an integer array nums and an integer k, 
return an array containing the minimum element of every contiguous subarray of size k.

Input:
nums = [4, 2, 12, 3, 5, 1, 6, 8]
k = 3
Output:
[2, 2, 3, 1, 1, 1]

step1:Question convert into your form
1.hume ek integer array diya hua hai ur fixed size k diya hua hai integer value vo bhi
2.hume har ek window mein minimum element nikal kr dena hai
3.ur jo bhi valid window hogi usme se jo minimum element hoga ushe hum ek array/vector mein daal kr return kr denge

step2:Input dekho:-
nums = [4, 2, 12, 3, 5, 1, 6, 8]  k=3
        0  1   2  3  4  5  6  7

 First Window:- [ 4,2,12]   =2
 Second Window:- [2,12,3]   =2
 Third Window:-  [12,3,5]   =3
 Fourth Window:- [3,5,1]    =1
 Fifth Window:-  [5,1,6]    =1
 Sixth Window:-  [1,6,8]    =1

 ans[2,2,3,1,1,1]
 Observation:-
 1.Hum har window mein sabse chota element ko answer bana rhe hai
 2.window hameri hamesa se fixed hai 


 step3:Brute Force socho
 1.Hum Har index se start krke ek window create krenge
 2.window create hone ke baad ek minimum element maintain krenge
 3.ans mein return kr denge

 step4:-Dry Run:-
 nums = [4, 2, 12, 3, 5, 1, 6, 8]  k=3
        0   1   2  3  4  5  6  7

   i    n      i<n     |   j    j<i+k      window[]   |  minimum_element   ans[]
   0    8      0<8         0    0<3         [4]             4
                           1    1<3         [4,2]           2
                           2    2<3         [4,2,12]        2
                           3    3<3(f)
                           Inner loop is complete 
                           ans[0]=[2]
                           and window restart again

   1    8      1<8         1    1<4          [2]            2
                           2    2<4          [2,12]         2
                           3    3<4          [2,12,3]       2
                           4    4<4(f)
                           Inner loop is complete 
                           ans[1]=2
                           and window restart again
                           
   2    8      2<8         2    2<5          [12]           12
                           3    3<5          [12,3]         03
                           4    4<5          [12,3,5]       03
                           5    5<5(f)
                           Inner loop is complete
                           ans[2]=03
                           and window restart again

   3    8       3<8        3    3<6           [03]          03
                           4    4<6           [3,5]         03
                           5    1<6           [3,5,1]       01
                           6    6<6(f)
                           Inner loop is complete
                           ans[3]=01
                           and window restart again   
                           
   4    8       4<8        4    4<7            [5]          5
                           5    5<7            [5,1]        1
                           6    6<7            [5,1,6]      1
                           Inner loop is complete
                           ans[4]=01
                           and window restart again  

   5    8       5<8        5    5<8            [1]          1
                           6    6<8            [1,6]        1
                           7    7<8            [1,6,8]      1
                           8    8<8(f)
                           Inner loop is complete
                           ans[5]=01
                           and window restart again    
                           
                           ans[2,2,3,1,1,1]

Observation:-
1.Hum har window ko create krne ki need h nhi hai hum minimum element compare krke bhi nikal sakte hai 
2.inner loop close hone ke baad hum minimum_element ko arr[i] kr de to automatic refresh ho jayega
3.ans return kr denge

code:-
vector<int> minimumwindow(vector<int> &arr,int k){
    int n=arr.size();
    vector<int> ans;
    for(int i=0;i<n-k;i++){
      int minimum_element=arr[i];
        for(int j=i;j<i+k;j++){
            minimum_element=min(minimum_element,arr[j]);
        }
        ans.push_back(minimum_element);
    }
    return ans;
}
         

step5:Repeat Work Analysis:-
1.Hum har ek valid window ke andar ek minimum_element baar baar dhund rhe hai
2. [3,5,1] 
    3 4 5

    agar ish subarray mein check kre to humre answer ke liye kya cheej useful hai
    minimum_element ya maximum_element ya saare element
    answer hai sirf minimum_element
    ish case mein mere liye useful candidate:-1
     useless candidate :- 3,5
3. hume ek kaam ye krna chiye hum ek aisa data structure alag se use kr le jisse hum minimum_element ko maintain kr paaye har window ke andar
4. ek cheej ur hai hum har window ko baar baar bana kr sacn kr rhe hai 
  First Window:-   [4,2,12]    -  2
                    0 1  2
  Second Window:-  [2,12,3]    -  2
                    1  2 3

     yaha pe hua kya hai internally ek element hat gaya hai ur ek element add ho gaya hai
      0 index vhla element remove hua hai window se kya jo element remove ho rha hai vo humra first window ka answer tha kya??
      3 vhla elemnet add hua hai kya vo jo element add hua hai vo h mera minimum_element to nhi hai
 
 step6:Pattern Analysis:-
 1. Hume ek datastructure chiye jo mere ish repeat work ko solve kr sake
 2. dekho hum jbh window ko slide krte hai tab hum starting mein ye check krna pad rha hai ki
     -- jo element bahar ja rha hai kya vo humre window se bahar to nhi ja rha agar ja rha hai to hume ushe pop bhi krna padega
     -- jo naya elemnet add ho rha hai kya vo ush window ka minimum_element hua to kya krenge hum  

     back se insert kr sake value ko 
     front se remove kr sake value ko
     ek main case ye hai agar element useless candidate hua i mean bada element hua to ushe bhi hum back se pop kr sake
     
     deque lag jayega ushi ke pass ye power hoti hai 
      

step7:Dry Run:-

 nums = [4, 2, 12, 3, 5, 1, 6, 8]  k=3                     ans[2,2,3,1,1,1]
         0  1   2  3  4  5  6  7
  
  deque:[]   
  
  At index 0:-
   deque:[4]
     index 1:-
      arr[i]<deque.back_front()
      2<4 true its means deque mein bada element hai ishe hum peeche se pop kr denge
      dq:[]
      aab ye naya element insert kr denge
      dq:[2]
      index 2:-
       12<2(f) aab ye ho sakta hai jo naya element aaya hai vo mera aage jakar kisi ke liye answer ban jaye
       deque mein push kr denge peeche se
       dq:[2,12]
 
   First Window is complete
     ans.push_back(dq.front());
     deque:[2,12]

   aab remaining window ke liye answer nikalenge  k se lekr end tk
     // aab ek element bahar ja rha hai
      arr[0]  = arr[i-k]=4
      ye jo elment bahar ja rha hai kya vo humre deque ke barabar hai kya agar hai to 
      deque se bhi pop kr denge
      4==2 no 
    
      //aab jo naya element window ke andar aaya hai
    arr[i]=3  kya ye element mere deque ke peeche se check kro kun chota hai
     arr[i]<deque.back_front()
      3<12 true its means deque mein bada element hai ishe hum peeche se pop kr denge
      deque:[2]
      3<2  false aab ye ho sakta hai jo naya element aaya hai vo mera aage jakar kisi ke liye answer ban jaye
       deque mein push kr denge peeche se
       dq:[2,3]



 step8:Code:-

vector<int> minimumwindow(vector<int> &arr,int k){

      int n=arr.size();
      vector<int> ans;
      deque<int> dq; // storing the indexes not value because we dont know when our indexes is silde
      dq.push_back(0);

      for(int i=1;i<k;i++){

          while(!dq.empty() && arr[i]<=arr[dq.back()]){
              dq.pop_back();  
          }
           
          dq.push_back(i);
      }

      ans.push_back(arr[dq.front()]);

      for(int i=k;i<n;i++){
         
     
        if(i-k == dq.front()){
            dq.pop_front();
        }

        int newelement=arr[i];
        //isme 2 case ban rhe hai 
          ya to jo naya element add ho rha hai vo mere peeche vhle element se bada hai

          while(!dq.empty() && arr[i]<=arr[dq.back()]){
              dq.pop_back();
          }

          dq.push_back(i);
          ans.push_back(arr[dq.front()]);

      }


   return ans;
}    


     

