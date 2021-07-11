// write a c program t perform addition of two polynomials in one variable using arrays

#include <stdio.h>
#define MAXLENGTH 15

typedef struct
{
  int coeff;
  int exp;
} terms;

terms polynomials[MAXLENGTH];

int dVal, i;

int attach(int c, int e)
{
  if (dVal > MAXLENGTH)
  {
    printf("\nExceeded array length");
    return 0;
  }

  polynomials[dVal].coeff = c;
  polynomials[dVal].exp = e;
  dVal++;
}

void pAdd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
{
  int eval;
  *startD = finishB + 1;
  dVal = *startD;
  while (startA <= finishA && startB <= finishB)
  {
    eval = polynomials[startA].exp - polynomials[startB].exp;
    if (eval > 0)
    {
      attach(polynomials[startA].coeff, polynomials[startA].exp);
      startA++;
    }
    else if (eval < 0)
    {
      attach(polynomials[startB].coeff, polynomials[startB].exp);
      startB++;
    }
    else
    {
      attach(polynomials[startA].coeff + polynomials[startB].coeff, polynomials[startA].exp);
      startA++;
      startB++;
    }
    *finishD = dVal - 1;
  }

  for (; startA <= finishA; startA++)
    attach(polynomials[startA].coeff, polynomials[startA].exp);
  for (; startB <= finishB; startB++)
    attach(polynomials[startB].coeff, polynomials[startB].exp);
  finishD--;
}

void displayPolynomial(int start, int finish)
{
  for (i = start; i <= finish; i++)
  {
    if (polynomials[i].coeff && (polynomials[i].coeff != 1 || polynomials[i].exp == 0))
      printf("%d", polynomials[i].coeff);
    if (polynomials[i].exp)
      printf("x^%d ", polynomials[i].exp);
    if (i != finish)
      printf(" + ");
  }
}

void readPolynomial(int start, int *finish, int count)
{
  for (i = 0; i < count; i++)
  {
    printf("Enter coefficient for term %d: ", i + 1);
    scanf("%d", &polynomials[start + i].coeff);
    printf("Enter exponent for term %d: ", i + 1);
    scanf("%d", &polynomials[start + i].exp);
  }
  *finish = start + count - 1;
}

void main()
{
  int count;
  int startA = 0, finishA, startB, finishB, startD, finishD;

  printf("How many terms in the first polynomial? ");
  scanf("%d", &count);
  readPolynomial(startA, &finishA, count);
  startB = count;
  printf("\nHow many terms in the second polynomial? ");
  scanf("%d", &count);

  readPolynomial(startB, &finishB, count);

  printf("\nPolynomial 1 = ");
  displayPolynomial(startA, finishA);
  printf("\nPolynomial 2 = ");
  displayPolynomial(startB, finishB);

  pAdd(startA, finishA, startB, finishB, &startD, &finishD);

  printf("\nAfter addition: ");
  displayPolynomial(startD, finishD);
  printf("\n");
}