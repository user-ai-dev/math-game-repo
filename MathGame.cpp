#include <iostream>
#include <string>
using namespace std;

enum enQuestionLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, MixLevel = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix = 5 };

struct stQuestionsList
{
    int QuestionNumber = 0;
    int Number1 = 0;
    int Number2 = 0;
    int PlayerAnswer = 0;
    int CorrectAnswer = 0;
    enQuestionLevel QuestionLevel;
    enOperationType OperationType;
    bool ResultAnswer = false;
};

struct stQuizz
{
    stQuestionsList QuestionsList[100];
    int NumberOfQuestions = 0;
    int NumberOfRightAnswers = 0;
    int NumberOfWrongAnswers = 0;
    enQuestionLevel QuestionLevel;
    enOperationType OperationType;
    bool IsPass = false;
};

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int ReadHowManyQuestions()
{
    int Question = 0;
    do 
    {
        cout << "How Many Questions Do You Want to Answer ? ";
        cin >> Question;

    } while (Question < 1 || Question > 10);

    return Question;
}

enQuestionLevel ReadQuestionLevel()
{
    int QuestionLevel = 0;

    do
    {
        cout << "Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix, ? ";
        cin >> QuestionLevel;

    } while (QuestionLevel < 1 || QuestionLevel > 4);

    return (enQuestionLevel)QuestionLevel;
}

enOperationType ReadOperationType()
{
    int OperationType = 0;

    do
    {
        cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Med, [5] Mix, ? ";
        cin >> OperationType;

    } while (OperationType < 1 || OperationType > 5);

    return (enOperationType)OperationType;
}

enOperationType GetRndomOperationType()
{
    return enOperationType(RandomNumber(1, 4));
}

string GetOperationTypeSymbol(enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return "+";
    case enOperationType::Sub:
        return "-";
    case enOperationType::Mul:
        return "X";
    case enOperationType::Div:
        return "/";
    default:
        return "Mix";
    }
}

string GetFinalResultText(bool IsPass)
{
    if (IsPass)
        return "Pass :-)";
    else
        return "Fail :-(";
}

string QuestionsLevelName(enQuestionLevel Level)
{
    string QuestionLevel[4] = { "Easy","Meduim","Hard","Mix" };
    return QuestionLevel[Level - 1];
}

string OperationTypeName(enOperationType OpType)
{
    string ArrOpType[5] = { "Add","Sub","Mul","Div","Mix" };
    return ArrOpType[OpType - 1];
}

int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Sub:
        return Number1 - Number2;
    case enOperationType::Mul:
        return Number1 * Number2;
    case enOperationType::Div:
        return Number1 / Number2;
    default:
        return Number1 + Number2;
    }
}

int ReadQuestionAnswer()
{
    int Answer = 0;
    cin >> Answer;
    return Answer;
}

stQuestionsList GenerateQuestion(enQuestionLevel QuestionLevel, enOperationType OperationType)
{
    stQuestionsList Question;

    if (QuestionLevel == enQuestionLevel::MixLevel)
        QuestionLevel = enQuestionLevel(RandomNumber(1, 3));

    if (OperationType == enOperationType::Mix)
        OperationType = GetRndomOperationType();
   

    Question.OperationType = OperationType;


    switch (QuestionLevel)
    {
    case enQuestionLevel::EasyLevel:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);

        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
        Question.QuestionLevel = QuestionLevel;
        return Question;

    case enQuestionLevel::MedLevel:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);

        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
        Question.QuestionLevel = QuestionLevel;
        return Question;

    case enQuestionLevel::HardLevel:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);

        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
        Question.QuestionLevel = QuestionLevel;
        return Question;
    }
}

void GenerateQuizzQuestions(stQuizz& Quizz)
{
    for (int Question = 0; Question < Quizz.NumberOfQuestions; Question++)
    {
        Quizz.QuestionsList[Question] = GenerateQuestion(Quizz.QuestionLevel, Quizz.OperationType);
    }
}

void PrintQuestionInfo(int QuestionNumber, stQuizz Quizz)
{
    cout << "\n\nQuestion [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n\n";
    cout << Quizz.QuestionsList[QuestionNumber].Number1 << endl;
    cout << Quizz.QuestionsList[QuestionNumber].Number2 << "  ";
    cout << GetOperationTypeSymbol(Quizz.QuestionsList[QuestionNumber].OperationType) << endl;
    cout << "_____________\n";
}

void SetScreenColor(bool AnswerResult)
{
    if (AnswerResult)
        system("color 2F");
    else
    {
        cout << "\a";
        system("color 4F");
    }
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, int QuestionNumber)
{

    if (Quizz.QuestionsList[QuestionNumber].PlayerAnswer != Quizz.QuestionsList[QuestionNumber].CorrectAnswer)
    {
        Quizz.QuestionsList[QuestionNumber].ResultAnswer = false;
        Quizz.NumberOfWrongAnswers++;
        cout << "Wrong Answer :-(\n";
        cout << "The Right Answer Is : " << Quizz.QuestionsList[QuestionNumber].CorrectAnswer;
        cout << endl;
    }
    else
    {
        Quizz.QuestionsList[QuestionNumber].ResultAnswer = true;
        Quizz.NumberOfRightAnswers++;
        cout << "Right Answer :-)\n";
    }
    
    SetScreenColor(Quizz.QuestionsList[QuestionNumber].ResultAnswer);

}

void AskAndCorrectQuestionsListAnswers(stQuizz& Quizz)
{
    for (int Question = 0; Question < Quizz.NumberOfQuestions; Question++)
    {
        PrintQuestionInfo(Question, Quizz);
        Quizz.QuestionsList[Question].PlayerAnswer = ReadQuestionAnswer();
        CorrectTheQuestionAnswer(Quizz, Question);
    }

    Quizz.IsPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}

void PrintGameResultes(stQuizz Quizz)
{
    cout << "___________________________________________\n\n";
    cout << "Final Result is " << GetFinalResultText(Quizz.IsPass) << endl;
    cout << "___________________________________________\n";
    cout << "Number Of Questions     : " << Quizz.NumberOfQuestions << endl;
    cout << "Questions Level         : " << QuestionsLevelName(Quizz.QuestionLevel) << endl;
    cout << "Operation Type          : " << OperationTypeName(Quizz.OperationType) << endl;
    cout << "Number Of Right Answers : " << Quizz.NumberOfRightAnswers << endl;
    cout << "Number Of Wrong Answers : " << Quizz.NumberOfWrongAnswers << endl;
    cout << "___________________________________________\n";
}

void PlayMathGame()
{
    stQuizz Quizz;
    Quizz.NumberOfQuestions = ReadHowManyQuestions();
    Quizz.QuestionLevel = ReadQuestionLevel();
    Quizz.OperationType = ReadOperationType();

    GenerateQuizzQuestions(Quizz);
    AskAndCorrectQuestionsListAnswers(Quizz);
    PrintGameResultes(Quizz);
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        ResetScreen();
        PlayMathGame();
        cout << "Do you Want To Play Again ? Y/N ? ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();

}

