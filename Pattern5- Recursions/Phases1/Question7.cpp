You are given a string s, and your task is to reverse the string.
Input: s = "for"
Output: "rof"

step1:Question convert into your form
1.Humre pass ek string s dhi gayi hai
2.Hume ish string ko reverse krna hai
3.jo string reverse hoke aayegi ushe h return kr dena hai

step2:-Input dekho
Input: s = "for"
            012
  0th index -- 2nd index (swap)
  1st index -- 1st index (swap)
  
            rof

step3:-Brute Force Socho:
1.Hum two pointer use kr lenge
2.First Pointer 0 index pe
  Second pointer Last index pe
3.swap krenge
4.First pointer ++
5.Second POinter --
6.ye hum jab apas mein ye dono pointer cross na ho jaye tab tk krenge

step4:-Code
class Solution {
  public:
    string reverseString(string& s) {
        
        int i=0;
        int j=s.size()-1;
        
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        
        return s;
    }
};

step5:Recursion ki soch
s="Harsh"
   01234
   i   j
    i j
    i/j
   f(s,i++,j--)
   f(s,i++,j--)
   f(s,i++,j--)

  Q1.Hum kya optimized krne ka try kr rhe hai - string s
  Q2.Hum rukna kab chthe hai --  i>=j
  Q3.Hum apne problem ko chota kaise kr rhe hai --  i++,j-- krke
  Q4.Hum pass kitne options hai call krne ke -- 1 option hai  reverse(s,i+1,j-1);
  Q5.Hum apna answer kaise maintain krenge -- ek saath reverse krke string return kr denge
  
  

class Solution {
  public:
    void reverse(string& s,int i,int j){
        if(i>=j){
            return ;
        }
        
        swap(s[i],s[j]);
        
        reverse(s,i+1,j-1);
        
    }
    string reverseString(string& s) {
       reverse(s,0,s.size()-1);
       return s;
    }
};



