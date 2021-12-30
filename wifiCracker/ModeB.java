import java.util.ArrayList;

public class ModeB implements PasswordGenerator
{
    private int pos = 0;
    private ArrayList<String> testcase = new ArrayList<>();
    private char [] ch = {'!','#','$','%','&','(',')','*','+','-','.','/', '0','1','2','3','4','5','6','7', '8','9',':',';','<','=','>','?','@'};

    public ModeB(ArrayList<String>Arr)
    {
        testcase = Arr;
        make();
    }

    private void make()
    {
        ArrayList<String> tmp = new ArrayList<>();
        for (int i=0;i<testcase.size();i++)
        {
            for (char c:ch)
            {
                String s = testcase.get(i) + c;
                String t = c + testcase.get(i);
                tmp.add(s);
                tmp.add(t);
            }
        }
        testcase = tmp;
    }
    @Override
    public boolean hasNextPassword() {
        if (pos != testcase.size())
            return true;
        else
            return false;
    }

    @Override
    public String nextPassword() {
        String prePass = testcase.get(pos);
        pos += 1;
        return prePass;
    }

    @Override
    public int getProgress() {
        return pos;
    }
}
