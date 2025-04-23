#ifndef FILE_PROCESSOR_H
  #define FILE_PROCESSOR_H

  #include <fstream>
  #include <memory>
  #include <string>


class FileProcessor;
  class FileProcessor {
  public:
      explicit FileProcessor(const std::string& filename);
      ~FileProcessor();
      bool readNumbers(int max_size);
      const int* getNumbers() const { return numbers.get(); }
      int getSize() const { return size; }

      void transferNumbers(FileProcessor& other);

      FileProcessor(FileProcessor& copy);


  private:
      std::ifstream file;
      std::unique_ptr<int[]> numbers;
      int size = 0;
  };



  #endif