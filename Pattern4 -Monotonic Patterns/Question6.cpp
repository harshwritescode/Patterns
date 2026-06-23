2104. Sum of Subarray Ranges
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
Return the sum of all subarray ranges of nums.
A subarray is a contiguous non-empty sequence of elements within an array.

Input: nums = [1,2,3]
Output: 4

step1:Question convert into your form
1.hume ek integer array diya hai
2.hume subarray niklna hai jisme ek condition dhi gayi hai 
3.ush subarray ka largest and smaller element ka difference nikalo
4.jo subarray ka ye condition nikalne ke baad answer aayega usko sum mein add krke 
5.hume sum return kr do
6.contigous ka matlab ek ke baad agla element ho aisa na ho beech mein 1 3 utha le 2 bhi beech mein hona jaruri hai

step2:Input dekho
nums = [1,2,3]
        0 1 2
     
        Possible subarray:-
        [1]  --  1-1=0
        [1,2] -- 2-1=1
        [1,2,3] -- 3-1=2

        [2] --  2-2=0
        [2,3] -- 3-2=1

        [3] -- 3-3=0

        sum=0+1+2+0+1+0=4

 Observation:-
 1. hum agar khud mein khud ko jodh kr sirf jiska size of window 1 h ho to usse humre answer pe affect nhi padega
 2. hum possible window nikal lenge 
 3.ush window mein minimum and maximum element nikal kr subtract kr lenge
 4.sum mein add krke return kr denge
 5.array sorted ya unsorted dono ho sakta hai
 5.ek ye observation aayi hai agar dono element window ke same ho ya saare element window ke same ho to bhi answer mein affect nhi krega

 step3:Brute Force:-
 1.Har index se nikal kr hum aage vhle index se last tk jakar ek window find out krenge
 2.minimum_element and maximum_element find out krenge har window mein
 3.har window ke andar inh dono amount ko subtract krenge
 4. sum mein add kr denge 
 5. return sum kr denge

 step4:Dry Run:-
 nums = [1,3,3]
         0 1 2
i  n    i<n    j   j<n    window[]     minimum_element      maximum_element     difference    sum+=difference
0  3    0<3    1   1<3     [1,3]             1                   3                  2             2
                   2<3     [1,3,3]           1                   3                  2             4

