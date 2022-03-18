# P.I.Works
technical questionarie
# by EFE ERTÜRK

I have come up with 2 different solutions, and asked which one would be more appropriate to use via email, but I did not get any response. The thing is, I think there exists an ambigiouty in the problem definition. The problem asks me to go as far as possible in the pyramid, and return the maximum path sum. However, these constraints can clash, for example:
  1
 4  9
1  2  2
Would the answer be 10 from 1+9 (but it does not go all the way to the end of the pyramid) or would it be 6 from 1+4+1 (it is less than 10, but it reaches to the end)? 
The implementation which solves as the second technique (which answers the question above as 6) is implemented in method "solvePyramid()".
The implementation which solves as the first technique (which answers the question above as 10, no restriction to go all the way to the end) is implemented in method "solvePyramid2()".
As I have stated, I would eliminate one of these different implementations, but, I did not recieve any answer to my questions. The implementation uses solvePyramid2() in default, but you can change that. This implementation yields the result of 8219 in the question 4, however, other implementation yields 8186.
