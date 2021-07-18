
public class OSproject1 {
    public static void main(String[] args) throws Exception {
        final TestTry Testtry = new TestTry();
        Thread t1 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    Testtry.produce();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });

        Thread t2 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    Testtry.consume();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });


        t1.start();
        t2.start();

        t1.join();
        t2.join();
    }

    public static class TestTry {
        int capacity = 2;
        Queue queue = new Queue(capacity);


        public void produce() throws Exception {
            int value = 0;
            while (true) {
                synchronized (this) {
                    while (queue.isFull(queue)) {
                        wait();
                    }
                    System.out.println("PRODUCER PRODUCING: " + value);
                    queue.enqueue(value++);
                    notify();
                    Thread.sleep(1000);
                }
            }
        }

        public void consume() throws Exception {
            while (true) {
                synchronized (this) {
                    while (queue.isEmpty(queue)) {
                        wait();
                    }
                    int val = queue.dequeue();
                    System.out.println("CONSUMER CONSUMING: " + val);
                    notify();
                    Thread.sleep(1000);
                }
            }
        }


        class Queue {
            int front, back, size;
            int length;
            int array[];

            public Queue(int capacity) {
                this.length = capacity;
                front = this.size = 0;
                back = capacity - 1;
                array = new int[this.length];

            }

            boolean isFull(Queue queue) {
                return (queue.size == queue.length);
            }

            boolean isEmpty(Queue queue) {
                return (queue.size == 0);
            }

            int front() {
                if (isEmpty(this))
                    return Integer.MIN_VALUE;
                return this.array[this.front];
            }

            int back() {
                if (isEmpty(this))
                    return Integer.MIN_VALUE;
                return this.array[this.back];
            }

            void enqueue(int i) {
                if (isFull(this))
                    return;
                this.back = (this.back + 1) % this.length;
                this.array[this.back] = i;
                this.size = this.size + 1;
            }

            int dequeue() {
                if (isEmpty(this))
                    return Integer.MIN_VALUE;

                int x = this.array[this.front];
                this.front = (this.front + 1) % this.length;
                this.size = this.size - 1;
                return x;
            }

        }
    }
}




