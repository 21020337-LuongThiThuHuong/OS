import java.util.concurrent.Semaphore;

public class Chopstick {
    public Semaphore chopstick = new Semaphore(1);
    boolean isUsed = false;
    public void picksUpChopstick(){
        try{
            chopstick.acquire();
            isUsed = true;
        }catch (InterruptedException e){
            e.printStackTrace();
        }
    }

    public void putDownChopstick(){
        chopstick.release();
        isUsed = false;
    }
}