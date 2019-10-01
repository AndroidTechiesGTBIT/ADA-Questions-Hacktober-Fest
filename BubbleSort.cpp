#include <ctime>
// #include <iomanip>
#include <iostream>
using namespace std;

void bubblesort(int* a, unsigned int size) {
  bool change = true;
  for (int j = 0; change; j++) {
    change = false;
    for (unsigned int i = 0; i < size - 1 - j; i++) {
      if (a[i] > a[i + 1]) {
        swap(a[i], a[i + 1]);
        change = true;
      }
    }
  }
}

int main() {
  cout << "Enter the size of array\n";
  unsigned int size;
  cin >> size;
  int arr[size];
  cout << "Enter elements: ";
  for (unsigned int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  clock_t start = clock();
  bubblesort(arr, size);
  clock_t finish = clock();
  long double duration = (finish - start) / static_cast<long double>(CLOCKS_PER_SEC);

  cout << "Sorted array:";
  for (auto i : arr) {
    cout << ' ' << i;
  }
  cout << '\n';
  cout << "Time taken = " /* << setprecision(9) */ << duration << '\n';
}
