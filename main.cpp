#include <bits/stdc++.h>

using namespace std;
string User_name="USER";
string Update_name()  // To Set the user's name.
{
    string new_name;
    cout << "Please Enter your name "<< endl;
    cin >> new_name;
    User_name=new_name;
    return User_name;
}
struct QuestionFormat
{
    string question;
    static  int question_Id;
    int question_Id1;      // Question's  unique ID
    string answer[4];
};
int QuestionFormat::question_Id=0;
QuestionFormat temp;
QuestionFormat new_;
QuestionFormat temp1;
vector < QuestionFormat>v;    // This is all of question which be available for stating any quiz.
vector<int >grades;    // All grades for each quiz.
static int count_quizzes=0;
int count_correct=0;
bool is_ok(int& x,int& y) // This function to correct each question in a quiz.
{
    if(x==y)
        return true;
    else
        return false;
}
void Start_quiz()    // To start a new quiz with random questions and random answers for each time that user start.
{
    while(v.size()<5)
    {
        cout << "Error, you can't start quiz Now." << endl;
        cout << "Please Add new questions or Load questions from question's file from Administration menu" << "\n\n";
        return;
    }
    count_quizzes++;
    char your_choice;

    int all_question;
    all_question=v.size();
    int n=5,i,j,m=4;
    bool arr[all_question]= {0};
    time_t t;
    srand((unsigned)time(&t));
    for(i=0; i<n; ++i)
    {
        int target;          // This is refer to actual index of answer that is will be appeared in the quiz
        int r=rand()%(all_question);
        if(!arr[r])
        {
            cout <<v[r].question << endl;
            time_t t;
            srand((unsigned)time(&t));
            bool arr_an[4]= {0};
            for( j=0; j<m; ++j)
            {
                int ans=rand()%(3+1);
                if(!arr_an[ans])
                {
                    cout <<char((j+1)+96)<<"-"<<v[r].answer[ans] << "   ";
                    if(ans==0)
                        target=j;
                }
                else
                    j--;
                arr_an[ans]=1;
            }
            cout << endl;
            cout << "your choice:" ;
            cin >> your_choice;
            int convert= (your_choice- 'a');    // To convert character index of answers to integers.
            if( is_ok(target,convert))
            {
                count_correct++;
            }
            cout << "\n\n";
        }
        else
            i--;
        arr[r]=1;
    }
    grades.push_back(count_correct);
    cout << "Thanks, you finished the quiz "<< endl;
    count_correct=0;
    cout << "\n\n";
}
int My_program_choice;       // To choose from The Main Menu of this program.
int *p=new int (My_program_choice);

void My_program()    //The main menu to start this program.
{
    cout << "Welcome "<<User_name<< " ,please choose from the following options: " << endl;
    cout << "      [1]Go to administration menu" << endl;
    cout << "      [2]Update your name " << endl;
    cout << "      [3]start a new quiz" << endl;
    cout << "      [4]Display your score's statistics " << endl;
    cout << "      [5]Display all your scores " << endl;
    cout << "      [6]Exit " << endl;

    cin >> My_program_choice;
    cout << "MY Choice :" << My_program_choice<< "\n\n";
    delete p;

}
void All_scores()  // To show history of all quizzes with details for each Quiz.
{
    while(grades.size()==0)
    {
        cout << "Error choice! You should do your quiz first." << "\n\n";
        return;
    }
    cout << "The Total number of all quizzes that " << User_name << " has been finished is [" << grades.size()<<"]."<< endl;;
    cout << "---------------------------------------------------------------------------" << endl;
    int grades_size=grades.size();
    for(int i=0; i<(grades_size); i++)
    {
        cout << "  QUIZ ("<< i+1<<"):" << endl;
        cout << "  _________" << endl;
        cout << "  -The total number of questions : 5" << endl;
        cout <<"  -Number of correct questions : " << grades[i] << endl;
        cout  <<"  -Number of wrong questions : " << 5-(grades[i]) <<endl;
        cout <<"  -Score of QUIZ " << i+1 << ": "<< 2*(grades[i]) << "/10" << endl;
        cout <<"  ----------------------------------" << endl;

    }
    cout << "\n\n";
}

