#ifndef MATRICULA_IRA_H_
#define MATRICULA_IRA_H_

#include <cctype>
#include <cmath>
#include <stdexcept>
#include <string>
#include <vector>
#include <functional>
#include <iostream>

#define DEFAULT_COUNT 10

#define DECLARE(type, name)                        \
  private:                                         \
    type _##name;                                  \
  public:                                          \
    void set_##name(type& var)                     \
    {                                              \
      _##name = var;                               \
    }                                              \
    type get_##name()                              \
    {                                              \
      return _##name;                              \
    }                                              \

#define VALIDATE_CLAUSE(condition, error_message) \
    [&]() -> std::pair<bool, std::string> { \
        return { condition, error_message }; \
    }

class Aluno {
  DECLARE(int, matricula);
  DECLARE(double, ira);
  DECLARE(std::string, nome);
  public:
    Aluno(int matricula, double ira, const std::string& nome)
    : _matricula(matricula), _ira(ira), _nome(nome) {}
};

void addAluno(std::vector<Aluno>& alunoVec, int matricula, double ira, const std::string& nome);
template<typename T>
void verifiedInput(const std::string& title,
                   T& input,
                   const std::vector<std::function<std::pair<bool, std::string>()>>& checks);
void promptAluno(std::vector<Aluno>& v, int i, int count);
void printAluno(Aluno aluno);
void printAlunoVector(std::string title, std::vector<Aluno> v);
int getMinMatriculaAlunoIndex(std::vector<Aluno> v);
void swapAluno(Aluno& x, Aluno& y);
std::vector<Aluno> selectionSort(std::vector<Aluno> v);
std::vector<Aluno> insertionSort(std::vector<Aluno> v);
std::vector<Aluno> bubbleSort(std::vector<Aluno> v);

#endif // MATRICULA_IRA_H_
