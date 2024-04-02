// document.getElementById("clickme").addEventListener("click",function xyz(){
//     console.log("Button Clicked");
// });

function attacheventlistner(){
    let count = 0;
    document.getElementById("clickme")
    .addEventListener("click",function xyz(){
        console.log("button clicked");
    });
}
attacheventlistner();