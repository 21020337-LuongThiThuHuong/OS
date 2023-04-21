import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
public class DiningPhilosophers {
    public static void main(String[] args) {
        int defineNumber = 5;
        Philosopher philosopher [] = new Philosopher[defineNumber];
        Chopstick chopstick [] = new Chopstick[defineNumber];

        for(int i = 0; i < defineNumber; i++){
            chopstick[i] = new Chopstick();
        }
        ExecutorService executor = Executors.newFixedThreadPool(defineNumber);
        for(int i = 0; i < defineNumber; i++){
                philosopher[i] = new Philosopher(i, chopstick[i], chopstick[(i + 1) % (defineNumber)], false);
                // else{
            //     philosopher[i] = new Philosopher(i, chopstick[i], chopstick[(i + 1)%defineNumber], true);
            // }
            executor.execute(philosopher[i]);
        }

        while(true){
            System.out.println("================================================================");
            for(int i = 0; i < philosopher.length; i++){
                System.out.println("Philosopher " + (i + 1) + " status: " + philosopher[i].status);
            }
            System.out.println("=================================================================");
            try {
                Thread.sleep(5000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
