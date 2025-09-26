# Sort Analysis Data

## Results Table
Make sure to go out to at least 100,000 (more are welcome), and you have 10 different values (more welcome). You are welcome to go farther, but given 100,000 can take about 20 seconds using a selection sort on a fast desktop computer, and 200,000 took 77 seconds, you start having to wait much longer the more 0s you add. However, to build a clearer line, you will want more data points, and you will find merge and quick are able to handle higher numbers easier (but at a cost you will explore below). 

You are free to write a script to run the program and build your table (then copy that table built into the markdown). If you do that, please include the script into the repo.  Note: merge and quick sorts are going to be explored in the team activity for Module 06. You can start on it now, but welcome to wait.

 

### Table [^note]
| N | Bubble | Selection | Insertion | Merge | Quick |
| :-- | :--: | :--: | :--: | :--: | :--: |
|100|0.000015|0.000007|0.000003|0.000005|0.000004|
|600|0.000386|0.000140|0.000111|0.000034|0.000026|
|1100|0.001087|0.000432|0.000270|0.000067|0.000052|
|20600|0.448772|0.130043|0.084871|0.001463|0.001233|
|21100|0.471930|0.135835|0.091166|0.001558|0.001277|
|21600|0.440764|0.142019|0.091892|0.001615|0.001354|
|48600|3.038722|0.728326|0.473094|0.003809|0.003337|
|49100|3.247625|0.732217|0.486210|0.003772|0.003299|
|49600|3.304235|0.749241|0.486749|0.004007|0.003215|
|76600|8.483181|1.808503|1.204223|0.006272|0.005416|
|77100|8.623096|1.845302|1.213143|0.006665|0.005432|
|77600|8.602854|1.837834|1.227466|0.006512|0.005536|
|98600|14.343674|2.948584|1.978974|0.008386|0.007370|
|99100|14.438810|2.977922|1.989524|0.008474|0.007019|
|99600|14.623122|3.068675|2.029382|0.008457|0.007265|

__Note: see results.txt for full table. This is a sample__


## BigO Analysis  / Questions

### 1. Build a line chart
Build a line chart using your favorite program. Your X axis will be N increasing, and your Y access will be the numbers for each type of sort. This will create something similar to the graph in the instructions, though it won't be as smooth. Due to speed differences, you may need to break up the $O(\log n)$ and $O(n^2)$ into different charts.

Include the image in your markdown. As a reminder, you save the image in your repo, and use [image markdown].

![Algorithum Results](/hw_extra_materials/results.png)
_See Code hw_extra_materials\results.ipynb for graph generation_




### 2. Analysis
Looking at the graph and the table, what can you say about the various sorts? Which are the fastest? Which are the slowest? Which are the most consistent? Which are the least consistent? Use this space to reflect in your own words your observations.

looking at the graph we can clearly see there is a big difference between our quadratic sorts and out linnerimthic sorts  (n log(N)). From best to worst we can clearly see the following relationships:
Best:
1. Quick -> best
2. Merge
3. Insertion
4. Selection
5. Bubble -> worst

As for consistentcey we can clearly see that Merge and Quick sorts have the slowest growth rate and therefor are the most consistent given and increasing list size. We can also say that selection and merge sort are the most consistent since they have a none adaptive run time (best, worst and average are the same). Bubble sort is a little bit of a quagmire given how much worse it is compared to the others. I believe the issue is related to the number of `swaps` bubble sort algorithum does. The other quadratic algorithum tend to perform less swaps.


### 3. Big O
Build another table that presents the best, worst, and average case for Bubble, Selection, Insertion, Merge, and Quick. You are free to use resources for this, but please reference them if you do. 

| Algorithum| Best | Average    | Worst|
| :--       | :--: | :--:       | :--: |
| Bubble    | $O(n)$ | $O(n^2)$ | $O(n^2)$|
| Selection |   $O(n^2)$ | $O(n^2)$ |$O(n^2)$|
| Insertion | $O(n)$ |$O(n^2)$|$O(n^2)$
| Merge     | $O(n*log(n))$|$O(n*log(n))$|$O(n*log(n))$
| Quick     | $O(n*log(n))$| $O(n*log(n))$| $O(n^2)$





* https://www.geeksforgeeks.org/dsa/when-does-the-worst-case-of-quicksort-occur/
* https://stackoverflow.com/questions/4834740/what-is-the-worst-case-scenario-for-quicksort
* https://www.geeksforgeeks.org/dsa/comparison-among-bubble-sort-selection-sort-and-insertion-sort/

#### 3.2 Worst Case
Provide example of arrays that generate _worst_ case for Bubble, Selection, Insertion, Merge Sorts

