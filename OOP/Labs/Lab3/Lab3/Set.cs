using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3
{
    internal class Set
    {
        #region
        public T[] els;
        public int size;
        public Developer dev;
        public Production prod;
        public Set (int size)
        {
            els = new T[size];
            size = 0;
        }

        #region Production and Developer
        public class Production
        {
            public int Id { get; set; }
            public string Name { get; set; }
        }
        public class Developer
        {
            public string Fio { get; set; }
            public int Id { get; set; }
            public string Department { get; set; }
        }
        #endregion
        #endregion

        #region prop
        public int[] all_els
        {
            get
            {
                if (size != 0)
                {
                    int[] all_ell = new int[size];
                    els.CopyTo(all_ell, 0);
                    return all_ell;
                }
                else { return els; }
            }
        }
        public int Size
        {
            get { return size; }
        }
        #endregion

        #region methods
        public void Insert(int a)
        {
            if(size == 0) {els[0] = a;size++; }
            else{bool uniq = true,next_b=false;
            int next=0;
            for(int i = 0; i < size; i++) {
                if (els[i] == a) uniq = false;
                if (els[i] > a && !next_b) { next = i;next_b = true; }
            }
                if (uniq)
                {
                    if(next_b){for (int i = size; i > next; i--)
                        {
                            els[i] = els[i - 1];
                        }
                        els[next] = a;
                    }
                    else{ els[size] = a; }
                    this.size++;
                }
            }
        }

        public void Remove(int a) {
            int temp=0;
            int c = 0;
            while (els[c] != a)
            {
                c++;
            }
            for (int i=c ; i < size-1; i++)
            {
                els[i] = els[i+1];

            }
            size--;
        }
        public void Print()
        {
            for (int i = 0; i < size; i++)
            {
                Console.Write(els[i] + " ");
            }
            Console.WriteLine();
        }
        #endregion
        #region override
        // * пересечение множеств
        public static Set<T> operator *(Set<T> set1, Set<T> set2)
        {
            Set set3 = new Set(set1.size);
            for(int i = 0; i < set1.size; i++)
            {
                for(int j = 0; j < set2.size; j++)
                {
                    if (set1.all_els[i] == set2.all_els[j]) set3.Insert(set1.all_els[i]);
                }
            }
            return set3;
        }

        // > проверка на принадлежность
        public static bool operator >(Set set1, int a)
        {

            for (int i = 0; i < set1.size; i++)
            {
                if (set1.all_els[i] == a) return true;
            }
            return false;
        }

        public static bool operator <(Set set1, int a)
        {

            for (int i = 0; i < set1.size; i++)
            {
                if (set1.all_els[i] == a) return true;
            }
            return false;
        }

        // < проверка на подмножество
        public static bool operator >(Set set1, Set set2)
        {
            bool check = true;
            if (set2.size > set1.size) { return false; }
            for (int i = 0; i < Math.Max(set1.size, set2.size); i++)
            {
                for (int j = 0; j < Math.Min(set1.size,set2.size); j++)
                {
                    if (set1.all_els[i+j] != set2.all_els[j]) check=false;
                    
                }
                if (check) { return check; }
                else { check = true; }
            }
            return check;
        }

        public static bool operator <(Set set2, Set set1)
        {
            bool check = true;
            if (set2.size > set1.size) { return false; }

            for (int i = 0; i < Math.Max(set1.size, set2.size); i++)
            {
                for (int j = 0; j < Math.Min(set1.size, set2.size); j++)
                {
                    if (set1.all_els[i + j] != set2.all_els[j]) check = false;

                }
                if (check) { return check; }
                else { check = true; }
            }
            return check;
        }

        public static explicit operator DateTime(Set set)
        {
            if(set.size>=3){int day = set.els[0];
            int month = set.els[2];
            int year = set.els[3];  // Пример преобразования в год
                return new DateTime(year, month, day);
            }
            else { return new DateTime(0); }
        }

        #endregion
    }

}
