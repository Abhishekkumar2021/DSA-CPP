#include <bits/stdc++.h>
using namespace std;

char changeCase(char ch)
{
    if (ch >= 65 && ch <= 90)
    {
        ch = ch + 32;
        return ch;
    }
    else
    {
        ch = ch - 32;
        return ch;
    }
}
int similarityPercentage(string word, string possible)
{
    int count = 0;
    for (int i = 0; i < word.length(); i++)
    {
        int flag = 0;
        char toSearch = word[i];
        for (int j = 0; j < possible.length(); j++)
        {
            if (possible[j] == toSearch || possible[j] == changeCase(toSearch))
                flag = 1;
        }
        if (flag == 1)
        {
            count++;
        }
    }
    int sum = word.length() + possible.length();
    if (sum > 0)
        return count * 200 / sum;
    else
        return 0;
}
bool isSimilar(string word, string possible)
{
    if (possible.length() != word.length())
        return false;
    for (int i = 0; i < word.length(); i++)
    {
        int flag = 0;
        char toSearch = word[i];
        for (int j = 0; j < possible.length(); j++)
        {
            if (possible[j] == toSearch)
                flag = 1;
        }
        if (flag == 1)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int ASCIISum(string word)
{
    int ASCCISumOfWord = 0;
    for (int i = 0; i < word.length(); i++)
    {
        ASCCISumOfWord += word[i];
    }
    return ASCCISumOfWord;
}
set<string> possibleCorrection(string word, set<string> correct)
{
    set<string> possibleCorrection;
    // int wordSum = ASCIISum(word);
    for (auto element : correct)
    {
        if (similarityPercentage(word, element) >= 80)
        {
            if (word != element)
                possibleCorrection.insert(element);
        }
    }
    return possibleCorrection;
}
map<string, int> possibleCorrection2(string word, set<string> correct)
{
    map<string, int> possibleCorrection;
    // int wordSum = ASCIISum(word);
    for (auto element : correct)
    {
        int similarity = similarityPercentage(word, element);
        if (similarity >= 80)
        {
            if (word != element)
                possibleCorrection[element] = similarity;
        }
    }
    return possibleCorrection;
}

int main()
{
    ifstream inputFile("input.txt");
    ifstream correctWordCollection("correct.txt");
    set<string> correct;
    ofstream outputFile("output.txt");
    while (correctWordCollection)
    {
        string correctWord;
        correctWordCollection >> correctWord;
        int n = correctWord.size();
        if (correctWord[n - 1] == '.' || correctWord[n - 1] == '?' || correctWord[n - 1] == ',')
            correctWord = correctWord.substr(0, n - 1);
        correct.insert(correctWord);
    }
    while (inputFile)
    {
        string word;
        inputFile >> word;
        // map<string,int> possibleCorrctWords = possibleCorrection(word,correct);
        set<string> possibleCorrctWords = possibleCorrection(word, correct);
        int count = 1;
        // if(possibleCorrctWords.size() > 0){
        //     outputFile << word << "( ";
        //     for(auto correctWord: possibleCorrctWords){
        //         if(possibleCorrctWords.size()==count)
        //           outputFile<<correctWord.first<<" ||similarity = "<<correctWord.second<<"%|| ";
        //         else
        //           outputFile<<correctWord.first<<"||similarity = "<<correctWord.second<<"%||, ";
        //         count++;
        //     }
        //     outputFile<<") ";
        // }
        if (possibleCorrctWords.size() > 0)
        {
            outputFile << word << "( ";
            for (auto correctWord : possibleCorrctWords)
            {
                if (possibleCorrctWords.size() == count)
                    outputFile << correctWord << " ";
                else
                    outputFile << correctWord << ", ";
                count++;
            }
            outputFile << ") ";
        }
        else
        {
            outputFile << word << " ";
        }
    }
    inputFile.close();
    correctWordCollection.close();
    outputFile.close();
    return 0;
}