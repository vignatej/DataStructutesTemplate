#include <iostream>
#include <vector>
#include <string>
#include <bitset> // For std::bitset

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // Use a vector of bitsets to store the grid efficiently
    std::vector<std::bitset<3000>> grid_bits(n);

    for (int i = 0; i < n; ++i) {
        std::string row_str;
        std::cin >> row_str;
        // Construct bitset from string.
        // Bitset constructor reads from right to left, so reverse or adjust for direct mapping.
        // For '1' at index j, it should be bit j.
        // Since we want grid[r][c] to map to bitset[c], and string has char at index c,
        // it's naturally correct as long as we consider bitset<N> (where N is actual width).
        // The bitset constructor `std::bitset<N>(string)` treats the 0th character of the string as the N-1th bit
        // and the (N-1)th character as the 0th bit.
        // To map string char at index `j` to `j`th bit, we need to reverse the string.
        // Or, more simply, construct it bit by bit manually.
        // Let's go with manual construction to be safe and clear.
        for (int j = 0; j < n; ++j) {
            if (row_str[j] == '1') {
                grid_bits[i][j] = 1;
            } else {
                grid_bits[i][j] = 0;
            }
        }
    }

    long long beautiful_subgrids_count = 0;

    // Iterate through all pairs of distinct rows (r1, r2)
    for (int r1 = 0; r1 < n; ++r1) {
        for (int r2 = r1 + 1; r2 < n; ++r2) {
            // Compute the bitwise AND of the two rows.
            // This gives a bitset where a bit is set if and only if
            // both grid[r1][c] and grid[r2][c] are '1'.
            std::bitset<3000> common_black_cols = grid_bits[r1] & grid_bits[r2];

            // Count the number of set bits (i.e., common black columns)
            int k = common_black_cols.count();

            // If there are k common black columns, we can choose any 2 of them
            // to form the left and right edges of a beautiful subgrid.
            // The number of ways to choose 2 from k is k * (k - 1) / 2.
            beautiful_subgrids_count += (long long)k * (k - 1) / 2;
        }
    }

    std::cout << beautiful_subgrids_count << std::endl;

    return 0;
}