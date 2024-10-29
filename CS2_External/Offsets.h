#pragma once
#include <Windows.h>
#include "Utils/ProcessManager.hpp"
using DWORD = unsigned long;
namespace Offset
{
	inline struct buttonsOffsets {
		DWORD attack;
		DWORD attack2;
		DWORD back;
		DWORD duck;
		DWORD forward;
		DWORD jump;
		DWORD left;
		DWORD lookatweapon;
		DWORD reload;
		DWORD right;
		DWORD showscores;
		DWORD sprint;
		DWORD turnleft;
		DWORD turnright;
		DWORD use;
		DWORD zoom;
	} buttons;

	inline struct CCSPlayer_MovementServicesOffsets {
		DWORD m_vecLadderNormal;
		DWORD m_nLadderSurfacePropIndex;
		DWORD m_flDuckAmount;
		DWORD m_flDuckSpeed;
		DWORD m_bDuckOverride;
		DWORD m_bDesiresDuck;
		DWORD m_flDuckOffset;
		DWORD m_nDuckTimeMsecs;
		DWORD m_nDuckJumpTimeMsecs;
		DWORD m_nJumpTimeMsecs;
		DWORD m_flLastDuckTime;
		DWORD m_vecLastPositionAtFullCrouchSpeed;
		DWORD m_duckUntilOnGround;
		DWORD m_bHasWalkMovedSinceLastJump;
		DWORD m_bInStuckTest;
		DWORD m_flStuckCheckTime;
		DWORD m_nTraceCount;
		DWORD m_StuckLast;
		DWORD m_bSpeedCropped;
		DWORD m_flGroundMoveEfficiency;
		DWORD m_nOldWaterLevel;
		DWORD m_flWaterEntryTime;
		DWORD m_vecForward;
		DWORD m_vecLeft;
		DWORD m_vecUp;
		DWORD m_nGameCodeHasMovedPlayerAfterCommand;
		DWORD m_bOldJumpPressed;
		DWORD m_flJumpPressedTime;
		DWORD m_fStashGrenadeParameterWhen;
		DWORD m_nButtonDownMaskPrev;
		DWORD m_flOffsetTickCompleteTime;
		DWORD m_flOffsetTickStashedSpeed;
		DWORD m_flStamina;
		DWORD m_flHeightAtJumpStart;
		DWORD m_flMaxJumpHeightThisJump;
		DWORD m_flMaxJumpHeightLastJump;
		DWORD m_flStaminaAtJumpStart;
		DWORD m_flAccumulatedJumpError;
	} CCSPlayer_MovementServices;

	inline struct sky3dparams_tOffsets {
		DWORD scale;
		DWORD origin;
		DWORD bClip3DSkyBoxNearToWorldFar;
		DWORD flClip3DSkyBoxNearToWorldFarOffset;
		DWORD fog;
		DWORD m_nWorldGroupID;
	} sky3dparams_t;

	inline struct C_ItemOffsets {
		DWORD m_pReticleHintTextName;
	} C_Item;

	inline struct C_SoundEventPathCornerEntityOffsets {
		DWORD m_vecCornerPairsNetworked;
	} C_SoundEventPathCornerEntity;

	inline struct C_CSGameRulesOffsets {
		DWORD m_bFreezePeriod;
		DWORD m_bWarmupPeriod;
		DWORD m_fWarmupPeriodEnd;
		DWORD m_fWarmupPeriodStart;
		DWORD m_bServerPaused;
		DWORD m_bTerroristTimeOutActive;
		DWORD m_bCTTimeOutActive;
		DWORD m_flTerroristTimeOutRemaining;
		DWORD m_flCTTimeOutRemaining;
		DWORD m_nTerroristTimeOuts;
		DWORD m_nCTTimeOuts;
		DWORD m_bTechnicalTimeOut;
		DWORD m_bMatchWaitingForResume;
		DWORD m_iRoundTime;
		DWORD m_fMatchStartTime;
		DWORD m_fRoundStartTime;
		DWORD m_flRestartRoundTime;
		DWORD m_bGameRestart;
		DWORD m_flGameStartTime;
		DWORD m_timeUntilNextPhaseStarts;
		DWORD m_gamePhase;
		DWORD m_totalRoundsPlayed;
		DWORD m_nRoundsPlayedThisPhase;
		DWORD m_nOvertimePlaying;
		DWORD m_iHostagesRemaining;
		DWORD m_bAnyHostageReached;
		DWORD m_bMapHasBombTarget;
		DWORD m_bMapHasRescueZone;
		DWORD m_bMapHasBuyZone;
		DWORD m_bIsQueuedMatchmaking;
		DWORD m_nQueuedMatchmakingMode;
		DWORD m_bIsValveDS;
		DWORD m_bLogoMap;
		DWORD m_bPlayAllStepSoundsOnServer;
		DWORD m_iSpectatorSlotCount;
		DWORD m_MatchDevice;
		DWORD m_bHasMatchStarted;
		DWORD m_nNextMapInMapgroup;
		DWORD m_szTournamentEventName;
		DWORD m_szTournamentEventStage;
		DWORD m_szMatchStatTxt;
		DWORD m_szTournamentPredictionsTxt;
		DWORD m_nTournamentPredictionsPct;
		DWORD m_flCMMItemDropRevealStartTime;
		DWORD m_flCMMItemDropRevealEndTime;
		DWORD m_bIsDroppingItems;
		DWORD m_bIsQuestEligible;
		DWORD m_bIsHltvActive;
		DWORD m_arrProhibitedItemIndices;
		DWORD m_arrTournamentActiveCasterAccounts;
		DWORD m_numBestOfMaps;
		DWORD m_nHalloweenMaskListSeed;
		DWORD m_bBombDropped;
		DWORD m_bBombPlanted;
		DWORD m_iRoundWinStatus;
		DWORD m_eRoundWinReason;
		DWORD m_bTCantBuy;
		DWORD m_bCTCantBuy;
		DWORD m_iMatchStats_RoundResults;
		DWORD m_iMatchStats_PlayersAlive_CT;
		DWORD m_iMatchStats_PlayersAlive_T;
		DWORD m_TeamRespawnWaveTimes;
		DWORD m_flNextRespawnWave;
		DWORD m_nServerQuestID;
		DWORD m_vMinimapMins;
		DWORD m_vMinimapMaxs;
		DWORD m_MinimapVerticalSectionHeights;
		DWORD m_bSpawnedTerrorHuntHeavy;
		DWORD m_nEndMatchMapGroupVoteTypes;
		DWORD m_nEndMatchMapGroupVoteOptions;
		DWORD m_nEndMatchMapVoteWinner;
		DWORD m_iNumConsecutiveCTLoses;
		DWORD m_iNumConsecutiveTerroristLoses;
		DWORD m_bMarkClientStopRecordAtRoundEnd;
		DWORD m_nMatchAbortedEarlyReason;
		DWORD m_bHasTriggeredRoundStartMusic;
		DWORD m_bSwitchingTeamsAtRoundReset;
		DWORD m_pGameModeRules;
		DWORD m_RetakeRules;
		DWORD m_nMatchEndCount;
		DWORD m_nTTeamIntroVariant;
		DWORD m_nCTTeamIntroVariant;
		DWORD m_bTeamIntroPeriod;
		DWORD m_iRoundEndWinnerTeam;
		DWORD m_eRoundEndReason;
		DWORD m_bRoundEndShowTimerDefend;
		DWORD m_iRoundEndTimerTime;
		DWORD m_sRoundEndFunFactToken;
		DWORD m_iRoundEndFunFactPlayerSlot;
		DWORD m_iRoundEndFunFactData1;
		DWORD m_iRoundEndFunFactData2;
		DWORD m_iRoundEndFunFactData3;
		DWORD m_sRoundEndMessage;
		DWORD m_iRoundEndPlayerCount;
		DWORD m_bRoundEndNoMusic;
		DWORD m_iRoundEndLegacy;
		DWORD m_nRoundEndCount;
		DWORD m_iRoundStartRoundNumber;
		DWORD m_nRoundStartCount;
		DWORD m_flLastPerfSampleTime;
	} C_CSGameRules;

	inline struct CBodyComponentSkeletonInstanceOffsets {
		DWORD m_skeletonInstance;
	} CBodyComponentSkeletonInstance;

	inline struct C_BaseModelEntityOffsets {
		DWORD m_CRenderComponent;
		DWORD m_CHitboxComponent;
		DWORD m_LastHitGroup;
		DWORD m_bInitModelEffects;
		DWORD m_bIsStaticProp;
		DWORD m_nLastAddDecal;
		DWORD m_nDecalsAdded;
		DWORD m_iOldHealth;
		DWORD m_nRenderMode;
		DWORD m_nRenderFX;
		DWORD m_bAllowFadeInView;
		DWORD m_clrRender;
		DWORD m_vecRenderAttributes;
		DWORD m_bRenderToCubemaps;
		DWORD m_bNoInterpolate;
		DWORD m_Collision;
		DWORD m_Glow;
		DWORD m_flGlowBackfaceMult;
		DWORD m_fadeMinDist;
		DWORD m_fadeMaxDist;
		DWORD m_flFadeScale;
		DWORD m_flShadowStrength;
		DWORD m_nObjectCulling;
		DWORD m_nAddDecal;
		DWORD m_vDecalPosition;
		DWORD m_vDecalForwardAxis;
		DWORD m_flDecalHealBloodRate;
		DWORD m_flDecalHealHeightRate;
		DWORD m_ConfigEntitiesToPropagateMaterialDecalsTo;
		DWORD m_vecViewOffset;
		DWORD m_pClientAlphaProperty;
		DWORD m_ClientOverrideTint;
		DWORD m_bUseClientOverrideTint;
	} C_BaseModelEntity;

	inline struct C_FootstepControlOffsets {
		DWORD m_source;
		DWORD m_destination;
	} C_FootstepControl;

	inline struct C_PointClientUIHUDOffsets {
		DWORD m_bCheckCSSClasses;
		DWORD m_bIgnoreInput;
		DWORD m_flWidth;
		DWORD m_flHeight;
		DWORD m_flDPI;
		DWORD m_flInteractDistance;
		DWORD m_flDepthOffset;
		DWORD m_unOwnerContext;
		DWORD m_unHorizontalAlign;
		DWORD m_unVerticalAlign;
		DWORD m_unOrientation;
		DWORD m_bAllowInteractionFromAllSceneWorlds;
		DWORD m_vecCSSClasses;
	} C_PointClientUIHUD;

	inline struct C_SpotlightEndOffsets {
		DWORD m_flLightScale;
		DWORD m_Radius;
	} C_SpotlightEnd;

	inline struct CEconItemAttributeOffsets {
		DWORD m_iAttributeDefinitionIndex;
		DWORD m_flValue;
		DWORD m_flInitialValue;
		DWORD m_nRefundableCurrency;
		DWORD m_bSetBonus;
	} CEconItemAttribute;

	inline struct C_PointCameraOffsets {
		DWORD m_FOV;
		DWORD m_Resolution;
		DWORD m_bFogEnable;
		DWORD m_FogColor;
		DWORD m_flFogStart;
		DWORD m_flFogEnd;
		DWORD m_flFogMaxDensity;
		DWORD m_bActive;
		DWORD m_bUseScreenAspectRatio;
		DWORD m_flAspectRatio;
		DWORD m_bNoSky;
		DWORD m_fBrightness;
		DWORD m_flZFar;
		DWORD m_flZNear;
		DWORD m_bCanHLTVUse;
		DWORD m_bAlignWithParent;
		DWORD m_bDofEnabled;
		DWORD m_flDofNearBlurry;
		DWORD m_flDofNearCrisp;
		DWORD m_flDofFarCrisp;
		DWORD m_flDofFarBlurry;
		DWORD m_flDofTiltToGround;
		DWORD m_TargetFOV;
		DWORD m_DegreesPerSecond;
		DWORD m_bIsOn;
		DWORD m_pNext;
	} C_PointCamera;

	inline struct C_EnvWindOffsets {
		DWORD m_EnvWindShared;
	} C_EnvWind;

	inline struct C_BaseCombatCharacterOffsets {
		DWORD m_hMyWearables;
		DWORD m_leftFootAttachment;
		DWORD m_rightFootAttachment;
		DWORD m_nWaterWakeMode;
		DWORD m_flWaterWorldZ;
		DWORD m_flWaterNextTraceTime;
	} C_BaseCombatCharacter;

	inline struct C_SoundEventSphereEntityOffsets {
		DWORD m_flRadius;
	} C_SoundEventSphereEntity;

	inline struct C_SceneEntityOffsets {
		DWORD m_bIsPlayingBack;
		DWORD m_bPaused;
		DWORD m_bMultiplayer;
		DWORD m_bAutogenerated;
		DWORD m_flForceClientTime;
		DWORD m_nSceneStringIndex;
		DWORD m_bClientOnly;
		DWORD m_hOwner;
		DWORD m_hActorList;
		DWORD m_bWasPlaying;
		DWORD m_QueuedEvents;
		DWORD m_flCurrentTime;
	} C_SceneEntity;

	inline struct CPlayer_CameraServicesOffsets {
		DWORD m_vecCsViewPunchAngle;
		DWORD m_nCsViewPunchAngleTick;
		DWORD m_flCsViewPunchAngleTickRatio;
		DWORD m_PlayerFog;
		DWORD m_hColorCorrectionCtrl;
		DWORD m_hViewEntity;
		DWORD m_hTonemapController;
		DWORD m_audio;
		DWORD m_PostProcessingVolumes;
		DWORD m_flOldPlayerZ;
		DWORD m_flOldPlayerViewOffsetZ;
		DWORD m_CurrentFog;
		DWORD m_hOldFogController;
		DWORD m_bOverrideFogColor;
		DWORD m_OverrideFogColor;
		DWORD m_bOverrideFogStartEnd;
		DWORD m_fOverrideFogStart;
		DWORD m_fOverrideFogEnd;
		DWORD m_hActivePostProcessingVolume;
		DWORD m_angDemoViewAngles;
	} CPlayer_CameraServices;

	inline struct C_BaseCSGrenadeOffsets {
		DWORD m_bClientPredictDelete;
		DWORD m_bRedraw;
		DWORD m_bIsHeldByPlayer;
		DWORD m_bPinPulled;
		DWORD m_bJumpThrow;
		DWORD m_bThrowAnimating;
		DWORD m_fThrowTime;
		DWORD m_flThrowStrength;
		DWORD m_flThrowStrengthApproach;
		DWORD m_fDropTime;
		DWORD m_fPinPullTime;
		DWORD m_bJustPulledPin;
		DWORD m_nNextHoldTick;
		DWORD m_flNextHoldFrac;
		DWORD m_hSwitchToWeaponAfterThrow;
	} C_BaseCSGrenade;

	inline struct C_FuncMonitorOffsets {
		DWORD m_targetCamera;
		DWORD m_nResolutionEnum;
		DWORD m_bRenderShadows;
		DWORD m_bUseUniqueColorTarget;
		DWORD m_brushModelName;
		DWORD m_hTargetCamera;
		DWORD m_bEnabled;
		DWORD m_bDraw3DSkybox;
	} C_FuncMonitor;

	inline struct C_RopeKeyframe__CPhysicsDelegateOffsets {
		DWORD m_pKeyframe;
	} C_RopeKeyframe__CPhysicsDelegate;

	inline struct CBodyComponentOffsets {
		DWORD m_pSceneNode;
		DWORD __m_pChainEntity;
	} CBodyComponent;

	inline struct C_SoundAreaEntitySphereOffsets {
		DWORD m_flRadius;
	} C_SoundAreaEntitySphere;

	inline struct C_LightGlowOffsets {
		DWORD m_nHorizontalSize;
		DWORD m_nVerticalSize;
		DWORD m_nMinDist;
		DWORD m_nMaxDist;
		DWORD m_nOuterMaxDist;
		DWORD m_flGlowProxySize;
		DWORD m_flHDRColorScale;
		DWORD m_GlowOverlay;
	} C_LightGlow;

	inline struct CountdownTimerOffsets {
		DWORD m_duration;
		DWORD m_timestamp;
		DWORD m_timescale;
		DWORD m_nWorldGroupId;
	} CountdownTimer;

	inline struct CGameSceneNodeHandleOffsets {
		DWORD m_hOwner;
		DWORD m_name;
	} CGameSceneNodeHandle;

	inline struct PredictedDamageTag_tOffsets {
		DWORD nTagTick;
		DWORD flFlinchModSmall;
		DWORD flFlinchModLarge;
		DWORD flFriendlyFireDamageReductionRatio;
	} PredictedDamageTag_t;

	inline struct C_ClientRagdollOffsets {
		DWORD m_bFadeOut;
		DWORD m_bImportant;
		DWORD m_flEffectTime;
		DWORD m_gibDespawnTime;
		DWORD m_iCurrentFriction;
		DWORD m_iMinFriction;
		DWORD m_iMaxFriction;
		DWORD m_iFrictionAnimState;
		DWORD m_bReleaseRagdoll;
		DWORD m_iEyeAttachment;
		DWORD m_bFadingOut;
		DWORD m_flScaleEnd;
		DWORD m_flScaleTimeStart;
		DWORD m_flScaleTimeEnd;
	} C_ClientRagdoll;

	inline struct C_GlobalLightOffsets {
		DWORD m_WindClothForceHandle;
	} C_GlobalLight;

	inline struct C_CSPlayerResourceOffsets {
		DWORD m_bHostageAlive;
		DWORD m_isHostageFollowingSomeone;
		DWORD m_iHostageEntityIDs;
		DWORD m_bombsiteCenterA;
		DWORD m_bombsiteCenterB;
		DWORD m_hostageRescueX;
		DWORD m_hostageRescueY;
		DWORD m_hostageRescueZ;
		DWORD m_bEndMatchNextMapAllVoted;
		DWORD m_foundGoalPositions;
	} C_CSPlayerResource;

	inline struct CSkeletonInstanceOffsets {
		DWORD m_modelState;
		DWORD m_bIsAnimationEnabled;
		DWORD m_bUseParentRenderBounds;
		DWORD m_bDisableSolidCollisionsForHierarchy;
		DWORD m_bDirtyMotionType;
		DWORD m_bIsGeneratingLatchedParentSpaceState;
		DWORD m_materialGroup;
		DWORD m_nHitboxSet;
	} CSkeletonInstance;

