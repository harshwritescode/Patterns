Given an integer n, return the factorial of n.
Input:
n = 5

Output:
120

step1:Question convert into your form
1.hume ek integer n diya hua hai
2.hume ek answer integer type ka return krna hai
3. hume ush integer ka factorial find krke dena hai

step2:Input dekho:-
 n=5
 Output:120

 Factorial means:- 1*2*3*4*5=120

 step3:Brute force socho:-
 1. Loop ki trha se
    -- hum index 1 se start krke n tk jayenge
    -- ur ek answer naam ke variable mein multiply krte chle jayenge
 
    for(int i=1;i<=n;i++){
        ans*=i;
    }

  2. Lekin Recursion ki trha socho
    
      n=5 
      hum kr kya rhe hai 1 * 2 * 3 * 4 * | 5
      basically 5 mein iske peeche ko jo answer aaya hai ushe multiply kr rhe hai
      aab question keh rhe tum iska answer nikal laoge to tume mera answer bhi mihl jayega  5 ke liye 
       1 * 2 * 3 * |  4   -- isne bhi kha tum mere peeche vhle ka answer lekr aao
       1 * 2 * |  3  --   isne bhi kha tum mere peeche vhle ka answer lekr aao
       1 *  | 2   --   isne bhi kha tum mere peeche vhle ka answer lekr aao
       1  mein hum kuch bhi multiply krenge to 1 h aayega to isne 1 answer return kr diye jha se ye call hua


       1
       1*2=2  isne apna 2 return kr diya jha se isse call kiya gaya
       2*3=6  isne 6 return kr diya jha se isse call kiya gaya
       6*4=24 isne 24 return kr diya jha isse call kiya gaya
       24*5=120 ye yha aake ruk gaya kyuki isne sabse pehle call kiya
      
      1. mai kya optimized kr rha hu- product 
      2. base case kya hai - n==1 return ho jao
      3. hum problem ko chota kaise kr sakte hai - n-1 krke
      4- humre pass call krne ke kitne options hai - n-1 h pass kr do ur koi option nhi hai
      5- answer kaise generate krenge - ans*=fact(n-1)

      int factorial(int n){
          if(n==0 || n==1 ){
            return 1;
          }

          return n*factorial(n-1)
      }
    
      
  
 

