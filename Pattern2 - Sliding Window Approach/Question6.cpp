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
2.aab har subtring ke liye check krunha
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