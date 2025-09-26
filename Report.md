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
|...|...|...|...|...|...|
|20600|0.448772|0.130043|0.084871|0.001463|0.001233|
|21100|0.471930|0.135835|0.091166|0.001558|0.001277|
|21600|0.440764|0.142019|0.091892|0.001615|0.001354|
|...|...|...|...|...|...|
|48600|3.038722|0.728326|0.473094|0.003809|0.003337|
|49100|3.247625|0.732217|0.486210|0.003772|0.003299|
|49600|3.304235|0.749241|0.486749|0.004007|0.003215|
|...|...|...|...|...|...|
|76600|8.483181|1.808503|1.204223|0.006272|0.005416|
|77100|8.623096|1.845302|1.213143|0.006665|0.005432|
|77600|8.602854|1.837834|1.227466|0.006512|0.005536|
|...|...|...|...|...|...|
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

Looking at the graph, we can clearly see there is a big difference between our quadratic sorts and our linearithmic sorts (n log(n)). From best to worst case, we can find the following relationship
Best:
1. Quick -> best
2. Merge
3. Insertion
4. Selection
5. Bubble -> worst

For consistency, the Merge and Quick sort algorithms have the slowest growth rate, and thus are the most consistent as the number of elements grows. In another way, we can also say that Selection and Merge sort are the _most_ consistent for runtime, since their best, average, and worst cases are the same. Bubble sort also seem to have the most variation in practice. I believe the issue with Bubble sort is related to the number of `swaps` the Bubble sort algorithm performs. The other quadratic algorithms tend to perform fewer swaps and therefore are less costly at each iteration.


### 3. Big O
Build another table that presents the best, worst, and average case for Bubble, Selection, Insertion, Merge, and Quick. You are free to use resources for this, but please reference them if you do. 

| Algorithum| Best | Average    | Worst|
| :--       | :--: | :--:       | :--: |
| Bubble    | $O(n)$ | $O(n^2)$ | $O(n^2)$|
| Selection |   $O(n^2)$ | $O(n^2)$ |$O(n^2)$|
| Insertion | $O(n)$ |$O(n^2)$|$O(n^2)$
| Merge     | $O(n*log(n))$|$O(n*log(n))$|$O(n*log(n))$
| Quick     | $O(n*log(n))$| $O(n*log(n))$| $O(n^2)$

[2, 3, 4]

#### 3.2 Worst Case
Provide example of arrays that generate _worst_ case for Bubble, Selection, Insertion, Merge Sorts

Worst Case:
* __Bubble__: Reverse sorted `(5,4,3,2,1)`. Every element will have to be compared to every other element.
* __Selection__: regardless of input, this algorithm always runs in $O(n^2)$ . We use a for loop and iterate over all elements and do not have adaptive out option. 
* __Insertion__: reverse sorted array for example `(5,4,3,2,1)`. This means we will have move the 1st element to the back of the array resulting in  n-1, n-2, ... 2, 1 comparisons
* __Merge__: Any array. Merge sort has time complexity does not change given the order of the array.
[4, 2]

#### 3.3 Best Case
Provide example of arrays that generate _best_ case for Bubble, Selection, Insertion, Merge Sorts 

Best Case:
* Bubble: Already sorted (1,2,3,4,5). There is an early out option which makes the algorithm O(N) if the list is already sorted.
* Selection: Always runs in O(n^2). We Use a for loop and iterate over all element without an early out option
* Insertion: Pre Sorted (1,2,3,4,5). The while loop can be a constant operation since it will only do one comparison
* Merge: Any. Merge sort's time complexity does not change given the order of the array.
* Quick: nLog(n). Picking the correct pivot element IE an element that is not the min nor max of the list. Its best to use a random  index
[4, 2]

#### 3.4 Memory Considerations
Order the various sorts based on which take up the most memory when sorting to the least memory. You may have to research this, and include the mathematical notation. 

_Best_
1. _Bubble, Selection, Insertion_: These algorithms’ space complexity can be considered constant, $O(1)$. They never create an additional array or new variables at every iteration, and instead use index variables. Therefore, the space throughout the sort remains stable and does not grow.
2. _Quick_: On average, Quick sort’s space complexity is $O(\log n)$, but under the worst conditions it can be $O(n)$, similar to Merge. I put it before Merge due to its more favorable variability.
3. _Merge_: Requires a temporary array of size $n$, and thus resulting in a space complexity of $O(n)$.
_Worst_
[2, 3, 4]


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

