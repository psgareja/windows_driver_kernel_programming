typedef struct _UNICODE_STRING {
USHORT Length;
USHORT MaximumLength;
PWCH Buffer;
} UNICODE_STRING;
typedef UNICODE_STRING *PUNICODE_STRING;
typedef const UNICODE_STRING *PCUNICODE_STRING;