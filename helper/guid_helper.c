#include <stdint.h>
#include <stdio.h>
#include "rticonnextdds-connector.h"

int GetGuidBytesFromSample(
    RTI_Connector *connector,
    const char* inputName,
    int sampleIndex,
    const char* baseFieldName,
    uint8_t* outBytes // must point to 16 bytes
) {
    char fieldName[256];
    for (int i = 0; i < 16; ++i) {
        snprintf(fieldName, sizeof(fieldName), "%s[%d]", baseFieldName, i + 1);
        double val = 0;
        int retcode = RTI_Connector_get_number_from_sample(nativeConnector, &val, inputName, sampleIndex, fieldName);
        if (retcode != 0) {
            return retcode;
        }
        outBytes[i] = (uint8_t)val;
    }
    return 0;
}
