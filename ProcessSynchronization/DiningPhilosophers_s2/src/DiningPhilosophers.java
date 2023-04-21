import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
// cách 2: kiểm tra điều kiện đặt đũa lên và xuôngS
public class DiningPhilosophers {
    public static void main(String[] args) {
        int defineNumber = 5;
        int count = 0;
        Philosopher philosopher [] = new Philosopher[defineNumber];
        Chopstick chopstick [] = new Chopstick[defineNumber];

        for(int i = 0; i < defineNumber; i++){
            chopstick[i] = new Chopstick();
        }
        ExecutorService executor = Executors.newFixedThreadPool(defineNumber);
        for(int i = 0; i < defineNumber; i++){
            if(i != defineNumber - 1){
                philosopher[i] = new Philosopher(i, chopstick[i], chopstick[(i + 1) % (defineNumber)]);
            }
            else{
                philosopher[i] = new Philosopher(i, chopstick[i], chopstick[(i + 1) % defineNumber] );
            }
            executor.execute(philosopher[i]);
        }

        while(true){
            System.out.println("================================================================");
            for(int i = 0; i < philosopher.length; i++){
                if(philosopher[i].status == "Thinking"){
                    count++;
                }
                if(i == 0){
                    count = 0;
                }
                System.out.println("Philosopher " + (i + 1) + " status: " + philosopher[i].status);
                if(count == 5) break;
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
