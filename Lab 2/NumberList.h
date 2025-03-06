#pragma once
class NumberList
{
    int numbers[10];
    float Math,English,History;
    int count;
    char NameStudent[30];

public:
    void Init();          // count will be 0
    bool Add(int x);      // adds X to the numbers list and increase the data member count.
    // if count is bigger or equal to 10, the function will return false
    void Sort();          // will sort the numbers vector
    void Print();         // will print the current vector
    void SetName(const char s[30]);
    const char* GetName();
    void SetMath(float x);
    float GetMath();
    void SetEnglish(float x);
    float GetEnglish();
    void SetHistory(float x);
    float GetHistory();
    float AverageGrade();


};