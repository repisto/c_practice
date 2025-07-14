#include <stdio.h>

void swap(int *num1, int *num2);
void inputScore(int score[][3], int row);
void outputScore(int score[][3], int row);
int calculateAverage(int score[][3], int row, int average[]);
void sortDescending(int average[], int len, int index[]);
void outputAverageScore(int average[], int len, int totalAverage, int index[]);
int main() {
  int score[5][3] = {0};
  inputScore(score, 5);
  outputScore(score, 5);
  int average[5] = {0};
  int totalAverage = calculateAverage(score, 5, average);
  int studentIndex[5] = {0, 1, 2, 3, 4};
  sortDescending(average, 5, studentIndex);
  outputAverageScore(average, 5, totalAverage, studentIndex);
  printf("program end\n");
  return 0;
}
void swap(int *num1, int *num2) {
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}
void inputScore(int score[][3], int row) {
  for (int i = 0; i < row; i++) {
    printf("Input student %d's score.\n", i);
    for (int j = 0; j < 3; j++) {
      if (j == 0) {
        printf("math: ");
        scanf("%d", &score[i][j]);
      } else if (j == 1) {
        printf("korean: ");
        scanf("%d", &score[i][j]);
      } else if (j == 2) {
        printf("english: ");
        scanf("%d", &score[i][j]);
      }
    }
  }
}
void outputScore(int score[][3], int row) {
  for (int i = 0; i < row; i++) {
    printf("Output student %d's score.\n", i);
    for (int j = 0; j < 3; j++) {
      if (j == 0) {
        printf("math: %d, ", score[i][j]);
      } else if (j == 1) {
        printf("korean: %d, ", score[i][j]);

      } else if (j == 2) {
        printf("english: %d, ", score[i][j]);
      }
    }
    printf("\n");
  }
}
int calculateAverage(int score[][3], int row, int average[]) {
  int totalSum = 0;
  for (int i = 0; i < row; i++) {
    int sum = 0;
    for (int j = 0; j < 3; j++) {
      sum += score[i][j];
    }
    int avg = sum / 3;
    average[i] = avg;
    totalSum += sum;
  }
  return totalSum / (row * 3);
}
void sortDescending(int arr[], int len, int index[]) {
  int maxIndex = 0;
  for (int i = 0; i < len - 1; i++) {
    maxIndex = i;
    for (int j = i + 1; j < len; j++) {
      if (arr[maxIndex] < arr[j]) {
        maxIndex = j;
      }
    }
    swap(&arr[i], &arr[maxIndex]);
    swap(&index[i], &index[maxIndex]);
  }
}
void outputAverageScore(int average[], int len, int totalAverage, int index[]) {
  for (int i = 0; i < len; i++) {
    printf("Student %d: ", index[i]);
    printf("%d ", average[i]);
    if (average[i] >= totalAverage)
      printf("pass\n");
    else
      printf("fail\n");
  }
}
