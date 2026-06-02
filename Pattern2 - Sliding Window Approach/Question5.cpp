Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
You may return the answer in any order.

s = "cbaebabacd", p = "abc"
     0123456789
output:[0,6]

Reason:- Index 0 -> "cba" => anagram of "abc"
         INdex 6 -> "bac" => anagram of "abc"

step1: Question convert into your language
1.string dhiya gaya hai hume vo bhi do string  s (main string)   p (pattern string)
2.Hume s ke andar aisi substrings (windows) dhundhni hain jo p ka anagram ho.
3.Window ka size hamesha p.length() ke equal rahega
4.Jab bhi koi window p ka anagram mile
   uska starting index answer mein store krna padega
5.Return me ek array/vector dena hai jisme saare valid starting indexes hon.

step2:Input dekho

s = "cbaebabacd", p = "abc"
     0123456789

Length of p=3
possible windows check krne hai
cba 
bae
aeb
eba
bab
bac
acd 

step3:Brute Force socho
1.Har position ke substring nikalo
2.aab check karo ki p ka anagram hai ki nahi
  cba-> sort -> abc
  bac -> sort -> abc  

  Match kr jayega

  bae -> sort => abe
  abc -> sort => abc
  No Match ✘

dekho question ye hona chiye tumra sort h kyu kiya hum frequency count store kr lete 

Anagram ka matlab kya hai???   

      Characters same hone chahiye
      Frequency bhi same honi chahiye
      Order same hona zaruri nahi hai

abc
cba
bac
cab   

 ye saare ke saare anagram hai 
 Reason:
 a = 1
 b = 1
 c = 1

 sab mein same frequency hai


Sort karke kya prove kar rahe hain?
cba -> sort -> abc
abc -> sort -> abc

Sort ke baad dono same aa gaye.
Matlab indirectly hum ye prove kar rahe hain ki:


a = 1
b = 1
c = 1

Dono strings me frequency same hai.
Frequency Count se bhi wahi kaam hoga

step4:Dry Run-
s = "cbaebabacd", p = "abc"
     0123456789

Length of p=3(n)

possible windows check krne hai
cba 
bae
aeb
eba
bab
bac
acd 


i    Window    sort(Window)    sort(p)    Match      ans
0    cba       abc             abc        ✔          [0]
1    bae       abe             abc        ✘          [0]
2    aeb       abe             abc        ✘          [0]
3    eba       abe             abc        ✘          [0]
4    bab       abb             abc        ✘          [0]
5    aba       aab             abc        ✘          [0]
6    bac       abc             abc        ✔          [0,6]
7    acd       acd             abc        ✘          [0,6]


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int n=p.size();
        int m=s.size();
        vector<int>ans;
        

         for(int i=0;i<=m-n;i++){
            string t="";

            for(int j=i;j<i+n;j++){
                t+=s[j];
            }

            sort(t.begin(),t.end());
            if(t==p){
              ans.push_back(i);
            }
         }
         return ans;

    }
};


step5: Brute Force me repeat kya ho raha hai?

cba -> sort -> abc
bae -> sort -> abe
aeb -> sort -> abe
eba -> sort -> abe
bab -> sort -> abb
aba -> sort -> aab
bac -> sort -> abc
acd -> sort -> acd

Observation :
1. first hume saari window nikalni pad rhi hai 
    -ishe hum kaise optimized kr sakte hai
    - dhyn se dekho agar 
       first window -- cba
      second window -- bae

      kya change hua isme ek naya elemnet add hua ur ek puurana element delete hua
      Sliding window lag jayega isme aab kun se lagega sliding window fixed size ki variable size
      
      answer hai fixed size

2. Sliding window mein hume maintain kya krna hai ??
    frequency 
    i mean jo p string hai uska record humne 
    store kr liya map ke andar 
    phir hum s string ko traverse krenge
    
    agar vo humre map ke andar jo jo element hai uski frequency ke equal hogya
    to uska starting index mtlb bahar vhle loop ka index store kr lenge aur aage move krenge

Optimized:
Fixed Size Sliding Window
+
Frequency Count (HashMap / Array)

step6:Generic Template
1. pattern ki frequency store kro
        p=abc
         a=1
         b=1
         c=1
   unordered_map<char,int> mp        or   vector<int> freq(26)
2. First Window ki frequency banao
s = "cbaebabacd", p = "abc"
     0123456789

  First Window="cba"
  frequency:
     a=1
     b=1
     c=1
     
3. compare karo
    window frequency == pattern frequency ??
       yes - starting index store kro
4. window slide kro
   ek character remove
   ek character add
   
   cba-> bae
   remove c add e

5.frequency update kro
  remove char ka count --
  add char ka count++
6. Dobara compare karo

  Window Frequency == Pattern Frequency ?
  answer me current starting index store karo
7. Jab tak string khatam na ho
 slide 
 update
 compare 
 store
  

step7: Dry Run

s = "cbaebabacd"
     0123456789

p = "abc"

Pattern Frequency 
a=1
b=1
c=1

k=3

First Window build karo
cba 
frequency
a=1
b=1
c=1

compare -- WindowFreq == PatternFreq
ans = [0]

slide window 1
bae

remove c
add e

 old frequency          new frequency
a=1                        a=1
b=1                        b=1
c=1                        e=1

compare kiya match nhi kiya
ans = [0]

slide window 2
aeb

remove b  add b
  
 old frequency          new frequency
a=1                        a=1
b=1                        b=1
e=1                        e=1

compare kiya match nhi kiya
ans = [0]

slide window 3

eba

 old frequency          new frequency
a=1                        a=1
b=1                        b=1
e=1                        e=1

remove a add a

compare kiya match nhi kiya
ans = [0]

slide window 4
bab

 old frequency          new frequency
a=1                        a=1
b=1                        b=2
e=1                        

remove e add b
compare kiya match nhi kiya
ans = [0]

slide window 5

aba

 old frequency          new frequency
a=1                        a=2
b=1                        b=1
e=1                        

remove b add a
compare kiya match nhi kiya
ans = [0]


slide window 6

bac

 old frequency          new frequency
a=1                        a=1
b=1                        b=1
e=1                        c=1

remove a add c

compare kiya match ho gaya
ans=[0,6]


slide window 7

acd

 old frequency          new frequency
a=1                        a=1
b=1                        c=1
e=1                        d=1

remove b add d

compare kiya match nhi hua
ans=[0,6]




class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int k=p.size();
        int n=s.size();
        vector<int> ans;

        unordered_map<char,int> pfreq;

        for(auto it:p){
           pfreq[it]++;
        }

        unordered_map<char,int> windowfreq;

        for(int i=0;i<k;i++){
            windowfreq[s[i]]++;   
        }

        if(windowfreq == pfreq){
            ans.push_back(0);
        }
    
        for(int i=k;i<n;i++){
             char removechar=s[i-k];
             char addchar=s[i];

             windowfreq[removechar]--;

             if(windowfreq[removechar]==0){
                windowfreq.erase(removechar);
             }

             windowfreq[addchar]++;


            if(windowfreq == pfreq){
                ans.push_back(i-k+1);
            }


        }

        return ans;
    }
};

1. Count return karna hota to?
2. First occurrence return karni hoti to?
3. Last occurrence return karni hoti to?
4. Input constraints badal jaati to?
5. Data structure replace kar sakte hain?