package com.company.interviews.sorting;

/**
 * Created by anamika on 22/8/18.
 */
public class CycleSort {
    public static void main(String args[]) {
        int arr[] = {1, 8, 3, 9, 10, 10, 2, 4 };
        cycleSort(arr, arr.length);
        printArray(arr);
    }

    private static void printArray(int arr[]) {
        for (int a: arr
                ) {
            System.out.print(a + " ");
        }
        System.out.println();
    }

    private static void cycleSort(int[] arr, int n) {
        int cycle_count;
        int write = 0;
        int pos, temp, i, item;
        for(cycle_count=0; cycle_count<=n-2; cycle_count++){
            pos = cycle_count;
            item = arr[cycle_count];
            for(i=cycle_count+1; i<n; i++) {
                if(item>arr[i])
                    pos++;
            }
            // already at correct place, skip this cycle then
            if(pos == cycle_count)
                continue;
            // duplicate item, increase position
            if(arr[pos] == item){
                pos++;
            }
            // swap
            if(pos!=cycle_count) {
                temp = item;
                write++;
                item = arr[pos];
                arr[pos] = temp;
            }

            while (pos!=cycle_count) {
                pos = cycle_count;
                for(i=cycle_count+1; i<n; i++) {
                    if(item>arr[i])
                        pos++;
                }
                if(arr[pos] == item){
                    pos++;
                }
                if(item!=arr[pos]) {
                    temp = item;
                    write++;
                    item = arr[pos];
                    arr[pos] = temp;
                }
            }
        }
        System.out.println(write);
    }
}
