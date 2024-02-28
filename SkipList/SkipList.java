import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class SkipList {
    private static final int MAX_LEVEL = 16;
    private Node header;
    private int level;

    public SkipList() {
        level = 0;
        header = new Node(Integer.MIN_VALUE, MAX_LEVEL);
    }

    private int randomLevel() {
        Random rand = new Random();
        int lvl = 0;
        while (lvl < MAX_LEVEL && rand.nextDouble() < 0.5)
            lvl++;
        return lvl;
    }

    public void insertElement(int key) {
        int level = randomLevel();
        Node[] update = new Node[level + 1];
        Node current = header;

        for (int i = level; i >= 0; i--) {
            while (current.forward.get(i) != null && current.forward.get(i).key < key)
                current = current.forward.get(i);
            update[i] = current;
        }
        current = current.forward.get(0);

        if (current == null || current.key != key) {
            Node newNode = new Node(key, level);
            for (int i = 0; i <= level; i++) {
                newNode.forward.set(i, update[i].forward.get(i));
                update[i].forward.set(i, newNode);
            }
        }
    }

    public void deleteElement(int key) {
        Node[] update = new Node[level + 1];
        Node current = header;

        for (int i = level; i >= 0; i--) {
            while (current.forward.get(i) != null && current.forward.get(i).key < key)
                current = current.forward.get(i);
            update[i] = current;
        }
        current = current.forward.get(0);

        if (current != null && current.key == key) {
            for (int i = 0; i < level; i++) {
                if (update[i].forward.get(i) != current)
                    break;
                update[i].forward.set(i, current.forward.get(i));
            }
        }
    }

    public void searchElement(int key) {
        Node current = header;
        for (int i = level; i >= 0; i--) {
            while (current.forward.get(i) != null && current.forward.get(i).key < key)
                current = current.forward.get(i);
        }
        current = current.forward.get(0);
        if (current != null && current.key == key)
            System.out.println("Found key: " + key);
        else
            System.out.println("Not Found key: " + key);
    }

    public void displayList() {
        System.out.println("Skip List:");
        for (int i = 0; i <= level; i++) {
            Node node = header.forward.get(i);
            System.out.print("Level " + i + ": ");
            while (node != null) {
                System.out.print(node.key + " ");
                node = node.forward.get(i);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        SkipList skipList = new SkipList();

        // Insert elements
        skipList.insertElement(3);
        skipList.insertElement(6);
        skipList.insertElement(7);
        skipList.insertElement(9);
        skipList.insertElement(12);
        skipList.insertElement(19);
        skipList.insertElement(17);
        skipList.insertElement(26);
        skipList.insertElement(21);
        skipList.insertElement(25);

        // Display the skip list
        skipList.displayList();

        // Search for an element
        skipList.searchElement(19);

        // Delete an element
        skipList.deleteElement(19);
        skipList.displayList();
    }
}

class Node {
    int key;
    List<Node> forward;

    Node(int key, int level) {
        this.key = key;
        forward = new ArrayList<>(level + 1);
        for (int i = 0; i <= level; i++)
            forward.add(null);
    }
}