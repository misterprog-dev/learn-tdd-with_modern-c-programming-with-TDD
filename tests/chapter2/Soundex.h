#ifndef Soundex_h
#define Soundex_h
#include <string>
#include <unordered_map>

class Soundex {
   static const size_t MaxCodeLength{4};
   const std::string notADigit{"*"};

   public:
   std::string encode(const std::string& word) const {
      return zeroPad(upperFront(head(word)) + encodedDigits(tail(word)));
   }

   private:
   std::string zeroPad(const std::string& word) const {
      return word + std::string(zerosMissing(word), '0');
   }

   private:
   int zerosMissing(const std::string& word) const {
      return MaxCodeLength - word.length();
   }

   private:
   std::string upperFront(const std::string& word) const {
      return std::string(1, std::toupper(static_cast<unsigned char>(word.front())));
   }

   private:
   std::string head(const std::string& word) const {
      return word.substr(0, 1);
   }

   private:
   std::string encodedDigits(const std::string& word) const {
      std::string encoding;
      for(auto letter: word) {
         if (isComplete(encoding)) break;

         auto digit = encodedDigit(letter);
         if (digit != notADigit && digit!= lastDigit(encoding))
            encoding += encodedDigit(letter);
      }
      return encoding;
   }

   private:
   std::string tail(const std::string& word) const {
      return word.substr(1);
   }

   private:
   bool isComplete(const std::string& word) const {
      return word.length() == MaxCodeLength - 1;
   }

   public:
   std::string encodedDigit(char letter) const {
      const std::unordered_map<char,std::string> encodings {
         {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"}, {'l', "4"},
         {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
         {'s', "2"}, {'x', "2"}, {'z', "2"}, {'d', "3"}, {'t', "3"},
         {'m', "5"}, {'n', "5"}, {'r', "6"}
      };
      auto it = encodings.find(lower(letter));
      return it == encodings.end() ? notADigit : it->second;
   }

   private:
   char lower(const char letter) const {
      return std::tolower(static_cast<unsigned char>(letter));
   }

   private: 
   std::string lastDigit(const std::string& encoding) const {
      if (encoding.empty()) return notADigit;
      return std::string(1, encoding.back());
   }
};
#endif