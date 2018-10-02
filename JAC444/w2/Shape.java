 package jac444.wk2;
 /**
  * Shape implements Measureable
  * contains point instance variable
  * @author Shweyin
  *
  */
 public abstract class Shape implements Measureable{
   Point point;
   /**
    * default constructor, no parameters
    */
   public Shape() {
    this.point = new Point(0.0D, 0.0D);
   }
   /**
    * moves the point by movX, movY
    * @param movX x wise translation
    * @param movY y wise translation
    */
   public void moveBy(double movX, double movY) {
   double tempX = this.point.getX();
   double tempY = this.point.getY();
   this.point = new Point(tempX + movX, tempY + movY);
   }
   /**
    * abstract 
    * @return area of shape
    */
   public abstract double shapeArea();
   /**
    * abstract
    * @return center of shape
    */
   public abstract Point getCentre();
   /**
    * @return area of shape as a string
    */
   public String getArea()
   {
	   return ("Shape area: " + Double.toString(shapeArea()));
   }
 }
