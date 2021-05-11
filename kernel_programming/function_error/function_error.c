NTSTATUS DoWork() {
NTSTATUS status = CallSomeKernelFunction();
if(!NT_SUCCESS(Statue)) {
KdPirnt((L"Error occurred: 0x%08X\n", status));
return status;
}
// continue with more operations
return STATUS_SUCCESS;
}