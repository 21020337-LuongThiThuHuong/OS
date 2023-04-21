import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {
    public static void main(String[] args) {
        ReaderWriters person = new ReaderWriters();
        ExecutorService executor = Executors.newFixedThreadPool(7);
        Reader reader[] = new Reader[5];
        Writer writer[] = new Writer[2];
        for(int i = 0; i < writer.length; i++){
            writer[i] = new Writer(i + 1, person);
            executor.execute(writer[i]);
        }
        for(int i = 0; i < reader.length; i++){
            reader[i] = new Reader(i + 1, person);
            executor.execute((reader[i]));
        }

    }
}