	inline struct CBodyComponentBaseAnimGraphOffsets {
		DWORD m_animationController;
	} CBodyComponentBaseAnimGraph;

	inline struct CBodyComponentPointOffsets {
		DWORD m_sceneNode;
	} CBodyComponentPoint;

	inline struct C_SmokeGrenadeProjectileOffsets {
		DWORD m_nSmokeEffectTickBegin;
		DWORD m_bDidSmokeEffect;
		DWORD m_nRandomSeed;
		DWORD m_vSmokeColor;
		DWORD m_vSmokeDetonationPos;
		DWORD m_VoxelFrameData;
		DWORD m_nVoxelFrameDataSize;
		DWORD m_nVoxelUpdate;
		DWORD m_bSmokeVolumeDataReceived;
		DWORD m_bSmokeEffectSpawned;
	} C_SmokeGrenadeProjectile;

	inline struct C_CSGO_MapPreviewCameraPathOffsets {
		DWORD m_flZFar;
		DWORD m_flZNear;
		DWORD m_bLoop;
		DWORD m_bVerticalFOV;
		DWORD m_bConstantSpeed;
		DWORD m_flDuration;
		DWORD m_flPathLength;
		DWORD m_flPathDuration;
	} C_CSGO_MapPreviewCameraPath;

	inline struct C_InfernoOffsets {
		DWORD m_nfxFireDamageEffect;
		DWORD m_hInfernoPointsSnapshot;
		DWORD m_hInfernoFillerPointsSnapshot;
		DWORD m_hInfernoOutlinePointsSnapshot;
		DWORD m_hInfernoClimbingOutlinePointsSnapshot;
		DWORD m_hInfernoDecalsSnapshot;
		DWORD m_firePositions;
		DWORD m_fireParentPositions;
		DWORD m_bFireIsBurning;
		DWORD m_BurnNormal;
		DWORD m_fireCount;
		DWORD m_nInfernoType;
		DWORD m_nFireLifetime;
		DWORD m_bInPostEffectTime;
		DWORD m_lastFireCount;
		DWORD m_nFireEffectTickBegin;
		DWORD m_drawableCount;
		DWORD m_blosCheck;
		DWORD m_nlosperiod;
		DWORD m_maxFireHalfWidth;
		DWORD m_maxFireHeight;
		DWORD m_minBounds;
		DWORD m_maxBounds;
		DWORD m_flLastGrassBurnThink;
	} C_Inferno;

	inline struct C_PlayerPingOffsets {
		DWORD m_hPlayer;
		DWORD m_hPingedEntity;
		DWORD m_iType;
		DWORD m_bUrgent;
		DWORD m_szPlaceName;
	} C_PlayerPing;

	inline struct C_CSTeamOffsets {
		DWORD m_szTeamMatchStat;
		DWORD m_numMapVictories;
		DWORD m_bSurrendered;
		DWORD m_scoreFirstHalf;
		DWORD m_scoreSecondHalf;
		DWORD m_scoreOvertime;
		DWORD m_szClanTeamname;
		DWORD m_iClanID;
		DWORD m_szTeamFlagImage;
		DWORD m_szTeamLogoImage;
	} C_CSTeam;

	inline struct C_CSGO_MapPreviewCameraPathNodeOffsets {
		DWORD m_szParentPathUniqueID;
		DWORD m_nPathIndex;
		DWORD m_vInTangentLocal;
		DWORD m_vOutTangentLocal;
		DWORD m_flFOV;
		DWORD m_flCameraSpeed;
		DWORD m_flEaseIn;
		DWORD m_flEaseOut;
		DWORD m_vInTangentWorld;
		DWORD m_vOutTangentWorld;
	} C_CSGO_MapPreviewCameraPathNode;

	inline struct C_CSPlayerPawnOffsets {
		DWORD m_pBulletServices;
		DWORD m_pHostageServices;
		DWORD m_pBuyServices;
		DWORD m_pGlowServices;
		DWORD m_pActionTrackingServices;
		DWORD m_pDamageReactServices;
		DWORD m_flHealthShotBoostExpirationTime;
		DWORD m_flLastFiredWeaponTime;
		DWORD m_bHasFemaleVoice;
		DWORD m_flLandingTimeSeconds;
		DWORD m_flOldFallVelocity;
		DWORD m_szLastPlaceName;
		DWORD m_bPrevDefuser;
		DWORD m_bPrevHelmet;
		DWORD m_nPrevArmorVal;
		DWORD m_nPrevGrenadeAmmoCount;
		DWORD m_unPreviousWeaponHash;
		DWORD m_unWeaponHash;
		DWORD m_bInBuyZone;
		DWORD m_bPreviouslyInBuyZone;
		DWORD m_aimPunchAngle;
		DWORD m_aimPunchAngleVel;
		DWORD m_aimPunchTickBase;
		DWORD m_aimPunchTickFraction;
		DWORD m_aimPunchCache;
		DWORD m_bInLanding;
		DWORD m_flLandingStartTime;
		DWORD m_bInHostageRescueZone;
		DWORD m_bInBombZone;
		DWORD m_bIsBuyMenuOpen;
		DWORD m_flTimeOfLastInjury;
		DWORD m_flNextSprayDecalTime;
		DWORD m_iRetakesOffering;
		DWORD m_iRetakesOfferingCard;
		DWORD m_bRetakesHasDefuseKit;
		DWORD m_bRetakesMVPLastRound;
		DWORD m_iRetakesMVPBoostItem;
		DWORD m_RetakesMVPBoostExtraUtility;
		DWORD m_bNeedToReApplyGloves;
		DWORD m_EconGloves;
		DWORD m_nEconGlovesChanged;
		DWORD m_bMustSyncRagdollState;
		DWORD m_nRagdollDamageBone;
		DWORD m_vRagdollDamageForce;
		DWORD m_vRagdollDamagePosition;
		DWORD m_szRagdollDamageWeaponName;
		DWORD m_bRagdollDamageHeadshot;
		DWORD m_vRagdollServerOrigin;
		DWORD m_bLastHeadBoneTransformIsValid;
		DWORD m_lastLandTime;
		DWORD m_bOnGroundLastTick;
		DWORD m_qDeathEyeAngles;
		DWORD m_bSkipOneHeadConstraintUpdate;
		DWORD m_bLeftHanded;
		DWORD m_fSwitchedHandednessTime;
		DWORD m_flViewmodelOffsetX;
		DWORD m_flViewmodelOffsetY;
		DWORD m_flViewmodelOffsetZ;
		DWORD m_flViewmodelFOV;
		DWORD m_vecPlayerPatchEconIndices;
		DWORD m_GunGameImmunityColor;
		DWORD m_vecBulletHitModels;
		DWORD m_bIsWalking;
		DWORD m_thirdPersonHeading;
		DWORD m_flSlopeDropOffset;
		DWORD m_flSlopeDropHeight;
		DWORD m_vHeadConstraintOffset;
		DWORD m_entitySpottedState;
		DWORD m_bIsScoped;
		DWORD m_bResumeZoom;
		DWORD m_bIsDefusing;
		DWORD m_bIsGrabbingHostage;
		DWORD m_iBlockingUseActionInProgress;
		DWORD m_flEmitSoundTime;
		DWORD m_bInNoDefuseArea;
		DWORD m_nWhichBombZone;
		DWORD m_iShotsFired;
		DWORD m_flFlinchStack;
		DWORD m_flVelocityModifier;
		DWORD m_flHitHeading;
		DWORD m_nHitBodyPart;
		DWORD m_bWaitForNoAttack;
		DWORD m_ignoreLadderJumpTime;
		DWORD m_bKilledByHeadshot;
		DWORD m_ArmorValue;
		DWORD m_unCurrentEquipmentValue;
		DWORD m_unRoundStartEquipmentValue;
		DWORD m_unFreezetimeEndEquipmentValue;
		DWORD m_nLastKillerIndex;
		DWORD m_bOldIsScoped;
		DWORD m_bHasDeathInfo;
		DWORD m_flDeathInfoTime;
		DWORD m_vecDeathInfoOrigin;
		DWORD m_grenadeParameterStashTime;
		DWORD m_bGrenadeParametersStashed;
		DWORD m_angStashedShootAngles;
		DWORD m_vecStashedGrenadeThrowPosition;
		DWORD m_vecStashedVelocity;
		DWORD m_angShootAngleHistory;
		DWORD m_vecThrowPositionHistory;
		DWORD m_vecVelocityHistory;
		DWORD m_PredictedDamageTags;
		DWORD m_nPrevHighestReceivedDamageTagTick;
		DWORD m_nHighestAppliedDamageTagTick;
	} C_CSPlayerPawn;

	inline struct C_RagdollPropAttachedOffsets {
		DWORD m_boneIndexAttached;
		DWORD m_ragdollAttachedObjectIndex;
		DWORD m_attachmentPointBoneSpace;
		DWORD m_attachmentPointRagdollSpace;
		DWORD m_vecOffset;
		DWORD m_parentTime;
		DWORD m_bHasParent;
	} C_RagdollPropAttached;

	inline struct C_BaseCSGrenadeProjectileOffsets {
		DWORD m_vInitialPosition;
		DWORD m_vInitialVelocity;
		DWORD m_nBounces;
		DWORD m_nExplodeEffectIndex;
		DWORD m_nExplodeEffectTickBegin;
		DWORD m_vecExplodeEffectOrigin;
		DWORD m_flSpawnTime;
		DWORD vecLastTrailLinePos;
		DWORD flNextTrailLineTime;
		DWORD m_bExplodeEffectBegan;
		DWORD m_bCanCreateGrenadeTrail;
		DWORD m_nSnapshotTrajectoryEffectIndex;
		DWORD m_hSnapshotTrajectoryParticleSnapshot;
		DWORD m_arrTrajectoryTrailPoints;
		DWORD m_arrTrajectoryTrailPointCreationTimes;
		DWORD m_flTrajectoryTrailEffectCreationTime;
	} C_BaseCSGrenadeProjectile;

	inline struct C_BaseTriggerOffsets {
		DWORD m_bDisabled;
		DWORD m_bClientSidePredicted;
	} C_BaseTrigger;

	inline struct C_WeaponBaseItemOffsets {
		DWORD m_SequenceCompleteTimer;
		DWORD m_bRedraw;
	} C_WeaponBaseItem;

	inline struct CEffectDataOffsets {
		DWORD m_vOrigin;
		DWORD m_vStart;
		DWORD m_vNormal;
		DWORD m_vAngles;
		DWORD m_hEntity;
		DWORD m_hOtherEntity;
		DWORD m_flScale;
		DWORD m_flMagnitude;
		DWORD m_flRadius;
		DWORD m_nSurfaceProp;
		DWORD m_nEffectIndex;
		DWORD m_nDamageType;
		DWORD m_nPenetrate;
		DWORD m_nMaterial;
		DWORD m_nHitBox;
		DWORD m_nColor;
		DWORD m_fFlags;
		DWORD m_nAttachmentIndex;
		DWORD m_nAttachmentName;
		DWORD m_iEffectName;
		DWORD m_nExplosionType;
	} CEffectData;

	inline struct C_BaseButtonOffsets {
		DWORD m_glowEntity;
		DWORD m_usable;
		DWORD m_szDisplayText;
	} C_BaseButton;

	inline struct CCSPlayer_ViewModelServicesOffsets {
		DWORD m_hViewModel;
	} CCSPlayer_ViewModelServices;

	inline struct CPlayer_MovementServices_HumanoidOffsets {
		DWORD m_flStepSoundTime;
		DWORD m_flFallVelocity;
		DWORD m_bInCrouch;
		DWORD m_nCrouchState;
		DWORD m_flCrouchTransitionStartTime;
		DWORD m_bDucked;
		DWORD m_bDucking;
		DWORD m_bInDuckJump;
		DWORD m_groundNormal;
		DWORD m_flSurfaceFriction;
		DWORD m_surfaceProps;
		DWORD m_nStepside;
	} CPlayer_MovementServices_Humanoid;

	inline struct C_PointClientUIWorldPanelOffsets {
		DWORD m_bForceRecreateNextUpdate;
		DWORD m_bMoveViewToPlayerNextThink;
		DWORD m_bCheckCSSClasses;
		DWORD m_anchorDeltaTransform;
		DWORD m_pOffScreenIndicator;
		DWORD m_bIgnoreInput;
		DWORD m_bLit;
		DWORD m_bFollowPlayerAcrossTeleport;
		DWORD m_flWidth;
		DWORD m_flHeight;
		DWORD m_flDPI;
		DWORD m_flInteractDistance;
		DWORD m_flDepthOffset;
		DWORD m_unOwnerContext;
		DWORD m_unHorizontalAlign;
		DWORD m_unVerticalAlign;
		DWORD m_unOrientation;
		DWORD m_bAllowInteractionFromAllSceneWorlds;
		DWORD m_vecCSSClasses;
		DWORD m_bOpaque;
		DWORD m_bNoDepth;
		DWORD m_bRenderBackface;
		DWORD m_bUseOffScreenIndicator;
		DWORD m_bExcludeFromSaveGames;
		DWORD m_bGrabbable;
		DWORD m_bOnlyRenderToTexture;
		DWORD m_bDisableMipGen;
		DWORD m_nExplicitImageLayout;
	} C_PointClientUIWorldPanel;

	inline struct CCSGameModeRules_DeathmatchOffsets {
		DWORD m_flDMBonusStartTime;
		DWORD m_flDMBonusTimeLength;
		DWORD m_sDMBonusWeapon;
	} CCSGameModeRules_Deathmatch;

	inline struct C_GameRulesOffsets {
		DWORD __m_pChainEntity;
		DWORD m_nTotalPausedTicks;
		DWORD m_nPauseStartTick;
		DWORD m_bGamePaused;
	} C_GameRules;

	inline struct C_TeamOffsets {
		DWORD m_aPlayerControllers;
		DWORD m_aPlayers;
		DWORD m_iScore;
		DWORD m_szTeamname;
	} C_Team;

	inline struct C_SoundAreaEntityOrientedBoxOffsets {
		DWORD m_vMin;
		DWORD m_vMax;
	} C_SoundAreaEntityOrientedBox;

	inline struct C_TextureBasedAnimatableOffsets {
		DWORD m_bLoop;
		DWORD m_flFPS;
		DWORD m_hPositionKeys;
		DWORD m_hRotationKeys;
		DWORD m_vAnimationBoundsMin;
		DWORD m_vAnimationBoundsMax;
		DWORD m_flStartTime;
		DWORD m_flStartFrame;
	} C_TextureBasedAnimatable;

	inline struct CCSPlayer_WaterServicesOffsets {
		DWORD m_flWaterJumpTime;
		DWORD m_vecWaterJumpVel;
		DWORD m_flSwimSoundTime;
	} CCSPlayer_WaterServices;

	inline struct CSkyboxReferenceOffsets {
		DWORD m_worldGroupId;
		DWORD m_hSkyCamera;
	} CSkyboxReference;

	inline struct CProjectedTextureBaseOffsets {
		DWORD m_hTargetEntity;
		DWORD m_bState;
		DWORD m_bAlwaysUpdate;
		DWORD m_flLightFOV;
		DWORD m_bEnableShadows;
		DWORD m_bSimpleProjection;
		DWORD m_bLightOnlyTarget;
		DWORD m_bLightWorld;
		DWORD m_bCameraSpace;
		DWORD m_flBrightnessScale;
		DWORD m_LightColor;
		DWORD m_flIntensity;
		DWORD m_flLinearAttenuation;
		DWORD m_flQuadraticAttenuation;
		DWORD m_bVolumetric;
		DWORD m_flVolumetricIntensity;
		DWORD m_flNoiseStrength;
		DWORD m_flFlashlightTime;
		DWORD m_nNumPlanes;
		DWORD m_flPlaneOffset;
		DWORD m_flColorTransitionTime;
		DWORD m_flAmbient;
		DWORD m_SpotlightTextureName;
		DWORD m_nSpotlightTextureFrame;
		DWORD m_nShadowQuality;
		DWORD m_flNearZ;
		DWORD m_flFarZ;
		DWORD m_flProjectionSize;
		DWORD m_flRotation;
		DWORD m_bFlipHorizontal;
	} CProjectedTextureBase;

	inline struct CCSPlayerController_InventoryServicesOffsets {
		DWORD m_unMusicID;
		DWORD m_rank;
		DWORD m_nPersonaDataPublicLevel;
		DWORD m_nPersonaDataPublicCommendsLeader;
		DWORD m_nPersonaDataPublicCommendsTeacher;
		DWORD m_nPersonaDataPublicCommendsFriendly;
		DWORD m_nPersonaDataXpTrailLevel;
		DWORD m_vecServerAuthoritativeWeaponSlots;
	} CCSPlayerController_InventoryServices;

	inline struct C_CSGOViewModelOffsets {
		DWORD m_bShouldIgnoreOffsetAndAccuracy;
		DWORD m_nLastKnownAssociatedWeaponEntIndex;
		DWORD m_bNeedToQueueHighResComposite;
		DWORD m_vLoweredWeaponOffset;
	} C_CSGOViewModel;

	inline struct CScriptComponentOffsets {
		DWORD m_scriptClassName;
	} CScriptComponent;

	inline struct C_EnvLightProbeVolumeOffsets {
		DWORD m_Entity_hLightProbeTexture;
		DWORD m_Entity_hLightProbeDirectLightIndicesTexture;
		DWORD m_Entity_hLightProbeDirectLightScalarsTexture;
		DWORD m_Entity_hLightProbeDirectLightShadowsTexture;
		DWORD m_Entity_vBoxMins;
		DWORD m_Entity_vBoxMaxs;
		DWORD m_Entity_bMoveable;
		DWORD m_Entity_nHandshake;
		DWORD m_Entity_nPriority;
		DWORD m_Entity_bStartDisabled;
		DWORD m_Entity_nLightProbeSizeX;
		DWORD m_Entity_nLightProbeSizeY;
		DWORD m_Entity_nLightProbeSizeZ;
		DWORD m_Entity_nLightProbeAtlasX;
		DWORD m_Entity_nLightProbeAtlasY;
		DWORD m_Entity_nLightProbeAtlasZ;
		DWORD m_Entity_bEnabled;
	} C_EnvLightProbeVolume;

