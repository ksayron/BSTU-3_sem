//task 1 
let numbers = [1, 2, 3];

let [y] = numbers;

console.log(y); // 1
//task 2
let user = {
  name: 'виндовспро1989',
  age: 35
};

let admin = {
  admin:true,
  ...user
};

console.log(admin);

//task 3
let store = {
  state: { //1 уровень
    profilePage: {  //2 уровень  
      posts: [  //3 уровень
        {
          id: 1,  
          massage: 'Hi',
          likesCount: 12
        },
        {  
          id: 2,
          message: 'By',  
          likesCount: 1
        }
      ],
      newPostText: 'About me'
    },

    dialogsPage: {
      dialogs: [
        {id: 1, name: 'Valera'},
        {id: 2, name: 'Andrey'}, 
        {id: 3, name: 'Sasha'},
        {id: 4, name: 'Viktor'}  
      ],
      messages:[
        {id: 1, message: 'hi'},
        {id: 2, message: 'hi hi'},
        {id: 3, message: 'hi hi hi'}  
      ]
    }
  },

  sidebar: []
}

let {
  state: {
    profilePage: {
      posts: [
        {id, likesCount}, 
        {message, likesCount: likesCount2}
      ],  
      newPostText
    },

    dialogsPage: {
      dialogs,
      messages
    }
  },

  sidebar  
} = store;
  
console.log(likesCount,likesCount2); // 12, 1
 console.log(messages);
 console.log(dialogs.filter((dialog) => dialog.id % 2 == 0));
 let newMessages = messages.map(msg => ({message: "Hello user"}));
 console.log(newMessages)
 //task 4
  let tasks = [
     {id: 1, title: "HTML&CSS", isDone: true},
     {id: 2, title: "JS", isDone: true},
     {id: 3, title: "ReactJS", isDone: false},
     {id: 4, title: "Rest API", isDone: false},
     {id: 5, title: "GraphQL", isDone: false},
 ];

 tasks = [...tasks, {id: 6, title: "Paint buttons", isDone: false},]
 console.log(tasks);

 //task 5
  function sumValues(x, y, z){
     return x + y + z;
  }

 let array = [1,2,3];
 console.log(sumValues(...array));
 
//попросили написать пример вложенной деструктуризации
 let animal ={
  name:"Beaver",
  age:24,
  kids:[ {name:"Sam",age:11},{name:"Vic",age:8}]
 }
 let{
  kids:[
    {name,age},
    {name:name2,age:age2}
  ]
 }=animal
 console.log(name2)