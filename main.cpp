#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Course;
class Student;
class Teacher;

class Student {
private:
    string studentID;
    string name;
    string email;
    vector<string> coursesEnrolled;

public:
    Student() {}
    Student(string id, string n, string e) : studentID(id), name(n), email(e) {}

    string getStudentID() const { return studentID; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    vector<string> getCoursesEnrolled() const { return coursesEnrolled; }

    void setStudentID(string id) { studentID = id; }
    void setName(string n) { name = n; }
    void setEmail(string e) { email = e; }

    bool enrollCourse(const string& courseCode) {
        bool alreadyEnrolled = false;
        for (size_t i = 0; i < coursesEnrolled.size(); ++i) {
            if (coursesEnrolled[i] == courseCode) {
                alreadyEnrolled = true;
                break;
            }
        }
        if (alreadyEnrolled) {
            cout << "Student is already enrolled in course: " << courseCode << endl;
            return false;
        }
        coursesEnrolled.push_back(courseCode);
        return true;
    }

    bool dropCourse(const string& courseCode) {
        for (size_t i = 0; i < coursesEnrolled.size(); ++i) {
            if (coursesEnrolled[i] == courseCode) {
                coursesEnrolled.erase(coursesEnrolled.begin() + i);
                return true;
            }
        }
        return false;
    }

    void viewCourses() const {
        cout << "\n--- Courses Enrolled by " << name << " ---" << endl;
        if (coursesEnrolled.empty()) {
            cout << "No courses enrolled." << endl;
        } else {
            for (const string& course : coursesEnrolled) {
                cout << "- " << course << endl;
            }
        }
    }

    string toFileString() const {
        string coursesList = "";
        for (size_t i = 0; i < coursesEnrolled.size(); i++) {
            coursesList += coursesEnrolled[i];
            if (i < coursesEnrolled.size() - 1) coursesList += ",";
        }
        return studentID + "|" + name + "|" + email + "|" + coursesList;
    }

    void fromFileString(const string& line) {
        stringstream ss(line);
        string token;
        getline(ss, studentID, '|');
        getline(ss, name, '|');
        getline(ss, email, '|');
        string coursesStr;
        getline(ss, coursesStr, '|');
        coursesEnrolled.clear();
        if (!coursesStr.empty()) {
            stringstream courseStream(coursesStr);
            string course;
            while (getline(courseStream, course, ',')) {
                coursesEnrolled.push_back(course);
            }
        }
    }
};

class Teacher {
private:
    string teacherID;
    string name;
    string email;
    vector<string> coursesTaught;

public:
    Teacher() {}
    Teacher(string id, string n, string e) : teacherID(id), name(n), email(e) {}

    string getTeacherID() const { return teacherID; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    vector<string> getCoursesTaught() const { return coursesTaught; }

    void setTeacherID(string id) { teacherID = id; }
    void setName(string n) { name = n; }
    void setEmail(string e) { email = e; }

    bool assignCourse(const string& courseCode) {
        bool alreadyAssigned = false;
        for (size_t i = 0; i < coursesTaught.size(); ++i) {
            if (coursesTaught[i] == courseCode) {
                alreadyAssigned = true;
                break;
            }
        }
        if (alreadyAssigned) {
            cout << "Teacher is already assigned to course: " << courseCode << endl;
            return false;
        }
        coursesTaught.push_back(courseCode);
        return true;
    }

    bool removeCourse(const string& courseCode) {
        for (size_t i = 0; i < coursesTaught.size(); ++i) {
            if (coursesTaught[i] == courseCode) {
                coursesTaught.erase(coursesTaught.begin() + i);
                return true;
            }
        }
        return false;
    }

    void viewCourses() const {
        cout << "\n--- Courses Taught by " << name << " ---" << endl;
        if (coursesTaught.empty()) {
            cout << "No courses assigned." << endl;
        } else {
            for (const string& course : coursesTaught) {
                cout << "- " << course << endl;
            }
        }
    }

    string toFileString() const {
        string coursesList = "";
        for (size_t i = 0; i < coursesTaught.size(); i++) {
            coursesList += coursesTaught[i];
            if (i < coursesTaught.size() - 1) coursesList += ",";
        }
        return teacherID + "|" + name + "|" + email + "|" + coursesList;
    }

    void fromFileString(const string& line) {
        stringstream ss(line);
        string token;
        getline(ss, teacherID, '|');
        getline(ss, name, '|');
        getline(ss, email, '|');
        string coursesStr;
        getline(ss, coursesStr, '|');
        coursesTaught.clear();
        if (!coursesStr.empty()) {
            stringstream courseStream(coursesStr);
            string course;
            while (getline(courseStream, course, ',')) {
                coursesTaught.push_back(course);
            }
        }
    }
};

class Course {
private:
    string courseCode;
    string courseName;
    string teacherID;
    vector<string> studentsEnrolled;
    int maxCapacity;

public:
    Course() {}
    Course(string code, string name, string tID, int capacity = 30)
        : courseCode(code), courseName(name), teacherID(tID), maxCapacity(capacity) {}

