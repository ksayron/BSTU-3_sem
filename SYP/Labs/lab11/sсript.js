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
        this.list.push(task);
    }

    removeTask(task){
        this.list.pop(task);
    }

    showTasks(){
        console.group("Tasks");
        this.list.forEach((element) => console.log(element))
        console.groupEnd();
    }
    showTasksFilter(status){
        if(status){console.group("Done tasks");}
        else{console.group("Undone tasks");}
        this.list.forEach((element) => {if(element.status==status){console.log(element)}})
        console.groupEnd();
    }
}

let todolist = new ToDoList("list",1);

let task1 = new Task("SYP Lab 11",1);
let task2 = new Task("SYP Lab 12",2);
let task3 = new Task("OOP Lab 16",3);

todolist.addTask(task1);
todolist.addTask(task2);
todolist.addTask(task3);
task3.setStatusTrue();
//todolist.removeTask(task1);
console.log(todolist);
todolist.showTasks();
todolist.showTasksFilter(false)
todolist.showTasksFilter(true)