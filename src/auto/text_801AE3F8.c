/* Functions from 0x801AE3F8 to 0x801B3220, found by decomp-toolkit. */
#include "common.h"
#include "global.h"
#pragma cplusplus on
struct SetupMenuObj {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(s32); virtual void v12(s32);
};
#pragma cplusplus reset
extern u8 gUiMainListPanelVtbl[];
extern struct unk_struct lbl_80331C6C;

void *fn_801AE3F8(u32 arg0) {
    void *Process_CreateChild(void *, u32);
    void *Process_Create(void *, u32);
    void fn_801403F0(void *);
    extern u8 lbl_802975D0[];
    extern u8 gFShopMsgTable[];
    void *var_r31;

    if (arg0 != 0U) {
        var_r31 = Process_CreateChild(lbl_802975D0, arg0);
    } else {
        var_r31 = Process_Create(lbl_802975D0, arg0);
    }
    if (var_r31 != NULL) {
        fn_801403F0(var_r31);
        *(s32 *)((u8 *)var_r31 + 0x40) = 0;
        *(s32 *)((u8 *)var_r31 + 0x44) = 0;
        *(s32 *)((u8 *)var_r31 + 0x48) = 0;
        *(s32 *)((u8 *)var_r31 + 0x4C) = 0;
        *(s32 *)((u8 *)var_r31 + 0x50) = 0;
        *(s32 *)((u8 *)var_r31 + 0x54) = 0;
        *(s32 *)((u8 *)var_r31 + 0x58) = 0;
        *(s32 *)((u8 *)var_r31 + 0x60) = 0;
        *(s32 *)((u8 *)var_r31 + 0x64) = 0;
        *(u8 **)((u8 *)var_r31 + 0x6C) = gFShopMsgTable;
    }
    return var_r31;
}

void fn_801AE498(void) {
    M2C_UNK fn_8013FE0C();
    fn_8013FE0C();
}

#pragma cplusplus on
/* Release a UI panel's child refs and destroy the panel base. */
extern "C" void Ui_DestroyPanel(void *panel) {
    extern void Ui_DtorPanelBase(void *, s32);
    extern u16 gUiPanelFlags;

    struct RefObj {
        virtual void destroy(s32);
        s32 refCount;
    };

    struct Holder {
        u8 pad[0x40];
        RefObj *child0;
        RefObj *child1;
        RefObj *child2;
        RefObj *child3;
        RefObj *child4;
        RefObj *child5;
        RefObj *child6;
        u8 pad5c[4];
        RefObj *child7;
        RefObj *child8;
    };

    Holder *h;
    RefObj *p;

    gUiPanelFlags &= 0xFFFFFFEF;
    h = (Holder *)panel;
    if (h != NULL) {
        p = h->child0;
        if (p != NULL) {
            if (--p->refCount == 0 && p != NULL) {
                p->destroy(1);
            }
            h->child0 = (RefObj *)0;
        }
        p = h->child1;
        if (p != NULL) {
            if (--p->refCount == 0 && p != NULL) {
                p->destroy(1);
            }
            h->child1 = (RefObj *)0;
        }
        p = h->child2;
        if (p != NULL) {
            if (--p->refCount == 0 && p != NULL) {
                p->destroy(1);
            }
            h->child2 = (RefObj *)0;
        }
        p = h->child3;
        if (p != NULL) {
            if (--p->refCount == 0 && p != NULL) {
                p->destroy(1);
            }
            h->child3 = (RefObj *)0;
        }
        p = h->child4;
        if (p != NULL) {
            if (--p->refCount == 0 && p != NULL) {
                p->destroy(1);
            }
            h->child4 = (RefObj *)0;
        }
        p = h->child5;
        if (p != NULL) {
            if (--p->refCount == 0 && p != NULL) {
                p->destroy(1);
            }
            h->child5 = (RefObj *)0;
        }
        p = h->child6;
        if (p != NULL) {
            if (--p->refCount == 0 && p != NULL) {
                p->destroy(1);
            }
            h->child6 = (RefObj *)0;
        }
        p = h->child7;
        if (p != NULL) {
            if (--p->refCount == 0 && p != NULL) {
                p->destroy(1);
            }
            h->child7 = (RefObj *)0;
        }
        p = h->child8;
        if (p != NULL) {
            if (--p->refCount == 0 && p != NULL) {
                p->destroy(1);
            }
            h->child8 = (RefObj *)0;
        }
        Ui_DtorPanelBase(h, 0);
    }
}
#pragma cplusplus reset

void fn_801AE73C(s32 arg0) {
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern u8 gFShopStrings[];
    
    s32 temp_r4;
    u8 var_r3;

    var_r3 = 0;
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20)) {
        var_r3 = 1;
    }
    if (var_r3 == 0) {
        temp_r4 = *(s32*)((char*)gPadInput + 4);
        if (temp_r4 & (*(s32*)((char*)gPadInput + 8) ^ temp_r4) & 0x300) {
            Ui_PlaySeCue(&gFShopStrings[0x36E], 0x64);
            Process_ClearFunc(arg0);
        }
    }
}

void fn_801AE7C0(void *arg0) {
    void TalkUi_ShowMsg(s32);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *, s32);
    void *inner;
    s32 saved;
    void *ret;

    TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)arg0 + 0x6C) + 0x50));
    inner = *(void **)((u8 *)arg0 + 0x6C);
    saved = *(s32 *)((u8 *)inner + 0x88);
    ret = Ui_FindChild(arg0, -0x1000, 0);
    if (ret != NULL) {
        Ui_SetWidgetText(ret, saved);
    }
}

void fn_801AE81C(void *arg0) {
    void TalkUi_ShowMsg(s32);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *, s32);
    void *inner;
    s32 saved;
    void *ret;

    TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)arg0 + 0x6C) + 0x58));
    inner = *(void **)((u8 *)arg0 + 0x6C);
    saved = *(s32 *)((u8 *)inner + 0x88);
    ret = Ui_FindChild(arg0, -0x1000, 0);
    if (ret != NULL) {
        Ui_SetWidgetText(ret, saved);
    }
}

#pragma cplusplus on
extern "C" void fn_801AE878(void *arg0) {
    struct VObj {
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
    s32 Ui_ListGetSelected(s32);
    void fn_8013AD70(s32, s32);
    VObj *Ui_FindChild(void *, s32, s32);
    void Process_Goto(void *, s32);
    extern u8 gBattleState[];
    s32 temp_r31;
    VObj *temp_r30;

    temp_r31 = *(s32 *)((u8 *)arg0 + 0x54);
    temp_r30 = Ui_FindChild(arg0, 0xA, 0);
    fn_8013AD70(temp_r31, *(s32 *)(gBattleState + 0xB0));
    temp_r30->v11(Ui_ListGetSelected(temp_r31));
    Process_Goto(arg0, *(u8 *)((u8 *)arg0 + 0x68));
}
extern "C" void fn_801AE908(void *arg0) {
    struct VObj {
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
    s32 Ui_ListGetSelected(s32);
    void fn_8013AD70(s32, s32);
    VObj *Ui_FindChild(void *, s32, s32);
    extern u8 gBattleState[];
    s32 temp_r31;
    VObj *temp_r30;

    temp_r31 = *(s32 *)((u8 *)arg0 + 0x54);
    temp_r30 = Ui_FindChild(arg0, 0xA, 0);
    fn_8013AD70(temp_r31, *(s32 *)(gBattleState + 0xAC));
    temp_r30->v11(Ui_ListGetSelected(temp_r31));
}
#pragma cplusplus reset
void fn_801AE980(void *arg0) {
    M2C_UNK Process_Goto(void *, u8);
    Process_Goto(arg0, *(u8 *)((char *)arg0 + 0x68));
}

void fn_801AE9A4(void *arg0) {
    s32 Ui_FindChild(void *, s32, s32);
    void Ui_BringChildToFront(void *, s32);
    void TalkUi_ShowMsg(void *);
    void Ui_PlaySeCue(void *, s32);
    void Process_ClearFunc(void *);
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern u8 gFShopStrings[];
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
            Ui_BringChildToFront(arg0, *(s32 *)((u8 *)arg0 + 0x54));
            TalkUi_ShowMsg(*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0x68));
            Ui_PlaySeCue(gFShopStrings + 0x36E, 0x64);
            Process_ClearFunc(arg0);
        }
    }
}

void FShop_OnCapacityHelp(void *proc) {
    /* On A/B, show MESS_FSHOP_CAPACITY_NG_NEXT, refresh caption, play SE, and clear this callback. */
    u32 Ui_FindChild(void *, s32, s32);
    void Ui_BringChildToFront(void *, s32);
    void TalkUi_ShowMsg(void *);
    void Ui_PlaySeCue(void *, s32);
    void Ui_SetWidgetText(u32, s32);
    void Process_ClearFunc(void *);
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern u8 gFShopStrings[];
    u8 inputLocked;
    u32 held;
    u32 prev;
    s32 captionId;
    u32 caption;

    Ui_BringChildToFront(proc, Ui_FindChild(proc, -0x1000, 0));
    inputLocked = 0;
    if ((gUiInputFlags & 0x10) != 0 && (gUiInputFlags & 0x20) == 0) {
        inputLocked = 1;
    }
    if (inputLocked == 0) {
        held = *(u32 *)((u8 *)gPadInput + 4);
        prev = *(u32 *)((u8 *)gPadInput + 8);
        if ((held & (prev ^ held) & 0x300) != 0) {
            TalkUi_ShowMsg(*(void **)((u8 *)*(void **)((u8 *)proc + 0x6C) + 0x60));
            Ui_PlaySeCue(gFShopStrings + 0x36E, 0x64);
            captionId = *(s32 *)((u8 *)*(void **)((u8 *)proc + 0x6C) + 0x88);
            caption = Ui_FindChild(proc, -0x1000, 0);
            if (caption != 0) {
                Ui_SetWidgetText(caption, captionId);
            }
            Process_ClearFunc(proc);
        }
    }
}

void FShop_OnAnimalHelp(void *proc) {
    /* On A/B, show MESS_FSHOP_ANIMAL_NG_NEXT, refresh caption, play SE, and clear this callback. */
    u32 Ui_FindChild(void *, s32, s32);
    void Ui_BringChildToFront(void *, s32);
    void TalkUi_ShowMsg(void *);
    void Ui_PlaySeCue(void *, s32);
    void Ui_SetWidgetText(u32, s32);
    void Process_ClearFunc(void *);
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern u8 gFShopStrings[];
    u8 inputLocked;
    u32 held;
    u32 prev;
    s32 captionId;
    u32 caption;

    Ui_BringChildToFront(proc, Ui_FindChild(proc, -0x1000, 0));
    inputLocked = 0;
    if ((gUiInputFlags & 0x10) != 0 && (gUiInputFlags & 0x20) == 0) {
        inputLocked = 1;
    }
    if (inputLocked == 0) {
        held = *(u32 *)((u8 *)gPadInput + 4);
        prev = *(u32 *)((u8 *)gPadInput + 8);
        if ((held & (prev ^ held) & 0x300) != 0) {
            Ui_BringChildToFront(proc, *(s32 *)((u8 *)proc + 0x54));
            TalkUi_ShowMsg(*(void **)((u8 *)*(void **)((u8 *)proc + 0x6C) + 0x4C));
            captionId = *(s32 *)((u8 *)*(void **)((u8 *)proc + 0x6C) + 0x70);
            caption = Ui_FindChild(proc, -0x1000, 0);
            if (caption != 0) {
                Ui_SetWidgetText(caption, captionId);
            }
            Ui_PlaySeCue(gFShopStrings + 0x36E, 0x64);
            Process_ClearFunc(proc);
        }
    }
}

void FShop_OnItemMaxHelp(void *proc) {
    /* On A/B, show MESS_FSHOP_ITEMMAX_NG_NEXT, refresh caption, play SE, and clear this callback. */
    u32 Ui_FindChild(void *, s32, s32);
    void Ui_BringChildToFront(void *, s32);
    void TalkUi_ShowMsg(void *);
    void Ui_PlaySeCue(void *, s32);
    void Ui_SetWidgetText(u32, s32);
    void Process_ClearFunc(void *);
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern u8 gFShopStrings[];
    u8 inputLocked;
    u32 held;
    u32 prev;
    s32 captionId;
    u32 caption;

    Ui_BringChildToFront(proc, Ui_FindChild(proc, -0x1000, 0));
    inputLocked = 0;
    if ((gUiInputFlags & 0x10) != 0 && (gUiInputFlags & 0x20) == 0) {
        inputLocked = 1;
    }
    if (inputLocked == 0) {
        held = *(u32 *)((u8 *)gPadInput + 4);
        prev = *(u32 *)((u8 *)gPadInput + 8);
        if ((held & (prev ^ held) & 0x300) != 0) {
            Ui_BringChildToFront(proc, *(s32 *)((u8 *)proc + 0x54));
            TalkUi_ShowMsg(*(void **)((u8 *)*(void **)((u8 *)proc + 0x6C) + 0x44));
            captionId = *(s32 *)((u8 *)*(void **)((u8 *)proc + 0x6C) + 0x70);
            caption = Ui_FindChild(proc, -0x1000, 0);
            if (caption != 0) {
                Ui_SetWidgetText(caption, captionId);
            }
            Ui_PlaySeCue(gFShopStrings + 0x36E, 0x64);
            Process_ClearFunc(proc);
        }
    }
}

void fn_801AECF8(void *arg0) {
    M2C_UNK fn_8000C188(void *);
    M2C_UNK fn_8013FF00(void *, s32);
    s32 fn_8013FF94(void *, s32, s32);
    M2C_UNK fn_801475FC(void *, M2C_UNK);
    extern u8 lbl_8027BD18[];
    extern u32 lbl_80367110;
    extern void *lbl_80367240;
    u8 var;
    s32 a;
    void *ptr;
    s32 b;
    unsigned int mask;
    int flags;

    fn_8013FF00(arg0, fn_8013FF94(arg0, -0x1000, 0));
    var = 0;
    ptr = lbl_80367240;
    flags = lbl_80367110;
    a = *(s32 *)((char *)ptr + 4);
    b = *(s32 *)((char *)ptr + 8);
    mask = a & (b ^ a);
    if ((flags & 0x10) && !(flags & 0x20)) {
        var = 1;
    }
    if (var == 0 && (mask & 0x300)) {
        fn_8013FF00(arg0, *(s32 *)((char *)arg0 + 0x48));
        fn_801475FC(&lbl_8027BD18[0x36E], 0x64);
        fn_8000C188(arg0);
    }
}

void fn_801AEDA0(void *arg0) {
    s32 Ui_FindChild(void *, s32, s32);
    void Ui_BringChildToFront(void *, s32);
    void Ui_PlaySeCue(void *, s32);
    void Process_ClearFunc(void *);
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern u8 gFShopStrings[];
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
            Ui_BringChildToFront(arg0, Ui_FindChild(arg0, 1, 0));
            Ui_PlaySeCue(gFShopStrings + 0x36E, 0x64);
            Process_ClearFunc(arg0);
        }
    }
}