	inline struct C_ViewmodelAttachmentModelOffsets {
		DWORD m_bShouldFrontFaceCullLeftHanded;
		DWORD m_bCreatedLeftHanded;
	} C_ViewmodelAttachmentModel;

	inline struct CSPerRoundStats_tOffsets {
		DWORD m_iKills;
		DWORD m_iDeaths;
		DWORD m_iAssists;
		DWORD m_iDamage;
		DWORD m_iEquipmentValue;
		DWORD m_iMoneySaved;
		DWORD m_iKillReward;
		DWORD m_iLiveTime;
		DWORD m_iHeadShotKills;
		DWORD m_iObjective;
		DWORD m_iCashEarned;
		DWORD m_iUtilityDamage;
		DWORD m_iEnemiesFlashed;
	} CSPerRoundStats_t;

	inline struct CRagdollManagerOffsets {
		DWORD m_iCurrentMaxRagdollCount;
	} CRagdollManager;

	inline struct C_TeamRoundTimerOffsets {
		DWORD m_bTimerPaused;
		DWORD m_flTimeRemaining;
		DWORD m_flTimerEndTime;
		DWORD m_bIsDisabled;
		DWORD m_bShowInHUD;
		DWORD m_nTimerLength;
		DWORD m_nTimerInitialLength;
		DWORD m_nTimerMaxLength;
		DWORD m_bAutoCountdown;
		DWORD m_nSetupTimeLength;
		DWORD m_nState;
		DWORD m_bStartPaused;
		DWORD m_bInCaptureWatchState;
		DWORD m_flTotalTime;
		DWORD m_bStopWatchTimer;
		DWORD m_bFireFinished;
		DWORD m_bFire5MinRemain;
		DWORD m_bFire4MinRemain;
		DWORD m_bFire3MinRemain;
		DWORD m_bFire2MinRemain;
		DWORD m_bFire1MinRemain;
		DWORD m_bFire30SecRemain;
		DWORD m_bFire10SecRemain;
		DWORD m_bFire5SecRemain;
		DWORD m_bFire4SecRemain;
		DWORD m_bFire3SecRemain;
		DWORD m_bFire2SecRemain;
		DWORD m_bFire1SecRemain;
		DWORD m_nOldTimerLength;
		DWORD m_nOldTimerState;
	} C_TeamRoundTimer;

	inline struct WeaponPurchaseCount_tOffsets {
		DWORD m_nItemDefIndex;
		DWORD m_nCount;
	} WeaponPurchaseCount_t;

	inline struct CPathSimpleOffsets {
		DWORD m_pathString;
	} CPathSimple;

	inline struct CCSPlayerBase_CameraServicesOffsets {
		DWORD m_iFOV;
		DWORD m_iFOVStart;
		DWORD m_flFOVTime;
		DWORD m_flFOVRate;
		DWORD m_hZoomOwner;
		DWORD m_flLastShotFOV;
	} CCSPlayerBase_CameraServices;

	inline struct CPointOffScreenIndicatorUiOffsets {
		DWORD m_bBeenEnabled;
		DWORD m_bHide;
		DWORD m_flSeenTargetTime;
		DWORD m_pTargetPanel;
	} CPointOffScreenIndicatorUi;

	inline struct C_CSWeaponBaseGunOffsets {
		DWORD m_zoomLevel;
		DWORD m_iBurstShotsRemaining;
		DWORD m_iSilencerBodygroup;
		DWORD m_silencedModelIndex;
		DWORD m_inPrecache;
		DWORD m_bNeedsBoltAction;
	} C_CSWeaponBaseGun;

	inline struct C_SkyCameraOffsets {
		DWORD m_skyboxData;
		DWORD m_skyboxSlotToken;
		DWORD m_bUseAngles;
		DWORD m_pNext;
	} C_SkyCamera;

	inline struct C_EntityDissolveOffsets {
		DWORD m_flStartTime;
		DWORD m_flFadeInStart;
		DWORD m_flFadeInLength;
		DWORD m_flFadeOutModelStart;
		DWORD m_flFadeOutModelLength;
		DWORD m_flFadeOutStart;
		DWORD m_flFadeOutLength;
		DWORD m_flNextSparkTime;
		DWORD m_nDissolveType;
		DWORD m_vDissolverOrigin;
		DWORD m_nMagnitude;
		DWORD m_bCoreExplode;
		DWORD m_bLinkedToServerEnt;
	} C_EntityDissolve;

	inline struct C_fogplayerparams_tOffsets {
		DWORD m_hCtrl;
		DWORD m_flTransitionTime;
		DWORD m_OldColor;
		DWORD m_flOldStart;
		DWORD m_flOldEnd;
		DWORD m_flOldMaxDensity;
		DWORD m_flOldHDRColorScale;
		DWORD m_flOldFarZ;
		DWORD m_NewColor;
		DWORD m_flNewStart;
		DWORD m_flNewEnd;
		DWORD m_flNewMaxDensity;
		DWORD m_flNewHDRColorScale;
		DWORD m_flNewFarZ;
	} C_fogplayerparams_t;

	inline struct C_CSPlayerPawnBaseOffsets {
		DWORD m_pPingServices;
		DWORD m_pViewModelServices;
		DWORD m_fRenderingClipPlane;
		DWORD m_nLastClipPlaneSetupFrame;
		DWORD m_vecLastClipCameraPos;
		DWORD m_vecLastClipCameraForward;
		DWORD m_bClipHitStaticWorld;
		DWORD m_bCachedPlaneIsValid;
		DWORD m_pClippingWeapon;
		DWORD m_previousPlayerState;
		DWORD m_iPlayerState;
		DWORD m_bIsRescuing;
		DWORD m_fImmuneToGunGameDamageTime;
		DWORD m_fImmuneToGunGameDamageTimeLast;
		DWORD m_bGunGameImmunity;
		DWORD m_bHasMovedSinceSpawn;
		DWORD m_fMolotovUseTime;
		DWORD m_fMolotovDamageTime;
		DWORD m_iThrowGrenadeCounter;
		DWORD m_flLastSpawnTimeIndex;
		DWORD m_iProgressBarDuration;
		DWORD m_flProgressBarStartTime;
		DWORD m_vecIntroStartEyePosition;
		DWORD m_vecIntroStartPlayerForward;
		DWORD m_flClientDeathTime;
		DWORD m_bScreenTearFrameCaptured;
		DWORD m_flFlashBangTime;
		DWORD m_flFlashScreenshotAlpha;
		DWORD m_flFlashOverlayAlpha;
		DWORD m_bFlashBuildUp;
		DWORD m_bFlashDspHasBeenCleared;
		DWORD m_bFlashScreenshotHasBeenGrabbed;
		DWORD m_flFlashMaxAlpha;
		DWORD m_flFlashDuration;
		DWORD m_iHealthBarRenderMaskIndex;
		DWORD m_flHealthFadeValue;
		DWORD m_flHealthFadeAlpha;
		DWORD m_flDeathCCWeight;
		DWORD m_flPrevRoundEndTime;
		DWORD m_flPrevMatchEndTime;
		DWORD m_angEyeAngles;
		DWORD m_fNextThinkPushAway;
		DWORD m_bShouldAutobuyDMWeapons;
		DWORD m_bShouldAutobuyNow;
		DWORD m_iIDEntIndex;
		DWORD m_delayTargetIDTimer;
		DWORD m_iTargetItemEntIdx;
		DWORD m_iOldIDEntIndex;
		DWORD m_holdTargetIDTimer;
		DWORD m_flCurrentMusicStartTime;
		DWORD m_flMusicRoundStartTime;
		DWORD m_bDeferStartMusicOnWarmup;
		DWORD m_cycleLatch;
		DWORD m_serverIntendedCycle;
		DWORD m_flLastSmokeOverlayAlpha;
		DWORD m_flLastSmokeAge;
		DWORD m_vLastSmokeOverlayColor;
		DWORD m_nPlayerSmokedFx;
		DWORD m_nPlayerInfernoBodyFx;
		DWORD m_nPlayerInfernoFootFx;
		DWORD m_flNextMagDropTime;
		DWORD m_nLastMagDropAttachmentIndex;
		DWORD m_vecLastAliveLocalVelocity;
		DWORD m_bGuardianShouldSprayCustomXMark;
		DWORD m_hOriginalController;
	} C_CSPlayerPawnBase;

	inline struct C_EnvWindSharedOffsets {
		DWORD m_flStartTime;
		DWORD m_iWindSeed;
		DWORD m_iMinWind;
		DWORD m_iMaxWind;
		DWORD m_windRadius;
		DWORD m_iMinGust;
		DWORD m_iMaxGust;
		DWORD m_flMinGustDelay;
		DWORD m_flMaxGustDelay;
		DWORD m_flGustDuration;
		DWORD m_iGustDirChange;
		DWORD m_location;
		DWORD m_iszGustSound;
		DWORD m_iWindDir;
		DWORD m_flWindSpeed;
		DWORD m_currentWindVector;
		DWORD m_CurrentSwayVector;
		DWORD m_PrevSwayVector;
		DWORD m_iInitialWindDir;
		DWORD m_flInitialWindSpeed;
		DWORD m_flVariationTime;
		DWORD m_flSwayTime;
		DWORD m_flSimTime;
		DWORD m_flSwitchTime;
		DWORD m_flAveWindSpeed;
		DWORD m_bGusting;
		DWORD m_flWindAngleVariation;
		DWORD m_flWindSpeedVariation;
		DWORD m_hEntOwner;
	} C_EnvWindShared;

	inline struct C_PostProcessingVolumeOffsets {
		DWORD m_hPostSettings;
		DWORD m_flFadeDuration;
		DWORD m_flMinLogExposure;
		DWORD m_flMaxLogExposure;
		DWORD m_flMinExposure;
		DWORD m_flMaxExposure;
		DWORD m_flExposureCompensation;
		DWORD m_flExposureFadeSpeedUp;
		DWORD m_flExposureFadeSpeedDown;
		DWORD m_flTonemapEVSmoothingRange;
		DWORD m_bMaster;
		DWORD m_bExposureControl;
		DWORD m_flRate;
		DWORD m_flTonemapPercentTarget;
		DWORD m_flTonemapPercentBrightPixels;
		DWORD m_flTonemapMinAvgLum;
	} C_PostProcessingVolume;

	inline struct CCSPlayer_PingServicesOffsets {
		DWORD m_hPlayerPing;
	} CCSPlayer_PingServices;

	inline struct C_AttributeContainerOffsets {
		DWORD m_Item;
		DWORD m_iExternalItemProviderRegisteredToken;
		DWORD m_ullRegisteredAsItemID;
	} C_AttributeContainer;

	inline struct C_BaseFireOffsets {
		DWORD m_flScale;
		DWORD m_flStartScale;
		DWORD m_flScaleTime;
		DWORD m_nFlags;
	} C_BaseFire;

	inline struct CBasePlayerControllerOffsets {
		DWORD m_nFinalPredictedTick;
		DWORD m_CommandContext;
		DWORD m_nInButtonsWhichAreToggles;
		DWORD m_nTickBase;
		DWORD m_hPawn;
		DWORD m_bKnownTeamMismatch;
		DWORD m_hPredictedPawn;
		DWORD m_nSplitScreenSlot;
		DWORD m_hSplitOwner;
		DWORD m_hSplitScreenPlayers;
		DWORD m_bIsHLTV;
		DWORD m_iConnected;
		DWORD m_iszPlayerName;
		DWORD m_steamID;
		DWORD m_bIsLocalPlayerController;
		DWORD m_iDesiredFOV;
	} CBasePlayerController;

	inline struct C_DecoyProjectileOffsets {
		DWORD m_nDecoyShotTick;
		DWORD m_nClientLastKnownDecoyShotTick;
		DWORD m_flTimeParticleEffectSpawn;
	} C_DecoyProjectile;

	inline struct C_CSGO_PreviewPlayerOffsets {
		DWORD m_animgraph;
		DWORD m_animgraphCharacterModeString;
		DWORD m_flInitialModelScale;
	} C_CSGO_PreviewPlayer;

	inline struct CBaseAnimGraphControllerOffsets {
		DWORD m_animGraphNetworkedVars;
		DWORD m_bSequenceFinished;
		DWORD m_flSoundSyncTime;
		DWORD m_nActiveIKChainMask;
		DWORD m_hSequence;
		DWORD m_flSeqStartTime;
		DWORD m_flSeqFixedCycle;
		DWORD m_nAnimLoopMode;
		DWORD m_flPlaybackRate;
		DWORD m_nNotifyState;
		DWORD m_bNetworkedAnimationInputsChanged;
		DWORD m_bNetworkedSequenceChanged;
		DWORD m_bLastUpdateSkipped;
		DWORD m_flPrevAnimUpdateTime;
	} CBaseAnimGraphController;

	inline struct C_C4Offsets {
		DWORD m_szScreenText;
		DWORD m_activeLightParticleIndex;
		DWORD m_eActiveLightEffect;
		DWORD m_bStartedArming;
		DWORD m_fArmedTime;
		DWORD m_bBombPlacedAnimation;
		DWORD m_bIsPlantingViaUse;
		DWORD m_entitySpottedState;
		DWORD m_nSpotRules;
		DWORD m_bPlayedArmingBeeps;
		DWORD m_bBombPlanted;
	} C_C4;

	inline struct CBaseAnimGraphOffsets {
		DWORD m_bInitiallyPopulateInterpHistory;
		DWORD m_bSuppressAnimEventSounds;
		DWORD m_bAnimGraphUpdateEnabled;
		DWORD m_flMaxSlopeDistance;
		DWORD m_vLastSlopeCheckPos;
		DWORD m_bAnimationUpdateScheduled;
		DWORD m_vecForce;
		DWORD m_nForceBone;
		DWORD m_pClientsideRagdoll;
		DWORD m_bBuiltRagdoll;
		DWORD m_RagdollPose;
		DWORD m_bRagdollClientSide;
		DWORD m_bHasAnimatedMaterialAttributes;
	} CBaseAnimGraph;

	inline struct C_PathParticleRopeOffsets {
		DWORD m_bStartActive;
		DWORD m_flMaxSimulationTime;
		DWORD m_iszEffectName;
		DWORD m_PathNodes_Name;
		DWORD m_flParticleSpacing;
		DWORD m_flSlack;
		DWORD m_flRadius;
		DWORD m_ColorTint;
		DWORD m_nEffectState;
		DWORD m_iEffectIndex;
		DWORD m_PathNodes_Position;
		DWORD m_PathNodes_TangentIn;
		DWORD m_PathNodes_TangentOut;
		DWORD m_PathNodes_Color;
		DWORD m_PathNodes_PinEnabled;
		DWORD m_PathNodes_RadiusScale;
	} C_PathParticleRope;

	inline struct C_SoundEventAABBEntityOffsets {
		DWORD m_vMins;
		DWORD m_vMaxs;
	} C_SoundEventAABBEntity;

	inline struct C_BasePlayerWeaponOffsets {
		DWORD m_nNextPrimaryAttackTick;
		DWORD m_flNextPrimaryAttackTickRatio;
		DWORD m_nNextSecondaryAttackTick;
		DWORD m_flNextSecondaryAttackTickRatio;
		DWORD m_iClip1;
		DWORD m_iClip2;
		DWORD m_pReserveAmmo;
	} C_BasePlayerWeapon;

	inline struct CBasePlayerWeaponVDataOffsets {
		DWORD m_szWorldModel;
		DWORD m_sToolsOnlyOwnerModelName;
		DWORD m_bBuiltRightHanded;
		DWORD m_bAllowFlipping;
		DWORD m_sMuzzleAttachment;
		DWORD m_szMuzzleFlashParticle;
		DWORD m_bLinkedCooldowns;
		DWORD m_iFlags;
		DWORD m_nPrimaryAmmoType;
		DWORD m_nSecondaryAmmoType;
		DWORD m_iMaxClip1;
		DWORD m_iMaxClip2;
		DWORD m_iDefaultClip1;
		DWORD m_iDefaultClip2;
		DWORD m_bReserveAmmoAsClips;
		DWORD m_iWeight;
		DWORD m_bAutoSwitchTo;
		DWORD m_bAutoSwitchFrom;
		DWORD m_iRumbleEffect;
		DWORD m_iSlot;
		DWORD m_iPosition;
		DWORD m_aShootSounds;
	} CBasePlayerWeaponVData;

	inline struct C_FishOffsets {
		DWORD m_pos;
		DWORD m_vel;
		DWORD m_angles;
		DWORD m_localLifeState;
		DWORD m_deathDepth;
		DWORD m_deathAngle;
		DWORD m_buoyancy;
		DWORD m_wiggleTimer;
		DWORD m_wigglePhase;
		DWORD m_wiggleRate;
		DWORD m_actualPos;
		DWORD m_actualAngles;
		DWORD m_poolOrigin;
		DWORD m_waterLevel;
		DWORD m_gotUpdate;
		DWORD m_x;
		DWORD m_y;
		DWORD m_z;
		DWORD m_angle;
		DWORD m_errorHistory;
		DWORD m_errorHistoryIndex;
		DWORD m_errorHistoryCount;
		DWORD m_averageError;
	} C_Fish;

	inline struct CTimelineOffsets {
		DWORD m_flValues;
		DWORD m_nValueCounts;
		DWORD m_nBucketCount;
		DWORD m_flInterval;
		DWORD m_flFinalValue;
		DWORD m_nCompressionType;
		DWORD m_bStopped;
	} CTimeline;

