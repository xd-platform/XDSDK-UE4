// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
using System;

public class XDAnti : ModuleRules
{
	public XDAnti(ReadOnlyTargetRules Target) : base(Target)
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
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
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
            AdditionalPropertiesForReceipt.Add(
                "AndroidPlugin",
                Path.Combine(ModuleDirectory, "XDAnti_Android_UPL.xml")
            );
        }	

         if (Target.Platform == UnrealTargetPlatform.IOS) {
				//bundle
				AdditionalBundleResources.Add(new BundleResource(Path.Combine(ModuleDirectory, "./iOS/iOSConfigs/AntiAdictionResources.bundle")));

                // Add framework
                PublicAdditionalFrameworks.Add(
                    new Framework(
						"AntiAddictionService",
						"../ThirdParty/AntiAddictionService.embeddedframework.zip"
                    )
                );

				PublicAdditionalFrameworks.Add(
                    new Framework(
						"AntiAddictionUI",
						"../ThirdParty/AntiAddictionUI.embeddedframework.zip"
                    )
                );

				AdditionalPropertiesForReceipt.Add(
                    "IOSPlugin", 
                    Path.Combine(ModuleDirectory, "XDAnti_iOS_UPL.xml")
                );

		} 

	}
}
