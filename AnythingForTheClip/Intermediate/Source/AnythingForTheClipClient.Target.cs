using UnrealBuildTool;

public class AnythingForTheClipClientTarget : TargetRules
{
	public AnythingForTheClipClientTarget(TargetInfo Target) : base(Target)
	{
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		Type = TargetType.Client;
		ExtraModuleNames.Add("AnythingForTheClip");
	}
}