	inline struct C_BasePlayerPawnOffsets {
		DWORD m_pWeaponServices;
		DWORD m_pItemServices;
		DWORD m_pAutoaimServices;
		DWORD m_pObserverServices;
		DWORD m_pWaterServices;
		DWORD m_pUseServices;
		DWORD m_pFlashlightServices;
		DWORD m_pCameraServices;
		DWORD m_pMovementServices;
		DWORD m_ServerViewAngleChanges;
		DWORD m_nHighestConsumedServerViewAngleChangeIndex;
		DWORD v_angle;
		DWORD v_anglePrevious;
		DWORD m_iHideHUD;
		DWORD m_skybox3d;
		DWORD m_flDeathTime;
		DWORD m_vecPredictionError;
		DWORD m_flPredictionErrorTime;
		DWORD m_vecLastCameraSetupLocalOrigin;
		DWORD m_flLastCameraSetupTime;
		DWORD m_flFOVSensitivityAdjust;
		DWORD m_flMouseSensitivity;
		DWORD m_vOldOrigin;
		DWORD m_flOldSimulationTime;
		DWORD m_nLastExecutedCommandNumber;
		DWORD m_nLastExecutedCommandTick;
		DWORD m_hController;
		DWORD m_bIsSwappingToPredictableController;
	} C_BasePlayerPawn;

	inline struct CAttributeManagerOffsets {
		DWORD m_Providers;
		DWORD m_iReapplyProvisionParity;
		DWORD m_hOuter;
		DWORD m_bPreventLoopback;
		DWORD m_ProviderType;
		DWORD m_CachedResults;
	} CAttributeManager;

	inline struct CAnimGraphNetworkedVariablesOffsets {
		DWORD m_PredNetBoolVariables;
		DWORD m_PredNetByteVariables;
		DWORD m_PredNetUInt16Variables;
		DWORD m_PredNetIntVariables;
		DWORD m_PredNetUInt32Variables;
		DWORD m_PredNetUInt64Variables;
		DWORD m_PredNetFloatVariables;
		DWORD m_PredNetVectorVariables;
		DWORD m_PredNetQuaternionVariables;
		DWORD m_PredNetGlobalSymbolVariables;
		DWORD m_OwnerOnlyPredNetBoolVariables;
		DWORD m_OwnerOnlyPredNetByteVariables;
		DWORD m_OwnerOnlyPredNetUInt16Variables;
		DWORD m_OwnerOnlyPredNetIntVariables;
		DWORD m_OwnerOnlyPredNetUInt32Variables;
		DWORD m_OwnerOnlyPredNetUInt64Variables;
		DWORD m_OwnerOnlyPredNetFloatVariables;
		DWORD m_OwnerOnlyPredNetVectorVariables;
		DWORD m_OwnerOnlyPredNetQuaternionVariables;
		DWORD m_OwnerOnlyPredNetGlobalSymbolVariables;
		DWORD m_nBoolVariablesCount;
		DWORD m_nOwnerOnlyBoolVariablesCount;
		DWORD m_nRandomSeedOffset;
		DWORD m_flLastTeleportTime;
	} CAnimGraphNetworkedVariables;

	inline struct C_TriggerBuoyancyOffsets {
		DWORD m_BuoyancyHelper;
		DWORD m_flFluidDensity;
	} C_TriggerBuoyancy;

	inline struct C_RopeKeyframeOffsets {
		DWORD m_LinksTouchingSomething;
		DWORD m_nLinksTouchingSomething;
		DWORD m_bApplyWind;
		DWORD m_fPrevLockedPoints;
		DWORD m_iForcePointMoveCounter;
		DWORD m_bPrevEndPointPos;
		DWORD m_vPrevEndPointPos;
		DWORD m_flCurScroll;
		DWORD m_flScrollSpeed;
		DWORD m_RopeFlags;
		DWORD m_iRopeMaterialModelIndex;
		DWORD m_LightValues;
		DWORD m_nSegments;
		DWORD m_hStartPoint;
		DWORD m_hEndPoint;
		DWORD m_iStartAttachment;
		DWORD m_iEndAttachment;
		DWORD m_Subdiv;
		DWORD m_RopeLength;
		DWORD m_Slack;
		DWORD m_TextureScale;
		DWORD m_fLockedPoints;
		DWORD m_nChangeCount;
		DWORD m_Width;
		DWORD m_PhysicsDelegate;
		DWORD m_hMaterial;
		DWORD m_TextureHeight;
		DWORD m_vecImpulse;
		DWORD m_vecPreviousImpulse;
		DWORD m_flCurrentGustTimer;
		DWORD m_flCurrentGustLifetime;
		DWORD m_flTimeToNextGust;
		DWORD m_vWindDir;
		DWORD m_vColorMod;
		DWORD m_vCachedEndPointAttachmentPos;
		DWORD m_vCachedEndPointAttachmentAngle;
		DWORD m_bConstrainBetweenEndpoints;
		DWORD m_bEndPointAttachmentPositionsDirty;
		DWORD m_bEndPointAttachmentAnglesDirty;
		DWORD m_bNewDataThisFrame;
		DWORD m_bPhysicsInitted;
	} C_RopeKeyframe;

	inline struct C_GradientFogOffsets {
		DWORD m_hGradientFogTexture;
		DWORD m_flFogStartDistance;
		DWORD m_flFogEndDistance;
		DWORD m_bHeightFogEnabled;
		DWORD m_flFogStartHeight;
		DWORD m_flFogEndHeight;
		DWORD m_flFarZ;
		DWORD m_flFogMaxOpacity;
		DWORD m_flFogFalloffExponent;
		DWORD m_flFogVerticalExponent;
		DWORD m_fogColor;
		DWORD m_flFogStrength;
		DWORD m_flFadeTime;
		DWORD m_bStartDisabled;
		DWORD m_bIsEnabled;
		DWORD m_bGradientFogNeedsTextures;
	} C_GradientFog;

	inline struct EntitySpottedState_tOffsets {
		DWORD m_bSpotted;
		DWORD m_bSpottedByMask;
	} EntitySpottedState_t;

	inline struct C_CSGO_TeamPreviewCameraOffsets {
		DWORD m_nVariant;
		DWORD m_bDofEnabled;
		DWORD m_flDofNearBlurry;
		DWORD m_flDofNearCrisp;
		DWORD m_flDofFarCrisp;
		DWORD m_flDofFarBlurry;
		DWORD m_flDofTiltToGround;
	} C_CSGO_TeamPreviewCamera;

	inline struct CCSPlayer_CameraServicesOffsets {
		DWORD m_flDeathCamTilt;
		DWORD m_vClientScopeInaccuracy;
	} CCSPlayer_CameraServices;

	inline struct C_EconWearableOffsets {
		DWORD m_nForceSkin;
		DWORD m_bAlwaysAllow;
	} C_EconWearable;

	inline struct CSMatchStats_tOffsets {
		DWORD m_iEnemy5Ks;
		DWORD m_iEnemy4Ks;
		DWORD m_iEnemy3Ks;
		DWORD m_iEnemyKnifeKills;
		DWORD m_iEnemyTaserKills;
	} CSMatchStats_t;

	inline struct C_EnvVolumetricFogVolumeOffsets {
		DWORD m_bActive;
		DWORD m_vBoxMins;
		DWORD m_vBoxMaxs;
		DWORD m_bStartDisabled;
		DWORD m_flStrength;
		DWORD m_nFalloffShape;
		DWORD m_flFalloffExponent;
		DWORD m_flHeightFogDepth;
		DWORD m_fHeightFogEdgeWidth;
		DWORD m_fIndirectLightStrength;
		DWORD m_fSunLightStrength;
		DWORD m_fNoiseStrength;
		DWORD m_bOverrideIndirectLightStrength;
		DWORD m_bOverrideSunLightStrength;
		DWORD m_bOverrideNoiseStrength;
		DWORD m_bAllowLPVIndirect;
	} C_EnvVolumetricFogVolume;

	inline struct C_FireSmokeOffsets {
		DWORD m_nFlameModelIndex;
		DWORD m_nFlameFromAboveModelIndex;
		DWORD m_flScaleRegister;
		DWORD m_flScaleStart;
		DWORD m_flScaleEnd;
		DWORD m_flScaleTimeStart;
		DWORD m_flScaleTimeEnd;
		DWORD m_flChildFlameSpread;
		DWORD m_flClipPerc;
		DWORD m_bClipTested;
		DWORD m_bFadingOut;
		DWORD m_tParticleSpawn;
		DWORD m_pFireOverlay;
	} C_FireSmoke;

	inline struct C_EnvCombinedLightProbeVolumeOffsets {
		DWORD m_Entity_Color;
		DWORD m_Entity_flBrightness;
		DWORD m_Entity_hCubemapTexture;
		DWORD m_Entity_bCustomCubemapTexture;
		DWORD m_Entity_hLightProbeTexture;
		DWORD m_Entity_hLightProbeDirectLightIndicesTexture;
		DWORD m_Entity_hLightProbeDirectLightScalarsTexture;
		DWORD m_Entity_hLightProbeDirectLightShadowsTexture;
		DWORD m_Entity_vBoxMins;
		DWORD m_Entity_vBoxMaxs;
		DWORD m_Entity_bMoveable;
		DWORD m_Entity_nHandshake;
		DWORD m_Entity_nEnvCubeMapArrayIndex;
		DWORD m_Entity_nPriority;
		DWORD m_Entity_bStartDisabled;
		DWORD m_Entity_flEdgeFadeDist;
		DWORD m_Entity_vEdgeFadeDists;
		DWORD m_Entity_nLightProbeSizeX;
		DWORD m_Entity_nLightProbeSizeY;
		DWORD m_Entity_nLightProbeSizeZ;
		DWORD m_Entity_nLightProbeAtlasX;
		DWORD m_Entity_nLightProbeAtlasY;
		DWORD m_Entity_nLightProbeAtlasZ;
		DWORD m_Entity_bEnabled;
	} C_EnvCombinedLightProbeVolume;

	inline struct ActiveModelConfig_tOffsets {
		DWORD m_Handle;
		DWORD m_Name;
		DWORD m_AssociatedEntities;
		DWORD m_AssociatedEntityNames;
	} ActiveModelConfig_t;

	inline struct CCSPlayer_BulletServicesOffsets {
		DWORD m_totalHitsOnServer;
	} CCSPlayer_BulletServices;

	inline struct CLogicRelayOffsets {
		DWORD m_OnTrigger;
		DWORD m_OnSpawn;
		DWORD m_bDisabled;
		DWORD m_bWaitForRefire;
		DWORD m_bTriggerOnce;
		DWORD m_bFastRetrigger;
		DWORD m_bPassthoughCaller;
	} CLogicRelay;

	inline struct C_PointCameraVFOVOffsets {
		DWORD m_flVerticalFOV;
	} C_PointCameraVFOV;

	inline struct CCSPlayer_ItemServicesOffsets {
		DWORD m_bHasDefuser;
		DWORD m_bHasHelmet;
		DWORD m_bHasHeavyArmor;
	} CCSPlayer_ItemServices;

	inline struct C_BarnLightOffsets {
		DWORD m_bEnabled;
		DWORD m_nColorMode;
		DWORD m_Color;
		DWORD m_flColorTemperature;
		DWORD m_flBrightness;
		DWORD m_flBrightnessScale;
		DWORD m_nDirectLight;
		DWORD m_nBakedShadowIndex;
		DWORD m_nLuminaireShape;
		DWORD m_flLuminaireSize;
		DWORD m_flLuminaireAnisotropy;
		DWORD m_LightStyleString;
		DWORD m_flLightStyleStartTime;
		DWORD m_QueuedLightStyleStrings;
		DWORD m_LightStyleEvents;
		DWORD m_LightStyleTargets;
		DWORD m_StyleEvent;
		DWORD m_hLightCookie;
		DWORD m_flShape;
		DWORD m_flSoftX;
		DWORD m_flSoftY;
		DWORD m_flSkirt;
		DWORD m_flSkirtNear;
		DWORD m_vSizeParams;
		DWORD m_flRange;
		DWORD m_vShear;
		DWORD m_nBakeSpecularToCubemaps;
		DWORD m_vBakeSpecularToCubemapsSize;
		DWORD m_nCastShadows;
		DWORD m_nShadowMapSize;
		DWORD m_nShadowPriority;
		DWORD m_bContactShadow;
		DWORD m_nBounceLight;
		DWORD m_flBounceScale;
		DWORD m_flMinRoughness;
		DWORD m_vAlternateColor;
		DWORD m_fAlternateColorBrightness;
		DWORD m_nFog;
		DWORD m_flFogStrength;
		DWORD m_nFogShadows;
		DWORD m_flFogScale;
		DWORD m_bFogMixedShadows;
		DWORD m_flFadeSizeStart;
		DWORD m_flFadeSizeEnd;
		DWORD m_flShadowFadeSizeStart;
		DWORD m_flShadowFadeSizeEnd;
		DWORD m_bPrecomputedFieldsValid;
		DWORD m_vPrecomputedBoundsMins;
		DWORD m_vPrecomputedBoundsMaxs;
		DWORD m_vPrecomputedOBBOrigin;
		DWORD m_vPrecomputedOBBAngles;
		DWORD m_vPrecomputedOBBExtent;
		DWORD m_nPrecomputedSubFrusta;
		DWORD m_vPrecomputedOBBOrigin0;
		DWORD m_vPrecomputedOBBAngles0;
		DWORD m_vPrecomputedOBBExtent0;
		DWORD m_vPrecomputedOBBOrigin1;
		DWORD m_vPrecomputedOBBAngles1;
		DWORD m_vPrecomputedOBBExtent1;
		DWORD m_vPrecomputedOBBOrigin2;
		DWORD m_vPrecomputedOBBAngles2;
		DWORD m_vPrecomputedOBBExtent2;
		DWORD m_vPrecomputedOBBOrigin3;
		DWORD m_vPrecomputedOBBAngles3;
		DWORD m_vPrecomputedOBBExtent3;
		DWORD m_vPrecomputedOBBOrigin4;
		DWORD m_vPrecomputedOBBAngles4;
		DWORD m_vPrecomputedOBBExtent4;
		DWORD m_vPrecomputedOBBOrigin5;
		DWORD m_vPrecomputedOBBAngles5;
		DWORD m_vPrecomputedOBBExtent5;
		DWORD m_bInitialBoneSetup;
		DWORD m_VisClusters;
	} C_BarnLight;

	inline struct C_TonemapController2Offsets {
		DWORD m_flAutoExposureMin;
		DWORD m_flAutoExposureMax;
		DWORD m_flTonemapPercentTarget;
		DWORD m_flTonemapPercentBrightPixels;
		DWORD m_flTonemapMinAvgLum;
		DWORD m_flExposureAdaptationSpeedUp;
		DWORD m_flExposureAdaptationSpeedDown;
		DWORD m_flTonemapEVSmoothingRange;
	} C_TonemapController2;

	inline struct CFuncWaterOffsets {
		DWORD m_BuoyancyHelper;
	} CFuncWater;

	inline struct C_EconEntityOffsets {
		DWORD m_flFlexDelayTime;
		DWORD m_flFlexDelayedWeight;
		DWORD m_bAttributesInitialized;
		DWORD m_AttributeManager;
		DWORD m_OriginalOwnerXuidLow;
		DWORD m_OriginalOwnerXuidHigh;
		DWORD m_nFallbackPaintKit;
		DWORD m_nFallbackSeed;
		DWORD m_flFallbackWear;
		DWORD m_nFallbackStatTrak;
		DWORD m_bClientside;
		DWORD m_bParticleSystemsCreated;
		DWORD m_vecAttachedParticles;
		DWORD m_hViewmodelAttachment;
		DWORD m_iOldTeam;
		DWORD m_bAttachmentDirty;
		DWORD m_nUnloadedModelIndex;
		DWORD m_iNumOwnerValidationRetries;
		DWORD m_hOldProvidee;
		DWORD m_vecAttachedModels;
	} C_EconEntity;

	inline struct C_RectLightOffsets {
		DWORD m_bShowLight;
	} C_RectLight;

	inline struct C_ParticleSystemOffsets {
		DWORD m_szSnapshotFileName;
		DWORD m_bActive;
		DWORD m_bFrozen;
		DWORD m_flFreezeTransitionDuration;
		DWORD m_nStopType;
		DWORD m_bAnimateDuringGameplayPause;
		DWORD m_iEffectIndex;
		DWORD m_flStartTime;
		DWORD m_flPreSimTime;
		DWORD m_vServerControlPoints;
		DWORD m_iServerControlPointAssignments;
		DWORD m_hControlPointEnts;
		DWORD m_bNoSave;
		DWORD m_bNoFreeze;
		DWORD m_bNoRamp;
		DWORD m_bStartActive;
		DWORD m_iszEffectName;
		DWORD m_iszControlPointNames;
		DWORD m_nDataCP;
		DWORD m_vecDataCPValue;
		DWORD m_nTintCP;
		DWORD m_clrTint;
		DWORD m_bOldActive;
		DWORD m_bOldFrozen;
	} C_ParticleSystem;

	inline struct C_CSGameRulesProxyOffsets {
		DWORD m_pGameRules;
	} C_CSGameRulesProxy;

	inline struct CPlayer_ObserverServicesOffsets {
		DWORD m_iObserverMode;
		DWORD m_hObserverTarget;
		DWORD m_iObserverLastMode;
		DWORD m_bForcedObserverMode;
		DWORD m_flObserverChaseDistance;
		DWORD m_flObserverChaseDistanceCalcTime;
	} CPlayer_ObserverServices;

	inline struct SequenceHistory_tOffsets {
		DWORD m_hSequence;
		DWORD m_flSeqStartTime;
		DWORD m_flSeqFixedCycle;
		DWORD m_nSeqLoopMode;
		DWORD m_flPlaybackRate;
		DWORD m_flCyclesPerSecond;
	} SequenceHistory_t;

	inline struct C_MultimeterOffsets {
		DWORD m_hTargetC4;
	} C_Multimeter;

	inline struct C_CsmFovOverrideOffsets {
		DWORD m_cameraName;
		DWORD m_flCsmFovOverrideValue;
	} C_CsmFovOverride;

	inline struct C_EnvDecalOffsets {
		DWORD m_hDecalMaterial;
		DWORD m_flWidth;
		DWORD m_flHeight;
		DWORD m_flDepth;
		DWORD m_nRenderOrder;
		DWORD m_bProjectOnWorld;
		DWORD m_bProjectOnCharacters;
		DWORD m_bProjectOnWater;
		DWORD m_flDepthSortBias;
	} C_EnvDecal;

