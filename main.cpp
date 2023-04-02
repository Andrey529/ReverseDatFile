#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>

// Link to github https://github.com/Andrey529/ReverseDatFile

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Wrong number of arguments. Must be: "
                     "<program name> <input_file.dat> <output_file.dat>";
        return -1;
    }

    try {
        auto start = std::chrono::high_resolution_clock::now();

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

        auto finish = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start);
        std::cout << "Execution time = " << finish.count() << " nanosec = " << finish.count()/1000 << " microsec = "
                  << finish.count()/1000000 << " ms = " << finish.count()/1000000000 << " sec." << std::endl;
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
        return -1;
    }
    return 0;
}
