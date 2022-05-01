// JAVA
import java.util.Scanner;
 
class Main {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		int N=scan.nextInt(), Q=scan.nextInt();
		int[] V = new int[N+1], psa = new int[N+1];
		for (int i=1; i<=N; i++) V[i]=scan.nextInt();
		psa[1]=V[1];
		for (int i=2; i<=N; i++) psa[i]=psa[i-1]+V[i];
		for (int i=0; i<Q; i++) {
			int L=scan.nextInt(), R=scan.nextInt();
			int ans=psa[R]-psa[L-1];
			System.out.println(ans);
		}
	}
}  