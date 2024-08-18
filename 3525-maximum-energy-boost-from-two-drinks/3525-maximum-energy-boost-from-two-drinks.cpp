class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        // long long res = LONG_LONG_MIN;
        // int n = energyDrinkA.size();
        // for(int i=0; i<n-1; i++) {
        //     if(energyDrinkA[i] == energyDrinkB[i] || energyDrinkA[i+1] < energyDrinkB[i+1]) {
        //         res--;
        //     }
        //     long long m = max(energyDrinkA[i], energyDrinkB[i]);
        //     res += m;
        // }
        // return res;
        int n = energyDrinkA.size();
        
        long long maxA = energyDrinkA[0]; // Start by drinking A
        long long maxB = energyDrinkB[0]; // Start by drinking B
        
        for (int i = 1; i < n; i++) {
            long long newMaxA = max(maxA + energyDrinkA[i], maxB);
            long long newMaxB = max(maxB + energyDrinkB[i], maxA);
            
            maxA = newMaxA;
            maxB = newMaxB;
        }
        
        return max(maxA, maxB);
    }
};