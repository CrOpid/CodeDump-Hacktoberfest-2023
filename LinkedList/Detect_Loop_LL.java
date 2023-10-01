public class Detect_Loop_LL {

    public boolean hasCycle(Node head) {
        
        Node fast = head;
        Node slow = head;

        while (fast!=null && fast.next != null){

            fast = fast.next.next;
            slow = slow.next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
}
    
