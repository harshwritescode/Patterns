Given two strings s and t of lengths m and n respectively,
 return the minimum window substring of s such that every character in t (including duplicates) is included in the window.
 If there is no such substring, return the empty string "".

 s = "ADOBECODEBANC", t = "ABC"
 Output="BANC"

 step1:Question convert into your form
 1. Humre pass 2 string hai s (main string) t( pattern string)
 2. minimum window substring return krna hai jisme t ke saare character aa jaye
 3. duplicates allowed hai humre pass
    "BBANC"
    "BANC"
     isse ek observation mujhe smjh aayi agar t.length() let suppose 3 aaya to usse minimal length to ho h nhi sakti
     nhi hua retun "" kr denge
 4. variable size window hai
 5.character ki frequency bhi matter krti hai

 step2:Input dekho

      s = ADOBECODEBANC    t=ABC
          01234567891011

 sabse pehle possible windows kya kya hogi
 ADOBEC    -   6
 DOBECCODEBA -  11
 OBECODEBA -  9
 BECODEBA - 8
 ECODEBA -  7
 CODEBA - 6
 ODEBANC - 7
 DEBANC - 6
 EBANC - 5
 BANC - 4

 Hume minimal length vhle ki substring return krni hai "BANC"

 Observation:
1. window size fixed nahi hai
2. order matter nhi krta
3. extra character allowed hai
4. character ki frequency matter karti hai
 t = AABC

toh humeri window mein 
'
A = 2
B = 1
C = 1
'
ye hona chiye
5.minimum window lekr return krni hai

step3:Brute force socho
1.Mai har possible substring generate krunga
2.aab har subtring ke liye check krunga
   kya isme pattern (t) ke saare character present hai
3.mihl gaya to answer calculate krunga

step4:Dry Run-

s = A D O B E C O D E B  A  N  C
    0 1 2 3 4 5 6 7 8 9 10 11 12
t = ABC

start=0
substring:
A
AD
ADO
ADOB
ADOBE
ADOBEC

check A B C present
valid window length=6
store minlen==6
    ans="ADOBEC"

Start = 1    
D
DO
DOB
DOBE
DOBEC
DOBECO
DOBECOD
...
DOBECODEBA

check A B C present
valid window length=11
compare minlen <len  false
store minlen==6
    ans="ADOBEC"

Start = 2 
O
OB
OBE
OBEC
...
OBECODEBA  

check A B C present
valid window length=9
compare minlen <len  false
store minlen==6
    ans="ADOBEC"

    Continue...
BANC



class Solution {
public:
    bool isvalid(string window,string t){
        unordered_map<char,int> freqwindow;

        for(auto it:window){
            freqwindow[it]++;
        }

        for(auto ch:t){
            if(freqwindow[ch]<=0){
                return false;
            }

            freqwindow[ch]--;
        }
        return true;

    }
    string minWindow(string s, string t) {
        int n=s.size();
        string ans="";
        int minlength=INT_MAX;

        for(int start=0;start<n;start++){

            for(int end=start;end<n;end++){
                string window=s.substr(start,end-start+1);

                if(isvalid(window,t)){
                    int length=end-start+1;

                    if(length < minlength){
                        minlength=length;
                        ans=window;
                    }
                }
            }
        }
                  return ans;
    }
};


steop4: Brute Force mein repeat kya ho rha hai

start = 0

start = 0

A
AD
ADO
ADOB
ADOBE
ADOBEC
ADOBECO
ADOBECOD
...

start = 1

D
DO
DOB
DOBE
DOBEC
DOBECO
DOBECOD
...

Observation:
1.Har baar nayi substring bana rhe hai
Example: ADOBEC ---  DOBEC
Kitna data same hai?   DOBEC
Bas: A remove hua

2.Har baar frequency dobbara calculate kr rhe hai

 ADOBEC
A=1
D=1
O=1
B=1
E=1
C=1    

DOBEC
D=1
O=1
B=1
E=1
C=1 
Ke liye fir se poora map bana rahe hain.
Reality mein bas A remove hua hai

3.Window mein haar baar sirf 2 cheej change ho rhi hai
ADOBEC ---  DOBEC

kya hua -- A REMOVE ADD O

Window ko dobara build karne ki zarurat nahi.
Left character remove
Right character add

4.Hum substring banane ke liye

s.substr(...)
use kr rhe hai 
ye bhuat expensive hai 

actually hume left right hi maintain krne hai

5.Hume poori string nahi chahiye.
  Hume sirf ye pata karna hai:
       Current window valid hai ya nahi?
       Kya current window me
       A,B,C present hain?


Window = [left .... right]

right ko move karenge expand krne ke liye
jab tak valid window nhi mihl jaati 
valid mihl jaye to left++ 
karke window ko chota krenge
Kyuki:
minimum length
dhundhni hai.

