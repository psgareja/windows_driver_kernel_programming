NTSTATUS IoCreateDevice(
_In_ PDRIVER_OBJECT DriverObject,
_In_ ULONG DeviceExtensionSize,
_In_opt_ PUNICODE_STRING DeviceName,
_In_ DEVICE_TYPE DeviceType,
_In_ ULONG DeviceCharacteristics,
_In_ BOOLEAN Exclusive,
_Outptr_ PDEVICE_OBJECT *DeviceObject);

UNICODE_STRING devName = RTL_CONSTANT_STRING(L"\\Device\\PriorityBooster");
// RtlInitUnicodeString(&devName, L"\\Device\\ThreadBoost");


PDEVICE_OBJECT DeviceObject;
NTSTATUS status = IoCreateDevice(
DriverObject // our driver object,
0 // no need for extra bytes,
&devName // the device name,
FILE_DEVICE_UNKNOWN // device type,
0 // characteristics flags,
FALSE // not exclusive,
&DeviceObject // the resulting pointer
);
if (!NT_SUCCESS(status)) {
KdPrint(("Failed to create device object (0x%08X)\n", status));
return status;
}


UNICODE_STRING symLink = RTL_CONSTANT_STRING(L"\\??\\PriorityBooster");
status = IoCreateSymbolicLink(&symLink, &devName);
if (!NT_SUCCESS(status)) {
KdPrint(("Failed to create symbolic link (0x%08X)\n", status));
IoDeleteDevice(DeviceObject);
return status;
}

void PriorityBoosterUnload(_In_ PDRIVER_OBJECT DriverObject) {
UNICODE_STRING symLink = RTL_CONSTANT_STRING(L"\\??\\PriorityBooster");
// delete symbolic link
IoDeleteSymbolicLink(&symLink);
// delete device object
IoDeleteDevice(DriverObject->DeviceObject);
}