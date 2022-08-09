#include "GlobalDefines.h"
class Employee;
class Project {
public:
	std::shared_ptr<Employee> m_emp;
	Project()
	{
		PrintFunctionSignature();
	}
	
	~Project()
	{
		PrintFunctionSignature();
	}
};

class Employee {
public:
	//std::shared_ptr<Project> m_project;	//using shared_ptr for both objects creates Circular Reference
	std::weak_ptr<Project> m_project;	//using weak_ptr for anyone of the objects solves Circular Reference
	Employee()
	{
		PrintFunctionSignature();
	}

	~Employee()
	{
		PrintFunctionSignature();
	}
};
#if 0
int main(int argc, char** argv)
{
	std::shared_ptr<Employee> emp1(new Employee());
	std::shared_ptr<Project> pro1(new Project());
	emp1->m_project = pro1;
	pro1->m_emp = emp1;
	return 0;
}
#endif