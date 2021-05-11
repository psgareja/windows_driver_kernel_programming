BOOL WINAPI DeviceIoControl(
_In_ HANDLE hDevice,
_In_ DWORD dwIoControlCode,
_In_reads_bytes_opt_(nInBufferSize) LPVOID lpInBuffer,
_In_ DWORD nInBufferSize,
_Out_writes_bytes_to_opt_(nOutBufferSize,*lpBytesReturned) LPVOID lpOutBuffer,
_In_ DWORD nOutBufferSize,
_Out_opt_ LPDWORD lpBytesReturned,
_Inout_opt_ LPOVERLAPPED lpOverlapped);

DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = PriorityBoosterDeviceControl;