using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace LTC139
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            string temp = "leetcode";
            HashSet<string> wordDict = new HashSet<string>();
            wordDict.Add("leet");
            wordDict.Add("code");
            bool flag = s.WordBreak(temp,wordDict);
        }
    }
    public class Solution
    {
        public bool WordBreak(string s, ISet<string> wordDict)
        {
            bool[] dp = new bool[s.Length + 1];
            dp[0] = true;
            for(int i = 1;i <= s.Length;i++)
            {
                string first = s.Substring(0,i);
                if(wordDict.Contains(first))
                {
                    dp[i] = true;
                    continue;
                }
                for(int k = 1;k <= i;k++)
                {
                    string temp = s.Substring(k, i - k);
                    if(dp[k] && wordDict.Contains(temp))
                    {
                        dp[i] = true;
                        break;
                    }
                }                
            }
            return dp[s.Length];
        }
    }
}
