#include <stdio.h>

struct student
{
  int stdID;
  char name[50];
  float cgpa_in_cse103;
  float cgpa_in_mat101;
  float cgpa_in_eng7101;
  float cgpa;
};

float calculateCGPA(float cse, float mat, float eng);

int main()
{
  FILE *input_file;
  FILE *output_file;

  struct student s[100];
  int n = 0;

  input_file = fopen("./student_input.txt", "r");

  if (input_file == NULL)
  {
    printf("No file found\n");
    return 1;
  }

  fscanf(input_file, "%d", &n);

  for (int i = 0; i < n; i++)
  {
    fscanf(input_file, "%d", &s[i].stdID);
    fscanf(input_file, " %[^\n]", s[i].name);
    fscanf(input_file, "%f", &s[i].cgpa_in_cse103);
    fscanf(input_file, "%f", &s[i].cgpa_in_mat101);
    fscanf(input_file, "%f", &s[i].cgpa_in_eng7101);

    s[i].cgpa = calculateCGPA(s[i].cgpa_in_cse103, s[i].cgpa_in_mat101, s[i].cgpa_in_eng7101);
  }

  fclose(input_file);

  output_file = fopen("./output.txt", "w");

  fprintf(output_file, "------------------------------------------------------------------------\n");
  fprintf(output_file, "%-8s %-15s %-10s %-10s %-10s %-8s\n", "ID", "Name", "CSE103", "MAT101", "ENG7101", "CGPA");
  fprintf(output_file, "------------------------------------------------------------------------\n");

  for (int i = 0; i < n; i++)
  {
    fprintf(output_file, "%-8d %-15s %-10.2f %-10.2f %-10.2f %-8.2f\n",
            s[i].stdID, s[i].name, s[i].cgpa_in_cse103,
            s[i].cgpa_in_mat101, s[i].cgpa_in_eng7101, s[i].cgpa);
  }

  fprintf(output_file, "------------------------------------------------------------------------\n");

  fclose(output_file);

  return 0;
}

float calculateCGPA(float cse, float mat, float eng)
{
  float total_credits = 4.5 + 3 + 3;
  float sum = (cse * 4.5) + (mat * 3) + (eng * 3);
  return sum / total_credits;
}
