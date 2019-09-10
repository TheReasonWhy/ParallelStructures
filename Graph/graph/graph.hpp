#ifndef GRAPH_HPP
#define GRAPH_HPP
#include<array>
#include<forward_list>
#include<vector>
#include<QDebug>
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<memory>
#include<list>
#include<unordered_set>

//inline static const size_t INF = 999999999;

template<typename Weight_type, size_t Node_num, size_t Connect_num>
class Graph
{
    static constexpr size_t get_infinity(){
        return std::numeric_limits<size_t>::max();
    }
    inline static const size_t INF = get_infinity();
    inline static const unsigned MAX_DEPTH_ALLOWED = 100;


struct Graph_node
{
struct distance_type{
    distance_type():
    m_edge(INF),
    m_distance(INF){}

    distance_type(size_t dist):
    m_edge(dist),
    m_distance(dist){}

    size_t m_edge;
    size_t m_distance;
};
    Graph_node():
        m_weight(0),
        m_checked(false),
        m_index(0){
            distance_type dist(INF);
            distances.fill(dist);
        }

    Graph_node(size_t const _index):
        m_weight(0),
        m_checked(false),
        m_index(_index)
    {
            distance_type dist(INF);
            distances.fill(dist);

    }
    void set_distance_to(size_t const Node, size_t const distance){
        if(Node<Node_num){
            if(Node != m_index){
                distances.at(Node).m_distance = distance;
            }
        }
    }
    void set_edge(size_t const Node, size_t const distance){
        if(Node<Node_num){
            if(Node != m_index){
                distance_type dist(distance);
                distances.at(Node)=dist;
            }
        }
    }
    void set_index(size_t const index_){
        m_index=index_;
        distance_type dist(0);
        distances.at(m_index)=dist;
    }
    void set_weight(Weight_type weight){
        m_weight=weight;
    }
    size_t get_index()const{
        return m_index;
    }
    void un_check(){
        m_checked = false;
    }
    size_t get_distance_to(size_t const index)const{
        return distances.at(index).m_distance;
    }
    std::array<distance_type,Node_num> &get_distances(){
        return distances;
    }
    size_t get_edge(size_t const index)const{
        return distances.at(index).m_edge;
    }
    void output()const{
        auto it = distances.begin();
        size_t iterator = 0;
        while(it!=distances.end()){
            if((*it).m_distance!=INF){
                qDebug()<<".from."<<m_index <<".to."<<iterator<<".edge."
                << (*it).m_edge <<".dist." << (*it).m_distance <<".weight"<< m_weight <<endl;
            }
            iterator++;
            it++;
        }
    }
    Weight_type m_weight;
    bool m_checked;
    size_t m_index;
    std::array<distance_type,Node_num> distances;
};

struct graph_statistics{
    graph_statistics(unsigned node_num_,
                unsigned edges_num_,
                size_t max_from_,
                size_t max_to_,
                unsigned max_step_num_):
    node_num(node_num_),
    edges_num(edges_num_),
    max_from(max_from_),
    max_to(max_to_),
    max_step_num(max_step_num_)
    {

    }
    unsigned node_num;
    unsigned edges_num;
    size_t max_from;
    size_t max_to;
    unsigned max_step_num;
};
public:
    Graph(){
        indexate();
    }
    ~Graph(){}
    std::unique_ptr<graph_statistics> get_statistics(){
        size_t max_from(0);
        size_t max_to(0);
        unsigned max_depth = get_max_step_num(max_from,max_to);

        std::unique_ptr<graph_statistics> res
        = std::make_unique<graph_statistics>(get_node_num(), get_edges_num(),max_from,max_to,max_depth);
        return res;
    }
    unsigned get_node_num(){
        return static_cast<unsigned>(Node_num);
    }
    unsigned get_edges_num(){
        size_t result(0);
        for (size_t i =0;i<m_nodes.size();i++){
            result+=get_neighbours_num(i);
        }
        if(result==0){return 0;}
        return result/2;
    }

