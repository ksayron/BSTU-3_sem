//task 1
function basicOperation(operation, value1, value2) {
    let result;
 if (operation=='*') {result= value1 * value2;}
 else if(operation=='+') {result= +value1 + value2;}
 else if (operation=='-') {result=value1 - value2;}
 else if( operation=='/') {result= Number(value1)/ Number(value2);}
 else {result='Такой операции нет';}
 return result;
}
let result1 = basicOperation('+', 1, 1); 
console.log(result1);


//task2
function sqrSum(n){
    let sum=0;
    let i=0;
    for(  i=1;i<=n;i++){
     sum = sum+i*i*i;
    }
return sum;
}

let result2=sqrSum(7);
console.log(result2);


//task3
function  mean(arr){
    let sum=0;
    for( let i=0;i<arr.length;i++){
        sum=sum+arr[i];
    }
    return sum/arr.length;
}
let array=[1,2,3,4,5,6,7,8,9,10]
let result3=mean(array);
console.log(result3);


//task4
function eng_Reverse(str){
    let strng="";
    for(let i=str.length-1; i>=0;i--){
        if( (str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z')){
            strng+=str[i];
        }
    }
return strng;
}

let string="Hello мир";
console.log(eng_Reverse(string));

//task 5
function strArr(number, str){
let strng="";
for(let i=0;i<number;i++){
    strng+=str+' ';
}
return strng;
}

console.log( strArr(5,"JS"));

//task6
function uniqString(arr1,arr2){
let arr3=[]
let fl=true;
for(let i=0;i<arr1.length;i++){
    for(let j=0;j<arr2.length;j++){
        if(arr1[i]==arr2[j]){f1=false;}
    }
    if (fl) {arr3.push(arr1[i]);}
    fl=true;
}
return arr3;
}
let array1=['C++','TypeScript','Node.js','Java'];
let array2=['TypeScript','Node.js'];
console.log(uniqString(array1,array2));