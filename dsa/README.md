# 300 C++ DSA Problems

Three hundred data-structures-and-algorithms problems solved in C++, organised by
topic. Every file is **self-contained and runnable**: it carries the problem
statement, the reasoning behind the approach, the time and space complexity, the
solution, and a `main()` that exercises it with sample input and the expected
output in a trailing comment.

## Building

Any single file compiles and runs on its own:

```bash
g++ -std=c++14 -O2 01_arrays/001_two_sum.cpp -o two_sum
./two_sum
```

To build and run everything:

```bash
for f in $(find . -name '*.cpp' | sort); do
  g++ -std=c++14 -O2 "$f" -o /tmp/a.out && /tmp/a.out
done
```

All 300 files compile warning-free with GCC 6.3 (`-std=c++14`) and run to
completion.

## Contents

### Arrays (35 problems)

| # | Problem | Difficulty |
|---|---------|------------|
| 001 | [Two Sum](01_arrays/001_two_sum.cpp) | Easy |
| 002 | [Best Time to Buy and Sell Stock](01_arrays/002_best_time_to_buy_and_sell_stock.cpp) | Easy |
| 003 | [Maximum Subarray (Kadane's Algorithm)](01_arrays/003_maximum_subarray_kadane.cpp) | Medium |
| 004 | [Move Zeroes](01_arrays/004_move_zeroes.cpp) | Easy |
| 005 | [Rotate Array by K Steps](01_arrays/005_rotate_array_by_k.cpp) | Medium |
| 006 | [Find the Duplicate Number](01_arrays/006_find_duplicate_number.cpp) | Medium |
| 007 | [Merge Intervals](01_arrays/007_merge_intervals.cpp) | Medium |
| 008 | [Product of Array Except Self](01_arrays/008_product_of_array_except_self.cpp) | Medium |
| 009 | [Container With Most Water](01_arrays/009_container_with_most_water.cpp) | Medium |
| 010 | [Trapping Rain Water](01_arrays/010_trapping_rain_water.cpp) | Hard |
| 011 | [3Sum](01_arrays/011_three_sum.cpp) | Medium |
| 012 | [Majority Element (Boyer-Moore Voting)](01_arrays/012_majority_element_moore.cpp) | Easy |
| 013 | [Sort Colors (Dutch National Flag)](01_arrays/013_sort_colors_dutch_flag.cpp) | Medium |
| 014 | [Next Permutation](01_arrays/014_next_permutation.cpp) | Medium |
| 015 | [Set Matrix Zeroes](01_arrays/015_set_matrix_zeroes.cpp) | Medium |
| 016 | [Spiral Matrix](01_arrays/016_spiral_matrix.cpp) | Medium |
| 017 | [Rotate Image by 90 Degrees](01_arrays/017_rotate_image_90.cpp) | Medium |
| 018 | [Max Consecutive Ones III](01_arrays/018_max_consecutive_ones_iii.cpp) | Medium |
| 019 | [Subarray Sum Equals K](01_arrays/019_subarray_sum_equals_k.cpp) | Medium |
| 020 | [Longest Consecutive Sequence](01_arrays/020_longest_consecutive_sequence.cpp) | Medium |
| 021 | [Maximum Product Subarray](01_arrays/021_maximum_product_subarray.cpp) | Medium |
| 022 | [Merge Sorted Array (in place)](01_arrays/022_merge_sorted_arrays_in_place.cpp) | Easy |
| 023 | [Missing Number](01_arrays/023_missing_number.cpp) | Easy |
| 024 | [Find All Duplicates in an Array](01_arrays/024_find_all_duplicates_in_array.cpp) | Medium |
| 025 | [First Missing Positive](01_arrays/025_first_missing_positive.cpp) | Hard |
| 026 | [Pascal's Triangle](01_arrays/026_pascals_triangle.cpp) | Easy |
| 027 | [Insert Interval](01_arrays/027_insert_interval.cpp) | Medium |
| 028 | [Non-overlapping Intervals](01_arrays/028_non_overlapping_intervals.cpp) | Medium |
| 029 | [4Sum](01_arrays/029_four_sum.cpp) | Medium |
| 030 | [Two Sum II (Sorted Input)](01_arrays/030_two_sum_ii_sorted.cpp) | Medium |
| 031 | [Minimum Size Subarray Sum](01_arrays/031_minimum_size_subarray_sum.cpp) | Medium |
| 032 | [Maximum Sum Subarray of Size K](01_arrays/032_max_sum_subarray_size_k.cpp) | Easy |
| 033 | [Rearrange Array Elements by Sign](01_arrays/033_rearrange_array_by_sign.cpp) | Medium |
| 034 | [Maximum Sum Circular Subarray](01_arrays/034_maximum_circular_subarray_sum.cpp) | Medium |
| 035 | [Best Time to Buy and Sell Stock II](01_arrays/035_stock_buy_sell_multiple.cpp) | Medium |

### Strings (25 problems)

| # | Problem | Difficulty |
|---|---------|------------|
| 036 | [Reverse String](02_strings/036_reverse_string.cpp) | Easy |
| 037 | [Valid Palindrome](02_strings/037_valid_palindrome.cpp) | Easy |
| 038 | [Valid Anagram](02_strings/038_valid_anagram.cpp) | Easy |
| 039 | [Longest Substring Without Repeating Characters](02_strings/039_longest_substring_without_repeating.cpp) | Medium |
| 040 | [Longest Palindromic Substring](02_strings/040_longest_palindromic_substring.cpp) | Medium |
| 041 | [Group Anagrams](02_strings/041_group_anagrams.cpp) | Medium |
| 042 | [String Compression (Run-Length Encoding)](02_strings/042_string_compression.cpp) | Medium |
| 043 | [KMP Pattern Searching](02_strings/043_kmp_pattern_search.cpp) | Hard |
| 044 | [Longest Common Prefix](02_strings/044_longest_common_prefix.cpp) | Easy |
| 045 | [Roman to Integer](02_strings/045_roman_to_integer.cpp) | Easy |
| 046 | [Integer to Roman](02_strings/046_integer_to_roman.cpp) | Medium |
| 047 | [Zigzag Conversion](02_strings/047_zigzag_conversion.cpp) | Medium |
| 048 | [Count and Say](02_strings/048_count_and_say.cpp) | Medium |
| 049 | [Minimum Window Substring](02_strings/049_minimum_window_substring.cpp) | Hard |
| 050 | [Permutation in String](02_strings/050_permutation_in_string.cpp) | Medium |
| 051 | [Find All Anagrams in a String](02_strings/051_find_all_anagrams_in_string.cpp) | Medium |
| 052 | [Isomorphic Strings](02_strings/052_isomorphic_strings.cpp) | Easy |
| 053 | [String to Integer (atoi)](02_strings/053_string_to_integer_atoi.cpp) | Medium |
| 054 | [Multiply Strings](02_strings/054_multiply_strings.cpp) | Medium |
| 055 | [Add Binary](02_strings/055_add_binary.cpp) | Easy |
| 056 | [Longest Repeating Character Replacement](02_strings/056_longest_repeating_char_replacement.cpp) | Medium |
| 057 | [Reverse Words in a String](02_strings/057_reverse_words_in_string.cpp) | Medium |
| 058 | [Rabin-Karp Substring Search](02_strings/058_rabin_karp.cpp) | Medium |
| 059 | [Z-Algorithm Pattern Search](02_strings/059_z_algorithm.cpp) | Hard |
| 060 | [Rotate String](02_strings/060_rotate_string_check.cpp) | Easy |

### Linked List (20 problems)

| # | Problem | Difficulty |
|---|---------|------------|
| 061 | [Reverse a Linked List](03_linked_list/061_reverse_linked_list.cpp) | Easy |
| 062 | [Middle of the Linked List](03_linked_list/062_middle_of_linked_list.cpp) | Easy |
| 063 | [Linked List Cycle Detection](03_linked_list/063_detect_cycle.cpp) | Easy |
| 064 | [Find the Node Where the Cycle Begins](03_linked_list/064_cycle_start_node.cpp) | Medium |
| 065 | [Merge Two Sorted Lists](03_linked_list/065_merge_two_sorted_lists.cpp) | Easy |
| 066 | [Remove Nth Node From End of List](03_linked_list/066_remove_nth_from_end.cpp) | Medium |
| 067 | [Palindrome Linked List](03_linked_list/067_palindrome_linked_list.cpp) | Easy |
| 068 | [Intersection of Two Linked Lists](03_linked_list/068_intersection_of_two_lists.cpp) | Easy |
| 069 | [Add Two Numbers](03_linked_list/069_add_two_numbers.cpp) | Medium |
| 070 | [Remove Duplicates from Sorted List](03_linked_list/070_remove_duplicates_sorted_list.cpp) | Easy |
| 071 | [Remove Duplicates from Sorted List II](03_linked_list/071_remove_duplicates_ii.cpp) | Medium |
| 072 | [Odd Even Linked List](03_linked_list/072_odd_even_linked_list.cpp) | Medium |
| 073 | [Rotate List](03_linked_list/073_rotate_list.cpp) | Medium |
| 074 | [Reverse Nodes in k-Group](03_linked_list/074_reverse_nodes_in_k_group.cpp) | Hard |
| 075 | [Sort List (Merge Sort on a Linked List)](03_linked_list/075_sort_list_merge_sort.cpp) | Medium |
| 076 | [Copy List with Random Pointer](03_linked_list/076_copy_list_with_random_pointer.cpp) | Medium |
| 077 | [Partition List](03_linked_list/077_partition_list.cpp) | Medium |
| 078 | [Reorder List](03_linked_list/078_reorder_list.cpp) | Medium |
| 079 | [Merge k Sorted Lists](03_linked_list/079_merge_k_sorted_lists.cpp) | Hard |
| 080 | [Swap Nodes in Pairs](03_linked_list/080_swap_nodes_in_pairs.cpp) | Medium |

### Stack Queue (18 problems)

| # | Problem | Difficulty |
|---|---------|------------|
| 081 | [Valid Parentheses](04_stack_queue/081_valid_parentheses.cpp) | Easy |
| 082 | [Min Stack](04_stack_queue/082_min_stack.cpp) | Medium |
| 083 | [Next Greater Element](04_stack_queue/083_next_greater_element.cpp) | Medium |
| 084 | [Largest Rectangle in Histogram](04_stack_queue/084_largest_rectangle_in_histogram.cpp) | Hard |
| 085 | [Evaluate Reverse Polish Notation](04_stack_queue/085_evaluate_reverse_polish_notation.cpp) | Medium |
| 086 | [Daily Temperatures](04_stack_queue/086_daily_temperatures.cpp) | Medium |
| 087 | [Implement Queue using Stacks](04_stack_queue/087_queue_using_stacks.cpp) | Easy |
| 088 | [Implement Stack using Queues](04_stack_queue/088_stack_using_queues.cpp) | Easy |
| 089 | [Sliding Window Maximum](04_stack_queue/089_sliding_window_maximum.cpp) | Hard |
| 090 | [Asteroid Collision](04_stack_queue/090_asteroid_collision.cpp) | Medium |
| 091 | [Remove K Digits](04_stack_queue/091_remove_k_digits.cpp) | Medium |
| 092 | [Decode String](04_stack_queue/092_decode_string.cpp) | Medium |
| 093 | [Simplify Path](04_stack_queue/093_simplify_path.cpp) | Medium |
| 094 | [Online Stock Spanner](04_stack_queue/094_stock_spanner.cpp) | Medium |
| 095 | [Sum of Subarray Minimums](04_stack_queue/095_sum_of_subarray_minimums.cpp) | Medium |
| 096 | [Trapping Rain Water (Monotonic Stack)](04_stack_queue/096_trapping_rain_water_stack.cpp) | Hard |
| 097 | [Design Circular Queue](04_stack_queue/097_circular_queue.cpp) | Medium |
| 098 | [LRU Cache](04_stack_queue/098_lru_cache.cpp) | Medium |

### Recursion Backtracking (17 problems)

| # | Problem | Difficulty |
|---|---------|------------|
| 099 | [Subsets (Power Set)](05_recursion_backtracking/099_subsets.cpp) | Medium |
| 100 | [Subsets II (with Duplicates)](05_recursion_backtracking/100_subsets_with_duplicates.cpp) | Medium |
| 101 | [Permutations](05_recursion_backtracking/101_permutations.cpp) | Medium |
| 102 | [Permutations II (with Duplicates)](05_recursion_backtracking/102_permutations_with_duplicates.cpp) | Medium |
| 103 | [Combination Sum](05_recursion_backtracking/103_combination_sum.cpp) | Medium |
| 104 | [Combination Sum II](05_recursion_backtracking/104_combination_sum_ii.cpp) | Medium |
| 105 | [N-Queens](05_recursion_backtracking/105_n_queens.cpp) | Hard |
| 106 | [Sudoku Solver](05_recursion_backtracking/106_sudoku_solver.cpp) | Hard |
| 107 | [Word Search](05_recursion_backtracking/107_word_search.cpp) | Medium |
| 108 | [Rat in a Maze](05_recursion_backtracking/108_rat_in_a_maze.cpp) | Medium |
| 109 | [Generate Parentheses](05_recursion_backtracking/109_generate_parentheses.cpp) | Medium |
| 110 | [Letter Combinations of a Phone Number](05_recursion_backtracking/110_letter_combinations_phone.cpp) | Medium |
| 111 | [Palindrome Partitioning](05_recursion_backtracking/111_palindrome_partitioning.cpp) | Medium |
| 112 | [Tower of Hanoi](05_recursion_backtracking/112_tower_of_hanoi.cpp) | Easy |
| 113 | [Josephus Problem](05_recursion_backtracking/113_josephus_problem.cpp) | Medium |
| 114 | [Permutation Sequence](05_recursion_backtracking/114_kth_permutation_sequence.cpp) | Hard |
| 115 | [Restore IP Addresses](05_recursion_backtracking/115_restore_ip_addresses.cpp) | Medium |

### Binary Search (18 problems)

| # | Problem | Difficulty |
|---|---------|------------|
| 116 | [Binary Search](06_binary_search/116_binary_search.cpp) | Easy |
| 117 | [Find First and Last Position of Element in Sorted Array](06_binary_search/117_first_and_last_position.cpp) | Medium |
| 118 | [Search in Rotated Sorted Array](06_binary_search/118_search_rotated_sorted_array.cpp) | Medium |
| 119 | [Search in Rotated Sorted Array II (with Duplicates)](06_binary_search/119_search_rotated_sorted_array_ii.cpp) | Medium |
| 120 | [Find Minimum in Rotated Sorted Array](06_binary_search/120_find_min_in_rotated_array.cpp) | Medium |
| 121 | [Find Peak Element](06_binary_search/121_find_peak_element.cpp) | Medium |
| 122 | [Search Insert Position](06_binary_search/122_search_insert_position.cpp) | Easy |
| 123 | [Integer Square Root](06_binary_search/123_sqrt_binary_search.cpp) | Easy |
