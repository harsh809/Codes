var countinterval;

function startcounter(){
    var number = parseInt(document.getElementById("input").value);

    if(isNaN(number)){
        alert("Please Enter a number");
        clearInterval(countinterval);
        return;
    }
    if(number < 1 || number>9){
        alert("Out of Range");
        clearInterval(countinterval);
        return;
    }
    var currno = document.querySelector(".counter .current");
    var nextno = document.querySelector(".counter .next");
    var count = 0;

    reset(currno,nextno);

    clearInterval(countinterval);

    countinterval = setInterval(function (){
        if(count === number){
            clearInterval(countinterval);
            alert("Counter Has Stopped");
            return;
        }
        increasecount(currno,nextno);
        count++;
    },1000);
}

function reset(currno,nextno){
    currno.innertext = 0;
    nextno.innertext = 1; 
}

function increasecount(currentNo, nextNo) {

    nextNo.classList.add("animate");

    setTimeout(function () {
        currentNo.innerText = nextNo.innerText;
        nextNo.classList.remove("animate");
        nextNo.innerText = parseInt(nextNo.innerText) + 1;
    }, 500);

}