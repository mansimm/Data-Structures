package com.practice.heap;

public class MaxHeapDemo {

	int size = -1;
	int heap[] = new int[20];
	
	public int parent(int i)
	{
		return (i-1)/2;
	}
	public int left(int i)
	{
		return 2*i+1;
	}
	public int right(int i)
	{
		return 2*i+2;
	}
	
	public int getMax()
	{
		return heap[0];
	}
	public void insert(int x)
	{
		if(size==39)
		{
			System.out.println("Heap is full, cant insert");
			return;
		}
		size++;
		heap[size]=x;
		moveUp(size);
	}
	public void moveUp(int i)
	{
		while(i>0)
		{
			if(heap[parent(i)]<heap[i])
			{
				int temp = heap[parent(i)];
				heap[parent(i)]= heap[i];
				heap[i]=temp;
			}
			i=i/2;
		}
	}
	public void moveDown(int i)
	{
		int index = i;
		int left = left(i);
		int right = right(i);
		
		if( left<=size && heap[left]>heap[i])
		{
			i=left;
		}
		if(right<=size && heap[right]>heap[i])
		{
			i=right;
		}
		
		if(i!=index)
		{
			int temp = heap[index];
			heap[index] = heap[i];
			heap[i] = temp;
			if(i<size)
			{
				moveDown(i);
			}
		}
		
		
	}
	
	public int delete()
	{
		int x = heap[0];
		heap[0] = heap[size];
		heap[size] = x;
		size--;
		moveDown(0);
		return x;
	}
	
	public static void main(String args[])
	{
		MaxHeapDemo h = new MaxHeapDemo();
		h.insert(10);
		h.insert(50);
		h.insert(60);
		h.insert(30);
		h.insert(20);
		
		System.out.println("Heap : ");
		for(int i=0;i<=h.size;i++)
		{
			System.out.println(h.heap[i]);
		}
		System.out.println("Max : "+h.getMax());
		
		System.out.println("\nAfter sorting : ");
		for(int i=0;h.size>=0;i++)
		{
			System.out.println(h.delete());
		}
		
		/*
		System.out.println("\n Heap : ");
		for(int i=0;i<20;i++)
		{
			System.out.println(h.heap[i]);
		}
		*/
		
	}
}
