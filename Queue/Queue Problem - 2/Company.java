package Que2;

public class Company {

	private Employee[] employees;
	private Queue pendingJobs;
	
	public Company(Employee[] employees, Queue pendingJobs) {
		this.employees = employees;
		this.pendingJobs = pendingJobs;
	}  
	
	public void allocateNewJob(Job job)
	{
		boolean alloc=false;
		for(int i=0;i<employees.length;i++)
		{
			if(employees[i].getAllocatedJob()==null)
			{
				employees[i].setAllocatedJob(job);
				alloc=true;
				break;
			}
		}
		if(!alloc)
		{
			pendingJobs.enqueue(job);
		}
	}
	
	public Queue elapsedTime(int noOfMinites)
	{
		boolean comp=false;
		Queue completed = new Queue(10);
		for(int i=0;i<employees.length;i++)
		{
			Job j = employees[i].elapsedTime(noOfMinites);
			if(j==null)
			{
				
			}
			else
			{
				completed.enqueue(j);
				comp=true;
			}
		}
		if(!comp)
		{
			return null;
		}
		else {
			return completed;
		}
		
	}
	
	public Employee[] getEmployees() {
		return employees;
	}
	public void setEmployees(Employee[] employees) {
		this.employees = employees;
	}
	public Queue getPendingJobs() {
		return pendingJobs;
	}
	public void setPendingJobs(Queue pendingJobs) {
		this.pendingJobs = pendingJobs;
	}
	

	
	
}
