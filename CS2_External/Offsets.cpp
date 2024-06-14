#include "Offsets.h"

DWORD64 SearchOffsets(std::string Signature, DWORD64 ModuleAddress)
{
	std::vector<DWORD64> TempAddressList;
	DWORD64 Address = 0;
	DWORD Offsets = 0;

	TempAddressList = ProcessMgr.SearchMemory(Signature, ModuleAddress, ModuleAddress + 0x4000000);

	if (TempAddressList.size() <= 0)
		return 0;

	if (!ProcessMgr.ReadMemory<DWORD>(TempAddressList.at(0) + 3, Offsets))
		return 0;

	Address = TempAddressList.at(0) + Offsets + 7;
	return Address;
}

bool Offset::UpdateOffsets()
{
	Offset::EntityList = cs2_dumper::offsets::client_dll::dwEntityList;
	Offset::LocalPlayerController = cs2_dumper::offsets::client_dll::dwLocalPlayerController;
	Offset::Matrix = cs2_dumper::offsets::client_dll::dwViewMatrix;
	Offset::GlobalVars = cs2_dumper::offsets::client_dll::dwGlobalVars;
	Offset::ViewAngle = cs2_dumper::offsets::client_dll::dwViewAngles;
	Offset::LocalPlayerPawn = cs2_dumper::offsets::client_dll::dwLocalPlayerPawn;
	return true;
}