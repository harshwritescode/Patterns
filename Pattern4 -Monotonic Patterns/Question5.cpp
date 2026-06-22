Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

Input: arr = [3,1,2,4]
Output: 17

step1:Question convert into your form
1.hume ek integer array diya gaya hai
2.hume sum nikalna hai min(b)
3. b ka matlab ranges hai /subarray hai array ka
4.answer humra bhuat bada bhi ho sakta hai
5.answer hum return 10^9+7 ke saath kr denge

step2:Input dekho
Input: arr = [3,1,2,4]
              0 1 2 3

 Starting AT 0:-             

 At 0 index : [3]            =3 
 At 1 index:  [3,1]          =1
 At 2 index:  [3,1,2]        =1
 At 3 index:  [3,1,2,4]      =1

 starting at 1:-

 At 1 index:  [1]            =1
 At 2 index:  [1,2]          =1
 At 3 index:  [1,2,4]        =1

 Starting at 2:-

 At 2 index: [2]             =2
 At 3 index: [2,4]           =2

 Starting at 4:-

 At 4 index: [4]             =4

 Total sum=3+1+1+1+1+1+1+2+2+4=17

 Observation:-
 1.har subarray se mujhe minimum element niklna hai 
 2.ur humre sum mein add krte jana hai
 3.last mein ans return kr do modulus ke saath

 step3:-Brute force socho:-
 1. Har index se hum ek window generate krenge
 2. jo window generate hogi usme hum minimum element find out krenge
 3. ek running sum maintain krenge jisme vo minimum element vhla element add kr denge
 4. last mein sum return kr denge

 step4:Dry Run:-
 arr = [11,81,94,43,3]
        0   1  2 3  4
        n=5

 i   n    i<n    j   j<n    window[]                 minimum_element  sum+=minimum_element 
 0   5    0<5    0   0<5      [11]                           11           11
                 1   1<5      [11,81]                        11           22
                 2   2<5      [11,81,94]                     11           33
                 3   3<5      [11,81,94,43]                  11           44
                 4   4<5      [11,81,94,43,3]                03           47

                 inner loop closed  sum=47
                 minimum_element=0

 1   5   1<5     1   1<5        [81]                          81           128
                 2    2<5       [81,94]                       81           209
                 3    3<5       [81,94,43]                    43           252
                 4    4<5       [81,94,43,3]                  03           255
                    
                  inner loop closed  sum=255
                  minimum_element=0
                  
 2   5   2<5     2   2<5       [94]                          94           349
                 3   3<5       [94,43]                       43           392
                 4   4<5       [94,43,3]                     03           395

                 inner loop closed  sum=395
                  minimum_element=0

 3   5   3<5     3   3<5        [43]                         43            438
                 4   4<5        [43,3]                       03            441

                 inner loop closed  sum=441
                  minimum_element=0

4    5   4<5     4   4<5        [3]                          03            444

                 inner loop closed  sum=444

                 outer loop closed sum=444 return


step5:Repeat Work Analysis:-
 [11,81,94,43,3]    =3
  0  1  2  3  4

  [81,94,43,3]      =3
    1  2  3 4

  1.hume har window mein minimum element maintain krna pad rha hai vo bhi har index se start krke 
  2.basically har index se start krke hume hrh window ka minimum element maintain krna pad rha hai
  3. [81,94,43,3]  minimum_element=3
      yha pe humre liye 91,94,43 useless ho gaye hai
      ur minimum_element useful ho gaya
  4. [11,81]
       0  1
       basically, humre liye hamesa jo answer dega vo sirf minimum element h dega 
       jab bhi bada element mihl jaye to hume ushe answer mein maitain krke kya milne vhla ushe maintain nhi krenge
        81 useless 
        11 useful hai
  5.isme sliding window isliye nhi laga pa rhe hai hume pta nhi chl rha window ko expand ur shrink kab krenge
    [11] = chlo ek element hai expand kr diya  minimuym_element =11 sum=0+11
    [11,81] = chlo ek element ur aaya humne ishe expand bhi kr diya minimum_element=11  sum=11+11=22
    yha window sirf expand ho rhi shrink to nhi ho rhi kisi bhi case mein

  6.43 humra kitne element ke liye minimum hai
    [11,81,94,43,3]    =3
      0  1  2  3  4
     pse          nse
[94,43]              [43,3]
[81,94,43]
[43]
 left approach        right approach

 arr[3]=arr[i]*i-pse*nse-i
       =43*3*1=129
       

        
Step 6: Pattern Analysis
1. Hume har subarray ka minimum nahi nikalna hai.

2. Hume har element ka contribution nikalna hai.

3. Question ban gaya:

   arr[i] kitni subarrays mein minimum hai?

4. Kisi element ke left aur right mein
   pehla smaller element uski boundary decide karega.

5. Agar koi bada element stack ke top par hai
   to future mein woh answer nahi de sakta.

   Isliye ushe pop kar denge.

6. Hume nearest smaller elements chahiye.

   Nearest Smaller Left (PSE)
   Nearest Smaller Right (NSE)

7. Nearest smaller find karne ke liye
   Monotonic Increasing Stack use kar sakte hain.


step7:-Dry Run:-
arr = [11,81,94,43,3]
       0  1  2  3  4
                                                                                            
       i=0                                                                                     i=4
       previous smaller element =-1                                                           nse[4]=5
       stack(0)                                                                               stack(4)

       i=1                                                                                     i=3
       11<81                                                                                   3<43 
       pse[1]=0                                                                                nse[3]=4
       stack(0,1)                                                                              stack(4,3)

       i=2                                                                                     i=2
       81<94                                                                                   94<43
       pse[2]=1                                                                                nse[2]=3
       stack(0,1,2)                                                                            stack(4,3,2)

       i=3                                                                                     i=1
       94<43 (false)                                                                           94>81 pop
       pop                                                                                     stack(4,3)
       stack(0,1)                                                                              43<81
       81<43 (false)                                                                           stack(4,3,1)
       pop
       stack(0)
       11<43
       stack(0,3)
                                                                                              i=0
                                                                                              81>11 pop
                                                                                              stack(4,3)
                                                                                              43>11 pop
                                                                                              stack(4)
                                                                                              nse[0]=4
                                                                                              stack(4,0)

       i=4
       43>=3
       pop
       stack(0)
       11>=3 pop
       stack()
       stack empty
       stack(4)
       PSE = [-1,0,1,0,-1]                                                                    NSE = [4,3,3,4,5]

left  = i - PSE
right = NSE - i

Contribution =
arr[i] * left * right



class Solution {
public:
    vector<int> getpse(vector<int> &arr){
        int n=arr.size();
        vector<int> pse(n);
        stack<int> st;

        for(int i=0;i<n;i++){
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

    vector<int> getNSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;

    for(int i = n - 1; i >= 0; i--) {

        while(!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }

        if(st.empty()) {
            nse[i] = n;
        } else {
            nse[i] = st.top();
        }

        st.push(i);
    }

    return nse;
}

    int sumSubarrayMins(vector<int>& arr) {
        const int MOD=1e9+7;
        int n=arr.size();
        long long ans=0;
        vector<int> pse = getpse(arr);
        vector<int> nse = getNSE(arr);
        for(int i=0;i<n;i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;

            long long contribution =
    (1LL * arr[i] * left * right) % MOD;
             ans = (ans + contribution) % MOD;
        }
        return ans;
    }
};





  
 