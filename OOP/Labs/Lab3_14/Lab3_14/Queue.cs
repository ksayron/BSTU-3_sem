using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3_14
{
    public class Queue
    {
        public Queue()
        {
            _queue = new List<int>();
        }
        #region fields and props
        private List<int> _queue;
        public List<int> queue
        {
            get
            {
                List<int> temp = new List<int>();
                temp = _queue.GetRange(0, _queue.Count);
                return temp;
            }
        }
        

        public int this[int index]
        {
            get { return _queue[index]; }
        }
        #endregion
        #region methods
        public void Print()
        {
            Console.Write("Queue elements: ");
            foreach (int item in queue)
            {
                Console.Write(item + " ");
            }
            Console.WriteLine();
        }
        #endregion
        #region oper
        public static Queue operator +(Queue q, int element)
        {
            q._queue.Add(element);
            return q;
        }

        public static Queue operator --(Queue q)
        {
            q._queue.RemoveAt(0);
            return q;
        }

        public static bool operator true(Queue q)
        {
            return q._queue.Count == 0;
        }
        public static bool operator false(Queue q)
        {
            return q._queue.Count != 0;
        }

        public static Queue operator <(Queue q1, Queue q2)
        {
            Queue newQueue = new Queue();
            foreach (int item in q1._queue.Concat(q2._queue).OrderByDescending(x => x))
            {
                newQueue._queue.Add(item);
            }
            return newQueue;
        }

        public static Queue operator >(Queue q1, Queue q2)
        {
            Queue newQueue = new Queue();
            foreach (int item in q1._queue.Concat(q2._queue).OrderByDescending(x => x))
            {
                newQueue._queue.Add(item);
            }
            return newQueue;
        }
        public static int operator !(Queue q)
        {
            return q._queue.Count;
        }
        public static implicit operator int(Queue q)
        {
            return q.queue[0] ^ 2;
        }
        #endregion
        #region Developer and Production
        public class Production
        {
            public int Id { get; set; }
            public string OrganizationName { get; set; }
        }

        public class Developer
        {
            public string FullName { get; set; }
            public int Id { get; set; }
            public string Department { get; set; }
        }
        #endregion

    }
}