#pragma use_lmw_stmw on
#pragma cplusplus on
#pragma optimization_level 3
extern "C" void fn_801AEE58(void *self) {
    struct Ref {
        virtual void v0(s32) = 0;
        s32 ref;
    };
    struct Child {
        u8 pad[0xC];
        s16 unkC;
    };
    Child *Ui_FindChild(void *, s32, s32);
    void Ui_RemoveChild(void *, void *);
    void Ui_SlideWidgetChild(void *, void *, s16 *, s32);
    void Process_Goto(void *, s32);
    s16 sp14[2];
    s16 sp10[2];
    s16 spC[2];
    s16 sp8[2];
    Child *cb;
    void *saved;
    Child *c4;
    Child *c9;
    Child *ca;
    s16 t;

    saved = *(void **)((u8 *)self + 0x54);
    cb = (Child *)saved;
    c4 = Ui_FindChild(self, 4, 0);
    c9 = Ui_FindChild(self, 9, 0);
    ca = Ui_FindChild(self, 0xA, 0);
    cb = Ui_FindChild(self, 0xB, 0);
    Ui_RemoveChild(self, saved);
    t = c4->unkC;
    sp14[0] = 0x260;
    sp14[1] = t;
    Ui_SlideWidgetChild(self, c4, sp14, 0);
    if (c9 != 0) {
        t = c9->unkC;
        sp10[0] = 0x260;
        sp10[1] = t;
        Ui_SlideWidgetChild(self, c9, sp10, 0);
    }
    if (ca != 0) {
        t = ca->unkC;
        spC[0] = 0x260;
        spC[1] = t;
        Ui_SlideWidgetChild(self, ca, spC, 0);
    }
    {
        Ref *p = *(Ref **)((u8 *)self + 0x60);
        if (p != 0) {
            if (--p->ref == 0) {
                if (p != 0) {
                    p->v0(1);
                }
            }
            *(Ref **)((u8 *)self + 0x60) = 0;
        }
    }
    if (cb != 0) {
        t = cb->unkC;
        sp8[0] = 0x260;
        sp8[1] = t;
        Ui_SlideWidgetChild(self, cb, sp8, 0);
    }
    {
        Ref *p = *(Ref **)((u8 *)self + 0x64);
        if (p != 0) {
            if (--p->ref == 0) {
                if (p != 0) {
                    p->v0(1);
                }
            }
            *(Ref **)((u8 *)self + 0x64) = 0;
        }
    }
    Process_Goto(self, 0x26);
}
#pragma optimization_level reset
#pragma cplusplus reset
#pragma use_lmw_stmw reset
void Ui_HandleUnitPanelListMode(void *panel) {
    extern u8 gUiContext[];
    extern u8 gBattleState[];
    extern u8 gConvoy[];
    s32 Ui_ListGetSelected(void *);
    void fn_80094ABC(s32, void *);
    u8 fn_8014D8DC(void *);
    void fn_800C3C1C(void *, void *);
    void fn_801402A0(void *, void *, s16 *, s32);
    void TalkUi_ShowMsg(s32);
    void Ui_LayoutUnitPanelList(void *);
    u32 Ui_FindChild(void *, s32, s32, void *);
    void Ui_SetWidgetText(u32, s32);
    void Process_Goto(void *, s32);

    void *widget;
    void *captionSrc;
    u32 caption;
    s16 pos[2];
    u8 mode;

    // Mode 0x81: give list/convoy item to the unit; mode 0x80: open the unit-panel list view.
    mode = gUiContext[8];
    widget = *(void **)((u8 *)panel + 0x64);
    switch (mode) {
    case 0x81:
        widget = (void *)(*(s32 *)((u8 *)panel + 0x48) + 0x60);
        if (*(s16 *)((u8 *)*(void **)((u8 *)panel + 0x54) + 0x4E) != 0x7FFF) {
            fn_80094ABC(Ui_ListGetSelected(*(void **)((u8 *)panel + 0x54)), widget);
        } else if (fn_8014D8DC(gBattleState) != 0) {
            fn_800C3C1C(gConvoy, widget);
        }
        gBattleState[0x51] = 1;
        break;
    case 0x80:
        pos[0] = *(s16 *)((u8 *)widget + 0xA);
        pos[1] = 0x108;
        fn_801402A0(panel, widget, pos, 0);
        *(s32 *)((u8 *)widget + 0x3C) = 1;
        TalkUi_ShowMsg(*(s32 *)((u8 *)*(void **)((u8 *)panel + 0x6C) + 0x2C));
        Ui_LayoutUnitPanelList(panel);
        captionSrc = *(void **)((u8 *)panel + 0x6C);
        widget = *(void **)((u8 *)captionSrc + 0x70);
        caption = Ui_FindChild(panel, -0x1000, 0, captionSrc);
        if (caption != 0U) {
            Ui_SetWidgetText(caption, (s32)widget);
        }
        Process_Goto(panel, 0x18);
        break;
    }
}

void fn_801AF148(void *arg0) {
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
    temp_r6 = *(void **)((u8 *)arg0 + 0x6C);
    temp_r31 = *(s32 *)((u8 *)temp_r6 + 0x8C);
    res = Ui_FindChild(arg0, -0x1000, 0, temp_r6);
    if (res != 0U) {
        Ui_SetWidgetText(res, temp_r31);
    }
}

#pragma cplusplus on
extern "C" void fn_801AF1C8(void *arg0) {
struct V{virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();};
void *Ui_FindChild(void *,s32,s32);
void Ui_SlideWidgetChild(void *,void *,s16 *,s32);
void Ui_SlideWidgetChildMode1(void *,void *,s16 *,s32);
void fn_801402A0(void *,void *,s16 *,s32);
void TalkUi_ShowMsg(s32);
s16 pos1[2],pos2[2],pos3[2];
s16 y;
void *panel;
void *child;
void *other;
panel=M2C_FIELD(arg0,void **,0x54);
child=Ui_FindChild(arg0,4,0);
other=M2C_FIELD(arg0,void **,0x64);
y=M2C_FIELD(panel,s16 *,0xC);
pos1[0]=0x260;
pos1[1]=y;
Ui_SlideWidgetChild(arg0,panel,pos1,0);
pos2[0]=0x138;
pos2[1]=0x74;
Ui_SlideWidgetChildMode1(arg0,child,pos2,0);
M2C_FIELD(child,s16 *,0xE)=M2C_FIELD(child,s16 *,0xA)+0x108;
M2C_FIELD(child,s16 *,0x4A)=0x14;
M2C_FIELD(child,s16 *,0x4C)=0;
((V*)child)->v8();
M2C_FIELD(child,u8 *,0x48)=1;
M2C_FIELD(child,u8 *,0x44)=2;
pos3[0]=M2C_FIELD(other,s16 *,0xA);
pos3[1]=0xA7;
fn_801402A0(arg0,other,pos3,0);
M2C_FIELD(other,s32 *,0x3C)=0;
TalkUi_ShowMsg(M2C_FIELD(M2C_FIELD(arg0,void **,0x6C),s32 *,0x34));
}
#pragma cplusplus reset

void fn_801AF2E0(void *panel) {
    extern u8 gUiContext[],gBattleState[],gConvoy[];
    s32 Ui_ListGetSelected(void *);
    void fn_80094ABC(s32,void *);
    u8 fn_8014D8DC(void *);
    void fn_800C3C1C(void *,void *);
    void Ui_SlideWidgetChild(void *,void *,s16 *,s32);
    void TalkUi_ShowMsg(s32);
    void Ui_LayoutUnitPanelList(void *);
    void *Ui_FindChild(void *,s32,s32);
    void Ui_SetWidgetText(void *,s32);
    void Process_Goto(void *,s32);
    void *widget;
    void *captionSrc;
    s32 captionText;
    s16 pos[2];
    s16 y;
    widget=Ui_FindChild(panel,9,0);
    switch(gUiContext[8]) {
    case 0x81:
        widget=(u8 *)M2C_FIELD(panel,void **,0x48)+0x60;
        if(M2C_FIELD(M2C_FIELD(panel,void **,0x54),s16 *,0x4e)!=0x7fff)
            fn_80094ABC(Ui_ListGetSelected(M2C_FIELD(panel,void **,0x54)),widget);
        else if(fn_8014D8DC(gBattleState)) fn_800C3C1C(gConvoy,widget);
        gBattleState[0x51]=1;
        break;
    case 0x80:
        y=M2C_FIELD(widget,s16 *,12);
        pos[0]=0x260;pos[1]=y;
        Ui_SlideWidgetChild(panel,widget,pos,0);
        TalkUi_ShowMsg(M2C_FIELD(M2C_FIELD(panel,void **,0x6c),s32 *,0x2c));
        Ui_LayoutUnitPanelList(panel);
        captionSrc=M2C_FIELD(panel,void **,0x6c);
        captionText=M2C_FIELD(captionSrc,s32 *,0x6c);
        widget=Ui_FindChild(panel,-0x1000,0);
        if(widget) Ui_SetWidgetText(widget,captionText);
        Process_Goto(panel,0x18);
        break;
    }
}

void fn_801AF40C(void *arg0) {
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
    temp_r6 = *(void **)((u8 *)arg0 + 0x6C);
    temp_r31 = *(s32 *)((u8 *)temp_r6 + 0x8C);
    res = Ui_FindChild(arg0, -0x1000, 0, temp_r6);
    if (res != 0U) {
        Ui_SetWidgetText(res, temp_r31);
    }
}

#pragma cplusplus on
extern "C" void fn_801AF48C(void *arg0) {
    void *fn_800C42D8(s32);
    void fn_8011D79C(s32);
    void fn_80138808(void *, s32);
    s32 fn_8013AC54(void *);
    void *fn_8013FF94(void *, s32, s32);
    void fn_801400F4(void *, void *);
    void fn_80140258(void *, void *, s16 *, s32);
    void fn_8014027C(void *, void *, s16 *, s32);
    extern void *lbl_8028FDB0[];
    extern void *lbl_80291A3C[];
    extern void *lbl_80292230[];
    extern f32 lbl_8036B0A8;

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

    s16 sp10[2];
    s16 spC[2];
    s16 sp8[2];
    void *temp_r31;
    void *temp_r30;
    void *temp_r28;
    s16 temp_r5;
    s16 temp_r6;
    s16 temp_r7;

    temp_r30 = *(void **)((u8 *)arg0 + 0x54);
    temp_r28 = fn_8013FF94(arg0, 4, 0);
    temp_r6 = *(s16 *)((u8 *)temp_r30 + 0xC);
    sp10[0] = 0x260;
    sp10[1] = temp_r6;
    fn_80140258(arg0, temp_r30, sp10, 0);
    spC[0] = 0x138;
    spC[1] = 0x74;
    fn_8014027C(arg0, temp_r28, spC, 0);
    temp_r5 = *(s16 *)((u8 *)temp_r28 + 0xA) + 0x108;
    *(s16 *)((u8 *)temp_r28 + 0xE) = temp_r5;
    *(s16 *)((u8 *)temp_r28 + 0x4A) = 0x14;
    *(s16 *)((u8 *)temp_r28 + 0x4C) = 0;
    ((Obj *)temp_r28)->v8();
    *(u8 *)((u8 *)temp_r28 + 0x48) = 1;
    *(u8 *)((u8 *)temp_r28 + 0x44) = 2;
    temp_r31 = fn_800C42D8(0x54);
    if (temp_r31 != NULL) {
        *(void **)temp_r31 = lbl_8028FDB0;
        *(s32 *)((u8 *)temp_r31 + 4) = 0;
        *(void **)temp_r31 = lbl_80292230;
        *(s16 *)((u8 *)temp_r31 + 8) = -1;
        *(s16 *)((u8 *)temp_r31 + 0xA) = 0x260;
        *(s16 *)((u8 *)temp_r31 + 0xC) = 0xA7;
        *(s16 *)((u8 *)temp_r31 + 0xE) = 0x368;
        *(s16 *)((u8 *)temp_r31 + 0x10) = 0xFC;
        *(s16 *)((u8 *)temp_r31 + 0x12) = 0;
        *(s16 *)((u8 *)temp_r31 + 0x14) = 0;
        *(s16 *)((u8 *)temp_r31 + 0x16) = 0x108;
        *(s16 *)((u8 *)temp_r31 + 0x18) = 0x55;
        *(s16 *)((u8 *)temp_r31 + 0x1A) = 0;
        *(s16 *)((u8 *)temp_r31 + 0x1C) = 0;
        ((u8 *)temp_r31)[0x1E] = 0xFF;
        ((u8 *)temp_r31)[0x1F] = 0xFF;
        ((u8 *)temp_r31)[0x20] = 0xFF;
        ((u8 *)temp_r31)[0x21] = 0xFF;
        *(s16 *)((u8 *)temp_r31 + 0x22) = 0x190;
        *(s16 *)((u8 *)temp_r31 + 0x24) = 0;
        *(f32 *)((u8 *)temp_r31 + 0x28) = lbl_8036B0A8;
        *(f32 *)((u8 *)temp_r31 + 0x2C) = lbl_8036B0A8;
        *(f32 *)((u8 *)temp_r31 + 0x30) = lbl_8036B0A8;
        *(s32 *)((u8 *)temp_r31 + 0x34) = 0;
        *(s32 *)((u8 *)temp_r31 + 0x38) = 0;
        *(void **)temp_r31 = lbl_80291A3C;
        *(s32 *)((u8 *)temp_r31 + 0x3C) = 0;
        *(s32 *)((u8 *)temp_r31 + 0x40) = 0x1003A;
        *(s32 *)((u8 *)temp_r31 + 0x4C) = 0;
        *(s32 *)((u8 *)temp_r31 + 0x50) = 0;
        ((Obj *)temp_r31)->v8();
        *(s16 *)((u8 *)temp_r31 + 8) = 9;
        *(s16 *)((u8 *)temp_r31 + 0x24) = 8;
        *(s32 *)((u8 *)temp_r31 + 0x34) |= 0x10;
        fn_80138808(temp_r31, fn_8013AC54(temp_r30));
        fn_801400F4(arg0, temp_r31);
        temp_r7 = *(s16 *)((u8 *)temp_r31 + 0xC);
        sp8[0] = 0x138;
        sp8[1] = temp_r7;
        fn_8014027C(arg0, temp_r31, sp8, 0);
        fn_8011D79C(*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0x30));
    }
}

