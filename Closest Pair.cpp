#include <iostream>
#include <vector> 
#include <float.h>
#include <math.h>
#include <algorithm> 

using namespace std; 

struct point
{
    long double x; 
    long double y;
};

vector<point> points; 

bool compareX(point &a, point &b)
{
    return a.x < b.x; 
}

bool compareIndexY(int &a, int &b)
{
    return points.at(a).y < points.at(b).y; 
}

vector<point> recursiveSearch(vector<int> searchPoints)
{
    //Divide: Will divide the points into two halfs along the midpoint
    //If we have an even number of points, we will take the division line between the two center points
    //If it is odd, we will take the average between the center point and the next point

    //Base case - stop dividing
    if((searchPoints.at(1) - searchPoints.at(0)) + 1 == 3) 
    {
        //Calculate distances
        long double dist1 = sqrt(pow((points.at(searchPoints.at(0)).x - points.at(searchPoints.at(0)+1).x), 2)+pow((points.at(searchPoints.at(0)).y - points.at(searchPoints.at(0)+1).y), 2));
        long double dist2 = sqrt(pow((points.at(searchPoints.at(0)).x - points.at(searchPoints.at(0)+2).x), 2)+pow((points.at(searchPoints.at(0)).y - points.at(searchPoints.at(0)+2).y), 2));
        long double dist3 = sqrt(pow((points.at(searchPoints.at(0)+1).x - points.at(searchPoints.at(0)+2).x), 2)+pow((points.at(searchPoints.at(0)+1).y - points.at(searchPoints.at(0)+2).y), 2));
 
        vector<point> closestPoints; 
        if(dist1 <= dist2 && dist1 <= dist3)
        {
            closestPoints.push_back(points.at(searchPoints.at(0)));
            closestPoints.push_back(points.at(searchPoints.at(0)+1));
        }
        else if(dist2 <= dist1 && dist2 <= dist3)
        {
            closestPoints.push_back(points.at(searchPoints.at(0)));
            closestPoints.push_back(points.at(searchPoints.at(0)+2));
        }
        else
        {
            closestPoints.push_back(points.at(searchPoints.at(0)+1));
            closestPoints.push_back(points.at(searchPoints.at(0)+2));
        }

        return closestPoints; 
    }
    else //Recursively divide
    {
        // vector<point> leftDivision; 
        // for(int i = 0; i < (searchPoints.size()/2); i++)
        // {
        //     leftDivision.push_back(searchPoints.at(i)); 
        // }

        // vector<point> rightDivision; 
        // for(int i = (searchPoints.size()/2); i < searchPoints.size(); i++)
        // { 
        //     rightDivision.push_back(searchPoints.at(i));
        // }

        // vector<point> closestLeft = recursiveSearch(leftDivision);
        // vector<point> closestRight = recursiveSearch(rightDivision);
        vector<int> leftIndexes; 
        leftIndexes.push_back(searchPoints.at(0)); 
        leftIndexes.push_back((searchPoints.at(1)+searchPoints.at(0))/2);

        vector<int> rightIndexes; 
        rightIndexes.push_back(((searchPoints.at(1)+searchPoints.at(0))/2)+1);
        rightIndexes.push_back(searchPoints.at(1));

        vector<point> closestLeft = recursiveSearch(leftIndexes);
        vector<point> closestRight = recursiveSearch(rightIndexes);

        //Calculate shortest distances from left and right
        long double shortestLeft =  sqrt(pow((closestLeft.at(0).x - closestLeft.at(1).x), 2)+pow((closestLeft.at(0).y - closestLeft.at(1).y), 2));
        long double shortestRight =  sqrt(pow((closestRight.at(0).x - closestRight.at(1).x), 2)+pow((closestRight.at(0).y - closestRight.at(1).y), 2));

        vector<point> currShortest; 

        //Take the shortest distance 
        long double shortestDistance; 
        if(shortestLeft < shortestRight)
        {
            shortestDistance = shortestLeft; 
            currShortest.push_back(closestLeft.at(0));
            currShortest.push_back(closestLeft.at(1));
        }
        else
        {
            shortestDistance = shortestRight; 
            currShortest.push_back(closestRight.at(0));
            currShortest.push_back(closestRight.at(1));
        }

        //Find shortest distance crossing the boundary
        //Find points shortestDistance to the left
        vector<int> potentialIndexes; 
        for(int i = searchPoints.at(0); i < ((searchPoints.at(1)+searchPoints.at(0))/2); i++)
        {
            if(points.at(i).x >= points.at((searchPoints.at(1)+searchPoints.at(0))/2).x - shortestDistance)
            {
                potentialIndexes.push_back(i);
            }
        }
        //Find points shortestDistance to the right
        for(int i = ((searchPoints.at(1)+searchPoints.at(0))/2); i < searchPoints.at(1); i++)
        {
            if(points.at(i).x <= points.at(((searchPoints.at(1)+searchPoints.at(0))/2)).x + shortestDistance)
            {
                potentialIndexes.push_back(i);
            }
        }

        //Compare and find smallest distance
        //sort potentialLeft and potentialRight by y
        //Mix arrays and compare to the next 12
        sort(potentialIndexes.begin(), potentialIndexes.end(), compareIndexY);


        // vector<point> mixedLeftRight; 
        // for(int i = 0; i < potentialLeft.size(); i++)
        // {
        //     mixedLeftRight.push_back(potentialLeft.at(i)); 
        // }
        // for(int i = 0; i < potentialRight.size(); i++)
        // {
        //     mixedLeftRight.push_back(potentialRight.at(i)); 
        // }
        //sort
        // vector<point> mixedLeftRightSorted; 
        // for(int i = 0; i < mixedLeftRightUnsorted.size(); i++)
        // {
        //     int indexOfSmallestY = 0;
        //     long double smallestY = DBL_MAX; 
        //     for(int j = 0; j < mixedLeftRightUnsorted.size(); j++)
        //     {
        //         if(mixedLeftRightUnsorted.at(j).x < smallestY)
        //         {
        //             smallestY = mixedLeftRightUnsorted.at(j).y; 
        //             indexOfSmallestY = j; 
        //         }
        //     }

        //     point copyPoint; 
        //     copyPoint.x = mixedLeftRightUnsorted.at(indexOfSmallestY).x; 
        //     copyPoint.y = mixedLeftRightUnsorted.at(indexOfSmallestY).y; 
        //     mixedLeftRightSorted.push_back(copyPoint); 
        //     mixedLeftRightUnsorted.at(indexOfSmallestY).y = DBL_MAX; 
        // }
        //sort(mixedLeftRight.begin(), mixedLeftRight.end(), compareY); 

        //For each point, check the next 11 points
        long double shortestCrossingDistance = DBL_MAX;
        int shortestCrossingIndex1; 
        int shortestCrossingIndex2;
        for(int i = 0; i < potentialIndexes.size(); i++)
        {
            for(int j = 0; j < 7; j++)
            {
                if((i+j) < potentialIndexes.size())
                {
                    long double tempDist = sqrt(pow(points.at(potentialIndexes.at(i)).x - points.at(potentialIndexes.at(j)).x, 2)+pow((points.at(potentialIndexes.at(i)).y - points.at(potentialIndexes.at(j)).y), 2));
                    if(tempDist < shortestCrossingDistance)
                    {
                        shortestCrossingDistance = tempDist; 
                        shortestCrossingIndex1 = i; 
                        shortestCrossingIndex2 = j; 
                    }
                }
            }
        }




        // long double shortestCrossingDistance = DBL_MAX;
        // int leftShortestCrossingIndex; 
        // int rightShortestCrossingIndex; 
        // for(int i = 0; i < leftDivision.size(); i++)
        // {
        //     for(int j = 0; j < rightDivision.size(); j++)
        //     {
        //         long double tempDist = sqrt(pow((leftDivision.at(i).x - rightDivision.at(j).x), 2)+pow((leftDivision.at(i).y - rightDivision.at(j).y), 2));
        //         if(tempDist < shortestCrossingDistance)
        //         {
        //             shortestCrossingDistance = tempDist; 
        //             leftShortestCrossingIndex = i; 
        //             rightShortestCrossingIndex = j; 
        //         }
        //     }
        // }

        if(shortestCrossingDistance < shortestDistance)
        {
            shortestDistance = shortestCrossingDistance; 
            currShortest.clear(); 
            currShortest.push_back(points.at(potentialIndexes.at(shortestCrossingIndex1))); 
            currShortest.push_back(points.at(potentialIndexes.at(shortestCrossingIndex2))); 
        }
        return currShortest;  
    }
}

