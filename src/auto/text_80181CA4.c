#include "common.h"
#pragma cplusplus on
struct UiAnimatedSprite {
    virtual void m08(); virtual void m0C(); virtual void m10();
    virtual s32 getTexId();
    virtual s16 getUvW(); virtual s16 getUvH();
    virtual s16 getW(); virtual s16 getH();
    virtual void m28(); virtual void m2C();
    virtual void draw(s32, s32, f32, f32, f32);
    u32 unk4;
    s32 direction;
    u8 visible, moving;
    s16 x, y, z, frame, movement;
};
struct LensFlareView {
    u8 pad[0x40];
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void setPosition(f32, f32, f32);
    virtual void setPoint(s32 *);
    virtual void setScreen(s32, s32);
    virtual void v10();
    virtual void setColor(u8, u8, u8, u8);
};
struct LensFlareOwner {
    u8 pad[0x10];
    virtual void v0(); virtual void v1();
    virtual LensFlareView *find(char *, char *);
};
struct CursorRenderView {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void update(void *);
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13();
    virtual void drawRow(s32, s16, s16, s16, u8);
};
struct ItemCursorView {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8();
    virtual s32 getRowOffset();
};
struct UnitPanelView {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10();
    virtual void setUnit(u32);
};
#pragma cplusplus reset
#pragma opt_common_subs off
static inline void init_761F8_base(void *p,s16 x,s16 y,s16 w,s16 h,s16 style) {
 extern u16 lbl_8028FDB0[],lbl_80292230[];
 extern f32 gF32_1;
 f32 zero;
 M2C_FIELD(p,void * *,0)=lbl_8028FDB0; M2C_FIELD(p,s32 *,4)=0; M2C_FIELD(p,void * *,0)=lbl_80292230; M2C_FIELD(p,s16 *,8)=-1;M2C_FIELD(p,s16 *,10)=x;
M2C_FIELD(p,s16 *,12)=y;
M2C_FIELD(p,s16 *,14)=x+w;
M2C_FIELD(p,s16 *,16)=y+h;
M2C_FIELD(p,s16 *,18)=0;
M2C_FIELD(p,s16 *,20)=0;
M2C_FIELD(p,s16 *,22)=w;
M2C_FIELD(p,s16 *,24)=h;
M2C_FIELD(p,s16 *,26)=0;
M2C_FIELD(p,s16 *,28)=0;M2C_FIELD(p,u8 *,30)=0xFF;
M2C_FIELD(p,u8 *,31)=0xFF;
M2C_FIELD(p,u8 *,32)=0xFF;
M2C_FIELD(p,u8 *,33)=0xFF;M2C_FIELD(p,s16 *,0x22)=style; M2C_FIELD(p,s16 *,0x24)=0;
 zero=gF32_1; M2C_FIELD(p,f32 *,0x28)=zero; M2C_FIELD(p,f32 *,0x2C)=zero; M2C_FIELD(p,f32 *,0x30)=zero;
 M2C_FIELD(p,s32 *,0x34)=0; M2C_FIELD(p,s32 *,0x38)=0;
 
}
#pragma opt_common_subs on
extern u32 gUiContext[];
extern u16 gUiMsgStrings[];
void fn_8006D8E8(void *);
extern u16 gUiListPanelProc[];

typedef struct Unk8016F694_Inner {
    u8 pad0[0x4C];
    s16 field4C;
} Unk8016F694_Inner;

typedef struct Unk8016F694_Outer {
    u8 pad0[0x44];
    void *ptr44;
    u8 pad1[0x4C - 0x44 - 4];
    Unk8016F694_Inner *inner;
} Unk8016F694_Outer;
extern u8 gBattleState[];
  extern void *lbl_803680E8;
  extern f32 lbl_8036AC2C;
extern f32 lbl_8036AC30;
extern f32 lbl_8036AC34;
extern f32 lbl_8036AC40;
extern f32 lbl_8036AC48;
extern f32 lbl_8036AC5C;
extern f32 lbl_8036AC60;
extern f32 lbl_8036AC64;
extern f32 lbl_8036AC68;
extern f32 lbl_8036AC6C;
extern f32 lbl_8036AC70;
extern f32 lbl_8036AC74;
extern f32 lbl_8036AC78;
extern f32 lbl_8036AB94;
extern u16 gUiListPanelProc[];
extern u16 E_FloatAnim_script[10];
extern f32 lbl_8036ABB0;
extern f32 lbl_8036ABBC;
extern f32 lbl_8036ABA0;
extern f32 lbl_8036A9C0;

extern u8 gUnits[];

static inline u8 IsSlotFilled(void *obj, s16 slot) {
    u32 *Unit_GetItemSlot(s32, s32);
    s32 idx = slot;
    u32 *item = Unit_GetItemSlot(M2C_FIELD(obj, s32 *, 0x58), idx);

    if (M2C_FIELD(obj, s32 *, 0x5C) == 1 && *item == 0) {
        if (slot == 0 || slot == 4 || *Unit_GetItemSlot(M2C_FIELD(obj, s32 *, 0x58), idx - 1) != 0) {
            return 1;
        }
    }
    return *item != 0;
}

