import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Test {
    static HuffmanTree huffmanTree;
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        huffmanTree = new HuffmanTree();
        while (true) {
            System.out.println("1. Text to Code");
            System.out.println("2. Code to Text");
            System.out.println("3. Check to Correct");
            System.out.println("4. exit");
            int menu = sc.nextInt();
            if (menu == 1) text_to_code();
            else if (menu == 2) code_to_text();
            else if (menu == 3) check_to_correct();
            else System.exit(-1);
        }
    }
    private static void text_to_code() throws Exception{
        try {
            BufferedReader bf = new BufferedReader(new FileReader(new File("text.txt")));
            String Text = "";
            String s;
            while ((s = bf.readLine()) != null) {
                Text += s;
            }
            bf.close();
            String Encode = huffmanTree.Encode(Text);
            System.out.println("text : '" + Text + "' convert to : " + Encode);
            System.out.println("code is : " + huffmanTree.getCode().toString());
            FileWriter Writer = new FileWriter("code.txt");
            Writer.write(Encode + "\n");
            for (Character ch : huffmanTree.getCounter().keySet()) {
                int count = huffmanTree.getCounter().get(ch);
                Writer.write(ch + " " + count + "\n");
            }
            Writer.close();
        }catch (Exception ex) {
            System.out.println("error!");
            System.exit(-1);
        }
    }
    private static void code_to_text() throws Exception{
        try {
            BufferedReader bf = new BufferedReader(new FileReader(new File("code.txt")));
            String Encode = bf.readLine();
            Map<Character, Integer> mp = new HashMap<>();
            String s;
            while ((s = bf.readLine()) != null) {
                String count = "" + s.charAt(2);
                mp.put(s.charAt(0), Integer.parseInt(count));
            }
            bf.close();
            String Decode = huffmanTree.Decode(Encode, mp);
            FileWriter Writer = new FileWriter("converted_text.txt");
            Writer.write(Decode);
            Writer.close();
            System.out.println("code to text : '" + Decode + "'");
        }catch (Exception ex) {
            System.out.println("error!");
            System.exit(-1);
        }
    }
    private static void check_to_correct() throws Exception {
        try {
            BufferedReader bf = new BufferedReader(new FileReader(new File("text.txt")));
            String Text = "";
            String s;
            while ((s = bf.readLine()) != null) {
                Text += s;
            }
            bf.close();
            bf = new BufferedReader(new FileReader(new File("converted_text.txt")));
            String converted_Text = "";
            while ((s = bf.readLine()) != null) {
                converted_Text += s;
            }
            bf.close();
            int number_of_dif = 0;
            for (int i = 0; i < Text.length(); i++) {
                if (i > converted_Text.length()) {
                    number_of_dif += Text.length() - converted_Text.length();
                    break;
                }
                if (Text.charAt(i) != converted_Text.charAt(i))
                        ++number_of_dif;
            }
            System.out.println("Number of unequal characters between text and converted text is : " + number_of_dif);
        }catch (Exception ex) {
            System.out.println("error!");
            System.exit(-1);
        }
    }
}
