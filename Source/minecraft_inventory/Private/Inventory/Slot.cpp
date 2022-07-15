// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Slot.h"

USlot::USlot()
{
	Items = TArray<FItem>();
	Stack = 0;
	IsEmpty = true;
}

EItemType USlot::GetType()
{
	if (Stack > 0)
	{
		return Items[0].Type;
	}

	return EItemType::None;
}

EItemBase USlot::GetBase()
{
	if (Stack > 0)
	{
		return Items[0].Base;
	}

	return EItemBase::None;
}

int USlot::GetMaxStack()
{
	if (Items.Num() > 0)
	{
		return Items[0].MaxStack;
	}

	return 0;
}

UTexture2D* USlot::GetTexture()
{
	if (Stack > 0)
	{
		return Items[0].Texture;
	}

	return nullptr;
}

void USlot::AddItem(const FItem Item)
{
	Items.Add(Item);
	IsEmpty = false;
	Stack++;
}

TArray<FItem> USlot::AddItems(TArray<FItem> NewItems)
{
	auto it = NewItems.CreateIterator();
	
	if (it && AcceptedTypes.Contains((*it).Type))
	{
		if (IsEmpty || ((*it).Base != Items[0].Base))
		{
			TArray<FItem> CachedItems = Items;
			Clear();
			Items = NewItems;
			Stack = Items.Num();
			IsEmpty = false;
			NewItems = CachedItems;
		}
		else
		{
			while (it && Stack<GetMaxStack())
			{
				AddItem(*it);
				it.RemoveCurrent();
				it++;
			}

		}
	}

	return NewItems;
}

void USlot::Clear()
{
	Items.Empty();
	IsEmpty = true;
	Stack = 0;
}

TArray<FItem> USlot::TakeFirst(int Size)
{
	auto it = Items.CreateIterator();
	TArray<FItem> ItemsToTake = TArray<FItem>();

	while (it && Size > 0)
	{
		ItemsToTake.Add(*it);
		it.RemoveCurrent();
		it++;
		Size--;
	}
	Stack = Items.Num();
	IsEmpty = Stack == 0;

	return ItemsToTake;
}

TArray<FItem> USlot::TakeHalf()
{
	return TakeFirst(Stack/2);
}

