class Task{
    constructor(name,id){
        this.name=name;
        this.id=id;
        this.status=false
    }

    setName(Newname){
        this.name=Newname;
    }

    setStatusTrue(){
        this.status=true;
    }

    setStatusFalse(){
        this.status=false;
    }
}

class ToDoList{
    constructor(name,id){
        this.id=id;
        this.name=name;
        this.list=[];
    }

    addTask(task){
        this.list+=task;
    }

    removeTask(task){
        this.list-=task;
    }
}

let todolist = new ToDoList("list",1);

let task1 = new Task("SYP Lab 11",1);
todolist.addTask(task1);
console.log(todolist);