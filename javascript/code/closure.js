//closure x() a = 7;

// function x(){
//     var a = 7;
//     function y(){
//         console.log(a);
//     }
//     y();
// }
// x();

// function x(){
//     var a = 10;
//     function y(){
//         console.log(a);
//     }
//     return y;
// }
// var z = x();
// console.log(z);
// z();

// function x(){
//     var a = 10;
//     return function y(){
//         console.log(a);
//     }
    
// }
// var z = x();
// console.log(z);
// z();

function x(){
    var a = 10;
    return function y(){
        console.log(a);
    }
}
var z = x()();
console.log(z);