import java.util.ArrayList;

public class UniqueDigits {
    static int uniqueDigitCount(int n) {
        ArrayList<Integer> ar = new ArrayList<>();
        int temp = n;
        int count = 1;
        do {
            ar.add(temp % 10);
            temp /= 10;
        }
        while (temp > 0);
        Integer[] arr = new Integer[ar.size()];
        arr = ar.toArray(arr);
        if (arr.length > 0) {
            for (int i = 0; i < arr.length - 1; i++) {
                if (arr[i] != arr[i + 1]) {

                    count++;
                }
            }
            return count;
        } else {
            return 0;
        }
    }

    public static void main(String[] args) {
        System.out.println(uniqueDigitCount(1091));
    }
}
