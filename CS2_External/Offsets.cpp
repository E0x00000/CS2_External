#include "Offsets.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "json.h"
#include <Windows.h>
#include <optional>
#include <optional>
#include <string>
#include <iostream>
#include <windows.h>
#include "a2x/basichttps/https.h"
using namespace std;
using json = nlohmann::json;

using DWORD = unsigned long;


DWORD findOffsetByName(const nlohmann::json& j, const std::string& category, const std::string& name) {
    if (j.contains(category) && j[category].contains(name)) {
        const auto& value = j[category][name];

        // Se for número, retorna diretamente, caso contrário, converte de string para DWORD
        if (value.is_number()) {
            return value.get<DWORD>();
        }
        else if (value.is_string()) {
            return std::stoul(value.get<std::string>(), nullptr, 16); // Converte string hexadecimal para DWORD
        }
    }
    throw std::runtime_error("Offset " + name + " não encontrado na categoria " + category);
}
using namespace Offset;



void parseAndAssignConstants(const std::string& jsonString)
{
    json j = json::parse(jsonString);
    // Atribuições para buttons
// buttons Offsets
    buttons.attack = findOffsetByName(j, "buttons", "attack");
    buttons.attack2 = findOffsetByName(j, "buttons", "attack2");
    buttons.back = findOffsetByName(j, "buttons", "back");
    buttons.duck = findOffsetByName(j, "buttons", "duck");
    buttons.forward = findOffsetByName(j, "buttons", "forward");
    buttons.jump = findOffsetByName(j, "buttons", "jump");
    buttons.left = findOffsetByName(j, "buttons", "left");
    buttons.lookatweapon = findOffsetByName(j, "buttons", "lookatweapon");
    buttons.reload = findOffsetByName(j, "buttons", "reload");
    buttons.right = findOffsetByName(j, "buttons", "right");
    buttons.showscores = findOffsetByName(j, "buttons", "showscores");
    buttons.sprint = findOffsetByName(j, "buttons", "sprint");
    buttons.turnleft = findOffsetByName(j, "buttons", "turnleft");
    buttons.turnright = findOffsetByName(j, "buttons", "turnright");
    buttons.use = findOffsetByName(j, "buttons", "use");
    buttons.zoom = findOffsetByName(j, "buttons", "zoom");

    // Atribuições para CCSPlayer_MovementServices
    // CCSPlayer_MovementServices Offsets
    CCSPlayer_MovementServices.m_vecLadderNormal = findOffsetByName(j, "CCSPlayer_MovementServices", "m_vecLadderNormal");
    CCSPlayer_MovementServices.m_nLadderSurfacePropIndex = findOffsetByName(j, "CCSPlayer_MovementServices", "m_nLadderSurfacePropIndex");
    CCSPlayer_MovementServices.m_flDuckAmount = findOffsetByName(j, "CCSPlayer_MovementServices", "m_flDuckAmount");
    CCSPlayer_MovementServices.m_flDuckSpeed = findOffsetByName(j, "CCSPlayer_MovementServices", "m_flDuckSpeed");
    CCSPlayer_MovementServices.m_bDuckOverride = findOffsetByName(j, "CCSPlayer_MovementServices", "m_bDuckOverride");
    CCSPlayer_MovementServices.m_bDesiresDuck = findOffsetByName(j, "CCSPlayer_MovementServices", "m_bDesiresDuck");
    CCSPlayer_MovementServices.m_flDuckOffset = findOffsetByName(j, "CCSPlayer_MovementServices", "m_flDuckOffset");
    CCSPlayer_MovementServices.m_nDuckTimeMsecs = findOffsetByName(j, "CCSPlayer_MovementServices", "m_nDuckTimeMsecs");
    CCSPlayer_MovementServices.m_nDuckJumpTimeMsecs = findOffsetByName(j, "CCSPlayer_MovementServices", "m_nDuckJumpTimeMsecs");
    CCSPlayer_MovementServices.m_nJumpTimeMsecs = findOffsetByName(j, "CCSPlayer_MovementServices", "m_nJumpTimeMsecs");
    CCSPlayer_MovementServices.m_flLastDuckTime = findOffsetByName(j, "CCSPlayer_MovementServices", "m_flLastDuckTime");
    CCSPlayer_MovementServices.m_vecLastPositionAtFullCrouchSpeed = findOffsetByName(j, "CCSPlayer_MovementServices", "m_vecLastPositionAtFullCrouchSpeed");
    CCSPlayer_MovementServices.m_duckUntilOnGround = findOffsetByName(j, "CCSPlayer_MovementServices", "m_duckUntilOnGround");
    CCSPlayer_MovementServices.m_bHasWalkMovedSinceLastJump = findOffsetByName(j, "CCSPlayer_MovementServices", "m_bHasWalkMovedSinceLastJump");
    CCSPlayer_MovementServices.m_bInStuckTest = findOffsetByName(j, "CCSPlayer_MovementServices", "m_bInStuckTest");
    CCSPlayer_MovementServices.m_flStuckCheckTime = findOffsetByName(j, "CCSPlayer_MovementServices", "m_flStuckCheckTime");
    CCSPlayer_MovementServices.m_nTraceCount = findOffsetByName(j, "CCSPlayer_MovementServices", "m_nTraceCount");
    CCSPlayer_MovementServices.m_StuckLast = findOffsetByName(j, "CCSPlayer_MovementServices", "m_StuckLast");
    CCSPlayer_MovementServices.m_bSpeedCropped = findOffsetByName(j, "CCSPlayer_MovementServices", "m_bSpeedCropped");
    CCSPlayer_MovementServices.m_flGroundMoveEfficiency = findOffsetByName(j, "CCSPlayer_MovementServices", "m_flGroundMoveEfficiency");
    CCSPlayer_MovementServices.m_nOldWaterLevel = findOffsetByName(j, "CCSPlayer_MovementServices", "m_nOldWaterLevel");
    CCSPlayer_MovementServices.m_flWaterEntryTime = findOffsetByName(j, "CCSPlayer_MovementServices", "m_flWaterEntryTime");
    CCSPlayer_MovementServices.m_vecForward = findOffsetByName(j, "CCSPlayer_MovementServices", "m_vecForward");
    CCSPlayer_MovementServices.m_vecLeft = findOffsetByName(j, "CCSPlayer_MovementServices", "m_vecLeft");
    CCSPlayer_MovementServices.m_vecUp = findOffsetByName(j, "CCSPlayer_MovementServices", "m_vecUp");
    CCSPlayer_MovementServices.m_nGameCodeHasMovedPlayerAfterCommand = findOffsetByName(j, "CCSPlayer_MovementServices", "m_nGameCodeHasMovedPlayerAfterCommand");
    CCSPlayer_MovementServices.m_bOldJumpPressed = findOffsetByName(j, "CCSPlayer_MovementServices", "m_bOldJumpPressed");
    CCSPlayer_MovementServices.m_flJumpPressedTime = findOffsetByName(j, "CCSPlayer_MovementServices", "m_flJumpPressedTime");
    CCSPlayer_MovementServices.m_fStashGrenadeParameterWhen = findOffsetByName(j, "CCSPlayer_MovementServices", "m_fStashGrenadeParameterWhen");
    CCSPlayer_MovementServices.m_nButtonDownMaskPrev = findOffsetByName(j, "CCSPlayer_MovementServices", "m_nButtonDownMaskPrev");
    CCSPlayer_MovementServices.m_flOffsetTickCompleteTime = findOffsetByName(j, "CCSPlayer_MovementServices", "m_flOffsetTickCompleteTime");
    CCSPlayer_MovementServices.m_flOffsetTickStashedSpeed = findOffsetByName(j, "CCSPlayer_MovementServices", "m_flOffsetTickStashedSpeed");
    CCSPlayer_MovementServices.m_flStamina = findOffsetByName(j, "CCSPlayer_MovementServices", "m_flStamina");
    CCSPlayer_MovementServices.m_flHeightAtJumpStart = findOffsetByName(j, "CCSPlayer_MovementServices", "m_flHeightAtJumpStart");
    CCSPlayer_MovementServices.m_flMaxJumpHeightThisJump = findOffsetByName(j, "CCSPlayer_MovementServices", "m_flMaxJumpHeightThisJump");
    CCSPlayer_MovementServices.m_flMaxJumpHeightLastJump = findOffsetByName(j, "CCSPlayer_MovementServices", "m_flMaxJumpHeightLastJump");
    CCSPlayer_MovementServices.m_flStaminaAtJumpStart = findOffsetByName(j, "CCSPlayer_MovementServices", "m_flStaminaAtJumpStart");
    CCSPlayer_MovementServices.m_flAccumulatedJumpError = findOffsetByName(j, "CCSPlayer_MovementServices", "m_flAccumulatedJumpError");

    // Atribuições para sky3dparams_t
    // sky3dparams_t Offsets
    sky3dparams_t.scale = findOffsetByName(j, "sky3dparams_t", "scale");
    sky3dparams_t.origin = findOffsetByName(j, "sky3dparams_t", "origin");
    sky3dparams_t.bClip3DSkyBoxNearToWorldFar = findOffsetByName(j, "sky3dparams_t", "bClip3DSkyBoxNearToWorldFar");
    sky3dparams_t.flClip3DSkyBoxNearToWorldFarOffset = findOffsetByName(j, "sky3dparams_t", "flClip3DSkyBoxNearToWorldFarOffset");
    sky3dparams_t.fog = findOffsetByName(j, "sky3dparams_t", "fog");
    sky3dparams_t.m_nWorldGroupID = findOffsetByName(j, "sky3dparams_t", "m_nWorldGroupID");

    // Atribuições para C_Item
    // C_Item Offsets
    C_Item.m_pReticleHintTextName = findOffsetByName(j, "C_Item", "m_pReticleHintTextName");

    // Atribuições para C_SoundEventPathCornerEntity
    // C_SoundEventPathCornerEntity Offsets
    C_SoundEventPathCornerEntity.m_vecCornerPairsNetworked = findOffsetByName(j, "C_SoundEventPathCornerEntity", "m_vecCornerPairsNetworked");

    // Atribuições para C_CSGameRules
    // C_CSGameRules Offsets
    C_CSGameRules.m_bFreezePeriod = findOffsetByName(j, "C_CSGameRules", "m_bFreezePeriod");
    C_CSGameRules.m_bWarmupPeriod = findOffsetByName(j, "C_CSGameRules", "m_bWarmupPeriod");
    C_CSGameRules.m_fWarmupPeriodEnd = findOffsetByName(j, "C_CSGameRules", "m_fWarmupPeriodEnd");
    C_CSGameRules.m_fWarmupPeriodStart = findOffsetByName(j, "C_CSGameRules", "m_fWarmupPeriodStart");
    C_CSGameRules.m_bServerPaused = findOffsetByName(j, "C_CSGameRules", "m_bServerPaused");
    C_CSGameRules.m_bTerroristTimeOutActive = findOffsetByName(j, "C_CSGameRules", "m_bTerroristTimeOutActive");
    C_CSGameRules.m_bCTTimeOutActive = findOffsetByName(j, "C_CSGameRules", "m_bCTTimeOutActive");
    C_CSGameRules.m_flTerroristTimeOutRemaining = findOffsetByName(j, "C_CSGameRules", "m_flTerroristTimeOutRemaining");
    C_CSGameRules.m_flCTTimeOutRemaining = findOffsetByName(j, "C_CSGameRules", "m_flCTTimeOutRemaining");
    C_CSGameRules.m_nTerroristTimeOuts = findOffsetByName(j, "C_CSGameRules", "m_nTerroristTimeOuts");
    C_CSGameRules.m_nCTTimeOuts = findOffsetByName(j, "C_CSGameRules", "m_nCTTimeOuts");
    C_CSGameRules.m_bTechnicalTimeOut = findOffsetByName(j, "C_CSGameRules", "m_bTechnicalTimeOut");
    C_CSGameRules.m_bMatchWaitingForResume = findOffsetByName(j, "C_CSGameRules", "m_bMatchWaitingForResume");
    C_CSGameRules.m_iRoundTime = findOffsetByName(j, "C_CSGameRules", "m_iRoundTime");
    C_CSGameRules.m_fMatchStartTime = findOffsetByName(j, "C_CSGameRules", "m_fMatchStartTime");
    C_CSGameRules.m_fRoundStartTime = findOffsetByName(j, "C_CSGameRules", "m_fRoundStartTime");
    C_CSGameRules.m_flRestartRoundTime = findOffsetByName(j, "C_CSGameRules", "m_flRestartRoundTime");
    C_CSGameRules.m_bGameRestart = findOffsetByName(j, "C_CSGameRules", "m_bGameRestart");
    C_CSGameRules.m_flGameStartTime = findOffsetByName(j, "C_CSGameRules", "m_flGameStartTime");
    C_CSGameRules.m_timeUntilNextPhaseStarts = findOffsetByName(j, "C_CSGameRules", "m_timeUntilNextPhaseStarts");
    C_CSGameRules.m_gamePhase = findOffsetByName(j, "C_CSGameRules", "m_gamePhase");
    C_CSGameRules.m_totalRoundsPlayed = findOffsetByName(j, "C_CSGameRules", "m_totalRoundsPlayed");
    C_CSGameRules.m_nRoundsPlayedThisPhase = findOffsetByName(j, "C_CSGameRules", "m_nRoundsPlayedThisPhase");
    C_CSGameRules.m_nOvertimePlaying = findOffsetByName(j, "C_CSGameRules", "m_nOvertimePlaying");
    C_CSGameRules.m_iHostagesRemaining = findOffsetByName(j, "C_CSGameRules", "m_iHostagesRemaining");
    C_CSGameRules.m_bAnyHostageReached = findOffsetByName(j, "C_CSGameRules", "m_bAnyHostageReached");
    C_CSGameRules.m_bMapHasBombTarget = findOffsetByName(j, "C_CSGameRules", "m_bMapHasBombTarget");
    C_CSGameRules.m_bMapHasRescueZone = findOffsetByName(j, "C_CSGameRules", "m_bMapHasRescueZone");
    C_CSGameRules.m_bMapHasBuyZone = findOffsetByName(j, "C_CSGameRules", "m_bMapHasBuyZone");
    C_CSGameRules.m_bIsQueuedMatchmaking = findOffsetByName(j, "C_CSGameRules", "m_bIsQueuedMatchmaking");
    C_CSGameRules.m_nQueuedMatchmakingMode = findOffsetByName(j, "C_CSGameRules", "m_nQueuedMatchmakingMode");
    C_CSGameRules.m_bIsValveDS = findOffsetByName(j, "C_CSGameRules", "m_bIsValveDS");
    C_CSGameRules.m_bLogoMap = findOffsetByName(j, "C_CSGameRules", "m_bLogoMap");
    C_CSGameRules.m_bPlayAllStepSoundsOnServer = findOffsetByName(j, "C_CSGameRules", "m_bPlayAllStepSoundsOnServer");
    C_CSGameRules.m_iSpectatorSlotCount = findOffsetByName(j, "C_CSGameRules", "m_iSpectatorSlotCount");
    C_CSGameRules.m_MatchDevice = findOffsetByName(j, "C_CSGameRules", "m_MatchDevice");
    C_CSGameRules.m_bHasMatchStarted = findOffsetByName(j, "C_CSGameRules", "m_bHasMatchStarted");
    C_CSGameRules.m_nNextMapInMapgroup = findOffsetByName(j, "C_CSGameRules", "m_nNextMapInMapgroup");
    C_CSGameRules.m_szTournamentEventName = findOffsetByName(j, "C_CSGameRules", "m_szTournamentEventName");
    C_CSGameRules.m_szTournamentEventStage = findOffsetByName(j, "C_CSGameRules", "m_szTournamentEventStage");
    C_CSGameRules.m_szMatchStatTxt = findOffsetByName(j, "C_CSGameRules", "m_szMatchStatTxt");
    C_CSGameRules.m_szTournamentPredictionsTxt = findOffsetByName(j, "C_CSGameRules", "m_szTournamentPredictionsTxt");
    C_CSGameRules.m_nTournamentPredictionsPct = findOffsetByName(j, "C_CSGameRules", "m_nTournamentPredictionsPct");
    C_CSGameRules.m_flCMMItemDropRevealStartTime = findOffsetByName(j, "C_CSGameRules", "m_flCMMItemDropRevealStartTime");
    C_CSGameRules.m_flCMMItemDropRevealEndTime = findOffsetByName(j, "C_CSGameRules", "m_flCMMItemDropRevealEndTime");
    C_CSGameRules.m_bIsDroppingItems = findOffsetByName(j, "C_CSGameRules", "m_bIsDroppingItems");
    C_CSGameRules.m_bIsQuestEligible = findOffsetByName(j, "C_CSGameRules", "m_bIsQuestEligible");
    C_CSGameRules.m_bIsHltvActive = findOffsetByName(j, "C_CSGameRules", "m_bIsHltvActive");
    C_CSGameRules.m_arrProhibitedItemIndices = findOffsetByName(j, "C_CSGameRules", "m_arrProhibitedItemIndices");
    C_CSGameRules.m_arrTournamentActiveCasterAccounts = findOffsetByName(j, "C_CSGameRules", "m_arrTournamentActiveCasterAccounts");
    C_CSGameRules.m_numBestOfMaps = findOffsetByName(j, "C_CSGameRules", "m_numBestOfMaps");
    C_CSGameRules.m_nHalloweenMaskListSeed = findOffsetByName(j, "C_CSGameRules", "m_nHalloweenMaskListSeed");
    C_CSGameRules.m_bBombDropped = findOffsetByName(j, "C_CSGameRules", "m_bBombDropped");
    C_CSGameRules.m_bBombPlanted = findOffsetByName(j, "C_CSGameRules", "m_bBombPlanted");
    C_CSGameRules.m_iRoundWinStatus = findOffsetByName(j, "C_CSGameRules", "m_iRoundWinStatus");
    C_CSGameRules.m_eRoundWinReason = findOffsetByName(j, "C_CSGameRules", "m_eRoundWinReason");
    C_CSGameRules.m_bTCantBuy = findOffsetByName(j, "C_CSGameRules", "m_bTCantBuy");
    C_CSGameRules.m_bCTCantBuy = findOffsetByName(j, "C_CSGameRules", "m_bCTCantBuy");
    C_CSGameRules.m_iMatchStats_RoundResults = findOffsetByName(j, "C_CSGameRules", "m_iMatchStats_RoundResults");
    C_CSGameRules.m_iMatchStats_PlayersAlive_CT = findOffsetByName(j, "C_CSGameRules", "m_iMatchStats_PlayersAlive_CT");
    C_CSGameRules.m_iMatchStats_PlayersAlive_T = findOffsetByName(j, "C_CSGameRules", "m_iMatchStats_PlayersAlive_T");
    C_CSGameRules.m_TeamRespawnWaveTimes = findOffsetByName(j, "C_CSGameRules", "m_TeamRespawnWaveTimes");
    C_CSGameRules.m_flNextRespawnWave = findOffsetByName(j, "C_CSGameRules", "m_flNextRespawnWave");
    C_CSGameRules.m_nServerQuestID = findOffsetByName(j, "C_CSGameRules", "m_nServerQuestID");
    C_CSGameRules.m_vMinimapMins = findOffsetByName(j, "C_CSGameRules", "m_vMinimapMins");
    C_CSGameRules.m_vMinimapMaxs = findOffsetByName(j, "C_CSGameRules", "m_vMinimapMaxs");
    C_CSGameRules.m_MinimapVerticalSectionHeights = findOffsetByName(j, "C_CSGameRules", "m_MinimapVerticalSectionHeights");
    C_CSGameRules.m_bSpawnedTerrorHuntHeavy = findOffsetByName(j, "C_CSGameRules", "m_bSpawnedTerrorHuntHeavy");
    C_CSGameRules.m_nEndMatchMapGroupVoteTypes = findOffsetByName(j, "C_CSGameRules", "m_nEndMatchMapGroupVoteTypes");
    C_CSGameRules.m_nEndMatchMapGroupVoteOptions = findOffsetByName(j, "C_CSGameRules", "m_nEndMatchMapGroupVoteOptions");
    C_CSGameRules.m_nEndMatchMapVoteWinner = findOffsetByName(j, "C_CSGameRules", "m_nEndMatchMapVoteWinner");
    C_CSGameRules.m_iNumConsecutiveCTLoses = findOffsetByName(j, "C_CSGameRules", "m_iNumConsecutiveCTLoses");
    C_CSGameRules.m_iNumConsecutiveTerroristLoses = findOffsetByName(j, "C_CSGameRules", "m_iNumConsecutiveTerroristLoses");
    C_CSGameRules.m_bMarkClientStopRecordAtRoundEnd = findOffsetByName(j, "C_CSGameRules", "m_bMarkClientStopRecordAtRoundEnd");
    C_CSGameRules.m_nMatchAbortedEarlyReason = findOffsetByName(j, "C_CSGameRules", "m_nMatchAbortedEarlyReason");
    C_CSGameRules.m_bHasTriggeredRoundStartMusic = findOffsetByName(j, "C_CSGameRules", "m_bHasTriggeredRoundStartMusic");
    C_CSGameRules.m_bSwitchingTeamsAtRoundReset = findOffsetByName(j, "C_CSGameRules", "m_bSwitchingTeamsAtRoundReset");
    C_CSGameRules.m_pGameModeRules = findOffsetByName(j, "C_CSGameRules", "m_pGameModeRules");
    C_CSGameRules.m_RetakeRules = findOffsetByName(j, "C_CSGameRules", "m_RetakeRules");
    C_CSGameRules.m_nMatchEndCount = findOffsetByName(j, "C_CSGameRules", "m_nMatchEndCount");
    C_CSGameRules.m_nTTeamIntroVariant = findOffsetByName(j, "C_CSGameRules", "m_nTTeamIntroVariant");
    C_CSGameRules.m_nCTTeamIntroVariant = findOffsetByName(j, "C_CSGameRules", "m_nCTTeamIntroVariant");
    C_CSGameRules.m_bTeamIntroPeriod = findOffsetByName(j, "C_CSGameRules", "m_bTeamIntroPeriod");
    C_CSGameRules.m_iRoundEndWinnerTeam = findOffsetByName(j, "C_CSGameRules", "m_iRoundEndWinnerTeam");
    C_CSGameRules.m_eRoundEndReason = findOffsetByName(j, "C_CSGameRules", "m_eRoundEndReason");
    C_CSGameRules.m_bRoundEndShowTimerDefend = findOffsetByName(j, "C_CSGameRules", "m_bRoundEndShowTimerDefend");
    C_CSGameRules.m_iRoundEndTimerTime = findOffsetByName(j, "C_CSGameRules", "m_iRoundEndTimerTime");
    C_CSGameRules.m_sRoundEndFunFactToken = findOffsetByName(j, "C_CSGameRules", "m_sRoundEndFunFactToken");
    C_CSGameRules.m_iRoundEndFunFactPlayerSlot = findOffsetByName(j, "C_CSGameRules", "m_iRoundEndFunFactPlayerSlot");
    C_CSGameRules.m_iRoundEndFunFactData1 = findOffsetByName(j, "C_CSGameRules", "m_iRoundEndFunFactData1");
    C_CSGameRules.m_iRoundEndFunFactData2 = findOffsetByName(j, "C_CSGameRules", "m_iRoundEndFunFactData2");
    C_CSGameRules.m_iRoundEndFunFactData3 = findOffsetByName(j, "C_CSGameRules", "m_iRoundEndFunFactData3");
    C_CSGameRules.m_sRoundEndMessage = findOffsetByName(j, "C_CSGameRules", "m_sRoundEndMessage");
    C_CSGameRules.m_iRoundEndPlayerCount = findOffsetByName(j, "C_CSGameRules", "m_iRoundEndPlayerCount");
    C_CSGameRules.m_bRoundEndNoMusic = findOffsetByName(j, "C_CSGameRules", "m_bRoundEndNoMusic");
    C_CSGameRules.m_iRoundEndLegacy = findOffsetByName(j, "C_CSGameRules", "m_iRoundEndLegacy");
    C_CSGameRules.m_nRoundEndCount = findOffsetByName(j, "C_CSGameRules", "m_nRoundEndCount");
    C_CSGameRules.m_iRoundStartRoundNumber = findOffsetByName(j, "C_CSGameRules", "m_iRoundStartRoundNumber");
    C_CSGameRules.m_nRoundStartCount = findOffsetByName(j, "C_CSGameRules", "m_nRoundStartCount");
    C_CSGameRules.m_flLastPerfSampleTime = findOffsetByName(j, "C_CSGameRules", "m_flLastPerfSampleTime");

    // Atribuições para CBodyComponentSkeletonInstance
    // CBodyComponentSkeletonInstance Offsets
    CBodyComponentSkeletonInstance.m_skeletonInstance = findOffsetByName(j, "CBodyComponentSkeletonInstance", "m_skeletonInstance");

    // Atribuições para C_BaseModelEntity
    // C_BaseModelEntity Offsets
    C_BaseModelEntity.m_CRenderComponent = findOffsetByName(j, "C_BaseModelEntity", "m_CRenderComponent");
    C_BaseModelEntity.m_CHitboxComponent = findOffsetByName(j, "C_BaseModelEntity", "m_CHitboxComponent");
    C_BaseModelEntity.m_LastHitGroup = findOffsetByName(j, "C_BaseModelEntity", "m_LastHitGroup");
    C_BaseModelEntity.m_bInitModelEffects = findOffsetByName(j, "C_BaseModelEntity", "m_bInitModelEffects");
    C_BaseModelEntity.m_bIsStaticProp = findOffsetByName(j, "C_BaseModelEntity", "m_bIsStaticProp");
    C_BaseModelEntity.m_nLastAddDecal = findOffsetByName(j, "C_BaseModelEntity", "m_nLastAddDecal");
    C_BaseModelEntity.m_nDecalsAdded = findOffsetByName(j, "C_BaseModelEntity", "m_nDecalsAdded");
    C_BaseModelEntity.m_iOldHealth = findOffsetByName(j, "C_BaseModelEntity", "m_iOldHealth");
    C_BaseModelEntity.m_nRenderMode = findOffsetByName(j, "C_BaseModelEntity", "m_nRenderMode");
    C_BaseModelEntity.m_nRenderFX = findOffsetByName(j, "C_BaseModelEntity", "m_nRenderFX");
    C_BaseModelEntity.m_bAllowFadeInView = findOffsetByName(j, "C_BaseModelEntity", "m_bAllowFadeInView");
    C_BaseModelEntity.m_clrRender = findOffsetByName(j, "C_BaseModelEntity", "m_clrRender");
    C_BaseModelEntity.m_vecRenderAttributes = findOffsetByName(j, "C_BaseModelEntity", "m_vecRenderAttributes");
    C_BaseModelEntity.m_bRenderToCubemaps = findOffsetByName(j, "C_BaseModelEntity", "m_bRenderToCubemaps");
    C_BaseModelEntity.m_bNoInterpolate = findOffsetByName(j, "C_BaseModelEntity", "m_bNoInterpolate");
    C_BaseModelEntity.m_Collision = findOffsetByName(j, "C_BaseModelEntity", "m_Collision");
    C_BaseModelEntity.m_Glow = findOffsetByName(j, "C_BaseModelEntity", "m_Glow");
    C_BaseModelEntity.m_flGlowBackfaceMult = findOffsetByName(j, "C_BaseModelEntity", "m_flGlowBackfaceMult");
    C_BaseModelEntity.m_fadeMinDist = findOffsetByName(j, "C_BaseModelEntity", "m_fadeMinDist");
    C_BaseModelEntity.m_fadeMaxDist = findOffsetByName(j, "C_BaseModelEntity", "m_fadeMaxDist");
    C_BaseModelEntity.m_flFadeScale = findOffsetByName(j, "C_BaseModelEntity", "m_flFadeScale");
    C_BaseModelEntity.m_flShadowStrength = findOffsetByName(j, "C_BaseModelEntity", "m_flShadowStrength");
    C_BaseModelEntity.m_nObjectCulling = findOffsetByName(j, "C_BaseModelEntity", "m_nObjectCulling");
    C_BaseModelEntity.m_nAddDecal = findOffsetByName(j, "C_BaseModelEntity", "m_nAddDecal");
    C_BaseModelEntity.m_vDecalPosition = findOffsetByName(j, "C_BaseModelEntity", "m_vDecalPosition");
    C_BaseModelEntity.m_vDecalForwardAxis = findOffsetByName(j, "C_BaseModelEntity", "m_vDecalForwardAxis");
    C_BaseModelEntity.m_flDecalHealBloodRate = findOffsetByName(j, "C_BaseModelEntity", "m_flDecalHealBloodRate");
    C_BaseModelEntity.m_flDecalHealHeightRate = findOffsetByName(j, "C_BaseModelEntity", "m_flDecalHealHeightRate");
    C_BaseModelEntity.m_ConfigEntitiesToPropagateMaterialDecalsTo = findOffsetByName(j, "C_BaseModelEntity", "m_ConfigEntitiesToPropagateMaterialDecalsTo");
    C_BaseModelEntity.m_vecViewOffset = findOffsetByName(j, "C_BaseModelEntity", "m_vecViewOffset");
    C_BaseModelEntity.m_pClientAlphaProperty = findOffsetByName(j, "C_BaseModelEntity", "m_pClientAlphaProperty");
    C_BaseModelEntity.m_ClientOverrideTint = findOffsetByName(j, "C_BaseModelEntity", "m_ClientOverrideTint");
    C_BaseModelEntity.m_bUseClientOverrideTint = findOffsetByName(j, "C_BaseModelEntity", "m_bUseClientOverrideTint");

    // Atribuições para C_FootstepControl
    // C_FootstepControl Offsets
    C_FootstepControl.m_source = findOffsetByName(j, "C_FootstepControl", "m_source");
    C_FootstepControl.m_destination = findOffsetByName(j, "C_FootstepControl", "m_destination");

    // Atribuições para C_PointClientUIHUD
    // C_PointClientUIHUD Offsets
    C_PointClientUIHUD.m_bCheckCSSClasses = findOffsetByName(j, "C_PointClientUIHUD", "m_bCheckCSSClasses");
    C_PointClientUIHUD.m_bIgnoreInput = findOffsetByName(j, "C_PointClientUIHUD", "m_bIgnoreInput");
    C_PointClientUIHUD.m_flWidth = findOffsetByName(j, "C_PointClientUIHUD", "m_flWidth");
    C_PointClientUIHUD.m_flHeight = findOffsetByName(j, "C_PointClientUIHUD", "m_flHeight");
    C_PointClientUIHUD.m_flDPI = findOffsetByName(j, "C_PointClientUIHUD", "m_flDPI");
    C_PointClientUIHUD.m_flInteractDistance = findOffsetByName(j, "C_PointClientUIHUD", "m_flInteractDistance");
    C_PointClientUIHUD.m_flDepthOffset = findOffsetByName(j, "C_PointClientUIHUD", "m_flDepthOffset");
    C_PointClientUIHUD.m_unOwnerContext = findOffsetByName(j, "C_PointClientUIHUD", "m_unOwnerContext");
    C_PointClientUIHUD.m_unHorizontalAlign = findOffsetByName(j, "C_PointClientUIHUD", "m_unHorizontalAlign");
    C_PointClientUIHUD.m_unVerticalAlign = findOffsetByName(j, "C_PointClientUIHUD", "m_unVerticalAlign");
    C_PointClientUIHUD.m_unOrientation = findOffsetByName(j, "C_PointClientUIHUD", "m_unOrientation");
    C_PointClientUIHUD.m_bAllowInteractionFromAllSceneWorlds = findOffsetByName(j, "C_PointClientUIHUD", "m_bAllowInteractionFromAllSceneWorlds");
    C_PointClientUIHUD.m_vecCSSClasses = findOffsetByName(j, "C_PointClientUIHUD", "m_vecCSSClasses");

    // Atribuições para C_SpotlightEnd
    // C_SpotlightEnd Offsets
    C_SpotlightEnd.m_flLightScale = findOffsetByName(j, "C_SpotlightEnd", "m_flLightScale");
    C_SpotlightEnd.m_Radius = findOffsetByName(j, "C_SpotlightEnd", "m_Radius");

    // Atribuições para CEconItemAttribute
    // CEconItemAttribute Offsets
    CEconItemAttribute.m_iAttributeDefinitionIndex = findOffsetByName(j, "CEconItemAttribute", "m_iAttributeDefinitionIndex");
    CEconItemAttribute.m_flValue = findOffsetByName(j, "CEconItemAttribute", "m_flValue");
    CEconItemAttribute.m_flInitialValue = findOffsetByName(j, "CEconItemAttribute", "m_flInitialValue");
    CEconItemAttribute.m_nRefundableCurrency = findOffsetByName(j, "CEconItemAttribute", "m_nRefundableCurrency");
    CEconItemAttribute.m_bSetBonus = findOffsetByName(j, "CEconItemAttribute", "m_bSetBonus");

    // Atribuições para C_PointCamera
    // C_PointCamera Offsets
    C_PointCamera.m_FOV = findOffsetByName(j, "C_PointCamera", "m_FOV");
    C_PointCamera.m_Resolution = findOffsetByName(j, "C_PointCamera", "m_Resolution");
    C_PointCamera.m_bFogEnable = findOffsetByName(j, "C_PointCamera", "m_bFogEnable");
    C_PointCamera.m_FogColor = findOffsetByName(j, "C_PointCamera", "m_FogColor");
    C_PointCamera.m_flFogStart = findOffsetByName(j, "C_PointCamera", "m_flFogStart");
    C_PointCamera.m_flFogEnd = findOffsetByName(j, "C_PointCamera", "m_flFogEnd");
    C_PointCamera.m_flFogMaxDensity = findOffsetByName(j, "C_PointCamera", "m_flFogMaxDensity");
    C_PointCamera.m_bActive = findOffsetByName(j, "C_PointCamera", "m_bActive");
    C_PointCamera.m_bUseScreenAspectRatio = findOffsetByName(j, "C_PointCamera", "m_bUseScreenAspectRatio");
    C_PointCamera.m_flAspectRatio = findOffsetByName(j, "C_PointCamera", "m_flAspectRatio");
    C_PointCamera.m_bNoSky = findOffsetByName(j, "C_PointCamera", "m_bNoSky");
    C_PointCamera.m_fBrightness = findOffsetByName(j, "C_PointCamera", "m_fBrightness");
    C_PointCamera.m_flZFar = findOffsetByName(j, "C_PointCamera", "m_flZFar");
    C_PointCamera.m_flZNear = findOffsetByName(j, "C_PointCamera", "m_flZNear");
    C_PointCamera.m_bCanHLTVUse = findOffsetByName(j, "C_PointCamera", "m_bCanHLTVUse");
    C_PointCamera.m_bAlignWithParent = findOffsetByName(j, "C_PointCamera", "m_bAlignWithParent");
    C_PointCamera.m_bDofEnabled = findOffsetByName(j, "C_PointCamera", "m_bDofEnabled");
    C_PointCamera.m_flDofNearBlurry = findOffsetByName(j, "C_PointCamera", "m_flDofNearBlurry");
    C_PointCamera.m_flDofNearCrisp = findOffsetByName(j, "C_PointCamera", "m_flDofNearCrisp");
    C_PointCamera.m_flDofFarCrisp = findOffsetByName(j, "C_PointCamera", "m_flDofFarCrisp");
    C_PointCamera.m_flDofFarBlurry = findOffsetByName(j, "C_PointCamera", "m_flDofFarBlurry");
    C_PointCamera.m_flDofTiltToGround = findOffsetByName(j, "C_PointCamera", "m_flDofTiltToGround");
    C_PointCamera.m_TargetFOV = findOffsetByName(j, "C_PointCamera", "m_TargetFOV");
    C_PointCamera.m_DegreesPerSecond = findOffsetByName(j, "C_PointCamera", "m_DegreesPerSecond");
    C_PointCamera.m_bIsOn = findOffsetByName(j, "C_PointCamera", "m_bIsOn");
    C_PointCamera.m_pNext = findOffsetByName(j, "C_PointCamera", "m_pNext");

    // Atribuições para C_EnvWind
    // C_EnvWind Offsets
    C_EnvWind.m_EnvWindShared = findOffsetByName(j, "C_EnvWind", "m_EnvWindShared");

    // Atribuições para C_BaseCombatCharacter
    // C_BaseCombatCharacter Offsets
    C_BaseCombatCharacter.m_hMyWearables = findOffsetByName(j, "C_BaseCombatCharacter", "m_hMyWearables");
    C_BaseCombatCharacter.m_leftFootAttachment = findOffsetByName(j, "C_BaseCombatCharacter", "m_leftFootAttachment");
    C_BaseCombatCharacter.m_rightFootAttachment = findOffsetByName(j, "C_BaseCombatCharacter", "m_rightFootAttachment");
    C_BaseCombatCharacter.m_nWaterWakeMode = findOffsetByName(j, "C_BaseCombatCharacter", "m_nWaterWakeMode");
    C_BaseCombatCharacter.m_flWaterWorldZ = findOffsetByName(j, "C_BaseCombatCharacter", "m_flWaterWorldZ");
    C_BaseCombatCharacter.m_flWaterNextTraceTime = findOffsetByName(j, "C_BaseCombatCharacter", "m_flWaterNextTraceTime");

    // Atribuições para C_SoundEventSphereEntity
    // C_SoundEventSphereEntity Offsets
    C_SoundEventSphereEntity.m_flRadius = findOffsetByName(j, "C_SoundEventSphereEntity", "m_flRadius");

    // Atribuições para C_SceneEntity
    // C_SceneEntity Offsets
    C_SceneEntity.m_bIsPlayingBack = findOffsetByName(j, "C_SceneEntity", "m_bIsPlayingBack");
    C_SceneEntity.m_bPaused = findOffsetByName(j, "C_SceneEntity", "m_bPaused");
    C_SceneEntity.m_bMultiplayer = findOffsetByName(j, "C_SceneEntity", "m_bMultiplayer");
    C_SceneEntity.m_bAutogenerated = findOffsetByName(j, "C_SceneEntity", "m_bAutogenerated");
    C_SceneEntity.m_flForceClientTime = findOffsetByName(j, "C_SceneEntity", "m_flForceClientTime");
    C_SceneEntity.m_nSceneStringIndex = findOffsetByName(j, "C_SceneEntity", "m_nSceneStringIndex");
    C_SceneEntity.m_bClientOnly = findOffsetByName(j, "C_SceneEntity", "m_bClientOnly");
    C_SceneEntity.m_hOwner = findOffsetByName(j, "C_SceneEntity", "m_hOwner");
    C_SceneEntity.m_hActorList = findOffsetByName(j, "C_SceneEntity", "m_hActorList");
    C_SceneEntity.m_bWasPlaying = findOffsetByName(j, "C_SceneEntity", "m_bWasPlaying");
    C_SceneEntity.m_QueuedEvents = findOffsetByName(j, "C_SceneEntity", "m_QueuedEvents");
    C_SceneEntity.m_flCurrentTime = findOffsetByName(j, "C_SceneEntity", "m_flCurrentTime");

    // Atribuições para CPlayer_CameraServices
    // CPlayer_CameraServices Offsets
    CPlayer_CameraServices.m_vecCsViewPunchAngle = findOffsetByName(j, "CPlayer_CameraServices", "m_vecCsViewPunchAngle");
    CPlayer_CameraServices.m_nCsViewPunchAngleTick = findOffsetByName(j, "CPlayer_CameraServices", "m_nCsViewPunchAngleTick");
    CPlayer_CameraServices.m_flCsViewPunchAngleTickRatio = findOffsetByName(j, "CPlayer_CameraServices", "m_flCsViewPunchAngleTickRatio");
    CPlayer_CameraServices.m_PlayerFog = findOffsetByName(j, "CPlayer_CameraServices", "m_PlayerFog");
    CPlayer_CameraServices.m_hColorCorrectionCtrl = findOffsetByName(j, "CPlayer_CameraServices", "m_hColorCorrectionCtrl");
    CPlayer_CameraServices.m_hViewEntity = findOffsetByName(j, "CPlayer_CameraServices", "m_hViewEntity");
    CPlayer_CameraServices.m_hTonemapController = findOffsetByName(j, "CPlayer_CameraServices", "m_hTonemapController");
    CPlayer_CameraServices.m_audio = findOffsetByName(j, "CPlayer_CameraServices", "m_audio");
    CPlayer_CameraServices.m_PostProcessingVolumes = findOffsetByName(j, "CPlayer_CameraServices", "m_PostProcessingVolumes");
    CPlayer_CameraServices.m_flOldPlayerZ = findOffsetByName(j, "CPlayer_CameraServices", "m_flOldPlayerZ");
    CPlayer_CameraServices.m_flOldPlayerViewOffsetZ = findOffsetByName(j, "CPlayer_CameraServices", "m_flOldPlayerViewOffsetZ");
    CPlayer_CameraServices.m_CurrentFog = findOffsetByName(j, "CPlayer_CameraServices", "m_CurrentFog");
    CPlayer_CameraServices.m_hOldFogController = findOffsetByName(j, "CPlayer_CameraServices", "m_hOldFogController");
    CPlayer_CameraServices.m_bOverrideFogColor = findOffsetByName(j, "CPlayer_CameraServices", "m_bOverrideFogColor");
    CPlayer_CameraServices.m_OverrideFogColor = findOffsetByName(j, "CPlayer_CameraServices", "m_OverrideFogColor");
    CPlayer_CameraServices.m_bOverrideFogStartEnd = findOffsetByName(j, "CPlayer_CameraServices", "m_bOverrideFogStartEnd");
    CPlayer_CameraServices.m_fOverrideFogStart = findOffsetByName(j, "CPlayer_CameraServices", "m_fOverrideFogStart");
    CPlayer_CameraServices.m_fOverrideFogEnd = findOffsetByName(j, "CPlayer_CameraServices", "m_fOverrideFogEnd");
    CPlayer_CameraServices.m_hActivePostProcessingVolume = findOffsetByName(j, "CPlayer_CameraServices", "m_hActivePostProcessingVolume");
    CPlayer_CameraServices.m_angDemoViewAngles = findOffsetByName(j, "CPlayer_CameraServices", "m_angDemoViewAngles");

    // Atribuições para C_BaseCSGrenade
    // C_BaseCSGrenade Offsets
    C_BaseCSGrenade.m_bClientPredictDelete = findOffsetByName(j, "C_BaseCSGrenade", "m_bClientPredictDelete");
    C_BaseCSGrenade.m_bRedraw = findOffsetByName(j, "C_BaseCSGrenade", "m_bRedraw");
    C_BaseCSGrenade.m_bIsHeldByPlayer = findOffsetByName(j, "C_BaseCSGrenade", "m_bIsHeldByPlayer");
    C_BaseCSGrenade.m_bPinPulled = findOffsetByName(j, "C_BaseCSGrenade", "m_bPinPulled");
    C_BaseCSGrenade.m_bJumpThrow = findOffsetByName(j, "C_BaseCSGrenade", "m_bJumpThrow");
    C_BaseCSGrenade.m_bThrowAnimating = findOffsetByName(j, "C_BaseCSGrenade", "m_bThrowAnimating");
    C_BaseCSGrenade.m_fThrowTime = findOffsetByName(j, "C_BaseCSGrenade", "m_fThrowTime");
    C_BaseCSGrenade.m_flThrowStrength = findOffsetByName(j, "C_BaseCSGrenade", "m_flThrowStrength");
    C_BaseCSGrenade.m_flThrowStrengthApproach = findOffsetByName(j, "C_BaseCSGrenade", "m_flThrowStrengthApproach");
    C_BaseCSGrenade.m_fDropTime = findOffsetByName(j, "C_BaseCSGrenade", "m_fDropTime");
    C_BaseCSGrenade.m_fPinPullTime = findOffsetByName(j, "C_BaseCSGrenade", "m_fPinPullTime");
    C_BaseCSGrenade.m_bJustPulledPin = findOffsetByName(j, "C_BaseCSGrenade", "m_bJustPulledPin");
    C_BaseCSGrenade.m_nNextHoldTick = findOffsetByName(j, "C_BaseCSGrenade", "m_nNextHoldTick");
    C_BaseCSGrenade.m_flNextHoldFrac = findOffsetByName(j, "C_BaseCSGrenade", "m_flNextHoldFrac");
    C_BaseCSGrenade.m_hSwitchToWeaponAfterThrow = findOffsetByName(j, "C_BaseCSGrenade", "m_hSwitchToWeaponAfterThrow");

    // Atribuições para C_FuncMonitor
    // C_FuncMonitor Offsets
    C_FuncMonitor.m_targetCamera = findOffsetByName(j, "C_FuncMonitor", "m_targetCamera");
    C_FuncMonitor.m_nResolutionEnum = findOffsetByName(j, "C_FuncMonitor", "m_nResolutionEnum");
    C_FuncMonitor.m_bRenderShadows = findOffsetByName(j, "C_FuncMonitor", "m_bRenderShadows");
    C_FuncMonitor.m_bUseUniqueColorTarget = findOffsetByName(j, "C_FuncMonitor", "m_bUseUniqueColorTarget");
    C_FuncMonitor.m_brushModelName = findOffsetByName(j, "C_FuncMonitor", "m_brushModelName");
    C_FuncMonitor.m_hTargetCamera = findOffsetByName(j, "C_FuncMonitor", "m_hTargetCamera");
    C_FuncMonitor.m_bEnabled = findOffsetByName(j, "C_FuncMonitor", "m_bEnabled");
    C_FuncMonitor.m_bDraw3DSkybox = findOffsetByName(j, "C_FuncMonitor", "m_bDraw3DSkybox");

    // Atribuições para C_RopeKeyframe__CPhysicsDelegate
    // C_RopeKeyframe__CPhysicsDelegate Offsets
    C_RopeKeyframe__CPhysicsDelegate.m_pKeyframe = findOffsetByName(j, "C_RopeKeyframe__CPhysicsDelegate", "m_pKeyframe");

    // Atribuições para CBodyComponent
    // CBodyComponent Offsets
    CBodyComponent.m_pSceneNode = findOffsetByName(j, "CBodyComponent", "m_pSceneNode");
    CBodyComponent.__m_pChainEntity = findOffsetByName(j, "CBodyComponent", "__m_pChainEntity");

    // Atribuições para C_SoundAreaEntitySphere
    // C_SoundAreaEntitySphere Offsets
    C_SoundAreaEntitySphere.m_flRadius = findOffsetByName(j, "C_SoundAreaEntitySphere", "m_flRadius");

    // Atribuições para C_LightGlow
    // C_LightGlow Offsets
    C_LightGlow.m_nHorizontalSize = findOffsetByName(j, "C_LightGlow", "m_nHorizontalSize");
    C_LightGlow.m_nVerticalSize = findOffsetByName(j, "C_LightGlow", "m_nVerticalSize");
    C_LightGlow.m_nMinDist = findOffsetByName(j, "C_LightGlow", "m_nMinDist");
    C_LightGlow.m_nMaxDist = findOffsetByName(j, "C_LightGlow", "m_nMaxDist");
    C_LightGlow.m_nOuterMaxDist = findOffsetByName(j, "C_LightGlow", "m_nOuterMaxDist");
    C_LightGlow.m_flGlowProxySize = findOffsetByName(j, "C_LightGlow", "m_flGlowProxySize");
    C_LightGlow.m_flHDRColorScale = findOffsetByName(j, "C_LightGlow", "m_flHDRColorScale");
    C_LightGlow.m_GlowOverlay = findOffsetByName(j, "C_LightGlow", "m_GlowOverlay");

    // Atribuições para CountdownTimer
    // CountdownTimer Offsets
    CountdownTimer.m_duration = findOffsetByName(j, "CountdownTimer", "m_duration");
    CountdownTimer.m_timestamp = findOffsetByName(j, "CountdownTimer", "m_timestamp");
    CountdownTimer.m_timescale = findOffsetByName(j, "CountdownTimer", "m_timescale");
    CountdownTimer.m_nWorldGroupId = findOffsetByName(j, "CountdownTimer", "m_nWorldGroupId");

    // Atribuições para CGameSceneNodeHandle
    // CGameSceneNodeHandle Offsets
    CGameSceneNodeHandle.m_hOwner = findOffsetByName(j, "CGameSceneNodeHandle", "m_hOwner");
    CGameSceneNodeHandle.m_name = findOffsetByName(j, "CGameSceneNodeHandle", "m_name");

    // Atribuições para PredictedDamageTag_t
    // PredictedDamageTag_t Offsets
    PredictedDamageTag_t.nTagTick = findOffsetByName(j, "PredictedDamageTag_t", "nTagTick");
    PredictedDamageTag_t.flFlinchModSmall = findOffsetByName(j, "PredictedDamageTag_t", "flFlinchModSmall");
    PredictedDamageTag_t.flFlinchModLarge = findOffsetByName(j, "PredictedDamageTag_t", "flFlinchModLarge");
    PredictedDamageTag_t.flFriendlyFireDamageReductionRatio = findOffsetByName(j, "PredictedDamageTag_t", "flFriendlyFireDamageReductionRatio");

    // Atribuições para C_ClientRagdoll
    // C_ClientRagdoll Offsets
    C_ClientRagdoll.m_bFadeOut = findOffsetByName(j, "C_ClientRagdoll", "m_bFadeOut");
    C_ClientRagdoll.m_bImportant = findOffsetByName(j, "C_ClientRagdoll", "m_bImportant");
    C_ClientRagdoll.m_flEffectTime = findOffsetByName(j, "C_ClientRagdoll", "m_flEffectTime");
    C_ClientRagdoll.m_gibDespawnTime = findOffsetByName(j, "C_ClientRagdoll", "m_gibDespawnTime");
    C_ClientRagdoll.m_iCurrentFriction = findOffsetByName(j, "C_ClientRagdoll", "m_iCurrentFriction");
    C_ClientRagdoll.m_iMinFriction = findOffsetByName(j, "C_ClientRagdoll", "m_iMinFriction");
    C_ClientRagdoll.m_iMaxFriction = findOffsetByName(j, "C_ClientRagdoll", "m_iMaxFriction");
    C_ClientRagdoll.m_iFrictionAnimState = findOffsetByName(j, "C_ClientRagdoll", "m_iFrictionAnimState");
    C_ClientRagdoll.m_bReleaseRagdoll = findOffsetByName(j, "C_ClientRagdoll", "m_bReleaseRagdoll");
    C_ClientRagdoll.m_iEyeAttachment = findOffsetByName(j, "C_ClientRagdoll", "m_iEyeAttachment");
    C_ClientRagdoll.m_bFadingOut = findOffsetByName(j, "C_ClientRagdoll", "m_bFadingOut");
    C_ClientRagdoll.m_flScaleEnd = findOffsetByName(j, "C_ClientRagdoll", "m_flScaleEnd");
    C_ClientRagdoll.m_flScaleTimeStart = findOffsetByName(j, "C_ClientRagdoll", "m_flScaleTimeStart");
    C_ClientRagdoll.m_flScaleTimeEnd = findOffsetByName(j, "C_ClientRagdoll", "m_flScaleTimeEnd");

    // Atribuições para C_GlobalLight
    // C_GlobalLight Offsets
    C_GlobalLight.m_WindClothForceHandle = findOffsetByName(j, "C_GlobalLight", "m_WindClothForceHandle");

    // Atribuições para C_CSPlayerResource
    // C_CSPlayerResource Offsets
    C_CSPlayerResource.m_bHostageAlive = findOffsetByName(j, "C_CSPlayerResource", "m_bHostageAlive");
    C_CSPlayerResource.m_isHostageFollowingSomeone = findOffsetByName(j, "C_CSPlayerResource", "m_isHostageFollowingSomeone");
    C_CSPlayerResource.m_iHostageEntityIDs = findOffsetByName(j, "C_CSPlayerResource", "m_iHostageEntityIDs");
    C_CSPlayerResource.m_bombsiteCenterA = findOffsetByName(j, "C_CSPlayerResource", "m_bombsiteCenterA");
    C_CSPlayerResource.m_bombsiteCenterB = findOffsetByName(j, "C_CSPlayerResource", "m_bombsiteCenterB");
    C_CSPlayerResource.m_hostageRescueX = findOffsetByName(j, "C_CSPlayerResource", "m_hostageRescueX");
    C_CSPlayerResource.m_hostageRescueY = findOffsetByName(j, "C_CSPlayerResource", "m_hostageRescueY");
    C_CSPlayerResource.m_hostageRescueZ = findOffsetByName(j, "C_CSPlayerResource", "m_hostageRescueZ");
    C_CSPlayerResource.m_bEndMatchNextMapAllVoted = findOffsetByName(j, "C_CSPlayerResource", "m_bEndMatchNextMapAllVoted");
    C_CSPlayerResource.m_foundGoalPositions = findOffsetByName(j, "C_CSPlayerResource", "m_foundGoalPositions");

    // Atribuições para CSkeletonInstance
    // CSkeletonInstance Offsets
    CSkeletonInstance.m_modelState = findOffsetByName(j, "CSkeletonInstance", "m_modelState");
    CSkeletonInstance.m_bIsAnimationEnabled = findOffsetByName(j, "CSkeletonInstance", "m_bIsAnimationEnabled");
    CSkeletonInstance.m_bUseParentRenderBounds = findOffsetByName(j, "CSkeletonInstance", "m_bUseParentRenderBounds");
    CSkeletonInstance.m_bDisableSolidCollisionsForHierarchy = findOffsetByName(j, "CSkeletonInstance", "m_bDisableSolidCollisionsForHierarchy");
    CSkeletonInstance.m_bDirtyMotionType = findOffsetByName(j, "CSkeletonInstance", "m_bDirtyMotionType");
    CSkeletonInstance.m_bIsGeneratingLatchedParentSpaceState = findOffsetByName(j, "CSkeletonInstance", "m_bIsGeneratingLatchedParentSpaceState");
    CSkeletonInstance.m_materialGroup = findOffsetByName(j, "CSkeletonInstance", "m_materialGroup");
    CSkeletonInstance.m_nHitboxSet = findOffsetByName(j, "CSkeletonInstance", "m_nHitboxSet");

    // Atribuições para CBodyComponentBaseAnimGraph
    // CBodyComponentBaseAnimGraph Offsets
    CBodyComponentBaseAnimGraph.m_animationController = findOffsetByName(j, "CBodyComponentBaseAnimGraph", "m_animationController");

    // Atribuições para CBodyComponentPoint
    // CBodyComponentPoint Offsets
    CBodyComponentPoint.m_sceneNode = findOffsetByName(j, "CBodyComponentPoint", "m_sceneNode");

    // Atribuições para C_SmokeGrenadeProjectile
    // C_SmokeGrenadeProjectile Offsets
    C_SmokeGrenadeProjectile.m_nSmokeEffectTickBegin = findOffsetByName(j, "C_SmokeGrenadeProjectile", "m_nSmokeEffectTickBegin");
    C_SmokeGrenadeProjectile.m_bDidSmokeEffect = findOffsetByName(j, "C_SmokeGrenadeProjectile", "m_bDidSmokeEffect");
    C_SmokeGrenadeProjectile.m_nRandomSeed = findOffsetByName(j, "C_SmokeGrenadeProjectile", "m_nRandomSeed");
    C_SmokeGrenadeProjectile.m_vSmokeColor = findOffsetByName(j, "C_SmokeGrenadeProjectile", "m_vSmokeColor");
    C_SmokeGrenadeProjectile.m_vSmokeDetonationPos = findOffsetByName(j, "C_SmokeGrenadeProjectile", "m_vSmokeDetonationPos");
    C_SmokeGrenadeProjectile.m_VoxelFrameData = findOffsetByName(j, "C_SmokeGrenadeProjectile", "m_VoxelFrameData");
    C_SmokeGrenadeProjectile.m_nVoxelFrameDataSize = findOffsetByName(j, "C_SmokeGrenadeProjectile", "m_nVoxelFrameDataSize");
    C_SmokeGrenadeProjectile.m_nVoxelUpdate = findOffsetByName(j, "C_SmokeGrenadeProjectile", "m_nVoxelUpdate");
    C_SmokeGrenadeProjectile.m_bSmokeVolumeDataReceived = findOffsetByName(j, "C_SmokeGrenadeProjectile", "m_bSmokeVolumeDataReceived");
    C_SmokeGrenadeProjectile.m_bSmokeEffectSpawned = findOffsetByName(j, "C_SmokeGrenadeProjectile", "m_bSmokeEffectSpawned");

    // Atribuições para C_CSGO_MapPreviewCameraPath
    // C_CSGO_MapPreviewCameraPath Offsets
    C_CSGO_MapPreviewCameraPath.m_flZFar = findOffsetByName(j, "C_CSGO_MapPreviewCameraPath", "m_flZFar");
    C_CSGO_MapPreviewCameraPath.m_flZNear = findOffsetByName(j, "C_CSGO_MapPreviewCameraPath", "m_flZNear");
    C_CSGO_MapPreviewCameraPath.m_bLoop = findOffsetByName(j, "C_CSGO_MapPreviewCameraPath", "m_bLoop");
    C_CSGO_MapPreviewCameraPath.m_bVerticalFOV = findOffsetByName(j, "C_CSGO_MapPreviewCameraPath", "m_bVerticalFOV");
    C_CSGO_MapPreviewCameraPath.m_bConstantSpeed = findOffsetByName(j, "C_CSGO_MapPreviewCameraPath", "m_bConstantSpeed");
    C_CSGO_MapPreviewCameraPath.m_flDuration = findOffsetByName(j, "C_CSGO_MapPreviewCameraPath", "m_flDuration");
    C_CSGO_MapPreviewCameraPath.m_flPathLength = findOffsetByName(j, "C_CSGO_MapPreviewCameraPath", "m_flPathLength");
    C_CSGO_MapPreviewCameraPath.m_flPathDuration = findOffsetByName(j, "C_CSGO_MapPreviewCameraPath", "m_flPathDuration");

    // Atribuições para C_Inferno
    // C_Inferno Offsets
    C_Inferno.m_nfxFireDamageEffect = findOffsetByName(j, "C_Inferno", "m_nfxFireDamageEffect");
    C_Inferno.m_hInfernoPointsSnapshot = findOffsetByName(j, "C_Inferno", "m_hInfernoPointsSnapshot");
    C_Inferno.m_hInfernoFillerPointsSnapshot = findOffsetByName(j, "C_Inferno", "m_hInfernoFillerPointsSnapshot");
    C_Inferno.m_hInfernoOutlinePointsSnapshot = findOffsetByName(j, "C_Inferno", "m_hInfernoOutlinePointsSnapshot");
    C_Inferno.m_hInfernoClimbingOutlinePointsSnapshot = findOffsetByName(j, "C_Inferno", "m_hInfernoClimbingOutlinePointsSnapshot");
    C_Inferno.m_hInfernoDecalsSnapshot = findOffsetByName(j, "C_Inferno", "m_hInfernoDecalsSnapshot");
    C_Inferno.m_firePositions = findOffsetByName(j, "C_Inferno", "m_firePositions");
    C_Inferno.m_fireParentPositions = findOffsetByName(j, "C_Inferno", "m_fireParentPositions");
    C_Inferno.m_bFireIsBurning = findOffsetByName(j, "C_Inferno", "m_bFireIsBurning");
    C_Inferno.m_BurnNormal = findOffsetByName(j, "C_Inferno", "m_BurnNormal");
    C_Inferno.m_fireCount = findOffsetByName(j, "C_Inferno", "m_fireCount");
    C_Inferno.m_nInfernoType = findOffsetByName(j, "C_Inferno", "m_nInfernoType");
    C_Inferno.m_nFireLifetime = findOffsetByName(j, "C_Inferno", "m_nFireLifetime");
    C_Inferno.m_bInPostEffectTime = findOffsetByName(j, "C_Inferno", "m_bInPostEffectTime");
    C_Inferno.m_lastFireCount = findOffsetByName(j, "C_Inferno", "m_lastFireCount");
    C_Inferno.m_nFireEffectTickBegin = findOffsetByName(j, "C_Inferno", "m_nFireEffectTickBegin");
    C_Inferno.m_drawableCount = findOffsetByName(j, "C_Inferno", "m_drawableCount");
    C_Inferno.m_blosCheck = findOffsetByName(j, "C_Inferno", "m_blosCheck");
    C_Inferno.m_nlosperiod = findOffsetByName(j, "C_Inferno", "m_nlosperiod");
    C_Inferno.m_maxFireHalfWidth = findOffsetByName(j, "C_Inferno", "m_maxFireHalfWidth");
    C_Inferno.m_maxFireHeight = findOffsetByName(j, "C_Inferno", "m_maxFireHeight");
    C_Inferno.m_minBounds = findOffsetByName(j, "C_Inferno", "m_minBounds");
    C_Inferno.m_maxBounds = findOffsetByName(j, "C_Inferno", "m_maxBounds");
    C_Inferno.m_flLastGrassBurnThink = findOffsetByName(j, "C_Inferno", "m_flLastGrassBurnThink");

    // Atribuições para C_PlayerPing
    // C_PlayerPing Offsets
    C_PlayerPing.m_hPlayer = findOffsetByName(j, "C_PlayerPing", "m_hPlayer");
    C_PlayerPing.m_hPingedEntity = findOffsetByName(j, "C_PlayerPing", "m_hPingedEntity");
    C_PlayerPing.m_iType = findOffsetByName(j, "C_PlayerPing", "m_iType");
    C_PlayerPing.m_bUrgent = findOffsetByName(j, "C_PlayerPing", "m_bUrgent");
    C_PlayerPing.m_szPlaceName = findOffsetByName(j, "C_PlayerPing", "m_szPlaceName");

    // Atribuições para C_CSTeam
    // C_CSTeam Offsets
    C_CSTeam.m_szTeamMatchStat = findOffsetByName(j, "C_CSTeam", "m_szTeamMatchStat");
    C_CSTeam.m_numMapVictories = findOffsetByName(j, "C_CSTeam", "m_numMapVictories");
    C_CSTeam.m_bSurrendered = findOffsetByName(j, "C_CSTeam", "m_bSurrendered");
    C_CSTeam.m_scoreFirstHalf = findOffsetByName(j, "C_CSTeam", "m_scoreFirstHalf");
    C_CSTeam.m_scoreSecondHalf = findOffsetByName(j, "C_CSTeam", "m_scoreSecondHalf");
    C_CSTeam.m_scoreOvertime = findOffsetByName(j, "C_CSTeam", "m_scoreOvertime");
    C_CSTeam.m_szClanTeamname = findOffsetByName(j, "C_CSTeam", "m_szClanTeamname");
    C_CSTeam.m_iClanID = findOffsetByName(j, "C_CSTeam", "m_iClanID");
    C_CSTeam.m_szTeamFlagImage = findOffsetByName(j, "C_CSTeam", "m_szTeamFlagImage");
    C_CSTeam.m_szTeamLogoImage = findOffsetByName(j, "C_CSTeam", "m_szTeamLogoImage");

    // Atribuições para C_CSGO_MapPreviewCameraPathNode
    // C_CSGO_MapPreviewCameraPathNode Offsets
    C_CSGO_MapPreviewCameraPathNode.m_szParentPathUniqueID = findOffsetByName(j, "C_CSGO_MapPreviewCameraPathNode", "m_szParentPathUniqueID");
    C_CSGO_MapPreviewCameraPathNode.m_nPathIndex = findOffsetByName(j, "C_CSGO_MapPreviewCameraPathNode", "m_nPathIndex");
    C_CSGO_MapPreviewCameraPathNode.m_vInTangentLocal = findOffsetByName(j, "C_CSGO_MapPreviewCameraPathNode", "m_vInTangentLocal");
    C_CSGO_MapPreviewCameraPathNode.m_vOutTangentLocal = findOffsetByName(j, "C_CSGO_MapPreviewCameraPathNode", "m_vOutTangentLocal");
    C_CSGO_MapPreviewCameraPathNode.m_flFOV = findOffsetByName(j, "C_CSGO_MapPreviewCameraPathNode", "m_flFOV");
    C_CSGO_MapPreviewCameraPathNode.m_flCameraSpeed = findOffsetByName(j, "C_CSGO_MapPreviewCameraPathNode", "m_flCameraSpeed");
    C_CSGO_MapPreviewCameraPathNode.m_flEaseIn = findOffsetByName(j, "C_CSGO_MapPreviewCameraPathNode", "m_flEaseIn");
    C_CSGO_MapPreviewCameraPathNode.m_flEaseOut = findOffsetByName(j, "C_CSGO_MapPreviewCameraPathNode", "m_flEaseOut");
    C_CSGO_MapPreviewCameraPathNode.m_vInTangentWorld = findOffsetByName(j, "C_CSGO_MapPreviewCameraPathNode", "m_vInTangentWorld");
    C_CSGO_MapPreviewCameraPathNode.m_vOutTangentWorld = findOffsetByName(j, "C_CSGO_MapPreviewCameraPathNode", "m_vOutTangentWorld");

    // Atribuições para C_CSPlayerPawn
    // C_CSPlayerPawn Offsets
    C_CSPlayerPawn.m_pBulletServices = findOffsetByName(j, "C_CSPlayerPawn", "m_pBulletServices");
    C_CSPlayerPawn.m_pHostageServices = findOffsetByName(j, "C_CSPlayerPawn", "m_pHostageServices");
    C_CSPlayerPawn.m_pBuyServices = findOffsetByName(j, "C_CSPlayerPawn", "m_pBuyServices");
    C_CSPlayerPawn.m_pGlowServices = findOffsetByName(j, "C_CSPlayerPawn", "m_pGlowServices");
    C_CSPlayerPawn.m_pActionTrackingServices = findOffsetByName(j, "C_CSPlayerPawn", "m_pActionTrackingServices");
    C_CSPlayerPawn.m_pDamageReactServices = findOffsetByName(j, "C_CSPlayerPawn", "m_pDamageReactServices");
    C_CSPlayerPawn.m_flHealthShotBoostExpirationTime = findOffsetByName(j, "C_CSPlayerPawn", "m_flHealthShotBoostExpirationTime");
    C_CSPlayerPawn.m_flLastFiredWeaponTime = findOffsetByName(j, "C_CSPlayerPawn", "m_flLastFiredWeaponTime");
    C_CSPlayerPawn.m_bHasFemaleVoice = findOffsetByName(j, "C_CSPlayerPawn", "m_bHasFemaleVoice");
    C_CSPlayerPawn.m_flLandingTimeSeconds = findOffsetByName(j, "C_CSPlayerPawn", "m_flLandingTimeSeconds");
    C_CSPlayerPawn.m_flOldFallVelocity = findOffsetByName(j, "C_CSPlayerPawn", "m_flOldFallVelocity");
    C_CSPlayerPawn.m_szLastPlaceName = findOffsetByName(j, "C_CSPlayerPawn", "m_szLastPlaceName");
    C_CSPlayerPawn.m_bPrevDefuser = findOffsetByName(j, "C_CSPlayerPawn", "m_bPrevDefuser");
    C_CSPlayerPawn.m_bPrevHelmet = findOffsetByName(j, "C_CSPlayerPawn", "m_bPrevHelmet");
    C_CSPlayerPawn.m_nPrevArmorVal = findOffsetByName(j, "C_CSPlayerPawn", "m_nPrevArmorVal");
    C_CSPlayerPawn.m_nPrevGrenadeAmmoCount = findOffsetByName(j, "C_CSPlayerPawn", "m_nPrevGrenadeAmmoCount");
    C_CSPlayerPawn.m_unPreviousWeaponHash = findOffsetByName(j, "C_CSPlayerPawn", "m_unPreviousWeaponHash");
    C_CSPlayerPawn.m_unWeaponHash = findOffsetByName(j, "C_CSPlayerPawn", "m_unWeaponHash");
    C_CSPlayerPawn.m_bInBuyZone = findOffsetByName(j, "C_CSPlayerPawn", "m_bInBuyZone");
    C_CSPlayerPawn.m_bPreviouslyInBuyZone = findOffsetByName(j, "C_CSPlayerPawn", "m_bPreviouslyInBuyZone");
    C_CSPlayerPawn.m_aimPunchAngle = findOffsetByName(j, "C_CSPlayerPawn", "m_aimPunchAngle");
    C_CSPlayerPawn.m_aimPunchAngleVel = findOffsetByName(j, "C_CSPlayerPawn", "m_aimPunchAngleVel");
    C_CSPlayerPawn.m_aimPunchTickBase = findOffsetByName(j, "C_CSPlayerPawn", "m_aimPunchTickBase");
    C_CSPlayerPawn.m_aimPunchTickFraction = findOffsetByName(j, "C_CSPlayerPawn", "m_aimPunchTickFraction");
    C_CSPlayerPawn.m_aimPunchCache = findOffsetByName(j, "C_CSPlayerPawn", "m_aimPunchCache");
    C_CSPlayerPawn.m_bInLanding = findOffsetByName(j, "C_CSPlayerPawn", "m_bInLanding");
    C_CSPlayerPawn.m_flLandingStartTime = findOffsetByName(j, "C_CSPlayerPawn", "m_flLandingStartTime");
    C_CSPlayerPawn.m_bInHostageRescueZone = findOffsetByName(j, "C_CSPlayerPawn", "m_bInHostageRescueZone");
    C_CSPlayerPawn.m_bInBombZone = findOffsetByName(j, "C_CSPlayerPawn", "m_bInBombZone");
    C_CSPlayerPawn.m_bIsBuyMenuOpen = findOffsetByName(j, "C_CSPlayerPawn", "m_bIsBuyMenuOpen");
    C_CSPlayerPawn.m_flTimeOfLastInjury = findOffsetByName(j, "C_CSPlayerPawn", "m_flTimeOfLastInjury");
    C_CSPlayerPawn.m_flNextSprayDecalTime = findOffsetByName(j, "C_CSPlayerPawn", "m_flNextSprayDecalTime");
    C_CSPlayerPawn.m_iRetakesOffering = findOffsetByName(j, "C_CSPlayerPawn", "m_iRetakesOffering");
    C_CSPlayerPawn.m_iRetakesOfferingCard = findOffsetByName(j, "C_CSPlayerPawn", "m_iRetakesOfferingCard");
    C_CSPlayerPawn.m_bRetakesHasDefuseKit = findOffsetByName(j, "C_CSPlayerPawn", "m_bRetakesHasDefuseKit");
    C_CSPlayerPawn.m_bRetakesMVPLastRound = findOffsetByName(j, "C_CSPlayerPawn", "m_bRetakesMVPLastRound");
    C_CSPlayerPawn.m_iRetakesMVPBoostItem = findOffsetByName(j, "C_CSPlayerPawn", "m_iRetakesMVPBoostItem");
    C_CSPlayerPawn.m_RetakesMVPBoostExtraUtility = findOffsetByName(j, "C_CSPlayerPawn", "m_RetakesMVPBoostExtraUtility");
    C_CSPlayerPawn.m_bNeedToReApplyGloves = findOffsetByName(j, "C_CSPlayerPawn", "m_bNeedToReApplyGloves");
    C_CSPlayerPawn.m_EconGloves = findOffsetByName(j, "C_CSPlayerPawn", "m_EconGloves");
    C_CSPlayerPawn.m_nEconGlovesChanged = findOffsetByName(j, "C_CSPlayerPawn", "m_nEconGlovesChanged");
    C_CSPlayerPawn.m_bMustSyncRagdollState = findOffsetByName(j, "C_CSPlayerPawn", "m_bMustSyncRagdollState");
    C_CSPlayerPawn.m_nRagdollDamageBone = findOffsetByName(j, "C_CSPlayerPawn", "m_nRagdollDamageBone");
    C_CSPlayerPawn.m_vRagdollDamageForce = findOffsetByName(j, "C_CSPlayerPawn", "m_vRagdollDamageForce");
    C_CSPlayerPawn.m_vRagdollDamagePosition = findOffsetByName(j, "C_CSPlayerPawn", "m_vRagdollDamagePosition");
    C_CSPlayerPawn.m_szRagdollDamageWeaponName = findOffsetByName(j, "C_CSPlayerPawn", "m_szRagdollDamageWeaponName");
    C_CSPlayerPawn.m_bRagdollDamageHeadshot = findOffsetByName(j, "C_CSPlayerPawn", "m_bRagdollDamageHeadshot");
    C_CSPlayerPawn.m_vRagdollServerOrigin = findOffsetByName(j, "C_CSPlayerPawn", "m_vRagdollServerOrigin");
    C_CSPlayerPawn.m_bLastHeadBoneTransformIsValid = findOffsetByName(j, "C_CSPlayerPawn", "m_bLastHeadBoneTransformIsValid");
    C_CSPlayerPawn.m_lastLandTime = findOffsetByName(j, "C_CSPlayerPawn", "m_lastLandTime");
    C_CSPlayerPawn.m_bOnGroundLastTick = findOffsetByName(j, "C_CSPlayerPawn", "m_bOnGroundLastTick");
    C_CSPlayerPawn.m_qDeathEyeAngles = findOffsetByName(j, "C_CSPlayerPawn", "m_qDeathEyeAngles");
    C_CSPlayerPawn.m_bSkipOneHeadConstraintUpdate = findOffsetByName(j, "C_CSPlayerPawn", "m_bSkipOneHeadConstraintUpdate");
    C_CSPlayerPawn.m_bLeftHanded = findOffsetByName(j, "C_CSPlayerPawn", "m_bLeftHanded");
    C_CSPlayerPawn.m_fSwitchedHandednessTime = findOffsetByName(j, "C_CSPlayerPawn", "m_fSwitchedHandednessTime");
    C_CSPlayerPawn.m_flViewmodelOffsetX = findOffsetByName(j, "C_CSPlayerPawn", "m_flViewmodelOffsetX");
    C_CSPlayerPawn.m_flViewmodelOffsetY = findOffsetByName(j, "C_CSPlayerPawn", "m_flViewmodelOffsetY");
    C_CSPlayerPawn.m_flViewmodelOffsetZ = findOffsetByName(j, "C_CSPlayerPawn", "m_flViewmodelOffsetZ");
    C_CSPlayerPawn.m_flViewmodelFOV = findOffsetByName(j, "C_CSPlayerPawn", "m_flViewmodelFOV");
    C_CSPlayerPawn.m_vecPlayerPatchEconIndices = findOffsetByName(j, "C_CSPlayerPawn", "m_vecPlayerPatchEconIndices");
    C_CSPlayerPawn.m_GunGameImmunityColor = findOffsetByName(j, "C_CSPlayerPawn", "m_GunGameImmunityColor");
    C_CSPlayerPawn.m_vecBulletHitModels = findOffsetByName(j, "C_CSPlayerPawn", "m_vecBulletHitModels");
    C_CSPlayerPawn.m_bIsWalking = findOffsetByName(j, "C_CSPlayerPawn", "m_bIsWalking");
    C_CSPlayerPawn.m_thirdPersonHeading = findOffsetByName(j, "C_CSPlayerPawn", "m_thirdPersonHeading");
    C_CSPlayerPawn.m_flSlopeDropOffset = findOffsetByName(j, "C_CSPlayerPawn", "m_flSlopeDropOffset");
    C_CSPlayerPawn.m_flSlopeDropHeight = findOffsetByName(j, "C_CSPlayerPawn", "m_flSlopeDropHeight");
    C_CSPlayerPawn.m_vHeadConstraintOffset = findOffsetByName(j, "C_CSPlayerPawn", "m_vHeadConstraintOffset");
    C_CSPlayerPawn.m_entitySpottedState = findOffsetByName(j, "C_CSPlayerPawn", "m_entitySpottedState");
    C_CSPlayerPawn.m_bIsScoped = findOffsetByName(j, "C_CSPlayerPawn", "m_bIsScoped");
    C_CSPlayerPawn.m_bResumeZoom = findOffsetByName(j, "C_CSPlayerPawn", "m_bResumeZoom");
    C_CSPlayerPawn.m_bIsDefusing = findOffsetByName(j, "C_CSPlayerPawn", "m_bIsDefusing");
    C_CSPlayerPawn.m_bIsGrabbingHostage = findOffsetByName(j, "C_CSPlayerPawn", "m_bIsGrabbingHostage");
    C_CSPlayerPawn.m_iBlockingUseActionInProgress = findOffsetByName(j, "C_CSPlayerPawn", "m_iBlockingUseActionInProgress");
    C_CSPlayerPawn.m_flEmitSoundTime = findOffsetByName(j, "C_CSPlayerPawn", "m_flEmitSoundTime");
    C_CSPlayerPawn.m_bInNoDefuseArea = findOffsetByName(j, "C_CSPlayerPawn", "m_bInNoDefuseArea");
    C_CSPlayerPawn.m_nWhichBombZone = findOffsetByName(j, "C_CSPlayerPawn", "m_nWhichBombZone");
    C_CSPlayerPawn.m_iShotsFired = findOffsetByName(j, "C_CSPlayerPawn", "m_iShotsFired");
    C_CSPlayerPawn.m_flFlinchStack = findOffsetByName(j, "C_CSPlayerPawn", "m_flFlinchStack");
    C_CSPlayerPawn.m_flVelocityModifier = findOffsetByName(j, "C_CSPlayerPawn", "m_flVelocityModifier");
    C_CSPlayerPawn.m_flHitHeading = findOffsetByName(j, "C_CSPlayerPawn", "m_flHitHeading");
    C_CSPlayerPawn.m_nHitBodyPart = findOffsetByName(j, "C_CSPlayerPawn", "m_nHitBodyPart");
    C_CSPlayerPawn.m_bWaitForNoAttack = findOffsetByName(j, "C_CSPlayerPawn", "m_bWaitForNoAttack");
    C_CSPlayerPawn.m_ignoreLadderJumpTime = findOffsetByName(j, "C_CSPlayerPawn", "m_ignoreLadderJumpTime");
    C_CSPlayerPawn.m_bKilledByHeadshot = findOffsetByName(j, "C_CSPlayerPawn", "m_bKilledByHeadshot");
    C_CSPlayerPawn.m_ArmorValue = findOffsetByName(j, "C_CSPlayerPawn", "m_ArmorValue");
    C_CSPlayerPawn.m_unCurrentEquipmentValue = findOffsetByName(j, "C_CSPlayerPawn", "m_unCurrentEquipmentValue");
    C_CSPlayerPawn.m_unRoundStartEquipmentValue = findOffsetByName(j, "C_CSPlayerPawn", "m_unRoundStartEquipmentValue");
    C_CSPlayerPawn.m_unFreezetimeEndEquipmentValue = findOffsetByName(j, "C_CSPlayerPawn", "m_unFreezetimeEndEquipmentValue");
    C_CSPlayerPawn.m_nLastKillerIndex = findOffsetByName(j, "C_CSPlayerPawn", "m_nLastKillerIndex");
    C_CSPlayerPawn.m_bOldIsScoped = findOffsetByName(j, "C_CSPlayerPawn", "m_bOldIsScoped");
    C_CSPlayerPawn.m_bHasDeathInfo = findOffsetByName(j, "C_CSPlayerPawn", "m_bHasDeathInfo");
    C_CSPlayerPawn.m_flDeathInfoTime = findOffsetByName(j, "C_CSPlayerPawn", "m_flDeathInfoTime");
    C_CSPlayerPawn.m_vecDeathInfoOrigin = findOffsetByName(j, "C_CSPlayerPawn", "m_vecDeathInfoOrigin");
    C_CSPlayerPawn.m_grenadeParameterStashTime = findOffsetByName(j, "C_CSPlayerPawn", "m_grenadeParameterStashTime");
    C_CSPlayerPawn.m_bGrenadeParametersStashed = findOffsetByName(j, "C_CSPlayerPawn", "m_bGrenadeParametersStashed");
    C_CSPlayerPawn.m_angStashedShootAngles = findOffsetByName(j, "C_CSPlayerPawn", "m_angStashedShootAngles");
    C_CSPlayerPawn.m_vecStashedGrenadeThrowPosition = findOffsetByName(j, "C_CSPlayerPawn", "m_vecStashedGrenadeThrowPosition");
    C_CSPlayerPawn.m_vecStashedVelocity = findOffsetByName(j, "C_CSPlayerPawn", "m_vecStashedVelocity");
    C_CSPlayerPawn.m_angShootAngleHistory = findOffsetByName(j, "C_CSPlayerPawn", "m_angShootAngleHistory");
    C_CSPlayerPawn.m_vecThrowPositionHistory = findOffsetByName(j, "C_CSPlayerPawn", "m_vecThrowPositionHistory");
    C_CSPlayerPawn.m_vecVelocityHistory = findOffsetByName(j, "C_CSPlayerPawn", "m_vecVelocityHistory");
    C_CSPlayerPawn.m_PredictedDamageTags = findOffsetByName(j, "C_CSPlayerPawn", "m_PredictedDamageTags");
    C_CSPlayerPawn.m_nPrevHighestReceivedDamageTagTick = findOffsetByName(j, "C_CSPlayerPawn", "m_nPrevHighestReceivedDamageTagTick");
    C_CSPlayerPawn.m_nHighestAppliedDamageTagTick = findOffsetByName(j, "C_CSPlayerPawn", "m_nHighestAppliedDamageTagTick");

    // Atribuições para C_RagdollPropAttached
    // C_RagdollPropAttached Offsets
    C_RagdollPropAttached.m_boneIndexAttached = findOffsetByName(j, "C_RagdollPropAttached", "m_boneIndexAttached");
    C_RagdollPropAttached.m_ragdollAttachedObjectIndex = findOffsetByName(j, "C_RagdollPropAttached", "m_ragdollAttachedObjectIndex");
    C_RagdollPropAttached.m_attachmentPointBoneSpace = findOffsetByName(j, "C_RagdollPropAttached", "m_attachmentPointBoneSpace");
    C_RagdollPropAttached.m_attachmentPointRagdollSpace = findOffsetByName(j, "C_RagdollPropAttached", "m_attachmentPointRagdollSpace");
    C_RagdollPropAttached.m_vecOffset = findOffsetByName(j, "C_RagdollPropAttached", "m_vecOffset");
    C_RagdollPropAttached.m_parentTime = findOffsetByName(j, "C_RagdollPropAttached", "m_parentTime");
    C_RagdollPropAttached.m_bHasParent = findOffsetByName(j, "C_RagdollPropAttached", "m_bHasParent");

    // Atribuições para C_BaseCSGrenadeProjectile
    // C_BaseCSGrenadeProjectile Offsets
    C_BaseCSGrenadeProjectile.m_vInitialPosition = findOffsetByName(j, "C_BaseCSGrenadeProjectile", "m_vInitialPosition");
    C_BaseCSGrenadeProjectile.m_vInitialVelocity = findOffsetByName(j, "C_BaseCSGrenadeProjectile", "m_vInitialVelocity");
    C_BaseCSGrenadeProjectile.m_nBounces = findOffsetByName(j, "C_BaseCSGrenadeProjectile", "m_nBounces");
    C_BaseCSGrenadeProjectile.m_nExplodeEffectIndex = findOffsetByName(j, "C_BaseCSGrenadeProjectile", "m_nExplodeEffectIndex");
    C_BaseCSGrenadeProjectile.m_nExplodeEffectTickBegin = findOffsetByName(j, "C_BaseCSGrenadeProjectile", "m_nExplodeEffectTickBegin");
    C_BaseCSGrenadeProjectile.m_vecExplodeEffectOrigin = findOffsetByName(j, "C_BaseCSGrenadeProjectile", "m_vecExplodeEffectOrigin");
    C_BaseCSGrenadeProjectile.m_flSpawnTime = findOffsetByName(j, "C_BaseCSGrenadeProjectile", "m_flSpawnTime");
    C_BaseCSGrenadeProjectile.vecLastTrailLinePos = findOffsetByName(j, "C_BaseCSGrenadeProjectile", "vecLastTrailLinePos");
    C_BaseCSGrenadeProjectile.flNextTrailLineTime = findOffsetByName(j, "C_BaseCSGrenadeProjectile", "flNextTrailLineTime");
    C_BaseCSGrenadeProjectile.m_bExplodeEffectBegan = findOffsetByName(j, "C_BaseCSGrenadeProjectile", "m_bExplodeEffectBegan");
    C_BaseCSGrenadeProjectile.m_bCanCreateGrenadeTrail = findOffsetByName(j, "C_BaseCSGrenadeProjectile", "m_bCanCreateGrenadeTrail");
    C_BaseCSGrenadeProjectile.m_nSnapshotTrajectoryEffectIndex = findOffsetByName(j, "C_BaseCSGrenadeProjectile", "m_nSnapshotTrajectoryEffectIndex");
    C_BaseCSGrenadeProjectile.m_hSnapshotTrajectoryParticleSnapshot = findOffsetByName(j, "C_BaseCSGrenadeProjectile", "m_hSnapshotTrajectoryParticleSnapshot");
    C_BaseCSGrenadeProjectile.m_arrTrajectoryTrailPoints = findOffsetByName(j, "C_BaseCSGrenadeProjectile", "m_arrTrajectoryTrailPoints");
    C_BaseCSGrenadeProjectile.m_arrTrajectoryTrailPointCreationTimes = findOffsetByName(j, "C_BaseCSGrenadeProjectile", "m_arrTrajectoryTrailPointCreationTimes");
    C_BaseCSGrenadeProjectile.m_flTrajectoryTrailEffectCreationTime = findOffsetByName(j, "C_BaseCSGrenadeProjectile", "m_flTrajectoryTrailEffectCreationTime");

    // Atribuições para C_BaseTrigger
    // C_BaseTrigger Offsets
    C_BaseTrigger.m_bDisabled = findOffsetByName(j, "C_BaseTrigger", "m_bDisabled");
    C_BaseTrigger.m_bClientSidePredicted = findOffsetByName(j, "C_BaseTrigger", "m_bClientSidePredicted");

    // Atribuições para C_WeaponBaseItem
    // C_WeaponBaseItem Offsets
    C_WeaponBaseItem.m_SequenceCompleteTimer = findOffsetByName(j, "C_WeaponBaseItem", "m_SequenceCompleteTimer");
    C_WeaponBaseItem.m_bRedraw = findOffsetByName(j, "C_WeaponBaseItem", "m_bRedraw");

    // Atribuições para CEffectData
    // CEffectData Offsets
    CEffectData.m_vOrigin = findOffsetByName(j, "CEffectData", "m_vOrigin");
    CEffectData.m_vStart = findOffsetByName(j, "CEffectData", "m_vStart");
    CEffectData.m_vNormal = findOffsetByName(j, "CEffectData", "m_vNormal");
    CEffectData.m_vAngles = findOffsetByName(j, "CEffectData", "m_vAngles");
    CEffectData.m_hEntity = findOffsetByName(j, "CEffectData", "m_hEntity");
    CEffectData.m_hOtherEntity = findOffsetByName(j, "CEffectData", "m_hOtherEntity");
    CEffectData.m_flScale = findOffsetByName(j, "CEffectData", "m_flScale");
    CEffectData.m_flMagnitude = findOffsetByName(j, "CEffectData", "m_flMagnitude");
    CEffectData.m_flRadius = findOffsetByName(j, "CEffectData", "m_flRadius");
    CEffectData.m_nSurfaceProp = findOffsetByName(j, "CEffectData", "m_nSurfaceProp");
    CEffectData.m_nEffectIndex = findOffsetByName(j, "CEffectData", "m_nEffectIndex");
    CEffectData.m_nDamageType = findOffsetByName(j, "CEffectData", "m_nDamageType");
    CEffectData.m_nPenetrate = findOffsetByName(j, "CEffectData", "m_nPenetrate");
    CEffectData.m_nMaterial = findOffsetByName(j, "CEffectData", "m_nMaterial");
    CEffectData.m_nHitBox = findOffsetByName(j, "CEffectData", "m_nHitBox");
    CEffectData.m_nColor = findOffsetByName(j, "CEffectData", "m_nColor");
    CEffectData.m_fFlags = findOffsetByName(j, "CEffectData", "m_fFlags");
    CEffectData.m_nAttachmentIndex = findOffsetByName(j, "CEffectData", "m_nAttachmentIndex");
    CEffectData.m_nAttachmentName = findOffsetByName(j, "CEffectData", "m_nAttachmentName");
    CEffectData.m_iEffectName = findOffsetByName(j, "CEffectData", "m_iEffectName");
    CEffectData.m_nExplosionType = findOffsetByName(j, "CEffectData", "m_nExplosionType");

    // Atribuições para C_BaseButton
    // C_BaseButton Offsets
    C_BaseButton.m_glowEntity = findOffsetByName(j, "C_BaseButton", "m_glowEntity");
    C_BaseButton.m_usable = findOffsetByName(j, "C_BaseButton", "m_usable");
    C_BaseButton.m_szDisplayText = findOffsetByName(j, "C_BaseButton", "m_szDisplayText");

    // Atribuições para CCSPlayer_ViewModelServices
    // CCSPlayer_ViewModelServices Offsets
    CCSPlayer_ViewModelServices.m_hViewModel = findOffsetByName(j, "CCSPlayer_ViewModelServices", "m_hViewModel");

    // Atribuições para CPlayer_MovementServices_Humanoid
    // CPlayer_MovementServices_Humanoid Offsets
    CPlayer_MovementServices_Humanoid.m_flStepSoundTime = findOffsetByName(j, "CPlayer_MovementServices_Humanoid", "m_flStepSoundTime");
    CPlayer_MovementServices_Humanoid.m_flFallVelocity = findOffsetByName(j, "CPlayer_MovementServices_Humanoid", "m_flFallVelocity");
    CPlayer_MovementServices_Humanoid.m_bInCrouch = findOffsetByName(j, "CPlayer_MovementServices_Humanoid", "m_bInCrouch");
    CPlayer_MovementServices_Humanoid.m_nCrouchState = findOffsetByName(j, "CPlayer_MovementServices_Humanoid", "m_nCrouchState");
    CPlayer_MovementServices_Humanoid.m_flCrouchTransitionStartTime = findOffsetByName(j, "CPlayer_MovementServices_Humanoid", "m_flCrouchTransitionStartTime");
    CPlayer_MovementServices_Humanoid.m_bDucked = findOffsetByName(j, "CPlayer_MovementServices_Humanoid", "m_bDucked");
    CPlayer_MovementServices_Humanoid.m_bDucking = findOffsetByName(j, "CPlayer_MovementServices_Humanoid", "m_bDucking");
    CPlayer_MovementServices_Humanoid.m_bInDuckJump = findOffsetByName(j, "CPlayer_MovementServices_Humanoid", "m_bInDuckJump");
    CPlayer_MovementServices_Humanoid.m_groundNormal = findOffsetByName(j, "CPlayer_MovementServices_Humanoid", "m_groundNormal");
    CPlayer_MovementServices_Humanoid.m_flSurfaceFriction = findOffsetByName(j, "CPlayer_MovementServices_Humanoid", "m_flSurfaceFriction");
    CPlayer_MovementServices_Humanoid.m_surfaceProps = findOffsetByName(j, "CPlayer_MovementServices_Humanoid", "m_surfaceProps");
    CPlayer_MovementServices_Humanoid.m_nStepside = findOffsetByName(j, "CPlayer_MovementServices_Humanoid", "m_nStepside");

    // Atribuições para C_PointClientUIWorldPanel
    // C_PointClientUIWorldPanel Offsets
    C_PointClientUIWorldPanel.m_bForceRecreateNextUpdate = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_bForceRecreateNextUpdate");
    C_PointClientUIWorldPanel.m_bMoveViewToPlayerNextThink = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_bMoveViewToPlayerNextThink");
    C_PointClientUIWorldPanel.m_bCheckCSSClasses = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_bCheckCSSClasses");
    C_PointClientUIWorldPanel.m_anchorDeltaTransform = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_anchorDeltaTransform");
    C_PointClientUIWorldPanel.m_pOffScreenIndicator = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_pOffScreenIndicator");
    C_PointClientUIWorldPanel.m_bIgnoreInput = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_bIgnoreInput");
    C_PointClientUIWorldPanel.m_bLit = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_bLit");
    C_PointClientUIWorldPanel.m_bFollowPlayerAcrossTeleport = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_bFollowPlayerAcrossTeleport");
    C_PointClientUIWorldPanel.m_flWidth = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_flWidth");
    C_PointClientUIWorldPanel.m_flHeight = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_flHeight");
    C_PointClientUIWorldPanel.m_flDPI = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_flDPI");
    C_PointClientUIWorldPanel.m_flInteractDistance = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_flInteractDistance");
    C_PointClientUIWorldPanel.m_flDepthOffset = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_flDepthOffset");
    C_PointClientUIWorldPanel.m_unOwnerContext = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_unOwnerContext");
    C_PointClientUIWorldPanel.m_unHorizontalAlign = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_unHorizontalAlign");
    C_PointClientUIWorldPanel.m_unVerticalAlign = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_unVerticalAlign");
    C_PointClientUIWorldPanel.m_unOrientation = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_unOrientation");
    C_PointClientUIWorldPanel.m_bAllowInteractionFromAllSceneWorlds = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_bAllowInteractionFromAllSceneWorlds");
    C_PointClientUIWorldPanel.m_vecCSSClasses = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_vecCSSClasses");
    C_PointClientUIWorldPanel.m_bOpaque = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_bOpaque");
    C_PointClientUIWorldPanel.m_bNoDepth = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_bNoDepth");
    C_PointClientUIWorldPanel.m_bRenderBackface = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_bRenderBackface");
    C_PointClientUIWorldPanel.m_bUseOffScreenIndicator = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_bUseOffScreenIndicator");
    C_PointClientUIWorldPanel.m_bExcludeFromSaveGames = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_bExcludeFromSaveGames");
    C_PointClientUIWorldPanel.m_bGrabbable = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_bGrabbable");
    C_PointClientUIWorldPanel.m_bOnlyRenderToTexture = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_bOnlyRenderToTexture");
    C_PointClientUIWorldPanel.m_bDisableMipGen = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_bDisableMipGen");
    C_PointClientUIWorldPanel.m_nExplicitImageLayout = findOffsetByName(j, "C_PointClientUIWorldPanel", "m_nExplicitImageLayout");

    // Atribuições para CCSGameModeRules_Deathmatch
    // CCSGameModeRules_Deathmatch Offsets
    CCSGameModeRules_Deathmatch.m_flDMBonusStartTime = findOffsetByName(j, "CCSGameModeRules_Deathmatch", "m_flDMBonusStartTime");
    CCSGameModeRules_Deathmatch.m_flDMBonusTimeLength = findOffsetByName(j, "CCSGameModeRules_Deathmatch", "m_flDMBonusTimeLength");
    CCSGameModeRules_Deathmatch.m_sDMBonusWeapon = findOffsetByName(j, "CCSGameModeRules_Deathmatch", "m_sDMBonusWeapon");

    // Atribuições para C_GameRules
    // C_GameRules Offsets
    C_GameRules.__m_pChainEntity = findOffsetByName(j, "C_GameRules", "__m_pChainEntity");
    C_GameRules.m_nTotalPausedTicks = findOffsetByName(j, "C_GameRules", "m_nTotalPausedTicks");
    C_GameRules.m_nPauseStartTick = findOffsetByName(j, "C_GameRules", "m_nPauseStartTick");
    C_GameRules.m_bGamePaused = findOffsetByName(j, "C_GameRules", "m_bGamePaused");

    // Atribuições para C_Team
    // C_Team Offsets
    C_Team.m_aPlayerControllers = findOffsetByName(j, "C_Team", "m_aPlayerControllers");
    C_Team.m_aPlayers = findOffsetByName(j, "C_Team", "m_aPlayers");
    C_Team.m_iScore = findOffsetByName(j, "C_Team", "m_iScore");
    C_Team.m_szTeamname = findOffsetByName(j, "C_Team", "m_szTeamname");

    // Atribuições para C_SoundAreaEntityOrientedBox
    // C_SoundAreaEntityOrientedBox Offsets
    C_SoundAreaEntityOrientedBox.m_vMin = findOffsetByName(j, "C_SoundAreaEntityOrientedBox", "m_vMin");
    C_SoundAreaEntityOrientedBox.m_vMax = findOffsetByName(j, "C_SoundAreaEntityOrientedBox", "m_vMax");

    // Atribuições para C_TextureBasedAnimatable
    // C_TextureBasedAnimatable Offsets
    C_TextureBasedAnimatable.m_bLoop = findOffsetByName(j, "C_TextureBasedAnimatable", "m_bLoop");
    C_TextureBasedAnimatable.m_flFPS = findOffsetByName(j, "C_TextureBasedAnimatable", "m_flFPS");
    C_TextureBasedAnimatable.m_hPositionKeys = findOffsetByName(j, "C_TextureBasedAnimatable", "m_hPositionKeys");
    C_TextureBasedAnimatable.m_hRotationKeys = findOffsetByName(j, "C_TextureBasedAnimatable", "m_hRotationKeys");
    C_TextureBasedAnimatable.m_vAnimationBoundsMin = findOffsetByName(j, "C_TextureBasedAnimatable", "m_vAnimationBoundsMin");
    C_TextureBasedAnimatable.m_vAnimationBoundsMax = findOffsetByName(j, "C_TextureBasedAnimatable", "m_vAnimationBoundsMax");
    C_TextureBasedAnimatable.m_flStartTime = findOffsetByName(j, "C_TextureBasedAnimatable", "m_flStartTime");
    C_TextureBasedAnimatable.m_flStartFrame = findOffsetByName(j, "C_TextureBasedAnimatable", "m_flStartFrame");

    // Atribuições para CCSPlayer_WaterServices
    // CCSPlayer_WaterServices Offsets
    CCSPlayer_WaterServices.m_flWaterJumpTime = findOffsetByName(j, "CCSPlayer_WaterServices", "m_flWaterJumpTime");
    CCSPlayer_WaterServices.m_vecWaterJumpVel = findOffsetByName(j, "CCSPlayer_WaterServices", "m_vecWaterJumpVel");
    CCSPlayer_WaterServices.m_flSwimSoundTime = findOffsetByName(j, "CCSPlayer_WaterServices", "m_flSwimSoundTime");

    // Atribuições para CSkyboxReference
    // CSkyboxReference Offsets
    CSkyboxReference.m_worldGroupId = findOffsetByName(j, "CSkyboxReference", "m_worldGroupId");
    CSkyboxReference.m_hSkyCamera = findOffsetByName(j, "CSkyboxReference", "m_hSkyCamera");

    // Atribuições para CProjectedTextureBase
    // CProjectedTextureBase Offsets
    CProjectedTextureBase.m_hTargetEntity = findOffsetByName(j, "CProjectedTextureBase", "m_hTargetEntity");
    CProjectedTextureBase.m_bState = findOffsetByName(j, "CProjectedTextureBase", "m_bState");
    CProjectedTextureBase.m_bAlwaysUpdate = findOffsetByName(j, "CProjectedTextureBase", "m_bAlwaysUpdate");
    CProjectedTextureBase.m_flLightFOV = findOffsetByName(j, "CProjectedTextureBase", "m_flLightFOV");
    CProjectedTextureBase.m_bEnableShadows = findOffsetByName(j, "CProjectedTextureBase", "m_bEnableShadows");
    CProjectedTextureBase.m_bSimpleProjection = findOffsetByName(j, "CProjectedTextureBase", "m_bSimpleProjection");
    CProjectedTextureBase.m_bLightOnlyTarget = findOffsetByName(j, "CProjectedTextureBase", "m_bLightOnlyTarget");
    CProjectedTextureBase.m_bLightWorld = findOffsetByName(j, "CProjectedTextureBase", "m_bLightWorld");
    CProjectedTextureBase.m_bCameraSpace = findOffsetByName(j, "CProjectedTextureBase", "m_bCameraSpace");
    CProjectedTextureBase.m_flBrightnessScale = findOffsetByName(j, "CProjectedTextureBase", "m_flBrightnessScale");
    CProjectedTextureBase.m_LightColor = findOffsetByName(j, "CProjectedTextureBase", "m_LightColor");
    CProjectedTextureBase.m_flIntensity = findOffsetByName(j, "CProjectedTextureBase", "m_flIntensity");
    CProjectedTextureBase.m_flLinearAttenuation = findOffsetByName(j, "CProjectedTextureBase", "m_flLinearAttenuation");
    CProjectedTextureBase.m_flQuadraticAttenuation = findOffsetByName(j, "CProjectedTextureBase", "m_flQuadraticAttenuation");
    CProjectedTextureBase.m_bVolumetric = findOffsetByName(j, "CProjectedTextureBase", "m_bVolumetric");
    CProjectedTextureBase.m_flVolumetricIntensity = findOffsetByName(j, "CProjectedTextureBase", "m_flVolumetricIntensity");
    CProjectedTextureBase.m_flNoiseStrength = findOffsetByName(j, "CProjectedTextureBase", "m_flNoiseStrength");
    CProjectedTextureBase.m_flFlashlightTime = findOffsetByName(j, "CProjectedTextureBase", "m_flFlashlightTime");
    CProjectedTextureBase.m_nNumPlanes = findOffsetByName(j, "CProjectedTextureBase", "m_nNumPlanes");
    CProjectedTextureBase.m_flPlaneOffset = findOffsetByName(j, "CProjectedTextureBase", "m_flPlaneOffset");
    CProjectedTextureBase.m_flColorTransitionTime = findOffsetByName(j, "CProjectedTextureBase", "m_flColorTransitionTime");
    CProjectedTextureBase.m_flAmbient = findOffsetByName(j, "CProjectedTextureBase", "m_flAmbient");
    CProjectedTextureBase.m_SpotlightTextureName = findOffsetByName(j, "CProjectedTextureBase", "m_SpotlightTextureName");
    CProjectedTextureBase.m_nSpotlightTextureFrame = findOffsetByName(j, "CProjectedTextureBase", "m_nSpotlightTextureFrame");
    CProjectedTextureBase.m_nShadowQuality = findOffsetByName(j, "CProjectedTextureBase", "m_nShadowQuality");
    CProjectedTextureBase.m_flNearZ = findOffsetByName(j, "CProjectedTextureBase", "m_flNearZ");
    CProjectedTextureBase.m_flFarZ = findOffsetByName(j, "CProjectedTextureBase", "m_flFarZ");
    CProjectedTextureBase.m_flProjectionSize = findOffsetByName(j, "CProjectedTextureBase", "m_flProjectionSize");
    CProjectedTextureBase.m_flRotation = findOffsetByName(j, "CProjectedTextureBase", "m_flRotation");
    CProjectedTextureBase.m_bFlipHorizontal = findOffsetByName(j, "CProjectedTextureBase", "m_bFlipHorizontal");

    // Atribuições para CCSPlayerController_InventoryServices
    // CCSPlayerController_InventoryServices Offsets
    CCSPlayerController_InventoryServices.m_unMusicID = findOffsetByName(j, "CCSPlayerController_InventoryServices", "m_unMusicID");
    CCSPlayerController_InventoryServices.m_rank = findOffsetByName(j, "CCSPlayerController_InventoryServices", "m_rank");
    CCSPlayerController_InventoryServices.m_nPersonaDataPublicLevel = findOffsetByName(j, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicLevel");
    CCSPlayerController_InventoryServices.m_nPersonaDataPublicCommendsLeader = findOffsetByName(j, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicCommendsLeader");
    CCSPlayerController_InventoryServices.m_nPersonaDataPublicCommendsTeacher = findOffsetByName(j, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicCommendsTeacher");
    CCSPlayerController_InventoryServices.m_nPersonaDataPublicCommendsFriendly = findOffsetByName(j, "CCSPlayerController_InventoryServices", "m_nPersonaDataPublicCommendsFriendly");
    CCSPlayerController_InventoryServices.m_nPersonaDataXpTrailLevel = findOffsetByName(j, "CCSPlayerController_InventoryServices", "m_nPersonaDataXpTrailLevel");
    CCSPlayerController_InventoryServices.m_vecServerAuthoritativeWeaponSlots = findOffsetByName(j, "CCSPlayerController_InventoryServices", "m_vecServerAuthoritativeWeaponSlots");

    // Atribuições para C_CSGOViewModel
    // C_CSGOViewModel Offsets
    C_CSGOViewModel.m_bShouldIgnoreOffsetAndAccuracy = findOffsetByName(j, "C_CSGOViewModel", "m_bShouldIgnoreOffsetAndAccuracy");
    C_CSGOViewModel.m_nLastKnownAssociatedWeaponEntIndex = findOffsetByName(j, "C_CSGOViewModel", "m_nLastKnownAssociatedWeaponEntIndex");
    C_CSGOViewModel.m_bNeedToQueueHighResComposite = findOffsetByName(j, "C_CSGOViewModel", "m_bNeedToQueueHighResComposite");
    C_CSGOViewModel.m_vLoweredWeaponOffset = findOffsetByName(j, "C_CSGOViewModel", "m_vLoweredWeaponOffset");

    // Atribuições para CScriptComponent
    // CScriptComponent Offsets
    CScriptComponent.m_scriptClassName = findOffsetByName(j, "CScriptComponent", "m_scriptClassName");

    // Atribuições para C_EnvLightProbeVolume
    // C_EnvLightProbeVolume Offsets
    C_EnvLightProbeVolume.m_Entity_hLightProbeTexture = findOffsetByName(j, "C_EnvLightProbeVolume", "m_Entity_hLightProbeTexture");
    C_EnvLightProbeVolume.m_Entity_hLightProbeDirectLightIndicesTexture = findOffsetByName(j, "C_EnvLightProbeVolume", "m_Entity_hLightProbeDirectLightIndicesTexture");
    C_EnvLightProbeVolume.m_Entity_hLightProbeDirectLightScalarsTexture = findOffsetByName(j, "C_EnvLightProbeVolume", "m_Entity_hLightProbeDirectLightScalarsTexture");
    C_EnvLightProbeVolume.m_Entity_hLightProbeDirectLightShadowsTexture = findOffsetByName(j, "C_EnvLightProbeVolume", "m_Entity_hLightProbeDirectLightShadowsTexture");
    C_EnvLightProbeVolume.m_Entity_vBoxMins = findOffsetByName(j, "C_EnvLightProbeVolume", "m_Entity_vBoxMins");
    C_EnvLightProbeVolume.m_Entity_vBoxMaxs = findOffsetByName(j, "C_EnvLightProbeVolume", "m_Entity_vBoxMaxs");
    C_EnvLightProbeVolume.m_Entity_bMoveable = findOffsetByName(j, "C_EnvLightProbeVolume", "m_Entity_bMoveable");
    C_EnvLightProbeVolume.m_Entity_nHandshake = findOffsetByName(j, "C_EnvLightProbeVolume", "m_Entity_nHandshake");
    C_EnvLightProbeVolume.m_Entity_nPriority = findOffsetByName(j, "C_EnvLightProbeVolume", "m_Entity_nPriority");
    C_EnvLightProbeVolume.m_Entity_bStartDisabled = findOffsetByName(j, "C_EnvLightProbeVolume", "m_Entity_bStartDisabled");
    C_EnvLightProbeVolume.m_Entity_nLightProbeSizeX = findOffsetByName(j, "C_EnvLightProbeVolume", "m_Entity_nLightProbeSizeX");
    C_EnvLightProbeVolume.m_Entity_nLightProbeSizeY = findOffsetByName(j, "C_EnvLightProbeVolume", "m_Entity_nLightProbeSizeY");
    C_EnvLightProbeVolume.m_Entity_nLightProbeSizeZ = findOffsetByName(j, "C_EnvLightProbeVolume", "m_Entity_nLightProbeSizeZ");
    C_EnvLightProbeVolume.m_Entity_nLightProbeAtlasX = findOffsetByName(j, "C_EnvLightProbeVolume", "m_Entity_nLightProbeAtlasX");
    C_EnvLightProbeVolume.m_Entity_nLightProbeAtlasY = findOffsetByName(j, "C_EnvLightProbeVolume", "m_Entity_nLightProbeAtlasY");
    C_EnvLightProbeVolume.m_Entity_nLightProbeAtlasZ = findOffsetByName(j, "C_EnvLightProbeVolume", "m_Entity_nLightProbeAtlasZ");
    C_EnvLightProbeVolume.m_Entity_bEnabled = findOffsetByName(j, "C_EnvLightProbeVolume", "m_Entity_bEnabled");

    // Atribuições para C_ViewmodelAttachmentModel
    // C_ViewmodelAttachmentModel Offsets
    C_ViewmodelAttachmentModel.m_bShouldFrontFaceCullLeftHanded = findOffsetByName(j, "C_ViewmodelAttachmentModel", "m_bShouldFrontFaceCullLeftHanded");
    C_ViewmodelAttachmentModel.m_bCreatedLeftHanded = findOffsetByName(j, "C_ViewmodelAttachmentModel", "m_bCreatedLeftHanded");

    // Atribuições para CSPerRoundStats_t
    // CSPerRoundStats_t Offsets
    CSPerRoundStats_t.m_iKills = findOffsetByName(j, "CSPerRoundStats_t", "m_iKills");
    CSPerRoundStats_t.m_iDeaths = findOffsetByName(j, "CSPerRoundStats_t", "m_iDeaths");
    CSPerRoundStats_t.m_iAssists = findOffsetByName(j, "CSPerRoundStats_t", "m_iAssists");
    CSPerRoundStats_t.m_iDamage = findOffsetByName(j, "CSPerRoundStats_t", "m_iDamage");
    CSPerRoundStats_t.m_iEquipmentValue = findOffsetByName(j, "CSPerRoundStats_t", "m_iEquipmentValue");
    CSPerRoundStats_t.m_iMoneySaved = findOffsetByName(j, "CSPerRoundStats_t", "m_iMoneySaved");
    CSPerRoundStats_t.m_iKillReward = findOffsetByName(j, "CSPerRoundStats_t", "m_iKillReward");
    CSPerRoundStats_t.m_iLiveTime = findOffsetByName(j, "CSPerRoundStats_t", "m_iLiveTime");
    CSPerRoundStats_t.m_iHeadShotKills = findOffsetByName(j, "CSPerRoundStats_t", "m_iHeadShotKills");
    CSPerRoundStats_t.m_iObjective = findOffsetByName(j, "CSPerRoundStats_t", "m_iObjective");
    CSPerRoundStats_t.m_iCashEarned = findOffsetByName(j, "CSPerRoundStats_t", "m_iCashEarned");
    CSPerRoundStats_t.m_iUtilityDamage = findOffsetByName(j, "CSPerRoundStats_t", "m_iUtilityDamage");
    CSPerRoundStats_t.m_iEnemiesFlashed = findOffsetByName(j, "CSPerRoundStats_t", "m_iEnemiesFlashed");

    // Atribuições para CRagdollManager
    // CRagdollManager Offsets
    CRagdollManager.m_iCurrentMaxRagdollCount = findOffsetByName(j, "CRagdollManager", "m_iCurrentMaxRagdollCount");

    // Atribuições para C_TeamRoundTimer
    // C_TeamRoundTimer Offsets
    C_TeamRoundTimer.m_bTimerPaused = findOffsetByName(j, "C_TeamRoundTimer", "m_bTimerPaused");
    C_TeamRoundTimer.m_flTimeRemaining = findOffsetByName(j, "C_TeamRoundTimer", "m_flTimeRemaining");
    C_TeamRoundTimer.m_flTimerEndTime = findOffsetByName(j, "C_TeamRoundTimer", "m_flTimerEndTime");
    C_TeamRoundTimer.m_bIsDisabled = findOffsetByName(j, "C_TeamRoundTimer", "m_bIsDisabled");
    C_TeamRoundTimer.m_bShowInHUD = findOffsetByName(j, "C_TeamRoundTimer", "m_bShowInHUD");
    C_TeamRoundTimer.m_nTimerLength = findOffsetByName(j, "C_TeamRoundTimer", "m_nTimerLength");
    C_TeamRoundTimer.m_nTimerInitialLength = findOffsetByName(j, "C_TeamRoundTimer", "m_nTimerInitialLength");
    C_TeamRoundTimer.m_nTimerMaxLength = findOffsetByName(j, "C_TeamRoundTimer", "m_nTimerMaxLength");
    C_TeamRoundTimer.m_bAutoCountdown = findOffsetByName(j, "C_TeamRoundTimer", "m_bAutoCountdown");
    C_TeamRoundTimer.m_nSetupTimeLength = findOffsetByName(j, "C_TeamRoundTimer", "m_nSetupTimeLength");
    C_TeamRoundTimer.m_nState = findOffsetByName(j, "C_TeamRoundTimer", "m_nState");
    C_TeamRoundTimer.m_bStartPaused = findOffsetByName(j, "C_TeamRoundTimer", "m_bStartPaused");
    C_TeamRoundTimer.m_bInCaptureWatchState = findOffsetByName(j, "C_TeamRoundTimer", "m_bInCaptureWatchState");
    C_TeamRoundTimer.m_flTotalTime = findOffsetByName(j, "C_TeamRoundTimer", "m_flTotalTime");
    C_TeamRoundTimer.m_bStopWatchTimer = findOffsetByName(j, "C_TeamRoundTimer", "m_bStopWatchTimer");
    C_TeamRoundTimer.m_bFireFinished = findOffsetByName(j, "C_TeamRoundTimer", "m_bFireFinished");
    C_TeamRoundTimer.m_bFire5MinRemain = findOffsetByName(j, "C_TeamRoundTimer", "m_bFire5MinRemain");
    C_TeamRoundTimer.m_bFire4MinRemain = findOffsetByName(j, "C_TeamRoundTimer", "m_bFire4MinRemain");
    C_TeamRoundTimer.m_bFire3MinRemain = findOffsetByName(j, "C_TeamRoundTimer", "m_bFire3MinRemain");
    C_TeamRoundTimer.m_bFire2MinRemain = findOffsetByName(j, "C_TeamRoundTimer", "m_bFire2MinRemain");
    C_TeamRoundTimer.m_bFire1MinRemain = findOffsetByName(j, "C_TeamRoundTimer", "m_bFire1MinRemain");
    C_TeamRoundTimer.m_bFire30SecRemain = findOffsetByName(j, "C_TeamRoundTimer", "m_bFire30SecRemain");
    C_TeamRoundTimer.m_bFire10SecRemain = findOffsetByName(j, "C_TeamRoundTimer", "m_bFire10SecRemain");
    C_TeamRoundTimer.m_bFire5SecRemain = findOffsetByName(j, "C_TeamRoundTimer", "m_bFire5SecRemain");
    C_TeamRoundTimer.m_bFire4SecRemain = findOffsetByName(j, "C_TeamRoundTimer", "m_bFire4SecRemain");
    C_TeamRoundTimer.m_bFire3SecRemain = findOffsetByName(j, "C_TeamRoundTimer", "m_bFire3SecRemain");
    C_TeamRoundTimer.m_bFire2SecRemain = findOffsetByName(j, "C_TeamRoundTimer", "m_bFire2SecRemain");
    C_TeamRoundTimer.m_bFire1SecRemain = findOffsetByName(j, "C_TeamRoundTimer", "m_bFire1SecRemain");
    C_TeamRoundTimer.m_nOldTimerLength = findOffsetByName(j, "C_TeamRoundTimer", "m_nOldTimerLength");
    C_TeamRoundTimer.m_nOldTimerState = findOffsetByName(j, "C_TeamRoundTimer", "m_nOldTimerState");

    // Atribuições para WeaponPurchaseCount_t
    // WeaponPurchaseCount_t Offsets
    WeaponPurchaseCount_t.m_nItemDefIndex = findOffsetByName(j, "WeaponPurchaseCount_t", "m_nItemDefIndex");
    WeaponPurchaseCount_t.m_nCount = findOffsetByName(j, "WeaponPurchaseCount_t", "m_nCount");

    // Atribuições para CPathSimple
    // CPathSimple Offsets
    CPathSimple.m_pathString = findOffsetByName(j, "CPathSimple", "m_pathString");

    // Atribuições para CCSPlayerBase_CameraServices
    // CCSPlayerBase_CameraServices Offsets
    CCSPlayerBase_CameraServices.m_iFOV = findOffsetByName(j, "CCSPlayerBase_CameraServices", "m_iFOV");
    CCSPlayerBase_CameraServices.m_iFOVStart = findOffsetByName(j, "CCSPlayerBase_CameraServices", "m_iFOVStart");
    CCSPlayerBase_CameraServices.m_flFOVTime = findOffsetByName(j, "CCSPlayerBase_CameraServices", "m_flFOVTime");
    CCSPlayerBase_CameraServices.m_flFOVRate = findOffsetByName(j, "CCSPlayerBase_CameraServices", "m_flFOVRate");
    CCSPlayerBase_CameraServices.m_hZoomOwner = findOffsetByName(j, "CCSPlayerBase_CameraServices", "m_hZoomOwner");
    CCSPlayerBase_CameraServices.m_flLastShotFOV = findOffsetByName(j, "CCSPlayerBase_CameraServices", "m_flLastShotFOV");

    // Atribuições para CPointOffScreenIndicatorUi
    // CPointOffScreenIndicatorUi Offsets
    CPointOffScreenIndicatorUi.m_bBeenEnabled = findOffsetByName(j, "CPointOffScreenIndicatorUi", "m_bBeenEnabled");
    CPointOffScreenIndicatorUi.m_bHide = findOffsetByName(j, "CPointOffScreenIndicatorUi", "m_bHide");
    CPointOffScreenIndicatorUi.m_flSeenTargetTime = findOffsetByName(j, "CPointOffScreenIndicatorUi", "m_flSeenTargetTime");
    CPointOffScreenIndicatorUi.m_pTargetPanel = findOffsetByName(j, "CPointOffScreenIndicatorUi", "m_pTargetPanel");

    // Atribuições para C_CSWeaponBaseGun
    // C_CSWeaponBaseGun Offsets
    C_CSWeaponBaseGun.m_zoomLevel = findOffsetByName(j, "C_CSWeaponBaseGun", "m_zoomLevel");
    C_CSWeaponBaseGun.m_iBurstShotsRemaining = findOffsetByName(j, "C_CSWeaponBaseGun", "m_iBurstShotsRemaining");
    C_CSWeaponBaseGun.m_iSilencerBodygroup = findOffsetByName(j, "C_CSWeaponBaseGun", "m_iSilencerBodygroup");
    C_CSWeaponBaseGun.m_silencedModelIndex = findOffsetByName(j, "C_CSWeaponBaseGun", "m_silencedModelIndex");
    C_CSWeaponBaseGun.m_inPrecache = findOffsetByName(j, "C_CSWeaponBaseGun", "m_inPrecache");
    C_CSWeaponBaseGun.m_bNeedsBoltAction = findOffsetByName(j, "C_CSWeaponBaseGun", "m_bNeedsBoltAction");

    // Atribuições para C_SkyCamera
    // C_SkyCamera Offsets
    C_SkyCamera.m_skyboxData = findOffsetByName(j, "C_SkyCamera", "m_skyboxData");
    C_SkyCamera.m_skyboxSlotToken = findOffsetByName(j, "C_SkyCamera", "m_skyboxSlotToken");
    C_SkyCamera.m_bUseAngles = findOffsetByName(j, "C_SkyCamera", "m_bUseAngles");
    C_SkyCamera.m_pNext = findOffsetByName(j, "C_SkyCamera", "m_pNext");

    // Atribuições para C_EntityDissolve
    // C_EntityDissolve Offsets
    C_EntityDissolve.m_flStartTime = findOffsetByName(j, "C_EntityDissolve", "m_flStartTime");
    C_EntityDissolve.m_flFadeInStart = findOffsetByName(j, "C_EntityDissolve", "m_flFadeInStart");
    C_EntityDissolve.m_flFadeInLength = findOffsetByName(j, "C_EntityDissolve", "m_flFadeInLength");
    C_EntityDissolve.m_flFadeOutModelStart = findOffsetByName(j, "C_EntityDissolve", "m_flFadeOutModelStart");
    C_EntityDissolve.m_flFadeOutModelLength = findOffsetByName(j, "C_EntityDissolve", "m_flFadeOutModelLength");
    C_EntityDissolve.m_flFadeOutStart = findOffsetByName(j, "C_EntityDissolve", "m_flFadeOutStart");
    C_EntityDissolve.m_flFadeOutLength = findOffsetByName(j, "C_EntityDissolve", "m_flFadeOutLength");
    C_EntityDissolve.m_flNextSparkTime = findOffsetByName(j, "C_EntityDissolve", "m_flNextSparkTime");
    C_EntityDissolve.m_nDissolveType = findOffsetByName(j, "C_EntityDissolve", "m_nDissolveType");
    C_EntityDissolve.m_vDissolverOrigin = findOffsetByName(j, "C_EntityDissolve", "m_vDissolverOrigin");
    C_EntityDissolve.m_nMagnitude = findOffsetByName(j, "C_EntityDissolve", "m_nMagnitude");
    C_EntityDissolve.m_bCoreExplode = findOffsetByName(j, "C_EntityDissolve", "m_bCoreExplode");
    C_EntityDissolve.m_bLinkedToServerEnt = findOffsetByName(j, "C_EntityDissolve", "m_bLinkedToServerEnt");

    // Atribuições para C_fogplayerparams_t
    // C_fogplayerparams_t Offsets
    C_fogplayerparams_t.m_hCtrl = findOffsetByName(j, "C_fogplayerparams_t", "m_hCtrl");
    C_fogplayerparams_t.m_flTransitionTime = findOffsetByName(j, "C_fogplayerparams_t", "m_flTransitionTime");
    C_fogplayerparams_t.m_OldColor = findOffsetByName(j, "C_fogplayerparams_t", "m_OldColor");
    C_fogplayerparams_t.m_flOldStart = findOffsetByName(j, "C_fogplayerparams_t", "m_flOldStart");
    C_fogplayerparams_t.m_flOldEnd = findOffsetByName(j, "C_fogplayerparams_t", "m_flOldEnd");
    C_fogplayerparams_t.m_flOldMaxDensity = findOffsetByName(j, "C_fogplayerparams_t", "m_flOldMaxDensity");
    C_fogplayerparams_t.m_flOldHDRColorScale = findOffsetByName(j, "C_fogplayerparams_t", "m_flOldHDRColorScale");
    C_fogplayerparams_t.m_flOldFarZ = findOffsetByName(j, "C_fogplayerparams_t", "m_flOldFarZ");
    C_fogplayerparams_t.m_NewColor = findOffsetByName(j, "C_fogplayerparams_t", "m_NewColor");
    C_fogplayerparams_t.m_flNewStart = findOffsetByName(j, "C_fogplayerparams_t", "m_flNewStart");
    C_fogplayerparams_t.m_flNewEnd = findOffsetByName(j, "C_fogplayerparams_t", "m_flNewEnd");
    C_fogplayerparams_t.m_flNewMaxDensity = findOffsetByName(j, "C_fogplayerparams_t", "m_flNewMaxDensity");
    C_fogplayerparams_t.m_flNewHDRColorScale = findOffsetByName(j, "C_fogplayerparams_t", "m_flNewHDRColorScale");
    C_fogplayerparams_t.m_flNewFarZ = findOffsetByName(j, "C_fogplayerparams_t", "m_flNewFarZ");

    // Atribuições para C_CSPlayerPawnBase
    // C_CSPlayerPawnBase Offsets
    C_CSPlayerPawnBase.m_pPingServices = findOffsetByName(j, "C_CSPlayerPawnBase", "m_pPingServices");
    C_CSPlayerPawnBase.m_pViewModelServices = findOffsetByName(j, "C_CSPlayerPawnBase", "m_pViewModelServices");
    C_CSPlayerPawnBase.m_fRenderingClipPlane = findOffsetByName(j, "C_CSPlayerPawnBase", "m_fRenderingClipPlane");
    C_CSPlayerPawnBase.m_nLastClipPlaneSetupFrame = findOffsetByName(j, "C_CSPlayerPawnBase", "m_nLastClipPlaneSetupFrame");
    C_CSPlayerPawnBase.m_vecLastClipCameraPos = findOffsetByName(j, "C_CSPlayerPawnBase", "m_vecLastClipCameraPos");
    C_CSPlayerPawnBase.m_vecLastClipCameraForward = findOffsetByName(j, "C_CSPlayerPawnBase", "m_vecLastClipCameraForward");
    C_CSPlayerPawnBase.m_bClipHitStaticWorld = findOffsetByName(j, "C_CSPlayerPawnBase", "m_bClipHitStaticWorld");
    C_CSPlayerPawnBase.m_bCachedPlaneIsValid = findOffsetByName(j, "C_CSPlayerPawnBase", "m_bCachedPlaneIsValid");
    C_CSPlayerPawnBase.m_pClippingWeapon = findOffsetByName(j, "C_CSPlayerPawnBase", "m_pClippingWeapon");
    C_CSPlayerPawnBase.m_previousPlayerState = findOffsetByName(j, "C_CSPlayerPawnBase", "m_previousPlayerState");
    C_CSPlayerPawnBase.m_iPlayerState = findOffsetByName(j, "C_CSPlayerPawnBase", "m_iPlayerState");
    C_CSPlayerPawnBase.m_bIsRescuing = findOffsetByName(j, "C_CSPlayerPawnBase", "m_bIsRescuing");
    C_CSPlayerPawnBase.m_fImmuneToGunGameDamageTime = findOffsetByName(j, "C_CSPlayerPawnBase", "m_fImmuneToGunGameDamageTime");
    C_CSPlayerPawnBase.m_fImmuneToGunGameDamageTimeLast = findOffsetByName(j, "C_CSPlayerPawnBase", "m_fImmuneToGunGameDamageTimeLast");
    C_CSPlayerPawnBase.m_bGunGameImmunity = findOffsetByName(j, "C_CSPlayerPawnBase", "m_bGunGameImmunity");
    C_CSPlayerPawnBase.m_bHasMovedSinceSpawn = findOffsetByName(j, "C_CSPlayerPawnBase", "m_bHasMovedSinceSpawn");
    C_CSPlayerPawnBase.m_fMolotovUseTime = findOffsetByName(j, "C_CSPlayerPawnBase", "m_fMolotovUseTime");
    C_CSPlayerPawnBase.m_fMolotovDamageTime = findOffsetByName(j, "C_CSPlayerPawnBase", "m_fMolotovDamageTime");
    C_CSPlayerPawnBase.m_iThrowGrenadeCounter = findOffsetByName(j, "C_CSPlayerPawnBase", "m_iThrowGrenadeCounter");
    C_CSPlayerPawnBase.m_flLastSpawnTimeIndex = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flLastSpawnTimeIndex");
    C_CSPlayerPawnBase.m_iProgressBarDuration = findOffsetByName(j, "C_CSPlayerPawnBase", "m_iProgressBarDuration");
    C_CSPlayerPawnBase.m_flProgressBarStartTime = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flProgressBarStartTime");
    C_CSPlayerPawnBase.m_vecIntroStartEyePosition = findOffsetByName(j, "C_CSPlayerPawnBase", "m_vecIntroStartEyePosition");
    C_CSPlayerPawnBase.m_vecIntroStartPlayerForward = findOffsetByName(j, "C_CSPlayerPawnBase", "m_vecIntroStartPlayerForward");
    C_CSPlayerPawnBase.m_flClientDeathTime = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flClientDeathTime");
    C_CSPlayerPawnBase.m_bScreenTearFrameCaptured = findOffsetByName(j, "C_CSPlayerPawnBase", "m_bScreenTearFrameCaptured");
    C_CSPlayerPawnBase.m_flFlashBangTime = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flFlashBangTime");
    C_CSPlayerPawnBase.m_flFlashScreenshotAlpha = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flFlashScreenshotAlpha");
    C_CSPlayerPawnBase.m_flFlashOverlayAlpha = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flFlashOverlayAlpha");
    C_CSPlayerPawnBase.m_bFlashBuildUp = findOffsetByName(j, "C_CSPlayerPawnBase", "m_bFlashBuildUp");
    C_CSPlayerPawnBase.m_bFlashDspHasBeenCleared = findOffsetByName(j, "C_CSPlayerPawnBase", "m_bFlashDspHasBeenCleared");
    C_CSPlayerPawnBase.m_bFlashScreenshotHasBeenGrabbed = findOffsetByName(j, "C_CSPlayerPawnBase", "m_bFlashScreenshotHasBeenGrabbed");
    C_CSPlayerPawnBase.m_flFlashMaxAlpha = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flFlashMaxAlpha");
    C_CSPlayerPawnBase.m_flFlashDuration = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flFlashDuration");
    C_CSPlayerPawnBase.m_iHealthBarRenderMaskIndex = findOffsetByName(j, "C_CSPlayerPawnBase", "m_iHealthBarRenderMaskIndex");
    C_CSPlayerPawnBase.m_flHealthFadeValue = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flHealthFadeValue");
    C_CSPlayerPawnBase.m_flHealthFadeAlpha = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flHealthFadeAlpha");
    C_CSPlayerPawnBase.m_flDeathCCWeight = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flDeathCCWeight");
    C_CSPlayerPawnBase.m_flPrevRoundEndTime = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flPrevRoundEndTime");
    C_CSPlayerPawnBase.m_flPrevMatchEndTime = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flPrevMatchEndTime");
    C_CSPlayerPawnBase.m_angEyeAngles = findOffsetByName(j, "C_CSPlayerPawnBase", "m_angEyeAngles");
    C_CSPlayerPawnBase.m_fNextThinkPushAway = findOffsetByName(j, "C_CSPlayerPawnBase", "m_fNextThinkPushAway");
    C_CSPlayerPawnBase.m_bShouldAutobuyDMWeapons = findOffsetByName(j, "C_CSPlayerPawnBase", "m_bShouldAutobuyDMWeapons");
    C_CSPlayerPawnBase.m_bShouldAutobuyNow = findOffsetByName(j, "C_CSPlayerPawnBase", "m_bShouldAutobuyNow");
    C_CSPlayerPawnBase.m_iIDEntIndex = findOffsetByName(j, "C_CSPlayerPawnBase", "m_iIDEntIndex");
    C_CSPlayerPawnBase.m_delayTargetIDTimer = findOffsetByName(j, "C_CSPlayerPawnBase", "m_delayTargetIDTimer");
    C_CSPlayerPawnBase.m_iTargetItemEntIdx = findOffsetByName(j, "C_CSPlayerPawnBase", "m_iTargetItemEntIdx");
    C_CSPlayerPawnBase.m_iOldIDEntIndex = findOffsetByName(j, "C_CSPlayerPawnBase", "m_iOldIDEntIndex");
    C_CSPlayerPawnBase.m_holdTargetIDTimer = findOffsetByName(j, "C_CSPlayerPawnBase", "m_holdTargetIDTimer");
    C_CSPlayerPawnBase.m_flCurrentMusicStartTime = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flCurrentMusicStartTime");
    C_CSPlayerPawnBase.m_flMusicRoundStartTime = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flMusicRoundStartTime");
    C_CSPlayerPawnBase.m_bDeferStartMusicOnWarmup = findOffsetByName(j, "C_CSPlayerPawnBase", "m_bDeferStartMusicOnWarmup");
    C_CSPlayerPawnBase.m_cycleLatch = findOffsetByName(j, "C_CSPlayerPawnBase", "m_cycleLatch");
    C_CSPlayerPawnBase.m_serverIntendedCycle = findOffsetByName(j, "C_CSPlayerPawnBase", "m_serverIntendedCycle");
    C_CSPlayerPawnBase.m_flLastSmokeOverlayAlpha = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flLastSmokeOverlayAlpha");
    C_CSPlayerPawnBase.m_flLastSmokeAge = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flLastSmokeAge");
    C_CSPlayerPawnBase.m_vLastSmokeOverlayColor = findOffsetByName(j, "C_CSPlayerPawnBase", "m_vLastSmokeOverlayColor");
    C_CSPlayerPawnBase.m_nPlayerSmokedFx = findOffsetByName(j, "C_CSPlayerPawnBase", "m_nPlayerSmokedFx");
    C_CSPlayerPawnBase.m_nPlayerInfernoBodyFx = findOffsetByName(j, "C_CSPlayerPawnBase", "m_nPlayerInfernoBodyFx");
    C_CSPlayerPawnBase.m_nPlayerInfernoFootFx = findOffsetByName(j, "C_CSPlayerPawnBase", "m_nPlayerInfernoFootFx");
    C_CSPlayerPawnBase.m_flNextMagDropTime = findOffsetByName(j, "C_CSPlayerPawnBase", "m_flNextMagDropTime");
    C_CSPlayerPawnBase.m_nLastMagDropAttachmentIndex = findOffsetByName(j, "C_CSPlayerPawnBase", "m_nLastMagDropAttachmentIndex");
    C_CSPlayerPawnBase.m_vecLastAliveLocalVelocity = findOffsetByName(j, "C_CSPlayerPawnBase", "m_vecLastAliveLocalVelocity");
    C_CSPlayerPawnBase.m_bGuardianShouldSprayCustomXMark = findOffsetByName(j, "C_CSPlayerPawnBase", "m_bGuardianShouldSprayCustomXMark");
    C_CSPlayerPawnBase.m_hOriginalController = findOffsetByName(j, "C_CSPlayerPawnBase", "m_hOriginalController");

    // Atribuições para C_EnvWindShared
    // C_EnvWindShared Offsets
    C_EnvWindShared.m_flStartTime = findOffsetByName(j, "C_EnvWindShared", "m_flStartTime");
    C_EnvWindShared.m_iWindSeed = findOffsetByName(j, "C_EnvWindShared", "m_iWindSeed");
    C_EnvWindShared.m_iMinWind = findOffsetByName(j, "C_EnvWindShared", "m_iMinWind");
    C_EnvWindShared.m_iMaxWind = findOffsetByName(j, "C_EnvWindShared", "m_iMaxWind");
    C_EnvWindShared.m_windRadius = findOffsetByName(j, "C_EnvWindShared", "m_windRadius");
    C_EnvWindShared.m_iMinGust = findOffsetByName(j, "C_EnvWindShared", "m_iMinGust");
    C_EnvWindShared.m_iMaxGust = findOffsetByName(j, "C_EnvWindShared", "m_iMaxGust");
    C_EnvWindShared.m_flMinGustDelay = findOffsetByName(j, "C_EnvWindShared", "m_flMinGustDelay");
    C_EnvWindShared.m_flMaxGustDelay = findOffsetByName(j, "C_EnvWindShared", "m_flMaxGustDelay");
    C_EnvWindShared.m_flGustDuration = findOffsetByName(j, "C_EnvWindShared", "m_flGustDuration");
    C_EnvWindShared.m_iGustDirChange = findOffsetByName(j, "C_EnvWindShared", "m_iGustDirChange");
    C_EnvWindShared.m_location = findOffsetByName(j, "C_EnvWindShared", "m_location");
    C_EnvWindShared.m_iszGustSound = findOffsetByName(j, "C_EnvWindShared", "m_iszGustSound");
    C_EnvWindShared.m_iWindDir = findOffsetByName(j, "C_EnvWindShared", "m_iWindDir");
    C_EnvWindShared.m_flWindSpeed = findOffsetByName(j, "C_EnvWindShared", "m_flWindSpeed");
    C_EnvWindShared.m_currentWindVector = findOffsetByName(j, "C_EnvWindShared", "m_currentWindVector");
    C_EnvWindShared.m_CurrentSwayVector = findOffsetByName(j, "C_EnvWindShared", "m_CurrentSwayVector");
    C_EnvWindShared.m_PrevSwayVector = findOffsetByName(j, "C_EnvWindShared", "m_PrevSwayVector");
    C_EnvWindShared.m_iInitialWindDir = findOffsetByName(j, "C_EnvWindShared", "m_iInitialWindDir");
    C_EnvWindShared.m_flInitialWindSpeed = findOffsetByName(j, "C_EnvWindShared", "m_flInitialWindSpeed");
    C_EnvWindShared.m_flVariationTime = findOffsetByName(j, "C_EnvWindShared", "m_flVariationTime");
    C_EnvWindShared.m_flSwayTime = findOffsetByName(j, "C_EnvWindShared", "m_flSwayTime");
    C_EnvWindShared.m_flSimTime = findOffsetByName(j, "C_EnvWindShared", "m_flSimTime");
    C_EnvWindShared.m_flSwitchTime = findOffsetByName(j, "C_EnvWindShared", "m_flSwitchTime");
    C_EnvWindShared.m_flAveWindSpeed = findOffsetByName(j, "C_EnvWindShared", "m_flAveWindSpeed");
    C_EnvWindShared.m_bGusting = findOffsetByName(j, "C_EnvWindShared", "m_bGusting");
    C_EnvWindShared.m_flWindAngleVariation = findOffsetByName(j, "C_EnvWindShared", "m_flWindAngleVariation");
    C_EnvWindShared.m_flWindSpeedVariation = findOffsetByName(j, "C_EnvWindShared", "m_flWindSpeedVariation");
    C_EnvWindShared.m_hEntOwner = findOffsetByName(j, "C_EnvWindShared", "m_hEntOwner");

    // Atribuições para C_PostProcessingVolume
    // C_PostProcessingVolume Offsets
    C_PostProcessingVolume.m_hPostSettings = findOffsetByName(j, "C_PostProcessingVolume", "m_hPostSettings");
    C_PostProcessingVolume.m_flFadeDuration = findOffsetByName(j, "C_PostProcessingVolume", "m_flFadeDuration");
    C_PostProcessingVolume.m_flMinLogExposure = findOffsetByName(j, "C_PostProcessingVolume", "m_flMinLogExposure");
    C_PostProcessingVolume.m_flMaxLogExposure = findOffsetByName(j, "C_PostProcessingVolume", "m_flMaxLogExposure");
    C_PostProcessingVolume.m_flMinExposure = findOffsetByName(j, "C_PostProcessingVolume", "m_flMinExposure");
    C_PostProcessingVolume.m_flMaxExposure = findOffsetByName(j, "C_PostProcessingVolume", "m_flMaxExposure");
    C_PostProcessingVolume.m_flExposureCompensation = findOffsetByName(j, "C_PostProcessingVolume", "m_flExposureCompensation");
    C_PostProcessingVolume.m_flExposureFadeSpeedUp = findOffsetByName(j, "C_PostProcessingVolume", "m_flExposureFadeSpeedUp");
    C_PostProcessingVolume.m_flExposureFadeSpeedDown = findOffsetByName(j, "C_PostProcessingVolume", "m_flExposureFadeSpeedDown");
    C_PostProcessingVolume.m_flTonemapEVSmoothingRange = findOffsetByName(j, "C_PostProcessingVolume", "m_flTonemapEVSmoothingRange");
    C_PostProcessingVolume.m_bMaster = findOffsetByName(j, "C_PostProcessingVolume", "m_bMaster");
    C_PostProcessingVolume.m_bExposureControl = findOffsetByName(j, "C_PostProcessingVolume", "m_bExposureControl");
    C_PostProcessingVolume.m_flRate = findOffsetByName(j, "C_PostProcessingVolume", "m_flRate");
    C_PostProcessingVolume.m_flTonemapPercentTarget = findOffsetByName(j, "C_PostProcessingVolume", "m_flTonemapPercentTarget");
    C_PostProcessingVolume.m_flTonemapPercentBrightPixels = findOffsetByName(j, "C_PostProcessingVolume", "m_flTonemapPercentBrightPixels");
    C_PostProcessingVolume.m_flTonemapMinAvgLum = findOffsetByName(j, "C_PostProcessingVolume", "m_flTonemapMinAvgLum");

    // Atribuições para CCSPlayer_PingServices
    // CCSPlayer_PingServices Offsets
    CCSPlayer_PingServices.m_hPlayerPing = findOffsetByName(j, "CCSPlayer_PingServices", "m_hPlayerPing");

    // Atribuições para C_AttributeContainer
    // C_AttributeContainer Offsets
    C_AttributeContainer.m_Item = findOffsetByName(j, "C_AttributeContainer", "m_Item");
    C_AttributeContainer.m_iExternalItemProviderRegisteredToken = findOffsetByName(j, "C_AttributeContainer", "m_iExternalItemProviderRegisteredToken");
    C_AttributeContainer.m_ullRegisteredAsItemID = findOffsetByName(j, "C_AttributeContainer", "m_ullRegisteredAsItemID");

    // Atribuições para C_BaseFire
    // C_BaseFire Offsets
    C_BaseFire.m_flScale = findOffsetByName(j, "C_BaseFire", "m_flScale");
    C_BaseFire.m_flStartScale = findOffsetByName(j, "C_BaseFire", "m_flStartScale");
    C_BaseFire.m_flScaleTime = findOffsetByName(j, "C_BaseFire", "m_flScaleTime");
    C_BaseFire.m_nFlags = findOffsetByName(j, "C_BaseFire", "m_nFlags");

    // Atribuições para CBasePlayerController
    // CBasePlayerController Offsets
    CBasePlayerController.m_nFinalPredictedTick = findOffsetByName(j, "CBasePlayerController", "m_nFinalPredictedTick");
    CBasePlayerController.m_CommandContext = findOffsetByName(j, "CBasePlayerController", "m_CommandContext");
    CBasePlayerController.m_nInButtonsWhichAreToggles = findOffsetByName(j, "CBasePlayerController", "m_nInButtonsWhichAreToggles");
    CBasePlayerController.m_nTickBase = findOffsetByName(j, "CBasePlayerController", "m_nTickBase");
    CBasePlayerController.m_hPawn = findOffsetByName(j, "CBasePlayerController", "m_hPawn");
    CBasePlayerController.m_bKnownTeamMismatch = findOffsetByName(j, "CBasePlayerController", "m_bKnownTeamMismatch");
    CBasePlayerController.m_hPredictedPawn = findOffsetByName(j, "CBasePlayerController", "m_hPredictedPawn");
    CBasePlayerController.m_nSplitScreenSlot = findOffsetByName(j, "CBasePlayerController", "m_nSplitScreenSlot");
    CBasePlayerController.m_hSplitOwner = findOffsetByName(j, "CBasePlayerController", "m_hSplitOwner");
    CBasePlayerController.m_hSplitScreenPlayers = findOffsetByName(j, "CBasePlayerController", "m_hSplitScreenPlayers");
    CBasePlayerController.m_bIsHLTV = findOffsetByName(j, "CBasePlayerController", "m_bIsHLTV");
    CBasePlayerController.m_iConnected = findOffsetByName(j, "CBasePlayerController", "m_iConnected");
    CBasePlayerController.m_iszPlayerName = findOffsetByName(j, "CBasePlayerController", "m_iszPlayerName");
    CBasePlayerController.m_steamID = findOffsetByName(j, "CBasePlayerController", "m_steamID");
    CBasePlayerController.m_bIsLocalPlayerController = findOffsetByName(j, "CBasePlayerController", "m_bIsLocalPlayerController");
    CBasePlayerController.m_iDesiredFOV = findOffsetByName(j, "CBasePlayerController", "m_iDesiredFOV");

    // Atribuições para C_DecoyProjectile
    // C_DecoyProjectile Offsets
    C_DecoyProjectile.m_nDecoyShotTick = findOffsetByName(j, "C_DecoyProjectile", "m_nDecoyShotTick");
    C_DecoyProjectile.m_nClientLastKnownDecoyShotTick = findOffsetByName(j, "C_DecoyProjectile", "m_nClientLastKnownDecoyShotTick");
    C_DecoyProjectile.m_flTimeParticleEffectSpawn = findOffsetByName(j, "C_DecoyProjectile", "m_flTimeParticleEffectSpawn");

    // Atribuições para C_CSGO_PreviewPlayer
    // C_CSGO_PreviewPlayer Offsets
    C_CSGO_PreviewPlayer.m_animgraph = findOffsetByName(j, "C_CSGO_PreviewPlayer", "m_animgraph");
    C_CSGO_PreviewPlayer.m_animgraphCharacterModeString = findOffsetByName(j, "C_CSGO_PreviewPlayer", "m_animgraphCharacterModeString");
    C_CSGO_PreviewPlayer.m_flInitialModelScale = findOffsetByName(j, "C_CSGO_PreviewPlayer", "m_flInitialModelScale");

    // Atribuições para CBaseAnimGraphController
    // CBaseAnimGraphController Offsets
    CBaseAnimGraphController.m_animGraphNetworkedVars = findOffsetByName(j, "CBaseAnimGraphController", "m_animGraphNetworkedVars");
    CBaseAnimGraphController.m_bSequenceFinished = findOffsetByName(j, "CBaseAnimGraphController", "m_bSequenceFinished");
    CBaseAnimGraphController.m_flSoundSyncTime = findOffsetByName(j, "CBaseAnimGraphController", "m_flSoundSyncTime");
    CBaseAnimGraphController.m_nActiveIKChainMask = findOffsetByName(j, "CBaseAnimGraphController", "m_nActiveIKChainMask");
    CBaseAnimGraphController.m_hSequence = findOffsetByName(j, "CBaseAnimGraphController", "m_hSequence");
    CBaseAnimGraphController.m_flSeqStartTime = findOffsetByName(j, "CBaseAnimGraphController", "m_flSeqStartTime");
    CBaseAnimGraphController.m_flSeqFixedCycle = findOffsetByName(j, "CBaseAnimGraphController", "m_flSeqFixedCycle");
    CBaseAnimGraphController.m_nAnimLoopMode = findOffsetByName(j, "CBaseAnimGraphController", "m_nAnimLoopMode");
    CBaseAnimGraphController.m_flPlaybackRate = findOffsetByName(j, "CBaseAnimGraphController", "m_flPlaybackRate");
    CBaseAnimGraphController.m_nNotifyState = findOffsetByName(j, "CBaseAnimGraphController", "m_nNotifyState");
    CBaseAnimGraphController.m_bNetworkedAnimationInputsChanged = findOffsetByName(j, "CBaseAnimGraphController", "m_bNetworkedAnimationInputsChanged");
    CBaseAnimGraphController.m_bNetworkedSequenceChanged = findOffsetByName(j, "CBaseAnimGraphController", "m_bNetworkedSequenceChanged");
    CBaseAnimGraphController.m_bLastUpdateSkipped = findOffsetByName(j, "CBaseAnimGraphController", "m_bLastUpdateSkipped");
    CBaseAnimGraphController.m_flPrevAnimUpdateTime = findOffsetByName(j, "CBaseAnimGraphController", "m_flPrevAnimUpdateTime");

    // Atribuições para C_C4
    // C_C4 Offsets
    C_C4.m_szScreenText = findOffsetByName(j, "C_C4", "m_szScreenText");
    C_C4.m_activeLightParticleIndex = findOffsetByName(j, "C_C4", "m_activeLightParticleIndex");
    C_C4.m_eActiveLightEffect = findOffsetByName(j, "C_C4", "m_eActiveLightEffect");
    C_C4.m_bStartedArming = findOffsetByName(j, "C_C4", "m_bStartedArming");
    C_C4.m_fArmedTime = findOffsetByName(j, "C_C4", "m_fArmedTime");
    C_C4.m_bBombPlacedAnimation = findOffsetByName(j, "C_C4", "m_bBombPlacedAnimation");
    C_C4.m_bIsPlantingViaUse = findOffsetByName(j, "C_C4", "m_bIsPlantingViaUse");
    C_C4.m_entitySpottedState = findOffsetByName(j, "C_C4", "m_entitySpottedState");
    C_C4.m_nSpotRules = findOffsetByName(j, "C_C4", "m_nSpotRules");
    C_C4.m_bPlayedArmingBeeps = findOffsetByName(j, "C_C4", "m_bPlayedArmingBeeps");
    C_C4.m_bBombPlanted = findOffsetByName(j, "C_C4", "m_bBombPlanted");

    // Atribuições para CBaseAnimGraph
    // CBaseAnimGraph Offsets
    CBaseAnimGraph.m_bInitiallyPopulateInterpHistory = findOffsetByName(j, "CBaseAnimGraph", "m_bInitiallyPopulateInterpHistory");
    CBaseAnimGraph.m_bSuppressAnimEventSounds = findOffsetByName(j, "CBaseAnimGraph", "m_bSuppressAnimEventSounds");
    CBaseAnimGraph.m_bAnimGraphUpdateEnabled = findOffsetByName(j, "CBaseAnimGraph", "m_bAnimGraphUpdateEnabled");
    CBaseAnimGraph.m_flMaxSlopeDistance = findOffsetByName(j, "CBaseAnimGraph", "m_flMaxSlopeDistance");
    CBaseAnimGraph.m_vLastSlopeCheckPos = findOffsetByName(j, "CBaseAnimGraph", "m_vLastSlopeCheckPos");
    CBaseAnimGraph.m_bAnimationUpdateScheduled = findOffsetByName(j, "CBaseAnimGraph", "m_bAnimationUpdateScheduled");
    CBaseAnimGraph.m_vecForce = findOffsetByName(j, "CBaseAnimGraph", "m_vecForce");
    CBaseAnimGraph.m_nForceBone = findOffsetByName(j, "CBaseAnimGraph", "m_nForceBone");
    CBaseAnimGraph.m_pClientsideRagdoll = findOffsetByName(j, "CBaseAnimGraph", "m_pClientsideRagdoll");
    CBaseAnimGraph.m_bBuiltRagdoll = findOffsetByName(j, "CBaseAnimGraph", "m_bBuiltRagdoll");
    CBaseAnimGraph.m_RagdollPose = findOffsetByName(j, "CBaseAnimGraph", "m_RagdollPose");
    CBaseAnimGraph.m_bRagdollClientSide = findOffsetByName(j, "CBaseAnimGraph", "m_bRagdollClientSide");
    CBaseAnimGraph.m_bHasAnimatedMaterialAttributes = findOffsetByName(j, "CBaseAnimGraph", "m_bHasAnimatedMaterialAttributes");

    // Atribuições para C_PathParticleRope
    // C_PathParticleRope Offsets
    C_PathParticleRope.m_bStartActive = findOffsetByName(j, "C_PathParticleRope", "m_bStartActive");
    C_PathParticleRope.m_flMaxSimulationTime = findOffsetByName(j, "C_PathParticleRope", "m_flMaxSimulationTime");
    C_PathParticleRope.m_iszEffectName = findOffsetByName(j, "C_PathParticleRope", "m_iszEffectName");
    C_PathParticleRope.m_PathNodes_Name = findOffsetByName(j, "C_PathParticleRope", "m_PathNodes_Name");
    C_PathParticleRope.m_flParticleSpacing = findOffsetByName(j, "C_PathParticleRope", "m_flParticleSpacing");
    C_PathParticleRope.m_flSlack = findOffsetByName(j, "C_PathParticleRope", "m_flSlack");
    C_PathParticleRope.m_flRadius = findOffsetByName(j, "C_PathParticleRope", "m_flRadius");
    C_PathParticleRope.m_ColorTint = findOffsetByName(j, "C_PathParticleRope", "m_ColorTint");
    C_PathParticleRope.m_nEffectState = findOffsetByName(j, "C_PathParticleRope", "m_nEffectState");
    C_PathParticleRope.m_iEffectIndex = findOffsetByName(j, "C_PathParticleRope", "m_iEffectIndex");
    C_PathParticleRope.m_PathNodes_Position = findOffsetByName(j, "C_PathParticleRope", "m_PathNodes_Position");
    C_PathParticleRope.m_PathNodes_TangentIn = findOffsetByName(j, "C_PathParticleRope", "m_PathNodes_TangentIn");
    C_PathParticleRope.m_PathNodes_TangentOut = findOffsetByName(j, "C_PathParticleRope", "m_PathNodes_TangentOut");
    C_PathParticleRope.m_PathNodes_Color = findOffsetByName(j, "C_PathParticleRope", "m_PathNodes_Color");
    C_PathParticleRope.m_PathNodes_PinEnabled = findOffsetByName(j, "C_PathParticleRope", "m_PathNodes_PinEnabled");
    C_PathParticleRope.m_PathNodes_RadiusScale = findOffsetByName(j, "C_PathParticleRope", "m_PathNodes_RadiusScale");

    // Atribuições para C_SoundEventAABBEntity
    // C_SoundEventAABBEntity Offsets
    C_SoundEventAABBEntity.m_vMins = findOffsetByName(j, "C_SoundEventAABBEntity", "m_vMins");
    C_SoundEventAABBEntity.m_vMaxs = findOffsetByName(j, "C_SoundEventAABBEntity", "m_vMaxs");

    // Atribuições para C_BasePlayerWeapon
    // C_BasePlayerWeapon Offsets
    C_BasePlayerWeapon.m_nNextPrimaryAttackTick = findOffsetByName(j, "C_BasePlayerWeapon", "m_nNextPrimaryAttackTick");
    C_BasePlayerWeapon.m_flNextPrimaryAttackTickRatio = findOffsetByName(j, "C_BasePlayerWeapon", "m_flNextPrimaryAttackTickRatio");
    C_BasePlayerWeapon.m_nNextSecondaryAttackTick = findOffsetByName(j, "C_BasePlayerWeapon", "m_nNextSecondaryAttackTick");
    C_BasePlayerWeapon.m_flNextSecondaryAttackTickRatio = findOffsetByName(j, "C_BasePlayerWeapon", "m_flNextSecondaryAttackTickRatio");
    C_BasePlayerWeapon.m_iClip1 = findOffsetByName(j, "C_BasePlayerWeapon", "m_iClip1");
    C_BasePlayerWeapon.m_iClip2 = findOffsetByName(j, "C_BasePlayerWeapon", "m_iClip2");
    C_BasePlayerWeapon.m_pReserveAmmo = findOffsetByName(j, "C_BasePlayerWeapon", "m_pReserveAmmo");

    // Atribuições para CBasePlayerWeaponVData
    // CBasePlayerWeaponVData Offsets
    CBasePlayerWeaponVData.m_szWorldModel = findOffsetByName(j, "CBasePlayerWeaponVData", "m_szWorldModel");
    CBasePlayerWeaponVData.m_sToolsOnlyOwnerModelName = findOffsetByName(j, "CBasePlayerWeaponVData", "m_sToolsOnlyOwnerModelName");
    CBasePlayerWeaponVData.m_bBuiltRightHanded = findOffsetByName(j, "CBasePlayerWeaponVData", "m_bBuiltRightHanded");
    CBasePlayerWeaponVData.m_bAllowFlipping = findOffsetByName(j, "CBasePlayerWeaponVData", "m_bAllowFlipping");
    CBasePlayerWeaponVData.m_sMuzzleAttachment = findOffsetByName(j, "CBasePlayerWeaponVData", "m_sMuzzleAttachment");
    CBasePlayerWeaponVData.m_szMuzzleFlashParticle = findOffsetByName(j, "CBasePlayerWeaponVData", "m_szMuzzleFlashParticle");
    CBasePlayerWeaponVData.m_bLinkedCooldowns = findOffsetByName(j, "CBasePlayerWeaponVData", "m_bLinkedCooldowns");
    CBasePlayerWeaponVData.m_iFlags = findOffsetByName(j, "CBasePlayerWeaponVData", "m_iFlags");
    CBasePlayerWeaponVData.m_nPrimaryAmmoType = findOffsetByName(j, "CBasePlayerWeaponVData", "m_nPrimaryAmmoType");
    CBasePlayerWeaponVData.m_nSecondaryAmmoType = findOffsetByName(j, "CBasePlayerWeaponVData", "m_nSecondaryAmmoType");
    CBasePlayerWeaponVData.m_iMaxClip1 = findOffsetByName(j, "CBasePlayerWeaponVData", "m_iMaxClip1");
    CBasePlayerWeaponVData.m_iMaxClip2 = findOffsetByName(j, "CBasePlayerWeaponVData", "m_iMaxClip2");
    CBasePlayerWeaponVData.m_iDefaultClip1 = findOffsetByName(j, "CBasePlayerWeaponVData", "m_iDefaultClip1");
    CBasePlayerWeaponVData.m_iDefaultClip2 = findOffsetByName(j, "CBasePlayerWeaponVData", "m_iDefaultClip2");
    CBasePlayerWeaponVData.m_bReserveAmmoAsClips = findOffsetByName(j, "CBasePlayerWeaponVData", "m_bReserveAmmoAsClips");
    CBasePlayerWeaponVData.m_iWeight = findOffsetByName(j, "CBasePlayerWeaponVData", "m_iWeight");
    CBasePlayerWeaponVData.m_bAutoSwitchTo = findOffsetByName(j, "CBasePlayerWeaponVData", "m_bAutoSwitchTo");
    CBasePlayerWeaponVData.m_bAutoSwitchFrom = findOffsetByName(j, "CBasePlayerWeaponVData", "m_bAutoSwitchFrom");
    CBasePlayerWeaponVData.m_iRumbleEffect = findOffsetByName(j, "CBasePlayerWeaponVData", "m_iRumbleEffect");
    CBasePlayerWeaponVData.m_iSlot = findOffsetByName(j, "CBasePlayerWeaponVData", "m_iSlot");
    CBasePlayerWeaponVData.m_iPosition = findOffsetByName(j, "CBasePlayerWeaponVData", "m_iPosition");
    CBasePlayerWeaponVData.m_aShootSounds = findOffsetByName(j, "CBasePlayerWeaponVData", "m_aShootSounds");

    // Atribuições para C_Fish
    // C_Fish Offsets
    C_Fish.m_pos = findOffsetByName(j, "C_Fish", "m_pos");
    C_Fish.m_vel = findOffsetByName(j, "C_Fish", "m_vel");
    C_Fish.m_angles = findOffsetByName(j, "C_Fish", "m_angles");
    C_Fish.m_localLifeState = findOffsetByName(j, "C_Fish", "m_localLifeState");
    C_Fish.m_deathDepth = findOffsetByName(j, "C_Fish", "m_deathDepth");
    C_Fish.m_deathAngle = findOffsetByName(j, "C_Fish", "m_deathAngle");
    C_Fish.m_buoyancy = findOffsetByName(j, "C_Fish", "m_buoyancy");
    C_Fish.m_wiggleTimer = findOffsetByName(j, "C_Fish", "m_wiggleTimer");
    C_Fish.m_wigglePhase = findOffsetByName(j, "C_Fish", "m_wigglePhase");
    C_Fish.m_wiggleRate = findOffsetByName(j, "C_Fish", "m_wiggleRate");
    C_Fish.m_actualPos = findOffsetByName(j, "C_Fish", "m_actualPos");
    C_Fish.m_actualAngles = findOffsetByName(j, "C_Fish", "m_actualAngles");
    C_Fish.m_poolOrigin = findOffsetByName(j, "C_Fish", "m_poolOrigin");
    C_Fish.m_waterLevel = findOffsetByName(j, "C_Fish", "m_waterLevel");
    C_Fish.m_gotUpdate = findOffsetByName(j, "C_Fish", "m_gotUpdate");
    C_Fish.m_x = findOffsetByName(j, "C_Fish", "m_x");
    C_Fish.m_y = findOffsetByName(j, "C_Fish", "m_y");
    C_Fish.m_z = findOffsetByName(j, "C_Fish", "m_z");
    C_Fish.m_angle = findOffsetByName(j, "C_Fish", "m_angle");
    C_Fish.m_errorHistory = findOffsetByName(j, "C_Fish", "m_errorHistory");
    C_Fish.m_errorHistoryIndex = findOffsetByName(j, "C_Fish", "m_errorHistoryIndex");
    C_Fish.m_errorHistoryCount = findOffsetByName(j, "C_Fish", "m_errorHistoryCount");
    C_Fish.m_averageError = findOffsetByName(j, "C_Fish", "m_averageError");

    // Atribuições para CTimeline
    // CTimeline Offsets
    CTimeline.m_flValues = findOffsetByName(j, "CTimeline", "m_flValues");
    CTimeline.m_nValueCounts = findOffsetByName(j, "CTimeline", "m_nValueCounts");
    CTimeline.m_nBucketCount = findOffsetByName(j, "CTimeline", "m_nBucketCount");
    CTimeline.m_flInterval = findOffsetByName(j, "CTimeline", "m_flInterval");
    CTimeline.m_flFinalValue = findOffsetByName(j, "CTimeline", "m_flFinalValue");
    CTimeline.m_nCompressionType = findOffsetByName(j, "CTimeline", "m_nCompressionType");
    CTimeline.m_bStopped = findOffsetByName(j, "CTimeline", "m_bStopped");

    // Atribuições para C_BasePlayerPawn
    // C_BasePlayerPawn Offsets
    C_BasePlayerPawn.m_pWeaponServices = findOffsetByName(j, "C_BasePlayerPawn", "m_pWeaponServices");
    C_BasePlayerPawn.m_pItemServices = findOffsetByName(j, "C_BasePlayerPawn", "m_pItemServices");
    C_BasePlayerPawn.m_pAutoaimServices = findOffsetByName(j, "C_BasePlayerPawn", "m_pAutoaimServices");
    C_BasePlayerPawn.m_pObserverServices = findOffsetByName(j, "C_BasePlayerPawn", "m_pObserverServices");
    C_BasePlayerPawn.m_pWaterServices = findOffsetByName(j, "C_BasePlayerPawn", "m_pWaterServices");
    C_BasePlayerPawn.m_pUseServices = findOffsetByName(j, "C_BasePlayerPawn", "m_pUseServices");
    C_BasePlayerPawn.m_pFlashlightServices = findOffsetByName(j, "C_BasePlayerPawn", "m_pFlashlightServices");
    C_BasePlayerPawn.m_pCameraServices = findOffsetByName(j, "C_BasePlayerPawn", "m_pCameraServices");
    C_BasePlayerPawn.m_pMovementServices = findOffsetByName(j, "C_BasePlayerPawn", "m_pMovementServices");
    C_BasePlayerPawn.m_ServerViewAngleChanges = findOffsetByName(j, "C_BasePlayerPawn", "m_ServerViewAngleChanges");
    C_BasePlayerPawn.m_nHighestConsumedServerViewAngleChangeIndex = findOffsetByName(j, "C_BasePlayerPawn", "m_nHighestConsumedServerViewAngleChangeIndex");
    C_BasePlayerPawn.v_angle = findOffsetByName(j, "C_BasePlayerPawn", "v_angle");
    C_BasePlayerPawn.v_anglePrevious = findOffsetByName(j, "C_BasePlayerPawn", "v_anglePrevious");
    C_BasePlayerPawn.m_iHideHUD = findOffsetByName(j, "C_BasePlayerPawn", "m_iHideHUD");
    C_BasePlayerPawn.m_skybox3d = findOffsetByName(j, "C_BasePlayerPawn", "m_skybox3d");
    C_BasePlayerPawn.m_flDeathTime = findOffsetByName(j, "C_BasePlayerPawn", "m_flDeathTime");
    C_BasePlayerPawn.m_vecPredictionError = findOffsetByName(j, "C_BasePlayerPawn", "m_vecPredictionError");
    C_BasePlayerPawn.m_flPredictionErrorTime = findOffsetByName(j, "C_BasePlayerPawn", "m_flPredictionErrorTime");
    C_BasePlayerPawn.m_vecLastCameraSetupLocalOrigin = findOffsetByName(j, "C_BasePlayerPawn", "m_vecLastCameraSetupLocalOrigin");
    C_BasePlayerPawn.m_flLastCameraSetupTime = findOffsetByName(j, "C_BasePlayerPawn", "m_flLastCameraSetupTime");
    C_BasePlayerPawn.m_flFOVSensitivityAdjust = findOffsetByName(j, "C_BasePlayerPawn", "m_flFOVSensitivityAdjust");
    C_BasePlayerPawn.m_flMouseSensitivity = findOffsetByName(j, "C_BasePlayerPawn", "m_flMouseSensitivity");
    C_BasePlayerPawn.m_vOldOrigin = findOffsetByName(j, "C_BasePlayerPawn", "m_vOldOrigin");
    C_BasePlayerPawn.m_flOldSimulationTime = findOffsetByName(j, "C_BasePlayerPawn", "m_flOldSimulationTime");
    C_BasePlayerPawn.m_nLastExecutedCommandNumber = findOffsetByName(j, "C_BasePlayerPawn", "m_nLastExecutedCommandNumber");
    C_BasePlayerPawn.m_nLastExecutedCommandTick = findOffsetByName(j, "C_BasePlayerPawn", "m_nLastExecutedCommandTick");
    C_BasePlayerPawn.m_hController = findOffsetByName(j, "C_BasePlayerPawn", "m_hController");
    C_BasePlayerPawn.m_bIsSwappingToPredictableController = findOffsetByName(j, "C_BasePlayerPawn", "m_bIsSwappingToPredictableController");

    // Atribuições para CAttributeManager
    // CAttributeManager Offsets
    CAttributeManager.m_Providers = findOffsetByName(j, "CAttributeManager", "m_Providers");
    CAttributeManager.m_iReapplyProvisionParity = findOffsetByName(j, "CAttributeManager", "m_iReapplyProvisionParity");
    CAttributeManager.m_hOuter = findOffsetByName(j, "CAttributeManager", "m_hOuter");
    CAttributeManager.m_bPreventLoopback = findOffsetByName(j, "CAttributeManager", "m_bPreventLoopback");
    CAttributeManager.m_ProviderType = findOffsetByName(j, "CAttributeManager", "m_ProviderType");
    CAttributeManager.m_CachedResults = findOffsetByName(j, "CAttributeManager", "m_CachedResults");

    // Atribuições para CAnimGraphNetworkedVariables
    // CAnimGraphNetworkedVariables Offsets
    CAnimGraphNetworkedVariables.m_PredNetBoolVariables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_PredNetBoolVariables");
    CAnimGraphNetworkedVariables.m_PredNetByteVariables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_PredNetByteVariables");
    CAnimGraphNetworkedVariables.m_PredNetUInt16Variables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_PredNetUInt16Variables");
    CAnimGraphNetworkedVariables.m_PredNetIntVariables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_PredNetIntVariables");
    CAnimGraphNetworkedVariables.m_PredNetUInt32Variables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_PredNetUInt32Variables");
    CAnimGraphNetworkedVariables.m_PredNetUInt64Variables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_PredNetUInt64Variables");
    CAnimGraphNetworkedVariables.m_PredNetFloatVariables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_PredNetFloatVariables");
    CAnimGraphNetworkedVariables.m_PredNetVectorVariables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_PredNetVectorVariables");
    CAnimGraphNetworkedVariables.m_PredNetQuaternionVariables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_PredNetQuaternionVariables");
    CAnimGraphNetworkedVariables.m_PredNetGlobalSymbolVariables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_PredNetGlobalSymbolVariables");
    CAnimGraphNetworkedVariables.m_OwnerOnlyPredNetBoolVariables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetBoolVariables");
    CAnimGraphNetworkedVariables.m_OwnerOnlyPredNetByteVariables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetByteVariables");
    CAnimGraphNetworkedVariables.m_OwnerOnlyPredNetUInt16Variables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetUInt16Variables");
    CAnimGraphNetworkedVariables.m_OwnerOnlyPredNetIntVariables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetIntVariables");
    CAnimGraphNetworkedVariables.m_OwnerOnlyPredNetUInt32Variables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetUInt32Variables");
    CAnimGraphNetworkedVariables.m_OwnerOnlyPredNetUInt64Variables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetUInt64Variables");
    CAnimGraphNetworkedVariables.m_OwnerOnlyPredNetFloatVariables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetFloatVariables");
    CAnimGraphNetworkedVariables.m_OwnerOnlyPredNetVectorVariables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetVectorVariables");
    CAnimGraphNetworkedVariables.m_OwnerOnlyPredNetQuaternionVariables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetQuaternionVariables");
    CAnimGraphNetworkedVariables.m_OwnerOnlyPredNetGlobalSymbolVariables = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_OwnerOnlyPredNetGlobalSymbolVariables");
    CAnimGraphNetworkedVariables.m_nBoolVariablesCount = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_nBoolVariablesCount");
    CAnimGraphNetworkedVariables.m_nOwnerOnlyBoolVariablesCount = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_nOwnerOnlyBoolVariablesCount");
    CAnimGraphNetworkedVariables.m_nRandomSeedOffset = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_nRandomSeedOffset");
    CAnimGraphNetworkedVariables.m_flLastTeleportTime = findOffsetByName(j, "CAnimGraphNetworkedVariables", "m_flLastTeleportTime");

    // Atribuições para C_TriggerBuoyancy
    // C_TriggerBuoyancy Offsets
    C_TriggerBuoyancy.m_BuoyancyHelper = findOffsetByName(j, "C_TriggerBuoyancy", "m_BuoyancyHelper");
    C_TriggerBuoyancy.m_flFluidDensity = findOffsetByName(j, "C_TriggerBuoyancy", "m_flFluidDensity");

    // Atribuições para C_RopeKeyframe
    // C_RopeKeyframe Offsets
    C_RopeKeyframe.m_LinksTouchingSomething = findOffsetByName(j, "C_RopeKeyframe", "m_LinksTouchingSomething");
    C_RopeKeyframe.m_nLinksTouchingSomething = findOffsetByName(j, "C_RopeKeyframe", "m_nLinksTouchingSomething");
    C_RopeKeyframe.m_bApplyWind = findOffsetByName(j, "C_RopeKeyframe", "m_bApplyWind");
    C_RopeKeyframe.m_fPrevLockedPoints = findOffsetByName(j, "C_RopeKeyframe", "m_fPrevLockedPoints");
    C_RopeKeyframe.m_iForcePointMoveCounter = findOffsetByName(j, "C_RopeKeyframe", "m_iForcePointMoveCounter");
    C_RopeKeyframe.m_bPrevEndPointPos = findOffsetByName(j, "C_RopeKeyframe", "m_bPrevEndPointPos");
    C_RopeKeyframe.m_vPrevEndPointPos = findOffsetByName(j, "C_RopeKeyframe", "m_vPrevEndPointPos");
    C_RopeKeyframe.m_flCurScroll = findOffsetByName(j, "C_RopeKeyframe", "m_flCurScroll");
    C_RopeKeyframe.m_flScrollSpeed = findOffsetByName(j, "C_RopeKeyframe", "m_flScrollSpeed");
    C_RopeKeyframe.m_RopeFlags = findOffsetByName(j, "C_RopeKeyframe", "m_RopeFlags");
    C_RopeKeyframe.m_iRopeMaterialModelIndex = findOffsetByName(j, "C_RopeKeyframe", "m_iRopeMaterialModelIndex");
    C_RopeKeyframe.m_LightValues = findOffsetByName(j, "C_RopeKeyframe", "m_LightValues");
    C_RopeKeyframe.m_nSegments = findOffsetByName(j, "C_RopeKeyframe", "m_nSegments");
    C_RopeKeyframe.m_hStartPoint = findOffsetByName(j, "C_RopeKeyframe", "m_hStartPoint");
    C_RopeKeyframe.m_hEndPoint = findOffsetByName(j, "C_RopeKeyframe", "m_hEndPoint");
    C_RopeKeyframe.m_iStartAttachment = findOffsetByName(j, "C_RopeKeyframe", "m_iStartAttachment");
    C_RopeKeyframe.m_iEndAttachment = findOffsetByName(j, "C_RopeKeyframe", "m_iEndAttachment");
    C_RopeKeyframe.m_Subdiv = findOffsetByName(j, "C_RopeKeyframe", "m_Subdiv");
    C_RopeKeyframe.m_RopeLength = findOffsetByName(j, "C_RopeKeyframe", "m_RopeLength");
    C_RopeKeyframe.m_Slack = findOffsetByName(j, "C_RopeKeyframe", "m_Slack");
    C_RopeKeyframe.m_TextureScale = findOffsetByName(j, "C_RopeKeyframe", "m_TextureScale");
    C_RopeKeyframe.m_fLockedPoints = findOffsetByName(j, "C_RopeKeyframe", "m_fLockedPoints");
    C_RopeKeyframe.m_nChangeCount = findOffsetByName(j, "C_RopeKeyframe", "m_nChangeCount");
    C_RopeKeyframe.m_Width = findOffsetByName(j, "C_RopeKeyframe", "m_Width");
    C_RopeKeyframe.m_PhysicsDelegate = findOffsetByName(j, "C_RopeKeyframe", "m_PhysicsDelegate");
    C_RopeKeyframe.m_hMaterial = findOffsetByName(j, "C_RopeKeyframe", "m_hMaterial");
    C_RopeKeyframe.m_TextureHeight = findOffsetByName(j, "C_RopeKeyframe", "m_TextureHeight");
    C_RopeKeyframe.m_vecImpulse = findOffsetByName(j, "C_RopeKeyframe", "m_vecImpulse");
    C_RopeKeyframe.m_vecPreviousImpulse = findOffsetByName(j, "C_RopeKeyframe", "m_vecPreviousImpulse");
    C_RopeKeyframe.m_flCurrentGustTimer = findOffsetByName(j, "C_RopeKeyframe", "m_flCurrentGustTimer");
    C_RopeKeyframe.m_flCurrentGustLifetime = findOffsetByName(j, "C_RopeKeyframe", "m_flCurrentGustLifetime");
    C_RopeKeyframe.m_flTimeToNextGust = findOffsetByName(j, "C_RopeKeyframe", "m_flTimeToNextGust");
    C_RopeKeyframe.m_vWindDir = findOffsetByName(j, "C_RopeKeyframe", "m_vWindDir");
    C_RopeKeyframe.m_vColorMod = findOffsetByName(j, "C_RopeKeyframe", "m_vColorMod");
    C_RopeKeyframe.m_vCachedEndPointAttachmentPos = findOffsetByName(j, "C_RopeKeyframe", "m_vCachedEndPointAttachmentPos");
    C_RopeKeyframe.m_vCachedEndPointAttachmentAngle = findOffsetByName(j, "C_RopeKeyframe", "m_vCachedEndPointAttachmentAngle");
    C_RopeKeyframe.m_bConstrainBetweenEndpoints = findOffsetByName(j, "C_RopeKeyframe", "m_bConstrainBetweenEndpoints");
    C_RopeKeyframe.m_bEndPointAttachmentPositionsDirty = findOffsetByName(j, "C_RopeKeyframe", "m_bEndPointAttachmentPositionsDirty");
    C_RopeKeyframe.m_bEndPointAttachmentAnglesDirty = findOffsetByName(j, "C_RopeKeyframe", "m_bEndPointAttachmentAnglesDirty");
    C_RopeKeyframe.m_bNewDataThisFrame = findOffsetByName(j, "C_RopeKeyframe", "m_bNewDataThisFrame");
    C_RopeKeyframe.m_bPhysicsInitted = findOffsetByName(j, "C_RopeKeyframe", "m_bPhysicsInitted");

    // Atribuições para C_GradientFog
    // C_GradientFog Offsets
    C_GradientFog.m_hGradientFogTexture = findOffsetByName(j, "C_GradientFog", "m_hGradientFogTexture");
    C_GradientFog.m_flFogStartDistance = findOffsetByName(j, "C_GradientFog", "m_flFogStartDistance");
    C_GradientFog.m_flFogEndDistance = findOffsetByName(j, "C_GradientFog", "m_flFogEndDistance");
    C_GradientFog.m_bHeightFogEnabled = findOffsetByName(j, "C_GradientFog", "m_bHeightFogEnabled");
    C_GradientFog.m_flFogStartHeight = findOffsetByName(j, "C_GradientFog", "m_flFogStartHeight");
    C_GradientFog.m_flFogEndHeight = findOffsetByName(j, "C_GradientFog", "m_flFogEndHeight");
    C_GradientFog.m_flFarZ = findOffsetByName(j, "C_GradientFog", "m_flFarZ");
    C_GradientFog.m_flFogMaxOpacity = findOffsetByName(j, "C_GradientFog", "m_flFogMaxOpacity");
    C_GradientFog.m_flFogFalloffExponent = findOffsetByName(j, "C_GradientFog", "m_flFogFalloffExponent");
    C_GradientFog.m_flFogVerticalExponent = findOffsetByName(j, "C_GradientFog", "m_flFogVerticalExponent");
    C_GradientFog.m_fogColor = findOffsetByName(j, "C_GradientFog", "m_fogColor");
    C_GradientFog.m_flFogStrength = findOffsetByName(j, "C_GradientFog", "m_flFogStrength");
    C_GradientFog.m_flFadeTime = findOffsetByName(j, "C_GradientFog", "m_flFadeTime");
    C_GradientFog.m_bStartDisabled = findOffsetByName(j, "C_GradientFog", "m_bStartDisabled");
    C_GradientFog.m_bIsEnabled = findOffsetByName(j, "C_GradientFog", "m_bIsEnabled");
    C_GradientFog.m_bGradientFogNeedsTextures = findOffsetByName(j, "C_GradientFog", "m_bGradientFogNeedsTextures");

    // Atribuições para EntitySpottedState_t
    // EntitySpottedState_t Offsets
    EntitySpottedState_t.m_bSpotted = findOffsetByName(j, "EntitySpottedState_t", "m_bSpotted");
    EntitySpottedState_t.m_bSpottedByMask = findOffsetByName(j, "EntitySpottedState_t", "m_bSpottedByMask");

    // Atribuições para C_CSGO_TeamPreviewCamera
    // C_CSGO_TeamPreviewCamera Offsets
    C_CSGO_TeamPreviewCamera.m_nVariant = findOffsetByName(j, "C_CSGO_TeamPreviewCamera", "m_nVariant");
    C_CSGO_TeamPreviewCamera.m_bDofEnabled = findOffsetByName(j, "C_CSGO_TeamPreviewCamera", "m_bDofEnabled");
    C_CSGO_TeamPreviewCamera.m_flDofNearBlurry = findOffsetByName(j, "C_CSGO_TeamPreviewCamera", "m_flDofNearBlurry");
    C_CSGO_TeamPreviewCamera.m_flDofNearCrisp = findOffsetByName(j, "C_CSGO_TeamPreviewCamera", "m_flDofNearCrisp");
    C_CSGO_TeamPreviewCamera.m_flDofFarCrisp = findOffsetByName(j, "C_CSGO_TeamPreviewCamera", "m_flDofFarCrisp");
    C_CSGO_TeamPreviewCamera.m_flDofFarBlurry = findOffsetByName(j, "C_CSGO_TeamPreviewCamera", "m_flDofFarBlurry");
    C_CSGO_TeamPreviewCamera.m_flDofTiltToGround = findOffsetByName(j, "C_CSGO_TeamPreviewCamera", "m_flDofTiltToGround");

    // Atribuições para CCSPlayer_CameraServices
    // CCSPlayer_CameraServices Offsets
    CCSPlayer_CameraServices.m_flDeathCamTilt = findOffsetByName(j, "CCSPlayer_CameraServices", "m_flDeathCamTilt");
    CCSPlayer_CameraServices.m_vClientScopeInaccuracy = findOffsetByName(j, "CCSPlayer_CameraServices", "m_vClientScopeInaccuracy");

    // Atribuições para C_EconWearable
    // C_EconWearable Offsets
    C_EconWearable.m_nForceSkin = findOffsetByName(j, "C_EconWearable", "m_nForceSkin");
    C_EconWearable.m_bAlwaysAllow = findOffsetByName(j, "C_EconWearable", "m_bAlwaysAllow");

    // Atribuições para CSMatchStats_t
    // CSMatchStats_t Offsets
    CSMatchStats_t.m_iEnemy5Ks = findOffsetByName(j, "CSMatchStats_t", "m_iEnemy5Ks");
    CSMatchStats_t.m_iEnemy4Ks = findOffsetByName(j, "CSMatchStats_t", "m_iEnemy4Ks");
    CSMatchStats_t.m_iEnemy3Ks = findOffsetByName(j, "CSMatchStats_t", "m_iEnemy3Ks");
    CSMatchStats_t.m_iEnemyKnifeKills = findOffsetByName(j, "CSMatchStats_t", "m_iEnemyKnifeKills");
    CSMatchStats_t.m_iEnemyTaserKills = findOffsetByName(j, "CSMatchStats_t", "m_iEnemyTaserKills");

    // Atribuições para C_EnvVolumetricFogVolume
    // C_EnvVolumetricFogVolume Offsets
    C_EnvVolumetricFogVolume.m_bActive = findOffsetByName(j, "C_EnvVolumetricFogVolume", "m_bActive");
    C_EnvVolumetricFogVolume.m_vBoxMins = findOffsetByName(j, "C_EnvVolumetricFogVolume", "m_vBoxMins");
    C_EnvVolumetricFogVolume.m_vBoxMaxs = findOffsetByName(j, "C_EnvVolumetricFogVolume", "m_vBoxMaxs");
    C_EnvVolumetricFogVolume.m_bStartDisabled = findOffsetByName(j, "C_EnvVolumetricFogVolume", "m_bStartDisabled");
    C_EnvVolumetricFogVolume.m_flStrength = findOffsetByName(j, "C_EnvVolumetricFogVolume", "m_flStrength");
    C_EnvVolumetricFogVolume.m_nFalloffShape = findOffsetByName(j, "C_EnvVolumetricFogVolume", "m_nFalloffShape");
    C_EnvVolumetricFogVolume.m_flFalloffExponent = findOffsetByName(j, "C_EnvVolumetricFogVolume", "m_flFalloffExponent");
    C_EnvVolumetricFogVolume.m_flHeightFogDepth = findOffsetByName(j, "C_EnvVolumetricFogVolume", "m_flHeightFogDepth");
    C_EnvVolumetricFogVolume.m_fHeightFogEdgeWidth = findOffsetByName(j, "C_EnvVolumetricFogVolume", "m_fHeightFogEdgeWidth");
    C_EnvVolumetricFogVolume.m_fIndirectLightStrength = findOffsetByName(j, "C_EnvVolumetricFogVolume", "m_fIndirectLightStrength");
    C_EnvVolumetricFogVolume.m_fSunLightStrength = findOffsetByName(j, "C_EnvVolumetricFogVolume", "m_fSunLightStrength");
    C_EnvVolumetricFogVolume.m_fNoiseStrength = findOffsetByName(j, "C_EnvVolumetricFogVolume", "m_fNoiseStrength");
    C_EnvVolumetricFogVolume.m_bOverrideIndirectLightStrength = findOffsetByName(j, "C_EnvVolumetricFogVolume", "m_bOverrideIndirectLightStrength");
    C_EnvVolumetricFogVolume.m_bOverrideSunLightStrength = findOffsetByName(j, "C_EnvVolumetricFogVolume", "m_bOverrideSunLightStrength");
    C_EnvVolumetricFogVolume.m_bOverrideNoiseStrength = findOffsetByName(j, "C_EnvVolumetricFogVolume", "m_bOverrideNoiseStrength");
    C_EnvVolumetricFogVolume.m_bAllowLPVIndirect = findOffsetByName(j, "C_EnvVolumetricFogVolume", "m_bAllowLPVIndirect");

    // Atribuições para C_FireSmoke
    // C_FireSmoke Offsets
    C_FireSmoke.m_nFlameModelIndex = findOffsetByName(j, "C_FireSmoke", "m_nFlameModelIndex");
    C_FireSmoke.m_nFlameFromAboveModelIndex = findOffsetByName(j, "C_FireSmoke", "m_nFlameFromAboveModelIndex");
    C_FireSmoke.m_flScaleRegister = findOffsetByName(j, "C_FireSmoke", "m_flScaleRegister");
    C_FireSmoke.m_flScaleStart = findOffsetByName(j, "C_FireSmoke", "m_flScaleStart");
    C_FireSmoke.m_flScaleEnd = findOffsetByName(j, "C_FireSmoke", "m_flScaleEnd");
    C_FireSmoke.m_flScaleTimeStart = findOffsetByName(j, "C_FireSmoke", "m_flScaleTimeStart");
    C_FireSmoke.m_flScaleTimeEnd = findOffsetByName(j, "C_FireSmoke", "m_flScaleTimeEnd");
    C_FireSmoke.m_flChildFlameSpread = findOffsetByName(j, "C_FireSmoke", "m_flChildFlameSpread");
    C_FireSmoke.m_flClipPerc = findOffsetByName(j, "C_FireSmoke", "m_flClipPerc");
    C_FireSmoke.m_bClipTested = findOffsetByName(j, "C_FireSmoke", "m_bClipTested");
    C_FireSmoke.m_bFadingOut = findOffsetByName(j, "C_FireSmoke", "m_bFadingOut");
    C_FireSmoke.m_tParticleSpawn = findOffsetByName(j, "C_FireSmoke", "m_tParticleSpawn");
    C_FireSmoke.m_pFireOverlay = findOffsetByName(j, "C_FireSmoke", "m_pFireOverlay");

    // Atribuições para C_EnvCombinedLightProbeVolume
    // C_EnvCombinedLightProbeVolume Offsets
    C_EnvCombinedLightProbeVolume.m_Entity_Color = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_Color");
    C_EnvCombinedLightProbeVolume.m_Entity_flBrightness = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_flBrightness");
    C_EnvCombinedLightProbeVolume.m_Entity_hCubemapTexture = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_hCubemapTexture");
    C_EnvCombinedLightProbeVolume.m_Entity_bCustomCubemapTexture = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_bCustomCubemapTexture");
    C_EnvCombinedLightProbeVolume.m_Entity_hLightProbeTexture = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_hLightProbeTexture");
    C_EnvCombinedLightProbeVolume.m_Entity_hLightProbeDirectLightIndicesTexture = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_hLightProbeDirectLightIndicesTexture");
    C_EnvCombinedLightProbeVolume.m_Entity_hLightProbeDirectLightScalarsTexture = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_hLightProbeDirectLightScalarsTexture");
    C_EnvCombinedLightProbeVolume.m_Entity_hLightProbeDirectLightShadowsTexture = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_hLightProbeDirectLightShadowsTexture");
    C_EnvCombinedLightProbeVolume.m_Entity_vBoxMins = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_vBoxMins");
    C_EnvCombinedLightProbeVolume.m_Entity_vBoxMaxs = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_vBoxMaxs");
    C_EnvCombinedLightProbeVolume.m_Entity_bMoveable = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_bMoveable");
    C_EnvCombinedLightProbeVolume.m_Entity_nHandshake = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_nHandshake");
    C_EnvCombinedLightProbeVolume.m_Entity_nEnvCubeMapArrayIndex = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_nEnvCubeMapArrayIndex");
    C_EnvCombinedLightProbeVolume.m_Entity_nPriority = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_nPriority");
    C_EnvCombinedLightProbeVolume.m_Entity_bStartDisabled = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_bStartDisabled");
    C_EnvCombinedLightProbeVolume.m_Entity_flEdgeFadeDist = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_flEdgeFadeDist");
    C_EnvCombinedLightProbeVolume.m_Entity_vEdgeFadeDists = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_vEdgeFadeDists");
    C_EnvCombinedLightProbeVolume.m_Entity_nLightProbeSizeX = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_nLightProbeSizeX");
    C_EnvCombinedLightProbeVolume.m_Entity_nLightProbeSizeY = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_nLightProbeSizeY");
    C_EnvCombinedLightProbeVolume.m_Entity_nLightProbeSizeZ = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_nLightProbeSizeZ");
    C_EnvCombinedLightProbeVolume.m_Entity_nLightProbeAtlasX = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_nLightProbeAtlasX");
    C_EnvCombinedLightProbeVolume.m_Entity_nLightProbeAtlasY = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_nLightProbeAtlasY");
    C_EnvCombinedLightProbeVolume.m_Entity_nLightProbeAtlasZ = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_nLightProbeAtlasZ");
    C_EnvCombinedLightProbeVolume.m_Entity_bEnabled = findOffsetByName(j, "C_EnvCombinedLightProbeVolume", "m_Entity_bEnabled");

    // Atribuições para ActiveModelConfig_t
    // ActiveModelConfig_t Offsets
    ActiveModelConfig_t.m_Handle = findOffsetByName(j, "ActiveModelConfig_t", "m_Handle");
    ActiveModelConfig_t.m_Name = findOffsetByName(j, "ActiveModelConfig_t", "m_Name");
    ActiveModelConfig_t.m_AssociatedEntities = findOffsetByName(j, "ActiveModelConfig_t", "m_AssociatedEntities");
    ActiveModelConfig_t.m_AssociatedEntityNames = findOffsetByName(j, "ActiveModelConfig_t", "m_AssociatedEntityNames");

    // Atribuições para CCSPlayer_BulletServices
    // CCSPlayer_BulletServices Offsets
    CCSPlayer_BulletServices.m_totalHitsOnServer = findOffsetByName(j, "CCSPlayer_BulletServices", "m_totalHitsOnServer");

    // Atribuições para CLogicRelay
    // CLogicRelay Offsets
    CLogicRelay.m_OnTrigger = findOffsetByName(j, "CLogicRelay", "m_OnTrigger");
    CLogicRelay.m_OnSpawn = findOffsetByName(j, "CLogicRelay", "m_OnSpawn");
    CLogicRelay.m_bDisabled = findOffsetByName(j, "CLogicRelay", "m_bDisabled");
    CLogicRelay.m_bWaitForRefire = findOffsetByName(j, "CLogicRelay", "m_bWaitForRefire");
    CLogicRelay.m_bTriggerOnce = findOffsetByName(j, "CLogicRelay", "m_bTriggerOnce");
    CLogicRelay.m_bFastRetrigger = findOffsetByName(j, "CLogicRelay", "m_bFastRetrigger");
    CLogicRelay.m_bPassthoughCaller = findOffsetByName(j, "CLogicRelay", "m_bPassthoughCaller");

    // Atribuições para C_PointCameraVFOV
    // C_PointCameraVFOV Offsets
    C_PointCameraVFOV.m_flVerticalFOV = findOffsetByName(j, "C_PointCameraVFOV", "m_flVerticalFOV");

    // Atribuições para CCSPlayer_ItemServices
    // CCSPlayer_ItemServices Offsets
    CCSPlayer_ItemServices.m_bHasDefuser = findOffsetByName(j, "CCSPlayer_ItemServices", "m_bHasDefuser");
    CCSPlayer_ItemServices.m_bHasHelmet = findOffsetByName(j, "CCSPlayer_ItemServices", "m_bHasHelmet");
    CCSPlayer_ItemServices.m_bHasHeavyArmor = findOffsetByName(j, "CCSPlayer_ItemServices", "m_bHasHeavyArmor");

    // Atribuições para C_BarnLight
    // C_BarnLight Offsets
    C_BarnLight.m_bEnabled = findOffsetByName(j, "C_BarnLight", "m_bEnabled");
    C_BarnLight.m_nColorMode = findOffsetByName(j, "C_BarnLight", "m_nColorMode");
    C_BarnLight.m_Color = findOffsetByName(j, "C_BarnLight", "m_Color");
    C_BarnLight.m_flColorTemperature = findOffsetByName(j, "C_BarnLight", "m_flColorTemperature");
    C_BarnLight.m_flBrightness = findOffsetByName(j, "C_BarnLight", "m_flBrightness");
    C_BarnLight.m_flBrightnessScale = findOffsetByName(j, "C_BarnLight", "m_flBrightnessScale");
    C_BarnLight.m_nDirectLight = findOffsetByName(j, "C_BarnLight", "m_nDirectLight");
    C_BarnLight.m_nBakedShadowIndex = findOffsetByName(j, "C_BarnLight", "m_nBakedShadowIndex");
    C_BarnLight.m_nLuminaireShape = findOffsetByName(j, "C_BarnLight", "m_nLuminaireShape");
    C_BarnLight.m_flLuminaireSize = findOffsetByName(j, "C_BarnLight", "m_flLuminaireSize");
    C_BarnLight.m_flLuminaireAnisotropy = findOffsetByName(j, "C_BarnLight", "m_flLuminaireAnisotropy");
    C_BarnLight.m_LightStyleString = findOffsetByName(j, "C_BarnLight", "m_LightStyleString");
    C_BarnLight.m_flLightStyleStartTime = findOffsetByName(j, "C_BarnLight", "m_flLightStyleStartTime");
    C_BarnLight.m_QueuedLightStyleStrings = findOffsetByName(j, "C_BarnLight", "m_QueuedLightStyleStrings");
    C_BarnLight.m_LightStyleEvents = findOffsetByName(j, "C_BarnLight", "m_LightStyleEvents");
    C_BarnLight.m_LightStyleTargets = findOffsetByName(j, "C_BarnLight", "m_LightStyleTargets");
    C_BarnLight.m_StyleEvent = findOffsetByName(j, "C_BarnLight", "m_StyleEvent");
    C_BarnLight.m_hLightCookie = findOffsetByName(j, "C_BarnLight", "m_hLightCookie");
    C_BarnLight.m_flShape = findOffsetByName(j, "C_BarnLight", "m_flShape");
    C_BarnLight.m_flSoftX = findOffsetByName(j, "C_BarnLight", "m_flSoftX");
    C_BarnLight.m_flSoftY = findOffsetByName(j, "C_BarnLight", "m_flSoftY");
    C_BarnLight.m_flSkirt = findOffsetByName(j, "C_BarnLight", "m_flSkirt");
    C_BarnLight.m_flSkirtNear = findOffsetByName(j, "C_BarnLight", "m_flSkirtNear");
    C_BarnLight.m_vSizeParams = findOffsetByName(j, "C_BarnLight", "m_vSizeParams");
    C_BarnLight.m_flRange = findOffsetByName(j, "C_BarnLight", "m_flRange");
    C_BarnLight.m_vShear = findOffsetByName(j, "C_BarnLight", "m_vShear");
    C_BarnLight.m_nBakeSpecularToCubemaps = findOffsetByName(j, "C_BarnLight", "m_nBakeSpecularToCubemaps");
    C_BarnLight.m_vBakeSpecularToCubemapsSize = findOffsetByName(j, "C_BarnLight", "m_vBakeSpecularToCubemapsSize");
    C_BarnLight.m_nCastShadows = findOffsetByName(j, "C_BarnLight", "m_nCastShadows");
    C_BarnLight.m_nShadowMapSize = findOffsetByName(j, "C_BarnLight", "m_nShadowMapSize");
    C_BarnLight.m_nShadowPriority = findOffsetByName(j, "C_BarnLight", "m_nShadowPriority");
    C_BarnLight.m_bContactShadow = findOffsetByName(j, "C_BarnLight", "m_bContactShadow");
    C_BarnLight.m_nBounceLight = findOffsetByName(j, "C_BarnLight", "m_nBounceLight");
    C_BarnLight.m_flBounceScale = findOffsetByName(j, "C_BarnLight", "m_flBounceScale");
    C_BarnLight.m_flMinRoughness = findOffsetByName(j, "C_BarnLight", "m_flMinRoughness");
    C_BarnLight.m_vAlternateColor = findOffsetByName(j, "C_BarnLight", "m_vAlternateColor");
    C_BarnLight.m_fAlternateColorBrightness = findOffsetByName(j, "C_BarnLight", "m_fAlternateColorBrightness");
    C_BarnLight.m_nFog = findOffsetByName(j, "C_BarnLight", "m_nFog");
    C_BarnLight.m_flFogStrength = findOffsetByName(j, "C_BarnLight", "m_flFogStrength");
    C_BarnLight.m_nFogShadows = findOffsetByName(j, "C_BarnLight", "m_nFogShadows");
    C_BarnLight.m_flFogScale = findOffsetByName(j, "C_BarnLight", "m_flFogScale");
    C_BarnLight.m_bFogMixedShadows = findOffsetByName(j, "C_BarnLight", "m_bFogMixedShadows");
    C_BarnLight.m_flFadeSizeStart = findOffsetByName(j, "C_BarnLight", "m_flFadeSizeStart");
    C_BarnLight.m_flFadeSizeEnd = findOffsetByName(j, "C_BarnLight", "m_flFadeSizeEnd");
    C_BarnLight.m_flShadowFadeSizeStart = findOffsetByName(j, "C_BarnLight", "m_flShadowFadeSizeStart");
    C_BarnLight.m_flShadowFadeSizeEnd = findOffsetByName(j, "C_BarnLight", "m_flShadowFadeSizeEnd");
    C_BarnLight.m_bPrecomputedFieldsValid = findOffsetByName(j, "C_BarnLight", "m_bPrecomputedFieldsValid");
    C_BarnLight.m_vPrecomputedBoundsMins = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedBoundsMins");
    C_BarnLight.m_vPrecomputedBoundsMaxs = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedBoundsMaxs");
    C_BarnLight.m_vPrecomputedOBBOrigin = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBOrigin");
    C_BarnLight.m_vPrecomputedOBBAngles = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBAngles");
    C_BarnLight.m_vPrecomputedOBBExtent = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBExtent");
    C_BarnLight.m_nPrecomputedSubFrusta = findOffsetByName(j, "C_BarnLight", "m_nPrecomputedSubFrusta");
    C_BarnLight.m_vPrecomputedOBBOrigin0 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBOrigin0");
    C_BarnLight.m_vPrecomputedOBBAngles0 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBAngles0");
    C_BarnLight.m_vPrecomputedOBBExtent0 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBExtent0");
    C_BarnLight.m_vPrecomputedOBBOrigin1 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBOrigin1");
    C_BarnLight.m_vPrecomputedOBBAngles1 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBAngles1");
    C_BarnLight.m_vPrecomputedOBBExtent1 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBExtent1");
    C_BarnLight.m_vPrecomputedOBBOrigin2 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBOrigin2");
    C_BarnLight.m_vPrecomputedOBBAngles2 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBAngles2");
    C_BarnLight.m_vPrecomputedOBBExtent2 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBExtent2");
    C_BarnLight.m_vPrecomputedOBBOrigin3 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBOrigin3");
    C_BarnLight.m_vPrecomputedOBBAngles3 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBAngles3");
    C_BarnLight.m_vPrecomputedOBBExtent3 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBExtent3");
    C_BarnLight.m_vPrecomputedOBBOrigin4 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBOrigin4");
    C_BarnLight.m_vPrecomputedOBBAngles4 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBAngles4");
    C_BarnLight.m_vPrecomputedOBBExtent4 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBExtent4");
    C_BarnLight.m_vPrecomputedOBBOrigin5 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBOrigin5");
    C_BarnLight.m_vPrecomputedOBBAngles5 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBAngles5");
    C_BarnLight.m_vPrecomputedOBBExtent5 = findOffsetByName(j, "C_BarnLight", "m_vPrecomputedOBBExtent5");
    C_BarnLight.m_bInitialBoneSetup = findOffsetByName(j, "C_BarnLight", "m_bInitialBoneSetup");
    C_BarnLight.m_VisClusters = findOffsetByName(j, "C_BarnLight", "m_VisClusters");

    // Atribuições para C_TonemapController2
    // C_TonemapController2 Offsets
    C_TonemapController2.m_flAutoExposureMin = findOffsetByName(j, "C_TonemapController2", "m_flAutoExposureMin");
    C_TonemapController2.m_flAutoExposureMax = findOffsetByName(j, "C_TonemapController2", "m_flAutoExposureMax");
    C_TonemapController2.m_flTonemapPercentTarget = findOffsetByName(j, "C_TonemapController2", "m_flTonemapPercentTarget");
    C_TonemapController2.m_flTonemapPercentBrightPixels = findOffsetByName(j, "C_TonemapController2", "m_flTonemapPercentBrightPixels");
    C_TonemapController2.m_flTonemapMinAvgLum = findOffsetByName(j, "C_TonemapController2", "m_flTonemapMinAvgLum");
    C_TonemapController2.m_flExposureAdaptationSpeedUp = findOffsetByName(j, "C_TonemapController2", "m_flExposureAdaptationSpeedUp");
    C_TonemapController2.m_flExposureAdaptationSpeedDown = findOffsetByName(j, "C_TonemapController2", "m_flExposureAdaptationSpeedDown");
    C_TonemapController2.m_flTonemapEVSmoothingRange = findOffsetByName(j, "C_TonemapController2", "m_flTonemapEVSmoothingRange");

    // Atribuições para CFuncWater
    // CFuncWater Offsets
    CFuncWater.m_BuoyancyHelper = findOffsetByName(j, "CFuncWater", "m_BuoyancyHelper");

    // Atribuições para C_EconEntity
    // C_EconEntity Offsets
    C_EconEntity.m_flFlexDelayTime = findOffsetByName(j, "C_EconEntity", "m_flFlexDelayTime");
    C_EconEntity.m_flFlexDelayedWeight = findOffsetByName(j, "C_EconEntity", "m_flFlexDelayedWeight");
    C_EconEntity.m_bAttributesInitialized = findOffsetByName(j, "C_EconEntity", "m_bAttributesInitialized");
    C_EconEntity.m_AttributeManager = findOffsetByName(j, "C_EconEntity", "m_AttributeManager");
    C_EconEntity.m_OriginalOwnerXuidLow = findOffsetByName(j, "C_EconEntity", "m_OriginalOwnerXuidLow");
    C_EconEntity.m_OriginalOwnerXuidHigh = findOffsetByName(j, "C_EconEntity", "m_OriginalOwnerXuidHigh");
    C_EconEntity.m_nFallbackPaintKit = findOffsetByName(j, "C_EconEntity", "m_nFallbackPaintKit");
    C_EconEntity.m_nFallbackSeed = findOffsetByName(j, "C_EconEntity", "m_nFallbackSeed");
    C_EconEntity.m_flFallbackWear = findOffsetByName(j, "C_EconEntity", "m_flFallbackWear");
    C_EconEntity.m_nFallbackStatTrak = findOffsetByName(j, "C_EconEntity", "m_nFallbackStatTrak");
    C_EconEntity.m_bClientside = findOffsetByName(j, "C_EconEntity", "m_bClientside");
    C_EconEntity.m_bParticleSystemsCreated = findOffsetByName(j, "C_EconEntity", "m_bParticleSystemsCreated");
    C_EconEntity.m_vecAttachedParticles = findOffsetByName(j, "C_EconEntity", "m_vecAttachedParticles");
    C_EconEntity.m_hViewmodelAttachment = findOffsetByName(j, "C_EconEntity", "m_hViewmodelAttachment");
    C_EconEntity.m_iOldTeam = findOffsetByName(j, "C_EconEntity", "m_iOldTeam");
    C_EconEntity.m_bAttachmentDirty = findOffsetByName(j, "C_EconEntity", "m_bAttachmentDirty");
    C_EconEntity.m_nUnloadedModelIndex = findOffsetByName(j, "C_EconEntity", "m_nUnloadedModelIndex");
    C_EconEntity.m_iNumOwnerValidationRetries = findOffsetByName(j, "C_EconEntity", "m_iNumOwnerValidationRetries");
    C_EconEntity.m_hOldProvidee = findOffsetByName(j, "C_EconEntity", "m_hOldProvidee");
    C_EconEntity.m_vecAttachedModels = findOffsetByName(j, "C_EconEntity", "m_vecAttachedModels");

    // Atribuições para C_RectLight
    // C_RectLight Offsets
    C_RectLight.m_bShowLight = findOffsetByName(j, "C_RectLight", "m_bShowLight");

    // Atribuições para C_ParticleSystem
    // C_ParticleSystem Offsets
    C_ParticleSystem.m_szSnapshotFileName = findOffsetByName(j, "C_ParticleSystem", "m_szSnapshotFileName");
    C_ParticleSystem.m_bActive = findOffsetByName(j, "C_ParticleSystem", "m_bActive");
    C_ParticleSystem.m_bFrozen = findOffsetByName(j, "C_ParticleSystem", "m_bFrozen");
    C_ParticleSystem.m_flFreezeTransitionDuration = findOffsetByName(j, "C_ParticleSystem", "m_flFreezeTransitionDuration");
    C_ParticleSystem.m_nStopType = findOffsetByName(j, "C_ParticleSystem", "m_nStopType");
    C_ParticleSystem.m_bAnimateDuringGameplayPause = findOffsetByName(j, "C_ParticleSystem", "m_bAnimateDuringGameplayPause");
    C_ParticleSystem.m_iEffectIndex = findOffsetByName(j, "C_ParticleSystem", "m_iEffectIndex");
    C_ParticleSystem.m_flStartTime = findOffsetByName(j, "C_ParticleSystem", "m_flStartTime");
    C_ParticleSystem.m_flPreSimTime = findOffsetByName(j, "C_ParticleSystem", "m_flPreSimTime");
    C_ParticleSystem.m_vServerControlPoints = findOffsetByName(j, "C_ParticleSystem", "m_vServerControlPoints");
    C_ParticleSystem.m_iServerControlPointAssignments = findOffsetByName(j, "C_ParticleSystem", "m_iServerControlPointAssignments");
    C_ParticleSystem.m_hControlPointEnts = findOffsetByName(j, "C_ParticleSystem", "m_hControlPointEnts");
    C_ParticleSystem.m_bNoSave = findOffsetByName(j, "C_ParticleSystem", "m_bNoSave");
    C_ParticleSystem.m_bNoFreeze = findOffsetByName(j, "C_ParticleSystem", "m_bNoFreeze");
    C_ParticleSystem.m_bNoRamp = findOffsetByName(j, "C_ParticleSystem", "m_bNoRamp");
    C_ParticleSystem.m_bStartActive = findOffsetByName(j, "C_ParticleSystem", "m_bStartActive");
    C_ParticleSystem.m_iszEffectName = findOffsetByName(j, "C_ParticleSystem", "m_iszEffectName");
    C_ParticleSystem.m_iszControlPointNames = findOffsetByName(j, "C_ParticleSystem", "m_iszControlPointNames");
    C_ParticleSystem.m_nDataCP = findOffsetByName(j, "C_ParticleSystem", "m_nDataCP");
    C_ParticleSystem.m_vecDataCPValue = findOffsetByName(j, "C_ParticleSystem", "m_vecDataCPValue");
    C_ParticleSystem.m_nTintCP = findOffsetByName(j, "C_ParticleSystem", "m_nTintCP");
    C_ParticleSystem.m_clrTint = findOffsetByName(j, "C_ParticleSystem", "m_clrTint");
    C_ParticleSystem.m_bOldActive = findOffsetByName(j, "C_ParticleSystem", "m_bOldActive");
    C_ParticleSystem.m_bOldFrozen = findOffsetByName(j, "C_ParticleSystem", "m_bOldFrozen");

    // Atribuições para C_CSGameRulesProxy
    // C_CSGameRulesProxy Offsets
    C_CSGameRulesProxy.m_pGameRules = findOffsetByName(j, "C_CSGameRulesProxy", "m_pGameRules");

    // Atribuições para CPlayer_ObserverServices
    // CPlayer_ObserverServices Offsets
    CPlayer_ObserverServices.m_iObserverMode = findOffsetByName(j, "CPlayer_ObserverServices", "m_iObserverMode");
    CPlayer_ObserverServices.m_hObserverTarget = findOffsetByName(j, "CPlayer_ObserverServices", "m_hObserverTarget");
    CPlayer_ObserverServices.m_iObserverLastMode = findOffsetByName(j, "CPlayer_ObserverServices", "m_iObserverLastMode");
    CPlayer_ObserverServices.m_bForcedObserverMode = findOffsetByName(j, "CPlayer_ObserverServices", "m_bForcedObserverMode");
    CPlayer_ObserverServices.m_flObserverChaseDistance = findOffsetByName(j, "CPlayer_ObserverServices", "m_flObserverChaseDistance");
    CPlayer_ObserverServices.m_flObserverChaseDistanceCalcTime = findOffsetByName(j, "CPlayer_ObserverServices", "m_flObserverChaseDistanceCalcTime");

    // Atribuições para SequenceHistory_t
    // SequenceHistory_t Offsets
    SequenceHistory_t.m_hSequence = findOffsetByName(j, "SequenceHistory_t", "m_hSequence");
    SequenceHistory_t.m_flSeqStartTime = findOffsetByName(j, "SequenceHistory_t", "m_flSeqStartTime");
    SequenceHistory_t.m_flSeqFixedCycle = findOffsetByName(j, "SequenceHistory_t", "m_flSeqFixedCycle");
    SequenceHistory_t.m_nSeqLoopMode = findOffsetByName(j, "SequenceHistory_t", "m_nSeqLoopMode");
    SequenceHistory_t.m_flPlaybackRate = findOffsetByName(j, "SequenceHistory_t", "m_flPlaybackRate");
    SequenceHistory_t.m_flCyclesPerSecond = findOffsetByName(j, "SequenceHistory_t", "m_flCyclesPerSecond");

    // Atribuições para C_Multimeter
    // C_Multimeter Offsets
    C_Multimeter.m_hTargetC4 = findOffsetByName(j, "C_Multimeter", "m_hTargetC4");

    // Atribuições para C_CsmFovOverride
    // C_CsmFovOverride Offsets
    C_CsmFovOverride.m_cameraName = findOffsetByName(j, "C_CsmFovOverride", "m_cameraName");
    C_CsmFovOverride.m_flCsmFovOverrideValue = findOffsetByName(j, "C_CsmFovOverride", "m_flCsmFovOverrideValue");

    // Atribuições para C_EnvDecal
    // C_EnvDecal Offsets
    C_EnvDecal.m_hDecalMaterial = findOffsetByName(j, "C_EnvDecal", "m_hDecalMaterial");
    C_EnvDecal.m_flWidth = findOffsetByName(j, "C_EnvDecal", "m_flWidth");
    C_EnvDecal.m_flHeight = findOffsetByName(j, "C_EnvDecal", "m_flHeight");
    C_EnvDecal.m_flDepth = findOffsetByName(j, "C_EnvDecal", "m_flDepth");
    C_EnvDecal.m_nRenderOrder = findOffsetByName(j, "C_EnvDecal", "m_nRenderOrder");
    C_EnvDecal.m_bProjectOnWorld = findOffsetByName(j, "C_EnvDecal", "m_bProjectOnWorld");
    C_EnvDecal.m_bProjectOnCharacters = findOffsetByName(j, "C_EnvDecal", "m_bProjectOnCharacters");
    C_EnvDecal.m_bProjectOnWater = findOffsetByName(j, "C_EnvDecal", "m_bProjectOnWater");
    C_EnvDecal.m_flDepthSortBias = findOffsetByName(j, "C_EnvDecal", "m_flDepthSortBias");

    // Atribuições para C_ColorCorrection
    // C_ColorCorrection Offsets
    C_ColorCorrection.m_vecOrigin = findOffsetByName(j, "C_ColorCorrection", "m_vecOrigin");
    C_ColorCorrection.m_MinFalloff = findOffsetByName(j, "C_ColorCorrection", "m_MinFalloff");
    C_ColorCorrection.m_MaxFalloff = findOffsetByName(j, "C_ColorCorrection", "m_MaxFalloff");
    C_ColorCorrection.m_flFadeInDuration = findOffsetByName(j, "C_ColorCorrection", "m_flFadeInDuration");
    C_ColorCorrection.m_flFadeOutDuration = findOffsetByName(j, "C_ColorCorrection", "m_flFadeOutDuration");
    C_ColorCorrection.m_flMaxWeight = findOffsetByName(j, "C_ColorCorrection", "m_flMaxWeight");
    C_ColorCorrection.m_flCurWeight = findOffsetByName(j, "C_ColorCorrection", "m_flCurWeight");
    C_ColorCorrection.m_netlookupFilename = findOffsetByName(j, "C_ColorCorrection", "m_netlookupFilename");
    C_ColorCorrection.m_bEnabled = findOffsetByName(j, "C_ColorCorrection", "m_bEnabled");
    C_ColorCorrection.m_bMaster = findOffsetByName(j, "C_ColorCorrection", "m_bMaster");
    C_ColorCorrection.m_bClientSide = findOffsetByName(j, "C_ColorCorrection", "m_bClientSide");
    C_ColorCorrection.m_bExclusive = findOffsetByName(j, "C_ColorCorrection", "m_bExclusive");
    C_ColorCorrection.m_bEnabledOnClient = findOffsetByName(j, "C_ColorCorrection", "m_bEnabledOnClient");
    C_ColorCorrection.m_flCurWeightOnClient = findOffsetByName(j, "C_ColorCorrection", "m_flCurWeightOnClient");
    C_ColorCorrection.m_bFadingIn = findOffsetByName(j, "C_ColorCorrection", "m_bFadingIn");
    C_ColorCorrection.m_flFadeStartWeight = findOffsetByName(j, "C_ColorCorrection", "m_flFadeStartWeight");
    C_ColorCorrection.m_flFadeStartTime = findOffsetByName(j, "C_ColorCorrection", "m_flFadeStartTime");
    C_ColorCorrection.m_flFadeDuration = findOffsetByName(j, "C_ColorCorrection", "m_flFadeDuration");

    // Atribuições para CModelState
    // CModelState Offsets
    CModelState.m_hModel = findOffsetByName(j, "CModelState", "m_hModel");
    CModelState.m_ModelName = findOffsetByName(j, "CModelState", "m_ModelName");
    CModelState.m_bClientClothCreationSuppressed = findOffsetByName(j, "CModelState", "m_bClientClothCreationSuppressed");
    CModelState.m_MeshGroupMask = findOffsetByName(j, "CModelState", "m_MeshGroupMask");
    CModelState.m_nIdealMotionType = findOffsetByName(j, "CModelState", "m_nIdealMotionType");
    CModelState.m_nForceLOD = findOffsetByName(j, "CModelState", "m_nForceLOD");
    CModelState.m_nClothUpdateFlags = findOffsetByName(j, "CModelState", "m_nClothUpdateFlags");

    // Atribuições para C_EconEntity__AttachedModelData_t
    // C_EconEntity__AttachedModelData_t Offsets
    C_EconEntity__AttachedModelData_t.m_iModelDisplayFlags = findOffsetByName(j, "C_EconEntity__AttachedModelData_t", "m_iModelDisplayFlags");

    // Atribuições para CAttributeList
    // CAttributeList Offsets
    CAttributeList.m_Attributes = findOffsetByName(j, "CAttributeList", "m_Attributes");
    CAttributeList.m_pManager = findOffsetByName(j, "CAttributeList", "m_pManager");

    // Atribuições para C_BaseDoor
    // C_BaseDoor Offsets
    C_BaseDoor.m_bIsUsable = findOffsetByName(j, "C_BaseDoor", "m_bIsUsable");

    // Atribuições para CGrenadeTracer
    // CGrenadeTracer Offsets
    CGrenadeTracer.m_flTracerDuration = findOffsetByName(j, "CGrenadeTracer", "m_flTracerDuration");
    CGrenadeTracer.m_nType = findOffsetByName(j, "CGrenadeTracer", "m_nType");

    // Atribuições para CBombTarget
    // CBombTarget Offsets
    CBombTarget.m_bBombPlantedHere = findOffsetByName(j, "CBombTarget", "m_bBombPlantedHere");

    // Atribuições para C_PointClientUIDialog
    // C_PointClientUIDialog Offsets
    C_PointClientUIDialog.m_hActivator = findOffsetByName(j, "C_PointClientUIDialog", "m_hActivator");
    C_PointClientUIDialog.m_bStartEnabled = findOffsetByName(j, "C_PointClientUIDialog", "m_bStartEnabled");

    // Atribuições para CCSGameModeRules_ArmsRace
    // CCSGameModeRules_ArmsRace Offsets
    CCSGameModeRules_ArmsRace.m_WeaponSequence = findOffsetByName(j, "CCSGameModeRules_ArmsRace", "m_WeaponSequence");

    // Atribuições para CPointChildModifier
    // CPointChildModifier Offsets
    CPointChildModifier.m_bOrphanInsteadOfDeletingChildrenOnRemove = findOffsetByName(j, "CPointChildModifier", "m_bOrphanInsteadOfDeletingChildrenOnRemove");

    // Atribuições para CDamageRecord
    // CDamageRecord Offsets
    CDamageRecord.m_PlayerDamager = findOffsetByName(j, "CDamageRecord", "m_PlayerDamager");
    CDamageRecord.m_PlayerRecipient = findOffsetByName(j, "CDamageRecord", "m_PlayerRecipient");
    CDamageRecord.m_hPlayerControllerDamager = findOffsetByName(j, "CDamageRecord", "m_hPlayerControllerDamager");
    CDamageRecord.m_hPlayerControllerRecipient = findOffsetByName(j, "CDamageRecord", "m_hPlayerControllerRecipient");
    CDamageRecord.m_szPlayerDamagerName = findOffsetByName(j, "CDamageRecord", "m_szPlayerDamagerName");
    CDamageRecord.m_szPlayerRecipientName = findOffsetByName(j, "CDamageRecord", "m_szPlayerRecipientName");
    CDamageRecord.m_DamagerXuid = findOffsetByName(j, "CDamageRecord", "m_DamagerXuid");
    CDamageRecord.m_RecipientXuid = findOffsetByName(j, "CDamageRecord", "m_RecipientXuid");
    CDamageRecord.m_iBulletsDamage = findOffsetByName(j, "CDamageRecord", "m_iBulletsDamage");
    CDamageRecord.m_iDamage = findOffsetByName(j, "CDamageRecord", "m_iDamage");
    CDamageRecord.m_iActualHealthRemoved = findOffsetByName(j, "CDamageRecord", "m_iActualHealthRemoved");
    CDamageRecord.m_iNumHits = findOffsetByName(j, "CDamageRecord", "m_iNumHits");
    CDamageRecord.m_iLastBulletUpdate = findOffsetByName(j, "CDamageRecord", "m_iLastBulletUpdate");
    CDamageRecord.m_bIsOtherEnemy = findOffsetByName(j, "CDamageRecord", "m_bIsOtherEnemy");
    CDamageRecord.m_killType = findOffsetByName(j, "CDamageRecord", "m_killType");

    // Atribuições para CCSPlayerController_DamageServices
    // CCSPlayerController_DamageServices Offsets
    CCSPlayerController_DamageServices.m_nSendUpdate = findOffsetByName(j, "CCSPlayerController_DamageServices", "m_nSendUpdate");
    CCSPlayerController_DamageServices.m_DamageList = findOffsetByName(j, "CCSPlayerController_DamageServices", "m_DamageList");

    // Atribuições para CRenderComponent
    // CRenderComponent Offsets
    CRenderComponent.__m_pChainEntity = findOffsetByName(j, "CRenderComponent", "__m_pChainEntity");
    CRenderComponent.m_bIsRenderingWithViewModels = findOffsetByName(j, "CRenderComponent", "m_bIsRenderingWithViewModels");
    CRenderComponent.m_nSplitscreenFlags = findOffsetByName(j, "CRenderComponent", "m_nSplitscreenFlags");
    CRenderComponent.m_bEnableRendering = findOffsetByName(j, "CRenderComponent", "m_bEnableRendering");
    CRenderComponent.m_bInterpolationReadyToDraw = findOffsetByName(j, "CRenderComponent", "m_bInterpolationReadyToDraw");

    // Atribuições para C_SoundEventOBBEntity
    // C_SoundEventOBBEntity Offsets
    C_SoundEventOBBEntity.m_vMins = findOffsetByName(j, "C_SoundEventOBBEntity", "m_vMins");
    C_SoundEventOBBEntity.m_vMaxs = findOffsetByName(j, "C_SoundEventOBBEntity", "m_vMaxs");

    // Atribuições para CLightComponent
    // CLightComponent Offsets
    CLightComponent.__m_pChainEntity = findOffsetByName(j, "CLightComponent", "__m_pChainEntity");
    CLightComponent.m_Color = findOffsetByName(j, "CLightComponent", "m_Color");
    CLightComponent.m_SecondaryColor = findOffsetByName(j, "CLightComponent", "m_SecondaryColor");
    CLightComponent.m_flBrightness = findOffsetByName(j, "CLightComponent", "m_flBrightness");
    CLightComponent.m_flBrightnessScale = findOffsetByName(j, "CLightComponent", "m_flBrightnessScale");
    CLightComponent.m_flBrightnessMult = findOffsetByName(j, "CLightComponent", "m_flBrightnessMult");
    CLightComponent.m_flRange = findOffsetByName(j, "CLightComponent", "m_flRange");
    CLightComponent.m_flFalloff = findOffsetByName(j, "CLightComponent", "m_flFalloff");
    CLightComponent.m_flAttenuation0 = findOffsetByName(j, "CLightComponent", "m_flAttenuation0");
    CLightComponent.m_flAttenuation1 = findOffsetByName(j, "CLightComponent", "m_flAttenuation1");
    CLightComponent.m_flAttenuation2 = findOffsetByName(j, "CLightComponent", "m_flAttenuation2");
    CLightComponent.m_flTheta = findOffsetByName(j, "CLightComponent", "m_flTheta");
    CLightComponent.m_flPhi = findOffsetByName(j, "CLightComponent", "m_flPhi");
    CLightComponent.m_hLightCookie = findOffsetByName(j, "CLightComponent", "m_hLightCookie");
    CLightComponent.m_nCascades = findOffsetByName(j, "CLightComponent", "m_nCascades");
    CLightComponent.m_nCastShadows = findOffsetByName(j, "CLightComponent", "m_nCastShadows");
    CLightComponent.m_nShadowWidth = findOffsetByName(j, "CLightComponent", "m_nShadowWidth");
    CLightComponent.m_nShadowHeight = findOffsetByName(j, "CLightComponent", "m_nShadowHeight");
    CLightComponent.m_bRenderDiffuse = findOffsetByName(j, "CLightComponent", "m_bRenderDiffuse");
    CLightComponent.m_nRenderSpecular = findOffsetByName(j, "CLightComponent", "m_nRenderSpecular");
    CLightComponent.m_bRenderTransmissive = findOffsetByName(j, "CLightComponent", "m_bRenderTransmissive");
    CLightComponent.m_flOrthoLightWidth = findOffsetByName(j, "CLightComponent", "m_flOrthoLightWidth");
    CLightComponent.m_flOrthoLightHeight = findOffsetByName(j, "CLightComponent", "m_flOrthoLightHeight");
    CLightComponent.m_nStyle = findOffsetByName(j, "CLightComponent", "m_nStyle");
    CLightComponent.m_Pattern = findOffsetByName(j, "CLightComponent", "m_Pattern");
    CLightComponent.m_nCascadeRenderStaticObjects = findOffsetByName(j, "CLightComponent", "m_nCascadeRenderStaticObjects");
    CLightComponent.m_flShadowCascadeCrossFade = findOffsetByName(j, "CLightComponent", "m_flShadowCascadeCrossFade");
    CLightComponent.m_flShadowCascadeDistanceFade = findOffsetByName(j, "CLightComponent", "m_flShadowCascadeDistanceFade");
    CLightComponent.m_flShadowCascadeDistance0 = findOffsetByName(j, "CLightComponent", "m_flShadowCascadeDistance0");
    CLightComponent.m_flShadowCascadeDistance1 = findOffsetByName(j, "CLightComponent", "m_flShadowCascadeDistance1");
    CLightComponent.m_flShadowCascadeDistance2 = findOffsetByName(j, "CLightComponent", "m_flShadowCascadeDistance2");
    CLightComponent.m_flShadowCascadeDistance3 = findOffsetByName(j, "CLightComponent", "m_flShadowCascadeDistance3");
    CLightComponent.m_nShadowCascadeResolution0 = findOffsetByName(j, "CLightComponent", "m_nShadowCascadeResolution0");
    CLightComponent.m_nShadowCascadeResolution1 = findOffsetByName(j, "CLightComponent", "m_nShadowCascadeResolution1");
    CLightComponent.m_nShadowCascadeResolution2 = findOffsetByName(j, "CLightComponent", "m_nShadowCascadeResolution2");
    CLightComponent.m_nShadowCascadeResolution3 = findOffsetByName(j, "CLightComponent", "m_nShadowCascadeResolution3");
    CLightComponent.m_bUsesBakedShadowing = findOffsetByName(j, "CLightComponent", "m_bUsesBakedShadowing");
    CLightComponent.m_nShadowPriority = findOffsetByName(j, "CLightComponent", "m_nShadowPriority");
    CLightComponent.m_nBakedShadowIndex = findOffsetByName(j, "CLightComponent", "m_nBakedShadowIndex");
    CLightComponent.m_bRenderToCubemaps = findOffsetByName(j, "CLightComponent", "m_bRenderToCubemaps");
    CLightComponent.m_nDirectLight = findOffsetByName(j, "CLightComponent", "m_nDirectLight");
    CLightComponent.m_nIndirectLight = findOffsetByName(j, "CLightComponent", "m_nIndirectLight");
    CLightComponent.m_flFadeMinDist = findOffsetByName(j, "CLightComponent", "m_flFadeMinDist");
    CLightComponent.m_flFadeMaxDist = findOffsetByName(j, "CLightComponent", "m_flFadeMaxDist");
    CLightComponent.m_flShadowFadeMinDist = findOffsetByName(j, "CLightComponent", "m_flShadowFadeMinDist");
    CLightComponent.m_flShadowFadeMaxDist = findOffsetByName(j, "CLightComponent", "m_flShadowFadeMaxDist");
    CLightComponent.m_bEnabled = findOffsetByName(j, "CLightComponent", "m_bEnabled");
    CLightComponent.m_bFlicker = findOffsetByName(j, "CLightComponent", "m_bFlicker");
    CLightComponent.m_bPrecomputedFieldsValid = findOffsetByName(j, "CLightComponent", "m_bPrecomputedFieldsValid");
    CLightComponent.m_vPrecomputedBoundsMins = findOffsetByName(j, "CLightComponent", "m_vPrecomputedBoundsMins");
    CLightComponent.m_vPrecomputedBoundsMaxs = findOffsetByName(j, "CLightComponent", "m_vPrecomputedBoundsMaxs");
    CLightComponent.m_vPrecomputedOBBOrigin = findOffsetByName(j, "CLightComponent", "m_vPrecomputedOBBOrigin");
    CLightComponent.m_vPrecomputedOBBAngles = findOffsetByName(j, "CLightComponent", "m_vPrecomputedOBBAngles");
    CLightComponent.m_vPrecomputedOBBExtent = findOffsetByName(j, "CLightComponent", "m_vPrecomputedOBBExtent");
    CLightComponent.m_flPrecomputedMaxRange = findOffsetByName(j, "CLightComponent", "m_flPrecomputedMaxRange");
    CLightComponent.m_nFogLightingMode = findOffsetByName(j, "CLightComponent", "m_nFogLightingMode");
    CLightComponent.m_flFogContributionStength = findOffsetByName(j, "CLightComponent", "m_flFogContributionStength");
    CLightComponent.m_flNearClipPlane = findOffsetByName(j, "CLightComponent", "m_flNearClipPlane");
    CLightComponent.m_SkyColor = findOffsetByName(j, "CLightComponent", "m_SkyColor");
    CLightComponent.m_flSkyIntensity = findOffsetByName(j, "CLightComponent", "m_flSkyIntensity");
    CLightComponent.m_SkyAmbientBounce = findOffsetByName(j, "CLightComponent", "m_SkyAmbientBounce");
    CLightComponent.m_bUseSecondaryColor = findOffsetByName(j, "CLightComponent", "m_bUseSecondaryColor");
    CLightComponent.m_bMixedShadows = findOffsetByName(j, "CLightComponent", "m_bMixedShadows");
    CLightComponent.m_flLightStyleStartTime = findOffsetByName(j, "CLightComponent", "m_flLightStyleStartTime");
    CLightComponent.m_flCapsuleLength = findOffsetByName(j, "CLightComponent", "m_flCapsuleLength");
    CLightComponent.m_flMinRoughness = findOffsetByName(j, "CLightComponent", "m_flMinRoughness");

    // Atribuições para C_EconItemView
    // C_EconItemView Offsets
    C_EconItemView.m_bInventoryImageRgbaRequested = findOffsetByName(j, "C_EconItemView", "m_bInventoryImageRgbaRequested");
    C_EconItemView.m_bInventoryImageTriedCache = findOffsetByName(j, "C_EconItemView", "m_bInventoryImageTriedCache");
    C_EconItemView.m_nInventoryImageRgbaWidth = findOffsetByName(j, "C_EconItemView", "m_nInventoryImageRgbaWidth");
    C_EconItemView.m_nInventoryImageRgbaHeight = findOffsetByName(j, "C_EconItemView", "m_nInventoryImageRgbaHeight");
    C_EconItemView.m_szCurrentLoadCachedFileName = findOffsetByName(j, "C_EconItemView", "m_szCurrentLoadCachedFileName");
    C_EconItemView.m_bRestoreCustomMaterialAfterPrecache = findOffsetByName(j, "C_EconItemView", "m_bRestoreCustomMaterialAfterPrecache");
    C_EconItemView.m_iItemDefinitionIndex = findOffsetByName(j, "C_EconItemView", "m_iItemDefinitionIndex");
    C_EconItemView.m_iEntityQuality = findOffsetByName(j, "C_EconItemView", "m_iEntityQuality");
    C_EconItemView.m_iEntityLevel = findOffsetByName(j, "C_EconItemView", "m_iEntityLevel");
    C_EconItemView.m_iItemID = findOffsetByName(j, "C_EconItemView", "m_iItemID");
    C_EconItemView.m_iItemIDHigh = findOffsetByName(j, "C_EconItemView", "m_iItemIDHigh");
    C_EconItemView.m_iItemIDLow = findOffsetByName(j, "C_EconItemView", "m_iItemIDLow");
    C_EconItemView.m_iAccountID = findOffsetByName(j, "C_EconItemView", "m_iAccountID");
    C_EconItemView.m_iInventoryPosition = findOffsetByName(j, "C_EconItemView", "m_iInventoryPosition");
    C_EconItemView.m_bInitialized = findOffsetByName(j, "C_EconItemView", "m_bInitialized");
    C_EconItemView.m_bDisallowSOC = findOffsetByName(j, "C_EconItemView", "m_bDisallowSOC");
    C_EconItemView.m_bIsStoreItem = findOffsetByName(j, "C_EconItemView", "m_bIsStoreItem");
    C_EconItemView.m_bIsTradeItem = findOffsetByName(j, "C_EconItemView", "m_bIsTradeItem");
    C_EconItemView.m_iEntityQuantity = findOffsetByName(j, "C_EconItemView", "m_iEntityQuantity");
    C_EconItemView.m_iRarityOverride = findOffsetByName(j, "C_EconItemView", "m_iRarityOverride");
    C_EconItemView.m_iQualityOverride = findOffsetByName(j, "C_EconItemView", "m_iQualityOverride");
    C_EconItemView.m_iOriginOverride = findOffsetByName(j, "C_EconItemView", "m_iOriginOverride");
    C_EconItemView.m_unClientFlags = findOffsetByName(j, "C_EconItemView", "m_unClientFlags");
    C_EconItemView.m_unOverrideStyle = findOffsetByName(j, "C_EconItemView", "m_unOverrideStyle");
    C_EconItemView.m_AttributeList = findOffsetByName(j, "C_EconItemView", "m_AttributeList");
    C_EconItemView.m_NetworkedDynamicAttributes = findOffsetByName(j, "C_EconItemView", "m_NetworkedDynamicAttributes");
    C_EconItemView.m_szCustomName = findOffsetByName(j, "C_EconItemView", "m_szCustomName");
    C_EconItemView.m_szCustomNameOverride = findOffsetByName(j, "C_EconItemView", "m_szCustomNameOverride");
    C_EconItemView.m_bInitializedTags = findOffsetByName(j, "C_EconItemView", "m_bInitializedTags");

    // Atribuições para C_HandleTest
    // C_HandleTest Offsets
    C_HandleTest.m_Handle = findOffsetByName(j, "C_HandleTest", "m_Handle");
    C_HandleTest.m_bSendHandle = findOffsetByName(j, "C_HandleTest", "m_bSendHandle");

    // Atribuições para C_EnvWindClientside
    // C_EnvWindClientside Offsets
    C_EnvWindClientside.m_EnvWindShared = findOffsetByName(j, "C_EnvWindClientside", "m_EnvWindShared");

    // Atribuições para C_WeaponShield
    // C_WeaponShield Offsets
    C_WeaponShield.m_flDisplayHealth = findOffsetByName(j, "C_WeaponShield", "m_flDisplayHealth");

    // Atribuições para C_PointClientUIWorldTextPanel
    // C_PointClientUIWorldTextPanel Offsets
    C_PointClientUIWorldTextPanel.m_messageText = findOffsetByName(j, "C_PointClientUIWorldTextPanel", "m_messageText");

    // Atribuições para CPlayer_MovementServices
    // CPlayer_MovementServices Offsets
    CPlayer_MovementServices.m_nImpulse = findOffsetByName(j, "CPlayer_MovementServices", "m_nImpulse");
    CPlayer_MovementServices.m_nButtons = findOffsetByName(j, "CPlayer_MovementServices", "m_nButtons");
    CPlayer_MovementServices.m_nQueuedButtonDownMask = findOffsetByName(j, "CPlayer_MovementServices", "m_nQueuedButtonDownMask");
    CPlayer_MovementServices.m_nQueuedButtonChangeMask = findOffsetByName(j, "CPlayer_MovementServices", "m_nQueuedButtonChangeMask");
    CPlayer_MovementServices.m_nButtonDoublePressed = findOffsetByName(j, "CPlayer_MovementServices", "m_nButtonDoublePressed");
    CPlayer_MovementServices.m_pButtonPressedCmdNumber = findOffsetByName(j, "CPlayer_MovementServices", "m_pButtonPressedCmdNumber");
    CPlayer_MovementServices.m_nLastCommandNumberProcessed = findOffsetByName(j, "CPlayer_MovementServices", "m_nLastCommandNumberProcessed");
    CPlayer_MovementServices.m_nToggleButtonDownMask = findOffsetByName(j, "CPlayer_MovementServices", "m_nToggleButtonDownMask");
    CPlayer_MovementServices.m_flMaxspeed = findOffsetByName(j, "CPlayer_MovementServices", "m_flMaxspeed");
    CPlayer_MovementServices.m_arrForceSubtickMoveWhen = findOffsetByName(j, "CPlayer_MovementServices", "m_arrForceSubtickMoveWhen");
    CPlayer_MovementServices.m_flForwardMove = findOffsetByName(j, "CPlayer_MovementServices", "m_flForwardMove");
    CPlayer_MovementServices.m_flLeftMove = findOffsetByName(j, "CPlayer_MovementServices", "m_flLeftMove");
    CPlayer_MovementServices.m_flUpMove = findOffsetByName(j, "CPlayer_MovementServices", "m_flUpMove");
    CPlayer_MovementServices.m_vecLastMovementImpulses = findOffsetByName(j, "CPlayer_MovementServices", "m_vecLastMovementImpulses");
    CPlayer_MovementServices.m_vecOldViewAngles = findOffsetByName(j, "CPlayer_MovementServices", "m_vecOldViewAngles");

    // Atribuições para CBasePlayerVData
    // CBasePlayerVData Offsets
    CBasePlayerVData.m_sModelName = findOffsetByName(j, "CBasePlayerVData", "m_sModelName");
    CBasePlayerVData.m_flHeadDamageMultiplier = findOffsetByName(j, "CBasePlayerVData", "m_flHeadDamageMultiplier");
    CBasePlayerVData.m_flChestDamageMultiplier = findOffsetByName(j, "CBasePlayerVData", "m_flChestDamageMultiplier");
    CBasePlayerVData.m_flStomachDamageMultiplier = findOffsetByName(j, "CBasePlayerVData", "m_flStomachDamageMultiplier");
    CBasePlayerVData.m_flArmDamageMultiplier = findOffsetByName(j, "CBasePlayerVData", "m_flArmDamageMultiplier");
    CBasePlayerVData.m_flLegDamageMultiplier = findOffsetByName(j, "CBasePlayerVData", "m_flLegDamageMultiplier");
    CBasePlayerVData.m_flHoldBreathTime = findOffsetByName(j, "CBasePlayerVData", "m_flHoldBreathTime");
    CBasePlayerVData.m_flDrowningDamageInterval = findOffsetByName(j, "CBasePlayerVData", "m_flDrowningDamageInterval");
    CBasePlayerVData.m_nDrowningDamageInitial = findOffsetByName(j, "CBasePlayerVData", "m_nDrowningDamageInitial");
    CBasePlayerVData.m_nDrowningDamageMax = findOffsetByName(j, "CBasePlayerVData", "m_nDrowningDamageMax");
    CBasePlayerVData.m_nWaterSpeed = findOffsetByName(j, "CBasePlayerVData", "m_nWaterSpeed");
    CBasePlayerVData.m_flUseRange = findOffsetByName(j, "CBasePlayerVData", "m_flUseRange");
    CBasePlayerVData.m_flUseAngleTolerance = findOffsetByName(j, "CBasePlayerVData", "m_flUseAngleTolerance");
    CBasePlayerVData.m_flCrouchTime = findOffsetByName(j, "CBasePlayerVData", "m_flCrouchTime");

    // Atribuições para CCSPlayerController_InGameMoneyServices
    // CCSPlayerController_InGameMoneyServices Offsets
    CCSPlayerController_InGameMoneyServices.m_iAccount = findOffsetByName(j, "CCSPlayerController_InGameMoneyServices", "m_iAccount");
    CCSPlayerController_InGameMoneyServices.m_iStartAccount = findOffsetByName(j, "CCSPlayerController_InGameMoneyServices", "m_iStartAccount");
    CCSPlayerController_InGameMoneyServices.m_iTotalCashSpent = findOffsetByName(j, "CCSPlayerController_InGameMoneyServices", "m_iTotalCashSpent");
    CCSPlayerController_InGameMoneyServices.m_iCashSpentThisRound = findOffsetByName(j, "CCSPlayerController_InGameMoneyServices", "m_iCashSpentThisRound");

    // Atribuições para C_EnvWindShared__WindVariationEvent_t
    // C_EnvWindShared__WindVariationEvent_t Offsets
    C_EnvWindShared__WindVariationEvent_t.m_flWindAngleVariation = findOffsetByName(j, "C_EnvWindShared__WindVariationEvent_t", "m_flWindAngleVariation");
    C_EnvWindShared__WindVariationEvent_t.m_flWindSpeedVariation = findOffsetByName(j, "C_EnvWindShared__WindVariationEvent_t", "m_flWindSpeedVariation");

    // Atribuições para C_EnvParticleGlow
    // C_EnvParticleGlow Offsets
    C_EnvParticleGlow.m_flAlphaScale = findOffsetByName(j, "C_EnvParticleGlow", "m_flAlphaScale");
    C_EnvParticleGlow.m_flRadiusScale = findOffsetByName(j, "C_EnvParticleGlow", "m_flRadiusScale");
    C_EnvParticleGlow.m_flSelfIllumScale = findOffsetByName(j, "C_EnvParticleGlow", "m_flSelfIllumScale");
    C_EnvParticleGlow.m_ColorTint = findOffsetByName(j, "C_EnvParticleGlow", "m_ColorTint");
    C_EnvParticleGlow.m_hTextureOverride = findOffsetByName(j, "C_EnvParticleGlow", "m_hTextureOverride");

    // Atribuições para C_SoundEventEntity
    // C_SoundEventEntity Offsets
    C_SoundEventEntity.m_bStartOnSpawn = findOffsetByName(j, "C_SoundEventEntity", "m_bStartOnSpawn");
    C_SoundEventEntity.m_bToLocalPlayer = findOffsetByName(j, "C_SoundEventEntity", "m_bToLocalPlayer");
    C_SoundEventEntity.m_bStopOnNew = findOffsetByName(j, "C_SoundEventEntity", "m_bStopOnNew");
    C_SoundEventEntity.m_bSaveRestore = findOffsetByName(j, "C_SoundEventEntity", "m_bSaveRestore");
    C_SoundEventEntity.m_bSavedIsPlaying = findOffsetByName(j, "C_SoundEventEntity", "m_bSavedIsPlaying");
    C_SoundEventEntity.m_flSavedElapsedTime = findOffsetByName(j, "C_SoundEventEntity", "m_flSavedElapsedTime");
    C_SoundEventEntity.m_iszSourceEntityName = findOffsetByName(j, "C_SoundEventEntity", "m_iszSourceEntityName");
    C_SoundEventEntity.m_iszAttachmentName = findOffsetByName(j, "C_SoundEventEntity", "m_iszAttachmentName");
    C_SoundEventEntity.m_onGUIDChanged = findOffsetByName(j, "C_SoundEventEntity", "m_onGUIDChanged");
    C_SoundEventEntity.m_onSoundFinished = findOffsetByName(j, "C_SoundEventEntity", "m_onSoundFinished");
    C_SoundEventEntity.m_flClientCullRadius = findOffsetByName(j, "C_SoundEventEntity", "m_flClientCullRadius");
    C_SoundEventEntity.m_iszSoundName = findOffsetByName(j, "C_SoundEventEntity", "m_iszSoundName");
    C_SoundEventEntity.m_hSource = findOffsetByName(j, "C_SoundEventEntity", "m_hSource");
    C_SoundEventEntity.m_nEntityIndexSelection = findOffsetByName(j, "C_SoundEventEntity", "m_nEntityIndexSelection");
    C_SoundEventEntity.m_bClientSideOnly = findOffsetByName(j, "C_SoundEventEntity", "m_bClientSideOnly");

    // Atribuições para C_Sun
    // C_Sun Offsets
    C_Sun.m_fxSSSunFlareEffectIndex = findOffsetByName(j, "C_Sun", "m_fxSSSunFlareEffectIndex");
    C_Sun.m_fxSunFlareEffectIndex = findOffsetByName(j, "C_Sun", "m_fxSunFlareEffectIndex");
    C_Sun.m_fdistNormalize = findOffsetByName(j, "C_Sun", "m_fdistNormalize");
    C_Sun.m_vSunPos = findOffsetByName(j, "C_Sun", "m_vSunPos");
    C_Sun.m_vDirection = findOffsetByName(j, "C_Sun", "m_vDirection");
    C_Sun.m_iszEffectName = findOffsetByName(j, "C_Sun", "m_iszEffectName");
    C_Sun.m_iszSSEffectName = findOffsetByName(j, "C_Sun", "m_iszSSEffectName");
    C_Sun.m_clrOverlay = findOffsetByName(j, "C_Sun", "m_clrOverlay");
    C_Sun.m_bOn = findOffsetByName(j, "C_Sun", "m_bOn");
    C_Sun.m_bmaxColor = findOffsetByName(j, "C_Sun", "m_bmaxColor");
    C_Sun.m_flSize = findOffsetByName(j, "C_Sun", "m_flSize");
    C_Sun.m_flHazeScale = findOffsetByName(j, "C_Sun", "m_flHazeScale");
    C_Sun.m_flRotation = findOffsetByName(j, "C_Sun", "m_flRotation");
    C_Sun.m_flHDRColorScale = findOffsetByName(j, "C_Sun", "m_flHDRColorScale");
    C_Sun.m_flAlphaHaze = findOffsetByName(j, "C_Sun", "m_flAlphaHaze");
    C_Sun.m_flAlphaScale = findOffsetByName(j, "C_Sun", "m_flAlphaScale");
    C_Sun.m_flAlphaHdr = findOffsetByName(j, "C_Sun", "m_flAlphaHdr");
    C_Sun.m_flFarZScale = findOffsetByName(j, "C_Sun", "m_flFarZScale");

    // Atribuições para CCSPlayerController_ActionTrackingServices
    // CCSPlayerController_ActionTrackingServices Offsets
    CCSPlayerController_ActionTrackingServices.m_perRoundStats = findOffsetByName(j, "CCSPlayerController_ActionTrackingServices", "m_perRoundStats");
    CCSPlayerController_ActionTrackingServices.m_matchStats = findOffsetByName(j, "CCSPlayerController_ActionTrackingServices", "m_matchStats");
    CCSPlayerController_ActionTrackingServices.m_iNumRoundKills = findOffsetByName(j, "CCSPlayerController_ActionTrackingServices", "m_iNumRoundKills");
    CCSPlayerController_ActionTrackingServices.m_iNumRoundKillsHeadshots = findOffsetByName(j, "CCSPlayerController_ActionTrackingServices", "m_iNumRoundKillsHeadshots");
    CCSPlayerController_ActionTrackingServices.m_unTotalRoundDamageDealt = findOffsetByName(j, "CCSPlayerController_ActionTrackingServices", "m_unTotalRoundDamageDealt");

    // Atribuições para CHitboxComponent
    // CHitboxComponent Offsets
    CHitboxComponent.m_bvDisabledHitGroups = findOffsetByName(j, "CHitboxComponent", "m_bvDisabledHitGroups");

    // Atribuições para C_ColorCorrectionVolume
    // C_ColorCorrectionVolume Offsets
    C_ColorCorrectionVolume.m_LastEnterWeight = findOffsetByName(j, "C_ColorCorrectionVolume", "m_LastEnterWeight");
    C_ColorCorrectionVolume.m_LastEnterTime = findOffsetByName(j, "C_ColorCorrectionVolume", "m_LastEnterTime");
    C_ColorCorrectionVolume.m_LastExitWeight = findOffsetByName(j, "C_ColorCorrectionVolume", "m_LastExitWeight");
    C_ColorCorrectionVolume.m_LastExitTime = findOffsetByName(j, "C_ColorCorrectionVolume", "m_LastExitTime");
    C_ColorCorrectionVolume.m_bEnabled = findOffsetByName(j, "C_ColorCorrectionVolume", "m_bEnabled");
    C_ColorCorrectionVolume.m_MaxWeight = findOffsetByName(j, "C_ColorCorrectionVolume", "m_MaxWeight");
    C_ColorCorrectionVolume.m_FadeDuration = findOffsetByName(j, "C_ColorCorrectionVolume", "m_FadeDuration");
    C_ColorCorrectionVolume.m_Weight = findOffsetByName(j, "C_ColorCorrectionVolume", "m_Weight");
    C_ColorCorrectionVolume.m_lookupFilename = findOffsetByName(j, "C_ColorCorrectionVolume", "m_lookupFilename");

    // Atribuições para C_BulletHitModel
    // C_BulletHitModel Offsets
    C_BulletHitModel.m_matLocal = findOffsetByName(j, "C_BulletHitModel", "m_matLocal");
    C_BulletHitModel.m_iBoneIndex = findOffsetByName(j, "C_BulletHitModel", "m_iBoneIndex");
    C_BulletHitModel.m_hPlayerParent = findOffsetByName(j, "C_BulletHitModel", "m_hPlayerParent");
    C_BulletHitModel.m_bIsHit = findOffsetByName(j, "C_BulletHitModel", "m_bIsHit");
    C_BulletHitModel.m_flTimeCreated = findOffsetByName(j, "C_BulletHitModel", "m_flTimeCreated");
    C_BulletHitModel.m_vecStartPos = findOffsetByName(j, "C_BulletHitModel", "m_vecStartPos");

    // Atribuições para C_MapVetoPickController
    // C_MapVetoPickController Offsets
    C_MapVetoPickController.m_nDraftType = findOffsetByName(j, "C_MapVetoPickController", "m_nDraftType");
    C_MapVetoPickController.m_nTeamWinningCoinToss = findOffsetByName(j, "C_MapVetoPickController", "m_nTeamWinningCoinToss");
    C_MapVetoPickController.m_nTeamWithFirstChoice = findOffsetByName(j, "C_MapVetoPickController", "m_nTeamWithFirstChoice");
    C_MapVetoPickController.m_nVoteMapIdsList = findOffsetByName(j, "C_MapVetoPickController", "m_nVoteMapIdsList");
    C_MapVetoPickController.m_nAccountIDs = findOffsetByName(j, "C_MapVetoPickController", "m_nAccountIDs");
    C_MapVetoPickController.m_nMapId0 = findOffsetByName(j, "C_MapVetoPickController", "m_nMapId0");
    C_MapVetoPickController.m_nMapId1 = findOffsetByName(j, "C_MapVetoPickController", "m_nMapId1");
    C_MapVetoPickController.m_nMapId2 = findOffsetByName(j, "C_MapVetoPickController", "m_nMapId2");
    C_MapVetoPickController.m_nMapId3 = findOffsetByName(j, "C_MapVetoPickController", "m_nMapId3");
    C_MapVetoPickController.m_nMapId4 = findOffsetByName(j, "C_MapVetoPickController", "m_nMapId4");
    C_MapVetoPickController.m_nMapId5 = findOffsetByName(j, "C_MapVetoPickController", "m_nMapId5");
    C_MapVetoPickController.m_nStartingSide0 = findOffsetByName(j, "C_MapVetoPickController", "m_nStartingSide0");
    C_MapVetoPickController.m_nCurrentPhase = findOffsetByName(j, "C_MapVetoPickController", "m_nCurrentPhase");
    C_MapVetoPickController.m_nPhaseStartTick = findOffsetByName(j, "C_MapVetoPickController", "m_nPhaseStartTick");
    C_MapVetoPickController.m_nPhaseDurationTicks = findOffsetByName(j, "C_MapVetoPickController", "m_nPhaseDurationTicks");
    C_MapVetoPickController.m_nPostDataUpdateTick = findOffsetByName(j, "C_MapVetoPickController", "m_nPostDataUpdateTick");
    C_MapVetoPickController.m_bDisabledHud = findOffsetByName(j, "C_MapVetoPickController", "m_bDisabledHud");

    // Atribuições para C_OmniLight
    // C_OmniLight Offsets
    C_OmniLight.m_flInnerAngle = findOffsetByName(j, "C_OmniLight", "m_flInnerAngle");
    C_OmniLight.m_flOuterAngle = findOffsetByName(j, "C_OmniLight", "m_flOuterAngle");
    C_OmniLight.m_bShowLight = findOffsetByName(j, "C_OmniLight", "m_bShowLight");

    // Atribuições para WeaponPurchaseTracker_t
    // WeaponPurchaseTracker_t Offsets
    WeaponPurchaseTracker_t.m_weaponPurchases = findOffsetByName(j, "WeaponPurchaseTracker_t", "m_weaponPurchases");

    // Atribuições para C_RetakeGameRules
    // C_RetakeGameRules Offsets
    C_RetakeGameRules.m_nMatchSeed = findOffsetByName(j, "C_RetakeGameRules", "m_nMatchSeed");
    C_RetakeGameRules.m_bBlockersPresent = findOffsetByName(j, "C_RetakeGameRules", "m_bBlockersPresent");
    C_RetakeGameRules.m_bRoundInProgress = findOffsetByName(j, "C_RetakeGameRules", "m_bRoundInProgress");
    C_RetakeGameRules.m_iFirstSecondHalfRound = findOffsetByName(j, "C_RetakeGameRules", "m_iFirstSecondHalfRound");
    C_RetakeGameRules.m_iBombSite = findOffsetByName(j, "C_RetakeGameRules", "m_iBombSite");

    // Atribuições para EngineCountdownTimer
    // EngineCountdownTimer Offsets
    EngineCountdownTimer.m_duration = findOffsetByName(j, "EngineCountdownTimer", "m_duration");
    EngineCountdownTimer.m_timestamp = findOffsetByName(j, "EngineCountdownTimer", "m_timestamp");
    EngineCountdownTimer.m_timescale = findOffsetByName(j, "EngineCountdownTimer", "m_timescale");

    // Atribuições para C_BaseFlex__Emphasized_Phoneme
    // C_BaseFlex__Emphasized_Phoneme Offsets
    C_BaseFlex__Emphasized_Phoneme.m_sClassName = findOffsetByName(j, "C_BaseFlex__Emphasized_Phoneme", "m_sClassName");
    C_BaseFlex__Emphasized_Phoneme.m_flAmount = findOffsetByName(j, "C_BaseFlex__Emphasized_Phoneme", "m_flAmount");
    C_BaseFlex__Emphasized_Phoneme.m_bRequired = findOffsetByName(j, "C_BaseFlex__Emphasized_Phoneme", "m_bRequired");
    C_BaseFlex__Emphasized_Phoneme.m_bBasechecked = findOffsetByName(j, "C_BaseFlex__Emphasized_Phoneme", "m_bBasechecked");
    C_BaseFlex__Emphasized_Phoneme.m_bValid = findOffsetByName(j, "C_BaseFlex__Emphasized_Phoneme", "m_bValid");

    // Atribuições para IntervalTimer
    // IntervalTimer Offsets
    IntervalTimer.m_timestamp = findOffsetByName(j, "IntervalTimer", "m_timestamp");
    IntervalTimer.m_nWorldGroupId = findOffsetByName(j, "IntervalTimer", "m_nWorldGroupId");

    // Atribuições para C_FuncLadder
    // C_FuncLadder Offsets
    C_FuncLadder.m_vecLadderDir = findOffsetByName(j, "C_FuncLadder", "m_vecLadderDir");
    C_FuncLadder.m_Dismounts = findOffsetByName(j, "C_FuncLadder", "m_Dismounts");
    C_FuncLadder.m_vecLocalTop = findOffsetByName(j, "C_FuncLadder", "m_vecLocalTop");
    C_FuncLadder.m_vecPlayerMountPositionTop = findOffsetByName(j, "C_FuncLadder", "m_vecPlayerMountPositionTop");
    C_FuncLadder.m_vecPlayerMountPositionBottom = findOffsetByName(j, "C_FuncLadder", "m_vecPlayerMountPositionBottom");
    C_FuncLadder.m_flAutoRideSpeed = findOffsetByName(j, "C_FuncLadder", "m_flAutoRideSpeed");
    C_FuncLadder.m_bDisabled = findOffsetByName(j, "C_FuncLadder", "m_bDisabled");
    C_FuncLadder.m_bFakeLadder = findOffsetByName(j, "C_FuncLadder", "m_bFakeLadder");
    C_FuncLadder.m_bHasSlack = findOffsetByName(j, "C_FuncLadder", "m_bHasSlack");

    // Atribuições para CPlayer_WeaponServices
    // CPlayer_WeaponServices Offsets
    CPlayer_WeaponServices.m_hMyWeapons = findOffsetByName(j, "CPlayer_WeaponServices", "m_hMyWeapons");
    CPlayer_WeaponServices.m_hActiveWeapon = findOffsetByName(j, "CPlayer_WeaponServices", "m_hActiveWeapon");
    CPlayer_WeaponServices.m_hLastWeapon = findOffsetByName(j, "CPlayer_WeaponServices", "m_hLastWeapon");
    CPlayer_WeaponServices.m_iAmmo = findOffsetByName(j, "CPlayer_WeaponServices", "m_iAmmo");

    // Atribuições para CAttributeManager__cached_attribute_float_t
    // CAttributeManager__cached_attribute_float_t Offsets
    CAttributeManager__cached_attribute_float_t.flIn = findOffsetByName(j, "CAttributeManager__cached_attribute_float_t", "flIn");
    CAttributeManager__cached_attribute_float_t.iAttribHook = findOffsetByName(j, "CAttributeManager__cached_attribute_float_t", "iAttribHook");
    CAttributeManager__cached_attribute_float_t.flOut = findOffsetByName(j, "CAttributeManager__cached_attribute_float_t", "flOut");

    // Atribuições para C_BaseGrenade
    // C_BaseGrenade Offsets
    C_BaseGrenade.m_bHasWarnedAI = findOffsetByName(j, "C_BaseGrenade", "m_bHasWarnedAI");
    C_BaseGrenade.m_bIsSmokeGrenade = findOffsetByName(j, "C_BaseGrenade", "m_bIsSmokeGrenade");
    C_BaseGrenade.m_bIsLive = findOffsetByName(j, "C_BaseGrenade", "m_bIsLive");
    C_BaseGrenade.m_DmgRadius = findOffsetByName(j, "C_BaseGrenade", "m_DmgRadius");
    C_BaseGrenade.m_flDetonateTime = findOffsetByName(j, "C_BaseGrenade", "m_flDetonateTime");
    C_BaseGrenade.m_flWarnAITime = findOffsetByName(j, "C_BaseGrenade", "m_flWarnAITime");
    C_BaseGrenade.m_flDamage = findOffsetByName(j, "C_BaseGrenade", "m_flDamage");
    C_BaseGrenade.m_iszBounceSound = findOffsetByName(j, "C_BaseGrenade", "m_iszBounceSound");
    C_BaseGrenade.m_ExplosionSound = findOffsetByName(j, "C_BaseGrenade", "m_ExplosionSound");
    C_BaseGrenade.m_hThrower = findOffsetByName(j, "C_BaseGrenade", "m_hThrower");
    C_BaseGrenade.m_flNextAttack = findOffsetByName(j, "C_BaseGrenade", "m_flNextAttack");
    C_BaseGrenade.m_hOriginalThrower = findOffsetByName(j, "C_BaseGrenade", "m_hOriginalThrower");

    // Atribuições para CCSGameModeRules
    // CCSGameModeRules Offsets
    CCSGameModeRules.__m_pChainEntity = findOffsetByName(j, "CCSGameModeRules", "__m_pChainEntity");

    // Atribuições para VPhysicsCollisionAttribute_t
    // VPhysicsCollisionAttribute_t Offsets
    VPhysicsCollisionAttribute_t.m_nInteractsAs = findOffsetByName(j, "VPhysicsCollisionAttribute_t", "m_nInteractsAs");
    VPhysicsCollisionAttribute_t.m_nInteractsWith = findOffsetByName(j, "VPhysicsCollisionAttribute_t", "m_nInteractsWith");
    VPhysicsCollisionAttribute_t.m_nInteractsExclude = findOffsetByName(j, "VPhysicsCollisionAttribute_t", "m_nInteractsExclude");
    VPhysicsCollisionAttribute_t.m_nEntityId = findOffsetByName(j, "VPhysicsCollisionAttribute_t", "m_nEntityId");
    VPhysicsCollisionAttribute_t.m_nOwnerId = findOffsetByName(j, "VPhysicsCollisionAttribute_t", "m_nOwnerId");
    VPhysicsCollisionAttribute_t.m_nHierarchyId = findOffsetByName(j, "VPhysicsCollisionAttribute_t", "m_nHierarchyId");
    VPhysicsCollisionAttribute_t.m_nCollisionGroup = findOffsetByName(j, "VPhysicsCollisionAttribute_t", "m_nCollisionGroup");
    VPhysicsCollisionAttribute_t.m_nCollisionFunctionMask = findOffsetByName(j, "VPhysicsCollisionAttribute_t", "m_nCollisionFunctionMask");

    // Atribuições para C_EnvVolumetricFogController
    // C_EnvVolumetricFogController Offsets
    C_EnvVolumetricFogController.m_flScattering = findOffsetByName(j, "C_EnvVolumetricFogController", "m_flScattering");
    C_EnvVolumetricFogController.m_flAnisotropy = findOffsetByName(j, "C_EnvVolumetricFogController", "m_flAnisotropy");
    C_EnvVolumetricFogController.m_flFadeSpeed = findOffsetByName(j, "C_EnvVolumetricFogController", "m_flFadeSpeed");
    C_EnvVolumetricFogController.m_flDrawDistance = findOffsetByName(j, "C_EnvVolumetricFogController", "m_flDrawDistance");
    C_EnvVolumetricFogController.m_flFadeInStart = findOffsetByName(j, "C_EnvVolumetricFogController", "m_flFadeInStart");
    C_EnvVolumetricFogController.m_flFadeInEnd = findOffsetByName(j, "C_EnvVolumetricFogController", "m_flFadeInEnd");
    C_EnvVolumetricFogController.m_flIndirectStrength = findOffsetByName(j, "C_EnvVolumetricFogController", "m_flIndirectStrength");
    C_EnvVolumetricFogController.m_nVolumeDepth = findOffsetByName(j, "C_EnvVolumetricFogController", "m_nVolumeDepth");
    C_EnvVolumetricFogController.m_fFirstVolumeSliceThickness = findOffsetByName(j, "C_EnvVolumetricFogController", "m_fFirstVolumeSliceThickness");
    C_EnvVolumetricFogController.m_nIndirectTextureDimX = findOffsetByName(j, "C_EnvVolumetricFogController", "m_nIndirectTextureDimX");
    C_EnvVolumetricFogController.m_nIndirectTextureDimY = findOffsetByName(j, "C_EnvVolumetricFogController", "m_nIndirectTextureDimY");
    C_EnvVolumetricFogController.m_nIndirectTextureDimZ = findOffsetByName(j, "C_EnvVolumetricFogController", "m_nIndirectTextureDimZ");
    C_EnvVolumetricFogController.m_vBoxMins = findOffsetByName(j, "C_EnvVolumetricFogController", "m_vBoxMins");
    C_EnvVolumetricFogController.m_vBoxMaxs = findOffsetByName(j, "C_EnvVolumetricFogController", "m_vBoxMaxs");
    C_EnvVolumetricFogController.m_bActive = findOffsetByName(j, "C_EnvVolumetricFogController", "m_bActive");
    C_EnvVolumetricFogController.m_flStartAnisoTime = findOffsetByName(j, "C_EnvVolumetricFogController", "m_flStartAnisoTime");
    C_EnvVolumetricFogController.m_flStartScatterTime = findOffsetByName(j, "C_EnvVolumetricFogController", "m_flStartScatterTime");
    C_EnvVolumetricFogController.m_flStartDrawDistanceTime = findOffsetByName(j, "C_EnvVolumetricFogController", "m_flStartDrawDistanceTime");
    C_EnvVolumetricFogController.m_flStartAnisotropy = findOffsetByName(j, "C_EnvVolumetricFogController", "m_flStartAnisotropy");
    C_EnvVolumetricFogController.m_flStartScattering = findOffsetByName(j, "C_EnvVolumetricFogController", "m_flStartScattering");
    C_EnvVolumetricFogController.m_flStartDrawDistance = findOffsetByName(j, "C_EnvVolumetricFogController", "m_flStartDrawDistance");
    C_EnvVolumetricFogController.m_flDefaultAnisotropy = findOffsetByName(j, "C_EnvVolumetricFogController", "m_flDefaultAnisotropy");
    C_EnvVolumetricFogController.m_flDefaultScattering = findOffsetByName(j, "C_EnvVolumetricFogController", "m_flDefaultScattering");
    C_EnvVolumetricFogController.m_flDefaultDrawDistance = findOffsetByName(j, "C_EnvVolumetricFogController", "m_flDefaultDrawDistance");
    C_EnvVolumetricFogController.m_bStartDisabled = findOffsetByName(j, "C_EnvVolumetricFogController", "m_bStartDisabled");
    C_EnvVolumetricFogController.m_bEnableIndirect = findOffsetByName(j, "C_EnvVolumetricFogController", "m_bEnableIndirect");
    C_EnvVolumetricFogController.m_bIndirectUseLPVs = findOffsetByName(j, "C_EnvVolumetricFogController", "m_bIndirectUseLPVs");
    C_EnvVolumetricFogController.m_bIsMaster = findOffsetByName(j, "C_EnvVolumetricFogController", "m_bIsMaster");
    C_EnvVolumetricFogController.m_hFogIndirectTexture = findOffsetByName(j, "C_EnvVolumetricFogController", "m_hFogIndirectTexture");
    C_EnvVolumetricFogController.m_nForceRefreshCount = findOffsetByName(j, "C_EnvVolumetricFogController", "m_nForceRefreshCount");
    C_EnvVolumetricFogController.m_fNoiseSpeed = findOffsetByName(j, "C_EnvVolumetricFogController", "m_fNoiseSpeed");
    C_EnvVolumetricFogController.m_fNoiseStrength = findOffsetByName(j, "C_EnvVolumetricFogController", "m_fNoiseStrength");
    C_EnvVolumetricFogController.m_vNoiseScale = findOffsetByName(j, "C_EnvVolumetricFogController", "m_vNoiseScale");
    C_EnvVolumetricFogController.m_bFirstTime = findOffsetByName(j, "C_EnvVolumetricFogController", "m_bFirstTime");

    // Atribuições para C_PointCommentaryNode
    // C_PointCommentaryNode Offsets
    C_PointCommentaryNode.m_bActive = findOffsetByName(j, "C_PointCommentaryNode", "m_bActive");
    C_PointCommentaryNode.m_bWasActive = findOffsetByName(j, "C_PointCommentaryNode", "m_bWasActive");
    C_PointCommentaryNode.m_flEndTime = findOffsetByName(j, "C_PointCommentaryNode", "m_flEndTime");
    C_PointCommentaryNode.m_flStartTime = findOffsetByName(j, "C_PointCommentaryNode", "m_flStartTime");
    C_PointCommentaryNode.m_flStartTimeInCommentary = findOffsetByName(j, "C_PointCommentaryNode", "m_flStartTimeInCommentary");
    C_PointCommentaryNode.m_iszCommentaryFile = findOffsetByName(j, "C_PointCommentaryNode", "m_iszCommentaryFile");
    C_PointCommentaryNode.m_iszTitle = findOffsetByName(j, "C_PointCommentaryNode", "m_iszTitle");
    C_PointCommentaryNode.m_iszSpeakers = findOffsetByName(j, "C_PointCommentaryNode", "m_iszSpeakers");
    C_PointCommentaryNode.m_iNodeNumber = findOffsetByName(j, "C_PointCommentaryNode", "m_iNodeNumber");
    C_PointCommentaryNode.m_iNodeNumberMax = findOffsetByName(j, "C_PointCommentaryNode", "m_iNodeNumberMax");
    C_PointCommentaryNode.m_bListenedTo = findOffsetByName(j, "C_PointCommentaryNode", "m_bListenedTo");
    C_PointCommentaryNode.m_hViewPosition = findOffsetByName(j, "C_PointCommentaryNode", "m_hViewPosition");
    C_PointCommentaryNode.m_bRestartAfterRestore = findOffsetByName(j, "C_PointCommentaryNode", "m_bRestartAfterRestore");

    // Atribuições para audioparams_t
    // audioparams_t Offsets
    audioparams_t.localSound = findOffsetByName(j, "audioparams_t", "localSound");
    audioparams_t.soundscapeIndex = findOffsetByName(j, "audioparams_t", "soundscapeIndex");
    audioparams_t.localBits = findOffsetByName(j, "audioparams_t", "localBits");
    audioparams_t.soundscapeEntityListIndex = findOffsetByName(j, "audioparams_t", "soundscapeEntityListIndex");
    audioparams_t.soundEventHash = findOffsetByName(j, "audioparams_t", "soundEventHash");

    // Atribuições para C_InfoVisibilityBox
    // C_InfoVisibilityBox Offsets
    C_InfoVisibilityBox.m_nMode = findOffsetByName(j, "C_InfoVisibilityBox", "m_nMode");
    C_InfoVisibilityBox.m_vBoxSize = findOffsetByName(j, "C_InfoVisibilityBox", "m_vBoxSize");
    C_InfoVisibilityBox.m_bEnabled = findOffsetByName(j, "C_InfoVisibilityBox", "m_bEnabled");

    // Atribuições para C_FireSprite
    // C_FireSprite Offsets
    C_FireSprite.m_vecMoveDir = findOffsetByName(j, "C_FireSprite", "m_vecMoveDir");
    C_FireSprite.m_bFadeFromAbove = findOffsetByName(j, "C_FireSprite", "m_bFadeFromAbove");

    // Atribuições para C_Precipitation
    // C_Precipitation Offsets
    C_Precipitation.m_flDensity = findOffsetByName(j, "C_Precipitation", "m_flDensity");
    C_Precipitation.m_flParticleInnerDist = findOffsetByName(j, "C_Precipitation", "m_flParticleInnerDist");
    C_Precipitation.m_pParticleDef = findOffsetByName(j, "C_Precipitation", "m_pParticleDef");
    C_Precipitation.m_tParticlePrecipTraceTimer = findOffsetByName(j, "C_Precipitation", "m_tParticlePrecipTraceTimer");
    C_Precipitation.m_bActiveParticlePrecipEmitter = findOffsetByName(j, "C_Precipitation", "m_bActiveParticlePrecipEmitter");
    C_Precipitation.m_bParticlePrecipInitialized = findOffsetByName(j, "C_Precipitation", "m_bParticlePrecipInitialized");
    C_Precipitation.m_bHasSimulatedSinceLastSceneObjectUpdate = findOffsetByName(j, "C_Precipitation", "m_bHasSimulatedSinceLastSceneObjectUpdate");
    C_Precipitation.m_nAvailableSheetSequencesMaxIndex = findOffsetByName(j, "C_Precipitation", "m_nAvailableSheetSequencesMaxIndex");

    // Atribuições para CPrecipitationVData
    // CPrecipitationVData Offsets
    CPrecipitationVData.m_szParticlePrecipitationEffect = findOffsetByName(j, "CPrecipitationVData", "m_szParticlePrecipitationEffect");
    CPrecipitationVData.m_flInnerDistance = findOffsetByName(j, "CPrecipitationVData", "m_flInnerDistance");
    CPrecipitationVData.m_nAttachType = findOffsetByName(j, "CPrecipitationVData", "m_nAttachType");
    CPrecipitationVData.m_bBatchSameVolumeType = findOffsetByName(j, "CPrecipitationVData", "m_bBatchSameVolumeType");
    CPrecipitationVData.m_nRTEnvCP = findOffsetByName(j, "CPrecipitationVData", "m_nRTEnvCP");
    CPrecipitationVData.m_nRTEnvCPComponent = findOffsetByName(j, "CPrecipitationVData", "m_nRTEnvCPComponent");
    CPrecipitationVData.m_szModifier = findOffsetByName(j, "CPrecipitationVData", "m_szModifier");

    // Atribuições para CBuoyancyHelper
    // CBuoyancyHelper Offsets
    CBuoyancyHelper.m_nFluidType = findOffsetByName(j, "CBuoyancyHelper", "m_nFluidType");
    CBuoyancyHelper.m_flFluidDensity = findOffsetByName(j, "CBuoyancyHelper", "m_flFluidDensity");
    CBuoyancyHelper.m_vecFractionOfWheelSubmergedForWheelFriction = findOffsetByName(j, "CBuoyancyHelper", "m_vecFractionOfWheelSubmergedForWheelFriction");
    CBuoyancyHelper.m_vecWheelFrictionScales = findOffsetByName(j, "CBuoyancyHelper", "m_vecWheelFrictionScales");
    CBuoyancyHelper.m_vecFractionOfWheelSubmergedForWheelDrag = findOffsetByName(j, "CBuoyancyHelper", "m_vecFractionOfWheelSubmergedForWheelDrag");
    CBuoyancyHelper.m_vecWheelDrag = findOffsetByName(j, "CBuoyancyHelper", "m_vecWheelDrag");

    // Atribuições para C_BaseClientUIEntity
    // C_BaseClientUIEntity Offsets
    C_BaseClientUIEntity.m_bEnabled = findOffsetByName(j, "C_BaseClientUIEntity", "m_bEnabled");
    C_BaseClientUIEntity.m_DialogXMLName = findOffsetByName(j, "C_BaseClientUIEntity", "m_DialogXMLName");
    C_BaseClientUIEntity.m_PanelClassName = findOffsetByName(j, "C_BaseClientUIEntity", "m_PanelClassName");
    C_BaseClientUIEntity.m_PanelID = findOffsetByName(j, "C_BaseClientUIEntity", "m_PanelID");

    // Atribuições para C_FuncTrackTrain
    // C_FuncTrackTrain Offsets
    C_FuncTrackTrain.m_nLongAxis = findOffsetByName(j, "C_FuncTrackTrain", "m_nLongAxis");
    C_FuncTrackTrain.m_flRadius = findOffsetByName(j, "C_FuncTrackTrain", "m_flRadius");
    C_FuncTrackTrain.m_flLineLength = findOffsetByName(j, "C_FuncTrackTrain", "m_flLineLength");

    // Atribuições para CCSPlayer_ActionTrackingServices
    // CCSPlayer_ActionTrackingServices Offsets
    CCSPlayer_ActionTrackingServices.m_hLastWeaponBeforeC4AutoSwitch = findOffsetByName(j, "CCSPlayer_ActionTrackingServices", "m_hLastWeaponBeforeC4AutoSwitch");
    CCSPlayer_ActionTrackingServices.m_bIsRescuing = findOffsetByName(j, "CCSPlayer_ActionTrackingServices", "m_bIsRescuing");
    CCSPlayer_ActionTrackingServices.m_weaponPurchasesThisMatch = findOffsetByName(j, "CCSPlayer_ActionTrackingServices", "m_weaponPurchasesThisMatch");
    CCSPlayer_ActionTrackingServices.m_weaponPurchasesThisRound = findOffsetByName(j, "CCSPlayer_ActionTrackingServices", "m_weaponPurchasesThisRound");

    // Atribuições para shard_model_desc_t
    // shard_model_desc_t Offsets
    shard_model_desc_t.m_nModelID = findOffsetByName(j, "shard_model_desc_t", "m_nModelID");
    shard_model_desc_t.m_hMaterialBase = findOffsetByName(j, "shard_model_desc_t", "m_hMaterialBase");
    shard_model_desc_t.m_hMaterialDamageOverlay = findOffsetByName(j, "shard_model_desc_t", "m_hMaterialDamageOverlay");
    shard_model_desc_t.m_solid = findOffsetByName(j, "shard_model_desc_t", "m_solid");
    shard_model_desc_t.m_vecPanelSize = findOffsetByName(j, "shard_model_desc_t", "m_vecPanelSize");
    shard_model_desc_t.m_vecStressPositionA = findOffsetByName(j, "shard_model_desc_t", "m_vecStressPositionA");
    shard_model_desc_t.m_vecStressPositionB = findOffsetByName(j, "shard_model_desc_t", "m_vecStressPositionB");
    shard_model_desc_t.m_vecPanelVertices = findOffsetByName(j, "shard_model_desc_t", "m_vecPanelVertices");
    shard_model_desc_t.m_vInitialPanelVertices = findOffsetByName(j, "shard_model_desc_t", "m_vInitialPanelVertices");
    shard_model_desc_t.m_flGlassHalfThickness = findOffsetByName(j, "shard_model_desc_t", "m_flGlassHalfThickness");
    shard_model_desc_t.m_bHasParent = findOffsetByName(j, "shard_model_desc_t", "m_bHasParent");
    shard_model_desc_t.m_bParentFrozen = findOffsetByName(j, "shard_model_desc_t", "m_bParentFrozen");
    shard_model_desc_t.m_SurfacePropStringToken = findOffsetByName(j, "shard_model_desc_t", "m_SurfacePropStringToken");

    // Atribuições para C_SceneEntity__QueuedEvents_t
    // C_SceneEntity__QueuedEvents_t Offsets
    C_SceneEntity__QueuedEvents_t.starttime = findOffsetByName(j, "C_SceneEntity__QueuedEvents_t", "starttime");

    // Atribuições para CBaseProp
    // CBaseProp Offsets
    CBaseProp.m_bModelOverrodeBlockLOS = findOffsetByName(j, "CBaseProp", "m_bModelOverrodeBlockLOS");
    CBaseProp.m_iShapeType = findOffsetByName(j, "CBaseProp", "m_iShapeType");
    CBaseProp.m_bConformToCollisionBounds = findOffsetByName(j, "CBaseProp", "m_bConformToCollisionBounds");
    CBaseProp.m_mPreferredCatchTransform = findOffsetByName(j, "CBaseProp", "m_mPreferredCatchTransform");

    // Atribuições para CPointTemplate
    // CPointTemplate Offsets
    CPointTemplate.m_iszWorldName = findOffsetByName(j, "CPointTemplate", "m_iszWorldName");
    CPointTemplate.m_iszSource2EntityLumpName = findOffsetByName(j, "CPointTemplate", "m_iszSource2EntityLumpName");
    CPointTemplate.m_iszEntityFilterName = findOffsetByName(j, "CPointTemplate", "m_iszEntityFilterName");
    CPointTemplate.m_flTimeoutInterval = findOffsetByName(j, "CPointTemplate", "m_flTimeoutInterval");
    CPointTemplate.m_bAsynchronouslySpawnEntities = findOffsetByName(j, "CPointTemplate", "m_bAsynchronouslySpawnEntities");
    CPointTemplate.m_pOutputOnSpawned = findOffsetByName(j, "CPointTemplate", "m_pOutputOnSpawned");
    CPointTemplate.m_clientOnlyEntityBehavior = findOffsetByName(j, "CPointTemplate", "m_clientOnlyEntityBehavior");
    CPointTemplate.m_ownerSpawnGroupType = findOffsetByName(j, "CPointTemplate", "m_ownerSpawnGroupType");
    CPointTemplate.m_createdSpawnGroupHandles = findOffsetByName(j, "CPointTemplate", "m_createdSpawnGroupHandles");
    CPointTemplate.m_SpawnedEntityHandles = findOffsetByName(j, "CPointTemplate", "m_SpawnedEntityHandles");
    CPointTemplate.m_ScriptSpawnCallback = findOffsetByName(j, "CPointTemplate", "m_ScriptSpawnCallback");
    CPointTemplate.m_ScriptCallbackScope = findOffsetByName(j, "CPointTemplate", "m_ScriptCallbackScope");

    // Atribuições para C_CSGO_PreviewModel
    // C_CSGO_PreviewModel Offsets
    C_CSGO_PreviewModel.m_animgraph = findOffsetByName(j, "C_CSGO_PreviewModel", "m_animgraph");
    C_CSGO_PreviewModel.m_animgraphCharacterModeString = findOffsetByName(j, "C_CSGO_PreviewModel", "m_animgraphCharacterModeString");
    C_CSGO_PreviewModel.m_defaultAnim = findOffsetByName(j, "C_CSGO_PreviewModel", "m_defaultAnim");
    C_CSGO_PreviewModel.m_nDefaultAnimLoopMode = findOffsetByName(j, "C_CSGO_PreviewModel", "m_nDefaultAnimLoopMode");
    C_CSGO_PreviewModel.m_flInitialModelScale = findOffsetByName(j, "C_CSGO_PreviewModel", "m_flInitialModelScale");
    C_CSGO_PreviewModel.m_sInitialWeaponState = findOffsetByName(j, "C_CSGO_PreviewModel", "m_sInitialWeaponState");

    // Atribuições para CInfoDynamicShadowHint
    // CInfoDynamicShadowHint Offsets
    CInfoDynamicShadowHint.m_bDisabled = findOffsetByName(j, "CInfoDynamicShadowHint", "m_bDisabled");
    CInfoDynamicShadowHint.m_flRange = findOffsetByName(j, "CInfoDynamicShadowHint", "m_flRange");
    CInfoDynamicShadowHint.m_nImportance = findOffsetByName(j, "CInfoDynamicShadowHint", "m_nImportance");
    CInfoDynamicShadowHint.m_nLightChoice = findOffsetByName(j, "CInfoDynamicShadowHint", "m_nLightChoice");
    CInfoDynamicShadowHint.m_hLight = findOffsetByName(j, "CInfoDynamicShadowHint", "m_hLight");

    // Atribuições para CGlowProperty
    // CGlowProperty Offsets
    CGlowProperty.m_fGlowColor = findOffsetByName(j, "CGlowProperty", "m_fGlowColor");
    CGlowProperty.m_iGlowType = findOffsetByName(j, "CGlowProperty", "m_iGlowType");
    CGlowProperty.m_iGlowTeam = findOffsetByName(j, "CGlowProperty", "m_iGlowTeam");
    CGlowProperty.m_nGlowRange = findOffsetByName(j, "CGlowProperty", "m_nGlowRange");
    CGlowProperty.m_nGlowRangeMin = findOffsetByName(j, "CGlowProperty", "m_nGlowRangeMin");
    CGlowProperty.m_glowColorOverride = findOffsetByName(j, "CGlowProperty", "m_glowColorOverride");
    CGlowProperty.m_bFlashing = findOffsetByName(j, "CGlowProperty", "m_bFlashing");
    CGlowProperty.m_flGlowTime = findOffsetByName(j, "CGlowProperty", "m_flGlowTime");
    CGlowProperty.m_flGlowStartTime = findOffsetByName(j, "CGlowProperty", "m_flGlowStartTime");
    CGlowProperty.m_bEligibleForScreenHighlight = findOffsetByName(j, "CGlowProperty", "m_bEligibleForScreenHighlight");
    CGlowProperty.m_bGlowing = findOffsetByName(j, "CGlowProperty", "m_bGlowing");

    // Atribuições para C_TriggerPhysics
    // C_TriggerPhysics Offsets
    C_TriggerPhysics.m_gravityScale = findOffsetByName(j, "C_TriggerPhysics", "m_gravityScale");
    C_TriggerPhysics.m_linearLimit = findOffsetByName(j, "C_TriggerPhysics", "m_linearLimit");
    C_TriggerPhysics.m_linearDamping = findOffsetByName(j, "C_TriggerPhysics", "m_linearDamping");
    C_TriggerPhysics.m_angularLimit = findOffsetByName(j, "C_TriggerPhysics", "m_angularLimit");
    C_TriggerPhysics.m_angularDamping = findOffsetByName(j, "C_TriggerPhysics", "m_angularDamping");
    C_TriggerPhysics.m_linearForce = findOffsetByName(j, "C_TriggerPhysics", "m_linearForce");
    C_TriggerPhysics.m_flFrequency = findOffsetByName(j, "C_TriggerPhysics", "m_flFrequency");
    C_TriggerPhysics.m_flDampingRatio = findOffsetByName(j, "C_TriggerPhysics", "m_flDampingRatio");
    C_TriggerPhysics.m_vecLinearForcePointAt = findOffsetByName(j, "C_TriggerPhysics", "m_vecLinearForcePointAt");
    C_TriggerPhysics.m_bCollapseToForcePoint = findOffsetByName(j, "C_TriggerPhysics", "m_bCollapseToForcePoint");
    C_TriggerPhysics.m_vecLinearForcePointAtWorld = findOffsetByName(j, "C_TriggerPhysics", "m_vecLinearForcePointAtWorld");
    C_TriggerPhysics.m_vecLinearForceDirection = findOffsetByName(j, "C_TriggerPhysics", "m_vecLinearForceDirection");
    C_TriggerPhysics.m_bConvertToDebrisWhenPossible = findOffsetByName(j, "C_TriggerPhysics", "m_bConvertToDebrisWhenPossible");

    // Atribuições para CCSPlayer_HostageServices
    // CCSPlayer_HostageServices Offsets
    CCSPlayer_HostageServices.m_hCarriedHostage = findOffsetByName(j, "CCSPlayer_HostageServices", "m_hCarriedHostage");
    CCSPlayer_HostageServices.m_hCarriedHostageProp = findOffsetByName(j, "CCSPlayer_HostageServices", "m_hCarriedHostageProp");

    // Atribuições para C_EnvCubemap
    // C_EnvCubemap Offsets
    C_EnvCubemap.m_Entity_hCubemapTexture = findOffsetByName(j, "C_EnvCubemap", "m_Entity_hCubemapTexture");
    C_EnvCubemap.m_Entity_bCustomCubemapTexture = findOffsetByName(j, "C_EnvCubemap", "m_Entity_bCustomCubemapTexture");
    C_EnvCubemap.m_Entity_flInfluenceRadius = findOffsetByName(j, "C_EnvCubemap", "m_Entity_flInfluenceRadius");
    C_EnvCubemap.m_Entity_vBoxProjectMins = findOffsetByName(j, "C_EnvCubemap", "m_Entity_vBoxProjectMins");
    C_EnvCubemap.m_Entity_vBoxProjectMaxs = findOffsetByName(j, "C_EnvCubemap", "m_Entity_vBoxProjectMaxs");
    C_EnvCubemap.m_Entity_bMoveable = findOffsetByName(j, "C_EnvCubemap", "m_Entity_bMoveable");
    C_EnvCubemap.m_Entity_nHandshake = findOffsetByName(j, "C_EnvCubemap", "m_Entity_nHandshake");
    C_EnvCubemap.m_Entity_nEnvCubeMapArrayIndex = findOffsetByName(j, "C_EnvCubemap", "m_Entity_nEnvCubeMapArrayIndex");
    C_EnvCubemap.m_Entity_nPriority = findOffsetByName(j, "C_EnvCubemap", "m_Entity_nPriority");
    C_EnvCubemap.m_Entity_flEdgeFadeDist = findOffsetByName(j, "C_EnvCubemap", "m_Entity_flEdgeFadeDist");
    C_EnvCubemap.m_Entity_vEdgeFadeDists = findOffsetByName(j, "C_EnvCubemap", "m_Entity_vEdgeFadeDists");
    C_EnvCubemap.m_Entity_flDiffuseScale = findOffsetByName(j, "C_EnvCubemap", "m_Entity_flDiffuseScale");
    C_EnvCubemap.m_Entity_bStartDisabled = findOffsetByName(j, "C_EnvCubemap", "m_Entity_bStartDisabled");
    C_EnvCubemap.m_Entity_bDefaultEnvMap = findOffsetByName(j, "C_EnvCubemap", "m_Entity_bDefaultEnvMap");
    C_EnvCubemap.m_Entity_bDefaultSpecEnvMap = findOffsetByName(j, "C_EnvCubemap", "m_Entity_bDefaultSpecEnvMap");
    C_EnvCubemap.m_Entity_bIndoorCubeMap = findOffsetByName(j, "C_EnvCubemap", "m_Entity_bIndoorCubeMap");
    C_EnvCubemap.m_Entity_bCopyDiffuseFromDefaultCubemap = findOffsetByName(j, "C_EnvCubemap", "m_Entity_bCopyDiffuseFromDefaultCubemap");
    C_EnvCubemap.m_Entity_bEnabled = findOffsetByName(j, "C_EnvCubemap", "m_Entity_bEnabled");

    // Atribuições para C_PredictedViewModel
    // C_PredictedViewModel Offsets
    C_PredictedViewModel.m_vPredictedLagOffset = findOffsetByName(j, "C_PredictedViewModel", "m_vPredictedLagOffset");
    C_PredictedViewModel.m_targetSpeed = findOffsetByName(j, "C_PredictedViewModel", "m_targetSpeed");
    C_PredictedViewModel.m_currentSpeed = findOffsetByName(j, "C_PredictedViewModel", "m_currentSpeed");

    // Atribuições para C_PointValueRemapper
    // C_PointValueRemapper Offsets
    C_PointValueRemapper.m_bDisabled = findOffsetByName(j, "C_PointValueRemapper", "m_bDisabled");
    C_PointValueRemapper.m_bDisabledOld = findOffsetByName(j, "C_PointValueRemapper", "m_bDisabledOld");
    C_PointValueRemapper.m_bUpdateOnClient = findOffsetByName(j, "C_PointValueRemapper", "m_bUpdateOnClient");
    C_PointValueRemapper.m_nInputType = findOffsetByName(j, "C_PointValueRemapper", "m_nInputType");
    C_PointValueRemapper.m_hRemapLineStart = findOffsetByName(j, "C_PointValueRemapper", "m_hRemapLineStart");
    C_PointValueRemapper.m_hRemapLineEnd = findOffsetByName(j, "C_PointValueRemapper", "m_hRemapLineEnd");
    C_PointValueRemapper.m_flMaximumChangePerSecond = findOffsetByName(j, "C_PointValueRemapper", "m_flMaximumChangePerSecond");
    C_PointValueRemapper.m_flDisengageDistance = findOffsetByName(j, "C_PointValueRemapper", "m_flDisengageDistance");
    C_PointValueRemapper.m_flEngageDistance = findOffsetByName(j, "C_PointValueRemapper", "m_flEngageDistance");
    C_PointValueRemapper.m_bRequiresUseKey = findOffsetByName(j, "C_PointValueRemapper", "m_bRequiresUseKey");
    C_PointValueRemapper.m_nOutputType = findOffsetByName(j, "C_PointValueRemapper", "m_nOutputType");
    C_PointValueRemapper.m_hOutputEntities = findOffsetByName(j, "C_PointValueRemapper", "m_hOutputEntities");
    C_PointValueRemapper.m_nHapticsType = findOffsetByName(j, "C_PointValueRemapper", "m_nHapticsType");
    C_PointValueRemapper.m_nMomentumType = findOffsetByName(j, "C_PointValueRemapper", "m_nMomentumType");
    C_PointValueRemapper.m_flMomentumModifier = findOffsetByName(j, "C_PointValueRemapper", "m_flMomentumModifier");
    C_PointValueRemapper.m_flSnapValue = findOffsetByName(j, "C_PointValueRemapper", "m_flSnapValue");
    C_PointValueRemapper.m_flCurrentMomentum = findOffsetByName(j, "C_PointValueRemapper", "m_flCurrentMomentum");
    C_PointValueRemapper.m_nRatchetType = findOffsetByName(j, "C_PointValueRemapper", "m_nRatchetType");
    C_PointValueRemapper.m_flRatchetOffset = findOffsetByName(j, "C_PointValueRemapper", "m_flRatchetOffset");
    C_PointValueRemapper.m_flInputOffset = findOffsetByName(j, "C_PointValueRemapper", "m_flInputOffset");
    C_PointValueRemapper.m_bEngaged = findOffsetByName(j, "C_PointValueRemapper", "m_bEngaged");
    C_PointValueRemapper.m_bFirstUpdate = findOffsetByName(j, "C_PointValueRemapper", "m_bFirstUpdate");
    C_PointValueRemapper.m_flPreviousValue = findOffsetByName(j, "C_PointValueRemapper", "m_flPreviousValue");
    C_PointValueRemapper.m_flPreviousUpdateTickTime = findOffsetByName(j, "C_PointValueRemapper", "m_flPreviousUpdateTickTime");
    C_PointValueRemapper.m_vecPreviousTestPoint = findOffsetByName(j, "C_PointValueRemapper", "m_vecPreviousTestPoint");

    // Atribuições para C_Knife
    // C_Knife Offsets
    C_Knife.m_bFirstAttack = findOffsetByName(j, "C_Knife", "m_bFirstAttack");

    // Atribuições para C_ItemDogtags
    // C_ItemDogtags Offsets
    C_ItemDogtags.m_OwningPlayer = findOffsetByName(j, "C_ItemDogtags", "m_OwningPlayer");
    C_ItemDogtags.m_KillingPlayer = findOffsetByName(j, "C_ItemDogtags", "m_KillingPlayer");

    // Atribuições para C_SoundOpvarSetPointBase
    // C_SoundOpvarSetPointBase Offsets
    C_SoundOpvarSetPointBase.m_iszStackName = findOffsetByName(j, "C_SoundOpvarSetPointBase", "m_iszStackName");
    C_SoundOpvarSetPointBase.m_iszOperatorName = findOffsetByName(j, "C_SoundOpvarSetPointBase", "m_iszOperatorName");
    C_SoundOpvarSetPointBase.m_iszOpvarName = findOffsetByName(j, "C_SoundOpvarSetPointBase", "m_iszOpvarName");
    C_SoundOpvarSetPointBase.m_iOpvarIndex = findOffsetByName(j, "C_SoundOpvarSetPointBase", "m_iOpvarIndex");
    C_SoundOpvarSetPointBase.m_bUseAutoCompare = findOffsetByName(j, "C_SoundOpvarSetPointBase", "m_bUseAutoCompare");

    // Atribuições para CCSPlayer_BuyServices
    // CCSPlayer_BuyServices Offsets
    CCSPlayer_BuyServices.m_vecSellbackPurchaseEntries = findOffsetByName(j, "CCSPlayer_BuyServices", "m_vecSellbackPurchaseEntries");

    // Atribuições para C_WeaponTaser
    // C_WeaponTaser Offsets
    C_WeaponTaser.m_fFireTime = findOffsetByName(j, "C_WeaponTaser", "m_fFireTime");
    C_WeaponTaser.m_nLastAttackTick = findOffsetByName(j, "C_WeaponTaser", "m_nLastAttackTick");

    // Atribuições para C_Fists
    // C_Fists Offsets
    C_Fists.m_bPlayingUninterruptableAct = findOffsetByName(j, "C_Fists", "m_bPlayingUninterruptableAct");
    C_Fists.m_nUninterruptableActivity = findOffsetByName(j, "C_Fists", "m_nUninterruptableActivity");

    // Atribuições para CInfoDynamicShadowHintBox
    // CInfoDynamicShadowHintBox Offsets
    CInfoDynamicShadowHintBox.m_vBoxMins = findOffsetByName(j, "CInfoDynamicShadowHintBox", "m_vBoxMins");
    CInfoDynamicShadowHintBox.m_vBoxMaxs = findOffsetByName(j, "CInfoDynamicShadowHintBox", "m_vBoxMaxs");

    // Atribuições para C_EnvCubemapFog
    // C_EnvCubemapFog Offsets
    C_EnvCubemapFog.m_flEndDistance = findOffsetByName(j, "C_EnvCubemapFog", "m_flEndDistance");
    C_EnvCubemapFog.m_flStartDistance = findOffsetByName(j, "C_EnvCubemapFog", "m_flStartDistance");
    C_EnvCubemapFog.m_flFogFalloffExponent = findOffsetByName(j, "C_EnvCubemapFog", "m_flFogFalloffExponent");
    C_EnvCubemapFog.m_bHeightFogEnabled = findOffsetByName(j, "C_EnvCubemapFog", "m_bHeightFogEnabled");
    C_EnvCubemapFog.m_flFogHeightWidth = findOffsetByName(j, "C_EnvCubemapFog", "m_flFogHeightWidth");
    C_EnvCubemapFog.m_flFogHeightEnd = findOffsetByName(j, "C_EnvCubemapFog", "m_flFogHeightEnd");
    C_EnvCubemapFog.m_flFogHeightStart = findOffsetByName(j, "C_EnvCubemapFog", "m_flFogHeightStart");
    C_EnvCubemapFog.m_flFogHeightExponent = findOffsetByName(j, "C_EnvCubemapFog", "m_flFogHeightExponent");
    C_EnvCubemapFog.m_flLODBias = findOffsetByName(j, "C_EnvCubemapFog", "m_flLODBias");
    C_EnvCubemapFog.m_bActive = findOffsetByName(j, "C_EnvCubemapFog", "m_bActive");
    C_EnvCubemapFog.m_bStartDisabled = findOffsetByName(j, "C_EnvCubemapFog", "m_bStartDisabled");
    C_EnvCubemapFog.m_flFogMaxOpacity = findOffsetByName(j, "C_EnvCubemapFog", "m_flFogMaxOpacity");
    C_EnvCubemapFog.m_nCubemapSourceType = findOffsetByName(j, "C_EnvCubemapFog", "m_nCubemapSourceType");
    C_EnvCubemapFog.m_hSkyMaterial = findOffsetByName(j, "C_EnvCubemapFog", "m_hSkyMaterial");
    C_EnvCubemapFog.m_iszSkyEntity = findOffsetByName(j, "C_EnvCubemapFog", "m_iszSkyEntity");
    C_EnvCubemapFog.m_hFogCubemapTexture = findOffsetByName(j, "C_EnvCubemapFog", "m_hFogCubemapTexture");
    C_EnvCubemapFog.m_bHasHeightFogEnd = findOffsetByName(j, "C_EnvCubemapFog", "m_bHasHeightFogEnd");
    C_EnvCubemapFog.m_bFirstTime = findOffsetByName(j, "C_EnvCubemapFog", "m_bFirstTime");

    // Atribuições para CCollisionProperty
    // CCollisionProperty Offsets
    CCollisionProperty.m_collisionAttribute = findOffsetByName(j, "CCollisionProperty", "m_collisionAttribute");
    CCollisionProperty.m_vecMins = findOffsetByName(j, "CCollisionProperty", "m_vecMins");
    CCollisionProperty.m_vecMaxs = findOffsetByName(j, "CCollisionProperty", "m_vecMaxs");
    CCollisionProperty.m_usSolidFlags = findOffsetByName(j, "CCollisionProperty", "m_usSolidFlags");
    CCollisionProperty.m_nSolidType = findOffsetByName(j, "CCollisionProperty", "m_nSolidType");
    CCollisionProperty.m_triggerBloat = findOffsetByName(j, "CCollisionProperty", "m_triggerBloat");
    CCollisionProperty.m_nSurroundType = findOffsetByName(j, "CCollisionProperty", "m_nSurroundType");
    CCollisionProperty.m_CollisionGroup = findOffsetByName(j, "CCollisionProperty", "m_CollisionGroup");
    CCollisionProperty.m_nEnablePhysics = findOffsetByName(j, "CCollisionProperty", "m_nEnablePhysics");
    CCollisionProperty.m_flBoundingRadius = findOffsetByName(j, "CCollisionProperty", "m_flBoundingRadius");
    CCollisionProperty.m_vecSpecifiedSurroundingMins = findOffsetByName(j, "CCollisionProperty", "m_vecSpecifiedSurroundingMins");
    CCollisionProperty.m_vecSpecifiedSurroundingMaxs = findOffsetByName(j, "CCollisionProperty", "m_vecSpecifiedSurroundingMaxs");
    CCollisionProperty.m_vecSurroundingMaxs = findOffsetByName(j, "CCollisionProperty", "m_vecSurroundingMaxs");
    CCollisionProperty.m_vecSurroundingMins = findOffsetByName(j, "CCollisionProperty", "m_vecSurroundingMins");
    CCollisionProperty.m_vCapsuleCenter1 = findOffsetByName(j, "CCollisionProperty", "m_vCapsuleCenter1");
    CCollisionProperty.m_vCapsuleCenter2 = findOffsetByName(j, "CCollisionProperty", "m_vCapsuleCenter2");
    CCollisionProperty.m_flCapsuleRadius = findOffsetByName(j, "CCollisionProperty", "m_flCapsuleRadius");

    // Atribuições para CNetworkedSequenceOperation
    // CNetworkedSequenceOperation Offsets
    CNetworkedSequenceOperation.m_hSequence = findOffsetByName(j, "CNetworkedSequenceOperation", "m_hSequence");
    CNetworkedSequenceOperation.m_flPrevCycle = findOffsetByName(j, "CNetworkedSequenceOperation", "m_flPrevCycle");
    CNetworkedSequenceOperation.m_flCycle = findOffsetByName(j, "CNetworkedSequenceOperation", "m_flCycle");
    CNetworkedSequenceOperation.m_flWeight = findOffsetByName(j, "CNetworkedSequenceOperation", "m_flWeight");
    CNetworkedSequenceOperation.m_bSequenceChangeNetworked = findOffsetByName(j, "CNetworkedSequenceOperation", "m_bSequenceChangeNetworked");
    CNetworkedSequenceOperation.m_bDiscontinuity = findOffsetByName(j, "CNetworkedSequenceOperation", "m_bDiscontinuity");
    CNetworkedSequenceOperation.m_flPrevCycleFromDiscontinuity = findOffsetByName(j, "CNetworkedSequenceOperation", "m_flPrevCycleFromDiscontinuity");
    CNetworkedSequenceOperation.m_flPrevCycleForAnimEventDetection = findOffsetByName(j, "CNetworkedSequenceOperation", "m_flPrevCycleForAnimEventDetection");

    // Atribuições para C_PlayerSprayDecal
    // C_PlayerSprayDecal Offsets
    C_PlayerSprayDecal.m_nUniqueID = findOffsetByName(j, "C_PlayerSprayDecal", "m_nUniqueID");
    C_PlayerSprayDecal.m_unAccountID = findOffsetByName(j, "C_PlayerSprayDecal", "m_unAccountID");
    C_PlayerSprayDecal.m_unTraceID = findOffsetByName(j, "C_PlayerSprayDecal", "m_unTraceID");
    C_PlayerSprayDecal.m_rtGcTime = findOffsetByName(j, "C_PlayerSprayDecal", "m_rtGcTime");
    C_PlayerSprayDecal.m_vecEndPos = findOffsetByName(j, "C_PlayerSprayDecal", "m_vecEndPos");
    C_PlayerSprayDecal.m_vecStart = findOffsetByName(j, "C_PlayerSprayDecal", "m_vecStart");
    C_PlayerSprayDecal.m_vecLeft = findOffsetByName(j, "C_PlayerSprayDecal", "m_vecLeft");
    C_PlayerSprayDecal.m_vecNormal = findOffsetByName(j, "C_PlayerSprayDecal", "m_vecNormal");
    C_PlayerSprayDecal.m_nPlayer = findOffsetByName(j, "C_PlayerSprayDecal", "m_nPlayer");
    C_PlayerSprayDecal.m_nEntity = findOffsetByName(j, "C_PlayerSprayDecal", "m_nEntity");
    C_PlayerSprayDecal.m_nHitbox = findOffsetByName(j, "C_PlayerSprayDecal", "m_nHitbox");
    C_PlayerSprayDecal.m_flCreationTime = findOffsetByName(j, "C_PlayerSprayDecal", "m_flCreationTime");
    C_PlayerSprayDecal.m_nTintID = findOffsetByName(j, "C_PlayerSprayDecal", "m_nTintID");
    C_PlayerSprayDecal.m_nVersion = findOffsetByName(j, "C_PlayerSprayDecal", "m_nVersion");
    C_PlayerSprayDecal.m_ubSignature = findOffsetByName(j, "C_PlayerSprayDecal", "m_ubSignature");
    C_PlayerSprayDecal.m_SprayRenderHelper = findOffsetByName(j, "C_PlayerSprayDecal", "m_SprayRenderHelper");

    // Atribuições para EntityRenderAttribute_t
    // EntityRenderAttribute_t Offsets
    EntityRenderAttribute_t.m_ID = findOffsetByName(j, "EntityRenderAttribute_t", "m_ID");
    EntityRenderAttribute_t.m_Values = findOffsetByName(j, "EntityRenderAttribute_t", "m_Values");

    // Atribuições para C_ShatterGlassShardPhysics
    // C_ShatterGlassShardPhysics Offsets
    C_ShatterGlassShardPhysics.m_ShardDesc = findOffsetByName(j, "C_ShatterGlassShardPhysics", "m_ShardDesc");

    // Atribuições para C_LightEntity
    // C_LightEntity Offsets
    C_LightEntity.m_CLightComponent = findOffsetByName(j, "C_LightEntity", "m_CLightComponent");

    // Atribuições para C_PlayerVisibility
    // C_PlayerVisibility Offsets
    C_PlayerVisibility.m_flVisibilityStrength = findOffsetByName(j, "C_PlayerVisibility", "m_flVisibilityStrength");
    C_PlayerVisibility.m_flFogDistanceMultiplier = findOffsetByName(j, "C_PlayerVisibility", "m_flFogDistanceMultiplier");
    C_PlayerVisibility.m_flFogMaxDensityMultiplier = findOffsetByName(j, "C_PlayerVisibility", "m_flFogMaxDensityMultiplier");
    C_PlayerVisibility.m_flFadeTime = findOffsetByName(j, "C_PlayerVisibility", "m_flFadeTime");
    C_PlayerVisibility.m_bStartDisabled = findOffsetByName(j, "C_PlayerVisibility", "m_bStartDisabled");
    C_PlayerVisibility.m_bIsEnabled = findOffsetByName(j, "C_PlayerVisibility", "m_bIsEnabled");

    // Atribuições para fogparams_t
    // fogparams_t Offsets
    fogparams_t.dirPrimary = findOffsetByName(j, "fogparams_t", "dirPrimary");
    fogparams_t.colorPrimary = findOffsetByName(j, "fogparams_t", "colorPrimary");
    fogparams_t.colorSecondary = findOffsetByName(j, "fogparams_t", "colorSecondary");
    fogparams_t.colorPrimaryLerpTo = findOffsetByName(j, "fogparams_t", "colorPrimaryLerpTo");
    fogparams_t.colorSecondaryLerpTo = findOffsetByName(j, "fogparams_t", "colorSecondaryLerpTo");
    fogparams_t.start = findOffsetByName(j, "fogparams_t", "start");
    fogparams_t.end = findOffsetByName(j, "fogparams_t", "end");
    fogparams_t.farz = findOffsetByName(j, "fogparams_t", "farz");
    fogparams_t.maxdensity = findOffsetByName(j, "fogparams_t", "maxdensity");
    fogparams_t.exponent = findOffsetByName(j, "fogparams_t", "exponent");
    fogparams_t.HDRColorScale = findOffsetByName(j, "fogparams_t", "HDRColorScale");
    fogparams_t.skyboxFogFactor = findOffsetByName(j, "fogparams_t", "skyboxFogFactor");
    fogparams_t.skyboxFogFactorLerpTo = findOffsetByName(j, "fogparams_t", "skyboxFogFactorLerpTo");
    fogparams_t.startLerpTo = findOffsetByName(j, "fogparams_t", "startLerpTo");
    fogparams_t.endLerpTo = findOffsetByName(j, "fogparams_t", "endLerpTo");
    fogparams_t.maxdensityLerpTo = findOffsetByName(j, "fogparams_t", "maxdensityLerpTo");
    fogparams_t.lerptime = findOffsetByName(j, "fogparams_t", "lerptime");
    fogparams_t.duration = findOffsetByName(j, "fogparams_t", "duration");
    fogparams_t.blendtobackground = findOffsetByName(j, "fogparams_t", "blendtobackground");
    fogparams_t.scattering = findOffsetByName(j, "fogparams_t", "scattering");
    fogparams_t.locallightscale = findOffsetByName(j, "fogparams_t", "locallightscale");
    fogparams_t.enable = findOffsetByName(j, "fogparams_t", "enable");
    fogparams_t.blend = findOffsetByName(j, "fogparams_t", "blend");
    fogparams_t.m_bNoReflectionFog = findOffsetByName(j, "fogparams_t", "m_bNoReflectionFog");
    fogparams_t.m_bPadding = findOffsetByName(j, "fogparams_t", "m_bPadding");

    // Atribuições para C_BaseFlex
    // C_BaseFlex Offsets
    C_BaseFlex.m_flexWeight = findOffsetByName(j, "C_BaseFlex", "m_flexWeight");
    C_BaseFlex.m_vLookTargetPosition = findOffsetByName(j, "C_BaseFlex", "m_vLookTargetPosition");
    C_BaseFlex.m_blinktoggle = findOffsetByName(j, "C_BaseFlex", "m_blinktoggle");
    C_BaseFlex.m_nLastFlexUpdateFrameCount = findOffsetByName(j, "C_BaseFlex", "m_nLastFlexUpdateFrameCount");
    C_BaseFlex.m_CachedViewTarget = findOffsetByName(j, "C_BaseFlex", "m_CachedViewTarget");
    C_BaseFlex.m_nNextSceneEventId = findOffsetByName(j, "C_BaseFlex", "m_nNextSceneEventId");
    C_BaseFlex.m_iBlink = findOffsetByName(j, "C_BaseFlex", "m_iBlink");
    C_BaseFlex.m_blinktime = findOffsetByName(j, "C_BaseFlex", "m_blinktime");
    C_BaseFlex.m_prevblinktoggle = findOffsetByName(j, "C_BaseFlex", "m_prevblinktoggle");
    C_BaseFlex.m_iJawOpen = findOffsetByName(j, "C_BaseFlex", "m_iJawOpen");
    C_BaseFlex.m_flJawOpenAmount = findOffsetByName(j, "C_BaseFlex", "m_flJawOpenAmount");
    C_BaseFlex.m_flBlinkAmount = findOffsetByName(j, "C_BaseFlex", "m_flBlinkAmount");
    C_BaseFlex.m_iMouthAttachment = findOffsetByName(j, "C_BaseFlex", "m_iMouthAttachment");
    C_BaseFlex.m_iEyeAttachment = findOffsetByName(j, "C_BaseFlex", "m_iEyeAttachment");
    C_BaseFlex.m_bResetFlexWeightsOnModelChange = findOffsetByName(j, "C_BaseFlex", "m_bResetFlexWeightsOnModelChange");
    C_BaseFlex.m_nEyeOcclusionRendererBone = findOffsetByName(j, "C_BaseFlex", "m_nEyeOcclusionRendererBone");
    C_BaseFlex.m_mEyeOcclusionRendererCameraToBoneTransform = findOffsetByName(j, "C_BaseFlex", "m_mEyeOcclusionRendererCameraToBoneTransform");
    C_BaseFlex.m_vEyeOcclusionRendererHalfExtent = findOffsetByName(j, "C_BaseFlex", "m_vEyeOcclusionRendererHalfExtent");
    C_BaseFlex.m_PhonemeClasses = findOffsetByName(j, "C_BaseFlex", "m_PhonemeClasses");

    // Atribuições para C_EnvSky
    // C_EnvSky Offsets
    C_EnvSky.m_hSkyMaterial = findOffsetByName(j, "C_EnvSky", "m_hSkyMaterial");
    C_EnvSky.m_hSkyMaterialLightingOnly = findOffsetByName(j, "C_EnvSky", "m_hSkyMaterialLightingOnly");
    C_EnvSky.m_bStartDisabled = findOffsetByName(j, "C_EnvSky", "m_bStartDisabled");
    C_EnvSky.m_vTintColor = findOffsetByName(j, "C_EnvSky", "m_vTintColor");
    C_EnvSky.m_vTintColorLightingOnly = findOffsetByName(j, "C_EnvSky", "m_vTintColorLightingOnly");
    C_EnvSky.m_flBrightnessScale = findOffsetByName(j, "C_EnvSky", "m_flBrightnessScale");
    C_EnvSky.m_nFogType = findOffsetByName(j, "C_EnvSky", "m_nFogType");
    C_EnvSky.m_flFogMinStart = findOffsetByName(j, "C_EnvSky", "m_flFogMinStart");
    C_EnvSky.m_flFogMinEnd = findOffsetByName(j, "C_EnvSky", "m_flFogMinEnd");
    C_EnvSky.m_flFogMaxStart = findOffsetByName(j, "C_EnvSky", "m_flFogMaxStart");
    C_EnvSky.m_flFogMaxEnd = findOffsetByName(j, "C_EnvSky", "m_flFogMaxEnd");
    C_EnvSky.m_bEnabled = findOffsetByName(j, "C_EnvSky", "m_bEnabled");

    // Atribuições para C_DynamicProp
    // C_DynamicProp Offsets
    C_DynamicProp.m_bUseHitboxesForRenderBox = findOffsetByName(j, "C_DynamicProp", "m_bUseHitboxesForRenderBox");
    C_DynamicProp.m_bUseAnimGraph = findOffsetByName(j, "C_DynamicProp", "m_bUseAnimGraph");
    C_DynamicProp.m_pOutputAnimBegun = findOffsetByName(j, "C_DynamicProp", "m_pOutputAnimBegun");
    C_DynamicProp.m_pOutputAnimOver = findOffsetByName(j, "C_DynamicProp", "m_pOutputAnimOver");
    C_DynamicProp.m_pOutputAnimLoopCycleOver = findOffsetByName(j, "C_DynamicProp", "m_pOutputAnimLoopCycleOver");
    C_DynamicProp.m_OnAnimReachedStart = findOffsetByName(j, "C_DynamicProp", "m_OnAnimReachedStart");
    C_DynamicProp.m_OnAnimReachedEnd = findOffsetByName(j, "C_DynamicProp", "m_OnAnimReachedEnd");
    C_DynamicProp.m_iszIdleAnim = findOffsetByName(j, "C_DynamicProp", "m_iszIdleAnim");
    C_DynamicProp.m_nIdleAnimLoopMode = findOffsetByName(j, "C_DynamicProp", "m_nIdleAnimLoopMode");
    C_DynamicProp.m_bRandomizeCycle = findOffsetByName(j, "C_DynamicProp", "m_bRandomizeCycle");
    C_DynamicProp.m_bStartDisabled = findOffsetByName(j, "C_DynamicProp", "m_bStartDisabled");
    C_DynamicProp.m_bFiredStartEndOutput = findOffsetByName(j, "C_DynamicProp", "m_bFiredStartEndOutput");
    C_DynamicProp.m_bForceNpcExclude = findOffsetByName(j, "C_DynamicProp", "m_bForceNpcExclude");
    C_DynamicProp.m_bCreateNonSolid = findOffsetByName(j, "C_DynamicProp", "m_bCreateNonSolid");
    C_DynamicProp.m_bIsOverrideProp = findOffsetByName(j, "C_DynamicProp", "m_bIsOverrideProp");
    C_DynamicProp.m_iInitialGlowState = findOffsetByName(j, "C_DynamicProp", "m_iInitialGlowState");
    C_DynamicProp.m_nGlowRange = findOffsetByName(j, "C_DynamicProp", "m_nGlowRange");
    C_DynamicProp.m_nGlowRangeMin = findOffsetByName(j, "C_DynamicProp", "m_nGlowRangeMin");
    C_DynamicProp.m_glowColor = findOffsetByName(j, "C_DynamicProp", "m_glowColor");
    C_DynamicProp.m_nGlowTeam = findOffsetByName(j, "C_DynamicProp", "m_nGlowTeam");
    C_DynamicProp.m_iCachedFrameCount = findOffsetByName(j, "C_DynamicProp", "m_iCachedFrameCount");
    C_DynamicProp.m_vecCachedRenderMins = findOffsetByName(j, "C_DynamicProp", "m_vecCachedRenderMins");
    C_DynamicProp.m_vecCachedRenderMaxs = findOffsetByName(j, "C_DynamicProp", "m_vecCachedRenderMaxs");

    // Atribuições para CPropDataComponent
    // CPropDataComponent Offsets
    CPropDataComponent.m_flDmgModBullet = findOffsetByName(j, "CPropDataComponent", "m_flDmgModBullet");
    CPropDataComponent.m_flDmgModClub = findOffsetByName(j, "CPropDataComponent", "m_flDmgModClub");
    CPropDataComponent.m_flDmgModExplosive = findOffsetByName(j, "CPropDataComponent", "m_flDmgModExplosive");
    CPropDataComponent.m_flDmgModFire = findOffsetByName(j, "CPropDataComponent", "m_flDmgModFire");
    CPropDataComponent.m_iszPhysicsDamageTableName = findOffsetByName(j, "CPropDataComponent", "m_iszPhysicsDamageTableName");
    CPropDataComponent.m_iszBasePropData = findOffsetByName(j, "CPropDataComponent", "m_iszBasePropData");
    CPropDataComponent.m_nInteractions = findOffsetByName(j, "CPropDataComponent", "m_nInteractions");
    CPropDataComponent.m_bSpawnMotionDisabled = findOffsetByName(j, "CPropDataComponent", "m_bSpawnMotionDisabled");
    CPropDataComponent.m_nDisableTakePhysicsDamageSpawnFlag = findOffsetByName(j, "CPropDataComponent", "m_nDisableTakePhysicsDamageSpawnFlag");
    CPropDataComponent.m_nMotionDisabledSpawnFlag = findOffsetByName(j, "CPropDataComponent", "m_nMotionDisabledSpawnFlag");

    // Atribuições para C_KeychainModule
    // C_KeychainModule Offsets
    C_KeychainModule.m_nKeychainDefID = findOffsetByName(j, "C_KeychainModule", "m_nKeychainDefID");
    C_KeychainModule.m_nKeychainSeed = findOffsetByName(j, "C_KeychainModule", "m_nKeychainSeed");

    // Atribuições para CCitadelSoundOpvarSetOBB
    // CCitadelSoundOpvarSetOBB Offsets
    CCitadelSoundOpvarSetOBB.m_iszStackName = findOffsetByName(j, "CCitadelSoundOpvarSetOBB", "m_iszStackName");
    CCitadelSoundOpvarSetOBB.m_iszOperatorName = findOffsetByName(j, "CCitadelSoundOpvarSetOBB", "m_iszOperatorName");
    CCitadelSoundOpvarSetOBB.m_iszOpvarName = findOffsetByName(j, "CCitadelSoundOpvarSetOBB", "m_iszOpvarName");
    CCitadelSoundOpvarSetOBB.m_vDistanceInnerMins = findOffsetByName(j, "CCitadelSoundOpvarSetOBB", "m_vDistanceInnerMins");
    CCitadelSoundOpvarSetOBB.m_vDistanceInnerMaxs = findOffsetByName(j, "CCitadelSoundOpvarSetOBB", "m_vDistanceInnerMaxs");
    CCitadelSoundOpvarSetOBB.m_vDistanceOuterMins = findOffsetByName(j, "CCitadelSoundOpvarSetOBB", "m_vDistanceOuterMins");
    CCitadelSoundOpvarSetOBB.m_vDistanceOuterMaxs = findOffsetByName(j, "CCitadelSoundOpvarSetOBB", "m_vDistanceOuterMaxs");
    CCitadelSoundOpvarSetOBB.m_nAABBDirection = findOffsetByName(j, "CCitadelSoundOpvarSetOBB", "m_nAABBDirection");

    // Atribuições para SellbackPurchaseEntry_t
    // SellbackPurchaseEntry_t Offsets
    SellbackPurchaseEntry_t.m_unDefIdx = findOffsetByName(j, "SellbackPurchaseEntry_t", "m_unDefIdx");
    SellbackPurchaseEntry_t.m_nCost = findOffsetByName(j, "SellbackPurchaseEntry_t", "m_nCost");
    SellbackPurchaseEntry_t.m_nPrevArmor = findOffsetByName(j, "SellbackPurchaseEntry_t", "m_nPrevArmor");
    SellbackPurchaseEntry_t.m_bPrevHelmet = findOffsetByName(j, "SellbackPurchaseEntry_t", "m_bPrevHelmet");
    SellbackPurchaseEntry_t.m_hItem = findOffsetByName(j, "SellbackPurchaseEntry_t", "m_hItem");

    // Atribuições para C_LocalTempEntity
    // C_LocalTempEntity Offsets
    C_LocalTempEntity.flags = findOffsetByName(j, "C_LocalTempEntity", "flags");
    C_LocalTempEntity.die = findOffsetByName(j, "C_LocalTempEntity", "die");
    C_LocalTempEntity.m_flFrameMax = findOffsetByName(j, "C_LocalTempEntity", "m_flFrameMax");
    C_LocalTempEntity.x = findOffsetByName(j, "C_LocalTempEntity", "x");
    C_LocalTempEntity.y = findOffsetByName(j, "C_LocalTempEntity", "y");
    C_LocalTempEntity.fadeSpeed = findOffsetByName(j, "C_LocalTempEntity", "fadeSpeed");
    C_LocalTempEntity.bounceFactor = findOffsetByName(j, "C_LocalTempEntity", "bounceFactor");
    C_LocalTempEntity.hitSound = findOffsetByName(j, "C_LocalTempEntity", "hitSound");
    C_LocalTempEntity.priority = findOffsetByName(j, "C_LocalTempEntity", "priority");
    C_LocalTempEntity.tentOffset = findOffsetByName(j, "C_LocalTempEntity", "tentOffset");
    C_LocalTempEntity.m_vecTempEntAngVelocity = findOffsetByName(j, "C_LocalTempEntity", "m_vecTempEntAngVelocity");
    C_LocalTempEntity.tempent_renderamt = findOffsetByName(j, "C_LocalTempEntity", "tempent_renderamt");
    C_LocalTempEntity.m_vecNormal = findOffsetByName(j, "C_LocalTempEntity", "m_vecNormal");
    C_LocalTempEntity.m_flSpriteScale = findOffsetByName(j, "C_LocalTempEntity", "m_flSpriteScale");
    C_LocalTempEntity.m_nFlickerFrame = findOffsetByName(j, "C_LocalTempEntity", "m_nFlickerFrame");
    C_LocalTempEntity.m_flFrameRate = findOffsetByName(j, "C_LocalTempEntity", "m_flFrameRate");
    C_LocalTempEntity.m_flFrame = findOffsetByName(j, "C_LocalTempEntity", "m_flFrame");
    C_LocalTempEntity.m_pszImpactEffect = findOffsetByName(j, "C_LocalTempEntity", "m_pszImpactEffect");
    C_LocalTempEntity.m_pszParticleEffect = findOffsetByName(j, "C_LocalTempEntity", "m_pszParticleEffect");
    C_LocalTempEntity.m_bParticleCollision = findOffsetByName(j, "C_LocalTempEntity", "m_bParticleCollision");
    C_LocalTempEntity.m_iLastCollisionFrame = findOffsetByName(j, "C_LocalTempEntity", "m_iLastCollisionFrame");
    C_LocalTempEntity.m_vLastCollisionOrigin = findOffsetByName(j, "C_LocalTempEntity", "m_vLastCollisionOrigin");
    C_LocalTempEntity.m_vecTempEntVelocity = findOffsetByName(j, "C_LocalTempEntity", "m_vecTempEntVelocity");
    C_LocalTempEntity.m_vecPrevAbsOrigin = findOffsetByName(j, "C_LocalTempEntity", "m_vecPrevAbsOrigin");
    C_LocalTempEntity.m_vecTempEntAcceleration = findOffsetByName(j, "C_LocalTempEntity", "m_vecTempEntAcceleration");

    // Atribuições para C_EnvWindShared__WindAveEvent_t
    // C_EnvWindShared__WindAveEvent_t Offsets
    C_EnvWindShared__WindAveEvent_t.m_flStartWindSpeed = findOffsetByName(j, "C_EnvWindShared__WindAveEvent_t", "m_flStartWindSpeed");
    C_EnvWindShared__WindAveEvent_t.m_flAveWindSpeed = findOffsetByName(j, "C_EnvWindShared__WindAveEvent_t", "m_flAveWindSpeed");

    // Atribuições para C_MolotovProjectile
    // C_MolotovProjectile Offsets
    C_MolotovProjectile.m_bIsIncGrenade = findOffsetByName(j, "C_MolotovProjectile", "m_bIsIncGrenade");

    // Atribuições para CInfoOffscreenPanoramaTexture
    // CInfoOffscreenPanoramaTexture Offsets
    CInfoOffscreenPanoramaTexture.m_bDisabled = findOffsetByName(j, "CInfoOffscreenPanoramaTexture", "m_bDisabled");
    CInfoOffscreenPanoramaTexture.m_nResolutionX = findOffsetByName(j, "CInfoOffscreenPanoramaTexture", "m_nResolutionX");
    CInfoOffscreenPanoramaTexture.m_nResolutionY = findOffsetByName(j, "CInfoOffscreenPanoramaTexture", "m_nResolutionY");
    CInfoOffscreenPanoramaTexture.m_szLayoutFileName = findOffsetByName(j, "CInfoOffscreenPanoramaTexture", "m_szLayoutFileName");
    CInfoOffscreenPanoramaTexture.m_RenderAttrName = findOffsetByName(j, "CInfoOffscreenPanoramaTexture", "m_RenderAttrName");
    CInfoOffscreenPanoramaTexture.m_TargetEntities = findOffsetByName(j, "CInfoOffscreenPanoramaTexture", "m_TargetEntities");
    CInfoOffscreenPanoramaTexture.m_nTargetChangeCount = findOffsetByName(j, "CInfoOffscreenPanoramaTexture", "m_nTargetChangeCount");
    CInfoOffscreenPanoramaTexture.m_vecCSSClasses = findOffsetByName(j, "CInfoOffscreenPanoramaTexture", "m_vecCSSClasses");
    CInfoOffscreenPanoramaTexture.m_bCheckCSSClasses = findOffsetByName(j, "CInfoOffscreenPanoramaTexture", "m_bCheckCSSClasses");

    // Atribuições para C_DynamicLight
    // C_DynamicLight Offsets
    C_DynamicLight.m_Flags = findOffsetByName(j, "C_DynamicLight", "m_Flags");
    C_DynamicLight.m_LightStyle = findOffsetByName(j, "C_DynamicLight", "m_LightStyle");
    C_DynamicLight.m_Radius = findOffsetByName(j, "C_DynamicLight", "m_Radius");
    C_DynamicLight.m_Exponent = findOffsetByName(j, "C_DynamicLight", "m_Exponent");
    C_DynamicLight.m_InnerAngle = findOffsetByName(j, "C_DynamicLight", "m_InnerAngle");
    C_DynamicLight.m_OuterAngle = findOffsetByName(j, "C_DynamicLight", "m_OuterAngle");
    C_DynamicLight.m_SpotRadius = findOffsetByName(j, "C_DynamicLight", "m_SpotRadius");

    // Atribuições para C_CSWeaponBase
    // C_CSWeaponBase Offsets
    C_CSWeaponBase.m_flFireSequenceStartTime = findOffsetByName(j, "C_CSWeaponBase", "m_flFireSequenceStartTime");
    C_CSWeaponBase.m_nFireSequenceStartTimeChange = findOffsetByName(j, "C_CSWeaponBase", "m_nFireSequenceStartTimeChange");
    C_CSWeaponBase.m_nFireSequenceStartTimeAck = findOffsetByName(j, "C_CSWeaponBase", "m_nFireSequenceStartTimeAck");
    C_CSWeaponBase.m_ePlayerFireEvent = findOffsetByName(j, "C_CSWeaponBase", "m_ePlayerFireEvent");
    C_CSWeaponBase.m_ePlayerFireEventAttackType = findOffsetByName(j, "C_CSWeaponBase", "m_ePlayerFireEventAttackType");
    C_CSWeaponBase.m_seqIdle = findOffsetByName(j, "C_CSWeaponBase", "m_seqIdle");
    C_CSWeaponBase.m_seqFirePrimary = findOffsetByName(j, "C_CSWeaponBase", "m_seqFirePrimary");
    C_CSWeaponBase.m_seqFireSecondary = findOffsetByName(j, "C_CSWeaponBase", "m_seqFireSecondary");
    C_CSWeaponBase.m_thirdPersonFireSequences = findOffsetByName(j, "C_CSWeaponBase", "m_thirdPersonFireSequences");
    C_CSWeaponBase.m_hCurrentThirdPersonSequence = findOffsetByName(j, "C_CSWeaponBase", "m_hCurrentThirdPersonSequence");
    C_CSWeaponBase.m_nSilencerBoneIndex = findOffsetByName(j, "C_CSWeaponBase", "m_nSilencerBoneIndex");
    C_CSWeaponBase.m_thirdPersonSequences = findOffsetByName(j, "C_CSWeaponBase", "m_thirdPersonSequences");
    C_CSWeaponBase.m_ClientPreviousWeaponState = findOffsetByName(j, "C_CSWeaponBase", "m_ClientPreviousWeaponState");
    C_CSWeaponBase.m_iState = findOffsetByName(j, "C_CSWeaponBase", "m_iState");
    C_CSWeaponBase.m_flCrosshairDistance = findOffsetByName(j, "C_CSWeaponBase", "m_flCrosshairDistance");
    C_CSWeaponBase.m_iAmmoLastCheck = findOffsetByName(j, "C_CSWeaponBase", "m_iAmmoLastCheck");
    C_CSWeaponBase.m_iAlpha = findOffsetByName(j, "C_CSWeaponBase", "m_iAlpha");
    C_CSWeaponBase.m_iScopeTextureID = findOffsetByName(j, "C_CSWeaponBase", "m_iScopeTextureID");
    C_CSWeaponBase.m_iCrosshairTextureID = findOffsetByName(j, "C_CSWeaponBase", "m_iCrosshairTextureID");
    C_CSWeaponBase.m_flGunAccuracyPositionDeprecated = findOffsetByName(j, "C_CSWeaponBase", "m_flGunAccuracyPositionDeprecated");
    C_CSWeaponBase.m_nLastEmptySoundCmdNum = findOffsetByName(j, "C_CSWeaponBase", "m_nLastEmptySoundCmdNum");
    C_CSWeaponBase.m_nViewModelIndex = findOffsetByName(j, "C_CSWeaponBase", "m_nViewModelIndex");
    C_CSWeaponBase.m_bReloadsWithClips = findOffsetByName(j, "C_CSWeaponBase", "m_bReloadsWithClips");
    C_CSWeaponBase.m_flTimeWeaponIdle = findOffsetByName(j, "C_CSWeaponBase", "m_flTimeWeaponIdle");
    C_CSWeaponBase.m_bFireOnEmpty = findOffsetByName(j, "C_CSWeaponBase", "m_bFireOnEmpty");
    C_CSWeaponBase.m_OnPlayerPickup = findOffsetByName(j, "C_CSWeaponBase", "m_OnPlayerPickup");
    C_CSWeaponBase.m_weaponMode = findOffsetByName(j, "C_CSWeaponBase", "m_weaponMode");
    C_CSWeaponBase.m_flTurningInaccuracyDelta = findOffsetByName(j, "C_CSWeaponBase", "m_flTurningInaccuracyDelta");
    C_CSWeaponBase.m_vecTurningInaccuracyEyeDirLast = findOffsetByName(j, "C_CSWeaponBase", "m_vecTurningInaccuracyEyeDirLast");
    C_CSWeaponBase.m_flTurningInaccuracy = findOffsetByName(j, "C_CSWeaponBase", "m_flTurningInaccuracy");
    C_CSWeaponBase.m_fAccuracyPenalty = findOffsetByName(j, "C_CSWeaponBase", "m_fAccuracyPenalty");
    C_CSWeaponBase.m_flLastAccuracyUpdateTime = findOffsetByName(j, "C_CSWeaponBase", "m_flLastAccuracyUpdateTime");
    C_CSWeaponBase.m_fAccuracySmoothedForZoom = findOffsetByName(j, "C_CSWeaponBase", "m_fAccuracySmoothedForZoom");
    C_CSWeaponBase.m_fScopeZoomEndTime = findOffsetByName(j, "C_CSWeaponBase", "m_fScopeZoomEndTime");
    C_CSWeaponBase.m_iRecoilIndex = findOffsetByName(j, "C_CSWeaponBase", "m_iRecoilIndex");
    C_CSWeaponBase.m_flRecoilIndex = findOffsetByName(j, "C_CSWeaponBase", "m_flRecoilIndex");
    C_CSWeaponBase.m_bBurstMode = findOffsetByName(j, "C_CSWeaponBase", "m_bBurstMode");
    C_CSWeaponBase.m_flLastBurstModeChangeTime = findOffsetByName(j, "C_CSWeaponBase", "m_flLastBurstModeChangeTime");
    C_CSWeaponBase.m_nPostponeFireReadyTicks = findOffsetByName(j, "C_CSWeaponBase", "m_nPostponeFireReadyTicks");
    C_CSWeaponBase.m_flPostponeFireReadyFrac = findOffsetByName(j, "C_CSWeaponBase", "m_flPostponeFireReadyFrac");
    C_CSWeaponBase.m_bInReload = findOffsetByName(j, "C_CSWeaponBase", "m_bInReload");
    C_CSWeaponBase.m_bReloadVisuallyComplete = findOffsetByName(j, "C_CSWeaponBase", "m_bReloadVisuallyComplete");
    C_CSWeaponBase.m_flDroppedAtTime = findOffsetByName(j, "C_CSWeaponBase", "m_flDroppedAtTime");
    C_CSWeaponBase.m_bIsHauledBack = findOffsetByName(j, "C_CSWeaponBase", "m_bIsHauledBack");
    C_CSWeaponBase.m_bSilencerOn = findOffsetByName(j, "C_CSWeaponBase", "m_bSilencerOn");
    C_CSWeaponBase.m_flTimeSilencerSwitchComplete = findOffsetByName(j, "C_CSWeaponBase", "m_flTimeSilencerSwitchComplete");
    C_CSWeaponBase.m_iOriginalTeamNumber = findOffsetByName(j, "C_CSWeaponBase", "m_iOriginalTeamNumber");
    C_CSWeaponBase.m_iMostRecentTeamNumber = findOffsetByName(j, "C_CSWeaponBase", "m_iMostRecentTeamNumber");
    C_CSWeaponBase.m_bDroppedNearBuyZone = findOffsetByName(j, "C_CSWeaponBase", "m_bDroppedNearBuyZone");
    C_CSWeaponBase.m_flNextAttackRenderTimeOffset = findOffsetByName(j, "C_CSWeaponBase", "m_flNextAttackRenderTimeOffset");
    C_CSWeaponBase.m_bClearWeaponIdentifyingUGC = findOffsetByName(j, "C_CSWeaponBase", "m_bClearWeaponIdentifyingUGC");
    C_CSWeaponBase.m_bVisualsDataSet = findOffsetByName(j, "C_CSWeaponBase", "m_bVisualsDataSet");
    C_CSWeaponBase.m_bOldFirstPersonSpectatedState = findOffsetByName(j, "C_CSWeaponBase", "m_bOldFirstPersonSpectatedState");
    C_CSWeaponBase.m_bUIWeapon = findOffsetByName(j, "C_CSWeaponBase", "m_bUIWeapon");
    C_CSWeaponBase.m_nCustomEconReloadEventId = findOffsetByName(j, "C_CSWeaponBase", "m_nCustomEconReloadEventId");
    C_CSWeaponBase.m_nextPrevOwnerUseTime = findOffsetByName(j, "C_CSWeaponBase", "m_nextPrevOwnerUseTime");
    C_CSWeaponBase.m_hPrevOwner = findOffsetByName(j, "C_CSWeaponBase", "m_hPrevOwner");
    C_CSWeaponBase.m_nDropTick = findOffsetByName(j, "C_CSWeaponBase", "m_nDropTick");
    C_CSWeaponBase.m_donated = findOffsetByName(j, "C_CSWeaponBase", "m_donated");
    C_CSWeaponBase.m_fLastShotTime = findOffsetByName(j, "C_CSWeaponBase", "m_fLastShotTime");
    C_CSWeaponBase.m_bWasOwnedByCT = findOffsetByName(j, "C_CSWeaponBase", "m_bWasOwnedByCT");
    C_CSWeaponBase.m_bWasOwnedByTerrorist = findOffsetByName(j, "C_CSWeaponBase", "m_bWasOwnedByTerrorist");
    C_CSWeaponBase.m_gunHeat = findOffsetByName(j, "C_CSWeaponBase", "m_gunHeat");
    C_CSWeaponBase.m_smokeAttachments = findOffsetByName(j, "C_CSWeaponBase", "m_smokeAttachments");
    C_CSWeaponBase.m_lastSmokeTime = findOffsetByName(j, "C_CSWeaponBase", "m_lastSmokeTime");
    C_CSWeaponBase.m_flNextClientFireBulletTime = findOffsetByName(j, "C_CSWeaponBase", "m_flNextClientFireBulletTime");
    C_CSWeaponBase.m_flNextClientFireBulletTime_Repredict = findOffsetByName(j, "C_CSWeaponBase", "m_flNextClientFireBulletTime_Repredict");
    C_CSWeaponBase.m_IronSightController = findOffsetByName(j, "C_CSWeaponBase", "m_IronSightController");
    C_CSWeaponBase.m_iIronSightMode = findOffsetByName(j, "C_CSWeaponBase", "m_iIronSightMode");
    C_CSWeaponBase.m_flLastLOSTraceFailureTime = findOffsetByName(j, "C_CSWeaponBase", "m_flLastLOSTraceFailureTime");
    C_CSWeaponBase.m_iNumEmptyAttacks = findOffsetByName(j, "C_CSWeaponBase", "m_iNumEmptyAttacks");
    C_CSWeaponBase.m_flLastMagDropRequestTime = findOffsetByName(j, "C_CSWeaponBase", "m_flLastMagDropRequestTime");
    C_CSWeaponBase.m_flWatTickOffset = findOffsetByName(j, "C_CSWeaponBase", "m_flWatTickOffset");

    // Atribuições para C_FuncElectrifiedVolume
    // C_FuncElectrifiedVolume Offsets
    C_FuncElectrifiedVolume.m_nAmbientEffect = findOffsetByName(j, "C_FuncElectrifiedVolume", "m_nAmbientEffect");
    C_FuncElectrifiedVolume.m_EffectName = findOffsetByName(j, "C_FuncElectrifiedVolume", "m_EffectName");
    C_FuncElectrifiedVolume.m_bState = findOffsetByName(j, "C_FuncElectrifiedVolume", "m_bState");

    // Atribuições para CCSPlayer_WeaponServices
    // CCSPlayer_WeaponServices Offsets
    CCSPlayer_WeaponServices.m_flNextAttack = findOffsetByName(j, "CCSPlayer_WeaponServices", "m_flNextAttack");
    CCSPlayer_WeaponServices.m_bIsLookingAtWeapon = findOffsetByName(j, "CCSPlayer_WeaponServices", "m_bIsLookingAtWeapon");
    CCSPlayer_WeaponServices.m_bIsHoldingLookAtWeapon = findOffsetByName(j, "CCSPlayer_WeaponServices", "m_bIsHoldingLookAtWeapon");
    CCSPlayer_WeaponServices.m_nOldShootPositionHistoryCount = findOffsetByName(j, "CCSPlayer_WeaponServices", "m_nOldShootPositionHistoryCount");
    CCSPlayer_WeaponServices.m_nOldInputHistoryCount = findOffsetByName(j, "CCSPlayer_WeaponServices", "m_nOldInputHistoryCount");

    // Atribuições para C_EnvDetailController
    // C_EnvDetailController Offsets
    C_EnvDetailController.m_flFadeStartDist = findOffsetByName(j, "C_EnvDetailController", "m_flFadeStartDist");
    C_EnvDetailController.m_flFadeEndDist = findOffsetByName(j, "C_EnvDetailController", "m_flFadeEndDist");

    // Atribuições para C_BaseEntity
    // C_BaseEntity Offsets
    C_BaseEntity.m_CBodyComponent = findOffsetByName(j, "C_BaseEntity", "m_CBodyComponent");
    C_BaseEntity.m_NetworkTransmitComponent = findOffsetByName(j, "C_BaseEntity", "m_NetworkTransmitComponent");
    C_BaseEntity.m_nLastThinkTick = findOffsetByName(j, "C_BaseEntity", "m_nLastThinkTick");
    C_BaseEntity.m_pGameSceneNode = findOffsetByName(j, "C_BaseEntity", "m_pGameSceneNode");
    C_BaseEntity.m_pRenderComponent = findOffsetByName(j, "C_BaseEntity", "m_pRenderComponent");
    C_BaseEntity.m_pCollision = findOffsetByName(j, "C_BaseEntity", "m_pCollision");
    C_BaseEntity.m_iMaxHealth = findOffsetByName(j, "C_BaseEntity", "m_iMaxHealth");
    C_BaseEntity.m_iHealth = findOffsetByName(j, "C_BaseEntity", "m_iHealth");
    C_BaseEntity.m_lifeState = findOffsetByName(j, "C_BaseEntity", "m_lifeState");
    C_BaseEntity.m_bTakesDamage = findOffsetByName(j, "C_BaseEntity", "m_bTakesDamage");
    C_BaseEntity.m_nTakeDamageFlags = findOffsetByName(j, "C_BaseEntity", "m_nTakeDamageFlags");
    C_BaseEntity.m_nPlatformType = findOffsetByName(j, "C_BaseEntity", "m_nPlatformType");
    C_BaseEntity.m_ubInterpolationFrame = findOffsetByName(j, "C_BaseEntity", "m_ubInterpolationFrame");
    C_BaseEntity.m_hSceneObjectController = findOffsetByName(j, "C_BaseEntity", "m_hSceneObjectController");
    C_BaseEntity.m_nNoInterpolationTick = findOffsetByName(j, "C_BaseEntity", "m_nNoInterpolationTick");
    C_BaseEntity.m_nVisibilityNoInterpolationTick = findOffsetByName(j, "C_BaseEntity", "m_nVisibilityNoInterpolationTick");
    C_BaseEntity.m_flProxyRandomValue = findOffsetByName(j, "C_BaseEntity", "m_flProxyRandomValue");
    C_BaseEntity.m_iEFlags = findOffsetByName(j, "C_BaseEntity", "m_iEFlags");
    C_BaseEntity.m_nWaterType = findOffsetByName(j, "C_BaseEntity", "m_nWaterType");
    C_BaseEntity.m_bInterpolateEvenWithNoModel = findOffsetByName(j, "C_BaseEntity", "m_bInterpolateEvenWithNoModel");
    C_BaseEntity.m_bPredictionEligible = findOffsetByName(j, "C_BaseEntity", "m_bPredictionEligible");
    C_BaseEntity.m_bApplyLayerMatchIDToModel = findOffsetByName(j, "C_BaseEntity", "m_bApplyLayerMatchIDToModel");
    C_BaseEntity.m_tokLayerMatchID = findOffsetByName(j, "C_BaseEntity", "m_tokLayerMatchID");
    C_BaseEntity.m_nSubclassID = findOffsetByName(j, "C_BaseEntity", "m_nSubclassID");
    C_BaseEntity.m_nSimulationTick = findOffsetByName(j, "C_BaseEntity", "m_nSimulationTick");
    C_BaseEntity.m_iCurrentThinkContext = findOffsetByName(j, "C_BaseEntity", "m_iCurrentThinkContext");
    C_BaseEntity.m_aThinkFunctions = findOffsetByName(j, "C_BaseEntity", "m_aThinkFunctions");
    C_BaseEntity.m_bDisabledContextThinks = findOffsetByName(j, "C_BaseEntity", "m_bDisabledContextThinks");
    C_BaseEntity.m_flAnimTime = findOffsetByName(j, "C_BaseEntity", "m_flAnimTime");
    C_BaseEntity.m_flSimulationTime = findOffsetByName(j, "C_BaseEntity", "m_flSimulationTime");
    C_BaseEntity.m_nSceneObjectOverrideFlags = findOffsetByName(j, "C_BaseEntity", "m_nSceneObjectOverrideFlags");
    C_BaseEntity.m_bHasSuccessfullyInterpolated = findOffsetByName(j, "C_BaseEntity", "m_bHasSuccessfullyInterpolated");
    C_BaseEntity.m_bHasAddedVarsToInterpolation = findOffsetByName(j, "C_BaseEntity", "m_bHasAddedVarsToInterpolation");
    C_BaseEntity.m_bRenderEvenWhenNotSuccessfullyInterpolated = findOffsetByName(j, "C_BaseEntity", "m_bRenderEvenWhenNotSuccessfullyInterpolated");
    C_BaseEntity.m_nInterpolationLatchDirtyFlags = findOffsetByName(j, "C_BaseEntity", "m_nInterpolationLatchDirtyFlags");
    C_BaseEntity.m_ListEntry = findOffsetByName(j, "C_BaseEntity", "m_ListEntry");
    C_BaseEntity.m_flCreateTime = findOffsetByName(j, "C_BaseEntity", "m_flCreateTime");
    C_BaseEntity.m_flSpeed = findOffsetByName(j, "C_BaseEntity", "m_flSpeed");
    C_BaseEntity.m_EntClientFlags = findOffsetByName(j, "C_BaseEntity", "m_EntClientFlags");
    C_BaseEntity.m_bClientSideRagdoll = findOffsetByName(j, "C_BaseEntity", "m_bClientSideRagdoll");
    C_BaseEntity.m_iTeamNum = findOffsetByName(j, "C_BaseEntity", "m_iTeamNum");
    C_BaseEntity.m_spawnflags = findOffsetByName(j, "C_BaseEntity", "m_spawnflags");
    C_BaseEntity.m_nNextThinkTick = findOffsetByName(j, "C_BaseEntity", "m_nNextThinkTick");
    C_BaseEntity.m_fFlags = findOffsetByName(j, "C_BaseEntity", "m_fFlags");
    C_BaseEntity.m_vecAbsVelocity = findOffsetByName(j, "C_BaseEntity", "m_vecAbsVelocity");
    C_BaseEntity.m_vecVelocity = findOffsetByName(j, "C_BaseEntity", "m_vecVelocity");
    C_BaseEntity.m_vecBaseVelocity = findOffsetByName(j, "C_BaseEntity", "m_vecBaseVelocity");
    C_BaseEntity.m_hEffectEntity = findOffsetByName(j, "C_BaseEntity", "m_hEffectEntity");
    C_BaseEntity.m_hOwnerEntity = findOffsetByName(j, "C_BaseEntity", "m_hOwnerEntity");
    C_BaseEntity.m_MoveCollide = findOffsetByName(j, "C_BaseEntity", "m_MoveCollide");
    C_BaseEntity.m_MoveType = findOffsetByName(j, "C_BaseEntity", "m_MoveType");
    C_BaseEntity.m_nActualMoveType = findOffsetByName(j, "C_BaseEntity", "m_nActualMoveType");
    C_BaseEntity.m_flWaterLevel = findOffsetByName(j, "C_BaseEntity", "m_flWaterLevel");
    C_BaseEntity.m_fEffects = findOffsetByName(j, "C_BaseEntity", "m_fEffects");
    C_BaseEntity.m_hGroundEntity = findOffsetByName(j, "C_BaseEntity", "m_hGroundEntity");
    C_BaseEntity.m_nGroundBodyIndex = findOffsetByName(j, "C_BaseEntity", "m_nGroundBodyIndex");
    C_BaseEntity.m_flFriction = findOffsetByName(j, "C_BaseEntity", "m_flFriction");
    C_BaseEntity.m_flElasticity = findOffsetByName(j, "C_BaseEntity", "m_flElasticity");
    C_BaseEntity.m_flGravityScale = findOffsetByName(j, "C_BaseEntity", "m_flGravityScale");
    C_BaseEntity.m_flTimeScale = findOffsetByName(j, "C_BaseEntity", "m_flTimeScale");
    C_BaseEntity.m_bAnimatedEveryTick = findOffsetByName(j, "C_BaseEntity", "m_bAnimatedEveryTick");
    C_BaseEntity.m_flNavIgnoreUntilTime = findOffsetByName(j, "C_BaseEntity", "m_flNavIgnoreUntilTime");
    C_BaseEntity.m_hThink = findOffsetByName(j, "C_BaseEntity", "m_hThink");
    C_BaseEntity.m_fBBoxVisFlags = findOffsetByName(j, "C_BaseEntity", "m_fBBoxVisFlags");
    C_BaseEntity.m_bPredictable = findOffsetByName(j, "C_BaseEntity", "m_bPredictable");
    C_BaseEntity.m_bRenderWithViewModels = findOffsetByName(j, "C_BaseEntity", "m_bRenderWithViewModels");
    C_BaseEntity.m_nSplitUserPlayerPredictionSlot = findOffsetByName(j, "C_BaseEntity", "m_nSplitUserPlayerPredictionSlot");
    C_BaseEntity.m_nFirstPredictableCommand = findOffsetByName(j, "C_BaseEntity", "m_nFirstPredictableCommand");
    C_BaseEntity.m_nLastPredictableCommand = findOffsetByName(j, "C_BaseEntity", "m_nLastPredictableCommand");
    C_BaseEntity.m_hOldMoveParent = findOffsetByName(j, "C_BaseEntity", "m_hOldMoveParent");
    C_BaseEntity.m_Particles = findOffsetByName(j, "C_BaseEntity", "m_Particles");
    C_BaseEntity.m_vecPredictedScriptFloats = findOffsetByName(j, "C_BaseEntity", "m_vecPredictedScriptFloats");
    C_BaseEntity.m_vecPredictedScriptFloatIDs = findOffsetByName(j, "C_BaseEntity", "m_vecPredictedScriptFloatIDs");
    C_BaseEntity.m_nNextScriptVarRecordID = findOffsetByName(j, "C_BaseEntity", "m_nNextScriptVarRecordID");
    C_BaseEntity.m_vecAngVelocity = findOffsetByName(j, "C_BaseEntity", "m_vecAngVelocity");
    C_BaseEntity.m_DataChangeEventRef = findOffsetByName(j, "C_BaseEntity", "m_DataChangeEventRef");
    C_BaseEntity.m_dependencies = findOffsetByName(j, "C_BaseEntity", "m_dependencies");
    C_BaseEntity.m_nCreationTick = findOffsetByName(j, "C_BaseEntity", "m_nCreationTick");
    C_BaseEntity.m_bAnimTimeChanged = findOffsetByName(j, "C_BaseEntity", "m_bAnimTimeChanged");
    C_BaseEntity.m_bSimulationTimeChanged = findOffsetByName(j, "C_BaseEntity", "m_bSimulationTimeChanged");
    C_BaseEntity.m_sUniqueHammerID = findOffsetByName(j, "C_BaseEntity", "m_sUniqueHammerID");
    C_BaseEntity.m_nBloodType = findOffsetByName(j, "C_BaseEntity", "m_nBloodType");

    // Atribuições para CEntityIdentity
    // CEntityIdentity Offsets
    CEntityIdentity.m_nameStringableIndex = findOffsetByName(j, "CEntityIdentity", "m_nameStringableIndex");
    CEntityIdentity.m_name = findOffsetByName(j, "CEntityIdentity", "m_name");
    CEntityIdentity.m_designerName = findOffsetByName(j, "CEntityIdentity", "m_designerName");
    CEntityIdentity.m_flags = findOffsetByName(j, "CEntityIdentity", "m_flags");
    CEntityIdentity.m_worldGroupId = findOffsetByName(j, "CEntityIdentity", "m_worldGroupId");
    CEntityIdentity.m_fDataObjectTypes = findOffsetByName(j, "CEntityIdentity", "m_fDataObjectTypes");
    CEntityIdentity.m_PathIndex = findOffsetByName(j, "CEntityIdentity", "m_PathIndex");
    CEntityIdentity.m_pPrev = findOffsetByName(j, "CEntityIdentity", "m_pPrev");
    CEntityIdentity.m_pNext = findOffsetByName(j, "CEntityIdentity", "m_pNext");
    CEntityIdentity.m_pPrevByClass = findOffsetByName(j, "CEntityIdentity", "m_pPrevByClass");
    CEntityIdentity.m_pNextByClass = findOffsetByName(j, "CEntityIdentity", "m_pNextByClass");

    // Atribuições para C_StattrakModule
    // C_StattrakModule Offsets
    C_StattrakModule.m_bKnife = findOffsetByName(j, "C_StattrakModule", "m_bKnife");

    // Atribuições para C_PhysicsProp
    // C_PhysicsProp Offsets
    C_PhysicsProp.m_bAwake = findOffsetByName(j, "C_PhysicsProp", "m_bAwake");

    // Atribuições para C_BreakableProp
    // C_BreakableProp Offsets
    C_BreakableProp.m_CPropDataComponent = findOffsetByName(j, "C_BreakableProp", "m_CPropDataComponent");
    C_BreakableProp.m_OnBreak = findOffsetByName(j, "C_BreakableProp", "m_OnBreak");
    C_BreakableProp.m_OnHealthChanged = findOffsetByName(j, "C_BreakableProp", "m_OnHealthChanged");
    C_BreakableProp.m_OnTakeDamage = findOffsetByName(j, "C_BreakableProp", "m_OnTakeDamage");
    C_BreakableProp.m_impactEnergyScale = findOffsetByName(j, "C_BreakableProp", "m_impactEnergyScale");
    C_BreakableProp.m_iMinHealthDmg = findOffsetByName(j, "C_BreakableProp", "m_iMinHealthDmg");
    C_BreakableProp.m_flPressureDelay = findOffsetByName(j, "C_BreakableProp", "m_flPressureDelay");
    C_BreakableProp.m_flDefBurstScale = findOffsetByName(j, "C_BreakableProp", "m_flDefBurstScale");
    C_BreakableProp.m_vDefBurstOffset = findOffsetByName(j, "C_BreakableProp", "m_vDefBurstOffset");
    C_BreakableProp.m_hBreaker = findOffsetByName(j, "C_BreakableProp", "m_hBreaker");
    C_BreakableProp.m_PerformanceMode = findOffsetByName(j, "C_BreakableProp", "m_PerformanceMode");
    C_BreakableProp.m_flPreventDamageBeforeTime = findOffsetByName(j, "C_BreakableProp", "m_flPreventDamageBeforeTime");
    C_BreakableProp.m_BreakableContentsType = findOffsetByName(j, "C_BreakableProp", "m_BreakableContentsType");
    C_BreakableProp.m_strBreakableContentsPropGroupOverride = findOffsetByName(j, "C_BreakableProp", "m_strBreakableContentsPropGroupOverride");
    C_BreakableProp.m_strBreakableContentsParticleOverride = findOffsetByName(j, "C_BreakableProp", "m_strBreakableContentsParticleOverride");
    C_BreakableProp.m_bHasBreakPiecesOrCommands = findOffsetByName(j, "C_BreakableProp", "m_bHasBreakPiecesOrCommands");
    C_BreakableProp.m_explodeDamage = findOffsetByName(j, "C_BreakableProp", "m_explodeDamage");
    C_BreakableProp.m_explodeRadius = findOffsetByName(j, "C_BreakableProp", "m_explodeRadius");
    C_BreakableProp.m_explosionDelay = findOffsetByName(j, "C_BreakableProp", "m_explosionDelay");
    C_BreakableProp.m_explosionBuildupSound = findOffsetByName(j, "C_BreakableProp", "m_explosionBuildupSound");
    C_BreakableProp.m_explosionCustomEffect = findOffsetByName(j, "C_BreakableProp", "m_explosionCustomEffect");
    C_BreakableProp.m_explosionCustomSound = findOffsetByName(j, "C_BreakableProp", "m_explosionCustomSound");
    C_BreakableProp.m_explosionModifier = findOffsetByName(j, "C_BreakableProp", "m_explosionModifier");
    C_BreakableProp.m_hPhysicsAttacker = findOffsetByName(j, "C_BreakableProp", "m_hPhysicsAttacker");
    C_BreakableProp.m_flLastPhysicsInfluenceTime = findOffsetByName(j, "C_BreakableProp", "m_flLastPhysicsInfluenceTime");
    C_BreakableProp.m_flDefaultFadeScale = findOffsetByName(j, "C_BreakableProp", "m_flDefaultFadeScale");
    C_BreakableProp.m_hLastAttacker = findOffsetByName(j, "C_BreakableProp", "m_hLastAttacker");
    C_BreakableProp.m_hFlareEnt = findOffsetByName(j, "C_BreakableProp", "m_hFlareEnt");
    C_BreakableProp.m_noGhostCollision = findOffsetByName(j, "C_BreakableProp", "m_noGhostCollision");

    // Atribuições para C_Beam
    // C_Beam Offsets
    C_Beam.m_flFrameRate = findOffsetByName(j, "C_Beam", "m_flFrameRate");
    C_Beam.m_flHDRColorScale = findOffsetByName(j, "C_Beam", "m_flHDRColorScale");
    C_Beam.m_flFireTime = findOffsetByName(j, "C_Beam", "m_flFireTime");
    C_Beam.m_flDamage = findOffsetByName(j, "C_Beam", "m_flDamage");
    C_Beam.m_nNumBeamEnts = findOffsetByName(j, "C_Beam", "m_nNumBeamEnts");
    C_Beam.m_queryHandleHalo = findOffsetByName(j, "C_Beam", "m_queryHandleHalo");
    C_Beam.m_hBaseMaterial = findOffsetByName(j, "C_Beam", "m_hBaseMaterial");
    C_Beam.m_nHaloIndex = findOffsetByName(j, "C_Beam", "m_nHaloIndex");
    C_Beam.m_nBeamType = findOffsetByName(j, "C_Beam", "m_nBeamType");
    C_Beam.m_nBeamFlags = findOffsetByName(j, "C_Beam", "m_nBeamFlags");
    C_Beam.m_hAttachEntity = findOffsetByName(j, "C_Beam", "m_hAttachEntity");
    C_Beam.m_nAttachIndex = findOffsetByName(j, "C_Beam", "m_nAttachIndex");
    C_Beam.m_fWidth = findOffsetByName(j, "C_Beam", "m_fWidth");
    C_Beam.m_fEndWidth = findOffsetByName(j, "C_Beam", "m_fEndWidth");
    C_Beam.m_fFadeLength = findOffsetByName(j, "C_Beam", "m_fFadeLength");
    C_Beam.m_fHaloScale = findOffsetByName(j, "C_Beam", "m_fHaloScale");
    C_Beam.m_fAmplitude = findOffsetByName(j, "C_Beam", "m_fAmplitude");
    C_Beam.m_fStartFrame = findOffsetByName(j, "C_Beam", "m_fStartFrame");
    C_Beam.m_fSpeed = findOffsetByName(j, "C_Beam", "m_fSpeed");
    C_Beam.m_flFrame = findOffsetByName(j, "C_Beam", "m_flFrame");
    C_Beam.m_nClipStyle = findOffsetByName(j, "C_Beam", "m_nClipStyle");
    C_Beam.m_bTurnedOff = findOffsetByName(j, "C_Beam", "m_bTurnedOff");
    C_Beam.m_vecEndPos = findOffsetByName(j, "C_Beam", "m_vecEndPos");
    C_Beam.m_hEndEntity = findOffsetByName(j, "C_Beam", "m_hEndEntity");

    // Atribuições para C_CSGO_TeamPreviewCharacterPosition
    // C_CSGO_TeamPreviewCharacterPosition Offsets
    C_CSGO_TeamPreviewCharacterPosition.m_nVariant = findOffsetByName(j, "C_CSGO_TeamPreviewCharacterPosition", "m_nVariant");
    C_CSGO_TeamPreviewCharacterPosition.m_nRandom = findOffsetByName(j, "C_CSGO_TeamPreviewCharacterPosition", "m_nRandom");
    C_CSGO_TeamPreviewCharacterPosition.m_nOrdinal = findOffsetByName(j, "C_CSGO_TeamPreviewCharacterPosition", "m_nOrdinal");
    C_CSGO_TeamPreviewCharacterPosition.m_sWeaponName = findOffsetByName(j, "C_CSGO_TeamPreviewCharacterPosition", "m_sWeaponName");
    C_CSGO_TeamPreviewCharacterPosition.m_xuid = findOffsetByName(j, "C_CSGO_TeamPreviewCharacterPosition", "m_xuid");
    C_CSGO_TeamPreviewCharacterPosition.m_agentItem = findOffsetByName(j, "C_CSGO_TeamPreviewCharacterPosition", "m_agentItem");
    C_CSGO_TeamPreviewCharacterPosition.m_glovesItem = findOffsetByName(j, "C_CSGO_TeamPreviewCharacterPosition", "m_glovesItem");
    C_CSGO_TeamPreviewCharacterPosition.m_weaponItem = findOffsetByName(j, "C_CSGO_TeamPreviewCharacterPosition", "m_weaponItem");

    // Atribuições para C_EnvScreenOverlay
    // C_EnvScreenOverlay Offsets
    C_EnvScreenOverlay.m_iszOverlayNames = findOffsetByName(j, "C_EnvScreenOverlay", "m_iszOverlayNames");
    C_EnvScreenOverlay.m_flOverlayTimes = findOffsetByName(j, "C_EnvScreenOverlay", "m_flOverlayTimes");
    C_EnvScreenOverlay.m_flStartTime = findOffsetByName(j, "C_EnvScreenOverlay", "m_flStartTime");
    C_EnvScreenOverlay.m_iDesiredOverlay = findOffsetByName(j, "C_EnvScreenOverlay", "m_iDesiredOverlay");
    C_EnvScreenOverlay.m_bIsActive = findOffsetByName(j, "C_EnvScreenOverlay", "m_bIsActive");
    C_EnvScreenOverlay.m_bWasActive = findOffsetByName(j, "C_EnvScreenOverlay", "m_bWasActive");
    C_EnvScreenOverlay.m_iCachedDesiredOverlay = findOffsetByName(j, "C_EnvScreenOverlay", "m_iCachedDesiredOverlay");
    C_EnvScreenOverlay.m_iCurrentOverlay = findOffsetByName(j, "C_EnvScreenOverlay", "m_iCurrentOverlay");
    C_EnvScreenOverlay.m_flCurrentOverlayTime = findOffsetByName(j, "C_EnvScreenOverlay", "m_flCurrentOverlayTime");

    // Atribuições para CCSWeaponBaseVData
    // CCSWeaponBaseVData Offsets
    CCSWeaponBaseVData.m_WeaponType = findOffsetByName(j, "CCSWeaponBaseVData", "m_WeaponType");
    CCSWeaponBaseVData.m_WeaponCategory = findOffsetByName(j, "CCSWeaponBaseVData", "m_WeaponCategory");
    CCSWeaponBaseVData.m_szViewModel = findOffsetByName(j, "CCSWeaponBaseVData", "m_szViewModel");
    CCSWeaponBaseVData.m_szPlayerModel = findOffsetByName(j, "CCSWeaponBaseVData", "m_szPlayerModel");
    CCSWeaponBaseVData.m_szWorldDroppedModel = findOffsetByName(j, "CCSWeaponBaseVData", "m_szWorldDroppedModel");
    CCSWeaponBaseVData.m_szAimsightLensMaskModel = findOffsetByName(j, "CCSWeaponBaseVData", "m_szAimsightLensMaskModel");
    CCSWeaponBaseVData.m_szMagazineModel = findOffsetByName(j, "CCSWeaponBaseVData", "m_szMagazineModel");
    CCSWeaponBaseVData.m_szHeatEffect = findOffsetByName(j, "CCSWeaponBaseVData", "m_szHeatEffect");
    CCSWeaponBaseVData.m_szEjectBrassEffect = findOffsetByName(j, "CCSWeaponBaseVData", "m_szEjectBrassEffect");
    CCSWeaponBaseVData.m_szMuzzleFlashParticleAlt = findOffsetByName(j, "CCSWeaponBaseVData", "m_szMuzzleFlashParticleAlt");
    CCSWeaponBaseVData.m_szMuzzleFlashThirdPersonParticle = findOffsetByName(j, "CCSWeaponBaseVData", "m_szMuzzleFlashThirdPersonParticle");
    CCSWeaponBaseVData.m_szMuzzleFlashThirdPersonParticleAlt = findOffsetByName(j, "CCSWeaponBaseVData", "m_szMuzzleFlashThirdPersonParticleAlt");
    CCSWeaponBaseVData.m_szTracerParticle = findOffsetByName(j, "CCSWeaponBaseVData", "m_szTracerParticle");
    CCSWeaponBaseVData.m_GearSlot = findOffsetByName(j, "CCSWeaponBaseVData", "m_GearSlot");
    CCSWeaponBaseVData.m_GearSlotPosition = findOffsetByName(j, "CCSWeaponBaseVData", "m_GearSlotPosition");
    CCSWeaponBaseVData.m_DefaultLoadoutSlot = findOffsetByName(j, "CCSWeaponBaseVData", "m_DefaultLoadoutSlot");
    CCSWeaponBaseVData.m_sWrongTeamMsg = findOffsetByName(j, "CCSWeaponBaseVData", "m_sWrongTeamMsg");
    CCSWeaponBaseVData.m_nPrice = findOffsetByName(j, "CCSWeaponBaseVData", "m_nPrice");
    CCSWeaponBaseVData.m_nKillAward = findOffsetByName(j, "CCSWeaponBaseVData", "m_nKillAward");
    CCSWeaponBaseVData.m_nPrimaryReserveAmmoMax = findOffsetByName(j, "CCSWeaponBaseVData", "m_nPrimaryReserveAmmoMax");
    CCSWeaponBaseVData.m_nSecondaryReserveAmmoMax = findOffsetByName(j, "CCSWeaponBaseVData", "m_nSecondaryReserveAmmoMax");
    CCSWeaponBaseVData.m_bMeleeWeapon = findOffsetByName(j, "CCSWeaponBaseVData", "m_bMeleeWeapon");
    CCSWeaponBaseVData.m_bHasBurstMode = findOffsetByName(j, "CCSWeaponBaseVData", "m_bHasBurstMode");
    CCSWeaponBaseVData.m_bIsRevolver = findOffsetByName(j, "CCSWeaponBaseVData", "m_bIsRevolver");
    CCSWeaponBaseVData.m_bCannotShootUnderwater = findOffsetByName(j, "CCSWeaponBaseVData", "m_bCannotShootUnderwater");
    CCSWeaponBaseVData.m_szName = findOffsetByName(j, "CCSWeaponBaseVData", "m_szName");
    CCSWeaponBaseVData.m_szAnimExtension = findOffsetByName(j, "CCSWeaponBaseVData", "m_szAnimExtension");
    CCSWeaponBaseVData.m_eSilencerType = findOffsetByName(j, "CCSWeaponBaseVData", "m_eSilencerType");
    CCSWeaponBaseVData.m_nCrosshairMinDistance = findOffsetByName(j, "CCSWeaponBaseVData", "m_nCrosshairMinDistance");
    CCSWeaponBaseVData.m_nCrosshairDeltaDistance = findOffsetByName(j, "CCSWeaponBaseVData", "m_nCrosshairDeltaDistance");
    CCSWeaponBaseVData.m_bIsFullAuto = findOffsetByName(j, "CCSWeaponBaseVData", "m_bIsFullAuto");
    CCSWeaponBaseVData.m_nNumBullets = findOffsetByName(j, "CCSWeaponBaseVData", "m_nNumBullets");
    CCSWeaponBaseVData.m_flCycleTime = findOffsetByName(j, "CCSWeaponBaseVData", "m_flCycleTime");
    CCSWeaponBaseVData.m_flMaxSpeed = findOffsetByName(j, "CCSWeaponBaseVData", "m_flMaxSpeed");
    CCSWeaponBaseVData.m_flSpread = findOffsetByName(j, "CCSWeaponBaseVData", "m_flSpread");
    CCSWeaponBaseVData.m_flInaccuracyCrouch = findOffsetByName(j, "CCSWeaponBaseVData", "m_flInaccuracyCrouch");
    CCSWeaponBaseVData.m_flInaccuracyStand = findOffsetByName(j, "CCSWeaponBaseVData", "m_flInaccuracyStand");
    CCSWeaponBaseVData.m_flInaccuracyJump = findOffsetByName(j, "CCSWeaponBaseVData", "m_flInaccuracyJump");
    CCSWeaponBaseVData.m_flInaccuracyLand = findOffsetByName(j, "CCSWeaponBaseVData", "m_flInaccuracyLand");
    CCSWeaponBaseVData.m_flInaccuracyLadder = findOffsetByName(j, "CCSWeaponBaseVData", "m_flInaccuracyLadder");
    CCSWeaponBaseVData.m_flInaccuracyFire = findOffsetByName(j, "CCSWeaponBaseVData", "m_flInaccuracyFire");
    CCSWeaponBaseVData.m_flInaccuracyMove = findOffsetByName(j, "CCSWeaponBaseVData", "m_flInaccuracyMove");
    CCSWeaponBaseVData.m_flRecoilAngle = findOffsetByName(j, "CCSWeaponBaseVData", "m_flRecoilAngle");
    CCSWeaponBaseVData.m_flRecoilAngleVariance = findOffsetByName(j, "CCSWeaponBaseVData", "m_flRecoilAngleVariance");
    CCSWeaponBaseVData.m_flRecoilMagnitude = findOffsetByName(j, "CCSWeaponBaseVData", "m_flRecoilMagnitude");
    CCSWeaponBaseVData.m_flRecoilMagnitudeVariance = findOffsetByName(j, "CCSWeaponBaseVData", "m_flRecoilMagnitudeVariance");
    CCSWeaponBaseVData.m_nTracerFrequency = findOffsetByName(j, "CCSWeaponBaseVData", "m_nTracerFrequency");
    CCSWeaponBaseVData.m_flInaccuracyJumpInitial = findOffsetByName(j, "CCSWeaponBaseVData", "m_flInaccuracyJumpInitial");
    CCSWeaponBaseVData.m_flInaccuracyJumpApex = findOffsetByName(j, "CCSWeaponBaseVData", "m_flInaccuracyJumpApex");
    CCSWeaponBaseVData.m_flInaccuracyReload = findOffsetByName(j, "CCSWeaponBaseVData", "m_flInaccuracyReload");
    CCSWeaponBaseVData.m_nRecoilSeed = findOffsetByName(j, "CCSWeaponBaseVData", "m_nRecoilSeed");
    CCSWeaponBaseVData.m_nSpreadSeed = findOffsetByName(j, "CCSWeaponBaseVData", "m_nSpreadSeed");
    CCSWeaponBaseVData.m_flTimeToIdleAfterFire = findOffsetByName(j, "CCSWeaponBaseVData", "m_flTimeToIdleAfterFire");
    CCSWeaponBaseVData.m_flIdleInterval = findOffsetByName(j, "CCSWeaponBaseVData", "m_flIdleInterval");
    CCSWeaponBaseVData.m_flAttackMovespeedFactor = findOffsetByName(j, "CCSWeaponBaseVData", "m_flAttackMovespeedFactor");
    CCSWeaponBaseVData.m_flHeatPerShot = findOffsetByName(j, "CCSWeaponBaseVData", "m_flHeatPerShot");
    CCSWeaponBaseVData.m_flInaccuracyPitchShift = findOffsetByName(j, "CCSWeaponBaseVData", "m_flInaccuracyPitchShift");
    CCSWeaponBaseVData.m_flInaccuracyAltSoundThreshold = findOffsetByName(j, "CCSWeaponBaseVData", "m_flInaccuracyAltSoundThreshold");
    CCSWeaponBaseVData.m_flBotAudibleRange = findOffsetByName(j, "CCSWeaponBaseVData", "m_flBotAudibleRange");
    CCSWeaponBaseVData.m_szUseRadioSubtitle = findOffsetByName(j, "CCSWeaponBaseVData", "m_szUseRadioSubtitle");
    CCSWeaponBaseVData.m_bUnzoomsAfterShot = findOffsetByName(j, "CCSWeaponBaseVData", "m_bUnzoomsAfterShot");
    CCSWeaponBaseVData.m_bHideViewModelWhenZoomed = findOffsetByName(j, "CCSWeaponBaseVData", "m_bHideViewModelWhenZoomed");
    CCSWeaponBaseVData.m_nZoomLevels = findOffsetByName(j, "CCSWeaponBaseVData", "m_nZoomLevels");
    CCSWeaponBaseVData.m_nZoomFOV1 = findOffsetByName(j, "CCSWeaponBaseVData", "m_nZoomFOV1");
    CCSWeaponBaseVData.m_nZoomFOV2 = findOffsetByName(j, "CCSWeaponBaseVData", "m_nZoomFOV2");
    CCSWeaponBaseVData.m_flZoomTime0 = findOffsetByName(j, "CCSWeaponBaseVData", "m_flZoomTime0");
    CCSWeaponBaseVData.m_flZoomTime1 = findOffsetByName(j, "CCSWeaponBaseVData", "m_flZoomTime1");
    CCSWeaponBaseVData.m_flZoomTime2 = findOffsetByName(j, "CCSWeaponBaseVData", "m_flZoomTime2");
    CCSWeaponBaseVData.m_flIronSightPullUpSpeed = findOffsetByName(j, "CCSWeaponBaseVData", "m_flIronSightPullUpSpeed");
    CCSWeaponBaseVData.m_flIronSightPutDownSpeed = findOffsetByName(j, "CCSWeaponBaseVData", "m_flIronSightPutDownSpeed");
    CCSWeaponBaseVData.m_flIronSightFOV = findOffsetByName(j, "CCSWeaponBaseVData", "m_flIronSightFOV");
    CCSWeaponBaseVData.m_flIronSightPivotForward = findOffsetByName(j, "CCSWeaponBaseVData", "m_flIronSightPivotForward");
    CCSWeaponBaseVData.m_flIronSightLooseness = findOffsetByName(j, "CCSWeaponBaseVData", "m_flIronSightLooseness");
    CCSWeaponBaseVData.m_angPivotAngle = findOffsetByName(j, "CCSWeaponBaseVData", "m_angPivotAngle");
    CCSWeaponBaseVData.m_vecIronSightEyePos = findOffsetByName(j, "CCSWeaponBaseVData", "m_vecIronSightEyePos");
    CCSWeaponBaseVData.m_nDamage = findOffsetByName(j, "CCSWeaponBaseVData", "m_nDamage");
    CCSWeaponBaseVData.m_flHeadshotMultiplier = findOffsetByName(j, "CCSWeaponBaseVData", "m_flHeadshotMultiplier");
    CCSWeaponBaseVData.m_flArmorRatio = findOffsetByName(j, "CCSWeaponBaseVData", "m_flArmorRatio");
    CCSWeaponBaseVData.m_flPenetration = findOffsetByName(j, "CCSWeaponBaseVData", "m_flPenetration");
    CCSWeaponBaseVData.m_flRange = findOffsetByName(j, "CCSWeaponBaseVData", "m_flRange");
    CCSWeaponBaseVData.m_flRangeModifier = findOffsetByName(j, "CCSWeaponBaseVData", "m_flRangeModifier");
    CCSWeaponBaseVData.m_flFlinchVelocityModifierLarge = findOffsetByName(j, "CCSWeaponBaseVData", "m_flFlinchVelocityModifierLarge");
    CCSWeaponBaseVData.m_flFlinchVelocityModifierSmall = findOffsetByName(j, "CCSWeaponBaseVData", "m_flFlinchVelocityModifierSmall");
    CCSWeaponBaseVData.m_flRecoveryTimeCrouch = findOffsetByName(j, "CCSWeaponBaseVData", "m_flRecoveryTimeCrouch");
    CCSWeaponBaseVData.m_flRecoveryTimeStand = findOffsetByName(j, "CCSWeaponBaseVData", "m_flRecoveryTimeStand");
    CCSWeaponBaseVData.m_flRecoveryTimeCrouchFinal = findOffsetByName(j, "CCSWeaponBaseVData", "m_flRecoveryTimeCrouchFinal");
    CCSWeaponBaseVData.m_flRecoveryTimeStandFinal = findOffsetByName(j, "CCSWeaponBaseVData", "m_flRecoveryTimeStandFinal");
    CCSWeaponBaseVData.m_nRecoveryTransitionStartBullet = findOffsetByName(j, "CCSWeaponBaseVData", "m_nRecoveryTransitionStartBullet");
    CCSWeaponBaseVData.m_nRecoveryTransitionEndBullet = findOffsetByName(j, "CCSWeaponBaseVData", "m_nRecoveryTransitionEndBullet");
    CCSWeaponBaseVData.m_flThrowVelocity = findOffsetByName(j, "CCSWeaponBaseVData", "m_flThrowVelocity");
    CCSWeaponBaseVData.m_vSmokeColor = findOffsetByName(j, "CCSWeaponBaseVData", "m_vSmokeColor");
    CCSWeaponBaseVData.m_szAnimClass = findOffsetByName(j, "CCSWeaponBaseVData", "m_szAnimClass");

    // Atribuições para C_PointWorldText
    // C_PointWorldText Offsets
    C_PointWorldText.m_bForceRecreateNextUpdate = findOffsetByName(j, "C_PointWorldText", "m_bForceRecreateNextUpdate");
    C_PointWorldText.m_messageText = findOffsetByName(j, "C_PointWorldText", "m_messageText");
    C_PointWorldText.m_FontName = findOffsetByName(j, "C_PointWorldText", "m_FontName");
    C_PointWorldText.m_bEnabled = findOffsetByName(j, "C_PointWorldText", "m_bEnabled");
    C_PointWorldText.m_bFullbright = findOffsetByName(j, "C_PointWorldText", "m_bFullbright");
    C_PointWorldText.m_flWorldUnitsPerPx = findOffsetByName(j, "C_PointWorldText", "m_flWorldUnitsPerPx");
    C_PointWorldText.m_flFontSize = findOffsetByName(j, "C_PointWorldText", "m_flFontSize");
    C_PointWorldText.m_flDepthOffset = findOffsetByName(j, "C_PointWorldText", "m_flDepthOffset");
    C_PointWorldText.m_Color = findOffsetByName(j, "C_PointWorldText", "m_Color");
    C_PointWorldText.m_nJustifyHorizontal = findOffsetByName(j, "C_PointWorldText", "m_nJustifyHorizontal");
    C_PointWorldText.m_nJustifyVertical = findOffsetByName(j, "C_PointWorldText", "m_nJustifyVertical");
    C_PointWorldText.m_nReorientMode = findOffsetByName(j, "C_PointWorldText", "m_nReorientMode");

    // Atribuições para CCSPlayerController
    // CCSPlayerController Offsets
    CCSPlayerController.m_pInGameMoneyServices = findOffsetByName(j, "CCSPlayerController", "m_pInGameMoneyServices");
    CCSPlayerController.m_pInventoryServices = findOffsetByName(j, "CCSPlayerController", "m_pInventoryServices");
    CCSPlayerController.m_pActionTrackingServices = findOffsetByName(j, "CCSPlayerController", "m_pActionTrackingServices");
    CCSPlayerController.m_pDamageServices = findOffsetByName(j, "CCSPlayerController", "m_pDamageServices");
    CCSPlayerController.m_iPing = findOffsetByName(j, "CCSPlayerController", "m_iPing");
    CCSPlayerController.m_bHasCommunicationAbuseMute = findOffsetByName(j, "CCSPlayerController", "m_bHasCommunicationAbuseMute");
    CCSPlayerController.m_szCrosshairCodes = findOffsetByName(j, "CCSPlayerController", "m_szCrosshairCodes");
    CCSPlayerController.m_iPendingTeamNum = findOffsetByName(j, "CCSPlayerController", "m_iPendingTeamNum");
    CCSPlayerController.m_flForceTeamTime = findOffsetByName(j, "CCSPlayerController", "m_flForceTeamTime");
    CCSPlayerController.m_iCompTeammateColor = findOffsetByName(j, "CCSPlayerController", "m_iCompTeammateColor");
    CCSPlayerController.m_bEverPlayedOnTeam = findOffsetByName(j, "CCSPlayerController", "m_bEverPlayedOnTeam");
    CCSPlayerController.m_flPreviousForceJoinTeamTime = findOffsetByName(j, "CCSPlayerController", "m_flPreviousForceJoinTeamTime");
    CCSPlayerController.m_szClan = findOffsetByName(j, "CCSPlayerController", "m_szClan");
    CCSPlayerController.m_sSanitizedPlayerName = findOffsetByName(j, "CCSPlayerController", "m_sSanitizedPlayerName");
    CCSPlayerController.m_iCoachingTeam = findOffsetByName(j, "CCSPlayerController", "m_iCoachingTeam");
    CCSPlayerController.m_nPlayerDominated = findOffsetByName(j, "CCSPlayerController", "m_nPlayerDominated");
    CCSPlayerController.m_nPlayerDominatingMe = findOffsetByName(j, "CCSPlayerController", "m_nPlayerDominatingMe");
    CCSPlayerController.m_iCompetitiveRanking = findOffsetByName(j, "CCSPlayerController", "m_iCompetitiveRanking");
    CCSPlayerController.m_iCompetitiveWins = findOffsetByName(j, "CCSPlayerController", "m_iCompetitiveWins");
    CCSPlayerController.m_iCompetitiveRankType = findOffsetByName(j, "CCSPlayerController", "m_iCompetitiveRankType");
    CCSPlayerController.m_iCompetitiveRankingPredicted_Win = findOffsetByName(j, "CCSPlayerController", "m_iCompetitiveRankingPredicted_Win");
    CCSPlayerController.m_iCompetitiveRankingPredicted_Loss = findOffsetByName(j, "CCSPlayerController", "m_iCompetitiveRankingPredicted_Loss");
    CCSPlayerController.m_iCompetitiveRankingPredicted_Tie = findOffsetByName(j, "CCSPlayerController", "m_iCompetitiveRankingPredicted_Tie");
    CCSPlayerController.m_nEndMatchNextMapVote = findOffsetByName(j, "CCSPlayerController", "m_nEndMatchNextMapVote");
    CCSPlayerController.m_unActiveQuestId = findOffsetByName(j, "CCSPlayerController", "m_unActiveQuestId");
    CCSPlayerController.m_nQuestProgressReason = findOffsetByName(j, "CCSPlayerController", "m_nQuestProgressReason");
    CCSPlayerController.m_unPlayerTvControlFlags = findOffsetByName(j, "CCSPlayerController", "m_unPlayerTvControlFlags");
    CCSPlayerController.m_iDraftIndex = findOffsetByName(j, "CCSPlayerController", "m_iDraftIndex");
    CCSPlayerController.m_msQueuedModeDisconnectionTimestamp = findOffsetByName(j, "CCSPlayerController", "m_msQueuedModeDisconnectionTimestamp");
    CCSPlayerController.m_uiAbandonRecordedReason = findOffsetByName(j, "CCSPlayerController", "m_uiAbandonRecordedReason");
    CCSPlayerController.m_bCannotBeKicked = findOffsetByName(j, "CCSPlayerController", "m_bCannotBeKicked");
    CCSPlayerController.m_bEverFullyConnected = findOffsetByName(j, "CCSPlayerController", "m_bEverFullyConnected");
    CCSPlayerController.m_bAbandonAllowsSurrender = findOffsetByName(j, "CCSPlayerController", "m_bAbandonAllowsSurrender");
    CCSPlayerController.m_bAbandonOffersInstantSurrender = findOffsetByName(j, "CCSPlayerController", "m_bAbandonOffersInstantSurrender");
    CCSPlayerController.m_bDisconnection1MinWarningPrinted = findOffsetByName(j, "CCSPlayerController", "m_bDisconnection1MinWarningPrinted");
    CCSPlayerController.m_bScoreReported = findOffsetByName(j, "CCSPlayerController", "m_bScoreReported");
    CCSPlayerController.m_nDisconnectionTick = findOffsetByName(j, "CCSPlayerController", "m_nDisconnectionTick");
    CCSPlayerController.m_bControllingBot = findOffsetByName(j, "CCSPlayerController", "m_bControllingBot");
    CCSPlayerController.m_bHasControlledBotThisRound = findOffsetByName(j, "CCSPlayerController", "m_bHasControlledBotThisRound");
    CCSPlayerController.m_bHasBeenControlledByPlayerThisRound = findOffsetByName(j, "CCSPlayerController", "m_bHasBeenControlledByPlayerThisRound");
    CCSPlayerController.m_nBotsControlledThisRound = findOffsetByName(j, "CCSPlayerController", "m_nBotsControlledThisRound");
    CCSPlayerController.m_bCanControlObservedBot = findOffsetByName(j, "CCSPlayerController", "m_bCanControlObservedBot");
    CCSPlayerController.m_hPlayerPawn = findOffsetByName(j, "CCSPlayerController", "m_hPlayerPawn");
    CCSPlayerController.m_hObserverPawn = findOffsetByName(j, "CCSPlayerController", "m_hObserverPawn");
    CCSPlayerController.m_bPawnIsAlive = findOffsetByName(j, "CCSPlayerController", "m_bPawnIsAlive");
    CCSPlayerController.m_iPawnHealth = findOffsetByName(j, "CCSPlayerController", "m_iPawnHealth");
    CCSPlayerController.m_iPawnArmor = findOffsetByName(j, "CCSPlayerController", "m_iPawnArmor");
    CCSPlayerController.m_bPawnHasDefuser = findOffsetByName(j, "CCSPlayerController", "m_bPawnHasDefuser");
    CCSPlayerController.m_bPawnHasHelmet = findOffsetByName(j, "CCSPlayerController", "m_bPawnHasHelmet");
    CCSPlayerController.m_nPawnCharacterDefIndex = findOffsetByName(j, "CCSPlayerController", "m_nPawnCharacterDefIndex");
    CCSPlayerController.m_iPawnLifetimeStart = findOffsetByName(j, "CCSPlayerController", "m_iPawnLifetimeStart");
    CCSPlayerController.m_iPawnLifetimeEnd = findOffsetByName(j, "CCSPlayerController", "m_iPawnLifetimeEnd");
    CCSPlayerController.m_iPawnBotDifficulty = findOffsetByName(j, "CCSPlayerController", "m_iPawnBotDifficulty");
    CCSPlayerController.m_hOriginalControllerOfCurrentPawn = findOffsetByName(j, "CCSPlayerController", "m_hOriginalControllerOfCurrentPawn");
    CCSPlayerController.m_iScore = findOffsetByName(j, "CCSPlayerController", "m_iScore");
    CCSPlayerController.m_recentKillQueue = findOffsetByName(j, "CCSPlayerController", "m_recentKillQueue");
    CCSPlayerController.m_nFirstKill = findOffsetByName(j, "CCSPlayerController", "m_nFirstKill");
    CCSPlayerController.m_nKillCount = findOffsetByName(j, "CCSPlayerController", "m_nKillCount");
    CCSPlayerController.m_bMvpNoMusic = findOffsetByName(j, "CCSPlayerController", "m_bMvpNoMusic");
    CCSPlayerController.m_eMvpReason = findOffsetByName(j, "CCSPlayerController", "m_eMvpReason");
    CCSPlayerController.m_iMusicKitID = findOffsetByName(j, "CCSPlayerController", "m_iMusicKitID");
    CCSPlayerController.m_iMusicKitMVPs = findOffsetByName(j, "CCSPlayerController", "m_iMusicKitMVPs");
    CCSPlayerController.m_iMVPs = findOffsetByName(j, "CCSPlayerController", "m_iMVPs");
    CCSPlayerController.m_bIsPlayerNameDirty = findOffsetByName(j, "CCSPlayerController", "m_bIsPlayerNameDirty");

    // Atribuições para C_BasePropDoor
    // C_BasePropDoor Offsets
    C_BasePropDoor.m_eDoorState = findOffsetByName(j, "C_BasePropDoor", "m_eDoorState");
    C_BasePropDoor.m_modelChanged = findOffsetByName(j, "C_BasePropDoor", "m_modelChanged");
    C_BasePropDoor.m_bLocked = findOffsetByName(j, "C_BasePropDoor", "m_bLocked");
    C_BasePropDoor.m_closedPosition = findOffsetByName(j, "C_BasePropDoor", "m_closedPosition");
    C_BasePropDoor.m_closedAngles = findOffsetByName(j, "C_BasePropDoor", "m_closedAngles");
    C_BasePropDoor.m_hMaster = findOffsetByName(j, "C_BasePropDoor", "m_hMaster");
    C_BasePropDoor.m_vWhereToSetLightingOrigin = findOffsetByName(j, "C_BasePropDoor", "m_vWhereToSetLightingOrigin");

    // Atribuições para C_NametagModule
    // C_NametagModule Offsets
    C_NametagModule.m_strNametagString = findOffsetByName(j, "C_NametagModule", "m_strNametagString");

    // Atribuições para C_PhysPropClientside
    // C_PhysPropClientside Offsets
    C_PhysPropClientside.m_flTouchDelta = findOffsetByName(j, "C_PhysPropClientside", "m_flTouchDelta");
    C_PhysPropClientside.m_fDeathTime = findOffsetByName(j, "C_PhysPropClientside", "m_fDeathTime");
    C_PhysPropClientside.m_inertiaScale = findOffsetByName(j, "C_PhysPropClientside", "m_inertiaScale");
    C_PhysPropClientside.m_vecDamagePosition = findOffsetByName(j, "C_PhysPropClientside", "m_vecDamagePosition");
    C_PhysPropClientside.m_vecDamageDirection = findOffsetByName(j, "C_PhysPropClientside", "m_vecDamageDirection");
    C_PhysPropClientside.m_nDamageType = findOffsetByName(j, "C_PhysPropClientside", "m_nDamageType");

    // Atribuições para C_SoundAreaEntityBase
    // C_SoundAreaEntityBase Offsets
    C_SoundAreaEntityBase.m_bDisabled = findOffsetByName(j, "C_SoundAreaEntityBase", "m_bDisabled");
    C_SoundAreaEntityBase.m_bWasEnabled = findOffsetByName(j, "C_SoundAreaEntityBase", "m_bWasEnabled");
    C_SoundAreaEntityBase.m_iszSoundAreaType = findOffsetByName(j, "C_SoundAreaEntityBase", "m_iszSoundAreaType");
    C_SoundAreaEntityBase.m_vPos = findOffsetByName(j, "C_SoundAreaEntityBase", "m_vPos");

    // Atribuições para C_FogController
    // C_FogController Offsets
    C_FogController.m_fog = findOffsetByName(j, "C_FogController", "m_fog");
    C_FogController.m_bUseAngles = findOffsetByName(j, "C_FogController", "m_bUseAngles");
    C_FogController.m_iChangedVariables = findOffsetByName(j, "C_FogController", "m_iChangedVariables");

    // Atribuições para CInfoWorldLayer
    // CInfoWorldLayer Offsets
    CInfoWorldLayer.m_pOutputOnEntitiesSpawned = findOffsetByName(j, "CInfoWorldLayer", "m_pOutputOnEntitiesSpawned");
    CInfoWorldLayer.m_worldName = findOffsetByName(j, "CInfoWorldLayer", "m_worldName");
    CInfoWorldLayer.m_layerName = findOffsetByName(j, "CInfoWorldLayer", "m_layerName");
    CInfoWorldLayer.m_bWorldLayerVisible = findOffsetByName(j, "CInfoWorldLayer", "m_bWorldLayerVisible");
    CInfoWorldLayer.m_bEntitiesSpawned = findOffsetByName(j, "CInfoWorldLayer", "m_bEntitiesSpawned");
    CInfoWorldLayer.m_bCreateAsChildSpawnGroup = findOffsetByName(j, "CInfoWorldLayer", "m_bCreateAsChildSpawnGroup");
    CInfoWorldLayer.m_hLayerSpawnGroup = findOffsetByName(j, "CInfoWorldLayer", "m_hLayerSpawnGroup");
    CInfoWorldLayer.m_bWorldLayerActuallyVisible = findOffsetByName(j, "CInfoWorldLayer", "m_bWorldLayerActuallyVisible");

    // Atribuições para C_PhysMagnet
    // C_PhysMagnet Offsets
    C_PhysMagnet.m_aAttachedObjectsFromServer = findOffsetByName(j, "C_PhysMagnet", "m_aAttachedObjectsFromServer");
    C_PhysMagnet.m_aAttachedObjects = findOffsetByName(j, "C_PhysMagnet", "m_aAttachedObjects");

    // Atribuições para C_FuncConveyor
    // C_FuncConveyor Offsets
    C_FuncConveyor.m_vecMoveDirEntitySpace = findOffsetByName(j, "C_FuncConveyor", "m_vecMoveDirEntitySpace");
    C_FuncConveyor.m_flTargetSpeed = findOffsetByName(j, "C_FuncConveyor", "m_flTargetSpeed");
    C_FuncConveyor.m_nTransitionStartTick = findOffsetByName(j, "C_FuncConveyor", "m_nTransitionStartTick");
    C_FuncConveyor.m_nTransitionDurationTicks = findOffsetByName(j, "C_FuncConveyor", "m_nTransitionDurationTicks");
    C_FuncConveyor.m_flTransitionStartSpeed = findOffsetByName(j, "C_FuncConveyor", "m_flTransitionStartSpeed");
    C_FuncConveyor.m_hConveyorModels = findOffsetByName(j, "C_FuncConveyor", "m_hConveyorModels");
    C_FuncConveyor.m_flCurrentConveyorOffset = findOffsetByName(j, "C_FuncConveyor", "m_flCurrentConveyorOffset");
    C_FuncConveyor.m_flCurrentConveyorSpeed = findOffsetByName(j, "C_FuncConveyor", "m_flCurrentConveyorSpeed");

    // Atribuições para CEntityInstance
    // CEntityInstance Offsets
    CEntityInstance.m_iszPrivateVScripts = findOffsetByName(j, "CEntityInstance", "m_iszPrivateVScripts");
    CEntityInstance.m_pEntity = findOffsetByName(j, "CEntityInstance", "m_pEntity");
    CEntityInstance.m_CScriptComponent = findOffsetByName(j, "CEntityInstance", "m_CScriptComponent");
    CEntityInstance.m_bVisibleinPVS = findOffsetByName(j, "CEntityInstance", "m_bVisibleinPVS");

    // Atribuições para ServerAuthoritativeWeaponSlot_t
    // ServerAuthoritativeWeaponSlot_t Offsets
    ServerAuthoritativeWeaponSlot_t.unClass = findOffsetByName(j, "ServerAuthoritativeWeaponSlot_t", "unClass");
    ServerAuthoritativeWeaponSlot_t.unSlot = findOffsetByName(j, "ServerAuthoritativeWeaponSlot_t", "unSlot");
    ServerAuthoritativeWeaponSlot_t.unItemDefIdx = findOffsetByName(j, "ServerAuthoritativeWeaponSlot_t", "unItemDefIdx");

    // Atribuições para C_BaseViewModel
    // C_BaseViewModel Offsets
    C_BaseViewModel.m_vecLastFacing = findOffsetByName(j, "C_BaseViewModel", "m_vecLastFacing");
    C_BaseViewModel.m_nViewModelIndex = findOffsetByName(j, "C_BaseViewModel", "m_nViewModelIndex");
    C_BaseViewModel.m_nAnimationParity = findOffsetByName(j, "C_BaseViewModel", "m_nAnimationParity");
    C_BaseViewModel.m_flAnimationStartTime = findOffsetByName(j, "C_BaseViewModel", "m_flAnimationStartTime");
    C_BaseViewModel.m_hWeapon = findOffsetByName(j, "C_BaseViewModel", "m_hWeapon");
    C_BaseViewModel.m_sVMName = findOffsetByName(j, "C_BaseViewModel", "m_sVMName");
    C_BaseViewModel.m_sAnimationPrefix = findOffsetByName(j, "C_BaseViewModel", "m_sAnimationPrefix");
    C_BaseViewModel.m_iCameraAttachment = findOffsetByName(j, "C_BaseViewModel", "m_iCameraAttachment");
    C_BaseViewModel.m_vecLastCameraAngles = findOffsetByName(j, "C_BaseViewModel", "m_vecLastCameraAngles");
    C_BaseViewModel.m_previousElapsedDuration = findOffsetByName(j, "C_BaseViewModel", "m_previousElapsedDuration");
    C_BaseViewModel.m_previousCycle = findOffsetByName(j, "C_BaseViewModel", "m_previousCycle");
    C_BaseViewModel.m_nOldAnimationParity = findOffsetByName(j, "C_BaseViewModel", "m_nOldAnimationParity");
    C_BaseViewModel.m_hOldLayerSequence = findOffsetByName(j, "C_BaseViewModel", "m_hOldLayerSequence");
    C_BaseViewModel.m_oldLayer = findOffsetByName(j, "C_BaseViewModel", "m_oldLayer");
    C_BaseViewModel.m_oldLayerStartTime = findOffsetByName(j, "C_BaseViewModel", "m_oldLayerStartTime");
    C_BaseViewModel.m_hControlPanel = findOffsetByName(j, "C_BaseViewModel", "m_hControlPanel");

    // Atribuições para CGameSceneNode
    // CGameSceneNode Offsets
    CGameSceneNode.m_nodeToWorld = findOffsetByName(j, "CGameSceneNode", "m_nodeToWorld");
    CGameSceneNode.m_pOwner = findOffsetByName(j, "CGameSceneNode", "m_pOwner");
    CGameSceneNode.m_pParent = findOffsetByName(j, "CGameSceneNode", "m_pParent");
    CGameSceneNode.m_pChild = findOffsetByName(j, "CGameSceneNode", "m_pChild");
    CGameSceneNode.m_pNextSibling = findOffsetByName(j, "CGameSceneNode", "m_pNextSibling");
    CGameSceneNode.m_hParent = findOffsetByName(j, "CGameSceneNode", "m_hParent");
    CGameSceneNode.m_vecOrigin = findOffsetByName(j, "CGameSceneNode", "m_vecOrigin");
    CGameSceneNode.m_angRotation = findOffsetByName(j, "CGameSceneNode", "m_angRotation");
    CGameSceneNode.m_flScale = findOffsetByName(j, "CGameSceneNode", "m_flScale");
    CGameSceneNode.m_vecAbsOrigin = findOffsetByName(j, "CGameSceneNode", "m_vecAbsOrigin");
    CGameSceneNode.m_angAbsRotation = findOffsetByName(j, "CGameSceneNode", "m_angAbsRotation");
    CGameSceneNode.m_flAbsScale = findOffsetByName(j, "CGameSceneNode", "m_flAbsScale");
    CGameSceneNode.m_nParentAttachmentOrBone = findOffsetByName(j, "CGameSceneNode", "m_nParentAttachmentOrBone");
    CGameSceneNode.m_bDebugAbsOriginChanges = findOffsetByName(j, "CGameSceneNode", "m_bDebugAbsOriginChanges");
    CGameSceneNode.m_bDormant = findOffsetByName(j, "CGameSceneNode", "m_bDormant");
    CGameSceneNode.m_bForceParentToBeNetworked = findOffsetByName(j, "CGameSceneNode", "m_bForceParentToBeNetworked");
    CGameSceneNode.m_bDirtyHierarchy = findOffsetByName(j, "CGameSceneNode", "m_bDirtyHierarchy");
    CGameSceneNode.m_bDirtyBoneMergeInfo = findOffsetByName(j, "CGameSceneNode", "m_bDirtyBoneMergeInfo");
    CGameSceneNode.m_bNetworkedPositionChanged = findOffsetByName(j, "CGameSceneNode", "m_bNetworkedPositionChanged");
    CGameSceneNode.m_bNetworkedAnglesChanged = findOffsetByName(j, "CGameSceneNode", "m_bNetworkedAnglesChanged");
    CGameSceneNode.m_bNetworkedScaleChanged = findOffsetByName(j, "CGameSceneNode", "m_bNetworkedScaleChanged");
    CGameSceneNode.m_bWillBeCallingPostDataUpdate = findOffsetByName(j, "CGameSceneNode", "m_bWillBeCallingPostDataUpdate");
    CGameSceneNode.m_bBoneMergeFlex = findOffsetByName(j, "CGameSceneNode", "m_bBoneMergeFlex");
    CGameSceneNode.m_nLatchAbsOrigin = findOffsetByName(j, "CGameSceneNode", "m_nLatchAbsOrigin");
    CGameSceneNode.m_bDirtyBoneMergeBoneToRoot = findOffsetByName(j, "CGameSceneNode", "m_bDirtyBoneMergeBoneToRoot");
    CGameSceneNode.m_nHierarchicalDepth = findOffsetByName(j, "CGameSceneNode", "m_nHierarchicalDepth");
    CGameSceneNode.m_nHierarchyType = findOffsetByName(j, "CGameSceneNode", "m_nHierarchyType");
    CGameSceneNode.m_nDoNotSetAnimTimeInInvalidatePhysicsCount = findOffsetByName(j, "CGameSceneNode", "m_nDoNotSetAnimTimeInInvalidatePhysicsCount");
    CGameSceneNode.m_name = findOffsetByName(j, "CGameSceneNode", "m_name");
    CGameSceneNode.m_hierarchyAttachName = findOffsetByName(j, "CGameSceneNode", "m_hierarchyAttachName");
    CGameSceneNode.m_flZOffset = findOffsetByName(j, "CGameSceneNode", "m_flZOffset");
    CGameSceneNode.m_flClientLocalScale = findOffsetByName(j, "CGameSceneNode", "m_flClientLocalScale");
    CGameSceneNode.m_vRenderOrigin = findOffsetByName(j, "CGameSceneNode", "m_vRenderOrigin");

    // Atribuições para CCSPointScript
    // CCSPointScript Offsets
    CCSPointScript.m_pParent = findOffsetByName(j, "CCSPointScript", "m_pParent");

    // Atribuições para C_CSObserverPawn
    // C_CSObserverPawn Offsets
    C_CSObserverPawn.m_hDetectParentChange = findOffsetByName(j, "C_CSObserverPawn", "m_hDetectParentChange");

    // Atribuições para C_EntityFlame
    // C_EntityFlame Offsets
    C_EntityFlame.m_hEntAttached = findOffsetByName(j, "C_EntityFlame", "m_hEntAttached");
    C_EntityFlame.m_hOldAttached = findOffsetByName(j, "C_EntityFlame", "m_hOldAttached");
    C_EntityFlame.m_bCheapEffect = findOffsetByName(j, "C_EntityFlame", "m_bCheapEffect");

    // Atribuições para CCSObserver_ObserverServices
    // CCSObserver_ObserverServices Offsets
    CCSObserver_ObserverServices.m_hLastObserverTarget = findOffsetByName(j, "CCSObserver_ObserverServices", "m_hLastObserverTarget");
    CCSObserver_ObserverServices.m_vecObserverInterpolateOffset = findOffsetByName(j, "CCSObserver_ObserverServices", "m_vecObserverInterpolateOffset");
    CCSObserver_ObserverServices.m_vecObserverInterpStartPos = findOffsetByName(j, "CCSObserver_ObserverServices", "m_vecObserverInterpStartPos");
    CCSObserver_ObserverServices.m_flObsInterp_PathLength = findOffsetByName(j, "CCSObserver_ObserverServices", "m_flObsInterp_PathLength");
    CCSObserver_ObserverServices.m_qObsInterp_OrientationStart = findOffsetByName(j, "CCSObserver_ObserverServices", "m_qObsInterp_OrientationStart");
    CCSObserver_ObserverServices.m_qObsInterp_OrientationTravelDir = findOffsetByName(j, "CCSObserver_ObserverServices", "m_qObsInterp_OrientationTravelDir");
    CCSObserver_ObserverServices.m_obsInterpState = findOffsetByName(j, "CCSObserver_ObserverServices", "m_obsInterpState");
    CCSObserver_ObserverServices.m_bObserverInterpolationNeedsDeferredSetup = findOffsetByName(j, "CCSObserver_ObserverServices", "m_bObserverInterpolationNeedsDeferredSetup");

    // Atribuições para C_Hostage
    // C_Hostage Offsets
    C_Hostage.m_entitySpottedState = findOffsetByName(j, "C_Hostage", "m_entitySpottedState");
    C_Hostage.m_leader = findOffsetByName(j, "C_Hostage", "m_leader");
    C_Hostage.m_reuseTimer = findOffsetByName(j, "C_Hostage", "m_reuseTimer");
    C_Hostage.m_vel = findOffsetByName(j, "C_Hostage", "m_vel");
    C_Hostage.m_isRescued = findOffsetByName(j, "C_Hostage", "m_isRescued");
    C_Hostage.m_jumpedThisFrame = findOffsetByName(j, "C_Hostage", "m_jumpedThisFrame");
    C_Hostage.m_nHostageState = findOffsetByName(j, "C_Hostage", "m_nHostageState");
    C_Hostage.m_bHandsHaveBeenCut = findOffsetByName(j, "C_Hostage", "m_bHandsHaveBeenCut");
    C_Hostage.m_hHostageGrabber = findOffsetByName(j, "C_Hostage", "m_hHostageGrabber");
    C_Hostage.m_fLastGrabTime = findOffsetByName(j, "C_Hostage", "m_fLastGrabTime");
    C_Hostage.m_vecGrabbedPos = findOffsetByName(j, "C_Hostage", "m_vecGrabbedPos");
    C_Hostage.m_flRescueStartTime = findOffsetByName(j, "C_Hostage", "m_flRescueStartTime");
    C_Hostage.m_flGrabSuccessTime = findOffsetByName(j, "C_Hostage", "m_flGrabSuccessTime");
    C_Hostage.m_flDropStartTime = findOffsetByName(j, "C_Hostage", "m_flDropStartTime");
    C_Hostage.m_flDeadOrRescuedTime = findOffsetByName(j, "C_Hostage", "m_flDeadOrRescuedTime");
    C_Hostage.m_blinkTimer = findOffsetByName(j, "C_Hostage", "m_blinkTimer");
    C_Hostage.m_lookAt = findOffsetByName(j, "C_Hostage", "m_lookAt");
    C_Hostage.m_lookAroundTimer = findOffsetByName(j, "C_Hostage", "m_lookAroundTimer");
    C_Hostage.m_isInit = findOffsetByName(j, "C_Hostage", "m_isInit");
    C_Hostage.m_eyeAttachment = findOffsetByName(j, "C_Hostage", "m_eyeAttachment");
    C_Hostage.m_chestAttachment = findOffsetByName(j, "C_Hostage", "m_chestAttachment");
    C_Hostage.m_pPredictionOwner = findOffsetByName(j, "C_Hostage", "m_pPredictionOwner");
    C_Hostage.m_fNewestAlphaThinkTime = findOffsetByName(j, "C_Hostage", "m_fNewestAlphaThinkTime");

    // Atribuições para C_Sprite
    // C_Sprite Offsets
    C_Sprite.m_hSpriteMaterial = findOffsetByName(j, "C_Sprite", "m_hSpriteMaterial");
    C_Sprite.m_hAttachedToEntity = findOffsetByName(j, "C_Sprite", "m_hAttachedToEntity");
    C_Sprite.m_nAttachment = findOffsetByName(j, "C_Sprite", "m_nAttachment");
    C_Sprite.m_flSpriteFramerate = findOffsetByName(j, "C_Sprite", "m_flSpriteFramerate");
    C_Sprite.m_flFrame = findOffsetByName(j, "C_Sprite", "m_flFrame");
    C_Sprite.m_flDieTime = findOffsetByName(j, "C_Sprite", "m_flDieTime");
    C_Sprite.m_nBrightness = findOffsetByName(j, "C_Sprite", "m_nBrightness");
    C_Sprite.m_flBrightnessDuration = findOffsetByName(j, "C_Sprite", "m_flBrightnessDuration");
    C_Sprite.m_flSpriteScale = findOffsetByName(j, "C_Sprite", "m_flSpriteScale");
    C_Sprite.m_flScaleDuration = findOffsetByName(j, "C_Sprite", "m_flScaleDuration");
    C_Sprite.m_bWorldSpaceScale = findOffsetByName(j, "C_Sprite", "m_bWorldSpaceScale");
    C_Sprite.m_flGlowProxySize = findOffsetByName(j, "C_Sprite", "m_flGlowProxySize");
    C_Sprite.m_flHDRColorScale = findOffsetByName(j, "C_Sprite", "m_flHDRColorScale");
    C_Sprite.m_flLastTime = findOffsetByName(j, "C_Sprite", "m_flLastTime");
    C_Sprite.m_flMaxFrame = findOffsetByName(j, "C_Sprite", "m_flMaxFrame");
    C_Sprite.m_flStartScale = findOffsetByName(j, "C_Sprite", "m_flStartScale");
    C_Sprite.m_flDestScale = findOffsetByName(j, "C_Sprite", "m_flDestScale");
    C_Sprite.m_flScaleTimeStart = findOffsetByName(j, "C_Sprite", "m_flScaleTimeStart");
    C_Sprite.m_nStartBrightness = findOffsetByName(j, "C_Sprite", "m_nStartBrightness");
    C_Sprite.m_nDestBrightness = findOffsetByName(j, "C_Sprite", "m_nDestBrightness");
    C_Sprite.m_flBrightnessTimeStart = findOffsetByName(j, "C_Sprite", "m_flBrightnessTimeStart");
    C_Sprite.m_hOldSpriteMaterial = findOffsetByName(j, "C_Sprite", "m_hOldSpriteMaterial");
    C_Sprite.m_nSpriteWidth = findOffsetByName(j, "C_Sprite", "m_nSpriteWidth");
    C_Sprite.m_nSpriteHeight = findOffsetByName(j, "C_Sprite", "m_nSpriteHeight");

    // Atribuições para C_PlantedC4
    // C_PlantedC4 Offsets
    C_PlantedC4.m_bBombTicking = findOffsetByName(j, "C_PlantedC4", "m_bBombTicking");
    C_PlantedC4.m_nBombSite = findOffsetByName(j, "C_PlantedC4", "m_nBombSite");
    C_PlantedC4.m_nSourceSoundscapeHash = findOffsetByName(j, "C_PlantedC4", "m_nSourceSoundscapeHash");
    C_PlantedC4.m_entitySpottedState = findOffsetByName(j, "C_PlantedC4", "m_entitySpottedState");
    C_PlantedC4.m_flNextGlow = findOffsetByName(j, "C_PlantedC4", "m_flNextGlow");
    C_PlantedC4.m_flNextBeep = findOffsetByName(j, "C_PlantedC4", "m_flNextBeep");
    C_PlantedC4.m_flC4Blow = findOffsetByName(j, "C_PlantedC4", "m_flC4Blow");
    C_PlantedC4.m_bCannotBeDefused = findOffsetByName(j, "C_PlantedC4", "m_bCannotBeDefused");
    C_PlantedC4.m_bHasExploded = findOffsetByName(j, "C_PlantedC4", "m_bHasExploded");
    C_PlantedC4.m_flTimerLength = findOffsetByName(j, "C_PlantedC4", "m_flTimerLength");
    C_PlantedC4.m_bBeingDefused = findOffsetByName(j, "C_PlantedC4", "m_bBeingDefused");
    C_PlantedC4.m_bTriggerWarning = findOffsetByName(j, "C_PlantedC4", "m_bTriggerWarning");
    C_PlantedC4.m_bExplodeWarning = findOffsetByName(j, "C_PlantedC4", "m_bExplodeWarning");
    C_PlantedC4.m_bC4Activated = findOffsetByName(j, "C_PlantedC4", "m_bC4Activated");
    C_PlantedC4.m_bTenSecWarning = findOffsetByName(j, "C_PlantedC4", "m_bTenSecWarning");
    C_PlantedC4.m_flDefuseLength = findOffsetByName(j, "C_PlantedC4", "m_flDefuseLength");
    C_PlantedC4.m_flDefuseCountDown = findOffsetByName(j, "C_PlantedC4", "m_flDefuseCountDown");
    C_PlantedC4.m_bBombDefused = findOffsetByName(j, "C_PlantedC4", "m_bBombDefused");
    C_PlantedC4.m_hBombDefuser = findOffsetByName(j, "C_PlantedC4", "m_hBombDefuser");
    C_PlantedC4.m_hControlPanel = findOffsetByName(j, "C_PlantedC4", "m_hControlPanel");
    C_PlantedC4.m_AttributeManager = findOffsetByName(j, "C_PlantedC4", "m_AttributeManager");
    C_PlantedC4.m_hDefuserMultimeter = findOffsetByName(j, "C_PlantedC4", "m_hDefuserMultimeter");
    C_PlantedC4.m_flNextRadarFlashTime = findOffsetByName(j, "C_PlantedC4", "m_flNextRadarFlashTime");
    C_PlantedC4.m_bRadarFlash = findOffsetByName(j, "C_PlantedC4", "m_bRadarFlash");
    C_PlantedC4.m_pBombDefuser = findOffsetByName(j, "C_PlantedC4", "m_pBombDefuser");
    C_PlantedC4.m_fLastDefuseTime = findOffsetByName(j, "C_PlantedC4", "m_fLastDefuseTime");
    C_PlantedC4.m_pPredictionOwner = findOffsetByName(j, "C_PlantedC4", "m_pPredictionOwner");
    C_PlantedC4.m_vecC4ExplodeSpectatePos = findOffsetByName(j, "C_PlantedC4", "m_vecC4ExplodeSpectatePos");
    C_PlantedC4.m_vecC4ExplodeSpectateAng = findOffsetByName(j, "C_PlantedC4", "m_vecC4ExplodeSpectateAng");
    C_PlantedC4.m_flC4ExplodeSpectateDuration = findOffsetByName(j, "C_PlantedC4", "m_flC4ExplodeSpectateDuration");

    // Atribuições para C_RagdollProp
    // C_RagdollProp Offsets
    C_RagdollProp.m_ragPos = findOffsetByName(j, "C_RagdollProp", "m_ragPos");
    C_RagdollProp.m_ragAngles = findOffsetByName(j, "C_RagdollProp", "m_ragAngles");
    C_RagdollProp.m_flBlendWeight = findOffsetByName(j, "C_RagdollProp", "m_flBlendWeight");
    C_RagdollProp.m_hRagdollSource = findOffsetByName(j, "C_RagdollProp", "m_hRagdollSource");
    C_RagdollProp.m_iEyeAttachment = findOffsetByName(j, "C_RagdollProp", "m_iEyeAttachment");
    C_RagdollProp.m_flBlendWeightCurrent = findOffsetByName(j, "C_RagdollProp", "m_flBlendWeightCurrent");
    C_RagdollProp.m_parentPhysicsBoneIndices = findOffsetByName(j, "C_RagdollProp", "m_parentPhysicsBoneIndices");
    C_RagdollProp.m_worldSpaceBoneComputationOrder = findOffsetByName(j, "C_RagdollProp", "m_worldSpaceBoneComputationOrder");

    // Atribuições para C_VoteController
    // C_VoteController Offsets
    C_VoteController.m_iActiveIssueIndex = findOffsetByName(j, "C_VoteController", "m_iActiveIssueIndex");
    C_VoteController.m_iOnlyTeamToVote = findOffsetByName(j, "C_VoteController", "m_iOnlyTeamToVote");
    C_VoteController.m_nVoteOptionCount = findOffsetByName(j, "C_VoteController", "m_nVoteOptionCount");
    C_VoteController.m_nPotentialVotes = findOffsetByName(j, "C_VoteController", "m_nPotentialVotes");
    C_VoteController.m_bVotesDirty = findOffsetByName(j, "C_VoteController", "m_bVotesDirty");
    C_VoteController.m_bTypeDirty = findOffsetByName(j, "C_VoteController", "m_bTypeDirty");
    C_VoteController.m_bIsYesNoVote = findOffsetByName(j, "C_VoteController", "m_bIsYesNoVote");

    // Atribuições para ViewAngleServerChange_t
    // ViewAngleServerChange_t Offsets
    ViewAngleServerChange_t.nType = findOffsetByName(j, "ViewAngleServerChange_t", "nType");
    ViewAngleServerChange_t.qAngle = findOffsetByName(j, "ViewAngleServerChange_t", "qAngle");
    ViewAngleServerChange_t.nIndex = findOffsetByName(j, "ViewAngleServerChange_t", "nIndex");

    // Atribuições para C_Chicken
    // C_Chicken Offsets
    C_Chicken.m_hHolidayHatAddon = findOffsetByName(j, "C_Chicken", "m_hHolidayHatAddon");
    C_Chicken.m_jumpedThisFrame = findOffsetByName(j, "C_Chicken", "m_jumpedThisFrame");
    C_Chicken.m_leader = findOffsetByName(j, "C_Chicken", "m_leader");
    C_Chicken.m_AttributeManager = findOffsetByName(j, "C_Chicken", "m_AttributeManager");
    C_Chicken.m_bAttributesInitialized = findOffsetByName(j, "C_Chicken", "m_bAttributesInitialized");
    C_Chicken.m_hWaterWakeParticles = findOffsetByName(j, "C_Chicken", "m_hWaterWakeParticles");
    C_Chicken.m_bIsPreviewModel = findOffsetByName(j, "C_Chicken", "m_bIsPreviewModel");

    // Atribuições para PhysicsRagdollPose_t
    // PhysicsRagdollPose_t Offsets
    PhysicsRagdollPose_t.m_Transforms = findOffsetByName(j, "PhysicsRagdollPose_t", "m_Transforms");
    PhysicsRagdollPose_t.m_hOwner = findOffsetByName(j, "PhysicsRagdollPose_t", "m_hOwner");

    // Atribuições para client_dll
    // client_dll Offsets
    client_dll.dwCSGOInput = findOffsetByName(j, "client_dll", "dwCSGOInput");
    client_dll.dwEntityList = findOffsetByName(j, "client_dll", "dwEntityList");
    client_dll.dwGameEntitySystem = findOffsetByName(j, "client_dll", "dwGameEntitySystem");
    client_dll.dwGameEntitySystem_highestEntityIndex = findOffsetByName(j, "client_dll", "dwGameEntitySystem_highestEntityIndex");
    client_dll.dwGameRules = findOffsetByName(j, "client_dll", "dwGameRules");
    client_dll.dwGlobalVars = findOffsetByName(j, "client_dll", "dwGlobalVars");
    client_dll.dwGlowManager = findOffsetByName(j, "client_dll", "dwGlowManager");
    client_dll.dwLocalPlayerController = findOffsetByName(j, "client_dll", "dwLocalPlayerController");
    client_dll.dwLocalPlayerPawn = findOffsetByName(j, "client_dll", "dwLocalPlayerPawn");
    client_dll.dwPlantedC4 = findOffsetByName(j, "client_dll", "dwPlantedC4");
    client_dll.dwPrediction = findOffsetByName(j, "client_dll", "dwPrediction");
    client_dll.dwSensitivity = findOffsetByName(j, "client_dll", "dwSensitivity");
    client_dll.dwSensitivity_sensitivity = findOffsetByName(j, "client_dll", "dwSensitivity_sensitivity");
    client_dll.dwViewAngles = findOffsetByName(j, "client_dll", "dwViewAngles");
    client_dll.dwViewMatrix = findOffsetByName(j, "client_dll", "dwViewMatrix");
    client_dll.dwViewRender = findOffsetByName(j, "client_dll", "dwViewRender");
    client_dll.dwWeaponC4 = findOffsetByName(j, "client_dll", "dwWeaponC4");

    // Atribuições para engine2_dll
    // engine2_dll Offsets
    engine2_dll.dwBuildNumber = findOffsetByName(j, "engine2_dll", "dwBuildNumber");
    engine2_dll.dwNetworkGameClient = findOffsetByName(j, "engine2_dll", "dwNetworkGameClient");
    engine2_dll.dwNetworkGameClient_clientTickCount = findOffsetByName(j, "engine2_dll", "dwNetworkGameClient_clientTickCount");
    engine2_dll.dwNetworkGameClient_deltaTick = findOffsetByName(j, "engine2_dll", "dwNetworkGameClient_deltaTick");
    engine2_dll.dwNetworkGameClient_isBackgroundMap = findOffsetByName(j, "engine2_dll", "dwNetworkGameClient_isBackgroundMap");
    engine2_dll.dwNetworkGameClient_localPlayer = findOffsetByName(j, "engine2_dll", "dwNetworkGameClient_localPlayer");
    engine2_dll.dwNetworkGameClient_maxClients = findOffsetByName(j, "engine2_dll", "dwNetworkGameClient_maxClients");
    engine2_dll.dwNetworkGameClient_serverTickCount = findOffsetByName(j, "engine2_dll", "dwNetworkGameClient_serverTickCount");
    engine2_dll.dwNetworkGameClient_signOnState = findOffsetByName(j, "engine2_dll", "dwNetworkGameClient_signOnState");
    engine2_dll.dwWindowHeight = findOffsetByName(j, "engine2_dll", "dwWindowHeight");
    engine2_dll.dwWindowWidth = findOffsetByName(j, "engine2_dll", "dwWindowWidth");

    // Atribuições para inputsystem_dll
    // inputsystem_dll Offsets
    inputsystem_dll.dwInputSystem = findOffsetByName(j, "inputsystem_dll", "dwInputSystem");

    // Atribuições para matchmaking_dll
    // matchmaking_dll Offsets
    matchmaking_dll.dwGameTypes = findOffsetByName(j, "matchmaking_dll", "dwGameTypes");
    matchmaking_dll.dwGameTypes_mapName = findOffsetByName(j, "matchmaking_dll", "dwGameTypes_mapName");

    // Atribuições para soundsystem_dll
    // soundsystem_dll Offsets
    soundsystem_dll.dwSoundSystem = findOffsetByName(j, "soundsystem_dll", "dwSoundSystem");
    soundsystem_dll.dwSoundSystem_engineViewData = findOffsetByName(j, "soundsystem_dll", "dwSoundSystem_engineViewData");

    // Atribuições para Trash
    // Trash Offsets
    Trash.AnimGraph = findOffsetByName(j, "Trash", "AnimGraph");
    Trash.Aspect_Ratio = findOffsetByName(j, "Trash", "Aspect_Ratio");
    Trash.Fov_Changer = findOffsetByName(j, "Trash", "Fov_Changer");
    Trash.Fov_Offset = findOffsetByName(j, "Trash", "Fov_Offset");
    Trash.LightSceneObject = findOffsetByName(j, "Trash", "LightSceneObject");
    Trash.ScenSystem = findOffsetByName(j, "Trash", "ScenSystem");
    Trash.hkDrawSceneObject = findOffsetByName(j, "Trash", "hkDrawSceneObject");

}

bool Offset::UpdateOffsets()
{
    try 
    {
        std::string url = ("https://raw.githubusercontent.com/E0x00000/CS2-Basic-Dump-V2/refs/heads/main/offsets.json");
        std::string final = Login::DownloadString2(url);
        parseAndAssignConstants(final);
    }
    catch (const std::exception& e)
    {
        return false;
    }
    return true;
}