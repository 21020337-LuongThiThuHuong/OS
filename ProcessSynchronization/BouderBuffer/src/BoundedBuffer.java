import java.util.concurrent.Semaphore;

public class BoundedBuffer implements Buffer{
    private static final int BUFFER_SIZE = 3;
    private int count; // số lượng items trong buffer
    private int in; // con trỏ trỏ tới vị trí free tiếp theo trong buffer
    private int out; // con trỏ trỏ tới vị trí đầu tiên trong buffer
    private Object[] buffer; // khai báo ra vùng đệm
    private Semaphore mutex; // semaphore mutex : 1 | 0
    private  Semaphore empty; // semphore empty chứa kích thước
    private  Semaphore full; // semaphore xem đã full hay chưa
    // constuctor
    public BoundedBuffer(){
        count = 0;
        in = 0;
        out = 0;
        buffer = new Object[BUFFER_SIZE];
        mutex = new Semaphore(1);
        empty = new Semaphore(BUFFER_SIZE);
        full = new Semaphore(0);
    }
    // producer
    // insert
    public void insert(Object item){
        // entry section
        try{
            // wait (empty)
            // wait (mutex)
            empty.acquire();
            mutex.acquire();
        }catch (InterruptedException e){
            System.out.println("Error in insert(): " + e);
        }
        // CS
        count++;
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;

        if(count == BUFFER_SIZE){
            System.out.println("Buffer Full " + "Producer inserted \"" + item + "\" count = " + count + ", "
            + "in = " + in + "out = " + out);
        }

        // exit section
        mutex.release();
        full.release();
    }
    // consumer
    // remove
    public Object remove(){
        Object item = null;
        // entry secion
        try{
            full.acquire();
            mutex.acquire();
        }catch (InterruptedException e){
            System.out.println("Error in remove(): " + e);
        }

        // CS
        count--;
        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        if (count == 0){
            System.out.println("BUFFER EMPTY "
                    + "Consumer removed \"" + item
                    + "\" count=" + count + ", "
                    + "in=" + in + ", out=" + out);
        }
        else{
            System.out.println("Consumer removed \"" + item
                    + "\" count=" + count + ", "
                    + "in=" + in + ", out=" + out);
        }

        // exit section
        mutex.release();
        empty.release();
        return item;
    }
}
