 package jac444.wk2;
 /**
  * Subclass of Shape
  * Has the top left point of the rectangle, width and length
  * @author Shweyin
  *
  */
 public class Rectangle extends Shape {
   Point topLeft;
   double width;
   double length;
   /**
    * constructor
    * @param conTopLeft top left corner of the rectangle as a point
    * @param conWidth width of the rectangle
    * @param conLength length of the rectangle
    */
   public Rectangle(Point conTopLeft, double conWidth, double conLength) {
   this.topLeft = conTopLeft;
  this.width = conWidth;
  this.length = conLength;
   }
   /**
    * returns the point of the center of the rectangle
    */
   public Point getCentre()
   {
   Point recCenter = new Point(this.topLeft.getX() + this.length / 2.0D, this.topLeft.getY() + this.width / 2.0D);
  return recCenter;
   }
   /**
    * returns the area of the rectangle
    */
	public double shapeArea()
	{
		double area = width * length;
		return area;
	}
 }
