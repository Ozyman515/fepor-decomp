/* Functions from 0x80006264 to 0x80011968, found by decomp-toolkit. */
#include "common.h"
#pragma cplusplus on
struct TextWidthFontInterface {
    virtual s32 v0() = 0;
    virtual s32 v1() = 0;
    virtual s32 v2() = 0;
    virtual s32 v3() = 0;
    virtual s32 v4() = 0;
    virtual s32 v5() = 0;
    virtual s32 v6() = 0;
    virtual s32 v7() = 0;
    virtual s32 v8() = 0;
    virtual s32 v9() = 0;
    virtual s32 v10() = 0;
    virtual s32 v11() = 0;
    virtual s32 v12() = 0;
    virtual s32 v13() = 0;
};
#pragma cplusplus reset

typedef struct {
    void *unk0;
    void *unk4;
    s32 unk8;
} Struct_8000B090;

extern s32 lbl_802AEE20[5]; // array of 5 pointers
static inline s32 Text_FindFontIndex(u32 *p, u32 result) {
    s32 i;
    for(i=0;i<5;i++,p++) {
        if(*p==result) return i;
    }
    return -1;
}
extern f64 lbl_80368C28;    // global float constant
extern u16 jumptable_80283AE8[];

extern f64 lbl_80368C28;

extern u16 gPrim2D;

extern void *(*lbl_80366DA0)(s32);
extern f32 gFloat1, lbl_80368BB8, lbl_80368B98;
extern u32 gProcessOpcodeTables[9];

extern void *fn_8000A738(void *, s32);
extern void fn_8000B5F0(void *);
extern void fn_8000B70C(void *);

typedef struct HashKey {
    u32 h1;
    u32 h2;
} HashKey;

extern struct UnkStruct_802AEE80 gUnk_802AEE80;

extern s32 gUnknown_0x80369C84;
extern s32 gUnknown_0x80369C88;

#pragma push
#pragma use_lmw_stmw on
#pragma peephole on

#pragma pop

int fn_8000E7FC(int a0, int a1, int a2, int a3, int a4, int a5, float f0, float f1, float f2, float f3, float f4);

#pragma push
#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma pop

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer reset

#pragma global_optimizer off

#pragma global_optimizer reset

extern f32 lbl_80368BDC;
extern f32 lbl_80368BE0;
extern f64 lbl_80368C20;

#pragma push
#pragma cplusplus on

#pragma pop

void fn_80010FF0(void) {
    M2C_UNK fn_801047D0();
    fn_801047D0();
}

#pragma global_optimizer off
s32 fn_80011010(s32 arg0) {
    u32 result;
    s32 fn_8010494C(s32);

    if (arg0 == -1) {
        arg0 = 0;
    }
    result = (u32)fn_8010494C(lbl_802AEE20[arg0]);
    return Text_FindFontIndex((u32 *)lbl_802AEE20, result);
}
#pragma global_optimizer on
void fn_800110B8(void) {
 extern char lbl_80267DC8[];
 extern u32 lbl_80367160[2];
 extern void *lbl_80367168;
 s32 Heap_Alloc(u32);
 s32 fn_801053CC(s32);
 void fn_80105284(s32, const char *, s32);
 struct Object { struct VTable { s32 (*method[9])(); } *vtable; u32 value; } *self;
 s32 object;
 object = Heap_Alloc(0x10);
 if (object) object = fn_801053CC(object);
 lbl_802AEE20[1] = object;
 fn_80105284(object,lbl_80267DC8,0);
 object = Heap_Alloc(0x10);
 if (object) object = fn_801053CC(object);
 lbl_802AEE20[2] = object;
 fn_80105284(object,lbl_80267DC8+0x12,0);
 object = Heap_Alloc(0x10);
 if (object) object = fn_801053CC(object);
 lbl_802AEE20[3] = object;
 fn_80105284(object,lbl_80267DC8+0x21,0);
 object = Heap_Alloc(0x10);
 if (object) object = fn_801053CC(object);
 lbl_802AEE20[4] = object;
 fn_80105284(object,lbl_80267DC8+0x33,0);
 self = (struct Object *)lbl_80367160;
 lbl_80367168 = self;
 if (!self->value) fn_8006EEFC(&self->value,self->vtable->method[8](self));
}

void fn_800111FC(void) {
    extern s32 lbl_802AEE20[5];
    extern s32 lbl_8036716C;
    extern s8 lbl_80367170;
    s32 ret;

    if (lbl_80367170 == 0) {
        lbl_8036716C = 0;
        lbl_80367170 = 1;
    }
    if (lbl_8036716C == 0) {
        fn_80104D90(0);
        fn_8010494C(0);
        ret = fn_80104944();
        lbl_8036716C = 1;
        lbl_802AEE20[0] = ret;
    }
}

