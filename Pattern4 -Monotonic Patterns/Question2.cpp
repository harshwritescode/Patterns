You are given an integer array arr[]. For every element in the array, determine its Previous Greater Element (PGE).
The Previous Greater Element (PGE) of an element x is the first element that appears to the left of x in the array and is strictly greater than x.
Note: If no such element exists, assign -1 as the PGE for that position.

arr[] = [10, 4, 2, 20, 40, 12, 30]
Output: [-1, 10, 4, -1, -1, 40, 40]

step1:Question convert into your form
1.hume ek integer array diya hai
2.hume har element jo array mein present hai uska previous gretaer element niklna hai
3.hume first greater element nikal kr dena hai 
4.agar koi bhi present na ho to -1 return krna hai
5.last meun vector/array retrn kr do

step2:Input dekho
arr[] = [10, 4, 2, 20, 40, 12, 30]
         0   1  2  3   4   5   6

Observations:-
1. agar hum index 0 se start krte hai to uske peeche koi element nhi hai to hume index 1 se start krna padega
2. [10,4]
    0  1
    
   -- hum 1 index se peeche dekenge ki greater element hai ki nhi arr[j] hamesa chota ho tab h hume arr[i] mein bada element milega
        4<10  hai to humra 10 ek answer ho jayega
3.[10,4,2]
   0  1 2  
   -- hum index 2 pe khade hai ur peeche dekh rhe hai ki previous greater element hai ki nhi
      
      2<4(true) to humra 4 bhi ek answer ho jayega

 step3:Brute force Analysis:
 1. Hum index 1 se start krenge ur uske peeche koi bada element find krenge
 2. agar mihl gaya piche/left side to ushe store krenge
 3. agar nhi mila to -1 store kr denge
 
 ans[0]=-1
 for(int i=1;i<n;i++){
    ans[i]=-1;

       for(int j=i;j>0;j--){
        if(arr[i]<arr[j-1]){
            ans[i]=arr[j];
            break;
        }
    }
    }
 return ans;


step4:Dry Run:-
arr[] = [10, 4, 2, 20, 40, 12, 30]
         0   1  2  3   4   5   6

ans[] = [-1 ,10,4, -1 ,-1,40,40 ]        
          0  1  2  3   4   5   6

 i   n    i<n    ans[i]=-1   j=i  j>=0    arr[i]<arr[j-1]   true/false   ans[i]=arr[j-1]    updated ans[] 
 1   7    1<7    ans[1]=-1    1   1>=0      4 <10             true       ans[1]=10             ans[-1,10]
                                  0>0          
 2   7    2<7    ans[2]=-1    2   2>=0      2<4               true       ans[2]=4              ans[-1,10,4]                    
 3   7    3<7    ans[3]=-1    3   3>=0      20<2              false
                                  2>=0      20<4              false
                                  1>=0      20<10             false                             
                                  agar kuch update nhi hua to hum automatic ans[3]=-1 fill kr chuke hai
class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {

        int n=arr.size();
        vector<int> ans(n);
        ans[0]=-1;
        
        for(int i=1;i<n;i++){
           ans[i]=-1;
           for(int j=i;j>0;j--){
               if(arr[i]<arr[j-1]){
                   ans[i]=arr[j-1];
                   break;
               }
           }
        }
        return ans;
    }
};

step5:-Repeat work analysis krna hai
1. mai jab kisi index pe kdha hu to hum ek loop laga kr uske peeche jakr element find kr rhe hai baar baar
2.[10, 4, 2, 20]
   0   1  2  3
   
   hum 3 index pe hai yha se hum left side dekenge ki jish index pe kdha hu usse bada element milega hume
   3 se 2 pe gaye  -- 20<2  nhi hai 
   3 se 1 pe gaye  -- 20<4  nhi hai
   3 se 0 pe gaye  -- 20<10 nhi hai
   jo mujhse chote element hai vo mere answer kabhi bhi nhi ho skate hai 

3. basically hum apne index se peeche bada element find kr rhe hai 
   [10, 4, 2]
    0   1  2
    
    jo element mujhse bade hai vo mere answer ho sakte hai
4. hume useful candidate banana hai ??
5. jo useful nhi hai ushe discard kr denge

step6:-Pattern Abalaysis:-

1. Monotonic stack lag jayega
2. kyuki  hume  previous next element niklna hai
3. jo candidate humre current index se chota hai vo useful candiate nhi hai
4. jo candidate humre current index se bada hai vo useful candiate  hai
5. isliye montonic stack kaam kr jayega

step7:Dry Run:-

arr[] = [10, 4, 2, 20, 40, 12, 30]
         0   1  2  3   4   5   6

stack:[10]
ans[-1,]

i=1
currentelement < st.top()
   4<10  true
   ans[i]=st.top() =10
   st.push(i)=4

 After Operation:  
stack:[10,4]
ans[-1,10]  
   
i=2
currentelement < st.top()
   2<4  true
   ans[i]=st.top() =4
   st.push(i)=2

 After Operation:  
stack:[10,4,2]
ans[-1,10,4]  

i=3
currentelement < st.top()
  ur ye cheej loop pe chlna 
 a)  20<2  false
   pop kro stack se 
 After Operation:  
stack:[10,4,]
ans[-1,10,4] 
 b)  20<4  false
   pop kro stack se 
 After Operation:  
stack:[10,]
ans[-1,10,4] 
 c)  20<10  false
   pop kro stack se 
 After Operation:  
stack:[]
ans[-1,10,4] 

if(st.empty()) ans[i]=-1
st.push(arr[i])//30

After Operation:-
stack:[30,]
ans[-1,10,4,-1] 
so onn.....

  
class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {

        int n=arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        st.push(arr[0]);
        
        for(int i=1;i<n;i++){
            
            while(!st.empty() && arr[i]>=st.top()){
                st.pop();
            }
            
            if(st.empty()){
                ans[i]=-1;
            }else{
                ans[i]=st.top();
            }
            

            st.push(arr[i]);
          
        }
        return ans;
    }
};




   