    string getCourseCode() const { return courseCode; }
    string getCourseName() const { return courseName; }
    string getTeacherID() const { return teacherID; }
    vector<string> getStudentsEnrolled() const { return studentsEnrolled; }
    int getMaxCapacity() const { return maxCapacity; }
    int getCurrentEnrollment() const { return studentsEnrolled.size(); }

    void setCourseCode(string code) { courseCode = code; }
    void setCourseName(string name) { courseName = name; }
    void setTeacherID(string tID) { teacherID = tID; }
    void setMaxCapacity(int capacity) { maxCapacity = capacity; }

    bool addStudent(const string& studentID) {
        if (studentsEnrolled.size() >= maxCapacity) {
            cout << "Course " << courseCode << " is full! Cannot enroll more students." << endl;
            return false;
        }
        bool alreadyEnrolled = false;
        for (size_t i = 0; i < studentsEnrolled.size(); ++i) {
            if (studentsEnrolled[i] == studentID) {
                alreadyEnrolled = true;
                break;
            }
        }
        if (alreadyEnrolled) {
            cout << "Student " << studentID << " is already enrolled in course " << courseCode << endl;
            return false;
        }
        studentsEnrolled.push_back(studentID);
        return true;
    }

    bool removeStudent(const string& studentID) {
        for (size_t i = 0; i < studentsEnrolled.size(); ++i) {
            if (studentsEnrolled[i] == studentID) {
                studentsEnrolled.erase(studentsEnrolled.begin() + i);
                return true;
            }
        }
        return false;
    }

    void viewStudents() const {
        cout << "\n--- Students Enrolled in " << courseCode << " (" << courseName << ") ---" << endl;
        cout << "Enrollment: " << studentsEnrolled.size() << "/" << maxCapacity << endl;
        if (studentsEnrolled.empty()) {
            cout << "No students enrolled." << endl;
        } else {
            for (const string& studentID : studentsEnrolled) {
                cout << "- " << studentID << endl;
            }
        }
    }

    string toFileString() const {
        string studentsList = "";
        for (size_t i = 0; i < studentsEnrolled.size(); i++) {
            studentsList += studentsEnrolled[i];
            if (i < studentsEnrolled.size() - 1) studentsList += ",";
        }
        return courseCode + "|" + courseName + "|" + teacherID + "|" + to_string(maxCapacity) + "|" + studentsList;
    }

    void fromFileString(const string& line) {
        stringstream ss(line);
        string token;
        getline(ss, courseCode, '|');
        getline(ss, courseName, '|');
        getline(ss, teacherID, '|');
        string capacityStr;
        getline(ss, capacityStr, '|');
        maxCapacity = stoi(capacityStr);
        string studentsStr;
        getline(ss, studentsStr, '|');
        studentsEnrolled.clear();
        if (!studentsStr.empty()) {
            stringstream studentStream(studentsStr);
            string student;
            while (getline(studentStream, student, ',')) {
                studentsEnrolled.push_back(student);
            }
        }
    }
};

class UniversityManagementSystem {
private:
    vector<Student> students;
    vector<Teacher> teachers;
    vector<Course> courses;

    const string STUDENTS_FILE = "students.txt";
    const string TEACHERS_FILE = "teachers.txt";
    const string COURSES_FILE = "courses.txt";

public:
    UniversityManagementSystem() {
        loadData();
    }

