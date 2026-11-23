/* Functions from 0x801833E8 to 0x801A2AB4, found by decomp-toolkit. */
#include "common.h"
#include "global.h"
typedef struct MoveSoundButtons { u32 words[7]; } MoveSoundButtons;
typedef struct MoveClassKind { u8 value; } MoveClassKind;

typedef struct ListNode {
    struct ListNode *prev;
    struct ListNode *next;
    void *val;
} ListNode;

typedef struct ListIter {
    ListNode *node;
} ListIter;

typedef struct List {
    s32 size;
} List;


static inline s32 CountUnitItemReferences(u8 *unit,u8 *target) {
void **Unit_GetHeldItemSlot(void *,s32);
s32 i; u8 *entry; void *item; s32 count=0;
if((*(u64 *)(target+0x38)&5ULL)!=0) {
for(i=count;i<4;i++) { entry=(u8 *)Unit_GetHeldItemSlot(unit,i);item=*(void **)entry; if(!item) break;
if(!(entry[5]&63) && target==item) count++;
}
} else {
for(i=0,entry=unit+0x1EC;i<4;i++,entry+=8) { item=*(void **)entry;if(!item) break;
if(!(entry[5]&63) && target==item) count++;
}
}
return count;
}

typedef struct PathHeightPoint { s32 index; f32 height; f32 rawHeight; } PathHeightPoint;
extern u16 gUnkGlobalVar_803306E0[];

#pragma optimization_level 4
#pragma inline auto

extern u16 lbl_8036719C;
extern u16 lbl_8036719E;
extern u32 lbl_803671A0;
extern u32 gCmScriptStatus;

extern f32 lbl_8036AE88;
extern f32 lbl_8036AE8C;
extern f64 lbl_8036AE90;
extern f64 lbl_8036AE98;

typedef struct {
    void *unk0;
    void *unk4;
    void *unk8;
    void *unkC;
    void *unk10;
    void *unk14;
    void *unk18;
    u32 unk1C;
    void *unk20;
    void *unk24;
    void *unk28;
    void *unk2C;
    void *unk30;
    u8 unk34;
    u8 unk35;
    u8 unk36;
    u8 unk37;
    s16 unk38;
    s16 unk3A;
    s16 unk3C;
    s16 unk3E;
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 unk43;
    s32 unk44;
    s32 unk48;
    f32 unk4C;
    f32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 unk64;
} StructEF0C;


extern u8 lbl_8036728B;
extern u16 lbl_80295C60[];
extern f32 lbl_8036AF74;
extern f64 lbl_8036AF78;

#pragma cplusplus on
extern "C" void fn_8017A000(void *);
extern "C" void *fn_80193950(void *, s16, s16, s16);
extern "C" u8 lbl_8029656C[];
extern "C" u16 gUiPanelVtbl[];
#pragma cplusplus reset

f32 fn_801833E8(void) {
    extern f32 lbl_8036ACC0;
    return lbl_8036ACC0;
}

s32 fn_801833F0(void) {
    return 0x1B0;
}

s32 fn_801833F8(void) {
    return 0x90;
}

s32 fn_80183400(void) {
    extern u8 gUiContext[];
    void fn_800919D8(void *);
    u8 *p;

    p = gUiContext;
    p[8] = 0;
    fn_800919D8(p);
    return 9;
}

#pragma use_lmw_stmw on
void fn_80183434(void *arg0, void *arg1) {
#pragma cplusplus on
struct Obj { u8 pad[4];
virtual void v0() = 0;
virtual void v1() = 0;
virtual void v2() = 0;
virtual void v3() = 0;
virtual void v4() = 0;
virtual void v5() = 0;
virtual void v6() = 0;
virtual void v7() = 0;
virtual void v8() = 0;
virtual void v9() = 0;
virtual void v10() = 0;
virtual void v11() = 0;
virtual void v12() = 0;
virtual void v13() = 0;
virtual void v14() = 0;
virtual void v15() = 0;
virtual void v16() = 0;
virtual void v17() = 0;
virtual s16 v18() = 0;
virtual void v19() = 0;
virtual void v20() = 0;
virtual void v21() = 0;
virtual void v22() = 0;
virtual void v23() = 0;
virtual void v24() = 0;
virtual void v25() = 0;
virtual void v26() = 0;
virtual void v27() = 0;
virtual void v28() = 0;
virtual void v29() = 0;
};
s32 Text_MeasureHeight(s32, f32);
void fn_8008AB7C(s32,s32,s32,s32,s32,s32,s32);
void fn_8008C1D8(s32,s32,s32,s32,s32);
void Prim2D_Begin(void);
void Prim2D_AddZ(f32);
void Prim2D_PrepareTex(void);
s32 flag;
s32 n = *(s8*)((u8*)arg1+0x60);
((Obj*)arg0)->v29();
fn_8008C1D8(0,0,0x90,(n<<5)+0x20,3);
if (*(s16*)((u8*)arg1+0x3A)>=5) {
Prim2D_Begin(); Prim2D_AddZ(-0.1f); Prim2D_PrepareTex();
flag=0;
if (!*(u8*)((u8*)arg1+0x2D) && !*(u8*)((u8*)arg1+0x2E)) flag=1;
fn_8008AB7C(((Obj*)arg0)->v18()/2, *(s16*)((u8*)arg1+0x3A)+Text_MeasureHeight(-1,1.0f)/2, (s32)(0.9f*((Obj*)arg0)->v18()),0x18,0x19,0x4B,flag);
Prim2D_Begin(); Prim2D_AddZ(0.1f); Prim2D_PrepareTex();
}
#pragma cplusplus reset
}
#pragma use_lmw_stmw reset
void fn_80183584(void) {
    extern u8 lbl_803681F0;
    extern u8 lbl_80278BB8[];

    if (lbl_803681F0 == 0x32) {
        Msg_Expand(&lbl_80278BB8[0x129]);
        return;
    }
    Msg_Expand(&lbl_80278BB8[0x12F]);
}

void fn_801835D0(void) {
    extern u8 lbl_803681F0;
    extern u8 lbl_80278BB8[];

    if (lbl_803681F0 == 0x32) {
        Msg_Expand(&lbl_80278BB8[0x135]);
        return;
    }
    Msg_Expand(&lbl_80278BB8[0x13B]);
}

s32 fn_8018361C(void) {
    return 4;
}

void fn_80183624(void *arg0) {
    u8 *BattleState_GetFactionInfo(void *, u8);
    s32 *Ui_GetColor(u8);
    void Prim2D_SetColorPacked(s32 *);
    extern u8 gBattleState[];
    extern u8 lbl_803681F0;
    s32 sp8;
    void *table;
    u8 *temp;
    u8 saved;
    s32 mode;

    table = gBattleState;
    mode = 3;
    if (lbl_803681F0 == 0x32) {
        mode = 0;
    }
    temp = BattleState_GetFactionInfo(table, (u8)mode);
    if (temp != NULL) {
        saved = *temp;
#pragma cplusplus on
        struct Obj {
            virtual void v00() = 0;
            virtual void v01() = 0;
            virtual void v02() = 0;
            virtual void v03() = 0;
            virtual void v04() = 0;
            virtual void v05() = 0;
            virtual void v06() = 0;
            virtual void v07() = 0;
            virtual void v08() = 0;
            virtual void v09() = 0;
            virtual void v10() = 0;
            virtual void v11() = 0;
            virtual void v12() = 0;
            virtual void v13() = 0;
            virtual void v14() = 0;
            virtual void v15() = 0;
            virtual void v16() = 0;
            virtual void v17() = 0;
            virtual void v18() = 0;
            virtual u8 v19() = 0;
        };
        if (saved == ((Obj *)arg0)->v19()) {
#pragma cplusplus reset
            mode = 6;
            if (lbl_803681F0 == 0x32) {
                mode = 7;
            }
            sp8 = *Ui_GetColor((u8)mode);
            Prim2D_SetColorPacked(&sp8);
        }
    }
}

#pragma cplusplus on
extern "C" s32 fn_801836D4(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1(u8 *) = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14() = 0;
        virtual void v15() = 0;
        virtual void v16() = 0;
        virtual void v17() = 0;
        virtual void v18() = 0;
        virtual s32 v19() = 0;
    };
    extern u8 gUiContext[];
    void fn_80091A1C(void);

    gUiContext[0x14] = (s8) ((Obj *)arg0)->v19();
    ((Obj *)arg0)->v1(gUiContext);
    fn_80091A1C();
    return 6;
}
#pragma cplusplus reset
void fn_80183734(void) {
    extern u8 lbl_803681F0;
    extern u8 lbl_80278BB8[];

    if (lbl_803681F0 == 0x32) {
        Msg_Expand(&lbl_80278BB8[0x155]);
        return;
    }
    Msg_Expand(&lbl_80278BB8[0x15B]);
}

void fn_80183780(void) {
    extern u8 lbl_803681F0;
    extern u8 lbl_80278BB8[];

    if (lbl_803681F0 == 0x32) {
        Msg_Expand(&lbl_80278BB8[0x161]);
        return;
    }
    Msg_Expand(&lbl_80278BB8[0x167]);
}

s32 fn_801837CC(void) {
    return 3;
}

void fn_801837D4(void) {
    extern u8 lbl_803681F0;
    extern u8 lbl_80278BB8[];

    if (lbl_803681F0 == 0x32) {
        Msg_Expand(&lbl_80278BB8[0x16D]);
        return;
    }
    Msg_Expand(&lbl_80278BB8[0x173]);
}

void fn_80183820(void) {
    extern u8 lbl_803681F0;
    extern u8 lbl_80278BB8[];

    if (lbl_803681F0 == 0x32) {
        Msg_Expand(&lbl_80278BB8[0x179]);
        return;
    }
    Msg_Expand(&lbl_80278BB8[0x17F]);
}

s32 fn_8018386C(void) {
    return 0;
}

void fn_80183874(void) {
    extern u16 lbl_80278BB8[];
    Msg_Expand((u8 *)lbl_80278BB8 + 0x185);
}

void fn_801838A0(void) {
    extern u8 lbl_80278BB8[];
    Msg_Expand(&lbl_80278BB8[0x18B]);
}

s32 fn_801838CC(void) {
    return 1;
}

s32 fn_801838D4(void) {
    extern u8 lbl_803681F0;
    return lbl_803681F0 == 0x33 ? 0 : 3;
}

void fn_801838F4(void) {
    extern u8 lbl_80278BB8[];
    Msg_Expand(&lbl_80278BB8[0x191]);
}

void fn_80183920(void) {
    extern u8 lbl_80278BB8[];
    Msg_Expand(&lbl_80278BB8[0x197]);
}

s32 fn_8018394C(void) {
    return 2;
}

s32 fn_80183954(void) { extern u8 lbl_803681F0; return lbl_803681F0 == 0x32 ? 0 : 3; }

#pragma opt_common_subs off
s32 fn_80183974(void) {
    u32 fn_8000C0C0(void *);
    extern u8 lbl_80295A00[];
    u8 *base;

    base = lbl_80295A00;
    if (fn_8000C0C0(base) != 0) {
        return 1;
    }
    if (fn_8000C0C0(base + 0x78) != 0) {
        return 1;
    }
    if (fn_8000C0C0(base + 0x98) != 0) {
        return 1;
    }
    if (fn_8000C0C0(base + 0xC0) != 0) {
        return 1;
    }
    if (fn_8000C0C0(base + 0x110) != 0) {
        return 1;
    }
    if (fn_8000C0C0(base + 0xE8) != 0) {
        return 1;
    }
    if (fn_8000C0C0(base + 0x20) != 0) {
        return 1;
    }
    return fn_8000C0C0(base + 0x3F0) != 0;
}
#pragma opt_common_subs reset
extern u16 E_MuFade_script[36];
s32 fn_80183A5C(void) {
    return Process_Find(&E_MuFade_script) != 0;
}

void fn_80183A90(s32 arg0) {
    void fn_8004FE98(s32, s32);
    fn_8004FE98(arg0, 0);
}

void MuEvent_Create(s32 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *Process_CreateEx(void *, s32, s32);
    extern u8 lbl_80295D1C[];
    void *temp_r3;

    temp_r3 = Process_CreateEx(lbl_80295D1C, arg4, arg2);
    *(s16 *)((u8 *)temp_r3 + 0x38) = arg1;
    *(s32 *)((u8 *)temp_r3 + 0x30) = arg0;
    *(s32 *)((u8 *)temp_r3 + 0x3C) = arg2;
    *(s32 *)((u8 *)temp_r3 + 0x40) = arg3;
}

void MuDead_Start(s32 arg0, s32 arg1) {
    extern u8 E_MuDead_script[];
    void *Process_CreateEx(u8 *, s32);
    s32 *obj;
    obj = (s32 *)Process_CreateEx(E_MuDead_script, arg1);
    obj[0x30 / 4] = arg0;
}

void *fn_80183B5C(void *arg0, void *arg1) {
    void *Process_CreateEx(void *, void *);
    u8 fn_800AA188(void);
    extern u16 lbl_80295D8C[];
    void *temp_r31;

    temp_r31 = Process_CreateEx(lbl_80295D8C, arg1);
    *(void **)((u8 *)temp_r31 + 0x30) = arg0;
    *((u8 *)temp_r31 + 0x3D) = 0;
    *((u8 *)temp_r31 + 0x3C) = 1;
    *((u8 *)temp_r31 + 0x3E) = 0;
    if (*(s32 *)((u8 *)arg0 + 0x1A0) & 0x010000DC) {
        *((u8 *)temp_r31 + 0x3C) = 0;
    }
    if (fn_800AA188() == 0) {
        *((u8 *)temp_r31 + 0x3C) = 0;
    }
    return temp_r31;
}

void *fn_80183BE4(void *arg0, void *arg1) {
    void *Process_CreateEx(void *, void *);
    u8 fn_800AA188(void);
    extern u16 lbl_80295D8C[];

    void *temp_r31;

    temp_r31 = Process_CreateEx(lbl_80295D8C, arg1);
    *(void **)((u8 *)temp_r31 + 0x30) = arg0;
    *((u8 *)temp_r31 + 0x3D) = 0;
    *((u8 *)temp_r31 + 0x3C) = 1;
    *((u8 *)temp_r31 + 0x3E) = 1;
    if (*(s32 *)((u8 *)arg0 + 0x1A0) & 0x010000DC) {
        *((u8 *)temp_r31 + 0x3C) = 0;
    }
    if (fn_800AA188() == 0) {
        *((u8 *)temp_r31 + 0x3C) = 0;
    }
    return temp_r31;
}

#pragma use_lmw_stmw on
void *fn_80183C6C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void *Process_CreateEx(void *, s32);
    f32 Map_SampleHeightRaw(void *, f32, f32);

    extern u8 lbl_80295B38[];
    extern u8 gBattleMap[];
    extern f32 gHalf;
    extern f64 lbl_8036ACE0;

    u8 *proc;
    f32 x;
    f32 y;

    proc = (u8 *)Process_CreateEx(lbl_80295B38, arg5);

    *(void **)(proc + 0x30) = arg0;

    x = gHalf + (f32)arg1;
    y = gHalf + (f32)arg2;

    *(f32 *)(proc + 0x34) = x;
    *(f32 *)(proc + 0x38) = y;

    *(f32 *)(proc + 0x3C) = Map_SampleHeightRaw(
        gBattleMap,
        *(f32 *)(proc + 0x34),
        *(f32 *)(proc + 0x38)
    );

    x = gHalf + (f32)arg3;
    y = gHalf + (f32)arg4;

    *(f32 *)(proc + 0x40) = x;
    *(f32 *)(proc + 0x44) = y;

    *(f32 *)(proc + 0x48) = Map_SampleHeightRaw(
        gBattleMap,
        *(f32 *)(proc + 0x40),
        *(f32 *)(proc + 0x44)
    );

    return proc;
}
#pragma use_lmw_stmw reset
void fn_80183D7C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *Process_CreateEx(void *, s32, s32);
    extern u8 lbl_80295CE4[];
    void *temp_r3;

    temp_r3 = Process_CreateEx(lbl_80295CE4, arg4, arg2);
    *(s32 *)((u8 *)temp_r3 + 0x30) = arg0;
    *(s32 *)((u8 *)temp_r3 + 0x34) = arg1;
    *(s32 *)((u8 *)temp_r3 + 0x44) = arg2;
    *(s32 *)((u8 *)temp_r3 + 0x48) = arg3;
}

void fn_80183DEC(s32 arg0, s32 arg1, s32 arg2) {
    void *Process_CreateEx(void *, s32);
    extern u8 lbl_80295CAC[];
    void *proc;

    proc = Process_CreateEx(lbl_80295CAC, arg2);
    M2C_FIELD(proc, s32 *, 0x30) = arg0;
    M2C_FIELD(proc, s32 *, 0x34) = arg1;
}

#pragma use_lmw_stmw on
void fn_80183E3C(s32 arg0, s32 arg1, s32 arg2, s8 arg3, s8 arg4, s32 arg5) {
    void *Process_CreateEx(void *, s32);
    extern u16 lbl_80295C60[];
    void *temp_r3;

    temp_r3 = Process_CreateEx(lbl_80295C60, arg5);
    *(s32 *)((u8 *)temp_r3 + 0x30) = arg0;
    *(s32 *)((u8 *)temp_r3 + 0x34) = 0;
    *((u8 *)temp_r3 + 0x3A) = (u8)arg3;
    *((u8 *)temp_r3 + 0x3B) = (u8)arg4;
    *(s32 *)((u8 *)temp_r3 + 0x40) = arg1;
    *(s32 *)((u8 *)temp_r3 + 0x44) = arg2;
    *((u8 *)temp_r3 + 0x48) = 0;
    *((u8 *)temp_r3 + 0x49) = 0;
}
#pragma use_lmw_stmw reset
void fn_80183EAC(s32 arg0, s32 arg1, s8 arg2, s8 arg3, s32 arg4) {
    void *Process_CreateEx(void *, s32);
    extern u16 lbl_80295C60[];
    void *temp_r3;

    temp_r3 = Process_CreateEx(lbl_80295C60, arg4);
    *(s32 *)((u8 *)temp_r3 + 0x30) = arg0;
    *(s32 *)((u8 *)temp_r3 + 0x34) = arg1;
    *((u8 *)temp_r3 + 0x3A) = (u8)arg2;
    *((u8 *)temp_r3 + 0x3B) = (u8)arg3;
    *(s32 *)((u8 *)temp_r3 + 0x40) = 0;
    *(s32 *)((u8 *)temp_r3 + 0x44) = 0;
    *((u8 *)temp_r3 + 0x48) = 0;
    *((u8 *)temp_r3 + 0x49) = 0;
}

void *MoveAnim_BindMapPath(void *unit, void *parent) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void MoveAnim_MatchUnit(void *, void *);
    void *Process_CreateChild(void *, void *);
    void *fn_800C45B8(s32, void *, s32);
    void Unit_SetModelAlpha(void *, s32);
    void MoveAnim_BuildPathHeights(void *);
    u8 *BattleMap_GetPath(void *);
    extern u8 gMoveAnimClass[];
    extern u8 MoveAnim_str[];
    extern u8 gBattleMap[];
    void *search[14];
    u8 *anim;
    s32 i;
    s32 count;
    s32 tile;
    u8 flags;
    u8 *path;

    /* Find or create a MoveAnim for unit and append the current battle-map path. */
    path = BattleMap_GetPath(gBattleMap);
    search[12] = unit;
    search[13] = 0;
    GfxEnt_ForEachKey(gMoveAnimClass, MoveAnim_MatchUnit, search);
    anim = search[13];
    if (anim == 0) {
        anim = Process_CreateChild(gMoveAnimClass, parent);
        *(void **)(anim + 0x30) = unit;
        *(u16 *)(anim + 0x52) = 0x40;
        *(void **)(anim + 0x54) = fn_800C45B8(-128, (void *)((u32)MoveAnim_str + 0x1A9), 0);
        anim[0x59] = 0;
        anim[0x5A] = 16;
        *(s8 *)(anim + 0x6A) = -1;
        *(void **)(anim + 0x6C) = fn_800C45B8(-1536, (char *)((u8 *)MoveAnim_str + 0x1A9), 0);
        if (*(u16 *)(anim + 0x52) & 16) {
            Unit_SetModelAlpha(unit, 0);
        }
        if ((*(u8 **)((u8 *)unit + 0x18C))[0x42] == 9) {
            *(u16 *)(anim + 0x52) |= 0x8000;
        }
        tile = (s32)*(f32 *)((u8 *)unit + 4);
        anim[0x40] = tile;
        anim[0x42] = tile;
        tile = (s32)*(f32 *)((u8 *)unit + 8);
        anim[0x41] = tile;
        anim[0x43] = tile;
    }
    if (path == 0) {
        count = 0;
    } else {
        u8 *q;
        count = 0;
        q = path;
        for (;;) {
            if (*q == 16) {
                break;
            }
            count++;
            q++;
        }
    }
    for (i = 0; i < count; i++) {
        (*(u8 **)(anim + 0x54))[i + anim[0x59]] = *path;
        anim[0x5A] = *path++;
    }
    (*(u8 **)(anim + 0x54))[i + anim[0x59]] = 16;
    flags = *(u16 *)(anim + 0x52) & 15;
    if (flags) {
        anim[0x5A] = flags;
    }
    anim[0x59] += count;
    MoveAnim_BuildPathHeights(anim);
    return anim;
}

#pragma opt_common_subs off
#pragma use_lmw_stmw on
/* Find or create a MoveAnim for unit and append the given path steps. */
void *MoveAnim_BindPath(void *unit, u8 *path, u16 flagsIn, void *parent) {
void GfxEnt_ForEachKey(void *,void *,void *); void MoveAnim_MatchUnit(void *,void *);
void *Process_CreateChild(void *,void *); void *fn_800C45B8(s32,void *,s32);
void Unit_SetModelAlpha(void *,s32); void MoveAnim_BuildPathHeights(void *);
extern u8 gMoveAnimClass[],MoveAnim_str[];
void *search[14];
u8 *anim; s32 i; u8 *p; s32 count; s32 tile; u8 flags;
search[12]=unit; search[13]=0;
GfxEnt_ForEachKey(gMoveAnimClass,MoveAnim_MatchUnit,search);
anim=search[13];
if(anim==0) {
anim=Process_CreateChild(gMoveAnimClass,parent);
*(void **)(anim+0x30)=unit;
*(u16 *)(anim+0x52)=flagsIn;
*(void **)(anim+0x54)=fn_800C45B8(-128,MoveAnim_str+0x1A9,0);
anim[0x59]=0;anim[0x5A]=16;*(s8 *)(anim+0x6A)=-1;
*(void **)(anim+0x6C)=fn_800C45B8(-1536,MoveAnim_str+0x1A9,0);
if(*(u16 *)(anim+0x52)&16) Unit_SetModelAlpha(unit,0);
if((*(u8 **)((u8 *)unit+0x18C))[0x42]==9) *(u16 *)(anim+0x52)|=0x8000;
tile=(s32)*(f32 *)((u8 *)unit+4); anim[0x40]=tile;anim[0x42]=tile;
tile=(s32)*(f32 *)((u8 *)unit+8); anim[0x41]=tile;anim[0x43]=tile;
}
p=path;
if(path==0) count=0;
else {u8 *q;count=0;q=path;for(;;) {if(*q==16) break; count++;q++;}}
for(i=0;i<count;i++) {
(*(u8 **)(anim+0x54))[i+anim[0x59]]=*p;anim[0x5A]=*p++;
}
(*(u8 **)(anim+0x54))[i+anim[0x59]]=16;
flags=*(u16 *)(anim+0x52)&15;
if(flags) anim[0x5A]=flags;
anim[0x59]+=count;MoveAnim_BuildPathHeights(anim);return anim;
}
#pragma optimization_level 3
void fn_80184578(s32 arg0, u8 *arg1, u32 arg2) {
    void fn_8000A388(void *, void *, void *);
    void *fn_8000CAF0(void *, u32);
    void fn_80185078(void *, void *);
    extern u8 lbl_80295B64[];
    u8 sp8[0x34];
    u32 var_r31;
    void *temp_r3;
    u8 a;
    u8 d;
    u8 c;
    u8 b;

    var_r31 = arg2;
    *(s32 *)(sp8 + 0x30) = arg0;
    fn_8000A388(lbl_80295B64, fn_80185078, sp8);
    if (var_r31 == 0U) {
        var_r31 = 3U;
    }
    temp_r3 = fn_8000CAF0(lbl_80295B64, var_r31);
    *(s32 *)((u8 *)temp_r3 + 0x30) = arg0;
    a = arg1[0];
    b = arg1[1];
    ((u8 *)temp_r3)[0x34] = a;
    c = arg1[2];
    ((u8 *)temp_r3)[0x35] = b;
    d = arg1[3];
    ((u8 *)temp_r3)[0x36] = c;
    ((u8 *)temp_r3)[0x37] = d;
}
#pragma optimization_level reset
void fn_80184618(s32 arg0, u32 arg1) {
 void GfxEnt_ForEachKey(void *, void *, void *);
 void *Process_Create(void *, u32);
 void MuFade_UnlinkSame(void *, void *);
 extern u8 E_MuFlag_script[];
 u8 sp8[0x34];
 u32 parent=arg1;
 s32 value=arg0;
 void *p;
 *(s32 *)(sp8+0x30)=value;
 GfxEnt_ForEachKey(E_MuFlag_script, MuFade_UnlinkSame, sp8);
 if (!parent) parent=3;
 p=Process_Create(E_MuFlag_script, parent);
 *(s32 *)((u8 *)p+0x30)=value;
}

/* Unlink any existing E_MuFlash for this unit, then start a new flash (palette index, duration). */
void *Mu_StartFlash(s32 unit, s32 colorIdx, s32 duration, u32 priority) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_Create(void *, u32);
    s32 Mu_GetFlashColor(s32);
    void MuFade_UnlinkSame(void *, void *);
    extern u8 E_MuFlash_script[];
    u8 key[0x44];
    u32 color;
    u32 prio;
    void *proc;
    u8 *p;

    prio = priority;
    M2C_FIELD(key, void **, 0x30) = (void *)unit;
    GfxEnt_ForEachKey(E_MuFlash_script, MuFade_UnlinkSame, key);
    if (prio == 0U) {
        prio = 3U;
    }
    proc = Process_Create(E_MuFlash_script, prio);
    M2C_FIELD(proc, s32 *, 0x30) = unit;
    M2C_FIELD(proc, s32 *, 0x40) = duration;
    color = Mu_GetFlashColor(colorIdx);
    p = proc;
    p[0x38] = ((u8 *)&color)[0];
    p[0x39] = ((u8 *)&color)[1];
    p[0x3A] = ((u8 *)&color)[2];
    p[0x3B] = ((u8 *)&color)[3];
    return p;
}

extern u16 *gUnitArray;
void *fn_80184750(void *unit, u32 dir, s32 frames, s32 priority) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, s32);
    void MuFade_UnlinkSame(void *, void *);
    extern u16 E_MuFade_script[36];
    u8 sp8[0x34];
    s32 tmp;
    s16 angle;
    void *proc;

    switch ((u8)dir) {
    case 4:
        tmp = 0;
        break;
    case 6:
        tmp = 0x2D;
        break;
    case 2:
        tmp = 0x5A;
        break;
    case 10:
        tmp = 0x87;
        break;
    case 8:
        tmp = 0xB4;
        break;
    case 9:
        tmp = 0xE1;
        break;
    case 1:
        tmp = 0x10E;
        break;
    case 5:
        tmp = 0x13B;
        break;
    case 0:
    case 3:
    case 7:
    default:
        tmp = 0;
        break;
    }
    angle = (s16)tmp;

    M2C_FIELD(sp8, void **, 0x30) = unit;
    GfxEnt_ForEachKey(&E_MuFade_script, MuFade_UnlinkSame, sp8);
    if ((f32)angle == ((f32)M2C_FIELD(unit, s16 *, 0x15C) / 50.0f)) {
        return NULL;
    }
    if (frames <= 0) {
        M2C_FIELD(unit, s16 *, 0x15C) = (s16)(50.0f * (f32)angle);
        return NULL;
    }
    proc = Process_CreateEx(&E_MuFade_script, priority);
    M2C_FIELD(proc, void **, 0x30) = unit;
    M2C_FIELD(proc, f32 *, 0x34) = (f32)angle;
    M2C_FIELD(proc, s32 *, 0x38) = frames;
    return proc;
}

void *fn_801848D8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void fn_8000A388(void *, void *, void *);
    void *fn_8000CA64(void *, s32);
    f32 fn_8004BDA8(f32, f32, f32);
    void fn_80185078(void *, void *);
    extern u16 lbl_80295A78[36];
    extern f32 lbl_8036ACD8;
    u8 sp8[0x34];
    f32 temp_f31;
    void *temp_r3;

    temp_f31 = fn_8004BDA8(lbl_8036ACD8 + (f32)arg1, lbl_8036ACD8 + (f32)arg2, lbl_8036ACD8);
    M2C_FIELD(sp8, void **, 0x30) = arg0;
    fn_8000A388(&lbl_80295A78, fn_80185078, sp8);
    if (temp_f31 == ((f32)M2C_FIELD(arg0, s16 *, 0x15C) / 50.0f)) {
        return NULL;
    }
    if (arg3 <= 0) {
        M2C_FIELD(arg0, s16 *, 0x15C) = (s16)(50.0f * temp_f31);
        return NULL;
    }
    temp_r3 = fn_8000CA64(&lbl_80295A78, arg4);
    M2C_FIELD(temp_r3, void **, 0x30) = arg0;
    M2C_FIELD(temp_r3, f32 *, 0x34) = temp_f31;
    M2C_FIELD(temp_r3, s32 *, 0x38) = arg3;
    return temp_r3;
}

void *Unit_FaceToward(void *unit, u32 target, s32 frames, s32 priority) {
    /* Fade unit facing (0x15C) toward target unit; snap if frames<=0. */
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, s32);
    f32 Unit_GetAngleTo(void);
    void MuFade_UnlinkSame(void *, void *);
    extern u16 E_MuFade_script[36];
    u8 sp8[0x34];
    f32 angle;
    void *proc;

    if (target == 0U) {
        return NULL;
    }
    angle = Unit_GetAngleTo();
    M2C_FIELD(sp8, void **, 0x30) = unit;
    GfxEnt_ForEachKey(&E_MuFade_script, MuFade_UnlinkSame, sp8);
    if (angle == ((f32)M2C_FIELD(unit, s16 *, 0x15C) / 50.0f)) {
        return NULL;
    }
    if (frames <= 0) {
        M2C_FIELD(unit, s16 *, 0x15C) = (s16)(50.0f * angle);
        return NULL;
    }
    proc = Process_CreateEx(&E_MuFade_script, priority);
    M2C_FIELD(proc, void **, 0x30) = unit;
    M2C_FIELD(proc, f32 *, 0x34) = angle;
    M2C_FIELD(proc, s32 *, 0x38) = frames;
    return proc;
}

void *Unit_FadeFacing(void *unit, s32 frames, s32 priority, f32 angle) {
    /* Fade unit facing (0x15C) toward angle; snap if frames<=0. */
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, s32);
    void MuFade_UnlinkSame(void *, void *);
    extern u16 E_MuFade_script[36];
    u8 sp8[0x34];
    void *proc;

    M2C_FIELD(sp8, void **, 0x30) = unit;
    GfxEnt_ForEachKey(&E_MuFade_script, MuFade_UnlinkSame, sp8);
    if (angle == ((f32)M2C_FIELD(unit, s16 *, 0x15C) / 50.0f)) {
        return NULL;
    }
    if (frames <= 0) {
        M2C_FIELD(unit, s16 *, 0x15C) = (s16)(50.0f * angle);
        return NULL;
    }
    proc = Process_CreateEx(&E_MuFade_script, priority);
    M2C_FIELD(proc, void **, 0x30) = unit;
    M2C_FIELD(proc, f32 *, 0x34) = angle;
    M2C_FIELD(proc, s32 *, 0x38) = frames;
    return proc;
}

void Mu_StartTransfer(s32 arg0, s32 arg1, s32 arg2, u32 arg3) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_Create(void *, u32);
    void MuFade_UnlinkSame(void *, void *);
    extern u8 E_MuTransfer_script[];
    u8 sp8[0x34];
    u32 var_r31;
    void *temp_r3;

    var_r31 = arg3;
    M2C_FIELD(sp8, void **, 0x30) = (void *)arg0;
    GfxEnt_ForEachKey(E_MuTransfer_script, MuFade_UnlinkSame, sp8);
    if (var_r31 == 0U) {
        var_r31 = 3U;
    }
    temp_r3 = Process_Create(E_MuTransfer_script, var_r31);
    M2C_FIELD(temp_r3, s32 *, 0x30) = arg0;
    M2C_FIELD(temp_r3, s32 *, 0x38) = arg1;
    M2C_FIELD(temp_r3, s32 *, 0x3C) = arg2;
}

void *Mu_StartBlend(s32 unit, s32 arg1, s32 hitCount, void *proc) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, void *);
    u8 fn_8004C0F0(void *);
    void fn_8004FE90(void *, u8);
    void fn_8004FE98(void *, s32);
    void fn_800506E0(void *, s32, void *);
    void *fn_800508C4(void *);
    f32 Math_Lerp(f32, f32, f32, f32);
    void fn_8005FC74(void *, void *, s32);
    void fn_8005FEE8(void *, f32);
    s32 fn_80060440(void *);
    void *fn_800639B4(void);
    void MuFade_UnlinkSame(void *, void *);
    extern u8 E_MuBlend_script[];
    extern u8 E_MuTransfer_script[];
    extern f32 lbl_8036ACEC;
    extern f32 lbl_8036ACF0;
    extern f64 lbl_8036ACE0;
    u8 blendKey[0x34];
    u8 transferKey[0x38];
    s32 rangeResult;
    void *animSrc;

    if (fn_8004C0F0((void *)unit) == 0) {
        return NULL;
    }
    *(void **)(blendKey + 0x30) = (void *)unit;
    GfxEnt_ForEachKey(E_MuBlend_script, MuFade_UnlinkSame, blendKey);
    *(void **)(transferKey + 0x30) = (void *)unit;
    GfxEnt_ForEachKey(E_MuTransfer_script, MuFade_UnlinkSame, transferKey);
    {
        u8 level = *(u8 *)((u8 *)fn_800508C4((void *)unit) + 9);
        if ((s32)level > 0x14) {
            if ((s32)level > 0x28) {
                hitCount <<= 1;
            } else {
                hitCount = (s32)((f32)hitCount + Math_Lerp(lbl_8036ACEC, (f32)hitCount, lbl_8036ACF0, (f32)((s32)level - 0x14)));
            }
        }
    }
    if ((hitCount == 0) || (fn_80060440((u8 *)unit + 0x1C) >= 4)) {
        fn_8004FE98((void *)unit, arg1);
        return NULL;
    }
    proc = Process_CreateEx(E_MuBlend_script, proc);
    *(void **)((u8 *)proc + 0x30) = (void *)unit;
    *(s32 *)((u8 *)proc + 0x34) = unit + 0x1C;
    *(s32 *)((u8 *)proc + 0x38) = arg1;
    *(s32 *)((u8 *)proc + 0x3C) = hitCount;
    *(s32 *)((u8 *)proc + 0x40) = 0;
    fn_800506E0(*(void **)((u8 *)proc + 0x30), arg1, (void *)(unit + 0x1C));
    animSrc = fn_800639B4();
    rangeResult = 0;
    switch (arg1) {
    case 0:
    case 1:
    case 8:
    case 15:
        if (*(void **)((u8 *)*(void **)((u8 *)proc + 0x34) + 0x44) != NULL) {
            void *range = *(void **)((u8 *)*(void **)((u8 *)proc + 0x34) + 0x44);
            f32 rangeStart = (f32)*(s32 *)((u8 *)range + 0x14);
            rangeResult = (s32)Math_Lerp((f32)*(s32 *)((u8 *)animSrc + 0x14), (f32)*(s32 *)((u8 *)animSrc + 0x18), (f32)*(s32 *)((u8 *)range + 0x18) - rangeStart, *(f32 *)((u8 *)*(void **)((u8 *)proc + 0x34) + 0x58) - rangeStart);
        }
        break;
    }
    fn_8005FC74(*(void **)((u8 *)proc + 0x34), animSrc, 1);
    fn_8005FEE8(*(void **)((u8 *)proc + 0x34), (f32)rangeResult);
    fn_8004FE90(*(void **)((u8 *)proc + 0x30), (u8)*(s32 *)((u8 *)proc + 0x38));
    return proc;
}

#pragma global_optimizer off
void fn_80184F20(s32 arg0) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void MuFade_UnlinkSame(void *, void *);
    extern u8 E_MuBlend_script[];
    struct Scr { u8 b; };
    u8 key0[0x38];
    u8 key1[0x38];
    u8 key2[0x38];
    u8 key3[0x38];
    u8 key4[0x38];
    u8 key5[0x38];
    u8 key6[0x38];
    u8 key7[0x38];
    u8 key8[0x38];
    u8 key9[0x38];
    u8 key10[0x38];
    s32 unit;
    struct Scr *script;

    script = (struct Scr *)E_MuBlend_script;
    unit = arg0;
    *(s32 *)(key0 + 0x30) = unit;
    GfxEnt_ForEachKey(&script->b, MuFade_UnlinkSame, key0);
    *(s32 *)(key1 + 0x30) = unit;
    GfxEnt_ForEachKey((u8 *)script + 0x20, MuFade_UnlinkSame, key1);
    *(s32 *)(key2 + 0x30) = unit;
    GfxEnt_ForEachKey((u8 *)script + 0x78, MuFade_UnlinkSame, key2);
    *(s32 *)(key3 + 0x30) = unit;
    GfxEnt_ForEachKey((u8 *)script + 0x98, MuFade_UnlinkSame, key3);
    *(s32 *)(key4 + 0x30) = unit;
    GfxEnt_ForEachKey((u8 *)script + 0xC0, MuFade_UnlinkSame, key4);
    *(s32 *)(key5 + 0x30) = unit;
    GfxEnt_ForEachKey((u8 *)script + 0x110, MuFade_UnlinkSame, key5);
    *(s32 *)(key6 + 0x30) = unit;
    GfxEnt_ForEachKey((u8 *)script + 0xE8, MuFade_UnlinkSame, key6);
    *(s32 *)(key7 + 0x30) = unit;
    GfxEnt_ForEachKey((u8 *)script + 0x40, MuFade_UnlinkSame, key7);
    *(s32 *)(key8 + 0x30) = unit;
    GfxEnt_ForEachKey((u8 *)script + 0x60, MuFade_UnlinkSame, key8);
    *(s32 *)(key9 + 0x30) = unit;
    GfxEnt_ForEachKey((u8 *)script + 0x164, MuFade_UnlinkSame, key9);
    *(s32 *)(key10 + 0x30) = unit;
    GfxEnt_ForEachKey((u8 *)script + 0x3F0, MuFade_UnlinkSame, key10);
}
#pragma global_optimizer on
void MoveAnim_MatchUnit(void *arg0, void *arg1) {
    if ((u32) M2C_FIELD(arg0, u32 *, 0x30) == (u32) M2C_FIELD(arg1, u32 *, 0x30)) {
        M2C_FIELD(arg1, void **, 0x34) = arg0;
    }
}

#pragma inline
void MuFade_UnlinkSame(void *arg0, void *arg1) {
    M2C_UNK Process_Unlink(void *);
    if ((u32) M2C_FIELD(arg0, u32 *, 0x30) == (u32) M2C_FIELD(arg1, u32 *, 0x30)) {
        Process_Unlink(arg0);
    }
}
void fn_801850A8(void *arg0) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, void *);
    s32 Mu_GetFlashColor(s32);
    void MuFade_UnlinkSame(void *, void *);
    extern u8 E_MuColorChange_script[];
    u8 spC[0x34];
    u32 sp8;
    void *temp_r30;
    void *temp_r3;

    temp_r30 = M2C_FIELD(arg0, void **, 0x30);
    M2C_FIELD(spC, void **, 0x30) = temp_r30;
    GfxEnt_ForEachKey(E_MuColorChange_script, MuFade_UnlinkSame, spC);
    temp_r3 = Process_CreateEx(E_MuColorChange_script, arg0);
    M2C_FIELD(temp_r3, void **, 0x30) = temp_r30;
    M2C_FIELD(temp_r3, s32 *, 0x3C) = 0x10;
    sp8 = Mu_GetFlashColor(0xC);
    M2C_FIELD(temp_r3, u8 *, 0x38) = ((u8 *)&sp8)[0];
    M2C_FIELD(temp_r3, u8 *, 0x39) = ((u8 *)&sp8)[1];
    M2C_FIELD(temp_r3, u8 *, 0x3A) = ((u8 *)&sp8)[2];
    M2C_FIELD(temp_r3, u8 *, 0x3B) = ((u8 *)&sp8)[3];
    M2C_FIELD(temp_r3, u8 *, 0x34) = ((u8 *)temp_r30)[0x24];
    M2C_FIELD(temp_r3, u8 *, 0x35) = ((u8 *)temp_r30)[0x25];
    M2C_FIELD(temp_r3, u8 *, 0x36) = ((u8 *)temp_r30)[0x26];
    M2C_FIELD(temp_r3, u8 *, 0x37) = ((u8 *)temp_r30)[0x27];
}

/* Play an SE at the bound unit, then start an E_MuFlash tint (palette 0xB, duration 8). */
void MuFlash_StartWithSe(void *proc) {
    void SeCue_PlayAt(void *, s32, f32, f32, f32);
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, void *);
    s32 Mu_GetFlashColor(s32);
    void MuFade_UnlinkSame(void *, void *);
    extern u8 MoveAnim_str[];
    extern u8 E_MuColorChange_script[];
    u8 key[0x34];
    u32 color;
    void *unit;
    void *flash;
    void *unitSe;

    unitSe = *(void **)((u8 *)proc + 0x30);
    SeCue_PlayAt(MoveAnim_str + 0x1AA, 0x64,
                *(f32 *)((u8 *)unitSe + 4),
                *(f32 *)((u8 *)unitSe + 8),
                *(f32 *)((u8 *)unitSe + 0xC));
    unit = *(void **)((u8 *)proc + 0x30);
    *(void **)(key + 0x30) = unit;
    GfxEnt_ForEachKey(E_MuColorChange_script, MuFade_UnlinkSame, key);
    flash = Process_CreateEx(E_MuColorChange_script, proc);
    *(void **)((u8 *)flash + 0x30) = unit;
    *(s32 *)((u8 *)flash + 0x3C) = 8;
    color = Mu_GetFlashColor(0xB);
    ((u8 *)flash)[0x38] = ((u8 *)&color)[0];
    ((u8 *)flash)[0x39] = ((u8 *)&color)[1];
    ((u8 *)flash)[0x3A] = ((u8 *)&color)[2];
    ((u8 *)flash)[0x3B] = ((u8 *)&color)[3];
    ((u8 *)flash)[0x34] = ((u8 *)unit)[0x24];
    ((u8 *)flash)[0x35] = ((u8 *)unit)[0x25];
    ((u8 *)flash)[0x36] = ((u8 *)unit)[0x26];
    ((u8 *)flash)[0x37] = ((u8 *)unit)[0x27];
}

void fn_80185244(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) (M2C_FIELD(arg0, s32 *, 0x34) + 1);
    if ((s32) M2C_FIELD(arg0, s32 *, 0x34) > (s32) M2C_FIELD(arg0, s32 *, 0x3C)) {
        Process_ClearFunc();
    }
}

#pragma opt_strength_reduction off
void fn_80185280(void *arg0) {
    void fn_8000A388(void *, void *, void *);
    void fn_8000C070(void *, s32);
    void *fn_8000CA64(void *, s32);
    u8 fn_8004C0F0(void *);
    void fn_8004FE90(void *, u8);
    void fn_8004FE98(void *, s32);
    void fn_800506E0(void *, s32);
    void *fn_800508C4(void *);
    f32 fn_80059F64(f32, f32, f32, f32);
    void fn_8005FC74(void *, void *, s32);
    void fn_8005FEE8(void *, f32);
    s32 fn_80060440(void *);
    void *fn_80060664(void *);
    void *fn_800639B4(void);
    u8 fn_80105BC0(void *, s32);
    void fn_80185078(void *, void *);
    extern u8 lbl_80295A00[];
    extern u8 lbl_80295A20[];
    extern f32 lbl_8036ACEC;
    extern f32 lbl_8036ACF0;
    extern f32 lbl_8036ACF4;
    u8 sp40[0x34];
    u8 sp8[0x38];
    void *obj;
    s32 count;
    void *tmp;
    void *end;
    u8 lvl;

    count = 0x10;
    obj = *(void **)((u8 *)arg0 + 0x30);
    if (fn_8004C0F0(obj) != 0) {
        *(void **)(sp40 + 0x30) = obj;
        fn_8000A388(lbl_80295A00, fn_80185078, sp40);
        *(void **)(sp8 + 0x30) = obj;
        fn_8000A388(lbl_80295A20, fn_80185078, sp8);
        lvl = *(u8 *)((u8 *)fn_800508C4(obj) + 9);
        if ((s32)lvl > 0x14) {
            if ((s32)lvl > 0x28) {
                count <<= 1;
            }
            if ((s32)lvl <= 0x28) {
                count = (s32)((f32)count + fn_80059F64(lbl_8036ACEC, lbl_8036ACF4, lbl_8036ACF0, (f32)((s32)lvl - 0x14)));
            }
        }
        if ((count == 0) || (fn_80060440((u8 *)obj + 0x1C) >= 4)) {
            fn_8004FE98(obj, 0xB);
        } else {
            tmp = fn_8000CA64(lbl_80295A00, 0);
            *(void **)((u8 *)tmp + 0x30) = obj;
            *(s32 *)((u8 *)tmp + 0x34) = (s32)obj + 0x1C;
            *(s32 *)((u8 *)tmp + 0x38) = 0xB;
            *(s32 *)((u8 *)tmp + 0x3C) = count;
            *(s32 *)((u8 *)tmp + 0x40) = 0;
            fn_800506E0(*(void **)((u8 *)tmp + 0x30), 0xB);
            fn_8005FC74(*(void **)((u8 *)tmp + 0x34), fn_800639B4(), 1);
            fn_8005FEE8(*(void **)((u8 *)tmp + 0x34), lbl_8036ACEC);
            fn_8004FE90(*(void **)((u8 *)tmp + 0x30), (u8)*(s32 *)((u8 *)tmp + 0x38));
        }
    }
    if (fn_80105BC0((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x1BC, 0x5C) != 0) {
        fn_8000C070(arg0, 0xA);
        return;
    }
    end = fn_80060664((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x1C);
    *(s32 *)((u8 *)arg0 + 0x3C) = (*(s32 *)((u8 *)end + 0x18) - *(s32 *)((u8 *)end + 0x14)) - 8;
    if (*(s32 *)((u8 *)arg0 + 0x3C) < 0) {
        *(s32 *)((u8 *)arg0 + 0x3C) = 0;
    }
    *(s32 *)((u8 *)arg0 + 0x34) = 0;
}
#pragma opt_strength_reduction on
void fn_8018548C(void *arg0) {
    fn_8004FC70(M2C_FIELD(arg0, s32 *, 0x30), 0xB);
}

void fn_801854B4(void *arg0) {
    M2C_UNK fn_8004B1B4(s32);
    fn_8004B1B4(M2C_FIELD(arg0, s32 *, 0x30));
}

#pragma push
#pragma cplusplus on
#pragma scheduling on
extern "C" void Unit_SetModelAlpha(void *, s32);
#pragma cplusplus off
#pragma scheduling on
void fn_801854D8(void *arg0) {
    void fn_8004E9D8(void *, s32);
    void fn_80050C90(void *);
    extern f32 lbl_8036ACF8;
    void *unit;

    unit = *(void **)((u8 *)arg0 + 0x30);
    *(f32 *)((u8 *)unit + 0x78) = 1.0f;
    if (*(u8 *)((u8 *)arg0 + 0x3D) == 0) {
        unit = *(void **)((u8 *)arg0 + 0x30);
        *(u8 *)((u8 *)unit + 3) |= 4;
        fn_8004E9D8(*(void **)((u8 *)arg0 + 0x30), 0);
        unit = *(void **)((u8 *)arg0 + 0x30);
        *(u8 *)((u8 *)unit + 3) &= ~4;
        fn_80050C90(*(void **)((u8 *)arg0 + 0x30));
    }
    if (*(u8 *)((u8 *)arg0 + 0x3C) != 0) {
        Unit_SetModelAlpha(*(void **)((u8 *)arg0 + 0x30), 0xFF);
    }
}
#pragma cplusplus off
void fn_80185564(void *arg0) {
    void fn_8004E9D8(void *, s32);
    void GfxEnt_ForEachKey(void *, void *, void *);
    void MuFade_UnlinkSame(void *, void *);
    void *Process_CreateEx(void *, void *);
    u32 Mu_GetFlashColor(s32);
    extern u8 E_MuColorChange_script[];

    u8 *self;
    u8 *unit;
    u8 *flash;
    u8 key[0x44];
    u32 color;
    s32 duration;

    self = (u8 *)arg0;

    self[0x3D] = 1;

    unit = *(u8 **)(self + 0x30);
    unit[3] |= 4;

    fn_8004E9D8(*(void **)(self + 0x30), 0);

    unit = *(u8 **)(self + 0x30);
    unit[3] &= ~4;

    duration = 16 / *(s32 *)(self + 0x34);

    unit = *(u8 **)(self + 0x30);
    *(void **)(key + 0x30) = unit;

    GfxEnt_ForEachKey(
        E_MuColorChange_script,
        MuFade_UnlinkSame,
        key
    );

    flash = (u8 *)Process_CreateEx(
        E_MuColorChange_script,
        self
    );

    *(void **)(flash + 0x30) = unit;
    *(s32 *)(flash + 0x3C) = duration;

    color = Mu_GetFlashColor(0);

    flash[0x38] = ((u8 *)&color)[0];
    flash[0x39] = ((u8 *)&color)[1];
    flash[0x3A] = ((u8 *)&color)[2];
    flash[0x3B] = ((u8 *)&color)[3];

    flash[0x34] = unit[0x24];
    flash[0x35] = unit[0x25];
    flash[0x36] = unit[0x26];
    flash[0x37] = unit[0x27];

    *(s32 *)(self + 0x38) = 0;
}

void fn_80185674(void *arg0) {
void *Effect_Create(void*,void*);
void Effect_SetPos(void*,f32,f32,f32);
void fn_80185B94(void);
void fn_80053658(void*,s32,void*);
void GfxEnt_ForEachKey(void*,void*,void*);
void MuFade_UnlinkSame(void*,void*);
void *Process_CreateEx(void*,void*);
u32 Mu_GetFlashColor(s32);
void *fn_80185BD4(void*);
void SeCue_PlayAt(void*,s32,f32,f32,f32);
void DebugPrint(void*,...);
extern u8 MoveAnim_str[],E_MuColorChange_script[];
extern f32 lbl_8036ACFC;
u8 *self=arg0;
u8 *flash;
u8 *unit;
u8 *effect;
u8 key[0x44];
u32 color;
s32 duration;
void *cue;
effect=Effect_Create(MoveAnim_str+0x1C1,self);
unit=*(u8**)(self+0x30);
Effect_SetPos(effect,*(f32*)(unit+4),*(f32*)(unit+8),*(f32*)(unit+12)-lbl_8036ACFC);
*(void(**)(void))(*(u8**)(effect+0x30)+0x40)=fn_80185B94;
fn_80053658(effect,0,self);
(*(u8**)(effect+0x30))[5]=4;
duration=16/ *(s32*)(self+0x34);
unit=*(u8**)(self+0x30);
*(void**)(key+0x30)=unit;
GfxEnt_ForEachKey(E_MuColorChange_script,MuFade_UnlinkSame,key);
flash=Process_CreateEx(E_MuColorChange_script,self);
*(void**)(flash+0x30)=unit;
*(s32*)(flash+0x3C)=duration;
color=Mu_GetFlashColor(3);
flash[0x38]=((u8*)&color)[0];
flash[0x39]=((u8*)&color)[1];
flash[0x3A]=((u8*)&color)[2];
flash[0x3B]=((u8*)&color)[3];
flash[0x34]=unit[0x24];
flash[0x35]=unit[0x25];
flash[0x36]=unit[0x26];
flash[0x37]=unit[0x27];
*(s32*)(self+0x38)=0;
cue=fn_80185BD4(*(void**)(self+0x30));
if(cue){
unit=*(u8**)(self+0x30);
SeCue_PlayAt(cue,100,*(f32*)(unit+4),*(f32*)(unit+8),*(f32*)(unit+12));
DebugPrint(MoveAnim_str+0x1CB,cue);
}
}

void fn_801857F0(void *arg0) {
    u8 Mu_IsAnimDone(s32);
    if (Mu_IsAnimDone(M2C_FIELD(arg0, s32 *, 0x30)) != 0) {
        Process_ClearFunc(arg0);
    }
}

#pragma global_optimizer off
void fn_80185830(void *arg0) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void Process_Goto(void *, s32);
    void *Process_CreateEx(void *, s32);
    void *Process_Create(void *, s32);
    u8 fn_8004C0F0(void *);
    void fn_8004FE90(void *, u8);
    void fn_8004FE98(void *, s32);
    u8 fn_800504FC(void *, s32);
    void fn_800506E0(void *, s32);
    void *fn_800508C4(void *);
    void Process_AttachFunc(void *, void *);
    f32 Math_Lerp(f32, f32, f32, f32);
    void fn_8005FC74(void *, void *, s32);
    void fn_8005FEE8(void *, f32);
    s32 fn_80060440(void *);
    void *fn_800639B4(void);
    void MuFade_UnlinkSame(void *, void *);
    void fn_80185AF4(void *);
    extern u8 E_MuBlend_script[];
    extern f32 lbl_8036ACEC;
    extern f32 lbl_8036ACF0;
    extern f32 lbl_8036ACF4;

    u8 gap[8];
    u8 sp78[0x38];
    u8 sp40[0x38];
    u8 sp8[0x38];
    void *self;
    u8 *base;
    s32 r29;
    void *r28;
    void *tmp;
    u8 lvl;
    s32 z;
    s32 z0;

    self = arg0;
    base = E_MuBlend_script;
    z = 0x40;
    *(s32 *)((u8 *)arg0 + 0x34) = 1;
    if (*(u8 *)((u8 *)arg0 + 0x3C) != 0) {
        if (fn_800504FC(*(void **)((u8 *)self + 0x30), 0xA) != 0) {
            r29 = (s32)*(void **)((u8 *)self + 0x30);
            r28 = self;
            *(s32 *)(sp78 + 0x30) = r29;
            GfxEnt_ForEachKey(base + z, MuFade_UnlinkSame, sp78);
            if ((u32)self == 0U) {
                r28 = (void *)3;
            }
            *(s32 *)((u8 *)Process_Create(base + z, (s32)r28) + 0x30) = r29;
            r29 = 0x10;
            r28 = *(void **)((u8 *)self + 0x30);
            if (fn_8004C0F0(r28) != 0) {
                z0 = z - 0x40;
                *(void **)(sp40 + 0x30) = r28;
                GfxEnt_ForEachKey(base + z0, MuFade_UnlinkSame, sp40);
                *(void **)(sp8 + 0x30) = r28;
                GfxEnt_ForEachKey(base + 0x20, MuFade_UnlinkSame, sp8);
                lvl = *(u8 *)((u8 *)fn_800508C4(r28) + 9);
                if ((s32)lvl > 0x14) {
                    if ((s32)lvl > 0x28) {
                        r29 <<= 1;
                    } else {
                        r29 = (s32)((f32)r29 + Math_Lerp(lbl_8036ACEC, lbl_8036ACF4, lbl_8036ACF0, (f32)((s32)lvl - 0x14)));
                    }
                }
                if ((r29 == 0) || (fn_80060440((u8 *)r28 + 0x1C) >= 4)) {
                    fn_8004FE98(r28, 0xA);
                } else {
                    tmp = Process_CreateEx(base + z0, 0);
                    *(void **)((u8 *)tmp + 0x30) = r28;
                    *(s32 *)((u8 *)tmp + 0x34) = (s32)r28 + 0x1C;
                    *(s32 *)((u8 *)tmp + 0x38) = 0xA;
                    *(s32 *)((u8 *)tmp + 0x3C) = r29;
                    *(s32 *)((u8 *)tmp + 0x40) = 0;
                    fn_800506E0(*(void **)((u8 *)tmp + 0x30), 0xA);
                    fn_8005FC74(*(void **)((u8 *)tmp + 0x34), fn_800639B4(), 1);
                    fn_8005FEE8(*(void **)((u8 *)tmp + 0x34), lbl_8036ACEC);
                    fn_8004FE90(*(void **)((u8 *)tmp + 0x30), (u8)*(s32 *)((u8 *)tmp + 0x38));
                }
            }
            Process_AttachFunc(fn_80185AF4, self);
        } else {
            Process_Goto(self, 0);
        }
    } else {
        Process_Goto(arg0, 1);
    }
    (void)gap;
}
#pragma global_optimizer reset
void fn_80185A64(void *arg0) {
    void GActor_RequestRes(void *);
    void fn_8004F5EC(void *, s32);
    u8 fn_800504FC(void *, s32);
    void fn_8004FC70(void *, s32);
    extern u8 MoveAnim_str[];
    void *obj;
    u8 *flags;

    if (*((u8 *)arg0 + 0x3C) != 0) {
        GActor_RequestRes(MoveAnim_str + 0x1C1);
        obj = *(void **)((u8 *)arg0 + 0x30);
        if (fn_800504FC(obj, 0xA) != 0) {
            fn_8004FC70(*(void **)((u8 *)arg0 + 0x30), 0xA);
        }
    }
    flags = (u8 *)*(void **)((u8 *)arg0 + 0x30) + 3;
    *flags |= 4;
    fn_8004F5EC(*(void **)((u8 *)arg0 + 0x30), 0);
    flags = (u8 *)*(void **)((u8 *)arg0 + 0x30) + 3;
    *flags &= 0xFFFFFFFB;
}

void fn_80185AF4(void *arg0) {
    extern void *gPadInput;
    s32 temp_r0;

    if ((u8) M2C_FIELD(arg0, u8 *, 0x3E) != 0) {
        temp_r0 = M2C_FIELD(gPadInput, s32 *, 4);
        if ((s32) M2C_FIELD(arg0, s32 *, 0x34) == 1) {
            if (temp_r0 & 0x100) {
                M2C_FIELD(arg0, s32 *, 0x34) = 2;
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 0x78) = (f32) M2C_FIELD(arg0, s32 *, 0x34);
            }
        } else if (!(temp_r0 & 0x100)) {
            M2C_FIELD(arg0, s32 *, 0x34) = 1;
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 0x78) = (f32) M2C_FIELD(arg0, s32 *, 0x34);
        }
    }
}

s32 fn_80185B94(void *arg0) {
    void *temp_r5;

    temp_r5 = M2C_FIELD(arg0, void **, 0x30);
    M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x5C), f32 *, 0x5C) = (f32) M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x4C), s32 *, 0x34);
    return 0;
}

void *fn_80185BD4(void *arg0) {
void *Res_GetByName(void *);
s32 Str_Cmp(void *, void *);
u8 Status_Test(void *, s32);
void fn_800056A0(s32);
extern u8 MoveAnim_str[];
void *res;
void *name;
void *key=*(void **)((u8 *)*(void **)((u8 *)arg0+0x18c)+0xc);
if(key) res=Res_GetByName(key); else res=0;
if(!res) return 0;
name=*(void **)res;
if(Str_Cmp(MoveAnim_str+0x1df,name)==0) return MoveAnim_str+0x1e8;
if(Str_Cmp(MoveAnim_str+0x1fd,name)==0) return MoveAnim_str+0x207;
if(Str_Cmp(MoveAnim_str+0x21d,name)==0) return MoveAnim_str+0x225;
if(Str_Cmp(MoveAnim_str+0x239,name)==0) return MoveAnim_str+0x225;
if(Str_Cmp(MoveAnim_str+0x243,name)==0) return MoveAnim_str+0x253;
if(Str_Cmp(MoveAnim_str+0x26a,name)==0) return MoveAnim_str+0x253;
if(Str_Cmp(MoveAnim_str+0x27c,name)==0) return MoveAnim_str+0x253;
if(Str_Cmp(MoveAnim_str+0x28c,name)==0) return MoveAnim_str+0x253;
if(Str_Cmp(MoveAnim_str+0x29e,name)==0) return MoveAnim_str+0x253;
if(Str_Cmp(MoveAnim_str+0x2ac,name)==0) return MoveAnim_str+0x253;
if(Str_Cmp(MoveAnim_str+0x2bc,name)==0) return MoveAnim_str+0x2c5;
if(Str_Cmp(MoveAnim_str+0x2da,name)==0) return MoveAnim_str+0x2c5;
if(Str_Cmp(MoveAnim_str+0x2e7,name)==0) return MoveAnim_str+0x2f0;
if(Str_Cmp(MoveAnim_str+0x305,name)==0) return MoveAnim_str+0x2f0;
if(Str_Cmp(MoveAnim_str+0x312,name)==0) return MoveAnim_str+0x31c;
if(Str_Cmp(MoveAnim_str+0x332,name)==0) return MoveAnim_str+0x31c;
if(Str_Cmp(MoveAnim_str+0x33e,name)==0) return MoveAnim_str+0x31c;
if(Status_Test((u8 *)res+0x1c,9)) fn_800056A0(0);
return 0;
}

/* On pad button 0, start an E_MuFlash tint for the bound unit and clear this process func. */
void MuFlash_StartOnButton(void *proc) {
    u8 Pad_IsButton(void *, s32);
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, s32);
    s32 Mu_GetFlashColor(s32);
    void MuFade_UnlinkSame(void *, void *);
    void Process_ClearFunc(void *);
    extern u8 E_MuColorChange_script[];
    u8 key[0x44];
    u32 color;
    void *unit;
    void *flash;

    if ((u8)Pad_IsButton(*(void **)((u8 *)*(void **)((u8 *)*(void **)((u8 *)proc + 0x34) + 0x30) + 0x5C), 0) == 0) {
        return;
    }
    unit = *(void **)((u8 *)proc + 0x30);
    *(void **)(key + 0x30) = unit;
    GfxEnt_ForEachKey(E_MuColorChange_script, MuFade_UnlinkSame, key);
    flash = Process_CreateEx(E_MuColorChange_script, 0);
    *(void **)((u8 *)flash + 0x30) = unit;
    *(s32 *)((u8 *)flash + 0x3C) = 0x10;
    color = Mu_GetFlashColor(0);
    ((u8 *)flash)[0x38] = ((u8 *)&color)[0];
    ((u8 *)flash)[0x39] = ((u8 *)&color)[1];
    ((u8 *)flash)[0x3A] = ((u8 *)&color)[2];
    ((u8 *)flash)[0x3B] = ((u8 *)&color)[3];
    ((u8 *)flash)[0x34] = ((u8 *)unit)[0x24];
    ((u8 *)flash)[0x35] = ((u8 *)unit)[0x25];
    ((u8 *)flash)[0x36] = ((u8 *)unit)[0x26];
    ((u8 *)flash)[0x37] = ((u8 *)unit)[0x27];
    Process_ClearFunc(proc);
}

void fn_80186028(void *arg0) {
    M2C_UNK Effect_SetPos(void *, void *, f32, f32, f32);
    s32 *temp_r3;
    void *temp_r4;

    temp_r4 = M2C_FIELD(arg0, void **, 0x30);
    Effect_SetPos(M2C_FIELD(arg0, void **, 0x34), temp_r4, M2C_FIELD(temp_r4, f32 *, 4), M2C_FIELD(temp_r4, f32 *, 8), M2C_FIELD(temp_r4, f32 *, 0xC));
    temp_r3 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), void **, 0x30), s32 **, 0x5C);
    *temp_r3 &= 0xFFFFFFBF;
}

/* Place the bound unit at tile (x+0.5,y+0.5) and hide it, or advance the process when flags&4. */
void Mu_HideAtTile(void *proc) {
    void Unit_SetWorldXY(void *, f32, f32, f32);
    void Unit_SetModelAlpha(void *, s32);
    void Unit_FocusCamera(void *, s32);
    void Process_Goto(void *, s32);
    extern f32 gHalf;
    s32 flags;

    flags = *(u16 *)((u8 *)proc + 0x38) & 5;
    switch (flags) {
    case 0:
    case 1:
        Unit_SetWorldXY(*(void **)((u8 *)proc + 0x30),
                    gHalf + (f32)*(s32 *)((u8 *)proc + 0x3C),
                    gHalf + (f32)*(s32 *)((u8 *)proc + 0x40),
                    gHalf);
        Unit_SetModelAlpha(*(void **)((u8 *)proc + 0x30), 0);
        if (*(u16 *)((u8 *)proc + 0x38) & 0x10) {
            Unit_FocusCamera(*(void **)((u8 *)proc + 0x30), 0);
        }
        break;
    case 4:
        Process_Goto(proc, 2);
        break;
    }
}

void fn_8018614C(void *arg0) {
    u8 Pad_IsButton(void *, s32);
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, s32);
    s32 Mu_GetFlashColor(s32);
    void MuFade_UnlinkSame(void *, void *);
    void Process_ClearFunc(void *);
    extern u8 E_MuColorChange_script[];

    u8 key[0x44];
    u32 color;
    void *unit;
    void *pad;
    void *proc;
    void *flash;

    proc = arg0;
    pad = *(void **)((u8 *)*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x34) + 0x30) + 0x5C);

    if ((u8)Pad_IsButton(pad, 0) != 0) {
        unit = *(void **)((u8 *)proc + 0x30);
        *(void **)(key + 0x30) = unit;
        GfxEnt_ForEachKey(E_MuColorChange_script, MuFade_UnlinkSame, key);
        flash = Process_CreateEx(E_MuColorChange_script, 0);
        *(void **)((u8 *)flash + 0x30) = unit;
        *(s32 *)((u8 *)flash + 0x3C) = 0x10;
        color = Mu_GetFlashColor(3);
        ((u8 *)flash)[0x38] = ((u8 *)&color)[0];
        ((u8 *)flash)[0x39] = ((u8 *)&color)[1];
        ((u8 *)flash)[0x3A] = ((u8 *)&color)[2];
        ((u8 *)flash)[0x3B] = ((u8 *)&color)[3];
        ((u8 *)flash)[0x34] = ((u8 *)unit)[0x24];
        ((u8 *)flash)[0x35] = ((u8 *)unit)[0x25];
        ((u8 *)flash)[0x36] = ((u8 *)unit)[0x26];
        ((u8 *)flash)[0x37] = ((u8 *)unit)[0x27];
    }

    if ((u8)Pad_IsButton(pad, 8) != 0) {
        *(u32 *)pad |= 0x40;
        Process_ClearFunc(proc);
    }
}

void fn_80186260(void *arg0) {
    s32 fn_8005F894(void *, s32);
    void fn_8005FEE8(void *, f32);
    void Process_Goto(void *, s32);
    void Unit_FocusCamera(void *, s32);
    void *node;
    s32 val;

    node = *(void **)((u8 *)*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x34) + 0x30) + 0x5C);
    if (node != NULL) {
        switch (*(u16 *)((u8 *)arg0 + 0x38) & 5) {
        case 1:
            val = fn_8005F894(node, 8);
            fn_8005FEE8(node, (f32)val);
            Process_Goto(arg0, 1);
            break;
        default:
            Process_Goto(arg0, 0);
            break;
        }
        if (*(u16 *)((u8 *)arg0 + 0x38) & 0x10) {
            Unit_FocusCamera(*(void **)((u8 *)arg0 + 0x30), 0);
        }
    }
}

void fn_80186318(void *arg0) {
    s32 Effect_Create(void *, void *);
    void Effect_SetPos(s32, f32, f32, f32);
    extern u8 MoveAnim_str[];
    f32 temp_f31;
    f32 temp_f30;
    f32 temp_f29;
    void *temp_r5;
    u8 *base;
    u8 *var_r3;
    u32 bit;

    base = MoveAnim_str;
    temp_r5 = M2C_FIELD(arg0, void **, 0x30);
    var_r3 = base + 0x357;
    bit = M2C_FIELD(arg0, u16 *, 0x38) & 0x20;
    temp_f31 = M2C_FIELD(temp_r5, f32 *, 4);
    temp_f30 = M2C_FIELD(temp_r5, f32 *, 8);
    temp_f29 = M2C_FIELD(temp_r5, f32 *, 0xC);
    if (bit) {
        var_r3 = base + 0x34C;
    }
    M2C_FIELD(arg0, s32 *, 0x34) = Effect_Create(var_r3, arg0);
    Effect_SetPos(M2C_FIELD(arg0, s32 *, 0x34), temp_f31, temp_f30, temp_f29);
}

void fn_801863BC(void *arg0) {
    extern u16 MoveAnim_str[];
    void GActor_RequestRes(void *);
    void *var_r3;

    var_r3 = (u8 *)MoveAnim_str + 0x357;
    if (*(u16 *)((u8 *)arg0 + 0x38) & 0x20) {
        var_r3 = (u8 *)MoveAnim_str + 0x34C;
    }
    GActor_RequestRes(var_r3);
}

void fn_801863F8(void *arg0) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, void *);
    u8 fn_8004C0F0(void *);
    void fn_8004FE90(void *, u8);
    void fn_8004FE98(void *, s32);
    void fn_800506E0(void *, s32);
    void *fn_800508C4(void *);
    f32 Math_Lerp(f32, f32, f32, f32);
    void fn_8005FC74(void *, void *, s32);
    void fn_8005FEE8(void *, f32);
    s32 fn_80060440(void *);
    void *fn_800639B4(void);
    void MuFade_UnlinkSame(void *, void *);
    extern u8 E_MuBlend_script[];
    extern u8 E_MuTransfer_script[];
    extern f32 lbl_8036ACEC;
    extern f32 lbl_8036ACF0;
    extern f32 lbl_8036ACF4;
    extern f64 lbl_8036ACE0;

    u8 blendKey[0x34];
    u8 transferKey[0x38];
    void *unit;
    s32 hitCount;
    void *animSrc;

    unit = *(void **)((u8 *)arg0 + 0x34);
    hitCount = 8;
    hitCount += 8;
    if (fn_8004C0F0(unit) != 0) {
        *(void **)(blendKey + 0x30) = unit;
        GfxEnt_ForEachKey(E_MuBlend_script, MuFade_UnlinkSame, blendKey);
        *(void **)(transferKey + 0x30) = unit;
        GfxEnt_ForEachKey(E_MuTransfer_script, MuFade_UnlinkSame, transferKey);
        {
            u8 level = *(u8 *)((u8 *)fn_800508C4(unit) + 9);
            if ((s32)level > 0x14) {
                if ((s32)level > 0x28) {
                    hitCount <<= 1;
                } else {
                    hitCount = (s32)((f32)hitCount + Math_Lerp(lbl_8036ACEC, lbl_8036ACF4, lbl_8036ACF0, (f32)((s32)level - 0x14)));
                }
            }
        }
        if ((hitCount == 0) || (fn_80060440((u8 *)unit + 0x1C) >= 4)) {
            fn_8004FE98(unit, 0);
            return;
        }
        arg0 = Process_CreateEx(E_MuBlend_script, arg0);
        *(void **)((u8 *)arg0 + 0x30) = unit;
        *(s32 *)((u8 *)arg0 + 0x34) = (s32)unit + 0x1C;
        *(s32 *)((u8 *)arg0 + 0x38) = 0;
        *(s32 *)((u8 *)arg0 + 0x3C) = hitCount;
        *(s32 *)((u8 *)arg0 + 0x40) = 0;
        fn_800506E0(*(void **)((u8 *)arg0 + 0x30), 0);
        animSrc = fn_800639B4();
        hitCount = 0;
        if (*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x34) + 0x44) != NULL) {
            void *range = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x34) + 0x44);
            f32 rangeStart = (f32)*(s32 *)((u8 *)range + 0x14);
            hitCount = (s32)Math_Lerp((f32)*(s32 *)((u8 *)animSrc + 0x14), (f32)*(s32 *)((u8 *)animSrc + 0x18), (f32)*(s32 *)((u8 *)range + 0x18) - rangeStart, *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x34) + 0x58) - rangeStart);
        }
        fn_8005FC74(*(void **)((u8 *)arg0 + 0x34), animSrc, 1);
        fn_8005FEE8(*(void **)((u8 *)arg0 + 0x34), (f32)hitCount);
        fn_8004FE90(*(void **)((u8 *)arg0 + 0x30), (u8)*(s32 *)((u8 *)arg0 + 0x38));
    }
}

#pragma global_optimizer off
void fn_80186648(u8 *arg0) {
f32 Math_EaseOutPow(s32,f32,f32,f32,f32);
void Unit_SetWorldXY(void*,f32,f32);
void Model_SetAlpha(void*,u8);
void Process_ClearFunc(void*);
extern f32 lbl_8036ACF8,lbl_8036ACEC,lbl_8036AD00,lbl_8036ACF4,gHalf;
f32 inc=lbl_8036ACF8;
f32 cur=*(f32*)(arg0+0x4C);
void *model;
s32 alpha;
f32 x,y;
f32 start=lbl_8036ACEC, end=lbl_8036AD00, duration=lbl_8036ACF4;
*(f32*)(arg0+0x4C)=cur+inc;
model=(u8*)*(void**)(arg0+0x34)+0x1C;
alpha=(s32)Math_EaseOutPow(2,start,end,duration,*(f32*)(arg0+0x4C));
x=Math_EaseOutPow(2,*(f32*)(arg0+0x38),gHalf+(f32)*(s32*)(arg0+0x44),lbl_8036ACF4,*(f32*)(arg0+0x4C));
y=Math_EaseOutPow(2,*(f32*)(arg0+0x3C),gHalf+(f32)*(s32*)(arg0+0x48),lbl_8036ACF4,*(f32*)(arg0+0x4C));
Unit_SetWorldXY(*(void**)(arg0+0x34),x,y);
Model_SetAlpha(model,(u8)alpha);
if(*(f32*)(arg0+0x4C)==lbl_8036ACF4)Process_ClearFunc(arg0);
}
#pragma global_optimizer on
void fn_80186780(void *proc) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, s32);
    u8 fn_8004C0F0(void *);
    void fn_8004FE90(void *, u8);
    void fn_8004FE98(void *, s32);
    void fn_800506E0(void *, s32);
    void *fn_800508C4(void *);
    f32 Math_Lerp(f32, f32, f32, f32);
    void fn_8005FC74(void *, void *, s32);
    void fn_8005FEE8(void *, f32);
    s32 fn_80060440(void *);
    void *fn_800639B4(void);
    void MuFade_UnlinkSame(void *, void *);
    extern u8 E_MuBlend_script[];
    extern u8 E_MuTransfer_script[];
    extern f32 lbl_8036ACEC;
    extern f32 lbl_8036ACF0;
    extern f32 lbl_8036AD04;
    u8 blendKey[0x34];
    u8 transferKey[0x38];
    void *unit;
    void *animSrc;
    s32 hitCount;

    unit = *(void **)((u8 *)proc + 0x34);
    hitCount = 3;
    hitCount += 1;
    if (fn_8004C0F0(unit) != 0) {
        *(void **)(blendKey + 0x30) = unit;
        GfxEnt_ForEachKey(E_MuBlend_script, MuFade_UnlinkSame, blendKey);
        *(void **)(transferKey + 0x30) = unit;
        GfxEnt_ForEachKey(E_MuTransfer_script, MuFade_UnlinkSame, transferKey);
        {
            u8 level = *(u8 *)((u8 *)fn_800508C4(unit) + 9);
            if ((s32)level > 0x14) {
                if ((s32)level > 0x28) {
                    hitCount <<= 1;
                } else {
                    hitCount = (s32)((f32)hitCount + Math_Lerp(lbl_8036ACEC, lbl_8036AD04, lbl_8036ACF0, (f32)((s32)level - 0x14)));
                }
            }
        }
        if ((hitCount == 0) || (fn_80060440((u8 *)unit + 0x1C) >= 4)) {
            fn_8004FE98(unit, 1);
            return;
        }
        proc = Process_CreateEx(E_MuBlend_script, 0);
        *(void **)((u8 *)proc + 0x30) = unit;
        *(s32 *)((u8 *)proc + 0x34) = (s32)unit + 0x1C;
        *(s32 *)((u8 *)proc + 0x38) = 1;
        *(s32 *)((u8 *)proc + 0x3C) = hitCount;
        *(s32 *)((u8 *)proc + 0x40) = 0;
        fn_800506E0(*(void **)((u8 *)proc + 0x30), 1);
        animSrc = fn_800639B4();
        hitCount = 0;
        if (*(void **)((u8 *)*(void **)((u8 *)proc + 0x34) + 0x44) != NULL) {
            void *range = *(void **)((u8 *)*(void **)((u8 *)proc + 0x34) + 0x44);
            f32 rangeStart = (f32)*(s32 *)((u8 *)range + 0x14);
            hitCount = (s32)Math_Lerp((f32)*(s32 *)((u8 *)animSrc + 0x14), (f32)*(s32 *)((u8 *)animSrc + 0x18), (f32)*(s32 *)((u8 *)range + 0x18) - rangeStart, *(f32 *)((u8 *)*(void **)((u8 *)proc + 0x34) + 0x58) - rangeStart);
        }
        fn_8005FC74(*(void **)((u8 *)proc + 0x34), animSrc, 1);
        fn_8005FEE8(*(void **)((u8 *)proc + 0x34), (f32)hitCount);
        fn_8004FE90(*(void **)((u8 *)proc + 0x30), (u8)*(s32 *)((u8 *)proc + 0x38));
    }
}

void fn_801869D0(void *arg0) {
 void GfxEnt_ForEachKey(void *,void *,void *); void *Process_CreateEx(void *,s32);
 f32 fn_8004BDA8(void *,f32,f32); void Unit_SetWorldXY(void *,f32,f32);
 void MuFade_UnlinkSame(void *,void *); extern u16 E_MuFade_script[36];
 extern f32 gHalf,lbl_8036ACE8,lbl_8036ACEC;
 u8 key1[0x38],key2[0x38]; f32 angle; void *unit; void *proc;
 M2C_FIELD(arg0,f32 *,0x4C)=lbl_8036ACEC;
 M2C_FIELD(arg0,f32 *,0x38)=M2C_FIELD(M2C_FIELD(arg0,void **,0x30),f32 *,4);
 M2C_FIELD(arg0,f32 *,0x3C)=M2C_FIELD(M2C_FIELD(arg0,void **,0x30),f32 *,8);
 Unit_SetWorldXY(M2C_FIELD(arg0,void **,0x34),M2C_FIELD(arg0,f32 *,0x38),M2C_FIELD(arg0,f32 *,0x3C));
 unit=M2C_FIELD(arg0,void **,0x30);
 angle=fn_8004BDA8(unit,gHalf+(f32)M2C_FIELD(arg0,s32 *,0x44),gHalf+(f32)M2C_FIELD(arg0,s32 *,0x48));
 M2C_FIELD(key1,void **,0x30)=unit;
 GfxEnt_ForEachKey(E_MuFade_script,MuFade_UnlinkSame,key1);
 if(angle!=((f32)M2C_FIELD(unit,s16 *,0x15C)/lbl_8036ACE8)) {
 proc=Process_CreateEx(E_MuFade_script,(s32)arg0);
 M2C_FIELD(proc,void **,0x30)=unit;
 M2C_FIELD(proc,f32 *,0x34)=angle;
 M2C_FIELD(proc,s32 *,0x38)=16;
 }
 unit=M2C_FIELD(arg0,void **,0x34);
 angle=fn_8004BDA8(unit,gHalf+(f32)M2C_FIELD(arg0,s32 *,0x44),gHalf+(f32)M2C_FIELD(arg0,s32 *,0x48));
 M2C_FIELD(key2,void **,0x30)=unit;
 GfxEnt_ForEachKey(E_MuFade_script,MuFade_UnlinkSame,key2);
 if(angle!=((f32)M2C_FIELD(unit,s16 *,0x15C)/lbl_8036ACE8)) {
 proc=Process_CreateEx(E_MuFade_script,(s32)arg0);
 M2C_FIELD(proc,void **,0x30)=unit;
 M2C_FIELD(proc,f32 *,0x34)=angle;
 M2C_FIELD(proc,s32 *,0x38)=16;
 }
}

#pragma opt_strength_reduction off
/* Clear prior E_MuBlend/E_MuTransfer procs for the unit, scale hit count by class level, then start E_MuBlend mode 0. */
void Event_StartMuBlend(void *proc) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, void *);
    u8 fn_8004C0F0(void *);
    void fn_8004FE90(void *, u8);
    void fn_8004FE98(void *, s32);
    void fn_800506E0(void *, s32);
    void *fn_800508C4(void *);
    f32 Math_Lerp(f32, f32, f32, f32);
    void fn_8005FC74(void *, void *, s32);
    void fn_8005FEE8(void *, f32);
    s32 fn_80060440(void *);
    void *fn_800639B4(void);
    void MuFade_UnlinkSame(void *, void *);
    extern u8 E_MuBlend_script[];
    extern u8 E_MuTransfer_script[];
    extern f32 lbl_8036ACEC;
    extern f32 lbl_8036ACF0;
    extern f32 lbl_8036AD08;
    extern f64 lbl_8036ACE0;
    u8 blendKey[0x34];
    u8 transferKey[0x38];
    void *unit;
    s32 hitCount;
    void *animSrc;

    unit = *(void **)((u8 *)proc + 0x34);
    hitCount = 1;
    hitCount += 1;
    if (fn_8004C0F0(unit) != 0) {
        *(void **)(blendKey + 0x30) = unit;
        GfxEnt_ForEachKey(E_MuBlend_script, MuFade_UnlinkSame, blendKey);
        *(void **)(transferKey + 0x30) = unit;
        GfxEnt_ForEachKey(E_MuTransfer_script, MuFade_UnlinkSame, transferKey);
        {
            u8 level = *(u8 *)((u8 *)fn_800508C4(unit) + 9);
            if ((s32)level > 0x14) {
                if ((s32)level > 0x28) {
                    hitCount <<= 1;
                } else {
                    hitCount = (s32)((f32)hitCount + Math_Lerp(lbl_8036ACEC, lbl_8036AD08, lbl_8036ACF0, (f32)((s32)level - 0x14)));
                }
            }
        }
        if ((hitCount == 0) || (fn_80060440((u8 *)unit + 0x1C) >= 4)) {
            fn_8004FE98(unit, 0);
            return;
        }
        proc = Process_CreateEx(E_MuBlend_script, proc);
        *(void **)((u8 *)proc + 0x30) = unit;
        *(s32 *)((u8 *)proc + 0x34) = (s32)unit + 0x1C;
        *(s32 *)((u8 *)proc + 0x38) = 0;
        *(s32 *)((u8 *)proc + 0x3C) = hitCount;
        *(s32 *)((u8 *)proc + 0x40) = 0;
        fn_800506E0(*(void **)((u8 *)proc + 0x30), 0);
        animSrc = fn_800639B4();
        hitCount = 0;
        if (*(void **)((u8 *)*(void **)((u8 *)proc + 0x34) + 0x44) != NULL) {
            void *range = *(void **)((u8 *)*(void **)((u8 *)proc + 0x34) + 0x44);
            f32 rangeStart = (f32)*(s32 *)((u8 *)range + 0x14);
            hitCount = (s32)Math_Lerp((f32)*(s32 *)((u8 *)animSrc + 0x14), (f32)*(s32 *)((u8 *)animSrc + 0x18), (f32)*(s32 *)((u8 *)range + 0x18) - rangeStart, *(f32 *)((u8 *)*(void **)((u8 *)proc + 0x34) + 0x58) - rangeStart);
        }
        fn_8005FC74(*(void **)((u8 *)proc + 0x34), animSrc, 1);
        fn_8005FEE8(*(void **)((u8 *)proc + 0x34), (f32)hitCount);
        fn_8004FE90(*(void **)((u8 *)proc + 0x30), (u8)*(s32 *)((u8 *)proc + 0x38));
    }
}

void fn_80186E10(void *arg0) {
    f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
    void Unit_SetWorldXY(void *, f32, f32);
    void Model_SetAlpha(void *, u8);
    void Process_ClearFunc(void *);
    extern f32 lbl_8036ACF8;
    extern f32 lbl_8036AD00;
    extern f32 lbl_8036ACEC;
    extern f32 lbl_8036ACF4;
    void *p34;
    void *p30;
    void *r31;
    s32 r30;
    f32 f31;
    f32 tmp;
    f32 *pf;
    f32 start = lbl_8036AD00;
    f32 end = lbl_8036ACEC;
    f32 duration = lbl_8036ACF4;

    pf = (f32 *)((u8 *)arg0 + 0x44);
    *pf = lbl_8036ACF8 + *pf;
    p34 = *(void **)((u8 *)arg0 + 0x34);
    r31 = (u8 *)p34 + 0x1C;
    r30 = (s32)Math_EaseOutPow(2, start, end, duration, *(f32 *)((u8 *)arg0 + 0x44));
    p30 = *(void **)((u8 *)arg0 + 0x30);
    f31 = Math_EaseOutPow(2, *(f32 *)((u8 *)arg0 + 0x38), *(f32 *)((u8 *)p30 + 4), lbl_8036ACF4, *(f32 *)((u8 *)arg0 + 0x44));
    p30 = *(void **)((u8 *)arg0 + 0x30);
    tmp = Math_EaseOutPow(2, *(f32 *)((u8 *)arg0 + 0x3C), *(f32 *)((u8 *)p30 + 8), lbl_8036ACF4, *(f32 *)((u8 *)arg0 + 0x44));
    Unit_SetWorldXY(*(void **)((u8 *)arg0 + 0x34), f31, tmp);
    Model_SetAlpha(r31, (u8)r30);
    if (*(f32 *)((u8 *)arg0 + 0x44) == lbl_8036ACF4) {
        Process_ClearFunc(arg0);
    }
}

void fn_80186F0C(void *proc) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, s32);
    u8 fn_8004C0F0(void *);
    void fn_8004FE90(void *, u8);
    void fn_8004FE98(void *, s32);
    void fn_800506E0(void *, s32);
    void *fn_800508C4(void *);
    f32 Math_Lerp(f32, f32, f32, f32);
    void fn_8005FC74(void *, void *, s32);
    void fn_8005FEE8(void *, f32);
    s32 fn_80060440(void *);
    void *fn_800639B4(void);
    void MuFade_UnlinkSame(void *, void *);
    extern u8 E_MuBlend_script[];
    extern u8 E_MuTransfer_script[];
    extern f32 lbl_8036ACEC;
    extern f32 lbl_8036ACF0;
    extern f32 lbl_8036AD04;
    u8 blendKey[0x34];
    u8 transferKey[0x38];
    void *unit;
    void *animSrc;
    s32 hitCount;

    unit = *(void **)((u8 *)proc + 0x34);
    hitCount = 3;
    hitCount += 1;
    if (fn_8004C0F0(unit) != 0) {
        *(void **)(blendKey + 0x30) = unit;
        GfxEnt_ForEachKey(E_MuBlend_script, MuFade_UnlinkSame, blendKey);
        *(void **)(transferKey + 0x30) = unit;
        GfxEnt_ForEachKey(E_MuTransfer_script, MuFade_UnlinkSame, transferKey);
        {
            u8 level = *(u8 *)((u8 *)fn_800508C4(unit) + 9);
            if ((s32)level > 0x14) {
                if ((s32)level > 0x28) {
                    hitCount <<= 1;
                } else {
                    hitCount = (s32)((f32)hitCount + Math_Lerp(lbl_8036ACEC, lbl_8036AD04, lbl_8036ACF0, (f32)((s32)level - 0x14)));
                }
            }
        }
        if ((hitCount == 0) || (fn_80060440((u8 *)unit + 0x1C) >= 4)) {
            fn_8004FE98(unit, 1);
            return;
        }
        proc = Process_CreateEx(E_MuBlend_script, 0);
        *(void **)((u8 *)proc + 0x30) = unit;
        *(s32 *)((u8 *)proc + 0x34) = (s32)unit + 0x1C;
        *(s32 *)((u8 *)proc + 0x38) = 1;
        *(s32 *)((u8 *)proc + 0x3C) = hitCount;
        *(s32 *)((u8 *)proc + 0x40) = 0;
        fn_800506E0(*(void **)((u8 *)proc + 0x30), 1);
        animSrc = fn_800639B4();
        hitCount = 0;
        if (*(void **)((u8 *)*(void **)((u8 *)proc + 0x34) + 0x44) != NULL) {
            void *range = *(void **)((u8 *)*(void **)((u8 *)proc + 0x34) + 0x44);
            f32 rangeStart = (f32)*(s32 *)((u8 *)range + 0x14);
            hitCount = (s32)Math_Lerp((f32)*(s32 *)((u8 *)animSrc + 0x14), (f32)*(s32 *)((u8 *)animSrc + 0x18), (f32)*(s32 *)((u8 *)range + 0x18) - rangeStart, *(f32 *)((u8 *)*(void **)((u8 *)proc + 0x34) + 0x58) - rangeStart);
        }
        fn_8005FC74(*(void **)((u8 *)proc + 0x34), animSrc, 1);
        fn_8005FEE8(*(void **)((u8 *)proc + 0x34), (f32)hitCount);
        fn_8004FE90(*(void **)((u8 *)proc + 0x30), (u8)*(s32 *)((u8 *)proc + 0x38));
    }
}

#pragma opt_strength_reduction on

void fn_8018715C(void *arg0) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, void *);
    f32 Unit_GetAngleTo(void *);
    void MuFade_UnlinkSame(void *, void *);
    extern u16 E_MuFade_script[36];
    extern f32 lbl_8036ACEC;
    struct Fields {
        char pad[0x30];
        void *field30;
        void *field34;
        f32 field38;
        f32 field3C;
        char pad2[4];
        f32 field44;
    };
    struct Fields *p = (struct Fields *)arg0;
    void *check;
    void *temp_r30;
    void *temp_r3;
    f32 temp_f31;
    u8 sp[0x70];

    p->field44 = lbl_8036ACEC;
    p->field38 = *(f32 *)((u8 *)p->field34 + 4);
    p->field3C = *(f32 *)((u8 *)p->field34 + 8);

    check = p->field34;
    temp_r30 = p->field30;
    if (check) {
        temp_f31 = Unit_GetAngleTo(temp_r30);
        *(void **)(sp + 0x68) = temp_r30;
        GfxEnt_ForEachKey(&E_MuFade_script, MuFade_UnlinkSame, sp + 0x38);
        if (temp_f31 != ((f32)*(s16 *)((u8 *)temp_r30 + 0x15C) / 50.0f)) {
            temp_r3 = Process_CreateEx(&E_MuFade_script, arg0);
            *(void **)((u8 *)temp_r3 + 0x30) = temp_r30;
            *(f32 *)((u8 *)temp_r3 + 0x34) = temp_f31;
            *(s32 *)((u8 *)temp_r3 + 0x38) = 0x10;
        }
    }

    check = p->field30;
    temp_r30 = p->field34;
    if (check) {
        temp_f31 = Unit_GetAngleTo(temp_r30);
        *(void **)(sp + 0x30) = temp_r30;
        GfxEnt_ForEachKey(&E_MuFade_script, MuFade_UnlinkSame, sp);
        if (temp_f31 != ((f32)*(s16 *)((u8 *)temp_r30 + 0x15C) / 50.0f)) {
            temp_r3 = Process_CreateEx(&E_MuFade_script, arg0);
            *(void **)((u8 *)temp_r3 + 0x30) = temp_r30;
            *(f32 *)((u8 *)temp_r3 + 0x34) = temp_f31;
            *(s32 *)((u8 *)temp_r3 + 0x38) = 0x10;
        }
    }
}

void fn_801872CC(void *arg0)
{
    extern void fn_8004FE98(void *, s32);

    u8 *obj;
    void (*callback)(void *);

    obj = (u8 *)arg0;

    if (obj[0x48] == 0) {
        fn_8004FE98(*(void **)(obj + 0x30), 0);

        if (*(void **)(obj + 0x34) != 0) {
            fn_8004FE98(*(void **)(obj + 0x34), 0);
        }
    }

    if (obj[0x49] == 0) {
        callback = *(void (**)(void *))(obj + 0x40);

        if (callback != 0) {
            callback(*(void **)(obj + 0x44));
        }
    }
}

void fn_80187344(void *arg0) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, void *);
    u8 fn_8004C0F0(u32);
    void fn_8004FE90(u32, u8);
    void fn_8004FE98(u32, s32);
    void fn_800506E0(u32, s32);
    void *fn_800508C4(u32);
    f32 Math_Lerp(f32, f32, f32, f32);
    void fn_8005FC74(void *, void *, s32);
    void fn_8005FEE8(void *, f32);
    s32 fn_80060440(s32);
    void *fn_800639B4(void);
    extern u8 E_MuBlend_script[];
    extern u8 E_MuTransfer_script[];
    extern f32 lbl_8036ACEC;
    extern f32 lbl_8036ACF0;
    extern f32 lbl_8036ACF4;
    struct { u8 pad[0x30]; u32 val; } spB0;
    struct { u8 pad[0x30]; u32 val; } sp78;
    struct { u8 pad[0x30]; u32 val; } sp40;
    struct { u8 pad[0x30]; u32 val; } sp8;
    s32 var_r28;
    u32 temp_r29;
    void *temp_r30;
    void *tmp;
    void *temp_r7;
    void *temp_r4;
    f32 temp_f3;
    u8 temp_r3;

    var_r28 = 0x10;
    temp_r29 = *(u32 *)((u8 *)arg0 + 0x30);
    if (fn_8004C0F0(temp_r29) != 0) {
        spB0.val = temp_r29;
        GfxEnt_ForEachKey(E_MuBlend_script, MuFade_UnlinkSame, &spB0);
        sp78.val = temp_r29;
        GfxEnt_ForEachKey(E_MuTransfer_script, MuFade_UnlinkSame, &sp78);
        temp_r3 = *(u8 *)((u8 *)fn_800508C4(temp_r29) + 9);
        if ((s32)temp_r3 > 0x14) {
            if ((s32)temp_r3 > 0x28) {
                var_r28 <<= 1;
            } else {
                var_r28 = (s32)((f32)var_r28 + Math_Lerp(lbl_8036ACEC, lbl_8036ACF4, lbl_8036ACF0, (f32)((s32)temp_r3 - 0x14)));
            }
        }
        if ((var_r28 == 0) || (fn_80060440(temp_r29 + 0x1C) >= 4)) {
            fn_8004FE98(temp_r29, 0);
        } else {
            temp_r30 = Process_CreateEx(E_MuBlend_script, arg0);
            *(u32 *)((u8 *)temp_r30 + 0x30) = temp_r29;
            *(void **)((u8 *)temp_r30 + 0x34) = (void *)(temp_r29 + 0x1C);
            *(s32 *)((u8 *)temp_r30 + 0x38) = 0;
            *(s32 *)((u8 *)temp_r30 + 0x3C) = var_r28;
            *(s32 *)((u8 *)temp_r30 + 0x40) = 0;
            fn_800506E0(*(u32 *)((u8 *)temp_r30 + 0x30), 0);
            temp_r7 = *(void **)((u8 *)temp_r30 + 0x34);
            tmp = fn_800639B4();
            var_r28 = 0;
            temp_r4 = *(void **)((u8 *)temp_r7 + 0x44);
            if (temp_r4 != NULL) {
                temp_f3 = (f32)*(s32 *)((u8 *)temp_r4 + 0x14);
                var_r28 = (s32)Math_Lerp((f32)*(s32 *)((u8 *)tmp + 0x14), (f32)*(s32 *)((u8 *)tmp + 0x18), (f32)*(s32 *)((u8 *)temp_r4 + 0x18) - temp_f3, *(f32 *)((u8 *)temp_r7 + 0x58) - temp_f3);
            }
            fn_8005FC74(*(void **)((u8 *)temp_r30 + 0x34), tmp, 1);
            fn_8005FEE8(*(void **)((u8 *)temp_r30 + 0x34), (f32)var_r28);
            fn_8004FE90(*(u32 *)((u8 *)temp_r30 + 0x30), (u8)*(s32 *)((u8 *)temp_r30 + 0x38));
        }
    }
    temp_r29 = *(u32 *)((u8 *)arg0 + 0x34);
    if (temp_r29 != 0) {
        var_r28 = 0x10;
        if (fn_8004C0F0(temp_r29) != 0) {
            sp40.val = temp_r29;
            GfxEnt_ForEachKey(E_MuBlend_script, MuFade_UnlinkSame, &sp40);
            sp8.val = temp_r29;
            GfxEnt_ForEachKey(E_MuTransfer_script, MuFade_UnlinkSame, &sp8);
            temp_r3 = *(u8 *)((u8 *)fn_800508C4(temp_r29) + 9);
            if ((s32)temp_r3 > 0x14) {
                if ((s32)temp_r3 > 0x28) {
                    var_r28 <<= 1;
                } else {
                    var_r28 = (s32)((f32)var_r28 + Math_Lerp(lbl_8036ACEC, lbl_8036ACF4, lbl_8036ACF0, (f32)((s32)temp_r3 - 0x14)));
                }
            }
            if ((var_r28 == 0) || (fn_80060440(temp_r29 + 0x1C) >= 4)) {
                fn_8004FE98(temp_r29, 0);
            } else {
                temp_r30 = Process_CreateEx(E_MuBlend_script, arg0);
                *(u32 *)((u8 *)temp_r30 + 0x30) = temp_r29;
                *(void **)((u8 *)temp_r30 + 0x34) = (void *)(temp_r29 + 0x1C);
                *(s32 *)((u8 *)temp_r30 + 0x38) = 0;
                *(s32 *)((u8 *)temp_r30 + 0x3C) = var_r28;
                *(s32 *)((u8 *)temp_r30 + 0x40) = 0;
                fn_800506E0(*(u32 *)((u8 *)temp_r30 + 0x30), 0);
                temp_r7 = *(void **)((u8 *)temp_r30 + 0x34);
                tmp = fn_800639B4();
                var_r28 = 0;
                temp_r4 = *(void **)((u8 *)temp_r7 + 0x44);
                if (temp_r4 != NULL) {
                    temp_f3 = (f32)*(s32 *)((u8 *)temp_r4 + 0x14);
                    var_r28 = (s32)Math_Lerp((f32)*(s32 *)((u8 *)tmp + 0x14), (f32)*(s32 *)((u8 *)tmp + 0x18), (f32)*(s32 *)((u8 *)temp_r4 + 0x18) - temp_f3, *(f32 *)((u8 *)temp_r7 + 0x58) - temp_f3);
                }
                fn_8005FC74(*(void **)((u8 *)temp_r30 + 0x34), tmp, 1);
                fn_8005FEE8(*(void **)((u8 *)temp_r30 + 0x34), (f32)var_r28);
                fn_8004FE90(*(u32 *)((u8 *)temp_r30 + 0x30), (u8)*(s32 *)((u8 *)temp_r30 + 0x38));
            }
        }
    }
    *((u8 *)arg0 + 0x48) = 1;
}

#pragma global_optimizer off
void fn_801877C4(void *arg0) {
    void fn_800056A0(s32);
    void GfxEnt_ForEachKey(void *, void *, void *);
    void Process_ClearFunc(void *);
    void *Process_CreateEx(void *, void *);
    void *Process_Create(void *, s32);
    f32 Map_SampleHeightRaw(void *, f32, f32);
    void fn_80025624(void *, s32);
    f32 Unit_GetAngleTo(void *);
    u8 Mu_IsAnimDone(void *);
    u8 fn_8004C0F0(void *);
    void fn_8004FE90(void *, u8);
    void fn_8004FE98(void *, s32);
    void fn_800506E0(void *, s32);
    void *fn_800508C4(void *);
    u32 Mu_GetFlashColor(s32);
    void Effect_SetPos(f32, f32, f32);
    void *Effect_Create(void *, void *);
    f32 Math_Angle2D(void *, f32, f32, f32, f32);
    f32 Math_Lerp(f32, f32, f32, f32);
    u8 Pad_IsButton(void *, s32);
    void fn_8005FC74(void *, void *, s32);
    void fn_8005FEE8(void *, f32);
    s32 fn_80060440(void *);
    void *fn_800639B4(void);
    s8 SeCue_PlayAt(void *, s32, f32, f32, f32);
    void MuFade_UnlinkSame(void *, void *);
    void fn_8018CFA4(s32, s32, s32, s32, void *);
    s32 Abs(s32);
    extern u8 MoveAnim_str[];
    extern u8 E_MuBlend_script[];
    extern u8 gBattleMap[];
    extern void *gPadInput;
    extern f32 gHalf;
    extern f32 lbl_8036ACEC;
    extern f32 lbl_8036ACF0;
    extern f32 lbl_8036AD08;

    u8 gap[8];
    u8 sp7C[0x38];
    u8 sp44[0x38];
    u8 spC[0x38];
    u32 sp8;
    f32 f31;
    f32 f30;
    f32 f29;
    f32 f28;
    s32 z;
    void (*cb)(s32);
    u8 *msg;
    void *pos;
    void *obj;
    s32 count;
    void *tmp;
    u8 *base;

    base = E_MuBlend_script;
    z = 0x40;
    if (Pad_IsButton((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0x1C, 0) != 0) {
        pos = *(void **)((u8 *)arg0 + 0x34);
        if (pos != 0) {
            f31 = *(f32 *)((u8 *)pos + 4);
            f30 = *(f32 *)((u8 *)pos + 8);
            f29 = *(f32 *)((u8 *)pos + 0xC);
            f28 = Unit_GetAngleTo(*(void **)((u8 *)arg0 + 0x30));
            obj = *(void **)((u8 *)arg0 + 0x34);
            count = 1;
            count += 1;
            if (fn_8004C0F0(obj) != 0) {
                *(void **)(sp7C + 0x30) = obj;
                GfxEnt_ForEachKey(base + (z - 0x40), MuFade_UnlinkSame, sp7C);
                *(void **)(sp44 + 0x30) = obj;
                GfxEnt_ForEachKey(base + 0x20, MuFade_UnlinkSame, sp44);
                {
                    u8 lvl = *(u8 *)((u8 *)fn_800508C4(obj) + 9);
                    if ((s32)lvl > 0x14) {
                        if ((s32)lvl > 0x28) {
                            count <<= 1;
                        } else {
                            count = (s32)((f32)count + Math_Lerp(lbl_8036ACEC, lbl_8036AD08, lbl_8036ACF0, (f32)((s32)lvl - 0x14)));
                        }
                    }
                }
                if ((count == 0) || (fn_80060440((u8 *)obj + 0x1C) >= 4)) {
                    fn_8004FE98(obj, 9);
                } else {
                    tmp = Process_CreateEx(base + (z - 0x40), arg0);
                    *(void **)((u8 *)tmp + 0x30) = obj;
                    *(s32 *)((u8 *)tmp + 0x34) = (s32)obj + 0x1C;
                    *(s32 *)((u8 *)tmp + 0x38) = 9;
                    *(s32 *)((u8 *)tmp + 0x3C) = count;
                    *(s32 *)((u8 *)tmp + 0x40) = 0;
                    fn_800506E0(*(void **)((u8 *)tmp + 0x30), 9);
                    fn_8005FC74(*(void **)((u8 *)tmp + 0x34), fn_800639B4(), 1);
                    fn_8005FEE8(*(void **)((u8 *)tmp + 0x34), lbl_8036ACEC);
                    fn_8004FE90(*(void **)((u8 *)tmp + 0x30), (u8)*(s32 *)((u8 *)tmp + 0x38));
                }
            }
            count = (s32)*(void **)((u8 *)arg0 + 0x34);
            obj = arg0;
            *(s32 *)(spC + 0x30) = count;
            GfxEnt_ForEachKey(base + 0xC0, MuFade_UnlinkSame, spC);
            if (arg0 == 0) {
                obj = (void *)3;
            }
            tmp = Process_Create(base + 0xC0, (s32)obj);
            *(s32 *)((u8 *)tmp + 0x30) = count;
            *(s32 *)((u8 *)tmp + 0x40) = 2;
            sp8 = Mu_GetFlashColor(1);
            *(u8 *)((u8 *)tmp + 0x38) = ((u8 *)&sp8)[0];
            *(u8 *)((u8 *)tmp + 0x39) = ((u8 *)&sp8)[1];
            *(u8 *)((u8 *)tmp + 0x3A) = ((u8 *)&sp8)[2];
            *(u8 *)((u8 *)tmp + 0x3B) = ((u8 *)&sp8)[3];
            Process_Create(base + 0x238, (s32)arg0);
        } else {
            f32 t8;
            f31 = gHalf + (f32)*(s8 *)((u8 *)arg0 + 0x3A);
            f30 = gHalf + (f32)*(s8 *)((u8 *)arg0 + 0x3B);
            f29 = Map_SampleHeightRaw(gBattleMap, f31, f30);
            tmp = *(void **)((u8 *)arg0 + 0x30);
            t8 = *(f32 *)((u8 *)tmp + 8);
            f28 = Math_Angle2D(tmp, *(f32 *)((u8 *)tmp + 4), t8, f31, f30);
        }
        count = Abs((s32)*(s8 *)((u8 *)arg0 + 0x3A) - (s32)*(s8 *)((u8 *)arg0 + 0x38));
        count += Abs((s32)*(s8 *)((u8 *)arg0 + 0x3B) - (s32)*(s8 *)((u8 *)arg0 + 0x39));
        msg = MoveAnim_str + 0x371;
        if (count >= 2) {
            msg = MoveAnim_str + 0x360;
        }
        base = Effect_Create(msg, arg0);
        Effect_SetPos(f31, f30, f29);
        *(f32 *)((u8 *)*(void **)((u8 *)base + 0x30) + 0x24) = f28;
        cb = *(void (**)(s32))((u8 *)arg0 + 0x40);
        if (cb != 0) {
            cb(*(s32 *)((u8 *)arg0 + 0x44));
            *(u8 *)((u8 *)arg0 + 0x49) = 1;
        }
        SeCue_PlayAt(MoveAnim_str + 0x37C, 0x64, f31, f30, f29);
        fn_8018CFA4(0xF, 6, 2, 0, arg0);
        fn_80025624(gPadInput, 8);
        Process_ClearFunc(arg0);
        return;
    }
    if (Mu_IsAnimDone(*(void **)((u8 *)arg0 + 0x30)) != 0) {
        fn_800056A0(0);
        Process_ClearFunc(arg0);
    }
    (void)gap;
}

void fn_80187BD4(void *arg0) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, s32);
    u8 fn_8004C0F0(void *);
    void fn_8004FE90(void *, u8);
    void fn_8004FE98(void *, s32);
    void fn_800506E0(void *, s32);
    void *fn_800508C4(void *);
    f32 Math_Lerp(f32,f32,f32,f32);
    void fn_8005FC74(void *,void *,s32);
    void fn_8005FEE8(void *,f32);
    s32 fn_80060440(void *);
    void *fn_800639B4(void);
    void MuFade_UnlinkSame(void *,void *);
    extern u8 E_MuBlend_script[], E_MuTransfer_script[];
    extern f32 lbl_8036ACEC,lbl_8036AD0C,lbl_8036ACF0;
    u8 sp40[0x34];
    u8 sp8[0x38];
    void *obj;
    s32 count;
    void *node;
    s32 level;
    count=8;
    obj=M2C_FIELD(arg0,void **,0x30);
    if(fn_8004C0F0(obj)) {
        *(void **)(sp40+0x30)=obj;
        GfxEnt_ForEachKey(E_MuBlend_script,MuFade_UnlinkSame,sp40);
        *(void **)(sp8+0x30)=obj;
        GfxEnt_ForEachKey(E_MuTransfer_script,MuFade_UnlinkSame,sp8);
        level=M2C_FIELD(fn_800508C4(obj),u8 *,9);
        if(level>20) {
            if(level>40) count<<=1;
            else count=(s32)((f32)count+Math_Lerp(lbl_8036ACEC,lbl_8036AD0C,lbl_8036ACF0,(f32)(level-20)));
        }
        if(count==0 || fn_80060440((u8 *)obj+0x1C)>=4) {
            fn_8004FE98(obj,6);
        } else {
            node=Process_CreateEx(E_MuBlend_script,0);
            M2C_FIELD(node,void **,0x30)=obj;
            M2C_FIELD(node,void **,0x34)=(u8 *)obj+0x1C;
            M2C_FIELD(node,s32 *,0x38)=6;
            M2C_FIELD(node,s32 *,0x3C)=count;
            M2C_FIELD(node,s32 *,0x40)=0;
            fn_800506E0(M2C_FIELD(node,void **,0x30),6);
            fn_8005FC74(M2C_FIELD(node,void **,0x34),fn_800639B4(),1);
            fn_8005FEE8(M2C_FIELD(node,void **,0x34),lbl_8036ACEC);
            fn_8004FE90(M2C_FIELD(node,void **,0x30),(u8)M2C_FIELD(node,s32 *,0x38));
        }
    }
}

#pragma global_optimizer reset
void fn_80187D70(void *arg0) {
    void fn_8000A388(void *, void *, void *);
    void *fn_8000CA64(void *, void *);
    f32 fn_8004BE18(void *);
    f32 fn_8004BDA8(void *, f32, f32);
    void fn_8004FC70(void *, s32);
    void fn_800558D8(void *);
    s32 fn_80230BCC(s32);
    void fn_80185078(void *, void *);
    extern u16 lbl_80295A78[36];
    extern u8 lbl_80278E24[];
    extern f32 lbl_8036ACEC;
    extern f32 lbl_8036ACD8;

    u8 sp[0x70];
    void *unit;
    void *node;
    f32 f;
    void *msg;
    register void *temp_r4;
    s32 a;
    s32 b;
    s32 sum;

    *(f32 *)((u8 *)arg0 + 0x3C) = lbl_8036ACEC;
    fn_8004FC70(*(void **)((u8 *)arg0 + 0x30), 6);
    temp_r4 = *(void **)((u8 *)arg0 + 0x34);
    if (temp_r4 != NULL) {
        unit = *(void **)((u8 *)arg0 + 0x30);
        if (temp_r4 != NULL) {
            f = fn_8004BE18(unit);
            *(void **)(sp + 0x68) = unit;
            fn_8000A388(&lbl_80295A78, fn_80185078, sp + 0x38);
            if (f != ((f32)*(s16 *)((u8 *)unit + 0x15C) / 50.0f)) {
                node = fn_8000CA64(&lbl_80295A78, arg0);
                *(void **)((u8 *)node + 0x30) = unit;
                *(f32 *)((u8 *)node + 0x34) = f;
                *(s32 *)((u8 *)node + 0x38) = 0x10;
            }
        }
        *(u8 *)((u8 *)arg0 + 0x38) = (s8)(s32)*(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x34) + 4);
        *(u8 *)((u8 *)arg0 + 0x39) = (s8)(s32)*(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x34) + 8);
        fn_8004FC70(*(void **)((u8 *)arg0 + 0x34), 9);
    } else {
        unit = *(void **)((u8 *)arg0 + 0x30);
        f = fn_8004BDA8(unit, lbl_8036ACD8 + (f32)(s8)*(u8 *)((u8 *)arg0 + 0x3A), lbl_8036ACD8 + (f32)(s8)*(u8 *)((u8 *)arg0 + 0x3B));
        *(void **)(sp + 0x30) = unit;
        fn_8000A388(&lbl_80295A78, fn_80185078, sp);
        if (f != ((f32)*(s16 *)((u8 *)unit + 0x15C) / 50.0f)) {
            node = fn_8000CA64(&lbl_80295A78, arg0);
            *(void **)((u8 *)node + 0x30) = unit;
            *(f32 *)((u8 *)node + 0x34) = f;
            *(s32 *)((u8 *)node + 0x38) = 0x10;
        }
        *(u8 *)((u8 *)arg0 + 0x38) = *(u8 *)((u8 *)arg0 + 0x3A);
        *(u8 *)((u8 *)arg0 + 0x39) = *(u8 *)((u8 *)arg0 + 0x3B);
    }
    a = fn_80230BCC((s8)*(u8 *)((u8 *)arg0 + 0x3A) - (s8)*(u8 *)((u8 *)arg0 + 0x38));
    b = fn_80230BCC((s8)*(u8 *)((u8 *)arg0 + 0x3B) - (s8)*(u8 *)((u8 *)arg0 + 0x39));
    sum = a + b;
    if (sum >= 2) {
        msg = lbl_80278E24 + 0x360;
    } else {
        msg = lbl_80278E24 + 0x371;
    }
    fn_800558D8(msg);
}

#pragma opt_strength_reduction on
#pragma optimization_level 4
void fn_80187FBC(void *arg0) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, s32);
    u8 fn_8004C0F0(void *);
    void fn_8004FE90(void *, u8);
    void fn_8004FE98(void *, s32);
    void fn_800506E0(void *, s32);
    void *fn_800508C4(void *);
    f32 Math_Lerp(f32, f32, f32, f32);
    void fn_8005FC74(void *, void *, s32);
    void fn_8005FEE8(void *, f32);
    s32 fn_80060440(void *);
    void *fn_800639B4(void);
    void MuFade_UnlinkSame(void *, void *);
    extern u8 E_MuBlend_script[];
    extern u8 E_MuTransfer_script[];
    extern f32 lbl_8036ACEC;
    extern f32 lbl_8036ACF0;
    extern f32 lbl_8036ACF4;
    u8 sp40[0x34];
    u8 sp8[0x38];
    void *node;
    void *obj;
    s32 count;
    void *temp_r7;
    void *temp_r4;
    s32 lvl;
    f32 temp_f3;

    node = 0;
    count = 8;
    count += 8;
    obj = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x18) + 0x34);
    if (fn_8004C0F0(obj) != 0) {
        *(void **)(sp40 + 0x30) = obj;
        GfxEnt_ForEachKey(E_MuBlend_script, MuFade_UnlinkSame, sp40);
        *(void **)(sp8 + 0x30) = obj;
        GfxEnt_ForEachKey(E_MuTransfer_script, MuFade_UnlinkSame, sp8);
        lvl = *(u8 *)((u8 *)fn_800508C4(obj) + 9);
        if (lvl > 0x14) {
            if (lvl > 0x28) {
                count <<= 1;
            } else {
                count = (s32)((f32)count + Math_Lerp(lbl_8036ACEC, lbl_8036ACF4, lbl_8036ACF0, (f32)(lvl - 0x14)));
            }
        }
        if ((count == 0) || (fn_80060440((u8 *)obj + 0x1C) >= 4)) {
            fn_8004FE98(obj, 0);
        } else {
            node = Process_CreateEx(E_MuBlend_script, 0);
            *(void **)((u8 *)node + 0x30) = obj;
            *(void **)((u8 *)node + 0x34) = (void *)((s32)obj + 0x1C);
            *(s32 *)((u8 *)node + 0x38) = 0;
            *(s32 *)((u8 *)node + 0x3C) = count;
            *(s32 *)((u8 *)node + 0x40) = 0;
            fn_800506E0(*(void **)((u8 *)node + 0x30), 0);
            obj = fn_800639B4();
            count = 0;
            temp_r7 = *(void **)((u8 *)node + 0x34);
            temp_r4 = *(void **)((u8 *)temp_r7 + 0x44);
            if (temp_r4 != NULL) {
                temp_f3 = (f32)*(s32 *)((u8 *)temp_r4 + 0x14);
                count = (s32)Math_Lerp((f32)*(s32 *)((u8 *)obj + 0x14), (f32)*(s32 *)((u8 *)obj + 0x18), (f32)*(s32 *)((u8 *)temp_r4 + 0x18) - temp_f3, *(f32 *)((u8 *)temp_r7 + 0x58) - temp_f3);
            }
            fn_8005FC74(*(void **)((u8 *)node + 0x34), obj, 1);
            fn_8005FEE8(*(void **)((u8 *)node + 0x34), (f32)count);
            fn_8004FE90(*(void **)((u8 *)node + 0x30), (u8)*(s32 *)((u8 *)node + 0x38));
        }
    }
}
#pragma optimization_level 4
#pragma opt_strength_reduction on

#pragma global_optimizer off
void fn_8018820C(void *arg0)
{
  void Unit_SetWorldXY(s32, f32, f32);
  f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
  extern f32 gHalf;
  extern f32 lbl_8036AD0C;
  f32 temp_f1;
  f32 temp_f31;
  void *temp_r31;
  temp_r31 = *((void **) (((u8 *) arg0) + 0x18));
  temp_f31 = *((s32 *) (((u8 *) arg0) + 0x60));
  *((s32 *) (((u8 *) arg0) + 0x60)) = temp_f31 + 1;
  temp_f31 = Math_EaseOutPow(2, gHalf + ((f32) ((s8) (*((u8 *) (((u8 *) temp_r31) + 0x38))))), gHalf + ((f32) ((s8) (*((u8 *) (((u8 *) temp_r31) + 0x3A))))), lbl_8036AD0C, (f32) (*((s32 *) (((u8 *) arg0) + 0x60))));
  temp_f1 = Math_EaseOutPow(2, gHalf + ((f32) ((s8) (*((u8 *) (((u8 *) temp_r31) + 0x39))))), gHalf + ((f32) ((s8) (*((u8 *) (((u8 *) temp_r31) + 0x3B))))), lbl_8036AD0C, (f32) (*((s32 *) (((u8 *) arg0) + 0x60))));
  Unit_SetWorldXY(*((s32 *) (((u8 *) temp_r31) + 0x34)), temp_f31, temp_f1);
  if ((*((s32 *) (((u8 *) arg0) + 0x60))) >= 8)
  {
    Process_ClearFunc(arg0);
  }
}
#pragma global_optimizer on
void fn_80188368(void *arg0) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, s32);
    u8 fn_8004C0F0(void *);
    void fn_8004FE90(void *, u8);
    void fn_8004FE98(void *, s32);
    void fn_800506E0(void *, s32);
    void *fn_800508C4(void *);
    f32 Math_Lerp(f32,f32,f32,f32);
    void fn_8005FC74(void *,void *,s32);
    void fn_8005FEE8(void *,f32);
    s32 fn_80060440(void *);
    void *fn_800639B4(void);
    void MuFade_UnlinkSame(void *,void *);
    extern u8 E_MuBlend_script[], E_MuTransfer_script[];
    extern f32 lbl_8036ACEC,lbl_8036AD08,lbl_8036ACF0;
    u8 sp40[0x34];
    u8 sp8[0x38];
    void *obj;
    s32 count;
    void *node;
    s32 level;
    count=2;
    obj=M2C_FIELD(M2C_FIELD(arg0,void **,0x18),void **,0x34);
    if(fn_8004C0F0(obj)) {
        *(void **)(sp40+0x30)=obj;
        GfxEnt_ForEachKey(E_MuBlend_script,MuFade_UnlinkSame,sp40);
        *(void **)(sp8+0x30)=obj;
        GfxEnt_ForEachKey(E_MuTransfer_script,MuFade_UnlinkSame,sp8);
        level=M2C_FIELD(fn_800508C4(obj),u8 *,9);
        if(level>20) {
            if(level>40) count<<=1;
            else { f32 delta=Math_Lerp(lbl_8036ACEC,lbl_8036AD08,lbl_8036ACF0,(f32)(level-20)); count+=delta; };
        }
        if(count==0 || fn_80060440((u8 *)obj+0x1C)>=4) {
            fn_8004FE98(obj,9);
        } else {
            node=Process_CreateEx(E_MuBlend_script,0);
            M2C_FIELD(node,void **,0x30)=obj;
            M2C_FIELD(node,void **,0x34)=(void *)((u32)obj+0x1C);
            M2C_FIELD(node,s32 *,0x38)=9;
            M2C_FIELD(node,s32 *,0x3C)=count;
            M2C_FIELD(node,s32 *,0x40)=0;
            fn_800506E0(M2C_FIELD(node,void **,0x30),9);
            fn_8005FC74(M2C_FIELD(node,void **,0x34),fn_800639B4(),1);
            fn_8005FEE8(M2C_FIELD(node,void **,0x34),lbl_8036ACEC);
            fn_8004FE90(M2C_FIELD(node,void **,0x30),(u8)M2C_FIELD(node,s32 *,0x38));
        }
    }
    M2C_FIELD(arg0,s32 *,0x60)=0;
}

#pragma use_lmw_stmw on
void MoveAnim_BuildPathHeights(void *arg0) {
f32 Map_SampleHeightRaw(void *,f32,f32); f32 Math_Lerp(f32,f32,f32,f32);
extern u8 gBattleMap[]; extern f32 gHalf,lbl_8036ACEC;
u8 *self=arg0;
PathHeightPoint *point; PathHeightPoint *anchor; u8 *dir;
s32 i; s32 count,y,x; f32 delta,offset,zero;
if(*(u16 *)(self+0x52)&0x8000) {
f32 *pos=*(f32 **)(self+0x30);
{ PathHeightPoint *initial=*(PathHeightPoint **)(self+0x6C); point=initial; anchor=initial; }
dir=*(u8 **)(self+0x54); x=(s32)pos[1]; y=(s32)pos[2]; offset=gHalf; zero=lbl_8036ACEC;
for(count=0;count<128;count++,dir++,point++) {
point->rawHeight=Map_SampleHeightRaw(gBattleMap,offset+(f32)x,offset+(f32)y);
point->index=count; point->height=point->rawHeight;
delta=point->height-anchor->height;
if(delta<zero) {
s32 off; PathHeightPoint *sample;
for(i=anchor->index+1,off=i*12;i<point->index;off+=12,i++) {
sample=(PathHeightPoint *)((u8 *)*(PathHeightPoint **)(self+0x6C)+off);
sample->height=Math_Lerp(anchor->height,point->height,(f32)(point->index-anchor->index),(f32)(sample->index-anchor->index));
} anchor=point;
}
if(delta>zero) {
if(*dir==16) {
s32 off; PathHeightPoint *sample;
for(i=point->index;i>=anchor->index;i--) {
sample=*(PathHeightPoint **)(self+0x6C)+i;
if(point->rawHeight>sample->rawHeight) {anchor=sample;break;}
}
for(i=anchor->index+1,off=i*12;i<point->index;off+=12,i++) {
sample=(PathHeightPoint *)((u8 *)*(PathHeightPoint **)(self+0x6C)+off);
sample->height=Math_Lerp(anchor->height,point->height,(f32)(point->index-anchor->index),(f32)(sample->index-anchor->index));
}
} else point->height=anchor->height;
}
if(*dir==16) break;
switch(*dir) {case 8:y--;break;case 4:y++;break;case 1:x--;break;case 2:x++;break;}
}
}
}

void MoveAnim_AttachClassCue(void *anim) {
    s32 Str_Cmp(void *, void *);
    s32 DebugPrint(const char *, ...);
    s8 SeCue_PlayAt(void *, s32, f32, f32, f32);
    extern u8 MoveAnim_str[];
    void *klass;
    void *cuePath;
    void *unit;
    f32 x;
    f32 y;
    f32 z;

    /* For class-type 9 units, pick an SE cue from JID/PID and attach it to the MoveAnim. */
    cuePath = NULL;
    unit = *(void **)((u8 *)anim + 0x30);
    klass = *(void **)((u8 *)unit + 0x18C);
    if (*(u8 *)((u8 *)klass + 0x42) == 9) {
        if (Str_Cmp(*(void **)klass, MoveAnim_str + 0x3AB) == 0) {
            cuePath = MoveAnim_str + 0x393;
        }
        if (Str_Cmp(*(void **)klass, MoveAnim_str + 0x3BF) == 0) {
            cuePath = MoveAnim_str + 0x393;
        }
        if (Str_Cmp(*(void **)klass, MoveAnim_str + 0x3D2) == 0) {
            cuePath = MoveAnim_str + 0x393;
        }
        if (Str_Cmp(*(void **)klass, MoveAnim_str + 0x3FF) == 0) {
            cuePath = MoveAnim_str + 0x3E7;
        }
        if (Str_Cmp(*(void **)klass, MoveAnim_str + 0x410) == 0) {
            cuePath = MoveAnim_str + 0x3E7;
        }
        if (Str_Cmp(*(void **)klass, MoveAnim_str + 0x423) == 0) {
            cuePath = MoveAnim_str + 0x3E7;
        }
        if (Str_Cmp(*(void **)klass, MoveAnim_str + 0x434) == 0) {
            cuePath = MoveAnim_str + 0x3E7;
        }
        if (Str_Cmp(*(void **)klass, MoveAnim_str + 0x312) == 0) {
            cuePath = MoveAnim_str + 0x447;
        }
        if (Str_Cmp(*(void **)klass, MoveAnim_str + 0x332) == 0) {
            cuePath = MoveAnim_str + 0x447;
        }
        if (Str_Cmp(*(void **)klass, MoveAnim_str + 0x33E) == 0) {
            cuePath = MoveAnim_str + 0x447;
        }
        if (Str_Cmp(*(void **)klass, MoveAnim_str + 0x2E7) == 0) {
            cuePath = MoveAnim_str + 0x45F;
        }
        if (Str_Cmp(*(void **)klass, MoveAnim_str + 0x305) == 0) {
            cuePath = MoveAnim_str + 0x45F;
        }
        if (Str_Cmp(*(void **)klass, MoveAnim_str + 0x2BC) == 0) {
            cuePath = MoveAnim_str + 0x477;
        }
        if (Str_Cmp(*(void **)klass, MoveAnim_str + 0x2DA) == 0) {
            cuePath = MoveAnim_str + 0x477;
        }
        unit = *(void **)((u8 *)anim + 0x30);
        if (Str_Cmp(**(void ***)((u8 *)unit + 0x188), MoveAnim_str + 0x4A7) == 0) {
            cuePath = MoveAnim_str + 0x48F;
        }
        if (cuePath != NULL) {
            unit = *(void **)((u8 *)anim + 0x30);
            x = *(f32 *)((u8 *)unit + 4);
            y = *(f32 *)((u8 *)unit + 8);
            z = *(f32 *)((u8 *)unit + 0xC);
            DebugPrint((char *)(MoveAnim_str + 0x4B3), cuePath);
            *(s8 *)((u8 *)anim + 0x6A) = SeCue_PlayAt(cuePath, 0x64, x, y, z);
        }
    }
}

static inline u8 MoveAnim_IsBlendMode(u8 mode) {
    u8 enabled = 1;
    if (!(1 >= (u8)(mode - 1))) enabled = 0;
    return enabled;
}

#pragma push
void fn_80188B4C(void *anim) {
    void fn_80050C90(void *);
    void fn_8004FE98(void *, s32);
    void GfxEnt_ForEachKey(void *, void *, void *);
    void MuFade_UnlinkSame(void *, void *);
    void Unit_SetModelAlpha(void *, s32);
    s32 DebugPrint(const char *, ...);
    void SeCue_FadeOut(s32, s32);
    void fn_800C4588(void *);

    extern u16 E_MuFade_script[36];
    extern u8 gMapBlendMode;
    extern u8 gBattleMap[];
    extern u8 gSeCueSlots[];
    extern u8 MoveAnim_str[];

    u8 fadeKey[0x34];
    u8 *self;
    s8 x;
    s32 y;
    u8 *unit;
    s16 degrees;
    f32 angle;
    u16 flags;
    s32 alpha;
    u8 blend;
    u8 slot;

    self = (u8 *)anim;
    if (M2C_FIELD(self, u16 *, 0x52) & 0x80) {
        unit = M2C_FIELD(self, u8 **, 0x30);
        x = (s8)unit[0x19E];
        y = *(s8 *)(unit + 0x19F);
        fn_80050C90(unit);

        unit = M2C_FIELD(self, u8 **, 0x30);
        switch (self[0x5A]) {
        case 4:  degrees = 0;   break;
        case 6:  degrees = 45;  break;
        case 2:  degrees = 90;  break;
        case 10: degrees = 135; break;
        case 8:  degrees = 180; break;
        case 9:  degrees = 225; break;
        case 1:  degrees = 270; break;
        case 5:  degrees = 315; break;
        default: degrees = 0;   break;
        }

        angle = (f32)degrees;
        *(void **)(fadeKey + 0x30) = unit;
        GfxEnt_ForEachKey(E_MuFade_script, MuFade_UnlinkSame, fadeKey);

        if (angle != (f32)M2C_FIELD(unit, s16 *, 0x15C) / 50.0f) {
            M2C_FIELD(unit, s16 *, 0x15C) = (s16)(50.0f * angle);
        }

        unit = M2C_FIELD(self, u8 **, 0x30);
        if (unit[2] != 0) {
            fn_8004FE98(unit, 0);
        }

        flags = M2C_FIELD(self, u16 *, 0x52);
        alpha = 255;
        if (flags & 0x10) {
            alpha = 255;
        }
        if (flags & 0x20) {
            alpha = 0;
        }
        blend = MoveAnim_IsBlendMode(gMapBlendMode);
        if (blend) {
            unit = M2C_FIELD(self, u8 **, 0x30);
            if (M2C_FIELD(unit, u8 **, 0x190)[8] == 1 &&
                (gBattleMap + x + y * 0x40)[0x200D] == 0) {
                alpha = 0;
            }
        }

        Unit_SetModelAlpha(M2C_FIELD(self, void **, 0x30), alpha);
    }

    slot = self[0x6A];
    if ((s8)slot != -1) {
        DebugPrint((const char *)(MoveAnim_str + 0x4C3),
                   **(const char ***)(gSeCueSlots + slot * 0x30));
        SeCue_FadeOut(self[0x6A], 250);
    }

    fn_800C4588(M2C_FIELD(self, void **, 0x54));
    M2C_FIELD(self, void **, 0x54) = NULL;
    fn_800C4588(M2C_FIELD(self, void **, 0x6C));
    M2C_FIELD(self, void **, 0x6C) = NULL;
}

#pragma pop
void fn_80188DBC(void *arg0) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, s32);
    void MuFade_UnlinkSame(void *, void *);
    extern u16 E_MuFade_script[36];
    u8 sp8[0x34];
    void *unit;
    void *proc;
    u8 dir;
    s16 angle;
    f32 fangle;

    if ((*(u16 *)((u8 *)arg0 + 0x52) & 0xF) == 0) {
        return;
    }
    dir = ((u8 *)arg0)[0x5A];
    unit = *(void **)((u8 *)arg0 + 0x30);
    switch (dir) {
    case 4:
        angle = 0;
        break;
    case 6:
        angle = 0x2D;
        break;
    case 2:
        angle = 0x5A;
        break;
    case 10:
        angle = 0x87;
        break;
    case 8:
        angle = 0xB4;
        break;
    case 9:
        angle = 0xE1;
        break;
    case 1:
        angle = 0x10E;
        break;
    case 5:
        angle = 0x13B;
        break;
    default:
        angle = 0;
        break;
    }
    fangle = (f32)angle;
    *(void **)(sp8 + 0x30) = unit;
    GfxEnt_ForEachKey(&E_MuFade_script, MuFade_UnlinkSame, sp8);
    if (fangle == ((f32)*(s16 *)((u8 *)unit + 0x15C) / 50.0f)) {
        return;
    }
    proc = Process_CreateEx(&E_MuFade_script, 0);
    *(void **)((u8 *)proc + 0x30) = unit;
    *(f32 *)((u8 *)proc + 0x34) = fangle;
    *(s32 *)((u8 *)proc + 0x38) = 0x10;
}

void fn_80188EF4(void *arg0) {
    void fn_8000C188(void);
    f32 fn_80059F64(f32, f32, f32, f32);
    void fn_8005F7B0(void *, u8);
    extern f32 lbl_8036ACF8;
    extern f64 lbl_8036AD10;
    void *ptr;

    *(f32 *)((char *)arg0 + 0x3C) = lbl_8036ACF8 + *(f32 *)((char *)arg0 + 0x3C);
    if (*(f32 *)((char *)arg0 + 0x3C) >= *(f32 *)((char *)arg0 + 0x38)) {
        *(f32 *)((char *)arg0 + 0x3C) = *(f32 *)((char *)arg0 + 0x38);
        fn_8000C188();
    }
    ptr = (void *)(*(s32 *)((char *)arg0 + 0x30) + 0x1C);
    fn_8005F7B0(ptr, (u8)(s32)fn_80059F64((f32)*(u8 *)((char *)arg0 + 0x50),
        (f32)*(u8 *)((char *)arg0 + 0x51),
        *(f32 *)((char *)arg0 + 0x38),
        *(f32 *)((char *)arg0 + 0x3C)));
}

void fn_80188FAC(void *p) {
void Process_Goto(void *,s32);
extern u8 gMapBlendMode;
extern u8 gBattleMap[];
s32 x,y;
u8 flag,temp;
void *unit;
M2C_FIELD(p,f32 *,0x38)=16.0f; M2C_FIELD(p,f32 *,0x3c)=0.0f;
M2C_FIELD(p,u8 *,0x50)=255; M2C_FIELD(p,u8 *,0x51)=255;
unit=M2C_FIELD(p,void **,0x30);
x=M2C_FIELD(unit,f32 *,4); y=M2C_FIELD(unit,f32 *,8);
switch(M2C_FIELD(p,u16 *,0x52)&0x30){
case 0x10:M2C_FIELD(p,u8 *,0x50)=0;break;
case 0x20:M2C_FIELD(p,u8 *,0x51)=0;break;
}
flag=1; temp=gMapBlendMode-1; if(!(temp<=flag))flag=0;
if(flag && M2C_FIELD(M2C_FIELD(M2C_FIELD(p,void **,0x30),void **,0x190),u8 *,8)==1 && gBattleMap[(s8)x+((s8)y<<6)+0x200d]==0) Process_Goto(p,0);
}

void fn_801890B4(u8 *self) {
void fn_80050C90(void *);
void fn_8004FE98(void *,s32);
void GfxEnt_ForEachKey(void *,void *,void *);
void MuFade_UnlinkSame(void *,void *);
void Unit_SetModelAlpha(void *,s32);
void DebugPrint(void *,...);
void SeCue_FadeOut(s32,s32);
void fn_800C4588(void *);
extern u16 E_MuFade_script[36];
extern u8 gBattleMap[],gSeCueSlots[],MoveAnim_str[],gMapBlendMode;
u8 key[0x34];
s32 x,y;
u8 tx,ty;
u8 *unit;
f32 angle;
s16 degrees;
s32 alpha;
u8 blend;
if(*(u16 *)(self+0x52)&0x80) {
unit=*(u8 **)(self+0x30);
tx=unit[0x19e]; ty=unit[0x19f]; x=(s8)tx; y=(s8)ty;
fn_80050C90(unit);
unit=*(u8 **)(self+0x30);
switch(self[0x5a]) {
case 4: degrees=0;break;
case 6: degrees=45;break;
case 2: degrees=90;break;
case 10: degrees=135;break;
case 8: degrees=180;break;
case 9: degrees=225;break;
case 1: degrees=270;break;
case 5: degrees=315;break;
default: degrees=0;break;
}
angle=degrees;
*(void **)(key+0x30)=unit;
GfxEnt_ForEachKey(E_MuFade_script,MuFade_UnlinkSame,key);
if(angle!=(f32)*(s16 *)(unit+0x15c)/50.0f) *(s16 *)(unit+0x15c)=50.0f*angle;
unit=*(u8 **)(self+0x30);
if(unit[2]) fn_8004FE98(unit,0);
alpha=255;
if(*(u16 *)(self+0x52)&0x10) {}
if(*(u16 *)(self+0x52)&0x20) alpha=0;
blend=1;
if(!((u8)(gMapBlendMode-1)<=1)) blend=0;
if(blend) {
if((*(u8 **)(*(u8 **)(self+0x30)+0x190))[8]==1) {
if(gBattleMap[0x200d+x+(y<<6)]==0) alpha=0;
}
}
Unit_SetModelAlpha(*(void **)(self+0x30),alpha);
}
if((s8)self[0x6a]!=-1) {
DebugPrint(MoveAnim_str+0x4c3,**(void ***)(gSeCueSlots+self[0x6a]*0x30));
SeCue_FadeOut(self[0x6a],250);
}
fn_800C4588(*(void **)(self+0x54));*(void **)(self+0x54)=0;
fn_800C4588(*(void **)(self+0x6c));*(void **)(self+0x6c)=0;
}

#pragma global_optimizer off
/* Advance a unit move animation: lerp xyz, optional fast-forward, update camera. */
void MoveAnim_Update(void *anim, f32 scaleArg) {
    void Process_ClearFunc(void *);
    void Unit_SetModelAlpha(void *, s32);
    f32 Math_Lerp(f32, f32, f32, f32);
    void fn_8014CAD4(void *, f32, f32);
    extern u8 gBattleState[];
    extern u8 gSeCueSlots[];
    extern void *gPadInput;
    extern f32 lbl_8036AD18, lbl_8036ACF8, lbl_8036AD08, lbl_8036AD1C, gHalf;
    f32 duration;



    f32 step;
    f32 scale;
    f64 dy, dx;
    f32 minimum;
    f32 distance;
    u8 fast;
    u32 flags;
    u8 index;
    u8 *p;
    duration = M2C_FIELD(anim, f32 *, 0x38);
    flags = M2C_FIELD(gPadInput, u32 *, 4);
    if (M2C_FIELD(anim, u16 *, 0x52) & 0x80)
        fast = 0;
    else if ((((u32)gBattleState[0x9C] >> 5U) & 1U) == 1U)
        fast = 1;
    else if (gBattleState[0x57] >= 2 && (flags & 0x100))
        fast = 1;
    else
        fast = 0;
    if (fast) {
        step = duration * lbl_8036AD18;
        if (step < lbl_8036ACF8)
            step = lbl_8036ACF8;
        M2C_FIELD(M2C_FIELD(anim, void **, 0x34), f32 *, 0x5C) = lbl_8036AD08;
    } else {
        M2C_FIELD(M2C_FIELD(anim, void **, 0x34), f32 *, 0x5C) = step = lbl_8036ACF8;
    }
    if (M2C_FIELD(anim, u16 *, 0x52) & 0x8000) {
        scaleArg = lbl_8036AD1C * (f32)__fabs(M2C_FIELD(anim, f32 *, 0x48) - M2C_FIELD(anim, f32 *, 0x44));
        if (scaleArg < lbl_8036ACF8)
            scaleArg = lbl_8036ACF8;
        duration = (s32)(duration * scaleArg);
    }
    M2C_FIELD(anim, f32 *, 0x3C) += step;
    if (M2C_FIELD(anim, f32 *, 0x3C) >= duration) {
        M2C_FIELD(anim, f32 *, 0x3C) = duration;
        M2C_FIELD(anim, u8 *, 0x58)++;
        Process_ClearFunc(anim);
    }
    {
        f32 x = Math_Lerp(gHalf + (f32)(s8)M2C_FIELD(anim, u8 *, 0x40),
                          gHalf + (f32)(s8)M2C_FIELD(anim, u8 *, 0x42),
                          duration, M2C_FIELD(anim, f32 *, 0x3C));
        f32 y;
        f32 z;
        y = Math_Lerp(gHalf + (f32)(s8)M2C_FIELD(anim, u8 *, 0x41),
                      gHalf + (f32)(s8)M2C_FIELD(anim, u8 *, 0x43),
                      duration, M2C_FIELD(anim, f32 *, 0x3C));
        z = Math_Lerp(M2C_FIELD(anim, f32 *, 0x44), M2C_FIELD(anim, f32 *, 0x48), duration,
                      M2C_FIELD(anim, f32 *, 0x3C));
        p = M2C_FIELD(anim, u8 **, 0x30);
        dy = __fabs(y - M2C_FIELD(p, f32 *, 8));
        dx = __fabs(x - M2C_FIELD(p, f32 *, 4));
        M2C_FIELD(anim, f32 *, 0x4C) = M2C_FIELD(anim, f32 *, 0x4C) + ((f32)dx + (f32)dy);
        M2C_FIELD(M2C_FIELD(anim, void **, 0x30), f32 *, 4) = x;
        M2C_FIELD(M2C_FIELD(anim, void **, 0x30), f32 *, 8) = y;
        M2C_FIELD(M2C_FIELD(anim, void **, 0x30), f32 *, 12) = z;
        if (M2C_FIELD(anim, u16 *, 0x52) & 0x40) {
            *(f32 *)(gBattleState + 0x524) = x;
            *(f32 *)(gBattleState + 0x528) = y;
            fn_8014CAD4(gBattleState, x, y);
            *(f32 *)(gBattleState + 0x534) = x;
            *(f32 *)(gBattleState + 0x538) = y;
        }
        Unit_SetModelAlpha(M2C_FIELD(anim, void **, 0x30),
                    (s32)Math_Lerp((f32)M2C_FIELD(anim, u8 *, 0x50), (f32)M2C_FIELD(anim, u8 *, 0x51),
                                   duration, M2C_FIELD(anim, f32 *, 0x3C)));
        index = M2C_FIELD(anim, u8 *, 0x6A);
        if ((s8)index != -1) {
            p = gSeCueSlots + index * 0x30;
            M2C_FIELD(p, f32 *, 0x1C) = x;
            M2C_FIELD(p, f32 *, 0x20) = y;
            M2C_FIELD(p, f32 *, 0x24) = z;
            p[12] |= 2;
        }
    }
}

#pragma dont_inline on
#pragma global_optimizer off
void fn_80189698(void *self) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, void *);
    void Process_Goto(void *, s32);
    u8 fn_8004C0F0(void *);
    u8 fn_8004C00C(void *);
    void fn_8004FE90(void *, u8);
    void fn_8004FE98(void *, s32);
    void fn_800506E0(void *, s32);
    void *fn_800508C4(void *);
    f32 Math_Lerp(f32, f32, f32, f32);
    void fn_8005FC74(void *, void *, s32);
    void fn_8005FEE8(void *, f32);
    s32 fn_80060440(void *);
    void *fn_800639B4(void);
    f32 Map_SampleHeightRaw(void *, f32, f32);
    void fn_8012B3C0(s32, s32, s32);
    void MuFade_UnlinkSame(void *, void *);
    extern u8 E_MuBlend_script[];
    extern u8 gBattleState[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    extern u8 gMapBlendMode;
    extern void *gPadInput;
    extern f32 lbl_8036ACEC, lbl_8036ACF0, lbl_8036ACF4, lbl_8036ACF8, lbl_8036ACE8, gHalf;

    u8 key1a[0x38];
    u8 key1b[0x38];
    u8 key2a[0x38];
    u8 key2b[0x38];
    u8 keyAng[0x38];
    u8 *base;
    u32 dir;
    u32 bump;
    void *unit;
    s32 yShift;
    s32 ox, oy, x, y;
    s32 frames;

    M2C_FIELD(self, f32 *, 0x3C) = lbl_8036ACEC;
    base = E_MuBlend_script;
    dir = M2C_FIELD(self, u8 **, 0x54)[M2C_FIELD(self, u8 *, 0x58)];
    M2C_FIELD(self, u8 *, 0x40) = M2C_FIELD(self, u8 *, 0x42);
    M2C_FIELD(self, u8 *, 0x41) = M2C_FIELD(self, u8 *, 0x43);

    switch (dir) {
    case 16: {
        u8 fast;
        u32 padFlags;
        void *end;
        void *old;
        void *model;
        s32 frame;
        s32 lvl;
        f32 start;
        void *obj;
        void *proc;
        s32 count;
        M2C_FIELD(M2C_FIELD(self, void **, 0x30), f32 *, 0x78) = lbl_8036ACF8;
        padFlags = M2C_FIELD(gPadInput, u32 *, 4);
        if (M2C_FIELD(self, u16 *, 0x52) & 0x80)
            fast = 0;
        else if ((((u32)gBattleState[0x9C] >> 5U) & 1U) == 1U)
            fast = 1;
        else if (gBattleState[0x57] >= 2 && (padFlags & 0x100))
            fast = 1;
        else
            fast = 0;
        if (fast) {
            obj = M2C_FIELD(self, void **, 0x30);
            count = 0x10;
            if (fn_8004C0F0(obj)) {
                M2C_FIELD(key1a, void **, 0x30) = obj;
                GfxEnt_ForEachKey(base + 0, MuFade_UnlinkSame, key1a);
                M2C_FIELD(key1b, void **, 0x30) = obj;
                GfxEnt_ForEachKey(base + 0x20, MuFade_UnlinkSame, key1b);
                lvl = M2C_FIELD(fn_800508C4(obj), u8 *, 9);
                if (lvl > 0x14) {
                    if (lvl > 0x28)
                        count <<= 1;
                    else
                        count = (s32)((f32)count + Math_Lerp(lbl_8036ACEC, lbl_8036ACF4, lbl_8036ACF0, (f32)(lvl - 0x14)));
                }
                if (count == 0 || fn_80060440((u8 *)obj + 0x1C) >= 4) {
                    fn_8004FE98(obj, 0);
                } else {
                    proc = Process_CreateEx(base + 0, 0);
                    M2C_FIELD(proc, void **, 0x30) = obj;
                    M2C_FIELD(proc, void **, 0x34) = (u8 *)obj + 0x1C;
                    M2C_FIELD(proc, s32 *, 0x38) = 0;
                    M2C_FIELD(proc, s32 *, 0x3C) = count;
                    M2C_FIELD(proc, s32 *, 0x40) = 0;
                    fn_800506E0(M2C_FIELD(proc, void **, 0x30), 0);
                    end = fn_800639B4();
                    model = M2C_FIELD(proc, void **, 0x34);
                    frame = 0;
                    old = M2C_FIELD(model, void **, 0x44);
                    if (old) {
                        start = (f32)M2C_FIELD(old, s32 *, 0x14);
                        frame = (s32)Math_Lerp((f32)M2C_FIELD(end, s32 *, 0x14), (f32)M2C_FIELD(end, s32 *, 0x18),
                                               (f32)M2C_FIELD(old, s32 *, 0x18) - start,
                                               M2C_FIELD(model, f32 *, 0x58) - start);
                    }
                    fn_8005FC74(M2C_FIELD(proc, void **, 0x34), end, 1);
                    fn_8005FEE8(M2C_FIELD(proc, void **, 0x34), (f32)frame);
                    fn_8004FE90(M2C_FIELD(proc, void **, 0x30), (u8)M2C_FIELD(proc, s32 *, 0x38));
                }
            }
        } else {
            obj = M2C_FIELD(self, void **, 0x30);
            count = 0x10;
            if (fn_8004C0F0(obj)) {
                M2C_FIELD(key2a, void **, 0x30) = obj;
                GfxEnt_ForEachKey(base + 0, MuFade_UnlinkSame, key2a);
                M2C_FIELD(key2b, void **, 0x30) = obj;
                GfxEnt_ForEachKey(base + 0x20, MuFade_UnlinkSame, key2b);
                lvl = M2C_FIELD(fn_800508C4(obj), u8 *, 9);
                if (lvl > 0x14) {
                    if (lvl > 0x28)
                        count <<= 1;
                    else
                        count = (s32)((f32)count + Math_Lerp(lbl_8036ACEC, lbl_8036ACF4, lbl_8036ACF0, (f32)(lvl - 0x14)));
                }
                if (count == 0 || fn_80060440((u8 *)obj + 0x1C) >= 4) {
                    fn_8004FE98(obj, 0);
                } else {
                    proc = Process_CreateEx(base + 0, 0);
                    M2C_FIELD(proc, void **, 0x30) = obj;
                    M2C_FIELD(proc, void **, 0x34) = (u8 *)obj + 0x1C;
                    M2C_FIELD(proc, s32 *, 0x38) = 0;
                    M2C_FIELD(proc, s32 *, 0x3C) = count;
                    M2C_FIELD(proc, s32 *, 0x40) = 0;
                    fn_800506E0(M2C_FIELD(proc, void **, 0x30), 0);
                    end = fn_800639B4();
                    model = M2C_FIELD(proc, void **, 0x34);
                    frame = 0;
                    old = M2C_FIELD(model, void **, 0x44);
                    if (old) {
                        start = (f32)M2C_FIELD(old, s32 *, 0x14);
                        frame = (s32)Math_Lerp((f32)M2C_FIELD(end, s32 *, 0x14), (f32)M2C_FIELD(end, s32 *, 0x18),
                                               (f32)M2C_FIELD(old, s32 *, 0x18) - start,
                                               M2C_FIELD(model, f32 *, 0x58) - start);
                    }
                    fn_8005FC74(M2C_FIELD(proc, void **, 0x34), end, 1);
                    fn_8005FEE8(M2C_FIELD(proc, void **, 0x34), (f32)frame);
                    fn_8004FE90(M2C_FIELD(proc, void **, 0x30), (u8)M2C_FIELD(proc, s32 *, 0x38));
                }
            }
        }
        {
            void *u = M2C_FIELD(self, void **, 0x30);
            f32 z0 = lbl_8036ACEC;
            M2C_FIELD(u, f32 *, 0x10) = z0;
            M2C_FIELD(u, f32 *, 0x14) = z0;
            M2C_FIELD(u, f32 *, 0x18) = z0;
        }
        Process_Goto(self, 0);
        return;
    }
    case 1:
        M2C_FIELD(self, u8 *, 0x42) = M2C_FIELD(self, u8 *, 0x40) - 1;
        M2C_FIELD(self, u8 *, 0x43) = M2C_FIELD(self, u8 *, 0x41);
        break;
    case 2:
        M2C_FIELD(self, u8 *, 0x42) = M2C_FIELD(self, u8 *, 0x40) + 1;
        M2C_FIELD(self, u8 *, 0x43) = M2C_FIELD(self, u8 *, 0x41);
        break;
    case 4:
        M2C_FIELD(self, u8 *, 0x42) = M2C_FIELD(self, u8 *, 0x40);
        M2C_FIELD(self, u8 *, 0x43) = M2C_FIELD(self, u8 *, 0x41) + 1;
        break;
    case 8:
        M2C_FIELD(self, u8 *, 0x42) = M2C_FIELD(self, u8 *, 0x40);
        M2C_FIELD(self, u8 *, 0x43) = M2C_FIELD(self, u8 *, 0x41) - 1;
        break;
    case 0: case 3: case 5: case 6: case 7: case 9:
    case 10: case 11: case 12: case 13: case 14: case 15:
        break;
    }

    x = (s8)M2C_FIELD(self, u8 *, 0x42);
    y = (s8)M2C_FIELD(self, u8 *, 0x43);
    ox = (s8)M2C_FIELD(self, u8 *, 0x40);
    oy = (s8)M2C_FIELD(self, u8 *, 0x41);
    yShift = y << 6;
    {
        u8 mapId = (gBattleMap + x + yShift)[0xD];
        bump = M2C_FIELD(self, u8 **, 0x54)[M2C_FIELD(self, u8 *, 0x58) + 1];
        if (mapId != 0)
            unit = gUnits + (mapId - 1) * 0x280;
        else
            unit = 0;
    }

    if (!(M2C_FIELD(self, u16 *, 0x52) & 0x200) && unit != 0 && unit != M2C_FIELD(self, void **, 0x30) && fn_8004C00C(unit) == 0) {
        u8 fast;
        u32 padFlags = M2C_FIELD(gPadInput, u32 *, 4);
        void *proc;
        s32 bit80 = M2C_FIELD(self, u16 *, 0x52) & 0x80;
        if (bit80)
            fast = 0;
        else if ((((u32)gBattleState[0x9C] >> 5U) & 1U) == 1U)
            fast = 1;
        else if (gBattleState[0x57] >= 2 && (padFlags & 0x100))
            fast = 1;
        else
            fast = 0;
        if (bit80 != 0) {
            void *parent = M2C_FIELD(self, void **, 0x18);
            if (!(M2C_FIELD(unit, u32 *, 0x1A0) & 0x10000DC)) {
                proc = Process_CreateEx(base + 0x184, parent);
                M2C_FIELD(proc, void **, 0x30) = unit;
                M2C_FIELD(proc, s32 *, 0x38) = dir;
                M2C_FIELD(proc, s32 *, 0x3C) = bump;
                M2C_FIELD(proc, u8 *, 0x64) = fast;
            }
        } else if (!(M2C_FIELD(unit, u32 *, 0x1A0) & 0x10000DC)) {
            proc = Process_CreateEx(base + 0x184, 0);
            M2C_FIELD(proc, void **, 0x30) = unit;
            M2C_FIELD(proc, s32 *, 0x38) = dir;
            M2C_FIELD(proc, s32 *, 0x3C) = bump;
            M2C_FIELD(proc, u8 *, 0x64) = fast;
        }
    }

    if (M2C_FIELD(self, u16 *, 0x52) & 0x8000) {
        {
            u8 *p = (u8 *)M2C_FIELD(self, void **, 0x6C) + M2C_FIELD(self, u8 *, 0x58) * 0xC;
            M2C_FIELD(self, f32 *, 0x44) = *(f32 *)(p + 4);
        }
        {
            u8 *p = (u8 *)M2C_FIELD(self, void **, 0x6C) + M2C_FIELD(self, u8 *, 0x58) * 0xC;
            M2C_FIELD(self, f32 *, 0x48) = *(f32 *)(p + 0x10);
        }
    } else {
        f32 h0;
        f32 mapX;
        void *obj;
        obj = M2C_FIELD(self, void **, 0x30);
        h0 = M2C_FIELD(obj, f32 *, 0xC);
        mapX = gHalf + (f32)x;
        M2C_FIELD(self, f32 *, 0x44) = h0;
        M2C_FIELD(self, f32 *, 0x48) = Map_SampleHeightRaw(gBattleMap, mapX, gHalf + (f32)y);
    }

    fn_8012B3C0(x, y, 0);
    M2C_FIELD(self, u8 *, 0x50) = 0xFF;
    M2C_FIELD(self, u8 *, 0x51) = 0xFF;
    switch (M2C_FIELD(self, u16 *, 0x52) & 0x30) {
    case 0x10:
        if (M2C_FIELD(self, u8 *, 0x58) == 0)
            M2C_FIELD(self, u8 *, 0x50) = 0;
        break;
    case 0x20:
        if ((s32)M2C_FIELD(self, u8 *, 0x58) == (s32)M2C_FIELD(self, u8 *, 0x59) - 1)
            M2C_FIELD(self, u8 *, 0x51) = 0;
        break;
    }

    {
        u8 flag = 1;
        u32 mode = (u8)(gMapBlendMode - 1);
        u32 test = ((u32)flag | ~mode) - (((u32)flag - mode) >> 1);
        if ((test >> 31) == 0)
            flag = 0;
        if (flag) {
            void *obj;
            obj = M2C_FIELD(self, void **, 0x30);
            if (M2C_FIELD(obj, u8 **, 0x190)[8] == 1) {
                u8 *mapTile = gBattleMap + 0x200D;
                if (mapTile[ox + (oy << 6)] == 0)
                    M2C_FIELD(self, u8 *, 0x50) = 0;
                if (mapTile[x + yShift] == 0)
                    M2C_FIELD(self, u8 *, 0x51) = 0;
            }
        }
    }

    {
        u8 fast;
        u32 padFlags;
        frames = (s32)M2C_FIELD(self, f32 *, 0x38);
        padFlags = M2C_FIELD(gPadInput, u32 *, 4);
        if (M2C_FIELD(self, u16 *, 0x52) & 0x80)
            fast = 0;
        else if ((((u32)gBattleState[0x9C] >> 5U) & 1U) == 1U)
            fast = 1;
        else if (gBattleState[0x57] >= 2 && (padFlags & 0x100))
            fast = 1;
        else
            fast = 0;
        if (fast)
            frames = frames / 2;
    }

    {
        s16 angle;
        f32 degrees;
        f32 scale;
        void *obj;
        void *proc;
        obj = M2C_FIELD(self, void **, 0x30);
        switch (dir & 0xFF) {
        case 4: angle = 0; break;
        case 6: angle = 0x2D; break;
        case 2: angle = 0x5A; break;
        case 10: angle = 0x87; break;
        case 8: angle = 0xB4; break;
        case 9: angle = 0xE1; break;
        case 1: angle = 0x10E; break;
        case 5: angle = 0x13B; break;
        default: angle = 0; break;
        }
        degrees = (f32)angle;
        M2C_FIELD(keyAng, void **, 0x30) = obj;
        GfxEnt_ForEachKey(base + 0x78, MuFade_UnlinkSame, keyAng);
        scale = lbl_8036ACE8;
        if (degrees != (f32)M2C_FIELD(obj, s16 *, 0x15C) / scale) {
            if (frames <= 0) {
                M2C_FIELD(obj, s16 *, 0x15C) = (s16)(s32)(scale * degrees);
            } else {
                proc = Process_CreateEx(base + 0x78, 0);
                M2C_FIELD(proc, void **, 0x30) = obj;
                M2C_FIELD(proc, f32 *, 0x34) = degrees;
                M2C_FIELD(proc, s32 *, 0x38) = frames;
            }
        }
    }
}
#pragma global_optimizer reset
#pragma dont_inline reset
void fn_8018A0A8(void *arg0) {
 void *Process_CreateEx(void *,s32);
 void GfxEnt_ForEachKey(void *,void *,void *);
 u8 fn_8004C0F0(void *);
 void *fn_800508C4(void *);
 void fn_8004FE98(void *,s32);
 void fn_800506E0(void *,s32);
 void *fn_800639B4(void);
 s32 fn_80060440(void *);
 void fn_8005FC74(void *,void *,s32);
 void fn_8005FEE8(void *,f32);
 void fn_8004FE90(void *,u8);
 f32 Math_Lerp(f32,f32,f32,f32);
 extern u8 E_MuBlend_script[];
 extern f32 lbl_8036ACEC,lbl_8036AD20,lbl_8036AD0C,lbl_8036ACF0,lbl_8036AD24,lbl_8036ACE8;
 register u8 *base=E_MuBlend_script;
 void *info;

 M2C_FIELD(arg0,u8 *,0x58)=0;
 M2C_FIELD(arg0,f32 *,0x4c)=lbl_8036ACEC;
 if(*M2C_FIELD(arg0,u8 **,0x54)==16) {
 if(M2C_FIELD(arg0,u16 *,0x52)&0x30) Process_Goto(arg0,2); else Process_Goto(arg0,0);
 return;
 }
 info=fn_800508C4(M2C_FIELD(arg0,void **,0x30));
 M2C_FIELD(arg0,void **,0x34)=(u8*)M2C_FIELD(arg0,void **,0x30)+0x1c;
 M2C_FIELD(arg0,f32 *,0x38)=(s32)((M2C_FIELD(info,u8 *,9)*10)/16.666666f);
 if(M2C_FIELD(arg0,f32 *,0x38)<8.0f) M2C_FIELD(arg0,f32 *,0x38)=8.0f;
 if(M2C_FIELD(arg0,u16 *,0x52)&0x100) {
 u8 key1a[0x38], key1b[0x38];
 void *obj = M2C_FIELD(arg0,void **,0x30);
 s32 count=8;
 void *proc; s32 frame; void *end; void *old; void *model; s32 lvl; f32 start;
 if(fn_8004C0F0(obj)) {
 M2C_FIELD(key1a,void **,0x30)=obj;
 GfxEnt_ForEachKey(base,MuFade_UnlinkSame,key1a);
 M2C_FIELD(key1b,void **,0x30)=obj;
 GfxEnt_ForEachKey(base+0x20,MuFade_UnlinkSame,key1b);
 lvl=M2C_FIELD(fn_800508C4(obj),u8 *,9);
 if(lvl>20) { if(lvl>40) count<<=1; else count=(s32)(count+Math_Lerp(lbl_8036ACEC,lbl_8036AD0C,lbl_8036ACF0,(f32)(lvl-20))); }
 if(count==0 || fn_80060440((u8*)obj+0x1c)>=4) fn_8004FE98(obj,15);
 else {
 proc=Process_CreateEx(base,0);
 M2C_FIELD(proc,void **,0x30)=obj;
 M2C_FIELD(proc,void **,0x34)=(u8*)obj+0x1c;
 M2C_FIELD(proc,s32 *,0x38)=15;
 M2C_FIELD(proc,s32 *,0x3c)=count;
 M2C_FIELD(proc,s32 *,0x40)=0;
 fn_800506E0(M2C_FIELD(proc,void **,0x30),15);
 end=fn_800639B4();
 model=M2C_FIELD(proc,void **,0x34); frame=0;
 old=M2C_FIELD(model,void **,0x44);
 if(old) { start=(f32)M2C_FIELD(old,s32 *,0x14); frame=(s32)Math_Lerp((f32)M2C_FIELD(end,s32 *,0x14),(f32)M2C_FIELD(end,s32 *,0x18),(f32)M2C_FIELD(old,s32 *,0x18)-start,M2C_FIELD(model,f32 *,0x58)-start); }
 fn_8005FC74(M2C_FIELD(proc,void **,0x34),end,1);
 fn_8005FEE8(M2C_FIELD(proc,void **,0x34),(f32)frame);
 fn_8004FE90(M2C_FIELD(proc,void **,0x30),(u8)M2C_FIELD(proc,s32 *,0x38));
 }
 }
 M2C_FIELD(arg0,f32 *,0x38)*=lbl_8036AD24;
} else {
 u8 key2a[0x38], key2b[0x38];
 void *obj = M2C_FIELD(arg0,void **,0x30);
 s32 count=8;
 void *proc; s32 frame; void *end; void *old; void *model; s32 lvl; f32 start;
 if(fn_8004C0F0(obj)) {
 M2C_FIELD(key2a,void **,0x30)=obj;
 GfxEnt_ForEachKey(base,MuFade_UnlinkSame,key2a);
 M2C_FIELD(key2b,void **,0x30)=obj;
 GfxEnt_ForEachKey(base+0x20,MuFade_UnlinkSame,key2b);
 lvl=M2C_FIELD(fn_800508C4(obj),u8 *,9);
 if(lvl>20) { if(lvl>40) count<<=1; else count=(s32)(count+Math_Lerp(lbl_8036ACEC,lbl_8036AD0C,lbl_8036ACF0,(f32)(lvl-20))); }
 if(count==0 || fn_80060440((u8*)obj+0x1c)>=4) fn_8004FE98(obj,1);
 else {
 proc=Process_CreateEx(base,0);
 M2C_FIELD(proc,void **,0x30)=obj;
 M2C_FIELD(proc,void **,0x34)=(u8*)obj+0x1c;
 M2C_FIELD(proc,s32 *,0x38)=1;
 M2C_FIELD(proc,s32 *,0x3c)=count;
 M2C_FIELD(proc,s32 *,0x40)=0;
 fn_800506E0(M2C_FIELD(proc,void **,0x30),1);
 end=fn_800639B4();
 model=M2C_FIELD(proc,void **,0x34); frame=0;
 old=M2C_FIELD(model,void **,0x44);
 if(old) { start=(f32)M2C_FIELD(old,s32 *,0x14); frame=(s32)Math_Lerp((f32)M2C_FIELD(end,s32 *,0x14),(f32)M2C_FIELD(end,s32 *,0x18),(f32)M2C_FIELD(old,s32 *,0x18)-start,M2C_FIELD(model,f32 *,0x58)-start); }
 fn_8005FC74(M2C_FIELD(proc,void **,0x34),end,1);
 fn_8005FEE8(M2C_FIELD(proc,void **,0x34),(f32)frame);
 fn_8004FE90(M2C_FIELD(proc,void **,0x30),(u8)M2C_FIELD(proc,s32 *,0x38));
 }
 }
 
}
 if(M2C_FIELD(arg0,u16 *,0x52)&0x30) {
 u8 key[0x38]; s16 angle; f32 degrees; void *obj=M2C_FIELD(arg0,void **,0x30);
 switch(*M2C_FIELD(arg0,u8 **,0x54)) {
 case 4:angle=0;break; case 6:angle=45;break; case 2:angle=90;break; case 10:angle=135;break;
 case 8:angle=180;break;case 9:angle=225;break;case 1:angle=270;break;case 5:angle=315;break;
 default:angle=0;break;
 }
 degrees=(f32)angle;
 M2C_FIELD(key,void **,0x30)=obj;
 GfxEnt_ForEachKey(base+0x78,MuFade_UnlinkSame,key);
 if(degrees!=M2C_FIELD(obj,s16 *,0x15c)/lbl_8036ACE8) M2C_FIELD(obj,s16 *,0x15c)=(s32)(lbl_8036ACE8*degrees);
 }
 M2C_FIELD(M2C_FIELD(arg0,void **,0x30),u32 *,0x1a0)&=~0x40;
 MoveAnim_AttachClassCue(arg0);
}
#pragma peephole reset
void MoveAnim_StartFlagFoot(void *anim) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_Create(void *, u32);
    void Unit_FocusCamera(void *, s32);
    void fn_8004FC70(void *, s32);
    void MuFade_UnlinkSame(void *, void *);
    extern u8 E_MuFlag_script[];
    extern u8 E_MuFoot_script[];
    u8 flagKey[0x34];
    u8 footKey[0x38];
    void *self;
    void *unit;
    void *prio;
    void *unit2;
    void *prio2;

    /* Optional camera/SFX prep, then restart E_MuFlag and E_MuFoot for this map unit. */
    self = anim;
    if (*(u16 *)((u8 *)self + 0x52) & 0x40) {
        Unit_FocusCamera(*(void **)((u8 *)self + 0x30), 0);
    }
    if (*(u16 *)((u8 *)self + 0x52) & 0x100) {
        fn_8004FC70(*(void **)((u8 *)self + 0x30), 0xF);
    }
    unit = *(void **)((u8 *)self + 0x30);
    prio = self;
    *(void **)(flagKey + 0x30) = unit;
    GfxEnt_ForEachKey(E_MuFlag_script, MuFade_UnlinkSame, flagKey);
    if (!self) {
        prio = (void *)3;
    }
    *(void **)((u8 *)Process_Create(E_MuFlag_script, (u32)prio) + 0x30) = unit;

    unit2 = *(void **)((u8 *)self + 0x30);
    prio2 = self;
    *(void **)(footKey + 0x30) = unit2;
    GfxEnt_ForEachKey(E_MuFoot_script, MuFade_UnlinkSame, footKey);
    if (!self) {
        prio2 = (void *)3;
    }
    *(void **)((u8 *)Process_Create(E_MuFoot_script, (u32)prio2) + 0x30) = unit2;
}

#pragma global_optimizer reset
void MuFade_ZeroScale(void *arg0) {
    extern f32 lbl_8036ACEC;
    u8 *ptr;
    f32 value;

    ptr = *(u8 **)((u8 *)arg0 + 0x30);
    value = lbl_8036ACEC;

    *(f32 *)(ptr + 0x10) = value;
    *(f32 *)(ptr + 0x14) = value;
    *(f32 *)(ptr + 0x18) = value;
}

#pragma scheduling off
#pragma global_optimizer off
void MuFade_InitScaleOut(void *arg0)
{
    extern f32 lbl_8036ACEC;
    s32 zero;
    f32 z;
    f32 t;

    zero = 0;
    z = lbl_8036ACEC;
    *(s32 *)((u8 *)arg0 + 0x34) = zero;
    t = *(f32 *)((u8 *)arg0 + 0x4C);
    *(f32 *)((u8 *)arg0 + 0x54) = t;
    t = *(f32 *)((u8 *)arg0 + 0x50);
    *(f32 *)((u8 *)arg0 + 0x58) = t;
    *(f32 *)((u8 *)arg0 + 0x4C) = z;
    *(f32 *)((u8 *)arg0 + 0x50) = z;
}
#pragma scheduling reset
#pragma global_optimizer reset
void MuFade_UpdateScale(void *proc) {
    /* Ease the map-unit scale XY toward proc targets over 10 frames, then clear the process. */
    void Process_ClearFunc(void *);
    f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
    extern f32 fMuFadeScaleFrames;
    extern f32 lbl_8036ACEC;
    f32 scaleX;
    f32 scaleY;
    f32 z;
    void *mu;

    if (*(u8 *)((u8 *)proc + 0x64)) {
        *(s32 *)((u8 *)proc + 0x34) = *(s32 *)((u8 *)proc + 0x34) + 1;
    }
*(s32 *)((u8 *)proc + 0x34) = *(s32 *)((u8 *)proc + 0x34) + 1;
    if (*(s32 *)((u8 *)proc + 0x34) >= 0xA) {
        *(s32 *)((u8 *)proc + 0x34) = 0xA;
        Process_ClearFunc(proc);
    }
    scaleX = Math_EaseOutPow(2, *(f32 *)((u8 *)proc + 0x54), *(f32 *)((u8 *)proc + 0x4C), fMuFadeScaleFrames, (f32)*(s32 *)((u8 *)proc + 0x34));
    scaleY = Math_EaseOutPow(2, *(f32 *)((u8 *)proc + 0x58), *(f32 *)((u8 *)proc + 0x50), fMuFadeScaleFrames, (f32)*(s32 *)((u8 *)proc + 0x34));
    mu = *(void **)((u8 *)proc + 0x30);
    z = lbl_8036ACEC;
    *(f32 *)((u8 *)mu + 0x10) = scaleX;
    *(f32 *)((u8 *)mu + 0x14) = scaleY;
    *(f32 *)((u8 *)mu + 0x18) = z;
}

#pragma cplusplus off
void fn_8018A91C(void *arg0, f32 angle) {
    void fn_80203320(void *,void *,f32);
    void fn_80203604(void *,void *,void *,f32);
    void fn_80202640(void *,void *);
    void fn_802029C4(void *,void *,void *);
    f32 fn_80023430(void *,f32,f32);
    extern u8 lbl_80278D70[];
    extern u8 lbl_802CA518[];
    extern u8 lbl_802B14E4[];
    f32 matrix[12];
    extern const f32 lbl_8036ACD8,lbl_8036ACEC,lbl_8036AD2C,lbl_8036AD30,lbl_8036AD34,lbl_8036AD38;
    u32 angles[4];
    f32 q1[4],q2[4],qout[4];
    u8 *data = lbl_80278D70;
    u32 axis[3],vec[3];
    u8 *self = arg0;
    f32 angle2;
    s32 from,to;
    f32 minusX,minusY,dx,x,dy,y,plusX,plusY,h1,h2,d1,d2,height;
    u8 id;
    void *unit;
    *(f32 *)(self+0x40)=*(f32 *)(*(u8 **)(self+0x30)+4);
    *(f32 *)(self+0x44)=*(f32 *)(*(u8 **)(self+0x30)+8);
    *(f32 *)(self+0x48)=*(f32 *)(*(u8 **)(self+0x30)+12);
    *(u32 *)(self+0x34)=0;
    from=*(s32 *)(self+0x38);
    angles[0]=*(u32 *)(data+0x8C);angles[1]=*(u32 *)(data+0x90);angles[2]=*(u32 *)(data+0x94);angles[3]=*(u32 *)(data+0x98);
    switch(from) {case 1:angle=*(f32 *)&angles[0];break;case 2:angle=*(f32 *)&angles[1];break;case 8:angle=*(f32 *)&angles[2];break;case 4:angle=*(f32 *)&angles[3];break;}
    to=*(s32 *)(self+0x3C);
    switch(to) {case 1:angle2=*(f32 *)&angles[0];break;case 2:angle2=*(f32 *)&angles[1];break;case 8:angle2=*(f32 *)&angles[2];break;case 4:angle2=*(f32 *)&angles[3];break;}
    if(from==to) angle2+=lbl_8036AD2C;
    axis[0]=*(u32 *)(data+0x9C);axis[1]=*(u32 *)(data+0xA0);axis[2]=*(u32 *)(data+0xA4);
    fn_80203320(q2,axis,lbl_8036AD30*angle2);
    fn_80203320(q1,axis,lbl_8036AD30*angle);
    fn_80203604(q1,q2,qout,lbl_8036ACD8);
    fn_80202640(matrix,qout);
    vec[0]=*(u32 *)(data+0xA8);vec[1]=*(u32 *)(data+0xAC);vec[2]=*(u32 *)(data+0xB0);
    fn_802029C4(matrix,vec,vec);
    *(f32 *)(self+0x5C)=lbl_8036AD34* *(f32 *)&vec[0];
    *(f32 *)(self+0x60)=lbl_8036AD34* *(f32 *)&vec[1];
    x=*(f32 *)(self+0x40);dx=*(f32 *)(self+0x5C);minusX=x-dx;
    if(minusX>=lbl_8036ACEC) {
        y=*(f32 *)(self+0x44);dy=*(f32 *)(self+0x60);minusY=y-dy;
        if(minusY>=lbl_8036ACEC && minusX<(f32)*(s32 *)lbl_802CA518 && minusY<(f32)*(s32 *)(lbl_802CA518+4)) {
            plusX=x+dx;
            if(plusX<lbl_8036ACEC || (plusY=y+dy)<lbl_8036ACEC || plusX>=(f32)*(s32 *)lbl_802CA518 || plusY>=(f32)*(s32 *)(lbl_802CA518+4)) {
                *(f32 *)(self+0x5C)*=lbl_8036AD34;
                *(f32 *)(self+0x60)*=lbl_8036AD34;
            } else {
                id=*(u8 *)(lbl_802CA518+(s8)plusX+((s8)plusY<<6)+0xD);
                if(id) unit=lbl_802B14E4+(id-1)*0x280;
                else unit=0;
                if(unit) {
                    *(f32 *)(self+0x5C)*=lbl_8036AD34;
                    *(f32 *)(self+0x60)*=lbl_8036AD34;
                }
                h1=fn_80023430(lbl_802CA518,*(f32 *)(self+0x40)+*(f32 *)(self+0x5C),*(f32 *)(self+0x44)+*(f32 *)(self+0x60));
                h2=fn_80023430(lbl_802CA518,*(f32 *)(self+0x40)-*(f32 *)(self+0x5C),*(f32 *)(self+0x44)-*(f32 *)(self+0x60));
                height=*(f32 *)(self+0x48);
                h1=height-h1;
                h2=height-h2;
                h1 *= h1;
                h2 *= h2;
                if(h1>h2) {
                    *(f32 *)(self+0x5C)*=lbl_8036AD34;
                    *(f32 *)(self+0x60)*=lbl_8036AD34;
                }
            }
        }
    }
    *(f32 *)(self+0x54)=lbl_8036ACEC;*(f32 *)(self+0x58)=lbl_8036ACEC;
    *(f32 *)(self+0x4C)=lbl_8036AD38* *(f32 *)(self+0x5C);
    *(f32 *)(self+0x50)=lbl_8036AD38* *(f32 *)(self+0x60);
}
/* Poll pad button IDs 0x14-0x1B to start/stop GActor node-link anims using MoveAnim_str names. */
void MoveAnim_PollPadNodeLinks(void *self) {
    u32 GActor_CreateNodeLink(s32, void *, void *, void *);
    void GActor_StopNodeLink(s32);
    void GActor_SetNodeLinkParam(void *, void *);
    u8 Pad_IsButton(void *, s32);
    extern u8 MoveAnim_str[];
    s32 param0x14;
    s32 param0x15;
    s32 param0x16;
    s32 param0x17;
    s32 param0x18;
    s32 param0x1A;
    s32 param0x1B;
    s32 pad;
    pad = M2C_FIELD(self, s32 *, 0x30) + 0x1C;
    if (Pad_IsButton((void *)pad, 0x14) != 0) {
        if (M2C_FIELD(self, u32 *, 0x38) != 0) {
            GActor_StopNodeLink(M2C_FIELD(self, s32 *, 0x38));
        }
        M2C_FIELD(self, u32 *, 0x38) = GActor_CreateNodeLink(M2C_FIELD(self, s32 *, 0x30) + 0x1C, MoveAnim_str + 0x4D3, MoveAnim_str + 0x4D7, self);
        param0x14 = M2C_FIELD(self, s32 *, 0x34);
        GActor_SetNodeLinkParam((void *)M2C_FIELD(self, u32 *, 0x38), &param0x14);
    }
    if (Pad_IsButton((void *)pad, 0x15) != 0) {
        if (M2C_FIELD(self, u32 *, 0x38) != 0) {
            GActor_StopNodeLink(M2C_FIELD(self, s32 *, 0x38));
        }
        M2C_FIELD(self, u32 *, 0x38) = GActor_CreateNodeLink(M2C_FIELD(self, s32 *, 0x30) + 0x1C, MoveAnim_str + 0x4DB, MoveAnim_str + 0x4DF, self);
        param0x15 = M2C_FIELD(self, s32 *, 0x34);
        GActor_SetNodeLinkParam((void *)M2C_FIELD(self, u32 *, 0x38), &param0x15);
    }
    if (Pad_IsButton((void *)pad, 0x16) != 0) {
        if (M2C_FIELD(self, u32 *, 0x38) != 0) {
            GActor_StopNodeLink(M2C_FIELD(self, s32 *, 0x38));
        }
        M2C_FIELD(self, u32 *, 0x38) = GActor_CreateNodeLink(M2C_FIELD(self, s32 *, 0x30) + 0x1C, MoveAnim_str + 0x4E3, MoveAnim_str + 0x4E7, self);
        param0x16 = M2C_FIELD(self, s32 *, 0x34);
        GActor_SetNodeLinkParam((void *)M2C_FIELD(self, u32 *, 0x38), &param0x16);
    }
    if (Pad_IsButton((void *)pad, 0x17) != 0) {
        if (M2C_FIELD(self, u32 *, 0x38) != 0) {
            GActor_StopNodeLink(M2C_FIELD(self, s32 *, 0x38));
        }
        M2C_FIELD(self, u32 *, 0x38) = GActor_CreateNodeLink(M2C_FIELD(self, s32 *, 0x30) + 0x1C, MoveAnim_str + 0x4EB, MoveAnim_str + 0x4EF, self);
        param0x17 = M2C_FIELD(self, s32 *, 0x34);
        GActor_SetNodeLinkParam((void *)M2C_FIELD(self, u32 *, 0x38), &param0x17);
    }
    if (Pad_IsButton((void *)pad, 0x18) != 0) {
        if (M2C_FIELD(self, u32 *, 0x38) != 0) {
            GActor_StopNodeLink(M2C_FIELD(self, s32 *, 0x38));
        }
        M2C_FIELD(self, u32 *, 0x38) = GActor_CreateNodeLink(M2C_FIELD(self, s32 *, 0x30) + 0x1C, MoveAnim_str + 0x4F3, MoveAnim_str + 0x4F7, self);
        param0x18 = M2C_FIELD(self, s32 *, 0x34);
        GActor_SetNodeLinkParam((void *)M2C_FIELD(self, u32 *, 0x38), &param0x18);
    }
    if (Pad_IsButton((void *)pad, 0x1A) != 0) {
        if (M2C_FIELD(self, u32 *, 0x38) != 0) {
            GActor_StopNodeLink(M2C_FIELD(self, s32 *, 0x38));
        }
        M2C_FIELD(self, u32 *, 0x38) = GActor_CreateNodeLink(M2C_FIELD(self, s32 *, 0x30) + 0x1C, MoveAnim_str + 0x4FB, MoveAnim_str + 0x4FF, self);
        param0x1A = M2C_FIELD(self, s32 *, 0x34);
        GActor_SetNodeLinkParam((void *)M2C_FIELD(self, u32 *, 0x38), &param0x1A);
    }
    if (Pad_IsButton((void *)pad, 0x1B) != 0) {
        if (M2C_FIELD(self, u32 *, 0x38) != 0) {
            GActor_StopNodeLink(M2C_FIELD(self, s32 *, 0x38));
        }
        M2C_FIELD(self, u32 *, 0x38) = GActor_CreateNodeLink(M2C_FIELD(self, s32 *, 0x30) + 0x1C, MoveAnim_str + 0x503, MoveAnim_str + 0x507, self);
        param0x1B = M2C_FIELD(self, s32 *, 0x34);
        GActor_SetNodeLinkParam((void *)M2C_FIELD(self, u32 *, 0x38), &param0x1B);
    }
    if (Pad_IsButton((void *)pad, 0x19) != 0) {
        if (M2C_FIELD(self, u32 *, 0x38) != 0) {
            GActor_StopNodeLink(M2C_FIELD(self, s32 *, 0x38));
            M2C_FIELD(self, u32 *, 0x38) = 0;
        }
    }
}

void fn_8018B004(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
}

void fn_8018B010(void *arg0) {
    void Unit_SetModelAlpha(void *, s32);
    void *p;
    f32 x, y, z;

    Unit_SetModelAlpha(*(void **)((u8 *)arg0 + 0x30), 0xFF);
    z = *(f32 *)((u8 *)arg0 + 0x48);
    y = *(f32 *)((u8 *)arg0 + 0x44);
    p = *(void **)((u8 *)arg0 + 0x30);
    x = *(f32 *)((u8 *)arg0 + 0x40);
    *(f32 *)((u8 *)p + 4) = x;
    *(f32 *)((u8 *)p + 8) = y;
    *(f32 *)((u8 *)p + 0xC) = z;
}

void fn_8018B060(u8 *arg0) {
    void Process_ClearFunc(void);
    void Unit_SetModelAlpha(void *, s32);
    f32 Math_Lerp(f32, f32, f32, f32);
    f32 Math_EaseInPow(s32, f32, f32, f32, f32);
    f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
    extern f64 lbl_8036ACE0;
    extern f32 gHalf;
    extern f32 lbl_8036ACEC;
    extern f32 lbl_8036AD00;
    extern f32 lbl_8036AD3C;

    s32 temp;
    void *self;
    s32 t;
    f32 f31;
    f32 f29;
    f32 f30;
    f32 half;
    void *obj;

    self = arg0;
    temp = *(s32 *)(arg0 + 0x50);
    *(s32 *)(arg0 + 0x50) = temp + 1;
    temp = *(s32 *)(arg0 + 0x50);
    if ((s32)temp >= *(s32 *)(arg0 + 0x54)) {
        *(s32 *)((u8 *)self + 0x50) = *(s32 *)(arg0 + 0x54);
        Process_ClearFunc();
    }
    t = (s32)Math_EaseInPow(2, lbl_8036ACEC, lbl_8036AD00,
                         (f32)*(s32 *)((u8 *)self + 0x54),
                         (f32)*(s32 *)((u8 *)self + 0x50));
    f31 = Math_Lerp(*(f32 *)((u8 *)self + 0x34), *(f32 *)((u8 *)self + 0x40),
                      (f32)*(s32 *)((u8 *)self + 0x54), (f32)*(s32 *)((u8 *)self + 0x50));
    f29 = Math_Lerp(*(f32 *)((u8 *)self + 0x38), *(f32 *)((u8 *)self + 0x44),
                      (f32)*(s32 *)((u8 *)self + 0x54), (f32)*(s32 *)((u8 *)self + 0x50));
    f30 = Math_Lerp(*(f32 *)((u8 *)self + 0x3C), *(f32 *)((u8 *)self + 0x48),
                      (f32)*(s32 *)((u8 *)self + 0x54), (f32)*(s32 *)((u8 *)self + 0x50));
    half = gHalf * (f32)*(s32 *)((u8 *)self + 0x54);
    temp = *(s32 *)((u8 *)self + 0x50);
    if ((f32)(s32)temp < half) {
        f30 += Math_EaseOutPow(2, lbl_8036ACEC, lbl_8036AD3C, half, (f32)(s32)temp);
    } else {
        f30 += Math_EaseInPow(2, lbl_8036AD3C, lbl_8036ACEC, half, (f32)(s32)temp - half);
    }
    Unit_SetModelAlpha(*(void **)((u8 *)self + 0x30), t);
    obj = *(void **)((u8 *)self + 0x30);
    *(f32 *)((u8 *)obj + 4) = f31;
    *(f32 *)((u8 *)obj + 8) = f29;
    *(f32 *)((u8 *)obj + 0xC) = f30;
}

void fn_8018B2C4(void *arg0) {
    M2C_UNK Unit_SetModelAlpha(s32, M2C_UNK);
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0x10;
    Unit_SetModelAlpha(M2C_FIELD(arg0, s32 *, 0x30), 0);
}

void fn_8018B2FC(void *arg0) {
    f32 *dst;
    f32 value0;
    f32 value1;
    f32 value2;

    value2 = *(f32 *)((u8 *)arg0 + 0x3C);
    value1 = *(f32 *)((u8 *)arg0 + 0x38);
    dst = *(f32 **)((u8 *)arg0 + 0x30);
    value0 = *(f32 *)((u8 *)arg0 + 0x34);

    dst[1] = value0;
    dst[2] = value1;
    dst[3] = value2;
}

#pragma fp_contract off
#pragma global_optimizer off
void fn_8018B31C(void *arg0) {
 extern f32 lbl_8036ACEC, lbl_8036ACF8, lbl_8036AD40;
 void Process_ClearFunc(void *);
 f32 f0; f32 f1; f32 f2; f32 f3; f32 f4; void *r4;
 f1=*(f32 *)((u8 *)arg0+0x48); f0=lbl_8036ACF8;
 *(f32 *)((u8 *)arg0+0x48)=f1+f0;
 f3=*(f32 *)((u8 *)arg0+0x48);
 f0=*(f32 *)((u8 *)arg0+0x44);
 r4=*(void **)((u8 *)arg0+0x30);
 f1=f0*f3;
 f4=*(f32 *)((u8 *)arg0+0x40);
 f2=*(f32 *)((u8 *)r4+0xc);
 f0=*(f32 *)((u8 *)arg0+0x3c);
 f1=f3*f1; f1=f4-f1; f1=f2-f1;
 if(f1>f0) {
 f1=*(f32 *)((u8 *)arg0+0x4c); f0=lbl_8036ACEC; f1=f4*f1;
 *(f32 *)((u8 *)arg0+0x40)=f1; *(f32 *)((u8 *)arg0+0x48)=f0;
 }
 f1=*(f32 *)((u8 *)arg0+0x3c); r4=*(void **)((u8 *)arg0+0x30);
 f0=lbl_8036AD40; *(f32 *)((u8 *)r4+0xc)=f1;
 f1=*(f32 *)((u8 *)arg0+0x40);
 if(f1<f0) Process_ClearFunc(arg0);
}
#pragma global_optimizer on
#pragma fp_contract on
void fn_8018B3AC(void *arg0) {
    f32 *ptr;
    f32 c;
    f32 v;

    c = 0.0f;
    ptr = *(f32 **)((u8 *)arg0 + 0x30);
    v = ptr[1];
    *(f32 *)((u8 *)arg0 + 0x34) = v;
    ptr = *(f32 **)((u8 *)arg0 + 0x30);
    v = ptr[2];
    *(f32 *)((u8 *)arg0 + 0x38) = v;
    ptr = *(f32 **)((u8 *)arg0 + 0x30);
    v = ptr[3];
    *(f32 *)((u8 *)arg0 + 0x3C) = v;
    *(f32 *)((u8 *)arg0 + 0x48) = c;
}

void fn_8018B3DC(void *arg0) {
    M2C_UNK Model_SetAlpha(s32, u8);
    s32 temp_r31;

    temp_r31 = M2C_FIELD(arg0, s32 *, 0x30) + 0x1C;
    Model_SetColor(temp_r31, M2C_FIELD(arg0, u8 *, 0x38), M2C_FIELD(arg0, u8 *, 0x39), M2C_FIELD(arg0, u8 *, 0x3A));
    Model_SetAlpha(temp_r31, M2C_FIELD(arg0, u8 *, 0x3B));
}

void fn_8018B434(void *arg0) {
    f32 Math_Lerp(f32, f32, f32, f32);
    void Model_SetColor(void *, u8, u8, u8);
    void Model_SetAlpha(void *, u8);
    void Process_ClearFunc(void *);

    u8 sp8[4];
    void *obj;
    f32 f_from;
    f32 f_to;
    u8 fromByte;
    void *base;

    *(s32 *)((u8 *)arg0 + 0x40) += 1;
    fromByte = *(u8 *)((u8 *)arg0 + 0x34);
    f_from = (f32)fromByte;
    f_to = (f32)*(u8 *)((u8 *)arg0 + 0x38);
    obj = *(void **)((u8 *)arg0 + 0x30);
    *(s32 *)sp8 = *(s32 *)((u8 *)obj + 0x24);
    base = (u8 *)obj + 0x1C;
    sp8[0] = (u8)(s32)Math_Lerp(f_from, f_to, (f32)*(s32 *)((u8 *)arg0 + 0x3C), (f32)*(s32 *)((u8 *)arg0 + 0x40));
    sp8[1] = (u8)(s32)Math_Lerp((f32)*(u8 *)((u8 *)arg0 + 0x35), (f32)*(u8 *)((u8 *)arg0 + 0x39), (f32)*(s32 *)((u8 *)arg0 + 0x3C), (f32)*(s32 *)((u8 *)arg0 + 0x40));
    sp8[2] = (u8)(s32)Math_Lerp((f32)*(u8 *)((u8 *)arg0 + 0x36), (f32)*(u8 *)((u8 *)arg0 + 0x3A), (f32)*(s32 *)((u8 *)arg0 + 0x3C), (f32)*(s32 *)((u8 *)arg0 + 0x40));
    sp8[3] = (u8)(s32)Math_Lerp((f32)*(u8 *)((u8 *)arg0 + 0x37), (f32)*(u8 *)((u8 *)arg0 + 0x3B), (f32)*(s32 *)((u8 *)arg0 + 0x3C), (f32)*(s32 *)((u8 *)arg0 + 0x40));
    Model_SetColor(base, sp8[0], sp8[1], sp8[2]);
    Model_SetAlpha(base, sp8[3]);
    if (*(s32 *)((u8 *)arg0 + 0x40) >= *(s32 *)((u8 *)arg0 + 0x3C)) {
        Process_ClearFunc(arg0);
    }
}

void fn_8018B698(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
}

void fn_8018B6A4(void *arg0) {
    M2C_UNK Model_SetColor(s32, u8, u8, u8);
    Model_SetColor(M2C_FIELD(arg0, s32 *, 0x30) + 0x1C, M2C_FIELD(arg0, u8 *, 0x34), M2C_FIELD(arg0, u8 *, 0x35), M2C_FIELD(arg0, u8 *, 0x36));
}

void fn_8018B6DC(void *arg0) {
f32 fn_80059EB8(s32,s32,f32,f32);
f32 Math_Lerp(f32,f32,f32,f32);
void Process_ClearFunc(void*);
void Model_SetColor(void*,u8,u8,u8);
extern f32 lbl_8036ACEC,lbl_8036AD44;
f32 t;
void *model;
s32 red,green;
model=(u8*)*(void**)((u8*)arg0+0x30)+0x1C;
*(s32*)((u8*)arg0+0x44)+=1;
if(*(s32*)((u8*)arg0+0x44)>=*(s32*)((u8*)arg0+0x40)){
*(s32*)((u8*)arg0+0x44)=*(s32*)((u8*)arg0+0x40);
Process_ClearFunc(arg0);
}
t=fn_80059EB8(*(s32*)((u8*)arg0+0x40),*(s32*)((u8*)arg0+0x44),lbl_8036ACEC,lbl_8036AD44);
red=(s32)Math_Lerp((f32)*((u8*)arg0+0x34),(f32)*((u8*)arg0+0x38),lbl_8036AD44,t);
green=(s32)Math_Lerp((f32)*((u8*)arg0+0x35),(f32)*((u8*)arg0+0x39),lbl_8036AD44,t);
Model_SetColor(model,(u8)red,(u8)green,(u8)(s32)Math_Lerp((f32)*((u8*)arg0+0x36),(f32)*((u8*)arg0+0x3A),lbl_8036AD44,t));
}

void fn_8018B854(void *arg0) {
    void *temp_r5;

    temp_r5 = M2C_FIELD(arg0, void **, 0x30);
    M2C_FIELD(arg0, u8 *, 0x34) = (u8) M2C_FIELD(temp_r5, u8 *, 0x24);
    M2C_FIELD(arg0, u8 *, 0x35) = (u8) M2C_FIELD(temp_r5, u8 *, 0x25);
    M2C_FIELD(arg0, u8 *, 0x36) = (u8) M2C_FIELD(temp_r5, u8 *, 0x26);
    M2C_FIELD(arg0, u8 *, 0x37) = (u8) M2C_FIELD(temp_r5, u8 *, 0x27);
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
}

void fn_8018B884(void *arg0) {
    extern f32 lbl_8036ACEC;
    u8 *ptr;
    f32 value;

    ptr = *(u8 **)((u8 *)arg0 + 0x30);
    value = lbl_8036ACEC;

    *(f32 *)(ptr + 0x10) = value;
    *(f32 *)(ptr + 0x14) = value;
    *(f32 *)(ptr + 0x18) = value;
}

void fn_8018B89C(void *arg0) {
    f64 sin(f32);
    void Process_ClearFunc(void *);
    extern const f32 lbl_8036ACEC;
    f32 t;
    f32 scale;
    void *p;
    void *self;

    self = arg0;
    *(s32 *)((u8 *)self + 0x40) += 1;
    *(f32 *)((u8 *)self + 0x44) =
        *(f32 *)((u8 *)self + 0x44) + *(f32 *)((u8 *)self + 0x34);
    t = (f32)sin(*(f32 *)((u8 *)self + 0x44));
    scale = *(f32 *)((u8 *)self + 0x3C);
    p = *(void **)((u8 *)self + 0x30);
    *(f32 *)((u8 *)p + 0x10) = scale * t;
    *(f32 *)((u8 *)p + 0x14) = lbl_8036ACEC;
    *(f32 *)((u8 *)p + 0x18) = lbl_8036ACEC;
    if (*(s32 *)((u8 *)self + 0x40) >= *(s32 *)((u8 *)self + 0x38)) {
        Process_ClearFunc(self);
    }
}

#pragma scheduling off
#pragma global_optimizer off
void fn_8018B920(void *arg0) {
    extern f32 lbl_8036ACEC;
    s32 z;
    f32 f;

    z = 0;
    f = lbl_8036ACEC;
    *(s32 *)((u8 *)arg0 + 0x40) = z;
    *(f32 *)((u8 *)arg0 + 0x44) = f;
}
#pragma global_optimizer reset
#pragma scheduling reset
void fn_8018B934(void *arg0) {
    f32 fn_8005A028(s32, f32, f32, f32, f32);
    void fn_8000C188(void *);
    extern f32 lbl_8036ACE8;
    extern f32 lbl_8036AD48;
    f32 ad48;
    f32 ace8;
    f32 temp_f1;
    void *temp_r4;

    M2C_FIELD(arg0, s32 *, 0x3C) = M2C_FIELD(arg0, s32 *, 0x3C) + 1;
    temp_f1 = fn_8005A028(2, M2C_FIELD(arg0, f32 *, 0x40), M2C_FIELD(arg0, f32 *, 0x44), (f32) M2C_FIELD(arg0, s32 *, 0x38), (f32) M2C_FIELD(arg0, s32 *, 0x3C));
    ad48 = lbl_8036AD48;
    ace8 = lbl_8036ACE8;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s16 *, 0x15C) = (s16) (ace8 * (temp_f1 - ad48 * (f32) (s32) (temp_f1 / ad48)));
    if (M2C_FIELD(arg0, s32 *, 0x3C) == M2C_FIELD(arg0, s32 *, 0x38)) {
        temp_r4 = M2C_FIELD(arg0, void **, 0x30);
        M2C_FIELD(temp_r4, s16 *, 0x15C) = (s16) (ace8 * M2C_FIELD(arg0, f32 *, 0x34));
        fn_8000C188(arg0);
    }
}
#pragma fp_contract reset
void fn_8018BA34(void *arg0) {
    extern f64 lbl_8036ACE0;
    extern f32 lbl_8036ACE8;
    extern f32 lbl_8036AD2C;
    extern f32 lbl_8036AD48;
    register f32 scale;
    register f32 thresh;
    register f32 a;
    register f32 b;
    s16 raw;
    void *unit;

    unit = *(void **)((u8 *)arg0 + 0x30);
    raw = *(s16 *)((u8 *)unit + 0x15C);
    thresh = lbl_8036AD2C;
    scale = lbl_8036ACE8;
    *(f32 *)((u8 *)arg0 + 0x40) = (f32)raw / scale;
    *(f32 *)((u8 *)arg0 + 0x44) = *(f32 *)((u8 *)arg0 + 0x34);
    a = *(f32 *)((u8 *)arg0 + 0x40);
    b = *(f32 *)((u8 *)arg0 + 0x44);
    if ((f32)__fabs(a - b) > thresh) {
        if (a < b) {
            *(f32 *)((u8 *)arg0 + 0x40) = a + lbl_8036AD48;
        } else if (a > b) {
            *(f32 *)((u8 *)arg0 + 0x44) = b + lbl_8036AD48;
        }
    }
    *(s32 *)((u8 *)arg0 + 0x3C) = 0;
    (void)lbl_8036ACE0;
}

void fn_8018BAC8(void *arg0) {
u8 Pad_IsButton(void*,s32);
s32 fn_8005B760(s32);
void fn_80060F70(void*,s32,void*);
void fn_8004B8F8(s32,s32,f32,f32);
extern u8 gBattleMap[];
extern f32 lbl_8036ACE8,lbl_8036AD48;
f32 pos[3];
u8 *unit=*(u8**)((u8*)arg0+0x30);
void *pad=unit+0x1C;
s32 i;
if((*(u8**)(unit+0x18C))[0x42]!=9 && Pad_IsButton(pad,0x32)){
s32 x,y;
unit=*(u8**)((u8*)arg0+0x30);
x=(s8)(s32)*(f32*)(unit+4);y=(s8)(s32)*(f32*)(unit+8);
switch(fn_8005B760((gBattleMap+x+(y<<6))[0x100D])){
case 0x18: case 0x19:
for(i=0;i<2;i++){
s32 index;
unit=*(u8**)((u8*)arg0+0x30);
index=*(s8*)(unit+0x168+i);
if(index>=0){
fn_80060F70(pad,index,pos);
unit=*(u8**)((u8*)arg0+0x30);
fn_8004B8F8((s32)(lbl_8036AD48-(f32)*(s16*)(unit+0x15C)/lbl_8036ACE8),0,pos[0],pos[1]);
}
}
break;
case 0x1A:
unit=*(u8**)((u8*)arg0+0x30);
fn_8004B8F8(0,1,*(f32*)(unit+4),*(f32*)(unit+8));
break;
}
}
}

#pragma dont_inline on
void fn_8018BC28(void *arg0) {
 u8 Pad_IsActive(void *);u8 Pad_IsButton(void *,s32);
 void *fn_80105C5C(void *,s32);s32 fn_8005B760(s32);
 void SeCue_PlayAt(void *,s32,f32,f32,f32);
 s32 Str_Cmp(void *,void *);void *fn_80234198(void *,void *);
 MoveClassKind fn_800A883C(void *,s32);
 void DebugPrint(void *,...);
 void fn_8004AE28(void *,f32,f32,f32);u16 fn_8005F92C(void *,void *);
 void fn_8018CFA4(s32,s32,s32,s32,void *);void fn_8018CF08(void);void fn_8018CF48(s32);void fn_80025624(void *,s32);
 extern u8 MoveAnim_str[],gBattleMap[];
 extern MoveSoundButtons lbl_80278DE0;
 extern void *gPadInput;
 MoveSoundButtons buttons;
 MoveClassKind c3,c2,c1,c0;
 void *pad;
 void *cls;
 s32 volume;
 u8 heavy;
 void *message;
 f32 x,y,z;
 pad=(u8 *)M2C_FIELD(arg0,void **,0x30)+0x1C;
 if(Pad_IsActive(pad)){
 x=M2C_FIELD(M2C_FIELD(arg0,void **,0x30),f32 *,4);
 y=M2C_FIELD(M2C_FIELD(arg0,void **,0x30),f32 *,8);
 z=M2C_FIELD(M2C_FIELD(arg0,void **,0x30),f32 *,12);
 if(Pad_IsButton(pad,0x32)){
 cls=M2C_FIELD(M2C_FIELD(arg0,void **,0x30),void **,0x18C);
 volume=100;
 if(M2C_FIELD(cls,u8 *,0x42)!=9){
 heavy=0;
 if(M2C_FIELD(cls,u8 *,0x42)==7||M2C_FIELD(cls,u8 *,0x42)==8)heavy=1;
 if((M2C_FIELD(cls,u16 *,0x3A)&0x40)&&fn_80105C5C((u8 *)M2C_FIELD(arg0,void **,0x30)+0x1BC,9))heavy=1;
 switch(fn_8005B760((gBattleMap+(s8)(s32)x+((s8)(s32)y<<6))[0x100D])){
 case 26:if(!heavy)SeCue_PlayAt(MoveAnim_str+0x50B,100,x,y,z);else SeCue_PlayAt(MoveAnim_str+0x51F,100,x,y,z);volume=70;break;
 case 24:if(!heavy)SeCue_PlayAt(MoveAnim_str+0x533,100,x,y,z);else SeCue_PlayAt(MoveAnim_str+0x546,100,x,y,z);volume=70;break;
 case 25:if(!heavy)SeCue_PlayAt(MoveAnim_str+0x559,100,x,y,z);else SeCue_PlayAt(MoveAnim_str+0x56C,100,x,y,z);volume=70;break;
 }}
 switch(M2C_FIELD(cls,u8 *,0x42)){
 case 7: message=MoveAnim_str+0x57f;SeCue_PlayAt(MoveAnim_str+0x59f,volume,x,y,z);break;
 case 8:
 if(Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x5b3)==0){message=MoveAnim_str+0x57f;SeCue_PlayAt(MoveAnim_str+0x59f,volume,x,y,z);}else{message=MoveAnim_str+0x5c2;SeCue_PlayAt(MoveAnim_str+0x5e2,volume,x,y,z);}break;
 case 3:case 4:message=MoveAnim_str+0x5f6;SeCue_PlayAt(MoveAnim_str+0x616,volume,x,y,z);break;
 case 9:
 if(Str_Cmp(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void **,0x30),void **,0x188),void **,0),MoveAnim_str+0x4a7)==0){message=MoveAnim_str+0x62a;SeCue_PlayAt(MoveAnim_str+0x64e,volume,x,y,z);}
 else if((s32)(c0=fn_800A883C(cls,0)).value==3||(s32)(c1=fn_800A883C(cls,1)).value==3){message=MoveAnim_str+0x666;SeCue_PlayAt(MoveAnim_str+0x68a,volume,x,y,z);}
 else if((s32)(c2=fn_800A883C(cls,0)).value==4||(s32)(c3=fn_800A883C(cls,1)).value==4){message=MoveAnim_str+0x6a2;SeCue_PlayAt(MoveAnim_str+0x6c6,volume,x,y,z);}
 else if(Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x6de)==0||Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x6ea)==0||Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x6f8)==0||Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x312)==0||Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x332)==0||Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x33e)==0){message=MoveAnim_str+0x708;SeCue_PlayAt(MoveAnim_str+0x72c,volume,x,y,z);}
 else if(Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x744)==0||Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x2bc)==0){message=MoveAnim_str+0x750;SeCue_PlayAt(MoveAnim_str+0x774,volume,x,y,z);}
 else{message=MoveAnim_str+0x78c;SeCue_PlayAt(MoveAnim_str+0x7b0,volume,x,y,z);}break;
 default:
 if(M2C_FIELD(cls,u16 *,0x3A)&0x40){
 if(Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x21d)==0||Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x239)==0){message=MoveAnim_str+0x7c8;SeCue_PlayAt(MoveAnim_str+0x7e8,volume,x,y,z);break;}
 if(Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x7fc)==0){message=MoveAnim_str+0x808;SeCue_PlayAt(MoveAnim_str+0x828,volume,x,y,z);break;}
 if(fn_80105C5C((u8 *)M2C_FIELD(arg0,void **,0x30)+0x1BC,9)){message=MoveAnim_str+0x83c;SeCue_PlayAt(MoveAnim_str+0x85c,volume,x,y,z);break;}
 }
 if((M2C_FIELD(cls,u16 *,0x3A)&0x80)&&fn_80105C5C((u8 *)M2C_FIELD(arg0,void **,0x30)+0x1BC,9)){message=MoveAnim_str+0x870;SeCue_PlayAt(MoveAnim_str+0x891,volume,x,y,z);break;}
 if(Str_Cmp(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void **,0x30),void **,0x188),void **,0),MoveAnim_str+0x8a6)==0){message=MoveAnim_str+0x5f6;SeCue_PlayAt(MoveAnim_str+0x616,volume,x,y,z);break;}
 if(Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x8b6)==0||Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x8c2)==0||Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x8d0)==0||Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x8db)==0){message=MoveAnim_str+0x808;SeCue_PlayAt(MoveAnim_str+0x828,volume,x,y,z);break;}
 if(fn_80234198(M2C_FIELD(cls,void **,0),MoveAnim_str+0x8e6)||Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x8e9)==0){
 if(Str_Cmp(M2C_FIELD(cls,void **,0),MoveAnim_str+0x8f3)==0){message=MoveAnim_str+0x902;SeCue_PlayAt(MoveAnim_str+0x922,volume,x,y,z);}else{message=MoveAnim_str+0x936;SeCue_PlayAt(MoveAnim_str+0x956,volume,x,y,z);}
 }else{message=MoveAnim_str+0x902;SeCue_PlayAt(MoveAnim_str+0x922,volume,x,y,z);}
 break;
 }
 if(message)DebugPrint(MoveAnim_str+0x96A,message,M2C_FIELD(pad,f32 *,0x58));
 }
 fn_8004AE28(pad,x,y,z);
 buttons=lbl_80278DE0;
 switch(fn_8005F92C(pad,&buttons)){
 case 10:fn_8018CFA4(15,6,2,1,arg0);break;
 case 9:fn_8018CFA4(30,6,2,1,arg0);break;
 case 11:fn_8018CFA4(60,6,2,1,arg0);break;
 case 31:fn_8018CFA4(15,6,0,1,arg0);break;
 case 30:fn_8018CFA4(30,6,0,1,arg0);break;
 case 32:fn_8018CFA4(60,6,0,1,arg0);break;
 case 33:fn_8018CF08();break;
 case 34:fn_8018CF48(-15);break;
 case 35:fn_8018CF48(-7);break;
 case 36:fn_8018CF48(-30);break;
 case 37:fn_8018CF48(15);break;
 case 38:fn_8018CF48(7);break;
 case 39:fn_8018CF48(30);break;
 }
 if(Pad_IsButton(pad,47))fn_80025624(gPadInput,4);
 if(Pad_IsButton(pad,48))fn_80025624(gPadInput,16);
 }
}
#pragma dont_inline reset
void fn_8018C680(void *arg0)
{
    void *Msg_ResolveName(void *);
    void DebugPrint(const char *, ...);
    extern u8 MoveAnim_str[];
    void *p;

    p = *(void **)((u8 *)arg0 + 0x30);
    p = *(void **)((u8 *)p + 0x188);
    DebugPrint((char *)(MoveAnim_str + 0x97b), Msg_ResolveName(p), MoveAnim_str);
}

#pragma opt_strength_reduction off
void fn_8018C6C0(void *arg0) {
    void GfxEnt_ForEachKey(void *, void *, void *);
    void *Process_CreateEx(void *, s32);
    u8 fn_8004C0F0(void *);
    void fn_8004FE90(void *, u8);
    void fn_8004FE98(void *, s32);
    void fn_800506E0(void *, s32);
    void *fn_800508C4(void *);
    f32 Math_Lerp(f32, f32, f32, f32);
    void fn_8005FC74(void *, void *, s32);
    void fn_8005FEE8(void *, f32);
    s32 fn_80060440(void *);
    void *fn_800639B4(void);
    void MuFade_UnlinkSame(void *, void *);
    extern u8 E_MuBlend_script[];
    extern u8 E_MuTransfer_script[];
    extern f32 lbl_8036ACEC;
    extern f32 lbl_8036ACF0;
    u8 sp40[0x34];
    u8 sp8[0x38];
    u32 mode;
    void *obj;
    s32 kind;
    s32 count;

    mode = *(u32 *)((u8 *)arg0 + 0x18);
    if (mode == 3U) {
        mode = 0;
    }
    obj = *(void **)((u8 *)arg0 + 0x30);
    count = *(s32 *)((u8 *)arg0 + 0x3C);
    kind = *(s32 *)((u8 *)arg0 + 0x38);
    if (fn_8004C0F0(obj) != 0) {
        *(void **)(sp40 + 0x30) = obj;
        GfxEnt_ForEachKey(E_MuBlend_script, MuFade_UnlinkSame, sp40);
        *(void **)(sp8 + 0x30) = obj;
        GfxEnt_ForEachKey(E_MuTransfer_script, MuFade_UnlinkSame, sp8);
        {
            s32 lvl = *(u8 *)((u8 *)fn_800508C4(obj) + 9);
            if (lvl > 0x14) {
                if (lvl > 0x28) {
                    count <<= 1;
                } else {
                    count = (s32)((f32)count + Math_Lerp(lbl_8036ACEC, (f32)count, lbl_8036ACF0, (f32)(lvl - 0x14)));
                }
            }
        }
        if ((count == 0) || (fn_80060440((u8 *)obj + 0x1C) >= 4)) {
            fn_8004FE98(obj, kind);
        } else {
            mode = (u32)Process_CreateEx(E_MuBlend_script, (s32)mode);
            *(void **)((u8 *)mode + 0x30) = obj;
            *(s32 *)((u8 *)mode + 0x34) = (s32)obj + 0x1C;
            *(s32 *)((u8 *)mode + 0x38) = kind;
            *(s32 *)((u8 *)mode + 0x3C) = count;
            *(s32 *)((u8 *)mode + 0x40) = 0;
            fn_800506E0(*(void **)((u8 *)mode + 0x30), kind);
            obj = fn_800639B4();
            count = 0;
            if (kind < 8) {
                if (kind < 2) {
                    if (kind >= 0) {
                        goto do_extra;
                    }
                }
            } else if (kind == 8) {
                goto do_extra;
            } else if (kind == 0xF) {
                goto do_extra;
            }
            goto after_extra;
do_extra:
            {
                void *node = *(void **)((u8 *)mode + 0x34);
                void *link = *(void **)((u8 *)node + 0x44);
                if (link != NULL) {
                    f32 base = (f32)*(s32 *)((u8 *)link + 0x14);
                    count = (s32)Math_Lerp(
                        (f32)*(s32 *)((u8 *)obj + 0x14),
                        (f32)*(s32 *)((u8 *)obj + 0x18),
                        (f32)*(s32 *)((u8 *)link + 0x18) - base,
                        *(f32 *)((u8 *)node + 0x58) - base);
                }
            }
after_extra:
            fn_8005FC74(*(void **)((u8 *)mode + 0x34), obj, 1);
            fn_8005FEE8(*(void **)((u8 *)mode + 0x34), (f32)count);
            fn_8004FE90(*(void **)((u8 *)mode + 0x30), (u8)*(s32 *)((u8 *)mode + 0x38));
        }
    }
}
#pragma opt_strength_reduction on

void fn_8018C964(void *arg0) {
    u8 Mu_IsAnimDone(s32);
    if (Mu_IsAnimDone(M2C_FIELD(arg0, s32 *, 0x30)) != 0) {
        Process_ClearFunc(arg0);
    }
}

void fn_8018C9A4(void *arg0) {
    M2C_UNK fn_8005FA14(s32, M2C_UNK);
    fn_8005FA14(M2C_FIELD(arg0, s32 *, 0x34), 1);
}

void fn_8018C9CC(void *arg0) {
    f32 Math_EaseOutPow(M2C_UNK, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern f32 lbl_8036ACEC;
    extern f32 lbl_8036ACF8;
    s32 cnt;

    cnt = *(s32 *)((u8 *)arg0 + 0x40);
    *(s32 *)((u8 *)arg0 + 0x40) = cnt + 1;
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x34) + 0x78) = Math_EaseOutPow(2, lbl_8036ACEC, lbl_8036ACF8, (f32)*(s32 *)((u8 *)arg0 + 0x3C), (f32)*(s32 *)((u8 *)arg0 + 0x40));
    if (*(s32 *)((u8 *)arg0 + 0x40) >= *(s32 *)((u8 *)arg0 + 0x3C)) {
        Process_ClearFunc(arg0);
    }
}

extern u8 LightScale_script[];
#pragma opt_strength_reduction off
void fn_8018CA68(u32 arg0) {
    void *Process_Find(void *);
    void fn_80050BA8(u32, s32, s32);
    extern u8 LightScale_script[];
    void *proc;
    u32 idx;
    u32 *p;

    proc = Process_Find(LightScale_script);
    if ((proc != NULL) && (arg0 != 0U)) {
        idx = *(u32 *)((u8 *)proc + 0x44);
        p = (u32 *)((u8 *)proc + (idx << 2));
        p[0x12] = arg0;
        idx = *(u32 *)((u8 *)proc + 0x44);
        *(u32 *)((u8 *)proc + 0x44) = idx + 1;
        fn_80050BA8(arg0, 1, 1);
    }
}
#pragma opt_strength_reduction reset
void fn_8018CAD8(s32 arg0, s32 arg1, s32 arg2) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    void Process_Goto(void *, s32);
    extern u8 LightScale_script[];
    void *var_r31;
    s32 var_r0;

    var_r31 = Process_Find(LightScale_script);
    if (var_r31 == NULL) {
        var_r31 = Process_Create(LightScale_script, arg2);
    } else {
        *(s32 *)((char *)var_r31 + 0x34) = *(s32 *)((char *)var_r31 + 0x30);
        Process_Goto(var_r31, 0);
    }
    *(s32 *)((char *)var_r31 + 0x38) = arg0;
    var_r0 = 1;
    if (arg1 != 0) {
        var_r0 = arg1;
    }
    *(s32 *)((char *)var_r31 + 0x40) = var_r0;
    *(s32 *)((char *)var_r31 + 0x3C) = 0;
}

void fn_8018CB7C(void) {
    M2C_UNK Light_ScaleProcess();
    Light_ScaleProcess();
}

void fn_8018CB9C(void *arg0) {
 s32 Light_GetChannel(s32);
 void Light_CopyChannel(s32,s32);
 void fn_80050BA8(s32,s32,s32);
 s32 i; u8 *p; s32 t;
 Light_CopyChannel(Light_GetChannel(1),Light_GetChannel(0));
 Light_CopyChannel(Light_GetChannel(3),Light_GetChannel(2));
 p=(u8 *)arg0;
 for(i=0;i<*(s32 *)((u8 *)arg0+0x44);i++) {
 fn_80050BA8(*(s32 *)(p+0x48),0,0); p+=4; }
}

void fn_8018CC3C(void *arg0) {
    M2C_UNK Light_CopyChannel(s32, s32);
    s32 Light_GetChannel(M2C_UNK);

    Light_CopyChannel(Light_GetChannel(0), Light_GetChannel(1));
    Light_CopyChannel(Light_GetChannel(2), Light_GetChannel(3));
    M2C_FIELD(arg0, s32 *, 0x30) = 0x64;
    M2C_FIELD(arg0, s32 *, 0x34) = 0x64;
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
}

/* Ease light intensity from start to end over duration, scale channels 0/2 from channel 1, then finish the process. */
void Light_ScaleProcess(void *proc) {
    f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
    u8 *Light_GetChannel(s32);
    void Process_Unlink(void *);
    void Process_ClearFunc(void *);
    s32 scale;
    s32 v;
    u8 *src;
    u8 *dst0;
    u8 *dst2;

    *(s32 *)((u8 *)proc + 0x3C) = *(s32 *)((u8 *)proc + 0x3C) + 1;
    *(s32 *)((u8 *)proc + 0x30) = (s32) Math_EaseOutPow(
        2,
        (f32)*(s32 *)((u8 *)proc + 0x34),
        (f32)*(s32 *)((u8 *)proc + 0x38),
        (f32)*(s32 *)((u8 *)proc + 0x40),
        (f32)*(s32 *)((u8 *)proc + 0x3C));
    src = Light_GetChannel(1);
    dst0 = Light_GetChannel(0);
    dst2 = Light_GetChannel(2);
    scale = *(s32 *)((u8 *)proc + 0x30);

    v = (src[4] * scale) / 100;
    if (v > 0xFF) {
        v = 0xFF;
    }
    dst0[4] = v;
    dst2[4] = v;

    v = (src[5] * scale) / 100;
    if (v > 0xFF) {
        v = 0xFF;
    }
    dst0[5] = v;
    dst2[5] = v;

    v = (src[6] * scale) / 100;
    if (v > 0xFF) {
        v = 0xFF;
    }
    dst0[6] = v;
    dst2[6] = v;

    v = (src[0] * scale) / 100;
    if (v > 0xFF) {
        v = 0xFF;
    }
    dst0[0] = v;
    dst2[0] = v;

    v = (src[1] * scale) / 100;
    if (v > 0xFF) {
        v = 0xFF;
    }
    dst0[1] = v;
    dst2[1] = v;

    v = (src[2] * scale) / 100;
    if (v > 0xFF) {
        v = 0xFF;
    }
    dst0[2] = v;
    dst2[2] = v;

    if (*(s32 *)((u8 *)proc + 0x3C) >= *(s32 *)((u8 *)proc + 0x40)) {
        if (*(s32 *)((u8 *)proc + 0x30) == 0x64) {
            Process_Unlink(proc);
        } else {
            Process_ClearFunc(proc);
        }
    }
}

void fn_8018CF08(void) {
    void *Process_Find(void *);
    extern u8 lbl_80296018[];
    void *temp_r3;

    temp_r3 = Process_Find(lbl_80296018);
    if (temp_r3 != NULL) {
        *(s32 *)((u8 *)temp_r3 + 0x3C) = 1;
        *(s32 *)((u8 *)temp_r3 + 0x40) = 0;
    }
}

void fn_8018CF48(s32 arg0) {
    void *Process_Find(void *);
    extern u8 lbl_80296018[];
    void *temp_r3;

    temp_r3 = Process_Find(lbl_80296018);
    if (temp_r3 != NULL) {
        arg0 = *(s32 *)((u8 *)temp_r3 + 0x34) + arg0;
        if (arg0 < 0) {
            arg0 = 0;
        }
        if (arg0 > 0x64) {
            arg0 = 0x64;
        }
        *(s32 *)((u8 *)temp_r3 + 0x40) = arg0;
    }
}

#pragma use_lmw_stmw on
void fn_8018CFA4(s32 arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4) {
    u32 Process_Find(void *);
    void *Process_Create(void *, s32);
    u32 Camera_GetActive(void);
    extern u8 lbl_80296018[];
    s32 var_r0;
    void *temp_r3;

    if (Camera_GetActive() != 0U && (arg3 != 0 || Process_Find(lbl_80296018) == 0U)) {
        temp_r3 = Process_Create(lbl_80296018, arg4);
        var_r0 = 1;
        if (arg1 != 0) {
            var_r0 = arg1;
        }
        *(s32 *)((u8 *)temp_r3 + 0x38) = var_r0;
        *(s32 *)((u8 *)temp_r3 + 0x34) = arg0;
        *(s32 *)((u8 *)temp_r3 + 0x40) = arg0;
        *(s32 *)((u8 *)temp_r3 + 0x3C) = arg2;
    }
}

void fn_8018D034(void *arg0) {
    f32 Math_Lerp(f32, f32, f32, f32);
    f64 sin(f64);
    void Process_Unlink(void *);
    extern f32 lbl_8036AD58, lbl_8036AD5C, lbl_8036AD60, lbl_8036AD64;
    typedef struct { f32 x, y, z; } Vec;
    extern Vec lbl_802797CC;
    Vec copy, v;
    s32 prev;
    s32 delta, step, current, target;
    f32 x, z, wave;
    void *obj;

    prev = M2C_FIELD(arg0, s32 *, 0x30);
    M2C_FIELD(arg0, s32 *, 0x30) = prev + 1;
    target = M2C_FIELD(arg0, s32 *, 0x40);
    current = M2C_FIELD(arg0, s32 *, 0x34);
    if (target != current) {
        delta = target - current;
        step = delta / 4;
        if (step) {
            M2C_FIELD(arg0, s32 *, 0x34) = current + step;
        } else {
            M2C_FIELD(arg0, s32 *, 0x34) = current + delta;
        }
        if (delta < 0 && M2C_FIELD(arg0, s32 *, 0x34) < M2C_FIELD(arg0, s32 *, 0x40)) {
            M2C_FIELD(arg0, s32 *, 0x34) = M2C_FIELD(arg0, s32 *, 0x40);
        }
        if (delta > 0 && M2C_FIELD(arg0, s32 *, 0x34) > M2C_FIELD(arg0, s32 *, 0x40)) {
            M2C_FIELD(arg0, s32 *, 0x34) = M2C_FIELD(arg0, s32 *, 0x40);
        }
        step = prev;
        (void)step;
    } else {
        step = prev;
        (void)step;
    }
    wave = (f32)sin(Math_Lerp(lbl_8036AD58, lbl_8036AD5C, (f32)M2C_FIELD(arg0, s32 *, 0x38), (f32)M2C_FIELD(arg0, s32 *, 0x30)));
    v = lbl_802797CC;
    x = lbl_8036AD60 * wave;
    v.x = x * (f32)M2C_FIELD(arg0, s32 *, 0x34);
    z = lbl_8036AD64 * wave;
    v.z = z * (f32)M2C_FIELD(arg0, s32 *, 0x34);
    obj = M2C_FIELD(arg0, void **, 0x44);
    copy = v;
    M2C_FIELD(obj, f32 *, 0x58) = copy.x;
    M2C_FIELD(obj, f32 *, 0x5C) = copy.y;
    M2C_FIELD(obj, f32 *, 0x60) = copy.z;
    if (M2C_FIELD(arg0, s32 *, 0x30) >= M2C_FIELD(arg0, s32 *, 0x38)) {
        M2C_FIELD(arg0, s32 *, 0x30) = 0;
        if (M2C_FIELD(arg0, s32 *, 0x3C) > 0) {
            M2C_FIELD(arg0, s32 *, 0x3C)--;
            if (M2C_FIELD(arg0, s32 *, 0x3C) == 0) {
                Process_Unlink(arg0);
                return;
            }
            goto check;
        }
    } else {
    check:
        if (M2C_FIELD(arg0, s32 *, 0x34) == 0) {
            Process_Unlink(arg0);
        }
    }
}

void fn_8018D218(void *arg0)
{
    typedef struct { f32 x, y, z; } Vec3;
    extern Vec3 lbl_802797C0;
    Vec3 a;
    void *p;

    p = *(void **)((u8 *)arg0 + 0x44);
    a = lbl_802797C0;
    *(f32 *)((u8 *)p + 0x58) = a.x;
    *(f32 *)((u8 *)p + 0x5C) = a.y;
    *(f32 *)((u8 *)p + 0x60) = a.z;
}

void fn_8018D25C(void *arg0) {
    s32 Camera_GetActive();
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = Camera_GetActive();
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
static inline s32 AiItemTableIndex_inl(void *unit, void **entry) {
    u32 *Hash_Lookup(char *);
    u8 Unit_CanReceiveItem(void *, void **);
    s32 Str_Cmp(s32, u32);
    extern u8 lbl_802798D0[];
    u32 *tbl = Hash_Lookup((char *)((u32)lbl_802798D0 + 0x1D));
    s32 dist;
    s32 val;
    u32 t;
    if (!Unit_CanReceiveItem(unit, entry)) {
        return -1;
    }
    dist = 0;
    while ((t = *tbl) != 0) {
        if (*(u32 *)entry != 0) {
            val = *(s32 *)*(void **)entry;
        } else {
            val = 0;
        }
        if (Str_Cmp(val, t) == 0) {
            return dist;
        }
        tbl++;
        dist++;
    }
    return -1;
}

u8 fn_8018D294(void *arg0, s32 arg1) {
    u8 Status_Test(void *, s32);
    void fn_8002F728(void *);
    void fn_8002C47C(void *, s32);
    void TargetList_GetAt(void *, s32);
    void *UnitRef_GetUnit(void);
    u8 fn_8003DC80(void *, void *);
    void **Unit_GetItemSlot(void *, s32);
    u32 *Hash_Lookup(char *);
    u8 Unit_CanReceiveItem(void *, void **);
    s32 Str_Cmp(s32, u32);
    void fn_8010F3F4(void *, s8, s8, s16 *, s16 *);
    void fn_800FB96C(s32, s8, s8, void *, s8, s8, s8, s32, s32);
    extern u8 lbl_80284E20[];
    extern u8 lbl_80296078[];
    extern s32 gTargetList[];
    extern u8 lbl_802798D0[];
    extern u8 gAiState[];

    struct {
        void *vtbl;
        void *unk4;
        s32 unk8;
    } obj;
    s16 sp12;
    s16 sp10;
    register s32 val;
    s32 dist;
    u32 *tbl;
    u32 t;
    void **entry;
    s8 slot;
    s8 foundSlot;
    s8 bestSlot;
    s32 bestDist;
    s32 foundDist;
    void *bestUnit;
    s32 i;
    void *unit;

    bestDist = 0x7FFFFFFF;
    if (!Status_Test((u8 *)arg0 + 0x1BC, 0x3C)) {
        return 0;
    }
    obj.vtbl = lbl_80284E20;
    obj.unk4 = arg0;
    obj.vtbl = lbl_80296078;
    obj.unk8 = arg1;
    fn_8002F728(gTargetList);
    fn_8002C47C(&obj, 0);
    i = 0;
    while (i < gTargetList[0]) {
        TargetList_GetAt(gTargetList, i);
        unit = UnitRef_GetUnit();
        if (fn_8003DC80(arg0, unit)) {
            foundSlot = -1;
            foundDist = -1;
            slot = 0;
            while ((s8)slot < 8) {
                entry = Unit_GetItemSlot(unit, slot);
                if (*(u32 *)entry != 0) {
                    dist = AiItemTableIndex_inl(arg0, entry);
                    if (dist >= 0) {
                        foundSlot = slot;
                        foundDist = dist;
                        break;
                    }
                }
                slot++;
            }
            if ((s8)foundSlot >= 0 && bestDist > foundDist) {
                bestDist = foundDist;
                bestUnit = unit;
                bestSlot = foundSlot;
            }
        }
        i++;
    }
    if (bestDist != 0x7FFFFFFF) {
        s32 bx;
        s32 by;
        bx = *(s8 *)((u8 *)bestUnit + 0x19E);
        by = *(s8 *)((u8 *)bestUnit + 0x19F);
        fn_8010F3F4(arg0, bx, by, &sp12, &sp10);
        *(u16 *)((u8 *)arg0 + 0x258) =
            *(u16 *)((u8 *)arg0 + 0x258) + 1;
        fn_800FB96C(0x11, (s8)sp12, (s8)sp10, bestUnit, bx, by, bestSlot, 0, 0);
    }
    return gAiState[0x21C];
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
u8 Ai_TryStealAction(void *arg0, s32 arg1) {
    u8 Status_Test(void *, s32);
    void Map_FillLayer(void *, s32, s32);
    void Map_SelectRangeBuffer(void *, s32);
    void Map_BuildUnitMoveRange(void *, s32, s32);
    void fn_8002F728(void *);
    void fn_8002C47C(void *, s32);
    void TargetList_GetAt(void *, s32);
    void *UnitRef_GetUnit(void);
    u8 fn_8003DC80(void *, void *);
    void **Unit_GetItemSlot(void *, s32);
    u32 *Hash_Lookup(char *);
    u8 Unit_CanReceiveItem(void *, void **);
    s32 Str_Cmp(s32, u32);
    void fn_8010F3F4(void *, s8, s8, s16 *, s16 *);
    void fn_800FB96C(s32, s8, s8, void *, s8, s8, s8, s32, s32);
    extern u8 gBattleMap[];
    extern u8 lbl_80284E20[];
    extern u8 lbl_80296078[];
    extern s32 gTargetList[];
    extern u8 lbl_802798D0[];
    extern u8 gAiState[];

    struct { void *vtbl; void *unk4; s32 unk8; } obj;
    s16 sp12;
    s16 sp10;
    register s32 val;
    s32 dist;
    u32 *tbl;
    u32 t;
    void **entry;
    s8 slot;
    s8 foundSlot;
    s8 bestSlot;
    s32 bestDist;
    s32 foundDist;
    void *bestUnit;
    s32 i;
    void *unit;
    void *base;

    base = gBattleMap;
    if (!Status_Test((u8 *)arg0 + 0x1BC, 0x3C)) return 0;
    if ((gAiState[1] & 2) || (*(u32 *)((u8 *)arg0 + 0x254) & 0x03000000)) {
        Map_FillLayer(base, 5, -1);
        Map_SelectRangeBuffer(base, 5);
        ((s16 *)*(void **)((u8 *)base + 0x14190))[(s8)*(u8 *)((u8 *)arg0 + 0x19E) + ((s8)*(u8 *)((u8 *)arg0 + 0x19F) << 6)] = 0;
    } else {
        Map_BuildUnitMoveRange(arg0, 5, -1);
    }
    bestDist = 0x7FFFFFFF;
    if (!Status_Test((u8 *)arg0 + 0x1BC, 0x3C)) return 0;
    obj.vtbl = lbl_80284E20;
    obj.unk4 = arg0;
    obj.vtbl = lbl_80296078;
    obj.unk8 = arg1;
    fn_8002F728(gTargetList);
    fn_8002C47C(&obj, 0);
    i = 0;
    while (i < gTargetList[0]) {
        TargetList_GetAt(gTargetList, i);
        unit = UnitRef_GetUnit();
        if (fn_8003DC80(arg0, unit)) {
            foundSlot = -1;
            slot = 0;
            foundDist = foundSlot;
            while ((s8)slot < 8) {
                entry = Unit_GetItemSlot(unit, slot);
                if (*(u32 *)entry != 0) {
                    tbl = Hash_Lookup((char *)((u32)lbl_802798D0 + 0x1D));
                    if (!Unit_CanReceiveItem(arg0, entry)) {
                        dist = -1;
                    } else {
                        dist = 0;
                        goto lbl_check;
                    lbl_body:
                        if (*(u32 *)entry != 0) {
                            val = *(s32 *)*(void **)entry;
                        } else {
                            val = 0;
                        }
                        if (Str_Cmp(val, t) == 0) goto lbl_done;
                        tbl++;
                        dist++;
                    lbl_check:
                        t = *tbl;
                        if (t != 0) goto lbl_body;
                        dist = -1;
                    lbl_done:
                        ;
                    }
                    if (dist >= 0) {
                        foundSlot = slot;
                        foundDist = dist;
                        break;
                    }
                }
                slot++;
            }
            if ((s8)foundSlot >= 0 && bestDist > foundDist) {
                bestDist = foundDist;
                bestUnit = unit;
                bestSlot = foundSlot;
            }
        }
        i++;
    }
    if (bestDist != 0x7FFFFFFF) {
        s8 bx = *(u8 *)((u8 *)bestUnit + 0x19E);
        s8 by = *(u8 *)((u8 *)bestUnit + 0x19F);
        fn_8010F3F4(arg0, bx, by, &sp10, &sp12);
        *(u16 *)((u8 *)arg0 + 0x258) = *(u16 *)((u8 *)arg0 + 0x258) + 1;
        fn_800FB96C(0x11, (s8)sp10, (s8)sp12, bestUnit, bx, by, bestSlot, 0, 0);
    }
    return gAiState[0x21C];
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

void fn_8018D7A4(s32 arg0, s32 arg1) {
    void fn_8002C47C(void *, s32);
    void fn_8002F728(void *);
    extern u8 lbl_80284E20[];
    extern u8 lbl_80296078[];
    extern u8 gTargetList[];
    struct {
        void *vtbl;
        s32 unk4;
        s32 unk8;
    } obj;

    obj.vtbl = lbl_80284E20;
    obj.unk4 = arg0;
    obj.vtbl = lbl_80296078;
    obj.unk8 = arg1;
    fn_8002F728(gTargetList);
    fn_8002C47C(&obj, 0);
}

void fn_8018D7FC(void *arg0, void *arg1) {
    extern u8 gTargetList[];
    void fn_8002F6E8(void *, u8, u8, u8, s32);

    if (((u8 (**)(void *))arg0)[2](arg1) != 0) {
        fn_8002F6E8(gTargetList,
                    *(u8 *)((u8 *)arg0 + 0xC),
                    *(u8 *)((u8 *)arg0 + 0xD),
                    *(u8 *)((u8 *)arg1 + 0x198),
                    0);
    }
}

void fn_8018D864(void *arg0, s8 arg1, s8 arg2) {
    void fn_8002C6F4(void *);
    extern u8 gBattleMap[];
    u8 *base;
    s32 yoff;
    u8 *row;
    u8 id;

    base = gBattleMap;
    yoff = arg2 << 6;
    row = base + 0x10000;
    row += arg1;
    if ((s8)row[yoff - 0x1E72] == 0) {
        if ((*(u32 *)((u8 *)*(void **)((u8 *)arg0 + 4) + 0x254) & 0x20000) == 0 ||
            (*(base + arg1 + yoff + 0x300D) & 2) == 0) {
            *((u8 *)arg0 + 0xC) = arg1;
            *((u8 *)arg0 + 0xD) = arg2;
            id = *(base + arg1 + yoff + 0xD);
            if (id == 0 || id == *((u8 *)*(void **)((u8 *)arg0 + 4) + 0x198)) {
                fn_8002C6F4(arg0);
            }
        }
    }
}

#pragma optimization_level 4
#pragma inline auto
extern u8 lbl_80296088[160];
extern f64 lbl_8036AD88;
extern f32 lbl_8036AD68;
extern f32 lbl_8036AD6C;
extern f32 lbl_8036AD70;
extern f32 lbl_8036AD74;
extern f32 lbl_8036AD78;
extern f32 lbl_8036AD7C;
extern f32 lbl_8036AD80;
extern f32 lbl_8036AD84;
#pragma optimization_level 4
#pragma inline auto
void *Ui_GetColor(u8 arg0)
{
#pragma fp_contract on
  u32 OSGetTick(void);
  f64 sin(f64);
  u8 *color = lbl_80296088 + (arg0 * 4);
  f32 phase;
  f32 wave;
  u32 ticks;
  u32 millis;
  u32 mod;
  switch (arg0)
  {
    case 19:
    case 34:
      ticks = OSGetTick();
      millis = ticks / (((*((u32 *) 0x800000F8)) / 4) / 1000);
      mod = millis % 1500;
      wave = (f32)mod / lbl_8036AD68;
      phase = wave;
      wave = (f32) sin(lbl_8036AD6C * phase);
      wave = (lbl_8036AD78 * wave) + lbl_8036AD78;
      wave = lbl_8036AD74 * wave;
      color[0] = (u8) (lbl_8036AD70 + wave);
      color[1] = (u8) (lbl_8036AD7C + wave);
      color[2] = (u8) (lbl_8036AD70 + wave);
      break;

    case 20:
      ticks = OSGetTick();
      millis = ticks / (((*((u32 *) 0x800000F8)) / 4) / 1000);
      mod = millis % 1500;
      phase = (f32)mod / lbl_8036AD68;
      wave = (f32) sin(lbl_8036AD6C * phase);
      wave = (lbl_8036AD78 * wave) + lbl_8036AD78;
      wave = lbl_8036AD80 * wave;
      color[0] = (u8) (lbl_8036AD70 + wave);
      color[1] = (u8) (lbl_8036AD84 + wave);
      color[2] = (u8) (lbl_8036AD70 + wave);
      break;

  }

  return color;
}
void fn_8018DAD4(void) {
    void *Process_Find(M2C_UNK *);
    extern u16 lbl_80296128[];
    void *temp_r3;

    temp_r3 = Process_Find((M2C_UNK *) &lbl_80296128);
    if (temp_r3 != NULL) {
        *(u16 *)((char *)temp_r3 + 0x30) = *(u16 *)((char *)temp_r3 + 0x30) & 0xFFFFFFFD;
    }
}

void fn_8018DB10(void) {
    register unsigned int object;
    extern u8 lbl_80296128[];

    object = Process_Find(lbl_80296128);

    if (object != 0) {
        *(u16 *)((u8 *)object + 0x30) |= 2;
    }
}

void fn_8018DB4C(void) {
    void *Process_Find(M2C_UNK *);
    extern u16 lbl_80296128[20];
    void *temp_r3;

    temp_r3 = Process_Find((M2C_UNK *)lbl_80296128);
    if (temp_r3 != NULL) {
        M2C_FIELD(temp_r3, s16 *, 0x32) = 1;
        M2C_FIELD(temp_r3, s16 *, 0x44) = 0;
        M2C_FIELD(temp_r3, s16 *, 0x54) = 0;
    }
}

void fn_8018DB90(void) {
    void *Process_Find(M2C_UNK *);
    extern u16 lbl_80296128[20];
    void *temp_r3;

    temp_r3 = Process_Find((M2C_UNK *)lbl_80296128);
    if (temp_r3 != NULL) {
        M2C_FIELD(temp_r3, s16 *, 0x32) = 0;
        M2C_FIELD(temp_r3, s16 *, 0x44) = 8;
        M2C_FIELD(temp_r3, s16 *, 0x54) = 0xFF;
    }
}

void fn_8018DBD8(void)
{
    void *Process_Find(void *);
    extern u8 lbl_80296128[];

    u8 *entry;

    entry = (u8 *)Process_Find(lbl_80296128);

    if (entry != 0) {
        *(u16 *)(entry + 0x32) = 1;
        *(u16 *)(entry + 0x46) = 0;
    }
}

void fn_8018DC18(void) {
    void *Process_Find(M2C_UNK *);
    extern u16 lbl_80296128[30];
    void *temp_r3;
    M2C_UNK *temp_r4;

    temp_r4 = (M2C_UNK *)lbl_80296128;
    temp_r3 = Process_Find(temp_r4);
    if (temp_r3 != NULL) {
        M2C_FIELD(temp_r3, s16 *, 0x32) = 1;
        M2C_FIELD(temp_r3, s16 *, 0x46) = 0xE;
    }
}

void fn_8018DC58(void) {
    void *Process_Find(M2C_UNK *);
    extern u16 lbl_80296128[30];
    void *temp_r3;

    temp_r3 = Process_Find((M2C_UNK *)lbl_80296128);
    if (temp_r3 != NULL) {
        M2C_FIELD(temp_r3, s16 *, 0x32) = 0;
        M2C_FIELD(temp_r3, s16 *, 0x46) = 2;
    }
}

extern u8 lbl_80296128[16];
void fn_8018DC98(void) {
    Process_UnlinkByKey(&lbl_80296128);
}

void fn_8018DCC0(s32 arg0) {
    void *Process_Find(void *lbl);
    void Process_Create(void *lbl, s32 arg);
    extern u8 lbl_80296128[16];

    if (Process_Find(lbl_80296128) == 0) {
        Process_Create(lbl_80296128, arg0);
    }
}

#pragma global_optimizer off
void fn_8018DD0C(void *arg0) {
void FileCache_ReleaseSlot(void *);
if (*(u32 *)((u8 *)arg0 + 0x34) != 0U) {
FileCache_ReleaseSlot((u8 *)arg0 + 0x34);
}
}
#pragma global_optimizer off
void fn_8018DD3C(void *arg0) {
    u16 FileCache_GetFlags(char *);
    void fn_8006EEFC(void *, void *);
    void Process_ClearFunc(void *);
    void Process_AttachFunc(void *, void *);
    void fn_8018DE24(void *);
    extern u8 lbl_80279B1C[];

    if (FileCache_GetFlags((char *)lbl_80279B1C + 0x105) & 0x2000) {
        fn_8006EEFC((char *)arg0 + 0x34, (char *)lbl_80279B1C + 0x105);
        Process_ClearFunc(arg0);
        Process_AttachFunc(fn_8018DE24, arg0);
    }
}
#pragma global_optimizer on
void fn_8018DDA8(void *arg0) {
    void fn_8005C8B4(void *);
    extern u8 lbl_80279B1C[];
    extern f32 lbl_8036AD98;
    extern f32 lbl_8036AD9C;
    f32 fb;
    f32 fa;
    u16 z;
    u16 lim;

    z = 0;
    fa = 630.0f;
    fb = 324.0f;
    *(u16 *)((u8 *)arg0 + 0x30) = z;
    *(u16 *)((u8 *)arg0 + 0x32) = 1;
    lim = (u16)(0x10000 - 1);
    *(s32 *)((u8 *)arg0 + 0x34) = z;
    *(f32 *)((u8 *)arg0 + 0x38) = fa;
    *(f32 *)((u8 *)arg0 + 0x3c) = fb;
    *(u16 *)((u8 *)arg0 + 0x44) = z;
    *(u16 *)((u8 *)arg0 + 0x46) = z;
    *(u16 *)((u8 *)arg0 + 0x54) = z;
    *(u16 *)((u8 *)arg0 + 0x48) = lim;
    *(u16 *)((u8 *)arg0 + 0x4a) = lim;
    *(u16 *)((u8 *)arg0 + 0x4c) = lim;
    *(u16 *)((u8 *)arg0 + 0x4e) = lim;
    *(u16 *)((u8 *)arg0 + 0x50) = lim;
    *(u16 *)((u8 *)arg0 + 0x52) = lim;
    fn_8005C8B4(lbl_80279B1C + 0x105);
}

static inline void Ui_DrawStatusPanelTextureAt(u8 *self, u16 index, f32 x, f32 y, f32 depth, u32 color, s32 alpha)
{
    void **fn_8006EDD8(s32, s32);
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void fn_80009EB0(s32, s32, s32, s32);
    void Prim2D_BindTexture(s32, s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPrimParam(f32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetColor(u8, u8, u8, s32);
    void Prim2D_EmitQuad(void);
    void Prim2D_EndPrim(void);
    extern f32 lbl_8036ADA0, lbl_8036ADA4;
    void **p;
    u16 h, w;
    u8 *rgb = (u8 *)&color;
    if (index != 0xFFFF) {
        p = fn_8006EDD8(*(s32 *)(self + 0x34), index);
        h = *(u16 *)((u8 *)*p + 2);
        w = *(u16 *)*p;
        Prim2D_Begin();
        Prim2D_SetTransform(lbl_8036ADA0, lbl_8036ADA0, depth, lbl_8036ADA4);
        if (p[1]) fn_80009EB0(*(s32 *)(self + 0x34), index, 0, 0x11);
        else Prim2D_BindTexture(*(s32 *)(self + 0x34), index, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetPrimParam(lbl_8036ADA0);
        Prim2D_SetQuadMin(x, y, lbl_8036ADA0, lbl_8036ADA0);
        Prim2D_SetQuadMax(x + (f32)h, y + (f32)w, (f32)h, (f32)w);
        Prim2D_SetColor(rgb[0], rgb[1], rgb[2], alpha);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
    }
}

#pragma cplusplus on
#pragma opt_common_subs off
#pragma opt_loop_invariants off
extern "C" void fn_8018DE24(void *arg0) {
    void *memcpy(void *, const void *, u32);
    char *strcat(char *, const char *);
    void *Process_Find(void *);
    void *Msg_Expand(void *);
    s16 Text_MeasureWidth(void *, s32, f32);
    void fn_8001003C(s16, s16, s32, s32, s32, void *, ...);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_SetCornerColors(void *, void *, void *, void *);
    void Prim2D_SetRect(f32, f32, f32, f32);
    extern u8 lbl_80286860[], lbl_80279B1C[];
    extern u32 lbl_8036AD94, lbl_8036AD90, lbl_8036C4FC, lbl_8036C4F8;
    extern const f32 lbl_8036ADA8, lbl_8036ADD0, lbl_8036ADD4, lbl_8036ADD8, lbl_8036ADDC, lbl_8036ADE0, lbl_8036ADE4;
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetColor(u8, u8, u8, s32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetPrimParam(f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void fn_80009EB0(s32, s32, s32, s32);
    void Prim2D_BindTexture(s32, s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void **fn_8006EDD8(s32, s32);
    s32 *Ui_GetColor(s32);
    extern u8 lbl_80279900[];
    extern u8 gBattleState[];
    extern const f32 lbl_8036AD98;
    extern const f32 lbl_8036AD9C;
    extern const f32 lbl_8036ADA0;
    extern const f32 lbl_8036ADA4;
    extern const f32 lbl_8036ADB8;
    extern const f32 lbl_8036ADBC;
    extern const f32 lbl_8036ADC0;
    extern const f32 lbl_8036ADC4;
    extern const f32 lbl_8036ADC8;
    extern const f32 lbl_8036ADCC;
    extern f64 lbl_8036ADE8;

    u8 *ro = lbl_80279900;
    u8 *base = gBattleState;
    u32 mode;
    s32 t;
    u32 selected = base[0x51D];
    s32 i;
    struct PanelTable {u16 icons[19][6];} buf;
    u16 *row;
    u8 col[4];
    void **p;
    void *tex;
    u16 h, w;
    f32 fx, fy;

    if (((((u32)base[0x9D] >> 2) & 3) != 2)) {
        t = *(s16 *)(((u8 *)arg0) + 0x46);
        if (t <= 0) {
            switch (*(s16 *)(((u8 *)arg0) + 0x32)) {
            case 0:
                *(s16 *)(((u8 *)arg0) + 0x44) = (s16)(*(s16 *)(((u8 *)arg0) + 0x44) + 1);
                if (*(s16 *)(((u8 *)arg0) + 0x44) > 8) {
                    *(s16 *)(((u8 *)arg0) + 0x44) = 8;
                }
                break;
            case 1:
                *(s16 *)(((u8 *)arg0) + 0x44) = (s16)(*(s16 *)(((u8 *)arg0) + 0x44) - 1);
                if (*(s16 *)(((u8 *)arg0) + 0x44) < 0) {
                    *(s16 *)(((u8 *)arg0) + 0x44) = 0;
                }
                break;
            }
        } else {
            *(s16 *)(((u8 *)arg0) + 0x46) = (s16)(t - 1);
        }
        *(f32 *)(((u8 *)arg0) + 0x38) = Math_Ease(4, lbl_8036AD98, lbl_8036ADB8, (f32)*(s16 *)(((u8 *)arg0) + 0x44), lbl_8036ADBC);
        *(f32 *)(((u8 *)arg0) + 0x3C) = lbl_8036AD9C;
        if (*(u16 *)(((u8 *)arg0) + 0x30) & 1) {
            *(u16 *)(((u8 *)arg0) + 0x30) = (u16)(*(u16 *)(((u8 *)arg0) + 0x30) & 0xFFFE);
            *(f32 *)(((u8 *)arg0) + 0x38) = (f32)*(s16 *)(((u8 *)arg0) + 0x40);
            *(f32 *)(((u8 *)arg0) + 0x3C) = (f32)*(s16 *)(((u8 *)arg0) + 0x42);
        }
        buf = *(struct PanelTable *)(ro + 0xC);
        row = buf.icons[selected];
        *(u16 *)(((u8 *)arg0) + 0x48) = row[0];
        *(u16 *)(((u8 *)arg0) + 0x4A) = row[1];
        *(u16 *)(((u8 *)arg0) + 0x4C) = row[2];
        *(u16 *)(((u8 *)arg0) + 0x4E) = row[3];
        *(u16 *)(((u8 *)arg0) + 0x50) = row[4];
        *(u16 *)(((u8 *)arg0) + 0x52) = row[5];
        Prim2D_Begin();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
        mode = (base[0x9D] >> 2) & 3;
        if (mode == 0) {
            u32 color;
            {
                f32 firstY = *(f32 *)(((u8 *)arg0) + 0x3C);
                f32 firstX = *(f32 *)(((u8 *)arg0) + 0x38);
                color = *Ui_GetColor(2);
                Ui_DrawStatusPanelTextureAt(((u8 *)arg0), 0, firstX, firstY, lbl_8036ADC0, color, 0xFF);
            }
            fy = lbl_8036ADC4 + *(f32 *)(((u8 *)arg0) + 0x3C);
            fx = lbl_8036ADC8 + *(f32 *)(((u8 *)arg0) + 0x38);
            color = *Ui_GetColor(1);
            Ui_DrawStatusPanelTextureAt(((u8 *)arg0), 1, fx, fy, lbl_8036ADCC, color, 0x1A);
            {
                struct Depths { f32 v[6]; } depths = *(struct Depths *)(ro+0xF0);
                struct Positions { f32 v[12]; } positions = *(struct Positions *)(ro+0x108);
                struct Positions offsets, initial = *(struct Positions *)(ro+0x168);
                memcpy(&offsets, &initial, sizeof(offsets));
                for (i=0; i<6; i++) {
                    f32 depth;
                    u16 icon;
                    depth = depths.v[i];
                    fy = *(f32 *)(((u8 *)arg0)+0x3C)+positions.v[i*2+1];
                    fx = *(f32 *)(((u8 *)arg0)+0x38)+positions.v[i*2];
                    color = *Ui_GetColor(1);
                    Ui_DrawStatusPanelTextureAt(((u8 *)arg0), (u16)(i+2), fx, fy, depth, color, 0xFF);
                    {
                    f32 iconX, iconY;
                    icon = *(u16 *)(((u8 *)arg0)+0x48+i*2);
                    iconY = *(f32 *)(((u8 *)arg0)+0x3C)+offsets.v[i*2+1];
                    iconX = *(f32 *)(((u8 *)arg0)+0x38)+offsets.v[i*2];
                    if (icon != 0xFFFF) {
                        p = fn_8006EDD8(*(s32 *)(((u8 *)arg0)+0x34),icon);
                        iconX -= lbl_8036ADA8 * *(u16 *)((u8 *)*p+2);
                        color = *Ui_GetColor(1);
                        Ui_DrawStatusPanelTextureAt(((u8 *)arg0),icon,iconX,iconY,lbl_8036ADD0,color,0xFF);
                    }
                    }
                }
            }
        } else {
            if (*(s16 *)(((u8 *)arg0)+0x46)<=0) {
                if (*(s16 *)(((u8 *)arg0)+0x44)!=0 || Process_Find(lbl_80286860)!=0 || (*(u16 *)(((u8 *)arg0)+0x30)&2)) {
                    *(s16 *)(((u8 *)arg0)+0x54)+=25;
                    if (*(s16 *)(((u8 *)arg0)+0x54)>255) *(s16 *)(((u8 *)arg0)+0x54)=255;
                } else {
                    *(s16 *)(((u8 *)arg0)+0x54)-=25;
                    if (*(s16 *)(((u8 *)arg0)+0x54)<0) *(s16 *)(((u8 *)arg0)+0x54)=0;
                }
            }
            if (*(s16 *)(((u8 *)arg0)+0x54)>0) {
                u32 c0,c1,c2,c3;
                char textBuffer[100];
                Prim2D_Begin();
                Prim2D_SetTransform(lbl_8036ADA0,lbl_8036ADA0,lbl_8036ADC0,lbl_8036ADA4);
                Prim2D_SetTex(0,0x12);
                Prim2D_SetColorByte((u8)*(s16 *)(((u8 *)arg0)+0x54));
                Prim2D_PrepareTex();
                Prim2D_AddPrim(3);
                Prim2D_SetQuadMin(lbl_8036ADA0,lbl_8036ADD4,lbl_8036ADA0,lbl_8036ADA0);
                Prim2D_SetQuadMax(lbl_8036ADD8,lbl_8036ADDC,lbl_8036ADA0,lbl_8036ADA0);
                c3=lbl_8036AD94; c2=lbl_8036AD90; c1=lbl_8036C4FC; c0=lbl_8036C4F8;
                Prim2D_SetCornerColors(&c0,&c1,&c2,&c3);
                Prim2D_EmitQuad();
                Prim2D_EndPrim();
                Prim2D_AddPrim(1);
                Prim2D_SetRect(lbl_8036ADA0,lbl_8036ADDC,lbl_8036ADD8,lbl_8036ADE0);
                Prim2D_SetColor(0,0,0,0xFF);
                Prim2D_EndPrim();
                Prim2D_Begin();
                Prim2D_SetTransform(lbl_8036ADA0,lbl_8036ADA0,lbl_8036ADE4,lbl_8036ADA4);
                Prim2D_SetTex(0,0x13);
                Prim2D_PrepareTex();
                {
                    struct Prefixes {char *v[6];} prefix = *(struct Prefixes *)(ro+0x1C8);
                    struct Names {void *v[15];} names = *(struct Names *)(ro+0x1E0);
                    textBuffer[0]=0;
                    for(i=0;i<6;i++,row++) {
                        if (*(u16 *)(((u8 *)arg0)+0x48+i*2)!=0xFFFF) {
                            strcat(textBuffer,prefix.v[i]);
                            if (i==4) strcat(textBuffer,(char *)lbl_80279B1C+0x119);
                            strcat(textBuffer,(char *)Msg_Expand(names.v[*row-8]));
                        }
                    }
                }
                {
                    s16 width=Text_MeasureWidth(textBuffer,-1,lbl_8036ADA4);
                    fn_8001003C((s16)(0x130-width/2),0x197,1,1,0,textBuffer,lbl_8036ADA4,lbl_8036ADA0);
                }
                Prim2D_Begin();
                Prim2D_SetColorByte(0xFF);
                Prim2D_PrepareTex();
            }
        }
    }
}
#pragma opt_common_subs reset
#pragma opt_loop_invariants reset
extern "C" void fn_8018E98C(void *arg0, s32 arg1) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual void v13() = 0;
        virtual void v14(s32) = 0;
    };
    ((Obj *)arg0)->v13();
    ((Obj *)arg0)->v14(arg1);
}

extern "C" void fn_8018E9E8(void *arg0) {
#pragma cplusplus on
struct Obj {
virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void prepare()=0;
virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0; virtual void v8()=0;
virtual void row0(s16)=0; virtual void row1(s16)=0; virtual void row2(s16,s32)=0; virtual void row3(s16)=0;
};
extern f32 lbl_8036ADF0, lbl_8036ADF4;
s32 Text_MeasureHeight(s32,f32);
void Prim2D_Begin(void);
void Prim2D_AddZ(f32);
void Prim2D_SetTex(s32,u16);
void Prim2D_PrepareTex(void);
s16 y;
Obj *self=(Obj *)arg0;
self->prepare();
y=*(s16 *)((u8 *)self+0x46);
y=(s16)(((0x1c-Text_MeasureHeight(-1,lbl_8036ADF0))+(s32)y)>>1);
Prim2D_Begin(); Prim2D_AddZ(lbl_8036ADF4);
Prim2D_SetTex(0,(u16)(*(u32 *)((u8 *)self+0x34)|0x13)); Prim2D_PrepareTex();
switch(*(s32 *)((u8 *)self+0x3c)) {
case 0: case 2: self->row0(y);break;
case 1:self->row1(y);break;
}
Prim2D_Begin();
Prim2D_SetTex(0,(u16)(*(u32 *)((u8 *)self+0x34)|0x13)); Prim2D_PrepareTex();
switch(*(s32 *)((u8 *)self+0x3c)) {
case 0: case 2:self->row1(y+0x1c);break;
case 1:self->row3(y+0x1c);break;
}
Prim2D_Begin();
Prim2D_SetTex(0,(u16)(*(u32 *)((u8 *)self+0x34)|0x13)); Prim2D_PrepareTex();
switch(*(s32 *)((u8 *)self+0x3c)) {
case 0: case 1:self->row2(y+0x38,1);break;
case 2:self->row2(y+0x38,0);break;
}
#pragma cplusplus reset
}

#pragma cplusplus reset
void fn_8018EBC0(void *arg0, s32 arg1) {
    void fn_8001C76C(void *);
    s32 UnitRef_GetName(void *);
    void UnitRef_Set(void *, s32);
    void Item_Destroy(void *, s32);
    s32 Text_MeasureHeight(s32, f32);
    void Text_Draw(s16, s16, s32, ...);
    void fn_8008CFB4(void *, s32, s32);
    extern u8 lbl_80279C40[];
    extern f32 lbl_8036ADF0;
    u8 sp8[8];
    register u16 y;
    register s32 y2;
    register s16 half;
    register s32 x;
    s32 w;
    fn_8001C76C(sp8);
    UnitRef_Set(sp8, *(s32 *)((u8 *)arg0 + 0x40));
    y = *(s16 *)((u8 *)arg0 + 0x44);
    half = (s16)((0x1C - Text_MeasureHeight(-1, lbl_8036ADF0)) >> 1);
    w = UnitRef_GetName(sp8);
    y2 = (s16)y;
    x = (s16)arg1 + half;
    Text_Draw((s16)(y2 + 0x18), (s16)x, 2, lbl_80279C40 + 0x50, w);
    fn_8008CFB4(sp8, y2, x);
    Item_Destroy(sp8, -1);
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
void fn_8018EC8C(void *arg0, s16 arg1, u8 arg2) {
    s32 Text_MeasureHeight(s32, f32);
    void *Msg_Expand(void *);
    void Text_Draw(s16, s16, s32, ...);
    void Prim2D_AddPrim(s32);
    s32 *Ui_GetColor(s32);
    void Prim2D_SetColorPacked(s32 *);
    void fn_80006B18(s32, s32, s32, s32, s32);
    void Prim2D_EndPrim(void);
    extern u8 lbl_80279C40[];
    extern const f32 lbl_8036ADF0;
    typedef struct Entry {
        void *ptr;
        u8 unk4;
        u8 flags;
        u8 pad[2];
    } Entry;
    extern Entry gConvoy[];
    s32 spC;
    s32 sp8;
    s32 dummy;
    Entry *e;
    s32 ctr;
    s32 count;
    void *target;
    void *str;
    void *p0;
    s16 y;
    s32 x;
    s32 k;

    y = M2C_FIELD(arg0, s16 *, 0x44);
    x = (s16)((0x1C - Text_MeasureHeight(-1, lbl_8036ADF0)) >> 1);
    str = Msg_Expand(lbl_80279C40 + 0x53);
    x += arg1;
    Text_Draw(y, (s16)x, 0xF, str);
    if (arg2 != 0 && M2C_FIELD(arg0, void **, 0x40) != NULL) {
        Prim2D_AddPrim(6);
        spC = *Ui_GetColor(2);
        Prim2D_SetColorPacked(&spC);
        target = M2C_FIELD(arg0, void **, 0x40);
        count = 0;
        if (target != NULL) {
            e = gConvoy;
            dummy = count;
            for (ctr = 0x28; ctr != 0; ctr--) {
                for (k = 0; k < 5; k++) {
                    p0 = e->ptr;
                    if (p0 != NULL && (e->flags & 0x3F) == 0 && p0 == target) {
                        count++;
                    }
                    e++;
                }
                dummy += 4;
            }
        }
        fn_80006B18(y + 0xA4, x, 0, 0, count);
        Prim2D_EndPrim();
    } else {
        Prim2D_AddPrim(6);
        sp8 = *Ui_GetColor(2);
        Prim2D_SetColorPacked(&sp8);
        fn_80006B18(y + 0xA4, x, 0, 0, 0);
        Prim2D_EndPrim();
    }
    str = Msg_Expand(lbl_80279C40 + 0x66);
    Text_Draw((s16)(y + 0xB0), (s16)x, 0xF, str);
}
void fn_8018EEB0(void *arg0, s16 arg1) {
    s32 Text_MeasureHeight(s32,f32);
    void *Msg_Expand(void *);
    void Text_Draw(s16,s16,s32,void *,...);
    s32 fn_800C3E54(void *);
    void Ui_DrawLine(s16,s16,s16,s16,s32,void *);
    extern u8 lbl_80279C40[];
    extern u8 gConvoy[];
    s16 width;
    s16 height;
    s32 x;
    s32 y;
    u8 color[4];
    width=M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12);
    x=M2C_FIELD(arg0,s16 *,0x44);
    height=Text_MeasureHeight(-1,1.0f);
    y=(s16)((0x1C-height)>>1);
    {
        void *str=Msg_Expand(lbl_80279C40+0x78);
        y=arg1+y;
        Text_Draw(x,y,0xF,str);
    }
    Text_Draw((s16)((s16)x+0x58),y,1,lbl_80279C40+0x8F,fn_800C3E54(gConvoy),0xC8);
    Text_Draw((s16)((s16)x+0xB0),y,0xF,Msg_Expand(lbl_80279C40+0x66));
    color[0]=0x70; color[1]=0x5F; color[2]=0x1F; color[3]=0x7F;
    Ui_DrawLine(0,(s16)(arg1+height),width,(s16)(arg1+height),0x10,color);
}

#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset

void fn_8018EFE0(void *arg0, s16 arg1) {
    void *Msg_Expand(void *);
    void Text_Draw(s16, s16, s32, ...);
    s32 Text_MeasureHeight(s32, f32);
    s16 Text_MeasureWidth(void *, s32, f32);
    extern u8 lbl_80279C40[];
    extern f32 lbl_8036ADF0;
    void *str;
    s16 y;
    s16 h;
    s16 t;

    str = Msg_Expand(lbl_80279C40 + 0xA0);
    h = Text_MeasureWidth(str, -1, lbl_8036ADF0);
    t = *(s16 *)((u8 *)arg0 + 0x12);
    y = (s16)(((s16)(*(s16 *)((u8 *)arg0 + 0x16) - t) - h) >> 1);
    Text_Draw(y, (s16)(arg1 + (s16)((0x1C - Text_MeasureHeight(-1, lbl_8036ADF0)) >> 1)), 2, str);
}

#pragma cplusplus on
extern "C" void fn_8018F090(void *arg0) {
    void fn_80152A18(s32, s32, s32);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    ((Obj *)arg0)->v2();
    fn_80152A18(0, 0, 0x10);
}

#pragma cplusplus on
extern "C" void fn_8018F0CC(void *arg0, s32 arg1) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3(void *) = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
    };
    s32 Text_MeasureHeight(s32, f32);
    s32 fn_80104E58(s16, s16, s16);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(s32, u16);
    void Prim2D_PrepareTex(void);
    void *fn_80105710(void *);
    void Item_Init(void *);
    void UnitRef_Set(void *, s32);
    void fn_8001ED58(s32);
    void *UnitRef_GetName(void *);
    void Text_Draw(s16, s16, s32, ...);
    void fn_8008CFB4(void *, s16, s16);
    void Item_Destroy(void *, s32);
    void *Msg_Expand(void *);
    s32 fn_8018F374(void *);
    void Prim2D_AddPrim(s32);
    s32 *Ui_GetColor(s32);
    void Prim2D_SetColorPacked(s32 *);
    void fn_80006B18(s32, s16, s32, s32, s32);
    void Prim2D_EndPrim(void);
    extern u8 lbl_80279C40[];
    extern f32 lbl_8036ADF0;
    extern f32 lbl_8036ADF4;
    u8 sp10[8];
    s32 x, y, w;
    s16 a, b, d, tmp;
    s32 item;
    void *str;
    s16 cnt;

    ((Obj *)arg0)->v9();
    ((Obj *)arg0)->v3((void *)arg1);

    x = (s16)((0x20 - Text_MeasureHeight(-1, lbl_8036ADF0)) >> 1);
    a = *(s16 *)((u8 *)arg0 + 0x12);
    b = *(s16 *)((u8 *)arg0 + 0x16);
    y = *(s16 *)((u8 *)arg0 + 0x40);
    tmp = y;
    d = *(s16 *)((u8 *)arg0 + 0x42);
    w = (s16)(b - a) - tmp;
    x = x + d;
    w = (s16)(w - (fn_80104E58(w, a, tmp) + 8));

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036ADF4);
    Prim2D_SetTex(0, (u16)(*(u32 *)((u8 *)arg0 + 0x34) | 0x13));
    Prim2D_PrepareTex();
    item = (s32)fn_80105710(*(void **)((u8 *)arg0 + 0x3C));
    if (item != 0) {
        Item_Init(sp10);
        UnitRef_Set(sp10, item);
        fn_8001ED58(item);
        str = UnitRef_GetName(sp10);
        Text_Draw((s16)(y + 0x18), (s16)x, 2, str);
        fn_8008CFB4(sp10, (s16)y, (s16)x);
        Prim2D_Begin();
        Prim2D_SetTex(0, (u16)(*(u32 *)((u8 *)arg0 + 0x34) | 0x13));
        Prim2D_PrepareTex();
        Item_Destroy(sp10, -1);
    } else {
        Text_Draw((s16)y, (s16)x, 0, lbl_80279C40 + 0xA9);
        str = Msg_Expand(lbl_80279C40 + 0x53);
        Text_Draw((s16)y, (s16)(x + 0x20), 0xF, str);
        str = Msg_Expand(lbl_80279C40 + 0x66);
        Text_Draw((s16)(w + 8), (s16)(x + 0x20), 0xF, str);
    }
    cnt = fn_8018F374(arg0);
    if (cnt >= 0) {
        s32 color;
        Prim2D_AddPrim(6);
        color = *Ui_GetColor(2);
        Prim2D_SetColorPacked(&color);
        fn_80006B18(w, (s16)(x + 0x20), 0, 0, cnt);
        Prim2D_EndPrim();
    } else {
        s32 color;
        Prim2D_AddPrim(6);
        color = *Ui_GetColor(2);
        Prim2D_SetColorPacked(&color);
        fn_80006B18(w, (s16)(x + 0x20), 0, 0, 0);
        Prim2D_EndPrim();
    }
}
#pragma cplusplus reset

extern "C" void fn_8018F338(void *arg0) {
    void fn_80154004(s32, s32, s32);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    ((Obj *)arg0)->v2();
    fn_80154004(0, 0, 0x10);
}

#pragma use_lmw_stmw on
#pragma cplusplus on
extern "C" s32 fn_8018F374(void *arg0) {
    void *fn_80105710(void *);
    extern u32 lbl_802CA264[];
    typedef struct Entry {
        void *ptr;
        u8 unk4;
        u8 flags;
        u8 pad[2];
    } Entry;
    extern Entry lbl_803200AC[];
    Entry *e;
    void *p0;
    s32 i;
    u8 *next;
    s32 total;
    u8 *unit;
    void *target;
    void *tmp;

    tmp = *(void **)((u8 *)arg0 + 0x3C);
    total = 0;
    if (tmp == NULL) {
        return -1;
    }
    if (fn_80105710(tmp) == NULL) {
        return -1;
    }
    target = fn_80105710(*(void **)((u8 *)arg0 + 0x3C));
    unit = *(u8 **)((u8 *)lbl_802CA264 + 0);
    goto loop1_test;
loop1_body:
    next = *(u8 **)(unit + 0x184);
    total += CountUnitItemReferences(unit, (u8 *)target);
    unit = next;
loop1_test:
    if (unit != NULL) {
        goto loop1_body;
    }
    unit = *(u8 **)((u8 *)lbl_802CA264 + 0x3C);
    goto loop2_test;
loop2_body:
    next = *(u8 **)(unit + 0x184);
    total += CountUnitItemReferences(unit, (u8 *)target);
    unit = next;
loop2_test:
    if (unit != NULL) {
        goto loop2_body;
    }
    e = lbl_803200AC;
    for (i = 0; i < 200; i++) {
        p0 = e->ptr;
        if (p0 != NULL && (e->flags & 0x3F) == 0 && target == p0) {
            total++;
        }
        e++;
    }
    return total;
}
#pragma cplusplus reset
#pragma use_lmw_stmw reset

extern "C" void fn_8018F6E8(void *arg0, s32 arg1) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3(s32) = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
    };
    void fn_80006B18(s16, s16, s32, s32, s32);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(s32, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void *Msg_Expand(void *);
    void Text_Draw(s16, s16, s32, void *, ...);
    s32 Text_MeasureHeight(s32, f32);
    s16 Text_MeasureWidth(void *, s32, f32);
    s32 fn_80104E58(void);
    s32 *Ui_GetColor(s32);
    extern u8 lbl_80279C40[];
    extern u8 gBattleState[];
    extern f32 lbl_8036ADF0;
    extern f32 lbl_8036ADF4;
    s32 spC;
    s32 sp8;
    s16 y;
    s32 y2;
    s16 h;
    s16 x;
    s16 a;
    s16 b;
    s32 t;

    ((Obj *)arg0)->v9();
    ((Obj *)arg0)->v3(arg1);

    x = (s16)((0x20 - Text_MeasureHeight(-1, lbl_8036ADF0)) >> 1);
    t = *(s16 *)((u8 *)arg0 + 0x40);
    a = *(s16 *)((u8 *)arg0 + 0x16);
    b = *(s16 *)((u8 *)arg0 + 0x12);
    y = (s16)(a - b);
    h = t;
    y = (s16)(y - t);
    x += *(s16 *)((u8 *)arg0 + 0x42);
    y -= fn_80104E58() + 8;

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036ADF4);
    Prim2D_SetTex(0, (u16)(*(u32 *)((u8 *)arg0 + 0x34) | 0x13));
    Prim2D_PrepareTex();

    Text_Draw(h, x, 0xF, Msg_Expand(lbl_80279C40 + 0xBE));
    Text_Draw(y + 8, x, 0xF, Msg_Expand(lbl_80279C40 + 0xD1));
    y2 = y + 8;

    if (*(s32 *)((u8 *)arg0 + 0x3C) >= 0) {
        arg1 = 0;
        if (*(s32 *)((u8 *)arg0 + 0x3C) <= *(s32 *)(gBattleState + 0x18)) {
            arg1 = 2;
        }
        Prim2D_AddPrim(6);
        spC = *Ui_GetColor((u8)arg1);
        Prim2D_SetColorPacked(&spC);
        fn_80006B18(y, (s16)x, 0, 0, *(s32 *)((u8 *)arg0 + 0x3C));
        Prim2D_EndPrim();
    } else {
        arg1 = (s32)(lbl_80279C40 + 0xE4);
        Text_Draw((s16)(y - (s16)Text_MeasureWidth((void *)arg1, -1, lbl_8036ADF0)), x, 0, (void *)arg1);
        Text_Draw(h, (s16)((arg1 = (s16)x) + 0x20), 0xF, Msg_Expand(lbl_80279C40 + 0xED));
        Text_Draw(y2, (s16)(arg1 + 0x20), 0xF, Msg_Expand((u8 *)lbl_80279C40 + 209));
        Prim2D_AddPrim(6);
        sp8 = *Ui_GetColor(2);
        Prim2D_SetColorPacked(&sp8);
        fn_80006B18(y, (s16)(arg1 + 0x20), 0, 0, *(s32 *)(gBattleState + 0x18));
        Prim2D_EndPrim();
    }
}

extern "C" void fn_8018F94C(void *arg0) {
    void fn_80154004(s32, s32, s32);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    ((Obj *)arg0)->v2();
    fn_80154004(0, 0, 0x10);
}

#pragma cplusplus on
extern "C" void fn_8018F988(void *arg0, s32 arg1) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10(s32) = 0;
    };
    ((Obj *)arg0)->v9();
    ((Obj *)arg0)->v10(arg1);
}

#pragma use_lmw_stmw on
#pragma cplusplus on
extern "C" void fn_8018F9E4(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
    };
    s32 Text_MeasureHeight(s32, f32);
    void *Msg_Expand(void *);
    void Text_Draw(s16, s16, s32, ...);
    s32 fn_80104E58(s16, s16, s16);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(s32, u16);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    s32 *Ui_GetColor(s32);
    void Prim2D_SetColorPacked(s32 *);
    void fn_80006B18(s16, s16, s32, s32, s32);
    void Prim2D_EndPrim(void);
    s32 fn_8018FC58(void *);
    extern u8 lbl_80279C40[];
    extern u8 gBattleState[];
    extern f32 lbl_8036ADF0, lbl_8036ADF4;
    s32 sp10, spC, sp8;
    void *msg;
    s32 z;
    s16 y, x, w, a, b;

    ((Obj *)arg0)->v3();
    x = (s16)((0x20 - Text_MeasureHeight(-1, lbl_8036ADF0)) >> 1);
    a = *(s16 *)((u8 *)arg0 + 0x12);
    b = *(s16 *)((u8 *)arg0 + 0x16);
    y = *(s16 *)((u8 *)arg0 + 0x40);
    w = (s16)((b - a) - y);
    x += *(s16 *)((u8 *)arg0 + 0x42);
    w = (s16)(w - (fn_80104E58(w, a, y) + 8));
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036ADF4);
    Prim2D_SetTex(0, (u16)(*(s32 *)((u8 *)arg0 + 0x34) | 0x13));
    Prim2D_PrepareTex();
    Text_Draw(y, x, 0xF, Msg_Expand(lbl_80279C40 + 0xED));
    msg = Msg_Expand(lbl_80279C40 + 0xD1);
    z = w + 8;
    Text_Draw(z, x, 0xF, msg);
    Prim2D_AddPrim(6);
    sp10 = *Ui_GetColor(2);
    Prim2D_SetColorPacked(&sp10);
    fn_80006B18(w, x, 0, 0, *(s32 *)(gBattleState + 0x18));
    Prim2D_EndPrim();
    Text_Draw(y, (s16)(x + 0x20), 0xF, Msg_Expand(lbl_80279C40 + 0x53));
    Text_Draw(z, (s16)(x + 0x20), 0xF, Msg_Expand(lbl_80279C40 + 0x66));
    if (*(u32 *)((u8 *)arg0 + 0x3C) != 0) {
        Prim2D_AddPrim(6);
        spC = *Ui_GetColor(2);
        Prim2D_SetColorPacked(&spC);
        fn_80006B18(w, (s16)(x + 0x20), 0, 0, fn_8018FC58(arg0));
        Prim2D_EndPrim();
    } else {
        Prim2D_AddPrim(6);
        sp8 = *Ui_GetColor(2);
        Prim2D_SetColorPacked(&sp8);
        fn_80006B18(w, (s16)(x + 0x20), 0, 0, 0);
        Prim2D_EndPrim();
    }
}
#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset

extern "C" void fn_8018FC1C(void *arg0) {
    void fn_80154004(s32, s32, s32);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    ((Obj *)arg0)->v2();
    fn_80154004(0, 0, 0x10);
}

#pragma opt_common_subs off
#pragma use_lmw_stmw on
extern "C" s32 fn_8018FC58(void *arg0)
{
  void **fn_80037BBC(void *, s32);
  u8 *new_var;
  extern u32 lbl_802CA264[];
  extern u32 lbl_803200AC[];
  u8 *self = (u8 *) arg0;
  s32 total;
  {
    u8 *unit;
    u8 *target = *((u8 **) (self + 0x3C));
    u8 *next;
    s32 count;
    s32 i;
    u8 *entry;
    void *item;
    total = 0;
    if (target == 0)
    {
      return 0;
    }
    for (unit = *((u8 **) (((u8 *) lbl_802CA264) + 0)); unit; unit = next)
    {
      next = *((u8 **) (unit + 0x184));
      total += CountUnitItemReferences(unit, target);
    }

  }
  new_var = *((u8 **) (self + 0x3C));
  {
    u8 *target = new_var;
    u8 *unit;
    u8 *next;
    s32 count;
    s32 i;
    u8 *entry;
    void *item;
    for (unit = *((u8 **) (((u8 *) lbl_802CA264) + 60)); unit; unit = next)
    {
      next = *((u8 **) (unit + 0x184));
      total += CountUnitItemReferences(unit, target);
    }

  }
  {
    u8 *entry = (u8 *) lbl_803200AC;
    u8 *target = *((u8 **) (self + 0x3C));
    s32 i;
    for (i = 0; i < 200; i++, entry += 8)
    {
      void *item = *((void **) entry);
      if ((item && (!(entry[5] & 63))) && (target == item))
      {
        total++;
      }
    }

  }
  return total;
}
#pragma cplusplus reset
#pragma opt_common_subs reset

void *fn_8018FFB4(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_80296150[];
    extern void *lbl_80292230[];
    extern void *lbl_8028FDB0[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_80296150;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_80292230;
            if (arg0 != NULL) {
                *(void **)arg0 = lbl_8028FDB0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

#pragma global_optimizer off
void fn_80190020(void *arg0) {
    s16 height, width;
    s32 bottom, right;
    s16 *p = (s16 *)arg0;
    p[0x44/2] = 8;
    p[0x46/2] = 0;
    height = p[0x10/2] - p[0xC/2];
    width = p[0xE/2] - p[0xA/2];
    bottom = height - 0x14;
    right = width - 0x1C;
    p[0x12/2] = 0x1C;
    p[0x14/2] = 0x14;
    p[0x16/2] = right;
    p[0x18/2] = bottom;
}
#pragma global_optimizer reset
void *fn_80190074(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_80296194[];
    extern void *lbl_80292230[];
    extern void *lbl_8028FDB0[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_80296194;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_80292230;
            if (arg0 != NULL) {
                *(void **)arg0 = lbl_8028FDB0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void fn_801900E0(void *arg0) {
    s16 height, width;
    s32 bottom, right;
    s16 *p = (s16 *)arg0;
    p[0x40/2] = 0x18;
    p[0x42/2] = 0;
    height = p[0x10/2] - p[0xC/2];
    width = p[0xE/2] - p[0xA/2];
    bottom = height - 2;
    right = width - 2;
    p[0x12/2] = 2;
    p[0x14/2] = 2;
    p[0x16/2] = right;
    p[0x18/2] = bottom;
}

void *fn_80190130(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_802961C4[];
    extern void *lbl_80292230[];
    extern void *lbl_8028FDB0[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_802961C4;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_80292230;
            if (arg0 != NULL) {
                *(void **)arg0 = lbl_8028FDB0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void fn_8019019C(void *arg0) {
    s16 height, width;
    s32 bottom, right;
    s16 *p = (s16 *)arg0;
    p[0x40/2] = 0x18;
    p[0x42/2] = 0;
    height = p[0x10/2] - p[0xC/2];
    width = p[0xE/2] - p[0xA/2];
    bottom = height - 2;
    right = width - 2;
    p[0x12/2] = 2;
    p[0x14/2] = 2;
    p[0x16/2] = right;
    p[0x18/2] = bottom;
}

void *fn_801901EC(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_802961F4[];
    extern void *lbl_80292230[];
    extern void *lbl_8028FDB0[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_802961F4;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_80292230;
            if (arg0 != NULL) {
                *(void **)arg0 = lbl_8028FDB0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void fn_80190258(void *arg0) {
    s16 height, width;
    s32 bottom, right;
    s16 *p = (s16 *)arg0;
    p[0x40/2] = 0x18;
    p[0x42/2] = 0;
    height = p[0x10/2] - p[0xC/2];
    width = p[0xE/2] - p[0xA/2];
    bottom = height - 2;
    right = width - 2;
    p[0x12/2] = 2;
    p[0x14/2] = 2;
    p[0x16/2] = right;
    p[0x18/2] = bottom;
}

void fn_801902A8(void *arg0) {
    void fn_80202A6C(void *,f32,f32,f32,f32);
    void GXSetProjection(void *,s32);
    void fn_80225034(f32 *);
    void GXSetViewport(f32,f32,f32,f32,f32,f32);
    void fn_80069F04(void *);
    f32 projection[3][4];
    f32 viewport[6];
    s16 width;
    s16 height;
    s16 x;
    s16 y;
    s16 left=M2C_FIELD(arg0,s16 *,0x12);
    s16 top=M2C_FIELD(arg0,s16 *,0x14);
    width=M2C_FIELD(arg0,s16 *,0x16)-left;
    height=M2C_FIELD(arg0,s16 *,0x18)-top;
    x=M2C_FIELD(arg0,s16 *,0xA)+left;
    y=M2C_FIELD(arg0,s16 *,0xC)+top;
    fn_80202A6C(projection,30.0f,(f32)(width/height),1.0f,1000.0f);
    GXSetProjection(projection,0);
    fn_80225034(viewport);
    GXSetViewport((f32)x,(f32)y,(f32)width,(f32)height,viewport[4],viewport[5]);
    fn_80069F04(M2C_FIELD(arg0,void **,0x40));
    GXSetViewport(viewport[0],viewport[1],viewport[2],viewport[3],viewport[4],viewport[5]);
}

#pragma cplusplus on
extern "C" void fn_801903D8(void *arg0, s32 arg1) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10(s32) = 0;
    };
    if (*(u8 *)((u8 *)arg0 + 0x44) != 0) {
        ((Obj *)arg0)->v9();
    }
    ((Obj *)arg0)->v10(arg1);
}

#pragma cplusplus on
#pragma global_optimizer off
extern "C" void fn_80190440(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
    };
    void fn_8013F748(void *, void *, void *);
    void PSMTXScale(f32 *, f32, f32, f32);
    void fn_80202574(f32 *, void *, f32, f32, f32);
    void Model_SetColor(void *, u8, u8, u8);
    void Model_SetAlpha(void *, s32);
    s32 fn_80138908(void *);
    void fn_800609DC(void *);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(s32, u16);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetCallback(void (*)(void *), s16 *);
    void Prim2D_ScissorFromRect(void *);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void fn_80007340(void (*)(void *), void *);
    void Prim2D_EndPrim(void);
    void Prim2D_ClearCallbacks(void);
    void fn_801902A8(void *);
    extern f32 lbl_8036ADFC;
    extern f32 lbl_8036AE10;
    extern f32 lbl_8036AE14;
    f32 mtx[12];
    s16 t14;
    void *self;
    s16 t18;
    s16 t12;
    s16 t16;

    self = arg0;
    ((Obj *)self)->v3();
    if (*(u32 *)((u8 *)self + 0x3C) != 0) {
        t14 = *(s16 *)((u8 *)self + 0x14);
        t18 = *(s16 *)((u8 *)self + 0x18);
        register int t12 = *(s16 *)((u8 *)self + 0x12);
        t16 = *(s16 *)((u8 *)self + 0x16);
        *(s16 *)((u8 *)self + 0x4A) = 0;
        *(s16 *)((u8 *)self + 0x4C) = 0;
        *(s16 *)((u8 *)self + 0x4E) = (s16)(t16 - t12);
        *(s16 *)((u8 *)self + 0x50) = (s16)(t18 - t14);
        fn_8013F748(self, (u8 *)self + 0x4A, (u8 *)self + 0x4A);
        fn_8013F748(self, (u8 *)self + 0x4E, (u8 *)self + 0x4E);
        PSMTXScale(mtx, lbl_8036ADFC, lbl_8036ADFC, lbl_8036ADFC);
        fn_80202574(mtx, (u8 *)*(void **)((u8 *)self + 0x40) + 0x10, lbl_8036AE10, lbl_8036AE10, lbl_8036AE14);
        Model_SetColor(*(void **)((u8 *)self + 0x40), 0x80, 0x80, 0x80);
        Model_SetAlpha(*(void **)((u8 *)self + 0x40), fn_80138908(self));
        fn_800609DC(*(void **)((u8 *)self + 0x40));
        Prim2D_Begin();
        Prim2D_SetTex(0, (u16)(*(u32 *)((u8 *)self + 0x34) | 0x410));
        Prim2D_SetColorByte(fn_80138908(self));
        Prim2D_SetCallback(Prim2D_ScissorFromRect, (s16 *)((u8 *)self + 0x4A));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(0xB);
        fn_80007340(fn_801902A8, self);
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_ClearCallbacks();
        Prim2D_PrepareTex();
    }
}
#pragma global_optimizer on
#pragma cplusplus reset
extern "C" void fn_80190590(void *arg0) {
    void fn_80159898(s32, s32, s16, s16, s32, s32);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    ((Obj *)arg0)->v2();
    fn_80159898(0, 0,
        (s16)(*(s16 *)((u8 *)arg0 + 0xE) - *(s16 *)((u8 *)arg0 + 0xA)),
        (s16)(*(s16 *)((u8 *)arg0 + 0x10) - *(s16 *)((u8 *)arg0 + 0xC)),
        0xB3, 0x10);
}

/* Bind or clear the forge preview GActor for a weapon (xwp/forge/<name>_b.*). */
extern "C" void Forge_BindWeaponActor(void *panel, s32 **weapon) {
    M2C_UNK fn_8005C7E8(s32);
    u32 FileCache_Load();
    M2C_UNK GActor_LoadTpl(s32 *, s32);
    M2C_UNK GActor_LoadG(s32 *, s32);
    M2C_UNK GActor_LoadGs(s32 *, s32);
    M2C_UNK GActor_Finalize(s32 *);
    M2C_UNK fn_800616A0(s32 *);
    s32 *GActor_Create();
    M2C_UNK fn_8008CDE0(s32 *, s32 **);
    s32 String_CStr(M2C_UNK *);
    M2C_UNK fn_800C992C(M2C_UNK *, s32, s32);
    M2C_UNK String_Destroy(M2C_UNK *, M2C_UNK);
    M2C_UNK String_Init(M2C_UNK *, M2C_UNK *, M2C_UNK *);
    M2C_UNK String_ConcatCStr(M2C_UNK *, M2C_UNK *, void *);
    s32 sprintf(void *, void *, ...);
    s32 strlen(s32);
    extern u8 gForgeActorStrings[];
    struct { s32 v[15]; } pathBuf;
    struct { s32 v[3]; } basePath;
    struct { s32 v[3]; } cmpPath;
    struct { s32 v[3]; } gPath;
    struct { s32 v[3]; } gsPath;
    struct { s32 v[3]; } tplPath;
    s32 scratch;
    s32 name;
    if (weapon == NULL) {
        M2C_FIELD(panel, s32 ***, 0x3C) = weapon;
        if (M2C_FIELD(panel, s32 **, 0x40) != 0) {
            fn_800616A0(M2C_FIELD(panel, s32 **, 0x40));
            M2C_FIELD(panel, s32 **, 0x40) = 0;
        }
        if (M2C_FIELD(panel, u32 *, 0x54) != 0U) {
            fn_8005C7E8(M2C_FIELD(panel, s32 *, 0x54));
            M2C_FIELD(panel, u32 *, 0x54) = 0U;
        }
    } else {
        if ((M2C_FIELD(panel, s32 ***, 0x3C) != 0) && (*M2C_FIELD(panel, s32 ***, 0x3C) == *weapon)) {
            M2C_FIELD(panel, s32 ***, 0x3C) = weapon;
            fn_8008CDE0(M2C_FIELD(panel, s32 **, 0x40), M2C_FIELD(panel, s32 ***, 0x3C));
            return;
        }
        M2C_FIELD(panel, s32 ***, 0x3C) = weapon;
        M2C_FIELD(panel, s32 **, 0x40) = GActor_Create();
        sprintf((M2C_UNK *)&pathBuf, gForgeActorStrings + 8, gForgeActorStrings + 0x11);
        String_Init((M2C_UNK *)&basePath, (M2C_UNK *)&pathBuf, (M2C_UNK *)&scratch);
        name = **M2C_FIELD(panel, s32 ***, 0x3C) + 4;
        fn_800C992C((M2C_UNK *)&basePath, name, strlen(name));
        String_ConcatCStr((M2C_UNK *)&cmpPath, (M2C_UNK *)&basePath, gForgeActorStrings + 0x16);
        String_CStr((M2C_UNK *)&cmpPath);
        M2C_FIELD(panel, u32 *, 0x54) = FileCache_Load();
        String_Destroy((M2C_UNK *)&cmpPath, -1);
        String_ConcatCStr((M2C_UNK *)&gPath, (M2C_UNK *)&basePath, gForgeActorStrings + 0x1D);
        GActor_LoadG(M2C_FIELD(panel, s32 **, 0x40), String_CStr((M2C_UNK *)&gPath));
        String_Destroy((M2C_UNK *)&gPath, -1);
        String_ConcatCStr((M2C_UNK *)&gsPath, (M2C_UNK *)&basePath, gForgeActorStrings + 0x22);
        GActor_LoadGs(M2C_FIELD(panel, s32 **, 0x40), String_CStr((M2C_UNK *)&gsPath));
        String_Destroy((M2C_UNK *)&gsPath, -1);
        String_ConcatCStr((M2C_UNK *)&tplPath, (M2C_UNK *)&basePath, gForgeActorStrings + 0x28);
        GActor_LoadTpl(M2C_FIELD(panel, s32 **, 0x40), String_CStr((M2C_UNK *)&tplPath));
        String_Destroy((M2C_UNK *)&tplPath, -1);
        *M2C_FIELD(panel, s32 **, 0x40) = *M2C_FIELD(panel, s32 **, 0x40) | 0x40000000 | 0x400;
        GActor_Finalize(M2C_FIELD(panel, s32 **, 0x40));
        fn_8008CDE0(M2C_FIELD(panel, s32 **, 0x40), M2C_FIELD(panel, s32 ***, 0x3C));
        M2C_FIELD(panel, s32 ***, 0x3C) = weapon;
        String_Destroy((M2C_UNK *)&basePath, -1);
    }
}

#pragma cplusplus reset

void *fn_80190818(void *arg0, s16 arg1) {
    void fn_800616A0(void *);
    void fn_8005C7E8(void *);
    void Heap_Free(void *);
    extern void *lbl_80296228[];
    extern void *lbl_80292230[];
    extern void *lbl_8028FDB0[];
    void *p;

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_80296228;
        p = *(void **)((u8 *)arg0 + 0x40);
        if (p != NULL) {
            fn_800616A0(p);
        }
        p = *(void **)((u8 *)arg0 + 0x54);
        if (p != NULL) {
            fn_8005C7E8(p);
        }
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_80292230;
            if (arg0 != NULL) {
                *(void **)arg0 = lbl_8028FDB0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void fn_801908B4(void) {

}

#pragma cplusplus on
extern "C" void fn_801908B8(void *arg0, s32 arg1) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11(s32) = 0;
    };
    if (*(u8 *)((u8 *)arg0 + 0x48) != 0) {
        ((Obj *)arg0)->v10();
    }
    ((Obj *)arg0)->v11(arg1);
}
#pragma cplusplus reset
#pragma cplusplus on
extern "C" void fn_80190920(void *arg0) {
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    s32 Text_MeasureHeight(s32, f32);
    void UnitRef_Draw(void *, s32, s16, s16);
    extern f32 lbl_8036ADFC;
    extern f32 lbl_8036AE18;
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual s32 v9(void *) = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
    };
    void *self;
    s16 h1;
    s16 h2;
    void *p3c;
    s32 y;

    self = arg0;
    ((Obj *)self)->v3();
    h1 = *(s16 *)((u8 *)self + 0x46);
    y = Text_MeasureHeight(-1, lbl_8036ADFC);
    p3c = *(void **)((u8 *)self + 0x3C);
    y = h1 - y;
    h2 = *(s16 *)((u8 *)self + 0x4A);
    y = (y >> 1) + *(s16 *)((u8 *)self + 0x4C);
    if (p3c != NULL) {
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036AE18);
        Prim2D_PrepareTex();
        UnitRef_Draw(p3c, ((Obj *)self)->v9(p3c), h2, (s16)y);
    }
}
#pragma cplusplus reset

s32 fn_801909E4(void *arg0, s32 *arg1) {
    s32 fn_80093DA8(void *, s32);
    void *v;

    v = *(void **)((u8 *)arg0 + 0x40);
    if (v != NULL) {
        return fn_80093DA8(v, *arg1);
    }
    return 1;
}

void fn_80190A1C(void *arg0) {
    M2C_UNK Prim2D_AddZ(f32);
    M2C_UNK Prim2D_PrepareTex();
    M2C_UNK Prim2D_Begin();
    M2C_UNK Ui_DrawRouteTex(s16, s16, s32);
    M2C_UNK fn_801583D0(M2C_UNK, M2C_UNK, s16, s16, M2C_UNK, M2C_UNK);
    extern f32 lbl_8036AE1C;
#pragma cplusplus on
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    s16 var_r4;
    register u32 temp;

    ((Obj *)arg0)->v2();
    fn_801583D0(0, 0, (s16) (M2C_FIELD(arg0, s16 *, 0xE) - M2C_FIELD(arg0, s16 *, 0xA)), (s16) (M2C_FIELD(arg0, s16 *, 0x10) - M2C_FIELD(arg0, s16 *, 0xC)), 0xFF, 0x10);
    if ((u8) M2C_FIELD(arg0, u8 *, 0x44) != 0) {
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036AE1C);
        Prim2D_PrepareTex();
        temp = M2C_FIELD(arg0, u8 *, 0x44);
        if (temp == 1) {
            var_r4 = -0x12;
        } else {
            var_r4 = (s16) (M2C_FIELD(arg0, s16 *, 0x10) - M2C_FIELD(arg0, s16 *, 0xC)) - 6;
        }
#pragma cplusplus reset
        {
            s32 eq = ((u8)temp == 1);
#pragma cplusplus on
            Ui_DrawRouteTex((s16) (((s16) (M2C_FIELD(arg0, s16 *, 0xE) - M2C_FIELD(arg0, s16 *, 0xA)) >> 1) - 0x10), var_r4, eq);
        }
#pragma cplusplus reset
    }
#pragma cplusplus reset
}

void fn_80190B00(void *arg0) {
    s16 height, width;
    s32 bottom, right;
    s16 *p = (s16 *)arg0;
    p[0x46/2] = 0;
    p[0x48/2] = 0;
    height = p[0x10/2] - p[0xC/2];
    width = p[0xE/2] - p[0xA/2];
    bottom = height - 8;
    right = width - 2;
    p[0x12/2] = 2;
    p[0x14/2] = 8;
    p[0x16/2] = right;
    p[0x18/2] = bottom;
}

void *fn_80190B50(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_8029625C[];
    extern void *lbl_80292230[];
    extern void *lbl_8028FDB0[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_8029625C;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_80292230;
            if (arg0 != NULL) {
                *(void **)arg0 = lbl_8028FDB0;
            }
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void fn_80190BBC(void *arg0) {
    s16 height, width;
    s32 bottom, right;
    s16 *p = (s16 *)arg0;
    s32 tmp;

    tmp = p[0x46/2] + p[0x4C/2] * 2;
    p[0x10/2] = (s16)(p[0xC/2] + (s16)(tmp + 0x10));
    height = p[0x10/2] - p[0xC/2];
    width = p[0xE/2] - p[0xA/2];
    bottom = height - 8;
    right = width - 2;
    p[0x12/2] = 2;
    p[0x14/2] = 8;
    p[0x16/2] = right;
    p[0x18/2] = bottom;
}

#pragma global_optimizer off
void *fn_80190C24(void *parent, void **names) {
    void *Process_CreateChild(void *, void *);
    void *Process_Create(void *, void *);
    void fn_801403F0(void *);
    void ItemList_Init(void *);
    void ItemList_EraseRange(ListIter *, List *, ListIter *, ListIter *);
    void ItemList_Insert(void *, void *, void *, void *);
    void Item_Init(void *);
    void Item_SetByName(void *, void *);
    void Item_Destroy(void *, s32);
    extern u8 lbl_80296298[];
    u8 item[8];
    ListIter end;
    ListIter start;
    ListIter ret;
    ListIter pos;
    ListIter out;
    void *obj;
    ListNode *sentinel;
    u8 *base;
    u8 mode;

    base = lbl_80296298;
    if (parent) {
        obj = Process_CreateChild(&base[0], parent);
    } else {
        obj = Process_Create(&base[0], parent);
    }
    if (obj) {
        fn_801403F0(obj);
        ItemList_Init((u8 *)obj + 0x40);
        *(s32 *)((u8 *)obj + 0x4C) = 0;
        *(s32 *)((u8 *)obj + 0x50) = 0;
        *(s32 *)((u8 *)obj + 0x54) = 0;
        *(s32 *)((u8 *)obj + 0x58) = 0;
        ((u8 *)obj)[0x5C] = 0;
        *(f32 *)((u8 *)obj + 0x64) = 1.0f;
        *(s32 *)((u8 *)obj + 0x68) = 0;
    }
    mode = 1;
    ((u8 *)obj)[0x5C] = mode;
    switch (mode) {
    case 0:
        *(void **)((u8 *)obj + 0x68) = base + 0x1B0;
        break;
    case 1:
        *(void **)((u8 *)obj + 0x68) = base + 0x210;
        break;
    }
    sentinel = (ListNode *)((u8 *)obj + 0x44);
    end.node = sentinel;
    start.node = *(ListNode **)((u8 *)obj + 0x48);
    ItemList_EraseRange(&ret, (List *)((u8 *)obj + 0x40), &start, &end);
    Item_Init(item);
    if (!names) {
        names = (void **)(base + 0x1A4);
        if (!((u8 *)obj)[0x5C]) {
            names = (void **)(base + 0x180);
        }
    }
    while (*names) {
        Item_SetByName(item, *names);
        pos.node = sentinel;
        ItemList_Insert(&out, (u8 *)obj + 0x40, &pos, item);
        names++;
    }
    Item_Destroy(item, -1);
    return obj;
}
#pragma global_optimizer on
void *fn_80190D9C(void *parent, void **names) {
    void *Process_CreateChild(void *, void *);
    void *Process_Create(void *, void *);
    void fn_801403F0(void *);
    void ItemList_Init(void *);
    void ItemList_EraseRange(ListIter *, List *, ListIter *, ListIter *);
    void ItemList_Insert(void *, void *, void *, void *);
    void Item_Init(void *);
    void Item_SetByName(void *, void *);
    void Item_Destroy(void *, s32);
    extern u8 lbl_80296298[];
    ListIter end;
    ListIter start;
    ListIter ret;
    ListIter out;
    ListIter pos;
    u8 item[8];
    u8 *base = lbl_80296298;
    u8 *obj;
    u8 mode;
    ListNode *sentinel;

    obj = parent != NULL ? Process_CreateChild(base, parent) : Process_Create(base, parent);
    if (obj != NULL) {
        fn_801403F0(obj);
        ItemList_Init(obj + 0x40);
        *(s32 *)(obj + 0x4C) = 0;
        *(s32 *)(obj + 0x50) = 0;
        *(s32 *)(obj + 0x54) = 0;
        *(s32 *)(obj + 0x58) = 0;
        obj[0x5C] = 0;
        *(f32 *)(obj + 0x64) = 1.0f;
        *(s32 *)(obj + 0x68) = 0;
    }
    mode = 0;
    switch (obj[0x5C] = mode) {
    case 0:
        *(void **)(obj + 0x68) = base + 0x1B0;
        break;
    case 1:
        *(void **)(obj + 0x68) = base + 0x210;
        break;
    }
    sentinel = (ListNode *)(obj + 0x44);
    end.node = sentinel;
    start.node = *(ListNode **)(obj + 0x48);
    ItemList_EraseRange(&ret, (List *)(obj + 0x40), &start, &end);
    Item_Init(item);
    if (names == NULL) {
        names = (void **)(base + 0x1A4);
        if (obj[0x5C] == 0) {
            names = (void **)(base + 0x180);
        }
    }
    while (*names != NULL) {
        Item_SetByName(item, *names);
        pos.node = sentinel;
        ItemList_Insert(&out, &((List *)(obj + 0x40))[0], &pos, item);
        names++;
    }
    Item_Destroy(item, -1);
    return obj;
}

void fn_80190F14(void) {
    M2C_UNK fn_8013FE0C();
    fn_8013FE0C();
}

#pragma global_optimizer off
#pragma cplusplus on
extern "C" void fn_80190F34(void *panel) {
    extern void Ui_DtorPanelBase(void *, s32);
    extern u16 gUiPanelFlags;
    void ItemList_EraseRange(void *, List *, ListNode **, ListNode **);

    struct RefObj {
        virtual void destroy(s32);
        s32 refCount;
    };

    ListNode *sp10;
    ListNode *spC;
    u8 sp8[4];
    ListNode *end;
    RefObj *p;
    void *self;

    gUiPanelFlags &= 0xFFFFFFEF;
    self = panel;
    if (self) {
        p = *(RefObj **)((u8 *)self + 0x4C);
        if (p) {
            if (--p->refCount == 0 && p) {
                p->destroy(1);
            }
            *(RefObj **)((u8 *)self + 0x4C) = (RefObj *)0;
        }
        p = *(RefObj **)((u8 *)self + 0x50);
        if (p) {
            if (--p->refCount == 0 && p) {
                p->destroy(1);
            }
            *(RefObj **)((u8 *)self + 0x50) = (RefObj *)0;
        }
        p = *(RefObj **)((u8 *)self + 0x54);
        if (p) {
            if (--p->refCount == 0 && p) {
                p->destroy(1);
            }
            *(RefObj **)((u8 *)self + 0x54) = (RefObj *)0;
        }
        p = *(RefObj **)((u8 *)self + 0x58);
        if (p) {
            if (--p->refCount == 0 && p) {
                p->destroy(1);
            }
            *(RefObj **)((u8 *)self + 0x58) = (RefObj *)0;
        }
        if ((s32)self + 0x40) {
            if ((s32)self + 0x40) {
                if ((s32)self + 0x40) {
                    end = (ListNode *)((u8 *)self + 0x44);
                    sp10 = end;
                    spC = end->next;
                    ItemList_EraseRange(sp8, (List *)((u8 *)self + 0x40), &spC, &sp10);
                }
            }
        }
        Ui_DtorPanelBase(self, 0);
    }
}
#pragma cplusplus reset
#pragma global_optimizer on

void fn_801910B4(void *arg0)
{
    extern u32 gUiInputFlags;
    extern u8 *gPadInput;
    extern u8 lbl_80279DF0[];

    extern void Ui_PlaySeCue(void *, s32);
    extern void Process_ClearFunc(void *);

    u32 flags;
    u32 active;
    u32 value;
    u32 previous;
    u8 *state;
    u8 *obj;

    obj = (u8 *)arg0;

    active = 0;
    flags = gUiInputFlags;

    if ((flags & 0x10) && !(flags & 0x20)) {
        active = 1;
    }

    if ((u8)active == 0) {
        state = gPadInput;

        value = *(u32 *)(state + 0x04);
        previous = *(u32 *)(state + 0x08);

        if ((value & (previous ^ value) & 0x300) != 0) {
            Ui_PlaySeCue(lbl_80279DF0 + 0x4AC, 0x64);
            Process_ClearFunc(obj);
        }
    }
}

void fn_80191138(void *arg0) {
    void TalkUi_ShowMsg(s32);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *, s32);
    void *inner;
    s32 saved;
    void *ret;

    TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)arg0 + 0x68) + 0x40));
    inner = *(void **)((u8 *)arg0 + 0x68);
    saved = *(s32 *)((u8 *)inner + 0x58);
    ret = Ui_FindChild(arg0, -0x1000, 0);
    if (ret != NULL) {
        Ui_SetWidgetText(ret, saved);
    }
}

#pragma cplusplus on
extern "C" void fn_80191194(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11(s32) = 0;
    };
    s32 Ui_ListGetSelected(s32);
    void fn_8013AD70(s32, s32);
    Obj *Ui_FindChild(void *, s32, s32);
    void Process_Goto(void *, s32);
    extern u8 gBattleState[];
    s32 temp_r31;
    Obj *temp_r30;

    temp_r31 = *(s32 *)((u8 *)arg0 + 0x50);
    temp_r30 = Ui_FindChild(arg0, 5, 0);
    fn_8013AD70(temp_r31, *(s32 *)(gBattleState + 0xB0));
    temp_r30->v11(Ui_ListGetSelected(temp_r31));
    Process_Goto(arg0, *(u8 *)((u8 *)arg0 + 0x5D));
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_80191224(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11(s32) = 0;
    };
    s32 Ui_ListGetSelected(s32);
    void fn_8013AD70(s32, s32);
    Obj *Ui_FindChild(void *, s32, s32);
    extern u8 gBattleState[];
    s32 temp_r31;
    Obj *temp_r30;

    temp_r31 = *(s32 *)((u8 *)arg0 + 0x50);
    temp_r30 = Ui_FindChild(arg0, 5, 0);
    fn_8013AD70(temp_r31, *(s32 *)(gBattleState + 0xAC));
    temp_r30->v11(Ui_ListGetSelected(temp_r31));
}
#pragma cplusplus reset
void fn_8019129C(void *arg0) {
    M2C_UNK Process_Goto(void *, u8);
    Process_Goto(arg0, *(u8 *)((char *)arg0 + 0x5D));
}

void fn_801912C0(void *arg0) {
    s32 Ui_FindChild(void *, s32, s32);
    void Ui_BringChildToFront(void *, s32);
    void TalkUi_ShowMsg(void *);
    void Ui_PlaySeCue(void *, s32);
    void Process_ClearFunc(void *);
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern u8 lbl_80279DF0[];
    u8 flag;
    u32 a;
    u32 b;

    Ui_BringChildToFront(arg0, Ui_FindChild(arg0, -0x1000, 0));
    flag = 0;
    if ((gUiInputFlags & 0x10) != 0 && (gUiInputFlags & 0x20) == 0) {
        flag = 1;
    }
    if (flag == 0) {
        a = *(u32 *)((u8 *)gPadInput + 4);
        b = *(u32 *)((u8 *)gPadInput + 8);
        if ((a & (b ^ a) & 0x300) != 0) {
            Ui_BringChildToFront(arg0, *(s32 *)((u8 *)arg0 + 0x50));
            TalkUi_ShowMsg(*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x68) + 0x3C));
            Ui_PlaySeCue(lbl_80279DF0 + 0x4AC, 0x64);
            Process_ClearFunc(arg0);
        }
    }
}

void fn_80191374(void *arg0) {
    s32 Ui_FindChild(void *, s32, s32);
    void Ui_BringChildToFront(void *, s32);
    void TalkUi_ShowMsg(void *);
    void Ui_PlaySeCue(void *, s32);
    void Process_ClearFunc(void *);
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern u8 lbl_80279DF0[];
    u8 flag;
    u32 a;
    u32 b;

    Ui_BringChildToFront(arg0, Ui_FindChild(arg0, -0x1000, 0));
    flag = 0;
    if ((gUiInputFlags & 0x10) != 0 && (gUiInputFlags & 0x20) == 0) {
        flag = 1;
    }
    if (flag == 0) {
        a = *(u32 *)((u8 *)gPadInput + 4);
        b = *(u32 *)((u8 *)gPadInput + 8);
        if ((a & (b ^ a) & 0x300) != 0) {
            Ui_BringChildToFront(arg0, *(s32 *)((u8 *)arg0 + 0x50));
            TalkUi_ShowMsg(*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x68) + 0x34));
            Ui_PlaySeCue(lbl_80279DF0 + 0x4AC, 0x64);
            Process_ClearFunc(arg0);
        }
    }
}

void fn_80191428(void *arg0) {
    s32 Ui_FindChild(void *, s32, s32);
    void Ui_BringChildToFront(void *, s32);
    void TalkUi_ShowMsg(void *);
    void Ui_PlaySeCue(void *, s32);
    void Process_ClearFunc(void *);
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern u8 lbl_80279DF0[];
    u8 flag;
    u32 a;
    u32 b;

    Ui_BringChildToFront(arg0, Ui_FindChild(arg0, -0x1000, 0));
    flag = 0;
    if ((gUiInputFlags & 0x10) != 0 && (gUiInputFlags & 0x20) == 0) {
        flag = 1;
    }
    if (flag == 0) {
        a = *(u32 *)((u8 *)gPadInput + 4);
        b = *(u32 *)((u8 *)gPadInput + 8);
        if ((a & (b ^ a) & 0x300) != 0) {
            Ui_BringChildToFront(arg0, *(s32 *)((u8 *)arg0 + 0x50));
            TalkUi_ShowMsg(*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x68) + 0x2C));
            Ui_PlaySeCue(lbl_80279DF0 + 0x4AC, 0x64);
            Process_ClearFunc(arg0);
        }
    }
}

void fn_801914DC(void *arg0) {
    s32 Ui_FindChild(void *, s32, s32);
    void Ui_BringChildToFront(void *, s32);
    void TalkUi_ShowMsg(void *);
    void Ui_PlaySeCue(void *, s32);
    void Process_ClearFunc(void *);
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern u8 lbl_80279DF0[];
    u8 flag;
    u32 a;
    u32 b;

    Ui_BringChildToFront(arg0, Ui_FindChild(arg0, -0x1000, 0));
    flag = 0;
    if ((gUiInputFlags & 0x10) != 0 && (gUiInputFlags & 0x20) == 0) {
        flag = 1;
    }
    if (flag == 0) {
        a = *(u32 *)((u8 *)gPadInput + 4);
        b = *(u32 *)((u8 *)gPadInput + 8);
        if ((a & (b ^ a) & 0x300) != 0) {
            Ui_BringChildToFront(arg0, *(s32 *)((u8 *)arg0 + 0x4C));
            TalkUi_ShowMsg(*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x68) + 0x24));
            Ui_PlaySeCue(lbl_80279DF0 + 0x4AC, 0x64);
            Process_ClearFunc(arg0);
        }
    }
}

#pragma use_lmw_stmw on
#pragma cplusplus on
extern "C" void fn_80191590(void *arg0) {
    struct Ref {
        virtual void v0(s32) = 0;
        s32 ref;
    };
    struct Child {
        u8 pad[0xC];
        s16 unkC;
    };
    struct Nest {
        u8 pad[8];
        s32 unk8;
        u8 padC[0x38];
        s32 unk44;
    };
    struct Self {
        u8 pad[0x50];
        void *unk50;
        Ref *unk54;
        Ref *unk58;
        u8 pad5C[0xC];
        Nest *unk68;
    };
    Child *Ui_FindChild(void *, s32, s32);
    void Ui_RemoveChild(void *, void *);
    void Ui_SlideWidgetChild(void *, void *, s16 *, s32);
    void TalkUi_ShowMsg(s32);
    void fn_80193344(void *);
    void Ui_SetWidgetText(Child *, s32);
    void Process_Goto(void *, s32);
    s16 sp14[2];
    s16 sp10[2];
    s16 spC[2];
    s16 sp8[2];
    Child *c6;
    void *saved;
    Child *c2;
    Child *c4;
    Child *c5;
    Self *self;
    s16 t;

    self = (Self *)arg0;
    saved = self->unk50;
    c2 = Ui_FindChild(self, 2, 0);
    c4 = Ui_FindChild(self, 4, 0);
    c5 = Ui_FindChild(self, 5, 0);
    c6 = Ui_FindChild(self, 6, 0);
    Ui_RemoveChild(self, saved);
    t = c2->unkC;
    sp14[0] = 0x260;
    sp14[1] = t;
    Ui_SlideWidgetChild(self, c2, sp14, 0);
    if (c4 != 0) {
        t = c4->unkC;
        sp10[0] = 0x260;
        sp10[1] = t;
        Ui_SlideWidgetChild(self, c4, sp10, 0);
    }
    if (c5 != 0) {
        t = c5->unkC;
        spC[0] = 0x260;
        spC[1] = t;
        Ui_SlideWidgetChild(self, c5, spC, 0);
    }
    {
        Ref *p = self->unk54;
        if (p != 0) {
            if (--p->ref == 0) {
                if (p != 0) {
                    p->v0(1);
                }
            }
            self->unk54 = 0;
        }
    }
    if (c6 != 0) {
        t = c6->unkC;
        sp8[0] = 0x260;
        sp8[1] = t;
        Ui_SlideWidgetChild(self, c6, sp8, 0);
    }
    {
        Ref *p = self->unk58;
        if (p != 0) {
            if (--p->ref == 0) {
                if (p != 0) {
                    p->v0(1);
                }
            }
            self->unk58 = 0;
        }
    }
    TalkUi_ShowMsg(self->unk68->unk8);
    fn_80193344(self);
    c6 = (Child *)self->unk68->unk44;
    {
        Child *res = Ui_FindChild(self, -0x1000, 0);
        if (res != 0) {
            Ui_SetWidgetText(res, (s32)c6);
        }
    }
    Process_Goto(self, 3);
}
#pragma cplusplus reset
#pragma use_lmw_stmw reset

void fn_80191794(void *panel) {
    extern u8 gUiContext[],gBattleState[],gConvoy[];
    void *Ui_FindChild(void *,s32,s32);
    u32 UnitRef_GetValue(void *);
    void fn_8014D268(void *,s32);
    s32 Ui_ListGetSelected(void *);
    void fn_80094A54(s32,void *);
    u8 fn_8014D8DC(void *);
    void fn_800C3AB0(void *,void *);
    void fn_801402A0(void *,void *,s16 *,s32);
    void TalkUi_ShowMsg(s32);
    void Ui_LayoutUnitList(void *);
    void Ui_SetWidgetText(void *,s32);
    void Process_Goto(void *,s32);
    s16 pos[2];
    void *list;
    void *item;
    void *widget;
    void *unit;
    void *child;
    s32 text;
    s32 price;
    void *entry;
    widget=M2C_FIELD(panel,void **,0x58);
    switch(gUiContext[8]) {
    case 0x81:
        list=M2C_FIELD(panel,void **,0x50);
        item=M2C_FIELD(Ui_FindChild(panel,2,0),void **,0x3C);
        price = (s32)(u16)UnitRef_GetValue(item);
        fn_8014D268(gBattleState, *(s32 *)(gBattleState + 0x18) - (s32)(*(f32 *)((u8 *)panel + 0x64) * (f32)price));
        if(M2C_FIELD(list,s16 *,0x4E)!=0x7FFF) {
            s32 selected=Ui_ListGetSelected(list);
            entry=M2C_FIELD(item,void **,0);
            if(entry) unit=M2C_FIELD(entry,void **,0); else unit=0;
            fn_80094A54(selected,unit);
        } else if(fn_8014D8DC(gBattleState)) {
            entry=M2C_FIELD(item,void **,0);
            if(entry) unit=M2C_FIELD(entry,void **,0); else unit=0;
            fn_800C3AB0(gConvoy,unit);
        }
        break;
    case 0x80:
        pos[0]=M2C_FIELD(widget,s16 *,0xA);
        pos[1]=0x108;
        fn_801402A0(panel,widget,pos,0);
        M2C_FIELD(widget,s32 *,0x3C)=1;
        TalkUi_ShowMsg(M2C_FIELD(M2C_FIELD(panel,void **,0x68),s32 *,0x14));
        Ui_LayoutUnitList(panel);
        text=M2C_FIELD(M2C_FIELD(panel,void **,0x68),s32 *,0x48);
        child=Ui_FindChild(panel,-0x1000,0);
        if(child) Ui_SetWidgetText(child,text);
        Process_Goto(panel,7);
        break;
    }
}

void fn_80191938(void *arg0) {
    void Ui_CreateMenu(void *, void *, s32);
    void *fn_8013BC10(s32, s32);
    u32 Ui_FindChild(void *, s32, s32, void *);
    void Ui_SetWidgetText(u32, s32);
    s32 temp_r31;
    void *temp_r3;
    void *temp_r6;
    u32 res;

    temp_r3 = fn_8013BC10(0, 0);
    *(s16 *)((u8 *)temp_r3 + 8) = 0x178;
    *(s16 *)((u8 *)temp_r3 + 0xA) = 0x3C;
    *(u8 *)((u8 *)temp_r3 + 0x24) = 1;
    Ui_CreateMenu(temp_r3, arg0, 0);
    temp_r6 = *(void **)((u8 *)arg0 + 0x68);
    temp_r31 = *(s32 *)((u8 *)temp_r6 + 0x4C);
    res = Ui_FindChild(arg0, -0x1000, 0, temp_r6);
    if (res != 0U) {
        Ui_SetWidgetText(res, temp_r31);
    }
}

void fn_801919B8(void *arg0) {
    void TalkUi_ShowMsg(s32);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SlideWidgetChild(void *, void *, s16 *, s32);
    void Ui_SlideWidgetChildMode1(void *, void *, s16 *, s32);
    void fn_801402A0(void *, void *, s16 *, s32);
#pragma cplusplus on
    struct Widget { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void update(); };
    s16 p1[2], p2[2], p3[2];
    s16 y;
    void *a;
    void *b;
    void *c;
    a = M2C_FIELD(arg0, void **, 0x50);
    b = Ui_FindChild(arg0, 2, 0);
    c = M2C_FIELD(arg0, void **, 0x58);
    y=M2C_FIELD(a,s16 *,0xC);
    p1[0]=0x260; p1[1]=y;
    Ui_SlideWidgetChild(arg0,a,p1,0);
    p2[0]=0x138; p2[1]=0x74;
    Ui_SlideWidgetChildMode1(arg0,b,p2,0);
    M2C_FIELD(b,s16 *,0xE)=M2C_FIELD(b,s16 *,0xA)+0x108;
    M2C_FIELD(b,s16 *,0x4A)=0x14;
    M2C_FIELD(b,s16 *,0x4C)=0;
    ((Widget *)b)->update();
    M2C_FIELD(b,s8 *,0x48)=1;
    M2C_FIELD(b,s8 *,0x44)=2;
    p3[0]=M2C_FIELD(c,s16 *,0xA); p3[1]=0xA7;
    fn_801402A0(arg0,c,p3,0);
    M2C_FIELD(c,s32 *,0x3C)=0;
    TalkUi_ShowMsg(M2C_FIELD(M2C_FIELD(arg0,void **,0x68),s32 *,0x1C));
#pragma cplusplus reset
}

#pragma opt_common_subs off
void fn_80191AD0(void *panel) {
    extern u8 gUiContext[], gBattleState[], gConvoy[];
    void *Ui_FindChild(void *, s32, s32);
    u32 UnitRef_GetValue(void *);
    void fn_8014D268(void *, s32);
    s32 Ui_ListGetSelected(void *);
    void fn_80094A54(s32, void *);
    u8 fn_8014D8DC(void *);
    void fn_800C3AB0(void *, void *);
    void Ui_SlideWidgetChild(void *, void *, s16 *, s32);
    void TalkUi_ShowMsg(s32);
    void Ui_LayoutUnitList(void *);
    void Ui_SetWidgetText(void *, s32);
    void Process_Goto(void *, s32);
    s16 pos[2];
    void *list;
    void *item;
    void *widget;
    void *unit;
    void *child;
    s32 text;
    s32 price;
    void *entry;

    widget = Ui_FindChild(panel, 4, 0);
    switch (gUiContext[8]) {
    case 0x81:
        list = M2C_FIELD(panel, void **, 0x50);
        item = M2C_FIELD(Ui_FindChild(panel, 2, 0), void **, 0x3C);
        price = (s32)(u16)UnitRef_GetValue(item);
        fn_8014D268(gBattleState, *(s32 *)(gBattleState + 0x18) - (s32)(*(f32 *)((u8 *)panel + 0x64) * (f32)price));
        if (M2C_FIELD(list, s16 *, 0x4E) != 0x7FFF) {
            s32 selected = Ui_ListGetSelected(list);
            entry = M2C_FIELD(item, void **, 0);
            if (entry)
                unit = M2C_FIELD(entry, void **, 0);
            else
                unit = 0;
            fn_80094A54(selected, unit);
        } else if (fn_8014D8DC(gBattleState)) {
            entry = M2C_FIELD(item, void **, 0);
            if (entry)
                unit = M2C_FIELD(entry, void **, 0);
            else
                unit = 0;
            fn_800C3AB0(gConvoy, unit);
        }
        break;
    case 0x80: {
        s16 y;
        y = M2C_FIELD(widget, s16 *, 0xC);
        pos[0] = 0x260;
        pos[1] = y;
        Ui_SlideWidgetChild(panel, widget, pos, 0);
        TalkUi_ShowMsg(M2C_FIELD(M2C_FIELD(panel, void **, 0x68), s32 *, 0x14));
        Ui_LayoutUnitList(panel);
        text = M2C_FIELD(M2C_FIELD(panel, void **, 0x68), s32 *, 0x48);
        child = Ui_FindChild(panel, -0x1000, 0);
        if (child)
            Ui_SetWidgetText(child, text);
        Process_Goto(panel, 7);
        break;
    }
    }
}
#pragma opt_common_subs reset
void fn_80191C7C(void *arg0) {
    void Ui_CreateMenu(void *, void *, s32);
    void *fn_8013BC10(s32, s32);
    u32 Ui_FindChild(void *, s32, s32, void *);
    void Ui_SetWidgetText(u32, s32);
    s32 temp_r31;
    void *temp_r3;
    void *temp_r6;
    u32 res;

    temp_r3 = fn_8013BC10(0, 0);
    *(s16 *)((u8 *)temp_r3 + 8) = 0x178;
    *(s16 *)((u8 *)temp_r3 + 0xA) = 0x3C;
    *(u8 *)((u8 *)temp_r3 + 0x24) = 1;
    Ui_CreateMenu(temp_r3, arg0, 0);
    temp_r6 = *(void **)((u8 *)arg0 + 0x68);
    temp_r31 = *(s32 *)((u8 *)temp_r6 + 0x4C);
    res = Ui_FindChild(arg0, -0x1000, 0, temp_r6);
    if (res != 0U) {
        Ui_SetWidgetText(res, temp_r31);
    }
}

#pragma cplusplus on
#pragma global_optimizer off
extern "C" void fn_80191CFC(void *arg0) {
    void *fn_800C42D8(s32);
    void fn_8011D79C(s32);
    s32 fn_8013AC54(void *);
    void *fn_8013FF94(void *, s32, s32);
    void fn_80138808(void *, s32);
    void fn_801400F4(void *, void *);
    void fn_80140258(void *, void *, s16 *, s32);
    void fn_8014027C(void *, void *, s16 *, s32);
    extern u8 lbl_8028FDB0[];
    extern u8 lbl_80291A3C[];
    extern u8 lbl_80292230[];
    extern const f32 lbl_8036AE20;

    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v5();
        virtual void v4();
        virtual void v6();
        virtual void v7();
        virtual void v8();
    };

    struct { s16 x; s16 y; } sp10;
    struct { s16 x; s16 y; } spC;
    struct { s16 x; s16 y; } sp8;
    s16 temp_r6;
    register void *temp_r31;
    s16 temp_r5;
    void *temp_r30;
    register s16 temp_r7;
    register void *temp_r28;
    f32 zf;

    temp_r30 = M2C_FIELD(arg0, void **, 0x50);
    temp_r28 = fn_8013FF94(arg0, 2, 0);
    temp_r6 = M2C_FIELD(temp_r30, s16 *, 0xC);
    sp10.x = 0x260;
    sp10.y = temp_r6;
    fn_80140258(arg0, temp_r30, &sp10.x, 0);
    spC.x = 0x138;
    spC.y = 0x74;
    fn_8014027C(arg0, temp_r28, &spC.x, 0);
    temp_r5 = M2C_FIELD(temp_r28, s16 *, 0xA) + 0x108;
    M2C_FIELD(temp_r28, s16 *, 0xE) = temp_r5;
    M2C_FIELD(temp_r28, s16 *, 0x4A) = 0x14;
    M2C_FIELD(temp_r28, s16 *, 0x4C) = 0;
    ((Obj *)temp_r28)->v8();
    M2C_FIELD(temp_r28, u8 *, 0x48) = 1;
    M2C_FIELD(temp_r28, u8 *, 0x44) = 2;
    temp_r31 = fn_800C42D8(0x54);
    if (temp_r31 != NULL) {
        M2C_FIELD(temp_r31, void **, 0) = lbl_8028FDB0;
        M2C_FIELD(temp_r31, s32 *, 4) = 0;
        M2C_FIELD(temp_r31, void **, 0) = lbl_80292230;
        M2C_FIELD(temp_r31, s16 *, 8) = -1;
        M2C_FIELD(temp_r31, s16 *, 0xA) = 0x260;
        M2C_FIELD(temp_r31, s16 *, 0xC) = 0xA7;
        M2C_FIELD(temp_r31, s16 *, 0xE) = 0x368;
        M2C_FIELD(temp_r31, s16 *, 0x10) = 0xFC;
        M2C_FIELD(temp_r31, s16 *, 0x14) = 0;
        M2C_FIELD(temp_r31, s16 *, 0x16) = 0x108;
        M2C_FIELD(temp_r31, s16 *, 0x12) = 0;
        M2C_FIELD(temp_r31, s16 *, 0x1A) = 0;
        M2C_FIELD(temp_r31, s16 *, 0x1C) = 0;
        M2C_FIELD(temp_r31, s16 *, 0x18) = 0x55;
        M2C_FIELD(temp_r31, u8 *, 0x1E) = 0xFF;
        M2C_FIELD(temp_r31, u8 *, 0x1F) = 0xFF;
        M2C_FIELD(temp_r31, u8 *, 0x20) = 0xFF;
        M2C_FIELD(temp_r31, u8 *, 0x21) = 0xFF;
        M2C_FIELD(temp_r31, s16 *, 0x22) = 0x190;
        M2C_FIELD(temp_r31, s16 *, 0x24) = 0;
        zf = lbl_8036AE20;
        M2C_FIELD(temp_r31, f32 *, 0x28) = zf;
        M2C_FIELD(temp_r31, f32 *, 0x2C) = zf;
        M2C_FIELD(temp_r31, f32 *, 0x30) = zf;
        M2C_FIELD(temp_r31, s32 *, 0x34) = 0;
        M2C_FIELD(temp_r31, s32 *, 0x38) = 0;
        M2C_FIELD(temp_r31, void **, 0) = lbl_80291A3C;
        M2C_FIELD(temp_r31, s32 *, 0x3C) = 0;
        M2C_FIELD(temp_r31, s32 *, 0x40) = 0x1003A;
        M2C_FIELD(temp_r31, s32 *, 0x4C) = 0;
        M2C_FIELD(temp_r31, s32 *, 0x50) = 0;
        ((Obj *)temp_r31)->v8();
        M2C_FIELD(temp_r31, s16 *, 8) = 4;
        M2C_FIELD(temp_r31, s16 *, 0x24) = 8;
        M2C_FIELD(temp_r31, s32 *, 0x34) |= 0x10;
        fn_80138808(temp_r31, fn_8013AC54(temp_r30));
        fn_801400F4(arg0, temp_r31);
        temp_r7 = M2C_FIELD(temp_r31, s16 *, 0xC);
        sp8.x = 0x138;
        sp8.y = temp_r7;
        fn_8014027C(arg0, temp_r31, &sp8.x, 0);
        fn_8011D79C(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0x18));
    }
}

#pragma cplusplus on
extern "C" void fn_80191F2C(void *arg0) {
    void Process_Goto(void *, s32);
    u32 *Item_GetFlagsPtr(void *);
    u8 fn_80092F38(void *);
    u8 fn_80092F9C(void *);
    s32 Convoy_FindEmpty(void *);
    void TalkUi_ShowMsg(s32);
    void *Ui_ListGetSelected(void *);
    void Ui_UpdatePanelWidgets(void *);
    void Ui_BringChildToFront(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_AddChild(void *, void *);
    void Ui_PlaySeCue(void *, s32);
    u8 fn_8014D8DC(void *);
    void Ui_SetWidgetText(void *, s32);
    void fn_801694AC(void *, void *);
    void fn_801695BC(void *, void *, s32);
    void Ui_CreateMsgPopup(void *, void *, f32, f32);
    void fn_80193344(void *);
    extern u8 lbl_80279DF0[];
    extern u8 gConvoy[];
    extern u8 gBattleState[];
    extern u32 gUiInputFlags;
    extern void *gPadInput;

    class Pair {
    public:
        s16 x;
        s16 y;
        Pair() {}
        Pair(s16 a, s16 b) : x(a), y(b) {}
        Pair(const Pair &o) { *(u32 *)this = *(u32 *)&o; }
        Pair &operator=(const Pair &o) { *(u32 *)this = *(u32 *)&o; return *this; }
    };
    void Ui_SlideWidgetChild(void *, void *, const Pair &, s32);
    void Ui_SlideWidgetChildMode1(void *, void *, const Pair &, s32);
    struct Ref {
        virtual void destroy(s32) = 0;
        s32 ref;
    };
    struct Panel {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11(s32) = 0;
    };
    struct ListObj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual Pair v9() = 0;
    };
    struct Child {
        u8 pad[0xC];
        s16 unkC;
        u8 padE[0x2E];
        s32 unk3C;
        void *unk40;
    };

    Child *child;
    void *unit;
    void *list;
    void *self;
    u32 btn;
    u32 a;
    u32 b;
    u8 gate;
    int flags;
    void *nest;
    s32 saved;
    void *ret;
    u32 pos;
    u32 *bits;
    void *sel;

    self = arg0;
    list = *(void **)((u8 *)arg0 + 0x50);
    child = (Child *)Ui_FindChild(self, 2, 0);
    unit = Ui_ListGetSelected(list);
    Ui_UpdatePanelWidgets(self);
    if (unit != Ui_ListGetSelected(list)) {
        if (unit != 0 && Ui_ListGetSelected(list) != 0) {
            sel = Ui_ListGetSelected(list);
            ((Panel *)*(void **)((u8 *)self + 0x54))->v11((s32)sel);
        } else if (unit != 0 && Ui_ListGetSelected(list) == 0) {
            Ui_SlideWidgetChild(self, *(void **)((u8 *)self + 0x54),
                        Pair(0x260, *(s16 *)((u8 *)*(void **)((u8 *)self + 0x54) + 0xC)), 1);
            if (fn_8014D8DC(gBattleState) != 0) {
                Ui_AddChild(self, *(void **)((u8 *)self + 0x58));
                Ui_SlideWidgetChildMode1(self, *(void **)((u8 *)self + 0x58),
                            Pair(0x134, *(s16 *)((u8 *)*(void **)((u8 *)self + 0x58) + 0xC)), 0);
            }
            Ui_BringChildToFront(self, list);
        } else {
            Ui_AddChild(self, *(void **)((u8 *)self + 0x54));
            Ui_SlideWidgetChildMode1(self, *(void **)((u8 *)self + 0x54),
                        Pair(0x138, *(s16 *)((u8 *)*(void **)((u8 *)self + 0x54) + 0xC)), 1);
            ((Panel *)*(void **)((u8 *)self + 0x54))->v11((s32)Ui_ListGetSelected(list));
            if (fn_8014D8DC(gBattleState) != 0) {
                Ui_SlideWidgetChild(self, *(void **)((u8 *)self + 0x58),
                            Pair(0x260, *(s16 *)((u8 *)*(void **)((u8 *)self + 0x58) + 0xC)), 0);
            }
            Ui_BringChildToFront(self, list);
        }
        unit = Ui_ListGetSelected(list);
    }
    child->unk40 = unit;
    flags = gUiInputFlags;
    gate = 0;
    if ((flags & 0x10) && !(flags & 0x20)) {
        gate = 1;
    }
    if (!gate) {
        a = *(u32 *)((u8 *)gPadInput + 4);
        b = *(u32 *)((u8 *)gPadInput + 8);
        btn = a & (b ^ a);
        if ((btn & 0x100) && unit != 0) {
            nest = (void *)child->unk3C;
            Ui_PlaySeCue(lbl_80279DF0 + 0x4BC, 0x64);
            bits = Item_GetFlagsPtr(nest);
            if ((*(u64 *)bits & 5ULL) != 0 && (u8)fn_80092F9C(unit) >= 4) {
                TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)self + 0x68) + 0x28));
                nest = *(void **)((u8 *)self + 0x68);
                saved = *(s32 *)((u8 *)nest + 0x54);
                ret = Ui_FindChild(self, -0x1000, 0);
                if (ret != 0) {
                    Ui_SetWidgetText(ret, saved);
                }
                Process_Goto(self, 0xC);
            } else {
                bits = Item_GetFlagsPtr(nest);
                if ((*(u64 *)bits & 0x18ULL) != 0 && (u8)fn_80092F38(unit) >= 4) {
                    TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)self + 0x68) + 0x28));
                    nest = *(void **)((u8 *)self + 0x68);
                    saved = *(s32 *)((u8 *)nest + 0x54);
                    ret = Ui_FindChild(self, -0x1000, 0);
                    if (ret != 0) {
                        Ui_SetWidgetText(ret, saved);
                    }
                    Process_Goto(self, 0xC);
                } else {
                    Process_Goto(self, 9);
                }
            }
        } else if ((btn & 0x100) && unit == 0 && *(s16 *)((u8 *)list + 0x4E) == 0x7FFF) {
            if (fn_8014D8DC(gBattleState) == 0) {
                *(Pair *)&pos = ((ListObj *)list)->v9();
                Ui_CreateMsgPopup(lbl_80279DF0 + 0x4CC, self, (f32)*(s16 *)&pos, (f32)*((s16 *)&pos + 1));
            } else {
                Ui_PlaySeCue(lbl_80279DF0 + 0x4BC, 0x64);
                if (Convoy_FindEmpty(gConvoy) < 0) {
                    TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)self + 0x68) + 0x38));
                    nest = *(void **)((u8 *)self + 0x68);
                    saved = *(s32 *)((u8 *)nest + 0x54);
                    ret = Ui_FindChild(self, -0x1000, 0);
                    if (ret != 0) {
                        Ui_SetWidgetText(ret, saved);
                    }
                    Process_Goto(self, 0xE);
                } else {
                    Process_Goto(self, 0xA);
                }
            }
        } else if ((btn & 0x800) && unit != 0) {
            fn_801695BC(unit, self, 0x1000000);
            *(u8 *)((u8 *)self + 0x5D) = 7;
            Process_Goto(self, 0xF);
        } else if ((btn & 0x400) && unit != 0) {
            fn_801694AC(unit, self);
            *(u8 *)((u8 *)self + 0x5D) = 7;
            Process_Goto(self, 0x10);
        } else if (btn & 0x200) {
            Ui_SlideWidgetChild(self, list, Pair(0x260, *(s16 *)((u8 *)list + 0xC)), 0);
            if (Ui_FindChild(self, 5, 0) != 0) {
                Ui_SlideWidgetChild(self, *(void **)((u8 *)self + 0x54),
                            Pair(0x260, *(s16 *)((u8 *)*(void **)((u8 *)self + 0x54) + 0xC)), 0);
            }
            {
                Ref *p = *(Ref **)((u8 *)self + 0x54);
                if (p != 0) {
                    if (--p->ref == 0) {
                        if (p != 0) {
                            p->destroy(1);
                        }
                    }
                    *(Ref **)((u8 *)self + 0x54) = (Ref *)0;
                }
            }
            if (Ui_FindChild(self, 6, 0) != 0) {
                Ui_SlideWidgetChild(self, *(void **)((u8 *)self + 0x58),
                            Pair(0x260, *(s16 *)((u8 *)*(void **)((u8 *)self + 0x58) + 0xC)), 0);
            }
            {
                Ref *p = *(Ref **)((u8 *)self + 0x58);
                if (p != 0) {
                    if (--p->ref == 0) {
                        if (p != 0) {
                            p->destroy(1);
                        }
                    }
                    *(Ref **)((u8 *)self + 0x58) = (Ref *)0;
                }
            }
            Ui_SlideWidgetChild(self, child, Pair(0x260, child->unkC), 0);
            TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)self + 0x68) + 0xC));
            fn_80193344(self);
            Process_Goto(self, 3);
            Ui_PlaySeCue(lbl_80279DF0 + 0x4DE, 0x64);
        }
    }
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void Ui_LayoutUnitList(void *arg0) {
    /* Slide in the unit-list panel: list, selection detail (or battle alt), and caption. */
    s32 Ui_ListGetSelected(void *);
    void Ui_BringChildToFront(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_AddChild(void *, void *);
    void Ui_SlideWidgetChildMode1(void *, void *, s16 *, s32);
    void fn_801402A0(void *, void *, s16 *, s32);
    u8 fn_8014D8DC(void *);
    void Ui_SetWidgetText(u32, s32);
    extern u8 gBattleState[];

    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11(s32);
    };

    s16 listPos[2];
    s16 detailPos[2];
    s16 altPos[2];
    s16 captionPos[2];
    void *list;
    void *panel;
    void *child;
    void *captionSrc;
    u32 caption;
    s16 savedH;
    s16 endX;

    panel = arg0;
    if ((list = Ui_FindChild(arg0, 3, 0)) == 0) {
        list = *(void **)((u8 *)panel + 0x50);
        Ui_AddChild(panel, list);
    }
    *(u8 *)((u8 *)list + 0x4C) = 1;
    if (*(s16 *)((u8 *)list + 0xA) != 0x118) {
        savedH = *(s16 *)((u8 *)list + 0xC);
        listPos[0] = 0x118;
        listPos[1] = savedH;
        Ui_SlideWidgetChildMode1(panel, list, listPos, 0);
    }
    if (*(s16 *)((u8 *)list + 0x4E) != 0x7FFF) {
        if ((child = Ui_FindChild(panel, 5, 0)) == 0) {
            child = *(void **)((u8 *)panel + 0x54);
            Ui_AddChild(panel, child);
        }
        ((Obj *)child)->v11(Ui_ListGetSelected(list));
        if (*(s16 *)((u8 *)child + 0xA) != 0x138) {
            savedH = *(s16 *)((u8 *)child + 0xC);
            detailPos[0] = 0x138;
            detailPos[1] = savedH;
            Ui_SlideWidgetChildMode1(panel, child, detailPos, 0);
        }
    } else if (fn_8014D8DC(gBattleState) != 0) {
        if ((child = Ui_FindChild(panel, 6, 0)) == 0) {
            child = *(void **)((u8 *)panel + 0x58);
            Ui_AddChild(panel, child);
        }
        if (*(s16 *)((u8 *)child + 0xA) != 0x134) {
            savedH = *(s16 *)((u8 *)child + 0xC);
            altPos[0] = 0x134;
            altPos[1] = savedH;
            Ui_SlideWidgetChildMode1(panel, child, altPos, 0);
        }
    }
    child = Ui_FindChild(panel, 2, 0);
    if (*(u8 *)((u8 *)child + 0x48) != 0) {
        captionPos[0] = 0x14C;
        captionPos[1] = 0x30;
        fn_801402A0(panel, child, captionPos, 0);
    }
    endX = *(s16 *)((u8 *)child + 0xA) + 0xE8;
    *(s16 *)((u8 *)child + 0xE) = endX;
    *(s16 *)((u8 *)child + 0x4A) = 8;
    *(s16 *)((u8 *)child + 0x4C) = 0;
    ((Obj *)child)->v8();
    *(u8 *)((u8 *)child + 0x48) = 0;
    *(u8 *)((u8 *)child + 0x44) = 0;
    Ui_BringChildToFront(panel, list);
    captionSrc = *(void **)((u8 *)arg0 + 0x68);
    panel = *(void **)((u8 *)captionSrc + 0x48);
    caption = (u32)Ui_FindChild(arg0, -0x1000, 0);
    if (caption != 0U) {
        Ui_SetWidgetText(caption, (s32)panel);
    }
}

#pragma cplusplus on
extern "C" void fn_801927DC(void *arg0) {
    void **ListWidget_GetSelected(void *);
    void *Heap_Alloc(s32);
    void Ui_AddChild(void *, void *);
    void fn_801402A0(void *, void *, s16 *, s32);
    void Ui_SlideWidgetChildMode1(void *, void *, s16 *, s32);
    void *fn_80193B60(void *, s16 *, s16 *, s32);
    void fn_8013B064(void *, void *);
    void fn_8013AD70(void *, void *);
    u64 *Item_GetFlagsPtr(void *);
    void *fn_80193950(void *, s16, s16, s32);
    void *fn_801938F8(void *, s16, s16, s32);
    void Ui_BringChildToFront(void *, void *);
    s32 Ui_ListGetSelected(void *);
    u8 fn_8014D8DC(void *);
    void TalkUi_ShowMsg(void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *, void *);
    extern u8 lbl_8028FDB0[], lbl_80292230[], lbl_8029625C[], lbl_80296150[];
    extern u8 gUnitLists[], gUiContext[], gBattleState[];
    extern f32 lbl_8036AE20;

    struct Obj {
        virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0;
        virtual void v3() = 0; virtual void v4() = 0; virtual void v5() = 0;
        virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0;
        virtual void v9() = 0; virtual void v10() = 0; virtual void v11(s32) = 0;
        virtual void v12(s32) = 0;
    };

    s16 sp1c[2], sp18[2], sp14[2], sp10[2], spc[2], sp8[2];
    void *list; void *unit; void *panel; void *p; void *q; void *walk; void *res; void *self;
    s16 x, y;

    self = arg0;
    unit = *ListWidget_GetSelected(*(void **)((u8 *)self + 0x4C));
    panel = Heap_Alloc(0x50);
    if (panel != NULL) {
        x = *(s16 *)((u8 *)self + 0x5E);
        y = *(s16 *)((u8 *)self + 0x60);
        *(void **)panel = lbl_8028FDB0;
        *(s32 *)((u8 *)panel + 4) = 0;
        *(void **)panel = lbl_80292230;
        *(s16 *)((u8 *)panel + 8) = -1;
        *(s16 *)((u8 *)panel + 0xA) = x;
        *(s16 *)((u8 *)panel + 0xC) = y;
        *(s16 *)((u8 *)panel + 0xE) = (s16)(x + 0xE8);
        *(s16 *)((u8 *)panel + 0x10) = y;
        *(s16 *)((u8 *)panel + 0x12) = 0;
        *(s16 *)((u8 *)panel + 0x14) = 0;
        *(s16 *)((u8 *)panel + 0x16) = 0xE8;
        *(s16 *)((u8 *)panel + 0x18) = 0;
        *(s16 *)((u8 *)panel + 0x1A) = 0;
        *(s16 *)((u8 *)panel + 0x1C) = 0;
        *(u8 *)((u8 *)panel + 0x1E) = 0xFF;
        *(u8 *)((u8 *)panel + 0x1F) = 0xFF;
        *(u8 *)((u8 *)panel + 0x20) = 0xFF;
        *(u8 *)((u8 *)panel + 0x21) = 0xFF;
        *(s16 *)((u8 *)panel + 0x22) = 0x32;
        *(s16 *)((u8 *)panel + 0x24) = 0;
        *(f32 *)((u8 *)panel + 0x28) = lbl_8036AE20;
        *(f32 *)((u8 *)panel + 0x2C) = lbl_8036AE20;
        *(f32 *)((u8 *)panel + 0x30) = lbl_8036AE20;
        *(s32 *)((u8 *)panel + 0x34) = 0;
        *(s32 *)((u8 *)panel + 0x38) = 0;
        *(void **)panel = lbl_8029625C;
        *(s32 *)((u8 *)panel + 0x3C) = 0;
        *(s32 *)((u8 *)panel + 0x40) = 0;
        *(u8 *)((u8 *)panel + 0x44) = 0;
        *(s16 *)((u8 *)panel + 0x46) = 0x20;
        *(u8 *)((u8 *)panel + 0x48) = 0;
        *(s16 *)((u8 *)panel + 0x4A) = 0x14;
        *(s16 *)((u8 *)panel + 0x4C) = 0;
        ((Obj *)panel)->v8();
    }
    *(s16 *)((u8 *)panel + 8) = 2;
    *(s16 *)((u8 *)panel + 0x24) = 8;
    *(s16 *)((u8 *)panel + 0x4A) = 8;
    *(s16 *)((u8 *)panel + 0x4C) = 0;
    ((Obj *)panel)->v8();
    *(void **)((u8 *)panel + 0x3C) = unit;
    *(u8 *)((u8 *)panel + 0x48) = 0;
    *(u8 *)((u8 *)panel + 0x44) = 0;
    Ui_AddChild(self, panel);
    sp1c[0] = 0x14C;
    sp1c[1] = 0x30;
    fn_801402A0(self, panel, sp1c, 0);

    q = *(void **)((u8 *)self + 0x50);
    list = q;
    if (q == NULL) {
        p = Heap_Alloc(0xD8);
        if (p != NULL) {
            sp18[0] = 0x128; sp18[1] = 0x9A;
            sp14[0] = 0x260; sp14[1] = 0x6C;
            p = fn_80193B60(p, sp14, sp18, 0x1F4);
        }
        *(void **)((u8 *)self + 0x50) = p;
        q = *(void **)((u8 *)self + 0x50);
        if (q != NULL) {
            *(s32 *)((u8 *)q + 4) += 1;
        }
        list = *(void **)((u8 *)self + 0x50);
        *(s16 *)((u8 *)list + 8) = 3;
        *(s16 *)((u8 *)list + 0x24) = 8;
        *(s16 *)((u8 *)list + 0x5A) = 0x1A;
        *(s16 *)((u8 *)list + 0x64) = 2;
        ((Obj *)list)->v12(4);
        *(s16 *)((u8 *)list + 0x58) = 2;
        for (walk = *(void **)gUnitLists; walk; walk = *(void **)((u8 *)walk + 0x184))
            fn_8013B064(list, walk);
        for (walk = *(void **)(gUnitLists + 0x3C); walk; walk = *(void **)((u8 *)walk + 0x184))
            fn_8013B064(list, walk);
        q = *(void **)gUiContext;
        if (q != NULL)
            fn_8013AD70(list, q);
    }
    *(u8 *)((u8 *)list + 0x4C) = 0;
    Ui_AddChild(self, list);
    if (*(s16 *)((u8 *)list + 0xA) != 0x118) {
        y = *(s16 *)((u8 *)list + 0xC);
        sp10[0] = 0x118; sp10[1] = y;
        Ui_SlideWidgetChildMode1(self, list, sp10, 0);
    }

    if ((*Item_GetFlagsPtr(unit) & 5ULL) != 0) {
        p = Heap_Alloc(0x78);
        if (p != NULL)
            p = fn_80193950(p, 0x260, 0x108, 0x1F4);
        *(void **)((u8 *)self + 0x54) = p;
    } else {
        p = Heap_Alloc(0x78);
        if (p != NULL)
            p = fn_801938F8(p, 0x260, 0x108, 0x1F4);
        *(void **)((u8 *)self + 0x54) = p;
    }
    q = *(void **)((u8 *)self + 0x54);
    if (q != NULL)
        *(s32 *)((u8 *)q + 4) += 1;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x54) + 8) = 5;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x54) + 0x24) = 8;
    *(u8 *)((u8 *)*(void **)((u8 *)self + 0x54) + 0x48) = 0;

    panel = Heap_Alloc(0x48);
    if (panel != NULL) {
        *(void **)panel = lbl_8028FDB0;
        *(s32 *)((u8 *)panel + 4) = 0;
        *(void **)panel = lbl_80292230;
        *(s16 *)((u8 *)panel + 8) = -1;
        *(s16 *)((u8 *)panel + 0xA) = 0x260;
        *(s16 *)((u8 *)panel + 0xC) = 0x108;
        *(s16 *)((u8 *)panel + 0xE) = 0x370;
        *(s16 *)((u8 *)panel + 0x10) = 0x188;
        *(s16 *)((u8 *)panel + 0x12) = 0;
        *(s16 *)((u8 *)panel + 0x14) = 0;
        *(s16 *)((u8 *)panel + 0x16) = 0x110;
        *(s16 *)((u8 *)panel + 0x18) = 0x80;
        *(s16 *)((u8 *)panel + 0x1A) = 0;
        *(s16 *)((u8 *)panel + 0x1C) = 0;
        *(u8 *)((u8 *)panel + 0x1E) = 0xFF;
        *(u8 *)((u8 *)panel + 0x1F) = 0xFF;
        *(u8 *)((u8 *)panel + 0x20) = 0xFF;
        *(u8 *)((u8 *)panel + 0x21) = 0xFF;
        *(s16 *)((u8 *)panel + 0x22) = 0x1F4;
        *(s16 *)((u8 *)panel + 0x24) = 0;
        *(f32 *)((u8 *)panel + 0x28) = lbl_8036AE20;
        *(f32 *)((u8 *)panel + 0x2C) = lbl_8036AE20;
        *(f32 *)((u8 *)panel + 0x30) = lbl_8036AE20;
        *(s32 *)((u8 *)panel + 0x34) = 0;
        *(s32 *)((u8 *)panel + 0x38) = 0;
        *(void **)panel = lbl_80296150;
        *(s32 *)((u8 *)panel + 0x3C) = 0;
        *(s32 *)((u8 *)panel + 0x40) = 0;
        ((Obj *)panel)->v8();
    }
    *(void **)((u8 *)self + 0x58) = panel;
    q = *(void **)((u8 *)self + 0x58);
    if (q != NULL)
        *(s32 *)((u8 *)q + 4) += 1;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x58) + 8) = 6;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x58) + 0x24) = 8;
    *(u32 *)((u8 *)*(void **)((u8 *)self + 0x58) + 0x40) = *(u32 *)unit;
    *(s32 *)((u8 *)*(void **)((u8 *)self + 0x58) + 0x3C) = 1;
    Ui_BringChildToFront(self, list);

    if (*(s16 *)((u8 *)list + 0x4E) != 0x7FFF) {
        Ui_AddChild(self, *(void **)((u8 *)self + 0x54));
        ((Obj *)*(void **)((u8 *)self + 0x54))->v11(Ui_ListGetSelected(list));
        q = *(void **)((u8 *)self + 0x54);
        if (*(s16 *)((u8 *)q + 0xA) != 0x138) {
            y = *(s16 *)((u8 *)q + 0xC);
            spc[0] = 0x138; spc[1] = y;
            Ui_SlideWidgetChildMode1(self, q, spc, 0);
        }
    } else if (fn_8014D8DC(gBattleState)) {
        Ui_AddChild(self, *(void **)((u8 *)self + 0x58));
        q = *(void **)((u8 *)self + 0x58);
        if (*(s16 *)((u8 *)q + 0xA) != 0x134) {
            y = *(s16 *)((u8 *)q + 0xC);
            sp8[0] = 0x134; sp8[1] = y;
            Ui_SlideWidgetChildMode1(self, q, sp8, 0);
        }
    }
    TalkUi_ShowMsg(*(void **)((u8 *)*(void **)((u8 *)self + 0x68) + 0x14));
    q = *(void **)((u8 *)self + 0x68);
    list = *(void **)((u8 *)q + 0x48);
    res = Ui_FindChild(self, -0x1000, 0);
    if (res != NULL)
        Ui_SetWidgetText(res, list);
}
#pragma cplusplus reset

#pragma cplusplus reset

#pragma global_optimizer reset
#pragma cplusplus reset

void fn_80192DB8(void *arg0) {
    void fn_8013F748(void *, void *, void *);
    void Ui_SlideWidgetChild(void *, void *, s16 *, s32);
    void *Ui_FindChild(void *, s32, s32);
    s16 spC[2];
    s16 sp8[2];
    void *r31;
    void *r4;
    s16 r7;

    r31 = *(void **)((u8 *)arg0 + 0x4C);
    fn_8013F748(r31, (u8 *)arg0 + 0x5E, (u8 *)r31 + 0x7C);
    r7 = *(s16 *)((u8 *)r31 + 0xC);
    spC[0] = 0x260;
    spC[1] = r7;
    Ui_SlideWidgetChild(arg0, r31, spC, 0);
    r4 = Ui_FindChild(arg0, 1, 0);
    r7 = *(s16 *)((u8 *)r4 + 0xC);
    sp8[0] = 0x260;
    sp8[1] = r7;
    Ui_SlideWidgetChild(arg0, r4, sp8, 0);
}

void fn_80192E54(void *arg0) {
    void Process_Goto(void *, s32);
    void TalkUi_ShowMsg(s32);
    u32 Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(s32, s32);
    extern u8 gUiContext[];
    s32 temp_r31;
    void *temp_r6;
    u32 result;

    switch ((s32)gUiContext[8]) {
    case 0x80:
        TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)arg0 + 0x68) + 0xC));
        temp_r6 = *(void **)((u8 *)arg0 + 0x68);
        temp_r31 = *(s32 *)((u8 *)temp_r6 + 0x44);
        result = Ui_FindChild(arg0, -0x1000, 0);
        if (result != 0U) {
            Ui_SetWidgetText(result, temp_r31);
        }
        Process_Goto(arg0, 3);
        break;
    case 0x81:
        break;
    }
}

void fn_80192EE8(void *arg0) {
    extern u8 lbl_80279DF0[];
    void *fn_8013BC10(void *, void *);
    void Ui_CreateMenu(void *, void *, s32);
    u32 Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(s32, s32);
    void *temp_r3;
    void *temp_r6;
    s32 temp_r31;
    u32 result;

    temp_r3 = fn_8013BC10(lbl_80279DF0 + 0x4EE, lbl_80279DF0 + 0x4F6);
    *(s16 *)((u8 *)temp_r3 + 8) = 0x178;
    *(s16 *)((u8 *)temp_r3 + 0xA) = 0x3C;
    *(s8 *)((u8 *)temp_r3 + 0x24) = 1;
    Ui_CreateMenu(temp_r3, arg0, 0);
    temp_r6 = *(void **)((u8 *)arg0 + 0x68);
    temp_r31 = *(s32 *)((u8 *)temp_r6 + 0x4C);
    result = Ui_FindChild(arg0, -0x1000, 0);
    if (result != 0U) {
        Ui_SetWidgetText(result, temp_r31);
    }
}

#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void Ui_HandleShopBuyCursorInput(void *arg0) {
    /* Handle shop-buy list cursor: A buy (funds check), Y unit info, B cancel. */
    void Process_Goto(void *, s32);
    void Process_ClearFunc(void *);
    void fn_8000D8BC(s32, s32);
    u32 *Item_GetFlagsPtr(void *);
    u32 UnitRef_GetValue(void *);
    void TalkUi_ShowMsg(s32);
    void Ui_UpdatePanelWidgets(void *);
    u32 Ui_FindChild(void *, s32, s32);
    s32 *ListWidget_GetSelected(void *);
    void Ui_PlaySeCue(void *, s32);
    void Ui_SetWidgetText(u32, s32);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_ShowUnitInfoPopup(void *, s32, f32, f32);
    void Ui_HideUnitInfoPopup(void *);
    void Ui_OpenUnitInfoPopup(void *, void *, s32, f32, f32);
    extern u8 lbl_80279DF0[];
    extern u8 gBattleState[];
    extern u8 gUnitInfoPopup[];
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern s32 gUnitInfoPopupFlag;

    class Pair {
    public:
        s16 x;
        s16 y;
        Pair() {}
        Pair(s16 a, s16 b) : x(a), y(b) {}
        Pair(const Pair &o) { *(u32 *)this = *(u32 *)&o; }
        Pair &operator=(const Pair &o) { *(u32 *)this = *(u32 *)&o; return *this; }
    };
    void Ui_SlideWidgetChild(void *, void *, const Pair &, s32);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual Pair getPos() = 0;
    };
    struct Child {
        u8 pad[0xC];
        s16 y;
        u8 padE[0x2E];
        s32 cost;
    };

    void *listWidget;
    s32 *entry;
    Child *child;
    void *self;
    register int btn;
    register u8 blocked;
    register int flags;
    void *unit;
    u32 *bits;
    void *owner;
    s32 saved;
    u32 msg;
    s32 val;
    u32 pos1;
    u32 pos2;
    f32 price;
    f32 scale;

    self = arg0;
    listWidget = *(void **)((u8 *)arg0 + 0x4C);
    entry = ListWidget_GetSelected(listWidget);
    *(u8 *)((u8 *)listWidget + 0x4C) = 1;
    Ui_UpdatePanelWidgets(arg0);
    if (entry != ListWidget_GetSelected(listWidget)) {
        entry = ListWidget_GetSelected(listWidget);
        if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            if (entry != NULL) {
                *(Pair *)&pos1 = ((Obj *)listWidget)->getPos();
                Ui_ShowUnitInfoPopup(gUnitInfoPopup, *entry, (f32)*(s16 *)&pos1, (f32)*((s16 *)&pos1 + 1));
            } else {
                Ui_HideUnitInfoPopup(gUnitInfoPopup);
            }
        }
    }
    child = (Child *)Ui_FindChild(arg0, 1, 0);
    val = *(s32 *)*entry;
    child->cost = val;
    flags = gUiInputFlags;
    blocked = 0;
    if ((flags & 0x10) && !(flags & 0x20)) {
        blocked = 1;
    }
    if (!blocked) {
        btn = *(s32 *)((u8 *)gPadInput + 4);
        btn = btn & (*(s32 *)((u8 *)gPadInput + 8) ^ btn);
        if ((btn & 0x100) && entry != NULL && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
              unit = (void *)*entry;
              price = (f32)(s32)(u16)UnitRef_GetValue(unit);
              scale = *(f32 *)((u8 *)self + 0x64);
              if ((s32)(scale * price) > *(s32 *)((u8 *)gBattleState + 0x18)) {
                  Ui_PlaySeCue((u8 *)lbl_80279DF0 + 0x501, 0x64);
                  TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)self + 0x68) + 0x20));
                  owner = *(void **)((u8 *)self + 0x68);
                  saved = *(s32 *)((u8 *)owner + 0x54);
                  msg = Ui_FindChild(self, -0x1000, 0);
                  if (msg != 0) Ui_SetWidgetText(msg, saved);
                  Process_Goto(self, 0xB);
              } else {
                  Ui_PlaySeCue((u8 *)lbl_80279DF0 + 0x4BC, 0x64);
                  val = (s32)(u16)UnitRef_GetValue(unit);
                  price = (f32)val;
                  scale = *(f32 *)((u8 *)self + 0x64);
                  fn_8000D8BC(0, (s32)(scale * price));
                  TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)self + 0x68) + 0x10));
                  Process_ClearFunc(self);
              }
        } else if ((btn & 0x800) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0 && entry != NULL) {
            *(Pair *)&pos2 = ((Obj *)listWidget)->getPos();
            Ui_OpenUnitInfoPopup(gUnitInfoPopup, self, *entry, (f32)*(s16 *)&pos2, (f32)*((s16 *)&pos2 + 1));
            *(s32 *)gUnitInfoPopup = *(s32 *)gUnitInfoPopup | gUnitInfoPopupFlag;
        } else if ((btn & 0xa00) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            Ui_HideUnitInfoPopup(gUnitInfoPopup);
        } else if ((btn & 0x200) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            *(u8 *)((u8 *)listWidget + 0x4C) = 0;
            Ui_SlideWidgetChild(self, child, Pair(0x260, child->y), 0);
            Process_Goto(self, 0x11);
            Ui_PlaySeCue((u8 *)lbl_80279DF0 + 0x4DE, 0x64);
        }
    }
}

extern "C" void fn_80193344(void *arg0) {
    void *Ui_FindChild(void *, s32, s32);
    void Ui_AddChild(void *, void *);
    void Ui_SlideWidgetChildMode1(void *, void *, s16 *, s32);
    void *Heap_Alloc(u32);
    void *ListWidget_GetSelected(void *);
    void Ui_BringChildToFront(void *, void *);
    void Ui_SetWidgetText(void *, void *);
    extern u8 lbl_8028FDB0[];
    extern u8 lbl_80292230[];
    extern u8 lbl_802961F4[];
    struct { s16 x; s16 y; } spC;
    struct { s16 x; s16 y; } sp8;
    void *p;
    void *obj;
    void *msg;
    s16 tmp;
    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
    };

    
    obj = Ui_FindChild(arg0, 0, 0);
    if (obj == NULL) {
        obj = M2C_FIELD(arg0, void **, 0x4C);
        Ui_AddChild(arg0, obj);
    }
    if (M2C_FIELD(obj, s16 *, 0xA) != 0x108) {
        register int tmp = M2C_FIELD(obj, s16 *, 0xC);
        spC.x = 0x108;
        spC.y = tmp;
        Ui_SlideWidgetChildMode1(arg0, obj, &spC.x, 0);
    }
    if (Ui_FindChild(arg0, 1, 0) == NULL) {
        p = Heap_Alloc(0x44);
        if (p != NULL) {
            M2C_FIELD(p, void **, 0) = lbl_8028FDB0;
            M2C_FIELD(p, void **, 0) = lbl_80292230;
            M2C_FIELD(p, u32 *, 4) = 0;
            M2C_FIELD(p, s16 *, 8) = -1;
            M2C_FIELD(p, s16 *, 0xA) = 0x260;
            M2C_FIELD(p, s16 *, 0xC) = 0x148;
            M2C_FIELD(p, s16 *, 0xE) = 0x349;
            M2C_FIELD(p, s16 *, 0x10) = 0x18F;
            M2C_FIELD(p, s16 *, 0x12) = 0;
            M2C_FIELD(p, s16 *, 0x14) = 0;
            M2C_FIELD(p, s16 *, 0x16) = 0xE9;
            M2C_FIELD(p, s16 *, 0x18) = 0x47;
            M2C_FIELD(p, s16 *, 0x1A) = 0;
            M2C_FIELD(p, s16 *, 0x1C) = 0;
            M2C_FIELD(p, u8 *, 0x1E) = 0xFF;
            M2C_FIELD(p, u8 *, 0x1F) = 0xFF;
            M2C_FIELD(p, u8 *, 0x20) = 0xFF;
            M2C_FIELD(p, u8 *, 0x21) = 0xFF;
            M2C_FIELD(p, s16 *, 0x22) = 0x1F4;
            M2C_FIELD(p, s16 *, 0x24) = 0;
            M2C_FIELD(p, f32 *, 0x28) = 1.0f;
            M2C_FIELD(p, f32 *, 0x2C) = 1.0f;
            M2C_FIELD(p, f32 *, 0x30) = 1.0f;
            M2C_FIELD(p, u32 *, 0x34) = 0;
            M2C_FIELD(p, u32 *, 0x38) = 0;
            M2C_FIELD(p, void **, 0) = lbl_802961F4;
            M2C_FIELD(p, u32 *, 0x3C) = 0;
            ((Obj *)p)->v8();
        }
        M2C_FIELD(p, s16 *, 8) = 1;
        M2C_FIELD(p, s16 *, 0x24) = 8;
            M2C_FIELD(p, u32 *, 0x3C) = *(u32 *)(*(void **)ListWidget_GetSelected(obj));
        Ui_AddChild(arg0, p);
        tmp = M2C_FIELD(p, s16 *, 0xC);
        sp8.x = 0x158;
        sp8.y = tmp;
        Ui_SlideWidgetChildMode1(arg0, p, &sp8.x, 0);
    }
    Ui_BringChildToFront(arg0, obj);
    msg = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), void **, 0x44);
    p = Ui_FindChild(arg0, -0x1000, 0);
    if (p != NULL) {
        Ui_SetWidgetText(p, msg);
    }
}

#pragma use_lmw_stmw reset
#pragma cplusplus reset

void fn_80193540(void *self) {
    void *Heap_Alloc(s32);
    void *fn_80193BB8(void *,s32,s32,s32,s32,s32);
    void fn_801439F0(void *,void *,s32);
    void fn_80143570(void *);
    void Ui_AddChild(void *,void *);
    void fn_8011D908(s32,void *);
    void *Ui_FindChild(void *,s32,s32);
    void Ui_SetWidgetText(void *,s32);
    void *tmp;
    void *node;
    void *end;
    void *p;
    void *owner;

    owner = self;
    tmp = Heap_Alloc(0x12C);
    if (tmp) {
        tmp = fn_80193BB8(tmp, 0x108, 0x6C, 0x138, 0xD8, 0x1F4);
    }
    *(void **)((u8 *)owner + 0x4C) = tmp;
    tmp = *(void **)((u8 *)owner + 0x4C);
    if (tmp) {
        *(s32 *)((u8 *)tmp + 4) = *(s32 *)((u8 *)tmp + 4) + 1;
    }
    p = *(void **)((u8 *)owner + 0x4C);
    *(s16 *)((u8 *)p + 8) = 0;
    *(s16 *)((u8 *)p + 0x24) = 8;
    *(s16 *)((u8 *)p + 0x8A) = 2;
    *(f32 *)((u8 *)p + 0x128) = *(f32 *)((u8 *)owner + 0x64);
    node = *(void **)((u8 *)owner + 0x48);
    end = (u8 *)owner + 0x44;
    while (node != end) {
        fn_801439F0(p, (u8 *)node + 8, 0);
        node = *(void **)((u8 *)node + 4);
    }
    fn_80143570(p);
    *(u8 *)((u8 *)p + 0x4C) = 0;
    Ui_AddChild(owner, p);
    fn_8011D908(*(s32 *)((u8 *)*(void **)((u8 *)owner + 0x68) + 4), owner);
    node = (void *)*(s32 *)((u8 *)*(void **)((u8 *)owner + 0x68) + 0x50);
    tmp = Ui_FindChild(owner, -0x1000, 0);
    if (tmp) {
        Ui_SetWidgetText(tmp, (s32)node);
    }
}

void fn_80193668(void *arg0) {
    void *Heap_Alloc(s32);
    void String_AssignCStr(void *, char *, u32);
    void Ui_AddChild(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(u32, s32);
    s32 Item_GetByIid(void *);
    void Allegiance_FillMask(s32, void *);
    s8 Unit_FindItemSlot(void *, s32);
    s32 fn_800C39A4(void *, s32);
    extern u8 lbl_8028FDB0[];
    extern u8 lbl_80292230[];
    extern u8 lbl_80293C84[];
    extern u8 lbl_80293C58[];
    extern u8 lbl_80279DF0[];
    extern u8 gUnits[];
    extern u8 gConvoy[];
    extern f32 lbl_8036AE20;
    extern f32 lbl_8036AE30;
    u8 sp8[8];
    void *unit;
    s32 i;
    s32 key;
    u8 found;
    void *obj;
    void *self;

    self = arg0;
    obj = Heap_Alloc(0x5C);
    if (obj != NULL) {
        *(void **)obj = lbl_8028FDB0;
        *(s32 *)((u8 *)obj + 4) = 0;
        *(void **)obj = lbl_80292230;
        *(s16 *)((u8 *)obj + 8) = -1;
        *(s16 *)((u8 *)obj + 0xA) = 0;
        *(s16 *)((u8 *)obj + 0xC) = 0x190;
        *(s16 *)((u8 *)obj + 0xE) = 0x260;
        *(s16 *)((u8 *)obj + 0x10) = 0x1C0;
        *(s16 *)((u8 *)obj + 0x12) = 0;
        *(s16 *)((u8 *)obj + 0x14) = 0;
        *(s16 *)((u8 *)obj + 0x16) = 0x260;
        *(s16 *)((u8 *)obj + 0x18) = 0x30;
        *(s16 *)((u8 *)obj + 0x1A) = 0;
        *(s16 *)((u8 *)obj + 0x1C) = 0;
        *(u8 *)((u8 *)obj + 0x1E) = 0xFF;
        *(u8 *)((u8 *)obj + 0x1F) = 0xFF;
        *(u8 *)((u8 *)obj + 0x20) = 0xFF;
        *(u8 *)((u8 *)obj + 0x21) = 0xFF;
        *(s16 *)((u8 *)obj + 0x22) = 0x5A;
        *(s16 *)((u8 *)obj + 0x24) = 0;
        *(f32 *)((u8 *)obj + 0x28) = 1.0f;
        *(f32 *)((u8 *)obj + 0x2C) = 1.0f;
        *(f32 *)((u8 *)obj + 0x30) = 1.0f;
        *(s32 *)((u8 *)obj + 0x34) = 0;
        *(s32 *)((u8 *)obj + 0x38) = 0;
        *(void **)obj = lbl_80293C84;
        *(s32 *)((u8 *)obj + 0x3C) = 0;
        *(s32 *)((u8 *)obj + 0x40) = 0;
        *(s32 *)((u8 *)obj + 0x44) = 0;
        *(s32 *)((u8 *)obj + 0x40) = 0;
        *(s32 *)((u8 *)obj + 0x48) = 0;
        *(u8 *)((u8 *)obj + 0x4C) = 1;
        *(s16 *)((u8 *)obj + 0x4E) = 0;
        *(s16 *)((u8 *)obj + 0x50) = 0;
        *(s16 *)((u8 *)obj + 0x52) = 0;
        *(s16 *)((u8 *)obj + 0x54) = 0;
        *(void **)obj = lbl_80293C58;
        *(s32 *)((u8 *)obj + 0x58) = 1;
        *(s16 *)((u8 *)obj + 0x4E) = 0x30;
        *(s16 *)((u8 *)obj + 0x52) = 0x30;
    }
    *(s16 *)((u8 *)obj + 8) = -0x1000;
    *(s32 *)((u8 *)obj + 0x48) = 1;
    String_AssignCStr((u8 *)obj + 0x3C, (char *)((u32)lbl_80279DF0 + 0x50F), strlen((char *)((u8 *)lbl_80279DF0 + 0x50F)));
    *(s32 *)((u8 *)obj + 0x34) |= 0x10;
    *(s32 *)((u8 *)obj + 0x58) = 1;
    Ui_AddChild(self, obj);
    key = *(s32 *)((u8 *)*(void **)((u8 *)self + 0x68) + 0x50);
    obj = Ui_FindChild(self, -0x1000, 0);
    if (obj != NULL) {
        Ui_SetWidgetText((u32)obj, key);
    }
    found = 0;
    *(f32 *)((u8 *)self + 0x64) = lbl_8036AE20;
    key = Item_GetByIid(lbl_80279DF0 + 0x510);
    Allegiance_FillMask(4, sp8);
    for (i = 1; i <= 0x9F; i++) {
        if ((u8)i != 0) {
            unit = gUnits + ((u8)i - 1) * 0x280;
        } else {
            unit = NULL;
        }
        if (*(u32 *)((u8 *)unit + 0x188) != 0 &&
            sp8[*(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)] != 0 &&
            (s8)Unit_FindItemSlot(unit, key) >= 0) {
            found = 1;
            break;
        }
    }
    if (found == 0) {
        if (fn_800C39A4(gConvoy, key) >= 0) {
            found = 1;
        }
    }
    if (found != 0) {
        *(f32 *)((u8 *)self + 0x64) *= lbl_8036AE30;
    }
}

#pragma cplusplus on
extern "C" void *fn_801938F8(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    struct Obj {
        virtual void m08() = 0;
        virtual void m0C() = 0;
        virtual void m10() = 0;
        virtual void m14() = 0;
        virtual void m18() = 0;
        virtual void m1C() = 0;
        virtual void m20() = 0;
        virtual void m24() = 0;
        virtual void m28() = 0;
    };
    void *fn_80193950(void *, s16, s16, s16);
    fn_80193950(arg0, arg1, arg2, arg3);
    *(void **)((u8 *)arg0 + 0x0) = (void *)lbl_8029656C;
    *(s32 *)((u8 *)arg0 + 0x60) = 2;
    ((Obj *) arg0)->m28();
    return arg0;
}


extern "C" void *fn_80193950(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    void fn_80142060(void *);
    extern u8 lbl_8028FDB0[];
    extern u8 lbl_80292230[];
    extern u8 lbl_80292208[];
    extern u8 lbl_80293BB8[];
    extern u8 lbl_80293B74[];
    extern f32 lbl_8036AE20;
    struct Obj {
        virtual void m08() = 0;
        virtual void m0C() = 0;
        virtual void m10() = 0;
        virtual void m14() = 0;
        virtual void m18() = 0;
        virtual void m1C() = 0;
        virtual void m20() = 0;
        virtual void m24() = 0;
        virtual void m28() = 0;
    };
    s32 z = 0;
    
    void *self = arg0;
    s32 e2 = (s16)arg2;
    s32 e1 = (s16)arg1;

    *(void **)self = lbl_8028FDB0;
    *(s32 *)((u8 *)self + 4) = z;
    *(void **)self = lbl_80292230;
    *(s16 *)((u8 *)self + 8) = -1;
    *(s16 *)((u8 *)self + 0xA) = arg1;
    *(s16 *)((u8 *)self + 0xC) = arg2;
    *(s16 *)((u8 *)self + 0xE) = (s16)(e1 + 0x108);
    *(s16 *)((u8 *)self + 0x10) = (s16)(e2 + 0x88);
    *(s16 *)((u8 *)self + 0x12) = z;
    *(s16 *)((u8 *)self + 0x14) = z;
    *(s16 *)((u8 *)self + 0x16) = 0x108;
    *(s16 *)((u8 *)self + 0x18) = 0x88;
    *(s16 *)((u8 *)self + 0x1A) = z;
    *(s16 *)((u8 *)self + 0x1C) = z;
    *(u8 *)((u8 *)self + 0x1E) = 0xFF;
    *(u8 *)((u8 *)self + 0x1F) = 0xFF;
    *(u8 *)((u8 *)self + 0x20) = 0xFF;
    *(u8 *)((u8 *)self + 0x21) = 0xFF;
    *(s16 *)((u8 *)self + 0x22) = arg3;
    *(s16 *)((u8 *)self + 0x24) = z;
    *(f32 *)((u8 *)self + 0x28) = lbl_8036AE20;
    *(f32 *)((u8 *)self + 0x2C) = lbl_8036AE20;
    *(f32 *)((u8 *)self + 0x30) = lbl_8036AE20;
    *(s32 *)((u8 *)self + 0x34) = z;
    *(s32 *)((u8 *)self + 0x38) = z;
    *(void **)self = lbl_80292208;
    fn_80142060((u8 *)arg0 + 0x3C);

    *(void **)self = lbl_80293BB8;
    *(u8 *)((u8 *)self + 0x48) = 1;
    *(u8 *)((u8 *)self + 0x49) = 0;
    *(u8 *)((u8 *)self + 0x4A) = 1;
    *(u8 *)((u8 *)self + 0x4B) = 0;
    *(s16 *)((u8 *)self + 0x50) = -1;
    *(s16 *)((u8 *)self + 0x52) = -1;
    *(s16 *)((u8 *)self + 0x54) = 0x20;
    *(s32 *)((u8 *)self + 0x58) = 0;
    *(s32 *)((u8 *)self + 0x5C) = 0;
    *(s32 *)((u8 *)self + 0x60) = 3;
    *(s16 *)((u8 *)self + 0x64) = 0x14;
    *(s16 *)((u8 *)self + 0x66) = 0;
    *(s32 *)((u8 *)self + 0x70) = 0;
    ((Obj *)self)->m28();

    *(void **)self = lbl_80293B74;
    *(s16 *)((u8 *)self + 0x64) = 0x18;
    *(s16 *)((u8 *)self + 0x66) = 0xA;
    *(s16 *)((u8 *)self + 0x54) = 0x1C;
    *(s32 *)((u8 *)self + 0x60) = 1;
    ((Obj *)self)->m28();
    return self;
}

#pragma cplusplus reset

void *fn_80193AF0(void *arg0, s16 arg1) {
    M2C_UNK fn_80165100(void *, s32);
    M2C_UNK Heap_Free(void *);
    extern u8 lbl_8029656C[];
    extern u8 lbl_80293B74[];

    if (arg0 != NULL) {
        M2C_FIELD(arg0, void **, 0) = lbl_8029656C;
        if (arg0 != NULL) {
            M2C_FIELD(arg0, void **, 0) = lbl_80293B74;
            fn_80165100(arg0, 0);
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

#pragma cplusplus on
extern "C" void *fn_80193B60(void *arg0) {
    struct Obj {
        virtual void m08() = 0;
        virtual void m0C() = 0;
        virtual void m10() = 0;
        virtual void m14() = 0;
        virtual void m18() = 0;
        virtual void m1C() = 0;
        virtual void m20() = 0;
        virtual void m24() = 0;
        virtual void m28() = 0;
    };
    fn_8017A000(arg0);
    *(void **)((u8 *)arg0 + 0x0) = (void *)gUiPanelVtbl;
    *(s16 *)((u8 *)arg0 + 0xD4) = 1;
    ((Obj *) arg0)->m28();
    return arg0;
}
#pragma cplusplus reset

void *fn_80193BB8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void fn_80179BC8(void *);
    extern u8 lbl_80292358[];
    extern f32 lbl_8036AE20;
    f32 f;

    fn_80179BC8(arg0);
    f = lbl_8036AE20;
    *(u8 **)((u8 *)arg0 + 0x0) = lbl_80292358;
    *(f32 *)((u8 *)arg0 + 0x128) = f;
    *(s16 *)((u8 *)arg0 + 0x88) = 0xC;
    *(s16 *)((u8 *)arg0 + 0x8A) = 0;
    *(s16 *)((u8 *)arg0 + 0x80) = (arg4 - (M2C_FIELD(arg0, s16 *, 0x8A) + 0xC)) / 32;
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x48) + 0x48) = 2;
    return arg0;
}

void ItemList_EraseRange(void **out, s32 *count, void **p_cur, void **p_end) {
    void Item_Destroy(void *, s32);
    void Heap_Free(void *);
    register void *cur;
    void *end;
    void *a;
    void *b;

    cur = *p_cur;
    end = *p_end;
    if (cur == end) {
        *out = end;
        return;
    }
    a = *(void **)end;
    b = *(void **)cur;
    *(void **)((u8 *)b + 4) = *(void **)((u8 *)a + 4);
    *(void **)(*(void **)((u8 *)a + 4)) = *(void **)cur;

    goto check;
    do {
        Item_Destroy((u8 *)*p_cur + 8, -1);
        cur = *p_cur;
        *p_cur = *(void **)((u8 *)cur + 4);
        Heap_Free(cur);
        *count -= 1;
    check:
        cur = *p_cur;
        end = *p_end;
    } while (cur != end);
    *out = end;
}

#pragma cplusplus on
/* Clone item into a new node and insert it before pos in the item list. */
extern "C" void ItemList_Insert(void *outNode, void *list, void *posRef, void *item) {
    void *Heap_Alloc(s32);
    void Heap_Free(void *);
    void Item_Clone(void *, void *);
    void fprintf(void *, void *, ...);
    void abort(void);
    extern char __files[];
    extern char lbl_80279DF0[];
    struct Node {
        Node *prev;
        Node *next;
        u8 value[8];
    };
    struct Holder {
        void *list;
        Node *node;
        Holder(void *l, Node *n) : list(l), node(n) {}
        ~Holder() {
            if (node != 0) {
                Heap_Free(node);
            }
        }
    };
    Node *node;
    Node *pos;
    Node *n;
    void *listPtr;

    listPtr = (s32 *)list + 1;
    node = (Node *)Heap_Alloc(0x10);
    if (node == 0) {
        fprintf(__files + 0xA0, lbl_80279DF0 + 0x51F, __files);
        abort();
    }
    {
        Holder h(listPtr, node);
        if (&h.node->value[0] != 0) {
            Item_Clone(&h.node->value[0], item);
        }
        pos = *(Node **)posRef;
        n = h.node;
        h.node = 0;
        pos->prev->next = n;
        n->prev = pos->prev;
        pos->prev = n;
        n->next = pos;
        (*(s32 *)list)++;
        *(void **)outNode = n;
    }
}
#pragma cplusplus reset

int ItemList_Init(void *arg0) {
    u32 *ptr;

    ptr = (u32 *)((u8 *)arg0 + 0x4);
    *(u32 *)arg0 = 0;
    ptr[1] = (u32)ptr;
    ptr[0] = (u32)ptr;
}

void *fn_80193DD8(u32 arg0) {
    void *Process_CreateChild(void *, u32);
    void *Process_Create(void *, u32);
    void fn_801403F0(void *);
    extern u8 lbl_802965C0[];
    extern u8 lbl_80296674[];
    void *var_r31;

    if (arg0 != 0U) {
        var_r31 = Process_CreateChild(lbl_802965C0, arg0);
    } else {
        var_r31 = Process_Create(lbl_802965C0, arg0);
    }
    if (var_r31 != NULL) {
        fn_801403F0(var_r31);
        *(s32 *)((u8 *)var_r31 + 0x40) = 0;
        *(u8 **)((u8 *)var_r31 + 0x44) = lbl_80296674;
    }
    return var_r31;
}

void fn_80193E58(void) {

}

void fn_80193E5C(void) {
    void Unit_ApplyTransform(void *);
    extern u8 gUiContext[];
    Unit_ApplyTransform(*(void **)(gUiContext + 4));
}

void fn_80193E88(void *arg0) {
    u8 Status_Test(void *, s32);
    u8 fn_80091D74(void *);
    void fn_8003C15C(void *);
    void Process_Goto(void *, s32);
    void fn_80183BE4(void *, void *);
    extern u8 gUiContext[];
    void *obj;
    u8 flags;

    flags = 0;
    obj = *(void **)(gUiContext + 4);
    if (Status_Test((u8 *)obj + 0x1BC, 9) != 0) {
        flags |= 1;
    }
    if (fn_80091D74(obj) != 0) {
        flags |= 2;
    }
    switch ((s32)flags) {
    case 3:
        fn_8003C15C(obj);
        Process_Goto(arg0, 6);
        break;
    case 0:
    case 1:
    case 2:
    default:
        fn_80183BE4(obj, arg0);
        break;
    }
}

void fn_80193F3C(void) {
    M2C_UNK fn_8013FE0C();
    fn_8013FE0C();
}

#pragma cplusplus on
extern "C" void Ui_DtorPanelBase(void *, s32);
extern "C" void fn_80193F5C(void *arg0) {
    extern u16 gUiPanelFlags;
    struct Obj {
        virtual void destroy(s32) = 0;
        s32 refcount;
    };
    Obj *obj;

    gUiPanelFlags &= ~0x10;
    if (arg0 != NULL) {
        obj = *(Obj **)((u8 *)arg0 + 0x40);
        if (obj != NULL) {
            if (--obj->refcount == 0 && obj != NULL) {
                obj->destroy(1);
            }
            *(Obj **)((u8 *)arg0 + 0x40) = (Obj *)0;
        }
        Ui_DtorPanelBase(arg0, 0);
    }
}

extern "C" void fn_80193FE0(void *arg0)
{
    extern u32 gUiInputFlags;
    extern u8 *gPadInput;
    extern u8 lbl_8027A360[];

    extern void Ui_PlaySeCue(void *, s32);
    extern void Process_ClearFunc(void *);

    u32 flags;
    u32 active;
    u32 value;
    u32 previous;
    u8 *state;
    u8 *obj;

    obj = (u8 *)arg0;

    active = 0;
    flags = gUiInputFlags;

    if ((flags & 0x10) && !(flags & 0x20)) {
        active = 1;
    }

    if ((u8)active == 0) {
        state = gPadInput;

        value = *(u32 *)(state + 0x04);
        previous = *(u32 *)(state + 0x08);

        if ((value & (previous ^ value) & 0x300) != 0) {
            Ui_PlaySeCue(lbl_8027A360 + 0x17C, 0x64);
            Process_ClearFunc(obj);
        }
    }
}

#pragma cplusplus reset
void fn_80194064(void *arg0) {
    void TalkUi_ShowMsg(s32);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *, s32);
    void *inner;
    s32 saved;
    void *ret;

    TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0x20));
    inner = *(void **)((u8 *)arg0 + 0x44);
    saved = *(s32 *)((u8 *)inner + 0x34);
    ret = Ui_FindChild(arg0, -0x1000, 0);
    if (ret != NULL) {
        Ui_SetWidgetText(ret, saved);
    }
}

void fn_801940C0(void *arg0) {
    s32 Ui_FindChild(void *, s32, s32);
    void Ui_BringChildToFront(void *, s32);
    void TalkUi_ShowMsg(void *);
    void Ui_PlaySeCue(void *, s32);
    void Process_ClearFunc(void *);
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern u8 lbl_8027A360[];
    u8 flag;
    u32 a;
    u32 b;

    Ui_BringChildToFront(arg0, Ui_FindChild(arg0, -0x1000, 0));
    flag = 0;
    if ((gUiInputFlags & 0x10) != 0 && (gUiInputFlags & 0x20) == 0) {
        flag = 1;
    }
    if (flag == 0) {
        a = *(u32 *)((u8 *)gPadInput + 4);
        b = *(u32 *)((u8 *)gPadInput + 8);
        if ((a & (b ^ a) & 0x300) != 0) {
            Ui_BringChildToFront(arg0, *(s32 *)((u8 *)arg0 + 0x40));
            TalkUi_ShowMsg(*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x44) + 0x1C));
            Ui_PlaySeCue(lbl_8027A360 + 0x17C, 0x64);
            Process_ClearFunc(arg0);
        }
    }
}

void fn_80194174(void) {

}

#pragma cplusplus on
#pragma scheduling off
void fn_80194178(void *arg0) {
    void Process_Goto(void *, s32);
    void Process_CreateChild(void *, void *, void *);
    void *Item_GetFlagsPtr(void *);
    u32 UnitRef_GetValue(void *);
    void Item_Clear(void *);
    void Unit_CompactItems(void *);
    void TalkUi_ShowMsg(s32);
    u32 Ui_FindChild(void *, s32, s32);
    void fn_80143570(void *);
    void fn_801436AC(void *, void *);
    void fn_80143784(void *, void *);
    void *ListWidget_GetSelected(void *);
    void fn_80143C9C(void *);
    void fn_8014D268(void *, s32, s32);
    void Ui_SetWidgetText(u32, s32);
    void Mu_StartBlend(void *, s32, s32, s32);
    extern u8 lbl_802966B0[];
    extern u8 gUiContext[];
    extern u8 gBattleState[];
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12(void *) = 0;
    };
    void *temp_r31;
    void *temp_r30;
    void *temp_r29;
    void *temp_r3;
    s32 temp_r5;
    s32 saved;
    void *temp_r6;
    u32 result;
    u64 flags;
    u8 t;
    s32 zero;

    switch ((s32)gUiContext[8]) {
    case 0x81:
        temp_r29 = *(void **)((u8 *)arg0 + 0x40);
        temp_r3 = ListWidget_GetSelected(temp_r29);
        temp_r31 = *(void **)temp_r3;
        temp_r30 = *(void **)((u8 *)temp_r3 + 4);
        temp_r5 = (s32)((UnitRef_GetValue(temp_r31) >> 1) & 0x7FFFu);
        fn_8014D268(gBattleState, *(s32 *)(gBattleState + 0x18) + temp_r5, temp_r5);
        ((Obj *)temp_r29)->v12(temp_r31);
        if (__rlwinm(*(u8 *)((u8 *)temp_r31 + 5), 25, 31, 31)) {
            flags = *(u64 *)Item_GetFlagsPtr(temp_r31);
            if ((flags & 0x100000000ULL) != 0
                && (*(s32 *)((u8 *)temp_r30 + 0x1A0) & 0x800000) != 0) {
                t = *(u8 *)((u8 *)temp_r31 + 5);
                zero = 0;
                *(u8 *)((u8 *)temp_r31 + 5) = (u8)__rlwimi(t, zero, 7, 24, 24);
                *(void **)(gUiContext + 4) = temp_r30;
                Process_CreateChild(lbl_802966B0, arg0, gUiContext);
            }
        }
        Item_Clear(temp_r31);
        if (temp_r30 != NULL) {
            Unit_CompactItems(temp_r30);
            fn_80143784(temp_r29, temp_r30);
            Mu_StartBlend(temp_r30, 0, 2, 0);
        } else {
            fn_801436AC(temp_r29, temp_r31);
        }
        fn_80143570(temp_r29);
        fn_80143C9C(temp_r29);
        TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0xC));
        temp_r6 = *(void **)((u8 *)arg0 + 0x44);
        saved = *(s32 *)((u8 *)temp_r6 + 0x24);
        result = Ui_FindChild(arg0, -0x1000, 0);
        if (result != 0U) {
            Ui_SetWidgetText(result, saved);
        }
        Process_Goto(arg0, 3);
        break;
    case 0x80:
        TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0x10));
        temp_r6 = *(void **)((u8 *)arg0 + 0x44);
        saved = *(s32 *)((u8 *)temp_r6 + 0x24);
        result = Ui_FindChild(arg0, -0x1000, 0);
        if (result != 0U) {
            Ui_SetWidgetText(result, saved);
        }
        Process_Goto(arg0, 3);
        break;
    }
}
#pragma scheduling reset
#pragma cplusplus reset

void fn_80194374(void *arg0) {
    extern u8 lbl_8027A360[];
    void *fn_8013BC10(void *, void *);
    void Ui_CreateMenu(void *, void *, s32);
    u32 Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(s32, s32);
    void *temp_r3;
    void *temp_r6;
    s32 temp_r31;
    u32 result;

    temp_r3 = fn_8013BC10(lbl_8027A360 + 0x18C, lbl_8027A360 + 0x195);
    *(s16 *)((u8 *)temp_r3 + 8) = 0x178;
    *(s16 *)((u8 *)temp_r3 + 0xA) = 0x3C;
    *(s8 *)((u8 *)temp_r3 + 0x24) = 1;
    Ui_CreateMenu(temp_r3, arg0, 0);
    temp_r6 = *(void **)((u8 *)arg0 + 0x44);
    temp_r31 = *(s32 *)((u8 *)temp_r6 + 0x28);
    result = Ui_FindChild(arg0, -0x1000, 0);
    if (result != 0U) {
        Ui_SetWidgetText(result, temp_r31);
    }
}

#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void Ui_HandleUnitListCursorInput(void *arg0) {
    /* Handle unit-list cursor: A select (blocked-unit check), Y unit info, B cancel. */
    void Process_Goto(void *, s32);
    void Process_ClearFunc(void *);
    void fn_8000D8BC(s32, s32);
    u32 *Item_GetFlagsPtr(void *);
    u32 UnitRef_GetValue(void *);
    void TalkUi_ShowMsg(s32);
    void Ui_UpdatePanelWidgets(void *);
    u32 Ui_FindChild(void *, s32, s32);
    s32 *ListWidget_GetSelected(void *);
    void Ui_PlaySeCue(void *, s32);
    void Ui_SetWidgetText(u32, s32);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_ShowUnitInfoPopup(void *, s32, f32, f32);
    void Ui_HideUnitInfoPopup(void *);
    void Ui_OpenUnitInfoPopup(void *, void *, s32, f32, f32);
    extern u8 lbl_8027A360[];
    extern u8 gUnitInfoPopup[];
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern s32 gUnitInfoPopupFlag;

    class Pair {
    public:
        s16 x;
        s16 y;
        Pair() {}
        Pair(s16 a, s16 b) : x(a), y(b) {}
        Pair(const Pair &o) { *(u32 *)this = *(u32 *)&o; }
        Pair &operator=(const Pair &o) { *(u32 *)this = *(u32 *)&o; return *this; }
    };
    void Ui_SlideWidgetChild(void *, void *, const Pair &, s32);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual void v12() = 0;
        virtual Pair getPos() = 0;
    };
    struct Child {
        u8 pad[0xC];
        s16 y;
        u8 padE[0x2E];
        s32 value;
    };

    void *listWidget;
    s32 *selected;
    Child *child;
    void *self;
    register int btn;
    register u8 blocked;
    register int flags;
    void *unit;
    u32 *bits;
    void *nest;
    s32 saved;
    u32 ret;
    s32 val;
    u32 pos1;
    u32 pos2;

    self = arg0;
    listWidget = *(void **)((u8 *)arg0 + 0x40);
    selected = ListWidget_GetSelected(listWidget);
    *(u8 *)((u8 *)listWidget + 0x4C) = 1;
    Ui_UpdatePanelWidgets(arg0);
    if (selected != ListWidget_GetSelected(listWidget)) {
        selected = ListWidget_GetSelected(listWidget);
        if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            if (selected != NULL) {
                *(Pair *)&pos1 = ((Obj *)listWidget)->getPos();
                Ui_ShowUnitInfoPopup(gUnitInfoPopup, *selected, (f32)*(s16 *)&pos1, (f32)*((s16 *)&pos1 + 1));
            } else {
                Ui_HideUnitInfoPopup(gUnitInfoPopup);
            }
        }
    }
    child = (Child *)Ui_FindChild(arg0, 1, 0);
    if (selected != NULL) {
        val = *(s32 *)*selected;
    } else {
        val = 0;
    }
    child->value = val;
    flags = gUiInputFlags;
    blocked = 0;
    if ((flags & 0x10) && !(flags & 0x20)) {
        blocked = 1;
    }
    if (!blocked) {
        btn = *(s32 *)((u8 *)gPadInput + 4);
        btn = btn & (*(s32 *)((u8 *)gPadInput + 8) ^ btn);
        if ((btn & 0x100) && selected != NULL && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            unit = (void *)*selected;
            Ui_PlaySeCue((u8 *)lbl_8027A360 + 0x1a0, 0x64);
            bits = Item_GetFlagsPtr(unit);
            if ((*(u64 *)bits & 0x20000000000ULL) != 0) {
                TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)self + 0x44) + 0x18));
                nest = *(void **)((u8 *)self + 0x44);
                saved = *(s32 *)((u8 *)nest + 0x30);
                ret = Ui_FindChild(self, -0x1000, 0);
                if (ret != 0) {
                    Ui_SetWidgetText(ret, saved);
                }
                Process_Goto(self, 5);
            } else {
                fn_8000D8BC(0, (s32)((UnitRef_GetValue(unit) >> 1) & 0x7FFF));
                TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)self + 0x44) + 0x14));
                Process_ClearFunc(self);
            }
        } else if ((btn & 0x800) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0 && selected != NULL) {
            *(Pair *)&pos2 = ((Obj *)listWidget)->getPos();
            Ui_OpenUnitInfoPopup(gUnitInfoPopup, self, *selected, (f32)*(s16 *)&pos2, (f32)*((s16 *)&pos2 + 1));
            *(s32 *)gUnitInfoPopup = *(s32 *)gUnitInfoPopup | gUnitInfoPopupFlag;
        } else if ((btn & 0xa00) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            Ui_HideUnitInfoPopup(gUnitInfoPopup);
        } else if ((btn & 0x200) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            *(u8 *)((u8 *)listWidget + 0x4C) = 0;
            Ui_SlideWidgetChild(self, child, Pair(0x260, child->y), 0);
            Process_Goto(self, 6);
            Ui_PlaySeCue((u8 *)lbl_8027A360 + 0x1b0, 0x64);
        }
    }
}
#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_8019477C(void *arg0) {
    void *Ui_FindChild(void *, s32, s32);
    void Ui_AddChild(void *, void *);
    void Ui_SlideWidgetChildMode1(void *, void *, s16 *, s32);
    void *Heap_Alloc(u32);
    void *ListWidget_GetSelected(void *);
    void Ui_BringChildToFront(void *, void *);
    void Ui_SetWidgetText(void *, void *);
    extern u8 lbl_8028FDB0[];
    extern u8 lbl_80292230[];
    extern u8 lbl_802961F4[];
    extern const f32 lbl_8036AE40;
    struct { s16 x; s16 y; } spC;
    struct { s16 x; s16 y; } sp8;
    void *p;
    void *obj;
    void *msg;
    s16 tmp;
    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
    };

    p = NULL;
    obj = Ui_FindChild(arg0, 0, 0);
    if (obj == NULL) {
        obj = M2C_FIELD(arg0, void **, 0x40);
        Ui_AddChild(arg0, obj);
    }
    if (M2C_FIELD(obj, s16 *, 0xA) != 0x108) {
        register int tmp = M2C_FIELD(obj, s16 *, 0xC);
        spC.x = 0x108;
        spC.y = tmp;
        Ui_SlideWidgetChildMode1(arg0, obj, &spC.x, 0);
    }
    if (Ui_FindChild(arg0, 1, 0) == NULL) {
        p = Heap_Alloc(0x44);
        if (p != NULL) {
            s32 zero;
            zero = 0;
            M2C_FIELD(p, void **, 0) = lbl_8028FDB0;
            M2C_FIELD(p, void **, 0) = lbl_80292230;
            M2C_FIELD(p, u32 *, 4) = zero;
            M2C_FIELD(p, s16 *, 8) = -1;
            M2C_FIELD(p, s16 *, 0xA) = 0x260;
            M2C_FIELD(p, s16 *, 0xC) = 0x14C;
            M2C_FIELD(p, s16 *, 0xE) = 0x349;
            M2C_FIELD(p, s16 *, 0x10) = 0x193;
            M2C_FIELD(p, s16 *, 0x12) = zero;
            M2C_FIELD(p, s16 *, 0x14) = zero;
            M2C_FIELD(p, s16 *, 0x16) = 0xE9;
            M2C_FIELD(p, s16 *, 0x18) = 0x47;
            M2C_FIELD(p, s16 *, 0x1A) = zero;
            M2C_FIELD(p, s16 *, 0x1C) = zero;
            M2C_FIELD(p, u8 *, 0x1E) = 0xFF;
            M2C_FIELD(p, u8 *, 0x1F) = 0xFF;
            M2C_FIELD(p, u8 *, 0x20) = 0xFF;
            M2C_FIELD(p, u8 *, 0x21) = 0xFF;
            M2C_FIELD(p, s16 *, 0x22) = 0x1F4;
            M2C_FIELD(p, s16 *, 0x24) = zero;
            M2C_FIELD(p, f32 *, 0x28) = lbl_8036AE40;
            M2C_FIELD(p, f32 *, 0x2C) = lbl_8036AE40;
            M2C_FIELD(p, f32 *, 0x30) = lbl_8036AE40;
            M2C_FIELD(p, u32 *, 0x34) = zero;
            M2C_FIELD(p, u32 *, 0x38) = zero;
            M2C_FIELD(p, void **, 0) = lbl_802961F4;
            M2C_FIELD(p, u32 *, 0x3C) = zero;
            ((Obj *)p)->v8();
        }
        M2C_FIELD(p, s16 *, 8) = 1;
        M2C_FIELD(p, s16 *, 0x24) = 8;
        if (ListWidget_GetSelected(obj) != NULL) {
            M2C_FIELD(p, u32 *, 0x3C) = *(u32 *)(*(void **)ListWidget_GetSelected(obj));
        }
        Ui_AddChild(arg0, p);
        tmp = M2C_FIELD(p, s16 *, 0xC);
        sp8.x = 0x158;
        sp8.y = tmp;
        Ui_SlideWidgetChildMode1(arg0, p, &sp8.x, 0);
    }
    Ui_BringChildToFront(arg0, obj);
    msg = M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), void **, 0x24);
    p = Ui_FindChild(arg0, -0x1000, 0);
    if (p != NULL) {
        Ui_SetWidgetText(p, msg);
    }
}
extern "C" void fn_80194988(void *arg0) {
    void *Heap_Alloc(s32);
    void *fn_80194DA0(void *, s32, s32, s32, s32, s32);
    void **Unit_GetHeldItemSlot(void *, s32);
    void fn_801439F0(void *, void *, void *);
    u8 fn_8014D8DC(void *);
    void fn_80143570(void *);
    void Ui_AddChild(void *, void *);
    void fn_8011D908(s32, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(u32, s32);
    extern struct { void *head; s32 unk4; s32 unk8; } gUnitLists[];
    extern u8 gBattleState[];
    extern u32 gConvoy[];

    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
    };

    struct Panel {
        u8 pad0[8];
        s16 f8;
        u8 pad1[0x1A];
        s16 f24;
        u8 pad2[0x64];
        s16 f8A;
    };

    register void *walk;
    register s32 i;
    void *dst;
    void *unit;
    void *self;
    void *obj;
    void **entry;
    void *saved;
    u32 res;
    Panel *panel;

    self = arg0;
    obj = Heap_Alloc(0x12C);
    if (obj != NULL) {
        obj = fn_80194DA0(obj, 0x108, 0x84, 0x138, 0xC4, 0x1F4);
    }
    *(void **)((u8 *)self + 0x40) = obj;
    obj = *(void **)((u8 *)self + 0x40);
    if (obj != NULL) {
        *(s32 *)((u8 *)obj + 4) = *(s32 *)((u8 *)obj + 4) + 1;
    }
    panel = *(Panel **)((u8 *)self + 0x40);
    panel->f8 = 0;
    panel = *(Panel **)((u8 *)self + 0x40);
    panel->f24 = 8;
    panel = *(Panel **)((u8 *)self + 0x40);
    panel->f8A = 0xA;

    dst = *(void **)((u8 *)self + 0x40);
    unit = gUnitLists[0].head;
    goto loop1_cond;
loop1_body:
    for (i = 0; i < 4; i++) {
        entry = Unit_GetHeldItemSlot(unit, i);
        if (*(u32 *)entry == 0) {
            break;
        }
        fn_801439F0(dst, entry, unit);
    }
    i = 0;
    walk = unit;
    while (i < 4) {
        if (*(u32 *)((u8 *)walk + 0x1EC) == 0) {
            break;
        }
        fn_801439F0(dst, (u8 *)walk + 0x1EC, unit);
        i += 1;
        walk = (u8 *)walk + 8;
    }
    unit = *(void **)((u8 *)unit + 0x184);
loop1_cond:
    if (unit != NULL) {
        goto loop1_body;
    }

    dst = *(void **)((u8 *)self + 0x40);
    unit = *(void **)((u8 *)gUnitLists + 0x3C);
    goto loop2_cond;
loop2_body:
    for (i = 0; i < 4; i++) {
        entry = Unit_GetHeldItemSlot(unit, i);
        if (*(u32 *)entry == 0) {
            break;
        }
        fn_801439F0(dst, entry, unit);
    }
    i = 0;
    walk = unit;
    while (i < 4) {
        if (*(u32 *)((u8 *)walk + 0x1EC) == 0) {
            break;
        }
        fn_801439F0(dst, (u8 *)walk + 0x1EC, unit);
        i += 1;
        walk = (u8 *)walk + 8;
    }
    unit = *(void **)((u8 *)unit + 0x184);
loop2_cond:
    if (unit != NULL) {
        goto loop2_body;
    }

    if (fn_8014D8DC(gBattleState) != 0) {
        dst = *(void **)((u8 *)self + 0x40);
        walk = gConvoy;
        i = 0;
        while (i < 0xC8) {
            if (*(u32 *)walk != 0) {
                fn_801439F0(dst, walk, NULL);
            }
            i += 1;
            walk = (u8 *)walk + 8;
        }
    }

    fn_80143570(*(void **)((u8 *)self + 0x40));
    obj = *(void **)((u8 *)self + 0x40);
    *(s32 *)((u8 *)obj + 0x11C) = 3;
    *(u8 *)((u8 *)*(void **)((u8 *)self + 0x40) + 0x4C) = 0;
    ((Obj *)*(void **)((u8 *)self + 0x40))->v11();
    Ui_AddChild(self, *(void **)((u8 *)self + 0x40));
    fn_8011D908(*(s32 *)((u8 *)*(void **)((u8 *)self + 0x44) + 4), self);
    saved = *(void **)((u8 *)*(void **)((u8 *)self + 0x44) + 0x2C);
    res = (u32)Ui_FindChild(self, -0x1000, 0);
    if (res != 0U) {
        Ui_SetWidgetText(res, (s32)saved);
    }
}

extern "C" void fn_80194BF8(void *arg0) {
    void *Heap_Alloc(s32);
    void String_AssignCStr(void *, void *, s32);
    s32 strlen(const char *);
    void Ui_AddChild(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *, void *);
    extern u8 lbl_8028FDB0[];
    extern u8 lbl_80292230[];
    extern u8 lbl_80293C84[];
    extern u8 lbl_80293C58[];
    extern u8 lbl_8027A360[];
    u8 *w;
    void *child;
    void *text;
    s32 len;

    w = (u8 *)Heap_Alloc(0x5C);
    if (w) {
        *(void **)(w + 0x0) = lbl_8028FDB0;
        *(s32 *)(w + 0x4) = 0;
        *(void **)(w + 0x0) = lbl_80292230;
        *(s16 *)(w + 0x8) = -1;
        *(s16 *)(w + 0xA) = 0;
        *(s16 *)(w + 0xC) = 0x190;
        *(s16 *)(w + 0xE) = 0x260;
        *(s16 *)(w + 0x10) = 0x1C0;
        *(s16 *)(w + 0x12) = 0;
        *(s16 *)(w + 0x14) = 0;
        *(s16 *)(w + 0x16) = 0x260;
        *(s16 *)(w + 0x18) = 0x30;
        *(s16 *)(w + 0x1A) = 0;
        *(s16 *)(w + 0x1C) = 0;
        w[0x1E] = 0xFF;
        w[0x1F] = 0xFF;
        w[0x20] = 0xFF;
        w[0x21] = 0xFF;
        *(s16 *)(w + 0x22) = 0x5A;
        *(s16 *)(w + 0x24) = 0;
        *(f32 *)(w + 0x28) = 1.0f;
        *(f32 *)(w + 0x2C) = 1.0f;
        *(f32 *)(w + 0x30) = 1.0f;
        *(s32 *)(w + 0x34) = 0;
        *(s32 *)(w + 0x38) = 0;
        *(void **)(w + 0x0) = lbl_80293C84;
        *(s32 *)(w + 0x3C) = 0;
        *(s32 *)(w + 0x40) = 0;
        *(s32 *)(w + 0x44) = 0;
        *(s32 *)(w + 0x40) = 0;
        *(s32 *)(w + 0x48) = 0;
        w[0x4C] = 1;
        *(s16 *)(w + 0x4E) = 0;
        *(s16 *)(w + 0x50) = 0;
        *(s16 *)(w + 0x52) = 0;
        *(s16 *)(w + 0x54) = 0;
        *(void **)(w + 0x0) = lbl_80293C58;
        *(s32 *)(w + 0x58) = 1;
        *(s16 *)(w + 0x4E) = 0x30;
        *(s16 *)(w + 0x52) = 0x30;
    }
    *(s16 *)(w + 0x8) = -0x1000;
    *(s32 *)(w + 0x48) = 1;
    len = strlen((const char *)lbl_8027A360 + 0x1C0);
    String_AssignCStr(w + 0x3C, lbl_8027A360 + 0x1C0, len);
    *(s32 *)(w + 0x34) |= 0x10;
    *(s32 *)(w + 0x58) = 1;
    Ui_AddChild(arg0, w);
    text = *(void **)(*(u8 **)((u8 *)arg0 + 0x44) + 0x2C);
    child = Ui_FindChild(arg0, -0x1000, 0);
    if (child) {
        Ui_SetWidgetText(child, text);
    }
}

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset

void *fn_80194DA0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void fn_80179800(void *);
    extern u8 lbl_802923E0[];

    fn_80179800(arg0);
    *(u8 **)arg0 = lbl_802923E0;
    *(s16 *)((u8 *)arg0 + 0x88) = 0xC;
    *(s16 *)((u8 *)arg0 + 0x8A) = 0;
    *(s16 *)((u8 *)arg0 + 0x80) = (s16)((arg4 - (*(s16 *)((u8 *)arg0 + 0x8A) + 0xC)) / 32);
    return arg0;
}

extern u8 Proc_EventArrowManager[16];
  void fn_80194E10(void) {
      Process_UnlinkByKey(&Proc_EventArrowManager);
  }

s32 fn_80194E38(void) {
    void *Process_Find(void *);
    void *proc;
    u8 *base;
    s32 off;
    s32 i;
    s32 k;
    s32 j;
    u8 ok;
    u8 *entry;

    proc = Process_Find(Proc_EventArrowManager);
    if (proc == NULL) {
        return 0;
    }
    j = 0;
    off = j;
    for (i = 0; i < 2; i++) {
        base = *(u8 **)((u8 *)proc + 0x30);
        for (k = 0; k < 4; k++) {
            entry = base + off;
            if ((*(f32 *)(entry + 0x10) >= *(f32 *)(entry + 0x18)) == 0) {
                ok = 0;
                goto done;
            }
            off += 0x3250;
        }
        j += 3;
    }
    ok = 1;
done:
    if (ok) {
        return 0;
    }
    return 1;
}

  void *EventArrow_Get(s32 arg0) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    extern u8 Proc_EventArrowManager[16];
    void *obj;

    obj = Process_Find(Proc_EventArrowManager);
    if (obj == NULL) {
        obj = Process_Create(Proc_EventArrowManager, 3);
    }
    return (void *)(*(s32 *)((u8 *)obj + 0x30) + arg0 * 0x3250);
}

void fn_80194FAC(void *arg0) {
    void fn_80195178(void *);
    void fn_801959FC(void *);
    void fn_8006785C(s32, void *, void *);

    extern u32 gUiInputFlags;

    u8 *self;
    s32 offset;
    s32 i;
    u8 *data;
    f32 value;

    self = (u8 *)arg0;

    if (gUiInputFlags & 1) {
        data = *(u8 **)(self + 0x30);
        value = *(f32 *)(data + 0x18);
        *(f32 *)(data + 0x14) = value;
        *(f32 *)(data + 0x10) = value;

        data = *(u8 **)(self + 0x30);
        value = *(f32 *)(data + 0x3268);
        *(f32 *)(data + 0x3264) = value;
        *(f32 *)(data + 0x3260) = value;

        data = *(u8 **)(self + 0x30);
        value = *(f32 *)(data + 0x64B8);
        *(f32 *)(data + 0x64B4) = value;
        *(f32 *)(data + 0x64B0) = value;

        data = *(u8 **)(self + 0x30);
        value = *(f32 *)(data + 0x9708);
        *(f32 *)(data + 0x9704) = value;
        *(f32 *)(data + 0x9700) = value;

        data = *(u8 **)(self + 0x30);
        value = *(f32 *)(data + 0xC958);
        *(f32 *)(data + 0xC954) = value;
        *(f32 *)(data + 0xC950) = value;

        data = *(u8 **)(self + 0x30);
        value = *(f32 *)(data + 0xFBA8);
        *(f32 *)(data + 0xFBA4) = value;
        *(f32 *)(data + 0xFBA0) = value;

        data = *(u8 **)(self + 0x30);
        value = *(f32 *)(data + 0x12DF8);
        *(f32 *)(data + 0x12DF4) = value;
        *(f32 *)(data + 0x12DF0) = value;

        data = *(u8 **)(self + 0x30);
        value = *(f32 *)(data + 0x16048);
        *(f32 *)(data + 0x16044) = value;
        *(f32 *)(data + 0x16040) = value;
    }

    i = 0;
    offset = 0;
    for (; i < 8; ) {
        fn_80195178(*(u8 **)(self + 0x30) + offset);
        fn_8006785C(2, fn_801959FC, *(u8 **)(self + 0x30) + offset);
        i += 1;
        offset += 0x3250;
    }
}

void fn_801950CC(void *arg0) {
    M2C_UNK Heap_FreeRaw(s32);
    u32 temp_r3;

    temp_r3 = M2C_FIELD(arg0, u32 *, 0x30);
    if (temp_r3 != 0U) {
        Heap_FreeRaw(temp_r3 - 0x10);
    }
}

void fn_801950FC(void *arg0) {
    void *Heap_AllocRaw(s32);
    s32 fn_8022C414(void *, void *, void *, s32, s32);
    void fn_80196018(void *);
    M2C_FIELD(arg0, s32 *, 0x30) = fn_8022C414(Heap_AllocRaw(0x19290), fn_80196018, 0, 0x3250, 8);
}

#pragma scheduling off
void fn_8019514C(void *dst, void *src) { u8 *d=dst; const u8 *s=src; unsigned int a=s[0]; unsigned char b=s[1]; d[0]=a; a=s[2]; d[1]=b; b=s[3]; d[2]=a; d[3]=b; }
#pragma scheduling reset
void fn_80195170(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 4) = arg1;
}

void fn_80195178(void *arg0) {
    f32 Math_Hermite(f32, f32, f32, f32, f32);
    f32 Math_Lerp(f32, f32, f32, f32);
    f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
    void BattleState_SetCamPos(void *, f32, f32);
    void fn_802031E8(f32 *, f32 *);
    extern f32 lbl_8027A580[];
    extern f32 lbl_8027A58C[];
    extern void gBattleState;
    extern u32 lbl_8036AE4C;
    extern f32 lbl_8036AE50;
    extern f32 lbl_8036AE54;
    extern f32 lbl_8036AE58;
    extern f32 lbl_8036AE5C;

    void *self;
    f32 sp30[3];
    f32 sp24[3];
    f32 sp18[3];
    f32 spC[3];
    u32 sp8;
    u8 *p;
    f32 *p0, *p2, *p3;
    f32 *dst;
    f32 *pos;
    f32 *nrm;
    f32 *a, *b;
    f32 *curpt;
    s32 i, j, k;
    s32 n;
    s32 cur, prev;
    s16 timer;
    f32 t;
    f32 t2;
    f32 frac;
    f32 w;

    self = arg0;
    *(s16 *)((u8 *)arg0 + 0xA) = 0;
    timer = *(s16 *)((u8 *)arg0 + 6);
    if (timer > 0) {
        *(s16 *)((u8 *)self + 6) = (s16)(timer + 1);
        if (*(s16 *)((u8 *)self + 6) == 0x1E) {
            f32 z = lbl_8036AE50;
            *(s16 *)((u8 *)self + 6) = 0;
            *(u8 *)((u8 *)self + 8) = 0;
            *(s16 *)((u8 *)self + 0xA) = 0;
            *(f32 *)((u8 *)self + 0xC) = z;
            *(f32 *)((u8 *)self + 0x10) = z;
            *(f32 *)((u8 *)self + 0x14) = z;
            *(f32 *)((u8 *)self + 0x18) = z;
            *(f32 *)((u8 *)self + 0x1C) = z;
            *(u8 *)((u8 *)self + 4) = 0;
            *(s16 *)((u8 *)self + 6) = 0;
            sp8 = lbl_8036AE4C;
            *(u8 *)self = ((u8 *)&sp8)[0];
            *((u8 *)self + 1) = ((u8 *)&sp8)[1];
            *((u8 *)self + 2) = ((u8 *)&sp8)[2];
            *((u8 *)self + 3) = ((u8 *)&sp8)[3];
        }
    }

    if (*(u8 *)((u8 *)self + 8) < 2) {
        return;
    }
    if (*(f32 *)((u8 *)self + 0x14) >= *(f32 *)((u8 *)self + 0x18)) {
        return;
    }

    *(f32 *)((u8 *)self + 0x1C) = *(f32 *)((u8 *)self + 0x1C) + lbl_8036AE54;
    t = *(f32 *)((u8 *)self + 0x18) - *(f32 *)((u8 *)self + 0x14);
    if (*(f32 *)((u8 *)self + 0x1C) > t) {
        *(f32 *)((u8 *)self + 0x1C) = t;
    }
    {
        f32 a14 = *(f32 *)((u8 *)self + 0x14);
        f32 a18 = *(f32 *)((u8 *)self + 0x18);
        *(f32 *)((u8 *)self + 0x10) = Math_EaseOutPow(2, a14, a18, a18 - a14, *(f32 *)((u8 *)self + 0x1C));
    }
    if (*(f32 *)((u8 *)self + 0x10) > *(f32 *)((u8 *)self + 0x18)) {
        *(f32 *)((u8 *)self + 0x10) = *(f32 *)((u8 *)self + 0x18);
    }

    n = *(u8 *)((u8 *)self + 8);
    w = *(f32 *)((u8 *)self + 0x10);
    if ((u32)n < 2) {
        t = lbl_8036AE50;
    } else {
        p = (u8 *)self;
        k = 0;
        for (i = n; i != 0; i--) {
            if ((f32)*(s32 *)(p + 0x20) >= w) {
                break;
            }
            p += 4;
            k += 1;
        }
        if (k == 0) {
            t = lbl_8036AE50;
        } else {
            cur = *(s32 *)((u8 *)self + k * 4 + 0x20);
            prev = *(s32 *)((u8 *)self + k * 4 + 0x1C);
            if (cur == prev) {
                t = (f32)(k - 1);
            } else {
                t = Math_Lerp((f32)(k - 1), (f32)k, (f32)(cur - prev), w - (f32)prev);
            }
        }
    }
    *(f32 *)((u8 *)self + 0xC) = t;

    *(f32 *)((u8 *)self + 0x220) = *(f32 *)((u8 *)self + 0xA0);
    *(f32 *)((u8 *)self + 0x224) = *(f32 *)((u8 *)self + 0xA4);
    *(f32 *)((u8 *)self + 0x228) = *(f32 *)((u8 *)self + 0xA8);
    dst = (f32 *)((u8 *)self + 0x22C);
    n = *(u8 *)((u8 *)self + 8);
    curpt = (f32 *)self;
    for (i = 0; i < n - 1; i++) {
        if (i == 0) {
            p0 = (f32 *)((u8 *)self + 0xA0);
        } else {
            p0 = (f32 *)((u8 *)self + 0xA0 + (i - 1) * 0xC);
        }
        p2 = (f32 *)((u8 *)self + 0xA0 + (i + 1) * 0xC);
        if (i == n - 2) {
            p3 = (f32 *)((u8 *)self + 0xA0 + (n - 1) * 0xC);
        } else {
            p3 = (f32 *)((u8 *)self + 0xA0 + (i + 2) * 0xC);
        }
        for (j = 1; j <= 0x10; j++) {
            t2 = (f32)j * lbl_8036AE58;
            dst[0] = Math_Hermite(p0[0], curpt[0xA0 / 4], p2[0], p3[0], t2);
            dst[1] = Math_Hermite(p0[1], curpt[0xA4 / 4], p2[1], p3[1], t2);
            dst[2] = Math_Hermite(p0[2], curpt[0xA8 / 4], p2[2], p3[2], t2);
            dst += 3;
        }
        curpt = (f32 *)((u8 *)curpt + 0xC);
    }
    dst[0] = dst[-3] + (dst[-3] - dst[-6]);
    dst[1] = dst[-2] + (dst[-2] - dst[-5]);
    dst[2] = dst[-1] + (dst[-1] - dst[-4]);
    *(s16 *)((u8 *)self + 0xA) = (s16)((*(u8 *)((u8 *)self + 8) - 1) * 0x10 + 1);

    pos = (f32 *)((u8 *)self + 0x220);
    nrm = (f32 *)((u8 *)self + 0x1A38);
    for (i = 0; i < *(s16 *)((u8 *)self + 0xA); i++) {
        sp18[0] = lbl_8027A580[0];
        sp18[1] = lbl_8027A580[1];
        sp18[2] = lbl_8027A580[2];
        sp18[0] = -(pos[4] - pos[1]);
        sp18[1] = pos[3] - pos[0];
        sp30[0] = sp18[0];
        sp30[1] = sp18[1];
        sp30[2] = sp18[2];
        fn_802031E8(sp30, sp30);
        if (i > 0) {
            spC[0] = lbl_8027A58C[0];
            spC[1] = lbl_8027A58C[1];
            spC[2] = lbl_8027A58C[2];
            spC[0] = pos[-2] - pos[1];
            spC[1] = -(pos[-3] - pos[0]);
            sp24[0] = spC[0];
            sp24[1] = spC[1];
            sp24[2] = spC[2];
            fn_802031E8(sp24, sp24);
            sp30[0] = (sp30[0] + sp24[0]) * lbl_8036AE5C;
            sp30[1] = (sp30[1] + sp24[1]) * lbl_8036AE5C;
        }
        nrm[0] = sp30[0];
        nrm[1] = sp30[1];
        nrm[2] = sp30[2];
        pos += 3;
        nrm += 3;
    }

    frac = lbl_8036AE54 + Math_Lerp(
        lbl_8036AE50,
        (f32)(*(s16 *)((u8 *)self + 0xA) - 1),
        (f32)(*(u8 *)((u8 *)self + 8) - 1),
        *(f32 *)((u8 *)self + 0xC));
    if ((f32)*(s16 *)((u8 *)self + 0xA) > frac) {
        k = (s32)frac;
        if (lbl_8036AE50 == frac - (f32)k) {
            *(s16 *)((u8 *)self + 0xA) = (s16)k;
        } else {
            *(s16 *)((u8 *)self + 0xA) = (s16)(k + 1);
            t2 = frac - (f32)k;
            a = (f32 *)((u8 *)self + 0x220 + (*(s16 *)((u8 *)self + 0xA) - 2) * 0xC);
            b = (f32 *)((u8 *)self + 0x220 + (*(s16 *)((u8 *)self + 0xA) - 1) * 0xC);
            b[0] = Math_Lerp(a[0], b[0], lbl_8036AE54, t2);
            b[1] = Math_Lerp(a[1], b[1], lbl_8036AE54, t2);
            b[2] = Math_Lerp(a[2], b[2], lbl_8036AE54, t2);
            a = (f32 *)((u8 *)self + 0x1A38 + (*(s16 *)((u8 *)self + 0xA) - 2) * 0xC);
            b = (f32 *)((u8 *)self + 0x1A38 + (*(s16 *)((u8 *)self + 0xA) - 1) * 0xC);
            b[0] = Math_Lerp(a[0], b[0], lbl_8036AE54, t2);
            b[1] = Math_Lerp(a[1], b[1], lbl_8036AE54, t2);
            b[2] = Math_Lerp(a[2], b[2], lbl_8036AE54, t2);
        }
    }

    if (*(u8 *)((u8 *)self + 4) != 0) {
        if (*(f32 *)((u8 *)self + 0x10) < *(f32 *)((u8 *)self + 0x18)) {
            b = (f32 *)((u8 *)self + 0x220 + (*(s16 *)((u8 *)self + 0xA) - 1) * 0xC);
            BattleState_SetCamPos(&gBattleState, b[0], b[1]);
        }
    }
}

void fn_80195880(void *arg0) {
    M2C_FIELD(arg0, s16 *, 6) = 1;
}

void fn_8019588C(void *arg0, s32 arg1) {
    f32 v;
    f32 z;

    z = 0.0f;
    *(f32 *)((u8 *)arg0 + 0x14) = *(f32 *)((u8 *)arg0 + 0x10);
    v = (f32)arg1;
    *(f32 *)((u8 *)arg0 + 0x18) = v;
    *(f32 *)((u8 *)arg0 + 0x1C) = z;
}

#pragma dont_inline on
void fn_801958C8(void *arg0, s32 arg1, void *arg2) {
    typedef struct { f32 x, y, z; } Vec3;
    typedef struct {
        u8 pad[8];
        u8 count;
        u8 pad9[15];
        f32 max;
        u32 pad1c;
        s32 keys[32];
        Vec3 pos[32];
    } Data;
    Data *p = arg0;
    Vec3 *v = arg2;
    s32 j, i;
    u8 *keys, *pos;
    Vec3 *dst;
    Vec3 tmp;
    f32 x;
    f32 y;
    f32 z;

#pragma scheduling off
    x = v->x;
    y = v->y;
    z = v->z;
    dst = (Vec3 *)((u8 *)p + (p->count * 12 + 0xA0));
    dst->x = x;
    dst->y = y;
    dst->z = z;
#pragma scheduling reset
    p->keys[p->count] = arg1;
    p->count++;
    for (i = 0; i < p->count; i++) {
        for (j = 0, keys = (u8 *)p, pos = (u8 *)p; j < p->count - i - 1; keys += 4, pos += 12, j++) {
            if (*(s32 *)(keys + 0x20) > *(s32 *)(keys + 0x24)) {
                s32 key = *(s32 *)(keys + 0x20);
                *(s32 *)(keys + 0x20) = *(s32 *)(keys + 0x24);
                *(s32 *)(keys + 0x24) = key;
                {
                    Vec3 *next = &p->pos[j + 1];
                    tmp = *(Vec3 *)(pos + 0xA0);
                    ((Vec3 *)(pos + 0xA0))->x = next->x;
                    ((Vec3 *)(pos + 0xA0))->y = next->y;
                    ((Vec3 *)(pos + 0xA0))->z = next->z;
                    next->x = tmp.x;
                    next->y = tmp.y;
                    next->z = tmp.z;
                }
            }
        }
    }
    p->max = (f32)p->keys[p->count - 1];
}

#pragma use_lmw_stmw on
void fn_801959FC(void *arg0) {
    f32 Math_Lerp(f32, f32, f32, f32);
    void *Camera_GetViewMtx(void);
    u32 fn_8006D948(void *);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXTrans(void *, f32, f32, f32);
    void GXSetVtxDesc(s32, s32);
    void GXClearVtxDesc(void);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void GXSetNumChans(s32);
    void GXBegin(s32, s32, s32);
    void fn_8022100C(s32);
    void GXSetChanMatColor(s32, void *);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void GXSetNumTexGens(s32, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTevStages(s32);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    extern u8 lbl_8027A598[];
    extern u32 lbl_80368210;
    extern s32 lbl_8036AE48;
    extern f32 lbl_8036AE50;
    extern f64 lbl_8036AE60;
    extern f32 lbl_8036AE68;
    extern f32 lbl_8036AE6C;
    extern f32 lbl_8036AE70;
    extern f32 lbl_8036AE74;
    extern f32 lbl_8036AE78;
    extern f64 lbl_8036AE80;

    f32 mtx[3][4];
    s32 color;
    void *self;
    void *view;
    f32 *pos;
    f32 *nrm;
    s32 i;
    s16 len;
    u8 alpha;
    u8 a0;
    s32 r, g, b;
    f32 f29;
    f64 f30;
    f64 f31;
    f32 *last;
    register volatile f32 *fifo;

    self = arg0;
    if (*(u8 *)((u8 *)self + 8) == 0) return;
    if (lbl_8036AE50 == *(f32 *)((u8 *)self + 0xC)) return;
    if (*(s16 *)((u8 *)self + 0xA) == 0) return;

    if (lbl_80368210 == 0) {
        lbl_80368210 = fn_8006D948(lbl_8027A598 + 0xE2);
    }
    fn_8022100C(0);
    PSMTXTrans(mtx, lbl_8036AE50, lbl_8036AE50, lbl_8036AE68);
    view = Camera_GetViewMtx();
    PSMTXConcat(view, mtx, mtx);
    GXLoadPosMtxImm(mtx, 0);
    GXSetCurrentMtx(0);
    color = lbl_8036AE48;
    GXSetChanMatColor(4, &color);
    GXSetBlendMode(4, 0, 1, 1, 0, 0, 2);
    GXSetCullMode(1);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0xFF, 0xFF, 4);
    GXSetNumTexGens(0, 4);
    GXSetNumChans(0);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xB, 1);
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);

    len = *(s16 *)((u8 *)self + 6);
    pos = (f32 *)((u8 *)self + 0x220);
    a0 = *(u8 *)((u8 *)self + 3);
    nrm = (f32 *)((u8 *)self + 0x1A38);
    alpha = a0;
    if (len > 0) {
        alpha = (u8)(s32)(((f32)(s32)a0 * Math_Lerp(lbl_8036AE6C, lbl_8036AE50, lbl_8036AE70, (f32)len)) / lbl_8036AE6C);
    }
    GXBegin(0x98, 0, (*(s16 *)((u8 *)self + 0xA) << 1) & 0xFFFE);
    f30 = lbl_8036AE80;
    f31 = lbl_8036AE60;
    f29 = lbl_8036AE74;
    i = 0;
    fifo = (volatile f32 *)0xCC008000;
    while (i < *(s16 *)((u8 *)self + 0xA)) {
        r = (s32)Math_Lerp((f32)*(u8 *)self, lbl_8036AE6C, (f32)(*(s16 *)((u8 *)self + 0xA) - 1), (f32)i);
        g = (s32)Math_Lerp((f32)*((u8 *)self + 1), lbl_8036AE6C, (f32)(*(s16 *)((u8 *)self + 0xA) - 1), (f32)i);
        b = (s32)Math_Lerp((f32)*((u8 *)self + 2), lbl_8036AE6C, (f32)(*(s16 *)((u8 *)self + 0xA) - 1), (f32)i);
        i += 1;
        fifo[0] = nrm[0] * f29 + pos[0];
        fifo[0] = nrm[1] * f29 + pos[1];
        fifo[0] = pos[2];
        ((volatile u8 *)fifo)[0] = (u8)r;
        ((volatile u8 *)fifo)[0] = (u8)g;
        ((volatile u8 *)fifo)[0] = (u8)b;
        ((volatile u8 *)fifo)[0] = alpha;
        fifo[0] = -(nrm[0] * f29 - pos[0]);
        fifo[0] = -(nrm[1] * f29 - pos[1]);
        fifo[0] = pos[2];
        ((volatile u8 *)fifo)[0] = (u8)r;
        ((volatile u8 *)fifo)[0] = (u8)g;
        ((volatile u8 *)fifo)[0] = (u8)b;
        ((volatile u8 *)fifo)[0] = alpha;
        nrm += 3;
        pos += 3;
    }
    last = (f32 *)((u8 *)self + (*(s16 *)((u8 *)self + 0xA) - 1) * 0xC);
    GXBegin(0x90, 0, 9);
    {
        f32 *p = (f32 *)((u8 *)last + 0x220);
        f32 *v = (f32 *)((u8 *)last + 0x1A38);
        f32 s = lbl_8036AE74;
        f32 t = lbl_8036AE78;
        fifo[0] = v[0]*s+p[0]; fifo[0]=v[1]*s+p[1]; fifo[0]=p[2];
        ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=alpha;
        fifo[0]=-(v[0]*s-p[0]); fifo[0]=-(v[1]*s-p[1]); fifo[0]=p[2];
        ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=alpha;
        fifo[0]=t*(v[1]*s)+p[0]; fifo[0]=-(t*(v[0]*s)-p[1]); fifo[0]=p[2];
        ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=alpha;
        fifo[0]=-(v[0]*s-p[0]); fifo[0]=-(v[1]*s-p[1]); fifo[0]=p[2];
        ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=alpha;
        fifo[0]=-(t*(v[0]*s)-p[0]); fifo[0]=-(t*(v[1]*s)-p[1]); fifo[0]=p[2];
        ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=alpha;
        fifo[0]=t*(v[1]*s)+p[0]; fifo[0]=-(t*(v[0]*s)-p[1]); fifo[0]=p[2];
        ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=alpha;
        fifo[0]=v[0]*s+p[0]; fifo[0]=v[1]*s+p[1]; fifo[0]=p[2];
        ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=alpha;
        fifo[0]=t*(v[1]*s)+p[0]; fifo[0]=-(t*(v[0]*s)-p[1]); fifo[0]=p[2];
        ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=alpha;
        fifo[0]=t*(v[0]*s)+p[0]; fifo[0]=t*(v[1]*s)+p[1]; fifo[0]=p[2];
        ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=0xFF; ((volatile u8*)fifo)[0]=alpha;
    }
    (void)f30; (void)f31;
}
void fn_80196018(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x8) = 0;
    M2C_FIELD(arg0, u16 *, 0xa) = 0;
    M2C_FIELD(arg0, f32 *, 0xc) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x10) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x14) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x18) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x1c) = 0.0f;
    M2C_FIELD(arg0, u8 *, 0x4) = 0;
    M2C_FIELD(arg0, u16 *, 0x6) = 0;
    {
        u8 color[4] = {0x00, 0x40, 0x80, 0xFF};
        M2C_FIELD(arg0, u8 *, 0x0) = color[0];
        M2C_FIELD(arg0, u8 *, 0x1) = color[1];
        M2C_FIELD(arg0, u8 *, 0x2) = color[2];
        M2C_FIELD(arg0, u8 *, 0x3) = color[3];
    }
}

#pragma global_optimizer off
void fn_80196078(void) {
    void fn_8000D3EC(void *, void *);
    extern u8 lbl_8027A688[];
    extern u8 lbl_80296700[];
    u8 *dst;

    dst = lbl_80296700;
    fn_8000D3EC(lbl_8027A688 + 0x28, dst + 0x34);
    fn_8000D3EC(lbl_8027A688 + 0x3C, dst + 0x44);
    fn_8000D3EC(lbl_8027A688 + 0x4B, dst + 0x44);
    fn_8000D3EC(lbl_8027A688 + 0x5D, dst + 0x44);
    fn_8000D3EC(lbl_8027A688 + 0x6F, dst + 0x44);
    fn_8000D3EC(lbl_8027A688 + 0x80, dst + 0x44);
    fn_8000D3EC(lbl_8027A688 + 0x92, dst + 0x44);
    fn_8000D3EC(lbl_8027A688 + 0xA3, dst + 0x44);
    fn_8000D3EC(lbl_8027A688 + 0xB3, dst + 0x44);
    fn_8000D3EC(lbl_8027A688 + 0xC2, dst + 0x54);
    fn_8000D3EC(lbl_8027A688 + 0xD0, dst + 0x54);
    fn_8000D3EC(lbl_8027A688 + 0xE1, dst + 0x64);
}
#pragma global_optimizer on
/* Advance UI unit's active weapon rank, then open weapon-kind help under parent. */
s32 Ui_OpenActiveWpnKindHelp(s32 parent) {
    void **Unit_GetActiveItemPtr(void *);
    void fn_80092528(void *, u8);
    void fn_80094A08(s32, s32);
    void Ui_OpenWeaponKindHelp(s8, s32, s32, s32, s32);
    extern u8 gUiContext[];
    extern u8 gBattle[];
    void *unit;
    void **slot;
    void *item;
    u8 kind;

    unit = *(void **)gUiContext;
    slot = Unit_GetActiveItemPtr(unit);
    kind = ((item = *slot) != NULL) ? ((u8 *)item)[0x12] : 0xC;
    fn_80092528(unit, kind);
    fn_80094A08((s32)unit, *(s8 *)&gUiContext[0xA]);
    *(u32 *)(gBattle + 0xCAC) |= 0x2000;
    kind = ((item = *slot) != NULL) ? ((u8 *)item)[0x12] : 0xC;
    Ui_OpenWeaponKindHelp((s8)kind, parent, -1, -1, -1);
    return 1;
}

s32 fn_80196268(void *arg0) {
    void *Unit_GetActiveItemPtr(void *);
    s32 Unit_GetWpnExp(void *, u8);
    s32 fn_80092C50(void *, u8, u8);
    s32 fn_8001CFA8(s32);
    s8 fn_80092414(void *);
    s32 v1;
    void *obj;
    void *obj2;
    u8 kind;
    void **slot;
    s32 v2;

    slot = Unit_GetActiveItemPtr(arg0);
    if (slot == NULL || (obj = *(void **)slot) == NULL) return 0;
    kind = (obj != NULL) ? *(u8 *)((u8 *)obj + 0x12) : 0xC;
    if (kind >= 8U) return 0;
    kind = (obj != NULL) ? *(u8 *)((u8 *)obj + 0x12) : 0xC;
    v1 = Unit_GetWpnExp(arg0, kind);
    v2 = fn_80092C50(arg0, ((obj2 = *(void **)slot) != NULL) ? *(u8 *)((u8 *)obj2 + 0x12) : 0xC, 0xFF);
    v1 = fn_8001CFA8(v1);
    v2 = fn_8001CFA8(v2);
    if ((u8)v1 == (u8)v2) return 0;
    if ((u8)v1 == 0xB5 && fn_80092414(arg0) >= 0) return 0;
    return 1;
}

s32 fn_80196388(s32 arg0) {
    void **fn_800285C0(void *);
    void fn_80037040(s32, u8, u8);
    void fn_80094A08(s32, s32);
    extern u8 lbl_802EF4C8[];
    void fn_8009127C(void *, s32, void *);
    s32 temp_r31;
    extern u8 lbl_80330EAC[];
    void *temp_r30;

    temp_r31 = *(s32 *)lbl_802EF4C8;
    temp_r30 = *fn_800285C0(lbl_802EF4C8);
    fn_80037040(temp_r31, ((u8 *)temp_r30)[0x28], ((u8 *)temp_r30)[0x27]);
    fn_80094A08(temp_r31, *(s8 *)&lbl_802EF4C8[0xA]);
    *(u32 *)((unsigned short)lbl_80330EAC + 0xCAC) |= 0x2000;
    fn_8009127C(temp_r30, arg0, lbl_80330EAC);
    return 1;
}

s32 fn_80196420(s32 arg0, void *arg1) {
    s8 Unit_GetMov();
    s8 Unit_GetCon(s32);
    s8 temp_r31;
    s8 temp_r3;
    s8 var_r4;
    s8 var_r5;

    temp_r31 = Unit_GetMov();
    temp_r3 = Unit_GetCon(arg0);
    var_r4 = temp_r31 + M2C_FIELD(arg1, u8 *, 0x27);
    var_r5 = temp_r3 + M2C_FIELD(arg1, u8 *, 0x28);
    if (var_r4 > 0x14) {
        var_r4 = 0x14;
    }
    if (var_r5 > 0x63) {
        var_r5 = 0x63;
    }
    if ((var_r4 == temp_r31) && (var_r5 == temp_r3)) {
        return 0;
    }
    return 1;
}

#pragma global_optimizer off
s32 fn_801964C8(s32 arg0) {
    s32 *UiCtx_GetItemSlot(void *);
    void fn_8003708C(s32, s32);
    void fn_80094A08(s32, s32);
    void StatBonus_ShowHelp(s32, s32, void *);
    extern u8 gUiContext[];
    extern u8 gBattle[];
    s32 temp;

    temp = *UiCtx_GetItemSlot(gUiContext);
    fn_8003708C(*(s32 *)gUiContext, temp + 0x1F);
    fn_80094A08(*(s32 *)gUiContext, *(s8 *)&gUiContext[0xA]);
    *(u32 *)(gBattle + 0xCAC) |= 0x2000;
    StatBonus_ShowHelp(temp, arg0, gBattle);
    return 1;
}
#pragma global_optimizer on
s32 fn_80196558(void *arg0, void *arg1) {
    s32 Unit_GetCarryWtLimit(void *);
    s32 Unit_GetMagAtk(void *);
    s32 fn_8003AF28(void *);
    s32 fn_8003AEB0(void *);
    s32 fn_8003ACF8(void *);
    s32 fn_8003AA40(void *);
    s32 fn_8003A778(void *);
    s32 a,b,c,d,e,f,g,h;
    s32 aa,bb,cc,dd,ee,ff,gg,hh;
    u8 same;
    a=M2C_FIELD(arg0,u8 *,0x1A8);
    b=Unit_GetCarryWtLimit(arg0);
    c=Unit_GetMagAtk(arg0);
    d=fn_8003AF28(arg0);
    e=fn_8003AEB0(arg0);
    f=fn_8003ACF8(arg0);
    g=fn_8003AA40(arg0);
    h=fn_8003A778(arg0);
    aa=(s8)a+M2C_FIELD(arg1,u8 *,0x1F);
    bb=(s8)b+M2C_FIELD(arg1,u8 *,0x20);
    cc=(s8)c+M2C_FIELD(arg1,u8 *,0x21);
    dd=(s8)d+M2C_FIELD(arg1,u8 *,0x22);
    ee=(s8)e+M2C_FIELD(arg1,u8 *,0x23);
    ff=(s8)f+M2C_FIELD(arg1,u8 *,0x24);
    gg=(s8)g+M2C_FIELD(arg1,u8 *,0x25);
    hh=(s8)h+M2C_FIELD(arg1,u8 *,0x26);
    if((s8)a!=(s8)aa) same=0;
    else if((s8)b!=(s8)bb) same=0;
    else if((s8)c!=(s8)cc) same=0;
    else if((s8)e!=(s8)ee) same=0;
    else if((s8)d!=(s8)dd) same=0;
    else if((s8)f!=(s8)ff) same=0;
    else if((s8)g!=(s8)gg) same=0;
    else if((s8)h!=(s8)hh) same=0;
    else same=1;
    return same==0;
}

s32 fn_80196704(s32 arg0) {
    void fn_80094A08(s32, s32);
    s32 Game_GetState(void);
    void fn_801EDA88(s32, s32);
    void fn_801ED9DC(s32, s32);
    extern struct {
        s32 unk0;
        s32 unk4;
        u8 unk8;
        u8 unk9;
        s8 unkA;
        u8 pad[0x18 - 0xB];
    } gUiContext;
    extern u8 gBattle[];

    fn_80094A08(gUiContext.unk0, gUiContext.unkA);
    *(u32 *)(gBattle + 0xCAC) |= 0x2000;
    if (Game_GetState() == 0x10) {
        fn_801EDA88(gUiContext.unk0, arg0);
    } else {
        fn_801ED9DC(gUiContext.unk0, arg0);
    }
    return 0;
}

void fn_80196794(void) {
    M2C_UNK Unit_CanPromote();
    Unit_CanPromote();
}

void fn_801967B4(void *arg0) {
    void fn_8004EA60(s32, s32);
    void Unit_Promote(s32);
    void fn_8004EB14(s32, s32);
    void fn_80050C90(s32);
    extern u8 gBattle[];

    fn_8004EA60(*(s32 *)((u8 *)arg0 + 0x30), 0);
    Unit_Promote(*(s32 *)((u8 *)arg0 + 0x30));
    *(u32 *)(gBattle + 0xCAC) |= 0x10;
    fn_8004EB14(*(s32 *)((u8 *)arg0 + 0x30), 0);
    fn_80050C90(*(s32 *)((u8 *)arg0 + 0x30));
}

void fn_80196818(void *arg0) {
    M2C_UNK fn_801B3258(s32, void *);
    fn_801B3258(M2C_FIELD(arg0, s32 *, 0x30), arg0);
}

void fn_80196840(void) {

}

void fn_80196844(void) {

}

extern u16 lbl_8028E090[];
void *fn_80196848(void *arg0, s16 arg1) {
    void String_Destroy(void *, s32);
    void fn_800DF724(void *, s32);
    void Heap_Free(void *);
    extern void *lbl_80296778[];

    if (arg0 != NULL) {
        M2C_FIELD(arg0, void ***, 0x40) = lbl_80296778;
        String_Destroy((s8 *)arg0 + 0x54, -1);
        if (arg0 != NULL) {
            *(void **)((char *)arg0 + 0x40) = (void *)lbl_8028E090;
            fn_800DF724(arg0, 0);
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void Ui_Meter_Nudge(void *arg0, s32 arg1) {
    s32 temp_r0;
    s32 temp_r5;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0x7C);
    temp_r5 = M2C_FIELD(arg0, s32 *, 0x78);
    if (temp_r0 != temp_r5) {
        M2C_FIELD(arg0, s32 *, 0x7C) = (s32) (temp_r0 + arg1);
    } else {
        M2C_FIELD(arg0, s32 *, 0x7C) = (s32) (temp_r5 + arg1);
    }
    M2C_FIELD(arg0, s32 *, 0x8C) = 3;
}

/* Apply a scroll delta to a UI meter, or refresh its string list when delta is 0. */
void Ui_Meter_ApplyDelta(void *meter, s32 delta, u8 useAltTiming, void *stringList) {
    void fn_80122F04(void *, void *);
    void fn_80123034(void *, void *, f32, f32, s32);
    void fn_801232F4(void *, void *, f32, f32);
    extern void *gGame;
    s32 cur;
    s32 target;

    if (delta == 0) {
        fn_80122F04(*(void **)((u8 *)meter + 0x64), stringList);
        if (*(u32 *)((u8 *)stringList + 4) != 0) {
            *(f32 *)((u8 *)meter + 0x90) = *(f32 *)((u8 *)gGame + 0xC8);
            *(f32 *)((u8 *)meter + 0x94) = *(f32 *)((u8 *)gGame + 0xCC);
            *(s32 *)((u8 *)meter + 0x98) = *(s32 *)((u8 *)gGame + 0xD0);
            *(u8 *)((u8 *)meter + 0x9C) = 1;
        }
    } else {
        cur = *(s32 *)((u8 *)meter + 0x7C);
        target = *(s32 *)((u8 *)meter + 0x78);
        if (cur != target) {
            *(s32 *)((u8 *)meter + 0x7C) = cur + delta;
        } else {
            *(s32 *)((u8 *)meter + 0x7C) = target + delta;
        }
        *(s32 *)((u8 *)meter + 0x8C) = 1;
        *(f32 *)((u8 *)meter + 0x90) = *(f32 *)((u8 *)gGame + 0xC8);
        *(f32 *)((u8 *)meter + 0x94) = *(f32 *)((u8 *)gGame + 0xCC);
        *(s32 *)((u8 *)meter + 0x98) = *(s32 *)((u8 *)gGame + 0xD0);
        *(u8 *)((u8 *)meter + 0x9C) = 0;
        if (*(u32 *)((u8 *)stringList + 4) != 0) {
            *(u8 *)((u8 *)meter + 0x9C) = 1;
        }
        if (*(s32 *)((u8 *)meter + 0x78) != 0) {
            fn_801232F4(*(void **)((u8 *)meter + 0x64), gGame,
                        *(f32 *)((u8 *)gGame + 0xA4),
                        *(f32 *)((u8 *)gGame + 0xA8));
        }
        if (useAltTiming != 0) {
            fn_80123034(*(void **)((u8 *)meter + 0x64), stringList,
                        *(f32 *)((u8 *)gGame + 0xBC),
                        *(f32 *)((u8 *)gGame + 0xC0),
                        *(s32 *)((u8 *)gGame + 0xC4));
            return;
        }
        fn_80123034(*(void **)((u8 *)meter + 0x64), stringList,
                    *(f32 *)((u8 *)gGame + 0xB0),
                    *(f32 *)((u8 *)gGame + 0xB4),
                    *(s32 *)((u8 *)gGame + 0xB8));
    }
}

void Ui_Meter_Init(void *arg0, s32 arg1, s32 arg2) {
    void fn_801232F4(void *, f32, f32);
    void fn_80123300(void *, s32);
    extern void *gGame;
    extern f32 lbl_8036AE8C;

    if (arg1 > 0x50) {
        arg1 = 0x50;
    }
    M2C_FIELD(arg0, s32 *, 0x70) = arg2;
    M2C_FIELD(arg0, s32 *, 0x78) = arg1;
    M2C_FIELD(arg0, s32 *, 0x74) = arg1;
    M2C_FIELD(arg0, s32 *, 0x7C) = M2C_FIELD(arg0, s32 *, 0x74);
    M2C_FIELD(arg0, s32 *, 0x8C) = 0;
    if (M2C_FIELD(arg0, void **, 0x64) != NULL) {
        fn_80123300(M2C_FIELD(arg0, void **, 0x64), M2C_FIELD(arg0, s32 *, 0x78));
        fn_801232F4(M2C_FIELD(arg0, void **, 0x64), lbl_8036AE8C, M2C_FIELD(gGame, f32 *, 0xA8));
    }
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_80196AD0(void *arg0, s32 arg1) {
    void Prim2D_SetColor(u8, u8, u8, u8);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    s32 fn_800E2E50(void *);
    s32 fn_800E2E58(void *);
    s32 fn_800E2E60(void *);
    s32 fn_800E2E68(void *);
    void SpriteSheet_DrawUvRect(void *, s32, s32 *, s32 *, s32, s32, s32, s32, s32, s32);
    extern f32 lbl_8036AE88;
    extern f32 lbl_8036AE8C;
    extern f64 lbl_8036AE90;
    extern f64 lbl_8036AE98;

    s32 uv[4];
    s32 rect[4];
    s32 copy[4];
    s32 copyb[4];
    s32 w;
    s32 h;
    s32 a;
    s32 sum;
    s32 pad;
    s32 half;
    s32 diff;
    s32 x0;
    s32 ySave;
    s32 dh;
    s32 alpha;
    s32 sp8;
    s32 spC;
    void *obj38;
    u8 r;
    u8 g;
    u8 bl;
    void *self;
    s32 layer;

    self = arg0;
    layer = arg1;

    uv[3] = 0; uv[2] = 0; uv[1] = 0; uv[0] = 0;
    rect[3] = 0; rect[2] = 0; rect[1] = 0; rect[0] = 0;

    w = fn_800E2E68(*(void **)((u8 *)self + 0x60));
    h = fn_800E2E60(*(void **)((u8 *)self + 0x60));
    a = fn_800E2E58(*(void **)((u8 *)self + 0x60));
    sum = h + fn_800E2E50(*(void **)((u8 *)self + 0x60));

    diff = *(s32 *)((u8 *)self + 0x78) - 0x28;
    if (diff >= 0) {
        pad = diff * 5 + 1;
        half = h / 2;
        uv[1] = sum;
        uv[2] = a;
        uv[0] = pad + a;
        uv[3] = half + sum;
        sp8 = 0xFF;
        spC = 0;
        obj38 = *(void **)((u8 *)self + 0x38);
        x0 = w - pad;
        x0 = *(s32 *)((u8 *)obj38 + 0x60) + x0;
        x0 = *(s32 *)((u8 *)self + 0x48) + x0;
        rect[0] = x0;
        ySave = half + *(s32 *)((u8 *)obj38 + 0x64);
        ySave = *(s32 *)((u8 *)self + 0x4C) + ySave;
        rect[2] = x0 + pad;
        rect[1] = ySave;
        rect[3] = ySave + half;
        SpriteSheet_DrawUvRect(*(void **)((u8 *)self + 0x60), layer, uv, rect,
                               *(s32 *)((u8 *)self + 0x44), 0xFF, 0xFF, 0xFF, sp8, spC);
        copy[0] = rect[0];
        bl = *(u8 *)((u8 *)self + 0x52);
        ySave = rect[1];
        dh = rect[3] - ySave;
        copy[2] = rect[2];
        g = *(u8 *)((u8 *)self + 0x51);
        r = *(u8 *)((u8 *)self + 0x50);
        copy[3] = rect[3];
        copy[1] = ySave;
        obj38 = *(void **)((u8 *)self + 0x38);
        alpha = (s32)(*(f32 *)((u8 *)obj38 + 0x6C) * (f32)*(u8 *)((u8 *)self + 0x53));
        Prim2D_Begin();
        {
            s32 t = *(s32 *)((u8 *)self + 0x44) - 1;
            Prim2D_SetTransform(lbl_8036AE88, lbl_8036AE88, (f32)t, lbl_8036AE8C);
        }
        Prim2D_SetTex(0, 0x20);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)copy[0], (f32)ySave, (f32)(copy[2] - copy[0]), (f32)dh);
        Prim2D_SetColor(r, g, bl, (u8)alpha);
        Prim2D_EndPrim();
    }

    if (*(s32 *)((u8 *)self + 0x78) > 0x28) {
        diff = 0x28;
        pad = diff * 5 + 1;
        half = h / 2;
        uv[1] = sum;
        uv[2] = a;
        uv[0] = pad + a;
        uv[3] = half + sum;
        sp8 = 0xFF;
        spC = 0;
        obj38 = *(void **)((u8 *)self + 0x38);
        x0 = w - pad;
        x0 = *(s32 *)((u8 *)obj38 + 0x60) + x0;
        x0 = *(s32 *)((u8 *)self + 0x48) + x0;
        rect[0] = x0;
        ySave = *(s32 *)((u8 *)self + 0x4C) + *(s32 *)((u8 *)obj38 + 0x64);
        rect[2] = x0 + pad;
        rect[1] = ySave;
        rect[3] = ySave + half;
        SpriteSheet_DrawUvRect(*(void **)((u8 *)self + 0x60), layer, uv, rect,
                               *(s32 *)((u8 *)self + 0x44), 0xFF, 0xFF, 0xFF, sp8, spC);
        copyb[0] = rect[0];
        bl = *(u8 *)((u8 *)self + 0x52);
        ySave = rect[1];
        dh = rect[3] - ySave;
        copyb[2] = rect[2];
        g = *(u8 *)((u8 *)self + 0x51);
        r = *(u8 *)((u8 *)self + 0x50);
        copyb[3] = rect[3];
        copyb[1] = ySave;
        obj38 = *(void **)((u8 *)self + 0x38);
        alpha = (s32)(*(f32 *)((u8 *)obj38 + 0x6C) * (f32)*(u8 *)((u8 *)self + 0x53));
        Prim2D_Begin();
        {
            s32 t = *(s32 *)((u8 *)self + 0x44) - 1;
            Prim2D_SetTransform(lbl_8036AE88, lbl_8036AE88, (f32)t, lbl_8036AE8C);
        }
        Prim2D_SetTex(0, 0x20);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)copyb[0], (f32)ySave, (f32)(copyb[2] - copyb[0]), (f32)dh);
        Prim2D_SetColor(r, g, bl, (u8)alpha);
        Prim2D_EndPrim();
    }
}

void fn_80196F10(void *arg0, s32 arg1) {
    extern void SpriteSheet_DrawUvRect(void *, s32, s32 *, s32 *, s32, s32, s32, s32, s32, s32);
    extern void Prim2D_Begin(void);
    extern void Prim2D_SetTransform(f32, f32, f32, f32);
    extern void Prim2D_SetTex(s32, s32);
    extern void Prim2D_PrepareTex(void);
    extern void Prim2D_AddPrim(s32);
    extern void Prim2D_SetRect(f32, f32, f32, f32);
    extern void Prim2D_SetColor(u8, u8, u8, u8);
    extern void Prim2D_EndPrim(void);
    extern s32 fn_800E2E50(void *);
    extern s32 fn_800E2E58(void *);
    extern s32 fn_800E2E60(void *);
    extern s32 fn_800E2E68(void *);
    extern f32 lbl_8036AE88;
    extern f32 lbl_8036AE8C;
    extern f32 lbl_8036AEA0;
    s32 copy2b[4];
    s32 copy2a[4];
    s32 copy4[4];
    s32 rect2a[4];
    s32 rect1a[4];
    s32 rect2c[4];
    s32 rect1c[4];
    s32 rect2b[4];
    s32 rect1b[4];
    s32 rect2d[4];
    s32 rect1d[4];
    void *self;
    s32 arg;
    s32 a, b, c, d, pad, x0, y0, h, alpha, padbase, yp, db;
    void *obj38;
    u8 r, g, bl;

    self = arg0;
    arg = arg1;
    padbase = *(s32 *)((u8 *)self + 0x70) - 0x28;
    copy2b[3] = 0; copy2b[2] = 0; copy2b[1] = 0; copy2b[0] = 0;
    rect1a[3] = 0; rect1a[2] = 0; rect1a[1] = 0; rect1a[0] = 0;
    rect2a[3] = 0; rect2a[2] = 0; rect2a[1] = 0; rect2a[0] = 0;
    fn_800E2E68(*(void **)((u8 *)self + 0x60));
    d = fn_800E2E60(*(void **)((u8 *)self + 0x60));
    a = fn_800E2E58(*(void **)((u8 *)self + 0x60));
    b = fn_800E2E50(*(void **)((u8 *)self + 0x60));
    pad = padbase * 5 + 1;
    db = d + b;
    rect1a[0] = a;
    rect1a[1] = db;
    rect1a[2] = pad + a;
    rect1a[3] = d + db;
    obj38 = *(void **)((u8 *)self + 0x38);
    x0 = (s32)(*(f32 *)((u8 *)obj38 + 0x68) + (f32)(*(s32 *)((u8 *)self + 0x48) + *(s32 *)((u8 *)obj38 + 0x60)));
    rect2a[0] = x0;
    y0 = *(s32 *)((u8 *)self + 0x4C) + *(s32 *)((u8 *)obj38 + 0x64);
    yp = y0 + 4;
    rect2a[1] = y0;
    rect2a[3] = yp + d;
    rect2a[1] = yp;
    rect2a[2] = x0 + pad;
    SpriteSheet_DrawUvRect(*(void **)((u8 *)self + 0x60), arg, rect1a, rect2a,
                *(s32 *)((u8 *)self + 0x44), 0x5A, 0x5A, 0x5A,
                (s32)(lbl_8036AEA0 * *(f32 *)((u8 *)obj38 + 0x6C)), 0);
    *(s32 *)((u8 *)self + 0x44) = *(s32 *)((u8 *)self + 0x44) - 1;

    padbase = *(s32 *)((u8 *)self + 0x78) - 0x28;
    if (padbase >= 0) {
        rect1b[3] = 0; rect1b[2] = 0; rect1b[1] = 0; rect1b[0] = 0;
        rect2b[3] = 0; rect2b[2] = 0; rect2b[1] = 0; rect2b[0] = 0;
        fn_800E2E68(*(void **)((u8 *)self + 0x60));
        d = fn_800E2E60(*(void **)((u8 *)self + 0x60));
        a = fn_800E2E58(*(void **)((u8 *)self + 0x60));
        b = fn_800E2E50(*(void **)((u8 *)self + 0x60));
        pad = padbase * 5 + 1;
        db = d + b;
        rect1b[0] = a;
        rect1b[1] = db;
        rect1b[2] = pad + a;
        rect1b[3] = d + db;
        obj38 = *(void **)((u8 *)self + 0x38);
        x0 = (s32)(*(f32 *)((u8 *)obj38 + 0x68) + (f32)(*(s32 *)((u8 *)self + 0x48) + *(s32 *)((u8 *)obj38 + 0x60)));
        rect2b[0] = x0;
        y0 = *(s32 *)((u8 *)self + 0x4C) + *(s32 *)((u8 *)obj38 + 0x64);
        yp = y0 + 4;
        rect2b[1] = y0;
        rect2b[3] = yp + d;
        rect2b[1] = yp;
        rect2b[2] = x0 + pad;
        SpriteSheet_DrawUvRect(*(void **)((u8 *)self + 0x60), arg, rect1b, rect2b,
                    *(s32 *)((u8 *)self + 0x44), 0xFF, 0xFF, 0xFF,
                    (s32)(lbl_8036AEA0 * *(f32 *)((u8 *)obj38 + 0x6C)), 0);

        obj38 = *(void **)((u8 *)self + 0x38);
        copy2b[0] = rect2b[0];
        bl = *(u8 *)((u8 *)self + 0x52);
        copy2b[1] = rect2b[1];
        copy2b[2] = rect2b[2];
        g = *(u8 *)((u8 *)self + 0x51);
        r = *(u8 *)((u8 *)self + 0x50);
        copy2b[3] = rect2b[3];
        h = rect2b[3] - rect2b[1];
        copy2a[0] = rect2b[0];
        copy2a[1] = rect2b[1];
        copy2a[2] = rect2b[2];
        copy2a[3] = rect2b[3];
        alpha = (s32)(*(f32 *)((u8 *)obj38 + 0x6C) * (f32)*(u8 *)((u8 *)self + 0x53));
        Prim2D_Begin();
        {
            s32 t = *(s32 *)((u8 *)self + 0x44) - 1;
            Prim2D_SetTransform(lbl_8036AE88, lbl_8036AE88, (f32)t, lbl_8036AE8C);
        }
        Prim2D_SetTex(0, 0x20);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetRect((f32)copy2a[0], (f32)rect2b[1], (f32)(copy2a[2] - copy2a[0]), (f32)h);
        Prim2D_SetColor(r, g, bl, (u8)alpha);
        Prim2D_EndPrim();
        *(s32 *)((u8 *)self + 0x44) = *(s32 *)((u8 *)self + 0x44) + 1;
    }

    h = *(s32 *)((u8 *)self + 0x78);
    if (h > 0x28) {
        h = 0x28;
    }
    rect1c[3] = 0; rect1c[2] = 0; rect1c[1] = 0; rect1c[0] = 0;
    rect2c[3] = 0; rect2c[2] = 0; rect2c[1] = 0; rect2c[0] = 0;
    fn_800E2E68(*(void **)((u8 *)self + 0x60));
    d = fn_800E2E60(*(void **)((u8 *)self + 0x60));
    a = fn_800E2E58(*(void **)((u8 *)self + 0x60));
    b = fn_800E2E50(*(void **)((u8 *)self + 0x60));
    db = d + b;
    rect1c[0] = a;
    rect1c[1] = db;
    rect1c[2] = a + 0xC9;
    rect1c[3] = d + db;
    obj38 = *(void **)((u8 *)self + 0x38);
    x0 = (s32)(*(f32 *)((u8 *)obj38 + 0x68) + (f32)(*(s32 *)((u8 *)self + 0x48) + *(s32 *)((u8 *)obj38 + 0x60)));
    rect2c[0] = x0;
    y0 = *(s32 *)((u8 *)self + 0x4C) + *(s32 *)((u8 *)obj38 + 0x64);
    yp = y0 - 8;
    rect2c[1] = y0;
    rect2c[3] = yp + d;
    rect2c[1] = yp;
    rect2c[2] = x0 + 0xC9;
    SpriteSheet_DrawUvRect(*(void **)((u8 *)self + 0x60), arg, rect1c, rect2c,
                *(s32 *)((u8 *)self + 0x44), 0x5A, 0x5A, 0x5A,
                (s32)(lbl_8036AEA0 * *(f32 *)((u8 *)obj38 + 0x6C)), 0);
    *(s32 *)((u8 *)self + 0x44) = *(s32 *)((u8 *)self + 0x44) - 1;

    rect1d[3] = 0; rect1d[2] = 0; rect1d[1] = 0; rect1d[0] = 0;
    rect2d[3] = 0; rect2d[2] = 0; rect2d[1] = 0; rect2d[0] = 0;
    fn_800E2E68(*(void **)((u8 *)self + 0x60));
    d = fn_800E2E60(*(void **)((u8 *)self + 0x60));
    a = fn_800E2E58(*(void **)((u8 *)self + 0x60));
    b = fn_800E2E50(*(void **)((u8 *)self + 0x60));
    pad = h * 5 + 1;
    db = d + b;
    rect1d[0] = a;
    rect1d[1] = db;
    rect1d[2] = pad + a;
    rect1d[3] = d + db;
    obj38 = *(void **)((u8 *)self + 0x38);
    x0 = (s32)(*(f32 *)((u8 *)obj38 + 0x68) + (f32)(*(s32 *)((u8 *)self + 0x48) + *(s32 *)((u8 *)obj38 + 0x60)));
    rect2d[0] = x0;
    y0 = *(s32 *)((u8 *)self + 0x4C) + *(s32 *)((u8 *)obj38 + 0x64);
    yp = y0 - 8;
    rect2d[1] = y0;
    rect2d[3] = yp + d;
    rect2d[1] = yp;
    rect2d[2] = x0 + pad;
    SpriteSheet_DrawUvRect(*(void **)((u8 *)self + 0x60), arg, rect1d, rect2d,
                *(s32 *)((u8 *)self + 0x44), 0xFF, 0xFF, 0xFF,
                (s32)(lbl_8036AEA0 * *(f32 *)((u8 *)obj38 + 0x6C)), 0);

    obj38 = *(void **)((u8 *)self + 0x38);
    copy2b[0] = rect2d[0];
    bl = *(u8 *)((u8 *)self + 0x52);
    copy2b[1] = rect2d[1];
    copy2b[2] = rect2d[2];
    g = *(u8 *)((u8 *)self + 0x51);
    r = *(u8 *)((u8 *)self + 0x50);
    copy2b[3] = rect2d[3];
    h = rect2d[3] - rect2d[1];
    copy4[0] = rect2d[0];
    copy4[1] = rect2d[1];
    copy4[2] = rect2d[2];
    copy4[3] = rect2d[3];
    alpha = (s32)(*(f32 *)((u8 *)obj38 + 0x6C) * (f32)*(u8 *)((u8 *)self + 0x53));
    Prim2D_Begin();
    {
        s32 t = *(s32 *)((u8 *)self + 0x44) - 1;
        Prim2D_SetTransform(lbl_8036AE88, lbl_8036AE88, (f32)t, lbl_8036AE8C);
    }
    Prim2D_SetTex(0, 0x20);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)copy4[0], (f32)rect2d[1], (f32)(copy4[2] - copy4[0]), (f32)h);
    Prim2D_SetColor(r, g, bl, (u8)alpha);
    Prim2D_EndPrim();
}

#pragma global_optimizer reset
void fn_801976A4(void *arg0, s32 arg1) {
    void Prim2D_SetColor(u8, u8, u8, u8);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    s32 fn_800E2E50(void *);
    s32 fn_800E2E58(void *);
    s32 fn_800E2E60(void *);
    s32 fn_800E2E68(void *);
    void SpriteSheet_DrawUvRect(void *, s32, s32 *, s32 *, s32, s32, s32, s32, s32, s32);
    extern f32 lbl_8036AE88;
    extern f32 lbl_8036AE8C;
    extern f32 lbl_8036AEA0;
    extern f64 lbl_8036AE90;
    extern f64 lbl_8036AE98;

    s32 rect1[4];
    s32 rect2[4];
    s32 copyb[4];
    s32 rect1b[4];
    s32 rect2b[4];
    s32 copy[4];
    void *self;
    s32 arg;
    s32 a, b, d, pad;
    void *obj38;
    u8 r, g, bl;
    s32 sp8, spC, h, alpha;

    self = arg0;
    arg = arg1;

    rect1[3] = 0; rect1[2] = 0; rect1[1] = 0; rect1[0] = 0;
    rect2[3] = 0; rect2[2] = 0; rect2[1] = 0; rect2[0] = 0;
    a = fn_800E2E58(*(void **)((u8 *)self + 0x60));
    b = fn_800E2E50(*(void **)((u8 *)self + 0x60));
    fn_800E2E68(*(void **)((u8 *)self + 0x60));
    d = fn_800E2E60(*(void **)((u8 *)self + 0x60));
    pad = *(s32 *)((u8 *)self + 0x70) * 5 + 1;
    rect1[1] = b;
    rect1[2] = a;
    rect1[3] = d + b;
    rect1[0] = pad + a;
    obj38 = *(void **)((u8 *)self + 0x38);
    b = (s32)((f32)(*(s32 *)((u8 *)self + 0x48) + *(s32 *)((u8 *)obj38 + 0x60)) + *(f32 *)((u8 *)obj38 + 0x68));
    rect2[0] = b;
    b = *(s32 *)((u8 *)self + 0x4C) + *(s32 *)((u8 *)obj38 + 0x64);
    rect2[2] = rect2[0] + pad;
    rect2[1] = b - 1;
    rect2[3] = rect2[1] + d;
    sp8 = (s32)(lbl_8036AEA0 * *(f32 *)((u8 *)obj38 + 0x6C));
    spC = 0;
    SpriteSheet_DrawUvRect(*(void **)((u8 *)self + 0x60), arg, rect1, rect2,
                *(s32 *)((u8 *)self + 0x44), 0x5A, 0x5A, 0x5A, sp8, 0);

    *(s32 *)((u8 *)self + 0x44) = *(s32 *)((u8 *)self + 0x44) - 1;

    rect1b[3] = 0; rect1b[2] = 0; rect1b[1] = 0; rect1b[0] = 0;
    rect2b[3] = 0; rect2b[2] = 0; rect2b[1] = 0; rect2b[0] = 0;
    a = fn_800E2E58(*(void **)((u8 *)self + 0x60));
    b = fn_800E2E50(*(void **)((u8 *)self + 0x60));
    fn_800E2E68(*(void **)((u8 *)self + 0x60));
    d = fn_800E2E60(*(void **)((u8 *)self + 0x60));
    pad = *(s32 *)((u8 *)self + 0x78) * 5 + 1;
    rect1b[1] = b;
    rect1b[2] = a;
    rect1b[3] = d + b;
    rect1b[0] = pad + a;
    obj38 = *(void **)((u8 *)self + 0x38);
    b = (s32)((f32)(*(s32 *)((u8 *)self + 0x48) + *(s32 *)((u8 *)obj38 + 0x60)) + *(f32 *)((u8 *)obj38 + 0x68));
    rect2b[0] = b;
    b = *(s32 *)((u8 *)self + 0x4C) + *(s32 *)((u8 *)obj38 + 0x64);
    rect2b[2] = rect2b[0] + pad;
    rect2b[1] = b - 1;
    rect2b[3] = rect2b[1] + d;
    sp8 = (s32)(lbl_8036AEA0 * *(f32 *)((u8 *)obj38 + 0x6C));
    spC = 0;
    SpriteSheet_DrawUvRect(*(void **)((u8 *)self + 0x60), arg, rect1b, rect2b,
                *(s32 *)((u8 *)self + 0x44), 0xFF, 0xFF, 0xFF, sp8, 0);

    copy[0] = rect2b[0];
    bl = *(u8 *)((u8 *)self + 0x52);
    copy[1] = rect2b[1];
    g = *(u8 *)((u8 *)self + 0x51);
    copy[2] = rect2b[2];
    r = *(u8 *)((u8 *)self + 0x50);
    copy[3] = rect2b[3];
    h = rect2b[3] - rect2b[1];
    alpha = (s32)(*(f32 *)((u8 *)obj38 + 0x6C) * (f32)*(u8 *)((u8 *)self + 0x53));
    Prim2D_Begin();
    {
        s32 t = *(s32 *)((u8 *)self + 0x44) - 1;
        Prim2D_SetTransform(lbl_8036AE88, lbl_8036AE88, (f32)t, lbl_8036AE8C);
    }
    Prim2D_SetTex(0, 0x20);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)copy[0], (f32)copy[1], (f32)(copy[2] - copy[0]), (f32)h);
    Prim2D_SetColor(r, g, bl, (u8)alpha);
    Prim2D_EndPrim();
}

#pragma cplusplus on
#pragma global_optimizer off
extern "C" void fn_80197A78(void *arg0, s32 arg1)
{
    extern void Prim2D_SetColor(u8, u8, u8, u8);
    extern void Prim2D_SetRect(f32, f32, f32, f32);
    extern void Prim2D_EndPrim(void);
    extern void Prim2D_AddPrim(s32);
    extern void Prim2D_SetTransform(f32, f32, f32, f32);
    extern void Prim2D_SetTex(s32, s32);
    extern void Prim2D_PrepareTex(void);
    extern void Prim2D_Begin(void);
    extern s32 fn_800E2E50(void *);
    extern s32 fn_800E2E58(void *);
    extern s32 fn_800E2E60(void *);
    extern s32 fn_800E2E68(void *);
    extern void SpriteSheet_DrawUvRect(void *, s32, s32 *, s32 *, s32, s32, s32, s32, s32, s32);
    extern void fn_80196AD0(void *, s32);
    extern void fn_80196F10(void *, s32);
    extern void fn_801976A4(void *, s32);
    extern f32 lbl_8036AE88;
    extern f32 lbl_8036AE8C;

    s32 copy[4];
    s32 rect2[4];
    s32 rect1[4];
    s32 copyb[4];
    s32 rect2b[4];
    s32 rect1b[4];
    void *self;
    s32 arg;
    s32 a, b, c, d, pad, x0, y0, h, alpha;
    void *obj38;
    u8 r, g, bl;

    self = arg0;
    arg = arg1;
    switch (*(s32 *)((u8 *)self + 0x6C)) {
    case 0:
        if (*(s32 *)((u8 *)self + 0x70) <= 0x28) {
            fn_801976A4(self, arg);
        } else {
            fn_80196F10(self, arg);
        }
        break;
    case 1:
        if (*(s32 *)((u8 *)self + 0x70) <= 0x28) {
            rect1[3] = 0; rect1[2] = 0; rect1[1] = 0; rect1[0] = 0;
            rect2[3] = 0; rect2[2] = 0; rect2[1] = 0; rect2[0] = 0;
            a = fn_800E2E58(*(void **)((u8 *)self + 0x60));
            b = fn_800E2E50(*(void **)((u8 *)self + 0x60));
            c = fn_800E2E68(*(void **)((u8 *)self + 0x60));
            d = fn_800E2E60(*(void **)((u8 *)self + 0x60));
            pad = *(s32 *)((u8 *)self + 0x78) * 5 + 1;
            rect1[1] = b;
            rect1[2] = a;
            rect1[3] = d + b;
            rect1[0] = pad + a;
            obj38 = *(void **)((u8 *)self + 0x38);
            x0 = *(s32 *)((u8 *)self + 0x48) + (*(s32 *)((u8 *)obj38 + 0x60) + (c - pad));
            rect2[0] = x0;
            y0 = *(s32 *)((u8 *)self + 0x4C) + *(s32 *)((u8 *)obj38 + 0x64);
            rect2[2] = x0 + pad;
            rect2[1] = y0;
            rect2[3] = y0 + d;
            SpriteSheet_DrawUvRect(*(void **)((u8 *)self + 0x60), arg, rect1, rect2,
                        *(s32 *)((u8 *)self + 0x44), 0xFF, 0xFF, 0xFF, 0xFF, 0);
            obj38 = *(void **)((u8 *)self + 0x38);
            copy[0] = rect2[0];
            bl = *(u8 *)((u8 *)self + 0x52);
            copy[1] = rect2[1];
            copy[2] = rect2[2];
            g = *(u8 *)((u8 *)self + 0x51);
            r = *(u8 *)((u8 *)self + 0x50);
            copy[3] = rect2[3];
            h = rect2[3] - rect2[1];
            alpha = (s32)(*(f32 *)((u8 *)obj38 + 0x6C) * (f32)*(u8 *)((u8 *)self + 0x53));
            Prim2D_Begin();
            {
                s32 t = *(s32 *)((u8 *)self + 0x44) - 1;
                Prim2D_SetTransform(lbl_8036AE88, lbl_8036AE88, (f32)t, lbl_8036AE8C);
            }
            Prim2D_SetTex(0, 0x20);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect((f32)copy[0], (f32)copy[1], (f32)(copy[2] - copy[0]), (f32)h);
            Prim2D_SetColor(r, g, bl, (u8)alpha);
            Prim2D_EndPrim();
        } else {
            fn_80196AD0(self, arg);
        }
        break;
    case 2:
        rect1b[3] = 0; rect1b[2] = 0; rect1b[1] = 0; rect1b[0] = 0;
        rect2b[3] = 0; rect2b[2] = 0; rect2b[1] = 0; rect2b[0] = 0;
        {
            s32 rem = *(s32 *)((u8 *)self + 0x84) % 100;
            a = fn_800E2E58(*(void **)((u8 *)self + 0x60));
            b = fn_800E2E50(*(void **)((u8 *)self + 0x60));
            c = fn_800E2E68(*(void **)((u8 *)self + 0x60));
            d = fn_800E2E60(*(void **)((u8 *)self + 0x60));
            rect1b[0] = a;
            rect1b[1] = b;
            rect1b[2] = c + a;
            rect1b[3] = d + b;
            obj38 = *(void **)((u8 *)self + 0x38);
            x0 = *(s32 *)((u8 *)self + 0x48) + *(s32 *)((u8 *)obj38 + 0x60);
            rect2b[0] = x0;
            y0 = *(s32 *)((u8 *)self + 0x4C) + *(s32 *)((u8 *)obj38 + 0x64);
            rect2b[2] = x0 + (c * rem) / 100;
            rect2b[1] = y0;
            rect2b[3] = y0 + d;
            SpriteSheet_DrawUvRect(*(void **)((u8 *)self + 0x60), arg, rect1b, rect2b,
                        *(s32 *)((u8 *)self + 0x44), 0xFF, 0xFF, 0xFF, 0xFF, 0);
            obj38 = *(void **)((u8 *)self + 0x38);
            copyb[0] = rect2b[0];
            bl = *(u8 *)((u8 *)self + 0x52);
            copyb[1] = rect2b[1];
            copyb[2] = rect2b[2];
            g = *(u8 *)((u8 *)self + 0x51);
            r = *(u8 *)((u8 *)self + 0x50);
            copyb[3] = rect2b[3];
            h = rect2b[3] - rect2b[1];
            alpha = (s32)(*(f32 *)((u8 *)obj38 + 0x6C) * (f32)*(u8 *)((u8 *)self + 0x53));
            Prim2D_Begin();
            {
                s32 t = *(s32 *)((u8 *)self + 0x44) - 1;
                Prim2D_SetTransform(lbl_8036AE88, lbl_8036AE88, (f32)t, lbl_8036AE8C);
            }
            Prim2D_SetTex(0, 0x20);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect((f32)copyb[0], (f32)copyb[1], (f32)(copyb[2] - copyb[0]), (f32)h);
            Prim2D_SetColor(r, g, bl, (u8)alpha);
            Prim2D_EndPrim();
        }
        break;
    }
}
#pragma global_optimizer reset
extern "C" void fn_80197F5C(void *arg0) {
void fn_80123300(void *,s32); void fn_801232F4(void *,f32,f32); void Ui_PlaySeCue(void *,s32);
f64 sin(f64);
extern void *gGame;
extern u8 lbl_8027A780[];
extern f32 lbl_8036AE88,lbl_8036AE8C,lbl_8036AEA0,lbl_8036AEA4;
struct Obj {u8 pad[0x40];
virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0;
virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0;
virtual void v8()=0; virtual void v9()=0; virtual void v10()=0;
virtual void color(u8,u8,u8,u8)=0;
};
u8 *self=(u8 *)arg0; u8 *owner=*(u8 **)self;
s32 value; f32 zero,wave; Obj *obj; u8 c;
value=(*(s32 *)(self+0x78));
if(value>0 && (*(s32 *)(self+0x7C))<value) {
if(--(*(s32 *)(self+0x8C))<=0) {
(*(s32 *)(self+0x78))--;(*(s32 *)(self+0x8C))=1;
fn_80123300((*(void * *)(self+0x64)),(*(s32 *)(self+0x78)));
if((*(s32 *)(self+0x7C))==(value=(*(s32 *)(self+0x78))) || value==0) {
fn_801232F4((*(void * *)(self+0x64)),lbl_8036AE8C,*(f32 *)((u8 *)gGame+0xAC));(*(s32 *)(self+0x8C))=-1;
}
}
}
value=(*(s32 *)(self+0x78));
if(value<(*(s32 *)(self+0x70)) && (*(s32 *)(self+0x7C))>value) {
if(--(*(s32 *)(self+0x8C))<=0) {
(*(s32 *)(self+0x78))++;(*(s32 *)(self+0x8C))=3;
Ui_PlaySeCue(lbl_8027A780+8,100);fn_80123300((*(void * *)(self+0x64)),(*(s32 *)(self+0x78)));
if((*(s32 *)(self+0x7C))==(*(s32 *)(self+0x78))) (*(s32 *)(self+0x8C))=-1;
}
}
if((*(s32 *)(self+0x88))>(*(s32 *)(self+0x84))) {
if(--(*(s32 *)(self+0x8C))<=0) {
(*(s32 *)(self+0x84))++;(*(s32 *)(self+0x8C))=1;
Ui_PlaySeCue(lbl_8027A780+0x1C,100);fn_80123300((*(void * *)(self+0x64)),(*(s32 *)(self+0x84))%100);
if((*(s32 *)(self+0x88))==(*(s32 *)(self+0x84))) (*(s32 *)(self+0x8C))=-1;
}
}
if((*(s32 *)(self+0x6C))!=2 && (*(s32 *)(self+0x98))==0) {
wave=lbl_8036AEA0*(f32)sin((f32)*(s32 *)(owner+0x44) * *(f32 *)((u8 *)gGame+0xD4));
if(wave<lbl_8036AE88) wave*=lbl_8036AEA4;
(*(u8 *)(self+0x52))=64;(*(u8 *)(self+0x51))=64;(*(u8 *)(self+0x50))=64;(*(u8 *)(self+0x53))=(s8)(s32)wave;
}
if((*(s32 *)(self+0x98))!=0) {
(*(u8 *)(self+0x50))=255; (*(u8 *)(self+0x52))=64; (*(u8 *)(self+0x51))=64; (*(u8 *)(self+0x53))=(s8)(s32)(*(f32 *)(self+0x90));
if((*(u8 *)(self+0x9C))!=0) {
obj=(Obj *)(*(void * *)(self+0x68)); if(obj) obj->color(255,255,255,(*(u8 *)(self+0x53)));
} else {
obj=(Obj *)(*(void * *)(self+0x64));c=255-(*(u8 *)(self+0x53));obj->color(255,c,c,255);
}
wave=(*(f32 *)(self+0x90)); zero=lbl_8036AE88; wave+=(*(f32 *)(self+0x94)); (*(f32 *)(self+0x90))=wave;
if((*(f32 *)(self+0x90))<zero) {
(*(f32 *)(self+0x90))=zero; ((Obj *)(*(void * *)(self+0x64)))->color(255,255,255,255);
}
(*(s32 *)(self+0x98))--;
}
}
extern "C" void *fn_80198288(void *arg0, void *arg1, void *arg2) {
    void fn_800E2CF4(void *);
    void fn_800C9ABC(void *, void *, void *);
    void fn_800C8DCC(void *, void *, void *);
    void fn_800C96F8(void *, void *, u32);
    void fn_800C9A60(void *, s32);
    void *fn_800C93EC(void *);
    s32 fn_800E7FB4(void *, void *);
    void fn_80123300(void *, s32);
    u32 strlen(const char *);
    extern u8 lbl_80296778[];
    extern u8 lbl_8027A780[];
    extern f32 lbl_8036AE88;

    typedef struct {
        u32 size;
        u32 cap;
        char *data;
    } String;

    struct VObj {
        u8 pad[0x10];
        virtual void *v0(char *, void *) = 0;
        virtual void *v1(char *, void *) = 0;
        virtual void *v2(char *, void *) = 0;
    };

    typedef struct {
        void *unk00;
        u8 pad04[0x3C];
        void *vtable;
        u8 pad44[0x10];
        String str54;
        void *unk60;
        void *unk64;
        void *unk68;
        s32 unk6C;
        s32 unk70;
        s32 unk74;
        s32 unk78;
        s32 unk7C;
        s32 unk80;
        s32 unk84;
        s32 unk88;
        s32 unk8C;
        f32 unk90;
        f32 unk94;
        s32 unk98;
        u8 unk9C;
    } Obj;

    char sp12C[0x20];
    char sp10C[0x20];
    char spEC[0x20];
    char spCC[0x20];
    char spAC[0x20];
    char sp8C[0x20];
    String sp80;
    String sp74;
    String sp68;
    String sp5C;
    String sp50;
    String sp44;
    String sp38;
    String sp2C;
    String sp20;
    u8 sp1C[4];
    u8 sp18[4];
    u8 sp14[4];
    u8 sp10[4];
    u8 spC[4];
    u8 sp8[4];
    void *saved;
    Obj *path;
    Obj *self;
    Obj *buf;
    s32 temp;
    f32 z;

    path = (Obj *)arg2;
    self = (Obj *)arg0;
    fn_800E2CF4(arg0);
    self->vtable = lbl_80296778;

    self->str54.size = 0;
    self->str54.cap = 0;
    self->str54.data = 0;
    self->str54.cap = 0;

    saved = self->unk00;

    sp80.cap = 0;
    sp74.cap = 0;
    sp68.cap = 0;
    sp80.size = 0;
    sp80.data = 0;
    sp80.cap = 0;
    sp74.size = 0;
    sp74.data = 0;
    sp74.cap = 0;
    sp68.size = 0;
    sp68.data = 0;
    sp68.cap = 0;

    fn_800C9ABC(&sp5C, lbl_8027A780 + 0x2E, &sp1C);
    fn_800C8DCC(sp12C, path, &sp5C);
    buf = (Obj *)sp12C;
    fn_800C96F8(&self->str54, buf, strlen((char *)buf));
    fn_800C9A60(&sp5C, -1);

    fn_800C9ABC(&sp50, lbl_8027A780 + 0x36, &sp18);
    fn_800C8DCC(sp10C, path, &sp50);
    buf = (Obj *)sp10C;
    fn_800C96F8(&sp74, buf, strlen((char *)buf));
    fn_800C9A60(&sp50, -1);

    fn_800C9ABC(&sp44, lbl_8027A780 + 0x3E, &sp14);
    fn_800C8DCC(spEC, path, &sp44);
    buf = (Obj *)spEC;
    fn_800C96F8(&sp68, buf, strlen((char *)buf));
    fn_800C9A60(&sp44, -1);

    fn_800C9ABC(&sp38, lbl_8027A780 + 0x47, &sp10);
    fn_800C8DCC(spCC, path, &sp38);
    self->unk6C = *(s32 *)spCC;
    fn_800C9A60(&sp38, -1);

    fn_800C9ABC(&sp2C, lbl_8027A780 + 0x4C, &spC);
    fn_800C8DCC(spAC, path, &sp2C);
    temp = *(s32 *)spAC;
    self->unk78 = temp;
    self->unk74 = temp;
    self->unk70 = temp;
    fn_800C9A60(&sp2C, -1);

    self->unk7C = self->unk74;
    self->unk8C = 0;

    fn_800C9ABC(&sp20, lbl_8027A780 + 0x4F, &sp8);
    fn_800C8DCC(sp8C, path, &sp20);
    temp = *(s32 *)sp8C;
    self->unk84 = temp;
    self->unk80 = temp;
    fn_800C9A60(&sp20, -1);

    self->unk60 = (void *)fn_800E7FB4(
        (temp = self->unk80, self->unk88 = temp, self->unk98 = 0, self->unk9C = 0, saved),
        (z = lbl_8036AE88, self->unk90 = z, self->unk94 = z, &self->str54));

    self->unk64 = ((VObj *)saved)->v2((char *)(lbl_8027A780 + 0x53), fn_800C93EC(&sp74));
    self->unk68 = ((VObj *)saved)->v2((char *)(lbl_8027A780 + 0x5A), fn_800C93EC(&sp68));

    if (self->unk6C != 2) {
        fn_80123300(self->unk64, self->unk74);
    } else {
        fn_80123300(self->unk64, self->unk80);
    }

    fn_800C9A60(&sp68, -1);
    fn_800C9A60(&sp74, -1);
    fn_800C9A60(&sp80, -1);
    return self;
}
#pragma cplusplus reset

#pragma cplusplus off

void fn_801985C4(void *arg0) {
    void *x = *(void **)((u8 *)arg0 + 0x144);
    if (x != NULL) {
        fn_801517F4(x);
    }
}

void fn_801985F0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x148) = arg1;
}

void fn_801985F8(void *arg0, s32 arg1) {
    s32 temp_r0;

    if (arg1 == 1) {
        temp_r0 = M2C_FIELD(arg0, s32 *, 0x124);
        if (temp_r0 == 6) {
            M2C_FIELD(arg0, s32 *, 0x124) = 1;
            return;
        } else if (temp_r0 == 7) {
            M2C_FIELD(arg0, s32 *, 0x124) = 2;
            return;
        } else if (temp_r0 == 8) {
            M2C_FIELD(arg0, s32 *, 0x124) = 0;
            return;
        }
    }
}

s32 fn_80198640(void *arg0) {
    f32 PSVECDistance(f32 *, f32 *);
    void fn_800DBBC8(f32 *, void *);
    extern void *gGame;
    f32 result[3];
    f32 pos2[3];
    f32 pos1[3];
    f32 *p;

    p = pos1;
    p[0] = *(f32 *)((u8 *)arg0 + 0x78);
    p[1] = 0.0f;
    p[2] = 0.0f;
    p = pos2;
    p[0] = *(f32 *)((u8 *)arg0 + 0x48);
    p[1] = 0.0f;
    p[2] = 0.0f;

    if (PSVECDistance(pos1, pos2) < *(f32 *)((u8 *)gGame + 0x144)) {
        *(u8 *)((u8 *)arg0 + 0x14D) = 1;
        fn_800DBBC8(result, arg0);
        *(f32 *)((u8 *)arg0 + 0x15C) = result[0];
        *(f32 *)((u8 *)arg0 + 0x160) = result[1];
        *(f32 *)((u8 *)arg0 + 0x164) = result[2];
        return 1;
    }
    return 0;
}

void fn_801986E0(u8 *p) {
 void fn_800DB964(void *,f32,f32,f32);
 void fn_800DF664(void *);
 void fn_800E4C14(void *,f32);
 double sin(double);
 void SeCue_PlayAt(void *,s32,f32,f32,f32);
 f32 PSVECDistance(void *,void *);
 extern u8 *gGame;
 extern u8 gWeaponAttachStr[];
 f32 b[3],a[3];
 fn_800DB964(p,*(f32 *)(p+0x84),*(f32 *)(p+0x88),*(f32 *)(p+0x8C));
 *(f32 *)(p+0x84)+=*(f32 *)(p+0x90);
 *(f32 *)(p+0x88)+=*(f32 *)(p+0x94);
 *(f32 *)(p+0x8C)+=*(f32 *)(p+0x98);
 switch(*(u32 *)(p+0x124)) {
 case 1: case 6:
 *(f32 *)(p+0x54)+=*(f32 *)(gGame+0x118);
 if(*(f32 *)(p+0x4C)<0.0f) {*(f32 *)(p+80)=0.0f;
*(f32 *)(p+76)=0.0f;
*(f32 *)(p+72)=0.0f;
*(f32 *)(p+92)=0.0f;
*(f32 *)(p+88)=0.0f;
*(f32 *)(p+84)=0.0f;p[0x14C]=0;
 fn_800DF664(p);fn_800E4C14(p,-1.0f);}
 break;
 case 2: case 7:
 *(f32 *)(p+0x4C)=*(f32 *)(p+0x180)*(f32)sin(*(f32 *)(p+0x16C))+*(f32 *)(p+0x154);
 *(f32 *)(p+0x16C)+=*(f32 *)(p+0x178);
 if(*(f32 *)(p+0x16C)<0.0f) *(f32 *)(p+0x16C)=0.0f;
 *(f32 *)(p+0x58)-=*(f32 *)(gGame+0x130);
 if(*(f32 *)(p+0x58)<-360.0f) {
 *(f32 *)(p+0x58)+=720.0f;
 SeCue_PlayAt(gWeaponAttachStr+0x54,100,*(f32 *)(p+0x48),*(f32 *)(p+0x4C),*(f32 *)(p+0x50));
 }
 if(*(f32 *)(p+0x58)>360.0f) *(f32 *)(p+0x58)-=360.0f;
 a[0]=*(f32 *)(p+0x150); a[1]=0.0f; a[2]=0.0f;
 b[0]=*(f32 *)(p+0x48); b[1]=0.0f; b[2]=0.0f;
 if(PSVECDistance(a,b)<*(f32 *)(gGame+0x134)) {*(f32 *)(p+80)=0.0f;
*(f32 *)(p+76)=0.0f;
*(f32 *)(p+72)=0.0f;
*(f32 *)(p+92)=0.0f;
*(f32 *)(p+88)=0.0f;
*(f32 *)(p+84)=0.0f;p[0x14C]=0;}
 break;
 case 9:
 if(*(f32 *)(p+0x4C)<0.0f) {*(f32 *)(p+80)=0.0f;
*(f32 *)(p+76)=0.0f;
*(f32 *)(p+72)=0.0f;
*(f32 *)(p+92)=0.0f;
*(f32 *)(p+88)=0.0f;
*(f32 *)(p+84)=0.0f;p[0x14C]=0; fn_800DF664(p);}
 break;
 }
}

s32 fn_8019906C(void *arg0) {
    s32 fn_801518D0(void *, s32);
    void *v;

    v = *(void **)((u8 *)arg0 + 0x144);
    if (v != NULL) {
        return fn_801518D0(v, 0x12);
    }
    return 0;
}

s32 fn_801990A4(void *arg0) {
    s32 fn_801518D0(void *, s32);
    void *v;

    v = *(void **)((u8 *)arg0 + 0x144);
    if (v != NULL) {
        return fn_801518D0(v, 1);
    }
    return 0;
}

s32 fn_801990DC(void *arg0) {
    s32 fn_801518D0(void *, s32);
    void *v;

    v = *(void **)((u8 *)arg0 + 0x144);
    if (v != NULL) {
        return fn_801518D0(v, 0);
    }
    return 0;
}

s32 fn_80199114(void *arg0) {
    s32 fn_80151948(void *, s32);
    void *v;

    v = *(void **)((u8 *)arg0 + 0x144);
    if (v != NULL) {
        return fn_80151948(v, 0x11);
    }
    return -1;
}

void fn_8019914C(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *Heap_Alloc(s32);
    void String_Init(void *, char *, void *);
    void String_Destroy(void *, s32);
    void *fn_80151D50(void *, void *, void *, void *, void *, void *, s32);
    void fn_801518B4(void *, void *);
    extern u8 gWeaponAttachStr[];
    struct Vec3 { s32 x, y, z; };
    struct Args { void *a0, *a1, *a2, *a3; };
    struct Vec3 sp24;
    struct Vec3 sp18;
    u8 spC[0xC];
    u8 sp8[4];
    s8 flag;
    struct Args args;
    void *obj;

    args.a0 = arg0;
    args.a1 = arg1;
    args.a2 = arg2;
    args.a3 = arg3;
    flag = 0;
    obj = Heap_Alloc(0xC8);
    if (obj != NULL) {
        sp24 = *(struct Vec3 *)args.a2;
        sp18 = *(struct Vec3 *)args.a1;
        String_Init(spC, (char *)(gWeaponAttachStr + 0x76), sp8);
        flag = 1;
        obj = fn_80151D50(obj, *(void **)((u8 *)args.a0 + 0xAC), spC, (u8 *)args.a0 + 0x12C, &sp18, &sp24, 1);
    }
    *(void **)((u8 *)args.a0 + 0x144) = obj;
    if (flag) {
        String_Destroy(spC, -1);
    }
    (*(void (***)(void *, void *))((u8 *)*(void **)((u8 *)args.a0 + 0xAC) + 0x10))[7](
        *(void **)((u8 *)args.a0 + 0xAC),
        *(void **)((u8 *)args.a0 + 0x144));
    fn_801518B4(*(void **)((u8 *)args.a0 + 0x144), args.a3);
}

#pragma global_optimizer off
void fn_80199240(void *arg0) {
    s32 String_Compare(void *, s32, u32, char *, s32);
    void *String_CStr(void *);
    void GActor_RequestRes(void);
    extern u8 gWeaponAttachStr[];
    s32 len;

    len = strlen((char *)(gWeaponAttachStr + 0x7A));
    if (String_Compare((u8 *)arg0 + 0x12C, 0, *(u32 *)((u8 *)arg0 + 0x12C), (char *)(gWeaponAttachStr + 0x7A), len) != 0) {
        String_CStr((u8 *)arg0 + 0x12C);
        GActor_RequestRes();
    }
    len = strlen((char *)(gWeaponAttachStr + 0x7A));
    if (String_Compare((u8 *)arg0 + 0x138, 0, *(u32 *)((u8 *)arg0 + 0x138), (char *)(gWeaponAttachStr + 0x7A), len) != 0) {
        String_CStr((u8 *)arg0 + 0x138);
        GActor_RequestRes();
    }
}
#pragma global_optimizer reset
s32 fn_801992F0(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x128);
}

s32 fn_801992F8(void *arg0) {
    extern s32 lbl_802967B0[];
    return lbl_802967B0[M2C_FIELD(arg0, s32 *, 0x124)];
}

s32 fn_80199310(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x124);
}

void fn_80199318(s32 arg0, s32 arg1) {
    String_Copy(arg0, arg1 + 0x118);
}

void fn_8019933C(f32 *arg0, void *arg1)
{
  extern f32 lbl_8036AEA8;
  u8 *obj = (u8 *) arg1;
  void *other;
  f32 pos[3];
  f32 x;
  f32 z;
  if ((*((u8 *) (obj + 0x14D))) != 0)
  {
    x = *((f32 *) (obj + 0x15C));
    z = *((f32 *) (obj + 0x164));
  }
  else
    if ((*((u8 *) (obj + 0x14C))) != 0)
  {
    x = *((f32 *) (obj + 0x48));
    z = *((f32 *) (obj + 0x50));
  }
  else
  {
    ;
    if ((other = *((void **) (obj + 0xEC))) != 0)
    {
      void (**vtable)(f32 *, void *, s32);
      vtable = *((void (***)(f32 *, void *, s32)) (((u8 *) other) + 0x40));
      vtable[14](pos, other, 0);
      x = pos[0];
      z = pos[2];
    }
    else
    {
      x = *((f32 *) (obj + 0x48));
      z = *((f32 *) (obj + 0x50));
    }
  }
  arg0[0] = x;
  arg0[1] = lbl_8036AEA8;
  arg0[2] = z;
}

extern s32 Model_SetAlpha(u32, u8);                         /* extern */
extern void fn_8006CAD4(u32);                            /* extern */
extern u8 fn_800E49D0(void *);                           /* extern */
extern void fn_800E5A4C(void);                           /* extern */
void fn_801993E0(void *arg0) {
    void fn_8006CAD4(void *);
    u8 fn_800E49D0(void *);
    void Model_SetAlpha(void *, u8);
    void fn_800E5A4C(void);
    u8 b;

    if (*(s32 *)((u8 *)arg0 + 0x124) == 3) {
        if (*(void **)((u8 *)arg0 + 0xE0) != NULL) {
            fn_8006CAD4(*(void **)((u8 *)arg0 + 0xE0));
        }
        if (*(void **)((u8 *)arg0 + 0xE4) != NULL) {
            b = *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0xE0) + 0xB);
            Model_SetAlpha(*(void **)((u8 *)arg0 + 0xE4), (u8)((b * fn_800E49D0(*(void **)((u8 *)arg0 + 0xE0))) / 255));
            fn_8006CAD4(*(void **)((u8 *)arg0 + 0xE4));
        }
    } else {
        fn_800E5A4C();
    }
}

void fn_80199484(void *arg0) {
    M2C_UNK fn_800E5B68();
    M2C_UNK MoveAnim_SyncWeaponBones();
    if ((s32) M2C_FIELD(arg0, s32 *, 0x124) == 3) {
        MoveAnim_SyncWeaponBones();
        return;
    }
    fn_800E5B68();
}

void fn_801994B8(void *arg0, s32 arg1) {
    M2C_UNK fn_800E5DEC(void *, s32);
    M2C_UNK fn_801986E0();
    if ((u8) M2C_FIELD(arg0, u8 *, 0x14C) != 0) {
        fn_801986E0();
    }
    fn_800E5DEC(arg0, arg1);
}

extern u16 gWeaponAttachVtable[];
void* fn_80199508(void* arg0, s16 arg1) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, void**, 0x40) = gWeaponAttachVtable;
        String_Destroy((u8*)arg0 + 0x138, -1);
        String_Destroy((u8*)arg0 + 0x12C, -1);
        String_Destroy((u8*)arg0 + 0x118, -1);
        Actor_Dtor(arg0, 0);
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

#pragma use_lmw_stmw off
#pragma global_optimizer off
/* Construct a weapon-attach node from XML path attributes (kind, ids, effect names). */
void *WeaponAttach_Ctor(void *arg0, void *arg1, void *arg2) {
    void fn_800E6058(void *);
    void String_Assign(void *, void *, s32, s32);
    void String_Init(void *, char *, void *);
    void Xml_GetNamedValue(void *, void *, void *);
    void String_Destroy(void *, s32);
    void String_AssignCStr(void *, char *, u32);
    s32 String_Compare(void *, s32, u32, char *, u32);
    void String_CStr(void *);
    void GActor_RequestRes(void);
    u32 strlen(char *);
    extern u8 gWeaponAttachStr[];

    typedef struct {
        u32 size;
        u32 cap;
        char *data;
    } String;

    typedef struct {
        u8 pad00[0x40];
        void *vtable;
        u8 pad44[0xD4];
        String name;
        s32 kind;
        s32 missile;
        String effectId;
        String damageEffId;
        s32 unk144;
        s32 unk148;
        u8 unk14C;
        u8 unk14D;
        u8 pad14E[2];
        f32 unk150;
        f32 unk154;
        f32 unk158;
        f32 unk15C;
        f32 unk160;
        f32 unk164;
        f32 unk168;
        f32 unk16C;
        f32 unk170;
        f32 unk174;
        f32 unk178;
        f32 unk17C;
    } Obj;

    char bufKind[0x20];
    char bufMissile[0x20];
    char bufEffect[0x20];
    char bufDamage[0x20];
    String keyKind;
    String keyMissile;
    String keyEffect;
    String keyDamage;
    u8 allocKind[4];
    u8 allocMissile[4];
    u8 allocEffect[4];
    u8 allocDamage[4];
    char *cstr;
    Obj *path;
    Obj *self;
    f32 zero;
    s32 len;
    u8 *p;

    path = (Obj *)arg2;
    self = (Obj *)arg0;
    fn_800E6058(self);
    zero = 0.0f;
    self->vtable = gWeaponAttachVtable;
    self->name.size = 0;
    self->name.cap = 0;
    self->name.data = NULL;
    self->name.cap = 0;
    self->effectId.size = 0;
    self->effectId.cap = 0;
    self->effectId.data = NULL;
    self->effectId.cap = 0;
    self->damageEffId.size = 0;
    self->damageEffId.cap = 0;
    self->damageEffId.data = NULL;
    self->damageEffId.cap = 0;
    self->unk158 = zero;
    self->unk154 = zero;
    self->unk150 = zero;
    self->unk164 = zero;
    self->unk160 = zero;
    self->unk15C = zero;
    self->unk170 = zero;
    self->unk16C = zero;
    self->unk168 = zero;
    self->unk17C = zero;
    self->unk178 = zero;
    self->unk174 = zero;
    String_Assign(&self->name, (u8 *)self + 0x10, 0, -1);

    String_Init(&keyKind, (char *)(gWeaponAttachStr + 0x7B), allocKind);
    Xml_GetNamedValue(bufKind, path, &keyKind);
    self->kind = *(s32 *)bufKind;
    String_Destroy(&keyKind, -1);

    String_Init(&keyMissile, (char *)(gWeaponAttachStr + 0x80), allocMissile);
    Xml_GetNamedValue(bufMissile, path, &keyMissile);
    self->missile = *(s32 *)bufMissile;
    String_Destroy(&keyMissile, -1);

    String_Init(&keyEffect, (char *)(gWeaponAttachStr + 0x88), allocEffect);
    Xml_GetNamedValue(bufEffect, path, &keyEffect);
    cstr = bufEffect;
    String_AssignCStr(&self->effectId, cstr, strlen(cstr));
    String_Destroy(&keyEffect, -1);

    String_Init(&keyDamage, (char *)(gWeaponAttachStr + 0x91), allocDamage);
    Xml_GetNamedValue(bufDamage, path, &keyDamage);
    cstr = bufDamage;
    String_AssignCStr(&self->damageEffId, cstr, strlen(cstr));
    String_Destroy(&keyDamage, -1);

    self->unk144 = 0;
    self->unk14C = 0;
    self->unk14D = 0;
    self->unk148 = 0;

    len = strlen((char *)((u8 *)gWeaponAttachStr + 0x7A));
    p = (u8 *)self + 0x12C;
    if (String_Compare(p, 0, *(u32 *)p, (char *)((u32)gWeaponAttachStr + 0x7A), len) != 0) {
        String_CStr((u8 *)self + 0x12C);
        GActor_RequestRes();
    }
    len = strlen((char *)((u8 *)gWeaponAttachStr + 0x7A));
    p = (u8 *)self + 0x138;
    if (String_Compare(p, 0, *(u32 *)p, (char *)((u32)gWeaponAttachStr + 0x7A), len) != 0) {
        String_CStr((u8 *)self + 0x138);
        GActor_RequestRes();
    }
    return self;
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset
void fn_80199818(u8 *arg0) {
    u32 fn_802097D4(void);
    void fn_80145E9C(s32);
    void fn_801C7C18(u8, u8, u8);
    extern u8 lbl_80367AE8;
    extern u8 lbl_80367AEA;

    struct {
        u8 hi : 4;
        u8 mid : 2;
        u8 lo : 2;
    } *bf;
    u8 *p = arg0;

    lbl_80367AE8 = p[8];
    lbl_80367AEA = p[9];
    if (fn_802097D4() == 1) {
        bf = (void *)&p[2];
        if (bf->mid == 0) {
            bf->mid = 1;
        }
        fn_80145E9C(bf->mid);
    } else {
        bf = (void *)&p[2];
        bf->mid = 0;
        fn_80145E9C(bf->mid);
    }
    fn_801C7C18(p[6], p[7], p[5]);
}

void fn_801998B0(void *arg0) {
    u32 fn_802097D4(void);
    struct Flags {
        u8 f0:2;
        u8 f1:1;
        u8 f2:2;
        u8 f3:1;
        u8 f4:1;
        u8 f5:1;
        u8 g0:2;
        u8 g1:1;
        u8 g2:1;
        u8 g3:2;
        u8 g4:1;
        u8 g5:1;
        u8 h0:1;
        u8 h1:1;
        u8 h2:1;
        u8 h3:1;
        u8 h4:2;
        u8 h5:1;
        u8 h6:1;
        u8 i0:1;
        u8 i1:1;
        u8 i2:1;
        u8 i3:1;
        u8 i4:1;
        u8 iPad:3;
        u8 b4;
        u8 b5;
        u8 b6;
        u8 b7;
        u8 b8;
        u8 b9;
        u8 bA;
        u8 bB;
        u8 bC;
        u8 bD;
        u8 bE;
        u8 bF;
        s32 w10;
        s32 w14;
    } *p;

    p = (struct Flags *)arg0;
    p->f0 = 0;
    p->f1 = 0;
    p->f2 = 1;
    p->f3 = 0;
    p->f4 = 0;
    p->f5 = 0;
    p->g0 = 0;
    p->g1 = 0;
    p->g2 = 0;
    p->g3 = 0;
    p->g4 = 0;
    p->g5 = 0;
    p->h0 = 0;
    p->h1 = 0;
    p->h2 = 0;
    p->h3 = 1;
    p->h5 = 0;
    p->h6 = 1;
    p->i0 = 0;
    p->i1 = 0;
    p->i2 = 0;
    p->i3 = 0;
    p->i4 = 0;
    if (fn_802097D4() == 1U) {
        p->h4 = 1;
    } else {
        p->h4 = 0;
    }
    p->b4 = 0x14;
    p->b5 = 0x40;
    p->b6 = 0;
    p->b7 = 0;
    p->b8 = 0x64;
    p->b9 = 0x64;
    p->bC = 0;
    p->w10 = 0;
    p->bD = 0;
    p->bE = 0;
    p->w14 = 0;
}

void fn_80199A60(void *arg0, s32 arg1) {
    void fn_80145E9C(s32);
    void Stream_Read(s32, s32, void *);
    u8 Stream_ReadU8(s32);
    void fn_801C7C18(u8, u8, u8);
    u32 fn_802097D4(void);
    extern u8 lbl_80367AE8;
    extern u8 lbl_80367AEA;
    u8 temp;

    Stream_Read(arg1, 4, arg0);
    *(u8 *)((u8 *)arg0 + 4) = Stream_ReadU8(arg1);
    *(u8 *)((u8 *)arg0 + 5) = Stream_ReadU8(arg1);
    if ((s8)*(u8 *)((u8 *)arg0 + 5) == 0) {
        *(u8 *)((u8 *)arg0 + 5) = 0x40;
    }
    *(u8 *)((u8 *)arg0 + 6) = Stream_ReadU8(arg1);
    *(u8 *)((u8 *)arg0 + 7) = Stream_ReadU8(arg1);
    *(u8 *)((u8 *)arg0 + 8) = Stream_ReadU8(arg1);
    *(u8 *)((u8 *)arg0 + 9) = Stream_ReadU8(arg1);
    *(u8 *)((u8 *)arg0 + 0xA) = Stream_ReadU8(arg1);
    *(u8 *)((u8 *)arg0 + 0xB) = Stream_ReadU8(arg1);
    lbl_80367AE8 = *(u8 *)((u8 *)arg0 + 8);
    lbl_80367AEA = *(u8 *)((u8 *)arg0 + 9);
    if (fn_802097D4() == 1) {
        temp = *(u8 *)((u8 *)arg0 + 2);
        if (((temp >> 2) & 3) == 0) {
            *(u8 *)((u8 *)arg0 + 2) = __rlwimi(temp, 1, 2, 28, 29);
        }
        fn_80145E9C((*(u8 *)((u8 *)arg0 + 2) >> 2) & 3);
    } else {
        struct B { u8 pad[2]; u8 hi : 4; u8 mode : 2; u8 lo : 2; };
        ((struct B *)arg0)->mode = 0;
        fn_80145E9C((*(u8 *)((u8 *)arg0 + 2) >> 2) & 3);
    }
    fn_801C7C18(*(u8 *)((u8 *)arg0 + 6), *(u8 *)((u8 *)arg0 + 7), *(u8 *)((u8 *)arg0 + 5));
}

void fn_80199B88(void *arg0, s32 arg1) {
    M2C_UNK Stream_Write(s32, M2C_UNK, void *);
    M2C_UNK Stream_WriteU8(s32, u8);
    Stream_Write(arg1, 4, arg0);
    Stream_WriteU8(arg1, M2C_FIELD(arg0, u8 *, 4));
    Stream_WriteU8(arg1, M2C_FIELD(arg0, u8 *, 5));
    Stream_WriteU8(arg1, M2C_FIELD(arg0, u8 *, 6));
    Stream_WriteU8(arg1, M2C_FIELD(arg0, u8 *, 7));
    Stream_WriteU8(arg1, M2C_FIELD(arg0, u8 *, 8));
    Stream_WriteU8(arg1, M2C_FIELD(arg0, u8 *, 9));
    Stream_WriteU8(arg1, M2C_FIELD(arg0, u8 *, 0xA));
    Stream_WriteU8(arg1, M2C_FIELD(arg0, u8 *, 0xB));
}

void fn_80199C2C(void) {
    void Process_UnlinkByKey(void *);
    extern u8 lbl_802968E8[];
    s32 base;

    base = (s32)lbl_802968E8;
    Process_UnlinkByKey((void *)(base + 0x50));
    Process_UnlinkByKey((void *)(base + 0x88));
    Process_UnlinkByKey((void *)(base + 0xFC));
    Process_UnlinkByKey((void *)(base + 0x138));
    Process_UnlinkByKey((void *)(base + 0x198));
    Process_UnlinkByKey((void *)(base + 0x238));
    Process_UnlinkByKey((void *)(base + 0x2B0));
    Process_UnlinkByKey((void *)(base + 0x318));
    Process_UnlinkByKey((void *)(base + 0x3C4));
    Process_UnlinkByKey((void *)(base + 0x410));
    Process_UnlinkByKey((void *)(base + 0x474));
    Process_UnlinkByKey((void *)(base + 0x508));
    Process_UnlinkByKey((void *)(base + 0x5EC));
}

void fn_80199CC0(s32 arg0) {
    void Process_CreateChild(void *, s32);
    extern u8 lbl_80296ED4[16];
    Process_CreateChild(lbl_80296ED4, arg0);
}

void fn_80199CEC(void *arg0) {
    M2C_UNK fn_800498A4(s32, M2C_UNK, M2C_UNK);
    fn_800498A4(M2C_FIELD(arg0, s32 *, 0x34), 0, 2);
}

#pragma fp_contract off
void fn_80199D18(void *arg0) {
    void *Effect_Create(void *, s32);
    void Effect_SetPos(void *, f32, f32, f32);
    void Process_ClearFunc(void *);
    extern u8 MapSelect_str[];
    extern f32 lbl_8036AF00;
    extern f32 lbl_8036AF04;
    void *msg;
    void *obj;
    s8 a;
    s8 b;
    struct Pair { f32 first; f32 second; } pair;

    if (*(s16 *)((u8 *)arg0 + 0x48) >= *(s16 *)((u8 *)arg0 + 0x4A) - 4) {
        msg = Effect_Create(MapSelect_str + 0xCA, 0);
        a = *(s8 *)((u8 *)arg0 + 0x3C);
        b = *(s8 *)((u8 *)arg0 + 0x3D);
        Effect_SetPos(msg, lbl_8036AF00 + (f32)a, lbl_8036AF00 + (f32)b, *(f32 *)((u8 *)arg0 + 0x44));
        pair.second = lbl_8036AF04;
        pair.first = lbl_8036AF00;
        obj = *(void **)((u8 *)msg + 0x30);
        *(f32 *)((u8 *)obj + 0x18) = pair.first;
        obj = *(void **)((u8 *)msg + 0x30);
        *(f32 *)((u8 *)obj + 0x24) = pair.second;
        Process_ClearFunc(arg0);
    }
}
#pragma fp_contract reset
void MapSelect_StartMove(void *arg0) {
    /* Start a map-select cursor slide from (x0,y0) to (x1,y1): length, duration, actor, camera. */
    void fn_80053658(void *, s32, void *);
    void *Effect_Create(u8 *, void *);
    f32 Math_Angle2D(f32, f32, f32, f32);
    void BattleState_SetCamPos(void *, f32, f32);
    f32 Vec_Length(f32 *);
    extern void MapSelect_UpdateMove(void);
    extern void MapSelect_SetGhostColor(void);
    extern u32 lbl_8027AA2C[3];
    extern u8 MapSelect_str[];
    extern u8 gBattleState[];
    extern f32 lbl_8036AF10;
    extern f32 lbl_8036AF14;
    f32 vec[3];
    f32 angle;
    f32 scale;
    void *actor;
    void *node;
    void *inner;

    *(u32 *)&vec[0] = lbl_8027AA2C[0];
    *(u32 *)&vec[1] = lbl_8027AA2C[1];
    *(u32 *)&vec[2] = lbl_8027AA2C[2];
    vec[0] = (f32)((s8)((u8 *)arg0)[0x3C] - (s8)((u8 *)arg0)[0x3A]);
    vec[1] = (f32)((s8)((u8 *)arg0)[0x3D] - (s8)((u8 *)arg0)[0x3B]);
    *(f32 *)((u8 *)arg0 + 0x4C) = Vec_Length(vec);
    *(s16 *)((u8 *)arg0 + 0x4A) = (s16)(lbl_8036AF10 * *(f32 *)((u8 *)arg0 + 0x4C));
    if (*(s16 *)((u8 *)arg0 + 0x4A) <= 0) {
        *(s16 *)((u8 *)arg0 + 0x4A) = 1;
    }
    *(s16 *)((u8 *)arg0 + 0x48) = 0;
    angle = Math_Angle2D(
        (f32)(s8)((u8 *)arg0)[0x3A],
        (f32)(s8)((u8 *)arg0)[0x3B],
        (f32)(s8)((u8 *)arg0)[0x3C],
        (f32)(s8)((u8 *)arg0)[0x3D]);
    actor = Effect_Create(MapSelect_str + 0xD4, arg0);
    node = *(void **)((u8 *)actor + 0x30);
    *(void **)((u8 *)node + 0x3C) = (void *)&MapSelect_SetGhostColor;
    node = *(void **)((u8 *)actor + 0x30);
    *(void **)((u8 *)node + 0x40) = (void *)&MapSelect_UpdateMove;
    fn_80053658(actor, 0, arg0);
    scale = lbl_8036AF14;
    inner = *(void **)((u8 *)actor + 0x30);
    *(s32 *)((u8 *)inner + 8) = *(s32 *)((u8 *)inner + 8) | 0x801;
    *(f32 *)((u8 *)*(void **)((u8 *)actor + 0x30) + 0x18) = scale;
    *(f32 *)((u8 *)*(void **)((u8 *)actor + 0x30) + 0x24) = angle;
    BattleState_SetCamPos(gBattleState, (f32)(s8)((u8 *)arg0)[0x3C], (f32)(s8)((u8 *)arg0)[0x3D]);
}

void fn_8019A01C(void *arg0) {
    u8 Pad_IsButton(void *, s32);
    void Process_ClearFunc(void *);
    u32 *flags;

    flags = (u32 *)(*(u8 **)((u8 *)arg0 + 0x34) + 0x14);
    if (Pad_IsButton(flags, 0x12)) {
        Process_ClearFunc(arg0);
    } else if (*flags & 0x10) {
        Process_ClearFunc(arg0);
    }
}

void fn_8019A088(void *arg0) {
    M2C_UNK fn_80049D30(s32);
    fn_80049D30(M2C_FIELD(arg0, s32 *, 0x34));
    fn_800498A4(M2C_FIELD(arg0, s32 *, 0x34), 0, 0);
}

void fn_8019A0C8(void *arg0) {
    void fn_80049520(s32, void *, s32, f32);
    f32 Math_Angle2D(f32, f32, f32, f32);
    void fn_801848D8(s32, s32, s32, s32, s32);
    M2C_FIELD(arg0,s16 *,0x3E)=(s32)Math_Angle2D(0.5f+(f32)M2C_FIELD(arg0,s8 *,0x3A),0.5f+(f32)M2C_FIELD(arg0,s8 *,0x3B),0.5f+(f32)M2C_FIELD(arg0,s8 *,0x3C),0.5f+(f32)M2C_FIELD(arg0,s8 *,0x3D));
    fn_80049520(M2C_FIELD(arg0,s32 *,0x34),arg0,0x14,(f32)M2C_FIELD(arg0,s16 *,0x3E));
    fn_801848D8(M2C_FIELD(arg0,s32 *,0x30),M2C_FIELD(arg0,s8 *,0x3A),M2C_FIELD(arg0,s8 *,0x3B),0x18,0);
}

void fn_8019A1E0(u8 *self)
{
  void *Map_Get(void *);
  void *Map_FindObjNear(void *, s32, s32, s32, s32);
  void fn_800056A0(s32);
  void Process_Goto(void *, s32);
  f32 Map_SampleHeight(void *, f32, f32);
  void GActor_RequestRes(void *);
  extern u8 gUiContext[];
  extern u8 gBattleMap[];
  extern u8 MapSelect_str[];
  void *map;
  self[0x38] = gUiContext[0xD];
  self[0x39] = gUiContext[0xE];
  map = Map_Get(gUiContext);
  *((void **) (self + 0x34)) = Map_FindObjNear(map, *(s8 *)(self + 0x38), *(s8 *)(self + 0x39), 0x8000, 0);
  if ((*((void **) (self + 0x34))) == NULL)
  {
    fn_800056A0(0);
    Process_Goto(self, 0x63);
    return;
  }
  self[0x3A] = (*((u8 **) (self + 0x34)))[0];
  self[0x3B] = (*((u8 **) (self + 0x34)))[1];
  self[0x3C] = gUiContext[0xF];
  self[0x3D] = gUiContext[0x10];
  *((f32 *) (self + 0x40)) = Map_SampleHeight(gBattleMap, (f32) ((s8) self[0x3A]), (f32) ((s8) self[0x3B]));
  *((f32 *) (self + 0x44)) = Map_SampleHeight(gBattleMap, (f32) ((s8) self[0x3C]), (f32) ((s8) self[0x3D]));
  GActor_RequestRes(MapSelect_str + 0xD4);
  GActor_RequestRes(MapSelect_str + 0xCA);
  *((s32 *) (self + 0x30)) = *((s32 *) gUiContext);
}

#pragma use_lmw_stmw on
s32 MapSelect_UpdateMove(void *arg0)
{
    void fn_80025624(s32, s32);
    void Effect_SetPos(void *, f32, f32, f32);
    f32 Math_Lerp(f32, f32, f32, f32);
    f32 Math_EaseInPow(s32, f32, f32, f32, f32);
    f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
    void SeCue_PlayAt(void *, s32, f32, f32, f32);
    void fn_8018CFA4(s32, s32, s32, s32, void *);
    void PSMTXRotRad(void *, s32, f32);
    void fn_802029C4(void *, void *, void *);
    extern u32 lbl_8027AA20[3];
    extern u8 MapSelect_str[];
    extern s32 gPadInput;
    extern u32 lbl_8036AEFC;
    extern f32 lbl_8036AF00;
    extern f32 lbl_8036AF18;
    extern f32 lbl_8036AF1C;
    extern f32 lbl_8036AF20;
    extern f32 lbl_8036AF24;
    extern f32 lbl_8036AF28;
    extern f32 lbl_8036AF2C;

    f32 mtx[12];
    f32 vec[3];
    u32 spC;
    u32 sp8;
    void *self;
    u8 *obj;
    f32 f31;
    f32 f30;
    f32 f29;
    f32 f28;
    f32 f27;
    f32 f26;
    f32 f25;
    f32 f24;
    s32 alpha;
    f32 scaled;

    self = arg0;
    obj = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x30) + 0x4C);
    if (*(s16 *)(obj + 0x48) >= *(s16 *)(obj + 0x4A)) {
        return 0;
    }
    (*(s16 *)(obj + 0x48))++;

#pragma peephole off
    f24 = lbl_8036AF00 + (f32)(s8)obj[0x3B];
    f30 = lbl_8036AF00 + (f32)(s8)obj[0x3C];
    f31 = *(f32 *)(obj + 0x40);
    f28 = *(f32 *)(obj + 0x44);
    f29 = lbl_8036AF00 + (f32)(s8)obj[0x3D];
    f27 = Math_Lerp(lbl_8036AF00 + (f32)(s8)obj[0x3A], f30,
                      (f32)*(s16 *)(obj + 0x4A), (f32)*(s16 *)(obj + 0x48));
    f26 = Math_Lerp(f24, f29,
                      (f32)*(s16 *)(obj + 0x4A), (f32)*(s16 *)(obj + 0x48));
    f31 = Math_Lerp(f31, f28,
                      (f32)*(s16 *)(obj + 0x4A), (f32)*(s16 *)(obj + 0x48));
#pragma peephole on

    alpha = 0xFF;
    *(u32 *)&vec[0] = lbl_8027AA20[0];
    *(u32 *)&vec[1] = lbl_8027AA20[1];
    *(u32 *)&vec[2] = lbl_8027AA20[2];
    vec[1] = *(f32 *)(obj + 0x4C);
    PSMTXRotRad(mtx, 0x58, lbl_8036AF18);
    fn_802029C4(mtx, vec, vec);

    scaled = lbl_8036AF1C * vec[2];
    f24 = (f32)*(s16 *)(obj + 0x4A) * lbl_8036AF00;
    f25 = lbl_8036AF20;
    if ((f32)*(s16 *)(obj + 0x48) < f24) {
        f31 += Math_EaseOutPow(2, lbl_8036AF24, -scaled, f24, (f32)*(s16 *)(obj + 0x48));
        alpha = (s32)Math_EaseOutPow(2, lbl_8036AF20, lbl_8036AF28, f24, (f32)*(s16 *)(obj + 0x48));
    } else {
        f31 += Math_EaseInPow(2, -scaled, f25, f24, (f32)*(s16 *)(obj + 0x48) - f24);
    }
    f25 += lbl_8036AF2C;

    if (*(s16 *)(obj + 0x48) >= *(s16 *)(obj + 0x4A)) {
        fn_80025624(gPadInput, 0x10);
        fn_8018CFA4(0x1E, 6, 2, 0, obj);
        SeCue_PlayAt(MapSelect_str + 0xDF, 0x64, f30, f29, f28);
        {
            void *p = *(void **)((u8 *)self + 0x30);
            f25 = lbl_8036AF20;
            *(u32 *)((u8 *)p + 8) &= ~0x800;
        }
    }

    Effect_SetPos(self, f27, f26, f31);
    {
        u8 *p;
        p = *(u8 **)((u8 *)self + 0x30);
        sp8 = lbl_8036AEFC;
        *((u8 *)&sp8 + 3) = alpha;
        spC = sp8;
        p[0x38] = *((u8 *)&spC + 0);
        p[0x39] = *((u8 *)&spC + 1);
        p[0x3A] = *((u8 *)&spC + 2);
        p[0x3B] = *((u8 *)&spC + 3);
        *(f32 *)(*(u8 **)((u8 *)self + 0x30) + 0x20) = f25;
    }
    return 0;
}
extern s32 lbl_8036AEF8;
s32 MapSelect_SetGhostColor(void *arg0) {
    u8 color[4] = {0x80, 0x80, 0x80, 0x40};
    u8 *dst;

    dst = M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), u8 **, 0x5C);
    dst[0x88] = color[0];
    dst[0x89] = color[1];
    dst[0x8A] = color[2];
    dst[0x8B] = color[3];
    return 1;
}

void fn_8019A7E8(s32 arg0) {
    extern u16 lbl_80296DF0[];
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);

    fn_8019D51C(Process_CreateChild(lbl_80296DF0, arg0), 0, 0);
}

#pragma use_lmw_stmw on
/* Start an event item command (opcodes 0x50-0x52): play SE and set up give/take/trade. */
void Event_RunItemCmd(void *cmd) {
    void fn_80025624(void *, s32);
    void Effect_SetPos(f32, f32, f32);
    void *Effect_Create(void *, void *);
    void *fn_80095934(s32, s32, s32);
    u8 fn_80096C18(void);
    s32 Event_GetCmdKind(s16);
    s32 Event_GetCmdFlags(s16);
    void *fn_8009809C(void);
    void fn_800983E0(void *, void *);
    void SeCue_PlayAtPos(void *, void *, s32);
    void FloatAnim_Start(void *, s32, void *);
    void fn_8017E2BC(void);
    void fn_8017F040(void *, s32, void *);
    void fn_8017F474(void *, void *);
    void fn_8017F70C(void *, void *);
    void Mu_StartFlash(s32, s32, s32, void *);
    void Mu_StartTransfer(s32, s32, s32, s32);
    void Mu_StartBlend(s32, s32, s32, s32);
    void fn_8018CFA4(s32, s32, s32, s32, void *);
    extern u8 MapSelect_str[];
    extern void *gPadInput;
    typedef struct { s32 x, y, z; } Word3;
    Word3 sp8c;
    Word3 sp80;
    Word3 sp74;
    Word3 sp68;
    Word3 sp5c;
    Word3 sp50;
    Word3 sp44;
    Word3 sp38;
    Word3 sp2c;
    Word3 sp20;
    Word3 sp14;
    Word3 sp8;
    void *unit;
    s32 flags;
    s32 kind;
    s32 slot;
    s32 tmp;
    void *p;
    s32 actor;

    unit = fn_8009809C();
    flags = Event_GetCmdFlags(*(s16 *)((u8 *)cmd + 0x56));
    kind = Event_GetCmdKind(*(s16 *)((u8 *)cmd + 0x56));
    if (kind == 0x52) {
        p = *(void **)unit;
        if (p != NULL) {
            actor = *(s32 *)((u8 *)p + 0x280);
        } else {
            actor = 0;
        }
        Mu_StartBlend(actor, 7, 2, 0);
        p = *(void **)unit;
        if (p != NULL) {
            actor = *(s32 *)((u8 *)p + 0x280);
        } else {
            actor = 0;
        }
        Mu_StartTransfer(actor, 8, 0x18, 0);
        fn_8017F474(unit, cmd);
        fn_800983E0(&sp74, unit);
        sp80 = sp74;
        SeCue_PlayAtPos(MapSelect_str + 0xF3, &sp80, 0x64);
        return;
    }
    slot = (s32)*(f32 *)((u8 *)unit + 0xC);
    if (slot == 0) {
        fn_8017F70C(unit, cmd);
        fn_800983E0(&sp5c, unit);
        sp68 = sp5c;
        SeCue_PlayAtPos(MapSelect_str + 0x101, &sp68, 0x64);
        fn_80025624(gPadInput, 4);
    } else {
        if (fn_80096C18() != 0) {
            fn_800983E0(&sp44, unit);
            sp50 = sp44;
            SeCue_PlayAtPos(MapSelect_str + 0x114, &sp50, 0x64);
        } else {
            fn_800983E0(&sp2c, unit);
            sp38 = sp2c;
            SeCue_PlayAtPos(MapSelect_str + 0x12B, &sp38, 0x64);
        }
        p = *(void **)unit;
        if (p != NULL) {
            actor = *(s32 *)((u8 *)p + 0x280);
        } else {
            actor = 0;
        }
        Mu_StartBlend(actor, 9, 2, 0);
        p = *(void **)unit;
        if (p != NULL) {
            actor = *(s32 *)((u8 *)p + 0x280);
        } else {
            actor = 0;
        }
        Mu_StartTransfer(actor, 8, 0x18, 0);
        if (kind == 0x51) {
            fn_8018CFA4(0x3C, 6, 2, 0, cmd);
            fn_80025624(gPadInput, 0x10);
            fn_8017E2BC();
            fn_800983E0(&sp14, unit);
            sp20 = sp14;
            SeCue_PlayAtPos(MapSelect_str + 0x142, &sp20, 0x64);
        } else {
            fn_8018CFA4(0xF, 6, 2, 0, cmd);
            fn_80025624(gPadInput, 8);
        }
        FloatAnim_Start(unit, slot, cmd);
        fn_8017F040(unit, slot, cmd);
    }
    p = *(void **)unit;
    if (p != NULL) {
        actor = *(s32 *)((u8 *)p + 0x280);
    } else {
        actor = 0;
    }
    Mu_StartFlash(actor, 1, 4, cmd);
    tmp = (s32)fn_80095934(0, kind, flags);
    if (tmp != 0) {
        fn_800983E0(&sp8, unit);
        sp8c = sp8;
        Effect_Create((void *)tmp, cmd);
        Effect_SetPos(*(f32 *)&sp8c.x, *(f32 *)&sp8c.y, *(f32 *)&sp8c.z);
    }
}
#pragma use_lmw_stmw reset

void fn_8019AB90(void *arg0) {
    fn_800498A4(M2C_FIELD(arg0, s32 *, 0x5C), 0, 2);
}

void fn_8019ABBC(void *arg0) {
    void Process_ClearFunc(void *);
    s16 a;
    s16 b;

    a = *(s16 *)((u8 *)arg0 + 0x6A);
    b = *(s16 *)((u8 *)arg0 + 0x68);
    if (b >= a - 4) {
        Process_ClearFunc(arg0);
    }
}

void fn_8019ABF0(void *arg0) {
 void fn_80053658(void *,s32,void *);
 void *Effect_Create(u8 *,void *);
 f32 Math_Angle2D(f32,f32,f32,f32);
 f32 Vec_Length(f32 *);
 extern void fn_8019ADD8(void);
 extern void fn_8019B25C(void);
 extern u32 lbl_8027AA14[3]; extern u8 MapSelect_str[];
 extern f32 lbl_8036AF30,lbl_8036AF14;
 f32 vec[3]; f32 angle; f32 scale; void *actor; void *node; void *inner;
 *(u32 *)&vec[0]=lbl_8027AA14[0];
 *(u32 *)&vec[1]=lbl_8027AA14[1];
 *(u32 *)&vec[2]=lbl_8027AA14[2];
 vec[0]=(f32)((s8)((u8 *)arg0)[0x66]-(s8)((u8 *)arg0)[0x64]);
 vec[1]=(f32)((s8)((u8 *)arg0)[0x67]-(s8)((u8 *)arg0)[0x65]);
 *(f32 *)((u8 *)arg0+0x6C)=Vec_Length(vec);
 *(s16 *)((u8 *)arg0+0x6A)=(s16)(lbl_8036AF30**(f32 *)((u8 *)arg0+0x6C));
 if(*(s16 *)((u8 *)arg0+0x6A)<=0) *(s16 *)((u8 *)arg0+0x6A)=1;
 *(s16 *)((u8 *)arg0+0x68)=0;
 angle=Math_Angle2D((f32)(s8)((u8 *)arg0)[0x64],(f32)(s8)((u8 *)arg0)[0x65],(f32)(s8)((u8 *)arg0)[0x66],(f32)(s8)((u8 *)arg0)[0x67]);
 actor=Effect_Create(MapSelect_str+0x15A,arg0);
 node=*(void **)((u8 *)actor+0x30);
 *(void **)((u8 *)node+0x3C)=(void *)&fn_8019B25C;
 node=*(void **)((u8 *)actor+0x30);
 *(void **)((u8 *)node+0x40)=(void *)&fn_8019ADD8;
 fn_80053658(actor,0,arg0);
 scale=lbl_8036AF14;
 inner=*(void **)((u8 *)actor+0x30);
 *(s32 *)((u8 *)inner+8)|=0x801;
 *(f32 *)((u8 *)*(void **)((u8 *)actor+0x30)+0x18)=scale;
 *(f32 *)((u8 *)*(void **)((u8 *)actor+0x30)+0x24)=angle;
}

#pragma use_lmw_stmw on
s32 fn_8019ADD8(void *arg0)
{
    f32 fn_80023068(void *, f32, f32);
    void fn_800536B0(void *, f32, f32, f32);
    f32 fn_80059F64(f32, f32, f32, f32);
    f32 fn_80059F78(s32, f32, f32, f32, f32);
    f32 fn_8005A028(s32, f32, f32, f32, f32);
    void fn_80202300(void *, s32, f32);
    void fn_802029C4(void *, void *, void *);
    extern u32 lbl_8027AA08[3];
    extern u8 lbl_802CA518[];
    extern u32 lbl_8036AEF4;
    extern f32 lbl_8036AF00;
    extern f32 lbl_8036AF1C;
    extern f32 lbl_8036AF20;
    extern f32 lbl_8036AF24;
    extern f32 lbl_8036AF28;
    extern f32 lbl_8036AF34;
    extern f32 lbl_8036AF38;
    extern f32 lbl_8036AF3C;

    f32 mtx[12];
    f32 vec[3];
    u32 spC;
    u32 sp8;
    unsigned int alpha;
    u8 *obj;
    void *self;
    f32 f27;
    f32 f30;
    f32 f29;
    f32 f28;
    f32 f31;
    f32 f26;

    self = arg0;
    obj = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x30) + 0x4C);
    if (*(s16 *)(obj + 0x68) >= *(s16 *)(obj + 0x6A)) {
        return 0;
    }
    (*(s16 *)(obj + 0x68))++;

    f28 = lbl_8036AF00 + (f32)(s8)obj[0x64];
    f29 = lbl_8036AF00 + (f32)(s8)obj[0x65];
    f31 = fn_80023068(lbl_802CA518, f28, f29);
    f30 = lbl_8036AF00 + (f32)(s8)obj[0x66];
    f27 = lbl_8036AF00 + (f32)(s8)obj[0x67];
    f26 = fn_80023068(lbl_802CA518, f30, f27);
    f30 = fn_80059F64(f28, f30,
                      (f32)*(s16 *)(obj + 0x6A), (f32)*(s16 *)(obj + 0x68));
    f29 = fn_80059F64(f29, f27,
                      (f32)*(s16 *)(obj + 0x6A), (f32)*(s16 *)(obj + 0x68));
    f28 = fn_80059F64(f31, f26,
                      (f32)*(s16 *)(obj + 0x6A), (f32)*(s16 *)(obj + 0x68));

    alpha = 0xFF;
    *(u32 *)&vec[0] = lbl_8027AA08[0];
    *(u32 *)&vec[1] = lbl_8027AA08[1];
    *(u32 *)&vec[2] = lbl_8027AA08[2];
    vec[1] = *(f32 *)(obj + 0x6C);
    fn_80202300(mtx, 0x58, lbl_8036AF34);
    fn_802029C4(mtx, vec, vec);

    f31 = lbl_8036AF00 * (f32)*(s16 *)(obj + 0x6A);
    {
        f32 scaled = lbl_8036AF1C * vec[2];
        if ((f32)*(s16 *)(obj + 0x68) < f31) {
            f26 = f28 + fn_8005A028(2, lbl_8036AF24, -scaled, f31, (f32)*(s16 *)(obj + 0x68));
            f27 = fn_8005A028(2, lbl_8036AF38, lbl_8036AF20, f31, (f32)*(s16 *)(obj + 0x68));
            alpha = (s32)fn_8005A028(2, lbl_8036AF20, lbl_8036AF28, f31, (f32)*(s16 *)(obj + 0x68));
        } else {
            f26 = f28 + fn_80059F78(2, -scaled, lbl_8036AF20, f31, (f32)*(s16 *)(obj + 0x68) - f31);
            f27 = fn_80059F78(2, lbl_8036AF20, lbl_8036AF3C, f31, (f32)*(s16 *)(obj + 0x68) - f31);
        }
    }

    fn_800536B0(self, f30, f29, f26);
    {
        u8 *p = *(u8 **)((u8 *)self + 0x30);
        sp8 = lbl_8036AEF4;
        *((u8 *)&sp8 + 3) = alpha;
        spC = sp8;
        p[0x38] = *((u8 *)&spC + 0);
        p[0x39] = *((u8 *)&spC + 1);
        p[0x3A] = *((u8 *)&spC + 2);
        p[0x3B] = *((u8 *)&spC + 3);
        *(f32 *)(*(u8 **)((u8 *)self + 0x30) + 0x20) = f27;
    }

    if (*(s16 *)(obj + 0x68) >= *(s16 *)(obj + 0x6A)) {
        void *p = *(void **)((u8 *)self + 0x30);
        *(u32 *)((u8 *)p + 8) &= ~0x800;
    }
    return 0;
}
s32 fn_8019B25C(void *arg0) {
    u8 color[4] = {0x80, 0x80, 0x80, 0x40};
    u8 *dst;

    dst = M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), u8 **, 0x5C);
    dst[0x88] = color[0];
    dst[0x89] = color[1];
    dst[0x8A] = color[2];
    dst[0x8B] = color[3];
    return 1;
}

void fn_8019B29C(void *arg0) {
    u8 Pad_IsButton(void *, s32);
    u32 *flags;

    flags = (u32 *) (M2C_FIELD(arg0, u8 **, 0x5C) + 0x14);
    if (Pad_IsButton(flags, 0x12) || (*flags & 0x10)) {
        Process_ClearFunc(arg0);
    }
}

void fn_8019B2FC(void *arg0) {
    M2C_UNK fn_80049D30(s32);
    M2C_UNK fn_800498A4(s32, M2C_UNK, M2C_UNK);
    void BattleState_SetCamPos(void *, f32, f32);
    extern u8 gBattleState[];

    fn_80049D30(M2C_FIELD(arg0, s32 *, 0x5C));
    fn_800498A4(M2C_FIELD(arg0, s32 *, 0x5C), 0, 0);
    BattleState_SetCamPos(gBattleState, M2C_FIELD(arg0, s8 *, 0x66), M2C_FIELD(arg0, s8 *, 0x67));
}

void fn_8019B388(void *arg0) {
    void fn_80049520(s32, void *, s32, f32);
    f32 Math_Angle2D(f32, f32, f32, f32);
    void fn_801848D8(s32, s32, s32, s32, s32);
    void Mu_StartBlend(s32, s32, s32, s32);
    void *unit;
    s32 actor;
    M2C_FIELD(arg0,s16 *,0x60)=(s32)Math_Angle2D(0.5f+(f32)M2C_FIELD(arg0,s8 *,0x64),0.5f+(f32)M2C_FIELD(arg0,s8 *,0x65),0.5f+(f32)M2C_FIELD(arg0,s8 *,0x66),0.5f+(f32)M2C_FIELD(arg0,s8 *,0x67));
    fn_80049520(M2C_FIELD(arg0,s32 *,0x5C),arg0,0x14,(f32)M2C_FIELD(arg0,s16 *,0x60));
    unit=*M2C_FIELD(arg0,void ***,0x34);
    if(unit) actor=M2C_FIELD(unit,s32 *,0x280); else actor=0;
    Mu_StartBlend(actor,8,0x10,0);
    unit=*M2C_FIELD(arg0,void ***,0x34);
    if(unit) actor=M2C_FIELD(unit,s32 *,0x280); else actor=0;
    fn_801848D8(actor,M2C_FIELD(arg0,s8 *,0x64),M2C_FIELD(arg0,s8 *,0x65),0x18,0);
    unit=*M2C_FIELD(arg0,void ***,0x30);
    if(unit) actor=M2C_FIELD(unit,s32 *,0x280); else actor=0;
    fn_801848D8(actor,M2C_FIELD(arg0,s8 *,0x64),M2C_FIELD(arg0,s8 *,0x65),0x18,0);
}

#pragma optimization_level 4
#pragma inline auto
extern u16 gBattle[0x834];
#pragma optimization_level 4
#pragma inline auto
void fn_8019B51C(void *self) {
    extern u8 gUiContext[];
    extern u8 MapSelect_str[];
    s32 Event_GetCmdFlags(s16);
    s32 Event_GetCmdKind(s16);
    void *Map_Get(void);
    void *Map_FindObjNear(void *,s32,s32,u32,s32);
    void fn_800056A0(s32);
    void Process_Goto(void *,s32);
    void GActor_RequestRes(void *);
    void *fn_80095934(s32,s32,s32);
    void fn_8004FC70(s32,s32);
    s32 flags;
    s32 kind;
    void *tmp;
    s32 actor;
    M2C_FIELD(self,u8 *,0x62)=gUiContext[0xD];
    M2C_FIELD(self,u8 *,0x63)=gUiContext[0xE];
    flags=Event_GetCmdFlags(M2C_FIELD(self,s16 *,0x56));
    kind=Event_GetCmdKind(M2C_FIELD(self,s16 *,0x56));
    M2C_FIELD(self,void **,0x5C)=Map_FindObjNear(Map_Get(),M2C_FIELD(self,s8 *,0x62),M2C_FIELD(self,s8 *,0x63),0x8000,0);
    if(!M2C_FIELD(self,void **,0x5C)) {
        fn_800056A0(0);
        Process_Goto(self,0x63);
        return;
    }
    M2C_FIELD(self,u8 *,0x64)=M2C_FIELD(M2C_FIELD(self,void **,0x5C),u8 *,0);
    M2C_FIELD(self,u8 *,0x65)=M2C_FIELD(M2C_FIELD(self,void **,0x5C),u8 *,1);
    M2C_FIELD(self,u8 *,0x66)=gUiContext[0xF];
    M2C_FIELD(self,u8 *,0x67)=gUiContext[0x10];
    GActor_RequestRes(MapSelect_str+0x15A);
    tmp=fn_80095934(0,kind,flags);
    if(tmp) GActor_RequestRes(tmp);
    tmp=*M2C_FIELD(self,void ***,0x34);
    if(tmp) actor=M2C_FIELD(tmp,s32 *,0x280); else actor=0;
    fn_8004FC70(actor,8);
    switch(kind) {
    case 0x50: case 0x51:
        tmp=*M2C_FIELD(self,void ***,0x34);
        if(tmp) actor=M2C_FIELD(tmp,s32 *,0x280); else actor=0;
        fn_8004FC70(actor,9);
        break;
    case 0x52:
        tmp=*M2C_FIELD(self,void ***,0x34);
        if(tmp) actor=M2C_FIELD(tmp,s32 *,0x280); else actor=0;
        fn_8004FC70(actor,7);
        break;
    }
}
void fn_8019B6B4(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, void *);
    extern u8 lbl_80296938[];
    extern u8 MapSelect_str[];

    fn_8019D51C(Process_CreateChild(lbl_80296938, arg0), arg1, MapSelect_str + 0x166);
}

#pragma global_optimizer off
void fn_8019B704(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, void *);
    void fn_8004FC70(void *, s32);
    extern u8 lbl_80296D5C[];
    extern u8 MapSelect_str[];
    void *r30;
    void *child;
    void *t;

    r30 = (void *)arg1;
    child = Process_CreateChild(lbl_80296D5C, arg0);
    fn_8019D51C(child, (s32)r30, MapSelect_str + 0x17A);
    r30 = 0;
    ((u8 *)child)[0x5C] = (u8)(s32)r30;
    t = *(void **)(*(void **)((u8 *)child + 0x34));
    if (t) {
        r30 = *(void **)((u8 *)t + 0x280);
    }
    if (r30) {
        fn_8004FC70(r30, 8);
        fn_8004FC70(r30, 9);
    }
}
#pragma global_optimizer reset
void fn_8019B79C(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, void *);
    void fn_8004FC70(void *, s32);
    extern u8 lbl_80296D5C[];
    extern u8 MapSelect_str[];
    void *temp_r31;
    void *var_r31;
    void *temp_r3;

    temp_r31 = Process_CreateChild(lbl_80296D5C, arg0);
    fn_8019D51C(temp_r31, arg1, MapSelect_str + 0x185);
    ((u8 *)temp_r31)[0x5C] = 1;
    temp_r3 = *(void **)((u8 *)temp_r31 + 0x34);
    temp_r3 = *(void **)temp_r3;
    if (temp_r3) {
        var_r31 = *(void **)((u8 *)temp_r3 + 0x280);
    } else {
        var_r31 = 0;
    }
    if (var_r31) {
        fn_8004FC70(var_r31, 8);
        fn_8004FC70(var_r31, 9);
    }
}

void fn_8019B83C(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, void *);
    extern u8 lbl_80296D5C[];
    extern u8 MapSelect_str[];
    void *temp_r31;

    temp_r31 = Process_CreateChild(lbl_80296D5C, arg0);
    fn_8019D51C(temp_r31, arg1, MapSelect_str + 0x194);
    M2C_FIELD(temp_r31, u8 *, 0x5C) = 3;
}

void fn_8019B8A0(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, void *);
    extern u8 lbl_80296D5C[];
    extern u8 MapSelect_str[];
    void *temp_r31;

    temp_r31 = Process_CreateChild(lbl_80296D5C, arg0);
    fn_8019D51C(temp_r31, arg1, MapSelect_str + 0x1A4);
    M2C_FIELD(temp_r31, u8 *, 0x5C) = 2;
}

void MapSelect_InitSelectFx(void *cmd) {
    /* Bind MapSelect_Update effect; for modes 0/1 start blend+transfer on the selected unit. */
    void *Effect_Create(void *, void *);
    void fn_800536D8(void *, void *);
    void fn_8005306C(void *);
    void fn_80053658(void *, s32, void *);
    void Mu_StartBlend(void *, s32, s32, s32);
    void Mu_StartTransfer(void *, s32, s32, s32);
    extern void MapSelect_Update(void);
    void *fx;
    void *unit;
    void *node;
    s32 mode;

    fx = Effect_Create((u8 *)cmd + 0x41, cmd);
    fn_800536D8(fx, *(void **)*(void **)((u8 *)cmd + 0x34));
    fn_8005306C(fx);
    *(void **)((u8 *)*(void **)((u8 *)fx + 0x30) + 0x40) = MapSelect_Update;
    fn_80053658(fx, 0, cmd);
    node = *(void **)*(void **)((u8 *)cmd + 0x34);
    if (node != NULL) {
        unit = *(void **)((u8 *)node + 0x280);
    } else {
        unit = NULL;
    }
    if (unit != NULL && !(*(u32 *)((u8 *)unit + 0x1A0) & 0x010000DC)) {
        mode = *(u8 *)((u8 *)cmd + 0x5C);
        switch (mode) {
        case 0:
        case 1:
            Mu_StartBlend(unit, 9, 0x10, 0);
            Mu_StartTransfer(unit, 8, 0x10, 0);
            break;
        }
    }
}

typedef struct { s32 x, y, z; } Word3B9;
/* Map unit-select process update: init cam zoom, handle A confirm / B cancel. */
s32 MapSelect_Update(void *proc) {
    void *Camera_GetActive(void);
    void fn_80052CA8(void *);
    void fn_80054C14(void *);
    s32 fn_8005F894(void *, s32);
    u8 Pad_IsButton(void *, s32);
    void fn_800983E0(void *, void *);
    void fn_80098524(void *);
    u8 fn_80098568(void *);
    void SeCue_PlayAtPos(void *, void *, s32);
    void FloatAnim_Start(void *, s32, void *, s32);
    void fn_8017F040(void *, s32, void *);
    void Mu_StartFlash(s32, s32, s32, void *);
    void fn_8018CFA4(s32, s32, s32, s32, void *);
    extern u8 MapSelect_str[];
    extern f32 gMapSelectCamZoom;

    typedef struct { s32 x, y, z; } Vec3i;
    Vec3i posCopy, pos, sePosA, sePosB;
    s32 height;
    void *pad;
    void *cmd;
    void *tmp;
    s32 actor;
    u8 mode;
    s32 posX;
    s32 posY;
    f32 heightF;

    tmp = *(void **)((u8 *)proc + 0x30);
    cmd = *(void **)((u8 *)tmp + 0x4C);
    pad = *(void **)((u8 *)tmp + 0x5C);
    if (!(*(u8 *)((u8 *)cmd + 0x40) & 1)) {
        if (fn_8005F894(pad, 0x12) < 0) {
            tmp = Camera_GetActive();
            *(f32 *)((u8 *)tmp + 0x70) = gMapSelectCamZoom;
            fn_80098524(*(void **)((u8 *)cmd + 0x34));
        }
        *(u8 *)((u8 *)cmd + 0x40) = (u8)(*(u8 *)((u8 *)cmd + 0x40) | 1);
    }
    if (Pad_IsButton(pad, 0) != 0) {
        fn_800983E0(&pos, *(void **)((u8 *)cmd + 0x34));
        tmp = *(void **)((u8 *)cmd + 0x34);
        posX = *(s32 *)(&pos);
        heightF = *(f32 *)((u8 *)tmp + 0xC);
        posY = *(s32 *)((u8 *)&pos + 4);
        height = (s32)heightF;
        *(s32 *)(&posCopy) = posX;
        *(s32 *)((u8 *)&posCopy + 4) = posY;
        *(s32 *)((u8 *)&posCopy + 8) = *(s32 *)((u8 *)&pos + 8);
        FloatAnim_Start(tmp, height, cmd, posX);
        fn_8017F040(*(void **)((u8 *)cmd + 0x34), height, cmd);
        mode = *(u8 *)((u8 *)cmd + 0x5C);
        switch (mode) {
        case 0:
        case 1:
            fn_8018CFA4(0xF, 6, 2, 0, cmd);
            if (fn_80098568(*(void **)((u8 *)cmd + 0x34)) != 0) {
                tmp = MapSelect_str + 0x114;
                *(s32 *)(&sePosA) = *(s32 *)(&posCopy);
                *(s32 *)((u8 *)&sePosA + 4) = *(s32 *)((u8 *)&posCopy + 4);
                *(s32 *)((u8 *)&sePosA + 8) = *(s32 *)((u8 *)&posCopy + 8);
                SeCue_PlayAtPos(tmp, &sePosA, 0x64);
            } else {
                tmp = MapSelect_str + 0x1B1;
                *(s32 *)(&sePosB) = *(s32 *)(&posCopy);
                *(s32 *)((u8 *)&sePosB + 4) = *(s32 *)((u8 *)&posCopy + 4);
                *(s32 *)((u8 *)&sePosB + 8) = *(s32 *)((u8 *)&posCopy + 8);
                SeCue_PlayAtPos(tmp, &sePosB, 0x64);
            }
            tmp = *(void **)(*(void **)((u8 *)cmd + 0x34));
            if (tmp != NULL) {
                actor = *(s32 *)((u8 *)tmp + 0x280);
            } else {
                actor = 0;
            }
            Mu_StartFlash(actor, 1, 4, cmd);
            break;
        case 2:
        case 3:
            tmp = *(void **)(*(void **)((u8 *)cmd + 0x34));
            if (tmp != NULL) {
                actor = *(s32 *)((u8 *)tmp + 0x280);
            } else {
                actor = 0;
            }
            Mu_StartFlash(actor, 1, 0x20, cmd);
            break;
        }
        if (*(void **)((u8 *)cmd + 0x58) != NULL) {
            mode = *(u8 *)((u8 *)cmd + 0x40);
            if (!(mode & 4)) {
                *(u8 *)((u8 *)cmd + 0x40) = (u8)(mode | 4);
                (*(void (**)(void *))((u8 *)cmd + 0x58))(cmd);
            }
        }
    }
    if (Pad_IsButton(pad, 0x12) != 0) {
        fn_80052CA8(proc);
        fn_80098524(*(void **)((u8 *)cmd + 0x34));
    }
    fn_80054C14(proc);
    return 0;
}

void fn_8019BC50(s32 arg0, s32 arg1, s32 arg2) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, void *);
    extern u8 lbl_80296CF8[];
    u8 *temp_r31;

    temp_r31 = Process_CreateChild(lbl_80296CF8, arg2);
    fn_8019D51C(temp_r31, 0, NULL);
    temp_r31[0x5D] = arg0;
    temp_r31[0x5E] = arg1;
    temp_r31[0x5C] = 1;
}

void fn_8019BCC0(s32 arg0, s32 arg1, s32 arg2) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, void *);
    extern u8 lbl_80296CF8[];
    u8 *temp_r31;

    temp_r31 = Process_CreateChild(lbl_80296CF8, arg2);
    fn_8019D51C(temp_r31, 0, NULL);
    temp_r31[0x5D] = arg0;
    temp_r31[0x5E] = arg1;
    temp_r31[0x5C] = 0;
}

void fn_8019BD30(u8 *arg0) {
    s32 fn_80098110(void);
    void MuEvent_Create(s32, u16, s32, s32, u8 *);
    s32 ret;
    u16 flags;

    ret = fn_80098110();
    flags = 0x10;
    if (arg0[0x5c] != 0) {
        flags |= 0x20;
    }
    MuEvent_Create(ret, flags, *(s8 *)(arg0 + 0x5d), *(s8 *)(arg0 + 0x5e), arg0);
}

void fn_8019BD8C(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);
    extern u8 lbl_80296CAC[];
    s32 temp;

    temp = arg1;
    fn_8019D51C(Process_CreateChild(lbl_80296CAC, arg0), temp, 0);
}

void fn_8019BDD4(void *arg0) {
    void Mu_StartFlash(s32, s32, s32, void *);
    s32 var_r3;
    u8 temp_r4;
    void *temp_r3;

    if (M2C_FIELD(arg0, void **, 0x58) != NULL) {
        temp_r4 = M2C_FIELD(arg0, u8 *, 0x40);
        if (!(temp_r4 & 4)) {
            M2C_FIELD(arg0, u8 *, 0x40) = (u8)(temp_r4 | 4);
            ((void (*)(void *))M2C_FIELD(arg0, void **, 0x58))(arg0);
        }
    }
    temp_r3 = *M2C_FIELD(arg0, void ***, 0x34);
    if (temp_r3 != NULL) {
        var_r3 = M2C_FIELD(temp_r3, s32 *, 0x280);
    } else {
        var_r3 = 0;
    }
    Mu_StartFlash(var_r3, 1, 0x20, arg0);
}

void fn_8019BE54(void *arg0, void *arg1)
{
    void *Process_CreateChild(void *, void *);
    void fn_8019D51C(void *, void *, const char *);

    extern u8 lbl_80296C74[];
    extern u8 MapSelect_str[];

    void *result;

    result = Process_CreateChild(lbl_80296C74, arg0);

    fn_8019D51C(
        result,
        arg1,
        (const char *)(MapSelect_str + 0x1C6)
    );
}

#pragma global_optimizer off
void fn_8019BEA4(void *arg0) {
    void TargetList_GetAt(s32 *, s32);
    void *UnitRef_GetUnit(void);
    void fn_80053658(void *, s32, void *);
    void fn_80053680(void *, void *);
    void *Effect_Create(u8 *, void *);
    extern void fn_8019BF5C(void);
    extern s32 gTargetList[];
    s32 i;
    void *item;
    void *obj;

    i = 0;
    goto check;
loop:
    TargetList_GetAt(gTargetList, i);
    item = UnitRef_GetUnit();
    obj = Effect_Create((u8 *)arg0 + 0x41, arg0);
    if (obj) {
        fn_80053680(obj, item);
        *(void **)((u8 *)*(void **)((u8 *)obj + 0x30) + 0x40) = (void *)&fn_8019BF5C;
        fn_80053658(obj, 0, arg0);
        fn_80053658(obj, 1, item);
        *(s32 *)((u8 *)*(void **)((u8 *)obj + 0x30) + 8) =
            *(s32 *)((u8 *)*(void **)((u8 *)obj + 0x30) + 8) | 0x400;
    }
    i += 1;
check:
    if (i < *gTargetList) {
        goto loop;
    }
}
#pragma global_optimizer on
s32 fn_8019BF5C(void *arg0) {
    void fn_80054C14(void *);
    u8 Pad_IsButton(void *, s32);
    void Mu_StartFlash(s32, s32, s32, void *);
    void *temp_r4;
    void *temp_r31;
    s32 temp_r30;
    void *temp_r3;
    u8 temp_r3_flags;

    temp_r4 = *(void **)((u8 *)arg0 + 0x30);
    temp_r3 = *(void **)((u8 *)temp_r4 + 0x5C);
    temp_r31 = *(void **)((u8 *)temp_r4 + 0x4C);
    temp_r30 = *(s32 *)((u8 *)temp_r4 + 0x50);
    if (temp_r3 != NULL && Pad_IsButton(temp_r3, 0) != 0) {
        Mu_StartFlash(temp_r30, 1, 0x20, temp_r31);
        if (*(void **)((u8 *)temp_r31 + 0x58) != NULL) {
            temp_r3_flags = *(u8 *)((u8 *)temp_r31 + 0x40);
            if (!(temp_r3_flags & 4)) {
                *(u8 *)((u8 *)temp_r31 + 0x40) = (u8)(temp_r3_flags | 4);
                (*(void (**)(void *))((u8 *)temp_r31 + 0x58))(temp_r31);
            }
        }
    }
    fn_80054C14(arg0);
    return 0;
}

void fn_8019C00C(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, void *);
    extern u8 lbl_80296D5C[];
    extern u8 MapSelect_str[];
    void *temp_r31;

    temp_r31 = Process_CreateChild(lbl_80296D5C, arg0);
    fn_8019D51C(temp_r31, arg1, MapSelect_str + 0x1A4);
    M2C_FIELD(temp_r31, u8 *, 0x5C) = 2;
}

void fn_8019C070(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, void *);
    extern u8 lbl_80296938[];
    extern u8 MapSelect_str[];

    fn_8019D51C(Process_CreateChild(lbl_80296938, arg0), arg1, MapSelect_str + 0x1D4);
}

void fn_8019C0C0(void *arg0, void *arg1)
{
    void *Process_CreateChild(void *, void *);
    void fn_8019D51C(void *, void *, const char *);

    extern u8 lbl_80296C00[];
    extern u8 MapSelect_str[];

    void *result;

    result = Process_CreateChild(lbl_80296C00, arg0);

    fn_8019D51C(
        result,
        arg1,
        (const char *)(MapSelect_str + 0x1DD)
    );
}

void fn_8019C110(void *arg0, void *arg1)
{
    void *Process_CreateChild(void *, void *);
    void fn_8019D51C(void *, void *, const char *);

    extern u8 lbl_80296C00[];
    extern u8 MapSelect_str[];

    void *result;

    result = Process_CreateChild(lbl_80296C00, arg0);

    fn_8019D51C(
        result,
        arg1,
        (const char *)(MapSelect_str + 0x1E8)
    );
}

extern s32* gPadInput;
extern s32* lbl_8036ACC0;
extern void* fn_8005306C(void*);
extern void* fn_80053658(void*, s32, void*);
extern void* fn_800536CC(s32);
extern void* fn_800536D8(void*, s32);
extern void* Effect_Create(s32, void*);
s32 fn_8019CC04(void *arg0);
void fn_8019C160(void *arg0, void *arg1)
{
    void *Process_CreateChild(void *, void *);
    void fn_8019D51C(void *, void *, const char *);

    extern u8 lbl_80296C00[];
    extern u8 MapSelect_str[];

    void *result;

    result = Process_CreateChild(lbl_80296C00, arg0);

    fn_8019D51C(
        result,
        arg1,
        (const char *)(MapSelect_str + 0x1F5)
    );
}

void fn_8019C1B0(void *arg0) {
    u8 temp_r4;

    if (((M2C_UNK (*)()) M2C_FIELD(arg0, M2C_UNK (**)(), 0x58)) != NULL) {
        temp_r4 = M2C_FIELD(arg0, u8 *, 0x40);
        if (!(temp_r4 & 4)) {
            M2C_FIELD(arg0, u8 *, 0x40) = (u8) (temp_r4 | 4);
            M2C_FIELD(arg0, M2C_UNK (**)(), 0x58)();
        }
    }
}

void fn_8019C1F8(void *arg0)
{
    extern void *Effect_Create(void *, void *);
    extern void fn_800536D8(void *, void *);
    extern void fn_8005306C(void *);

    void *result;

    result = Effect_Create((u8 *)arg0 + 0x41, arg0);

    fn_800536D8(
        result,
        *(void **)(*(u8 **)((u8 *)arg0 + 0x30))
    );

    fn_8005306C(result);
}

void fn_8019C244(void *arg0) {
    void TargetList_GetAt(s32 *, s32);
    void *UnitRef_GetUnit(void);
    f32 fn_8004BDA8(void *, f32, f32);
    void *Unit_FadeFacing(void *, s32, s32, f32);
    void GActor_RequestRes(void *);
    extern s32 gTargetList[];
    extern f32 lbl_8036AF20;
    extern f32 lbl_8036AF00;
    s32 *list = gTargetList;
    s32 i;
    f32 sumX;
    f32 sumY;
    void *unit;
    f32 angle;
    s8 y;
    s8 x;
    s32 count;

    sumX = lbl_8036AF20;
    sumY = sumX;
    for (i = 0; i < list[0];) {
        TargetList_GetAt(list, i);
        unit = UnitRef_GetUnit();
        y = *(s8 *)((u8 *)unit + 0x19F);
        i++;
        x = *(s8 *)((u8 *)unit + 0x19E);
        sumX += (f32)x;
        sumY += (f32)y;
    }
    count = list[0];
    unit = *(void **)((u8 *)arg0 + 0x38);
    sumX /= (f32)count;
    sumY /= (f32)count;
    angle = fn_8004BDA8(unit, lbl_8036AF00 + sumX, lbl_8036AF00 + sumY);
    Unit_FadeFacing(*(void **)((u8 *)arg0 + 0x38), 0x10, (s32)arg0, angle);
    GActor_RequestRes((u8 *)arg0 + 0x41);
}

extern u16 gUnkGlobalVar_80296B20[];
void fn_8019C394(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);
    extern u8 lbl_80296B20[];
    s32 temp;

    temp = arg1;
    fn_8019D51C(Process_CreateChild(lbl_80296B20, arg0), temp, 0);
}

void fn_8019C3DC(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);
    extern u8 lbl_80296B20[];
    s32 temp;

    temp = arg1;
    fn_8019D51C(Process_CreateChild(lbl_80296B20, arg0), temp, 0);
}

void fn_8019C424(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);
    extern u8 lbl_80296B20[];
    s32 temp;

    temp = arg1;
    fn_8019D51C(Process_CreateChild(lbl_80296B20, arg0), temp, 0);
}

void fn_8019C46C(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);
    extern u8 lbl_80296B20[];
    s32 temp;

    temp = arg1;
    fn_8019D51C(Process_CreateChild(lbl_80296B20, arg0), temp, 0);
}

void fn_8019C4B4(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);
    extern u8 lbl_80296B20[];
    s32 temp;

    temp = arg1;
    fn_8019D51C(Process_CreateChild(lbl_80296B20, arg0), temp, 0);
}

void fn_8019C4FC(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);
    extern u8 lbl_80296B98[];
    s32 temp;

    temp = arg1;
    fn_8019D51C(Process_CreateChild(lbl_80296B98, arg0), temp, 0);
}

void fn_8019C544(void *arg0) {
    void *Effect_Create(void *, void *);
    void fn_800536CC(void *, void *);
    void fn_800536D8(void *, void *);
    void fn_8005306C(void *);
    void fn_80053658(void *, s32, void *);
    extern void fn_8019CC04(void);
    void *temp;
    void *p;

    temp = Effect_Create((u8 *)arg0 + 0x41, arg0);
    if (temp) {
        p = *(void **)((u8 *)arg0 + 0x30);
        if (p) {
            fn_800536CC(temp, *(void **)p);
        }
        p = *(void **)((u8 *)arg0 + 0x34);
        if (p) {
            fn_800536D8(temp, *(void **)p);
        }
        fn_8005306C(temp);
        *(void **)((u8 *)*(void **)((u8 *)temp + 0x30) + 0x40) = fn_8019CC04;
        fn_80053658(temp, 0, arg0);
        p = *(void **)((u8 *)temp + 0x30);
        *(u32 *)((u8 *)p + 8) |= 0x400;
    }
}

void fn_8019C5EC(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);
    extern u8 lbl_80296A80[];
    s32 temp;

    temp = arg1;
    fn_8019D51C(Process_CreateChild(lbl_80296A80, arg0), temp, 0);
}

void fn_8019C634(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);
    extern u8 lbl_80296A80[];
    s32 temp;

    temp = arg1;
    fn_8019D51C(Process_CreateChild(lbl_80296A80, arg0), temp, 0);
}

void fn_8019C67C(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);
    extern u8 lbl_80296A80[];
    s32 temp;

    temp = arg1;
    fn_8019D51C(Process_CreateChild(lbl_80296A80, arg0), temp, 0);
}

void fn_8019C6C4(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);
    extern u8 lbl_80296A80[];
    s32 temp;

    temp = arg1;
    fn_8019D51C(Process_CreateChild(lbl_80296A80, arg0), temp, 0);
}

void fn_8019C70C(void *arg0) {
    void *Effect_Create(void *, void *);
    void fn_800536CC(void *, void *);
    void fn_800536D8(void *, void *);
    void fn_8005306C(void *);
    void fn_80053658(void *, s32, void *);
    extern void fn_8019CD40(void);
    void *temp;
    void *p;

    temp = Effect_Create((u8 *)arg0 + 0x41, arg0);
    if (temp) {
        p = *(void **)((u8 *)arg0 + 0x30);
        if (p) {
            fn_800536CC(temp, *(void **)p);
        }
        p = *(void **)((u8 *)arg0 + 0x34);
        if (p) {
            fn_800536D8(temp, *(void **)p);
        }
        fn_8005306C(temp);
        *(void **)((u8 *)*(void **)((u8 *)temp + 0x30) + 0x40) = fn_8019CD40;
        fn_80053658(temp, 0, arg0);
        p = *(void **)((u8 *)temp + 0x30);
        *(u32 *)((u8 *)p + 8) |= 0x400;
    }
}

void fn_8019C7B4(void *arg0) {
    void *Effect_Create(void *, void *);
    void fn_800536CC(void *, void *);
    void fn_800536D8(void *, void *);
    void fn_8005306C(void *);
    void fn_80053658(void *, s32, void *);
    extern void MapSelect_UpdateTarget(void);
    void *temp;
    void *p;

    temp = Effect_Create((u8 *)arg0 + 0x41, arg0);
    if (temp) {
        p = *(void **)((u8 *)arg0 + 0x30);
        if (p) {
            fn_800536CC(temp, *(void **)p);
        }
        p = *(void **)((u8 *)arg0 + 0x34);
        if (p) {
            fn_800536D8(temp, *(void **)p);
        }
        fn_8005306C(temp);
        *(void **)((u8 *)*(void **)((u8 *)temp + 0x30) + 0x40) = MapSelect_UpdateTarget;
        fn_80053658(temp, 0, arg0);
        p = *(void **)((u8 *)temp + 0x30);
        *(u32 *)((u8 *)p + 8) |= 0x400;
    }
}

void fn_8019C85C(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);
    extern u8 lbl_80296A20[];
    s32 temp;

    temp = arg1;
    fn_8019D51C(Process_CreateChild(lbl_80296A20, arg0), temp, 0);
}

void fn_8019C8A4(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);
    extern u8 lbl_802969E4[];
    s32 temp;

    temp = arg1;
    fn_8019D51C(Process_CreateChild(lbl_802969E4, arg0), temp, 0);
}

void fn_8019C8EC(void *arg0) {
    void *Effect_Create(void *, void *);
    void fn_800536CC(void *, void *);
    void fn_800536D8(void *, void *);
    void fn_8005306C(void *);
    void fn_80053658(void *, s32, void *);
    extern void fn_8019CC80(void);
    void *temp;
    void *p;

    temp = Effect_Create((u8 *)arg0 + 0x41, arg0);
    if (temp) {
        p = *(void **)((u8 *)arg0 + 0x30);
        if (p) {
            fn_800536CC(temp, *(void **)p);
        }
        p = *(void **)((u8 *)arg0 + 0x34);
        if (p) {
            fn_800536D8(temp, *(void **)p);
        }
        fn_8005306C(temp);
        *(void **)((u8 *)*(void **)((u8 *)temp + 0x30) + 0x40) = fn_8019CC80;
        fn_80053658(temp, 0, arg0);
        p = *(void **)((u8 *)temp + 0x30);
        *(u32 *)((u8 *)p + 8) |= 0x400;
    }
}

void fn_8019C994(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);
    extern u8 lbl_80296970[];
    s32 temp;

    temp = arg1;
    fn_8019D51C(Process_CreateChild(lbl_80296970, arg0), temp, 0);
}

void fn_8019C9DC(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);
    extern u8 lbl_80296970[];
    s32 temp;

    temp = arg1;
    fn_8019D51C(Process_CreateChild(lbl_80296970, arg0), temp, 0);
}

void fn_8019CA24(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);
    extern u8 lbl_80296938[];
    s32 temp;

    temp = arg1;
    fn_8019D51C(Process_CreateChild(lbl_80296938, arg0), temp, 0);
}

void fn_8019CA6C(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void fn_8019D51C(void *, s32, s32);
    extern u8 lbl_80296938[];
    s32 temp;

    temp = arg1;
    fn_8019D51C(Process_CreateChild(lbl_80296938, arg0), temp, 0);
}

void fn_8019CAB4(void *arg0) {
    void *Effect_Create(void *, void *);
    void fn_800536CC(void *, void *);
    void fn_800536D8(void *, void *);
    void fn_8005306C(void *);
    void fn_80053658(void *, s32, void *);
    extern void MapSelect_UpdateTarget(void);
    void *temp;
    void *p;

    temp = Effect_Create((u8 *)arg0 + 0x41, arg0);
    if (temp) {
        p = *(void **)((u8 *)arg0 + 0x30);
        if (p) {
            fn_800536CC(temp, *(void **)p);
        }
        p = *(void **)((u8 *)arg0 + 0x34);
        if (p) {
            fn_800536D8(temp, *(void **)p);
        }
        fn_8005306C(temp);
        *(void **)((u8 *)*(void **)((u8 *)temp + 0x30) + 0x40) = MapSelect_UpdateTarget;
        fn_80053658(temp, 0, arg0);
        p = *(void **)((u8 *)temp + 0x30);
        *(u32 *)((u8 *)p + 8) |= 0x400;
    }
}

void fn_8019CB5C(void *arg0) {
    void *Effect_Create(void *, void *);
    void fn_800536CC(void *, void *);
    void fn_800536D8(void *, void *);
    void fn_8005306C(void *);
    void fn_80053658(void *, s32, void *);
    extern void fn_8019CD40(void);
    void *temp;
    void *p;

    temp = Effect_Create((u8 *)arg0 + 0x41, arg0);
    if (temp) {
        p = *(void **)((u8 *)arg0 + 0x30);
        if (p) {
            fn_800536CC(temp, *(void **)p);
        }
        p = *(void **)((u8 *)arg0 + 0x34);
        if (p) {
            fn_800536D8(temp, *(void **)p);
        }
        fn_8005306C(temp);
        *(void **)((u8 *)*(void **)((u8 *)temp + 0x30) + 0x40) = fn_8019CD40;
        fn_80053658(temp, 0, arg0);
        p = *(void **)((u8 *)temp + 0x30);
        *(u32 *)((u8 *)p + 8) |= 0x400;
    }
}

s32 fn_8019CC04(void *arg0) {
    u8 Pad_IsButton(void *, s32);
    void *temp_r4;
    void *temp_r31;
    void *temp_r3;
    u8 temp_r3_flags;

    temp_r4 = *(void **)((u8 *)arg0 + 0x30);
    temp_r3 = *(void **)((u8 *)temp_r4 + 0x5C);
    temp_r31 = *(void **)((u8 *)temp_r4 + 0x4C);
    if (temp_r3 != NULL && Pad_IsButton(temp_r3, 0) != 0) {
        if (*(void **)((u8 *)temp_r31 + 0x58) != NULL) {
            temp_r3_flags = *(u8 *)((u8 *)temp_r31 + 0x40);
            if (!(temp_r3_flags & 4)) {
                *(u8 *)((u8 *)temp_r31 + 0x40) = (u8)(temp_r3_flags | 4);
                (*(void (**)(void *))((u8 *)temp_r31 + 0x58))(temp_r31);
            }
        }
    }
    return 0;
}

s32 fn_8019CC80(void *arg0) {
    void Map_RefreshUnitMap(void *);
    void fn_80054C14(void *);
    u8 Pad_IsButton(void *, s32);
    void fn_800C1060(void *);
    extern u8 gBattleMap[];
    void *temp_r4;
    void *temp_r31;
    void *temp_r3;
    void *temp_r4_2;
    u8 temp_r3_flags;
    u8 *base;

    temp_r4 = *(void **)((u8 *)arg0 + 0x30);
    temp_r3 = *(void **)((u8 *)temp_r4 + 0x5C);
    temp_r31 = *(void **)((u8 *)temp_r4 + 0x4C);
    if (temp_r3 != NULL && Pad_IsButton(temp_r3, 0) != 0) {
        temp_r4_2 = *(void **)((u8 *)temp_r31 + 0x38);
        if (temp_r4_2 != NULL) {
            base = (u8 *)temp_r4_2;
            ((struct { u8 pad:3; u8 mid:3; u8 lo:2; } *)(base + 0x1A6))->mid = 4;
            Map_RefreshUnitMap(gBattleMap);
            fn_800C1060(temp_r31);
        }
        if (*(void **)((u8 *)temp_r31 + 0x58) != NULL) {
            temp_r3_flags = *(u8 *)((u8 *)temp_r31 + 0x40);
            if (!(temp_r3_flags & 4)) {
                *(u8 *)((u8 *)temp_r31 + 0x40) = (u8)(temp_r3_flags | 4);
                (*(void (**)(void *))((u8 *)temp_r31 + 0x58))(temp_r31);
            }
        }
    }
    fn_80054C14(arg0);
    return 0;
}

s32 fn_8019CD40(void *proc) {
    void *Camera_GetActive(void);
    void fn_80052CA8(void *);
    void fn_80054C14(void *);
    s32 fn_8005F894(void *, s32);
    u8 Pad_IsButton(void *, s32);
    u8 fn_80096B80(void);
    void fn_8017F474(void *, void *);
    void fn_800983E0(void *, void *);
    void fn_80098524(void *);
    void SeCue_PlayAtPos(void *, void *, s32);
    void Mu_StartFlash(s32, s32, s32, void *);
    extern u8 MapSelect_str[];
    extern f32 gMapSelectCamZoom;
    typedef struct { s32 x,y,z; } Vec3i;
    Vec3i copy, pos;
    void *pad;
    void *cmd;
    void *tmp;
    s32 actor;
    u8 flags;
    tmp = M2C_FIELD(proc, void **, 0x30);
    cmd = M2C_FIELD(tmp, void **, 0x4C);
    pad = M2C_FIELD(tmp, void **, 0x5C);
    if (!(M2C_FIELD(cmd,u8 *,0x40)&1)) {
        if (fn_8005F894(pad,0x12)<0) {
            tmp=Camera_GetActive();
            M2C_FIELD(tmp,f32 *,0x70)=gMapSelectCamZoom;
            fn_80098524(M2C_FIELD(cmd,void **,0x34));
        }
        M2C_FIELD(cmd,u8 *,0x40)|=1;
    }
    if(pad && Pad_IsButton(pad,0)) {
        if(fn_80096B80()) {
            fn_8017F474(M2C_FIELD(cmd,void **,0x34),cmd);
            fn_800983E0(&pos,M2C_FIELD(cmd,void **,0x34));
            copy=pos;
            SeCue_PlayAtPos(MapSelect_str+0xF3,&copy,100);
        } else {
            tmp=M2C_FIELD(M2C_FIELD(cmd,void **,0x34),void **,0);
            if(tmp) actor=M2C_FIELD(tmp,s32 *,0x280); else actor=0;
            Mu_StartFlash(actor,1,0x20,cmd);
        }
        if(M2C_FIELD(cmd,void (**)(void *),0x58)) {
            flags=M2C_FIELD(cmd,u8 *,0x40);
            if(!(flags&4)) {
                M2C_FIELD(cmd,u8 *,0x40)=flags|4;
                M2C_FIELD(cmd,void (**)(void *),0x58)(cmd);
            }
        }
    }
    if(Pad_IsButton(pad,0x12)) {
        fn_80052CA8(proc);
        tmp=Camera_GetActive();
        M2C_FIELD(tmp,f32 *,0x70)=gMapSelectCamZoom;
        fn_80098524(M2C_FIELD(cmd,void **,0x34));
    }
    fn_80054C14(proc);
    return 0;
}

/* Map-select process tick: init zoom, confirm selection on A, cancel on B. */
s32 MapSelect_UpdateTarget(void *proc) {
    M2C_UNK fn_80052CA8(void *);
    M2C_UNK fn_80054C14(void *);
    s32 fn_8005F894(s32, M2C_UNK);
    u8 Pad_IsButton(s32, M2C_UNK);
    M2C_UNK fn_80098524(void *);
    M2C_UNK FloatAnim_Start(void *, s32, void *);
    M2C_UNK fn_8017F040(void *, s32, void *);
    M2C_UNK Mu_StartFlash(s32, M2C_UNK, M2C_UNK, void *);
    extern f32 gMapSelectCamZoom;
    s32 pad;
    s32 height;
    void *self;
    s32 actor;
    u8 flags;
    void *work;
    void *cursor;
    void *unit;
    void *cam;
    void *cmd;

    work = M2C_FIELD(proc, void **, 0x30);
    self = proc;
    cmd = M2C_FIELD(work, void **, 0x4C);
    pad = M2C_FIELD(work, s32 *, 0x5C);
    if (!(M2C_FIELD(cmd, u8 *, 0x40) & 1)) {
        if (fn_8005F894(pad, 0x12) < 0) {
            cam = (void *)Camera_GetActive();
            M2C_FIELD(cam, f32 *, 0x70) = (f32) gMapSelectCamZoom;
            fn_80098524(M2C_FIELD(cmd, void **, 0x34));
        }
        M2C_FIELD(cmd, u8 *, 0x40) = (u8) (M2C_FIELD(cmd, u8 *, 0x40) | 1);
    }
    if (Pad_IsButton(pad, 0) != 0) {
        cursor = M2C_FIELD(cmd, void **, 0x34);
        height = (s32) M2C_FIELD(cursor, f32 *, 0xC);
        FloatAnim_Start(cursor, height, cmd);
        fn_8017F040(M2C_FIELD(cmd, void **, 0x34), height, cmd);
        unit = M2C_FIELD(M2C_FIELD(cmd, void **, 0x34), void **, 0);
        if (unit != NULL) {
            actor = M2C_FIELD(unit, s32 *, 0x280);
        } else {
            actor = 0;
        }
        Mu_StartFlash(actor, 1, 0x20, cmd);
        if (((M2C_UNK (*)(void *)) M2C_FIELD(cmd, M2C_UNK (**)(void *), 0x58)) != NULL) {
            flags = M2C_FIELD(cmd, u8 *, 0x40);
            if (!(flags & 4)) {
                M2C_FIELD(cmd, u8 *, 0x40) = (u8) (flags | 4);
                M2C_FIELD(cmd, M2C_UNK (**)(void *), 0x58)(cmd);
            }
        }
    }
    if (Pad_IsButton(pad, 0x12) != 0) {
        fn_80052CA8(self);
        cam = (void *)Camera_GetActive();
        M2C_FIELD(cam, f32 *, 0x70) = (f32) gMapSelectCamZoom;
        fn_80098524(M2C_FIELD(cmd, void **, 0x34));
    }
    fn_80054C14(self);
    return 0;
}

void fn_8019D038(void *arg0) {
    M2C_UNK fn_8017E394(s32, M2C_UNK, void *, M2C_UNK);
    fn_8017E394(M2C_FIELD(arg0, s32 *, 0x34), 0, arg0, 3);
}

void fn_8019D068(s32 arg0)
{
  u32 temp_r31;
  u32 Event_GetSlotUnit(M2C_UNK);
  M2C_UNK Unit_FaceToward(u32, u32, M2C_UNK, s32);
  u32 temp_r30;
  temp_r31 = Event_GetSlotUnit(0);
  temp_r30 = Event_GetSlotUnit(1);
  if ((temp_r31 != 0U) && (temp_r30 != 0U))
  {
    Unit_FaceToward(temp_r31, temp_r30, 0x10, arg0);
    Unit_FaceToward(temp_r30, temp_r31, 0x10, arg0);
  }
}

void fn_8019D0F4(void *arg0)
{
    extern void *fn_80055204(void *, s32);
    extern void strcpy(void *, void *);
    extern void GActor_RequestRes(void *);

    u8 *obj;
    void *result;

    obj = (u8 *)arg0;

    if ((s8)obj[0x41] == 0) {
        result = fn_80055204(
            *(void **)(*(u8 **)(obj + 0x30)),
            0
        );

        strcpy(obj + 0x41, result);
    }

    GActor_RequestRes(obj + 0x41);
}

void fn_8019D150(void *arg0) {
    u8 fn_80098568(void **);
    M2C_UNK MuDead_Start(s32, void *);
    s32 var_r3;
    s32 var_r3_2;
    void *temp_r3;
    void *temp_r3_2;

    if (fn_80098568(M2C_FIELD(arg0, void ***, 0x34)) != 0) {
        temp_r3 = *M2C_FIELD(arg0, void ***, 0x34);
        if (temp_r3 != NULL) {
            var_r3 = M2C_FIELD(temp_r3, s32 *, 0x280);
        } else {
            var_r3 = 0;
        }
        MuDead_Start(var_r3, arg0);
        return;
    }
    temp_r3_2 = *M2C_FIELD(arg0, void ***, 0x34);
    if (temp_r3_2 != NULL) {
        var_r3_2 = M2C_FIELD(temp_r3_2, s32 *, 0x280);
    } else {
        var_r3_2 = 0;
    }
    Mu_StartBlend(var_r3_2, 0, 0x18, 0);
}

void fn_8019D1DC(void *arg0) {
    void *tmp;
    u8 flags;

    tmp = *(void **)((u8 *)arg0 + 0x38);
    if (tmp != NULL) {
        fn_80050BA8(tmp, 0, 0);
    }
    tmp = *(void **)((u8 *)arg0 + 0x3C);
    if (tmp != NULL) {
        fn_80050BA8(tmp, 0, 0);
    }
    fn_8005376C();
    if (*(void **)((u8 *)arg0 + 0x58) != NULL) {
        flags = *(u8 *)((u8 *)arg0 + 0x40);
        if (!(flags & 4)) {
            *(u8 *)((u8 *)arg0 + 0x40) = (u8)(flags | 4);
            (*(void (**)(void *))((u8 *)arg0 + 0x58))(arg0);
        }
    }
}

s32 fn_8019D268(void) {
    void *Process_Find(void *);
    u8 fn_800537E8(void);
    void Process_Unlink(void *);
    extern u8 lbl_802968E8[];
    void *temp_r3;

    temp_r3 = Process_Find(lbl_802968E8);
    if (temp_r3 != NULL && fn_800537E8() == 0) {
        Process_Unlink(temp_r3);
        return 0;
    }
    return 1;
}

u8 fn_8019D2C0(void) {
    void *Process_Find(void *);
    extern u8 lbl_802968E8[];
    void *p;
    p = Process_Find(lbl_802968E8);
    if (p != NULL) {
        return M2C_FIELD(p, u8 *, 0x34);
    }
    return 1;
}

void fn_8019D2FC(void *arg0) {
    void *Process_Create(void *, void *);
    extern u8 lbl_802968E8[];
    void *temp_r3;
    void *temp_r4;
    s32 var_r0;

    temp_r3 = Process_Create(lbl_802968E8, arg0);
    temp_r4 = *(void **)((u8 *)arg0 + 0x30);
    temp_r4 = *(void **)temp_r4;
    if (temp_r4 != NULL) {
        var_r0 = *(s32 *)((u8 *)temp_r4 + 0x280);
    } else {
        var_r0 = 0;
    }
    *(s32 *)((u8 *)temp_r3 + 0x30) = var_r0;
    *(u8 *)((u8 *)temp_r3 + 0x34) = 0;
    *(u8 *)((u8 *)temp_r3 + 0x35) = 0;
}

void fn_8019D360(void *arg0) {
    void *temp_r5;

    if ((u8) M2C_FIELD(arg0, u8 *, 0x35) == 0) {
        temp_r5 = M2C_FIELD(arg0, void **, 0x30);
        M2C_FIELD(temp_r5, s32 *, 0x1C) = (s32) (M2C_FIELD(temp_r5, s32 *, 0x1C) & 0xFFFFFF3F);
        M2C_FIELD(arg0, u8 *, 0x35) = 1U;
    }
}

/* Wait for the unit's map anim to finish; pad buttons can skip or cancel. */
void Mu_WaitAnimTick(void *proc) {
    u8 Pad_IsButton(void *, s32);
    u8 Mu_IsAnimDone(void *);
    void fn_800056A0(s32);
    void Process_ClearFunc(void *);
    void *unit;
    u32 *modelFlags;

    unit = *(void **)((u8 *)proc + 0x30);
    modelFlags = (u32 *)((u8 *)unit + 0x1C);

    if (*(u8 *)((u8 *)proc + 0x34) == 0) {
        if (Pad_IsButton(modelFlags, 2)) {
            *modelFlags |= 0x80;
            *(u8 *)((u8 *)proc + 0x34) = 1;
        }
        if (Mu_IsAnimDone(*(void **)((u8 *)proc + 0x30))) {
            fn_800056A0(0);
            *(u8 *)((u8 *)proc + 0x34) = 1;
        }
    } else {
        if (Mu_IsAnimDone(unit)) {
            Process_ClearFunc(proc);
        }
    }

    if (*(u8 *)((u8 *)proc + 0x34) == 1) {
        if (Pad_IsButton(modelFlags, 8)) {
            *modelFlags |= 0x40;
        }
    }
}

void fn_8019D458(void *arg0) {
    M2C_UNK fn_80184618(s32, void *);
    M2C_UNK Mu_StartTransfer(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Mu_StartBlend(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    Mu_StartBlend(M2C_FIELD(arg0, s32 *, 0x30), 5, 0x10, 0);
    Mu_StartTransfer(M2C_FIELD(arg0, s32 *, 0x30), 0, 0x10, 0);
    fn_80184618(M2C_FIELD(arg0, s32 *, 0x30), arg0);
}

void fn_8019D4B4(void *arg0) {
    void *Camera_GetActive(void);
    void Unit_FocusCamera(void *, s32);
    extern f32 gMapSelectCamZoom;
    void *tmp;

    tmp = Camera_GetActive();
    *(f32 *)((u8 *)tmp + 0x70) = gMapSelectCamZoom;
    Unit_FocusCamera(*(void **)((u8 *)arg0 + 0x30), 0);
}

void fn_8019D4F4(void *arg0) {
    M2C_UNK fn_8004FC70(s32, M2C_UNK);
    fn_8004FC70(M2C_FIELD(arg0, s32 *, 0x30), 5);
}

void fn_8019D51C(void *arg0, s32 arg1, char *arg2) {
    void fn_80097AB4(void);
    s16 fn_80097740(void);
    void Event_AdvanceCmd(s32);
    void **fn_80098094(void);
    void **fn_8009809C(void);
    void fn_80050BA8(void *, s32, s32);
    char *strcpy(char *, char *);
    void Process_Goto(void *, s32);
    extern u8 gBattleMap[];
    u8 *self;
    void *tmp;
    void *u38;
    void *u3c;
    u8 flag;
    s8 x;
    s8 y;
    void *info;

    self = (u8 *)arg0;
    self[0x40] = 0;
    *(s32 *)(self + 0x58) = arg1;
    fn_80097AB4();
    *(s16 *)(self + 0x56) = fn_80097740();
    Event_AdvanceCmd(*(s16 *)(self + 0x56));
    *(void **)(self + 0x30) = (void *)fn_80098094();
    *(void **)(self + 0x34) = (void *)fn_8009809C();
    tmp = *(void **)(*(void **)(self + 0x30));
    if (tmp != 0) {
        u38 = *(void **)((u8 *)tmp + 0x280);
    } else {
        u38 = 0;
    }
    *(void **)(self + 0x38) = u38;
    tmp = *(void **)(*(void **)(self + 0x34));
    if (tmp != 0) {
        u3c = *(void **)((u8 *)tmp + 0x280);
    } else {
        u3c = 0;
    }
    *(void **)(self + 0x3C) = u3c;
    if (*(void **)(self + 0x38) != 0) {
        fn_80050BA8(*(void **)(self + 0x38), 0, 1);
    }
    if (*(void **)(self + 0x3C) != 0) {
        fn_80050BA8(*(void **)(self + 0x3C), 0, 1);
    }
    if (arg2 != 0) {
        strcpy((char *)(self + 0x41), arg2);
    } else {
        self[0x41] = 0;
    }
    u38 = *(void **)(self + 0x38);
    flag = 0;
    if (u38 != 0) {
        info = *(void **)((u8 *)u38 + 0x190);
        if (*(u8 *)((u8 *)info + 8) != 1) {
            flag = 1;
            goto check_done;
        }
    }
    if (u38 != 0) {
        x = ((s8 *)u38)[0x19E];
        y = ((s8 *)u38)[0x19F];
        if ((gBattleMap + x + (y << 6))[0x200D] != 0) {
            flag = 1;
        }
    }
    u3c = *(void **)(self + 0x3C);
    if (u3c != 0) {
        x = ((s8 *)u3c)[0x19E];
        y = ((s8 *)u3c)[0x19F];
        if ((gBattleMap + x + (y << 6))[0x200D] != 0) {
            flag = 1;
        }
    }
check_done:
    if (flag == 0) {
        Process_Goto(arg0, 0x63);
    }
}

/* Register event-arrow script command handlers. */
void Script_RegisterEventArrowCommands(void) {
    void Script_RegisterCommand(void *, void *, s32);
    extern u8 gEventArrowCmdNames[];
    void fn_8019D9BC(void);
    void fn_8019D958(void);
    void fn_8019D8CC(void);
    void fn_8019D850(void);
    void fn_8019D930(void);
    void fn_8019D7A8(void);
    void fn_8019D90C(void);

    Script_RegisterCommand(gEventArrowCmdNames + 0xDF, fn_8019D9BC, 5);
    Script_RegisterCommand(gEventArrowCmdNames + 0xF0, fn_8019D958, 2);
    Script_RegisterCommand(gEventArrowCmdNames + 0x100, fn_8019D8CC, 2);
    Script_RegisterCommand(gEventArrowCmdNames + 0x110, fn_8019D850, 5);
    Script_RegisterCommand(gEventArrowCmdNames + 0x120, fn_8019D930, 1);
    Script_RegisterCommand(gEventArrowCmdNames + 0x132, fn_8019D7A8, 0);
    Script_RegisterCommand(gEventArrowCmdNames + 0x141, fn_8019D90C, 0);
}

s32 fn_8019D7A8(void) {
    extern s32 gUiInputFlags;
    extern u8 lbl_80296F50[];

    void *Process_CreateChild(void *, s32);
    void fn_80013864(void);
    s32 fn_800C0658(void);
    u8 fn_80194E38(void);

    if (gUiInputFlags & 1) {
        return 0;
    }
    if (fn_80194E38() != 0) {
        Process_CreateChild(lbl_80296F50, fn_800C0658());
        fn_80013864();
    }
    return 1;
}

void fn_8019D800(s32 arg0) {
    void Process_ClearFunc(s32);
    u8 fn_80194E38();
    extern s32 gUiInputFlags;

    if (gUiInputFlags & 1) {
        Process_ClearFunc(arg0);
    } else if (fn_80194E38() == 0) {
        Process_ClearFunc(arg0);
    }
}

s32 fn_8019D850(s32 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    void *EventArrow_Get(s32);
    void fn_8019514C(void *, void *);
    extern s32 lbl_8036C500;
    void *obj;
    s32 spC;
    s32 sp8;

    obj = EventArrow_Get(arg0);
    sp8 = lbl_8036C500;
    ((u8 *)&sp8)[0] = arg1;
    ((u8 *)&sp8)[1] = arg2;
    ((u8 *)&sp8)[2] = arg3;
    ((u8 *)&sp8)[3] = arg4;
    spC = sp8;
    fn_8019514C(obj, &spC);
    return 1;
}

extern void *EventArrow_Get(s32);
extern void fn_80195170(void *arg0, s8 arg1);
s32 fn_8019D8CC(s32 arg0, s32 arg1) {
    void *EventArrow_Get(s32);
    void fn_80195170(void *, s32);
    fn_80195170(EventArrow_Get(arg0), arg1 != 0);
    return 1;
}

s32 fn_8019D90C(void) {
    M2C_UNK fn_80194E10();
    fn_80194E10();
    return 1;
}

s32 fn_8019D930(void) {
    M2C_UNK EventArrow_Get();
    M2C_UNK fn_80195880();
    EventArrow_Get();
    fn_80195880();
    return 1;
}

s32 fn_8019D958(s32 arg0, s32 arg1) {
    void *EventArrow_Get(s32);
    void fn_8019588C(void *, s32);
    extern f32 lbl_8036AF48;
    f32 temp_f1;
    void *obj;

    obj = EventArrow_Get(arg0);
    temp_f1 = (f32) arg1;
    fn_8019588C(obj, (s32) (temp_f1 / lbl_8036AF48));
    return 1;
}

s32 fn_8019D9BC(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4) {
typedef struct { f32 x,y,z; } Vec3;
extern Vec3 lbl_8027AC38;
extern u8 gBattleMap[];
extern f32 lbl_8036AF48,lbl_8036AF58,lbl_8036AF5C;
void *EventArrow_Get(s32);
f32 Map_SampleHeight(void*,f32,f32);
void fn_801958C8(void*,s32,void*);
Vec3 copy;
Vec3 pos;
void *obj=EventArrow_Get(arg0);
if(arg4<=-1000) arg4=(s32)(Map_SampleHeight(gBattleMap,lbl_8036AF58+(f32)arg2,lbl_8036AF58+(f32)arg3)-lbl_8036AF5C);
pos=lbl_8027AC38;
pos.x=lbl_8036AF58+(f32)arg2;
pos.y=lbl_8036AF58+(f32)arg3;
pos.z=(f32)arg4;
copy=pos;
fn_801958C8(obj,(s32)((f32)arg1/lbl_8036AF48),&copy);
return 1;
}

void fn_8019DB28(void) {
    void Process_UnlinkByKey(void *);
    void fn_800A84A0(void);
    void fn_800C0818(s32);
    void fn_801293C0(void);
    void fn_80199C2C(void);
    void fn_8005376C(void);
    extern u8 Proc_MuEventInst[];

    fn_800C0818(0);
    fn_801293C0();
    Process_UnlinkByKey(Proc_MuEventInst);
    fn_80199C2C();
    fn_800A84A0();
    fn_8005376C();
}

void fn_8019DB68(void) {
    void Script_RegisterCommand(void *, void *, s32);
    extern u8 lbl_8027AD98[];
    void fn_801A23D0(void);
    void fn_801A233C(void);
    void fn_801A21C0(void);
    void fn_801A212C(void);
    void fn_801A2098(void);
    void fn_801A1DB8(void);
    void fn_801A1D04(void);
    void fn_801A1198(void);
    void fn_801A0F68(void);
    void ScriptCmd_UnitWarp(void);
    void fn_801A0D64(void);
    void fn_801A2464(void);
    void fn_801A0A10(void);
    void fn_801A0B20(void);
    void MuDead_StartForUnit(void);
    void MuEvent_StartForUnit(void);
    void fn_801A06EC(void);
    void fn_801A0434(void);
    void ScriptCmd_UnitTransform(void);
    void fn_801A147C(void);
    void fn_801A19D8(void);
    void fn_801A1960(void);
    void fn_801A1934(void);
    void fn_801A1884(void);
    void fn_801A17CC(void);
    void fn_801A17A0(void);
    void fn_801A16E8(void);
    void fn_801A16BC(void);
    void fn_801A1604(void);
    void fn_801A14D8(void);
    void fn_801A0400(void);
    void fn_801A0374(void);
    void Map_HideObjAt(void);
    void Map_ShowObjAt(void);
    void fn_8019F4A8(void);
    void fn_8019F2D0(void);
    void Map_HideLinkedAt(void);
    void Map_ShowLinkedAt(void);
    void fn_8019EEE0(void);
    void Map_SelectObjAt(void);
    void fn_8019F230(void);
    void fn_8019ED74(void);
    void Map_OpenObjAt(void);
    void fn_8019EAF4(void);
    void ScriptCmd_EventMapFlags(void);
    void fn_801A0258(void);
    void fn_801A01D8(void);
    void fn_801A016C(void);
    void fn_801A0100(void);
    void fn_801A0208(void);
    void ScriptCmd_EventSetSavedByte(void);
    void fn_801A1B58(void);
    void ScriptCmd_EventSepia(void);
    void fn_801A25FC(void);
    void fn_801A0060(void);
    void fn_8019FFBC(void);
    void fn_8019FF68(void);
    void fn_8019FEB8(void);
    void fn_8019FE54(void);
    void fn_8019FE2C(void);
    void ScriptCmd_CamPathAddScaled(void);
    void fn_8019FCD0(void);
    void fn_8019FCAC(void);
    void fn_8019FC88(void);
    void fn_8019FC08(void);
    void fn_801A2004(void);
    void fn_8019EA74(void);
    void fn_8019EA48(void);
    void fn_8019E818(void);
    void fn_8019E764(void);
    void fn_8019E6D8(void);
    void fn_8019E6B4(void);
    void fn_8019F9B4(void);
    void fn_8019F914(void);
    void fn_8019FA50(void);
    void fn_8019EC0C(void);
    void Map_GetScaledHeight(void);
    void ScriptCmd_GetScaledHeight(void);
    void fn_8019E690(void);
    void fn_8019E668(void);
    void fn_8019E640(void);
    void fn_8019E5D4(void);
    void fn_801A2254(void);
    void fn_8019E564(void);
    void fn_8019E528(void);
    void fn_8019E4EC(void);

    Script_RegisterCommand(lbl_8027AD98 + 0x152, fn_801A23D0, 0);
    Script_RegisterCommand(lbl_8027AD98 + 0x15F, fn_801A233C, 0);
    Script_RegisterCommand(lbl_8027AD98 + 0x16B, fn_801A21C0, 0);
    Script_RegisterCommand(lbl_8027AD98 + 0x176, fn_801A212C, 0);
    Script_RegisterCommand(lbl_8027AD98 + 0x182, fn_801A2098, 0);
    Script_RegisterCommand(lbl_8027AD98 + 0x18E, fn_801A1DB8, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x19A, fn_801A1D04, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x1A7, fn_801A1198, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x1B3, fn_801A0F68, 3);
    Script_RegisterCommand(lbl_8027AD98 + 0x1BF, ScriptCmd_UnitWarp, 3);
    Script_RegisterCommand(lbl_8027AD98 + 0x1CA, fn_801A0D64, 3);
    Script_RegisterCommand(lbl_8027AD98 + 0x1D5, fn_801A2464, 0);
    Script_RegisterCommand(lbl_8027AD98 + 0x1E2, fn_801A0A10, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x1EB, fn_801A0B20, 3);
    Script_RegisterCommand(lbl_8027AD98 + 0x1F5, MuDead_StartForUnit, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x1FE, MuEvent_StartForUnit, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x20A, fn_801A06EC, 3);
    Script_RegisterCommand(lbl_8027AD98 + 0x215, fn_801A0434, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x223, ScriptCmd_UnitTransform, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x238, fn_801A147C, 3);
    Script_RegisterCommand(lbl_8027AD98 + 0x24D, fn_801A19D8, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x254, fn_801A1960, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x267, fn_801A1934, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x275, fn_801A1884, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x287, fn_801A17CC, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x293, fn_801A17A0, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x2A6, fn_801A16E8, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x2B5, fn_801A16BC, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x2CB, fn_801A1604, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x2D6, fn_801A14D8, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x2E6, fn_801A0400, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x2EE, fn_801A0374, 0);
    Script_RegisterCommand(lbl_8027AD98 + 0x2F8, Map_HideObjAt, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x308, Map_ShowObjAt, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x319, fn_8019F4A8, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x322, fn_8019F2D0, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x32C, Map_HideLinkedAt, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x33C, Map_ShowLinkedAt, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x34D, fn_8019EEE0, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x356, Map_SelectObjAt, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x360, fn_8019F230, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x369, fn_8019ED74, 3);
    Script_RegisterCommand(lbl_8027AD98 + 0x371, Map_OpenObjAt, 3);
    Script_RegisterCommand(lbl_8027AD98 + 0x37A, fn_8019EAF4, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x38B, ScriptCmd_EventMapFlags, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x396, fn_801A0258, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x39F, fn_801A01D8, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x3AA, fn_801A016C, 3);
    Script_RegisterCommand(lbl_8027AD98 + 0x3B5, fn_801A0100, 3);
    Script_RegisterCommand(lbl_8027AD98 + 0x3C0, fn_801A0208, 6);
    Script_RegisterCommand(lbl_8027AD98 + 0x3C7, ScriptCmd_EventSetSavedByte, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x3CF, fn_801A1B58, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x3D9, ScriptCmd_EventSepia, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x3E2, fn_801A25FC, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x3F1, fn_801A0060, 3);
    Script_RegisterCommand(lbl_8027AD98 + 0x3FE, fn_8019FFBC, 3);
    Script_RegisterCommand(lbl_8027AD98 + 0x412, fn_8019FF68, 0);
    Script_RegisterCommand(lbl_8027AD98 + 0x420, fn_8019FEB8, 0);
    Script_RegisterCommand(lbl_8027AD98 + 0x42E, fn_8019FE54, 0);
    Script_RegisterCommand(lbl_8027AD98 + 0x443, fn_8019FE2C, 0);
    Script_RegisterCommand(lbl_8027AD98 + 0x455, ScriptCmd_CamPathAddScaled, 4);
    Script_RegisterCommand(lbl_8027AD98 + 0x466, fn_8019FCD0, 4);
    Script_RegisterCommand(lbl_8027AD98 + 0x478, fn_8019FCAC, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x489, fn_8019FC88, 0);
    Script_RegisterCommand(lbl_8027AD98 + 0x49B, fn_8019FC08, 0);
    Script_RegisterCommand(lbl_8027AD98 + 0x4AB, fn_801A2004, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x4BE, fn_8019EA74, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x4CC, fn_8019EA48, 0);
    Script_RegisterCommand(lbl_8027AD98 + 0x4DA, fn_8019E818, 3);
    Script_RegisterCommand(lbl_8027AD98 + 0x4E5, fn_8019E764, 0);
    Script_RegisterCommand(lbl_8027AD98 + 0x4F0, fn_8019E6D8, 3);
    Script_RegisterCommand(lbl_8027AD98 + 0x4FB, fn_8019E6B4, 0);
    Script_RegisterCommand(lbl_8027AD98 + 0x50A, fn_8019F9B4, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x518, fn_8019F914, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x526, fn_8019FA50, 3);
    Script_RegisterCommand(lbl_8027AD98 + 0x534, fn_8019EC0C, 3);
    Script_RegisterCommand(lbl_8027AD98 + 0x542, Map_GetScaledHeight, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x553, ScriptCmd_GetScaledHeight, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x560, fn_8019E690, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x56E, fn_8019E668, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x57C, fn_8019E640, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x589, fn_8019E5D4, 2);
    Script_RegisterCommand(lbl_8027AD98 + 0x596, fn_801A2254, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x5A2, fn_8019E564, 1);
    Script_RegisterCommand(lbl_8027AD98 + 0x5AD, fn_8019E528, 0);
    Script_RegisterCommand(lbl_8027AD98 + 0x5B9, fn_8019E4EC, 0);
}

s32 fn_8019E4EC(void) {
    u8 fn_800A69D8(M2C_UNK *, s32 *);
    M2C_UNK spC;
    s32 sp8;

    if (fn_800A69D8(&spC, &sp8) != 0) {
        return sp8;
    }
    return 0;
}

s32 fn_8019E528(void) {
    u8 fn_800A69D8(M2C_UNK *, s32 *);
    s32 spC;
    M2C_UNK sp8;

    if (fn_800A69D8(&spC, &sp8) != 0) {
        return spC;
    }
    return 0;
}

s32 fn_8019E564(s32 arg0)
{
    void Process_UnlinkByKey(void *);
    void Process_Create(void *, s32);
    s32 fn_800C0658(void);
    extern u8 lbl_80297070[];

    if (arg0 != 0) {
        Process_Create(lbl_80297070, fn_800C0658());
    } else {
        Process_UnlinkByKey(lbl_80297070);
    }
    return 1;
}

void fn_8019E5B0(void) {
    M2C_UNK fn_8000A274(M2C_UNK);
    fn_8000A274(0);
}

s32 fn_8019E5D4(u8 arg0, s32 arg1) {
    extern u8 gUnits[];
    u8 *var_r3;
    if (arg0 != 0) {
        var_r3 = &gUnits[(arg0 - 1) * 0x280];
    } else {
        var_r3 = NULL;
    }
    if ((var_r3 == NULL) || (*(u32 *)(var_r3 + 0x188) == 0)) {
        return 0;
    }
    if (arg1 != 0) {
        *(s32 *)(var_r3 + 0x1A0) = *(s32 *)(var_r3 + 0x1A0) | 1;
    } else {
        *(s32 *)(var_r3 + 0x1A0) = *(s32 *)(var_r3 + 0x1A0) & ~1;
    }
    return 1;
}

s32 fn_8019E640(s32 arg0) {
    u8 var_r0;
    
    var_r0 = lbl_8036728B | 0x2;
    if (arg0 != 0) {
        var_r0 = lbl_8036728B & 0xFFFFFFFD;
    }
    lbl_8036728B = var_r0;
    return 1;
}

s32 fn_8019E668(s32 arg0) {
    u8 var_r0;
    
    var_r0 = lbl_8036728B & 0xFFFFFFFB;
    if (arg0 != 0) {
        var_r0 = lbl_8036728B | 0x4;
    }
    lbl_8036728B = var_r0;
    return 1;
}

s32 fn_8019E690(s32 arg0) {
    extern u8 lbl_8036728B;
    u8 var_r0;

    var_r0 = lbl_8036728B | 1;
    if (arg0 != 0) {
        var_r0 = lbl_8036728B & 0xFE;
    }
    lbl_8036728B = var_r0;
    return 1;
}

s32 fn_8019E6B4(void) {
    M2C_UNK fn_8018CF08();
    fn_8018CF08();
    return 1;
}

s32 fn_8019E6D8(s32 arg0, s32 arg1, s32 arg2) {
    s32 fn_800C0658(void);
    void fn_8018CFA4(s32, s32, s32, s32, s32);
    extern f32 lbl_8036AF74;
    f32 temp_f1;
    s32 temp;

    temp = fn_800C0658();
    temp_f1 = (f32)arg1;
    fn_8018CFA4(arg0, (s32)(temp_f1 / lbl_8036AF74), arg2, 1, temp);
    return 1;
}

s32 fn_8019E764(void) {
    extern s32 gUiInputFlags;
    extern u8 lbl_80297058[];

    void *Process_CreateChild(void *, s32);
    void fn_80013864(void);
    void fn_8005376C(void);
    u8 fn_800537E8(void);
    s32 fn_800C0658(void);

    if (gUiInputFlags & 1) {
        fn_8005376C();
        return 0;
    }
    if (fn_800537E8() != 0) {
        Process_CreateChild(lbl_80297058, fn_800C0658());
        fn_80013864();
    }
    return 1;
}

void fn_8019E7C0(void *arg0)
{
    void fn_8005376C(void);
    s32 fn_800537E8(void);
    void Process_ClearFunc(void *);

    extern u32 gUiInputFlags;

    if (gUiInputFlags & 1) {
        fn_8005376C();
        Process_ClearFunc(arg0);
    } else {
        if ((u8)fn_800537E8() == 0) {
            Process_ClearFunc(arg0);
        }
    }
}

s32 fn_8019E818(s32 arg0, s32 arg1, s32 arg2) {
    void *Process_CreateChild(void *, s32);
    void fn_80013864(void);
    void GActor_RequestRes(s32);
    s32 fn_800C0658(void);
    void strcpy(void *, s32);
    extern u8 lbl_80297040[];
    extern s32 gUiInputFlags;
    void *obj;

    if (gUiInputFlags & 1) {
        return 0;
    }
    obj = Process_CreateChild(lbl_80297040, fn_800C0658());
    strcpy((u8 *)obj + 0x30, arg0);
    *(s32 *)((u8 *)obj + 0x50) = arg1;
    *(s32 *)((u8 *)obj + 0x54) = arg2;
    GActor_RequestRes(arg0);
    fn_80013864();
    return 1;
}

void fn_8019E8B0(void *self)
{
  extern u32 gUiInputFlags;
  extern u8 Proc_MuEventInst[];
  extern u8 gBattleMap[];
  extern f64 lbl_8036AF78;
  extern f32 lbl_8036AF80;
  extern f32 lbl_8036AF84;
  void Process_ClearFunc(void *);
  u8 GActor_CheckResources(void *);
  void *Process_Find(void *);
  void *fn_80127C48(void);
  void *fn_800C0658(void);
  void *Process_Create(void *, void *);
  void *fn_80053AE8(void *, void *);
  s32 fn_80052F9C(void *);
  f32 Map_SampleHeight(void *, f32, f32);
  void Effect_SetPos(void *, f32, f32, f32);
  void *parent;
  void *effect;
  void *host;
  f32 height;
  (void)lbl_8036AF78;
  if (gUiInputFlags & 1)
  {
    Process_ClearFunc(self);
    return;
  }
  if (GActor_CheckResources((u8 *) self + ((short) 0x30)))
  {
    host = Process_Find(Proc_MuEventInst);
    if (host)
    {
      parent = host;
    }
    else
    {
      parent = fn_80127C48();
      if (!parent)
      {
        parent = fn_800C0658();
      }
      parent = Process_Create(Proc_MuEventInst, parent);
    }
    effect = fn_80053AE8(((u8 *) self) + 0x30, parent);
    switch (fn_80052F9C(effect))
    {
      case 0:
      {
        height = Map_SampleHeight(gBattleMap, (f32) ((s8) (*((s32 *) (((s8 *) self) + 0x50)))), (f32) ((s8) (*((s32 *) (((s8 *) self) + 0x54)))));
        Effect_SetPos(effect, lbl_8036AF80 + ((f32) (*((s32 *) (((s8 *) self) + 0x50)))), lbl_8036AF80 + ((f32) (*((s32 *) (((s8 *) self) + 0x54)))), height);
        break;
      }
      default:
      {
        Effect_SetPos(effect, (f32) (*((s32 *) (((s8 *) self) + 0x50))), (f32) (*((s32 *) (((s8 *) self) + 0x54))), lbl_8036AF84);
      }

    }

    Process_ClearFunc(self);
  }
}

s32 fn_8019EA48(void) {
    void Process_UnlinkByKey(void *);
    extern u8 lbl_80297024[];
    Process_UnlinkByKey(lbl_80297024);
    return 1;
}

s32 fn_8019EA74(s32 arg0, s32 arg1) {
    void *Process_Create(void *, s32);
    s32 fn_800C0658(void);
    extern u8 lbl_80297024[];
    void *temp_r3;

    temp_r3 = Process_Create(lbl_80297024, fn_800C0658());
    M2C_FIELD(temp_r3, s32 *, 0x30) = arg0;
    M2C_FIELD(temp_r3, s32 *, 0x34) = arg1;
    return 1;
}

void fn_8019EAC8(void *arg0) {
    M2C_UNK fn_800F18A4(s32, s32);
    fn_800F18A4(M2C_FIELD(arg0, s32 *, 0x30), M2C_FIELD(arg0, s32 *, 0x34));
}

s32 fn_8019EAF4(s32 x, s32 y) {
    s32 Map_Get(void);
    void *Map_FindObjNear(void *, s32, s32, u32, s32);
    void *Map_FindObjAt(void *, s32, s32, u32, s32);
    void MapObjEvent_Push(void *, s32, s32, s32, s32);
    void fn_800056A0(s32);
    void fn_80049D08(void *);
    void fn_80049CB4(void *, void *);
    s32 fn_800C0658(void);
    void fn_8012ADAC(s32, s32, u32);
    void fn_80013864(void);

    extern u8 gMapObjEventList[];
    extern u32 gUiInputFlags;
    extern u32 lbl_8036AF70;

    u8 *obj;
    u32 value;
    struct Pair { s32 x; s32 y; } p;
    u8 *other;

    obj = (u8 *)Map_FindObjNear(
        (void *)Map_Get(),
        x,
        y,
        0xA00,
        0x10
    );

    if (obj == (u32)NULL) {
        fn_800056A0(0);
        return 0;
    }

    p.x = M2C_FIELD(obj, s8 *, 0);
    p.y = M2C_FIELD(obj, s8 *, 1);

    MapObjEvent_Push(
        gMapObjEventList,
        p.x,
        p.y,
        0x25,
        0
    );

    if (gUiInputFlags & 1) {
        obj[2] |= 1;

        other = (u8 *)Map_FindObjAt(
            (void *)Map_Get(),
            p.x,
            p.y,
            0x20000,
            0
        );

        if (other != (u32)NULL) {
            fn_80049D08(other);

            value = lbl_8036AF70;
            fn_80049CB4(other, &value);

            other[2] &= ~1;
        }

        return 0;
    }

    fn_8012ADAC(p.x, p.y, fn_800C0658());
    fn_80013864();

    return 1;
}

s32 fn_8019EC0C(s32 arg0, s32 arg1, u8 arg2) {
    void *Map_FindObjAt(void *, s32, s32, s32, s32);
    s32 Map_Get(void);
    void fn_80044450(s32, s32);
    void fn_80016180(void);
    void fn_800056A0(s32);
    
    u8 *temp_r3;

    temp_r3 = Map_FindObjAt((void *) Map_Get(), arg0, arg1, 0x800, 0x10);
    if (temp_r3 == NULL) {
        fn_800056A0(0);
        return 0;
    }
    
    if (arg2 != 0) {
        temp_r3[2] = (u8)(temp_r3[2] & 0xFFFFFFFD);
    } else {
        temp_r3[2] = (u8)(temp_r3[2] | 2);
    }
    
    fn_80044450(Map_Get(), 1);
    fn_80016180();
    return 1;
}

s32 Map_OpenObjAt(s32 unused, s32 x, s32 y) {
    s32 Map_Get(void);
    void *Map_FindObjNear(void *, s32, s32, u32, s32);
    void fn_800056A0(s32);
    void MapObjEvent_Push(void *, s32, s32, s32, s32);
    void fn_80049D08(void *);
    s32 fn_800C0658(void);
    void fn_800498A4(void *, s32, s32);
    void fn_80013864(void);
    extern u8 gMapObjEventList[];
    extern s32 gUiInputFlags;
    u8 *obj;

    (void)unused;
    // Find a map object at/near (x,y), queue open event 0x24, and start its open anim (or cancel if UI flag 1).
    obj = (u8 *)Map_FindObjNear((void *)Map_Get(), x, y, 0xa00, 0x10);
    if (obj == NULL) {
        fn_800056A0(0);
        return 0;
    }
    MapObjEvent_Push(gMapObjEventList, (s8)obj[0], (s8)obj[1], 0x24, 0);
    if (gUiInputFlags & 1) {
        fn_80049D08(obj);
        return 0;
    }
    fn_800498A4(obj, fn_800C0658(), 0);
    fn_80013864();
    return 1;
}

s32 fn_8019ED74(void) {
    return 1;
}

/* Script command: select the map object at (x,y), or refresh links when free-input is on. */
s32 Map_SelectObjAt(s32 x, s32 y) {
    extern u32 gUiInputFlags;
    extern u8 gMapObjEventList[];
    s32 Map_Get(void);
    void *Map_FindObjAt(void *, s32, s32, u32, s32);
    s32 Map_CollectLinkedObjs(void *, void *, void *);
    void fn_80044450(s32, s32);
    void fn_800056A0(s8);
    void fn_80016180(void);
    void fn_80013864(void);
    s32 MapObj_IsVisible(void *);
    void MapObj_Show(void *, u8);
    s32 fn_800C0658(void);
    void MapObjEvent_Remove(void *, s32, s32, u8);
    void fn_80129888(void *, s32);
    void *obj;
    s32 linked[10];
    s32 count;
    s32 i;
    s32 entry;
    s32 *p;
    u8 *sel;

    if (gUiInputFlags & 1) {
        obj = Map_FindObjAt((void *) Map_Get(), x, y, 0x800, 0x10);
        if (obj == NULL) {
            fn_800056A0(0);
        } else {
            MapObjEvent_Remove(gMapObjEventList, (s8) x, (s8) y, 0x22);
            count = Map_CollectLinkedObjs((void *) Map_Get(), obj, linked);
            p = linked;
            i = 0;
            while (i < count) {
                entry = *p;
                if ((u8) MapObj_IsVisible((void *) entry) == 0) {
                    MapObj_Show((void *) entry, 0);
                }
                p++;
                i++;
            }
            fn_80044450(Map_Get(), 1);
            fn_80016180();
        }
        return 0;
    }
    sel = (u8 *) Map_FindObjAt((void *) Map_Get(), x, y, 0x800, 0x10);
    if (sel == NULL) {
        fn_800056A0(0);
        return 0;
    }
    fn_80129888(sel, fn_800C0658());
    MapObjEvent_Remove(gMapObjEventList, (s8) sel[0], (s8) sel[1], 0x22);
    fn_80013864();
    return 1;
}

s32 fn_8019EEE0(s32 x, s32 y) {
    extern u32 gUiInputFlags;
    extern u8 gMapObjEventList[];
    s32 Map_Get(void);
    void *Map_FindObjAt(void *, s32, s32, u32, s32);
    s32 Map_CollectLinkedObjs(void *, void *, void *);
    void fn_80044450(s32, s32);
    void fn_800056A0(s8);
    void fn_80016180(void);
    void fn_80013864(void);
    s32 MapObj_IsHidden(void *);
    void MapObj_Hide(void *, u8);
    s32 fn_800C0658(void);
    void MapObjEvent_Push(void *, s32, s32, u8, s32);
    void fn_80129A84(void *, s32);
    void *obj;
    s32 linked[10];
    s32 count;
    s32 i;
    s32 entry;
    s32 *p;
    u8 *sel;

    if (gUiInputFlags & 1) {
        obj = Map_FindObjAt((void *) Map_Get(), x, y, 0x800, 0x10);
        if (obj == NULL) {
            fn_800056A0(0);
        } else {
            MapObjEvent_Push(gMapObjEventList, (s8) x, (s8) y, 0x22, 0);
            count = Map_CollectLinkedObjs((void *) Map_Get(), obj, linked);
            p = linked;
            i = 0;
            while (i < count) {
                entry = *p;
                if ((u8) MapObj_IsHidden((void *) entry) == 0) {
                    MapObj_Hide((void *) entry, 0);
                }
                p++;
                i++;
            }
            fn_80044450(Map_Get(), 1);
            fn_80016180();
        }
        return 0;
    }
    sel = (u8 *) Map_FindObjAt((void *) Map_Get(), x, y, 0x800, 0x10);
    if (sel == NULL) {
        fn_800056A0(0);
        return 0;
    }
    fn_80129A84(sel, fn_800C0658());
    MapObjEvent_Push(gMapObjEventList, (s8) sel[0], (s8) sel[1], 0x22, 0);
    fn_80013864();
    return 1;
}

s32 Map_ShowLinkedAt(s32 x, s32 y) {
    extern u8 gMapObjEventList[];
    s32 Map_Get(void);
    void *Map_FindObjAt(void *, s32, s32, u32, s32);
    s32 Map_CollectLinkedObjs(void *, void *, void *);
    void fn_80044450(s32, s32);
    void fn_800056A0(s8);
    void fn_80016180(void);
    s32 MapObj_IsVisible(void *);
    void MapObj_Show(void *, u8);
    void MapObjEvent_Remove(void *, s32, s32, u8);
    s32 linked[10];
    s32 count;
    s32 i;
    s32 entry;
    s32 *p;

    /* Show linked map objects at (x,y) and clear event 0x22; fail if none. */
    {
        void *obj = Map_FindObjAt((void *)Map_Get(), x, y, 0x800, 0x10);
        if (obj == NULL) {
            fn_800056A0(0);
            return 0;
        }
        MapObjEvent_Remove(gMapObjEventList, (s8)x, (s8)y, 0x22);
        count = Map_CollectLinkedObjs((void *)Map_Get(), obj, linked);
    }
    p = linked;
    i = 0;
    while (i < count) {
        entry = *p;
        if ((u8)MapObj_IsVisible((void *)entry) == 0) {
            MapObj_Show((void *)entry, 0);
        }
        p++;
        i++;
    }
    fn_80044450(Map_Get(), 1);
    fn_80016180();
    return 1;
}

/* Script command: hide the map object at (x,y) and its linked group; queue event 0x22. */
s32 Map_HideLinkedAt(s32 x, s32 y) {
    extern u8 gMapObjEventList[];
    s32 Map_Get(void);
    void *Map_FindObjAt(void *, s32, s32, u32, s32);
    s32 Map_CollectLinkedObjs(void *, void *, void *);
    void fn_80044450(s32, s32);
    void fn_800056A0(s8);
    void fn_80016180(void);
    s32 MapObj_IsHidden(void *);
    void MapObj_Hide(void *, u8);
    void MapObjEvent_Push(void *, s32, s32, u8, s32);
    s32 linked[10];
    s32 count;
    s32 i;
    s32 entry;
    s32 *p;

    {
        void *obj = Map_FindObjAt((void *)Map_Get(), x, y, 0x800, 0x10);
        if (obj == NULL) {
            fn_800056A0(0);
            return 0;
        }
        MapObjEvent_Push(gMapObjEventList, (s8)x, (s8)y, 0x22, 0);
        count = Map_CollectLinkedObjs((void *)Map_Get(), obj, linked);
    }
    p = linked;
    i = 0;
    while (i < count) {
        entry = *p;
        if ((u8)MapObj_IsHidden((void *)entry) == 0) {
            MapObj_Hide((void *)entry, 0);
        }
        p++;
        i++;
    }
    fn_80044450(Map_Get(), 1);
    fn_80016180();
    return 1;
}

s32 fn_8019F230(s32 arg0, s32 arg1) {
    s32 Map_Get(void);
    void *Map_FindObjAt(void *, s32, s32, s32, s32);
    void fn_800056A0(s32);
    void fn_8012942C(void *, s32);
    s32 fn_800C0658(void);
    void MapObjEvent_Push(void *, s32, s32, s32, s32);
    void fn_80013864(void);
    extern u8 gMapObjEventList[];

    void *temp_r3;

    temp_r3 = Map_FindObjAt((void *) Map_Get(), arg0, arg1, 0x200, 0x410);
    if (temp_r3 == NULL) {
        fn_800056A0(0);
        return 0;
    }
    fn_8012942C(temp_r3, fn_800C0658());
    MapObjEvent_Push(gMapObjEventList, (s8) arg0, (s8) arg1, 0x23, 0);
    fn_80013864();
    return 1;
}

s32 fn_8019F2D0(s32 x, s32 y)
{
  extern u32 gUiInputFlags;
  s32 Map_Get(void);
  void *Map_FindObjAt(void *, s32, s32, u32, s32);
  void fn_800056A0(s32);
  void MapObjEvent_Remove(void *, s32, s32, s32);
  void *MapObjEvent_Find(void *, s32, s32, s32);

  void MapObj_FadeIn(void *, s32);
  void *Map_FindObjNear(void *, s32, s32, u32, s32);
  s32 Map_CollectLinkedObjs(void *, void *, s32 *);
  u8 MapObj_IsVisible(void *);
  void MapObj_Show(void *, s32);
  void fn_80044450(s32, s32);
  void fn_80016180(void);
  void fn_80013864(void);
  s32 fn_800C0658(void);
  void fn_80129588(void *, s32);
  extern u8 gMapObjEventList[];
  s32 count;
  s32 i;
  s32 v;
  s32 *p;
  s32 linked[10];
  if (gUiInputFlags & 1)
  {
    {
      void *obj = Map_FindObjAt((void *) Map_Get(), x, y, 0x1000, 0x10);
      if (obj == NULL)
      {
        fn_800056A0(0);
      }
      else
      {
        MapObjEvent_Remove(gMapObjEventList, (s8) x, (s8) y, 0x21);
        {
          void *ev = MapObjEvent_Find(gMapObjEventList, (char) x, (char) y, 4);
          if (ev != NULL)
          {
            ((u8 *) ev)[4] = ((u8 *) ev)[5];
          }
        }
        MapObj_FadeIn(obj, 0);
        obj = Map_FindObjNear((void *) Map_Get(), x, y, 0x800, 0);
        if (obj != NULL)
        {
          count = Map_CollectLinkedObjs((void *) Map_Get(), obj, linked);
          p = linked;
          i = 0;
          while (i < count)
          {
            v = *p;
            if (((u8) MapObj_IsVisible((void *) v)) == 0)
            {
              MapObj_Show((void *) v, 0);
            }
            p++;
            i++;
          }

        }
      }
    }
    fn_80044450(Map_Get(), 1);
    fn_80016180();
    return 0;
  }
  {
    void *obj = Map_FindObjAt((void *) Map_Get(), x, y, 0x1000, 0x10);
    if (obj == NULL)
    {
      fn_800056A0(0);
      return 0;
    }
    MapObjEvent_Remove(gMapObjEventList, (s8) x, (s8) y, 0x21);
    {
      void *ev = MapObjEvent_Find(gMapObjEventList, (char) x, (char) y, 4);
      if (ev != NULL)
      {
        ((u8 *) ev)[4] = ((u8 *) ev)[5];
      }
    }
    fn_80129588(obj, fn_800C0658());
  }
  fn_80013864();
  return 1;
}

#pragma use_lmw_stmw off
s32 fn_8019F4A8(s32 x, s32 y) {
    s32 Map_Get(void);
    void *Map_FindObjAt(void *, s32, s32, u32, s32);
    void fn_800056A0(s32);
    void MapObjEvent_Push(void *, s32, s32, s32, s32);
    void *MapObjEvent_Find(void *, s32, s32, s32);
    void MapObj_FadeOut(void *, s32);
    void *Map_FindObjNear(void *, s32, s32, u32, s32);
    s32 Map_CollectLinkedObjs(void *, void *, s32 *);
    u8 MapObj_IsHidden(void *);
    void MapObj_Hide(void *, s32);
    void fn_80044450(s32, s32);
    void fn_80016180(void);
    void *fn_800C0658(void);
    void fn_80129708(void *, void *);
    void fn_80013864(void);
    extern u8 gMapObjEventList[];
    extern u32 gUiInputFlags;
    s32 count;
    s32 i;
    s32 v;
    s32 *p;
    s32 linked[10];

    if (gUiInputFlags & 1) {
        {
            void *obj = Map_FindObjAt((void *)Map_Get(), x, y, 0x1000, 0x10);
            if (obj == NULL) {
                fn_800056A0(0);
            } else {
                MapObjEvent_Push(gMapObjEventList, (s8)x, (s8)y, 0x21, 0);
                {
                    void *ev = MapObjEvent_Find(gMapObjEventList, (char)x, (char)y, 4);
                    if (ev != NULL) {
                        ((u8 *)ev)[4] = 0;
                    }
                }
                MapObj_FadeOut(obj, 0);
                {
                    void *obj = Map_FindObjNear((void *)Map_Get(), x, y, 0x800, 0);
                    if (obj != NULL) {
                        count = Map_CollectLinkedObjs((void *)Map_Get(), obj, linked);
                        p = linked;
                        i = 0;
                        while (i < count) {
                            v = *p;
                            if ((u8)MapObj_IsHidden((void *)v) == 0) {
                                MapObj_Hide((void *)v, 0);
                            }
                            p++;
                            i++;
                        }
                    }
                }
            }
        }
        fn_80044450(Map_Get(), 1);
        fn_80016180();
        return 0;
    }

    {
        void *obj = Map_FindObjAt((void *)Map_Get(), x, y, 0x1000, 0x10);
        if (obj == NULL) {
            fn_800056A0(0);
            return 0;
        }
        MapObjEvent_Push(gMapObjEventList, (s8)x, (s8)y, 0x21, 0);
        {
            void *ev = MapObjEvent_Find(gMapObjEventList, (char)x, (char)y, 4);
            if (ev != NULL) {
                ((u8 *)ev)[4] = 0;
            }
        }
        fn_80129708(obj, fn_800C0658());
        fn_80013864();
        return 1;
    }
}
#pragma use_lmw_stmw reset
/* Show the 0x1000 map object at (x,y), clear its event, and show linked 0x800 objects. */
s32 Map_ShowObjAt(s32 x, s32 y) {
    s32 Map_Get(void);
    void *Map_FindObjAt(void *, s32, s32, u32, s32);
    void fn_800056A0(s32);
    void MapObjEvent_Remove(void *, s32, s32, s32);
    void *MapObjEvent_Find(void *, s32, s32, s32);
    void MapObj_FadeIn(void *, s32);
    void *Map_FindObjNear(void *, s32, s32, u32, s32);
    s32 Map_CollectLinkedObjs(void *, void *, s32 *);
    u8 MapObj_IsVisible(void *);
    void MapObj_Show(void *, s32);
    void fn_80044450(s32, s32);
    void fn_80016180(void);
    extern u8 gMapObjEventList[];
    s32 count;
    s32 i;
    s32 v;
    s32 *p;
    s32 linked[10];

    {
        void *obj = Map_FindObjAt((void *)Map_Get(), x, y, 0x1000, 0x10);
        if (obj == NULL) {
            fn_800056A0(0);
            return 0;
        }
        MapObjEvent_Remove(gMapObjEventList, (s8)x, (s8)y, 0x21);
        {
            void *ev = MapObjEvent_Find(gMapObjEventList, (char)x, (char)y, 4);
            if (ev != NULL) {
                ((u8 *)ev)[4] = ((u8 *)ev)[5];
            }
        }
        MapObj_FadeIn(obj, 0);
    }
    {
        void *obj = Map_FindObjNear((void *)Map_Get(), x, y, 0x800, 0);
        if (obj != NULL) {
            count = Map_CollectLinkedObjs((void *)Map_Get(), obj, linked);
            p = linked;
            i = 0;
            while (i < count) {
                v = *p;
                if ((u8)MapObj_IsVisible((void *)v) == 0) {
                    MapObj_Show((void *)v, 0);
                }
                p++;
                i++;
            }
        }
    }
    fn_80044450(Map_Get(), 1);
    fn_80016180();
    return 1;
}
#pragma use_lmw_stmw on
/* Hide the 0x1000 map object at (x,y), queue its event, and hide linked 0x800 objects. */
s32 Map_HideObjAt(s32 x, s32 y) {
    s32 Map_Get(void);
    void *Map_FindObjAt(void *, s32, s32, u32, s32);
    void fn_800056A0(s32);
    void MapObjEvent_Push(void *, s32, s32, s32, s32);
    void *MapObjEvent_Find(void *, s32, s32, s32);
    void MapObj_FadeOut(void *, s32);
    void *Map_FindObjNear(void *, s32, s32, u32, s32);
    s32 Map_CollectLinkedObjs(void *, void *, s32 *);
    u8 MapObj_IsHidden(void *);
    void MapObj_Hide(void *, s32);
    void fn_80044450(s32, s32);
    void fn_80016180(void);
    extern u8 gMapObjEventList[];
    s32 count;
    s32 i;
    s32 v;
    s32 *p;
    s32 linked[10];

    {
        void *obj = Map_FindObjAt((void *)Map_Get(), x, y, 0x1000, 0x10);
        if (obj == NULL) {
            fn_800056A0(0);
            return 0;
        }
        MapObjEvent_Push(gMapObjEventList, (s8)x, (s8)y, 0x21, 0);
        {
            void *ev = MapObjEvent_Find(gMapObjEventList, (char)x, (char)y, 4);
            if (ev != NULL) {
                ((u8 *)ev)[4] = 0;
            }
        }
        MapObj_FadeOut(obj, 0);
    }
    {
        void *obj = Map_FindObjNear((void *)Map_Get(), x, y, 0x800, 0);
        if (obj != NULL) {
            count = Map_CollectLinkedObjs((void *)Map_Get(), obj, linked);
            p = linked;
            i = 0;
            while (i < count) {
                v = *p;
                if ((u8)MapObj_IsHidden((void *)v) == 0) {
                    MapObj_Hide((void *)v, 0);
                }
                p++;
                i++;
            }
        }
    }
    fn_80044450(Map_Get(), 1);
    fn_80016180();
    return 1;
}
s32 fn_8019F914(s32 arg0, s32 arg1) {
    s32 Map_Get(void);
    void *Map_FindObjAt(s32, s32, s32, s32, s32);
    void MapObjEvent_Push(void *, s32, s32, s32, s32);
    void fn_80049C8C(void *, s32);
    void fn_80044450(s32, s32);
    void fn_80016180(void);
    extern u8 gMapObjEventList[];
    void *temp;

    temp = Map_FindObjAt(Map_Get(), arg0, arg1, 0x80000, 0x10);
    if (temp == NULL) {
        return 0;
    }
    MapObjEvent_Push(gMapObjEventList, (s8)arg0, (s8)arg1, 0x29, 0);
    fn_80049C8C(temp, 0);
    fn_80044450(Map_Get(), 1);
    fn_80016180();
    return 1;
}

s32 fn_8019F9B4(s32 arg0, s32 arg1) {
    s32 Map_Get(void);
    void *Map_FindObjAt(s32, s32, s32, s32, s32);
    void MapObjEvent_Remove(void *, s32, s32, s32);
    void fn_80049C8C(void *, s32);
    void fn_80044450(s32, s32);
    void fn_80016180(void);
    extern u8 gMapObjEventList[];
    void *temp;

    temp = Map_FindObjAt(Map_Get(), arg0, arg1, 0x80000, 0x10);
    if (temp == NULL) {
        return 0;
    }
    MapObjEvent_Remove(gMapObjEventList, (s8)arg0, (s8)arg1, 0x29);
    fn_80049C8C(temp, 1);
    fn_80044450(Map_Get(), 1);
    fn_80016180();
    return 1;
}

s32 fn_8019FA50(s32 x,s32 y,s32 mode) {
void *Map_Get(void);
void *Map_FindObjAt(void *,s32,s32,s32,s32);
void MapObjEvent_Push(void *,s8,s8,s32,s32);
void MapObjEvent_Remove(void *,s8,s8,s32);
void *Process_Find(void *); void *Process_Create(void *,void *);
void *fn_80127C48(void); void *fn_800C0658(void);
void fn_800498A4(void *,void *,u8);
extern u8 gMapObjEventList[],Proc_MuEventInst[];
extern s32 gUiInputFlags;
void *obj;
void *proc;
void *found;
obj=Map_FindObjAt(Map_Get(),x,y,0x200,0x410);
if(!obj) return 0;
switch(mode) {
case 2: break;
case 0: case 4: MapObjEvent_Push(gMapObjEventList,x,y,0x28,0); break;
case 1: case 3: MapObjEvent_Remove(gMapObjEventList,x,y,0x28); break;
}
switch(mode) {
case 0: if(gUiInputFlags&1) mode=4; break;
case 1: if(gUiInputFlags&1) mode=3; break;
case 2: if(gUiInputFlags&1) return 0; break;
}
switch(mode) {
case 0: case 1: case 2:
found=Process_Find(Proc_MuEventInst);
if(found) { proc=found; } else { proc=fn_80127C48(); if(!proc) proc=fn_800C0658(); proc=Process_Create(Proc_MuEventInst,proc); }
fn_800498A4(obj,proc,(u8)mode); break;
case 3: case 4: fn_800498A4(obj,0,(u8)mode); break;
}
return 1;
}

s32 fn_8019FC08(void) {
    u8 fn_8001772C(void);
    M2C_UNK Process_CreateChild(void *, s32);
    M2C_UNK fn_80013864(void);
    extern u8 lbl_80297010[];
    if (fn_8001772C() != 0) {
        Process_CreateChild(lbl_80297010, fn_800C0658());
        fn_80013864();
    }
    return 1;
}

void fn_8019FC4C(s32 arg0) {
    M2C_UNK Process_ClearFunc(s32);
    u8 fn_8001772C();
    if (fn_8001772C() == 0) {
        Process_ClearFunc(arg0);
    }
}

s32 fn_8019FC88(void) {
    M2C_UNK fn_80017774();
    fn_80017774();
    return 1;
}

s32 fn_8019FCAC(void) {
    M2C_UNK fn_8001779C();
    fn_8001779C();
    return 1;
}

s32 fn_8019FCD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_UNK CamPath_AddPoint(M2C_UNK, s32, f32, f32, f32);
    CamPath_AddPoint(1, arg0, (f32) arg1, (f32) arg2, (f32) arg3);
    return 1;
}

s32 ScriptCmd_CamPathAddScaled(s32 id, s32 x, s32 y, s32 z) {
    /* Add a CamPath point; divide map coords by E_EventState scale and center by +0.5. */
    void *Process_Find(void *);
    void CamPath_AddPoint(s32, s32, f32, f32, f32);
    extern u8 E_EventState_script[];
    void *state;
    s32 scale;
    f32 fscale;

    state = Process_Find(E_EventState_script);
    if (state != NULL) {
        scale = *(s32 *)((u8 *)state + 0x3C);
    } else {
        scale = 1;
    }
    fscale = (f32)scale;
    CamPath_AddPoint(0, id,
                0.5f + (f32)x / fscale,
                0.5f + (f32)y / fscale,
                (f32)z / fscale);
    return 1;
}

s32 fn_8019FE2C(void) {
    M2C_UNK fn_800C0658();
    M2C_UNK fn_800177E0();
    fn_800C0658();
    fn_800177E0();
    return 1;
}

s32 fn_8019FE54(void) {
    void *Camera_GetActive(void);
    void fn_800193CC(void *, f32);
    extern u8 lbl_80330E90[];
    void *p;
    f32 f;

    if (lbl_80330E90[0] != 0) {
        p = Camera_GetActive();
        if (p != NULL) {
            f = *(f32 *)(lbl_80330E90 + 4);
            *(f32 *)((u8 *)p + 4) = f;
            *(f32 *)((u8 *)p + 0x10) = f;
            f = *(f32 *)(lbl_80330E90 + 8);
            *(f32 *)((u8 *)p + 8) = f;
            *(f32 *)((u8 *)p + 0x14) = f;
            fn_800193CC(p, *(f32 *)(lbl_80330E90 + 0xC));
        }
    }
    return 1;
}

s32 fn_8019FEB8(void) {
    void *Camera_GetActive(void);
    void fn_800193CC(void *, f32);
    extern u32 gUiInputFlags;
    extern u8 lbl_80330E90[];
    void *p;
    f32 f;

    if (gUiInputFlags & 1) {
        if (lbl_80330E90[0] != 0) {
            p = Camera_GetActive();
            if (p != NULL) {
                f = *(f32 *)(lbl_80330E90 + 4);
                *(f32 *)((u8 *)p + 4) = f;
                *(f32 *)((u8 *)p + 0x10) = f;
                f = *(f32 *)(lbl_80330E90 + 8);
                *(f32 *)((u8 *)p + 8) = f;
                *(f32 *)((u8 *)p + 0x14) = f;
                fn_800193CC(p, *(f32 *)(lbl_80330E90 + 0xC));
            }
        }
    } else {
        if (lbl_80330E90[0] != 0) {
            p = Camera_GetActive();
            if (p != NULL) {
                *(f32 *)((u8 *)p + 4) = *(f32 *)(lbl_80330E90 + 4);
                *(f32 *)((u8 *)p + 8) = *(f32 *)(lbl_80330E90 + 8);
                *(f32 *)((u8 *)p + 0xC) = *(f32 *)(lbl_80330E90 + 0xC);
            }
        }
    }
    return 1;
}

s32 fn_8019FF68(void) {
    void *Camera_GetActive(void);
    extern u8 lbl_80330E90[];
    u8 *p = Camera_GetActive();

    if (p != NULL) {
        *(f32 *)(lbl_80330E90 + 4) = *(f32 *)(p + 4);
        *(f32 *)(lbl_80330E90 + 8) = *(f32 *)(p + 8);
        *(f32 *)(lbl_80330E90 + 0xc) = *(f32 *)(p + 0xc);
        lbl_80330E90[0] = 1;
    }
    return 1;
}

#pragma optimization_level 3
s32 fn_8019FFBC(s32 arg0, s32 arg1, s32 arg2) {
    void *Camera_GetActive(void);
    void fn_800193CC(void *, f32);
    void Camera_SyncFromBattleState(void);
    void *p;

    p = Camera_GetActive();
    *(f32 *)((char *)p + 0x10) = *(f32 *)((char *)p + 4) = (f32)arg0;
    *(f32 *)((char *)p + 0x14) = *(f32 *)((char *)p + 8) = (f32)arg1;
    fn_800193CC(p, (f32)arg2);
    Camera_SyncFromBattleState();
    return 1;
}
#pragma optimization_level reset
s32 fn_801A0060(s32 arg0, s32 arg1, s32 arg2) {
    void *Camera_GetActive(void);
    void *obj;
    f32 scale;

    obj = Camera_GetActive();
    scale = 2.0f;
    *(f32 *)((u8 *)obj + 4) = (f32)arg0;
    *(f32 *)((u8 *)obj + 8) = (f32)arg1;
    *(f32 *)((u8 *)obj + 0xC) = (f32)arg2;
    *(f32 *)((u8 *)obj + 0x70) = scale;
    return 1;
}

int fn_801A0100(u8 arg0, u8 arg1, u8 arg2) {
    extern u32 lbl_8036AF6C;
    extern u8 lbl_80367298[4];
    u32 value;
    u32 copy;
    value = lbl_8036AF6C;
    ((u8 *)&value)[0] = arg0;
    ((u8 *)&value)[1] = arg1;
    ((u8 *)&value)[2] = arg2;
    copy = value;
    lbl_80367298[0] = ((u8 *)&copy)[0];
    lbl_80367298[1] = ((u8 *)&copy)[1];
    lbl_80367298[2] = ((u8 *)&copy)[2];
    lbl_80367298[3] = ((u8 *)&copy)[3];
    Map_Get();
    fn_80045C68();
    fn_80013864();
    return 1;
}

int fn_801A016C(u8 arg0, u8 arg1, u8 arg2) {
    extern u32 lbl_8036AF68;
    extern u8 lbl_8036729C[4];
    u32 value;
    u32 copy;
    value = lbl_8036AF68;
    ((u8 *)&value)[0] = arg0;
    ((u8 *)&value)[1] = arg1;
    ((u8 *)&value)[2] = arg2;
    copy = value;
    lbl_8036729C[0] = ((u8 *)&copy)[0];
    lbl_8036729C[1] = ((u8 *)&copy)[1];
    lbl_8036729C[2] = ((u8 *)&copy)[2];
    lbl_8036729C[3] = ((u8 *)&copy)[3];
    Map_Get();
    fn_80045C68();
    fn_80013864();
    return 1;
}

s32 fn_801A01D8(s8 arg0) {
    M2C_UNK fn_80013864();
    M2C_UNK Map_Get();
    M2C_UNK fn_80040DA4();
    extern s8 gBattleSkyIndex;
    gBattleSkyIndex = arg0;
    Map_Get();
    fn_80040DA4();
    fn_80013864();
    return 1;
}

s32 fn_801A0208(s32 arg0, s32 arg1, s32 arg2, u8 arg3, u8 arg4, u8 arg5)
{
    extern u32 lbl_8036AF64;
    void fn_80048A3C(s32, s32, s32, u32 *);
    void Map_Get(void);
    void fn_80045B9C(void);
    void fn_80013864(void);

    u32 copy;
    u32 value;

    value = lbl_8036AF64;
    ((u8 *)&value)[0] = arg3;
    ((u8 *)&value)[1] = arg4;
    ((u8 *)&value)[2] = arg5;
    copy = value;
    fn_80048A3C(arg0, arg1, arg2, &copy);
    Map_Get();
    fn_80045B9C();
    fn_80013864();
    return 1;
}

s32 fn_801A0258(void) {
    void fn_80048A70(void);
    void Map_RefreshUnitMap(void *);
    void Map_Get(void);
    void fn_80040DA4(void);
    void fn_80016180(void);
    void fn_80013864(void);
    extern u8 gBattleMap[];

    fn_80048A70();
    Map_RefreshUnitMap(gBattleMap);
    Map_Get();
    fn_80040DA4();
    fn_80016180();
    fn_80013864();
    return 1;
}

/* Ensure E_EventState exists; enable or disable map tile-flag overlay. */
s32 ScriptCmd_EventMapFlags(s32 enable) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    s32 fn_800C0658();
    s32 Map_Get(void);
    void Map_ReloadTileFlags(s32, u8);
    extern u16 E_EventState_script[];
    extern u8 gBattleState[];
    extern s32 gUiInputFlags;

    void *p;
    void *state;

    p = Process_Find(E_EventState_script);
    if (p != NULL) {
        state = p;
    } else {
        p = Process_Create(E_EventState_script, fn_800C0658());
        ((u8 *)p)[0x30] = 1;
        ((u8 *)p)[0x31] = 0;
        ((u8 *)p)[0x32] = 0;
        ((u16 *)((u8 *)p + 0x34))[0] = 0;
        ((u8 *)p)[0x33] = gBattleState[0xA0];
        ((u8 *)p)[0x36] = 1;
        ((u32 *)((u8 *)p + 0x3C))[0] = 1;
        ((u8 *)p)[0x37] = 0;
        ((u8 *)p)[0x38] = 0;
        state = p;
    }
    if (enable != 0) {
        ((u8 *)state)[0x36] = 1;
        gUiInputFlags &= 0xFFFFEFFF;
        Map_ReloadTileFlags(Map_Get(), 1);
    } else {
        ((u8 *)state)[0x36] = 0;
        gUiInputFlags |= 0x1000;
        Map_ReloadTileFlags(Map_Get(), 0);
    }
    return 1;
}

s32 fn_801A0374(void) {
    extern u8 gBattleState[];
    void BattleState_LoadMap(void *, s32);
    void fn_8014C798(void *);
    void BattleState_SetCamPos(void *, f32, f32);
    void Camera_SyncFromBattleState(void);

    BattleState_LoadMap(gBattleState, 0);
    fn_8014C798(gBattleState);
    BattleState_SetCamPos(gBattleState, (f32) (s8) gBattleState[0x52], (f32) (s8) gBattleState[0x53]);
    Camera_SyncFromBattleState();
    return 1;
}

extern u16 gBattleState[];
s32 fn_801A0400(s32 arg0) {
    void BattleState_LoadMap(void *, s32);
    void fn_80013864(void);
    extern u16 gBattleState[];
    BattleState_LoadMap(gBattleState, arg0);
    fn_80013864();
    return 1;
}

s32 fn_801A0434(u8 arg0,u8 arg1) {
extern u8 gUnits[],Proc_MuEventInst[];
extern u32 gUiInputFlags;
u8 Status_Test(void *,s32);
void Unit_ApplyTransform(void *);
void fn_8004E9D8(void *,s32);
void fn_80050C90(void *);
void *Process_Find(void *);
void *Process_Create(void *,void *);
void *fn_80127C48(void);
void *fn_800C0658(void);
void fn_801A06CC(void);
void *fn_800590D8(void (*)(void),void *,s32,void *);
void *fn_80183B5C(void *,void *);
u8 *unit;
void *proc;
void *parent;
void *found;
void *event;
if(gUiInputFlags&1) {
if(arg0) unit=gUnits+(arg0-1)*0x280; else unit=0;
if(unit && *(u32 *)(unit+0x188) && (!arg1 || !Status_Test(unit+0x1bc,9)) && (arg1 || Status_Test(unit+0x1bc,9))) {
Unit_ApplyTransform(unit); fn_8004E9D8(unit,0); fn_80050C90(unit);
}
return 0;
}
if(arg0) unit=gUnits+(arg0-1)*0x280; else unit=0;
if(!unit || !*(u32 *)(unit+0x188)) return 0;
if(arg1 && Status_Test(unit+0x1bc,9)) return 0;
if(!arg1 && !Status_Test(unit+0x1bc,9)) return 0;
found=Process_Find(Proc_MuEventInst);
if(found) {proc=found;} else {
parent=fn_80127C48();
if(!parent) parent=fn_800C0658();
proc=Process_Create(Proc_MuEventInst,parent);
}
event=fn_800590D8(fn_801A06CC,unit,1,proc);
fn_80183B5C(unit,event);
return 1;
}

s32 ScriptCmd_UnitTransform(u8 unitId, u8 wantTransformed) {
    /* Immediately transform or untransform unitId to match wantTransformed (status 9). */
    void Unit_ApplyTransform(void *);
    void fn_8004E9D8(void *, s32);
    void fn_80050C90(void *);
    u8 Status_Test(void *, s32);
    extern u8 gUnits[];
    void *unit;

    if (unitId != 0) {
        unit = gUnits + (unitId - 1) * 0x280;
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    if (wantTransformed != 0 && Status_Test((u8 *)unit + 0x1BC, 9) != 0) {
        return 0;
    }
    if (wantTransformed == 0 && Status_Test((u8 *)unit + 0x1BC, 9) == 0) {
        return 0;
    }
    Unit_ApplyTransform(unit);
    fn_8004E9D8(unit, 0);
    fn_80050C90(unit);
    return 1;
}

void fn_801A06CC(void) {
    M2C_UNK Unit_ApplyTransform();
    Unit_ApplyTransform();
}

#pragma optimization_level 3
s32 fn_801A06EC(u8 arg0, u8 arg1, s32 arg2) {
    extern u8 gUnits[];
    extern u32 gUiInputFlags;
    extern u8 Proc_MuEventInst[];
    void *Process_Find(u8 *);
    void *Process_Create(u8 *, s32);
    void Unit_SetMapPos(void *, s8, s8);
    void fn_80050C90(void *);
    u32 fn_80127C48(void);
    s32 fn_800C0658(void);
    void fn_80183EAC(void *, void *, s32, s32, void *);
    u8 *unit1;
    u8 *unit2;
    s32 var_r29;
    s32 var_r28;
    s32 temp;
    void *host;
    void *parent;
    u32 tmp;

    if (arg0 != 0) {
        unit1 = gUnits + ((arg0 - 1) * 0x280);
    } else {
        unit1 = NULL;
    }
    if (arg1 != 0) {
        unit2 = gUnits + ((arg1 - 1) * 0x280);
    } else {
        unit2 = NULL;
    }
    if (unit1 == NULL || *(u32 *)(unit1 + 0x188) == 0) {
        return 0;
    }
    if (unit2 == NULL || *(u32 *)(unit2 + 0x188) == 0) {
        return 0;
    }

    var_r29 = *(s8 *)(unit2 + 0x19E);
    temp = *(s8 *)(unit1 + 0x19E);
    var_r28 = *(s8 *)(unit2 + 0x19F);
    if (var_r29 > temp) {
        var_r29 = var_r29 + arg2;
    }
    if (var_r29 < temp) {
        var_r29 = var_r29 - arg2;
    }
    temp = *(s8 *)(unit1 + 0x19F);
    if (var_r28 > temp) {
        var_r28 = var_r28 + arg2;
    }
    if (var_r28 < temp) {
        var_r28 = var_r28 - arg2;
    }

    Unit_SetMapPos(unit2, (s8)var_r29, (s8)var_r28);

    if (gUiInputFlags & 1) {
        fn_80050C90(unit2);
        return 0;
    }

    host = Process_Find(Proc_MuEventInst);
    if (host != NULL) {
        parent = host;
    } else {
        tmp = fn_80127C48();
        if (tmp == 0) {
            tmp = fn_800C0658();
        }
        parent = Process_Create(Proc_MuEventInst, tmp);
    }
    fn_80183EAC(unit1, unit2, var_r29, var_r28, parent);
    return 1;
}
#pragma optimization_level reset
/* Start MU event kind 4 for the unit at the given deployment index. */
s32 MuEvent_StartForUnit(u8 unitId) {
    extern u32 gUiInputFlags;
    extern u8 gUnits[];
    extern u8 Proc_MuEventInst[];
    void *Process_Find(u8 *);
    void *Process_Create(u8 *, s32);
    u32 fn_80127C48(void);
    s32 fn_800C0658(void);
    void MuEvent_Create(void *, s32, s32, s32, void *);
    void *unit;
    void *host;
    void *parent;
    u32 tmp;

    if (gUiInputFlags & 1) {
        return 0;
    }
    if (unitId != 0) {
        unit = gUnits + ((unitId - 1) * 0x280);
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    host = Process_Find(Proc_MuEventInst);
    if (host != NULL) {
        parent = host;
    } else {
        tmp = fn_80127C48();
        if (tmp == 0) {
            tmp = fn_800C0658();
        }
        parent = Process_Create(Proc_MuEventInst, tmp);
    }
    MuEvent_Create(unit, 4, -1, -1, parent);
    return 1;
}

s32 MuDead_StartForUnit(u8 unitId) {
    /* Start E__MuDead for the unit at the given deployment index. */
    extern u32 gUiInputFlags;
    extern u8 gUnits[];
    extern u8 Proc_MuEventInst[];
    void *Process_Find(u8 *);
    void *Process_Create(u8 *, s32);
    u32 fn_80127C48(void);
    s32 fn_800C0658(void);
    void MuDead_Start(void *, void *);
    void *unit;
    void *host;
    void *parent;
    u32 tmp;

    if (gUiInputFlags & 1) {
        return 0;
    }
    if (unitId != 0) {
        unit = gUnits + ((unitId - 1) * 0x280);
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        return 0;
    }
    host = Process_Find(Proc_MuEventInst);
    if (host != NULL) {
        parent = host;
    } else {
        tmp = fn_80127C48();
        if (tmp == 0) {
            tmp = fn_800C0658();
        }
        parent = Process_Create(Proc_MuEventInst, tmp);
    }
    MuDead_Start(unit, parent);
    return 1;
}

s32 fn_801A0A10(u8 arg0, s32 arg1) {
    extern u8 gUnits[];
    extern u8 lbl_80296FE0[];
    extern u8 Proc_MuEventInst[];
    extern u32 gUiInputFlags;

    void *GfxEnt_ForEachKey(void *, void *, void *);
    void fn_801A0C3C(void *, u32);
    void fn_8004FE98(void *, s32);
    void fn_8004BF24(void *);
    u32 Process_Find(void *);
    void *Process_Create(void *, s32);
    void *Process_CreateChild(void *, void *);
    u32 fn_80127C48(void);
    u32 fn_800C0658(void);

    u8 *unit;
    u32 parent;
    u8 *proc;
    u32 result;

    if (arg0 != 0) {
        unit = gUnits + ((arg0 - 1) * 0x280);
    } else {
        unit = 0;
    }

    if (unit == 0 || *(u32 *)(unit + 0x188) == 0) {
        result = 0;
        goto done;
    }

    GfxEnt_ForEachKey(lbl_80296FE0, fn_801A0C3C, unit);

    if (gUiInputFlags & 1) {
        fn_8004FE98(unit, arg1);
        fn_8004BF24(unit);
        result = 0;
        goto done;
    }

    parent = Process_Find(Proc_MuEventInst);
    parent = parent ? parent : (u32)Process_Create(Proc_MuEventInst,
        ((result = fn_80127C48()) || (result = fn_800C0658()), result));

    proc = Process_CreateChild(lbl_80296FE0, (void *)parent);

    *(void **)(proc + 0x54) = unit;
    *(s32 *)(proc + 0x60) = arg1;
    *(s32 *)(proc + 0x64) = 0x10;

    result = 1;
done:
    return result;
}

s32 fn_801A0B20(u8 unitId, s32 arg1, s32 arg2) {
    extern u32 gUiInputFlags;
    extern u8 gUnits[];
    extern u8 Proc_MuEventInst[];
    extern u8 lbl_80296FE0[];
    void *Process_Find(u8 *);
    void *Process_Create(u8 *, s32);
    void *Process_CreateChild(u8 *, void *);
    void GfxEnt_ForEachKey(void *, void *, void *);
    void fn_801A0C3C(void *, void *);
    u32 fn_80127C48(void);
    s32 fn_800C0658(void);
    void fn_8004FE98(void *, s32);
    void fn_8004BF24(void *);
    void *unit;
    void *host;
    u32 tmp;
    s32 result;

    if (unitId != 0) {
        unit = gUnits + ((unitId - 1) * 0x280);
    } else {
        unit = NULL;
    }
    if (unit == NULL || *(u32 *)((u8 *)unit + 0x188) == 0) {
        result = 0;
        goto done;
    }
    GfxEnt_ForEachKey(lbl_80296FE0, fn_801A0C3C, unit);
    if (!(gUiInputFlags & 1) && arg2 < 0) {
        fn_8004FE98(unit, arg1);
        fn_8004BF24(unit);
        result = 0;
        goto done;
    }
    host = Process_Find(Proc_MuEventInst);
    if (host != NULL) {
        goto stores;
    }
    tmp = fn_80127C48();
    if (tmp == 0) {
        tmp = fn_800C0658();
    }
    host = Process_Create(Proc_MuEventInst, tmp);
    host = Process_CreateChild(lbl_80296FE0, host);
stores:
    *(void **)((u8 *)host + 0x54) = unit;
    *(s32 *)((u8 *)host + 0x60) = arg1;
    *(s32 *)((u8 *)host + 0x64) = arg2;
    result = 1;
done:
    return result;
}

void fn_801A0C3C(void *arg0, u32 arg1) {
    M2C_UNK Process_Unlink();
    if ((u32) M2C_FIELD(arg0, u32 *, 0x54) == arg1) {
        Process_Unlink();
    }
}

void fn_801A0C68(void *arg0) {
    u8 Mu_IsAnimDone(s32);
    if (Mu_IsAnimDone(M2C_FIELD(arg0, s32 *, 0x54)) != 0) {
        Process_ClearFunc(arg0);
    }
}

void fn_801A0CA8(void *arg0) {
    u8 fn_8004FA88(s32, s32);
    s32 temp_r31;

    temp_r31 = M2C_FIELD(arg0, s32 *, 0x54);
    fn_8004FC70(temp_r31, M2C_FIELD(arg0, s32 *, 0x60));
    if (fn_8004FA88(temp_r31, M2C_FIELD(arg0, s32 *, 0x60)) != 0) {
        Mu_StartBlend(temp_r31, M2C_FIELD(arg0, s32 *, 0x60), M2C_FIELD(arg0, s32 *, 0x64), arg0);
        M2C_FIELD(arg0, s32 *, 0x60) = -1;
        Process_ClearFunc(arg0);
    }
}

void fn_801A0D20(void *arg0) {
    void fn_8004BF24(void *);
    void fn_8004FE98(void *, s32);
    void *temp_r31;
    s32 temp;

    temp = *(s32 *)((u8 *)arg0 + 0x60);
    temp_r31 = *(void **)((u8 *)arg0 + 0x54);
    if (temp >= 0) {
        fn_8004FE98(temp_r31, temp);
        fn_8004BF24(temp_r31);
    }
}

s32 fn_801A0D64(u8 arg0, s32 arg1, s32 arg2) {
    extern u16 gUnits[];
    extern u8 Proc_MuEventInst[];
    extern u32 gUiInputFlags;
    extern f32 lbl_8036AF74;
    extern f64 lbl_8036AF78;

    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    u32 fn_80127C48(void);
    s32 fn_800C0658(void);
    void *fn_80184750(void *, u32, s32, s32);

    u8 *unit;
    void *parent;
    void *found;
    s32 duration;
    u32 temp;

    if (arg0 != 0) {
        unit = (u8 *)gUnits + ((arg0 - 1) * 0x280);
    } else {
        unit = 0;
    }

    if (unit == 0 || *(u32 *)(unit + 0x188) == 0) {
        return 0;
    }

    if (gUiInputFlags & 1) {
        fn_80184750(unit, arg1, 0, 0);
    } else {
        found = Process_Find(Proc_MuEventInst);
        if (found != 0) {
            parent = found;
        } else {
            temp = fn_80127C48();
            if (temp == 0) {
                temp = fn_800C0658();
            }
            parent = Process_Create(Proc_MuEventInst, temp);
        }
        duration = (s32)((f32)arg2 / lbl_8036AF74);
        fn_80184750(unit, arg1, duration, (s32)parent);
    }

    return 1;
}

/* Script command: warp unit unitId to (x, y) instantly and ensure MuEventInst is running. */
s32 ScriptCmd_UnitWarp(u8 unitId, u8 x, u8 y) {
    extern u8 gUnits[];
    extern u8 gBattleMap[];
    extern u8 Proc_MuEventInst[36];
    void *Process_Find(u8 *);
    void *Process_Create(u8 *, s32);
    s32 Unit_SetMapPos(void *, u8, u8);
    s32 fn_80050C90(void *);
    s32 Unit_ResolveWarpPos(void *, u8 *, u8 *, s32, s32, s32);
    s32 Map_RefreshUnitMap(u8 *);
    u32 fn_80127C48(void);
    s32 fn_800C0658(void);

    u8 *unit;
    u8 wx;
    u8 wy;

    if (unitId != 0) {
        unit = gUnits + ((unitId - 1) * 0x280);
    } else {
        unit = 0;
    }

    if (unit == 0 || *(u32 *)(unit + 0x188) == 0) {
        return 0;
    }

    wx = x;
    wy = y;

    Unit_ResolveWarpPos(unit, &wx, &wy, 0, 0, 0);
    Unit_SetMapPos(unit, wx, wy);
    Map_RefreshUnitMap(gBattleMap);

    fn_80050C90(unit);

    if (Process_Find(Proc_MuEventInst) == 0) {
        u32 parent = fn_80127C48();
        if (parent == 0) {
            parent = fn_800C0658();
        }
        Process_Create(Proc_MuEventInst, parent);
    }

    return 1;
}

s32 fn_801A0F68(u8 arg0, u8 arg1, u8 arg2) {
    extern u8 gUnits[];
    extern u8 E_EventState_script[];
    extern u8 Proc_MuEventInst[];
    extern u8 gBattleMap[];
    extern s32 gUiInputFlags;
    void *Process_Find(u8 *);
    void *Process_Create(u8 *, s32);
    void Map_RefreshUnitMap(u8 *);
    void Unit_SetMapPos(void *, u8, u8);
    void fn_8004FE98(void *, s32);
    void fn_80050C90(void *);
    s32 fn_800C0658(void);
    s32 Unit_ResolveWarpPos(void *, u8 *, u8 *, s32, s32, s32);
    u32 fn_80127C48(void);
    void MoveAnim_BindPath(void *, s32, u16, void *);
    void fn_80184750(void *, s32, s32, s32);

    u8 *var_r31;
    u16 var_r30;
    void *temp;
    s32 temp_r28;
    u8 sp9;
    u8 sp8;
    void *var_r6;
    u32 var_r3;
    u8 b;
    s32 sw;

    if (arg0 != 0) {
        var_r31 = gUnits + ((arg0 - 1) * 0x280);
    } else {
        var_r31 = NULL;
    }
    if (var_r31 == NULL || *(u32 *)(var_r31 + 0x188) == 0) {
        return 0;
    }

    var_r30 = 0x80;
    temp = Process_Find(E_EventState_script);
    if (temp != NULL) {
        b = ((u8 *)temp)[0x30];
    } else {
        b = 1;
    }
    if (b != 0) {
        var_r30 |= 0x40;
    }

    temp = Process_Find(E_EventState_script);
    if (temp != NULL) {
        b = ((u8 *)temp)[0x31];
    } else {
        b = 0;
    }
    if (b != 0) {
        var_r30 |= 0x200;
    }

    temp = Process_Find(E_EventState_script);
    if (temp != NULL) {
        sw = ((u8 *)temp)[0x32];
    } else {
        sw = 0;
    }
    switch (sw) {
    case 2:
        var_r30 |= 0x20;
        break;
    case 1:
        var_r30 |= 0x10;
        break;
    }

    temp = Process_Find(E_EventState_script);
    var_r30 = (u16)(var_r30 | (temp != NULL ? *(u16 *)((u8 *)temp + 0x34) : 0));

    sp9 = arg1;
    sp8 = arg2;
    temp_r28 = Unit_ResolveWarpPos(var_r31, &sp9, &sp8, 1, 0, 0);
    if (temp_r28 != 0) {
        Unit_SetMapPos(var_r31, sp9, sp8);
        if (gUiInputFlags & 1) {
            fn_8004FE98(var_r31, 0);
            fn_80184750(var_r31, var_r30 & 0xF, 0, 0);
            fn_80050C90(var_r31);
        } else {
            temp = Process_Find(Proc_MuEventInst);
            if (temp != NULL) {
                var_r6 = temp;
            } else {
                var_r3 = fn_80127C48();
                if (var_r3 == 0) {
                    var_r3 = fn_800C0658();
                }
                var_r6 = Process_Create(Proc_MuEventInst, var_r3);
            }
            MoveAnim_BindPath(var_r31, temp_r28, var_r30, var_r6);
        }
    }
    Map_RefreshUnitMap(gBattleMap);
    return 1;
}

s32 fn_801A1198(s32 arg0, s8 *arg1)
{
    extern s8 gUnits[];
    extern u8 E_EventState_script[];
    extern u8 Proc_MuEventInst[];
    extern u8 lbl_8027AD98[];
    extern u8 gBattleMap[];
    extern u32 gUiInputFlags;

    void *Process_Find(void *);
    void *Process_Create(void *, u32);
    void *fn_800C45B8(s32, void *, s32);
    void fn_800C4588(void *);
    void Unit_SetMapPos(void *, s8, s8);
    void fn_8004FE98(void *, s32);
    void *fn_80184750(void *, s32, s32, s32);
    void fn_80050C90(void *);
    u32 fn_80127C48(void);
    u32 fn_800C0658(void);
    void *MoveAnim_BindPath(void *, u8 *, u16, void *);
    void Map_RefreshUnitMap(void *);

    s8 *unit;
    u16 flags;
    s32 x;
    s32 y;
    u8 *buffer;
    u8 *dst;
    u8 *state;
    u8 mode;
    s32 mode2;
    s32 field;
    s32 ch;
    void *temp;
    void *var_r6;
    u32 var_r3;

    if ((u8)arg0 != 0) {
        unit = gUnits + ((u8)arg0 - 1) * 0x280;
    } else {
        unit = 0;
    }

    if (unit == 0 || *(u32 *)(unit + 0x188) == 0) {
        return 0;
    }

    flags = 0x80;

    state = Process_Find(E_EventState_script);
    mode = state != 0 ? state[0x30] : 1;
    if (mode != 0) {
        flags |= 0x40;
    }

    state = Process_Find(E_EventState_script);
    mode = state != 0 ? state[0x31] : 0;
    if (mode != 0) {
        flags |= 0x200;
    }

    state = Process_Find(E_EventState_script);
    mode2 = state != 0 ? state[0x32] : 0;
    switch (mode2) {
    case 2:
        flags |= 0x20;
        break;
    case 1:
        flags |= 0x10;
        break;
    }

    state = Process_Find(E_EventState_script);
    field = state != 0 ? *(u16 *)(state + 0x34) : 0;
    flags |= field;

    x = unit[0x19E];
    y = unit[0x19F];

    buffer = fn_800C45B8(-0x80, lbl_8027AD98 + 0x5C5, 0);
    dst = buffer;

    while (*arg1 != 0) {
        ch = *arg1++;
        switch (ch) {
        case '8':
            y--;
            *dst++ = 8;
            break;
        case '2':
            y++;
            *dst++ = 4;
            break;
        case '4':
            x--;
            *dst++ = 1;
            break;
        case '6':
            x++;
            *dst++ = 2;
            break;
        case 'U':
            flags |= 8;
            break;
        case 'D':
            flags |= 4;
            break;
        case 'L':
            flags |= 1;
            break;
        case 'R':
            flags |= 2;
            break;
        }
    }

    *dst = 0x10;

    Unit_SetMapPos(unit, (s8)x, (s8)y);

    if (gUiInputFlags & 1) {
        fn_8004FE98(unit, 0);
        fn_80184750(unit, flags & 0xF, 0, 0);
        fn_80050C90(unit);
    } else {
        temp = Process_Find(Proc_MuEventInst);
        if (temp != 0) {
            var_r6 = temp;
        } else {
            var_r3 = fn_80127C48();
            if (var_r3 == 0) {
                var_r3 = fn_800C0658();
            }
            var_r6 = Process_Create(Proc_MuEventInst, var_r3);
        }
        MoveAnim_BindPath(unit, buffer, flags, var_r6);
    }

    fn_800C4588(buffer);
    Map_RefreshUnitMap(gBattleMap);
    return 1;
}

s32 fn_801A147C(void *arg0, s32 *arg1, s32 *arg2) {
    void fn_80106F68(void *, u8 *, u8 *);
    u8 sp9;
    u8 sp8;

    fn_80106F68(arg0, &sp9, &sp8);
    *arg1 = (s8)sp9;
    *arg2 = (s8)sp8;
    return 0;
}

s32 fn_801A14D8(s32 arg0) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    void *Process_CreateChild(void *, s32);
    s32 fn_800C0658(void);
    void Dispos_Apply(s32, void *, s32);
    u32 fn_80127C48(void);
    u8 fn_80183974(void);
    void fn_80013864(void);
    void fn_80106BCC(void);
    void Unit_MoveToList(void *,s32);
    void fn_80050C90(void *);
    extern u8 Proc_MuEventInst[];
    extern u8 lbl_80296FCC[];
    extern u8 gUnitLists[];
    void *next;
    s32 count;
    void *unit;
    void *temp;
    void *proc;
    u32 parent;
    fn_80106BCC();
    count=0;
    for(unit=*(void **)(gUnitLists+0x3C);unit;unit=next) {
        u32 flags=M2C_FIELD(unit,u32 *,0x1A0);
        next=M2C_FIELD(unit,void **,0x184);
        if(flags&0x400000) {
            M2C_FIELD(unit,u32 *,0x1A0)=flags&~1;
            Unit_MoveToList(unit,0);
            fn_80050C90(unit);
            count++;
        }
    }
    if(count>0) {
        temp=Process_Find(Proc_MuEventInst);
        if(temp) proc=temp;
        else {
            parent=fn_80127C48();
            if(!parent) parent=fn_800C0658();
            proc=Process_Create(Proc_MuEventInst,parent);
        }
        Dispos_Apply(arg0,proc,2);
        temp=Process_Find(Proc_MuEventInst);
        if((((u32)(-(s32)temp|(s32)temp)>>31)!=0)||fn_80183974()!=0) {
            fn_80013864();
            Process_CreateChild(lbl_80296FCC,fn_800C0658());
        }
    }
    return 1;
}

s32 fn_801A1604(s32 arg0) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    void *Process_CreateChild(void *, s32);
    s32 fn_800C0658(void);
    void Dispos_Apply(s32, void *, s32);
    u32 fn_80127C48(void);
    u8 fn_80183974(void);
    void fn_80013864(void);
    extern u8 Proc_MuEventInst[];
    extern u8 lbl_80296FCC[];
    void *var_r4;
    u32 var_r3;
    void *temp;

    temp = Process_Find(Proc_MuEventInst);
    if (temp != NULL) {
        var_r4 = temp;
    } else {
        var_r3 = fn_80127C48();
        if (var_r3 == 0U) {
            var_r3 = fn_800C0658();
        }
        var_r4 = Process_Create(Proc_MuEventInst, var_r3);
    }
    Dispos_Apply(arg0, var_r4, 3);
    temp = Process_Find(Proc_MuEventInst);
    if ((((u32)(-(s32)temp | (s32)temp) >> 31) != 0) || (fn_80183974() != 0)) {
        fn_80013864();
        Process_CreateChild(lbl_80296FCC, fn_800C0658());
    }
    return 1;
}

s32 fn_801A16BC(void *arg0) {
    Dispos_Apply(arg0, 0, 2);
    return 1;
}

s32 fn_801A16E8(s32 arg0) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    void *Process_CreateChild(void *, s32);
    s32 fn_800C0658(void);
    void Dispos_Apply(s32, void *, s32);
    u32 fn_80127C48(void);
    u8 fn_80183974(void);
    void fn_80013864(void);
    extern u8 Proc_MuEventInst[];
    extern u8 lbl_80296FCC[];
    void *var_r4;
    u32 var_r3;
    void *temp;

    temp = Process_Find(Proc_MuEventInst);
    if (temp != NULL) {
        var_r4 = temp;
    } else {
        var_r3 = fn_80127C48();
        if (var_r3 == 0U) {
            var_r3 = fn_800C0658();
        }
        var_r4 = Process_Create(Proc_MuEventInst, var_r3);
    }
    Dispos_Apply(arg0, var_r4, 2);
    temp = Process_Find(Proc_MuEventInst);
    if ((((u32)(-(s32)temp | (s32)temp) >> 31) != 0) || (fn_80183974() != 0)) {
        fn_80013864();
        Process_CreateChild(lbl_80296FCC, fn_800C0658());
    }
    return 1;
}

s32 fn_801A17A0(void *arg0) {
    Dispos_Apply(arg0, 0, 1);
    return 1;
}

s32 fn_801A17CC(s32 arg0) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    void *Process_CreateChild(void *, s32);
    s32 fn_800C0658(void);
    void Dispos_Apply(s32, void *, s32);
    u32 fn_80127C48(void);
    u8 fn_80183974(void);
    void fn_80013864(void);
    extern u8 Proc_MuEventInst[];
    extern u8 lbl_80296FCC[];
    void *var_r4;
    u32 var_r3;
    void *temp;

    temp = Process_Find(Proc_MuEventInst);
    if (temp != NULL) {
        var_r4 = temp;
    } else {
        var_r3 = fn_80127C48();
        if (var_r3 == 0U) {
            var_r3 = fn_800C0658();
        }
        var_r4 = Process_Create(Proc_MuEventInst, var_r3);
    }
    Dispos_Apply(arg0, var_r4, 1);
    temp = Process_Find(Proc_MuEventInst);
    if ((((u32)(-(s32)temp | (s32)temp) >> 31) != 0) || (fn_80183974() != 0)) {
        fn_80013864();
        Process_CreateChild(lbl_80296FCC, fn_800C0658());
    }
    return 1;
}

s32 fn_801A1884(char *arg0) {
    void strcpy(char *, char *);
    void strcat(char *, char *);
    void Dispos_Apply(char *, s32, s32);
    extern u16 gBattleState[];
    extern u8 lbl_8027AD98[];
    char sp8[0x28];

    strcpy(sp8, arg0);
    switch (((u8 *)gBattleState)[0xA6]) {
    case 0:
        strcat(sp8, (char *)(lbl_8027AD98 + 0x5C6));
        break;
    case 1:
        strcat(sp8, (char *)(lbl_8027AD98 + 0x5C9));
        break;
    case 2:
    case 3:
        strcat(sp8, (char *)(lbl_8027AD98 + 0x5CC));
        break;
    }
    Dispos_Apply(sp8, 0, 0);
    return 1;
}

s32 fn_801A1934(void *arg0) {
    Dispos_Apply(arg0, 0, 0);
    return 1;
}

s32 fn_801A1960(s32 arg0) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    void Dispos_Apply(s32, void *, s32);
    u32 fn_80127C48(void);
    s32 fn_800C0658(void);
    extern u8 Proc_MuEventInst[];
    void *var_r4;
    u32 var_r3;
    void *temp;

    temp = Process_Find(Proc_MuEventInst);
    if (temp != NULL) {
        var_r4 = temp;
    } else {
        var_r3 = fn_80127C48();
        if (var_r3 == 0U) {
            var_r3 = fn_800C0658();
        }
        var_r4 = Process_Create(Proc_MuEventInst, var_r3);
    }
    Dispos_Apply(arg0, var_r4, 0);
    return 1;
}

s32 fn_801A19D8(s32 arg0) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    void *Process_CreateChild(void *, s32);
    s32 fn_800C0658(void);
    void Dispos_Apply(s32, void *, s32);
    u32 fn_80127C48(void);
    u8 fn_80183974(void);
    void fn_80013864(void);
    extern u8 Proc_MuEventInst[];
    extern u8 lbl_80296FCC[];
    void *var_r4;
    u32 var_r3;
    void *temp;

    temp = Process_Find(Proc_MuEventInst);
    if (temp != NULL) {
        var_r4 = temp;
    } else {
        var_r3 = fn_80127C48();
        if (var_r3 == 0U) {
            var_r3 = fn_800C0658();
        }
        var_r4 = Process_Create(Proc_MuEventInst, var_r3);
    }
    Dispos_Apply(arg0, var_r4, 0);
    temp = Process_Find(Proc_MuEventInst);
    if ((((u32)(-(s32)temp | (s32)temp) >> 31) != 0) || (fn_80183974() != 0)) {
        fn_80013864();
        Process_CreateChild(lbl_80296FCC, fn_800C0658());
    }
    return 1;
}

extern s32 lbl_801B1C80;
extern s32 lbl_801B1C84;
extern s32 lbl_801B1C88;
extern s32 lbl_801B1C8C;
/* Ensure E_EventState exists; enable or disable the E_Sepia overlay process. */
s32 ScriptCmd_EventSepia(s32 enable) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    void Process_UnlinkByKey(void *);
    s32 fn_800C0658(void);
    extern u16 E_EventState_script[];
    extern u16 E_Sepia_script[];
    extern u16 gBattleState[];
    void *p;
    void *state;

    p = Process_Find(E_EventState_script);
    if (p != NULL) {
        state = p;
    } else {
        p = Process_Create(E_EventState_script, fn_800C0658());
        M2C_FIELD(p, s8 *, 0x30) = 1;
        M2C_FIELD(p, s8 *, 0x31) = 0;
        M2C_FIELD(p, s8 *, 0x32) = 0;
        M2C_FIELD(p, s16 *, 0x34) = 0;
        M2C_FIELD(p, u8 *, 0x33) = ((u8 *)gBattleState)[0xA0];
        M2C_FIELD(p, s8 *, 0x36) = 1;
        M2C_FIELD(p, s32 *, 0x3C) = 1;
        M2C_FIELD(p, s8 *, 0x37) = 0;
        M2C_FIELD(p, s8 *, 0x38) = 0;
        state = p;
    }
    if (state != NULL) {
        M2C_FIELD(state, s8 *, 0x37) = (s8)enable;
        if ((u8)M2C_FIELD(state, u8 *, 0x37) == 1) {
            Process_Create(E_Sepia_script, (s32)state);
        } else {
            Process_UnlinkByKey(E_Sepia_script);
        }
    }
    return 1;
}

s32 fn_801A1B58(s32 arg0) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    s32 fn_800C0658(void);
    void fn_8004DC54(s32);
    extern u16 E_EventState_script[];
    extern u16 gBattleState[];

    void *p = Process_Find(E_EventState_script);
    if (p == NULL) {
        s32 x = fn_800C0658();
        p = Process_Create(E_EventState_script, x);
        ((u8 *)p)[0x30] = 1;
        ((u8 *)p)[0x31] = 0;
        ((u8 *)p)[0x32] = 0;
        *(u16 *)((u8 *)p + 0x34) = 0;
        ((u8 *)p)[0x33] = ((u8 *)gBattleState)[0xA0];
        ((u8 *)p)[0x36] = 1;
        *(s32 *)((u8 *)p + 0x3C) = 1;
        ((u8 *)p)[0x37] = 0;
        ((u8 *)p)[0x38] = 0;
    }
    fn_8004DC54(arg0 != 0);
    return 1;
}

s32 ScriptCmd_EventSetSavedByte(s32 value) {
    /* Set gBattleState[0xA0] clamped to 0–100; negative restores the E_EventState backup. */
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    s32 fn_800C0658(void);
    extern u16 E_EventState_script[];
    extern u16 gBattleState[];
    s32 v;
    void *p;

    v = value;
    if (v > 0x64) {
        v = 0x64;
    }
    if (v < 0) {
        p = Process_Find(E_EventState_script);
        if (p != NULL) {
            ((u8 *)gBattleState)[0xA0] = ((u8 *)p)[0x33];
        }
    } else {
        if (Process_Find(E_EventState_script) == NULL) {
            p = Process_Create(E_EventState_script, fn_800C0658());
            M2C_FIELD(p, s8 *, 0x30) = 1;
            M2C_FIELD(p, s8 *, 0x31) = 0;
            M2C_FIELD(p, s8 *, 0x32) = 0;
            M2C_FIELD(p, s16 *, 0x34) = 0;
            M2C_FIELD(p, u8 *, 0x33) = ((u8 *)gBattleState)[0xA0];
            M2C_FIELD(p, s8 *, 0x36) = 1;
            M2C_FIELD(p, s32 *, 0x3C) = 1;
            M2C_FIELD(p, s8 *, 0x37) = 0;
            M2C_FIELD(p, s8 *, 0x38) = 0;
        }
        ((u8 *)gBattleState)[0xA0] = (u8)v;
    }
    return 1;
}

u16 fn_801A1CC8(void) {
    void *Process_Find(void *);
    extern u8 E_EventState_script[];
    void *p;

    p = Process_Find(E_EventState_script);
    if (p != NULL) {
        return *(u16 *)((u8 *)p + 0x34);
    }
    return 0;
}

s32 fn_801A1D04(s32 arg0) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    s32 fn_800C0658(void);
    extern u16 E_EventState_script[];
    void *p;
    void *v;

    p = Process_Find(E_EventState_script);
    if (p != NULL) {
        v = p;
    } else {
        p = Process_Create(E_EventState_script, fn_800C0658());
        M2C_FIELD(p, s8 *, 0x30) = 1;
        M2C_FIELD(p, s8 *, 0x31) = 0;
        M2C_FIELD(p, s8 *, 0x32) = 0;
        M2C_FIELD(p, s16 *, 0x34) = 0;
        M2C_FIELD(p, u8 *, 0x33) = ((u8 *)gBattleState)[0xA0];
        M2C_FIELD(p, s8 *, 0x36) = 1;
        M2C_FIELD(p, s32 *, 0x3C) = 1;
        M2C_FIELD(p, s8 *, 0x37) = 0;
        M2C_FIELD(p, s8 *, 0x38) = 0;
        v = p;
    }
    if (arg0 != 0) {
        M2C_FIELD(v, u16 *, 0x34) = (u16)(M2C_FIELD(v, u16 *, 0x34) | 0x100);
    } else {
        M2C_FIELD(v, u16 *, 0x34) = (u16)(M2C_FIELD(v, u16 *, 0x34) & 0xFFFFFEFF);
    }
    return 1;
}

s32 fn_801A1DB8(s32 arg0) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    s32 fn_800C0658();
    extern u16 E_EventState_script[];
    extern u16 gBattleState[];
    void *p;
    void *v;
    u16 t;

    p = Process_Find(E_EventState_script);
    if (p != NULL) {
        v = p;
    } else {
        p = Process_Create(E_EventState_script, fn_800C0658());
        *(s8 *)((u8 *)p + 0x30) = 1;
        *(s8 *)((u8 *)p + 0x31) = 0;
        *(s8 *)((u8 *)p + 0x32) = 0;
        *(s16 *)((u8 *)p + 0x34) = 0;
        *(u8 *)((u8 *)p + 0x33) = ((u8 *)gBattleState)[0xA0];
        *(s8 *)((u8 *)p + 0x36) = 1;
        *(s32 *)((u8 *)p + 0x3C) = 1;
        *(s8 *)((u8 *)p + 0x37) = 0;
        *(s8 *)((u8 *)p + 0x38) = 0;
        v = p;
    }
    t = *(u16 *)((u8 *)v + 0x34);
    t = t & 0xFFF0;
    *(u16 *)((u8 *)v + 0x34) = t;
    *(u16 *)((u8 *)v + 0x34) = *(u16 *)((u8 *)v + 0x34) | (arg0 & 0xF);
    return 1;
}

s32 ScriptCmd_GetScaledHeight(s8 x, s8 y) {
    /* Return battle-map height at tile (x, y), scaled by E_EventState's scale (or 1). */
    void *Process_Find(void *);
    f32 Map_SampleHeightRaw(void *, f32, f32);
    extern u16 E_EventState_script[];
    extern u8 gBattleMap[];
    void *state;
    s32 scale;
    f32 height;

    state = Process_Find(E_EventState_script);
    if (state != NULL) {
        scale = *(s32 *)((u8 *)state + 0x3C);
    } else {
        scale = 1;
    }
    height = Map_SampleHeightRaw(gBattleMap, (f32)x, (f32)y);
    return (s32)(height * (f32)scale);
}

/* Sample battle-map height at tile (x, y), scaled by E_EventState's scale (or 1). */
s32 Map_GetScaledHeight(s8 x, s8 y) {
    void *Process_Find(void *);
    f32 Map_SampleHeight(void *, f32, f32);
    extern u16 E_EventState_script[];
    extern u8 gBattleMap[];
    void *state;
    s32 scale;
    f32 height;

    state = Process_Find(E_EventState_script);
    if (state != NULL) {
        scale = *(s32 *)((u8 *)state + 0x3C);
    } else {
        scale = 1;
    }
    height = Map_SampleHeight(gBattleMap, (f32)x, (f32)y);
    return (s32)(height * (f32)scale);
}

s32 fn_801A2004(s32 arg0) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    s32 fn_800C0658();
    extern u16 E_EventState_script[];
    void *p;
    void *v;

    p = Process_Find(E_EventState_script);
    if (p != NULL) {
        v = p;
    } else {
        p = Process_Create(E_EventState_script, fn_800C0658());
        M2C_FIELD(p, s8 *, 0x30) = 1;
        M2C_FIELD(p, s8 *, 0x31) = 0;
        M2C_FIELD(p, s8 *, 0x32) = 0;
        M2C_FIELD(p, s16 *, 0x34) = 0;
        M2C_FIELD(p, u8 *, 0x33) = ((u8 *)gBattleState)[0xA0];
        M2C_FIELD(p, s8 *, 0x36) = 1;
        M2C_FIELD(p, s32 *, 0x3C) = 1;
        M2C_FIELD(p, s8 *, 0x37) = 0;
        M2C_FIELD(p, s8 *, 0x38) = 0;
        v = p;
    }
    M2C_FIELD(v, s32 *, 0x3C) = arg0;
    return 1;
}

s32 fn_801A2098(void) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    s32 fn_800C0658();
    extern u16 E_EventState_script[];
    void *p;
    void *v;

    p = Process_Find(E_EventState_script);
    if (p != NULL) {
        v = p;
    } else {
        p = Process_Create(E_EventState_script, fn_800C0658());
        M2C_FIELD(p, s8 *, 0x30) = 1;
        v = p;
        M2C_FIELD(p, s8 *, 0x31) = 0;
        M2C_FIELD(p, s8 *, 0x32) = 0;
        M2C_FIELD(p, s16 *, 0x34) = 0;
        M2C_FIELD(p, u8 *, 0x33) = ((u8 *)gBattleState)[0xA0];
        M2C_FIELD(p, s8 *, 0x36) = 1;
        M2C_FIELD(p, s32 *, 0x3C) = 1;
        M2C_FIELD(p, s8 *, 0x37) = 0;
        M2C_FIELD(p, s8 *, 0x38) = 0;
    }
    M2C_FIELD(v, s8 *, 0x32) = 0;
    return 1;
}

s32 fn_801A212C(void) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    s32 fn_800C0658();
    extern u16 E_EventState_script[];
    void *p;
    void *v;

    p = Process_Find(E_EventState_script);
    if (p != NULL) {
        v = p;
    } else {
        p = Process_Create(E_EventState_script, fn_800C0658());
        M2C_FIELD(p, s8 *, 0x30) = 1;
        v = p;
        M2C_FIELD(p, s8 *, 0x31) = 0;
        M2C_FIELD(p, s8 *, 0x32) = 0;
        M2C_FIELD(p, s16 *, 0x34) = 0;
        M2C_FIELD(p, u8 *, 0x33) = ((u8 *)gBattleState)[0xA0];
        M2C_FIELD(p, s8 *, 0x36) = 1;
        M2C_FIELD(p, s32 *, 0x3C) = 1;
        M2C_FIELD(p, s8 *, 0x37) = 0;
        M2C_FIELD(p, s8 *, 0x38) = 0;
    }
    M2C_FIELD(v, s8 *, 0x32) = 2;
    return 1;
}

s32 fn_801A21C0(void) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    s32 fn_800C0658(void);
    extern u16 E_EventState_script[];
    extern u16 gBattleState[];
    void *p;
    void *v;

    p = Process_Find(E_EventState_script);
    if (p != NULL) {
        v = p;
    } else {
        p = Process_Create(E_EventState_script, fn_800C0658());
        *(s8 *)((u8 *)p + 0x30) = 1;
        v = p;
        *(s8 *)((u8 *)p + 0x31) = 0;
        *(s8 *)((u8 *)p + 0x32) = 0;
        *(s16 *)((u8 *)p + 0x34) = 0;
        *(u8 *)((u8 *)p + 0x33) = ((u8 *)gBattleState)[0xA0];
        *(s8 *)((u8 *)p + 0x36) = 1;
        *(s32 *)((u8 *)p + 0x3C) = 1;
        *(s8 *)((u8 *)p + 0x37) = 0;
        *(s8 *)((u8 *)p + 0x38) = 0;
    }
    *(s8 *)((u8 *)v + 0x32) = 1;
    return 1;
}

s32 fn_801A2254(s32 arg0) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    s32 fn_800C0658();
    extern u16 E_EventState_script[];
    void *p;
    void *v;

    p = Process_Find(E_EventState_script);
    if (p != NULL) {
        v = p;
    } else {
        p = Process_Create(E_EventState_script, fn_800C0658());
        M2C_FIELD(p, s8 *, 0x30) = 1;
        M2C_FIELD(p, s8 *, 0x31) = 0;
        M2C_FIELD(p, s8 *, 0x32) = 0;
        M2C_FIELD(p, s16 *, 0x34) = 0;
        M2C_FIELD(p, u8 *, 0x33) = ((u8 *)gBattleState)[0xA0];
        M2C_FIELD(p, s8 *, 0x36) = 1;
        M2C_FIELD(p, s32 *, 0x3C) = 1;
        M2C_FIELD(p, s8 *, 0x37) = 0;
        M2C_FIELD(p, s8 *, 0x38) = 0;
        v = p;
    }
    if (arg0 != 0) {
        M2C_FIELD(v, s8 *, 0x31) = 1;
    } else {
        M2C_FIELD(v, s8 *, 0x31) = 0;
    }
    return 1;
}

u8 fn_801A2300(void) {
    void *Process_Find(void *);
    extern u8 E_EventState_script[];
    void *p;

    p = Process_Find(E_EventState_script);
    if (p != NULL) {
        return M2C_FIELD(p, u8 *, 0x30);
    }
    return 1;
}

s32 fn_801A233C(void) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    s32 fn_800C0658();
    extern u16 E_EventState_script[];
    void *p;
    void *v;

    p = Process_Find(E_EventState_script);
    if (p != NULL) {
        v = p;
    } else {
        p = Process_Create(E_EventState_script, fn_800C0658());
        M2C_FIELD(p, s8 *, 0x30) = 1;
        v = p;
        M2C_FIELD(p, s8 *, 0x31) = 0;
        M2C_FIELD(p, s8 *, 0x32) = 0;
        M2C_FIELD(p, s16 *, 0x34) = 0;
        M2C_FIELD(p, u8 *, 0x33) = ((u8 *)gBattleState)[0xA0];
        M2C_FIELD(p, s8 *, 0x36) = 1;
        M2C_FIELD(p, s32 *, 0x3C) = 1;
        M2C_FIELD(p, s8 *, 0x37) = 0;
        M2C_FIELD(p, s8 *, 0x38) = 0;
    }
    M2C_FIELD(v, s8 *, 0x30) = 1;
    return 1;
}

s32 fn_801A23D0(void) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    s32 fn_800C0658();
    extern u16 E_EventState_script[];
    void *p;
    void *v;

    p = Process_Find(E_EventState_script);
    if (p != NULL) {
        v = p;
    } else {
        p = Process_Create(E_EventState_script, fn_800C0658());
        M2C_FIELD(p, s8 *, 0x30) = 1;
        v = p;
        M2C_FIELD(p, s8 *, 0x31) = 0;
        M2C_FIELD(p, s8 *, 0x32) = 0;
        M2C_FIELD(p, s16 *, 0x34) = 0;
        M2C_FIELD(p, u8 *, 0x33) = ((u8 *)gBattleState)[0xA0];
        M2C_FIELD(p, s8 *, 0x36) = 1;
        M2C_FIELD(p, s32 *, 0x3C) = 1;
        M2C_FIELD(p, s8 *, 0x37) = 0;
        M2C_FIELD(p, s8 *, 0x38) = 0;
    }
    M2C_FIELD(v, s8 *, 0x30) = 0;
    return 1;
}

s32 fn_801A2464(void) {
    void *Process_Find(void *);
    void *Process_CreateChild(void *, s32);
    s32 fn_800C0658(void);
    u8 fn_80183974(void);
    void fn_80013864(void);
    extern u8 Proc_MuEventInst[];
    extern u8 lbl_80296FCC[];
    void *temp;

    temp = Process_Find(Proc_MuEventInst);
    if ((((u32)(-(s32)temp | (s32)temp) >> 31) != 0) || (fn_80183974() != 0)) {
        fn_80013864();
        Process_CreateChild(lbl_80296FCC, fn_800C0658());
    }
    return 1;
}

void fn_801A24C4(void *arg0) {
    s32 Process_Find(void *);
    u8 fn_80183974(void);
    void Process_ClearFunc(void *);
    extern u8 Proc_MuEventInst[];
    s32 temp_r3;

    temp_r3 = Process_Find(Proc_MuEventInst);
    if (((u32)(-temp_r3 | temp_r3) >> 31) == 0 && fn_80183974() == 0) {
        Process_ClearFunc(arg0);
    }
}

#pragma optimization_level 1
void fn_801A251C(void) {
    void *Process_Find(u8 *);
    void *Process_Create(u8 *, s32);
    u32 fn_80127C48(void);
    s32 fn_800C0658(void);
    extern u8 Proc_MuEventInst[];
    void *temp;
    void *var_r4;
    u32 var_r3;

    temp = Process_Find(Proc_MuEventInst);
    if (temp != NULL) {
        var_r4 = temp;
    } else {
        var_r3 = fn_80127C48();
        if (var_r3 == 0) {
            var_r3 = fn_800C0658();
        }
        Process_Create(Proc_MuEventInst, var_r3);
    }
}
#pragma optimization_level reset
void fn_801A2570(void) {
    void fn_800C1060(void);
    extern u8 gMapBlendMode;
    u8 flag;
    u8 temp;

    flag = 1;
    temp = (u8)(gMapBlendMode - 1);
    if (!(temp <= 1U)) {
        flag = 0;
    }
    if (flag) {
        fn_800C1060();
    }
}

void fn_801A25C4(void) {
    M2C_UNK fn_80016180();
    M2C_UNK fn_8005376C();
    M2C_UNK fn_800C1BDC();
    extern s32 gUiInputFlags;
    if (gUiInputFlags & 1) {
        Process_Unlink();
        fn_800C1BDC();
        fn_80016180();
        fn_8005376C();
    }
}

s32 fn_801A25FC(s8 arg0) {
    void *Process_Find(void *);
    void *Process_Create(void *, s32);
    s32 fn_800C0658(void);
    extern u16 E_EventState_script[];
    extern u16 gBattleState[];
    void *p;
    void *v;

    p = Process_Find(E_EventState_script);
    if (p != NULL) {
        v = p;
    } else {
        p = Process_Create(E_EventState_script, fn_800C0658());
        M2C_FIELD(p, s8 *, 0x30) = 1;
        M2C_FIELD(p, s8 *, 0x31) = 0;
        M2C_FIELD(p, s8 *, 0x32) = 0;
        M2C_FIELD(p, s16 *, 0x34) = 0;
        M2C_FIELD(p, u8 *, 0x33) = ((u8 *)gBattleState)[0xA0];
        M2C_FIELD(p, s8 *, 0x36) = 1;
        M2C_FIELD(p, s32 *, 0x3C) = 1;
        M2C_FIELD(p, s8 *, 0x37) = 0;
        M2C_FIELD(p, s8 *, 0x38) = 0;
        v = p;
    }
    M2C_FIELD(v, s8 *, 0x38) = arg0;
    return 1;
}

u8 fn_801A2690(void) {
    void *Process_Find(u16 *);
    extern u8 E_EventState_script[];
    void *temp_r3;
    temp_r3 = Process_Find((u16 *)E_EventState_script);
    if (temp_r3 == NULL) {
        return 0U;
    }
    return *(u8 *)((uintptr_t)temp_r3 + 0x38);
}

void fn_801A26CC(void *arg0) {
extern u16 gBattleState[];
extern s32 gUiInputFlags;
s32 fn_80040824(void *);
void *Map_Get(void);
void Map_ReloadTileFlags(void *,s32);
void fn_8004DC54(s32);
u8 *obj=(u8*)arg0;
((u8*)gBattleState)[0xa0]=obj[0x33];
if(obj[0x36]==0) {
gUiInputFlags &= ~0x1000;
if((u8)fn_80040824(arg0)!=0) {
Map_ReloadTileFlags(Map_Get(),1);
}
}
fn_8004DC54(1);
}

void fn_801A2730(void *arg0)
{
    void fn_80067708(s32, s32, void (*)(void *), void *);
    void fn_801A27F8(void *);

    fn_80067708(4, 2, fn_801A27F8, arg0);
}

void fn_801A2764(void *arg0) {
    M2C_UNK fn_800C4588(s32);
    fn_800C4588(M2C_FIELD(arg0, s32 *, 0x30));
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
}

void fn_801A27A0(void *arg0) {
    s32 fn_800C45B8(void *, void *, M2C_UNK);
    void *GXGetTexBufferSize(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern u16 lbl_8027AD98[];
    *(s32 *)((u8 *)arg0 + 0x30) = fn_800C45B8(GXGetTexBufferSize(0x260, 0x1C0, 4, 0, 0), (u8 *)lbl_8027AD98 + 0x5C5, 0);
}

void fn_801A27F8(void *arg0) {
    M2C_UNK fn_80066D00(M2C_UNK, void *, f32, f32, f32);
    M2C_UNK fn_80067490(M2C_UNK);
    M2C_UNK fn_80067984(M2C_UNK);
    M2C_UNK Camera_ApplyOrtho(M2C_UNK);
    M2C_UNK GXSetVtxDesc(M2C_UNK, M2C_UNK);
    M2C_UNK GXClearVtxDesc();
    M2C_UNK GXSetVtxAttrFmt(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK fn_802201A8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXSetNumChans(M2C_UNK);
    M2C_UNK fn_802209FC();
    M2C_UNK GXBegin(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK fn_8022124C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK fn_802212FC(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXCopyTex(u32, M2C_UNK);
    M2C_UNK GXSetCullMode(M2C_UNK);
    M2C_UNK GXSetBlendMode(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK fn_80222644(M2C_UNK *, u32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXInitTexObjLOD(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32, f32, f32);
    M2C_UNK fn_80222C50(M2C_UNK *, M2C_UNK);
    M2C_UNK fn_80222EB4();
    M2C_UNK GXSetTevColorIn(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXSetTevAlphaIn(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXSetTevColorOp(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXSetTevAlphaOp(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK fn_80223C78(M2C_UNK, s32 *);
    M2C_UNK fn_80223CDC(M2C_UNK, M2C_UNK);
    M2C_UNK GXSetTevOrder(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXSetNumTevStages(M2C_UNK);
    M2C_UNK fn_802245D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXSetZMode(M2C_UNK, M2C_UNK, M2C_UNK);
    extern s32 lbl_8036AF60;
    M2C_UNK spC[8];
    s32 sp8;

    Camera_ApplyOrtho(0);
    if ((u32) M2C_FIELD(arg0, u32 *, 0x30) != 0U) {
        fn_8022124C(0, 0, 0x260, 0x1C0);
        fn_802212FC(0x260, 0x1C0, 4, 0);
        GXCopyTex(M2C_FIELD(arg0, u32 *, 0x30), 0);
        fn_802209FC();
        fn_80222EB4();
        fn_80222644(spC, M2C_FIELD(arg0, u32 *, 0x30), 0x260, 0x1C0, 4, 0, 0, 0);
        GXInitTexObjLOD(spC, 1, 1, 0, 0, 0, 0.0f, 0.0f, 0.0f);
        GXSetCullMode(1);
        GXSetBlendMode(4, 0, 1, 1, 0, 0, 2);
        GXSetNumChans(1);
        fn_80222C50(spC, 0);
        GXSetTevOrder(0, 0, 0, 4);
        fn_802201A8(0, 1, 4, 0x3C, 0, 0x7D);
        GXSetNumTevStages(1);
        sp8 = lbl_8036AF60;
        fn_80223C78(3, &sp8);
        fn_80223CDC(0, 0xF);
        GXSetTevColorIn(0, 0xF, 0xE, 8, 0xF);
        GXSetTevColorOp(0, 0, 0, 0, 1, 0);
        GXSetTevAlphaIn(0, 7, 7, 7, 6);
        GXSetTevAlphaOp(0, 0, 0, 0, 0, 0);
        fn_802245D8(0, 0, 0, 0);
        GXSetZMode(0, 3, 0);
        GXClearVtxDesc();
        GXSetVtxDesc(9, 1);
        GXSetVtxDesc(0xD, 1);
        GXSetVtxAttrFmt(0, 9, 1, 4, 0);
        GXSetVtxAttrFmt(0, 0xD, 1, 4, 0);
        fn_80067490(0);
        GXBegin(0x80, 0, 4);
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 608.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 1.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 608.0f;
        *(f32 *)0xCC008000 = 448.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 1.0f;
        *(f32 *)0xCC008000 = 1.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 448.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 0.0f;
        *(f32 *)0xCC008000 = 1.0f;
        fn_80066D00(-1, (void *)0xCC010000, 1.0f, 608.0f, 0.0f);
        fn_80067984(0);
    }
}

#include "common.h"

extern s32 lbl_8036AF6C;
extern u8 lbl_80367298;
#include "common.h"
extern u16 gUiPanelVtbl[];
#include "global.h"

extern u32 E_MuBlend_script[];
extern u32 E_MuTransfer_script[];
extern f32 lbl_8036ACE0;
extern f32 lbl_8036ACEC;
extern f32 lbl_8036AD04;
extern f32 lbl_8036ACF0;

void *GfxEnt_ForEachKey(u32*, u32*, void*);
void *Process_CreateEx(u32*, s32);
u8 fn_8004C0F0(s32);
void *fn_8004FE90(s32, u8);
void *fn_8004FE98(s32, s32);
void *fn_800506E0(s32, s32, void*);
void *fn_800508C4(s32);
f32 Math_Lerp(f32, f32, f32, f32);
void *fn_8005FC74(void*, void*, s32);
void *fn_8005FEE8(void*, f32);
s32 fn_80060440(s32);
void *fn_800639B4();
extern u16 gProcessQueue[];
extern s32 gProcessQueueCount;
extern u16 lbl_802968E8;
extern u16 lbl_802797C0[6];
extern u16 lbl_8036AE4C;
extern f32 lbl_8036AE50;
#include "common.h"

extern u16 Proc_MuEventInst;
#include "global.h"
#include "unit.h"
extern u16 lbl_80295D1C[];
#include "common.h"
#include "m2c.h"

extern u16 lbl_802923E0[];
extern u16 lbl_80296018[];
extern u16 gBattleState[0x2B4];
#include "common.h"
#include "structs.h"
#include "ef.h"

struct UnkStruct_802EF4C8 {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
    s8 unkA;
    u8 pad[0x18 - 0xB];
};

extern struct UnkStruct_802EF4C8 gUiContext;
extern u16 gBattle[];
extern u16 gUiInputFlags;
extern u16 lbl_80330E90[4];
extern u16 E_EventState_script[];
#include "global.h"
#include "structs.h"

extern u16 __files[160]; // 320 bytes, 160 elements
extern u8 lbl_80279DF0[29]; // 29 bytes

void *Heap_Alloc(s32);
void fprintf(void*, void*, void*);
void abort(void);
void Item_Clone(void*, s32);

typedef struct {
    void *unk0;
    void *unk4;
} unk_struct_80193CFC;
extern u8 E_MuColorChange_script[0x80];
#include "global.h"
extern u16 E_MuFade_script[36];
extern f32 lbl_8036ACE0;
extern f32 gHalf;
extern f32 lbl_8036ACE8;
#include "common.h"
#include "global.h"
#pragma optimization_level 4
#pragma inline auto

extern u16 gTargetList;
extern f32 lbl_8036AF00;
extern f32 lbl_8036AF20;
#include "common.h"
#include "global.h"
extern u32 lbl_8028FDB0;
extern u32 lbl_80292208;
extern u32 lbl_80292230;
extern u32 lbl_80293B74;
extern u32 lbl_80293BB8;
extern f32 lbl_8036AE20;
#include "global.h"
#include "common.h"

extern u32* D_801B5548;
extern s32* D_801B5580;
extern s32 D_801B56A4;
extern void* D_801B574C;
extern void* D_801B5750;
extern void* D_801B5754;
extern void* D_801B5758;
extern s32 D_801BF920;
extern s32* D_800D8C74;

// This is a stub for the function, but let's see what we can extract.
extern s32 D_801B56AC;
void fn_80198910(void *self, f32 *pos, s32 mode) {
void fn_800E4F30(void *);
s32 fn_800E5200(void *,s32,s32);
void PSMTXRotRad(void *,s32,f32);
void fn_802029C4(void *,void *,void *);
extern const f32 lbl_8036AEA8,lbl_8036AEAC,lbl_8036AEBC,lbl_8036AEC0,lbl_8036AEC4,lbl_8036AEC8,lbl_8036AECC,lbl_8036AED0,lbl_8036AED4,lbl_8036AED8,lbl_8036AEDC,lbl_8036AEE0;
extern void *gGame;
f32 mx[12],my[12],v[3]; s32 frames; f32 d, zero;
M2C_FIELD(self,void **,0x184)=M2C_FIELD(self,void **,0xEC);
M2C_FIELD(self,void **,0x188)=M2C_FIELD(self,void **,0xF0);
fn_800E4F30(self); M2C_FIELD(self,u8 *,0x14D)=0;
M2C_FIELD(self,f32 *,0x78)=pos[0];M2C_FIELD(self,f32 *,0x7c)=pos[1];M2C_FIELD(self,f32 *,0x80)=pos[2];
if(M2C_FIELD(self,s32 *,0x124)==9 && mode==3) M2C_FIELD(self,f32 *,0x54)=lbl_8036AEBC;
v[0]=lbl_8036AEA8;v[1]=lbl_8036AEA8;v[2]=lbl_8036AEC0;
PSMTXRotRad(mx,0x58,lbl_8036AEC4*M2C_FIELD(self,f32 *,0x54));
fn_802029C4(mx,v,v);
PSMTXRotRad(my,0x59,lbl_8036AEC4*M2C_FIELD(self,f32 *,0x58));
fn_802029C4(my,v,v);
M2C_FIELD(self,f32 *,0x84)=v[0];M2C_FIELD(self,f32 *,0x88)=v[1];M2C_FIELD(self,f32 *,0x8c)=v[2];
M2C_FIELD(self,f32 *,0x90)=lbl_8036AEA8;M2C_FIELD(self,f32 *,0x94)=lbl_8036AEA8;M2C_FIELD(self,f32 *,0x98)=lbl_8036AEA8;
switch(M2C_FIELD(self,s32 *,0x124)){
case 0:case 5:
M2C_FIELD(self,f32 *,0x84)*=M2C_FIELD(gGame,f32 *,0x110);M2C_FIELD(self,f32 *,0x8c)*=M2C_FIELD(gGame,f32 *,0x110);break;
case 1:case 6:
d=lbl_8036AEC8;zero=0.0f;
M2C_FIELD(self,f32 *,0x54)=M2C_FIELD(gGame,f32 *,0x114);M2C_FIELD(self,f32 *,0x88)=M2C_FIELD(gGame,f32 *,0x11c);
M2C_FIELD(self,f32 *,0x84)*=M2C_FIELD(gGame,f32 *,0x120);M2C_FIELD(self,f32 *,0x8c)*=M2C_FIELD(gGame,f32 *,0x120);
d+=(M2C_FIELD(self,f32 *,0x7c)-M2C_FIELD(self,f32 *,0x4c));
if(d>zero)d=zero;
if(d<lbl_8036AECC)d=lbl_8036AECC;
M2C_FIELD(self,f32 *,0x90)=lbl_8036AEA8;
M2C_FIELD(self,f32 *,0x94)=d*lbl_8036AED0+M2C_FIELD(gGame,f32 *,0x124);
M2C_FIELD(self,f32 *,0x98)=lbl_8036AEA8;break;
case 2:case 7:
frames=fn_800E5200(M2C_FIELD(self,void **,0x184),2,0);
frames=fn_800E5200(M2C_FIELD(self,void **,0x184),14,0)-frames-1;
M2C_FIELD(self,f32 *,0x150)=M2C_FIELD(self,f32 *,0x48);M2C_FIELD(self,f32 *,0x154)=M2C_FIELD(self,f32 *,0x4c);M2C_FIELD(self,f32 *,0x158)=M2C_FIELD(self,f32 *,0x50);
M2C_FIELD(self,f32 *,0x58)=lbl_8036AEA8;M2C_FIELD(self,f32 *,0x5c)=lbl_8036AED4;
M2C_FIELD(self,f32 *,0x84)*=M2C_FIELD(gGame,f32 *,0x128);M2C_FIELD(self,f32 *,0x8c)*=M2C_FIELD(gGame,f32 *,0x128);
v[0]=lbl_8036AEA8;v[1]=lbl_8036AEA8;v[2]=-(lbl_8036AED8*M2C_FIELD(gGame,f32 *,0x128)/frames);
fn_802029C4(my,v,v);
M2C_FIELD(self,f32 *,0x90)=v[0];M2C_FIELD(self,f32 *,0x94)=v[1];M2C_FIELD(self,f32 *,0x98)=lbl_8036AEA8;
M2C_FIELD(self,f32 *,0x168)=lbl_8036AEA8;M2C_FIELD(self,f32 *,0x16c)=lbl_8036AEDC;M2C_FIELD(self,f32 *,0x170)=lbl_8036AEA8;
M2C_FIELD(self,f32 *,0x174)=lbl_8036AEA8;M2C_FIELD(self,f32 *,0x178)=M2C_FIELD(gGame,f32 *,0x13c)*(lbl_8036AEE0/frames);M2C_FIELD(self,f32 *,0x17c)=lbl_8036AEA8;
M2C_FIELD(self,f32 *,0x180)=lbl_8036AEAC*(M2C_FIELD(self,f32 *,0x7c)-M2C_FIELD(self,f32 *,0x154));break;
case 9:M2C_FIELD(self,f32 *,0x84)*=M2C_FIELD(gGame,f32 *,0x140);M2C_FIELD(self,f32 *,0x88)*=M2C_FIELD(gGame,f32 *,0x140);M2C_FIELD(self,f32 *,0x8c)*=M2C_FIELD(gGame,f32 *,0x140);break;
case 3:case 4:case 8:default:break;
}
M2C_FIELD(self,u8 *,0x14C)=1;
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
/* Sync BW00N weapon-bone matrices from the source unit actor onto this unit and its weapon actor. */
void MoveAnim_SyncWeaponBones(void *self) {
    void fn_800608AC(void *);
    void *Unit_GetActor(void *);
    void *GActor_GetNodeTable(void *);
    void MTXRotDegOrder(void *, void *);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXCopy(void *, void *);
    s32 Str_Cmp(char *, char *);
    s32 GActor_FindNode(void *, char *);
    void fn_8006D378(void *);
    void fn_800E4A78(void *, void *);
    extern u8 gWeaponAttachStr[];

    f32 mtxWorld[3][4];
    f32 mtxTmpA[3][4];
    f32 mtxTmpB[3][4];
    void *srcActor;
    s32 srcMtxOff;
    s32 nSrcBones;
    s32 nDstBones;
    s32 i;
    u8 *srcBone;
    u8 *dstBone;
    void *anim;
    s32 found;
    s32 srcBwId;
    s32 dstBwId;
    void *dstActor;
    s32 j;
    char *name;
    void *dstMtx;

    anim = self;
    fn_800608AC(*(void **)((u8 *)anim + 0xE0));
    srcActor = Unit_GetActor(*(void **)((u8 *)anim + 0xEC));
    {
        void *srcTable = *(void **)((u8 *)srcActor + 0x40);
        void *dstTable = *(void **)((u8 *)*(void **)((u8 *)anim + 0xE0) + 0x40);
        nSrcBones = *(s32 *)((u8 *)srcTable + 8);
        nDstBones = *(s32 *)((u8 *)dstTable + 8);
    }
    MTXRotDegOrder(
        (u8 *)*(void **)((u8 *)GActor_GetNodeTable(srcActor) + 0xC) + *(s32 *)((u8 *)anim + 0xF0) * 0xF4,
        mtxWorld);
    PSMTXConcat((u8 *)srcActor + 0x10, mtxWorld, mtxWorld);
    PSMTXCopy(mtxWorld, (u8 *)*(void **)((u8 *)anim + 0xE0) + 0x10);
    PSMTXCopy(mtxWorld, (u8 *)*(void **)((u8 *)anim + 0xE4) + 0x10);

    i = 0;
    srcMtxOff = 0;
    srcBone = *(u8 **)((u8 *)*(void **)((u8 *)srcActor + 0x40) + 0xC);
    while (i < nSrcBones) {
        name = *(char **)(srcBone + 0xF0);
        if (!name) {
            srcBwId = -1;
        } else if ((s32)(u8)name[0] != 0x42) {
            srcBwId = -1;
        } else if ((s32)(u8)name[1] != 0x57) {
            srcBwId = -1;
        } else if ((s32)(u8)name[2] != 0x30) {
            srcBwId = -1;
        } else if ((s32)(u8)name[3] != 0x30) {
            srcBwId = -1;
        } else {
            srcBwId = (s8)name[4] - 0x30;
        }
        if (srcBwId >= 0) {
            dstActor = *(void **)((u8 *)anim + 0xE0);
            j = 0;
            dstBone = *(u8 **)((u8 *)*(void **)((u8 *)dstActor + 0x40) + 0xC);
            for (; j < nDstBones; j += 1, dstBone += 0xF4) {
                name = *(char **)(dstBone + 0xF0);
                if (!name) {
                    dstBwId = -1;
                } else if ((s32)(u8)name[0] != 0x42) {
                    dstBwId = -1;
                } else if ((s32)(u8)name[1] != 0x57) {
                    dstBwId = -1;
                } else if ((s32)(u8)name[2] != 0x30) {
                    dstBwId = -1;
                } else if ((s32)(u8)name[3] != 0x30) {
                    dstBwId = -1;
                } else {
                    dstBwId = (s8)name[4] - 0x30;
                }
                if (dstBwId >= 0 && dstBwId == srcBwId) {
                    PSMTXConcat(
                        (u8 *)*(void **)((u8 *)srcActor + 0x60) + srcMtxOff,
                        dstBone + 0x10,
                        (u8 *)*(void **)((u8 *)dstActor + 0x64) + j * 0x30);
                    if (Str_Cmp(*(char **)(srcBone + 0xF0), (char *)(gWeaponAttachStr + 0x6A)) == 0) {
                        found = GActor_FindNode(*(void **)((u8 *)anim + 0xE0), (char *)(gWeaponAttachStr + 0x38));
                        if (found >= 0) {
                            PSMTXConcat((u8 *)*(void **)((u8 *)srcActor + 0x60) + srcMtxOff, dstBone + 0x10, mtxTmpA);
                            dstMtx = (u8 *)*(void **)((u8 *)*(void **)((u8 *)anim + 0xE0) + 0x60) + found * 0x30;
                            PSMTXConcat(mtxTmpA, dstMtx, dstMtx);
                        }
                    }
                    if (Str_Cmp(*(char **)(srcBone + 0xF0), (char *)(gWeaponAttachStr + 0x70)) == 0) {
                        found = GActor_FindNode(*(void **)((u8 *)anim + 0xE0), (char *)(gWeaponAttachStr + 0x4C));
                        if (found >= 0) {
                            PSMTXConcat((u8 *)*(void **)((u8 *)srcActor + 0x60) + srcMtxOff, dstBone + 0x10, mtxTmpB);
                            dstMtx = (u8 *)*(void **)((u8 *)*(void **)((u8 *)anim + 0xE0) + 0x60) + found * 0x30;
                            PSMTXConcat(mtxTmpB, dstMtx, dstMtx);
                        }
                    }
                    break;
                }
            }
        }
        srcMtxOff += 0x30;
        i += 1;
        srcBone += 0xF4;
    }

    fn_8006D378(*(void **)((u8 *)anim + 0xE0));
    fn_800E4A78(*(void **)((u8 *)anim + 0xE4), *(void **)((u8 *)anim + 0xE0));
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

void fn_80198F8C(s32 arg0, s32 arg1) {
    String_Copy(arg0, arg1 + 0x138);
}

void fn_80198FB0(void *arg0) {
    u32 Actor_SetNodeLink(void *, u32, u32, u8);
    s32 fn_8001B9F4(void *);
    void GActor_SetNodeLinkParam(void *, void *);
    extern u32 lbl_802967E0[];
    extern u32 lbl_80296810[];
    s32 sp8;
    u32 result;
    void *p;
    u32 idx;

    idx = *(u32 *)((u8 *)arg0 + 0x124);
    result = Actor_SetNodeLink(arg0, lbl_802967E0[idx], lbl_80296810[idx], 1);
    p = *(void **)((u8 *)arg0 + 0x148);
    if (p != NULL) {
        sp8 = fn_8001B9F4(p);
        GActor_SetNodeLinkParam((void *)result, &sp8);
    }
}

s32 fn_80199028(void *arg0) {
    s32 fn_801518D0(void *, s32);
    void *p = *(void **)((u8 *)arg0 + 0x144);
    if (p != NULL && (u8)fn_801518D0(p, 0x37) != 0) {
        return 1;
    }
    return 0;
}

#include "common.h"
#include "global.h"

extern f32 lbl_8036ADF0;
extern f32 lbl_8036ADF4;
extern u8 lbl_80279C40[];

