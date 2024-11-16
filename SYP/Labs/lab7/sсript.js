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
const car2 = {
  model: 'БМВ',
  year: 2019,

  getInfo() {
    return this.model+' '+this.year;
  }
}
console.log(car2.getInfo())

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

  this.Print = function(){
    console.log(this.author+' '+this.title);
  }
}


const GoT = new Book('Песень льда и пламени', 'Джордж Р.Р. Мартин');
const Metamorphisis = new Book('Превращение', 'Франц Кафка');

GoT.getTitle(); 
Metamorphisis.getAuthor(); 
GoT.Print();

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
const item = {
  _price: 100, 

  get price() {
    return this._price;
  },

  set price(value) {
    this._price = value;
  },

  deleteprice() {
    delete this._price;
  }
};

console.log(item.price); 
item.price = 150;
console.log(item.price); 
delete item.price;

Object.defineProperty(item, 'price', {
  value: 100,
  writable: false,
  configurable: false
});

console.log(item.price); 
item.price = 150; 
console.log(item.price); 
delete item.price; 
console.log(item.price); 

//task 7
const circle = {
  _radius: 5,
  _area:10,

  get radius() {
    return this._radius;
  },

  set radius(value) {
    this._radius = value;
  },

  get area() {
    return Math.PI * this._radius ** 2;
  },

  set area(value){
    this._area=value;
  }
};

console.log(circle.radius);
console.log(circle.area);

circle.radius = 7;
console.log(circle.radius); 
console.log(circle.area);

circle.area=15;
console.log(circle.area);

//task 8

const car = {
  make: 'Рено',
  model: 'Логан',
};

console.log(car.make); 
console.log(car.model); 

car.make = 'Фольтсваген';
car.model = 'Жук';

console.log(car.make); 
console.log(car.model); 

delete car.make;
delete car.model;

console.log(car.make); 
console.log(car.model); 

Object.defineProperties(car, {
  make: {
    value: 'Рено',
    writable: false,
    configurable: false
  },
  model: {
    value: 'Логан',
    writable: false,
    configurable: false
  },
});

console.log(car.make);
console.log(car.model); 

car.make = 'Фольтсваген'; 
car.model = 'Жук'; 

delete car.make; 
delete car.model;

console.log(car.make);
console.log(car.model); 
//task 9
const arr = [5, 10, 15];

Object.defineProperty(arr, 'sum', {
  get: function() {
    return this.reduce((total, num) => total + num, 0);
  },
  configurable:false,
});

console.log(arr.sum); // Output: 30

arr.sum = 100; 
console.log(arr.sum);

console.log(arr.sum); 
//task 10
const rectangle = {
  _width: 5,
  _height: 10,

  get width() {
    return this._width;
  },

  set width(value) {
    this._width = value;
  },

  get height() {
    return this._height;
  },

  set height(value) {
    this._height = value;
  },

  get area() {
    return this._width * this._height;
  }
};

console.log(rectangle.width); // 5
console.log(rectangle.height); // 10
console.log(rectangle.area); // 50

rectangle.width = 7;
rectangle.height = 12;

console.log(rectangle.width); // 7
console.log(rectangle.height); // 12
console.log(rectangle.area); // 84

//task 11
const user = {
  _firstName: 'Кучерук',
  _lastName: 'Николай',

  get fullName() {
    return `${this._firstName} ${this._lastName}`;
  },

  set fullName(fullName) {
    [this._firstName, this._lastName] = fullName.split(' ');
  }
};

console.log(user.fullName); // Output: "John Doe"

user.fullName = 'Кравченко Сергей';
console.log(user.fullName); 
console.log(user._firstName);
console.log(user._lastName);