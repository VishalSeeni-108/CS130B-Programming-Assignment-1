#include <iostream> 
#include <vector> 
#include <climits>

using namespace std; 

main()
{
    //Read in input
    vector<vector <long long int>> checkerboard; 

    long long int rows, columns; 
    cin >> rows; 
    cin >> columns; 

    for(long long int i = 0; i < rows; i++)
    {
        vector<long long int> tempRow; 
        for(long long int j = 0; j < columns; j++)
        {
            long long int tempValue; 
            cin >> tempValue; 
            tempRow.push_back(tempValue); 
        }
        checkerboard.push_back(tempRow); 
    }

    // cout << endl; 
    // for(long long int i = 0; i < rows; i++)
    // {
    //     for(long long int j = 0; j < columns; j++)
    //     {
    //         cout << checkerboard.at(i).at(j) << " "; 
    //     }
    //     cout << endl; 
    // }

    //New approach: we know that parity will be the either along alternating rows or along alternating columns. We will assume 4 cases: 
    //1. Alternating rows, starting with even
    //2. Alternating rows, starting with odd
    //3. Alternating columns, starting with even
    //4. Alternating columns, starting with odd
    //Create assignments for all 4, compare, and pick whichever has the least sum
    //Potential TODO: figure out a way to pick between the 4 above cases

    vector<vector<long long int>> rowEven(checkerboard); 
    vector<vector<long long int>> rowOdd(checkerboard);
    vector<vector<long long int>> colEven(checkerboard); 
    vector<vector<long long int>> colOdd(checkerboard); 

    //1. Alternating rows, starting with even
    bool invalidFlag1 = false; 
    for(long long int i = 0; i < rows; i++)
    {
        for(long long int j = 0; j < columns; j++)
        {   
            //If there is no existing value
            if(rowEven.at(i).at(j) == 0)
            {
                long long int smallestCandidate1 = 1; 
                long long int smallestCandidate2 = 1; 
                long long int nextValue; 

                if(i > 0)
                {
                    if(rowEven.at(i-1).at(j) != 0)
                    {
                        smallestCandidate1 = rowEven.at(i-1).at(j) + 1; 
                    }
                }

                if(j > 0)
                {
                    if(rowEven.at(i).at(j-1) != 0)
                    {
                        smallestCandidate2 = rowEven.at(i).at(j-1) + 1; 
                    }
                }

                if(smallestCandidate1 > smallestCandidate2)
                {
                    nextValue = smallestCandidate1; 
                }
                else
                {
                    nextValue = smallestCandidate2; 
                }

                //ensure nextValue is correct parity - if it is in a even row it should be even 
                if((i % 2) == 0) //should be even
                {
                    if((nextValue % 2) != 0)
                    {
                        nextValue++;
                    }
                }
                else //should be odd
                {
                    if((nextValue % 2) == 0)
                    {
                        nextValue++;
                    }
                }

                //ensure nextValue mantains increasing property both to the right and down
                if(i < (rows - 1))
                {
<<<<<<< HEAD
                    if(nextValue >= rowEven.at(i+1).at(j))
                    {
                        cout << -1 << endl; 
                        invalidFlag1 = true; 
=======
                    if((nextValue > rowEven.at(i + 1).at(j)) && (rowEven.at(i+1).at(j) != 0))
                    {
                        // cout << -1 << endl; 
                        // cout << "Not increasing along column" << endl; 
                        invalidFlag1 = true; 
                        break;
>>>>>>> e1af2e88c2c935b545e04c42f4086b821f137468
                    }
                }

                if(j < (columns - 1))
                {
<<<<<<< HEAD
                    if(nextValue >= rowEven.at(i).at(j+1))
                    {
                        
=======
                    if((nextValue > rowEven.at(i).at(j+1)) && (rowEven.at(i).at(j+1) != 0))
                    {
                        // cout << -1 << endl; 
                        // cout << "Not increasing along row" << endl; 
                        invalidFlag1 = true; 
                        break; 
>>>>>>> e1af2e88c2c935b545e04c42f4086b821f137468
                    }
                }

                rowEven.at(i).at(j) = nextValue; 
            }
            else //There is already a value
            {
                //Check parity
                if((i % 2) == 0) //should be even
                {
                    if((rowEven.at(i).at(j) % 2) != 0)
                    {
                        // cout << -1 << endl; 
                        // cout << "Existing value should be even" << endl; 
                        invalidFlag1 = true; 
                        break; 
                    }
                }
                else //should be odd
                {
                    if((rowEven.at(i).at(j) % 2) == 0)
                    {
                        // cout << -1 << endl; 
                        // cout << "Existing value should be odd" << endl; 
                        invalidFlag1 = true; 
                        break; 
                    }
                }

                //Check increasing 
                if(i != 0)
                {
                    if(rowEven.at(i).at(j) <= rowEven.at(i-1).at(j))
                    {
                        invalidFlag1 = true; 
                        break; 
                    }
                }

                if(j != 0)
                {
                    if(rowEven.at(i).at(j) <= rowEven.at(i).at(j-1))
                    {
                        invalidFlag1 = true; 
                        break;
                    }
                }
            }

            if(invalidFlag1)
            {
                break; 
            }
            
        }

        if(invalidFlag1)
        {
            break; 
        }
    }

    //2. Alternating rows, starting with odd
    bool invalidFlag2 = false; 
    for(long long int i = 0; i < rows; i++)
    { 
        for(long long int j = 0; j < columns; j++)
        {   
            //If there is no existing value
            if(rowOdd.at(i).at(j) == 0)
            {
                long long int smallestCandidate1 = 1; 
                long long int smallestCandidate2 = 1; 
                long long int nextValue; 

                if(i > 0)
                {
                    if(rowOdd.at(i-1).at(j) != 0)
                    {
                        smallestCandidate1 = rowOdd.at(i-1).at(j) + 1; 
                    }
                }

                if(j > 0)
                {
                    if(rowOdd.at(i).at(j-1) != 0)
                    {
                        smallestCandidate2 = rowOdd.at(i).at(j-1) + 1; 
                    }
                }

                if(smallestCandidate1 > smallestCandidate2)
                {
                    nextValue = smallestCandidate1; 
                }
                else
                {
                    nextValue = smallestCandidate2; 
                }

                //ensure nextValue is correct parity - if it is in a even row it should be odd 
                if((i % 2) == 0) //should be odd
                {
                    if((nextValue % 2) == 0)
                    {
                        nextValue++;
                    }
                }
                else //should be even
                {
                    if((nextValue % 2) != 0)
                    {
                        nextValue++;
                    }
                }

                //ensure nextValue maintains increasing property both to the right and down
                if(i < (rows - 1))
                {
                    if((nextValue > rowOdd.at(i + 1).at(j)) && (rowOdd.at(i+1).at(j) != 0))
                    {
                        // cout << -1 << endl; 
                        // cout << "Not increasing along column" << endl; 
                        invalidFlag2 = true; 
                        break;
                    }
                }

                if(j < (columns - 1))
                {
                    if((nextValue > rowOdd.at(i).at(j+1)) && (rowOdd.at(i).at(j+1) != 0))
                    {
                        // cout << -1 << endl; 
                        // cout << "Not increasing along row" << endl; 
                        invalidFlag2 = true; 
                        break; 
                    }
                }

                rowOdd.at(i).at(j) = nextValue; 
            }
            else //There is already a value
            {
                //Check parity
                if((i % 2) == 0) //should be odd
                {
                    if((rowOdd.at(i).at(j) % 2) == 0)
                    {
                        // cout << -1 << endl; 
                        // cout << "Existing value should be odd" << endl; 
                        invalidFlag2 = true; 
                        break; 
                    }
                }
                else //should be even
                {
                    if((rowOdd.at(i).at(j) % 2) != 0)
                    {
                        // cout << -1 << endl; 
                        // cout << "Existing value should be even" << endl; 
                        invalidFlag2 = true; 
                        break; 
                    }
                }

                //Check increasing 
                if(i != 0)
                {
                    if(rowOdd.at(i).at(j) <= rowOdd.at(i-1).at(j))
                    {
                        invalidFlag2 = true; 
                        break; 
                    }
                }

                if(j != 0)
                {
                    if(rowOdd.at(i).at(j) <= rowOdd.at(i).at(j-1))
                    {
                        invalidFlag2 = true; 
                        break;
                    }
                }
            }

            if(invalidFlag2)
            {
                break; 
            }
            
        }

        if(invalidFlag2)
        {
            break; 
        }
    }

    //3. Alternating columns, starting with even
    bool invalidFlag3 = false; 
    for(long long int i = 0; i < rows; i++)
    { 
        for(long long int j = 0; j < columns; j++)
        {   
            //If there is no existing value
            if(colEven.at(i).at(j) == 0)
            {
                long long int smallestCandidate1 = 1; 
                long long int smallestCandidate2 = 1; 
                long long int nextValue; 

                if(i > 0)
                {
                    if(colEven.at(i-1).at(j) != 0)
                    {
                        smallestCandidate1 = colEven.at(i-1).at(j) + 1; 
                    }
                }

                if(j > 0)
                {
                    if(colEven.at(i).at(j-1) != 0)
                    {
                        smallestCandidate2 = colEven.at(i).at(j-1) + 1; 
                    }
                }

                if(smallestCandidate1 > smallestCandidate2)
                {
                    nextValue = smallestCandidate1; 
                }
                else
                {
                    nextValue = smallestCandidate2; 
                }

                //ensure nextValue is correct parity - if it is in a even column it should be even 
                if((j % 2) == 0) //should be even
                {
                    if((nextValue % 2) != 0)
                    {
                        nextValue++;
                    }
                }
                else //should be odd
                {
                    if((nextValue % 2) == 0)
                    {
                        nextValue++;
                    }
                }

                //ensure nextValue maintains increasing property both to the right and down
                if(i < (rows - 1))
                {
                    if((nextValue > colEven.at(i + 1).at(j)) && (colEven.at(i+1).at(j) != 0))
                    {
                        // cout << -1 << endl; 
                        // cout << "Not increasing along column" << endl; 
                        invalidFlag3 = true; 
                        break;
                    }
                }

                if(j < (columns - 1))
                {
                    if((nextValue > colEven.at(i).at(j+1)) && (colEven.at(i).at(j+1) != 0))
                    {
                        // cout << -1 << endl; 
                        // cout << "Not increasing along row" << endl; 
                        invalidFlag3 = true; 
                        break; 
                    }
                }

                colEven.at(i).at(j) = nextValue; 
            }
            else //There is already a value
            {
                //Check parity
                if((j % 2) == 0) //should be even
                {
                    if((colEven.at(i).at(j) % 2) != 0)
                    {
                        // cout << -1 << endl; 
                        // cout << "Existing value should be even" << endl; 
                        invalidFlag3 = true; 
                        break; 
                    }
                }
                else //should be odd
                {
                    if((colEven.at(i).at(j) % 2) == 0)
                    {
                        // cout << -1 << endl; 
                        // cout << "Existing value should be odd" << endl; 
                        invalidFlag3 = true; 
                        break; 
                    }
                }

                //Check increasing 
                if(i != 0)
                {
                    if(colEven.at(i).at(j) <= colEven.at(i-1).at(j))
                    {
                        invalidFlag3 = true; 
                        break; 
                    }
                }

                if(j != 0)
                {
                    if(colEven.at(i).at(j) <= colEven.at(i).at(j-1))
                    {
                        invalidFlag3 = true; 
                        break;
                    }
                }
            }

            if(invalidFlag3)
            {
                break; 
            }
            
        }

        if(invalidFlag3)
        {
            break; 
        }
    }

    //4. Alternating columns, starting with odd
    bool invalidFlag4 = false; 
    for(long long int i = 0; i < rows; i++)
    { 
        for(long long int j = 0; j < columns; j++)
        {   
            //If there is no existing value
            if(colOdd.at(i).at(j) == 0)
            {
                long long int smallestCandidate1 = 1; 
                long long int smallestCandidate2 = 1; 
                long long int nextValue; 

                if(i > 0)
                {
                    if(colOdd.at(i-1).at(j) != 0)
                    {
                        smallestCandidate1 = colOdd.at(i-1).at(j) + 1; 
                    }
                }

                if(j > 0)
                {
                    if(colOdd.at(i).at(j-1) != 0)
                    {
                        smallestCandidate2 = colOdd.at(i).at(j-1) + 1; 
                    }
                }

                if(smallestCandidate1 > smallestCandidate2)
                {
                    nextValue = smallestCandidate1; 
                }
                else
                {
                    nextValue = smallestCandidate2; 
                }

                //ensure nextValue is correct parity - if it is in a even column it should be odd 
                if((j % 2) == 0) //should be odd
                {
                    if((nextValue % 2) == 0)
                    {
                        nextValue++;
                    }
                }
                else //should be even
                {
                    if((nextValue % 2) != 0)
                    { 
                        nextValue++;
                    }
                }

                //ensure nextValue maintains increasing property both to the right and down
                if(i < (rows - 1))
                {
                    if((nextValue > colOdd.at(i + 1).at(j)) && (colOdd.at(i+1).at(j) != 0))
                    {
                        // cout << -1 << endl; 
                        // cout << "Not increasing along column" << endl; 
                        invalidFlag4 = true; 
                        break;
                    }
                }

                if(j < (columns - 1))
                {
                    if((nextValue > colOdd.at(i).at(j+1)) && (colOdd.at(i).at(j+1) != 0))
                    {
                        // cout << -1 << endl; 
                        // cout << "Not increasing along row" << endl; 
                        invalidFlag4 = true; 
                        break; 
                    }
                }

                colOdd.at(i).at(j) = nextValue; 
            }
            else //There is already a value
            {
                //Check parity
                if((j % 2) == 0) //should be odd
                {
                    if((colOdd.at(i).at(j) % 2) == 0)
                    {
                        // cout << -1 << endl; 
                        // cout << "Existing value should be odd" << endl; 
                        invalidFlag4 = true; 
                        break; 
                    }
                }
                else //should be even
                {
                    if((colOdd.at(i).at(j) % 2) != 0)
                    {
                        // cout << -1 << endl; 
                        // cout << "Existing value should be even" << endl; 
                        invalidFlag4 = true; 
                        break; 
                    }
                }

                //Check increasing 
                if(i != 0)
                {
                    if(colOdd.at(i).at(j) <= colOdd.at(i-1).at(j))
                    {
                        invalidFlag4 = true; 
                        break; 
                    }
                }

                if(j != 0)
                {
                    if(colOdd.at(i).at(j) <= colOdd.at(i).at(j-1))
                    {
                        invalidFlag4 = true; 
                        break;
                    }
                }
            }

            if(invalidFlag4)
            {
                break; 
            }
            
        }

        if(invalidFlag4)
        {
            break; 
        }
    }

    //Calculate sums
    long long int rowEvenSum = 0; 
    long long int rowOddSum = 0; 
    long long int colEvenSum = 0; 
    long long int colOddSum = 0; 

    for(long long int i = 0; i < rows; i++)
    {
        for(long long int j = 0; j < columns; j++)
        {
            if(!invalidFlag1)
            {
                rowEvenSum += rowEven.at(i).at(j); 
            }

            if(!invalidFlag2)
            {
                rowOddSum += rowOdd.at(i).at(j); 
            }

            if(!invalidFlag3)
            {
                colEvenSum += colEven.at(i).at(j); 
            }

            if(!invalidFlag4)
            {
                colOddSum += colOdd.at(i).at(j); 
            }
        }
    }

    if(invalidFlag1)
    {
        rowEvenSum = LLONG_MAX; 
    }
    if(invalidFlag2)
    {
        rowOddSum = LLONG_MAX; 
    }
    if(invalidFlag3)
    {
        colEvenSum = LLONG_MAX; 
    }
    if(invalidFlag4)
    {
        colOddSum = LLONG_MAX; 
    }

    // cout << endl; 
    // cout << "Sum check:" << endl; 
    // cout << rowEvenSum << endl; 
    // cout << rowOddSum << endl; 
    // cout << colEvenSum << endl; 
    // cout << colOddSum << endl; 
    // cout << endl; 

    //Pick lowest sum
    //Also checking for edgecases here 
    if(rows < 0 || columns < 0)
    {
        cout << -1 << endl; 
    }
    else if(rows == 0 && columns == 0)
    {
        cout << 0 << endl; 
    }
    else if(rows == 1 && columns == 1)
    {
        if(checkerboard.at(0).at(0) != 0)
        {
            cout << checkerboard.at(0).at(0) << endl; 
        }
        else
        {
            cout << 1 << endl; 
        }
    }
    else if(rows == 1)
    {
        int sum = 0; 

        if(checkerboard.at(0).at(0) == 0)
        {
            checkerboard.at(0).at(0) = 1; 
        }
        sum += checkerboard.at(0).at(0); 
        for(int i = 1; i < columns; i++)
        { 
            if(checkerboard.at(0).at(i) == 0) //Empty cell
            {
                checkerboard.at(0).at(i) = checkerboard.at(0).at(i-1) + 1; 
            }
            else if(checkerboard.at(0).at(i) <= checkerboard.at(0).at(i-1)) //Non empty cell - check strictly increasing property
            {   
                sum = -1; 
                break; 
            }
            
            sum += checkerboard.at(0).at(i); 
        }

        cout << sum << endl; 
    }
    else if(columns == 1)
    {
        int sum = 0; 

        if(checkerboard.at(0).at(0) == 0)
        {
            checkerboard.at(0).at(0) = 1; 
        }

        sum += checkerboard.at(0).at(0);
        for(int i = 1; i < rows; i++)
        { 
            if(checkerboard.at(i).at(0) == 0) //Empty cell
            {
                checkerboard.at(i).at(0) = checkerboard.at(i-1).at(0) + 1; 
            }
            else if(checkerboard.at(i).at(0) <= checkerboard.at(i-1).at(0)) //Nonempty cell - check increasing property
            {
                sum = -1; 
                break;
            } 
            sum += checkerboard.at(i).at(0); 
        }

        cout << sum << endl; 
    }
    else if((rowEvenSum <= rowOddSum) && (rowEvenSum <= colEvenSum) && (rowEvenSum <= colOddSum) && (!invalidFlag1))
    {
        cout << rowEvenSum << endl; 
    }
    else if((rowOddSum <= rowEvenSum) && (rowOddSum <= colEvenSum) && (rowOddSum <= colOddSum) && (!invalidFlag2))
    {
        cout << rowOddSum << endl; 
    }
    else if((colEvenSum <= rowEvenSum) && (colEvenSum <= rowOddSum) && (colEvenSum <= colOddSum) && (!invalidFlag3))
    {
        cout << colEvenSum << endl; 
    }
    else if((colOddSum <= rowEvenSum) && (colOddSum <= rowOddSum) && (colOddSum <= colEvenSum) && (!invalidFlag4))
    {
        cout << colOddSum << endl; 
    }
    else
    {
        cout << -1 << endl; 
    }
}



//Print out all arrays

    // cout << endl; 
    // cout << "Original: " << endl;
    // for(long long int i = 0; i < rows; i++)
    // {
    //     for(long long int j = 0; j < columns; j++)
    //     {
    //         cout << checkerboard.at(i).at(j) << " "; 
    //     }
    //     cout << endl; 
    // }

    // cout << endl;
    // cout << "rowEven: " << endl;  
    // for(long long int i = 0; i < rows; i++)
    // {
    //     for(long long int j = 0; j < columns; j++)
    //     {
    //         cout << rowEven.at(i).at(j) << " "; 
    //     }
    //     cout << endl; 
    // }

    // cout << endl;
    // cout << "rowOdd: " << endl;  
    // for(long long int i = 0; i < rows; i++)
    // {
    //     for(long long int j = 0; j < columns; j++)
    //     {
    //         cout << rowOdd.at(i).at(j) << " "; 
    //     }
    //     cout << endl; 
    // }

    // cout << endl;
    // cout << "colEven: " << endl;  
    // for(long long int i = 0; i < rows; i++)
    // {
    //     for(long long int j = 0; j < columns; j++)
    //     {
    //         cout << colEven.at(i).at(j) << " "; 
    //     }
    //     cout << endl; 
    // }

    // cout << endl;
    // cout << "colOdd: " << endl;  
    // for(long long int i = 0; i < rows; i++)
    // {
    //     for(long long int j = 0; j < columns; j++)
    //     {
    //         cout << colOdd.at(i).at(j) << " "; 
    //     }
    //     cout << endl; 
    // }





























   // cout << endl; 
    // for(long long int i = 0; i < rows; i++)
    // {
    //     for(long long int j = 0; j < columns; j++)
    //     {
    //         cout << parity.at(i).at(j) << " "; 
    //     }
    //     cout << endl; 
    // }

//     //Assign parity array
//     //First, we check if the input is invalid by figuring out if there are parities spread row and column wise
//     bool invalid = false; 
//     bool sameRow = false;
//     bool sameCol = false;  
//     long long int parityAssigned = 0; //0 - unassigned, 1 - rowwise, 2 - columnwise 
    
//     for(long long int i = 0; i < rows; i++)
//     {
//         for(long long int j = 0; j < columns; j++)
//         {
//             if(parity.at(i).at(j) !=  2)
//             {
//                 //Check if there are cells with the same parity in the same row
                
//                 for(long long int k = 0; k < columns; k++)
//                 {
//                     if((k != j) && parity.at(i).at(k) == parity.at(i).at(j))
//                     {
//                         sameRow = true; 
//                         break; 
//                     }
//                 }

//                 //Check if there are cells with the same parity in the same column

//                 for(long long int l = 0; l < rows; l++)
//                 {
//                     if((l != i) && parity.at(l).at(j) == parity.at(i).at(j))
//                     {
//                         sameCol = true; 
//                         break; 
//                     }
//                 }

//                 //if there are cells with the same parity in the same row, check if there are any elements with the same parity in "adjacent" rows
//                 if(sameRow)
//                 {
//                     cout << "Same row" << endl; 
//                     for(long long int k = i+1; k < rows; k+=2)
//                     {
//                         for(long long int m = 0; m < columns; m++)
//                         {
//                             if(parity.at(k).at(m) == parity.at(i).at(j))
//                             {
//                                 invalid = true; 
//                                 break; 
//                             }
//                         }
//                     }
//                     for(long long int k = i-1; k >= 0; k-=2)
//                     {
//                         for(long long int m = 0; m < columns; m++)
//                         {
//                             if(parity.at(k).at(m) == parity.at(i).at(j))
//                             {
//                                 cout << "This was triggered" << endl; 
//                                 cout << "k: " << k << endl; 
//                                 cout << "m: " << m << endl; 
//                                 cout << "i: " << i << endl; 
//                                 cout << "j: " << j << endl; 
//                                 invalid = true; 
//                                 break; 
//                             }
//                         }
//                     }

//                     //if not invalid, assign parity by row 
//                     long long int parityToAssign = parity.at(i).at(j); 
//                     if(!invalid)
//                     {
//                         cout << "assigning parity" << endl; 
//                         for(long long int k = i; k < rows; k+=2)
//                         {
//                             for(long long int l = 0; l < columns; l++)
//                             {
//                                 parity.at(k).at(l) = parityToAssign; 
//                             }
//                         }
//                         for(long long int k = i; k >= 0; k-=2)
//                         {
//                             for(long long int l = 0; l < columns; l++)
//                             {
//                                 parity.at(k).at(l) = parityToAssign; 
//                             }
//                         }
//                         break; 
//                     }
//                 }
//                 else if(sameCol) //if there are cells with the same parity in the same column, check if there are any elements with the same parity in "adjacent" column
//                 {
//                     cout << "Same column" << endl; 
//                     for(long long int k = j+1; k < columns; k+=2)
//                     {
//                         for(long long int m = 0; m < rows; m++)
//                         {
//                             if(parity.at(m).at(k) == parity.at(i).at(j))
//                             {
//                                 invalid = true; 
//                                 break; 
//                             }
//                         }
//                     }
//                     for(long long int k = j-1; k >= 0; k-=2)
//                     {
//                         for(long long int m = 0; m < rows; m++)
//                         {
//                             if(parity.at(m).at(k) == parity.at(i).at(j))
//                             {
//                                 cout << "This was triggered" << endl; 
//                                 cout << "k: " << k << endl; 
//                                 cout << "m: " << m << endl; 
//                                 cout << "i: " << i << endl; 
//                                 cout << "j: " << j << endl; 
//                                 invalid = true; 
//                                 break; 
//                             }
//                         }
//                     }

//                     //if not invalid, assign parity by column 
//                     long long int parityToAssign = parity.at(i).at(j); 
//                     if(!invalid)
//                     {
//                         cout << "assigning parity" << endl; 
//                         for(long long int k = j; k < columns; k+=2)
//                         {
//                             for(long long int l = 0; l < rows; l++)
//                             {
//                                 parity.at(l).at(k) = parityToAssign; 
//                             }
//                         }
//                         for(long long int k = j; k >= 0; k-=2)
//                         {
//                             for(long long int l = 0; l < rows; l++)
//                             {
//                                 parity.at(l).at(k) = parityToAssign; 
//                             }
//                         }
//                         break; 
//                     }
//                 }
//             }

//             if(sameRow || sameCol)
//             {
//                 break; 
//             }
//         }

//         if(sameRow || sameCol)
//         {
//                 break; 
//         }
//     }

//    cout << endl; 
//    cout << "After edit" << endl; 
//     for(long long int i = 0; i < rows; i++)
//     {
//         for(long long int j = 0; j < columns; j++)
//         {
//             cout << parity.at(i).at(j) << " "; 
//         }
//         cout << endl; 
//     }

//     //Idea: take the smallest possible value at each choice
//     //Check all 4 corners for parity - if they all agree, pick the smallest value that is increasing both row and column wise and has opposite parity
//     bool invalidInput = false; 

//     for(long long int i = 0; i < rows; i++)
//     {
//         for(long long int j = 0; j < columns; j++)
//         {
//             //Check parity dictated by corners - if there is an invalid setup, return -1
//             bool parityAgrees = true;
//             long long int  cornerParity = 2; //0 for even, 1 for odd  
//             //Check upper left
//             if(i != 0 && j != 0)
//             {
//                 if(checkerboard.at(i-1).at(j-1) != 0)
//                 {
//                     if(cornerParity == 2)
//                     {
//                         cornerParity = checkerboard.at(i-1).at(j-1) % 2; 
//                     }
//                     else
//                     {
//                         if(cornerParity != checkerboard.at(i-1).at(j-1) % 2)
//                         {
//                             parityAgrees = false; 
//                         }
//                     }
//                 }
//             }
//             //Check upper right
//             if(i != 0 && j != (columns - 1))
//             {
//                 if(checkerboard.at(i-1).at(j+1) != 0)
//                 {
//                     if(cornerParity == 2)
//                     {
//                         cornerParity = checkerboard.at(i-1).at(j+1) % 2; 
//                     }
//                     else
//                     {
//                         if(cornerParity != checkerboard.at(i-1).at(j+1) % 2)
//                         {
//                             parityAgrees = false; 
//                         }
//                     }
//                 }
//             }
//             //Check lower left
//             if(i != (rows - 1) && j != 0)
//             {
//                 if(checkerboard.at(i+1).at(j-1) != 0)
//                 {
//                     if(cornerParity == 2)
//                     {
//                         cornerParity = checkerboard.at(i+1).at(j-1) % 2; 
//                     }
//                     else
//                     {
//                         if(cornerParity != checkerboard.at(i+1).at(j-1) % 2)
//                         {
//                             parityAgrees = false; 
//                         }
//                     }
//                 }
              
//             }
//             //Check lower right
//             if(i != (rows - 1) && j != (columns - 1))
//             {
//                 if(checkerboard.at(i+1).at(j+1) != 0)
//                 {
//                     if(cornerParity == 2)
//                     {
//                         cornerParity = checkerboard.at(i+1).at(j+1) % 2; 
//                     }
//                     else
//                     {
//                         if(cornerParity != checkerboard.at(i+1).at(j+1) % 2)
//                         {
//                             parityAgrees = false; 
//                         }
//                     }
//                 }
//             }

//             if(!parityAgrees)
//             {
//                 cout << -1 << endl; 
//                 //cout << "Invalid case 1" << endl; 
//                 //cout << "Row: " << i << " Column: " << j << endl; 
//                 invalidInput = true; 
//                 break; 
//             }
//             else
//             {
//                 if(checkerboard.at(i).at(j) != 0)
//                 {
//                     if(checkerboard.at(i).at(j) % 2 == cornerParity)
//                     {
//                         cout << -1 << endl; 
//                         //cout << "Invalid case 2" << endl; 
//                         //cout << "Row: " << i << " Column: " << j << endl; 
//                         invalidInput = true; 
//                         break; 
//                     }
//                 }
//                 else
//                 {
//                     long long int nextSmallestValue;
//                     if(i == 0 && j == 0)
//                     {
//                         nextSmallestValue = 1; 
//                     }
//                     else if(i == 0)
//                     {
//                         nextSmallestValue = checkerboard.at(i).at(j-1) + 1; 
//                     }
//                     else if(j == 0)
//                     {
//                         nextSmallestValue = checkerboard.at(i-1).at(j) + 1; 
//                     }
//                     else
//                     {
//                         nextSmallestValue = checkerboard.at(i-1).at(j) + 1; 
//                         if(nextSmallestValue < (checkerboard.at(i).at(j-1) + 1))
//                         {
//                             nextSmallestValue = checkerboard.at(i).at(j-1) + 1; 
//                         }
//                     }

//                     if(nextSmallestValue % 2 == cornerParity)
//                     {
//                         nextSmallestValue++; 
//                     }

//                     //Check increasing property
//                     bool increasingValid = true; 
//                     if(i != (rows - 1))
//                     {
//                         if(nextSmallestValue >= checkerboard.at(i+1).at(j) && checkerboard.at(i+1).at(j) != 0)
//                         {
//                             increasingValid = false; 
//                         }
//                     }
//                     if(j != (columns - 1))
//                     {
//                         if(nextSmallestValue >= checkerboard.at(i).at(j+1) && checkerboard.at(i).at(j+1) != 0)
//                         {
//                             increasingValid = false; 
//                         }
//                     }
//                     if(!increasingValid)
//                     {
//                         cout << -1 << endl; 
//                         //cout << "Invalid case 3" << endl; 
//                         //cout << "Row: " << i << " Column: " << j << endl; 
//                         invalidInput = true; 
//                         break; 
//                     }
//                     else
//                     {
//                         checkerboard.at(i).at(j) = nextSmallestValue; 
//                     }
//                 }
//             }

//         }
//         if(invalidInput)
//         {
//             break; 
//         }
//     }

//     if(!invalidInput)
//     {
//         long long int sum = 0; 
//         for(long long int i = 0; i < rows; i++)
//         {
//             for(long long int j = 0; j < columns; j++)
//             {
//                 sum += checkerboard.at(i).at(j); 
//             }
//         }
//         cout << sum << endl; 
//     }