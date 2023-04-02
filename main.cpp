#include <fstream>
#include <iostream>
#include <string>
#include <vector>

//#include <random>
//#include <chrono>

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Wrong number of arguments. Must be: "
                     "<program name> <input_file.dat> <output_file.dat>";
    }

    try {
        std::ifstream inputFile(argv[1], std::ios::in | std::ios::binary);

        // Get the file size
        inputFile.seekg(0, std::ios::end);
        std::streamsize size = inputFile.tellg();
        inputFile.seekg(0, std::ios::beg);

        std::vector<char> buffer(size);

        // Reading data from a file
        if (inputFile.is_open()) {
            inputFile.read(buffer.data(), size);
            inputFile.close();
        } else {
            std::cerr << "Failed to open file for reading data." << std::endl;
            return -1;
        }

        std::ofstream outputFile(argv[2], std::ios::out | std::ios::binary);
        if (outputFile.is_open()) {
            for (auto it = buffer.rbegin(); it != buffer.rend(); ++it) {
                outputFile.write(&(*it), sizeof(std::vector<char>::value_type));
            }
        } else {
            std::cerr << "Failed to open file for writing data." << std::endl;
            return -1;
        }



//        std::fstream outputFile(argv[1], std::ios::out | std::ios::binary);
//
//        std::mt19937 generator(std::chrono::steady_clock::now().time_since_epoch().count()); //generator random values
//        std::uniform_int_distribution<> range(0, 255);
//
//        std::ofstream testFile("D:\\Projects\\Clion\\ReverseDatFile\\data\\test.txt", std::ios::out);
//
//        for (int i = 0; i < 10'000'000; ++i) {
//            char c = range(generator);
//            outputFile.write(&c, sizeof(char));
//            testFile << static_cast<int>(c) << std::endl;
//        }
//        outputFile.close();
//        testFile.close();



//        std::ifstream inputFile(argv[2], std::ios::in | std::ios::binary);
//
//        // Get the file size
//        inputFile.seekg(0, std::ios::end);
//        std::streamsize size = inputFile.tellg();
//        inputFile.seekg(0, std::ios::beg);
//
//        std::vector<char> buffer(size);
//
//        // Reading data from a file
//        if (inputFile.is_open()) {
//            inputFile.read(buffer.data(), size);
//            inputFile.close();
//        } else {
//            std::cerr << "Failed to open file for reading data." << std::endl;
//        }
//        std::ofstream testFileReverse("D:\\Projects\\Clion\\ReverseDatFile\\data\\testFileReverse.txt", std::ios::out);
//        for (auto item : buffer) {
//            testFileReverse << static_cast<int>(item) << std::endl;
//        }

    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}
