

     // **************************************************************** 
     // ** Function Name : formValidationExample()
     // ** Called from   : js-form-validation-multipleField-error-on-page.html
     // ****************************************************************
     // ** Function Description
     // ** ====================
     // **
     // ** This function .........
     // **
     // ****************************************************************

     function formValidationExample() {

       clearErrors();            // Clear error message area

       var result = validateSurname();  // Call name validation function
	   result = validatePhoneNumber() && result;  // Call phone number validation function

       return result;

       // return validatePhoneNumber() && validateSurname();
 
     }  //  End of main function

     // ****************************************************************
     // ** Function Name : validateSurname()                         **
     // **                                                            **
     // ** Called from   : formValidationExample()                    **
     // ****************************************************************
     // ** Function Description                                       **
     // ** ====================                                       **
     // **                                                            **
     // ** This function ......                                       **
     // **                                                            **
     // ****************************************************************

     function validateSurname() {

       var nameMessageRules="<p> - Please enter a minimum of 4 alphabetic characters</p>";

       var stringName = document.querySelector("#client").value;
       stringName = stringName.trim();
       var stringLength = stringName.length;

       if (stringLength == 0) { 
         showErrors("<p><mark>Name</mark><br /> - The name field can not be left empty or just blank characters<br />" + nameMessageRules + "</p>");
         return false;
       } 

       if (stringLength < 4) {
		   showErrors( "<p><mark>Name</mark><br /> - You did not enter enough charcaters for the name<br />" + nameMessageRules + "</p>" );
           return false;
       }
		
       var countNonAlpha = 0;		
	   stringName = stringName.toUpperCase(); // easier to check  - otherwise you will need to check for upper and lower case inside the for loop                 

	   for (var i=0;i<stringLength;i++ ) {
		  if (! ( (stringName.charCodeAt(i) > 64) && (stringName.charCodeAt(i) < 91) ) ) {  // A=65  .....  Z=90 - upper case range
			 countNonAlpha++;
			 break;
		  } 
	   } // End of the for loop

	   if  (countNonAlpha) {
	      showErrors("<p><mark>Name</mark><br /> - Only alphabetic characters are allowed for the name<br />" + nameMessageRules + "</p>");
          return false;
       }
	   
	   return true;

     }  //  End of function

	 // ****************************************************************
     // ** Function Name : validatePhoneNumber()                      **
     // **                                                            **
     // ** Called from   : formValidationExample()                    **
     // ****************************************************************
     // ** Function Description                                       **
     // ** ====================                                       **
     // **                                                            **
     // ** This function .........                                    **
     // **                                                            **
     // ****************************************************************

     function validatePhoneNumber() {

       var messageRules="<p> - Please enter a phone number with the format of ###-###-####.</p>";

       var str = document.querySelector("#pnumber").value;
       str = str.trim();

       var stringLength = str.length;

       if (stringLength == 0) { 
		   showErrors("<p><mark>Phone Number</mark><br /> - The phone number field can not be left empty or just blank characters<br />" + messageRules + "</p>");
           return false;
       }  

       if (str.charAt(3) !== '-' || str.charAt(7) !== '-' || stringLength !== 12) {
		   showErrors("<p><mark>Phone Number</mark><br /> - The phone number was in wrong format.<br />" + messageRules + "</p>");
           return false;
	   }  
       else { 
	       var i, flag = true, myArray = str.split('-');
		   for (i = 0; i <3; i++) {
		      if (parseInt(myArray[i]) != myArray[i]) {
			     flag = false;
				 break;
			  }
		   }
		   
		   if (!flag) {
		      showErrors("<p><mark>Phone Number</mark><br /> - The phone number was in wrong format.<br />" + messageRules + "</p>");
              return false;
		   }
	   }

       return true;

     }  //  End of function
	 
     // ****************************************************************
     // ** Function Name : showErrors(messages)                       **
     // **                                                            **
     // ** Called from   : formValidationExample()                    **
     // ****************************************************************
     // ** Function Description                                       **
     // ** ====================                                       **
     // **                                                            **
     // ** This function is called if there are errors                **
     // **                                                            **
     // ****************************************************************


     function showErrors(messages) {
      
        document.querySelector('#errors').innerHTML += messages;

     }  //  End of function


     // ****************************************************************
     // ** Function Name : clearErrors()                          **
     // **                                                            **
     // ** Called from   : the html file                              **
     // ****************************************************************
     // ** Function Description                                       **
     // ** ====================                                       **
     // **                                                            **
     // ** This function is called if the clear button is clicked on  **
     // **                                                            **
     // ****************************************************************

 
     function  clearErrors() {

        document.querySelector('#errors').innerHTML = "";
        document.querySelector('#client').focus();         
     }  //  End of function