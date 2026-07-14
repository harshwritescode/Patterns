Given an array, arr[] of n integers, and an integer element x, find whether element x is present in the array.
 Return the index of the first occurrence of x in the array, or -1 if it doesn't exist
Input:-
arr[] = [1, 2, 3, 4], x = 3

step1:Question Convert into your form
1.Humre pass ek integer array diya gaya hai jiska size n bhi mentioned hai
2.Humre pass ek x element hai jo hume apne array mein dhund kr dena hai
3.Agar ye x present hai humre pass to uska first occurence jha pehli baar aaya hai vo return kr do
4.Agar x present nhi hai to hume -1 return kr dena hai

step2:-Input dekho:-
arr=[1,2,3,4]    x=3
     0 1 2 3

 Aab Humre Pass ek Question hai hum Search kha se start krenge??
 0-->
 1-->
 2-->
 3-->    

 Kyun?
 kyuki hume "First Occurence chiye"
 isliye hamesa left to right chalenge

step3:-Dry Run:-
i=0
arr[0]=1
1==3 ?  No

i=1
arr[1]=2
2==3 ? No

i=2
arr[2]=3
3==3  ? Yes ur yhi se break ho jao  "Search Khatam"

Agar humre pass array mein x mila h nhi to

arr=[1,2,3,4]  x=8
i=0
arr[0]=1
1==8 ? No

i=1
arr[1]=2
2==8 ? No

i=2
arr[2]=3
3==8 ? No

i=3
arr[3]=4
4==8 ? No

agar loop khtm hogaya ho to hume -1 return kr dena hai


step3:-Loop ki soch
1.Hum ek loop chla lenge 0 to arr.size() tk
2.Hum ek ek element left to right traverse krte huye jayenge
3.agar hume element x ke equal mihl gaya to uska index return kr denge ur break krke loop ko clode kr denge
4.Agar answer na mila hume to -1 return kr denge

    int search(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                return i;
            }
        }
        
        return -1;
    }
};

step4:Recursion ki soch

arr=[10 20 10 10 40]  x=40
      0  1  2  3  4

  Tail Recursion:-
  int ans=-1
  Phase 1:-
  10==40 ? No
  search(arr,ans,index+1)
  
  Phase 2:-
  20==40 ? No
  search(arr,ans,index+1)

  Phase 3:-
  10==40 ? No
  serach(arr,ans,index+1)

  Phase 4:-
  10==40 ? No
  search(arr,ans,index+1)

  Phase 5:-
  40==40 ? Yes ans=index ans=4
  return;

  Q1. Hum kya optimized kr rhe hai -- ans
  Q2. Hume rukna kab hai --  index >= arr.size()
  Q3. Hum Problem kaise choti kar sakte hai -- index+1
  Q4. Recursive call kitni kr rhe hai -- sirf ek
  Q5. Answer kaise generate kaise ho rha hai -- arr[index]==x  ans=index

  class Solution {
  public:
    int searchLinear(vector<int>& arr,int ans,int index,int x){
        
        if(index>=arr.size()){
            return ans;
        }
        
        if(arr[index]==x){
            ans=index;
            return ans;
        }
        
        return searchLinear(arr,ans,index+1,x);
    }
     
    int search(vector<int>& arr, int x) {

        int ans=-1;
        return searchLinear(arr,ans,0,x);
    }
};

step5:-Head Recursion  kaise kre taaki Signature shi ho sake
  Abhi tk hum aise kr rhe the 
    (arr,ans,0,3)     1==3 ?  NO
         |
    (arr,ans,1,3)     2==3 ? NO
         |
    (arr,ans,2,3)      3==3 ? Yes  ans=2  return ans;      

  Aab hume aise krna hai 
   (arr,0,3)    arr[index]==x  ? No
   (arr,1,3)    arr[index]==x  ? No
   (arr,2,3)    arr[index]==3  ? Yes return

    int searchLinearHeadRecursion(vector<int>& arr,int index,int x){
       if(index>=arr.size()){
        return -1;
       }

       if(arr[index]==x){
         return index;
       }

       return searchLinearHeadRecursion(arr,index+1,x);
    
    
    }

