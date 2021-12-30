import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class HuffmanTree {
    private Map<Character, String> Code;
    private Map<Character, Integer> counter;
    private Node root;

    public Map<Character, String> getCode() {
        return Code;
    }

    public void setCode(Map<Character, String> code) {
        Code = code;
    }

    public Map<Character, Integer> getCounter() {
        return counter;
    }

    public void setCounter(Map<Character, Integer> counter) {
        this.counter = counter;
    }

    public Node getRoot() {
        return root;
    }

    public void setRoot(Node root) {
        this.root = root;
    }

    public HuffmanTree() {
        this.Code = new HashMap<>();
        this.counter = new HashMap<>();
        root = null;
    }
    public String Encode(String Text) {
        setCounter(Text);
        this.root = this.Build_Huffman_Tree();
        this.setCodes(this.root, "");
        String Encode = "";
        for (int i = 0; i < Text.length(); i++) {
            Encode += this.Code.get(Text.charAt(i));
        }
        return Encode;
    }

    public String Decode(String Encode, Map<Character, Integer> Counter) {
        this.setCounter(Counter);
        this.root = this.Build_Huffman_Tree();
        String Decode = "";
        Node Temp = this.root;
        for (int i = 0; i < Encode.length(); i++) {
            if (Encode.charAt(i) == '0') {
                Temp = Temp.left_child;
            } else {
                Temp = Temp.right_child;
            }
            if (this.isLeaf(Temp)) {
                Decode += Temp.ch;
                Temp = this.root;
            }
        }
        return Decode;
    }
    //--
    private void setCounter(String Text) {
        for (int i = 0; i < Text.length(); i++) {
            if (counter.containsKey(Text.charAt(i))) {
                counter.put(Text.charAt(i), 1 + counter.get(Text.charAt(i)));
            } else {
                counter.put(Text.charAt(i), 1);
            }
        }
    }
    private Node Build_Huffman_Tree() {
        PriorityQueue<Node> nodes = get_Priority_nodes();
        Node root = null;
        while (!nodes.isEmpty()) {
            if (nodes.size() == 1) {
                root = nodes.poll();
            } else {
                Node a = nodes.poll();
                Node b = nodes.poll();
                Node c = new Node();
                c.ch = '-';
                c.count = a.count + b.count;
                c.left_child = a;
                c.right_child = b;
                nodes.offer(c);
            }
        }
        return root;
    }
    private PriorityQueue<Node> get_Priority_nodes() {
        Comparator<Node> Priority = new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                int dif = o1.count - o2.count;
                return dif;
            }
        };
        PriorityQueue<Node> nodes = new PriorityQueue<>(Priority);
        for (Character ch : this.counter.keySet()) {
            Node n = new Node();
            n.count = this.counter.get(ch);
            n.ch = ch;
            n.left_child = n.right_child = null;
            nodes.offer(n);
        }
        return nodes;
    }
    private void setCodes(Node n, String Str) {
        if (n != null) {
            if (isLeaf(n)) {
                this.Code.put(n.ch, Str);
            } else {
                this.setCodes(n.left_child, Str + "0");
                this.setCodes(n.right_child, Str + "1");
            }
        }
    }
    private boolean isLeaf(Node node) {
        return node.right_child == null && node.left_child == null;
    }
}
