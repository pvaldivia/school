//video.cpp
//Valdivia, Pedro
//pvaldivia1

#include"video.h"

using namespace std;

//CLASS CONSTRUCTOR THAT INITIALIZES ALL MEMBER VARIABLES
Video::Video(string title,string url, string comment,double video_length,int rating)
{
    video_title = title;
    video_url = url;
    video_comment = comment;
    video_video_length = video_length;
    video_rating = rating;
}
//PRINT FUNCTION THAT PRINTS THE MEMBER VARIABLES 
void Video::print()
{
    cout << video_title << ", " << video_url << ", " << video_comment << ", " << video_video_length << ", ";
    for (int i = 0; i < video_rating; i++)
    {
        cout << "*";
    }
    cout<<"\n";
}
//LENGTH FUNCTION THAT RETURNS TRUE OR FALSE
bool Video::sort_length(Video *other)
{
    return (video_video_length > other->video_video_length);
}
//TITLE FUNCTION THAT RETURNS THE MEMBER VARIABLE "video_title"
string Video::get_title()
{
    return video_title;
}
//RATING FUNCTION THAT RETURNS THE MEMBER VARIABLE "video_rating"
int Video::return_rating()
{
    return video_rating;
}
