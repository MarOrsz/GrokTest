#include "file_processor.h"
  #include <iostream>

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
      return 0;
  }