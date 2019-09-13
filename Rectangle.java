
public class Rectangle {
	private float L;
	private float W;
	public void setN(float x,float y)
	{
		L=x;
		W=y;
	}
	public float area()
	{
		return (float)(L*W);
	}
	public static void main(String[] args) {
		Rectangle P= new Rectangle();
		P.setN(5,5);
		System.out.println("Area of Rectangle P is "+P.area());
	}
}
