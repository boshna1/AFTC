using UnrealBuildTool;

public class AnythingForTheClipEditorTarget : TargetRules
{
	public AnythingForTheClipEditorTarget(TargetInfo Target) : base(Target)
	{
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		Type = TargetType.Editor;
		ExtraModuleNames.Add("AnythingForTheClip");
	}
}
