//Approach - 1
//concept is that, we will traverse the given array.
//while traversing we keep track of how much fuel we have.
//so start an outer loop which defines the starting point(the index of starting
//petrol pump).
//the nested loop within it, marks the end point. so while trvaersing in the inner
//loop, if fuel becomes less than 0, then we know that we can't make the tour from our
//current starting point. we can also say that we can't make the tour from any point
//between the current starting point and current ending point. This is because 
//we will get stuck at the same ending point if we start from any point in between
//the current starting and ending point.
//so, what we do is take a new starting point from the next index from the 
//current ending point and start the traversing again.
//in case during traversing, if the ending point becomes the same as the starting point
//then we have found the answer. we return the starting point.
//during this process if we ever if the starting point ever becomes the same as the
//first starting point after we encountered the first ending point, then the process
//has started to repeat itself so we can say that no answer exists and hence return -1.
//this situation is taken care by using condition variable in our code.
//once the ending point crosses the last element and starts from the first element,
//now if we encounter an ending point then, it will be the same ending point that
//we first encountered. so the loop will start repeating itself and there will be no
//solution. that si why once we cross n-1 to come back at 0, we make condition true.

//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       long long int fuel = 0;
       int j;
       bool condition = false;
       for(int i=0; i<n; i++)
       {
           fuel = 0;
           j = i;
           for(; j<n;)
           {
               fuel += p[j].petrol;
               fuel -= p[j].distance;
               if(fuel<0)
               {
                   if(condition)
                    return -1;
                   i = j;
                   break;
               }
               j++;
               if(j==n)
               {
                   j=0;
                   condition = true;
               }
               if(i==j)
                return i;
           }
       }
       return -1;
    }
};



//Approach - 2
//same approach as approach-1, just different implementation.

//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        long long int fuel = 0;
        int start = 0;
        for(int i=0; i<n; i++)
        {
            fuel += p[i].petrol-p[i].distance;
            if(fuel<0)
            {
                while(p[i].petrol<p[i].distance)
                    i++;
                start = i;
                fuel = 0;
                i--;
            }
        }
        if(fuel<0)
            return -1;
        for(int i=0; i<start; i++)
        {
            fuel += p[i].petrol-p[i].distance;
            if(fuel<0)
                return -1;
        }
        return start;
        
    }
};



//Approach - 3
//we start by traversing the array.
//if the fuel(petrol-distance) ever drops below 0, then we add it to deficit, and 
//make fuel = 0 and make the next index as start point.
//whenever fuel<0, it means that we need -1*fuel amount of extra petrol to go from
//the current point to the next point.
//so we add this value to deficit.
//-1*deficit represents total amount of extra petrol required to cross all the points
//which we couldn't initially cross.
//make deficit = -1*deficit.
//now after the loop ends, if the value of fuel is less than deficit(i.e. extra fuel)
//required then, we don't have a solution and return -1
//else return the start point.

//this method requires only one traversal, whereas above two methods may require upto
//two traversals of the array.

//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int start = 0;
        long long int fuel = 0;
        long long int deficit = 0;
        for(int i=0; i<n; i++)
        {
            fuel += p[i].petrol - p[i].distance;
            if(fuel<0)
            {
                deficit += fuel;
                fuel = 0;
                start = i+1;
            }
        }
        deficit *= -1;
        if(fuel<deficit)
            return -1;
        return start;
            
    }
};