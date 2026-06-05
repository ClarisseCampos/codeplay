/*C.R.U.D  stands for...
C = Create
R = Read
U = Update
D = Delete*/

/*---------------------------------------------- */
console.log("===== CREATE =====");

let users = [
    {
        "id": 1,
        "name": "Clarisse Campos",
        "email": "teteaaruda17@gmail.com",
        "age": 19
    }, 
    
    {
        "id": 2,
        "name": "Michael Jackson",
        "email": "heehee@gmail.com",
        "age": 60
    }];

function createUser(id, name, email, age){
    const newUser = {
        "id": id,
        "name": name,
        "email": email,
        "age": age
    };
    users.push(newUser); // object method
}
createUser(3, "Severino Ribeiro", "severino123@hotmail.com", 42);
console.log(users);

/*---------------------------------------------- */
console.log("===== READ =====");
function getUserById(id){
    return users.find(user => user.id === id); // object method
}
const user = getUserById(1);
console.log(user);

/*---------------------------------------------- */
console.log("===== UPDATE =====");

function updateUser(id, updatedData){
    const userIndex = users.findIndex(user => user.id === id); // method
    if(userIndex !== -1){
        users[userIndex] = { ...users[userIndex], ...updatedData};
    }
}
updateUser(1, { "name": "Johnathan Doe", "age": 31 });
console.log(users);

/*---------------------------------------------- */
console.log("===== DELETE =====");
function deleteUser(id){
    users = users.filter(user => user.id !== id);
}
deleteUser(2);
console.log(users);