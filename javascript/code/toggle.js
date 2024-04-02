var toggle = false;

var h1tag = document.getElementsByTagName("h1")[0];
var circle = document.getElementById("circle");
var body = document.getElementsByTagName("body")[0];

document.getElementById("toggle").onclick = function(){
    if(!toggle){
        h1tag.classList.add("color-white");
        body.classList.add("bck-color-black");
        circle.style.marginLeft = "100px";

        toggle = true;
    }
    else{
        h1tag.classList.remove("color-white");
        body.classList.remove("bck-color-black");
        circle.style.marginLeft = "1px";

        toggle = false;
    }
};