    ~UniversityManagementSystem() {
        saveData();
    }

    void saveData() {
        ofstream studentFile(STUDENTS_FILE);
        if (studentFile.is_open()) {
            for (const Student& student : students) {
                studentFile << student.toFileString() << endl;
            }
            studentFile.close();
        }
        ofstream teacherFile(TEACHERS_FILE);
        if (teacherFile.is_open()) {
            for (const Teacher& teacher : teachers) {
                teacherFile << teacher.toFileString() << endl;
            }
            teacherFile.close();
        }
        ofstream courseFile(COURSES_FILE);
        if (courseFile.is_open()) {
            for (const Course& course : courses) {
                courseFile << course.toFileString() << endl;
            }
            courseFile.close();
        }
    }

    void loadData() {
        ifstream studentFile(STUDENTS_FILE);
        if (studentFile.is_open()) {
            string line;
            while (getline(studentFile, line) && !line.empty()) {
                Student student;
                student.fromFileString(line);
                students.push_back(student);
            }
            studentFile.close();
        }
        ifstream teacherFile(TEACHERS_FILE);
        if (teacherFile.is_open()) {
            string line;
            while (getline(teacherFile, line) && !line.empty()) {
                Teacher teacher;
                teacher.fromFileString(line);
                teachers.push_back(teacher);
            }
            teacherFile.close();
        }
        ifstream courseFile(COURSES_FILE);
        if (courseFile.is_open()) {
            string line;
            while (getline(courseFile, line) && !line.empty()) {
                Course course;
                course.fromFileString(line);
                courses.push_back(course);
            }
            courseFile.close();
        }
    }

    void addStudent() {
        string id, name, email;
        cout << "\n--- Add New Student ---" << endl;
        cout << "Enter Student ID: ";
        cin >> id;
        for (const Student& s : students) {
            if (s.getStudentID() == id) {
                cout << "Student with ID " << id << " already exists!" << endl;
                return;
            }
        }
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Student Email: ";
        cin >> email;
        students.push_back(Student(id, name, email));
        cout << "Student added successfully!" << endl;
    }

    void addTeacher() {
        string id, name, email;
        cout << "\n--- Add New Teacher ---" << endl;
        cout << "Enter Teacher ID: ";
        cin >> id;
        for (const Teacher& t : teachers) {
            if (t.getTeacherID() == id) {
                cout << "Teacher with ID " << id << " already exists!" << endl;
                return;
            }
        }
        cin.ignore();
        cout << "Enter Teacher Name: ";
        getline(cin, name);
        cout << "Enter Teacher Email: ";
        cin >> email;
        teachers.push_back(Teacher(id, name, email));
        cout << "Teacher added successfully!" << endl;
    }

    void addCourse() {
        string code, name, teacherID;
        int capacity;
        cout << "\n--- Add New Course ---" << endl;
        cout << "Enter Course Code: ";
        cin >> code;
        for (const Course& c : courses) {
            if (c.getCourseCode() == code) {
                cout << "Course with code " << code << " already exists!" << endl;
                return;
            }
        }
        cin.ignore();
        cout << "Enter Course Name: ";
        getline(cin, name);
        cout << "Available Teachers:" << endl;
        for (const Teacher& t : teachers) {
            cout << "- " << t.getTeacherID() << " (" << t.getName() << ")" << endl;
        }
        cout << "Enter Teacher ID: ";
        cin >> teacherID;
        bool teacherFound = false;
        for (Teacher& t : teachers) {
            if (t.getTeacherID() == teacherID) {
                teacherFound = true;
                t.assignCourse(code);
                break;
            }
        }
        if (!teacherFound) {
            cout << "Teacher not found!" << endl;
            return;
        }
        cout << "Enter Maximum Capacity (default 30): ";
        cin >> capacity;
        courses.push_back(Course(code, name, teacherID, capacity));
        cout << "Course added successfully!" << endl;
    }

