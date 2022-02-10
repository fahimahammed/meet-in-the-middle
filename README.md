# MEET IN THE MIDDLE

This basically reduces time complexity from O(2N) to O(2N/2) .

We divide the set into two sets [0…N/2] and [(N/2 + 1)…(N-1)] and generate all subsets sums individually for the two sets which will be 2 * 217 operations. Now, what we can do is to find the combinations of these sets that would give the desired sum. This again can be done in an efficient way, sort one of the summed up set and binary search the values that will yield the sum for the particular value of the other set. Sort the second set and for each element in the first set, search for the lower bound of A – S2[i] (let say ‘low’) and upper bound of B – S2[i] (let say ‘high’). Subtract (high – low) to get the desired answer.


- Split the set of integers into 2 subsets say A and B. A having first n/2 integers and B having rest.
- Find all possible subset sums of integers in set A and store in an array X. Similarly calculate all possible subset sums of integers in set B and store in array Y. Hence, Size of each of the array X and Y will be at most 2n/2.
- Now merge these 2 sub problems. Find combinations from array X and Y such that their sum is less than or equal to S. 
- One way to do that is simply iterate over all elements of array Y for each element of array X to check the existence of such a combination. This will take O( (2n/2)2) which is equivalent to O(2n).
- To make it less complex, first sort array Y and then iterate over each element of X and for each element x in X use binary search to find maximum element y in Y such that x + y <= S.
- Binary search here helps in reducing complexity from 2nto 2n/2log(2n/2)which is equivalent to 2n/2n.
- Thus our final running time is O(2n/2n).

<br/><br/>
<a href="https://www.geeksforgeeks.org/meet-in-the-middle/">Source</a>



