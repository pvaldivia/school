//video.h
//Valdivia, Pedro
//pvaldivia1

#ifndef VIDEO_H_
#define VIDEO_H_

#include<iostream>
#include<string>
using namespace std;

class Video
{
    public:
        Video(string title, string url, string comment, double video_length,int rating);
        void print();
        int return_rating();
        bool sort_length(Video*);
        string sort_title();
    private:
        string video_title;
        string video_url;
        string video_comment;
        double video_video_length;
        int video_rating;
};

#endif
