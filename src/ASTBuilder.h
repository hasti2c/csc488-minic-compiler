//
// Created by Fan Long on 2020/12/4.
//

#ifndef MINICC_ASTBUILDER_H
#define MINICC_ASTBUILDER_H

#include <string>

namespace minicc {
    class Program;
}

minicc::Program* buildAST(const std::string &InputFile);

#endif //MINICC_ASTBUILDER_H
