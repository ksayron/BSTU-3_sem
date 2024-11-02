//task 1
const person = {
  name: 'Дима',
  age: 30,

  greet() {
    return `Я ${this.name}!`;
  },

  ageAfterYears(years) {
    return this.age + years; 
  }
}
console.log(person.greet())
console.log(person.ageAfterYears(7))

//task 2
const car = {
  model: 'BMW',
  year: 2019,

  getInfo() {
    return this.model+' '+this.year;
  }
}
console.log(car.getInfo())

//task 3
function Book(title, author) {
  this.title = title;
  this.author = author;

  this.getTitle = function() {
    return this.title;
  }

  this.getAuthor = function() {
    return this.author;
  }
}


const GoT = new Book('Песень льда и пламени', 'Джордж Р.Р. Мартин');
const Metamorphisis = new Book('Превращение', 'Франц Кафка');

GoT.getTitle(); // "Book title 1"  
Metamorphisis.getAuthor(); // "Author 2"


//task 4
const team = {
  players: [
    {name: 'Никита', age: 30},
    {name: 'Миша', age: 26},  
    {name: 'Маша', age: 28}
  ],

  printPlayers() {

    this.players.forEach(function(player) {
      console.log(player.name);
    });
  }
}

team.printPlayers();
//task 5
// main.js
const counter =(()=> {
  let count = 0;
  function increment() {
    this.count++;
  };

  function decrement(){
    this.count--;
  };

  function getCount() {
    return this.count;
  };
  return {
      increment,
      decrement,
      getCount
  }
});



console.log(counter().increment);
console.log(counter().increment);
console.log(counter().decrement);
console.log(counter().getCount);


//task 6

//task 7

//task 8

//task 9

//task 10

//task 11