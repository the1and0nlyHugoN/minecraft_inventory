// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/CraftingComponent.h"

// Sets default values for this component's properties
UCraftingComponent::UCraftingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UDataTable> CraftingObject(TEXT("DataTable'/Game/Inventory/Data/DT_CraftnigRecipe.DT_CraftnigRecipe'"));
	if (CraftingObject.Succeeded())
	{
		CraftingData = CraftingObject.Object;
	}
}


// Called when the game starts
void UCraftingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCraftingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FItem UCraftingComponent::CraftItem()
{
	EItemBase CraftedItem = CheckRecipe();
	if (CraftedItem != EItemBase::None)
	{

	}

	return FItem();
}

EItemBase UCraftingComponent::CheckRecipe()
{
	TArray<FRecipeData> Recipe = ConvertInventoryToRecipie();
	
	TArray<FCraftingData*> CraftingTable;
	CraftingData->GetAllRows<FCraftingData>(FString(), CraftingTable);
	for (FCraftingData* Data : CraftingTable)
	{
		if (Data->Recipe == Recipe)
		{
			return Data->Result;
		}
	}
	
	return EItemBase::None;
}

TArray<FRecipeData> UCraftingComponent::ConvertInventoryToRecipie()
{
	return TArray<FRecipeData>();
}

