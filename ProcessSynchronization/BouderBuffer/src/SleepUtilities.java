public class SleepUtilities {
    private static final int NAP_TIME = 10;

    public static void nap(){
        nap(NAP_TIME);
    }
    private static void nap(int duration){
        int sleepTime = (int)(NAP_TIME * Math.random());
        System.out.println("Nap for " + sleepTime + "seconds");

        try {
            Thread.sleep(sleepTime* 1000);
        }catch (InterruptedException e){
            System.out.println("Error in nap(): " + e);
        }
    }
}
