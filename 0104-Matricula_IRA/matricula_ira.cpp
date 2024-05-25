#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define declare(type, name)                        \
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

class Aluno {
  declare(int, matricula);
  declare(double, ira);
  declare(std::string, nome);
  public:
    Aluno(int matricula, double ira, const std::string& nome)
    : _matricula(matricula), _ira(ira), _nome(nome) {}
};

void addAluno(std::vector<Aluno>& alunoVec, int matricula, double ira, const std::string& nome) {
  Aluno newAluno(matricula, ira, nome);
  alunoVec.push_back(newAluno);
}

void printAluno(Aluno aluno) {
  std::cout << "\n-------- #### ----------\n"
            << "Nome: " << aluno.get_nome()
            << "\nMatricula: " << aluno.get_matricula()
            << "\nIRA: " << aluno.get_ira()
            << "\n-------- #### ----------\n" << std::endl;
}

void printAlunoVector(std::string title, std::vector<Aluno> v) {
  std::cout << "\n...!.... !!!! ......!...\n"
            << title << " :"
            << "\n...!.... !!!! ......!...\n" << std::endl;
  for(Aluno& aluno : v) {
    printAluno(aluno);
  }
}

int getMinMatriculaAlunoIndex(std::vector<Aluno> v) {
  int minMatriculaAlunoIndex = 0;
  for (int i = 1; i < v.size(); ++i) {
    if (v[i].get_matricula() < v[minMatriculaAlunoIndex].get_matricula()) {
     minMatriculaAlunoIndex = i;
    }
  }
  return minMatriculaAlunoIndex;
}

void swapAluno(Aluno& x, Aluno& y) {
  Aluno _x = x;
  x = y;
  y = _x;
}

std::vector<Aluno> selectionSort(std::vector<Aluno> v) {
  std::vector<Aluno> copyV(v);
  std::vector<Aluno> sorted;

  for (int i = 0; i < v.size(); ++i) {
    int minIndex = getMinMatriculaAlunoIndex(copyV);
    sorted.push_back(copyV[minIndex]);
    copyV.erase(copyV.begin() + minIndex);
  }

  return sorted;
}

std::vector<Aluno> insertionSort(std::vector<Aluno> v) {
  std::vector<Aluno> sorted(v);
  int i, j;
  i = (j = 1);
  for (; i < sorted.size(); ++i, j=i) {
    Aluno aluno = sorted[i];
    while(--j, j >= 0 && sorted[j].get_matricula() > aluno.get_matricula())
      sorted[j + 1] = sorted[j];
    sorted[j + 1] = aluno;
  }
  return sorted;
}

std::vector<Aluno> bubbleSort(std::vector<Aluno> v) {
  std::vector<Aluno> sorted(v);
  int i, j, n=v.size();
  for(i = (j = 0); j < n-1; ++j, i = (i+1) % (n-1))
    if(sorted[i].get_matricula() > sorted[i+1].get_matricula())
      swapAluno(sorted[i], sorted[i+1]), j = 0;
  return sorted;
}

int main(void) {
  std::vector<Aluno> alunoVector;
  std::vector<Aluno> selectionSorted;
  std::vector<Aluno> bubbleSorted;
  std::vector<Aluno> insertionSorted;

  addAluno(alunoVector, 42, 9.0, "Alberto");
  addAluno(alunoVector, 369, 9.9, "Maria");
  addAluno(alunoVector, 352, 8.5, "Beatriz");
  addAluno(alunoVector, 30, 7.5, "Carlos");

  selectionSorted = selectionSort(alunoVector);
  bubbleSorted = bubbleSort(alunoVector);
  insertionSorted = insertionSort(alunoVector);

  printAlunoVector("Selection Sort", selectionSorted);
  printAlunoVector("Bubble Sort", bubbleSorted);
  printAlunoVector("Insertion Sort", insertionSorted);

   return 0;
}
