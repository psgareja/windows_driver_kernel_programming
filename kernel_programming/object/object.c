HANDLE hDevice = CreateFile(L"\\\\.\\PROCEXP152",
GENERIC_WRITE | GENERIC_READ, 0, nullptr, OPEN_EXISTING, 0, nullptr);