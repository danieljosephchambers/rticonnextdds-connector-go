#ifndef GUID_HELPER_H
#define GUID_HELPER_H

#include <stdint.h>

int GetGuidBytesFromSample(
    RTI_Connector *connector,
    const char* inputName,
    int sampleIndex,
    const char* baseFieldName,
    uint8_t* outBytes
);

#endif
