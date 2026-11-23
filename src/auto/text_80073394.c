/* Functions from 0x80073394 to 0x80073E70, found by decomp-toolkit. */
#include "common.h"
extern void Game_SetState(s32);
extern void BMapMain_Goto(s32);
extern void* (*fn_80024398_ptr)(void*, s32, s32);
extern void GfxEnt_UnlinkByName(void *);
s32 Msg_Expand(void *);

void *fn_80073394(void) {
    extern u16 gSaveUiStrs[];
    return (u8 *)gSaveUiStrs + 0x1a7;
}

s32 fn_800733A4(void) {
    extern u16 gSaveUiStrs[];
    Game_SetState(3);
    BMapMain_Goto(6);
    GfxEnt_UnlinkByName((u8 *)gSaveUiStrs + 0x101);
    return 5;
}

void *fn_800733E4(void) {
    extern u16 gSaveUiStrs[];
    return (u8 *)gSaveUiStrs + 0x1d6;
}

s32 fn_800733F4(void) {
    return 1;
}

void *fn_800733FC(void) {
    extern u16 gSaveUiStrs[];
    return (u8 *)gSaveUiStrs + 0x1E0;
}

s32 fn_8007340C(s32 arg0, s32 arg1) {
    void *fn_800241C8(s32);
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    M2C_UNK fn_8018DC18(void *);
    extern u8 gUiContext[];
    extern M2C_UNK lbl_80367390;
    s32 temp_r31;

    temp_r31 = M2C_FIELD(fn_800241C8(arg1), s32 *, 0x18);
    gUiContext[8] = 0;
    fn_8018DC18(gUiContext);
    Ui_CreateMenu(&lbl_80367390, temp_r31, 0);
    return 5;
}

void *fn_80073464(void) {
    extern u8 gSaveUiStrs[];
    return gSaveUiStrs + 0x203;
}

s32 fn_80073474(s32 unused, s32 arg1) {
    void *fn_800241C8(s32);
    void Process_CreateChild(void *, s32);
    extern u8 lbl_80286EF0[];
    void *p;
    void *lbl;

    p = fn_800241C8(arg1);
    lbl = lbl_80286EF0;
    Process_CreateChild(lbl, *(s32 *)((u8 *)p + 0x18));
    return 5;
}

u8 fn_800734B0(void) { u8 fn_801E3620(void*); extern u8 gSystemSave[]; s32 result; u8 ready=fn_801E3620(gSystemSave); result=2; if(ready!=0) result=0; return (u8)result; }

void fn_800734EC(void) {
    M2C_UNK Msg_Expand(void *);
    extern u8 gSaveUiStrs[];
    Msg_Expand(gSaveUiStrs + 0x20C);
}

void fn_80073518(void) {
    M2C_UNK Msg_Expand(void *);
    extern u8 gSaveUiStrs[];
    Msg_Expand(gSaveUiStrs + 0x215);
}

s32 fn_80073544(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x35;
    return 5;
}

void fn_8007355C(void) {
    s32 Msg_Expand(void *);
    extern u8 gSaveUiStrs[];
    Msg_Expand(gSaveUiStrs + 0x21E);
}

void fn_80073588(void) {
    extern u16 gSaveUiStrs[];
    Msg_Expand((u8 *)gSaveUiStrs + 0x226);
}

s32 fn_800735B4(s32 arg0, s32 arg1) {
    void *fn_800241C8(s32);
    M2C_UNK fn_801AA120(s32);
    fn_801AA120(M2C_FIELD(fn_800241C8(arg1), s32 *, 0x18));
    return 5;
}

void fn_800735E4(void) {
    extern u16 gSaveUiStrs[];
    Msg_Expand((u8 *)gSaveUiStrs + 0x22f);
}

void fn_80073610(void) {
    M2C_UNK Msg_Expand(void *);
    extern u8 gSaveUiStrs[];
    Msg_Expand(gSaveUiStrs + 0x238);
}

#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void Process_CreateChild(void *);
extern "C" void fn_80166AE8(s32, s32, s32, void *);
extern "C" s32 fn_8007363C(s32 arg0, void *arg1, void *arg2) {
    struct Obj {
        u8 pad[4];
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
        virtual void v18() = 0;
        virtual void v19() = 0;
        virtual void v20() = 0;
        virtual s16 v21() = 0;
        virtual s16 v22() = 0;
    };
    extern u8 gSaveUiStrs[];
    extern u8 lbl_80286ED8[];
    Obj *obj;
    s32 a;
    s32 str;
    s32 b;
    s16 x;
    s16 y;

    if (M2C_FIELD(arg2, u8 *, 0x39) != 0) {
        str = Msg_Expand(gSaveUiStrs + 0x242);
        obj = M2C_FIELD(arg1, Obj **, 0x3C);
        x = M2C_FIELD(arg2, s16 *, 0x30);
        a = obj->v22();
        y = M2C_FIELD(arg2, s16 *, 0x32);
        b = obj->v21();
        fn_80166AE8(b + x, a + y, str, arg1);
        return 0;
    }
    Process_CreateChild(lbl_80286ED8);
    return 4;
}
#pragma use_lmw_stmw reset
#pragma cplusplus reset
u8 fn_800736F0(void) {
    u8 fn_801E3620(M2C_UNK *);
    extern u8 gSystemSave[];
    extern s32 gUiInputFlags;
    u8 res;
    s32 ret;

    if (gUiInputFlags & 0x10) {
        return 0;
    }
    res = fn_801E3620((M2C_UNK *)gSystemSave);
    ret = 2;
    if (res != 0) {
        ret = 0;
    }
    return ret;
}

