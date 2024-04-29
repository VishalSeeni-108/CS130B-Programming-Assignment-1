#include <iostream> 
#include <vector> 

using namespace std; 

main()
{
    //Read in input
    vector<vector <int>> checkerboard; 
    vector<vector <int>> parity; 

    int rows, columns; 
    cin >> rows; 
    cin >> columns; 

    for(int i = 0; i < rows; i++)
    {
        vector<int> tempRow; 
        vector<int> parityRow; 
        for(int j = 0; j < columns; j++)
        {
            int tempValue; 
            cin >> tempValue; 
            tempRow.push_back(tempValue); 
            if(tempValue == 0)
            {
                parityRow.push_back(2); 
            }
            else
            {
                parityRow.push_back(tempValue % 2); 
            }
        }
        checkerboard.push_back(tempRow); 
        parity.push_back(parityRow); 
    }

    cout << endl; 
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << checkerboard.at(i).at(j) << " "; 
        }
        cout << endl; 
    }

    cout << endl; 
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << parity.at(i).at(j) << " "; 
        }
        cout << endl; 
    }

    //Assign parity array
    //First, we check if the input is invalid by figuring out if there are parities spread row and column wise
    bool invalid = false; 
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            bool sameRow = false;
            bool sameCol = false;  
            if(parity.at(i).at(j) !=  2)
            {
                //Check if there are cells with the same parity in the same row
                
                for(int k = 0; k < columns; k++)
                {
                    if((k != j) && parity.at(i).at(k) == parity.at(i).at(j))
                    {
                        sameRow = true; 
                        break; 
                    }
                }

                //Check if there are cells with the same parity in the same column

                for(int l = 0; l < rows; l++)
                {
                    if((l != i) && parity.at(l).at(j) == parity.at(i).at(j))
                    {
                        sameCol = true; 
                        break; 
                    }
                }

                //if there are cells with the same parity in the same row, check if there are any elements with the same parity in "adjacent" rows
                if(sameRow)
                {
                    for(int k = i+1; k < rows; k+=2)
                    {
                        for(int m = 0; m < columns; m++)
                        {
                            if((m != i) && parity.at(k).at(m) == parity.at(i).at(j))
                            {
                                invalid = true; 
                                break; 
                            }
                        }
                    }
                    for(int k = i-1; k >= 0; k-=2)
                    {
                        for(int m = 0; m < columns; m++)
                        {
                            if((m != i) && parity.at(k).at(m) == parity.at(i).at(j))
                            {
                                cout << "This was triggered" << endl; 
                                cout << "k: " << k << endl; 
                                cout << "m: " << m << endl; 
                                cout << "i: " << i << endl; 
                                cout << "j: " << j << endl; 
                                invalid = true; 
                                break; 
                            }
                        }
                    }

                    //if not invalid, assign parity by row 
                    int parityToAssign = parity.at(i).at(j); 
                    if(!invalid)
                    {
                        cout << "assigning parity" << endl; 
                        for(int k = i; k < rows; k+=2)
                        {
                            for(int l = 0; l < columns; l++)
                            {
                                parity.at(k).at(l) = parityToAssign; 
                            }
                        }
                        for(int k = i; k >= 0; k-=2)
                        {
                            for(int l = 0; l < columns; l++)
                            {
                                parity.at(k).at(l) = parityToAssign; 
                            }
                        }
                        break; 
                    }
                }
                else if(sameCol)
                {
                    
                }
            }

            if(sameRow)
            {
                break; 
            }
        }
    }

   cout << endl; 
   cout << "After edit" << endl; 
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << parity.at(i).at(j) << " "; 
        }
        cout << endl; 
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


    cout << endl; 
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << checkerboard.at(i).at(j) << " "; 
        }
        cout << endl; 
    }
}