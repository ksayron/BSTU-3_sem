//task 1
let square = {
  width:100,
  height:100,
  color:"yellow",
  getSquare(){
      return this.width*this.height;
  },
  getInfo(){
      return `This is a square with height ${this.height} and width ${this.width}. Square's color is ${this.color}`;
  },
  getOwnPropeties(){
    let props =  Object.keys(this)
    let check = false
    props.some(prop => {
        if(prop =='color' && this.hasOwnProperty(prop))check=true;
      });
    return check
  }
};
let small_square = {
  __proto__:square,
  width:50,
  height:50,

};

let circle = {
  radius:100,
  color:"white",
  getSquare(){
      return Math.PI*Math.pow(this.radius,2);
  },
  getInfo(){
      `This is a circle with radius ${this.radius} and it's color is ${this.color}`;
  }
};

let another_circle = {
  __proto__:circle,
  color:"green"
};

let triangle_with_lines = {
  base:20,
  height:40,
  lines:1,
  color:"white",
  getSquare(){
      return (this.base/2)*this.height;
  },
  getInfo(){
      return `This is a triangle with ${this.lines} lines and it's color is ${this.color} `;
  }
};

let another_triangle = {
  __proto__:triangle_with_lines,
  lines:3
};
console.group("Фигуры");
console.log(square.getInfo());
console.log(small_square.getInfo());
console.log(circle.getInfo());
console.log(another_circle.getInfo());
console.log(triangle_with_lines.getInfo());
console.log(another_triangle.getInfo());
console.log(small_square.getOwnPropeties())
console.groupEnd();

//task 2
console.group("Студенты")
class Human{
  constructor(name, surname, birthYear, address) {

      this.name = name;
      this.surname = surname;
      this.address = address;
      this.birthYear=birthYear
  }
  setAge(NewAge){
    let current_year = new Date().getFullYear();
    this.birthYear =current_year- NewAge;
  }
  get age(){
      let current_year = new Date().getFullYear();
      return current_year - this.birthYear;
  }
  setAddress(NewAddress){
      this.address = NewAddress;
  }
};

let human = new Human("Никита","Бобриков",2006,"Чурноса 24");
console.log(human.age);

class Student extends Human{
  constructor(name, surname, birthYear, address, faculty, course, group,id) {
      super(name, surname, birthYear, address);
      this.faculty = faculty;
      this.course = course;
      this.group = group;
      this.id=id;
  };

  setCourse(NewCourse){
      this.course = NewCourse;
  }
  setGroup(NewGroup){
      this.group = NewGroup;
  }
  getFullName(){
      return `${this.name} ${this.surname}`;
  }
}



class Faculty{
  constructor(name,group_count,students_count){
      this.name = name;
      this.group_count = group_count;
      this.students_count = students_count;
      this.students = [];
  }
  setGroups(NewGroups){
      this.group_count = NewGroups;
  }
  setStudents(NewStudents){
      this.students_count = NewStudents;
  }
  getDev(){
      let dev_count = 0;
      this.students.forEach(element => {
          let str_id = element.id.toString();
          if(str_id[1]==3){
              dev_count++;
          }
      });
      return dev_count;
  }
  getGroup(num){
      let gruop_list = [];
      this.students.forEach(element => {
          if(element.group==num){
              gruop_list.push(element);
          }
      });
      return gruop_list;
  }

}
let student = new Student("Николай","Кучерук",2005,"Свердлова 13","ФИТ",2,6,71231129);
console.log(student.getFullName());
let student1 = new Student("Верлонов","Дмитрий",2007,"Свердлова 13","ИД",1,4,62242567);
let student2 = new Student("Кардоцкая","Василиса",2004,"Свердлова 13","ФИТ",4,3,73211226);
let student3 = new Student("Альшевская","Алина",2006,"Свердлова 13","ФИТ",2,6,71231128);


let FIT = new Faculty("FIT",10,1000);
FIT.students.push(student);
FIT.students.push(student1);
FIT.students.push(student2);
FIT.students.push(student3);
console.log(FIT.getDev());
console.log(FIT.getGroup(6));
console.groupEnd();