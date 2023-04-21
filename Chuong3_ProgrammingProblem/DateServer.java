import java.net.*;
import java.io.*;
public class DateServer{
		public static void main(String[] args) {
			try {
				ServerSocket sock = new ServerSocket(6013);
				/* now listen for connections */
				while (true) {
					Socket client = sock.accept();
					PrintWriter pout = new
					PrintWriter(client.getOutputStream(), true);
					/* write the Date to the socket */
					String quote = "My quote of the day";
					pout.println(new java.util.Date().toString());
					pout.println(quote);
					/* close the socket and resume */
					/* listening for connections */
					client.close();
				}
			}
			catch (IOException ioe) {
				System.err.println(ioe);
			}
		}	
}