_Original List:_
(2,"Bob"), (2,"Josh"), (1,"Dave")

_Stable Sort:_
(1,"Dave"), (2,"Bob"), (2,"Josh")

_Unstable Sort_
(1,"Dave"), (2,"Josh"), (2,"Bob")


In the above example we can see that the stable sort maintains the original order of Bob and then Josh, but the unstable sort does not and swaps the original order.

https://www.geeksforgeeks.org/dsa/stable-and-unstable-sorting-algorithms/

### 6.2 When stability is needed?
Explain in your own words a case in which you will want a stable algorithm over an unstable. Include an example. 

I think this is pretty important when there is a natural order to the data you are dealing with. For example, lets say we have a list that we append credit card transaction too at the time of transaction. This list would be naturally be sorted by time. If we were too then sort this list by transaction amount, we would then have a list that is sorted by transaction amount and then time if we used a stable algorithm.


### 7. Gold Thief

You are planning a heist to steal a rare coin that weighs 1.0001 ounces. The problem is that the rare coin was mixed with a bunch of counter fit coins. You know the counter fit coins only weight 1.0000 ounce each. There are in total 250 coins.  You have a simple balance scale where the coins can be weighed against each other. Hint: don't think about all the coins at once, but how you can break it up into even(ish) piles.

#### 7.1 Algorithm
Describe an algorithm that will help you find the coin. We encourage you to use pseudo-code, but not required.

I believe this problem can be accomplished as divide and conquer algorithm. 

# Instructions:

1. split pile of gold in two  even halves.
   1.1 If you are dealing with an odd number of coins pull one out -> $Pile_1, Pile_2, ExtraCoin$  
2. Weigh Each Pile => $PileWeight_1, PileWeight_2$  
3. Perform the following checks:  
   3.1 If $PileWeight_1 \gt PileWeight_2$  
   &nbsp;&nbsp;&nbsp;&nbsp;3.1.1 if $size(Pile_1) \gt 1$ start at step one with $Pile_1$  
   &nbsp;&nbsp;&nbsp;&nbsp;3.1.2 if $size(Pile_1) = 1$ Rare Coin!  

   3.2 If $PileWeight_2 \gt PileWeight_1$  
   &nbsp;&nbsp;&nbsp;&nbsp;3.2.1 if $size(Pile_2) \gt 1$ start at step one with $Pile_2$  
   &nbsp;&nbsp;&nbsp;&nbsp;3.2.2 if $size(Pile_2) = 1$ Rare Coin!

   3.3 If $PileWeight_1 == PileWeight_2$ $ExtraCoin$ is the Rare Coin!

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
The best case for this algorithm would be O(1). This means when we perform our splits and weighing action, we are immediately able to find our coin on the first try

__Average Case:__
It is hard to say exactly what the average case would be for this algorithm. We know that our recursive calls should reach about half way down the recursive tree when compared to the worst case. Given this information, we know this algorithm will be greater than $O(1)$ complexity but less than $O(Log(n))$. We can therefor conclude that the runtime is $O(Log(n))$

__Worst Case:__
As a worst case this algorithm is $O(Log(n))$. We can assume this because we are recursively splitting our piles in half every time, and thus our number operations would grow at a logarithmic rate.



## Technical Interview Practice Questions

For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.

__Question:__ When would we want an algorithm with a higher time complexity than another faster algorithm?
__Answer:__
Choosing an algorithm is always situational and really dependent on the task at hand. _Speed is never the only parameter to consider_. For example, if we want to sort data live, the fast quick and merge sort, may not be the answer given that they are offline algorithms. We Therefor may want to consider algorithms that can work online like insertion sort.


2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others. 

__Problem: Remove Element__
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

```c
int removeElement(int* nums, int numsSize, int val) {
    // index with current items removed
    int k = 0;
    // indexing through the array
    for (int i=0; i < numsSize; i++){
        if (nums[i] != val){
            nums[k] = nums[i];
            k++;//
        }
    }
    return k;
}
```


## Deeper Thinking
Sorting algorithms are still being studied today. They often include a statistical analysis of data before sorting. This next question will require some research, as it isn't included in class content. When you call `sort()` or `sorted()` in Python 3.6+, what sort is it using?

