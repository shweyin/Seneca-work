var listTitle = "Student List (Alphabetical)";
var studentArray = ["John", "Bob", "Amy", "Haley", "Kimberly"];

window.onload = function()
{
    var dom_greeting = document.querySelector("#greeting");
    dom_greeting.innerHTML = listTitle;
    var dom_list = document.getElementById("studentList");
    var txt = "";
    studentArray.sort();
    for (let i=0; i<studentArray.length; i++)
    {
        txt += studentArray[i] + "<br>"; 
    }
    dom_list.innerHTML = txt;
         
    // create a button
    /*
    var aBox = document.querySelector("#aBox");
    var dom_button = document.createElement("button");
    var dom_text = document.createTextNode("Click Me");
    dom_button.appendChild(dom_text);
    aBox.appendChild(dom_button);
    */
}
function addList()
{
    /// dynamically add student list by click a button
    var dom_addList = document.querySelector("#addList");
    var ol = document.createElement("ol");
   
    var li=null, li_text = null;
    for (var i = 0; i<studentArray.length; i++)
    {
        li = document.createElement("li");
        li_text = document.createTextNode(studentArray[i]);
        li.appendChild(li_text);
        ol.appendChild(li);
    }
    dom_addList.appendChild(ol);
}

function changeColor()
{
    var dom_list = document.getElementById("addList");
    dom_list.style.color = "blue";
}

var data=[ ["a11", "a12", "a13"],
           ["a21", "a22", "a23"],
           ["a31", "a32", "a33"]
         ];
function addTable()
{
    var dom_table = document.querySelector("#addTable");
    var table = document.createElement("table");
    var tr = null, td=null, txt=null;
    for (let i=0; i<data.length; i++)
    {
        tr = document.createElement("tr");
        for (let j=0; j<data[i].length;j++)
        {
            td = document.createElement("td");
            txt = document.createTextNode(data[i][j]);
            td.appendChild(txt);
            td.style.border="1px solid";
            tr.appendChild(td);
        }  // for each data cell
        table.appendChild(tr);
    } // for each row
    table.style.border="1px solid";
    dom_table.appendChild(table);

} //function addTable()


