
import java.util.HashSet;
class Node
{
	Integer data;
	Node next;

	public Node(Integer data)
	{
		this.data = data;
		this.next = null;
	}
	public static void push(Integer data)
	{
		Node n = new Node(data);
		if(DetectLoopSolution.head == null)
		{
			DetectLoopSolution.head = n;
		}
		else
		{
			n.next = DetectLoopSolution.head;
			DetectLoopSolution.head = n;
		}			

	}
	public static void detectLoop()
	{
		HashSet<Node> set = new HashSet();

		if(DetectLoopSolution.head==null)
		{
			System.out.println("Linked list is empty");
			return;
		}
		Node p = DetectLoopSolution.head;
		while(p != null)
		{
			if(set.contains(p))
			{
				System.out.println("Link list contains loop");
				return;
			}
			else
			{
				set.add(p);
			}
			p = p.next;

		}
		System.out.println("List does not have any loop");

	}
	public static void printList()
	{
		if(DetectLoopSolution.head == null)
		{
			System.out.println("List is empty");
		}
		else
		{
			Node p = DetectLoopSolution.head;
			while(p!=null)
			{
				System.out.println(p.data);
				p = p.next;
			}
		}

	}
}

public class DetectLoopSolution
{
	public static Node head = null;
	
	public static void main(String args[])
	{
		Node.push(10);
		Node.push(20);
		Node.push(30);
		Node.push(40);
		Node.push(50);
		
		head.next.next.next.next.next = head.next;
		Node.detectLoop();
		//Node.printList();

	}
}