extern "C" void fn_801AF6BC(void *arg0)
{
    void *Ui_FindChild(void *, s32, s32);
    s32 Ui_ListGetSelected(void *);
    void Ui_UpdatePanelWidgets(void *);
    void Ui_AddChild(void *, void *);
    void Ui_SlideWidgetChild(void *, void *, s16 *, s32);
    void Ui_SlideWidgetChildMode1(void *, void *, s16 *, s32);
    void Ui_BringChildToFront(void *, void *);
    u8 fn_8014D8DC(void *);
    void Ui_PlaySeCue(void *, s32);
    u64 *Item_GetFlagsPtr(void *);
    u8 fn_80092F9C(void *);
    u8 fn_80092F38(void *);
    void TalkUi_ShowMsg(void *);
    void Ui_SetWidgetText(void *, void *);
    void Process_Goto(void *, s32);
    s32 Convoy_FindEmpty(void *);
    void fn_801695BC(void *, void *, s32);
    void fn_801694AC(void *, void *);
    void Ui_CreateMsgPopup(void *, void *, f32, f32);

    extern u32 gUiInputFlags;
    extern u32 *gPadInput;
    extern u8 gFShopStrings[];
    extern u8 gBattleState[];
    extern u8 gConvoy[];
    extern f32 lbl_8036B0AC;
    extern f64 lbl_8036B0B0;

    struct Obj {
        virtual void v0(s32) = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9(s16 *, void *) = 0;
        virtual void v10() = 0;
        virtual void v11(s32) = 0;
    };

    volatile u32 sp28;
    s16 sp24[2];
    s16 sp20[2];
    s16 sp1C[2];
    s16 sp18[2];
    s16 sp14[2];
    s16 sp10[2];
    s16 spC[2];
    s16 sp8[2];

    void *panel;
    void *sel;
    void *list;
    void *obj;
    void *tmp;
    void *res;
    void **vt;

    u8 skip;
    u32 pressed;
    u32 held;
    s16 y;

    list = *(void **)((u8 *)arg0 + 0x54);

    panel = Ui_FindChild(arg0, 4, 0);
    sel = (void *)Ui_ListGetSelected(list);

    Ui_UpdatePanelWidgets(arg0);

    if (sel != (void *)Ui_ListGetSelected(list)) {
        if (sel != NULL && (u32)Ui_ListGetSelected(list) != 0) {
            s32 arg = Ui_ListGetSelected(list);
            ((Obj *)*(void **)((u8 *)arg0 + 0x60))->v11(arg);
        } else if (sel != NULL && (u32)Ui_ListGetSelected(list) == 0) {
            obj = *(void **)((u8 *)arg0 + 0x60);
            y = *(s16 *)((u8 *)obj + 0xC);

            sp24[0] = 0x260;
            sp24[1] = y;

            Ui_SlideWidgetChild(arg0, obj, sp24, 1);

            if (fn_8014D8DC(gBattleState) != 0) {
                Ui_AddChild(
                    arg0,
                    *(void **)((u8 *)arg0 + 0x64)
                );

                obj = *(void **)((u8 *)arg0 + 0x64);
                y = *(s16 *)((u8 *)obj + 0xC);

                sp20[0] = 0x134;
                sp20[1] = y;

                Ui_SlideWidgetChildMode1(arg0, obj, sp20, 0);
            }

            Ui_BringChildToFront(arg0, list);
        } else {
            Ui_AddChild(
                arg0,
                *(void **)((u8 *)arg0 + 0x60)
            );

            obj = *(void **)((u8 *)arg0 + 0x60);
            y = *(s16 *)((u8 *)obj + 0xC);

            sp1C[0] = 0x138;
            sp1C[1] = y;

            Ui_SlideWidgetChildMode1(arg0, obj, sp1C, 1);

            ((Obj *)*(void **)((u8 *)arg0 + 0x60))->v11(Ui_ListGetSelected(list));

            if (fn_8014D8DC(gBattleState) != 0) {
                obj = *(void **)((u8 *)arg0 + 0x64);
                y = *(s16 *)((u8 *)obj + 0xC);

                sp18[0] = 0x260;
                sp18[1] = y;

                Ui_SlideWidgetChild(arg0, obj, sp18, 0);
            }

            Ui_BringChildToFront(arg0, list);
        }

        sel = (void *)Ui_ListGetSelected(list);
    }

    *(void **)((u8 *)panel + 0x40) = sel;

    skip = (gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20);

    if (skip == 0) {
        held = gPadInput[1];
        pressed = held & (gPadInput[2] ^ held);

        if ((pressed & 0x100) != 0 && sel != NULL) {
            tmp = *(void **)((u8 *)panel + 0x3C);

            Ui_PlaySeCue(
                gFShopStrings + 0x37E,
                0x64
            );

            if ((*Item_GetFlagsPtr(tmp) & 5ULL) != 0 &&
                fn_80092F9C(sel) >= 4) {

                TalkUi_ShowMsg(
                    *(void **)(*(u8 **)((u8 *)arg0 + 0x6C) + 0x40)
                );

                res = *(void **)(
                    *(u8 **)((u8 *)arg0 + 0x6C) + 0x84
                );

                tmp = Ui_FindChild(arg0, -0x1000, 0);

                if (tmp != NULL) {
                    Ui_SetWidgetText(tmp, res);
                }

                Process_Goto(arg0, 0x1E);
                return;
            }

            if ((*Item_GetFlagsPtr(tmp) & 0x18ULL) != 0 &&
                fn_80092F38(sel) >= 4) {

                TalkUi_ShowMsg(
                    *(void **)(*(u8 **)((u8 *)arg0 + 0x6C) + 0x40)
                );

                res = *(void **)(
                    *(u8 **)((u8 *)arg0 + 0x6C) + 0x84
                );

                tmp = Ui_FindChild(arg0, -0x1000, 0);

                if (tmp != NULL) {
                    Ui_SetWidgetText(tmp, res);
                }

                Process_Goto(arg0, 0x1E);
                return;
            }

            Process_Goto(arg0, 0x1A);
            return;
        }

        if ((pressed & 0x100) != 0 &&
            sel == NULL &&
            *(s16 *)((u8 *)list + 0x4E) == 0x7FFF) {

            if (fn_8014D8DC(gBattleState) == 0) {
                ((Obj *)list)->v9(sp14, list);

                sp28 = *(u32 *)sp14;

                Ui_CreateMsgPopup(
                    gFShopStrings + 0x38E,
                    arg0,
                    (f32)((volatile s16 *)&sp28)[0],
                    (f32)((volatile s16 *)&sp28)[1]
                );

                return;
            }

            Ui_PlaySeCue(
                gFShopStrings + 0x37E,
                0x64
            );

            if (Convoy_FindEmpty(gConvoy) < 0) {
                TalkUi_ShowMsg(
                    *(void **)(*(u8 **)((u8 *)arg0 + 0x6C) + 0x64)
                );

                res = *(void **)(
                    *(u8 **)((u8 *)arg0 + 0x6C) + 0x7C
                );

                tmp = Ui_FindChild(arg0, -0x1000, 0);

                if (tmp != NULL) {
                    Ui_SetWidgetText(tmp, res);
                }

                Process_Goto(arg0, 0x21);
                return;
            }

            Process_Goto(arg0, 0x1B);
            return;
        }

        if ((pressed & 0x800) != 0 && sel != NULL) {
            fn_801695BC(sel, arg0, 0x1000000);

            *(u8 *)((u8 *)arg0 + 0x68) = 0x18;

            Process_Goto(arg0, 0x22);
            return;
        }

        if ((pressed & 0x400) != 0 && sel != NULL) {
            fn_801694AC(sel, arg0);

            *(u8 *)((u8 *)arg0 + 0x68) = 0x18;

            Process_Goto(arg0, 0x23);
            return;
        }

        if ((pressed & 0x200) != 0) {
            y = *(s16 *)((u8 *)list + 0xC);

            sp10[0] = 0x260;
            sp10[1] = y;

            Ui_SlideWidgetChild(arg0, list, sp10, 0);

            if (Ui_FindChild(arg0, 0xA, 0) != NULL) {
                obj = *(void **)((u8 *)arg0 + 0x60);
                y = *(s16 *)((u8 *)obj + 0xC);

                spC[0] = 0x260;
                spC[1] = y;

                Ui_SlideWidgetChild(arg0, obj, spC, 0);
            }

            obj = *(void **)((u8 *)arg0 + 0x60);

            if (obj != NULL) {
                if (--*(s32 *)((u8 *)obj + 4) == 0) {
                    if (obj != NULL) {
                        ((Obj *)obj)->v0(1);
                    }
                }

                *(void **)((u8 *)arg0 + 0x60) = NULL;
            }

            if (Ui_FindChild(arg0, 0xB, 0) != NULL) {
                obj = *(void **)((u8 *)arg0 + 0x64);
                y = *(s16 *)((u8 *)obj + 0xC);

                sp8[0] = 0x260;
                sp8[1] = y;

                Ui_SlideWidgetChild(arg0, obj, sp8, 0);
            }

            obj = *(void **)((u8 *)arg0 + 0x64);

            if (obj != NULL) {
                if (--*(s32 *)((u8 *)obj + 4) == 0) {
                    if (obj != NULL) {
                        ((Obj *)obj)->v0(1);
                    }
                }

                *(void **)((u8 *)arg0 + 0x64) = NULL;
            }

            *(s16 *)((u8 *)panel + 0xE) =
                (s16)(*(s16 *)((u8 *)panel + 0xA) + 0x108);

            *(s16 *)((u8 *)panel + 0x4A) = 0x14;
            *(s16 *)((u8 *)panel + 0x4C) = 0;

            ((Obj *)panel)->v8();

            *(u8 *)((u8 *)panel + 0x48) = 1;
            *(f32 *)((u8 *)panel + 0x2C) = lbl_8036B0AC;
            *(u8 *)((u8 *)panel + 0x44) = 0;
            *(s32 *)((u8 *)panel + 0x40) = 0;

            if (*(u32 *)((u8 *)arg0 + 0x58) != 0) {
                Process_Goto(arg0, 0x13);
            } else {
                Process_Goto(arg0, 0xE);
            }

            Ui_PlaySeCue(
                gFShopStrings + 0x3A0,
                0x64
            );
        }
    }
}

#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void Ui_LayoutUnitPanelList(void *arg0) {
    /* Slide in the unit-panel list view: list, selection detail (or battle alt), and caption. */
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
    list = Ui_FindChild(arg0, 8, 0);
    if (list == NULL) {
        list = *(void **)((u8 *)panel + 0x54);
        Ui_AddChild(panel, list);
    }
    if (*(s16 *)((u8 *)list + 0xA) != 0x118) {
        savedH = *(s16 *)((u8 *)list + 0xC);
        listPos[0] = 0x118;
        listPos[1] = savedH;
        Ui_SlideWidgetChildMode1(panel, list, listPos, 0);
    }
    *(u8 *)((u8 *)list + 0x4C) = 1;
    if (*(s16 *)((u8 *)list + 0x4E) != 0x7FFF) {
        child = Ui_FindChild(panel, 0xA, 0);
        if (child == NULL) {
            child = *(void **)((u8 *)panel + 0x60);
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
        child = Ui_FindChild(panel, 0xB, 0);
        if (child == NULL) {
            child = *(void **)((u8 *)panel + 0x64);
            Ui_AddChild(panel, child);
        }
        if (*(s16 *)((u8 *)child + 0xA) != 0x134) {
            savedH = *(s16 *)((u8 *)child + 0xC);
            altPos[0] = 0x134;
            altPos[1] = savedH;
            Ui_SlideWidgetChildMode1(panel, child, altPos, 0);
        }
    }
    child = Ui_FindChild(panel, 4, 0);
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
    captionSrc = *(void **)((u8 *)panel + 0x6C);
    list = *(void **)((u8 *)captionSrc + 0x70);
    caption = (u32)Ui_FindChild(panel, -0x1000, 0);
    if (caption != 0U) {
        Ui_SetWidgetText(caption, (s32)list);
    }
}

#pragma cplusplus on
extern "C" void fn_801AFF9C(void *arg0) {
void *Ui_FindChild(void *,s32,s32);
void Ui_AddChild(void *,void *);
void Ui_SlideWidgetChildMode1(void *,void *,s16 *,s32);
void fn_801402A0(void *,void *,s16 *,s32);
void *Heap_Alloc(s32);
void *fn_80193B60(void *,s16 *,s16 *,s32);
void fn_8013B064(void *,void *);
void fn_8013AD70(void *,void *);
u64 *Item_GetFlagsPtr(void *);
void *fn_80193950(void *,s16,s16,s32);
void *fn_801938F8(void *,s16,s16,s32);
void Ui_BringChildToFront(void *,void *);
s32 Ui_ListGetSelected(void *);
u8 fn_8014D8DC(void *);
void TalkUi_ShowMsg(void *);
void Ui_SetWidgetText(void *,void *);
extern u8 gUnitLists[],gUiContext[],lbl_8028FDB0[],lbl_80292230[],lbl_80296150[],gBattleState[];
extern const f32 lbl_8036B0A8;
s16 sp20[2],sp1c[2],sp18[2],sp14[2],sp10[2],spc[2],sp8[2];
void *list; void *item; void *panel; void *self; void *p; void *q; void *walk; void *res;
s16 x,y,w,h;
self=arg0;
item=(u8 *)(*(void * *)((u8 *)self + 0x48))+0x60;
panel=Ui_FindChild(self,4,0);
if (!panel) {
 panel=*(void * *)((u8 *)self + 0x4c);
 Ui_AddChild(self,panel);
 x=*(s16 *)((u8 *)panel + 0xa); w=(s16)(*(s16 *)((u8 *)panel + 0xe)-x);
 *(s16 *)((u8 *)panel + 0xe)=x+w;
 y=*(s16 *)((u8 *)panel + 0xc); h=(s16)(*(s16 *)((u8 *)panel + 0x10)-y);
 *(s16 *)((u8 *)panel + 0x10)=h+0x30; *(s16 *)((u8 *)panel + 0xc)=0x30;
 sp20[0]=0x14c; sp20[1]=0x30;
 Ui_SlideWidgetChildMode1(self,panel,sp20,0);
} else {sp1c[0]=0x14c;sp1c[1]=0x30;fn_801402A0(self,panel,sp1c,0);}
*(s16 *)((u8 *)panel + 0xe)=*(s16 *)((u8 *)panel + 0xa)+0xe8;
*(s16 *)((u8 *)panel + 0x4a)=8; *(s16 *)((u8 *)panel + 0x4c)=0;
((SetupMenuObj *)panel)->v8();
*(u8 *)((u8 *)panel + 0x48)=0;*(u8 *)((u8 *)panel + 0x44)=0;
q=*(void * *)((u8 *)self + 0x54);
list=q;
if (!q) {
 p=Heap_Alloc(0xd8);
 if(p) {sp18[0]=0x128;sp18[1]=0x9a;sp14[0]=0x260;sp14[1]=0x6c;p=fn_80193B60(p,sp14,sp18,0x1f4);}
 *(void * *)((u8 *)self + 0x54)=p;
 q=*(void * *)((u8 *)self + 0x54); if(q) *(s32 *)((u8 *)q + 0x4)+=1;
 list=*(void * *)((u8 *)self + 0x54);
 *(s16 *)((u8 *)list + 0x8)=8;*(s16 *)((u8 *)list + 0x24)=8;*(s16 *)((u8 *)list + 0x5a)=0x1a;*(s16 *)((u8 *)list + 0x64)=2;
 ((SetupMenuObj *)list)->v12(4);
 *(s16 *)((u8 *)list + 0x58)=2;
 for(walk=*(void **)gUnitLists;walk;walk=*(void * *)((u8 *)walk + 0x184)) fn_8013B064(list,walk);
 for(walk=*(void **)(gUnitLists+0x3c);walk;walk=*(void * *)((u8 *)walk + 0x184)) fn_8013B064(list,walk);
 q=*(void **)gUiContext;if(q) fn_8013AD70(list,q);
}
*(u8 *)((u8 *)list + 0x4c)=0;Ui_AddChild(self,list);
if(*(s16 *)((u8 *)list + 0xa)!=0x118){y=*(s16 *)((u8 *)list + 0xc);sp10[0]=0x118;sp10[1]=y;Ui_SlideWidgetChildMode1(self,list,sp10,0);}
if((*Item_GetFlagsPtr(item)&5ULL)!=0) {
 p=Heap_Alloc(0x78);if(p)p=fn_80193950(p,0x260,0x108,0x1f4);*(void * *)((u8 *)self + 0x60)=p;
} else {p=Heap_Alloc(0x78);if(p)p=fn_801938F8(p,0x260,0x108,0x1f4);*(void * *)((u8 *)self + 0x60)=p;}
q=*(void * *)((u8 *)self + 0x60);if(q)*(s32 *)((u8 *)q + 0x4)+=1;
*(s16 *)((u8 *)(*(void * *)((u8 *)self + 0x60)) + 0x8)=0xa;
*(s16 *)((u8 *)(*(void * *)((u8 *)self + 0x60)) + 0x24)=8;
*(u8 *)((u8 *)(*(void * *)((u8 *)self + 0x60)) + 0x48)=0;
panel=Heap_Alloc(0x48);
if(panel) {
q=panel;
*(void * *)((u8 *)q + 0x0)=lbl_8028FDB0;
*(s32 *)((u8 *)q + 0x4)=0;
*(void * *)((u8 *)q + 0x0)=lbl_80292230;
*(s16 *)((u8 *)q + 0x8)=-1;
*(s16 *)((u8 *)q + 0xa)=608;
*(s16 *)((u8 *)q + 0xc)=264;
*(s16 *)((u8 *)q + 0xe)=880;
*(s16 *)((u8 *)q + 0x10)=392;
*(s16 *)((u8 *)q + 0x12)=0;
*(s16 *)((u8 *)q + 0x14)=0;
*(s16 *)((u8 *)q + 0x16)=272;
*(s16 *)((u8 *)q + 0x18)=128;
*(s16 *)((u8 *)q + 0x1a)=0;
*(s16 *)((u8 *)q + 0x1c)=0;
*(u8 *)((u8 *)q + 0x1e)=0xff;
*(u8 *)((u8 *)q + 0x1f)=0xff;
*(u8 *)((u8 *)q + 0x20)=0xff;
*(u8 *)((u8 *)q + 0x21)=0xff;
*(s16 *)((u8 *)q + 0x22)=0x1f4;*(s16 *)((u8 *)q + 0x24)=0;
*(f32 *)((u8 *)q + 0x28)=lbl_8036B0A8;
*(f32 *)((u8 *)q + 0x2c)=lbl_8036B0A8;
*(f32 *)((u8 *)q + 0x30)=lbl_8036B0A8;
*(s32 *)((u8 *)q + 0x34)=0;*(s32 *)((u8 *)q + 0x38)=0;*(void * *)((u8 *)q + 0x0)=lbl_80296150;
*(s32 *)((u8 *)q + 0x3c)=0;*(s32 *)((u8 *)q + 0x40)=0;
((SetupMenuObj *)q)->v8();
}
*(void * *)((u8 *)self + 0x64)=panel;q=*(void * *)((u8 *)self + 0x64);if(q)*(s32 *)((u8 *)q + 0x4)+=1;
*(s16 *)((u8 *)(*(void * *)((u8 *)self + 0x64)) + 0x8)=0xb;
*(s16 *)((u8 *)(*(void * *)((u8 *)self + 0x64)) + 0x24)=8;
*(u32 *)((u8 *)(*(void * *)((u8 *)self + 0x64)) + 0x40)=*(u32 *)item;
*(s32 *)((u8 *)(*(void * *)((u8 *)self + 0x64)) + 0x3c)=1;
Ui_BringChildToFront(self,list);
if(*(s16 *)((u8 *)list + 0x4e)!=0x7fff){
Ui_AddChild(self,*(void * *)((u8 *)self + 0x60));
((SetupMenuObj *)(*(void * *)((u8 *)self + 0x60)))->v11(Ui_ListGetSelected(list));
q=*(void * *)((u8 *)self + 0x60);if(*(s16 *)((u8 *)q + 0xa)!=0x138){y=*(s16 *)((u8 *)q + 0xc);spc[0]=0x138;spc[1]=y;Ui_SlideWidgetChildMode1(self,q,spc,0);}
} else if(fn_8014D8DC(gBattleState)){
Ui_AddChild(self,*(void * *)((u8 *)self + 0x64));
q=*(void * *)((u8 *)self + 0x64);if(*(s16 *)((u8 *)q + 0xa)!=0x134){y=*(s16 *)((u8 *)q + 0xc);sp8[0]=0x134;sp8[1]=y;Ui_SlideWidgetChildMode1(self,q,sp8,0);}
}
TalkUi_ShowMsg(*(void * *)((u8 *)(*(void * *)((u8 *)self + 0x6c)) + 0x2c));
q=*(void * *)((u8 *)self + 0x6c);list=*(void * *)((u8 *)q + 0x70);res=Ui_FindChild(self,-0x1000,0);if(res)Ui_SetWidgetText(res,list);
}
#pragma cplusplus reset

