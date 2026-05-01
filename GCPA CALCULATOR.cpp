#include<iostream>
#include<string>
using namespace std;
struct Courses{
	string name;
	string grade;
	float credit_hours;
	float grade_points;
	float earned_gradePoints;
};
class Student{
	public:
	int n;
	float overall_gradePoints;
	float overall_credit_hours;
	float semester_GPA;
	struct Courses *course;
	Student(){
	cout<<"Enter number of courses  taken by a Student: "<<endl;
	cin>>n;
	course=new Courses[n];
	}
	~Student(){
    delete[] course;
}
void Assign_gradePoints(int i,string grade){
	if(grade == "A+" || grade == "A"){
    	course[i].grade_points = 4.0;
	}
	else if(grade == "A-"){
    	course[i].grade_points = 3.7;
	}
	else if(grade == "B+"){
    	course[i].grade_points = 3.3;
	}
	else if(grade == "B"){
    	course[i].grade_points = 3.0;
	}
	else if(grade == "B-"){
    	course[i].grade_points = 2.7;
	}
	else if(grade == "C+"){
    	course[i].grade_points = 2.3;
	}
	else if(grade == "C"){
    	course[i].grade_points = 2.0;
	}
	else if(grade == "D"){
    	course[i].grade_points = 1.0;
	}
	else if(grade == "F"){
    	course[i].grade_points = 0.0;
	}
	else {
    	course[i].grade_points = 0.0;
	}
	
}
float earned_gradePoints(float grade_points,float credit_hours){
	return grade_points*credit_hours;	
}
float total_gradePoints(float earned_grade_points)
{
	static float sum=0.0;
	sum+=earned_grade_points;
	return sum;
	}
float total_credit_hours(float ch)
 {
  static float sum=0.0;
    sum+=ch;
    return sum;
}
float SemesterGPA(float grade_points,float credit_hours){
	semester_GPA=grade_points/credit_hours;
	return semester_GPA;

}
void displayReportCard() {
    cout << "\n\n========== REPORT CARD ==========\n";
    cout << "-----------------------------------\n";
    cout << "Subject\t\tGrade\tCredits\tGP\tEarned\n";
    cout << "-----------------------------------\n";
    
    for(int i = 0; i < n; i++) {
        cout << course[i].name << "\t\t"
             << course[i].grade << "\t"
             << course[i].credit_hours << "\t"
             << course[i].grade_points << "\t"
             << course[i].earned_gradePoints << "\n";
    }
    
    cout << "-----------------------------------\n";
    cout << "Total Credits:\t\t" << overall_credit_hours << "\n";
    cout << "Total Grade Points:\t" << overall_gradePoints << "\n";
    cout << "Semester GPA:\t\t" << semester_GPA << "\n";
    cout << "===================================\n";
}
};

int main(){
	Student S1;
	cout<<"Enter the names of the subjects: "<<endl;
	for (int i=0; i<S1.n;i++){
		cout<<"Course no: "<<i+1<<endl;
		 cin.ignore();
		cout<<"Name: ";
        getline(cin, S1.course[i].name); 		
		cout<<"Grade: ";
        getline(cin, S1.course[i].grade); 
		cout<<"Credit Hours: ";
		cin>>S1.course[i].credit_hours;	
		S1.Assign_gradePoints(i,S1.course[i].grade);
		cout<<"Grade points= "<<S1.course[i].grade_points<<endl;
		S1.course[i].earned_gradePoints=S1.earned_gradePoints(S1.course[i].grade_points,S1.course[i].credit_hours);
		cout<<"Grade Points Earned: "<<S1.course[i].earned_gradePoints<<endl;
	}
	for (int i=0;i<S1.n;i++){
		S1.overall_gradePoints=S1.total_gradePoints(S1.course[i].earned_gradePoints);
		cout<<"Total Grade Points earned: "<<S1.overall_gradePoints<<endl;
	}
	for (int i=0;i<S1.n;i++){
		S1.overall_credit_hours=S1.total_credit_hours(S1.course[i].credit_hours);
		cout<<"Total credit points earned: "<<S1.overall_credit_hours<<endl;
	}
	S1.SemesterGPA(S1.overall_gradePoints,S1.overall_credit_hours);
	S1.displayReportCard();	

}
