/* Functions from 0x800056A0 to 0x80006258, found by decomp-toolkit. */
#include "common.h"

void fn_800056A0(s8 arg0) {
    extern void *lbl_80367100;
    M2C_FIELD(lbl_80367100, s8 *, 0x18) = arg0;
}

void fn_800056AC(void) {
    extern void *lbl_80367100;
    s16 *p = (s16 *)lbl_80367100;

    p[0x10/2] = (s16)(p[0xE/2] - 0x10);
    *(u8*)&p[0x18/2] = (u8)0;
}

s32 DebugPrint(const char *fmt, ...) {
    return 0;
}

#pragma optimization_level 3
void fn_80005720(u32 arg0, s8 arg1)
{
    extern void *lbl_80367100;
    u16 flags;
    s32 pos;
    s32 lim;
    s32 i;
    s32 t;
    s32 z;
    u32 tmp;

    flags = arg0;
    if (arg0 & 0x10) {
        tmp = __cntlzw(((u8 *)lbl_80367100)[0x18]);
        ((u8 *)lbl_80367100)[0x18] = tmp >> 5;
    }
    if (((u8 *)lbl_80367100)[0x16] != 0) {
        *(s16 *)((u8 *)lbl_80367100 + 0x10) -= (s8)arg1 / 8;
        if (*(s16 *)((u8 *)lbl_80367100 + 0x10) < 0x10) {
            *(s16 *)((u8 *)lbl_80367100 + 0x10) = 0x10;
        }
        t = *(s16 *)((u8 *)lbl_80367100 + 0xE);
        t = t - 0x10;
        if (*(s16 *)((u8 *)lbl_80367100 + 0x10) > t) {
            *(s16 *)((u8 *)lbl_80367100 + 0x10) = t;
        }
    }
    if ((flags & 0xF) == 0) {
        return;
    }
    if (((u8 *)lbl_80367100)[0x16] != 0) {
        pos = *(s16 *)((u8 *)lbl_80367100 + 0x3A) - *(s16 *)((u8 *)lbl_80367100 + 0x14);
        lim = *(s16 *)((u8 *)lbl_80367100 + 0x38) - *(s16 *)((u8 *)lbl_80367100 + 0x6);
        if (pos < 0) {
            pos = 0;
        }
        if (flags & 0x8) {
            if (pos > 0 && pos > lim) {
                (*(s16 *)((u8 *)lbl_80367100 + 0x3A))--;
            }
        }
        if (flags & 0x4) {
            (*(s16 *)((u8 *)lbl_80367100 + 0x3A))++;
            if (*(s16 *)((u8 *)lbl_80367100 + 0x3A) == *(s16 *)((u8 *)lbl_80367100 + 0x38)) {
                ((u8 *)lbl_80367100)[0x16] = 0;
            }
        }
        if (flags & 1) {
            for (i = 0; i < 8; i++) {
                if (pos > 0 && pos > lim) {
                    (*(s16 *)((u8 *)lbl_80367100 + 0x3A))--;
                }
            }
        }
        if (flags & 2) {
            z = 0;
            for (i = 0; i < 8; i++) {
                (*(s16 *)((u8 *)lbl_80367100 + 0x3A))++;
                if (*(s16 *)((u8 *)lbl_80367100 + 0x3A) == *(s16 *)((u8 *)lbl_80367100 + 0x38)) {
                    ((u8 *)lbl_80367100)[0x16] = z;
                }
            }
        }
    } else if (flags & 0x8) {
        ((u8 *)lbl_80367100)[0x16] = 1;
        *(s16 *)((u8 *)lbl_80367100 + 0x3A) = *(s16 *)((u8 *)lbl_80367100 + 0x38) - 1;
    }
}
#pragma optimization_level reset
void fn_800059B0(void) {

}

