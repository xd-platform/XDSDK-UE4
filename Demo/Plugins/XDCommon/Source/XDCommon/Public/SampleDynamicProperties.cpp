#if PLATFORM_ANDROID || PLATFORM_IOS

#include "SampleDynamicProperties.h"
#include "TapJson.h"
#include "Json.h"
#include "Serialization/JsonWriter.h"

SampleDynamicProperties::SampleDynamicProperties(){

}

SampleDynamicProperties::~SampleDynamicProperties(){

}

FString TapDBDynamicProperties::GetDynamicProperties(){
    FDateTime Time = FDateTime::Now();
	int64 Timestamp = Time.ToUnixTimestamp();
    FString JsonOutString;
    TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> Writer = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&JsonOutString);
    Writer->WriteObjectStart();
    Writer->WriteValue(TEXT("UE_DynamicProperties"), Timestamp);
    Writer->WriteObjectEnd();
    Writer->Close();
    return JsonOutString;
}

TapDBDynamicProperties * GetTapDBDynamicProperties(){
    static TapDBDynamicProperties* properties = nullptr;
    if(properties == nullptr){
        properties = new SampleDynamicProperties();
    }
    return properties;
}

#endif