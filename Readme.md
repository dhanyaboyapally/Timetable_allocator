Description of Code

I took all the arrays as global objects to no need to pass arguments to functions.

-------------------Functions-----------------------

getData(): Here I am getting the data of total number of faculty, course, students, classroom.

getStudentEnrollment(): Here student enrollment is going on means like assigning number of students per
                        each ug.

getCourseOffered(): Here the input of course names are taken into (char data type) courses array.

getInitialTimeSlot(): Here the input is taken for number of hours the faculty is free in that week and 
                      this input helps in getAvailableTimeSlot() function. 

getAvailableTimeSlots(): Here based on getTimeSlot() function we are assigning the each timeslot a value
                         of 1 or 0 . If the the faculty is free during the a timeslot then value 1 is 
                         assigned. Here we are assigning timeslots value randomly so that we get 
                         different timetables for each run.

colorEdges(): Here we are coloring the edges based on faculty and courses and student and courses graph
              No two edges have same color and all the colors are assigned with different colors.
              For my convenience i took 4 colors.

generateGraph(): Here we are making an array of faculty and courses taught by respective faculty
                 based on the coloring edges. And doing same with each ug and course offered or assigned

generateTimetable(): Here we are matching the two arrays faculty_courses and ug_courses so that the 
                     common timeslots will be alloted in the timetable with course as common point taken.

----------------------Constraints--------------------------

HardConstraints: no two ugs have same course on sameslot.
                 No two ug have class in same classroom in a timeslot.
                 No faculty teaches two courses at same time
                 No student is present in different sections.
                 No two ugs have same course.

SoftConstraints: Lecturer should have a min of 1 hour free slot
                 One subject shouldn't be taught for more than 2 ug's
                 Timetable is random so no two days have same schedule.
                 Mostly every ug has 2 classes a day

----------------------Input format---------------------------

INPUT datatype for name of faculty and course is char so a single char is req

input datatype for classroom is int so input number

input format for timeslot is %d %d %d %d %d %d all int and should be less than or equal to 6.
