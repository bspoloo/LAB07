// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarFighterGameModeBase.h"
#include "NaveTerrestreEnemiga01.h"
#include "NaveAcuatica.h"
void AStarFighterGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	//auto ne = SpawnNave<ANaveTerrestreEnemiga01>();
	UE_LOG(LogTemp, Warning, TEXT("Dentro de BeginPlay en GameModeBase"));
	GetWorldTimerManager().SetTimer(AcuaticaTimerHandle, this, &AStarFighterGameModeBase::SpawnNave, 03.0f, true, 2.0f);//cada cierto tiempo creamos una NaveAcuatica extra en el mapa con el SpawnNave
	
	
}

AStarFighterGameModeBase::AStarFighterGameModeBase()
{
	/*UE_LOG(LogTemp, Warning, TEXT("Dentro de constructor en GameModeBase"));
	GetWorld()->SpawnActor<ANaveTerrestreEnemiga01>(FVector::ZeroVector, FRotator::ZeroRotator);*/

	//SpawnNave<ANaveTerrestreEnemiga01>();

}

void AStarFighterGameModeBase::SpawnNave()
{
	UWorld* const World = GetWorld();
	
		srand(time(nullptr));
		ejeX = rand() % 100 + 1;
		ejeY = rand() % 100 + 1;

		World->SpawnActor<ANaveAcuatica>(FVector(ejeX, ejeY, 112.0f), FRotator::ZeroRotator);//me crea una NaveAcuatica en un cierto lugar aleatorio
	
}
