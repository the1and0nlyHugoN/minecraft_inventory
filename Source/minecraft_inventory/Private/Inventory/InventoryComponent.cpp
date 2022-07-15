// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UInventoryComponent::TryAddToInventory(FItem Item)
{
	USlot* Slot = FindAvailableSlotForItem(Item);
	if (Slot != nullptr)
	{
		Slot->AddItem(Item);
		return true;
	}

	return false;
}

USlot* UInventoryComponent::FindAvailableSlotForItem(FItem Item)
{
	TArray<USlot*> AvailableSlots = TArray<USlot*>();
	TArray<USlot*> EmptySlots = TArray<USlot*>();

	for (USlot* it : Inventory)
	{
		if ((it)->IsEmpty && ((it)->AcceptedTypes.Contains(Item.Type)))
		{
			EmptySlots.Add(it);
		}
		else if ((it)->GetBase()==Item.Base && ((it)->Stack < Item.MaxStack))
		{
			AvailableSlots.Add(it);
		}
	}

	if (AvailableSlots.Num() > 0)
	{
		return (AvailableSlots[0]);
	}

	if (EmptySlots.Num() > 0)
	{
		return (EmptySlots[0]);
	}

	return nullptr;
}

USlot* UInventoryComponent::FindAvailableSlot(USlot* Slot)
{
	if (Slot && Slot->Stack>0)
	{
		FindAvailableSlotForItem(Slot->Items[0]);
	}

	return nullptr;
}

int UInventoryComponent::CoordsToIndex(const FVector2D Coords)
{
	return Coords.X* Size.Y + Coords.Y;
}

FVector2D UInventoryComponent::IndexToCoords(const int Index)
{
	int Columns = Size.Y;

	return FVector2D(Index/Columns, Index%Columns);
}

void UInventoryComponent::MoveItem(USlot* Source, USlot* Target)
{
	if (Source && Target && &Source!=&Target)
	{
		TArray<FItem> CachedItems = Target->Items;
		TArray<FItem> ItemsLeft = Target->AddItems(Source->Items);
		Source->Clear();
		Source->AddItems(ItemsLeft);
	}
}

bool UInventoryComponent::TryAddItems(TArray<FItem> Items, USlot* Target)
{
	if (Target)
	{
		TArray<FItem> ItemsLeft = Target->AddItems(Items);

		return true;
	}

	return false;
}


