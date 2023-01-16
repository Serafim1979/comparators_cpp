#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
////////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<Document> FindTopDocuments(const std::string& raw_query) const 
{
    const std::set<std::string> query_words = ParseQuery(raw_query);
    auto matched_documents = FindAllDocuments(query_words);

    sort(matched_documents.begin(), matched_documents.end(),
         [](const Document& lhs, const Document& rhs) 
         {  // Это лямбда-функция
             return lhs.relevance > rhs.relevance;
         });

    if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) 
    {
        matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
    }
    return matched_documents;
} 
////////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<int> ReadNumbers() 
{
    int count;
    std::cin >> count;

    std::vector<int> numbers;
    for (int i = 0; i < count; ++i) 
    {
        int number;
        std::cin >> number;
        numbers.push_back(number);
    }

    return numbers;
}

void PrintNumbers(const std::vector<int>& numbers) 
{
    for (auto number : numbers) 
    {
        std::cout << number << " "s;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    std::vector<int> numbers = ReadNumbers();

    sort(numbers.begin(), numbers.end(), [](int n1, int n2) 
    {
        /*
           Напишите тело лямбда-функции самостоятельно.
           Сначала должны располагаться чётные числа в порядке возрастания,
           а следом за ними — нечётные числа в порядке убывания
        */
        bool is_even1 = (n1 & 1) == 0;
        bool is_even2 = (n2 & 1) == 0;
        if(is_even1 && is_even2)
        {
            return n1 < n2;
        }
        if (is_even1) 
        {  
            return true;  
        }
        if(is_even2)
        {  
           return false; 
        }

        return n1 > n2; 
    });

    PrintNumbers(numbers);

///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // считайте входные данные и сформируйте вывод программы
    int n;
    std::cin >> n;

    std::vector<std::string> str;

    for(int i = 0; i < n; ++i)
    {
        std::string tmp;
        std::cin >> tmp;
        str.push_back(tmp);
    }

    std::sort(str.begin(), str.end(), [](const std::string& lhs, const std::string& rhs)
    {
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), [](const char l, const char r){return std::tolower(l) < std::tolower(r);});
    });
    
    for(int i = 0; i < n; ++i)
    {
        std::cout << str[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}