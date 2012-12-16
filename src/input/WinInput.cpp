#ifdef _WIN32
#include <core/PhantomGame.h>
#include "WinInput.h"

namespace phantom {
    WinInput::WinInput(PhantomGame *game) : Input(game) {
        /* Optional RAW Input for later on 
        unsigned int puiNumDevices;
        GetRawInputDeviceList(nullptr, &puiNumDevices, sizeof(RAWINPUTDEVICELIST));
        PRAWINPUTDEVICELIST *deviceList = new PRAWINPUTDEVICELIST[puiNumDevices];
        GetRawInputDeviceList(*deviceList, &puiNumDevices, sizeof(RAWINPUTDEVICELIST));
        
        unsigned int i = 0;
        for(; i < puiNumDevices; ++i) {
            if(deviceList[i]->dwType == RIM_TYPEMOUSE) {
                RID_DEVICE_INFO_MOUSE *pData;
                UINT size = sizeof(RID_DEVICE_INFO_MOUSE);
                GetRawInputDeviceInfo(deviceList[i]->hDevice, RIDI_DEVICEINFO, pData, &size);
                break;
            }
        }
        delete[] deviceList;
        /**/
    }

    void WinInput::checkForChanges() {
        GetKeyboardState(_keyboardState->getBuffer());
        /* Need a Win32 window handle for mouse */
    }
}

#endif