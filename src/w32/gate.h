int WINAPI CreateCallGate(void *FunctionAddress,
                          int NumberOfParameters,
                          PWORD pSelector);
int WINAPI FreeCallGate(WORD CallGateSelector);

#define SUCCESS                 0
#define ERROR_DRIVER_NOT_FOUND  1
#define ERROR_BAD_PARAMETER     2
#define ERROR_IOCONTROL_FAILED  3
