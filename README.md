# cpp_Module_05-09

## 05

### Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!



## Pegar uma branch de um repositório no GitHub e enviar para outro repositório Git

### 🧭 Cenário

#### Tens um repositório no GitHub, por exemplo:

https://github.com/alfa48/projeto.git

#### Para Adiciona o remoto do outro repositório, use:

git remote add origin git@outro.repositorio:ola/_project.git

## 🚀 Passo a passo completo
### 1. Clona o repositório original (do GitHub) e garante que estás na branch certa
### 2. Adiciona o remoto do outro git
Ex: git remote add origin git@outro.repositorio:ola/_project.git
### 3. Faz o push da branch específica para o outro git:
ex: git push origin dev:master
