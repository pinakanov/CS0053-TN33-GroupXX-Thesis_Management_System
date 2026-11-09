#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Thesis
{
    string thesisID;
    string studentName;
    string title;
    string adviserName;
    string status;
    string comments;
};
vector<Thesis> theses;

// first commit features.
void submitProposal();
void viewProposal();


void studentMenu()
{
    int choice;

    do
    {
        cout << "\n\n STUDENT MENU ";
        cout << "\n1. Submit Proposal";
        cout << "\n2. View Proposal";
        cout << "\n3. Edit Proposal";
        cout << "\n4. Delete Proposal";
        cout << "\n5. Submit Revision";
        cout << "\n6. Check Status";
        cout << "\n7. Back";

        cout << "\nChoice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: submitProposal(); 
            break;
            case 2: viewProposal();
            break;
        }

    } while(choice != 7);
    
}

void submitProposal()
{
    Thesis t;

    cout << "\nEnter Thesis ID: ";
    cin >> t.thesisID;

    cin.ignore();

    cout << "Student Name: ";
    getline(cin, t.studentName);

    cout << "Thesis Title: ";
    getline(cin, t.title);

    cout << "Adviser Name: ";
    getline(cin, t.adviserName);

    t.status = "Pending";
    t.comments = "No comments yet";

    theses.push_back(t);

    cout << "\nProposal submitted successfully!\n";
}

void viewProposal()
{
    string id;

    cout << "\nEnter Thesis ID: ";
    cin >> id;

    bool found = false;

    for(const auto& t : theses)
    {
        if(t.thesisID == id)
        {
            cout << "\n--------------------------";
            cout << "\nThesis ID: " << t.thesisID;
            cout << "\nStudent: " << t.studentName;
            cout << "\nTitle: " << t.title;
            cout << "\nAdviser: " << t.adviserName;
            cout << "\nStatus: " << t.status;
            cout << "\nComments: " << t.comments;
            cout << "\n--------------------------\n";

            found = true;
        }
    }

    if(!found)
        cout << "\nThesis not found.\n";
}



int main()
{
    int choice;

    do
    {
        cout << "\n   THESIS MANAGEMENT SYSTEM";
        cout << "\n1. Student";
        cout << "\n2. Adviser";
        cout << "\n3. Thesis Repository";
        cout << "\n4. Exit";

        cout << "\n\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                studentMenu();
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                cout << "\nThank you for using the system.\n";
                break;

            default:
                cout << "\nInvalid choice.\n";
        }

    } while(choice != 4);

    return 0;
}

