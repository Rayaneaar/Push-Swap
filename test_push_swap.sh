
#!/bin/bash

PASS=0
FAIL=0

make
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

test_error() {
    description="$1"
    shift

    output=$(./push_swap "$@" 2>&1)
    status=$?

    if [ "$output" = "Error" ] && [ "$status" -eq 0 ]; then
        echo "✅ PASS: $description"
        PASS=$((PASS + 1))
    else
        echo "❌ FAIL: $description"
        echo "   Expected: Error"
        echo "   Got: $output"
        FAIL=$((FAIL + 1))
    fi
}

test_valid() {
    description="$1"
    shift

    output=$(./push_swap "$@" 2>&1)

    if ! echo "$output" | grep -q "^Error$"; then
        echo "✅ PASS: $description"
        PASS=$((PASS + 1))
    else
        echo "❌ FAIL: $description"
        echo "   Unexpected Error"
        FAIL=$((FAIL + 1))
    fi
}

echo "======================================"
echo "       PUSH_SWAP TEST SUITE"
echo "======================================"

echo ""
echo "----- VALID INPUTS -----"

test_valid "Multiple positive and negative numbers" 1 3 5 +9 20 -4 50 60 04 08
test_valid "Single string list" "3 4 6 8 9 74 -56 +495"
test_valid "INT MAX" 2147483647 2 4 7
test_valid "INT MIN" 99 -2147483648 23 545
test_valid "INT MAX in string" "2147483647 843 56544 24394"
test_valid "Negative and positive values are different" "95 99 -9 10 9"

echo ""
echo "----- INVALID CHARACTERS -----"

test_error "Word inside arguments" 1 3 dog 35 80 -3
test_error "Single character" a
test_error "Character inside number" 1 2 3 5 67b778 947
test_error "Characters inside string" "12 4 6 8 54fhd 4354"
test_error "Double dash" 1 -- 45 32

echo ""
echo "----- DUPLICATE NUMBERS -----"

test_error "Duplicate number" 1 3 58 9 3
test_error "Leading zero duplicate" 3 03
test_error "Duplicate inside string" "49 128     50 38   49"

echo ""
echo "----- INTEGER OVERFLOW -----"

test_error "Above INT MAX" 54867543867438 3
test_error "Below INT MIN" -2147483647765 4 5
test_error "Overflow inside string" "214748364748385 28 47 29"

echo ""
echo "----- MIXED STRING AND INTEGER ARGUMENTS -----"

test_valid "Mixed string and integer arguments" "1 2 4 3" 76 90 "348 05"

echo ""
echo "======================================"
echo "             TEST RESULTS"
echo "======================================"

TOTAL=$((PASS + FAIL))

echo "PASSED: $PASS"
echo "FAILED: $FAIL"
echo "TOTAL:  $TOTAL"

if [ "$FAIL" -eq 0 ]; then
    echo ""
    echo "🎉 ALL TESTS PASSED!"
else
    echo ""
    echo "⚠️ SOME TESTS FAILED!"
    exit 1
fi

