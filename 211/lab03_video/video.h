#ifndef VIDEO_H_
#define VIDEO_H_

#include<iostream>
#include<string>
using namespace std;

class Video 
{
    public:
       Video(string title,string url,string comment,float video_length, int rating);
       void print();
    private:
        string video_title;
        string video_url;
        string video_comment;
        float video_video_length;
        int video_rating;
};

#endif
