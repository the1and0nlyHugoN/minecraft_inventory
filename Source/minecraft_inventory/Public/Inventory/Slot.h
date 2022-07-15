// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Items/Item.h"


#include "Slot.generated.h"

/**
 * 
 */



UCLASS(Blueprintable)
class MINECRAFT_INVENTORY_API USlot : public UObject
{
	GENERATED_BODY()

public:

	USlot();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventorySlot")
	TSet<EItemType> AcceptedTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventorySlot")
	int Stack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventorySlot")
	TArray<FItem> Items;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventorySlot")
	bool IsEmpty;

	UFUNCTION(BlueprintPure, Category = "InventorySlot")
	EItemType GetType();

	UFUNCTION(BlueprintPure, Category = "InventorySlot")
	EItemBase GetBase();

	UFUNCTION(BlueprintPure, Category = "InventorySlot")
	int GetMaxStack();

	UFUNCTION(BlueprintPure, Category = "InventorySlot")
	UTexture2D* GetTexture();

	UFUNCTION(BlueprintCallable, Category = "InventorySlot")
	void AddItem(const FItem Item);

	UFUNCTION(BlueprintCallable, Category = "InventorySlot")
	TArray<FItem> AddItems(TArray<FItem> NewItems);

	UFUNCTION(BlueprintCallable, Category = "InventorySlot")
	void Clear();

	UFUNCTION(BlueprintCallable, Category = "InventorySlot")
	TArray<FItem> TakeFirst(int Size);

	UFUNCTION(BlueprintCallable, Category = "InventorySlot")
	TArray<FItem> TakeHalf();
};
