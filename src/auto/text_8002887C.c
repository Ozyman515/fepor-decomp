/* Functions from 0x8002887C to 0x80033080, found by decomp-toolkit. */
#include "common.h"
void fn_801481CC(void *, s32);

void fn_8002F6E8(void *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4);

static inline void *map_find_xy(s32 *arg0, s8 arg1, s8 arg2) {
    s32 *p;
    s32 i;
    s32 n;

    n = *arg0;
    p = arg0;
    for (i = 0; i < n; p = (s32 *)((char *)p + 0x14), i++) {
        if (arg1 == *(s8 *)((char *)p + 8) && arg2 == *(s8 *)((char *)p + 9)) {
            return (void *)((char *)arg0 + i * 0x14 + 8);
        }
    }
    return NULL;
}

static inline u8 *map_first(s32 *m) {
    s32 c;
    u8 *e;

    c = *m;
    e = (u8 *)m + 8;
    if (c <= 0) {
        e = (u8 *)0;
    }
    return e;
}

void fn_8002887C(void) {
    s32 Unit_GetMov(void *);
    M2C_UNK fn_8003B69C(void *);
    M2C_UNK MapUi_ShowUnitRanges();
    M2C_UNK MapCursor_InitTrail(u8, u8, s32);
    void *Map_GetCursorUnit();
    u8 temp_r31;
    u8 temp_r30;
    void *temp_r29;

    temp_r29 = Map_GetCursorUnit();
    MapUi_ShowUnitRanges();
    temp_r31 = M2C_FIELD(temp_r29, u8 *, 0x19F);
    temp_r30 = M2C_FIELD(temp_r29, u8 *, 0x19E);
    MapCursor_InitTrail(temp_r30, temp_r31, Unit_GetMov(temp_r29));
    fn_8003B69C(temp_r29);
}

#pragma global_optimizer off
void fn_800288E4(void) {
    s8 Fx_FindSlotByName(void *);
    void fn_80147EBC(s32);
    void fn_801481CC(void *, s32);
    void fn_8014876C(void *, s32, s32);
    void fn_80146AF0(void);
    extern u8 lbl_80269070[];
    extern u16 gFxChannels[];
    if (Fx_FindSlotByName((u8 *)lbl_80269070 + 0xE6) != -1) {
        fn_80147EBC(0x3E8);
        fn_8014876C(gFxChannels, 0x64, 0x3E8);
        fn_801481CC((u8 *)lbl_80269070 + 0xE6, 0x190);
        fn_80146AF0();
    }
}
#pragma global_optimizer on
void fn_80028950(void) {
    void BattleState_SetCamPos(void *, f32, f32);
    void fn_80183A90(void *);
    extern u8 gUiContext[];
    extern u8 gBattleState[];
    void *temp_r31;

    temp_r31 = *(void **)gUiContext;
    fn_80183A90(temp_r31);
    BattleState_SetCamPos(gBattleState, M2C_FIELD(temp_r31, s8 *, 0x19E), M2C_FIELD(temp_r31, s8 *, 0x19F));
}

void fn_800289D0(void *arg0) {
    extern u8 gUiContext[],gBattleState[],gBattleMap[];
    void *BattleMap_GetPath(void *);
    void fn_800F0B18(void *);
    s32 Status_Test(void *,s32);
    u8 fn_8001FB04(void *,s8 *,s8 *,s32,s32);
    void BattleState_SetCamPos(void *,f32,f32);
    void MoveAnim_BindMapPath(void *,void *);
    s8 x;
    s8 y;
    void *unit;
    unit=*(void**)gUiContext;
    gBattleState[0x51d]=0;
    fn_800F0B18(BattleMap_GetPath(gBattleMap));
    {
        s32 status=Status_Test((u8*)unit+0x1bc,4);
        x=*((s8*)unit+0x19e);
        y=*((s8*)unit+0x19f);
        switch(fn_8001FB04(gBattleMap,&x,&y,status,0)) {
        case 1:
            BattleState_SetCamPos(gBattleState,x,y);
            gUiContext[8]=0x24;
            break;
        case 2:
            BattleState_SetCamPos(gBattleState,x,y);
            gUiContext[8]=0x2d;
            break;
        }
    }
    MoveAnim_BindMapPath(unit,arg0);
}

void fn_80028B4C(s32 arg0) {
    void fn_8018DC18(void);
    void Process_Unlink(s32);
    extern u8 gUiContext[];

    if (gUiContext[8] == 0x35) {
        fn_8018DC18();
        Process_Unlink(arg0);
    }
}

void MapUi_HandleUnitSelect(void *proc) {
    /* Cancel unit select in some UI modes, or confirm and show move ranges. */
    void Process_Goto(void *, s32);
    u8 Ui_CanConfirmUnitSelect(void *);
    void Ui_ConfirmUnitAction(void *);
    void MapUi_ShowUnitRanges(void *);
    void MapCursor_InitTrail(u8, u8, s32);
    extern u8 gUiContext[];
    u8 *ctx;
    s32 mode;
    void *unit;

    ctx = gUiContext;
    mode = ctx[8];
    switch (mode) {
    case 7:
        if (*(u8 *)((u8 *)*(void **)((u8 *)*(void **)ctx + 0x190) + 8) != 0) {
            ctx[8] = 1;
            break;
        }
    case 6:
    case 0x1B:
    case 0x1C:
    case 0x28:
        Process_Goto(proc, 6);
        return;
    }

    if ((u8)Ui_CanConfirmUnitSelect(gUiContext) != 0) {
        Ui_ConfirmUnitAction(gUiContext);
        unit = *(void **)gUiContext;
        MapUi_ShowUnitRanges(unit);
        MapCursor_InitTrail(
            ((u8 *)unit)[0x19E],
            ((u8 *)unit)[0x19F],
            (s8)gUiContext[0x11]
        );
        Process_Goto(proc, 3);
    }
}

void fn_80028C90(s32 arg0) {
    void Process_Unlink(s32);
    u32 fn_800AA5F0(s32);
    void fn_8018DC18(void);
    extern u8 gUiContext[];
    extern u8 gBattleState[];
    void *ctx;
    u32 bit;

    ctx = *(void **)gUiContext;
    *(u32 *)((u8 *)ctx + 0x1A0) |= 1;
    bit = (gBattleState[0x9E] >> 5) & 1;
    if (bit != 1) {
        if (fn_800AA5F0(0) == 0) {
            fn_8018DC18();
            Process_Unlink(arg0);
        }
    }
}

void fn_80028D04(void *arg0) {
void Process_Goto(void *,s32);
void fn_80027038(void *);
void UiCtx_EndMoveSelect(void *,s32);
void BattleState_SetCamPos(void *,f32,f32);
extern u8 gUiContext[], gBattleState[];
switch(gUiContext[8]) {
case 0x32: case 0x33:
Process_Goto(arg0,6);
break;
default:
fn_80027038(gUiContext);
UiCtx_EndMoveSelect(gUiContext,1);
BattleState_SetCamPos(gBattleState,(f32)(s8)gUiContext[0xD],(f32)(s8)gUiContext[0xE]);
break;
}
}

void fn_80028DBC(void *arg0) {
void fn_800271C8(void *, void *);
void fn_8002807C(void *);
void MapUi_ShowUnitRanges(void *);
void Process_Goto(void *, s32);
extern u8 gUiContext[];
u8 *ctx=gUiContext;
s32 mode=ctx[8];
void *unit;
switch (mode) {
case 0x23: Process_Goto(arg0,6); return;
case 0:
if (ctx[0x16]==0) {
unit=*(void **)ctx;
fn_8002807C(ctx);
MapUi_ShowUnitRanges(unit);
Process_Goto(arg0,3);
return;
}
break;
case 7: ctx[0x16]|=1; break;
case 6: case 0x28: gUiContext[0x16]|=2; break;
case 0x1B: case 0x1C: ctx[0x16]|=4; break;
}
fn_800271C8(gUiContext,arg0);
}

void fn_80028EC8(s32 arg0) {
    void Ui_PlaySeCue(void *, s32);
    void fn_800725F8(s32);
    extern u8 gUiContext[];
    extern u8 lbl_80269070[];
    u8 temp_r0;

    temp_r0 = gUiContext[8];
    if (temp_r0 != 0x24 && temp_r0 != 0x2D) {
        Ui_PlaySeCue(lbl_80269070 + 0xF0, 0x64);
        fn_800725F8(arg0);
    }
}

void fn_80028F28(void) {
    void fn_800280C8(void *, s32, s32);
    void BattleState_SetCamPos(void *, f32, f32);
    extern f32 gBattleState[];
    extern u8 gUiContext[];
    f32 *base;

    base = gBattleState;
    fn_800280C8(gUiContext, (s32)base[0x524 / 4], (s32)base[0x528 / 4]);
    BattleState_SetCamPos(gBattleState, (f32)(s8)(s32)base[0x524 / 4], (f32)(s8)(s32)base[0x528 / 4]);
}

void fn_80028FE4(void *proc) {
    extern u32 gUiInputFlags;
    extern u32 *gPadInput;
    extern u8 gBattleState[], gUiContext[], gBattleMap[], lbl_80269070[];
    void *Map_GetCursorUnit(void);
    void Process_Goto(void *, s32);
    void fn_8007D064(void *, void *, s32);
    void fn_800A8400(void);
    u8 fn_800AA304(s32,s32);
    void Ui_PlaySeCue(void *,s32);
    void Map_HideMoveLimitView(void);
    void fn_800919D8(void);
    void Map_RefreshUnitMap(void *);
    s32 Unit_GetMov(void *);
    void MapCursor_InitTrail(u8,u8,s32);
    void BattleState_SetCamPos(void *,f32,f32);
    u32 keys;
    void *unit;
    void *selected;
    u8 y,x;
    if (!(gUiInputFlags & 0x80)) {
        keys = gPadInput[1] & (gPadInput[2] ^ gPadInput[1]);
        unit = Map_GetCursorUnit();
        if (unit && (keys & 0x800)) {
            Process_Goto(proc,3);
            fn_8007D064(unit,proc,0);
            fn_800A8400();
            return;
        }
        if (keys & 0x100) {
            if (!fn_800AA304((s32)*(f32 *)(gBattleState+0x524),(s32)*(f32 *)(gBattleState+0x528))) {
                Ui_PlaySeCue(lbl_80269070+0x105,100);
                return;
            }
            Process_Goto(proc,5);
            Map_HideMoveLimitView();
            fn_800919D8();
            Ui_PlaySeCue(lbl_80269070+0x113,100);
            return;
        }
        if (keys & 0x200) {
            if ((s8)gUiContext[0x12] == 0) {
                Map_RefreshUnitMap(gBattleMap);
                Process_Goto(proc,8);
                Map_HideMoveLimitView();
                fn_800919D8();
                Ui_PlaySeCue(lbl_80269070+0x123,100);
                return;
            }
        } else if (!(keys & 0x400)) return;
        selected = *(void **)gUiContext;
        y = ((u8 *)selected)[0x19f];
        x = ((u8 *)selected)[0x19e];
        MapCursor_InitTrail(x,y,Unit_GetMov(selected));
        BattleState_SetCamPos(gBattleState,(f32)((s8 *)selected)[0x19e],(f32)((s8 *)selected)[0x19f]);
        Ui_PlaySeCue(lbl_80269070+0x123,100);
    }
}

void fn_800291D8(void *proc) {
    extern u32 gUiInputFlags;
    extern u32 *gPadInput;
    extern u8 gBattleState[], gBattleMap[], gUiContext[], lbl_80269070[];
    extern struct { void *head; s32 unk4; s32 unk8; } gUnitLists[];
    void *Map_GetCursorUnit(void);
    void Process_Goto(void *, s32);
    void fn_8007D064(void *, void *, s32);
    void fn_800A8400(void);
    void *fn_800AA5F0(void *);
    void BattleState_SetCamPos(void *, f32, f32);
    s32 Unit_GetPhaseActCode(void *);
    void Map_RefreshUnitMap(void *);
    void Map_SetupUnitMoveLimit(void *);
    void Ui_PlaySeCue(void *, s32);
    void UiCtx_BeginMoveSelect(void *, void *);
    void fn_800A8450(void);
    void fn_8018DB90(void);
    void fn_80072900(void *);
    void fn_8016B730(void *);
    void Map_HideMoveLimitView(void);
    u32 keys;
    void *unit;
    void *next;
    void *cur;
    u8 changed;

    if (!(gUiInputFlags & 0x80)) {
        keys = gPadInput[1] & (gPadInput[2] ^ gPadInput[1]);
        unit = Map_GetCursorUnit();
        if (unit && (keys & 0x800)) {
            Process_Goto(proc, 0);
            fn_8007D064(unit, proc, 0);
            fn_800A8400();
            return;
        }
        if (keys & 0x400) {
            void *v = fn_800AA5F0(Map_GetCursorUnit());
            if (v) {
                BattleState_SetCamPos(gBattleState, (f32)(s8)((u8 *)v)[0x19e], (f32)(s8)((u8 *)v)[0x19f]);
                Process_Goto(proc, 0);
                Ui_PlaySeCue(lbl_80269070 + 0x138, 100);
                return;
            }
        }
        if (keys & 0x100) {
            switch ((u8)Unit_GetPhaseActCode(unit)) {
            case 2:
                if (!(*(u32 *)((u8 *)unit + 0x1a0) & 0x800)) {
                    *(u32 *)((u8 *)unit + 0x1a0) |= 0x800;
                    Map_RefreshUnitMap(gBattleMap);
                    Map_SetupUnitMoveLimit(unit);
                    Ui_PlaySeCue(lbl_80269070 + 0x154, 100);
                }
                return;
            case 3:
                return;
            case 4:
            case 6:
                return;
            case 1:
                UiCtx_BeginMoveSelect(gUiContext, unit);
                { s32 x = (s8)((u8 *)unit)[0x19e];
                s32 y = (s8)((u8 *)unit)[0x19f];
                u8 *map = gBattleMap;
                map += x;
                map[y * 64 + 0xd] = ((u8 *)unit)[0x198]; }
                Ui_PlaySeCue(lbl_80269070 + 0x16f, 100);
                Process_Goto(proc, 2);
                return;
            case 0:
            case 5:
                break;
            }
        }
        if (keys & 0x200) {
            switch ((u8)Unit_GetPhaseActCode(unit)) {
            case 2:
                if (*(u32 *)((u8 *)unit + 0x1a0) & 0x800) {
                    *(u32 *)((u8 *)unit + 0x1a0) &= ~0x800;
                    Map_RefreshUnitMap(gBattleMap);
                    Map_SetupUnitMoveLimit(unit);
                    Ui_PlaySeCue(lbl_80269070 + 0x184, 100);
                    return;
                }
                break;
            case 0:
                changed = 0;
                cur = gUnitLists[1].head;
                while (cur) {
                    next = *(void **)((u8 *)cur + 0x184);
                    if (*(u32 *)((u8 *)cur + 0x1a0) & 0x800) {
                        *(u32 *)((u8 *)cur + 0x1a0) &= ~0x800;
                        changed = 1;
                    }
                    cur = next;
                }
                Map_RefreshUnitMap(gBattleMap);
                if (changed) {
                    Ui_PlaySeCue(lbl_80269070 + 0x184, 100);
                }
                return;
            case 1:
                break;
            }
        }
        if (keys & 0x1000) {
            fn_800A8400();
            fn_8016B730(proc);
            return;
        }
        if (keys & 0x10) {
            Map_HideMoveLimitView();
            fn_800A8450();
            fn_8018DB90();
            fn_80072900(proc);
            Process_Goto(proc, 7);
        }
    }
}

void fn_800294E8(void) {
    void *Map_GetCursorUnit(void);
    extern u8 gUiContext[];
    extern u8 gBattleState[];

    if (Map_GetCursorUnit() != NULL) {
        gBattleState[0x51D] = 0xB;
    } else {
        gBattleState[0x51D] = 9;
    }
    if ((s8)gUiContext[0x12] != 0) {
        switch (gBattleState[0x51D]) {
        case 9:
            gBattleState[0x51D] = 0xC;
            break;
        case 10:
            gBattleState[0x51D] = 0xD;
            break;
        case 11:
            gBattleState[0x51D] = 0xE;
            break;
        }
    }
}

void fn_80029598(void) {
void *Map_GetCursorUnit(void);
void Allegiance_FillMask(s32,u8 *);
extern u8 gUnits[],gBattleState[];
u8 mask[4];
u8 found;
u8 *unit;
s32 flags;
s32 i;
unit=Map_GetCursorUnit();
if(!unit) {
found=0;
Allegiance_FillMask(1,mask);
for(i=1;i<160;i++) {
u8 id=i;
u8 *p=id?gUnits+(id-1)*0x280:0;
if(*(u32 *)(p+0x188) && mask[(*(u8 **)(p+0x190))[8]] && (*(u32 *)(p+0x1a0)&0x800)) {found=1;break;}
}
if(found) gBattleState[0x51d]=2;
else gBattleState[0x51d]=1;
return;
}
flags=*(u32 *)(unit+0x1a0);
if(flags&1) {gBattleState[0x51d]=4;return;}
switch((s32)(*(u8 **)(unit+0x190))[8]) {
case 0: gBattleState[0x51d]=3;break;
case 1: if(flags&0x800) gBattleState[0x51d]=6; else gBattleState[0x51d]=5;break;
case 2: gBattleState[0x51d]=8;break;
case 3: gBattleState[0x51d]=7;break;
}
}

void fn_80029730(void) {
    void fn_800F214C(void);
    void fn_800F20E0(void);
    void fn_800F0BFC(s32, s32);
    void fn_800F0BC8(void);
    extern u8 gBattleState[];

    fn_800F214C();
    fn_800F20E0();
    fn_800F0BFC((s32)*(f32 *)(gBattleState + 0x524), (s32)*(f32 *)(gBattleState + 0x528));
    fn_800F0BC8();
}

void fn_80029784(void) {
    u8 fn_800AA188();
    M2C_UNK fn_800F214C();
    extern s32 gUiInputFlags;
    if ((fn_800AA188() != 0) && !(gUiInputFlags & 0x80)) {
        fn_800F214C();
        fn_800F20E0();
    }
}