#pragma cplusplus on
extern "C" s32 fn_80011264(void **arg0) {
    struct Obj {
        virtual s32 v0() = 0;
        virtual s32 v1() = 0;
        virtual s32 v2() = 0;
        virtual s32 v3() = 0;
        virtual s32 v4() = 0;
        virtual s32 v5() = 0;
        virtual s32 v6() = 0;
        virtual s32 v7() = 0;
        virtual s32 v8() = 0;
        virtual s32 v9() = 0;
        virtual s32 v10() = 0;
        virtual s32 v11() = 0;
        virtual s32 v12() = 0;
        virtual s32 v13() = 0;
        virtual s32 v14() = 0;
        virtual s32 v15() = 0;
    };
    return ((Obj *)arg0)->v10() / ((Obj *)arg0)->v14();
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" s32 fn_800112C0(void **arg0) {
    struct Obj {
        virtual s32 v0() = 0;
        virtual s32 v1() = 0;
        virtual s32 v2() = 0;
        virtual s32 v3() = 0;
        virtual s32 v4() = 0;
        virtual s32 v5() = 0;
        virtual s32 v6() = 0;
        virtual s32 v7() = 0;
        virtual s32 v8() = 0;
        virtual s32 v9() = 0;
        virtual s32 v10() = 0;
        virtual s32 v11() = 0;
        virtual s32 v12() = 0;
        virtual s32 v13() = 0;
        virtual s32 v14() = 0;
        virtual s32 v15() = 0;
    };
    return ((Obj *)arg0)->v9() / ((Obj *)arg0)->v13();
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" u16 fn_8001131C(void *arg0) {
    struct Obj {
        virtual s32 v0() = 0;
        virtual s32 v1() = 0;
        virtual s32 v2() = 0;
        virtual s32 v3() = 0;
        virtual s32 v4() = 0;
        virtual s32 v5() = 0;
        virtual s32 v6() = 0;
        virtual s32 v7() = 0;
        s32 unk04;
    };
    u16 **fn_8006EDD8(s32, s32);
    Obj *obj = (Obj *)arg0;
    return **fn_8006EDD8(obj->unk04, obj->v7());
}
extern "C" u16 fn_80011368(void *arg0) {
    struct Obj {
        virtual s32 v0() = 0;
        virtual s32 v1() = 0;
        virtual s32 v2() = 0;
        virtual s32 v3() = 0;
        virtual s32 v4() = 0;
        virtual s32 v5() = 0;
        virtual s32 v6() = 0;
        virtual s32 v7() = 0;
        s32 unk04;
    };
    void **fn_8006EDD8(s32, s32);
    Obj *obj = (Obj *)arg0;
    return *(u16 *)((u8 *)*fn_8006EDD8(obj->unk04, obj->v7()) + 2);
}
#pragma cplusplus reset
s32 fn_800113B4(void) {
    return 0;
}

s32 fn_800113BC(void) {
    return 0;
}

