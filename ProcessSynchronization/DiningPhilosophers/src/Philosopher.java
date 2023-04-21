import java.util.concurrent.ThreadLocalRandom;

public class Philosopher implements Runnable{
     private int phiNumber;
     private boolean isPre;
     Chopstick leftChopstick;
     Chopstick rightChopstick;
     public String status;

     public Philosopher(int number, Chopstick leftChopstick, Chopstick rightChopstick, boolean isPre){
          this.phiNumber = number;
          this.leftChopstick = leftChopstick;
          this.rightChopstick = rightChopstick;
          this.isPre = isPre;
          this.status =  "Waiting";
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
     public void run(){
          while (true){
                  action("Waiting");
                   leftChopstick.picksUpChopstick();
                   System.out.println("Phisolopher " + (phiNumber + 1) + " picks up leftChopstick");
                   action("Thinking");
                   rightChopstick.picksUpChopstick();
                   System.out.println("Phisolopher " + (phiNumber + 1) + " picks up rightChopstick");

                   action("Eatting");

                   leftChopstick.putDownChopstick();
                   System.out.println("Philosopher " + (phiNumber + 1) +
                           " puts down leftChopstick");
                   action("Thinking");
                   rightChopstick.putDownChopstick();
                   System.out.println("Philosopher " + (phiNumber + 1) +
                           " puts down rightChopstick");

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

               // if(isPre == false){
               //      action("Waiting");
               //      leftChopstick.picksUpChopstick();
               //      action("Thinking");
               //      rightChopstick.picksUpChopstick();
               //      action("Eating");
               //      leftChopstick.putDownChopstick();
               //      action("Thinking");
               //      rightChopstick.putDownChopstick();
               // }else{
               //      action("Waiting");
               //      rightChopstick.picksUpChopstick();
               //      action("Thinking");
               //      leftChopstick.picksUpChopstick();
               //      action("Eating");
               //      rightChopstick.putDownChopstick();
               //      action("Thinking");
               //      leftChopstick.putDownChopstick();
               // }
          }
     }
}