    void output_all(std::string const &filename){
        std::ofstream ostr(filename);
        update_all_distances();
        graph_statistics stats = *(get_statistics().get());
        ostr<< ".node_num."<< stats.node_num << std::endl;
        ostr<< ".edges_num."<< stats.edges_num << std::endl;
        ostr<< ".msx_step_num."<< stats.max_step_num << ".from."<<stats.max_from<< ".to."<< stats.max_to<<std::endl;

        for (unsigned from =0;from<m_nodes.size();++from){
            for (unsigned to =0;to<m_nodes.size();++to)
            {
                ostr<< ".from."<< m_nodes.at(from).get_index() <<
                ".to."<< m_nodes.at(to).get_index()
                <<".edge."
                << m_nodes.at(from).get_edge(to)
                 <<".dist."
                << m_nodes.at(from).get_distance_to(to) << std::endl;
            }
        }
    }

    unsigned get_max_step_num(size_t &max_from,size_t &max_to){
        unsigned max_depth(0);
        for (size_t from =0;from<m_nodes.size();from++){
            for (size_t to =0;to<m_nodes.size();to++){
                unsigned bfs=BFS_depth_counter(from,to);
                qDebug()<< ".bfs."<< bfs<< ".from."<<from<< ".to."<<to<<endl;
                if(bfs>max_depth){
                    max_depth=bfs;
                    max_from = from;
                    max_to = to;
                }
            }
        }
        return max_depth+1;
    }
    void update_all_distances(){
        for (size_t to =0;to<m_nodes.size();to++){
            Dijkstra(to);
        }
    }
    void Dijkstra(size_t const To){
        reset_checks();
        std::forward_list<size_t> neighbours = get_neighbours(To);
        std::forward_list<size_t>::iterator It = neighbours.begin();
        check(To);
        while (It!=neighbours.end()) {
            size_t neighbour = *It;
            Dijkstra_recursive(neighbour, To);
            It++;
        }
        reset_checks();
    }

    size_t DFS(size_t const Index){
        reset_checks();
        size_t Node_number(0);
        DFS_recursive(Index, Node_number);
        return Node_number;
    }

    unsigned BFS_depth_counter(size_t const start_index, size_t const goal_index){
        qDebug()<< ".BFS_depth_counter."<< start_index<< "...."<<goal_index<<endl;
        if(start_index==goal_index){return 0;}
        reset_checks();
        std::forward_list<size_t> neighbours = get_neighbours(start_index);
        std::forward_list<size_t>::iterator It = neighbours.begin();
        std::list<size_t> branches;
        unsigned depth_counter(1);
        bool result(false);
        check(start_index);
        while (It!=neighbours.end()){
            if(*It==goal_index){
                result = true;
            }
            It++;
        }        
        while ((!result)&&(depth_counter<MAX_DEPTH_ALLOWED)) {
            It=neighbours.begin();
            while (It!=neighbours.end()){
                        qDebug()<< ".depth_counter."<< depth_counter<<endl;
                BFS_recursive_depths(start_index, *It, depth_counter-1,branches);
                while (!branches.empty()){
                    if(branches.back()==goal_index){
                        result=true;
                    }
                    branches.pop_back();
                }
                It++;
            }
            depth_counter++;
        }
        return depth_counter;
    }

    void output()const{
        for (unsigned i =0;i<m_nodes.size();++i){
            m_nodes.at(i).output();
        }
    }
    void output_distances_to(size_t const To)const{
        for (unsigned i =0;i<m_nodes.size();++i)
        {
            qDebug()<< ".index."<< m_nodes.at(i).get_index() <<".dist." << m_nodes.at(i).get_distance_to(To) << endl;
        }
    }


    void set_edge(size_t const First, size_t const Second, size_t const Distance){
        if((First<Node_num)&&(Second<Node_num)&&(First!=Second)){
            m_graph.at(First).push_front(Second);
            m_graph.at(Second).push_front(First);
            m_nodes.at(First).set_edge(Second,Distance);
            m_nodes.at(Second).set_edge(First,Distance);
        }
    }
    void set_weight(size_t node, Weight_type weight){
        m_nodes.at(node).set_weight(weight);
    }
    void indexate(){
        for (size_t i =0;i<m_nodes.size();i++) {
            m_nodes.at(i).set_index(i);
        }
    }
    private:
    std::forward_list<size_t> &get_neighbours(Graph_node const &node){
        return m_graph.at(node.index);
    }
    std::forward_list<size_t> &get_neighbours(size_t const &node_index){
        return m_graph.at(node_index);
    }
    void check(size_t index){
        m_nodes.at(index).m_checked=true;
    }
    void un_check(size_t index){
        m_nodes.at(index).m_checked=false;
    }
    bool is_checked(size_t index)const{
        return m_nodes.at(index).m_checked;
    }
    void reset_checks(){
        for (size_t i =0;i<m_nodes.size();++i) {
            m_nodes.at(i).un_check();
        }
    }

