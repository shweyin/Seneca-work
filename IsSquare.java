import java.util.ArrayList;
import java.util.Scanner;

public class IsSquare {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Integer> rowOfInts = new ArrayList<Integer>();
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNextInt())
		{
			rowOfInts.add(scanner.nextInt());
			System.out.println(rowOfInts);
		}
		System.out.println("here");
		scanner.close();
	}

}
