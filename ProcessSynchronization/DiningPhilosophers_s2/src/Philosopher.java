import java.util.concurrent.ThreadLocalRandom;

public class Philosopher implements Runnable{
    private int phiNumber;
    Chopstick leftChopstick;
    Chopstick rightChopstick;

    public String status;

    public Philosopher(int number, Chopstick leftChopstick, Chopstick rightChopstick){
        this.phiNumber = number;
        this.leftChopstick = leftChopstick;
        this.rightChopstick = rightChopstick;
        this.status = "waiting";
    }
    public void action(String action) {
        int waitTime = ThreadLocalRandom.current().nextInt(1000, 3000);
        try {
            Thread.sleep(waitTime);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
//          System.out.println("Philosopher " + (phiNumber + 1) + " " + action );
        this.status= action;

    }
    public void busy(){
        try {
            Thread.sleep(ThreadLocalRandom.current().nextInt(1000, 3000));
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
    public void run(){
        while (true){
//               action("Thinking");
//               if(isPre == false){
//                    leftChopstick.picksUpChopstick();
//                    System.out.println("Phisolopher " + (phiNumber + 1) + " picks up leftChopstick");
//                    rightChopstick.picksUpChopstick();
//                    System.out.println("Phisolopher " + (phiNumber + 1) + " picks up rightChopstick");
//
//                    action("Eatting");
//
//                    leftChopstick.putDownChopstick();
//                    System.out.println("Philosopher " + (phiNumber + 1) +
//                            " puts down leftChopstick");
//                    rightChopstick.putDownChopstick();
//                    System.out.println("Philosopher " + (phiNumber + 1) +
//                            " puts down rightChopstick");
//               }else{
//                    rightChopstick.picksUpChopstick();
//                    System.out.println("Phisolopher " + (phiNumber + 1) + " picks up rightChopstick");
//                    leftChopstick.picksUpChopstick();
//                    System.out.println("Phisolopher " + (phiNumber + 1) + " picks up leftChopstick");
//
//                    action("Eatting");
//
//                    rightChopstick.putDownChopstick();
//                    System.out.println("Philosopher " + (phiNumber + 1) +
//                            " puts down rightChopstick");
//                    leftChopstick.putDownChopstick();
//                    System.out.println("Philosopher " + (phiNumber + 1) +
//                            " puts down leftChopstick");
//               }
//
//            if(isPre == false){
//                action("Waiting");
//                leftChopstick.picksUpChopstick();
//                action("Thinking");
//                rightChopstick.picksUpChopstick();
//                action("Eating");
//                leftChopstick.putDownChopstick();
//                action("Thinking");
//                rightChopstick.putDownChopstick();
//            }else{
//                action("Waiting");
//                rightChopstick.picksUpChopstick();
//                action("Thinking");
//                leftChopstick.picksUpChopstick();
//                action("Eating");
//                rightChopstick.putDownChopstick();
//                action("Thinking");
//                leftChopstick.putDownChopstick();
//            }
            action("Waiting");
            leftChopstick.picksUpChopstick();
            action("Thinking");
            if(rightChopstick.isUsed == false){
                rightChopstick.picksUpChopstick();
                action("Eating");
                busy();
                leftChopstick.putDownChopstick();
            action("Thinking");
            rightChopstick.putDownChopstick();
            }else{
                leftChopstick.putDownChopstick();
                action("Waiting");
                continue;
            }
        }
    }
}
