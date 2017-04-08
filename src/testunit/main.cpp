#include "../nn/network.h"
#include "gtest/gtest.h"

namespace {

// The fixture for testing class Foo.
class LogicPortsTest : public ::testing::Test
{
protected:
	LogicPortsTest()
	{
	// You can do set-up work for each test here.
	}

	virtual ~LogicPortsTest()
	{
	// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	virtual void SetUp()
	{
		// Setup "And Gate"
		andGate.neurons.resize(4);
		andGate.neurons.at(3).inputs.push_back(synapse(0, 8));
		andGate.neurons.at(3).inputs.push_back(synapse(1, 8));
		andGate.neurons.at(3).inputs.push_back(synapse(2, -12));
		andGate.inputNeurons = 3;
		andGate.outputNeurons = 1;
		andGate.neurons.at(2).output = 1;
		andGate.sorttopology();

		// Setup "Or Gate"
		orGate.neurons.resize(4);
		orGate.neurons.at(3).inputs.push_back(synapse(0, 12));
		orGate.neurons.at(3).inputs.push_back(synapse(1, 12));
		orGate.neurons.at(3).inputs.push_back(synapse(2, -6));
		orGate.inputNeurons = 3;
		orGate.outputNeurons = 1;
		orGate.neurons.at(2).output = 1;
		orGate.sorttopology();
	}

	virtual void TearDown()
	{
	// Code here will be called immediately after each test (right
	// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case for Foo.
	network andGate;
	network orGate;
};

// Tests and gate for 0x0=0.
TEST_F(LogicPortsTest, And_0_0)
{
	andGate.neurons.at(0).output = 0;
	andGate.neurons.at(1).output = 0;
	andGate.evaluate();
	EXPECT_LE(andGate.neurons.at(3).output, 0.2);
}

// Tests and gate for 0x1=0.
TEST_F(LogicPortsTest, And_0_1)
{
	andGate.neurons.at(0).output = 0;
	andGate.neurons.at(1).output = 1;
	andGate.evaluate();
	EXPECT_LE(andGate.neurons.at(3).output, 0.2);
}

// Tests and gate for 0x1=0.
TEST_F(LogicPortsTest, And_1_0)
{
	andGate.neurons.at(0).output = 1;
	andGate.neurons.at(1).output = 0;
	andGate.evaluate();
	EXPECT_LE(andGate.neurons.at(3).output, 0.2);
}

// Tests and gate for 1x1=1.
TEST_F(LogicPortsTest, And_1_1)
{
	andGate.neurons.at(0).output = 1;
	andGate.neurons.at(1).output = 1;
	andGate.evaluate();
	EXPECT_GE(andGate.neurons.at(3).output, 0.8);
}

// Tests or gate for 0+0=0.
TEST_F(LogicPortsTest, Or_0_0)
{
	orGate.neurons.at(0).output = 0;
	orGate.neurons.at(1).output = 0;
	orGate.evaluate();
	EXPECT_LE(orGate.neurons.at(3).output, 0.2);
}

// Tests or gate for 0+1=1.
TEST_F(LogicPortsTest, Or_0_1)
{
	orGate.neurons.at(0).output = 0;
	orGate.neurons.at(1).output = 1;
	orGate.evaluate();
	EXPECT_GE(orGate.neurons.at(3).output, 0.8);
}

// Tests or gate for 1+0=1.
TEST_F(LogicPortsTest, Or_1_0)
{
	orGate.neurons.at(0).output = 1;
	orGate.neurons.at(1).output = 0;
	orGate.evaluate();
	EXPECT_GE(orGate.neurons.at(3).output, 0.8);
}

// Tests or gate for 1+1=1.
TEST_F(LogicPortsTest, Or_1_1)
{
	orGate.neurons.at(0).output = 1;
	orGate.neurons.at(1).output = 1;
	orGate.evaluate();
	EXPECT_GE(orGate.neurons.at(3).output, 0.8);
}
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
