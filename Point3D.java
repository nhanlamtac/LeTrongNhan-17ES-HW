public class Point3D
{
	private double x,y,z;
	public Point3D(double x, double y, double z)
	{
		this.x = x;
		this.y = y;
		this.z = z;
	}
	public double distanceFromCenter()
    {
		return distanceFrom(0,0,0);
    }
	public double distanceFrom(Point3D other)
    {
		return Math.sqrt(Math.pow(x-other.x,2)+ Math.pow(y-other.y,2)+ Math.pow(z-other.z,2));
    }
 
	public double distanceFrom(double xVal, double yVal, double zVal)
	{
		return Math.sqrt(Math.pow(x-xVal,2)+ Math.pow(y-yVal,2)+ Math.pow(z-zVal,2));
	}

	public void details()
	{
             	System.out.println("x="+x+ "y="+y+" z="+z);
	}
public static void main(String args[])
  	{
		Point3D point1, point2;
        point1 = new Point3D(2,3,4);
        point2 = new Point3D(3,7,8);
        System.out.print("point1:");
              	point1.details();
        System.out.print("point2:");
                point2.details();
        System.out.println("The distance between point1 and (0,0,0) is : " + point1.distanceFromCenter());
        System.out.println("The distance between point1 and point2 is : " + point1.distanceFrom(point2));
  	}
}
