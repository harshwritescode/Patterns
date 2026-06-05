You are given an array of integers nums,
 there is a sliding window of size k which is moving from the very left of the array to the very right. 
 You can only see the k numbers in the window. Each time the sliding window moves right by one position.

 Return the max sliding window.

 nums = [1,3,-1,-3,5,3,6,7], k = 3
 window1: [1,3,-1] --   3
 window2:  [3,-1,-3] -- 3
 window3: [-1,-3,5] --  5
 window4: [-3,5,3] --   5
 window5: [5,3,6]  -- 6
 window6: [3,6,7]  -- 7

 step1:Question convert into your language
 1.Array diya gaya hai hume positive, negative number diye hai array mein
 2.ek hume k diya hua hai 
 3.hume fixed size k ke corresponding window/continous create krni hai
 4.jo bhi valid window substring create hogi usme se  hume maximum number find krna hai
 5. ek array/vector answer create krna hoga
 6. jo maximum number aaya hai ushe store kr lenge
 7. return kr denge vector/array answer vhla

 step2:Input dekho

  nums = [1,3,-1,-3,5,3,6,7], k = 3
 window1: [1,3,-1] --   3
 window2:  [3,-1,-3] -- 3
 window3: [-1,-3,5] --  5
 window4: [-3,5,3] --   5
 window5: [5,3,6]  -- 6
 window6: [3,6,7]  -- 7


 Observation:
 1.Fixed size window hai haar baar traverse krne ke liye
 2.Hume window jo maitain krni hai usme hume maximum number maitain krna hai

 step3:Brute force socho
1.Har index se size k ki ek valid window/subarray nikalo.
2.Current window ke andar maximum element find karo.
3.Us maximum ko answer vector me store karo.
4.Saari windows ke liye repeat karo.


[1,3,-1]  -> 3
[3,-1,-3] -> 3
[-1,-3,5] -> 5
[-3,5,3]  -> 5
[5,3,6]   -> 6
[3,6,7]   -> 7

Maximum kaise nikalenge?
[1,3,-1]

maxElement = INT_MIN;

for(int j=i; j<i+k; j++)
{
    maxElement = max(maxElement, nums[j]);
}


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<=n-k;i++){
            vector<int> window;
            for(int j=i;j<i+k;j++){
              window.push_back(nums[j]);
            }

            int maxElement=INT_MIN;

        for(auto x : window)
{
    maxElement=max(maxElement,x);
}

            ans.push_back(maxElement);
        }
        return ans;
    }
};



step4:Repeat Work identify karo
1.Hum har index ke liye ek valid window nikal kr la rhe hai vo bhi baar baar
   First Window: [1,3,-1] 
   Second Window:  [3,-1,-3] 
   
    Reality mein dekhe hum  to ek element bahar ja rha hai ur ek andar aa rha hai
     1 element bahar gaya 
     -3 element andar aaya

     sliding window lag jayega

2. Dusra kaam hum har window ke liye maximum number nikal rhe hai
[1,3,-1]  -> 3
[3,-1,-3] -> 3
[-1,-3,5] -> 5
[-3,5,3]  -> 5
[5,3,6]   -> 6
[3,6,7]   -> 7  


Hum poori window ki jagah aisi information maintain karna chahte hain
jisse current maximum efficiently mil jaye.
maintain krne ke liye hume ek datastructure chiye hoga 
jo maximum number maintain kr paye vo bhi same order mein 

order kyu ?? kya pta hum window slide krke aage chle gaye ho ur hume abhi bhi puurni window ka maximum answer de rha ho

iske liye hum queue use kr sakte hai 

[1,3,-1]   Agar future mein mujhe maximum number h chiye  to kya 1 store krne se fadya hai kya 
  
   3 uske baad aaya
   aur 3>1 hai

   To 1 kabhi maximum ban sakta hai kya?

Window ban rhi hai
1
1,3

jab 3 aaya 1 useless ho gaya 3 > 1

