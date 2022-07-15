// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/CraftingData.h"

bool FRecipeData::operator==(const FRecipeData& Recipe) const
{
    return (Coords == Recipe.Coords) && (Item == Recipe.Item);
}

bool FCraftingData::operator==(const FCraftingData& RecipeData) const
{
    return false;
}
