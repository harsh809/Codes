// var box = document.getElementById("outer");

// box.addEventListener('mouseover',function (){
//     console.log("mouse-over");
// });
// box.addEventListener('mouseout',function (){
//     console.log("mouse-out");
// });

// var input = document.getElementById("search");

// input.addEventListener('keypress',function (){
//     console.log("key-pressed");
// });

// input.addEventListener('keydown',function (event){
//     console.log("key-down",event.keycode);
// });
// input.addEventListener('keyup',function (KeyboardEvent){
//     console.log("key-up",KeyboardEvent["keyCode"]);
// });

//event propagation

// var outer = document.getElementById("outer");
// var inner = document.getElementById("inner");

// outer.addEventListener('click',function (){
//     console.log("outer");
// })
// inner.addEventListener('click',function (event){
//     console.log("inner");
//     event.stopPropagation();

// })
// document.addEventListener('click',function(){
//     console.log("document");
// })