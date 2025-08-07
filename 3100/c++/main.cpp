class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int remaining = numBottles;
        int total_drank = 0;
        while(remaining >= numExchange)
        {
            remaining -= numExchange;
            total_drank += numExchange;
            numExchange++;
            remaining++;
        }

        return total_drank + remaining;
    }
};