void fn_80073740(void) {
    extern u16 gSaveUiStrs[];
    Msg_Expand((u8 *)gSaveUiStrs + 0x24c);
}

void fn_8007376C(void) {
    extern u16 gSaveUiStrs[];
    Msg_Expand(&gSaveUiStrs[0x254 / sizeof(u16)]);
}

s32 fn_80073798(s32 arg0, s32 arg1, void *arg2) {
    void *fn_800241C8(s32);
    void fn_801E9C70(s32);

    if (*(u8 *)((u8 *)arg2 + 0x39) != 0) {
        return 0x10;
    }
    fn_801E9C70(*(s32 *)((u8 *)fn_800241C8(arg1) + 0x18));
    return 5;
}

void fn_800737DC(void) {
    extern u16 gSaveUiStrs[];
    Msg_Expand((u8 *)gSaveUiStrs + 0x25D);
}

void fn_80073808(void) {
    extern u16 gSaveUiStrs[];
    Msg_Expand((u8 *)gSaveUiStrs + 0x267);
}

s32 fn_80073834(s32 arg0, s32 arg1)
{
    void *fn_800241C8(s32);
    void fn_8012C9FC(s32, s32);
    void *ptr;

    ptr = fn_800241C8(arg1);
    fn_8012C9FC(0, *(s32 *)((u8 *)ptr + 0x18));
    return 5;
}

void Unit_OfferItem(void *unit, s32 itemArg, void *parent) {
    void *Unit_GetItemSlot(void *, s32);
    u8 fn_80094ABC(void *, void *);
    void fn_80091788(void *, void *, void *);
    void fn_800916B8(void *, void *, void *);
    void Item_Copy(void *, void *);
    void Process_CreateChild(void *, void *);
    extern void *lbl_80367468;
    extern u64 lbl_8036746C;
    extern u8 lbl_80287378[];

    void *item;
    s32 clear;
    u8 flags;
    s32 i;
    void *slot;
    void *info;
    u8 kind;
    s32 one;

    item = (void *)itemArg;
    clear = 0;
    flags = *((u8 *)item + 5);
    flags = __rlwimi(flags, clear, 7, 24, 24);
    *((u8 *)item + 5) = flags;
    flags = __rlwimi(flags, clear, 6, 25, 25);
    *((u8 *)item + 5) = flags;

    info = *(void **)((u8 *)unit + 0x190);
    if (*((u8 *)info + 8) == 1) {
        i = 0;
        while (1) {
            slot = Unit_GetItemSlot(unit, i);
            if (*(u32 *)slot == 0) {
                break;
            }
            if (((*((u8 *)slot + 5) >> 6) & 1) != 0) {
                goto after_flag;
            }
            i += 1;
            if (i >= 8) {
                break;
            }
        }
        one = 1;
        flags = *((u8 *)item + 5);
        flags = __rlwimi(flags, one, 6, 25, 25);
        *((u8 *)item + 5) = flags;
    }
after_flag:
    if (fn_80094ABC(unit, item) != 0) {
        info = *(void **)((u8 *)unit + 0x190);
        if (*((u8 *)info + 8) != 1) {
            fn_80091788(item, parent, unit);
        } else {
            fn_800916B8(item, parent, unit);
        }
    } else {
        info = *(void **)((u8 *)unit + 0x190);
        kind = *((u8 *)info + 8);
        if (kind == 0 || kind == 5) {
            lbl_80367468 = unit;
            Item_Copy(&lbl_8036746C, item);
            Process_CreateChild(lbl_80287378, parent);
        }
    }
}

void fn_800739A8(void) {
    M2C_UNK Unit_ApplyTransform(void *);
    u8 fn_80091D74();
    extern void *lbl_80367468;
    if ((M2C_FIELD(lbl_80367468, s32 *, 0x1A0) & 0x800000) && (fn_80091D74() == 0)) {
        Unit_ApplyTransform(lbl_80367468);
    }
}

void fn_800739E8(void *arg0)
{
    extern void *lbl_80367468;

    u8 fn_80091D74(void *);
    void fn_80183BE4(void *, void *);

    void *ptr;

    ptr = lbl_80367468;

    if ((*(u32 *)((u8 *)ptr + 0x1A0) & 0x00800000) != 0) {
        if (fn_80091D74(ptr) == 0) {
            fn_80183BE4(lbl_80367468, arg0);
        }
    }
}

void fn_80073A3C(void) {
    M2C_UNK Item_Clear(M2C_UNK *);
    extern M2C_UNK lbl_8036746C;
    Item_Clear(&lbl_8036746C);
}

