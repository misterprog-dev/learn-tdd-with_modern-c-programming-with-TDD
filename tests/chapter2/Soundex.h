#ifndef Soundex_h
#define Soundex_h
#include <string>

class Soundex {
   static const size_t MaxCodeLength{4};

   public:
   std::string encode(const std::string& word) const {
      return zeroPad(head(word) + encodedDigits(word));
   }

   private:
   std::string head(const std::string& word) const {
      return word.substr(0, 1);
   }

   private:
   std::string encodedDigits(const std::string& word) const {
      if (word.length() > 1) return encodedDigit();
      return "";
   }

   private:
   std::string encodedDigit() const {
      return "1";
   }

   private:
   std::string zeroPad(const std::string& word) const {
      return word + std::string(zerosMissing(word), '0');
   }

   private:
   int zerosMissing(const std::string& word) const {
      return MaxCodeLength - word.length();
   }
};
#endif