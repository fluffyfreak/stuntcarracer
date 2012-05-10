#include "dxstdafx.h"
#include "XBOXController.h"

// ctor - playerNumber 1<>4
CXBOXController::CXBOXController(const int playerNumber) : _isConnected(false)
{
	// Set the Controller Number
	_controllerNum = playerNumber - 1;
}

void CXBOXController::Update()
{
	// backup the current state
	memcpy(&_previousState, &_controllerState, sizeof(XINPUT_STATE));

	// Zeroise the state
	ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));

	// Get the state
	_isConnected = (XInputGetState(_controllerNum, &_controllerState) == ERROR_SUCCESS);
}

bool CXBOXController::IsConnected() const {
	return _isConnected;
}

void CXBOXController::Vibrate(const unsigned short leftVal, const unsigned short rightVal)
{
	// Create a Vibraton State
	XINPUT_VIBRATION Vibration;

	// Zeroise the Vibration
	ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));

	// Set the Vibration Values
	Vibration.wLeftMotorSpeed = leftVal;
	Vibration.wRightMotorSpeed = rightVal;

	// Vibrate the controller
	XInputSetState(_controllerNum, &Vibration);
}

bool CXBOXController::buttonDown( const int btn ) const {
	return (_controllerState.Gamepad.wButtons & btn) == btn;
}

bool CXBOXController::buttonPressed( const int btn ) const {
	return (_controllerState.Gamepad.wButtons & btn) && !(_previousState.Gamepad.wButtons & btn);
}

bool CXBOXController::buttonReleased( const int btn ) const {
	return !(_controllerState.Gamepad.wButtons & btn) && (_previousState.Gamepad.wButtons & btn);
}

bool CXBOXController::buttonHeld( const int btn ) const {
	return (_controllerState.Gamepad.wButtons & btn) && (_previousState.Gamepad.wButtons & btn);
}

bool CXBOXController::rightTriggerDown() const {
	return (_controllerState.Gamepad.bRightTrigger>0);
}
bool CXBOXController::rightTriggerPressed() const {
	return (_controllerState.Gamepad.bRightTrigger) && !(_previousState.Gamepad.bRightTrigger);
}
bool CXBOXController::rightTriggerReleased() const {
	return !(_controllerState.Gamepad.bRightTrigger) && (_previousState.Gamepad.bRightTrigger);
}
bool CXBOXController::rightTriggerHeld() const {
	return (_controllerState.Gamepad.bRightTrigger) && (_previousState.Gamepad.bRightTrigger);
}

bool CXBOXController::leftTriggerDown() const {
	return (_controllerState.Gamepad.bLeftTrigger>0);
}
bool CXBOXController::leftTriggerPressed() const {
	return (_controllerState.Gamepad.bLeftTrigger) && !(_previousState.Gamepad.bLeftTrigger);
}
bool CXBOXController::leftTriggerReleased() const {
	return !(_controllerState.Gamepad.bLeftTrigger) && (_previousState.Gamepad.bLeftTrigger);
}
bool CXBOXController::leftTriggerHeld() const {
	return (_controllerState.Gamepad.bLeftTrigger) && (_previousState.Gamepad.bLeftTrigger);
}