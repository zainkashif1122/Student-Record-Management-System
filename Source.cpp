#include <iostream>
using namespace std;

const int MAX_STUDENTS = 5;

void showIntroBanner() 
{
    cout << "***********************************************" << endl;
    cout << "*                                             *" << endl;
    cout << "*       STUDENT RECORD MANAGEMENT SYSTEM      *" << endl;
    cout << "*                                             *" << endl;
    cout << "*       Manage, Add, Update, and Display      *" << endl;
    cout << "*             Student Records Easily          *" << endl;
    cout << "*                                             *" << endl;
    cout << "***********************************************" << endl;
    cout << endl;
}

int main()
{
    showIntroBanner();

    int rollNumbers[MAX_STUDENTS];
    int marksCS[MAX_STUDENTS];
    int marksMath[MAX_STUDENTS];
    double percentages[MAX_STUDENTS];
    char grades[MAX_STUDENTS];
    int count = 0;
    char choice;

    do
    {
        if (count >= MAX_STUDENTS)
        {
            cout << endl << "Cannot enroll more students, limit reached.\n";
            break;
        }

        int rollNumber, marksCSInput, marksMathInput;
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        do
        {
            cout << "Enter Marks for Computer Science (0-100): ";
            cin >> marksCSInput;
        } while (marksCSInput > 100 || marksCSInput < 0);
        do
        {
            cout << "Enter Marks for Mathematics (0-100): ";
            cin >> marksMathInput;
        } while (marksMathInput > 100 || marksMathInput < 0);

        rollNumbers[count] = rollNumber;
        marksCS[count] = marksCSInput;
        marksMath[count] = marksMathInput;
        percentages[count] = (marksCSInput + marksMathInput) / 2.0;

        if (percentages[count] >= 91 && percentages[count] <= 100)
        {
            grades[count] = 'A';
        }
        else if (percentages[count] >= 75 && percentages[count] < 91)
        {
            grades[count] = 'B';
        }
        else if (percentages[count] >= 60 && percentages[count] < 75)
        {
            grades[count] = 'C';
        }
        else if (percentages[count] >= 50 && percentages[count] < 60)
        {
            grades[count] = 'D';
        }
        else
        {
            grades[count] = 'F';
        }

        count++;

        cout << endl << "Do you want to enroll another student? (Y/y for yes): ";
        cin >> choice;
        cout << endl;
    } while ((choice == 'Y' || choice == 'y') && count < MAX_STUDENTS);

    do
    {
        cout << endl << "Do you want to perform advanced operations? (Y/y for yes, N/n to exit): ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            int operation;
            cout << endl << "Choose an operation:" << endl;
            cout << "1. Update Roll Number of a particular student" << endl;
            cout << "2. Update marks of a particular student for Computer Science" << endl;
            cout << "3. Update marks of Computer Science for all students" << endl;
            cout << "4. Update marks of a particular student for Mathematics" << endl;
            cout << "5. Update marks of Mathematics for all students" << endl;
            cout << "6. Sort the data on the basis of generated percentages" << endl;
            cout << "7. Delete the record of a particular student" << endl;
            cin >> operation;

            if (operation == 1)
            {
                int rollNumber;
                cout << endl << "Enter Roll Number of the student to update: ";
                cin >> rollNumber;
                int index = -1;
                for (int i = 0; i < count; ++i)
                {
                    if (rollNumbers[i] == rollNumber)
                    {
                        index = i;
                        break;
                    }
                }
                if (index == -1)
                {
                    cout << endl << "Student not found." << endl;
                }
                else
                {
                    cout << "Enter new Roll Number: ";
                    cin >> rollNumbers[index];
                }
            }
            else if (operation == 2)
            {
                int rollNumber, marksCSInput;
                cout << endl << "Enter Roll Number of the student to update: ";
                cin >> rollNumber;
                int index = -1;
                for (int i = 0; i < count; ++i)
                {
                    if (rollNumbers[i] == rollNumber)
                    {
                        index = i;
                        break;
                    }
                }
                if (index == -1)
                {
                    cout << endl << "Student not found." << endl;
                }
                else
                {
                    do
                    {
                        cout << "Enter new Marks for Computer Science (0-100): ";
                        cin >> marksCSInput;
                    } while (marksCSInput > 100 || marksCSInput < 0);
                    marksCS[index] = marksCSInput;
                    percentages[index] = (marksCS[index] + marksMath[index]) / 2.0;

                    if (percentages[index] >= 91 && percentages[index] <= 100)
                    {
                        grades[index] = 'A';
                    }
                    else if (percentages[index] >= 75 && percentages[index] < 91)
                    {
                        grades[index] = 'B';
                    }
                    else if (percentages[index] >= 60 && percentages[index] < 75)
                    {
                        grades[index] = 'C';
                    }
                    else if (percentages[index] >= 50 && percentages[index] < 60)
                    {
                        grades[index] = 'D';
                    }
                    else
                    {
                        grades[index] = 'F';
                    }
                }
            }
            else if (operation == 3)
            {
                int marksCSInput;
                do
                {
                    cout << endl << "Enter new Marks for Computer Science for all students (0-100): ";
                    cin >> marksCSInput;
                } while (marksCSInput > 100 || marksCSInput < 0);
                for (int i = 0; i < count; ++i)
                {
                    marksCS[i] = marksCSInput;
                    percentages[i] = (marksCS[i] + marksMath[i]) / 2.0;

                    if (percentages[i] >= 91 && percentages[i] <= 100)
                    {
                        grades[i] = 'A';
                    }
                    else if (percentages[i] >= 75 && percentages[i] < 91)
                    {
                        grades[i] = 'B';
                    }
                    else if (percentages[i] >= 60 && percentages[i] < 75)
                    {
                        grades[i] = 'C';
                    }
                    else if (percentages[i] >= 50 && percentages[i] < 60)
                    {
                        grades[i] = 'D';
                    }
                    else
                    {
                        grades[i] = 'F';
                    }
                }
            }
            else if (operation == 4)
            {
                int rollNumber, marksMathInput;
                cout << endl << "Enter Roll Number of the student to update: ";
                cin >> rollNumber;
                int index = -1;
                for (int i = 0; i < count; ++i)
                {
                    if (rollNumbers[i] == rollNumber)
                    {
                        index = i;
                        break;
                    }
                }
                if (index == -1)
                {
                    cout << endl << "Student not found." << endl;
                }
                else
                {
                    do
                    {
                        cout << "Enter new Marks for Mathematics (0-100): ";
                        cin >> marksMathInput;
                    } while (marksMathInput > 100 || marksMathInput < 0);
                    marksMath[index] = marksMathInput;
                    percentages[index] = (marksCS[index] + marksMath[index]) / 2.0;

                    if (percentages[index] >= 91 && percentages[index] <= 100)
                    {
                        grades[index] = 'A';
                    }
                    else if (percentages[index] >= 75 && percentages[index] < 91)
                    {
                        grades[index] = 'B';
                    }
                    else if (percentages[index] >= 60 && percentages[index] < 75)
                    {
                        grades[index] = 'C';
                    }
                    else if (percentages[index] >= 50 && percentages[index] < 60)
                    {
                        grades[index] = 'D';
                    }
                    else
                    {
                        grades[index] = 'F';
                    }
                }
            }
            else if (operation == 5)
            {
                int marksMathInput;
                do
                {
                    cout << endl << "Enter new Marks for Mathematics for all students (0-100): ";
                    cin >> marksMathInput;
                } while (marksMathInput > 100 || marksMathInput < 0);
                for (int i = 0; i < count; ++i)
                {
                    marksMath[i] = marksMathInput;
                    percentages[i] = (marksCS[i] + marksMath[i]) / 2.0;

                    if (percentages[i] >= 91 && percentages[i] <= 100)
                    {
                        grades[i] = 'A';
                    }
                    else if (percentages[i] >= 75 && percentages[i] < 91)
                    {
                        grades[i] = 'B';
                    }
                    else if (percentages[i] >= 60 && percentages[i] < 75)
                    {
                        grades[i] = 'C';
                    }
                    else if (percentages[i] >= 50 && percentages[i] < 60)
                    {
                        grades[i] = 'D';
                    }
                    else
                    {
                        grades[i] = 'F';
                    }
                }
            }
            else if (operation == 6)
            {
                for (int i = 0; i < count - 1; ++i)
                {
                    for (int j = i + 1; j < count; ++j)
                    {
                        if (percentages[i] > percentages[j])
                        {
                            int tempRollNumber = rollNumbers[i];
                            rollNumbers[i] = rollNumbers[j];
                            rollNumbers[j] = tempRollNumber;

                            int tempMarksCS = marksCS[i];
                            marksCS[i] = marksCS[j];
                            marksCS[j] = tempMarksCS;

                            int tempMarksMath = marksMath[i];
                            marksMath[i] = marksMath[j];
                            marksMath[j] = tempMarksMath;

                            double tempPercentage = percentages[i];
                            percentages[i] = percentages[j];
                            percentages[j] = tempPercentage;

                            char tempGrade = grades[i];
                            grades[i] = grades[j];
                            grades[j] = tempGrade;
                        }
                    }
                }
                cout << endl << "Data sorted based on percentages." << endl;
            }
            else if (operation == 7)
            {
                int rollNumber;
                cout << endl << "Enter Roll Number of the student to delete: ";
                cin >> rollNumber;
                int index = -1;
                for (int i = 0; i < count; ++i)
                {
                    if (rollNumbers[i] == rollNumber)
                    {
                        index = i;
                        break;
                    }
                }
                if (index == -1)
                {
                    cout << endl << "Student not found." << endl;
                }
                else
                {
                    for (int i = index; i < count - 1; ++i)
                    {
                        rollNumbers[i] = rollNumbers[i + 1];
                        marksCS[i] = marksCS[i + 1];
                        marksMath[i] = marksMath[i + 1];
                        percentages[i] = percentages[i + 1];
                        grades[i] = grades[i + 1];
                    }
                    count--;
                    cout << endl << "Record deleted successfully." << endl;
                }
            }
        }
    } while (choice != 'N' && choice != 'n');

    cout << endl << "Student Records:" << endl;
    for (int i = 0; i < count; ++i)
    {
        cout << "Roll Number: " << rollNumbers[i]
             << ", Marks (CS): " << marksCS[i]
             << ", Marks (Math): " << marksMath[i]
             << ", Percentage: " << percentages[i]
             << ", Grade: " << grades[i] << endl;
    }

    return 0;
}
