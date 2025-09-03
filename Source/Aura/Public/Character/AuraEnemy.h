// Copyright Evilman Studio

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();

	/* Begin Enemy interface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/* End Enemy interface */
	
	virtual void BeginPlay() override;
protected:
	void SetCustomDepth(bool bEnableCustemDepth, int Depth);

	void InitAbilityActorInfo() override;
};
