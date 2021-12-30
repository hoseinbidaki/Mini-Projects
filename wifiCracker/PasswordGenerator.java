public interface PasswordGenerator {
    public boolean hasNextPassword();
    public String nextPassword();
    public int getProgress();
}
