//main.cpp
//Valdivia, Pedro
//pvaldivia1

#include"video.h"
#include<algorithm>
#include<set>
#include<stdlib.h>

using namespace std;
const int MAX_VIDEOS = 100;

int main()
{
//DECLARATION OF VARIABLES
    Video *video_object[MAX_VIDEOS];
    string sorting_method;
    string title;
    string url;
    string comment;
    double videoLength;
    int rating;
    int num_videos = 0;
//SETS THE VALUES IN THE ARRAY TO NOTHING
    for (int i = 0; i < MAX_VIDEOS; i++)
    {
        video_object[i] = NULL;
    }
//USER INPUT FOR SORTING METHOD
    cin >> sorting_method;
    cin.ignore();
    if (sorting_method != "rating" && sorting_method != "length" && sorting_method != "title")
    {
        cerr << sorting_method << " is not a legal sorting method, giving up.\n";
        return 1;
        exit(EXIT_FAILURE);
    }
//START OF WHILE LOOP TO READ ALL USER INPUT 
    while (getline(cin,title))
    {
        getline(cin,url);
        getline(cin,comment);
        cin >> videoLength;
        cin >> rating;
        //STORING THE ADDRESS OF THE TEMPORARY POINTER THAT POINT TO A VIDEO OBJECT
        video_object[num_videos] = new Video (title,url,comment,videoLength,rating);
        //COUNTS THE AMOUNT OF VIDEOS STORED
        num_videos++;
        cin.ignore();

        if (num_videos > MAX_VIDEOS)
        {
            cerr<<"Too many videos, giving up.\n";
            return 1;
            exit(EXIT_FAILURE);
        }

    }
//END OF WHILE LOOP AND START OF SORTING THE VIDEOS IN THE CORRECT ORDER

    
//SORTS THE VIDEOS IN ORDER FROM BIGGEST TO SMALLEST BASED ON RATING
    if (sorting_method == "rating" || sorting_method == "Rating")
    {
        for (int last = num_videos-1; last > 0; last--)
        {
            for (int current = 0; current < last; current++)
            {
                if (video_object[current]->return_rating() < video_object[current+1]->return_rating())
                {
                    swap(video_object[current],video_object[current+1]);
                }
            }
        }
    }
//SORTS THE VIDEOS IN ODER FROM SMALLEST TO BIGGEST BASED ON LENGTH OF VIDEO
    else if (sorting_method == "length" || sorting_method == "Length")
    {
        for (int last = num_videos-1; last > 0; last--)
        {
            for (int current = 0; current < last; current++)
            {
                if (video_object[current]->sort_length(video_object[current+1]))
                {
                    swap(video_object[current],video_object[current+1]);
                }
            }
        }
    }
//SORTS THE VIDEOS IN ORDER FROM SMALLES TO BIGGEST BASED ON ALPHABETICAL ORDER
    else if (sorting_method == "title" || sorting_method == "Title")
    {
        for (int last = num_videos-1; last > 0; last--)
        {
            for (int current = 0; current < last; current++)
            {
                if (video_object[current]->sort_title() > video_object[current+1]->sort_title())
                {
                    swap(video_object[current],video_object[current+1]);
                }
            }
        }
    }
//PRINTS EACH VIDEO OBJECT IN CORRECT ORDER
    for (int i = 0; i < num_videos; i++)
    {
        //cout << "video_object[" << i << "] = ";
        video_object[i]->print();
    }

    return 0;

}
