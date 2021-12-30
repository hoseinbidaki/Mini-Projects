import java.util.ArrayList;

public class ModeA implements PasswordGenerator
{
    private int pos = 0;
    private ArrayList<String>testcase = new ArrayList<>();

    public ModeA(ArrayList<String>Arr)
    {
        testcase = Arr;
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
