#ifndef Soundex_h
#define Soundex_h
#include <string>
#include <unordered_map>

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
      if (word.length() > 1) return encodedDigit(word[1]);
      return "";
   }

   private:
   std::string encodedDigit(char letter) const {
      const std::unordered_map<char,std::string> encodings {
         {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"}, {'l', "4"},
         {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
         {'s', "2"}, {'x', "2"}, {'z', "2"}, {'d', "3"}, {'t', "3"},
         {'m', "5"}, {'n', "5"}, {'r', "6"}
      };
      auto it = encodings.find(letter);
      return it == encodings.end() ? "" : it->second;
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