CREATE TABLE tblCourse (
    CourseID Number(38) PRIMARY KEY,
    CourseCode Text(6) NOT NULL,
    CONSTRAINT unique_CourseCode UNIQUE(CourseCode)
);

CREATE TABLE tblStudent (
    studentID Number(38) PRIMARY KEY,
    StudentNumber Text(11) NOT NULL,
    StudentFname Text(20),
    StudentLname Text(20) NOT NULL,
    CONSTRAINT studentID_check CHECK (studentID > 0),
    CONSTRAINT unique_studentNumber UNIQUE (StudentNumber)
);

CREATE TABLE tblInstructor (
    InstructorID Number(38) PRIMARY KEY,
    InstructorNumber Text(15) NOT NULL,
    InstructorFname Text(25),
    InstructorLname Text(25) NOT NULL,
    CONSTRAINT CHECK (InstructorID > 0),
    CONSTRAINT UNIQUE (InstructorNumber)
);

CREATE TABLE tblSemester (
    SemesterID Number(38) PRIMARY KEY,
    SemesterCode Text(11) NOT NULL,
    SemesterYear Number(4) NOT NULL,
    SemesterSeason Text (6) NOT NULL,
    CONSTRAINT CHECK (SemesterID > 0),
    CONSTRAINT UNIQUE (SemesterCode),
    CONSTRAINT CHECK (SemesterYear > 2000),
    CONSTRAINT UNIQUE (SemesterYear),
    CONSTRAINT CHECK (SemesterSeason IN ('Fall', 'Winter', 'Summer'))
);

CREATE TABLE tblCourseDetail (
    CourseID Number(38),
    StudentID Number(38),
    SemesterID Number(38),
    InstructorID Number(38),
    CourseGrade Text(2) NOT NULL,
    CourseFinalGrade Number(5, 2) NOT NULL,
    PRIMARY KEY (CourseID, StudentID, SemesterID),
    FOREIGN KEY (CourseID) REFERENCES tblCourse(CourseID),
    FOREIGN KEY (StudentID) REFERENCES tblStudent(StudentID),
    FOREIGN KEY (SemesterID) REFERENCES tblSemester(SemesterID),
    FOREIGN KEY (InstructorID) REFERENCES tblInstructor(InstructorID),
    CONSTRAINT grade_letter CHECK (CourseGrade IN ('F', 'D', 'D+', 'C', 'C+', 'B', 'B+', 'A', 'A+')),
    CONSTRAINT CHECK (CourseFinalGrade BETWEEN 0 AND 100)
);