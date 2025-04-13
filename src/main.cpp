#include "labyrinth.h"
#include "test.h"
#include <fstream>

int main() {
    std::ifstream ifs("labyrinth.txt");
    lab maze = labyrinth_from_file(ifs);
    ifs.close();

    print_labyrinth(maze);
    return 0;
}
