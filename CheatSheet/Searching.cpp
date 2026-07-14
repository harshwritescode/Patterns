1. Linear Search
Condition: Array sorted hona zaruri nahi.

Har element check karte hain.
Time Complexity
Best    : O(1)
Average : O(n)
Worst   : O(n)


2.Binary Search
Condition: Array sorted hona chahiye.

Har baar search space ko aadha kar dete hain.

Time Complexity
Best    : O(1)
Average : O(log n)
Worst   : O(log n)

3. Jump Search
Condition: Array sorted hona chahiye.

Pehle blocks mein jump karta hai, phir linear search.

Time Complexity
O(√n)

4. Interpolation Search
Condition: Sorted array,Uniformly distributed data

Binary Search se bhi fast ho sakta hai.

Time Complexity
Average:O(log log n)
Worst:O(n)

5. Exponential Search

Condition: Sorted Array,Size unknown ho

Pehle range find karta hai, fir Binary Search.
O(log n)


6. Fibonacci Search
Binary Search jaisa hi hai
Middle nikalne ke liye Fibonacci numbers use karta hai.

O(log n)

7. Ternary Search

Har baar array ko 3 parts mein divide karta hai.

Mostly unimodal functions ke liye use hota hai, normal array searching ke liye Binary Search zyada common hai.

8. Hashing
Agar multiple searches karni hain.

unordered_map
unordered_set

Average: O(1)

Interview ke liye sabse important
Abhi tum is order mein padho:

✅ Linear Search
✅ Recursive Linear Search
✅ Binary Search
✅ Recursive Binary Search
✅ Lower Bound
✅ Upper Bound
✅ First Occurrence
✅ Last Occurrence
✅ Count Occurrence
✅ Search Insert Position
✅ Floor & Ceil
✅ Rotated Sorted Array
✅ Peak Element
✅ Search in 2D Matrix

