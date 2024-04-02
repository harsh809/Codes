var cur = "square";

var shape = ["square", "rectangle", "circle", "oval", "triangle-up", "triangle-down", "triangle-topleft", "triangle-bottomleft", "triangle-bottomright", "triangle-right"];

var color = ["red", "orange", "green", "maroon", "pink", "violet"];


var block = document.getElementById("block");
document.getElementById("shape").onclick = function(){
    var random_shape = shape[Math.floor(Math.random()*shape.length)];
    document.getElementById(cur).setAttribute("id",random_shape);
    cur = random_shape;
};
document.getElementById("color").onclick = function(){
    var random_color = color[Math.floor(Math.random()*color.length)];
    block.style.backgroundColor = random_color;
};
