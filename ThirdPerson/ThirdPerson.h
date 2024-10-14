// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// Define the sphere's parameters as a macro
#define DRAW_SPHERE_PARAMS(World, Location) \
    DrawDebugSphere(World, Location, 25.0f, 10, FColor::Red, false, 30.0f)
