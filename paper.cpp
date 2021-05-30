#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>

#include "build_graph.hpp"
#include "G_prefix_sort.hpp"
#include "G_ds.hpp"

int main(void)
{
    std::vector<Node> NodeList;
    std::vector<char> seq {'#', 'G', 'A', 'C', 'G', 'T', 'A', 'C', 'C', 'T', 'G', '$'};
    std::vector<std::pair<int, char>> insert;// {std::make_pair(1, 'A'), std::make_pair(3, 'C')} ;
    std::vector<std::pair<int, int>> del {std::make_pair(3, 5), std::make_pair(6, 8), std::make_pair(6, 10)} ;
    std::vector<std::pair<int, char>> substitution {std::make_pair(3, 'T')} ;
    //std::pair del {(3, 5), (6, 8), (6, 10)};

    build_graph::linear_ref(seq, NodeList);
    build_graph::add_SNP(NodeList, insert, del, substitution);

    for(auto& node : NodeList)
        for(auto& TO : node.to)
            std::cout << "id: " << node.id << " , to: " << TO << std::endl;
    
    //G_prefix_sort::show(NodeList);
//    for(auto& node : NodeList)
//        for(auto& inc : node.income)
//            std::cout << "id: " << node.id << " , inc: " << inc << std::endl;
    
    std::vector<Prefix> PrefixList;
    G_prefix_sort::init_split(NodeList);

    for(auto& node : NodeList)
    {
        std::cout << "id: " << node.id << " , label: " << node.label;
        for(auto& to : node.to)
            std::cout << " , to: " << to << " ";
        std::cout << std::endl;
    }
    //G_prefix_sort::init_prefix(NodeList, PrefixList);
    std::cout << "test: ";
    //for(auto& fuck6 : NodeList[6].to)
    //    std::cout << fuck6 << " ";

    std::cout << "show: \n";
    G_prefix_sort::show(NodeList);
    //for(auto& pre : PrefixList)
    //    std::cout << "from: " << pre.from << " , id: " << pre.id << " , rank: " << pre.rank << std::endl;
}
