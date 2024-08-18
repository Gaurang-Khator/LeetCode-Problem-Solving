class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {

        int n = energyDrinkA.size();
        
        long long maxA = energyDrinkA[0]; 
        long long maxB = energyDrinkB[0]; 
        
        for (int i = 1; i < n; i++) {
            long long newMaxA = max(maxA + energyDrinkA[i], maxB);
            long long newMaxB = max(maxB + energyDrinkB[i], maxA);
            
            maxA = newMaxA;
            maxB = newMaxB;
        }
        
        return max(maxA, maxB);
    }
};