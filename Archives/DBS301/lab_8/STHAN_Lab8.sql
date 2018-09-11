-- Shweyin Than 115675175 DBS301 Lab 8
-- 7/28/2018

-- Question 1 --

CREATE TABLE tblCourse (
    CourseID Number (38),
    CourseCode VARCHAR(6) NOT NULL,
    PRIMARY KEY (CourseID),
    UNIQUE (CourseCode)
);

CREATE TABLE tblStudent (
    studentID Number(38) PRIMARY KEY,
    StudentNumber VARCHAR(11) NOT NULL,
    StudentFname VARCHAR(20),
    StudentLname VARCHAR(20) NOT NULL,
    CONSTRAINT studentID_check CHECK (studentID > 0),
    UNIQUE (StudentNumber)
);

CREATE TABLE tblInstructor (
    InstructorID Number(38) PRIMARY KEY,
    InstructorNumber VARCHAR(15) NOT NULL,
    InstructorFname VARCHAR(25),
    InstructorLname VARCHAR(25) NOT NULL,
    CONSTRAINT instructorID_check CHECK (InstructorID > 0),
    UNIQUE (InstructorNumber)
);

CREATE TABLE tblSemester (
    SemesterID Number(38) PRIMARY KEY,
    SemesterCode VARCHAR(11) NOT NULL,
    SemesterYear Number(4) NOT NULL,
    SemesterSeason VARCHAR (6) NOT NULL,
    CONSTRAINT semesterID_check CHECK (SemesterID > 0),
    UNIQUE (SemesterCode),
    CONSTRAINT semesterYear_check CHECK (SemesterYear > 2000),
    UNIQUE (SemesterYear),
    CONSTRAINT semesterSeason_check CHECK (SemesterSeason IN ('Fall', 'Winter', 'Summer'))
);

CREATE TABLE tblCourseDetail (
    CourseID Number(38),
    StudentID Number(38),
    SemesterID Number(38),
    InstructorID Number(38),
    CourseGrade VARCHAR(2) NOT NULL,
    CourseFinalGrade Number(5, 2) NOT NULL,
    PRIMARY KEY (CourseID, StudentID, SemesterID),
    FOREIGN KEY (CourseID) REFERENCES tblCourse(CourseID),
    FOREIGN KEY (StudentID) REFERENCES tblStudent(StudentID),
    FOREIGN KEY (SemesterID) REFERENCES tblSemester(SemesterID),
    FOREIGN KEY (InstructorID) REFERENCES tblInstructor(InstructorID),
    CONSTRAINT grade_letter CHECK (CourseGrade IN ('F', 'D', 'D+', 'C', 'C+', 'B', 'B+', 'A', 'A+')),
    CONSTRAINT finalGrade_check CHECK (CourseFinalGrade BETWEEN 0 AND 100)
);

-- Question 2 --

ALTER TABLE tblCourse ADD CourseDesc VARCHAR(35) NOT NULL;

-- Question 3 --

ALTER TABLE tblSemester DROP UNIQUE (SemesterYear);

-- Question 4 --

ALTER TABLE tblCourseDetail RENAME COLUMN CourseGrade TO CourseLetterGrade;

-- Question 5 --

ALTER TABLE tblStudent MODIFY
(
    StudentFname VARCHAR(25),
    StudentLname VARCHAR(25)
);