void fn_80073A60(void) {
 extern u8 gUiContext[],gBattleState[],gConvoy[],lbl_8036746C[8];
 extern void *lbl_80367468;
 u8 fn_8014D8DC(void *); void Convoy_AddItem(void *,void *);
 void *Item_GetFlagsPtr(void *); void *Unit_GetItemSlot(void *,s32);
 void Item_Clear(void *); void Unit_CompactItems(void *);
 s8 Unit_GetActiveItemSlot(void *); void fn_800951D0(void *,s32); void fn_80094ABC(void *,void *);
 s32 index; void *item; s32 offset;
 index=((s8*)gUiContext)[10];
 if(index==4) {
 if(fn_8014D8DC(gBattleState)) Convoy_AddItem(gConvoy,lbl_8036746C);
 } else {
 if(index==4) item=lbl_8036746C;
 else { void *flags=Item_GetFlagsPtr(lbl_8036746C);
 offset=((*(u64 *)flags&5)!=0)?0:4; item=Unit_GetItemSlot(lbl_80367468,offset+index); }
 if(fn_8014D8DC(gBattleState)) Convoy_AddItem(gConvoy,item);
 Item_Clear(item);Unit_CompactItems(lbl_80367468);
 if(Unit_GetActiveItemSlot(lbl_80367468)<0) fn_800951D0(lbl_80367468,-1);
 fn_80094ABC(lbl_80367468,lbl_8036746C);
 }
}

void fn_80073B74(s32 arg0)
{
    extern u32 lbl_80367468;
    extern u8 lbl_80312000[];

    fn_80091CD8(lbl_80367468);
    Ui_CreateMenu(lbl_80312000, arg0, 0);
}

void fn_80073BB8(void *arg0) {
    extern void *lbl_8036746C;
    extern void *lbl_80367468;
    extern void fn_80091788(void *, void *, void *);

    fn_80091788(
        (void *)&lbl_8036746C,
        arg0,
        lbl_80367468
    );
}

extern u8 lbl_80311FD8[];
extern s32 lbl_80367468;
extern s32 lbl_8036746C;
extern s32 lbl_80312000;
extern u8 gUiContext[24];
void fn_80073BE4(s32 arg0) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);

    Ui_CreateMenu((M2C_UNK *)lbl_80311FD8, arg0, 0);
}

void fn_80073C14(s32 arg0) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    extern u8 lbl_80311FC8[];

    Ui_CreateMenu((M2C_UNK *)lbl_80311FC8, arg0, 0);
}

void fn_80073C44(s32 arg0) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    extern u8 lbl_80311FBC[];

    Ui_CreateMenu((M2C_UNK *)lbl_80311FBC, arg0, 0);
}

void fn_80073C74(s32 arg0) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    extern u8 lbl_80311F70[];

    Ui_CreateMenu((M2C_UNK *)lbl_80311F70, arg0, 0);
}

void fn_80073CA4(void) {
    void Unit_ApplyTransform(void *);
    void Unit_GetMov(void *);
    void fn_800F0A3C(void);
    extern u8 gUiContext[24];
    Unit_ApplyTransform(*(void **)gUiContext);
    Unit_GetMov(*(void **)gUiContext);
    fn_800F0A3C();
}

void fn_80073CE4(s32 arg0) {
    void Process_Unlink(s32);
    void fn_8003C15C(void *);
    u8 Status_Test(void *, s32);
    u8 fn_80091D74(void *);
    void fn_80183BE4(void *, s32);
    extern u8 gUiContext[24];
    u8 flags;
    flags = 0;
    if (Status_Test((u8 *)*(void **)gUiContext + 0x1BC, 9) != 0) flags |= 1;
    if (fn_80091D74(*(void **)gUiContext) != 0) flags |= 2;
    switch ((s32)flags) {
    case 3:
        fn_8003C15C(*(void **)gUiContext);
        Process_Unlink(arg0);
        break;
    case 0:
    case 1:
    case 2:
    default:
        fn_80183BE4(*(void **)gUiContext, arg0);
        break;
    }
}

void fn_80073DA4(s32 arg0) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    extern u8 lbl_80311F60[];

    Ui_CreateMenu((M2C_UNK *)lbl_80311F60, arg0, 0);
}

void fn_80073DD4(s32 arg0) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    extern u8 lbl_80311F50[];

    Ui_CreateMenu((M2C_UNK *)lbl_80311F50, arg0, 0);
}

void fn_80073E04(s32 arg0) {
    M2C_UNK Ui_CreateMenu(M2C_UNK *, s32, M2C_UNK);
    extern u8 lbl_80311F40[];

    Ui_CreateMenu((M2C_UNK *)lbl_80311F40, arg0, 0);
}

void fn_80073E34(s32 arg0) {
    void Ui_CreateMenu(void *, s32, s32);
    extern u8 lbl_80367414;
    u8 *p;

    p = gUiContext;
    p[8] = 0;
    Ui_CreateMenu(&lbl_80367414, arg0, 0);
}

