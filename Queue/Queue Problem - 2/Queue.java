package Que2;

class Queue {
    
    private int front;
    private int rear;
    private int maxSize;
    private Job arr[];
      
    Queue(int maxSize) {
        this.front = 0;
        this.rear = -1;
        this.maxSize = maxSize;
        this.arr = new Job[this.maxSize];
    }
      
    public boolean isFull() {
        if (rear == maxSize - 1) {
            return true;
        }
        return false;
    }
            
    public void enqueue(Job data) {
        if (isFull()) {
            System.out.println("Q is full ");
        } else {
            arr[++rear] = data;
            //return true;
        }
    }

    public void display() {
        if(isEmpty())
            System.out.println("Queue is empty!");
        else {
            for (int index = front; index <= rear; index++) {
                System.out.println(arr[index].getName()+" "+arr[index].getTimeNeeded()+" "+arr[index].getTimeElapsed());
            }
        }
    }
            
    public boolean isEmpty() {
        if (front > rear)
            return true;
        return false;
    }
            
    public Job dequeue() {
        if (isEmpty()) {
            return null;
        } else {
        	Job data = arr[this.front];
            arr[front++] = null;
            return data;
        }
    }

    public int getMaxSize() {
        return maxSize;
    }
}


