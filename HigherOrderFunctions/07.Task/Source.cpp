#include <iostream>
#include <cstring>

bool isLetter(char c)
{
    return 'A' <= c && c <= 'Z' || 'a' <= c && c <= 'z';
}

int getWordsCount(char* sentence)
{
    int wordsCount = 0;
    int sentenceLength = strlen(sentence);

    for (int i = 0; i < sentenceLength; i++)
    {
        if (isLetter(sentence[i]))
        {
            wordsCount++;
        }

        while (isLetter(sentence[i]) && i < sentenceLength)
        {
            i++;
        }
    }

    return wordsCount;
}

void extractWordsFromSentence(char* sentence, char** words)
{
    int wordIndex = 0, wordCurrentIndex = 0;
    int sentenceLength = strlen(sentence);
    char* temp = new char[sentenceLength + 1]{};

    while (*sentence != '\0' || wordCurrentIndex > 0)
    {
        if (isLetter(*sentence))
        {
            temp[wordCurrentIndex++] = *sentence;
        }
        else if (wordCurrentIndex > 0)
        {
            words[wordIndex] = new char[wordCurrentIndex + 1]{};

            for (int i = 0; i <= wordCurrentIndex; i++)
            {
                words[wordIndex][i] = temp[i];
            }

            wordIndex++;
            wordCurrentIndex = 0;

            delete[] temp;
            temp = new char[sentenceLength + 1]{};
        }

        if (*sentence != '\0')
        {
            sentence++;
        }
    }

    delete[] temp;
}

int findConsecutiveWordsCount(char** wordsInText, int wordsInTextCount, char** wordsInSentence, int wordsInSentenceCount)
{
    int maxConsecutiveWordsCount = 0;
    int consecutiveWordsCount = 0;

    for (int i = 0; i < wordsInSentenceCount; i++)
    {
        bool isInSentence = false;

        for (int j = 0; j < wordsInTextCount; j++)
        {
            if (strcmp(wordsInText[j], wordsInSentence[i]) == 0)
            {
                isInSentence = true;
                break;
            }
        }

        if (isInSentence)
        {
            consecutiveWordsCount++;
        }
        else
        {
            if (consecutiveWordsCount > maxConsecutiveWordsCount)
            {
                maxConsecutiveWordsCount = consecutiveWordsCount;
            }

            consecutiveWordsCount = 0;
        }
    }

    if (consecutiveWordsCount > maxConsecutiveWordsCount)
    {
        maxConsecutiveWordsCount = consecutiveWordsCount;
    }

    return maxConsecutiveWordsCount;
}

double findSameWordsPercent(char** wordsInText, int wordsInTextCount, char** wordsInSentence, int wordsInSentenceCount)
{
    int wordsMet = 0;

    for (int i = 0; i < wordsInSentenceCount; i++)
    {
        for (int j = 0; j < wordsInTextCount; j++)
        {
            if (strcmp(wordsInText[j], wordsInSentence[i]) == 0)
            {
                wordsMet++;
                break;
            }
        }
    }

    return (double)wordsMet / wordsInSentenceCount;
}

int* getWordsStatistic(char** wordsInText, int wordsInTextCount, char** wordsInSentence, int wordsInSentenceCount)
{
    int* occ = new int[wordsInSentenceCount] {};

    for (int i = 0; i < wordsInSentenceCount; i++)
    {
        for (int j = 0; j < wordsInTextCount; j++)
        {
            if (strcmp(wordsInText[j], wordsInSentence[i]) == 0)
            {
                occ[i]++;
            }
        }

    }

    return occ;
}

int main()
{
    char text[1025];
    std::cin.getline(text, 1025);

    int wordsInTextCount = getWordsCount(text);
    char** wordsInText = new char* [wordsInTextCount];
    extractWordsFromSentence(text, wordsInText);

    int sentenceLength;
    std::cin >> sentenceLength;
    std::cin.ignore();

    char* sentence = new char[sentenceLength + 1]{};
    std::cin.getline(sentence, sentenceLength + 1);

    int wordsInSentenceCount = getWordsCount(sentence);
    char** wordsInSentence = new char* [wordsInSentenceCount];
    extractWordsFromSentence(sentence, wordsInSentence);

    int consecutiveWordsCount = findConsecutiveWordsCount(wordsInText, wordsInTextCount, wordsInSentence, wordsInSentenceCount);

    std::cout << consecutiveWordsCount << std::endl;

    double sameWordsPercent = findSameWordsPercent(wordsInText, wordsInTextCount, wordsInSentence, wordsInSentenceCount);

    std::cout << sameWordsPercent << std::endl;

    int* wordsOcc = getWordsStatistic(wordsInText, wordsInTextCount, wordsInSentence, wordsInSentenceCount);

    for (int i = 0; i < wordsInSentenceCount; i++)
    {
        std::cout << wordsInSentence[i] << ": " << wordsOcc[i] << std::endl;
    }

    delete[] wordsOcc;

    for (int i = 0; i < wordsInSentenceCount; i++)
    {
        delete[] wordsInSentence[i];
    }
    delete[] wordsInSentence;

    delete[] sentence;

    for (int i = 0; i < wordsInTextCount; i++)
    {
        delete[] wordsInText[i];
    }

    delete[] wordsInText;

    return 0;
}