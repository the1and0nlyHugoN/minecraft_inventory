// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Items/Item.h"
#include "Inventory/Slot.h"
#include "Math/Vector2D.h"
#include "Blueprint/UserWidget.h"

#include "InventoryComponent.generated.h"


UCLASS(Blueprintable)
class MINECRAFT_INVENTORY_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FVector2D Size;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int SlotSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<USlot*> Inventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TSubclassOf<USlot> SlotClass;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool TryAddToInventory(FItem Item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	USlot* FindAvailableSlotForItem(FItem Item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	USlot* FindAvailableSlot(USlot * Slot);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int CoordsToIndex(const FVector2D Coords);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FVector2D IndexToCoords(const int Index);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void MoveItem(USlot* Source, USlot* Target);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool TryAddItems(TArray<FItem> Items, USlot* Target);
};
