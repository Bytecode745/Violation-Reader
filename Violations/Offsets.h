#pragma once

typedef unsigned long long uintptr_t;

namespace Offsets {
	// Hyperion
	constexpr uintptr_t ViolationTable = 0x10FC120;
	constexpr int ViolationsIndex = 0xA;
	constexpr int EncodedViolations = 0xC;

	constexpr int XorTableIndex = 0x35; // not always present
	
	// Instance
	constexpr uintptr_t DatamodelArbiter = 0x8eb6960;
	constexpr int ArbiterToDatamodel = 0x1F0;
	constexpr int Children = 0x70;
	constexpr int ScriptContext = 0x440;

	// Structs
	constexpr int LGlobal = 0x50; // L->global
	constexpr int RegistryFree = 0x640; // global->registryfree

	// Luau
	constexpr int GlobalStates = 0x188;
	constexpr int ActorState = 0x310;
	constexpr int GlobalState = 0x50;
	constexpr int EncryptedState = 0x38;
}