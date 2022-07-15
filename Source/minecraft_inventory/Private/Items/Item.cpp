// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"

FItem::FItem()
{
	Id = FGuid();
	MaxStack = 1;
	Type = EItemType::None;
	Base = EItemBase::None;
}

bool FItem::operator==(const FItem& Item) const
{
	return Item.Id==Id;
}

