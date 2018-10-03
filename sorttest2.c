#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* Program which reads numbers from the command line,
 * outputs them, sorts them in descending order, and outputs the sorted list.
 *
 * Usage:
 *         ./sorttest number_of_numbers sorting_algorithm
 * Example:
 *         ./sorttest 2014 2
 *
 * The sorting algorithm choices are as follows:
 * 0 - The default implementation
 * 1 - Adding to the index instead of incrementing the indext
 * 2 - Incrementing pointers.
 *
 */

/** Main program
 * @param argc Number of words on the command line
 * @param argv[] Array of character strings, the words from the command line.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

int main (int argc, const char* argv[]) {

  int *nums; // space to store numbers entered from the command line.

  int i; // array index 
  int num_nums; // How many numbers actually entered on the command line.

  // Check that there are at least two numbers
  if (argc - 1 < 2 || argc - 1 > 3) { 
    printf("Please enter the number of numbers as well as which sorting");
    printf(" algorithm to use (the range is [0, 2])\n");
    return 1; // Indicate failure
  }

  num_nums = atoi(argv[1]);
	int sortingChoice = atoi(argv[2]);

  // Allocate an array big enough to hold the numbers
  nums = (int*) calloc(num_nums, sizeof(int));
  if (nums == NULL) {
    fprintf(stderr, "Unable to allocate enough memory to hold the numbers.\n");
  }

  for (i = 0; i < num_nums; i++) {
    nums[i] = rand();
  }

  // Now print, sort, and print the array, and time how long the sorting took.
  timesort(nums, num_nums, sortingChoice);

  return 0; // Indicate success!
}
