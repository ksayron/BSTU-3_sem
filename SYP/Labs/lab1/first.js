let a = 5;
let name = "Name";
let i = 0;
let double = 0.23;
let result = 1/0;
let answer = true;
let no=null;

let comparison1 = ("Котик" == "котик") ? "Равны" : "Не равны";
let comparison2 = ("Котик" == "китик") ? "Равны" : "Не равны";
let comparison3 = ("Кот" == "Котик") ? "Равны" : "Не равны";
let comparison4 = ("Привет" == "Пока") ? "Равны" : "Не равны";
let comparison5 = (73 == "53") ? "Равны" : "Не равны";
let comparison6 = (false == 0) ? "Равны" : "Не равны";

console.log(comparison1);
console.log(comparison2);
console.log(comparison3);
console.log(comparison4);
console.log(comparison5);
console.log(comparison6); 



let input = prompt("Введите ваше имя:");

let teacherName  = "Марина";
let teacherName2 = "Марина Федоровна";
let teacherName3 = "Кудлацкая Марина Федоровна";

if (input.toLowerCase() == teacherName.toLowerCase() || input.toLowerCase() === teacherName2.toLowerCase() || input.toLowerCase() === teacherName3.toLowerCase())
    { alert("Вход успешен!");}
    else {
    alert("Данные некорректны");}


    document.getElementById('button1').addEventListener('click', 
        function kubiki() {
            let sidea1=45,sidea2=21;
        let  solution = Math.floor(sidea1/5)*Math.floor(sidea2/5);
            document.getElementById('solution').textContent = "Ответ: " + solution;
        });
    document.getElementById('button2').addEventListener('click',function takeExams() {
        const rus = document.getElementById('rus').checked;
        const math = document.getElementById('math').checked;
        const eng = document.getElementById('eng').checked;

        
        if(rus && math && eng){ document.getElementById('results').textContent = "Результат сессии: 2 курс" ;}
        else if( rus || math || eng){ document.getElementById('results').textContent = "Результат сессии: Пересдача"}
        else{ document.getElementById('results').textContent = "Результат сессии: Отчислен"}
        
     
    });

    console.log(true + true);
    console.log(0 + "5");
    console.log(5 + "mm");
    console.log(8 / Infinity);
    console.log(9 * "\n9");
    console.log(null - 1);
    console.log("5" - 2);
    console.log("5px" - 3);
    console.log(true - 3);
    console.log(7 || 0);

    for (let i = 1; i <= 10; i++) {
        if (i % 2 === 0) {
            console.log(i + 2);
        } else {
            let odd = i.toString() + "mm";
            console.log(odd);
        }
    }
    const obj = {
        1: 'пн',
        2: 'вт',
        3: 'ср',
        4: 'чт',
        5: 'пт',
        6: 'сб',
        7: 'вс'
    };
    
    const input2 = parseInt(prompt('Введите номер дня недели (от 1 до 7):'));
    const obj_mini = obj[input2];
    
    if (obj_mini) {
        console.log(`Это день "${obj_mini}".`);
    } else {
        console.log('Неверный номер дня.');
    }

    const arr = ['пн', 'вт', 'ср', 'чт', 'пт', 'сб', 'вс'];

const input3 = parseInt(prompt('Введите номер дня недели (от 1 до 7):'));
const arr_mini = arr[input3 - 1];

if (arr_mini) {
    console.log(`Это день "${arr_mini}".`);
} else {
    console.log('Неверный номер дня.');
}

function generateString(param1 = "Первый", param2, param3) {
    return `${param1} ${param2} ${param3}`;
}

const input4 = prompt("Введите слово:");
const result3 = generateString( undefined,"из", input4);

console.log(result3);

function params(a, b) {
    if (a === b) {
        return 4 * a;
    } else {
        return a * b; 
    }
}
const params2 = function(a, b) {
    if (a === b) {
        return 4 * a;
    } else {
        return a * b;
    }
};
const params3 = (a, b) => (a === b) ? 4 * a : a * b;
    