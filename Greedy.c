#include <stdio.h>
#include <stdlib.h>

// Structure for an activity (with start and end times)
struct Activity {
    int start;
    int end;
};

// Comparison function for qsort (sort activities by their end time)
int compare(const void *a, const void *b) {
    struct Activity *activityA = (struct Activity *)a;
    struct Activity *activityB = (struct Activity *)b;
    return (activityA->end - activityB->end);
}

// Function to perform the activity selection using the greedy approach
void activitySelection(struct Activity activities[], int n) {
    // Sort activities by their end time
    qsort(activities, n, sizeof(struct Activity), compare);

    printf("Selected activities:\n");

    // The first activity is always selected
    int lastSelected = 0;
    printf("(%d, %d)\n", activities[0].start, activities[0].end);

    // Consider remaining activities
    for (int i = 1; i < n; i++) {
        // If this activity's start time is greater or equal to the last selected end time
        if (activities[i].start >= activities[lastSelected].end) {
            printf("(%d, %d)\n", activities[i].start, activities[i].end);
            lastSelected = i;  // Update the last selected activity
        }
    }
}

// Driver code
int main() {
    struct Activity activities[] = {
        {5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}
    };
    int n = sizeof(activities) / sizeof(activities[0]);

    activitySelection(activities, n);

    return 0;
}
