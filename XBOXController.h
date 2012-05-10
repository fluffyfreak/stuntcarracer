#ifndef _XBOX_CONTROLLER_H_
#define _XBOX_CONTROLLER_H_

// No MFC
#define WIN32_LEAN_AND_MEAN

// We need the Windows Header and the XInput Header
#include <windows.h>
#include <XInput.h>

// Now, the XInput Library
// NOTE: COMMENT THIS OUT IF YOU ARE NOT USING A COMPILER THAT SUPPORTS THIS METHOD OF LINKING LIBRARIES
#pragma comment(lib, "XInput.lib")

// XBOX Controller Class Definition
class CXBOXController
{
private:
	XINPUT_STATE _controllerState;
	XINPUT_STATE _previousState;
	int _controllerNum;
	bool _isConnected;
public:
	// ctor - playerNumber 1<>4
	CXBOXController(const int playerNumber);
	void Update();
	bool IsConnected() const;
	void Vibrate(const unsigned short leftVal = 0, const unsigned short rightVal = 0);

	bool buttonDown( const int btn ) const;
	bool buttonPressed( const int btn ) const;
	bool buttonReleased( const int btn ) const;
	bool buttonHeld( const int btn ) const;

	bool rightTriggerDown() const;
	bool rightTriggerPressed() const;
	bool rightTriggerReleased() const;
	bool rightTriggerHeld() const;

	bool leftTriggerDown() const;
	bool leftTriggerPressed() const;
	bool leftTriggerReleased() const;
	bool leftTriggerHeld() const;

	SHORT thumbLX() const { return _controllerState.Gamepad.sThumbLX; }
	SHORT thumbLY() const { return _controllerState.Gamepad.sThumbLY; }
	SHORT thumbRX() const { return _controllerState.Gamepad.sThumbRX; }
	SHORT thumbRY() const { return _controllerState.Gamepad.sThumbRY; }
};

#endif