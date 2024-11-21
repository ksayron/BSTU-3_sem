using Lab13;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab13
{
    internal interface ISerializer<T>
    {
        public void Serialize(T animal);
        public T Deserialize();
    }
}