void *fn_800297C0(void *arg0, s16 arg1) {
    extern u8 gMemStreamVtbl[];
    extern u8 gStreamBaseVtbl[];
    s32 temp_r30;

    if (arg0 != NULL) {
        *(void **)((char *)arg0 + 0x10) = gMemStreamVtbl;
        if (arg0 != NULL) {
            *(void **)((char *)arg0 + 0x10) = gStreamBaseVtbl;
            if (*(u8 *)((char *)arg0 + 0xC) != 0) {
                fn_800C4588(*(s32 *)((char *)arg0));
                *(s32 *)((char *)arg0) = 0;
                *(u8 *)((char *)arg0 + 0xC) = 0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

s32 fn_80029848(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 4) - M2C_FIELD(arg0, s32 *, 0);
}

#pragma cplusplus on
extern "C" {
void fn_80029858(s8 x, s8 y) {
    void fn_8002F6E8(void *, s8, s8, u8, s32);
    void fn_8002F728(void *);
    extern u8 lbl_80284E10[];
    extern u8 lbl_80284E20[];
    extern u8 gTargetList[];
    extern u8 gBattleMap[];
    struct Visitor {
        virtual void v0(s8, s8) = 0;
        virtual void visit(s8, s8) = 0;
    };
    struct {
        void *vtbl;
    } obj;
    u8 id;

    obj.vtbl = lbl_80284E20;
    obj.vtbl = lbl_80284E10;
    fn_8002F728(gTargetList);
    id = gBattleMap[x + (y << 6) + 0xD];
    if (id != 0) {
        fn_8002F6E8(gTargetList, x, y, id, 1);
    }
    if (y - 1 >= 0) {
        ((Visitor *)&obj)->visit(x, y - 1);
    }
    if (x + 1 < *(s32 *)gBattleMap) {
        ((Visitor *)&obj)->visit(x + 1, y);
    }
    if (y + 1 < *(s32 *)(gBattleMap + 4)) {
        ((Visitor *)&obj)->visit(x, y + 1);
    }
    if (x - 1 >= 0) {
        ((Visitor *)&obj)->visit(x - 1, y);
    }
}

void fn_800299B8(void *arg0) {
    void fn_8002F728(void *);
    extern u8 lbl_80284E20[];
    extern u8 lbl_80284E00[];
    extern u8 lbl_80284DF0[];
    extern u8 lbl_80284DE0[];
    extern u8 gTargetList[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    struct Visitor {
        virtual void apply(void *unit) = 0;
    };
    struct {
        void *vtbl;
        void *arg;
    } obj;
    void *unit;
    u8 id;
    s8 x;
    s8 y;
    u16 *flags;
    unsigned yOff;
    u16 f;

    obj.vtbl = lbl_80284E20;
    obj.vtbl = lbl_80284E00;
    obj.vtbl = lbl_80284DF0;
    obj.vtbl = lbl_80284DE0;
    obj.arg = arg0;
    fn_8002F728(gTargetList);
    x = (s8)*((u8 *)obj.arg + 0x19E);
    y = (s8)*((u8 *)obj.arg + 0x19F);
    yOff = y << 6;
    flags = (u16 *)(gBattleMap + ((x + (s32)yOff) << 1));
    f = *(u16 *)((u8 *)flags + (unsigned)0x408E);
    flags = (u16 *)((u8 *)flags + 0x408E);
    if ((f & 8) != 0) {
        id = gBattleMap[x + ((s8)(y - 1) << 6) + 0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 2) != 0) {
        id = gBattleMap[(s8)(x + 1) + (s32)yOff + 0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 4) != 0) {
        id = gBattleMap[x + ((s8)(y + 1) << 6) + 0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 1) != 0) {
        id = gBattleMap[(s8)(x - 1) + (s32)yOff + 0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
}

#pragma cplusplus on
void fn_80029C08(void *arg0) {
    void fn_8002F728(void *);
    extern u8 lbl_80284E20[];
    extern u8 lbl_80284E00[];
    extern u8 lbl_80284DF0[];
    extern u8 gTargetList[];
    extern u8 gUnits[];
    extern u8 gBattleMap[];
    struct Visitor {
        virtual void apply(void *unit) = 0;
    };
    struct {
        void *vtbl;
        void *arg;
    } obj;
    register void *unit;
    u8 id;
    s32 x;
    s8 y;
    u16 *flags;
    register unsigned yOff;
    u8 t;
    u16 f;

    obj.vtbl = lbl_80284E20;
    obj.vtbl = lbl_80284E00;
    obj.arg = arg0;
    obj.vtbl = lbl_80284DF0;
    fn_8002F728(gTargetList);
    t = *((u8 *)obj.arg + 0x19F);
    y = (s8)t;
    x = *(s8 *)((u8 *)obj.arg + 0x19E);
    yOff = y << 6;
    flags = (u16 *)((u32)gBattleMap + ((x + yOff) << 1));
    f = *(u16 *)((u8 *)flags + 0x408E);
    flags = (u16 *)((u8 *)flags + 0x408E);
    if (f & 8) {
        id = gBattleMap[x + ((s8)(y - 1) << 6) + 0xD];
        if (id) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if (*flags & 2) {
        id = gBattleMap[(s8)(x + 1) + yOff + 0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if (*flags & 4) {
        id = gBattleMap[x + ((s8)(y + 1) << 6) + 0xD];
        if (id) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if (*flags & 1) {
        id = gBattleMap[(s8)(x - 1) + yOff + 0xD];
        if (id) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if ((unsigned)unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
}
#pragma cplusplus reset

}
#pragma cplusplus reset

#pragma global_optimizer off
#pragma cplusplus on
extern "C" void fn_80029E4C(void *arg0) {
    extern u8 lbl_80284E00[];
    extern u8 lbl_80284E20[];
    extern u8 gTargetList[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    void fn_8002F728(void *);
    struct Visitor {
        virtual void apply(void *unit) = 0;
    };
    struct {
        void *vtbl;
        void *unit;
    } obj;
    s32 x;
    s32 y;
    u16 *flags;
    s32 yOff;
    void *unit;
    u8 id;
    u16 f;
    u8 *entry;

    obj.vtbl = lbl_80284E20;
    obj.unit = arg0;
    obj.vtbl = lbl_80284E00;
    fn_8002F728(gTargetList);
    {
        u8 *map;
        y = (s8)*(u8 *)((u8 *)obj.unit + 0x19F);
        x = *(s8 *)((u8 *)obj.unit + 0x19E);
        map = gBattleMap;
        yOff = y << 6;
        flags = (u16 *)(map + ((x + yOff) << 1));
        f = *(u16 *)((u8 *)flags + 0x408E);
        flags = (u16 *)((u8 *)flags + 0x408E);
        if ((f & 8) != 0) {
            entry = map + x;
            entry = entry + ((s8)(y - 1) << 6);
            id = entry[0xD];
            if (id) {
                unit = gUnits + (id - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (unit) {
                ((Visitor *)&obj)->apply(unit);
            }
        }
    }
    if ((*flags & 2) != 0) {
        u8 *map;
        u8 *t;
        map = gBattleMap;
        t = map + (s8)(x + 1);
        entry = t + yOff;
        id = entry[0xD];
        if (id) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 4) != 0) {
        u8 *map = gBattleMap;
        entry = map + x;
        entry = entry + ((s8)(y + 1) << 6);
        id = entry[0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 1) != 0) {
        u8 *map;
        u8 *t;
        map = gBattleMap;
        t = map + (s8)(x - 1);
        entry = t + yOff;
        id = entry[0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
}
#pragma cplusplus on
#pragma global_optimizer off
extern "C" void fn_8002A084(void *arg0) {
    extern u8 lbl_80284DD0[];
    extern u8 lbl_80284E20[];
    extern u8 gTargetList[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    void fn_8002F728(void *);
    struct Visitor {
        virtual void apply(void *unit) = 0;
    };
    struct {
        void *vtbl;
        void *unit;
    } obj;
    s32 x;
    s32 y;
    u16 *flags;
    s32 yOff;
    void *unit;
    u8 id;
    u16 f;
    u8 *entry;

    obj.vtbl = lbl_80284E20;
    obj.unit = arg0;
    obj.vtbl = lbl_80284DD0;
    fn_8002F728(gTargetList);
    {
        u8 *map;
        y = (s8)*(u8 *)((u8 *)obj.unit + 0x19F);
        x = *(s8 *)((u8 *)obj.unit + 0x19E);
        map = gBattleMap;
        yOff = y << 6;
        flags = (u16 *)(map + ((x + yOff) << 1));
        f = *(u16 *)((u8 *)flags + 0x408E);
        flags = (u16 *)((u8 *)flags + 0x408E);
        if ((f & 8) != 0) {
            entry = map + x;
            entry = entry + ((s8)(y - 1) << 6);
            id = entry[0xD];
            if (id) {
                unit = gUnits + (id - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (unit) {
                ((Visitor *)&obj)->apply(unit);
            }
        }
    }
    if ((*flags & 2) != 0) {
        u8 *map;
        u8 *t;
        map = gBattleMap;
        t = map + (s8)(x + 1);
        entry = t + yOff;
        id = entry[0xD];
        if (id) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 4) != 0) {
        u8 *map = gBattleMap;
        entry = map + x;
        entry = entry + ((s8)(y + 1) << 6);
        id = entry[0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 1) != 0) {
        u8 *map;
        u8 *t;
        map = gBattleMap;
        t = map + (s8)(x - 1);
        entry = t + yOff;
        id = entry[0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
}
#pragma global_optimizer reset
#pragma cplusplus reset
extern "C" void fn_8002A2BC(void *arg0) {
    extern u8 lbl_80284DC0[];
    extern u8 lbl_80284E20[];
    extern u8 gTargetList[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    void fn_8002F728(void *);
    struct Visitor {
        virtual void apply(void *unit) = 0;
    };
    struct {
        void *vtbl;
        void *unit;
    } obj;
    s32 x;
    s32 y;
    u16 *flags;
    s32 yOff;
    void *unit;
    u8 id;
    u16 f;
    u8 *entry;

    obj.vtbl = lbl_80284E20;
    obj.unit = arg0;
    obj.vtbl = lbl_80284DC0;
    fn_8002F728(gTargetList);
    {
        u8 *map;
        y = (s8)*(u8 *)((u8 *)obj.unit + 0x19F);
        x = *(s8 *)((u8 *)obj.unit + 0x19E);
        map = gBattleMap;
        yOff = y << 6;
        flags = (u16 *)(map + ((x + yOff) << 1));
        f = *(u16 *)((u8 *)flags + 0x408E);
        flags = (u16 *)((u8 *)flags + 0x408E);
        if ((f & 8) != 0) {
            entry = map + x;
            entry = entry + ((s8)(y - 1) << 6);
            id = entry[0xD];
            if (id) {
                unit = gUnits + (id - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (unit) {
                ((Visitor *)&obj)->apply(unit);
            }
        }
    }
    if ((*flags & 2) != 0) {
        u8 *map;
        u8 *t;
        map = gBattleMap;
        t = map + (s8)(x + 1);
        entry = t + yOff;
        id = entry[0xD];
        if (id) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 4) != 0) {
        u8 *map = gBattleMap;
        entry = map + x;
        entry = entry + ((s8)(y + 1) << 6);
        id = entry[0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 1) != 0) {
        u8 *map;
        u8 *t;
        map = gBattleMap;
        t = map + (s8)(x - 1);
        entry = t + yOff;
        id = entry[0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
}

void fn_8002A4F4(struct Unit* unit) {
void fn_8001EDA0(void *);
    void fn_8002F728(void *);
#pragma cplusplus on
    extern u8 lbl_80284DB0[];
    extern u8 lbl_80284E20[];
    extern u8 gTargetList[];
    extern s32 gBattleMap[];
    struct Visitor { virtual void v0(s8,s8)=0; virtual void visit(s8,s8)=0; };
    struct { void *vtbl; u8 flag; } obj;
    
    obj.vtbl=lbl_80284E20;
    obj.vtbl=lbl_80284DB0;
    obj.flag=0;
    obj.flag=1;
    fn_8001EDA0(&obj.flag);
    fn_8002F728(gTargetList);
    if(obj.flag&3) {
        s8 y;
        s8 x;
        y=*((s8*)unit+0x19f);
        x=*((s8*)unit+0x19e);
        if(y-1>=0) ((Visitor*)&obj)->visit(x,y-1);
        if(x+1<gBattleMap[0]) ((Visitor*)&obj)->visit(x+1,y);
        if(y+1<gBattleMap[1]) ((Visitor*)&obj)->visit(x,y+1);
        if(x-1>=0) ((Visitor*)&obj)->visit(x-1,y);
    }
#pragma cplusplus reset
}

#pragma cplusplus on
extern "C" void fn_8001EDA0(void *);
extern "C" void fn_8002F728(void *);
extern "C" void fn_8002A63C(void *arg0) {
    extern u8 lbl_80284DB0[];
    extern u8 lbl_80284E20[];
    extern u8 gTargetList[];
    extern s32 gBattleMap[];
    struct Visitor {
        virtual void v0(s8, s8) = 0;
        virtual void visit(s8, s8) = 0;
    };
    struct {
        void *vtbl;
        u8 flag;
    } obj;
    s8 y;
    register s8 x;

    obj.vtbl = lbl_80284E20;
    obj.vtbl = lbl_80284DB0;
    obj.flag = 0;
    obj.flag = 2;
    fn_8001EDA0(&obj.flag);
    fn_8002F728(gTargetList);
    if (obj.flag & 3) {
        y = M2C_FIELD(arg0, s8 *, 0x19F);
        x = M2C_FIELD(arg0, s8 *, 0x19E);
        if (y - 1 >= 0) {
            ((Visitor *)&obj)->visit(x, y - 1);
        }
        if (x + 1 < gBattleMap[0]) {
            ((Visitor *)&obj)->visit(x + 1, y);
        }
        if (y + 1 < gBattleMap[1]) {
            ((Visitor *)&obj)->visit(x, y + 1);
        }
        if (x - 1 >= 0) {
            ((Visitor *)&obj)->visit(x - 1, y);
        }
    }
}

#pragma cplusplus on
extern "C" void fn_8002A784(void *unit, u8 *arg1) {
    void fn_8001EDA0(void *);
    void fn_8002F728(void *);
    extern u8 lbl_80284DB0[];
    extern u8 lbl_80284E20[];
    extern u8 gTargetList[];
    extern s32 gBattleMap[];
    struct Visitor { virtual void v0(s8, s8) = 0; virtual void visit(s8, s8) = 0; };
    struct { void *vtbl; u8 flag; } obj;
    register s8 x;
    register s8 y;

    obj.vtbl = lbl_80284E20;
    obj.flag = 0;
    obj.vtbl = lbl_80284DB0;
    obj.flag = *arg1;
    fn_8001EDA0(&obj.flag);
    fn_8002F728(gTargetList);
    if (obj.flag & 3) {
        y = *((s8 *)unit + 0x19f);
        x = *((s8 *)unit + 0x19e);
        if (y - 1 >= 0)
            ((Visitor *)&obj)->visit(x, y - 1);
        if (x + 1 < gBattleMap[0])
            ((Visitor *)&obj)->visit(x + 1, y);
        if (y + 1 < gBattleMap[1])
            ((Visitor *)&obj)->visit(x, y + 1);
        if (x - 1 >= 0)
            ((Visitor *)&obj)->visit(x - 1, y);
    }
}

extern "C" void fn_8002A8CC(void *arg0, void *arg1) {
extern u8 lbl_80284E20[],lbl_80284DA0[],lbl_80284D90[],gTargetList[],gBattleMap[],gUnits[];
void fn_8002F728(void *); void Map_SelectRangeBuffer(void *,s32);
s32 Item_GetRangeForUnit(void *,void *); void Map_FillAttackRange(void *,s32,s32,s32,s32);
struct Visitor { virtual void visit(void *)=0; };
struct {void *vtbl; void *unit;} obj;
s32 y,x,rowOffset,index;
u8 *row,*cell,*map;
s32 range;
u8 ir,iy,ix;
obj.vtbl=lbl_80284E20;obj.vtbl=lbl_80284DA0;obj.unit=arg0;obj.vtbl=lbl_80284D90;
fn_8002F728(gTargetList);Map_SelectRangeBuffer(gBattleMap,6);
ir=((u8*)arg1)[0x1D];iy=((u8*)obj.unit)[0x19F];ix=((u8*)obj.unit)[0x19E];
Map_FillAttackRange(gBattleMap,ix,iy,ir,Item_GetRangeForUnit(arg1,obj.unit));
range=((s8*)arg1)[0x1D];map=gBattleMap;
for(y=0,rowOffset=0,row=map;(s8)y<*(s32*)(map+4);y++,rowOffset+=64,row+=64){
for(x=0,index=rowOffset,cell=row;(s8)x<*(s32*)map;x++,index++,cell++){
if((*(s16**)(map+0x14190))[index]>=range){
u8 id=cell[13];
if(id){void *unit;if(id)unit=gUnits+(id-1)*0x280;else unit=0;
((Visitor*)&obj)->visit(unit);
}
}
}
}
}

extern "C" void fn_8002AA34(void *arg0, void *arg1)
{
#pragma use_lmw_stmw on
#pragma global_optimizer off
    extern u8 lbl_80284E20[];
    extern u8 lbl_80284DA0[];
    extern u8 lbl_80284D80[];
    extern u8 gTargetList[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];

    void fn_8002F728(void *);
    void Map_SelectRangeBuffer(void *, s32);
    s32 Item_GetRangeForUnit(void *, void *);
    void Map_FillAttackRange(void *, s32, s32, s32, s32);

    struct { void *vtable; void *unit; } visitor;
    u8 *map;
    u8 *row;
    u8 *cell;
    u8 *item;
    u8 range;
    u8 y;
    u8 x;
    u8 id;
    void *target;
    s32 rowOffset;
    s32 bufferOffset;
    s32 rowIndex;
    s32 colIndex;

    visitor.vtable = lbl_80284E20;
    visitor.vtable = lbl_80284DA0;
    visitor.unit = arg0;
    visitor.vtable = lbl_80284D80;

    fn_8002F728(gTargetList);
    Map_SelectRangeBuffer(gBattleMap, 6);

    item = (u8 *)arg1;
    range = item[0x1D];
    y = ((u8 *)visitor.unit)[0x19F];
    x = ((u8 *)visitor.unit)[0x19E];

    Map_FillAttackRange(
        gBattleMap,
        x,
        y,
        range,
        Item_GetRangeForUnit(arg1, visitor.unit)
    );

    map = gBattleMap;
    range = (s8)item[0x1D];

    rowOffset = rowIndex = 0;
    row = map;

    while ((s8)rowIndex < *(s32 *)(map + 4)) {
        bufferOffset = rowOffset;
        cell = row;
        colIndex = 0;

        while ((s8)colIndex < *(s32 *)map) {
            if (*(s16 *)((u8 *)*(void **)(map + 0x14190)
                        + bufferOffset * 2) >= (s8)range) {
                id = cell[0xD];

                if (id != 0) {
                    if (id != 0) {
                        target = gUnits + (id - 1) * 0x280;
                    } else {
                        target = 0;
                    }

                    ((void (*)(void *, void *))
                        ((void **)visitor.vtable)[2])(
                            (void *)&visitor.vtable,
                            target
                        );
                }
            }

            bufferOffset++;
            cell++;
            colIndex++;
        }

        rowOffset += 0x40;
        row += 0x40;
        rowIndex++;
    }
}

extern "C" void fn_8002AB9C(s32 arg0, s32 arg1)
{
    extern u8 lbl_80284E20[];
    extern u8 lbl_80284DA0[];
    extern u8 lbl_80284D70[];
    extern u8 gTargetList[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];

    void fn_8002F728(void *);
    void Map_SelectRangeBuffer(void *, s32);
    s32 Item_GetRangeForUnit(void *, void *);
    void Map_FillAttackRange(void *, s32, s32, s32, s32);

    struct Visitor {
        virtual void visit(void *) = 0;
    };

    struct {
        void *vtbl;
        void *unit;
    } obj;

    s32 y;
    s32 x;
    s32 rowOffset;
    s32 index;
    s32 range;
    u8 *row;
    u8 *cell;
    u8 *map;
    u8 ir;
    u8 iy;
    u8 ix;

    obj.vtbl = lbl_80284E20;
    obj.vtbl = lbl_80284DA0;
    obj.unit = (void *)arg0;
    obj.vtbl = lbl_80284D70;

    fn_8002F728(gTargetList);
    Map_SelectRangeBuffer(gBattleMap, 6);

    ir = ((u8 *)arg1)[0x1D];
    iy = ((u8 *)obj.unit)[0x19F];
    ix = ((u8 *)obj.unit)[0x19E];

    Map_FillAttackRange(
        gBattleMap,
        ix,
        iy,
        ir,
        Item_GetRangeForUnit((void *)arg1, obj.unit)
    );

    range = ((s8 *)arg1)[0x1D];
    map = gBattleMap;

    for (y = 0, rowOffset = 0, row = map;
         (s8)y < *(s32 *)(map + 4);
         y++, rowOffset += 64, row += 64) {

        for (x = 0, index = rowOffset, cell = row;
             (s8)x < *(s32 *)map;
             x++, index++, cell++) {

            if ((*(s16 **)(map + 0x14190))[index] >= range) {
                u8 id = cell[0xD];

                if (id != 0) {
                    void *unit;

                    if (id != 0) {
                        unit = gUnits + (id - 1) * 0x280;
                    } else {
                        unit = 0;
                    }

                    ((Visitor *)&obj)->visit(unit);
                }
            }
        }
    }
}

#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on
#pragma global_optimizer off
extern "C" void fn_8002AD04(void *arg0, void *arg1) {
    extern u8 lbl_80284E20[];
    extern u8 lbl_80284DA0[];
    extern u8 lbl_80284D60[];
    extern u8 gTargetList[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    void fn_8002F728(void *);
    void Map_SelectRangeBuffer(void *, s32);
    s32 Item_GetRangeForUnit(void *, void *);
    void Map_FillAttackRange(void *, s32, s32, s32, s32);
    struct { void *vtable; void *unit; } visitor;
    u8 *row;
    u8 *map;
    u8 *cell;
    u8 *item;
    u8 range;
    u8 y;
    u8 x;
    u8 id;
    void *target;
    s32 rowIndex;
    s32 rowOffset;
    s32 bufferOffset;
    s32 colIndex;
    visitor.vtable = lbl_80284E20;
    visitor.vtable = lbl_80284DA0;
    visitor.unit = arg0;
    visitor.vtable = lbl_80284D60;
    fn_8002F728(gTargetList);
    Map_SelectRangeBuffer(gBattleMap, 6);
    item = (u8 *)arg1;
    range = item[0x1D];
    y = ((u8 *)visitor.unit)[0x19F];
    x = ((u8 *)visitor.unit)[0x19E];
    Map_FillAttackRange(gBattleMap, x, y, range, Item_GetRangeForUnit(arg1, visitor.unit));
    map = gBattleMap;
    range = (s8)item[0x1D];
    rowOffset = rowIndex = 0;
    row = map;
    while ((s8)rowIndex < *(s32 *)(map + 4)) {
        bufferOffset = rowOffset;
        cell = row;
        colIndex = 0;
        while ((s8)colIndex < *(s32 *)map) {
            if (*(s16 *)((u8 *)*(void **)(map + 0x14190) + bufferOffset * 2) >= (s8)range) {
                id = cell[0xD];
                if (id != 0) {
                    if (id != 0) {
                        target = gUnits + (id - 1) * 0x280;
                    } else {
                        target = 0;
                    }
                    ((void (*)(void *, void *))((void **)visitor.vtable)[2])((void *)&visitor.vtable, target);
                }
            }
            bufferOffset++;
            cell++;
            colIndex++;
        }
        rowOffset += 0x40;
        row += 0x40;
        rowIndex++;
    }
}
#pragma global_optimizer reset
extern "C" void fn_8002AE6C(void *arg0) {
    extern u8 lbl_80284D50[];
    extern u8 lbl_80284E20[];
    extern u8 gTargetList[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    void fn_8002F728(void *);
    struct Visitor {
        virtual void apply(void *unit) = 0;
    };
    struct {
        void *vtbl;
        void *unit;
    } obj;
    s32 x;
    s32 y;
    u16 *flags;
    s32 yOff;
    void *unit;
    u8 id;
    u16 f;
    u8 *entry;

    obj.vtbl = lbl_80284E20;
    obj.unit = arg0;
    obj.vtbl = lbl_80284D50;
    fn_8002F728(gTargetList);
    {
        u8 *map;
        y = (s8)*(u8 *)((u8 *)obj.unit + 0x19F);
        x = *(s8 *)((u8 *)obj.unit + 0x19E);
        map = gBattleMap;
        yOff = y << 6;
        flags = (u16 *)(map + ((x + yOff) << 1));
        f = *(u16 *)((u8 *)flags + 0x408E);
        flags = (u16 *)((u8 *)flags + 0x408E);
        if ((f & 8) != 0) {
            entry = map + x;
            entry = entry + ((s8)(y - 1) << 6);
            id = entry[0xD];
            if (id) {
                unit = gUnits + (id - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (unit) {
                ((Visitor *)&obj)->apply(unit);
            }
        }
    }
    if ((*flags & 2) != 0) {
        u8 *map;
        u8 *t;
        map = gBattleMap;
        t = map + (s8)(x + 1);
        entry = t + yOff;
        id = entry[0xD];
        if (id) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 4) != 0) {
        u8 *map = gBattleMap;
        entry = map + x;
        entry = entry + ((s8)(y + 1) << 6);
        id = entry[0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 1) != 0) {
        u8 *map;
        u8 *t;
        map = gBattleMap;
        t = map + (s8)(x - 1);
        entry = t + yOff;
        id = entry[0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_8002B0A4(void *arg0) {
extern u8 lbl_80284E20[],lbl_80284D40[],gTargetList[],gBattleMap[],gUnits[],gUiContext[];
void fn_8002F728(void *);
struct Visitor { virtual void apply(void *) = 0; };
void **vt;
s8 y;
s8 x;
u16 *flags;
s32 row;
u8 id;
void *unit;
vt=(void **)lbl_80284E20;
vt=(void **)lbl_80284D40;
fn_8002F728(gTargetList);
y=((u8*)arg0)[0x19f];
x=((u8*)arg0)[0x19e];
y=(s8)y;
x=(s8)x;
row=y<<6;
flags=(u16 *)(gBattleMap+2*(x+row));
u16 f=*(u16 *)((u8*)flags+0x408e);
flags=(u16 *)((u8*)flags+0x408e);
if (f & 8) { id=*(gBattleMap+x+((s8)(y-1)<<6)+0xd); if(id) unit=gUnits+(id-1)*0x280; else unit=0; if(unit) ((Visitor *)&vt)->apply(unit); }
if (*flags & 2) { id=*(gBattleMap+(s8)(x+1)+row+0xd); if(id) unit=gUnits+(id-1)*0x280; else unit=0; if(unit) ((Visitor *)&vt)->apply(unit); }
if (*flags & 4) { id=*(gBattleMap+x+((s8)(y+1)<<6)+0xd); if(id) unit=gUnits+(id-1)*0x280; else unit=0; if(unit) ((Visitor *)&vt)->apply(unit); }
if (*flags & 1) { id=*(gBattleMap+(s8)(x-1)+row+0xd); if(id) unit=gUnits+(id-1)*0x280; else unit=0; if(unit) ((Visitor *)&vt)->apply(unit); }
*(u32 *)(gUiContext+4)=0;
}

#pragma cplusplus reset

extern "C" void fn_8002B2E8(void *arg0) {
    extern u8 lbl_80284D30[];
    extern u8 lbl_80284E20[];
    extern u8 gTargetList[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    void fn_8002F728(void *);
    struct Visitor {
        virtual void apply(void *unit) = 0;
    };
    struct {
        void *vtbl;
        void *unit;
    } obj;
    s32 x;
    s32 y;
    u16 *flags;
    s32 yOff;
    void *unit;
    u8 id;
    u16 f;
    u8 *entry;

    obj.vtbl = lbl_80284E20;
    obj.unit = arg0;
    obj.vtbl = lbl_80284D30;
    fn_8002F728(gTargetList);
    {
        u8 *map;
        y = (s8)*(u8 *)((u8 *)obj.unit + 0x19F);
        x = *(s8 *)((u8 *)obj.unit + 0x19E);
        map = gBattleMap;
        yOff = y << 6;
        flags = (u16 *)(map + ((x + yOff) << 1));
        f = *(u16 *)((u8 *)flags + 0x408E);
        flags = (u16 *)((u8 *)flags + 0x408E);
        if ((f & 8) != 0) {
            entry = map + x;
            entry = entry + ((s8)(y - 1) << 6);
            id = entry[0xD];
            if (id) {
                unit = gUnits + (id - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (unit) {
                ((Visitor *)&obj)->apply(unit);
            }
        }
    }
    if ((*flags & 2) != 0) {
        u8 *map;
        u8 *t;
        map = gBattleMap;
        t = map + (s8)(x + 1);
        entry = t + yOff;
        id = entry[0xD];
        if (id) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 4) != 0) {
        u8 *map = gBattleMap;
        entry = map + x;
        entry = entry + ((s8)(y + 1) << 6);
        id = entry[0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 1) != 0) {
        u8 *map;
        u8 *t;
        map = gBattleMap;
        t = map + (s8)(x - 1);
        entry = t + yOff;
        id = entry[0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
}

#pragma cplusplus on
extern "C" void fn_8002B520(void *arg0) {
    extern u8 lbl_80284D20[];
    extern u8 lbl_80284E20[];
    extern u8 gTargetList[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    void fn_8002F728(void *);
    struct Visitor {
        virtual void apply(void *unit) = 0;
    };
    struct {
        void *vtbl;
        void *unit;
    } obj;
    s32 x;
    s32 y;
    u16 *flags;
    s32 yOff;
    void *unit;
    u8 id;
    u16 f;
    u8 *entry;

    obj.vtbl = lbl_80284E20;
    obj.unit = arg0;
    obj.vtbl = lbl_80284D20;
    fn_8002F728(gTargetList);
    {
        u8 *map;
        y = (s8)*(u8 *)((u8 *)obj.unit + 0x19F);
        x = *(s8 *)((u8 *)obj.unit + 0x19E);
        map = gBattleMap;
        yOff = y << 6;
        flags = (u16 *)(map + ((x + yOff) << 1));
        f = *(u16 *)((u8 *)flags + 0x408E);
        flags = (u16 *)((u8 *)flags + 0x408E);
        if ((f & 8) != 0) {
            entry = map + x;
            entry = entry + ((s8)(y - 1) << 6);
            id = entry[0xD];
            if (id) {
                unit = gUnits + (id - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (unit) {
                ((Visitor *)&obj)->apply(unit);
            }
        }
    }
    if ((*flags & 2) != 0) {
        u8 *map;
        u8 *t;
        map = gBattleMap;
        t = map + (s8)(x + 1);
        entry = t + yOff;
        id = entry[0xD];
        if (id) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 4) != 0) {
        u8 *map = gBattleMap;
        entry = map + x;
        entry = entry + ((s8)(y + 1) << 6);
        id = entry[0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 1) != 0) {
        u8 *map;
        u8 *t;
        map = gBattleMap;
        t = map + (s8)(x - 1);
        entry = t + yOff;
        id = entry[0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
}
#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void fn_800227F8(void *, s32);
extern "C" void fn_8002F728(void *);
extern "C" void fn_8002B758(void *arg0) {
    extern u8 lbl_80284D10[];
    extern u8 lbl_80284E20[];
    extern u8 gTargetList[];
    extern u8 gBattleMap[];
    struct Visitor {
        virtual void v0(s8, s8) = 0;
        virtual void visit(s8, s8) = 0;
    };
    struct {
        void *vtbl;
        void *unit;
    } obj;
    u16 *flags;
    s8 y;
    s8 x;

    obj.vtbl = lbl_80284E20;
    obj.unit = arg0;
    obj.vtbl = lbl_80284D10;
    fn_8002F728(gTargetList);
    fn_800227F8(gBattleMap, M2C_FIELD(M2C_FIELD(obj.unit, void **, 0x194), s32 *, 0x18C));
    y = *(s8 *)((u8 *)obj.unit + 0x19F);
    x = *(s8 *)((u8 *)obj.unit + 0x19E);
    flags = (u16 *)(gBattleMap + 0x408E) + (x + (y << 6));
    if (*flags & 8) {
        ((Visitor *)&obj)->visit(x, y - 1);
    }
    if (*flags & 2) {
        ((Visitor *)&obj)->visit(x + 1, y);
    }
    if (*flags & 4) {
        ((Visitor *)&obj)->visit(x, y + 1);
    }
    if (*flags & 1) {
        ((Visitor *)&obj)->visit(x - 1, y);
    }
}

#pragma cplusplus on
extern "C" void fn_8002B89C(void *arg0, void *arg1) {
    extern u8 lbl_80284D00[];
    extern u8 lbl_80284E20[];
    extern u8 gTargetList[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    struct Visitor {
        virtual void apply(void *unit) = 0;
    };
    struct {
        void *vtbl;
        void *arg;
    } obj;
    s8 y;
    s8 x;
    u16 *flags;
    unsigned yOff;
    void *unit;
    u8 id;
    u16 f;

    (void)arg1;
    obj.vtbl = lbl_80284E20;
    obj.vtbl = lbl_80284D00;
    obj.arg = arg0;
    fn_8002F728(gTargetList);
    x = (s8)*((u8 *)arg0 + 0x19E);
    y = (s8)*((u8 *)arg0 + 0x19F);
    if ((gBattleMap + x)[((unsigned)y << 6) + 0x100D] != 0x16) {
        x = (s8)*((u8 *)obj.arg + 0x19E);
        y = (s8)*((u8 *)obj.arg + 0x19F);
        yOff = y << 6;
        flags = (u16 *)(gBattleMap + ((x + (s32)yOff) << 1));
        f = *(u16 *)((u8 *)flags + 0x408E);
        flags = (u16 *)((u8 *)flags + 0x408E);
        if ((f & 8) != 0) {
            id = gBattleMap[x + ((s8)(y - 1) << 6) + 0xD];
            if (id) {
                unit = gUnits + (id - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (unit) {
                ((Visitor *)&obj)->apply(unit);
            }
        }
        if ((*flags & 2) != 0) {
            id = gBattleMap[(s8)(x + 1) + (s32)yOff + 0xD];
            if (id) {
                unit = gUnits + (id - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (unit != 0) {
                ((Visitor *)&obj)->apply(unit);
            }
        }
        if ((*flags & 4) != 0) {
            id = gBattleMap[x + ((s8)(y + 1) << 6) + 0xD];
            if (id != 0) {
                unit = gUnits + (id - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (unit != 0) {
                ((Visitor *)&obj)->apply(unit);
            }
        }
        if ((*flags & 1) != 0) {
            id = gBattleMap[(s8)(x - 1) + (s32)yOff + 0xD];
            if (id) {
                unit = gUnits + (id - 1) * 0x280;
            } else {
                unit = 0;
            }
            if ((unsigned)unit != 0) {
                ((Visitor *)&obj)->apply(unit);
            }
        }
    }
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_8002BAFC(void *arg0, s32 arg1) {
    extern u8 lbl_80284E20[];
    extern u8 lbl_80284CF0[];
    extern u8 gTargetList[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    struct Visitor {
        virtual void apply(void *unit) = 0;
    };
    struct {
        void *vtbl;
        void *arg;
        s32 val;
    } obj;
    s8 y;
    s8 x;

    obj.vtbl = lbl_80284E20;
    obj.vtbl = lbl_80284CF0;
    obj.arg = arg0;
    obj.val = arg1;
    fn_8002F728(gTargetList);
    y = (s8)*((u8 *)arg0 + 0x19F);
    x = (s8)*((u8 *)arg0 + 0x19E);
    if ((gBattleMap + x)[((unsigned)y << 6) + 0x100D] != 0x16) {
        s32 flags;
        unsigned yOff;
        void *unit;
        u8 id;
        u16 f;
        u8 *row;
        yOff = (unsigned)y << 6;
        row = gBattleMap + x;
        flags = (s32)(gBattleMap + ((x + (s32)yOff) << 1));
        f = *(u16 *)(flags + 0x408E);
        {
            s32 bumped = flags + 0x408E;
            flags = bumped;
        }
        if ((f & 8) != 0) {
            id = row[((s8)(y - 1) << 6) + 0xD];
            if (id != 0) {
                unit = gUnits + (id - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (unit != 0) {
                ((Visitor *)&obj)->apply(unit);
            }
        }
        if ((*(u16 *)flags & 2) != 0) {
            id = gBattleMap[(s8)(x + 1) + (s32)yOff + 0xD];
            if (id != 0) {
                unit = gUnits + (id - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (unit != 0) {
                ((Visitor *)&obj)->apply(unit);
            }
        }
        if ((*(u16 *)flags & 4) != 0) {
            id = gBattleMap[x + ((s8)(y + 1) << 6) + 0xD];
            if (id != 0) {
                unit = gUnits + (id - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (unit != 0) {
                ((Visitor *)&obj)->apply(unit);
            }
        }
        if ((*(u16 *)flags & 1) != 0) {
            id = gBattleMap[(s8)(x - 1) + (s32)yOff + 0xD];
            if (id != 0) {
                unit = gUnits + (id - 1) * 0x280;
            } else {
                unit = 0;
            }
            if (unit != 0) {
                ((Visitor *)&obj)->apply(unit);
            }
        }
    }
}

extern "C" void MapObj_BuildAttackTargetList(void *arg0, void *arg1)
{
    extern u8 gMapObjEventList[];
    extern u8 lbl_80284E20[];
    extern u8 lbl_80284CE0[];
    extern u8 lbl_80284CD0[];
    extern u8 gTargetList[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];

    void *MapObjEvent_Find(void *, s32, s32, s32);
    void fn_8002F728(void *);
    void Map_SelectRangeBuffer(void *, s32);
    void *Item_Get(s32);
    s32 Item_GetMaxRange(void *);
    void Map_FillAttackRange(void *, s32, s32, s32, s32);
    void Map_ClipRangeByFacing(void *, s32, s32, s32);

    u8 *source;
    u8 *unit;
    u8 *base;
    u8 *row;
    u8 *cell;
    u8 *table;
    u8 *entry;
    u8 *data;
    s32 threshold;
    s32 result;
    s32 rowIndex;
    s32 columnIndex;
    s32 rowOffset;
    s32 columnOffset;
    s32 count;
    void *localObject[2];
#pragma cplusplus on
struct Visitor { virtual void apply(void *)=0; };
u8 minRange,py,px;
u8 id;
    void *vtable;

    source = (u8 *)arg1;

    if (source == 0) {
        source = (u8 *)MapObjEvent_Find(
            gMapObjEventList,
            *((u8 *)arg0 + 0x19E),
            *((u8 *)arg0 + 0x19F),
            7
        );

        if (source == 0) {
            fn_8002F728(gTargetList);
            return;
        }
    }

    localObject[0] = lbl_80284E20;
    localObject[1] = arg0;
    localObject[0] = lbl_80284CE0;
    localObject[0] = lbl_80284CD0;

    fn_8002F728(gTargetList);
    Map_SelectRangeBuffer(gBattleMap, 6);

    unit = (u8 *)Item_Get(source[4]);

    py=source[1]; minRange=unit[0x1D]; px=source[0];
result = Item_GetMaxRange(unit);

    Map_FillAttackRange(
        gBattleMap,
        px,
        py,
        minRange,
        result
    );

    Map_ClipRangeByFacing(
        gBattleMap,
        source[0],
        source[1],
        source[3]
    );

    base = gBattleMap;
    threshold = (s8)unit[0x1D];

    rowIndex = 0;
    rowOffset = 0;
    row = base;

    table = base + 0x10000;

    while ((s8)rowIndex < *(s32 *)(base + 4)) {
        count = rowOffset;
        columnIndex = 0;
        
        cell = row;

        while ((s8)columnIndex < *(s32 *)base) {
            columnOffset=count*2;
            if (*(s16 *)(*(u8 **)(table+0x4190) + columnOffset) >= threshold) {
                id = cell[0xD];

                if (id != 0) {
                    if (id != 0) {
entry = gUnits + (id - 1) * 0x280;
} else { entry = 0; }

                    ((Visitor *)localObject)->apply(entry);
                }
            }

            count++;
            
            cell++;
            columnIndex++;
        }

        rowOffset += 0x40;
        row += 0x40;
        rowIndex++;
    }
#pragma cplusplus reset
}

extern "C" void fn_8002BEFC(void *arg0, void *arg1) {
#pragma cplusplus on
#pragma opt_propagation off
    extern u8 lbl_80284E20[], lbl_80284CE0[], lbl_80284CC0[], gTargetList[], gBattleMap[];
    void fn_8002F728(void *);
    void Map_SelectRangeBuffer(void *, s32);
    s32 Item_GetMaxRange(void *);
    void Map_FillAttackRange(void *, s32, s32, s32, s32);
    struct Visitor { virtual void v0(s32, s32) = 0; virtual void visit(s32, s32) = 0; };
    struct { void *vtable; void *unit; s32 range; } visitor;
    s32 x;
    s32 y;
    s32 index;
    u8 *map;
    s32 rowOffset;
    u8 *p;
    s32 threshold;
    s32 r;

    visitor.vtable = lbl_80284E20;
    visitor.vtable = lbl_80284CE0;
    visitor.unit = arg0;
    visitor.vtable = lbl_80284CC0;
    fn_8002F728(gTargetList);
    Map_SelectRangeBuffer(gBattleMap, 6);
    p = (u8 *)arg1;
    y = p[0x1D];
    x = ((u8 *)visitor.unit)[0x19F];
    map = (u8 *)(u32)((u8 *)visitor.unit)[0x19E];
    Map_FillAttackRange(gBattleMap, (s32)map, x, y, Item_GetMaxRange(arg1));
    map = gBattleMap;
    r = p[0x1D];
    y = 0;
    visitor.range = r;
    rowOffset = y;
    p = map + 0x10000;
    threshold = (s8)r;
    while ((s8)y < *(s32 *)(map + 4)) {
        index = rowOffset;
        x = 0;
        while ((s8)x < *(s32 *)map) {
            if (*(s16 *)((u8 *)*(void **)(p + 0x4190) + index * 2) >= threshold) {
                ((Visitor *)&visitor)->visit(x, y);
            }
            index++;
            x++;
        }
        rowOffset += 0x40;
        y++;
    }
#pragma opt_propagation reset
#pragma cplusplus reset
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
#pragma peephole off
extern "C" void fn_8002C034(void *arg0, void *arg1) {
#pragma optimization_level 1
    extern u8 lbl_80284E20[], lbl_80284CE0[], gTargetList[], gBattleMap[], gUnits[];
    void fn_8002F728(void *);
    void Map_SelectRangeBuffer(void *, s32);
    s32 Item_GetMaxRange(void *);
    void Map_FillAttackRange(void *, s32, s32, s32, s32);
    struct Visitor { virtual void apply(void *)=0; };
    struct { void *vtable; void *unit; s32 range; } visitor;
    s32 colIndex;
    s32 rowIndex;
    s32 bufferOffset;
    u8 *cell;
    s32 rowOffset;
    u8 *row;
    u8 *rangeBase;
    u8 *map;
    s32 threshold;
    u8 *item;
    u8 range;
    u8 y;
    u8 x;
    u8 id;
    void *target;

    visitor.vtable=lbl_80284E20;
    visitor.unit=arg0;
    visitor.vtable=lbl_80284CE0;
    fn_8002F728(gTargetList);
    Map_SelectRangeBuffer(gBattleMap,6);
    item=(u8 *)arg1;
    range=item[0x1D];
    y=((u8 *)visitor.unit)[0x19F];
    x=((u8 *)visitor.unit)[0x19E];
    Map_FillAttackRange(gBattleMap,x,y,range,Item_GetMaxRange(arg1));
    map=gBattleMap;
    rowIndex=0;
    visitor.range=item[0x1D];
    rowOffset=rowIndex;
    row=map;
    rangeBase=map+0x10000;
    threshold=(s8)visitor.range;
    while((s8)rowIndex<*(s32 *)(map+4)) {
        bufferOffset=rowOffset;
        cell=row;
        colIndex=0;
        while((s8)colIndex<*(s32 *)map) {
            if(*(s16 *)((u8 *)*(void **)(rangeBase+0x4190)+bufferOffset*2)>=threshold) {
                id=cell[0xD];
                if(id!=0) {
                    if(id!=0) target=gUnits+(id-1)*0x280;
                    else target=0;
                    ((Visitor *)&visitor)->apply(target);
                }
            }
            bufferOffset++;
            cell++;
            colIndex++;
        }
        rowOffset+=0x40;
        row+=0x40;
        rowIndex++;
    }
#pragma optimization_level reset
#pragma peephole reset
#pragma global_optimizer reset
#pragma cplusplus reset
}
extern "C" void fn_8002C194(void *arg0, s8 arg1) {
    extern u8 lbl_80284E20[];
    extern u8 lbl_80284CB0[];
    extern u8 gTargetList[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    struct Visitor {
        virtual void apply(void *unit) = 0;
    };
    struct {
        void *vtbl;
        void *arg;
        s8 flag;
    } obj;
    u16 *flags;
    s8 x;
    s8 y;
    void *unit;
    u8 id;
    u16 f;

    obj.vtbl = lbl_80284E20;
    obj.vtbl = lbl_80284CB0;
    obj.arg = arg0;
    obj.flag = arg1;
    fn_8002F728(gTargetList);
    y = *(s8 *)((u8 *)arg0 + 0x19F);
    x = *(s8 *)((u8 *)arg0 + 0x19E);
    flags = (u16 *)(gBattleMap + ((x + (y << 6)) << 1));
    f = *(u16 *)((u8 *)flags + 0x408E);
    flags = (u16 *)((u8 *)flags + 0x408E);
    if ((f & 8) != 0) {
        id = gBattleMap[x + ((s8)(y - 1) << 6) + 0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 2) != 0) {
        id = gBattleMap[(s8)(x + 1) + (y << 6) + 0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 4) != 0) {
        id = gBattleMap[x + ((s8)(y + 1) << 6) + 0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*flags & 1) != 0) {
        id = gBattleMap[(s8)(x - 1) + (y << 6) + 0xD];
        if (id != 0) {
            unit = gUnits + (id - 1) * 0x280;
        } else {
            unit = 0;
        }
        if (unit != 0) {
            ((Visitor *)&obj)->apply(unit);
        }
    }
    if ((*(u32 *)((u8 *)arg0 + 0x1A0) & 2) != 0) {
        ((Visitor *)&obj)->apply(*(void **)((u8 *)arg0 + 0x194));
    }
}

extern "C" void fn_8002C3D8(void *arg0, void *arg1) {
    struct Visitor {
        virtual void apply(void *unit) = 0;
    };
    u8 fn_80093088(void *);
    void fn_8002F6E8(void *, u8, u8, u8, s32);
    extern u8 gTargetList[];
    void *child;

    u32 side;

    child = *(void **)((u8 *)arg0 + 4);
    side = *(u32 *)((u8 *)child + 0x190);
    if (*(u32 *)((u8 *)arg1 + 0x190) == side) {
        if (fn_80093088(child) == 0 || fn_80093088(arg1) == 0) {
            fn_8002F6E8(
                gTargetList,
                *(u8 *)((u8 *)arg1 + 0x19E),
                *(u8 *)((u8 *)arg1 + 0x19F),
                *(u8 *)((u8 *)arg1 + 0x198),
                0
            );
        }
    }

    if ((*(u32 *)((u8 *)arg1 + 0x1A0) & 2) != 0) {
        ((Visitor *)arg0)->apply(*(void **)((u8 *)arg1 + 0x194));
    }
}

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma use_lmw_stmw on
#pragma cplusplus on
extern "C" void fn_8002C47C(void *arg0, s32 arg1) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1(s32, s32) = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
    };
    extern u8 gBattleMap[];
    void *self;
    s32 x;
    s32 y;
    s8 thresh;
    u8 *map2;
    s32 row;
    s32 scratch;
    u8 *map;
    s16 *arr;

    map = gBattleMap;
    self = arg0;
    thresh = (s8)arg1;
    map2 = map + 0x10000;
    y = 0;
    row = 0;
    while ((s8)y < *(s32 *)(map + 4)) {
        scratch = row;
        x = 0;
        while ((s8)x < *(s32 *)map) {
            arr = *(s16 **)(map2 + 0x4190);
            if (arr[scratch] >= thresh) {
                ((Obj *)self)->v1(x, y);
            }
            scratch++;
            x++;
        }
        row += 0x40;
        y++;
    }
}
#pragma optimization_level 3
extern "C" void fn_8002C530(void *arg0, s32 arg1) {
    struct Obj {
        virtual void apply(void *) = 0;
        virtual void v1() = 0;
    };
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    void *self;
    s32 x;
    s32 y;
    s8 thresh;
    u8 *map2;
    s32 row;
    s32 scratch;
    u8 *map;
    u8 *maprow;
    u8 *cell;
    s16 *arr;
    u8 id;
    void *unit;

    map = gBattleMap;
    self = arg0;
    thresh = (s8)arg1;
    maprow = map;
    y = 0;
    map2 = map + 0x10000;
    row = 0;
    while ((s8)y < *(s32 *)(map + 4)) {
        scratch = row;
        cell = maprow;
        x = 0;
        while ((s8)x < *(s32 *)map) {
            arr = *(s16 **)(map2 + 0x4190);
            if (arr[scratch] >= thresh) {
                id = cell[0xD];
                if (id != 0) {
                    if (id != 0) {
                        unit = gUnits + (id - 1) * 0x280;
                    } else {
                        unit = 0;
                    }
                    ((Obj *)self)->apply(unit);
                }
            }
            scratch += 1;
            cell += 1;
            x += 1;
        }
        row += 0x40;
        maprow += 0x40;
        y += 1;
    }
}
#pragma optimization_level reset
extern "C" void fn_8002C618(void *arg0, s8 arg1, s8 arg2) {
    extern s32 gBattleMap[];
    struct Visitor {
        virtual void v0(s8, s8) = 0;
        virtual void visit(s8, s8) = 0;
    };
    s8 x;
    s8 y;

    x = arg1;
    y = arg2;

    if (y - 1 >= 0) {
        ((Visitor *)arg0)->visit(x, (s8)(y - 1));
    }
    if (x + 1 < gBattleMap[0]) {
        ((Visitor *)arg0)->visit((s8)(x + 1), y);
    }
    if (y + 1 < gBattleMap[1]) {
        ((Visitor *)arg0)->visit(x, (s8)(y + 1));
    }
    if (x - 1 >= 0) {
        ((Visitor *)arg0)->visit((s8)(x - 1), y);
    }
}

extern "C" void fn_8002C6F4(void *obj,s32 arg1,s32 arg2) {
extern u8 gBattleMap[],gUnits[];
#pragma cplusplus on
struct Visitor { virtual void apply(void *)=0; };
s32 x=(s8)arg1;
s32 y=(s8)arg2;
u16 *flags=(u16 *)(gBattleMap+((x+(y<<6))<<1));
u16 f=*(u16 *)((u8 *)flags+0x408e);
void *unit;
u8 id;
flags += 0x2047;

if ((f&8)!=0) {
id=gBattleMap[x+((s8)(y-1)<<6)+0xd];
if(id) unit=gUnits+(id-1)*0x280; else unit=0;
if(unit) ((Visitor *)obj)->apply(unit);
}

if ((*flags&2)!=0) {
id=gBattleMap[(s8)(x+1)+(y<<6)+0xd];
if(id) unit=gUnits+(id-1)*0x280; else unit=0;
if(unit) ((Visitor *)obj)->apply(unit);
}

if ((*flags&4)!=0) {
id=gBattleMap[x+((s8)(y+1)<<6)+0xd];
if(id) unit=gUnits+(id-1)*0x280; else unit=0;
if(unit) ((Visitor *)obj)->apply(unit);
}

if ((*flags&1)!=0) {
id=gBattleMap[(s8)(x-1)+(y<<6)+0xd];
if(id) unit=gUnits+(id-1)*0x280; else unit=0;
if(unit) ((Visitor *)obj)->apply(unit);
}
#pragma cplusplus reset
}

#pragma use_lmw_stmw reset
#pragma cplusplus reset

void fn_8002C8E0(void) {
    void *MapObjEvent_Find(void *, s8, s8, u8);
    void fn_8002F6E8(void *, u8, u8, s32, s32);
    extern u8 gMapObjEventList[];
    extern u8 gTargetList[];
    void *ptr;
    s8 x;
    s8 y;

    ptr = MapObjEvent_Find(gMapObjEventList, x, y, 4);
    if (ptr != NULL) {
        if (*(u8 *)((char *)ptr + 4) != 0) {
            fn_8002F6E8(gTargetList, *(u8 *)ptr, *(u8 *)((char *)ptr + 1), 0, 4);
        }
    }
}

void fn_8002C940(void *arg0, void *arg1) {
    u8 Allegiance_Compare(s32, s32);
    void fn_8002F6E8(void *, u8, u8, u8, u8);
    extern u8 gTargetList[];
    if (Allegiance_Compare(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x190), M2C_FIELD(arg1, s32 *, 0x190)) == 1) {
        fn_8002F6E8(gTargetList, M2C_FIELD(arg1, u8 *, 0x19E), M2C_FIELD(arg1, u8 *, 0x19F), M2C_FIELD(arg1, u8 *, 0x198), 0);
    }
}

void fn_8002C9A0(void *arg0, void *arg1)
{
    extern u8 gBattleMap[];
    extern u8 gTargetList[];

    s32 fn_8003DD20(void *);
    s32 fn_800227F8(s32, s32);
    s32 fn_8002134C(void *);
    s32 fn_8001F85C(void *, s32, s32, s32, s32);
    void fn_8002F6E8(void *, s32, s32, s32, s32);

    u8 *obj;
    u8 *unit;
    u8 *other;
    u8 *base;
    u8 *occupancy;
    u8 *terrain;
    s32 x;
    s32 y;
    s32 dx;
    s32 dy;
    s32 nextX;
    s32 nextY;
    s32 secondX;
    s32 secondY;
    s32 index;
    s32 value;

    obj = (u8 *)arg0;
    unit = (u8 *)arg1;
    base = gBattleMap;

    if ((u8)fn_8003DD20(*(void **)(obj + 4)) == 0) {
        return;
    }

    x = unit[0x19E];
    y = unit[0x19F];

    if (base[(s8)x + ((s8)y << 6) + 0x100D] == 0x16) {
        return;
    }

    other = *(u8 **)(obj + 4);

    dx = (s8)(x - other[0x19E]);
    dy = (s8)(y - other[0x19F]);

    value = fn_800227F8(
        fn_8003DD20(*(void **)(obj + 4)),
        *(s32 *)(unit + 0x18C)
    );

    nextX = (s8)((s8)x + dx);
    nextY = (s8)((s8)y + dy);

    occupancy = base + 0xD;
    terrain = base + 0x300D;

    index = (s8)nextX + ((s8)nextY << 6);

    if (occupancy[index] != 0) {
        return;
    }

    if (terrain[index] != 0) {
        return;
    }

    if ((s16)fn_8002134C((void *)value) > 0x7530) {
        return;
    }

    if ((u8)fn_8001F85C(
            base,
            x,
            y,
            (s8)nextX,
            (s8)nextY
        ) == 0) {
        return;
    }

    if (*(s32 *)(obj + 8) == 2) {
        secondX = (s8)(nextX + dx);
        secondY = (s8)(nextY + dy);

        index = (s8)secondX + ((s8)secondY << 6);

        if (occupancy[index] != 0) {
            return;
        }

        if (terrain[index] != 0) {
            return;
        }

        if ((s16)fn_8002134C(base) > 0x7530) {
            return;
        }

        if ((u8)fn_8001F85C(
                base,
                nextX,
                nextY,
                (s8)secondX,
                (s8)secondY
            ) == 0) {
            return;
        }
    }

    fn_8002F6E8(
        gTargetList,
        unit[0x19E],
        unit[0x19F],
        unit[0x198],
        0
    );
}

void fn_8002CB50(void *arg0, void *arg1) {
    u8 Allegiance_Compare(s32, s32);
    void fn_8002F6E8(void *, u8, u8, u8, u8);
    u8 fn_8003DD7C(void *, void *);
    extern u8 gTargetList[];
    if ((Allegiance_Compare(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x190), M2C_FIELD(arg1, s32 *, 0x190)) != 1) && (fn_8003DD7C(M2C_FIELD(arg0, void **, 4), arg1) != 0) && !(M2C_FIELD(arg1, s32 *, 0x1A0) & 6)) {
        fn_8002F6E8(gTargetList, M2C_FIELD(arg1, u8 *, 0x19E), M2C_FIELD(arg1, u8 *, 0x19F), M2C_FIELD(arg1, u8 *, 0x198), 0);
    }
}

#pragma opt_strength_reduction off
void fn_8002CBDC(void *unused, s32 x, s32 y)
{
    extern u8 lbl_802CA518[];
    extern u8 lbl_802EF4E0[];
    extern s16 fn_8002134C(void *);
    extern void fn_8002F6E8(void *, s32, s32, s32, s32);

    u8 *base;
    s32 r31;
    s32 r30;

    base = lbl_802CA518;
    r31 = y;
    r30 = x;
    if (base[(s8)r30 + ((s8)r31 << 6) + 0xD] == 0) {
        if (fn_8002134C(base) <= 0x7530) {
            fn_8002F6E8(lbl_802EF4E0, r30, r31, 0, 0);
        }
    }
}
#pragma opt_strength_reduction reset
void fn_8002CC64(void *arg0, void *arg1) {
    void fn_8002F6E8(void *, u8, u8, u8, u8);
    u8 fn_8003DD7C(void *, s32);
    extern u8 gTargetList[];
    void *inner;

    inner = *(void **)((u8 *)arg0 + 4);
    if (*(u32 *)((u8 *)inner + 0x190) == *(u32 *)((u8 *)arg1 + 0x190)
        && (*(u32 *)((u8 *)arg1 + 0x1A0) & 6) == 0
        && fn_8003DD7C(arg1, *(s32 *)((u8 *)inner + 0x194)) != 0) {
        fn_8002F6E8(
            gTargetList,
            *(u8 *)((u8 *)arg1 + 0x19E),
            *(u8 *)((u8 *)arg1 + 0x19F),
            *(u8 *)((u8 *)arg1 + 0x198),
            *(u8 *)((u8 *)*(void **)((u8 *)*(void **)((u8 *)arg0 + 4) + 0x194) + 0x198));
    }
}

void fn_8002CCF0(void *arg0, void *arg1) {
    void fn_8002F6E8(void *, u8, u8, u8, u8);
    u8 fn_8003DD7C(void *, void *);
    extern u8 gTargetList[];
    void *inner;
    u32 flags;

    inner = *(void **)((u8 *)arg0 + 4);
    if (*(u32 *)((u8 *)inner + 0x190) == *(u32 *)((u8 *)arg1 + 0x190)) {
        flags = *(u32 *)((u8 *)arg1 + 0x1A0);
        if ((flags & 2) && !(flags & 0x100000)
            && fn_8003DD7C(inner, *(void **)((u8 *)arg1 + 0x194)) != 0) {
            fn_8002F6E8(gTargetList,
                *(u8 *)((u8 *)arg1 + 0x19E),
                *(u8 *)((u8 *)arg1 + 0x19F),
                *(u8 *)((u8 *)arg1 + 0x198),
                *(u8 *)((u8 *)*(void **)((u8 *)arg1 + 0x194) + 0x198));
        }
    }
}

void fn_8002CD70(void *arg0, void *arg1) {
    u8 fn_800BF1E8(void *);
    void fn_8002F6E8(void *, u8, u8, u8, u8);
    extern u8 gUiContext[];
    extern u8 gTargetList[];

    *(void **)(gUiContext + 4) = arg1;
    if (fn_800BF1E8(gUiContext) != 0) {
        fn_8002F6E8(gTargetList, *(u8 *)((u8 *)arg1 + 0x19E), *(u8 *)((u8 *)arg1 + 0x19F), *(u8 *)((u8 *)arg1 + 0x198), 0);
    }
}

void fn_8002CDCC(void *arg0, void *arg1)
{
    u8 Allegiance_Compare(s32, s32);
    void fn_8002F6E8(void *, u8, u8, u8, u8);
    u8 fn_8003DC80(void *, void *);
    u8 fn_80093088(void *);
    extern u8 gTargetList[];

    if (Allegiance_Compare(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x190), M2C_FIELD(arg1, s32 *, 0x190)) != 1) {
        return;
    }
    if (fn_8003DC80(M2C_FIELD(arg0, void **, 4), arg1) == 0) {
        return;
    }
    if (fn_80093088(arg1) != 0) {
        return;
    }
    fn_8002F6E8(gTargetList, M2C_FIELD(arg1, u8 *, 0x19E), M2C_FIELD(arg1, u8 *, 0x19F), M2C_FIELD(arg1, u8 *, 0x198), 0);
}

void fn_8002CE5C(void *arg0, void *arg1) {
    u8 Allegiance_Compare(s32, s32);
    void fn_8002F6E8(void *, u8, u8, u8, u8);
    s8 Unit_GetMaxHp(void *);
    extern u8 gTargetList[];
    u8 temp_r31;
    void *inner;

    inner = *(void **)((u8 *)arg0 + 4);
    if (Allegiance_Compare(*(s32 *)((u8 *)inner + 0x190), *(s32 *)((u8 *)arg1 + 0x190)) != 1) {
        temp_r31 = *(u8 *)((u8 *)arg1 + 0x1A8);
        if ((s8)temp_r31 != Unit_GetMaxHp(arg1)) {
            fn_8002F6E8(
                gTargetList,
                *(u8 *)((u8 *)arg1 + 0x19E),
                *(u8 *)((u8 *)arg1 + 0x19F),
                *(u8 *)((u8 *)arg1 + 0x198),
                0);
        }
    }
}

void fn_8002CEE0(void *arg0, void *arg1) {
    u8 Allegiance_Compare(s32, s32);
    u8 fn_801044FC(void *);
    void fn_8002F6E8(void *, u8, u8, u8, u8);
    extern u8 gTargetList[];

    if (Allegiance_Compare(*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 4) + 0x190), *(s32 *)((u8 *)arg1 + 0x190)) != 1) {
        if (fn_801044FC((u8 *)arg1 + 0x1A4) != 0) {
            fn_8002F6E8(gTargetList, *(u8 *)((u8 *)arg1 + 0x19E), *(u8 *)((u8 *)arg1 + 0x19F), *(u8 *)((u8 *)arg1 + 0x198), 0);
        }
    }
}

void fn_8002CF50(void *arg0, void *arg1) {
    u8 Allegiance_Compare(s32, s32);
    void fn_8002F6E8(void *, u8, u8, u8, u8);
    extern u8 gTargetList[];
    if (Allegiance_Compare(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x190), M2C_FIELD(arg1, s32 *, 0x190)) == 1) {
        fn_8002F6E8(gTargetList, M2C_FIELD(arg1, u8 *, 0x19E), M2C_FIELD(arg1, u8 *, 0x19F), M2C_FIELD(arg1, u8 *, 0x198), 0);
    }
}

void fn_8002CFB0(void *arg0, void *arg1) {
    u8 Allegiance_Compare(s32, s32);
    void fn_8002F6E8(void *, u8, u8, u8, int);
    int Unit_CalcHitRate(void *, void *);
    extern u8 gTargetList[];
    void *self;
    void *other;
    u8 v198;
    u8 v19f;
    u8 v19e;

    self = arg0;
    other = arg1;
    if (Allegiance_Compare(*(s32 *)((u8 *)*(void **)((u8 *)self + 4) + 0x190), *(s32 *)((u8 *)other + 0x190)) != 1) {
        v198 = *(u8 *)((u8 *)other + 0x198);
        v19f = *(u8 *)((u8 *)other + 0x19F);
        v19e = *(u8 *)((u8 *)other + 0x19E);
        fn_8002F6E8(gTargetList, v19e, v19f, v198, Unit_CalcHitRate(*(void **)((u8 *)self + 4), other));
    }
}

void fn_8002D044(void *arg0, s32 arg1, s32 arg2) {
    u8 fn_800BE968(s32, s32, s32);
    void fn_8002F6E8(void *, s32, s32, s32, s32);
    extern u8 gTargetList[];
    u8 flags;

    flags = *(u8 *)((u8 *)arg0 + 4);
    if (flags & 2) {
        if (fn_800BE968(0xB, arg1, arg2) != 0) {
            fn_8002F6E8(gTargetList, arg1, arg2, 0, 2);
        }
    }
    if (*(u8 *)((u8 *)arg0 + 4) & 1) {
        if (fn_800BE968(0xC, arg1, arg2) != 0) {
            fn_8002F6E8(gTargetList, arg1, arg2, 0, 1);
        }
    }
}

void fn_8002D0FC(void *arg0, void *arg1) {
    u8 Allegiance_Compare(s32, s32);
    void fn_8002F6E8(void *, u8, u8, u8, u8);
    extern u8 gTargetList[];
    if (Allegiance_Compare(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x190), M2C_FIELD(arg1, s32 *, 0x190)) != 1) {
        fn_8002F6E8(gTargetList, M2C_FIELD(arg1, u8 *, 0x19E), M2C_FIELD(arg1, u8 *, 0x19F), M2C_FIELD(arg1, u8 *, 0x198), 0);
    }
}

void fn_8002D15C(void *arg0, void *arg1) {
    u8 Allegiance_Compare(s32, s32);
    void Unit_GetHeldItemSlot(void *, s32);
    u8 fn_8001C0C8(void);
    void fn_8002F6E8(void *, u8, u8, u8, u8);
    extern u8 gTargetList[];
    s32 i;

    if (Allegiance_Compare(*(s32 *)((char *)*(void **)((char *)arg0 + 4) + 0x190), *(s32 *)((char *)arg1 + 0x190)) == 1) {
        return;
    }
    i = 0;
    do {
        Unit_GetHeldItemSlot(arg1, i);
        if (fn_8001C0C8() != 0) {
            fn_8002F6E8(gTargetList, *(u8 *)((char *)arg1 + 0x19E), *(u8 *)((char *)arg1 + 0x19F), *(u8 *)((char *)arg1 + 0x198), i);
            return;
        }
        i++;
    } while (i < 4);
}

void fn_8002D1F0(void *arg0, void *arg1) {
    u8 Allegiance_Compare(s32, s32);
    void fn_8002F6E8(void *, u8, u8, u8, u8);
    extern u8 gTargetList[];

    if (Allegiance_Compare(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x190), M2C_FIELD(arg1, s32 *, 0x190)) == 0) {
        fn_8002F6E8(gTargetList, M2C_FIELD(arg1, u8 *, 0x19E), M2C_FIELD(arg1, u8 *, 0x19F), M2C_FIELD(arg1, u8 *, 0x198), 0);
    }
}

void fn_8002D24C(void *arg0, void *arg1) {
    u8 Allegiance_Compare(s32, s32);
    void fn_8002F6E8(void *, u8, u8, u8, u8);
    extern u8 gTargetList[];

    if (Allegiance_Compare(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x190), M2C_FIELD(arg1, s32 *, 0x190)) == 0
        && (M2C_FIELD(arg1, u32 *, 0x1A0) & 1)) {
        fn_8002F6E8(gTargetList, M2C_FIELD(arg1, u8 *, 0x19E), M2C_FIELD(arg1, u8 *, 0x19F), M2C_FIELD(arg1, u8 *, 0x198), 0);
    }
}

#pragma global_optimizer off
void fn_8002D2B4(void *arg0, void *arg1) {
    u8 Allegiance_Compare(s32, s32);
    u8 Status_Test(void *, s32);
    void fn_8002F6E8(void *, u8, u8, u8, u8);
    extern u8 gTargetList[];

    if (Allegiance_Compare(*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 4) + 0x190), *(s32 *)((u8 *)arg1 + 0x190)) != 1)
        return;
    if (Status_Test((u8 *)arg1 + 0x1bc, 6) != 0)
        return;
    if (Status_Test((u8 *)arg1 + 0x1bc, 7) != 0)
        return;
    fn_8002F6E8(gTargetList, *(u8 *)((u8 *)arg1 + 0x19e), *(u8 *)((u8 *)arg1 + 0x19f), *(u8 *)((u8 *)arg1 + 0x198), 0);
}
#pragma global_optimizer on
void fn_8002D33C(void *arg0, s8 arg1, s8 arg2) {
    extern u8 gBattleMap[];
    extern u8 gTargetList[];
    void fn_8002F6E8(void *, s8, s8, u8, s32);
    u8 temp;
    temp = gBattleMap[arg1 + (arg2 << 6) + 0xD];
    if (((u32)(-(s32)temp | temp) >> 31) != 0) {
        fn_8002F6E8(gTargetList, arg1, arg2, temp, 2);
    }
}

void fn_8002D398(void) {

}

void fn_8002D39C(void) {

}

#pragma optimization_level 3
void fn_8002D3A0(void *arg0) {
    void Event_StartByName(void *, void *);
    extern u8 gBattleState[];
    extern u8 Battle_str[];
    void *str;

    str = arg0;
    switch (gBattleState[0x54]) {
    case 5:
        str = Battle_str + 0x148;
        break;
    case 6:
        str = Battle_str + 0x154;
        break;
    case 7:
        str = Battle_str + 0x160;
        break;
    }
    Event_StartByName(str, arg0);
}
#pragma optimization_level reset
void fn_8002D420(s32 arg0) {
    void fn_8014C718(void *, s32);
    extern u8 gBattleState[16];
    fn_8014C718(gBattleState, arg0);
}

void fn_8002D44C(void) {
    M2C_UNK fn_800C4B8C();
    fn_800C4B8C();
}

s32 Heap_GetFree(void);
void Heap_Create(void *, s32, void *);
void Heap_Select(void *);
void fn_80016498(void);
void fn_80015D54(void);
void fn_8002D46C(void)
{
    extern u8 Battle_str[];
    s32 tmp;

    tmp = Heap_GetFree();
    Heap_Create(Battle_str + 0x16c, tmp, Battle_str);
    Heap_Select(Battle_str + 0x176);
    fn_80016498();
    fn_80015D54();
}

#pragma global_optimizer off
void fn_8002D4B8(void)
{
    extern u16 Battle_str[];
    u16 FileCache_Probe(void *);
    void fn_8005C7C8(void *);
    void fn_80166228(void);
    void fn_800C4B8C(void);

    if (FileCache_Probe((u8 *)Battle_str + 0x17F) != 0x8000) {
        fn_8005C7C8((u8 *)Battle_str + 0x17F);
    }
    if (FileCache_Probe((u8 *)Battle_str + 0x198) != 0x8000) {
        fn_8005C7C8((u8 *)Battle_str + 0x198);
    }
    fn_80166228();
    fn_8005C7C8((u8 *)Battle_str + 0x1AF);
    fn_800C4B8C();
    fn_800C4B8C();
}
#pragma global_optimizer off
void Battle_LoadMap(void)
{
    extern u8 Battle_str[];
    extern u8 gBattleState[];
    void Heap_Create(void *, s32);
    void Chapter_LoadScript(s32);
    u16 FileCache_Probe(void *);
    void Archive_LoadFlags(void *, s32);
    void Archive_Load(void *);
    void FileCache_Load(void *);
    void Map_InitGfx(void);
    s32 Heap_GetFree(void);
    void Heap_Select(void *);
    void fn_80016498(void);
    void fn_80015D54(void);
    void Camera_InitSlots(void);
    void DebugPrint(char *, ...);

    /* Enter a battle map: create heaps, load chapter script and archives, init gfx/units/cameras. */
    Heap_Create(Battle_str + 0x176, 0x180000);
    Chapter_LoadScript(gBattleState[0x10]);
    if (FileCache_Probe(Battle_str + 0x198) != 0x8000) {
        Archive_LoadFlags(Battle_str + 0x198, 8);
    }
    if (FileCache_Probe(Battle_str + 0x17F) != 0x8000) {
        Archive_Load(Battle_str + 0x17F);
    }
    FileCache_Load(Battle_str + 0x1AF);
    Map_InitGfx();
    Heap_Create(Battle_str + 0x16C, Heap_GetFree());
    Heap_Select(Battle_str + 0x176);
    fn_80016498();
    fn_80015D54();
    Camera_InitSlots();
    DebugPrint((char *)(Battle_str + 0x1BF), Heap_GetFree());
}
#pragma global_optimizer reset
/* Create E_BMapMain (+BGM ctrl), load map and save, then place the camera and refresh units. */
void Battle_StartMapMain(void *parent) {
    extern u16 Proc_BMapMain[];
    extern u16 Proc_BMapBGMCtrl[];
    extern u8 gBattleState[];
    extern struct { u32 unk0; u32 unk4; } gSaveDataBase;
    void *Process_CreateChild(void *, void *);
    void *Process_Create(void *, void *);
    void Process_Goto(void *, s32);
    void Game_SetState(s32);
    void BattleState_LoadMap(void *, void *);
    void fn_801E379C(u32);
    void SaveData_Release(void *);
    void BattleState_SetCamPos(void *, f32, f32);
    void Camera_SyncFromBattleState(void);
    void fn_8014C798(void *);
    void fn_800163F8(void);
    void fn_80016180(void);
    void *proc;

    proc = Process_CreateChild(Proc_BMapMain, parent);
    Process_Goto(proc, 4);
    Process_Create(Proc_BMapBGMCtrl, proc);
    Game_SetState(0x10);
    BattleState_LoadMap(gBattleState, gBattleState + 0x504);
    fn_801E379C(gSaveDataBase.unk4);
    SaveData_Release(&gSaveDataBase);
    BattleState_SetCamPos(gBattleState, (f32)(s8)gBattleState[0x52], (f32)(s8)gBattleState[0x53]);
    Camera_SyncFromBattleState();
    fn_8014C798(gBattleState);
    fn_800163F8();
    fn_80016180();
    Camera_SyncFromBattleState();
}

void fn_8002D72C(void *arg0) {
    extern u16 Proc_BMapBGMCtrl[];
    extern u16 lbl_80284E5C[];
    extern u16 Proc_BMapMain[];
    void *Process_CreateChild(void *, void *);
    void *Process_Create(void *, void *);
    void Game_SetState(s32);
    void *r;

    r = Process_CreateChild(Proc_BMapMain, arg0);
    r = Process_Create(Proc_BMapBGMCtrl, r);
    r = Process_CreateChild(lbl_80284E5C, r);
    Game_SetState(0x10);
}

extern u16 Proc_BMapMain[216];
void BMapMain_Goto(s32 arg0) {
    void *Process_Find(void *);
    void Process_Goto(void *, u8);

    Process_Goto(Process_Find(Proc_BMapMain), (u8)arg0);
}

void fn_8002D7BC(s32 arg0) {
    void Map_RefreshUnitMap(void *);
    void fn_800C1060(s32);
    extern u8 gBattleMap[];
    extern u8 gMapBlendMode;
    s32 var_r4;
    s32 temp;
    s32 a, b;

    Map_RefreshUnitMap(gBattleMap);
    var_r4 = 1;
    temp = (u8)(gMapBlendMode - 1);
    b = var_r4 | ~temp;
    a = (u32)(1 - temp) >> 1;
    if (((u32)(b - a) >> 31) == 0) {
        var_r4 = 0;
    }
    if ((u8)var_r4 != 0) {
        fn_800C1060(arg0);
    }
}

void fn_8002D82C(void) {
    M2C_UNK fn_80146AF0();
    extern s32 lbl_80367254;
    fn_80146AF0();
    lbl_80367254 = 0;
}

/* Clear the process callback once none of the battle FX name slots are active. */
void Battle_ClearProcIfFxIdle(s32 proc) {
    s8 Fx_FindSlotByName(u8 *);
    void Process_ClearFunc(s32);
    extern u8 Battle_str[];
    u8 fxBusy;

    if ((s8)Fx_FindSlotByName(Battle_str + 0x1E3) != -1
        || (s8)Fx_FindSlotByName(Battle_str + 0x1F1) != -1
        || (s8)Fx_FindSlotByName(Battle_str + 0x1FF) != -1
        || (s8)Fx_FindSlotByName(Battle_str + 0x20D) != -1
        || (s8)Fx_FindSlotByName(Battle_str + 0x21B) != -1
        || (s8)Fx_FindSlotByName(Battle_str + 0x22B) != -1) {
        fxBusy = 1;
    } else {
        fxBusy = 0;
    }
    if (fxBusy == 0) {
        Process_ClearFunc(proc);
    }
}

/* Clear the process function if any of the six named battle FX slots is active. */
void Battle_ClearProcIfFxActive(s32 proc) {
    s8 Fx_FindSlotByName(u8 *);
    void Process_ClearFunc(s32);
    extern u8 Battle_str[];
    u8 active;

    if ((s8)Fx_FindSlotByName(Battle_str + 0x1E3) != -1
        || (s8)Fx_FindSlotByName(Battle_str + 0x1F1) != -1
        || (s8)Fx_FindSlotByName(Battle_str + 0x1FF) != -1
        || (s8)Fx_FindSlotByName(Battle_str + 0x20D) != -1
        || (s8)Fx_FindSlotByName(Battle_str + 0x21B) != -1
        || (s8)Fx_FindSlotByName(Battle_str + 0x22B) != -1) {
        active = 1;
    } else {
        active = 0;
    }
    if (active == 1) {
        Process_ClearFunc(proc);
    }
}

#pragma optimization_level 1
#pragma cplusplus on
extern "C" void fn_8002DA30(void)
{
    void *fn_8014D8FC(void *);
    u8 fn_80146AE4(void);
    void fn_801481CC(void *, s32);
    u32 Process_FindByName(void *);
    s32 fn_80015680(void *);
    void *fn_8014CA54(void *, s32);
    void *fn_80234198(void *, void *);
    u8 EventFlag_IsSet(void *, void *, void *);
    s32 Str_Cmp(s32, void *);
    void fn_80148980(void *, s32);
    void Fx_StartSlot(s32, void *, s32, s32);
    s8 Fx_FindSlotByName(void *);
    s8 fn_80146BE4(void *);
    void Fx_FadeOut(void *, s32);
    void Fx_FadeIn(void *, s32);
    void fn_8014876C(void *, s32, s32);
    extern u8 gBattleState[];
    extern u8 Battle_str[];
    extern s32 lbl_80367254;
    extern s32 lbl_80367250;
    extern u8 gUnitLists[];

    struct Obj {
        void *unk0;
        u8 pad[4];
        virtual u8 v0() = 0;
        u8 flag;
        u8 pad2[0x1F];
        u16 unk2C;
        u16 unk2E;
    };
    extern Obj gFxChannels;

    void *str;
    Obj *obj;
    void *ctx;
    void *base;
    u8 ok;
    s8 idx;
    u8 any;
    s32 slot;
    s32 timer;

    str = 0;
    ctx = fn_8014D8FC(gBattleState);
    if (fn_80146AE4() != 0) {
        fn_801481CC(Battle_str + 0x1E3, 0x190);
        fn_801481CC(Battle_str + 0x1F1, 0x190);
        fn_801481CC(Battle_str + 0x1FF, 0x190);
        fn_801481CC(Battle_str + 0x20D, 0x190);
        fn_801481CC(Battle_str + 0x21B, 0x190);
        fn_801481CC(Battle_str + 0x22B, 0x190);
        return;
    }
    if (Process_FindByName(Battle_str + 0x23B) != 0) {
        timer = 0xA;
        lbl_80367254 = timer;
        str = Battle_str + 0x246;
    } else if ((timer = lbl_80367254) > 0) {
        lbl_80367254 = timer - 1;
        return;
    } else if (fn_80015680(gUnitLists + 0xC) >= 1
        || (slot = *(u8 *)((u8 *)ctx + 0x3C), slot == 1)
        || (slot >= 9 && slot <= 0x1F)
        || slot == 0x33
        || fn_80234198(fn_8014CA54(gBattleState, 0), Battle_str + 0x251) != 0
        || fn_80234198(fn_8014CA54(gBattleState, 1), Battle_str + 0x251) != 0
        || fn_80234198(fn_8014CA54(gBattleState, 0), Battle_str + 0x256) != 0
        || fn_80234198(fn_8014CA54(gBattleState, 1), Battle_str + 0x256) != 0
        || fn_80234198(fn_8014CA54(gBattleState, 0), Battle_str + 0x25B) != 0
        || fn_80234198(fn_8014CA54(gBattleState, 1), Battle_str + 0x25B) != 0) {
        str = *(void **)((u8 *)ctx + 0x10);
    } else {
        str = Battle_str + 0x260;
    }

    base = gBattleState;
    if (EventFlag_IsSet((u8 *)base + 0xB4, Battle_str + 0x26D, base) == 0) {
        ok = 0;
        obj = &gFxChannels;
        if (obj->flag & 1) {
            if (obj->v0()) {
                ok = 1;
            }
        }
        if (ok == 0) {
            lbl_80367250 = 0;
            Fx_StartSlot(0, str, 0x64, 1);
            return;
        }
        if (Str_Cmp(*(s32 *)obj->unk0, str) != 0
            && obj->unk2C > obj->unk2E) {
            fn_80148980(obj, 0x3E8);
            return;
        }
    }

    idx = Fx_FindSlotByName(str);
    if (idx != -1) {
        obj = (Obj *)((u8 *)&gFxChannels + (u8)idx * 0x30);
        if (Fx_FindSlotByName(Battle_str + 0x1E3) != -1
            || Fx_FindSlotByName(Battle_str + 0x1F1) != -1
            || Fx_FindSlotByName(Battle_str + 0x1FF) != -1
            || Fx_FindSlotByName(Battle_str + 0x20D) != -1
            || Fx_FindSlotByName(Battle_str + 0x21B) != -1
            || Fx_FindSlotByName(Battle_str + 0x22B) != -1) {
            any = 1;
        } else {
            any = 0;
        }
        if ((u8)any == 1
            || fn_80146BE4(Battle_str + 0x279) != -1
            || fn_80146BE4(Battle_str + 0x28A) != -1) {
            if (lbl_80367250 == 0) {
                Fx_FadeOut(obj, 0xC8);
                lbl_80367250 = 1;
            }
        } else if (lbl_80367250 == 1) {
            Fx_FadeIn(obj, 0x3E8);
            fn_8014876C(obj, 0x64, 0x3E8);
            lbl_80367250 = 0;
        }
    }
}
#pragma cplusplus reset
#pragma optimization_level reset

void fn_8002DEB4(s32 arg0) {
    extern u16 Battle_str[];

    fn_801481CC((u8 *)Battle_str + 0x1e3, arg0);
    fn_801481CC((u8 *)Battle_str + 0x1f1, arg0);
    fn_801481CC((u8 *)Battle_str + 0x1ff, arg0);
    fn_801481CC((u8 *)Battle_str + 0x20d, arg0);
    fn_801481CC((u8 *)Battle_str + 0x21b, arg0);
    fn_801481CC((u8 *)Battle_str + 0x22b, arg0);
}

void fn_8002DF54(void) {
    M2C_UNK fn_80147188(M2C_UNK);
    extern s8 gBgmQuietVol;
    extern s8 gBgmVol;
    extern s8 lbl_80367AF6;
    fn_80147188(0);
    gBgmQuietVol = 0x64;
    gBgmVol = 0x64;
    lbl_80367AF6 = 0;
}

void fn_8002DF8C(void) {
void Allegiance_FillMask(s32,u8 *);
void Unit_SeparateRescue(void *,u8,u8);
void fn_80104410(void *);
s32 Unit_GetMaxHp(void *);
void Unit_SetHp(void *,s32);
void fn_8003BBD4(void *,s32);
void fn_8003C1B4(void *);
void fn_8014DA88(void *,s32);
extern u8 gUnits[],gBattleState[];
u8 mask[8];
s32 i;
u8 *unit;
u8 *rescued;
u32 flags;
Allegiance_FillMask(4,mask);
i=1;
do {
if ((u8)i != 0) unit=gUnits+((u8)i-1)*0x280; else unit=0;
if (*(u32 *)(unit+0x188)!=0 && mask[(*(u8 **)(unit+0x190))[8]]!=0) {
flags=*(u32 *)(unit+0x1A0);
if ((flags&2) && !(flags&0x100000)) {
rescued=*(u8 **)(unit+0x194);
Unit_SeparateRescue(unit,unit[0x19E],unit[0x19F]);
if (rescued) *(u32 *)(rescued+0x1A0)&=~1;
}
*(u32 *)(unit+0x1A0)&=0xFF88C7FE;
fn_80104410(unit+0x1A4);
Unit_SetHp(unit,(s8)Unit_GetMaxHp(unit));
fn_8003BBD4(unit,0);
fn_8003C1B4(unit);
}
i++;
} while (i<=0x9F);
fn_8014DA88(gBattleState+0x3C4,1);
*(u16 *)(gBattleState+0x12)=1;
gBattleState[0x11]=0;
}

void Battle_AdvancePhase(void) {
    void Game_SetState(s32);
    void Allegiance_FillMask(s32, void *);
    void *Unit_FindByName(void *);
    void fn_80016C58(void);
    void Unit_SetHp(void *, s8);
    s32 Unit_GetMaxHp(void *);
    void fn_8003BBD4(void *, s32);
    void fn_8003C1B4(void *);
    void Unit_MoveToListHead(void *, s32);
    void Unit_SeparateRescue(void *, u8, u8);
    void fn_80104410(void *);
    void Battle_SetPhase(void *, u8);
    void fn_8014DA88(void *, s32);
    void fn_801E3400(void *, u8);
    extern u8 gBattleState[];
    extern u8 gUnits[];
    extern u8 gUnitLists[];
    extern u8 Battle_str[];
    extern u8 gSystemSave[];
    u8 factionMaskB[8];
    u8 factionMaskA[8];

    /* Advance battle phase: clear turn state on active units, then bump phase. */
    if ((gBattleState[0x9F] >> 3) & 1) {
        Game_SetState(0x20);
        return;
    }
    if (gBattleState[0x10] == 0x1C) {
        s32 i;
        u8 *unit;
        void *partner;
        u32 flags;

        Allegiance_FillMask(4, factionMaskA);
        i = 1;
        do {
            if ((u8)i != 0) {
                unit = gUnits + ((u8)i - 1) * 0x280;
            } else {
                unit = NULL;
            }
            if (*(u32 *)(unit + 0x188) != 0
                && factionMaskA[*(u8 *)(*(u8 **)(unit + 0x190) + 8)] != 0) {
                flags = *(u32 *)(unit + 0x1A0);
                if ((flags & 2) && !(flags & 0x100000)) {
                    partner = *(void **)(unit + 0x194);
                    Unit_SeparateRescue(unit, unit[0x19E], unit[0x19F]);
                    if (partner != NULL) {
                        *(u32 *)((u8 *)partner + 0x1A0) &= ~1;
                    }
                }
                flags = *(u32 *)(unit + 0x1A0);
                *(u32 *)(unit + 0x1A0) = flags & 0xFF88C7FE;
                fn_80104410(unit + 0x1A4);
                Unit_SetHp(unit, (s8)Unit_GetMaxHp(unit));
                fn_8003BBD4(unit, 0);
                fn_8003C1B4(unit);
            }
            i += 1;
        } while (i <= 0x9F);
        fn_8014DA88(gBattleState + 0x3C4, 1);
        *(s16 *)(gBattleState + 0x12) = 1;
        gBattleState[0x11] = 0;
        Battle_SetPhase(gBattleState, (u8)(gBattleState[0x10] + 1));
        gBattleState[0x54] = 4;
        return;
    }
    {
        void *unit;
        void *next;
        u32 flags;

        unit = *(void **)(gUnitLists + 0x40);
        while (unit != NULL) {
            flags = *(u32 *)((u8 *)unit + 0x1A0);
            next = *(void **)((u8 *)unit + 0x180);
            if ((flags & 0x4000) && (flags & 0x10000)) {
                Unit_MoveToListHead(unit, 0);
            }
            unit = next;
        }
        unit = Unit_FindByName(Battle_str + 0x29C);
        if (unit != NULL) {
            Unit_MoveToListHead(unit, 0);
        }
    }
    {
        s32 i;
        u8 *unit;
        void *partner;
        u32 flags;

        Allegiance_FillMask(4, factionMaskB);
        i = 1;
        do {
            if ((u8)i != 0) {
                unit = gUnits + ((u8)i - 1) * 0x280;
            } else {
                unit = NULL;
            }
            if (*(u32 *)(unit + 0x188) != 0
                && factionMaskB[*(u8 *)(*(u8 **)(unit + 0x190) + 8)] != 0) {
                flags = *(u32 *)(unit + 0x1A0);
                if ((flags & 2) && !(flags & 0x100000)) {
                    partner = *(void **)(unit + 0x194);
                    Unit_SeparateRescue(unit, unit[0x19E], unit[0x19F]);
                    if (partner != NULL) {
                        *(u32 *)((u8 *)partner + 0x1A0) &= ~1;
                    }
                }
                flags = *(u32 *)(unit + 0x1A0);
                *(u32 *)(unit + 0x1A0) = flags & 0xFF88C7FE;
                fn_80104410(unit + 0x1A4);
                Unit_SetHp(unit, (s8)Unit_GetMaxHp(unit));
                fn_8003BBD4(unit, 0);
                fn_8003C1B4(unit);
            }
            i += 1;
        } while (i <= 0x9F);
    }
    fn_80016C58();
    fn_8014DA88(gBattleState + 0x3C4, 0);
    Battle_SetPhase(gBattleState, (u8)(gBattleState[0x10] + 1));
    gBattleState[0x54] = 4;
    if (gBattleState[0x10] == 0x20) {
        fn_801E3400(gSystemSave, gBattleState[0x51C]);
    }
}

void fn_8002E408(s32 arg0) {
    void fn_800AE3DC();
    extern u8 gBattleState[];
    if (gBattleState[gBattleState[0x11] + 0x14] != 0) {
        fn_800AE3DC(arg0);
    }
}

void Battle_FocusCamOnStatus0Unit(void) {
    /* On player phase (when battle flag 0x9E bit6 is clear), focus the camera on the first unit with status bit 0. */
    u8 Status_Test(void *, s32);
    void BattleState_SetCamPos(void *, f32, f32);
    extern struct {
        void *head;
        s32 unk4;
        s32 unk8;
    } gUnitLists[];
    extern u8 gBattleState[];
    void *unit;

    if (gBattleState[0x11] == 0 && !((gBattleState[0x9E] >> 6) & 1)) {
        for (unit = gUnitLists[gBattleState[0x11]].head; unit != NULL; unit = *(void **)((u8 *)unit + 0x184)) {
            if (Status_Test((u8 *)unit + 0x1BC, 0)) {
                break;
            }
        }
        if (unit != NULL) {
            BattleState_SetCamPos(gBattleState, (s8)*((u8 *)unit + 0x19E), (s8)*((u8 *)unit + 0x19F));
        }
    }
}

void fn_8002E510(void) {
    u8 Status_Test(void *, M2C_UNK);
    void BattleState_SetCamPos(void *, f32, f32);
    extern struct {
        void *head;
        s32 unk4;
        s32 unk8;
    } gUnitLists[];
    extern u8 gBattleState[];
    void *p;

    for (p = gUnitLists[0].head; p != NULL; p = M2C_FIELD(p, void **, 0x184)) {
        if (Status_Test((u8 *)p + 0x1BC, 0)) {
            break;
        }
    }
    if (p != NULL) {
        BattleState_SetCamPos(gBattleState, M2C_FIELD(p, s8 *, 0x19E), M2C_FIELD(p, s8 *, 0x19F));
    }
}

void fn_8002E5B4(s32 arg0) {
    u8 Map_IsInViewBounds(void *, s8, s8);
    void Process_Goto(s32, M2C_UNK);
    extern struct {
        void *head;
        s32 unk4;
        s32 unk8;
    } gUnitLists[];
    extern u8 gBattleState[];
    extern u8 gBattleMap[];
    void *p;
    void *next;

    p = gUnitLists[gBattleState[0x11]].head;
    while (p != NULL) {
        next = M2C_FIELD(p, void **, 0x184);
        if (Map_IsInViewBounds(gBattleMap, M2C_FIELD(p, s8 *, 0x19E), M2C_FIELD(p, s8 *, 0x19F))) {
            return;
        }
        p = next;
    }
    Process_Goto(arg0, 5);
}

void fn_8002E648(void) {
    M2C_UNK fn_8014D3B4(void *);
    extern u8 gBattleState[];
    fn_8014D3B4(gBattleState);
}

/* Start the computer-player phase process for the current allegiance, if that side's phase slot is active. */
void Battle_StartCpPhase(s32 parent) {
    void *BattleState_GetFactionInfo(void *, u8);
    void CpPhase_Start(s32);
    void CpPhase_StartAlt(s32);
    extern u8 gBattleState[];
    u8 *state;
    u8 *phaseTable;
    void *factionInfo;
    s32 allegiance;

    state = gBattleState;
    phaseTable = state + 0x14;
    allegiance = state[0x11];
    if (phaseTable[allegiance] == 0) {
        return;
    }
    factionInfo = BattleState_GetFactionInfo(state, (u8)allegiance);
    allegiance = state[0x11];
    if (allegiance == 3) {
        goto case3;
    }
    if (allegiance >= 3) {
        goto end;
    }
    if (allegiance == 0) {
        goto case0;
    }
    if (allegiance >= 0) {
        goto case12;
    }
    goto end;
case0:
    CpPhase_Start(parent);
    goto end;
case3:
    if (factionInfo != NULL) {
        if (*(u8 *)factionInfo == 1) {
            CpPhase_StartAlt(parent);
        } else {
            CpPhase_Start(parent);
        }
    }
    goto end;
case12:
    if (phaseTable[allegiance] == 2) {
        CpPhase_StartAlt(parent);
    }
end:
    return;
}

void fn_8002E738(s32 arg0) {
    M2C_UNK Process_CreateChild(void *, s32);
    extern u8 gBattleState[];
    extern u8 Proc_BMapPlph[];
    if (gBattleState[gBattleState[0x11] + 0x14] == 1) {
        Process_CreateChild(Proc_BMapPlph, arg0);
    }
}

void Battle_ResetAllyTurnVisuals(void)
{
    void Allegiance_FillMask(s32, u8 *);
    u8 Map_IsInViewBounds(void *, u8, u8);
    void Map_RefreshUnitMap(void *);
    void Unit_FadeFacing(u8 *, s32, s32, f32);
    extern u8 gUnits[];
    extern u8 gBattleMap[];
    extern u8 gBattleState[];
    extern f32 lbl_80368DE8;
    u8 factionMask[8];
    s32 i;
    u8 *unit;
    u8 *state;

    /* Clear ally turn bits, fade on-screen units to 0 alpha, then refresh the map. */
    Allegiance_FillMask(3, factionMask);
    state = gBattleState;
    i = 1;
    do {
        if ((u8)i != 0) {
            unit = gUnits + ((u8)i - 1) * 0x280;
        } else {
            unit = NULL;
        }
        if (*(u32 *)(unit + 0x188) != 0) {
            if (factionMask[(*(u8 **)(unit + 0x190))[8]] != 0) {
                *(u32 *)(unit + 0x1A0) &= ~1;
                if (!((state[0x9E] >> 4) & 1)) {
                    if (Map_IsInViewBounds(gBattleMap, unit[0x19E], unit[0x19F]) != 0) {
                        Unit_FadeFacing(unit, 0x10, 0, lbl_80368DE8);
                    }
                }
                *(u32 *)(unit + 0x1A0) &= ~0x800;
            }
        }
        i += 1;
    } while (i <= 0x9F);
    Map_RefreshUnitMap(gBattleMap);
}

void fn_8002E880(void) {
    void Allegiance_FillMask(s32, u8 *);
    void fn_8003B69C(void *);
    void fn_8010FBD4(void *);
    extern u8 gUnits[];
    extern u8 gBattleState[];
    extern u8 gMapObjEventList[];
    u8 sp8[8];
    s32 i;
    u8 *unit;

    Allegiance_FillMask(0, sp8);
    i = 1;
    do {
        if ((u8)i != 0) {
            unit = gUnits + ((u8)i - 1) * 0x280;
        } else {
            unit = NULL;
        }
        if (*(u32 *)(unit + 0x188) != 0) {
            if (sp8[(*(u8 **)(unit + 0x190))[8]] != 0) {
                fn_8003B69C(unit);
            }
        }
        i += 1;
    } while (i <= 0x9F);
    if (gBattleState[0x11] == 0) {
        fn_8010FBD4(gMapObjEventList);
    }
}

void fn_8002E93C(void) {
    void UnitList_GainSupportPoints(void *);
    void fn_8014D678(void *);
    void Allegiance_SetMask(s8, s8, s8, s8, s8, s8, s8, s8, void *);
    void Status_Set(void *, s32);
    void fn_800163F8(void);
    extern u8 gBattleState[];
    extern u8 gUnitLists[];
    extern u8 gUnits[];
    u8 allegMask[8];
    u8 *unit;
    s32 i;
    void *next;
    void *p;

    if (gBattleState[0x10] != 0x1D) {
        if (gBattleState[0x10] != 0x12 || (s32)gBattleState[0x54] >= 8 || (s32)gBattleState[0x54] < 5) {
            UnitList_GainSupportPoints(gUnitLists);
        }
    }
    fn_8014D678(gBattleState);
    Allegiance_SetMask(1, 0, 0, 0, 0, 1, 1, 1, allegMask);
    for (i = 1; i <= 0x9F; i++) {
        if ((u8)i != 0) {
            unit = gUnits + ((u8)i - 1) * 0x280;
        } else {
            unit = NULL;
        }
        if (*(u32 *)(unit + 0x188) != 0
            && allegMask[*(u8 *)(*(u8 **)(unit + 0x190) + 8)] != 0) {
            *(u32 *)(unit + 0x1A0) &= ~0x4400;
            Status_Set(unit + 0x1BC, 0x5C);
        }
    }
    p = *(void **)gUnitLists;
    goto test;
body:
    next = *(void **)((u8 *)p + 0x184);
    *(u32 *)((u8 *)p + 0x1A0) |= 0x400;
    p = next;
test:
    if (p != NULL) {
        goto body;
    }
    fn_800163F8();
}

s32 fn_8002EA74(void) {
    return 0;
}

void Ui_CalcSlideFadeIn(s32 *frame, s32 *outY, s32 *outX, s32 *outAlpha) {
    /* Ease slide-in: Y from -64 to 0 and alpha 0 to 255 over 8 frames; X stays 0. */
    f32 Math_Ease(s32, f32, f32, f32, f32);
    s32 t;

    *outX = 0;
    t = *frame;
    t = t + 1;
    if (t > 8) {
        t = 8;
    }
    *outY = (s32)Math_Ease(6, -64.0f, 0.0f, (f32)t, 8.0f);
    *outAlpha = (s32)Math_Ease(0, 0.0f, 255.0f, (f32)t, 8.0f);
}

#pragma cplusplus on
extern "C" void *fn_8002EB54(void *arg0, u32 arg1) {
    void *Process_CreateChild(void *);
    void *Process_Create(void *, s32);
    void BattleState_SetCamPos(void *, f32, f32);
    extern u8 lbl_80285028[];
    extern s32 gTargetList[];
    extern u8 gBattleState[];
    extern f32 lbl_80368E00;
    struct Obj {
        u8 pad[4];
        virtual void v0(void *) = 0;
        virtual void v1(void *) = 0;
        virtual void v2(void *) = 0;
        virtual void v3(void *) = 0;
        virtual void v4(void *) = 0;
        virtual void v5(void *) = 0;
    };
    void *obj;
    s32 *base;
    u32 i;
    s32 *walk;
    s32 n;
    u32 pm;
    u32 qm;
    u8 *p;
    u8 *q;
    void *found;
    u32 tmp;
    u32 temp0;
    u32 temp1;
    f32 fx;
    f32 fy;

    if (arg1 != 0U) {
        obj = Process_CreateChild(lbl_80285028);
    } else {
        obj = Process_Create(lbl_80285028, 3);
    }
    ((u8 *)obj)[0x48] = (u8)(s32)*(f32 *)(gBattleState + 0x524);
    base = gTargetList;
    i = 0;
    walk = base;
    ((u8 *)obj)[0x49] = (u8)(s32)*(f32 *)(gBattleState + 0x528);
    for (n = base[0]; i < n; n = base[0]) {
        pm = (i + n - 1) % n;
        qm = (i + 1) % n;
        i += 1;
        tmp = pm * 0x14;
        tmp = (u32)base + tmp;
        tmp = tmp + 8;
        *(void **)((u8 *)walk + 0xC) = (void *)tmp;
        tmp = qm * 0x14;
        tmp = (u32)base + tmp;
        tmp = tmp + 8;
        *(void **)((u8 *)walk + 0x10) = (void *)tmp;
        walk = (s32 *)((u8 *)walk + 0x14);
    }
    *(void **)((u8 *)obj + 0x30) = arg0;
    p = (u8 *)gTargetList + 8;
    if (gTargetList[0] <= 0) {
        p = (u8 *)0;
    }
    *(void **)((u8 *)obj + 0x40) = p;
    if (p != (u8 *)0) {
        *(void **)((u8 *)obj + 0x44) = p;
    }
    q = (u8 *)gTargetList + 8;
    n = gTargetList[0];
    if (n <= 0) {
        q = (u8 *)0;
    }
    p = (u8 *)gTargetList + 8;
    if (n <= 0) {
        p = (u8 *)0;
    }
    temp0 = ((u8 *)obj)[0x3E];
    fx = lbl_80368E00 + (f32)(s8)p[0];
    temp1 = ((u8 *)obj)[0x3F];
    fy = lbl_80368E00 + (f32)(s8)q[1];
    ((u8 *)obj)[0x3C] = temp0;
    ((u8 *)obj)[0x3D] = temp1;
    *(f32 *)((u8 *)obj + 0x34) = fx;
    *(f32 *)((u8 *)obj + 0x38) = fy;
    ((u8 *)obj)[0x3E] = (u8)(s32)*(f32 *)((u8 *)obj + 0x34);
    ((u8 *)obj)[0x3F] = (u8)(s32)*(f32 *)((u8 *)obj + 0x38);
    temp0 = ((u8 *)obj)[0x3E];
    if ((s8)((u8 *)obj)[0x3C] != (s8)temp0 || (s8)((u8 *)obj)[0x3D] != (s8)((u8 *)obj)[0x3F]) {
        found = map_find_xy(base, (s8)temp0, (s8)((u8 *)obj)[0x3F]);
        *(void **)((u8 *)obj + 0x40) = found;
        if (found != (void *)0) {
            *(void **)((u8 *)obj + 0x44) = found;
        }
    }
    q = (u8 *)gTargetList + 8;
    n = gTargetList[0];
    if (n <= 0) {
        q = (u8 *)0;
    }
    p = (u8 *)gTargetList + 8;
    if (n <= 0) {
        p = (u8 *)0;
    }
    BattleState_SetCamPos(gBattleState, (f32)(s8)q[0], (f32)(s8)p[1]);
    ((Obj *)arg0)->v1(obj);
    *(s32 *)arg0 = 0;
    ((Obj *)arg0)->v5(obj);
    gBattleState[0x51D] = 0x10;
    return obj;
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_8002EEA8(void *arg0) {
    struct Obj {
        u8 pad[4];
        virtual void v0(void *) = 0;
        virtual void v1(void *) = 0;
        virtual void v2(void *) = 0;
        virtual void v3(void *) = 0;
        virtual void v4(void *) = 0;
        virtual void v5(void *) = 0;
        virtual void v6(void *) = 0;
        virtual void v7(void *) = 0;
        virtual void v8(void *) = 0;
        virtual void v9(void *) = 0;
    };
    ((Obj *)*(void **)((u8 *)arg0 + 0x30))->v9(arg0);
}
#pragma cplusplus reset
#pragma cplusplus on
extern "C" void fn_8002EEDC(void *arg0) {
    struct Obj {
        u8 pad[4];
        virtual void v0(void *) = 0;
        virtual void v1(void *) = 0;
        virtual void v2(void *) = 0;
    };
    ((Obj *)*(void **)((u8 *)arg0 + 0x30))->v2(arg0);
}

extern "C" void fn_8002EF10(u8 *self) {
void Ui_PlaySeCue(void *,s32); void Process_Goto(void *,s32);
extern u32 gUiInputFlags,lbl_80367258;
extern u32 *gPadInput;
extern u8 gMapUiResult,lbl_802694B8[];
#pragma cplusplus on
struct Controller { s32 count;
virtual void v0(void *)=0;
virtual void v1(void *)=0;
virtual void v2(void *)=0;
virtual u8 v3(void *)=0;
virtual u8 v4(void *)=0;
virtual void v5(void *)=0;
virtual void v6(void *)=0;
virtual void v7(void *)=0;
virtual void v8(void *)=0;
virtual void v9(void *)=0;
virtual void *v10()=0;
};
u32 held,pressed;
if(!*(u32 *)(self+0x40)) (*(Controller **)(self+0x30))->count=0;
else (*(Controller **)(self+0x30))->count++;
if(gUiInputFlags&0x80) (*(Controller **)(self+0x30))->v8(self);
else {
(*(Controller **)(self+0x30))->v7(self);
(*(Controller **)(self+0x30))->v8(self);
lbl_80367258=0;
held=gPadInput[1];
pressed=held & (gPadInput[2]^held);
if(pressed&0x100) lbl_80367258=(*(Controller **)(self+0x30))->v3(self);
else if(pressed&0x200) lbl_80367258=(*(Controller **)(self+0x30))->v4(self);
}
gMapUiResult=lbl_80367258;
if(lbl_80367258&4) Ui_PlaySeCue((*(Controller **)(self+0x30))->v10(),100);
if(lbl_80367258&8) Ui_PlaySeCue(lbl_802694B8+0xee,100);
if(lbl_80367258&16) Ui_PlaySeCue(lbl_802694B8+0xfe,100);
if(lbl_80367258&1) Process_Goto(self,99);
#pragma cplusplus reset
}

#pragma cplusplus reset

void fn_8002F0B0(void) {
    M2C_UNK fn_800F20E0();
    fn_800F20E0();
}

#pragma cplusplus on
extern "C" void fn_8002F0D0(void *arg0, void *arg1) {
    void fn_800F214C(void);
    void BattleState_SetCamPos(void *, f32, f32);
    void Ui_PlaySeCue(void *, s32);
    extern s32 *gPadInput;
    extern u8 gBattleState[];
    extern s32 gTargetList[];
    extern f32 lbl_80368E08;
    extern u8 lbl_802694B8[];
    struct Obj {
        u8 pad[4];
        virtual void v0(void *) = 0;
        virtual void v1(void *) = 0;
        virtual void v2(void *) = 0;
        virtual void v3(void *) = 0;
        virtual void v4(void *) = 0;
        virtual void v5(void *) = 0;
    };
    void *found;
    void *var_r31;
    void *cur;
    s32 flags;
    u8 changed;
    u8 temp_r4;
    f32 fa;
    f32 fb;
    u8 t0;
    u8 t1;

    if ((gPadInput[1] & 0xF) == 0) {
        fn_800F214C();
        t0 = ((u8 *)arg1)[0x3E];
        fa = *(f32 *)(gBattleState + 0x538);
        fb = *(f32 *)(gBattleState + 0x534);
        ((u8 *)arg1)[0x3C] = t0;
        t1 = ((u8 *)arg1)[0x3F];
        ((u8 *)arg1)[0x3D] = t1;
        *(f32 *)((u8 *)arg1 + 0x34) = fb;
        *(f32 *)((u8 *)arg1 + 0x38) = fa;
        ((u8 *)arg1)[0x3E] = (u8)(s32)*(f32 *)((u8 *)arg1 + 0x34);
        ((u8 *)arg1)[0x3F] = (u8)(s32)*(f32 *)((u8 *)arg1 + 0x38);
        temp_r4 = ((u8 *)arg1)[0x3E];
        if ((s8)((u8 *)arg1)[0x3C] != (s8)temp_r4 ||
            (s8)((u8 *)arg1)[0x3D] != (s8)((u8 *)arg1)[0x3F]) {
            found = map_find_xy(gTargetList, temp_r4, ((u8 *)arg1)[0x3F]);
            *(void **)((u8 *)arg1 + 0x40) = found;
            if (found != NULL) {
                *(void **)((u8 *)arg1 + 0x44) = found;
            }
        }
    } else {
        flags = gPadInput[3];
        var_r31 = NULL;
        cur = *(void **)((u8 *)arg1 + 0x44);
        if (flags & 9) {
            var_r31 = *(void **)((u8 *)cur + 4);
        }
        if (flags & 6) {
            var_r31 = *(void **)((u8 *)cur + 8);
        }
        if (var_r31 == NULL) {
            goto end;
        }
        if (var_r31 != cur) {
            goto do_body;
        }
        goto end;
    do_body:
        {
            s8 c0 = ((u8 *)var_r31)[0];
            s8 c1 = ((u8 *)var_r31)[1];
            t0 = ((u8 *)arg1)[0x3E];
            ((u8 *)arg1)[0x3C] = t0;
            t1 = ((u8 *)arg1)[0x3F];
            ((u8 *)arg1)[0x3D] = t1;
            *(f32 *)((u8 *)arg1 + 0x34) = lbl_80368E08 + (f32)c0;
            *(f32 *)((u8 *)arg1 + 0x38) = lbl_80368E08 + (f32)c1;
        }
        ((u8 *)arg1)[0x3E] = (u8)(s32)*(f32 *)((u8 *)arg1 + 0x34);
        ((u8 *)arg1)[0x3F] = (u8)(s32)*(f32 *)((u8 *)arg1 + 0x38);
        temp_r4 = ((u8 *)arg1)[0x3E];
        if ((s8)((u8 *)arg1)[0x3C] != (s8)temp_r4 ||
            (s8)((u8 *)arg1)[0x3D] != (s8)((u8 *)arg1)[0x3F]) {
            found = map_find_xy(gTargetList, temp_r4, ((u8 *)arg1)[0x3F]);
            *(void **)((u8 *)arg1 + 0x40) = found;
            if (found != NULL) {
                *(void **)((u8 *)arg1 + 0x44) = found;
            }
        }
        BattleState_SetCamPos(gBattleState, (f32)(s8)((u8 *)var_r31)[0], (f32)(s8)((u8 *)var_r31)[1]);
        Ui_PlaySeCue(lbl_802694B8 + 0x10C, 0x64);
        *(void **)((u8 *)arg1 + 0x40) = var_r31;
        if (var_r31 != NULL) {
            *(void **)((u8 *)arg1 + 0x44) = var_r31;
        }
    }

    changed = 0;
    if ((s8)((u8 *)arg1)[0x3E] != (s8)((u8 *)arg1)[0x3C] ||
        (s8)((u8 *)arg1)[0x3F] != (s8)((u8 *)arg1)[0x3D]) {
        changed = 1;
    }
    if (changed) {
        ((Obj *)arg0)->v5(arg1);
    }
end:
    *(s32 *)arg0 = 0;
}
#pragma cplusplus reset

s32 fn_8002F468(void) {
    extern u8 gBattleState[];
    gBattleState[0x51D] = 0xF;
    return 9;
}

s32 fn_8002F480(void *arg0, void *arg1) {
    extern u8 gUiContext[];
    extern u8 gUnits[];
    u8 *p = *(u8 **)((u8 *)arg1 + 0x40);
    u8 b0;
    u8 b1;
    u8 id;

    if (p == NULL) {
        return 0x10;
    }
    b1 = p[1];
    b0 = p[0];
    gUiContext[0xF] = b0;
    gUiContext[0x10] = b1;
    id = p[2];
    if (id != 0) {
        *(void **)(gUiContext + 4) = (id != 0) ? gUnits + (id - 1) * 0x280 : NULL;
    }
    return 5;
}

void fn_8002F4EC(void *arg0, void *arg1) {
    void Map_HideMoveLimitView(void *);
    void BattleState_SetCamPos(void *, f32, f32);
    extern u8 gBattleState[];

    Map_HideMoveLimitView(arg0);
    BattleState_SetCamPos(gBattleState, (f32)*(s8 *)((u8 *)arg1 + 0x48), (f32)*(s8 *)((u8 *)arg1 + 0x49));
}

#pragma optimization_level 3
void fn_8002F564(void) {
    void Map_FillLayer(void *, s32, s32);
    void Map_ShowMoveLimitView(void);
    extern u8 gBattleMap[];
    extern s32 gTargetList[];
    u8 *p;
    s32 limit;
    s32 i;
    s32 n;
    u8 *entry;
    s8 x;
    s8 y;

    Map_FillLayer(gBattleMap, 5, -1);
    Map_FillLayer(gBattleMap, 8, 0);

    p = (u8 *)gTargetList;
    limit = *(s32 *)p;
    i = 0;
    for (n = limit; n > 0; n--) {
        if (i >= limit) {
            entry = NULL;
        } else {
            entry = p + 8;
        }
        y = (s8)entry[1];
        p += 0x14;
        x = (s8)entry[0];
        i += 1;
        *(u16 *)(gBattleMap + ((x + (y << 6)) * 2) + 0xC18E) = 1;
    }
    Map_ShowMoveLimitView();
}
#pragma optimization_level reset
void fn_8002F61C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 1);
}

void *TargetList_GetCurrent(s32 *arg0) {
    s32 idx = arg0[1];
    if (idx >= *arg0) {
        return NULL;
    }
    return (void *)((char *)arg0 + idx * 0x14 + 8);
}

void *TargetList_GetAt(s32 *arg0, s32 arg1) {
    if (arg1 >= (s32)*arg0) {
        return NULL;
    }
    return (void *)((char *)arg0 + arg1 * 0x14 + 0x8);
}

void *fn_8002F680(s32 *arg0, s8 arg1, s8 arg2) {
    s32 *p;
    s32 i;
    s32 n;

    n = *arg0;
    p = arg0;
    for (i = 0; i < n; p = (s32 *)((char *)p + 0x14), i++) {
        if (arg1 == *(s8 *)((char *)p + 8) && arg2 == *(s8 *)((char *)p + 9)) {
            return (void *)((char *)arg0 + i * 0x14 + 8);
        }
    }
    return NULL;
}

void fn_8002F6E8(void *arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    s32 *m = (s32 *)arg0;
    s32 idx = *m;
    u8 *p;
    *m = idx + 1;
    p = (u8 *)arg0 + (idx * 0x14) + 8;
    p[0] = arg1;
    p[1] = arg2;
    p[2] = arg3;
    p[3] = arg4;
    *((s8 *)((u8 *)arg0 + (*m * 0x14) + 8)) = -1;
}

void fn_8002F728(void *arg0) {
    *(s32*)((char*)arg0 + 0x0) = 0;
    *(s32*)((char*)arg0 + 0x4) = 0;
    *(s8*)((char*)arg0 + 0x8) = -1;
}

#pragma dont_inline on
u32 UnitRef_GetUnit(u32 arg0) {
    extern u8 gUnits[101760];
    u8 id = ((u8 *)arg0)[2];
    if (id != 0) {
        return (u32)&gUnits[(id - 1) * 0x280];
    }
    return 0;
}
#pragma dont_inline reset

void fn_8002F76C(void) {

}

void fn_8002F770(void) {

}

void fn_8002F774(void) {

}

void *fn_8002F778(void) {
    extern u16 lbl_802694B8[];
    return (char *)lbl_802694B8 + 0xDE;
}

void fn_8002F788(s32 arg0) {
    void *Item_GetByIid(void *);
    void fn_8002C034(void *, void *);
    void *fn_8002EB54(void *, s32);
    extern u8 gMapUiStrs[];
    extern u8 lbl_80285050[];
    extern u8 lbl_802853B4[];
    extern u8 lbl_802853EC[];
    extern void *gUiContext[];
    extern u8 lbl_802EFDAC[];
    extern s8 lbl_80367281;
    void *temp;

    temp = gUiContext[0];
    fn_8002C034(temp, Item_GetByIid(gMapUiStrs + 0xE5));
    if (lbl_80367281 == 0) {
        *(void **)(lbl_802EFDAC + 4) = lbl_80285050;
        *(void **)(lbl_802EFDAC + 4) = lbl_802853EC;
        *(void **)(lbl_802EFDAC + 4) = lbl_802853B4;
        lbl_80367281 = 1;
    }
    fn_8002EB54(lbl_802EFDAC, arg0);
}

void fn_8002F82C(s32 arg0) {
    void Map_ShowMoveLimitView(void);
    void Process_CreateChild(void *, s32);
    void MapObj_BuildAttackTargetList(void *, s32);
    void fn_8002EB54(void *, s32);
    extern void *gUiContext[6];
    extern u8 lbl_802850C0[];
    extern u8 lbl_80367280;
    extern u8 lbl_80285050[];
    extern u8 lbl_802EFDA0[];
    extern u8 lbl_802853EC[];
    extern u8 lbl_8028537C[];
    void **p = gUiContext;

    if (((u8 *)p)[8] == 0x31) {
        Map_ShowMoveLimitView();
        Process_CreateChild(lbl_802850C0, arg0);
        return;
    }
    MapObj_BuildAttackTargetList(p[0], 0);
    if ((s8)lbl_80367280 == 0) {
        *(void **)(lbl_802EFDA0 + 4) = lbl_80285050;
        *(void **)(lbl_802EFDA0 + 4) = lbl_802853EC;
        *(void **)(lbl_802EFDA0 + 4) = lbl_8028537C;
        lbl_80367280 = 1;
    }
    fn_8002EB54(lbl_802EFDA0, arg0);
}

void fn_8002F8DC(void) {
    void fn_8002FC64(u32,s32,s32,s32);
    void Item_Init(void *);
    void Item_SetByName(void *,void *);
    void Item_Destroy(void *,s32);
    u8 Allegiance_CompareIds(u8,u8);
    void Battle_SetupPair(void *,void *,void *);
    void fn_801A7528(void *,void *);
    void fn_801A6F34(void *,s32);
    extern u8 gBattleState[],gBattleMap[],gUnits[],gMapUiStrs[],gUiContext[],gBattle[];
    u32 item[2];
    s32 row;
    s32 x;
    u8 id;
    void *unit;
    x=(s8)*(f32*)(gBattleState+0x524);
    row=(s8)*(f32*)(gBattleState+0x528)<<6;
    if(((u16*)(gBattleMap+0x10000))[(x+row)-0x1f39]!=0) {
        id=*(gBattleMap+x+row+0xd);
        if(id) unit=gUnits+(id-1)*0x280;
        else unit=0;
        if(unit && Allegiance_CompareIds(*(u8*)(*(u8**)((u8*)unit+0x190)+8),gBattleState[0x11])==1) {
            Item_Init(item);
            Item_SetByName(item,gMapUiStrs+0xf1);
            Battle_SetupPair(gBattle,*(void**)gUiContext,unit);
            fn_801A7528(gBattle,item);
            fn_801A6F34(gBattle,15);
            if(!((gBattleState[0x9d]>>6)&3)) *(s16*)(gBattle+0x57a)=*(s16*)(gBattle+0x298)-1;
            fn_8002FC64((u32)unit,0,0,255);
            Item_Destroy(item,-1);
        }
    }
}

void fn_8002FA54(void) {
    void MapObj_BuildAttackTargetList(void *, s32);
    void TargetList_GetAt(void *, s32);
    s32 UnitRef_GetUnit(void);
    void fn_8014CB14(void *, s32);
    extern u8 gUiContext[];
    extern u8 gTargetList[];
    extern u8 gBattleState[];
    s32 *p;
    s32 tmp;

    MapObj_BuildAttackTargetList(*(void **)gUiContext, 0);
    p = (s32 *)gTargetList;
    if (*p != 0) {
        TargetList_GetAt(p, 0);
        tmp = UnitRef_GetUnit();
        fn_8014CB14(gBattleState, tmp);
    }
}

/* Confirm cursor tile if it is marked in the range map (A), or cancel (B). */
void MapUi_HandleRangeConfirm(void *proc) {
    void Ui_PlaySeCue(void *, s32);
    void Process_Goto(void *, s32);
    extern void *gPadInput;
    extern f32 gBattleState[];
    extern u8 gBattleMap[];
    extern u8 gMapUiStrs[];
    extern u8 gMapUiResult;
    s32 held;
    s32 pressed;
    f32 cursorY;
    f32 cursorX;
    u16 *rangeMap;

    held = *(s32 *)((u8 *)gPadInput + 4);
    pressed = held & (*(s32 *)((u8 *)gPadInput + 8) ^ held);
    if (pressed & 0x100) {
        cursorY = gBattleState[0x528 / 4];
        cursorX = gBattleState[0x524 / 4];
        rangeMap = (u16 *)(gBattleMap + 0xC18E);
        if (rangeMap[(s8)(s32)cursorX + ((s8)(s32)cursorY << 6)] != 0) {
            Ui_PlaySeCue(gMapUiStrs + 0xFC, 0x64);
            gMapUiResult = 5;
            Process_Goto(proc, 0x63);
            return;
        }
    }
    if (pressed & 0x200) {
        Ui_PlaySeCue(gMapUiStrs + 0x10C, 0x64);
        gMapUiResult = 9;
        Process_Goto(proc, 0x63);
    }
}

void fn_8002FBA8(s32 arg0) {
    void *Unit_GetActiveItemPtr(void *);
    void fn_8002BEFC(void *, void *);
    void fn_8002C034(void *, void *);
    void fn_8002EB54(void *, s32);
    extern u8 gUiContext[];
    extern u8 lbl_80367275;
    extern u8 lbl_80285050[];
    extern u8 lbl_802EFD88[];
    extern u8 lbl_802853EC[];

    if (gUiContext[8] == 0x27) {
        fn_8002BEFC(*(void **)gUiContext, *(void **)Unit_GetActiveItemPtr(*(void **)gUiContext));
    } else {
        fn_8002C034(*(void **)gUiContext, *(void **)Unit_GetActiveItemPtr(*(void **)gUiContext));
    }
    if ((s8)lbl_80367275 == 0) {
        *(void **)(lbl_802EFD88 + 4) = lbl_80285050;
        *(void **)(lbl_802EFD88 + 4) = lbl_802853EC;
        lbl_80367275 = 1;
    }
    fn_8002EB54(lbl_802EFD88, arg0);
}

#pragma dont_inline on
void fn_8002FC64(u32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *Ui_GetColor(s32);
    void fn_8005C8B4(void *);
    u8 FileCache_IsReady(void *);
    void fn_8006EEFC(s32 *, void *);
    void FileCache_ReleaseSlot(s32 *);
    extern u8 gBattleState[];
    extern u8 gMapUiStrs[];
    s32 sp6C;
    s32 sp68;

    sp6C = *Ui_GetColor(1);
    if (arg0 != 0 && ((gBattleState[0x9D] >> 6) & 3) != 2) {
        fn_8005C8B4(gMapUiStrs + 0x11C);
        if (FileCache_IsReady(gMapUiStrs + 0x11C) != 0) {
            fn_8006EEFC(&sp68, gMapUiStrs + 0x11C);
            (void)arg1;
            (void)arg2;
            (void)arg3;
            (void)sp6C;
                          FileCache_ReleaseSlot(&sp68);
          }
      }
  }
  #pragma dont_inline reset
  
  void fn_80031508(s32 arg0) {
    extern u16 gUiContext[];
    extern u16 lbl_802EFCB8[];
    void fn_80029C08(s32);
    void fn_8002EB54(void *, s32);

    fn_80029C08(*(s32 *)gUiContext);
    fn_8002EB54(lbl_802EFCB8, arg0);
}

void fn_80031550(s32 arg0) {
    extern u16 gUiContext[];
    extern u16 lbl_802EFCB8[];
    void fn_80029E4C(s32);
    void fn_8002EB54(void *, s32);

    fn_80029E4C(*(s32 *)gUiContext);
    fn_8002EB54(lbl_802EFCB8, arg0);
}

void fn_80031598(s32 arg0) {
    extern u8 gUiContext[];
    extern u8 lbl_80285088[];

    u8 val2 = (u8)fn_8001DD04(*(s32 *)gUiContext);
    fn_8003CE88(*(s32 *)(gUiContext + 4), val2);
    Map_ShowMoveLimitView();
    Process_CreateChild(lbl_80285088, arg0);
}

void fn_800315F8(void) {
    void Map_HideMoveLimitView(void *);
    void fn_8014CB14(void *, void *);
    extern u8 gUiContext[];
    extern u8 gBattleState[];
    u8 *ctx = gUiContext;
    u8 *base = gBattleState;

    ctx[0xF] = (u8)(s32)*(f32 *)(base + 0x524);
    ctx[0x10] = (u8)(s32)*(f32 *)(base + 0x528);
    Map_HideMoveLimitView(ctx);
    fn_8014CB14(gBattleState, *(void **)gUiContext);
}

/* Confirm cursor tile if reachable in the move-cost map (A), or cancel (B). */
void MapUi_HandleMoveConfirm(void *proc) {
    void Ui_PlaySeCue(void *, s32);
    void Process_Goto(void *, s32);
    extern void *gPadInput;
    extern f32 gBattleState[];
    extern u8 gBattleMap[];
    extern u8 gMapUiStrs[];
    extern u8 gMapUiResult;
    s32 held;
    s32 pressed;
    f32 cursorY;
    f32 cursorX;
    s16 *moveCost;

    held = *(s32 *)((u8 *)gPadInput + 4);
    pressed = held & (*(s32 *)((u8 *)gPadInput + 8) ^ held);
    if (pressed & 0x100) {
        cursorY = gBattleState[0x528 / 4];
        cursorX = gBattleState[0x524 / 4];
        moveCost = (s16 *)(gBattleMap + 0x610e);
        if (moveCost[(s8)(s32)cursorX + ((s8)(s32)cursorY << 6)] >= 0) {
            Ui_PlaySeCue(gMapUiStrs + 0xFC, 0x64);
            gMapUiResult = 5;
            Process_Goto(proc, 0x63);
            return;
        }
    }
    if (pressed & 0x200) {
        gMapUiResult = 9;
        Process_Goto(proc, 0x63);
    }
}

void fn_80031748(s32 arg0) {
    void **UiCtx_GetItemSlot(void *);
    void fn_8002A084(void *, void *, void *);
    void fn_8002EB54(void *, s32);
    extern void *gUiContext[6];
    extern u8 lbl_8036726E;
    extern u8 lbl_80285050[];
    extern u8 lbl_80285348[];
    extern u8 lbl_802EFD7C[];
    void **ret;

    ret = UiCtx_GetItemSlot(gUiContext);
    fn_8002A084(gUiContext[0], *ret, gUiContext);
    if ((s8)lbl_8036726E == 0) {
        *(void **)(lbl_802EFD7C + 4) = lbl_80285050;
        *(void **)(lbl_802EFD7C + 4) = lbl_80285348;
        lbl_8036726E = 1;
    }
    fn_8002EB54(lbl_802EFD7C, arg0);
}

void fn_800317D4(s32 arg0) {
    extern u16 gUiContext[];
    extern u16 lbl_802EFCB8[];
    s32 *UiCtx_GetItemSlot(void *);
    void fn_8002A8CC(s32, s32);
    void fn_8002EB54(void *, s32);
    s32 *temp;

    temp = UiCtx_GetItemSlot(gUiContext);
    fn_8002A8CC(*(s32 *)gUiContext, *temp);
    fn_8002EB54(lbl_802EFCB8, arg0);
}

void fn_8003182C(s32 arg0) {
    void fn_8002A2BC(void *);
    void fn_8002EB54(void *, s32);
    extern void *gUiContext[6];
    extern u8 lbl_8036726D;
    extern u8 lbl_80285050[];
    extern u8 lbl_80285314[];
    extern u8 lbl_802EFD70[];

    fn_8002A2BC(gUiContext[0]);
    if ((s8)lbl_8036726D == 0) {
        *(void **)(lbl_802EFD70 + 4) = lbl_80285050;
        *(void **)(lbl_802EFD70 + 4) = lbl_80285314;
        lbl_8036726D = 1;
    }
    fn_8002EB54(lbl_802EFD70, arg0);
}

void fn_800318A8(s32 arg0) {
    extern u16 gUiContext[];
    extern u16 lbl_802EFCC4[];
    void fn_8002A2BC(s32);
    void fn_8002EB54(void *, s32);

    fn_8002A2BC(*(s32 *)gUiContext);
    fn_8002EB54(lbl_802EFCC4, arg0);
}

void fn_800318F0(s32 arg0) {
    void fn_8002A63C(void *);
    void fn_8002EB54(void *, s32);
    extern void *gUiContext[6];
    extern u8 lbl_8036726C;
    extern u8 lbl_80285050[];
    extern u8 lbl_802852E0[];
    extern u8 lbl_802EFD64[];

    fn_8002A63C(gUiContext[0]);
    if ((s8)lbl_8036726C == 0) {
        *(void **)(lbl_802EFD64 + 4) = lbl_80285050;
        *(void **)(lbl_802EFD64 + 4) = lbl_802852E0;
        lbl_8036726C = 1;
    }
    fn_8002EB54(lbl_802EFD64, arg0);
}

void fn_8003196C(s32 arg0) {
    void fn_8002A4F4(void *);
    void fn_8002EB54(void *, s32);
    extern void *gUiContext[6];
    extern u8 lbl_8036726B;
    extern u8 lbl_80285050[];
    extern u8 lbl_802852E0[];
    extern u8 lbl_802EFD58[];

    fn_8002A4F4(gUiContext[0]);
    if ((s8)lbl_8036726B == 0) {
        *(void **)(lbl_802EFD58 + 4) = lbl_80285050;
        *(void **)(lbl_802EFD58 + 4) = lbl_802852E0;
        lbl_8036726B = 1;
    }
    fn_8002EB54(lbl_802EFD58, arg0);
}

void fn_800319E8(s32 arg0) {
    void fn_8002A784(void *, u8 *);
    void fn_8002EB54(void *, s32);
    extern void *gUiContext[6];
    extern u8 lbl_8036726A;
    extern u8 lbl_80285050[];
    extern u8 lbl_802852E0[];
    extern u8 lbl_802EFD4C[];
    u8 sp8;

    sp8 = ((u8 *)gUiContext)[0x13];
    fn_8002A784(gUiContext[0], &sp8);
    if ((s8)lbl_8036726A == 0) {
        *(void **)(lbl_802EFD4C + 4) = lbl_80285050;
        *(void **)(lbl_802EFD4C + 4) = lbl_802852E0;
        lbl_8036726A = 1;
    }
    fn_8002EB54(lbl_802EFD4C, arg0);
}

void fn_80031A70(s32 arg0) {
    void fn_8002AE6C(void *);
    void fn_8002EB54(void *, s32);
    extern void *gUiContext[6];
    extern u8 lbl_80367269;
    extern u8 lbl_80285050[];
    extern u8 lbl_802852AC[];
    extern u8 lbl_802EFD40[];

    fn_8002AE6C(gUiContext[0]);
    if ((s8)lbl_80367269 == 0) {
        *(void **)(lbl_802EFD40 + 4) = lbl_80285050;
        *(void **)(lbl_802EFD40 + 4) = lbl_802852AC;
        lbl_80367269 = 1;
    }
    fn_8002EB54(lbl_802EFD40, arg0);
}

void fn_80031AEC(s32 arg0) {
    void **UiCtx_GetItemSlot(void *);
    void fn_8002AA34(void *, void *, void *);
    void fn_8002EB54(void *, s32);
    extern void *gUiContext[6];
    extern u8 lbl_80367268;
    extern u8 lbl_80285050[];
    extern u8 lbl_80285278[];
    extern u8 lbl_802EFD34[];
    void **ret;

    ret = UiCtx_GetItemSlot(gUiContext);
    fn_8002AA34(gUiContext[0], *ret, gUiContext);
    if ((s8)lbl_80367268 == 0) {
        *(void **)(lbl_802EFD34 + 4) = lbl_80285050;
        *(void **)(lbl_802EFD34 + 4) = lbl_80285278;
        lbl_80367268 = 1;
    }
    fn_8002EB54(lbl_802EFD34, arg0);
}

void fn_80031B78(s32 arg0) {
    extern u16 gUiContext[];
    extern u16 lbl_802EFCB8[];
    s32 *UiCtx_GetItemSlot(void *);
    void fn_8002AB9C(s32, s32);
    void fn_8002EB54(void *, s32);
    s32 *temp;

    temp = UiCtx_GetItemSlot(gUiContext);
    fn_8002AB9C(*(s32 *)gUiContext, *temp);
    fn_8002EB54(lbl_802EFCB8, arg0);
}

void fn_80031BD0(s32 arg0) {
    extern u16 gUiContext[];
    extern u16 lbl_802EFCB8[];
    void fn_8002B0A4(s32);
    void fn_8002EB54(void *, s32);

    fn_8002B0A4(*(s32 *)gUiContext);
    fn_8002EB54(lbl_802EFCB8, arg0);
}

void fn_80031C18(s32 arg0) {
    void fn_8002B2E8(void *);
    void fn_8002EB54(void *, s32);
    extern void *gUiContext[6];
    extern u8 lbl_80367267;
    extern u8 lbl_80285050[];
    extern u8 lbl_80285244[];
    extern u8 lbl_80285210[];
    extern u8 lbl_802EFD28[];

    fn_8002B2E8(gUiContext[0]);
    if ((s8)lbl_80367267 == 0) {
        *(void **)(lbl_802EFD28 + 4) = lbl_80285050;
        *(void **)(lbl_802EFD28 + 4) = lbl_80285244;
        *(void **)(lbl_802EFD28 + 4) = lbl_80285210;
        lbl_80367267 = 1;
    }
    fn_8002EB54(lbl_802EFD28, arg0);
}

void fn_80031CA0(s32 arg0) {
    void fn_8002B520(void *);
    void fn_8002EB54(void *, s32);
    extern void *gUiContext[6];
    extern u8 lbl_80367266;
    extern u8 lbl_80285050[];
    extern u8 lbl_80285244[];
    extern u8 lbl_802851DC[];
    extern u8 lbl_802EFD1C[];

    fn_8002B520(gUiContext[0]);
    if ((s8)lbl_80367266 == 0) {
        *(void **)(lbl_802EFD1C + 4) = lbl_80285050;
        *(void **)(lbl_802EFD1C + 4) = lbl_80285244;
        *(void **)(lbl_802EFD1C + 4) = lbl_802851DC;
        lbl_80367266 = 1;
    }
    fn_8002EB54(lbl_802EFD1C, arg0);
}

/* Build heal staff targets, store heal amount (item + Mag), open heal info select. */
void MapUi_BeginHealSelect(s32 parent) {
    void **UiCtx_GetItemSlot(void *);
    void fn_8002AD04(void *, void *, void *);
    s32 Item_GetHealAmount(void *);
    s32 Unit_GetMagAtk(void *);
    void fn_8002EB54(void *, s32);
    extern void *gUiContext[6];
    extern u8 sHealInfoInited;
    extern u8 lbl_80285050[];
    extern u8 gHealInfoVtbl[];
    extern u8 gHealInfoWin[];
    void **itemSlot;
    u8 *win;

    itemSlot = UiCtx_GetItemSlot(gUiContext);
    fn_8002AD04(gUiContext[0], *itemSlot, gUiContext);
    if ((s8)sHealInfoInited == 0) {
        *(void **)(gHealInfoWin + 4) = lbl_80285050;
        *(void **)(gHealInfoWin + 4) = gHealInfoVtbl;
        sHealInfoInited = 1;
    }
    itemSlot = UiCtx_GetItemSlot(gUiContext);
    win = gHealInfoWin;
    *(s32 *)(win + 0xC) = Item_GetHealAmount(*itemSlot);
    *(s32 *)(win + 0xC) = *(s32 *)(win + 0xC) + (s8)Unit_GetMagAtk(gUiContext[0]);
    fn_8002EB54(gHealInfoWin, parent);
}

void fn_80031DF8(s32 arg0) {
    void fn_8002C194(void *, u8);
    void fn_8002EB54(void *, s32);
    typedef struct {
        void *unit;
        u8 unk04[6];
        u8 unk0A;
    } Ctx;
    extern Ctx gUiContext;
    extern u8 lbl_80367264;
    extern u8 lbl_80285050[];
    extern u8 lbl_80285174[];
    extern u8 lbl_802EFD00[];

    fn_8002C194(gUiContext.unit, gUiContext.unk0A);
    if ((s8)lbl_80367264 == 0) {
        *(void **)(lbl_802EFD00 + 4) = lbl_80285050;
        *(void **)(lbl_802EFD00 + 4) = lbl_80285174;
        lbl_80367264 = 1;
    }
    fn_8002EB54(lbl_802EFD00, arg0);
}

void fn_80031E74(s32 arg0) {
    void fn_8002B758(void *);
    void fn_8002EB54(void *, s32);
    extern void *gUiContext[6];
    extern u8 lbl_80367263;
    extern u8 lbl_80285050[];
    extern u8 lbl_802EFCF4[];

    fn_8002B758(gUiContext[0]);
    if ((s8)lbl_80367263 == 0) {
        *(void **)(lbl_802EFCF4 + 4) = lbl_80285050;
        lbl_80367263 = 1;
    }
    fn_8002EB54(lbl_802EFCF4, arg0);
}

void fn_80031EE4(s32 arg0) {
    void fn_8002B89C(void *);
    void fn_8002EB54(void *, s32);
    extern void *gUiContext[6];
    extern u8 lbl_80367262;
    extern u8 lbl_80285050[];
    extern u8 lbl_80285244[];
    extern u8 lbl_80285140[];
    extern u8 lbl_802EFCE8[];

    fn_8002B89C(gUiContext[0]);
    if ((s8)lbl_80367262 == 0) {
        *(void **)(lbl_802EFCE8 + 4) = lbl_80285050;
        *(void **)(lbl_802EFCE8 + 4) = lbl_80285244;
        *(void **)(lbl_802EFCE8 + 4) = lbl_80285140;
        lbl_80367262 = 1;
    }
    fn_8002EB54(lbl_802EFCE8, arg0);
}

void fn_80031F6C(s32 arg0) {
    void fn_8002BAFC(void *, s32);
    void fn_8002EB54(void *, s32);
    extern void *gUiContext[6];
    extern u8 lbl_80367261;
    extern u8 lbl_80285050[];
    extern u8 lbl_80285244[];
    extern u8 lbl_8028510C[];
    extern u8 lbl_802EFCDC[];

    fn_8002BAFC(gUiContext[0], 2);
    if ((s8)lbl_80367261 == 0) {
        *(void **)(lbl_802EFCDC + 4) = lbl_80285050;
        *(void **)(lbl_802EFCDC + 4) = lbl_80285244;
        *(void **)(lbl_802EFCDC + 4) = lbl_8028510C;
        lbl_80367261 = 1;
    }
    fn_8002EB54(lbl_802EFCDC, arg0);
}

void fn_80031FF8(s32 arg0) {
    void fn_8002BAFC(void *, s32);
    void fn_8002EB54(void *, s32);
    extern void *gUiContext[6];
    extern u8 lbl_80367260;
    extern u8 lbl_80285050[];
    extern u8 lbl_80285244[];
    extern u8 lbl_8028510C[];
    extern u8 lbl_802EFCD0[];

    fn_8002BAFC(gUiContext[0], 1);
    if ((s8)lbl_80367260 == 0) {
        *(void **)(lbl_802EFCD0 + 4) = lbl_80285050;
        *(void **)(lbl_802EFCD0 + 4) = lbl_80285244;
        *(void **)(lbl_802EFCD0 + 4) = lbl_8028510C;
        lbl_80367260 = 1;
    }
    fn_8002EB54(lbl_802EFCD0, arg0);
}

void fn_80032084(void *win, void *slot) {
void Prim2D_Begin(void); void Prim2D_PrepareTex(void);
void Prim2D_SetTransform(f32,f32,f32,f32);
void Prim2D_SetColorByte(u8); void Prim2D_AddZ(f32);
void UnitInfo_DrawStatus(s32); void Ui_DrawRouteTex(s32,s32,s32);
u32 UnitRef_GetUnit(u32);
extern f32 gUnitInfoDrawScale,gUnitInfoDrawDepth,lbl_80368E34;
extern u8 gUiContext[];
#pragma cplusplus on
struct Obj { u8 pad[4]; virtual void getPos(s32 *,s32 *,s32 *)=0; };
s32 alpha,y,x;
s32 alpha2,y2,x2;
if(M2C_FIELD(slot,u32 *,0x40)!=0) {
if(M2C_FIELD(slot,u32 *,0x40)!=0) {
((Obj *)win)->getPos(&x,&y,&alpha);
Prim2D_Begin();
Prim2D_SetTransform((f32)(x+0x20),(f32)(y+0xb0),gUnitInfoDrawScale,gUnitInfoDrawDepth);
Prim2D_SetColorByte((u8)alpha); Prim2D_PrepareTex();
UnitInfo_DrawStatus(UnitRef_GetUnit(M2C_FIELD(slot,u32 *,0x40)));
Prim2D_Begin();
Prim2D_SetTransform((f32)(x+0x20),(f32)(y+0x30),gUnitInfoDrawScale,gUnitInfoDrawDepth);
Prim2D_PrepareTex();
UnitInfo_DrawStatus(M2C_FIELD(gUiContext,s32 *,0));
Prim2D_Begin(); Prim2D_SetColorByte(0xff); Prim2D_PrepareTex();
}
((Obj *)win)->getPos(&x2,&y2,&alpha2);
Prim2D_Begin(); Prim2D_AddZ(lbl_80368E34);
Prim2D_SetColorByte((u8)alpha2); Prim2D_PrepareTex();
Ui_DrawRouteTex(0x64,0x6a,0);
Prim2D_Begin(); Prim2D_SetColorByte(0xff); Prim2D_PrepareTex();
}
#pragma cplusplus reset
}

void fn_80032220(void *win, void *slot) {
void Prim2D_Begin(void); void Prim2D_PrepareTex(void);
void Prim2D_SetTransform(f32,f32,f32,f32);
void Prim2D_SetColorByte(u8); void Prim2D_AddZ(f32);
void UnitInfo_DrawStatus(s32); void Ui_DrawRouteTex(s32,s32,s32);
u32 UnitRef_GetUnit(u32);
extern f32 gUnitInfoDrawScale,gUnitInfoDrawDepth,lbl_80368E34;
extern u8 gUiContext[];
#pragma cplusplus on
struct Obj { u8 pad[4]; virtual void getPos(s32 *,s32 *,s32 *)=0; };
s32 alpha,y,x;
s32 alpha2,y2,x2;
if(M2C_FIELD(slot,u32 *,0x40)!=0) {
if(M2C_FIELD(slot,u32 *,0x40)!=0) {
((Obj *)win)->getPos(&x,&y,&alpha);
Prim2D_Begin();
Prim2D_SetTransform((f32)(x+0x20),(f32)(y+0xb0),gUnitInfoDrawScale,gUnitInfoDrawDepth);
Prim2D_SetColorByte((u8)alpha); Prim2D_PrepareTex();
UnitInfo_DrawStatus(UnitRef_GetUnit(M2C_FIELD(slot,u32 *,0x40)));
Prim2D_Begin();
Prim2D_SetTransform((f32)(x+0x20),(f32)(y+0x30),gUnitInfoDrawScale,gUnitInfoDrawDepth);
Prim2D_PrepareTex();
UnitInfo_DrawStatus(M2C_FIELD(gUiContext,s32 *,0));
Prim2D_Begin(); Prim2D_SetColorByte(0xff); Prim2D_PrepareTex();
}
((Obj *)win)->getPos(&x2,&y2,&alpha2);
Prim2D_Begin(); Prim2D_AddZ(lbl_80368E34);
Prim2D_SetColorByte((u8)alpha2); Prim2D_PrepareTex();
Ui_DrawRouteTex(0x64,0x6a,1);
Prim2D_Begin(); Prim2D_SetColorByte(0xff); Prim2D_PrepareTex();
}
#pragma cplusplus reset
}

#pragma cplusplus on
extern "C" void Prim2D_Begin(void);
extern "C" void Prim2D_PrepareTex(void);
extern "C" void Prim2D_SetTransform(f32, f32, f32, f32);
extern "C" void Prim2D_SetColorByte(u8);
extern "C" void UnitInfo_DrawBagPanel(void *);
extern "C" void UnitInfo_DrawBag(void *win, void *slot) {
    /* Draw unit-info bag panel (affiliation strip + items with equip marks) for the slot unit. */
    extern f32 gUnitInfoDrawScale;
    extern f32 gUnitInfoDrawDepth;
    struct Obj {
        u8 pad[4];
        virtual void getPos(s32 *, s32 *, s32 *) = 0;
    };
    s32 x;
    s32 y;
    s32 alpha;

    if (M2C_FIELD(slot, u32 *, 0x40) != 0) {
        ((Obj *)win)->getPos(&x, &y, &alpha);
        Prim2D_Begin();
        Prim2D_SetTransform((f32)(x + 0x20), (f32)(y + 0x30), gUnitInfoDrawScale, gUnitInfoDrawDepth);
        Prim2D_SetColorByte((u8)alpha);
        Prim2D_PrepareTex();
        UnitInfo_DrawBagPanel((void *)UnitRef_GetUnit(M2C_FIELD(slot, u32 *, 0x40)));
        Prim2D_Begin();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
    }
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void UnitInfo_DrawHealStats(s32, s32);
extern "C" void UnitInfo_DrawHeal(void *win, void *slot) {
    /* Draw the heal unit-info panel for the unit in slot. */
    extern f32 gUnitInfoDrawScale;
    extern f32 gUnitInfoDrawDepth;
    struct Obj {
        u8 pad[4];
        virtual void getPos(s32 *, s32 *, s32 *) = 0;
    };
    s32 x;
    s32 y;
    s32 alpha;

    if (M2C_FIELD(slot, u32 *, 0x40) != 0) {
        ((Obj *)win)->getPos(&x, &y, &alpha);
        Prim2D_Begin();
        Prim2D_SetTransform((f32)(x + 0x20), (f32)(y + 0x30), gUnitInfoDrawScale, gUnitInfoDrawDepth);
        Prim2D_SetColorByte((u8)alpha);
        Prim2D_PrepareTex();
        UnitInfo_DrawHealStats(UnitRef_GetUnit(M2C_FIELD(slot, u32 *, 0x40)), M2C_FIELD(win, s32 *, 0xC));
        Prim2D_Begin();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
    }
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void UnitInfo_DrawStatus(s32);
extern "C" void UnitInfo_DrawPair(s32);
extern "C" void Ui_DrawRouteTex(s32, s32, s32);
extern "C" void Prim2D_AddZ(f32);
extern "C" void UnitInfo_DrawDualSwap(void *win, void *slot) {
    /* Draw dual unit-info with status below and pair panel above (layout swap of UnitInfo_DrawDual). */
    extern f32 gUnitInfoDrawScale;
    extern f32 gUnitInfoDrawDepth;
    extern f32 lbl_80368E34;
    extern u8 gUiContext[];
    struct Obj {
        u8 pad[4];
        virtual void getPos(s32 *, s32 *, s32 *) = 0;
    };
    s32 x;
    s32 y;
    s32 alpha;

    if (M2C_FIELD(slot, u32 *, 0x40) != 0) {
        ((Obj *)win)->getPos(&x, &y, &alpha);
        Prim2D_Begin();
        Prim2D_SetTransform((f32)(x + 0x20), (f32)(y + 0x118), gUnitInfoDrawScale, gUnitInfoDrawDepth);
        Prim2D_SetColorByte((u8)alpha);
        Prim2D_PrepareTex();
        UnitInfo_DrawStatus(UnitRef_GetUnit(M2C_FIELD(slot, u32 *, 0x40)));
        Prim2D_Begin();
        Prim2D_SetTransform((f32)(x + 0x20), (f32)(y + 0x30), gUnitInfoDrawScale, gUnitInfoDrawDepth);
        Prim2D_PrepareTex();
        UnitInfo_DrawPair(M2C_FIELD(gUiContext, s32 *, 0));
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80368E34);
        Prim2D_PrepareTex();
        Ui_DrawRouteTex(0x64, 0xD2, 0);
        Prim2D_Begin();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
    }
}

#pragma cplusplus on
extern "C" void UnitInfo_DrawDual(void *win, void *slot) {
    /* Draw the selected unit's status panel, the UI-context panel, and an atlas icon. */
    extern f32 gUnitInfoDrawScale;
    extern f32 gUnitInfoDrawDepth;
    extern f32 lbl_80368E34;
    extern u8 gUiContext[];
    struct Obj {
        u8 pad[4];
        virtual void getPos(s32 *, s32 *, s32 *) = 0;
    };
    s32 x;
    s32 y;
    s32 alpha;
    s32 alpha2;
    s32 y2;
    s32 x2;

    if (M2C_FIELD(slot, u32 *, 0x40) != 0) {
        ((Obj *)win)->getPos(&x, &y, &alpha);
        Prim2D_Begin();
        Prim2D_SetTransform((f32)(x + 0x20), (f32)(y + 0xB0), gUnitInfoDrawScale, gUnitInfoDrawDepth);
        Prim2D_SetColorByte((u8)alpha);
        Prim2D_PrepareTex();
        UnitInfo_DrawPair(UnitRef_GetUnit(M2C_FIELD(slot, u32 *, 0x40)));
        Prim2D_Begin();
        Prim2D_SetTransform((f32)(x + 0x20), (f32)(y + 0x30), gUnitInfoDrawScale, gUnitInfoDrawDepth);
        Prim2D_PrepareTex();
        UnitInfo_DrawStatus(M2C_FIELD(gUiContext, s32 *, 0));
        Prim2D_Begin();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
        ((Obj *)win)->getPos(&x2, &y2, &alpha2);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_80368E34);
        Prim2D_SetColorByte((u8)alpha2);
        Prim2D_PrepareTex();
        Ui_DrawRouteTex(0x64, 0x6A, 1);
        Prim2D_Begin();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
    }
}
#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on
extern "C" void UnitInfo_DrawDualStatus(void *win, void *slot) {
    /* Draw status panels for the selected unit (lower) and the UI-context unit (upper). */
    extern f32 gUnitInfoDrawScale;
    extern f32 gUnitInfoDrawDepth;
    extern u8 gUiContext[];
    struct Obj {
        u8 pad[4];
        virtual void getPos(s32 *, s32 *, s32 *) = 0;
    };
    s32 x;
    s32 y;
    s32 alpha;

    if (M2C_FIELD(slot, u32 *, 0x40) != 0) {
        ((Obj *)win)->getPos(&x, &y, &alpha);
        Prim2D_Begin();
        Prim2D_SetTransform((f32)(x + 0x20), (f32)(y + 0xB0), gUnitInfoDrawScale, gUnitInfoDrawDepth);
        Prim2D_SetColorByte((u8)alpha);
        Prim2D_PrepareTex();
        UnitInfo_DrawStatus(UnitRef_GetUnit(M2C_FIELD(slot, u32 *, 0x40)));
        Prim2D_Begin();
        Prim2D_SetTransform((f32)(x + 0x20), (f32)(y + 0x30), gUnitInfoDrawScale, gUnitInfoDrawDepth);
        Prim2D_PrepareTex();
        UnitInfo_DrawStatus(M2C_FIELD(gUiContext, s32 *, 0));
        Prim2D_Begin();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
    }
}

#pragma cplusplus on
extern "C" void UnitInfo_DrawCombat(void *win, void *slot) {
    /* Draw combat/HP unit-info for slot, showing hit rate vs the UI-context unit. */
    extern f32 gUnitInfoDrawScale;
    extern f32 gUnitInfoDrawDepth;
    extern u32 gUiContext[];
    s32 UnitRef_GetUnit(u32);
    s32 Unit_CalcHitRate(s32, s32);
    void UnitInfo_DrawCombatStats(s32, s32);
    struct Obj {
        u8 pad[4];
        virtual void getPos(s32 *, s32 *, s32 *) = 0;
    };
    s32 x;
    s32 y;
    s32 alpha;
    s32 uiUnit;
    u8 hit;

    if (M2C_FIELD(slot, u32 *, 0x40) != 0) {
        ((Obj *)win)->getPos(&x, &y, &alpha);
        Prim2D_Begin();
        Prim2D_SetTransform((f32)(x + 0x20), (f32)(y + 0x30), gUnitInfoDrawScale, gUnitInfoDrawDepth);
        Prim2D_SetColorByte((u8)alpha);
        Prim2D_PrepareTex();
        uiUnit = gUiContext[0];
        hit = (u8)Unit_CalcHitRate(uiUnit, UnitRef_GetUnit(M2C_FIELD(slot, u32 *, 0x40)));
        UnitInfo_DrawCombatStats(UnitRef_GetUnit(M2C_FIELD(slot, u32 *, 0x40)), hit);
        Prim2D_Begin();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
    }
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void UnitInfo_DrawItems(void *win, void *slot) {
    /* Draw item/give unit-info for slot, marking slots the UI-context unit can receive. */
    extern f32 gUnitInfoDrawScale;
    extern f32 gUnitInfoDrawDepth;
    extern u32 gUiContext[];
    void UnitInfo_DrawItemStats(s32, s32);
    s32 UnitRef_GetUnit(u32);
    struct Obj {
        u8 pad[4];
        virtual void getPos(s32 *, s32 *, s32 *) = 0;
    };
    s32 x;
    s32 y;
    s32 alpha;
    s32 uiUnit;

    if (M2C_FIELD(slot, u32 *, 0x40) != 0) {
        ((Obj *)win)->getPos(&x, &y, &alpha);
        Prim2D_Begin();
        Prim2D_SetTransform((f32)(x + 0x20), (f32)(y + 0x30), gUnitInfoDrawScale, gUnitInfoDrawDepth);
        Prim2D_SetColorByte((u8)alpha);
        Prim2D_PrepareTex();
        uiUnit = gUiContext[0];
        UnitInfo_DrawItemStats(UnitRef_GetUnit(M2C_FIELD(slot, u32 *, 0x40)), uiUnit);
        Prim2D_Begin();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
    }
}
#pragma cplusplus reset

#pragma cplusplus reset
void *fn_80032B4C(void) {
    extern u16 gMapUiStrs[];
    return (u8 *)gMapUiStrs + 0x14F;
}

s32 fn_80032B5C(void *arg0, void *arg1) {
    extern u8 gUiContext[];
    u8 *src;
    u8 b0;
    u8 b1;

    src = *(u8 **)((u8 *)arg1 + 0x40);
    if (src == NULL) {
        return 0x10;
    }
    b1 = src[1];
    b0 = src[0];
    gUiContext[0xF] = b0;
    gUiContext[0x10] = b1;
    return 5;
}

#pragma cplusplus on
extern "C" void fn_80090688(void *, s32, s32);
/* Draw unit-info HP/staff panel for the slot unit (weapon type 7). */
extern "C" void UnitInfo_DrawStaff(void *win, void *slot) {
    extern f32 gUnitInfoDrawScale;
    extern f32 gUnitInfoDrawDepth;
    struct Obj {
        u8 pad[4];
        virtual void getPos(s32 *, s32 *, s32 *) = 0;
    };
    s32 x;
    s32 y;
    s32 alpha;
    void *unit;

    if (M2C_FIELD(slot, u32 *, 0x40) != 0) {
        ((Obj *)win)->getPos(&x, &y, &alpha);
        Prim2D_Begin();
        Prim2D_SetTransform((f32)(x + 0x20), (f32)(y + 0x30), gUnitInfoDrawScale, gUnitInfoDrawDepth);
        Prim2D_SetColorByte((u8)alpha);
        Prim2D_PrepareTex();
        unit = (void *)UnitRef_GetUnit(M2C_FIELD(slot, u32 *, 0x40));
        fn_80090688((void *)UnitRef_GetUnit(M2C_FIELD(slot, u32 *, 0x40)), 7, 7 - ((*(u8 *)((u8 *)unit + 0x1A6) >> 5) & 7));
        Prim2D_Begin();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
    }
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void UnitInfo_DrawInventoryPanel(void *);
extern "C" void UnitInfo_DrawInventory(void *win, void *slot) {
    /* Draw unit-info inventory panel (affiliation strip + held items) for the slot unit. */
    extern f32 gUnitInfoDrawScale;
    extern f32 gUnitInfoDrawDepth;
    struct Obj {
        u8 pad[4];
        virtual void getPos(s32 *, s32 *, s32 *) = 0;
    };
    s32 x;
    s32 y;
    s32 alpha;

    if (M2C_FIELD(slot, u32 *, 0x40) != 0) {
        ((Obj *)win)->getPos(&x, &y, &alpha);
        Prim2D_Begin();
        Prim2D_SetTransform((f32)(x + 0x20), (f32)(y + 0x30), gUnitInfoDrawScale, gUnitInfoDrawDepth);
        Prim2D_SetColorByte((u8)alpha);
        Prim2D_PrepareTex();
        UnitInfo_DrawInventoryPanel((void *)UnitRef_GetUnit(M2C_FIELD(slot, u32 *, 0x40)));
        Prim2D_Begin();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
    }
}
#pragma cplusplus reset
void *fn_80032D4C(void) {
    extern u16 gMapUiStrs[];
    return (u8 *)gMapUiStrs + 0x14F;
}

void *fn_80032D5C(void) {
    s32 Item_Get(u8);
    void UnitRef_Set(void *, s32);
    void *MapObjEvent_Find(void *, u8, u8, s32);
    extern u8 gUiContext[];
    extern u8 gMapObjEventList[];
    extern u8 lbl_80367278;
    u8 *p;
    void *temp;
    s32 val;

    p = gUiContext;
    temp = MapObjEvent_Find(gMapObjEventList, p[0xD], p[0xE], 7);
    val = Item_Get(*(u8 *)((u8 *)temp + 4));
    UnitRef_Set(&lbl_80367278, val);
    return &lbl_80367278;
}

#pragma cplusplus on
extern "C" void fn_80032DB4(void *arg0, void *arg1) {
    struct Obj {
        u8 pad[4];
        virtual void v0(s32 *, s32 *, s32 *) = 0;
    };
    s32 x;
    s32 y;
    s32 z;

    if (arg1 != NULL && M2C_FIELD(arg1, u32 *, 0x40) != 0 && UnitRef_GetUnit(M2C_FIELD(arg1, u32 *, 0x40)) != 0) {
        ((Obj *)arg0)->v0(&x, &y, &z);
        fn_8002FC64(UnitRef_GetUnit(M2C_FIELD(arg1, u32 *, 0x40)), x, y, z);
    }
}

extern "C" void fn_80032E3C(void *arg0, void *arg1) {
#pragma global_optimizer off
void fn_801848D8(void *,s8,s8,s32,s32);
void *UnitRef_GetUnit(void *);
void Unit_FaceToward(void *,void *,s32,s32);
void Battle_SetupPair(void *,void *,void *);
void fn_801A7528(void *,s32);
void fn_801A6F34(void *,u32);
extern u8 gUiContext[],gBattle[];
struct Obj { u8 pad[4]; virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0; virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0; virtual void v8()=0; virtual void v9()=0; virtual void v10()=0; virtual s32 get()=0; };
void *ref;
register void *unit;
register u8 *ctx=gUiContext;
u32 mode;
u8 *battle;
fn_801848D8(*(void **)ctx,(s8)((u8 *)arg1)[0x3E],(s8)((u8 *)arg1)[0x3F],8,0);
ref=*(void **)((u8 *)arg1+0x40);
if (ref && UnitRef_GetUnit(ref)) {
unit=*(void **)gUiContext;
Unit_FaceToward(UnitRef_GetUnit(ref),unit,8,0);
unit=*(void **)gUiContext;
Battle_SetupPair(gBattle,unit,UnitRef_GetUnit(ref));
fn_801A7528(gBattle,((Obj *)arg0)->get());
battle=gBattle;
mode=15;
if (gUiContext[8]==0x15) mode=0x15;
fn_801A6F34(battle,(u8)mode);
}
#pragma global_optimizer reset
}

#pragma cplusplus reset
void fn_80032F50(void) {
    void Unit_GetActiveItemPtr(void *);
    extern u8 gUiContext[24];
    Unit_GetActiveItemPtr(*(void **)gUiContext);
}

s32 fn_80032F7C(s32 arg0, void *arg1) {
    s32 fn_8002F480(s32, void *);
    u32 UnitRef_GetUnit(void *);
    extern u8 gUiContext[];
    void *temp_r31;
    u8 b0;
    u8 b1;
    u8 *p;
    s32 ret;

    temp_r31 = *(void **)((u8 *)arg1 + 0x40);
    if (temp_r31 == NULL) {
        return 0x10;
    }
    if (UnitRef_GetUnit(temp_r31) != 0U) {
        return fn_8002F480(arg0, arg1);
    }
    if (*(u8 *)((u8 *)temp_r31 + 3) != 0) {
        b1 = *(u8 *)((u8 *)temp_r31 + 1);
        b0 = *(u8 *)((u8 *)temp_r31 + 0);
        p = gUiContext;
        ret = 5;
        p[0xF] = b0;
        p[0x10] = b1;
        *(s32 *)(p + 4) = 0;
        return ret;
    }
    return 0;
}

void fn_80033024(void) {
    M2C_UNK Map_ShowMoveLimitView();
    Map_ShowMoveLimitView();
}

M2C_UNK *fn_80033044(void) {
    s32 Item_GetByIid(void *);
    M2C_UNK UnitRef_Set(M2C_UNK *, s32);
    extern u8 gMapUiStrs[];
    extern M2C_UNK lbl_80367278;
    UnitRef_Set(&lbl_80367278, Item_GetByIid(gMapUiStrs + 0xE5));
    return &lbl_80367278;
}

#include "common.h"

extern u16 lbl_80284E00[8];
extern u16 lbl_80284E20[8];
extern u32 gTargetList[502];
extern u8 gBattleMap[151280];
extern u8 gUnits[101760];
extern u32 gMapObjEventList; // size: 0x204

#include "common.h"
#include "global.h"

extern u16* Battle_str;
extern s32* gBattleState;
