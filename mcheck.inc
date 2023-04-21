/*
    * The MIT License (MIT)
    *
    * Copyright (c) 2023 21th year
    *
    * Permission is hereby granted, free of charge, to any person obtaining a copy
    * of this software and associated documentation files (the "Software"), to deal
    * in the Software without restriction, including without limitation the rights
    * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    * copies of the Software, and to permit persons to whom the Software is
    * furnished to do so, subject to the following conditions:
    *
    * The above copyright notice and this permission notice shall be included in all
    * copies or substantial portions of the Software.
    *
    * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    * SOFTWARE.
*/

#if defined m_check
    #endinput
#endif
#define m_check

#tryinclude <a_samp>

#if !defined gpci
    native gpci(playerid, buffer[], size = sizeof(buffer));
#endif

#if !defined GetPlayerClientID
    native GetPlayerClientID(playerid, buffer[], size = sizeof(buffer)) = gpci;
#endif 

#define DEVICE_TYPE_MOBILE      1
#define DEVICE_TYPE_CLIENT      2
#define STRUCTURE_CLIENT_NAME   2
#define STRUCTURE_CLIENT_HASH   1

// HASH_LEN = 44;

enum E_CLIENT_STRUCTURE {
    e_szClientID,
    e_szAuthKey[44],
    e_szClientName[21 + 1],
    e_szDevice[6 + 1]
};
new client_info[MAX_PLAYERS char][E_CLIENT_STRUCTURE];

static const m_structure_authkeys[][E_CLIENT_STRUCTURE] = {
    {1, "5638413348335738345A4536524D4A524539334B", "Hasn't name"},
    {2,  "ED40ED0E8089CC44C08EE9580F4C8C44EE8EE990", "Jekmant"},
    {3,  "FF2BE5E6F5D9392F57C4E66F7AD78767277C6E4F6B", "Hasn't name"},
    {4,  "E02262CF28BC542486C558D4BE9EFB716592AFAF8B", "Codessar/FLIN BY SGMP"},
    {5,  "10B3D2B1317ADD02CC1F680BC500A8BC0FD7AD42CE7", "grishin"},
    {6,  "15121F6F18550C00AC4B4F8A167D0379BB0ACA99043", "Monser/Tushoonka"}
};

public OnGameModeInit(Args)
{
    printf("Mobile checker:\nХешей клиентов загружено: \t%d\n", sizeof(m_structure_authkeys));
    #if defined MC_OnGameModeInit
        return MC_OnGameModeInit();
    #else
        return 1;
    #endif
}
#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif

#define OnGameModeInit MC_OnGameModeInit
#if defined MC_OnGameModeInit
    forward MC_OnGameModeInit();
#endif

stock IsAMobile(playerid) {
    static
        clientID[44];
    GetPlayerClientID(playerid, clientID, sizeof(clientID));

    for(new i; i < sizeof( m_structure_authkeys ); i++) {

        if( strfind(clientID, m_structure_authkeys[i][STRUCTURE_CLIENT_HASH], false, 0) != -1)
            return true;
        
    }
    return false;
}


stock SetDeviceType(playerid, type[]) {
    switch(type): {

        case DEVICE_TYPE_MOBILE: 
            client_info[playerid][e_szDevice] = "Mobile";
        case DEVICE_TYPE_CLIENT:
            client_info[playerid][e_szDevice] = "Client";
    }
}

stock GetPlayerClient(playerid) {
    static
        clientID[44];
    GetPlayerClientID(playerid, clientID, sizeof(clientID));

    for(new i; i < sizeof( m_structure_authkeys ); i++) {

        if(strfind(clientID, m_structure_authkeys[i][STRUCTURE_CLIENT_HASH], false, 0) != -1) 
            client_info[playerid][e_szClientName] = m_structure_authkeys[i][STRUCTURE_CLIENT_NAME];
    }
    
    return client_info[playerid][e_szClientName];
}
