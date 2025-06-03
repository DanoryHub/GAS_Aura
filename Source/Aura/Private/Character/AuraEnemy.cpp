// Copyright Evilman Studio


#include "Character/AuraEnemy.h"
#include "Aura/Aura.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
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
