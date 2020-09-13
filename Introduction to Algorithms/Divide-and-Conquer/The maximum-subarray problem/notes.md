# The maximum-subarray problem

Suppose we want to find a maximum subarray of the subarray A[low...high]. We can divide the subarray into 2 subarrays of as equal size as possible.
- find the **mid** point
- consider A[low...mid] and A[mid+1...high]
Then we got 3 sub-problems
- Find the maximum-subarray of A[low...mid]
- Find the maximum-subarray of A[mid+1...high]
- Find the maximum-subarray cross **mid**point
The **answer** is the largest one of the three.

Consider the third one, *find the maximum-subarray cross the midpoint*
- any sub-array crossing the midpoint consist of 2 sub-arrays, A[i...mid] and A[mid+1...j]
- we just need to find the maximum-subarray of the form A[i..mid] and A[mid+1...j],  the combine them.

**TAKE A LOOK AT the file** ***Find_max_crossing_subarray.c***

