#pragma once

#if PLATFORM_ANDROID || PLATFORM_IOS
#include "TapDBDynamicProperties.h"

class SampleDynamicProperties:public TapDBDynamicProperties
{
public:
    SampleDynamicProperties();
    ~SampleDynamicProperties();

    FString GetDynamicProperties();
};

#endif