import java.math.BigInteger;
import java.util.Scanner; 

class Main { 
	static BigInteger f[] = new BigInteger[1000];

    public static void main(String[] args) {
		f[0] = BigInteger.ONE;
		for (int i = 1; i < 1000; i++) f[i] = f[i-1].multiply(BigInteger.valueOf(i));

		Scanner sc = new Scanner(System.in);
		while (sc.hasNextInt()) {			
			int x = sc.nextInt();
			if (x == 0) break;

			int[] count = new int[10];
			for (int i = 0; i < 10; i++) count[i] = 0;
			for (char c : f[x].toString().toCharArray()) count[c - '0']++;

			System.out.println(String.format("%d! --", x));
			for (int i = 0; i < 5; i++) {
				System.out.print(String.format("   (%d)%5d", i, count[i]));
				if (i != 4) System.out.print(" ");
			}
			System.out.println();
			for (int i = 5; i < 10; i++) {
				System.out.print(String.format("   (%d)%5d", i, count[i]));
				if (i != 9) System.out.print(" ");
			}
			System.out.println();
		}
    	sc.close();
    } 
} 