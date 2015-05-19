#include "model/map.h"
#include "model/tour.h"
#include "gtest/gtest.h"


TEST(MapTest, Initialize) {
    ttp::Map m(2);
    EXPECT_EQ(std::numeric_limits<double>::max(), m.get(0,1));
    EXPECT_EQ(std::numeric_limits<double>::max(), m.get(2,2));

}


TEST(MapTest, Set) {
    ttp::Map m(2);

    // set value in index -> no distance. it is 1 to 1.
    EXPECT_EQ(0, m.get(1,1));
    m.set(1,1,6);
    EXPECT_EQ(0, m.get(1,1));

    // set value in index
    m.set(1,0,6);
    EXPECT_EQ(6, m.get(1,0));

    // set value out of bounds
    EXPECT_EQ(std::numeric_limits<double>::max(), m.get(2,2));
    m.set(2,2,6);
    EXPECT_EQ(std::numeric_limits<double>::max(), m.get(2,2));

}

TEST(MapTest, Symetrical) {
    ttp::Map m(2);

    m.set(0,1,6);
    EXPECT_EQ(6, m.get(0,1));
    EXPECT_EQ(6, m.get(1,0));

}



