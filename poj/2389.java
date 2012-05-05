import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  static byte[] ans;
  static byte[] multiply(byte[] s, byte t) {
    byte[] ans = new byte[s.length+1];
    byte carry = 0;
    for(int i = s.length-1; i >= 0; i--) {
      ans[i+1] = (byte)(s[i] * t + carry);
      if (ans[i+1] >= 10) {
        carry = (byte)(ans[i+1] / 10);
        ans[i+1] %= 10;
      } else {
        carry = 0;
      }
    }
    ans[0] = carry;
    return ans;
  }

  static void addAns(byte[] s, int idx) {
    byte carry = 0;
    for (int i = 0; i < s.length; i++) {
      ans[idx+i] += s[s.length-1-i] + carry;
      if (ans[idx+i] >= 10) {
        carry = (byte)(ans[idx+i] / 10);
        ans[idx+i] %= 10;
      } else {
        carry = 0;
      }
    }
    ans[idx + s.length] += carry;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    byte[] s = scanner.next().getBytes();
    byte[] t = scanner.next().getBytes();
    for (int i = 0; i < s.length; i++) s[i] -= '0';
    for (int i = 0; i < t.length; i++) t[i] -= '0';

    ans = new byte[s.length * t.length * 2];
    for (int i = 0; i < t.length; i++) {
      byte multiplier = t[t.length-1-i];
      byte[] submul = multiply(s, multiplier);
      addAns(submul, i);
    }

    int idx = ans.length-1;
    while (ans[idx] == 0) idx--;
    while (idx >= 0) {
      System.out.print(ans[idx]);
      idx--;
    }
    System.out.println();
  }
}

