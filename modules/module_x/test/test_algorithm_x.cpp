#include "algorithm_x.hpp"
#include <gtest/gtest.h>

class AlgorithmXTest : public ::testing::Test {
protected:
  void SetUp() override {
    Catalan::Configuration config;
    config.method = 0;
    algorithm_ = std::make_unique<Catalan>(config);
  }
    std::unique_ptr<Catalan> algorithm_;
};

TEST_F(AlgorithmXTest, BasicProcessing) {
    int input = 5;
    auto result = algorithm_->process(input);
    
    EXPECT_EQ(result.size(), input+1);
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 2);
    EXPECT_EQ(result[3], 5);
    EXPECT_EQ(result[4], 14);
    EXPECT_EQ(result[5], 42);
}

TEST_F(AlgorithmXTest, WrongConfig) {
    Catalan::Configuration new_config;
    new_config.method = 1;
    
    algorithm_->updateConfiguration(new_config);
    
    // Test with new configuration
    int input = 5;
    auto result = algorithm_->process(input);
    
    EXPECT_EQ(result.size(), input+1);
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 1);
    EXPECT_EQ(result[2], 2);
    EXPECT_EQ(result[3], 5);
    EXPECT_EQ(result[4], 14);
    EXPECT_EQ(result[5], 42);
}

int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}