# Push_swap TODO
## Core functionality
- [ ] Implement argument parsing for multiple arguments and space-separated number strings.
- [ ] Validate integer syntax, signs, range, empty input, and duplicate values.
- [ ] Handle invalid input and allocation failures with the required error output and complete cleanup.
- [ ] Implement stacks A and B, including correct handling of empty and single-element stacks.
- [ ] Implement the 11 required stack operations.
- [ ] Make `push_swap` output operations that sort stack A in ascending order, with the smallest value on top.
- [ ] Produce no output when there are no arguments or the input is already sorted.
## Required strategies
- [ ] Implement the Simple strategy with O(n²) operation-model complexity.
- [ ] Implement the Medium strategy with O(n√n) operation-model complexity.
- [ ] Implement the Complex strategy with O(n log n) operation-model complexity.
- [ ] Add runtime selection for `--simple`, `--medium`, and `--complex`.
- [ ] Measure input disorder before sorting and make the Adaptive strategy select methods that meet the subject's complexity targets for low, medium, and high disorder.
- [ ] Make Adaptive the default strategy and ensure strategy selection works for valid input sizes and disorder levels.
## Project requirements
- [ ] Add a root `README.md` with the required description, instructions, resources and AI-use details, algorithm explanations, and both learners' contributions.
- [ ] Include both learners as repository contributors and ensure both can explain the project.
- [ ] Verify the Makefile builds with the required flags, provides the required targets, and does not relink unnecessarily.
- [ ] Check that allocated memory is released on success and every error path.
## Verification
- [ ] Test malformed input, duplicates, integer limits, overflow, and allocation/error cleanup.
- [ ] Test sorted and unsorted inputs, including 2, 3, and 5 values, with a checker.
- [ ] Test all four strategies on the same inputs and verify that each sorts correctly.
- [ ] Test random inputs of 100 and 500 values against the subject's operation-count limits.
- [ ] Run memory checks and verify there are no leaks or invalid accesses.
- [ ] Verify the Makefile's `all`, `clean`, `fclean`, and `re` rules.
- [ ] Implement and verify the optional `--bench` output if time permits.
