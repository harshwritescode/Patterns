A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and 
removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Input: s = "A man, a plan, a canal: Panama"
Output: true

step1:Question convert into your form
1.Humre pass ek string s dhi huyi hai 
2.Ish string mein Uppercase letter & Lowercase Letter dono h hai
3.Hume sabse pehle uppercase letter ko lowercase letter mein change krna hai
4.Jitne bhi non-alphanumeric character hai unhe bhi string se remove krna hai
5.Agar vo samne se bhi ur peeche se bhi same hai
6.To vo string palindrome hai humeri ur ushe return kr denge
7.Alphanumeric mein humre pass letters number sab ho sakte hai

step2:-Input dekho
s = "A man, a plan, a canal: Panama"

a man,a plan,a canal : panama

amanaplanacanalpanama  Normal String
Ishe reverse kiya:-

amanaplanacanalpanama  reverse string
dono same hai 
return true

step3:Brute Force socho
1.Hume apni string to sabse pehle lowercase letter mein convert krna hai
2.Saare alphanumeric character remove krne hai
3.jo string iske baad generate hogi 
4.uske baad ek new string bana lenge reverse krke 
5.new string kyu?? humre compare krna hais string se isliye
6. agar same hua to true otherwise false


step4:-Algorithm
1.Ek empty string temp banao.
2.Original string ko ek-ek character traverse karo.
3.Agar character alphanumeric hai:
4.Usko lowercase mein convert karo.
5.temp mein add kar do.
6.temp ki ek copy rev bana lo.
7.Recursive function ki help se rev ko reverse kar do.
8.Agar rev == temp
true return karo.
Warna
false return karo.


Step5: Recursion ki Soch
temp = "madam"
reverseString(temp,0,4)
reverseString(0,4)
        |
swap(m,m)
        |
reverseString(1,3)
        |
swap(a,a)
        |
reverseString(2,2)
        |
Base Case
if(i>=j)
    return s;


class Solution {
public:
    string reverseString(string &s,int i,int j){
        if(i>=j) {
            return s;
        }
        swap(s[i],s[j]);
        return reverseString(s,i+1,j-1);
    }

    bool isPalindrome(string s) {
       string temp="";

       for(char ch:s){
         if(isalnum(ch)){
            temp+=tolower(ch);
         }
       }
        string rev = temp;

        rev = reverseString(rev, 0, rev.size() - 1);

       if(rev==temp){
        return true;
       }
       else{
        return false;
       }
    }
};