#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma cplusplus reset

void fn_801B04F8(void *arg0) {
    void Ui_SlideWidgetChild(void *, void *, s16 *, s32);
    s16 spC[2];
    s16 sp8[2];
    void *p50;
    void *p58;
    s16 r7;

    p50 = *(void **)((u8 *)arg0 + 0x50);
    r7 = *(s16 *)((u8 *)p50 + 0xC);
    spC[0] = 0x260;
    spC[1] = r7;
    Ui_SlideWidgetChild(arg0, p50, spC, 0);
    p58 = *(void **)((u8 *)arg0 + 0x58);
    r7 = *(s16 *)((u8 *)p58 + 0xC);
    sp8[0] = 0x260;
    sp8[1] = r7;
    Ui_SlideWidgetChild(arg0, p58, sp8, 0);
}

#pragma cplusplus on
extern "C" void fn_801B0564(void *arg0) {
    void Process_Goto(void *, s32);
    void Process_ClearFunc(void *);
    void fn_8001BC5C(void *, u8, u8, u8, u8);
    void Ui_UpdatePanelWidgets(void *);
    void Ui_PlaySeCue(void *, s32);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_ShowUnitInfoText(void *, s32, f32, f32);
    void Ui_HideUnitInfoPopup(void *);
    void Ui_OpenUnitInfoText(void *, void *, s32, f32, f32);
    extern u8 gFShopStrings[];
    extern u8 gUnitInfoPopup[];
    extern u8 lbl_80331C38[];
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
        virtual s32 v9() = 0;
        virtual Pair v10() = 0;
    };
    struct RefObj {
        virtual void v0(s32) = 0;
    };

    void *p;
    void *color_arg;
    void *self;
    s16 saved;
    s16 cur;
    void *tmp;
    s32 a;
    register int btn;
    register u8 gate;
    register int flags;
    u32 pos1;
    u32 color;
    u32 pos2;

    self = arg0;
    p = *(void **)((u8 *)arg0 + 0x50);
    tmp = *(void **)((u8 *)arg0 + 0x58);
    color_arg = *(void **)((u8 *)p + 0x3C);
    saved = *(s16 *)((u8 *)tmp + 0x3E);
    *(u8 *)((u8 *)tmp + 0x3C) = 1;
    Ui_UpdatePanelWidgets(self);
    tmp = *(void **)((u8 *)self + 0x58);
    a = saved;
    cur = *(s16 *)((u8 *)tmp + 0x3E);
    if (a != cur) {
        saved = cur;
        if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            *(Pair *)&pos1 = ((Obj *)*(void **)((u8 *)self + 0x58))->v10();
            Ui_ShowUnitInfoText(gUnitInfoPopup, ((Obj *)*(void **)((u8 *)self + 0x58))->v9(), (f32)*(s16 *)&pos1, (f32)*((s16 *)&pos1 + 1));
        }
    }

    color = *(u32 *)&lbl_80331C38[(*(s16 *)((u8 *)*(void **)((u8 *)self + 0x58) + 0x40) + 1) * 4];
    fn_8001BC5C(color_arg, ((u8 *)&color)[0], ((u8 *)&color)[1], ((u8 *)&color)[2], ((u8 *)&color)[3]);

    flags = gUiInputFlags;
    gate = 0;
    if ((flags & 0x10) && !(flags & 0x20)) {
        gate = 1;
    }
    if (!gate) {
        btn = *(s32 *)((u8 *)gPadInput + 4);
        btn = btn & (*(s32 *)((u8 *)gPadInput + 8) ^ btn);
        if ((btn & 0x100) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            switch (saved) {
            case 0:
                Ui_PlaySeCue(gFShopStrings + 0x3B0, 0x64);
                break;
            case 1:
                *(s16 *)((u8 *)*(void **)((u8 *)self + 0x58) + 0x40) = -1;
                Ui_PlaySeCue(gFShopStrings + 0x37E, 0x64);
                break;
            case 2:
                Ui_PlaySeCue(gFShopStrings + 0x37E, 0x64);
                Process_ClearFunc(self);
                break;
            }
        } else if ((btn & 0x1000) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            *(s16 *)((u8 *)*(void **)((u8 *)self + 0x58) + 0x3E) = 2;
        } else if ((btn & 0x800) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            *(Pair *)&pos2 = ((Obj *)*(void **)((u8 *)self + 0x58))->v10();
            Ui_OpenUnitInfoText(gUnitInfoPopup, self, ((Obj *)*(void **)((u8 *)self + 0x58))->v9(), (f32)*(s16 *)&pos2, (f32)*((s16 *)&pos2 + 1));
            *(s32 *)gUnitInfoPopup = *(s32 *)gUnitInfoPopup | gUnitInfoPopupFlag;
        } else if ((btn & 0xA00) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            Ui_HideUnitInfoPopup(gUnitInfoPopup);
        } else if ((btn & 0x200) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            void *obj4c;
            void *obj58;
            s32 n;
            Ui_PlaySeCue(gFShopStrings + 0x3A0, 0x64);
            obj4c = *(void **)((u8 *)self + 0x4C);
            Ui_SlideWidgetChild(self, obj4c, Pair(0x260, *(s16 *)((u8 *)obj4c + 0xC)), 0);
            obj58 = *(void **)((u8 *)self + 0x58);
            Ui_SlideWidgetChild(self, obj58, Pair(0x260, *(s16 *)((u8 *)obj58 + 0xC)), 0);
            obj58 = *(void **)((u8 *)self + 0x58);
            if (obj58 != NULL) {
                n = *(s32 *)((u8 *)obj58 + 4) - 1;
                *(s32 *)((u8 *)obj58 + 4) = n;
                if (n == 0 && obj58 != NULL) {
                    ((RefObj *)obj58)->v0(1);
                }
                *(void **)((u8 *)self + 0x58) = NULL;
            }
            Ui_SlideWidgetChild(self, p, Pair(0x260, *(s16 *)((u8 *)*(void **)((u8 *)self + 0x50) + 0xC)), 0);
            Process_Goto(self, 0x10);
        }
    }
}

extern "C" void fn_801B0978(void *arg0) {
 void *Ui_FindChild(void *,s32,s32);
 void Ui_AddChild(void *,void *);
 void Ui_SlideWidgetChildMode1(void *,void *,s16 *,s32);
 void TalkUi_ShowMsg(s32);
 void Ui_BringChildToFront(void *,void *);
 void Ui_SetWidgetText(void *,s32);
 s16 a[2],b[2],c[2];
 s32 text;
 void *p;
 s16 y;
 p=Ui_FindChild(arg0,4,0);
 if(!p){p=M2C_FIELD(arg0,void **,0x4c);Ui_AddChild(arg0,p);}
 if(M2C_FIELD(p,s16 *,10)!=0x138){a[0]=0x138;a[1]=0x74;Ui_SlideWidgetChildMode1(arg0,p,a,0);}
 p=Ui_FindChild(arg0,5,0);
 if(!p){p=M2C_FIELD(arg0,void **,0x50);Ui_AddChild(arg0,p);}
 if(M2C_FIELD(p,s16 *,10)!=0x138){y=M2C_FIELD(p,s16 *,12);b[0]=0x138;b[1]=y;Ui_SlideWidgetChildMode1(arg0,p,b,0);}
 p=Ui_FindChild(arg0,7,0);
 if(!p){p=M2C_FIELD(arg0,void **,0x58);Ui_AddChild(arg0,p);}
 if(M2C_FIELD(p,s16 *,10)!=0x138){y=M2C_FIELD(p,s16 *,12);c[0]=0x138;c[1]=y;Ui_SlideWidgetChildMode1(arg0,p,c,0);}
 Ui_BringChildToFront(arg0,p);
 TalkUi_ShowMsg(M2C_FIELD(M2C_FIELD(arg0,void **,0x6c),s32 *,0x28));
 text=M2C_FIELD(M2C_FIELD(arg0,void **,0x6c),s32 *,0x7c);
 p=Ui_FindChild(arg0,-0x1000,0);
 if(p) Ui_SetWidgetText(p,text);
}

extern "C" void fn_801B0AEC(void *arg0) {
#pragma cplusplus on
    void *Heap_Alloc(s32);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *, s32);
    extern u8 lbl_8028FDB0[], lbl_80292230[], lbl_8029759C[];
    extern f32 lbl_8036B0A8;
    u8 *obj;
    u8 *derivedTable;
    s32 caption;
    void *child;
    obj = (u8 *)Heap_Alloc(0x48);
    if (obj) {
        derivedTable = lbl_8029759C;
        *(void **)obj = lbl_8028FDB0;
        *(s32 *)(obj + 4) = 0;
        *(void **)obj = lbl_80292230;
        *(s16 *)(obj + 8) = -1;
        *(s16 *)(obj + 0xA) = 0x260;
        *(s16 *)(obj + 0xC) = 0x108;
        *(s16 *)(obj + 0xE) = 0x368;
        *(s16 *)(obj + 0x10) = 0x180;
        *(s16 *)(obj + 0x12) = 0;
        *(s16 *)(obj + 0x14) = 0;
        *(s16 *)(obj + 0x16) = 0x108;
        *(s16 *)(obj + 0x18) = 0x78;
        *(s16 *)(obj + 0x1A) = 0;
        *(s16 *)(obj + 0x1C) = 0;
        obj[0x1E] = 0xFF;
        obj[0x1F] = 0xFF;
        obj[0x20] = 0xFF;
        obj[0x21] = 0xFF;
        *(s16 *)(obj + 0x22) = 0x1F4;
        *(s16 *)(obj + 0x24) = 0;
        *(f32 *)(obj + 0x28) = 0.0f;
        *(f32 *)(obj + 0x2C) = 0.0f;
        *(f32 *)(obj + 0x30) = 0.0f;
        *(s32 *)(obj + 0x34) = 0;
        *(s32 *)(obj + 0x38) = 0;
        *(void **)obj = derivedTable;
        obj[0x3C] = 1;
        *(s16 *)(obj + 0x3E) = 2;
        *(s16 *)(obj + 0x40) = -1;
        *(s16 *)(obj + 0x42) = -1;
        *(s16 *)(obj + 0x44) = -1;
        ((SetupMenuObj *)obj)->v8();
    }
    *(u8 **)((u8 *)arg0 + 0x58) = obj;
    obj = *(u8 **)((u8 *)arg0 + 0x58);
    if (obj) (*(s32 *)(obj + 4))++;
    *(s16 *)(*(u8 **)((u8 *)arg0 + 0x58) + 8) = 7;
    (*(u8 **)((u8 *)arg0 + 0x58))[0x3C] = 0;
    *(s16 *)(*(u8 **)((u8 *)arg0 + 0x58) + 0x24) = 8;
    caption = *(s32 *)(*(u8 **)((u8 *)arg0 + 0x6C) + 0x7C);
    child = Ui_FindChild(arg0, -0x1000, 0);
    if (child) Ui_SetWidgetText(child, caption);
#pragma cplusplus reset
}

