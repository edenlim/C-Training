#include <stdio.h>
#include <string.h>

int score = 0;
char name[50];
int question_count = 3;

const char *questions[] = {
    "1. What is 1 + 1?\n",
    "2. What is the name of the capital of Germany?\n",
    "3. What is the shark from Ikea called?\n"
};

const char *answers[] = {
    "2", 
    "Berlin", 
    "Blahaj"
};

const char* standard_reply(int result){
  if(result == 0) {
    return "The answer is correct!\n";
  } else {
    return "The answer is incorrect!\n";
  }
}

int main(void) {
  printf("Hello, what is your name?\n");
  fgets(name, sizeof(name), stdin);
  name[strcspn(name, "\n")] = '\0';
  printf("Hello %s, we will now begin the quiz. Press enter to continue\n",
         name);
  while (getchar() != '\n');
  for(int current_question_number = 0; current_question_number < question_count; current_question_number++){
    char answer[50];
    printf("%s\n", questions[current_question_number]);
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = '\0';
    int result = strcasecmp(answer, answers[current_question_number]);
    if(result == 0){
      score++;
    } 
    printf("%s", standard_reply(result));
    while (getchar() != '\n');
    
  }
  printf("The quiz has ended. Your final score is %d out of %d\n", score, question_count);
  return 0;
}

