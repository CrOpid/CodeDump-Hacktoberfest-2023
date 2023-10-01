public class Middel_LL {
 
    public Node middleNode(Node head) {
        
        Node s = head, f = head;

        while(s!=null){

            if(f==null || f.next==null) return s;
            s = s.next;
            f = f.next.next;
        }

        return null;
    }

}