    void enrollStudentInCourse() {
        string studentID, courseCode;
        cout << "\n--- Enroll Student in Course ---" << endl;
        cout << "Enter Student ID: ";
        cin >> studentID;
        Student* student = nullptr;
        for (Student& s : students) {
            if (s.getStudentID() == studentID) {
                student = &s;
                break;
            }
        }
        if (!student) {
            cout << "Student not found!" << endl;
            return;
        }
        cout << "Available Courses:" << endl;
        for (const Course& c : courses) {
            cout << "- " << c.getCourseCode() << " (" << c.getCourseName() << ") - "
                 << c.getCurrentEnrollment() << "/" << c.getMaxCapacity() << " enrolled" << endl;
        }
        cout << "Enter Course Code: ";
        cin >> courseCode;
        Course* course = nullptr;
        for (Course& c : courses) {
            if (c.getCourseCode() == courseCode) {
                course = &c;
                break;
            }
        }
        if (!course) {
            cout << "Course not found!" << endl;
            return;
        }
        if (course->addStudent(studentID) && student->enrollCourse(courseCode)) {
            cout << "Student " << studentID << " enrolled in course " << courseCode << " successfully!" << endl;
        } else {
            cout << "Enrollment failed!" << endl;
        }
    }

    void viewStudentCourses() {
        string studentID;
        cout << "\n--- View Student Courses ---" << endl;
        cout << "Enter Student ID: ";
        cin >> studentID;
        for (const Student& s : students) {
            if (s.getStudentID() == studentID) {
                s.viewCourses();
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    void viewCourseStudents() {
        string courseCode;
        cout << "\n--- View Course Students ---" << endl;
        cout << "Enter Course Code: ";
        cin >> courseCode;
        for (const Course& c : courses) {
            if (c.getCourseCode() == courseCode) {
                c.viewStudents();
                return;
            }
        }
        cout << "Course not found!" << endl;
    }

    void viewAllStudents() {
        cout << "\n--- All Students ---" << endl;
        if (students.empty()) {
            cout << "No students found." << endl;
            return;
        }
        cout << setw(12) << "Student ID" << setw(20) << "Name" << setw(25) << "Email" << setw(15) << "Courses" << endl;
        cout << string(72, '-') << endl;
        for (const Student& s : students) {
            cout << setw(12) << s.getStudentID()
                 << setw(20) << s.getName()
                 << setw(25) << s.getEmail()
                 << setw(15) << s.getCoursesEnrolled().size() << endl;
        }
    }

    void viewAllCourses() {
        cout << "\n--- All Courses ---" << endl;
        if (courses.empty()) {
            cout << "No courses found." << endl;
            return;
        }
        cout << setw(12) << "Course Code" << setw(20) << "Course Name" << setw(12) << "Teacher ID"
             << setw(15) << "Enrolled/Max" << endl;
        cout << string(59, '-') << endl;
        for (const Course& c : courses) {
            cout << setw(12) << c.getCourseCode()
                 << setw(20) << c.getCourseName()
                 << setw(12) << c.getTeacherID()
                 << setw(15) << (to_string(c.getCurrentEnrollment()) + "/" + to_string(c.getMaxCapacity())) << endl;
        }
    }

    void displayMenu() {
        cout << "\n=== University Management System ===" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Add Teacher" << endl;
        cout << "3. Add Course" << endl;
        cout << "4. Enroll Student in Course" << endl;
        cout << "5. View Student's Courses" << endl;
        cout << "6. View Course Students" << endl;
        cout << "7. View All Students" << endl;
        cout << "8. View All Courses" << endl;
        cout << "9. Save and Exit" << endl;
        cout << "Enter your choice: ";
    }

    void run() {
        int choice;
        cout << "Welcome to University Management System!" << endl;
        cout << "Data loaded from files successfully." << endl;
        do {
            displayMenu();
            cin >> choice;
            switch (choice) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    addTeacher();
                    break;
                case 3:
                    addCourse();
                    break;
                case 4:
                    enrollStudentInCourse();
                    break;
                case 5:
                    viewStudentCourses();
                    break;
                case 6:
                    viewCourseStudents();
                    break;
                case 7:
                    viewAllStudents();
                    break;
                case 8:
                    viewAllCourses();
                    break;
                case 9:
                    saveData();
                    cout << "Data saved successfully. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice! Please try again." << endl;
            }
        } while (choice != 9);
    }
};

int main() {
    UniversityManagementSystem ums;
    ums.run();
    return 0;
}