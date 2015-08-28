using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace LTC165
{
    class Program
    {
        static void Main(string[] args)
        {
            string a = "1",b = "1.1";
            int res = CompareVersion(a, b);
        }
        static int CompareVersion(string version1, string version2)
        {
            string[] first = version1.Split(".".ToCharArray());
            string[] last = version2.Split(".".ToCharArray());
            int i = 0;
            while (i < Math.Min(first.Length,last.Length))
            {
                int a = Convert.ToInt32(first[i]);
                int b = Convert.ToInt32(last[i]);
                if (a > b)
                {
                    return 1;
                }
                if (a < b)
                    return -1;
                i++;
            }
            if (first.Length > last.Length && !IsAllZero(i,first))
                return 1;
            if (first.Length < last.Length && !IsAllZero(i,last))
                return -1;
            return 0;
        }

        static bool IsAllZero(int pos, string[] arrstr)
        {
            while (pos < arrstr.Length)
            {
                int a = Convert.ToInt32(arrstr[pos]);
                if (a != 0)
                    return false;
                pos++;
            }
            return true;
        }
    }
}
