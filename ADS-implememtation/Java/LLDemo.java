import java.util.*;

class Node{
    private int data;
    private Node next;
    public Node(int data){
        this.data = data;
    }
    public void setData(int data){
        this.data = data;
    }
    public int getData(){
        return this.data;
    }
    public void setNext(Node n){
        this.next = n;
    }
    public Node getNext(){
        return this.next;
    }
}

class LL{
    Node head;
    Node tail;
    public LL(){}
    public LL(Node head){
        this.head = head;
    }
    public void addNode(Node n){
        if(head == null){
            head = tail = n;
            return;
        }
        tail.setNext(n);
        tail = n;
    }
    public void addNode(int n){
        Node node = new Node(n);
        if(head == null){
            head = tail = node;
            return;
        }
        tail.setNext(node);
        tail = node;
    }
    public void traverse(){
        Node t = head;
        while(t != null){
            System.out.println(t.getData()+" ");
            t = t.getNext();
        }
    }
}

class LLDemo{
    public static void main(String[] args){
        LL ll = new LL();
        ll.addNode(7);
        ll.addNode(8);
        ll.addNode(2);
        ll.addNode(9);
        ll.traverse();
    }
}