Step 5: Pattern identify karo

Har baar nayi substring bana rahe the
Har baar uski frequency dobara calculate kar rahe the

Fixed Size Sliding Window ❌

Variable Size Sliding Window ✔
1. Variable Size Sliding Window lagega

2. Pattern ki frequency store karenge
   (patternFreq)

3. Current window ki frequency store karenge
   (windowFreq)

4. left aur right pointer se window maintain karenge

5. right se expand karenge

6. Valid window milte hi left se shrink karenge

7. Har valid window par minimum length update karenge

8. Answer ke liye start index aur minimum length store karenge


step6:Dry Run

s = "ADOBECODEBANC"
t = "ABC"

Pattern Frequency
A = 1
B = 1
C = 1

patternFreq = {A:1, B:1, C:1}

left=0
right=0
windowfreq=[]
valid=0 (initially)
minlen=INT_MAX;
ans=""

Step-by-step Sliding Window
Right = 0 → 'A'    window = A    A count match ✔   windowfreq=[ A=1  ]
Right = 1 → 'D'    window = A D  still invalid
Right = 2 → 'O'    window = A D O still invalid
Right = 3 → 'B'    window= A D O B   A ✔B ✔ C ❌  windowfreq=[ A=1  B=1 ]
Right = 4 → 'E'    window=A D O B E  still invalid
Right = 5 → 'C'    window=A D O B E C   A ✔B ✔C ✔  windowfreq=[ A=1  B=1  C=1]

VALID WINDOW FOUND   length = 6    minLen = 6 ans = "ADOBEC"


| right | char | windowFreq update     | formed | valid? | left move     | window         | minLen | ans    |
| ----- | ---- | --------------------- | ------ | ------ | ------------- | -------------- | ------ | ------ |
| 0     | A    | A=1                   | 1      | ❌      | -             | A              | INF    | ""     |
| 1     | D    | D=1                   | 1      | ❌      | -             | AD             | INF    | ""     |
| 2     | O    | O=1                   | 1      | ❌      | -             | ADO            | INF    | ""     |
| 3     | B    | B=1                   | 2      | ❌      | -             | ADOB           | INF    | ""     |
| 4     | E    | E=1                   | 2      | ❌      | -             | ADOBE          | INF    | ""     |
| 5     | C    | C=1                   | 3      | ✔      | shrink starts | ADOBEC         | 6      | ADOBEC |
| 5     | -    | A removed → A=0       | 2      | ❌      | stop shrink   | DOBEC          | 6      | ADOBEC |
| 6     | O    | O=2                   | 2      | ❌      | -             | DOBECO         | 6      | ADOBEC |
| 7     | D    | D=2                   | 2      | ❌      | -             | DOBECOD        | 6      | ADOBEC |
| 8     | E    | E=2                   | 2      | ❌      | -             | DOBECODE       | 6      | ADOBEC |
| 9     | B    | B=2                   | 2      | ❌      | -             | DOBECODEB      | 6      | ADOBEC |
| 10    | A    | A=1                   | 3      | ✔      | shrink starts | DOBECODEBA     | 6      | ADOBEC |
| 10    | -    | shrink reduces window | 3      | ✔      | shrink        | CODEBA         | 6      | ADOBEC |
| 10    | -    | more shrink           | 3      | ✔      | shrink        | ODEBANC → BANC | 4      | BANC   |
| 11    | N    | N=1                   | 3      | ✔      | shrink        | BANC           | 4      | BANC   |
| 12    | C    | C=2                   | 3      | ✔      | shrink        | BANC           | 4      | BANC   |




Step 7: Final Pattern + Interview Ready Template

Brute Force → Repeat work
Repeat work → Sliding Window idea
Sliding Window → Variable size + HashMap

Core Idea:
1. windowFreq (current window ka count)
2. needFreq (t ka count)
3. formed (kitne characters satisfy ho chuke hain)
4. left, right pointers


class Solution {
public:
    string minWindow(string s, string t) {
               unordered_map<char,int> need, window;

        for(auto it:t){
            need[it]++;
        }

        int left=0;
        int right=0;
        int minlength=INT_MAX;
        int startindex=0;
        int formed=0;
        int required=need.size();

        while(right<s.size()){
            char ch=s[right];

            window[ch]++;

            if(need.count(ch) && window[ch]==need[ch] ){
               formed++;
            }

            while(left<=right && formed==required){
                char temp=s[left];

                if(right-left+1<minlength){
                    minlength=right-left+1;
                    startindex=left;
                }

                window[temp]--;

                if(left<=right && window[temp]<need[temp]){
                    formed--;
                }

                left++;
            }
            right++;
        }
      return minlength == INT_MAX ? "" : s.substr(startindex, minlength); 
    }
};