#pragma cplusplus on
extern "C" void fn_800113C4(void *obj, s32 arg1, u8 *color, f32 x, f32 y, f32 z) {
    f64 fmod(f64, f64);
    void GXBegin(s32, s32, s32);
    extern f64 lbl_80368C38;
    extern f64 lbl_80368C40;
    extern f32 lbl_80368BF0;
    extern f64 lbl_80368C28;
    struct Obj {
        virtual s32 v0() = 0;
        virtual s32 v1() = 0;
        virtual s32 v2() = 0;
        virtual s32 v3() = 0;
        virtual s32 v4() = 0;
        virtual s32 v5() = 0;
        virtual s32 v6() = 0;
        virtual s32 v7() = 0;
        virtual s32 v8() = 0;
        virtual s32 v9() = 0;
        virtual s32 v10() = 0;
        virtual s32 v11() = 0;
        virtual s32 v12() = 0;
        virtual s32 v13() = 0;
        virtual s32 v14() = 0;
        virtual s32 v15() = 0;
    };
    f32 f30;
    f32 f29;
    f32 f28;
    f32 f27;
    f32 f26;
    f32 f25;
    s32 t;
    s32 idx;
    s32 w;
    s32 rem;
    u8 r, g, b, a;
    f32 f0, f1, f2, f3;
    u8 *wg;

    idx = arg1;
    if (idx < 0) {
        return;
    }
    {
        f32 f = (f32)fmod(lbl_80368C38, lbl_80368C40);
        f30 = (f32)(s32)(f * (x + (lbl_80368BF0 / f))) / f;
    }
    {
        f32 f = (f32)fmod(lbl_80368C38, lbl_80368C40);
        f29 = (f32)(s32)(f * (y + (lbl_80368BF0 / f))) / f;
    }
    t = ((Obj *)obj)->v13();
    w = ((Obj *)obj)->v11();
    rem = idx % w;
    f28 = (f32)(rem * t);
    t = ((Obj *)obj)->v14();
    w = ((Obj *)obj)->v11();
    rem = idx / w;
    f27 = (f32)(rem * t);
    f26 = (f32)((Obj *)obj)->v13();
    f25 = (f32)((Obj *)obj)->v14();
    GXBegin(0x80, 0, 4);
    wg = (u8 *)0xCC010000;
    r = color[wg - (u8 *)0xCC010000];
    *(volatile f32 *)(wg - 0x8000) = f30;
    f0 = f30 + f26;
    g = color[1];
    f1 = f28 + f26;
    *(volatile f32 *)(wg - 0x8000) = f29;
    f2 = f29 + f25;
    b = color[2];
    *(volatile f32 *)(wg - 0x8000) = z;
    f3 = f27 + f25;
    a = color[3];
    *(wg - 0x8000) = r;
    *(wg - 0x8000) = g;
    *(wg - 0x8000) = b;
    *(wg - 0x8000) = a;
    *(volatile f32 *)(wg - 0x8000) = f28;
    *(volatile f32 *)(wg - 0x8000) = f27;
    *(volatile f32 *)(wg - 0x8000) = f0;
    *(volatile f32 *)(wg - 0x8000) = f29;
    *(volatile f32 *)(wg - 0x8000) = z;
    *(wg - 0x8000) = r;
    *(wg - 0x8000) = g;
    *(wg - 0x8000) = b;
    *(wg - 0x8000) = a;
    *(volatile f32 *)(wg - 0x8000) = f1;
    *(volatile f32 *)(wg - 0x8000) = f27;
    *(volatile f32 *)(wg - 0x8000) = f0;
    *(volatile f32 *)(wg - 0x8000) = f2;
    *(volatile f32 *)(wg - 0x8000) = z;
    *(wg - 0x8000) = r;
    *(wg - 0x8000) = g;
    *(wg - 0x8000) = b;
    *(wg - 0x8000) = a;
    *(volatile f32 *)(wg - 0x8000) = f1;
    *(volatile f32 *)(wg - 0x8000) = f3;
    *(volatile f32 *)(wg - 0x8000) = f30;
    *(volatile f32 *)(wg - 0x8000) = f2;
    *(volatile f32 *)(wg - 0x8000) = z;
    *(wg - 0x8000) = r;
    *(wg - 0x8000) = g;
    *(wg - 0x8000) = b;
    *(wg - 0x8000) = a;
    *(volatile f32 *)(wg - 0x8000) = f28;
    *(volatile f32 *)(wg - 0x8000) = f3;
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_800116F0(void *arg0) {
#pragma scheduling off
    void PSMTXScale(void *, f32, f32, f32);
    void fn_80224E50(void *, s32, s32);
    extern f32 lbl_80368BDC;
    extern f64 lbl_80368C28;
    struct Obj {
        virtual s32 v0() = 0;
        virtual s32 v1() = 0;
        virtual s32 v2() = 0;
        virtual s32 v3() = 0;
        virtual s32 v4() = 0;
        virtual s32 v5() = 0;
        virtual s32 v6() = 0;
        virtual s32 v7() = 0;
        virtual s32 v8() = 0;
        virtual s32 v9() = 0;
        virtual s32 v10() = 0;
        virtual s32 v11() = 0;
        virtual s32 v12() = 0;
        virtual s32 v13() = 0;
        virtual s32 v14() = 0;
        virtual s32 v15() = 0;
    };
    u8 sp8[0x30];
    f32 inv_h;
    s32 t;
    Obj *obj = (Obj *)arg0;

    t = obj->v10();
    inv_h = lbl_80368BDC / (f32)t;
    t = obj->v9();
    PSMTXScale(sp8, lbl_80368BDC / (f32)t, inv_h, lbl_80368BDC);
    fn_80224E50(sp8, 0x21, 1);
#pragma scheduling reset
}
#pragma cplusplus reset
void fn_800117B0(void *arg0) {
    void fn_8006EBC4(s32, void *, void *, s32, s32);
    void fn_80222A3C(void *, s32, s32);
    void fn_80222C50(void *, s32);
    void fn_80222CF0(void *, s32);
    u8 sp8[0xC];
    u8 sp14[0x20];
    void *obj;
    s32 temp;

    obj = arg0;
    temp = (*(s32 (**)(void *))((u8 *)*(void **)obj + 0x24))(obj);
    fn_8006EBC4(*(s32 *)((u8 *)obj + 4), sp14, sp8,
        (*(s32 (**)(void *))((u8 *)*(void **)obj + 0x28))(obj), temp);
    fn_80222A3C(sp14, 0, 0);
    fn_80222C50(sp14, 1);
    fn_80222CF0(sp8, (*(s32 (**)(void *))((u8 *)*(void **)obj + 0x28))(obj));
}
#pragma cplusplus reset
void fn_8001185C(void) {
    M2C_UNK GXSetTevColorIn(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXSetTevAlphaIn(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXSetTevColorOp(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXSetTevAlphaOp(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    fn_802201A8(0, 1, 4, 0x1E, 0, 0x7D);
    GXSetTevColorIn(0, 0xF, 0xF, 0xF, 0xA);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 4, 5, 7);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevOrder(0, 0, 0, 4);
}

void fn_80011910(void) {
    M2C_UNK fn_802201A8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GXSetNumTexGens(M2C_UNK, M2C_UNK);
    M2C_UNK GXSetTevOrder(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    fn_802201A8(0, 1, 4, 0x21, 0, 0x7D);
    GXSetNumTexGens(0, 0);
    GXSetTevOrder(0, 0, 1, 4);
}