	inline struct C_ColorCorrectionOffsets {
		DWORD m_vecOrigin;
		DWORD m_MinFalloff;
		DWORD m_MaxFalloff;
		DWORD m_flFadeInDuration;
		DWORD m_flFadeOutDuration;
		DWORD m_flMaxWeight;
		DWORD m_flCurWeight;
		DWORD m_netlookupFilename;
		DWORD m_bEnabled;
		DWORD m_bMaster;
		DWORD m_bClientSide;
		DWORD m_bExclusive;
		DWORD m_bEnabledOnClient;
		DWORD m_flCurWeightOnClient;
		DWORD m_bFadingIn;
		DWORD m_flFadeStartWeight;
		DWORD m_flFadeStartTime;
		DWORD m_flFadeDuration;
	} C_ColorCorrection;

	inline struct CModelStateOffsets {
		DWORD m_hModel;
		DWORD m_ModelName;
		DWORD m_bClientClothCreationSuppressed;
		DWORD m_MeshGroupMask;
		DWORD m_nIdealMotionType;
		DWORD m_nForceLOD;
		DWORD m_nClothUpdateFlags;
	} CModelState;

	inline struct C_EconEntity__AttachedModelData_tOffsets {
		DWORD m_iModelDisplayFlags;
	} C_EconEntity__AttachedModelData_t;

	inline struct CAttributeListOffsets {
		DWORD m_Attributes;
		DWORD m_pManager;
	} CAttributeList;

	inline struct C_BaseDoorOffsets {
		DWORD m_bIsUsable;
	} C_BaseDoor;

	inline struct CGrenadeTracerOffsets {
		DWORD m_flTracerDuration;
		DWORD m_nType;
	} CGrenadeTracer;

	inline struct CBombTargetOffsets {
		DWORD m_bBombPlantedHere;
	} CBombTarget;

	inline struct C_PointClientUIDialogOffsets {
		DWORD m_hActivator;
		DWORD m_bStartEnabled;
	} C_PointClientUIDialog;

	inline struct CCSGameModeRules_ArmsRaceOffsets {
		DWORD m_WeaponSequence;
	} CCSGameModeRules_ArmsRace;

	inline struct CPointChildModifierOffsets {
		DWORD m_bOrphanInsteadOfDeletingChildrenOnRemove;
	} CPointChildModifier;

	inline struct CDamageRecordOffsets {
		DWORD m_PlayerDamager;
		DWORD m_PlayerRecipient;
		DWORD m_hPlayerControllerDamager;
		DWORD m_hPlayerControllerRecipient;
		DWORD m_szPlayerDamagerName;
		DWORD m_szPlayerRecipientName;
		DWORD m_DamagerXuid;
		DWORD m_RecipientXuid;
		DWORD m_iBulletsDamage;
		DWORD m_iDamage;
		DWORD m_iActualHealthRemoved;
		DWORD m_iNumHits;
		DWORD m_iLastBulletUpdate;
		DWORD m_bIsOtherEnemy;
		DWORD m_killType;
	} CDamageRecord;

	inline struct CCSPlayerController_DamageServicesOffsets {
		DWORD m_nSendUpdate;
		DWORD m_DamageList;
	} CCSPlayerController_DamageServices;

	inline struct CRenderComponentOffsets {
		DWORD __m_pChainEntity;
		DWORD m_bIsRenderingWithViewModels;
		DWORD m_nSplitscreenFlags;
		DWORD m_bEnableRendering;
		DWORD m_bInterpolationReadyToDraw;
	} CRenderComponent;

	inline struct C_SoundEventOBBEntityOffsets {
		DWORD m_vMins;
		DWORD m_vMaxs;
	} C_SoundEventOBBEntity;

	inline struct CLightComponentOffsets {
		DWORD __m_pChainEntity;
		DWORD m_Color;
		DWORD m_SecondaryColor;
		DWORD m_flBrightness;
		DWORD m_flBrightnessScale;
		DWORD m_flBrightnessMult;
		DWORD m_flRange;
		DWORD m_flFalloff;
		DWORD m_flAttenuation0;
		DWORD m_flAttenuation1;
		DWORD m_flAttenuation2;
		DWORD m_flTheta;
		DWORD m_flPhi;
		DWORD m_hLightCookie;
		DWORD m_nCascades;
		DWORD m_nCastShadows;
		DWORD m_nShadowWidth;
		DWORD m_nShadowHeight;
		DWORD m_bRenderDiffuse;
		DWORD m_nRenderSpecular;
		DWORD m_bRenderTransmissive;
		DWORD m_flOrthoLightWidth;
		DWORD m_flOrthoLightHeight;
		DWORD m_nStyle;
		DWORD m_Pattern;
		DWORD m_nCascadeRenderStaticObjects;
		DWORD m_flShadowCascadeCrossFade;
		DWORD m_flShadowCascadeDistanceFade;
		DWORD m_flShadowCascadeDistance0;
		DWORD m_flShadowCascadeDistance1;
		DWORD m_flShadowCascadeDistance2;
		DWORD m_flShadowCascadeDistance3;
		DWORD m_nShadowCascadeResolution0;
		DWORD m_nShadowCascadeResolution1;
		DWORD m_nShadowCascadeResolution2;
		DWORD m_nShadowCascadeResolution3;
		DWORD m_bUsesBakedShadowing;
		DWORD m_nShadowPriority;
		DWORD m_nBakedShadowIndex;
		DWORD m_bRenderToCubemaps;
		DWORD m_nDirectLight;
		DWORD m_nIndirectLight;
		DWORD m_flFadeMinDist;
		DWORD m_flFadeMaxDist;
		DWORD m_flShadowFadeMinDist;
		DWORD m_flShadowFadeMaxDist;
		DWORD m_bEnabled;
		DWORD m_bFlicker;
		DWORD m_bPrecomputedFieldsValid;
		DWORD m_vPrecomputedBoundsMins;
		DWORD m_vPrecomputedBoundsMaxs;
		DWORD m_vPrecomputedOBBOrigin;
		DWORD m_vPrecomputedOBBAngles;
		DWORD m_vPrecomputedOBBExtent;
		DWORD m_flPrecomputedMaxRange;
		DWORD m_nFogLightingMode;
		DWORD m_flFogContributionStength;
		DWORD m_flNearClipPlane;
		DWORD m_SkyColor;
		DWORD m_flSkyIntensity;
		DWORD m_SkyAmbientBounce;
		DWORD m_bUseSecondaryColor;
		DWORD m_bMixedShadows;
		DWORD m_flLightStyleStartTime;
		DWORD m_flCapsuleLength;
		DWORD m_flMinRoughness;
	} CLightComponent;

	inline struct C_EconItemViewOffsets {
		DWORD m_bInventoryImageRgbaRequested;
		DWORD m_bInventoryImageTriedCache;
		DWORD m_nInventoryImageRgbaWidth;
		DWORD m_nInventoryImageRgbaHeight;
		DWORD m_szCurrentLoadCachedFileName;
		DWORD m_bRestoreCustomMaterialAfterPrecache;
		DWORD m_iItemDefinitionIndex;
		DWORD m_iEntityQuality;
		DWORD m_iEntityLevel;
		DWORD m_iItemID;
		DWORD m_iItemIDHigh;
		DWORD m_iItemIDLow;
		DWORD m_iAccountID;
		DWORD m_iInventoryPosition;
		DWORD m_bInitialized;
		DWORD m_bDisallowSOC;
		DWORD m_bIsStoreItem;
		DWORD m_bIsTradeItem;
		DWORD m_iEntityQuantity;
		DWORD m_iRarityOverride;
		DWORD m_iQualityOverride;
		DWORD m_iOriginOverride;
		DWORD m_unClientFlags;
		DWORD m_unOverrideStyle;
		DWORD m_AttributeList;
		DWORD m_NetworkedDynamicAttributes;
		DWORD m_szCustomName;
		DWORD m_szCustomNameOverride;
		DWORD m_bInitializedTags;
	} C_EconItemView;

	inline struct C_HandleTestOffsets {
		DWORD m_Handle;
		DWORD m_bSendHandle;
	} C_HandleTest;

	inline struct C_EnvWindClientsideOffsets {
		DWORD m_EnvWindShared;
	} C_EnvWindClientside;

	inline struct C_WeaponShieldOffsets {
		DWORD m_flDisplayHealth;
	} C_WeaponShield;

	inline struct C_PointClientUIWorldTextPanelOffsets {
		DWORD m_messageText;
	} C_PointClientUIWorldTextPanel;

	inline struct CPlayer_MovementServicesOffsets {
		DWORD m_nImpulse;
		DWORD m_nButtons;
		DWORD m_nQueuedButtonDownMask;
		DWORD m_nQueuedButtonChangeMask;
		DWORD m_nButtonDoublePressed;
		DWORD m_pButtonPressedCmdNumber;
		DWORD m_nLastCommandNumberProcessed;
		DWORD m_nToggleButtonDownMask;
		DWORD m_flMaxspeed;
		DWORD m_arrForceSubtickMoveWhen;
		DWORD m_flForwardMove;
		DWORD m_flLeftMove;
		DWORD m_flUpMove;
		DWORD m_vecLastMovementImpulses;
		DWORD m_vecOldViewAngles;
	} CPlayer_MovementServices;

	inline struct CBasePlayerVDataOffsets {
		DWORD m_sModelName;
		DWORD m_flHeadDamageMultiplier;
		DWORD m_flChestDamageMultiplier;
		DWORD m_flStomachDamageMultiplier;
		DWORD m_flArmDamageMultiplier;
		DWORD m_flLegDamageMultiplier;
		DWORD m_flHoldBreathTime;
		DWORD m_flDrowningDamageInterval;
		DWORD m_nDrowningDamageInitial;
		DWORD m_nDrowningDamageMax;
		DWORD m_nWaterSpeed;
		DWORD m_flUseRange;
		DWORD m_flUseAngleTolerance;
		DWORD m_flCrouchTime;
	} CBasePlayerVData;

	inline struct CCSPlayerController_InGameMoneyServicesOffsets {
		DWORD m_iAccount;
		DWORD m_iStartAccount;
		DWORD m_iTotalCashSpent;
		DWORD m_iCashSpentThisRound;
	} CCSPlayerController_InGameMoneyServices;

	inline struct C_EnvWindShared__WindVariationEvent_tOffsets {
		DWORD m_flWindAngleVariation;
		DWORD m_flWindSpeedVariation;
	} C_EnvWindShared__WindVariationEvent_t;

	inline struct C_EnvParticleGlowOffsets {
		DWORD m_flAlphaScale;
		DWORD m_flRadiusScale;
		DWORD m_flSelfIllumScale;
		DWORD m_ColorTint;
		DWORD m_hTextureOverride;
	} C_EnvParticleGlow;

	inline struct C_SoundEventEntityOffsets {
		DWORD m_bStartOnSpawn;
		DWORD m_bToLocalPlayer;
		DWORD m_bStopOnNew;
		DWORD m_bSaveRestore;
		DWORD m_bSavedIsPlaying;
		DWORD m_flSavedElapsedTime;
		DWORD m_iszSourceEntityName;
		DWORD m_iszAttachmentName;
		DWORD m_onGUIDChanged;
		DWORD m_onSoundFinished;
		DWORD m_flClientCullRadius;
		DWORD m_iszSoundName;
		DWORD m_hSource;
		DWORD m_nEntityIndexSelection;
		DWORD m_bClientSideOnly;
	} C_SoundEventEntity;

	inline struct C_SunOffsets {
		DWORD m_fxSSSunFlareEffectIndex;
		DWORD m_fxSunFlareEffectIndex;
		DWORD m_fdistNormalize;
		DWORD m_vSunPos;
		DWORD m_vDirection;
		DWORD m_iszEffectName;
		DWORD m_iszSSEffectName;
		DWORD m_clrOverlay;
		DWORD m_bOn;
		DWORD m_bmaxColor;
		DWORD m_flSize;
		DWORD m_flHazeScale;
		DWORD m_flRotation;
		DWORD m_flHDRColorScale;
		DWORD m_flAlphaHaze;
		DWORD m_flAlphaScale;
		DWORD m_flAlphaHdr;
		DWORD m_flFarZScale;
	} C_Sun;

	inline struct CCSPlayerController_ActionTrackingServicesOffsets {
		DWORD m_perRoundStats;
		DWORD m_matchStats;
		DWORD m_iNumRoundKills;
		DWORD m_iNumRoundKillsHeadshots;
		DWORD m_unTotalRoundDamageDealt;
	} CCSPlayerController_ActionTrackingServices;

	inline struct CHitboxComponentOffsets {
		DWORD m_bvDisabledHitGroups;
	} CHitboxComponent;

	inline struct C_ColorCorrectionVolumeOffsets {
		DWORD m_LastEnterWeight;
		DWORD m_LastEnterTime;
		DWORD m_LastExitWeight;
		DWORD m_LastExitTime;
		DWORD m_bEnabled;
		DWORD m_MaxWeight;
		DWORD m_FadeDuration;
		DWORD m_Weight;
		DWORD m_lookupFilename;
	} C_ColorCorrectionVolume;

	inline struct C_BulletHitModelOffsets {
		DWORD m_matLocal;
		DWORD m_iBoneIndex;
		DWORD m_hPlayerParent;
		DWORD m_bIsHit;
		DWORD m_flTimeCreated;
		DWORD m_vecStartPos;
	} C_BulletHitModel;

	inline struct C_MapVetoPickControllerOffsets {
		DWORD m_nDraftType;
		DWORD m_nTeamWinningCoinToss;
		DWORD m_nTeamWithFirstChoice;
		DWORD m_nVoteMapIdsList;
		DWORD m_nAccountIDs;
		DWORD m_nMapId0;
		DWORD m_nMapId1;
		DWORD m_nMapId2;
		DWORD m_nMapId3;
		DWORD m_nMapId4;
		DWORD m_nMapId5;
		DWORD m_nStartingSide0;
		DWORD m_nCurrentPhase;
		DWORD m_nPhaseStartTick;
		DWORD m_nPhaseDurationTicks;
		DWORD m_nPostDataUpdateTick;
		DWORD m_bDisabledHud;
	} C_MapVetoPickController;

	inline struct C_OmniLightOffsets {
		DWORD m_flInnerAngle;
		DWORD m_flOuterAngle;
		DWORD m_bShowLight;
	} C_OmniLight;

	inline struct WeaponPurchaseTracker_tOffsets {
		DWORD m_weaponPurchases;
	} WeaponPurchaseTracker_t;

	inline struct C_RetakeGameRulesOffsets {
		DWORD m_nMatchSeed;
		DWORD m_bBlockersPresent;
		DWORD m_bRoundInProgress;
		DWORD m_iFirstSecondHalfRound;
		DWORD m_iBombSite;
	} C_RetakeGameRules;

	inline struct EngineCountdownTimerOffsets {
		DWORD m_duration;
		DWORD m_timestamp;
		DWORD m_timescale;
	} EngineCountdownTimer;

	inline struct C_BaseFlex__Emphasized_PhonemeOffsets {
		DWORD m_sClassName;
		DWORD m_flAmount;
		DWORD m_bRequired;
		DWORD m_bBasechecked;
		DWORD m_bValid;
	} C_BaseFlex__Emphasized_Phoneme;

	inline struct IntervalTimerOffsets {
		DWORD m_timestamp;
		DWORD m_nWorldGroupId;
	} IntervalTimer;

	inline struct C_FuncLadderOffsets {
		DWORD m_vecLadderDir;
		DWORD m_Dismounts;
		DWORD m_vecLocalTop;
		DWORD m_vecPlayerMountPositionTop;
		DWORD m_vecPlayerMountPositionBottom;
		DWORD m_flAutoRideSpeed;
		DWORD m_bDisabled;
		DWORD m_bFakeLadder;
		DWORD m_bHasSlack;
	} C_FuncLadder;

	inline struct CPlayer_WeaponServicesOffsets {
		DWORD m_hMyWeapons;
		DWORD m_hActiveWeapon;
		DWORD m_hLastWeapon;
		DWORD m_iAmmo;
	} CPlayer_WeaponServices;

	inline struct CAttributeManager__cached_attribute_float_tOffsets {
		DWORD flIn;
		DWORD iAttribHook;
		DWORD flOut;
	} CAttributeManager__cached_attribute_float_t;

	inline struct C_BaseGrenadeOffsets {
		DWORD m_bHasWarnedAI;
		DWORD m_bIsSmokeGrenade;
		DWORD m_bIsLive;
		DWORD m_DmgRadius;
		DWORD m_flDetonateTime;
		DWORD m_flWarnAITime;
		DWORD m_flDamage;
		DWORD m_iszBounceSound;
		DWORD m_ExplosionSound;
		DWORD m_hThrower;
		DWORD m_flNextAttack;
		DWORD m_hOriginalThrower;
	} C_BaseGrenade;

	inline struct CCSGameModeRulesOffsets {
		DWORD __m_pChainEntity;
	} CCSGameModeRules;

	inline struct VPhysicsCollisionAttribute_tOffsets {
		DWORD m_nInteractsAs;
		DWORD m_nInteractsWith;
		DWORD m_nInteractsExclude;
		DWORD m_nEntityId;
		DWORD m_nOwnerId;
		DWORD m_nHierarchyId;
		DWORD m_nCollisionGroup;
		DWORD m_nCollisionFunctionMask;
	} VPhysicsCollisionAttribute_t;

