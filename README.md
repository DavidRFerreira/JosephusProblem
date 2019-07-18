# josephusProblem_C
The Josephus Problem implemented with the C language.

There are many different ways to implement this problem. The one that is being 
presented here sure is not the most effective method but it is, in my opinion, the 
most natural way of thinking.

-----Description of the Problem:

Soldiers are standing in a circle waiting to be killed. Counting begins at a specified 
point in the circle and proceeds around the circle in a specified direction. The first
soldier kills the soldier (that's still alive) next to him, then the next soldier in the
circle (still alive) kills the next soldier (still alive) next to him. This goes on till
there's only one soldier left (the one that survived).

The problem — given the number of soldier — is to choose the position in the initial circle to 
avoid execution.

-----Example:

Let´s imagine that there are 5 soldiers. In which position is the soldier that is going to survive?
(A) - alive. 
(D) - dead.

soldiers = [1(A), 2(A), 3(A), 4(A), 5(A)] 
soldiers = [1(A), 2(D), 3(A), 4(A), 5(A)] (1 killed 2)
soldiers = [1(A), 2(D), 3(A), 4(D), 5(A)] (3 killed 4)
soldiers = [1(D), 2(D), 3(A), 4(D), 5(A)] (5 killed 1)
soldiers = [1(D), 2(D), 3(A), 4(D), 5(D)] (3 killed 5)

So, the soldier in the 3rd position survived!
