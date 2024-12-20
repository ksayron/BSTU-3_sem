let tasksIds = 1;

class Task {
  constructor(name, id) {
    this.name = name;
    this.id = id;
    this.status = false;
  }

  setName(Newname) {
    this.name = Newname;
  }

  setStatusTrue() {
    this.status = true;
  }

  setStatusFalse() {
    this.status = false;
  }
}

class ToDoList {
  constructor(name, id) {
    this.id = id;
    this.name = name;
    this.list = [];
  }

  addTask(task) {
    this.list.push(task);
    this.showTask(task);
  }
  removeTask(task) {
    const taskIndex = this.list.indexOf(task);
    if (taskIndex !== -1) {
      this.list.splice(taskIndex, 1);
      const taskDiv = document.querySelector(`.task[data-id="${task.id}"]`);
        if (taskDiv) {
        taskDiv.remove();
        }
      this.updateTaskList();
      console.clear();
      this.showTasks();
    }
  }

  showTasks() {
    console.group("Tasks");
    this.list.forEach((element) => console.log(element));
    console.groupEnd();
  }

  showTasksFilter(status) {
    if (status) {
      console.group("Done tasks");
    } else {
      console.group("Undone tasks");
    }
    this.list.forEach((element) => {
      if (element.status == status) {
        console.log(element);
      }
    });
    console.groupEnd();
  }

  showTask(task) {
    const taskDiv = document.createElement("div");
    taskDiv.classList.add("task");
    taskDiv.dataset.id = task.id;

    const checkboxInput = document.createElement("input");
    checkboxInput.type = "checkbox";
    checkboxInput.name = "status";
    checkboxInput.checked = task.status;
    checkboxInput.addEventListener("change", () => {
      task.status = checkboxInput.checked;
    });

    const nameP = document.createElement("p");
    nameP.name = "name";
    nameP.textContent = task.name;

    const editButton = document.createElement("button");
    editButton.name = "Edit";
    editButton.innerHTML = '<img src="edit-svgrepo-com.svg" alt="">Редактировать';
    editButton.addEventListener("click", () => {
      const newName = prompt("Введите новое имя для вашего дела:");
      task.setName(newName);
      nameP.textContent = task.name;
    });

    const deleteButton = document.createElement("button");
    deleteButton.name = "Delete";
    deleteButton.innerHTML = '<img src="delete-1487-svgrepo-com.svg" alt=""> Удалить';
    deleteButton.addEventListener("click", () => {
      todolist.removeTask(task);
    });

    taskDiv.appendChild(checkboxInput);
    taskDiv.appendChild(nameP);
    taskDiv.appendChild(editButton);
    taskDiv.appendChild(deleteButton);

    document.querySelector(".tasksList").appendChild(taskDiv);
    console.clear();
    this.showTasks();
  }
  updateTaskList() {
    const tasksList = document.querySelector(".tasksList");
    tasksList.innerHTML = "";

    this.list.forEach((task) => {
      this.showTask(task);
    });
  }
  updateTaskListOnlyTrue() {
    const tasksList = document.querySelector(".tasksList");
    tasksList.innerHTML = "";

    this.list.forEach((task) => {
        if(task.status){this.showTask(task);}
    });
  }
    updateTaskListOnlyFalse() {
    const tasksList = document.querySelector(".tasksList");
    tasksList.innerHTML = "";

    this.list.forEach((task) => {
        if(!task.status){this.showTask(task);}
    });
  }


}

let todolist = new ToDoList("main", 0);

document.addEventListener('DOMContentLoaded', function() {
  document.getElementById('add').addEventListener('click',
    function addByClick() {
      let name = document.getElementById('newTaskInput').value;
      document.getElementById('newTaskInput').value = '';
      let newTask = new Task(name, tasksIds++);
      todolist.addTask(newTask);
    }
  );
});
document.addEventListener('DOMContentLoaded', function() {
    document.getElementById('showAll').addEventListener('click',
      function addByClick() {
        todolist.updateTaskList();
      }
    );
  });
document.addEventListener('DOMContentLoaded', function() {
    document.getElementById('showTrue').addEventListener('click',
      function addByClick() {
        todolist.updateTaskListOnlyTrue();
      }
    );
  });
  document.addEventListener('DOMContentLoaded', function() {
    document.getElementById('showFalse').addEventListener('click',
      function addByClick() {
        todolist.updateTaskListOnlyFalse();
      }
    );
  });