Worst Case:
* Bubble: reverse sorted (5,4,3,2,1). Every element will have to be compared to every other element. 
* Selection: always runs in O(n^2). We use a for loop and iterate over all elements without an early out option
* Insertion: reverse sorted (5,4,3,2,1). This means we will have to bring the 1st element to the back of the array which means at every iteration our comparison will be n-1, n-2, ...,2, 1
* Merge: Any. Merge sort has constant time complexity and does not change given the order of the array.
* Quick: nLog(n). Picking a pivot which is the min or max of the array.

* https://www.geeksforgeeks.org/dsa/when-does-the-worst-case-of-quicksort-occur/
* https://stackoverflow.com/questions/4834740/what-is-the-worst-case-scenario-for-quicksort

#### 3.3 Best Case
Provide example of arrays that generate _best_ case for Bubble, Selection, Insertion, Merge Sorts 

Best Case:
* Bubble: Already sorted (1,2,3,4,5). There is an early out option which makes the algorithm O(N) if the list is already sorted.
* Selection: Always runs in O(n^2). We Use a for loop and iterate over all element without an early out option
* Insertion: Pre Sorted (1,2,3,4,5). The while loop can be a constant operation since it will only do one comparison
* Merge: Any. Merge sort's time complexity does not change given the order of the array.
* Quick: nLog(n). Picking the correct pivot element IE an element that is not the min nor max of the list. Its best to use a random  index


#### 3.4 Memory Considerations
Order the various sorts based on which take up the most memory when sorting to the least memory. You may have to research this, and include the mathematical notation. 

_Best_
1. Bubble, selection, insertion: these algorithms time complexity can be considered constant O(1). They never create an array or create new variables at every iteration, and use index variables. Therefor the space throughout the sort remains stable and does no grow. 
2. Quick: on average quick's space complexity is O(log(n)), but given the worst conditions it is O(n) like merge.
3. Merge: we have to have a temporary array of n. 
_Worst_

https://www.geeksforgeeks.org/dsa/time-and-space-complexity-analysis-of-quick-sort/


### 4. Growth of Functions
Give the following values, place them correctly into *six* categories. Use the bullets, and feel free to cut and paste the full LatexMath we used to generate them.  

__Answer:__ 
#### Categories

_Constant:_
* $10000$
* $100$  

_Linear:_
* $3n$ 
* $100n$

_Linearithmic (nLog (n)):_
* $n\log_2n$  

_Quadratic:_
* $n^2$
* $5n^2+5n$  


_Exponential:_
* $2^n$
* $2^{(n-1)}$  


_Factorial:_
* $n!$  

<!-- $n^2$   -->
<!-- $n!$   -->
<!-- $n\log_2n$   -->
<!-- $5n^2+5n$   -->
<!-- $10000$   -->
<!-- $3n$     -->
<!-- $100$   -->
<!-- $2^n$   -->
<!-- $100n$   -->
<!-- $2^{(n-1)}$ -->


### 5. Growth of Function Language

Pair the following terms with the correct function in the table. 
* Constant, Logarithmic, Linear, Quadratic, Cubic, Exponential, Factorial

| Big $O$     |  Name  |
| ------      | ------ |
| $O(n^3)$    |  Cubic |
| $O(1)$      |  Constant |
| $O(n)$      |  Linear |
| $O(\log_2n)$ |  Logarithmic |
| $O(n^2)$    |  Quadratic |
| $O(n!)$     | Factorial  |
| $O(2^n)$    |  Exponential |



### 6. Stable vs Unstable
Look up stability as it refers to sorting. In your own words, describe one sort that is stable and one sort that isn't stable  

A stable algorithm is one that maintains the original order of the elements when sorting. For example lets say we are sorting these tuples by there first element:

_Orginal List:_
(2,"Bob"), (2,"Josh"), (1,"Dave")

_Stable Sort:_
(1,"Dave"), (2,"Bob"), (2,"Josh")

_Unstable Sort_
(1,"Dave"), (2,"Josh"), (2,"Bob")


In the above example we can see that the stable sort maintains the original order of Bob and then Josh, but the unstable sort does not and swaps the original order.

https://www.geeksforgeeks.org/dsa/stable-and-unstable-sorting-algorithms/

### 6.2 When stability is needed?
Explain in your own words a case in which you will want a stable algorithm over an unstable. Include an example. 

I think this is pretty important when there is a natural order to the data. For example lets say we have a list that we append credit card transaction too when they happen. This list would be naturally be sorted by time. If we were too then sort this list by transaction amount, we would then have a list that is sorted by transaction amount and then time.


### 7. Gold Thief

You are planning a heist to steal a rare coin that weighs 1.0001 ounces. The problem is that the rare coin was mixed with a bunch of counter fit coins. You know the counter fit coins only weight 1.0000 ounce each. There are in total 250 coins.  You have a simple balance scale where the coins can be weighed against each other. Hint: don't think about all the coins at once, but how you can break it up into even(ish) piles.

#### 7.1 Algorithm
Describe an algorithm that will help you find the coin. We encourage you to use pseudo-code, but not required.

