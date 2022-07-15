// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/Texture2D.h"

#include "Item.generated.h"

/**
 * 
 */

UENUM(BlueprintType, Category = "Items")
enum class EItemType : uint8
{
	None,
	Weapon,
	Chest,
	Head,
	Legs,
	Feet,
	Material
};

UENUM(BlueprintType, Category = "Items")
enum class EItemBase : uint8
{
	None,
	Sword,
	Wood,
	Rock,
	Book,
	PlateArmour,
	Boots,
	Pants,
	Helmet,
	Flower,
	Mushroom,
	Berry,
	Root,
	Fossil
};

USTRUCT(Blueprintable)
struct MINECRAFT_INVENTORY_API FItem : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	FGuid Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	int MaxStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	EItemType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	EItemBase Base;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Texture;

	FItem();

	bool operator==(const FItem& Item) const;
};
