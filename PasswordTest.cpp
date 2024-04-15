/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)

};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, double_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, space_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, number_as_string)
{
    Password my_password;
    int actual = my_password.count_leading_characters("1111");
    ASSERT_EQ(4, actual); 
}

TEST(PasswordTest, allUppercase) {
    Password my_password;
    bool actual = my_password.has_mixed_case("ZZ");
    ASSERT_FALSE(actual);
}

TEST(PasswordTest, mixCase) {
    Password my_password;
    bool actual = my_password.has_mixed_case("Zz");
    ASSERT_TRUE(actual);
}

TEST(PasswordTest, allLowerCase) {
    Password my_password;
    bool actual = my_password.has_mixed_case("cz");
    ASSERT_FALSE(actual);
}



