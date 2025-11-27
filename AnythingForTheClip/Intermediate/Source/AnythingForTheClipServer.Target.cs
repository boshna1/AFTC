using UnrealBuildTool;

public class AnythingForTheClipServerTarget : TargetRules
{
	public AnythingForTheClipServerTarget(TargetInfo Target) : base(Target)
	{
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		Type = TargetType.Server;
		ExtraModuleNames.Add("AnythingForTheClip");
	}
}
