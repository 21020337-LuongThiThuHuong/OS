public class Writer implements Runnable{
    private ReaderWriters person;
    private int writerId;

    public Writer(int writerId, ReaderWriters person) {
        this.writerId = writerId;
        this.person = person;
    }

    public void run(){
        while (true){
            person.busy();
            System.out.println("Writer " + writerId + " request to Write");
            person.joinWrite(writerId);
            person.busy();
            person.outRead(writerId);
        }
    }
}
// 4 cái request to Read thì deadlock