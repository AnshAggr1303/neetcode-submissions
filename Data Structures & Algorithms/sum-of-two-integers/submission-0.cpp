class Solution {
public:
    int getSum(int a, int b) {

        // Keep going until there is no carry left
        while (b != 0) {

            // XOR gives the sum without considering carry
            int sum = a ^ b;

            // AND finds the carry bits, then shift left because
            // carry is added to the next higher bit
            int carry = (a & b) << 1;

            // Update a with the current sum
            a = sum;

            // Update b with the carry for the next iteration
            b = carry;
        }

        // When carry becomes 0, a contains the final answer
        return a;
    }
};