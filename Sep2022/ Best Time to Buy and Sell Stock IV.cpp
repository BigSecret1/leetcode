class Solution {
public:
	int dp[1002][102][2];
	int n;
    int maxProfit(int k, vector<int>& prices) {
		n = prices.size();
		memset(dp, -1, sizeof(dp));
		if(n <= 1 || k == 0) return 0;
		return Recurs(0, 1, k, 1, prices);
    }
    
    int Recurs(int idx, int cnt, int k, int buy, vector<int> prices) {
		if(idx == n || cnt == k + 1) return 0;
		if(dp[idx][cnt][buy] != -1) return dp[idx][cnt][buy];
		int profit = 0;
		cout << idx << endl;
		if(buy) {
			int buyed = -prices[idx] + Recurs(idx + 1, cnt, k, 0, prices);
			int notBuyed = Recurs(idx + 1, cnt, k, 1, prices);
			profit = max(buyed, notBuyed);
			}
			else  {
			   int sell = prices[idx] + Recurs(idx + 1, cnt + 1, k, 1, prices);
			   int notSell = Recurs(idx + 1, cnt, k, 0, prices);
			   profit = max(sell, notSell);
				}
				//cout << profit << nedl;
				return dp[idx][cnt][buy] = profit;
		}
    
};

