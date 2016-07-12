#include"video.h"
using namespace std;

Video::Video(string title,string url,string comment,float video_length,int rating)
{
    video_title = title;
    video_url = url;
    video_comment = comment;
    video_video_length = video_length;
    video_rating = rating;
}

void Video::print()
{
    cout << video_title << ", " << video_url << ", " << video_comment << ", " << video_video_length << ", ";
    for (int i = 0; i < video_rating; i++)
    {
        cout << "*";
    }
    cout<<"\n";
}
