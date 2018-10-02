 package jac444.wk2;
 
 /**
  * Inherits point and adds a string 'label' to it
  * @author Shweyin
  *
  */
 public class LabeledPoint extends Point {
   private String label;
   /**
    * 
    * @param conLabel String label for this point
    * @param conX x coordinate of point
    * @param conY y coordinate of point
    */
   public LabeledPoint(String conLabel, double conX, double conY) { super(conX, conY);
    	this.label = new String(conLabel);
   }
   /**
    * 
    * @return returns label string
    */
   public String getLabel() {
	   return this.label;
   }
   /**
    * toString() overload
    */
   public String toString() {
	   return toString();
   }
   /**
    * equals(obj) overload
    * @param obj object reference
    */
   public boolean equals(Point obj) {
	   return equals(obj);
   }
   /**
    * hashcode() overload
    */
   public int hashCode() {
	   return hashCode();
   }
 }