main()
{
    //Take in input
    int n; 
    cin >> n; 

    while(n != 0)
    {
        for(int i = 0; i < n; i++)
        {
            point tempPoint; 
            cin >> tempPoint.x; 
            cin >> tempPoint.y; 
            points.push_back(tempPoint); 
        }

        //Edge case - only 2 points
        if(n == 2)
        {
            cout << points.at(0).x << " " << points.at(0).y << " " <<  points.at(1).x << " " << points.at(1).y << endl; 
        }
        else
        {
            //First, sort points by x values
            // vector<point> sortedPoints; 
            // for(int i = 0; i < points.size(); i++)
            // {
            //     int indexOfSmallestX = 0;
            //     long double smallestX = DBL_MAX; 
            //     for(int j = 0; j < points.size(); j++)
            //     {
            //         if(points.at(j).x < smallestX)
            //         {
            //             smallestX = points.at(j).x; 
            //             indexOfSmallestX = j; 
            //         }
            //     }

            //     point copyPoint; 
            //     copyPoint.x = points.at(indexOfSmallestX).x; 
            //     copyPoint.y = points.at(indexOfSmallestX).y; 
            //     sortedPoints.push_back(copyPoint); 
            //     points.at(indexOfSmallestX).x = DBL_MAX; 
            // }

            sort(points.begin(), points.end(), compareX); 

            //Call recursive function on sorted array
            vector<int> searchIndexs; 
            searchIndexs.push_back(0); 
            searchIndexs.push_back(points.size()-1); 
            vector<point> closestPoints = recursiveSearch(searchIndexs);
            cout << closestPoints.at(0).x << " " << closestPoints.at(0).y << " " << closestPoints.at(1).x << " " << closestPoints.at(1).y << endl; 
         }
        points.clear(); 

        cin >> n; 
    }
}