#pragma peephole off
void fn_800059B4(void)
{
  extern void *lbl_80367100;
  struct { s32 off; u8 z; } s;
  s32 i;
  void *table;
  u8 *p;

  s.off = 0;
  i = 0;
  s.z = s.off;
  while (i < (*((s16 *) (((u8 *) lbl_80367100) + 6))))
  {
    table = *((void **) lbl_80367100);
    i += 1;
    p = *((u8 **) (((u8 *) table) + s.off));
    *p = s.z;
    s.off += 4;
  }

  *((u32 *) (((u8 *) lbl_80367100) + 0x2C)) = 0;
  *((u32 *) (((u8 *) lbl_80367100) + 0x30)) = 0;
}
#pragma peephole reset
void fn_800059FC(s16 a, s16 b, s16 c, s16 d, s16 e) {
    extern void *lbl_80367100;
    s16 x;
    s16 w;

    if (a >= 0) {
        *(s16 *)((u8 *)lbl_80367100 + 8) = a;
    }
    if (b >= 0) {
        *(s16 *)((u8 *)lbl_80367100 + 0xA) = b;
    }
    if (c >= 0) {
        *(s16 *)((u8 *)lbl_80367100 + 0xC) = c;
    }
    if (d >= 0) {
        *(s16 *)((u8 *)lbl_80367100 + 0xE) = d;
    }
    if (e >= 0) {
        *(s16 *)((u8 *)lbl_80367100 + 0x12) = e;
    }
    x = *(s16 *)((u8 *)lbl_80367100 + 8);
    w = *(s16 *)((u8 *)lbl_80367100 + 0xC);
    if (x + w > 0x280) {
        *(s16 *)((u8 *)lbl_80367100 + 0xC) = 0x27F - x;
    }
    *(s16 *)((u8 *)lbl_80367100 + 0x14) = d / e;
}

void fn_80005A84(s32 size, s32 count) {
    void *fn_800C4638(s32, void *, s32);
    extern void *lbl_80367100;
    extern u8 lbl_80267B60[];

    u8 *self;
    u8 *buffer;
    s32 tableSize;
    s32 offset;
    s32 i;
    s32 zero;


    if (size == 0) {
        size = 0x34;
    }

    if (count == 0) {
        count = 0x200;
    }

    self = (u8 *)fn_800C4638(
        0x40,
        lbl_80267B60 + 0x1C,
        0
    );

    lbl_80367100 = self;

    *(s16 *)(self + 4) = (size + 8) & 0xFC;
    *(s16 *)(self + 6) = count;

    *(s16 *)(self + 0x34) = 8;
    *(s16 *)(self + 0x36) = 0;
    self[0x16] = 0;
    self[0x17] = 0;
    self[0x18] = 1;
    *(s16 *)(self + 0x3C) = 0;

    tableSize = *(s16 *)(self + 6) << 2;

    buffer = (u8 *)fn_800C4638(
        tableSize + (*(s16 *)(self + 4) * *(s16 *)(self + 6)),
        lbl_80267B60 + 0x1C,
        0
    );

    *(u8 **)self = buffer;

    i = 0;
    offset = i;
    zero = i;

    buffer = *(u8 **)self;
    *(u8 **)buffer = buffer + tableSize;

    while (i < *(s16 *)(self + 6)) {
        *(u8 **)(*(u8 **)self + offset) =
            *(u8 **)(*(u8 **)self) +
            (*(s16 *)(self + 4) * i);

        *(u8 *)(*(u8 **)(*(u8 **)self + offset)) = zero;

        offset += 4;
        i++;
    }

    *(s16 *)((u8 *)lbl_80367100 + 8) = 0;
    *(s16 *)((u8 *)lbl_80367100 + 0xA) = 0x10;
    *(s16 *)((u8 *)lbl_80367100 + 0xC) = 0x260;
    *(s16 *)((u8 *)lbl_80367100 + 0xE) = 0x1A0;
    *(s16 *)((u8 *)lbl_80367100 + 0x12) = 0x10;

    if (*(s16 *)((u8 *)lbl_80367100 + 8) +
        *(s16 *)((u8 *)lbl_80367100 + 0xC) > 0x280) {
        *(s16 *)((u8 *)lbl_80367100 + 0xC) =
            0x27F - *(s16 *)((u8 *)lbl_80367100 + 8);
    }

    *(s16 *)((u8 *)lbl_80367100 + 0x14) = 0x1A;

    *(s16 *)(self + 0x10) =
        *(s16 *)(self + 0xE) - 0x41;
}

void fn_80005C18(void) {
    M2C_UNK fn_800111FC();
    extern s32 lbl_80367108;
    fn_800111FC();
    lbl_80367108 = fn_801047D0();
}

void fn_80005C40(void) {
    fn_801047D0();
}

void fn_80005C60(void) {
    void Process_Create(void *, s32);
    extern u8 gGameProc[];
    Process_Create(gGameProc, 3);
}