#### Description
Python's sort function relies on the algorithm `Timsort`. `Timsort` is what we call a hybrid algorithm. Every sorting algorithm has benefits and and draw backs and hybrid algorithms tries to maximize the benefits and minimize the cost of each algorithm. Hybrid algorithms accomplish this by  merging multiple algorithms into one. `Timesort` is backed by two algorithms, insertion and merge. Let's break down the major steps of this algorithm

##### TimSort Steps:
1. First we break our array into chunks whihc are called runs. These runs are generally 32 to 64 elements long.
    <br>1.1 (Optimization) Insertion Only: If the array is of a certain size we just run insertion sort and therefor reduce the overhead of the entire algorithm.<br><br>
2. We then sort each run using insertion sort. 
    <br>2.2 (Optimization) Reverse it: When using insertion sort we identify if the run is in descending order, and if it is we then reverse it.<br><br>
3. We then take each chunk and perform merge from merge sort. 
    <br>3.1 (Optimization) Gallop Mode: This merge sort is adaptive because it will recognize when a particular sub array has been added back to the main array multiple times. When this happens the algorithm "gallops" over items by using binary insertion. This allows us to insert multiple value at once and reduce the number of comparisons on average.
    <br>3.2 (Optimization) Adaptive Merging: We will also calculate the size of each array and merge arrays that are considerably smaller together.

`Timsort` is powerful because it is designed to detect patterns within data and then use those patterns to it advantage. 
[5, 1]

#### Visualize
Find a graphic / visualization (can be a youtube video) that demonstrates the sort in action. 
* https://www.youtube.com/watch?v=GhP5WbE4GYo&t=3s
* https://www.youtube.com/watch?v=0Dg41UEK3Io&t=1s
* https://www.youtube.com/watch?v=NVIjHj-lrT4&t=1s
[5, 1, 8]


#### Big O
Give the worst and best case time-complexity, and examples that would generate them.

* Best Case: $O(n)$, the array is already sorted `(0,1,2,3,4,5)`
* Worst Case: $O(nLog(n))$. The worst case for this is tricky and is all dependent on how the array is broken up before the merge step. Specifically, we can say that it is the worst case if each sub array needs to be perform the maximum number of swaps at each merge step. For example let say we have the following runs the at we are merging `(0, 2, 4, 6)` and (`1, 3, 5, 7)`. This array will have to make a comparison as each step and thus abstracted out to larger process would result in a time complexity of $O(n*Log(n))$. Merge sort is an adaptive algorithm and given the example array we cannot exploit any natural order within the elements. 
[7]

<hr>

## References
Add your references here. A good reference includes an inline citation, such as [1] , and then down in your references section, you include the full details of the reference. Use [ACM Reference format].

1. Geekific. (n.d.). YouTube. https://www.youtube.com/watch?v=GhP5WbE4GYo&t=3s 
2. GeeksforGeeks. (2025a, July 11). Comparison among bubble sort, selection sort and insertion sort. https://www.geeksforgeeks.org/dsa/comparison-among-bubble-sort-selection-sort-and-insertion-sort/ 
3. GeeksforGeeks. (2025b, July 23). Time and space complexity analysis of Quick Sort. https://www.geeksforgeeks.org/dsa/time-and-space-complexity-analysis-of-quick-sort/ 
4. GeeksforGeeks. (2025c, July 23). When does the worst case of quicksort occur? https://www.geeksforgeeks.org/dsa/when-does-the-worst-case-of-quicksort-occur/ 
5. KIRUPA. (n.d.). Timsort: A Deep Dive Into the Fastest Sorting Algorithm 😀. YouTube. https://www.youtube.com/watch?v=0Dg41UEK3Io&t=1s 
7. On the worst-case complexity of Timsort - IGM. (n.d.). https://igm.univ-mlv.fr/~juge/slides/conf/esa2018.pdf 
6. What is the worst case scenario for quicksort?. Stack Overflow. (2011, January 29). https://stackoverflow.com/questions/4834740/what-is-the-worst-case-scenario-for-quicksort
8. Timo Bingmann. (n.d.). Tim Sort. YouTube. https://www.youtube.com/watch?v=NVIjHj-lrT4&t=1s 






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