# University Management System

**Object Oriented Programming Lab - Open-Ended Task**  
**Bahria University, Islamabad - Department of Computer Science**  
**BS(AI), 2(A) - Spring 2025**

A comprehensive console-based University Management System built in C++ that allows administrators to manage students, teachers, and courses with persistent data storage using file handling.

## 📋 Lab Requirements

This project implements the **University Management System with File Handling** as specified in the OOP Open-Ended Lab assignment with the following requirements:

### Required Classes & Attributes
- **Student**: `studentID`, `name`, `email`, `coursesEnrolled` (list)
- **Teacher**: `teacherID`, `name`, `email`, `coursesTaught` (list)  
- **Course**: `courseCode`, `courseName`, `teacher`, `studentsEnrolled` (list)

### Core Functionality Implementation
- ✅ **Enrollment System**: Students can enroll in courses with capacity validation
- ✅ **Course Management**: Each course has maximum capacity enforcement
- ✅ **File Handling**: Persistent data storage using structured text files
- ✅ **Data Structures**: Utilizes vectors for managing collections
- ✅ **User Interface**: User-friendly console interface for navigation

## 🚀 Features

### Student Management
- Add new students with unique ID validation
- Enroll students in available courses
- View individual student course enrollments
- Prevent duplicate course enrollments

### Teacher Management
- Register teachers with unique identification
- Assign courses to teachers
- View teacher course assignments

### Course Management
- Create courses with capacity limits
- Track enrollment statistics
- Prevent over-enrollment beyond capacity
- Display enrolled students per course

### Data Persistence
- Automatic save/load functionality using text files
- Structured data format for easy parsing
- Session continuity - resume activities seamlessly

## ⚙️ System Requirements

- **Compiler**: C++11 or later
- **Operating System**: Windows, macOS, or Linux
- **Dependencies**: Standard C++ Library only

## 📦 Installation & Setup

1. **Clone the repository**
   ```bash
   git clone https://github.com/yourusername/open-ended-lab.git
   cd open-ended-lab
   ```

2. **Compile the program**
   ```bash
   g++ -std=c++11 main.cpp -o university_system
   ```

3. **Run the application**
   ```bash
   ./university_system
   ```

## 📁 Repository Structure

```
open-ended-lab/
├── main.cpp              # Main source code
├── students.txt          # Student data storage (auto-generated)
├── teachers.txt          # Teacher data storage (auto-generated)
├── courses.txt           # Course data storage (auto-generated)
└── README.md            # This file
```

## Usage Guide

### Main Menu Options

1. **Add Student** - Register a new student with ID, name, and email
2. **Add Teacher** - Register a new teacher with ID, name, and email  
3. **Add Course** - Create a new course with code, name, assigned teacher, and capacity
4. **Enroll Student in Course** - Enroll existing students in available courses
5. **View Student's Courses** - Display all courses a specific student is enrolled in
6. **View Course Students** - Display all students enrolled in a specific course
7. **View All Students** - List all registered students with summary information
8. **View All Courses** - List all available courses with enrollment statistics
9. **Save and Exit** - Save all data and close the application

### Sample Workflow

1. **Add Teachers First**: Create teacher profiles before adding courses
2. **Add Courses**: Create courses and assign them to existing teachers
3. **Add Students**: Register student accounts
4. **Enroll Students**: Enroll students in available courses
5. **View Reports**: Use view options to check enrollment status

## Data Storage Format

The system uses pipe-delimited text files for data persistence:

### Students (`students.txt`)
```
StudentID|Name|Email|Course1,Course2,Course3
```

### Teachers (`teachers.txt`)
```
TeacherID|Name|Email|Course1,Course2,Course3
```

### Courses (`courses.txt`)
```
CourseCode|CourseName|TeacherID|MaxCapacity|Student1,Student2,Student3
```

## Class Architecture

### Core Classes

- **`Student`**: Manages student data and course enrollments
- **`Teacher`**: Handles teacher information and course assignments
- **`Course`**: Manages course details, capacity, and enrolled students
- **`UniversityManagementSystem`**: Main controller class handling all operations

### Key Design Features

- **Encapsulation**: Private data members with public getter/setter methods
- **Data Validation**: Prevents duplicate IDs and enrollments
- **Capacity Management**: Enforces course enrollment limits
- **File I/O**: Automatic persistence with structured data format

## Error Handling

The system includes comprehensive error handling for:
- Duplicate student/teacher/course IDs
- Invalid enrollment attempts
- Course capacity violations
- File I/O operations
- Invalid user input

## Future Enhancements

- [ ] Grade management system
- [ ] Search and filter functionality
- [ ] Student withdrawal from courses
- [ ] Teacher course reassignment
- [ ] Backup and restore features
- [ ] GUI interface
- [ ] Database integration
- [ ] Report generation (PDF/CSV export)

## Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/new-feature`)
3. Commit your changes (`git commit -am 'Add new feature'`)
4. Push to the branch (`git push origin feature/new-feature`)
5. Create a Pull Request

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 📝 Lab Submission Notes

### Group Collaboration Requirements
- **Maximum Group Size**: 2 students
- **GitHub Collaboration**: Both members must contribute with equal commits
- **Documentation**: Journal must include public GitHub repository link with screenshots

### Time Allocation
- **Development Time**: 1 hour 30 minutes
- **Evaluation Time**: 30 minutes
- **Total Weightage**: 6%

### Expected Deliverables
- ✅ Functional university management system
- ✅ User-friendly console interface
- ✅ File handling implementation for data persistence
- ✅ Session continuity for seamless user experience
- ✅ GitHub repository with proper collaboration history

## 👥 Contributors

- **[Student 1 Name]** - [GitHub: @username1]
- **[Student 2 Name]** - [GitHub: @username2]

## 🎓 Academic Information

- **Course**: Object Oriented Programming Lab
- **Program**: BS(AI), Section 2(A)
- **Semester**: Spring 2025
- **University**: Bahria University, Islamabad
- **Department**: Computer Science

## 📄 License

This project is submitted as part of academic coursework at Bahria University.

---

**Academic Integrity Note**: This project is developed as part of the OOP Lab Open-Ended Task and follows all university guidelines for academic collaboration and submission.
