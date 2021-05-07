//Accessing windows kernel object from process explorer
bool KillProcess(DWORD pid)
{
   HANDLE hProcess == OpenProcess(PROCESS_TERMINATE, FALSE, pid);
   if (!hProcess)
        return false;
    BOOL success = TerminateProcess(hProcess, 1);
    CloseHandle(hProcess);
    return success !=FALSE;
    
}