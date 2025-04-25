#include "file_processor.h"
  #include <iostream>
  #include <algorithm>
  #include <vector>

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
    numbers = std::move(other.numbers);
    size = other.size;

    other.numbers = nullptr;
    other.size = 0;
  }

  void FileProcessor::filterNumbers(int threshold)
  {
    if (size < 1)
        return;

    auto newEnd = std::remove_if(numbers.get(), numbers.get() + size, [threshold](int x){return x < threshold;});

    size = *newEnd - 1;
  }
