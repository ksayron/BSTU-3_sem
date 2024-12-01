ц//task 1
let user = {
  name: 'Masha',
  age: 21
};

let userCopy = { ...user };

//task 2
let numbers = [1, 2, 3];

let numbersCopy = [...numbers];
console.log(numbersCopy);

//task 3
let user1 = {
  name: 'Masha',
  age: 23,
  location: {
      city: 'Minsk',
      country: 'Belarus'
  }
};

let user1Copy = { ...user1, location: { ...user1.location } };
user1Copy.age=24;
console.log(user1);
console.log(user1Copy);

//task 4
let user2 = {
  name: 'Masha',
  age: 28,
  skills: ["HTML", "CSS", "JavaScript", "React"]
};

let user2Copy = { ...user2, skills: [...user2.skills] }
console.log(user2);
console.log(user2Copy);

//task 5
const array = [
  { id: 1, name: 'Vasya', group: 10 },
  { id: 2, name: 'Ivan', group: 11 },
  { id: 3, name: 'Masha', group: 12 },
  { id: 4, name: 'Petya', group: 10 },
  { id: 5, name: 'Kira', group: 11 },
];

let arrayCopy = array.map(el => ({ ...el }));

//task 6
let user4 = {
  name: 'Masha',
  age: 19,
  studies: {
      university: 'BSTU',
      speciality: 'deisgner',
      year: 2020,
      exams: {
          maths: true,
          programming: false
      }
  }
};

let user4Copy = {
  ...user4,
  studies: {
      ...user4.studies,
      exams: {
          ...user4.studies.exams,
      }
  },
};

console.log(user4);
console.log(user4Copy);

//task 7 
let user5 = {
  name: 'Masha',
  age: 22,
  studies: {
      university: 'BSTU',
      speciality: 'deisgner',
      year: 2020,
      department: {
          faculty: 'FIT',
          group: 10,
      },
      exams: [
          { maths: true, mark: 8 },
          { programming: true, mark: 4 },
      ]
  }
};

let user5Copy = {
  ...user5,
  studies: {
      ...user5.studies,
      department: {
          ...user5.studies.department
      },
      exams: user5.studies.exams.map(el => ({ ...el })),

  }
}

user5Copy.studies.department.group = 12;
user5Copy.studies.exams[1].mark = 10;
console.log(user5);
console.log(user5Copy);

//task 8 
let user6 = {
  name: 'Masha',
  age: 21,
  studies: {
      university: 'BSTU',
      speciality: 'deisgner',
      year: 2020,
      department: {
          faculty: 'FIT',
          group: 10,
      },
      exams: [
          {
              maths: true,
              mark: 8,
              professor: {
                  name: 'Ivan Ivanov',
                  degree: 'PhD'
              }
          },
          {
              programming: true,
              mark: 10,
              professor: {
                  name: 'Petr Petrov',
                  degree: 'PhD'
              }
          },
      ]
  }
};

let user6Copy = {
  ...user6,
  studies: {
      ...user6.studies,
      department: {
          ...user6.studies.department
      },
      exams: user6.studies.exams.map(el => (
          {
              ...el,
              professor: {
                  ...el.professor
              }
          }
      ))
  }
}

user6Copy.studies.exams[0].professor.name = "Yarotskaya";
user6Copy.studies.exams[1].professor.name = "Kudlatskaya";
console.log(user6);
console.log(user6Copy);

//task 9
let user7 = {
  name: 'Masha',
  age: 20,
  studies: {
      university: 'BSTU',
      speciality: 'deisgner',
      year: 2020,
      department: {
          faculty: 'FIT',
          group: 10,
      },
      exams: [
          {
              maths: true,
              mark: 8,
              professor: {
                  name: 'Ivan Ivanov',
                  degree: 'PhD',
                  articles: [
                      { title: "About HTML", pageNumber: 3 },
                      { title: "About CSS", pageNumber: 5 },
                      { title: "About JavaScript", pageNumber: 1 },
                  ]
              }
          },
          {
              programming: true,
              mark: 10,
              professor: {
                  name: 'Petr Petrov',
                  degree: 'PhD',
                  articles: [
                      { title: "About HTML", pageNumber: 3 },
                      { title: "About CSS", pageNumber: 5 },
                      { title: "About JavaScript", pageNumber: 1 },
                  ]
              }
          },
      ]
  }
};

let user7Copy = {
    ...user7,
    studies: {
      ...user7.studies,
      department: {
        ...user7.studies.department
      },
      exams: [...user7.studies.exams].map(exam => ({
        ...exam,
        professor: {
          ...exam.professor,
          articles: [...exam.professor.articles].map(article => ({
            ...article
          }))
        }
      }))
    }
  };

user7Copy.studies.exams[1].professor.articles[1].pageNumber = 3;
user7Copy.studies.exams[0].mark=10;
console.log(user7);
console.log(user7Copy);


//task 10
let store = {
  state: {
      profilePage: {
          posts: [
              { id: 1, message: 'Hi', likesCount: 12 },
              { id: 2, message: 'By', likesCount: 1 },
          ],
          newPostText: 'About me',
      },
      dialogsPage: {
          dialogs: [
              { id: 1, name: 'Valera' },
              { id: 2, name: 'Andrey' },
              { id: 3, name: 'Sasha' },
              { id: 4, name: 'Viktor' }
          ],
          messages: [
              { id: 1, message: 'hi' },
              { id: 2, message: 'hi hi,' },
              { id: 3, message: 'hi hi hi' }
          ],
      },

      sidebar: [],
  },
}

let storeCopy = {
    ...store,
    state: {
      ...store.state,
      profilePage: {
        ...store.state.profilePage,
        posts: [...store.state.profilePage.posts],
      },
      dialogsPage: {
        ...store.state.dialogsPage,
        dialogs: [...store.state.dialogsPage.dialogs],
        messages: [...store.state.dialogsPage.messages],
      },
      sidebar: [...store.state.sidebar],
    },
  };

storeCopy.state.profilePage.posts.map(num => num.message = "Hello");
storeCopy.state.dialogsPage.messages.map(num => num.message = "Hello");
console.log(store);
console.log(storeCopy);
