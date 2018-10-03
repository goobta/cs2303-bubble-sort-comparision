# CS2303 Bubble Sort Comparison

## Summary

This project uses bubble sort to see the efficiency differences in the different
ways to access memory.

## Execution Directions

When you run `make` for the first time, you will get two executables,
`sorttest` and `sorttest2`.

### sorttest

This is the default implementation, which uses an incremented index and a fixed
input for numbers.

To execute this from the commandline, run the executable as 
`./sorttest num1 num2 num3 num4`, where `num` is a number that you would like to
be sorted.

### sorttest2

This executable allows for different implementations of the algorithm to be
used, as well as the ability to randomly generate numbers.

To execute this from the commandline, run the executable as 
`./sorttest2 num_of_nums implementation`, where `num_of_nums` is an integer
representing how many numbers you would like generated, and `implementation`
being either `0`, `1`, or `2`. The number to implementation map is defined as
below:

* `0` - the default implementation. Uses an index variable in a for loop and
  accesses the array through `a[i]`
* `1` - increments a delta variable that gets added to the pointer at the start
  of the array. Accesses the array through `*(a + i)`
* `2` - increments the pointer itself in a loop. Accesses the array though
  `*(a++)`

## Results

This experiment was run on 1000 randomly generated numbers (with the same seed).
The results are as below:

| Algorithm | Execution Time |
|-----------|----------------|
|    `0`    |      1513      |
|    `1`    |      1432      |
|    `2`    |      1193      |

This makes sense, as implementation `0` is basically syntactical sugar for
implementation `1`. Thus, it would make sense that `1` is faster by a tiny bit,
as it would take more time to convert the syntax as the numbers got
asymptotically large.

It also makes sense that `2` is faster than both by a significant margin, as
that is incrementing in the pointer, which is generally a faster action. This
also takes advantage of the `++` operator, which is also faster than using the
`+=` operator.
