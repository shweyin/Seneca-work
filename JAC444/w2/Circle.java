package jac444.wk2;
 /**
  * Models a circle
  * has a point and a radius
  * @author Shweyin
  *
  */
public class Circle extends Shape {
   Point center;
   double radius;
   /**
    * takes 2 parameters
    * @param conCentre point for the center of the circle
    * @param conRadius length of the radius
    */
   public Circle(Point conCentre, double conRadius) {
	   this.center = conCentre;
	   this.radius = conRadius;
   }
   /**
    * @return returns the center of the circle as a point
    */
   public Point getCentre() {
	   return this.center;
   }
	public double shapeArea()
	{
		double area = (radius*radius) * 3.14;
		return area;
	}
 }
