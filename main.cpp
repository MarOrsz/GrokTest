#include "file_processor.h"
  #include <iostream>
  #include <chrono>

  int main() {
      FileProcessor fp("input.txt");
      if (fp.readNumbers(100)) {
          for (int i = 0; i < fp.getSize(); ++i) {
              std::cout << fp.getNumbers()[i] << " ";
          }
          std::cout << "\n";
      } else {
          std::cerr << "Failed to read numbers\n";
      }



      FileProcessor fp1("input.txt");

      auto start = std::chrono::system_clock::now();
      fp1.readNumbers(100);
      auto end = std::chrono::system_clock::now();

      auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end -start);

      std::cout<< duration.count() << std::endl;

      FileProcessor fp2("input.txt");

      fp2.transferNumbers(fp1);

      auto start2 = std::chrono::system_clock::now();
      fp1.transferNumbers(fp1);
      auto end2 = std::chrono::system_clock::now();

      auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 -start2);

      std::cout<< duration2.count() << std::endl;

      return 0;
  }