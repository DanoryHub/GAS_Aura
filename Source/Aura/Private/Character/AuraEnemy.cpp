// Copyright Evilman Studio


#include "Character/AuraEnemy.h"

#include "NavigationSystemTypes.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAuraEnemy::HighlightActor()
{
	SetCustemDepth(true, CUSTOM_DEPTH_RED);
}

void AAuraEnemy::UnHighlightActor()
{
	SetCustemDepth(false, 0);
}

void AAuraEnemy::SetCustemDepth(bool bEnableCustemDepth, int Depth)
{
	GetMesh()->SetRenderCustomDepth(bEnableCustemDepth);
	GetMesh()->SetCustomDepthStencilValue(Depth);

	Weapon->SetRenderCustomDepth(bEnableCustemDepth);
	Weapon->SetCustomDepthStencilValue(Depth);
}
