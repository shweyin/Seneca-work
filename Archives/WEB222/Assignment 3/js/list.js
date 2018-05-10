// Data for the "HTML Lists" Page

var fruits = [ "Apples","Oranges","Pears","Grapes","Pineapples","Mangos" ];

var directory = [
    {type: "file", name: "file1.txt"},
    {type: "file", name: "file2.txt"},
    {type: "directory", name: "HTML Files", files: [{type: "file", name: "file1.html"},{type: "file", name: "file2.html"}]},
    {type: "file", name: "file3.txt"},
    {type: "directory", name: "JavaScript Files", files: [{type: "file", name: "file1.js"},{type: "file", name: "file2.js"},{type: "file", name: "file3.js"}]}
];

window.onload = function()
{
    //List 1
    var list1div = document.querySelector("#list1");
    var ol = document.createElement("ol");
    var li = null, li_text = null;
    for(var i = 0; i < fruits.length; i++)
    {
        //list1 += "<li>" + fruits[i] + "</li>";
        li = document.createElement("li");
        li_text = document.createTextNode(fruits[i]);
        li.appendChild(li_text);
        ol.appendChild(li);
    }
    list1div.appendChild(ol);
    
    //List 2
    var list2div = document.querySelector("#list2");
    var ul = document.createElement("ul");
    var li2 = null, li_text2 = null;
    for (var i = 0; i < directory.length; i++)
    {
        if(directory[i].type == "file")
        {
            li2 = document.createElement("li");
            li_text2 = document.createTextNode(directory[i].name);
            li2.appendChild(li_text2);
            ul.appendChild(li2);
        }
        
        else
        {
            li2 = document.createElement("li");
            li_text2 = document.createTextNode(directory[i].name); 
            li2.appendChild(li_text2);

            var ul2 = document.createElement("ul");
            var li3 = null, li_text3 = null;
            for (var j = 0; j < directory[i].files.length; j++)
            {
                li3 = document.createElement("li");
                li_text3 = document.createTextNode(directory[i].files[j].name);
                li3.appendChild(li_text3);
                ul2.appendChild(li3);
            }
            li2.appendChild(ul2);
            ul.appendChild(li2)
        }
    }
    list2div.appendChild(ul);
};