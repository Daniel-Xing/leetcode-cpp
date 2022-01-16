/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (40.04%)
 * Likes:    642
 * Dislikes: 0
 * Total Accepted:    101.1K
 * Total Submissions: 252.5K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * 给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
 * 
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
 * 
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：k = 2, prices = [2,4,1]
 * 输出：2
 * 解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：k = 2, prices = [3,2,6,5,0,3]
 * 输出：7
 * 解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
 * ⁠    随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 =
 * 3 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 0 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size()/2 > k) {
            std::vector<std::vector<int> > buy(k+1, std::vector<int>(prices.size()+1, 0));
            std::vector<std::vector<int> > sell(k+1, std::vector<int>(prices.size()+1, 0));
            int res = INT_MIN;


            for(int K = 0; K <= k ; K ++) {
                for (int i = 0; i <= prices.size(); i ++) {
                    if (K == 0 || i == 0) {
                        sell[K][i] = INT_MIN;
                        continue;
                    }

                    buy[K][i] = max(buy[K][i-1], sell[K][i-1] + prices[i-1]);
                    sell[K][i] = max(sell[K][i-1], buy[K-1][i-1] - prices[i-1]);
                }
                
                if (buy[K][prices.size()] > res) {
                    res = buy[K][prices.size()];
                    // std::cout << K << " " << res << std::endl;
                }
            }
            return res;
        }else{
            int p0, p1;
            p0 = 0;
            p1 = INT_MIN;

            for (int i = 0; i < prices.size(); i ++) {
                int t0 = max(p0, p1 + prices[i]);
                int t1 = max(p1, p0 - prices[i]);
                p0 = t0;
                p1 = t1;
            }
            return p0;
        }
    }
};
// @lc code=end

