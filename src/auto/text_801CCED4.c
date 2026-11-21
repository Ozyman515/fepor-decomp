/* Functions from 0x801B3258 to 0x801E4380, found by decomp-toolkit. */
#include "common.h"
static inline u8 *Battle_FindActiveSideUnit(void) {
    extern u8 gBattle[];
    u8 *unit;
    u8 type;
    unit = *(u8 **)(gBattle + 0x280);
    if (unit) {
        type = (*(u8 **)(unit + 0x190))[8];
        if (type == 0 || type == 5) return unit;
    }
    unit = *(u8 **)(gBattle + 0x560);
    if (unit) {
        type = (*(u8 **)(unit + 0x190))[8];
        if (type == 0 || type == 5) return unit;
    }
    return 0;
}
static inline u8 *MenuResource_FindIn(u8 *p, s32 id) {
s32 i;
for(i=0;i<40;p+=12,i++) { if(id==*(s32*)p) return p; }
return 0;
}
static inline u8 *MenuResource_Find(s32 id) {
extern u8 lbl_80299A78[];
u8 *p=lbl_80299A78;
s32 i;
for(i=0;i<40;i++,p+=12) { if(id==*(s32*)p) return p; }
return 0;
}
#pragma cplusplus on
struct MenuD28 {
virtual s32 v0()=0;
virtual s32 v1()=0;
virtual s32 v2()=0;
virtual s32 v3()=0;
virtual s32 v4()=0;
virtual s32 v5()=0;
virtual s32 v6()=0;
virtual s32 v7()=0;
virtual s32 v8()=0;
virtual s32 v9()=0;
virtual s32 v10()=0;
};
struct UnitHireItem {
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
virtual void v12();
virtual void v13();
virtual void v14();
virtual void v15();
virtual void v16();
virtual void v17();
virtual void set2(s32);
virtual void v19();
virtual void set3(s32);
};
struct UnitHireMenuBase { u32 unknown; };
struct UnitHireMenu : UnitHireMenuBase {
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
virtual void v12();
virtual void v13();
virtual void v14();
virtual UnitHireItem *get(s32);
};
static inline void InitUnitHireWidget(u8 *w) {
    extern u8 lbl_8028FDB0[], lbl_80292230[], lbl_8029186C[];
        *(void **)(w+0) = lbl_8028FDB0;
        *(s32 *)(w+4) = 0;
        *(void **)(w+0) = lbl_80292230;
        *(s16 *)(w+8) = -1;
        *(s16 *)(w+0xA) = 0x260;
        *(s16 *)(w+0xC) = 0x7C;
        *(s16 *)(w+0xE) = 0x368;
        *(s16 *)(w+0x10) = 0x16E;
        *(s16 *)(w+0x12) = 0;
        *(s16 *)(w+0x14) = 0;
        *(s16 *)(w+0x16) = 0x108;
        *(s16 *)(w+0x18) = 0xF2;
        *(s16 *)(w+0x1A) = 0;
        *(s16 *)(w+0x1C) = 0;
        w[0x1E] = 255; w[0x1F] = 255; w[0x20] = 255; w[0x21] = 255;
        *(s16 *)(w+0x22) = 0x1E0;
        *(s16 *)(w+0x24) = 0;
        *(f32 *)(w+0x28) = 1.0f;
        *(f32 *)(w+0x2C) = 1.0f;
        *(f32 *)(w+0x30) = 1.0f;
        *(s32 *)(w+0x34) = 0;
        *(s32 *)(w+0x38) = 0;
        *(void **)(w+0) = lbl_8029186C;
        *(s32 *)(w+0x3C) = 0;
        *(s16 *)(w+0x40) = 20;
        *(s16 *)(w+0x42) = 8;
}
struct UnitHireWidgetFields {
    void *vtable; s32 refcount;
    s16 id, x, y, right, bottom, offX, offY, width, height, scrollX, scrollY;
    u8 color[4]; s16 style, mode; f32 scale[3]; u32 flags, unk38;
    void *entry; s16 unk40, unk42;
};
struct UnitHireWidget {
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void init();
};
#pragma cplusplus reset




typedef struct ParseValue801CB41C { f32 v[8]; } ParseValue801CB41C;
typedef struct String801CB41C { u32 a, b, c; } String801CB41C;

typedef struct Self801CAF94 {
    s32 unk0;
    u8 pad4[0x50];
    s32 unk54;
    u8 pad58[0x14];
    void *unk6C;
    u8 pad70[4];
    s32 unk74;
    s8 unk78;
    s8 unk79;
} Self801CAF94;

void *Process_Create(void *, s32);
void *fn_801BEB9C(void *arg0, s16 *arg1, s16 *arg2, s16 arg3);

typedef struct ListNode {
    struct ListNode *prev;
    struct ListNode *next;
    void *val;
} ListNode;

typedef struct ListIter {
    ListNode *node;
} ListIter;

typedef struct MonitorWin {
    u8 pad0[0x30];
    u32 field30;
} MonitorWin;
typedef MonitorWin Arg801C838C;

typedef struct List {
    s32 size;
} List;

typedef struct UIListObj {
    u8 unk00[0x4E];
    s16 field4E;
    u8 unk50[4];
    s16 field54;
    u8 unk56[0x16];
    u32 count;
    u8 unk70[4];
    void *field74;
} UIListObj;


static inline s32 MsgBoxAddPad(s32 h, s32 pad) {
    return h + pad;
}

void fn_801E00EC(void *arg0, void *arg1);
extern u8 gFxChannels[];
extern u16 gScriptObjSlots[];
extern f32 lbl_8036B4A8;
extern f32 lbl_8027D528[3];
extern f32 lbl_8027D534[3];

typedef struct {
    u8 pad[0xC];
    u32 flags;
} Fn801C797CEnt;

struct Unit {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
    u16 unk1C;
    u16 unk1E;
    u16 unk20;
    u16 unk22;
    u16 unk24;
    u16 unk26;
    u16 unk28;
    u16 unk2A;
    u16 unk2C;
    u16 unk2E;
    u16 unk30;
    u16 unk32;
    u16 unk34;
    u16 unk36;
    u16 unk38;
    u16 unk3A;
    u16 unk3C;
    u16 unk3E;
    u16 unk40;
    u16 unk42;
    u16 unk44;
    u16 unk46;
    u16 unk48;
    u16 unk4A;
    u16 unk4C;
    u16 unk4E;
    u16 unk50;
    u16 unk52;
    u16 unk54;
    u16 unk56;
    u16 unk58;
    u16 unk5A;
    u16 unk5C;
    u16 unk5E;
    u16 unk60;
    u16 unk62;
    u16 unk64;
    u16 unk66;
};

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    u32 unk40;
    u32 unk44;
    u32 unk48;
    u32 unk4C;
    u32 unk50;
    u32 unk54;
    u32 unk58;
    u32 unk5C;
    u32 unk60;
    u32 unk62;
} struct0;


/* Message box: up to 7 text lines, opened/closed through state (0x64/0x6E open, 0xC8/0xD2 close). */
typedef struct MsgBox {
    /* 0x000 */ s16 flags;
    /* 0x002 */ s16 state;
    /* 0x004 */ s16 type;
    /* 0x006 */ u8 unk6[4];
    /* 0x00A */ s16 width;
    /* 0x00C */ s16 height;
    /* 0x00E */ u8 unkE[0x10];
    /* 0x01E */ s16 timer;
    /* 0x020 */ char lines[7][0x41];
    /* 0x1E7 */ s8 numLines;
    /* 0x1E8 */ u8 unk1E8[2];
} MsgBox;

static inline s32 MsgBoxPadHeight(s32 h, s32 pad) {
    return h + pad;
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset

#pragma opt_common_subs off

#pragma opt_common_subs reset

/* Advance the EXP bar fill: lerp displayed EXP, play a tick SE on odd frames, clear when finished. */

#pragma global_optimizer off
#pragma opt_common_subs off

#pragma opt_common_subs reset
#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer reset
#pragma global_optimizer off

#pragma global_optimizer reset

#pragma use_lmw_stmw on

/* Return 1 if every player/faction-5 unit has escaped (stateFlags 0x4000); else 0. */

#pragma use_lmw_stmw reset

/* Count enemy units whose job JID is Priest, Bishop, or Saint. */

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

#pragma opt_common_subs off

extern f32 lbl_8036B228;

#pragma opt_common_subs reset
#pragma opt_loop_invariants off

#pragma opt_loop_invariants reset

/* Apply chapter achievement gold to funds; open bonus tally UI when unlocked. */

#pragma global_optimizer off

#pragma use_lmw_stmw on

#pragma global_optimizer off

#pragma global_optimizer on

/* Focus the unit-manage list on gBattleState's unit, sync portrait/skill widgets, then Process_Goto. */

/* Focus the unit-manage list on gBattleState+0xAC's unit and sync portrait/skill widgets. */

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on
/* Handle unit select-list input: A picks the unit, X opens info, B hides/backs out. */

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus on
#pragma opt_common_subs off

#pragma opt_common_subs reset
#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma cplusplus reset

/* Layout the unit-manage panel: attach list, slide inventory into place, init help cursor, set caption. */

/* Handle unit-manage list input: sync inventory widgets on selection change; A confirms unit, Y/X open side panels, B backs out. */

#pragma cplusplus on

#pragma cplusplus on

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus on
#pragma use_lmw_stmw on
/* Allocate the unit-panel caption and position child widgets, or exit if the panel is not ready. */

#pragma cplusplus off
#pragma use_lmw_stmw reset

#pragma cplusplus reset

#pragma optimization_level 3

#pragma optimization_level reset

#pragma cplusplus on

#pragma cplusplus reset

/* Build the unit-hire panel: caption widget plus list child bound to gUiContext. */

#pragma cplusplus on
/* Handle unit-hire panel input: A buys if affordable, X/Y open side panels, B backs out. */

#pragma cplusplus reset

#pragma cplusplus on
/* Attach cached unit-panel children, size them for the open layout, and set the caption text. */

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus on
/* Destroy a unit panel: release ten refcounted children, run base dtor, optionally free. */

#pragma cplusplus reset

#pragma cplusplus reset

/* Validate skill assign on the unit panel; store error -1/-2/-3 at +4, return 2 on fail or 0. */

/* Menu item for skill assign: draw error popup from item+4, or enter state 0x82. */

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma cplusplus reset

#pragma cplusplus on
#pragma opt_common_subs off
#pragma dont_inline on
#pragma global_optimizer off
#pragma use_lmw_stmw on

#pragma global_optimizer reset
#pragma dont_inline reset
#pragma opt_common_subs reset
#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma optimization_level 3

#pragma optimization_level reset

#pragma cplusplus on

#pragma cplusplus off

#pragma cplusplus off

#pragma cplusplus on
extern "C" void fn_80142060(void *);
extern "C" int fn_801C18E4(void *);
extern "C" void fn_801D2C30(void *);

#pragma cplusplus reset

void Heap_Free(void *);
void *fn_801D2E40(void *, s16);

#pragma global_optimizer off

#pragma global_optimizer off

#pragma global_optimizer on

#pragma cplusplus on

#pragma cplusplus reset

#pragma opt_common_subs off

#pragma use_lmw_stmw on

#pragma opt_common_subs on

extern u8 lbl_8029824C[];

#pragma optimization_level 3

#pragma optimization_level reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma global_optimizer off

#pragma global_optimizer on

#pragma optimization_level 3

#pragma optimization_level reset

/* Copy LightFade source channels onto display lights, release extras, restore fog color. */

#pragma use_lmw_stmw on
/* Fade GX light and fog colors toward the linked unit's target colors over time. */

#pragma use_lmw_stmw reset

extern u32 lbl_8036C510;

extern u8 LightFade_script[];

#pragma use_lmw_stmw on

#pragma cplusplus on

#pragma cplusplus reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
#pragma optimization_level 2
#pragma global_optimizer off
/* Reload CameraWin anim list for a category and set the camChara side mode. */

#pragma global_optimizer reset
#pragma optimization_level reset
#pragma use_lmw_stmw reset

#pragma cplusplus off
/* Construct the ztool CameraWin window and wire its child controls. */

#pragma use_lmw_stmw on
#pragma global_optimizer off
#pragma opt_strength_reduction off
#pragma cplusplus on

#pragma cplusplus reset
#pragma opt_strength_reduction reset
#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer on

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
#pragma opt_common_subs off

#pragma cplusplus reset

#pragma use_lmw_stmw on

#pragma opt_common_subs on
#pragma cplusplus off

#pragma cplusplus on

#pragma global_optimizer off
#pragma peephole off

#pragma peephole on
#pragma global_optimizer reset

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma global_optimizer off
#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma cplusplus reset
#pragma use_lmw_stmw reset
#pragma global_optimizer reset

#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma optimization_level 1

#pragma optimization_level reset
#pragma cplusplus on
#pragma use_lmw_stmw on

extern "C" void fn_801CCED4(s32 *arg0, void *arg1) {
#pragma use_lmw_stmw on
#pragma cplusplus on
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
        virtual s32 v9() = 0;
        virtual s32 v10() = 0;
        virtual s32 v11() = 0;
    };
    s32 *fn_8013F748(void *, s32 *, s16 *);
    s32 spC;
    s16 dims[2];
    s32 w;
    s16 x;
    s16 y;
    Obj *self;
    s32 *out;
    s32 t;
    s32 h;

    x = *(s16 *)((u8 *)arg1 + 0x48);
    out = arg0;
    self = (Obj *)arg1;
    t = self->v11();
    y = (s16)(*(s16 *)((u8 *)self + 0x4A) - t);
    w = self->v9();
    h = self->v10();
    dims[0] = (s16)(x * w);
    dims[1] = (s16)(y * h);
    *out = *fn_8013F748(self, &spC, dims);
#pragma cplusplus reset
}
#pragma cplusplus reset

void *fn_801CCF78(void) {
    extern u16 lbl_8027DD30[];
    return &lbl_8027DD30[0x11];
}

void fn_801CCF88(void *arg0) {
    s16 fn_801CD508(s32);
    s16 fn_801CD548(s32);
#pragma cplusplus on
    class Window {
    public:
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void v3(); virtual void v4(); virtual void v5();
        virtual void v6(); virtual void v7(); virtual void v8();
        virtual s32 width(); virtual s32 height();
    };
    extern s16 lbl_80366EA0;
    extern f32 lbl_8036B4E0;
    s16 sp8;
    s16 *limit;
    s16 rows, width, height;
    s16 x, y;
    sp8 = fn_801CD548(M2C_FIELD(arg0, s32 *, 0x3C));
    rows = fn_801CD508(M2C_FIELD(arg0, s32 *, 0x3C));
    limit = &lbl_80366EA0;
    M2C_FIELD(arg0, s16 *, 0x40) = sp8;
    if (sp8 < lbl_80366EA0) limit = &sp8;
    M2C_FIELD(arg0, s16 *, 0x42) = *limit;
    M2C_FIELD(arg0, s16 *, 0x44) = rows;
    width = M2C_FIELD(arg0, s16 *, 0x44) * ((Window*)arg0)->width() + 0x20;
    height = M2C_FIELD(arg0, s16 *, 0x42) * ((Window*)arg0)->height() + 0x20;
    M2C_FIELD(arg0, s16 *, 0xE) = M2C_FIELD(arg0, s16 *, 0xA) + width;
    M2C_FIELD(arg0, s16 *, 0x10) = M2C_FIELD(arg0, s16 *, 0xC) + height;
    M2C_FIELD(arg0, s16 *, 0x12) = 0x10;
    M2C_FIELD(arg0, s16 *, 0x14) = 0x10;
    M2C_FIELD(arg0, s16 *, 0x16) = width - 0x10;
    M2C_FIELD(arg0, s16 *, 0x18) = height - 0x10;
    M2C_FIELD(arg0, s16 *, 0x6A) = (s16)(M2C_FIELD(arg0,s16*,0x16)-M2C_FIELD(arg0,s16*,0x12)) >> 1;
    M2C_FIELD(arg0, s16 *, 0x6C) = 0;
    M2C_FIELD(arg0, s16 *, 0x6E) = 0;
    x = (s16)(M2C_FIELD(arg0,s16*,0x16)-M2C_FIELD(arg0,s16*,0x12)) >> 1;
    y = M2C_FIELD(arg0,s16*,0x18)-M2C_FIELD(arg0,s16*,0x14);
    M2C_FIELD(arg0, s16 *, 0x92) = x;
    M2C_FIELD(arg0, s16 *, 0x94) = y;
    M2C_FIELD(arg0, s16 *, 0x96) = 0;
    M2C_FIELD(arg0, f32 *, 0x80) = -1.0f;
    M2C_FIELD(arg0, f32 *, 0xA8) = -1.0f;
#pragma cplusplus reset
}

void *fn_801CD0D0(void *arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4)
{
    extern u8 lbl_8028FDB0[];
    extern u8 lbl_80292230[];
    extern u8 gUiPanelEVtbl[];
    extern u8 gEmptyVtbl[];
    extern f32 lbl_8036B4CC;
    extern f32 lbl_8036B4D0;

    u8 *self;
    u8 *sub;
    s32 zero;
    s32 one;
    s32 ff;

    self = (u8 *)arg0;
    zero = 0;
    one = 1;
    ff = 0xFF;

    *(void **)self = lbl_8028FDB0;
    *(s32 *)(self + 4) = zero;
    *(void **)self = lbl_80292230;

    *(s16 *)(self + 0x08) = -1;
    *(s16 *)(self + 0x0A) = arg1;
    *(s16 *)(self + 0x0C) = arg2;
    *(s16 *)(self + 0x0E) = arg1;
    *(s16 *)(self + 0x10) = arg2;
    *(s16 *)(self + 0x12) = zero;
    *(s16 *)(self + 0x14) = zero;
    *(s16 *)(self + 0x16) = zero;
    *(s16 *)(self + 0x18) = zero;
    *(s16 *)(self + 0x1A) = zero;
    *(s16 *)(self + 0x1C) = zero;

    self[0x1E] = ff;
    self[0x1F] = ff;
    self[0x20] = ff;
    self[0x21] = ff;

    *(s16 *)(self + 0x22) = arg3;
    *(s16 *)(self + 0x24) = zero;

    *(f32 *)(self + 0x28) = lbl_8036B4CC;
    *(f32 *)(self + 0x2C) = lbl_8036B4CC;
    *(f32 *)(self + 0x30) = lbl_8036B4CC;

    *(s32 *)(self + 0x34) = zero;
    *(s32 *)(self + 0x38) = zero;

    *(void **)self = gUiPanelEVtbl;
    *(s32 *)(self + 0x3C) = arg4;

    *(s16 *)(self + 0x40) = zero;
    *(s16 *)(self + 0x42) = zero;
    *(s16 *)(self + 0x44) = zero;
    *(s16 *)(self + 0x46) = zero;
    *(s16 *)(self + 0x48) = zero;
    *(s16 *)(self + 0x4A) = zero;
    *(s16 *)(self + 0x4C) = -1;
    *(s16 *)(self + 0x4E) = -1;
    *(f32 *)(self + 0x58) = lbl_8036B4D0;

    sub = self + 0x5C;
    *(void **)sub = gEmptyVtbl;
    *(s32 *)(sub + 0x04) = zero;
    *(s32 *)(sub + 0x08) = 2;
    sub[0x0C] = one;
    sub[0x0D] = one;
    *(s16 *)(sub + 0x14) = zero;
    *(s16 *)(sub + 0x16) = zero;
    *(f32 *)(sub + 0x18) = lbl_8036B4CC;
    *(f32 *)(sub + 0x1C) = lbl_8036B4CC;
    sub[0x20] = ff;
    sub[0x21] = ff;
    sub[0x22] = ff;
    sub[0x23] = ff;
    *(f32 *)(sub + 0x24) = lbl_8036B4D0;

    ((void (*)(void *))(*(void ***)((u8 *)sub))[3])(sub);

    sub = self + 0x84;
    *(void **)sub = gEmptyVtbl;
    *(s32 *)(sub + 0x04) = zero;
    *(s32 *)(sub + 0x08) = 3;
    sub[0x0C] = one;
    sub[0x0D] = one;
    *(s16 *)(sub + 0x14) = zero;
    *(s16 *)(sub + 0x16) = zero;
    *(f32 *)(sub + 0x18) = lbl_8036B4CC;
    *(f32 *)(sub + 0x1C) = lbl_8036B4CC;
    sub[0x20] = ff;
    sub[0x21] = ff;
    sub[0x22] = ff;
    sub[0x23] = ff;
    *(f32 *)(sub + 0x24) = lbl_8036B4D0;

    ((void (*)(void *))(*(void ***)sub)[3])(sub);
    ((void (*)(void *))(*(void ***)self)[10])(self);

    return self;
}

#pragma cplusplus on
extern "C" void fn_801CD2AC(void *arg0) {
    void fn_80158DD8(s32, s32, s16, s16, s32, s32);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    ((Obj *)arg0)->v2();
    fn_80158DD8(0, 0,
        (s16)(*(s16 *)((u8 *)arg0 + 0xE) - *(s16 *)((u8 *)arg0 + 0xA)),
        (s16)(*(s16 *)((u8 *)arg0 + 0x10) - *(s16 *)((u8 *)arg0 + 0xC)),
        0xFF, 0x10);
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void *Ui_DtorPanelE(void *self, s16 doFree) {
    /* C++ destructor for UI panel E (gUiPanelEVtbl): destroy embeds, chain base vtors, optional free. */
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    struct Owner {
        void *vtbl;
        u8 pad4[0x58];
        void *sub5c;
        u8 pad60[0x24];
        void *sub84;
    };
    void Heap_Free(void *);
    extern u8 gUiPanelEVtbl[];
    extern u8 gEmptyVtbl[];
    extern u8 lbl_80292230[];
    extern u8 lbl_8028FDB0[];
    Owner *owner;

    owner = (Owner *)self;
    if (self != NULL) {
        owner->vtbl = gUiPanelEVtbl;
        if (&owner->sub84 != NULL) {
            owner->sub84 = gEmptyVtbl;
            ((Obj *)&owner->sub84)->v2();
        }
        if (&owner->sub5c != NULL) {
            owner->sub5c = gEmptyVtbl;
            ((Obj *)&owner->sub5c)->v2();
        }
        if (self != NULL) {
            owner->vtbl = lbl_80292230;
            if (self != NULL) {
                owner->vtbl = lbl_8028FDB0;
            }
        }
        if (doFree > 0) {
            Heap_Free(self);
        }
    }
    return self;
}
#pragma cplusplus reset
s32 fn_801CD3E4(void) {
    return 0x24;
}

s32 fn_801CD3EC(void) {
    return 0x24;
}

s16 fn_801CD3F4(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x46);
}

s16 fn_801CD3FC(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x42);
}

s16 fn_801CD404(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x44);
}

s16 fn_801CD40C(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x40);
}

void *fn_801CD414(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_80298498[];
    extern void *lbl_80292230[];
    extern void *lbl_8028FDB0[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_80298498;
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
s32 fn_801CD480(s32 arg0, s32 arg1, s32 arg2) {
extern u8 *lbl_802984C0[];
extern char lbl_8027DD60[];
s32 count=0;
u8 **table=(u8**)count;

u8 *result;
switch(arg0) {case 0: table=lbl_802984C0; break;}
while((s32)**table!=10) {table++;count++;}
count=(s16)(count+1);
table=0;
switch(arg0) {case 0: table=lbl_802984C0;break;}
result=table[(s16)arg1+count*(s16)arg2];
if(result) return (s32)result;
return (s32)(lbl_8027DD60+0x16);
}
#pragma global_optimizer reset
s32 fn_801CD508(s32 arg0) {
    extern u8 *lbl_802984C0[];
    s32 count = 0;
    u8 **table = 0;
    u8 **p;
    switch (arg0) {
    case 0: table = lbl_802984C0; break;
    }
    p = table;
    while ((s32)**p != 10) { ++p; ++count; }
    return count;
}

#pragma opt_propagation on
#pragma global_optimizer on
s32 fn_801CD548(s32 arg0) {
    extern u8 *lbl_802984C0[];
    s32 count;
    u8 **table;
    s32 n;
    s16 stride;
    s32 step;
    u8 **tmp;
    u8 **cur;

    count = 0;
    table = (u8 **)count;
    n = 0;

    switch(arg0) { case 0: table=lbl_802984C0; break; }
    goto search;

loop1:
    table += 1;
    count += 1;
search:
    if ((s32)**table != 0xA) {
        goto loop1;
    }

    stride = (s16)(count + 1);
    tmp = (u8 **)0;

    switch(arg0) {case 0: tmp=lbl_802984C0;break;}

    cur = tmp;
    step = stride << 2;
    goto check;
loop2:
    cur = (u8 **)((u8 *)cur + step);
    n += 1;
check:
    if (*cur != NULL) {
        goto loop2;
    }
    return n;
}
#pragma global_optimizer reset
#pragma opt_propagation reset
void fn_801CD5CC(void *self) {
extern u32 gUiInputFlags; extern u8 *gPadInput; extern s16 lbl_80366EA8,lbl_80366EAA; extern u8 lbl_8027DE18[];
void Ui_PlaySeCue(void*,s32);
u32 pressed;
s16 lim,old;
u32 *p;
s32 i;
s16 *cap;
s32 v;
u32 flags;
u8 gate;
u32 input;
flags=gUiInputFlags;gate=0;
if((flags&0x10) && !(flags&0x20)) gate=1;
if(gate) return;
input=*(u32*)(gPadInput+0xc);
pressed=*(u32*)(gPadInput+4) & (*(u32*)(gPadInput+8)^*(u32*)(gPadInput+4));
if(input&0x11000041) {
s16 count;

p=(u32*)((u8*)self+0x3c);i=0;while(*p) {p++;i++;}
count=(s16)i; cap=&count;
if(lbl_80366EA8<(s16)i) cap=&lbl_80366EA8;
lim=*cap;old=*(s16*)((u8*)self+0x70);
v=old-1;
*(s16*)((u8*)self+0x70)=v;
if((s16)v<0) *(s16*)((u8*)self+0x70)=input==pressed?lim:0;
if(old!=*(s16*)((u8*)self+0x70)) Ui_PlaySeCue(lbl_8027DE18+8,0x64);
} else if(input&0x22000022) {
s16 count;

p=(u32*)((u8*)self+0x3c);i=0;while(*p) {p++;i++;}
count=(s16)i; cap=&count;
if(lbl_80366EAA<(s16)i) cap=&lbl_80366EAA;
lim=*cap;old=*(s16*)((u8*)self+0x70);
v=old+1;
*(s16*)((u8*)self+0x70)=v;
if((u32)(s16)v>(u32)lim) *(s16*)((u8*)self+0x70)=input==pressed?0:lim;
if(old!=*(s16*)((u8*)self+0x70)) Ui_PlaySeCue(lbl_8027DE18+8,0x64);
}
}

#pragma cplusplus on
#pragma use_lmw_stmw on
#pragma optimization_level 2
#pragma global_optimizer off
extern "C" void fn_801CD764(u8 *self) {
void Prim2D_Begin(); void Prim2D_AddZ(f32); void Prim2D_PrepareTex();
void Ui_DrawLine(s16,s16,s16,s16,s32,u8*);
extern f32 lbl_8036B4E8;
u8 color[4];
s16 target; s32 old;
s32 x,y; s16 x2,y2;
((MenuD28*)self)->v3();
target=*(s16*)(self+0x70)*0x16;
if(*(s32*)(self+0x78)!=0) target+=0x18;
old=*(s16*)(self+0x72);
if((s16)old<0 || *(s16*)(self+0x74)<0) { *(s16*)(self+0x72)=target; *(s16*)(self+0x74)=0; }
else {
*(s16*)(self+0x72)=(old+(target+1))>>1;
*(s16*)(self+0x74)=(*(s16*)(self+0x74)+1)>>1;
}
x=*(s16*)(self+0x72); y=*(s16*)(self+0x74);
Prim2D_Begin(); Prim2D_AddZ(lbl_8036B4E8); Prim2D_PrepareTex();
color[0]=0x9c; x2=(s16)(x+0x16); y2=(s16)(y+0x20); color[1]=0x2f; color[2]=0x12; color[3]=0xff;
Ui_DrawLine((s16)x,(s16)(y-1),x2,(s16)(y-1),*(s32*)(self+0x34),color);
Ui_DrawLine((s16)x,(s16)y2,x2,(s16)y2,*(s32*)(self+0x34),color);
Ui_DrawLine((s16)(x-1),(s16)y,(s16)(x-1),(s16)y2,*(s32*)(self+0x34),color);
Ui_DrawLine(x2,(s16)y,x2,(s16)y2,*(s32*)(self+0x34),color);
Ui_DrawLine((s16)x,(s16)y,x2,(s16)y,*(s32*)(self+0x34),color);
Ui_DrawLine((s16)x,(s16)(y2-1),x2,(s16)(y2-1),*(s32*)(self+0x34),color);
Ui_DrawLine((s16)x,(s16)y,(s16)x,(s16)y2,*(s32*)(self+0x34),color);
Ui_DrawLine((s16)(x2-1),(s16)y,(s16)(x2-1),(s16)y2,*(s32*)(self+0x34),color);
}
#pragma optimization_level reset
#pragma global_optimizer reset
#pragma use_lmw_stmw reset
#pragma cplusplus off
extern struct efUnit* gEfUnitArray;
void fn_801CD940(void *arg0, void *arg1)
{
    void fn_801583D0(s16, s16, s32, s32, u8, s32);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    s32 Text_MeasureHeight(s32, f32);
    s32 fn_8001059C(u8 *, s32, f32);
    void Ui_DrawIcon(void *, s32, s32, s32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetTextScale(u8, f32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);

    extern u8 gUiIconDrawer[];
    extern f32 lbl_8036B4EC;
    extern f32 lbl_8036B4F0;
    extern f32 lbl_8036B4F4;

    u8 *self;
    u8 *str;
    void **vtable;
    s32 offset;
    s32 width;
    s16 y;
    s16 xOffset;
    s32 x;

    self = (u8 *)arg0;

    vtable = *(void ***)self;
    ((void (*)(void *))vtable[4])(self);

    fn_801583D0(
        0,
        0,
        (s16)(*(s16 *)(self + 0xE) -
              *(s16 *)(self + 0xA)),
        (s16)(*(s16 *)(self + 0x10) -
              *(s16 *)(self + 0xC)),
        0xFF,
        0x10
    );

    vtable = *(void ***)self;
    ((void (*)(void *, void *))vtable[5])(self, arg1);

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B4EC);
    Prim2D_PrepareTex();

    y = (s16)((0x20 -
        Text_MeasureHeight(-1, lbl_8036B4F0)) >> 1);

    offset = 0;

    if (*(s32 *)(self + 0x78) != 0) {
        Ui_DrawIcon(
            gUiIconDrawer,
            0,
            4,
            *(s32 *)(self + 0x78)
        );

        offset = 0x18;
    }

    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();

    str = self + 0x3C;

    while (*(u32 *)str != 0) {
        width = fn_8001059C(
            str,
            -1,
            lbl_8036B4F0
        );

        xOffset = (s16)((0x16 - width) >> 1);

        Prim2D_AddPrim(6);

        x = (s16)offset + xOffset;

        Prim2D_SetPos(
            (f32)x,
            (f32)y
        );

        Prim2D_SetTextScale(
            1,
            lbl_8036B4F4
        );

        Prim2D_SetText(str);
        Prim2D_EndPrim();

        str += 4;
        offset += 0x16;
    }
}

void *NameEntry_InsertChar(void *a, u8 *b) {
    u8 *self;
    u8 c;
    u8 *p;
    u8 is_double;
    u8 d;
    u8 t0;
    u8 t1;
    s32 n;

    self = a;
    c = b[0];
    n = *(s16 *)(self + 0x70);
    p = self + n * 4 + 0x3c;
    *(u32 *)p = 0;

    if ((c >= 0x81U && c <= 0x9FU) || (c >= 0xE0U && c <= 0xFCU)) {
        d = b[1];
        if ((d >= 0x40U && d <= 0x7EU) || (d >= 0x80U && d <= 0xFCU)) {
            is_double = 1;
        } else {
            goto not_double;
        }
    } else {
    not_double:
        is_double = 0;
    }

    if (is_double != 0) {
        t0 = b[0];
        t1 = b[1];
        p[0] = t0;
        p[1] = t1;
    } else {
        p[0] = b[0];
    }

    return self + *(s16 *)(self + 0x70) * 4 + 0x3c;
}

#pragma opt_unroll off
void *fn_801CDB74(void *arg0) {
    s32 i;
    u32 *p;
    s16 count;
    s32 n;
    u32 chunks;

    i = 0;
    p = (u32 *)((u8 *)arg0 + 0x3C);
    while (*p != 0) {
        i++;
        p++;
    }
    count = *(s16 *)((u8 *)arg0 + 0x70);
    i = (s16)i;
    if ((u32)i == (u32)count) {
        return (u8 *)arg0 + ((s32)count * 4) + 0x3C;
    }
    p = (u32 *)((u8 *)arg0 + ((s32)count * 4) + 0x3C);
    n = i - count;
    if ((u32)count < (u32)i) {
        chunks = (u32)n >> 3;
        if (chunks != 0) {
            do {
                p[0] = p[1];
                p[1] = p[2];
                p[2] = p[3];
                p[3] = p[4];
                p[4] = p[5];
                p[5] = p[6];
                p[6] = p[7];
                p[7] = p[8];
                p += 8;
            } while (--chunks);
        }
        n &= 7;
        if (n != 0) {
            do {
                p[0] = p[1];
                p++;
            } while (--n);
        }
    }
    return (u8 *)arg0 + ((s32)*(s16 *)((u8 *)arg0 + 0x70) * 4) + 0x3C;
}
#pragma opt_unroll reset
s16 NameEntry_MoveCaretRight(void *self, u8 flag) {
    extern s16 lbl_80366EAA;
    extern u8 lbl_8027DE18[];
    void Ui_PlaySeCue(void *, s32);
    s16 sp8;
    s16 *cap;
    register s32 i;
    u32 *p;
    s16 old;
    s16 lim;
    s32 v;

    for (i = 0, p = (u32 *)((u8 *)self + 0x3c); *p != 0; i++, p++) {
    }
    sp8 = (s16)i;
    cap = &sp8;
    if (lbl_80366EAA < (s16)i) {
        cap = &lbl_80366EAA;
    }
    old = *(s16 *)((u8 *)self + 0x70);
    lim = *cap;
    v = old + 1;
    *(s16 *)((u8 *)self + 0x70) = (s16)v;
    if ((u32)(s16)v > (u32)lim) {
        *(s16 *)((u8 *)self + 0x70) = lim & ~(((-(s32)flag) | (s32)flag) >> 31);
    }
    if (old != *(s16 *)((u8 *)self + 0x70)) {
        Ui_PlaySeCue(lbl_8027DE18 + 8, 0x64);
    }
    return *(s16 *)((u8 *)self + 0x70);
}

s16 NameEntry_MoveCaretLeft(void *self, u8 flag) {
    extern s16 lbl_80366EA8;
    extern u8 lbl_8027DE18[];
    void Ui_PlaySeCue(void *, s32);
    s16 sp8;
    s16 *cap;
    s32 i;
    u32 *p;
    s16 old;
    s16 lim;
    s16 v;

    i = 0;
    p = (u32 *)((u8 *)self + 0x3c);
    while (*p != 0) {
        i += 1;
        p += 1;
    }
    sp8 = (s16)i;
    cap = &sp8;
    if (lbl_80366EA8 < (s16)i) {
        cap = &lbl_80366EA8;
    }
    old = *(s16 *)((u8 *)self + 0x70);
    lim = *cap;
    v = (s16)(old - 1);
    *(s16 *)((u8 *)self + 0x70) = v;
    if (v < 0) {
        *(s16 *)((u8 *)self + 0x70) = (s16)(lim & (((-(s32)flag) | (s32)flag) >> 31));
    }
    if (old != *(s16 *)((u8 *)self + 0x70)) {
        Ui_PlaySeCue(lbl_8027DE18 + 8, 0x64);
    }
    return *(s16 *)((u8 *)self + 0x70);
}

void fn_801CDDC8(void *arg0, char *arg1) {
    s32 strlen(char *);
    void strcat(char *, char *);

    char *var_r31;

    var_r31 = (char *)arg0 + 0x3C;
    *arg1 = 0;
    while (*(u32 *)var_r31 != 0) {
        strlen(var_r31);
        strcat(arg1, var_r31);
        var_r31 += 4;
    }
}

#pragma global_optimizer off
void fn_801CDE2C(void *self, u8 *str) {
    s32 fn_80010710(u8 *);
    void *memset(void *, int, unsigned long);
    u8 *p;
    u8 *dest;
    s32 count;
    u8 b0;
    u8 b1;
    u8 isSjis;

    p = str;
    dest = (u8 *)self + 0x3c;
    memset(dest, 0, 0x34);
    count = 0;
    goto check;
body:
    p += fn_80010710(p);
    if ((s8)*p == 0) {
        goto done;
    }
    b0 = *(volatile u8 *)p;
    if (b0 < 0x81U) {
        goto not_sjis;
    }
    if (b0 > 0x9FU) {
        if (b0 < 0xE0U) {
            goto not_sjis;
        }
        if (b0 > 0xFCU) {
            goto not_sjis;
        }
    }
    b1 = p[1];
    if (b1 < 0x40U) {
        goto not_sjis;
    }
    if (b1 > 0x7EU) {
        if (b1 < 0x80U) {
            goto not_sjis;
        }
        if (b1 > 0xFCU) {
            goto not_sjis;
        }
    }
    isSjis = 1;
    goto after_sjis;
not_sjis:
    isSjis = 0;
after_sjis:
    if (isSjis != 0) {
        b0 = p[0];
        b1 = p[1];
        p += 2;
        dest[0] = b0;
        dest[1] = b1;
        dest += 4;
    } else {
        b0 = p[0];
        p += 1;
        dest[0] = b0;
        dest += 4;
    }
    count += 1;
check:
    if ((s8)*p == 0) {
        goto done;
    }
    if ((u32)count < 0xCU) {
        goto body;
    }
done:
    *(s16 *)((u8 *)self + 0x70) = 0;
    *(s16 *)((u8 *)self + 0x72) = -1;
    *(s16 *)((u8 *)self + 0x74) = -1;
}
#pragma global_optimizer on
void *fn_801CDF5C(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_80298678[];
    extern void *lbl_80292230[];
    extern void *lbl_8028FDB0[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_80298678;
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

void fn_801CDFC8(void *arg0)
{
  s16 *p;
  s32 pad;
  s16 ten;
  s16 eight;
  s16 c;
  s16 t10;
  s16 a;
  s16 e;
  s16 diff_v;
  s16 diff_h;
  s16 tmp;
  s32 half;
  p = (s16 *) arg0;
  pad = 0x128;
  if ((*((s32 *) (((u8 *) arg0) + 0x78))) != 0)
  {
    pad = 0x140;
  }
  ten = 0x10;
  eight = 8;
  p[0xE / 2] = p[0xA / 2] + pad;
  c = p[0xC / 2];
  t10 = p[0x10 / 2];
  tmp = t10 - c;
  a = p[0xA / 2];
  e = p[0xE / 2];
  diff_v = tmp;
  p[0x12 / 2] = ten;
  diff_h = e - a;
  tmp = diff_v - 8;
  p[0x14 / 2] = eight;
  p[0x16 / 2] = diff_h - 0x10;
  p[0x18 / 2] = tmp;
  a = p[0xA / 2];
  e = p[0xE / 2];
  c = p[0xC / 2];
  diff_h = e - a;
  a = (0x200 - diff_h) >> 1;
  half = a;
  p[0xE / 2] = ((s16) half) + diff_h;
  p[0xA / 2] = half;
  p[0x10 / 2] = c + ((s16) (p[0x10 / 2] - p[0xC / 2]));
}

void *fn_801CE070(s32 a,char*b,s32 c){void *Process_CreateChild(void*,s32);void fn_801403F0(void);void String_AssignCStr(void*,char*,s32);extern u8 lbl_802986A8[];void*p=Process_CreateChild(lbl_802986A8,c);if(p){fn_801403F0();*(s32*)((char*)p+0x40)=0;*(s32*)((char*)p+0x44)=0;*(s32*)((char*)p+0x4c)=0;*(s32*)((char*)p+0x50)=0;*(s32*)((char*)p+0x54)=0;*(s32*)((char*)p+0x58)=0;*(s32*)((char*)p+0x5c)=0;*(s32*)((char*)p+0x58)=0;*(s32*)((char*)p+0x48)=0;}*(s32*)((char*)p+0x4c)=0;*(s32*)((char*)p+0x50)=a;String_AssignCStr((char*)p+0x54,b,strlen(b));return p;}

void *fn_801CE11C(s32 arg0,char *arg1,s32 arg2,s32 arg3) {
void *Process_CreateChild(void*,s32); void fn_801403F0(void); void String_AssignCStr(void*,char*,s32); extern u8 lbl_802986A8[];
void *p=Process_CreateChild(lbl_802986A8,arg3);
if(p){fn_801403F0();*(s32*)((char*)p+0x40)=0;*(s32*)((char*)p+0x44)=0;*(s32*)((char*)p+0x4c)=0;*(s32*)((char*)p+0x50)=0;*(s32*)((char*)p+0x54)=0;*(s32*)((char*)p+0x58)=0;*(s32*)((char*)p+0x5c)=0;*(s32*)((char*)p+0x58)=0;*(s32*)((char*)p+0x48)=0;}
*(s32*)((char*)p+0x4c)=arg2;*(s32*)((char*)p+0x50)=arg0;String_AssignCStr((char*)p+0x54,arg1,strlen(arg1));return p;
}

void fn_801CE1D0(void *arg0) {
    void String_Destroy(void *, s32);
    void Ui_DtorPanelBase(void *, s32);

    u8 *self;
    u8 *obj;
    void (**vtable)(void *, s32);
    s32 count;
    s32 zero;

    self = (u8 *)arg0;

    if (self != NULL) {
        obj = *(u8 **)(self + 0x40);

        if (obj != NULL) {
            count = *(s32 *)(obj + 4) - 1;
            *(s32 *)(obj + 4) = count;

            if (count == 0 && obj != NULL) {
                vtable = *(void (***)(void *, s32))obj;
                vtable[2](obj, 1);
            }
        }

        *(void **)(self + 0x40) = NULL;

        obj = *(u8 **)(self + 0x44);

        if (obj != NULL) {
            count = *(s32 *)(obj + 4) - 1;
            *(s32 *)(obj + 4) = count;

            if (count == 0 && obj != NULL) {
                vtable = *(void (***)(void *, s32))obj;
                vtable[2](obj, 1);
            }
        }

        *(void **)(self + 0x44) = NULL;

        obj = *(u8 **)(self + 0x48);
        zero = 0;

        if (obj != NULL) {
            count = *(s32 *)(obj + 4) - 1;
            *(s32 *)(obj + 4) = count;

            if (count == 0 && obj != NULL) {
                vtable = *(void (***)(void *, s32))obj;
                vtable[2](obj, 1);
            }
        }

        *(s32 *)(self + 0x48) = zero;

        String_Destroy(self + 0x54, -1);
        Ui_DtorPanelBase(self, 0);
    }
}

void fn_801CE2DC(void *arg0) {
    void *Ui_FindChild(void *, s32, s32);
    void Ui_CloseChildAnim(void *, void *, s32);
    void *self;

    self = arg0;
    Ui_CloseChildAnim(self, Ui_FindChild(self, 3, 0), 0);
    Ui_CloseChildAnim(self, Ui_FindChild(self, 2, 0), 0);
    Ui_CloseChildAnim(self, Ui_FindChild(self, 1, 0), 0);
    Ui_CloseChildAnim(self, Ui_FindChild(self, 0, 0), 1);
}

#pragma cplusplus on
#pragma opt_common_subs off
extern "C" void Ui_HandleNameEntryInput(void *arg0) {
/* Handle name-entry input: A insert char, L/R move caret, Start confirm, Y info, B back. */
void *Ui_FindChild(void *,s32,s32); u32 NameGrid_GetCharAtCursor(void *); void Ui_UpdatePanelWidgets(void *);
u8 Ui_IsUnitInfoPopupOpen(void *); void Ui_ShowUnitInfoText(void *,s32,f32,f32); void Ui_OpenUnitInfoText(void *,void *,s32,f32,f32); void Ui_HideUnitInfoPopup(void *);
void NameEntry_InsertChar(void *,u32); void NameEntry_MoveCaretRight(void *,s32); void NameEntry_MoveCaretLeft(void *,s32);
void Ui_PlaySeCue(void *,s32); void Process_ClearFunc(void *);
void fn_8013F748(void *,void *,void *); s16 *fn_8013F6B8(void *,void *,void *);
extern u8 gUnitInfoPopup[],lbl_8027DE48[]; extern void *gPadInput; extern const s32 gUnitInfoPopupFlag;
class Pair { public: s16 x,y; Pair() {} Pair(const Pair &o) { *(u32 *)this=*(u32 *)&o; } Pair &operator=(const Pair &o) { *(u32 *)this=*(u32 *)&o; return *this; } };
struct Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual s32 v15(); virtual Pair v16(); };
u32 pos1,pos2,pos3,pos4;
s32 btn;
void *field,*entry,*grid;
u32 ch;
s32 held;
s16 *xy;
field=Ui_FindChild(arg0,0,0);
entry=Ui_FindChild(arg0,1,0);
grid=Ui_FindChild(arg0,2,0);
ch=NameGrid_GetCharAtCursor(grid);
Ui_UpdatePanelWidgets(arg0);
if(ch!=NameGrid_GetCharAtCursor(grid)) {
ch=NameGrid_GetCharAtCursor(grid);
if(Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
*(Pair *)&pos1=((Obj *)grid)->v16();
Ui_ShowUnitInfoText(gUnitInfoPopup,((Obj *)grid)->v15(),(f32)*(s16 *)&pos1,(f32)*((s16 *)&pos1+1));
}
}
held=M2C_FIELD(gPadInput,s32 *,4);
btn=held&(M2C_FIELD(gPadInput,s32 *,8)^held);
if((btn&0x100)&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
NameEntry_InsertChar(entry,ch);NameEntry_MoveCaretRight(entry,0);Ui_PlaySeCue(lbl_8027DE48+0x1e,100);
} else if((btn&0x10000040)&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
NameEntry_MoveCaretLeft(entry,0);
} else if((btn&0x20000020)&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
NameEntry_MoveCaretRight(entry,0);
} else if((btn&0x1000)&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
M2C_FIELD(field,s16 *,0x3c)=3;
pos2=M2C_FIELD(grid,u32 *,0x4c);
fn_8013F748(grid,&pos2,&pos2);
xy=fn_8013F6B8(field,&pos2,&pos2);
M2C_FIELD(field,s16 *,0x3e)=xy[0];M2C_FIELD(field,s16 *,0x40)=xy[1];
Process_ClearFunc(arg0);Ui_PlaySeCue(lbl_8027DE48+0x1e,100);
} else if((btn&0x800)&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
*(Pair *)&pos3=((Obj *)grid)->v16();
Ui_OpenUnitInfoText(gUnitInfoPopup,arg0,((Obj *)grid)->v15(),(f32)*(s16 *)&pos3,(f32)*((s16 *)&pos3+1));
*(s32 *)gUnitInfoPopup|=gUnitInfoPopupFlag;
} else if((btn&0xa00)&&Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
Ui_HideUnitInfoPopup(gUnitInfoPopup);
} else if((btn&0x200)&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
pos4=M2C_FIELD(grid,u32 *,0x4c);
fn_8013F748(grid,&pos4,&pos4);
xy=fn_8013F6B8(field,&pos4,&pos4);
M2C_FIELD(field,s16 *,0x3e)=xy[0];M2C_FIELD(field,s16 *,0x40)=xy[1];
Process_ClearFunc(arg0);Ui_PlaySeCue(lbl_8027DE48+0x2e,100);
}
}
#pragma opt_common_subs on
#pragma cplusplus off

void fn_801CE744(s32 arg0) {
    void *Ui_FindChild(s32, s32, s32);
    void *fn_8013F6B8(void *, s32 *, s32 *);
    void fn_8013F748(void *, s32 *, s32 *);
    void Ui_BringChildToFront(s32, void *);
    void *base;
    void *obj;
    s32 tmp;

    base = Ui_FindChild(arg0, 0, 0);
    obj = Ui_FindChild(arg0, 2, 0);
    tmp = *(s32 *)((u8 *)base + 0x3E);
    fn_8013F748(base, &tmp, &tmp);
    base = obj;
    obj = fn_8013F6B8(base, &tmp, &tmp);
    *(s16 *)((u8 *)base + 0x4C) = *(s16 *)obj;
    *(s16 *)((u8 *)base + 0x4E) = *(s16 *)((u8 *)obj + 2);
    Ui_BringChildToFront(arg0, Ui_FindChild(arg0, 2, 0));
}

#pragma cplusplus on
extern "C" void fn_801CE7F4(void *arg0) {
void *Ui_FindChild(void *,s32,s32);
s16 fn_801CF614(void *);
void Ui_BringChildToFront(void *,void *);
void Ui_AddChild(void *,void *);
void Ui_CloseChildAnim(void *,void *,s32);
void Ui_OpenChildAnim(void *,void *,s32);
u8 Ui_IsUnitInfoPopupOpen(void *);
void Ui_ShowUnitInfoText(void *,s32,f32,f32);
void Ui_OpenUnitInfoText(void *,void *,s32,f32,f32);
void Ui_HideUnitInfoPopup(void *);
void fn_801CDB74(void *);
void fn_801CDDC8(void *,s32);
void fn_801CDE2C(void *,s32);
s32 String_CStr(void *);
void Ui_PlaySeCue(void *,s32);
void Process_ClearFunc(void *);
void Process_Goto(void *,s32);
extern u8 gUnitInfoPopup[],lbl_8027DE48[],gUiContext[];
extern u32 gUiInputFlags;
extern void *gPadInput;
extern const s32 gUnitInfoPopupFlag;
class Pair { public: s16 x,y; Pair() {} Pair(const Pair &o) { *(u32 *)this=*(u32 *)&o; } Pair &operator=(const Pair &o) { *(u32 *)this=*(u32 *)&o; return *this; } };
struct Obj {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6();
 virtual void v7(void *);
 virtual s32 v8(); virtual Pair v9();
};
u32 pos1,pos3;
s32 btn,t;
u8 gate;
u32 flags;
u16 saved;
void *a,*b,*c;
s32 idx;
s32 addr;
a=Ui_FindChild(arg0,0,0);
b=Ui_FindChild(arg0,1,0);
c=Ui_FindChild(arg0,2,0);
saved=*(u16 *)((u8 *)a+0x3c);
((Obj *)a)->v7(arg0);
((Obj *)b)->v7(arg0);
if((s16)saved!=*(s16 *)((u8 *)a+0x3c)) {
 if(Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
  *(Pair *)&pos1=((Obj *)a)->v9();
  Ui_ShowUnitInfoText(gUnitInfoPopup,((Obj *)a)->v8(),(f32)*(s16 *)&pos1,(f32)*((s16 *)&pos1+1));
 } else if(fn_801CF614(a)>=0) {
  idx=fn_801CF614(a);
  addr=(s32)arg0+(idx<<2);
  if(c!=*(void **)(addr+0x48)) {
   if(c!=0) Ui_CloseChildAnim(arg0,c,0);
   idx=fn_801CF614(a);
   addr=(s32)arg0+(idx<<2);
   Ui_AddChild(arg0,*(void **)(addr+0x48));
   idx=fn_801CF614(a);
   addr=(s32)arg0+(idx<<2);
   Ui_OpenChildAnim(arg0,*(void **)(addr+0x48),1);
   Ui_BringChildToFront(arg0,a);
  }
 }
}
gate=0;
flags=gUiInputFlags;
if(flags&0x10) {
 if(!(flags&0x20)) gate=1;
}
if(gate==0) {
 t=M2C_FIELD(gPadInput,s32 *,4);
 btn=t&(M2C_FIELD(gPadInput,s32 *,8)^t);
 if((btn&0x100)&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
  if(fn_801CF614(a)>=0) {
   Process_ClearFunc(arg0);
  } else {
   switch(*(s16 *)((u8 *)a+0x3c)) {
   case 1: fn_801CDB74(b); break;
   case 2: fn_801CDE2C(b,String_CStr((u8 *)arg0+0x54)); break;
   case 3: fn_801CDDC8(b,*(s32 *)((u8 *)arg0+0x50)); Process_Goto(arg0,5); break;
   }
  }
  Ui_PlaySeCue(lbl_8027DE48+0x1e,0x64);
 } else if((btn&0x1000)&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
  *(s16 *)((u8 *)a+0x3c)=3;
  Ui_PlaySeCue(lbl_8027DE48+0x1e,0x64);
 } else if((btn&0x800)&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
  *(Pair *)&pos3=((Obj *)a)->v9();
  Ui_OpenUnitInfoText(gUnitInfoPopup,arg0,((Obj *)a)->v8(),(f32)*(s16 *)&pos3,(f32)*((s16 *)&pos3+1));
  *(s32 *)gUnitInfoPopup|=gUnitInfoPopupFlag;
 } else if((btn&0xa00)&&Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
  Ui_HideUnitInfoPopup(gUnitInfoPopup);
 } else if((btn&0x200)&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
  gUiContext[8]=0;
  Process_Goto(arg0,5);
  Ui_PlaySeCue(lbl_8027DE48+0x2e,0x64);
 }
}
}
#pragma cplusplus reset

void fn_801CEC28(void *arg0) {
    void Ui_BringChildToFront(void *, void *);
    void *Ui_FindChild(void *, s32, s32);

    Ui_BringChildToFront(arg0, Ui_FindChild(arg0, 0, 0));
}

#pragma cplusplus on
extern "C" void fn_801CEC68(void *arg0) {
    void *Heap_Alloc(s32);
    void *fn_801CF62C(void *,s16,s16,s16);
    void *fn_801CD0D0(void *,s16,s16,s16,s32);
    void Ui_AddChild(void *,void *);
    void Ui_BringChildToFront(void *,void *);
    void Ui_OpenChildAnim(void *,void *,s32);
    void fn_801CDE2C(void *,s32);
    extern u8 gUiContext[];
    extern void *lbl_8028FDB0[],*lbl_80292230[],*lbl_80298498[],*lbl_80298678[];
    extern const f32 lbl_8036B508;
    struct Obj {
        virtual void v0()=0;
        virtual void v1()=0;
        virtual void v2()=0;
        virtual void v3()=0;
        virtual void v4()=0;
        virtual void v5()=0;
        virtual void v6()=0;
        virtual void v7()=0;
        virtual void v8()=0;
    };
    u8 *p;
    u8 *self=(u8 *)arg0;
    u8 *child;
    void *created;
    *(u8 *)(gUiContext+8)=0xF;
    p=(u8 *)Heap_Alloc(0x3C);
    if(p) {
        *(void **)p=lbl_8028FDB0;
        *(s32 *)(p+4)=0;
        *(void **)p=lbl_80292230;
        *(s16 *)(p+0x8)=-1;
        *(s16 *)(p+0xa)=0x18;
        *(s16 *)(p+0xc)=0x80;
        *(s16 *)(p+0xe)=0x248;
        *(s16 *)(p+0x10)=0x198;
        *(s16 *)(p+0x12)=0;
        *(s16 *)(p+0x14)=0;
        *(s16 *)(p+0x16)=0x230;
        *(s16 *)(p+0x18)=0x118;
        *(s16 *)(p+0x1a)=0;
        *(s16 *)(p+0x1c)=0;
        *(p+0x1e)=0xFF;
        *(p+0x1f)=0xFF;
        *(p+0x20)=0xFF;
        *(p+0x21)=0xFF;
        *(s16 *)(p+0x22)=0x32;
        *(s16 *)(p+0x24)=0;
        *(f32 *)(p+0x28)=lbl_8036B508;
        *(f32 *)(p+0x2C)=lbl_8036B508;
        *(f32 *)(p+0x30)=lbl_8036B508;
        *(s32 *)(p+0x34)=0;
        *(s32 *)(p+0x38)=0;
        *(void **)p=lbl_80298498;
    }
    *(s16 *)(p+8)=3;
    *(u32 *)(p+0x34)|=0x10;
    *(s16 *)(p+0x24)=4;
    Ui_AddChild(self,p);
    created=Heap_Alloc(0x44);
    if(created) created=fn_801CF62C(created,0x1D4,0xAC,0x28);
    *(void **)(self+0x40)=created;
    child=*(u8 **)(self+0x40);
    if(child) *(s32 *)(child+4)+=1;
    *(s16 *)(*(u8 **)(self+0x40)+8)=0;
    *(u32 *)(*(u8 **)(self+0x40)+0x34)|=0x10;
    *(s16 *)(*(u8 **)(self+0x40)+0x24)=4;
    Ui_AddChild(self,*(void **)(self+0x40));
    child=(u8 *)Heap_Alloc(0x7C);
    if(child) {
        *(void **)child=lbl_8028FDB0;
        *(s32 *)(child+4)=0;
        *(void **)child=lbl_80292230;
        *(s16 *)(child+0x8)=-1;
        *(s16 *)(child+0xa)=0x95;
        *(s16 *)(child+0xc)=0x6C;
        *(s16 *)(child+0xe)=0x95;
        *(s16 *)(child+0x10)=0x9C;
        *(s16 *)(child+0x12)=0;
        *(s16 *)(child+0x14)=0;
        *(s16 *)(child+0x16)=0;
        *(s16 *)(child+0x18)=0x30;
        *(s16 *)(child+0x1a)=0;
        *(s16 *)(child+0x1c)=0;
        *(child+0x1e)=0xFF;
        *(child+0x1f)=0xFF;
        *(child+0x20)=0xFF;
        *(child+0x21)=0xFF;
        *(s16 *)(child+0x22)=0x28;
        *(s16 *)(child+0x24)=0;
        *(f32 *)(child+0x28)=lbl_8036B508;
        *(f32 *)(child+0x2C)=lbl_8036B508;
        *(f32 *)(child+0x30)=lbl_8036B508;
        *(s32 *)(child+0x34)=0;
        *(s32 *)(child+0x38)=0;
        *(void **)child=lbl_80298678;
        *(s16 *)(child+0x70)=0;
        *(s16 *)(child+0x72)=-1;
        *(s16 *)(child+0x74)=-1;
        *(u32 *)(child+0x78)=0;
        ((Obj *)child)->v8();
    }
    *(u8 **)(self+0x44)=child;
    child=*(u8 **)(self+0x44);
    if(child) *(s32 *)(child+4)+=1;
    *(s16 *)(*(u8 **)(self+0x44)+8)=1;
    *(s16 *)(*(u8 **)(self+0x44)+0x24)=4;
    *(u32 *)(*(u8 **)(self+0x44)+0x34)|=0x10;
    *(u32 *)(*(u8 **)(self+0x44)+0x78)=*(u32 *)(self+0x4C);
    ((Obj *)*(void **)(self+0x44))->v8();
    fn_801CDE2C(*(void **)(self+0x44),*(s32 *)(self+0x50));
    Ui_AddChild(self,*(void **)(self+0x44));
    created=Heap_Alloc(0xAC);
    if(created) created=fn_801CD0D0(created,0x24,0x90,0x28,0);
    *(void **)(self+0x48)=created;
    child=*(u8 **)(self+0x48);
    if(child) *(s32 *)(child+4)+=1;
    *(s16 *)(*(u8 **)(self+0x48)+8)=2;
    *(u32 *)(*(u8 **)(self+0x48)+0x34)|=0x10;
    *(s16 *)(*(u8 **)(self+0x48)+0x24)=4;
    Ui_AddChild(self,*(void **)(self+0x48));
    Ui_BringChildToFront(self,*(void **)(self+0x40));
    Ui_OpenChildAnim(self,p,0);
    Ui_OpenChildAnim(self,*(void **)(self+0x40),0);
    Ui_OpenChildAnim(self,*(void **)(self+0x44),0);
    Ui_OpenChildAnim(self,*(void **)(self+0x48),1);
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_801CF018(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
    };
    ((Obj *)arg0)->v6();
}

extern "C" void fn_801CF044(void *arg0) {
void Ui_PlaySeCue(void *, s32);
extern u8 lbl_8027DED8[];
extern s32 gUiInputFlags;
extern void *gPadInput;
s32 flags;
s32 buttons, held, edge;
s16 *fp;
s32 old;
s16 now;
u8 skip;

skip=0;
flags=gUiInputFlags;
fp=(s16*)((u8*)arg0+0x3C);
old=*fp;
if ((flags&0x10)&&!(flags&0x20)) skip=1;
if (!skip) {
now=*(s16*)((u8*)arg0+0x3C);
buttons=*(s32*)((u8*)gPadInput+0xC);
held=*(s32*)((u8*)gPadInput+4);
edge=held&(*(s32*)((u8*)gPadInput+8)^held);
if(buttons&0x08000008) {
if((s16)old==0) { if(buttons==edge) *fp=3; }
else *fp=now-1;
} else if(buttons&0x04000004) {
if((s16)old==3) { if(buttons==edge) *fp=0; }
else *fp=now+1;
}
if(now!=*(s16*)((u8*)arg0+0x3C)) Ui_PlaySeCue(lbl_8027DED8+0x2C,100);
}
}

extern "C" void fn_801CF134(void *arg0, void *arg1)
{
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Ui_DrawLine(s16, s16, s16, s16, s32, u8 *);
    extern f32 lbl_8036B510;

    struct Obj { virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0; virtual void v4() = 0; virtual void v5() = 0; };
    u8 color[4];
    s16 old;
    s16 target;
    void *selected;
    s32 x2;
    s32 y2;
    s32 x;
    s32 y;
    u8 *self;
    u8 *parent;

    parent = (u8 *)arg1;
    self = (u8 *)arg0;

    ((Obj *)self)->v3();

    old = *(s16 *)(self + 0x3E);
    target = (s16)(*(s16 *)(self + 0x3C) * 0x22 + 0xD);

    if (old == -1 && *(s16 *)(self + 0x40) == -1) {
        *(s16 *)(self + 0x3E) = 5;
        *(s16 *)(self + 0x40) = target;
    } else {
        *(s16 *)(self + 0x3E) = (old + 6) >> 1;
        *(s16 *)(self + 0x40) = (*(s16 *)(self + 0x40) + target + 1) >> 1;
    }

    x = *(s16 *)(self + 0x3E);
    y = *(s16 *)(self + 0x40);

    selected = *(u32 *)(parent + 0x34) ? *(void **)(*(u8 **)(parent + 0x38) + 8) : NULL;
    if (selected != self) return;

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B510);
    Prim2D_PrepareTex();

    color[0] = 0x9C;
    x2 = (s16)(x + 0x5C);
    y2 = (s16)(y + 0x1D);
    color[1] = 0x2F;
    color[2] = 0x12;
    color[3] = 0xFF;

    Ui_DrawLine((s16)x, (s16)(y - 1), x2, (s16)(y - 1), *(s32 *)(self + 0x34), color);
    Ui_DrawLine((s16)x, (s16)y2, x2, (s16)y2, *(s32 *)(self + 0x34), color);
    Ui_DrawLine((s16)(x - 1), (s16)y, (s16)(x - 1), (s16)y2, *(s32 *)(self + 0x34), color);
    Ui_DrawLine(x2, (s16)y, x2, (s16)y2, *(s32 *)(self + 0x34), color);
    Ui_DrawLine((s16)x, (s16)y, x2, (s16)y, *(s32 *)(self + 0x34), color);
    Ui_DrawLine((s16)x, (s16)(y2 - 1), x2, (s16)(y2 - 1), *(s32 *)(self + 0x34), color);
    Ui_DrawLine((s16)x, (s16)y, (s16)x, (s16)y2, *(s32 *)(self + 0x34), color);
    Ui_DrawLine((s16)(x2 - 1), (s16)y, (s16)(x2 - 1), (s16)y2, *(s32 *)(self + 0x34), color);
}

#pragma cplusplus on
extern "C" void fn_801CF324(void *arg0, s32 arg1) {
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
        virtual void v10() = 0;
    };
    void fn_80152DE0(s32, s32, u8, s32, s32);
    s32 id;
    s32 i;
    Obj *self;

    self = (Obj *)arg0;
    self->v10();
    self->v3(arg1);
    id = 0xD;
    i = 0;
    do {
        fn_80152DE0(5, id, (u8)i,
                    (i == *(s16 *)((u8 *)self + 0x3C)) ? 1 : 0,
                    *(s32 *)((u8 *)self + 0x34));
        i += 1;
        id += 0x22;
    } while (i < 4);
}

#pragma global_optimizer off
#pragma cplusplus on
extern "C" void fn_801CF3C4(void *self) {
void Ui_DrawLine(s16,s16,s16,s16,s32,u8*); void Ui_DrawRect(s16,s16,s32,s16*,u8*,s32);
void Prim2D_Begin(void);void Prim2D_AddZ(f32);void Prim2D_PrepareTex(void);
extern f32 lbl_8036B514;
s16 rect[4];
u8 light[4],dark[4],fill[4];
s32 w;
s16 height;
s32 right;
s32 h;
((UnitHireItem*)self)->v2();
w=(s16)(*(s16*)((u8*)self+0xe)-*(s16*)((u8*)self+0xa));
height=(s16)(*(s16*)((u8*)self+0x10)-*(s16*)((u8*)self+0xc));
light[0]=0x4c;light[1]=0x4c;light[2]=0x4c;light[3]=255;
dark[0]=0;dark[1]=0;dark[2]=0;dark[3]=255;
fill[0]=16;fill[1]=14;fill[2]=15;fill[3]=255;
right=w-1;
Ui_DrawLine(1,0,right,0,*(s32*)((u8*)self+0x34),light);
Ui_DrawLine(1,height,right,height,*(s32*)((u8*)self+0x34),light);
h=height-1;
Ui_DrawLine(0,1,0,h,*(s32*)((u8*)self+0x34),light);
Ui_DrawLine(w,1,w,h,*(s32*)((u8*)self+0x34),light);
Ui_DrawLine(1,1,right,1,*(s32*)((u8*)self+0x34),dark);
Ui_DrawLine(1,h,right,h,*(s32*)((u8*)self+0x34),dark);
Ui_DrawLine(1,1,1,h,*(s32*)((u8*)self+0x34),dark);
Ui_DrawLine(right,1,right,h,*(s32*)((u8*)self+0x34),dark);
Prim2D_Begin();Prim2D_AddZ(lbl_8036B514);Prim2D_PrepareTex();
rect[2]=right;rect[0]=1;rect[1]=1;rect[3]=h;
Ui_DrawRect(1,1,*(s32*)((u8*)self+0x34),rect,fill,0);
}
#pragma cplusplus reset
#pragma global_optimizer reset

#pragma cplusplus reset

#pragma cplusplus reset

#pragma scheduling on
void fn_801CF5A4(s32 *arg0, void *arg1) {
    s32 *fn_8013F748(void *, s32 *, s16 *);
    s16 sp8;
    s16 spA;
    s32 spC;
    s16 t;

    t = *(s16 *)((u8 *)arg1 + 0x3C);
    sp8 = 5;
    spA = (s16)(t * 0x22 + 0xD);
    *arg0 = *fn_8013F748(arg1, &spC, &sp8);
}
#pragma scheduling reset
s32 fn_801CF5FC(void *arg0) {
#pragma global_optimizer on
extern s32 lbl_80298720[];
return lbl_80298720[*(s16*)((u8*)arg0+0x3c)];
#pragma global_optimizer reset
}

s32 fn_801CF614(void *arg0) {
    s16 v;
    s32 r;
    v = *(s16 *)((u8 *)arg0 + 0x3C);
    r = -1;
    if (v == 0) {
        r = 0;
    }
    return r;
}

#pragma opt_common_subs off
void *fn_801CF62C(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
extern void *lbl_8028FDB0[], *lbl_80292230[], *lbl_80298730[];
extern const f32 lbl_8036B518;
*(void**)arg0=lbl_8028FDB0;
*(s32*)((u8*)arg0+4)=0;
*(void**)arg0=lbl_80292230;
*(s16*)((u8*)arg0+8)=-1;
*(s16*)((u8*)arg0+10)=arg1;
*(s16*)((u8*)arg0+12)=arg2;
*(s16*)((u8*)arg0+14)=arg1+0x67;
*(s16*)((u8*)arg0+16)=arg2+0x9d;
*(s16*)((u8*)arg0+18)=0;
*(s16*)((u8*)arg0+20)=0;
*(s16*)((u8*)arg0+22)=0x67;
*(s16*)((u8*)arg0+24)=0x9d;
*(s16*)((u8*)arg0+26)=0;
*(s16*)((u8*)arg0+28)=0;
*(u8*)((u8*)arg0+30)=255;
*(u8*)((u8*)arg0+31)=255;
*(u8*)((u8*)arg0+32)=255;
*(u8*)((u8*)arg0+33)=255;
*(s16*)((u8*)arg0+34)=arg3;
*(s16*)((u8*)arg0+36)=0;
*(f32*)((u8*)arg0+40)=lbl_8036B518;
*(f32*)((u8*)arg0+44)=lbl_8036B518;
*(f32*)((u8*)arg0+48)=lbl_8036B518;
*(s32*)((u8*)arg0+52)=0;
*(s32*)((u8*)arg0+56)=0;
*(void**)arg0=lbl_80298730;
*(s16*)((u8*)arg0+60)=0;
*(s16*)((u8*)arg0+62)=-1;
*(s16*)((u8*)arg0+64)=-1;
return arg0;
}
#pragma opt_common_subs on
void *fn_801CF6F4(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    extern void *lbl_80298730[];
    extern void *lbl_80292230[];
    extern void *lbl_8028FDB0[];

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_80298730;
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

void *ScriptObj_FindByName(void *arg0) {
    s32 Str_Cmp(void *, void *);
    extern u16 gScriptObjSlots[];
    u8 *p;
    s32 i;

    p = (u8 *)gScriptObjSlots;
    i = 0;
    do {
        if ((*(u32 *)(p + 8) & 1) != 0 &&
            Str_Cmp(*(void **)(*(void **)(p + 0x24)), arg0) == 0) {
            return (u8 *)gScriptObjSlots + i * 0x15C;
        }
        i += 1;
        p += 0x15C;
    } while (i < 2);
    return NULL;
}

void ScriptObj_Start(void *name, void *parent) {
    s32 Str_Cmp(void *, void *);
    void fn_801CFAB8(void *, u8, void *);
    void fn_8005C8B4(void *);
    void *Process_Create(void *, void *);
    void FallingParticle_CreateEx(void *, f32);
    extern u8 gScriptObjDefs[];
    extern u16 gScriptObjSlots[];
    extern u8 lbl_8027DF20[];
    extern u8 gScriptObjProc[];
    extern f32 gFloatMinusOne;
    u8 *def;
    u8 *p;
    u8 *slot;
    s32 i;
    s32 ctr;
    f32 scale;

    def = gScriptObjDefs;
    for (;;) {
        if (Str_Cmp(name, *(void **)def) == 0) {
            break;
        }
        def += 0x10;
    }
    p = (u8 *)gScriptObjSlots;
    i = 0;
    for (ctr = 2; ctr != 0; ctr--) {
        if ((*(s32 *)(p + 8) & 1) == 0) {
            slot = (u8 *)gScriptObjSlots + i * 0x15C;
            fn_801CFAB8(slot, (u8)i, def);
            fn_8005C8B4(lbl_8027DF20 + 0x13E);
            fn_8005C8B4(slot + 0x12C);
            *(void **)(slot + 0x150) = Process_Create(gScriptObjProc, parent);
            scale = gFloatMinusOne;
            *(u8 *)(*(u8 **)(slot + 0x150) + 0x30) = i;
            FallingParticle_CreateEx(*(void **)(slot + 0x150), scale);
            return;
        }
        p += 0x15C;
        i += 1;
    }
}

void fn_801CF8E4(void *arg0)
{
    void *record;

    record = (u8 *)gScriptObjSlots +
        (*(u8 *)((u8 *)arg0 + 0x30) * 0x15C);

    FileCache_ReleaseSlot(record);
    FileCache_ReleaseSlot((u8 *)record + 4);
}

void fn_801CF92C(void *arg0)
{
    void Process_ClearFunc(void *);
    void fn_801D15D4(void *);
    void fn_801D107C(void *);
    u8 *table;
    u8 *entry;

    table = (u8 *)gScriptObjSlots;
    entry = table + *(u8 *)((u8 *)arg0 + 0x30) * 0x15C;
    if ((*(u32 *)(entry + 8) & 1) == 0) {
        Process_ClearFunc(arg0);
        return;
    }
    fn_801D15D4(entry);
    fn_801D107C((u8 *)gScriptObjSlots + *(u8 *)((u8 *)arg0 + 0x30) * 0x15C);
}

#pragma global_optimizer off
void fn_801CF99C(void *arg0) {
    s32 FileCache_GetFlags(void *);
    void fn_8006EEFC(void *, void *);
    void Process_ClearFunc(void *);
    extern u16 gScriptObjSlots[];
    extern u8 lbl_8027DF20[];
    u8 *entry;
    u8 ok;

    entry = (u8 *)gScriptObjSlots + *(u8 *)((u8 *)arg0 + 0x30) * 0x15C;
    if (!(FileCache_GetFlags(lbl_8027DF20 + 0x13E) & 0x2000) ||
        !(FileCache_GetFlags(entry + 0x12C) & 0x2000)) {
        ok = 0;
    } else {
        fn_8006EEFC(entry, lbl_8027DF20 + 0x13E);
        fn_8006EEFC(entry + 4, entry + 0x12C);
        ok = 1;
    }
    if (ok != 0) {
        Process_ClearFunc(arg0);
    }
}
#pragma global_optimizer on
void fn_801CFA44(void *arg0)
{
    extern void fn_8000C60C(void *);
    extern void fn_801C18FC(s32);

    s32 i;
    u8 *ptr;
    u32 zero;

    zero = 0U;
    i = (s32)zero;
    ptr = (u8 *)arg0;

    *(s32 *)(ptr + 0x8) = zero;

    do {
        *(u8 *)(ptr + 0x28) = zero;

        if (*(void **)(ptr + 0x2C) != 0) {
            fn_8000C60C(*(void **)(ptr + 0x2C));
            *(s32 *)(ptr + 0x2C) = zero;
        }

        ptr += 8;
        i++;
    } while (i < 7);

    fn_801C18FC(1);
}

void fn_801CFAB8(void *arg0, u8 arg1, void *arg2)
{
    extern f32 lbl_8036B56C;
    extern u8 lbl_8027DF20[];
    char *strcpy(char *, const char *);

    u8 *obj;
    u16 type;

    obj = (u8 *)arg0;

    *(s32 *)(obj + 0x08) = 1;
    obj[0x0C] = arg1;
    *(s16 *)(obj + 0x0E) = 0;
    *(s16 *)(obj + 0x10) = 0;
    *(s16 *)(obj + 0x12) = 0;

    obj[0x14] = 100;
    obj[0x15] = 100;
    obj[0x16] = 100;

    *(s16 *)(obj + 0x18) = 0;
    *(s16 *)(obj + 0x1A) = 0;
    *(f32 *)(obj + 0x1C) = lbl_8036B56C;

    obj[0x20] = 0xFF;
    obj[0x21] = 0xFF;
    *(void **)(obj + 0x24) = arg2;

    obj[0x28] = 0;
    obj[0x30] = 0;
    obj[0x38] = 0;
    obj[0x40] = 0;
    obj[0x48] = 0;
    obj[0x50] = 0;
    obj[0x58] = 0;

    obj[0x61] = 0;
    obj[0x6F] = 0;
    obj[0x7D] = 0;
    obj[0x8B] = 0;
    obj[0x99] = 0;
    obj[0xA7] = 0;
    obj[0xB5] = 0;
    obj[0xC3] = 0;
    obj[0xD1] = 0;
    obj[0xDF] = 0;

    obj[0xEC] = 0;
    obj[0xF4] = 0;
    obj[0xFC] = 0;
    obj[0x104] = 0;
    obj[0x10C] = 0;
    obj[0x114] = 0;
    obj[0x11C] = 0;
    obj[0x124] = 0;

    type = *(u16 *)((u8 *)arg2 + 4);

    switch (type) {
    case 0:
        strcpy((char *)obj + 0x12C,
               (char *)lbl_8027DF20 + 0x14C);
        break;

    case 1:
        strcpy((char *)obj + 0x12C,
               (char *)lbl_8027DF20 + 0x161);
        break;

    case 2:
        strcpy((char *)obj + 0x12C,
               (char *)lbl_8027DF20 + 0x176);
        break;

    case 3:
        strcpy((char *)obj + 0x12C,
               (char *)lbl_8027DF20 + 0x18C);
        break;

    case 4:
        strcpy((char *)obj + 0x12C,
               (char *)lbl_8027DF20 + 0x1A0);
        break;

    case 5:
        strcpy((char *)obj + 0x12C,
               (char *)lbl_8027DF20 + 0x1B4);
        break;
    }
}

void fn_801CFC4C(void *arg0, s32 arg1) {
    if (arg1 <= 0) {
        arg1 = 1;
    }
    *(u8 *)((u8 *)arg0 + 0x158) = 0xFF;
    *(u8 *)((u8 *)arg0 + 0x159) = 0;
    *(u16 *)((u8 *)arg0 + 0x154) = 0;
    *(u16 *)((u8 *)arg0 + 0x156) = arg1;
    *(u32 *)((u8 *)arg0 + 8) |= 2;
}

void fn_801CFC80(void *arg0, s32 arg1) {
    if (arg1 <= 0) {
        arg1 = 1;
    }
    *(u8 *)((u8 *)arg0 + 0x158) = 0;
    *(u8 *)((u8 *)arg0 + 0x159) = 0xFF;
    *(u16 *)((u8 *)arg0 + 0x154) = 0;
    *(u16 *)((u8 *)arg0 + 0x156) = arg1;
    *(u32 *)((u8 *)arg0 + 8) |= 2;
}

extern void *gPrim2D;
#pragma global_optimizer off
void fn_801CFCB4(s8 *a) {
    s32 c = 3;
    s32 x;
    s32 n = 0x10;

    x = a[0xEC];
    if (x) {
        a[0xEC] = c;
    }
    x = a[0xF4];
    if (x) {
        a[0xF4] = c;
    }
    a += n;
    x = a[0xEC];
    if (x) {
        a[0xEC] = c;
    }
    x = a[0xF4];
    if (x) {
        a[0xF4] = c;
    }
    x = a[0xFC];
    if (x) {
        a[0xFC] = c;
    }
    x = a[0x104];
    if (x) {
        a[0x104] = c;
    }
    x = a[0x10C];
    if (x) {
        a[0x10C] = c;
    }
    x = a[0x114];
    if (x) {
        a[0x114] = c;
    }
}
#pragma global_optimizer reset
void fn_801CFD40(u8 *arg0, s32 arg1) {
    arg1 = (arg1 << 3) + 0xEC;
    if ((s8)arg0[arg1] != 0) {
        arg0[arg1] = 3;
    }
}

#pragma global_optimizer off
void fn_801CFD60(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s8 arg4) {
    s32 temp_r8;

    temp_r8 = arg1 * 8;
    temp_r8 += 0xEC;
    temp_r8 = arg0 + temp_r8;
    *(u8 *)(temp_r8 + 0x0) = 1;
    *(u16 *)(temp_r8 + 0x2) = arg2;
    *(u16 *)(temp_r8 + 0x4) = arg3;
    *(u8 *)(temp_r8 + 0x6) = arg4;
    *(u8 *)(temp_r8 + 0x7) = 0;
}
#pragma global_optimizer on
void fn_801CFD8C(s32 arg0, s32 arg1, u8 arg2) {
    u32 temp_r4;

    temp_r4 = (arg1 * 0xE) + 0x60;
    if (arg2 != 0) {
        *(u8*)(arg0 + temp_r4) |= 2;
        return;
    }
    *(u8*)(arg0 + temp_r4) &= 0xFFFFFFFD;
}

#pragma global_optimizer off
void fn_801CFDBC(s32 arg0, s32 arg1) {
    s32 temp_r4;

    temp_r4 = (arg1 * 0xE) + 0x60;
    *(u8 *)(arg0 + temp_r4) = *(u8 *)(arg0 + temp_r4) | 1;
}
#pragma global_optimizer on
void fn_801CFDD4(s8 *a)
{
    s32 c;
    s32 x;
    s8 *p;

    c = 0x63;
    x = a[0x61];
    if (x) {
        a[0x61] = c;
    }
    x = a[0x6f];
    if (x) {
        a[0x6f] = c;
    }
    p = a;
    p += 0x1c;
    x = p[0x61];
    if (x) {
        p[0x61] = c;
    }
    x = p[0x6f];
    if (x) {
        p[0x6f] = c;
    }
    x = p[0x7d];
    if (x) {
        p[0x7d] = c;
    }
    x = p[0x8b];
    if (x) {
        p[0x8b] = c;
    }
    x = p[0x99];
    if (x) {
        p[0x99] = c;
    }
    x = p[0xa7];
    if (x) {
        p[0xa7] = c;
    }
    x = p[0xb5];
    if (x) {
        p[0xb5] = c;
    }
    x = p[0xc3];
    if (x) {
        p[0xc3] = c;
    }
}
#pragma opt_strength_reduction on
#pragma global_optimizer on
void fn_801CFE80(void *arg0, s32 arg1) {
    u8 *p;

    p = (u8 *)arg0 + arg1 * 0xE + 0x60;
    if ((s8)p[1] != 0) {
        p[1] = 0x63;
    }
}

void fn_801CFEA4(s32 arg0, s32 arg1) {
    void fn_801CFEF4(void);
    s32 temp_r4;
    s32 temp_r3;

    fn_801CFEF4();
    temp_r3 = arg1 * 0xE;
    temp_r4 = 3;
    *(u8 *)(arg0 + temp_r3 + 0x61) = temp_r4;
    *(u8 *)(arg0 + temp_r3 + 0x63) = 0x96;
}

void fn_801CFEF4(void *arg0, s32 arg1)
{
    extern u32 lbl_8036B540;
    extern u32 lbl_8036B544;
    extern u32 lbl_8036B548;
    extern u32 lbl_8036B54C;
    extern u32 lbl_8036B550;
    extern u32 lbl_8036B554;
    extern u32 lbl_8036B558;
    extern u32 lbl_8036B55C;
    extern u32 lbl_8036B560;
    extern u32 lbl_8036B564;

    u8 *self;
    u8 *entry;

    self = (u8 *)arg0;
    entry = self + arg1 * 0xE + 0x60;

    entry[0] = 0;
    entry[1] = 1;
    entry[2] = arg1;
    entry[3] = 0;

    switch (*(u16 *)(*(u8 **)(self + 0x24) + 4)) { case 0:
        switch ((s8)entry[2]) {
        case 0:
        {
            u32 color;
            u8 *p = (u8 *)&color;

            *(u16 *)(entry + 8) = 1;
            *(u16 *)(entry + 4) = 0x33;
            *(u16 *)(entry + 6) = 0x2C;
            color = lbl_8036B540;

            entry[0xA] = p[0];
            entry[0xB] = p[1];
            entry[0xC] = p[2];
            entry[0xD] = p[3];
            break;
        }

        case 1:
        {
            u32 color;
            u8 *p = (u8 *)&color;

            *(u16 *)(entry + 8) = 2;
            *(u16 *)(entry + 4) = 0x17;
            *(u16 *)(entry + 6) = 0x9C;
            color = lbl_8036B544;

            entry[0xA] = p[0];
            entry[0xB] = p[1];
            entry[0xC] = p[2];
            entry[0xD] = p[3];
            break;
        }

        case 2:
        {
            u32 color;
            u8 *p = (u8 *)&color;

            *(u16 *)(entry + 8) = 3;
            *(u16 *)(entry + 4) = 0x124;
            *(u16 *)(entry + 6) = 7;
            color = lbl_8036B548;

            entry[0xA] = p[0];
            entry[0xB] = p[1];
            entry[0xC] = p[2];
            entry[0xD] = p[3];
            break;
        }

        case 3:
        {
            u32 color;
            u8 *p = (u8 *)&color;

            *(u16 *)(entry + 8) = 4;
            *(u16 *)(entry + 4) = 0xB0;
            *(u16 *)(entry + 6) = 0x66;
            color = lbl_8036B54C;

            entry[0xA] = p[0];
            entry[0xB] = p[1];
            entry[0xC] = p[2];
            entry[0xD] = p[3];
            break;
        }

        case 4:
        {
            u32 color;
            u8 *p = (u8 *)&color;

            *(u16 *)(entry + 8) = 5;
            *(u16 *)(entry + 4) = 0xDD;
            *(u16 *)(entry + 6) = 0xA6;
            color = lbl_8036B550;

            entry[0xA] = p[0];
            entry[0xB] = p[1];
            entry[0xC] = p[2];
            entry[0xD] = p[3];
            break;
        }

        case 5:
        {
            u32 color;
            u8 *p = (u8 *)&color;

            *(u16 *)(entry + 8) = 6;
            *(u16 *)(entry + 4) = 0xFA;
            *(u16 *)(entry + 6) = 0x157;
            color = lbl_8036B554;

            entry[0xA] = p[0];
            entry[0xB] = p[1];
            entry[0xC] = p[2];
            entry[0xD] = p[3];
            break;
        }

        case 6:
        {
            u32 color;
            u8 *p = (u8 *)&color;

            *(u16 *)(entry + 8) = 7;
            *(u16 *)(entry + 4) = 0x6C;
            *(u16 *)(entry + 6) = 0x13B;
            color = lbl_8036B558;

            entry[0xA] = p[0];
            entry[0xB] = p[1];
            entry[0xC] = p[2];
            entry[0xD] = p[3];
            break;
        }

        case 7:
        {
            u32 color;
            u8 *p = (u8 *)&color;

            *(u16 *)(entry + 8) = 8;
            *(u16 *)(entry + 4) = 0x32;
            *(u16 *)(entry + 6) = 0xDC;
            color = lbl_8036B55C;

            entry[0xA] = p[0];
            entry[0xB] = p[1];
            entry[0xC] = p[2];
            entry[0xD] = p[3];
            break;
        }

        case 8:
        {
            u32 color;
            u8 *p = (u8 *)&color;

            *(u16 *)(entry + 8) = 9;
            *(u16 *)(entry + 4) = 0xB0;
            *(u16 *)(entry + 6) = 0x66;
            color = lbl_8036B560;

            entry[0xA] = p[0];
            entry[0xB] = p[1];
            entry[0xC] = p[2];
            entry[0xD] = p[3];
            break;
        }

        case 9:
        {
            u32 color;
            u8 *p = (u8 *)&color;

            *(u16 *)(entry + 8) = 5;
            *(u16 *)(entry + 4) = 0xDD;
            *(u16 *)(entry + 6) = 0xA6;
            color = lbl_8036B564;

            entry[0xA] = p[0];
            entry[0xB] = p[1];
            entry[0xC] = p[2];
            entry[0xD] = p[3];
            break;
        }
        }
    }
}

#pragma opt_strength_reduction off
void fn_801D0200(void *arg0) {
 s8 *p = arg0; s32 i;
 for (i=0;i<7;i++,p+=8) { if (p[0x28]) p[0x28]=5; }
}
#pragma opt_strength_reduction on
void fn_801D027C(s32 arg0, s32 arg1) {
    s32 temp_r4;
    
    temp_r4 = (arg1 << 3);
    if ((s8)*(u8*)(arg0 + temp_r4 + 0x28) != 0) {
        *(u8*)(arg0 + temp_r4 + 0x28) = 5;
    }
}

void fn_801D029C(u8 *self, s32 index, s32 x, s32 y, u8 *color, f32 scale) {
    void *fn_8005397C(void *, void *);
    void Effect_SetPos(void *, f32, f32, f32);
    extern u8 lbl_8027DF20[];
    typedef struct { u8 r,g,b,a; } Color;
    extern Color lbl_8036C530;
    Color copy, c;
    typedef struct { u8 active, flag; u16 pad; void *effect; } Entry;
    typedef struct { u8 pad[0x28]; Entry entries[1]; } Self;
    Entry *entry;
    u8 *effect;
    u8 *data;
    s32 r, g, b;
    entry = &((Self *)self)->entries[index];
    entry->active = 1;
    entry->flag = 0;
    effect = fn_8005397C(lbl_8027DF20 + 0x1C9, *(void **)(self + 0x150));
    entry->effect = effect;
    Effect_SetPos(effect, (f32)x, (f32)y, 935.0f);
    r = color[0] >> 1;
    data = *(u8 **)(effect + 0x30);
    g = color[1] >> 1;
    b = color[2] >> 1;
    *(f32 *)(data + 0x18) = 0.2f * scale;
    data = *(u8 **)(effect + 0x30);
    {
    c = lbl_8036C530;
    c.r = r; c.g = g; c.b = b;
    }
    copy = c;
    data[0x38] = copy.r;
    data[0x39] = copy.g;
    data[0x3A] = copy.b;
    data[0x3B] = copy.a;
    data = *(u8 **)(effect + 0x30);
    *(u32 *)(data + 8) |= 0x1004;
}

void fn_801D03E4(void *arg0, s32 arg1, u8 arg2) {
    if (arg2 != 0) {
        *(s32*)((char*)arg0 + 8) |= (0x800 << arg1);
        return;
    }
    *(s32*)((char*)arg0 + 8) &= ~(0x800 << arg1);
}

void fn_801D041C(void *arg0, u8 arg1) {
    if (arg1 != 0) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) & 0xFFFFFFFB);
        return;
    }
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) | 4);
}

void fn_801D0444(s16 *arg0, s32 idx) {
    if (idx < 3)
        arg0[idx + 7] = 0;
}

void fn_801D0460(void *arg0, s32 arg1) {
    if (arg1 < 3) {
        u32* field_ptr = (u32*)((char*)arg0 + 8);
        *field_ptr |= (0x100 << arg1);
    }
}

#pragma push
#pragma fp_contract on
void fn_801D0480(void *arg0) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    f32 Math_Hermite(f32, f32, f32, f32, f32);
    void Ui_LoadAtlasTex(void *, void *, s32);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXTrans(void *, f32, f32, f32);
    void GXBegin(s32, s32, s32);
    void fn_80222C50(void *, s32);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    f64 fn_80237E90(f32);
    extern f32 lbl_80367068[];
    extern s32 lbl_8036B520;
    extern s32 lbl_8036B524;
    extern s32 lbl_8036B528;
    extern s32 lbl_8036B52C;
    extern s32 lbl_8036B530;
    extern s32 lbl_8036B534;
    extern s32 lbl_8036B538;
    extern s32 lbl_8036B53C;
    extern const f32 lbl_8036B56C;
    extern const f64 lbl_8036B578;
    extern const f32 lbl_8036B580;
    extern const f32 lbl_8036B584;
    extern const f32 lbl_8036B588;
    extern const f32 lbl_8036B58C;
    extern const f32 lbl_8036B590;
    extern const f64 lbl_8036B598;
    extern const f64 lbl_8036B5A0;
    extern const f64 lbl_8036B5A8;
    extern const f32 lbl_8036B5B0;
    extern const f32 lbl_8036B5B4;
    extern const f32 lbl_8036B5B8;
    extern const f32 lbl_8036B5BC;
    extern const f32 lbl_8036B5C0;
    extern const f32 lbl_8036B5C4;
    extern const f64 lbl_8036B5C8;

    f32 mtxA[3][4];
    f32 mtxB[3][4];
    f32 mtxC[3][4];
    f32 mtxD[3][4];
    u8 tex[0x20];
    s32 c0, c1;
    u8 *seg;
    s32 lane;
    s32 acc;
    s32 width;
    u8 *self;
    s32 off4;
    s32 off2;
    s32 entry;
    u8 g0,b0,g1,b1;
    u8 r0,r1;
    s32 cr,cg,cb;
    u8 alpha;
    s32 i;
    f32 px,py,lx,ly;
    f32 fade,half,dist,t;
    u32 timer;
    void **lists;

    self = (u8 *)arg0;
    lane = 0;
    off4 = 0;
    off2 = 0;
    px = lbl_8036B580;
    py = px;
    lx = px;
    ly = px;
    for (;;) {
        if(lane>=3) break;
        if (*(s16 *)(self + off2 + 0xE) <= 0) {
            lane++;
            off4 += 4;
            off2 += 2;
            continue;
        }
        lists = *(void ***)(*(u8 **)(self + 0x24) + 8);
        if (lists[lane] == NULL) {
            break;
        }
        dist = lbl_8036B580;
        entry = 0;
        acc = 0;
        for (;;) {
            seg = (u8 *)(*(void ***)(*(u8 **)(self + 0x24) + 8))[lane] + entry;
            if (*(u16 *)seg & 0x8000) {
                break;
            }
            if (*(u16 *)seg & 4) {
                dist = lbl_8036B580;
                entry += 0x16;
                continue;
            }
            acc += seg[0x13];
            if (*(s16 *)(self + off2 + 0xE) >= acc) {
                width = seg[0x12];
            } else {
                width = (s32)(((f32)seg[0x12] * (f32)(*(s16 *)(self + off2 + 0xE) - (acc - seg[0x13]))) / (f32)seg[0x13]);
            }
            if (width <= 0) {
                break;
            }
            switch (seg[0x14]) {
            case 0: {
                s32 c0,c1;
                c0 = lbl_8036B520;
                c1 = lbl_8036B524;
            r0 = ((u8 *)&c0)[0];
            g0 = ((u8 *)&c0)[1];
            b0 = ((u8 *)&c0)[2];
            r1 = ((u8 *)&c1)[0];
            g1 = ((u8 *)&c1)[1];
            b1 = ((u8 *)&c1)[2];
                break;
            }
            case 1: {
                s32 c0,c1;
                c0 = lbl_8036B528;
                c1 = lbl_8036B52C;
            r0 = ((u8 *)&c0)[0];
            g0 = ((u8 *)&c0)[1];
            b0 = ((u8 *)&c0)[2];
            r1 = ((u8 *)&c1)[0];
            g1 = ((u8 *)&c1)[1];
            b1 = ((u8 *)&c1)[2];
                break;
            }
            case 2: {
                s32 c0,c1;
                c0 = lbl_8036B530;
                c1 = lbl_8036B534;
            r0 = ((u8 *)&c0)[0];
            g0 = ((u8 *)&c0)[1];
            b0 = ((u8 *)&c0)[2];
            r1 = ((u8 *)&c1)[0];
            g1 = ((u8 *)&c1)[1];
            b1 = ((u8 *)&c1)[2];
                break;
            }
            default: {
                s32 c0,c1;
                c0 = lbl_8036B538;
                c1 = lbl_8036B53C;
            r0 = ((u8 *)&c0)[0];
            g0 = ((u8 *)&c0)[1];
            b0 = ((u8 *)&c0)[2];
            r1 = ((u8 *)&c1)[0];
            g1 = ((u8 *)&c1)[1];
            b1 = ((u8 *)&c1)[2];
                break;
            }
            }
            fade = (f32)self[0x14 + lane] / lbl_8036B584;
            timer = *(u32 *)(self + 0x14C);
            if (timer < 0x5DCU) {
                cr = (s32)(fade * Math_Ease(0, (f32)r0, (f32)r1, (f32)*(u32 *)(self + 0x14C), lbl_8036B588));
                cg = (s32)(fade * Math_Ease(0, (f32)g0, (f32)g1, (f32)*(u32 *)(self + 0x14C), lbl_8036B588));
                cb = (s32)(fade * Math_Ease(0, (f32)b0, (f32)b1, (f32)*(u32 *)(self + 0x14C), lbl_8036B588));
                alpha=255;
            } else {
                cr = (s32)(fade * Math_Ease(0, (f32)r1, (f32)r0, (f32)(*(u32 *)(self + 0x14C) - 0x5DC), lbl_8036B588));
                cg = (s32)(fade * Math_Ease(0, (f32)g1, (f32)g0, (f32)(*(u32 *)(self + 0x14C) - 0x5DC), lbl_8036B588));
                cb = (s32)(fade * Math_Ease(0, (f32)b1, (f32)b0, (f32)(*(u32 *)(self + 0x14C) - 0x5DC), lbl_8036B588));
                alpha=255;
            }
            alpha = (u8)((self[0x21] * (alpha * self[0x20])) / 65025);
            Ui_LoadAtlasTex(*(void **)self, tex, 0);
            fn_80222C50(tex, 0);
            PSMTXTrans(mtxA, (f32)*(s16 *)(self + 0x18), (f32)*(s16 *)(self + 0x1A), lbl_8036B580);
            GXSetCurrentMtx(0);
            GXLoadPosMtxImm(mtxA, 0);
            cr=(u8)cr; cg=(u8)cg; cb=(u8)cb;
            for (i = 0; i < width; i++) {
                half = lbl_8036B58C * ((lbl_8036B590 * *(f32 *)(self + 0x1C) * (f32)seg[0x15]) / lbl_8036B584);
                if (*(u16 *)seg & 2) {
                    t = Math_Ease(0, lbl_8036B580, lbl_8036B56C, (f32)i, (f32)seg[0x12]);
                } else {
                    t = (f32)i / (f32)seg[0x12];
                }
                lx = px;
                px = *(f32 *)(self + 0x1C) * Math_Hermite((f32)*(s16 *)(seg + 2), (f32)*(s16 *)(seg + 6),
                                                           (f32)*(s16 *)(seg + 0xA), (f32)*(s16 *)(seg + 0xE), t);
                ly = py;
                py = *(f32 *)(self + 0x1C) * Math_Hermite((f32)*(s16 *)(seg + 4), (f32)*(s16 *)(seg + 8),
                                                           (f32)*(s16 *)(seg + 0xC), (f32)*(s16 *)(seg + 0x10), t);
                if (i == 0) {
                    lx = px;
                    ly = py;
                }
                if (*(u16 *)seg & 0x10) {
                    f32 dy=py-ly;
                    f32 dx=px-lx;
                    f32 length = dx*dx+dy*dy;
                    if (length > lbl_8036B580) {
                        f64 estimate = __frsqrte(length);
                        estimate = (lbl_8036B598*estimate)*(lbl_8036B5A0-length*(estimate*estimate));
                        estimate = (lbl_8036B598*estimate)*(lbl_8036B5A0-length*(estimate*estimate));
                        estimate = (lbl_8036B598*estimate)*(lbl_8036B5A0-length*(estimate*estimate));
                        length = (f32)(length*estimate);
                    } else if (length < lbl_8036B5A8) {
                        length = lbl_80367068[0];
                    } else {
                        union {f32 f;u32 u;} v;
                        s32 kind;
                        v.f=length;
                        switch(v.u & 0x7f800000) {
                        case 0x7f800000: if(v.u & 0x7fffff) kind=1;else kind=2;break;
                        case 0: if(v.u & 0x7fffff) kind=5;else kind=3;break;
                        default:kind=4;break;
                        }
                        if(kind==1) length=lbl_80367068[0];
                    }
                    dist += length;
                    if(dist-lbl_8036B5B0*(s32)(dist/lbl_8036B5B0)>=lbl_8036B5B4) continue;
                }
                GXBegin(0x98, 0, 4);
                { f32 z=lbl_8036B580, one=lbl_8036B56C;
                *(volatile f32 *)0xCC008000 = px - half;
                *(volatile f32 *)0xCC008000 = py - half;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = (u8)cr;
                *(volatile u8 *)0xCC008000 = (u8)cg;
                *(volatile u8 *)0xCC008000 = (u8)cb;
                *(volatile u8 *)0xCC008000 = alpha;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile f32 *)0xCC008000 = px + half;
                *(volatile f32 *)0xCC008000 = py - half;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = (u8)cr;
                *(volatile u8 *)0xCC008000 = (u8)cg;
                *(volatile u8 *)0xCC008000 = (u8)cb;
                *(volatile u8 *)0xCC008000 = alpha;
                *(volatile f32 *)0xCC008000 = one;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile f32 *)0xCC008000 = px - half;
                *(volatile f32 *)0xCC008000 = py + half;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = (u8)cr;
                *(volatile u8 *)0xCC008000 = (u8)cg;
                *(volatile u8 *)0xCC008000 = (u8)cb;
                *(volatile u8 *)0xCC008000 = alpha;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile f32 *)0xCC008000 = one;
                *(volatile f32 *)0xCC008000 = px + half;
                *(volatile f32 *)0xCC008000 = py + half;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = (u8)cr;
                *(volatile u8 *)0xCC008000 = (u8)cg;
                *(volatile u8 *)0xCC008000 = (u8)cb;
                *(volatile u8 *)0xCC008000 = alpha;
                *(volatile f32 *)0xCC008000 = one;
                *(volatile f32 *)0xCC008000 = one;
                }
            }
            if ((*(u16 *)seg & 8) || *(s16 *)(self+off2+0xE)<=acc) {
                f32 dx = px-lx;
                f32 dy = py-ly;
                f32 angle;
                alpha=(u8)((self[0x21]*(0xff*self[0x20]))/65025);
                Ui_LoadAtlasTex(*(void **)self,tex,1);
                fn_80222C50(tex,0);
                if(dx==lbl_8036B580) dx=lbl_8036B5B8;
                angle=(f32)fn_80237E90(dy/dx);
                if(dx<lbl_8036B580) angle+=lbl_8036B5BC;
                angle+=lbl_8036B5C0;
                PSMTXTrans(mtxB,-px,-py,lbl_8036B580);
                PSMTXRotRad(mtxC,'z',angle);
                PSMTXTrans(mtxD,px+(f32)*(s16 *)(self+0x18),py+(f32)*(s16 *)(self+0x1A),lbl_8036B580);
                PSMTXConcat(mtxC,mtxB,mtxA);
                PSMTXConcat(mtxD,mtxA,mtxA);
                GXSetCurrentMtx(0);
                GXLoadPosMtxImm(mtxA,0);
                GXBegin(0x98, 0, 4);
                { f32 z=lbl_8036B580, one=lbl_8036B56C;
                half=lbl_8036B58C*(lbl_8036B5C4* *(f32 *)(self+0x1C));
                *(volatile f32 *)0xCC008000 = px - half;
                *(volatile f32 *)0xCC008000 = py - half;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = (u8)cr;
                *(volatile u8 *)0xCC008000 = (u8)cg;
                *(volatile u8 *)0xCC008000 = (u8)cb;
                *(volatile u8 *)0xCC008000 = alpha;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile f32 *)0xCC008000 = px + half;
                *(volatile f32 *)0xCC008000 = py - half;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = (u8)cr;
                *(volatile u8 *)0xCC008000 = (u8)cg;
                *(volatile u8 *)0xCC008000 = (u8)cb;
                *(volatile u8 *)0xCC008000 = alpha;
                *(volatile f32 *)0xCC008000 = one;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile f32 *)0xCC008000 = px - half;
                *(volatile f32 *)0xCC008000 = py + half;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = (u8)cr;
                *(volatile u8 *)0xCC008000 = (u8)cg;
                *(volatile u8 *)0xCC008000 = (u8)cb;
                *(volatile u8 *)0xCC008000 = alpha;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile f32 *)0xCC008000 = one;
                *(volatile f32 *)0xCC008000 = px + half;
                *(volatile f32 *)0xCC008000 = py + half;
                *(volatile f32 *)0xCC008000 = z;
                *(volatile u8 *)0xCC008000 = (u8)cr;
                *(volatile u8 *)0xCC008000 = (u8)cg;
                *(volatile u8 *)0xCC008000 = (u8)cb;
                *(volatile u8 *)0xCC008000 = alpha;
                *(volatile f32 *)0xCC008000 = one;
                *(volatile f32 *)0xCC008000 = one;
                }
            }
            entry += 0x16;
        }
        lane++;
        off4 += 4;
        off2 += 2;
    }
}
#pragma pop
void fn_801D107C(void *arg0) {
    void fn_80007340(void (*)(void *), void *);
    void fn_80007698(u8);
    void fn_800076AC(s32, s32, s32, s32);
    void fn_800077D8(f32, f32, f32, f32);
    void fn_80007818(f32, f32, f32, f32);
    void fn_80007838(f32, f32, f32, f32);
    void fn_80007884(void);
    void fn_80007898(s32);
    void fn_80009B8C(u8);
    void fn_80009C0C(f32);
    void fn_80009D74(f32, f32, f32, f32);
    void fn_80009EB0(void *, u16, s32, s32);
    void fn_80009F90(void *, u16, s32);
    void fn_8000A248(void);
    void fn_8000A258(void);
    void **fn_8006EDD8(void *, u16);
    void fn_801D0480(void *);
    extern u16 lbl_80331D00[];
    extern f32 lbl_8036B568;
    extern f64 lbl_8036B578;
    extern f32 lbl_8036B580;
    extern f64 lbl_8036B5C8;
    extern f32 lbl_8036B5D0;

    u8 *self = arg0;
    register s32 i;
    u16 *pair;
    f32 h;
    f32 w;
    void *node;
    u16 idx;
    void **tex;
    u8 *ent;
    s16 *poly;
    void **tex2;

    fn_8000A258();
    fn_80009D74(
        (f32)*(s16 *)(self + 0x18),
        (f32)*(s16 *)(self + 0x1A),
        (f32)(self[0xC] * 0xA + 0x3B6),
        *(f32 *)(self + 0x1C));
    fn_80009B8C(self[0x20]);
    fn_8000A248();

    fn_8000A258();
    fn_80009F90(*(void **)(self + 4), 0, 0x11);
    fn_8000A248();

    tex = fn_8006EDD8(*(void **)(self + 4), 0);
    pair = (u16 *)*tex;
    h = (f32)pair[1];
    w = (f32)pair[0];
    fn_80007898(1);
    fn_80007838(lbl_8036B580, lbl_8036B580, lbl_8036B580, lbl_8036B580);
    fn_80007818(h, w, h, w);
    fn_800076AC(0xFF, 0xFF, 0xFF, 0xFF);
    fn_80007884();

    fn_8000A258();
    fn_80009C0C(lbl_8036B568);
    fn_8000A248();

    node = *(void **)(*(u8 **)(self + 0x24) + 0xC);
    if (node != NULL) {
        poly = *(s16 **)((u8 *)node + 4);
        fn_8000A258();
        fn_80009F90(*(void **)(self + 4), *(u16 *)node, 0x11);
        fn_8000A248();
        while (poly[0] != -1) {
            fn_80007898(1);
            fn_80007838((f32)poly[0], (f32)poly[1], (f32)poly[0], (f32)poly[1]);
            fn_80007818((f32)poly[2], (f32)poly[3], (f32)poly[2], (f32)poly[3]);
            fn_800076AC(0x17, 0x2E, 0x56, 0xFF);
            fn_80007884();
            poly += 4;
        }
    }

    fn_8000A258();
    fn_80009C0C(lbl_8036B568);
    fn_8000A248();

    i = 0;
    ent = self;
    do {
        if ((s8)ent[0x61] != 0) {
            tex = fn_8006EDD8(*(void **)(self + 4), *(u16 *)(ent + 0x68));
            pair = (u16 *)*tex;
            h = (f32)pair[1];
            w = (f32)pair[0];
            fn_8000A258();
            fn_80009F90(*(void **)(self + 4), *(u16 *)(ent + 0x68), 0x10);
            fn_8000A248();
            fn_80007898(1);
            fn_800077D8(
                (f32)*(s16 *)(ent + 0x64),
                (f32)*(s16 *)(ent + 0x66),
                h, w);
            fn_800076AC(
                ent[0x6A], ent[0x6B], ent[0x6C],
                (u8)((ent[0x63] * 0xFF) / 255));
            fn_80007884();
        }
        ++i;
        ent += 0xE;
    } while (i < 0xA);

    fn_8000A258();
    fn_80009C0C(lbl_8036B568);
    fn_8000A248();

    if (*(u32 *)(*(u8 **)(self + 0x24) + 8) != 0) {
        fn_8000A258();
        fn_80009F90(*(void **)self, 0, 0x10);
        fn_8000A248();
        fn_80007898(0xB);
        fn_80007340(fn_801D0480, (u8 *)lbl_80331D00 + self[0xC] * 0x15C);
        fn_80007884();
    }

    fn_8000A258();
    fn_80009D74(
        (f32)*(s16 *)(self + 0x18),
        (f32)*(s16 *)(self + 0x1A),
        lbl_8036B5D0,
        *(f32 *)(self + 0x1C));
    fn_8000A248();

    i = 0;
    ent = self;
    do {
        if ((s8)ent[0xEC] != 0) {
            idx = (u16)((s8)ent[0xF2] + 2);
            tex2 = fn_8006EDD8(*(void **)self, idx);
            pair = (u16 *)*tex2;
            h = (f32)pair[1];
            w = (f32)pair[0];
            fn_8000A258();
            if (tex2[1] != NULL) {
                fn_80009EB0(*(void **)self, idx, 0, 0x10);
            } else {
                fn_80009F90(*(void **)self, idx, 0x10);
            }
            fn_8000A248();
            fn_80007898(1);
            fn_800077D8(
                (f32)*(s16 *)(ent + 0xEE),
                (f32)*(s16 *)(ent + 0xF0),
                h, w);
            fn_80007698(ent[0xF3]);
            fn_80007884();
        }
        i += 1;
        ent += 8;
    } while (8 > i);

    fn_8000A258();
    fn_80009B8C(0xFF);
    fn_8000A248();
}

#pragma use_lmw_stmw on
void fn_801D15D4(void *arg0) {
    s64 OSGetTime(void);
    s64 __div2i(s32, s32, s32, s32);
    s64 __mod2i(s32, s32, s32, s32);
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_Unlink(void *);
    extern u32 lbl_8036C528;
    extern u32 lbl_8036C52C;

    s32 sp18;
    s32 sp14;
    u8 sp10[4];
    s32 spC;
    u8 sp8[4];
    void *self;
    void *slot;
    void *p;
    void *obj;
    void *node;
    void *base;
    void **arr;
    s32 k;
    s32 i;
    s32 j;
    s32 v;
    s32 sum;
    s32 bit;
    s16 s;
    u8 r, g, b;
    u8 fl;
    u32 bus;
    u32 mag;
    u32 div;
    s64 t;

    self = arg0;
    t = OSGetTime();
    bus = *(u32 *)0x800000F8;
    mag = 0x10624DD3;
    bus = bus >> 2;
    div = (u32)(((u64)mag * bus) >> 32) >> 6;
    t = __div2i((s32)(t >> 32), (s32)t, 0, (s32)div);
    t = __mod2i((s32)(t >> 32), (s32)t, 0, 0xBB8);
    *(u32 *)((u8 *)self + 0x14C) = (u32)t;

    if (*(u32 *)((u8 *)self + 8) & 2) {
        *(u16 *)((u8 *)self + 0x154) = (u16)(*(u16 *)((u8 *)self + 0x154) + 1);
        {
            u8 a = *(u8 *)((u8 *)self + 0x158);
            u8 c = *(u8 *)((u8 *)self + 0x159);
            u16 d = *(u16 *)((u8 *)self + 0x154);
            u16 e = *(u16 *)((u8 *)self + 0x156);
            *(u8 *)((u8 *)self + 0x20) = (u8)Math_Ease(0, (f32)a, (f32)c, (f32)d, (f32)e);
        }
        if (*(u16 *)((u8 *)self + 0x154) >= *(u16 *)((u8 *)self + 0x156)) {
            *(u32 *)((u8 *)self + 8) = *(u32 *)((u8 *)self + 8) & ~2;
        }
    }

    p = self;
    for (k = 10; k != 0; k--) {
        switch ((s8)*(u8 *)((u8 *)p + 0x61)) {
        case 1:
            v = *(u8 *)((u8 *)p + 0x63) + 2;
            if (v < 0xFF) {
                *(u8 *)((u8 *)p + 0x63) = (u8)v;
            } else {
                *(u8 *)((u8 *)p + 0x61) = 2;
                *(u8 *)((u8 *)p + 0x63) = 0xFF;
            }
            break;
        case 2:
            v = *(u8 *)((u8 *)p + 0x63) - 2;
            if (v > 0x96) {
                *(u8 *)((u8 *)p + 0x63) = (u8)v;
            } else {
                *(u8 *)((u8 *)p + 0x61) = 3;
                *(u8 *)((u8 *)p + 0x63) = 0x96;
            }
            break;
        case 3:
            if (*(u8 *)((u8 *)p + 0x60) & 1) {
                *(u8 *)((u8 *)p + 0x61) = 4;
            }
            if (*(u8 *)((u8 *)p + 0x60) & 2) {
                *(u8 *)((u8 *)p + 0x61) = 4;
            }
            break;
        case 4:
            v = *(u8 *)((u8 *)p + 0x63) + 2;
            if (v < 0xFF) {
                *(u8 *)((u8 *)p + 0x63) = (u8)v;
            } else {
                *(u8 *)((u8 *)p + 0x61) = 5;
                *(u8 *)((u8 *)p + 0x63) = 0xFF;
            }
            break;
        case 5:
            v = *(u8 *)((u8 *)p + 0x63) - 2;
            if (v <= 0x96) {
                fl = *(u8 *)((u8 *)p + 0x60);
                v = 0x96;
                if (fl & 1) {
                    *(u8 *)((u8 *)p + 0x60) = (u8)(fl & ~3);
                    *(u8 *)((u8 *)p + 0x61) = 3;
                } else if (fl & 2) {
                    *(u8 *)((u8 *)p + 0x60) = (u8)(fl & ~1);
                    *(u8 *)((u8 *)p + 0x61) = 4;
                } else {
                    *(u8 *)((u8 *)p + 0x61) = 3;
                }
            }
            *(u8 *)((u8 *)p + 0x63) = (u8)v;
            break;
        case 0x63:
            v = *(u8 *)((u8 *)p + 0x63) - 2;
            if (v > 0) {
                *(u8 *)((u8 *)p + 0x63) = (u8)v;
            } else {
                *(u8 *)((u8 *)p + 0x61) = 0;
                *(u8 *)((u8 *)p + 0x63) = 0;
            }
            break;
        }
        p = (u8 *)p + 0xE;
    }

    i = 0;
    slot = self;
    do {
        obj = *(void **)((u8 *)slot + 0x2C);
        if (obj != NULL) {
            sp18 = *(s32 *)((u8 *)*(void **)((u8 *)obj + 0x30) + 0x38);
            r = ((u8 *)&sp18)[0];
            g = ((u8 *)&sp18)[1];
            b = ((u8 *)&sp18)[2];
        }
        switch ((s8)*(u8 *)((u8 *)slot + 0x28)) {
        case 1:
            s = (s16)(*(u8 *)((u8 *)slot + 0x29) + 5);
            if (s >= 0xFF) {
                s = 0xFF;
                *(u8 *)((u8 *)slot + 0x28) = 3;
            }
            *(u8 *)((u8 *)slot + 0x29) = (u8)s;
            if (obj != NULL) {
                *(u32 *)sp10 = lbl_8036C528;
                sp10[0] = r;
                sp10[1] = g;
                sp10[2] = b;
                sp10[3] = *(u8 *)((u8 *)slot + 0x29);
                sp14 = *(s32 *)sp10;
                node = *(void **)((u8 *)obj + 0x30);
                ((u8 *)node)[0x38] = ((u8 *)&sp14)[0];
                ((u8 *)node)[0x39] = ((u8 *)&sp14)[1];
                ((u8 *)node)[0x3A] = ((u8 *)&sp14)[2];
                ((u8 *)node)[0x3B] = ((u8 *)&sp14)[3];
            }
            break;
        case 5:
            s = (s16)((s16)*(u8 *)((u8 *)slot + 0x29) - 5);
            if (s <= 0) {
                *(u8 *)((u8 *)slot + 0x28) = 0;
                if (obj != NULL) {
                    Process_Unlink(*(void **)((u8 *)slot + 0x2C));
                    *(void **)((u8 *)slot + 0x2C) = NULL;
                }
            } else {
                *(u8 *)((u8 *)slot + 0x29) = (u8)s;
                if (obj != NULL) {
                    *(u32 *)sp8 = lbl_8036C52C;
                    sp8[0] = r;
                    sp8[1] = g;
                    sp8[2] = b;
                    sp8[3] = *(u8 *)((u8 *)slot + 0x29);
                    spC = *(s32 *)sp8;
                    node = *(void **)((u8 *)obj + 0x30);
                    ((u8 *)node)[0x38] = ((u8 *)&spC)[0];
                    ((u8 *)node)[0x39] = ((u8 *)&spC)[1];
                    ((u8 *)node)[0x3A] = ((u8 *)&spC)[2];
                    ((u8 *)node)[0x3B] = ((u8 *)&spC)[3];
                }
            }
            break;
        }
        i += 1;
        slot = (u8 *)slot + 8;
    } while (i < 7);

    p = self;
    for (k = 4; k != 0; k--) {
        switch ((s8)*(u8 *)((u8 *)p + 0xEC)) {
        case 1:
            v = *(u8 *)((u8 *)p + 0xF3) + 0xA;
            if (v > 0xFF) {
                v = 0xFF;
                *(u8 *)((u8 *)p + 0xEC) = 2;
            }
            *(u8 *)((u8 *)p + 0xF3) = (u8)v;
            break;
        case 3:
            v = *(u8 *)((u8 *)p + 0xF3) - 0xA;
            if (v < 0) {
                v = 0;
                *(u8 *)((u8 *)p + 0xEC) = 0;
            }
            *(u8 *)((u8 *)p + 0xF3) = (u8)v;
            break;
        }
        switch ((s8)*(u8 *)((u8 *)p + 0xF4)) {
        case 1:
            v = *(u8 *)((u8 *)p + 0xFB) + 0xA;
            if (v > 0xFF) {
                v = 0xFF;
                *(u8 *)((u8 *)p + 0xF4) = 2;
            }
            *(u8 *)((u8 *)p + 0xFB) = (u8)v;
            break;
        case 3:
            v = *(u8 *)((u8 *)p + 0xFB) - 0xA;
            if (v < 0) {
                v = 0;
                *(u8 *)((u8 *)p + 0xF4) = 0;
            }
            *(u8 *)((u8 *)p + 0xFB) = (u8)v;
            break;
        }
        p = (u8 *)p + 0x10;
    }

    v = *(u8 *)((u8 *)self + 0x21);
    if (*(u32 *)((u8 *)self + 8) & 4) {
        v = v - 0xA;
        if (v < 0) {
            v = 0;
        }
    } else {
        v = v + 0xA;
        if (v > 0xFF) {
            v = 0xFF;
        }
    }
    *(u8 *)((u8 *)self + 0x21) = (u8)v;

    {
        u32 flags = *(u32 *)((u8 *)self + 8);
        u32 sh = 0x800;
        v = *(u8 *)((u8 *)self + 0x14);
        if (flags & (sh << 0)) {
            v = v - 2;
            if (v < 0x32) v = 0x32;
        } else {
            v = v + 2;
            if (v > 0x64) v = 0x64;
        }
        *(u8 *)((u8 *)self + 0x14) = (u8)v;

        v = *(u8 *)((u8 *)self + 0x15);
        if (flags & (sh << 1)) {
            v = v - 2;
            if (v < 0x32) v = 0x32;
        } else {
            v = v + 2;
            if (v > 0x64) v = 0x64;
        }
        *(u8 *)((u8 *)self + 0x15) = (u8)v;

        v = *(u8 *)((u8 *)self + 0x16);
        if (flags & (sh << 2)) {
            v = v - 2;
            if (v < 0x32) v = 0x32;
        } else {
            v = v + 2;
            if (v > 0x64) v = 0x64;
        }
        *(u8 *)((u8 *)self + 0x16) = (u8)v;
    }

    if (*(u32 *)(*(u8 **)((u8 *)self + 0x24) + 8) != 0) {
        i = 0;
        p = self;
        j = 0;
        while (i < 3) {
            bit = 0x100 << i;
            if (*(void **)(*(u8 **)(*(u8 **)((u8 *)self + 0x24) + 8) + i) == NULL) {
                break;
            }
            if (*(u32 *)((u8 *)self + 8) & bit) {
                sum = 0;
                *(s16 *)((u8 *)p + 0xE) = (s16)(*(s16 *)((u8 *)p + 0xE) + 1);
                arr = *(void ***)(*(u8 **)((u8 *)self + 0x24) + 8);
                base = arr[i];
                j = 0;
                for (;;) {
                    if ((*(u16 *)base & 0x8000) != 0) {
                        *(u32 *)((u8 *)self + 8) &= ~bit;
                        break;
                    }
                    sum += ((u8 *)base)[0x13];
                    if (*(s16 *)((u8 *)p + 0xE) < (s16)sum) {
                        break;
                    }
                    if (*(s16 *)((u8 *)p + 0xE) == (s16)sum) {
                        if ((*(u16 *)((u8 *)arr[i] + j + 0x16) & 4) != 0) {
                            *(u32 *)((u8 *)self + 8) &= ~bit;
                            break;
                        }
                    }
                    base = (u8 *)base + 0x16;
                    j += 0x16;
                }
            }
            p = (u8 *)p + 2;
            i += 1;
        }
    }
}
#pragma use_lmw_stmw reset

#pragma cplusplus on
extern "C" void fn_801D1C80(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
    };
    ((Obj *)arg0)->v6();
}

#pragma cplusplus on
extern "C" void fn_801D1CAC(void *arg0) {
    void fn_8013ED84(void *, s16);
    void Ui_PlaySeCue(void *, s32);
    extern s32 gUiInputFlags;
    extern void *gPadInput;
    extern f64 lbl_8036B5D8;
    extern u8 lbl_8027E0F8[];
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v7() = 0;
        virtual void v6() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual void v11() = 0;
        virtual s32 v12() = 0;
    };
    s32 *pads;
    register s32 held;
    s32 pressed;
    s32 pad3;
    s16 temp_r0_2;
    s16 temp_r3;
    s16 temp_r4_2;
    s16 temp_r4_3;
    s16 temp_r4_4;
    s16 temp_r5;
    s16 temp_r7;
    s32 var_r3;
    s32 temp_r0;
    s32 temp_r4;
    s32 temp_r6;
    u8 var_r5;

    var_r3 = ((Obj *)arg0)->v12();
    temp_r0 = *(s32 *)((u8 *)arg0 + 0x6C);
    if ((s16)var_r3 > (s16)temp_r0) {
        var_r3 = (s16)temp_r0;
    }
    var_r5 = 0;
    temp_r7 = *(s16 *)((u8 *)arg0 + 0x4E);
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20)) {
        var_r5 = 1;
    }
    if (var_r5 == 0) {
        temp_r5 = *(s16 *)((u8 *)arg0 + 0x4E);
        pads = (s32 *)gPadInput;
        held = pads[1];
        pressed = held & (pads[2] ^ held);
        pad3 = pads[3];
        if ((s16)(s32)*(f32 *)((u8 *)arg0 + 0x5C) == 0) {
            if (pad3 & 0x08000008) {
                if (temp_r7 == 0) {
                    if (pad3 == pressed) {
                        temp_r4 = (s16)temp_r0 - (s16)var_r3;
                        temp_r6 = (s16)temp_r0 - 1;
                        *(s16 *)((u8 *)arg0 + 0x4E) = temp_r5 + temp_r6;
                        *(s16 *)((u8 *)arg0 + 0x54) = (temp_r4 > 0) ? temp_r4 : 0;
                        if (*(s16 *)((u8 *)arg0 + 0x4E) > temp_r6) {
                            *(s16 *)((u8 *)arg0 + 0x4E) = temp_r6;
                        }
                    }
                } else {
                    *(s16 *)((u8 *)arg0 + 0x4E) = temp_r5 - 1;
                    temp_r4_2 = *(s16 *)((u8 *)arg0 + 0x4E);
                    if (temp_r4_2 > 0) {
                        temp_r3 = *(s16 *)((u8 *)arg0 + 0x54);
                        if (temp_r4_2 - temp_r3 == 0) {
                            *(s16 *)((u8 *)arg0 + 0x54) = temp_r3 - 1;
                            *(f32 *)((u8 *)arg0 + 0x5C) = (f32)-*(s16 *)((u8 *)arg0 + 0x56);
                        }
                    }
                }
                if (temp_r5 != *(s16 *)((u8 *)arg0 + 0x4E)) {
                    *(s16 *)((u8 *)arg0 + 0x8E) = 1;
                    *(u8 *)((u8 *)arg0 + 0x85) = 1;
                }
            } else if (pad3 & 0x04000004) {
                register temp_r4_3 = (s16)temp_r0 - 1;
                if (temp_r7 == temp_r4_3) {
                    if (pad3 == pressed) {
                        *(s16 *)((u8 *)arg0 + 0x4E) = temp_r5 - temp_r4_3;
                        *(s16 *)((u8 *)arg0 + 0x54) = 0;
                    }
                } else {
                    *(s16 *)((u8 *)arg0 + 0x4E) = temp_r5 + 1;
                    if (*(s16 *)((u8 *)arg0 + 0x4E) > temp_r4_3) {
                        *(s16 *)((u8 *)arg0 + 0x4E) = temp_r4_3;
                    }
                    temp_r0_2 = *(s16 *)((u8 *)arg0 + 0x4E);
                    if (temp_r0_2 < temp_r4_3) {
                        temp_r4_4 = *(s16 *)((u8 *)arg0 + 0x54);
                        if ((s16)var_r3 - 1 == temp_r0_2 - temp_r4_4) {
                            *(s16 *)((u8 *)arg0 + 0x54) = temp_r4_4 + 1;
                            *(f32 *)((u8 *)arg0 + 0x5C) = (f32)*(s16 *)((u8 *)arg0 + 0x56);
                        }
                    }
                }
                if (temp_r5 != *(s16 *)((u8 *)arg0 + 0x4E)) {
                    *(s16 *)((u8 *)arg0 + 0xB6) = 1;
                    *(u8 *)((u8 *)arg0 + 0xAD) = 1;
                }
                if (temp_r5 != *(s16 *)((u8 *)arg0 + 0x4E)) {
                    Ui_PlaySeCue(lbl_8027E0F8 + 8, 0x64);
                }
            }
        }
    }
    fn_8013ED84(*(void **)((u8 *)arg0 + 0x48),
                (s16)(*(s16 *)((u8 *)arg0 + 0x56) * *(s16 *)((u8 *)arg0 + 0x54)
                      - (s32)*(f32 *)((u8 *)arg0 + 0x5C)));
}

extern "C" void fn_801D1F28(void *self, void *other)
{
    struct Obj {
        virtual void f0()=0; virtual void f1()=0; virtual void f2()=0;
        virtual void f3()=0;
        virtual void f4()=0; virtual void f5()=0; virtual void f6()=0;
        virtual void f7()=0; virtual void f8()=0; virtual void f9()=0;
        virtual s32 f10()=0;
    };
    void *Prim2D_PushZ(void *);
    void fn_80202574(void *, void *, f32, f32, f32);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    s32 Text_MeasureHeight(s32, f32);
    void Ui_DrawRouteIconEx(s16, s32, s32);
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    void Prim2D_ClearCallbacks(void);
    void Prim2D_SetAlphaByte(s32);

    extern f32 lbl_8036B5E0;
    extern f32 lbl_8036B5E4;
    extern f32 lbl_8036B5EC;
    extern f32 lbl_8036B5F0;
    extern f32 lbl_8036B5F4;

    s16 height;
    s32 width;
    s32 selected;
    s16 targetX;
    s16 targetY;
    s32 h2;
    u8 sp8[8];
    void *tmp;
    void *ptr;
    s32 x;
    s32 y;
    s32 i;
    u8 flag;

    ((Obj *)self)->f3();

    tmp = Prim2D_PushZ(sp8);
    fn_80202574(tmp, tmp, lbl_8036B5E4, lbl_8036B5E4, lbl_8036B5EC);

    width = ((Obj *)self)->f10();

    x = (s16)(*(s16 *)((u8 *)self + 0x4E) - *(s16 *)((u8 *)self + 0x54));
    height = *(s16 *)((u8 *)self + 0x56);
    targetX = (s16)(*(s16 *)((u8 *)self + 0x60) - 0x20);
    targetY = (s16)(height * x + *(s16 *)((u8 *)self + 0x62));

    if (*(s16 *)((u8 *)self + 0x50) < 0 || *(s16 *)((u8 *)self + 0x52) < 0) {
        *(s16 *)((u8 *)self + 0x50) = targetX;
        *(s16 *)((u8 *)self + 0x52) = targetY;
    } else {
        *(s16 *)((u8 *)self + 0x50) = (*(s16 *)((u8 *)self + 0x50) + targetX + 1) >> 1;
        *(s16 *)((u8 *)self + 0x52) = (*(s16 *)((u8 *)self + 0x52) + targetY + 1) >> 1;
    }

    if (*(u8 *)((u8 *)self + 0x4C) != 0 && *(u32 *)((u8 *)self + 0x6C) != 0) {
        selected = 0;
        flag = selected;
        if (*(u8 *)((u8 *)other + 0x2D) == 0) {
            if (*(u8 *)((u8 *)other + 0x2E) == 0) {
                flag = 1;
            }
        }
        if (flag) {
            if (*(u32 *)((u8 *)other + 0x34) != 0) {
                ptr = *(void **)(*(u8 **)((u8 *)other + 0x38) + 8);
            } else {
                ptr = 0;
            }
            if (ptr == self) {
                selected = 1;
            }
        }

        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B5F0);
        Prim2D_PrepareTex();

        h2 = *(s16 *)((u8 *)self + 0x56);
        i = Text_MeasureHeight(-1, lbl_8036B5E0);
        y = *(s16 *)((u8 *)self + 0x52) + (s16)(((s16)h2 - i) >> 1);
        Ui_DrawRouteIconEx(*(s16 *)((u8 *)self + 0x50), y, selected);

        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B5F4);
        Prim2D_PrepareTex();

        x = targetX - *(s16 *)((u8 *)self + 0x60) + ((s16)width >> 1) + 0x20;
        y = targetY + (height >> 1);
        fn_8008AB7C(x, y, (s16)width, 0x18, 0x19, 0x33, selected);
    }

    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
}

#pragma global_optimizer off
#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void fn_801D2118(void *arg0, s32 arg1) {
    struct Node { Node *prev; Node *next; void *obj; void *spr; void *data; };
    struct Obj {
        virtual void v0()=0; virtual void v1()=0; virtual void v2()=0;
        virtual void v3()=0; virtual void v4()=0;
        virtual void v5(s32)=0;
        virtual void v6()=0; virtual void v7()=0; virtual void v8()=0;
        virtual void v9()=0; virtual void v10()=0; virtual void v11()=0;
        virtual void v12()=0;
        virtual void v13()=0;
        virtual s32 v14()=0;
        virtual void v15(s16, s16, void *)=0;
        virtual void v16()=0;
        u8 pad4[6];
        s16 unkA, unkC;
        u8 padE[0x12-0xE];
        s16 a12, a14, a16, a18;
        u8 pad1A[0x22-0x1A];
        s16 a22;
        u8 pad24[0x54-0x24];
        s16 a54, a56;
        u8 pad58[0x5C-0x58];
        f32 a5c;
        s16 a60, a62;
        s16 rect[4];
        u32 a6c;
        u8 pad70[0x74-0x70];
        Node *list;
        u8 pad78[0x84-0x78];
        u8 flag84;
        u8 pad85[0xAC-0x85];
        u8 flagAC;
    };
    struct Sub {
        virtual void v0()=0; virtual void v1()=0; virtual void v2()=0;
        virtual void v3()=0; virtual void v4()=0; virtual void v5()=0;
        virtual void v6()=0; virtual void v7()=0; virtual void v8()=0;
        virtual void v9()=0; virtual void v10()=0;
        virtual void v11(s32)=0;
    };
    typedef void (Sub::*PTMF)(s32);
    struct Pair { PTMF ptmf; s32 arg; };
    void fn_8013F748(void *, s16 *, s16 *);
    void Prim2D_Begin(void); void Prim2D_PrepareTex(void); void Prim2D_ClearCallbacks(void);
    void Prim2D_AddZ(f32); void Prim2D_ScissorFromRect(void *);
    void Prim2D_SetCallback(void (*)(void *), s16 *);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXConcat(void *, void *, void *);
    void fn_802025E8(void *, void *, f32, f32, f32);
    void fn_80202574(void *, void *, f32, f32, f32);
    void Prim2D_SetTransform(f32, f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_AddPrim(s32);
    void fn_80007340(void *, s32);
    void Prim2D_EndPrim(void);
    void fn_8004BD1C(void *, f32 *, f32);
    u8 fn_800BE890(void *);
    void Model_SetColor(void *, s32, s32, s32);
    void Model_SetAlpha(void *, s32);
    void fn_8005F780(void *, s32);
    void fn_80060060(void *);
    void fn_800609DC(void *);
    void fn_8004DDB8(s32);
    extern f32 lbl_8036B5F8, lbl_8036B5E4, lbl_8036B5E8;
    extern f32 lbl_8036B5FC, lbl_8036B600, lbl_8036B604;
    extern f32 lbl_8036B608, lbl_8036B5E0, lbl_8036B60C, lbl_8036B610;
    extern f32 lbl_80367098[];
    extern PTMF lbl_80299980;
    extern void fn_801D2E9C;
    extern void fn_80069F04;
    u8 *raw;
    Obj *self;
    s32 arg;
    s32 visible;
    s16 index, idx0, row_h, scroll, sign, n, row, endrow;
    s16 xbase, xoff, y;
    s32 ypos;
    s16 *rect;
    s16 w, h;
    Node *node;
    Node *it, *sent;
    void *spr;
    f32 fx, fy;
    f32 sp28[2];
    u8 sp34[0x30];
    u8 sp64[0x30];
    Pair p[2];

    raw = (u8 *)arg0;
    self = (Obj *)arg0;
    arg = arg1;
    self->v16();
    self->v5(arg);
    rect = self->rect;
    h = (s16)(self->a18 - self->a14);
    w = (s16)(self->a16 - self->a12);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = w;
    rect[3] = h;
    fn_8013F748(self, rect, rect);
    rect = self->rect + 2;
    fn_8013F748(self, rect, rect);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B5F8);
    Prim2D_SetCallback(Prim2D_ScissorFromRect, self->rect);
    Prim2D_PrepareTex();

    visible = self->v14();
    idx0 = self->a54;
    index = idx0;
    self->v12();
    {
        f32 zero = lbl_8036B5E4;
        f32 fval = self->a5c;
        scroll = (s16)fval;
        row_h = self->a56;
        if (fval < zero) {
            f32 value = (f32)row_h * lbl_8036B5E8 + self->a5c;
            self->a5c = value;
            if (value >= -lbl_80367098[0]) {
                self->a5c = zero;
            }
        } else if (fval > zero) {
            f32 value = self->a5c - (f32)row_h * lbl_8036B5E8;
            self->a5c = value;
            if (value <= lbl_80367098[0]) {
                self->a5c = zero;
            }
        }
    }
    if (scroll < 0) {
        sign = -1;
    } else {
        sign = (s16)(scroll > 0);
    }
    if (sign > 0 && idx0 >= 0) {
        index = (s16)(index - 1);
    }
    node = self->list;
    n = index;
    if (index >= 0) {
        while (n > 0) {
            node = node->next;
            n = (s16)(n - 1);
        }
    } else {
        while (n < 0) {
            node = node->prev;
            n = (s16)(n + 1);
        }
    }
    xbase = self->a60;
    row = (s16)((-sign & ~sign) >> 31);
    endrow = (s16)visible;
    if (sign < 0) {
        endrow = (s16)(endrow + 1);
    }
    ypos = (s32)row * (s32)row_h;
    for (; row < endrow; ypos += row_h, row = (s16)(row + 1), index = (s16)(index + 1)) {
        if ((u32)(s16)index >= self->a6c) {
            break;
        }
        y = (s16)(scroll + ypos + self->a62);
        self->v15(xbase, y, (u8 *)node + 8);
        node = node->next;
    }

    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_PrepareTex();
    self->v5(arg);

    index = self->a54;
    if (sign > 0 && index >= 0) {
        index = (s16)(index - 1);
    }
    node = self->list;
    n = index;
    if (index >= 0) {
        while (n > 0) {
            node = node->next;
            n = (s16)(n - 1);
        }
    } else {
        while (n < 0) {
            node = node->prev;
            n = (s16)(n + 1);
        }
    }
    xoff = (s16)(self->a60 - 0x10);
    PSMTXRotRad(sp34, 0x79, lbl_8036B5FC);
    PSMTXRotRad(sp64, 0x78, lbl_8036B600);
    PSMTXConcat(sp64, sp34, sp64);
    fn_802025E8(sp64, sp64, lbl_8036B604, lbl_8036B604, lbl_8036B604);
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B5E4, lbl_8036B5E4, lbl_8036B608 + (f32)self->a22, lbl_8036B5E0, lbl_8036B608);
    Prim2D_SetTex(0, 0x410);
    Prim2D_SetColorByte(0xFF);
    if ((s16)self->a5c != 0) {
        Prim2D_SetCallback(Prim2D_ScissorFromRect, self->rect);
    }
    Prim2D_PrepareTex();
    Prim2D_AddPrim(0xB);
    fn_80007340(&fn_801D2E9C, 0);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B60C);
    Prim2D_PrepareTex();

    row = (s16)((-sign & ~sign) >> 31);
    endrow = (s16)visible;
    if (sign < 0) {
        endrow = (s16)(endrow + 1);
    }
    ypos = (s32)row * (s32)row_h;
    for (; row < endrow; ypos += row_h, row = (s16)(row + 1), index = (s16)(index + 1)) {
        if ((u32)(s16)index >= self->a6c) {
            break;
        }
        spr = node->spr;
        y = (s16)(ypos + self->a62 + self->a56 + scroll);
        if (spr != NULL) {
            fx = (f32)(s16)(xoff + self->unkA);
            fy = (f32)(s16)(y + self->unkC);
            fn_8004BD1C(node->data, sp28, lbl_8036B604);
            fx += sp28[0];
            fy += sp28[1];
            fn_80202574(sp64, (u8 *)spr + 0x10, fx, fy, (f32)self->a22);
            if (fn_800BE890(node->obj) != 0) {
                *(u32 *)spr &= ~0x20000u;
            } else {
                *(u32 *)spr |= 0x20000u;
            }
            Model_SetColor(spr, 0x80, 0x80, 0x80);
            Model_SetAlpha(spr, 0xFF);
            fn_8005F780(spr, 0xFF);
            fn_80060060(spr);
            fn_800609DC(spr);
            Prim2D_AddPrim(0xB);
            fn_80007340(&fn_80069F04, (s32)spr);
            Prim2D_EndPrim();
        }
        node = node->next;
    }

    fn_8004DDB8(self->a22 - 1);
    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_PrepareTex();
    self->v5(arg);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B610);
    Prim2D_PrepareTex();

    self->flag84 = (u8)(self->a54 > 0);
    {
        s16 diff = (s16)((s16)self->a6c - (s16)self->v14());
        self->flagAC = (u8)(self->a54 < diff);
    }
    ((Sub *)(raw + 0x78))->v11(0x10);
    ((Sub *)(raw + 0xA0))->v11(0x10);
    {
        void *bar = *(void **)(raw + 0x48);
        *(s16 *)((u8 *)bar + 0x3C) = (s16)((s16)self->a6c * row_h);
        *(s16 *)((u8 *)bar + 0x3E) = (s16)((s16)visible * row_h);
        *(s16 *)((u8 *)bar + 0x40) = (s16)((row_h * self->a54) - scroll);
    }
    p[0].ptmf = lbl_80299980;
    p[0].arg = arg;
    p[1].ptmf = lbl_80299980;
    p[1].arg = arg;
    it = *(Node **)(raw + 0x44);
    sent = (Node *)(raw + 0x40);
    while (it != sent) {
        (((Sub *)it->obj)->*p[0].ptmf)(p[0].arg);
        it = it->next;
    }
}
#pragma cplusplus reset
#pragma use_lmw_stmw reset
#pragma global_optimizer reset

#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_801D283C(void *arg0) {
    void fn_8015BAA8(s32, s32, s16, s16, s32, s32);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    ((Obj *)arg0)->v2();
    fn_8015BAA8(0, 0,
        (s16)(*(s16 *)((u8 *)arg0 + 0xE) - *(s16 *)((u8 *)arg0 + 0xA)),
        (s16)(*(s16 *)((u8 *)arg0 + 0x10) - *(s16 *)((u8 *)arg0 + 0xC)),
        0xFF, 0x10);
}
#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on
#pragma optimization_level 2
#pragma global_optimizer off
extern "C" void fn_801D28A8(u8 *self,s32 x,s32 y,u8 *item) {
void Prim2D_Begin(); void Prim2D_SetTex(s32,u16); void Prim2D_PrepareTex();
s32 Text_MeasureHeight(s32,f32); u8 fn_800BE890(s32);
void *Msg_ResolveName(void*); void *fn_800BE728(s32); void *Msg_Expand(void*);
void Text_Draw(s32,s16,u8,void*,...); void Ui_DrawLine(s16,s16,s16,s16,s32,u8*);
s32 fn_800BE798(s32); void fn_80152B4C(s16,s16,s32,s32);
extern f32 lbl_8036B5E0;
u8 color[4]; s32 pad; s32 disabled; void *text;
s16 h1; s16 h; s16 left,width; s32 half; s32 lineY;
Prim2D_Begin(); Prim2D_SetTex(0,(u16)(*(u32*)(self+0x34)|0x13)); Prim2D_PrepareTex();
h1=*(s16*)(self+0x56);
pad=(s16)(((s16)h1-Text_MeasureHeight(-1,lbl_8036B5E0))>>1);
disabled=fn_800BE890(*(s32*)item)?0:1;
if(*(void**)(item+8)) text=Msg_ResolveName(*(void**)((u8*)*(void**)(item+8)+0x188));
else text=Msg_Expand(fn_800BE728(*(s32*)item));
s32 yy=(s16)y;
Text_Draw(x,(s16)(yy+pad),(u8)disabled,text);
width=(s16)(((MenuD28*)self)->v10()-*(s16*)(self+0x60)-0x10);
s32 xx=(s16)x;
left=(s16)(xx-0x10);
h=*(s16*)(self+0x56);
half=((s16)h-Text_MeasureHeight(-1,lbl_8036B5E0))>>1;
s32 textH=Text_MeasureHeight(-1,lbl_8036B5E0);
lineY=(s16)(yy+(s16)(textH+half));
s16 right=(s16)(left+width);
color[0]=255; color[1]=255; color[2]=255; color[3]=0x33;
Ui_DrawLine(left,lineY,right,lineY,0x10,color);
s32 value=fn_800BE798(*(s32*)item);
s32 baseline=yy+pad; s32 numberX=xx+0xc0;
fn_80152B4C((s16)numberX,(s16)(baseline+6),value,0x10);
}
#pragma optimization_level reset
#pragma global_optimizer reset
#pragma use_lmw_stmw reset
#pragma cplusplus off
s32 fn_801D2A38(void *arg0) {
    s32 fn_800BE890(s32);
    struct Node {
        struct Node *prev;
        struct Node *next;
        s32 unk8;
    };
    s32 tmp;
    s16 n;
    struct Node *node;

    if (*(u32 *)((u8 *)arg0 + 0x6C) == 0) {
        return 0;
    }
    tmp = *(s16 *)((u8 *)arg0 + 0x4E);
    node = *(struct Node **)((u8 *)arg0 + 0x74);
    n = (s16)tmp;
    if (n >= 0) {
        goto loop_pos;
        do {
            node = node->next;
            n -= 1;
        loop_pos:
            ;
        } while (n > 0);
    } else {
        goto loop_neg;
        do {
            node = node->prev;
            n += 1;
        loop_neg:
            ;
        } while (n < 0);
    }
    return fn_800BE890(node->unk8);
}

int fn_801D2AAC(void *arg0) {
    struct Node {
        struct Node *prev;
        struct Node *next;
        s32 unk8;
    };
    s32 tmp;
    s16 n;
    struct Node *node;

    if (*(u32 *)((u8 *)arg0 + 0x6C) == 0) {
        return 0;
    }
    tmp = *(s16 *)((u8 *)arg0 + 0x4E);
    node = *(struct Node **)((u8 *)arg0 + 0x74);
    n = (s16)tmp;
    if (n >= 0) {
        goto loop_pos;
        do {
            node = node->next;
            n -= 1;
        loop_pos:
            ;
        } while (n > 0);
    } else {
        goto loop_neg;
        do {
            node = node->prev;
            n += 1;
        loop_neg:
            ;
        } while (n < 0);
    }
    return node->unk8;
}

s32 fn_801D2B04(void *arg0) {
    s32 Msg_Expand(void);
    s32 Msg_ResolveName(s32);
    void fn_800BE728(s32);
    struct Node {
        struct Node *prev;
        struct Node *next;
        s32 unk8;
        u8 padC[4];
        void *unk10;
    };
    s32 tmp;
    s16 n;
    struct Node *node;
    void *p;

    if (*(u32 *)((u8 *)arg0 + 0x6C) == 0) {
        return 0;
    }
    tmp = *(s16 *)((u8 *)arg0 + 0x4E);
    node = *(struct Node **)((u8 *)arg0 + 0x74);
    n = (s16)tmp;
    if (n >= 0) {
        goto loop_pos;
        do {
            node = node->next;
            n -= 1;
        loop_pos:
            ;
        } while (n > 0);
    } else {
        goto loop_neg;
        do {
            node = node->prev;
            n += 1;
        loop_neg:
            ;
        } while (n < 0);
    }
    p = node->unk10;
    if (p != NULL) {
        return Msg_ResolveName(*(s32 *)((u8 *)p + 0x188));
    }
    fn_800BE728(node->unk8);
    return Msg_Expand();
}

#pragma optimization_level 3
void fn_801D2B94(s32 *arg0, void *arg1) {
    s32 *fn_8013F748(void *, M2C_UNK *, s16 *, s16, s32, s16);
    M2C_UNK spC;
    s16 pt[2];
    s16 temp_r6;
    s16 temp_r6_2;
    s32 temp_r7;
#pragma cplusplus on
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
    };
    ((Obj *)arg1)->v10();
#pragma cplusplus reset

    temp_r6 = M2C_FIELD(arg1, s16 *, 0x4E) - M2C_FIELD(arg1, s16 *, 0x54);
    temp_r6_2 = M2C_FIELD(arg1, s16 *, 0x62);
    temp_r7 = M2C_FIELD(arg1, s16 *, 0x56) * temp_r6;
    pt[0] = M2C_FIELD(arg1, s16 *, 0x60);
    pt[1] = (s16)(temp_r7 + temp_r6_2);
    *arg0 = *fn_8013F748(arg1, &spC, pt, temp_r6_2, temp_r7, temp_r6);
}
#pragma optimization_level reset
void *fn_801D2C20(void) {
    extern u16 lbl_8027E0F8[];
    return &lbl_8027E0F8[0x12];
}

#pragma cplusplus on
extern "C" void fn_801D2C30(void *arg0) {
    void fn_801C1824(void *, void *, void *, void *);
    void fn_801D2FE4(void *, void *, void *, void *);
    s32 fn_800BE914(void);
    u8 fn_800BE800(s32);
    s32 fn_800BE728(s32);
    u8 Id_GetKind(void);
    u32 Unit_FindByName(s32);
    void fn_800616A0(void *);
    void *GActor_Create(void);
    void fn_800506E0(u32, s32, void *);
    s32 fn_800639B4(void);
    void GActor_Finalize(void *);

    struct Obj {
        virtual void v0() {}
        virtual void v1() {}
        virtual void v2() {}
        virtual void v3() {}
        virtual void v4() {}
        virtual void v5() {}
        virtual void v6() {}
        virtual void v7() {}
        virtual void v8() {}
        virtual void v9() {}
        virtual void v10() {}
        virtual void v11() {}
        virtual s16 v12() { return 0; }
    };

    struct Self {
        u8 unk00[0x4E];
        s16 field4E;
        u8 unk50[4];
        s16 field54;
        u8 unk56[0x16];
        u32 count;
        u8 unk70[4];
        void *field74;
    };

    void *sp18;
    void *sp14;
    s32 sp10;
    void *spC;
    s32 sp8;
    struct {
        s32 idx;
        void *node;
        u32 unit;
    } row;
    u32 unit;
    s32 item;
    s16 cur;
    void *endPtr;
    s32 idx;
    Self *self;
    s32 total;
    void **p14;
    void **p18;

    self = (Self *)arg0;
    endPtr = (u8 *)self + 0x70;
    cur = self->field4E;
    p14 = &sp14;
    p18 = &sp18;
    *p18 = endPtr;
    *p14 = self->field74;
    fn_801C1824(&sp10, &self->count, p14, p18);
    total = fn_800BE914();
    idx = 0;
    while (idx < total) {
        if (fn_800BE800(idx) != 0) {
            s32 kind;
            row.idx = idx;
            row.node = 0;
            row.unit = 0;
            item = fn_800BE728(idx);
            unit = 0;
            kind = (s32)(u8)Id_GetKind();
            if (kind == 5) {
            } else if (kind >= 5) {
            } else {
                switch (kind) {
                case 1:
                    unit = Unit_FindByName(item);
                    break;
                }
            }
            if (unit != 0) {
                u32 *p;
                if (row.node != 0) {
                    fn_800616A0(row.node);
                }
                row.node = GActor_Create();
                *(s32 *)((u8 *)row.node + 4) = (s32)(unit + 0x1C);
                p = (u32 *)row.node;
                *p = *p | 0x50028400;
                fn_800506E0(unit, 0, p);
                *(s32 *)((u8 *)row.node + 0x44) = fn_800639B4();
                row.unit = unit;
                *(u32 *)((u8 *)row.node + 0x90) = unit;
                GActor_Finalize(row.node);
            }
            spC = endPtr;
            fn_801D2FE4(&sp8, &self->count, &spC, &row);
            if (row.node != 0) {
                fn_800616A0(row.node);
            }
        }
        idx += 1;
    }
    {
        u32 count = self->count;
        s32 cur32 = cur;
        register u32 last = count - 1;
        s16 v;
        s16 scroll;
        if ((u32)cur32 > last) {
            cur = (s16)last;
        }
        if (cur < 0) {
            cur = 0;
        }
        v = ((Obj *)self)->v12();
        if (count <= (u32)v) {
            self->field4E = cur;
            self->field54 = 0;
        } else {
            scroll = self->field54;
            if ((u32)(count - scroll) < (u32)v) {
                self->field4E = cur;
                self->field54 = (s16)(count - v);
            } else if (scroll < cur && (s32)(cur - scroll) < (s32)(v - 1)) {
                self->field4E = cur;
            } else if (cur == 0) {
                self->field54 = cur;
                self->field4E = cur;
            } else {
                self->field4E = cur;
                self->field54 = (s16)(cur - 1);
            }
        }
    }
}
#pragma cplusplus reset

void *fn_801D2E40(void *arg0, s16 arg1) {
    void fn_800616A0(void *);
    void Heap_Free(void *);
    void *temp;

    if (arg0 != NULL) {
        temp = *(void **)((u8 *)arg0 + 4);
        if (temp != NULL) {
            fn_800616A0(temp);
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void fn_801D2E9C(void) {
    void fn_80059C2C(int, int, int, int, int);
    fn_80059C2C(0, 0, 0x260, 0x1C0, 0);
}

#pragma cplusplus on
extern "C" void *Ui_DtorScrollListPanel(void *self, s16 doFree) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    typedef struct DtorNode {
        struct DtorNode *prev;
        struct DtorNode *next;
    } DtorNode;
    typedef struct {
        u32 unk0;
        DtorNode node;
    } DtorList;
    typedef struct Owner {
        void *vtbl;
        u8 pad4[0x68];
        DtorList list;
        void *sub78;
        u8 pad7C[0x24];
        void *subA0;
    } Owner;
    void fn_801C1824(void *, void *, void *, void *);
    void fn_8013F2A4(void *, s32);
    void Heap_Free(void *);
    extern u8 gUiScrollListPanelVtbl[];
    extern u8 gEmptyVtbl[];

    DtorNode *sp10;
    DtorNode *spC;
    u8 sp8[4];
    DtorNode *end;
    Owner *owner;

    /* C++ destructor for scroll-list UI panel: destroy embeds, clear list, run base dtor, optional free. */
    owner = (Owner *)self;
    if (self) {
        owner->vtbl = gUiScrollListPanelVtbl;
        if (&owner->subA0) {
            owner->subA0 = gEmptyVtbl;
            ((Obj *)&owner->subA0)->v2();
        }
        if (&owner->sub78) {
            owner->sub78 = gEmptyVtbl;
            ((Obj *)&owner->sub78)->v2();
        }
        if (&owner->list) {
            if (&owner->list) {
                if (&owner->list) {
                    end = &owner->list.node;
                    sp10 = end;
                    spC = end->next;
                    fn_801C1824(sp8, &owner->list, &spC, &sp10);
                }
            }
        }
        fn_8013F2A4(self, 0);
        if (doFree > 0) {
            Heap_Free(self);
        }
    }
    return self;
}
#pragma cplusplus reset

s32 fn_801D2FC0(void *arg0) {
 return (s16)(M2C_FIELD(arg0, s16 *, 0x16) - M2C_FIELD(arg0, s16 *, 0x12));
}

void fn_801D2FD4(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x58) = arg1;
}

s16 fn_801D2FDC(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x58);
}

void fn_801D2FE4(void **outNode, s32 *listHead, void ***insertBefore, s32 *unitPtr) {
void *Heap_Alloc(s32);
void Heap_Free(void *);
void fprintf(void *,void *,...);
void abort(void);
void fn_800616A0(void *);
void *GActor_Create(void);
void fn_800506E0(s32,s32,void *);
s32 fn_800639B4(void);
void GActor_Finalize(void *);
#pragma cplusplus on
    struct Obj {
        u32 flags;
        s32 unk4;
        u8 pad8[0x3C];
        s32 anim;
        u8 pad48[0x48];
        s32 source;
    };
    struct Value {
        s32 unit;
        Obj *actor;
        s32 source;
    };
    struct Node {
        Node *prev;
        Node *next;
        Value value;
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
    extern char __files[];
    extern char lbl_8027E0F8[];
    Value *value;
    Node *node;
    void *list;
    u32 unit;
    Obj *actor;
    Node *pos;
    Node *n;

    // Copy the actor value and splice its node into the list.
    list = listHead + 1;
    node = (Node *)Heap_Alloc(0x14);
    if (node == 0) {
        fprintf(__files + 0xA0, lbl_8027E0F8 + 0x34);
        abort();
    }
    {
        Holder h(list, node);
        value = &h.node->value;
        if (value != 0) {
            value->unit = unitPtr[0];
            unit = unitPtr[2];
            value->actor = 0;
            value->source = 0;
            if(unit != 0) {
            if (value->actor != 0) {
                fn_800616A0(value->actor);
            }
            value->actor = (Obj *)GActor_Create();
            value->actor->unk4 = unit + 0x1C;
            actor = value->actor;
            actor->flags |= 0x50028400;
            fn_800506E0(unit, 0, actor);
            value->actor->anim = fn_800639B4();
            value->source = unit;
            value->actor->source = unit;
            GActor_Finalize(value->actor);
            }
        }
        pos = (Node *)*insertBefore;
        n = h.node;
        h.node = 0;
        pos->prev->next = n;
        n->prev = pos->prev;
        pos->prev = n;
        n->next = pos;
        (*listHead)++;
        *outNode = n;
    }
#pragma cplusplus reset
}

u32 fn_801D3124(void) {
void Allegiance_SetMask(s32,s32,s32,s32,s32,s32,s32,s32,void *);
extern u8 gBattleState[],gUnits[];
u8 mask[8];
s32 i;
u8 *unit;
u32 result=gBattleState[0x10]>=10U;
if (!result) {
*(u32*)(gBattleState+0x6C)=0;
*(u32*)(gBattleState+0x68)=0;
*(s16*)(gBattleState+0x70)=0;
*(s16*)(gBattleState+0x72)=0;
Allegiance_SetMask(1,0,0,0,0,1,1,1,mask);
for(i=1;i<=0x9F;i++) {
if ((u8)i) unit=gUnits+((u8)i-1)*0x280; else unit=NULL;
if (*(u32*)(unit+0x188) && mask[*(u8*)(*(u8**)(unit+0x190)+8)]) {
*(u32*)(unit+0x1A0)&=0xFFF77FFF;
*(s16*)(unit+0x22C)=0;
}
}
}
return result;
}

void *fn_801D322C(s32 arg0) {
    void *Process_CreateChild(void *, s32);
    void fn_801403F0(void);
    extern u16 lbl_802999D0[];
    void *temp_r3;

    temp_r3 = Process_CreateChild(lbl_802999D0, arg0);
    if (temp_r3 != NULL) {
        fn_801403F0();
        *(s32 *)((char *)temp_r3 + 0x40) = 0;
        *(s32 *)((char *)temp_r3 + 0x48) = 0;
        *(s32 *)((char *)temp_r3 + 0x4C) = 0;
        *(s32 *)((char *)temp_r3 + 0x50) = 0;
        *(s32 *)((char *)temp_r3 + 0x4C) = 0;
    }
    return temp_r3;
}

void fn_801D3288(void *self) {
void fn_8003F670(void*); void fn_80161F7C(void); void *fn_8014D8FC(void*); void fn_80109020(void*); void String_Destroy(void*,s32); void Ui_DtorPanelBase(void*,s32);
void Allegiance_SetMask(s32,s32,s32,s32,s32,s32,s32,s32,void *);
void EventFlag_Clear(void*,void*); void fn_80089650(s32,s32); void fn_8008A290(s32,s32); s8 Fx_FindSlotByName(void*); void fn_801480D8(s32);
extern u16 gUiPanelFlags; extern u32 gUiInputFlags;
extern u8 gBattleState[],gUnits[],gBattleUiStrings[];
u8 mask[8];
s32 i;
u8 *unit;
gUiPanelFlags &= ~0x10;
fn_8003F670(*(void**)((u8*)self+0x44));
fn_80161F7C();
fn_80109020(*(void**)((u8*)fn_8014D8FC(gBattleState)+0x44));
if(self) { String_Destroy((u8*)self+0x48,-1); Ui_DtorPanelBase(self,0); }
*(u32*)(gBattleState+0x6C)=0;
*(u32*)(gBattleState+0x68)=0;
*(s16*)(gBattleState+0x70)=0;
*(s16*)(gBattleState+0x72)=0;
Allegiance_SetMask(1,0,0,0,0,1,1,1,mask);
for(i=1;i<=0x9F;i++) {
if ((u8)i) unit=gUnits+((u8)i-1)*0x280; else unit=NULL;
if (*(u32*)(unit+0x188) && mask[*(u8*)(*(u8**)(unit+0x190)+8)]) {
*(u32*)(unit+0x1A0)&=0xFFF77FFF;
*(s16*)(unit+0x22C)=0;
}
}
EventFlag_Clear(gBattleState+0xb4,gBattleUiStrings+0x2d);
gUiInputFlags &= ~3;
fn_80089650(0,0); fn_8008A290(1,0);
if(Fx_FindSlotByName(gBattleUiStrings+0x39)) fn_801480D8(0x2ee);
}

void fn_801D341C(void) {
    void TalkUi_ShowMsg(void *);
    void sprintf(void *, ...);
    extern u8 lbl_803682DC;
    extern void *lbl_803682D8;
    extern u8 gBattleUiStrings[];
    extern u8 gBattleState[];

    if ((s8)lbl_803682DC == 0) {
        lbl_803682DC = 1;
        lbl_803682D8 = &gBattleUiStrings[0x45];
    }

    sprintf(lbl_803682D8, &gBattleUiStrings[0x54], gBattleState[0x10], &gBattleUiStrings);
    TalkUi_ShowMsg(lbl_803682D8);
}

void fn_801D3488(s32 arg0) {
    void Process_ClearFunc(s32);
    void TalkUi_ShowMsg(void *);
    void sprintf(void *, ...);
    extern u8 lbl_803682D4;
    extern void *lbl_803682D0;
    extern u8 gBattleUiStrings[];
    extern u8 gBattleState[];

    if ((s8)lbl_803682D4 == 0) {
        lbl_803682D4 = 1;
        lbl_803682D0 = &gBattleUiStrings[0x65];
    }

    sprintf(lbl_803682D0, &gBattleUiStrings[0x76], gBattleState[0x10], &gBattleUiStrings);
    TalkUi_ShowMsg(lbl_803682D0);
    Process_ClearFunc(arg0);
}

void fn_801D3508(s32 arg0) {
    void Process_ClearFunc(s32);
    void TalkUi_ShowMsg(void *);
    void sprintf(void *, ...);
    extern u8 lbl_803682CC;
    extern void *lbl_803682C8;
    extern u8 gBattleUiStrings[];
    extern u8 gBattleState[];

    if ((s8)lbl_803682CC == 0) {
        lbl_803682CC = 1;
        lbl_803682C8 = &gBattleUiStrings[0x89];
    }

    sprintf(lbl_803682C8, &gBattleUiStrings[0x98], gBattleState[0x10], &gBattleUiStrings);
    TalkUi_ShowMsg(lbl_803682C8);
    Process_ClearFunc(arg0);
}

void fn_801D3588(s32 arg0) {
    void Process_Goto(s32, s32);
    extern u8 gUnitLists[];
    u8 *node;
    u32 flags;

    node = *(u8 **)(gUnitLists + 0x48);
    while (node != NULL) {
        flags = *(u32 *)(node + 0x1A0);
        node = *(u8 **)(node + 0x184);
        if (flags & 0x8000) {
            Process_Goto(arg0, 2);
            return;
        }
    }
    Process_Goto(arg0, 3);
}

#pragma cplusplus on
extern "C" void Ui_HandleOverlayDismissInput(void *proc) {
    /* Tick child 0x10 each frame; on A/B play SE, close-animate it, and clear this callback. */
    void Process_ClearFunc(void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_CloseChildAnim(void *, void *, s32);
    void Ui_PlaySeCue(void *, s32);
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern u8 gBattleUiStrings[];
    struct Widget {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7(void *) = 0;
    };
    u8 inputLocked;
    unsigned long held;
    s32 flags;

    if (gUiInputFlags & 3) {
        Process_ClearFunc(proc);
        return;
    }
    ((Widget *)Ui_FindChild(proc, 0x10, 0))->v7(proc);
    inputLocked = 0;
    flags = gUiInputFlags;
    if (flags & 0x10) {
        if (!(flags & 0x20)) {
            inputLocked = 1;
        }
    }
    if (inputLocked == 0) {
        held = *(s32 *)((char *)gPadInput + 4);
        if (held & (*(s32 *)((char *)gPadInput + 8) ^ held) & 0x300) {
            Ui_PlaySeCue(gBattleUiStrings + 0xA9, 0x64);
            Ui_CloseChildAnim(proc, Ui_FindChild(proc, 0x10, 0), 0);
            Process_ClearFunc(proc);
        }
    }
}
#pragma cplusplus reset

void fn_801D36B8(void *arg0) {
    void *Heap_Alloc(s32);
    void *fn_801D3860(void *, s32, s32, s32);
    void Ui_AddChild(void *, void *);
    void Ui_OpenChildAnim(void *, void *, s32);
    extern s32 gUiInputFlags;
    void *obj;

    if ((gUiInputFlags & 3) == 0) {
        obj = Heap_Alloc(0xA0);
        if (obj != NULL) {
            obj = fn_801D3860(obj, 0x40, 0x10, 0xA);
        }
        *(s16 *)((u8 *)obj + 8) = 0x10;
        *(u32 *)((u8 *)obj + 0x34) |= 0x10;
        *(s16 *)((u8 *)obj + 0x24) = 8;
        Ui_AddChild(arg0, obj);
        Ui_OpenChildAnim(arg0, obj, 1);
    }
}

void fn_801D3750(s32 arg0) {
    void fn_8011D908(void *, s32);
    void sprintf(void *, ...);
    extern u8 lbl_803682C4;
    extern void *lbl_803682C0;
    extern u8 gBattleUiStrings[];
    extern u8 gBattleState[];

    if ((s8)lbl_803682C4 == 0) {
        lbl_803682C4 = 1;
        lbl_803682C0 = &gBattleUiStrings[0xB9];
    }

    sprintf(lbl_803682C0, &gBattleUiStrings[0xCA], gBattleState[0x10], &gBattleUiStrings);
    fn_8011D908(lbl_803682C0, arg0);
}

void fn_801D37CC(void *arg0) {
    s32 Archive_Load();
    M2C_UNK fn_80162054();
    M2C_UNK fn_801620AC();
    extern s32 gUiInputFlags;
    fn_801620AC();
    M2C_FIELD(arg0, s32 *, 0x44) = Archive_Load();
    fn_80162054();
    gUiInputFlags &= 0xFFFFFFFC;
}

void fn_801D3810(s32 arg0) {
    void fn_800C0BAC(s32);
    void fn_8013FE0C(void);
    extern void *gPadInput;
    s32 temp_r4;

    fn_8013FE0C();
    temp_r4 = ((s32 *)gPadInput)[1];
    if (temp_r4 & (((s32 *)gPadInput)[2] ^ temp_r4) & 0x1000) {
        fn_800C0BAC(arg0);
    }
}

#pragma cplusplus on
#pragma opt_common_subs off
#pragma dont_inline on
#pragma global_optimizer on
extern "C" void *fn_801D3860(void *arg0,s32 x,s32 y,s32 id) {
extern u8 lbl_8028FDB0[],lbl_80292230[],gUiPanelDVtbl[],gEmptyVtbl[],gBattleState[];
extern const f32 lbl_8036B618,lbl_8036B61C;
struct Obj {virtual void v0()=0;virtual void v1()=0;virtual void v2()=0;virtual void v3()=0;virtual void v4()=0;virtual void v5()=0;virtual void v6()=0;virtual void v7()=0;virtual void v8()=0;};
u8 *base; s32 zero; s16 right; s16 bottom; u8 *self; u8 *initial; f32 scale; f32 one;
self=(u8 *)arg0;
zero=0;
right=(s16)x;bottom=(s16)y;
right+=0x1E0;bottom+=0x100;
initial=self;
base=initial;
*(void **)self=lbl_8028FDB0;
one=lbl_8036B618;scale=lbl_8036B61C;
*(s32 *)(initial+4)=zero;
*(void **)base=lbl_80292230;
*(s16 *)(base+8)=-1;
*(s16 *)(base+0xA)=x;*(s16 *)(base+0xC)=y;*(s16 *)(base+0xE)=right;*(s16 *)(base+0x10)=bottom;
*(s16 *)(base+0x12)=zero;*(s16 *)(base+0x14)=zero;*(s16 *)(base+0x16)=0x1E0;*(s16 *)(base+0x18)=0x100;
*(s16 *)(base+0x1A)=zero;*(s16 *)(base+0x1C)=zero;
base[0x1E]=255;base[0x1F]=255;base[0x20]=255;base[0x21]=255;
*(s16 *)(base+0x22)=id;*(s16 *)(base+0x24)=zero;
*(f32 *)(base+0x28)=one;*(f32 *)(base+0x2C)=one;*(f32 *)(base+0x30)=one;
*(s32 *)(base+0x34)=zero;*(s32 *)(base+0x38)=zero;
*(void **)self=gUiPanelDVtbl;
*(s16 *)(self+0x3C)=0x20;*(s16 *)(self+0x3E)=8;*(s16 *)(self+0x40)=0;*(f32 *)(self+0x44)=scale;
*(void **)(self+80)=gEmptyVtbl;
*(s32 *)(self+84)=0;
*(s32 *)(self+88)=2;
self[92]=1;self[93]=1;
*(s16 *)(self+100)=0;*(s16 *)(self+102)=0;
*(f32 *)(self+104)=one;*(f32 *)(self+108)=one;
self[112]=255;self[113]=255;self[114]=255;self[115]=255;
*(f32 *)(self+116)=scale;
((Obj *)(self+80))->v1();
one=lbl_8036B618;scale=lbl_8036B61C;
*(void **)(self+120)=gEmptyVtbl;
*(s32 *)(self+124)=0;
*(s32 *)(self+128)=3;
self[132]=1;self[133]=1;
*(s16 *)(self+140)=0;*(s16 *)(self+142)=0;
*(f32 *)(self+144)=one;*(f32 *)(self+148)=one;
self[152]=255;self[153]=255;self[154]=255;self[155]=255;
*(f32 *)(self+156)=scale;
((Obj *)(self+120))->v1();
((Obj *)self)->v8();return self;
}
#pragma global_optimizer reset
#pragma dont_inline reset
#pragma opt_common_subs reset
#pragma cplusplus reset
void fn_801D3A4C(u8 *arg0) {
    s16 height, width;
    s32 bottom, right;
    s16 *p = (s16 *)arg0;
    s16 v12, v16, v14, v18, t;

    height = p[0x10 / 2] - p[0xC / 2];
    width = p[0xE / 2] - p[0xA / 2];
    bottom = height - 8;
    right = width - 4;
    p[0x12 / 2] = 4;
    p[0x14 / 2] = 8;
    p[0x16 / 2] = right;
    p[0x18 / 2] = bottom;

    v12 = p[0x12 / 2];
    v16 = p[0x16 / 2];
    t = (s16)(v16 - v12);
    p[0x5E / 2] = t >> 1;
    p[0x60 / 2] = 0;
    p[0x62 / 2] = 0;

    v12 = p[0x12 / 2];
    v16 = p[0x16 / 2];
    v14 = p[0x14 / 2];
    t = (s16)(v16 - v12);
    v18 = p[0x18 / 2];
    t = t >> 1;
    p[0x86 / 2] = t;
    p[0x88 / 2] = v18 - v14;
    p[0x8A / 2] = 0;
}

void fn_801D3AE0(s32 arg0) {
    void *Process_CreateChild(void *, s32);
    extern u8 lbl_80299CC4[];
    void *temp_r3;
    temp_r3 = Process_CreateChild(lbl_80299CC4, arg0);
    *(u32 *)((u8 *)temp_r3 + 0x34) = 2;
}

void fn_801D3B14(void *arg0)
{
    extern s32 gUiInputFlags;
    extern u8 gSystemSave[];
    extern u8 lbl_80299CC4[];
    extern s32 lbl_803682E0;

    extern s32 fn_801E3620(void *);
    extern void *Process_CreateChild(void *, void *);

    u8 *entry;

    if (!(gUiInputFlags & 0x10)) {
        if ((u8)fn_801E3620(gSystemSave) == 0) {
            return;
        }
    }

    entry = (u8 *)Process_CreateChild(lbl_80299CC4, arg0);

    *(s32 *)(entry + 0x34) = 1;
    lbl_803682E0 = 0;
}

void fn_801D3B7C(s32 arg0) {
    void *Process_CreateChild(void *, s32);
    extern u8 lbl_80299CC4[];
    extern u8 gSystemSave[];
    extern s32 lbl_803682E0;
    u8 *p = gSystemSave;
    void *ret;

    *(s32 *)(p + 0) = -1;
    *(s32 *)(p + 4) = -1;
    p[0x44] = 1;
    ret = Process_CreateChild(lbl_80299CC4, arg0);
    *(s32 *)((u8 *)ret + 0x34) = 0;
    lbl_803682E0 = 0;
}

void fn_801D3BD0(void *arg0) {
    void Process_UnlinkByKey(void*);
    void Process_Unlink(void);
    void FileCache_ReleaseSlot(void*);
    void fn_800C4588(void*);
    void fn_801457B4(void);
    void fn_80161F7C(void);
    extern u8 lbl_80299C58[];
    extern u8 lbl_80299A78[];
    s32 i;
    void *obj;
    obj = *(void**)((u8*)arg0 + 0x30);
    Process_UnlinkByKey(lbl_80299C58);
    i = 0;
    do {
        if (*(u32*)(lbl_80299A78 + i * 0xc + 8) != 0) {
            FileCache_ReleaseSlot(lbl_80299A78 + i * 0xc + 8);
        }
        *(u32*)(lbl_80299A78 + i * 0xc + 8) = 0;
        i++;
    } while (i < 0x28);
    if (*(u8*)((u8*)obj + 0x5a) != 0) {
        fn_80161F7C();
    }
    if (*(void**)((u8*)obj + 0xc) != 0) {
        Process_Unlink();
    }
    if (*(u32*)((u8*)obj + 0x8) != 0) {
        FileCache_ReleaseSlot((u8*)obj + 0x8);
    }
    fn_800C4588(obj);
    *(u32*)((u8*)arg0 + 0x30) = 0;
    fn_801457B4();
}

#pragma opt_common_subs off
void fn_801D3C88(void *arg0) {
    void *fn_800C4638(s32, void *, s32);
    void fn_8006EEFC(void *, void *);
    void fn_80162054(void);
    void fn_80145828(void);
    s32 Process_AttachFunc(void *, void *);
    void fn_8008A290(s32, s32);
    extern u8 gUiSeCues[];
    extern s32 lbl_803682E4;
    extern void fn_801D8E80(void);
    void *obj;

    obj = fn_800C4638(0x544, gUiSeCues + 0x27b, 0);
    *(void **)((u8 *)arg0 + 0x30) = obj;
    *(s32 *)((u8 *)obj + 0xC) = 0;
    *(s32 *)((u8 *)obj + 8) = 0;
    *(u8 *)((u8 *)obj + 0x5A) = 0;
    *(u8 *)((u8 *)obj + 0x10) = *(s32 *)((u8 *)arg0 + 0x34);
    fn_8006EEFC((u8 *)obj + 8, gUiSeCues + 0x27c);
    lbl_803682E4 = *(s32 *)((u8 *)obj + 8);
    fn_80162054();
    *(u8 *)((u8 *)obj + 0x5A) = 1;
    fn_80145828();
    *(s32 *)((u8 *)obj + 0xC) = Process_AttachFunc(fn_801D8E80, arg0);
    fn_8008A290(2, 0xfa);
}
#pragma opt_common_subs reset
void fn_801D3D3C(void *arg0) {
 void *fn_800D3590(void *);
 void *fn_801DE370(void *);
 void fn_801DBD84(void *);
 void SaveData_Release(void *);
 void fn_801E3118(void *, void *, u8);
 s32 Card_GetResult(void);
 void *fn_801DC10C(s32);
 u8 fn_801DE368(void *);
 void fn_801DE0EC(s32 *, void *);
 u8 fn_801DE3D0(void *);
 u8 SystemSave_TestFlag0(void *);
 void Ui_PlaySeCue(void *, s32);
 void MsgBox_Init(void *, void *, u8, u8, s16);
 void *Msg_Expand(void *);
 void sprintf(void *, void *, void *, void *);
 void fn_801DE3C4(void *);
 void fn_8008A290(s32, s32);
 void Game_SetState(s32);
 void Process_ClearFunc(void *);
 void Ui_OpenConfirmDialog(void *, s8, s8, s32, void *, s8, void *);
 void fn_801DE3BC(void *, s8);
 void fn_801D8E18(void *, s16, s16, u8, u8);
 void fn_801D8D78(void *, s16, s16, u8, u8);
 void fn_801D8E08(void *);
 void fn_801DDDE8(s32, void *);
 u8 fn_801DE360(void *);
 void fn_801E1440(void *, s32, s32);
 void fn_800E99E4(void *);
 void fn_801E323C(void *, void *);
 void fn_801DF5D8(void *, void *);
 void fn_801DE378(void *);
 void fn_801D8D68(void *);
 void fn_801D8D58(void *);
 void FileMenu_InitEntry(void *, s16, s16);
 s32 fn_801DBFF8(void);
 void *fn_801DC0CC(void);
 void fn_801D8894(void *);
 void fn_801D88B0(void *, s8);
 void fn_801D888C(void *, s16);
 void fn_801E00EC(void *, void *);
 void fn_801E1498(void *, s32, s32, s32, void *);
 void fn_801E21EC(void *, s32);
 void fn_80006160(s32);
 void fn_801D8854(void *, u32);
 void fn_801DBEA8(void *, s32);
 void fn_801D8C0C(void *, s16);
 void fn_801D88B8(void *, void *, u8);
 u8 fn_801DE358(void *);
 void fn_801E080C(void *);
 void fn_801E0B48(void *, s32, s32, void *);
 extern void *gPadInput;
 extern s8 lbl_803682EC;
 extern s32 lbl_803682E8;
 extern u8 gSaveDataBase;
 extern u8 gBattleState[];
 extern u8 gSystemSave[];
 extern u8 gUiSeCues[];
 s32 arr_lo[10];
 s32 arr_hi[10];
 s32 i, j, k, m, n, count;
 s32 *p;
 s32 *p24;
 s32 i25;
 s8 saved_byte;
 s32 result;
 u8 tmp_u8;
 s16 x, y;
 s32 v, changed, sel, flags_a, flags_b;
 void *state, *tmp_ptr, *tmp_ptr2;
 u8 *slot;
 state = *(void **)((u8 *)arg0 + 0x30);
 flags_a = (s32)fn_800D3590(gPadInput);
 flags_b = (s32)fn_801DE370(gPadInput);
 if ((s8)lbl_803682EC == 0) { lbl_803682E8 = 1; lbl_803682EC = 1; }
 switch (*(s32 *)state) {
 case 0:
  saved_byte = *(s8 *)((u8 *)state + 0x11);
  fn_801DBD84(arg0);
  *(s8 *)((u8 *)state + 0x11) = saved_byte;
  SaveData_Release(&gSaveDataBase);
  fn_801E3118(&gSaveDataBase, arg0, *(u8 *)((u8 *)state + 0x10) == 1);
  *(s32 *)state = 3; break;
 case 3:
  result = Card_GetResult();
  if (result == -0x80) { *(s32 *)state = 0x28; break; }
  if (result == -0x42) { *(s32 *)state = 0x1e; break; }
  if (result == -0x41) { *(s32 *)state = 0xd; break; }
  if (result == -0x40) { *(s32 *)state = 0x23; break; }
  if (result == -0xd || result == -6) { *(s32 *)state = 0xf; break; }
  if (result == -5) { *(s32 *)state = 0x18; break; }
  if (result == -4) { *(s32 *)state = 0x19; break; }
  if (result == -3) { *(s32 *)state = 5; break; }
  if (result == -2) { *(s32 *)state = 0xe; break; }
  if (result == -1) { *(s32 *)state = 0; break; }
  if (result != 0) { *(s32 *)state = 5; break; }
  if (*(u8 *)((u8 *)state + 0x10) != 1) {
   p24 = arr_hi; count = 0; i25 = 0;
   while (i25 < 5) {
    if (fn_801DC10C(i25) != 0) { tmp_u8 = fn_801DE368(fn_801DC10C(i25)); count++; *p24 = tmp_u8; p24++; }
    i25++;
   }
   arr_hi[count] = 1; arr_hi[count+1] = 0x20; arr_hi[count+2] = 0x63; arr_hi[count+3] = -1;
   fn_801DE0EC(arr_hi, arg0);
  } else {
   count = 0; p24 = arr_lo; i25 = 0;
   while (i25 < 5) {
    if (fn_801DC10C(i25) != 0) { tmp_u8 = fn_801DE368(fn_801DC10C(i25)); count++; *p24 = tmp_u8; p24++; }
    i25++;
   }
   tmp_u8 = fn_801DE3D0(gBattleState);
   if ((s32)tmp_u8 - 2 >= 1) { tmp_u8 = fn_801DE3D0(gBattleState); arr_lo[count] = (s32)tmp_u8 - 2; count++; }
   tmp_u8 = fn_801DE3D0(gBattleState);
   if ((s32)tmp_u8 - 1 >= 1) { tmp_u8 = fn_801DE3D0(gBattleState); arr_lo[count] = (s32)tmp_u8 - 1; count++; }
   tmp_u8 = fn_801DE3D0(gBattleState);
   arr_lo[count] = tmp_u8; arr_lo[count+1] = 0x20; arr_lo[count+2] = 0x63; arr_lo[count+3] = -1;
   fn_801DE0EC(arr_lo, arg0);
  }
  tmp_u8 = *(u8 *)((u8 *)state + 0x10);
  if (tmp_u8 == 0) *(s32 *)state = 0x32;
  else if (tmp_u8 == 1) *(s32 *)state = 0x258;
  else if (tmp_u8 == 2) {
   *(u8 *)((u8 *)state + 0x10) = 0;
   if (SystemSave_TestFlag0(gSystemSave)) *(s32 *)state = 0x2bc; else *(s32 *)state = 0x32;
  }
  break;
 case 5:
  Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
  MsgBox_Init((u8 *)state + 0x330, gUiSeCues + 0x2a4, 0, 1, 0);
  *(s32 *)state = 6; break;
 case 6:
  if (*(u8 *)((u8 *)state + 0x10) == 1) { *(s32 *)state = 0x2d; break; }
  tmp_ptr = Msg_Expand(gUiSeCues + 0x2cd);
  tmp_ptr2 = Msg_Expand(gUiSeCues + 0x2c3);
  sprintf((u8 *)state + 0x1a, gUiSeCues + 0x2b2, tmp_ptr2, tmp_ptr);
  *(s32 *)state = 7;
 case 7:
  if (flags_a & 0x100) {
   fn_801DE3C4((u8 *)state + 0x330); *(s32 *)state = 8;
   Ui_PlaySeCue(gUiSeCues + 0x2d4, 0x64); *(u8 *)((u8 *)state + 0x1a) = 0;
  } else if (flags_a & 0x200) {
   fn_8008A290(3, 0xfa);
   if (*(u8 *)((u8 *)state + 0x10) != 1) Game_SetState(0x1b);
   Process_ClearFunc(arg0); SaveData_Release(&gSaveDataBase); Ui_PlaySeCue(gUiSeCues + 0x2e4, 0x64);
  }
  break;
 case 8:
  Ui_OpenConfirmDialog(gUiSeCues + 0x2f4, 1, 1, 0, gUiSeCues + 0x2d4, 0, arg0);
  *(s32 *)state = 9; break;
 case 9:
  if (*(s8 *)((u8 *)state + 0x14) == 0) {
   *(s32 *)state = 0xa;
   MsgBox_Init((u8 *)state + 0x330, Msg_Expand(gUiSeCues + 0x307), 1, 0, 1);
   *(u8 *)((u8 *)state + 0x14) = 0;
   fn_801DE3BC((u8 *)state + 0x330, *(s8 *)((u8 *)state + 0x14));
   fn_801D8E18((u8 *)state + 0x52e, *(s16 *)((u8 *)state + 0x33e), *(s16 *)((u8 *)state + 0x340), 0, 1);
  } else {
   fn_8008A290(3, 0xfa);
   if (*(u8 *)((u8 *)state + 0x10) != 1) Game_SetState(0x1b);
   Process_ClearFunc(arg0); SaveData_Release(&gSaveDataBase);
  }
  break;
 case 0xa:
  sel = *(s8 *)((u8 *)state + 0x14); changed = 0;
  if (flags_a & 0x100) {
   Ui_PlaySeCue(gUiSeCues + 0x318, 0x64);
   *(u8 *)((u8 *)state + 0x18) = *(u8 *)((u8 *)state + 0x14);
   *(s32 *)state = 0xb; *(u8 *)((u8 *)state + 0x19) = 0;
   fn_801DE3C4((u8 *)state + 0x330); fn_801D8E08((u8 *)state + 0x52e); fn_801DDDE8(5, arg0); break;
  }
  if (flags_a & 0x200) {
   Ui_PlaySeCue(gUiSeCues + 0x2e4, 0x64); fn_8008A290(3, 0xfa);
   if (*(u8 *)((u8 *)state + 0x10) != 1) Game_SetState(0x1b);
   Process_ClearFunc(arg0); SaveData_Release(&gSaveDataBase);
  }
  if (flags_b & 0x1000001) {
   *(u8 *)((u8 *)state + 0x14) = *(u8 *)((u8 *)state + 0x14) - 1;
   if (*(s8 *)((u8 *)state + 0x14) < 0) *(u8 *)((u8 *)state + 0x14) = 0;
   if (sel != *(s8 *)((u8 *)state + 0x14)) changed = 1;
  }
  if (flags_b & 0x2000002) {
   *(u8 *)((u8 *)state + 0x14) = *(u8 *)((u8 *)state + 0x14) + 1;
   if (*(s8 *)((u8 *)state + 0x14) > 2) *(u8 *)((u8 *)state + 0x14) = 2;
   if (sel != *(s8 *)((u8 *)state + 0x14)) changed = 1;
  }
  if ((u8)changed == 1) {
   Ui_PlaySeCue(gUiSeCues + 0x328, 0x64);
   sel = *(s8 *)((u8 *)state + 0x14);
   if (sel == 0) { x = *(s16 *)((u8 *)state + 0x340); y = *(s16 *)((u8 *)state + 0x33e); }
   else if (sel == 1) { x = *(s16 *)((u8 *)state + 0x344); y = *(s16 *)((u8 *)state + 0x342); }
   else if (sel == 2) { x = *(s16 *)((u8 *)state + 0x348); y = *(s16 *)((u8 *)state + 0x346); }
   else { x = 0; y = 0; }
   fn_801D8D78((u8 *)state + 0x52e, y, x, 0, 1);
   fn_801DE3BC((u8 *)state + 0x330, *(s8 *)((u8 *)state + 0x14));
  }
  break;
 case 0xb:
  v = fn_801DE360(gSystemSave); v = ((u8)v == 0); sel = *(s8 *)((u8 *)state + 0x18);
  if (sel == 0) changed = v ? 0 : 3; else if (sel == 1) changed = v != 0; else if (sel == 2) changed = v ? 2 : 1; else changed = 0;
  fn_801E1440(&gSaveDataBase, changed, *(s8 *)((u8 *)state + 0x19) != 0);
  fn_8008A290(3, 0xfa);
  if (*(u8 *)((u8 *)state + 0x10) != 1) Game_SetState(0x1a);
  Process_ClearFunc(arg0); SaveData_Release(&gSaveDataBase); break;
 case 0xd:
  Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
  MsgBox_Init((u8 *)state + 0x330, gUiSeCues + 0x344, 0, 1, 0); *(s32 *)state = 6; break;
 case 0xe:
  Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
  MsgBox_Init((u8 *)state + 0x330, gUiSeCues + 0x351, 0, 1, 0); *(s32 *)state = 6; break;
 case 0xf:
  if (*(u8 *)((u8 *)state + 0x10) == 1) {
   Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
   MsgBox_Init((u8 *)state + 0x330, gUiSeCues + 0x35e, 0, 1, 0); *(s32 *)state = 0x2d;
  } else {
   Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
   Ui_OpenConfirmDialog(gUiSeCues + 0x36d, 1, 1, 0, gUiSeCues + 0x2d4, 1, arg0); *(s32 *)state = 0x10;
  }
  break;
 case 0x10:
  if (*(s8 *)((u8 *)state + 0x14) == 0) {
   Ui_OpenConfirmDialog(gUiSeCues + 0x37b, 1, 1, 0, gUiSeCues + 0x2d4, 0, arg0); *(s32 *)state = 0x11;
  } else { *(s32 *)state = 0x14; }
  break;
 case 0x11:
  if (*(s8 *)((u8 *)state + 0x14) == 0) {
   fn_800E99E4(arg0);
   MsgBox_Init((u8 *)state + 0x330, gUiSeCues + 0x38a, 0, 0, 0); *(s32 *)state = 0x12;
  } else { *(s32 *)state = 0x14; }
  break;
 case 0x12:
  fn_801DE3C4((u8 *)state + 0x330); *(s32 *)state = 0x13; fn_801DDDE8(5, arg0); break;
 case 0x13:
  if (Card_GetResult() == 0) {
   Ui_OpenConfirmDialog(gUiSeCues + 0x39a, 0, 0, 0, NULL, 0, arg0); *(s32 *)state = 0;
  } else {
   Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
   MsgBox_Init((u8 *)state + 0x330, gUiSeCues + 0x3ab, 0, 1, 0); *(s32 *)state = 6;
  }
  break;
 case 0x14:
  Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
  MsgBox_Init((u8 *)state + 0x330, gUiSeCues + 0x3bc, 0, 1, 0); *(s32 *)state = 6; break;
 case 0x18:
  Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
  MsgBox_Init((u8 *)state + 0x330, gUiSeCues + 0x3cb, 0, 1, 0); *(s32 *)state = 6; break;
 case 0x19:
  if (*(u8 *)((u8 *)state + 0x10) == 1) *(s32 *)state = 0x23;
  else { Ui_OpenConfirmDialog(gUiSeCues + 0x3d5, 1, 0, 0, gUiSeCues + 0x2d4, 0, arg0); *(s32 *)state = 0x1a; }
  break;
 case 0x1a:
  if (*(s8 *)((u8 *)state + 0x14) == 0) {
   fn_801E323C(&gSaveDataBase, arg0);
   MsgBox_Init((u8 *)state + 0x330, gUiSeCues + 0x3e3, 0, 0, 0); *(s32 *)state = 0x1b;
  } else { *(s32 *)state = 8; }
  break;
 case 0x1b:
  fn_801DE3C4((u8 *)state + 0x330); *(s32 *)state = 0x1c; fn_801DDDE8(5, arg0); break;
 case 0x1c:
  if (Card_GetResult() == 0) {
   Ui_OpenConfirmDialog(gUiSeCues + 0x3ef, 0, 0, 0, NULL, 0, arg0); *(s32 *)state = 0;
  } else {
   Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
   if (Card_GetResult() == -5) MsgBox_Init((u8 *)state + 0x330, gUiSeCues + 0x3cb, 0, 1, 0);
   else MsgBox_Init((u8 *)state + 0x330, gUiSeCues + 0x3fd, 0, 1, 0);
   *(s32 *)state = 6;
  }
  break;
 case 0x1e:
  Ui_PlaySeCue(gUiSeCues + 0x290, 0x64); fn_801DF5D8(&gSaveDataBase, arg0);
  MsgBox_Init((u8 *)state + 0x330, gUiSeCues + 0x40b, 0, 1, 0); *(s32 *)state = 0x20; break;
 case 0x1f: break;
 case 0x20:
  if (flags_a & 0x100) {
   fn_801DE3C4((u8 *)state + 0x330); *(s32 *)state = 0;
   Ui_PlaySeCue(gUiSeCues + 0x2d4, 0x64); *(u8 *)((u8 *)state + 0x1a) = 0;
  }
  break;
 case 0x23:
  Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
  MsgBox_Init((u8 *)state + 0x330, gUiSeCues + 0x417, 0, 1, 0); *(s32 *)state = 0x2d; break;
 case 0x28:
  Ui_PlaySeCue(gUiSeCues + 0x290, 0x64); fn_801DE378((u8 *)state + 0x330);
  MsgBox_Init((u8 *)state + 0x330, gUiSeCues + 0x428, 1, 1, 0); *(s32 *)state = 6; break;
 case 0x2d:
  if (*(u8 *)((u8 *)state + 0x10) == 1) {
   tmp_ptr = Msg_Expand(gUiSeCues + 0x43e); tmp_ptr2 = Msg_Expand(gUiSeCues + 0x435);
   sprintf((u8 *)state + 0x1a, gUiSeCues + 0x2b2, tmp_ptr2, tmp_ptr);
  } else {
   tmp_ptr = Msg_Expand(gUiSeCues + 0x2cd); tmp_ptr2 = Msg_Expand(gUiSeCues + 0x435);
   sprintf((u8 *)state + 0x1a, gUiSeCues + 0x2b2, tmp_ptr2, tmp_ptr);
  }
  *(s32 *)state = 0x2e;
 case 0x2e:
  if (flags_a & 0x100) {
   fn_801DE3C4((u8 *)state + 0x330); *(s32 *)state = 0;
   Ui_PlaySeCue(gUiSeCues + 0x2d4, 0x64); *(u8 *)((u8 *)state + 0x1a) = 0;
  } else if (flags_a & 0x200) {
   fn_8008A290(3, 0xfa);
   if (*(u8 *)((u8 *)state + 0x10) != 1) Game_SetState(0x1b);
   Process_ClearFunc(arg0); SaveData_Release(&gSaveDataBase); Ui_PlaySeCue(gUiSeCues + 0x2e4, 0x64);
  }
  break;
 case 0x32:
  p24 = (s32 *)state; i25 = 0;
  while (i25 < 6) { fn_801D8D68((u8 *)p24 + 0x7c); i25++; p24 = (s32 *)((u8 *)p24 + 0x34); }
  p24 = (s32 *)state; i25 = 0;
  while (i25 < 5) { fn_801D8D58((u8 *)p24 + 0x1b4); i25++; p24 = (s32 *)((u8 *)p24 + 0x4c); }
  *(u8 *)((u8 *)state + 0x15) = 0;
  result = fn_801DBFF8();
  if (fn_801DC0CC() != 0) {
   FileMenu_InitEntry((u8 *)state + *(s8 *)((u8 *)state + 0x15) * 0x34 + 0x7c, *(s8 *)((u8 *)state + 0x15), 2);
   *(u8 *)((u8 *)state + 0x15) = *(u8 *)((u8 *)state + 0x15) + 1;
  }
  if (result >= 1) {
   FileMenu_InitEntry((u8 *)state + *(s8 *)((u8 *)state + 0x15) * 0x34 + 0x7c, *(s8 *)((u8 *)state + 0x15), 1);
   *(u8 *)((u8 *)state + 0x15) = *(u8 *)((u8 *)state + 0x15) + 1;
  }
  if (result >= 1 && result < 5) {
   FileMenu_InitEntry((u8 *)state + *(s8 *)((u8 *)state + 0x15) * 0x34 + 0x7c, *(s8 *)((u8 *)state + 0x15), 3);
   *(u8 *)((u8 *)state + 0x15) = *(u8 *)((u8 *)state + 0x15) + 1;
  }
  if (result >= 1) {
   FileMenu_InitEntry((u8 *)state + *(s8 *)((u8 *)state + 0x15) * 0x34 + 0x7c, *(s8 *)((u8 *)state + 0x15), 4);
   *(u8 *)((u8 *)state + 0x15) = *(u8 *)((u8 *)state + 0x15) + 1;
  }
  if (result != 5) {
   FileMenu_InitEntry((u8 *)state + *(s8 *)((u8 *)state + 0x15) * 0x34 + 0x7c, *(s8 *)((u8 *)state + 0x15), 0);
   *(u8 *)((u8 *)state + 0x15) = *(u8 *)((u8 *)state + 0x15) + 1;
  }
  if (SystemSave_TestFlag0(gSystemSave)) {
   FileMenu_InitEntry((u8 *)state + *(s8 *)((u8 *)state + 0x15) * 0x34 + 0x7c, *(s8 *)((u8 *)state + 0x15), 6);
   *(u8 *)((u8 *)state + 0x15) = *(u8 *)((u8 *)state + 0x15) + 1;
  }
  { s8 idx11 = *(s8 *)((u8 *)state + 0x11);
    if (idx11 < 0 || idx11 >= *(s8 *)((u8 *)state + 0x15)) *(u8 *)((u8 *)state + 0x11) = 0; }
  { s8 idx11 = *(s8 *)((u8 *)state + 0x11);
    s16 *fl = (s16 *)((u8 *)state + idx11 * 0x34 + 0x7c); *fl = (s16)(*fl | 2); }
  *(s32 *)state = 0x37; *(s32 *)((u8 *)state + 4) = 0; fn_801DDDE8(0xf, arg0); break;
 case 0x37: {
  s8 idx = *(s8 *)((u8 *)state + 0x11); u8 *base = (u8 *)state + idx * 0x34;
  fn_801D8E18((u8 *)state + 0x51a, *(s16 *)(base + 0x88), *(s16 *)(base + 0x8a), 1, 0);
  *(s32 *)state = 0x3c;
 }
 case 0x3c:
  if (flags_a & 0x100) { *(s32 *)state = 0x3de; Ui_PlaySeCue(gUiSeCues + 0x2d4, 0x64); }
  else if (flags_a & 0x200) { *(s32 *)state = 0x384; Ui_PlaySeCue(gUiSeCues + 0x2e4, 0x64); }
  else if (flags_b & 0x8000008) {
   sel = *(s8 *)((u8 *)state + 0x11);
   { s16 *fl = (s16 *)((u8 *)state + sel * 0x34 + 0x7c); *fl = (s16)(*fl & ~2); }
   *(u8 *)((u8 *)state + 0x11) = *(u8 *)((u8 *)state + 0x11) - 1;
   if (*(s8 *)((u8 *)state + 0x11) < 0) *(u8 *)((u8 *)state + 0x11) = *(u8 *)((u8 *)state + 0x15) - 1;
   { s8 idx = *(s8 *)((u8 *)state + 0x11); s16 *fl = (s16 *)((u8 *)state + idx * 0x34 + 0x7c); *fl = (s16)(*fl | 2);
     fn_801D8D78((u8 *)state + 0x51a, *(s16 *)((u8 *)state + idx * 0x34 + 0x88), *(s16 *)((u8 *)state + idx * 0x34 + 0x8a), 1, 0); }
   if (sel != *(s8 *)((u8 *)state + 0x11)) Ui_PlaySeCue(gUiSeCues + 0x446, 0x64);
  } else if (flags_b & 0x4000004) {
   sel = *(s8 *)((u8 *)state + 0x11);
   { s16 *fl = (s16 *)((u8 *)state + sel * 0x34 + 0x7c); *fl = (s16)(*fl & ~2); }
   *(u8 *)((u8 *)state + 0x11) = *(u8 *)((u8 *)state + 0x11) + 1;
   if (*(s8 *)((u8 *)state + 0x11) > *(s8 *)((u8 *)state + 0x15) - 1) *(u8 *)((u8 *)state + 0x11) = 0;
   { s8 idx = *(s8 *)((u8 *)state + 0x11); s16 *fl = (s16 *)((u8 *)state + idx * 0x34 + 0x7c); *fl = (s16)(*fl | 2);
     fn_801D8D78((u8 *)state + 0x51a, *(s16 *)((u8 *)state + idx * 0x34 + 0x88), *(s16 *)((u8 *)state + idx * 0x34 + 0x8a), 1, 0); }
   if (sel != *(s8 *)((u8 *)state + 0x11)) Ui_PlaySeCue(gUiSeCues + 0x446, 0x64);
  }
  break;
 case 0x64:
  fn_801DBEA8(state, 0); *(s8 *)((u8 *)state + 0x12) = -1;
  p24 = (s32 *)state; i25 = 0;
  while (i25 < 5) {
   fn_801D8D58((u8 *)p24 + 0x1b4); fn_801D8C0C((u8 *)p24 + 0x1b4, (s16)i25);
   i25++; p24 = (s32 *)((u8 *)p24 + 0x4c);
  }
  p24 = (s32 *)state; i25 = 0;
  while (i25 < 5) {
   fn_801D88B8((u8 *)p24 + 0x1b4, state, 0);
   if (!(*(s16 *)((u8 *)p24 + 0x1b4) & 4) && *(s8 *)((u8 *)state + 0x12) == -1) *(u8 *)((u8 *)state + 0x12) = (u8)i25;
   i25++; p24 = (s32 *)((u8 *)p24 + 0x4c);
  }
  { s8 idx = *(s8 *)((u8 *)state + 0x12); s16 *fl = (s16 *)((u8 *)state + idx * 0x4c + 0x1b4); *fl = (s16)(*fl | 2); }
  *(s32 *)state = 0x69; fn_801DDDE8(0x14, arg0); break;
 case 0x69: {
  s8 idx = *(s8 *)((u8 *)state + 0x12); u8 *base = (u8 *)state + idx * 0x4c;
  fn_801D8E18((u8 *)state + 0x51a, *(s16 *)(base + 0x1be), *(s16 *)(base + 0x1c0), 1, 0);
  fn_801D88B0((u8 *)state + 0x5c, 0); *(s32 *)state = 0x6a;
 }
 case 0x6a:
  if (flags_a & 0x100) {
   if (fn_801DC0CC() != 0) {
    Ui_OpenConfirmDialog(gUiSeCues + 0x462, 1, 1, 1, gUiSeCues + 0x2d4, 0, arg0);
    *(s32 *)state = 0x6e; Ui_PlaySeCue(gUiSeCues + 0x2d4, 0x64);
   } else { *(s32 *)state = 0x73; Ui_PlaySeCue(gUiSeCues + 0x2d4, 0x64); }
  } else if (flags_a & 0x200) {
   *(s32 *)state = 0x3b6; Ui_PlaySeCue(gUiSeCues + 0x2e4, 0x64);
  } else if (flags_b & 0x8000008) {
   sel = *(s8 *)((u8 *)state + 0x12);
   { s16 *fl = (s16 *)((u8 *)state + sel * 0x4c + 0x1b4); *fl = (s16)(*fl & ~2); }
   do { *(u8 *)((u8 *)state + 0x12) = *(u8 *)((u8 *)state + 0x12) - 1;
        if (*(s8 *)((u8 *)state + 0x12) < 0) *(u8 *)((u8 *)state + 0x12) = 4;
   } while (*(s16 *)((u8 *)state + *(s8 *)((u8 *)state + 0x12) * 0x4c + 0x1b4) & 4);
   { s8 idx = *(s8 *)((u8 *)state + 0x12); s16 *fl = (s16 *)((u8 *)state + idx * 0x4c + 0x1b4); *fl = (s16)(*fl | 2);
     fn_801D8D78((u8 *)state + 0x51a, *(s16 *)((u8 *)state + idx * 0x4c + 0x1be), *(s16 *)((u8 *)state + idx * 0x4c + 0x1c0), 1, 0); }
   if (sel != *(s8 *)((u8 *)state + 0x12)) Ui_PlaySeCue(gUiSeCues + 0x473, 0x64);
  } else if (flags_b & 0x4000004) {
   sel = *(s8 *)((u8 *)state + 0x12);
   { s16 *fl = (s16 *)((u8 *)state + sel * 0x4c + 0x1b4); *fl = (s16)(*fl & ~2); }
   do { *(u8 *)((u8 *)state + 0x12) = *(u8 *)((u8 *)state + 0x12) + 1;
        if (*(s8 *)((u8 *)state + 0x12) > 4) *(u8 *)((u8 *)state + 0x12) = 0;
   } while (*(s16 *)((u8 *)state + *(s8 *)((u8 *)state + 0x12) * 0x4c + 0x1b4) & 4);
   { s8 idx = *(s8 *)((u8 *)state + 0x12); s16 *fl = (s16 *)((u8 *)state + idx * 0x4c + 0x1b4); *fl = (s16)(*fl | 2);
     fn_801D8D78((u8 *)state + 0x51a, *(s16 *)((u8 *)state + idx * 0x4c + 0x1be), *(s16 *)((u8 *)state + idx * 0x4c + 0x1c0), 1, 0); }
   if (sel != *(s8 *)((u8 *)state + 0x12)) Ui_PlaySeCue(gUiSeCues + 0x473, 0x64);
  }
  break;
 case 0x6e:
  if (*(s8 *)((u8 *)state + 0x14) == 0) { fn_801E00EC(&gSaveDataBase, arg0); *(s32 *)state = 0x71; }
  else *(s32 *)state = 0x69;
  break;
 case 0x71:
  if (Card_GetResult() == 0) { *(s32 *)state = 0x73; fn_801D8894((u8 *)state + 0x60); }
  else {
   Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
   Ui_OpenConfirmDialog(gUiSeCues + 0x488, 0, 0, 0, NULL, 1, arg0); *(s32 *)state = 0x69;
  }
  break;
 case 0x73:
  MsgBox_Init((u8 *)state + 0x330, Msg_Expand(gUiSeCues + 0x307), 1, 0, 1);
  *(u8 *)((u8 *)state + 0x14) = 0;
  fn_801DE3BC((u8 *)state + 0x330, *(s8 *)((u8 *)state + 0x14));
  fn_801D8E18((u8 *)state + 0x52e, *(s16 *)((u8 *)state + 0x33e), *(s16 *)((u8 *)state + 0x340), 0, 1);
  fn_801D88B0((u8 *)state + 0x5c, 0x66); fn_801D888C((u8 *)state + 0x5c, -9);
  *(s32 *)state = 0x74;
 case 0x74:
  sel = *(s8 *)((u8 *)state + 0x14); changed = 0;
  if (flags_a & 0x100) {
   *(u8 *)((u8 *)state + 0x18) = *(u8 *)((u8 *)state + 0x14);
   if (SystemSave_TestFlag0(gSystemSave)) { Ui_PlaySeCue(gUiSeCues + 0x2d4, 0x64); *(s32 *)state = 0x75; }
   else { Ui_PlaySeCue(gUiSeCues + 0x318, 0x64); *(s32 *)state = 0x77; *(u8 *)((u8 *)state + 0x19) = 0; }
   fn_801DE3C4((u8 *)state + 0x330); fn_801D8E08((u8 *)state + 0x52e); fn_801DDDE8(5, arg0); break;
  }
  if (flags_a & 0x200) {
   Ui_PlaySeCue(gUiSeCues + 0x2e4, 0x64); *(s32 *)state = 0x69;
   fn_801DE3C4((u8 *)state + 0x330); fn_801D8E08((u8 *)state + 0x52e); fn_801DDDE8(5, arg0);
  }
  if (flags_b & 0x1000001) {
   *(u8 *)((u8 *)state + 0x14) = *(u8 *)((u8 *)state + 0x14) - 1;
   if (*(s8 *)((u8 *)state + 0x14) < 0) *(u8 *)((u8 *)state + 0x14) = 0;
   if (sel != *(s8 *)((u8 *)state + 0x14)) changed = 1;
  }
  if (flags_b & 0x2000002) {
   *(u8 *)((u8 *)state + 0x14) = *(u8 *)((u8 *)state + 0x14) + 1;
   if (*(s8 *)((u8 *)state + 0x14) > 2) *(u8 *)((u8 *)state + 0x14) = 2;
   if (sel != *(s8 *)((u8 *)state + 0x14)) changed = 1;
  }
  if ((u8)changed == 1) {
   Ui_PlaySeCue(gUiSeCues + 0x328, 0x64); sel = *(s8 *)((u8 *)state + 0x14);
   if (sel == 0) { y = *(s16 *)((u8 *)state + 0x33e); x = *(s16 *)((u8 *)state + 0x340); }
   else if (sel == 1) { y = *(s16 *)((u8 *)state + 0x342); x = *(s16 *)((u8 *)state + 0x344); }
   else if (sel == 2) { y = *(s16 *)((u8 *)state + 0x346); x = *(s16 *)((u8 *)state + 0x348); }
   else { x = 0; y = 0; }
   fn_801D8D78((u8 *)state + 0x52e, y, x, 0, 1);
   fn_801DE3BC((u8 *)state + 0x330, *(s8 *)((u8 *)state + 0x14));
  }
  break;
 case 0x75:
  MsgBox_Init((u8 *)state + 0x330, Msg_Expand(gUiSeCues + 0x49b), 1, 0, 2);
  *(u8 *)((u8 *)state + 0x14) = 0;
  fn_801DE3BC((u8 *)state + 0x330, *(s8 *)((u8 *)state + 0x14));
  fn_801D8E18((u8 *)state + 0x52e, *(s16 *)((u8 *)state + 0x33e), *(s16 *)((u8 *)state + 0x340), 0, 1);
  *(s32 *)state = 0x76;
 case 0x76:
  sel = *(s8 *)((u8 *)state + 0x14); changed = 0;
  if (flags_a & 0x100) {
   Ui_PlaySeCue(gUiSeCues + 0x318, 0x64); *(s32 *)state = 0x77;
   *(u8 *)((u8 *)state + 0x19) = *(u8 *)((u8 *)state + 0x14);
   fn_801DE3C4((u8 *)state + 0x330); fn_801D8E08((u8 *)state + 0x52e); fn_801DDDE8(5, arg0); break;
  }
  if (flags_a & 0x200) {
   if (SystemSave_TestFlag0(gSystemSave)) *(s32 *)state = 0x73; else *(s32 *)state = 0x69;
   Ui_PlaySeCue(gUiSeCues + 0x2e4, 0x64);
   fn_801DE3C4((u8 *)state + 0x330); fn_801D8E08((u8 *)state + 0x52e); fn_801DDDE8(5, arg0);
  }
  if (flags_b & 0x1000001) {
   *(u8 *)((u8 *)state + 0x14) = *(u8 *)((u8 *)state + 0x14) - 1;
   if (*(s8 *)((u8 *)state + 0x14) < 0) *(u8 *)((u8 *)state + 0x14) = 0;
   if (sel != *(s8 *)((u8 *)state + 0x14)) changed = 1;
  }
  if (flags_b & 0x2000002) {
   *(u8 *)((u8 *)state + 0x14) = *(u8 *)((u8 *)state + 0x14) + 1;
   if (*(s8 *)((u8 *)state + 0x14) > 1) *(u8 *)((u8 *)state + 0x14) = 1;
   if (sel != *(s8 *)((u8 *)state + 0x14)) changed = 1;
  }
  if ((u8)changed == 1) {
   Ui_PlaySeCue(gUiSeCues + 0x328, 0x64); sel = *(s8 *)((u8 *)state + 0x14);
   if (sel == 0) { y = *(s16 *)((u8 *)state + 0x33e); x = *(s16 *)((u8 *)state + 0x340); }
   else if (sel == 1) { y = *(s16 *)((u8 *)state + 0x342); x = *(s16 *)((u8 *)state + 0x344); }
   else if (sel == 2) { y = *(s16 *)((u8 *)state + 0x346); x = *(s16 *)((u8 *)state + 0x348); }
   else { x = 0; y = 0; }
   fn_801D8D78((u8 *)state + 0x52e, y, x, 0, 1);
   fn_801DE3BC((u8 *)state + 0x330, *(s8 *)((u8 *)state + 0x14));
  }
  break;
 case 0x77:
  fn_801D88B0((u8 *)state + 0x5c, 0);
  v = fn_801DE360(gSystemSave); v = ((u8)v == 0);
  sel = *(s8 *)((u8 *)state + 0x18);
  if (sel == 0) changed = v ? 0 : 3; else if (sel == 1) changed = v != 0; else if (sel == 2) changed = v ? 2 : 1; else changed = 0;
  fn_801E1498(&gSaveDataBase, *(s8 *)((u8 *)state + 0x12), changed, *(s8 *)((u8 *)state + 0x19) != 0, arg0);
  MsgBox_Init((u8 *)state + 0x330, gUiSeCues + 0x4ab, 0, 0, 0);
  *(s32 *)state = 0x78; break;
 case 0x78:
  fn_801DE3C4((u8 *)state + 0x330); *(s32 *)state = 0x7d; fn_801DDDE8(5, arg0);
 case 0x7d:
  if (Card_GetResult() == 0) {
   fn_801E21EC(&gSaveDataBase, *(s8 *)((u8 *)state + 0x12)); *(s32 *)state = 0x82;
  } else {
   Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
   Ui_OpenConfirmDialog(gUiSeCues + 0x4b5, 0, 0, 0, NULL, 1, arg0); *(s32 *)state = 0x69;
  }
  break;
 case 0x82:
  if (Card_GetResult() == 0) {
   fn_801D8854((u8 *)state + *(s8 *)((u8 *)state + 0x12) * 0x4c + 0x1b4, (u32)(gUiSeCues + 0x4c1));
   *(s32 *)state = 0x87; fn_801DDDE8(0x64, arg0);
  } else {
   Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
   Ui_OpenConfirmDialog(gUiSeCues + 0x4d2, 0, 0, 0, NULL, 1, arg0); *(s32 *)state = 0x69;
  }
  break;
 case 0x87:
  fn_8008A290(3, 0xfa); Game_SetState(0x1c);
  fn_80006160(*(s8 *)((u8 *)state + 0x12)); Process_ClearFunc(arg0); break;
    case 0xc8:
    fn_801DBEA8(state, 1); *(s8 *)((u8 *)state + 0x12) = -1;
    p24 = (s32 *)state; i25 = 0;
    while (i25 < 5) {
     fn_801D8D58((u8 *)p24 + 0x1b4); fn_801D8C0C((u8 *)p24 + 0x1b4, i25);
     i25 += 1; p24 = (s32 *)((u8 *)p24 + 0x4c);
    }
    p24 = (s32 *)gSystemSave; tmp_ptr = (void *)state; changed = 0;
    while (changed < 5) {
     fn_801D88B8((u8 *)tmp_ptr + 0x1b4, state, 0);
     if (*(s16 *)((u8 *)tmp_ptr + 0x1b4) & 4) {
      if (*(s8 *)((u8 *)state + 0x12) == -1 || (s32)(u8)fn_801DE358(p24) == changed)
       *(u8 *)((u8 *)state + 0x12) = (u8)changed;
     }
     changed += 1; tmp_ptr = (u8 *)tmp_ptr + 0x4c;
    }
    { s8 idx = *(s8 *)((u8 *)state + 0x12); s16 *fl = (s16 *)((u8 *)state + idx * 0x4c + 0x1b4); *fl = (s16)(*fl | 2); }
    *(s32 *)state = 0xcd; fn_801DDDE8(0x14, arg0); break;
 case 0xcd: {
  s8 idx = *(s8 *)((u8 *)state + 0x12); u8 *base = (u8 *)state + idx * 0x4c;
  fn_801D8E18((u8 *)state + 0x51a, *(s16 *)(base + 0x1be), *(s16 *)(base + 0x1c0), 1, 0);
  *(s32 *)state = 0xce;
 }
 case 0xce:
  if (flags_a & 0x100) {
   if (fn_801DC0CC() != 0) {
    Ui_OpenConfirmDialog(gUiSeCues + 0x462, 1, 1, 1, gUiSeCues + 0x318, 0, arg0);
    *(s32 *)state = 0xd2; Ui_PlaySeCue(gUiSeCues + 0x2d4, 0x64);
   } else { *(s32 *)state = 0xd7; Ui_PlaySeCue(gUiSeCues + 0x318, 0x64); }
  } else if (flags_a & 0x200) {
   *(s32 *)state = 0x3b6; Ui_PlaySeCue(gUiSeCues + 0x2e4, 0x64);
  } else if (flags_b & 0x8000008) {
   sel = *(s8 *)((u8 *)state + 0x12);
   { s16 *fl = (s16 *)((u8 *)state + sel * 0x4c + 0x1b4); *fl = (s16)(*fl & ~2); }
   do { *(u8 *)((u8 *)state + 0x12) = *(u8 *)((u8 *)state + 0x12) - 1;
        if (*(s8 *)((u8 *)state + 0x12) < 0) *(u8 *)((u8 *)state + 0x12) = 4;
   } while (!(*(s16 *)((u8 *)state + *(s8 *)((u8 *)state + 0x12) * 0x4c + 0x1b4) & 4));
   { s8 idx = *(s8 *)((u8 *)state + 0x12); s16 *fl = (s16 *)((u8 *)state + idx * 0x4c + 0x1b4); *fl = (s16)(*fl | 2);
     fn_801D8D78((u8 *)state + 0x51a, *(s16 *)((u8 *)state + idx * 0x4c + 0x1be), *(s16 *)((u8 *)state + idx * 0x4c + 0x1c0), 1, 0); }
   if (sel != *(s8 *)((u8 *)state + 0x12)) Ui_PlaySeCue(gUiSeCues + 0x473, 0x64);
  } else if (flags_b & 0x4000004) {
   sel = *(s8 *)((u8 *)state + 0x12);
   { s16 *fl = (s16 *)((u8 *)state + sel * 0x4c + 0x1b4); *fl = (s16)(*fl & ~2); }
   do { *(u8 *)((u8 *)state + 0x12) = *(u8 *)((u8 *)state + 0x12) + 1;
        if (*(s8 *)((u8 *)state + 0x12) > 4) *(u8 *)((u8 *)state + 0x12) = 0;
   } while (!(*(s16 *)((u8 *)state + *(s8 *)((u8 *)state + 0x12) * 0x4c + 0x1b4) & 4));
   { s8 idx = *(s8 *)((u8 *)state + 0x12); s16 *fl = (s16 *)((u8 *)state + idx * 0x4c + 0x1b4); *fl = (s16)(*fl | 2);
     fn_801D8D78((u8 *)state + 0x51a, *(s16 *)((u8 *)state + idx * 0x4c + 0x1be), *(s16 *)((u8 *)state + idx * 0x4c + 0x1c0), 1, 0); }
   if (sel != *(s8 *)((u8 *)state + 0x12)) Ui_PlaySeCue(gUiSeCues + 0x473, 0x64);
  }
  break;
 case 0xd2:
  if (*(s8 *)((u8 *)state + 0x14) == 0) { fn_801E00EC(&gSaveDataBase, arg0); *(s32 *)state = 0xd5; }
  else *(s32 *)state = 0xcd;
  break;
 case 0xd5:
  if (Card_GetResult() == 0) { *(s32 *)state = 0xd7; fn_801D8894((u8 *)state + 0x60); }
  else {
   Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
   Ui_OpenConfirmDialog(gUiSeCues + 0x488, 0, 0, 0, NULL, 1, arg0); *(s32 *)state = 0xcd;
  }
  break;
 case 0xd6: break;
 case 0xd7:
  fn_801E21EC(&gSaveDataBase, *(s8 *)((u8 *)state + 0x12));
  *(s32 *)state = 0xdc; fn_801DDDE8(0xa, arg0); break;
 case 0xdc:
  if (Card_GetResult() == 0) {
   fn_8008A290(3, 0xfa); Game_SetState(0x1c);
   fn_80006160(*(s8 *)((u8 *)state + 0x12)); Process_ClearFunc(arg0);
  } else {
   Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
   Ui_OpenConfirmDialog(gUiSeCues + 0x4df, 0, 0, 0, NULL, 1, arg0); *(s32 *)state = 0xcd;
  }
  break;
 case 0x12c:
  fn_801DBEA8(state, 2); *(s8 *)((u8 *)state + 0x12) = -1;
  p24 = (s32 *)state; i25 = 0;
  while (i25 < 5) {
   fn_801D8D58((u8 *)p24 + 0x1b4); fn_801D8C0C((u8 *)p24 + 0x1b4, (s16)i25);
   i25++; p24 = (s32 *)((u8 *)p24 + 0x4c);
  }
  p24 = (s32 *)state; i25 = 0;
  while (i25 < 5) {
   fn_801D88B8((u8 *)p24 + 0x1b4, state, 0);
   if ((*(s16 *)((u8 *)p24 + 0x1b4) & 8) && *(s8 *)((u8 *)state + 0x12) == -1) *(u8 *)((u8 *)state + 0x12) = (u8)i25;
   i25++; p24 = (s32 *)((u8 *)p24 + 0x4c);
  }
  { s8 idx = *(s8 *)((u8 *)state + 0x12); s16 *fl = (s16 *)((u8 *)state + idx * 0x4c + 0x1b4); *fl = (s16)(*fl | 2); }
  *(s32 *)state = 0x131; fn_801DDDE8(0x14, arg0); break;
 case 0x131: {
  s8 idx = *(s8 *)((u8 *)state + 0x12); u8 *base = (u8 *)state + idx * 0x4c;
  fn_801D8E18((u8 *)state + 0x51a, *(s16 *)(base + 0x1be), *(s16 *)(base + 0x1c0), 1, 0);
  *(s32 *)state = 0x132;
 }
 case 0x132:
  if (flags_a & 0x100) { *(s32 *)state = 0x136; Ui_PlaySeCue(gUiSeCues + 0x318, 0x64); }
  else if (flags_a & 0x200) { *(s32 *)state = 0x3b6; Ui_PlaySeCue(gUiSeCues + 0x2e4, 0x64); }
  break;
 case 0x136:
  fn_801E080C(&gSaveDataBase); *(s32 *)state = 0x13b; fn_801DDDE8(0xa, arg0); break;
 case 0x13b:
  if (Card_GetResult() == 0) *(s32 *)state = 0x140;
  else {
   Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
   Ui_OpenConfirmDialog(gUiSeCues + 0x4eb, 0, 0, 0, NULL, 1, arg0); *(s32 *)state = 0x131;
  }
  break;
 case 0x140:
  fn_801E00EC(&gSaveDataBase, arg0); *(s32 *)state = 0x145; break;
 case 0x145:
  if (Card_GetResult() == 0) {
   fn_801D8894((u8 *)state + 0x60);
   fn_8008A290(3, 0xfa); Game_SetState(0x1d);
   fn_80006160(*(s8 *)((u8 *)state + 0x12)); Process_ClearFunc(arg0);
  } else {
   Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
   Ui_OpenConfirmDialog(gUiSeCues + 0x488, 0, 0, 0, NULL, 1, arg0); *(s32 *)state = 0x131;
  }
  break;
 case 0x190:
  fn_801DBEA8(state, 3); *(s8 *)((u8 *)state + 0x12) = -1;
  p24 = (s32 *)state; i25 = 0;
  while (i25 < 5) {
   fn_801D8D58((u8 *)p24 + 0x1b4); fn_801D8C0C((u8 *)p24 + 0x1b4, (s16)i25);
   i25++; p24 = (s32 *)((u8 *)p24 + 0x4c);
  }
  fn_801DDDE8(0x14, arg0); *(s32 *)state = 0x193;
 case 0x193:
  p24 = (s32 *)state; i25 = 0;
  while (i25 < 5) {
   fn_801D88B8((u8 *)p24 + 0x1b4, state, 0);
   if ((*(s16 *)((u8 *)p24 + 0x1b4) & 4) && *(s8 *)((u8 *)state + 0x12) == -1) *(u8 *)((u8 *)state + 0x12) = (u8)i25;
   i25++; p24 = (s32 *)((u8 *)p24 + 0x4c);
  }
  { s8 idx = *(s8 *)((u8 *)state + 0x12); s16 *fl = (s16 *)((u8 *)state + idx * 0x4c + 0x1b4); *fl = (s16)(*fl | 2); }
  fn_801D8E08((u8 *)state + 0x52e); *(s32 *)state = 0x195; break;
 case 0x195: {
  s8 idx = *(s8 *)((u8 *)state + 0x12); u8 *base = (u8 *)state + idx * 0x4c;
  fn_801D8E18((u8 *)state + 0x51a, *(s16 *)(base + 0x1be), *(s16 *)(base + 0x1c0), 1, 0);
  *(s32 *)state = 0x196;
 }
 case 0x196:
  if (flags_a & 0x100) {
   *(s8 *)((u8 *)state + 0x13) = -1;
   p24 = (s32 *)state; i25 = 0;
   while (i25 < 5) {
    if (fn_801DC10C(i25) != 0) {
     { s16 *fl = (s16 *)((u8 *)p24 + 0x1b4); *fl = (s16)(*fl | 4); }
    } else if (*(s8 *)((u8 *)state + 0x13) == -1) {
     *(u8 *)((u8 *)state + 0x13) = (u8)i25;
    }
    i25++; p24 = (s32 *)((u8 *)p24 + 0x4c);
   }
   { s8 idx = *(s8 *)((u8 *)state + 0x13); s16 *fl = (s16 *)((u8 *)state + idx * 0x4c + 0x1b4); *fl = (s16)(*fl | 2);
     fn_801D8E18((u8 *)state + 0x52e, *(s16 *)((u8 *)state + idx * 0x4c + 0x1be), *(s16 *)((u8 *)state + idx * 0x4c + 0x1c0), 1, 0); }
   *(s32 *)state = 0x19a; Ui_PlaySeCue(gUiSeCues + 0x2d4, 0x64);
  } else if (flags_a & 0x200) {
   *(s32 *)state = 0x3b6; Ui_PlaySeCue(gUiSeCues + 0x2e4, 0x64);
  } else if (flags_b & 0x8000008) {
   sel = *(s8 *)((u8 *)state + 0x12);
   { s16 *fl = (s16 *)((u8 *)state + sel * 0x4c + 0x1b4); *fl = (s16)(*fl & ~2); }
   do { *(u8 *)((u8 *)state + 0x12) = *(u8 *)((u8 *)state + 0x12) - 1;
        if (*(s8 *)((u8 *)state + 0x12) < 0) *(u8 *)((u8 *)state + 0x12) = 4;
   } while (!(*(s16 *)((u8 *)state + *(s8 *)((u8 *)state + 0x12) * 0x4c + 0x1b4) & 4));
   { s8 idx = *(s8 *)((u8 *)state + 0x12); s16 *fl = (s16 *)((u8 *)state + idx * 0x4c + 0x1b4); *fl = (s16)(*fl | 2);
     fn_801D8D78((u8 *)state + 0x51a, *(s16 *)((u8 *)state + idx * 0x4c + 0x1be), *(s16 *)((u8 *)state + idx * 0x4c + 0x1c0), 1, 0); }
   if (sel != *(s8 *)((u8 *)state + 0x12)) Ui_PlaySeCue(gUiSeCues + 0x473, 0x64);
  } else if (flags_b & 0x4000004) {
   sel = *(s8 *)((u8 *)state + 0x12);
   { s16 *fl = (s16 *)((u8 *)state + sel * 0x4c + 0x1b4); *fl = (s16)(*fl & ~2); }
   do { *(u8 *)((u8 *)state + 0x12) = *(u8 *)((u8 *)state + 0x12) + 1;
        if (*(s8 *)((u8 *)state + 0x12) > 4) *(u8 *)((u8 *)state + 0x12) = 0;
   } while (!(*(s16 *)((u8 *)state + *(s8 *)((u8 *)state + 0x12) * 0x4c + 0x1b4) & 4));
   { s8 idx = *(s8 *)((u8 *)state + 0x12); s16 *fl = (s16 *)((u8 *)state + idx * 0x4c + 0x1b4); *fl = (s16)(*fl | 2);
     fn_801D8D78((u8 *)state + 0x51a, *(s16 *)((u8 *)state + idx * 0x4c + 0x1be), *(s16 *)((u8 *)state + idx * 0x4c + 0x1c0), 1, 0); }
   if (sel != *(s8 *)((u8 *)state + 0x12)) Ui_PlaySeCue(gUiSeCues + 0x473, 0x64);
  }
  break;
 case 0x19a:
  if (flags_a & 0x100) { *(s32 *)state = 0x19f; Ui_PlaySeCue(gUiSeCues + 0x2d4, 0x64); }
  else if (flags_a & 0x200) {
   *(s32 *)state = 0x193; fn_801D8E08((u8 *)state + 0x52e);
   Ui_PlaySeCue(gUiSeCues + 0x2e4, 0x64);
  } else if (flags_b & 0x8000008) {
   sel = *(s8 *)((u8 *)state + 0x13);
   { s16 *fl = (s16 *)((u8 *)state + sel * 0x4c + 0x1b4); *fl = (s16)(*fl & ~2); }
   do { *(u8 *)((u8 *)state + 0x13) = *(u8 *)((u8 *)state + 0x13) - 1;
        if (*(s8 *)((u8 *)state + 0x13) < 0) *(u8 *)((u8 *)state + 0x13) = 4;
   } while (*(s16 *)((u8 *)state + *(s8 *)((u8 *)state + 0x13) * 0x4c + 0x1b4) & 4);
   { s8 idx = *(s8 *)((u8 *)state + 0x13); s16 *fl = (s16 *)((u8 *)state + idx * 0x4c + 0x1b4); *fl = (s16)(*fl | 2);
     fn_801D8D78((u8 *)state + 0x52e, *(s16 *)((u8 *)state + idx * 0x4c + 0x1be), *(s16 *)((u8 *)state + idx * 0x4c + 0x1c0), 1, 0); }
   if (sel != *(s8 *)((u8 *)state + 0x13)) Ui_PlaySeCue(gUiSeCues + 0x473, 0x64);
  } else if (flags_b & 0x4000004) {
   sel = *(s8 *)((u8 *)state + 0x13);
   { s16 *fl = (s16 *)((u8 *)state + sel * 0x4c + 0x1b4); *fl = (s16)(*fl & ~2); }
   do { *(u8 *)((u8 *)state + 0x13) = *(u8 *)((u8 *)state + 0x13) + 1;
        if (*(s8 *)((u8 *)state + 0x13) > 4) *(u8 *)((u8 *)state + 0x13) = 0;
   } while (*(s16 *)((u8 *)state + *(s8 *)((u8 *)state + 0x13) * 0x4c + 0x1b4) & 4);
   { s8 idx = *(s8 *)((u8 *)state + 0x13); s16 *fl = (s16 *)((u8 *)state + idx * 0x4c + 0x1b4); *fl = (s16)(*fl | 2);
     fn_801D8D78((u8 *)state + 0x52e, *(s16 *)((u8 *)state + idx * 0x4c + 0x1be), *(s16 *)((u8 *)state + idx * 0x4c + 0x1c0), 1, 0); }
   if (sel != *(s8 *)((u8 *)state + 0x13)) Ui_PlaySeCue(gUiSeCues + 0x473, 0x64);
  }
  break;
 case 0x19f:
  fn_801E0B48(&gSaveDataBase, *(s8 *)((u8 *)state + 0x12), *(s8 *)((u8 *)state + 0x13), arg0);
  MsgBox_Init((u8 *)state + 0x330, gUiSeCues + 0x4fb, 0, 0, 0);
  *(s32 *)state = 0x1a1; break;
    case 0x1a1:
    fn_801DE3C4((u8 *)state + 0x330); *(s32 *)state = 0x1a4;
    if (Card_GetResult() == 0) {
     fn_801D8854((u8 *)state + *(s8 *)((u8 *)state + 0x13) * 0x4c + 0x1b4, (u32)(gUiSeCues + 0x4c1));
     fn_801DDDE8(0x64, arg0);
    } else fn_801DDDE8(5, arg0);
    break;
   case 0x1a4:
    if (Card_GetResult() == 0) {
     result = fn_801DBFF8();
     if (result >= 1 && result < 5) {
      *(s8 *)((u8 *)state + 0x12) = -1; *(s32 *)state = 0x193;
     } else *(s32 *)state = 0x3b6;
    } else {
     Ui_PlaySeCue(gUiSeCues + 0x290, 0x64);
     Ui_OpenConfirmDialog(gUiSeCues + 0x506, 0, 0, 0, NULL, 1, arg0); *(s32 *)state = 0x193;
    }
    break;
 case 0x1f4: *(s32 *)state = 0x1f4; break;
 case 0x1f7: *(s32 *)state = 0x1f7; break;
 case 0x1f8: break;
 case 0x1f9: *(s32 *)state = 0x1f9; break;
 case 0x1fa: *(s32 *)state = 0x1fa; break;
 case 0x1fe: *(s32 *)state = 0x1fe; break;
 case 0x200: *(s32 *)state = 0x200; break;
 case 0x201: *(s32 *)state = 0x201; break;
 case 0x203: *(s32 *)state = 0x203; break;
 case 0x208: *(s32 *)state = 0x208; break;
 case 0x20a: *(s32 *)state = 0x20a; break;
 case 0x20d: *(s32 *)state = 0x20d; break;
 case 0x212: *(s32 *)state = 0x212; break;
 case 0x258: *(s32 *)state = 0x258; break;
 case 0x25d: *(s32 *)state = 0x25d; break;
 case 0x25e: *(s32 *)state = 0x25e; break;
 case 0x262: *(s32 *)state = 0x262; break;
 case 0x267: *(s32 *)state = 0x267; break;
 case 0x268: *(s32 *)state = 0x268; break;
 case 0x269: *(s32 *)state = 0x269; break;
 case 0x26a: *(s32 *)state = 0x26a; break;
 case 0x26c: *(s32 *)state = 0x26c; break;
 case 0x28a: *(s32 *)state = 0x28a; break;
 case 0x2bc: *(s32 *)state = 0x2bc; break;
 case 0x2c1: *(s32 *)state = 0x2c1; break;
 case 0x2c6: *(s32 *)state = 0x2c6; break;
 case 0x2d0: *(s32 *)state = 0x2d0; break;
 case 0x2d5: *(s32 *)state = 0x2d5; break;
 case 0x2e4: *(s32 *)state = 0x2e4; break;
 case 0x2e9: *(s32 *)state = 0x2e9; break;
 case 0x2ee: *(s32 *)state = 0x2ee; break;
 case 0x2f3: *(s32 *)state = 0x2f3; break;
 case 0x2f8: *(s32 *)state = 0x2f8; break;
 case 0x2fd: *(s32 *)state = 0x2fd; break;
 case 0x320: *(s32 *)state = 0x320; break;
 case 0x321: *(s32 *)state = 0x321; break;
 case 0x325: *(s32 *)state = 0x325; break;
 case 0x326: *(s32 *)state = 0x326; break;
 case 0x32a: *(s32 *)state = 0x32a; break;
 case 0x32d: *(s32 *)state = 0x32d; break;
 case 0x32f: *(s32 *)state = 0x32f; break;
 case 0x334: *(s32 *)state = 0x334; break;
 case 0x352: *(s32 *)state = 0x352; break;
 case 0x357: *(s32 *)state = 0x357; break;
 case 0x384: *(s32 *)state = 0x384; break;
 case 0x389: *(s32 *)state = 0x389; break;
 case 0x3a2: *(s32 *)state = 0x3a2; break;
 case 0x3a7: *(s32 *)state = 0x3a7; break;
 case 0x3b6: *(s32 *)state = 0x3b6; break;
 case 0x3bb: *(s32 *)state = 0x3bb; break;
 case 0x3de: *(s32 *)state = 0x3de; break;
 case 0x3e3: *(s32 *)state = 0x3e3; break;
 case 0x3e8: *(s32 *)state = 0x3e8; break;
 case 0x3ed: *(s32 *)state = 0x3ed; break;
 case 0x3f2: *(s32 *)state = 0x3f2; break;
 case 0x3f7: *(s32 *)state = 0x3f7; break;
 default: break;
 }
}

u8 fn_801D8840(void *arg0) {
    return (u8) (M2C_FIELD(arg0, u8 *, 0x16) == 0x20);
}

void fn_801D8854(void *arg0, u32 arg1) {
    *(u16*)((char*)arg0 + 2) = 0x12C;
    if (arg1 != 0) {
        Ui_PlaySeCue(arg1, 0x64);
    }
}

void fn_801D888C(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 2) = arg1;
}

void fn_801D8894(void *arg0) {
    s16 *ptr = (s16 *)arg0;
    ptr[1] = 0x12C;
    ptr[2] = 0;
    ptr[3] = 0x18;
}

void fn_801D88B0(s8 *arg0, s8 arg1) {
    *arg0 = arg1;
}

#pragma optimization_level 3
void fn_801D88B8(void *arg0, void *arg1, u8 arg2) {
    void *fn_801E09B4(void *);
    void *fn_801E2324(void *, void *);
    void fn_801E3A60(void *, s32 *, s32 *, s32 *);
    char *Msg_Expand(void *);
    char *strcpy(char *, char *);
    extern u8 gSaveDataBase;
    extern u8 gUiSeCues[];
    u8 *self = (u8 *)arg0;
    u8 *other = (u8 *)arg1;
    void *save;
    void *unit;
    u8 name;
    s32 flags;

    flags = *(s16 *)self;
    if (flags & 0x20) {
        *(u16 *)(self + 0x3A) = *(u16 *)(self + 0x38);
        *(u8 *)(self + 0x17) = *(u8 *)(self + 0x16);
        strcpy((char *)self + 0x28, (char *)self + 0x18);
        if (arg2 != 0) {
            *(u16 *)(self + 0x3C) = 0;
        }
        flags = *(s16 *)self;
        if (flags & 4) {
            *(s16 *)self = flags | 0x40;
        } else {
            *(s16 *)self = flags & ~0x40;
        }
    } else {
        *(s16 *)self = flags | 0x20;
    }

    save = fn_801E09B4(&gSaveDataBase);
    if (save == NULL) goto save0_null;
    if (*(u8 *)((u8 *)save + 0x60) != 3) goto save0_null;
    goto save0_ok;
save0_null:
    save = NULL;
save0_ok:
    if (save != NULL) {
        save = fn_801E09B4(&gSaveDataBase);
        if (save == NULL) goto save1_null;
        if (*(u8 *)((u8 *)save + 0x60) != 3) goto save1_null;
        goto save1_ok;
save1_null:
        save = NULL;
save1_ok:
        name = *(u8 *)((u8 *)save + 0x63);
    } else {
        name = 0xFF;
    }

    *(s16 *)self = *(s16 *)self | 1;
    *(s16 *)self = *(s16 *)self & ~4;
    *(s16 *)self = *(s16 *)self & ~8;
    *(s16 *)self = *(s16 *)self & ~2;

    save = fn_801E2324(&gSaveDataBase, (void *)(s32)*(s16 *)(self + 8));
    if (save == NULL) goto unit0_null;
    if (*(u8 *)((u8 *)save + 0x60) != 2) goto unit0_null;
    goto unit0_ok;
unit0_null:
    save = NULL;
unit0_ok:
    if (save == NULL) goto early_exit;
    unit = fn_801E2324(&gSaveDataBase, (void *)(s32)*(s16 *)(self + 8));
    if (unit == NULL) goto unit1_null;
    if (*(u8 *)((u8 *)unit + 0x60) != 2) goto unit1_null;
    goto unit1_ok;
unit1_null:
    unit = NULL;
unit1_ok:

    *(s16 *)self = *(s16 *)self | 4;
    *(u8 *)(self + 0x16) = *(u8 *)((u8 *)unit + 0x64);
    if (*(s16 *)(self + 8) == (u8)name) {
        *(s16 *)self = *(s16 *)self | 8;
        *(s16 *)(other + 0x60) |= 1;
        *(u16 *)(other + 0x62) = 0x64;
        *(u8 *)(other + 0x78) = 0x80;
    }
    fn_801E3A60(unit, (s32 *)(self + 0x40), (s32 *)(self + 0x44), (s32 *)(self + 0x48));
    if (*(s32 *)(self + 0x40) >= 0x63) {
        *(s32 *)(self + 0x40) = 0x63;
        *(s32 *)(self + 0x44) = 0x3B;
        *(s32 *)(self + 0x48) = 0x3B;
    }

    switch (*(u8 *)((u8 *)unit + 0x66)) {
    case 0:
        *(u16 *)(self + 0x38) = 2;
        break;
    case 1:
        *(u16 *)(self + 0x38) = 3;
        break;
    case 2:
    case 3:
        *(u16 *)(self + 0x38) = 4;
        break;
    }

    switch (*(u8 *)((u8 *)unit + 0x65)) {
    case 1:
        strcpy((char *)self + 0x18, Msg_Expand(gUiSeCues + 0x585));
        break;
    case 2:
        strcpy((char *)self + 0x18, Msg_Expand(gUiSeCues + 0x58E));
        break;
    case 5:
        strcpy((char *)self + 0x18, Msg_Expand(gUiSeCues + 0x597));
        break;
    case 6:
        strcpy((char *)self + 0x18, Msg_Expand(gUiSeCues + 0x5A0));
        break;
    case 7:
        strcpy((char *)self + 0x18, Msg_Expand(gUiSeCues + 0x5A9));
        break;
    case 9:
        strcpy((char *)self + 0x18, Msg_Expand(gUiSeCues + 0x5B2));
        break;
    case 0:
    case 3:
    case 4:
    case 8:
    default:
        *(u8 *)(self + 0x18) = 0;
        break;
    }
    goto done;
early_exit:
    *(u16 *)(self + 0x38) = 2;
done:
    return;
}
#pragma optimization_level reset
void fn_801D8C0C(void *arg0, s16 arg1)
{
  memset(arg0, 0, 0x4C);
  *((s16 *) (((char *) arg0) + 2)) = 0;
  *((s16 *) (((char *) arg0) + 0)) = 0;
  *((s16 *) (((char *) arg0) + 8)) = arg1 ^ 0;
  *((s16 *) (((char *) arg0) + 2)) = 0x64;
}

#pragma use_lmw_stmw on
#pragma opt_common_subs off
/* Clear a file-menu entry and build its label from gFileMenuMsgKeys[type] via Msg_Expand. */
void FileMenu_InitEntry(void *entry, s16 slot, s16 type)
{
    extern u32 gFileMenuMsgKeys[12];
    extern u8 gUiSeCues[];
    void *Msg_Expand(u32);
    void strcpy(void *, u8 *);
    void strcat(void *, void *);
    u32 msgKeys[12];
    s16 idx;

    msgKeys[0] = gFileMenuMsgKeys[0];
    msgKeys[1] = gFileMenuMsgKeys[1];
    msgKeys[2] = gFileMenuMsgKeys[2];
    msgKeys[3] = gFileMenuMsgKeys[3];
    msgKeys[4] = gFileMenuMsgKeys[4];
    msgKeys[5] = gFileMenuMsgKeys[5];
    msgKeys[6] = gFileMenuMsgKeys[6];
    msgKeys[7] = gFileMenuMsgKeys[7];
    msgKeys[8] = gFileMenuMsgKeys[8];
    msgKeys[9] = gFileMenuMsgKeys[9];
    msgKeys[10] = gFileMenuMsgKeys[10];
    msgKeys[11] = gFileMenuMsgKeys[11];
    memset(entry, 0, 0x34);
    *(s16 *)((u8 *)entry + 2) = 0;
    *(s16 *)((u8 *)entry + 0) = 0;
    *(s16 *)((u8 *)entry + 0xa) = slot;
    *(s16 *)((u8 *)entry + 8) = type;
    *(s16 *)((u8 *)entry + 2) = 0x64;
    strcpy((u8 *)entry + 0x18, gUiSeCues + 0x5bb);
    idx = *(s16 *)((u8 *)entry + 8);
    strcat((u8 *)entry + 0x18, Msg_Expand(msgKeys[idx]));
}
#pragma opt_common_subs reset
void fn_801D8D58(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 0) = 0;
}

void fn_801D8D68(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 0) = 0;
}

void fn_801D8D78(void *arg0,s16 arg1,s16 arg2,u8 arg3,u8 arg4) { s16 a=M2C_FIELD(arg0,s16*,0xa); s16 b=M2C_FIELD(arg0,s16*,8); M2C_FIELD(arg0,s16*,0)=(s16)(M2C_FIELD(arg0,s16*,0)|1); if(arg3){M2C_FIELD(arg0,s16*,0)=(s16)(M2C_FIELD(arg0,s16*,0)|2);}else{M2C_FIELD(arg0,s16*,0)=(s16)(M2C_FIELD(arg0,s16*,0)&0xfffffffd);} if(arg4){M2C_FIELD(arg0,s16*,0)=(s16)(M2C_FIELD(arg0,s16*,0)|4);}else{M2C_FIELD(arg0,s16*,0)=(s16)(M2C_FIELD(arg0,s16*,0)&0xfffffffb);} M2C_FIELD(arg0,s16*,2)=0xc8; M2C_FIELD(arg0,s16*,0xc)=b; M2C_FIELD(arg0,s16*,8)=b; M2C_FIELD(arg0,s16*,0xe)=a; M2C_FIELD(arg0,s16*,0xa)=a; M2C_FIELD(arg0,s16*,0x10)=arg1; M2C_FIELD(arg0,s16*,0x12)=arg2; M2C_FIELD(arg0,s16*,4)=0; M2C_FIELD(arg0,s16*,6)=4; }

void fn_801D8E08(s16 *arg0) {
    *arg0 &= 0xFFFFFFFE;
}

void fn_801D8E18(void *arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4) {
    M2C_FIELD(arg0, s16 *, 0) = (s16) (M2C_FIELD(arg0, s16 *, 0) | 1);
    if (arg3 != 0) {
        M2C_FIELD(arg0, s16 *, 0) = (s16) (M2C_FIELD(arg0, s16 *, 0) | 2);
    } else {
        M2C_FIELD(arg0, s16 *, 0) = (s16) (M2C_FIELD(arg0, s16 *, 0) & 0xFFFFFFFD);
    }
    if (arg4 != 0) {
        M2C_FIELD(arg0, s16 *, 0) = (s16) (M2C_FIELD(arg0, s16 *, 0) | 4);
    } else {
        M2C_FIELD(arg0, s16 *, 0) = (s16) (M2C_FIELD(arg0, s16 *, 0) & 0xFFFFFFFB);
    }
    M2C_FIELD(arg0, s16 *, 2) = 0x64;
    M2C_FIELD(arg0, s16 *, 8) = arg1;
    M2C_FIELD(arg0, s16 *, 0xA) = arg2;
}

void fn_801D8E80(void *arg0) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_UnlinkByKey(void *);
    void fn_801DB5B4(void *, void *);
    void MsgBox_Layout(void *);
    s16 CARDProbeEx(s32, s32, s32);
    extern u8 lbl_80299C88[];
    extern u32 gUiInputFlags;
    extern f32 lbl_8036B628;
    extern f32 lbl_8036B62C;
    extern f32 lbl_8036B630;
    extern f32 lbl_8036B634;
    extern f32 lbl_8036B638;
    extern f64 lbl_8036B670;

    u8 *st;
    s16 pad;
    s16 i;
    u8 *slot;
    s8 side;

    st = *(u8 **)((u8 *)arg0 + 0x30);
    if (!(gUiInputFlags & 0x10)) {
        pad = CARDProbeEx(0, 0, 0);
        if (pad == -0x80) {
            *(s32 *)st = 0x28;
        }
        if (pad != -1) {
            if ((u16)*(s16 *)(st + 0x16) != 0xFFFF) {
                if (*(s16 *)(st + 0x16) == -3 && (pad == -2 || pad == 0)) {
                    *(s32 *)st = 0;
                    Process_UnlinkByKey(lbl_80299C88);
                }
                if ((*(s16 *)(st + 0x16) == -2 || *(s16 *)(st + 0x16) == 0) && pad == -3) {
                    *(s32 *)st = 0;
                    Process_UnlinkByKey(lbl_80299C88);
                }
            }
            *(s16 *)(st + 0x16) = pad;
        }
    }

    switch (*(s16 *)(st + 0x62)) {
    case 0:
        *(s16 *)(st + 0x60) = 0;
        break;
    case 0x64:
        *(f32 *)(st + 0x6C) = *(f32 *)(st + 0x6C) + lbl_8036B628;
        if (*(f32 *)(st + 0x6C) >= lbl_8036B62C) {
            *(f32 *)(st + 0x6C) = *(f32 *)(st + 0x6C) - lbl_8036B62C;
        }
        *(s16 *)(st + 0x70) = 0;
        *(f32 *)(st + 0x74) = lbl_8036B630;
        break;
    case 0x12C:
        *(s16 *)(st + 0x64) = (s16)(*(s16 *)(st + 0x64) + 1);
        *(s16 *)(st + 0x70) = (s16)Math_Ease(0, lbl_8036B634, lbl_8036B638, (f32)*(s16 *)(st + 0x64), (f32)*(s16 *)(st + 0x66));
        *(f32 *)(st + 0x74) = Math_Ease(0, lbl_8036B630, lbl_8036B634, (f32)*(s16 *)(st + 0x64), (f32)*(s16 *)(st + 0x66));
        if (*(s16 *)(st + 0x64) >= *(s16 *)(st + 0x66)) {
            *(s16 *)(st + 0x62) = 0;
        }
        break;
    }

    for (i = 0, slot = st; i < 6; i++, slot += 0x34) {
        side = (s8)st[0x15];
        switch (*(s16 *)(slot + 0x7E)) {
        case 0:
            *(s16 *)(slot + 0x7C) = 0;
            break;
        case 0x64:
            *(s16 *)(slot + 0x7C) = (s16)(*(s16 *)(slot + 0x7C) | 1);
            *(s16 *)(slot + 0x7E) = 0x69;
            *(s16 *)(slot + 0x8A) = (s16)(((6 - side) * 0x1E) + (*(s16 *)(slot + 0x86) * 0x3C) + 0x2D);
            if ((*(s16 *)(slot + 0x86) & 1) == 0) {
                *(s16 *)(slot + 0x8C) = -0x156;
                *(s16 *)(slot + 0x88) = -0x156;
                *(s16 *)(slot + 0x90) = 0x9E;
            } else {
                *(s16 *)(slot + 0x8C) = 0x292;
                *(s16 *)(slot + 0x88) = 0x292;
                *(s16 *)(slot + 0x90) = 0x9E;
            }
            *(s16 *)(slot + 0x80) = 0;
            *(s16 *)(slot + 0x82) = 0xF;
            /* fallthrough */
        case 0x69:
            *(s16 *)(slot + 0x80) = (s16)(*(s16 *)(slot + 0x80) + 1);
            *(s16 *)(slot + 0x88) = (s16)Math_Ease(4, (f32)*(s16 *)(slot + 0x8C), (f32)*(s16 *)(slot + 0x90), (f32)*(s16 *)(slot + 0x80), (f32)*(s16 *)(slot + 0x82));
            if (*(s16 *)(slot + 0x80) >= *(s16 *)(slot + 0x82)) {
                *(s16 *)(slot + 0x7E) = 0x6E;
            }
            break;
        case 0xC8:
            *(s16 *)(slot + 0x7C) = (s16)(*(s16 *)(slot + 0x7C) | 1);
            *(s16 *)(slot + 0x7E) = 0xCD;
            *(s16 *)(slot + 0x8A) = (s16)(((6 - side) * 0x1E) + (*(s16 *)(slot + 0x86) * 0x3C) + 0x2D);
            if ((*(s16 *)(slot + 0x86) & 1) == 0) {
                *(s16 *)(slot + 0x8C) = 0x9E;
                *(s16 *)(slot + 0x88) = 0x9E;
                *(s16 *)(slot + 0x90) = 0x292;
            } else {
                *(s16 *)(slot + 0x8C) = 0x9E;
                *(s16 *)(slot + 0x88) = 0x9E;
                *(s16 *)(slot + 0x90) = -0x156;
            }
            *(s16 *)(slot + 0x80) = 0;
            *(s16 *)(slot + 0x82) = 0xF;
            /* fallthrough */
        case 0xCD:
            *(s16 *)(slot + 0x80) = (s16)(*(s16 *)(slot + 0x80) + 1);
            *(s16 *)(slot + 0x88) = (s16)Math_Ease(4, (f32)*(s16 *)(slot + 0x8C), (f32)*(s16 *)(slot + 0x90), (f32)*(s16 *)(slot + 0x80), (f32)*(s16 *)(slot + 0x82));
            if (*(s16 *)(slot + 0x80) >= *(s16 *)(slot + 0x82)) {
                *(s16 *)(slot + 0x7E) = 0xD2;
            }
            break;
        case 0x12C:
            *(s16 *)(slot + 0x7C) = (s16)(*(s16 *)(slot + 0x7C) | 1);
            *(s16 *)(slot + 0x7E) = 0x69;
            *(s16 *)(slot + 0x8A) = 0x28;
            *(s16 *)(slot + 0x8C) = 0x292;
            *(s16 *)(slot + 0x88) = 0x292;
            *(s16 *)(slot + 0x90) = 0x9E;
            *(s16 *)(slot + 0x80) = 0;
            *(s16 *)(slot + 0x82) = 0xF;
            break;
        case 0x190:
            *(s16 *)(slot + 0x7C) = (s16)(*(s16 *)(slot + 0x7C) | 1);
            *(s16 *)(slot + 0x7E) = 0xCD;
            *(s16 *)(slot + 0x8A) = 0x28;
            *(s16 *)(slot + 0x8C) = 0x9E;
            *(s16 *)(slot + 0x88) = 0x9E;
            *(s16 *)(slot + 0x90) = -0x156;
            *(s16 *)(slot + 0x80) = 0;
            *(s16 *)(slot + 0x82) = 0xF;
            break;
        }
    }

    {
        s16 j;
        u8 *row;
        for (j = 0, row = st; j < 5; j++, row += 0x4C) {
            fn_801DB5B4(row + 0x1B4, st);
        }
    }

    switch (*(s16 *)(st + 0x332)) {
    case 0:
        *(s16 *)(st + 0x330) = 0;
        break;
    case 0x64:
        *(s16 *)(st + 0x330) = (s16)(*(s16 *)(st + 0x330) | 1);
        *(s16 *)(st + 0x332) = 0x6E;
        /* fallthrough */
    case 0x6E:
        *(s16 *)(st + 0x34E) = (s16)(*(s16 *)(st + 0x34E) + 1);
        if (*(s16 *)(st + 0x34E) >= 5) {
            *(s16 *)(st + 0x34E) = 5;
        }
        break;
    case 0xC8:
        *(s16 *)(st + 0x330) = (s16)(*(s16 *)(st + 0x330) | 1);
        *(s16 *)(st + 0x332) = 0xD2;
        /* fallthrough */
    case 0xD2:
        *(s16 *)(st + 0x34E) = (s16)(*(s16 *)(st + 0x34E) - 1);
        if (*(s16 *)(st + 0x34E) < 1) {
            *(s16 *)(st + 0x34E) = 0;
            *(s16 *)(st + 0x332) = 0;
            *(s16 *)(st + 0x330) = 0;
        }
        break;
    }
    MsgBox_Layout(st + 0x330);

    {
        s16 k;
        u8 *a;
        for (k = 0, a = st; k < 2; k++, a += 0x14) {
            switch (*(s16 *)(a + 0x51C)) {
            case 0:
                *(s16 *)(a + 0x51A) = 0;
                break;
            case 0xC8:
                *(s16 *)(a + 0x51E) = (s16)(*(s16 *)(a + 0x51E) + 1);
                *(s16 *)(a + 0x522) = (s16)Math_Ease(4, (f32)*(s16 *)(a + 0x526), (f32)*(s16 *)(a + 0x52A), (f32)*(s16 *)(a + 0x51E), (f32)*(s16 *)(a + 0x520));
                *(s16 *)(a + 0x524) = (s16)Math_Ease(4, (f32)*(s16 *)(a + 0x528), (f32)*(s16 *)(a + 0x52C), (f32)*(s16 *)(a + 0x51E), (f32)*(s16 *)(a + 0x520));
                if (*(s16 *)(a + 0x51E) >= *(s16 *)(a + 0x520)) {
                    *(s16 *)(a + 0x51C) = 0x64;
                }
                break;
            }
        }
    }
}

void fn_801D9FA4(void *arg0)
{
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetAlphaByte(s32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_AddZ(f32);
    void **fn_8006EDD8(void *, s32);
    u32 *Ui_GetColor(s32);
    void Prim2D_BindTexture(void *, s32, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPrimParam(f32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetColor(u8, u8, u8, u8);
    void Prim2D_EmitQuad(void);
    void Prim2D_EndPrim(void);
    void Prim2D_SetTex(s32, s32);
    s32 Text_MeasureWidth(void *, s32, f32);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, f32, f32, ...);

    extern s32 lbl_803682E4;
    extern u8 lbl_80299A78[];
    extern u8 gUiSeCues[];
    extern f32 lbl_8036B630;
    extern f32 lbl_8036B634;
    extern f32 lbl_8036B63C;
    extern f32 lbl_8036B648;
    extern f32 lbl_8036B654;
    extern f32 lbl_8036B658;
    extern f32 lbl_8036B664;
    extern f32 lbl_8036B680;
    extern f32 lbl_8036B684;
    extern f32 lbl_8036B688;
    extern f32 lbl_8036B68C;
    extern f32 lbl_8036B690;

    u8 *self = (u8 *)arg0;
    void *sprite;
    u8 *found;
    u16 *tex;
    u16 texIndex;
    u16 w;
    u16 h;
    s16 spriteX;
    s16 spriteY;
    s32 originX;
    s32 originY;
    f32 fx;
    f32 fy;
    f32 tw;
    f32 th;
    s32 textWidth;
    s32 textX;
    s32 alpha;
    u32 color0;
    u32 color1;
    u32 color2;
    u32 color3;
    u32 color4;
    u32 color5;
    u32 color6;
    u32 color7;
    u32 color8;
    s32 i;
    s16 flags;

    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B634, lbl_8036B634, lbl_8036B63C, lbl_8036B630);
    Prim2D_PrepareTex();

    flags = *(s16 *)self;
    if ((flags & 1) == 0) {
        return;
    }

    if (flags & 2) {
        Prim2D_Begin();
        Prim2D_SetAlphaByte(0x80);
        Prim2D_PrepareTex();
    } else {
        Prim2D_Begin();
        Prim2D_SetAlphaByte(0x40);
        Prim2D_PrepareTex();
    }
    Prim2D_Begin();
    Prim2D_SetColorByte((u8)*(s16 *)(self + 0x3C));
    Prim2D_PrepareTex();

    texIndex = *(u16 *)(self + 0x38);
    fx = (f32)*(s16 *)(self + 0xA);
    fy = (f32)*(s16 *)(self + 0xC);
    tex = *(u16 **)fn_8006EDD8((void *)lbl_803682E4, texIndex);
    tw = (f32)tex[0];
    th = (f32)tex[1];
    color0 = *Ui_GetColor(1);
    tex = *(u16 **)fn_8006EDD8((void *)lbl_803682E4, texIndex);
    w = tex[0];
    h = tex[1];
    Prim2D_Begin();
    Prim2D_BindTexture((void *)lbl_803682E4, texIndex, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetPrimParam(lbl_8036B634);
    Prim2D_SetQuadMin(fx, fy, lbl_8036B634, lbl_8036B634);
    Prim2D_SetQuadMax(fx + th, fy + tw, (f32)h, (f32)w);
    Prim2D_SetColor(((u8 *)&color0)[0], ((u8 *)&color0)[1], ((u8 *)&color0)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B680);
    Prim2D_PrepareTex();

    tex = *(u16 **)fn_8006EDD8((void *)lbl_803682E4, 5);
    fx = (f32)*(s16 *)(self + 0xA);
    fy = (f32)*(s16 *)(self + 0xC);
    tw = (f32)tex[0];
    th = (f32)tex[1];
    color1 = *Ui_GetColor(1);
    tex = *(u16 **)fn_8006EDD8((void *)lbl_803682E4, 5);
    w = tex[0];
    h = tex[1];
    Prim2D_Begin();
    Prim2D_BindTexture((void *)lbl_803682E4, 5, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetPrimParam(lbl_8036B634);
    Prim2D_SetQuadMin(fx, fy, lbl_8036B634, lbl_8036B634);
    Prim2D_SetQuadMax(fx + th, fy + tw, (f32)h, (f32)w);
    Prim2D_SetColor(((u8 *)&color1)[0], ((u8 *)&color1)[1], ((u8 *)&color1)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    spriteX = (s16)(*(s16 *)(self + 0xA) + 0x61);
    spriteY = (s16)(*(s16 *)(self + 0xC) + 0xD);
    if (*(s16 *)self & 4) {
        found = MenuResource_Find(self[0x16]);
        sprite = found != 0 ? *(void **)(found + 8) : 0;
        if (sprite != 0) {
            tex = *(u16 **)fn_8006EDD8(sprite, 0);
            w = tex[1];
            h = tex[0];
            Prim2D_Begin();
            Prim2D_BindTexture(sprite, 0, 0x11);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetQuadMin((f32)spriteX, (f32)spriteY, lbl_8036B634, lbl_8036B634);
            Prim2D_SetQuadMax((f32)(spriteX + w), (f32)(spriteY + h), (f32)w, (f32)h);
            Prim2D_EndPrim();
        }
        if ((s8)self[0x18] != 0) {
            Prim2D_Begin();
            Prim2D_SetTex(0, 0x13);
            Prim2D_PrepareTex();
            textWidth = Text_MeasureWidth(self + 0x18, -1, lbl_8036B684);
            textX = (s32)((f32)(*(s16 *)(self + 0xA) + 0x1BE) - (f32)textWidth * lbl_8036B658);
            fn_8001003C(textX, (s16)(*(s16 *)(self + 0xC) + 0xC), 6, 1, 0, self + 0x18, lbl_8036B684, lbl_8036B634);
        }
    } else {
        found = MenuResource_Find(0x63);
        sprite = found != 0 ? *(void **)(found + 8) : 0;
        if (sprite != 0) {
            tex = *(u16 **)fn_8006EDD8(sprite, 0);
            w = tex[1];
            h = tex[0];
            Prim2D_Begin();
            Prim2D_BindTexture(sprite, 0, 0x11);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetQuadMin((f32)spriteX, (f32)spriteY, lbl_8036B634, lbl_8036B634);
            Prim2D_SetQuadMax((f32)(spriteX + w), (f32)(spriteY + h), (f32)w, (f32)h);
            Prim2D_EndPrim();
        }
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B664);
    Prim2D_PrepareTex();

    alpha = 0xFF - *(s16 *)(self + 0x3C);
    if (alpha != 0) {
        Prim2D_Begin();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();

        texIndex = *(u16 *)(self + 0x3A);
        fx = (f32)*(s16 *)(self + 0xA);
        fy = (f32)*(s16 *)(self + 0xC);
        tex = *(u16 **)fn_8006EDD8((void *)lbl_803682E4, texIndex);
        tw = (f32)tex[0];
        th = (f32)tex[1];
        color2 = *Ui_GetColor(1);
        tex = *(u16 **)fn_8006EDD8((void *)lbl_803682E4, texIndex);
        w = tex[0];
        h = tex[1];
        Prim2D_Begin();
        Prim2D_BindTexture((void *)lbl_803682E4, texIndex, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetPrimParam(lbl_8036B634);
        Prim2D_SetQuadMin(fx, fy, lbl_8036B634, lbl_8036B634);
        Prim2D_SetQuadMax(fx + th, fy + tw, (f32)h, (f32)w);
        Prim2D_SetColor(((u8 *)&color2)[0], ((u8 *)&color2)[1], ((u8 *)&color2)[2], 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B654);
        Prim2D_PrepareTex();

        fx = (f32)*(s16 *)(self + 0xA);
        fy = (f32)*(s16 *)(self + 0xC);
        tex = *(u16 **)fn_8006EDD8((void *)lbl_803682E4, 5);
        tw = (f32)tex[0];
        th = (f32)tex[1];
        color3 = *Ui_GetColor(1);
        tex = *(u16 **)fn_8006EDD8((void *)lbl_803682E4, 5);
        w = tex[0];
        h = tex[1];
        Prim2D_Begin();
        Prim2D_BindTexture((void *)lbl_803682E4, 5, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetPrimParam(lbl_8036B634);
        Prim2D_SetQuadMin(fx, fy, lbl_8036B634, lbl_8036B634);
        Prim2D_SetQuadMax(fx + th, fy + tw, (f32)h, (f32)w);
        Prim2D_SetColor(((u8 *)&color3)[0], ((u8 *)&color3)[1], ((u8 *)&color3)[2], 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
    }

    Prim2D_Begin();
    Prim2D_SetColorByte((u8)(0xFF - *(s16 *)(self + 0x3C)));
    Prim2D_PrepareTex();

    spriteX = (s16)(*(s16 *)(self + 0xA) + 0x61);
    spriteY = (s16)(*(s16 *)(self + 0xC) + 0xD);
    if (*(s16 *)self & 0x40) {
        found = MenuResource_Find(self[0x17]);
        sprite = found != 0 ? *(void **)(found + 8) : 0;
        if (sprite != 0) {
            tex = *(u16 **)fn_8006EDD8(sprite, 0);
            w = tex[1];
            h = tex[0];
            Prim2D_Begin();
            Prim2D_BindTexture(sprite, 0, 0x11);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetQuadMin((f32)spriteX, (f32)spriteY, lbl_8036B634, lbl_8036B634);
            Prim2D_SetQuadMax((f32)(spriteX + w), (f32)(spriteY + h), (f32)w, (f32)h);
            Prim2D_EndPrim();
        }
        if ((s8)self[0x28] != 0) {
            Prim2D_Begin();
            Prim2D_SetTex(0, 0x13);
            Prim2D_PrepareTex();
            textWidth = Text_MeasureWidth(self + 0x28, -1, lbl_8036B684);
            textX = (s32)((f32)(*(s16 *)(self + 0xA) + 0x1BE) - (f32)textWidth * lbl_8036B658);
            fn_8001003C(textX, (s16)(*(s16 *)(self + 0xC) + 0xC), 6, 1, 0, self + 0x28, lbl_8036B684, lbl_8036B634);
        }
    } else {
        found = MenuResource_Find(0x63);
        sprite = found != 0 ? *(void **)(found + 8) : 0;
        if (sprite != 0) {
            tex = *(u16 **)fn_8006EDD8(sprite, 0);
            w = tex[1];
            h = tex[0];
            Prim2D_Begin();
            Prim2D_BindTexture(sprite, 0, 0x11);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetQuadMin((f32)spriteX, (f32)spriteY, lbl_8036B634, lbl_8036B634);
            Prim2D_SetQuadMax((f32)(spriteX + w), (f32)(spriteY + h), (f32)w, (f32)h);
            Prim2D_EndPrim();
        }
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B630);
    Prim2D_PrepareTex();

    if (*(s16 *)self & 0x10) {
        Prim2D_Begin();
        Prim2D_SetColorByte((u8)*(s16 *)(self + 0x3C));
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B680);
        Prim2D_PrepareTex();
        for (i = 0; i < 3; i++) {
            fx = (f32)*(s16 *)(self + 0xA);
            fy = (f32)*(s16 *)(self + 0xC);
            alpha = (u8)*(s16 *)(self + 0x3E);
            texIndex = *(u16 *)(self + 0x38);
            color4 = *Ui_GetColor(1);
            tex = *(u16 **)fn_8006EDD8((void *)lbl_803682E4, texIndex);
            w = tex[0];
            h = tex[1];
            Prim2D_Begin();
            Prim2D_BindTexture((void *)lbl_803682E4, texIndex, 0x21);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetPrimParam(lbl_8036B634);
            Prim2D_SetQuadMin(fx, fy, lbl_8036B634, lbl_8036B634);
            Prim2D_SetQuadMax(fx + lbl_8036B688, fy + lbl_8036B68C, (f32)h, (f32)w);
            Prim2D_SetColor(((u8 *)&color4)[0], ((u8 *)&color4)[1], ((u8 *)&color4)[2], alpha);
            Prim2D_EmitQuad();
            Prim2D_EndPrim();

            fx = (f32)*(s16 *)(self + 0xA);
            fy = (f32)*(s16 *)(self + 0xC);
            alpha = (u8)*(s16 *)(self + 0x3E);
            color5 = *Ui_GetColor(1);
            tex = *(u16 **)fn_8006EDD8((void *)lbl_803682E4, 5);
            w = tex[0];
            h = tex[1];
            Prim2D_Begin();
            Prim2D_BindTexture((void *)lbl_803682E4, 5, 0x21);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetPrimParam(lbl_8036B634);
            Prim2D_SetQuadMin(fx, fy, lbl_8036B634, lbl_8036B634);
            Prim2D_SetQuadMax(fx + lbl_8036B688, fy + lbl_8036B68C, (f32)h, (f32)w);
            Prim2D_SetColor(((u8 *)&color5)[0], ((u8 *)&color5)[1], ((u8 *)&color5)[2], alpha);
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
        }
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B664);
    Prim2D_PrepareTex();
    if (0xFF - *(s16 *)(self + 0x3C) != 0) {
        Prim2D_Begin();
        Prim2D_SetColorByte((u8)(0xFF - *(s16 *)(self + 0x3C)));
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B680);
        Prim2D_PrepareTex();
        if (*(s16 *)self & 0x10) {
            for (i = 0; i < 3; i++) {
                fx = (f32)*(s16 *)(self + 0xA);
                fy = (f32)*(s16 *)(self + 0xC);
                alpha = (u8)*(s16 *)(self + 0x3E);
                texIndex = *(u16 *)(self + 0x3A);
                color6 = *Ui_GetColor(1);
                tex = *(u16 **)fn_8006EDD8((void *)lbl_803682E4, texIndex);
                w = tex[0];
                h = tex[1];
                Prim2D_Begin();
                Prim2D_BindTexture((void *)lbl_803682E4, texIndex, 0x21);
                Prim2D_PrepareTex();
                Prim2D_AddPrim(1);
                Prim2D_SetPrimParam(lbl_8036B634);
                Prim2D_SetQuadMin(fx, fy, lbl_8036B634, lbl_8036B634);
                Prim2D_SetQuadMax(fx + lbl_8036B688, fy + lbl_8036B68C, (f32)h, (f32)w);
                Prim2D_SetColor(((u8 *)&color6)[0], ((u8 *)&color6)[1], ((u8 *)&color6)[2], alpha);
                Prim2D_EmitQuad();
                Prim2D_EndPrim();

                fx = (f32)*(s16 *)(self + 0xA);
                fy = (f32)*(s16 *)(self + 0xC);
                alpha = (u8)*(s16 *)(self + 0x3E);
                color7 = *Ui_GetColor(1);
                tex = *(u16 **)fn_8006EDD8((void *)lbl_803682E4, 5);
                w = tex[0];
                h = tex[1];
                Prim2D_Begin();
                Prim2D_BindTexture((void *)lbl_803682E4, 5, 0x21);
                Prim2D_PrepareTex();
                Prim2D_AddPrim(1);
                Prim2D_SetPrimParam(lbl_8036B634);
                Prim2D_SetQuadMin(fx, fy, lbl_8036B634, lbl_8036B634);
                Prim2D_SetQuadMax(fx + lbl_8036B688, fy + lbl_8036B68C, (f32)h, (f32)w);
                Prim2D_SetColor(((u8 *)&color7)[0], ((u8 *)&color7)[1], ((u8 *)&color7)[2], alpha);
                Prim2D_EmitQuad();
                Prim2D_EndPrim();
            }
        }
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B664);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();

    flags = *(s16 *)self;
    if (!(flags & 4) || !(flags & 2)) {
        return;
    }

    originX = *(s16 *)(self + 0xA) + 0x1AC;
    originY = *(s16 *)(self + 0xC) + 0x28;
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B648);
    Prim2D_PrepareTex();
    tex = *(u16 **)fn_8006EDD8((void *)lbl_803682E4, 6);
    tw = (f32)tex[0];
    th = (f32)tex[1];
    color8 = *Ui_GetColor(1);
    tex = *(u16 **)fn_8006EDD8((void *)lbl_803682E4, 6);
    w = tex[0];
    h = tex[1];
    Prim2D_Begin();
    Prim2D_BindTexture((void *)lbl_803682E4, 6, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetPrimParam(lbl_8036B634);
    Prim2D_SetQuadMin((f32)originX, (f32)originY, lbl_8036B634, lbl_8036B634);
    Prim2D_SetQuadMax((f32)originX + th, (f32)originY + tw, (f32)h, (f32)w);
    Prim2D_SetColor(((u8 *)&color8)[0], ((u8 *)&color8)[1], ((u8 *)&color8)[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B654);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    fn_8001003C((s16)(originX + 0xA), (s16)(originY + 0x1A), 2, 0, 0, gUiSeCues + 0x5C0, lbl_8036B630, lbl_8036B634, *(s32 *)(self + 0x40));
    fn_8001003C((s16)(originX + 0x22), (s16)(originY + 0x18), 2, 0, 0, gUiSeCues + 0x5C5, lbl_8036B630, lbl_8036B634);
    fn_8001003C((s16)(originX + 0x2A), (s16)(originY + 0x1A), 2, 0, 0, gUiSeCues + 0x5C0, lbl_8036B630, lbl_8036B634, *(s32 *)(self + 0x44));
    fn_8001003C((s16)(originX + 0x42), (s16)(originY + 0x18), 2, 0, 0, gUiSeCues + 0x5C5, lbl_8036B630, lbl_8036B634);
    fn_8001003C((s16)(originX + 0x4A), (s16)(originY + 0x1A), 2, 0, 0, gUiSeCues + 0x5C0, lbl_8036B630, lbl_8036B634, *(s32 *)(self + 0x48));
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B690);
    Prim2D_PrepareTex();
}

static s32 fn_801DB5B4(s32 arg0, s32 arg1) {
    u16* unit = (u16*)arg0;
    s32 r0, r3, r4, r5;
    
    switch (unit[1]) {
        case 0x64: // 100
            unit[0] = (u16)(unit[0] | 0x1);
            unit[1] = (s16)0x6E;
            r4 = unit[2];
            r0 = unit[4];
            r4 = (s16)(r4 + 1);
            r0 = r0 << 6;
            r0 += 0x5E;
            unit[6] = (s16)r0;
            unit[7] = (s16)0x2E;
            
            if (unit[2] >= unit[3]) {
                return 0;
            }
            unit[1] = (s16)0x6E;
            break;

        case 0xCD: // 205
            unit[0] = (u16)(unit[0] | 0x1);
            unit[1] = (s16)0xD2;
            r4 = unit[4];
            r0 = unit[6]; 
            r4 = (s16)(r4 + 1);
            r0 = r0 << 6;
            r0 += 0x5E;
            unit[6] = (s16)r0;
            unit[7] = (s16)0x2E;
            
            if (unit[4] >= unit[3]) {
                return 0;
            }
            unit[1] = (s16)0xD2;
            break;

        case 0x69: // 105
            unit[0] = (u16)(unit[0] | 0x1);
            unit[1] = (s16)0x69;
            unit[0x1E] = (s16)0xFF;
            r4 = unit[4];
            r0 = unit[6];
            r4 = (s16)(r4 + 1);
            r0 = r0 << 6;
            r0 += 0x5E;
            unit[6] = (s16)r0;
            
            if (unit[4] >= unit[3]) {
                return 0;
            }
            unit[1] = (s16)0x6E;
            break;

        case 0xC8: // 200
            unit[0] = (u16)(unit[0] | 0x1);
            unit[1] = (s16)0xCD;
            unit[0x1E] = (s16)0xFF;
            r0 = unit[4];
            r0 = r0 << 6;
            r0 += 0x5E;
            unit[6] = (s16)r0;
            unit[7] = (s16)0x2E;
            
            if (unit[4] >= unit[3]) {
                return 0;
            }
            unit[1] = (s16)0xD2;
            break;

        case 0x0: // 0
        case 0x6E:
        case 0xD2:
        case 0x12C:
            unit[0] = (u16)(unit[0] | 0x1);
            unit[1] = (s16)0x00;
            unit[0x1E] = (s16)0xFF;
            
            if (unit[4] < unit[3]) {
                return 0;
            }
            unit[1] = (s16)0xD2;
            break;

        case 0x131: // 305
            unit[0] = (u16)(unit[0] | 0x1);
            unit[1] = (s16)0x46;
            unit[5] = (s16)0xFF;
            unit[6] = (s16)0x3E8;
            
            r4 = unit[1];
            r0 = unit[2];
            r5 = unit[3];
            
            // Absolute value calculation: ((r5 ^ (r5 >> 31)) - (r5 >> 31))
            r5 = (r5 >> 31); 
            r5 = ((r5 ^ r5) - r5);
            r5 >>= 1;
            
            if (r4 < r5) {
                // Branch A
                r0 = unit[1];
                if (r0 & 0x4000) {
                    unit[0] = (u16)(unit[0] | 0x20);
                } else {
                    unit[0] = (u16)(unit[0] & ~0x20);
                }
            } else if (r4 == r5) {
                // Branch B
                r0 = unit[1];
                if (r0 & 0x2000) {
                    unit[0] = (u16)(unit[0] | 0x40);
                } else {
                    unit[0] = (u16)(unit[0] & ~0x40);
                }
            } else {
                // Branch C
                r0 = -r5 + r4;
                if (r0 & 0x8000) {
                    unit[0] = (u16)(unit[0] | 0x20);
                } else {
                    unit[0] = (u16)(unit[0] & ~0x20);
                }
            }
            break;

        default:
            return 0;
    }

    return 0;
}

void fn_801DBD84(void *arg0) {
u8 *state=*(u8**)((u8*)arg0+0x30);
s32 i;
*(u32*)(state)=0;
*(u32*)(state+4)=0;
state[0x11]=0; state[0x15]=0;
*(s16*)(state+0x16)=-1;
state[0x1A]=0; state[0x5C]=0;
*(s16*)(state+0x5E)=0;
memset(state+0x60,0,0x1C);
*(s16*)(state+0x62)=0;
*(s16*)(state+0x60)=0;
for(i=0;i<6;i++) {
memset(state+0x7C+i*0x34,0,0x34);
*(s16*)(state+0x7E+i*0x34)=0;
*(s16*)(state+0x7C+i*0x34)=0;
}
for(i=0;i<5;i++) {
memset(state+0x1B4+i*0x4C,0,0x4C);
*(s16*)(state+0x1B6+i*0x4C)=0;
*(s16*)(state+0x1B4+i*0x4C)=0;
}
memset(state+0x330,0,0x1EA);
*(s16*)(state+0x332)=0;
*(s16*)(state+0x330)=0;
*(s16*)(state+0x34E)=0;
for(i=0;i<2;i++) {
memset(state+0x51A+i*0x14,0,0x14);
*(s16*)(state+0x51C+i*0x14)=0;
*(s16*)(state+0x51A+i*0x14)=0;
}
}

void fn_801DBEA8(void *arg0, s32 type) {
    u8 *self = arg0;
    *(s16 *)(self + 126) = 0;
    *(s16 *)(self + 124) = 0;
    *(s16 *)(self + 178) = 0;
    *(s16 *)(self + 176) = 0;
    *(s16 *)(self + 230) = 0;
    *(s16 *)(self + 228) = 0;
    *(s16 *)(self + 282) = 0;
    *(s16 *)(self + 280) = 0;
    *(s16 *)(self + 334) = 0;
    *(s16 *)(self + 332) = 0;
    *(s16 *)(self + 386) = 0;
    *(s16 *)(self + 384) = 0;
    FileMenu_InitEntry(self + 0x7C, (s8)self[0x15], type);
    *(s16 *)(self + 0x7E) = 0x12C;
    *(s16 *)(self + 0x7C) |= 2;
    self[0x15] = 1;
}

s32 fn_801DBFF8(void)
{
  void *fn_801E2324(void *, s32);
  extern s32 lbl_803682F0;
  s32 i;
  s32 count;
  void *obj;
  count = 0;
  for (i = 0; i < 5; i++)
  {
    obj = fn_801E2324(&lbl_803682F0, i);
    if (obj != NULL)
    {
      if ((*(((u8 *) obj) + 0x60)) == 2)
      {
        obj = NULL;
      }
      else
      {
      }
    }
    else
    {
      obj = NULL;
    }
    if (obj != NULL)
    {
      count += 1;
    }
  }

  return count;
}

static inline u8 *fn_801DC070_GetType2(void *id) {
    extern u8 gSaveDataBase;
    void *fn_801E2324(void *, void *);
    u8 *r = (u8 *)fn_801E2324(&gSaveDataBase, id);
    if (r != NULL && r[0x60] == 2) return r;
    return NULL;
}

void *fn_801DC070(void *arg0)
{
    u8 *result;

    result = fn_801DC070_GetType2(arg0);
    if (result != NULL && result[0x64] != 0x20) {
        result = NULL;
    }
    return result;
}

void *fn_801DC0CC(void) {
    void *fn_801E09B4(M2C_UNK *);
    extern M2C_UNK gSaveDataBase;
    void *temp_r3;

    temp_r3 = fn_801E09B4(&gSaveDataBase);
    if ((temp_r3 != NULL) && ((u8) M2C_FIELD(temp_r3, u8 *, 0x60) == 3)) {
        return temp_r3;
    }
    return NULL;
}

void *fn_801DC10C(void *arg0)
{
    extern u8 gSaveDataBase;
    extern void *fn_801E2324(void *, void *);

    u8 *result;

    result = (u8 *)fn_801E2324(&gSaveDataBase, arg0);

    if (result != 0 && result[0x60] == 2) {
        return result;
    }

    return 0;
}

void Ui_OpenConfirmDialog(s32 arg0, s8 arg1, s8 arg2, s32 arg3, s32 arg4, s8 arg5, void *arg6) {
    void *Process_CreateChild(void *, void *);
    extern u8 lbl_80299C88[];
    void *temp_r3;

    temp_r3 = Process_CreateChild(lbl_80299C88, arg6);
    *(void **)((u8 *)temp_r3 + 0x30) = *(void **)((u8 *)arg6 + 0x30);
    *(s32 *)((u8 *)temp_r3 + 0x34) = arg0;
    *(s8 *)((u8 *)temp_r3 + 0x3C) = arg1;
    *(s32 *)((u8 *)temp_r3 + 0x40) = arg3;
    *(s32 *)((u8 *)temp_r3 + 0x38) = arg4;
    *(s8 *)((u8 *)(*(void **)((u8 *)temp_r3 + 0x30)) + 0x14) = arg2;
    *(s8 *)((u8 *)temp_r3 + 0x44) = arg5;
}

#pragma global_optimizer off
void fn_801DC1C8(u8 *arg0) {
    u8 *base;
    s32 off;

    base = *(u8 **)(arg0 + 0x30);
    *(s16 *)(base + 0x332) = 0xC8;
    off = *(s32 *)(arg0 + 0x40) * 0x14 + 0x51A;
    *(s16 *)(base + off) = (s16)(*(s16 *)(base + off) & ~1);
}
#pragma global_optimizer on
/* Handle A/B confirm/cancel and left/right option select for a yes-no dialog. */
void Ui_HandleConfirmDialogInput(void *arg0) {
    void Process_ClearFunc(void *);
    void Ui_PlaySeCue(void *, s32);
    extern void *gPadInput;
    extern u8 gUiSeCues[];
    void *self;
    s32 pressed;
    void *state;
    s32 bonus;
    s32 buttons;
    s32 prev;
    s32 mask;
    s32 yPos;
    void *entry;
    s16 xPos;
    s16 flags;
    s16 srcX;
    s16 srcY;

    self = arg0;
    buttons = ((s32 *)gPadInput)[1];
    prev = ((s32 *)gPadInput)[2];
    state = *(void **)((u8 *)self + 0x30);
    pressed = buttons & (prev ^ buttons);

    if (*((u8 *)self + 0x3C) != 1) {
        goto not_mode1;
    }

    
    mask = *(s16 *)((u8 *)state + 0x330);
    mask = (mask >> 2) & 1;
    bonus = mask == 1 ? 0x28 : 0;

    if ((pressed & 0x100) == 0) {
        goto after_a;
    }
    if ((s8)*((u8 *)state + 0x14) == 0) {
        Ui_PlaySeCue(*(void **)((u8 *)self + 0x38), 0x64);
    } else {
        Ui_PlaySeCue(gUiSeCues + 0x2E4, 0x64);
    }
    Process_ClearFunc(self);
after_a:
    if ((pressed & 0x200) == 0) {
        goto after_b;
    }
    Ui_PlaySeCue(gUiSeCues + 0x2E4, 0x64);
    *((u8 *)state + 0x14) = 1;
    Process_ClearFunc(self);
after_b:
    if ((pressed & 0x01000001) == 0) {
        goto after_left;
    }
    if ((s32)*((u8 *)state + 0x14) == 1) {
        Ui_PlaySeCue(gUiSeCues + 0x328, 0x64);
    }
    {
        s32 zero;
        s32 val_c8;
        s32 four;
        zero = 0;
        val_c8 = 0xC8;
        *((u8 *)state + 0x14) = zero;
        four = 4;
        yPos = *(s16 *)((u8 *)state + 0x340) + bonus;
        xPos = *(s16 *)((u8 *)state + 0x33E);
        entry = (u8 *)state + (*(s32 *)((u8 *)self + 0x40) * 0x14) + 0x51A;
        flags = *(s16 *)entry;
        srcY = *(s16 *)((u8 *)entry + 0xA);
        srcX = *(s16 *)((u8 *)entry + 8);
        *(s16 *)entry = flags | 1;
        *(s16 *)entry = *(s16 *)entry & ~2;
        *(s16 *)entry = *(s16 *)entry & ~4;
        *(s16 *)((u8 *)entry + 2) = val_c8;
        *(s16 *)((u8 *)entry + 0xC) = srcX;
        *(s16 *)((u8 *)entry + 0xE) = srcY;
        *(s16 *)((u8 *)entry + 0x10) = xPos;
        *(s16 *)((u8 *)entry + 0x12) = yPos;
        *(s16 *)((u8 *)entry + 4) = zero;
        *(s16 *)((u8 *)entry + 6) = four;
    }
after_left:
    if ((pressed & 0x02000002) == 0) {
        goto done;
    }
    if ((s8)*((u8 *)state + 0x14) == 0) {
        Ui_PlaySeCue(gUiSeCues + 0x328, 0x64);
    }
    {
        s32 yPos;
        void *entry;
        s16 xPos;
        s16 flags;
        s16 srcX;
        s16 srcY;
        s32 one;
        s32 val_c8;
        s32 zero;
        s32 four;
        one = 1;
        val_c8 = 0xC8;
        *((u8 *)state + 0x14) = one;
        zero = 0;
        four = 4;
        yPos = *(s16 *)((u8 *)state + 0x344) + bonus;
        xPos = *(s16 *)((u8 *)state + 0x342);
        entry = (u8 *)state + (*(s32 *)((u8 *)self + 0x40) * 0x14) + 0x51A;
        flags = *(s16 *)entry;
        srcY = *(s16 *)((u8 *)entry + 0xA);
        srcX = *(s16 *)((u8 *)entry + 8);
        *(s16 *)entry = flags | 1;
        *(s16 *)entry = *(s16 *)entry & ~2;
        *(s16 *)entry = *(s16 *)entry & ~4;
        *(s16 *)((u8 *)entry + 2) = val_c8;
        *(s16 *)((u8 *)entry + 0xC) = srcX;
        *(s16 *)((u8 *)entry + 0xE) = srcY;
        *(s16 *)((u8 *)entry + 0x10) = xPos;
        *(s16 *)((u8 *)entry + 0x12) = yPos;
        *(s16 *)((u8 *)entry + 4) = zero;
        *(s16 *)((u8 *)entry + 6) = four;
    }
    goto done;

not_mode1:
    if (pressed & 0x100) {
        Ui_PlaySeCue(gUiSeCues + 0x2D4, 0x64);
        Process_ClearFunc(self);
    }
done:
    ;
}

void fn_801DC454(void *arg0) {
void MsgBox_Init(void *,void *,u8,u8,s16);
u8 *state=M2C_FIELD(arg0,u8 **,0x30);
u8 *box=state+0x330;
s32 bit, pad;
s16 *entry;
s16 x,y;
MsgBox_Init(box,M2C_FIELD(arg0,void **,0x34),M2C_FIELD(arg0,u8 *,0x3C),M2C_FIELD(arg0,u8 *,0x44),0);
if(M2C_FIELD(arg0,u8 *,0x3C)==1) {
bit=((u32)M2C_FIELD(box,s16 *,0)>>2)&1;
pad=40&(~((bit-1)|(1-bit))>>31);
if(M2C_FIELD(state,s8 *,0x14)==0) {
x=M2C_FIELD(box,s16 *,0xE); y=M2C_FIELD(box,s16 *,0x10)+pad;
entry=(s16 *)(state+M2C_FIELD(arg0,s32 *,0x40)*20+0x51A);
entry[0]|=1; entry[0]&=~2; entry[0]&=~4; entry[1]=100; entry[4]=x; entry[5]=y;
} else {
x=M2C_FIELD(box,s16 *,0x12); y=M2C_FIELD(box,s16 *,0x14)+pad;
entry=(s16 *)(state+M2C_FIELD(arg0,s32 *,0x40)*20+0x51A);
entry[0]|=1; entry[0]&=~2; entry[0]&=~4; entry[1]=100; entry[4]=x; entry[5]=y;
}
}
}

void MsgBox_Layout(MsgBox *arg0) {
    u8 *Msg_Expand(u8 *);
    s32 Text_MeasureWidth(void *, s32, f32);
    extern u8 gUiSeCues[];
    extern f32 lbl_8036B630;
    extern f32 lbl_8036B650;
    extern f32 lbl_8036B664;
    extern f32 lbl_8036B668;
    extern f32 lbl_8036B698;
    extern f32 lbl_8036B69C;

    f32 width0;
    f32 width1;
    f32 width2;
    f32 gap;
    s32 lastWidth;
    s32 width;
    s32 centeredY;

    switch (arg0->type) {
    case 0:
        width0 = (f32)Text_MeasureWidth(Msg_Expand(gUiSeCues + 0x5C7), -1, lbl_8036B630);
        lastWidth = Text_MeasureWidth(Msg_Expand(gUiSeCues + 0x5CE), -1, lbl_8036B630);
        width = arg0->width;
        M2C_FIELD(arg0, s16 *, 6) = (0x260 - width) / 2;
        centeredY = 0x1E0 - arg0->height;
        gap = (((f32)width - width0) - (f32)lastWidth) / lbl_8036B698;
        M2C_FIELD(arg0, s16 *, 8) = centeredY / 2;
        M2C_FIELD(arg0, s16 *, 0xE) = (s16)((f32)M2C_FIELD(arg0, s16 *, 6) + gap);
        M2C_FIELD(arg0, s16 *, 0x10) = M2C_FIELD(arg0, s16 *, 8) + arg0->numLines * 0x14 + 0x12;
        M2C_FIELD(arg0, s16 *, 0x12) = (s16)(lbl_8036B664 * gap + ((f32)M2C_FIELD(arg0, s16 *, 6) + width0));
        M2C_FIELD(arg0, s16 *, 0x14) = M2C_FIELD(arg0, s16 *, 8) + arg0->numLines * 0x14 + 0x12;
        return;

    case 1:
        width0 = (f32)Text_MeasureWidth(Msg_Expand(gUiSeCues + 0x5D4), -1, lbl_8036B630);
        width1 = (f32)Text_MeasureWidth(Msg_Expand(gUiSeCues + 0x5DE), -1, lbl_8036B630);
        lastWidth = Text_MeasureWidth(Msg_Expand(gUiSeCues + 0x5E6), -1, lbl_8036B630);
        width = arg0->width;
        M2C_FIELD(arg0, s16 *, 6) = (0x260 - width) / 2;
        M2C_FIELD(arg0, s16 *, 8) = (0x1E0 - arg0->height) / 2;
        gap = ((((f32)width - width0) - width1) - (f32)lastWidth) * lbl_8036B69C;
        M2C_FIELD(arg0, s16 *, 0xE) = (s16)((f32)M2C_FIELD(arg0, s16 *, 6) + gap);
        M2C_FIELD(arg0, s16 *, 0x10) = M2C_FIELD(arg0, s16 *, 8) + arg0->numLines * 0x14 + 0x12;
        M2C_FIELD(arg0, s16 *, 0x12) = (s16)(lbl_8036B664 * gap + ((f32)M2C_FIELD(arg0, s16 *, 6) + width0));
        M2C_FIELD(arg0, s16 *, 0x14) = M2C_FIELD(arg0, s16 *, 8) + arg0->numLines * 0x14 + 0x12;
        M2C_FIELD(arg0, s16 *, 0x16) = (s16)(lbl_8036B698 * gap + (width1 + ((f32)M2C_FIELD(arg0, s16 *, 6) + width0)));
        M2C_FIELD(arg0, s16 *, 0x18) = M2C_FIELD(arg0, s16 *, 8) + arg0->numLines * 0x14 + 0x12;
        return;

    case 2:
        width0 = (f32)Text_MeasureWidth(Msg_Expand(gUiSeCues + 0x5F0), -1, lbl_8036B630);
        lastWidth = Text_MeasureWidth(Msg_Expand(gUiSeCues + 0x5F7), -1, lbl_8036B630);
        width = arg0->width;
        M2C_FIELD(arg0, s16 *, 6) = (0x260 - width) / 2;
        centeredY = 0x1E0 - arg0->height;
        gap = (((f32)width - width0) - (f32)lastWidth) / lbl_8036B698;
        M2C_FIELD(arg0, s16 *, 8) = centeredY / 2;
        M2C_FIELD(arg0, s16 *, 0xE) = (s16)((f32)M2C_FIELD(arg0, s16 *, 6) + gap);
        M2C_FIELD(arg0, s16 *, 0x10) = M2C_FIELD(arg0, s16 *, 8) + arg0->numLines * 0x14 + 0x12;
        M2C_FIELD(arg0, s16 *, 0x12) = (s16)(lbl_8036B664 * gap + ((f32)M2C_FIELD(arg0, s16 *, 6) + width0));
        M2C_FIELD(arg0, s16 *, 0x14) = M2C_FIELD(arg0, s16 *, 8) + arg0->numLines * 0x14 + 0x12;
        return;

    case 3:
        width0 = (f32)Text_MeasureWidth(Msg_Expand(gUiSeCues + 0x600), -1, lbl_8036B630);
        width1 = (f32)Text_MeasureWidth(Msg_Expand(gUiSeCues + 0x609), -1, lbl_8036B630);
        width2 = (f32)Text_MeasureWidth(Msg_Expand(gUiSeCues + 0x612), -1, lbl_8036B630);
        lastWidth = Text_MeasureWidth(Msg_Expand(gUiSeCues + 0x61C), -1, lbl_8036B630);
        width = arg0->width;
        M2C_FIELD(arg0, s16 *, 6) = (0x260 - width) / 2;
        M2C_FIELD(arg0, s16 *, 8) = (0x1E0 - arg0->height) / 2;
        gap = (((((f32)width - width0) - width1) - width2) - (f32)lastWidth) / lbl_8036B650;
        M2C_FIELD(arg0, s16 *, 0xE) = (s16)((f32)M2C_FIELD(arg0, s16 *, 6) + gap);
        M2C_FIELD(arg0, s16 *, 0x10) = M2C_FIELD(arg0, s16 *, 8) + arg0->numLines * 0x14 + 0x12;
        M2C_FIELD(arg0, s16 *, 0x12) = (s16)(lbl_8036B664 * gap + ((f32)M2C_FIELD(arg0, s16 *, 6) + width0));
        M2C_FIELD(arg0, s16 *, 0x14) = M2C_FIELD(arg0, s16 *, 8) + arg0->numLines * 0x14 + 0x12;
        M2C_FIELD(arg0, s16 *, 0x16) = (s16)(lbl_8036B698 * gap + (width1 + ((f32)M2C_FIELD(arg0, s16 *, 6) + width0)));
        M2C_FIELD(arg0, s16 *, 0x18) = M2C_FIELD(arg0, s16 *, 8) + arg0->numLines * 0x14 + 0x12;
        M2C_FIELD(arg0, s16 *, 0x1A) = (s16)(lbl_8036B668 * gap + ((width1 + ((f32)M2C_FIELD(arg0, s16 *, 6) + width0)) + width2));
        M2C_FIELD(arg0, s16 *, 0x1C) = M2C_FIELD(arg0, s16 *, 8) + arg0->numLines * 0x14 + 0x12;
        return;
    }
}

void fn_801DCD3C(u8 *arg0)
{
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Prim2D_AddZ(f32);
    void fn_8007CFD8(s32 *, f32, f32, f32, f32);
    void fn_8015A2D8(s16, s16, s16, s16, s32, s32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_EndPrim(void);
    void *fn_8006EDD8(s32, s32);
    void Prim2D_BindTexture(s32, s32, s32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    s32 Text_MeasureWidth(void *, s32, f32);
    void fn_8001003C(s16, s16, u8, s32, s32, void *, f32, f32);
    u8 *Msg_Expand(void *);
    extern f32 lbl_8036B630, lbl_8036B634, lbl_8036B63C, lbl_8036B650;
    extern f32 lbl_8036B654, lbl_8036B658, lbl_8036B664;
    extern f32 lbl_8036B6A0, lbl_8036B6A4, lbl_8036B6A8, lbl_8036B6AC, lbl_8036B6B0;
    extern s32 lbl_8036B620, lbl_8036B624;
    extern s32 gUiAtlas;
    extern u8 gUiSeCues[];

    f32 f30;
    s16 x, y;
    s32 color;
    s16 mode;

    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B634, lbl_8036B634, lbl_8036B63C, lbl_8036B630);
    Prim2D_PrepareTex();
    if (*(s16 *)arg0 & 1) {
        f30 = Math_Ease(0, lbl_8036B634, lbl_8036B630, (f32)*(s16 *)(arg0 + 0x1E), lbl_8036B650);
        Prim2D_Begin();
        Prim2D_SetTransform(lbl_8036B6A0, lbl_8036B6A4, lbl_8036B63C, f30);
        Prim2D_PrepareTex();
        x = (s16)(lbl_8036B658 * (f32)(-(s16)*(s16 *)(arg0 + 0xA)));
        y = (s16)(lbl_8036B658 * (f32)(-(s16)*(s16 *)(arg0 + 0xC)));
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B6A8);
        Prim2D_PrepareTex();
        mode = *(s16 *)(arg0 + 4);
        if (mode == 0) {
            if (*(s16 *)arg0 & 4) {
                color = lbl_8036B620;
            } else {
                color = lbl_8036B624;
            }
            fn_8007CFD8(&color, (f32)x, (f32)y, (f32)*(s16 *)(arg0 + 0xA), (f32)*(s16 *)(arg0 + 0xC));
        } else {
            fn_8015A2D8(x, y, *(s16 *)(arg0 + 0xA), *(s16 *)(arg0 + 0xC), 0xFF, 0x10);
            if (mode == 1 || mode == 2) {
                s16 x0 = (s16)(x + 0x18);
                s16 y0 = (s16)(y + 0x4C);
                s16 w = (s16)(*(s16 *)(arg0 + 0xA) - 0x30);
                s16 h = (s16)(*(s16 *)(arg0 + 0xC) - 0x60);
                Prim2D_Begin();
                Prim2D_AddZ(lbl_8036B654);
                Prim2D_PrepareTex();
                Prim2D_Begin();
                Prim2D_SetTex(0, 0x12);
                Prim2D_PrepareTex();
                Prim2D_AddPrim(4);
                Prim2D_SetRect((f32)x0, (f32)y0, (f32)w, lbl_8036B634);
                Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0x4D);
                Prim2D_EndPrim();
                Prim2D_AddPrim(4);
                Prim2D_SetRect((f32)x0, (f32)(y0 + h), (f32)w, lbl_8036B634);
                Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0x4D);
                Prim2D_EndPrim();
                Prim2D_AddPrim(4);
                Prim2D_SetRect((f32)x0, (f32)y0, lbl_8036B634, (f32)h);
                Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0x4D);
                Prim2D_EndPrim();
                Prim2D_AddPrim(4);
                Prim2D_SetRect((f32)(x0 + w), (f32)y0, lbl_8036B634, (f32)h);
                Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0x4D);
                Prim2D_EndPrim();
                Prim2D_Begin();
                Prim2D_AddZ(lbl_8036B654);
                Prim2D_PrepareTex();
                Prim2D_AddPrim(1);
                Prim2D_SetRect((f32)(x0 + 1), (f32)(y0 + 1), (f32)(w - 2), (f32)(h - 2));
                Prim2D_SetColor(0, 0, 0, 0x4D);
                Prim2D_EndPrim();
                Prim2D_Begin();
                Prim2D_AddZ(lbl_8036B664);
                Prim2D_PrepareTex();
            }
        }
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B6AC);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_SetTransform(lbl_8036B634, lbl_8036B634, lbl_8036B63C, lbl_8036B630);
        Prim2D_PrepareTex();
    }
}

/* Advance MsgBox open/close fade (timer 0..5) and relayout. */
void MsgBox_Update(MsgBox *box) {
    void MsgBox_Layout(void);
    s16 state;
    s16 *timer;

    state = box->state;
    switch (state) {                              /* irregular */
    case 0x0:
        box->flags = 0;
        break;
    case 0x64:
        box->flags = box->flags | 1;
        box->state = 0x6E;
        /* fallthrough */
    case 0x6E:
        timer = &box->timer;
        *timer = *timer + 1;
        if (*timer >= 5) {
            *timer = 5;
        }
        break;
    case 0xC8:
        box->flags = box->flags | 1;
        box->state = 0xD2;
        /* fallthrough */
    case 0xD2:
        timer = &box->timer;
        *timer = *timer - 1;
        if (*timer < 1) {
            *timer = 0;
            box->state = 0;
            box->flags = 0;
        }
        break;
    }
    MsgBox_Layout();
}

extern void *lbl_801D3B14;
#pragma opt_propagation off
void MsgBox_Init(MsgBox *w, s32 msgId, u8 withTitle, u8 withButtons, s16 type) {
    /* Clear a MsgBox, expand msgId into lines, size the box, then layout it. */
    void *memset(void *, s32, u32);
    void *memcpy(void *, const void *, u32);
    char *Msg_Expand(s32);
    s32 Text_MeasureWidth(char *, s32, f32);
    void MsgBox_Layout(MsgBox *);
    s32 n;
    char *s;
    char *start;
    s32 len;
    f32 width;
    s32 h;
    s32 t;
    s32 pad;
    s32 x;
    u16 *tex;
    void *str;
    void *obj;
    s32 id;
    s32 width2;

    memset(w, 0, sizeof(MsgBox));
    w->state = 0;
    w->flags = 0;
    w->timer = 0;
    w->state = 100;
    w->type = type;
    if (withButtons) {
        w->flags |= 4;
    } else {
        w->flags &= ~4;
    }
    w->width = 200;
    if (w->type == 1 || w->type == 2 || w->type == 3) {
        w->width = 400;
    }
    s = Msg_Expand(msgId);
    n = len = 0;
    start = s;
    for (;;) {
        if (*s == 0 || *s == '\n') {
            if (len > 0) {
                memcpy(w->lines[n], start, len);
            }
            w->lines[n][len] = 0;
            width = Text_MeasureWidth(w->lines[n], -1, 1.0f);
            if (width > w->width) {
                w->width = width;
            }
            n++;
            if (*s == 0) {
                break;
            }
            s++;
            len = 0;
            start = s;
        } else {
            s++;
            len++;
        }
    }
    w->numLines = n;
    w->width += 0x18;
    t = withTitle ? 20 : 0;
    h = w->numLines * 20;
    h = h + t;
    pad = (w->flags & 4) ? 40 : 0;
    x = h + pad;
    w->height = x + 32;
    if (w->type == 1 || w->type == 2) {
        w->height += 0x88;
    }
    if (w->type == 3) {
        w->height += 10;
    }
    if (withTitle) {
        w->flags |= 2;
    }
    MsgBox_Layout(w);
}
#pragma opt_propagation reset
void fn_801DDDE8(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *lbl, s32 arg);
    extern u8 lbl_80299C74[];
    extern f32 lbl_8036B634;
    extern f64 lbl_8036B670;
    void *temp_r3;

    temp_r3 = Process_CreateChild(lbl_80299C74, arg1);
    *(f32 *)((u8 *)temp_r3 + 0x30) = lbl_8036B634;
    *(f32 *)((u8 *)temp_r3 + 0x34) = (f32)arg0;
}

#pragma scheduling on
void fn_801DDE44(void *arg0) {
    extern f32 lbl_8036B630;
    void Process_ClearFunc(void);
    f32 d = lbl_8036B630;
    f32 *p = (f32 *)((u8 *)arg0 + 0x30);

    *p += d;
    if (*p >= *(f32 *)((u8 *)arg0 + 0x34)) {
        Process_ClearFunc();
    }
}
#pragma global_optimizer off
void fn_801DDE88(register s32 px, register s32 py, s32 id) {
void Prim2D_SetQuadMax(f32,f32,f32,f32);void Prim2D_SetQuadMin(f32,f32,f32,f32);
void Prim2D_EndPrim(void);void Prim2D_AddPrim(s32);void Prim2D_BindTexture(void*,s32,s32);void Prim2D_PrepareTex(void);void Prim2D_Begin(void);u16 **fn_8006EDD8(void*,s32);
extern u8 lbl_80299A78[];extern f32 lbl_8036B634;
u8 *record;
void *texture;
u16 w,h;
u16 *image;

record=MenuResource_FindIn(lbl_80299A78,id);
if(record) texture=*(void**)(record+8);else texture=0;
if(texture) {
image=*fn_8006EDD8(texture,0);
w=image[1];h=image[0];
Prim2D_Begin();Prim2D_BindTexture(texture,0,0x11);Prim2D_PrepareTex();Prim2D_AddPrim(1);
px=(s16)px;py=(s16)py;
Prim2D_SetQuadMin((f32)px,(f32)py,lbl_8036B634,lbl_8036B634);
Prim2D_SetQuadMax((f32)(px+(s32)w),(f32)(py+(s32)h),(f32)(u32)w,(f32)(u32)h);
Prim2D_EndPrim();
}
}
#pragma global_optimizer reset
void fn_801DE074(void) {
    void Process_UnlinkByKey(void *);
    void FileCache_ReleaseSlot(void *);
    extern u8 lbl_80299C58[];
    extern u8 lbl_80299A78[];
    s32 i;
    Process_UnlinkByKey(lbl_80299C58);
    i = 0;
    do {
        if (*(u32 *)(lbl_80299A78 + i * 0xC + 8) != 0) {
            FileCache_ReleaseSlot(lbl_80299A78 + i * 0xC + 8);
        }
        *(u32 *)(lbl_80299A78 + i * 0xC + 8) = 0;
        i++;
    } while (i < 0x28);
}

#pragma cplusplus on
#pragma global_optimizer off
#pragma opt_loop_invariants off
extern "C" void fn_801DE0EC(s32 *list, s32 parent) {
void Process_UnlinkByKey(void*); void Process_CreateChild(void*,s32); void FileCache_ReleaseSlot(void*); void fn_8005C8B4(void*); int sprintf(char*,const char*,...);
extern u8 lbl_80299C58[],lbl_80299A78[],gUiSeCues[];
char path[64];
s32 *cursor=list;
s32 owner=parent;
s32 clear;
s32 i;
u8 *p;
u8 *base;
s32 id;
Process_UnlinkByKey(lbl_80299C58);
base=lbl_80299A78;
i=0;
clear=i;
p=base;
do {
if(*(u32*)(p+8)) FileCache_ReleaseSlot(p+8);
i++;
*(u32*)(p+8)=clear;
p+=12;
} while(i<40);
for(;(id=*cursor)!=-1;cursor++) {
p=MenuResource_FindIn(base,id);
if(p) {sprintf(path,(char*)gUiSeCues+0x661,*(s32*)(p+4));fn_8005C8B4(path);}
}
Process_CreateChild(lbl_80299C58,owner);
}
#pragma opt_loop_invariants reset
#pragma global_optimizer reset
#pragma cplusplus reset
void fn_801DE274(void) {
    s32 sprintf(char *, char *, ...);
    s32 FileCache_GetFlags(char *);
    void fn_8006EEFC(void *, void *);
    extern char gUiSeCues[];
    extern u8 lbl_80299A78[];
    char buf[0x40];
    char *cues;
    u8 *p;
    s32 i;

    p = lbl_80299A78;
    cues = gUiSeCues;
    i = 0;
    do {
        sprintf(buf, cues + 0x661, *(s32 *)(p + 4));
        if (FileCache_GetFlags(buf) & 0x2000) {
            fn_8006EEFC(p + 8, buf);
        }
        i += 1;
        p += 0xC;
    } while (i < 0x28);
}
#pragma opt_loop_invariants reset

#pragma use_lmw_stmw reset
void fn_801DE2FC(s32 arg0) {
    u8 fn_8005BB2C();
    if (fn_8005BB2C() != 0) {
        Process_ClearFunc(arg0);
    }
}

void fn_801DE338(void *arg0) {
 s32 *p = arg0;
 s32 invalid = -1;
 u8 active = (u8)-invalid;
 p[0] = invalid;
 p[1] = invalid;
 *((u8 *)arg0 + 0x44) = active;
}

u8 fn_801DE350(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x63);
}

u8 fn_801DE358(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x47);
}

s32 fn_801DE360(void) {
    return 1;
}

u8 fn_801DE368(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x64);
}

s32 fn_801DE370(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xC);
}

void fn_801DE378(void *arg0)
{
  memset(arg0, 0, 0x1EA);
  *((s16 *) arg0) = (*(((s16 *) arg0) + 1) = 0);
  *(((s16 *) arg0) + 0xF) = 0;
}

void fn_801DE3BC(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x1E8) = arg1;
}

void fn_801DE3C4(void *arg0) {
    M2C_FIELD(arg0, s16 *, 2) = 0xC8;
}

u8 fn_801DE3D0(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x10);
}

#pragma optimization_level 3
void fn_801DE3D8(void *arg0) {
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern f32 lbl_8036B6B8, lbl_8036B6BC;
    u8 gate;
    u32 flags;
    void *pad;
    f32 tmp;

    gate = 0;
    flags = gUiInputFlags;
    if ((flags & 0x10) && !(flags & 0x20)) {
        gate = 1;
    }
    if (!gate) {
        tmp = *(f32 *)((char *)arg0 + 0x44);
        pad = gPadInput;
        flags = *(u32 *)((u8 *)pad + 0xc);
        if ((s16)tmp == 0) {
            if ((flags & 0x04000004) && *(u8 *)((char *)arg0 + 0x84)) {
                *(f32 *)((char *)arg0 + 0x44) = lbl_8036B6B8;
            } else if ((flags & 0x08000008) && *(u8 *)((char *)arg0 + 0x5C)) {
                *(f32 *)((char *)arg0 + 0x44) = lbl_8036B6BC;
            }
        }
    }
}
#pragma optimization_level reset
void fn_801DE474(void *arg0, void *arg1)
{
    void fn_8013F748(void *, s16 *, s16 *);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddZ(f32);
    void Prim2D_SetCallback(void (*)(void *), s16 *);
    void Prim2D_ClearCallbacks(void);
    void Prim2D_SetTex(s32, u16);
    void Prim2D_ScissorFromRect(void *);
    s16 Text_MeasureHeight(s32, f32);
    s32 fn_8001059C(u8 *, s32, f32);
    s16 Text_MeasureWidth(u8 *, s32, f32);
    void *Msg_Expand(u8 *);
    void Text_Draw(s32, s32, s32, void *, ...);
    void Prim2D_AddPrim(s32);
    s32 *Ui_GetColor(s32);
    void Prim2D_SetColorPacked(s32 *);
    void fn_80006B18(s32, s32, s32, s32, s32);
    void Prim2D_EndPrim(void);
    void *fn_8014C604(u8 *);
    void *Msg_ResolveName(u32);
    void Allegiance_SetMask(s32, s32, s32, s32, s32, s32, s32, s32);
    extern f32 lbl_8036B6C0;
    extern f32 lbl_8036B6C4;
    extern f32 lbl_8036B6C8;
    extern f32 lbl_8036B6CC;
    extern f32 lbl_8036B6D0;
    extern f32 lbl_80367098[];
    extern u8 lbl_8027E8D0[];
    extern u8 gBattleState[];
    extern u8 gUnits[];
    extern u8 gUnitLists[];

    typedef void (*V0)(void *);
    typedef void (*V1)(void *, void *);
    typedef void (*VS)(void *, s16);
    V0 *vt;
    s16 rect_storage[4];
    s16 *rect;
    s16 dy, dx;
    s16 scroll_adj;
    s16 y0, x0, ybase;
    s16 half, gap, right, left_x;
    s16 row_y;
    s16 visible;
    f32 f1;
    s32 tmp;
    u8 *str_colon;
    s16 i;
    u8 any;
    u8 *unit;
    s16 x_cur, y_prev, x_prev;
    s16 name_w;
    void *node;
    void *entry;
    s8 flag;
    u8 flags8[0x20];

    vt = *(V0 **)arg0;
    ((V0)vt[0x30 / 4])(arg0);
    vt = *(V0 **)arg0;
    ((V1)vt[0x14 / 4])(arg0, arg1);

    dy = (s16)(M2C_FIELD(arg0, s16 *, 0x18) - M2C_FIELD(arg0, s16 *, 0x14));
    dx = (s16)(M2C_FIELD(arg0, s16 *, 0x16) - M2C_FIELD(arg0, s16 *, 0x12));
    rect = (s16 *)((u8 *)arg0 + 0x48);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = dx;
    rect[3] = dy;
    fn_8013F748(arg0, rect, rect);
    rect = (s16 *)((u8 *)arg0 + 0x4C);
    fn_8013F748(arg0, rect, rect);

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B6C0);
    Prim2D_SetTex(0, (u16)(M2C_FIELD(arg0, u32 *, 0x34) | 3));
    Prim2D_SetCallback(Prim2D_ScissorFromRect, (s16 *)((u8 *)arg0 + 0x48));
    Prim2D_PrepareTex();

    f1 = M2C_FIELD(arg0, f32 *, 0x44);
    str_colon = lbl_8027E8D0 + 0x1D;
    scroll_adj = 0;
    if (f1 < lbl_8036B6C4) {
        f1 = f1 + lbl_8036B6C8;
        M2C_FIELD(arg0, f32 *, 0x44) = f1;
        if (f1 >= -lbl_80367098[0]) {
            M2C_FIELD(arg0, f32 *, 0x44) = lbl_8036B6C4;
            M2C_FIELD(arg0, s16 *, 0x40) = (s16)(M2C_FIELD(arg0, s16 *, 0x40) - 0x1C);
        } else {
            scroll_adj = (s16)(-((s32)M2C_FIELD(arg0, f32 *, 0x44) + 0x1C));
        }
    } else if (f1 > lbl_8036B6C4) {
        f1 = f1 - lbl_8036B6C8;
        M2C_FIELD(arg0, f32 *, 0x44) = f1;
        if (f1 <= lbl_80367098[0]) {
            M2C_FIELD(arg0, f32 *, 0x44) = lbl_8036B6C4;
            M2C_FIELD(arg0, s16 *, 0x40) = (s16)(M2C_FIELD(arg0, s16 *, 0x40) + 0x1C);
        } else {
            scroll_adj = (s16)(0x1C - (s32)M2C_FIELD(arg0, f32 *, 0x44));
        }
    }

    left_x = M2C_FIELD(arg0, s16 *, 0x3C);
    scroll_adj = (s16)(M2C_FIELD(arg0, s16 *, 0x40) + scroll_adj);
    ybase = (s16)(scroll_adj + M2C_FIELD(arg0, s16 *, 0x3E));
    half = Text_MeasureHeight(-1, lbl_8036B6CC);
    gap = (s16)((0x1C - half) >> 1);
    right = (s16)((s16)(M2C_FIELD(arg0, s16 *, 0x16) - M2C_FIELD(arg0, s16 *, 0x12)) - left_x);
    right = (s16)(right - fn_8001059C(lbl_8027E8D0 + 0x20, -1, lbl_8036B6CC));
    x0 = (s16)(right - 0x18);
    y0 = Text_MeasureWidth(str_colon, -1, lbl_8036B6CC);

#define ROW_VISIBLE(y) ((((s16)((y) + 0x1C) > 0) && ((y) < (s16)(M2C_FIELD(arg0, s16 *, 0x18) - M2C_FIELD(arg0, s16 *, 0x14)))) ? 1 : 0)

    visible = ROW_VISIBLE(ybase);
    if (visible) {
        row_y = (s16)(ybase + gap);
        Text_Draw(left_x, row_y, 0xF, Msg_Expand(lbl_8027E8D0 + 0x24));
        Text_Draw(x0, row_y, 0xF, lbl_8027E8D0 + 0x20);
        Prim2D_AddPrim(6);
        tmp = *Ui_GetColor(0x1D);
        Prim2D_SetColorPacked(&tmp);
        fn_80006B18(x0, row_y, 0, 0, *(s32 *)(gBattleState + 0x68));
        Prim2D_EndPrim();
        vt = *(V0 **)arg0;
        ((VS)vt[0x2C / 4])(arg0, (s16)(half + row_y));
        Prim2D_Begin();
        Prim2D_SetTex(0, (u16)(M2C_FIELD(arg0, u32 *, 0x34) | 3));
        Prim2D_PrepareTex();
    }

    row_y = (s16)(ybase + 0x1C);
    visible = ROW_VISIBLE(row_y);
    if (visible) {
        row_y = (s16)(row_y + gap);
        Text_Draw(left_x, row_y, 0xF, Msg_Expand(lbl_8027E8D0 + 0x35));
        Text_Draw(x0, row_y, 0xF, lbl_8027E8D0 + 0x20);
        Prim2D_AddPrim(6);
        tmp = *Ui_GetColor(0x1E);
        Prim2D_SetColorPacked(&tmp);
        fn_80006B18(x0, row_y, 0, 0, *(s32 *)(gBattleState + 0x6C));
        Prim2D_EndPrim();
        vt = *(V0 **)arg0;
        ((VS)vt[0x2C / 4])(arg0, (s16)(half + row_y));
        Prim2D_Begin();
        Prim2D_SetTex(0, (u16)(M2C_FIELD(arg0, u32 *, 0x34) | 3));
        Prim2D_PrepareTex();
    }

    row_y = (s16)(ybase + 0x38);
    visible = ROW_VISIBLE(row_y);
    if (visible) {
        row_y = (s16)(row_y + gap);
        Text_Draw(left_x, row_y, 0xF, Msg_Expand(lbl_8027E8D0 + 0x44));
        Text_Draw(x0, row_y, 0xF, lbl_8027E8D0 + 0x20);
        Prim2D_AddPrim(6);
        tmp = *Ui_GetColor(2);
        Prim2D_SetColorPacked(&tmp);
        fn_80006B18(x0, row_y, 0, 0, *(s32 *)(gBattleState + 0x18));
        Prim2D_EndPrim();
        vt = *(V0 **)arg0;
        ((VS)vt[0x2C / 4])(arg0, (s16)(half + row_y));
        Prim2D_Begin();
        Prim2D_SetTex(0, (u16)(M2C_FIELD(arg0, u32 *, 0x34) | 3));
        Prim2D_PrepareTex();
    }

    row_y = (s16)(ybase + 0x54);
    visible = ROW_VISIBLE(row_y);
    if (visible) {
        row_y = (s16)(row_y + gap);
        Text_Draw(left_x, row_y, 0xF, Msg_Expand(lbl_8027E8D0 + 0x54));
        Text_Draw(x0, row_y, 0xF, lbl_8027E8D0 + 0x62);
        Prim2D_AddPrim(6);
        tmp = *Ui_GetColor(0x1D);
        Prim2D_SetColorPacked(&tmp);
        fn_80006B18(x0, row_y, 0, 0, (s32)M2C_FIELD(gBattleState, s16 *, 0x70));
        Prim2D_EndPrim();
        vt = *(V0 **)arg0;
        ((VS)vt[0x2C / 4])(arg0, (s16)(half + row_y));
        Prim2D_Begin();
        Prim2D_SetTex(0, (u16)(M2C_FIELD(arg0, u32 *, 0x34) | 3));
        Prim2D_PrepareTex();
    }

    row_y = (s16)(ybase + 0x70);
    visible = ROW_VISIBLE(row_y);
    if (visible) {
        row_y = (s16)(row_y + gap);
        Text_Draw(left_x, row_y, 0xF, Msg_Expand(lbl_8027E8D0 + 0x66));
        Text_Draw(x0, row_y, 0xF, lbl_8027E8D0 + 0x62);
        Prim2D_AddPrim(6);
        tmp = *Ui_GetColor(0x1D);
        Prim2D_SetColorPacked(&tmp);
        fn_80006B18(x0, row_y, 0, 0, (s32)M2C_FIELD(gBattleState, s16 *, 0x72));
        Prim2D_EndPrim();
        vt = *(V0 **)arg0;
        ((VS)vt[0x2C / 4])(arg0, (s16)(half + row_y));
        Prim2D_Begin();
        Prim2D_SetTex(0, (u16)(M2C_FIELD(arg0, u32 *, 0x34) | 3));
        Prim2D_PrepareTex();
    }

    row_y = (s16)(ybase + 0x8C);
    visible = ROW_VISIBLE(row_y);
    if (visible) {
        row_y = (s16)(row_y + gap);
        Text_Draw(left_x, row_y, 0xF, Msg_Expand(lbl_8027E8D0 + 0x76));
        if (fn_8014C604(gBattleState) != NULL) {
            Text_Draw((s16)(left_x + 0x80), row_y, 2, Msg_ResolveName(*(u32 *)((u8 *)fn_8014C604(gBattleState) + 0x188)));
        } else {
            Text_Draw((s16)(left_x + 0x80), row_y, 0xF, lbl_8027E8D0 + 0x84);
        }
        vt = *(V0 **)arg0;
        ((VS)vt[0x2C / 4])(arg0, (s16)(half + row_y));
        Prim2D_Begin();
        Prim2D_SetTex(0, (u16)(M2C_FIELD(arg0, u32 *, 0x34) | 3));
        Prim2D_PrepareTex();
    }

    ybase = (s16)(ybase + 0xA8);
    visible = ROW_VISIBLE(ybase);
    if (visible) {
        row_y = (s16)(ybase + gap);
        Text_Draw(left_x, row_y, 0xF, Msg_Expand(lbl_8027E8D0 + 0x8D));
        vt = *(V0 **)arg0;
        ((VS)vt[0x2C / 4])(arg0, (s16)(half + row_y));
    }
    Prim2D_Begin();
    Prim2D_SetTex(0, (u16)(M2C_FIELD(arg0, u32 *, 0x34) | 3));
    Prim2D_PrepareTex();

    x_cur = 0x80;
    x_prev = 0;
    y_prev = 0;
    any = 0;
    Allegiance_SetMask(1, 0, 0, 0, 0, 1, 1, 0);
    row_y = (s16)(ybase + gap);
    for (i = 1; i <= 0x9F; i++) {
        unit = gUnits + (i - 1) * 0x280;
        if (M2C_FIELD(unit, u32 *, 0x188) != 0
            && flags8[M2C_FIELD(*(void **)((u8 *)unit + 0x190), u8 *, 8)] != 0
            && (M2C_FIELD(unit, u32 *, 0x1A0) & 0x80000)) {
            any = 1;
            Msg_ResolveName(M2C_FIELD(unit, u32 *, 0x188));
            name_w = Text_MeasureWidth((u8 *)-1, -1, lbl_8036B6CC);
            if ((s32)(x_cur + name_w + y0) > right + 0x18) {
                if (ROW_VISIBLE(ybase)) {
                    vt = *(V0 **)arg0;
                    ((VS)vt[0x2C / 4])(arg0, (s16)(half + row_y));
                }
                Prim2D_Begin();
                Prim2D_SetTex(0, (u16)(M2C_FIELD(arg0, u32 *, 0x34) | 3));
                Prim2D_PrepareTex();
                x_cur = 0x80;
                row_y = (s16)(row_y + 0x1C);
                ybase = (s16)(ybase + 0x1C);
            }
            if (x_prev != 0) {
                if (ROW_VISIBLE(y_prev)) {
                    Text_Draw(x_prev, (s16)(y_prev + gap), 2, Msg_Expand(str_colon));
                }
            }
            if (ROW_VISIBLE(ybase)) {
                Text_Draw((s16)(left_x + x_cur), row_y, 2, Msg_ResolveName(M2C_FIELD(unit, u32 *, 0x188)));
            }
            y_prev = ybase;
            x_prev = (s16)(left_x + x_cur + name_w);
            x_cur = (s16)(name_w + y0 + x_cur);
        }
    }
    if (any == 0) {
        if (ROW_VISIBLE(ybase)) {
            Text_Draw((s16)(left_x + 0x80), (s16)(ybase + gap), 0xF, lbl_8027E8D0 + 0x84);
        }
    }
    if (ROW_VISIBLE(ybase)) {
        vt = *(V0 **)arg0;
        ((VS)vt[0x2C / 4])(arg0, (s16)(ybase + gap + half));
    }

    ybase = (s16)(ybase + 0x1C);
    Prim2D_Begin();
    Prim2D_SetTex(0, (u16)(M2C_FIELD(arg0, u32 *, 0x34) | 3));
    Prim2D_PrepareTex();
    if (ROW_VISIBLE(ybase)) {
        row_y = (s16)(ybase + gap);
        Text_Draw(left_x, row_y, 0xF, Msg_Expand(lbl_8027E8D0 + 0x9C));
        vt = *(V0 **)arg0;
        ((VS)vt[0x2C / 4])(arg0, (s16)(half + row_y));
    }
    Prim2D_Begin();
    Prim2D_SetTex(0, (u16)(M2C_FIELD(arg0, u32 *, 0x34) | 3));
    Prim2D_PrepareTex();

    row_y = (s16)(ybase + gap);
    x_cur = 0x80;
    node = *(void **)(gUnitLists + 0x48);
    x_prev = 0;
    y_prev = 0;
    any = 0;
    while (node != NULL) {
        entry = M2C_FIELD(node, void **, 0x184);
        if (M2C_FIELD(node, u32 *, 0x1A0) & 0x8000) {
            any = 1;
            Msg_ResolveName(M2C_FIELD(node, u32 *, 0x188));
            name_w = Text_MeasureWidth((u8 *)-1, -1, lbl_8036B6CC);
            if ((s32)(x_cur + name_w + y0) > right + 0x18) {
                if (ROW_VISIBLE(ybase)) {
                    vt = *(V0 **)arg0;
                    ((VS)vt[0x2C / 4])(arg0, (s16)(half + row_y));
                }
                Prim2D_Begin();
                Prim2D_SetTex(0, (u16)(M2C_FIELD(arg0, u32 *, 0x34) | 3));
                Prim2D_PrepareTex();
                x_cur = 0x80;
                row_y = (s16)(row_y + 0x1C);
                ybase = (s16)(ybase + 0x1C);
            }
            if (x_prev != 0) {
                if (ROW_VISIBLE(y_prev)) {
                    Text_Draw(x_prev, (s16)(y_prev + gap), 2, Msg_Expand(str_colon));
                }
            }
            if (ROW_VISIBLE(ybase)) {
                Text_Draw((s16)(left_x + x_cur), row_y, 2, Msg_ResolveName(M2C_FIELD(node, u32 *, 0x188)));
            }
            y_prev = ybase;
            x_prev = (s16)(left_x + x_cur + name_w);
            x_cur = (s16)(name_w + y0 + x_cur);
        }
        node = entry;
    }
    if (any == 0) {
        if (ROW_VISIBLE(ybase)) {
            Text_Draw((s16)(left_x + 0x80), (s16)(ybase + gap), 0xF, lbl_8027E8D0 + 0x84);
        }
    }
    {
        s16 next_y = (s16)(ybase + 0x1C);
        visible = 0;
        if (next_y > 0 && ybase < (s16)(M2C_FIELD(arg0, s16 *, 0x18) - M2C_FIELD(arg0, s16 *, 0x14))) {
            visible = 1;
        }
        if (visible) {
            vt = *(V0 **)arg0;
            ((VS)vt[0x2C / 4])(arg0, (s16)(ybase + gap + half));
        }
        Prim2D_Begin();
        Prim2D_SetTex(0, (u16)(M2C_FIELD(arg0, u32 *, 0x34) | 3));
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B6D0);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_ClearCallbacks();
        Prim2D_PrepareTex();

        flag = 0;
        {
            s16 top = (s16)(scroll_adj + M2C_FIELD(arg0, s16 *, 0x3E));
            if (top < 0 || (s16)(top + 0x1C) >= (s16)(M2C_FIELD(arg0, s16 *, 0x18) - M2C_FIELD(arg0, s16 *, 0x14))) {
                flag = 1;
            }
        }
        M2C_FIELD(arg0, s8 *, 0x5C) = flag;
        {
            void *sub = (u8 *)arg0 + 0x50;
            vt = *(V0 **)sub;
            ((VS)vt[0x2C / 4])(sub, (s16)M2C_FIELD(arg0, u32 *, 0x34));
        }
        flag = 0;
        if (ybase < 0 || next_y >= (s16)(M2C_FIELD(arg0, s16 *, 0x18) - M2C_FIELD(arg0, s16 *, 0x14))) {
            flag = 1;
        }
        M2C_FIELD(arg0, s8 *, 0x84) = flag;
        {
            void *sub = (u8 *)arg0 + 0x78;
            vt = *(V0 **)sub;
            ((VS)vt[0x2C / 4])(sub, (s16)M2C_FIELD(arg0, u32 *, 0x34));
        }
    }
#undef ROW_VISIBLE
}

#pragma cplusplus on
extern "C" void fn_801DF468(void *arg0) {
    void fn_80151EDC(s32, s32, s32);
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    ((Obj *)arg0)->v2();
    fn_80151EDC(0, 0, 0x10);
}
#pragma cplusplus on
#pragma global_optimizer off
extern "C" void fn_801DF4A4(void *arg0, s32 arg1) {
    struct Color {
        u8 r, g, b, a;
    };
    void Ui_DrawLine(s32, s32, s16, s32, s32, struct Color *);
    s16 v, h;
    struct Color col;

    h = *(s16 *)((u8 *)arg0 + 0x12);
    h = *(s16 *)((u8 *)arg0 + 0x16) - h;
    col.r = 0x80;
    col.g = 0x78;
    col.b = 0x50;
    col.a = 0xE6;
    v = h - 0x10;
    Ui_DrawLine(0x10, arg1, v, arg1, 0x10, &col);
}
#pragma global_optimizer reset
#pragma cplusplus reset
extern "C" void *Ui_DtorPanelD(void *self, s16 doFree) {
    /* C++ destructor for UI panel D (gUiPanelDVtbl): destroy embeds, chain base vtors, optional free. */
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    struct Owner {
        void *vtbl;
        u8 pad4[0x4C];
        void *sub50;
        u8 pad54[0x24];
        void *sub78;
    };
    void Heap_Free(void *);
    extern u8 gUiPanelDVtbl[];
    extern u8 gEmptyVtbl[];
    extern u8 lbl_80292230[];
    extern u8 lbl_8028FDB0[];
    Owner *owner;

    owner = (Owner *)self;
    if (self) {
        owner->vtbl = gUiPanelDVtbl;
        if (&owner->sub78) {
            owner->sub78 = gEmptyVtbl;
            ((Obj *)&owner->sub78)->v2();
        }
        if (&owner->sub50) {
            owner->sub50 = gEmptyVtbl;
            ((Obj *)&owner->sub50)->v2();
        }
        if (self) {
            owner->vtbl = lbl_80292230;
            if (self) {
                owner->vtbl = lbl_8028FDB0;
            }
        }
        if (doFree > 0) {
            Heap_Free(self);
        }
    }
    return self;
}
#pragma cplusplus reset

extern u8 lbl_80299F4C[];
void fn_801DF5D8(void) {
    extern u8 lbl_80299F4C[];
    void Process_CreateChild(void *);
    Process_CreateChild(lbl_80299F4C);
}

void fn_801DF600(void *arg0)
{
    extern void *gSaveDataBase;

    void *memset(void *, s32, u32);
    s32 fn_8021D614(s32, u32 *);
    s64 OSGetTime(void);
    s32 fn_80211690(void);
    u16 fn_802072A0(void);
    u8 fn_80209A0C(void);
    void Card_RequestWrite(void *, s32, s32, s32, s32);

    union {
        u64 value;
        u32 words[2];
    } timestamp;

    u8 *save;
    s32 language;

    save = (u8 *)gSaveDataBase + 0x2000;

    memset(save, 0, 0x2000);

    *(u32 *)(save + 0x70) = 0x53595346;
    *(u32 *)(save + 0x74) = 0x20050201;

    timestamp.words[0] = 0;
    timestamp.words[1] = 0;

    fn_8021D614(0, timestamp.words);

    timestamp.value += (u64)OSGetTime();
    timestamp.value += (u32)fn_80211690() * 0x7B;

    *(u32 *)(save + 0x7C) = timestamp.words[1];
    *(u32 *)(save + 0x78) = timestamp.words[0];

    *(u16 *)(save + 0x80) = 0;

    save[0xB0] = 0;
    save[0xB1] = 0;
    save[0xB2] = 0x40;
    save[0xB3] = 0;

    if (fn_802072A0() == 1) {
        language = 0;
    } else {
        switch (fn_80209A0C()) {
        case 0:
            language = 1;
            break;
        case 1:
            language = 2;
            break;
        case 2:
            language = 3;
            break;
        case 3:
            language = 4;
            break;
        case 4:
            language = 5;
            break;
        case 5:
            language = 1;
            break;
        }
    }

    save[0xB4] = language;
    save[0xB7] = 0;

    memset(save + 0x82, 0, 0x1E);
    memset(save + 0xB5, 0, 2);

    *(u32 *)(save + 0xAC) = 0;
    *(u32 *)(save + 0xA8) = 0;
    *(u32 *)(save + 0xA4) = 0;
    *(u32 *)(save + 0xA0) = 0;
    *(u32 *)(save + 0x40) = 0;
    *(u32 *)(save + 0x48) = 1;

    Card_RequestWrite(
        save,
        0x2000,
        (s32)(save - (u8 *)gSaveDataBase),
        -1,
        (s32)arg0
    );
}

extern u64 OSGetTime();
extern u16 fn_802072A0(u32, s32, s32, s32);
extern u8 fn_80209A0C();
extern s32 fn_80211690(s32, s32);
extern void fn_8021D614(u32, s32*, u32);
void fn_801DF7C8(void *arg0) {
    s32 fn_80211690();
    u16 fn_802072A0();
    u64 time;
    s8 lang;
    u8 *p = arg0;
    u32 add;
    memset(p, 0, 0x2000);
    *(u32 *)(p+0x70)=0x53595346;
    *(u32 *)(p+0x74)=0x20050201;
    time=0;
    fn_8021D614(0,(s32 *)&time,0x20050201);
    time += OSGetTime();
    add=fn_80211690()*123;
    time += add;
    *(u64 *)(p+0x78)=time;
    *(u16 *)(p+0x80)=0;
    p[0xB0]=0; p[0xB1]=0; p[0xB2]=0x40; p[0xB3]=0;
    if (fn_802072A0()==1) lang=0;
    else switch((s32)fn_80209A0C()) {
    case 0: lang=1; break; case 1: lang=2; break; case 2: lang=3; break;
    case 3: lang=4; break; case 4: lang=5; break; case 5: lang=1; break;
    }
    p[0xB4]=lang; p[0xB7]=0;
    memset(p+0x82,0,0x1E); memset(p+0xB5,0,2);
    *(u32 *)(p+0xAC)=0; *(u32 *)(p+0xA8)=0; *(u32 *)(p+0xA4)=0; *(u32 *)(p+0xA0)=0;
    *(u32 *)(p+0x40)=0; *(u32 *)(p+0x48)=1;
}

void fn_801DF960(void *arg0)
{
    extern void *gSaveDataBase;
    void Process_Goto(void *, s32);

    u8 *data;
    s32 i;
    u32 offset;
    u32 size;
    u32 limit;
    u32 mask;
    u8 valid;
    u8 found;
    u8 *base;
    u32 offset2;
    u8 *slot;

    base = (u8 *)gSaveDataBase;
    i = 0;
    offset = 0x2000;
    for (; i < 6; i++) {
        data = base + offset;
        if (*(u32 *)(data + 0x70) != 0x53595346U) {
            valid = 0;
        } else if (*(u32 *)(data + 0x74) != 0x20050201U) {
            valid = 0;
        } else {
            valid = 1;
        }
        if (valid != 0) {
            size = *(u32 *)(data + 0x48);
            limit = 0x100000;
            mask = size > limit ? 0 : size;
            if (mask <= limit) {
                found = 1;
                goto check;
            }
        }
        offset += 0x4000;
    }

    offset2 = 0x1A000;
    for (i = 0; i < 2; i++) {
        slot = base + offset2;
        if (*(u32 *)(slot + 0x70) != 0x53595346U) {
            valid = 0;
        } else if (*(u32 *)(slot + 0x74) != 0x20050201U) {
            valid = 0;
        } else {
            valid = 1;
        }
        if (valid != 0) {
            size = *(u32 *)(slot + 0x48);
            limit = 0x100000;
            mask = size > limit ? 0 : size;
            if (mask <= limit) {
                found = 1;
                goto check;
            }
        }
        offset2 += 0x6000;
    }

    found = 0;
check:
    if (found != 0) return;
    Process_Goto(arg0, 2);
}

void fn_801DFB4C(void *arg0) {
    extern void *gSaveDataBase;
    extern u8 gSaveStrings[];

    void DebugPrint(const char *, ...);
    void fn_800C4588(void *);
    void *fn_800C4604(s32, s32, void *, s32);
    void fn_800EA540(void *, void *);

    void *ptr;
    void *arg;

    arg = arg0;

    if (gSaveDataBase != (int)NULL) {
        DebugPrint(
            (char *)(gSaveStrings + 0x122)
        );

        fn_800C4588(gSaveDataBase);
        gSaveDataBase = NULL;
    }

    DebugPrint(
        (char *)(gSaveStrings + 0x137)
    );

    ptr = fn_800C4604(
        0,
        -0x26000,
        gSaveStrings + 0x14E,
        0
    );

    gSaveDataBase = ptr;

    fn_800EA540(ptr, arg);
}

#pragma use_lmw_stmw on
#pragma optimization_level 2
/* Clear first corrupt chapter/suspend save slot (bad CRC) and request a card rewrite; return 1 if cleared. */
s32 Save_ClearCorruptSlots(s32 proc) {
    extern void *gSaveDataBase;
    extern u8 gSaveStrings[];
    u8 Card_CheckError(void);
    void *fn_800C4638(s32, void *, s32);
    void fn_800C4588(void *);
    void Crc32_InitTable(void);
    u32 Crc32_Calc(void *, void *, s32);
    void Card_RequestWrite(void *, s32, s32, s32, s32);
    void *memset(void *, s32, s32);

    void *crcTable;
    u32 checksum;
    s32 self;
    s32 i;
    u8 *slot;
    s32 offset;
    u8 headerOk;
    u8 checksumOk;

    self = proc;
    if (Card_CheckError() != 0) {
        return 0;
    }

    i = 0;
    offset = 0x2000;
    do {
        slot = (u8 *)gSaveDataBase + offset;
        if (*(u32 *)(slot + 0x40) != SAVE_SLOT_MAGIC) {
            headerOk = 0;
        } else if (*(u32 *)(slot + 0x44) != SAVE_VER_20050201) {
            headerOk = 0;
        } else {
            headerOk = 1;
        }
        if (headerOk != 0) {
            if (*(u32 *)(slot + 0x50) == SAVE_CHECKSUM_UNINIT) {
                checksumOk = 1;
            } else if (*(u8 *)(slot + 0x60) == 1) {
                checksumOk = 1;
            } else {
                crcTable = fn_800C4638(0x400, gSaveStrings + 0x14E, 0);
                Crc32_InitTable();
                checksum = Crc32_Calc(crcTable, slot + SAVE_SLOT_PAYLOAD_OFF, *(s32 *)(slot + 0x4C) - SAVE_SLOT_PAYLOAD_OFF);
                fn_800C4588(crcTable);
                if (*(u32 *)(slot + 0x50) != checksum) {
                    checksumOk = 0;
                } else {
                    checksumOk = 1;
                }
            }
            if (checksumOk == 0) {
                memset(slot, 0, SAVE_SLOT_BLOCK_SIZE);
                Card_RequestWrite(slot, SAVE_SLOT_BLOCK_SIZE, (s32)(slot - (u8 *)gSaveDataBase), -1, self);
                return 1;
            }
        }
        i += 1;
        offset += 0x4000;
    } while (i < 6);

    i = 0;
    offset = 0x1A000;
    do {
        slot = (u8 *)gSaveDataBase + offset;
        if (*(u32 *)(slot + 0x40) != SAVE_SLOT_MAGIC) {
            headerOk = 0;
        } else if (*(u32 *)(slot + 0x44) != SAVE_VER_20050201) {
            headerOk = 0;
        } else {
            headerOk = 1;
        }
        if (headerOk != 0) {
            if (*(u32 *)(slot + 0x50) == SAVE_CHECKSUM_UNINIT) {
                checksumOk = 1;
            } else if (*(u8 *)(slot + 0x60) == 1) {
                checksumOk = 1;
            } else {
                crcTable = fn_800C4638(0x400, gSaveStrings + 0x14E, 0);
                Crc32_InitTable();
                checksum = Crc32_Calc(crcTable, slot + SAVE_SLOT_PAYLOAD_OFF, *(s32 *)(slot + 0x4C) - SAVE_SLOT_PAYLOAD_OFF);
                fn_800C4588(crcTable);
                if (*(u32 *)(slot + 0x50) != checksum) {
                    checksumOk = 0;
                } else {
                    checksumOk = 1;
                }
            }
            if (checksumOk == 0) {
                memset(slot, 0, SAVE_SLOT_BLOCK_SIZE);
                Card_RequestWrite(slot, SAVE_SLOT_BLOCK_SIZE, (s32)(slot - (u8 *)gSaveDataBase), -1, self);
                return 1;
            }
        }
        i += 1;
        offset += 0x6000;
    } while (i < 2);

    return 0;
}
  #pragma optimization_level reset
  
  static inline u32 save_slot_size(u8 *slot) {
    u32 size = *(u32 *)(slot + 0x48);
    if (size > 0x100000U) {
        return 0;
    }
    return size;
}

static inline u32 save_slot_size_lim(u8 *slot, u32 limit) {
    u32 size = *(u32 *)(slot + 0x48);
    return (size <= limit) ? size : 0;
}
  
#pragma opt_strength_reduction off
void fn_801DFE60(u8 **arg0, s32 arg1) {
    void fn_800062CC(void *, void *, s32);
    void fn_801E3CA8(void *);
    void Card_RequestWrite(void *, s32, s32, s32, s32);
    extern void *gSaveDataBase;

    u32 minSize;
    s32 off;
    u8 *best;
    s32 i;
    s32 self;
    s32 ctr;
    u8 *slot;
    u8 hdrOk;
    u32 clamped;
    u8 *found;
    s32 diff;

    minSize = (u32)-1;
    off = 0x2000;
    best = NULL;
    i = 0;
    self = arg1;

    for (ctr = 3; ctr != 0; ctr--) {
        slot = *arg0 + off;
        if (*(u32 *)(slot + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(slot + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk == 0) {
            clamped = save_slot_size(slot);
            if (minSize > clamped) {
                best = slot;
                minSize = save_slot_size(slot);
            }
        }
        off += 0x4000;
        slot = *arg0 + off;
        if (*(u32 *)(slot + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(slot + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk == 0) {
            clamped = save_slot_size(slot);
            if (minSize > clamped) {
                best = slot;
                minSize = save_slot_size(slot);
            }
        }
        off += 0x4000;
        i += 1;
    }

    i = 0;
    off = 0x2000;
    for (ctr = 2; ctr != 0; ctr--) {
        found = *arg0 + off;
        if (*(u32 *)(found + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(found + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk != 0) {
            goto found_slot;
        }
        off += 0x4000;
        found = *arg0 + off;
        if (*(u32 *)(found + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(found + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk != 0) {
            goto found_slot;
        }
        off += 0x4000;
        found = *arg0 + off;
        if (*(u32 *)(found + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(found + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk != 0) {
            goto found_slot;
        }
        off += 0x4000;
        i += 2;
    }

    found = NULL;

found_slot:
    if (found == NULL) {
        found = *arg0 + 0x2000;
        if (found == best) {
            found = *arg0 + 0x6000;
        }
    }

    fn_800062CC(best, found, *(s32 *)(found + 0x4C));
    fn_801E3CA8(best);
    diff = (s32)best - (s32)gSaveDataBase;
    Card_RequestWrite(best, *(s32 *)(best + 0x4C), diff, diff, self);
}
  extern u8 lbl_80299F1C[];
void fn_801E00EC(void *arg0, void *arg1) { void Process_CreateChild(void *); extern u8 lbl_80299F1C[]; (void)arg0; (void)arg1; Process_CreateChild(lbl_80299F1C); }

void fn_801E0114(s32 arg0) {
    u8 Card_CheckError(void);
    void fn_801E0154(void *, s32);
    extern u32 gSaveDataBase;

    if (Card_CheckError() != 0) {
        return;
    }

    fn_801E0154(&gSaveDataBase, arg0);
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
void fn_801E0154(u8 **arg0, s32 arg1) {
    void fn_800062CC(void *, void *, s32);
    void fn_801E3CA8(void *);
    void Card_RequestWrite(void *, s32, s32, s32, s32);
    void *fn_800C4638(s32, void *, s32);
    void fn_800C4588(void *);
    void Crc32_InitTable(void);
    u32 Crc32_Calc(void *, void *, s32);
    extern void *gSaveDataBase;
    extern u8 gSaveStrings[];

    u8 *base;
    u8 *src;
    u8 *cand;
    u8 *dst;
    s32 off;
    s32 j;
    s32 i;
    s32 dummy;
    s32 ctr;
    s32 self;
    u8 id;
    u8 hdrOk;
    u8 chkOk;
    void *buf;
    u32 sum;

    self = arg1;
    off = 0x20000 - 0x6000;
    i = 0;
loop1:
    base = *arg0;
    src = base + off;
    if (*(u32 *)(src + 0x40) != 0x4645384AU) {
        hdrOk = 0;
    } else if (*(u32 *)(src + 0x44) != 0x20050201U) {
        hdrOk = 0;
    } else {
        hdrOk = 1;
    }
    if (hdrOk == 0) {
        goto next1;
    }
    id = *(u8 *)(src + 0x63);
    dummy = 0;
    j = 0x2000;
    ctr = 2;
    do {
        cand = base + j;
        if (*(u32 *)(cand + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(cand + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk == 0) {
            goto miss1;
        }
        if ((s32)*(u8 *)(cand + 0x62) != (s32)id) {
            goto miss1;
        }
        goto found_pair;
    miss1:
        j += 0x4000;
        cand = base + j;
        if (*(u32 *)(cand + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(cand + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk == 0) {
            goto miss2;
        }
        if ((s32)*(u8 *)(cand + 0x62) != (s32)id) {
            goto miss2;
        }
        goto found_pair;
    miss2:
        j += 0x4000;
        cand = base + j;
        if (*(u32 *)(cand + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(cand + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk == 0) {
            goto miss3;
        }
        if ((s32)*(u8 *)(cand + 0x62) != (s32)id) {
            goto miss3;
        }
        goto found_pair;
    miss3:
        j += 0x4000;
        dummy += 2;
        ctr -= 1;
    } while (ctr != 0);
    cand = NULL;
found_pair:
    if (cand == NULL) {
        goto next1;
    }
    goto phase2;
next1:
    i += 1;
    off += 0x6000;
    if (i < 2) {
        goto loop1;
    }
    src = NULL;

phase2:
    i = 0;
    off = 0x20000 - 0x6000;
loop2:
    dst = *arg0 + off;
    if (*(u32 *)(dst + 0x40) != 0x4645384AU) {
        hdrOk = 0;
    } else if (*(u32 *)(dst + 0x44) != 0x20050201U) {
        hdrOk = 0;
    } else {
        hdrOk = 1;
    }
    if (hdrOk == 0) {
        goto do_copy;
    }
    if (*(u32 *)(dst + 0x50) == 0x12345678U) {
        chkOk = 1;
    } else if (*(u8 *)(dst + 0x60) == 1) {
        chkOk = 1;
    } else {
        buf = fn_800C4638(0x400, gSaveStrings + 0x14E, 0);
        Crc32_InitTable();
        sum = Crc32_Calc(buf, dst + 0x70, *(s32 *)(dst + 0x4C) - 0x70);
        fn_800C4588(buf);
        if (*(u32 *)(dst + 0x50) != sum) {
            chkOk = 0;
        } else {
            chkOk = 1;
        }
    }
    if (chkOk == 0) {
        goto do_copy;
    }
    i += 1;
    off += 0x6000;
    if (i < 2) {
        goto loop2;
    }
    base = *arg0;
    dst = base + 0x1A000;
    if (save_slot_size(base + 0x1A000) >= save_slot_size(base + 0x20000)) {
        dst = base + 0x20000;
    }

do_copy:
    fn_800062CC(dst, src, *(s32 *)(src + 0x4C));
    fn_801E3CA8(dst);
    *(u8 *)(dst + 0x60) = 1;
    Card_RequestWrite(dst, 0x2000, (s32)dst - (s32)gSaveDataBase, -1, self);
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
void fn_801E047C(u8 **arg0, s32 arg1) {
    void fn_80006298(void *, s32, s32);
    void fn_800167E4(void *);
    void Unit_WriteAll(void *);
    void fn_80048C5C(void *);
    void Icon_WriteSlots(void *, void *);
    void fn_800C33C0(void *, void *);
    void fn_800C4588(void *);
    void *fn_800C4638(s32, void *, s32);
    void Card_RequestWrite(void *, s32, s32, s32, s32);
    u32 Crc32_Calc(void *, void *, s32);
    void Crc32_InitTable(void);
    void fn_8010FBA8(void *, void *);
    void BattleState_Write(void *, void *);
    void fn_8017A38C(void *, void *);
    void fn_801E3CA8(void *);
    extern u8 gSaveStrings[];
    extern u8 gStreamBaseVtbl[];
    extern u8 gMemStreamVtbl[];
    extern u8 gConvoy[];
    extern u8 gIconSlots[];
    extern u8 gMapObjEventList[];
    extern u8 gBattleState[];
    extern u8 gSystemSave[];
    extern s32 gSaveDataBase;

    s32 i;
    s32 off;
    u8 *slot;
    u8 hdrOk;
    u8 chkOk;
    void *buf;
    u32 sum;
    u8 *base;
    struct {
        void *start;
        void *cur;
        u32 size;
        u8 owned;
        u8 pad[3];
        void *vtbl;
    } w;
    u8 *p;

    i = 0;
    off = 0x20000 - 0x6000;
loop:
    slot = *arg0 + off;
    if ((u32)(*(u32 *)(slot + 0x40) + 0xB9BB0000) != 0x384AU) {
        hdrOk = 0;
    } else if ((u32)(*(u32 *)(slot + 0x44) + 0xDFFB0000) != 0x201U) {
        hdrOk = 0;
    } else {
        hdrOk = 1;
    }
    if (hdrOk != 0) {
        if ((u32)(*(u32 *)(slot + 0x50) + 0xEDCC0000) == 0x5678U) {
            chkOk = 1;
        } else if (slot[0x60] == 1) {
            chkOk = 1;
        } else {
            buf = fn_800C4638(0x400, gSaveStrings + 0x14E, 0);
            Crc32_InitTable();
            sum = Crc32_Calc(buf, slot + 0x70, *(s32 *)(slot + 0x4C) - 0x70);
            fn_800C4588(buf);
            if (*(u32 *)(slot + 0x50) != sum) {
                chkOk = 0;
            } else {
                chkOk = 1;
            }
        }
        if (chkOk == 0) {
        } else {
            i += 1;
            off += 0x6000;
            if (i < 2) {
                goto loop;
            }
            base = *arg0;
            slot = base + 0x1A000;
            if (save_slot_size(base + 0x1A000) < save_slot_size(base + 0x20000)) {
            } else {
                slot = base + 0x20000;
            }
        }
    }

    fn_80006298(slot, 0, 0x6000);
    *(s32 *)(slot + 0x4C) = 0x6000;
    *(u32 *)(slot + 0x40) = 0x4645384AU;
    *(u32 *)(slot + 0x44) = 0x20050201U;
    *(u32 *)(slot + 0x48) = 0;
    *(u32 *)(slot + 0x5C) = 0;
    *(u32 *)(slot + 0x58) = 0;
    p = slot + 0xB8;
    slot[0x60] = 3;
    slot[0x61] = 0;
    slot[0x62] = 0;
    slot[0x63] = 0;
    slot[0x64] = 0;
    slot[0x65] = 0;
    slot[0x66] = 0;
    slot[0x63] = gSystemSave[0x47];
    *(u32 *)(slot + 0x5C) = *(u32 *)(gBattleState + 0x5C);
    *(u32 *)(slot + 0x58) = *(u32 *)(gBattleState + 0x58);
    slot[0x61] = gBattleState[0x51C];
    slot[0x64] = gBattleState[0x10];
    slot[0x65] = 8;
    slot[0x66] = gBattleState[0xA6];

    w.vtbl = gStreamBaseVtbl;
    w.cur = NULL;
    w.start = NULL;
    w.size = 0;
    w.owned = 0;
    w.vtbl = gMemStreamVtbl;
    w.owned = 0;
    w.start = p;
    w.cur = p;
    w.size = 0x100000;
    fn_8017A38C(&w, gSaveStrings + 0x14F);
    BattleState_Write(gBattleState, &w);
    fn_8017A38C(&w, gSaveStrings + 0x154);
    fn_80048C5C(&w);
    fn_8017A38C(&w, gSaveStrings + 0x159);
    if (gBattleState[0x55] != 0) {
        fn_800167E4(&w);
    } else {
        Unit_WriteAll(&w);
    }
    fn_8017A38C(&w, gSaveStrings + 0x15E);
    fn_800C33C0(gConvoy, &w);
    fn_8017A38C(&w, gSaveStrings + 0x163);
    Icon_WriteSlots(gIconSlots, &w);
    fn_8017A38C(&w, gSaveStrings + 0x168);
    fn_8010FBA8(gMapObjEventList, &w);
    w.vtbl = gMemStreamVtbl;
    w.vtbl = gStreamBaseVtbl;
    if (w.owned != 0) {
        fn_800C4588(w.start);
        w.start = NULL;
        w.owned = 0;
    }
    fn_801E3CA8(slot);
    arg0[1] = slot;
    Card_RequestWrite(slot, *(s32 *)(slot + 0x4C), (s32)slot - gSaveDataBase, (s32)slot - gSaveDataBase, arg1);
}
#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset

#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset

static inline u8 *Save_FindLinkedSlot(u8 *base, s32 id)
{
s32 off;
u8 *slot;
s32 i;
u8 valid;
i=0; off=0x2000;
for(;i<6;i++) {
slot=base+off;
if(*(u32 *)(slot+0x40)!=0x4645384AU) valid=0;
else if(*(u32 *)(slot+0x44)!=0x20050201U) valid=0;
else valid=1;
if(valid && id==slot[0x62]) return slot;
off+=0x4000;
}
return 0;
}
static inline u8 *Save_FindLinkedHeader(u8 **save)
{
u8 *base;
s32 off;
u8 *slot;
s32 i;
u8 valid;
i=0; off=0x1a000;
for(;i<2;i++) {
base=*save;
slot=base+off;
if(*(u32 *)(slot+0x40)!=0x4645384AU) valid=0;
else if(*(u32 *)(slot+0x44)!=0x20050201U) valid=0;
else valid=1;
if(valid && Save_FindLinkedSlot(base,slot[0x63])) return slot;
off+=0x6000;
}
return 0;
}
#pragma global_optimizer off
void fn_801E080C(void *arg0) {
extern u8 gSystemSave[];
u8 **save=(u8 **)arg0;
save[1]=Save_FindLinkedHeader(save);
gSystemSave[0x47]=save[1][0x63];
}
#pragma cplusplus on
#pragma global_optimizer off
void *fn_801E09B4(u8 **save) {
u8 *slot;
s32 off;
u8 *base;
s32 i;
u8 valid;
i=0; off=0x1a000;
for(;i<2;i++) {
base=*save;
slot=base+off;
if(*(u32 *)(slot+0x40)!=0x4645384AU) valid=0;
else if(*(u32 *)(slot+0x44)!=0x20050201U) valid=0;
else valid=1;
if(valid && Save_FindLinkedSlot(base,slot[0x63])) return slot;
off+=0x6000;
}
return 0;
}
#pragma global_optimizer reset
#pragma cplusplus reset
void fn_801E0B48(s32 unused, s32 arg1, s32 arg2, s32 arg3) {
    void *Process_CreateChild(void *, s32);
    extern u8 lbl_80299ED8[];
    void *obj;

    obj = Process_CreateChild(lbl_80299ED8, arg3);
    *(s32 *)((u8 *)obj + 0x60) = arg1;
    *(s32 *)((u8 *)obj + 0x64) = arg2;
}

void fn_801E0B94(void *arg0) {
    s32 fn_80211690();
    u16 fn_802072A0();
    u64 time;
    s8 lang;
    u8 *p = *(u8 **)((u8 *)arg0 + 0x54);
    u32 add;
    memset(p, 0, 0x2000);
    *(u32 *)(p+0x70)=0x53595346;
    *(u32 *)(p+0x74)=0x20050201;
    time=0;
    fn_8021D614(0,(s32 *)&time,0x20050201);
    time += OSGetTime();
    add=fn_80211690()*123;
    time += add;
    *(u64 *)(p+0x78)=time;
    *(u16 *)(p+0x80)=0;
    p[0xB0]=0; p[0xB1]=0; p[0xB2]=0x40; p[0xB3]=0;
    if (fn_802072A0()==1) lang=0;
    else switch((s32)fn_80209A0C()) {
    case 0: lang=1; break; case 1: lang=2; break; case 2: lang=3; break;
    case 3: lang=4; break; case 4: lang=5; break; case 5: lang=1; break;
    }
    p[0xB4]=lang; p[0xB7]=0;
    memset(p+0x82,0,0x1E); memset(p+0xB5,0,2);
    *(u32 *)(p+0xAC)=0; *(u32 *)(p+0xA8)=0; *(u32 *)(p+0xA4)=0; *(u32 *)(p+0xA0)=0;
    *(u32 *)(p+0x40)=0; *(u32 *)(p+0x48)=1;
}

void fn_801E0D30(void *arg0) {
    u8 Card_CheckError(void);
    void fn_801E0D78(void *, void *, s32, s32);
    extern u16 gSaveDataBase;

    if (Card_CheckError() != 0) {
        return;
    }

    fn_801E0D78(&gSaveDataBase, arg0, *(s32 *) ((u8 *) arg0 + 0x60), *(s32 *) ((u8 *) arg0 + 0x64));
}

#pragma opt_strength_reduction off
void fn_801E0D78(void **arg0, void *arg1, s32 arg2, s32 arg3) {
    void fn_800062CC(void *, void *, s32);
    void fn_801E3CA8(void *);
    void Card_RequestWrite(void *, s32, s32, s32, void *);
    extern void *gSaveDataBase;

    s32 i;
    s32 off;
    s32 val;
    void *self;
    s32 ctr;
    u8 *found;
    u8 hdrOk;
    u8 *best;
    u32 minSize;
    u8 *slot;
    u32 clamped;
    s32 diff;

    i = 0;
    off = 0x2000;
    val = arg3;
    self = arg1;

    for (ctr = 2; ctr != 0; ctr--) {
        found = (u8 *)*arg0 + off;
        if (*(u32 *)(found + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(found + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk == 0) {
        } else if (arg2 != *(u8 *)(found + 0x62)) {
        } else {
            goto found_slot;
        }
        off += 0x4000;
        found = (u8 *)*arg0 + off;
        if (*(u32 *)(found + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(found + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk == 0) {
        } else if (arg2 != *(u8 *)(found + 0x62)) {
        } else {
            goto found_slot;
        }
        off += 0x4000;
        found = (u8 *)*arg0 + off;
        if (*(u32 *)(found + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(found + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk == 0) {
        } else if (arg2 != *(u8 *)(found + 0x62)) {
        } else {
            goto found_slot;
        }
        off += 0x4000;
        i += 2;
    }

    found = NULL;

found_slot:
    best = NULL;
    i = 0;
    minSize = (u32)-1;
    off = 0x2000;
    for (ctr = 3; ctr != 0; ctr--) {
        slot = (u8 *)*arg0 + off;
        if (*(u32 *)(slot + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(slot + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk == 0) {
            clamped = save_slot_size(slot);
            if (minSize > clamped) {
                best = slot;
                minSize = save_slot_size(slot);
            }
        }
        off += 0x4000;
        slot = (u8 *)*arg0 + off;
        if (*(u32 *)(slot + 0x40) != 0x4645384AU) {
            hdrOk = 0;
        } else if (*(u32 *)(slot + 0x44) != 0x20050201U) {
            hdrOk = 0;
        } else {
            hdrOk = 1;
        }
        if (hdrOk == 0) {
            clamped = save_slot_size(slot);
            if (minSize > clamped) {
                best = slot;
                minSize = save_slot_size(slot);
            }
        }
        off += 0x4000;
        i += 1;
    }

    fn_800062CC(best, found, *(s32 *)(found + 0x4C));
    *(u8 *)(best + 0x62) = (u8)val;
    fn_801E3CA8(best);
    diff = (s32)best - (s32)gSaveDataBase;
    Card_RequestWrite(best, *(s32 *)(best + 0x4C), diff, diff, self);
    *(void **)((u8 *)self + 0x54) = best;
}

#pragma global_optimizer off
#pragma opt_strength_reduction off
void fn_801E1018(u8 **arg0, s32 arg1, void *arg2) {
    void *Process_CreateChild(void *, void *);
    extern u8 lbl_80299E9C[];
    s32 i;
    s32 off;
    s32 ctr;
    u8 *slot;
    u8 valid;
    void *proc;

    i = 0;
    off = 0x2000;

    for (ctr = 2; ctr != 0; ctr--) {
        slot = *arg0 + off;
        if (*(u32 *)(slot + 0x40) != 0x4645384AU) {
            valid = 0;
        } else if (*(u32 *)(slot + 0x44) != 0x20050201U) {
            valid = 0;
        } else {
            valid = 1;
        }
        if (valid && arg1 == *(u8 *)(slot + 0x62))
            goto create;
        off += 0x4000;
        slot = *arg0 + off;
        if (*(u32 *)(slot + 0x40) != 0x4645384AU) {
            valid = 0;
        } else if (*(u32 *)(slot + 0x44) != 0x20050201U) {
            valid = 0;
        } else {
            valid = 1;
        }
        if (valid && arg1 == *(u8 *)(slot + 0x62))
            goto create;
        off += 0x4000;
        slot = *arg0 + off;
        if (*(u32 *)(slot + 0x40) != 0x4645384AU) {
            valid = 0;
        } else if (*(u32 *)(slot + 0x44) != 0x20050201U) {
            valid = 0;
        } else {
            valid = 1;
        }
        if (valid && arg1 == *(u8 *)(slot + 0x62))
            goto create;
        off += 0x4000;
        i += 2;
    }
create:
    proc = Process_CreateChild(lbl_80299E9C, arg2);
    *(s32 *)((u8 *)proc + 0x60) = arg1;
}
#pragma opt_strength_reduction reset
#pragma global_optimizer on
void fn_801E1168(void *arg0) {
    u8 Card_CheckError(void);
    void fn_801E11AC(void *, void *, s32);
    extern u16 gSaveDataBase[4];

    if (Card_CheckError() != 0) {
        return;
    }

    fn_801E11AC(gSaveDataBase, arg0, *(s32 *) ((u8 *) arg0 + 0x60));
}

#pragma opt_strength_reduction off
