// console.log("start");
// setTimeout(function cb(){
//     console.log("callback");
// },5000);
// console.log("end");

// console.log("start");

// setTimeout(function cb(){
//     console.log("callback");
// },5000);

// fetch("https://api.netflix.com").then(function cbf(){
//     console.log("cbf");
// });
// console.log("end");

console.log("start");

setTimeout(function cb(){
    console.log("callback");
},5000);

DOMException(function cbf(){
    console.log("cbf");
});
console.log("end");