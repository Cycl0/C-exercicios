#include "matricula_ira.h"

int main(void) {
  std::vector<Aluno> alunoVector;
  std::vector<Aluno> selectionSorted;
  std::vector<Aluno> insertionSorted;
  std::vector<Aluno> bubbleSorted;

  int count = DEFAULT_COUNT; // 10

  for (int  i = 0; i < count; ++i)
    promptAluno(alunoVector, i, count);

  selectionSorted = selectionSort(alunoVector);
  insertionSorted = insertionSort(alunoVector);
  bubbleSorted = bubbleSort(alunoVector);

  printAlunoVector("Selection Sort (Matricula)", selectionSorted);
  printAlunoVector("Insertion Sort (Matricula)", insertionSorted);
  printAlunoVector("Bubble Sort (IRA)", bubbleSorted);

   return 0;
}

void addAluno(std::vector<Aluno>& alunoVec, int matricula, double ira, const std::string& nome) {
  Aluno newAluno(matricula, ira, nome);
  alunoVec.push_back(newAluno);
}

template<typename T>
void verifiedInput(const std::string& title,
                   T& input,
                   const std::vector<std::function<std::pair<bool, std::string>()>>& checks) {
  while (true) {
    std::cout << "\n——————— ---------- ————————\n"
              << title
              << "\n——————— ---------- ————————" << std::endl;
    if (std::cin >> input) {
      bool inputIsValid = true;
      for (const auto& check : checks) {
        auto result = check();
        if (result.first) {
          std::cout << result.second << std::endl;
          inputIsValid = false;
          break;
        }
      }
      if (inputIsValid) {
        break;
      }
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "\nErro: tipo imcompativel." << std::endl;
    }
  }
}

void promptAluno(std::vector<Aluno>& v, int i, int count) {
  int matricula;
  double ira;
  std::string nome;

  std::cout << "\nxxxxxxx \' \' \' \' xxxxxxx\n"
            << "Insira Aluno " << "(" <<  i+1 << "/" << count << ")"
            << "\nxxxxxxx \' \' \' \' xxxxxxx" << std::endl;

  verifiedInput("Nome (Max 60 caracteres):", nome, {
    VALIDATE_CLAUSE(nome.empty(), "Erro: 'nome' deve ser registrado."),
    VALIDATE_CLAUSE(nome.size() > 60, "Erro: 'nome' nao deve exceder 60 caracteres."),
    VALIDATE_CLAUSE(std::all_of(nome.begin(), nome.end(), ::isdigit), "Erro: 'nome' nao deve ser um numeral.")
  });

    
  verifiedInput("Ira:", ira, {
    VALIDATE_CLAUSE(ira < 0, "Erro: 'ira' deve ser positivo.")
  });

    verifiedInput("Matricula:", matricula, {
    VALIDATE_CLAUSE(matricula < 0, "Erro: 'matricula' deve ser positivo.")
  });

  addAluno(v, matricula, ira, nome);

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
  for (Aluno& aluno : v) {
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
  for (i = (j = 0); j < n-1; ++j, i = (i+1) % (n-1))
    if(sorted[i].get_ira() > sorted[i+1].get_ira())
      swapAluno(sorted[i], sorted[i+1]), j = 0;
  return sorted;
}
