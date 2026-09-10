# triagem

  O projeto implementa, em linguagem C, um Sistema de Triagem de Pacientes que simula o
gerenciamento da fila de atendimento de uma unidade de saude (por exemplo, um posto de saude
ou pronto-socorro). O problema pratico resolvido e a organizacao do atendimento: garantir que cada
paciente seja cadastrado com uma senha unica e sequencial, e que pacientes com necessidade de
atendimento prioritario sejam posicionados a frente na fila, respeitando a ordem de chegada entre
os proprios prioritarios.
  Essa e uma necessidade real e recorrente: filas com atendimento prioritario sao comuns em
hospitais, clinicas, bancos e servicos publicos, sendo inclusive uma exigencia legal em diversos
paises para grupos como idosos, gestantes e pessoas com deficiencia. A solucao proposta resolve
esse problema de forma simples e realista, sem depender de bibliotecas externas ou banco de
dados: toda a fila e mantida em memoria, atraves de um vetor de registros (struct), e a insercao
prioritaria e feita deslocando elementos do vetor para a posicao correta.
