Given an integer array arr[] and a number k. Find the count of distinct elements in every window of size k in the array.
 arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
 Output:
    [3,4,4,3]

   First Window: [1,2,1,3]  3 distinct element
   second window: [2,1,3,4] 4 distinct element
   third window: [1,3,4,2]  4 distinct element
   fourth window: [3,4,2,3]  3 distinct element

   [3,4,4,3]


step1:Question convert into your form
1. hume ek integer array diya gaya hai to isme postive negative number dono ho sakte hai
2. hume fixed size window k tk traverse krna hai
3. ush current window mein jitne bhi distinct element hai uska count store krna hai
4. hume retun array vo bhi integer type ka krna hai 

step2:Input dekho

 arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
          0  1  2  3  4  5  6

Observation:
1.fixed size window hai
2.count maintain krna padega vo bhi distinct element ka

step3:Brute Force socho
 arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
          0  1  2  3  4  5  6

1.hum array ko traverse karenge left to right
2.hume pehli window jaise h milegi
  - usme hum distinct element check krenge
  - jo uska count hoga ushe store kr lenge
3. return kr denge array/vector ko

Window me Distinct Elements Find Karne ke Possible Approaches

Current Window:
[1,2,1,3]

1. Nested Loop Approach

   * Har element ke liye check karo ki kya wo current window me pehle aa chuka hai.
   * Agar pehli baar mila hai to distinct count badhao.
   * Time Complexity: O(k²)

2. set Approach

   * Current window ke sabhi elements set me insert kar do.
   * set duplicate values automatically remove kar deta hai.
   * Distinct Count = set.size()
   * Time Complexity per window: O(k log k)

3. unordered_set Approach

   * Current window ke sabhi elements unordered_set me insert karo.
   * Distinct Count = unordered_set.size()
   * Average Time Complexity per window: O(k)

4. Frequency Map Approach

   * Har element ki frequency maintain karo.
   * Agar kisi element ki frequency 0 se 1 hoti hai to distinct count badhao.
   * Agar frequency 1 se 0 hoti hai to distinct count ghatao.
   * Sliding Window ke saath use karne par efficient solution milta hai.


step4:Dry Run--
 arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
          0  1  2  3  4  5  6

 First iteration         
 i  n  condition1(i<=n-k)   j    condition2(j<i+k)   window
 0  7     0<=7              0           [0<4]          [1]
                            1           [1<4]          [1,2]
                            2           [2<4]          [1,2,1]
                            3           [3<4]          [1,2,1,3]
                            4           [4<4]f

                            inner loop se bahar aaye
                 outer loop mein ditinct elemnet find krna hai 
                 unordered_set<int> st;
                 for(auto it:window){
                    st.insert(it);
                 }      
                 ans.push_back(st.size());
                 ans=[3] 
 
class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        vector<int> ans;
        
        for(int i=0;i<=n-k;i++){
            
            vector<int> window;
            
            for(int j=i;j<i+k;j++){
                window.push_back(arr[j]);
            }
            
            unordered_set<int> st;
            for(auto it:window){
                st.insert(it);
            }
            
            ans.push_back(st.size());
        }
        
        return ans;
    }
};

step5:Pattern analysed krna

 arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
          0  1  2  3  4  5  6

 First iteration         
 i  n  condition1(i<=n-k)   j    condition2(j<i+k)   window
 0  7     0<=7              0           [0<4]          [1]
                            1           [1<4]          [1,2]
                            2           [2<4]          [1,2,1]
                            3           [3<4]          [1,2,1,3]
                            4           [4<4]f

                            inner loop se bahar aaye
                 outer loop mein ditinct elemnet find krna hai 
                 unordered_set<int> st;
                 for(auto it:window){
                    st.insert(it);
                 }      
                 ans.push_back(st.size());
                 ans=[3] 

Second Iteration 
 First iteration         
 i  n  condition1(i<=n-k)   j    condition2(j<i+k)   window
 1  7     1<=7              1           [1<4]          [2]
                            2           [2<4]          [2,1]
                            3           [3<4]          [2,1,3]
                            4           [4<4]          [2,1,3,4]
                            5           [5<4]f

                            inner loop se bahar aaye
                 outer loop mein ditinct elemnet find krna hai 
                 unordered_set<int> st;
                 for(auto it:window){
                    st.insert(it);
                 }      
                 ans.push_back(st.size());
                 ans=[3,4]
                 
1.Hum har index ke liye subrray vhla window nikal rhe hai
First Window:  [1,2,1,3]
Second Window: [2,1,3,4]

Reality mein 1 remove hua hai 4 add hua hai
ek element remove hua
ek element add hua

yha sliding window lag jayega easily way mein

2.hum window nikalne ke baad ushe set mein daal kr distinct element baar baar dinf kr rhe hai
    kya hum jo window hai usme frequency maintain kr le to easy ho jayega

    [1,2,1,3]
    first window 
      distinct element : 3

          {
        1:2
        2:1
        3:1
      }  

    [2,1,3,4]
    second window
      distinct element :4
      jo element bahar ja rha hai agar vo humre window mein already present hai to ushe remove kro count kam kro
      jo element add hua hai agar vo new element hai to iska count bada denge

      condition jiska map mein already data hoga ushe dubra insert nhi krenge

            {
        2:1
        1:1
        3:1
        4:1

      }

      Sliding window + Hashmap (conndition if( arr[index] iski value hum map mein check krnege ki agar present hai to aage skip kr denge agar nhi hai to add kr denge ))
      left se remove krenge  

       
 
step6:Generic Template
Build First Window

Store Answer

while(window slide kar sakti hai)

    Remove Left Element

    Agar freq 0 ho gayi
        distinct--

    Add Right Element

    Agar pehle freq 0 thi
        distinct++

    Answer Store



 class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        vector<int> ans;
        unordered_map<int, int> freq;
        
        for(int i=0;i<k;i++){
            freq[arr[i]]++;
        }
        
        ans.push_back(freq.size());
        
        for(int i=k;i<n;i++){
            freq[arr[i-k]]--;
            
            if (freq[arr[i - k]] == 0) {
                freq.erase(arr[i - k]);
            }
            
            freq[arr[i]]++;
            
            ans.push_back(freq.size());
            
        }
         return ans;
        
        // vector<int> ans;
        
        // for(int i=0;i<=n-k;i++){
            
        //     vector<int> window;
            
        //     for(int j=i;j<i+k;j++){
        //         window.push_back(arr[j]);
        //     }
            
        //     unordered_set<int> st;
        //     for(auto it:window){
        //         st.insert(it);
        //     }
            
        //     ans.push_back(st.size());
        // }
        
        // return ans;
    }
};   
                 