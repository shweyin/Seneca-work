package jac444.wk2;
 /**
  * Defines a point with an x coordinate and y coordinate
  * @author Shweyin
  *
  */
 public class Point {
   protected double x;
   protected double y;
   /**
    * point constructor
    * @param conX x coordinate
    * @param conY y coordinate
    */
   public Point(double conX, double conY) {
    this.x = conX;
    this.y = conY;
   }
   /**
    * x coordinate accessor
    * @return x coordinate
    */
   public double getX() {
  return this.x;
   }
   /**
    * y coordinate accessor
    * @return y coordinate
    */
   public double getY() {
  return this.y;
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
    * @return true if equal
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
