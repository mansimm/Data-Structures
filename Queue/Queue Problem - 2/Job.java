package Que2;

public class Job {

	private String name;
	private int timeNeeded;
	private int timeElapsed=0;
	
	public Job(String name, int timeNeeded) {
		this.name = name;
		this.timeNeeded = timeNeeded;
		this.timeElapsed = 0;
	}
	public boolean elapsedTime(int noOfMinites)
	{
		this.timeElapsed += noOfMinites;
		if(this.timeElapsed>=this.timeNeeded)
		{
			return true;
		}
		return false;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getTimeNeeded() {
		return timeNeeded;
	}

	public void setTimeNeeded(int timeNeeded) {
		this.timeNeeded = timeNeeded;
	}

	public int getTimeElapsed() {
		return timeElapsed;
	}

	public void setTimeElapsed(int timeElapsed) {
		this.timeElapsed = timeElapsed;
	}
	
	
	
	
}
