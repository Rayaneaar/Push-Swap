

#!/usr/bin/env python3

import subprocess
import sys
import re

PROGRAM = "./push_swap"
TIMEOUT = 5

INT_MIN = -2147483648
INT_MAX = 2147483647

TESTS = [
    # VALID INPUTS
    ("multiple arguments", ["1", "3", "5", "+9", "20", "-4", "50", "60", "04", "08"], True),
    ("quoted list", ["3 4 6 8 9 74 -56 +495"], True),
    ("negative and positive", ["95 99 -9 10 9"], True),
    ("INT_MAX", ["2147483647", "2", "4", "7"], True),
    ("INT_MIN", ["99", "-2147483648", "23", "545"], True),
    ("INT boundaries in string", ["2147483647 -2147483648 0"], True),
    ("already sorted", ["1", "2", "3", "4"], True),
    ("reverse sorted", ["4", "3", "2", "1"], True),
    ("single number", ["42"], True),
    ("zero", ["0"], True),
    ("spaces around numbers", ["  12  4  6  8  "], True),
    ("multiple quoted arguments", ["1 2", "3 4"], True),
    ("mixed arguments", ["1 2 3", "4", "5"], True),
    ("plus sign", ["+42", "-42"], True),
    ("leading zeroes", ["01", "002", "0003"], True),

    # INVALID CHARACTERS
    ("word among numbers", ["1", "3", "dog", "35", "80", "-3"], False),
    ("single letter", ["a"], False),
    ("letter inside number", ["1", "2", "67b778", "947"], False),
    ("letters in quoted list", ["12 4 6 8 54fhd 4354"], False),
    ("double dash", ["1", "--", "45", "32"], False),
    ("decimal number", ["1.5", "2", "3"], False),
    ("embedded plus", ["1+2"], False),
    ("embedded minus", ["1-2"], False),
    ("double plus", ["++42"], False),
    ("double minus", ["--42"], False),
    ("plus only", ["+"], False),
    ("minus only", ["-"], False),
    ("empty argument", [""], False),
    ("whitespace only", ["   "], False),

    # DUPLICATES
    ("duplicate integer", ["1", "3", "58", "9", "3"], False),
    ("duplicate with leading zero", ["3", "03"], False),
    ("duplicate in quoted list", ["49 128 50 38 49"], False),
    ("duplicate zero", ["0", "00"], False),
    ("positive duplicate", ["+5", "5"], False),
    ("negative duplicate", ["-5", "-05"], False),
    ("duplicate across arguments", ["1 2", "3", "02"], False),
    ("duplicate INT_MAX", ["2147483647", "2147483647"], False),
    ("duplicate INT_MIN", ["-2147483648", "-2147483648"], False),

    # OVERFLOW / UNDERFLOW
    ("positive overflow", ["54867543867438", "3"], False),
    ("negative underflow", ["-2147483647765", "4", "5"], False),
    ("overflow in quoted list", ["214748364748385 28 47 29"], False),
    ("INT_MAX + 1", ["2147483648"], False),
    ("INT_MIN - 1", ["-2147483649"], False),
    ("huge positive", ["999999999999999999999999"], False),
    ("huge negative", ["-999999999999999999999999"], False),
    ("huge positive in list", ["1 999999999999999999999999 3"], False),
    ("huge negative in list", ["1 -999999999999999999999999 3"], False),
]


def parse_args(argv):
    values = []

    for arg in argv:
        tokens = arg.split()

        for token in tokens:
            if not re.fullmatch(r"[+-]?[0-9]+", token):
                raise ValueError("invalid character")

            number = int(token)

            if number < INT_MIN or number > INT_MAX:
                raise OverflowError("integer out of range")

            values.append(number)

    if not values:
        raise ValueError("empty input")

    if len(values) != len(set(values)):
        raise ValueError("duplicate numbers")

    return values


def is_exact_error(result):
    return (
        result.stdout == "Error\n" and result.stderr == ""
    ) or (
        result.stderr == "Error\n" and result.stdout == ""
    )


