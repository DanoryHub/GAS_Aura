// Copyright Evilman Studio

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AuraWidgetController.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()

	FWidgetControllerParams(){}
	FWidgetControllerParams(
		APlayerController* PC,
		APlayerState* PS,
		UAbilitySystemComponent* ASC,
		UAttributeSet* AS
		):
	PlayerController(PC),
	PlayerState(PS),
	AbilitySystemComponent(ASC),
	AttributeSet(AS)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APlayerController* PlayerController = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APlayerState* PlayerState = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAbilitySystemComponent* AbilitySystemComponent = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAttributeSet* AttributeSet = nullptr;
};

/**
 * 
 */
UCLASS()
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FWidgetControllerParams& WidgetControllerParams);
	
	virtual void BroadcastInitialValues();

	virtual void BindCallbacksToDependencies();
protected:
	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	APlayerController* PlayerController;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	APlayerState* PlayerState;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	UAttributeSet* AttributeSet;
};