void Score_stat()   // To calculate quizzes scores & its statistical analysis.
{
    while(grades.size()==0)
    {
        cout << "Error choice! You should do your quiz first." << "\n\n";
        return;
    }
    char score_sta;
    double initial_sum=0;

    sort(grades.begin(),grades.end());
    cout << "Your score's statistics :" << endl;
    cout << "             -Number of Quizzes taken: " << count_quizzes << endl;
    cout << "             -Highest score : " << (grades.back())*2 << "/" << "10"<< endl;
    cout << "             -Lowest  score : " << (grades[0])*2 << "/" << "10" << endl;
    cout << "             -Average score : " << (((accumulate(grades.begin(),grades.end(),initial_sum)))/(grades.size()))*2<< "/" << "10" << "\n\n";
    cout << "Press [b] if you want to go back to the main menu or [e] to exit. " << endl;
    cin >> score_sta;

    if(score_sta== 'e'|| score_sta== 'E')
    {
        exit(0);
    }
    else
        return;
}
void view_questions(QuestionFormat & temp)  // To view all questions List & delete any of them.
{
    char delete_choice;
    int del_question_count;
    int id_deleted;
    cout << "Number of questions available : " << v.size() << endl;
    cout << "--------------------------------"<< endl;
    cout << "Question List:"<< endl;
    cout << "-------------- "<< endl;
    int c=v.size();
    for(int i=1; i<=c; i++)
    {
        cout <<"["<<v[i-1].question_Id1<< "]"<< v[i-1].question<< endl;
        for(int j=0; j<4; j++)
        {
            if(j==0)
            {
                cout << "**" <<  char((j+1)+96)<<"-"<<v[i-1].answer[j] << "    ";
            }
            else
                cout << char((j+1)+96)<<"-"<<v[i-1].answer[j] << "    ";
        }
        cout << "\n\n";
    }
    cout << "-------------------------------------------------------" << endl;
    cout << "****The first answer in this file is the correct answer.****" << "\n\n";
    cout << "Press [d] to delete questions ,then Press count of this questions ,then Press question's ID for each question." << endl;
    cout << "Press [b] if you want to go back to the main menu" << endl;
    cin >>delete_choice ;
    if(delete_choice== 'd'|| delete_choice=='D')
    {
        cout << "How many questions that you want to delete? " << endl;
        cin >> del_question_count;
        while(del_question_count-- && (v.size()!=0))
        {
            cout << "Enter question's number that will be deleted" << endl;

            cin >> id_deleted;
            int vec_size=v.size();
            for(int h=0; h<vec_size; h++)
            {
                if(v[h].question_Id1==id_deleted)
                {
                    v.erase(v.begin()+(h));
                }
            }
        }
    }
    else
        My_program();

    cout << endl;
}
void add_newQuestion(QuestionFormat new_)      //To add new questions to the main question's list.
{
    cin.ignore(3200000,'\n');
    cout << "Please enter your new question " <<endl;
    getline(cin,new_.question);
    new_.question_Id++;
    new_.question_Id1=new_.question_Id;
    cout << "Now you must enter 4 different answers,The right answer must be the first answer. "<<endl;
    for(int i=0; i<4; i++)
    {
        getline(cin,new_.answer[i]);
    }
    v.push_back(new_);
    cout << "Your new question added successfully " << endl;
    cout << endl;
}
void load_question()       // This is to load questions with their answers from a file.
{
    QuestionFormat temp1;
    ifstream f;
    string filename;
    cout << "Please enter a file name to load from it: " << endl;
    cin.ignore(3200000,'\n');
    getline(cin,filename);
    f.open(filename.c_str());
    if(!f.is_open())
    {
        cout << "Error open: " << filename << endl;
    }
    while(!f.eof())
    {
        QuestionFormat temp1;
        getline(f,temp1.question);
        temp1.question_Id++;
        temp1.question_Id1=temp1.question_Id;
        cout <<"["<<temp1.question_Id1<<"]"<<temp1.question<<endl;
        for(int j=0; j< 4; j++)
        {
            getline(f,temp1.answer[j]);
            cout  <<  char((j+1)+96)<<"-"<<temp1.answer[j] << "    ";

        }
        cout << "\n\n";
        v.push_back(temp1);
    }

    f.close();
}
void Adminst_menu()     // This is Administration Menu in Main (My_program) menu
{
    int admin_choice;
    cout << "Welcome to administration menu,please choose from the following options: "  << endl;
    cout << "     [1]view all questions "<< endl;
    cout << "     [2]Add new question " << endl;
    cout << "     [3]Load question from file" << endl;
    cout << "     [4]Go back to main menu" << endl;
    cin >> admin_choice;
    cout << "My choice: " << admin_choice<< "\n\n";
    switch(admin_choice)
    {
    case (1):
        view_questions(temp);
        break;
    case (2):
        add_newQuestion(new_);
        break;
    case (3):
        load_question();
        break;
    case (4):
    default:
        My_program();
        break;
    }
}


int main()
{
    My_program();
    ifstream infile;
    infile.open("exam_questions (2).txt");   // This is to load all questions available in this file.
    if(infile.fail())
    {
        cout << "error";
        return 0;
    }
    while(!(infile.eof()))
    {
        getline(infile,temp.question);

        for(int i=0; i< 4; i++)
        {
            getline(infile,temp.answer[i]);

        }
        temp.question_Id++;
        temp.question_Id1=temp.question_Id;
        v.push_back(temp);
    }
    infile.close();

    while(true)
    {

        switch((My_program_choice))
        {

        case(1):
            Adminst_menu();
            break;
        case(2):
        {
            Update_name();
            My_program();
        }
        break;
        case(3):
        {
            Start_quiz();
            My_program();
        }
        break;
        case(4):
        {
            Score_stat();
            My_program();
        }
        break;
        case(5):
        {
            All_scores();
            My_program();
        }

        break;
        case(6):
            return 0;
        default:
        {
            cout << "Renter your choice ,press favourite choice from [1] to [6] :" << "\n\n";
            My_program();
        }
        }
    }

    return 0;
}

