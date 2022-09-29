#include "gmock/gmock.h"
#include "Soundex.h"

using namespace testing;

class SoundexEncoding: public ::testing::Test {
   public:
   Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
   ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
   ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
   ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
   ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, ReplacesMutlipleConsonantsWithDigits) {
   ASSERT_THAT(soundex.encode("Afdg"), Eq("A132"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
   ASSERT_THAT(soundex.encode("Dcdlb"), Eq("D234"));
}