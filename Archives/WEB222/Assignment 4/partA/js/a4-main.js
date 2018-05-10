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
        if(filterType == "" && isInAgeRange(filterAgeMin, filterAgeMax, petData[i].age))
        {
            addToRow(petData[i]);
        }
        if(filterType == "dog" && petData[i].type == "dog" && isInAgeRange(filterAgeMin, filterAgeMax, petData[i].age))
        {
            addToRow(petData[i]);
        }
        if(filterType == "cat" && petData[i].type == "cat" && isInAgeRange(filterAgeMin, filterAgeMax, petData[i].age))
        {
            addToRow(petData[i]);
        }
        if(filterType == "bird" && petData[i].type == "bird" && isInAgeRange(filterAgeMin, filterAgeMax, petData[i].age))
        {
            addToRow(petData[i]);
        }
    }
}
var isInAgeRange = function(min, max, age)
{
    var torf = false;
    if (age < max && age > min)
    {
        torf = true;
    }
    return torf;
}
var addToRow = function(petOBJ)
{
    var mainTableBody = document.querySelector("#main-table-body");
    var row = mainTableBody.insertRow();
    var td1 = row.insertCell();
    var td2 = row.insertCell();
    td1.innerHTML = "<img src =\"" + petOBJ.image.src +  "\" width =\"" + petOBJ.image.width + "\" height=\"" + petOBJ.image.height + "\" alt =\"" + petOBJ.image.alt + "\"/>";
    td2.innerHTML = "<h4>" + petOBJ.name + "</h4>" + "<p>" + petOBJ.description + "</p><span>Age: " + petOBJ.age + " years old.</span>";
};

var filterDog = function()
{
    filterType = "dog";
    loadTableWithFilters();
};
var filterCat = function()
{
    filterType = "cat";
    loadTableWithFilters();
};
var filterBird = function()
{
    filterType = "bird";
    loadTableWithFilters();
};
var filter_zero_1 = function()
{
    filterAgeMin = 0;
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
    filterAgeMax = Number.MAX_VALUE;
    loadTableWithFilters();
};
var filterAllPets = function()
{
    filterAgeMin = 0;
    filterAgeMax = Number.MAX_VALUE;
    filterType = "";
    loadTableWithFilters();
};