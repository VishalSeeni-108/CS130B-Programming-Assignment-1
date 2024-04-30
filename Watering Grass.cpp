#include <iostream>
#include <string>
#include <sstream> 
#include <vector>

using namespace std; 

main()
{
    //Take in input
    string input;
    getline(cin, input);
    while(input != "")
    {
        int numSprinklers; 
        int length; 
        int width; 
        stringstream caseInput(input); 
        caseInput >> numSprinklers; 
        caseInput >> length; 
        caseInput >> width; 

        vector<vector<int>> sprinklers; 
        for(int i = 0; i < numSprinklers; i++)
        {
            int position; 
            int radius; 
            cin >> position;
            cin >> radius; 

            vector<int> newSprinkler; 
            newSprinkler.push_back(position); 
            newSprinkler.push_back(radius); 
            sprinklers.push_back(newSprinkler); 
        }

        cout << numSprinklers << " " << length << " " << width << endl; 
        for(int i = 0; i < numSprinklers; i++)
        {
            cout << sprinklers.at(i).at(0) << " " << sprinklers.at(i).at(1) << endl; 
        }

        cout << "END CASE" << endl; 
        cout << endl; 

        getline(cin, input);
        getline(cin, input); 
    }
}