package Que2;

public class Employee {

	private String name;
	private Job allocatedJob;
	
	public Employee(String name, Job allocatedJob) {
		this.name = name;
		this.allocatedJob = allocatedJob;
	}
	public String toString()
	{
		return "Emp Name: "+name+" Job: "+allocatedJob.getName()+
				" "+allocatedJob.getTimeNeeded()+
				" "+allocatedJob.getTimeElapsed();
	}
	public Job elapsedTime(int noOfMinites)
	{
		if(allocatedJob!=null && allocatedJob.elapsedTime(noOfMinites))
		{
			Job job = this.allocatedJob;
			this.allocatedJob=null;
			return job;
		}
		else 
			return null;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Job getAllocatedJob() {
		return allocatedJob;
	}

	public void setAllocatedJob(Job allocatedJob) {
		this.allocatedJob = allocatedJob;
	}
	
	
}
