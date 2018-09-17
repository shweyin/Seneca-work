import java.util.Random;

public class PrintRandomString {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		long randLong = new Random().nextLong();
		System.out.println(Long.toString(randLong, 36));
	}

}
