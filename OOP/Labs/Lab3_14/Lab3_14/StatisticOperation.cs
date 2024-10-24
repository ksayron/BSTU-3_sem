using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3_14
{
    public static class StatisticOperation
    {
        public static int sum(Queue q)
        {
            return q.queue.Sum();
        }

        public static int diff(Queue q)
        {
            return q.queue.Max() - q.queue.Min();
        }

        public static int count(Queue q)
        {
            return q.queue.Count;
        }
        #region ExtensionMethods
        public static int GetLastEl(this Queue q)
        {
            
            return q[q.queue[q.queue.Count-1]];
        }
        public static int GetFirstDot(this string sentence)
        {
            int indx;
            indx = sentence.IndexOf(".");
            return indx;
        }
        #endregion
    }
}
