
public class Circle {
	private	float R;
	public void setR(float x)
	{
		R=x;
	}
	public float area()
	{
		return (float)(R*R*Math.PI);
	}
	public static void main(String[] args) {
		Circle O= new Circle();
		O.setR(5);
		System.out.println("Area of circle O is "+O.area());
	}
}
