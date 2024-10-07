#pragma once

#include "Entity.h"

namespace AntiFlashbang
{
	inline void Run(const CEntity &aLocalPlayer) noexcept
	{
		float duration{};
		ProcessMgr.WriteMemory(aLocalPlayer.Pawn.Address + Offset::C_CSPlayerPawnBase.m_flFlashDuration, duration);
	}
} // namespace AntiFlashbang
