// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class DaniaUEProjektTarget : TargetRules
{
	public DaniaUEProjektTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "DaniaUEProjekt" } );
	}
}
