#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool Bouquets(const std::vector<int>& bloomDay, int m, int k, int days) {
        long long bouquets = 0;
        long long flowers_in_bouquet = 0;
        
        for (int i = 0; i < bloomDay.size(); ++i) {
            if (bloomDay[i] <= days) {
                ++flowers_in_bouquet;
                if (flowers_in_bouquet == k) {
                    ++bouquets;
                    flowers_in_bouquet = 0;
                }
            } else {
                flowers_in_bouquet = 0;
            }
        }
        
        return bouquets >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k){
        long long bouquets = 0;
        int n = bloomDay.size();
        if(static_cast<long long>(n) < static_cast<long long>(m)*k){
            return -1;
        }
        long long left = 1;
        long long right = *max_element(bloomDay.begin(), bloomDay.end());
        long long min_days = right;
        while(left <= right){
            long long mid = left + (right - left) / 2;
            if(Bouquets(bloomDay, m, k, mid)){
                min_days = mid;
                right = mid - 1;
            } else{
                left = mid + 1;
            }
        }
        return min_days;
    }
};


//Example Testcase
int main(){
    Solution sol;
    vector<int> bloomDay = {7,7,7,7,12,7,7};
    int m = 2, k = 3;
    cout << sol.minDays(bloomDay, m, k) << endl;
    return 0;
}