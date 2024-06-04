// code for a simple arithmetic expression a = b + c * d

#include <iostream>
#include <fstream>

void generate_code(const std::string& output_file) {
    std::ofstream outfile(output_file);

    if (!outfile.is_open()) {
        std::cerr << "Error: Unable to open output file!" << std::endl;
        return;
    }

    outfile << "#include <iostream>" << std::endl;
    outfile << "int main() {" << std::endl;
    outfile << "    int a, b, c, d;" << std::endl;
    outfile << "    // Input values for b, c, d" << std::endl;
    outfile << "    std::cout << \"Enter values for b, c, d: \";" << std::endl;
    outfile << "    std::cin >> b >> c >> d;" << std::endl;
    outfile << "    // Compute expression a = b + c * d" << std::endl;
    outfile << "    a = b + c * d;" << std::endl;
    outfile << "    // Output result" << std::endl;
    outfile << "    std::cout << \"Result: \" << a << std::endl;";
    outfile << "    return 0;" << std::endl;
    outfile << "}" << std::endl;

    outfile.close();

    std::cout << "Code generated successfully and saved to " << output_file << std::endl;
}

int main() {
    std::string output_file = "generated_code.cpp";
    generate_code(output_file);
    return 0;
}