static inline u8 IsSlotAvailable(void *obj, s16 slot) {
    if (slot >= 0 && slot <= 3 && !(M2C_FIELD(obj, s32 *, 0x60) & 1)) {
        return 0;
    }
    if (slot >= 4 && slot <= 7 && !(M2C_FIELD(obj, s32 *, 0x60) & 2)) {
        return 0;
    }
    return IsSlotFilled(obj, slot);
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
#pragma opt_peephole off

#pragma opt_peephole reset
#pragma global_optimizer reset
#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on
#pragma global_optimizer off
#pragma cplusplus on

#pragma cplusplus reset
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma global_optimizer off

#pragma global_optimizer on

/* First empty item slot in the range selected by inv+0x60&3 (1:0-3, 2:4-7, 3:0-7), or -1. */

#pragma scheduling reset
/* Find the next filled inventory slot at or below startSlot, or -1 if none. */

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus on

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus reset

#pragma use_lmw_stmw on
#pragma global_optimizer off
/* Construct a BattleTerrain: base strings, load map path, parse param.dbx room/foot fields. */

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw reset

#pragma cplusplus on
#pragma global_optimizer off
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma global_optimizer reset
#pragma cplusplus reset
extern u16 lbl_8028DED0[];

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on

#pragma dont_inline on

#pragma dont_inline reset

#pragma use_lmw_stmw reset

#pragma opt_common_subs off

#pragma opt_common_subs reset

#pragma cplusplus on
  extern "C" void *fn_8016915C(void *, s16, s16, s16, s16);
  extern "C" u8 gUiPanelVtbl[];

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus reset

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
/* Draw a centered menu-slot label and its selection frame. */

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus reset

extern u8 lbl_80294514[16];

extern u8 E_Jyokyo_script[16];

extern void fn_8005376C(void);
extern void FileCache_ReleaseSlot(void *);
extern void fn_800C4588(void);

#pragma global_optimizer off
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset
#pragma global_optimizer reset

/* One-shot E_Jyokyo teardown: clear map disp, refresh face, free nodes/cache, unlink process. */

#pragma global_optimizer off
#pragma opt_strength_reduction off
#pragma opt_common_subs off

#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
#pragma global_optimizer reset

#pragma use_lmw_stmw off

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw reset
#pragma global_optimizer on
/* Draw the fullscreen map overlay: dim backdrop, then map and unit markers. */

#pragma use_lmw_stmw off
#pragma global_optimizer off

#pragma global_optimizer on

#pragma cplusplus on
/* Release a list panel's seven child refs and destroy the panel base. */

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

/* Pop a nested UI menu: rebuild the parent list, retreat a step, restore MU blend and portrait, then clear this process. */

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma cplusplus on

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on
/* Tick map-cursor unit-info: follow the hovered unit and handle A/B/X popup input. */

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus reset

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma use_lmw_stmw on
#pragma cplusplus on
/* Handle unit-list pad input: help text, unit-info popup, confirm/cancel, and back. */

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on

#pragma cplusplus reset
#pragma opt_common_subs on

/* Slide the unit list back on, reset the inventory panel, slide detail widget 0x107 off, dismiss 0x106, and raise the inventory. */

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus off

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset

/* Bring the unit inventory forward for taking the selected list item, limiting slots by item flags. */

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma use_lmw_stmw on
#pragma cplusplus on
/* Handle A/B/X/Y while choosing a trade partner from the unit list. */

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma dont_inline on
#pragma global_optimizer off
#pragma cplusplus on

#pragma cplusplus reset
#pragma global_optimizer reset
#pragma dont_inline reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus reset

#pragma opt_common_subs on
#pragma global_optimizer on

#pragma cplusplus on
extern "C" void Ui_DrawListWindowFrame(s32, s32, s32, s16, s32, s32);
extern "C" void Ui_DrawLine(s32, s32, s16, s32, s32, void *);
extern "C" s32 Prim2D_SetAlphaByte(u8);
/* Draw a list panel's window chrome and a faint horizontal separator above the footer. */

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

extern u16 gUiMsgStrings[257];

/* If entry type is 2, show a lock-message popup at parent+entry pos; else set UI command 0x87. */

#pragma use_lmw_stmw on
#pragma cplusplus on
/* Draw a centered UI slot label, with optional leading icon. */

#pragma cplusplus reset

/* If the menu entry is locked, show a popup; otherwise set UI command 0x86. */

/* If the menu entry is locked, show a popup; otherwise set UI command 0x85 and advance the list panel. */

/* If the menu entry is locked, show a popup; otherwise open the list panel. */

/* If the list option is disabled (state 2), show a help popup for the selected submenu index; otherwise set UI command 0x83 and advance the list panel. */

#pragma opt_strength_reduction off

/* If the menu entry is locked, show a popup; otherwise set UI command 0x82. */

#pragma opt_strength_reduction reset

#pragma opt_peephole off

#pragma opt_peephole reset
/* If entry type is 2, show a lock-message popup at parent+entry pos; else set UI command 0x81. */

/* If the menu entry is locked, show a popup; otherwise set UI command 0x80. */

#pragma cplusplus on

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus on
/* Space each child gfx ent evenly across parent width (v18); y = 0. */

#pragma cplusplus reset
extern "C" M2C_UNK Prim2D_SetTransform(f32, f32, f32, f32);
extern "C" M2C_UNK Prim2D_SetColorByte(u8);
extern "C" M2C_UNK Prim2D_SetAlphaByte(u8);

#pragma cplusplus on

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset
/* Move a horizontal UI row cursor with left/right, refresh unit-info text, and focus/unfocus slots. */

#pragma cplusplus reset

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on

#pragma cplusplus reset

static inline void Stream_InitBase(void *self) {
    extern u8 gStreamBaseVtbl[];
    *(void **)((u8 *)self + 0x10) = gStreamBaseVtbl;
    *(s32 *)((u8 *)self + 4) = 0;
    *(s32 *)self = 0;
    *(s32 *)((u8 *)self + 8) = 0;
    *(u8 *)((u8 *)self + 0xC) = 0;
}
#pragma cplusplus on

#pragma cplusplus off

#pragma cplusplus on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma cplusplus on
#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer on
#pragma cplusplus reset

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset

s32 Status_SumBonus(void *);
#pragma cplusplus on
extern "C" void Ui_DrawJobPersonalPanel(s16, s16, s16, s16, s32, s32, s32, f32);

#pragma cplusplus reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma scheduling off

#pragma scheduling on
#pragma cplusplus off

#pragma global_optimizer off

#pragma global_optimizer on

#pragma global_optimizer off

#pragma global_optimizer on

#pragma dont_inline on
#pragma global_optimizer off
#pragma optimization_level 3
#pragma cplusplus on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma cplusplus reset
#pragma optimization_level reset
#pragma global_optimizer reset
#pragma dont_inline reset

#pragma scheduling on

#pragma scheduling reset

/* Gold cost for qty after base calc, status 0x4B markup (*10/7), and 0xB half-price. */

#pragma cplusplus on

#pragma cplusplus reset

#pragma cplusplus on
/* Draw a UI sprite quad with frame UVs, color, and optional UV rotation. */

#pragma cplusplus reset

#pragma opt_strength_reduction off
/* Start a process that lerps target's float at +4 by amount (duration from amount). */

#pragma opt_strength_reduction reset

/* Advance FloatAnim: tick, lerp target's float at +4, play rise SE on odd frames, clear when duration elapses. */

#pragma global_optimizer off

#pragma global_optimizer on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw off
#pragma peephole off
#pragma cplusplus on

#pragma cplusplus reset
#pragma peephole reset
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma use_lmw_stmw on
#pragma cplusplus on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
#pragma cplusplus on

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on

#pragma cplusplus reset
/* Create the unit-info title (id 0x80) and caption (id -0x1000) widgets and attach them to parent. */

#pragma opt_common_subs off

#pragma cplusplus on

#pragma use_lmw_stmw on

#pragma cplusplus reset

#pragma cplusplus on
extern "C" s32 Unit_GetSupportRankTotal(s32, s16);
extern "C" void fn_80157700(s32, s16, u8, s32);
extern "C" void fn_80157930(s32, s32, s16, s16, s32, s32);

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma cplusplus reset

#pragma scheduling on
#pragma peephole on

#pragma scheduling reset
#pragma peephole reset
typedef struct ListNode {
    struct ListNode *prev;
    struct ListNode *next;
} ListNode;

typedef struct List {
    u32 unk0;
    ListNode node;
} List;

typedef struct ListOwner {
    void *vtbl;
    u8 pad4[0x58];
    List list;
} ListOwner;

ListOwner *fn_80181CA4(ListOwner *arg0, s16 arg1) {
    M2C_UNK fn_8013F2A4(void *, s32);
    M2C_UNK Heap_Free(void *);
    M2C_UNK List_EraseRange(void *, List *, ListNode **, ListNode **);
    extern u8 lbl_802956B8[];
    ListNode *sp10;
    ListNode *spC;
    u8 sp8[4];
    ListNode *end;

    if (arg0 != NULL) {
        arg0->vtbl = lbl_802956B8;
        if (&arg0->list != NULL) {
            if (&arg0->list != NULL) {
                if (&arg0->list != NULL) {
                    end = &arg0->list.node;
                    sp10 = end;
                    spC = end->next;
                    List_EraseRange(sp8, &arg0->list, &spC, &sp10);
                }
            }
        }
        fn_8013F2A4(arg0, 0);
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void fn_80181D44(void *arg0) {
    s16 height, width;
    s32 bottom, right;
    s16 *p = (s16 *)arg0;
    height = p[0x10 / 2] - p[0xC / 2];
    width = p[0xE / 2] - p[0xA / 2];
    bottom = height - 5;
    right = width - 3;
    p[0x12 / 2] = 3;
    p[0x14 / 2] = 5;
    p[0x16 / 2] = right;
    p[0x18 / 2] = bottom;
}

#pragma cplusplus on
extern "C" void *fn_80181D88(void *arg0) {
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
    void fn_8016915C(void *);
    extern u8 gUiPanelBVtbl[];

    fn_8016915C(arg0);
    *(void **)arg0 = gUiPanelBVtbl;
    ((Obj *)arg0)->m28();
    return arg0;
}
#pragma cplusplus reset

s32 fn_80181DD8(void *arg0) {
    return *(s32 *)(*(u8 **)((u8 *)arg0 + 0x188) + 0x50) != 0;
}

#pragma use_lmw_stmw on
void fn_80181DF0(s32 *arg0, void **arg1) {
    void *Unit_FindByPerson(void *);
    s32 Unit_FindSupportPartnerIndex(void *, void *);
    s32 Unit_GetSupportRank(void *, s32);
    u8 fn_80036FC4(void *, s32);
    void Heap_Free(void *);
    void fn_8018212C(s32 *, s32 *, void **);
    void *sp1C;
    void *sp18;
    s32 sp14;
    void *sp10;
    void *spC;
    void *sp8;
    void **node;
    void **node2;
    void *idNode;
    void *idNode2;
    void *unitNode2;
    void *unitNode;
    s32 sNode2;
    s32 sNode;
    u8 t;
    u8 swap;
    u8 c0;
    u32 half;
    u32 n;
    void **it;
    void **left;
    void *tmp;
    s32 cnt;

    cnt = *arg0;
    if (cnt != 2) {
        if (cnt >= 2) {
            goto split;
        }
        if (cnt >= 0) {
            return;
        }
        goto split;
    }
    node = (void **)arg0[2];
    node2 = (void **)node[1];
    idNode = node[2];
    idNode2 = node2[2];
    unitNode2 = Unit_FindByPerson(idNode2);
    unitNode = Unit_FindByPerson(idNode);
    if (unitNode2 != 0) {
        t = *(u8 *)(*(u8 **)((u8 *)unitNode2 + 0x190) + 8);
        if (t != 0 && t != 5 && t != 6 && t != 7) {
            unitNode2 = 0;
        }
    }
    if (unitNode != 0) {
        t = *(u8 *)(*(u8 **)((u8 *)unitNode + 0x190) + 8);
        if (t != 0 && t != 5 && t != 6 && t != 7) {
            unitNode = 0;
        }
    }
    if (unitNode2 == 0 && unitNode == 0) {
        swap = 1;
    } else if (unitNode2 == 0) {
        swap = 0;
    } else if (unitNode == 0) {
        swap = 1;
    } else {
        sNode2 = Unit_FindSupportPartnerIndex(*arg1, idNode2);
        sNode = Unit_FindSupportPartnerIndex(*arg1, idNode);
        sNode = (s8)sNode;
        sNode2 = (s8)sNode2;
        c0 = (u8)Unit_GetSupportRank(*arg1, sNode);
        if ((u8)Unit_GetSupportRank(*arg1, sNode2) != c0) {
            c0 = (u8)Unit_GetSupportRank(*arg1, sNode);
            swap = (c0 <= (u8)Unit_GetSupportRank(*arg1, sNode2));
        } else {
            c0 = fn_80036FC4(*arg1, sNode);
            swap = (c0 <= fn_80036FC4(*arg1, sNode2));
        }
    }
    if (swap) {
        tmp = node[0];
        node[0] = node[1];
        node[1] = tmp;
        tmp = node2[0];
        node2[0] = node2[1];
        node2[1] = tmp;
        tmp = (void *)arg0[1];
        arg0[1] = arg0[2];
        arg0[2] = (s32)tmp;
    }
    return;

split:
    half = (u32)cnt >> 1;
    it = (void **)arg0[2];
    if (half != 0) {
        n = half >> 3;
        if (n != 0) {
            do {
                it = (void **)it[1];
                it = (void **)it[1];
                it = (void **)it[1];
                it = (void **)it[1];
                it = (void **)it[1];
                it = (void **)it[1];
                it = (void **)it[1];
                it = (void **)it[1];
            } while (--n);
        }
        n = half & 7;
        if (n != 0) {
            do {
                it = (void **)it[1];
            } while (--n);
        }
    }
    sp14 = 0;
    sp1C = (void *)&sp18;
    sp18 = (void *)&sp18;
    left = (void **)arg0[1];
    ((void **)it[0])[1] = left[1];
    *(void **)left[1] = it[0];
    ((void **)sp18)[1] = it;
    it[0] = sp18;
    sp18 = (void *)left;
    left[1] = &sp18;
    sp14 = *arg0 - (s32)half;
    *arg0 = (s32)half;
    sp10 = *arg1;
    fn_80181DF0(arg0, &sp10);
    spC = *arg1;
    fn_80181DF0(&sp14, &spC);
    sp8 = *arg1;
    fn_8018212C(arg0, &sp14, &sp8);
    unitNode2 = sp1C;
    if (unitNode2 != (void *)&sp18) {
        ((void **)((void **)unitNode2)[0])[1] = ((void **)sp18)[1];
        *(void **)((void **)sp18)[1] = ((void **)unitNode2)[0];
        do {
            tmp = unitNode2;
            unitNode2 = ((void **)unitNode2)[1];
            Heap_Free(tmp);
            sp14 -= 1;
        } while (unitNode2 != (void *)&sp18);
    }
}

#pragma use_lmw_stmw on
void fn_8018212C(s32 *arg0, s32 *arg1, void **arg2) {
    void *Unit_FindByPerson(void *);
    s32 Unit_FindSupportPartnerIndex(void *, void *);
    s32 Unit_GetSupportRank(void *, s32);
    u8 fn_80036FC4(void *, s32);
    void fn_80182514(s32 *, void **, s32 *);

    void *sp8;
    void **node;
    void **node2;
    void *sentinel2;
    void *sentinel1;
    void *id2;
    void *id1;
    void *unit2;
    void *unit1;
    u8 t;
    u8 take;
    s32 s2;
    s32 s1;
    s8 ss2;
    s8 ss1;
    u8 c0;
    u8 c1;
    void **walk;
    s32 count;
    void *link;

    if (arg0 == arg1) {
        return;
    }
    node = (void **)arg0[2];
    sentinel1 = (void *)(arg0 + 1);
    node2 = (void **)arg1[2];
    sentinel2 = (void *)(arg1 + 1);
    while (node != sentinel1 && node2 != sentinel2) {
        id2 = node2[2];
        id1 = node[2];
        unit2 = Unit_FindByPerson(id2);
        unit1 = Unit_FindByPerson(id1);
        if (unit2 != NULL) {
            t = *(u8 *)(*(u8 **)((u8 *)unit2 + 0x190) + 8);
            if (t != 0 && t != 5 && t != 6 && t != 7) {
                unit2 = NULL;
            }
        }
        if (unit1 != NULL) {
            t = *(u8 *)(*(u8 **)((u8 *)unit1 + 0x190) + 8);
            if (t != 0 && t != 5 && t != 6 && t != 7) {
                unit1 = NULL;
            }
        }
        if (unit2 == NULL && unit1 == NULL) {
            take = 1;
        } else if (unit2 == NULL) {
            take = 0;
        } else if (unit1 == NULL) {
            take = 1;
        } else {
            s2 = Unit_FindSupportPartnerIndex(*arg2, id2);
            s1 = Unit_FindSupportPartnerIndex(*arg2, id1);
            ss1 = (s8)s1;
            c0 = (u8)Unit_GetSupportRank(*arg2, ss1);
            ss2 = (s8)s2;
            c1 = (u8)Unit_GetSupportRank(*arg2, ss2);
            if (c1 != c0) {
                c0 = (u8)Unit_GetSupportRank(*arg2, ss1);
                take = (c0 <= (u8)Unit_GetSupportRank(*arg2, ss2));
            } else {
                c0 = fn_80036FC4(*arg2, ss1);
                take = (c0 <= fn_80036FC4(*arg2, ss2));
            }
        }
        if (take != 0) {
            walk = (void **)node2[1];
            count = 1;
            while (walk != sentinel2) {
                id2 = walk[2];
                id1 = node[2];
                unit2 = Unit_FindByPerson(id2);
                unit1 = Unit_FindByPerson(id1);
                if (unit2 != NULL) {
                    t = *(u8 *)(*(u8 **)((u8 *)unit2 + 0x190) + 8);
                    if (t != 0 && t != 5 && t != 6 && t != 7) {
                        unit2 = NULL;
                    }
                }
                if (unit1 != NULL) {
                    t = *(u8 *)(*(u8 **)((u8 *)unit1 + 0x190) + 8);
                    if (t != 0 && t != 5 && t != 6 && t != 7) {
                        unit1 = NULL;
                    }
                }
                if (unit2 == NULL && unit1 == NULL) {
                    take = 1;
                } else if (unit2 == NULL) {
                    take = 0;
                } else if (unit1 == NULL) {
                    take = 1;
                } else {
                    s2 = Unit_FindSupportPartnerIndex(*arg2, id2);
                    s1 = Unit_FindSupportPartnerIndex(*arg2, id1);
                    ss1 = (s8)s1;
                    c0 = (u8)Unit_GetSupportRank(*arg2, ss1);
                    ss2 = (s8)s2;
                    c1 = (u8)Unit_GetSupportRank(*arg2, ss2);
                    if (c1 != c0) {
                        c0 = (u8)Unit_GetSupportRank(*arg2, ss1);
                        take = (c0 <= (u8)Unit_GetSupportRank(*arg2, ss2));
                    } else {
                        c0 = fn_80036FC4(*arg2, ss1);
                        take = (c0 <= fn_80036FC4(*arg2, ss2));
                    }
                }
                if (take == 0) {
                    break;
                }
                walk = (void **)walk[1];
                count += 1;
            }
            link = walk[0];
            ((void **)((void **)node2[0])[1])[0] = ((void **)link)[1];
            *(void **)((void **)link)[1] = node2[0];
            ((void **)node[0])[1] = node2;
            node2[0] = node[0];
            node2 = walk;
            node[0] = link;
            ((void **)link)[1] = node;
            *arg1 -= count;
            *arg0 += count;
        }
        node = (void **)node[1];
    }
    if (node2 != sentinel2) {
        sp8 = node;
        fn_80182514(arg0, &sp8, arg1);
    }
}

#pragma use_lmw_stmw reset

void fn_80182514(u32 *arg0, ListNode **arg1, List *arg2)
{
    ListNode *list;
    ListNode *sentinel;
    ListNode *next;
    ListNode *prev;

    if (*(u32 *)arg2 == 0) {
        return;
    }

    sentinel = (ListNode *)((u8 *)arg2 + 4);
    list = *arg1;
    next = sentinel->next;
    prev = sentinel->prev;

    sentinel->next = sentinel;
    sentinel->prev = sentinel;

    list->prev->next = next;
    next->prev = list->prev;
    list->prev = prev;
    prev->next = list;

    *arg0 = *arg0 + *(u32 *)arg2;
    *(u32 *)arg2 = 0;
}

#pragma opt_common_subs reset
s32 Ai_BehaviorNop(void) {
    return 1;
}

s32 Ai_TryHandleLowHpHeal(s32 unit) {
    /* When low-HP and no hostile staff action: try heal item, seek healer, or approach safety. */
    void fn_8010AC58(s32);
    u8 Ai_TryApproachHealer(s32);
    u8 Ai_TrySelectApproachTile(s32);
    u8 Ai_TrySeekHealTerrain(s32);
    u8 Ai_TrySeekHealer(s32);
    u8 Ai_TryUseHealItem(s32);
    u8 Unit_HasLowHpAi(s32);
    u8 Unit_IsLowHp(s32);
    u8 fn_8010F670(s32, void *);
    s32 Ai_UnitIsHostileToActive(void *);
    extern u8 gAiState[];
    if ((*(u8 *)(gAiState + 1) & 4) != 0) {
        return 1;
    }
    if ((fn_8010F670(unit, Ai_UnitIsHostileToActive) == 0) && (Unit_HasLowHpAi(unit) != 0) && (Unit_IsLowHp(unit) != 0)) {
        if (Ai_TryUseHealItem(unit) != 0) {
            return 1;
        }
        if (Ai_TrySeekHealer(unit) != 0) {
            return 1;
        }
        if (Ai_TrySeekHealTerrain(unit) != 0) {
            fn_8010AC58(unit);
        } else if (Ai_TrySelectApproachTile(unit) != 0) {
            fn_8010AC58(unit);
        } else if (Ai_TryApproachHealer(unit) != 0) {
            fn_8010AC58(unit);
        }
        goto block_15;
    }
block_15:
    return 1;
}

s32 Ai_TryMoveToSeekTile(void *arg0) {
    void fn_800FB96C(s32, s8, s8, s32, s8, s8, s32, s32, s32);
    u8 fn_801025BC(void *, s16 *, s16 *);
    extern u8 gAiState[];
    s16 sp12;
    s16 sp10;

    if ((gAiState[1] & 2) || (*(s32 *)((char *)arg0 + 0x254) & 0x03000000)) {
        return 0;
    }
    if (fn_801025BC(arg0, &sp12, &sp10) == 1) {
        fn_800FB96C(1, (s8)sp12, (s8)sp10, 0, (s8)sp12, (s8)sp10, -1, 0, 0);
    }
    return 1;
}

s32 Ai_TryMoveToFactionPos(void *arg0) {
    struct Obj {
        u8 pad0[0x236];
        u8 unk236;
        u8 pad237[0x254 - 0x237];
        u32 unk254;
    };
    s8 fn_80017290(u8 *);
    s8 fn_800172D4(u8 *);
    u8 fn_800BE968(u8, u8, u8);
    void Ai_SetUnitMoveTo(void *, s16, s16, s32, u16, s32, s32, s32);
    void fn_80101448(void *, s16, s16, s32, u16, s32, s32, s32);
    extern u8 gAiState[];
    struct Obj *p = (struct Obj *)arg0;
    s8 temp_r30;
    s8 temp_r3;

    temp_r30 = fn_80017290(&p->unk236);
    temp_r3 = fn_800172D4(&p->unk236);
    if ((gAiState[1] & 2) || (p->unk254 & 0x03000000)) {
        return 0;
    }
    Ai_SetUnitMoveTo(p, temp_r3, temp_r30, 1, 0xFFFF, 1, 0, -1);
    if (gAiState[0x21C] == 0) {
        fn_80101448(p, temp_r3, temp_r30, 1, 0xFFFF, 1, 0, -1);
    }
    if (gAiState[0x21C] != 0) {
        u8 d = ((u8 *)gUiContext)[0xD];
        if ((s8)fn_800172D4(&p->unk236) == (s8)d) {
            u8 e = ((u8 *)gUiContext)[0xE];
            if ((s8)fn_80017290(&p->unk236) == (s8)e) {
                if (fn_800BE968(0xE, ((u8 *)gUiContext)[0xD], ((u8 *)gUiContext)[0xE]) != 0) {
                    ((u8 *)gUiContext)[0x8] = 0xE;
                }
            }
        }
    }
    return 1;
}

#pragma opt_common_subs off
s32 Ai_TryReactToIkeStatus(void *arg0) {
    void *Unit_FindIke(u8 *);
    s8 fn_80017290(u8 *);
    s8 fn_800172D4(u8 *);
    u8 fn_800BE968(u8, u8, u8);
    void Ai_SetUnitMoveTo(void *, s16, s16, s32, u16, s32, s32, s32);
    void fn_80101448(void *, s16, s16, s32, u16, s32, s32, s32);
    extern u8 gAiState[];
    void *self;
    u8 *ai;
    s8 y;
    s8 x;
    void *ike;
    u32 flags;
    u8 tx;
    u8 ty;

    self = arg0;
    ike = Unit_FindIke((u8 *)self + 0x236);
    flags = *(u32 *)((u8 *)ike + 0x1A0);
    if (flags & 0x98) {
        *(s32 *)(gAiState + 8) = 1;
        return 0;
    }
    if (flags & 4) {
        *(s32 *)(gAiState + 8) = 4;
    }
    tx = ((u8 *)ike)[0x19E];
    ty = ((u8 *)ike)[0x19F];
    if ((gAiState[1] & 2) || (*(u32 *)((u8 *)self + 0x254) & 0x03000000)) {
        return 0;
    }
    x = tx;
    y = ty;
    Ai_SetUnitMoveTo(self, x, y, 1, 0xFFFF, 1, 0, -1);
    ai = gAiState;
    if (ai[0x21C] == 0) {
        fn_80101448(self, x, y, 1, 0xFFFF, 1, 0, -1);
    }
    if (ai[0x21C] != 0) {
        u8 d;
        u8 e;
        ai = (u8 *)gUiContext;
        d = ai[0xD];
        if ((s8)fn_800172D4((u8 *)self + 0x236) == (s8)d) {
            self = (u8 *)gUiContext;
            e = ((u8 *)self)[0xE];
            if ((s8)fn_80017290((u8 *)arg0 + 0x236) == (s8)e) {
                if (fn_800BE968(0xE, ai[0xD], ((u8 *)self)[0xE]) != 0) {
                    ((u8 *)gUiContext)[0x8] = 0xE;
                }
            }
        }
    }
    return 1;
}
#pragma opt_common_subs reset
s32 Ai_TryCombatFiltered(s32 arg0) {
    u8 Ai_TryAttackAction(u8 *, s32);
    void Ai_SetUnitMoveTo(s32, s16, s16, s32, u16, s32, s32, s32);
    u8 Ai_FindLowestCostUnitTile(u8 *, s32, s16 *, s16 *);
    u8 fn_8010F52C(s32, u8 *);
    u8 Ai_TryStealAction(s32, u8 *);
    extern u8 fn_80182C84[];
    s16 spA;
    s16 sp8;

    if ((fn_8010F52C(arg0, fn_80182C84) == 0) && (Ai_TryStealAction(arg0, fn_80182C84) == 0) && (Ai_TryAttackAction(fn_80182C84, 0xF) == 0) && (Ai_FindLowestCostUnitTile(fn_80182C84, arg0, &spA, &sp8) != 0)) {
        Ai_SetUnitMoveTo(arg0, spA, sp8, 1, 0xFFFF, 1, 0, -1);
    }
    return 1;
}

s32 Ai_TryCombatHostiles(s32 arg0) {
    u8 Ai_TryAttackAction(u8 *, s32);
    void Ai_SetUnitMoveTo(s32, s16, s16, s32, u16, s32, s32, s32);
    u8 Ai_FindLowestCostUnitTile(u8 *, s32, s16 *, s16 *);
    u8 fn_8010F52C(s32, u8 *);
    u8 Ai_TryStealAction(s32, u8 *);
    extern u8 Ai_UnitIsHostileToActive[];
    extern u8 fn_80182CE4[];
    s16 spA;
    s16 sp8;

    if ((fn_8010F52C(arg0, Ai_UnitIsHostileToActive) == 0) && (Ai_TryStealAction(arg0, Ai_UnitIsHostileToActive) == 0) && (Ai_TryAttackAction(fn_80182CE4, 0xF) == 0) && (Ai_FindLowestCostUnitTile(fn_80182CE4, arg0, &spA, &sp8) != 0)) {
        Ai_SetUnitMoveTo(arg0, spA, sp8, 1, 0xFFFF, 1, 0, -1);
    }
    return 1;
}

/* AI: approach Ike unless he has blocking flags; else store result code in gAiState. */
s32 Ai_TryApproachIke(s32 unit) {
    void *Unit_FindIke(s32);
    u8 Ai_TryAttackAction(u8 *, s32);
    void Ai_SetUnitMoveTo(s32, s16, s16, s32, u16, s32, s32, s32);
    u8 Ai_FindLowestCostUnitTile(u8 *, s32, s16 *, s16 *);
    u8 fn_8010F52C(s32, u8 *);
    u8 Ai_TryStealAction(s32, u8 *);
    extern u8 Ai_UnitIsIke[];
    extern u8 gAiState[];
    s16 x;
    s16 y;
    s32 flags;

    flags = *(s32 *)((u8 *)Unit_FindIke(unit + 0x236) + 0x1A0);
    if (flags & 0x98) {
        *(s32 *)(gAiState + 8) = 1;
        return 0;
    }
    if (flags & 4) {
        *(s32 *)(gAiState + 8) = 4;
        return 0;
    }
    if ((fn_8010F52C(unit, Ai_UnitIsIke) == 0) && (Ai_TryStealAction(unit, Ai_UnitIsIke) == 0) &&
        (Ai_TryAttackAction(Ai_UnitIsIke, 0xF) == 0) &&
        (Ai_FindLowestCostUnitTile(Ai_UnitIsIke, unit, &x, &y) != 0)) {
        Ai_SetUnitMoveTo(unit, x, y, 1, 0xFFFF, 1, 0, -1);
    }
    return 1;
}

s32 fn_80182C84(void *arg0) {
    extern u32 gUiContext[];
    u8 Allegiance_Compare(s32, s32);
    s32 Status_Test(void *, s32);
    void *other;

    other = (void *)gUiContext[0];
    if (Allegiance_Compare(*(s32 *)((u8 *)arg0 + 0x190), *(s32 *)((u8 *)other + 0x190)) == 1) {
        return Status_Test((u8 *)arg0 + 0x1BC, 6);
    }
    return 0;
}

#pragma opt_common_subs off
s32 fn_80182CE4(void *arg0) {
    u8 Allegiance_Compare(void *, void *);
    void **Unit_GetHeldItemSlot(void *, s32);
    s8 Unit_GetActiveItemSlot(void *);
    u8 fn_8009339C(void *, void *);
    s32 fn_8001D500(void *);
    void Battle_SetupFromParams(void *, void *, void *);
    void fn_801A6F34(void *, s32);
    extern u32 gUiContext[];
    extern u8 gBattle[];
    typedef struct Param {
        void *p;
        u8 b4[4];
        s32 x8;
        u8 bC[4];
    } Param;
    extern Param lbl_80278B98;
    extern Param lbl_80278BA8;
    Param sp18;
    Param sp8;
    s32 i;
    s32 bestScore;
    s8 bestSlot;
    void *uiUnit;
    void **slot;
    s32 score;

    uiUnit = (void *)gUiContext[0];
    if ((u8)Allegiance_Compare(*(void **)((u8 *)arg0 + 0x190), *(void **)((u8 *)uiUnit + 0x190)) != 1) {
        return 0;
    }

    bestScore = 0;
    bestSlot = -1;
    i = bestScore;
    sp18 = lbl_80278B98;
    sp18.p = uiUnit;
    sp18.b4[0] = ((u8 *)uiUnit)[0x19E];
    sp18.b4[1] = ((u8 *)uiUnit)[0x19F];

    for (; i < 4; i++) {
        slot = Unit_GetHeldItemSlot(uiUnit, i);
        if (*slot != NULL) {
            if ((u8)fn_8009339C(uiUnit, *slot) != 0) {
                if ((u8)bestScore < (u8)fn_8001D500(slot)) {
                    score = fn_8001D500(slot);
                    bestSlot = (s8)i;
                    bestScore = score;
                }
            }
        }
    }

    sp18.b4[2] = bestSlot;
    sp8 = lbl_80278BA8;
    sp8.p = arg0;
    sp8.b4[0] = ((u8 *)arg0)[0x19E];
    sp8.b4[1] = ((u8 *)arg0)[0x19F];
    sp8.b4[2] = Unit_GetActiveItemSlot(arg0);
    Battle_SetupFromParams(gBattle, &sp18, &sp8);
    fn_801A6F34(gBattle, 0xF);

    {
        s16 v2a2 = *(s16 *)(gBattle + 0x2A2);
        s32 diff = *(s16 *)(gBattle + 0x298) - *(s16 *)(gBattle + 0x57A);
        return (diff * (v2a2 != 0)) > 0;
    }
}
#pragma opt_common_subs reset
s32 Ai_UnitIsIke(s32 arg0) {
    s32 Unit_FindIke(void *);
    extern u32 gUiContext[];

    return arg0 == Unit_FindIke((u8 *)*(void **)gUiContext + 0x236);
}

void fn_80182EC8(s32 arg0) {
    void *Process_CreateChild(void *, s32);
    s32 BattleState_GetFactionInfo(void *, s32);
    extern u8 lbl_80295788[];
    void *temp_r31;
    s32 var_r3;

    if (((u8 *)gUiContext)[0x14] == 3) {
        temp_r31 = Process_CreateChild(lbl_80295788, arg0);
        if (((u8 *)gUiContext)[8] == 0x32) {
            var_r3 = BattleState_GetFactionInfo(gBattleState, 0);
        } else {
            var_r3 = BattleState_GetFactionInfo(gBattleState, 3);
        }
        *(s32 *)((u8 *)temp_r31 + 0x30) = var_r3;
    }
}

void fn_80182F50(void) {
    void BattleState_SetCamPos(void *, f32, f32);
    void Map_HideMoveLimitView();

    BattleState_SetCamPos(gBattleState, (f32) (s8) ((u8 *)gUiContext)[0xD], (f32) (s8) ((u8 *)gUiContext)[0xE]);
    Map_HideMoveLimitView();
}

void fn_80182FC4(void *arg0) {
    void *Map_GetCursorUnit(void);
    void Process_Goto(void *, s32);
    void Ui_PlaySeCue(void *, s32);
    void fn_8009197C(void);
    extern void *gPadInput;
    extern u8 gBattleState[];
    extern u8 gBattleMap[];
    extern u32 gUiContext[];
    extern u8 gMapUiResult;
    extern u8 lbl_80278BB8[];
    u32 curr;
    u32 edge;
    s32 xRaw;
    s32 yRaw;
    s8 x;
    s8 y;
    s8 *tilePtr;
    s8 tile;
    u8 *coords;
    s16 mapVal;
    u8 *mapHi;
    u8 *mapBase;
    u8 zero;

    curr = *(u32 *)((u8 *)gPadInput + 4);
    edge = curr & (*(u32 *)((u8 *)gPadInput + 8) ^ curr);
    Map_GetCursorUnit();
    xRaw = (s32)*(f32 *)(gBattleState + 0x524);
    mapBase = gBattleMap;
    yRaw = (s32)*(f32 *)(gBattleState + 0x528);
    mapHi = mapBase + 0x10000;
    x = (s8)xRaw;
    y = (s8)yRaw;
    tilePtr = (s8 *)(mapHi + x);
    tilePtr = (s8 *)((u8 *)tilePtr + (y << 6));
    tile = *(tilePtr -= 0x1E72);
    if (tile != 0 || (mapVal = ((s16 *)(mapBase + 0x610E))[x + (y << 6)]) < 0) {
        coords = *(u8 **)((u8 *)arg0 + 0x30);
        coords[0] = 0;
        goto after_coords;
    }
    coords = *(u8 **)((u8 *)arg0 + 0x30);
    coords[0] = 3;
    if ((s8)xRaw >= 0) {
        coords[2] = (u8)xRaw;
    }
    if ((s8)yRaw >= 0) {
        coords[3] = (u8)yRaw;
    }
after_coords:
    if (edge & 0x100) {
        if (*tilePtr == 0) {
            mapVal = ((s16 *)(gBattleMap + 0x610E))[x + (y << 6)];
            if (mapVal >= 0) {
                u8 *ui;
                zero = 0;
                ui = (u8 *)gUiContext;
                gMapUiResult = zero;
                ui[0xF] = (u8)xRaw;
                ui[0x10] = (u8)yRaw;
                Process_Goto(arg0, 0x63);
                Ui_PlaySeCue(lbl_80278BB8 + 0xCE, 0x64);
            }
        }
    } else if (edge & 0x200) {
        gMapUiResult = 9;
        ((u8 *)gUiContext)[8] = 0;
        fn_8009197C();
        coords = *(u8 **)((u8 *)arg0 + 0x30);
        coords[0] = ((u8 *)arg0)[0x34];
        coords[1] = ((u8 *)arg0)[0x35];
        coords[2] = ((u8 *)arg0)[0x36];
        coords[3] = ((u8 *)arg0)[0x37];
        Process_Goto(arg0, 0x63);
        Ui_PlaySeCue(lbl_80278BB8 + 0xDE, 0x64);
    }
}

#pragma global_optimizer off
void fn_80183184(void *arg0) {
    void Map_FillLayer(void *, s32, s32);
    void Map_SelectRangeBuffer(void *, s32);
    void *Job_GetByJid(void *);
    void fn_800227F8(void *, void *);
    void fn_80022748(void *, s32);
    void Map_FloodMoveRange(void *, u8, u8, u16, s32, s32);
    void Map_ShowMoveLimitView(void);
    void BattleState_SetCamPos(void *, f32, f32);
    extern u8 gBattleMap[];
    extern u8 gBattleState[];
    extern u8 lbl_80278BB8[];
    u8 *unit;
    u8 *coords;
    u8 y;
    u8 x;
    u8 camX;
    u8 camY;

    unit = *(u8 **)gUiContext;
    Map_FillLayer(gBattleMap, 8, 0);
    Map_SelectRangeBuffer(gBattleMap, 5);
    fn_800227F8(gBattleMap, Job_GetByJid(lbl_80278BB8 + 0xEE));
    fn_80022748(gBattleMap, 0);
    Map_FloodMoveRange(gBattleMap, unit[0x19E], unit[0x19F], 0xC8, 0, 0);
    Map_ShowMoveLimitView();

    coords = *(u8 **)((u8 *)arg0 + 0x30);
    ((u8 *)arg0)[0x34] = coords[0];
    ((u8 *)arg0)[0x35] = coords[1];
    ((u8 *)arg0)[0x36] = coords[2];
    ((u8 *)arg0)[0x37] = coords[3];

    coords = *(u8 **)((u8 *)arg0 + 0x30);
    x = coords[2];
    if ((s8)x < 0 || (y = coords[3], (s8)y < 0) ||
        ((s16 *)(gBattleMap + 0x610E))[(s8)x + ((s8)y << 6)] < 0) {
        camX = unit[0x19E];
        camY = unit[0x19F];
    } else {
        camX = x;
        camY = y;
    }
    BattleState_SetCamPos(gBattleState, (f32)(s8)camX, (f32)(s8)camY);
}
#pragma global_optimizer on
void fn_801832F8(s32 arg0) {
    void Msg_Expand(void *);
    void fn_80091A1C(void);
    void Ui_CreateMenu(void *, s32, s32);
    extern u8 lbl_803681F0;
    extern u8 lbl_80278BB8[440];
    extern u8 lbl_80368208[8];
    u8 val = *((u8 *)gUiContext + 8);

    lbl_803681F0 = val;
    if (val == 0x32) {
        Msg_Expand(&lbl_80278BB8[0xF8]);
        fn_80091A1C();
    } else {
        Msg_Expand(&lbl_80278BB8[0x102]);
        fn_80091A1C();
    }
    Ui_CreateMenu(lbl_80368208, arg0, 0);
}

#include "common.h"
extern u32 gUiContext[];
extern u16 gUiMsgStrings[];
extern u16 lbl_80294550[];
extern f32 lbl_8036AB94;
extern u16 lbl_80277EA0;
extern u16 lbl_80293D8C;
extern void *lbl_8028D9A4[];
extern u8 gItemFlagsDummyReady;
extern s32 gItemFlagsDummy;
extern s32 gItemFlagsDummyHi;
#include <common.h>
#include "global.h"


extern u16* gSomeBssVar; // gUiContext
#include "common.h"
#include "dolphin/os.h"
extern u16 lbl_80292230[];
extern u16 lbl_8028FDB0[];
extern u16 lbl_80292208[];
extern u16 lbl_80292488[];
extern f32 gF32_1;
extern f32 lbl_8036AB70;
#include "global.h"

extern f32 lbl_8036A9CC;
extern f32 gUiMenuSlotTextZ;
extern f32 gUiMenuSlotTextScale;
extern f32 gUiMenuSlotFrameZ;
extern f64 lbl_8036A9B8;
extern u16 lbl_80293BB8;

