using UnrealBuildTool;

public class AnythingForTheClipTarget : TargetRules
{
	public AnythingForTheClipTarget(TargetInfo Target) : base(Target)
	{
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		Type = TargetType.Game;
		ExtraModuleNames.Add("AnythingForTheClip");
	}
}
