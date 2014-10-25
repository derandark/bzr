/*
 * Bael'Zharon's Respite
 * Copyright (C) 2014 Daniel Skorupski
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#include "net/MessageType.h"
#include <unordered_map>

static const unordered_map<uint32_t, string> kMessageNames
{
    {0x0001, "Admin_CreateRare"},
    {0x0003, "Allegiance_AllegianceUpdateAborted"},
    {0x0004, "Communication_PopUpString"},
    {0x0005, "Character_PlayerOptionChangedEvent"},
    {0x0006, "Admin_TeleportCharacterReturn"},
    {0x0007, "Combat_UntargetedMeleeAttack"},
    {0x0008, "Combat_TargetedMeleeAttack"},
    {0x0009, "Object_Startup"},
    {0x000a, "Combat_TargetedMissileAttack"},
    {0x000b, "Combat_UntargetedMissileAttack"},
    {0x000c, "Admin_TeleportCharacterToMe"},
    {0x000d, "Admin_AdminCharDataByName"},
    {0x000e, "Admin_SetBodyPart"},
    {0x000f, "Communication_SetAFKMode"},
    {0x0010, "Communication_SetAFKMessage"},
    {0x0013, "Player_Description"},
    {0x0015, "Communication_Talk"},
    {0x0017, "Social_RemoveFriend"},
    {0x0018, "Social_AddFriend"},
    {0x0019, "Inventory_PutItemInContainer"},
    {0x001a, "Inventory_GetAndWieldItem"},
    {0x001b, "Inventory_DropItem"},
    {0x001c, "Weenie_Error"},
    {0x001d, "Allegiance_SwearAllegiance"},
    {0x001e, "Allegiance_BreakAllegiance"},
    {0x001f, "Allegiance_UpdateRequest"},
    {0x0020, "Allegiance_Update"},
    {0x0021, "Social_FriendsUpdate"},
    {0x0022, "Inventory_Put_Obj_In_Container"},
    {0x0023, "Inventory_Wield_Obj"},
    {0x0024, "Inventory_Remove_Obj"},
    {0x0025, "Social_ClearFriends"},
    {0x0026, "Character_TeleToPKLArena"},
    {0x0027, "Character_TeleToPKArena"},
    {0x0028, "Social_AddCharacterTitle"},
    {0x0029, "Social_CharacterTitleTable"},
    {0x002a, "Character_Generation_Result"},
    {0x002b, "Social_AddOrSetCharacterTitle"},
    {0x002c, "Social_SetDisplayCharacterTitle"},
    {0x002d, "Admin_RemoveCharacterTitle"},
    {0x002e, "Admin_AddCharacterTitle"},
    {0x002f, "Admin_DumpCharacterTitles"},
    {0x0030, "Allegiance_QueryAllegianceName"},
    {0x0031, "Allegiance_ClearAllegianceName"},
    {0x0032, "Communication_TalkDirect"},
    {0x0033, "Allegiance_SetAllegianceName"},
    {0x0034, "Char_Base_ObjDesc"},
    {0x0035, "Inventory_UseWithTargetEvent"},
    {0x0036, "Inventory_UseEvent"},
    {0x0039, "Admin_ResetAllegianceName"},
    {0x003a, "Character_Logon"},
    {0x003b, "Allegiance_SetAllegianceOfficer"},
    {0x003c, "Allegiance_SetAllegianceOfficerTitle"},
    {0x003d, "Allegiance_ListAllegianceOfficerTitles"},
    {0x003e, "Allegiance_ClearAllegianceOfficerTitles"},
    {0x003f, "Allegiance_DoAllegianceLockAction"},
    {0x0040, "Allegiance_SetAllegianceApprovedVassal"},
    {0x0041, "Allegiance_AllegianceChatGag"},
    {0x0042, "Allegiance_DoAllegianceHouseAction"},
    {0x0044, "Train_TrainAttribute2nd"},
    {0x0045, "Train_TrainAttribute"},
    {0x0046, "Train_TrainSkill"},
    {0x0047, "Train_TrainSkillAdvancementClass"},
    {0x0048, "Magic_CastUntargetedSpell"},
    {0x004a, "Magic_CastTargetedSpell"},
    {0x004b, "Magic_ResearchSpell"},
    {0x004c, "Update_Spell"},
    {0x004d, "Remove_Spell"},
    {0x004e, "Update_Enchantment"},
    {0x004f, "Remove_Enchantment"},
    {0x0050, "Inventory_CommenceViewingContents"},
    {0x0051, "Update_Spell_Timestamp"},
    {0x0052, "Close_Ground_Container"},
    {0x0053, "Combat_ChangeCombatMode"},
    {0x0054, "Inventory_StackableMerge"},
    {0x0055, "Inventory_StackableSplitToContainer"},
    {0x0056, "Inventory_StackableSplitTo3D"},
    {0x0058, "Communication_ModifyCharacterSquelch"},
    {0x0059, "Communication_ModifyAccountSquelch"},
    {0x005a, "Communication_SquelchQuery"},
    {0x005b, "Communication_ModifyGlobalSquelch"},
    {0x005d, "Communication_TalkDirectByName"},
    {0x005e, "Attack_Notification"},
    {0x005f, "Vendor_Buy"},
    {0x0060, "Vendor_Sell"},
    {0x0061, "Vendor_RequestVendorInfo"},
    {0x0062, "Vendor_Info"},
    {0x0063, "Character_TeleToLifestone"},
    {0x0064, "Admin_InqWeenieDesc"},
    {0x0065, "Admin_SetPosition"},
    {0x0066, "Admin_SetSkill"},
    {0x0067, "Admin_SetDataID"},
    {0x0068, "Admin_SetString"},
    {0x0069, "Admin_SetFloat"},
    {0x006a, "Admin_SetInt"},
    {0x006b, "Admin_SetAttribute2nd"},
    {0x006c, "Admin_SetAttribute"},
    {0x006d, "Admin_Teleport"},
    {0x0070, "Admin_Create"},
    {0x0075, "Character_StartBarber"},
    {0x0076, "Admin_Delete"},
    {0x007d, "Admin_RaiseAttribute2nd"},
    {0x007e, "Admin_RaiseAttribute"},
    {0x007f, "Admin_RaiseSkill"},
    {0x0080, "Admin_RaiseXP"},
    {0x0081, "Admin_WeenieLogEvent"},
    {0x0082, "Admin_InqPlayerDataEvent"},
    {0x0084, "Admin_InqFullPlayerDataEvent"},
    {0x0085, "Admin_Recv_Full_Player_Data"},
    {0x0086, "Admin_CloakRequest"},
    {0x0087, "Admin_PortalTeleport"},
    {0x0088, "Admin_SetInstanceID"},
    {0x0089, "Admin_StickyRequest"},
    {0x008a, "Admin_SetBool"},
    {0x0096, "Admin_Recv_Weenie_Desc"},
    {0x0097, "Admin_Recv_Position"},
    {0x009c, "Portal_Storm_Subsided"},
    {0x009d, "Portal_Storm_Brewing"},
    {0x009e, "Portal_Storm_Imminent"},
    {0x009f, "Portal_Storm"},
    {0x00a0, "Inventory_Server_Says_Failed"},
    {0x00a1, "Character_LoginCompleteNotification"},
    {0x00a2, "Fellowship_Create"},
    {0x00a3, "Fellowship_Quit"},
    {0x00a4, "Fellowship_Dismiss"},
    {0x00a5, "Fellowship_Recruit"},
    {0x00a6, "Fellowship_UpdateRequest"},
    {0x00a7, "Recv_Quit_Fellow"},
    {0x00aa, "Writing_BookData"},
    {0x00ab, "Writing_BookModifyPage"},
    {0x00ac, "Writing_BookAddPage"},
    {0x00ad, "Writing_BookDeletePage"},
    {0x00ae, "Writing_BookPageData"},
    {0x00af, "Recv_Fellowship_Update"},
    {0x00b0, "Recv_Update_Fellow"},
    {0x00b1, "Recv_Dismiss_Fellow"},
    {0x00b2, "Recv_Logoff_Fellow"},
    {0x00b3, "Recv_Disband_Fellowship"},
    {0x00b4, "Book_Data_Response"},
    {0x00b5, "Book_Modify_Page_Response"},
    {0x00b6, "Book_Add_Page_Response"},
    {0x00b7, "Book_Delete_Page_Response"},
    {0x00b8, "Book_Page_Data_Response"},
    {0x00be, "Writing_GetInscription"},
    {0x00bf, "Writing_SetInscription"},
    {0x00c3, "Get_Inscription_Response"},
    {0x00c8, "Item_Appraise"},
    {0x00c9, "Appraisal_Info"},
    {0x00ca, "Fellowship_Appraise"},
    {0x00cd, "Inventory_GiveObjectRequest"},
    {0x00d3, "Advocate_Bestow"},
    {0x00d4, "Advocate_SetState"},
    {0x00d5, "Advocate_SetAttackable"},
    {0x00d6, "Advocate_Teleport"},
    {0x0140, "Character_AbuseLogRequest"},
    {0x0145, "Communication_AddToChannel"},
    {0x0146, "Communication_RemoveFromChannel"},
    {0x0147, "Communication_ChannelBroadcast"},
    {0x0148, "Communication_ChannelList"},
    {0x0149, "Communication_ChannelIndex"},
    {0x014a, "Channel_Broadcast"},
    {0x014b, "Channel_List"},
    {0x014c, "Channel_Index"},
    {0x0195, "Inventory_NoLongerViewingContents"},
    {0x0196, "View_Contents"},
    {0x0197, "Stackable_Set_StackSize"},
    {0x019a, "Inventory_Put_Obj_In_3D"},
    {0x019b, "Inventory_StackableSplitToWield"},
    {0x019c, "Character_AddShortCut"},
    {0x019d, "Character_RemoveShortCut"},
    {0x019e, "Player_Death"},
    {0x01a1, "Character_CharacterOptionsEvent"},
    {0x01a2, "Admin_SaveSanctuaryPosition"},
    {0x01a4, "Dispel_Enchantment"},
    {0x01a5, "Update_Enchantments"},
    {0x01a6, "Remove_Enchantments"},
    {0x01a7, "Attack_Done"},
    {0x01a8, "Magic_RemoveSpell"},
    {0x01ab, "Purge_Enchantments"},
    {0x01ac, "Victim_Notification"},
    {0x01ad, "Killer_Notification"},
    {0x01ae, "Dispel_Enchantments"},
    {0x01b1, "Attack_Notification2"},
    {0x01b2, "Defender_Notification"},
    {0x01b3, "Evasion_Attacker_Notification"},
    {0x01b4, "Evasion_Defender_Notification"},
    {0x01b6, "Admin_DumpEnemyTable"},
    {0x01b7, "Combat_CancelAttack"},
    {0x01b8, "Combat_CommenceAttack"},
    {0x01b9, "Admin_Kill"},
    {0x01ba, "Admin_DropAll"},
    {0x01bb, "Admin_Dispel"},
    {0x01bc, "Admin_Humble"},
    {0x01bd, "Admin_QueryActive"},
    {0x01be, "Admin_QueryContext"},
    {0x01bf, "Combat_QueryHealth"},
    {0x01c0, "Combat_QueryHealthResponse"},
    {0x01c1, "Admin_QueryHouseKeeping"},
    {0x01c2, "Character_QueryAge"},
    {0x01c3, "Character_QueryAgeResponse"},
    {0x01c4, "Character_QueryBirth"},
    {0x01c6, "Admin_QueryShop"},
    {0x01c7, "Item_UseDone"},
    {0x01c8, "Allegiance_AllegianceUpdateDone"},
    {0x01c9, "Fellowship_FellowUpdateDone"},
    {0x01ca, "Fellowship_FellowStatsDone"},
    {0x01cb, "Item_AppraiseDone"},
    {0x01cc, "Admin_QueryCPWorth"},
    {0x01cd, "Admin_Heal"},
    {0x01ce, "Admin_InqAccountDataEvent"},
    {0x01cf, "Admin_Freeze"},
    {0x01d0, "Admin_TeleportHome"},
    {0x01d1, "Qualities_PrivateRemoveIntEvent"},
    {0x01d2, "Qualities_RemoveIntEvent"},
    {0x01d3, "Qualities_PrivateRemoveBoolEvent"},
    {0x01d4, "Qualities_RemoveBoolEvent"},
    {0x01d5, "Qualities_PrivateRemoveFloatEvent"},
    {0x01d6, "Qualities_RemoveFloatEvent"},
    {0x01d7, "Qualities_PrivateRemoveStringEvent"},
    {0x01d8, "Qualities_RemoveStringEvent"},
    {0x01d9, "Qualities_PrivateRemoveDataIDEvent"},
    {0x01da, "Qualities_RemoveDataIDEvent"},
    {0x01db, "Qualities_PrivateRemoveInstanceIDEvent"},
    {0x01dc, "Qualities_RemoveInstanceIDEvent"},
    {0x01dd, "Qualities_PrivateRemovePositionEvent"},
    {0x01de, "Qualities_RemovePositionEvent"},
    {0x01df, "Communication_Emote"},
    {0x01e0, "Communication_HearEmote"},
    {0x01e1, "Communication_SoulEmote"},
    {0x01e2, "Communication_HearSoulEmote"},
    {0x01e3, "Character_AddSpellFavorite"},
    {0x01e4, "Character_RemoveSpellFavorite"},
    {0x01e5, "Admin_ForceRegen"},
    {0x01e6, "Advocate_TeleportTo"},
    {0x01e7, "Admin_QueryMessage"},
    {0x01e8, "Admin_QueryTime"},
    {0x01e9, "Character_RequestPing"},
    {0x01ea, "Character_ReturnPing"},
    {0x01ec, "Admin_Gag"},
    {0x01ed, "Admin_DumpQuestTable"},
    {0x01ee, "Admin_WorldBroadcastEmote"},
    {0x01ef, "Admin_LocalBroadcastEmote"},
    {0x01f0, "Admin_DirectBroadcastEmote"},
    {0x01f1, "Admin_QueryEventStatus"},
    {0x01f2, "Admin_SetEventState"},
    {0x01f4, "Communication_SetSquelchDB"},
    {0x01f5, "Admin_CreateInternal"},
    {0x01f6, "Trade_OpenTradeNegotiations"},
    {0x01f7, "Trade_CloseTradeNegotiations"},
    {0x01f8, "Trade_AddToTrade"},
    {0x01f9, "Trade_RemoveFromTrade"},
    {0x01fa, "Trade_AcceptTrade"},
    {0x01fb, "Trade_DeclineTrade"},
    {0x01fc, "Trade_DumpTrade"},
    {0x01fd, "Trade_Recv_RegisterTrade"},
    {0x01fe, "Trade_Recv_OpenTrade"},
    {0x01ff, "Trade_Recv_CloseTrade"},
    {0x0200, "Trade_Recv_AddToTrade"},
    {0x0201, "Trade_Recv_RemoveFromTrade"},
    {0x0202, "Trade_Recv_AcceptTrade"},
    {0x0203, "Trade_Recv_DeclineTrade"},
    {0x0204, "Trade_ResetTrade"},
    {0x0205, "Trade_Recv_ResetTrade"},
    {0x0206, "Admin_QueryViewing"},
    {0x0207, "Trade_Recv_TradeFailure"},
    {0x0208, "Trade_Recv_ClearTradeAcceptance"},
    {0x0216, "Character_ClearPlayerConsentList"},
    {0x0217, "Character_DisplayPlayerConsentList"},
    {0x0218, "Character_RemoveFromPlayerConsentList"},
    {0x0219, "Character_AddPlayerPermission"},
    {0x021a, "Character_RemovePlayerPermission"},
    {0x021b, "House_DumpHouse"},
    {0x021c, "House_BuyHouse"},
    {0x021d, "House_Recv_HouseProfile"},
    {0x021e, "House_QueryHouse"},
    {0x021f, "House_AbandonHouse"},
    {0x0220, "House_StealHouse"},
    {0x0221, "House_RentHouse"},
    {0x0222, "House_LinkToHouse"},
    {0x0223, "House_ReCacheHouse"},
    {0x0224, "Character_SetDesiredComponentLevel"},
    {0x0225, "House_Recv_HouseData"},
    {0x0226, "House_Recv_HouseStatus"},
    {0x0227, "House_Recv_UpdateRentTime"},
    {0x0228, "House_Recv_UpdateRentPayment"},
    {0x0229, "Update_Int"},
    {0x022a, "Update_Float"},
    {0x022b, "Update_String"},
    {0x022c, "Update_Bool"},
    {0x022d, "Update_IID"},
    {0x022e, "Update_DID"},
    {0x022f, "Update_Position"},
    {0x0230, "Update_Skill"},
    {0x0231, "Update_Skill_Level"},
    {0x0232, "Update_SAC"},
    {0x0233, "Update_Attribute"},
    {0x0234, "Update_Attribute_Level"},
    {0x0235, "Update_Attribute_2nd"},
    {0x0236, "Update_Attribute_2nd_Level"},
    {0x0237, "Update_Int_Private"},
    {0x0238, "Update_Float_Private"},
    {0x0239, "Update_String_Private"},
    {0x023a, "Update_Bool_Private"},
    {0x023b, "Update_IID_Private"},
    {0x023c, "Update_DID_Private"},
    {0x023d, "Update_Position_Private"},
    {0x023e, "Update_Skill_Private"},
    {0x023f, "Update_Skill_Level_Private"},
    {0x0240, "Update_SAC_Private"},
    {0x0241, "Update_Attribute_Private"},
    {0x0242, "Update_Attribute_Level_Private"},
    {0x0243, "Update_Attribute_2nd_Private"},
    {0x0244, "Update_Attribute_2nd_Level_Private"},
    {0x0245, "House_AddPermanentGuest_Event"},
    {0x0246, "House_RemovePermanentGuest_Event"},
    {0x0247, "House_SetOpenHouseStatus_Event"},
    {0x0248, "House_Recv_UpdateRestrictions"},
    {0x0249, "House_ChangeStoragePermission_Event"},
    {0x024a, "House_BootSpecificHouseGuest_Event"},
    {0x024b, "House_BootAllUninvitedGuests_Event"},
    {0x024c, "House_RemoveAllStoragePermission"},
    {0x024d, "House_RequestFullGuestList_Event"},
    {0x024e, "House_RentPay"},
    {0x024f, "House_RentWarn"},
    {0x0250, "House_RentDue"},
    {0x0254, "Allegiance_SetMotd"},
    {0x0255, "Allegiance_QueryMotd"},
    {0x0256, "Allegiance_ClearMotd"},
    {0x0257, "House_Recv_UpdateHAR"},
    {0x0258, "House_QueryLord"},
    {0x0259, "House_Recv_HouseTransaction"},
    {0x025a, "House_RentOverDue"},
    {0x025b, "Admin_QueryInv"},
    {0x025c, "House_AddAllStoragePermission"},
    {0x025d, "House_QueryHouseOwner"},
    {0x025e, "House_RemoveAllPermanentGuests_Event"},
    {0x025f, "House_BootEveryone_Event"},
    {0x0260, "Admin_Orphan"},
    {0x0261, "House_AdminTeleToHouse"},
    {0x0262, "House_TeleToHouse_Event"},
    {0x0263, "Item_QueryItemMana"},
    {0x0264, "Item_QueryItemManaResponse"},
    {0x0265, "House_PayRentForAllHouses"},
    {0x0266, "House_SetHooksVisibility"},
    {0x0267, "House_ModifyAllegianceGuestPermission"},
    {0x0268, "House_ModifyAllegianceStoragePermission"},
    {0x0269, "Game_Join"},
    {0x026a, "Game_Quit"},
    {0x026b, "Game_Move"},
    {0x026c, "Game_MoveGrid"},
    {0x026d, "Game_MovePass"},
    {0x026e, "Game_Stalemate"},
    {0x026f, "Admin_CreateTreasure"},
    {0x0270, "House_ListAvailableHouses"},
    {0x0271, "House_Recv_AvailableHouses"},
    {0x0272, "Admin_TogglePortalBypass"},
    {0x0273, "Admin_Mutate"},
    {0x0274, "Character_ConfirmationRequest"},
    {0x0275, "Character_ConfirmationResponse"},
    {0x0276, "Character_ConfirmationDone"},
    {0x0277, "Allegiance_BreakAllegianceBoot"},
    {0x0278, "House_TeleToMansion_Event"},
    {0x0279, "Character_Suicide"},
    {0x027a, "Allegiance_AllegianceLoginNotificationEvent"},
    {0x027b, "Allegiance_AllegianceInfoRequest"},
    {0x027c, "Allegiance_AllegianceInfoResponseEvent"},
    {0x027d, "Inventory_CreateTinkeringTool"},
    {0x027e, "Admin_CreateMaterial"},
    {0x027f, "Admin_EraseQuestTable"},
    {0x0281, "Game_Recv_JoinGameResponse"},
    {0x0282, "Game_Recv_StartGame"},
    {0x0283, "Game_Recv_MoveResponse"},
    {0x0284, "Game_Recv_OpponentTurn"},
    {0x0285, "Game_Recv_OppenentStalemateState"},
    {0x0286, "Character_SpellbookFilterEvent"},
    {0x0287, "Admin_QueryTrophyDrops"},
    {0x0288, "House_SetMaintenanceFree"},
    {0x0289, "House_DumpHouseAccess"},
    {0x028a, "Communication_WeenieError"},
    {0x028b, "Communication_WeenieErrorWithString"},
    {0x028c, "Game_Recv_GameOver"},
    {0x028d, "Character_TeleToMarketplace"},
    {0x028e, "Admin_StampQuest"},
    {0x028f, "Character_EnterPKLite"},
    {0x0290, "Fellowship_AssignNewLeader"},
    {0x0291, "Fellowship_ChangeFellowOpeness"},
    {0x0292, "Admin_ClearEvent"},
    {0x0293, "Admin_Limbo"},
    {0x0294, "Admin_SentinelRunBoost"},
    {0x0295, "Communication_Recv_ChatRoomTracker"},
    {0x0296, "Admin_PassupInfo"},
    {0x0297, "Admin_SetNeverHouseKept"},
    {0x0298, "Admin_SetCPWorth"},
    {0x0299, "Admin_SetDeafMode"},
    {0x029a, "Admin_SetDeafHear"},
    {0x029b, "Admin_SetDeafMute"},
    {0x029c, "Admin_SnoopOn"},
    {0x029d, "Admin_SetInvincibility"},
    {0x029f, "Admin_AssertTheServer"},
    {0x02a0, "Allegiance_AllegianceChatBoot"},
    {0x02a1, "Allegiance_AddAllegianceBan"},
    {0x02a2, "Allegiance_RemoveAllegianceBan"},
    {0x02a3, "Allegiance_ListAllegianceBans"},
    {0x02a4, "Allegiance_AddAllegianceOfficer"},
    {0x02a5, "Allegiance_RemoveAllegianceOfficer"},
    {0x02a6, "Allegiance_ListAllegianceOfficers"},
    {0x02a7, "Allegiance_ClearAllegianceOfficers"},
    {0x02a8, "Admin_SavePosition"},
    {0x02a9, "Admin_RecallPosition"},
    {0x02aa, "Admin_AdminBoot"},
    {0x02ab, "Allegiance_RecallAllegianceHometown"},
    {0x02ac, "Admin_DumpRareTiers"},
    {0x02ad, "Admin_QueryPluginList"},
    {0x02ae, "Admin_Recv_QueryPluginList"},
    {0x02af, "Admin_QueryPluginListResponse"},
    {0x02b0, "Admin_QueryPlugin"},
    {0x02b1, "Admin_Recv_QueryPlugin"},
    {0x02b2, "Admin_QueryPluginResponse"},
    {0x02b3, "Admin_Recv_QueryPluginResponse"},
    {0x02b4, "Inventory_Recv_SalvageOperationsResultData"},
    {0x02b5, "Admin_SetInt64"},
    {0x02b6, "Update_Int64"},
    {0x02b7, "Update_Int64_Private"},
    {0x02b8, "Qualities_PrivateRemoveInt64Event"},
    {0x02b9, "Qualities_RemoveInt64Event"},
    {0x02ba, "Admin_RaiseLevel"},
    {0x02bb, "Communication_HearSpeech"},
    {0x02bc, "Communication_HearRangedSpeech"},
    {0x02bd, "Communication_HearDirectSpeech"},
    {0x02be, "Fellowship_FullUpdate"},
    {0x02bf, "Fellowship_Disband"},
    {0x02c0, "Fellowship_UpdateFellow"},
    {0x02c1, "Magic_UpdateSpell"},
    {0x02c2, "Magic_UpdateEnchantment"},
    {0x02c3, "Magic_RemoveEnchantment"},
    {0x02c4, "Magic_UpdateMultipleEnchantments"},
    {0x02c5, "Magic_RemoveMultipleEnchantments"},
    {0x02c6, "Magic_PurgeEnchantments"},
    {0x02c7, "Magic_DispelEnchantment"},
    {0x02c8, "Magic_DispelMultipleEnchantments"},
    {0x02c9, "Misc_PortalStormBrewing"},
    {0x02ca, "Misc_PortalStormImminent"},
    {0x02cb, "Misc_PortalStorm"},
    {0x02cc, "Misc_PortalStormSubsided"},
    {0x02cd, "Qualities_PrivateUpdateInt"},
    {0x02ce, "Qualities_UpdateInt"},
    {0x02cf, "Qualities_PrivateUpdateInt64"},
    {0x02d0, "Qualities_UpdateInt64"},
    {0x02d1, "Qualities_PrivateUpdateBool"},
    {0x02d2, "Qualities_UpdateBool"},
    {0x02d3, "Qualities_PrivateUpdateFloat"},
    {0x02d4, "Qualities_UpdateFloat"},
    {0x02d5, "Qualities_PrivateUpdateString"},
    {0x02d6, "Qualities_UpdateString"},
    {0x02d7, "Qualities_PrivateUpdateDataID"},
    {0x02d8, "Qualities_UpdateDataID"},
    {0x02d9, "Qualities_PrivateUpdateInstanceID"},
    {0x02da, "Qualities_UpdateInstanceID"},
    {0x02db, "Qualities_PrivateUpdatePosition"},
    {0x02dc, "Qualities_UpdatePosition"},
    {0x02dd, "Qualities_PrivateUpdateSkill"},
    {0x02de, "Qualities_UpdateSkill"},
    {0x02df, "Qualities_PrivateUpdateSkillLevel"},
    {0x02e0, "Qualities_UpdateSkillLevel"},
    {0x02e1, "Qualities_PrivateUpdateSkillAC"},
    {0x02e2, "Qualities_UpdateSkillAC"},
    {0x02e3, "Qualities_PrivateUpdateAttribute"},
    {0x02e4, "Qualities_UpdateAttribute"},
    {0x02e5, "Qualities_PrivateUpdateAttributeLevel"},
    {0x02e6, "Qualities_UpdateAttributeLevel"},
    {0x02e7, "Qualities_PrivateUpdateAttribute2nd"},
    {0x02e8, "Qualities_UpdateAttribute2nd"},
    {0x02e9, "Qualities_PrivateUpdateAttribute2ndLevel"},
    {0x02ea, "Qualities_UpdateAttribute2ndLevel"},
    {0x02eb, "Communication_TransientString"},
    {0x030c, "Admin_ForceRenameCharacter"},
    {0x030d, "Admin_GagTime"},
    {0x030e, "Admin_AddRenameToken"},
    {0x030f, "Character_Rename"},
    {0x0311, "Character_FinishBarber"},
    {0x0312, "Magic_PurgeBadEnchantments"},
    {0x0314, "Social_SendClientContractTrackerTable"},
    {0x0315, "Social_SendClientContractTracker"},
    {0x0316, "Social_AbandonContract"},
    {0xea60, "Admin_Environs"},
    {0xf619, "Movement_PositionAndMovement"},
    {0xf61b, "Movement_Jump"},
    {0xf61c, "Movement_MoveToState"},
    {0xf61e, "Movement_DoMovementCommand"},
    {0xf625, "Physics_ObjDescEvent"},
    {0xf630, "User_Alert"},
    {0xf643, "Character_Generation_Verification_Response"},
    {0xf648, "Movement_TurnEvent"},
    {0xf649, "Movement_TurnToEvent"},
    {0xf651, "Expire_Warning"},
    {0xf653, "Character_Exit_Game"},
    {0xf654, "Character_Preview"},
    {0xf655, "Character_Delete"},
    {0xf656, "Character_Create"},
    {0xf657, "Character_Enter_Game"},
    {0xf658, "Login_CharacterSet"},
    {0xf659, "Character_Error"},
    {0xf65a, "System_Messages"},
    {0xf661, "Movement_StopMovementCommand"},
    {0xf69b, "Admin_Recv_Player_Data"},
    {0xf6ea, "Control_Force_ObjDesc_Send"},
    {0xf745, "Physics_CreateObject"},
    {0xf746, "Physics_CreatePlayer"},
    {0xf747, "Physics_DeleteObject"},
    {0xf748, "Movement_UpdatePosition"},
    {0xf749, "Physics_ParentEvent"},
    {0xf74a, "Physics_PickupEvent"},
    {0xf74b, "Physics_SetState"},
    {0xf74c, "Movement_MovementEvent"},
    {0xf74e, "Physics_VectorUpdate"},
    {0xf750, "Physics_SoundEvent"},
    {0xf751, "Physics_PlayerTeleport"},
    {0xf752, "Movement_AutonomyLevel"},
    {0xf753, "Movement_AutonomousPosition"},
    {0xf754, "Physics_PlayScriptID"},
    {0xf755, "Physics_PlayScriptType"},
    {0xf765, "LBDB_Status_Client"},
    {0xf7a8, "CliDat_RequestData"},
    {0xf7a9, "CliDat_RequestCell"},
    {0xf7aa, "CliDat_Error"},
    {0xf7ab, "CliDat_Landblock"},
    {0xf7ac, "CliDat_Cell"},
    {0xf7b0, "Weenie_Ordered"},
    {0xf7b1, "Ordered"},
    {0xf7b7, "CliDat_Data"},
    {0xf7bb, "CliDat_Cell_Purge"},
    {0xf7c1, "Account_Banned"},
    {0xf7c2, "Client_Logon_Server"},
    {0xf7c7, "CharDB_Ready_To_Enter_Game"},
    {0xf7c8, "Client_Request_Enter_Game"},
    {0xf7c9, "Movement_Jump_NonAutonomous"},
    {0xf7ca, "Admin_ReceiveAccountData"},
    {0xf7cb, "Admin_ReceivePlayerData"},
    {0xf7cc, "Admin_GetServerVersion"},
    {0xf7cd, "Admin_Friends"},
    {0xf7ce, "Admin_ReloadSystemMessages"},
    {0xf7cf, "Admin_SetUserLimit"},
    {0xf7d0, "Admin_SetLoadBalanceInterval"},
    {0xf7d1, "Admin_SetLoadBalanceThreshold"},
    {0xf7d2, "Admin_SetPortalStormThreshold"},
    {0xf7d3, "Admin_SetPortalStormNumToMove"},
    {0xf7d4, "Admin_FingerCharacter"},
    {0xf7d5, "Admin_FingerAccount"},
    {0xf7d6, "Admin_AdminLevelList"},
    {0xf7d7, "Admin_CopyCharacter"},
    {0xf7d8, "Admin_AdminNextIDsList"},
    {0xf7d9, "Admin_AdminRestoreCharacter"},
    {0xf7da, "Admin_QueryBannedList"},
    {0xf7db, "Physics_UpdateObject"},
    {0xf7dc, "Account_Booted"},
    {0xf7dd, "Admin_ClearLocks"},
    {0xf7de, "Admin_ChatServerData"},
    {0xf7df, "Character_EnterGame_ServerReady"},
    {0xf7e0, "Communication_TextboxString"},
    {0xf7e1, "Login_WorldInfo"},
    {0xf7e2, "DDD_Data"},
    {0xf7e3, "DDD_RequestData"},
    {0xf7e4, "DDD_Error"},
    {0xf7e5, "DDD_Interrogation"},
    {0xf7e6, "DDD_InterrogationResponse"},
    {0xf7e7, "DDD_BeginDDD"},
    {0xf7e8, "DDD_BeginPullDDD"},
    {0xf7e9, "DDD_IterationData"},
    {0xf7ea, "DDD_EndDDD"},
    {0xf7eb, "DDD_Pending"},
};

const string& getMessageName(MessageType messageType)
{
    auto it = kMessageNames.find(static_cast<uint32_t>(messageType));

    if(it == kMessageNames.end())
    {
        throw runtime_error("unknown message type");
    }

    return it->second;
}