/* Boot init: grow heap, load file caches and archives, init UI drawers and battle defaults. */
void Game_InitSystems(void) {
    void fn_800110B8(void);
    void fn_8001B134(void *);
    void Archive_Load(void *);
    void Ui_InitIconDrawer(void *);
    void fn_8005BCAC(void);
    void FileCache_Load(void *);
    void fn_80066F64(void);
    void fn_80067480(void);
    void fn_8006826C(s32);
    void fn_8007C34C(void);
    void fn_8007C408(void);
    void fn_8008CD9C(void);
    void fn_800A6450(void);
    void fn_800C2750(void);
    void Heap_AdjustExtent(s32);
    void fn_800FC678(void);
    void fn_80146AF0(void);
    void fn_80147188(s32);
    void fn_801A2AC4(void);
    void FaceResMan_Init(void);
    extern u8 Game_str[];
    extern u8 gUiIconDrawer[];
    extern u8 gItemIconDrawer[];
    extern u8 gBattleState[];
    extern u8 gBgmQuietVol;
    extern u8 gBgmVol;
    extern u8 lbl_80367AF6;

    Heap_AdjustExtent(0x100000);
    FileCache_Load(Game_str + 0x9B);
    Heap_AdjustExtent(0xFFF00000);
    fn_800C2750();
    fn_8006826C(0x200);
    fn_80066F64();
    fn_80067480();
    fn_8001B134(Game_str + 0xA6);
    fn_800FC678();
    fn_800A6450();
    fn_801A2AC4();
    fn_8007C408();
    fn_8007C34C();
    FaceResMan_Init();
    fn_8005BCAC();
    fn_800110B8();
    fn_8008CD9C();
    Ui_InitIconDrawer(gUiIconDrawer);
    Ui_InitIconDrawer(gItemIconDrawer);
    Archive_Load(Game_str + 0xB2);
    Archive_Load(Game_str + 0xBD);
    Archive_Load(Game_str + 0xD1);
    fn_80147188(0);
    gBgmQuietVol = 0x64;
    gBgmVol = 0x64;
    lbl_80367AF6 = 0;
    fn_80146AF0();
    gBattleState[0xA1] = 0x40;
}

void fn_80005D88(void) {
    extern u8 gBattleState[];
    void *temp_r31;

    temp_r31 = (u16 *)gBattleState + 0x9C / sizeof(u16);
    fn_801998B0(temp_r31);
    fn_80199818(temp_r31);
}

void fn_80005DC8(void) {
    unsigned long long fn_80006798(void);
    extern u8 gBattleState[];

    *(unsigned long long *)(gBattleState + 0x58) += fn_80006798();
    *(unsigned long long *)(gBattleState + 0x60) += fn_80006798();
}

u8 fn_80005E2C(void) {
    u32 OSGetResetCode(void);
    extern s32 gGameFlags;
    u8 var_r3;

    if ((OSGetResetCode() >> 31) == 0) {
        return 0;
    }

    var_r3 = 1;

    if (gGameFlags & 0x90000) {
        return (u8)((u32)__cntlzw(OSGetResetCode() & 2) >> 5);
    }

    if (gGameFlags & 0x60000) {
        var_r3 = (u8)((u32)__cntlzw(OSGetResetCode() & 0x20) >> 5);
    }

    return var_r3;
}

s32 fn_80005E98(void) {
    extern u8 gBattleState[];
    return gBattleState[0x10] == 0x1D;
}

void fn_80005EB4(void) {
    M2C_UNK fn_800C4B8C();
    fn_800C4B8C();
}

void fn_80005ED4(void) {
    extern u8 Game_str[];
    Heap_Create((u8 *)Game_str + 0xDF, 0xB00000);
}