1  3    1<3    2   2<3     [3,3]             3                   3                  0             4
                   3<3

                   sum=4

 step5:Repeat Work Analysis && Pattern Analysyis:-
  1. Hum har window ke andar maximum,minimum element dhund rhe hai 
  2. [1,2,3,4,5,6]
      0 1 2 3 4 5
      
      let suppose tum index 4 pe kadhe ho,
      to hume kya chiye hume abhi tk ka sabse chota element ur abhi tk ka sabse bada element chiye
       0 -1 (minimum)
       1- 2
       2- 3
       3- 4
       4- 5 (maximum)

      [2,1,5,3,4]
       0 1 2 3 4 

       0-2
       1-1 (minimum)
       2-5 (maximum)
       3-3
       4-4

       hum window mein maximum ur minimum elemnet ko h maintain kr rhe hai 
       ur ek observation ye aayi hai hum sabse chota element ur sabse bada elment dhund rhe hai na ki first smaller and greater element
  3.    hume minimum_element ,maximum element dono maintain krne h padenge
  4.   [2,1,5,3,4]
        0 1 2 3 4

        [2,1] =1
         0 1
        [2,1,5] =1
         0 1 2
        [2 1 5 3] =1
         0 1 2 3
        [2 1 5 3 4] =1
         0 1 2 3 4 
         question ye hona chiye 1 kitno ka minimum_element hai ???
         jab tk usse chota element window mein na aa jaye
         
  5.     [2]  =2 minimum element
         [2,3] = abhi bhi 2 minium element hai
         [2,3,4] = abhi bhi 2 minimum element hai
         [2,3,4,1] = aab jaise h humre window mein 2 se chota element aa gaya to humeri condition ko ye rokh de rha hai
                       2>1
  6.     [2,1,5,3,4]
          0 1 2 3 4                          

          1 kitne element ka min hai
          [2,1]
          [2,1,5]
          [1,5]
          [1,5,3]
          [1,5,3,4]
          [2,1,5,3,4]
          [2,1,5,3]
          [1]       
          
          to basically hum left mein pehla smaller kha hai  hum right mein pehla smaller kahan hai   

          [2,1,5,3,4]                                                              [2,1,5,3,4]
           0 1 2 3 4                                                                0 1 2 3 4
 
           [-1,-1,1,1,3]                                                           [1,-1,3,-1,-1]

           stack:(0)                                                                stack:-(4)
           pse[0]=-1                                                                nse[4]=-1

           i=1                                                                      i=3
           1<2 true                                                                 3<4 true
           stack:() empty                                                           stack:() pop empty
           pse[1]=-1                                                                nse[3]=-1
           stack(1)                                                                 stack:(3)

           i=2                                                                      i=2
           5<1 false                                                                5<3 false
           pse[2]=1                                                                 nse[2]=3
           stack:-(1,2)                                                             stack:(3,2)
            
           i=3                                                                      i=1
           3<5 true                                                                 1<5 true 
           stack:-pop                                                               stack: pop
           stack:-(1)                                                               stack:-(3)
           3<1                                                                      1<3  true
           pse[3]=1                                                                 stack:pop
           stack(1,3)                                                               stack:() empty
                                                                                     nse[1]=-1
                                                                                     stack:(1)

                                                                                     i=0
           i=4                                                                       2<1 false  
                                                                                    nse[0]=1    
           4<3  false                                                                stack:-(1,0)
           pse[3]=3                                                                   
           stack:-(1,3,4)


           pse:-[-1,-1,1,1,3]                                                        nse:-[1,-1,3,-1,-1]


  7.   [ 2 | 1 | 5 3 4 ]
        -1         5
         0   1   2 3 4   n=5
        left choices :- i-p =1-(-1)=2 ways
        right choices:- n-i =5-1=4 ways

        total 4*2= 8ways

8.Har element ke liye:
Ye kitne subarrays ka minimum hai?
minimum contribution
=
nums[i] * minimum frequency
9.Har element ke liye:
Ye kitne subarrays ka maximum hai?
maximum contribution
=
nums[i] * maximum frequency
10.answer = maxSum - minSum


class Solution {
public:
    vector<int> previoussmaller(vector<int>& nums){
        int n=nums.size();
        stack<int> st;
        vector<int> pse(n,-1);
        // st.push(-1);

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
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
   
   vector<int> previousGreater(vector<int>& nums){
    int n = nums.size();

    vector<int> pge(n);
    stack<int> st;

    for(int i=0;i<n;i++){

        while(!st.empty() && nums[st.top()] <= nums[i]){
            st.pop();
        }

        pge[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }

    return pge;
}

vector<int> nextGreater(vector<int>& nums){
    int n = nums.size();

    vector<int> nge(n);
    stack<int> st;

    for(int i=n-1;i>=0;i--){

        while(!st.empty() && nums[st.top()] < nums[i]){
            st.pop();
        }

        nge[i] = st.empty() ? n : st.top();

        st.push(i);
    }

    return nge;
}
        vector<int> nextsmaller(vector<int>& nums){
        int n=nums.size();
        stack<int> st;
        vector<int> nse(n,-1);
        // st.push(-1);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
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

    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> pse = previoussmaller(nums);
        vector<int> nse = nextsmaller(nums);

        vector<int> pge = previousGreater(nums);
        vector<int> nge = nextGreater(nums);

        long long minSum = 0;
        long long maxSum = 0;
        for(int i=0;i<n;i++){

            long long leftMin  = i - pse[i];
            long long rightMin = nse[i] - i;

            minSum += 1LL * nums[i] * leftMin * rightMin;

            long long leftMax  = i - pge[i];
            long long rightMax = nge[i] - i;

            maxSum += 1LL * nums[i] * leftMax * rightMax;
        }

        return maxSum - minSum;
    }
};