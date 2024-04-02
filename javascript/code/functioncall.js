var x = 1;
a();
b();
console.log(x);
//these functions forms a mini execution context within a environment.these functions takes the valuee which locally defined.in a() x = 10,and in b() x = 100,
function a(){
    var x = 10;
    console.log(x);
}
function b(){
    var x = 100;
    console.log(x);
}