	inline struct C_EnvVolumetricFogControllerOffsets {
		DWORD m_flScattering;
		DWORD m_flAnisotropy;
		DWORD m_flFadeSpeed;
		DWORD m_flDrawDistance;
		DWORD m_flFadeInStart;
		DWORD m_flFadeInEnd;
		DWORD m_flIndirectStrength;
		DWORD m_nVolumeDepth;
		DWORD m_fFirstVolumeSliceThickness;
		DWORD m_nIndirectTextureDimX;
		DWORD m_nIndirectTextureDimY;
		DWORD m_nIndirectTextureDimZ;
		DWORD m_vBoxMins;
		DWORD m_vBoxMaxs;
		DWORD m_bActive;
		DWORD m_flStartAnisoTime;
		DWORD m_flStartScatterTime;
		DWORD m_flStartDrawDistanceTime;
		DWORD m_flStartAnisotropy;
		DWORD m_flStartScattering;
		DWORD m_flStartDrawDistance;
		DWORD m_flDefaultAnisotropy;
		DWORD m_flDefaultScattering;
		DWORD m_flDefaultDrawDistance;
		DWORD m_bStartDisabled;
		DWORD m_bEnableIndirect;
		DWORD m_bIndirectUseLPVs;
		DWORD m_bIsMaster;
		DWORD m_hFogIndirectTexture;
		DWORD m_nForceRefreshCount;
		DWORD m_fNoiseSpeed;
		DWORD m_fNoiseStrength;
		DWORD m_vNoiseScale;
		DWORD m_bFirstTime;
	} C_EnvVolumetricFogController;

	inline struct C_PointCommentaryNodeOffsets {
		DWORD m_bActive;
		DWORD m_bWasActive;
		DWORD m_flEndTime;
		DWORD m_flStartTime;
		DWORD m_flStartTimeInCommentary;
		DWORD m_iszCommentaryFile;
		DWORD m_iszTitle;
		DWORD m_iszSpeakers;
		DWORD m_iNodeNumber;
		DWORD m_iNodeNumberMax;
		DWORD m_bListenedTo;
		DWORD m_hViewPosition;
		DWORD m_bRestartAfterRestore;
	} C_PointCommentaryNode;

	inline struct audioparams_tOffsets {
		DWORD localSound;
		DWORD soundscapeIndex;
		DWORD localBits;
		DWORD soundscapeEntityListIndex;
		DWORD soundEventHash;
	} audioparams_t;

	inline struct C_InfoVisibilityBoxOffsets {
		DWORD m_nMode;
		DWORD m_vBoxSize;
		DWORD m_bEnabled;
	} C_InfoVisibilityBox;

	inline struct C_FireSpriteOffsets {
		DWORD m_vecMoveDir;
		DWORD m_bFadeFromAbove;
	} C_FireSprite;

	inline struct C_PrecipitationOffsets {
		DWORD m_flDensity;
		DWORD m_flParticleInnerDist;
		DWORD m_pParticleDef;
		DWORD m_tParticlePrecipTraceTimer;
		DWORD m_bActiveParticlePrecipEmitter;
		DWORD m_bParticlePrecipInitialized;
		DWORD m_bHasSimulatedSinceLastSceneObjectUpdate;
		DWORD m_nAvailableSheetSequencesMaxIndex;
	} C_Precipitation;

	inline struct CPrecipitationVDataOffsets {
		DWORD m_szParticlePrecipitationEffect;
		DWORD m_flInnerDistance;
		DWORD m_nAttachType;
		DWORD m_bBatchSameVolumeType;
		DWORD m_nRTEnvCP;
		DWORD m_nRTEnvCPComponent;
		DWORD m_szModifier;
	} CPrecipitationVData;

	inline struct CBuoyancyHelperOffsets {
		DWORD m_nFluidType;
		DWORD m_flFluidDensity;
		DWORD m_vecFractionOfWheelSubmergedForWheelFriction;
		DWORD m_vecWheelFrictionScales;
		DWORD m_vecFractionOfWheelSubmergedForWheelDrag;
		DWORD m_vecWheelDrag;
	} CBuoyancyHelper;

	inline struct C_BaseClientUIEntityOffsets {
		DWORD m_bEnabled;
		DWORD m_DialogXMLName;
		DWORD m_PanelClassName;
		DWORD m_PanelID;
	} C_BaseClientUIEntity;

	inline struct C_FuncTrackTrainOffsets {
		DWORD m_nLongAxis;
		DWORD m_flRadius;
		DWORD m_flLineLength;
	} C_FuncTrackTrain;

	inline struct CCSPlayer_ActionTrackingServicesOffsets {
		DWORD m_hLastWeaponBeforeC4AutoSwitch;
		DWORD m_bIsRescuing;
		DWORD m_weaponPurchasesThisMatch;
		DWORD m_weaponPurchasesThisRound;
	} CCSPlayer_ActionTrackingServices;

	inline struct shard_model_desc_tOffsets {
		DWORD m_nModelID;
		DWORD m_hMaterialBase;
		DWORD m_hMaterialDamageOverlay;
		DWORD m_solid;
		DWORD m_vecPanelSize;
		DWORD m_vecStressPositionA;
		DWORD m_vecStressPositionB;
		DWORD m_vecPanelVertices;
		DWORD m_vInitialPanelVertices;
		DWORD m_flGlassHalfThickness;
		DWORD m_bHasParent;
		DWORD m_bParentFrozen;
		DWORD m_SurfacePropStringToken;
	} shard_model_desc_t;

	inline struct C_SceneEntity__QueuedEvents_tOffsets {
		DWORD starttime;
	} C_SceneEntity__QueuedEvents_t;

	inline struct CBasePropOffsets {
		DWORD m_bModelOverrodeBlockLOS;
		DWORD m_iShapeType;
		DWORD m_bConformToCollisionBounds;
		DWORD m_mPreferredCatchTransform;
	} CBaseProp;

	inline struct CPointTemplateOffsets {
		DWORD m_iszWorldName;
		DWORD m_iszSource2EntityLumpName;
		DWORD m_iszEntityFilterName;
		DWORD m_flTimeoutInterval;
		DWORD m_bAsynchronouslySpawnEntities;
		DWORD m_pOutputOnSpawned;
		DWORD m_clientOnlyEntityBehavior;
		DWORD m_ownerSpawnGroupType;
		DWORD m_createdSpawnGroupHandles;
		DWORD m_SpawnedEntityHandles;
		DWORD m_ScriptSpawnCallback;
		DWORD m_ScriptCallbackScope;
	} CPointTemplate;

	inline struct C_CSGO_PreviewModelOffsets {
		DWORD m_animgraph;
		DWORD m_animgraphCharacterModeString;
		DWORD m_defaultAnim;
		DWORD m_nDefaultAnimLoopMode;
		DWORD m_flInitialModelScale;
		DWORD m_sInitialWeaponState;
	} C_CSGO_PreviewModel;

	inline struct CInfoDynamicShadowHintOffsets {
		DWORD m_bDisabled;
		DWORD m_flRange;
		DWORD m_nImportance;
		DWORD m_nLightChoice;
		DWORD m_hLight;
	} CInfoDynamicShadowHint;

	inline struct CGlowPropertyOffsets {
		DWORD m_fGlowColor;
		DWORD m_iGlowType;
		DWORD m_iGlowTeam;
		DWORD m_nGlowRange;
		DWORD m_nGlowRangeMin;
		DWORD m_glowColorOverride;
		DWORD m_bFlashing;
		DWORD m_flGlowTime;
		DWORD m_flGlowStartTime;
		DWORD m_bEligibleForScreenHighlight;
		DWORD m_bGlowing;
	} CGlowProperty;

	inline struct C_TriggerPhysicsOffsets {
		DWORD m_gravityScale;
		DWORD m_linearLimit;
		DWORD m_linearDamping;
		DWORD m_angularLimit;
		DWORD m_angularDamping;
		DWORD m_linearForce;
		DWORD m_flFrequency;
		DWORD m_flDampingRatio;
		DWORD m_vecLinearForcePointAt;
		DWORD m_bCollapseToForcePoint;
		DWORD m_vecLinearForcePointAtWorld;
		DWORD m_vecLinearForceDirection;
		DWORD m_bConvertToDebrisWhenPossible;
	} C_TriggerPhysics;

	inline struct CCSPlayer_HostageServicesOffsets {
		DWORD m_hCarriedHostage;
		DWORD m_hCarriedHostageProp;
	} CCSPlayer_HostageServices;

	inline struct C_EnvCubemapOffsets {
		DWORD m_Entity_hCubemapTexture;
		DWORD m_Entity_bCustomCubemapTexture;
		DWORD m_Entity_flInfluenceRadius;
		DWORD m_Entity_vBoxProjectMins;
		DWORD m_Entity_vBoxProjectMaxs;
		DWORD m_Entity_bMoveable;
		DWORD m_Entity_nHandshake;
		DWORD m_Entity_nEnvCubeMapArrayIndex;
		DWORD m_Entity_nPriority;
		DWORD m_Entity_flEdgeFadeDist;
		DWORD m_Entity_vEdgeFadeDists;
		DWORD m_Entity_flDiffuseScale;
		DWORD m_Entity_bStartDisabled;
		DWORD m_Entity_bDefaultEnvMap;
		DWORD m_Entity_bDefaultSpecEnvMap;
		DWORD m_Entity_bIndoorCubeMap;
		DWORD m_Entity_bCopyDiffuseFromDefaultCubemap;
		DWORD m_Entity_bEnabled;
	} C_EnvCubemap;

	inline struct C_PredictedViewModelOffsets {
		DWORD m_vPredictedLagOffset;
		DWORD m_targetSpeed;
		DWORD m_currentSpeed;
	} C_PredictedViewModel;

	inline struct C_PointValueRemapperOffsets {
		DWORD m_bDisabled;
		DWORD m_bDisabledOld;
		DWORD m_bUpdateOnClient;
		DWORD m_nInputType;
		DWORD m_hRemapLineStart;
		DWORD m_hRemapLineEnd;
		DWORD m_flMaximumChangePerSecond;
		DWORD m_flDisengageDistance;
		DWORD m_flEngageDistance;
		DWORD m_bRequiresUseKey;
		DWORD m_nOutputType;
		DWORD m_hOutputEntities;
		DWORD m_nHapticsType;
		DWORD m_nMomentumType;
		DWORD m_flMomentumModifier;
		DWORD m_flSnapValue;
		DWORD m_flCurrentMomentum;
		DWORD m_nRatchetType;
		DWORD m_flRatchetOffset;
		DWORD m_flInputOffset;
		DWORD m_bEngaged;
		DWORD m_bFirstUpdate;
		DWORD m_flPreviousValue;
		DWORD m_flPreviousUpdateTickTime;
		DWORD m_vecPreviousTestPoint;
	} C_PointValueRemapper;

	inline struct C_KnifeOffsets {
		DWORD m_bFirstAttack;
	} C_Knife;

	inline struct C_ItemDogtagsOffsets {
		DWORD m_OwningPlayer;
		DWORD m_KillingPlayer;
	} C_ItemDogtags;

	inline struct C_SoundOpvarSetPointBaseOffsets {
		DWORD m_iszStackName;
		DWORD m_iszOperatorName;
		DWORD m_iszOpvarName;
		DWORD m_iOpvarIndex;
		DWORD m_bUseAutoCompare;
	} C_SoundOpvarSetPointBase;

	inline struct CCSPlayer_BuyServicesOffsets {
		DWORD m_vecSellbackPurchaseEntries;
	} CCSPlayer_BuyServices;

	inline struct C_WeaponTaserOffsets {
		DWORD m_fFireTime;
		DWORD m_nLastAttackTick;
	} C_WeaponTaser;

	inline struct C_FistsOffsets {
		DWORD m_bPlayingUninterruptableAct;
		DWORD m_nUninterruptableActivity;
	} C_Fists;

	inline struct CInfoDynamicShadowHintBoxOffsets {
		DWORD m_vBoxMins;
		DWORD m_vBoxMaxs;
	} CInfoDynamicShadowHintBox;

	inline struct C_EnvCubemapFogOffsets {
		DWORD m_flEndDistance;
		DWORD m_flStartDistance;
		DWORD m_flFogFalloffExponent;
		DWORD m_bHeightFogEnabled;
		DWORD m_flFogHeightWidth;
		DWORD m_flFogHeightEnd;
		DWORD m_flFogHeightStart;
		DWORD m_flFogHeightExponent;
		DWORD m_flLODBias;
		DWORD m_bActive;
		DWORD m_bStartDisabled;
		DWORD m_flFogMaxOpacity;
		DWORD m_nCubemapSourceType;
		DWORD m_hSkyMaterial;
		DWORD m_iszSkyEntity;
		DWORD m_hFogCubemapTexture;
		DWORD m_bHasHeightFogEnd;
		DWORD m_bFirstTime;
	} C_EnvCubemapFog;

	inline struct CCollisionPropertyOffsets {
		DWORD m_collisionAttribute;
		DWORD m_vecMins;
		DWORD m_vecMaxs;
		DWORD m_usSolidFlags;
		DWORD m_nSolidType;
		DWORD m_triggerBloat;
		DWORD m_nSurroundType;
		DWORD m_CollisionGroup;
		DWORD m_nEnablePhysics;
		DWORD m_flBoundingRadius;
		DWORD m_vecSpecifiedSurroundingMins;
		DWORD m_vecSpecifiedSurroundingMaxs;
		DWORD m_vecSurroundingMaxs;
		DWORD m_vecSurroundingMins;
		DWORD m_vCapsuleCenter1;
		DWORD m_vCapsuleCenter2;
		DWORD m_flCapsuleRadius;
	} CCollisionProperty;

	inline struct CNetworkedSequenceOperationOffsets {
		DWORD m_hSequence;
		DWORD m_flPrevCycle;
		DWORD m_flCycle;
		DWORD m_flWeight;
		DWORD m_bSequenceChangeNetworked;
		DWORD m_bDiscontinuity;
		DWORD m_flPrevCycleFromDiscontinuity;
		DWORD m_flPrevCycleForAnimEventDetection;
	} CNetworkedSequenceOperation;

	inline struct C_PlayerSprayDecalOffsets {
		DWORD m_nUniqueID;
		DWORD m_unAccountID;
		DWORD m_unTraceID;
		DWORD m_rtGcTime;
		DWORD m_vecEndPos;
		DWORD m_vecStart;
		DWORD m_vecLeft;
		DWORD m_vecNormal;
		DWORD m_nPlayer;
		DWORD m_nEntity;
		DWORD m_nHitbox;
		DWORD m_flCreationTime;
		DWORD m_nTintID;
		DWORD m_nVersion;
		DWORD m_ubSignature;
		DWORD m_SprayRenderHelper;
	} C_PlayerSprayDecal;

	inline struct EntityRenderAttribute_tOffsets {
		DWORD m_ID;
		DWORD m_Values;
	} EntityRenderAttribute_t;

	inline struct C_ShatterGlassShardPhysicsOffsets {
		DWORD m_ShardDesc;
	} C_ShatterGlassShardPhysics;

	inline struct C_LightEntityOffsets {
		DWORD m_CLightComponent;
	} C_LightEntity;

	inline struct C_PlayerVisibilityOffsets {
		DWORD m_flVisibilityStrength;
		DWORD m_flFogDistanceMultiplier;
		DWORD m_flFogMaxDensityMultiplier;
		DWORD m_flFadeTime;
		DWORD m_bStartDisabled;
		DWORD m_bIsEnabled;
	} C_PlayerVisibility;

	inline struct fogparams_tOffsets {
		DWORD dirPrimary;
		DWORD colorPrimary;
		DWORD colorSecondary;
		DWORD colorPrimaryLerpTo;
		DWORD colorSecondaryLerpTo;
		DWORD start;
		DWORD end;
		DWORD farz;
		DWORD maxdensity;
		DWORD exponent;
		DWORD HDRColorScale;
		DWORD skyboxFogFactor;
		DWORD skyboxFogFactorLerpTo;
		DWORD startLerpTo;
		DWORD endLerpTo;
		DWORD maxdensityLerpTo;
		DWORD lerptime;
		DWORD duration;
		DWORD blendtobackground;
		DWORD scattering;
		DWORD locallightscale;
		DWORD enable;
		DWORD blend;
		DWORD m_bNoReflectionFog;
		DWORD m_bPadding;
	} fogparams_t;

	inline struct C_BaseFlexOffsets {
		DWORD m_flexWeight;
		DWORD m_vLookTargetPosition;
		DWORD m_blinktoggle;
		DWORD m_nLastFlexUpdateFrameCount;
		DWORD m_CachedViewTarget;
		DWORD m_nNextSceneEventId;
		DWORD m_iBlink;
		DWORD m_blinktime;
		DWORD m_prevblinktoggle;
		DWORD m_iJawOpen;
		DWORD m_flJawOpenAmount;
		DWORD m_flBlinkAmount;
		DWORD m_iMouthAttachment;
		DWORD m_iEyeAttachment;
		DWORD m_bResetFlexWeightsOnModelChange;
		DWORD m_nEyeOcclusionRendererBone;
		DWORD m_mEyeOcclusionRendererCameraToBoneTransform;
		DWORD m_vEyeOcclusionRendererHalfExtent;
		DWORD m_PhonemeClasses;
	} C_BaseFlex;

	inline struct C_EnvSkyOffsets {
		DWORD m_hSkyMaterial;
		DWORD m_hSkyMaterialLightingOnly;
		DWORD m_bStartDisabled;
		DWORD m_vTintColor;
		DWORD m_vTintColorLightingOnly;
		DWORD m_flBrightnessScale;
		DWORD m_nFogType;
		DWORD m_flFogMinStart;
		DWORD m_flFogMinEnd;
		DWORD m_flFogMaxStart;
		DWORD m_flFogMaxEnd;
		DWORD m_bEnabled;
	} C_EnvSky;

	inline struct C_DynamicPropOffsets {
		DWORD m_bUseHitboxesForRenderBox;
		DWORD m_bUseAnimGraph;
		DWORD m_pOutputAnimBegun;
		DWORD m_pOutputAnimOver;
		DWORD m_pOutputAnimLoopCycleOver;
		DWORD m_OnAnimReachedStart;
		DWORD m_OnAnimReachedEnd;
		DWORD m_iszIdleAnim;
		DWORD m_nIdleAnimLoopMode;
		DWORD m_bRandomizeCycle;
		DWORD m_bStartDisabled;
		DWORD m_bFiredStartEndOutput;
		DWORD m_bForceNpcExclude;
		DWORD m_bCreateNonSolid;
		DWORD m_bIsOverrideProp;
		DWORD m_iInitialGlowState;
		DWORD m_nGlowRange;
		DWORD m_nGlowRangeMin;
		DWORD m_glowColor;
		DWORD m_nGlowTeam;
		DWORD m_iCachedFrameCount;
		DWORD m_vecCachedRenderMins;
		DWORD m_vecCachedRenderMaxs;
	} C_DynamicProp;