    bool try_set_distance(size_t const From, size_t const To, size_t accumulated_distance){
        if(m_nodes.at(From).get_distance_to(To)>accumulated_distance){
            m_nodes.at(From).set_distance_to(To,accumulated_distance);
            return true;
        }
        return false;
    }

/*   void Floyd(std::vector<size_t> &nodes){
        for (size_t i =0;i<m_nodes.size();++i) {
            std::array<distance_type,Node_num> dists_i = m_nodes.at(i).get_distances();
            std::forward_list<size_t> neighbours = get_neighbours(i);
            std::forward_list<size_t>::iterator It = neighbours.begin();
            while (It!=neighbours.end()) {
                std::array<distance_type,Node_num> dists_k = m_nodes.at(*It).get_distances();
                for (size_t k; k<dists.size(); k++) {
                    dists_k.at(k)=std::min(dists_k.at(k),dists_i.at(i)+);
                }
                It++
            }
        }
        reset_checks();
    }

    void Ford_Bellman(size_t From, size_t To, std::vector<size_t> &nodes){

        reset_checks();
    }
*/
    void BFS_recursive_depths(size_t const previous,
                    size_t const start_index,
                    size_t depth_counter,
                    std::list<size_t> &branches){
        //qDebug()<< ".BFS_recursive_depths."<<start_index<<" depth "<<depth_counter<< endl;
        std::forward_list<size_t> neighbours = get_neighbours(start_index);
        std::forward_list<size_t>::iterator It = neighbours.begin();
        qDebug()<< ".called."<< start_index<<depth_counter<<endl;
        if(depth_counter==0){
            if(is_checked(start_index)){
                return;
            }
            check(start_index);
            while (It!=neighbours.end()){
                if(*It!=start_index){
                    branches.push_back(*It);
                }
                It++;
            }
        }else {
            --depth_counter;
            while (It!=neighbours.end()){
                if(*It!=previous){
                    BFS_recursive_depths(start_index, *It, depth_counter,branches);
                }
                It++;
            }
        }
    }

    void Dijkstra_recursive(size_t const From, size_t const To){
        std::forward_list<size_t> neighbours = get_neighbours(From);
        std::forward_list<size_t>::iterator It = neighbours.begin();
        if(!is_checked(From)){
            while (It!=neighbours.end()) {
                size_t neighbour = *It;
                size_t accumulated_distance =
                    m_nodes.at(neighbour).get_distance_to(From)+m_nodes.at(From).get_distance_to(To);
                if(try_set_distance(neighbour, To, accumulated_distance)){
                    un_check(neighbour);
                    Dijkstra_recursive(neighbour, To);
                }
                It++;
            }
            check(From);
        }
    }


    void DFS_recursive(size_t const Index, size_t &Node_number){
        Node_number++;
        std::forward_list<size_t> neighbours = get_neighbours(Index);
        std::forward_list<size_t>::iterator It = neighbours.begin();
        check(Index);
        while (It!=neighbours.end()){
            size_t neighbour = *It;
            if(!is_checked(neighbour))
            {
                DFS_recursive(neighbour,Node_number);
            }
            It++;
        }
    }
    unsigned get_neighbours_num(size_t const Index){
        size_t counter(0);
        std::forward_list<size_t> neighbours = get_neighbours(Index);
        std::forward_list<size_t>::iterator It = neighbours.begin();
        while (It!=neighbours.end()){            
            It++;
            counter++;
        }
        //qDebug()<<Index<<"..has.."<<counter<<"..neighbours"<<endl;
        return counter;
    }
private:
    std::array<std::forward_list<size_t>, Node_num> m_graph;
    std::array<Graph_node, Node_num> m_nodes;
};

#endif // GRAPH_HPP
