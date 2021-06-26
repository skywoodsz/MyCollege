#include <iostream>
#include <string>

#include <ros/ros.h>
#include <std_msgs/Int8.h>

#inlcude <teacher.h>
#inlcude <classmate.h>
using namespace std;


class MYCOLLEGE 
{
	public:
		MYCOLLEGE()
		{
			cout = 0;
			name = "ztl";
			
			teacher_sub_ = nh_.subscribe("/teacher",10,&MYCOLLEGE::ToGetTeacher,this);
			classmate_sub_ = nh_.subscribe("/classmate",10,&MYCOLLEGE::ToGetClassmate,this);
			cout_pub_ = nh_.advertise<std_msgs::Int8.h> ("cout",1);
			
			MyProgress();
			
		};
		~MYCOLLEGE()
		{
			
		};
		
		void MyProgress()
		{
			switch(cout)
			{
				case 0:
				   MeetInCollege();
				   break; 
				case 1:
				   DisappointedInCollege()
				   break;
				case 2:
				   GetAwayFromCollege();
				   break;
				case 3:
				   cout = 0;
				   cout_pub_.publish(cout);
				   break;
				default : 
				   exit();
			}
		}
		
		void ToGetTeacher(auto & teacher_msg)
		{
			auto TeacherState = *teacher_msg;
			switch(TeacherState.msg)
			{
				case "Class":
				   teacher::BecameClass();
				   break; 
				case "Lab":
				   teacher::BecameLabor()
				   break;
				case "Money":
				   teacher::GoToFindPresident();
				   break;
				default : 
				  teacher::exit();
			}
		}
		
		void ToGetClassmate(auto & classmate_msg)
		{
			auto ClassmateState = *teacher_msg;
			switch(Classmate.msg)
			{
				case "Class":
				   classmate::BecameClassmate();
				   break; 
				case "Lab":
				   classmate::BecameLabormate()
				   break;
				case "Test":
				   classmate::BecameMastermate();
				   break; 
				case "Money":
				   classmate::Reject();
				   break;
				case "Love":
				   classmate::Reject();
				   break;
				default : 
				  classmate::SaveWechat();
			}
		}
	public:
		int cout;
		string name;
	
	private:
		ros::NodeHandle nh_;
		ros::Subscriber classmate_sub_,teacher_sub_;
		ros::Publisher cout_pub_;
		
	
}
int i = 0;
void ResetCout(const std_msgs::Int8& msg)
{
	i = msg->data;
}
int main(int argc, char *argv[])
{
	ros::init(argc, argv, "MyCollege");
	
	MYCOLLEGE me;
	
	for(;i<4;i++)
	{
		me.cout = i;
		ros::spinOnce();
	}
	
	ros::spin();
    return 0;
}