I believe this problem can be accomplished as divide and conquer algorithm. This can be accomplished with the following steps:

1. split pile of gold in half even halfs. If you are dealing with an odd number of coins pull one out and leave aside -> $Pile_1, Pile_2, ExtraCoin$  
2. Weigh Each Pile => $PileWeight_1, PileWeight_2$  
3. Perform the following checks:  
   3.1 If $PileWeight_1 \gt PileWeight_2$  
   &nbsp;&nbsp;&nbsp;&nbsp;3.1.1 if $size(Pile_1) \gt 1$ start at step one with $Pile_1$  
   &nbsp;&nbsp;&nbsp;&nbsp;3.1.2 if $size(Pile_1) = 1$ Congratulations you have found the rare coin!  

   3.2 If $PileWeight_2 \gt PileWeight_1$  
   &nbsp;&nbsp;&nbsp;&nbsp;3.2.1 if $size(Pile_2) \gt 1$ start at step one with $Pile_2$  
   &nbsp;&nbsp;&nbsp;&nbsp;3.2.2 if $size(Pile_2) = 1$ Congratulations you have found the rare coin!

   3.3 If $PileWeight_1 == PileWeight_2$ then your $ExtraCoin$ is the rare coin!

```c
 SplitPiles(pile, size):
    Input:
        pile: pile of coins
        size: size of pile
    output:
        index: pile_1, pile_2, size, extra_coin

    if size MOD 2 == 0:
        extra_coin == NULL
        mid = size/2
        pile_1 =  pile[0:mid]
        pile_2 = pile[mid, size]
    
    else:
        extra_coin = pile[size-1]
        size -= 1
        mid = size/2
        pile_1 =  pile[0:mid]
        pile_2 = pile[mid, size]
    return pile_1, pile_2, size, extra_coin

weighPiles(pile_1, pile_2):
    Input:
        pile: pile of coins
    output:
        weight:
        - 1: pile_1 is heavier then pile_2
        - 0: pile_1 and pile_2 are of equal weight
        - -1: pile_2 is heavier then pile_1
    // imagination... Cant code a phsycal action
    weight(pile_1,pile_2)


FindMeSomeRareGold(pile, size)
    Input:
        pile: pile of coins
        size: size of pile
    output:
        Rare Coin:

    // if we have one coin then we have reach our base case
    if size == 1:
        return pile[0]

    // Split Coins into even piles
    pile_1, pile_2, size, extra_coin = SpiltPiles(pile, size)

    // Weigh Each Pile
    weighing_result = weighPiles(pile_1, pile_2)

    if(weighing_result == 1):
        return FindMeSomeRareGold(pile_1, size)
    else if (weighing_result == -1):
        return FindMeSomeRareGold(pile_2, size)
    else:
        return extra_coin
```





#### 7.2 Time Complexity

__Best Case:__
The best case for this algorithm would be O(1). This means when we perform our splits and weighing action we are immediately able to find our coin on the first try

__Average Case:__
This algorithm is hard to say exactly what the average case would be expect for it being $O(Log(n))$. We know that our recursive calls should reach about half down the recursive tree. Given that position we know this algorithm will be greater than $O(1)$ and less than $O(Log(n))$ given the average case therefor it would be $O(Log(n))$

__Worst Case:__
As a worst case this algorithm should run in $O(Log(n))$. We can assume this because we are recursively splitting our piles in half every time, and thus our operations are working on smaller and smaller piles.



## Technical Interview Practice Questions

For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.

2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others. 
 

## Deeper Thinking
Sorting algorithms are still being studied today. They often include a statistical analysis of data before sorting. This next question will require some research, as it isn't included in class content. When you call `sort()` or `sorted()` in Python 3.6+, what sort is it using? 

#### Visualize
Find a graphic / visualization (can be a youtube video) that demonstrates the sort in action. 

#### Big O
Give the worst and best case time-complexity, and examples that would generate them. 

<hr>

## References
Add your references here. A good reference includes an inline citation, such as [1] , and then down in your references section, you include the full details of the reference. Use [ACM Reference format].

1. Reference info, date, etc.
2. ...





## Footnotes:
[^note]: You will want at least 10 different N values, probably more to see the curve for Merge and Quick. If bubble, selection, and insertion start to take more than a  minute, you can say $> 60s$ or - . For example 
    | N | Bubble | Selection | Insertion | Merge | Quick |
    | :-- | :--: | :--: | :--: | :--: | :--: |
    | 10,000|0.197758|0.070548|0.000070|0.000513|0.000230|
    |100,000|-|-|-|0.131061|0.018602|

<!-- links moved to bottom for easier reading in plain text (btw, this a comment that doesn't show in the webpage generated-->
[image markdown]: https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax#images

[ACM Reference Format]: https://www.acm.org/publications/authors/reference-formatting
[IEEE]: https://www.ieee.org/content/dam/ieee-org/ieee/web/org/conferences/style_references_manual.pdf