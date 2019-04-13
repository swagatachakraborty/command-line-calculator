#include <stdio.h>

typedef float (*func_ptr)(float, float);
func_ptr get_function(char);

float add(float, float);
float sub(float, float);
float multiply(float, float);
float division(float, float);
float percentage(float, float);

int main()
{
  float index = 0, operand1, operand2, result = 0;
  char operator;

  printf("Enter first operand : ");
  scanf("%f", &operand1);

  printf("Enter second operand : ");
  scanf("%f", &operand2);

  getchar();

  printf("Enter operator : ");
  scanf("%c", &operator);

  printf("%.2f %c %.2f = ", operand1, operator, operand2);
  printf("%.4f\n", get_function(operator)(operand1, operand2));
  return 1;
}

func_ptr get_function(char operator)
{
  switch (operator)
  {
  case '-':
    return &sub;

  case '*':
    return &multiply;

  case '/':
    return &division;

  case '%':
    return &percentage;

  default:
    return &add;
  }
}

float add(float a, float b)
{
  return a + b;
}

float sub(float a, float b)
{
  return a - b;
}

float division(float a, float b)
{
  return a / b;
}

float multiply(float a, float b)
{
  return a * b;
}

float percentage(float a, float b)
{
  return a * b / 100;
}