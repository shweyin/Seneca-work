package jac444.wk2;
/**
 * Implements Measureable interface
 * @author Shweyin
 *
 */
public class Country implements Measureable
{
  String name;
  double areaKm2;
  /**
   * returns string with area
   */
  public String getArea()
  {
	  return (name + "'s area: " + Double.toString(areaKm2) + "km2");
  }
}
