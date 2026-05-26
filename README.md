# 🧮 Math Quiz Game

A console-based C++ math quiz game that tests your arithmetic skills across different difficulty levels and operation types.

---

## 📖 Overview

Math Quiz Game is an interactive command-line application that generates random math questions and evaluates your answers in real time. The screen changes color based on whether your answer is correct or wrong, giving instant visual feedback.

---

## ✨ Features

- **4 Difficulty Levels**: Easy, Medium, Hard, and Mix
- **5 Operation Types**: Addition, Subtraction, Multiplication, Division, and Mix
- **Configurable Quiz Length**: Choose between 1 and 10 questions per round
- **Real-time Feedback**: Screen turns green for correct answers, red for wrong ones — with a sound alert on mistakes
- **Score Summary**: Full results displayed at the end of each round
- **Replay Option**: Play as many rounds as you want without restarting the program

---

## 🎮 How to Play

1. Run the program.
2. Enter the number of questions (1–10).
3. Choose a difficulty level:
   - `1` Easy (numbers 1–10)
   - `2` Medium (numbers 10–50)
   - `3` Hard (numbers 50–100)
   - `4` Mix (random difficulty per question)
4. Choose an operation type:
   - `1` Add
   - `2` Sub
   - `3` Mul
   - `4` Div
   - `5` Mix
5. Answer each question as it appears.
6. View your final score and decide whether to play again.

---

## 📊 Scoring

- **Pass**: Number of correct answers ≥ number of wrong answers
- **Fail**: Number of correct answers < number of wrong answers

---

## 🏗️ Project Structure

```
MathQuizGame/
│
├── main.cpp          # Full source code
└── README.md         # Project documentation
```

### Key Components

| Component | Description |
|---|---|
| `enQuestionLevel` | Enum for difficulty levels (Easy, Med, Hard, Mix) |
| `enOperationType` | Enum for operation types (Add, Sub, Mul, Div, Mix) |
| `stQuestionsList` | Struct holding individual question data |
| `stQuizz` | Struct holding the full quiz session data |
| `GenerateQuestion()` | Generates a random question based on level and operation |
| `AskAndCorrectQuestionsListAnswers()` | Runs the quiz loop and evaluates answers |
| `PrintGameResultes()` | Displays the final score summary |
| `StartGame()` | Entry point for the game loop with replay support |

---

## 📄 License

This project is open source and free to use for educational purposes.

---

👤 Author
👤 Ahmed Mohamed
📧 ahmed.mohamed@example.com
💼 linkedin.com/in/ahmed-mohamed



