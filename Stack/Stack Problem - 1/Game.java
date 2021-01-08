package stack1;

public class Game {
	
	Stack ball;
	Stack redBall;
	Stack greenBall;
	Stack blueBall;
	Stack yellowBall;
	
	public Game(Stack ball) {
		this.ball = ball;
		redBall = new Stack(2);
		greenBall = new Stack(2);
		blueBall = new Stack(2);
		yellowBall = new Stack(2);

	}
	
	public void groupinBasedOnColor()
	{
		while(!ball.isEmpty())
		{
			Ball b = ball.pop();
			
			if(b.getColor().contentEquals("Red"))
			{
				redBall.push(b);
			}
			else if(b.getColor().contentEquals("Green"))
			{
				greenBall.push(b);
			}
			else if(b.getColor().contentEquals("Blue"))
			{
				blueBall.push(b);
			}
			else if(b.getColor().contentEquals("Yellow"))
			{
				yellowBall.push(b);
			}
		}
	}
	
	public void rearrangeBalls()
	{
		Stack temp1 = new Stack(2);
		Stack temp2 = new Stack(2);
		Stack temp3 = new Stack(2);
		Stack temp4 = new Stack(2);

		
		if(redBall.peek().getName().equals("A"))
		{
			
		}
		else
		{
			temp1.push(redBall.pop());
			temp1.push(redBall.pop());
			redBall = temp1;
		}
		
		if(greenBall.peek().getName().equals("A"))
		{
			
		}
		else
		{
			temp2.push(greenBall.pop());
			temp2.push(greenBall.pop());
			greenBall = temp2;
		}
		
		if(blueBall.peek().getName().equals("A"))
		{
			
		}
		else
		{
			temp3.push(blueBall.pop());
			temp3.push(blueBall.pop());
			blueBall = temp3;
		}
		
		if(yellowBall.peek().getName().equals("A"))
		{
			
		}
		else
		{
			temp4.push(yellowBall.pop());
			temp4.push(yellowBall.pop());
			yellowBall = temp4;
		}
		
	}
	
	public void displayBallDetails()
	{
		System.out.println("Red Ball : ");
		redBall.display();
		System.out.println("Green Ball : ");
		greenBall.display();
		System.out.println("Blue Ball : ");
		blueBall.display();
		System.out.println("Yellow Ball : ");
		yellowBall.display();
	}

}
