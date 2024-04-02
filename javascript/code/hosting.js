// hosting is a phenomenon in javascript by which we are able to access the functions and variable even befor they are initializing it and put some values in it without any  error.
getname();
console.log(x);
console.log(getname);
var x = 7;
function getname(){
    console.log("hello world");
}
