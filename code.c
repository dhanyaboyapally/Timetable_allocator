#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int students[3];
char faculty[12];
char courses[12];
int classrooms[6];
int timeSlots[12][6];
int available_timeslots[12][6][6];
int ug2[4];
int ug3[4];
int ug4[4];
int ug_courses[3][12];
int faculty_courses[12][12];
char ug2_graph[6][6];
char ug3_graph[6][6];
char ug4_graph[6][6];
int course_classroom[12];

void getData() {
  // no.of faculty
  // no.of course
  // no.of students
  // no.of classroom etc.
  for (int j = 0; j < 12; j++) {
    printf("Enter name of faculty-%d:", (j + 1));
    scanf("%s", &faculty[j]);
  }

  for (int l = 0; l < 6; l++) {
    printf("Enter classroom-number-%d:", (l + 1));
    scanf("%d", &classrooms[l]);
  }
}
void getStudentEnrollment() {
  // steps to get students enrolled for subjects
  for (int i = 0; i < 3; i++) {
    printf("Enter the number of students for ug-%d: ", (i + 2));
    scanf("%d", &students[i]);
  }
}
void getCourseOffered() {
  // steps to get a list of courses offered by faculty
  for (int k = 0; k < 12; k++) {
    printf("Enter name of course-%d:", (k + 1));
    scanf("%s", &courses[k]);
  }
}
void getInitialTimeSlot() {
  // steps to get a time slot for faculty
  for (int n = 0; n < 12; n++) {
    printf("Enter time-slot for faculty-%d for week:", (n + 1));
    for (int m = 0; m < 6; m++) {
      scanf("%d", &timeSlots[n][m]);
    }
  }
}
void ColorEdges() {
  // steps to meet the courses with faculty and courses with student
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      faculty_courses[4 * i + j][4 * i + j] = (j + 1);
    }
  }

  for (int k = 0; k < 3; k++) {
    for (int j = 0; j < 4; j++) {
      ug_courses[k][4 * k + j] = (j + 1);
    }
  }
}
void getAvailableTimeSlot() {
  // steps to avoid violating the hard constraints.
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 6; j++) {
      int count = timeSlots[i][j];
      int sum = 0;
      while (count > sum) {
        int timeslot = rand() % 6;
        if (available_timeslots[i][timeslot][j] == 0) {
          available_timeslots[i][timeslot][j] = 1;
          sum++;
        }
      }
    }
  }
}
void generateGraph() {
  // graph 1 : faculty and classes taught by respective faculty
  // graph 2: classes and groups of students enrolling in the course
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      faculty_courses[4 * i + j][4 * i + j] = 1;
    }
  }

  for (int k = 0; k < 3; k++) {
    for (int j = 0; j < 4; j++) {
      ug_courses[k][4 * k + j] = 1;
    }
  }
}
void generateTimetable() {
  // steps to generate timetable
  for (int s = 0; s < 6; s++) {
    for (int r = 0; r < 6; r++) {
      ug2_graph[s][r] = '0';
      ug3_graph[s][r] = '0';
      ug4_graph[s][r] = '0';
    }
  }
  for (int i = 0; i < 4; i++) {
    int max_week = 3;
    int count = 0;
    while (max_week > count) {
      int j = rand() % 6;
      int k = rand() % 6;
      if ((available_timeslots[i][j][k] == 1) && (ug2_graph[j][k] == '0')) {
        ug2_graph[j][k] = courses[i];
        count++;
      }
    }
  }

  for (int i = 4; i < 8; i++) {
    int max_week = 3;
    int count = 0;
    while (max_week > count) {
      int j = rand() % 6;
      int k = rand() % 6;
      if ((available_timeslots[i][j][k] == 1) && (ug3_graph[j][k] == '0')) {
        ug3_graph[j][k] = courses[i];
        count++;
      }
    }
  }

  for (int i = 8; i < 12; i++) {
    int max_week = 3;
    int count = 0;
    while (max_week > count) {
      int j = rand() % 6;
      int k = rand() % 6;
      if ((available_timeslots[i][j][k] == 1) && (ug4_graph[j][k] == '0')) {
        ug4_graph[j][k] = courses[i];
        count++;
      }
    }
  }
}

