#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <datatypes/dictionary.hpp>

using namespace ntt;

TEST(DictionaryTest, Test_ToString)
{
    Dictionary<String, String> dict;
    dict["key1"] = "value1";
    dict["key2"] = "value2";
    dict["key3"] = "value3";

    EXPECT_THAT(dict.ToString(),
                testing::Eq("{\n\tkey1: value1,\n\tkey2: value2,\n\tkey3: value3,\n}"));
}