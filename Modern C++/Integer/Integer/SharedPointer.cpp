#include "Integer.h"
#include "GlobalDefines.h"
#include <memory>

class Project {
	std::string m_projectName{ 0 };
public:
	void SetName(const std::string& name) {
		m_projectName = name;
	}
	const std::string& GetName() const {
		return m_projectName;
	}

	void DisplayInfo()const {
		std::cout << "Project Name : [" << GetName() << "]"<< std::endl;
	}
};

class Employee {
	std::shared_ptr<Project> m_project{ nullptr };
public:
	void SetProject(const std::shared_ptr<Project>& project) {
		m_project = project;
	}

};

#if 0
int main(int argc, char** argv)
{
	std::shared_ptr<Project> project1(new Project());	//project1 has to be shared_ptr because we are doing copy assignment, which wont work with unique_ptr
	project1->SetName("Eudyptula");
	std::unique_ptr<Employee> e1(new Employee());
	e1->SetProject(project1);

	std::unique_ptr<Employee> e2(new Employee());
	e2->SetProject(project1);

	project1->DisplayInfo();
	std::cout << "Project1 Ref count: " << project1.use_count() << std::endl;
	//std::cout << "e1 Ref count: " << e1.use_count() << std::endl;

	e1.reset();
	std::cout << "Project1 Ref count: " << project1.use_count() << std::endl;


	return 0;
}
#endif