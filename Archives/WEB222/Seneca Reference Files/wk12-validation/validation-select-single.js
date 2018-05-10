/* validation-select-single.js */
function checkForm() {
        var NoOfOptions = document.example.whatToDo.options.length;
        var messages="<p>No. of select whatToDo options = <mark>" + NoOfOptions + "</mark></p>";

        var whichOneSelected = document.example.whatToDo.selectedIndex;
        

        if (whichOneSelected == -1) {                                        
            messages += "<p style='color:red;'>None selected</p>"; 
            showErrors(messages); 
            return false; // return false - allow for changes - form not submitted
        }
        else {
            
            messages += "<p>You have selected - <mark>";
            messages += document.example.whatToDo.options[whichOneSelected].text + "</mark> with a value of <mark>";
            messages += document.example.whatToDo.options[whichOneSelected].value + "</mark></p>";
            showErrors(messages); 
            return false;        
            // return true;  

        }
    } // End of function


     function showErrors(messages) {
        
         document.querySelector('#errors').innerHTML = messages;

     }  //  End of function


     // ****************************************************************
     // ** Function Name : clearShowErrors()                          **
     // **                                                            **
     // ** Called from   : the html file                              **
     // ****************************************************************
     // ** Function Description                                       **
     // ** ====================                                       **
     // **                                                            **
     // ** This function is called if the clear button is clicked on  **
     // **                                                            **
     // ****************************************************************

 
     function  clearShowErrors() {

        document.querySelector('#errors').innerHTML = " ";
        document.querySelector('#client').focus();         
     }  //  End of function