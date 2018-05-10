var addHeading = function()
{
    var heading2 = document.querySelector("#jsH2div");
    document.getElementById("jsH2div").style.color = "red";
    var h2 = document.createElement("h2");
    var headingText = document.createTextNode("Dynamic List Heading");
    h2.appendChild(headingText);
    heading2.appendChild(h2);
}