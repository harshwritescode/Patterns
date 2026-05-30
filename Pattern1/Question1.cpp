// Given an array nums and a target, return indices of two numbers whose sum = target.

nums=[2,7,11,15];
target=9;

output: [0,1]  Reason : nums[0]+nums[1]=9


Step1: Question convert into your language

Array diya hai
2 number dhundo 

unka sum target ke equal hona chiye 

Numbers nahi,
unke indexes return karne hai

step2: Input dekho
2
7
11
15

step3: Brute Force socho

Question solve krne ki pehla idea 

mai har number  ko har number ke saath add krunga

2+7=9   (true)     {2,7} == 9(target)
2+11=13 (false)    {2,11} == 9(target)
2+15=17 (false)    {2,15} == 9(target)
7+11=18 (false)    {7,11} == 9(target)
7+15= 22 (false)   {7,15} == 9(target)
11+15=26 (false)   {11,15} == 9(target)


step4 : Pattern nikalo

har pair check krane ka time hum kyu kr rahe hai ???

let suppose :

current=2
target=9

Hum soch rahe hai hume 9-2= 7 (mujhe 7 chiye )

current=7
target=9

hum soch rhe hai hume 9-7=2 (mujhe aab 2 chiye ) 



Pattern Analysed hua mujhe
Current element lo
Target se minus karo
check kro remaining value pehle dekhi hai ki nahi

Note:    Ye hi Two Sum ka actual pattern hai.

Step5: Question ko ur todh sakte hai

HashMap Pattern

need= target- nums[i];

  kya need humne pehle array mein kahi dekha hai kya ??

  agar haa - answer mihl gaya
  agar nhi - current number store kr do 

step 6: Generic Template
1. Traverse array
2. Current value nikalo
3. Required value calculate karo
4. HashMap mein search karo
5. Mil jaye -> answer
6. Nahi mile -> store karo


Dry Run:

nums = [2,7,11,15] target=9  map {}

i=0;
 num=2  need=9-2=7  map mein 7 hai  NO {2:0}
i=1;
 num=7 need=9-7=2  map mein 2 hai yes  map[2]=0   currentindex=1;   answer {0,1}


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int currentElement=nums[i];
            int needsum=target-currentElement;

           if(mp.find(needsum) != mp.end()){
                return {mp[needsum],i};
            }
            else{
                mp[currentElement]=i;
            }

        }
        return {};
    }
};















