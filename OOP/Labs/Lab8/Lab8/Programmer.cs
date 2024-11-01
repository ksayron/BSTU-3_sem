using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8
{
    public delegate void RenameHandler(string prjcname, string newnamee);
    public delegate void NewOperationHandler(string prjcname, string newOperation);
    public class Programmer
    {
        public string name;


        public Programmer(string name)
        {
            this.name = name;
            
        }

        public event RenameHandler RenameEvent;
        public event NewOperationHandler NewOperation;
        public void Rename(string prjcname,string newname)
        {
            RenameEvent?.Invoke(prjcname, newname);
        }
        public void AddOperation(string prjcname, string newOperation)
        {
            NewOperation?.Invoke(prjcname, newOperation);
        }
       
    }
    public class Language
    {
        public string name;
        public string version;
        public string[] operations;
        private int opp_size=0;
        public Language(string name, string version,Programmer prog)
        {
            this.name = name;
            this.version = version;
            operations = new string[5];
            prog.RenameEvent += (string prjcname, string newname) =>{ if (this.name == prjcname) this.name = newname; }  ;
            prog.NewOperation += (string prjcname, string newname) => { if (this.name == prjcname) this.operations[opp_size] += newname;opp_size++; };
        }

    }
    public class Projects
    {
        public Language[] projects;
        private int project_size;
        public Projects(int size) {
            projects = new Language[size];
            project_size = 0;
        }

        public void AddProject(Language language)
        {
            projects[project_size] = language;
            project_size++;
        }
        public void PrintProjects()
        {
            for (int i = 0; i < project_size; i++)
            {
                Console.Write($"{projects[i].name} {projects[i].version} ");
                foreach (string op in projects[i].operations)
                {
                    Console.Write(" " + op + " ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }

    }
}
