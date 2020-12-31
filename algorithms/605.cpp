//INNNNoVation!!!
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        for (int i = 0; i < m; i++)
        if (flowerbed[i] == 1)
        {
            if (i > 0 && flowerbed[i - 1] == 0) flowerbed[i - 1] = 2;
            if (i < m - 1 && flowerbed[i + 1] == 0) flowerbed[i + 1] = 2;
        }
        for (int i = 0; i < m; i++)
        if (flowerbed[i] == 0)
        {
            n--;
            if (i < m - 1) flowerbed[i + 1] = 1;
        }
        if (n <= 0) return true;
            else return false;
    }
};