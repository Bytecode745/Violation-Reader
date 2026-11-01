#pragma once

typedef unsigned long long uintptr_t;

namespace Offsets {
	// Hyperion
	constexpr uintptr_t ViolationTable = 0x10E0586;
	constexpr int ViolationsIndex = 0x10;
	constexpr int EncodedViolations = 0x19;

	constexpr int XorTableIndex = 0x0; // not always present
	
	// Instance
	constexpr uintptr_t DatamodelArbiter = 0x8d06600;
	constexpr int ArbiterToDatamodel = 0x1F0;
	constexpr int Children = 0x70;
	constexpr int ScriptContext = 0x440;

	// Structs
	constexpr int LGlobal = 0x38; // L->global
	constexpr int RegistryFree = 0x628; // global->registryfree

	// Luau
	constexpr int GlobalStates = 0x188;
	constexpr int ActorState = 0x310;
	constexpr int GlobalState = 0x98;
	constexpr int EncryptedState = 0x0;
}