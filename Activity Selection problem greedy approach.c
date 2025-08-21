#include <stdio.h>

// Structure to represent an activity
typedef struct {
    int start;
    int end;
} Activity;

// Function to sort activities by finish time (selection sort)
void sortByFinishTime(Activity activities[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (activities[j].end < activities[minIndex].end) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Activity temp = activities[i];
            activities[i] = activities[minIndex];
            activities[minIndex] = temp;
        }
    }
}

// Function to perform activity selection
void selectActivities(Activity activities[], int n) {
    sortByFinishTime(activities, n);

    printf("\nSelected activities:\n");
    int lastFinish = activities[0].end;
    printf("Activity 1: Start = %d, End = %d\n", activities[0].start, activities[0].end);

    int count = 1;
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            count++;
            printf("Activity %d: Start = %d, End = %d\n", count, activities[i].start, activities[i].end);
            lastFinish = activities[i].end;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    Activity activities[n];
    printf("Enter start and end times of each activity:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &activities[i].start, &activities[i].end);
    }

    selectActivities(activities, n);

    return 0;
}
