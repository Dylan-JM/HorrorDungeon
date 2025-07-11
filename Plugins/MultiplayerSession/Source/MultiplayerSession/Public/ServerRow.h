// Copyright DM

#pragma once

#include "CoreMinimal.h"
#include "OnlineSessionSettings.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "ServerRow.generated.h"

class UMenu;
class UTextBlock;
class UButton;
class UMultiplayerSessionsSubsystem;

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSION_API UServerRow : public UUserWidget
{
	GENERATED_BODY()

public:

	void UpdateServerRow(FOnlineSessionSearchResult SessionResult);

	void InitializeServerRow(UMenu* Menu);

	UPROPERTY(meta=(BindWidget))
	UButton* ServerResultButton;

	FOnlineSessionSearchResult ServerResult;

	UPROPERTY()
	UMenu* OwnerMenu;

private:

	UFUNCTION()
	void SearchButtonClicked();
	
	UPROPERTY(meta=(BindWidget))
	UTextBlock* Text_ServerName; 

	UPROPERTY(meta=(BindWidget))
	UTextBlock* Text_NumPlayers;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* Text_Ping;
	
	FOnlineSessionSearchResult SessionSearchResult;
	

	
};
