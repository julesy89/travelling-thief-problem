#include <iostream>
#include "problems/ttp_so.h"
#include "gtest/gtest.h"
#include <memory>
#include <vector>
#include "examples/test_examples.h"



using namespace TTP;



TEST(TTPSO, Evaluate1) {

    MapPtr m = exampleMap();
    vector<pair<ItemPtr, int>> items = exampleItemsLarge();

    SingleObjectiveTravellingThiefProblem ttpso(m, 3);
    ttpso.setRentingRate(1);
    ttpso.addItems(items);


    std::vector<int> v = {0,2,1,3};
    Tour t(v);

    Knapsack k = ttpso.convertKnapsack(std::vector<int> {0,1,0,1,0,0});


    double targetValue = ttpso.evaluate(t, k);


    EXPECT_NEAR(-73.14, targetValue, 0.01);

}



TEST(TTPSO, Evaluate2) {

    MapPtr m = exampleMap();
    vector<pair<ItemPtr, int>> items = exampleItemsLarge();

    SingleObjectiveTravellingThiefProblem ttpso(m, 3);
    ttpso.setRentingRate(1);
    ttpso.addItems(items);



    std::vector<int> v = {0,1,3,2};
    Tour t(v);

    Knapsack k = ttpso.convertKnapsack(std::vector<int> {0,1,1,0,0,0});


    double targetValue = ttpso.evaluate(t, k);


    EXPECT_NEAR(50, targetValue, 0.01);

}