#pragma cplusplus reset
#pragma opt_common_subs off
void fn_801B0C70(void *arg0) {
    void fn_8011D650(void);
    void fn_8001BD4C(void *, void *);
    s32 UnitRef_GetName(void *);
    s32 fn_8001ED58(void *);
    s32 Str_Cmp(s32, s32);
    void fn_8001BCF4(void *);
    void Process_Goto(void *, s32);
    extern struct unk_struct lbl_80331C6C;
    extern u8 gUiContext[];
    void *obj48;
    s32 name;
    void *ptr;
    s32 flag;

    obj48 = *(void **)((u8 *)arg0 + 0x48);
    fn_8011D650();
    fn_8001BD4C((u8 *)obj48 + 0x60, &lbl_80331C6C);
    flag = (s32)gUiContext[8];
    switch (flag) {
    case 0:
        ptr = *(void **)((u8 *)obj48 + 0x60);
        name = UnitRef_GetName((u8 *)obj48 + 0x60);
        if (Str_Cmp(fn_8001ED58(ptr), name) == 0) {
            fn_8001BCF4((u8 *)obj48 + 0x60);
        }
        Process_Goto(arg0, 0xE);
        break;
    default:
        ptr = *(void **)((u8 *)obj48 + 0x60);
        name = UnitRef_GetName((u8 *)obj48 + 0x60);
        if (Str_Cmp(fn_8001ED58(ptr), name) == 0) {
            fn_8001BCF4((u8 *)obj48 + 0x60);
        }
        if (*(s16 *)((u8 *)*(void **)((u8 *)arg0 + 0x40) + 0x3E) == 4) {
            Process_Goto(arg0, 0x16);
        }
        break;
    }
}
#pragma opt_common_subs on
void fn_801B0D6C(void *arg0) {
    s32 UnitRef_GetName(void *);
    s32 fn_8001ED58(void);
    void Str_CopyPad(void *, s32, s32);
    void fn_801CE11C(void *, s32, s32, void *);
    void TalkUi_ShowMsg(s32);
    u32 Ui_FindChild(void *, s32, s32, void *);
    void Ui_SetWidgetText(u32, s32);
    struct Obj48 { u8 pad[0x60]; void *p60; };
    s32 saved;
    u8 b;
    void *obj6c;
    struct Obj48 *obj48;
    register unsigned long res;

    obj48 = *(struct Obj48 **)((u8 *)arg0 + 0x48);
    Str_CopyPad(&lbl_80331C6C, UnitRef_GetName(&obj48->p60), 0x14);
    ((u8 *)&lbl_80331C6C)[0x14] = b = 0;
    if (obj48->p60 != NULL) {
        b = *(u8 *)((u8 *)obj48->p60 + 0x15);
    }
    fn_801CE11C(&lbl_80331C6C, fn_8001ED58(), (u8)b + 0x61, arg0);
    TalkUi_ShowMsg(*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0x24));
    obj6c = *(void **)((u8 *)arg0 + 0x6C);
    saved = *(s32 *)((u8 *)obj6c + 0x6C);
    res = Ui_FindChild(arg0, -0x1000, 0, obj6c);
    if (res != 0U) {
        Ui_SetWidgetText(res, saved);
    }
}

void fn_801B0E38(void *arg0) {
 void Ui_SlideWidgetChild(void *,void *,s16 *,s32);
 void Process_Goto(void *,s32);
 extern u8 gUiContext[];
 s16 a[2],b[2],c[2],d[2],e[2];
 void *p;
 s16 y;
 switch(gUiContext[8]) {
 case 0x81:
 p=M2C_FIELD(arg0,void **,0x4c);y=M2C_FIELD(p,s16 *,12);a[0]=0x260;a[1]=y;Ui_SlideWidgetChild(arg0,p,a,0);
 p=M2C_FIELD(arg0,void **,0x48);y=M2C_FIELD(p,s16 *,12);b[0]=0x260;b[1]=y;Ui_SlideWidgetChild(arg0,p,b,0);
 if(M2C_FIELD(M2C_FIELD(arg0,void **,0x40),s16 *,0x3e)!=4) {
 p=M2C_FIELD(arg0,void **,0x50);y=M2C_FIELD(p,s16 *,12);c[0]=0x260;c[1]=y;Ui_SlideWidgetChild(arg0,p,c,0);
 } break;
 case 0x80:
 if(M2C_FIELD(M2C_FIELD(arg0,void **,0x40),s16 *,0x3e)!=4) {
 p=M2C_FIELD(arg0,void **,0x50);y=M2C_FIELD(p,s16 *,12);d[0]=0x260;d[1]=y;Ui_SlideWidgetChild(arg0,p,d,0);
 }
 p=M2C_FIELD(arg0,void **,0x48);y=M2C_FIELD(p,s16 *,12);e[0]=0x260;e[1]=y;Ui_SlideWidgetChild(arg0,p,e,0);
 Process_Goto(arg0,0x16);break;
 }
}

void fn_801B0F60(void *arg0) {
    void Ui_CreateMenu(void *, void *, s32);
    void *fn_8013BC10(s32, s32);
    u32 Ui_FindChild(void *, s32, s32, void *);
    void Ui_SetWidgetText(u32, s32);
    s32 temp_r31;
    void *temp_r3;
    void *temp_r6;
    u32 res;

    temp_r3 = fn_8013BC10(0, 0);
    *(s16 *)((u8 *)temp_r3 + 8) = 0x198;
    *(s16 *)((u8 *)temp_r3 + 0xA) = 0x3C;
    *(u8 *)((u8 *)temp_r3 + 0x24) = 1;
    Ui_CreateMenu(temp_r3, arg0, 0);
    temp_r6 = *(void **)((u8 *)arg0 + 0x6C);
    temp_r31 = *(s32 *)((u8 *)temp_r6 + 0x8C);
    res = Ui_FindChild(arg0, -0x1000, 0, temp_r6);
    if (res != 0U) {
        Ui_SetWidgetText(res, temp_r31);
    }
}

void fn_801B0FE0(void *arg0) {
 void *Ui_FindChild(void *,s32,s32);
 void Ui_AddChild(void *,void *);
 void Ui_SlideWidgetChildMode1(void *,void *,s16 *,s32);
 void TalkUi_ShowMsg(s32);
 s16 a[2],b[2],c[2];
 void *p;
 s16 y;
 p=Ui_FindChild(arg0,4,0);
 if(!p){p=M2C_FIELD(arg0,void **,0x4c);Ui_AddChild(arg0,p);}
 if(M2C_FIELD(p,s16 *,10)!=0x138){a[0]=0x138;a[1]=0x74;Ui_SlideWidgetChildMode1(arg0,p,a,0);}
 p=Ui_FindChild(arg0,6,0);
 if(!p){p=M2C_FIELD(arg0,void **,0x48);Ui_AddChild(arg0,p);}
 if(M2C_FIELD(p,s16 *,10)!=0x138){y=M2C_FIELD(p,s16 *,12);b[0]=0x138;b[1]=y;Ui_SlideWidgetChildMode1(arg0,p,b,0);}
 if(M2C_FIELD(M2C_FIELD(arg0,void **,0x40),s16 *,0x3e)!=4){
 p=Ui_FindChild(arg0,5,0);
 if(!p){p=M2C_FIELD(arg0,void **,0x50);Ui_AddChild(arg0,p);}
 if(M2C_FIELD(p,s16 *,10)!=0x138){y=M2C_FIELD(p,s16 *,12);c[0]=0x138;c[1]=y;Ui_SlideWidgetChildMode1(arg0,p,c,0);}
 }
 TalkUi_ShowMsg(M2C_FIELD(M2C_FIELD(arg0,void **,0x6c),s32 *,0x20));
}

void fn_801B1130(void *arg0)
{
    extern void Forge_BindWeaponActor(void *, void *);

    u8 *obj;
    u8 *data;
    u8 *state;
    u8 *target;

    obj = (u8 *)arg0;
    data = *(u8 **)(obj + 0x48);

    data[0x3C] = 0;

    state = *(u8 **)(obj + 0x40);

    if (*(s16 *)(state + 0x3E) != 4) {
        target = *(u8 **)(obj + 0x50);
        Forge_BindWeaponActor(target, data + 0x60);
    }

    target = *(u8 **)(obj + 0x4C);
    *(void **)(target + 0x3C) = data + 0x60;
}

void fn_801B1194(s32 arg0) {
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern u8 gFShopStrings[];
    
    s32 temp_r4;
    u8 var_r3;

    var_r3 = 0;
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20)) {
        var_r3 = 1;
    }
    if (var_r3 == 0) {
        temp_r4 = *(s32*)((char*)gPadInput + 4);
        if (temp_r4 & (*(s32*)((char*)gPadInput + 8) ^ temp_r4) & 0x300) {
            Ui_PlaySeCue(&gFShopStrings[0x36E], 0x64);
            Process_ClearFunc(arg0);
        }
    }
}

extern s32 gActorXmlStrs[];
extern u16* lbl_80296128;
void fn_801B1218(void *self) {
    void TalkUi_ShowMsg(s32);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *, s32);
    void fn_8014D268(void *, s32);
    void fn_8001BF3C(void *, s32);
    void fn_8001BEC0(void *, s32);
    void fn_8001BE44(void *, s32);
    void fn_8001BDC8(void *, s32);
    void Ui_SlideWidgetChild(void *, void *, s16 *, s32);
    void fn_801402A0(void *, void *, s16 *, s32);
    void fn_8014017C(void *, void *, s16 *, s32);
    void Forge_BindWeaponActor(void *, void *);
    void Process_Goto(void *, s32);
    extern u8 gUiContext[];
    extern u8 gBattleState[];
    void *obj;
    void *child;
    void *child2;
    void *weapon;
    void *slide;
    s16 pos[2];
    s16 pos2[2];
    s16 pos3[2];
    s32 text;

    obj = *(void **)((u8 *)self + 0x48);
    switch (gUiContext[8]) {
    case 0x81:
        TalkUi_ShowMsg(*(s32 *)((u8 *)*(void **)((u8 *)self + 0x6C) + 0x1C));
        text = *(s32 *)((u8 *)*(void **)((u8 *)self + 0x6C) + 0x84);
        child = Ui_FindChild(self, -0x1000, 0);
        if (child != NULL) {
            Ui_SetWidgetText(child, text);
        }
        child2 = Ui_FindChild(self, 2, 0);
        fn_8014D268(gBattleState, *(s32 *)(gBattleState + 0x18) - *(s32 *)((u8 *)child2 + 0x3C));
        weapon = (u8 *)obj + 0x60;
        fn_8001BF3C(weapon, (s8)((u8 *)obj)[0x51]);
        fn_8001BEC0(weapon, (s8)((u8 *)obj)[0x52]);
        fn_8001BE44(weapon, (s8)((u8 *)obj)[0x53]);
        fn_8001BDC8(weapon, (s8)((u8 *)obj)[0x54]);
        ((u8 *)obj)[0x54] = 0;
        ((u8 *)obj)[0x53] = 0;
        ((u8 *)obj)[0x52] = 0;
        ((u8 *)obj)[0x51] = 0;
        ((u8 *)obj)[0x3C] = 0;
        ((u8 *)obj)[0x50] = 0;
        pos[0] = 0x260;
        pos[1] = *(s16 *)((u8 *)child2 + 0xC);
        Ui_SlideWidgetChild(self, child2, pos, 0);
        if (*(s16 *)((u8 *)*(void **)((u8 *)self + 0x40) + 0x3E) != 4) {
            ((u8 *)obj)[0x3D] = 0;
            pos2[0] = *(s16 *)((u8 *)obj + 0xA);
            pos2[1] = 0x108;
            fn_801402A0(self, obj, pos2, 0);
        }
        slide = *(void **)((u8 *)self + 0x50);
        ((u8 *)slide)[0x44] = 1;
        pos3[0] = (s16)(*(s16 *)((u8 *)slide + 0xE) - *(s16 *)((u8 *)slide + 0xA));
        pos3[1] = 0xE0;
        fn_8014017C(self, slide, pos3, 0);
        Forge_BindWeaponActor(slide, weapon);
        *(void **)((u8 *)*(void **)((u8 *)self + 0x4C) + 0x3C) = weapon;
        break;
    case 0x80:
        Process_Goto(self, 0xB);
        break;
    }
}

void fn_801B1400(void *arg0) {
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
    temp_r6 = *(void **)((u8 *)arg0 + 0x6C);
    temp_r31 = *(s32 *)((u8 *)temp_r6 + 0x8C);
    res = Ui_FindChild(arg0, -0x1000, 0, temp_r6);
    if (res != 0U) {
        Ui_SetWidgetText(res, temp_r31);
    }
}

void fn_801B1480(void *arg0) {
    void fn_8000D8BC(s32, s32, void *);
    void TalkUi_ShowMsg(s32);
    void *Ui_FindChild(void *, s32, s32);
    void *temp_r5;

    temp_r5 = Ui_FindChild(arg0, 2, 0);
    *(s8 *)(*(u8 **)((u8 *)arg0 + 0x48) + 0x3C) = 0;
    fn_8000D8BC(0, *(s32 *)((u8 *)temp_r5 + 0x3C), temp_r5);
    TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)arg0 + 0x6C) + 0x18));
}

