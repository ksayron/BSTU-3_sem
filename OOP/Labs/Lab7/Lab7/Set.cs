using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

namespace Lab7
{
    interface IPublic<T> 
    {
        void Add(T a);
        void Pop(T a);
        T GetById(int id);
    }
    internal class Set<T>:IPublic<T> where T : class
    {
        #region
        public T[] els;
        public int size;
        public Developer dev;
        public Production prod;
        public Set(int size)
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
        public T[] all_els
        {
            get
            {
                return els; 
            }
        }
        public int Size
        {
            get { return size; }
        }
        #endregion

        #region methods
        public void Add(T a)
        {
            if (size == 0) { els[0] = a; size++; }
            else
            {
                bool uniq = true, next_b = false;
                int next = 0;
                for (int i = 0; i < size; i++)
                {
                    if (Eqs(els[i],a) ) uniq = false;
                }
                if (uniq)
                {
                    els[size] = a;
                    size++;
                }
            }
            Array.Sort(els,0,size);
        }

        public void Pop(T a)
        {
            int temp = 0;
            int c = 0;
            while (!Eqs(els[c], a))
            {
                c++;
            }
            for (int i = c; i < size - 1; i++)
            {
                els[i] = els[i + 1];

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
        public T GetById(int id)
        {
            return els[id-1];
        }
        public  static bool Eqs(T t1, T t2)
        {
            return EqualityComparer<T>.Default.Equals(t1, t2);
        }
        public void PushToFile()
        {
            using StreamWriter sw = new("Set.json");
            var str = JsonSerializer.Serialize(els);
            sw.WriteLine(str);

        }

        public void ReadFromFile()
        {
            try
            {
                using StreamReader sr = new("Set.json");
                var str = sr.ReadToEnd();
                els = JsonSerializer.Deserialize<T[]>(str);
                this.size = els.Length;
            }
            catch (Exception e) 
            {
                Console.WriteLine(e);
            }
            finally
            {
                Console.WriteLine("Чтение с файла успешно!") ;
            }
        }
        #endregion
        #region override

        // * пересечение множеств
        public static Set<T> operator *(Set<T> set1, Set<T> set2)
        {
            Set<T> set3 = new Set<T>(set1.size);
            for (int i = 0; i < set1.size; i++)
            {
                for (int j = 0; j < set2.size; j++)
                {
                    if (Eqs(set1.all_els[i] , set2.all_els[j])) set3.Add(set1.all_els[i]);
                }
            }
            return set3;
        }

        // > проверка на принадлежность
        public static bool operator >(Set<T> set1, T a)
        {

            for (int i = 0; i < set1.size; i++)
            {
                if (Eqs(set1.all_els[i], a)) return true;
            }
            return false;
        }

        public static bool operator <(Set<T> set1, T a)
        {

            for (int i = 0; i < set1.size; i++)
            {
                if (Eqs(set1.all_els[i], a)) return true;
            }
            return false;
        }

        // < проверка на подмножество
        public static bool operator >(Set<T> set1, Set<T> set2)
        {
            bool check = true;
            if (set2.size > set1.size) { return false; }
            for (int i = 0; i < Math.Max(set1.size, set2.size); i++)
            {
                for (int j = 0; j < Math.Min(set1.size, set2.size); j++)
                {
                    if (!Eqs(set1.all_els[i + j], set2.all_els[j])) check = false;

                }
                if (check) { return check; }
                else { check = true; }
            }
            return check;
        }

        public static bool operator <(Set<T> set2, Set<T> set1)
        {
            bool check = true;
            if (set2.size > set1.size) { return false; }

            for (int i = 0; i < Math.Max(set1.size, set2.size); i++)
            {
                for (int j = 0; j < Math.Min(set1.size, set2.size); j++)
                {
                    if (!Eqs(set1.all_els[i + j] ,set2.all_els[j])) check = false;

                }
                if (check) { return check; }
                else { check = true; }
            }
            return check;
        }

        public static explicit operator DateTime(Set<T> set)
        { 
            return new DateTime(0); 
        }

        #endregion
    }

}
