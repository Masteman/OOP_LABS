#include <iostream>

class Persona
{
private:
    std::string name;
    std::string login;

public:
    Persona(std::string n, std::string l)
    {
        name = n;
        login = l;
    }

    Persona()
    {
        name = "";
        login = "";
    }

    auto getName() -> std::string
    {
        return name;
    }

    void setName(std::string n)
    {
        name = n;
    }

    auto getLogin() -> std::string
    {
        return login;
    }

    void setLogin(std::string l)
    {
        login = l;
    }

    ~Persona()
    {
        std::cout << "destruction of memory (clearing (^ d ^) )" << std::endl;
    }
};

class Teacher : public Persona
{
private:
    std::string subject;

public:
    Teacher(std::string n, std::string l, std::string e) : Persona(n, l)
    {
        subject = e;
    }

    Teacher() : Persona()
    {
        subject = "";
    }

    auto getSubject() -> std::string
    {
        return subject;
    }

    void setSubject(std::string e)
    {
        subject = e;
    }

    void print()
    {
        std::cout << "Name: " << getName() << ";  Login: " << getLogin() << ";  Subject: " << getSubject() << "\n" << std::endl;
    }
};

class Head_of_faculty : public Teacher
{
private:
    std::string faculty;

public:
    Head_of_faculty(std::string n, std::string l, std::string e, std::string f) : Teacher(n, l, e)
    {
        faculty = f;
    }

    Head_of_faculty() : Teacher()
    {
        faculty = "";
    }

    auto getFaculty() -> std::string
    {
        return faculty;
    }

    void setFaculty(std::string f)
    {
        faculty = f;
    }

    void print()
    {
        std::cout << "Name: " << getName() << ";  Login: " << getLogin() << ";  Subject: " << getSubject() << ";  Faculty: " << getFaculty() << "\n" << std::endl;
    }
};

class Student : public Persona
{
private:
    std::string education_form;

public:
    Student(std::string n, std::string l, std::string e) : Persona(n, l)
    {
        education_form = e;
    }

    Student() : Persona()
    {
        education_form = "";
    }

    auto getEducation() -> std::string
    {
        return education_form;
    }

    void setEducation(std::string e)
    {
        education_form = e;
    }

    void print()
    {
        std::cout << "Persona: " << getName() << ";  Login: " << getLogin() << ";  Education Form: " << getEducation() << "\n" << std::endl;
    }
};

int main()
{
    Teacher teacher("Misura", "Karate_Covid", "DCP / Optimization of Beer Production");
    teacher.print();

    Head_of_faculty head_f("Glazunova", "Super_Dekan_3000", "System Analysis", "Faculty of Information Technology");
    head_f.print();

    Student student("Valentine", "Pepsikolniy", "Budget");
    student.print();
}