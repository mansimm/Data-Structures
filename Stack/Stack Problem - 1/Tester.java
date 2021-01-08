package stack1;

class Tester {
    
    public static void main(String args[]) {
            
        Stack stack = new Stack(10);
        
        Ball b1 = new Ball("Red","A");
        Ball b2 = new Ball("Blue","B");
        Ball b3 = new Ball("Yellow","B");
        Ball b4 = new Ball("Blue","A");
        Ball b5 = new Ball("Yellow","A");
        Ball b6 = new Ball("Green","B");
        Ball b7 = new Ball("Green","A");
        Ball b8 = new Ball("Red","B");

        stack.push(b1);
        stack.push(b2);
        stack.push(b3);
        stack.push(b4);
        stack.push(b5);
        stack.push(b6);
        stack.push(b7);
        stack.push(b8);
        
        Game G =new Game(stack);
        
            
        System.out.println("\n	 Initial stack");
        stack.display();
        
        System.out.println("\n	Reaaranged stacks..............");

        G.groupinBasedOnColor();
        G.rearrangeBalls();
        G.displayBallDetails();

    }

    public static void calculateSum(Stack stack) {
        //Implement your code here
    }
}