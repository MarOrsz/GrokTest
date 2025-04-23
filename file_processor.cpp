#include "file_processor.h"
  #include <iostream>

  FileProcessor::FileProcessor(const std::string& filename) : file(filename) {
      if (!file.is_open()) {
          std::cerr << "Error: Could not open file " << filename << "\n";
      }
  }

  FileProcessor::~FileProcessor() {
      if (file.is_open()) {
          file.close();
      }
  }

  bool FileProcessor::readNumbers(int max_size) {
      if (!file.is_open()) return false;
      numbers = std::make_unique<int[]>(max_size);
      size = 0;
      int num;
      while (size < max_size && file >> num) {
          numbers[size++] = num;
      }
      return true;
  }

  void FileProcessor::transferNumbers(FileProcessor &other)
  {
    other.numbers = std::move(numbers);
    other.size = size;

    numbers = nullptr;
    size = 0;

  }

  FileProcessor::FileProcessor(FileProcessor &copy)
  {
    copy.numbers = numbers;

    
  }
