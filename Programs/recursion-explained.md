# Video 1: 

[link](https://youtu.be/Q83nN97LVOU)

for fibbonachi - it is better to implement using a for loop!

# Video 2: 

[link](https://youtu.be/ngCos392W4w)

## 1. Problem: recrusive sum of N upto n.
implementation in: vid2-prob1.c

How to Think about Recursion? So:

    1. Define simplest case and set as base case. (0 or 1 mostly).
    2. Play with examples and see how it works.
    3. Relate big/hard example to simpler one.
    4. Create the pattern.
    5. Code it!

Recursive Leap of Faith: Assume Simpler Cases work.

i.e. sum(5) = 5+sum(4) in prob 1.

## 2. Problem: calculate unique paths from top left till bottom right of n x m grid.

    1. simple input = 1,1 == 1 path, 2,1 , 1,2 also 1 path. so if either or is 1 then 1
    2. 2,2 is a 2. 2,3 a 3. 3,3 a 6. 
    3. is it... n * (m-1)?  nope, it is 2,3 + 3,2.  
    4. so it is (n*(m-1))+((n-1)*m)
    5. code...

## 3. Problem: count the number of ways to partition n objects using parts up to m>=0. (so the biggest number in a partition is m. i.e.: n=10,m=5: 5+5,5+4+1,...,1+1+...+1)

    1. simplest: 0,0. has 1 partition. also for 0,1 and 0,2. so if n=0 then 1, if m=0 then 0
    2. 3. play: all n,m-1 are in n,m and rest are in n-m,m.
    4. count(n,m) = count(n-m,m) + count (n,m-1).
    5. code


# Video 3: 

[link](https://youtu.be/BNeOE1qMy)

Fortran was the first language to introduce loops

> excellent for scientific calculations

Fortran was slightly abstracter than Assembly -time period of 40s to 60s-

Two for loops are just a two dimensional arrays.

Higher dimensional Arrays might need the higher nested loops.

Ackerman's function is so high that there's almost no thing of similar "might" needed in day-to-day life.

Compiler are kind of similar but a tad lower.

Bracket nesting is the simplest form of recursion that you see in real life.


