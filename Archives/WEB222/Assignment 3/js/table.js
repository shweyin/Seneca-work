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
    table.border = "1";
    var tr = null, td = null, txt = null;

    /*
    tr = document.createElement("tr");
    for (var key in users[1])
    {
        if(users[1].hasOwnProperty(key))
        {
            th = document.createElement("th");
            txt = document.createTextNode(key);
            th.appendChild(txt);
            tr.appendChild(th);
        }
    }
    table.appendChild(tr);
    */
    tr = document.createElement("tr");
    txt = "<th>First Name</th><th>Last Name</th><th>Age</th><th>Email</th>";
    tr.innerHTML = txt;
    table.appendChild(tr);

    for(var i = 0; i < users.length; i++)
    {
        tr = document.createElement("tr");
        for (key in users[i])
        {
            if(users[i].hasOwnProperty(key))
            {
                if(key == "email")
                {
                    td = document.createElement("td");
                    txt = "<a href=\"mailto:" + users[i][key] + "\">" + users[i][key] + "</a>";
                    td.innerHTML = txt;
                    tr.appendChild(td);
                }
                else
                {
                    td = document.createElement("td");
                    txt = document.createTextNode(users[i][key]);
                    td.appendChild(txt);
                    tr.appendChild(td);
                }
            }
        }
        table.appendChild(tr);
    }
    tableDivContainer.appendChild(table);
};

//<a href="mailto:shweyin@gmail.com">Email Me</a>