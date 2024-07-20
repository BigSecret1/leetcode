class Solution {
public:
    int findTheWinner(int n, int k) {
        // Initialize vector of N friends, labeled from 1-N
        vector<int> circle;
        for (int i = 1; i <= n; i++) {
            circle.push_back(i);
        }

        // Maintain the index of the friend to start the count on
        int startIndex = 0;

        // Perform eliminations while there is more than 1 friend left
        while (circle.size() > 1) {
            // Calculate the index of the friend to be removed
            int removalIndex = (startIndex + k - 1) % circle.size();
            // Erase the friend at removalIndex
            circle.erase(circle.begin() + removalIndex);

            // Update startIndex for the next round
            startIndex = removalIndex;
        }

        return circle.front();
    }
};


// Breaks the problem into sub problem and solve 
class Solution {
public:
    int findTheWinner(int n, int k) {
        // Initialize vector of N friends, labeled from 1-N
        return Recurs(n, k) + 1;
    }

    int Recurs(int n, int k) {
        if(n == 0) return 0;
        return ((Recurs(n - 1, k) + k) % n);
    }
};
