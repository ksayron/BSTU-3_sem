
    // Task 1 
    let arr=[1,[1,2,[3,4]],[2,4]]
    function flattenArray(InputArray){
    return InputArray.reduce((Acc,Curr)=>{
    if(Array.isArray(Curr)){
      return Acc.concat(flattenArray(Curr));
    }
    else{
      return Acc.concat([Curr]);
    }
    },[]);
    }
  const result41 = flattenArray(arr);
  console.log(result41);
    // Task 2

    let arr1 = [[1,2], [3,4]];
        
    let arr2 = [[5,6], [7,8]];
    
    var result1 = arr1.flat(Infinity).reduce(function(sum, current) {
        return sum + current;
      }, 0);
    var result2 = arr2.flat(Infinity).reduce(function(sum, current) {
        return sum + current;
    }, 0);
    
    let arr3=[1,2,3,4];
    var res33 =arr3.reduce(function(sum,curr){
        return sum + curr;
    },0);

    console.log(res33)


    console.log(result1+result2)
    

    // Task 3
    function groupStudents(students) {
    return students.reduce((obj, student) => {
    if(student.age > 17) {
    obj[student.groupId] = obj[student.groupId] || [];
    obj[student.groupId].push(student);
    }
    return obj;
    }, {});
    }
    let students = [
        
        {name: 'Коля', age: 18, groupId: 1},
        
        {name: 'Алина', age: 17, groupId: 1},
        
        {name: 'Виктор', age: 19, groupId: 2},

        {name: 'Максим', age: 16, groupId: 2},
        
        {name: 'Сергей', age: 19, groupId: 1},
        
        {name: 'Катя', age: 18, groupId: 2}
        
        ];
        
        let grouped = groupStudents(students);
        
        console.log(grouped);
    
    // Task 4 
    function cipher(str) {
        return str.split('').map(char => char.charCodeAt(0)).join('');
    }      
    
    function decipher(str) {

    let total1 = cipher(str);
          
    let total2 = total1.replace("7", "1");;
    return total1-total2;
    }
    let str = 'ABC';
        
        let result = decipher(str);

        console.log(result);
    
    // Task 5
    function extend(...objs) {
    return Object.assign({}, ...objs);
    }
        let obj1 = {a: 1,c:3}; 
        let obj2 = {b: 2};
        
        let extended = extend(obj1, obj2);
        
        console.log(extended);
    // Task 6 
    function tower(floors) {
    let result = [];
    for(let i = 0; i < floors; i++) {
    result.push(" ".repeat(floors - i - 1) + "*".repeat(2*i + 1) + " ".repeat(floors - i - 1));
    }
    return result;
    }
    let pyramid = tower(5);
        
        console.log(pyramid);