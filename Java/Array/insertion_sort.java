public class insertion_sort {
  public static void main(String args[]) {
    int arr[] = {13,46,24,52,20,9};
    int n = arr.length;
     System.out.println("Before insertion sort:");
    for (int i = 0; i < n; i++) {
      System.out.print(arr[i] + " ");
    }
    System.out.println();
    //insertion sort
    for (int i = 1; i < n; i++) {
      int current = arr[i];
      int j = i - 1;
      while (j >= 0 && arr[j] > current) {
        //swap
        arr[j + 1] = arr[j];
        j--;
      }
      arr[j + 1] = current;
    }

    System.out.println("After insertion sort:");
    for (int i = 0; i < n; i++) {
      System.out.print(arr[i] + " ");
    }
    System.out.println();

  }

}
