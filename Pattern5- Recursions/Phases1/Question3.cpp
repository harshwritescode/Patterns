Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
Input: x = 2.00000, n = 10
Output: 1024.00000

step1:Question convert into your form
1.Hume do integer value dhi hai x aur n
2.Hume x ko n times repeat krke ek answer nikalna hai
3.jo answer aayega usko double datatype ke saath return krna padega


step2:Input dekho:-
 x = 2.00000, n = 10

 Naturally:-
  2*2*2*2*2......=1024.00000

Observation:-ab agar n ki value 0 ho gayi to hume 1 return krna hai 
iska mtlb ye hua hume isko ek baar bhi multiply nhi krna hai jo answer x hai vhi return kr do

   x=2.00000 , n=0
   return 2

step3:Brute Force socho:-
Loop ki thinking:-
1.ans=1
2.loop chla denge n times
3.ans*=x;

double myPow(double x, int n) {

    if(n==0)
        return 1;

    long long power = n;
    double ans = 1;

    if(power < 0){

        power = -power;

        for(int i=0;i<power;i++)
            ans /= x;
    }
    else{

        for(int i=0;i<power;i++)
            ans *= x;
    }

    return ans;
}
TC:-O(n)

step4:Recursion ki soch:-
1. Hum kya optimize kar rahe hain? :- Pow(x^n)
2. Hume rukna kab hai:-
    jbh n==1 return 1 kr do
3. Hum Problem kaise chota kr sakte hai:- 
   2^10= 2*2*2*2*2*2*2*2*2*2
    pow(2,10)=1024
      |
    pow(2,9)=512
      |
    pow(2,8)=256
      |
    pow(2,7)=108
      |
    pow(2,6)=64
      |
    pow(2,5)=32
      |
    pow(2,4)=16
      |
    pow(2,3) =8
      |
    pow(2,2) =4
      |
    pow(2,1) = 2
      |
    pow(2,0)  // yha jaise h n==0 hua humne 1 return kr diya
      