def simulate(numbers, output):
    a = list(numbers)
    b = []

    operations = {
        "sa", "sb", "ss",
        "pa", "pb",
        "ra", "rb", "rr",
        "rra", "rrb", "rrr"
    }

    for line_number, op in enumerate(output.splitlines(), 1):

        if op not in operations:
            return False, f"invalid instruction {op!r} at line {line_number}"

        if op == "sa":
            if len(a) > 1:
                a[0], a[1] = a[1], a[0]

        elif op == "sb":
            if len(b) > 1:
                b[0], b[1] = b[1], b[0]

        elif op == "ss":
            if len(a) > 1:
                a[0], a[1] = a[1], a[0]
            if len(b) > 1:
                b[0], b[1] = b[1], b[0]

        elif op == "pa":
            if b:
                a.insert(0, b.pop(0))

        elif op == "pb":
            if a:
                b.insert(0, a.pop(0))

        elif op == "ra":
            if a:
                a.append(a.pop(0))

        elif op == "rb":
            if b:
                b.append(b.pop(0))

        elif op == "rr":
            if a:
                a.append(a.pop(0))
            if b:
                b.append(b.pop(0))

        elif op == "rra":
            if a:
                a.insert(0, a.pop())

        elif op == "rrb":
            if b:
                b.insert(0, b.pop())

        elif op == "rrr":
            if a:
                a.insert(0, a.pop())
            if b:
                b.insert(0, b.pop())

    if b:
        return False, f"stack B is not empty: {b}"

    if a != sorted(numbers):
        return False, f"incorrect final stack: {a}"

    return True, ""

def run_test(description, argv, expected_valid):

    try:
        numbers = parse_args(argv)
        input_is_valid = True
    except (ValueError, OverflowError):
        numbers = None
        input_is_valid = False

    if input_is_valid != expected_valid:
        print(f"TEST ERROR: {description} is incorrectly classified")
        return False

    try:
        result = subprocess.run(
            [PROGRAM] + argv,
            capture_output=True,
            text=True,
            timeout=TIMEOUT
        )

    except subprocess.TimeoutExpired:
        print(f"FAIL  {description}: timeout")
        return False

    except FileNotFoundError:
        print(f"FAIL  Cannot find {PROGRAM}. Run make first.")
        return None

    # Invalid inputs
    if not expected_valid:
        if is_exact_error(result):
            print(f"PASS  {description}")
            return True

        print(
            f"FAIL  {description}: expected exactly Error\\n\n"
            f"      stdout: {result.stdout!r}\n"
            f"      stderr: {result.stderr!r}"
        )
        return False

    # Valid inputs
    if result.returncode != 0:
        print(f"FAIL  {description}: exit code {result.returncode}")
        return False

    if result.stderr:
        print(f"FAIL  {description}: unexpected stderr {result.stderr!r}")
        return False

    output = result.stdout.strip()

    if output == "Error":
        print(f"FAIL  {description}: valid input rejected")
        return False

    # MODE 1: Parser/debug output (numbers)
    try:
        output_numbers = [int(token) for token in output.split()]
        numeric_output = bool(output.split())
    except ValueError:
        output_numbers = []
        numeric_output = False

    if numeric_output:
        if output_numbers != numbers:
            print(
                f"FAIL  {description}: parsed numbers incorrect\n"
                f"      Expected: {numbers}\n"
                f"      Received: {output_numbers}"
            )
            return False

        print(f"PASS  {description} [PARSER]")
        return True

    # MODE 2: Push_swap instruction output
    success, reason = simulate(numbers, result.stdout)

    if not success:
        print(f"FAIL  {description}: {reason}")
        return False

    print(f"PASS  {description} [SORTING]")
    return True
def main():

    try:
        subprocess.run(
            [PROGRAM],
            capture_output=True,
            timeout=TIMEOUT
        )
    except FileNotFoundError:
        print(f"Cannot find {PROGRAM}. Run make first.")
        return 1

    print("\n========== PUSH_SWAP TESTER ==========\n")

    passed = 0
    failed = 0

    for description, argv, expected_valid in TESTS:

        result = run_test(description, argv, expected_valid)

        if result is True:
            passed += 1
        else:
            failed += 1

    total = passed + failed

    print("\n======================================")
    print(f"TOTAL:  {total}")
    print(f"PASSED: {passed}")
    print(f"FAILED: {failed}")
    print("======================================")

    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
