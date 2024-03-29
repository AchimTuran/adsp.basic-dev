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
 *  along with KODI; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "kodi/threads/threads.h"
#include "kodi/threads/mutex.h"

#define SOUND_TEST_OFF              0
#define SOUND_TEST_PINK_NOICE       1
#define SOUND_TEST_VOICE            2

#define CONTINUES_PINK_NOISE_TIME   2
#define CONTINUES_SOUND_TEST_TIME   2

using namespace PLATFORM;

class cPinkNoise;
class CGUIDialogSpeakerGain;

class cDSPProcessorSoundTest
{
public:
  cDSPProcessorSoundTest(unsigned long outChannelPresentFlags, CGUIDialogSpeakerGain *cbClass);
  ~cDSPProcessorSoundTest();

  void SetTestMode(int mode, AE_DSP_CHANNEL channel, bool continues);
  void SetTestVolume(float volume);
  unsigned int ProcessTestMode(float **array_in, float **array_out, unsigned int samples);

private:
  AE_DSP_CHANNEL GetNextChannelPtr(AE_DSP_CHANNEL previous);

  AE_DSP_CHANNEL    m_currentTestPointer;
  int               m_currentTestMode;
  bool              m_currentTestContinues;
  time_t            m_lastContinuesChange;
  unsigned long     m_OutChannelPresentFlags;
  cPinkNoise       *m_NoiseSource;
  CAddonSoundPlay  *m_TestSound;
  PLATFORM::CMutex  m_Mutex;
  CGUIDialogSpeakerGain *m_ContinueTestCBClass;
};
