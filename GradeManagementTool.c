/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

#define MAX_GRADE 100
#define MIN_GRADE 0
#define TOTAL_GRADE 101


/*-------------------------------------------------------------------------
Check the grades of C.S. Students
 -------------------------------------------------------------------------*/

int sum(int num) {
    static int sum = 0;
    sum += num;
    return sum;
}

double avg(int sum,int counter) {
    if (counter != 0) {
        double avg = (double) sum / counter;
        return avg;
    }
    else
        return 0;

}

int avgR(int sum, int counter) {
    int avgRound = (int) (avg(sum,counter) + 0.5);
    return avgRound;
}

/* int Size(int* arr[]) { // Error
    int arraySize = sizeof(*arr) / sizeof(*arr[0]);
    return arraySize;
} */

int minimum(int num[]) {
    int min = MAX_GRADE;
    for (int i = 0; i < TOTAL_GRADE; i++) {
        if (num[i] != 0) {
            min = i;
            break;
        }
    }
    return min;
}

int maximum (int num[]) {
    int max = MIN_GRADE;
    for (int i = 100; i > 0; i--) {
        if (num[i] != 0) {
            max = i;
            break;
        }
    }
    return max;
}

int median(int num[]) {
    int median = 0, sum = 0;
    for (int i = 0; i < TOTAL_GRADE; i++)
        sum += num[i];
    int n = (sum+1)/2;
    sum = 0;
    int j = 0;
    while (sum < n)
    {
        sum += num[j];
        median = j;
        j++;
    }
    return median;
}

int greater(int array[], int num) { // CHECK
    int sum = 0;
    if (num > 0)
        for (int i = num + 1; i < 101; i++)
            sum += array[i];
    else
        for (int i = 0; i < 101; i++)
            sum += array[i];
    return sum;
}

int less(int array[],int num) {
    int sum = 0;
    if (num <= 101)
    for (int i = num - 1; i >= 0; i--)
        sum += array[i];
    else
        for (int i = 101; i > 0; i--) {
            sum += array[i];
        }
    return sum;
}


/* int between(int array[],int num1,int num2) { // Double check
    if (num1 == num2)
        return 0;
    int maximum = num1 > num2 ? num1:num2;
    int minimum = num1 < num2 ? num1:num2;
    if (maximum < 0 || minimum > 100)
        return 0;
    else {
        maximum = maximum > 100 ? 100:maximum;
        minimum = minimum < 0 ? 0:minimum;
    }
    int sum = 0;
    for (int i = minimum + 1; i < maximum; i++)
    {
        sum += array[i];
    }
    return sum;
} */

int factor(int array[],int pass, double percent) {
    int factor = 0,length = 0,sum = 0;
    double per;
    percent /= 100;
    int min = minimum(array);
    int max = maximum(array);
    for (int i = min; i <= max; i++) //LENGTH
        {
            if (array[i] != 0)
                length += array[i];
        }
    for (int i = max; i >= min; i--)
    {
        if (array[i] == 0)
            continue;
        factor = i > pass ? factor:pass-i;
        sum += array[i];
        per = (double) sum / length;
        if (per >= percent)
            break;

    }
    return factor;
}


int main()
{
    int grade,sum1 = 0,counter = 0;
    int grades[TOTAL_GRADE] = {0};
    printf("Enter your grades ending with '-1':\n");
    printf("No grades above 100 or below 0 are counted\n);
    while (grade != -1 || (counter % 2 != 1 && counter != 0)) {
        if (scanf("%d", &grade) != 1)
            return 1;
        if (grade > 100 || grade < 0)
            continue;
        for (int i = 0; i < TOTAL_GRADE; i++)
        {
            if (grade == i)
                grades[i]++;
        }
        sum1 = sum(grade);
        counter++;
    }
    char in;

    while (1)
    {
        printf("Enter your command:\n");
        if (scanf(" %c", &in) != 1)
            break;
        switch (in) {
        case 'V': {printf("%d\n",avgR(sum1,counter)); break;} // Rounded Average
        case 'X': { // Maximum
            printf("%d\n",maximum(grades));
            break;
        } 
        case 'I': {printf("%d\n",minimum(grades)); break;} // Minimum
        case 'M': // Median
        {
            printf("%d\n",median(grades));
            break;

        }
        case 'A': // Greater than
        {
            int temp1;
            printf("Enter lower bound:\n");
            if (scanf("%d",&temp1) != 1)
                break;
            printf("%d\n",greater(grades,temp1));
            break;

        } 
        case 'B': { // Less than

            int temp1;
            printf("Enter upper bound:\n");
            if (scanf("%d",&temp1) != 1)
                break;
            printf("%d\n",less(grades,temp1));
            break;

        } // Factor
        case 'F': {
            int temp1;
            double temp2;
            printf("Enter passing grade and what percentage of the class needs to pass:\n");
            if (scanf("%d %lf",&temp1,&temp2) != 2)
                break;
            if (temp1 > 100 || temp2 > 100) {
                printf("0\n");
                break;
            }
            printf("%d\n",factor(grades,temp1,temp2));
            break;

        } // (input1) < x (input2)
        default: {printf("This command is not currently supported by the system.\n"); break;} // Default output

        }
    }

  return 0;
}
