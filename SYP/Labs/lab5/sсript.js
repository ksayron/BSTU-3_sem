//task 1 
{function makeCounter(){
  let count=1;
  return function(){
    return count++
  };
}

let counter = makeCounter();

console.log(counter());
console.log(counter());
console.log(counter());

let counter2 = makeCounter();

console.log(counter2());
}
{
  let count=1;
  function makeCounter(){
  return function(){
    return count++
  };
}

let counter = makeCounter();
let counter2 = makeCounter();

console.log(counter());
console.log(counter());
console.log(counter2());
console.log(counter2());
}
//task 2
function volume(length) {
  return function(width) {
    
    return function(height){return length * width * height;}
  }
}

const carried_v = volume(5);

let v1 = carried_v(2)(3); // 30
let v2 = carried_v(4)(1); // 20

console.log(v1, v2);
//task 3
function* moveObject(initialX, initialY) {
  let x = initialX; 
  let y = initialY;


  for(let i = 0; i < 10; i++) {
    const direction = prompt('Введите направление(влево-a, вправо-d, вверх-w, вниз-s)');
    switch(direction) {
      case 'a': 
        x--;
        break;
      case 'd':  
        x++; 
        break;
      case 'w':
        y++;
        break;
      case 's':   
        y--;
        break;  
    }

    alert(`Вы находитесь в (${x}, ${y})`);
  }
  yield{x,y};
}
const generator = moveObject(0, 0);
generator.next()
//task 4
keyArray=[];
for(let key in window) {
  keyArray.push(window[key]);
}
console.log(keyArray)