int main() {
  srand(time(0));
  // printf("\nThere are 12 courses offered by 12 faculties");
  // printf("\nAsssumption: Each faculty can teach only 1 courses");
  // printf("\nAssumption: There are 180 students and they are equally divided "
  //        "into 3 ug groups");
  // printf("\nAssumption: Each ug can cover 4 courses");
  // printf("\nAssumption: There are 6 classrooms");
  // printf("\nAssumption: There are 6 time slots a day and total of 36 timeslots "
  //        "a week");
  // printf("\nEnter the number of faculty, courses, students, classrooms etc.");
  // printf("\nAssumption: Consider weekdays as 1,2,3,4,5,6");
  // printf("\nAssumption: Room numbers available are 101,102,103,104,105,106");
  // printf("\nAssumption: Time slots available are 1,2,3,4,5,6 for a day.\n");
  getData();
  printf("\nEnter the number of students enrolled for each course\n");
  getStudentEnrollment();
  printf("\nEnter the courses offered by each faculty\n");
  getCourseOffered();
  printf("\nEnter the initial time slot for each faculty\n");
  getInitialTimeSlot();
  generateGraph();
  ColorEdges();
  printf("\n Coloured Faculty courses graph\n");
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++) {
      if (j == 11) {
        printf("%d\n", faculty_courses[i][j]);
      } else {
        printf("%d ", faculty_courses[i][j]);
      }
    }
  }
  printf("\nColoured ug courses graph\n");
  for (int k = 0; k < 3; k++) {
    for (int l = 0; l < 12; l++) {
      if (l == 11) {
        printf("%d\n", ug_courses[k][l]);
      } else {
        printf("%d ", ug_courses[k][l]);
      }
    }
  }
  getAvailableTimeSlot();
  for (int i = 0; i < 12; i++) {
    printf("\nAvailable time slots for faculty-%d\n", (i + 1));
    for (int j = 0; j < 6; j++) {
      for (int k = 0; k < 6; k++) {
        if (k != 5) {
          printf("%d ", available_timeslots[i][j][k]);
        } else {
          printf("%d\n", available_timeslots[i][j][k]);
        }
      }
    }
  }
  course_classroom[0] = 101;
  course_classroom[1] = 101;
  course_classroom[2] = 102;
  course_classroom[3] = 102;
  course_classroom[4] = 103;
  course_classroom[5] = 103;
  course_classroom[6] = 104;
  course_classroom[7] = 104;
  course_classroom[8] = 105;
  course_classroom[9] = 105;
  course_classroom[10] = 106;
  course_classroom[11] = 106;
  generateTimetable();
  for (int i = 0; i < 3; i++) {
    if (i == 0) {
      printf("\nUG-%d generated timetable\n", 2);
      printf("  mon  tue  wed  thu  fri  sat \n");
      for (int j = 0; j < 6; j++) {
        if (j == 3) {
          printf("  ------------LUNCH------------\n");
        }
        for (int k = 0; k < 6; k++) {
          if (k != 5) {
            printf("  %c  ", ug2_graph[j][k]);
          } else {
            printf("  %c\n", ug2_graph[j][k]);
          }
        }
      }
    } else if (/* condition */ i == 1) {
      printf("\nUG-%d generated timetable\n", 3);
      printf("  mon  tue  wed  thu  fri  sat \n");
      for (int j = 0; j < 6; j++) {
        if (j == 3) {
          printf("  ------------LUNCH------------\n");
        }
        for (int k = 0; k < 6; k++) {
          if (k != 5) {
            printf("  %c  ", ug3_graph[j][k]);
          } else {
            printf("  %c\n", ug3_graph[j][k]);
          }
        }
      }
    } else {
      printf("\nUG-%d generated timetable\n", 4);
      printf("  mon  tue  wed  thu  fri  sat \n");
      for (int j = 0; j < 6; j++) {
        if (j == 3) {
          printf("  ------------LUNCH------------\n");
        }
        for (int k = 0; k < 6; k++) {
          if (k != 5) {
            printf("  %c  ", ug4_graph[j][k]);
          } else {
            printf("  %c\n", ug4_graph[j][k]);
          }
        }
      }
    }
  }
  printf("\nROOMS ALLOTMENT:\n");
  for (int i = 0; i < 12; i++) {
    printf("\nCourse-%c is offered in room-%d\n", courses[i],
           course_classroom[i]);
  }
}
