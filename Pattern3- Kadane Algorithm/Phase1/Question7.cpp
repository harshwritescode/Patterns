You are given an array prices  where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 prices = [7,1,5,3,6,4]
           0 1 2 3 4 5
          
           0th day=7
           1th day=1
           2nd day=5
           3rd day=3
           4th day=6
           5th day=4

           ans= sell -buy
              =   6 -1 =5

step1:Question convert into your form
1. ek price naam ka array/vector diya hai jisme saare positive elemnet h hai
2. jo indexes hai vo represent day ko kr rhe hai
3. jo values hai vo stock ke price ko
4. hume maximum profit dena hai 
     jisme hum  kisi bhi ek dhin ushe buy krenge
     ur aage kisi bhi future vhle dhin mein hum ushe sell kr denge
5. jo maximum profit hume dega vhi mera answer hoga

step2:Input dekho
 prices = [7,1,5,3,6,4]
           0 1 2 3 4 5

  1. profit maximixed krne ke liye hum puure array mein maximum_elemeng ur minimum_element niakl kr subtract kr sakte the
     lekin usme problem ye hai
     minimum_element=1
     maximum_element=7
     
     profit=7-1=6
     aana chiye ye kyu nhi aayega
     kyuki jish dhin hum buy select krenge phir uske aage se h maximum_element nikal kr lana hai
                   maximumelement   minimumelement       access element
     at index 0:-       7               7                    [7]
     at index 1:-       7               1                    [7,1]
     aab hume break krna chiye :-
                  maximumelement=-1 set kr do ya INT_MIN bhi kr sakte hai

                  phir loop jha se hume minimumelement mila vha se array ke end tk traverse krna hai
                  maximumelement=6
                  profit=6-1=5

                   Maximum Profit = Current Price - Minimum Price Seen Till Now


    2. ish solution mein bhi ek drawback hai
       prices=[7,6,4,3,1]
       isme humne minimum_element nikla =1
       uske baad hum traverse kha kre ye batao ???
       
    3.hum best profit kaise bana sakte hai
       [7,1,5,3,6,4]
       day 0: buy=7
              profit=0
              
       day 1: buy=min(7,1)=1
              profit=0
       day 2: sell=5   
            profit=5-1=4
       day 3: sell=3
             profit = 3 - 1 = 2
       day 4:sell = 6
           profit = 6 - 1 = 5  
       day 5: sell =4
           profit: 6-4=2
           maximum profit=5
        
 step3: Brute force socho:
 1. Har buy day ke liye
 2. future ka har sell day ke liye
 3.profit=sell-buy
 4.maximum profit store krenge

 step4:Dry Run:-

[7,1,5,3,6,4]

Buy at index 0 (7):          Buy at index 1 (1):     Buy at index 2 (5):        Buy at index 3 (3):      Buy at index 4 (6):
7→1 = -6                     1→5 = 4                   5→3 = -2                   3→6 = 3                 6→4 = -2
7→5 = -2                     1→3 = 2                   5→6 = 1                    3→4 = 1
7→3 = -4                     1→6 = 5                   5→4 = -1
7→6 = -1                     1→4 = 3
7→4 = -3

Best=0                       Best=5                    Best=1                     Best=3                   Best = 0
max(0,5,1,3,0) = 5

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       int maxprofit=0;
       for(int i=0;i<n;i++){
         int buyingprice=prices[i];
         for(int j=i+1;j<n;j++){
             int sellingprice=prices[j];
             int difference=sellingprice-buyingprice;
             maxprofit=max(maxprofit,difference);
         }
       } 
       return maxprofit;
    }
};

step5:Repeat work identify kro
 1. hum har index se future tk ke saare element dekhe
 2. uske baad har index i pe best ans store kr rhe hai
 3. phir last mein max krke answer return kr rhe hai

 basically hum koi index pe kadhe hai maan lo 
    index 2: 
       [5,6,3,4]
        2 3 4 5 
 
        2 pe kadhe hone ke baad hum aage ke saare element ko ek ek krke subtract krke maximum profit nikalne ka try kr rhe the isse aacha 
        5 se aage hum maximum_element nikal sakte hai (maximum selling price)
        5->6 =1
        yha kuch opertaion bach gaye

        index 1:
        [1,5,6,3,4]
         1 2 3 4 5
          
         1 pe kadhe hone ke baad hum maximum elemnet nikal rhe hai
         1->6 =5
        
         Har index ke liye = Futuremax[i] - prices[i]
         O(n^2) = O(n) ho jayega


         prices = [7,1,5,3,6,4]
                   0 1 2 3 4 5
                     prices =7 1 5 3 6 4
                   futuremax=7 6 6 6 6 4

                   Maximum = 5

step6: Generic Template
1. Future maximum nikalo
             prices = [7,1,5,3,6,4]
      Right se traverse:           
    futureMax = [7,6,6,6,6,4]

2.   Phase 2: Profit calculate karo  
         profit = futureMax[i] - prices[i]

3. maximum profit

class Solution {
public:
    int maxProfit(vector<int>& prices) {

    int n=prices.size();
    vector<int> futuremax(n);

    futuremax[n-1]=prices[n-1];
    for(int i=n-2;i>=0;i--){
        futuremax[i]=max(futuremax[i+1],prices[i]);
    }
    int profit=0;
    for(int i=0;i<n;i++){
        profit=max(profit,futuremax[i]-prices[i]);
    }
    return profit;
    }
};
Time complexity: O(N)
Space complecity: O(N)

Tum futureMax array bana rahe ho:
Calculation ke time tumhe sirf current future maximum chahiye, poora array nahi.
Ek variable se bhi kaam ho sakta hai.  Space: O(n) -> O(1)

prices = [7,1,5,3,6,4]
Ab Kadane wale insaan ki soch:Profit = 6 - 1
ko tod deta hai:

6 - 1
=
(5-1) + (3-5) + (6-3)
=
4 + (-2) + 3=5

diff = [-6, +4, -2, +3, -2]

Aur problem ban gayi:
Maximum Profit
=
Maximum Sum Contiguous Subarray of diff[]


        int n=prices.size();
        int currsum=0;
        int bestmaxsum=0;

        for(int i=1;i<n;i++){
            int diff=prices[i]-prices[i-1];
            currsum=max(diff,currsum+diff);
            bestmaxsum=max(currsum,bestmaxsum);
        }
        return bestmaxsum;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
    //    int n=prices.size();
    //    int maxprofit=0;
    //    for(int i=0;i<n;i++){
    //      int buyingprice=prices[i];
    //      for(int j=i+1;j<n;j++){
    //          int sellingprice=prices[j];
    //          int difference=sellingprice-buyingprice;
    //          maxprofit=max(maxprofit,difference);
    //      }
    //    } 
    //    return maxprofit;


    // int n=prices.size();
    // vector<int> futuremax(n);

    // futuremax[n-1]=prices[n-1];
    // for(int i=n-2;i>=0;i--){
    //     futuremax[i]=max(futuremax[i+1],prices[i]);
    // }
    // int profit=0;
    // for(int i=0;i<n;i++){
    //     profit=max(profit,futuremax[i]-prices[i]);
    // }
    // return profit;



        int n = prices.size();

        int futureMax = prices[n-1];
        int ans = 0;

        for(int i = n-1; i >= 0; i--) {

            futureMax = max(futureMax, prices[i]);

            int profit = futureMax - prices[i];

            ans = max(ans, profit);
        }

        return ans;
    }
};

