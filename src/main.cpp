#include "labyrinth.h"
#include "test.h"
#include <fstream>
#include <windows.h>
#include <locale>

int main() {

    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    std::ios_base::sync_with_stdio(false);
    std::ifstream ifs("labyrinth.txt");
    lab maze = labyrinth_from_file(ifs);
    ifs.close();

    print_labyrinth(maze);

    std::cout << std::endl;

    // c_stack_test(maze, pos(0,0));
    // std_stack_test(maze, pos(0,0));

    std::cout << "Собственная реализация : " << measure_c_stack(maze, pos(0,0)) << " мкс."<< std::endl;
    std::cout << "STL реализация : " << measure_std_stack(maze, pos(0,0)) << " мкс."<< std::endl;
    /* std::cout << "STL реализация : " << measure_std_stack_bin("maze.bin", 10000, 10000, pos(0, 0)) << " мкс." <<
            std::endl;*/

    return 0;
}
