#include <iostream>
#include <string>
#include <sstream> 
#include <vector>
#include <math.h>
#include <algorithm> 
#include <float.h>

using namespace std; 

struct sprinkler
{
    long double position; 
    long double radius; 
};

struct coverageRectangle
{
    long double start; 
    long double end; 
}; 

main()
{
    //Take in input
    string input;
    getline(cin, input);
    while(input != "")
    {
        long double numSprinklers; 
        long double length; 
        long double width; 
        stringstream caseInput(input); 
        caseInput >> numSprinklers; 
        caseInput >> length; 
        caseInput >> width; 

        vector<sprinkler> sprinklers; 
        for(int i = 0; i < numSprinklers; i++)
        {
            long double position; 
            long double radius; 
            cin >> position;
            cin >> radius; 

            sprinkler newSprinkler; 
            newSprinkler.position = position; 
            newSprinkler.radius = radius; 
            sprinklers.push_back(newSprinkler); 
        }

        // cout << numSprinklers << " " << length << " " << width << endl; 
        // for(int i = 0; i < numSprinklers; i++)
        // {
        //     cout << sprinklers.at(i).position << " " << sprinklers.at(i).radius << endl; 
        // }

        //IDEA: Each circle only fully covers a rectangle of height w - any portion that is only partially covered will need another circle to cover it, 
        // and since all sprinklers are along the same axis, it will have to cover it by its own rectangle in order to fully cover it. Thus, only the rectangles of full coverage are 
        //relevant. 
        // After reading in input, translate circles into covered rectangles (note that any circles smaller than the width of the grass will have no fully covered rectangles, and
        // will be left out).
        // With the rectagles, we can use our previous interval algorithm. 

        
        //Convert vector of circles into vectors of rectangles
        vector<coverageRectangle> rectangles; 
        for(int i = 0; i < numSprinklers; i++)
        {
            //Check if circle is at least as large as the width of the grass
            if(sprinklers.at(i).radius > (width/2))
            {
                //Calculate x, the distance from the center of the circle to the left/right sides of the rectangle
                long double x = sqrt(pow(sprinklers.at(i).radius, 2) - pow((width / 2), 2)); 

                //Store the start of the rectange (sprinkler position - x) and the end (sprinkler postion + x)
                coverageRectangle newRectangle; 
                newRectangle.start = (sprinklers.at(i).position - x); 
                newRectangle.end = (sprinklers.at(i).position + x); 

                rectangles.push_back(newRectangle); 
            }
        }

        //Perform interval choosing algorithm on rectangles
        //First, sort the vector 
        vector<coverageRectangle> sortedRectangles; 
        for(int i = 0; i < rectangles.size(); i++)
        {
            int indexOfEarliest = 0;
            long double earliestStart = DBL_MAX; 
            for(int j = 0; j < rectangles.size(); j++)
            {
                if(rectangles.at(j).start < earliestStart)
                {
                    earliestStart = rectangles.at(j).start; 
                    indexOfEarliest = j; 
                }
            }

            coverageRectangle copyRectangle; 
            copyRectangle.start = rectangles.at(indexOfEarliest).start; 
            copyRectangle.end = rectangles.at(indexOfEarliest).end; 
            sortedRectangles.push_back(copyRectangle); 
            rectangles.at(indexOfEarliest).start = DBL_MAX; 
        }

        //Next, starting from position 0, choose intervals such that they start before the current position and extend as far after it as possible
        long double currentCovered = 0; 
        int numIntervals = 0; 

        while(currentCovered < length)
        {
            long double nextIntervalEnd = -(DBL_MAX); 
            bool validIntervalFound = false; 
            for(int i = 0; i < sortedRectangles.size(); i++)
            {
                if(sortedRectangles.at(i).start < currentCovered)
                {
                    if(sortedRectangles.at(i).end > nextIntervalEnd && sortedRectangles.at(i).end > currentCovered)
                    {
                        nextIntervalEnd = sortedRectangles.at(i).end; 
                        validIntervalFound = true; 
                    }
                }
            }
        
            if(!validIntervalFound)
            {
                numIntervals = -1; 
                break; 
            }
            else
            {
                currentCovered = nextIntervalEnd; 
                numIntervals++; 
            }
        }
    
        cout << numIntervals << endl; 
        getline(cin, input);
        getline(cin, input); 
    }


    
}