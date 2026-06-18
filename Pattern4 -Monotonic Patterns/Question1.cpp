You are given an integer array arr[ ]. For every element in the array, your task is to determine its Next Smaller Element (NSE).
The Next Smaller Element (NSE) of an element x is the first element that appears to the right of x in the array 
and is strictly smaller than x.
If no such element exists, assign -1 as the NSE for that position.

arr[]=[4,8,5,2,25]
output:-[2, 5, 2, -1, -1]

step1:Question convert into your form
1. ek array diya hai hume
2. hume first next smaller element nikalna hai har index se start krke 
3. ek array/vector maitain krna hai
4. let supoose kisi index pe next smaller element na mila to -1 return kr dena hai
5. vector/array return kr denge

step2:Input dekho
arr[]=[4,8,5,2,25]
       0 1 2 3 4
 
       0 index se  first smaller element uske baad -> 3 index pe hai jiski value 2 hai
       1 index se  first smaller element uske baad -> 2 index pe hai jiski value 5 hai
       2 index se  first smaller element uske baad -> 3 index pe hai jiski value 2 hai
       3 index se  first smaller element uske baad -> kisi  bhi index pe nhi hai -1 
       4 index se  first smaller element uske baad -> kisi  bhi index pe nhi hai -1

       ans=[2,5,2,-1,-1]

Important Observation:-
1.array jo hai vo sorted nhi hai
2.agar hum first index pe khade hai to hume puura array last tk check krna padega
3. isse aacha hum last se h traverse krte huye chle to hum answer easily way mein maintain kr payenge
     
step3:Brute force socho
1. Har index ke liye right side mein hum smaller element find krenge
2. last index mein automatic -1 h fill kr denge
3. ans mein return kr denge 

for(int i=0;i<n;i++){
    ans[i]=-1;

    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[i]){
            ans[i]=arr[j];
            break;
        }
    }
    return ans;
}

step4:Dry Run:-
arr[]=[4,8,5,2,25]
       0 1 2 3  4
i  n    ans[]          j   arr[j]<arr[i]    ans[]
0  5   ans[0]=-1       1      8<4(false)    
                       2      5<4 (false)
                       3      2<4 (true)    ans[0]=2
                       
1  5   ans[1]=-1       2      5<8(true)     ans[1]=5
2  5   ans[2]=-1       3      2<5(true)     ans[2]=2

3  5   ans[3]=-1       4      25<2(false)   
4  5   loop close 

ans=[2,5,2,-1,-1]


step5:Repeat work identify karo:-
1.Har index se start krke hum next smaller element nikal kr la rhe hai 
2.vo bhi baar baar
3.  4 ke liye next smaller element 2 hai
    5 ke liye next smaller element bhi vhi 2 hai
4. iska mtlb jo bhi aage aane vhle greater element hai vo useless ho gaye
5. [8,5,2]
    8 ke liye to 5 aa jayega
    5 ke liye 2 aa jayega
    
    its means 8 kabhi answer ho h nhi sakta humra 
    its means Hume aise candidates maintain karne chahiye
   jo future mein kisi ka Next Smaller ban sakte hain.

   jo candidate current element se bada ya equal hai,
   wo current element ke peeche useless ho jata hai.

Step6: Pattern Analysis

1. Monotonic Stack lag jayega.

2. Kyu?

   Hume Next Smaller Element nikalna hai.

3. Hum aise candidates maintain karna chahte hain
   jo future mein answer ban sakte hain.

4. Jo candidate current element se bada ya equal hai
   wo useless ho jata hai.

5. Isliye useless candidates ko pop kar denge.

6. Sirf useful candidates maintain karenge.

7. Hum increasing order maintain karna nahi chahte.

Hum useless elements pop karte hain.

Us pop condition ki wajah se
stack automatically increasing ban jata hai.

8. Isliye Monotonic Stack use hoga.

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n,-1);
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=st.top()){
                st.pop();
            }
            if(!st.empty()){
               ans[i]=st.top(); 
            }
            st.push(arr[i]);
        }
       return ans;
    }
};