#include "file_processor.h"
  #include <iostream>
  #include <chrono>
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

      auto dur = std::chrono::duration_cast< std::chrono::nanoseconds>(end - start);
      
      std::cout <<"No of nanoseconds while reading from file:"<< dur.count()<<std::endl;

      FileProcessor fp2("input.txt");

        start = std::chrono::system_clock::now();
      fp2.transferNumbers(fp1);
       end = std::chrono::system_clock::now();

        dur = std::chrono::duration_cast< std::chrono::nanoseconds>(end - start);
      
      std::cout <<"No of nanoseconds while transferring data by move:"<< dur.count()<<std::endl;

      return 0;
  }