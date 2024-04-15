# Projeto de Acompanhamento Personalizado com IA

Bem-vindo à documentação do projeto de acompanhamento personalizado com IA. Este documento explica como a Inteligência Artificial é aplicada no projeto para fornecer sugestões personalizadas de treino e alimentação aos usuários.

## Introdução

O objetivo deste projeto é oferecer um aplicativo que utiliza IA para personalizar planos de treino e alimentação de acordo com os objetivos e características individuais dos usuários.

## Integrantes do grupo

Henrique Baptista - RM97796

Igor Ribeiro Anccilotto - RM550415

Pedro Henrique Endo de Oliveira - RM551446

Kauane Almeida Gonçalves - RM551405

Luigi Exposito Uchiyama - RM99520

## Seção 1: Classificação dos Usuários com IA

### 1.1. Coleta de Dados do Usuário

Coletamos dados dos usuários, como idade, peso, altura, tipo de corpo, histórico de saúde e objetivos de fitness.

### 1.2. Pré-processamento de Dados

Os dados coletados são pré-processados para garantir qualidade e consistência. Isso inclui a remoção de ruído, tratamento de valores ausentes e normalização.

### 1.3. Modelo de Classificação

Usamos um modelo de IA para classificar os usuários com base em seus dados. O modelo identifica o objetivo do usuário, tipo de corpo e outras características relevantes.

O modelo é treinado com uma ampla variedade de dados de usuários, usando técnicas de validação cruzada para garantir boa generalização. As métricas de desempenho incluem precisão, recall e F1-score.

### 1.4 Modelos possíveis de Machine Learning para classificação

- **Logistic Regression:** Útil para classificação binária ou multi-classe, com boa interpretabilidade.
- **K-Nearest Neighbors (KNN)**: Classificador fácil de entender que pode ser útil para sugestões de treino personalizadas
- **Random Forest:** Combina várias árvores de decisão para uma classificação mais precisa e robusta.
- **Support Vector Machines (SVM):** Pode ser útil para problemas de classificação complexos com um alto grau de precisão.
- **Neural Networks:** Modelos poderosos para lidar com dados complexos e alta dimensionalidade.

## Seção 2: Sugestões de Treino e Alimentação

### 2.1. Processamento dos Dados Classificados

Os dados classificados dos usuários são usados para gerar sugestões personalizadas de treino e alimentação.

### 2.2. Gerenciamento de Treinos Personalizados

A IA sugere sequências de treinos e planos personalizados com base nos objetivos e tipo de corpo do usuário.

### 2.3. Planos de Alimentação

A IA também recomenda planos de alimentação personalizados, com sugestões sobre a ingestão de calorias, macronutrientes e micronutrientes.

## Seção 3: API com ChatGPT para Recomendações Gerativas

### 3.1. Integração com ChatGPT

O aplicativo integra uma API com ChatGPT para interagir com os usuários, fornecendo recomendações gerativas.

### 3.2. Gerenciamento de Interações com ChatGPT

A API com ChatGPT permite aos usuários fazer perguntas sobre treinos, planos e dicas de alimentação. A API retorna respostas com base nas interações e nas necessidades individuais dos usuários.

## Conclusão

A implementação de IA neste projeto oferece personalização e orientação eficazes para os usuários em sua jornada de fitness.

Se você tiver sugestões ou feedback, fique à vontade para entrar em contato conosco.

---

Obrigado por usar nosso projeto! 😊
