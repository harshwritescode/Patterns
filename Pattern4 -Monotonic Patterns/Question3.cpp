Given an array of integers temperatures represents the daily temperatures,
 return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
  If there is no future day for which this is possible,
   keep answer[i] == 0 instead.

    temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]

step1:Question convert into your form
1. ek hume integer array diya hai jiska naam temperatures hai
2. jo represent kr rha hai daily kya temperature hai
3. hume ek answer vector return krna hai
4. answer[i] represent kr rha hai ki aapko kitna wait krna padega warmer temperature ke liye
5. agar nhi mila to 0 return kr denge

step2:Input dekho:-
temperatures = [73,74,75,71,69,72,76,73]
                0   1  2  3  4  5  6  7
      0th day-73  
      1st day=74
      2nd day=75
      3rd day=71
      4th day=69
      5th day=72
      6th day=76  
      7th day=73
      
      let suppose tum index 0 pe ho uski current value hai =73
      aab tume iske aage check krna hai ur ye dekhna hai ish cuurent value se aage kitni dher baad tume bada element/warm element mihl rha
      uske baad h moihl gaya to 1
      0->1
      1->1
      2->4
      3->2
      4->1
      5->1
      6->0
      7->0

Observation:-
1.Hume count maintain krna padega/jo current element se bade hai ur vo kitni dher baad aa rhe hai
2. logically socho:-
    [75,71,69,72,76]
      2  3  4  5  6
      i           j
      ye kitni dher baad bada element mila hume kaise pta chla pehla jump dusra jump ur teesra jump
    j-i =4
    
    basically jab vo mere liye useful answerr nikal kr de rha hai tab mai ye count krna chtha hu

step3:Brute force socho
1. Hum har index se start krenge nested loop iske aage vhle index se lagna start kr denge
2. traverse left to right krenge
3. agar humre currentelement se bada element mihl jata hai to vo mera answer hoga ur ush nested loop ko brreak kr denge
4. ans mein store kr lenge
5. return ans kr deng

step4:Dry Run:-
temperatures = [73,74,75,71,69,72,76,73]
                0   1  2  3  4  5  6  7

i  n   i<n   j    j<n     arr[i]<arr[j]     count=j-i     ans[]                    
0  8   0<8   1    1<8       73<74              1          ans[1]               break;
1  8   1<8   2    2<8       74<75              1          ans[1,1]             break; 
2  8   2<8   3    3<8       75<71(false)
                  4<8       75<69(false)
                  5<8       75<72(false)
                  6<8       75<76(true)        4         ans[1,1,4]            break;

3  8   3<8  4     4<8      71<69(false)
                  5<8      71<72(true)         2         ans[1,1,4,2]          break;   
                  
4  8   4<8  5     5<8      69<72(true)         1         ans[1,1,4,2,1]        break; 
5  8   5<8  6     6<8      72<76(true)         1         ans[1,1,4,2,1,1]       break;
6  8   6<8  7     7<8      76<73(false)
                  8<8                                    ans[1,1,4,2,1,1,0]

7  8   7<8  8     8<8                                    ans[1,1,4,2,1,1,0]              
                  
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(temperatures[i]<temperatures[j]){
                    ans[i]=j-i;
                    break;
                }
            }
        }
        return ans;
    }
};

step5:Repeat Work Analysis-
temperatures = [73,74,75,71,69,72,76,73]
                0   1  2  3  4  5  6  7

1.Hum har inner loop ke liye baar baar bada element find out krke la rhe hai 
2. Basically,
    0 index se hum -> 1,2,3,4,5,6,7
    1 index se hum -> 2,3,4,5,6,7
    
    basically aage badte badte hum ek h cheej baar baar compare kr rhe hai 
3.    [75,71,69,72,76]
      2  3  4  5  6
      
      ye batao mujhe agar tum 2 index pe khade ho->
    tum aage kaise bad rhe ho agar chota element na mile mere current element se
    agar bada mihl jaye to ad kr de rhe answer mein 
    ish case mein:-

     useful sirf:- 76 hai
     baaki useless hai :- 71,69,72
4.Hum useful camdidate ko h maintain krte hai 
  baaki pop kr denge jo useless hai

step6:Pattern Analysis:-
1.Monotonic stack lag jayega
2. hum sirf jo element bade hai vhi answer maintain krna chthe hai
3.stack mein hum dirf index maintain krenge
4. useless candidate ko pop krenge
5. Monotonic stack lag jayega

step7:Dry Run:-

temperatures = [73,74,75,71,69,72,76,73]
                0   1  2  3  4  5  6  7

 stack:-[0]
 ans:-[]
 
 at i=1
  if(arr[i]>arr[st.top()]) 74>73
  ans(1-0)
  ans[1]
stack:[1]

at i=2
  if(arr[i]>arr[st.top()]) 75>74
  ans(2-1)
  ans[1,1]
 stack:[2] 

at i=3
 if(arr[i]>arr[st.top()]) 71>75false
  push
  stack:[2]
  ans[1,1]
 if(arr[i]>arr[st.top()]) 71>74false
  pop
  stack:[0,1]

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        stack<int> st;
        st.push(0);

        for(int i=1;i<n;i++){

            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                int index=st.top();
                st.pop();

                ans[index]=i-index;
            }


            st.push(i);
        }
      return ans;
    }
};

Jo index stack se pop hota hai, usi ka answer milta hai.