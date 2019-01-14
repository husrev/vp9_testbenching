#ifndef VP9_FINETUNING
#define VP9_FINETUNING

#include <string>
#include <chrono>

#define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

class experiment{

    private:
    
        std::string const coeffsFile = "coefficients.txt";
        int startAngle = 0;
        int tCoeffs[32] =
        {
            16098,15304,14102,12539,11960,11718,13815,12187,4760,13267,11646,13696,12204,12559,9450,9457,
            3049,5850,8342,10545,11198,11451,8808,10951,15677,9614,11524,8992,10932,10521,13384,13379
        };

    public:

        experiment(bool resume);
        std::string process(std::string binary, std::string exp1, std::string dir);
        long double getBDBR(std::string baseline, std::string exp1);
        bool writeCoefficients();
        int getAngle(int angle){return tCoeffs[angle];}
        int getStartAngle(){return startAngle;}
        void setAngle(int angle, int value) {tCoeffs[angle] = value;}
};

const int max_buffer = 4096;

struct vseq
{
    std::string name;
    std::string dims;
    std::string fps;
};

struct vseq files[] = {
    {"Beauty_3840x2160.yuv","--width=3840 --height=2160","120"}, // 4K Videos
    {"Bosphorus_3840x2160.yuv","--width=3840 --height=2160","120"},  
    {"HoneyBee_3840x2160.yuv","--width=3840 --height=2160","120"},
    {"Jockey_3840x2160.yuv","--width=3840 --height=2160","120"},
    {"ReadySteadyGo_3840x2160.yuv","--width=3840 --height=2160","120"},
    {"ShakeNDry_3840x2160.yuv","--width=3840 --height=2160","120"},
    {"YachtRide_3840x2160.yuv","--width=3840 --height=2160","120"},
//        {"Traffic_2560x1600_30_crop.yuv","--width=2560 --height=1600","30"}, // Class A 2560x1600 :
//        {"PeopleOnStreet_2560x1600_30_crop.yuv","--width=2560 --height=1600","30"},
////        {"NebutaFestival_2560x1600_60_10bit_crop.yuv","--width=2560 --height=1600","60"},
////        {"SteamLocomotiveTrain_2560x1600_60_10bit_crop.yuv","--width=2560 --height=1600","60"},
//        {"Kimono1_1920x1080_24.yuv","--width=1920 --height=1080","24"}, // Class B  1920x1080 : 
//        {"ParkScene_1920x1080_24.yuv","--width=1920 --height=1080","24"},
//        {"Cactus_1920x1080_50.yuv","--width=1920 --height=1080","50"},
//        {"BQTerrace_1920x1080_60.yuv","--width=1920 --height=1080","60"},
//       {"BasketballDrive_1920x1080_50.yuv","--width=1920 --height=1080","50"},
//        {"RaceHorses_832x480_30.yuv","--width=832 --height=480","30"}, // Class C 832x480 :  
//      {"BQMall_832x480_60.yuv","--width=832 --height=480","60"},
//      {"PartyScene_832x480_50.yuv","--width=832 --height=480","50"},
//      {"BasketballDrillText_832x480_50.yuv","--width=832 --height=480","50"},
//        {"RaceHorses_416x240_30.yuv","--width=416 --height=240","30"}, // Class D 416x240 :
//        {"BQSquare_416x240_60.yuv","--width=416 --height=240","60"},
//      {"BlowingBubbles_416x240_50.yuv","--width=416 --height=240","50"},
//      {"BasketballPass_416x240_50.yuv","--width=416 --height=240","50"},
//        {"FourPeople_1280x720_60.yuv","--width=1280 --height=720","60"}, // Class E 1280x720 :
//      {"Johnny_1280x720_60.yuv","--width=1280 --height=720","60"},
//      {"KristenAndSara_1280x720_60.yuv","--width=1280 --height=720","60"}//,
////        {"BasketballDrillText_832x480_50.yuv","--width=832 --height=480","50"}, // Class F mixed:
////        {"ChinaSpeed_1024x768_30.yuv","--width=1024 --height=768","30"},
////        {"SlideEditing_1280x720_30.yuv","--width=1280 --height=720","30"},
////        {"SlideShow_1280x720_20.yuv","--width=1280 --height=720","20"}
    };
    
    /*
    struct vseq files[] = 
    {
        {"Beauty_3840x2160.yuv","--width=3840 --height=2160","120"}
    };
    */

#endif
