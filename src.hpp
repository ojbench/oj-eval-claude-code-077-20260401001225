#ifndef CROSSARRAY_HPP
#define CROSSARRAY_HPP

namespace sjtu {
    class CrossArray {
    private:
        int** arrays;          // Pointer to array of pointers
        int* sizes;            // Array to store size of each sub-array
        int capacity;          // Maximum number of arrays (lines)
        int currentCount;      // Current number of arrays inserted

    public:
        explicit CrossArray(int lines) : capacity(lines), currentCount(0) {
            arrays = new int*[capacity];
            sizes = new int[capacity];
            for (int i = 0; i < capacity; i++) {
                arrays[i] = nullptr;
                sizes[i] = 0;
            }
        }

        CrossArray(const CrossArray& o) : capacity(o.capacity), currentCount(o.currentCount) {
            arrays = new int*[capacity];
            sizes = new int[capacity];

            for (int i = 0; i < capacity; i++) {
                if (o.arrays[i] != nullptr) {
                    sizes[i] = o.sizes[i];
                    arrays[i] = new int[sizes[i]];
                    for (int j = 0; j < sizes[i]; j++) {
                        arrays[i][j] = o.arrays[i][j];
                    }
                } else {
                    arrays[i] = nullptr;
                    sizes[i] = 0;
                }
            }
        }

        CrossArray& WhichGreater(CrossArray& o) {
            int thisTotal = 0;
            int otherTotal = 0;

            for (int i = 0; i < capacity; i++) {
                if (arrays[i] != nullptr) {
                    thisTotal += sizes[i];
                }
            }

            for (int i = 0; i < o.capacity; i++) {
                if (o.arrays[i] != nullptr) {
                    otherTotal += o.sizes[i];
                }
            }

            if (thisTotal >= otherTotal) {
                return *this;
            } else {
                return o;
            }
        }

        bool IsSame(const CrossArray& o) {
            return arrays == o.arrays;
        }

        bool InsertArrays(const int* Input, int size) {
            if (currentCount >= capacity) {
                return false;
            }

            arrays[currentCount] = new int[size];
            sizes[currentCount] = size;

            for (int i = 0; i < size; i++) {
                arrays[currentCount][i] = Input[i];
            }

            currentCount++;
            return true;
        }

        void AppendArrays(const int* Input, int Line, int size) {
            int oldSize = sizes[Line];
            int newSize = oldSize + size;

            int* newArray = new int[newSize];

            // Copy old elements
            for (int i = 0; i < oldSize; i++) {
                newArray[i] = arrays[Line][i];
            }

            // Copy new elements
            for (int i = 0; i < size; i++) {
                newArray[oldSize + i] = Input[i];
            }

            delete[] arrays[Line];
            arrays[Line] = newArray;
            sizes[Line] = newSize;
        }

        void DoubleCrossLength() {
            int newCapacity = capacity * 2;
            int** newArrays = new int*[newCapacity];
            int* newSizes = new int[newCapacity];

            // Copy old arrays
            for (int i = 0; i < capacity; i++) {
                newArrays[i] = arrays[i];
                newSizes[i] = sizes[i];
            }

            // Initialize new arrays to nullptr
            for (int i = capacity; i < newCapacity; i++) {
                newArrays[i] = nullptr;
                newSizes[i] = 0;
            }

            delete[] arrays;
            delete[] sizes;

            arrays = newArrays;
            sizes = newSizes;
            capacity = newCapacity;
        }

        const int* AtArray(int i) {
            return arrays[i];
        }

        int& At(int i, int j) {
            return arrays[i][j];
        }

        ~CrossArray() {
            for (int i = 0; i < capacity; i++) {
                if (arrays[i] != nullptr) {
                    delete[] arrays[i];
                }
            }
            delete[] arrays;
            delete[] sizes;
        }
    };
}

#endif
