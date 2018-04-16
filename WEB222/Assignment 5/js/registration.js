function formCheck()
{
    var good = false;
    var myLabel = document.getElementById("finalSubmit");
    if(username() && password() && phone() && cityCheck() && postalCheck())
    {
        good = true;
        myLabel.innerHTML = "";
    }
    else
    {
        myLabel.innerHTML = "Invalid Entry/Entries!";
    }
    return good;
}

function usernameCheck()
{
    good = false;
    var letters = /^[A-Za-z]+$/;
    var myElement = document.getElementById('Username');
    var myDiv = document.getElementById("usernameID");

    if(myElement.value.length > 5 && myElement.value.match(letters))
    {
        myDiv.innerHTML = "";
        good = true;
    }
    else
    {
        myDiv.innerHTML = "Username must be at least 6 characters and all letters";
    }
    return good;
}

function passwordCheck()
{
    good = false;
    var letters = /^[A-Za-z]+$/;
    var number = /\d/;
    var myElement = document.getElementById('Password');
    var myElement2 = document.getElementById('Password2')
    var myDiv = document.getElementById("passwordID");
    if (myElement.value.length > 7 && myElement.value.charAt(0).match(letters) && 
    myElement.value.toLowerCase() != myElement.value && number.test(myElement.value) &&
    myElement2.value == myElement.value)
    {
        myDiv.innerHTML = "";
        good = true;
    }
    else
    {
        myDiv.innerHTML = "Passwords must match, be more than 7 characters, start with a letter, and have at least 1 Uppercase and 1 Digit";
    }
    return good;
}

function phoneCheck()
{
    var good = false;
    var phone = /^\d{3}-\d{3}-\d{4}$/
    var myElement = document.getElementById('PhoneNumber');
    var myDiv = document.getElementById("numberID");
    if (phone.test(myElement.value))
    {
        myDiv.innerHTML = "";
        good = true;
    }
    else
    {
        myDiv.innerHTML = "Phone number must be all digits with a hypen in positions 4 and 8";
    }
    return good;
}

function cityCheck()
{
    var good = false;
    var letters = /^[A-Za-z]+$/;
    var myElement = document.getElementById('city');
    var myDiv = document.getElementById("cityID");
    if(letters.test(myElement.value))
    {
        myDiv.innerHTML = "";
        good = true;
    }
    else
    {
        myDiv.innerHTML = "Only letters are allowed";
    }
    return good;
}

function postalCheck()
{
    var good = false;
    var postalCode = /^[A-Za-z]\d[A-Za-z]\d[A-Za-z]\d$/;
    var myElement = document.getElementById('postal');
    var myDiv = document.getElementById("postalID");
    if(postalCode.test(myElement.value))
    {
        myDiv.innerHTML = "";
        good = true;
    }
    else
    {
        myDiv.innerHTML = "Must be in the format (Letter Digit Letter Digit Letter Digit)";
    }
    return good;
}