	inline struct CPropDataComponentOffsets {
		DWORD m_flDmgModBullet;
		DWORD m_flDmgModClub;
		DWORD m_flDmgModExplosive;
		DWORD m_flDmgModFire;
		DWORD m_iszPhysicsDamageTableName;
		DWORD m_iszBasePropData;
		DWORD m_nInteractions;
		DWORD m_bSpawnMotionDisabled;
		DWORD m_nDisableTakePhysicsDamageSpawnFlag;
		DWORD m_nMotionDisabledSpawnFlag;
	} CPropDataComponent;

	inline struct C_KeychainModuleOffsets {
		DWORD m_nKeychainDefID;
		DWORD m_nKeychainSeed;
	} C_KeychainModule;

	inline struct CCitadelSoundOpvarSetOBBOffsets {
		DWORD m_iszStackName;
		DWORD m_iszOperatorName;
		DWORD m_iszOpvarName;
		DWORD m_vDistanceInnerMins;
		DWORD m_vDistanceInnerMaxs;
		DWORD m_vDistanceOuterMins;
		DWORD m_vDistanceOuterMaxs;
		DWORD m_nAABBDirection;
	} CCitadelSoundOpvarSetOBB;

	inline struct SellbackPurchaseEntry_tOffsets {
		DWORD m_unDefIdx;
		DWORD m_nCost;
		DWORD m_nPrevArmor;
		DWORD m_bPrevHelmet;
		DWORD m_hItem;
	} SellbackPurchaseEntry_t;

	inline struct C_LocalTempEntityOffsets {
		DWORD flags;
		DWORD die;
		DWORD m_flFrameMax;
		DWORD x;
		DWORD y;
		DWORD fadeSpeed;
		DWORD bounceFactor;
		DWORD hitSound;
		DWORD priority;
		DWORD tentOffset;
		DWORD m_vecTempEntAngVelocity;
		DWORD tempent_renderamt;
		DWORD m_vecNormal;
		DWORD m_flSpriteScale;
		DWORD m_nFlickerFrame;
		DWORD m_flFrameRate;
		DWORD m_flFrame;
		DWORD m_pszImpactEffect;
		DWORD m_pszParticleEffect;
		DWORD m_bParticleCollision;
		DWORD m_iLastCollisionFrame;
		DWORD m_vLastCollisionOrigin;
		DWORD m_vecTempEntVelocity;
		DWORD m_vecPrevAbsOrigin;
		DWORD m_vecTempEntAcceleration;
	} C_LocalTempEntity;

	inline struct C_EnvWindShared__WindAveEvent_tOffsets {
		DWORD m_flStartWindSpeed;
		DWORD m_flAveWindSpeed;
	} C_EnvWindShared__WindAveEvent_t;

	inline struct C_MolotovProjectileOffsets {
		DWORD m_bIsIncGrenade;
	} C_MolotovProjectile;

	inline struct CInfoOffscreenPanoramaTextureOffsets {
		DWORD m_bDisabled;
		DWORD m_nResolutionX;
		DWORD m_nResolutionY;
		DWORD m_szLayoutFileName;
		DWORD m_RenderAttrName;
		DWORD m_TargetEntities;
		DWORD m_nTargetChangeCount;
		DWORD m_vecCSSClasses;
		DWORD m_bCheckCSSClasses;
	} CInfoOffscreenPanoramaTexture;

	inline struct C_DynamicLightOffsets {
		DWORD m_Flags;
		DWORD m_LightStyle;
		DWORD m_Radius;
		DWORD m_Exponent;
		DWORD m_InnerAngle;
		DWORD m_OuterAngle;
		DWORD m_SpotRadius;
	} C_DynamicLight;

	inline struct C_CSWeaponBaseOffsets {
		DWORD m_flFireSequenceStartTime;
		DWORD m_nFireSequenceStartTimeChange;
		DWORD m_nFireSequenceStartTimeAck;
		DWORD m_ePlayerFireEvent;
		DWORD m_ePlayerFireEventAttackType;
		DWORD m_seqIdle;
		DWORD m_seqFirePrimary;
		DWORD m_seqFireSecondary;
		DWORD m_thirdPersonFireSequences;
		DWORD m_hCurrentThirdPersonSequence;
		DWORD m_nSilencerBoneIndex;
		DWORD m_thirdPersonSequences;
		DWORD m_ClientPreviousWeaponState;
		DWORD m_iState;
		DWORD m_flCrosshairDistance;
		DWORD m_iAmmoLastCheck;
		DWORD m_iAlpha;
		DWORD m_iScopeTextureID;
		DWORD m_iCrosshairTextureID;
		DWORD m_flGunAccuracyPositionDeprecated;
		DWORD m_nLastEmptySoundCmdNum;
		DWORD m_nViewModelIndex;
		DWORD m_bReloadsWithClips;
		DWORD m_flTimeWeaponIdle;
		DWORD m_bFireOnEmpty;
		DWORD m_OnPlayerPickup;
		DWORD m_weaponMode;
		DWORD m_flTurningInaccuracyDelta;
		DWORD m_vecTurningInaccuracyEyeDirLast;
		DWORD m_flTurningInaccuracy;
		DWORD m_fAccuracyPenalty;
		DWORD m_flLastAccuracyUpdateTime;
		DWORD m_fAccuracySmoothedForZoom;
		DWORD m_fScopeZoomEndTime;
		DWORD m_iRecoilIndex;
		DWORD m_flRecoilIndex;
		DWORD m_bBurstMode;
		DWORD m_flLastBurstModeChangeTime;
		DWORD m_nPostponeFireReadyTicks;
		DWORD m_flPostponeFireReadyFrac;
		DWORD m_bInReload;
		DWORD m_bReloadVisuallyComplete;
		DWORD m_flDroppedAtTime;
		DWORD m_bIsHauledBack;
		DWORD m_bSilencerOn;
		DWORD m_flTimeSilencerSwitchComplete;
		DWORD m_iOriginalTeamNumber;
		DWORD m_iMostRecentTeamNumber;
		DWORD m_bDroppedNearBuyZone;
		DWORD m_flNextAttackRenderTimeOffset;
		DWORD m_bClearWeaponIdentifyingUGC;
		DWORD m_bVisualsDataSet;
		DWORD m_bOldFirstPersonSpectatedState;
		DWORD m_bUIWeapon;
		DWORD m_nCustomEconReloadEventId;
		DWORD m_nextPrevOwnerUseTime;
		DWORD m_hPrevOwner;
		DWORD m_nDropTick;
		DWORD m_donated;
		DWORD m_fLastShotTime;
		DWORD m_bWasOwnedByCT;
		DWORD m_bWasOwnedByTerrorist;
		DWORD m_gunHeat;
		DWORD m_smokeAttachments;
		DWORD m_lastSmokeTime;
		DWORD m_flNextClientFireBulletTime;
		DWORD m_flNextClientFireBulletTime_Repredict;
		DWORD m_IronSightController;
		DWORD m_iIronSightMode;
		DWORD m_flLastLOSTraceFailureTime;
		DWORD m_iNumEmptyAttacks;
		DWORD m_flLastMagDropRequestTime;
		DWORD m_flWatTickOffset;
	} C_CSWeaponBase;

	inline struct C_FuncElectrifiedVolumeOffsets {
		DWORD m_nAmbientEffect;
		DWORD m_EffectName;
		DWORD m_bState;
	} C_FuncElectrifiedVolume;

	inline struct CCSPlayer_WeaponServicesOffsets {
		DWORD m_flNextAttack;
		DWORD m_bIsLookingAtWeapon;
		DWORD m_bIsHoldingLookAtWeapon;
		DWORD m_nOldShootPositionHistoryCount;
		DWORD m_nOldInputHistoryCount;
	} CCSPlayer_WeaponServices;

	inline struct C_EnvDetailControllerOffsets {
		DWORD m_flFadeStartDist;
		DWORD m_flFadeEndDist;
	} C_EnvDetailController;

	inline struct C_BaseEntityOffsets {
		DWORD m_CBodyComponent;
		DWORD m_NetworkTransmitComponent;
		DWORD m_nLastThinkTick;
		DWORD m_pGameSceneNode;
		DWORD m_pRenderComponent;
		DWORD m_pCollision;
		DWORD m_iMaxHealth;
		DWORD m_iHealth;
		DWORD m_lifeState;
		DWORD m_bTakesDamage;
		DWORD m_nTakeDamageFlags;
		DWORD m_nPlatformType;
		DWORD m_ubInterpolationFrame;
		DWORD m_hSceneObjectController;
		DWORD m_nNoInterpolationTick;
		DWORD m_nVisibilityNoInterpolationTick;
		DWORD m_flProxyRandomValue;
		DWORD m_iEFlags;
		DWORD m_nWaterType;
		DWORD m_bInterpolateEvenWithNoModel;
		DWORD m_bPredictionEligible;
		DWORD m_bApplyLayerMatchIDToModel;
		DWORD m_tokLayerMatchID;
		DWORD m_nSubclassID;
		DWORD m_nSimulationTick;
		DWORD m_iCurrentThinkContext;
		DWORD m_aThinkFunctions;
		DWORD m_bDisabledContextThinks;
		DWORD m_flAnimTime;
		DWORD m_flSimulationTime;
		DWORD m_nSceneObjectOverrideFlags;
		DWORD m_bHasSuccessfullyInterpolated;
		DWORD m_bHasAddedVarsToInterpolation;
		DWORD m_bRenderEvenWhenNotSuccessfullyInterpolated;
		DWORD m_nInterpolationLatchDirtyFlags;
		DWORD m_ListEntry;
		DWORD m_flCreateTime;
		DWORD m_flSpeed;
		DWORD m_EntClientFlags;
		DWORD m_bClientSideRagdoll;
		DWORD m_iTeamNum;
		DWORD m_spawnflags;
		DWORD m_nNextThinkTick;
		DWORD m_fFlags;
		DWORD m_vecAbsVelocity;
		DWORD m_vecVelocity;
		DWORD m_vecBaseVelocity;
		DWORD m_hEffectEntity;
		DWORD m_hOwnerEntity;
		DWORD m_MoveCollide;
		DWORD m_MoveType;
		DWORD m_nActualMoveType;
		DWORD m_flWaterLevel;
		DWORD m_fEffects;
		DWORD m_hGroundEntity;
		DWORD m_nGroundBodyIndex;
		DWORD m_flFriction;
		DWORD m_flElasticity;
		DWORD m_flGravityScale;
		DWORD m_flTimeScale;
		DWORD m_bAnimatedEveryTick;
		DWORD m_flNavIgnoreUntilTime;
		DWORD m_hThink;
		DWORD m_fBBoxVisFlags;
		DWORD m_bPredictable;
		DWORD m_bRenderWithViewModels;
		DWORD m_nSplitUserPlayerPredictionSlot;
		DWORD m_nFirstPredictableCommand;
		DWORD m_nLastPredictableCommand;
		DWORD m_hOldMoveParent;
		DWORD m_Particles;
		DWORD m_vecPredictedScriptFloats;
		DWORD m_vecPredictedScriptFloatIDs;
		DWORD m_nNextScriptVarRecordID;
		DWORD m_vecAngVelocity;
		DWORD m_DataChangeEventRef;
		DWORD m_dependencies;
		DWORD m_nCreationTick;
		DWORD m_bAnimTimeChanged;
		DWORD m_bSimulationTimeChanged;
		DWORD m_sUniqueHammerID;
		DWORD m_nBloodType;
	} C_BaseEntity;

	inline struct CEntityIdentityOffsets {
		DWORD m_nameStringableIndex;
		DWORD m_name;
		DWORD m_designerName;
		DWORD m_flags;
		DWORD m_worldGroupId;
		DWORD m_fDataObjectTypes;
		DWORD m_PathIndex;
		DWORD m_pPrev;
		DWORD m_pNext;
		DWORD m_pPrevByClass;
		DWORD m_pNextByClass;
	} CEntityIdentity;

	inline struct C_StattrakModuleOffsets {
		DWORD m_bKnife;
	} C_StattrakModule;

	inline struct C_PhysicsPropOffsets {
		DWORD m_bAwake;
	} C_PhysicsProp;

	inline struct C_BreakablePropOffsets {
		DWORD m_CPropDataComponent;
		DWORD m_OnBreak;
		DWORD m_OnHealthChanged;
		DWORD m_OnTakeDamage;
		DWORD m_impactEnergyScale;
		DWORD m_iMinHealthDmg;
		DWORD m_flPressureDelay;
		DWORD m_flDefBurstScale;
		DWORD m_vDefBurstOffset;
		DWORD m_hBreaker;
		DWORD m_PerformanceMode;
		DWORD m_flPreventDamageBeforeTime;
		DWORD m_BreakableContentsType;
		DWORD m_strBreakableContentsPropGroupOverride;
		DWORD m_strBreakableContentsParticleOverride;
		DWORD m_bHasBreakPiecesOrCommands;
		DWORD m_explodeDamage;
		DWORD m_explodeRadius;
		DWORD m_explosionDelay;
		DWORD m_explosionBuildupSound;
		DWORD m_explosionCustomEffect;
		DWORD m_explosionCustomSound;
		DWORD m_explosionModifier;
		DWORD m_hPhysicsAttacker;
		DWORD m_flLastPhysicsInfluenceTime;
		DWORD m_flDefaultFadeScale;
		DWORD m_hLastAttacker;
		DWORD m_hFlareEnt;
		DWORD m_noGhostCollision;
	} C_BreakableProp;

	inline struct C_BeamOffsets {
		DWORD m_flFrameRate;
		DWORD m_flHDRColorScale;
		DWORD m_flFireTime;
		DWORD m_flDamage;
		DWORD m_nNumBeamEnts;
		DWORD m_queryHandleHalo;
		DWORD m_hBaseMaterial;
		DWORD m_nHaloIndex;
		DWORD m_nBeamType;
		DWORD m_nBeamFlags;
		DWORD m_hAttachEntity;
		DWORD m_nAttachIndex;
		DWORD m_fWidth;
		DWORD m_fEndWidth;
		DWORD m_fFadeLength;
		DWORD m_fHaloScale;
		DWORD m_fAmplitude;
		DWORD m_fStartFrame;
		DWORD m_fSpeed;
		DWORD m_flFrame;
		DWORD m_nClipStyle;
		DWORD m_bTurnedOff;
		DWORD m_vecEndPos;
		DWORD m_hEndEntity;
	} C_Beam;

	inline struct C_CSGO_TeamPreviewCharacterPositionOffsets {
		DWORD m_nVariant;
		DWORD m_nRandom;
		DWORD m_nOrdinal;
		DWORD m_sWeaponName;
		DWORD m_xuid;
		DWORD m_agentItem;
		DWORD m_glovesItem;
		DWORD m_weaponItem;
	} C_CSGO_TeamPreviewCharacterPosition;

	inline struct C_EnvScreenOverlayOffsets {
		DWORD m_iszOverlayNames;
		DWORD m_flOverlayTimes;
		DWORD m_flStartTime;
		DWORD m_iDesiredOverlay;
		DWORD m_bIsActive;
		DWORD m_bWasActive;
		DWORD m_iCachedDesiredOverlay;
		DWORD m_iCurrentOverlay;
		DWORD m_flCurrentOverlayTime;
	} C_EnvScreenOverlay;

	inline struct CCSWeaponBaseVDataOffsets {
		DWORD m_WeaponType;
		DWORD m_WeaponCategory;
		DWORD m_szViewModel;
		DWORD m_szPlayerModel;
		DWORD m_szWorldDroppedModel;
		DWORD m_szAimsightLensMaskModel;
		DWORD m_szMagazineModel;
		DWORD m_szHeatEffect;
		DWORD m_szEjectBrassEffect;
		DWORD m_szMuzzleFlashParticleAlt;
		DWORD m_szMuzzleFlashThirdPersonParticle;
		DWORD m_szMuzzleFlashThirdPersonParticleAlt;
		DWORD m_szTracerParticle;
		DWORD m_GearSlot;
		DWORD m_GearSlotPosition;
		DWORD m_DefaultLoadoutSlot;
		DWORD m_sWrongTeamMsg;
		DWORD m_nPrice;
		DWORD m_nKillAward;
		DWORD m_nPrimaryReserveAmmoMax;
		DWORD m_nSecondaryReserveAmmoMax;
		DWORD m_bMeleeWeapon;
		DWORD m_bHasBurstMode;
		DWORD m_bIsRevolver;
		DWORD m_bCannotShootUnderwater;
		DWORD m_szName;
		DWORD m_szAnimExtension;
		DWORD m_eSilencerType;
		DWORD m_nCrosshairMinDistance;
		DWORD m_nCrosshairDeltaDistance;
		DWORD m_bIsFullAuto;
		DWORD m_nNumBullets;
		DWORD m_flCycleTime;
		DWORD m_flMaxSpeed;
		DWORD m_flSpread;
		DWORD m_flInaccuracyCrouch;
		DWORD m_flInaccuracyStand;
		DWORD m_flInaccuracyJump;
		DWORD m_flInaccuracyLand;
		DWORD m_flInaccuracyLadder;
		DWORD m_flInaccuracyFire;
		DWORD m_flInaccuracyMove;
		DWORD m_flRecoilAngle;
		DWORD m_flRecoilAngleVariance;
		DWORD m_flRecoilMagnitude;
		DWORD m_flRecoilMagnitudeVariance;
		DWORD m_nTracerFrequency;
		DWORD m_flInaccuracyJumpInitial;
		DWORD m_flInaccuracyJumpApex;
		DWORD m_flInaccuracyReload;
		DWORD m_nRecoilSeed;
		DWORD m_nSpreadSeed;
		DWORD m_flTimeToIdleAfterFire;
		DWORD m_flIdleInterval;
		DWORD m_flAttackMovespeedFactor;
		DWORD m_flHeatPerShot;
		DWORD m_flInaccuracyPitchShift;
		DWORD m_flInaccuracyAltSoundThreshold;
		DWORD m_flBotAudibleRange;
		DWORD m_szUseRadioSubtitle;
		DWORD m_bUnzoomsAfterShot;
		DWORD m_bHideViewModelWhenZoomed;
		DWORD m_nZoomLevels;
		DWORD m_nZoomFOV1;
		DWORD m_nZoomFOV2;
		DWORD m_flZoomTime0;
		DWORD m_flZoomTime1;
		DWORD m_flZoomTime2;
		DWORD m_flIronSightPullUpSpeed;
		DWORD m_flIronSightPutDownSpeed;
		DWORD m_flIronSightFOV;
		DWORD m_flIronSightPivotForward;
		DWORD m_flIronSightLooseness;
		DWORD m_angPivotAngle;
		DWORD m_vecIronSightEyePos;
		DWORD m_nDamage;
		DWORD m_flHeadshotMultiplier;
		DWORD m_flArmorRatio;
		DWORD m_flPenetration;
		DWORD m_flRange;
		DWORD m_flRangeModifier;
		DWORD m_flFlinchVelocityModifierLarge;
		DWORD m_flFlinchVelocityModifierSmall;
		DWORD m_flRecoveryTimeCrouch;
		DWORD m_flRecoveryTimeStand;
		DWORD m_flRecoveryTimeCrouchFinal;
		DWORD m_flRecoveryTimeStandFinal;
		DWORD m_nRecoveryTransitionStartBullet;
		DWORD m_nRecoveryTransitionEndBullet;
		DWORD m_flThrowVelocity;
		DWORD m_vSmokeColor;
		DWORD m_szAnimClass;
	} CCSWeaponBaseVData;

