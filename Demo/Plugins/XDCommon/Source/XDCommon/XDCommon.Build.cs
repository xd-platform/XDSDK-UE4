// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
using System;

public class XDCommon : ModuleRules
{
	public XDCommon(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PrivateIncludePaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "Private")));
        PublicIncludePaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "Public")));
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Engine",
				"RenderCore",
				"RHI",
				"Core",
				"CoreUObject",
				"Slate",
				"SlateCore",
				"UMG",
				"TapDB"
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Engine",
				"RenderCore",
				"RHI",
				"Core",
				"CoreUObject",
				"Slate",
				"SlateCore",
				"UMG",
				"TapDB"
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

		if (Target.Platform == UnrealTargetPlatform.Android){
            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                        "Launch"
                }
            );
            AdditionalPropertiesForReceipt.Add(
                "AndroidPlugin",
                Path.Combine(ModuleDirectory, "XDCommon_Android_UPL.xml")
            );
        }

		 if (Target.Platform == UnrealTargetPlatform.IOS) {
			 PublicFrameworks.AddRange(
					new string[]{
						"Accelerate",
						"SystemConfiguration",
						"WebKit",
						"SystemConfiguration",
						"CoreTelephony",
						"MobileCoreServices",
						"Security",
						"SafariServices",
						"AuthenticationServices"
					}
				);

				PublicSystemLibraryPaths.Add("/usr/lib/swift");
				PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "../ThirdParty/libswiftCompatibility51.a"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "../ThirdParty/libswiftCompatibility50.a"));
                PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "../ThirdParty/libswiftCompatibilityDynamicReplacements.a")); 
				PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "../ThirdParty/libWeChatSDK.a"));

				//bundle
				AdditionalBundleResources.Add(new BundleResource(Path.Combine(ModuleDirectory, "./iOS/iOSConfigs/XDResources.bundle")));

                // Add framework
                PublicAdditionalFrameworks.Add(
                    new Framework(
						"TDSGlobalSDKCommonKit",
						"../ThirdParty/TDSGlobalSDKCommonKit.embeddedframework.zip"
                    )
                );

				 PublicAdditionalFrameworks.Add(
                    new Framework(
						"XDCommonSDK",
						"../ThirdParty/XDCommonSDK.embeddedframework.zip"
                    )
                );

				 PublicAdditionalFrameworks.Add(
                    new Framework(
						"TencentOpenAPI",
						"../ThirdParty/TencentOpenAPI.embeddedframework.zip"
                    )
                );

				 AdditionalPropertiesForReceipt.Add(
                    "IOSPlugin", 
                    Path.Combine(ModuleDirectory, "XDCommon_iOS_UPL.xml")
                );

		}

	}
}
