// COPYRIGHT @DYLAN MARLEY.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Menu.generated.h"

class UTextBlock;
class UServerRow;
class UScrollBox;
class UBorder;
class UMultiplayerSessionsSubsystem;
class UButton;
/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSION_API UMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void MenuSetup(int32 NumberOfPublicConnections = 4, FString TypeOfMatch = FString(TEXT("Looter")), FString LobbyPath = "/Game/ThirdPerson/Maps/Lobby");

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> WBP_ServerRow;

	UPROPERTY()
	UServerRow* ServerRowWidget;

	UPROPERTY()
	UServerRow* SelectedRow;

protected:

	virtual bool Initialize() override;
	virtual void NativeDestruct() override;

	/*
	 * Callbacks for the custom delegates on the MultiplayerSessionsSubsystem
	 */
	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);
	void OnFindSessions(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccessful);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);
	UFUNCTION()
	void OnDestroySession(bool bWasSuccessful);
	UFUNCTION()
	void OnStartSession(bool bWasSuccessful);
	
private:

	UPROPERTY(meta=(BindWidget))
	UButton* HostButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* JoinButton;

	UPROPERTY(meta=(BindWidget))
	UButton* SearchButton;

	UPROPERTY(meta=(BindWidget))
	UBorder* Border_ServerList;

	UPROPERTY(meta=(BindWidget))
	UScrollBox* ScrollBox_ServerList;


	
	UPROPERTY()
	TArray<UServerRow*> ServerInfoArray;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* SearchText;

	UFUNCTION()
	void HostButtonClicked();

	UFUNCTION()
	void JoinButtonClicked();

	UFUNCTION()
	void SearchButtonClicked();

	void MenuTearDowm();

	// Subsystem designed to handle all online session functionality
	TObjectPtr<UMultiplayerSessionsSubsystem> MultiplayerSessionsSubsystem;

	int32 NumPublicConnections{4};
	FString MatchType{TEXT("FreeForAll")};
	FString PathToLobby{TEXT("")};
};