	inline struct C_PointWorldTextOffsets {
		DWORD m_bForceRecreateNextUpdate;
		DWORD m_messageText;
		DWORD m_FontName;
		DWORD m_bEnabled;
		DWORD m_bFullbright;
		DWORD m_flWorldUnitsPerPx;
		DWORD m_flFontSize;
		DWORD m_flDepthOffset;
		DWORD m_Color;
		DWORD m_nJustifyHorizontal;
		DWORD m_nJustifyVertical;
		DWORD m_nReorientMode;
	} C_PointWorldText;

	inline struct CCSPlayerControllerOffsets {
		DWORD m_pInGameMoneyServices;
		DWORD m_pInventoryServices;
		DWORD m_pActionTrackingServices;
		DWORD m_pDamageServices;
		DWORD m_iPing;
		DWORD m_bHasCommunicationAbuseMute;
		DWORD m_szCrosshairCodes;
		DWORD m_iPendingTeamNum;
		DWORD m_flForceTeamTime;
		DWORD m_iCompTeammateColor;
		DWORD m_bEverPlayedOnTeam;
		DWORD m_flPreviousForceJoinTeamTime;
		DWORD m_szClan;
		DWORD m_sSanitizedPlayerName;
		DWORD m_iCoachingTeam;
		DWORD m_nPlayerDominated;
		DWORD m_nPlayerDominatingMe;
		DWORD m_iCompetitiveRanking;
		DWORD m_iCompetitiveWins;
		DWORD m_iCompetitiveRankType;
		DWORD m_iCompetitiveRankingPredicted_Win;
		DWORD m_iCompetitiveRankingPredicted_Loss;
		DWORD m_iCompetitiveRankingPredicted_Tie;
		DWORD m_nEndMatchNextMapVote;
		DWORD m_unActiveQuestId;
		DWORD m_nQuestProgressReason;
		DWORD m_unPlayerTvControlFlags;
		DWORD m_iDraftIndex;
		DWORD m_msQueuedModeDisconnectionTimestamp;
		DWORD m_uiAbandonRecordedReason;
		DWORD m_bCannotBeKicked;
		DWORD m_bEverFullyConnected;
		DWORD m_bAbandonAllowsSurrender;
		DWORD m_bAbandonOffersInstantSurrender;
		DWORD m_bDisconnection1MinWarningPrinted;
		DWORD m_bScoreReported;
		DWORD m_nDisconnectionTick;
		DWORD m_bControllingBot;
		DWORD m_bHasControlledBotThisRound;
		DWORD m_bHasBeenControlledByPlayerThisRound;
		DWORD m_nBotsControlledThisRound;
		DWORD m_bCanControlObservedBot;
		DWORD m_hPlayerPawn;
		DWORD m_hObserverPawn;
		DWORD m_bPawnIsAlive;
		DWORD m_iPawnHealth;
		DWORD m_iPawnArmor;
		DWORD m_bPawnHasDefuser;
		DWORD m_bPawnHasHelmet;
		DWORD m_nPawnCharacterDefIndex;
		DWORD m_iPawnLifetimeStart;
		DWORD m_iPawnLifetimeEnd;
		DWORD m_iPawnBotDifficulty;
		DWORD m_hOriginalControllerOfCurrentPawn;
		DWORD m_iScore;
		DWORD m_recentKillQueue;
		DWORD m_nFirstKill;
		DWORD m_nKillCount;
		DWORD m_bMvpNoMusic;
		DWORD m_eMvpReason;
		DWORD m_iMusicKitID;
		DWORD m_iMusicKitMVPs;
		DWORD m_iMVPs;
		DWORD m_bIsPlayerNameDirty;
	} CCSPlayerController;

	inline struct C_BasePropDoorOffsets {
		DWORD m_eDoorState;
		DWORD m_modelChanged;
		DWORD m_bLocked;
		DWORD m_closedPosition;
		DWORD m_closedAngles;
		DWORD m_hMaster;
		DWORD m_vWhereToSetLightingOrigin;
	} C_BasePropDoor;

	inline struct C_NametagModuleOffsets {
		DWORD m_strNametagString;
	} C_NametagModule;

	inline struct C_PhysPropClientsideOffsets {
		DWORD m_flTouchDelta;
		DWORD m_fDeathTime;
		DWORD m_inertiaScale;
		DWORD m_vecDamagePosition;
		DWORD m_vecDamageDirection;
		DWORD m_nDamageType;
	} C_PhysPropClientside;

	inline struct C_SoundAreaEntityBaseOffsets {
		DWORD m_bDisabled;
		DWORD m_bWasEnabled;
		DWORD m_iszSoundAreaType;
		DWORD m_vPos;
	} C_SoundAreaEntityBase;

	inline struct C_FogControllerOffsets {
		DWORD m_fog;
		DWORD m_bUseAngles;
		DWORD m_iChangedVariables;
	} C_FogController;

	inline struct CInfoWorldLayerOffsets {
		DWORD m_pOutputOnEntitiesSpawned;
		DWORD m_worldName;
		DWORD m_layerName;
		DWORD m_bWorldLayerVisible;
		DWORD m_bEntitiesSpawned;
		DWORD m_bCreateAsChildSpawnGroup;
		DWORD m_hLayerSpawnGroup;
		DWORD m_bWorldLayerActuallyVisible;
	} CInfoWorldLayer;

	inline struct C_PhysMagnetOffsets {
		DWORD m_aAttachedObjectsFromServer;
		DWORD m_aAttachedObjects;
	} C_PhysMagnet;

	inline struct C_FuncConveyorOffsets {
		DWORD m_vecMoveDirEntitySpace;
		DWORD m_flTargetSpeed;
		DWORD m_nTransitionStartTick;
		DWORD m_nTransitionDurationTicks;
		DWORD m_flTransitionStartSpeed;
		DWORD m_hConveyorModels;
		DWORD m_flCurrentConveyorOffset;
		DWORD m_flCurrentConveyorSpeed;
	} C_FuncConveyor;

	inline struct CEntityInstanceOffsets {
		DWORD m_iszPrivateVScripts;
		DWORD m_pEntity;
		DWORD m_CScriptComponent;
		DWORD m_bVisibleinPVS;
	} CEntityInstance;

	inline struct ServerAuthoritativeWeaponSlot_tOffsets {
		DWORD unClass;
		DWORD unSlot;
		DWORD unItemDefIdx;
	} ServerAuthoritativeWeaponSlot_t;

	inline struct C_BaseViewModelOffsets {
		DWORD m_vecLastFacing;
		DWORD m_nViewModelIndex;
		DWORD m_nAnimationParity;
		DWORD m_flAnimationStartTime;
		DWORD m_hWeapon;
		DWORD m_sVMName;
		DWORD m_sAnimationPrefix;
		DWORD m_iCameraAttachment;
		DWORD m_vecLastCameraAngles;
		DWORD m_previousElapsedDuration;
		DWORD m_previousCycle;
		DWORD m_nOldAnimationParity;
		DWORD m_hOldLayerSequence;
		DWORD m_oldLayer;
		DWORD m_oldLayerStartTime;
		DWORD m_hControlPanel;
	} C_BaseViewModel;

	inline struct CGameSceneNodeOffsets {
		DWORD m_nodeToWorld;
		DWORD m_pOwner;
		DWORD m_pParent;
		DWORD m_pChild;
		DWORD m_pNextSibling;
		DWORD m_hParent;
		DWORD m_vecOrigin;
		DWORD m_angRotation;
		DWORD m_flScale;
		DWORD m_vecAbsOrigin;
		DWORD m_angAbsRotation;
		DWORD m_flAbsScale;
		DWORD m_nParentAttachmentOrBone;
		DWORD m_bDebugAbsOriginChanges;
		DWORD m_bDormant;
		DWORD m_bForceParentToBeNetworked;
		DWORD m_bDirtyHierarchy;
		DWORD m_bDirtyBoneMergeInfo;
		DWORD m_bNetworkedPositionChanged;
		DWORD m_bNetworkedAnglesChanged;
		DWORD m_bNetworkedScaleChanged;
		DWORD m_bWillBeCallingPostDataUpdate;
		DWORD m_bBoneMergeFlex;
		DWORD m_nLatchAbsOrigin;
		DWORD m_bDirtyBoneMergeBoneToRoot;
		DWORD m_nHierarchicalDepth;
		DWORD m_nHierarchyType;
		DWORD m_nDoNotSetAnimTimeInInvalidatePhysicsCount;
		DWORD m_name;
		DWORD m_hierarchyAttachName;
		DWORD m_flZOffset;
		DWORD m_flClientLocalScale;
		DWORD m_vRenderOrigin;
	} CGameSceneNode;

	inline struct CCSPointScriptOffsets {
		DWORD m_pParent;
	} CCSPointScript;

	inline struct C_CSObserverPawnOffsets {
		DWORD m_hDetectParentChange;
	} C_CSObserverPawn;

	inline struct C_EntityFlameOffsets {
		DWORD m_hEntAttached;
		DWORD m_hOldAttached;
		DWORD m_bCheapEffect;
	} C_EntityFlame;

	inline struct CCSObserver_ObserverServicesOffsets {
		DWORD m_hLastObserverTarget;
		DWORD m_vecObserverInterpolateOffset;
		DWORD m_vecObserverInterpStartPos;
		DWORD m_flObsInterp_PathLength;
		DWORD m_qObsInterp_OrientationStart;
		DWORD m_qObsInterp_OrientationTravelDir;
		DWORD m_obsInterpState;
		DWORD m_bObserverInterpolationNeedsDeferredSetup;
	} CCSObserver_ObserverServices;

	inline struct C_HostageOffsets {
		DWORD m_entitySpottedState;
		DWORD m_leader;
		DWORD m_reuseTimer;
		DWORD m_vel;
		DWORD m_isRescued;
		DWORD m_jumpedThisFrame;
		DWORD m_nHostageState;
		DWORD m_bHandsHaveBeenCut;
		DWORD m_hHostageGrabber;
		DWORD m_fLastGrabTime;
		DWORD m_vecGrabbedPos;
		DWORD m_flRescueStartTime;
		DWORD m_flGrabSuccessTime;
		DWORD m_flDropStartTime;
		DWORD m_flDeadOrRescuedTime;
		DWORD m_blinkTimer;
		DWORD m_lookAt;
		DWORD m_lookAroundTimer;
		DWORD m_isInit;
		DWORD m_eyeAttachment;
		DWORD m_chestAttachment;
		DWORD m_pPredictionOwner;
		DWORD m_fNewestAlphaThinkTime;
	} C_Hostage;

	inline struct C_SpriteOffsets {
		DWORD m_hSpriteMaterial;
		DWORD m_hAttachedToEntity;
		DWORD m_nAttachment;
		DWORD m_flSpriteFramerate;
		DWORD m_flFrame;
		DWORD m_flDieTime;
		DWORD m_nBrightness;
		DWORD m_flBrightnessDuration;
		DWORD m_flSpriteScale;
		DWORD m_flScaleDuration;
		DWORD m_bWorldSpaceScale;
		DWORD m_flGlowProxySize;
		DWORD m_flHDRColorScale;
		DWORD m_flLastTime;
		DWORD m_flMaxFrame;
		DWORD m_flStartScale;
		DWORD m_flDestScale;
		DWORD m_flScaleTimeStart;
		DWORD m_nStartBrightness;
		DWORD m_nDestBrightness;
		DWORD m_flBrightnessTimeStart;
		DWORD m_hOldSpriteMaterial;
		DWORD m_nSpriteWidth;
		DWORD m_nSpriteHeight;
	} C_Sprite;

	inline struct C_PlantedC4Offsets {
		DWORD m_bBombTicking;
		DWORD m_nBombSite;
		DWORD m_nSourceSoundscapeHash;
		DWORD m_entitySpottedState;
		DWORD m_flNextGlow;
		DWORD m_flNextBeep;
		DWORD m_flC4Blow;
		DWORD m_bCannotBeDefused;
		DWORD m_bHasExploded;
		DWORD m_flTimerLength;
		DWORD m_bBeingDefused;
		DWORD m_bTriggerWarning;
		DWORD m_bExplodeWarning;
		DWORD m_bC4Activated;
		DWORD m_bTenSecWarning;
		DWORD m_flDefuseLength;
		DWORD m_flDefuseCountDown;
		DWORD m_bBombDefused;
		DWORD m_hBombDefuser;
		DWORD m_hControlPanel;
		DWORD m_AttributeManager;
		DWORD m_hDefuserMultimeter;
		DWORD m_flNextRadarFlashTime;
		DWORD m_bRadarFlash;
		DWORD m_pBombDefuser;
		DWORD m_fLastDefuseTime;
		DWORD m_pPredictionOwner;
		DWORD m_vecC4ExplodeSpectatePos;
		DWORD m_vecC4ExplodeSpectateAng;
		DWORD m_flC4ExplodeSpectateDuration;
	} C_PlantedC4;

	inline struct C_RagdollPropOffsets {
		DWORD m_ragPos;
		DWORD m_ragAngles;
		DWORD m_flBlendWeight;
		DWORD m_hRagdollSource;
		DWORD m_iEyeAttachment;
		DWORD m_flBlendWeightCurrent;
		DWORD m_parentPhysicsBoneIndices;
		DWORD m_worldSpaceBoneComputationOrder;
	} C_RagdollProp;

	inline struct C_VoteControllerOffsets {
		DWORD m_iActiveIssueIndex;
		DWORD m_iOnlyTeamToVote;
		DWORD m_nVoteOptionCount;
		DWORD m_nPotentialVotes;
		DWORD m_bVotesDirty;
		DWORD m_bTypeDirty;
		DWORD m_bIsYesNoVote;
	} C_VoteController;

	inline struct ViewAngleServerChange_tOffsets {
		DWORD nType;
		DWORD qAngle;
		DWORD nIndex;
	} ViewAngleServerChange_t;

	inline struct C_ChickenOffsets {
		DWORD m_hHolidayHatAddon;
		DWORD m_jumpedThisFrame;
		DWORD m_leader;
		DWORD m_AttributeManager;
		DWORD m_bAttributesInitialized;
		DWORD m_hWaterWakeParticles;
		DWORD m_bIsPreviewModel;
	} C_Chicken;

	inline struct PhysicsRagdollPose_tOffsets {
		DWORD m_Transforms;
		DWORD m_hOwner;
	} PhysicsRagdollPose_t;

	inline struct client_dllOffsets {
		DWORD dwCSGOInput;
		DWORD dwEntityList;
		DWORD dwGameEntitySystem;
		DWORD dwGameEntitySystem_highestEntityIndex;
		DWORD dwGameRules;
		DWORD dwGlobalVars;
		DWORD dwGlowManager;
		DWORD dwLocalPlayerController;
		DWORD dwLocalPlayerPawn;
		DWORD dwPlantedC4;
		DWORD dwPrediction;
		DWORD dwSensitivity;
		DWORD dwSensitivity_sensitivity;
		DWORD dwViewAngles;
		DWORD dwViewMatrix;
		DWORD dwViewRender;
		DWORD dwWeaponC4;
	} client_dll;

	inline struct engine2_dllOffsets {
		DWORD dwBuildNumber;
		DWORD dwNetworkGameClient;
		DWORD dwNetworkGameClient_clientTickCount;
		DWORD dwNetworkGameClient_deltaTick;
		DWORD dwNetworkGameClient_isBackgroundMap;
		DWORD dwNetworkGameClient_localPlayer;
		DWORD dwNetworkGameClient_maxClients;
		DWORD dwNetworkGameClient_serverTickCount;
		DWORD dwNetworkGameClient_signOnState;
		DWORD dwWindowHeight;
		DWORD dwWindowWidth;
	} engine2_dll;

	inline struct inputsystem_dllOffsets {
		DWORD dwInputSystem;
	} inputsystem_dll;

	inline struct matchmaking_dllOffsets {
		DWORD dwGameTypes;
		DWORD dwGameTypes_mapName;
	} matchmaking_dll;

	inline struct soundsystem_dllOffsets {
		DWORD dwSoundSystem;
		DWORD dwSoundSystem_engineViewData;
	} soundsystem_dll;

	inline struct TrashOffsets {
		DWORD AnimGraph;
		DWORD Aspect_Ratio;
		DWORD Fov_Changer;
		DWORD Fov_Offset;
		DWORD LightSceneObject;
		DWORD ScenSystem;
		DWORD hkDrawSceneObject;
	} Trash;

	bool UpdateOffsets();
}