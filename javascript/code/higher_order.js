// const radius = [2,6,3,7,5];

// function double(x){
//     return x*2;
// }

// const output = radius.map(double);
// const output = radius.map(x => x.toString(2));
// const output = radius.map(x => x*2);
// const output = radius.map(x => x*3);
// const output = radius.filter(x => x%2);
// const output = radius.filter(x => x%2===0);

// function isodd(x){
//     return x%2;
// }
// const output = radius.filter(isodd);
// const output = radius.filter(x => x>4);

// const output = radius.reduce(function (acc,curr){
//     acc += curr;
//     return acc;
// },0);
// const output = radius.reduce(function (acc,curr){
//     if(acc<curr){
//         acc = curr;
//     }
//     return acc;
// },0);
const users = [
    {firstname:"akshay",lastname:"saini",age:26},
    {firstname:"harsh",lastname:"kumar",age:75},
    {firstname:"elon",lastname:"musk",age:50},
    {firstname:"abhay",lastname:"roy",age:26},
]
// const output = users.map(x => x.firstname + " " + x.lastname);

// const output = users.reduce(function (acc,curr){
//     if(acc[curr.age]){
//         acc[curr.age] = ++acc[curr.age];
//     }
//     else{
//         acc[curr.age] = 1;
//     }
//     return acc;
// },{});

// const output = users.filter(x => x.age < 30).map(x => x.firstname);

const output = users.reduce(function (acc,curr){
    if(curr.age<30){
        acc.push(curr.firstname);
    }
    return acc;
},[]);
console.log(output);