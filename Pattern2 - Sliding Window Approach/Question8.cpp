Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
 s = "abciiidef", k = 3

Substrings:

"abc" -> 1 vowel
"bci" -> 1 vowel
"cii" -> 2 vowels
"iii" -> 3 vowels
"iid" -> 2 vowels
"ide" -> 2 vowels
"def" -> 1 vowel

Answer = 3

step1:Question convert into your form
1.string diya hai aur integer value k dhiya hua hai
2.hume haar baar k size ki window mein traverse krte rehna hai
3.fixed size window hai
4.window nikalne  ke badd hume ush window mein kitna vowel hai vo check krna hai
5. ans mein store krna hai


step2:Input dekho
 s = "abciiidef", k = 3
      012345678
Substrings:

"abc" -> 1 vowel
"bci" -> 1 vowel
"cii" -> 2 vowels
"iii" -> 3 vowels
"iid" -> 2 vowels
"ide" -> 2 vowels
"def" -> 1 vowel

Answer = 3

Observation:
1.fixed window mein vowel dhundne hai (a,e,i,o,u)
2.count maintain krna padega
3.aisa bhi ho sakta hau puuri string mein vowel na mile to kya return krna hai ye likha nhi hai kuch
4.its means s string aise design kiya gaya hai ki usme minimum ek vowel to ho
5. minimum ans 1 to aayega
6.maximum count vhle vowel ka count return kr denge

step3:Brute Force
1.Har index ke liye hume substring window find krke laana hai
2. jo currenet substring/window aayegi usme hume vowel check krne hai 
3. vowel ka count hum store kr lenge 
4.har window mein jiske count mein sabse jada vowel ka count hoga vo return kr denge


step4:Dry Run-
 s = "abciiidef", k = 3
      012345678
Substrings:

"abc" -> 1 vowel
"bci" -> 1 vowel
"cii" -> 2 vowels
"iii" -> 3 vowels
"iid" -> 2 vowels
"ide" -> 2 vowels
"def" -> 1 vowel

i n condition(i<=n-k)  j   condition(j<i+k)  window   search(window,count)  
0 9    0<=6            0       0<3            "a"         "a"                        
                       1       1<3            "ab"        "ab"            
                       2       2<3            "abc"       "abc"
                       3       3<3(f)
 

                    inner loop close hua 
                    aab hum jo window aayi hai usme search krenge ki kitne vowels hai??
                    "abc"   cnt=1
                            maxcnt=1    

i n condition(i<=n-k)  j   condition(j<i+k)  window   search(window,count)  
1 9    1<=6            1       1<4            "b"         "b"                        
                       2       2<4            "bc"        "bc"            
                       3       3<4            "bci"       "bci"
                       4       4<4(f)
 

                    inner loop close hua 
                    aab hum jo window aayi hai usme search krenge ki kitne vowels hai??
                    "bci"   cnt=1
                            if(cnt>maxcnt)
                            maxcnt=cnt
                                   =1
                                   
i n condition(i<=n-k)  j   condition(j<i+k)  window   search(window,count)  
2 9    2<=6            2       2<5            "c"         "c"                        
                       3       3<5            "ci"        "c"            
                       4       4<5            "cii"       "cii"
                       5       5<5(f)
 

                    inner loop close hua 
                    aab hum jo window aayi hai usme search krenge ki kitne vowels hai??
                    "cci"   cnt=2
                            if(cnt>maxcnt)
                            maxcnt=cnt
                                   =2
aise krte krte hume answer mihl jayega..........
                        maxcnt=3

class Solution {
public:
    int countVowels(string &window)
{
    int cnt = 0;

    for(char ch : window)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u')
        {
            cnt++;
        }
    }

    return cnt;
}

    int maxVowels(string s, int k) {
        int n=s.size();
        int maxcnt=INT_MIN;


        for(int i=0;i<=n-k;i++){
           string window="";

           for(int j=i;j<i+k;j++){
                char ch=s[j];
                window+=ch;   
           }

           //aab search kro kitne vowel hai window mein
            int cnt=countVowels(window);

            maxcnt=max(maxcnt,cnt);
        }
        return maxcnt;
    }
};
                        

step5:Repeat work identify karo
 s = "abciiidef", k = 3
      012345678
Substrings:

"abc" -> 1 vowel
"bci" -> 1 vowel
"cii" -> 2 vowels
"iii" -> 3 vowels
"iid" -> 2 vowels
"ide" -> 2 vowels
"def" -> 1 vowel

1. Hum har baar poori substring/window bana rahe hain.

2. Hum har baar poori window me dobara vowel count kar rahe hain.

3. Reality me previous window se sirf ek character remove hota hai
   aur ek character add hota hai.

4. Isliye poori window scan karne ki zarurat nahi hai.

5. Sirf remove hone wale aur add hone wale character ko check karke
   vowel count update kar sakte hain.

6. Fixed size window hai.

Pattern:
Sliding Window + Running Count vowel


step6:Generic Template
1.First window ki information nikalo
   pehle k character traverse karo
   agar character vowel hai 
    count++

    "abc"
     count=1

2. answer intialize kro 
   maxcnt=count

3. Window slide karo
  Har slide mein:
     ek character bahar jayega
     ek character andar aayega
4. left character remove karo
     count--
5. right character add karo
    agar add hone vhla character vowel hai:
       count++
6.answer update karo
   maxcnt=max(maxcnt,count)
7. return maxcnt   

step7:Dry Run-
 s = "abciiidef", k = 3
      012345678
Substrings:

"abc" -> 1 vowel
"bci" -> 1 vowel
"cii" -> 2 vowels
"iii" -> 3 vowels
"iid" -> 2 vowels
"ide" -> 2 vowels
"def" -> 1 vowel

string window="";
int count=0;
for(int i=0;i<k;i++){
   char ch=s[i];
   window+=s[i];

           if(ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u')
           {
            count++;
           }
}

0 - "a" -  1
1 - "ab" - 1
2 - "abc" -1

int maxcnt=count;
maxcnt=1;

for(int i=k;i<n;i++){
    char temp=s[i-k];  //a
    
    // left++;
    if(temp == 'a' || temp == 'e' || temp == 'i' ||
           temp == 'o' || temp == 'u')
    {
        count--;
    }      
    
   char newChar = s[i];


        if(newChar == 'a' || newChar == 'e' || newChar == 'i' ||
           newChar == 'o' || newChar == 'u')
    {
        count++;
    }


     maxcnt=max(maxcnt,count);
}


class Solution {
public:
    int maxVowels(string s, int k) {
       int n=s.size();
       string window="";
       int count=0;

       for(int i=0;i<k;i++){
         char ch=s[i];
         window+=s[i];

         if(ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u')
           {
            count++;
           }
       } 

       int maxcount=count;

       for(int i=k;i<n;i++){
          char temp=s[i-k];

              if(temp == 'a' || temp == 'e' || temp == 'i' ||
           temp == 'o' || temp == 'u')
    {
        count--;
    }  

           char newChar=s[i];

                if(newChar == 'a' || newChar == 'e' || newChar == 'i' ||
           newChar == 'o' || newChar == 'u')
    {
        count++;
    }
   

        maxcount=max(maxcount,count);
       }

     return maxcount;
    }
};