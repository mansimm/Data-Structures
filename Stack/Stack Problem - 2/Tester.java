package Stack2;

class Tester {
    
    public static void main(String args[]) {
            
        Stack stack = new Stack(10);
        stack.push(7);
        stack.push(8);
        stack.push(5);
        stack.push(66);
        stack.push(5);

        System.out.println("initial stack");
        stack.display();
        
        stack= calculate(stack);
            
        System.out.println("Updated stack");
        stack.display();
    }

    public static Stack calculate(Stack stack) {
        //Implement your code here
    	
    	Stack temp1 = new Stack(10);
    	Stack ans = new Stack(10);

    	int min=100;
    	
    	while(!stack.isEmpty())
    	{
    		int x = stack.pop();
    		if(x<min)
    		{
    			min=x;
    		}
    		temp1.push(x);
    	}
    	while(!temp1.isEmpty())
    	{
    		int x= temp1.pop();
    		if(x==min)
    		{
    			ans.push(x);
    		}
    		else
    		{
    			stack.push(x);
    		}
    	}
    	while(!stack.isEmpty())
    	{
    		temp1.push(stack.pop());
    	}
    	while(!temp1.isEmpty())
    	{
    		ans.push(temp1.pop());
    	}
    	return ans;
    	
    	
    }
}
