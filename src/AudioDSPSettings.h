#pragma once
/*
 *      Copyright (C) 2005-2014 Team KODI
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with KODI; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */


#include <string>
#include <vector>
#include "client.h"
#include "AudioDSPBasic.h"

#define SPIN_CONTROL_SPEAKER_CH_FL      13
#define SPIN_CONTROL_SPEAKER_CH_FR      14
#define SPIN_CONTROL_SPEAKER_CH_FC      15
#define SPIN_CONTROL_SPEAKER_CH_LFE     16
#define SPIN_CONTROL_SPEAKER_CH_BL      17
#define SPIN_CONTROL_SPEAKER_CH_BR      18
#define SPIN_CONTROL_SPEAKER_CH_FLOC    19
#define SPIN_CONTROL_SPEAKER_CH_FROC    20
#define SPIN_CONTROL_SPEAKER_CH_BC      21
#define SPIN_CONTROL_SPEAKER_CH_SL      22
#define SPIN_CONTROL_SPEAKER_CH_SR      23
#define SPIN_CONTROL_SPEAKER_CH_TFL     24
#define SPIN_CONTROL_SPEAKER_CH_TFR     25
#define SPIN_CONTROL_SPEAKER_CH_TFC     26
#define SPIN_CONTROL_SPEAKER_CH_TC      27
#define SPIN_CONTROL_SPEAKER_CH_TBL     28
#define SPIN_CONTROL_SPEAKER_CH_TBR     29
#define SPIN_CONTROL_SPEAKER_CH_TBC     30
#define SPIN_CONTROL_SPEAKER_CH_BLOC    31
#define SPIN_CONTROL_SPEAKER_CH_BROC    32

class CAddonGUISpinControl;

struct sDSPSettings
{
  struct sDSPChannel
  {
    std::string strName;
    int iChannelNumber;
    int iVolumeCorrection;
    int iOldVolumeCorrection;
    int iDistanceCorrection;
    int iOldDistanceCorrection;
    CAddonGUISpinControl *ptrSpinControl;
  };

  struct sDSPFreeSurround
  {
    float           fInputGain;
    float           fDepth;
    float           fCircularWrap;
    float           fShift;
    float           fCenterImage;
    float           fFocus;
    float           fFrontSeparation;
    float           fRearSeparation;
    bool            bLFE;
    float           fLowCutoff;
    float           fHighCutoff;
  };

  sDSPChannel           m_channels[AE_DSP_CH_MAX];
  sDSPFreeSurround      m_FreeSurround;
};

class CDSPSettings
{
public:
  CDSPSettings();
  virtual ~CDSPSettings() {};

  static AE_DSP_CHANNEL TranslateGUIIdToChannelId(int controlId);
  static int TranslateChannelIdToStringId(int channel);

  bool LoadSettingsData(int settingId = -1, bool initial = false);
  bool SaveSettingsData();

  sDSPSettings m_Settings;
};

