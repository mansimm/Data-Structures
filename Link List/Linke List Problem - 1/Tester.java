/*
	Problem Statements-

	linklist nodes can contains charecters(alphabets,* or /)
	1.if one * or one / occures it should be replaced by space
	2.if * occurs twise(**) in adjacaent nodes replace them by only one  space and capttalize next charecter
	3.if / occures twice(//) in adjacent nodes replace them by single space and capitalize next charecter
	3.if / and * occures adjacent nodes replace them by single space and capitalize next charecter
	4.there are only two successive occurance of / or * not more than it .

input :         // A,n,*,/,a,p,p,l,e,*,a,/,day,*,*,k,e,e,p,s,/,*,a,/,/,d,o,c,t,o,r,*,A,w,a,y 

output :	 ,A,n, ,A,p,p,l,e, ,a, ,day, ,K,e,e,p,s, ,A, ,D,o,c,t,o,r, ,A,w,a,y 
*/



package linkelisttester1;


class Node {

    private String data;
    private Node next;

    public Node(String data) {
        this.data = data;
    }

    public void setData(String data) {
        this.data = data;
    }
      
    public void setNext(Node node) {
        this.next = node;
    }
      
    public String getData() {
        return this.data;
    }
      
    public Node getNext() {
        return this.next;
    }
}


class LinkedList {

    private Node head;
    private Node tail;

    public Node getHead() {
        return this.head;
    }
      
    public Node getTail() {
        return this.tail;
    }

    public void addAtEnd(String data) {
        Node node = new Node(data);

        if (this.head == null) {
            this.head = this.tail = node;
        } else {
            this.tail.setNext(node);

            this.tail = node;
        }
    }

    public void addAtBeginning(String data) {
        Node node = new Node(data);

        if (this.head == null) {
            this.head = this.tail = node;
        }

        else {
            node.setNext(this.head);
            this.head = node;
        }
    }

      public void display() {
        Node temp = this.head;

        while (temp != null) {
            System.out.println(temp.getData());
            temp = temp.getNext();
        }
    }

    public Node find(String data) {
        Node temp = this.head;

        while (temp != null) {
            if (temp.getData().equals(data))
                return temp;
            temp = temp.getNext();
        }
        return null;
    }

    public void insert(String data, String dataBefore) {
        Node node = new Node(data);

        if (this.head == null)
            this.head = this.tail = node;
        else {
            Node nodeBefore = this.find(dataBefore);
            if (nodeBefore != null) {
                node.setNext(nodeBefore.getNext());
                nodeBefore.setNext(node);
                if (nodeBefore == this.tail)
                    this.tail = node;
            } 
            else
                System.out.println("Node not found");
        }
    }

    public void delete(String data) {

        if (this.head == null)
            System.out.println("List is empty");
        else {
            Node node = this.find(data);

            if (node == null)
                System.out.println("Node not found");

            if (node == this.head) {
                this.head = this.head.getNext();
                node.setNext(null);
          
                if (node == this.tail)
                    tail = null;
            }
            else {
                Node nodeBefore = null;
                Node temp = this.head;
                while (temp != null) {
                    if (temp.getNext() == node) {
                    nodeBefore = temp;
                    break;
                    }
                    temp = temp.getNext();
                }

                nodeBefore.setNext(node.getNext());
                      
                if (node == this.tail)
                    this.tail = nodeBefore;
                node.setNext(null);
            }
        }
    }
}


class Tester {

    public static void main(String args[]) {
        LinkedList linkedList1 = new LinkedList();
        // A,n,*,/,a,p,p,l,e,*,a,/,day,*,*,k,e,e,p,s,/,*,a,/,/,d,o,c,t,o,r,*,A,w,a,y 
        linkedList1.addAtEnd("A");
        linkedList1.addAtEnd("n");
        linkedList1.addAtEnd("*");
        linkedList1.addAtEnd("/");
        linkedList1.addAtEnd("a");
        linkedList1.addAtEnd("p");
        linkedList1.addAtEnd("p");
        linkedList1.addAtEnd("l");
        linkedList1.addAtEnd("e");
        linkedList1.addAtEnd("*");
        linkedList1.addAtEnd("a");
        linkedList1.addAtEnd("/");
        linkedList1.addAtEnd("day");
        linkedList1.addAtEnd("*");
        linkedList1.addAtEnd("*");
        linkedList1.addAtEnd("k");
        linkedList1.addAtEnd("e");
        linkedList1.addAtEnd("e");
        linkedList1.addAtEnd("p");
        linkedList1.addAtEnd("s");
        linkedList1.addAtEnd("/");
        linkedList1.addAtEnd("*");
        linkedList1.addAtEnd("a");
        linkedList1.addAtEnd("/");
        linkedList1.addAtEnd("/");
        linkedList1.addAtEnd("d");
        linkedList1.addAtEnd("o");
        linkedList1.addAtEnd("c");
        linkedList1.addAtEnd("t");
        linkedList1.addAtEnd("o");
        linkedList1.addAtEnd("r");
        linkedList1.addAtEnd("*");
        linkedList1.addAtEnd("Away");
        
            
        System.out.println("Initial List");
        //linkedList1.display();
       Node temp1=linkedList1.getHead();String s1 = "";
        while(temp1!=null)
        {
        	s1=s1+""+temp1.getData();
        	temp1=temp1.getNext();
        }
        System.out.println(s1);
        
        createString(linkedList1);
        System.out.println("After List");
        //linkedList1.display();
        
        Node temp=linkedList1.getHead();String s = "";
        while(temp!=null)
        {
        	s=s+""+temp.getData();
        	temp=temp.getNext();
        }
        System.out.println(s);
     
    }

    public static void createString(LinkedList linkedList) 
    {
        //Implement your code here
    	Node temp = linkedList.getHead();
    	
    	String s ="";
    	while(temp!=null)
    	{
    		s = temp.getData();
    		if(s.equals("*") || s.equals("/"))
    		{
    			if(temp.getNext().getData().equals("*") || temp.getNext().getData().equals("/"))
				{
					temp.setData(" ");
					temp.setNext(temp.getNext().getNext());
					temp= temp.getNext();
					temp.setData(temp.getData().toUpperCase());
					temp = temp.getNext();
				}
				else
				{
					temp.setData(" ");
					temp =temp.getNext();
				}
    		}
    		else
    		{
    			temp=temp.getNext();
    		}
    	}
    		
    }

    
}

