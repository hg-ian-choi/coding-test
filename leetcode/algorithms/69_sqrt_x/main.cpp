#include <cmath>

class SqrtX {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        long low = 1;
        long high = x;

        while (low <= high) {
            long mid = (low + high) / 2;

            if (mid == x / mid) {
                return (int)mid;
            } else if (mid > x / mid) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)high;
    }


    // Solution
    // Solution 1
    int solution1(int x) {
        long r = x;
        while (r * r > x) {
            r = (r + x / r) / 2;
        }
        return r;
    }

    // Solution 2
    int solution2(int x) {
        // For special cases when x is 0 or 1, return x.
        if (x == 0 || x == 1) {
            return x;
        }

        // Initialize the search range for the square root.
        int start = 1;
        int end = x;
        int mid = -1;

        // Perform binary search to find the square root of x.
        while (start <= end) {
            // Calculate the middle point using "start + (end - start) / 2" to avoid integer overflow.
            mid = start + (end - start) / 2;

            // Convert mid to long to handle large values without overflow.
            long long square = static_cast<long long>(mid) * mid;

            // If the square of the middle value is greater than x, move the "end" to the left (mid - 1).
            if (square > x) {
                end = mid - 1;
            } else if (square == x) {
                // If the square of the middle value is equal to x, we found the square root.
                return mid;
            } else {
                // If the square of the middle value is less than x, move the "start" to the right (mid + 1).
                start = mid + 1;
            }
        }

        // The loop ends when "start" becomes greater than "end", and "end" is the integer value of the square root.
        // However, since we might have been using integer division in the calculations,
        // we round down the value of "end" to the nearest integer to get the correct square root.
        return static_cast<int>(std::round(end));
    }
};
