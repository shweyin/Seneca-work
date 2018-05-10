     // Subject       : INT222 
     // Author        : Your Name
     // Written on    : 
     // Last Modified : 


       function checkForm() {

               var NoOfOptions = document.example.whatToDo.options.length;
               var messages="<p>No. of select wish list options = <mark>" + NoOfOptions + "</mark></p>";

               var result="";

               for (var i = 0; i < NoOfOptions; i++) {

                 if (document.example.whatToDo[i].selected==true) {
                    result += "<p>You have selected <mark>";
                    result += document.example.whatToDo[i].text + "</mark> with a value of <mark>";
                    result += document.example.whatToDo[i].value + "</mark></p>";
                 } // end of if

               } // End of for


               if (result=="") { 
                    messages += "<p>None selected</p>"; 
                    showErrors(messages); 
                    return false; // return false - allow for changes - form not submitted
               }
               else { 
                    messages += "<p>You have selected - <mark>" + result + "</p>";
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