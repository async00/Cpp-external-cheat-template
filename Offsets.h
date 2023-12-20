#pragma once

class Offsets // by Lufzys
{
public:
    int dwLocalPlayer = 0xDA5A84; // GameAssembly.dll
    int dwCharacter = 0xDAF3E8; // GameAssembly.dll
    int dwCharacterState[4] = { 0x5C, 0x20, 0x34, 0x28 }; // CREW = 0, IMP = 1; GHOST = 257 | dwCharacter
    int dwEnvironment = 0x12A86E0; // UnityPlayer.dll
    int dwWallCheack[3] = { 0x80, 0x5C, 0x0 }; // ON = 1, OFF = 2 | dwEnvironment 
    int dwOriginX[3] = { 0x80, 0x5C, 0x2C }; // dwEnvironment 
    int dwOriginY[3] = { 0x80, 0x5C, 0x30 }; // dwEnvironment 

    // Player
    int dwPlayerId[5] = { 0x5C, 0x0, 0x34, 0x8, 0x0 }; // dwLocalPlayer
    int flSpeed[3] = { 0x5C, 0x4, 0x14 }; // dwLocalPlayer
    int dwColorId[4] = { 0x5C, 0x0, 0x34, 0x10 }; // dwLocalPlayer
    int btIsDead[4] = { 0x5C, 0x0, 0x34, 0x29 }; // dwLocalPlayer
    int btIsImpostor[4] = { 0x5C, 0x0, 0x34, 0x8 }; // dwLocalPlayer / buggly
    int strPlayerName[5] = { 0x5C, 0x0, 0x34, 0xC, 0xC }; // dwLocalPlayer | Unicode
    int flLightRadius[4] = { 0x5C, 0x0, 0x54, 0x1C }; // dwLocalPlayer

    // Server Info
    int dwServerManager = 0x00DA5A84; // GameAssembly.dll
    int dwMaxPlayer[3] = { 0x5C, 0x4, 0x8 }; // dwServerManager 
    int btMapId[3] = { 0x5C, 0x4, 0x10 }; // dwServerManager

    // Time
    int dwDiscussionTime[3] = { 0x5C, 0x4, 0x44 }; // dwLocalPlayer 
    int dwVotingTime[3] = { 0x5C, 0x4, 0x48 }; // dwLocalPlayer 

    // Crew
    int dwEmergencyCount[3] = { 0x5C, 0x4, 0x30 }; // dwLocalPlayer 
    int dwRemainingEmergencyCount[3] = { 0x5C, 0x0, 0x48 }; // dwLocalPlayer 
    int flCrewLightDistance[3] = { 0x5C, 0x4, 0x18 }; // dwLocalPlayer 
    int dwMaxReportDistance[3] = { 0x5C, 0x0, 0x2C }; // dwLocalPlayer 

    // Impostor
    int dwImposterCount[3] = { 0x5C, 0x4, 0x38 }; // dwLocalPlayer 
    int flImpostorLightDistance[3] = { 0x5C, 0x4, 0x1C }; // dwLocalPlayer 
    int dwKillCooldown[3] = { 0x5C, 0x4, 0x20 }; // dwLocalPlayer 
    int dwKillDistance[3] = { 0x5C, 0x0, 0x40 }; // dwLocalPlayer | Short = 1, Normal = 2, Far = 3
    int dwKillTimer[3] = { 0x5C, 0x0, 0x44 }; // dwLocalPlayer 
};
