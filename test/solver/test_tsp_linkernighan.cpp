#include "solver/tsp_lin_kernighan.h"
#include "examples/test_examples.h"
#include "gtest/gtest.h"

#include "generator/generator.h"
using namespace ttp;

/*

TEST(TSPLinKernighanSolver, Bier127) {
    //TravellingSalesmanProblem tsp = ProblemFactory::createTSP("../test/generator/berlin4.tsp");

    TravellingSalesmanProblem tsp = ProblemFactory::createTSP("../data/tsplib/bier127.tsp");

    TSPLinKernighanSolver s;

    s.solve(tsp);

    //EXPECT_EQ(0, m.get(1,1));
}
*/


TEST(TSPLinKernighanSolver, Bier127_2) {
    TravellingSalesmanProblem tsp = ProblemFactory::createTSP("../data/tsplib/bier127.tsp");
    TSPLinKernighanSolver s;

    s.solve(tsp);

    ProblemFactory::createTSP("../data/tsplib/berlin52.tsp");

    Tour t = s.solve(tsp);
    cout << t<< endl;

    cout << tsp.evaluate(t);



    //EXPECT_EQ(0, m.get(1,1));
}
