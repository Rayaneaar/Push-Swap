# Push_swap TODO

## 1. Core Functionality
- [x] Implement argument parsing for multiple arguments and space-separated number strings.
- [x] Validate integer syntax, signs, range, empty input, and duplicate values.
- [ ] Handle invalid input and allocation failures with the required error output and complete cleanup.
- [x] Optimise parsing code, structure and logic.

## 2. Stack Implementation
- [ ] Implement Stack A and Stack B.
- [ ] Implement the 11 required operations (pa, pb, sa, sb, ss, ra, rb, rr, rra, rrb, rrr).
- [ ] Handle empty and single-element stacks.
- [ ] Test all stack operations.

## 3. Sorting Algorithms
- [ ] Implement Simple strategy — O(n²).
- [ ] Implement Medium strategy — O(n√n).
- [ ] Implement Complex strategy — O(n log n).
- [ ] Test each strategy independently.

## 4. Disorder & Adaptive Strategy
- [ ] Measure input disorder before sorting.
- [ ] Implement Adaptive strategy.
- [ ] Select sorting methods based on input disorder.
- [ ] Make Adaptive the default strategy.
- [ ] Ensure all strategies work with valid input sizes and disorder levels.

## 5. Program Options & Output
- [ ] Implement --simple, --medium, and --complex.
- [ ] Separate operation logic from printing.
- [ ] Print operations that sort A in ascending order (smallest on top).
- [ ] Produce no output when there are no arguments.
- [ ] Produce no output when input is already sorted.

## 6. Benchmark Mode (--bench)
- [ ] Implement the optional --bench flag.
- [ ] Display computed disorder as a percentage with two decimal places.
- [ ] Display the strategy name and its theoretical complexity.
- [ ] Display the total number of operations.
- [ ] Display the count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr).
- [ ] Send all benchmark information to stderr.
- [ ] Display benchmark information only when --bench is present.
- [ ] Verify benchmark counts match the actual operations performed.

## 7. Verification
- [ ] Test malformed input, duplicates, integer limits, overflow, and allocation failures.
- [ ] Test sorted and unsorted inputs, including 2, 3, and 5 values, with a checker.
- [ ] Test all four strategies on identical inputs.
- [ ] Test random inputs of 100 and 500 values against operation-count limits.
- [ ] Run memory checks and verify there are no leaks or invalid accesses.
- [ ] Verify Makefile all, clean, fclean, and re rules.
- [ ] Implement and verify optional --bench output if time permits.
- [ ] Review, check norm and remove deadcode and add README.md

## 8. SALINA, Lhlwaaa, LGTM, lbradia na3s
- [ ] 3dbni wrk 3liya
