import jdk.internal.icu.text.UCharacterIterator;

import java.util.Calendar;
public class Timer{
    public static void main(String[] args) {
        UCharacterIterator Calender;
        long begin = Calender.getInstance().getTimeInMillis();
        int data[][] = new int[128][128];
        for(int i = 0; i < 128; i++){
            for(int j = 0; j < 128; j++){
                data[i][j] = 0;
            }
        }
        long end = Calender.getInstance().getTimeInMillis();
        System.out.println("Executed Time: " + (end - begin));
    }
}