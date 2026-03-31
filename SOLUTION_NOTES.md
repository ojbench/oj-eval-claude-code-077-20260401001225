# Solution Notes

## Problem Summary
Implement a CrossArray class in C++ that represents a 2D jagged array (arrays with different lengths).

## Implementation Details
- File: src.hpp
- Language: C++
- Namespace: sjtu
- Class: CrossArray

### Key Features Implemented:
1. **Constructor** - Initializes empty jagged array with specified capacity
2. **Copy Constructor** - Deep copies another CrossArray
3. **InsertArrays** - Inserts a new array at the next available position
4. **At** - Access element at [i][j]
5. **AppendArrays** - Extends an existing array with new elements
6. **WhichGreater** - Compares total element counts between two CrossArrays
7. **IsSame** - Checks if two CrossArrays share the same memory
8. **AtArray** - Returns pointer to a specific sub-array
9. **DoubleCrossLength** - Doubles the capacity of the CrossArray
10. **Destructor** - Properly frees all allocated memory

## Submission History
- Attempts 1-4: Failed with Git submission (OJ system bug where Git URL was treated as source code)
- Attempt 5: Submitted source code directly as C++ - **100/100 points achieved**

## Test Results
All 7 test groups passed:
- Group 1 (30%): Constructor, Destructor, InsertArrays
- Group 2 (10%): At function
- Group 3 (15%): Copy constructor
- Group 4 (15%): AppendArrays
- Group 5 (10%): WhichGreater and IsSame
- Group 6 (5%): AtArray
- Group 7 (15%): DoubleCrossLength

**Final Score: 100/100**
