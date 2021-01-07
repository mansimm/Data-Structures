package Que2;

public class Tester {

	public static void main(String args[])
	{
		Employee e1 = new Employee("A",null);
		Employee e2 = new Employee("B",null);
		Employee e3 = new Employee("C",null);
		Employee e4 = new Employee("D",null);
		Employee e5 = new Employee("E",null);
		
		Employee emp[] = {e1,e2,e3,e4,e5};
		
		Job j1 = new Job("J1",30);
		Job j2 = new Job("J2",50);
		Job j3 = new Job("J3",10);
		Job j4 = new Job("J4",40);
		Job j5 = new Job("J5",60);
		Job j6= new Job("J6",10);
		Job j7 = new Job("J7",40);
		Job j8 = new Job("J8",60);
	
		Queue pending = new Queue(10);
		//pending.enqueue(j1);
		//pending.enqueue(j2);
		//pending.enqueue(j3);
		//pending.enqueue(j4);
		//pending.enqueue(j5);

		
		Company c = new Company(emp,pending);
		
		c.allocateNewJob(j1);
		c.allocateNewJob(j2);
		c.allocateNewJob(j3);
		c.allocateNewJob(j4);
		c.allocateNewJob(j5);
		c.allocateNewJob(j6);
		c.allocateNewJob(j7);
		c.allocateNewJob(j8);
		
		for(int i=0;i<emp.length;i++)
		{
			if(emp[i].getAllocatedJob()==null)
			{
				System.out.println(emp[i].getName()+" is not allocated job !");
			}
			else
				System.out.println(emp[i]);

		}
		
		Queue completed = c.elapsedTime(50);

		System.out.println("\n pending Jobs are :");
		c.getPendingJobs().display();
		/*
		for(int i=0;i<emp.length;i++)
		{
			if(emp[i]!=null)
			System.out.println(emp[i]);

		}*/
		System.out.println("\n Completed Jobs are :");
		completed.display();
	}

}
