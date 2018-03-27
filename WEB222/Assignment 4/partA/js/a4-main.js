var filterType = ""; // sets the filter type to "" (will later be dog, cat or bird)
var filterAgeMin = 0; // sets the filter age min to 0 (for no minimum age filter)
var filterAgeMax = Number.MAX_VALUE; // sets the filter age max to the largest number possible (for no maximum age filter)


window.onload = function ()
{
    loadTableWithFilters();
};
var loadTableWithFilters = function()
{
    mainTableBody = document.querySelector("#main-table-body");
    mainTableBody.innerHTML = "";
    for (var i = 0; i < petData.length; i++)
    {
        if(filterType == "")
        {
            addToRow(petData[i]);
        }
        if(filterType == "dog" && petData[i].type == "dog")
        {

        }
        if(filterType == "cat" && petData[i].type == "cat")
        {
            
        }
        if(filterType == "bird" && petData[i].type == "bird")
        {
            
        }
    }
}
var addToRow = function(petOBJ)
{
    var mainTableBody = document.querySelector("#main-table-body");
    var row = mainTableBody.insertRow();
    var td1 = row.insertCell();
    var td2 = row.insertCell();
    td1.innerHTML = "<img src =\"" + petOBJ.image.src +  "\" width =\"" + petOBJ.image.width + "\" height=\"" + petOBJ.image.height + "\" alt =\"" + petOBJ.image.alt + "\"/>";
    td2.innerHTML = "<p>" + petOBJ.description + "</p><span>Age: " + petOBJ.age + " years old.</span>";
}
var filterAllPets = function()
{
    filterAgeMin = 0;
    filterAgeMax = Number.MAX_VALUE;
    filterType = "";
    loadTableWithFilters();
}
var showDogs = function()
{
    filterType = "dog";
    loadTableWithFilters();
};
var showCats = function()
{
    filterType = "cat";
    loadTableWithFilters();
};
var showBirds = function()
{
    filterType = "bird";
    loadTableWithFilters();
};
var filter_zero_1 = function()
{
    filterAgeMax = 1;
    loadTableWithFilters();
};
var filter_1_3 = function()
{
    filterAgeMin = 1
    filterAgeMax = 3;
    loadTableWithFilters();
};
var filter_4_plus = function()
{
    filterAgeMin = 4;
    loadTableWithFilters();
};