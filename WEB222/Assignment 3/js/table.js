// Data for the "HTML Tables" Page

var users = [
    {first_name: "Kaitlin", last_name: "Burns", age: 23, email: "kburns99753@usermail.com"},
    {first_name: "Joshua", last_name: "Feir", age: 31, email: "josh319726@usermail.com"},
    {first_name: "Stephen", last_name: "Shaw", age: 28, email: "steve.shaw47628@usermail.com"},
    {first_name: "Timothy", last_name: "McAlpine", age: 37, email: "Timbo72469@usermail.com"},
    {first_name: "Sarah", last_name: "Connor", age: 19, email: "SarahC6320@usermail.com"}
];

window.onload = function()
{
    var tableDivContainer = document.querySelector("#tableDivID");
    var table = document.createElement("table");
    var tr = null, td = null, txt = null;
    for(var i = 0; i < users.length; i++)
    {
        tr = createElement("tr");

        td = createElement("td");
        txt = createTextNode(users[i].first_name);
        td.appendChild(txt);
        tr.appendChild(td);

        //td = createElement("td");
        txt = createTextNode(users[i].last_name);
        td.appendChild(txt);
        tr.appendChild(td);

        //td = createElement("td");
        txt = createTextNode(users[i].age);
        td.appendChild(txt);
        tr.appendChild(td);

        //td = createElement("td");
        txt = createTextNode(users[i].email);
        td.appendChild(txt);
        tr.appendChild(td);

        table.appendChild(tr);
    }
    table.style.border = "1px solid";
    tableDivContainer.appendChild(table);
};

//<a href="mailto:shweyin@gmail.com">Email Me</a>