1, 3, 5

agar mujhe sirf maximum candiate rakhne hai
5 aate hi 3 bhi useless aur 1 bhi useless

bacha sirf [5]

Hume aisa data structure chiye??
 -  back se chote element hata sake
 -  back se naya element add kr sake
 - front se puurane element hata sake

Queue
pop_front ✅
push_back ✅

pop_back ❌

Aur deque?
pop_front ✅
push_back ✅
pop_back ✅

Pattern : Slidind window+ deque

step5:Dry Run:
[1,3,-1]
agar maximum maintain karna hai 
1 
new element 3
new element -1

deque:[1]
deque mein maximum maitain krna hai 
3>1 pop krne ki condition
1 future mein kabhi bhi maximum nhi ban sakta hai
1 useless 
deque:[3]

-1>3 
deque:[3,-1]
Deque increasing order mein hai

Next Window:[3,-1,-3]
new element:-3
deque:[3,-1,-3]

Next Window:[-1,-3,5]
new element:5
5>-3
remove kro deque se
deque:[3,-1,-3]
deque:[3,-1]  remove
5>-1  remove kro deque se
deque:[3]  remove  5>3 remove kro deque se

deque:[5]
Deque me hum:
Front -> Largest
Back  -> Smallest

Monotonic Decreasing Deque


step6:Generic Template-
1.deque maintain karo
2.back se chote element hatao
3.current element add karo
4.window ke bahar vhle element ko front se hatao
4.front pe maximum milega
5.answer mein push karo
6.Har slide pe repeat krenge


deque mein store kya krenge ??
value ya index

Window slide hone par hume pata lagana hota hai
ki koi element current window ke bahar gaya ya nahi.

Value se ye nahi pata chalega.

Index se easily check kar sakte hain:

if(dq.front() <= i-k)
    pop_front();

 step7:Dry Run-
   nums = [1,3,-1,-3,5,3,6,7], k = 3  
           0 1  2  3 4 5 6 7
         
           int n=8
 First Window traverse krte hai
 int element=arr[0]=1

 i  i<k  nums[i] deque  condition(nums[deque.back()]<newelement)              deque se hum tab tak pop krenge jbh tk ye condition false na ho jaye
 0  0<3   1      [0]          first element ke liye check nhi krenge
 1  1<3   3      [0]             1<3 (true)                                          deque[]   jaise h empty ho jaye ish new elment ke index ko store kr lo  deque[1]
 2  2<3  -1      [1]             3<-1                             direct insert kr do   deque[1,2] 
 
 aab first window complete ho gayi
 deque:[1,2]
 maximum=nums[dq.front()]=3
 ans=[3]

 for(int i=k;i<n;i++){

 }
 Second window find krna hai aab
 i  i<k  nums[i]  deque  condition(nums[deque.back()]<newelement)              deque se hum tab tak pop krenge jbh tk ye condition false na ho jaye
 3   3<8  -3      [1,2]        -1<-3                               deque insert kr do deque[1,2,3]
 remove from the left also
   [3,-1,-3]
indices:
    1  2   3

    window se bahar kun gaya index 0
    deque front kya hai  dq.front()=1
    Kya front index window ke bahar hai?
      dq.front() <= i-k
        1<=0  false to kuch remove nhi hoga
ans=[3,3]

third window find krna hai aab
i  i<k  nums[i]  deque  condition(nums[deque.back()]<newelement)              deque se hum tab tak pop krenge jbh tk ye condition false na ho jaye
4   4<8   5     [1,2,3]     -3<5(true)                                         pop_back()
                                                                                deque[1,2]  -1<5(true)  pop_back()  deque[1]  pop_back()   deque()  deque(4)
                                                                                 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        deque<int> dq;

        for(int i=0;i<k;i++){

            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
             dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        for(int i=k;i<n;i++){
         
            while(!dq.empty() &&  dq.front()<=i-k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }


            // Insert current index
            dq.push_back(i);


            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
















