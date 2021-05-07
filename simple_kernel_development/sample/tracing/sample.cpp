void SampleUnload(_In_ PDRIVER_OBJECT DriverObject) {
UNREFERENCED_PARAMETER(DriverObject);
KdPrint(("Sample driver Unload called\n"));
}

extern "C"
NTSTATUS
DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath) {
UNREFERENCED_PARAMETER(RegistryPath);
DriverObject->DriverUnload = SampleUnload;
KdPrint(("Sample driver initialized successfully\n"));
return STATUS_SUCCESS;
}