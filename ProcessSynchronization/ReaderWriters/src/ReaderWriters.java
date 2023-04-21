import java.util.concurrent.Semaphore;
import java.util.concurrent.ThreadLocalRandom;

public class ReaderWriters {
    private static int readCount;
    private static Semaphore mutex;
    private static Semaphore wrt;

    public ReaderWriters() {
        readCount = 0;
        mutex = new Semaphore(1);
        wrt = new Semaphore(1);
    }

    public void joinRead(int readerId) {
        try {
            mutex.acquire();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        System.out.println("Reader " + readerId + " is READING");
        readCount++;
        if (readCount == 1) {
            try {
                wrt.acquire();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            System.out.println("Reader " + readerId + " is WRITING");
        }
        mutex.release();
    }

    public void outRead(int readerId){
        try {
            mutex.acquire();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        readCount--;
        System.out.println("Reader " + readerId + " stop READ");
        if(readCount == 0){
            wrt.release();
            System.out.println("Reader " + readerId + " stop WRITE");
        }
        mutex.release();
    }

    public void joinWrite(int writeId){

            try {
                wrt.acquire();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            readCount++;     
            System.out.println("Writer " + writeId + " is WRITING");
    }
    public void outWrite(int writeId){
        wrt.release();
        readCount--;
        System.out.println("Writer " + writeId + " stop WRITE");
    }
    public void busy(){
        try {
            Thread.sleep(ThreadLocalRandom.current().nextInt(1000, 3000));
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}
