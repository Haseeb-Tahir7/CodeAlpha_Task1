
#include <iostream>
#include <vector>
using namespace std;

class Course {
public:
    float grade;
    int credit;

    Course(float g, int c) {
        grade = g;
        credit = c;
    }
};

class Student {
private:
    vector<Course> courses;

public:
    void addCourse(float grade, int credit) {
        courses.push_back(Course(grade, credit));
    }

    float calculateCGPA() {
        float totalPoints = 0;
        int totalCredits = 0;
        for (Course c : courses) {
            totalPoints += c.grade * c.credit;
            totalCredits += c.credit;
        }
        if (totalCredits == 0) return 0;
        return totalPoints / totalCredits;
    }

    void displayCourses() {
        cout << "Courses Entered:\n";
        for (int i = 0; i < courses.size(); i++) {
            cout << "Course " << i+1 << ": Grade = " << courses[i].grade
                 << ", Credit Hours = " << courses[i].credit << endl;
        }
    }
};

int main() {
    Student s;
    int n;
    cout << "Enter number of courses: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        float grade;
        int credit;
        cout << "Enter grade and credit hours for course " << i+1 << ": ";
        cin >> grade >> credit;
        s.addCourse(grade, credit);
    }
    s.displayCourses();
    cout << "CGPA: " << s.calculateCGPA() << endl;
    return 0;
}
