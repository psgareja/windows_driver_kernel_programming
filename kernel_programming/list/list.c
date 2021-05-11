typedef struct _LIST_ENTRY {
struct _LIST_ENTRY *Flink;
struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY;


struct MyDataItem {
// some data members
LIST_ENTRY Link;
// more data members
};

MyDataItem* GetItem(LIST_ENTRY* pEntry) {
return CONTAINING_RECORD(pEntry, MyDataItem, Link);
}