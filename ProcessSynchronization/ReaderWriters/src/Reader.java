import java.util.concurrent.ThreadLocalRandom;

public class Reader implements Runnable{
    private ReaderWriters person;
    private int readerId;

    public Reader(int readerId, ReaderWriters person){
        this.readerId = readerId;
        this.person = person;
    }

    public void run(){
        while(true){
            person.busy();
            System.out.println("Reader " + readerId + " request to Read");
            person.joinRead(readerId);
            // reading
            person.busy();
            person.outRead(readerId);

        }
    }
}
