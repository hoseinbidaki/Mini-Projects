import java.util.ArrayList;

public class ModeC implements PasswordGenerator
{
    private int pos = 0;
    private ArrayList<String> testcase1,testcase2;
    private ArrayList<String>Merge = new ArrayList<>();
    private char [] ch = {'!','#','$','%','&','(',')','*','+','-','.','/', '0','1','2','3','4','5','6','7', '8','9',':',';','<','=','>','?','@'};

    public ModeC(ArrayList<String>Arr1,ArrayList<String>Arr2)
    {
        testcase1 = Arr1;
        testcase2 = Arr2;
        make();
    }

    private void make()
    {
        for (String A : testcase1)for (String B:testcase2)for (char C:ch)
        {
            Merge.add(A+B+C);
            Merge.add(C+B+A);
        }
        for (String A : testcase2)for (String B:testcase1)for (char C:ch)
        {
            Merge.add(A+B+C);
            Merge.add(C+B+A);
        }
    }
    @Override
    public boolean hasNextPassword() {
        if (pos != Merge.size())
            return true;
        else
            return false;
    }

    @Override
    public String nextPassword() {
        String prePass = Merge.get(pos);
        pos += 1;
        return prePass;
    }

    @Override
    public int getProgress() {
        return pos;
    }
}
