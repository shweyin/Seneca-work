import java.util.Scanner;
public class PrintInt {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		System.out.println("Enter an Integer:");
		int num = in.nextInt();
		System.out.println(Integer.toBinaryString(num));
		System.out.println(Integer.toOctalString(num));
		System.out.println(Integer.toHexString(num));
		System.out.println("Reciprocol Hex:");
		float recip = (float) 1 / num;
		System.out.println(Float.toHexString(recip));
		in.close();
	}

}
