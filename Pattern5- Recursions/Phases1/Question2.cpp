Given an integer n, return the sum of the first n natural numbers.
Input:- n = 5
Output:- 15

step1:Question convert into your form
1.Hume ek integer n diya hua hai
2.Hume ek integer answer return krna hai
3.Hume 1 se n tak sabhi number ka sum nikalna hai

step2:Input dekho:-
n=5
Natural Number:-
1+2+3+4+5=15

step3:Brute Force Socho:-
Loop wali thinking:-
1.1 se n tk loop chalna hai
2.sum store krte jana hai

int sum=0;
for(int i=0;i<n;i++){
    sum+=i;
}

step4:Aab Recursion ki soch
1.Basically hum sum nikal rhe hai
2.Hume ye sochna chiye ki hum sum nikalte kaise hai ur ush problem ko hum kaise chota kr sakte hai
    1+2+3+4+5  hume ye cheej krni hai correct
    Hum n se ye kehte ki tum khud ko chor kr apne peeche vhle ka answer nikal kr le aao ur mere mein add kr dena
    1+2+3+4
    Hum n se phir kehte hai ki tum mujhe chor ke apne peeche vhle ka answer nikal kr le aao ur mere mein add kr dena
    1+2+3
     Hum n se phir kehte hai ki tum mujhe chor ke apne peeche vhle ka answer nikal kr le aao ur mere mein add kr dena
    1+2
     Hum n se phir kehte hai ki tum mujhe chor ke apne peeche vhle ka answer nikal kr le aao ur mere mein add kr dena
    1
3.Matlab hum recursive call tab rok rhe hai jab hume ek single element mihl rha hai ur vhi number return kr de rhe hai jo humre answer ko nikal kr layega
   sum(5)
     |
    sum(4)
      |
     sum(3)
       |
       sum(2)
         |
        sum(1) jaise h sum(1) ko call kr rha hai ye return ho jana chiye
 
step5:Recursion ki soch:-
1.Hum kya optimized kr rhe hai :- sum
2.Hum base case kya likh rhe hai : -  n==1 return 1;
3.Hum Problem ko kaise chota kr sakte hai: - (n-1)
4.Hum recursive call kitni kr rhe hai:-  (n-1) sirf ek 
5.Hum answer kaise build kr rhe hai:- sum ko add krke 

int sum(int n){
    if(n==1) return 1;

    return n+sum(n-1);
}
    