#pragma cplusplus on
extern "C" void fn_801B14DC(void *arg0) {
    void Process_Goto(void *, s32);
    void Process_ClearFunc(void *);
    s32 fn_8001C284(void *, u8, s8, s8, s8, s8);
    u16 UnitRef_GetValue(void *);
    void TalkUi_ShowMsg(s32);
    void Ui_UpdatePanelWidgets(void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_CloseChildAnim(void *, void *, s32);
    void Ui_PlaySeCue(void *, s32);
    void Ui_SetWidgetText(void *, s32);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_ShowUnitInfoText(void *, s32, f32, f32);
    void Ui_HideUnitInfoPopup(void *);
    void Ui_OpenUnitInfoText(void *, void *, s32, f32, f32);
    extern u8 gFShopStrings[];
    extern u8 gBattleState[];
    extern u8 gUnitInfoPopup[];
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern void *gUnitRef;
    extern u8 lbl_80368238;
    extern s32 gUnitInfoPopupFlag;

    class Pair {
    public:
        s16 x;
        s16 y;
        Pair() {}
        Pair(const Pair &o) { *(u32 *)this = *(u32 *)&o; }
        Pair &operator=(const Pair &o) { *(u32 *)this = *(u32 *)&o; return *this; }
    };
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual s32 v8() = 0;
        virtual Pair v9() = 0;
    };
    struct RefObj {
        virtual void v0(s32) = 0;
    };
    struct Child {
        u8 pad[0x3C];
        s32 unk3C;
    };

    void *self;
    Child *child;
    void *obj;
    s16 saved;
    s32 a;
    s32 score;
    u16 addend;
    register int btn;
    register u8 gate;
    register int flags;
    register u32 bit100;
    void *ret;
    u32 pos1;
    u32 pos2;

    self = arg0;
    child = (Child *)Ui_FindChild(arg0, 2, 0);
    obj = *(void **)((u8 *)arg0 + 0x48);
    saved = *(s16 *)((u8 *)obj + 0x3E);
    *(u8 *)((u8 *)obj + 0x3C) = 1;
    Ui_UpdatePanelWidgets(arg0);
    a = saved;
    if (a != *(s16 *)((u8 *)*(void **)((u8 *)arg0 + 0x48) + 0x3E)) {
        if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            *(Pair *)&pos1 = ((Obj *)*(void **)((u8 *)arg0 + 0x48))->v9();
            Ui_ShowUnitInfoText(gUnitInfoPopup, ((Obj *)*(void **)((u8 *)arg0 + 0x48))->v8(), (f32)*(s16 *)&pos1, (f32)*((s16 *)&pos1 + 1));
        }
    }
    obj = *(void **)((u8 *)arg0 + 0x48);
    score = fn_8001C284(*(void **)((u8 *)obj + 0x60), *(u8 *)((u8 *)obj + 0x64),
                        (s8)*(u8 *)((u8 *)obj + 0x51), (s8)*(u8 *)((u8 *)obj + 0x52),
                        (s8)*(u8 *)((u8 *)obj + 0x53), (s8)*(u8 *)((u8 *)obj + 0x54));
    addend = UnitRef_GetValue(&gUnitRef);
    score = addend + score;
    child->unk3C = score;

    flags = gUiInputFlags;
    gate = 0;
    if ((flags & 0x10) && !(flags & 0x20)) {
        gate = 1;
    }
    if (!gate) {
        btn = *(s32 *)((u8 *)gPadInput + 4);
        btn = btn & (*(s32 *)((u8 *)gPadInput + 8) ^ btn);
        bit100 = btn & 0x100;
        if (bit100 != 0 && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            obj = *(void **)((u8 *)arg0 + 0x48);
            if (*(s16 *)((u8 *)obj + 0x3E) != 4) {
                switch (*(s32 *)((u8 *)obj + 0x4C)) {
                case 0:
                    lbl_80368238 = *(u8 *)((u8 *)obj + 0x51);
                    (&lbl_80368238)[1] = *(u8 *)((u8 *)obj + 0x52);
                    (&lbl_80368238)[2] = *(u8 *)((u8 *)obj + 0x53);
                    (&lbl_80368238)[3] = *(u8 *)((u8 *)obj + 0x54);
                    *(s32 *)((u8 *)obj + 0x4C) = 1;
                    self = (void *)*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0x78);
                    ret = Ui_FindChild(arg0, -0x1000, 0);
                    if (ret != NULL) {
                        Ui_SetWidgetText(ret, (s32)self);
                    }
                    break;
                case 1:
                    *(s32 *)((u8 *)obj + 0x4C) = 0;
                    self = (void *)*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0x74);
                    ret = Ui_FindChild(arg0, -0x1000, 0);
                    if (ret != NULL) {
                        Ui_SetWidgetText(ret, (s32)self);
                    }
                    break;
                }
                Ui_PlaySeCue(gFShopStrings + 0x37E, 0x64);
                return;
            }
        }
        if (bit100 != 0 && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0 &&
            *(s16 *)((u8 *)*(void **)((u8 *)arg0 + 0x48) + 0x3E) == 4) {
            if (score > *(s32 *)(gBattleState + 0x18)) {
                Ui_PlaySeCue(gFShopStrings + 0x3B0, 0x64);
                TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)arg0 + 0x6C) + 0x38));
                self = (void *)*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0x84);
                ret = Ui_FindChild(arg0, -0x1000, 0);
                if (ret != NULL) {
                    Ui_SetWidgetText(ret, (s32)self);
                }
                Process_Goto(arg0, 0x1D);
            } else {
                Ui_PlaySeCue(gFShopStrings + 0x37E, 0x64);
                Process_ClearFunc(arg0);
            }
            return;
        }
        if ((btn & 0x1000) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            obj = *(void **)((u8 *)arg0 + 0x48);
            if (*(s32 *)((u8 *)obj + 0x4C) == 1) {
                *(s32 *)((u8 *)obj + 0x4C) = 0;
                self = (void *)*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0x74);
                ret = Ui_FindChild(arg0, -0x1000, 0);
                if (ret != NULL) {
                    Ui_SetWidgetText(ret, (s32)self);
                }
            }
            *(s16 *)((u8 *)*(void **)((u8 *)arg0 + 0x48) + 0x3E) = 4;
            Ui_PlaySeCue(gFShopStrings + 0x37E, 0x64);
            return;
        }
        if ((btn & 0x800) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            *(Pair *)&pos2 = ((Obj *)*(void **)((u8 *)arg0 + 0x48))->v9();
            Ui_OpenUnitInfoText(gUnitInfoPopup, arg0, ((Obj *)*(void **)((u8 *)arg0 + 0x48))->v8(),
                        (f32)*(s16 *)&pos2, (f32)*((s16 *)&pos2 + 1));
            *(s32 *)gUnitInfoPopup = *(s32 *)gUnitInfoPopup | gUnitInfoPopupFlag;
            return;
        }
        if ((btn & 0xA00) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            Ui_HideUnitInfoPopup(gUnitInfoPopup);
            return;
        }
        if ((btn & 0x200) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            obj = *(void **)((u8 *)arg0 + 0x48);
            if (*(s32 *)((u8 *)obj + 0x4C) == 1) {
                *(u8 *)((u8 *)obj + 0x51) = lbl_80368238;
                *(u8 *)((u8 *)obj + 0x52) = (&lbl_80368238)[1];
                *(u8 *)((u8 *)obj + 0x53) = (&lbl_80368238)[2];
                *(u8 *)((u8 *)obj + 0x54) = (&lbl_80368238)[3];
                *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x48) + 0x4C) = 0;
                self = (void *)*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0x74);
                ret = Ui_FindChild(arg0, -0x1000, 0);
                if (ret != NULL) {
                    Ui_SetWidgetText(ret, (s32)self);
                }
                Ui_PlaySeCue(gFShopStrings + 0x3A0, 0x64);
                return;
            }
            Ui_PlaySeCue(gFShopStrings + 0x3A0, 0x64);
            Ui_CloseChildAnim(arg0, *(void **)((u8 *)arg0 + 0x48), 0);
            obj = *(void **)((u8 *)arg0 + 0x48);
            if (obj != NULL) {
                s32 n = *(s32 *)((u8 *)obj + 4) - 1;
                *(s32 *)((u8 *)obj + 4) = n;
                if (n == 0 && obj != NULL) {
                    ((RefObj *)obj)->v0(1);
                }
                *(void **)((u8 *)arg0 + 0x48) = NULL;
            }
            Process_Goto(arg0, 8);
        }
    }
}

#pragma cplusplus reset
void Ui_ShowConfirmChild(void *panel) {
    u32 Ui_FindChild();
    void Ui_AddChild(void *, void *);
    f32 Ui_GetWorldScale(void *);
    void Ui_OpenChildAnim(void *, void *, s32);
    void Ui_BringChildToFront(void *, void *);
    void TalkUi_ShowMsg(void *);
    void Ui_SetWidgetText(u32, s32);
    extern f32 lbl_8036B0A8;
    void *child;
    void *ctx;
    s32 text;
    u32 widget;

    /* Show confirm child 6 (or +0x48), talk message, and mode 0/1 help text. */
    child = (void *)Ui_FindChild(panel, 6, 0);
    if (child == NULL) {
        child = *(void **)((u8 *)panel + 0x48);
        Ui_AddChild(panel, child);
    }
    if (lbl_8036B0A8 != Ui_GetWorldScale(child)) {
        Ui_OpenChildAnim(panel, child, 0);
    }
    Ui_BringChildToFront(panel, child);
    TalkUi_ShowMsg(*(void **)((u8 *)*(void **)((u8 *)panel + 0x6C) + 0x14));
    switch (*(s32 *)((u8 *)child + 0x4C)) {
    case 0:
        ctx = *(void **)((u8 *)panel + 0x6C);
        text = *(s32 *)((u8 *)ctx + 0x74);
        widget = Ui_FindChild(panel, -0x1000, 0, ctx);
        if (widget != 0) {
            Ui_SetWidgetText(widget, text);
        }
        break;
    case 1:
        ctx = *(void **)((u8 *)panel + 0x6C);
        text = *(s32 *)((u8 *)ctx + 0x78);
        widget = Ui_FindChild(panel, -0x1000, 0, ctx);
        if (widget != 0) {
            Ui_SetWidgetText(widget, text);
        }
        break;
    }
}

/* Create the confirm child at self+0x48 (id 6), bind gUnitRef's item, slide it in, and set help text. */
void Ui_CreateConfirmChild(void *self) {
    void *Heap_Alloc(s32);
    void *Ui_ConfirmChild_Ctor(void *, s32, s32, s32, s32, s32);
    void Ui_ConfirmChild_BindItem(void *, void *);
    void Ui_AddChild(void *, void *);
    void Ui_OpenChildAnim(void *, void *, s32);
    u32 Ui_FindChild(void *, s32, s32, void *);
    void Ui_SetWidgetText(u32, s32);
    extern u8 gUnitRef;
    void *child;
    void *tmp;
    void *msgTable;
    s32 text;
    u32 widget;

    child = Heap_Alloc(0x68);
    if (child != NULL) {
        child = Ui_ConfirmChild_Ctor(child, 0x138, 0xA8, 0x108, 0x78, 0x190);
    }
    *(void **)((u8 *)self + 0x48) = child;
    tmp = *(void **)((u8 *)self + 0x48);
    if (tmp != NULL) {
        *(s32 *)((u8 *)tmp + 4) = *(s32 *)((u8 *)tmp + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 8) = 6;
    *(u8 *)((u8 *)*(void **)((u8 *)self + 0x48) + 0x3C) = 0;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 0x24) = 8;
    Ui_ConfirmChild_BindItem(*(void **)((u8 *)self + 0x48), &gUnitRef);
    Ui_AddChild(self, *(void **)((u8 *)self + 0x48));
    Ui_OpenChildAnim(self, *(void **)((u8 *)self + 0x48), 0);
    msgTable = *(void **)((u8 *)self + 0x6C);
    text = *(s32 *)((u8 *)msgTable + 0x74);
    widget = Ui_FindChild(self, -0x1000, 0, msgTable);
    if (widget != 0) {
        Ui_SetWidgetText(widget, text);
    }
}

void fn_801B1C60(void) {

}

void fn_801B1C64(void *arg0) {
    extern u8 gUiContext[24];
    void Ui_SlideWidgetChild(void *, void *, s16 *, s32);
    void Ui_SlideWidgetChildMode1(void *, void *, s16 *, s32);
    void Forge_BindWeaponActor(void *, s32);
    void Ui_AddChild(void *, void *);
    void Ui_BringChildToFront(void *, void *);
    void TalkUi_ShowMsg(s32);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *, s32);
    void Process_Goto(void *, s32);
#pragma cplusplus on
    struct RefObj { virtual void destroy(s32); s32 refCount; };
    u8 *self = (u8 *)arg0;
    u8 *widget;
    RefObj *child;
    s32 text;
    s16 y;
    s16 pos1[2], pos2[2], pos3[2], pos4[2];
    switch (gUiContext[8]) {
    case 0x80:
        widget = *(u8 **)(self + 0x4C);
        y = *(s16 *)(widget + 0xC); pos1[0] = 0x260; pos1[1] = y;
        Ui_SlideWidgetChild(self, widget, pos1, 0);
        child = *(RefObj **)(self + 0x4C);
        if (child) {
            if (--child->refCount == 0 && child) child->destroy(1);
            *(RefObj **)(self + 0x4C) = 0;
        }
        if (*(s16 *)(*(u8 **)(self + 0x40) + 0x3E) != 4) {
            Forge_BindWeaponActor(*(void **)(self + 0x50), 0);
            widget = *(u8 **)(self + 0x50);
            y = *(s16 *)(widget + 0xC); pos2[0] = 0x260; pos2[1] = y;
            Ui_SlideWidgetChild(self, widget, pos2, 0);
            child = *(RefObj **)(self + 0x50);
            if (child) {
                if (--child->refCount == 0 && child) child->destroy(1);
                *(RefObj **)(self + 0x50) = 0;
            }
        }
        widget = *(u8 **)(self + 0x40);
        Ui_AddChild(self, widget);
        y = *(s16 *)(widget + 0xC); pos3[0] = 0x138; pos3[1] = y;
        Ui_SlideWidgetChildMode1(self, widget, pos3, 0);
        widget = *(u8 **)(self + 0x44);
        *(s16 *)(widget + 0x24) = 8;
        Ui_AddChild(self, widget);
        y = *(s16 *)(widget + 0xC); pos4[0] = 0x118; pos4[1] = y;
        Ui_SlideWidgetChildMode1(self, widget, pos4, 0);
        Ui_BringChildToFront(self, widget);
        TalkUi_ShowMsg(*(s32 *)(*(u8 **)(self + 0x6C) + 0xC));
        text = *(s32 *)(*(u8 **)(self + 0x6C) + 0x6C);
        widget = (u8 *)Ui_FindChild(self, -0x1000, 0);
        if (widget) Ui_SetWidgetText(widget, text);
        Process_Goto(self, 7);
    case 0x81: return;
    }
#pragma cplusplus reset
}

void fn_801B1E54(void *arg0) {
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
    temp_r6 = *(void **)((u8 *)arg0 + 0x6C);
    temp_r31 = *(s32 *)((u8 *)temp_r6 + 0x8C);
    res = Ui_FindChild(arg0, -0x1000, 0, temp_r6);
    if (res != 0U) {
        Ui_SetWidgetText(res, temp_r31);
    }
}