#pragma optimization_level 3
void fn_80005F04(void)
{
    void fn_801ED3D4(void);
    void fn_80121414(void);
    void fn_801E379C(void *);
    void Battle_SetPhase(void *, u32);
    void fn_8014D41C(void *);
    void SaveData_Release(void *);
    void *Process_Find(void *);
    void Battle_LoadMap(void);
    void fn_8014D920(void);
    s32 fn_8016947C(void);
    void fn_80016C58(void);
    void BattleState_SetCamPos(float, float);
    void Camera_SyncFromBattleState(void);
    void Unit_ResetAll(void);

    extern u8 gSaveDataBase;
    extern u8 gBattleState[];
    extern u8 gGameProc[];

    u8 *object;
    u8 *data;
    u8 *state;
    u8 type;
    s32 bit;

    object = *(u8 **)((u8 *)&gSaveDataBase + 4);

    fn_801ED3D4();
    fn_80121414();
    fn_801E379C(object);

    type = object[0x65];

    switch (type) {
    case 10:
        data = gBattleState;
        bit = 1;
        data[0x9F] = __rlwimi(data[0x9F], bit, 3, 28, 28);

        Battle_SetPhase(data, object[0x64]);
        fn_8014D41C(data);

    case 4:
        SaveData_Release(&gSaveDataBase);

        state = (u8 *)Process_Find(gGameProc);
        *(s32 *)(state + 0x60) = 0xA;
        break;

    case 5:
    case 6:
    case 7:
        Battle_LoadMap();
        fn_8014D920();
        fn_801E379C(object);
        SaveData_Release(&gSaveDataBase);

        state = (u8 *)Process_Find(gGameProc);
        *(s32 *)(state + 0x60) = 0x11;
        break;

    case 1:
        Battle_LoadMap();
        fn_8014D920();
        fn_801E379C(object);
        SaveData_Release(&gSaveDataBase);

        if ((u8)fn_8016947C() == 0) {
            fn_80016C58();

            state = (u8 *)Process_Find(gGameProc);
            *(s32 *)(state + 0x60) = 0xE;
        } else {
            data = gBattleState;

            BattleState_SetCamPos((float)(s8)data[0x52], (float)(s8)data[0x53]);
            Camera_SyncFromBattleState();

            state = (u8 *)Process_Find(gGameProc);
            *(s32 *)(state + 0x60) = 0x15;
        }
        break;

    case 2:
        Battle_LoadMap();
        fn_8014D920();
        fn_801E379C(object);
        SaveData_Release(&gSaveDataBase);

        state = (u8 *)Process_Find(gGameProc);
        *(s32 *)(state + 0x60) = 0x16;
        break;

    case 3:
        SaveData_Release(&gSaveDataBase);
        fn_801E379C(object);
        Unit_ResetAll();

        state = (u8 *)Process_Find(gGameProc);
        *(s32 *)(state + 0x60) = 0xA;
        break;

    case 8:
        state = (u8 *)Process_Find(gGameProc);
        *(s32 *)(state + 0x60) = 0x12;
        break;

    case 0:
    case 9:
    default:
        break;
    }
}
#pragma optimization_level reset
void fn_800060F8(void) {
    void Unit_ResetAll(void);
    Unit_ResetAll();
}

void fn_80006118(void)
{
  void *Process_Find(void *);
  extern u8 gGameProc[];
  extern u8 gSaveDataBase;
  void *temp;
  void *ret;
  if (1)
  {
    ret = &gSaveDataBase;
    temp = *((void **) (((u8 *) ret) + 4));
    ret = ((void *(*)(void *, void *))Process_Find)(gGameProc, ret);
    *(((u8 *) temp) + 0x64) = *((u32 *) (((u8 *) ret) + 0x64));
  }
  *(((u8 *) temp) + 0x65) = 0xA;
}

void fn_80006160(s32 arg0)
{
    extern u8 gGameProc[];
    void *Process_Find(void *);
    s32 *obj;

    obj = (s32 *)Process_Find(gGameProc);
    obj[0x64 / 4] = arg0;
}

void fn_80006198(void) {
    extern u8 gGameProc[];
    void *Process_Find(void *);
    void Process_Goto(void *, u8);
    void *arg0 = Process_Find(gGameProc);
    Process_Goto(arg0, (u8)*(u32 *)((u8 *)arg0 + 0x60));
}

void fn_800061CC(void *arg0) {
    void Process_Goto(void *, u8);
    Process_Goto(arg0, (u8)*(u32 *)((u8 *)arg0 + 0x60));
}

s32 Game_GetState(void) {
    extern u8 gGameProc[];
    void *Process_Find(void *);
    void *arg0 = Process_Find(gGameProc);
    return *(u32 *)((u8 *)arg0 + 0x60);
}

void Game_SetState(s32 arg0) {
    extern u8 gGameProc[];
    void *Process_Find(void *);
    s32 *obj;
    obj = (s32 *)Process_Find(gGameProc);
    obj[0x60 / 4] = arg0;
}
#include <common.h>
extern u32 jumptable_80283748[];
extern u8 gBattleState[1400];
extern u8 gGameProc[1100];
extern f64 lbl_80368B60;
