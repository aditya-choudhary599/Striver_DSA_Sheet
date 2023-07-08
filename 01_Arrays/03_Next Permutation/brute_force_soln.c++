/* Question link : https://leetcode.com/problems/next-permutation/description/

This solution is inspired from the brute-force approach idea that striver gave in his solution video of this question
The link for that video is : https://www.youtube.com/watch?v=JDOXKqF60RQ&t=808s */

/* Here I am writing the algorithm for this only
Step 1 : Store all the possible sequences which will be n! in a vector of vector
Step 2 : Sort the vector of vector
Step 3 : Get the next sequence after the given sequence from the vector of vector
Step 4 (Edge Case) : And if the given sequence is already sorted in the descending order then return the sequence which is sorted in the ascending order (As mentioned in the question)*/
