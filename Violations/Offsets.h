#pragma once

typedef unsigned long long uintptr_t;

namespace Offsets {
	// Hyperion
	constexpr uintptr_t ViolationTable = 0x14C74;
	constexpr int ViolationsIndex = 0xE;
	constexpr int EncodedViolations = 0x16;

	constexpr int XorTableIndex = 0x31; // not always present
	
	// Instance
	constexpr uintptr_t DatamodelArbiter = 0x8e16368;
	constexpr int ArbiterToDatamodel = 0x1F0;
	constexpr int Children = 0x70;
	constexpr int ScriptContext = 0x440;

	// Structs
	constexpr int LGlobal = 0x68; // L->global
	constexpr int RegistryFree = 0x628; // global->registryfree

	// Luau
	constexpr int GlobalStates = 0x188;
	constexpr int ActorState = 0x2F0;
	constexpr int GlobalState = 0x8;
	constexpr int EncryptedState = 0x288;
}