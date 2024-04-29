#include <iostream> 
#include <vector> 

using namespace std; 

main()
{
    vector<vector <int>> checkerboard; 

    int rows, columns; 
    cin >> rows; 
    cin >> columns; 

    for(int i = 0; i < rows; i++)
    {
        vector<int> tempRow; 
        for(int j = 0; j < columns; j++)
        {
            int tempValue; 
            cin >> tempValue; 
            tempRow.push_back(tempValue); 
        }
        checkerboard.push_back(tempRow); 
    }

    //Find first non empty cell
    int nonZeroRow = 0; 
    int nonZeroColumn = 0;
    bool nonZeroFound = false;     
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(checkerboard.at(i).at(j) != 0)
            {
                nonZeroRow = i; 
                nonZeroColumn = j; 
                nonZeroFound = true; 
            }
            if(nonZeroFound)
            {
                break;
            }
        }
        if(nonZeroFound)
        {
            break; 
        }
    }

    //All (even, even) and (odd, odd) squares will be one parity and all (even, odd) and (odd, even) squares will be the other
    //Call this class 1 and class 2 respectively
    //First, classify the first nonzero value. It's parity will be used for all the values in its class. 

    //Since we're using modulo, a value of 0 will indicate even and a value of 1 will indicate odd
    int firstValClass; 

    int firstValRowParity = nonZeroRow % 2; 
    int firstValColParity = nonZeroColumn % 2; 
    int firstValParity = checkerboard.at(nonZeroRow).at(nonZeroColumn) % 2; 

    if((nonZeroRow == 0 && nonZeroColumn == 0) || (nonZeroRow == 1 && nonZeroColumn == 1))
    {
        firstValClass = 0; //Class 1
    }
    else
    {
        firstValClass = 1; //Class 2
    }

    //Now, for each square: 
    //1. Classify the cell. 
    //2. Check if a value is already present. If there is a value already assigned, check if it is the expected parity. If it isn't, stop the program and return -1. Otherwise, continue. 
    //3. Check the previous values in the row and index (with exceptions for values on the edges). Since we need the values to be increasing from left to right and top to bottom, we will 
    //take the greedy approach by choosing the smallest value that will satisfy the increasing constraint both ways. 

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            //Classify Cell 
            int currCellClass; 

            int currCellRowParity = i % 2; 
            int currCellColParity = j % 2; 

            if((currCellRowParity == 0 && currCellColParity == 0) || (currCellRowParity == 1 && currCellColParity == 1))
            {
                currCellClass = 0; //Class 1
            }
            else
            {
                currCellClass = 1; //Class 2
            }

            //Check if there is an existing value
            if(checkerboard.at(i).at(j) != 0)
            {
                int existingValueParity = checkerboard.at(i).at(j) % 2; 
                if(currCellClass == firstValClass)
                {
                    if(existingValueParity != firstValParity)
                    {
                        cout << -1 << endl; 
                        cout << "Invalid case 1 reached" << endl; //Delete this later
                    }
                }
                else if(currCellClass != firstValClass)
                {
                    if(existingValueParity == firstValParity)
                    {
                        cout << -1 << endl; 
                        cout << "Invalid case 2 reached" << endl; //Delete this later
                    }
                }
            }
        }
    }





    // cout << endl; 

    // for(int i = 0; i < rows; i++)
    // {
    //     for(int j = 0; j < columns; j++)
    //     {
    //         cout << checkerboard.at(i).at(j) << " "; 
    //     }
    //     cout << endl; 
    // }
}