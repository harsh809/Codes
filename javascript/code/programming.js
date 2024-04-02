// console.log("start");

// setTimeout(function (){
//     console.log("callback");
// },5000);

// console.log("end");

// let startDate = new Date().getTime();
// let endDate = startDate;
// while(endDate < startDate + 10000){
//     endDate = new Date().getTime();
// }
// console.log("while expire");

const radius = [3,6,1,8,5];

// const area = function (radius){
//     return Math.PI*radius*radius;
// };
// const circumference = function (radius){
//     return 2*Math.PI*radius;
// };
// const diameter = function (radius){
//     return 2*radius;
// };

// const calculate = function (logic,radius){
//     const output = [];
//     for(let i =0 ; i<radius.length ;i++){
//         output.push(logic(radius[i]));
//     }
//     return output;
// };
// console.log(calculate(area,radius));
// console.log(calculate(circumference,radius));
// console.log(calculate(diameter,radius));

const output = radius.map(x => Math.PI*x*x);
console.log(output);