var listTitle = "Student List (Alphabetical)";
var studentArray = ["John", "Bob", "Amy", "Haley", "Kimberly"];
window.onload=function()
{
    var myTitle = document.querySelector("#heading");
    myTitle.innerHTML += "<br><i><u>" + listTitle + "</u> </i>";

    var myContainer = document.querySelector("#outputContainer");
    studentArray.sort();
    var txt = "";
    for (var i=0; i<studentArray.length; i++)
    {
        txt += "<p>" + studentArray[i] +"</p>";
    }
    myContainer.innerHTML = txt;
   
};// onload
