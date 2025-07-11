// Copyright DM


#include "ServerRow.h"
#include "Menu.h"
#include "OnlineSessionSettings.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UServerRow::UpdateServerRow(FOnlineSessionSearchResult SessionResult)
{
	SessionSearchResult = SessionResult;
	
	Text_ServerName->SetText(FText::FromString(SessionSearchResult.Session.OwningUserName));
	
	FString NumPlayers = FString::Printf(TEXT("%d / %d"), (SessionSearchResult.Session.SessionSettings.NumPublicConnections - SessionSearchResult.Session.NumOpenPublicConnections), SessionSearchResult.Session.SessionSettings.NumPublicConnections);
	Text_NumPlayers->SetText(FText::FromString(NumPlayers));
	
	FString Ping = FString::Printf(TEXT("%d ms"), SessionSearchResult.PingInMs);
	Text_Ping->SetText(FText::FromString(Ping));
}

void UServerRow::InitializeServerRow(UMenu* Menu)
{
	OwnerMenu = Menu;
	if (ServerResultButton)
	{
		ServerResultButton->OnClicked.AddDynamic(this, &ThisClass::SearchButtonClicked);
	}
}

void UServerRow::SearchButtonClicked()
{
	ServerResultButton->SetIsEnabled(false);
	OwnerMenu->SelectedRow = this;
}
