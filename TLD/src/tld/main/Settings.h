/* Modified by Anshul Samar
 * Previous Credits:
*  Copyright 2011 AIT Austrian Institute of Technology
*
*   This file is part of OpenTLD.
*
*   OpenTLD is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   OpenTLD is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with OpenTLD.  If not, see <http://www.gnu.org/licenses/>.
*
*/

/**
 * @author Clemens Korner
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

using std::string;

extern "C" {
#include <ccv.h>
}

class Settings
{
public:

    Settings();
    ~Settings();

    //Settings comments from libccv documentation for tld

    /* short-term lucas-kanade tracking parameters */
    int win_size_width; //these are the parts of the ccv_size_t struct that we need user to input
    int win_size_height;
    int level;
    float min_eigen;
    float min_forward_backward_error;
    /* image pyramid (different resolution) generation parameters */
    int interval;
    float shift;
    /* samples generation parameters */
    int min_win;
    float include_overlap;
    float exclude_overlap;
    /* fern classifier setting */
    int structs;
    int features;
    /* nearest neighbor thresholds */
    float validate_set; // 0.5 for conservative confidence
    float nnc_same; // the same object
    float nnc_thres; // highly correlated
    float nnc_verify; // correlated with tracking
    float nnc_beyond; // this is the cap of nnc_thres
    float nnc_collect; // modest correlated, worth to collect as negative example
    int bad_patches; // number of bad patches
    /* deformation round */
    int new_deform;
    int track_deform;
    float new_deform_angle;
    float track_deform_angle;
    float new_deform_scale;
    float track_deform_scale;
    float new_deform_shift;
    float track_deform_shift;
    /* top detections */
    int top_n;
    /* speed up technique, instead of running slide window at
     * every frame, we will rotate them, for example, slide window 1
     * only gets examined at frame % rotation == 1 */
    int rotation;

    //images to be tracked
    std::string m_trackImagesPath;

    //tracked images to be played in analysis
    std::string m_analysisImagesPath;

    //where tracked images and csv files will be saved
    std::string m_resultsDirectory;

    //true or false based on what user wishes to do
    bool m_track;
    bool m_saveResults;
    bool m_analyze;

};


#endif /* SETTINGS_H */
