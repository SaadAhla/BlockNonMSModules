#include <Windows.h>
#include <stdio.h>


BOOL BlockNonMSDlls() {
    // Define the policy
    PROCESS_MITIGATION_BINARY_SIGNATURE_POLICY signaturePolicy = {};
    signaturePolicy.MicrosoftSignedOnly = 1;
    signaturePolicy.MitigationOptIn = 1;

    // Set the process mitigation policy for loading only Microsoft DLLs
    BOOL result = SetProcessMitigationPolicy(ProcessSignaturePolicy, &signaturePolicy, sizeof(signaturePolicy));
    if (!result)
    {
        printf("Failed to set policy (%u)\n", GetLastError());
        return FALSE;
    }
    return TRUE;
}

int main()
{
    
    if (!BlockNonMSDlls()) {
        return -1;
    }
    

    // The policy is now applied to the current process
    // Your Code here
    // ...
    //     

    while (true)
    {

        Sleep(1000);
    }

    return 0;
}
