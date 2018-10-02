package jac444.wk2;
 /**
  * Subclass of Shape
  * contains 2 points that make a line
  * @author Shweyin
  *
  */
 public class Line extends Shape {
   Point p1;
   Point p2;
   /**
    * constructor
    * @param from point a
    * @param to point b
    */
   public Line(Point from, Point to) {
   this.p1 = from;
   this.p2 = to;
   }
   /**
    * returns a point of the midway point of the two points
    */
   public Point getCentre() {
	   Point lineCenter = new Point((this.p1.getX() + this.p2.getX()) / 2.0D, (this.p1.getY() + this.p2.getY()) / 2.0D);
	   return lineCenter;
   }
   /**
    * returns 0
    */
	public double shapeArea()
	{
		return 0.0D;
	}
 }
