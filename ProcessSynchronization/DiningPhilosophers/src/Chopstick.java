import java.util.concurrent.Semaphore;

public class Chopstick {
    public Semaphore chopstick = new Semaphore(1);

    public void picksUpChopstick(){
        try{
            chopstick.acquire();
        }catch (InterruptedException e){
            e.printStackTrace();
        }
    }

    public void putDownChopstick(){
        chopstick.release();
    }
}


// ý tưởng đầu tiên cho việc giải quyết deadlock là việc chọn 1 người và người đó sẽ lấy đũa theo thứ tự ngược lại so với
// những người còn lai success

// ý tưởng thứ 2 giải quyết vấn đề này nếu 1 người bất kì lấy đũa, họ sẽ cần kiểm tra xem trạng thái hiện tại của đũa
// là như thế nào, nếu đũa đã được lấy thì người đó sẽ tiến hành đặt đũa xuống