void fn_801B1ED4(void *arg0) {
    void *Heap_Alloc(M2C_UNK);
    M2C_UNK TalkUi_ShowMsg(s32);
    u32 Ui_FindChild(void *, M2C_UNK, M2C_UNK);
    M2C_UNK Ui_AddChild(void *, void *);
    M2C_UNK Ui_SlideWidgetChildMode1(void *, s16 *, M2C_UNK, s16);
    M2C_UNK Forge_BindWeaponActor(void *, M2C_UNK *);
    extern M2C_UNK lbl_8028FDB0;
    extern M2C_UNK lbl_80292230;
    extern M2C_UNK lbl_80296228;
    extern M2C_UNK lbl_8029625C;
    extern M2C_UNK gUnitRef;
    extern f32 lbl_8036B0A8;
    s16 spE;
    s16 spC;
    s16 spA;
    s16 sp8;
    s16 temp_r7;
    s16 temp_r7_2;
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r4;
    void *temp_r4_2;
    void *temp_r4_3;
    void *temp_r4_4;

    if ((void *) M2C_FIELD(arg0, void **, 0x4C) == NULL) {
        temp_r3 = Heap_Alloc(0x50);
        if (temp_r3 != NULL) {
            M2C_FIELD(temp_r3, M2C_UNK **, 0) = &lbl_8028FDB0;
            M2C_FIELD(temp_r3, s32 *, 4) = 0;
            M2C_FIELD(temp_r3, M2C_UNK **, 0) = &lbl_80292230;
            M2C_FIELD(temp_r3, s16 *, 8) = -1;
            M2C_FIELD(temp_r3, s16 *, 0xA) = 0x260;
            M2C_FIELD(temp_r3, s16 *, 0xC) = 0x74;
            M2C_FIELD(temp_r3, s16 *, 0xE) = 0x368;
            M2C_FIELD(temp_r3, s16 *, 0x10) = 0x74;
            M2C_FIELD(temp_r3, s16 *, 0x12) = 0;
            M2C_FIELD(temp_r3, s16 *, 0x14) = 0;
            M2C_FIELD(temp_r3, s16 *, 0x16) = 0x108;
            M2C_FIELD(temp_r3, s16 *, 0x18) = 0;
            M2C_FIELD(temp_r3, s16 *, 0x1A) = 0;
            M2C_FIELD(temp_r3, s16 *, 0x1C) = 0;
            M2C_FIELD(temp_r3, s8 *, 0x1E) = 0xFF;
            M2C_FIELD(temp_r3, s8 *, 0x1F) = 0xFF;
            M2C_FIELD(temp_r3, s8 *, 0x20) = 0xFF;
            M2C_FIELD(temp_r3, s8 *, 0x21) = 0xFF;
            M2C_FIELD(temp_r3, s16 *, 0x22) = 0xBE;
            M2C_FIELD(temp_r3, s16 *, 0x24) = 0;
            M2C_FIELD(temp_r3, f32 *, 0x28) = (f32) lbl_8036B0A8;
            M2C_FIELD(temp_r3, f32 *, 0x2C) = (f32) lbl_8036B0A8;
            M2C_FIELD(temp_r3, f32 *, 0x30) = (f32) lbl_8036B0A8;
            M2C_FIELD(temp_r3, s32 *, 0x34) = 0;
            M2C_FIELD(temp_r3, s32 *, 0x38) = 0;
            M2C_FIELD(temp_r3, M2C_UNK **, 0) = &lbl_8029625C;
            M2C_FIELD(temp_r3, s32 *, 0x3C) = 0;
            M2C_FIELD(temp_r3, s32 *, 0x40) = 0;
            M2C_FIELD(temp_r3, s8 *, 0x44) = 0;
            M2C_FIELD(temp_r3, s16 *, 0x46) = 0x20;
            M2C_FIELD(temp_r3, s8 *, 0x48) = 0;
            M2C_FIELD(temp_r3, s16 *, 0x4A) = 0x14;
            M2C_FIELD(temp_r3, s16 *, 0x4C) = 0;
            M2C_FIELD(M2C_FIELD(temp_r3, M2C_UNK **, 0), M2C_UNK (**)(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x28)(0x20, &lbl_8029625C, 0xBE, 0xFF, 0x108, 0x368, 0x74);
        }
        M2C_FIELD(arg0, void **, 0x4C) = temp_r3;
        temp_r4 = M2C_FIELD(arg0, void **, 0x4C);
        if (temp_r4 != NULL) {
            M2C_FIELD(temp_r4, s32 *, 4) = (s32) (M2C_FIELD(temp_r4, s32 *, 4) + 1);
        }
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s16 *, 8) = 4;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s16 *, 0x24) = 8;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s8 *, 0x48) = 1;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s8 *, 0x44) = 0;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), M2C_UNK **, 0x3C) = &gUnitRef;
    }
    if (Ui_FindChild(arg0, 4, 0) == 0U) {
        Ui_AddChild(arg0, M2C_FIELD(arg0, void **, 0x4C));
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), M2C_UNK **, 0x3C) = &gUnitRef;
    temp_r4_2 = M2C_FIELD(arg0, void **, 0x4C);
    if ((s16) M2C_FIELD(temp_r4_2, s16 *, 0xA) != 0x138) {
        temp_r7 = M2C_FIELD(temp_r4_2, s16 *, 0xC);
        spC = 0x138;
        spE = temp_r7;
        Ui_SlideWidgetChildMode1(arg0, &spC, 0, temp_r7);
    }
    if ((s16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), s16 *, 0x3E) != 4) {
        if ((void *) M2C_FIELD(arg0, void **, 0x50) == NULL) {
            temp_r3_2 = Heap_Alloc(0x58);
            if (temp_r3_2 != NULL) {
                M2C_FIELD(temp_r3_2, M2C_UNK **, 0) = &lbl_8028FDB0;
                M2C_FIELD(temp_r3_2, s32 *, 4) = 0;
                M2C_FIELD(temp_r3_2, M2C_UNK **, 0) = &lbl_80292230;
                M2C_FIELD(temp_r3_2, s16 *, 8) = -1;
                M2C_FIELD(temp_r3_2, s16 *, 0xA) = 0x260;
                M2C_FIELD(temp_r3_2, s16 *, 0xC) = 0xA8;
                M2C_FIELD(temp_r3_2, s16 *, 0xE) = 0x368;
                M2C_FIELD(temp_r3_2, s16 *, 0x10) = 0x120;
                M2C_FIELD(temp_r3_2, s16 *, 0x12) = 0;
                M2C_FIELD(temp_r3_2, s16 *, 0x14) = 0;
                M2C_FIELD(temp_r3_2, s16 *, 0x16) = 0x108;
                M2C_FIELD(temp_r3_2, s16 *, 0x18) = 0x78;
                M2C_FIELD(temp_r3_2, s16 *, 0x1A) = 0;
                M2C_FIELD(temp_r3_2, s16 *, 0x1C) = 0;
                M2C_FIELD(temp_r3_2, s8 *, 0x1E) = 0xFF;
                M2C_FIELD(temp_r3_2, s8 *, 0x1F) = 0xFF;
                M2C_FIELD(temp_r3_2, s8 *, 0x20) = 0xFF;
                M2C_FIELD(temp_r3_2, s8 *, 0x21) = 0xFF;
                M2C_FIELD(temp_r3_2, s16 *, 0x22) = 0x1F4;
                M2C_FIELD(temp_r3_2, s16 *, 0x24) = 0;
                M2C_FIELD(temp_r3_2, f32 *, 0x28) = (f32) lbl_8036B0A8;
                M2C_FIELD(temp_r3_2, f32 *, 0x2C) = (f32) lbl_8036B0A8;
                M2C_FIELD(temp_r3_2, f32 *, 0x30) = (f32) lbl_8036B0A8;
                M2C_FIELD(temp_r3_2, s32 *, 0x34) = 0;
                M2C_FIELD(temp_r3_2, s32 *, 0x38) = 0;
                M2C_FIELD(temp_r3_2, M2C_UNK **, 0) = &lbl_80296228;
                M2C_FIELD(temp_r3_2, s32 *, 0x3C) = 0;
                M2C_FIELD(temp_r3_2, s32 *, 0x40) = 0;
                M2C_FIELD(temp_r3_2, s8 *, 0x44) = 1;
                M2C_FIELD(temp_r3_2, s32 *, 0x54) = 0;
                M2C_FIELD(M2C_FIELD(temp_r3_2, M2C_UNK **, 0), M2C_UNK (**)(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x28)(&lbl_80296228, 0x1F4, 0xFF, 0x78, 0x108, 0x120, 0x368);
            }
            M2C_FIELD(arg0, void **, 0x50) = temp_r3_2;
            temp_r4_3 = M2C_FIELD(arg0, void **, 0x50);
            if (temp_r4_3 != NULL) {
                M2C_FIELD(temp_r4_3, s32 *, 4) = (s32) (M2C_FIELD(temp_r4_3, s32 *, 4) + 1);
            }
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x50), s16 *, 8) = 5;
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x50), s16 *, 0x24) = 8;
        }
        Forge_BindWeaponActor(M2C_FIELD(arg0, void **, 0x50), &gUnitRef);
        if (Ui_FindChild(arg0, 5, 0) == 0U) {
            Ui_AddChild(arg0, M2C_FIELD(arg0, void **, 0x50));
        }
        temp_r4_4 = M2C_FIELD(arg0, void **, 0x50);
        if ((s16) M2C_FIELD(temp_r4_4, s16 *, 0xA) != 0x138) {
            temp_r7_2 = M2C_FIELD(temp_r4_4, s16 *, 0xC);
            sp8 = 0x138;
            spA = temp_r7_2;
            Ui_SlideWidgetChildMode1(arg0, &sp8, 0, temp_r7_2);
        }
    }
    TalkUi_ShowMsg(M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), s32 *, 0x10));
}

#pragma cplusplus on
extern "C" void Ui_HandleUnitPanelCursorInput(void *arg0) {
    /* Handle unit-panel cursor input: A buy/confirm (funds check), Y unit info, B cancel. */
    void Process_Goto(void *, s32);
    void Process_ClearFunc(void *);
    u16 UnitRef_GetValue(void *);
    void UnitRef_Set(void *, void *);
    void TalkUi_ShowMsg(s32);
    void *fn_80134280(void *);
    void Ui_UpdatePanelWidgets(void *);
    void Ui_BringChildToFront(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void fn_801402C4(void *, void *, s32, s32);
    void Ui_PlaySeCue(void *, s32);
    void Ui_SetWidgetText(void *, s32);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_ShowUnitInfoPopup(void *, void *, f32, f32);
    void Ui_HideUnitInfoPopup(void *);
    void Ui_OpenUnitInfoPopup(void *, void *, void *, f32, f32);
    extern u8 gFShopStrings[];
    extern u8 gBattleState[];
    extern u8 gUnitInfoPopup[];
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern void *gUnitRef;
    extern s32 gUnitInfoPopupFlag;
    extern f32 lbl_8036B0A8;
    extern f64 lbl_8036B0B0;

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
        virtual Pair v9() = 0;
    };
    struct RefObj {
        virtual void destroy(s32) = 0;
    };
    struct Child {
        u8 pad[0x3C];
        s32 cost;
    };

    void *panel40;
    void *unit;
    Child *child;
    void *self;
    register int btn;
    register u8 blocked;
    register int flags;
    void *owner;
    s32 saved;
    void *msg;
    void *panel44;
    void *tmp;
    u32 pos1;
    u32 pos2;

    self = arg0;
    child = (Child *)Ui_FindChild(arg0, 2, 0);
    tmp = fn_80134280(*(void **)((u8 *)arg0 + 0x44));
    *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x44) + 0x3C) = 1;
    unit = tmp;
    Ui_UpdatePanelWidgets(arg0);
    if (unit != fn_80134280(*(void **)((u8 *)arg0 + 0x44))) {
        unit = fn_80134280(*(void **)((u8 *)arg0 + 0x44));
        if (gUnitRef != unit) {
            UnitRef_Set(&gUnitRef, unit);
        }
        if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            *(Pair *)&pos1 = ((Obj *)*(void **)((u8 *)arg0 + 0x44))->v9();
            Ui_ShowUnitInfoPopup(gUnitInfoPopup, &gUnitRef, (f32)*(s16 *)&pos1, (f32)*((s16 *)&pos1 + 1));
        }
    }
    if (gUnitRef != unit) {
        UnitRef_Set(&gUnitRef, unit);
    }
    child->cost = UnitRef_GetValue(&gUnitRef);
    flags = gUiInputFlags;
    blocked = 0;
    if ((flags & 0x10) && !(flags & 0x20)) {
        blocked = 1;
    }
    if (!blocked) {
        btn = *(s32 *)((u8 *)gPadInput + 4);
        btn = btn & (*(s32 *)((u8 *)gPadInput + 8) ^ btn);
        if ((btn & 0x100) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            if (child->cost > *(s32 *)(gBattleState + 0x18)) {
                Ui_PlaySeCue(gFShopStrings + 0x3B0, 0x64);
                TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)self + 0x6C) + 0x38));
                owner = *(void **)((u8 *)self + 0x6C);
                saved = *(s32 *)((u8 *)owner + 0x84);
                msg = Ui_FindChild(self, -0x1000, 0);
                if (msg != NULL) {
                    Ui_SetWidgetText(msg, saved);
                }
                Process_Goto(self, 0x1C);
            } else {
                Ui_PlaySeCue(gFShopStrings + 0x37E, 0x64);
                panel40 = *(void **)((u8 *)self + 0x40);
                Ui_SlideWidgetChild(self, panel40, Pair(0x260, *(s16 *)((u8 *)panel40 + 0xC)), 0);
                panel44 = *(void **)((u8 *)self + 0x44);
                *(s16 *)((u8 *)panel44 + 0x24) = 8;
                Ui_SlideWidgetChild(self, panel44, Pair(0x260, *(s16 *)((u8 *)panel44 + 0xC)), 0);
                Process_ClearFunc(self);
            }
        } else if ((btn & 0x800) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            *(Pair *)&pos2 = ((Obj *)*(void **)((u8 *)self + 0x44))->v9();
            Ui_OpenUnitInfoPopup(gUnitInfoPopup, self, &gUnitRef, (f32)*(s16 *)&pos2, (f32)*((s16 *)&pos2 + 1));
            *(s32 *)gUnitInfoPopup = *(s32 *)gUnitInfoPopup | gUnitInfoPopupFlag;
        } else if ((btn & 0xA00) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            Ui_HideUnitInfoPopup(gUnitInfoPopup);
        } else if ((btn & 0x200) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            panel44 = *(void **)((u8 *)self + 0x44);
            *(s16 *)((u8 *)panel44 + 0x24) = 4;
            fn_801402C4(self, *(void **)((u8 *)self + 0x44), 0, 1);
            panel44 = *(void **)((u8 *)self + 0x44);
            if (panel44 != NULL) {
                s32 n = *(s32 *)((u8 *)panel44 + 4) - 1;
                *(s32 *)((u8 *)panel44 + 4) = n;
                if (n == 0 && panel44 != NULL) {
                    ((RefObj *)panel44)->destroy(1);
                }
                *(void **)((u8 *)self + 0x44) = NULL;
            }
            panel40 = *(void **)((u8 *)self + 0x40);
            *(f32 *)((u8 *)panel40 + 0x30) = lbl_8036B0A8;
            Ui_BringChildToFront(self, panel40);
            Process_Goto(self, 3);
            Ui_PlaySeCue(gFShopStrings + 0x3A0, 0x64);
        }
    }
}
#pragma cplusplus reset

void fn_801B2644(void *arg0) {
    void TalkUi_ShowMsg(s32);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *, s32);
    void *inner;
    s32 saved;
    void *ret;

    TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)arg0 + 0x6C) + 0xC));
    inner = *(void **)((u8 *)arg0 + 0x6C);
    saved = *(s32 *)((u8 *)inner + 0x6C);
    ret = Ui_FindChild(arg0, -0x1000, 0);
    if (ret != NULL) {
        Ui_SetWidgetText(ret, saved);
    }
}

/* Create the secondary list panel at self+0x44, positioned from the panel at +0x40, and slide it in. */
void Ui_CreateSideListPanel(void *self) {
    void *Heap_Alloc(s32);
    void *fn_801343F8(void *, s32, s32, s32, s32, s32, s32);
    void Ui_LayoutListPanel(void *);
    void Ui_AddChild(void *, void *);
    void fn_801402E4(void *, void *, s32, s32);
    void *panel;
    void *tmp;
    void *basePanel;
    s16 x;
    s16 y;

    basePanel = *(void **)((u8 *)self + 0x40);
    x = *(s16 *)((u8 *)basePanel + 0xA) - 0x20;
    y = *(s16 *)((u8 *)basePanel + 0xC) + 0x20;
    panel = Heap_Alloc(0x54);
    if (panel != NULL) {
        panel = fn_801343F8(panel, *(s16 *)((u8 *)basePanel + 0x3E), x, y, 0x108, 0xD0, 0x1F4);
    }
    *(void **)((u8 *)self + 0x44) = panel;
    tmp = *(void **)((u8 *)self + 0x44);
    if (tmp != NULL) {
        *(s32 *)((u8 *)tmp + 4) = *(s32 *)((u8 *)tmp + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x44) + 8) = 1;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x44) + 0x46) = 0x30;
    Ui_LayoutListPanel(*(void **)((u8 *)self + 0x44));
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x44) + 0x24) = 4;
    *(u8 *)((u8 *)*(void **)((u8 *)self + 0x44) + 0x3C) = 0;
    Ui_AddChild(self, *(void **)((u8 *)self + 0x44));
    fn_801402E4(self, *(void **)((u8 *)self + 0x44), 0, 1);
}

void fn_801B27A0(void *arg0) {
    extern f32 lbl_8036B0B8;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), f32 *, 0x30) = (f32) lbl_8036B0B8;
}

