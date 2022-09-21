## Modern c++ programming with TDD
> I learn TDD with book (https://pragprog.com/titles/lotdd/modern-c-programming-with-test-driven-development/) <br>
> To practise I decide to do a second folder from source code and follow all steps and I commit these by chapter
<hr>

## Launch Tests

```bash
cd tests/<chapter>
clang++ -lgtest main.cpp -o  ./main -std=c++14 && ./main
```
<hr>

## Examples used
### 1- First Example
> In this chapter, we will test-drive a Soundex class that can improve the search capability in an application. All details(https://fr.wikipedia.org/wiki/Soundex)