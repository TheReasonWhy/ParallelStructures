#include <QtTest>
#include<graph_factory.hpp>

// add necessary includes here

class graph_test : public QObject
{
    Q_OBJECT

public:
    graph_test();
    ~graph_test();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1_data();
    void test_case1();

};

graph_test::graph_test()
{

}

graph_test::~graph_test()
{

}

void graph_test::initTestCase()
{

}

void graph_test::cleanupTestCase()
{

}

void graph_test::test_case1_data()
{
    qDebug()<<"... test_case1_data ..."<<endl;
}

void graph_test::test_case1()
{
qDebug()<<"... test_case1 ..."<<endl;
size_t const node_number = 12;
size_t const max_num_of_connections = 4;
Graph_factory<size_t, node_number, max_num_of_connections> factory;
/*

std::unique_ptr<Graph_factory<size_t, node_number, max_num_of_connections>::graph> G = factory.create_graph(10);
G.get()->output();
G.get()->Dijkstra(4);
//size_t control_val=G.get()->DFS(4);
QCOMPARE(G.get()->DFS(4),node_number);
//QCOMPARE(G.get()->BFS(0,5),true);
*/


std::unique_ptr<Graph_factory<size_t, node_number, max_num_of_connections>::graph> G2 =
    factory.create_graph_from_file("graph_data_weighted.txt");
//
G2.get()->output();
G2.get()->Dijkstra(4);
size_t control_val=G2.get()->DFS(4);
QCOMPARE(control_val,node_number);
G2->output_all("graph_data_weighted_output.txt");
//QCOMPARE(G2.get()->BFS_depth_counter(4,1),true);

/*
std::vector<Graph_initializer_connections> initializer = generate_graph_initializers_from_file("graph_data.txt");
size_t const node_number2 = 12;
size_t const max_num_of_connections2 = 4;
Graph<node_number2,max_num_of_connections2> m_graph2(initializer);
m_graph2.output();
m_graph2.Dijkstra(4);
size_t control_val2=m_graph2.DFS(4);
QCOMPARE(control_val2,node_number2);
QCOMPARE(m_graph2.BFS(0,5),true);
*/


qDebug()<<"... test_case1_end ..."<<endl;
}

QTEST_APPLESS_MAIN(graph_test)

#include "tst_graph_test.moc"