#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void fn_801B27B0(void *arg0) {
    void Process_Goto(void *, s32);
    void Process_ClearFunc(void *);
    void Ui_UpdatePanelWidgets(void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SlideWidgetChild(void *, void *, s16 *, s32);
    void Ui_PlaySeCue(void *, s32);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_ShowUnitInfoText(void *, s32, f32, f32);
    void Ui_HideUnitInfoPopup(void *);
    void Ui_OpenUnitInfoText(void *, void *, s32, f32, f32);
    extern u8 gFShopStrings[];
    extern u8 gUnitInfoPopup[];
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern s32 gUnitInfoPopupFlag;

    class Vec2s {
    public:
        s16 x;
        s16 y;
        Vec2s() {}
        Vec2s(const Vec2s &o) { *(u32 *)this = *(u32 *)&o; }
        Vec2s &operator=(const Vec2s &o) { *(u32 *)this = *(u32 *)&o; return *this; }
    };
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual s32 v8() = 0;
        virtual Vec2s v9() = 0;
    };

    void *obj;
    void *p;
    void *self;
    s16 saved;
    register int btn;
    register u8 gate;
    register int flags;
    u32 sp18;
    u32 sp14;
    u32 sp10;
    u32 spC;
    s16 sp8[2];
    s16 tmp;

    self = arg0;
    obj = *(void **)((u8 *)arg0 + 0x40);
    p = Ui_FindChild(arg0, 2, 0);
    saved = *(s16 *)((u8 *)obj + 0x3E);
    *(u8 *)((u8 *)obj + 0x3C) = 1;
    Ui_UpdatePanelWidgets(self);
    if (saved != *(s16 *)((u8 *)obj + 0x3E)) {
        if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            *(Vec2s *)&sp18 = ((Obj *)obj)->v9();
            Ui_ShowUnitInfoText(gUnitInfoPopup, ((Obj *)obj)->v8(), (f32)*(s16 *)&sp18, (f32)*((s16 *)&sp18 + 1));
        }
    }

    *(s32 *)((u8 *)p + 0x3C) = -1;
    flags = gUiInputFlags;
    gate = 0;
    if ((flags & 0x10) && !(flags & 0x20)) {
        gate = 1;
    }
    if (!gate) {
        btn = *(s32 *)((u8 *)gPadInput + 4);
        btn = btn & (*(s32 *)((u8 *)gPadInput + 8) ^ btn);
        if ((btn & 0x100) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            Ui_PlaySeCue(gFShopStrings + 0x37e, 0x64);
            Process_ClearFunc(self);
        } else if ((btn & 0x800) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            *(Vec2s *)&sp14 = ((Obj *)obj)->v9();
            Ui_OpenUnitInfoText(gUnitInfoPopup, self, ((Obj *)obj)->v8(), (f32)*(s16 *)&sp14, (f32)*((s16 *)&sp14 + 1));
            *(s32 *)gUnitInfoPopup = *(s32 *)gUnitInfoPopup | gUnitInfoPopupFlag;
        } else if ((btn & 0xa00) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            Ui_HideUnitInfoPopup(gUnitInfoPopup);
        } else if ((btn & 0x200) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            *(u8 *)((u8 *)obj + 0x3C) = 0;
            tmp = *(s16 *)((u8 *)p + 0xC);
            sp8[0] = 0x260;
            sp8[1] = tmp;
            Ui_SlideWidgetChild(self, p, sp8, 0);
            Process_Goto(self, 0x24);
            Ui_PlaySeCue(gFShopStrings + 0x3a0, 0x64);
        }
    }
    (void)sp10;
    (void)spC;
}
#pragma use_lmw_stmw reset
#pragma cplusplus reset

void fn_801B2A80(void *arg0) {
    void *Heap_Alloc(s32);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_AddChild(void *, void *);
    void Ui_BringChildToFront(void *, void *);
    void Ui_SetWidgetText(void *, s32);
    void Ui_SlideWidgetChildMode1(void *, void *, s16 *, s32);
    extern u8 lbl_8028FDB0[], lbl_80292230[], lbl_802961C4[];
#pragma cplusplus on
    s16 firstPos[2];
    s16 secondPos[2];
    u8 *obj;
    u8 *panel;
    s32 caption;
    void *child;
    panel = (u8 *)Ui_FindChild(arg0, 0, 0);
    if (!panel) {
        panel = *(u8 **)((u8 *)arg0 + 0x40);
        Ui_AddChild(arg0, panel);
    }
    if (*(s16 *)(panel + 0xA) != 0x138) {
        s16 y = *(s16 *)(panel + 0xC);
        firstPos[0] = 0x138;
        firstPos[1] = y;
        Ui_SlideWidgetChildMode1(arg0, panel, firstPos, 0);
    }
    obj = (u8 *)Heap_Alloc(0x44);
    if (obj) {
        *(u32 *)obj = (u32)lbl_8028FDB0;
        *(s32 *)(obj + 4) = 0;
        *(u32 *)obj = (u32)lbl_80292230;
        *(s16 *)(obj + 8) = -1;
        *(s16 *)(obj + 0xA) = 0x260;
        *(s16 *)(obj + 0xC) = 0x148;
        *(s16 *)(obj + 0xE) = 0x349;
        *(s16 *)(obj + 0x10) = 0x18F;
        *(s16 *)(obj + 0x12) = 0;
        *(s16 *)(obj + 0x14) = 0;
        *(s16 *)(obj + 0x16) = 0xE9;
        *(s16 *)(obj + 0x18) = 0x47;
        *(s16 *)(obj + 0x1A) = 0;
        *(s16 *)(obj + 0x1C) = 0;
        obj[0x1E] = 0xFF;
        obj[0x1F] = 0xFF;
        obj[0x20] = 0xFF;
        obj[0x21] = 0xFF;
        *(s16 *)(obj + 0x22) = 0x226;
        *(s16 *)(obj + 0x24) = 0;
        *(f32 *)(obj + 0x28) = 0.0f;
        *(f32 *)(obj + 0x2C) = 0.0f;
        *(f32 *)(obj + 0x30) = 0.0f;
        *(s32 *)(obj + 0x34) = 0;
        *(s32 *)(obj + 0x38) = 0;
        *(u32 *)obj = (u32)lbl_802961C4;
        *(s32 *)(obj + 0x3C) = -1;
        ((SetupMenuObj *)obj)->v8();
    }
    *(s16 *)(obj + 8) = 2;
    *(s16 *)(obj + 0x24) = 8;
    Ui_AddChild(arg0, obj);
    {
        s16 y = *(s16 *)(obj + 0xC);
        secondPos[0] = 0x158;
        secondPos[1] = y;
        Ui_SlideWidgetChildMode1(arg0, obj, secondPos, 0);
    }
    Ui_BringChildToFront(arg0, panel);
    caption = *(s32 *)(*(u8 **)((u8 *)arg0 + 0x6C) + 0x6C);
    child = Ui_FindChild(arg0, -0x1000, 0);
    if (child) Ui_SetWidgetText(child, caption);
#pragma cplusplus reset
}

void fn_801B2C58(void *arg0) {
    M2C_UNK Process_Goto(void *, M2C_UNK);
    M2C_UNK Allegiance_SetMask(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, void *);
    u8 fn_80092F9C();
    s32 Convoy_FindEmpty(void *);
    M2C_UNK TalkUi_ShowMsg(s32);
    u32 Ui_FindChild(void *, M2C_UNK, M2C_UNK, void *);
    M2C_UNK Ui_SetWidgetText(s32);
    extern u8 gUnits[101760];
    extern u8 gConvoy[1600];
    u8 sp10[16];
    int var_r29;
    u8 var_r30;
    void *var_r3;
    void *temp_r6;
    s32 temp_r30;
    void *self = arg0;

    var_r30 = 0;
    Allegiance_SetMask(1, 0, 0, 0, 0, 1, 0, 0, sp10);
    var_r29 = 1;
    for (;;) {
        if (var_r29 & 0xFF) {
            var_r3 = gUnits + ((var_r29 - 1) * 0x280);
        } else {
            var_r3 = 0;
        }
        if (*(u32 *)((u8 *)var_r3 + 0x188) != 0 &&
            sp10[*(u8 *)(((u8 *)*(void **)((u8 *)var_r3 + 0x190)) + 0x8)] != 0 &&
            fn_80092F9C() < 4) {
            var_r30 = 1;
            break;
        }
        var_r29++;
        if (var_r29 > 0x9F) {
            break;
        }
    }
    if (var_r30 == 0 && Convoy_FindEmpty(gConvoy) >= 0) {
        var_r30 = 1;
    }
    if (var_r30 != 0) {
        TalkUi_ShowMsg(*(s32 *)((u8 *)*(void **)((u8 *)self + 0x6C) + 0x8));
        return;
    }
    TalkUi_ShowMsg(*(s32 *)((u8 *)*(void **)((u8 *)self + 0x6C) + 0x5C));
    temp_r6 = *(void **)((u8 *)self + 0x6C);
    temp_r30 = *(s32 *)((u8 *)temp_r6 + 0x84);
    if (Ui_FindChild(self, -0x1000, 0, temp_r6) != 0) {
        Ui_SetWidgetText(temp_r30);
    }
    Process_Goto(self, 0x20);
}

void fn_801B2DA8(void *arg0) {
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
        TalkUi_ShowMsg(*(s32 *)(*(u8 **)((u8 *)arg0 + 0x6C) + 0x58));
        temp_r6 = *(void **)((u8 *)arg0 + 0x6C);
        temp_r31 = *(s32 *)((u8 *)temp_r6 + 0x88);
        result = Ui_FindChild(arg0, -0x1000, 0);
        if (result != 0U) {
            Ui_SetWidgetText(result, temp_r31);
        }
        Process_Goto(arg0, 0x25);
        break;
    case 0x81:
        break;
    }
}

void fn_801B2E3C(void *arg0) {
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
    temp_r6 = *(void **)((u8 *)arg0 + 0x6C);
    temp_r31 = *(s32 *)((u8 *)temp_r6 + 0x8C);
    res = Ui_FindChild(arg0, -0x1000, 0, temp_r6);
    if (res != 0U) {
        Ui_SetWidgetText(res, temp_r31);
    }
}

/* Create the main list panel at self+0x40, attach it, and set its caption text. */
void Ui_CreateMainListPanel(void *self) {
    void *Heap_Alloc(s32);
    void *Ui_MainListPanel_Ctor(void *, s32, s32, s32, s32, s32);
    void Ui_LayoutListPanel(void *);
    void Ui_AddChild(void *, void *);
    void fn_8011D908(s32, void *);
    u32 Ui_FindChild(void *, s32, s32, void *);
    void Ui_SetWidgetText(u32, s32);
    void *panel;
    void *tmp;
    void *data;
    s32 caption;
    u32 child;

    panel = Heap_Alloc(0x4C);
    if (panel != NULL) {
        panel = Ui_MainListPanel_Ctor(panel, 0x138, 0x6C, 0x108, 0xD0, 0x226);
    }
    *(void **)((u8 *)self + 0x40) = panel;
    tmp = *(void **)((u8 *)self + 0x40);
    if (tmp != NULL) {
        *(s32 *)((u8 *)tmp + 4) = *(s32 *)((u8 *)tmp + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x40) + 8) = 0;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x40) + 0x46) = 0x38;
    Ui_LayoutListPanel(*(void **)((u8 *)self + 0x40));
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x40) + 0x24) = 8;
    *(u8 *)((u8 *)*(void **)((u8 *)self + 0x40) + 0x3C) = 0;
    Ui_AddChild(self, *(void **)((u8 *)self + 0x40));
    fn_8011D908(*(s32 *)((u8 *)*(void **)((u8 *)self + 0x6C) + 4), self);
    data = *(void **)((u8 *)self + 0x6C);
    caption = *(s32 *)((u8 *)data + 0x80);
    child = Ui_FindChild(self, -0x1000, 0, data);
    if (child != 0) {
        Ui_SetWidgetText(child, caption);
    }
}

void fn_801B2FA8(void *arg0) {
    void *Heap_Alloc(s32);
    s32 strlen(void *);
    void String_AssignCStr(void *, void *, s32);
    void Ui_AddChild(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *, s32);
    extern u8 lbl_8028FDB0[], lbl_80292230[], lbl_80293C84[], lbl_80293C58[];
    extern u8 gFShopStrings[];
#pragma cplusplus on
    u8 *obj;
    s32 caption;
    void *child;
    obj = (u8 *)Heap_Alloc(0x5C);
    if (obj) {
        *(void * *)(obj + 0x0) = lbl_8028FDB0;
        *(s32 *)(obj + 0x4) = 0;
        *(void * *)(obj + 0x0) = lbl_80292230;
        *(s16 *)(obj + 0x8) = -1;
        *(s16 *)(obj + 0xa) = 0;
        *(s16 *)(obj + 0xc) = 0x190;
        *(s16 *)(obj + 0xe) = 0x260;
        *(s16 *)(obj + 0x10) = 0x1C0;
        *(s16 *)(obj + 0x12) = 0;
        *(s16 *)(obj + 0x14) = 0;
        *(s16 *)(obj + 0x16) = 0x260;
        *(s16 *)(obj + 0x18) = 0x30;
        *(s16 *)(obj + 0x1a) = 0;
        *(s16 *)(obj + 0x1c) = 0;
        *(u8 *)(obj + 0x1e) = 255;
        *(u8 *)(obj + 0x1f) = 255;
        *(u8 *)(obj + 0x20) = 255;
        *(u8 *)(obj + 0x21) = 255;
        *(s16 *)(obj + 0x22) = 0x5A;
        *(s16 *)(obj + 0x24) = 0;
        *(f32 *)(obj + 0x28) = 0.0f;
        *(f32 *)(obj + 0x2c) = 0.0f;
        *(f32 *)(obj + 0x30) = 0.0f;
        *(s32 *)(obj + 0x34) = 0;
        *(s32 *)(obj + 0x38) = 0;
        *(void * *)(obj + 0x0) = lbl_80293C84;
        *(s32 *)(obj + 0x3c) = 0;
        *(s32 *)(obj + 0x40) = 0;
        *(s32 *)(obj + 0x44) = 0;
        *(s32 *)(obj + 0x40) = 0;
        *(s32 *)(obj + 0x48) = 0;
        *(u8 *)(obj + 0x4c) = 1;
        *(s16 *)(obj + 0x4e) = 0;
        *(s16 *)(obj + 0x50) = 0;
        *(s16 *)(obj + 0x52) = 0;
        *(s16 *)(obj + 0x54) = 0;
        *(void * *)(obj + 0x0) = lbl_80293C58;
        *(s32 *)(obj + 0x58) = 1;
        *(s16 *)(obj + 0x4e) = 0x30;
        *(s16 *)(obj + 0x52) = 0x30;
    }
    *(s16 *)(obj + 8) = -0x1000;
    *(s32 *)(obj + 0x48) = 1;
    String_AssignCStr(obj + 0x3C, gFShopStrings + 0x3BE, strlen(gFShopStrings + 0x3BE));
    *(u32 *)(obj + 0x34) |= 0x10;
    *(s32 *)(obj + 0x58) = 1;
    Ui_AddChild(arg0, obj);
    caption = *(s32 *)(*(u8 **)((u8 *)arg0 + 0x6C) + 0x80);
    child = Ui_FindChild(arg0, -0x1000, 0);
    if (child) Ui_SetWidgetText(child, caption);
#pragma cplusplus reset
}

void *Ui_ConfirmChild_Ctor(void *arg0) {
    extern u8 lbl_80291758[];
    void fn_80134E48(void *);
    void Item_Init(void *);
    s16 w;
    s16 h;
    s16 w8;

    fn_80134E48(arg0);
    *(void **)arg0 = lbl_80291758;
    *(u32 *)((u8 *)arg0 + 0x4C) = 0;
    ((u8 *)arg0)[0x50] = 1;
    Item_Init((u8 *)arg0 + 0x60);

    w = (s16)(*(s16 *)((u8 *)arg0 + 0x10) - *(s16 *)((u8 *)arg0 + 0x0C));
    h = (s16)(*(s16 *)((u8 *)arg0 + 0x0E) - *(s16 *)((u8 *)arg0 + 0x0A));
    *(s16 *)((u8 *)arg0 + 0x12) = 2;
    w8 = (s16)(w - 8);
    *(s16 *)((u8 *)arg0 + 0x14) = 8;
    *(s16 *)((u8 *)arg0 + 0x16) = (s16)(h - 2);
    *(s16 *)((u8 *)arg0 + 0x18) = w8;
    return arg0;
}

void *Ui_MainListPanel_Ctor(void *arg0) {
    void fn_80134E48(void *);

    fn_80134E48(arg0);
    *(void **)arg0 = gUiMainListPanelVtbl;
    return arg0;
}
extern s32 gUiInputFlags;
extern s32 *gPadInput;
extern u8 gFShopStrings[];
#include "global.h"
#include "unit.h"

extern struct SomeStruct gUiContext;
