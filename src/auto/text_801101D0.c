/* Functions from 0x801101D0 to 0x80120CC0, found by decomp-toolkit. */
#include "common.h"
#include "actor.h"
extern u8 lbl_8032FE24[];
extern u16 gActorXmlStrs[];
extern u16 lbl_80296128[];

typedef struct String {
    u32 size;
    u32 cap;
    char *data;
} String;

extern f32 lbl_8036A1DC;
extern f32 fActorDefaultRadius;
extern f32 lbl_8036A1C8;
extern u16 lbl_8028F6C8[];
void String_Init(void *, char *, void *);
void String_Destroy(void *, s32);
void fn_800E6418(void *, s32, void *, s32, s32, void *);
void fn_800D6878(void *, void *, void *);
void String_AssignCStr(void *, char *, u32);
s32 String_Compare(void *, s32, void *, char *, s32);
s32 String_Find(void *, char *, s32, s32);
u8 Actor_IsBusy(void *);
void Actor_LoadAnim(void *, void *, s32, s32, s32);
void fn_801134EC(void *, void *, void *);
void String_Assign(void *, void *, s32, s32);
void *String_CStr(void *);
extern u16 gUiPanelFlags;

extern s32 gUiInputFlags;

extern s32 gBattleState[];
extern f32 lbl_8036A184;
extern f32 lbl_8036A1BC;
extern f32 lbl_8036A1B0;
extern f64 lbl_8036A198;
extern f32 lbl_8036A1D8;
void fn_8005FEE8(void *, f32);
void fn_800608AC(void *);
void PSMTXRotRad(void *, s32, void *, f32, f32);
void fn_802029C4(void *, void *, void *);
#define VCALL(ptr, offset) (((void(**)(void *, void *))((u8*)(ptr) + (offset)))[0])

typedef struct {
    void *unk0;
    void *unk4;
    void *unk8;
    void *unkC;
    void *unk10;
    void *unk14;
    void *unk18;
    void *unk1C;
    void *unk20;
    void *unk24;
    void *unk28;
    void *unk2C;
    void *unk30;
    void *unk34;
    void *unk38;
    void *unk3C;
    void *unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    // ... (more fields if needed)
} UnitStruct;

// Global data for this function
u8 lbl_8028FDB0[0x10] = { 0 };
u8 lbl_80292230[0x28] = { 0 };
u8 lbl_802921E0[0x28] = { 0 };

extern f32 lbl_8036A1E8;
extern f32 lbl_8036A1F8;

extern u8 lbl_80367A48;

void fn_801101D0(void *arg0, s32 arg1) {
    void fn_800E5A4C(void *, s32);
    void fn_801C6978(void *);
    void *tmp = *(void **)((u8 *)arg0 + 0xE0);
    if (tmp != NULL) {
        fn_801C6978(tmp);
    }
    fn_800E5A4C(arg0, arg1);
}

u8 fn_80110220(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x1A7);
}

#pragma cplusplus on
extern "C" void fn_80110228(void *arg0) {
    s32 strlen(char *);
    void *Heap_Alloc(s32);
    s32 String_Compare(void *, s32, void *, char *, s32);
    void String_AssignCStr(void *, char *, u32);
    void String_Assign(void *, void *, s32, s32);
    void String_Destroy(void *, s32);
    void String_Init(void *, char *, void *);
    void String_ConcatCStr(void *, void *, char *);
    void String_JoinCStr(void *, void *, void *);
    void Camera_GetLookAt(void *, void *);
    void fn_800DB67C(void *, void *, s32);
    s32 fn_800DDAA4(void *, void *);
    void fn_800DF670(void *);
    void fn_800E4E7C(void *, void *, char *);
    void fn_800E4FE8(void *, void *, char *);
    s32 fn_800E5200(void *, s32, s32, f32);
    u8 fn_800E5248(void *, s32);
    void UiObj_SetCamerasTransitionDecay(void *, f32);
    void UiObj_SetCamerasTransition(void *, s32, s32, f32);
    void fn_80111740(void *);
    void fn_80151894(void *);
    void *fn_80151D50(void *, void *, void *, void *, void *, void *, s32);
    void *fn_801992F8(void *);
    s32 fn_80199310(void);
    void fn_80203184(void *, void *, void *);
    void fn_802031CC(void *, void *, f32);
    void fn_802031E8(void *, void *);
    extern void *gGame;
    extern f32 lbl_8036A188;
    extern f32 lbl_8036A18C;

    struct V3 {
        f32 x, y, z;
        V3() {}
        V3(f32 _x, f32 _y, f32 _z) { x = _x; y = _y; z = _z; }
    };

    struct Actor {
        u8 pad[0x40];
        virtual void v1() = 0;
        virtual void v0() = 0;
        virtual void v3() = 0;
        virtual void v2() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v10() = 0;
        virtual void v9() = 0;
        virtual void Color(f32, f32, f32) = 0;
        virtual V3 GetPos(s32) = 0;
    };

    struct Manager {
        u8 pad[0x10];
        virtual void v2() = 0;
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void Add(void *) = 0;
    };

    typedef struct {
        s32 x, y, z;
    } Word3;

    typedef void (*GetPosFn)(V3 *, void *, s32);

    V3 sp378;
    V3 sp384;
    String str294;
    String str288;
    String str27C;
    String str270;
    String str264;
    String str258;
    String str24C;
    String str240;
    String str1F8;
    String str1B0;
    String str168;
    String str2E8;
    String str2A0;
    Word3 copyB;
    Word3 tmpVec;
    Word3 copyA;
    V3 got;
    Word3 pos;
    V3 sp114;
    V3 sp120;
    V3 spFC;
    V3 sp108;
    V3 spE4;
    V3 spF0;
    V3 spCC;
    V3 spD8;
    V3 spB4;
    V3 spC0;
    V3 sp90;
    V3 spA8;
    V3 sp9C;
    V3 sp78;
    V3 sp84;
    V3 sp54;
    V3 sp6C;
    V3 sp60;
    V3 sp3C;
    V3 sp48;
    V3 sp24;
    V3 sp30;
    V3 sp360;
    V3 sp348;
    V3 sp324;
    V3 sp318;
    V3 sp2DC;
    V3 sp2D0;
    Word3 w300;
    Word3 w2B8;
    void *scratch;
    void *scratch2;
    void *scratch3;
    void *scratch4;
    void *scratch5;
    void *scratch6;
    void *self;
    s32 n;
    s8 flag;
    void *obj;
    void *other;
    f32 a0, a1, a2;
    f32 z;
    f32 temp_f;
    s32 t;
    void *tmp;

    self = arg0;
    sp384.z = lbl_8036A184;
    sp384.y = lbl_8036A184;
    sp384.x = lbl_8036A184;
    sp378.z = lbl_8036A184;
    sp378.y = lbl_8036A184;
    sp378.x = lbl_8036A184;

    if ((u8)fn_800E5248(self, 9) != 0) {
        UiObj_SetCamerasTransition(*(void **)((u8 *)self + 0xAC), 0, 0x3C, *(f32 *)((u8 *)gGame + 0x98));
    }
    if ((u8)fn_800E5248(self, 0xA) != 0) {
        UiObj_SetCamerasTransition(*(void **)((u8 *)self + 0xAC), 0, 0x3C, *(f32 *)((u8 *)gGame + 0x9C));
    }
    if ((u8)fn_800E5248(self, 0xB) != 0) {
        UiObj_SetCamerasTransition(*(void **)((u8 *)self + 0xAC), 0, 0x3C, *(f32 *)((u8 *)gGame + 0xA0));
    }
    if ((u8)fn_800E5248(self, 0x1E) != 0) {
        UiObj_SetCamerasTransition(*(void **)((u8 *)self + 0xAC), 0, -1, *(f32 *)((u8 *)gGame + 0x98));
    }
    if ((u8)fn_800E5248(self, 0x1F) != 0) {
        UiObj_SetCamerasTransition(*(void **)((u8 *)self + 0xAC), 0, -1, *(f32 *)((u8 *)gGame + 0x9C));
    }
    if ((u8)fn_800E5248(self, 0x20) != 0) {
        UiObj_SetCamerasTransition(*(void **)((u8 *)self + 0xAC), 0, -1, *(f32 *)((u8 *)gGame + 0xA0));
    }
    if ((u8)fn_800E5248(self, 0x21) != 0) {
        UiObj_SetCamerasTransitionDecay(*(void **)((u8 *)self + 0xAC), *(f32 *)((u8 *)gGame + 0x98));
    }

    if ((u8)fn_800E5248(self, 0x2B) != 0) {
        str294.size = 0;
        str294.cap = 0;
        str294.data = 0;
        str294.cap = 0;
        switch (*(s32 *)((u8 *)self + 0x1CC)) {
        case 1:
            n = strlen((char *)gActorXmlStrs + 0x1D);
            String_AssignCStr(&str294, (char *)gActorXmlStrs + 0x1D, n);
            break;
        case 2:
            n = strlen((char *)gActorXmlStrs + 0x2D);
            String_AssignCStr(&str294, (char *)gActorXmlStrs + 0x2D, n);
            break;
        case 3:
            n = strlen((char *)gActorXmlStrs + 0x3E);
            String_AssignCStr(&str294, (char *)gActorXmlStrs + 0x3E, n);
            break;
        default:
            String_Destroy(&str294, -1);
            goto after_2b;
        }
        *(f32 *)&pos.z = lbl_8036A184;
        *(f32 *)&pos.y = lbl_8036A184;
        *(f32 *)&pos.x = lbl_8036A184;
        n = strlen((char *)gActorXmlStrs + 0x4E);
        if (String_Compare(&str294, 0, (void *)str294.size, (char *)gActorXmlStrs + 0x4E, n) != 0) {
            got = ((Actor *)self)->GetPos(0);
            flag = 0;
            *(f32 *)&pos.y = got.y;
            *(f32 *)&pos.x = got.x;
            *(f32 *)&pos.z = got.z;
            *(f32 *)&pos.y = lbl_8036A184;
            obj = Heap_Alloc(0xC8);
            if (obj != NULL) {
                Camera_GetLookAt(&tmpVec, self);
                copyA = tmpVec;
                copyB = pos;
                String_Init(&str240, (char *)gActorXmlStrs + 0x51, &scratch);
                flag = 1;
                obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &str240, &str294, &copyB, &copyA, 0);
            }
            if (flag) {
                String_Destroy(&str240, -1);
            }
            ((Actor *)obj)->Color(
                *(f32 *)((u8 *)gGame + 0x104),
                *(f32 *)((u8 *)gGame + 0x108),
                *(f32 *)((u8 *)gGame + 0x10C));
            fn_80151894(obj);
            (*(Manager **)((u8 *)self + 0xAC))->Add(obj);
        }
        String_Destroy(&str294, -1);
    }
after_2b:

    if ((u8)fn_800E5248(self, 0x2C) != 0) {
        str288.size = 0;
        str288.cap = 0;
        str288.data = 0;
        str288.cap = 0;
        switch (*(s32 *)((u8 *)self + 0x1CC)) {
        case 1:
            n = strlen((char *)gActorXmlStrs + 0x55);
            String_AssignCStr(&str288, (char *)gActorXmlStrs + 0x55, n);
            break;
        case 2:
            n = strlen((char *)gActorXmlStrs + 0x66);
            String_AssignCStr(&str288, (char *)gActorXmlStrs + 0x66, n);
            break;
        case 3:
            n = strlen((char *)gActorXmlStrs + 0x77);
            String_AssignCStr(&str288, (char *)gActorXmlStrs + 0x77, n);
            break;
        default:
            String_Destroy(&str288, -1);
            goto after_2c;
        }
        *(f32 *)&pos.z = lbl_8036A184;
        *(f32 *)&pos.y = lbl_8036A184;
        *(f32 *)&pos.x = lbl_8036A184;
        n = strlen((char *)gActorXmlStrs + 0x4E);
        if (String_Compare(&str288, 0, (void *)str288.size, (char *)gActorXmlStrs + 0x4E, n) != 0) {
            got = ((Actor *)self)->GetPos(0);
            flag = 0;
            *(f32 *)&pos.y = got.y;
            *(f32 *)&pos.x = got.x;
            *(f32 *)&pos.z = got.z;
            *(f32 *)&pos.y = lbl_8036A184;
            obj = Heap_Alloc(0xC8);
            if (obj != NULL) {
                Camera_GetLookAt(&tmpVec, self);
                copyA = tmpVec;
                copyB = pos;
                String_Init(&str1F8, (char *)gActorXmlStrs + 0x51, &scratch2);
                flag = 1;
                obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &str1F8, &str288, &copyB, &copyA, 0);
            }
            if (flag) {
                String_Destroy(&str1F8, -1);
            }
            ((Actor *)obj)->Color(
                *(f32 *)((u8 *)gGame + 0x104),
                *(f32 *)((u8 *)gGame + 0x108),
                *(f32 *)((u8 *)gGame + 0x10C));
            fn_80151894(obj);
            (*(Manager **)((u8 *)self + 0xAC))->Add(obj);
        }
        String_Destroy(&str288, -1);
    }
after_2c:

    if ((u8)fn_800E5248(self, 0x2D) != 0) {
        fn_80111740(self);
    }

    if ((u8)fn_800E5248(self, 0x2E) != 0) {
        str27C.size = 0;
        str27C.cap = 0;
        str27C.data = 0;
        str27C.cap = 0;
        switch (*(s32 *)((u8 *)self + 0x1CC)) {
        case 1:
            n = strlen((char *)gActorXmlStrs + 0x88);
            String_AssignCStr(&str27C, (char *)gActorXmlStrs + 0x88, n);
            break;
        case 2:
            n = strlen((char *)gActorXmlStrs + 0x99);
            String_AssignCStr(&str27C, (char *)gActorXmlStrs + 0x99, n);
            break;
        case 3:
            n = strlen((char *)gActorXmlStrs + 0xAA);
            String_AssignCStr(&str27C, (char *)gActorXmlStrs + 0xAA, n);
            break;
        default:
            String_Destroy(&str27C, -1);
            goto after_2e;
        }
        *(f32 *)&pos.z = lbl_8036A184;
        *(f32 *)&pos.y = lbl_8036A184;
        *(f32 *)&pos.x = lbl_8036A184;
        n = strlen((char *)gActorXmlStrs + 0x4E);
        if (String_Compare(&str27C, 0, (void *)str27C.size, (char *)gActorXmlStrs + 0x4E, n) != 0) {
            got = ((Actor *)self)->GetPos(0);
            flag = 0;
            *(f32 *)&pos.y = got.y;
            *(f32 *)&pos.x = got.x;
            *(f32 *)&pos.z = got.z;
            *(f32 *)&pos.y = lbl_8036A184;
            obj = Heap_Alloc(0xC8);
            if (obj != NULL) {
                Camera_GetLookAt(&tmpVec, self);
                copyA = tmpVec;
                copyB = pos;
                String_Init(&str1B0, (char *)gActorXmlStrs + 0x51, &scratch3);
                flag = 1;
                obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &str1B0, &str27C, &copyB, &copyA, 0);
            }
            if (flag) {
                String_Destroy(&str1B0, -1);
            }
            ((Actor *)obj)->Color(
                *(f32 *)((u8 *)gGame + 0x104),
                *(f32 *)((u8 *)gGame + 0x108),
                *(f32 *)((u8 *)gGame + 0x10C));
            fn_80151894(obj);
            (*(Manager **)((u8 *)self + 0xAC))->Add(obj);
        }
        String_Destroy(&str27C, -1);
    }
after_2e:

    if ((u8)fn_800E5248(self, 0x3C) != 0) {
        str270.size = 0;
        str270.cap = 0;
        str270.data = 0;
        str270.cap = 0;
        switch (*(s32 *)((u8 *)self + 0x1CC)) {
        case 1:
            n = strlen((char *)gActorXmlStrs + 0xBB);
            String_AssignCStr(&str270, (char *)gActorXmlStrs + 0xBB, n);
            break;
        case 2:
            n = strlen((char *)gActorXmlStrs + 0xCC);
            String_AssignCStr(&str270, (char *)gActorXmlStrs + 0xCC, n);
            break;
        case 3:
            n = strlen((char *)gActorXmlStrs + 0xDD);
            String_AssignCStr(&str270, (char *)gActorXmlStrs + 0xDD, n);
            break;
        default:
            String_Destroy(&str270, -1);
            goto after_3c;
        }
        *(f32 *)&pos.z = lbl_8036A184;
        *(f32 *)&pos.y = lbl_8036A184;
        *(f32 *)&pos.x = lbl_8036A184;
        n = strlen((char *)gActorXmlStrs + 0x4E);
        if (String_Compare(&str270, 0, (void *)str270.size, (char *)gActorXmlStrs + 0x4E, n) != 0) {
            got = ((Actor *)self)->GetPos(0);
            flag = 0;
            *(f32 *)&pos.y = got.y;
            *(f32 *)&pos.x = got.x;
            *(f32 *)&pos.z = got.z;
            *(f32 *)&pos.y = lbl_8036A184;
            obj = Heap_Alloc(0xC8);
            if (obj != NULL) {
                Camera_GetLookAt(&tmpVec, self);
                copyA = tmpVec;
                copyB = pos;
                String_Init(&str168, (char *)gActorXmlStrs + 0x51, &scratch4);
                flag = 1;
                obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &str168, &str270, &copyB, &copyA, 0);
            }
            if (flag) {
                String_Destroy(&str168, -1);
            }
            ((Actor *)obj)->Color(
                *(f32 *)((u8 *)gGame + 0x104),
                *(f32 *)((u8 *)gGame + 0x108),
                *(f32 *)((u8 *)gGame + 0x10C));
            fn_80151894(obj);
            (*(Manager **)((u8 *)self + 0xAC))->Add(obj);
        }
        String_Destroy(&str270, -1);
    }
after_3c:

    if ((u8)fn_800E5248(self, 0xC) != 0 && *(s32 *)((u8 *)self + 0x1B8) == 1) {
        if (*(s32 *)((u8 *)self + 0x19C) != 0) {
            if (*(void **)((u8 *)self + 0x118) == NULL) {
                a0 = *(f32 *)((u8 *)self + 0x48);
                a2 = *(f32 *)((u8 *)self + 0x50);
            } else {
                ((GetPosFn)((void **)*(void **)((u8 *)self + 0x40))[0xE])(&sp114, self, 0);
                other = *(void **)((u8 *)self + 0x118);
                ((GetPosFn)((void **)*(void **)((u8 *)other + 0x40))[0xE])(&sp120, other, 0);
                z = lbl_8036A184;
                spFC.y = z;
                spFC.x = sp120.x - (sp114.x - *(f32 *)((u8 *)self + 0x48));
                spFC.z = z;
                sp108.y = z;
                sp108.z = z;
                sp108.x = -*(f32 *)((u8 *)self + 0x60);
                fn_802031CC(&sp108, &sp108, *(f32 *)((u8 *)self + 0x128) * lbl_8036A188);
                fn_80203184(&spFC, &sp108, &spFC);
                a0 = spFC.x;
                a2 = lbl_8036A184;
            }
            sp384.x = a0;
            sp384.y = lbl_8036A184;
            sp384.z = a2;
        } else {
            if (*(void **)((u8 *)self + 0x118) == NULL) {
                a0 = *(f32 *)((u8 *)self + 0x48);
                a2 = *(f32 *)((u8 *)self + 0x50);
            } else {
                ((GetPosFn)((void **)*(void **)((u8 *)self + 0x40))[0xE])(&spE4, self, 0);
                other = *(void **)((u8 *)self + 0x118);
                ((GetPosFn)((void **)*(void **)((u8 *)other + 0x40))[0xE])(&spF0, other, 0);
                z = lbl_8036A184;
                spCC.y = z;
                spCC.x = spF0.x - (spE4.x - *(f32 *)((u8 *)self + 0x48));
                spCC.z = z;
                spD8.y = z;
                spD8.z = z;
                spD8.x = -*(f32 *)((u8 *)self + 0x60);
                fn_802031CC(&spD8, &spD8, *(f32 *)((u8 *)self + 0x128) * lbl_8036A18C);
                fn_80203184(&spCC, &spD8, &spCC);
                a0 = spCC.x;
                a2 = lbl_8036A184;
            }
            sp384.x = a0;
            sp384.y = lbl_8036A184;
            sp384.z = a2;
        }
        *(u8 *)((u8 *)self + 0x195) = 0;
        *(u8 *)((u8 *)self + 0x194) = 1;
        got = sp384;
        fn_800DB67C(self, &got, fn_800E5200(self, 0xD, *(s32 *)((u8 *)self + 0xCC), sp384.x) - *(s32 *)((u8 *)self + 0xCC));
        *(s32 *)((u8 *)self + 0x1A8) = 0;
    }

    if ((u8)fn_800E5248(self, 5) != 0 && *(s32 *)((u8 *)self + 0x1B8) == 1) {
        other = *(void **)((u8 *)self + 0x118);
        if (other != NULL) {
            temp_f = *(f32 *)((u8 *)gGame + 0x100);
            ((GetPosFn)((void **)*(void **)((u8 *)other + 0x40))[0xE])(&spB4, other, 0);
            tmp = *(void **)((u8 *)other + 0x118);
            ((GetPosFn)((void **)*(void **)((u8 *)tmp + 0x40))[0xE])(&spC0, tmp, 0);
            sp90.x = spB4.x;
            sp90.y = lbl_8036A184;
            sp90.z = lbl_8036A184;
            spA8.y = lbl_8036A184;
            spA8.z = lbl_8036A184;
            spA8.x = -*(f32 *)((u8 *)other + 0x60);
            fn_802031E8(&spA8, &spA8);
            fn_802031CC(&spA8, &spA8, temp_f);
            fn_80203184(&sp90, &spA8, &sp9C);
            sp384.y = lbl_8036A184;
            sp384.x = sp9C.x;
            sp384.z = lbl_8036A184;
        } else {
            got = ((Actor *)self)->GetPos(0);
            sp384 = got;
        }
        *(u8 *)((u8 *)self + 0x195) = 0;
        got = sp384;
        fn_800DB67C(self, &got, fn_800E5200(self, 0xD, *(s32 *)((u8 *)self + 0xCC), sp384.x) - *(s32 *)((u8 *)self + 0xCC));
        fn_80111740(self);
        *(s32 *)((u8 *)self + 0x1A8) = 0;
    }

    if ((u8)fn_800E5248(self, *(s32 *)((u8 *)gGame + 0x16C)) != 0) {
        other = *(void **)((u8 *)self + 0x118);
        if (other != NULL) {
            temp_f = *(f32 *)((u8 *)gGame + 0x17C);
            ((GetPosFn)((void **)*(void **)((u8 *)other + 0x40))[0xE])(&sp78, other, 0);
            tmp = *(void **)((u8 *)other + 0x118);
            ((GetPosFn)((void **)*(void **)((u8 *)tmp + 0x40))[0xE])(&sp84, tmp, 0);
            sp54.x = sp78.x;
            sp54.y = lbl_8036A184;
            sp54.z = lbl_8036A184;
            sp6C.y = lbl_8036A184;
            sp6C.z = lbl_8036A184;
            sp6C.x = -*(f32 *)((u8 *)other + 0x60);
            fn_802031E8(&sp6C, &sp6C);
            fn_802031CC(&sp6C, &sp6C, temp_f);
            fn_80203184(&sp54, &sp6C, &sp60);
            sp384.y = lbl_8036A184;
            sp384.x = sp60.x;
            sp384.z = lbl_8036A184;
        } else {
            got = ((Actor *)self)->GetPos(0);
            sp384 = got;
        }
        *(u8 *)((u8 *)self + 0x195) = 0;
        got = sp384;
        fn_800DB67C(self, &got, fn_800E5200(self, *(s32 *)((u8 *)gGame + 0x170), *(s32 *)((u8 *)self + 0xCC), sp384.x) - *(s32 *)((u8 *)self + 0xCC));
        fn_80111740(self);
        *(s32 *)((u8 *)self + 0x1A8) = 0;
    }

    if ((u8)fn_800E5248(self, *(s32 *)((u8 *)gGame + 0x174)) != 0) {
        if (*(void **)((u8 *)self + 0x118) == NULL) {
            a0 = *(f32 *)((u8 *)self + 0x48);
            a2 = *(f32 *)((u8 *)self + 0x50);
        } else {
            ((GetPosFn)((void **)*(void **)((u8 *)self + 0x40))[0xE])(&sp3C, self, 0);
            other = *(void **)((u8 *)self + 0x118);
            ((GetPosFn)((void **)*(void **)((u8 *)other + 0x40))[0xE])(&sp48, other, 0);
            z = lbl_8036A184;
            sp24.y = z;
            sp24.x = sp48.x - (sp3C.x - *(f32 *)((u8 *)self + 0x48));
            sp24.z = z;
            sp30.y = z;
            sp30.z = z;
            sp30.x = -*(f32 *)((u8 *)self + 0x60);
            fn_802031CC(&sp30, &sp30, *(f32 *)((u8 *)self + 0x128) * lbl_8036A18C);
            fn_80203184(&sp24, &sp30, &sp24);
            a0 = sp24.x;
            a2 = lbl_8036A184;
        }
        sp384.x = a0;
        sp384.y = lbl_8036A184;
        *(u8 *)((u8 *)self + 0x195) = 0;
        sp384.z = a2;
        got = sp384;
        fn_800DB67C(self, &got, fn_800E5200(self, *(s32 *)((u8 *)gGame + 0x178), *(s32 *)((u8 *)self + 0xCC), sp384.x) - *(s32 *)((u8 *)self + 0xCC));
        fn_80111740(self);
        *(s32 *)((u8 *)self + 0x1A8) = 0;
    }

    if ((u8)fn_800E5248(self, 0xE) != 0) {
        if (*(void **)((u8 *)self + 0x11C) != NULL) {
            t = fn_80199310();
            fn_800DF670(*(void **)((u8 *)self + 0x11C));
            if (t == 3) {
                fn_800E4FE8(*(void **)((u8 *)self + 0x11C), self, (char *)gActorXmlStrs + 0xEE);
            } else {
                fn_800E4FE8(*(void **)((u8 *)self + 0x11C), self, (char *)gActorXmlStrs + 0xF5);
            }
            String_Init(&str24C, (char *)gActorXmlStrs + 0xFC, &scratch5);
            String_JoinCStr(&str258, fn_801992F8(*(void **)((u8 *)self + 0x11C)), &str24C);
            String_Assign((u8 *)self + 0x154, &str258, 0, -1);
            String_Destroy(&str258, -1);
            String_Destroy(&str24C, -1);
        }
        String_ConcatCStr(&str264, (u8 *)self + 0x154, (char *)gActorXmlStrs + 0xFE);
        t = fn_800DDAA4(*(void **)((u8 *)self + 0xDC), &str264) == 0 ? 1 : 0;
        String_Destroy(&str264, -1);
        if ((u8)t != 0) {
            *(u8 *)((u8 *)self + 0x1A4) = 1;
        }
    }

    if ((u8)fn_800E5248(self, 3) != 0) {
        *(s32 *)((u8 *)self + 0x1B4) = 1;
    }

    if (*(s32 *)((u8 *)gGame + 0x194) != 0 && (u8)fn_800E5248(self, 3) != 0) {
        tmp = *(void **)((u8 *)self + 0x11C);
        if (tmp != NULL) {
            if (*(u32 *)((u8 *)self + 0x120) != 0) {
                fn_800E4E7C(&sp324, self, (char *)gActorXmlStrs + 0x103);
                sp378 = sp324;
            } else {
                fn_800E4E7C(&sp318, tmp, (char *)gActorXmlStrs + 0x103);
                sp378 = sp318;
            }
            flag = 0;
            obj = Heap_Alloc(0xC8);
            if (obj != NULL) {
                Camera_GetLookAt(&w300, self);
                copyA = w300;
                *(f32 *)&copyB.x = sp378.x;
                *(f32 *)&copyB.y = sp378.y;
                *(f32 *)&copyB.z = sp378.z;
                String_Init(&str2E8, (char *)gActorXmlStrs + 0x51, &scratch6);
                flag = 1;
                obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &str2E8, (u8 *)gGame + 0x19C, &copyB, &copyA, 0);
            }
            (*(Manager **)((u8 *)self + 0xAC))->Add(obj);
            if (flag) {
                String_Destroy(&str2E8, -1);
            }
        }
    }

    if (*(s32 *)((u8 *)gGame + 0x198) != 0 && (u8)fn_800E5248(self, 3) != 0) {
        tmp = *(void **)((u8 *)self + 0x11C);
        if (tmp != NULL) {
            if (*(u32 *)((u8 *)self + 0x120) != 0) {
                fn_800E4E7C(&sp2DC, self, (char *)gActorXmlStrs + 0x103);
                sp378 = sp2DC;
            } else {
                fn_800E4E7C(&sp2D0, tmp, (char *)gActorXmlStrs + 0x103);
                sp378 = sp2D0;
            }
            flag = 0;
            obj = Heap_Alloc(0xC8);
            if (obj != NULL) {
                Camera_GetLookAt(&w2B8, self);
                copyA = w2B8;
                *(f32 *)&copyB.x = sp378.x;
                *(f32 *)&copyB.y = sp378.y;
                *(f32 *)&copyB.z = sp378.z;
                String_Init(&str2A0, (char *)gActorXmlStrs + 0x51, &scratch);
                flag = 1;
                obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &str2A0, (u8 *)gGame + 0x1A8, &copyB, &copyA, 0);
            }
            (*(Manager **)((u8 *)self + 0xAC))->Add(obj);
            if (flag) {
                String_Destroy(&str2A0, -1);
            }
        }
    }
}
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_80111740(void *arg0) {
    s32 strlen(char *);
    void *Heap_Alloc(s32);
    void Camera_GetLookAt(void *, void *);
    void *fn_80151D50(void *, void *, void *, void *, void *, void *, s32);
    void fn_80151894(void *);
    extern void *gGame;

    struct V3 {
        f32 x, y, z;
        V3() {}
        V3(f32 _x, f32 _y, f32 _z) { x = _x; y = _y; z = _z; }
    };

    struct Actor {
        u8 pad[0x40];
        virtual void v1() = 0;
        virtual void v0() = 0;
        virtual void v3() = 0;
        virtual void v2() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v10() = 0;
        virtual void v9() = 0;
        virtual void Color(f32, f32, f32) = 0;
        virtual V3 GetPos(s32) = 0;
    };

    struct Manager {
        u8 pad[0x10];
        virtual void v2() = 0;
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void Add(void *) = 0;
    };

    typedef struct {
        s32 x, y, z;
    } Word3;

    struct Self {
        u8 pad0[0xAC];
        void *mgr;
        String name;
        u8 pad1[0x1CC - 0xBC];
        s32 state;
    };

    String sp54;
    String sp48;
    Word3 copyB;
    Word3 tmpVec;
    Word3 copyA;
    V3 got;
    Word3 pos;
    void *scratch;
    Self *self;
    s32 n;
    s8 flag;
    void *obj;

    self = (Self *)arg0;
    sp54.size = 0;
    sp54.cap = 0;
    sp54.data = 0;
    sp54.cap = 0;

    n = strlen((char *)((u8 *)gActorXmlStrs + 0x109));
    if (String_Compare(&self->name, 0, (void *)self->name.size,
                    (char *)((u32)gActorXmlStrs + 0x109), n) == 0)
        goto fail;
    n = strlen((char *)((u8 *)gActorXmlStrs + 0x10E));
    if (String_Compare(&self->name, 0, (void *)self->name.size,
                    (char *)((u32)gActorXmlStrs + 0x10E), n) == 0)
        goto fail;
    n = strlen((char *)((u8 *)gActorXmlStrs + 0x113));
    if (String_Compare(&self->name, 0, (void *)self->name.size,
                    (char *)((u32)gActorXmlStrs + 0x113), n) == 0)
        goto fail;
    n = strlen((char *)((u8 *)gActorXmlStrs + 0x118));
    if (String_Compare(&self->name, 0, (void *)self->name.size,
                    (char *)((u32)gActorXmlStrs + 0x118), n) == 0)
        goto fail;
    n = strlen((char *)((u8 *)gActorXmlStrs + 0x11D));
    if (String_Compare(&self->name, 0, (void *)self->name.size,
                    (char *)((u32)gActorXmlStrs + 0x11D), n) == 0)
        goto fail;

    switch (self->state) {
    case 1:
        n = strlen((char *)((u8 *)gActorXmlStrs + 0x122));
        String_AssignCStr(&sp54, (char *)((u32)gActorXmlStrs + 0x122), n);
        break;
    case 2:
        n = strlen((char *)((u8 *)gActorXmlStrs + 0x133));
        String_AssignCStr(&sp54, (char *)((u32)gActorXmlStrs + 0x133), n);
        break;
    case 3:
        n = strlen((char *)((u8 *)gActorXmlStrs + 0x144));
        String_AssignCStr(&sp54, (char *)((u32)gActorXmlStrs + 0x144), n);
        break;
    default:
        goto fail;
    }

    *(f32 *)&pos.z = lbl_8036A184;
    *(f32 *)&pos.y = lbl_8036A184;
    *(f32 *)&pos.x = lbl_8036A184;
    n = strlen((char *)((u8 *)gActorXmlStrs + 0x4E));
    if (String_Compare(&sp54, 0, (void *)sp54.size,
                    (char *)((u32)gActorXmlStrs + 0x4E), n) != 0) {
        got = ((Actor *)self)->GetPos(0);
        flag = 0;
        *(f32 *)&pos.y = got.y;
        *(f32 *)&pos.x = got.x;
        *(f32 *)&pos.z = got.z;
        *(f32 *)&pos.y = lbl_8036A184;
        obj = Heap_Alloc(0xC8);
        if (obj != NULL) {
            Camera_GetLookAt(&tmpVec, self);
            copyA = tmpVec;
            copyB = pos;
            String_Init(&sp48, (char *)gActorXmlStrs + 0x51, &scratch);
            flag = 1;
            obj = fn_80151D50(obj, self->mgr, &sp48, &sp54, &copyB, &copyA, 0);
        }
        if (flag) {
            String_Destroy(&sp48, -1);
        }
        ((Actor *)obj)->Color(
            *(f32 *)((u8 *)gGame + 0x104),
            *(f32 *)((u8 *)gGame + 0x108),
            *(f32 *)((u8 *)gGame + 0x10C));
        fn_80151894(obj);
        (*(Manager **)(&self->mgr))->Add(obj);
    }
    String_Destroy(&sp54, -1);
    return;
fail:
    String_Destroy(&sp54, -1);
}

#pragma use_lmw_stmw on
#pragma optimization_level 3
#pragma cplusplus on
extern "C" void fn_80111AE8(void *self, String *name, u8 doSomething) {
    s32 strlen(char *);
    void *Heap_Alloc(s32);
    s32 String_Compare(void *, s32, void *, char *, s32);
    void String_Destroy(void *, s32);
    void String_Init(void *, char *, void *);
    void Camera_GetLookAt(void *, void *);
    void fn_80151894(void *);
    void *fn_80151D50(void *, void *, void *, void *, void *, void *, s32);
    extern void *gGame;

    struct V3 {
        f32 x, y, z;
    };

    struct Actor {
        u8 pad[0x40];
        virtual void v1() = 0;
        virtual void v0() = 0;
        virtual void v3() = 0;
        virtual void v2() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v10() = 0;
        virtual void v9() = 0;
        virtual void Color(f32, f32, f32) = 0;
        virtual V3 GetPos(s32) = 0;
    };

    struct Manager {
        u8 pad[0x10];
        virtual void v2() = 0;
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void Add(void *) = 0;
    };

    typedef struct {
        s32 x, y, z;
    } Word3;

    typedef void (*GetPosFn)(V3 *, void *, s32);

    Word3 pos;
    V3 got;
    Word3 copyA;
    Word3 tmpVec;
    Word3 copyB;
    String str;
    void *scratch;
    void *obj;
    s8 flag;
    s32 n;

    *(f32 *)&pos.z = 0.0f;
    *(f32 *)&pos.y = 0.0f;
    *(f32 *)&pos.x = 0.0f;
    n = strlen((char *)gActorXmlStrs + 0x4E);
    if (String_Compare(name, 0, (void *)name->size, (char *)gActorXmlStrs + 0x4E, n) != 0) {
        ((GetPosFn)((void **)*(void **)((u8 *)self + 0x40))[0xE])(&got, self, 0);
        flag = 0;
        *(f32 *)&pos.y = got.y;
        *(f32 *)&pos.x = got.x;
        *(f32 *)&pos.z = got.z;
        *(f32 *)&pos.y = 0.0f;
        if ((obj = Heap_Alloc(0xC8)) != 0) {
            Camera_GetLookAt(&tmpVec, self);
            copyA = tmpVec;
            copyB = pos;
            String_Init(&str, (char *)gActorXmlStrs + 0x51, &scratch);
            flag = 1;
            obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &str, name, &copyB, &copyA, 0);
        }
        if (flag) {
            String_Destroy(&str, -1);
        }
        ((Actor *)obj)->Color(
            *(f32 *)((u8 *)gGame + 0x104),
            *(f32 *)((u8 *)gGame + 0x108),
            *(f32 *)((u8 *)gGame + 0x10C));
        if (doSomething) {
            fn_80151894(obj);
        }
        (*(Manager **)((u8 *)self + 0xAC))->Add(obj);
    }
}

#pragma use_lmw_stmw on
extern "C" void fn_80111C8C(void *arg0, void *arg1) {
    s32 strlen(char *);
    s32 String_Compare(void *, s32, void *, char *, s32);
    void SeCue_PlayAt(char *, u8, f32, f32, f32);
    void UiObj_SetCamerasTransition(void *, s32, s32, f32);
    u8 *fn_80117CC0(void *, s32);
    extern void *gGame;
    u8 flagA, flagB, vol;
    s32 i;
    #define CMPAT(off) (String_Compare((void *)((u8 *)arg0 + 0xB0), 0, (void *)*(u32 *)((u8 *)arg0 + 0xB0), (char *)((u32)gActorXmlStrs + (off)), strlen((char *)((u8 *)gActorXmlStrs + (off)))) == 0)
    #define PLAY(off) SeCue_PlayAt((char *)((u32)gActorXmlStrs + (off)), vol, ((f32 *)arg1)[0], ((f32 *)arg1)[1], ((f32 *)arg1)[2])
    flagA = 0;
    flagB = 0;
    vol = 0x50;
    if (*(s32 *)((u8 *)arg0 + 0x1D0) == 0) vol = 0x64;
    if (CMPAT(0x155) || CMPAT(0x15A) || CMPAT(0x15F)) {
        PLAY(0x164);
        flagA = 1;
    } else if (CMPAT(0x178) || CMPAT(0x17D) || CMPAT(0x182) || CMPAT(0x187)) {
        PLAY(0x18C);
        flagA = 1;
    } else if (CMPAT(0x1A0) || CMPAT(0x1A5) || CMPAT(0x1AA)) {
        PLAY(0x1AF);
        flagB = 1;
    } else if (CMPAT(0x1C3) || CMPAT(0x1C8)) {
        PLAY(0x1CD);
        flagB = 1;
    } else if (CMPAT(0x1E1) || CMPAT(0x1E6) || CMPAT(0x1EB)) {
        PLAY(0x1F0);
    } else if (CMPAT(0x205)) {
        PLAY(0x20A);
    } else if (CMPAT(0x109) || CMPAT(0x10E) || CMPAT(0x113) || CMPAT(0x118) || CMPAT(0x11D)) {
        PLAY(0x21E);
        UiObj_SetCamerasTransition(*(void **)((u8 *)arg0 + 0xAC), 1, 0x3C, *(f32 *)((u8 *)gGame + 0x94));
    } else if (CMPAT(0x232) || CMPAT(0x237) || CMPAT(0x23C) || CMPAT(0x241) || CMPAT(0x246) || (*fn_80117CC0((u8 *)arg0 + 0xB0, 2) == 0x66)) {
        PLAY(0x24B);
    } else if (CMPAT(0x25F) || CMPAT(0x264) || CMPAT(0x269) || CMPAT(0x26E) || CMPAT(0x273) || CMPAT(0x278)) {
        PLAY(0x27D);
    } else {
        PLAY(0x20A);
    }
    i = *(s32 *)((u8 *)arg0 + 0x1D0);
    switch (i) {
    case 1:
        if (flagA || flagB) SeCue_PlayAt((char *)((u32)gActorXmlStrs + 0x291), 0x64, ((f32 *)arg1)[0], ((f32 *)arg1)[1], ((f32 *)arg1)[2]);
        else SeCue_PlayAt((char *)((u32)gActorXmlStrs + 0x2A4), 0x64, ((f32 *)arg1)[0], ((f32 *)arg1)[1], ((f32 *)arg1)[2]);
        break;
    case 2:
        if (flagA || flagB) SeCue_PlayAt((char *)((u32)gActorXmlStrs + 0x2B7), 0x64, ((f32 *)arg1)[0], ((f32 *)arg1)[1], ((f32 *)arg1)[2]);
        else SeCue_PlayAt((char *)((u32)gActorXmlStrs + 0x2CB), 0x64, ((f32 *)arg1)[0], ((f32 *)arg1)[1], ((f32 *)arg1)[2]);
        break;
    case 3:
        if (flagA || flagB) SeCue_PlayAt((char *)((u32)gActorXmlStrs + 0x2DF), 0x64, ((f32 *)arg1)[0], ((f32 *)arg1)[1], ((f32 *)arg1)[2]);
        else SeCue_PlayAt((char *)((u32)gActorXmlStrs + 0x2F2), 0x64, ((f32 *)arg1)[0], ((f32 *)arg1)[1], ((f32 *)arg1)[2]);
        break;
    }
}

#pragma cplusplus reset
#pragma optimization_level reset
#pragma use_lmw_stmw reset

extern "C" void fn_801126A4(void *arg0, s32 arg1, s32 arg2) {
 void Prim2D_Begin(void); void Prim2D_SetTransform(f32,f32,f32,f32); void Prim2D_SetTex(s32,s32); void Prim2D_PrepareTex(void);
 void Prim2D_AddPrim(s32); void Prim2D_SetPos(f32,f32); void Prim2D_SetText(void *); void Prim2D_SetScale(f32); void Prim2D_SetTint(s32,s32,s32,s32); void Prim2D_EndPrim(void);
 void *fn_800DDB94(void *,void *); int sprintf(char *,const char *,...);
 extern f32 lbl_8036A18C,lbl_8036A190;
 char buf[128];
 u8 *self=(u8 *)arg0; s32 x=arg1; s32 y=arg2;
 Prim2D_Begin(); Prim2D_SetTransform(0.0f,0.0f,0.0f,lbl_8036A18C);
 Prim2D_SetTex(0,19); Prim2D_PrepareTex();
 sprintf(buf,(char *)gActorXmlStrs+0x38b,String_CStr(self+0xbc));
 Prim2D_AddPrim(5); Prim2D_SetPos((f32)x,(f32)y); Prim2D_SetText(buf); Prim2D_SetScale(lbl_8036A190); Prim2D_SetTint(255,255,255,255); Prim2D_EndPrim();
 sprintf(buf,(char *)gActorXmlStrs+0x38b,fn_800DDB94(*(void **)(self+0xdc),self+0xbc));
 Prim2D_AddPrim(5); Prim2D_SetPos((f32)x,(f32)(y+16)); Prim2D_SetText(buf); Prim2D_SetScale(lbl_8036A190); Prim2D_SetTint(255,255,255,255); Prim2D_EndPrim();
}

#pragma cplusplus reset
#pragma use_lmw_stmw on
#pragma global_optimizer off
/* Parse actor XML at path into self: string-map entries, scalars, then apply defaults. */
void Actor_LoadXml(void *arg0, void *arg1) {
    void *Heap_Alloc(s32);
    void Xml_GetChildName(String *, void *);
    void Xml_GetChildValue(char *, void *);
    void Xml_GetNamedValue(void *, void *, String *);
    void Xml_AdvanceChild(void *);
    void Xml_Destroy(void *, s32);
    void *Xml_ParseFile(void *, void *, String *);
    void String_AssignCStr(String *, char *, u32);
    void String_Assign(String *, String *, s32, s32);
    void String_Destroy(String *, s32);
    void String_Init(String *, char *, void *);
    void *StringMap_FindOrInsert(void *, String *);
    u32 strlen(char *);
    extern void *gGame;
    extern f32 fActorDefaultHeight;

    char sp33C[0x20];
    char sp31C[0x20];
    char sp2FC[0x20];
    char sp2DC[0x20];
    char sp2BC[0x20];
    char sp29C[0x20];
    char sp27C[0x20];
    char sp25C[0x20];
    char sp23C[0x20];
    char sp21C[0x20];
    char sp1FC[0x20];
    char sp1DC[0x20];
    char sp1BC[0x20];
    char sp19C[0x20];
    char sp17C[0x20];
    char sp15C[0x20];
    char sp13C[0x20];
    String str130;
    String str124;
    String sp118;
    String sp10C;
    String sp100;
    String spF4;
    String spE8;
    String spDC;
    String spD0;
    String spC4;
    String spB8;
    String spAC;
    String spA0;
    String sp94;
    String sp88;
    String sp7C;
    String sp70;
    String sp64;
    String sp58;
    String sp4C;
    void *sc48;
    void *sc44;
    void *sc40;
    void *sc3C;
    void *sc38;
    void *sc34;
    void *sc30;
    void *sc2C;
    void *sc28;
    void *sc24;
    void *sc20;
    void *sc1C;
    void *sc18;
    void *sc14;
    void *sc10;
    void *scC;
    void *sc8;
    BattleActor *self;
    void *xml;
    char *nameBuf;
    s32 count;
    s32 i;
    void *path;
    s8 made;
    s32 tmp;
    String *node;

    self = (BattleActor *)arg0;
    path = arg1;
    made = 0;
    str130.cap = 0;
    str124.cap = 0;
    str130.size = 0;
    str130.data = 0;
    str130.cap = 0;
    str124.size = 0;
    str124.data = 0;
    str124.cap = 0;

    xml = Heap_Alloc(0x60);
    if (xml != 0) {
        String_Init(&sp118, (char *)gActorXmlStrs + 0x38E, &sc48);
        made = 1;
        xml = Xml_ParseFile(xml, path, &sp118);
    }
    if (made != 0) {
        String_Destroy(&sp118, -1);
    }

    String_Init(&sp10C, (char *)gActorXmlStrs + 0x393, &sc44);
    Xml_GetNamedValue(sp33C, xml, &sp10C);
    count = *(s32 *)sp33C;
    String_Destroy(&sp10C, -1);

    nameBuf = sp31C;
    for (i = 0; i < count; i++) {
        Xml_AdvanceChild(xml);
        Xml_GetChildName(&sp100, xml);
        String_Assign(&str130, &sp100, 0, -1);
        String_Destroy(&sp100, -1);
        Xml_GetChildValue(sp31C, xml);
        String_AssignCStr(&str124, nameBuf, strlen(nameBuf));
        node = (String *)((u8 *)StringMap_FindOrInsert((u8 *)self + 0x1BC, &str130) + 0xC);
        String_Assign(node, &str124, 0, -1);
    }

    String_Init(&spF4, (char *)gActorXmlStrs + 0x39A, &sc40);
    Xml_GetNamedValue(sp2FC, xml, &spF4);
    self->height = *(f32 *)sp2FC;
    String_Destroy(&spF4, -1);

    String_Init(&spE8, (char *)gActorXmlStrs + 0x3A3, &sc3C);
    Xml_GetNamedValue(sp2DC, xml, &spE8);
    self->radius = *(f32 *)sp2DC;
    String_Destroy(&spE8, -1);

    String_Init(&spDC, (char *)gActorXmlStrs + 0x3AA, &sc38);
    Xml_GetNamedValue(sp2BC, xml, &spDC);
    self->unk_12C = *(s32 *)sp2BC;
    String_Destroy(&spDC, -1);

    String_Init(&spD0, (char *)gActorXmlStrs + 0x3B7, &sc34);
    Xml_GetNamedValue(sp29C, xml, &spD0);
    self->unk_130 = *(s32 *)sp29C;
    String_Destroy(&spD0, -1);

    String_Init(&spC4, (char *)gActorXmlStrs + 0x3C6, &sc30);
    Xml_GetNamedValue(sp27C, xml, &spC4);
    self->unk_134 = *(s32 *)sp27C;
    String_Destroy(&spC4, -1);

    String_Init(&spB8, (char *)gActorXmlStrs + 0x3D3, &sc2C);
    Xml_GetNamedValue(sp25C, xml, &spB8);
    self->unk_138 = *(s32 *)sp25C;
    String_Destroy(&spB8, -1);

    String_Init(&spAC, (char *)gActorXmlStrs + 0x3E0, &sc28);
    Xml_GetNamedValue(sp23C, xml, &spAC);
    self->unk_13C = *(s32 *)sp23C;
    String_Destroy(&spAC, -1);

    String_Init(&spA0, (char *)gActorXmlStrs + 0x3ED, &sc24);
    Xml_GetNamedValue(sp21C, xml, &spA0);
    self->heightFlag = *(s32 *)sp21C;
    String_Destroy(&spA0, -1);

    String_Init(&sp94, (char *)gActorXmlStrs + 0x3F4, &sc20);
    Xml_GetNamedValue(sp1FC, xml, &sp94);
    tmp = *(s32 *)sp1FC;
    self->flag_1A1 = (u8)(tmp != 0);
    String_Destroy(&sp94, -1);

    String_Init(&sp88, (char *)gActorXmlStrs + 0x401, &sc1C);
    Xml_GetNamedValue(sp1DC, xml, &sp88);
    self->rate = *(s32 *)sp1DC;
    String_Destroy(&sp88, -1);

    String_Init(&sp7C, (char *)gActorXmlStrs + 0x40A, &sc18);
    Xml_GetNamedValue(sp1BC, xml, &sp7C);
    self->unk_150 = *(f32 *)sp1BC;
    String_Destroy(&sp7C, -1);

    String_Init(&sp70, (char *)gActorXmlStrs + 0x417, &sc14);
    Xml_GetNamedValue(sp19C, xml, &sp70);
    self->unk_188 = *(s32 *)sp19C;
    String_Destroy(&sp70, -1);

    String_Init(&sp64, (char *)gActorXmlStrs + 0x420, &sc10);
    Xml_GetNamedValue(sp17C, xml, &sp64);
    self->unk_18C = *(s32 *)sp17C;
    String_Destroy(&sp64, -1);

    String_Init(&sp58, (char *)gActorXmlStrs + 0x42D, &scC);
    Xml_GetNamedValue(sp15C, xml, &sp58);
    self->unk_190 = *(s32 *)sp15C;
    String_Destroy(&sp58, -1);

    String_Init(&sp4C, (char *)gActorXmlStrs + 0x43A, &sc8);
    Xml_GetNamedValue(sp13C, xml, &sp4C);
    tmp = *(s32 *)sp13C;
    self->flag_1B6 = (u8)(tmp != 0);
    String_Destroy(&sp4C, -1);

    if (lbl_8036A184 == self->height) {
        self->height = fActorDefaultHeight;
    }
    if (lbl_8036A184 == self->radius) {
        self->radius = fActorDefaultRadius;
    }
    if (self->rate == 0) {
        self->rate = 1;
    }
    if (lbl_8036A184 == self->unk_150) {
        self->unk_150 = *(f32 *)((u8 *)gGame + 0xEC);
    }
    if (self->unk_188 == 0) {
        self->unk_188 = *(s32 *)((u8 *)gGame + 0x180);
    }
    if (self->unk_18C == 0) {
        self->unk_18C = *(s32 *)((u8 *)gGame + 0x188);
    }
    if (self->unk_190 == 0) {
        self->unk_190 = *(s32 *)((u8 *)gGame + 0x184);
    }

    Xml_Destroy(xml, 1);
    String_Destroy(&str124, -1);
    String_Destroy(&str130, -1);
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma cplusplus reset

void fn_80112DFC(void *arg0, u8 arg1) {
    s32 *temp_r3;

    temp_r3 = M2C_FIELD(arg0, s32 **, 0xE0);
    if (temp_r3 != NULL) {
        if (arg1 != 0) {
            *temp_r3 |= 0x80;
            return;
        }
        *temp_r3 &= 0xFFFFFF7F;
    }
}

#pragma cplusplus on
typedef struct Vec3f {
    f32 x, y, z;
    Vec3f() {}
    Vec3f(f32 _x, f32 _y, f32 _z) {
        x = _x;
        y = _y;
        z = _z;
    }
} Vec3f;
extern "C" f32 PSVECDistance(const Vec3f &, const Vec3f &);
extern "C" void fn_80112E30(void *arg0) {
    extern f32 lbl_8036A1A8;
    struct Actor {
        u8 pad0[0x40];
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
        virtual Vec3f GetPos(s32) = 0;
    };
    Actor *target;
    Actor *self;
    f32 dist;

    self = (Actor *)arg0;
    target = M2C_FIELD(arg0, Actor **, 0x118);
    if (target == NULL) {
        dist = lbl_8036A184;
    } else {
        Vec3f pb;
        Vec3f pa;
        Vec3f b(lbl_8036A184, lbl_8036A184, lbl_8036A184);
        Vec3f a(lbl_8036A184, lbl_8036A184, lbl_8036A184);
        pa = a = self->GetPos(0);
        pb = b = target->GetPos(0);
        dist = PSVECDistance(pa, pb);
    }
    if (dist >= lbl_8036A1A8 + M2C_FIELD(arg0, f32 *, 0x128)) {
        M2C_FIELD(arg0, u8 *, 0x1A4) = 0;
    }
}
#pragma cplusplus reset

u8 fn_80112F3C(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x1A4);
}

#pragma global_optimizer off
s32 Actor_IsWaitAnim(void *actor) {
    /* True if the actor's current anim path is Wait, contains Wait, or contains the +0x444 name while idle. */
    s32 n;
    extern u16 gActorXmlStrs[];
    s32 strlen(char *);
    s32 String_Compare(void *, s32, void *, char *, s32);
    s32 String_Find(void *, char *, s32, s32);
    u8 Actor_IsBusy(void *);

    n = strlen((char *)gActorXmlStrs + 0x43F);
    if (String_Compare((u8 *)actor + 0x178, 0, (void *)*(s32 *)((u8 *)actor + 0x178),
                      (char *)gActorXmlStrs + 0x43F, n) == 0 ||
        (u32)(String_Find((u8 *)actor + 0x178, (char *)gActorXmlStrs + 0x43F, 0,
                         strlen((char *)gActorXmlStrs + 0x43F)) + 0x10000) != 0xFFFF ||
        ((u32)(String_Find((u8 *)actor + 0x178, (char *)gActorXmlStrs + 0x444, 0,
                          strlen((char *)gActorXmlStrs + 0x444)) + 0x10000) != 0xFFFF &&
         Actor_IsBusy(actor) == 0)) {
        return 1;
    }
    return 0;
}
#pragma global_optimizer off
void fn_80113030(void *arg0, s32 arg1, void *arg2, void *arg3) {
    void *StringMap_FindOrInsert(void *, void *);
    void String_Assign(void *, void *, s32, s32);
    s32 String_Compare(void *, s32, void *, char *, s32);
    void String_Init(void *, char *, void *);
    void String_Destroy(void *, s32);
    void String_JoinCStr(void *, char *, void *);
    void String_ConcatCStr(void *, void *, char *);
    void fn_800C99A0(void *, void *, s32, s32);
    void *String_CStr(void *);
    void fn_800E5044(void *, void *);
    extern char *lbl_8028F6B8[];
    String sp48;
    String sp3C;
    String sp30;
    String sp24;
    String sp18;
    String spC;
    void *sp8;
    s32 n;
    u8 *p;

    sp48.cap = 0;
    sp3C.cap = 0;
    sp48.size = 0;
    sp48.data = 0;
    sp48.cap = 0;
    sp3C.size = 0;
    sp3C.data = 0;
    sp3C.cap = 0;

    p = (u8 *)StringMap_FindOrInsert((u8 *)arg0 + 0x1BC, arg3) + 0xC;
    String_Assign(&sp3C, p, 0, -1);
    n = strlen((char *)((u8 *)gActorXmlStrs + 0x1C));
    if (String_Compare(&sp3C, 0, (void *)sp3C.size, (char *)((u32)gActorXmlStrs + 0x1C), n) == 0) {
        p = (u8 *)StringMap_FindOrInsert((u8 *)arg0 + 0x1BC, arg2) + 0xC;
        String_Assign(&sp3C, p, 0, -1);
    }
    n = strlen((char *)((u8 *)gActorXmlStrs + 0x1C));
    if (String_Compare(&sp3C, 0, (void *)sp3C.size, (char *)((u32)gActorXmlStrs + 0x1C), n) == 0) {
        String_Init(&sp30, lbl_8028F6B8[arg1 & 3], &sp8);
        p = (u8 *)StringMap_FindOrInsert((u8 *)arg0 + 0x1BC, &sp30) + 0xC;
        String_Assign(&sp3C, p, 0, -1);
        String_Destroy(&sp30, -1);
    }
    n = strlen((char *)((u8 *)gActorXmlStrs + 0x449));
    if (String_Compare(&sp3C, 0, (void *)sp3C.size, (char *)((u32)gActorXmlStrs + 0x449), n) == 0) {
        String_Assign(&sp3C, (u8 *)arg0 + 0xB0, 0, -1);
    }
    String_JoinCStr(&sp24, (char *)((u8 *)gActorXmlStrs + 0x450), (u8 *)arg0 + 0xB0);
    String_ConcatCStr(&sp18, &sp24, (char *)((u8 *)gActorXmlStrs + 0x454));
    String_Assign(&sp48, &sp18, 0, -1);
    String_Destroy(&sp18, -1);
    String_Destroy(&sp24, -1);
    String_ConcatCStr(&spC, &sp3C, (char *)((u8 *)gActorXmlStrs + 0x456));
    fn_800C99A0(&sp48, &spC, 0, -1);
    String_Destroy(&spC, -1);
    fn_800E5044(arg0, String_CStr(&sp48));
    String_Destroy(&sp3C, -1);
    String_Destroy(&sp48, -1);
}
#pragma global_optimizer on
/* Load an actor animation from a relative path under the actor base dir. */
void Actor_LoadAnim(void *actor, void *relPath, s32 flag, s32 arg3, s32 arg4) {
    void String_Concat(void *, void *, void *);
    void String_Substr(void *, void *, s32, s32);
    void fn_800E574C(void *, void *, f32, s32, s32, s32, s32);
    char *fn_800DDB94(void *, void *);
    u8 fn_800E7AD4(void *, void *, void *, u8, u8);
    extern f32 lbl_8036A18C;
    String fullPath;
    String pathStr;
    String concat;
    String prefix;
    String cueName;
    String cueCopy;
    String mapped;
    void *scratch;
    void *path;
    s32 a2;
    s32 a3;
    s32 a4;
    void *self;
    void *strMap;
    void *cstr;

    path = relPath;
    self = actor;
    a2 = flag;
    a3 = arg3;
    a4 = arg4;
    fullPath.size = 0;
    fullPath.cap = 0;
    fullPath.data = 0;
    fullPath.cap = 0;
    String_AssignCStr((u8 *)self + 0x178, path, strlen(path));
    String_Init(&pathStr, path, &scratch);
    String_Concat(&concat, (u8 *)self + 0x154, &pathStr);
    String_Assign(&fullPath, &concat, 0, -1);
    String_Destroy(&concat, -1);
    String_Destroy(&pathStr, -1);
    cstr = String_CStr(&fullPath);
    fn_800E574C(self, cstr, lbl_8036A18C, a3, a4, *(u8 *)((u8 *)self + 0x184), a2);
    mapped.cap = 0;
    cueCopy.cap = 0;
    cueName.cap = 0;
    mapped.size = 0;
    mapped.data = 0;
    mapped.cap = 0;
    cueCopy.size = 0;
    cueCopy.data = 0;
    cueCopy.cap = 0;
    cueName.size = 0;
    cueName.data = 0;
    cueName.cap = 0;
    strMap = *(void **)((u8 *)self + 0xDC);
    if (strMap == NULL) {
        String_Destroy(&cueName, -1);
        String_Destroy(&cueCopy, -1);
        String_Destroy(&mapped, -1);
    } else {
        char *mappedCstr;
        s32 n;
        mappedCstr = fn_800DDB94(strMap, (u8 *)self + 0xBC);
        String_AssignCStr(&mapped, mappedCstr, strlen(mappedCstr));
        n = strlen((char *)((u8 *)gActorXmlStrs + 0x1C));
        if (String_Compare(&mapped, 0, (void *)mapped.size, (char *)((u32)gActorXmlStrs + 0x1C), n) == 0) {
            String_Destroy(&cueName, -1);
            String_Destroy(&cueCopy, -1);
            String_Destroy(&mapped, -1);
        } else {
            String_Substr(&prefix, &mapped, 0, 0xB);
            String_Assign(&cueCopy, &prefix, 0, -1);
            String_Destroy(&prefix, -1);
            String_Assign(&cueName, &cueCopy, 0, -1);
            *(u8 *)((u8 *)self + 0x1A7) = fn_800E7AD4(*(void **)((u8 *)self + 0xAC), &cueName, *(void **)((u8 *)self + 0x1AC), *(u8 *)((u8 *)self + 0x1A2), *(u8 *)((u8 *)self + 0x1A3));
            String_Destroy(&cueName, -1);
            String_Destroy(&cueCopy, -1);
            String_Destroy(&mapped, -1);
        }
    }
    String_Destroy(&fullPath, -1);
}

#pragma global_optimizer off
void fn_801134EC(void *out, void *actor, void *name) {
    s32 strlen(char *);
    s32 String_Compare(void *, s32, void *, char *, s32);
    void String_Assign(void *, void *, s32, s32);
    void String_Destroy(void *, s32);
    void String_Concat(void *, void *, void *);
    void String_Copy(void *, void *);
    void fn_800C992C(void *, char *, u32);
    void fn_800C99A0(void *, void *, s32, s32);
    s32 fn_800DDC04(void *, void *);
    String path;
    String joined;
    u32 n;
    s32 ok;

    path.cap = 0;
    path.size = 0;
    path.data = 0;
    path.cap = 0;
    String_Assign(&path, name, 0, -1);
    n = strlen((char *)gActorXmlStrs + 0x1C);
    if (String_Compare((u8 *)actor + 0x160, 0, (void *)*(u32 *)((u8 *)actor + 0x160),
                       (char *)gActorXmlStrs + 0x1C, n) != 0) {
        fn_800C992C(&path, (char *)gActorXmlStrs + 0xFC,
                    strlen((char *)gActorXmlStrs + 0xFC));
        fn_800C99A0(&path, (u8 *)actor + 0x160, 0, -1);
    }
    String_Concat(&joined, (u8 *)actor + 0x154, &path);
    ok = fn_800DDC04(*(void **)((u8 *)actor + 0xDC), &joined) == 0;
    String_Destroy(&joined, -1);
    if ((u8)ok != 0) {
        String_Assign(&path, name, 0, -1);
        *(u8 *)((u8 *)actor + 0x184) = 1;
    } else {
        *(u8 *)((u8 *)actor + 0x184) = 1;
    }
    String_Copy(out, &path);
    String_Destroy(&path, -1);
}
#pragma global_optimizer on

void Actor_SetRadius(void *arg0, f32 farg0) {
    M2C_FIELD(arg0, f32 *, 0x128) = farg0;
}

f32 Actor_GetRadius(void *arg0) {
    return M2C_FIELD(arg0, f32 *, 0x128);
}

#pragma cplusplus on
extern "C" void fn_80113658(void *arg0, void *arg1) {
    struct Actor {
        u8 pad0[0x40];
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
        virtual Vec3f GetPos() = 0;
    };
    Vec3f a;
    Vec3f b;

    a = ((Actor *)arg0)->GetPos();
    b = ((Actor *)arg1)->GetPos();
    PSVECDistance(a, b);
}
#pragma cplusplus reset
void fn_801136EC(f32 *arg0, void *arg1) {
    s32 fn_800E4F0C(void *, char *);
    void fn_80060F70(void *, s32, f32 *);
    extern f32 lbl_8036A1B4;
    extern f32 lbl_8036A1B8;

    f32 pos[3];
    f32 x;
    f32 y;
    f32 z;
    s32 index;

    index = fn_800E4F0C(arg1, (char *)((u32)gActorXmlStrs + 0x45b));
    if (index == -1) {
        (*(void (**)(f32 *, void *, s32))(*(u8 **)((u8 *)arg1 + 0x40) + 0x38))(arg0, arg1, 0);
    } else {
        fn_80060F70(*(void **)((u8 *)arg1 + 0xE0), index, pos);
        x = pos[0];
        if (x > lbl_8036A1B4 && x < lbl_8036A1B8) {
            y = pos[1];
            z = pos[2];
        } else {
            z = lbl_8036A184;
            y = z;
            x = z;
        }
        arg0[0] = x;
        arg0[1] = y;
        arg0[2] = z;
    }
}

void fn_801137AC(f32 *out, void *arg1, u8 arg2) {
    s32 fn_800E4F0C(void *, char *);
    extern u16 lbl_80273DF8[];
    void fn_80060F70(void *, s32, f32 *);
    extern f32 lbl_8036A184;
    extern f32 lbl_8036A1B4;
    extern f32 lbl_8036A1B8;
    f32 sp8[3];
    int idx;
    register f32 x;
    f32 z;
    register f32 y;

    idx = fn_800E4F0C(arg1, (char *)lbl_80273DF8 + 0x45F);
    fn_80060F70(M2C_FIELD(arg1, void **, 0xE0), idx, sp8);
    x = sp8[0];
    if (x > lbl_8036A1B4 && x < lbl_8036A1B8) {
        y = lbl_8036A184;
        z = sp8[2];
    } else {
        z = lbl_8036A184;
        x = z;
        y = z;
    }
    if (M2C_FIELD(arg1, s32 *, 0x19C) != 0 || arg2 != 0) {
        y = sp8[1];
    }
    out[1] = y;
    out[0] = x;
    out[2] = z;
}

void fn_8011386C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x14C) = -1;
}

s32 Actor_HasHeightFlag(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x19C) != 0;
}

u8 fn_8011388C(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x1B4);
}

s32 fn_80113894(void *arg0) {
    u8 fn_8019906C(s32);
    s32 fn_80199114(s32);
    if ((fn_8019906C(M2C_FIELD(arg0, s32 *, 0x11C)) != 0) && (fn_80199114(M2C_FIELD(arg0, s32 *, 0x11C)) != -1)) {
        return 1;
    }
    return 0;
}

void fn_801138E8(void *arg0) {
    M2C_UNK fn_801990A4(s32);
    fn_801990A4(M2C_FIELD(arg0, s32 *, 0x11C));
}

void fn_8011390C(void *arg0) {
    M2C_UNK fn_801990DC(s32);
    fn_801990DC(M2C_FIELD(arg0, s32 *, 0x11C));
}

#pragma cplusplus on
extern "C" void fn_80113930(void *arg0) {
    struct Vec3 {
        f32 x, y, z;
Vec3() {}
Vec3(f32 v) { z=v; y=v; x=v; }
    };
    struct Actor {
        u8 pad0[0x40];
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
        virtual Vec3 GetPos(s32) = 0;
    };
    void fn_800E4E7C(void *, void *, char *);
    void Camera_GetLookAt(void *, void *);
    void fn_8019914C(void *, void *, void *, void *);
    void fn_801985C4(void *);
    extern f32 lbl_8036A184;
    extern u16 gActorXmlStrs[];
    Vec3 a(0.0f);
    Vec3 b(0.0f);
    Vec3 c(0.0f);
    Vec3 tmpA;
    Vec3 tmpB;
    Actor *other;


    fn_800E4E7C(&tmpA, arg0, (char *)gActorXmlStrs + 0x464);
    a.x = tmpA.x;
    a.y = tmpA.y;
    a.z = tmpA.z;

    Camera_GetLookAt(&tmpB, arg0);
    b.x = tmpB.x;
    b.y = tmpB.y;
    b.z = tmpB.z;

    other = *(Actor **)((u8 *)arg0 + 0x118);
    c = other->GetPos(0);

    fn_8019914C(*(void **)((u8 *)arg0 + 0x11C), &a, &b, &c);
    fn_801985C4(*(void **)((u8 *)arg0 + 0x11C));
}

extern "C" void fn_80113A24(void *arg0, u8 arg1) {
 struct Vec3 { f32 x,y,z; Vec3() {} Vec3(f32 f) { z=f; y=f; x=f; } };
 struct Actor {
 u8 pad[0x40];
 virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0;
 virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0;
 virtual void v8()=0; virtual void v9()=0; virtual void v10()=0; virtual void v11()=0;
 virtual Vec3 GetPos(s32)=0;
 };
 Vec3 Camera_GetLookAt(void *); s32 fn_801992F0(void *); void fn_8019914C(void *,void *,void *,void *);
 Vec3 a(0.0f), b(0.0f), c(0.0f);
 if(arg1 || fn_801992F0(*(void **)((u8 *)arg0+0x11c))==1 || fn_801992F0(*(void **)((u8 *)arg0+0x11c))==2) {
 typedef Vec3 (*GetPosFn)(void *,s32);
 GetPosFn *table=*(GetPosFn **)((u8 *)arg0+0x40);
 a=table[14](arg0,0);
 b=Camera_GetLookAt(arg0);
 } else {
 a=(*(Actor **)((u8 *)arg0+0x118))->GetPos(0);
 b=Camera_GetLookAt(*(void **)((u8 *)arg0+0x118));
 }
 c=(*(Actor **)((u8 *)arg0+0x118))->GetPos(0);
 a.y=0.0f;
 fn_8019914C(*(void **)((u8 *)arg0+0x11c),&a,&b,&c);
}

extern "C" void fn_80113BA0(void *arg0) {
    struct V3 {
        f32 x, y, z;
    };
    struct Actor {
        u8 pad[0x40];
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
        virtual V3 GetPos(s32) = 0;
    };
    void *fn_80117CC0(void *, s32);
    s32 fn_80199310(void *);
    void fn_80198910(void *, V3 *, s32);
    extern f32 lbl_8036A184;
    extern f32 lbl_8036A1BC;

    V3 pos;
    void *actor;
    V3 got;
    f32 twenty;
    f32 zero;
    s32 ch;

    zero = 0.0f;
    twenty = 20.0f;
    pos.x = twenty;
    pos.y = zero;
    pos.z = zero;

    actor = *(void **)((u8 *)arg0 + 0x118);
    if (actor != NULL) {
        got = ((Actor *)actor)->GetPos(1);
        pos.x = got.x;
        pos.y = got.y;
        pos.z = got.z;
    }
    if (fn_80199310(*(void **)((u8 *)arg0 + 0x11C)) == 3 && *(void **)((u8 *)arg0 + 0x120) != NULL) {
        register ch = *(u8 *)fn_80117CC0((u8 *)arg0 + 0xB0, 0);
        if (ch == 0x73) {
            fn_80198910(*(void **)((u8 *)arg0 + 0x120), &pos, *(s32 *)((u8 *)arg0 + 0x144));
        } else {
            fn_80198910(*(void **)((u8 *)arg0 + 0x120), &pos, 0);
        }
    } else {
        fn_80198910(*(void **)((u8 *)arg0 + 0x11C), &pos, 0);
    }
}
#pragma cplusplus reset

void fn_80113C84(void *self, s32 mode) {
    s32 strlen(char *);
    s32 fn_800DDC04(void *, void *);
    void String_Concat(void *, void *, void *);
    String sp3C;
    String sp30;
    String sp24;
    String sp18;
    String spC;
    s32 sp8;
    u32 ok;

    sp3C.cap = 0;
    sp30.cap = 0;
    sp3C.size = 0;
    sp3C.data = 0;
    sp3C.cap = 0;
    sp30.size = 0;
    sp30.data = 0;
    sp30.cap = 0;

    String_AssignCStr((u8 *)self + 0x16C, (char *)&gActorXmlStrs + 0x1C, strlen((char *)&gActorXmlStrs + 0x1C));
    *(s32 *)((u8 *)self + 0x144) = mode;

    switch (mode) {
    case 0:
        String_AssignCStr(&sp3C, (char *)&gActorXmlStrs + 0x46A, strlen((char *)&gActorXmlStrs + 0x46A));
        break;
    case 1:
        String_AssignCStr(&sp3C, (char *)&gActorXmlStrs + 0x46F, strlen((char *)&gActorXmlStrs + 0x46F));
        break;
    case 2:
        String_AssignCStr(&sp3C, (char *)&gActorXmlStrs + 0x46F, strlen((char *)&gActorXmlStrs + 0x46F));
        break;
    case 3:
        String_AssignCStr(&sp3C, (char *)&gActorXmlStrs + 0x478, strlen((char *)&gActorXmlStrs + 0x478));
        break;
    }

    if (String_Compare(&sp3C, 0, (void *)sp3C.size, (char *)&gActorXmlStrs + 0x478, strlen((char *)&gActorXmlStrs + 0x478)) == 0) {
        String_Init(&spC, String_CStr(&sp3C), &sp8);
        String_Concat(&sp18, (u8 *)self + 0x154, &spC);
        ok = fn_800DDC04(*(void **)((u8 *)self + 0xDC), &sp18) != 0;
        String_Destroy(&sp18, -1);
        String_Destroy(&spC, -1);
        if (ok == 0) {
            String_AssignCStr(&sp3C, (char *)&gActorXmlStrs + 0x46A, strlen((char *)&gActorXmlStrs + 0x46A));
        }
    }

    String_Assign(&sp30, &sp3C, 0, -1);
    fn_801134EC(&sp24, self, &sp3C);
    String_Assign(&sp3C, &sp24, 0, -1);
    String_Destroy(&sp24, -1);
    String_AssignCStr((u8 *)self + 0x16C, (char *)&gActorXmlStrs + 0x43F, strlen((char *)&gActorXmlStrs + 0x43F));
    Actor_LoadAnim(self, String_CStr(&sp3C), *(s32 *)((u8 *)self + 0x188), 0, 1);
    String_Assign((u8 *)self + 0x160, &sp30, 0, -1);
    *(u8 *)(*(u8 **)((u8 *)self + 0x11C) + 0x14D) = 0;
    *(u8 *)((u8 *)self + 0x1A4) = 1;
    String_Destroy(&sp30, -1);
    String_Destroy(&sp3C, -1);
}

u8 fn_80113F68(void *arg0) {
    extern f32 lbl_8036A184;
    return (u8) (lbl_8036A184 != M2C_FIELD(arg0, f32 *, 0x104));
}

#pragma cplusplus reset
void fn_80113F88(void *arg0) {
    void fn_800E4C14(void *, f32);
    void fn_800E4BE0(void *, s32, s32, f32);
    void SeCue_PlayAt(void *, s32, f32, f32, f32);
    extern f32 lbl_8036A1C0;
    extern f32 lbl_8036A1C4;

    typedef struct { f32 x, y, z; } Vec3f;
    f32 fx;
    f32 fy;
    f32 fz;
    Vec3f pos;
    void *child;

    (*(void (**)(Vec3f *, void *, s32))(*(u8 **)((u8 *)arg0 + 0x40) + 0x38))(&pos, arg0, 0);
    fx = pos.x;
    fy = pos.y;
    fz = pos.z;

    fn_800E4C14(arg0, lbl_8036A1C0);
    child = *(void **)((u8 *)arg0 + 0x11C);
    if (child != 0) {
        fn_800E4C14(child, lbl_8036A1C0);
    }
    fn_800E4BE0(arg0, 0x80, 0x270f, lbl_8036A1C4);
    child = *(void **)((u8 *)arg0 + 0x11C);
    if (child != 0) {
        fn_800E4BE0(child, 0x80, 0x270f, lbl_8036A1C4);
    }
    SeCue_PlayAt((char *)gActorXmlStrs + 0x481, 0x64, fx, fy, fz);
}
void fn_80114078(void *arg0) {
    s32 n;
    *(u8 *)((u8 *)arg0 + 0x184) = 1;
    Actor_LoadAnim(arg0, (u8 *)&gActorXmlStrs + 0x498, *(s32 *)((u8 *)arg0 + 0x188) * 2, 0, 1);
    n = strlen((char *)&gActorXmlStrs + 0x1C);
    String_AssignCStr((u8 *)arg0 + 0x160, (char *)&gActorXmlStrs + 0x1C, n);
    n = strlen((char *)&gActorXmlStrs + 0x1C);
    String_AssignCStr((u8 *)arg0 + 0x16C, (char *)&gActorXmlStrs + 0x1C, n);
    *(u8 *)((u8 *)arg0 + 0x1A4) = 1;
    *(u8 *)((u8 *)arg0 + 0x1A6) = 1;
}

#pragma cplusplus on
#pragma global_optimizer off
extern "C" void fn_80114124(void *arg0, s32 arg1) {
    s32 strlen(char *);
    void String_AssignCStr(void *, char *, u32);
    void String_Assign(void *, void *, s32, s32);
    void String_Destroy(void *, s32);
    void String_Init(void *, char *, void *);
    void String_Concat(void *, void *, void *);
    void String_ConcatCStr(void *, void *, char *);
    void String_JoinCStr(void *, void *, void *);
    void *String_CStr(void *);
    s32 String_Compare(void *, s32, void *, char *, s32);
    s32 fn_800DDAA4(void *, void *);
    s32 fn_800DDC04(void *, void *);
    void fn_800DF670(void *);
    void fn_800E4FE8(void *, void *, char *);
    void Actor_LoadAnim(void *, void *, s32, s32, s32);
    void fn_801134EC(void *, void *, void *);
    void SeCue_PlayAt(char *, s32, f32, f32, f32);
    void *fn_801992F8(void *);
    s32 fn_80199310(void);
    void fn_80203184(void *, void *, void *);
    void fn_802031CC(void *, void *, f32);
    extern f32 PSVECDistance(const Vec3f &, const Vec3f &);
    extern void *gGame;

    struct Actor {
        u8 pad0[0x40];
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
        virtual Vec3f GetPos(s32) = 0;
        virtual void v13() = 0;
        virtual void Adjust(Vec3f *, f32, f32) = 0;
    };

    typedef void (*GetPosFn)(Vec3f *, void *, s32);

    s32 t;
    f32 fx;
    f32 fy;
    f32 fz;
    f32 adj_x;
    f32 scale;
    String sp104;
    Vec3f spF8;
    Vec3f spEC;
    String spE0;
    String spD4;
    Vec3f spC8;
    String spBC;
    String spB0;
    String spA4;
    String sp98;
    String sp8C;
    Vec3f sp80;
    Vec3f sp74;
    Vec3f sp68;
    Vec3f sp5C;
    Vec3f sp50;
    Vec3f sp44;
    Vec3f sp38;
    Vec3f sp2C;
    Vec3f sp20;
    Vec3f sp14;
    void *scratch1;
    void *scratch0;
    void *scratch2;

    sp104.size = 0;
    sp104.cap = 0;
    sp104.data = 0;
    sp104.cap = 0;

    ((GetPosFn)((void **)*(void **)((u8 *)arg0 + 0x40))[0xE])(&spEC, arg0, 0);
    fx = spEC.x;
    fy = spEC.y;
    fz = spEC.z;

    String_AssignCStr((u8 *)arg0 + 0x16C, (char *)&gActorXmlStrs + 0x1C,
                strlen((char *)&gActorXmlStrs + 0x1C));

    if (*(void **)((u8 *)arg0 + 0x11C) != 0) {
        t = fn_80199310();
        fn_800DF670(*(void **)((u8 *)arg0 + 0x11C));
        if (t == 3) {
            fn_800E4FE8(*(void **)((u8 *)arg0 + 0x11C), arg0, (char *)&gActorXmlStrs + 0xEE);
        } else {
            fn_800E4FE8(*(void **)((u8 *)arg0 + 0x11C), arg0, (char *)&gActorXmlStrs + 0xF5);
        }
        String_Init(&spA4, (char *)&gActorXmlStrs + 0xFC, &scratch0);
        String_JoinCStr(&spB0, fn_801992F8(*(void **)((u8 *)arg0 + 0x11C)), &spA4);
        String_Assign((u8 *)arg0 + 0x154, &spB0, 0, -1);
        String_Destroy(&spB0, -1);
        String_Destroy(&spA4, -1);
    }

    String_ConcatCStr(&spBC, (u8 *)arg0 + 0x154, (char *)&gActorXmlStrs + 0xFE);
    t = fn_800DDAA4(*(void **)((u8 *)arg0 + 0xDC), &spBC) == 0 ? 1 : 0;
    String_Destroy(&spBC, -1);
    if ((u8)t != 0) {
        *(u8 *)((u8 *)arg0 + 0x1A4) = 1;
    }

    String_Init(&spE0, (char *)&gActorXmlStrs + 0x444, &scratch1);
    fn_801134EC(&spD4, arg0, &spE0);
    String_Assign(&sp104, &spD4, 0, -1);
    String_Destroy(&spD4, -1);
    String_Destroy(&spE0, -1);

    if (arg1 != 0) {
        String_Init(&sp8C, (char *)&gActorXmlStrs + 0x49D, &scratch2);
        String_Concat(&sp98, (u8 *)arg0 + 0x154, &sp8C);
        t = fn_800DDC04(*(void **)((u8 *)arg0 + 0xDC), &sp98) != 0 ? 1 : 0;
        String_Destroy(&sp98, -1);
        String_Destroy(&sp8C, -1);
        if ((u32)t == 0) {
            goto do_43f;
        }
        goto skip_43f;
    }
do_43f:
    String_AssignCStr((u8 *)arg0 + 0x16C, (char *)&gActorXmlStrs + 0x43F,
                strlen((char *)&gActorXmlStrs + 0x43F));
skip_43f:

    Actor_LoadAnim(arg0, String_CStr(&sp104), *(s32 *)((u8 *)arg0 + 0x188), 0, 1);

    {
        s32 n;
        n = strlen((char *)((u32)&gActorXmlStrs + 0x49D));
        if (String_Compare(&sp104, 0, (void *)sp104.size, (char *)((u32)&gActorXmlStrs + 0x49D), n) == 0) {
            String_AssignCStr((u8 *)arg0 + 0x160, (char *)&gActorXmlStrs + 0x1C,
                        strlen((char *)&gActorXmlStrs + 0x1C));
        } else {
            String_AssignCStr((u8 *)arg0 + 0x160, (char *)&gActorXmlStrs + 0x444,
                        strlen((char *)&gActorXmlStrs + 0x444));
        }
    }

    {
        f32 d;
        void *other;
        f32 z;
        f32 dx;
        other = *(void **)((u8 *)arg0 + 0x118);
        d = lbl_8036A184;
        spF8.z = d;
        spF8.y = d;
        spF8.x = d;
#pragma scheduling off
        if (other != 0) {
            goto do_dist;
        }
        goto after_dist;
#pragma scheduling reset
do_dist:
        sp44.z = d;
        sp44.y = d;
        sp44.x = d;
        sp50.z = d;
        sp50.y = d;
        sp50.x = d;
        ((GetPosFn)((void **)*(void **)((u8 *)arg0 + 0x40))[0xE])(&sp74, arg0, 0);
        sp5C = sp74;
        sp44 = sp74;
        ((GetPosFn)((void **)*(void **)((u8 *)other + 0x40))[0xE])(&sp80, other, 0);
        sp50 = sp80;
        sp68 = sp80;
        d = PSVECDistance(sp5C, sp68);
after_dist:

        scale = *(f32 *)((u8 *)gGame + 0xE0);
        if (d < *(f32 *)((u8 *)arg0 + 0x128) * scale) {
            f32 a0, a1, a2;
            if (*(u32 *)((u8 *)arg0 + 0x118) == 0) {
                a0 = *(f32 *)((u8 *)arg0 + 0x48);
                a1 = lbl_8036A184;
                a2 = *(f32 *)((u8 *)arg0 + 0x50);
            } else {
                ((GetPosFn)((void **)*(void **)((u8 *)arg0 + 0x40))[0xE])(&sp2C, arg0, 0);
                adj_x = sp2C.x;
                ((GetPosFn)((void **)*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x118) + 0x40))[0xE])(
                    &sp38, *(void **)((u8 *)arg0 + 0x118), 0);
                z = lbl_8036A184;
                dx = adj_x - *(f32 *)((u8 *)arg0 + 0x48);
                sp14.y = z;
                sp14.x = sp38.x - dx;
                sp14.z = z;
                sp20.y = z;
                sp20.z = z;
                sp20.x = -*(f32 *)((u8 *)arg0 + 0x60);
                fn_802031CC(&sp20, &sp20, *(f32 *)((u8 *)arg0 + 0x128) * scale);
                fn_80203184(&sp14, &sp20, &sp14);
                a0 = sp14.x;
                a1 = lbl_8036A184;
                a2 = lbl_8036A184;
            }
            spF8.x = a0;
            spF8.y = a1;
            spF8.z = a2;
            *(u32 *)&spC8.x = *(u32 *)&spF8.x;
            *(u32 *)&spC8.y = *(u32 *)&spF8.y;
            *(u32 *)&spC8.z = *(u32 *)&spF8.z;
            ((Actor *)arg0)->Adjust(&spC8, *(f32 *)((u8 *)gGame + 0xE4), lbl_8036A184);
        }
    }

    *(s32 *)((u8 *)arg0 + 0x140) = 0;
    SeCue_PlayAt((char *)&gActorXmlStrs + 0x4A7, 0x64, fx, fy, fz);
    *(u8 *)((u8 *)arg0 + 0x1A4) = 1;
    String_Destroy(&sp104, -1);
}

extern "C" void fn_801146BC(void *arg0) {
    void *Heap_Alloc(s32);
    void String_Init(void *, char *, void *);
    void String_Destroy(void *, s32);
    void Camera_GetLookAt(void *, void *);
    void *fn_80151D50(void *, void *, void *, void *, void *, void *, s32);
    struct Actor {
        u8 pad[0x40];
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
        virtual Vec3f GetPos(s32) = 0;
    };
    struct Manager {
        u8 pad[0x10];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void Add(void *) = 0;
    };
    typedef struct { s32 x, y, z; } Word3;
    Vec3f pos;
    Vec3f got;
    Word3 copyA;
    Word3 lookAt;
    Word3 copyB;
    String strLong;
    String strShort;
    void *scratch1;
    void *scratch2;
    void *obj;
    s8 flagLong;
    s8 flagShort;

    pos.z = 0.0f;
    pos.y = 0.0f;
    pos.x = 0.0f;
    got = ((Actor *)arg0)->GetPos(0);
    flagLong = 0;
    flagShort = 0;
    pos.y = got.y;
    pos.x = got.x;
    pos.z = got.z;
    pos.y = 6.0f + *(f32 *)((u8 *)arg0 + 0x4C);
    obj = Heap_Alloc(0xC8);
    if (obj != NULL) {
        Camera_GetLookAt(&lookAt, arg0);
        copyA = lookAt;
        *(u32 *)&copyB.x = *(u32 *)&pos.x;
        *(u32 *)&copyB.y = *(u32 *)&pos.y;
        *(u32 *)&copyB.z = *(u32 *)&pos.z;
        String_Init(&strLong, (char *)gActorXmlStrs + 0x4B5, &scratch1);
        flagLong = 1;
        String_Init(&strShort, (char *)gActorXmlStrs + 0x51, &scratch2);
        flagShort = 1;
        obj = fn_80151D50(obj, *(void **)((u8 *)arg0 + 0xAC), &strShort, &strLong, &copyB, &copyA, 0);
    }
    (*(Manager **)((u8 *)arg0 + 0xAC))->Add(obj);
    if (flagShort) {
        String_Destroy(&strShort, -1);
    }
    if (flagLong) {
        String_Destroy(&strLong, -1);
    }
}

#pragma global_optimizer reset
#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_80114840(void *arg0) {
    void *Heap_Alloc(s32);
    void String_Init(void *, char *, void *);
    void Camera_GetLookAt(void *, void *);
    void String_Destroy(void *, s32);
    void *fn_80151D50(void *, void *, void *, void *, void *, void *, s32);
    void SeCue_PlayAt(void *, s32, f32, f32, f32);
    extern void *gPadInput;
    void fn_80025624(void *, s32);

    struct Actor {
        u8 pad[0x40];
        virtual void v1() = 0;
        virtual void v0() = 0;
        virtual void v3() = 0;
        virtual void v2() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v10() = 0;
        virtual void v9() = 0;
        virtual void v11() = 0;
        virtual Vec3f GetPos(s32) = 0;
    };

    struct Manager {
        u8 pad[0x10];
        virtual void v2() = 0;
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5(void *) = 0;
    };

    typedef struct {
        s32 x, y, z;
    } Word3;

    void *self;
    Word3 pos;
    s8 flagA;
    register s8 flagB;
    register String strC;
    Vec3f got;
    Word3 copyA;
    register Word3 tmpVec;
    Word3 copyB2;
    register String strB;
    register String strA;
    Word3 copyB;
    void *obj;
    Word3 tmpVec2;
    Word3 copyA2;
    String strD;
    void *scratch;
    void *scratch2;
    void *scratch3;
    void *scratch4;

    self = arg0;
    *(f32 *)&pos.z = lbl_8036A184;
    *(f32 *)&pos.y = lbl_8036A184;
    *(f32 *)&pos.x = lbl_8036A184;
    got = ((Actor *)self)->GetPos(0);
    flagB = 0;
    flagA = 0;
    *(f32 *)&pos.y = got.y;
    *(f32 *)&pos.x = got.x;
    *(f32 *)&pos.z = got.z;
    *(f32 *)&pos.y = lbl_8036A1C8 + *(f32 *)((u8 *)self + 0x4C);
    *(s32 *)((u8 *)self + 0x140) = 0;
    obj = Heap_Alloc(0xC8);
    if (obj != NULL) {
        Camera_GetLookAt(&tmpVec, self);
        copyA = tmpVec;
        copyB = pos;
        String_Init(&strB, (char *)gActorXmlStrs + 0x4BE, &scratch);
        flagB = 1;
        String_Init(&strA, (char *)gActorXmlStrs + 0x51, &scratch2);
        flagA = 1;
        obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &strA, &strB, &copyB, &copyA, 0);
    }
    (*(Manager **)((u8 *)self + 0xAC))->v5(obj);
    if (flagA) {
        String_Destroy(&strA, -1);
    }
    if (flagB) {
        String_Destroy(&strB, -1);
    }
    flagA = 0;
    flagB = 0;
    obj = Heap_Alloc(0xC8);
    if (obj != NULL) {
        Camera_GetLookAt(&tmpVec2, self);
        copyA2 = tmpVec2;
        copyB2 = pos;
        String_Init(&strD, (char *)gActorXmlStrs + 0x4CB, &scratch3);
        flagA = 1;
        String_Init(&strC, (char *)gActorXmlStrs + 0x51, &scratch4);
        flagB = 1;
        obj = fn_80151D50(obj, *(void **)((u8 *)self + 0xAC), &strC, &strD, &copyB2, &copyA2, 0);
    }
    (*(Manager **)((u8 *)self + 0xAC))->v5(obj);
    if (flagB) {
        String_Destroy(&strC, -1);
    }
    if (flagA) {
        String_Destroy(&strD, -1);
    }
    SeCue_PlayAt((char *)gActorXmlStrs + 0x4DA, 0x64, *(f32 *)&pos.x, *(f32 *)&pos.y, *(f32 *)&pos.z);
    fn_80025624(gPadInput, 4);
    *(u8 *)((u8 *)self + 0x1A4) = 1;
}
#pragma cplusplus reset

typedef struct { f32 x, y, z; } PVector3;
#pragma cplusplus on
struct ActorMotionInterface {
    u8 pad[0x40];
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
    virtual PVector3 GetPos(s32) = 0;
    virtual void v13() = 0;
    virtual void Adjust(void *, f32, f32) = 0;
};
#pragma cplusplus on
#pragma push
#pragma dont_inline on
#pragma optimization_level 3
#pragma global_optimizer off
extern "C" void fn_80114AF0(void *arg0, s32 mode, u8 flag, u8 force) {
s32 strlen(char *);
s32 fn_80199310(void *);
void fn_800DF670(void *);
void fn_800E4FE8(void *,void *,char *);
void *fn_801992F8(void *);
void String_JoinCStr(void *,void *,void *);
void String_ConcatCStr(void *,void *,char *);
s32 fn_800DDAA4(void *,void *);
void fn_802031E8(void *,void *);
void fn_802031CC(void *,void *,f32);
void fn_80203184(void *,void *,void *);
void fn_800E4BE0(void *,s32,s32,f32);
void SeCue_PlayAt(char *,s32,f32,f32,f32);
void *fn_800E7E4C(void *,void *);
void fn_800DBF38(void *,s32,f32,f32);
void fn_80025624(void *,s32);
extern void *gGame;
extern void *gPadInput;
extern f32 lbl_8036A18C, lbl_8036A1C4, lbl_8036A1CC;
String anim;
f32 move[3];
PVector3 pos;
String se8, se7;
u32 copy[3];
String se6,se5,se4,se3,se2,se1,test,joined,suffix;
PVector3 other;
f32 current[3];
f32 dir[3], result[3], origin[3];
void *scratch7,*scratch6,*scratch5,*scratch4,*scratch3,*scratch2,*scratch1,*scratch0;
f32 scale,x,y,z,px;
s32 kind;
s32 missing;
anim.cap=0; anim.size=0; anim.data=0; anim.cap=0;
pos = ((ActorMotionInterface*)arg0)->GetPos(0);
x=pos.x;y=pos.y;z=pos.z;
if (*(void **)((u8*)arg0+0x11C)) {
kind=fn_80199310(*(void **)((u8*)arg0+0x11C));
fn_800DF670(*(void **)((u8*)arg0+0x11C));
if(kind==3) fn_800E4FE8(*(void **)((u8*)arg0+0x11C),arg0,(char*)gActorXmlStrs+0xEE);
else fn_800E4FE8(*(void **)((u8*)arg0+0x11C),arg0,(char*)gActorXmlStrs+0xF5);
String_Init(&suffix,(char*)gActorXmlStrs+0xFC,&scratch0);
String_JoinCStr(&joined,fn_801992F8(*(void **)((u8*)arg0+0x11C)),&suffix);
String_Assign((u8*)arg0+0x154,&joined,0,-1);
String_Destroy(&joined,-1);String_Destroy(&suffix,-1);
}
String_ConcatCStr(&test,(u8*)arg0+0x154,(char*)gActorXmlStrs+0xFE);
missing=fn_800DDAA4(*(void **)((u8*)arg0+0xDC),&test)==0 ? 1 : 0;
String_Destroy(&test,-1);
if((u8)missing) *(u8*)((u8*)arg0+0x1A4)=1;
if(!flag) {
*(u32*)((u8*)arg0+0x14C)=*(u32*)((u8*)gGame+0xE8);
*(s32*)((u8*)arg0+0x148)=mode;
}
String_Init(&se8,(char*)gActorXmlStrs+0x4ED,&scratch7);
fn_801134EC(&se7,arg0,&se8);
String_Assign(&anim,&se7,0,-1);
String_Destroy(&se7,-1);String_Destroy(&se8,-1);
String_AssignCStr((u8*)arg0+0x16C,(char*)gActorXmlStrs+0x43F,strlen((char*)gActorXmlStrs+0x43F));
Actor_LoadAnim(arg0,String_CStr(&anim),*(s32*)((u8*)arg0+0x188),0,1);
String_AssignCStr((u8*)arg0+0x160,(char*)gActorXmlStrs+0x4ED,strlen((char*)gActorXmlStrs+0x4ED));
move[2]=lbl_8036A184;move[1]=lbl_8036A184;move[0]=lbl_8036A184;
scale=*(f32*)((u8*)arg0+0x150);
((void (*)(void *,void *,s32))(*(void ***)((u8*)arg0+0x40))[14])(&current,arg0,0);
px=current[0];
other = ((ActorMotionInterface*)*(void **)((u8*)arg0+0x118))->GetPos(0);
origin[0]=px;origin[1]=lbl_8036A184;origin[2]=lbl_8036A184;
dir[0]=-*(f32*)((u8*)arg0+0x60);dir[1]=lbl_8036A184;dir[2]=lbl_8036A184;
fn_802031E8(&dir,&dir);fn_802031CC(&dir,&dir,scale);fn_80203184(&origin,&dir,&result);
move[1]=lbl_8036A184;move[0]=result[0];move[2]=lbl_8036A184;
*(u32*)&copy[0]=*(u32*)&move[0];*(u32*)&copy[1]=*(u32*)&move[1];*(u32*)&copy[2]=*(u32*)&move[2];
((ActorMotionInterface*)arg0)->Adjust(&copy,*(f32*)((u8*)gGame+0xF0),lbl_8036A184);
*(s32*)((u8*)arg0+0x140)=0;
{
f32 rate=*(f32*)((u8*)gGame+0xF8);
s32 frames=(s32)*(f32*)((u8*)gGame+0xF4);
fn_800E4BE0(arg0,frames,*(s32*)((u8*)gGame+0xFC),rate);
}
switch(*(s32*)((u8*)*(void **)((u8*)arg0+0x118)+0x144)){
case 3: SeCue_PlayAt((char*)gActorXmlStrs+0x305,100,x,y,z);
case 2: SeCue_PlayAt((char*)gActorXmlStrs+0x31D,100,x,y,z);
SeCue_PlayAt((char*)gActorXmlStrs+0x334,100,x,y,z);break;
case 1: SeCue_PlayAt((char*)gActorXmlStrs+0x334,100,x,y,z);
default:
if(force) SeCue_PlayAt((char*)gActorXmlStrs+0x31D,100,x,y,z);
else {
void *p=*(void **)((u8*)*(void **)((u8*)arg0+0x118)+0x11C);
kind=p?fn_80199310(p):0;
switch(kind){
case 0:case 2:case 5:case 7:case 10:
if(*(s32*)((u8*)*(void **)((u8*)arg0+0x118)+0x140)==0) SeCue_PlayAt((char*)gActorXmlStrs+0x34C,100,x,y,z);
else SeCue_PlayAt((char*)gActorXmlStrs+0x361,100,x,y,z);break;
case 1:case 3:case 6:SeCue_PlayAt((char*)gActorXmlStrs+0x374,100,x,y,z);break;
case 4:case 8:case 11:SeCue_PlayAt((char*)gActorXmlStrs+0x34C,100,x,y,z);break;
default:SeCue_PlayAt((char*)gActorXmlStrs+0x34C,100,x,y,z);break;
}
}
}
if(mode==1) {
String_Init(&se6,(char*)gActorXmlStrs+0x4F6,&scratch6);
{
void *obj=fn_800E7E4C(*(void **)((u8*)arg0+0xAC),&se6);
fn_800DBF38(obj,60,lbl_8036A18C,lbl_8036A18C);
}
String_Destroy(&se6,-1);
String_Init(&se5,(char*)gActorXmlStrs+0x4FD,&scratch5);
{
void *obj=fn_800E7E4C(*(void **)((u8*)arg0+0xAC),&se5);
fn_800DBF38(obj,60,lbl_8036A18C,lbl_8036A18C);
}
String_Destroy(&se5,-1);
fn_80025624(gPadInput,16);
}
else if(mode==2) {
String_Init(&se4,(char*)gActorXmlStrs+0x4F6,&scratch4);
{
void *obj=fn_800E7E4C(*(void **)((u8*)arg0+0xAC),&se4);
fn_800DBF38(obj,60,lbl_8036A1C4,lbl_8036A18C);
}
String_Destroy(&se4,-1);
String_Init(&se3,(char*)gActorXmlStrs+0x4FD,&scratch3);
{
void *obj=fn_800E7E4C(*(void **)((u8*)arg0+0xAC),&se3);
fn_800DBF38(obj,60,lbl_8036A1C4,lbl_8036A18C);
}
String_Destroy(&se3,-1);
fn_80025624(gPadInput,16);
}
else if(mode==3) {
String_Init(&se2,(char*)gActorXmlStrs+0x4F6,&scratch2);
{
void *obj=fn_800E7E4C(*(void **)((u8*)arg0+0xAC),&se2);
fn_800DBF38(obj,60,lbl_8036A1CC,lbl_8036A18C);
}
String_Destroy(&se2,-1);
String_Init(&se1,(char*)gActorXmlStrs+0x4FD,&scratch1);
{
void *obj=fn_800E7E4C(*(void **)((u8*)arg0+0xAC),&se1);
fn_800DBF38(obj,60,lbl_8036A1CC,lbl_8036A18C);
}
String_Destroy(&se1,-1);
fn_80025624(gPadInput,16);
}
else fn_80025624(gPadInput,8);
*(u8*)((u8*)arg0+0x1A4)=1;*(u8*)((u8*)arg0+0x1A0)=0;
String_Destroy(&anim,-1);
}
  #pragma pop
  #pragma cplusplus off
  void fn_80115264(void *self,s32 mode,s32 flag) {
s32 strlen(char *);
s32 fn_80199310(void *);
s32 kind;
s32 fn_800DDC04(void *,void *);
void String_Concat(void *,void *,void *);
void fn_800C992C(void *,char *,s32);
String spC8,spBC,spB0,spA4,sp98,sp8C,sp80,sp74,sp68,sp5C,sp50,sp44,sp38,sp2C,sp20;
s32 sc1C,sc18,sc14,sc10,scC,sc8;
u32 ok;
u8 saved;
spC8.cap=0;spBC.cap=0;
spC8.size=0;spC8.data=0;spC8.cap=0;
spBC.size=0;spBC.data=0;spBC.cap=0;
M2C_FIELD(self,u8 *,0x1a8)=1;
M2C_FIELD(self,s32 *,0x144)=mode;
switch(mode) {
case 0: {s32 len=strlen((char *)gActorXmlStrs+0x505); String_AssignCStr(&spC8,(char *)gActorXmlStrs+0x505,len);}
break;
case 1: {s32 len=strlen((char *)gActorXmlStrs+0x50a); String_AssignCStr(&spC8,(char *)gActorXmlStrs+0x50a,len);}
M2C_FIELD(self,s32 *,0x140)=0;
break;
case 2: {s32 len=strlen((char *)gActorXmlStrs+0x50a); String_AssignCStr(&spC8,(char *)gActorXmlStrs+0x50a,len);}
M2C_FIELD(self,s32 *,0x140)=1;
break;
case 3: {s32 len=strlen((char *)gActorXmlStrs+0x50f); String_AssignCStr(&spC8,(char *)gActorXmlStrs+0x50f,len);}
M2C_FIELD(self,s32 *,0x140)=0;
if(M2C_FIELD(self,s32 *,0x19c)) M2C_FIELD(self,u8 *,0x1a8)=0;
break;
case 4: {s32 len=strlen((char *)gActorXmlStrs+0x46a); String_AssignCStr(&spC8,(char *)gActorXmlStrs+0x46a,len);}
M2C_FIELD(self,s32 *,0x140)=0;
break;
case 5: {s32 len=strlen((char *)gActorXmlStrs+0x46f); String_AssignCStr(&spC8,(char *)gActorXmlStrs+0x46f,len);}
M2C_FIELD(self,s32 *,0x140)=0;
break;
case 6: {s32 len=strlen((char *)gActorXmlStrs+0x46f); String_AssignCStr(&spC8,(char *)gActorXmlStrs+0x46f,len);}
M2C_FIELD(self,s32 *,0x140)=0;
break;
case 7: {s32 len=strlen((char *)gActorXmlStrs+0x478); String_AssignCStr(&spC8,(char *)gActorXmlStrs+0x478,len);}
M2C_FIELD(self,s32 *,0x140)=0;
break;
}
if(mode<3) { if(!M2C_FIELD(self,s32 *,0x140)) {s32 len=strlen((char *)gActorXmlStrs+0x514); fn_800C992C(&spC8,(char *)gActorXmlStrs+0x514,len);} else {s32 len=strlen((char *)gActorXmlStrs+0x516); fn_800C992C(&spC8,(char *)gActorXmlStrs+0x516,len);} }
if(String_Compare(&spC8,0,(void *)spC8.size,(char *)gActorXmlStrs+0x518,strlen((char *)gActorXmlStrs+0x518))==0) {
String_Init(&sp80,String_CStr(&spC8),&sc18);
String_Concat(&sp8C,(u8 *)self+0x154,&sp80);
ok=fn_800DDC04(M2C_FIELD(self,void **,0xdc),&sp8C)!=0;
String_Destroy(&sp8C,-1); String_Destroy(&sp80,-1);
if(!ok) {s32 len=strlen((char *)gActorXmlStrs+0x51e); String_AssignCStr(&spC8,(char *)gActorXmlStrs+0x51e,len);}
}
if(String_Compare(&spC8,0,(void *)spC8.size,(char *)gActorXmlStrs+0x524,strlen((char *)gActorXmlStrs+0x524))==0) {
String_Init(&sp68,String_CStr(&spC8),&sc14);
String_Concat(&sp74,(u8 *)self+0x154,&sp68);
ok=fn_800DDC04(M2C_FIELD(self,void **,0xdc),&sp74)!=0;
String_Destroy(&sp74,-1); String_Destroy(&sp68,-1);
if(!ok) {s32 len=strlen((char *)gActorXmlStrs+0x52a); String_AssignCStr(&spC8,(char *)gActorXmlStrs+0x52a,len);}
}
if(String_Compare(&spC8,0,(void *)spC8.size,(char *)gActorXmlStrs+0x50f,strlen((char *)gActorXmlStrs+0x50f))==0) {
String_Init(&sp50,String_CStr(&spC8),&sc10);
String_Concat(&sp5C,(u8 *)self+0x154,&sp50);
ok=fn_800DDC04(M2C_FIELD(self,void **,0xdc),&sp5C)!=0;
String_Destroy(&sp5C,-1); String_Destroy(&sp50,-1);
if(!ok) {s32 len=strlen((char *)gActorXmlStrs+0x51e); String_AssignCStr(&spC8,(char *)gActorXmlStrs+0x51e,len);}
}
if(String_Compare(&spC8,0,(void *)spC8.size,(char *)gActorXmlStrs+0x478,strlen((char *)gActorXmlStrs+0x478))==0) {
String_Init(&sp38,String_CStr(&spC8),&scC);
String_Concat(&sp44,(u8 *)self+0x154,&sp38);
ok=fn_800DDC04(M2C_FIELD(self,void **,0xdc),&sp44)!=0;
String_Destroy(&sp44,-1); String_Destroy(&sp38,-1);
if(!ok) {s32 len=strlen((char *)gActorXmlStrs+0x46a); String_AssignCStr(&spC8,(char *)gActorXmlStrs+0x46a,len);}
}
saved=M2C_FIELD(self,u8 *,0x1a2);
if(M2C_FIELD(M2C_FIELD(self,void **,0x118),u8 *,0x1b6) && !M2C_FIELD(self,u8 *,0x1b6) && M2C_FIELD(self,s32 *,0x1b8)==1) {
if(saved) M2C_FIELD(self,u8 *,0x1a2)=0; else M2C_FIELD(self,u8 *,0x1a2)=1;
}
String_Assign(&spBC,&spC8,0,-1);
fn_801134EC(&spB0,self,&spC8);
String_Assign(&spC8,&spB0,0,-1);
String_Destroy(&spB0,-1);
Actor_LoadAnim(self,String_CStr(&spC8),M2C_FIELD(self,s32 *,0x188),0,1);
String_Assign((u8 *)self+0x160,&spBC,0,-1);
M2C_FIELD(self,u8 *,0x1a2)=saved;
if(mode) M2C_FIELD(self,s32 *,0x140)=0;
else { M2C_FIELD(self,s32 *,0x140)++; if(M2C_FIELD(self,s32 *,0x140)>1) M2C_FIELD(self,s32 *,0x140)=0; }
M2C_FIELD(self,u8 *,0x1a4)=1;
String_Init(&sp20,(char *)gActorXmlStrs+0x518,&sc8);
String_Concat(&sp2C,(u8 *)self+0x154,&sp20);
ok=fn_800DDC04(M2C_FIELD(self,void **,0xdc),&sp2C)!=0;
String_Destroy(&sp2C,-1);String_Destroy(&sp20,-1);
if(!ok) {M2C_FIELD(self,s32 *,0x140)=0;flag=0;}
if(flag) {{s32 len=strlen((char *)gActorXmlStrs+0x1c); String_AssignCStr((u8 *)self+0x16c,(char *)gActorXmlStrs+0x1c,len);}} else {
String_Init(&spA4,(char *)gActorXmlStrs+0x43f,&sc1C);
fn_801134EC(&sp98,self,&spA4);
String_Assign((u8 *)self+0x16c,&sp98,0,-1);
String_Destroy(&sp98,-1);String_Destroy(&spA4,-1);
}
if(M2C_FIELD(self,u8 *,0x1a1) && mode==2 && String_Compare((u8 *)self+0xb0,0,M2C_FIELD(self,void **,0xb0),(char *)gActorXmlStrs+0x530,strlen((char *)gActorXmlStrs+0x530))!=0) M2C_FIELD(self,u8 *,0x1b5)=1;
if(M2C_FIELD(self,u8 *,0x1a1) && mode==2 && String_Compare((u8 *)self+0xb0,0,M2C_FIELD(self,void **,0xb0),(char *)gActorXmlStrs+0x530,strlen((char *)gActorXmlStrs+0x530))==0) {
if(M2C_FIELD(self,void **,0x11c)) kind=fn_80199310(M2C_FIELD(self,void **,0x11c)); else kind=-1;
if(kind==2) M2C_FIELD(self,u8 *,0x1b5)=1;
}
if(M2C_FIELD(self,s32 *,0x19c)) M2C_FIELD(self,u8 *,0x1a0)=1;
String_Destroy(&spBC,-1);String_Destroy(&spC8,-1);
}

s32 fn_80115AF0(void *actor) {
#pragma global_optimizer off
    s32 n;
    extern u16 gActorXmlStrs[];
    s32 strlen(char *);
    s32 String_Compare(void *, s32, void *, char *, s32);
    s32 String_Find(void *, char *, s32, s32);

    n = strlen((char *)gActorXmlStrs + 0x4ED);
    if (String_Compare((u8 *)actor + 0x160, 0, (void *)*(s32 *)((u8 *)actor + 0x160),
                      (char *)gActorXmlStrs + 0x4ED, n) == 0 ||
        (n = strlen((char *)gActorXmlStrs + 0x444),
         String_Compare((u8 *)actor + 0x160, 0, (void *)*(s32 *)((u8 *)actor + 0x160),
                       (char *)gActorXmlStrs + 0x444, n) == 0)) {
        n = strlen((char *)gActorXmlStrs + 0x43F);
        if (String_Compare((u8 *)actor + 0x178, 0, (void *)*(s32 *)((u8 *)actor + 0x178),
                          (char *)gActorXmlStrs + 0x43F, n) == 0 ||
            (u32)(String_Find((u8 *)actor + 0x178, (char *)gActorXmlStrs + 0x43F, 0,
                             strlen((char *)gActorXmlStrs + 0x43F)) + 0x10000) != 0xFFFF) {
            return 1;
        }
        return 0;
    }
    return 0;
#pragma global_optimizer on
}

#pragma global_optimizer off
#pragma cplusplus on
extern "C" s32 fn_80115C0C(void *arg0, s32 arg1) {
    s32 strlen(char *);
    void String_AssignCStr(void *, char *, s32);
    s32 String_Compare(void *, s32, s32, char *, s32);
    void String_Init(void *, char *, void *);
    void String_Concat(void *, void *, void *);
    s32 fn_800DDC04(void *, void *);
    void String_Destroy(void *, s32);
    void Actor_ClearBusy(void *);
    void fn_80111740(void *);
    void Actor_LoadAnim(void *, char *, s32, s32, s32);
    void fn_80203184(f32 *, f32 *, f32 *);
    void fn_802031CC(f32 *, f32 *, f32);
    f32 PSVECDistance(f32 *, f32 *);
    extern u16 gActorXmlStrs[];
    extern void *gGame;
    extern f32 lbl_8036A184;
    extern f32 lbl_8036A1D0;
    extern f32 lbl_8036A1D4;

    typedef struct { f32 x, y, z; } Vec3f;
    typedef void (*GetPosFn)(Vec3f *, void *, s32);
    typedef u8 (*BoolFn)(void *);
    typedef void (*AdjustFn)(void *, Vec3f *, f32, f32);

    f32 spB0, spAC, spA8;
    Vec3f sp9C;
    u8 sp90[0xC];
    u8 sp84[0xC];
    Vec3f sp78, sp6C, sp60, sp54;
    Vec3f sp48, sp3C;
    Vec3f sp30, sp24;
    f32 sp18[3];
    f32 spC[3];
    u8 sp8[4];
    f32 dist;
    f32 pad;
    void *other;
    s32 ret;
    u8 doMove;
    u32 ok;
    void *self;

    self = arg0;
    spB0 = lbl_8036A184;
    doMove = 0;
    spAC = lbl_8036A184;
    ret = 0;
    spA8 = lbl_8036A184;
    String_AssignCStr((u8 *)self + 0x16C, (char *)&gActorXmlStrs + 0x1C, strlen((char *)&gActorXmlStrs + 0x1C));
    other = *(void **)((u8 *)self + 0x118);
    if (other == 0) return 1;
    if (*(u8 *)((u8 *)self + 0x195) != 0) return 1;
    if (*(s32 *)((u8 *)self + 0x12C) != 0 && arg1 == 0 && *(s32 *)((u8 *)self + 0x140) == 0) {
        Actor_ClearBusy(self); return 1;
    }
    if (*(s32 *)((u8 *)self + 0x130) != 0 && arg1 == 0 && *(s32 *)((u8 *)self + 0x140) != 0) {
        Actor_ClearBusy(self); return 1;
    }
    if (*(s32 *)((u8 *)self + 0x134) != 0 && arg1 == 1) {
        Actor_ClearBusy(self); return 1;
    }
    if (*(s32 *)((u8 *)self + 0x138) != 0 && arg1 == 2) {
        Actor_ClearBusy(self); return 1;
    }
    if (*(s32 *)((u8 *)self + 0x13C) != 0 && arg1 == 3) {
        Actor_ClearBusy(self); return 1;
    }
    if (other == 0) {
        dist = lbl_8036A184;
    } else {
        sp3C.x = sp3C.y = sp3C.z = lbl_8036A184;
        sp48.x = sp48.y = sp48.z = lbl_8036A184;
        ((GetPosFn)((void **)*(void **)((u8 *)self + 0x40))[0xE])(&sp6C, self, 0);
        sp54 = sp6C;
        sp3C = sp6C;
        ((GetPosFn)((void **)*(void **)((u8 *)other + 0x40))[0xE])(&sp78, other, 0);
        sp48 = sp78;
        sp60 = sp78;
        dist = PSVECDistance((f32 *)&sp54, (f32 *)&sp60);
    }
    pad = lbl_8036A1D4;
    if (String_Compare((u8 *)self + 0xB0, 0, *(s32 *)((u8 *)self + 0xB0), (char *)&gActorXmlStrs + 0x15F, strlen((char *)&gActorXmlStrs + 0x15F)) == 0) {
        pad = lbl_8036A1D0;
    }
    if (dist <= pad + (*(f32 *)((u8 *)self + 0x128) + *(f32 *)((u8 *)self + 0x1B0))) {
        Actor_ClearBusy(self); return 1;
    }
    if (((BoolFn)((void **)*(void **)((u8 *)self + 0x40))[0x12])(self) == 0
        && dist > (*(f32 *)((u8 *)self + 0x128) + *(f32 *)((u8 *)self + 0x1B0))
        && *(u8 *)((u8 *)self + 0x1A4) != 0
        && *(u8 *)((u8 *)self + 0x1A5) == 0) {
        *(u8 *)((u8 *)self + 0x184) = 1;
        Actor_LoadAnim(self, (char *)&gActorXmlStrs + 0x535, *(s32 *)((u8 *)self + 0x188), 0, 1);
        *(s32 *)((u8 *)self + 0x140) = 0;
        String_AssignCStr((u8 *)self + 0x160, (char *)&gActorXmlStrs + 0x535, strlen((char *)&gActorXmlStrs + 0x535));
        return 1;
    }
    if (*(u8 *)((u8 *)self + 0x1A4) != 0) {
        Actor_ClearBusy(self); return 1;
    }
    if (String_Compare((u8 *)self + 0x178, 0, *(s32 *)((u8 *)self + 0x178), (char *)&gActorXmlStrs + 0x53A, strlen((char *)&gActorXmlStrs + 0x53A)) == 0
        || String_Compare((u8 *)self + 0x178, 0, *(s32 *)((u8 *)self + 0x178), (char *)&gActorXmlStrs + 0x43F, strlen((char *)&gActorXmlStrs + 0x43F)) == 0) {
        String_Init(sp84, (char *)&gActorXmlStrs + 0x53F, sp8);
        String_Concat(sp90, (u8 *)self + 0x154, sp84);
        ok = fn_800DDC04(*(void **)((u8 *)self + 0xDC), sp90) != 0;
        String_Destroy(sp90, -1);
        String_Destroy(sp84, -1);
        if (ok) {
            *(u8 *)((u8 *)self + 0x184) = 1;
            Actor_LoadAnim(self, (char *)&gActorXmlStrs + 0x53F, *(s32 *)((u8 *)self + 0x18C), 0, 1);
            fn_80111740(self);
        }
    } else if (String_Compare((u8 *)self + 0x178, 0, *(s32 *)((u8 *)self + 0x178), (char *)&gActorXmlStrs + 0x53F, strlen((char *)&gActorXmlStrs + 0x53F)) == 0) {
        if (*(u8 *)((u8 *)self + 0xD0) == 0) {
            *(u8 *)((u8 *)self + 0x184) = 1;
            Actor_LoadAnim(self, (char *)&gActorXmlStrs + 0xFE, *(s32 *)((u8 *)self + 0x18C), 1, 1);
            String_AssignCStr((u8 *)self + 0x160, (char *)&gActorXmlStrs + 0xFE, strlen((char *)&gActorXmlStrs + 0xFE));
            doMove = 1;
            ret = 1;
        }
    } else {
        *(u8 *)((u8 *)self + 0x184) = 1;
        if (*(s32 *)((u8 *)self + 0x19C) == 0) {
            Actor_LoadAnim(self, (char *)&gActorXmlStrs + 0xFE, *(s32 *)((u8 *)self + 0x18C), 0, 1);
            String_AssignCStr((u8 *)self + 0x160, (char *)&gActorXmlStrs + 0xFE, strlen((char *)&gActorXmlStrs + 0xFE));
            fn_80111740(self);
            doMove = 1;
            ret = 0;
        } else {
            Actor_LoadAnim(self, (char *)&gActorXmlStrs + 0xFE, *(s32 *)((u8 *)self + 0x18C), 0, 1);
            String_AssignCStr((u8 *)self + 0x160, (char *)&gActorXmlStrs + 0x1C, strlen((char *)&gActorXmlStrs + 0x1C));
            fn_80111740(self);
            doMove = 0;
            *(u8 *)((u8 *)self + 0x1A0) = 1;
            ret = 1;
            *(u8 *)((u8 *)self + 0x1A4) = 1;
        }
    }
    if (doMove != 0) {
        f32 scale = *(f32 *)((u8 *)gGame + 0xDC);
        *(u8 *)((u8 *)self + 0x195) = 1;
        if (*(void **)((u8 *)self + 0x118) == 0) {
            spAC = lbl_8036A184;
            spA8 = *(f32 *)((u8 *)self + 0x48);
            spB0 = *(f32 *)((u8 *)self + 0x50);
        } else {
            void *oth = *(void **)((u8 *)self + 0x118);
            f32 px;
            ((GetPosFn)((void **)*(void **)((u8 *)self + 0x40))[0xE])(&sp24, self, 0);
            px = sp24.x;
            ((GetPosFn)((void **)*(void **)((u8 *)oth + 0x40))[0xE])(&sp30, oth, 0);
            spC[1] = lbl_8036A184;
            spC[2] = lbl_8036A184;
            spC[0] = sp30.x - (px - *(f32 *)((u8 *)self + 0x48));
            sp18[1] = lbl_8036A184;
            sp18[2] = lbl_8036A184;
            sp18[0] = -*(f32 *)((u8 *)self + 0x60);
            fn_802031CC(sp18, sp18, *(f32 *)((u8 *)self + 0x128) * scale);
            fn_80203184(spC, sp18, spC);
            spAC = lbl_8036A184;
            spA8 = spC[0];
            spB0 = lbl_8036A184;
        }
        sp9C.x = spA8;
        sp9C.y = spAC;
        sp9C.z = spB0;
        ((AdjustFn)((void **)*(void **)((u8 *)self + 0x40))[0x10])(self, &sp9C, *(f32 *)((u8 *)self + 0x124), lbl_8036A184);
        *(s32 *)((u8 *)self + 0x140) = 0;
        *(u8 *)((u8 *)self + 0x1A4) = 1;
    }
    return ret;
}
#pragma cplusplus reset
#pragma global_optimizer reset

#pragma global_optimizer off
void fn_8011631C(void *arg0, s8 arg1)
{
    String sp24;
    String sp18;
    String spC;
    s32 sp8;
    u8 flag;
    s32 n;
    s32 n2;
    extern u16 gActorXmlStrs[];
    s32 strlen(char *);
    s32 String_Compare(void *, s32, void *, char *, s32);
    s32 String_Find(void *, char *, s32, s32);
    u8 Actor_IsBusy(void *);
    void String_Init(void *, char *, void *);
    void String_Assign(void *, void *, s32, s32);
    void String_Destroy(void *, s32);
    void String_AssignCStr(void *, char *, s32);
    void *String_CStr(void *);
    void fn_801134EC(void *, void *, void *);
    void Actor_LoadAnim(void *, void *, s32, s32, s32);

    sp24.size = 0;
    sp24.cap = 0;
    sp24.data = 0;
    sp24.cap = 0;

    n = strlen((char *)gActorXmlStrs + 0x43F);
    if (String_Compare((u8 *)arg0 + 0x178, 0, (void *)*(s32 *)((u8 *)arg0 + 0x178),
                       (char *)gActorXmlStrs + 0x43F, n) == 0
        || (u32)(String_Find((u8 *)arg0 + 0x178, (char *)gActorXmlStrs + 0x43F, 0,
                             strlen((char *)gActorXmlStrs + 0x43F)) + 0x10000) != 0xFFFF
        || ((u32)(String_Find((u8 *)arg0 + 0x178, (char *)gActorXmlStrs + 0x444, 0,
                              strlen((char *)gActorXmlStrs + 0x444)) + 0x10000) != 0xFFFF
            && Actor_IsBusy(arg0) == 0)) {
        flag = 1;
    } else {
        flag = 0;
    }

    if (flag == 0 && *(u8 *)((u8 *)arg0 + 0x1A6) == 0) {
        String_Init(&sp18, (char *)gActorXmlStrs + 0x43F, &sp8);
        fn_801134EC(&spC, arg0, &sp18);
        String_Assign(&sp24, &spC, 0, -1);
        String_Destroy(&spC, -1);
        String_Destroy(&sp18, -1);
        *(u8 *)((u8 *)arg0 + 0x184) = arg1;

        n2 = strlen((char *)gActorXmlStrs + 0x43F);
        if (String_Compare(&sp24, 0, (void *)sp24.size, (char *)gActorXmlStrs + 0x43F, n2) == 0) {
            Actor_LoadAnim(arg0, String_CStr(&sp24), *(s32 *)((u8 *)arg0 + 0x190), 1, 1);
        } else {
            Actor_LoadAnim(arg0, String_CStr(&sp24), *(s32 *)((u8 *)arg0 + 0x188), 0, 1);
            String_AssignCStr((u8 *)arg0 + 0x16C, (char *)gActorXmlStrs + 0x43F,
                              strlen((char *)gActorXmlStrs + 0x43F));
        }
    }

    *(u8 *)((u8 *)arg0 + 0x1A8) = 0;
    String_Destroy(&sp24, -1);
}
#pragma global_optimizer reset
s32 fn_8011654C(void *arg0) {
    s32 fn_801992F0(void *);
    void *v;

    v = *(void **)((u8 *)arg0 + 0x11C);
    if (v != NULL) {
        return fn_801992F0(v);
    }
    return 0;
}

s32 fn_80116580(void *arg0) {
    s32 fn_80199310(void *);
    void *v;

    v = *(void **)((u8 *)arg0 + 0x11C);
    if (v != NULL) {
        return fn_80199310(v);
    }
    return -1;
}

#pragma peephole off
void *fn_801165B4(void *arg0, void *arg1) {
    void fn_80199318(void *, void *);
    u8 sp8[8];
    void *self;
    void *v;

    self = arg0;
    v = *(void **)((u8 *)arg1 + 0x11C);
    if (v != NULL) {
        fn_80199318(self, v);
    } else {
        String_Init(self, (char *)((u8 *)gActorXmlStrs + 0x1C), sp8);
    }
    return self;
}
#pragma peephole reset
s32 fn_80116604(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x11C);
}

void fn_8011660C(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x1B8) = arg1;
    if ((s32) M2C_FIELD(arg0, s32 *, 0x1B8) > 1) {
        M2C_FIELD(arg0, s8 *, 0x1A4) = 1;
        M2C_FIELD(arg0, s8 *, 0x1A5) = 1;
    }
}

void fn_8011662C(void *arg0, s32 arg1) {
    s32 fn_80165B04(s32);
    s32 fn_80165B0C(s32);
    M2C_UNK fn_801C4468(s32);
    M2C_UNK fn_801C6008(s32);
    s32 temp_r3;

    if (arg1 != 0) {
        M2C_FIELD(arg0, s32 *, 0x1CC) = fn_80165B0C(arg1);
        M2C_FIELD(arg0, s32 *, 0x1D0) = fn_80165B04(arg1);
        if ((s32) M2C_FIELD(arg0, s32 *, 0x1CC) == 2) {
            fn_801C4468(M2C_FIELD(arg0, s32 *, 0xE0));
        }
        temp_r3 = M2C_FIELD(arg0, s32 *, 0x1CC);
        if (((temp_r3 == 1) && ((s32) M2C_FIELD(arg0, s32 *, 0x1D0) == 1)) || ((temp_r3 == 3) && ((s32) M2C_FIELD(arg0, s32 *, 0x1D0) == 3))) {
            fn_801C6008(M2C_FIELD(arg0, s32 *, 0xE0));
        }
    }
}

#pragma cplusplus on
extern "C" void fn_801166C4(void *arg0, void *arg1) {
    struct Obj {
        u8 pad[0x40];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7(f32, f32, f32) = 0;
        virtual void v8() = 0;
        virtual void v9(f32, f32, f32) = 0;
    };
    extern f32 lbl_8036A184;
    extern u16 gActorXmlStrs[];

    void fn_800DF670(void *);
    void fn_800E4FE8(void *, void *, void *);

    u8 *obj;
    Obj *ptr;
    f32 value;

    obj = (u8 *)arg0;

    if (arg1 != NULL) {
        *(void **)(obj + 0x120) = arg1;
    }

    ptr = *(Obj **)(obj + 0x120);

    if (ptr != NULL) {
        value = lbl_8036A184;
        ptr->v7(value, value, value);

        ptr = *(Obj **)(obj + 0x120);
        value = lbl_8036A184;
        ptr->v9(value, value, value);

        fn_800DF670(*(void **)(obj + 0x120));

        fn_800E4FE8(
            *(void **)(obj + 0x120),
            obj,
            (u8 *)gActorXmlStrs + 0xF5
        );
    }
}
#pragma cplusplus reset
void fn_80116760(s32 arg0, s32 arg1) {
    extern u16 gActorXmlStrs[];
    s32 sp8;

    String_ConcatCStr(&sp8, arg1, (u8 *)gActorXmlStrs + 0xfc);
    String_Assign((void *)(arg0 + 0x154), &sp8, 0, -1);
    String_Destroy(&sp8, -1);
}

void fn_801167BC(void *actor, u32 arg1) {
    void *scratch;
    String str24;
    String str18;
    String strC;
    s32 kind;
    s32 fn_80199310(void *);
    void fn_800DF670(void *);
    void fn_800E4FE8(void *, void *, char *);
    char *fn_801992F8(void *);
    void String_JoinCStr(void *, char *, void *);
    void String_ConcatCStr(void *, void *, char *);
    s32 fn_800DDAA4(void *, void *);

    if (arg1 != 0) {
        *(u32 *)((u8 *)actor + 0x11C) = arg1;
    }
    if (*(u32 *)((u8 *)actor + 0x11C) != 0) {
        kind = fn_80199310(*(void **)((u8 *)actor + 0x11C));
        fn_800DF670(*(void **)((u8 *)actor + 0x11C));
        if (kind == 3) {
            fn_800E4FE8(*(void **)((u8 *)actor + 0x11C), actor, (char *)gActorXmlStrs + 0xEE);
        } else {
            fn_800E4FE8(*(void **)((u8 *)actor + 0x11C), actor, (char *)gActorXmlStrs + 0xF5);
        }
        String_Init(&str24, (char *)gActorXmlStrs + 0xFC, &scratch);
        String_JoinCStr(&str18, fn_801992F8(*(void **)((u8 *)actor + 0x11C)), &str24);
        String_Assign((u8 *)actor + 0x154, &str18, 0, -1);
        String_Destroy(&str18, -1);
        String_Destroy(&str24, -1);
    }
    String_ConcatCStr(&strC, (u8 *)actor + 0x154, (char *)gActorXmlStrs + 0xFE);
    kind = fn_800DDAA4(*(void **)((u8 *)actor + 0xDC), &strC) == 0;
    String_Destroy(&strC, -1);
    if ((u8)kind != 0) {
        *(u8 *)((u8 *)actor + 0x1A4) = 1;
    }
}

void fn_801168F4(void *arg0, char *arg1) {
    void String_Destroy(void *, s32);
    void String_Init(void *, char *, void *);
    s32 fn_800E7DA4(s32, void *);
    M2C_UNK spC;
    M2C_UNK sp8;

    String_Init(&spC, arg1, &sp8);
    *(s32 *)((u8 *)arg0 + 0x118) = fn_800E7DA4(*(s32 *)((u8 *)arg0 + 0xAC), &spC);
    String_Destroy(&spC, -1);
}

#pragma cplusplus on
extern "C" void fn_80116944(void *arg0) {
    struct Obj {
        u8 pad[0x40];
        virtual void v0();
        virtual void v1();
    };
    void fn_800608AC(s32);
    fn_800608AC(M2C_FIELD(arg0, s32 *, 0xE0));
    ((Obj *)arg0)->v1();
}

#pragma global_optimizer off
#pragma cplusplus on
extern "C" void fn_80116988(void *arg0, s32 arg1, f32 farg0) {
    s32 strlen(char *);
    void String_AssignCStr(void *, char *, u32);
    void String_Assign(void *, void *, s32, s32);
    void String_Destroy(void *, s32);
    void String_ConcatCStr(void *, void *, char *);
    s32 fn_800DDAA4(void *, void *);
    u32 fn_800DDC04(void *, void *);
    extern void *gGame;

    struct Actor {
        u8 pad0[0x40];
        virtual void v0() = 0;
        virtual void Unk() = 0;
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
        virtual Vec3f GetPos(s32) = 0;
        virtual void v13() = 0;
        virtual void Adjust(Vec3f *, f32, f32) = 0;
    };

    typedef void (*GetPosFn)(Vec3f *, void *, s32);

    f32 f31;
    f32 f30;
    f32 f29;
    f32 f28;
    f32 f27;
    f32 f26;
    u8 sp98[0x30];
    String sp8C;
    Vec3f sp80;
    Vec3f sp74;
    String sp68;
    String sp5C;
    String sp50;
    String sp44;
    String sp38;
    Vec3f sp2C;
    Vec3f sp20;
    Vec3f sp14;
    Vec3f sp8;

    sp8C.size = 0;
    sp8C.cap = 0;
    sp8C.data = 0;
    sp8C.cap = 0;

    f31 = farg0;
    {
        void *oth = *(void **)((u8 *)arg0 + 0x118);
        ((GetPosFn)((void **)*(void **)((u8 *)oth + 0x40))[0xE])(&sp74, oth, 0);
    }
    f30 = *(f32 *)((u8 *)arg0 + 0x128) * f31 + sp74.x;

    if (*(s32 *)((u8 *)arg0 + 0x19C) == 0) {
        String_ConcatCStr(&sp68, (u8 *)arg0 + 0x154, (char *)&gActorXmlStrs + 0x53F);
        String_Assign(&sp8C, &sp68, 0, -1);
        String_Destroy(&sp68, -1);
        if (fn_800DDC04(*(void **)((u8 *)arg0 + 0xDC), &sp8C) != 0) {
            u32 res;
            f27 = *(f32 *)((u8 *)arg0 + 0x48);
            f28 = *(f32 *)((u8 *)arg0 + 0x4C);
            f29 = *(f32 *)((u8 *)arg0 + 0x50);
            res = fn_800DDC04(*(void **)((u8 *)arg0 + 0xDC), &sp8C);
            if (res != 0) {
                f32 z = lbl_8036A184;
                void *e0;
                *(f32 *)((u8 *)arg0 + 0x50) = z;
                *(f32 *)((u8 *)arg0 + 0x4C) = z;
                *(f32 *)((u8 *)arg0 + 0x48) = z;
                e0 = *(void **)((u8 *)arg0 + 0xE0);
                *(u32 *)((u8 *)e0 + 0x44) = res;
                e0 = *(void **)((u8 *)arg0 + 0xE0);
                *(u32 *)((u8 *)e0 + 0x74) = 0;
                ((Actor *)arg0)->Unk();
                fn_8005FEE8(*(void **)((u8 *)arg0 + 0xE0), lbl_8036A1B0);
                fn_800608AC(*(void **)((u8 *)arg0 + 0xE0));
                ((GetPosFn)((void **)*(void **)((u8 *)arg0 + 0x40))[0xE])(&sp20, arg0, 0);
                f26 = sp20.x;
            } else {
                f26 = lbl_8036A184;
            }
            *(f32 *)((u8 *)arg0 + 0x48) = f27;
            *(f32 *)((u8 *)arg0 + 0x4C) = f28;
            *(f32 *)((u8 *)arg0 + 0x50) = f29;
        } else {
            f26 = lbl_8036A184;
        }
        String_ConcatCStr(&sp5C, (u8 *)arg0 + 0x154, (char *)&gActorXmlStrs + 0xFE);
        String_Assign(&sp8C, &sp5C, 0, -1);
        String_Destroy(&sp5C, -1);
        {
            s32 daa = fn_800DDAA4(*(void **)((u8 *)arg0 + 0xDC), &sp8C);
            if (daa != 0) {
                *(f32 *)((u8 *)arg0 + 0x48) =
                    f31 * (*(f32 *)((u8 *)arg0 + 0x124) * ((f32)daa * (f32)*(s32 *)((u8 *)arg0 + 0x198))) + f30;
                *(f32 *)((u8 *)arg0 + 0x48) = *(f32 *)((u8 *)arg0 + 0x48) + f26;
            } else {
                *(f32 *)((u8 *)arg0 + 0x48) = lbl_8036A1BC * f31;
            }
        }
    } else {
        f32 tmp;
        String_ConcatCStr(&sp50, (u8 *)arg0 + 0x154, (char *)&gActorXmlStrs + 0xFE);
        String_Assign(&sp8C, &sp50, 0, -1);
        String_Destroy(&sp50, -1);
        f28 = *(f32 *)((u8 *)arg0 + 0x48);
        f27 = *(f32 *)((u8 *)arg0 + 0x4C);
        f26 = *(f32 *)((u8 *)arg0 + 0x50);
        {
            u32 res = fn_800DDC04(*(void **)((u8 *)arg0 + 0xDC), &sp8C);
            if (res != 0) {
                f32 z = lbl_8036A184;
                void *e0;
                *(f32 *)((u8 *)arg0 + 0x50) = z;
                *(f32 *)((u8 *)arg0 + 0x4C) = z;
                *(f32 *)((u8 *)arg0 + 0x48) = z;
                e0 = *(void **)((u8 *)arg0 + 0xE0);
                *(u32 *)((u8 *)e0 + 0x44) = res;
                e0 = *(void **)((u8 *)arg0 + 0xE0);
                *(u32 *)((u8 *)e0 + 0x74) = 0;
                ((Actor *)arg0)->Unk();
                fn_8005FEE8(*(void **)((u8 *)arg0 + 0xE0), lbl_8036A1B0);
                fn_800608AC(*(void **)((u8 *)arg0 + 0xE0));
                ((GetPosFn)((void **)*(void **)((u8 *)arg0 + 0x40))[0xE])(&sp14, arg0, 0);
                tmp = sp14.x;
            } else {
                tmp = lbl_8036A184;
            }
        }
        *(f32 *)((u8 *)arg0 + 0x48) = f28;
        *(f32 *)((u8 *)arg0 + 0x4C) = f27;
        *(f32 *)((u8 *)arg0 + 0x50) = f26;
        *(f32 *)((u8 *)arg0 + 0x48) = f30 - tmp;
    }

    if ((u8)arg1 != 0) {
        void *oth;
        f32 dx;
        f32 z;
        oth = *(void **)((u8 *)arg0 + 0x118);
        dx = *(f32 *)((u8 *)arg0 + 0x48);
        z = lbl_8036A184;
        dx = dx - *(f32 *)((u8 *)oth + 0x48);
        sp80.y = z;
        sp80.x = dx;
        sp80.z = z;
        PSMTXRotRad(sp98, 0x59, gGame,
                    lbl_8036A1D8 * (*(f32 *)((u8 *)gGame + 0x164) * f31),
                    dx);
        fn_802029C4(sp98, &sp80, &sp80);
        *(f32 *)((u8 *)arg0 + 0x48) =
            *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x118) + 0x48) + sp80.x;
        *(f32 *)((u8 *)arg0 + 0x4C) =
            *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x118) + 0x4C) + sp80.y;
        *(f32 *)((u8 *)arg0 + 0x50) =
            *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x118) + 0x50) + sp80.z;
        *(f32 *)((u8 *)arg0 + 0x58) =
            *(f32 *)((u8 *)gGame + 0x164) * f31 + *(f32 *)((u8 *)arg0 + 0x58);
    }

    {
        f32 tmp;
        String_ConcatCStr(&sp44, (u8 *)arg0 + 0x154, (char *)&gActorXmlStrs + 0x535);
        String_Assign(&sp8C, &sp44, 0, -1);
        String_Destroy(&sp44, -1);
        f28 = *(f32 *)((u8 *)arg0 + 0x48);
        f27 = *(f32 *)((u8 *)arg0 + 0x4C);
        f26 = *(f32 *)((u8 *)arg0 + 0x50);
        {
            u32 res = fn_800DDC04(*(void **)((u8 *)arg0 + 0xDC), &sp8C);
            if (res != 0) {
                f32 z = lbl_8036A184;
                void *e0;
                *(f32 *)((u8 *)arg0 + 0x50) = z;
                *(f32 *)((u8 *)arg0 + 0x4C) = z;
                *(f32 *)((u8 *)arg0 + 0x48) = z;
                e0 = *(void **)((u8 *)arg0 + 0xE0);
                *(u32 *)((u8 *)e0 + 0x44) = res;
                e0 = *(void **)((u8 *)arg0 + 0xE0);
                *(u32 *)((u8 *)e0 + 0x74) = 0;
                ((Actor *)arg0)->Unk();
                fn_8005FEE8(*(void **)((u8 *)arg0 + 0xE0), lbl_8036A1B0);
                fn_800608AC(*(void **)((u8 *)arg0 + 0xE0));
                ((GetPosFn)((void **)*(void **)((u8 *)arg0 + 0x40))[0xE])(&sp8, arg0, 0);
                tmp = sp8.x;
            } else {
                tmp = lbl_8036A184;
            }
        }
        *(f32 *)((u8 *)arg0 + 0x48) = f28;
        tmp = (f32)__fabs((f64)tmp);
        *(f32 *)((u8 *)arg0 + 0x4C) = f27;
        *(f32 *)((u8 *)arg0 + 0x50) = f26;
        *(f32 *)((u8 *)arg0 + 0x1B0) = tmp;
        *(u8 *)((u8 *)arg0 + 0x1A4) = 0;
    }

    String_ConcatCStr(&sp38, (u8 *)arg0 + 0x154, (char *)&gActorXmlStrs + 0x53A);
    String_Assign(&sp8C, &sp38, 0, -1);
    String_Destroy(&sp38, -1);
    f28 = *(f32 *)((u8 *)arg0 + 0x48);
    f27 = *(f32 *)((u8 *)arg0 + 0x4C);
    f26 = *(f32 *)((u8 *)arg0 + 0x50);
    {
        u32 res = fn_800DDC04(*(void **)((u8 *)arg0 + 0xDC), &sp8C);
        if (res != 0) {
            f32 z = lbl_8036A184;
            void *e0;
            *(f32 *)((u8 *)arg0 + 0x50) = z;
            *(f32 *)((u8 *)arg0 + 0x4C) = z;
            *(f32 *)((u8 *)arg0 + 0x48) = z;
            e0 = *(void **)((u8 *)arg0 + 0xE0);
            *(u32 *)((u8 *)e0 + 0x44) = res;
            e0 = *(void **)((u8 *)arg0 + 0xE0);
            *(u32 *)((u8 *)e0 + 0x74) = 0;
            ((Actor *)arg0)->Unk();
            fn_8005FEE8(*(void **)((u8 *)arg0 + 0xE0), lbl_8036A1B0);
            fn_800608AC(*(void **)((u8 *)arg0 + 0xE0));
            ((GetPosFn)((void **)*(void **)((u8 *)arg0 + 0x40))[0xE])(&sp2C, arg0, 0);
        }
    }
    *(f32 *)((u8 *)arg0 + 0x48) = f28;
    *(f32 *)((u8 *)arg0 + 0x4C) = f27;
    *(f32 *)((u8 *)arg0 + 0x50) = f26;

    String_AssignCStr((u8 *)arg0 + 0x160, (char *)&gActorXmlStrs + 0x1C,
                strlen((char *)&gActorXmlStrs + 0x1C));
    String_Destroy(&sp8C, -1);
}
#pragma cplusplus reset
#pragma global_optimizer reset

#pragma optimization_level 1
extern "C" void fn_80116F84(void *arg0, s32 *arg1) {
 void fn_800DB7A4(void *, s32 (*)[3]);
 s32 copy[3];
 s32 *src = arg1;
 s32 c = src[2];
 s32 b = src[1];
 s32 a = src[0];
 copy[0]=a; copy[1]=b; copy[2]=c;
 fn_800DB7A4(arg0,&copy);
 if(M2C_FIELD(arg0,u8*,0x195)) M2C_FIELD(arg0,s32*,0x9C)=M2C_FIELD(arg0,s32*,0xC8)*M2C_FIELD(arg0,s32*,0x198);
}
#pragma optimization_level reset
#pragma cplusplus off
#pragma cplusplus on
#pragma cplusplus on
static inline s32 ActorUpdate_Compare(void *str, char *text) {
 s32 strlen(char *);
 return String_Compare(str,0,*(void **)str,text,strlen(text));
}
static inline void ActorUpdate_CopyVector(Vec3f *dst, const Vec3f *src) {
 const u32 *in=(const u32 *)src;
 u32 *out=(u32 *)dst;
 out[0]=in[0];out[1]=in[1];out[2]=in[2];
}
static inline void ActorUpdate_ReadPosition(Vec3f *out, void *actor) {
 typedef void (*Callback)(Vec3f *,void *,s32);
 Callback *vtable=*(Callback **)((u8 *)actor+0x40);
 Callback callback=vtable[14];
 callback(out,actor,0);
}
struct ActorUpdateSceneInterface {
 u8 pad[0x10];
 virtual void v0()=0;virtual void v1()=0;virtual void v2()=0;virtual void v3()=0;virtual void v4()=0;
 virtual void Add(void *)=0;
};
struct ActorUpdateInterface {
 u8 pad[0x40];
 virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0;
 virtual void v4()=0; virtual void v5()=0; virtual void v6()=0;
 virtual void SetScale(f32,f32,f32)=0;
 virtual void v8()=0; virtual void v9()=0; virtual void v10()=0; virtual void v11()=0;
 virtual Vec3f GetPos(s32)=0;
 virtual void v13()=0; virtual void v14()=0; virtual void v15()=0;
 virtual u8 IsBusy()=0;
};
#pragma cplusplus off
#pragma cplusplus on
#pragma global_optimizer off
#pragma optimization_level reset
#pragma global_optimizer off
extern "C" void fn_80116FE8(void *self) {
 s32 Str_Cmp(void *,char *); void fn_80111C8C(void *,void *);
 void fn_800E5DEC(void *); void fn_800DBAB8(void *,void *); void fn_800DF664(void *);
 s32 strlen(char *); s32 fn_80199310(void *); u8 fn_800E5248(void *,s32);
 void fn_80198FB0(void *); void Actor_ClearNodeLink(void *); void *Actor_SetNodeLink(void *,char *,char *,s32);
 void GActor_SetNodeLinkParam(void *,void *); void fn_80198F8C(void *,void *); s32 fn_801992F0(void *);
 void *Heap_Alloc(s32); void Camera_GetLookAt(void *,void *);
 void *fn_80151D50(void *,void *,void *,void *,void *,void *,s32);
 void fn_802031A8(void *,void *,void *); void fn_802031E8(void *,void *);
 void fn_802031CC(void *,void *,f32); void fn_80203184(void *,void *,void *);
 extern s32 lbl_8036A180; extern void *gGame; extern f32 lbl_8036A1AC;
 typedef void (*GetPosFn)(Vec3f *,void *,s32);
 typedef u8 (*BusyFn)(void *);
 typedef void (*SetFn)(void *,f32,f32,f32);
 typedef void (*AddFn)(void *,void *);
 Vec3f pos;
 String name;
 Vec3f oldPos;
 String a,b;
 Vec3f p,copyLook,look,copyPos;
 String effect;
 Vec3f discarded,origin,other1,other2,footp,foot,current;
 Vec3f b1,a1,cb1,ca1,pb1,pa1;
 Vec3f b2,a2,cb2,ca2,pb2,pa2;
 void *node;
 s32 compare;
 s32 length;
 f32 radius, distance, separation;
 pos.z=lbl_8036A184; pos.y=lbl_8036A184; pos.x=lbl_8036A184;
 fn_800E5DEC(self);
 fn_800DBAB8(&oldPos,self);
 if(!Actor_IsBusy(self) && M2C_FIELD(self,u8 *,0x1B5)) {
   fn_800DF664(self);
   if(M2C_FIELD(self,void **,0x11C)) fn_800DF664(M2C_FIELD(self,void **,0x11C));
   f32 zero=lbl_8036A184;
   f32 scale=fActorDefaultRadius;
   M2C_FIELD(self,u8 *,0x1B5)=0;
   ((ActorUpdateInterface *)self)->SetScale(zero,scale,zero);
 }
 if(!Actor_IsBusy(self) && (length=strlen((char *)gActorXmlStrs+0x1C), String_Compare((u8 *)self+0x16C,0,M2C_FIELD(self,void **,0x16C),(char *)gActorXmlStrs+0x1C,length))) {
   if(!(length=strlen((char *)gActorXmlStrs+0x43F), String_Compare((u8 *)self+0x16C,0,M2C_FIELD(self,void **,0x16C),(char *)gActorXmlStrs+0x43F,length))) {
     M2C_FIELD(self,u8 *,0x184)=1;
     Actor_LoadAnim(self,String_CStr((u8 *)self+0x16C),M2C_FIELD(self,s32 *,0x190),1,1);
     String_Assign((u8 *)self+0x160,(u8 *)self+0x16C,0,-1);
     String_AssignCStr((u8 *)self+0x16C,(char *)gActorXmlStrs+0x1C,strlen((char *)gActorXmlStrs+0x1C));
   } else {
     M2C_FIELD(self,u8 *,0x184)=1;
     Actor_LoadAnim(self,String_CStr((u8 *)self+0x16C),M2C_FIELD(self,s32 *,0x188),0,1);
     String_AssignCStr((u8 *)self+0x16C,(char *)gActorXmlStrs+0x43F,strlen((char *)gActorXmlStrs+0x43F));
   }
   M2C_FIELD(self,u8 *,0x1A8)=0;
 }
 fn_80110228(self);
 if(M2C_FIELD(self,void **,0x11C) && fn_80199310(M2C_FIELD(self,void **,0x11C))!=4) {
   s32 event;
   switch(fn_80199310(M2C_FIELD(self,void **,0x11C))) {
   case 0:event=20;break; case 1:case 6:event=21;break; case 2:case 7:event=22;break;case 3:event=23;break;default:event=20;break;
   }
   if(fn_800E5248(self,event)) fn_80198FB0(M2C_FIELD(self,void **,0x11C));
   if(fn_800E5248(self,25)) Actor_ClearNodeLink(M2C_FIELD(self,void **,0x11C));
   if(M2C_FIELD(self,void **,0x120)) {
     if(fn_800E5248(self,24)) fn_80198FB0(M2C_FIELD(self,void **,0x120));
     if(fn_800E5248(self,25)) Actor_ClearNodeLink(M2C_FIELD(self,void **,0x120));
   }
 } else if(M2C_FIELD(self,void **,0x11C) && fn_80199310(M2C_FIELD(self,void **,0x11C))==4) {
   if(fn_800E5248(self,24)) {
     void *p=Actor_SetNodeLink(self,(char *)gActorXmlStrs+0x549,(char *)gActorXmlStrs+0x54D,0);
     if(p) { s32 param=lbl_8036A180; GActor_SetNodeLinkParam(p,&param); }
   }
   if(fn_800E5248(self,25)) Actor_ClearNodeLink(self);
 }
 name.cap=0;name.size=0;name.data=0;name.cap=0;
 if(M2C_FIELD(self,s32 *,0x14C)>0) --M2C_FIELD(self,s32 *,0x14C);
 if(M2C_FIELD(self,s32 *,0x14C)==0) {
   if(M2C_FIELD(self,s32 *,0x148)==99) {
     String_AssignCStr(&name,(char *)gActorXmlStrs+0x551,strlen((char *)gActorXmlStrs+0x551));
   } else {
     if(M2C_FIELD(self,s32 *,0x148)!=0) String_AssignCStr(&name,(char *)gActorXmlStrs+0x55E,strlen((char *)gActorXmlStrs+0x55E));
     else String_AssignCStr(&name,(char *)gActorXmlStrs+0x551,strlen((char *)gActorXmlStrs+0x551));
     node=M2C_FIELD(M2C_FIELD(self,void **,0x118),void **,0x11C);
     if(node) {
       fn_80198F8C(&a,node);
       length=strlen((char *)gActorXmlStrs+0x1C);
       compare=String_Compare(&a,0,(void *)a.size,(char *)gActorXmlStrs+0x1C,length);
       String_Destroy(&a,-1);
       if(compare && (fn_801992F0(node)==1 || M2C_FIELD(self,s32 *,0x1B8)==1)) {
         fn_80198F8C(&b,node); String_Assign(&name,&b,0,-1); String_Destroy(&b,-1);
       }
     }
   }
   {
     void *effectNode;
     s8 initialized;
     ((GetPosFn)M2C_FIELD(M2C_FIELD(self,void **,0x40),void **,0x38))(&p,self,0);
     pos.y=p.y;pos.x=p.x;pos.z=p.z;pos.y=lbl_8036A184;initialized=0;
     effectNode=Heap_Alloc(0xC8);
     if(effectNode) {
       u8 allocator;
       Camera_GetLookAt(&look,self);ActorUpdate_CopyVector(&copyLook,&look);ActorUpdate_CopyVector(&copyPos,&pos);
       String_Init(&effect,(char *)gActorXmlStrs+0x51,&allocator);
       initialized=1;
       effectNode=fn_80151D50(effectNode,M2C_FIELD(self,void **,0xAC),&effect,&name,&copyPos,&copyLook,0);
     }
     ((ActorUpdateSceneInterface *)M2C_FIELD(self,void **,0xAC))->Add(effectNode);
     if(initialized) String_Destroy(&effect,-1);
   }
   M2C_FIELD(self,s32 *,0x14C)=-1;
 }
 if(M2C_FIELD(self,u8 *,0x195) && !((ActorUpdateInterface *)self)->IsBusy()) {
   M2C_FIELD(self,u8 *,0xD1)=0;M2C_FIELD(self,u8 *,0x195)=0;
 }
 {
   
   origin.z=lbl_8036A184;origin.y=lbl_8036A184;origin.x=lbl_8036A184;
   radius=M2C_FIELD(gGame,f32 *,0xD8);
   current.x=M2C_FIELD(self,f32 *,0x48);current.y=lbl_8036A184;current.z=M2C_FIELD(self,f32 *,0x50);
   if(PSVECDistance(origin,current)>radius) {
     fn_802031A8(&current,&origin,&current);fn_802031E8(&current,&current);fn_802031CC(&current,&current,radius);fn_80203184(&origin,&current,&current);
     M2C_FIELD(self,f32 *,0x48)=current.x;M2C_FIELD(self,f32 *,0x50)=current.z;
   }
 }
 if(!((ActorUpdateInterface *)self)->IsBusy() && M2C_FIELD(self,u8 *,0x1A8)) {
   node=M2C_FIELD(self,void **,0x118);
   if(!node) distance=lbl_8036A184;
   else {
     
     pa1.z=lbl_8036A184;pa1.y=lbl_8036A184;pa1.x=lbl_8036A184;pb1.z=lbl_8036A184;pb1.y=lbl_8036A184;pb1.x=lbl_8036A184;
     ((GetPosFn)M2C_FIELD(M2C_FIELD(self,void **,0x40),void **,0x38))(&a1,self,0);
     ca1=a1;pa1=a1;
     ((GetPosFn)M2C_FIELD(M2C_FIELD(node,void **,0x40),void **,0x38))(&b1,node,0);
     pb1=b1;cb1=b1;distance=PSVECDistance(ca1,cb1);
   }
   separation=lbl_8036A1AC*M2C_FIELD(self,f32 *,0x128);
   if(distance<separation) {
     radius=separation-distance;
     ((GetPosFn)M2C_FIELD(M2C_FIELD(M2C_FIELD(self,void **,0x118),void **,0x40),void **,0x38))(&other1,M2C_FIELD(self,void **,0x118),0);
     if(M2C_FIELD(self,f32 *,0x48)<other1.x) M2C_FIELD(self,f32 *,0x48)-=radius;
     else M2C_FIELD(self,f32 *,0x48)+=radius;
   }
 }
 else if(!Str_Cmp(String_CStr((u8 *)self+0x160),(char *)gActorXmlStrs+0x535) || !Str_Cmp(String_CStr((u8 *)self+0x160),(char *)gActorXmlStrs+0xFE)) {
   node=M2C_FIELD(self,void **,0x118);
   if(!node) distance=lbl_8036A184;
   else {
     
     pa2.z=lbl_8036A184;pa2.y=lbl_8036A184;pa2.x=lbl_8036A184;pb2.z=lbl_8036A184;pb2.y=lbl_8036A184;pb2.x=lbl_8036A184;
     ((GetPosFn)M2C_FIELD(M2C_FIELD(self,void **,0x40),void **,0x38))(&a2,self,0);
     ca2=a2;pa2=a2;
     ((GetPosFn)M2C_FIELD(M2C_FIELD(node,void **,0x40),void **,0x38))(&b2,node,0);
     pb2=b2;cb2=b2;distance=PSVECDistance(ca2,cb2);
   }
   separation=lbl_8036A1AC*M2C_FIELD(self,f32 *,0x128);
   if(distance<separation) {
     radius=separation-distance;
     ((GetPosFn)M2C_FIELD(M2C_FIELD(M2C_FIELD(self,void **,0x118),void **,0x40),void **,0x38))(&other2,M2C_FIELD(self,void **,0x118),0);
     if(M2C_FIELD(self,f32 *,0x48)<other2.x) M2C_FIELD(self,f32 *,0x48)-=radius;
     else M2C_FIELD(self,f32 *,0x48)+=radius;
   }
 }
 {
 
 foot.z=lbl_8036A184;foot.y=lbl_8036A184;foot.x=lbl_8036A184;
 if(fn_800E5248(self,50)) {
 ((GetPosFn)M2C_FIELD(M2C_FIELD(self,void **,0x40),void **,0x38))(&footp,self,0);
 foot=footp;fn_80111C8C(self,&foot);
 }
 }
 if(!(length=strlen((char *)gActorXmlStrs+0x56E), String_Compare((u8 *)self+0xB0,0,M2C_FIELD(self,void **,0xB0),(char *)gActorXmlStrs+0x56E,length))) {
 ((GetPosFn)M2C_FIELD(M2C_FIELD(self,void **,0x40),void **,0x38))(&discarded,self,0);
 }
 String_Destroy(&name,-1);
}
#pragma optimization_level reset
#pragma global_optimizer reset
#pragma cplusplus off

void *fn_801179DC(void *arg0, s16 arg1) {
    void BinTree_Destroy(void *, void *);
    void String_Destroy(void *, s32);
    void Actor_Dtor(void *, s32);
    void Heap_Free(void *);
    extern u16 lbl_8028F6C8[];
    u8 *p;

    if (arg0 != NULL) {
        p = (u8 *)arg0;
        *(void **)(p + 0x40) = lbl_8028F6C8;
        if (p + 0x1BC)
            if (p + 0x1BC)
                if (*(void **)(p + 0x1C0))
                    BinTree_Destroy(p + 0x1BC, *(void **)(p + 0x1C0));
        String_Destroy(p + 0x178, -1);
        String_Destroy(p + 0x16C, -1);
        String_Destroy(p + 0x160, -1);
        String_Destroy(p + 0x154, -1);
        Actor_Dtor(arg0, 0);
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

#pragma global_optimizer off
void *fn_80117A94(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s8 arg5)
{
    String sp24;
    String sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 a3;
    s32 a4;
    s8 a5;

    String_Init(&sp24, (char *)gActorXmlStrs + 0x573, &sp14);
    String_Init(&sp18, (char *)gActorXmlStrs + 0x579, &sp10);
    a3 = arg3;
    a4 = arg4;
    a5 = arg5;
    fn_800E6418(arg0, arg1, &sp24, arg2, a3, &sp18);
    String_Destroy(&sp18, -1);
    String_Destroy(&sp24, -1);

    {
        u8 *self = (u8 *)arg0;
        f32 fv1B0;
        f32 fv128;
        f32 fv124;

        *(void **)(self + 0x40) = lbl_8028F6C8;

        *(u32 *)(self + 0x154) = 0;
        *(u32 *)(self + 0x158) = 0;
        *(u32 *)(self + 0x15C) = 0;
        *(u32 *)(self + 0x158) = 0;
        *(u32 *)(self + 0x160) = 0;
        *(u32 *)(self + 0x164) = 0;
        *(u32 *)(self + 0x168) = 0;
        *(u32 *)(self + 0x164) = 0;
        *(u32 *)(self + 0x16C) = 0;
        *(u32 *)(self + 0x170) = 0;
        *(u32 *)(self + 0x174) = 0;
        *(u32 *)(self + 0x170) = 0;
        *(u32 *)(self + 0x178) = 0;
        *(u32 *)(self + 0x17C) = 0;
        *(u32 *)(self + 0x180) = 0;
        *(u32 *)(self + 0x17C) = 0;

        fn_800D6878(self + 0x1BC, &sp8, &spC);

        *(s32 *)(self + 0x118) = 0;
        fv124 = lbl_8036A1DC;
        *(s32 *)(self + 0x11C) = 0;
        fv128 = fActorDefaultRadius;
        *(s32 *)(self + 0x120) = 0;
        fv1B0 = lbl_8036A1C8;
        *(f32 *)(self + 0x124) = fv124;
        *(f32 *)(self + 0x128) = fv128;
        *(s32 *)(self + 0x12C) = 0;
        *(s32 *)(self + 0x130) = 0;
        *(s32 *)(self + 0x134) = 0;
        *(s32 *)(self + 0x138) = 0;
        *(s32 *)(self + 0x13C) = 0;
        *(s32 *)(self + 0x140) = 0;
        *(s32 *)(self + 0x14C) = -1;
        *(s32 *)(self + 0x148) = 0;
        self[0x184] = 0;
        self[0x194] = 0;
        self[0x195] = 0;
        *(s32 *)(self + 0x198) = 1;
        *(s32 *)(self + 0x19C) = 0;
        self[0x1A0] = 0;
        self[0x1A1] = 0;
        self[0x1A2] = a5;
        self[0x1A3] = a5;
        self[0x1A4] = 0;
        self[0x1A5] = 0;
        self[0x1A6] = 0;
        self[0x1A7] = 0;
        self[0x1A8] = 0;
        *(s32 *)(self + 0x1AC) = a4;
        *(f32 *)(self + 0x1B0) = fv1B0;
        self[0x1B4] = 0;
        self[0x1B5] = 0;
        self[0x1B6] = 0;
        *(s32 *)(self + 0x1B8) = 1;

        String_AssignCStr(self + 0x154, (char *)gActorXmlStrs + 0x581, strlen((char *)gActorXmlStrs + 0x581));
        String_AssignCStr(self + 0x160, (char *)gActorXmlStrs + 0x1C, strlen((char *)gActorXmlStrs + 0x1C));
        String_AssignCStr(self + 0x16C, (char *)gActorXmlStrs + 0x1C, strlen((char *)gActorXmlStrs + 0x1C));

        self[0x1D7] = 1;
        self[0x1D6] = 1;
        self[0x1D5] = 1;
        self[0x1D4] = 1;
        return self;
    }
}
#pragma global_optimizer reset

s32 fn_80117CC0(void *arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 8) + arg1;
}

void fn_80117CCC(void) {
    void fn_8014C798(void *);
    void fn_800163F8(void);
    void fn_80016180(void);
    void *Unit_FindByName(void *);
    void Unit_FocusCamera(void *, s32);
    void Camera_SyncFromBattleState(void);
    extern s32 gBattleState[];
    extern u8 lbl_80274508[];
    void *temp_r3;

    fn_8014C798(gBattleState);
    fn_800163F8();
    fn_80016180();
    temp_r3 = Unit_FindByName(lbl_80274508 + 0x130);
    if (temp_r3 != 0) {
        Unit_FocusCamera(temp_r3, 0);
        Camera_SyncFromBattleState();
    }
}

void fn_80117D20(s32 arg0) {
    void BattleState_LoadMap(void *, s32);
    void ScriptCtx_Begin(void *);
    void ScriptCtx_Call(void);
    void Event_StartByName(void *, s32);
    extern s32 gBattleState[];
    extern u8 lbl_80274508[];

    BattleState_LoadMap(gBattleState, 0);
    ScriptCtx_Begin(lbl_80274508 + 0x138);
    ScriptCtx_Call();
    Event_StartByName(lbl_80274508 + 0x150, arg0);
}

#pragma use_lmw_stmw on
s32 fn_80117D80(void *arg0, void *unit) {
    void Map_RefreshUnitMap(void *);
    void fn_800C1060(s32);
    void *TargetList_GetAt(void *, s32);
    void Unit_SetMapPos(void *, u8, u8);
    void fn_80050C90(void *);
    extern u8 gBattleMap[];
    extern u8 gMapBlendMode;
    extern u8 gTargetList[];
    s32 result;
    u32 flags;
    s32 var_r4;
    s32 temp;
    s32 i;
    u8 *tgt;
    s8 x;
    s8 y;

    result = 0;
    flags = *(u32 *)((u8 *)unit + 0x1A0);
    if ((flags & 0x010000DC) == 0) {
        if ((flags & 0x10000) != 0) {
            return 0;
        }
        *(u32 *)((u8 *)unit + 0x1A0) = flags | 0x010000DC;
        Map_RefreshUnitMap(gBattleMap);
#pragma optimization_level 1
        var_r4 = 1;
        temp = (u8)(gMapBlendMode - 1);
        if (((u32)((var_r4 | ~temp) - ((u32)(var_r4 - temp) >> 1)) >> 31) == 0) {
            var_r4 = 0;
        }
#pragma optimization_level reset
        if ((u8)var_r4 != 0) {
            fn_800C1060(0);
        }
        result = 1;
    } else if ((flags & 0x00200000) != 0) {
        return 0;
    } else {
        for (i = 0; i < *(s32 *)gTargetList; i++) {
            tgt = (u8 *)TargetList_GetAt(gTargetList, i);
            x = (s8)tgt[0];
            y = (s8)tgt[1];
            if (*(u8 *)(gBattleMap + x + (y << 6) + 0xD) == 0) {
                *(u32 *)((u8 *)unit + 0x1A0) &= ~0x010000DCU;
                Unit_SetMapPos(unit, tgt[0], tgt[1]);
                fn_80050C90(unit);
                Map_RefreshUnitMap(gBattleMap);
#pragma optimization_level 1
                var_r4 = 1;
                temp = (u8)(gMapBlendMode - 1);
                if (((u32)((var_r4 | ~temp) - ((u32)(var_r4 - temp) >> 1)) >> 31) == 0) {
                    var_r4 = 0;
                }
#pragma optimization_level reset
                if ((u8)var_r4 != 0) {
                    fn_800C1060(0);
                }
                result = 1;
                break;
            }
        }
    }
    return result;
}
void fn_80117F1C(void *arg0) {
    M2C_UNK Process_Goto(void *, u8);
    M2C_UNK Ui_DecBusy();
    Ui_DecBusy();
    Process_Goto(arg0, M2C_FIELD(arg0, u8 *, 0x48));
}

void fn_80117F54(s32 arg0) {
    extern s32 gUiContext[];
    
    void fn_8013FED0(void);
    void fn_8007D064(s32, s32, s32);

    fn_8013FED0();
    fn_8007D064(gUiContext[0], arg0, 0);
}

void fn_80117F98(void *arg0) {
    typedef struct {
        void *unk0;
        s32 unk4;
        s16 unk8;
        s16 unkA;
        s16 unkC;
        s16 unkE;
        s16 unk10;
        s16 unk12;
        s16 unk14;
        s16 unk16;
        s16 unk18;
        s16 unk1A;
        s16 unk1C;
        u8 unk1E;
        u8 unk1F;
        u8 unk20;
        u8 unk21;
        s16 unk22;
        s16 unk24;
        f32 unk28;
        f32 unk2C;
        f32 unk30;
        s32 unk34;
        s32 unk38;
        s32 unk3C;
        s32 unk40;
        s32 unk44;
        s32 unk48;
        u8 unk4C;
        u8 pad4D;
        s16 unk4E;
        s16 unk50;
        s16 unk52;
        s16 unk54;
        s32 unk58;
    } Unk5C;
    void *Heap_Alloc(s32);
    void String_AssignCStr(void *, char *, s32);
    s32 strlen(char *);
    void Ui_AddChild(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Process_RetreatStep(void *);
    void Process_ClearFunc(void *);
    void Process_Goto(void *, s32);
    void fn_8011ACFC(void);
    extern u8 gUiContext[];
    extern u8 lbl_80293C84[];
    extern u8 lbl_80293C58[];
    extern u8 lbl_80274508[];
    Unk5C *temp_r3;
    Unk5C *found;
    s32 len;

    switch (gUiContext[8]) {
    case 0x81:
        Process_Goto(arg0, 0x13);
        break;
    default:
        Process_RetreatStep(*(void **)((u8 *)arg0 + 0x44));
        temp_r3 = (Unk5C *)Heap_Alloc(0x5C);
        if (temp_r3) {
            temp_r3->unk0 = lbl_8028FDB0;
            temp_r3->unk4 = 0;
            temp_r3->unk0 = lbl_80292230;
            temp_r3->unk8 = -1;
            temp_r3->unkA = 0;
            temp_r3->unkC = 0x190;
            temp_r3->unkE = 0x260;
            temp_r3->unk10 = 0x1C0;
            temp_r3->unk12 = 0;
            temp_r3->unk14 = 0;
            temp_r3->unk16 = 0x260;
            temp_r3->unk18 = 0x30;
            temp_r3->unk1A = 0;
            temp_r3->unk1C = 0;
            temp_r3->unk1E = 0xFF;
            temp_r3->unk1F = 0xFF;
            temp_r3->unk20 = 0xFF;
            temp_r3->unk21 = 0xFF;
            temp_r3->unk22 = 0x316;
            temp_r3->unk24 = 0;
            temp_r3->unk28 = 1.0f;
            temp_r3->unk2C = 1.0f;
            temp_r3->unk30 = 1.0f;
            temp_r3->unk34 = 0;
            temp_r3->unk38 = 0;
            temp_r3->unk0 = lbl_80293C84;
            temp_r3->unk3C = 0;
            temp_r3->unk40 = 0;
            temp_r3->unk44 = 0;
            temp_r3->unk40 = 0;
            temp_r3->unk48 = 0;
            temp_r3->unk4C = 1;
            temp_r3->unk4E = 0;
            temp_r3->unk50 = 0;
            temp_r3->unk52 = 0;
            temp_r3->unk54 = 0;
            temp_r3->unk0 = lbl_80293C58;
            temp_r3->unk58 = 1;
            temp_r3->unk4E = 0x30;
            temp_r3->unk52 = 0x30;
        }
        temp_r3->unk8 = -0x1000;
        temp_r3->unk48 = 1;
        len = strlen((char *)lbl_80274508 + 0x161);
        String_AssignCStr(&temp_r3->unk3C, (char *)(lbl_80274508 + 353), len);
        temp_r3->unk34 |= 0x10;
        temp_r3->unk58 = 1;
        Ui_AddChild(arg0, temp_r3);
        found = (Unk5C *)Ui_FindChild(arg0, -0x1000, 0);
        if (found) {
            found->unk58 = 0;
        }
        fn_8011ACFC();
        Process_ClearFunc(arg0);
        break;
    }
}

void fn_80118170(void *arg0) {
    void fn_8012C7C8(void *, void *);
    void Process_AdvanceStep(s32);
    s32 Ui_FindChild(void *, s32, s32);
    void Ui_RemoveChild(void *, s32);
    void fn_80117D80(void);
    s32 tmp;

    fn_8012C7C8((void *)fn_80117D80, arg0);
    Process_AdvanceStep(*(s32 *)((u8 *)arg0 + 0x44));
    tmp = Ui_FindChild(arg0, -0x1000, 0);
    if (tmp != 0) {
        Ui_RemoveChild(arg0, tmp);
    }
}

void fn_801181D0(void) {
    M2C_UNK fn_80006198();
    M2C_UNK Game_SetState(M2C_UNK);
    Game_SetState(0xE);
    fn_80006198();
}

void fn_801181F8(s32 arg0) {
    extern u8 gUiContext[];
    switch ((s32)gUiContext[8]) {
    case 0x81:
        Process_Goto(arg0, 0x12);
        return;
    case 0x80:
        Process_Goto(arg0, 1);
        return;
    }
}

void fn_8011824C(s32 arg0) {
    void Msg_Expand(void *);
    void Ui_CreateMenu(void *, s32, s32);
    void *fn_8013BFFC(void);
    extern char lbl_80274508[];
    void *tmp;

    Msg_Expand(lbl_80274508 + 0x162);
    tmp = fn_8013BFFC();
    *((u8 *)tmp + 0x24) = 1;
    Ui_CreateMenu(tmp, arg0, 0);
}

void fn_8011829C(void *arg0) {
    void EventLock_Dec(void);
    void Process_Goto(void *, s32);
    extern u8 gUiContext[];

    EventLock_Dec();
    switch ((s32)gUiContext[8]) {
    case 0x81:
        Process_Goto(arg0, 0x13);
        return;
    case 0x80:
        Process_Goto(arg0, *(u8 *)((u8 *)arg0 + 0x48));
        return;
    }
}

void fn_80118308(s32 arg0) {
    void Msg_Expand(void *);
    void EventLock_Inc(void);
    void Ui_CreateMenu(void *, s32, s32);
    void fn_8011A2FC(void);
    void *fn_8013BFFC(void);
    u32 Ui_FindChild(s32, s32, s32);
    void Ui_SetWidgetText(u32, void *);
    extern char lbl_80274508[];
    void *tmp;
    u32 result;

    fn_8011A2FC();
    EventLock_Inc();
    Msg_Expand(lbl_80274508 + 0x17C);
    tmp = fn_8013BFFC();
    *((u8 *)tmp + 0x24) = 1;
    Ui_CreateMenu(tmp, arg0, 0);
    result = Ui_FindChild(arg0, -0x1000, 0);
    if (result != 0) {
        Ui_SetWidgetText(result, lbl_80274508 + 0x194);
    }
}

void fn_80118388(s32 arg0) {
    M2C_UNK Process_ClearFunc(s32);
    M2C_UNK fn_800A8400();
    Ui_DecBusy();
    fn_800A8400();
    Process_ClearFunc(arg0);
}

void fn_801183C0(s32 arg0) {
    void fn_8013FED0(s32);
    void fn_801D3B14(s32);
    extern s32 gBattleState[];

    fn_8013FED0(arg0);
    *((u8 *)gBattleState + 0x54) = 2;
    fn_801D3B14(arg0);
}

void fn_80118404(s32 arg0) {
    Ui_DecBusy();
    fn_800A8400();
    Process_ClearFunc(arg0);
}

void fn_8011843C(s32 arg0) {
    M2C_UNK fn_8013FED0();
    M2C_UNK fn_801AA120(s32);
    fn_8013FED0();
    fn_801AA120(arg0);
}

void fn_80118470(s32 arg0) {
    Ui_DecBusy();
    fn_800A8400();
    Process_ClearFunc(arg0);
}

void fn_801184A8(s32 arg0) {
    M2C_UNK fn_8016B730(s32);
    fn_8013FED0();
    fn_8016B730(arg0);
}

void fn_801184DC(void *arg0) {
    typedef struct {
        void *unk0;
        s32 unk4;
        s16 unk8;
        s16 unkA;
        s16 unkC;
        s16 unkE;
        s16 unk10;
        s16 unk12;
        s16 unk14;
        s16 unk16;
        s16 unk18;
        s16 unk1A;
        s16 unk1C;
        u8 unk1E;
        u8 unk1F;
        u8 unk20;
        u8 unk21;
        s16 unk22;
        s16 unk24;
        f32 unk28;
        f32 unk2C;
        f32 unk30;
        s32 unk34;
        s32 unk38;
        s32 unk3C;
        s32 unk40;
        s32 unk44;
        s32 unk48;
        u8 unk4C;
        u8 pad4D;
        s16 unk4E;
        s16 unk50;
        s16 unk52;
        s16 unk54;
        s32 unk58;
    } Unk5C;
    void *Heap_Alloc(s32);
    void String_AssignCStr(void *, char *, s32);
    s32 strlen(char *);
    void Ui_AddChild(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Process_RetreatStep(void *);
    void Process_ClearFunc(void *);
    extern u8 lbl_80293C84[];
    extern u8 lbl_80293C58[];
    extern u8 lbl_80274508[];
    Unk5C *temp_r3;
    Unk5C *found;
    s32 len;

    temp_r3 = (Unk5C *)Heap_Alloc(0x5C);
    if (temp_r3) {
        temp_r3->unk0 = lbl_8028FDB0;
        temp_r3->unk4 = 0;
        temp_r3->unk0 = lbl_80292230;
        temp_r3->unk8 = -1;
        temp_r3->unkA = 0;
        temp_r3->unkC = 0x190;
        temp_r3->unkE = 0x260;
        temp_r3->unk10 = 0x1C0;
        temp_r3->unk12 = 0;
        temp_r3->unk14 = 0;
        temp_r3->unk16 = 0x260;
        temp_r3->unk18 = 0x30;
        temp_r3->unk1A = 0;
        temp_r3->unk1C = 0;
        temp_r3->unk1E = 0xFF;
        temp_r3->unk1F = 0xFF;
        temp_r3->unk20 = 0xFF;
        temp_r3->unk21 = 0xFF;
        temp_r3->unk22 = 0x316;
        temp_r3->unk24 = 0;
        temp_r3->unk28 = 1.0f;
        temp_r3->unk2C = 1.0f;
        temp_r3->unk30 = 1.0f;
        temp_r3->unk34 = 0;
        temp_r3->unk38 = 0;
        temp_r3->unk0 = lbl_80293C84;
        temp_r3->unk3C = 0;
        temp_r3->unk40 = 0;
        temp_r3->unk44 = 0;
        temp_r3->unk40 = 0;
        temp_r3->unk48 = 0;
        temp_r3->unk4C = 1;
        temp_r3->unk4E = 0;
        temp_r3->unk50 = 0;
        temp_r3->unk52 = 0;
        temp_r3->unk54 = 0;
        temp_r3->unk0 = lbl_80293C58;
        temp_r3->unk58 = 1;
        temp_r3->unk4E = 0x30;
        temp_r3->unk52 = 0x30;
    }
    temp_r3->unk8 = -0x1000;
    temp_r3->unk48 = 1;
    len = strlen((char *)lbl_80274508 + 0x161);
    String_AssignCStr(&temp_r3->unk3C, (char *)(lbl_80274508 + 353), len);
    temp_r3->unk34 |= 0x10;
    temp_r3->unk58 = 1;
    Ui_AddChild(arg0, temp_r3);
    found = (Unk5C *)Ui_FindChild(arg0, -0x1000, 0);
    if (found) {
        found->unk58 = 0;
    }
    Process_RetreatStep(*(void **)((u8 *)arg0 + 0x44));
    Process_ClearFunc(arg0);
}

void fn_8011868C(void *arg0) {
    M2C_UNK Process_AdvanceStep(s32);
    s32 Ui_FindChild(void *, M2C_UNK, M2C_UNK);
    M2C_UNK Ui_RemoveChild(void *, s32);
    M2C_UNK fn_8016E9DC(void *);
    s32 tmp;

    Process_AdvanceStep(M2C_FIELD(arg0, s32 *, 0x44));
    tmp = Ui_FindChild(arg0, -0x1000, 0);
    if (tmp != 0) {
        Ui_RemoveChild(arg0, tmp);
    }
    fn_8016E9DC(arg0);
}

void fn_801186E4(void *arg0)
{
    void Process_Goto(void *, s32);
    u8 Allegiance_CompareIds(s32, u8);
    void Map_RefreshUnitMap(u8 *);
    void UiCtx_BindUnit(u8 *, void *);
    void Map_HideMoveLimitView(void);
    void Map_ShowMoveLimitView(void);
    void fn_800A8400(void);
    void *Map_GetCursorUnit(void);
    void Map_SetupUnitMoveLimit(void *);
    u32 Ui_FindChild(void *, s32, s32);
    void Ui_PlaySeCue(u8 *, s32);
    void Ui_SetWidgetText(u32, u8 *);
    extern u8 lbl_80274508[];
    extern u8 gUnitLists[];
    extern u8 gBattleMap[];
    extern u8 gUiContext[];
    extern s32 gUiInputFlags;
    extern void *gPadInput;
    extern void *lbl_803679F0;
    extern s8 lbl_803679F4;
    void *unit;
    void *unit2;
    u8 flag;
    u8 skip;
    u32 buttons;
    void *iter;
    u32 flags;
    u32 ret;
    void *self;

    self = arg0;
    unit = Map_GetCursorUnit();
    if (unit != NULL) {
        if (Allegiance_CompareIds(0, *(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)) == 1) {
            if (!(*(u32 *)((u8 *)unit + 0x1A0) & 0x800)) {
                ret = Ui_FindChild(self, -0x1000, 0);
                if (ret != 0) {
                    Ui_SetWidgetText(ret, lbl_80274508 + 0x1A7);
                }
            } else {
                ret = Ui_FindChild(self, -0x1000, 0);
                if (ret != 0) {
                    Ui_SetWidgetText(ret, lbl_80274508 + 0x1B9);
                }
            }
        } else {
            ret = Ui_FindChild(self, -0x1000, 0);
            if (ret != 0) {
                Ui_SetWidgetText(ret, lbl_80274508 + 0x1CB);
            }
        }
    } else {
        flag = 0;
        iter = *(void **)(gUnitLists + 0xC);
        while (iter != NULL) {
            flags = *(u32 *)((u8 *)iter + 0x1A0);
            iter = *(void **)((u8 *)iter + 0x184);
            if (flags & 0x800) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            ret = Ui_FindChild(self, -0x1000, 0);
            if (ret != 0) {
                Ui_SetWidgetText(ret, lbl_80274508 + 0x1DD);
            }
        } else {
            ret = Ui_FindChild(self, -0x1000, 0);
            if (ret != 0) {
                Ui_SetWidgetText(ret, lbl_80274508 + 0x1EF);
            }
        }
    }
    if (lbl_803679F4 == 0) {
        lbl_803679F0 = NULL;
        lbl_803679F4 = 1;
    }
    unit2 = Map_GetCursorUnit();
    if (unit2 == NULL && (gUiInputFlags & 0x400)) {
        Map_HideMoveLimitView();
    }
    skip = 0;
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20)) {
        skip = 1;
    }
    if ((skip != 0) ||
        ((!( *(u32 *)((u8 *)gPadInput + 4) & 0xF)) &&
         ((s8)(*(u8 **)gPadInput)[2] == 0) &&
         ((s8)(*(u8 **)gPadInput)[3] == 0))) {
        if ((lbl_803679F0 != unit2) || !(gUiInputFlags & 0x400)) {
            lbl_803679F0 = unit2;
            if ((unit2 == NULL) || (*(u8 *)(*(u8 **)((u8 *)unit2 + 0x190) + 8) == 0)) {
                if (gUiInputFlags & 0x400) {
                    Map_HideMoveLimitView();
                }
            } else {
                Map_SetupUnitMoveLimit(unit2);
                Map_ShowMoveLimitView();
            }
        }
    }
    skip = 0;
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20)) {
        skip = 1;
    }
    if (skip == 0) {
        buttons = *(u32 *)((u8 *)gPadInput + 4);
        buttons = buttons & (*(u32 *)((u8 *)gPadInput + 8) ^ buttons);
        if ((unit != NULL) && (buttons & 0x800)) {
            fn_800A8400();
            if (gUiInputFlags & 0x400) {
                Map_HideMoveLimitView();
            }
            UiCtx_BindUnit(gUiContext, unit);
            Ui_PlaySeCue(lbl_80274508 + 0x201, 0x64);
            *((u8 *)self + 0x48) = 4;
            Process_Goto(self, 0x11);
            return;
        }
        if (buttons & 0x100) {
            if ((unit != NULL) && (Allegiance_CompareIds(0, *(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)) == 1)) {
                flags = *(u32 *)((u8 *)unit + 0x1A0);
                if (!(flags & 0x800)) {
                    *(u32 *)((u8 *)unit + 0x1A0) = flags | 0x800;
                    Map_RefreshUnitMap(gBattleMap);
                    Map_SetupUnitMoveLimit(unit);
                    Ui_PlaySeCue(lbl_80274508 + 0x211, 0x64);
                }
            } else {
                goto block_65;
            }
        } else if (buttons & 0x200) {
            if ((unit != NULL) && (Allegiance_CompareIds(0, *(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)) == 1)) {
                flags = *(u32 *)((u8 *)unit + 0x1A0);
                if (flags & 0x800) {
                    *(u32 *)((u8 *)unit + 0x1A0) = flags & ~0x800;
                    Map_RefreshUnitMap(gBattleMap);
                    Map_SetupUnitMoveLimit(unit);
                    Ui_PlaySeCue(lbl_80274508 + 0x22C, 0x64);
                }
            } else if (unit == NULL) {
                flag = 0;
                iter = *(void **)(gUnitLists + 0xC);
                while (iter != NULL) {
                    flags = *(u32 *)((u8 *)iter + 0x1A0);
                    if (flags & 0x800) {
                        flag = 1;
                        *(u32 *)((u8 *)iter + 0x1A0) = flags & ~0x800;
                    }
                    iter = *(void **)((u8 *)iter + 0x184);
                }
                if (flag != 0) {
                    Ui_PlaySeCue(lbl_80274508 + 0x22C, 0x64);
                    Map_RefreshUnitMap(gBattleMap);
                }
            }
        } else {
            if (buttons & 0x10) {
            block_65:
                if (gUiInputFlags & 0x400) {
                    Map_HideMoveLimitView();
                }
                Ui_PlaySeCue(lbl_80274508 + 0x247, 0x64);
                Process_Goto(self, 1);
                return;
            }
            if (buttons & 0x1000) {
                if (gUiInputFlags & 0x400) {
                    Map_HideMoveLimitView();
                }
                *((u8 *)self + 0x48) = 4;
                Process_Goto(self, 9);
            }
        }
    }
}

void fn_80118B7C(void *arg0) {
    void EventLock_Dec(void);
    void fn_800A8478(void);
    void fn_8018DB4C(void);
    void fn_8000C060(void *, void *);
    void Process_Goto(void *, s32);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_CloseChildAnim(void *, void *, s32);
    extern u8 gEventLockDepth;
    void *temp_r31;

    while (gEventLockDepth != 0) {
        EventLock_Dec();
    }
    fn_800A8478();
    fn_8018DB4C();
    temp_r31 = *(void **)((u8 *)arg0 + 0x44);
    fn_8000C060(temp_r31, 0);
    Process_Goto(temp_r31, 0);
    if (Ui_FindChild(arg0, 0x40, 0) != NULL) {
        Ui_CloseChildAnim(arg0, Ui_FindChild(arg0, 0x40, 0), 1);
    }
}

void fn_80118C1C(void) {
    void fn_800A6AE4(void);
    void fn_8002297C(void *);
    void fn_800C1060(s32);
    extern u8 lbl_802CA518[];
    extern u8 lbl_80367289;
    u8 flag;
    u8 temp;

    fn_800A6AE4();
    fn_8002297C(lbl_802CA518);
    flag = 1;
    temp = (u8)(lbl_80367289 - 1);
    if (((u32)((flag | ~temp) - ((u32)(flag - temp) >> 1)) >> 31) == 0) {
        flag = 0;
    }
    if (flag) {
        fn_800C1060(0);
    }
}

#pragma use_lmw_stmw on
void fn_80118C84(void *arg0) {
    void Process_Goto(void *, s32);
    void Process_ClearFunc(void *);
    void *Process_CreateChild(void *, void *);
    void *Process_Create(void *, s32);
    u8 Allegiance_CompareIds(s32, u8);
    void Map_RefreshUnitMap(u8 *);
    void UiCtx_BindUnit(u8 *, void *);
    void *TargetList_GetAt(void *, s32);
    void Map_HideMoveLimitView(void);
    void Map_ShowMoveLimitView(void);
    void fn_800A6AAC(void);
    void fn_800A8400(void);
    void *Map_GetCursorUnit(void);
    void Map_SetupUnitMoveLimit(void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_PlaySeCue(u8 *, s32);
    void BattleState_SetCamPos(void *, f32, f32);
    void Ui_SetWidgetText(void *, u8 *);
    extern u8 lbl_80274508[];
    extern u8 lbl_8028F7B8[];
    extern u8 gUnits[];
    extern u8 gUnitLists[];
    extern u8 gBattleMap[];
    extern u8 gUiContext[];
    extern u8 gTargetList[];
    extern s32 gBattleState[];
    extern s32 gUiInputFlags;
    extern void *gPadInput;
    extern void *lbl_803679F0;
    extern s8 lbl_803679F4;
    void *self;
    void *unit;
    void *other;
    void *unit2;
    void *iter;
    void *p;
    void *node;
    void *ret;
    u8 *map;
    u8 *ef;
    s8 cur_y;
    s8 cur_x;
    s32 sel_x;
    s32 sel_y;
    s32 idx;
    u8 id;
    u8 found;
    u8 flag;
    u8 skip;
    u32 buttons;
    u32 flags;
    s32 i;

    self = arg0;
    unit = Map_GetCursorUnit();
    ef = gUiContext;
    cur_y = (s8)ef[0xE];
    sel_x = (s32)*(f32 *)((u8 *)gBattleState + 0x524);
    sel_y = (s32)*(f32 *)((u8 *)gBattleState + 0x528);
    cur_x = (s8)ef[0xD];
    map = gBattleMap + 0xD;
    idx = cur_x + (cur_y << 6);
    id = map[idx];
    if (id != 0) {
        other = &gUnits[(id - 1) * 0x280];
    } else {
        other = NULL;
    }
    if (unit != NULL) {
        if (Allegiance_CompareIds(0, *(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)) == 1) {
            if (!(*(u32 *)((u8 *)unit + 0x1A0) & 0x800)) {
                ret = Ui_FindChild(self, -0x1000, 0);
                if (ret != NULL)
                    Ui_SetWidgetText(ret, lbl_80274508 + 0x1A7);
            } else {
                ret = Ui_FindChild(self, -0x1000, 0);
                if (ret != NULL)
                    Ui_SetWidgetText(ret, lbl_80274508 + 0x1B9);
            }
        } else if (other != unit) {
            found = 0;
            id = map[(s8)sel_x + ((s8)sel_y << 6)];
            if (id != 0) {
                p = &gUnits[(id - 1) * 0x280];
                if (*(u32 *)((u8 *)p + 0x1A0) & 0x20000) {
                    found = 0;
                } else {
                    goto search1;
                }
            } else {
            search1:
                for (i = 0; i < *(s32 *)gTargetList; i++) {
                    p = TargetList_GetAt(gTargetList, i);
                    if ((s8)sel_x == (s8)*(u8 *)p && (s8)sel_y == (s8)*((u8 *)p + 1)) {
                        found = 1;
                        break;
                    }
                }
            }
            if (found != 0) {
                ret = Ui_FindChild(self, -0x1000, 0);
                if (ret != NULL)
                    Ui_SetWidgetText(ret, lbl_80274508 + 0x257);
            } else {
                ret = Ui_FindChild(self, -0x1000, 0);
                if (ret != NULL)
                    Ui_SetWidgetText(ret, lbl_80274508 + 0x269);
            }
        } else {
            ret = Ui_FindChild(self, -0x1000, 0);
            if (ret != NULL)
                Ui_SetWidgetText(ret, lbl_80274508 + 0x27B);
        }
    } else {
        flag = 0;
        iter = *(void **)(gUnitLists + 0xC);
        while (iter != NULL) {
            flags = *(u32 *)((u8 *)iter + 0x1A0);
            iter = *(void **)((u8 *)iter + 0x184);
            if (flags & 0x800) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            ret = Ui_FindChild(self, -0x1000, 0);
            if (ret != NULL)
                Ui_SetWidgetText(ret, lbl_80274508 + 0x28D);
        } else {
            ret = Ui_FindChild(self, -0x1000, 0);
            if (ret != NULL)
                Ui_SetWidgetText(ret, lbl_80274508 + 0x1EF);
        }
    }
    if (lbl_803679F4 == 0) {
        lbl_803679F0 = NULL;
        lbl_803679F4 = 1;
    }
    unit2 = Map_GetCursorUnit();
    if (unit2 == NULL && (gUiInputFlags & 0x400))
        Map_HideMoveLimitView();
    skip = 0;
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20))
        skip = 1;
    if ((skip != 0) ||
        ((!(*(u32 *)((u8 *)gPadInput + 4) & 0xF)) &&
         ((s8)(*(u8 **)gPadInput)[2] == 0) &&
         ((s8)(*(u8 **)gPadInput)[3] == 0))) {
        if ((lbl_803679F0 != unit2) || !(gUiInputFlags & 0x400)) {
            lbl_803679F0 = unit2;
            if ((unit2 == NULL) || (*(u8 *)(*(u8 **)((u8 *)unit2 + 0x190) + 8) == 0)) {
                if (gUiInputFlags & 0x400)
                    Map_HideMoveLimitView();
            } else {
                Map_SetupUnitMoveLimit(unit2);
                Map_ShowMoveLimitView();
            }
        }
    }
    skip = 0;
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20))
        skip = 1;
    if (skip != 0)
        return;
    buttons = *(u32 *)((u8 *)gPadInput + 4);
    buttons = buttons & (*(u32 *)((u8 *)gPadInput + 8) ^ buttons);
    if ((unit != NULL) && (buttons & 0x800)) {
        fn_800A8400();
        if (gUiInputFlags & 0x400)
            Map_HideMoveLimitView();
        UiCtx_BindUnit(gUiContext, unit);
        ef[0xD] = (u8)cur_x;
        ef[0xE] = (u8)cur_y;
        Ui_PlaySeCue(lbl_80274508 + 0x201, 0x64);
        *((u8 *)self + 0x48) = 6;
        Process_Goto(self, 0x11);
        return;
    }
    if (buttons & 0x100) {
        if (unit != NULL) {
            found = 0;
            id = map[(s8)sel_x + ((s8)sel_y << 6)];
            if (id != 0) {
                p = &gUnits[(id - 1) * 0x280];
                if (*(u32 *)((u8 *)p + 0x1A0) & 0x20000) {
                    found = 0;
                } else {
                    goto search2;
                }
            } else {
            search2:
                for (i = 0; i < *(s32 *)gTargetList; i++) {
                    p = TargetList_GetAt(gTargetList, i);
                    if ((s8)sel_x == (s8)*(u8 *)p && (s8)sel_y == (s8)*((u8 *)p + 1)) {
                        found = 1;
                        break;
                    }
                }
            }
            if (found == 0) {
                if (Allegiance_CompareIds(0, *(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)) == 1) {
                    flags = *(u32 *)((u8 *)unit + 0x1A0);
                    if (!(flags & 0x800)) {
                        *(u32 *)((u8 *)unit + 0x1A0) = flags | 0x800;
                        Map_RefreshUnitMap(gBattleMap);
                        Map_SetupUnitMoveLimit(unit);
                        Ui_PlaySeCue(lbl_80274508 + 0x211, 0x64);
                    }
                } else {
                    Ui_PlaySeCue(lbl_80274508 + 0x29F, 0x64);
                }
                return;
            }
        }
        if ((s8)sel_x != cur_x || (s8)sel_y != cur_y) {
            found = 0;
            id = map[(s8)sel_x + ((s8)sel_y << 6)];
            if (id != 0) {
                p = &gUnits[(id - 1) * 0x280];
                if (*(u32 *)((u8 *)p + 0x1A0) & 0x20000) {
                    found = 0;
                } else {
                    goto search3;
                }
            } else {
            search3:
                for (i = 0; i < *(s32 *)gTargetList; i++) {
                    p = TargetList_GetAt(gTargetList, i);
                    if ((s8)sel_x == (s8)*(u8 *)p && (s8)sel_y == (s8)*((u8 *)p + 1)) {
                        found = 1;
                        break;
                    }
                }
            }
            if (found != 0) {
                fn_800A6AAC();
                if (gUiInputFlags & 0x400)
                    Map_HideMoveLimitView();
                id = map[idx];
                if (id != 0)
                    other = &gUnits[(id - 1) * 0x280];
                else
                    other = NULL;
                if (other != NULL) {
                    if (self != NULL)
                        node = Process_CreateChild(lbl_8028F7B8, self);
                    else
                        node = Process_Create(lbl_8028F7B8, 4);
                    *(void **)((u8 *)node + 0x30) = other;
                    *((u8 *)node + 0x58) = (u8)sel_x;
                    *((u8 *)node + 0x59) = (u8)sel_y;
                }
                if (unit != NULL) {
                    if (self != NULL)
                        node = Process_CreateChild(lbl_8028F7B8, self);
                    else
                        node = Process_Create(lbl_8028F7B8, 4);
                    *(void **)((u8 *)node + 0x30) = unit;
                    *((u8 *)node + 0x58) = (u8)cur_x;
                    *((u8 *)node + 0x59) = (u8)cur_y;
                }
                Ui_PlaySeCue(lbl_80274508 + 0x2AD, 0x64);
                Process_ClearFunc(self);
                return;
            }
        }
        goto cancel;
    } else if (buttons & 0x200) {
        if (unit != NULL) {
            found = 0;
            id = map[(s8)sel_x + ((s8)sel_y << 6)];
            if (id != 0) {
                p = &gUnits[(id - 1) * 0x280];
                if (*(u32 *)((u8 *)p + 0x1A0) & 0x20000) {
                    found = 0;
                } else {
                    goto search4;
                }
            } else {
            search4:
                for (i = 0; i < *(s32 *)gTargetList; i++) {
                    p = TargetList_GetAt(gTargetList, i);
                    if ((s8)sel_x == (s8)*(u8 *)p && (s8)sel_y == (s8)*((u8 *)p + 1)) {
                        found = 1;
                        break;
                    }
                }
            }
            if (found == 0 && Allegiance_CompareIds(0, *(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)) == 1) {
                flags = *(u32 *)((u8 *)unit + 0x1A0);
                if (flags & 0x800) {
                    *(u32 *)((u8 *)unit + 0x1A0) = flags & ~0x800;
                    Map_RefreshUnitMap(gBattleMap);
                    Map_SetupUnitMoveLimit(unit);
                    Ui_PlaySeCue(lbl_80274508 + 0x22C, 0x64);
                }
                return;
            }
        }
        if (unit == NULL) {
            flag = 0;
            iter = *(void **)(gUnitLists + 0xC);
            while (iter != NULL) {
                flags = *(u32 *)((u8 *)iter + 0x1A0);
                if (flags & 0x800) {
                    flag = 1;
                    *(u32 *)((u8 *)iter + 0x1A0) = flags & ~0x800;
                }
                iter = *(void **)((u8 *)iter + 0x184);
            }
            if (flag != 0) {
                Ui_PlaySeCue(lbl_80274508 + 0x22C, 0x64);
                Map_RefreshUnitMap(gBattleMap);
                return;
            }
        }
        if (gUiInputFlags & 0x400)
            Map_HideMoveLimitView();
        Ui_PlaySeCue(lbl_80274508 + 0x247, 0x64);
        BattleState_SetCamPos(gBattleState, (f32)(s8)ef[0xD], (f32)(s8)ef[0xE]);
        Process_Goto(self, 2);
        return;
    } else {
        if (buttons & 0x10) {
        cancel:
            if (gUiInputFlags & 0x400)
                Map_HideMoveLimitView();
            Ui_PlaySeCue(lbl_80274508 + 0x247, 0x64);
            BattleState_SetCamPos(gBattleState, (f32)(s8)ef[0xD], (f32)(s8)ef[0xE]);
            Process_Goto(self, 1);
            return;
        }
        if (buttons & 0x1000) {
            if (gUiInputFlags & 0x400)
                Map_HideMoveLimitView();
            *((u8 *)self + 0x48) = 6;
            Process_Goto(self, 9);
        }
    }
}
#pragma use_lmw_stmw reset

void fn_801196A8(void *arg0) {
    void fn_800A8478(void);
    void fn_8018DB4C(void);
    void fn_8000C060(void *, void *);
    void Process_Goto(void *, s32);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_CloseChildAnim(void *, void *, s32);
    void fn_80119738(void);
    void *temp_r31;

    fn_800A8478();
    fn_8018DB4C();
    temp_r31 = *(void **)((u8 *)arg0 + 0x44);
    fn_8000C060(temp_r31, fn_80119738);
    Process_Goto(temp_r31, 1);
    if (Ui_FindChild(arg0, 0x40, 0) != NULL) {
        Ui_CloseChildAnim(arg0, Ui_FindChild(arg0, 0x40, 0), 1);
    }
}

void fn_80119738(void *arg0) {
    void fn_8006785C(s32, void (*)(void *), void *);
    void fn_80119768(void *);
    fn_8006785C(2, fn_80119768, arg0);
}

#pragma use_lmw_stmw on
void fn_80119768(void) {
    void *TargetList_GetAt(s32 *, s32);
    M2C_UNK fn_8004A864(s32 *);
    M2C_UNK Map_SetupColorGx();
    M2C_UNK fn_802245D8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern u8 gUiContext[];
    extern u8 gTargetList[];
    extern u8 gBattleMap[];
    extern u8 gUnits[];
    extern s32 lbl_8036A1E0;
    extern s32 lbl_8036A1E4;
    s32 spC;
    s32 sp8;
    s8 t29;
    s8 t28;
    s32 i;
    u8 b0;
    u8 b1;
    u8 id;
    void *unit;

    Map_SetupColorGx();
    i = 0;
    t28 = (s8) gUiContext[0xD];
    t29 = (s8) gUiContext[0xE];
    for (i = 0; i < *(s32 *) gTargetList; i++) {
        b0 = *(u8 *) TargetList_GetAt((s32 *) gTargetList, i);
        b1 = *((u8 *) TargetList_GetAt((s32 *) gTargetList, i) + 1);
        id = gBattleMap[0xD + (s8) b0 + ((s8) b1 << 6)];
        if (id == 0) {
            goto sound;
        }
        if (id != 0) {
            unit = &gUnits[(id - 1) * 0x280];
        } else {
            unit = NULL;
        }
        if (M2C_FIELD(unit, s32 *, 0x1A0) & 0x20000) {
            continue;
        }
sound:
        if (((s8) b0 != t28) || ((s8) b1 != t29)) {
            spC = lbl_8036A1E0;
            fn_8004A864(&spC);
        } else {
            sp8 = lbl_8036A1E4;
            fn_8004A864(&sp8);
        }
    }
    fn_802245D8(1, 4, 5, 0);
}

void fn_80119884(void *arg0) {
    void *Map_GetCursorUnit(void);
    u8 Allegiance_CompareIds(s32, u8);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *);
    extern s32 gBattleState[];
    extern u8 lbl_80274508[];
    extern u8 lbl_803679F4;
    extern void *lbl_803679F0;
    void *unit;
    s32 cx, cy;
    u8 *base;

    unit = Map_GetCursorUnit();
    base = (u8 *)gBattleState;
    cx = (s32)*(f32 *)(base + 0x524);
    cy = (s32)*(f32 *)(base + 0x528);
    (void)cx; (void)cy;
    if (unit != 0) {
        if (Allegiance_CompareIds(0, *(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8)) == 1) {
            if (!(*(u32 *)((u8 *)unit + 0x1A0) & 0x800)) {
                if (Ui_FindChild(arg0, -0x1000, 0) != 0)
                    Ui_SetWidgetText(lbl_80274508 + 0x1A7);
            } else if (Ui_FindChild(arg0, -0x1000, 0) != 0) {
                Ui_SetWidgetText(lbl_80274508 + 0x1B9);
            }
        }
    }
    if ((s8)lbl_803679F4 == 0) {
        lbl_803679F0 = 0;
        lbl_803679F4 = 1;
    }
}

void fn_8011A0CC(void *arg0) {
    void EventLock_Dec(void);
    void fn_800A8478(void);
    void fn_8018DB4C(void);
    void fn_8000C060(void *, void *);
    void Process_Goto(void *, s32);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_CloseChildAnim(void *, void *, s32);
    void fn_80119738(void);
    extern u8 gEventLockDepth;
    extern s8 gUiContext[];
    void *temp_r31;

    while (gEventLockDepth != 0) {
        EventLock_Dec();
    }
    fn_800A8478();
    fn_8018DB4C();
    temp_r31 = *(void **)((u8 *)arg0 + 0x44);
    fn_8000C060(temp_r31, fn_80119738);
    Process_Goto(temp_r31, 1);
    if (Ui_FindChild(arg0, 0x40, 0) != NULL) {
        Ui_CloseChildAnim(arg0, Ui_FindChild(arg0, 0x40, 0), 1);
    }
    gUiContext[0xD] = -1;
    gUiContext[0xE] = -1;
}

void fn_8011A184(void *arg0) {
 void fn_8011ACFC(void); void Unit_MoveToList(void *,s32); s32 fn_80015680(void *);
 void fn_800A8400(void); void Map_RefreshUnitMap(void *); void fn_80161F7C(void); void fn_8003F670(void *);
 void EventLock_Dec(void); void Ui_DtorPanelBase(void *,s32); void fn_801481CC(void *,s32); void fn_80148980(void *,s32); void fn_80018B04(void);
 extern u8 gUnitLists[],gTargetList[],gBattleMap[],gFxChannels[],lbl_80274508[];
 extern s16 lbl_80366E88; extern u8 gEventLockDepth;
 s16 count; s16 *limit; u8 *next; u8 *unit; s32 n;
 unit=*(u8 **)(gUnitLists+0xc);
 while(unit) { next=*(u8 **)(unit+0x184); *(u32 *)(unit+0x1a0)&=~0x800; unit=next; }
 fn_8011ACFC();
 unit=*(u8 **)gUnitLists;
 while(unit) {
 u32 flags=*(u32 *)(unit+0x1a0); next=*(u8 **)(unit+0x184);
 if(flags&0x010000DC) { *(u32 *)(unit+0x1a0)=flags&~0x010000DC; Unit_MoveToList(unit,5); }
 unit=next;
 }
 n=*(s32 *)gTargetList;
 count=n-fn_80015680(gUnitLists);
 limit=&count;
 if(count<lbl_80366E88) limit=&lbl_80366E88;
 ((u8 *)gBattleState)[0x56]=*limit;
 fn_800A8400(); Map_RefreshUnitMap(gBattleMap); fn_80161F7C(); fn_8003F670(*(void **)((u8 *)arg0+0x40));
 while(gEventLockDepth) EventLock_Dec();
 if(arg0) Ui_DtorPanelBase(arg0,0);
 if(!(gUiInputFlags&0x10)) { fn_801481CC(lbl_80274508+0x2e9,250); fn_80148980(gFxChannels,500); }
 fn_80018B04();
}

#pragma use_lmw_stmw reset
void fn_8011A2FC(s32 arg0) {
    s32 temp_r3;
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;
    s32 temp_r7;
    s32 temp_r8;
    s32 temp_r9;
    s32 temp_r31;
    
    // Call Ui_FindChild with parameters 0x40 and 0
    temp_r3 = Ui_FindChild(0x40, 0);
    
    // Check if return value is zero
    if (temp_r3 == 0) {
        // Call Heap_Alloc with parameter 0x3C
        temp_r31 = Heap_Alloc(0x3C);
        
        // Check if the return value is not null
        if (temp_r31 != 0) {
            // Setup for structure initialization - load the addresses of our globals
            temp_r4 = (s32)&lbl_8028FDB0;
            temp_r5 = (s32)&lbl_80292230;
            temp_r6 = (s32)&lbl_802921E0;
            
            // Initialize structure fields
            *(u32*)temp_r31 = temp_r4;
            *(u32*)(temp_r31 + 4) = 0;
            *(u32*)(temp_r31 + 0x0) = temp_r5;
            
            *(s16*)(temp_r31 + 8) = -1;
            *(s16*)(temp_r31 + 0xa) = 0;
            *(s16*)(temp_r31 + 0xc) = 0;
            *(s16*)(temp_r31 + 0xe) = 0x260;
            *(s16*)(temp_r31 + 0x10) = 0x1C0;
            *(s16*)(temp_r31 + 0x12) = 0;
            *(s16*)(temp_r31 + 0x14) = 0;
            *(s16*)(temp_r31 + 0x16) = 0x260;
            *(s16*)(temp_r31 + 0x18) = 0x1C0;
            *(s16*)(temp_r31 + 0x1a) = 0;
            *(s16*)(temp_r31 + 0x1c) = 0;
            
            *(u8*)(temp_r31 + 0x1e) = 0xFF;
            *(u8*)(temp_r31 + 0x1f) = 0xFF;
            *(u8*)(temp_r31 + 0x20) = 0xFF;
            *(u8*)(temp_r31 + 0x21) = 0xFF;
            *(s16*)(temp_r31 + 0x22) = 0x316;
            *(s16*)(temp_r31 + 0x24) = 0;
            
            *(f32*)(temp_r31 + 0x28) = 1.0f;
            *(f32*)(temp_r31 + 0x2c) = 1.0f;
            *(f32*)(temp_r31 + 0x30) = 1.0f;
            
            *(u32*)(temp_r31 + 0x34) = 0;
            *(u32*)(temp_r31 + 0x38) = 0;
            
            // Update the base address
            *(u32*)temp_r31 = temp_r6;
            
            // Continue initialization
            *(s16*)(temp_r31 + 8) = 0x40;
            *(u8*)(temp_r31 + 0x24) = 8;
            *(f32*)(temp_r31 + 0x2c) = 0.0f;
            
            // Call Ui_AddChild with parameters
            temp_r5 = *(u32*)(temp_r31 + 0x34);
            temp_r5 = temp_r5 | 0x10;
            *(u32*)(temp_r31 + 0x34) = temp_r5;
            
            Ui_AddChild(arg0, (void*)temp_r31, temp_r5);
            Ui_OpenChildAnim(arg0, (void*)temp_r31, 1);
        }
    }
}

void fn_8011A470(s32 arg0) {
    void EventLock_Inc(void);
    void fn_800A8450(void);
    void fn_8011A2FC(s32);
    void fn_8011A4E4(s32);
    u32 Ui_FindChild(s32, s32, s32);
    void Ui_SetWidgetText(u32, u8 *);
    extern u8 gEventLockDepth;
    extern u8 lbl_80274508[];
    u32 temp;

    if (gEventLockDepth == 0) {
        EventLock_Inc();
    }
    fn_800A8450();
    fn_8011A4E4(arg0);
    fn_8011A2FC(arg0);
    temp = Ui_FindChild(arg0, -0x1000, 0);
    if (temp != 0) {
        Ui_SetWidgetText(temp, lbl_80274508 + 0x2F5);
    }
}

void fn_8011A4E4(s32 arg0) {
    void Ui_CreateMenu(void *, s32, s32);
    extern u8 gUiContext[];
    extern u8 gUiMenuDrawVtbl[];
    extern u8 lbl_80286664[];
    extern u8 lbl_80286590[];
    extern u8 lbl_8028F7EC[];
    extern u8 lbl_8028FA3C[];
    extern u8 lbl_8028FABC[];
    extern u8 lbl_8028FB10[];
    extern u8 lbl_8028FB64[];
    extern u8 lbl_8028FBB8[];
    extern u8 lbl_8028FC0C[];
    extern u8 lbl_8028FC60[];
    extern u8 lbl_8028FCB4[];
    extern u8 lbl_8028FD08[];
    extern u8 lbl_8028FD5C[];
    extern s8 lbl_803679F5;
    extern void *lbl_803679F8;
    extern s8 lbl_803679FC;
    extern void *lbl_80367A00;
    extern s8 lbl_80367A04;
    extern void *lbl_80367A08;
    extern s8 lbl_80367A0C;
    extern void *lbl_80367A10;
    extern s8 lbl_80367A14;
    extern void *lbl_80367A18;
    extern s8 lbl_80367A1C;
    extern void *lbl_80367A20;
    extern s8 lbl_80367A24;
    extern void *lbl_80367A28;
    extern s8 lbl_80367A2C;
    extern void *lbl_80367A30;
    extern s8 lbl_80367A34;
    extern void *lbl_80367A38;
    extern s8 lbl_80367A3C;
    extern void *lbl_80367A40[2];

    if (lbl_803679F5 == 0) {
        lbl_803679F8 = lbl_8028FD5C;
        lbl_803679F5 = 1;
    }
    if (lbl_803679FC == 0) {
        lbl_80367A00 = lbl_8028FD08;
        lbl_803679FC = 1;
    }
    if (lbl_80367A04 == 0) {
        lbl_80367A08 = lbl_8028FCB4;
        lbl_80367A04 = 1;
    }
    if (lbl_80367A0C == 0) {
        lbl_80367A10 = lbl_8028FC60;
        lbl_80367A0C = 1;
    }
    if (lbl_80367A14 == 0) {
        lbl_80367A18 = lbl_8028FC0C;
        lbl_80367A14 = 1;
    }
    if (lbl_80367A1C == 0) {
        lbl_80367A20 = lbl_8028FBB8;
        lbl_80367A1C = 1;
    }
    if (lbl_80367A24 == 0) {
        lbl_80367A28 = lbl_8028FB64;
        lbl_80367A24 = 1;
    }
    if (lbl_80367A2C == 0) {
        lbl_80367A30 = lbl_8028FB10;
        lbl_80367A2C = 1;
    }
    if (lbl_80367A34 == 0) {
        lbl_80367A38 = lbl_8028FABC;
        lbl_80367A34 = 1;
    }
    if (lbl_80367A3C == 0) {
        lbl_80367A40[1] = gUiMenuDrawVtbl;
        lbl_80367A40[1] = lbl_80286664;
        lbl_80367A40[1] = lbl_80286590;
        lbl_80367A40[0] = lbl_8028F7EC;
        lbl_80367A40[1] = lbl_8028FA3C;
        lbl_80367A3C = 1;
    }
    gUiContext[8] = 0;
    Ui_CreateMenu(lbl_80367A40, arg0, 0);
}

void fn_8011A694(void) {
    void Unit_MoveToListHead(void *, s32);
    void Unit_MoveToList(void *, s32);
    void *Unit_FindByName(void *);
    void Map_RefreshUnitMap(void *);
    void fn_800C1060(s32);
    extern u8 gUnitLists[];
    extern u8 lbl_80274508[];
    extern u8 gBattleMap[];
    extern u8 gMapBlendMode;

    void *next;
    void *head;
    void *unit;
    void *found;
    s32 var_r4;
    s32 temp;

    head = *(void **)gUnitLists;
    unit = *(void **)(gUnitLists + 4);
    while (unit != NULL) {
        next = *(void **)((u8 *)unit + 0x180);
        if ((*(u32 *)((u8 *)unit + 0x1A0) & 0x10000) != 0) {
            Unit_MoveToListHead(unit, 0);
            if (unit == head) {
                break;
            }
        }
        unit = next;
    }

    unit = *(void **)(gUnitLists + 0x3C);
    while (unit != NULL) {
        next = *(void **)((u8 *)unit + 0x184);
        Unit_MoveToList(unit, 0);
        *(u32 *)((u8 *)unit + 0x1A0) |= 0x010000DC;
        unit = next;
    }

    found = Unit_FindByName(lbl_80274508 + 0x130);
    next = *(void **)gUnitLists;
    while (next != NULL) {
        unit = *(void **)((u8 *)next + 0x184);
        if (next != found) {
            *(s16 *)((u8 *)next + 0x15C) =
                (s16)(50.0f * ((f32)*(s16 *)((u8 *)found + 0x15C) / 50.0f));
        }
        next = unit;
    }

    Map_RefreshUnitMap(gBattleMap);
#pragma optimization_level 1
    var_r4 = 1;
    temp = (u8)(gMapBlendMode - 1);
    if (((u32)((var_r4 | ~temp) - ((u32)(var_r4 - temp) >> 1)) >> 31) == 0) {
        var_r4 = 0;
    }
#pragma optimization_level reset
    if ((u8)var_r4 != 0) {
        fn_800C1060(0);
    }
}

void fn_8011A7FC(void *arg0) {
    extern u8 gUnitLists[], gTargetList[], lbl_8028F790[], lbl_80274508[], lbl_80293C84[], lbl_80293C58[];
    extern u8 lbl_80367A48;
    void Unit_MoveToListHead(void *, s32);
    void fn_8002F728(void *);
    void fn_8002F6E8(void *, s8, s8, s32, s32);
    void *TargetList_GetAt(void *, s32);
    void *TargetList_GetCurrent(void *);
    void fn_8011C404(void *, void *);
    void fn_8011C2B8(void *, void *);
    void fn_8011C164(void *, void *);
    void fn_8011C018(void *, void *);
    void *Process_Create(void *, void *);
    void GfxEnt_UnlinkByName(char *);
    void *Heap_Alloc(s32);
    s32 strlen(char *);
    void Ui_AddChild(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Fx_StartSlot(s32,char *,s32,s32);
    void fn_80018B18(void);
    s32 d,c,b,a;
    s32 count;
    void *entry;
    s32 j;
    u8 *next, *unit, *coords;
    s32 i;
    s32 len;
    u8 *p;
    lbl_80367A48=0;
    gUiInputFlags &= ~1;
    for(unit=*(u8 **)(gUnitLists+4);unit;unit=next) {
        next=*(u8 **)(unit+0x180);
        if(*(u32 *)(unit+0x1A0)&0x010000DC) Unit_MoveToListHead(unit,5);
    }
    count=(s8)((u8 *)gBattleState)[0x544];
    fn_8002F728(gTargetList);
    coords=(u8 *)gBattleState+0x545;
    for(i=0;i<count;coords+=2,i++) fn_8002F6E8(gTargetList,(s8)coords[0],(s8)coords[1],0,0);
    for(j=0;j<*(s32 *)gTargetList;j++) {
        entry=TargetList_GetAt(gTargetList,j);
        fn_8011C404(entry,&a); fn_8011C2B8(entry,&b);
        fn_8011C164(entry,&c); fn_8011C018(entry,&d);
    }
    p=Process_Create(lbl_8028F790,arg0);
    if(p) *(void **)(p+0x30)=TargetList_GetCurrent(gTargetList);
    *(u8 **)((u8 *)arg0+0x44)=p;
    p=*(u8 **)((u8 *)arg0+0x44); p[0x2c]|=4;
    GfxEnt_UnlinkByName((char *)lbl_80274508+0x115);
    p=Heap_Alloc(0x5C);
    if(p) {
            M2C_FIELD(p, void * *, 0x0) = lbl_8028FDB0;
            M2C_FIELD(p, s32 *, 0x4) = 0;
            M2C_FIELD(p, void * *, 0x0) = lbl_80292230;
            M2C_FIELD(p, s16 *, 0x8) = -1;
            M2C_FIELD(p, s16 *, 0xA) = 0;
            M2C_FIELD(p, s16 *, 0xC) = 0x190;
            M2C_FIELD(p, s16 *, 0xE) = 0x260;
            M2C_FIELD(p, s16 *, 0x10) = 0x1C0;
            M2C_FIELD(p, s16 *, 0x12) = 0;
            M2C_FIELD(p, s16 *, 0x14) = 0;
            M2C_FIELD(p, s16 *, 0x16) = 0x260;
            M2C_FIELD(p, s16 *, 0x18) = 0x30;
            M2C_FIELD(p, s16 *, 0x1A) = 0;
            M2C_FIELD(p, s16 *, 0x1C) = 0;
            M2C_FIELD(p, u8 *, 0x1E) = 0xFF;
            M2C_FIELD(p, u8 *, 0x1F) = 0xFF;
            M2C_FIELD(p, u8 *, 0x20) = 0xFF;
            M2C_FIELD(p, u8 *, 0x21) = 0xFF;
            M2C_FIELD(p, s16 *, 0x22) = 0x316;
            M2C_FIELD(p, s16 *, 0x24) = 0;
            M2C_FIELD(p, f32 *, 0x28) = 1.0f;
            M2C_FIELD(p, f32 *, 0x2C) = 1.0f;
            M2C_FIELD(p, f32 *, 0x30) = 1.0f;
            M2C_FIELD(p, s32 *, 0x34) = 0;
            M2C_FIELD(p, s32 *, 0x38) = 0;
            M2C_FIELD(p, void * *, 0x0) = lbl_80293C84;
            M2C_FIELD(p, s32 *, 0x3C) = 0;
            M2C_FIELD(p, s32 *, 0x40) = 0;
            M2C_FIELD(p, s32 *, 0x44) = 0;
            M2C_FIELD(p, s32 *, 0x40) = 0;
            M2C_FIELD(p, s32 *, 0x48) = 0;
            M2C_FIELD(p, u8 *, 0x4C) = 1;
            M2C_FIELD(p, s16 *, 0x4E) = 0;
            M2C_FIELD(p, s16 *, 0x50) = 0;
            M2C_FIELD(p, s16 *, 0x52) = 0;
            M2C_FIELD(p, s16 *, 0x54) = 0;
            M2C_FIELD(p, void * *, 0x0) = lbl_80293C58;
            M2C_FIELD(p, s32 *, 0x58) = 1;
            M2C_FIELD(p, s16 *, 0x4E) = 0x30;
            M2C_FIELD(p, s16 *, 0x52) = 0x30;
    }
    *(s16 *)(p+8)=-0x1000; *(s32 *)(p+0x48)=1;
    len=strlen(&((char *)lbl_80274508)[353]);
    String_AssignCStr(&p[0x3C],(char *)&lbl_80274508[353],len);
    *(u32 *)(p+0x34)|=0x10; *(s32 *)(p+0x58)=1;
    Ui_AddChild(arg0,p);
    p=Ui_FindChild(arg0,-0x1000,0);
    if(p) *(s32 *)(p+0x58)=0;
    ((u8 *)gBattleState)[0xA9]=0; ((u8 *)gBattleState)[0xAA]=0; *(s32 *)((u8 *)gBattleState+0xB0)=0;
    if(!(gUiInputFlags&0x10)) Fx_StartSlot(0,(char *)lbl_80274508+0x2E9,100,1);
    fn_80018B18();
}

void fn_8011AB38(void *arg0) {
    s32 fn_8003FCCC();
    u8 fn_8005BA10();
    s32 fn_80161FB8();
    M2C_UNK fn_80162054();
    fn_801620AC();
    if (fn_8005BA10() != 0) {
        if (fn_80161FB8() == 0) {
            return;
        }
        fn_80162054();
        fn_801620AC();
        M2C_FIELD((short)arg0, s32 *, 0x40) = fn_8003FCCC();
        fn_8000C188(arg0);
    }
}

void fn_8011AB98(void) {
    M2C_UNK fn_801620AC();
    M2C_UNK fn_8005C8B4();
    M2C_UNK fn_80162018();
    fn_801620AC();
    fn_8005C8B4();
    fn_80162018();
}

void fn_8011ABC0(s32 arg0) {
    void Msg_Expand(void *);
    void Ui_CreateMenu(void *, s32, s32);
    void *fn_8013BFFC(void);
    extern char lbl_80274508[];
    void *tmp;

    Msg_Expand(lbl_80274508 + 0x17c);
    tmp = fn_8013BFFC();
    *((u8 *)tmp + 0x24) = 1;
    Ui_CreateMenu(tmp, arg0, 0);
}

s32 fn_8011AC10(void) {
    extern u16 lbl_8028F814[];
    s32 v = Process_Find(lbl_8028F814);
    return v != 0;
}

void fn_8011AC44(void) {
    u32 Process_Find(void *);
    void Process_Unlink(void);
    extern u8 lbl_8028F814[];
    if (Process_Find(lbl_8028F814) != 0U) {
        Process_Unlink();
    }
}

void *fn_8011AC78(void *arg0)
{
    extern u8 lbl_8028F814[];
    extern u8 lbl_8028F7D8[];

    extern void *Process_CreateChild(void *, void *);
    extern void *Process_Create(void *, void *);
    extern void fn_801403F0(void *);

    u8 *result;

    if (arg0 != 0) {
        result = (u8 *)Process_CreateChild(lbl_8028F814, arg0);
    } else {
        result = (u8 *)Process_Create(lbl_8028F814, arg0);
    }

    if (result != 0) {
        fn_801403F0(result);
        *(u32 *)(result + 0x40) = 0;
    }

    Process_Create(lbl_8028F7D8, result);

    return result;
}

void fn_8011ACFC(void) {
    void fn_8001594C(void *, s8);
    void fn_800156A0(void *, void *);
    void fn_80015718(void *, void *);
    extern u8 gUnitLists[];
    void *list[3];
    u32 flags;
    u8 *next;
    u8 *node;
    fn_8001594C(list,0);
    node=*(u8 **)gUnitLists;
    for(;node;node=next) {
        next=*(u8 **)(node+0x184);
        if(!(*(u32 *)(node+0x1A0)&0x010000DC)) {
            fn_800156A0(*(void **)(node+0x190),node);
            fn_80015718(list,node);
        }
    }
    node=*(u8 **)gUnitLists;
    for(;node;node=next) {
        next=*(u8 **)(node+0x184);
        if(!(*(u32 *)(node+0x1A0)&0x010000DC)) break;
        fn_800156A0(*(void **)(node+0x190),node);
        fn_80015718(list,node);
        *(u32 *)(node+0x1A0)|=0x010000DC;
    }
    node=list[0];
    for(;node;node=next) {
        next=*(u8 **)(node+0x184);
        flags=*(u32 *)(node+0x1A0)&0x010000DC;
        fn_800156A0(*(void **)(node+0x190),node);
        fn_80015718(gUnitLists,node);
        if(flags) *(u32 *)(node+0x1A0)|=0x010000DC;
    }
}

void fn_8011AE2C(void *arg0) {
    M2C_UNK Unit_SetMapPos(s32, u8, u8);
    M2C_UNK fn_80050C90(s32);
    Unit_SetMapPos(M2C_FIELD(arg0, s32 *, 0x30), M2C_FIELD(arg0, u8 *, 0x58), M2C_FIELD(arg0, u8 *, 0x59));
    fn_80050C90(M2C_FIELD(arg0, s32 *, 0x30));
}

void fn_8011AE6C(void *arg0) {
    f32 Map_SampleHeightRaw(void *, f32, f32);
    extern u8 gBattleMap[];
    extern f32 lbl_8036A200;
    extern f32 lbl_8036A1F8;
    extern f64 lbl_8036A208;
    extern f64 lbl_8036A210;
    extern f64 lbl_8036A218;
    extern f32 lbl_80367068[];
    extern f32 lbl_8036A224;
    extern f32 lbl_8036A228;
    extern f32 lbl_8036A220;
    extern f32 lbl_8036A22C;
    extern f32 lbl_8036A230;
    f32 spC;
    f32 sp8;
    f32 c;
    f32 x, y, z;
    f32 x2, y2, z2;
    f32 mx, my, mz;
    f32 dx, dy, dz;
    f32 len;
    f32 len2;
    f32 clamped;
    f32 ratio;
    f32 nx, ny;
    f32 zoff;
    f32 eps;
    f64 g, g2, g3;
    s32 cls;
    s32 word;
    void *p;

    p = *(void **)((u8 *)arg0 + 0x30);
    *(f32 *)((u8 *)arg0 + 0x34) = *(f32 *)((u8 *)p + 4);
    p = *(void **)((u8 *)arg0 + 0x30);
    *(f32 *)((u8 *)arg0 + 0x38) = *(f32 *)((u8 *)p + 8);
    *(f32 *)((u8 *)arg0 + 0x3C) = Map_SampleHeightRaw(gBattleMap,
        *(f32 *)((u8 *)arg0 + 0x34), *(f32 *)((u8 *)arg0 + 0x38));
    c = lbl_8036A200;
    *(f32 *)((u8 *)arg0 + 0x4C) = c + (f32)(s8)((u8 *)arg0)[0x58];
    *(f32 *)((u8 *)arg0 + 0x50) = c + (f32)(s8)((u8 *)arg0)[0x59];
    *(f32 *)((u8 *)arg0 + 0x54) = Map_SampleHeightRaw(gBattleMap,
        (f32)(s8)((u8 *)arg0)[0x58], (f32)(s8)((u8 *)arg0)[0x59]);
    c = lbl_8036A200;
    y = *(f32 *)((u8 *)arg0 + 0x38);
    y2 = *(f32 *)((u8 *)arg0 + 0x50);
    x = *(f32 *)((u8 *)arg0 + 0x34);
    x2 = *(f32 *)((u8 *)arg0 + 0x4C);
    dy = y2 - y;
    my = y + y2;
    z = *(f32 *)((u8 *)arg0 + 0x3C);
    dx = x2 - x;
    z2 = *(f32 *)((u8 *)arg0 + 0x54);
    dy = dy * dy;
    mx = x + x2;
    dz = z2 - z;
    dx = (dx * dx) + dy;
    mz = z + z2;
    mx = c * mx;
    len = (dz * dz) + dx;
    my = c * my;
    mz = c * mz;
    if (len > lbl_8036A1F8) {
        g = __frsqrte(len);
        g2 = lbl_8036A208 * g * -(((f64)len * (g * g)) - lbl_8036A210);
        g3 = lbl_8036A208 * g2 * -(((f64)len * (g2 * g2)) - lbl_8036A210);
        len = (f32)((f64)len * (lbl_8036A208 * g3 * -(((f64)len * (g3 * g3)) - lbl_8036A210)));
    } else if ((f64)len < lbl_8036A218) {
        len = lbl_80367068[0];
    } else {
        spC = len;
        word = *(s32 *)&spC;
        switch (word & 0x7F800000) {
        case 0x7F800000:
            if (word & 0x7FFFFF) {
                cls = 1;
            } else {
                cls = 2;
            }
            break;
        case 0x0:
            if (word & 0x7FFFFF) {
                cls = 5;
            } else {
                cls = 3;
            }
            break;
        default:
            cls = 4;
            break;
        }
        if (cls == 1) {
            len = lbl_80367068[0];
        }
    }
    eps = lbl_8036A1F8;
    *(s16 *)((u8 *)arg0 + 0x5C) = (s16)(((lbl_8036A220 * (lbl_8036A224 - len)) + (lbl_8036A228 * len)) * lbl_8036A22C);
    *(s16 *)((u8 *)arg0 + 0x5A) = 0;
    dy = *(f32 *)((u8 *)arg0 + 0x50) - my;
    ny = *(f32 *)((u8 *)arg0 + 0x4C) - mx;
    nx = -dy;
    len2 = (nx * nx) + (ny * ny);
    if (len2 > eps) {
        g = __frsqrte(len2);
        g2 = lbl_8036A208 * g * -(((f64)len2 * (g * g)) - lbl_8036A210);
        g3 = lbl_8036A208 * g2 * -(((f64)len2 * (g2 * g2)) - lbl_8036A210);
        len2 = (f32)((f64)len2 * (lbl_8036A208 * g3 * -(((f64)len2 * (g3 * g3)) - lbl_8036A210)));
    } else if ((f64)len2 < lbl_8036A218) {
        len2 = lbl_80367068[0];
    } else {
        sp8 = len2;
        word = *(s32 *)&sp8;
        switch (word & 0x7F800000) {
        case 0x7F800000:
            if (word & 0x7FFFFF) {
                cls = 1;
            } else {
                cls = 2;
            }
            break;
        case 0x0:
            if (word & 0x7FFFFF) {
                cls = 5;
            } else {
                cls = 3;
            }
            break;
        default:
            cls = 4;
            break;
        }
        if (cls == 1) {
            len2 = lbl_80367068[0];
        }
    }
    clamped = len2;
    if (len2 > lbl_8036A230) {
        clamped = lbl_8036A230;
    }
    ratio = clamped / len2;
    nx = nx * ratio;
    ny = ny * ratio;
    zoff = lbl_8036A230;
    zoff = zoff * clamped;
    *(f32 *)((u8 *)arg0 + 0x40) = mx + nx;
    *(f32 *)((u8 *)arg0 + 0x44) = my + ny;
    *(f32 *)((u8 *)arg0 + 0x48) = mz - zoff;
    if (*(s16 *)((u8 *)arg0 + 0x5C) > 0x30) {
        *(s16 *)((u8 *)arg0 + 0x5C) = 0x30;
    }
}

#pragma global_optimizer off
void fn_8011B204(void *arg0) {
    void Process_ClearFunc(void *);
    extern f32 lbl_8036A1E8;
    extern f32 lbl_8036A230;
    f32 c1;
    s16 num;
    s16 den;
    f32 c2;
    f32 p1y;
    f32 tn;
    f32 p1x;
    f32 td;
    f32 p1z;
    f32 p0x;
    f32 p0y;
    f32 p2y;
    f32 t;
    f32 p2x;
    f32 p0z;
    f32 p2z;
    void *out;
    f32 u;
    f32 t2;
    f32 w;
    f32 u2;
    f32 x;
    f32 y;
    f32 z;
    s16 cur;

    c1 = lbl_8036A1E8;
    num = *(s16 *)((u8 *)arg0 + 0x5A);
    den = *(s16 *)((u8 *)arg0 + 0x5C);
    c2 = lbl_8036A230;
    p1y = *(f32 *)((u8 *)arg0 + 0x44);
    tn = (f32)num;
    p1x = *(f32 *)((u8 *)arg0 + 0x40);
    td = (f32)den;
    p1z = *(f32 *)((u8 *)arg0 + 0x48);
    p0x = *(f32 *)((u8 *)arg0 + 0x34);
    p0y = *(f32 *)((u8 *)arg0 + 0x38);
    p2y = *(f32 *)((u8 *)arg0 + 0x50);
    t = tn / td;
    p2x = *(f32 *)((u8 *)arg0 + 0x4C);
    p0z = *(f32 *)((u8 *)arg0 + 0x3C);
    p2z = *(f32 *)((u8 *)arg0 + 0x54);
    out = *(void **)((u8 *)arg0 + 0x30);

    u = c1 - t;
    t2 = t * t;
    w = c2 * u;
    u2 = u * u;
    w = w * t;

    x = p1x * w;
    y = p1y * w;
    z = p1z * w;
    x = p0x * u2 + x;
    y = p0y * u2 + y;
    z = p0z * u2 + z;
    x = p2x * t2 + x;
    y = p2y * t2 + y;
    z = p2z * t2 + z;

    *(f32 *)((u8 *)out + 4) = x;
    *(f32 *)((u8 *)out + 8) = y;
    *(f32 *)((u8 *)out + 0xC) = z;

    cur = *(s16 *)((u8 *)arg0 + 0x5A);
    *(s16 *)((u8 *)arg0 + 0x5A) = (s16)(cur + 1);
    if (cur == *(s16 *)((u8 *)arg0 + 0x5C)) {
        Process_ClearFunc(arg0);
    }
}
#pragma global_optimizer reset
void fn_8011B2EC(void) {
    M2C_UNK fn_800F20E0();
    M2C_UNK fn_800F214C();
    fn_800F214C();
    fn_800F20E0();
}

#pragma use_lmw_stmw on
void fn_8011B310(void *arg0) {
    void fn_800F20E0(void);
    void fn_800F214C(void);
    void Ui_PlaySeCue(void *, s32);
    void BattleState_SetCamPos(void *, f32, f32);
    extern s32 gUiInputFlags;
    extern s32 *gPadInput;
    extern u8 lbl_80274508[];
    register s32 flags;
    register u8 saved_x;
    register u8 saved_y;
    register u8 skip;
    register u8 *node;
    register u8 *base;

    skip = 0;
    base = (u8 *)gBattleState;
    saved_x = (u8)(s32)*(f32 *)(base + 0x524);
    saved_y = (u8)(s32)*(f32 *)(base + 0x528);
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20)) {
        skip = 1;
    }
    if (skip == 0) {
        flags = gPadInput[3];
        if (flags & 1) {
            node = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x30) + 4);
            *(void **)((u8 *)arg0 + 0x30) = node;
            BattleState_SetCamPos(gBattleState, (f32)(s8)node[0], (f32)(s8)node[1]);
        }
        if (flags & 8) {
            node = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x30) + 0xC);
            *(void **)((u8 *)arg0 + 0x30) = node;
            BattleState_SetCamPos(gBattleState, (f32)(s8)node[0], (f32)(s8)node[1]);
        }
        if (flags & 2) {
            node = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x30) + 8);
            *(void **)((u8 *)arg0 + 0x30) = node;
            BattleState_SetCamPos(gBattleState, (f32)(s8)node[0], (f32)(s8)node[1]);
        }
        if (flags & 4) {
            node = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x30) + 0x10);
            *(void **)((u8 *)arg0 + 0x30) = node;
            BattleState_SetCamPos(gBattleState, (f32)(s8)node[0], (f32)(s8)node[1]);
        }
        if ((flags & 0xF) == 0) {
            fn_800F214C();
        }
        if ((s32)saved_x != (s8)(s32)*(f32 *)(base + 0x524) ||
            (s32)saved_y != (s8)(s32)*(f32 *)(base + 0x528)) {
            Ui_PlaySeCue(lbl_80274508 + 0x307, 0x64);
        }
    }
    fn_800F20E0();
}
#pragma use_lmw_stmw reset

void fn_8011B570(void) {

}

void fn_8011B574(void) {

}

s32 fn_8011B578(void) {
    return 0xB0;
}

#pragma cplusplus on
extern "C" void fn_8011B580(void *arg0, void *arg1) {
void fn_8008C1D8(s32,s32,s32,s32,s32);
struct Obj { u8 pad[4]; virtual void v0()=0;
virtual void v1()=0;
virtual void v2()=0;
virtual void v3()=0;
virtual void v4()=0;
virtual void v5()=0;
virtual void v6()=0;
virtual void v7()=0;
virtual void v8()=0;
virtual void v9()=0;
virtual void v10()=0;
virtual void v11()=0;
virtual void v12()=0;
virtual void v13()=0;
virtual void v14()=0;
virtual void v15()=0;
virtual void v16()=0;
virtual void v17()=0;
virtual void v18()=0;
virtual void v19()=0;
virtual s16 v20()=0;
virtual void v21()=0;
virtual void v22()=0;
virtual void v23()=0;
virtual void v24()=0;
virtual void v25()=0;
virtual void v26()=0;
virtual void v27()=0;
virtual void v28()=0;
virtual void v29()=0; };
s32 value=*(s8 *)((u8 *)arg1+0x60);
s32 count=value;
((Obj *)arg0)->v29();
fn_8008C1D8(0,0,0,count*((Obj *)*(void **)((u8 *)arg1+0x3C))->v20()+0x20,2);
}
#pragma cplusplus reset
void fn_8011B5FC(void *arg0, void *arg1) {
    M2C_UNK Prim2D_AddZ(f32);
    M2C_UNK Prim2D_PrepareTex();
    M2C_UNK Prim2D_Begin();
    s32 Text_MeasureHeight(M2C_UNK, f32, f32);
    M2C_UNK Ui_DrawObjRouteIcon();
    M2C_UNK fn_8008AB7C(s32, s32, s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern f32 lbl_8036A1E8;
    extern f32 lbl_8036A234;
    extern f32 lbl_8036A238;
    extern f32 lbl_8036A23C;
    f32 temp_f2;
    s16 temp_r31;
    s32 temp_r29;
    s32 temp_r30;

    Ui_DrawObjRouteIcon();
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), M2C_UNK (**)(void *, void *), 0x7C)(arg0, arg1);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A234);
    Prim2D_PrepareTex();
    temp_f2 = (f32) M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 (**)(void *), 0x50)(arg0);
    temp_r29 = (s32) (lbl_8036A238 * temp_f2);
    temp_r30 = Text_MeasureHeight(-1, lbl_8036A1E8, temp_f2) >> 1;
    temp_r31 = M2C_FIELD(arg1, s16 *, 0x3A);
    fn_8008AB7C(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 (**)(void *), 0x50)(arg0) >> 1, temp_r31 + temp_r30, temp_r29, 0x17, 0xA, 0x28, 1);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036A23C);
    Prim2D_PrepareTex();
}

#pragma cplusplus on
extern "C" s16 fn_8011B710(void *arg0) {
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
        virtual s16 v18() = 0;
    };
    s16 temp = ((Obj *)arg0)->v18();
    return (s16)((0x260 - temp) >> 1);
}
#pragma cplusplus reset
s32 fn_8011B74C(void) {
    return 0x40;
}

extern u8 gUnitInfoPopup[];
s32 fn_8011B754(void) {
    u8 Ui_IsUnitInfoPopupOpen(void *);

    return Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) ? 0x40 : 0x10;
}

#pragma cplusplus on
extern "C" void *GfxEnt_Get(u8);
extern "C" u8 Ui_IsUnitInfoPopupOpen(void *);
extern "C" s32 fn_8011B78C(void *arg0, void *arg1) {
    extern void *gPadInput;
    extern u8 gUiContext[];
    struct Handler {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual s32 OnA(void *, void *) = 0;
        virtual s32 OnL(void *, void *) = 0;
        virtual s32 OnZ(void *, void *) = 0;
        virtual void v12() = 0;
        virtual s32 OnDefault(void *, void *) = 0;
    };
    struct Menu {
        u8 pad0[4];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual s32 OnB(void *, void *) = 0;
        virtual s32 OnR(void *, void *) = 0;
    };
    u32 buttons;
    void *unit;
    u8 flag;
    u8 *ids;

    ids = (u8 *)arg1 + 0x40;
    unit = GfxEnt_Get(ids[M2C_FIELD(arg1, s8 *, 0x62)]);
    flag = 0;
    if ((gUiInputFlags & 0x10) && !(gUiInputFlags & 0x20)) {
        flag = 1;
    }
    if (flag) {
        return M2C_FIELD(unit, Handler **, 0x34)->OnDefault(arg1, unit);
    }
    buttons = M2C_FIELD(gPadInput, u32 *, 4) & (M2C_FIELD(gPadInput, u32 *, 8) ^ M2C_FIELD(gPadInput, u32 *, 4));
    lbl_80367A48 = M2C_FIELD(unit, u8 *, 0x3A) + 0x80;
    if ((buttons & 0x100) && !Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
        return M2C_FIELD(unit, Handler **, 0x34)->OnA(arg1, unit);
    }
    if (buttons & 0x200) {
        return M2C_FIELD(arg1, Menu **, 0x3C)->OnB(arg1, unit);
    }
    if (buttons & 0x400) {
        return M2C_FIELD(unit, Handler **, 0x34)->OnL(arg1, unit);
    }
    if (buttons & 0x800) {
        return M2C_FIELD(arg1, Menu **, 0x3C)->OnR(arg1, unit);
    }
    if (buttons & 0x10) {
        return M2C_FIELD(unit, Handler **, 0x34)->OnZ(arg1, unit);
    }
    if ((buttons & 0x1000) && !Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x18), u8 *, 0x48) = 1;
        gUiContext[8] = 0x88;
        return 5;
    }
    return M2C_FIELD(unit, Handler **, 0x34)->OnDefault(arg1, unit);
}
#pragma cplusplus reset
void fn_8011B978(void) {
    extern u16 lbl_80274508[];
    Msg_Expand((u8 *)lbl_80274508 + 0x357);
}

void *fn_8011B9A4(void) {
    extern u16 lbl_80274508[];
    return &lbl_80274508[0x364 / sizeof(u16)];
}

u8 fn_8011B9B4(void) {
    extern u8 lbl_80367A48;
    return (u8) (lbl_80367A48 == 0x88);
}

s32 fn_8011B9C8(s32 unused, u8 *arg1) {
    extern u8 gUiContext[24];
    u8 *p;
    u8 *obj;
    obj = *(u8 **)(arg1 + 0x18);
    obj[0x48] = 1;
    p = gUiContext;
    p[8] = 0x88;
    return 5;
}

#pragma cplusplus on
extern "C" void fn_8011B9EC(void *self, void *panel, void *entry) {
    s32 Text_MeasureWidth(void *, s32, f32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    extern f32 lbl_8036A1E8;

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
        virtual s16 v18() = 0;
    };
    struct TextSrc {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void *v4(void *) = 0;
    };
    struct Host {
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
        virtual void v17(void *) = 0;
        virtual void v18(void *) = 0;
    };

    s16 w;
    s32 tw;
    void *text;

    w = ((Obj *)*(void **)((u8 *)panel + 0x3C))->v18();
    text = ((TextSrc *)*(void **)((u8 *)entry + 0x34))->v4(entry);
    tw = Text_MeasureWidth(text, -1, lbl_8036A1E8);
    ((Host *)self)->v17(panel);
    Prim2D_AddPrim(6);
    Prim2D_SetPos((f32)((w - tw) >> 1), (f32)*(s16 *)((u8 *)entry + 0x32));
    ((Host *)self)->v18(entry);
    text = ((TextSrc *)*(void **)((u8 *)entry + 0x34))->v4(entry);
    Prim2D_SetText(text);
    Prim2D_EndPrim();
}
#pragma cplusplus reset

void fn_8011BAF8(void) {
    extern u16 lbl_80274508[];
    Msg_Expand((u8 *)lbl_80274508 + 0x385);
}

void *fn_8011BB24(void) {
    extern u16 lbl_80274508[];
    return (u8 *) &lbl_80274508 + 0x38F;
}

u8 fn_8011BB34(void) {
    u8 fn_801E3620(void *);
    extern u8 gSystemSave[];

    if (((u8 *)gBattleState)[0x10] > 0x1FU) {
        return 2;
    }
    if (!(gUiInputFlags & 0x10) && fn_801E3620(gSystemSave) == 0) {
        return 2;
    }
    return (u8)(lbl_80367A48 == 0x87);
}

#pragma cplusplus on
extern "C" s32 fn_8011BBA4(void *arg0, void *panel, void *entry) {
    void Ui_CreateMsgPopup(void *, void *, f32, f32);
    u8 fn_801E3620(void *);
    extern u8 lbl_80274508[];
    extern u8 gSystemSave[];
    extern u8 gUiContext[];
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
    f32 fx;
    f32 fy;
    s16 base;

    if (*(u8 *)((u8 *)entry + 0x39) == 2) {
        base = ((Obj *)*(void **)((u8 *)panel + 0x3C))->v21();
        fx = (f32)(base + *(s16 *)((u8 *)entry + 0x30));
        base = ((Obj *)*(void **)((u8 *)panel + 0x3C))->v22();
        fy = (f32)(base + *(s16 *)((u8 *)entry + 0x32));
        if (((u8 *)gBattleState)[0x10] > 0x1FU) {
            Ui_CreateMsgPopup(lbl_80274508 + 0x398, panel, fx, fy);
        } else if (!(gUiInputFlags & 0x10) && fn_801E3620(gSystemSave) == 0) {
            Ui_CreateMsgPopup(lbl_80274508 + 0x3AD, panel, fx, fy);
        }
        return 0;
    }
    gUiContext[8] = 0x87;
    return 5;
}
#pragma cplusplus reset
void fn_8011BD08(void) {
    extern u8 lbl_80274508[];
    extern void Msg_Expand(void *);

    Msg_Expand(lbl_80274508 + 0x3BE);
}

void *fn_8011BD34(void) {
    extern u16 lbl_80274508[];
    return (u8 *)lbl_80274508 + 0x3C6;
}

u8 fn_8011BD44(void) {
    extern u8 lbl_80367A48;
    return (u8) (lbl_80367A48 == 0x86);
}

s32 fn_8011BD58(void) {
    extern u8 gUiContext[24];
    gUiContext[8] = 0x86;
    return 5;
}

void fn_8011BD70(void) {
    extern u8 lbl_80274508[];
    Msg_Expand(&lbl_80274508[0x3CF]);
}

void *fn_8011BD9C(void) {
    extern u16 lbl_80274508[];
    return (u8 *)lbl_80274508 + 0x3D8;
}

u8 fn_8011BDAC(void) {
    extern u8 lbl_80367A48;
    u32 temp;

    temp = __cntlzw(0x85 - lbl_80367A48);
    return (u8)((temp >> 5) & 0xFF);
}

extern u8 gUiContext[24];
s32 fn_8011BDC0(void) {
    gUiContext[8] = 0x85;
    return 5;
}

void fn_8011BDD8(void) {
    extern u16 lbl_80274508[];
    Msg_Expand((u8 *)lbl_80274508 + 0x3E1);
}

void *fn_8011BE04(void) {
    extern u16 lbl_80274508[];
    return (u8 *)lbl_80274508 + 0x3ED;
}

s32 fn_8011BE14(void) {
    u32 Res_GetByName(void *);
    extern u8 lbl_80274508[];
    extern u8 lbl_80367A48;

    if (Res_GetByName(lbl_80274508 + 0x3f9) == 0) {
        return 3;
    }
    return (u8)(lbl_80367A48 == 0x84);
}

s32 fn_8011BE60(void) {
    gUiContext[8] = 0x84;
    return 5;
}

void fn_8011BE78(void) {
    extern u16 lbl_80274508[];
    Msg_Expand((u8 *)lbl_80274508 + 0x402);
}

void *fn_8011BEA4(void) {
    extern u16 lbl_80274508[];
    return (u8 *)lbl_80274508 + 0x412;
}

u8 fn_8011BEB4(void) {
    extern u8 lbl_80367A48;
    u32 temp;

    temp = __cntlzw(0x83 - lbl_80367A48);
    return (u8)((temp >> 5) & 0xFF);
}

s32 fn_8011BEC8(void) {
    gUiContext[8] = 0x83;
    return 5;
}

void fn_8011BEE0(void) {
    extern u16 lbl_80274508[];
    Msg_Expand((u8 *)lbl_80274508 + 0x41D);
}

void *fn_8011BF0C(void) {
    extern u16 lbl_80274508[];
    return (u8 *)lbl_80274508 + 0x429;
}

u8 fn_8011BF1C(void) {
    extern u8 lbl_80367A48;
    u32 temp;

    temp = __cntlzw(0x82 - lbl_80367A48);
    return (u8)((temp >> 5) & 0xFF);
}

s32 fn_8011BF30(void) {
    gUiContext[8] = 0x82;
    return 5;
}

void fn_8011BF48(void) {
    extern u16 lbl_80274508[];
    Msg_Expand((u8 *)lbl_80274508 + 0x435);
}

void *fn_8011BF74(void) {
    extern u8 lbl_80274508[];
    return &lbl_80274508[0x442];
}

u8 fn_8011BF84(void) {
    extern u8 lbl_80367A48;
    u32 temp;

    temp = __cntlzw(0x81 - lbl_80367A48);
    return (u8)((temp >> 5) & 0xFF);
}

s32 fn_8011BF98(void) {
    *(u8*)((u32)&gUiContext + 8) = 0x81;
    return 5;
}

void fn_8011BFB0(void) {
    extern u16 lbl_80274508[];
    Msg_Expand((u8 *)lbl_80274508 + 0x44F);
}

void *fn_8011BFDC(void) {
    extern u16 lbl_80274508[];
    return (u8 *)lbl_80274508 + 0x45C;
}

u8 fn_8011BFEC(void) {
    extern u8 lbl_80367A48;
    u32 temp;

    temp = __cntlzw(0x80 - lbl_80367A48);
    return (u8)((temp >> 5) & 0xFF);
}

s32 fn_8011C000(void) {
    gUiContext[8] = 0x80;
    return 5;
}

#pragma use_lmw_stmw on
s32 fn_8011C018(void *self) {
    void *TargetList_GetAt(void *, s32);
    extern u8 gTargetList[];
    s16 bestDist;
    void *best;
    s32 i;
    void *other;
    s32 dy;
    s32 dx;
    s16 dist;
    u8 prefer;
    void *result;
    u32 oy;
    u32 ox;
    u32 sy;
    u32 sx;
    s32 neg;

    bestDist = 0x7FFF;
    best = NULL;
    for (i = 0; i < *(s32 *)gTargetList; i++) {
        other = TargetList_GetAt(gTargetList, i);
        if (self == other) {
            continue;
        }
        oy = ((u8 *)other)[1];
        sy = ((u8 *)self)[1];
        if ((s8)sy >= (s8)oy) {
            continue;
        }
        dy = (s8)sy - (s8)oy;
        neg = dy < 0;
        if (neg) {
            dy = -dy;
        }
        ox = ((u8 *)other)[0];
        sx = ((u8 *)self)[0];
        dx = (s8)sx - (s8)ox;
        if ((s8)sx - (s8)ox < 0) {
            dx = -dx;
        }
        dist = (s16)(dx + dy);
        if (bestDist < dist) {
            continue;
        }
        if (best != NULL && bestDist == dist) {
            if ((s8)((u8 *)best)[1] == (s8)oy) {
                prefer = (s8)((u8 *)best)[0] < (s8)ox;
            } else {
                prefer = (s8)((u8 *)best)[1] < (s8)oy;
            }
            if (prefer == 0) {
                continue;
            }
        }
        bestDist = dist;
        best = other;
    }
    if (best != NULL) {
        result = best;
    } else {
        result = self;
    }
    *(void **)((u8 *)self + 0x10) = result;
    return best != NULL;
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
s32 fn_8011C164(void *self) {
    void *TargetList_GetAt(void *, s32);
    extern u8 gTargetList[];
    s16 bestDist;
    void *best;
    s32 i;
    void *other;
    s32 dy;
    s32 dx;
    s16 dist;
    u8 prefer;
    void *result;
    u32 oy;
    u32 ox;
    u32 sy;
    u32 sx;

    bestDist = 0x7FFF;
    best = NULL;
    for (i = 0; i < *(s32 *)gTargetList; i++) {
        other = TargetList_GetAt(gTargetList, i);
        if (self == other) {
            continue;
        }
        ox = ((u8 *)other)[0];
        sx = ((u8 *)self)[0];
        if ((s8)sx >= (s8)ox) {
            continue;
        }
        oy = ((u8 *)other)[1];
        sy = ((u8 *)self)[1];
        dy = (s8)sy - (s8)oy;
        if ((s8)sy - (s8)oy < 0) {
            dy = -dy;
        }
        dx = (s8)sx - (s8)ox;
        if (dx < 0) {
            dx = -dx;
        }
        dist = (s16)(dx + dy);
        if (bestDist < dist) {
            continue;
        }
        if (best != NULL && bestDist == dist) {
            if ((s8)((u8 *)best)[0] == (s8)ox) {
                prefer = (s8)oy < (s8)((u8 *)best)[1];
            } else {
                prefer = (s8)((u8 *)best)[0] < (s8)ox;
            }
            if (prefer == 0) {
                continue;
            }
        }
        bestDist = dist;
        best = other;
    }
    if (best != NULL) {
        result = best;
    } else {
        result = self;
    }
    *(void **)((u8 *)self + 0x8) = result;
    return best != NULL;
}
#pragma global_optimizer on
s32 fn_8011C2B8(void *self) {
    void *TargetList_GetAt(void *, s32);
    extern u8 gTargetList[];
    s16 bestDist;
    void *best;
    s32 i;
    void *other;
    s32 dy;
    s32 dx;
    s16 dist;
    u8 prefer;
    void *result;
    u32 oy;
    u32 ox;
    u32 sy;
    u32 sx;

    bestDist = 0x7FFF;
    best = NULL;
    for (i = 0; i < *(s32 *)gTargetList; i++) {
        other = TargetList_GetAt(gTargetList, i);
        if (self == other) {
            continue;
        }
        oy = ((u8 *)other)[1];
        sy = ((u8 *)self)[1];
        if ((s8)sy <= (s8)oy) {
            continue;
        }
        dy = (s8)sy - (s8)oy;
        if ((s8)sy - (s8)oy < 0) {
            dy = -dy;
        }
        ox = ((u8 *)other)[0];
        sx = ((u8 *)self)[0];
        dx = (s8)sx - (s8)ox;
        if ((s8)sx - (s8)ox < 0) {
            dx = -dx;
        }
        dist = (s16)(dx + dy);
        if (bestDist < dist) {
            continue;
        }
        if (best != NULL && bestDist == dist) {
            if ((s8)((u8 *)best)[1] == (s8)oy) {
                prefer = (s8)ox < (s8)((u8 *)best)[0];
            } else {
                prefer = (s8)oy < (s8)((u8 *)best)[1];
            }
            if (prefer == 0) {
                continue;
            }
        }
        bestDist = dist;
        best = other;
    }
    if (best != NULL) {
        result = best;
    } else {
        result = self;
    }
    *(void **)((u8 *)self + 0xC) = result;
    return best != NULL;
}
#pragma global_optimizer off
s32 fn_8011C404(void *self) {
    void *TargetList_GetAt(void *, s32);
    extern u8 gTargetList[];
    s16 bestDist;
    void *best;
    s32 i;
    u8 *op;
    void *other;
    s32 dy;
    s32 dx;
    s16 dist;
    u8 prefer;
    void *result;
    u32 sx;
    u32 sy;
    u32 ox;
    u32 oy;

    bestDist = 0x7FFF;
    best = NULL;
    for (i = 0; i < *(s32 *)gTargetList; i++) {
        other = TargetList_GetAt(gTargetList, i);
        if (self == other) {
            continue;
        }
        op = (u8 *)other;
        ox = op[0];
        sx = ((u8 *)self)[0];
        if ((s8)sx <= (s8)ox) {
            continue;
        }
        oy = op[1];
        sy = ((u8 *)self)[1];
        dy = (s8)sy - (s8)oy;
        if ((s8)sy - (s8)oy < 0) {
            dy = -dy;
        }
        dx = (s8)sx - (s8)ox;
        if (dx < 0) {
            dx = -dx;
        }
        dist = (s16)(dx + dy);
        if (bestDist < dist) {
            continue;
        }
        if (best != NULL && bestDist == dist) {
            if ((s8)((u8 *)best)[0] == (s8)ox) {
                prefer = (s8)((u8 *)best)[1] < (s8)oy;
            } else {
                prefer = (s8)ox < (s8)((u8 *)best)[0];
            }
            if (prefer == 0) {
                continue;
            }
        }
        bestDist = dist;
        best = other;
    }
    if (best != NULL) {
        result = best;
    } else {
        result = self;
    }
    *(void **)((u8 *)self + 0x4) = result;
    return best != NULL;
}
#pragma global_optimizer on
void *fn_8011C558(void *arg0, s16 arg1) {
    void Heap_Free(void *);

    if (arg0 != NULL) {
        *(void **)arg0 = lbl_80292230;
        if (arg0 != NULL) {
            *(void **)arg0 = lbl_8028FDB0;
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

s32 BgWin_OnCancel(void) {
    M2C_UNK fn_800D758C(s32);
    extern s32 gBgWin;
    fn_800D758C(gBgWin);
    return 0;
}

s32 BgWin_OnOk(void)
{
    extern u8 *gBgWin;

    extern void fn_800D758C(void *);
    extern s32 fn_8011C9E4(void *);
    extern void fn_800DA894(s32, s32, s32);

    u8 *obj;
    s32 value1;
    s32 value2;
    s32 value3;

    fn_800D758C(gBgWin);

    obj = gBgWin;
    value3 = fn_8011C9E4(*(void **)(obj + 0x42C));

    obj = gBgWin;
    value2 = fn_8011C9E4(*(void **)(obj + 0x428));

    obj = gBgWin;
    value1 = fn_8011C9E4(*(void **)(obj + 0x424));

    fn_800DA894(value1, value2, value3);

    return 0;
}

void fn_8011C64C(void *arg0, s32 arg1) {
    void fn_8011CAAC(s32, s32, s32);
    fn_8011CAAC(*(s32 *)((u8 *)arg0 + 0x428), arg1, 0);
}

void fn_8011C674(void *arg0, s32 arg1) {
    void fn_8011CAAC(s32, s32, s32);
    fn_8011CAAC(*(s32 *)((u8 *)arg0 + 0x424), arg1, 0);
}

void *BgWin_Create(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    /* Construct the ztool BgWin window and wire its Terrain/Sky/Obj/Ok/Cancel controls. */
    void String_ConcatCStr(void *, void *, char *);
    void *fn_800D75FC(void *, void *);
    void fn_800D764C(void *, s32, s32, s32, void *, void *);
    void fn_800E3F54(void *);
    extern char BgWin_str[];
    extern u8 BgWin_vtable[];
    extern void BgWin_OnOk(void);
    extern void BgWin_OnCancel(void);
    String pathBase;
    String dbxPath;
    String winName;
    String terrainBox;
    String skyBox;
    String objBox;
    String okBtn;
    String cancelBtn;
    void *sp20;
    void *sp1C;
    void *sp18;
    void *sp14;
    void *sp10;
    void *spC;
    void *sp8;
    void *temp;
    void *self;

    self = arg0;
    String_Init(&pathBase, BgWin_str, &sp20);
    String_ConcatCStr(&dbxPath, &pathBase, BgWin_str + 7);
    String_Init(&winName, BgWin_str + 0x11, &sp1C);
    fn_800D764C(self, arg1, arg2, arg3, &dbxPath, &winName);
    String_Destroy(&winName, -1);
    String_Destroy(&dbxPath, -1);
    String_Destroy(&pathBase, -1);
    *(void **)((u8 *)self + 0xC) = BgWin_vtable;
    String_Init(&terrainBox, BgWin_str + 0x17, &sp18);
    *(void **)((u8 *)self + 0x424) = fn_800D75FC(self, &terrainBox);
    String_Destroy(&terrainBox, -1);
    String_Init(&skyBox, BgWin_str + 0x22, &sp14);
    *(void **)((u8 *)self + 0x428) = fn_800D75FC(self, &skyBox);
    String_Destroy(&skyBox, -1);
    String_Init(&objBox, BgWin_str + 0x29, &sp10);
    *(void **)((u8 *)self + 0x42C) = fn_800D75FC(self, &objBox);
    String_Destroy(&objBox, -1);
    String_Init(&okBtn, BgWin_str + 0x30, &spC);
    temp = fn_800D75FC(self, &okBtn);
    *(void **)((u8 *)self + 0x430) = temp;
    *(void **)((u8 *)self + 0x418) = temp;
    String_Destroy(&okBtn, -1);
    String_Init(&cancelBtn, BgWin_str + 0x36, &sp8);
    temp = fn_800D75FC(self, &cancelBtn);
    *(void **)((u8 *)self + 0x434) = temp;
    *(void **)((u8 *)self + 0x41C) = temp;
    String_Destroy(&cancelBtn, -1);
    temp = *(void **)((u8 *)self + 0x430);
    *(void **)((u8 *)temp + 0xA4) = (void *)BgWin_OnOk;
    temp = *(void **)((u8 *)self + 0x434);
    *(void **)((u8 *)temp + 0xA4) = (void *)BgWin_OnCancel;
    *(void **)((u8 *)self + 0x14) = *(void **)((u8 *)self + 0x424);
    *(void **)((u8 *)self + 0x54) = *(void **)((u8 *)self + 0x428);
    *(void **)((u8 *)self + 0x94) = *(void **)((u8 *)self + 0x42C);
    *(void **)((u8 *)self + 0xD4) = *(void **)((u8 *)self + 0x430);
    *(void **)((u8 *)self + 0x414) = *(void **)((u8 *)self + 0x424);
    fn_800E3F54(*(void **)((u8 *)self + 0x424));
    return self;
}

void *fn_8011C8DC(void *arg0, s16 arg1) {
#pragma global_optimizer off
    extern u8 lbl_8028FDD0[];
    void Heap_Free(void *);
    void *fn_800CA6C8(void *, s16);
    void fn_800E45EC(void *, s16);
    u8 *p;

    if (arg0 != NULL) {
        p = (u8 *)arg0;
        *(void **)(p + 0x40) = lbl_8028FDD0;
        if (p + 0xB8)
            if (p + 0xB8)
                if (p + 0xB8)
                    if (*(void **)(p + 0xC0))
                        Heap_Free(*(void **)(p + 0xC0));
        if (p + 0xAC)
            if (p + 0xAC)
                fn_800CA6C8(p + 0xAC, 0);
        fn_800E45EC(arg0, 0);
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
#pragma global_optimizer reset
}

void *fn_8011C984(void *arg0, u32 arg1) {
    u32 count;
    void **array;

    count = *(u32 *)((u8 *)arg0 + 0xBC);

    if (arg1 < count) {
        array = *(void ***)((u8 *)arg0 + 0xC0);
        return array[arg1];
    }

    return NULL;
}

void fn_8011C9A8(void *arg0, s32 arg1) {
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;

    M2C_FIELD(arg0, s32 *, 0xEC) = arg1;
    temp_r6 = M2C_FIELD(arg0, s32 *, 0xF4);
    temp_r4 = M2C_FIELD(arg0, s32 *, 0xF8);
    temp_r5 = M2C_FIELD(arg0, s32 *, 0xEC);
    if (temp_r5 >= (s32) (temp_r6 + temp_r4)) {
        M2C_FIELD(arg0, s32 *, 0xF4) = (s32) ((temp_r5 - temp_r4) + 1);
        return;
    }
    if (temp_r5 < temp_r6) {
        M2C_FIELD(arg0, s32 *, 0xF4) = temp_r5;
    }
}

s32 fn_8011C9E4(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xEC);
}

s32 fn_8011C9EC(s32 arg0) {
    return arg0 + 0xAC;
}

M2C_UNK *fn_8011C9F4(void *arg0) {
    extern u8 lbl_80274A88[];
    u32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, u32 *, 0xEC);
    if (temp_r4 < (u32) M2C_FIELD(arg0, u32 *, 0xB0)) {
        return (M2C_UNK *)String_CStr((void *)(M2C_FIELD(arg0, s32 *, 0xB4) + (temp_r4 * 0xC)));
    }
    return (M2C_UNK *)lbl_80274A88;
}

extern void fn_800CA91C(void *arg0);
extern void fn_800DD598(s32 arg0, s32 arg1, u8 *arg2);
#pragma global_optimizer off
void fn_8011CA3C(void *arg0, void *arg1) {
    void fn_800CA91C(void *);
    void fn_800DD598(void *, void *, void *, u8 *);
    u8 sp8;

    fn_800CA91C((char *)arg0 + 0xAC);
    *(s32 *)((char *)arg0 + 0xBC) = 0;
    if ((void *)((char *)arg0 + 0xAC) != arg1) {
        sp8 = *(u8 *)((char *)&sp8 + 4);
        fn_800DD598((char *)arg0 + 0xAC,
                    *(void **)((char *)arg1 + 8),
                    (char *)*(void **)((char *)arg1 + 8) + *(s32 *)((char *)arg1 + 4) * 0xC,
                    &sp8);
    }
}
#pragma global_optimizer on
void fn_8011CAAC(void *arg0, void *arg1, void *arg2)
{
    extern void fn_800CA18C(void *, void *, s32, void *);
    extern void fn_800C9BC4(void *, void *, s32, void *);

    u8 *obj;
    u8 *source;
    u8 *destination;
    void *value;

    obj = (u8 *)arg0;
    value = arg2;

    source = *(u8 **)(obj + 0xB4);
    source += *(s32 *)(obj + 0xB0) * 0xC;

    fn_800CA18C(
        obj + 0xAC,
        source,
        1,
        arg1
    );

    destination = *(u8 **)(obj + 0xC0);
    destination += *(s32 *)(obj + 0xBC) * 4;

    fn_800C9BC4(
        obj + 0xB8,
        destination,
        1,
        &value
    );
}

void fn_8011CB18(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0xF0) = 0;
    M2C_FIELD(arg0, s32 *, 0x64) = (s32) M2C_FIELD(arg0, s32 *, 0xC8);
}

void fn_8011CB2C(void *arg0) {
    M2C_UNK (*temp_r12)();

    M2C_FIELD(arg0, s8 *, 0xF0) = 0;
    M2C_FIELD(arg0, s32 *, 0x64) = (s32) M2C_FIELD(arg0, s32 *, 0xC8);
    temp_r12 = M2C_FIELD(arg0, M2C_UNK (**)(), 0xFC);
    if (temp_r12 != NULL) {
        temp_r12();
    }
}

void fn_8011CB6C(void *arg0, s32 arg1, s32 arg2) {
    s32 t48;
    u8 flag;
    s32 t4c;
    s32 x;
    s32 t64;
    s32 y;
    s32 t60;
    s32 tc8;

    t48 = *(s32 *)((u8 *)arg0 + 0x48);
    flag = 0;
    t4c = *(s32 *)((u8 *)arg0 + 0x4C);
    x = arg1 - t48;
    t64 = *(s32 *)((u8 *)arg0 + 0x64);
    y = arg2 - t4c;
    t60 = *(s32 *)((u8 *)arg0 + 0x60);
    tc8 = *(s32 *)((u8 *)arg0 + 0xC8);
    *(s32 *)((u8 *)arg0 + 0xCC) = flag;
    *(s32 *)((u8 *)arg0 + 0xD0) = tc8;
    *(s32 *)((u8 *)arg0 + 0xD4) = t60;
    *(s32 *)((u8 *)arg0 + 0xD8) = t64;
    if (x >= *(s32 *)((u8 *)arg0 + 0xCC) && x <= *(s32 *)((u8 *)arg0 + 0xD4) &&
        y >= *(s32 *)((u8 *)arg0 + 0xD0) && y <= *(s32 *)((u8 *)arg0 + 0xD8)) {
        flag = 1;
    }
    if (flag != 0) {
        *(s32 *)((u8 *)arg0 + 0xEC) = (y / 16) - 1;
        if (*(u32 *)((u8 *)arg0 + 0xEC) >= *(u32 *)((u8 *)arg0 + 0xB0)) {
            *(s32 *)((u8 *)arg0 + 0xEC) = *(s32 *)((u8 *)arg0 + 0xB0) - 1;
        }
    }
}

#pragma global_optimizer off
void fn_8011CC04(u8 *arg0) {
    s32 a;
    s32 b;
    s32 shifted;
    s32 base;

    arg0[0xF0] = 1;
    a = *(s32 *)(arg0 + 0xB0);
    b = *(s32 *)(arg0 + 0xF8);
    if (a > b) {
        a = b;
    }
    shifted = a << 4;
    base = *(s32 *)(arg0 + 0xC8);
    *(s32 *)(arg0 + 0x64) = base + shifted + 2;
}
#pragma global_optimizer reset
void ListBox_HandleInput(void *list) {
    void Win_UpdatePos(void *);
    void Win_SetDirty(void *);
    extern void *gPadInput;
    void *owner;
    u32 buttons;

    /* Move list-box cursor with D-pad (1/10 steps) and keep the scroll window in range. */
    Win_UpdatePos(list);
    owner = M2C_FIELD(list, void **, 0x0);
    buttons = M2C_FIELD(gPadInput, u32 *, 0xC);
    if (M2C_FIELD(list, u8 *, 0xF0) != 0) {
        if (buttons & 8) {
            M2C_FIELD(list, s32 *, 0xEC) -= 1;
        } else if (buttons & 4) {
            M2C_FIELD(list, s32 *, 0xEC) += 1;
        } else if (buttons & 1) {
            M2C_FIELD(list, s32 *, 0xEC) -= 10;
        } else if (buttons & 2) {
            M2C_FIELD(list, s32 *, 0xEC) += 10;
        }
        if (M2C_FIELD(list, s32 *, 0xEC) < 0) {
            M2C_FIELD(list, s32 *, 0xEC) = 0;
        }
        if (M2C_FIELD(list, s32 *, 0xEC) >= M2C_FIELD(list, s32 *, 0xB0)) {
            M2C_FIELD(list, s32 *, 0xEC) = M2C_FIELD(list, s32 *, 0xB0) - 1;
        }
        if (M2C_FIELD(list, s32 *, 0xEC) >= M2C_FIELD(list, s32 *, 0xF4) + M2C_FIELD(list, s32 *, 0xF8)) {
            M2C_FIELD(list, s32 *, 0xF4) = M2C_FIELD(list, s32 *, 0xEC) - M2C_FIELD(list, s32 *, 0xF8) + 1;
        } else if (M2C_FIELD(list, s32 *, 0xEC) < M2C_FIELD(list, s32 *, 0xF4)) {
            M2C_FIELD(list, s32 *, 0xF4) = M2C_FIELD(list, s32 *, 0xEC);
        }
        Win_SetDirty(owner);
    }
}

#pragma optimization_level 3
void *fn_8011D118(void *arg0, void *arg1, void *xml) {
    void fn_800E4688(void *);
    void Xml_GetChildValue(char *, void *);
    u8 Xml_AdvanceChild(void *);
    void String_Init(String *, char *, void *);
    void String_Destroy(String *, s32);
    void fn_800CA18C(void *, void *, s32, void *);
    void fn_800C9BC4(void *, void *, s32, void *);
    extern u8 lbl_8028FDD0[];
    char childVal[0x18];
    String name;
    s32 idx;
    char tmp;
    char *pChild;
    u8 *self;

    self = (u8 *)arg0;
    fn_800E4688(self);
    pChild = childVal;
    *(void **)(self + 0x40) = lbl_8028FDD0;
    *(s32 *)(self + 0xAC) = 0;
    *(s32 *)(self + 0xB0) = 0;
    *(s32 *)(self + 0xB4) = 0;
    *(s32 *)(self + 0xB8) = 0;
    *(s32 *)(self + 0xBC) = 0;
    *(s32 *)(self + 0xC0) = 0;
    *(s32 *)(self + 0xD8) = 0;
    *(s32 *)(self + 0xD4) = 0;
    *(s32 *)(self + 0xD0) = 0;
    *(s32 *)(self + 0xCC) = 0;
    *(s32 *)(self + 0xE8) = 0;
    *(s32 *)(self + 0xE4) = 0;
    *(s32 *)(self + 0xE0) = 0;
    *(s32 *)(self + 0xDC) = 0;

    while (Xml_AdvanceChild(xml)) {
        Xml_GetChildValue(childVal, xml);
        String_Init(&name, pChild, &tmp);
        idx = 0;
        fn_800CA18C(self + 0xAC, *(u8 **)(self + 0xB4) + *(s32 *)(self + 0xB0) * 12, 1, &name);
        fn_800C9BC4(self + 0xB8, *(u8 **)(self + 0xC0) + (*(s32 *)(self + 0xBC) << 2), 1, &idx);
        String_Destroy(&name, -1);
    }

    *(s32 *)(self + 0x68) = 8;
    *(s32 *)(self + 0x6C) = 1;
    *(s32 *)(self + 0xC4) = *(s32 *)(self + 0x60);
    *(s32 *)(self + 0xC8) = *(s32 *)(self + 0x64);
    *(s32 *)(self + 0xFC) = 0;
    {
        s32 n = *(s32 *)(self + 0xB0);
        s32 w = *(s32 *)(self + 0x60);
        s32 c8 = *(s32 *)(self + 0xC8);
        *(s32 *)(self + 0xCC) = 0;
        *(s32 *)(self + 0xD0) = c8;
        *(s32 *)(self + 0xD4) = w;
        *(s32 *)(self + 0xD8) = c8 + (n << 4) + 2;
        w = *(s32 *)(self + 0x60);
        *(s32 *)(self + 0xDC) = w - 0x10;
        *(s32 *)(self + 0xE0) = 0;
        *(s32 *)(self + 0xE4) = w;
        *(s32 *)(self + 0xE8) = 0x10;
        *(s32 *)(self + 0xEC) = 0;
        self[0xF0] = 0;
        *(s32 *)(self + 0xF4) = 0;
        *(s32 *)(self + 0xF8) = 0xA;
    }
    return self;
}
#pragma optimization_level reset
void fn_8011D2AC(void *arg0) {
 void **fn_8007C3BC(void *); void *fn_8007BC3C(void *,s32,s32,u16,void *);
 u8 fn_80109B24(void *); void fn_80079300(void *,u8); void fn_800791F0(void *,void *); void fn_80120F94(void);
 s32 i; u8 *unit=(u8 *)arg0+0x30; u8 *self=*(u8 **)((u8 *)arg0+0x18); u8 *entry;
 for(i=0;i<4;i++) {
 if(*(void **)(self+0x48+i*4)==0) {
 u8 *info; u8 flag; u8 v; void *obj;
 if(gUiInputFlags&3) *(u16 *)(self+0x5c)=0x180;
 info=*fn_8007C3BC(unit); flag=0;
 if((s8)info[3]==(s8)info[5] && (s32)info[4]==0x4c) flag=1;
 if(!flag) *(u16 *)(self+0x5c)|=0x4000;
 obj=fn_8007BC3C(unit,0,0,*(u16 *)(self+0x5c),self);
 entry=self+i*4; *(void **)(entry+0x48)=obj; *(u16 *)(self+0x5c)=0x82;
 if(*(void **)(self+0x58) && fn_80109B24(*(void **)(self+0x58))!=0 && fn_80109B24(*(void **)(self+0x58))!=255) v=fn_80109B24(*(void **)(self+0x58)); else v=255;
 (*(u8 **)(entry+0x48))[0x41]=v-0x4d;
 fn_80079300(*(void **)(entry+0x48),self[0x5e]);
 if(!(gUiInputFlags&3)) fn_800791F0(*(void **)(entry+0x48),self);
 { s32 s=(s8)self[0x5e]; u8 t=self[0x5e]; if(s!=(s8)t) { self[0x65]=t; self[0x5e]=s; fn_80120F94(); } }
 break;
 }}
}

void fn_8011D428(void *arg0) {
    void *fn_8007C3BC(void *);
    char *strcat(char *, s32);
    char *strcpy(char *, char *);
    void fn_8005C8B4(char *);
    extern u8 TalkUi_str[];
    char sp8[0x40];

    strcpy(sp8, (char *)TalkUi_str + 0x2F);
    strcat(sp8, *(s32 *)((char *)fn_8007C3BC((u8 *)arg0 + 0x30) + 8));
    fn_8005C8B4(sp8);
}

u32 fn_8011D484(void) {
    void *Process_Find(void *);
    extern u8 gUiPanelProc[];
    void *p;
    u32 v;

    p = Process_Find(gUiPanelProc);
    if (p != NULL) {
        v = *(u32 *)((u8 *)p + 0x58);
        if (v != 0U) {
            return v;
        }
    }
    return 0U;
}

void fn_8011D4C8(void) {
    void fn_80122C84(void *);
    void fn_8007AD6C(void *);
    void fn_80109020(void *);
    void Process_Unlink(void *);
    void fn_80120F0C(void);
    void fn_800AA208(void);
    void *Process_Find(void *);
    extern u8 gUiPanelProc[];
    extern u32 lbl_80367A5C;
    u8 *p;
    s32 i;
    u8 *self;
    self=Process_Find(gUiPanelProc);
    if(self) {
    i=0; p=self;
    do {
        void *obj=*(void **)(p+0x34);
        if(obj) { fn_80122C84(obj); *(void **)(p+0x34)=0; }
        i++; p+=4;
    } while(i<4);
    i=0; p=self;
    do {
        void *obj=*(void **)(p+0x48);
        if(obj) { fn_8007AD6C(obj); *(void **)(p+0x48)=0; }
        i++; p+=4;
    } while(i<4);
    *(s32 *)(self+0x30)=0;
    if(lbl_80367A5C) { fn_80109020((void *)lbl_80367A5C); lbl_80367A5C=0; }
    if(*(void **)(self+0x58)) { Process_Unlink(*(void **)(self+0x58)); *(void **)(self+0x58)=0; }
    fn_80120F0C();
    if(gUiPanelFlags&0x80) { fn_800AA208(); gUiPanelFlags &= ~0x80; }
    gUiPanelFlags=0;
    gUiInputFlags &= ~2;
    Process_Unlink(self);
    }
}

void fn_8011D5EC(void) {
    extern u8 gUiPanelProc[];
    extern u16 gUiPanelFlags;
    void *Process_Find(void *);
    void UiPanel_ClearShowFlags(u16 *);
    void Process_Goto(void *, s32);
    u8 *obj;

    obj = Process_Find(gUiPanelProc);
    UiPanel_ClearShowFlags(&gUiPanelFlags);
    *(u32 *)(obj + 0x30) = *(u32 *)(obj + 0x30) + 2;
    gUiPanelFlags &= ~0x10;
    Process_Goto(obj, 1);
}

void fn_8011D650(void) {
    extern u8 gUiPanelProc[];
    extern u16 gUiPanelFlags;
    extern s32 gUiInputFlags;
    void *Process_Find(void *);
    void UiPanel_ClearShowFlags(u16 *);
    void Process_MarkActive(void *);
    void Process_Goto(void *, s32);
    void UiPanel_PollSkip(u16 *);
    void UiPanel_Finish(void *);
    void Process_Unlink(void *);
    void fn_80013864(void);
    void *obj;
    u32 flags;

    obj = Process_Find(gUiPanelProc);
    UiPanel_ClearShowFlags(&gUiPanelFlags);
    Process_MarkActive(obj);
    *(s32 *)((u8 *)obj + 0x30) = *(s32 *)((u8 *)obj + 0x30) + 2;
    flags = gUiPanelFlags;
    flags &= ~0x10;
    gUiPanelFlags = flags;
    Process_Goto(obj, 1);
    UiPanel_PollSkip(&gUiPanelFlags);
    if (gUiInputFlags & 3) {
        UiPanel_Finish(obj);
        if (!(gUiPanelFlags & 0x10)) {
            Process_Unlink(obj);
        }
    } else {
        fn_80013864();
    }
}

void fn_8011D6F4(s32 arg0) {
    extern u8 gUiPanelProc[];
    extern u16 gUiPanelFlags;
    extern s32 gUiInputFlags;
    void *Process_Find(void *);
    void UiPanel_ClearShowFlags(u16 *);
    void Process_MarkActive(void *);
    void Process_Goto(void *, s32);
    void UiPanel_PollSkip(u16 *);
    void UiPanel_Finish(void *);
    void Process_Unlink(void *);
    void fn_80013864(void);
    void *obj;
    u32 flags;

    obj = Process_Find(gUiPanelProc);
    UiPanel_ClearShowFlags(&gUiPanelFlags);
    Process_MarkActive(obj);
    *(s32 *)((u8 *)obj + 0x30) = arg0;
    flags = gUiPanelFlags;
    flags &= ~0x10;
    gUiPanelFlags = flags;
    Process_Goto(obj, 1);
    UiPanel_PollSkip(&gUiPanelFlags);
    if (gUiInputFlags & 3) {
        UiPanel_Finish(obj);
        if (!(gUiPanelFlags & 0x10)) {
            Process_Unlink(obj);
        }
    } else {
        fn_80013864();
    }
}

extern u16 TalkUi_str[];
extern u16 gTalkUiLastMsg[];
extern u16 gUiPanelProc[];
/* Expand msg, show it on the UI panel, then finish sync or yield. */
void TalkUi_ShowMsg(void *msg) {
    s32 DebugPrint(const char *, ...);
    void *Msg_Expand(void *);
    void Str_CopyPad(void *, const void *, s32);
    extern u16 gUiPanelFlags;
    extern s32 gUiInputFlags;
    void *Process_Find(void *);
    void UiPanel_ClearShowFlags(u16 *);
    void Process_MarkActive(void *);
    void Process_Goto(void *, s32);
    void UiPanel_PollSkip(u16 *);
    void UiPanel_Finish(void *);
    void Process_Unlink(void *);
    void fn_80013864(void);
    void *expanded;
    void *panel;
    u32 flags;

    DebugPrint((char *)TalkUi_str + 0x35, msg);
    expanded = Msg_Expand(msg);
    Str_CopyPad(gTalkUiLastMsg, msg, 0x1E);
    panel = Process_Find(gUiPanelProc);
    UiPanel_ClearShowFlags(&gUiPanelFlags);
    Process_MarkActive(panel);
    *(void **)((u8 *)panel + 0x30) = expanded;
    flags = gUiPanelFlags;
    flags &= ~0x10;
    gUiPanelFlags = flags;
    Process_Goto(panel, 1);
    UiPanel_PollSkip(&gUiPanelFlags);
    if (gUiInputFlags & 3) {
        UiPanel_Finish(panel);
        if (!(gUiPanelFlags & 0x10)) {
            Process_Unlink(panel);
        }
    } else {
        fn_80013864();
    }
}

void fn_8011D87C(void *arg0)
{
    s32 DebugPrint(const char *, ...);
    void *Msg_Expand(void *);
    void Str_CopyPad(void *, const void *, s32);
    void *Process_Find(void *);
    void Process_Goto(void *, u8);

    void *result;
    u8 *obj;
    u16 flags;

    DebugPrint((char *)TalkUi_str + 0x35, arg0);

    result = Msg_Expand(arg0);

    Str_CopyPad(gTalkUiLastMsg, arg0, 0x1E);

    obj = (u8 *)Process_Find(gUiPanelProc);
    *(void **)(obj + 0x30) = result;

    flags = gUiPanelFlags;
    flags &= ~0x10;
    gUiPanelFlags = flags;

    Process_Goto(obj, 1);
}

void fn_8011D908(void *msg, void *parent) {
    s32 DebugPrint(const char *, ...);
    void *Msg_Expand(void *);
    void Str_CopyPad(void *, const void *, s32);
    void UiPanel_ClearFlags(u16 *);
    void *Process_CreateEx(void *, void *);
    void fn_8012205C(void *);
    void UiPanel_PollSkip(u16 *);
    void UiPanel_Finish(void *);
    void Process_Unlink(void *);
    void fn_80013864(void);
    extern u16 TalkUi_str[];
    extern u16 gTalkUiLastMsg[];
    extern u16 gUiPanelFlags;
    extern u16 gUiPanelProc[];
    extern u8 lbl_8032BDE8[];
    extern s32 gUiInputFlags;
    void *expanded;
    u8 *panel;

    DebugPrint((char *)TalkUi_str + 0x52, msg);
    expanded = Msg_Expand(msg);
    Str_CopyPad(gTalkUiLastMsg, msg, 0x1E);
    UiPanel_ClearFlags(&gUiPanelFlags);
    panel = (u8 *)Process_CreateEx(gUiPanelProc, parent);
    *(s32 *)(panel + 0x34) = 0;
    *(s32 *)(panel + 0x38) = 0;
    *(s32 *)(panel + 0x3C) = 0;
    *(s32 *)(panel + 0x40) = 0;
    *(s32 *)(panel + 0x48) = 0;
    *(s32 *)(panel + 0x4C) = 0;
    *(s32 *)(panel + 0x50) = 0;
    *(s32 *)(panel + 0x54) = 0;
    *(s32 *)(panel + 0x58) = 0;
    *(s32 *)(panel + 0x44) = 0;
    *(s8 *)(panel + 0x5E) = -1;
    *(s8 *)(panel + 0x65) = -1;
    *(void **)(panel + 0x30) = expanded;
    panel[0x5F] = 1;
    *(s16 *)(panel + 0x68) = 0x10B;
    panel[0x63] = 0;
    *(s16 *)(panel + 0x5C) = 0x82;
    panel[0x61] = 0;
    panel[0x60] = 0;
    panel[0x62] = 1;
    fn_8012205C(lbl_8032BDE8);
    panel[0x66] = 1;
    UiPanel_PollSkip(&gUiPanelFlags);
    if (gUiInputFlags & 1) {
        UiPanel_Finish(panel);
        if (!(gUiPanelFlags & 0x10)) {
            Process_Unlink(panel);
        }
    } else {
        fn_80013864();
    }
}

void UiPanel_Create(void *owner, void *parent) {
    void UiPanel_ClearFlags(void *);
    void *Process_CreateEx(void *, void *);
    void fn_8012205C(void *);
    void UiPanel_PollSkip(void *);
    void UiPanel_Finish(void *);
    void Process_Unlink(void *);
    void fn_80013864(void);
    extern u16 gUiPanelFlags;
    extern u16 gUiPanelProc[];
    extern u8 lbl_8032BDE8[];
    extern s32 gUiInputFlags;
    u8 *panel;

    /* Create the UI panel process, init its slots, and run or yield for input. */
    UiPanel_ClearFlags(&gUiPanelFlags);
    panel = (u8 *)Process_CreateEx(gUiPanelProc, parent);
    *(s32 *)(panel + 0x34) = 0;
    *(s32 *)(panel + 0x38) = 0;
    *(s32 *)(panel + 0x3C) = 0;
    *(s32 *)(panel + 0x40) = 0;
    *(s32 *)(panel + 0x48) = 0;
    *(s32 *)(panel + 0x4C) = 0;
    *(s32 *)(panel + 0x50) = 0;
    *(s32 *)(panel + 0x54) = 0;
    *(s32 *)(panel + 0x58) = 0;
    *(s32 *)(panel + 0x44) = 0;
    *(s8 *)(panel + 0x5E) = -1;
    *(s8 *)(panel + 0x65) = -1;
    *(void **)(panel + 0x30) = owner;
    panel[0x5F] = 1;
    *(s16 *)(panel + 0x68) = 0x10B;
    panel[0x63] = 0;
    *(s16 *)(panel + 0x5C) = 0x82;
    panel[0x61] = 0;
    panel[0x60] = 0;
    panel[0x62] = 1;
    fn_8012205C(lbl_8032BDE8);
    panel[0x66] = 1;
    UiPanel_PollSkip(&gUiPanelFlags);
    if (gUiInputFlags & 1) {
        UiPanel_Finish(panel);
        if (!(gUiPanelFlags & 0x10)) {
            Process_Unlink(panel);
        }
    } else {
        fn_80013864();
    }
}

void fn_8011DB48(void *arg0) {
 void *Process_Find(void *); void *fn_80122998(void *); void *fn_80122CE0(void *);
 void fn_80122E34(void *,u32); void fn_80122E28(void *,s32,s32); void fn_80122E10(void *,s32);
 void fn_80122E04(void *,u32,u32); void fn_80122E20(void *,u32); void fn_80122E18(void *,u32); void fn_80122DFC(void *,u32);
 void fn_80122DEC(void *,u32,s32,s32); void *Sound_Create(void *,void *); void Sound_FadeFromZero(void *,u8);
 extern u16 gUiPanelProc[]; extern u32 lbl_80367A5C;
 s32 i; u8 *item; u8 *data=arg0; u8 *panel; u8 *entry;
 panel=Process_Find(gUiPanelProc); item=0;
 for(i=(s32)item;i<4;i++) {
 if (((void **)(panel+i*4))[13]==0) {
 void *slot=fn_80122998(panel);
 entry=panel+i*4;
 *(void **)(entry+0x34)=slot;
 slot=fn_80122CE0(*(void **)(entry+0x34));
 *(void **)(panel+0x44)=*(void **)(entry+0x34);
 item=slot; break;
 }}
 fn_80122E34(item,*(u32 *)(data+8));
 fn_80122E28(item,*(s16 *)(data+0x14),*(s16 *)(data+0x16));
 fn_80122E10(item,*(s16 *)(data+0x1c));
 fn_80122E04(item,data[0x1e],data[0x1f]);
 fn_80122E20(item,data[0x20]); fn_80122E18(item,data[0x21]); fn_80122DFC(item,data[0x22]);
 item[0x6a]=data[0x23];
 fn_80122DEC(item,*(u32 *)(data+0x10),*(s16 *)(data+0x18),*(s16 *)(data+0x1a));
 item[0x6b]=data[0x25]; lbl_80367A5C=*(u32 *)(data+0xc);
 panel[0x63]=data[0x24]!=0;
 if(data[0x24]==0 && *(void **)(data+0xc)!=0) Sound_FadeFromZero(Sound_Create(*(void **)(data+0xc),panel),(u8)*(s16 *)(panel+0x68));
}

void fn_8011DCB4(void) {
    M2C_UNK fn_8008A290(M2C_UNK, M2C_UNK);
    fn_8008A290(2, 0x10B);
}

void fn_8011DCDC(void *arg0) {
    fn_8008A290(3, M2C_FIELD(arg0, s16 *, 0x68));
}

void fn_8011DD08(void *arg0) {
    s32 fn_8008A56C();
    if (fn_8008A56C() & 2) {
        if (fn_8008A56C() & 4) {
            M2C_FIELD(arg0, s8 *, 0x64) = 2;
            return;
        }
        if (fn_8008A56C() & 8) {
            M2C_FIELD(arg0, s8 *, 0x64) = 5;
            return;
        }
        goto block_5;
    }
block_5:
    fn_8008A290(3, M2C_FIELD(arg0, s16 *, 0x68));
    M2C_FIELD(arg0, s8 *, 0x64) = 2;
}

void fn_8011DD80(void *arg0)
{
    void fn_800AA1CC(void *);
    void Sound_Create(void *, void *);

    extern u16 gUiPanelFlags;
    extern void *lbl_80367A5C;

    void *ptr;

    fn_800AA1CC(arg0);

    gUiPanelFlags |= 0x80;

    ptr = lbl_80367A5C;

    if (ptr != 0) {
        Sound_Create(ptr, arg0);
    }
}

extern u32 lbl_80367A5C;
void fn_8011DDCC(void *arg0) {
    void fn_80122C84(void *);
    void fn_8007AD6C(void *);
    void fn_80109020(void *);
    void Process_Unlink(void *);
    void fn_80120F0C(void);
    void fn_800AA208(void);
    u8 *self = arg0;
    u8 *p;
    s32 i;
    s32 zero;
    for(i=0,p=self,zero=i;i<4;i++,p+=4) {
        void *obj=*(void **)(p+0x34);
        if(obj) { fn_80122C84(obj); *(s32 *)(p+0x34)=zero; }
    }
    for(i=0,p=self,zero=i;i<4;i++,p+=4) {
        void *obj=*(void **)(p+0x48);
        if(obj) { fn_8007AD6C(obj); *(s32 *)(p+0x48)=zero; }
    }
    *(s32 *)(self+0x30)=0;
    if(lbl_80367A5C) { fn_80109020((void *)lbl_80367A5C); lbl_80367A5C=0; }
    if(*(void **)(self+0x58)) { Process_Unlink(*(void **)(self+0x58)); *(void **)(self+0x58)=0; }
    fn_80120F0C();
    if(gUiPanelFlags&0x80) { fn_800AA208(); gUiPanelFlags &= ~0x80; }
    { u32 flags=gUiInputFlags & ~2; gUiPanelFlags=0; gUiInputFlags=flags; }
}

void UiPanel_Finish(void *arg0) {
    void Process_Goto(void *, s32);
    void Process_Unlink(void *);
    void fn_800790D4(void *, void *);
    void fn_8007AD6C(void *);
    void fn_80089650(s32, s32);
    void fn_800AA208(void);
    void fn_80109020(void *);
    void *Sound_FindByName(void *);
    void fn_80109BB4(void *, u8);
    void fn_8011E12C(void *);
    void fn_80120F0C(void);
    void fn_80120F94(void);
    void fn_80122000(void *);
    void fn_80122238(void *, void *);
    void fn_80122C84(void *);
    extern u8 lbl_8032BDE8[];
    void *self;
    void *p;
    s32 i;
    s32 zero;

    self = arg0;
    while (!(gUiPanelFlags & 0x20)) {
        fn_8011E12C(self);
    }
    if (gUiPanelFlags & 0x10) {
        Process_Goto(self, 2);
        return;
    }
    fn_80122000(lbl_8032BDE8);
    if ((gUiInputFlags & 2) && (*(u8 *)((u8 *)self + 0x63) != 0) && !(gUiInputFlags & 1)) {
        fn_80089650(2, 0x85);
    }
    if (gUiInputFlags & 3) {
        i = 0;
        p = self;
        zero = i ^ i;
        do {
            void *obj = *(void **)((u8 *)p + 0x34);
            if (obj != NULL) {
                fn_80122C84(obj);
                *(s32 *)((u8 *)p + 0x34) = zero;
            }
            i += 1;
            p = (u8 *)p + 4;
        } while (i < 4);
        i = 0;
        p = self;
        zero = i ^ i;
        do {
            void *obj = *(void **)((u8 *)p + 0x48);
            if (obj != NULL) {
                fn_8007AD6C(obj);
                *(s32 *)((u8 *)p + 0x48) = zero;
            }
            i += 1;
            p = (u8 *)p + 4;
        } while (i < 4);
        *(s32 *)((u8 *)self + 0x30) = 0;
        if (lbl_80367A5C != 0) {
            fn_80109020((void *)lbl_80367A5C);
            lbl_80367A5C = 0;
        }
        if (*(void **)((u8 *)self + 0x58) != NULL) {
            Process_Unlink(*(void **)((u8 *)self + 0x58));
            *(s32 *)((u8 *)self + 0x58) = 0;
        }
        fn_80120F0C();
        if (gUiPanelFlags & 0x80) {
            fn_800AA208();
            *(volatile u16 *)&gUiPanelFlags &= ~0x80;
        }
        {
            s32 t = gUiInputFlags;
            *(volatile u16 *)&gUiPanelFlags = 0;
            gUiInputFlags = t & ~2;
            Process_Goto(self, 4);
        }
        return;
    }
    if (*(u8 *)((u8 *)self + 0x63) != 0) {
        Process_Goto(self, 3);
        return;
    }
    fn_80120F94();
    {
        void *p2;
        s32 i2;
        i2 = 0;
        p2 = self;
        do {
            void *obj = *(void **)((u8 *)p2 + 0x34);
            if (obj != NULL) {
                fn_80122238(obj, self);
            }
            i2 += 1;
            p2 = (u8 *)p2 + 4;
        } while (i2 < 4);
    }
    {
        void *p2;
        s32 i2;
        i2 = 0;
        p2 = self;
        do {
            void *obj = *(void **)((u8 *)p2 + 0x48);
            if (obj != NULL) {
                if (gUiInputFlags & 3) {
                    fn_8007AD6C(obj);
                } else {
                    fn_800790D4(obj, self);
                }
            }
            i2 += 1;
            p2 = (u8 *)p2 + 4;
        } while (i2 < 4);
    }
    if (lbl_80367A5C != 0) {
        fn_80109BB4(Sound_FindByName((void *)lbl_80367A5C), (u8)((*(s16 *)((u8 *)self + 0x68) * 0x3C) / 1000));
    }
}

#pragma use_lmw_stmw on
s32 fn_8011E12C(void *arg0) {
    u8 fn_8011E4B8(void *, void *, u16);
    void Process_ClearFunc(void *);
    u8 fn_801229C4(void *);
    void fn_801226D0(void *, void *);
    void fn_801222A4(void *, void *);
    void fn_80121D60(void *, void *);
    void Ui_SetTooltip(void *, s32, s32, void *);
    u8 fn_80109B24(void *);
    void Obj_StartTintEase(void *, u8);
    void fn_80122114(void *, u8);
    void fn_80122A2C(void *, u8);
    extern u16 gUiPanelFlags;
    extern u8 lbl_8032BDE8[];
    struct Item {
        u8 pad[0x34];
        void **unk34;
        f32 unk38;
        f32 unk3C;
        u8 pad40[3];
        u8 unk43;
    };
    struct Obj {
        u8 pad0[0x30];
        u8 *text;
        void *pad34[4];
        void *unk44;
        struct Item *items[4];
        void *unk58;
        u8 pad5C[2];
        u8 unk5E;
        u8 pad5F;
        u8 unk60;
        u8 pad61;
        u8 unk62;
        u8 pad63[2];
        u8 unk65;
        u8 pad66;
        u8 unk67;
    };
    struct Sda {
        u16 unk0;
        u16 unk2;
    };
    struct Obj *self;
    struct Sda *sda;
    struct Item *slot;
    u16 old;
    s32 code;
    s8 idx;
    struct Item *it;
    s32 i;
    u8 ch;
    u8 v;
    u8 *text;
    struct Obj *cur;

    self = (struct Obj *)arg0;
    sda = (struct Sda *)&gUiPanelFlags;
    old = sda->unk2;
    sda->unk2 = (u16)(old + 1);
    code = (u8)fn_8011E4B8(self, &self->text, old);
    if (code == 2) {
        goto ret2;
    }
    if (code >= 3) {
        goto def;
    }
    if (code == 0) {
        Process_ClearFunc(self);
        return 0;
    }
    goto def;
ret2:
    return 2;
def:
    if (fn_801229C4(self->unk44) != 0) {
        fn_801226D0(self->unk44, self);
        return 2;
    }
    if (*(u8 *)((u8 *)self->unk44 + 0x68) == 0) {
        fn_801222A4(self->unk44, self);
        return 2;
    }
    ch = self->unk5E;
    if ((s8)ch < 0) {
        idx = -1;
    } else if (self->items[0] != 0 && (s8)self->items[0]->unk43 == (s8)ch) {
        idx = 0;
    } else if (self->items[1] != 0 && (s8)self->items[1]->unk43 == (s8)ch) {
        idx = 1;
    } else if (self->items[2] != 0 && (s8)self->items[2]->unk43 == (s8)ch) {
        idx = 2;
    } else if (self->items[3] != 0 && (s8)self->items[3]->unk43 == (s8)ch) {
        idx = 3;
    } else {
        idx = -1;
    }
    if ((s8)idx < 0) {
        slot = 0;
    } else {
        slot = self->items[idx];
    }
    if (slot != 0) {
        fn_80121D60(lbl_8032BDE8, *slot->unk34);
        if (self->unk67 == 0) {
            self->unk67 = 1;
            Ui_SetTooltip(*slot->unk34, (s32)slot->unk38, (s32)slot->unk3C, self);
            ch = self->unk5E;
            if ((s8)self->unk65 != (s8)ch) {
                self->unk65 = ch;
                cur = self;
                i = 0;
                do {
                    it = *(struct Item **)((u8 *)cur + 0x48);
                    if (it != 0) {
                        if ((s8)it->unk43 == (s8)self->unk5E) {
                            if (self->unk58 != 0 && fn_80109B24(self->unk58) != 0
                                && (u8)fn_80109B24(self->unk58) != 0xFF) {
                                v = fn_80109B24(self->unk58);
                            } else {
                                v = 0xFF;
                            }
                            Obj_StartTintEase(*(void **)((u8 *)cur + 0x48), v);
                        } else {
                            if (self->unk58 != 0 && fn_80109B24(self->unk58) != 0
                                && (u8)fn_80109B24(self->unk58) != 0xFF) {
                                v = fn_80109B24(self->unk58);
                            } else {
                                v = 0xFF;
                            }
                            Obj_StartTintEase(*(void **)((u8 *)cur + 0x48), (u8)(v - 0x4D));
                        }
                    }
                    i += 1;
                    cur = (struct Obj *)((u8 *)cur + 4);
                } while (i < 4);
            }
        }
    }
    text = self->text;
    ch = *text;
    if ((s8)ch >= 0x20 && (s8)ch < 0x7F) {
        fn_80122114(lbl_8032BDE8, ch);
        text = self->text;
        self->text = text + 1;
        fn_80122A2C(self->unk44, *text);
    } else {
        fn_80122114(lbl_8032BDE8, ch);
        text = self->text;
        self->text = text + 1;
        fn_80122A2C(self->unk44, *text);
        fn_80122114(lbl_8032BDE8, *self->text);
        text = self->text;
        self->text = text + 1;
        fn_80122A2C(self->unk44, *text);
    }
    self->unk60 = self->unk62;
    return 3;
}
#pragma use_lmw_stmw reset

u8 fn_8011E4B8(void *arg0, void *arg1, u16 arg2)
{
    extern u16 gUiPanelFlags;
    extern s32 gUiInputFlags;
    extern u32 lbl_80367A5C;
    extern s32 gBattleState[];
    extern u8 lbl_8032BDE8[];
    extern u8 lbl_8032FE24[];
    extern u16 TalkUi_str[];

    void fn_801220B8(void *);
    void fn_801229F8(void *);
    void fn_80121D60(void *, void *);
    void Ui_SetTooltip(void *, s32, s32, void *);
    u8 fn_80109B24(void *);
    void Obj_StartTintEase(void *, u8);
    s32 fn_80010710(u8 *);
    void fn_80122114(void *, u8);
    void fn_80122A2C(void *, u8);
    void TalkUi_SpawnKeyWait2(void *, void *, u8);
    void fn_801225D4(void *, void *);
    s32 TalkUi_LayoutSlot(void *, u32);
    void fn_80120F94(void);
    void *fn_80049DA4(s32, s32, u32);
    void fn_8011FB58(void *, s32);
    void fn_80122238(void *, void *);
    void fn_8007AD6C(void *);
    void fn_800790D4(void *, void *);
    void fn_80079198(void *, void *);
    void fn_800791F0(void *, void *);
    void fn_801222A4(void *, void *);
    void fn_80122170(void *, void *, s32);
    u8 fn_8011F184(void *, u8 **);
    void *Sound_FindByName(void *);
    void Sound_FadeToVol(void *, s32);
    void Sound_FadeFromZero(void *, s32);
    void *Sound_Create(void *, void *);
    void Process_Goto(void *, s32);
    void Process_DetachChild(void *);
    s32 Str_Cmp(void *, void *);
    void *fn_8014D8FC(void *);
    void fn_8008A290(s32, s32);

    struct Item {
        u8 pad[0x34];
        void **unk34;
        f32 unk38;
        f32 unk3C;
        u8 pad40[3];
        u8 unk43;
    };
    struct Obj {
        u8 pad0[0x18];
        void *unk18;
        u8 pad1C[0x14];
        u8 *text;
        void *pad34[4];
        void *unk44;
        struct Item *items[4];
        void *unk58;
        u8 pad5C[2];
        s8 unk5E;
        u8 pad5F;
        u8 unk60;
        u8 pad61;
        u8 unk62;
        u8 unk63;
        u8 unk64;
        u8 unk65;
        u8 unk66;
        u8 unk67;
        s16 unk68;
    };

    struct Obj *self;
    u8 *text;
    struct Item *item;
    u8 *buffer;
    u8 *soundName;
    void *object;
    void *sound;
    s32 ch;
    s32 command;
    s32 index;
    u8 selected;
    s32 count;
    s32 i;
    struct Obj *cur;
    s32 result;
    u8 color;
    s32 speed;
    u8 oldSlot;
    s8 idx;
    s32 bit;

    self = (struct Obj *)arg0;

    text = *((u8 **)arg1);
    ch = *text;

    if ((s8)ch == 0) {
        gUiPanelFlags |= 0x20;
        return 0;
    }

    if ((s8)ch == 0xA) {
        fn_801220B8(lbl_8032BDE8);
        fn_801229F8(self->unk44);
        text = *((u8 **)arg1);
        *((u8 **)arg1) = text + 1;
        return 1;
    }

    if ((s8)ch == '#') {
        selected = self->unk5E;
        if ((s8)selected < 0) {
            idx = -1;
        } else if (self->items[0] != 0 && (s8)self->items[0]->unk43 == (s8)selected) {
            idx = 0;
        } else if (self->items[1] != 0 && (s8)self->items[1]->unk43 == (s8)selected) {
            idx = 1;
        } else if (self->items[2] != 0 && (s8)self->items[2]->unk43 == (s8)selected) {
            idx = 2;
        } else if (self->items[3] != 0 && (s8)self->items[3]->unk43 == (s8)selected) {
            idx = 3;
        } else {
            idx = -1;
        }

        if (idx < 0) {
            item = 0;
        } else {
            item = self->items[idx];
        }

        if (item != 0) {
            fn_80121D60(lbl_8032BDE8, *item->unk34);
            if (self->unk67 == 0) {
                self->unk67 = 1;
                Ui_SetTooltip(*item->unk34, (s32)item->unk38, (s32)item->unk3C, self);
                if ((s8)self->unk65 != (s8)self->unk5E) {
                    self->unk65 = self->unk5E;
                    cur = self;
                    i = 0;
                    do {
                        item = *(struct Item **)((u8 *)cur + 0x48);
                        if (item != 0) {
                            if ((s8)item->unk43 == (s8)self->unk5E) {
                                if (self->unk58 != 0 && fn_80109B24(self->unk58) != 0
                                    && (u8)fn_80109B24(self->unk58) != 0xFF) {
                                    color = fn_80109B24(self->unk58);
                                } else {
                                    color = 0xFF;
                                }
                                Obj_StartTintEase(*(void **)((u8 *)cur + 0x48), color);
                            } else {
                                if (self->unk58 != 0 && fn_80109B24(self->unk58) != 0
                                    && (u8)fn_80109B24(self->unk58) != 0xFF) {
                                    color = fn_80109B24(self->unk58);
                                } else {
                                    color = 0xFF;
                                }
                                Obj_StartTintEase(*(void **)((u8 *)cur + 0x48), (u8)(color - 0x4D));
                            }
                        }
                        i += 1;
                        cur = (struct Obj *)((u8 *)cur + 4);
                    } while (i < 4);
                }
            }
        }

        count = fn_80010710(*((u8 **)arg1));
        i = 0;
        while (i < count) {
            text = *((u8 **)arg1);
            fn_80122114(lbl_8032BDE8, *text);
            object = self->unk44;
            text = *((u8 **)arg1);
            *((u8 **)arg1) = text + 1;
            fn_80122A2C(object, *text);
            i++;
        }
        return 1;
    }

    if ((s8)ch != '$') {
        return 3;
    }

    text = *((u8 **)arg1);
    *((u8 **)arg1) = text + 1;
    text = *((u8 **)arg1);
    *((u8 **)arg1) = text + 1;
    command = (s8)*text;

    switch (command) {
    case 'K':
        self->unk60 = 0;
        text = *((u8 **)arg1);
        TalkUi_SpawnKeyWait2(self->unk44, self, (s8)text[1] == 'P');
        return 2;

    case 'P':
    clear_box:
        fn_801220B8(lbl_8032BDE8);
        object = self->unk44;
        if (object != 0) {
            fn_801225D4(object, self);
        }
        return 2;

    case 'c':
        text = *((u8 **)arg1);
        *((u8 **)arg1) = text + 1;
        index = (u8)(*text - '0');
        *((u8 **)arg1) -= 3;
        TalkUi_LayoutSlot(self, index);
        text = *((u8 **)arg1);
        *((u8 **)arg1) = text + 3;
        oldSlot = self->unk5E;
        if ((s8)oldSlot != index) {
            self->unk65 = oldSlot;
            self->unk5E = (s8)index;
            fn_80120F94();
        }
        buffer = lbl_8032FE24;
        for (buffer = lbl_8032FE24; (s8)**((u8 **)arg1) != '|'; ++buffer) { *buffer = *(*((u8 **)arg1))++; }
        *buffer = 0;
        text = *((u8 **)arg1);
        *((u8 **)arg1) = text + 1;
        object = fn_80049DA4((s32)((u8 *)TalkUi_str + 0x6F), (s32)lbl_8032FE24, 0);
        fn_8011FB58(self, (s32)object);
        return 2;

    case 'd':
        text = *((u8 **)arg1);
        *((u8 **)arg1) = text + 1;
        index = (u8)(*text - '0');
        *((u8 **)arg1) -= 3;
        TalkUi_LayoutSlot(self, index);
        text = *((u8 **)arg1);
        *((u8 **)arg1) = text + 3;
        oldSlot = self->unk5E;
        if ((s8)oldSlot == index) {
            result = 0;
        } else {
            self->unk65 = oldSlot;
            self->unk5E = (s8)index;
            fn_80120F94();
            result = 1;
        }
        if ((u8)result == 0) {
            fn_80120F94();
        }
        if (!(gUiInputFlags & 3)) {
            fn_80122238(self->unk44, self);
        }
        selected = self->unk5E;
        if ((s8)selected < 0) {
            idx = -1;
        } else if (self->items[0] != 0 && (s8)self->items[0]->unk43 == (s8)selected) {
            idx = 0;
        } else if (self->items[1] != 0 && (s8)self->items[1]->unk43 == (s8)selected) {
            idx = 1;
        } else if (self->items[2] != 0 && (s8)self->items[2]->unk43 == (s8)selected) {
            idx = 2;
        } else if (self->items[3] != 0 && (s8)self->items[3]->unk43 == (s8)selected) {
            idx = 3;
        } else {
            idx = -1;
        }
        if (gUiInputFlags & 3) {
            fn_8007AD6C(self->items[idx]);
        } else {
            fn_800790D4(self->items[idx], self);
        }
        self->items[idx] = 0;
        self->unk5E = -1;
        return 2;

    case 's':
        text = *((u8 **)arg1);
        *((u8 **)arg1) = text + 1;
        index = (u8)(*text - '0');
        if ((s8)self->unk5E != index) {
            self->unk65 = self->unk5E;
            self->unk5E = (s8)index;
            fn_80120F94();
        }
        object = self->pad34[index];
        if (object != 0 && *(u8 *)((u8 *)object + 0x68) != 0) {
            *((u8 **)arg1) -= 3;
            TalkUi_LayoutSlot(self, index);
            *((u8 **)arg1) += 3;
            goto clear_box;
        }
        return 1;

    case 'W':
        text = *((u8 **)arg1);
        ch = *text;
        switch ((s8)ch) {
        case 'D':
            *((u8 **)arg1) = text + 1;
            if (!(gUiInputFlags & 3)) {
                fn_80122238(self->unk44, self);
            }
            fn_80120F94();
            return 2;
        case '-':
            *((u8 **)arg1) = text + 1;
            if (!(gUiInputFlags & 3)) {
                if (lbl_80367A5C != 0) {
                    sound = Sound_FindByName((void *)lbl_80367A5C);
                    Sound_FadeToVol(sound, 8);
                }
                i = 0;
                cur = self;
                do {
                    object = *(void **)((u8 *)cur + 0x34);
                    if (object != 0) fn_80122238(object, self);
                    i++;
                    cur = (struct Obj *)((u8 *)cur + 4);
                } while (i < 4);
                i = 0;
                cur = self;
                do {
                    object = *(void **)((u8 *)cur + 0x48);
                    if (object != 0) fn_80079198(object, self);
                    i++;
                    cur = (struct Obj *)((u8 *)cur + 4);
                } while (i < 4);
            }
            return 2;
        case '+':
            *((u8 **)arg1) = text + 1;
            if (!(gUiInputFlags & 3)) {
                if (lbl_80367A5C != 0) {
                    sound = Sound_FindByName((void *)lbl_80367A5C);
                    Sound_FadeFromZero(sound, 8);
                }
                i = 0;
                cur = self;
                do {
                    object = *(void **)((u8 *)cur + 0x34);
                    if (object != 0) fn_801222A4(object, self);
                    i++;
                    cur = (struct Obj *)((u8 *)cur + 4);
                } while (i < 4);
                i = 0;
                cur = self;
                do {
                    object = *(void **)((u8 *)cur + 0x48);
                    if (object != 0) fn_800791F0(object, self);
                    i++;
                    cur = (struct Obj *)((u8 *)cur + 4);
                } while (i < 4);
            }
            return 2;
        default:
            text = *((u8 **)arg1);
            *((u8 **)arg1) = text + 1;
            index = (u8)(*text - '0');
            result = TalkUi_LayoutSlot(self, index);
            return (u8)result ? 2 : 1;
        }

    case 'w':
        self->unk60 = 0;
        text = *((u8 **)arg1);
        object = self->unk44;
        *((u8 **)arg1) = text + 1;
        index = (s8)*text - '0';
        fn_80122170(object, self, 1 << index);
        bit = gUiPanelFlags & 0x200;
        return 2 + ((-bit | bit) >> 31);

    case 'Y':
        return 2;

    case 'F':
        return fn_8011F184(self, ((u8 **)arg1));

    case 'R':
        buffer = lbl_8032FE24;
        for (buffer = lbl_8032FE24; (s8)**((u8 **)arg1) != '|'; ++buffer) { *buffer = *(*((u8 **)arg1))++; }
        *buffer = 0;
        text = *((u8 **)arg1);
        *((u8 **)arg1) = text + 1;
        sound = fn_80049DA4((s32)((u8 *)TalkUi_str + 0x74), (s32)lbl_8032FE24, 0);
        Sound_Create(sound, self);
        if (self->unk63 != 0 && !(gUiInputFlags & 3)) {
            Process_Goto(self, 0);
            return 2;
        }
        return 1;

    case '<':
        fn_8008A290(self->unk64, self->unk68);
        return 1;

    case '>':
        fn_8008A290(3, self->unk68);
        return 1;

    case 'B':
        buffer = lbl_8032FE24;
        for (buffer = lbl_8032FE24; (s8)**((u8 **)arg1) != '|'; ++buffer) { *buffer = *(*((u8 **)arg1))++; }
        *buffer = 0;
        text = *((u8 **)arg1);
        *((u8 **)arg1) = text + 1;
        soundName = lbl_8032FE24;
        if (Str_Cmp(soundName, (u8 *)TalkUi_str + 0x79) == 0) {
            soundName = (u8 *)TalkUi_str + 0x82;
            object = fn_8014D8FC(gBattleState);
            if (object != 0) {
                soundName = *(u8 **)((u8 *)object + 0x50) + 4;
            }
        }
        if (!(gUiInputFlags & 3)) {
            sound = fn_80049DA4((s32)((u8 *)TalkUi_str + 0x74), (s32)soundName, 0);
            self->unk58 = Sound_Create(sound, self);
        }
        return 1;

    case 'U':
        if (self->unk18 == 0) {
            text = *((u8 **)arg1);
            *((u8 **)arg1) = text + 1;
            return 1;
        }
        text = *((u8 **)arg1);
        switch ((s8)*text) {
        case 'b':
            gUiPanelFlags |= 0x100;
        case 'B':
            ++*((u8 **)arg1);
            Process_DetachChild(self);
            return 1;
        default:
            goto invalid_command;
        }

    case 'H':
        self->unk60 = 0;
        text = *((u8 **)arg1);
        *((u8 **)arg1) = text - 2;
        gUiPanelFlags |= 0x30;
        return 2;

    case 'D':
        text = *((u8 **)arg1);
        if ((s8)*text == 'C') {
            *((u8 **)arg1) = text + 1;
            gUiPanelFlags |= 8;
            return 1;
        }
        goto invalid_command;

    case 'S':
        text = *((u8 **)arg1);
        ch = *text;
        if ((s8)ch == 'D') {
            *((u8 **)arg1) = text + 1;
            gUiPanelFlags |= 8;
            return 1;
        }
        if ((s8)ch == 'E') {
            *((u8 **)arg1) = text + 1;
            gUiPanelFlags &= ~8;
            return 1;
        }
    case 'N':
        text = *((u8 **)arg1);
        if ((s8)*text == 'D') {
            *((u8 **)arg1) = text + 1;
            gUiPanelFlags ^= 0x40;
            return 1;
        }
        fn_801220B8(lbl_8032BDE8);
        fn_801229F8(self->unk44);
        return 1;

    case 'M':
        text = *((u8 **)arg1);
        switch ((s8)*text) {
        case 'C':
            self->unk62 = 0;
            ++*((u8 **)arg1);
            break;
        case 'D':
            self->unk62 = 1;
            ++*((u8 **)arg1);
            break;
        }
        return 1;

    case 'O':
        text = *((u8 **)arg1);
        *((u8 **)arg1) = text + 1;
        self->unk66 = (u8)(*text - '0');
        return 1;

    case '=':
        text = *((u8 **)arg1);
        *((u8 **)arg1) = text + 1;
        self->unk68 = ((s8)*text - '0') * 1000;
        text = *((u8 **)arg1);
        speed = self->unk68;
        *((u8 **)arg1) = text + 1;
        self->unk68 = speed + ((s8)*text - '0') * 100;
        text = *((u8 **)arg1);
        speed = self->unk68;
        *((u8 **)arg1) = text + 1;
        self->unk68 = speed + ((s8)*text - '0') * 10;
        text = *((u8 **)arg1);
        speed = self->unk68;
        *((u8 **)arg1) = text + 1;
        self->unk68 = speed + ((s8)*text - '0');
        if (self->unk68 == 9999) {
            self->unk68 = 0x10B;
        }
        return 1;

    case 'G':
        fn_80121D60(lbl_8032BDE8, (u8 *)TalkUi_str + 0x8E);
        return 1;

    default:
        break;
    }
invalid_command:
    return 3;
}

s32 fn_8011F184(void *self,u8 **text) {
void fn_80120F94(void);
s32 fn_80049DA4(void *,void *,s32);
void fn_8011FB58(void *,s32);
void fn_800790D4(void *,void *);
void fn_8007AD6C(void *);
void fn_8007AD08(void *,s32,s32);
extern u8 lbl_8032FE24[];
s32 slot,want,c;
u8 previous;
void *child;
char *out;
previous=M2C_FIELD(self,u8 *,0x5e);
want=(s8)previous;
if(want<0) slot=-1;
else {
 child=M2C_FIELD(self,void **,0x48);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=0;
 else {child=M2C_FIELD(self,void **,0x4c);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=1;
 else {child=M2C_FIELD(self,void **,0x50);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=2;
 else {child=M2C_FIELD(self,void **,0x54);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=3; else slot=-1;
 }}}
}
if((s8)slot<0) child=0; else child=((void **)((u8 *)self + (s8)slot * 4))[18];

c=(s8)**text;
if(c>='0' && c<='9') {
if(want!=c-'0') {
M2C_FIELD(self,u8 *,0x65)=previous;
M2C_FIELD(self,u8 *,0x5e)=c-'0';
fn_80120F94();
}
++*text;
return 1;
}
c=(s8)*(*text)++;
switch(c) {
case 'C':
want=M2C_FIELD(self,s8 *,0x5e);
if(want<0) slot=-1;
else {
 child=M2C_FIELD(self,void **,0x48);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=0;
 else {child=M2C_FIELD(self,void **,0x4c);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=1;
 else {child=M2C_FIELD(self,void **,0x50);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=2;
 else {child=M2C_FIELD(self,void **,0x54);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=3; else slot=-1;
 }}}
}
if((s8)slot<0) child=0; else child=((void **)((u8 *)self + (s8)slot * 4))[18];

if(child) *text-=2;
else {
out=(char *)lbl_8032FE24;
while((s32)**text!='|') *out++=*(*text)++;
*out=0; ++*text;
fn_8011FB58(self,fn_80049DA4((u8 *)TalkUi_str+0x6f,lbl_8032FE24,0));
}
return 2;
case 'D':
want=M2C_FIELD(self,s8 *,0x5e);
if(want<0) slot=-1;
else {
 child=M2C_FIELD(self,void **,0x48);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=0;
 else {child=M2C_FIELD(self,void **,0x4c);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=1;
 else {child=M2C_FIELD(self,void **,0x50);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=2;
 else {child=M2C_FIELD(self,void **,0x54);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=3; else slot=-1;
 }}}
}

if(!(gUiInputFlags&3)) {
fn_800790D4(((void **)((u8 *)self + (s8)slot * 4))[18],self);fn_80120F94();
} else fn_8007AD6C(((void **)((u8 *)self + (s8)slot * 4))[18]);
((void **)((u8 *)self + (s8)slot * 4))[18]=0;
M2C_FIELD(self,s8 *,0x5e)=-1;return 2;
case 'S':
if(child) M2C_FIELD(child,u16 *,0x46)&=~0x202;
else M2C_FIELD(self,u16 *,0x5c)&=~0x202;
return 1;
case 'A':
if(child) {M2C_FIELD(child,u16 *,0x46)&=~0x202;M2C_FIELD(child,u16 *,0x46)|=2;}
else {M2C_FIELD(self,u16 *,0x5c)&=~0x202;M2C_FIELD(self,u16 *,0x5c)|=2;}
return 1;
case 'f':
want=M2C_FIELD(self,s8 *,0x5e);
if(want<0) slot=-1;
else {
 child=M2C_FIELD(self,void **,0x48);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=0;
 else {child=M2C_FIELD(self,void **,0x4c);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=1;
 else {child=M2C_FIELD(self,void **,0x50);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=2;
 else {child=M2C_FIELD(self,void **,0x54);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=3; else slot=-1;
 }}}
}
if((s8)slot<0) child=0; else child=((void **)((u8 *)self + (s8)slot * 4))[18];
fn_8007AD08(child,2,-1);
return 1;
case 's':
want=M2C_FIELD(self,s8 *,0x5e);
if(want<0) slot=-1;
else {
 child=M2C_FIELD(self,void **,0x48);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=0;
 else {child=M2C_FIELD(self,void **,0x4c);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=1;
 else {child=M2C_FIELD(self,void **,0x50);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=2;
 else {child=M2C_FIELD(self,void **,0x54);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=3; else slot=-1;
 }}}
}
if((s8)slot<0) child=0; else child=((void **)((u8 *)self + (s8)slot * 4))[18];
fn_8007AD08(child,1,-1);
return 1;
case 'd':
want=M2C_FIELD(self,s8 *,0x5e);
if(want<0) slot=-1;
else {
 child=M2C_FIELD(self,void **,0x48);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=0;
 else {child=M2C_FIELD(self,void **,0x4c);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=1;
 else {child=M2C_FIELD(self,void **,0x50);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=2;
 else {child=M2C_FIELD(self,void **,0x54);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=3; else slot=-1;
 }}}
}
if((s8)slot<0) child=0; else child=((void **)((u8 *)self + (s8)slot * 4))[18];
fn_8007AD08(child,1,1);
return 1;
case 'c':
if(child) {
want=M2C_FIELD(self,s8 *,0x5e);
if(want<0) slot=-1;
else {
 child=M2C_FIELD(self,void **,0x48);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=0;
 else {child=M2C_FIELD(self,void **,0x4c);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=1;
 else {child=M2C_FIELD(self,void **,0x50);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=2;
 else {child=M2C_FIELD(self,void **,0x54);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=3; else slot=-1;
 }}}
}
if((s8)slot<0) child=0; else child=((void **)((u8 *)self + (s8)slot * 4))[18];
fn_8007AD08(child,-1,3);
} else M2C_FIELD(self,u16 *,0x5c)|=4;
return 1;
case 'h':
if(child) {
want=M2C_FIELD(self,s8 *,0x5e);
if(want<0) slot=-1;
else {
 child=M2C_FIELD(self,void **,0x48);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=0;
 else {child=M2C_FIELD(self,void **,0x4c);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=1;
 else {child=M2C_FIELD(self,void **,0x50);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=2;
 else {child=M2C_FIELD(self,void **,0x54);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=3; else slot=-1;
 }}}
}
if((s8)slot<0) child=0; else child=((void **)((u8 *)self + (s8)slot * 4))[18];
fn_8007AD08(child,-1,4);
} else M2C_FIELD(self,u16 *,0x5c)|=8;
return 1;
case 'o':
if(child) {
want=M2C_FIELD(self,s8 *,0x5e);
if(want<0) slot=-1;
else {
 child=M2C_FIELD(self,void **,0x48);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=0;
 else {child=M2C_FIELD(self,void **,0x4c);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=1;
 else {child=M2C_FIELD(self,void **,0x50);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=2;
 else {child=M2C_FIELD(self,void **,0x54);
 if(child && M2C_FIELD(child,s8 *,0x43)==want) slot=3; else slot=-1;
 }}}
}
if((s8)slot<0) child=0; else child=((void **)((u8 *)self + (s8)slot * 4))[18];
fn_8007AD08(child,5,5);
} else M2C_FIELD(self,u16 *,0x5c)|=12;
return 1;
}
return 2;
}

void fn_8011FB58(void *arg0, s32 arg1) {
    s32 Str_Cmp(s32, void *);
    void *fn_8003A114(void *);
    void *fn_8003A064(void *);
    void *Unit_FindByName(void *);
    void **fn_8007C3BC(void *);
    void *fn_8007BC3C(void *, s32, s32, u16, void *);
    u8 fn_80109B24(void *);
    void fn_80079300(void *, u8);
    void fn_800791F0(void *, void *);
    void fn_80120F94(void);
    void strcpy(void *, void *);
    void strcat(void *, void *);
    s32 FileCache_Probe(void *);
    void *Process_CreateChild(void *, void *);
    void Str_CopyPad(void *, void *, s32);
    extern u16 TalkUi_str[];
    extern u8 gUiContext[24];
    extern s32 gUiInputFlags;
    extern u8 lbl_8028FED0[];
    void *unit;
    s32 i;
    void *p;
    u8 flag;
    void **infop;
    u8 *info;
    u8 v;
    u8 sp[0x40];
    s32 flags;
    void *tmp;
    void *self;
    s32 arg;

    self = arg0;
    arg = arg1;
    unit = (void *)arg;
    if (Str_Cmp(arg, (u8 *)TalkUi_str + 0x90) == 0) {
        unit = fn_8003A114(*(void **)gUiContext);
        goto got_unit;
    }
    if (Str_Cmp(arg, (u8 *)TalkUi_str + 0x97) == 0) {
        unit = fn_8003A064(*(void **)gUiContext);
        goto got_unit;
    }
    if (Str_Cmp(arg, (u8 *)TalkUi_str + 0x9F) == 0) {
        tmp = Unit_FindByName((u8 *)TalkUi_str + 0xA7);
        if (tmp != NULL) {
            unit = fn_8003A114(tmp);
            goto got_unit;
        }
    } else if (Str_Cmp(arg, (u8 *)TalkUi_str + 0xAF) == 0) {
        tmp = Unit_FindByName((u8 *)TalkUi_str + 0xA7);
        if (tmp != NULL) {
            unit = fn_8003A064(tmp);
            goto got_unit;
        }
    } else if (Str_Cmp(arg, (u8 *)TalkUi_str + 0xB9) == 0) {
        tmp = Unit_FindByName((u8 *)TalkUi_str + 0xC2);
        if (tmp != NULL) {
            unit = fn_8003A114(tmp);
            goto got_unit;
        }
    } else if (Str_Cmp(arg, (u8 *)TalkUi_str + 0xCB) == 0) {
        tmp = Unit_FindByName((u8 *)TalkUi_str + 0xC2);
        if (tmp != NULL) {
            unit = fn_8003A064(tmp);
            goto got_unit;
        }
    }
got_unit:
    flags = gUiInputFlags & 3;
    if (flags != 0) {
        p = self;
        i = 0;
        do {
            if (*(void **)((u8 *)p + 0x48) == NULL) {
                if (flags != 0) {
                    *(u16 *)((u8 *)self + 0x5C) = 0x180;
                }
                infop = fn_8007C3BC(unit);
                info = (u8 *)*infop;
                flag = 0;
                if ((s8)info[3] == (s8)info[5] && (s32)info[4] == 0x4C) {
                    flag = 1;
                }
                if (flag == 0) {
                    *(u16 *)((u8 *)self + 0x5C) |= 0x4000;
                }
                *(void **)((u8 *)self + 0x48 + i * 4) = fn_8007BC3C(unit, 0, 0, *(u16 *)((u8 *)self + 0x5C), self);
                *(u16 *)((u8 *)self + 0x5C) = 0x82;
                if (*(void **)((u8 *)self + 0x58) != NULL && fn_80109B24(*(void **)((u8 *)self + 0x58)) != 0
                    && fn_80109B24(*(void **)((u8 *)self + 0x58)) != 0xFF) {
                    v = fn_80109B24(*(void **)((u8 *)self + 0x58));
                } else {
                    v = 0xFF;
                }
                *(u8 *)((u8 *)*(void **)((u8 *)self + 0x48 + i * 4) + 0x41) = (u8)(v - 0x4D);
                fn_80079300(*(void **)((u8 *)self + 0x48 + i * 4), *(u8 *)((u8 *)self + 0x5E));
                if ((gUiInputFlags & 3) == 0) {
                    fn_800791F0(*(void **)((u8 *)self + 0x48 + i * 4), self);
                }
                {
                    u8 t = *(u8 *)((u8 *)self + 0x5E);
                    s8 s = (s8)t;
                    if (s != s) {
                        *(u8 *)((u8 *)self + 0x65) = t;
                        *(u8 *)((u8 *)self + 0x5E) = (u8)s;
                        fn_80120F94();
                    }
                }
                return;
            }
            p = (u8 *)p + 4;
            i += 1;
        } while (i < 4);
    } else {
        strcpy(sp, (u8 *)TalkUi_str + 0x2F);
        strcat(sp, *(void **)((u8 *)fn_8007C3BC(unit) + 8));
        if (FileCache_Probe(sp) & 0x2000) {
            p = self;
            i = 0;
            do {
                if (*(void **)((u8 *)p + 0x48) == NULL) {
                    if (gUiInputFlags & 3) {
                        *(u16 *)((u8 *)self + 0x5C) = 0x180;
                    }
                    infop = fn_8007C3BC(unit);
                    info = (u8 *)*infop;
                    flag = 0;
                    if ((s8)info[3] == (s8)info[5] && (s32)info[4] == 0x4C) {
                        flag = 1;
                    }
                    if (flag == 0) {
                        *(u16 *)((u8 *)self + 0x5C) |= 0x4000;
                    }
                    *(void **)((u8 *)self + 0x48 + i * 4) = fn_8007BC3C(unit, 0, 0, *(u16 *)((u8 *)self + 0x5C), self);
                    *(u16 *)((u8 *)self + 0x5C) = 0x82;
                    if (*(void **)((u8 *)self + 0x58) != NULL && fn_80109B24(*(void **)((u8 *)self + 0x58)) != 0
                        && fn_80109B24(*(void **)((u8 *)self + 0x58)) != 0xFF) {
                        v = fn_80109B24(*(void **)((u8 *)self + 0x58));
                    } else {
                        v = 0xFF;
                    }
                    *(u8 *)((u8 *)*(void **)((u8 *)self + 0x48 + i * 4) + 0x41) = (u8)(v - 0x4D);
                    fn_80079300(*(void **)((u8 *)self + 0x48 + i * 4), *(u8 *)((u8 *)self + 0x5E));
                    if ((gUiInputFlags & 3) == 0) {
                        fn_800791F0(*(void **)((u8 *)self + 0x48 + i * 4), self);
                    }
                    {
                        u8 t = *(u8 *)((u8 *)self + 0x5E);
                        s8 s = (s8)t;
                        if (s != s) {
                            *(u8 *)((u8 *)self + 0x65) = t;
                            *(u8 *)((u8 *)self + 0x5E) = (u8)s;
                            fn_80120F94();
                        }
                    }
                    return;
                }
                p = (u8 *)p + 4;
                i += 1;
            } while (i < 4);
        } else {
            Str_CopyPad((u8 *)Process_CreateChild(lbl_8028FED0, self) + 0x30, unit, 0x3A);
        }
    }
}

#pragma global_optimizer off
s32 TalkUi_LayoutSlot(void *talk, u32 slot) {
    s32 fn_801208BC(void *, u32);
    void fn_80108BD0(void *, s32, s32, s32);
    void fn_80122DD0(void *, s16, s16);
    void fn_80122E28(void *, s16, s16);
    void fn_801222A4(void *, void *);
    extern u16 TalkUi_str[];
    extern s16 lbl_80312060[];
    void *self;
    s32 width;
    u32 idx;
    s32 side;
    void *panel;
    s32 baseW;
    u8 *slotPtr;

    /* Position the talk window and portrait for speaker slot 0-3 from text width. */
    self = talk;
    slotPtr = (u8 *)self + ((slot << 2) & 0x3FC);
    *(void **)((u8 *)self + 0x44) = *(void **)(slotPtr + 0x34);
    idx = slot & 0xFF;
    panel = *(void **)((u8 *)self + 0x44);
    if ((u32)panel != 0 && *(u8 *)((u8 *)panel + 0x68) == 0) {
        baseW = fn_801208BC(*(void **)((u8 *)self + 0x30), idx) + 0xE0;
        switch (idx) {
        case 0:
            panel = *(void **)((u8 *)self + 0x34);
            width = baseW;
            if ((u32)panel != 0 && *(u8 *)((u8 *)panel + 0x6B) != 0) {
                if (baseW < 0x170) {
                    width = 0x170;
                }
                if (width > 0x230) {
                    width = 0x230;
                }
                fn_80108BD0((char *)TalkUi_str + 0xD6, 0x18, 0x14, width);
                panel = *(void **)((u8 *)self + 0x34);
                if ((u32)panel != 0) {
                    fn_80122DD0(panel, (s16)(width - 0x40), 0x7C);
                }
            }
            break;
        case 1:
            panel = *(void **)((u8 *)self + 0x38);
            width = baseW;
            if ((u32)panel != 0 && *(u8 *)((u8 *)panel + 0x6B) != 0) {
                if (baseW < 0x170) {
                    width = 0x170;
                }
                if (width > 0x230) {
                    width = 0x230;
                }
                fn_80108BD0((char *)TalkUi_str + 0xDF, 0x248 - width, 0x13C, width);
                fn_80122E28(*(void **)((u8 *)self + 0x38), (s16)(0x278 - width), 0x14C);
                panel = *(void **)((u8 *)self + 0x38);
                if ((u32)panel != 0) {
                    fn_80122DD0(panel, (s16)(0x288 - width), 0x1A4);
                }
            }
            break;
        case 2:
            panel = *(void **)((u8 *)self + 0x3C);
            side = baseW;
            if ((u32)panel != 0 && *(u8 *)((u8 *)panel + 0x6B) != 0) {
                width = 0x60;
                if (baseW < 0x170) {
                    side = 0x170;
                }
                if (side > 0x230) {
                    side = 0x230;
                }
                if (side + 0x60 > 0x230) {
                    width = 0x230 - side;
                }
                fn_80108BD0((char *)TalkUi_str + 0xE8, width + 0x18, 0xA0, side);
                fn_80122E28(*(void **)((u8 *)self + 0x3C), (s16)(width + 0xC0), 0xB0);
                lbl_80312060[6] = (s16)(width + 0x70);
                lbl_80312060[7] = 0x10F;
                lbl_80312060[8] = 1;
                panel = *(void **)((u8 *)self + 0x3C);
                if ((u32)panel != 0) {
                    s32 t = side - 0x40;
                    fn_80122DD0(panel, (s16)(width + t), 0x108);
                }
            }
            break;
        case 3:
            panel = *(void **)((u8 *)self + 0x40);
            width = baseW;
            if ((u32)panel != 0 && *(u8 *)((u8 *)panel + 0x6B) != 0) {
                side = 0x60;
                if (baseW < 0x170) {
                    width = 0x170;
                }
                if (width > 0x230) {
                    width = 0x230;
                }
                if (width + 0x60 > 0x230) {
                    side = 0x230 - width;
                }
                fn_80108BD0((char *)TalkUi_str + 0xF1, (0x248 - width) - side, 0xB4, width);
                fn_80122E28(*(void **)((u8 *)self + 0x40), (s16)((0x278 - width) - side), 0xC4);
                lbl_80312060[9] = (s16)(0x1F0 - side);
                lbl_80312060[10] = 0x123;
                lbl_80312060[11] = 0;
                panel = *(void **)((u8 *)self + 0x40);
                if ((u32)panel != 0) {
                    fn_80122DD0(panel, (s16)((0x288 - width) - side), 0x11C);
                }
            }
            break;
        }
        fn_801222A4(*(void **)((u8 *)self + 0x44), self);
        return 1;
    }
    return 0;
}
#pragma global_optimizer reset
void fn_80120354(void *);

void fn_80120304(void *arg0)
{
    void UiPanel_PollSkip(u16 *);
    u8 fn_8008A59C(void);
    void fn_80120354(void *);
    extern u16 gUiPanelFlags;

    UiPanel_PollSkip(&gUiPanelFlags);

    if (*((u8 *)arg0 + 0x63) == 0 || (u8)fn_8008A59C() == 0) {
        fn_80120354(arg0);
    }
}

void fn_80120354(void *arg0) {
    void Process_ClearFunc(void *);
    void *Process_CreateChild(void *, void *);
    void fn_8007ACE4(void *);
    void fn_8007AD30(void *, s32);
    s32 fn_8011E12C(void *);
    void Ui_PlaySeCue(void *, s32);
    u32 fn_80211690(void);
    extern u16 TalkUi_str[];
    extern u8 lbl_8028FE30[];
    extern s32 gUiInputFlags;
    extern void *gPadInput;
    extern u16 gUiPanelFlags;
    extern u32 lbl_80367A60;
    extern s8 lbl_80367A64;

    s32 i;
    void *self;
    s32 limit;
    s32 flags;
    s32 t;
    u16 raw;
    u16 cleared;
    void *pad;
    s32 pad4;
    s32 btn;
    s32 trigger;
    s8 delay;
    s32 slot;
    s32 want;
    void *tmp;
    void *child;
    s32 *p;

    self = arg0;
    *((u8 *)self + 0x5f) = *((u8 *)self + 0x5f) - 1;
    flags = gUiInputFlags;
    if (flags & 0x2000) {
        t = 1;
    } else if ((u32)((((u8 *)gBattleState)[0x9c] >> 3) & 3) == 3) {
        t = 0xffff;
    } else {
        t = 1;
    }
    limit = t;
    if ((gUiPanelFlags & 4) && !(flags & 3)) {
        tmp = Process_CreateChild(lbl_8028FE30, self);
        *(void **)((u8 *)tmp + 0x30) = self;
        *(s32 *)((u8 *)tmp + 0x34) = 0;
        return;
    }
    raw = *(volatile u16 *)&gUiPanelFlags;
    pad = gPadInput;
    cleared = raw & 0xfffffbff;
    *(volatile u16 *)&gUiPanelFlags = cleared;
    pad4 = *(s32 *)((u8 *)pad + 4);
    btn = pad4 & (*(s32 *)((u8 *)pad + 8) ^ pad4);
    if (!(btn & 0x100)) {
        if (!(pad4 & 0x04000004) || !(pad4 & 0x100)) {
            if (*(volatile u16 *)&gUiPanelFlags & 8) {
                if (!(btn & 0x200)) {
                    trigger = 0;
                    goto after_trig;
                }
            } else if (flags & 3) {
                trigger = 1;
                goto after_trig;
            } else {
                trigger = 0;
                goto after_trig;
            }
        } else {
            *(volatile u16 *)&gUiPanelFlags = cleared | 0x400;
        }
    }
    trigger = 1;
    *(volatile u16 *)&gUiPanelFlags |= 0x200;
after_trig:
    if ((u8)trigger) {
        *((u8 *)self + 0x5f) = 0;
        limit = 0xffff;
    }
    flags = gUiInputFlags;
    if (flags & 3) {
        Process_ClearFunc(self);
        return;
    }
    if ((s8)*((u8 *)self + 0x5f) != 0) {
        return;
    }
    if (flags & 0x2000) {
        delay = 5;
    } else {
        switch ((s32)((((u8 *)gBattleState)[0x9c] >> 3) & 3)) {
        case 0:
            delay = 0xa;
            break;
        case 1:
            delay = 4;
            break;
        case 2:
            delay = 1;
            break;
        case 3:
            delay = 1;
            break;
        default:
            delay = -1;
            break;
        }
    }
    *((u8 *)self + 0x5f) = delay;
    i = 0;
    *((u8 *)self + 0x67) = 0;
    while (i < limit) {
        if ((u8)fn_8011E12C(self) != 3) {
            break;
        }
        i += 1;
    }
    if (*((u8 *)self + 0x60) != 0) {
        if (lbl_80367A64 == 0) {
            lbl_80367A60 = -1;
            lbl_80367A64 = 1;
        }
        if (lbl_80367A60 != fn_80211690() - 1) {
            lbl_80367A60 = fn_80211690();
            if (!((((u8 *)gBattleState)[0x9f] >> 5) & 1)) {
                switch ((s32)*((u8 *)self + 0x66)) {
                case 0:
                    break;
                case 1:
                    Ui_PlaySeCue((char *)TalkUi_str + 0xfa, 0x64);
                    break;
                case 2:
                    Ui_PlaySeCue((char *)TalkUi_str + 0x107, 0x64);
                    break;
                case 3:
                    Ui_PlaySeCue((char *)TalkUi_str + 0x114, 0x64);
                    break;
                case 4:
                    Ui_PlaySeCue((char *)TalkUi_str + 0x121, 0x64);
                    break;
                }
            }
        }
    }
    want = (s8)*((u8 *)self + 0x5e);
    if (want < 0) {
        slot = -1;
    } else {
        child = *(void **)((u8 *)self + 0x48);
        if (child != NULL && (s8)*((u8 *)child + 0x43) == want) {
            slot = 0;
        } else {
            child = *(void **)((u8 *)self + 0x4c);
            if (child != NULL && (s8)*((u8 *)child + 0x43) == want) {
                slot = 1;
            } else {
                child = *(void **)((u8 *)self + 0x50);
                if (child != NULL && (s8)*((u8 *)child + 0x43) == want) {
                    slot = 2;
                } else {
                    child = *(void **)((u8 *)self + 0x54);
                    if (child != NULL && (s8)*((u8 *)child + 0x43) == want) {
                        slot = 3;
                    } else {
                        slot = -1;
                    }
                }
            }
        }
    }
    if ((s8)slot < 0) {
        child = 0;
    } else {
        p = (s32 *)self + (s8)slot;
        child = *(void **)((u8 *)p + 0x48);
    }
    if (child != NULL) {
        if (*((u8 *)self + 0x60) != *((u8 *)self + 0x61)) {
            if (*((u8 *)self + 0x60) != 0) {
                fn_8007ACE4(child);
            } else {
                fn_8007AD30(child, 0x80);
            }
        }
    }
    *((u8 *)self + 0x61) = *((u8 *)self + 0x60);
}

void fn_8012075C(void *arg0) {
    void fn_80122AA8(void *);
    extern s32 gUiInputFlags;
    s32 i;
    void *p;
    void *obj;

    if ((gUiInputFlags & 3) == 0) {
        i = 0;
        p = arg0;
        do {
            obj = *(void **)((u8 *)p + 0x34);
            if (obj != NULL) {
                fn_80122AA8(obj);
            }
            i += 1;
            p = (u8 *)p + 4;
        } while (i < 4);
    }
}

void fn_801207BC(void) {
    extern s32 gUiInputFlags;
    extern u16 gUiPanelFlags;
    gUiPanelFlags &= 0xFFFFFFFB;
    gUiInputFlags |= 2;
}

void fn_801207D8(void *arg0) {
    void fn_80089650(s32, s32);
    void Process_ClearFunc(void *);
    void fn_80079198(void *, void *);
    void fn_80122238(void *, void *);
    void fn_80120F94(void);
    void *fn_801090C0(void *);
    void fn_80109BB4(void *, u8);
    extern u32 lbl_80367A5C;
    void *self = arg0;
    void *obj;
    void *p;
    s32 i;
    void *t;

    obj = *(void **)((u8 *)self + 0x30);
    if (*(u8 *)((u8 *)obj + 0x63) != 0) {
        fn_80089650(3, 0x85);
        Process_ClearFunc(self);
        return;
    }
    for (i = 0, p = obj; i < 4; i += 1, p = (u8 *)p + 4) {
        t = *(void **)((u8 *)p + 0x48);
        if (t != NULL) {
            fn_80079198(t, self);
        }
    }
    {
        s32 i2;
        void *p2;
        for (i2 = 0, p2 = obj; i2 < 4; i2 += 1, p2 = (u8 *)p2 + 4) {
            t = *(void **)((u8 *)p2 + 0x34);
            if (t != NULL) {
                fn_80122238(t, self);
            }
        }
    }
    fn_80120F94();
    if (lbl_80367A5C != 0) {
        fn_80109BB4(fn_801090C0((void *)lbl_80367A5C), 8);
    }
    Process_ClearFunc(self);
}

extern s32 fn_80010710(u8* arg0);
extern s32 gActiveCam;
#pragma scheduling on
/* TODO: verify command mappings after table index 23. read_data truncates
 * jumptable_80290110 relocations there; cases s/n/w remain provisional.
 * Instruction match alone does not validate those jump-table entries. */
static inline s8 Text_NextChar(s8 **text)
{
    return *(*text)++;
}

static inline void Text_CopyDelimited(s8 **text, u8 *out)
{
    while ((s32)(u8)**text != '|') {
        *out++ = *(*text)++;
    }
    *out = 0;
    ++*text;
}

#pragma scheduling on
#pragma peephole on
s32 fn_801208BC(s8 *text, s32 wanted)
{
  s32 fn_80010428(s8 **, s32, f32);
  s8 *fn_80104970(s8 *);
  extern f32 lbl_8036A248;
  s32 longest = -1;
  s32 width;
  s32 selected = wanted;
  s32 font = 2;
  for (;;)
  {
    width = 0;
    for (;;)
    {
      if (!((s8) (*text)))
      {
        goto done;
      }
      if (((s8) (*text)) == '\n')
      {
        ++text;
        break;
      }
      if (((s8) (*text)) == '#')
      {
        if (((s32) ((u8) text[1])) == 'F')
        {
          font = ((s8) text[3]) - '0';
        }
        text += fn_80010710((u8 *) text);
      }
      if (((s32) ((u8) (*text))) == '$')
      {
        ++text;
        switch ((s8) (*(text++)))
        {
          case 'N':
            if (((s32) ((u8) (*text))) == 'D')
          {
            ++text;
            continue;
          }

          case 's':
            switch ((s8) (*(text++)))
          {
            case '0':
              selected = 0;
              continue;

            case '1':
              selected = 1;
              continue;

            break;
            case '2':
              selected = 2;
              continue;

            case '3':
              selected = 3;
              continue;

            case '4':
              selected = 4;
              continue;

            case 'D':
              if (selected == wanted)
            {
              goto done;
            }
              continue;

            default:
              continue;

          }


          case 'n':
          {
            switch ((s8) (*(text++)))
            {
              case '0':
                selected = 0;
                break;

              case '1':
                selected = 1;
                break;

              case '2':
                selected = 2;
                break;

              case '3':
                selected = 3;
                break;

            }

            Text_CopyDelimited(&text, lbl_8032FE24);
            continue;
          }

          case 'w':
            switch ((s8) (*(text++)))
          {
            case '0':
              selected = 0;
              break;

            case '1':
              selected = 1;
              break;

            case '2':
              selected = 2;
              break;

            case '3':
              selected = 3;
              break;

          }

            if (selected == wanted)
          {
            goto done;
          }
            continue;

          case 'D':

          case 'M':

          case 'O':

          case 'S':
            ++text;
            continue;

          case '=':
            text += 4;
            continue;

          case 'F':
            switch ((s32) ((u8) (*(text++))))
          {
            case 'C':
            {
              Text_CopyDelimited(&text, lbl_8032FE24);
              continue;
            }
              break;

          }

            continue;

          case 'B':

          case 'R':
          {
            Text_CopyDelimited(&text, lbl_8032FE24);
            continue;
          }

          case 'P':
            goto done;

          default:
            continue;

        }

        break;
      }
      if (selected == wanted)
      {
        width += fn_80010428(&text, font, lbl_8036A248);
      }
      else
      {
        text = fn_80104970(text);
      }
    }

    if (longest < width)
    {
      longest = width;
    }
  }

  done:
  if (longest < width)
  {
    longest = width;
  }

  return longest;
}
#include "common.h"

extern u16 lbl_8028F6C8[];
extern u16 lbl_80296128[];
extern void *gUnitLists;
extern u16 gTargetList[];

s32 fn_80120C2C(void) {
    extern u16 gUiPanelFlags;
    extern void *gPadInput;
    extern s32 gUiInputFlags;
    u32 raw;
    u16 cleared;
    void *pad;
    s32 buttons;
    s32 pressed;

    raw = gUiPanelFlags;
    pad = gPadInput;
    raw &= ~0x400;
    cleared = (u16)raw;
    gUiPanelFlags = cleared;
    buttons = *(s32 *)((u8 *)pad + 4);
    pressed = buttons & (*(s32 *)((u8 *)pad + 8) ^ buttons);
    if (!(pressed & 0x100)) {
        if (!(buttons & 0x04000004) || !(buttons & 0x100)) {
            if (*(volatile u16 *)&gUiPanelFlags & 8) {
                if (!(pressed & 0x200)) {
                    return 0;
                }
            } else {
                return (gUiInputFlags & 3) != 0;
            }
        } else {
            gUiPanelFlags = (u16)(cleared | 0x400);
        }
    }
    gUiPanelFlags |= 0x200;
    return 1;
}
