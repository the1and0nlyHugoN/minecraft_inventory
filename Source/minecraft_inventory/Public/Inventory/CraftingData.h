// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Items/Item.h"

#include "CraftingData.generated.h"

/**
 * 
 */

USTRUCT(Blueprintable)
struct MINECRAFT_INVENTORY_API FRecipeData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
	FVector2D Coords;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
	EItemBase Item;

	bool operator==(const FRecipeData& Recipe) const;
};


USTRUCT(Blueprintable)
struct MINECRAFT_INVENTORY_API FCraftingData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
	TArray<FRecipeData> Recipe;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
	EItemBase Result;

	bool operator==(const FCraftingData& Recipe) const;
};
