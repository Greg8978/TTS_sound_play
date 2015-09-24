#include <iostream>

#include <sound_play/sound_play.h>

#include <ros/ros.h>
#include "ros/package.h"


sound_play::SoundClient* soundClient_;

void verbalize(std::string sentence, unsigned int time) {
    soundClient_->say(sentence);
    printf("[saying] %s\n", sentence.c_str());
    sleep(time);
}

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{

  verbalize(msg->data, 10);    

}


int main(int argc, char ** argv) {


    ros::init(argc, argv, "TTS_sound_play");

    ros::NodeHandle n;

    sound_play::SoundClient soundClient;
    soundClient_ = &soundClient;

    ros::Subscriber sub = n.subscribe("chat_bot/speech", 1000, chatterCallback);
    
    ros::spin();

    return 0;
}
