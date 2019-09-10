#ifndef GRAPH_FACTORY_HPP
#define GRAPH_FACTORY_HPP

#include<graph.hpp>

template<typename Weight_type, size_t Node_num, size_t Connect_num>
class Graph_factory{
struct Graph_initializer_connections
{
    Graph_initializer_connections(){}
    Graph_initializer_connections(size_t first,size_t second,size_t distance):First(first),Second(second),Distance(distance) {}
    void init(size_t first,size_t second,size_t distance){
        First=first;
        Second=second;
        Distance=distance;
    }
    size_t First;
    size_t Second;
    size_t Distance;
};
struct Graph_initializer_weights
{
    Graph_initializer_weights(){}
    Graph_initializer_weights(size_t node,Weight_type weight):Node(node),Weight(weight){}
    void init(size_t node,Weight_type weight){
        Node=node;
        Weight=weight;
    }
    size_t Node;
    Weight_type Weight;
};
public:
using graph = Graph<Weight_type, Node_num, Connect_num>;

    std::unique_ptr<graph> create_graph_from_file(std::string const filename){
        std::unique_ptr<graph> result = std::make_unique<graph>();
        std::vector<Graph_initializer_connections> connections;
        std::vector<Graph_initializer_weights> weights;
        generate_graph_initializers_from_file(filename,connections,weights);
        for(size_t i=0;i<connections.size();++i){
            result.get()->set_edge(connections.at(i).First,connections.at(i).Second,connections.at(i).Distance);
        }
        for(size_t i=0;i<weights.size();++i){
            result.get()->set_weight(weights.at(i).Node, weights.at(i).Weight);
        }
        return result;
    }
    std::unique_ptr<graph> create_graph(Weight_type weight_divisor){
        std::unique_ptr<graph> result = std::make_unique<graph>();
        std::vector<Graph_initializer_connections> connections;
        std::vector<Graph_initializer_weights> weights;
        generate_random_graph_initializers(connections,weights,weight_divisor);
        for(size_t i=0;i<connections.size();++i){
            result.get()->set_edge(connections.at(i).First,connections.at(i).Second,connections.at(i).Distance);
        }
        for(size_t i=0;i<weights.size();++i){
            result.get()->set_weight(weights.at(i).Node, weights.at(i).Weight);
        }
        return result;
    }

    void init(std::vector<Graph_initializer_connections> const &initializer){
        for(size_t i=0;i<initializer.size();++i){
            add_connection(initializer.at(i).First,initializer.at(i).Second,initializer.at(i).Distance);
        }
    }

    void init_random(size_t const node_number,size_t const max_num_of_connections){
        std::vector<Graph_initializer_connections> params = generate_random_graph_initializers(node_number,max_num_of_connections);
        init(params);
    }


void generate_graph_initializers_from_file(std::string const filename,
    std::vector<Graph_initializer_connections> &connections,
    std::vector<Graph_initializer_weights> &weights){

    std::vector<Graph_initializer_connections> result;
    std::ifstream file(filename);
    if (!file.good()) {
        qDebug()<<filename.data()<< "not found!"<< endl;
        throw std::exception();
    }

    while(!file.eof()){
        std::string control_letter;
        size_t node_in;
        size_t node_out;
        size_t distance;
        Weight_type weight;
        getline(file, control_letter, ' ');
        if(control_letter == "c"){
            qDebug()<<"c"<< control_letter.data()<< endl;
            file>>node_in;
            file>>node_out;
            file>>distance;
            Graph_initializer_connections node;
            node.init(node_in,node_out,distance);
            connections.push_back(node);
        }else if (control_letter == "w") {
            qDebug()<<"w"<< control_letter.data()<< endl;
            file>>node_in;
            file>>weight;
            Graph_initializer_weights node;
            node.init(node_in,weight);
            weights.push_back(node);
        }else{
            qDebug()<<"letter was "<< control_letter.data()<< endl;
        }
        getline(file, control_letter);
    }
}

void generate_random_graph_initializers(std::vector<Graph_initializer_connections> &connections,
                                        std::vector<Graph_initializer_weights> &weights,
                                        Weight_type weight_divisor){
    std::vector<Graph_initializer_connections> result;
    if(Node_num==1){
        connections.push_back(Graph_initializer_connections(0,0,0));
        weights.push_back(Graph_initializer_weights(0,0));
    }
    for(size_t i =0; i< Node_num;++i){
        size_t Node = i;
        size_t connect_num = static_cast<size_t>(static_cast<size_t>(rand())%(Connect_num));
        for(size_t j =0; j< connect_num;++j){
            size_t Neighbour = static_cast<size_t>(static_cast<size_t>(rand())%(Node_num-1));
            size_t Distance = static_cast<size_t>(static_cast<size_t>(rand())%(100));
            connections.push_back(Graph_initializer_connections(Node,Neighbour,Distance));
        }
    }
    for(size_t i =0; i< Node_num;++i){
        Weight_type weight = static_cast<Weight_type>(static_cast<Weight_type>(rand())%(weight_divisor));
        weights.push_back(Graph_initializer_weights(i, weight));
    }

}

};

#endif // GRAPH_FACTORY_HPP
