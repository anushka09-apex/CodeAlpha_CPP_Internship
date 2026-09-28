#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

struct Course {
    string name;
    char grade;
    double creditHours;
    double gradePoint;
};

double getGradePoint(char grade) {
    switch (grade) {
        case 'A':
        case 'a':
            return 10.0;

        case 'B':
        case 'b':
            return 8.0;

        case 'C':
        case 'c':
            return 7.0;

        case 'D':
        case 'd':
            return 6.0;

        case 'E':
        case 'e':
            return 5.0;

        case 'F':
        case 'f':
            return 0.0;

        default:
            return -1.0;
    }
}

int main() {
    int numberOfCourses;

    cout << "====================================\n";
    cout << "       CODEALPHA CGPA CALCULATOR\n";
    cout << "====================================\n\n";

    cout << "Enter number of courses: ";
    cin >> numberOfCourses;

    if (numberOfCourses <= 0) {
        cout << "Invalid number of courses.\n";
        return 0;
    }

    vector<Course> courses(numberOfCourses);

    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    for (int i = 0; i < numberOfCourses; i++) {

        cout << "\nCourse " << i + 1 << "\n";

        cout << "Enter course name: ";
        cin >> courses[i].name;

        cout << "Enter grade (A/B/C/D/E/F): ";
        cin >> courses[i].grade;

        courses[i].gradePoint = getGradePoint(courses[i].grade);

        if (courses[i].gradePoint == -1) {
            cout << "Invalid grade entered.\n";
            return 0;
        }

        cout << "Enter credit hours: ";
        cin >> courses[i].creditHours;

        if (courses[i].creditHours <= 0) {
            cout << "Invalid credit hours.\n";
            return 0;
        }

        double coursePoints =
            courses[i].gradePoint * courses[i].creditHours;

        totalGradePoints += coursePoints;
        totalCredits += courses[i].creditHours;
    }

    double cgpa = totalGradePoints / totalCredits;

    cout << "\n\n====================================\n";
    cout << "           COURSE DETAILS\n";
    cout << "====================================\n";

    cout << left
         << setw(15) << "Course"
         << setw(10) << "Grade"
         << setw(15) << "Credits"
         << setw(15) << "Grade Point"
         << endl;

    cout << "-------------------------------------------------------\n";

    for (const Course& course : courses) {
        cout << left
             << setw(15) << course.name
             << setw(10) << course.grade
             << setw(15) << course.creditHours
             << setw(15) << course.gradePoint
             << endl;
    }

    cout << "\nTotal Credit Hours: " << totalCredits << endl;

    cout << fixed << setprecision(2);
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Final CGPA: " << cgpa << endl;

    cout << "\n====================================\n";
    cout << "       CGPA CALCULATION COMPLETE\n";
    cout << "====================================\n";

    return 0;
}