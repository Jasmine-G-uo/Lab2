#include <stdio.h>

// Define the Student struct
struct Student {
    char name[50];
    int grades[3];
    float average;  // To store the average grade
    float weightedaverage;  // To store the weighted average grade
};

// Function to calculate the average (pass-by-reference)

void calculateAverage(struct Student *student) {
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += student->grades[i];
    }
    student->average = sum / 3.0;  // Calculate and update the average
}



// Function to calculate the weighted average (pass-by-reference)

void WeightedAverage(struct Student *student, float weight[3]) {
    float weightedaverage = 0;
    for (int i = 0; i < 3; i++) {
        weightedaverage += student->grades[i] * weight[i];
    }
    student->weightedaverage = weightedaverage;  // Calculate and update the weighted average
}


// Main function
int main() {
    // Create and initialize an array of 3 students
    struct Student students[3] = {
        {"Andy", {85, 90, 78}, 0},
        {"Randy", {88, 76, 92}, 0},
        {"Sandy", {70, 80, 75}, 0}
    };

    float weight[3] = {0.4, 0.3, 0.3};

    // Call calculateAverage for each student
    for (int i = 0; i < 3; i++) {
        //TODO;  // Pass each student by reference
        calculateAverage(&students[i]);
    }

    // Call weightedAverage for each student
    for (int i = 0; i < 3; i++) {
        //TODO;  // Pass each student by reference
        WeightedAverage(&students[i], weight);
    }

    // Print student details
    for (int i = 0; i < 3; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Grades: %d, %d, %d\n", students[i].grades[0], students[i].grades[1], students[i].grades[2]);
        printf("Average: %.2f\n", students[i].average);
        printf("WeightedAverage: %.2f\n\n", students[i].weightedaverage);
    }

    int top = 0;
    for (int i = 1; i < 3; i++){
        if (students[i].weightedaverage > students[top].weightedaverage){
            top = i;
        }
    }
    printf("Top Student is: %s\n", students[top].name);
    
    return 0;
}
