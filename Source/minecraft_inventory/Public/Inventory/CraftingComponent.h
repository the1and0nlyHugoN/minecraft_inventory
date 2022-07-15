// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory/InventoryComponent.h"
#include "Inventory/CraftingData.h"

#include "CraftingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MINECRAFT_INVENTORY_API UCraftingComponent : public UInventoryComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCraftingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UDataTable* CraftingData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UDataTable* BaseItemData;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
	USlot* CraftedSlot;

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	FItem CraftItem();

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	EItemBase CheckRecipe();

	UFUNCTION(BlueprintCallable, Category = "Crafting")
	TArray<FRecipeData> ConvertInventoryToRecipie();
};
