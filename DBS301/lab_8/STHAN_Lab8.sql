CREATE TABLE tblCourse (
    CourseID Number(38) PRIMARY KEY,
    CourseCode Text(6)
    CONSTRAINT check_CourseID CHECK (CourseID > 0)
);

CREATE TABLE tblStudent (
    studentID Number(38) PRIMARY KEY,
    StudentNumber Text(11),
    StudentFname Text(20),
    StudentLname Text(20)
);

CREATE TABLE tblInstructor (
    InstructorID Number(38) PRIMARY KEY,
    InstructorNumber Text(15),
    InstructorFname Text(25),
    InstructorLname Text(25)
);

CREATE TABLE tblSemester (
    SemesterID Number(38) PRIMARY KEY,
    SemesterCode Text(11),
    SemesterYear Number(4),
    SemesterSeason Text (6)
);

CREATE TABLE tblCourseDetail (
    CourseID Number(38),
    SudentID Number(38),
    SemesterID Number(38),
    InstructorID Number(38),
    CourseGrade Text(2),
    CourseFinalGrade Number(5, 2)
);