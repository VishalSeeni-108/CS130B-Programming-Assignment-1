#include <iostream> 
#include <vector> 

using namespace std; 

main()
{
    //Read in input
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

    //Idea: take the smallest possible value at each choice
    //Check all 4 corners for parity - if they all agree, pick the smallest value that is increasing both row and column wise and has opposite parity
    bool invalidInput = false; 

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            //Check parity dictated by corners - if there is an invalid setup, return -1
            bool parityAgrees = true;
            int  cornerParity = 2; //0 for even, 1 for odd  
            //Check upper left
            if(i != 0 && j != 0)
            {
                if(checkerboard.at(i-1).at(j-1) != 0)
                {
                    if(cornerParity == 2)
                    {
                        cornerParity = checkerboard.at(i-1).at(j-1) % 2; 
                    }
                    else
                    {
                        if(cornerParity != checkerboard.at(i-1).at(j-1) % 2)
                        {
                            parityAgrees = false; 
                        }
                    }
                }
            }
            //Check upper right
            if(i != 0 && j != (columns - 1))
            {
                if(checkerboard.at(i-1).at(j+1) != 0)
                {
                    if(cornerParity == 2)
                    {
                        cornerParity = checkerboard.at(i-1).at(j+1) % 2; 
                    }
                    else
                    {
                        if(cornerParity != checkerboard.at(i-1).at(j+1) % 2)
                        {
                            parityAgrees = false; 
                        }
                    }
                }
            }
            //Check lower left
            if(i != (rows - 1) && j != 0)
            {
                if(checkerboard.at(i+1).at(j-1) != 0)
                {
                    if(cornerParity == 2)
                    {
                        cornerParity = checkerboard.at(i+1).at(j-1) % 2; 
                    }
                    else
                    {
                        if(cornerParity != checkerboard.at(i+1).at(j-1) % 2)
                        {
                            parityAgrees = false; 
                        }
                    }
                }
              
            }
            //Check lower right
            if(i != (rows - 1) && j != (columns - 1))
            {
                if(checkerboard.at(i+1).at(j+1) != 0)
                {
                    if(cornerParity == 2)
                    {
                        cornerParity = checkerboard.at(i+1).at(j+1) % 2; 
                    }
                    else
                    {
                        if(cornerParity != checkerboard.at(i+1).at(j+1) % 2)
                        {
                            parityAgrees = false; 
                        }
                    }
                }
            }

            if(!parityAgrees)
            {
                cout << -1 << endl; 
                //cout << "Invalid case 1" << endl; 
                //cout << "Row: " << i << " Column: " << j << endl; 
                invalidInput = true; 
                break; 
            }
            else
            {
                if(checkerboard.at(i).at(j) != 0)
                {
                    if(checkerboard.at(i).at(j) % 2 == cornerParity)
                    {
                        cout << -1 << endl; 
                        //cout << "Invalid case 2" << endl; 
                        //cout << "Row: " << i << " Column: " << j << endl; 
                        invalidInput = true; 
                        break; 
                    }
                }
                else
                {
                    int nextSmallestValue;
                    if(i == 0 && j == 0)
                    {
                        nextSmallestValue = 1; 
                    }
                    else if(i == 0)
                    {
                        nextSmallestValue = checkerboard.at(i).at(j-1) + 1; 
                    }
                    else if(j == 0)
                    {
                        nextSmallestValue = checkerboard.at(i-1).at(j) + 1; 
                    }
                    else
                    {
                        nextSmallestValue = checkerboard.at(i-1).at(j) + 1; 
                        if(nextSmallestValue < (checkerboard.at(i).at(j-1) + 1))
                        {
                            nextSmallestValue = checkerboard.at(i).at(j-1) + 1; 
                        }
                    }

                    if(nextSmallestValue % 2 == cornerParity)
                    {
                        nextSmallestValue++; 
                    }

                    //Check increasing property
                    bool increasingValid = true; 
                    if(i != (rows - 1))
                    {
                        if(nextSmallestValue >= checkerboard.at(i+1).at(j) && checkerboard.at(i+1).at(j) != 0)
                        {
                            increasingValid = false; 
                        }
                    }
                    if(j != (columns - 1))
                    {
                        if(nextSmallestValue >= checkerboard.at(i).at(j+1) && checkerboard.at(i).at(j+1) != 0)
                        {
                            increasingValid = false; 
                        }
                    }
                    if(!increasingValid)
                    {
                        cout << -1 << endl; 
                        //cout << "Invalid case 3" << endl; 
                        //cout << "Row: " << i << " Column: " << j << endl; 
                        invalidInput = true; 
                        break; 
                    }
                    else
                    {
                        checkerboard.at(i).at(j) = nextSmallestValue; 
                    }
                }
            }

        }
        if(invalidInput)
        {
            break; 
        }
    }

    if(!invalidInput)
    {
        int sum = 0; 
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                sum += checkerboard.at(i).at(j); 
            }
        }
        cout << sum << endl; 
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