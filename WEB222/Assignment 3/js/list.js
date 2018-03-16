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
    var list1 = "<ol>";
    for(var i = 0; i < fruits.length; i++)
    {
        list1 += "<li>" + fruits[i] + "</li>";
    }
    list2 += "</ol>";
    list1div.innerHTML = list1;
    
    //List 2
    var list2div = document.querySelector("#list2");
    var list2 = "<ul>";
    for (var i = 0; i < directory.length; i++)
    {
        if(directory[i].type == "file")
        {
            list2 += "<li>" + directory[i].name + "</li>";
        }
        else
        {
            list2 += "<li>" + directory[i].name + "<ul>";
            for (var j = 0; j < directory[i].files.length; j++)
            {
                list2 += "<li>" + directory[i].files[j].name + "</li>";
            }
            list2 += "</ul>" + "</li>";
        }
    }
    list2 += "</ul>";
    list2div.innerHTML = list2;
};