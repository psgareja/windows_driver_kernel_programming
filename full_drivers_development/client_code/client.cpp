#include <windows.h>
#include <stdio.h>
#include "..\PriorityBooster\PriorityBoosterCommon.h"


HANDLE hDevice = CreateFile(L"\\\\.\\PriorityBooster", GENERIC_WRITE,
FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, 0, nullptr);
if (hDevice == INVALID_HANDLE_VALUE)
return Error("Failed to open device");
The Error function simply prints some text with the last error occurred:
int Error(const char* message) {
printf("%s (error=%d)\n", message, GetLastError());
return 1;
}


ThreadData data;
data.ThreadId = atoi(argv[1]); // command line first argument
data.Priority = atoi(argv[2]);


DWORD returned;
BOOL success = DeviceIoControl(hDevice,
IOCTL_PRIORITY_BOOSTER_SET_PRIORITY, // control code
&data, sizeof(data), // input buffer and length
nullptr, 0, // output buffer and length
&returned, nullptr);
if (success)
printf("Priority change succeeded!\n");
else
Error("Priority change failed!");
CloseHandle(hDevice);

int main(int argc, const char* argv[]) {
if (argc < 3) {
printf("Usage: Booster <threadid> <priority>\n");
return 0;
}