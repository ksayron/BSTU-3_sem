//task 1
const products1 = new Set();

function addProduct(product) {
  products1.add(product);
}

function deleteProduct(product) {
  products1.delete(product); 
}

function checkProduct(product) {
  return products1.has(product);
}

function countProducts() {
  return products1.size;
}

addProduct('Молоко');
addProduct('Хлеб');
addProduct('Сыр');


deleteProduct('Сыр');


console.log(checkProduct('Хлеб')); 


console.log(countProducts());
console.log(products1)
//task 2
const students = new Set();

function addStudent(student) {
  students.add(student);
}

function deleteStudent(id) {
  students.delete(id);
}

function filterByGroup(group) {
  return Array.from(students).filter(student => student.group === group);
} 

function sortByID() {
  return Array.from(students).sort((a, b) => a.id - b.id);
}

const student1 = {
  id: 1,
  name: 'Пупкин Василий Васильевич',
  group: 'A' 
}
const student2 = {
  id: 2,
  name: 'Дупкин Петр Васильевич',
  group: 'B' 
}
const student3 = {
  id: 4,
  name: 'Пупкина Василиса Василисовна',
  group: 'A' 
}
const student4 = {
  id: 3,
  name: 'Купкин Николай Петрович',
  group: 'B' 
}
const student5 = {
  id: 5,
  name: 'Уткин Дмитрий Сергеевич',
  group: 'B' 
}
addStudent(student1);
addStudent(student2);
addStudent(student3);
addStudent(student4);
addStudent(student5);
deleteStudent(student5)

console.log(students)

console.log(filterByGroup('A'));
console.log(sortByID());
//task 3

const cart = new Map(); 

let id = 0;

function addItem(item) {
  item.id = id++;
  cart.set(item.id, item);
}

function removeItemById(id) {
  cart.delete(id);
}

function removeItemsByName(name) {
  cart.forEach((item) => {
    if(item.name === name) {
      cart.delete(item.id);
    }
  });
}


function updateQuantity(id, quantity) {
  const item = cart.get(id);
  item.quantity = quantity;
}


function updatePrice(id, price) {
  const item = cart.get(id);
  item.price = price;
}


function totalItems() {
  return cart.size;
}


function totalPrice() {
  let total = 0;
  cart.forEach(item => {
    total += item.price * item.quantity;
  });
  return total;
}


// Products
const products = [
  {name: 'Milk', price: 10, quantity: 1},
  {name: 'Bread', price: 20, quantity: 2},
  {name: 'Eggs', price: 15, quantity: 3}, 
  {name: 'Cheese', price: 30, quantity: 5}
];


products.forEach(product => {
  addItem(product);
});

updateQuantity(products[2].id,15)
updatePrice(products[2].id,3)
removeItemById(products[0].id); 

removeItemsByName('Cheese');

console.log(cart);

const cartTotal = totalPrice(); 

console.log('Cart total:', cartTotal);

//task 4

const cache = new WeakMap();


function calc(num){
  return num*num;
}
function cachingFunc2(key)
{
    if(cache.has(key))
    {
        console.log("берем с кеша")
        return cache.get(key)
    }
    const result = calc(key.key);
    cache.set(key,result);
    console.log("не берем с кеша")
    return result;
}
 obj = {key:5};
console.log(cachingFunc2(obj));
console.log(cachingFunc2(obj))
 obj = {key:6}
console.log(cachingFunc2(obj))

let name = "John";

function sayHi() {
  alert("Hi, " + name);
}

name = "Pete";

sayHi(); 
