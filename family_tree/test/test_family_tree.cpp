/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_FamilyTreeTest_init = false;
#include "/home/matth-l/Documents/3A_UQAC_cybersecu/trimestre_2/algo/data-struct-compendium/family_tree/test/FamilyTreeTest.hpp"

static FamilyTreeTest suite_FamilyTreeTest;

static CxxTest::List Tests_FamilyTreeTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_FamilyTreeTest( "test/FamilyTreeTest.hpp", 11, "FamilyTreeTest", suite_FamilyTreeTest, Tests_FamilyTreeTest );

static class TestDescription_suite_FamilyTreeTest_testEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FamilyTreeTest_testEmpty() : CxxTest::RealTestDescription( Tests_FamilyTreeTest, suiteDescription_FamilyTreeTest, 14, "testEmpty" ) {}
 void runTest() { suite_FamilyTreeTest.testEmpty(); }
} testDescription_suite_FamilyTreeTest_testEmpty;

static class TestDescription_suite_FamilyTreeTest_testSimpleAdding : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FamilyTreeTest_testSimpleAdding() : CxxTest::RealTestDescription( Tests_FamilyTreeTest, suiteDescription_FamilyTreeTest, 28, "testSimpleAdding" ) {}
 void runTest() { suite_FamilyTreeTest.testSimpleAdding(); }
} testDescription_suite_FamilyTreeTest_testSimpleAdding;

static class TestDescription_suite_FamilyTreeTest_testAddingChildren : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FamilyTreeTest_testAddingChildren() : CxxTest::RealTestDescription( Tests_FamilyTreeTest, suiteDescription_FamilyTreeTest, 45, "testAddingChildren" ) {}
 void runTest() { suite_FamilyTreeTest.testAddingChildren(); }
} testDescription_suite_FamilyTreeTest_testAddingChildren;

static class TestDescription_suite_FamilyTreeTest_testAddingGrandchildren : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FamilyTreeTest_testAddingGrandchildren() : CxxTest::RealTestDescription( Tests_FamilyTreeTest, suiteDescription_FamilyTreeTest, 68, "testAddingGrandchildren" ) {}
 void runTest() { suite_FamilyTreeTest.testAddingGrandchildren(); }
} testDescription_suite_FamilyTreeTest_testAddingGrandchildren;

static class TestDescription_suite_FamilyTreeTest_testRelationships : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FamilyTreeTest_testRelationships() : CxxTest::RealTestDescription( Tests_FamilyTreeTest, suiteDescription_FamilyTreeTest, 91, "testRelationships" ) {}
 void runTest() { suite_FamilyTreeTest.testRelationships(); }
} testDescription_suite_FamilyTreeTest_testRelationships;

static class TestDescription_suite_FamilyTreeTest_testRemovingNodes : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FamilyTreeTest_testRemovingNodes() : CxxTest::RealTestDescription( Tests_FamilyTreeTest, suiteDescription_FamilyTreeTest, 121, "testRemovingNodes" ) {}
 void runTest() { suite_FamilyTreeTest.testRemovingNodes(); }
} testDescription_suite_FamilyTreeTest_testRemovingNodes;

static class TestDescription_suite_FamilyTreeTest_testHeight : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FamilyTreeTest_testHeight() : CxxTest::RealTestDescription( Tests_FamilyTreeTest, suiteDescription_FamilyTreeTest, 151, "testHeight" ) {}
 void runTest() { suite_FamilyTreeTest.testHeight(); }
} testDescription_suite_FamilyTreeTest_testHeight;

static class TestDescription_suite_FamilyTreeTest_testFilterByEyeColor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FamilyTreeTest_testFilterByEyeColor() : CxxTest::RealTestDescription( Tests_FamilyTreeTest, suiteDescription_FamilyTreeTest, 178, "testFilterByEyeColor" ) {}
 void runTest() { suite_FamilyTreeTest.testFilterByEyeColor(); }
} testDescription_suite_FamilyTreeTest_testFilterByEyeColor;

static class TestDescription_suite_FamilyTreeTest_testListDescendantPreOrder : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FamilyTreeTest_testListDescendantPreOrder() : CxxTest::RealTestDescription( Tests_FamilyTreeTest, suiteDescription_FamilyTreeTest, 202, "testListDescendantPreOrder" ) {}
 void runTest() { suite_FamilyTreeTest.testListDescendantPreOrder(); }
} testDescription_suite_FamilyTreeTest_testListDescendantPreOrder;

static class TestDescription_suite_FamilyTreeTest_testListDescendantPostOrder : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FamilyTreeTest_testListDescendantPostOrder() : CxxTest::RealTestDescription( Tests_FamilyTreeTest, suiteDescription_FamilyTreeTest, 232, "testListDescendantPostOrder" ) {}
 void runTest() { suite_FamilyTreeTest.testListDescendantPostOrder(); }
} testDescription_suite_FamilyTreeTest_testListDescendantPostOrder;

static class TestDescription_suite_FamilyTreeTest_testListAncestorByEyeColor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_FamilyTreeTest_testListAncestorByEyeColor() : CxxTest::RealTestDescription( Tests_FamilyTreeTest, suiteDescription_FamilyTreeTest, 262, "testListAncestorByEyeColor" ) {}
 void runTest() { suite_FamilyTreeTest.testListAncestorByEyeColor(); }
} testDescription_suite_FamilyTreeTest_testListAncestorByEyeColor;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
