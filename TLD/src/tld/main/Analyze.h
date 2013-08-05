#ifndef Analyze_H_
#define Analyze_H_

#include <QThread>
#include <QSemaphore>
#include <QSettings>
#include <vector>
#include <QTextEdit>
#include <QMutex>
#include "AnalyzeGui.h"

extern "C" {
#include <ccv.h>
}

class Analyze
{
public:

    tld::AnalyzeGui *analyzeGui;

    Analyze(double fx, double fy, QTextEdit* aWin, std::string resultsDirectory, std::string mainWindowName, std::string secondaryWindowName) {
        analyzeGui = new tld::AnalyzeGui();
        numGroups = 0;
        numTrackers = 0;
        frameCount = 1;
        this->aWin = aWin;
        this->resultsDirectory = resultsDirectory;
        this->mainWindowName = mainWindowName;
        this->secondaryWindowName = secondaryWindowName;
        this->fx = fx;
        this->fy = fy;
    }
    ~Analyze();
    bool doWork();
    void initGui(int mainVideoX, int mainVideoY, int secondaryVideoX, int secondaryVideoY, std::string mainWindowName, std::string secondaryWindowName);


private:

    void debugAnalyze();


    bool groupInfo(std::string groupName);
    long startFrame(int trackerId);
    void getImage(long frame, std::string newImageName, int x, int y, int width, int height);
    bool trackerInfo(std::string trackerName);
    std::string getCommand();

    QTextEdit* aWin;

    std::map<std::string, int> trackerNameToId;
    std::map<std::string, int> groupNameToId;
    std::map<int, std::string> idToGroupName;
    std::map<int, std::string> idToTrackerName;
    std::map<int, int> trackersToGroupMap;
    std::vector< std::vector<int> > trackersPerGroup;
    std::vector< std::vector<std::string> > trackerResults;
    std::vector<long> startFrames;

    struct colors {
        int r;
        int g;
        int b;
    };

    std::vector< struct colors* > groupColors;

    int numTrackers;
    long frameCount;
    int numGroups;

    std::string resultsDirectory;
    std::string mainWindowName;
    std::string secondaryWindowName;

    double fx;
    double fy;
};

#endif /* Analyze_H_ */
