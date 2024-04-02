var box = document.getElementById("box");
var time = document.getElementById("time");
var count = 0;
box.addEventListener('click',function (){
    count++;
    time.innerText = count + " ";
})