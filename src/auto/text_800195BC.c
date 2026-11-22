/* Functions from 0x800195BC to 0x8001EE58, found by decomp-toolkit. */
#include "common.h"

void *fn_800195BC(void) {
extern u8 lbl_80268330[];
return lbl_80268330+0x1A3;
}

void fn_800195CC(void) {

}

void fn_800195D0(void *arg0) {
    M2C_FIELD(arg0, f32 *, 0x18) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
    M2C_FIELD(arg0, f32 *, 0x10) = (f32) M2C_FIELD(arg0, f32 *, 4);
    M2C_FIELD(arg0, f32 *, 0x14) = (f32) M2C_FIELD(arg0, f32 *, 8);
}

f32 fn_800195EC(void) {
    extern f32 lbl_80368CE8;
    return lbl_80368CE8;
}

void *fn_800195F4(void) {
    extern u16 lbl_80268330[];
    return (u8 *)lbl_80268330 + 0x1B3;
}

#pragma cplusplus on
extern "C" void fn_80019604(void *arg0) {
    extern void *gPadInput;
    extern f32 lbl_80368C88;
    extern f32 lbl_80368CA4;
    extern f32 lbl_80368CEC;
    extern f32 lbl_80368CF0;
    extern f32 lbl_80368CF4;
    extern f32 lbl_80368CF8;
    extern f32 lbl_80368CFC;
    extern f32 lbl_80368D00;
    extern f32 lbl_80368D04;

    struct VObj {
        u8 pad[0x74];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual f32 v2(s32) = 0;
    };

    s32 temp_r5;
    f32 z;
    f32 field;
    f32 temp_f2;
    f32 temp_f1;

    temp_r5 = *(s32 *)((u8 *)gPadInput + 4);
    if (temp_r5 & (*(s32 *)((u8 *)gPadInput + 8) ^ temp_r5) & 0x40) {
        *(s32 *)((u8 *)arg0 + 0x20) = (*(s32 *)((u8 *)arg0 + 0x20) + 1) & 3;
        *(f32 *)((u8 *)arg0 + 0xC) = ((VObj *)arg0)->v2(*(s32 *)((u8 *)arg0 + 0x20));
    }

    z = lbl_80368C88;
    field = *(f32 *)((u8 *)arg0 + 8);
    *(f32 *)((u8 *)arg0 + 8) = field - ((f32)(s8)*(u8 *)(*(u8 **)gPadInput + 5) / lbl_80368CEC);
    temp_f1 = *(f32 *)((u8 *)arg0 + 8);
    if (temp_f1 < z) {
        *(f32 *)((u8 *)arg0 + 8) = temp_f1 * lbl_80368CA4;
    }
    temp_f1 = *(f32 *)((u8 *)arg0 + 8);
    if (temp_f1 > lbl_80368CF0) {
        temp_f1 = lbl_80368CF0 + temp_f1;
        *(f32 *)((u8 *)arg0 + 8) = temp_f1 * lbl_80368CA4;
    }

    z = lbl_80368CF4;
    field = *(f32 *)((u8 *)arg0 + 4);
    *(f32 *)((u8 *)arg0 + 4) = field - ((f32)(s8)*(u8 *)(*(u8 **)gPadInput + 4) / lbl_80368CEC);
    temp_f2 = *(f32 *)((u8 *)arg0 + 4);
    if (temp_f2 < z) {
        temp_f1 = temp_f2 - lbl_80368CF8;
        *(f32 *)((u8 *)arg0 + 4) = temp_f1 * lbl_80368CA4;
    }
    temp_f1 = *(f32 *)((u8 *)arg0 + 4);
    if (temp_f1 > lbl_80368CF8) {
        temp_f1 = lbl_80368CF8 + temp_f1;
        *(f32 *)((u8 *)arg0 + 4) = temp_f1 * lbl_80368CA4;
    }

    if ((s8)*(u8 *)(*(u8 **)gPadInput + 4) == 0) {
        temp_f1 = *(f32 *)((u8 *)arg0 + 4);
        if (temp_f1 >= lbl_80368CFC) {
            if (temp_f1 <= lbl_80368D00) {
                *(f32 *)((u8 *)arg0 + 4) = temp_f1 * lbl_80368D04;
            }
        }
    }
}
#pragma cplusplus reset

f32 fn_800197B4(s32 unused, s32 idx) {
    u32 local[4];
    extern u32 lbl_80268308[4];
    local[0] = lbl_80268308[0];
    local[1] = lbl_80268308[1];
    local[2] = lbl_80268308[2];
    local[3] = lbl_80268308[3];
    return ((f32 *)local)[idx];
}

void *fn_800197F4(void) {
    extern u8 lbl_80268330[];
    return (u8 *)lbl_80268330 + 0x1C1;
}

f32 fn_80019804(void) {
    extern f32 lbl_80368CE8;
    return lbl_80368CE8;
}

void fn_8001980C(void *arg0) {
    extern void *gPadInput;
    extern f32 lbl_80368C88;
    extern f32 lbl_80368C8C;
    extern f32 lbl_80368CA4;
    extern f32 lbl_80368CE4;
    extern f32 lbl_80368D08;
    extern f32 lbl_80368D0C;
    extern f32 lbl_80368D10;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 scale;
    f32 zero;
    f32 one;
    s32 temp_r5;
    void *temp_r6;

    if (M2C_FIELD(gPadInput, s32 *, 4) & 0x200) {
        scale = lbl_80368CE4;
        M2C_FIELD(arg0, f32 *, 0x60) =
            M2C_FIELD(arg0, f32 *, 0x60)
            + ((f32)M2C_FIELD(M2C_FIELD(gPadInput, void **, 0), u8 *, 7) / scale);
        M2C_FIELD(arg0, f32 *, 0x60) =
            M2C_FIELD(arg0, f32 *, 0x60)
            + ((f32)(-(s32)M2C_FIELD(M2C_FIELD(gPadInput, void **, 0), u8 *, 6)) / scale);
        temp_r5 = M2C_FIELD(gPadInput, s32 *, 4);
        if (temp_r5 & (M2C_FIELD(gPadInput, s32 *, 8) ^ temp_r5) & 0x800) {
            M2C_FIELD(arg0, f32 *, 0x60) = lbl_80368C88;
        }
    } else {
        temp_r6 = M2C_FIELD(gPadInput, void **, 0);
        scale = lbl_80368D08;
        one = lbl_80368C8C;
        one = one - ((f32)M2C_FIELD(temp_r6, u8 *, 7) / scale);
        one = one + ((f32)M2C_FIELD(temp_r6, u8 *, 6) / scale);
        M2C_FIELD(arg0, f32 *, 0x18) = M2C_FIELD(arg0, f32 *, 0x18) * one;
    }
    zero = lbl_80368C88;
    M2C_FIELD(arg0, f32 *, 0x14) =
        -(((f32)(s8)M2C_FIELD(M2C_FIELD(gPadInput, void **, 0), u8 *, 5) * lbl_80368D0C)
          - M2C_FIELD(arg0, f32 *, 0x14));
    temp_f1 = M2C_FIELD(arg0, f32 *, 0x14);
    if (temp_f1 < zero) {
        M2C_FIELD(arg0, f32 *, 0x14) = temp_f1 * lbl_80368CA4;
    }
    temp_f1_2 = M2C_FIELD(arg0, f32 *, 0x14);
    if (temp_f1_2 > lbl_80368D10) {
        temp_f1_2 = lbl_80368D10 + temp_f1_2;
        M2C_FIELD(arg0, f32 *, 0x14) = temp_f1_2 * lbl_80368CA4;
    }
    M2C_FIELD(arg0, f32 *, 0x10) =
        -(((f32)(s8)M2C_FIELD(M2C_FIELD(gPadInput, void **, 0), u8 *, 4) * lbl_80368D0C)
          - M2C_FIELD(arg0, f32 *, 0x10));
    M2C_FIELD(arg0, f32 *, 0xC) = M2C_FIELD(arg0, f32 *, 0x18);
    M2C_FIELD(arg0, f32 *, 8) = M2C_FIELD(arg0, f32 *, 0x14);
    M2C_FIELD(arg0, f32 *, 4) = M2C_FIELD(arg0, f32 *, 0x10);
    M2C_FIELD(arg0, s32 *, 0x1C) = 0xFF;
}

void *fn_800199E8(void) {
    extern s32 lbl_80268330[];
    return (char *) &lbl_80268330 + 0x1D0;
}

#pragma cplusplus on
extern "C" void fn_800199F8(void *arg0) {
    void fn_8000A274(s32);
    void Ui_PlaySeCue(void *, s32);
    extern u8 lbl_80268330[];
    extern u8 gBattleState[];
    extern void *gPadInput;
    extern f32 lbl_80368C88;
    extern f32 lbl_80368CA4;
    extern f32 lbl_80368CF0;
    extern f32 lbl_80368CF4;
    extern f32 lbl_80368CF8;
    extern f32 lbl_80368D0C;
    extern f32 lbl_80368D20;
    extern f32 lbl_80368D24;
    extern f32 lbl_80368D28;
    extern f32 lbl_80368D2C;

    struct VObj {
        u8 pad[0x74];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual f32 v2(s32) = 0;
    };

    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    s32 temp_r3;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 var_r30;

    temp_r5 = *(s32 *)((u8 *)gPadInput + 4);
    if (temp_r5 & (*(s32 *)((u8 *)gPadInput + 8) ^ temp_r5) & 0x40) {
        *(s32 *)((u8 *)arg0 + 0x20) = (*(s32 *)((u8 *)arg0 + 0x20) + 1) & 3;
        *(f32 *)((u8 *)arg0 + 0xC) = ((VObj *)arg0)->v2(*(s32 *)((u8 *)arg0 + 0x20));
    }
    temp_r5_2 = *(s32 *)((u8 *)gPadInput + 4);
    temp_r3 = temp_r5_2 & (*(s32 *)((u8 *)gPadInput + 8) ^ temp_r5_2);
    var_r30 = temp_r3;
    if ((gBattleState[0x9E] >> 7) & 1) {
        if (temp_r3 & 0x10000000) {
            var_r30 = temp_r3 & 0xEFFFFFFF;
            var_r30 |= 0x20000000;
        } else if (temp_r3 & 0x20000000) {
            var_r30 = temp_r3 & 0xDFFFFFFF;
            var_r30 |= 0x10000000;
        }
    }
    if (var_r30 & 0x10000000) {
        temp_f1 = *(f32 *)((u8 *)arg0 + 4);
        if (temp_f1 < lbl_80368CF8) {
            *(f32 *)((u8 *)arg0 + 4) = temp_f1 + lbl_80368CF8;
            Ui_PlaySeCue(lbl_80268330 + 0x18C, 0x64);
        }
    }
    if (var_r30 & 0x20000000) {
        temp_f1_2 = *(f32 *)((u8 *)arg0 + 4);
        if (temp_f1_2 > lbl_80368CF4) {
            *(f32 *)((u8 *)arg0 + 4) = temp_f1_2 - lbl_80368CF8;
            Ui_PlaySeCue(lbl_80268330 + 0x18C, 0x64);
        }
    }
    temp_f1_3 = *(f32 *)((u8 *)arg0 + 4);
    if (temp_f1_3 > lbl_80368CF8) {
        *(f32 *)((u8 *)arg0 + 4) = lbl_80368CF8;
    }
    if (*(f32 *)((u8 *)arg0 + 4) < lbl_80368CF4) {
        *(f32 *)((u8 *)arg0 + 4) = lbl_80368CF4;
    }
    temp_f1_3 = *(f32 *)((u8 *)arg0 + 4);
    if (lbl_80368D20 < temp_f1_3) {
        if (temp_f1_3 < lbl_80368D24) {
            *(f32 *)((u8 *)arg0 + 4) = lbl_80368C88;
        }
    }
    if (gBattleState[0x9D] & 1) {
        *(f32 *)((u8 *)arg0 + 8) =
            ((f32)(s8)*(u8 *)(*(u8 **)gPadInput + 5) * lbl_80368D0C) + *(f32 *)((u8 *)arg0 + 8);
    } else {
        *(f32 *)((u8 *)arg0 + 8) =
            *(f32 *)((u8 *)arg0 + 8) - ((f32)(s8)*(u8 *)(*(u8 **)gPadInput + 5) * lbl_80368D0C);
    }
    temp_f1_4 = *(f32 *)((u8 *)arg0 + 8);
    if (temp_f1_4 < lbl_80368C88) {
        *(f32 *)((u8 *)arg0 + 8) = temp_f1_4 * lbl_80368CA4;
    }
    temp_f1_5 = *(f32 *)((u8 *)arg0 + 8);
    if (temp_f1_5 > lbl_80368CF0) {
        temp_f1_5 = lbl_80368CF0 + temp_f1_5;
        *(f32 *)((u8 *)arg0 + 8) = temp_f1_5 * lbl_80368CA4;
    }
    fn_8000A274((s32)(lbl_80368D28 - lbl_80368D2C * (f32)*(u8 *)(*(u8 **)gPadInput + 7)));
}
#pragma cplusplus reset
f32 fn_80019C80(s32 unused, s32 idx) {
    u32 local[4];
    extern u32 lbl_802682F8[4];
    local[0] = lbl_802682F8[0];
    local[1] = lbl_802682F8[1];
    local[2] = lbl_802682F8[2];
    local[3] = lbl_802682F8[3];
    return ((f32 *)local)[idx];
}

/* Classify an ID string by prefix (PID_/JID_/IID_/FID_/msg/EID_/AID_/RID_/SID_). */
s32 Id_GetKind(char *idName) {
    s32 c1;

    if (idName == NULL) {
        return ID_KIND_NONE;
    }
    c1 = (u8)idName[1];
    if (c1 == 'I' && idName[2] == 'D' && idName[3] == '_') {
        switch (idName[0]) {
            case 'P':
                return ID_KIND_PID;
            case 'J':
                return ID_KIND_JID;
            case 'I':
                return ID_KIND_IID;
            case 'F':
                return ID_KIND_FID;
            case 'E':
                return ID_KIND_EID;
            case 'A':
                return ID_KIND_AID;
            case 'S':
                return ID_KIND_SID;
            case 'R':
                return ID_KIND_RID;
        }
    }
    if (idName[0] == 'M') {
        if (idName[2] == '_' || idName[4] == '_') {
            return ID_KIND_MSG;
        }
        if ((s8)c1 == 'Y') {
            return ID_KIND_MSG;
        }
    }
    return ID_KIND_NONE;
}

s32 Affinity_GetEntry(u8 arg0) {
    extern s32 lbl_8036720C;
    return lbl_8036720C + (arg0 * 0xC);
}

s32 Terrain_GetEntry(u8 arg0) {
    extern s32 lbl_803671EC;
    return lbl_803671EC + (arg0 * 0xC);
}

void fn_80019DD0(void) {
    M2C_UNK Res_GetByName();
    Res_GetByName();
}

s32 Res_GetEntry(u8 arg0) {
    extern s32 lbl_803671E8;
    return lbl_803671E8 + (arg0 * 0x28);
}

void Item_GetByIid(void) {
    M2C_UNK Res_GetByName();
    Res_GetByName();
}

#pragma dont_inline on
s32 Item_Get(s32 arg0) {
    extern s32 lbl_803671E4;
    if (arg0 == 0) {
        return 0;
    }
    return lbl_803671E4 + ((arg0 - 1) * 0x48);
}
#pragma dont_inline reset

void Job_GetByJid(void) {
    M2C_UNK Res_GetByName();
    Res_GetByName();
}

s32 Job_Get(s32 arg0) {
    extern s32 lbl_803671DC;
    if (arg0 == 0) {
        return 0;
    }
    return lbl_803671DC + ((arg0 - 1) * 0x64);
}

void Person_GetByPid(void) {
    M2C_UNK Res_GetByName();
    Res_GetByName();
}

s32 Person_Get(s32 arg0) {
    extern s32 lbl_803671D4;
    if (arg0 == 0) {
        return 0;
    }
    return lbl_803671D4 + ((arg0 - 1) * 0x64);
}

s32 fn_80019ED0(s32 arg0) {
    extern s32 lbl_80367204;
    extern s32 lbl_80367208;
    if (arg0 < 0) {
        return 0;
    }
    if (arg0 >= (s32) lbl_80367208) {
        return 0;
    }
    return lbl_80367204 + (arg0 * 0x60);
}

void *fn_80019F04(int arg0) {
    extern int lbl_80367208;
    extern u8 *lbl_80367204;
    int i;
    u8 *ptr;

    ptr = lbl_80367204;

    for (i = 0; i < lbl_80367208; i++) {
        if (ptr[0x3C] == arg0) {
            return ptr;
        }
        ptr += 0x60;
    }

    return 0;
}

void *fn_80019F3C(void *arg0, s16 arg1) {
    extern u8 lbl_802842B8[];
    extern u8 gStreamBaseVtbl[];
    s32 temp_r30;

    if (arg0 != NULL) {
        *(void **)((char *)arg0 + 0x10) = lbl_802842B8;
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

void fn_80019FC4(void)
{
    u8 *Hash_Lookup(char *);
    void *Heap_AllocRaw(s32);
    void *fn_8022C414(void *, void *, s32, s32, s32);
    s32 fn_8001EB44(u32);
    s32 Item_GetKindFromIid(u32);
    s32 fn_8001CE78(u32);
    void fn_8001DE1C(void *, u32);
    void Unit_OrMSfxFlag(void *, u32);
    void fn_8001E71C(void *);
    void fn_8000D3EC(u32, void *);
    void fn_8001A5D0(void *);

    extern char lbl_80268510[];
    extern s32 lbl_803671E0;
    extern void *lbl_803671E4;

    u8 *data;
    u8 *entry;
    u32 value;
    s32 count;
    s32 i;
    u8 *records;

    data = Hash_Lookup(lbl_80268510 + 0x6A);

    count = (data[0] << 24) +
            (data[1] << 16) +
            (data[2] << 8) +
            data[3];

    lbl_803671E0 = count;

    data += 4;

    records = fn_8022C414(
        Heap_AllocRaw(count * 0x48 + 0x10),
        fn_8001A5D0,
        0,
        0x48,
        count
    );

    lbl_803671E4 = records;

    for (i = 0; i < count; i++) {
        entry = records + i * 0x48;

        *(u16 *)(entry + 0xE) = i + 1;

        if (data != 0) {
            value = (data[0] << 24) +
                    (data[1] << 16) +
                    (data[2] << 8) +
                    data[3];
            data += 4;
        } else {
            value = 0;
        }

        *(u32 *)(entry + 0x0) = value;

        if (data != 0) {
            value = (data[0] << 24) +
                    (data[1] << 16) +
                    (data[2] << 8) +
                    data[3];
            data += 4;
        } else {
            value = 0;
        }

        *(u32 *)(entry + 0x4) = value;

        if (data != 0) {
            value = (data[0] << 24) +
                    (data[1] << 16) +
                    (data[2] << 8) +
                    data[3];
            data += 4;
        } else {
            value = 0;
        }

        *(u32 *)(entry + 0x8) = value;

        if (data != 0) {
            value = (data[0] << 24) +
                    (data[1] << 16) +
                    (data[2] << 8) +
                    data[3];
            data += 4;
        } else {
            value = 0;
        }

        entry[0x12] = fn_8001EB44(value);

        if (data != 0) {
            value = (data[0] << 24) +
                    (data[1] << 16) +
                    (data[2] << 8) +
                    data[3];
            data += 4;
        } else {
            value = 0;
        }

        entry[0x13] = fn_8001EB44(value);

        entry[0x14] = Item_GetKindFromIid(*(u32 *)(entry + 0x0));

        if (data != 0) {
            value = (data[0] << 24) +
                    (data[1] << 16) +
                    (data[2] << 8) +
                    data[3];
            data += 4;
        } else {
            value = 0;
        }

        entry[0x16] = fn_8001CE78(value);

        if (data != 0) {
            value = (data[0] << 24) +
                    (data[1] << 16) +
                    (data[2] << 8) +
                    data[3];
            data += 4;
        } else {
            value = 0;
        }

        fn_8001DE1C(entry, value);

        if (data != 0) {
            value = (data[0] << 24) +
                    (data[1] << 16) +
                    (data[2] << 8) +
                    data[3];
            data += 4;
        } else {
            value = 0;
        }

        fn_8001DE1C(entry, value);

        if (data != 0) {
            value = (data[0] << 24) +
                    (data[1] << 16) +
                    (data[2] << 8) +
                    data[3];
            data += 4;
        } else {
            value = 0;
        }

        fn_8001DE1C(entry, value);

        if (data != 0) {
            value = (data[0] << 24) +
                    (data[1] << 16) +
                    (data[2] << 8) +
                    data[3];
            data += 4;
        } else {
            value = 0;
        }

        fn_8001DE1C(entry, value);

        if (data != 0) {
            value = (data[0] << 24) +
                    (data[1] << 16) +
                    (data[2] << 8) +
                    data[3];
            data += 4;
        } else {
            value = 0;
        }

        fn_8001DE1C(entry, value);

        if (data != 0) {
            value = (data[0] << 24) +
                    (data[1] << 16) +
                    (data[2] << 8) +
                    data[3];
            data += 4;
        } else {
            value = 0;
        }

        fn_8001DE1C(entry, value);

        if (data != 0) {
            value = (data[0] << 24) +
                    (data[1] << 16) +
                    (data[2] << 8) +
                    data[3];
            data += 4;
        } else {
            value = 0;
        }

        Unit_OrMSfxFlag(entry + 0xC, value);

        if (data != 0) {
            value = (data[0] << 24) +
                    (data[1] << 16) +
                    (data[2] << 8) +
                    data[3];
            data += 4;
        } else {
            value = 0;
        }

        Unit_OrMSfxFlag(entry + 0xC, value);

        if (data != 0) {
            value = (data[0] << 24) +
                    (data[1] << 16) +
                    (data[2] << 8) +
                    data[3];
            data += 4;
        } else {
            value = 0;
        }

        *(u32 *)(entry + 0x40) = value;

        if (data != 0) {
            value = (data[0] << 24) +
                    (data[1] << 16) +
                    (data[2] << 8) +
                    data[3];
            data += 4;
        } else {
            value = 0;
        }

        *(u32 *)(entry + 0x44) = value;

        *(u16 *)(entry + 0x10) =
            (data[0] << 8) + data[1];

        entry[0x18] = data[2];
        entry[0x19] = data[3];
        entry[0x1A] = data[4];
        entry[0x1B] = data[5];
        entry[0x1C] = data[6];
        entry[0x1D] = data[7];
        entry[0x1E] = data[8];
        entry[0x15] = data[9];
        entry[0x17] = data[10];
        entry[0x1F] = data[11];
        entry[0x20] = data[12];
        entry[0x21] = data[13];
        entry[0x22] = data[14];
        entry[0x23] = data[15];
        entry[0x24] = data[16];
        entry[0x25] = data[17];
        entry[0x26] = data[18];
        entry[0x27] = data[19];
        entry[0x28] = data[20];
        entry[0x2A] = data[21];
        entry[0x2B] = data[22];
        entry[0x2C] = data[23];
        entry[0x2D] = data[24];
        entry[0x2E] = data[25];
        entry[0x2F] = data[26];
        entry[0x30] = data[27];
        entry[0x31] = data[28];
        entry[0x29] = data[29];

        fn_8001E71C(entry);

        fn_8000D3EC(*(u32 *)(entry + 0x0), entry);

        data = (u8 *)(((u32)(data + 0x21)) & ~3);
    }
}

void fn_8001A5D0(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
}

#pragma use_lmw_stmw on
void fn_8001A5E4(void) {
    u8 *Hash_Lookup(char *);
    void *Heap_AllocRaw(s32);
    void *fn_8022C414(void *, void *, s32, s32, s32);
    void fn_8001CC48(void *, u32);
    void Status_OrByName(void *, u32);
    u8 Status_Test(void *, s32);
    void Status_Clear(void *, s32);
    void Unit_OrMSfxFlag(void *, u32);
    u32 fn_80234198(u32, char *);
    void fn_8000D3EC(u32, void *);
    void fn_800A89C0(void *);
    extern char lbl_80268510[];
    extern s32 lbl_803671D8;
    extern void *lbl_803671DC;

    u8 *ptr;
    u8 *rec;
    s32 i;
    u32 v;
    u32 id;
    char *base;
    u8 *data;
    s32 count;

    data = Hash_Lookup(lbl_80268510 + 0x73);
    ptr = data + 4;
    count = (data[0] << 24) + ((data[1] << 16) + (data[2] << 8) + data[3]);
    lbl_803671D8 = count;
    rec = fn_8022C414(Heap_AllocRaw(count * 0x64 + 0x10), fn_800A89C0, 0, 0x64, count);
    lbl_803671DC = rec;
    base = lbl_80268510;
    for (i = 0; i < lbl_803671D8; i++) {
        *(s16 *)(rec + 0x38) = i + 1;
        if (ptr == NULL) {
            id = 0;
        } else {
            id = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]);
            ptr += 4;
        }
        *(u32 *)(rec + 0x0) = id;
        if (ptr == NULL) { v = 0; } else { v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]); ptr += 4; }
        *(u32 *)(rec + 0x4) = v;
        if (ptr == NULL) { v = 0; } else { v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]); ptr += 4; }
        *(u32 *)(rec + 0x8) = v;
        if (ptr == NULL) { v = 0; } else { v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]); ptr += 4; }
        *(u32 *)(rec + 0xC) = v;
        if (ptr == NULL) { v = 0; } else { v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]); ptr += 4; }
        *(u32 *)(rec + 0x14) = v;
        if (ptr == NULL) { v = 0; } else { v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]); ptr += 4; }
        fn_8001CC48(rec + 0x2C, v);
        *(u32 *)(rec + 0x34) = v;
        if (ptr == NULL) { v = 0; } else { v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]); ptr += 4; }
        Status_OrByName(rec + 0x1C, v);
        if (ptr == NULL) { v = 0; } else { v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]); ptr += 4; }
        Status_OrByName(rec + 0x1C, v);
        if (ptr == NULL) { v = 0; } else { v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]); ptr += 4; }
        Status_OrByName(rec + 0x1C, v);
        if (ptr == NULL) { v = 0; } else { v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]); ptr += 4; }
        Status_OrByName(rec + 0x1C, v);
        if (ptr == NULL) { v = 0; } else { v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]); ptr += 4; }
        Status_OrByName(rec + 0x1C, v);
        if (Status_Test(rec + 0x1C, 3) == 0) {
            Status_Clear(rec + 0x1C, 0x44);
        }
        if (ptr == NULL) { v = 0; } else { v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]); ptr += 4; }
        Unit_OrMSfxFlag(rec + 0x3A, v);
        if (ptr == NULL) { v = 0; } else { v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]); ptr += 4; }
        Unit_OrMSfxFlag(rec + 0x3A, v);
        if (ptr == NULL) { v = 0; } else { v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]); ptr += 4; }
        Unit_OrMSfxFlag(rec + 0x3A, v);
        if (ptr == NULL) { v = 0; } else { v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]); ptr += 4; }
        *(u32 *)(rec + 0x18) = v;
        rec[0x3C] = ptr[0]; rec[0x3D] = ptr[1]; rec[0x3E] = ptr[2]; rec[0x3F] = ptr[3];
        rec[0x40] = ptr[4]; rec[0x41] = ptr[5]; rec[0x42] = ptr[6]; rec[0x43] = ptr[7];
        rec[0x44] = ptr[8]; rec[0x45] = ptr[9]; rec[0x46] = ptr[10]; rec[0x47] = ptr[11];
        rec[0x48] = ptr[12]; rec[0x4A] = ptr[14]; rec[0x4B] = ptr[15]; rec[0x4C] = ptr[16];
        rec[0x4D] = ptr[17]; rec[0x4E] = ptr[18]; rec[0x4F] = ptr[19]; rec[0x50] = ptr[20];
        rec[0x52] = ptr[22]; rec[0x53] = ptr[23]; rec[0x54] = ptr[24]; rec[0x55] = ptr[25];
        rec[0x56] = ptr[26]; rec[0x57] = ptr[27]; rec[0x58] = ptr[28]; rec[0x59] = ptr[29];
        rec[0x5A] = ptr[30]; rec[0x5B] = ptr[31]; rec[0x5C] = ptr[32]; rec[0x5D] = ptr[33];
        rec[0x5E] = ptr[34]; rec[0x5F] = ptr[35]; rec[0x60] = ptr[36]; rec[0x61] = ptr[37];
        rec[0x62] = ptr[38]; rec[0x63] = ptr[39];
        if (fn_80234198(id, base + 0x7B) != 0) {
            Status_OrByName(rec + 0x1C, (u32)(base + 0x7E));
        }
        fn_8000D3EC(*(u32 *)(rec + 0x0), rec);
        ptr = (u8 *)(((u32)(ptr + 0x2B)) & ~3);
        rec += 0x64;
    }
}
#pragma use_lmw_stmw reset
void fn_8001AC18(void) {
    u8 *Hash_Lookup(char *);
    void *Heap_AllocRaw(s32);
    void *fn_8022C414(void *, void *, s32, s32, s32);
    u16 Rand_Range(s32);
    void fn_8000D3EC(u32, void *);
    void fn_8001CC48(void *, u32);
    s32 Affinity_FromName(u32);
    void Status_OrByName(void *, u32);
    void fn_800A8A2C(void *);
    extern char lbl_80268510[];
    extern s32 lbl_803671D0;
    extern void *lbl_803671D4;

    u8 *data;
    u8 *ptr;
    void *rec;
    s32 count;
    s32 i;
    u32 v;
    u16 h;
    u8 b;

    data = Hash_Lookup(lbl_80268510 + 0x89);
    ptr = data + 4;
    count = (data[0] << 24) + ((data[1] << 16) + (data[2] << 8) + data[3]);
    lbl_803671D0 = count;
    rec = fn_8022C414(Heap_AllocRaw(count * 0x64 + 0x10), fn_800A8A2C, 0, 0x64, count);
    lbl_803671D4 = rec;

    for (i = 0; i < lbl_803671D0; i++) {
        *(s16 *)((u8 *)rec + 0x18) = i + 1;

        if (ptr == NULL) {
            v = 0;
        } else {
            v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]);
            ptr += 4;
        }
        *(u32 *)((u8 *)rec + 0x0) = v;

        if (ptr == NULL) {
            v = 0;
        } else {
            v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]);
            ptr += 4;
        }
        *(u32 *)((u8 *)rec + 0x4) = v;

        if (ptr == NULL) {
            v = 0;
        } else {
            v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]);
            ptr += 4;
        }
        *(u32 *)((u8 *)rec + 0x8) = v;

        if (ptr == NULL) {
            v = 0;
        } else {
            v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]);
            ptr += 4;
        }
        *(u32 *)((u8 *)rec + 0xC) = v;

        if (ptr == NULL) {
            v = 0;
        } else {
            v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]);
            ptr += 4;
        }
        *(u32 *)((u8 *)rec + 0x10) = v;

        if (ptr == NULL) {
            v = 0;
        } else {
            v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]);
            ptr += 4;
        }
        *(u8 *)((u8 *)rec + 0x54) = Affinity_FromName(v);

        if (ptr == NULL) {
            v = 0;
        } else {
            v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]);
            ptr += 4;
        }
        fn_8001CC48((u8 *)rec + 0x35, v);

        if (ptr == NULL) {
            v = 0;
        } else {
            v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]);
            ptr += 4;
        }
        Status_OrByName((u8 *)rec + 0x40, v);

        if (ptr == NULL) {
            v = 0;
        } else {
            v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]);
            ptr += 4;
        }
        Status_OrByName((u8 *)rec + 0x40, v);

        if (ptr == NULL) {
            v = 0;
        } else {
            v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]);
            ptr += 4;
        }
        Status_OrByName((u8 *)rec + 0x40, v);

        if (ptr == NULL) {
            v = 0;
        } else {
            v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]);
            ptr += 4;
        }
        *(u32 *)((u8 *)rec + 0x5C) = v;

        if (ptr == NULL) {
            v = 0;
        } else {
            v = (ptr[0] << 24) + ((ptr[1] << 16) + (ptr[2] << 8) + ptr[3]);
            ptr += 4;
        }
        *(u32 *)((u8 *)rec + 0x60) = v;

        *(u16 *)((u8 *)rec + 0x5A) = (ptr[0] << 8) + ptr[1];
        h = (ptr[2] << 8) + ptr[3];
        if (h == 0) {
            h = Rand_Range(0x16E);
        }
        *(u16 *)((u8 *)rec + 0x58) = h;

        *(u8 *)((u8 *)rec + 0x56) = ptr[4];
        b = ptr[5];
        if (b == 0) {
            b = 0x1E;
        }
        *(u8 *)((u8 *)rec + 0x55) = b;

        *(u8 *)((u8 *)rec + 0x1A) = ptr[6];
        *(u8 *)((u8 *)rec + 0x1B) = ptr[7];
        *(u8 *)((u8 *)rec + 0x1C) = ptr[8];
        *(u8 *)((u8 *)rec + 0x1D) = ptr[9];
        *(u8 *)((u8 *)rec + 0x1E) = ptr[10];
        *(u8 *)((u8 *)rec + 0x1F) = ptr[11];
        *(u8 *)((u8 *)rec + 0x20) = ptr[12];
        *(u8 *)((u8 *)rec + 0x21) = ptr[13];
        *(u8 *)((u8 *)rec + 0x22) = ptr[14];
        *(u8 *)((u8 *)rec + 0x23) = ptr[15];
        *(u8 *)((u8 *)rec + 0x24) = ptr[16];
        *(u8 *)((u8 *)rec + 0x25) = ptr[17];
        *(u8 *)((u8 *)rec + 0x26) = ptr[18];
        *(u8 *)((u8 *)rec + 0x27) = ptr[19];
        *(u8 *)((u8 *)rec + 0x28) = ptr[20];
        *(u8 *)((u8 *)rec + 0x29) = ptr[21];
        *(u8 *)((u8 *)rec + 0x2A) = ptr[22];
        *(u8 *)((u8 *)rec + 0x2B) = ptr[23];
        *(u8 *)((u8 *)rec + 0x2C) = ptr[24];
        *(u8 *)((u8 *)rec + 0x2D) = ptr[25];
        *(u8 *)((u8 *)rec + 0x2E) = ptr[26];
        *(u8 *)((u8 *)rec + 0x2F) = ptr[27];
        *(u8 *)((u8 *)rec + 0x30) = ptr[28];
        *(u8 *)((u8 *)rec + 0x31) = ptr[29];
        *(u8 *)((u8 *)rec + 0x32) = ptr[30];
        *(u8 *)((u8 *)rec + 0x33) = ptr[31];
        *(u8 *)((u8 *)rec + 0x34) = ptr[32];

        fn_8000D3EC(*(u32 *)((u8 *)rec + 0x0), rec);

        ptr = (u8 *)(((u32)(ptr + 0x24)) & ~3);
        rec = (u8 *)rec + 0x64;
    }
}

#pragma global_optimizer off
void fn_8001B134(void) {
    void Archive_Load();
    void DebugPrint(char *, ...);
    u8 *Hash_Lookup(char *);
    s32 Res_GetByName(char *);
    void fn_8000D3EC(u32, void *);
    void fn_80019FC4(void);
    void fn_8001A5E4(void);
    void fn_8001AC18(void);
    void fn_8001B9DC(void *);
    void fn_8003B844(void *, s32);
    void fn_8005B820(void);
    void *Heap_AllocRaw(s32);
    void fn_800C4588(s32);
    void fn_8017A7D4(void *, void *);
    void *fn_8017A950(void *);
    void fn_801B8798(void);
    void *fn_8022C414(void *, void *, s32, s32, s32);
    extern char lbl_80268510[];
    extern u8 lbl_802842B8[];
    extern u8 gStreamBaseVtbl[];
    extern void *lbl_803671E8;
    extern void *lbl_803671EC;
    extern void *lbl_803671F0;
    extern void *lbl_803671F4;
    extern s32 lbl_803671F8;
    extern void *lbl_803671FC;
    extern s32 lbl_80367200;
    extern s32 lbl_80367204;
    extern void *lbl_80367208;
    extern void *lbl_8036720C;
    extern void *lbl_80367210;
    extern void *lbl_80367214;

    struct {
        void *ptr;
        s32 unk4;
        u8 pad[4];
        u8 flag;
        u8 pad2[3];
        void *vt;
    } tmp;
    u8 *src;
    u8 *rec;
    u8 *p;
    s32 n;
    s32 i;
    s32 val;

    Archive_Load();
    Archive_Load(lbl_80268510 + 0xCF);
    Archive_Load(lbl_80268510 + 0xDB);

    src = Hash_Lookup(lbl_80268510 + 0x94) + 4;
    if (src == 0) {
        val = 0;
    } else {
        val = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
        src += 4;
    }
    DebugPrint(lbl_80268510 + 0xA1, val);

    if (src == 0) {
        val = 0;
    } else {
        val = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    }
    DebugPrint(lbl_80268510 + 0xB6, val);
    DebugPrint(lbl_80268510 + 0xCB);
    DebugPrint(lbl_80268510 + 0xE9);

    lbl_803671E8 = Hash_Lookup(lbl_80268510 + 0x60) + 4;
    DebugPrint(lbl_80268510 + 0x10B);
    DebugPrint(lbl_80268510 + 0x113);
    fn_8001AC18();
    DebugPrint(lbl_80268510 + 0x10B);
    DebugPrint(lbl_80268510 + 0x139);
    fn_8001A5E4();
    DebugPrint(lbl_80268510 + 0x10B);
    DebugPrint(lbl_80268510 + 0x159);
    fn_80019FC4();
    DebugPrint(lbl_80268510 + 0x10B);
    DebugPrint(lbl_80268510 + 0x17D);

    p = Hash_Lookup(lbl_80268510 + 0x3E);
    src = p + 4;
    n = (p[0] << 24) + (p[1] << 16) + (p[2] << 8) + p[3];
    lbl_803671F8 = n;
    rec = fn_8022C414(Heap_AllocRaw(n * 0x14 + 0x10), fn_8001B9DC, 0, 0x14, n);
    lbl_803671F4 = rec;
    for (i = 0; i < lbl_803671F8; i++) {
        if (src == 0) {
            val = 0;
        } else {
            val = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
            src += 4;
        }
        *(s32 *)(rec + 0) = val;
        if (src == 0) {
            val = 0;
        } else {
            val = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
            src += 4;
        }
        *(s32 *)(rec + 4) = val;
        rec[8] = src[0];
        rec[9] = src[1];
        rec[10] = src[2];
        rec[11] = src[3];
        rec[12] = src[4];
        rec[13] = src[5];
        rec[14] = src[6];
        rec[15] = src[7];
        *(s32 *)(rec + 0x10) = (src[8] << 24) + (src[9] << 16) + (src[10] << 8) + src[11];
        fn_8000D3EC(*(u32 *)(rec + 0), rec);
        rec += 0x14;
        src = (u8 *)(((u32)src + 0xF) & ~3);
    }

    DebugPrint(lbl_80268510 + 0x10B);
    DebugPrint(lbl_80268510 + 0x1AB);

    p = Hash_Lookup(lbl_80268510 + 0x53);
    src = p + 4;
    n = (p[0] << 24) + (p[1] << 16) + (p[2] << 8) + p[3];
    lbl_803671F0 = src;
    fn_8003B844(src, n);

    DebugPrint(lbl_80268510 + 0x10B);
    DebugPrint(lbl_80268510 + 0x1CD);

    lbl_8036720C = Hash_Lookup(lbl_80268510 + 0x8) + 4;
    DebugPrint(lbl_80268510 + 0x10B);
    DebugPrint(lbl_80268510 + 0x1F1);

    lbl_803671EC = Hash_Lookup(lbl_80268510 + 0x47) + 4;
    fn_8005B820();
    DebugPrint(lbl_80268510 + 0x10B);
    DebugPrint(lbl_80268510 + 0x211);

    p = Hash_Lookup(lbl_80268510 + 0x33);
    src = p + 4;
    n = (p[0] << 24) + (p[1] << 16) + (p[2] << 8) + p[3];
    lbl_80367200 = n;
    rec = fn_8022C414(Heap_AllocRaw(n * 0xC + 0x10), 0, 0, 0xC, n);
    lbl_803671FC = rec;
    for (i = 0; i < lbl_80367200; i++) {
        if (src == 0) {
            val = 0;
        } else {
            val = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
            src += 4;
        }
        *(s32 *)(rec + 0) = val;
        rec[4] = src[0];
        rec[5] = src[1];
        rec[6] = src[2];
        rec[7] = src[3];
        src += 4;
        if (src == 0) {
            val = 0;
        } else {
            val = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
            src += 4;
        }
        *(s32 *)(rec + 8) = val;
        fn_8000D3EC(*(u32 *)(rec + 0), rec);
        rec += 0xC;
        src = (u8 *)(((u32)src + 3) & ~3);
    }

    DebugPrint(lbl_80268510 + 0x10B);
    DebugPrint(lbl_80268510 + 0x23B);

    fn_8017A7D4(&tmp, Hash_Lookup(lbl_80268510 + 0x27));
    lbl_80367208 = fn_8017A950(&tmp);
    tmp.vt = lbl_802842B8;
    lbl_80367204 = tmp.unk4;
    tmp.vt = gStreamBaseVtbl;
    if (tmp.flag != 0) {
        fn_800C4588((s32)tmp.ptr);
        tmp.ptr = 0;
        tmp.flag = 0;
    }

    DebugPrint(lbl_80268510 + 0x10B);
    DebugPrint(lbl_80268510 + 0x265);

    lbl_80367210 = (void *)Res_GetByName(lbl_80268510 + 0x1D);
    DebugPrint(lbl_80268510 + 0x10B);
    DebugPrint(lbl_80268510 + 0x287);

    lbl_80367214 = Hash_Lookup(lbl_80268510 + 0x13) + 4;
    fn_801B8798();
    DebugPrint(lbl_80268510 + 0x10B);
    DebugPrint(lbl_80268510 + 0x2A3);
    DebugPrint(lbl_80268510 + 0x2CD);
}
#pragma scheduling off
#pragma global_optimizer off
f32 fn_8001B84C(u8 **arg0) {
    u8 *next;
    u32 result;
    u32 b0;
    u32 b2;
    u8 *data;
    u32 b3;
    u32 value;

    data = *arg0;
    b2 = data[2];
    next = data + 4;
    result = data[1];
    b0 = data[0];
    b2 <<= 8;
    result <<= 16;
    b3 = data[3];
    result = result + b2;
    b0 <<= 24;
    result = result + b3;
    *arg0 = next;
    value = b0 + result;
    return *(f32 *)&value;
}
#pragma global_optimizer reset
#pragma scheduling reset
u32 Bin_ReadU32(u8 **arg0) {
    u8 *next;
    u32 result;
    u32 b0;
    u32 b2;
    u8 *data;
    u32 b3;

    data = *arg0;
    if (data == 0) {
        return 0;
    }
    b2 = data[2];
    next = data + 4;
    result = data[1];
    b0 = data[0];
    b2 <<= 8;
    result <<= 16;
    b3 = data[3];
    result = result + b2;
    b0 <<= 24;
    result = result + b3;
    *arg0 = next;
    result = b0 + result;
    return result;
}
#pragma global_optimizer reset
#pragma scheduling reset
#pragma global_optimizer off
#pragma scheduling off
u32 fn_8001B8E0(u8 **arg0)
{
    u8 *next;
    u32 result;
    u32 b0;
    u32 b2;
    u8 *data;
    u32 b3;

    data = *arg0;
    b2 = data[2];
    next = data + 4;
    result = data[1];
    b0 = data[0];
    b2 <<= 8;
    result <<= 16;
    b3 = data[3];
    result = result + b2;
    b0 <<= 24;
    result = result + b3;
    *arg0 = next;
    result = b0 + result;
    return result;
}
#pragma global_optimizer reset
#pragma scheduling reset
#pragma peephole off
u16 fn_8001B91C(u8 **arg0) {
 u8 *p; u8 *next; u16 hi; u32 lo;
 p=*arg0; hi=p[0]; next=p+2; lo=p[1];
 hi = (hi << 8) + lo;
 *arg0=next;
 return hi;
}
#pragma peephole on
u8 Bin_ReadU8(u8 **arg0) {
    u8 *temp_r4;

    temp_r4 = *arg0;
    *arg0 = temp_r4 + 1;
    return *temp_r4;
}

s32 fn_8001B954(s32 *arg0) {
    return *arg0;
}

s32 fn_8001B95C(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 8);
}

extern u8 gStreamBaseVtbl[];
void *fn_8001B964(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    void fn_800C4588(s32);
    extern u8 gStreamBaseVtbl[];

    if (arg0 != NULL) {
        *(void **)((char *)arg0 + 0x10) = gStreamBaseVtbl;
        if (*(u8 *)((char *)arg0 + 0xC) != 0) {
            fn_800C4588(*(s32 *)arg0);
            *(s32 *)arg0 = 0;
            *(u8 *)((char *)arg0 + 0xC) = 0;
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void fn_8001B9DC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 9) = 0x14;
    M2C_FIELD(arg0, s8 *, 0xA) = 0;
    M2C_FIELD(arg0, s8 *, 0xB) = 0;
}

u32 fn_8001B9F4(void *arg0) {
s32 *fn_800C29D0(void *, s32);
extern u8 gIconSlots[1152];
extern u32 lbl_80368D34;
extern u32 lbl_80368D38;
extern u32 lbl_80368D3C;
extern u32 lbl_80368D40;
extern u32 lbl_80368D44;
extern u32 lbl_80368D48;
extern u32 lbl_80368D4C;
extern u32 lbl_80368D50;
extern u32 lbl_80368D54;
extern u32 lbl_80368D58;
u32 result;
u32 t0;
u32 t1;
u32 t2;
u32 t3;
u32 t4;
u32 t5;
u32 t6;
u32 t7;
u32 t8;
u8 *item=arg0; u8 *data; u8 *color; u32 kind; u32 mask;
result=lbl_80368D34;
mask=item[5]&63;
if(mask) {
color=(u8*)fn_800C29D0(gIconSlots,mask);
((u8*)&result)[0]=color[0];
((u8*)&result)[1]=color[1];
((u8*)&result)[2]=color[2];
((u8*)&result)[3]=color[3];
} else {
data=*(u8**)item;
kind=data ? data[0x29] : 0;
switch(kind) {
case 0: t0=lbl_80368D38;
((u8*)&result)[0]=((u8*)&t0)[0];
((u8*)&result)[1]=((u8*)&t0)[1];
((u8*)&result)[2]=((u8*)&t0)[2];
((u8*)&result)[3]=((u8*)&t0)[3];
break;
case 1: t1=lbl_80368D3C;
((u8*)&result)[0]=((u8*)&t1)[0];
((u8*)&result)[1]=((u8*)&t1)[1];
((u8*)&result)[2]=((u8*)&t1)[2];
((u8*)&result)[3]=((u8*)&t1)[3];
break;
case 2: t2=lbl_80368D40;
((u8*)&result)[0]=((u8*)&t2)[0];
((u8*)&result)[1]=((u8*)&t2)[1];
((u8*)&result)[2]=((u8*)&t2)[2];
((u8*)&result)[3]=((u8*)&t2)[3];
break;
case 3: t3=lbl_80368D44;
((u8*)&result)[0]=((u8*)&t3)[0];
((u8*)&result)[1]=((u8*)&t3)[1];
((u8*)&result)[2]=((u8*)&t3)[2];
((u8*)&result)[3]=((u8*)&t3)[3];
break;
case 4: t4=lbl_80368D48;
((u8*)&result)[0]=((u8*)&t4)[0];
((u8*)&result)[1]=((u8*)&t4)[1];
((u8*)&result)[2]=((u8*)&t4)[2];
((u8*)&result)[3]=((u8*)&t4)[3];
break;
case 5: t5=lbl_80368D4C;
((u8*)&result)[0]=((u8*)&t5)[0];
((u8*)&result)[1]=((u8*)&t5)[1];
((u8*)&result)[2]=((u8*)&t5)[2];
((u8*)&result)[3]=((u8*)&t5)[3];
break;
case 6: t6=lbl_80368D50;
((u8*)&result)[0]=((u8*)&t6)[0];
((u8*)&result)[1]=((u8*)&t6)[1];
((u8*)&result)[2]=((u8*)&t6)[2];
((u8*)&result)[3]=((u8*)&t6)[3];
break;
case 7: t7=lbl_80368D54;
((u8*)&result)[0]=((u8*)&t7)[0];
((u8*)&result)[1]=((u8*)&t7)[1];
((u8*)&result)[2]=((u8*)&t7)[2];
((u8*)&result)[3]=((u8*)&t7)[3];
break;
case 8: t8=lbl_80368D58;
((u8*)&result)[0]=((u8*)&t8)[0];
((u8*)&result)[1]=((u8*)&t8)[1];
((u8*)&result)[2]=((u8*)&t8)[2];
((u8*)&result)[3]=((u8*)&t8)[3];
break;
}
}
return result;
}

s32 *fn_8001BC18(void *arg0) {
    s32 *fn_800C29D0(void *, s32);
    extern u8 gIconSlots[];
    extern s32 lbl_80368D30;
    s32 sp8;
    s32 mask;

    mask = *((u8 *)arg0 + 5) & 0x3F;
    if (mask == 0) {
        sp8 = lbl_80368D30;
        return &sp8;
    }
    return fn_800C29D0(gIconSlots, mask);
}

extern u8 lbl_80268330;
#pragma use_lmw_stmw on
void fn_8001BC5C(void *arg0, u8 a, u8 b, u8 c, u8 d) {
    s32 fn_800C29E8(u8 *, s32, void *);
    s32 Icon_AllocSlot(u8 *);
    extern u8 gIconSlots[];
    extern u32 lbl_8036C408;
    u32 sp8;

    if (!(((u8 *)arg0)[5] & 0x3F)) {
        ((u8 *)arg0)[5] = (u8)((((u8 *)arg0)[5] & ~0x3F) | (Icon_AllocSlot(gIconSlots) & 0x3F));
    }
    sp8 = lbl_8036C408;
    ((u8 *)&sp8)[0] = a;
    ((u8 *)&sp8)[1] = b;
    ((u8 *)&sp8)[2] = c;
    ((u8 *)&sp8)[3] = d;
    ((u8 *)arg0)[5] = (u8)((((u8 *)arg0)[5] & ~0x3F) | (fn_800C29E8(gIconSlots, ((u8 *)arg0)[5] & 0x3F, &sp8) & 0x3F));
}
#pragma use_lmw_stmw reset
void fn_8001BCF4(void *arg0) {
    s32 fn_800C2EF8(u8 *, s32, u8 *);
    extern u8 gIconSlots[];
    extern u8 gDataStr[];
    u8 mask = ((u8 *)arg0)[5] & 0x3F;
    if (mask) {
        ((u8 *)arg0)[5] = (u8)((((u8 *)arg0)[5] & ~0x3F) | (fn_800C2EF8(gIconSlots, mask, gDataStr + 0x3B) & 0x3F));
    }
}

void fn_8001BD4C(void *arg0, s32 arg1) {
    s32 fn_800C2EF8(u8 *, s32, s32);
    s32 Icon_AllocSlot(u8 *);
    extern u8 gIconSlots[];
    if (!(((u8 *)arg0)[5] & 0x3F)) {
        ((u8 *)arg0)[5] = (u8)((((u8 *)arg0)[5] & ~0x3F) | (Icon_AllocSlot(gIconSlots) & 0x3F));
    }
    ((u8 *)arg0)[5] = (u8)((((u8 *)arg0)[5] & ~0x3F) | (fn_800C2EF8(gIconSlots, ((u8 *)arg0)[5] & 0x3F, arg1) & 0x3F));
}

void fn_8001BDC8(void *arg0, s32 arg1) {
    s32 fn_800C2AE0(u8 *, s32, s32);
    s32 Icon_AllocSlot(u8 *);
    extern u8 gIconSlots[];
    if (!(((u8 *)arg0)[5] & 0x3F)) {
        ((u8 *)arg0)[5] = (u8)((((u8 *)arg0)[5] & ~0x3F) | (Icon_AllocSlot(gIconSlots) & 0x3F));
    }
    ((u8 *)arg0)[5] = (u8)((((u8 *)arg0)[5] & ~0x3F) | (fn_800C2AE0(gIconSlots, ((u8 *)arg0)[5] & 0x3F, arg1) & 0x3F));
}

void fn_8001BE44(void *arg0, s32 arg1) {
    s32 fn_800C2BBC(u8 *, s32, s32);
    s32 Icon_AllocSlot(u8 *);
    extern u8 gIconSlots[];
    if (!(((u8 *)arg0)[5] & 0x3F)) {
        ((u8 *)arg0)[5] = (u8)((((u8 *)arg0)[5] & ~0x3F) | (Icon_AllocSlot(gIconSlots) & 0x3F));
    }
    ((u8 *)arg0)[5] = (u8)((((u8 *)arg0)[5] & ~0x3F) | (fn_800C2BBC(gIconSlots, ((u8 *)arg0)[5] & 0x3F, arg1) & 0x3F));
}

void fn_8001BEC0(void *arg0, s32 arg1) {
    s32 fn_800C2C98(u8 *, s32, s32);
    s32 Icon_AllocSlot(u8 *);
    extern u8 gIconSlots[];
    if (!(((u8 *)arg0)[5] & 0x3F)) {
        ((u8 *)arg0)[5] = (u8)((((u8 *)arg0)[5] & ~0x3F) | (Icon_AllocSlot(gIconSlots) & 0x3F));
    }
    ((u8 *)arg0)[5] = (u8)((((u8 *)arg0)[5] & ~0x3F) | (fn_800C2C98(gIconSlots, ((u8 *)arg0)[5] & 0x3F, arg1) & 0x3F));
}

void fn_8001BF3C(void *arg0, s32 arg1) {
    s32 fn_800C2D74(u8 *, s32, s32);
    s32 Icon_AllocSlot(u8 *);
    extern u8 gIconSlots[];
    if (!(((u8 *)arg0)[5] & 0x3F)) {
        ((u8 *)arg0)[5] = (u8)((((u8 *)arg0)[5] & ~0x3F) | (Icon_AllocSlot(gIconSlots) & 0x3F));
    }
    ((u8 *)arg0)[5] = (u8)((((u8 *)arg0)[5] & ~0x3F) | (fn_800C2D74(gIconSlots, ((u8 *)arg0)[5] & 0x3F, arg1) & 0x3F));
}

s8 fn_8001BFB8(u8 *arg0) {
    s32 fn_800C2ACC(void *, s32);
    extern u8 gIconSlots[];
    s32 result;
    s32 mask;

    mask = arg0[5] & 0x3F;
    if (mask == 0) {
        result = 0;
    } else {
        result = (s8)fn_800C2ACC(gIconSlots, mask);
    }
    return (s8)result;
}

s8 fn_8001BFFC(u8 *arg0) {
    s32 fn_800C2BA8(void *, s32);
    extern u8 gIconSlots[];
    s32 result;
    s32 mask;

    mask = arg0[5] & 0x3F;
    if (mask == 0) {
        result = 0;
    } else {
        result = (s8)fn_800C2BA8(gIconSlots, mask);
    }
    return (s8)result;
}

s8 fn_8001C040(u8 *arg0) {
    s32 fn_800C2C84(void *, s32);
    extern u8 gIconSlots[];
    s32 result;
    s32 mask;

    mask = arg0[5] & 0x3F;
    if (mask == 0) {
        result = 0;
    } else {
        result = (s8)fn_800C2C84(gIconSlots, mask);
    }
    return (s8)result;
}

s8 fn_8001C084(u8 *arg0) {
    s32 fn_800C2D60(void *, s32);
    extern u8 gIconSlots[];
    s32 result;
    s32 mask;

    mask = arg0[5] & 0x3F;
    if (mask == 0) {
        result = 0;
    } else {
        result = (s8)fn_800C2D60(gIconSlots, mask);
    }
    return (s8)result;
}

extern u8 gItemFlagsDummyReady;
extern s32 gItemFlagsDummy;
extern s32 gItemFlagsDummyHi;
s32 fn_8001C0C8(u8 *arg0)
{
    extern u8 gItemFlagsDummyReady;
    extern s32 gItemFlagsDummyHi;
    extern s32 gItemFlagsDummy;

    void *temp_r7;
    unsigned long long *p;
    u8 other;

    if ((s8)gItemFlagsDummyReady == 0) {
        gItemFlagsDummyHi = 0;
        gItemFlagsDummy = 0;
        gItemFlagsDummyReady = 1;
    }

    temp_r7 = *(void **)arg0;
    if (temp_r7 != NULL) {
        p = (unsigned long long *)((u8 *)temp_r7 + 0x38);
    } else {
        p = (unsigned long long *)&gItemFlagsDummy;
    }

    if ((*p & 0x318ULL) != 0) {
        return 0;
    }

    if (temp_r7 != NULL) {
        other = *((u8 *)temp_r7 + 0x18);
    } else {
        other = 0;
    }

    if (arg0[4] == other) {
        return 0;
    }
    return 1;
}

void Item_Read(void *arg0, void *arg1) {
    void Icon_FreeSlot(void *, s32);
    u16 Stream_ReadU16(void *);
    s32 Item_Get(s32);
    extern u8 gIconSlots[];
    typedef struct {
        u8 pad : 1;
        u8 flag : 1;
        u8 rest : 6;
    } Bit6;
    Bit6 *bf;
    s32 mask;
    u16 temp;

    temp = Stream_ReadU16(arg1);
    if (temp == 0) {
        *(s32 *)((u8 *)arg1 + 4) = *(s32 *)((u8 *)arg1 + 4) + 2;
        bf = (Bit6 *)((u8 *)arg0 + 5);
        bf->rest = 0;
        *(s32 *)arg0 = 0;
        *((u8 *)arg0 + 4) = 0;
        bf->pad = 0;
        bf->flag = 0;
        mask = *((u8 *)arg0 + 5) & 0x3F;
        if (mask != 0) {
            Icon_FreeSlot(gIconSlots, mask);
            bf->rest = 0;
        }
    } else {
        *(s32 *)arg0 = Item_Get(temp);
        *((u16 *)arg0 + 2) = Stream_ReadU16(arg1);
    }
}

void fn_8001C21C(void *arg0, s32 arg1) {
    M2C_UNK Stream_WriteS32(s32, M2C_UNK);
    M2C_UNK Stream_WriteU16(s32, u16);
    void *temp_r3;

    temp_r3 = M2C_FIELD(arg0, void **, 0);
    if (temp_r3 == NULL) {
        Stream_WriteS32(arg1, 0);
        return;
    }
    Stream_WriteU16(arg1, M2C_FIELD(temp_r3, u16 *, 0xE));
    Stream_WriteU16(arg1, M2C_FIELD(arg0, u16 *, 4));
}

extern f32 lbl_80368D5C;
extern f32 lbl_80368D60;
extern f64 lbl_80368D68;
extern f64 lbl_80368D70;
double fabs(double);
#pragma scheduling on
s32 fn_8001C284(void *arg0, u8 arg1, s8 arg2, s8 arg3, s8 arg4, s8 arg5) {
extern f32 lbl_80368D5C; extern f32 lbl_80368D60;
f32 total = lbl_80368D5C;
if ((arg5 | (arg4 | (arg2 | arg3))) == 0) return 0;
if (arg2) { f32 next, square, base; base=(f32)*(u8*)((u8*)arg0+0x19); square=base*base; next=base+(f32)(arg2); total+=(f32)arg1*((f32)__fabs(next*next-square)*((f32)*(u16*)((u8*)arg0+0x10)/square)); }
if (arg3) { f32 next, square, base; base=(f32)*(u8*)((u8*)arg0+0x1A); square=base*base; next=base+(f32)(arg3*5); total+=(f32)arg1*((f32)__fabs(next*next-square)*((f32)*(u16*)((u8*)arg0+0x10)/square)); }
if (arg4) { f32 next, square, base; base=(f32)(*(u8*)((u8*)arg0+0x1C)+10); square=base*base; next=base+(f32)(arg4*3); total+=(f32)arg1*((f32)__fabs(next*next-square)*((f32)*(u16*)((u8*)arg0+0x10)/square)); }
if (arg5) { f32 next, square, base; base=(f32)(23-*(u8*)((u8*)arg0+0x1B)); square=base*base; next=base+(f32)(arg5); total+=(f32)arg1*((f32)__fabs(next*next-square)*((f32)*(u16*)((u8*)arg0+0x10)/square)); }
return (s32)(total*lbl_80368D60);
}
#pragma scheduling reset
void *Item_Copy(void *dstItem, void *srcItem) {
    /* Copy item fields and share/clone the icon slot referenced by the 6-bit index. */
    s32 Icon_GetSlot(void *, s32);
    s32 Icon_CopySlot(void *, s32, s32);
    s32 Icon_AllocSlot(void *);
    void Icon_FreeSlot(void *, s32);
    extern u8 gIconSlots[];
    typedef struct {
        u8 pad : 1;
        u8 flag : 1;
        u8 rest : 6;
    } Bit6;
    Bit6 *dst;
    Bit6 *src;
    s32 mask;
    s32 temp;

    dst = (Bit6 *)((u8 *)dstItem + 5);
    src = (Bit6 *)((u8 *)srcItem + 5);
    if (dstItem != srcItem) {
        *(s32 *)dstItem = *(s32 *)srcItem;
        *((u8 *)dstItem + 4) = *((u8 *)srcItem + 4);
        dst->pad = src->pad;
        dst->flag = src->flag;
        mask = src->rest;
        if (mask != 0) {
            temp = Icon_GetSlot(gIconSlots, mask);
            if (dst->rest == 0) {
                dst->rest = Icon_AllocSlot(gIconSlots);
            }
            dst->rest = Icon_CopySlot(gIconSlots, dst->rest, temp);
        } else if (dst->rest != 0) {
            Icon_FreeSlot(gIconSlots, dst->rest);
            dst->rest = 0;
        }
    }
    return dstItem;
}

void *Item_Destroy(void *arg0, s16 arg1) {
    void Icon_FreeSlot(void *, s32);
    void Heap_Free(void *);
    extern u8 gIconSlots[];
    typedef struct {
        u8 pad : 1;
        u8 flag : 1;
        u8 rest : 6;
    } Bit6;
    Bit6 *bf;
    s32 mask;

    if (arg0 != NULL) {
        *(s32 *)arg0 = 0;
        *((u8 *)arg0 + 4) = 0;
        bf = (Bit6 *)((u8 *)arg0 + 5);
        bf->pad = 0;
        bf->flag = 0;
        mask = *((u8 *)arg0 + 5) & 0x3F;
        if (mask != 0) {
            Icon_FreeSlot(gIconSlots, mask);
            bf->rest = 0;
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void *Item_Clone(void *arg0, void *arg1) {
    s32 fn_800C30CC(void *, s32);
    s32 fn_800C30DC(void *, s32, s32);
    s32 fn_800C3260(void *);
    extern u8 lbl_803206EC[];
    typedef struct {
        u8 pad : 1;
        u8 flag : 1;
        u8 rest : 6;
    } Bit6;
    Bit6 *dst;
    Bit6 tmp;
    s32 word;
    u8 byte4;
    s32 mask;
    s32 temp;
    s32 pad;
    s32 flag;

    dst = (Bit6 *)((u8 *)arg0 + 5);
    word = *(s32 *)arg1;
    *(u8 *)&tmp = *((u8 *)arg1 + 5);
    mask = tmp.rest;
    dst->rest = 0;
    pad = tmp.pad;
    flag = tmp.flag;
    byte4 = *((u8 *)arg1 + 4);
    *(s32 *)arg0 = word;
    *((u8 *)arg0 + 4) = byte4;
    dst->pad = pad;
    dst->flag = flag;
    if (mask != 0) {
        temp = fn_800C30CC(lbl_803206EC, mask);
        if (dst->rest == 0) {
            dst->rest = fn_800C3260(lbl_803206EC);
        }
        dst->rest = fn_800C30DC(lbl_803206EC, dst->rest, temp);
    }
    return arg0;
}

void *Item_Init(void *arg0) {
    void Icon_FreeSlot(void *, s32);
    extern u8 gIconSlots[];
    typedef struct {
        u8 pad : 1;
        u8 flag : 1;
        u8 rest : 6;
    } Bit6;
    Bit6 *bf;
    s32 mask;

    bf = (Bit6 *)((u8 *)arg0 + 5);
    bf->rest = 0;
    *(s32 *)arg0 = 0;
    *((u8 *)arg0 + 4) = 0;
    bf->pad = 0;
    bf->flag = 0;
    mask = *((u8 *)arg0 + 5) & 0x3F;
    if (mask != 0) {
        Icon_FreeSlot(gIconSlots, mask);
        bf->rest = 0;
    }
    return arg0;
}

void fn_8001C7F0(void *unused, void *arg1, void *arg2) {
void strcpy(void *, s32);
void strcat(void *, void *);
void *Res_GetByName(void *);
extern void *lbl_80367230;
extern u8 lbl_802CA4FC[], gDataStr[];
void *obj;
if(lbl_80367230 != arg1) {
lbl_80367230=arg1;
strcpy(lbl_802CA4FC,*(s32 *)arg1);
strcat(lbl_802CA4FC,gDataStr+0x3C);
}
obj=Res_GetByName(lbl_802CA4FC);
if(obj==0) {
(*(void (**)(void *))((u8 *)obj+0xC))(arg2);
}
}

s32 fn_8001C878(void *unused, void *arg1, void *arg2) {
    void strcpy(void *, s32);
    void strcat(void *, void *);
    void *Res_GetByName(void *);
    extern void *gItemUfxCache;
    extern u8 gItemUfxPath[];
    extern u8 gDataStr[];
    void *obj;
    void **p;

    (void)unused;
    if (gItemUfxCache != arg1) {
        gItemUfxCache = arg1;
        strcpy(gItemUfxPath, *(s32 *)arg1);
        strcat(gItemUfxPath, gDataStr + 0x3C);
    }
    obj = Res_GetByName(gItemUfxPath);
    if (obj != 0) {
    } else {
        obj = 0;
    }
    p = (void **)obj;
    if (p[2] != 0) {
        ((void (*)(void *))p[2])(arg2);
        return 1;
    }
    return 0;
}

u32 Item_CallUfx(void *arg0, void *arg1) {
    void strcpy(void *, s32);
    void strcat(void *, void *);
    void *Res_GetByName(void *);
    extern void *gItemUfxCache;
    extern u8 gItemUfxPath[];
    extern u8 gDataStr[];
    void *obj;

    if (gItemUfxCache != arg1) {
        gItemUfxCache = arg1;
        strcpy(gItemUfxPath, *(s32 *)arg1);
        strcat(gItemUfxPath, gDataStr + 0x3C);
    }
    obj = Res_GetByName(gItemUfxPath);
    if (obj == 0) {
        obj = 0;
    }
    if (obj == 0) {
        return 0;
    }
    return (*(u32 (**)(void *, void *))obj)(arg0, arg1);
}

u32 Item_GetUfx(void *arg0) {
    void strcpy(void *, s32);
    void strcat(void *, void *);
    u32 Res_GetByName(void *);
    extern void *gItemUfxCache;
    extern u8 gItemUfxPath[];
    extern u8 gDataStr[];
    u32 ret;

    if (gItemUfxCache != arg0) {
        gItemUfxCache = arg0;
        strcpy(gItemUfxPath, *(s32 *)arg0);
        strcat(gItemUfxPath, gDataStr + 0x3C);
    }
    ret = Res_GetByName(gItemUfxPath);
    if (ret == 0) {
        return 0;
    }
    return ret;
}

s32 fn_8001CA2C(void *arg0) {
void *data;
u64 *ptr;
u32 flags;
s32 value;
u32 price;
if (*(void **)arg0==0) return 0;
value=0;
if ((s8)gItemFlagsDummyReady==0) {
gItemFlagsDummyHi=0;gItemFlagsDummy=0;gItemFlagsDummyReady=1;
}
if(*(void **)arg0) ptr=(u64 *)((u8 *)*(void **)arg0+0x38);
else ptr=(u64 *)&gItemFlagsDummy;
flags=(u32)*ptr;
if(flags&0x3007FF80000ULL) value+=50000;
price=0;
data=*(void **)arg0;
if(data) price=*(u16 *)((u8 *)data+0x10);
value+=(u16)(price * *(u8 *)((u8 *)arg0+4));
if(flags&4) value+=10000;
if(flags&0x10) value+=10000;
if(flags&8) value+=10000;
if(flags&0x20) value+=2000;
if(flags&0x80) value+=2000;
if(flags&0x1000000000ULL) value+=2000;
if(flags&0x40) value+=2000;
if(flags&0x400) value+=2000;
if(flags&0x800) value+=1000;
if(flags&0x4000) value+=1000;
return value;
}

void *Item_GetFlagsPtr(void *arg0)
{
    extern u8 gItemFlagsDummyReady;
    extern s32 gItemFlagsDummyHi;
    extern s32 gItemFlagsDummy;

    void *ptr;

    if ((s8)gItemFlagsDummyReady == 0) {
        gItemFlagsDummyHi = 0;
        gItemFlagsDummy = 0;
        gItemFlagsDummyReady = 1;
    }

    ptr = *(void **)arg0;

    if (ptr != 0) {
        return (u8 *)ptr + 0x38;
    }

    return &gItemFlagsDummy;
}

#pragma peephole off
#pragma scheduling off
s32 fn_8001CBA0(u8 *arg0) {
    if (arg0[0] >= 0xFB) {
        return 0;
    }
    if (arg0[1] >= 0xFB) {
        return 1;
    }
    if (arg0[2] >= 0xFB) {
        return 2;
    }
    if (arg0[3] >= 0xFB) {
        return 3;
    }
    if (arg0[4] >= 0xFB) {
        return 4;
    }
    if (arg0[5] >= 0xFB) {
        return 5;
    }
    if (arg0[6] >= 0xFB) {
        return 6;
    }
    if (arg0[7] >= 0xFB) {
        return 7;
    }
    return -1;
}
#pragma peephole reset
#pragma scheduling reset
void fn_8001CC48(u8 *dst, u8 *src) {
    s32 i;

    for (i = 0; i < 8; i++) {
        switch ((s8)src[i]) {
        case 'S':
            dst[i] = 0xFB;
            break;
        case 'A':
            dst[i] = 0xB5;
            break;
        case 'B':
            dst[i] = 0x79;
            break;
        case 'C':
            dst[i] = 0x47;
            break;
        case 'D':
            dst[i] = 0x1F;
            break;
        case 'E':
            dst[i] = 0x01;
            break;
        case '-':
            dst[i] = 0;
            break;
        case '*':
            dst[i] = 0;
            break;
        }
    }
}

/* Returns the next weapon-rank exp threshold above the current value (E→D→C→B→A→S). */
s32 WpnRank_GetNext(u8 exp) {
    u8 rank;

    if (exp >= 0xFBU) {
        rank = 0xFB;
    } else if (exp >= 0xB5U) {
        rank = 0xB5;
    } else if (exp >= 0x79U) {
        rank = 0x79;
    } else if (exp >= 0x47U) {
        rank = 0x47;
    } else if (exp >= 0x1FU) {
        rank = 0x1F;
    } else if (exp >= 1U) {
        rank = 1;
    } else {
        rank = 0;
    }
    switch ((s32) rank) {                         /* irregular */
    case 0x0:
        return 0;
    case 0xFB:
        return 0xFB;
    case 0x1:
        return 0x1F;
    case 0x1F:
        return 0x47;
    case 0x47:
        return 0x79;
    case 0x79:
        return 0xB5;
    case 0xB5:
        return 0xFB;
    default:
        return 0;
    }
}

void *WpnRank_GetLetter(u8 arg0)
{
    extern u8 gDataStr[];

    if (arg0 >= 0xFBU) {
        return gDataStr + 0x41;
    }
    if (arg0 >= 0xB5U) {
        return gDataStr + 0x6;
    }
    if (arg0 >= 0x79U) {
        return gDataStr + 0x4;
    }
    if (arg0 >= 0x47U) {
        return gDataStr + 0x2;
    }
    if (arg0 >= 0x1FU) {
        return gDataStr + 0x43;
    }
    if (arg0 >= 1U) {
        return gDataStr + 0x45;
    }
    return gDataStr;
}

s32 fn_8001CE78(void *arg0) {
s32 Str_Cmp(void *,void *);
extern u8 gDataStr[];
if (!arg0) return 0;
if (Str_Cmp(arg0,gDataStr+0x41)==0) return 0xFB;
if (Str_Cmp(arg0,gDataStr+6)==0) return 0xB5;
if (Str_Cmp(arg0,gDataStr+4)==0) return 0x79;
if (Str_Cmp(arg0,gDataStr+2)==0) return 0x47;
if (Str_Cmp(arg0,gDataStr+0x43)==0) return 0x1F;
if (Str_Cmp(arg0,gDataStr+0x45)==0) return 1;
if (Str_Cmp(arg0,gDataStr+0x47)!=0) return 0;
return 0;
}

#pragma peephole off
u32 fn_8001CFA8(u8 arg0) {
    if (arg0 >= 0xFBU) {
        return 0xFBU;
    }
    if (arg0 >= 0xB5U) {
        return 0xB5U;
    }
    if (arg0 >= 0x79U) {
        return 0x79U;
    }
    if (arg0 >= 0x47U) {
        return 0x47U;
    }
    if (arg0 >= 0x1FU) {
        return 0x1FU;
    }
    return arg0 >= 1U;
}
#pragma peephole reset
void fn_8001D018(s32 arg0, s32 arg1) {
    M2C_UNK Stream_Read(s32, M2C_UNK, s32);
    Stream_Read(arg1, 8, arg0);
}

void fn_8001D044(s32 arg0, s32 arg1) {
    M2C_UNK Stream_Write(s32, M2C_UNK, s32);
    Stream_Write(arg1, 8, arg0);
}

void *fn_8001D070(u8 *p,u8 mode) {
 extern u8 gDataStr[];
 void *Res_GetByName(void *);
 char *Msg_Expand(void *);
 u8 *item;
 char *name;
 s32 kind;
 item=*(u8 **)p;
 if(!item) return gDataStr+0x3B;
 if(p[5]&63) return mode?gDataStr+0x49:gDataStr+0x4E;
 if(*(u64 *)(item+0x38)&0x40000000000ULL) kind=1;
 else if(*(u64 *)(item+0x38)&0x80000000000ULL) kind=2;
 else if(*(u64 *)(item+0x38)&0x100000000000ULL) kind=3;
 else if(*(u64 *)(item+0x38)&0x200000000000ULL) kind=0;
 else if(*(u64 *)(item+0x38)&0x20000000000ULL) kind=3;
 else {
 if(Res_GetByName(*(void **)(item+4))) name=Msg_Expand(*(void **)(item+4)); else name=*(char **)item;
 if(!name) kind=0;
 else switch(*name) {
 case 'A':case 'E':case 'I':case 'O':case 'U':
 case 'a':case 'e':case 'i':case 'o':case 'u':kind=2;break;
 default:kind=1;break;
 }
 }
 if(mode) {
 switch(kind) {case 1:return gDataStr+0x53;case 2:return gDataStr+0x56;case 3:return gDataStr+0x49;}
 } else {
 switch(kind) {case 1:return gDataStr+0x5A;case 2:return gDataStr+0x5D;case 3:return gDataStr+0x4E;}
 }
 return gDataStr+0x3B;
}

u16 UnitRef_GetValue(void* arg0) {
    void** temp_r4 = (void**)arg0;
    u16 var_r5 = 0;

    if (*temp_r4 != NULL) {
        var_r5 = *(u16*)((char*)*temp_r4 + 0x10);
    }

    return (u16)(var_r5 * *(u8*)((char*)arg0 + 4));
}

void *UnitRef_GetName(void *arg0) {
    u8 *fn_800C2E3C(u8 *, s32);
    void *Res_GetByName(void *);
    void *Msg_Expand(void *);
    extern u8 gIconSlots[];
    u8 flag;
    void *inner;
    s32 mask;

    if (*(void **)arg0 == NULL) {
        return NULL;
    }
    mask = *((u8 *)arg0 + 5) & 0x3F;
    if (mask != 0) {
        flag = (u8)((s8)*fn_800C2E3C(gIconSlots, mask) != 0);
    } else {
        flag = 0;
    }
    if (flag == 0) {
        inner = *(void **)arg0;
        if (Res_GetByName(*(void **)((u8 *)inner + 4)) != NULL) {
            return Msg_Expand(*(void **)((u8 *)inner + 4));
        }
        return *(void **)inner;
    }
    return fn_800C2E3C(gIconSlots, *((u8 *)arg0 + 5) & 0x3F);
}

u8 Item_GetWt(void *arg0) {
    s32 fn_800C2ACC(void *, s32);
    extern u8 gIconSlots[];
    s8 result;
    s32 mask;
    s32 diff;
    u8 *inner;

    if (*(void **)arg0 == NULL) {
        return 0U;
    }
    mask = *((u8 *)arg0 + 5) & 0x3F;
    if (mask == 0) {
        result = 0;
    } else {
        result = fn_800C2ACC(gIconSlots, mask);
    }
    inner = *(u8 **)arg0;
    diff = inner[0x1B] - result;
    if (diff < 1) {
        diff = 1;
    }
    return (u8)diff;
}

u8 fn_8001D3FC(void *arg0) {
    s32 fn_800C2BA8(void *, s32);
    extern u8 gIconSlots[];
    s8 result;
    s32 mask;
    s32 var;
    u8 *inner;
    if (*(void **)arg0 == NULL) {
        return 0U;
    }
    mask = *((u8 *)arg0 + 5) & 0x3F;
    if (mask == 0) {
        result = 0;
    } else {
        result = fn_800C2BA8(gIconSlots, mask);
    }
    inner = *(u8 **)arg0;
    var = inner[0x1C] + result * 3;
    if (var < 0) {
        var = 0;
    }
    return (u8)var;
}

u8 fn_8001D47C(void *arg0) {
    s32 fn_800C2C84(void *, s32);
    extern u8 gIconSlots[];
    s8 result;
    s32 mask;
    s32 var;
    u8 *inner;

    if (*(void **)arg0 == NULL) {
        return 0U;
    }
    mask = *((u8 *)arg0 + 5) & 0x3F;
    if (mask == 0) {
        result = 0;
    } else {
        result = fn_800C2C84(gIconSlots, mask);
    }
    inner = *(u8 **)arg0;
    var = inner[0x1A] + result * 5;
    if (var < 1) {
        var = 1;
    }
    return (u8)var;
}

u8 fn_8001D500(void *arg0) {
    s32 fn_800C2D60(void *, s32);
    extern u8 gIconSlots[];
    s8 result;
    s32 mask;
    s32 var;
    u8 *inner;

    if (*(void **)arg0 == NULL) {
        return 0U;
    }
    mask = *((u8 *)arg0 + 5) & 0x3F;
    if (mask == 0) {
        result = 0;
    } else {
        result = fn_800C2D60(gIconSlots, mask);
    }
    inner = *(u8 **)arg0;
    var = inner[0x19] + result;
    if (var < 1) {
        var = 1;
    }
    return (u8)var;
}

void Item_Clear(void *arg0) {
    void Icon_FreeSlot(void *, s32);
    extern u8 gIconSlots[];
    typedef struct {
        u8 pad : 1;
        u8 flag : 1;
        u8 rest : 6;
    } Bit6;
    Bit6 *bf;
    s32 mask;

    *(s32 *)arg0 = 0;
    *((u8 *)arg0 + 4) = 0;
    bf = (Bit6 *)((u8 *)arg0 + 5);
    bf->pad = 0;
    bf->flag = 0;
    mask = *((u8 *)arg0 + 5) & 0x3F;
    if (mask != 0) {
        Icon_FreeSlot(gIconSlots, mask);
        bf->rest = 0;
    }
}

s32 Item_SetUses(void *arg0, u8 arg1) {
    void Icon_FreeSlot(void *, s32);
    extern u8 gIconSlots[];
    typedef struct {
        u8 pad : 1;
        u8 flag : 1;
        u8 rest : 6;
    } BitField;
    BitField *bf;

    *(u8 *)((u8 *)arg0 + 4) = arg1;
    if (*(u8 *)((u8 *)arg0 + 4) == 0) {
        *(s32 *)arg0 = 0;
        *(u8 *)((u8 *)arg0 + 4) = 0;
        bf = (BitField *)((u8 *)arg0 + 5);
        bf->pad = 0;
        bf->flag = 0;
        if (bf->rest != 0) {
            Icon_FreeSlot(gIconSlots, bf->rest);
            bf->rest = 0;
        }
        return 1;
    }
    return 0;
}

s32 Item_DecUses(void *item) {
    /* Decrement item uses unless unbreakable; clear the slot when uses hit 0. */
    void Icon_FreeSlot(void *, s32);
    extern u8 gItemFlagsDummyReady;
    extern s32 gItemFlagsDummy;
    extern s32 gItemFlagsDummyHi;
    extern u8 gIconSlots[];
    typedef struct {
        u8 pad : 1;
        u8 flag : 1;
        u8 rest : 6;
    } Bit6;
    unsigned long long *flags;
    Bit6 *bf;
    s32 mask;

    if ((s8)gItemFlagsDummyReady == 0) {
        gItemFlagsDummyHi = 0;
        gItemFlagsDummy = 0;
        gItemFlagsDummyReady = 1;
    }

    if (*(void **)item != 0) {
        flags = (unsigned long long *)((u8 *)*(void **)item + 0x38);
    } else {
        flags = (unsigned long long *)&gItemFlagsDummy;
    }

    if ((*flags & 0x10000000000ULL) != 0) {
        return 0;
    }

    *((u8 *)item + 4) = *((u8 *)item + 4) - 1;
    if (*((u8 *)item + 4) == 0) {
        *(void **)item = 0;
        *((u8 *)item + 4) = 0;
        bf = (Bit6 *)((u8 *)item + 5);
        bf->pad = 0;
        bf->flag = 0;
        mask = *((u8 *)item + 5) & 0x3F;
        if (mask != 0) {
            Icon_FreeSlot(gIconSlots, mask);
            bf->rest = 0;
        }
        return 1;
    }
    return 0;
}

s32 Item_SetByName(void *arg0, void *arg1)
{
    void *Res_GetByName(void *);
    void Icon_FreeSlot(void *, s32);
    extern u8 gIconSlots[];
    typedef struct {
        u8 pad : 1;
        u8 flag : 1;
        u8 rest : 6;
    } Bit6;
    Bit6 *bf;
    s32 mask;
    void *result;

    result = Res_GetByName(arg1);
    *(s32 *)arg0 = 0;
    *((u8 *)arg0 + 4) = 0;
    bf = (Bit6 *)((u8 *)arg0 + 5);
    bf->pad = 0;
    bf->flag = 0;
    mask = *((u8 *)arg0 + 5) & 0x3F;
    if (mask != 0) {
        Icon_FreeSlot(gIconSlots, mask);
        bf->rest = 0;
    }
    *(void **)arg0 = result;
    *((u8 *)arg0 + 4) = *((u8 *)result + 0x18);
    return 1;
}

s32 UnitRef_Set(void *arg0, void *arg1) {
    void Icon_FreeSlot(void *, s32);
    extern u8 gIconSlots[];
    typedef struct {
        u8 pad : 1;
        u8 flag : 1;
        u8 rest : 6;
    } Bit6;
    Bit6 *bf;
    s32 mask;

    *(s32 *)arg0 = 0;
    *((u8 *)arg0 + 4) = 0;
    bf = (Bit6 *)((u8 *)arg0 + 5);
    bf->pad = 0;
    bf->flag = 0;
    mask = *((u8 *)arg0 + 5) & 0x3F;
    if (mask != 0) {
        Icon_FreeSlot(gIconSlots, mask);
        bf->rest = 0;
    }
    *(void **)arg0 = arg1;
    *((u8 *)arg0 + 4) = *((u8 *)arg1 + 0x18);
    return 1;
}

char *Unit_FormatAttrFlags(u16 *flags) {
    /* Concatenate gDataStr attribute labels for each set bit in *flags into gAttrFlagsStr. */
    extern char gAttrFlagsStr[];
    extern char gDataStr[];
    char *buf;
    u16 *p;

    p = flags;
    buf = gAttrFlagsStr;
    buf[0] = 0;
    if (*p & 1) {
        strcat(buf, gDataStr + 0xD4);
    }
    if (*p & 2) {
        strcat(gAttrFlagsStr, gDataStr + 0xD8);
    }
    if (*p & 4) {
        strcat(gAttrFlagsStr, gDataStr + 0xDC);
    }
    if (*p & 8) {
        strcat(gAttrFlagsStr, gDataStr + 0xE4);
    }
    if (*p & 0x10) {
        strcat(gAttrFlagsStr, gDataStr + 0xE8);
    }
    if (*p & 0x20) {
        strcat(gAttrFlagsStr, gDataStr + 0xEE);
    }
    if (*p & 0x40) {
        strcat(gAttrFlagsStr, gDataStr + 0xF4);
    }
    if (*p & 0x80) {
        strcat(gAttrFlagsStr, gDataStr + 0xF8);
    }
    if (*p & 0x100) {
        strcat(gAttrFlagsStr, gDataStr + 0xFC);
    }
    if (*p & 0x200) {
        strcat(gAttrFlagsStr, gDataStr + 0x100);
    }
    if (*p & 0x400) {
        strcat(gAttrFlagsStr, gDataStr + 0x106);
    }
    if (*p & 0x800) {
        strcat(gAttrFlagsStr, gDataStr + 0x10E);
    }
    return gAttrFlagsStr;
}

/* OR one map-move SFX category bit into *flags from the category name (mage, fly, …). */
void Unit_OrMSfxFlag(u16 *flags, char *name) {
    s32 Str_Cmp(char *, char *);
    extern u8 gDataStr[];

    if (name != NULL) {
        if (Str_Cmp(name, (char *)gDataStr + 0x113) == 0) {
            *flags |= MSFX_FLAG_MAGE;
        } else if (Str_Cmp(name, (char *)gDataStr + 0x118) == 0) {
            *flags |= MSFX_FLAG_FLY;
        } else if (Str_Cmp(name, (char *)gDataStr + 0x11C) == 0) {
            *flags |= MSFX_FLAG_KNIGHT;
        } else if (Str_Cmp(name, (char *)gDataStr + 0x123) == 0) {
            *flags |= MSFX_FLAG_ARMOR;
        } else if (Str_Cmp(name, (char *)gDataStr + 0x129) == 0) {
            *flags |= MSFX_FLAG_ALIZE;
        } else if (Str_Cmp(name, (char *)gDataStr + 0x12F) == 0) {
            *flags |= MSFX_FLAG_HUMAN;
        } else if (Str_Cmp(name, (char *)gDataStr + 0x135) == 0) {
            *flags |= MSFX_FLAG_BEAST;
        } else if (Str_Cmp(name, (char *)gDataStr + 0x13B) == 0) {
            *flags |= MSFX_FLAG_DRAGON;
        } else if (Str_Cmp(name, (char *)gDataStr + 0x142) == 0) {
            *flags |= MSFX_FLAG_BIRD;
        } else if (Str_Cmp(name, (char *)gDataStr + 0x147) == 0) {
            *flags |= MSFX_FLAG_FINAL;
        } else if (Str_Cmp(name, (char *)gDataStr + 0x14D) == 0) {
            *flags |= MSFX_FLAG_HERO;
        } else if (Str_Cmp(name, (char *)gDataStr + 0x152) == 0) {
            *flags |= MSFX_FLAG_BOSS;
        } else if (Str_Cmp(name, (char *)gDataStr + 0x157) == 0) {
            *flags |= MSFX_FLAG_DOORBREAK;
        }
    }
}

u8 fn_8001DD04(void) {
    s8 Unit_GetMagAtk();
    s8 temp_r3;
    u8 var_r3;

    temp_r3 = Unit_GetMagAtk();
    var_r3 = (u8) ((s32) (((u32) temp_r3 >> 0x1FU) + temp_r3) >> 1);
    if (var_r3 < 5U) {
        var_r3 = 5;
    }
    if (var_r3 > 0xFU) {
        var_r3 = 0xF;
    }
    return var_r3;
}

u8 Item_GetRangeForUnit(void *arg0, s32 arg1) {
    s8 temp_r3;
    u8 var_r3;

    var_r3 = M2C_FIELD(arg0, u8 *, 0x1E);
    if (var_r3 == 0xFF) {
        temp_r3 = Unit_GetMagAtk(arg1);
        var_r3 = (u8) ((s32) (((u32) temp_r3 >> 0x1FU) + temp_r3) >> 1);
        if (var_r3 < 5U) {
            var_r3 = 5;
        }
        if (var_r3 > 0xFU) {
            var_r3 = 0xF;
        }
    }
    return var_r3;
}

u8 fn_8001DDB4(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x1E);
}

u8 Item_GetMaxRange(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x1E);
}

s32 fn_8001DDC4(u8 arg0) {
    if ((arg0 >= 4U) && (arg0 <= 7U)) {
        return 1;
    }
    return 0;
}

u8 fn_8001DDE8(void *arg0) {
    return (u8)((*(unsigned long long *)((u8 *)arg0 + 0x38) & 0x40EULL) != 0);
}

/* Returns the display name for weapon type kind (0–11); kind 7 picks an alternate if flag != 0. */
char *WpnType_GetName(u8 kind, u8 flag)
{
    extern u8 gDataStr[];

    switch (kind) {
    case 0:
        return (char *)gDataStr + 0x2D4;

    case 1:
        return (char *)gDataStr + 0x2DA;

    case 2:
        return (char *)gDataStr + 0x2E0;

    case 3:
        return (char *)gDataStr + 0x2E4;

    case 4:
        return (char *)gDataStr + 0x2E8;

    case 5:
        return (char *)gDataStr + 0x2ED;

    case 6:
        return (char *)gDataStr + 0x2F5;

    case 7:
        if (flag != 0) {
            return (char *)gDataStr + 0x2FA;
        }
        return (char *)gDataStr + 0x300;

    case 8:
        return (char *)gDataStr + 0x306;

    case 9:
        return (char *)gDataStr + 0x30B;

    case 10:
        return (char *)gDataStr + 0x30E;

    case 11:
        return (char *)gDataStr + 0x311;

    default:
        return (char *)gDataStr + 0x314;
    }
}

char *fn_8001E5D0(u8 arg0, u8 arg1) {
extern u8 gDataStr[];
char *Msg_Expand(void *);
switch(arg0) {
case 0: return Msg_Expand(gDataStr+0x317);
case 1: return Msg_Expand(gDataStr+0x31e);
case 2: return Msg_Expand(gDataStr+0x325);
case 3: return Msg_Expand(gDataStr+0x32c);
case 4: return Msg_Expand(gDataStr+0x333);
case 5: return Msg_Expand(gDataStr+0x33a);
case 6: return Msg_Expand(gDataStr+0x341);
case 7: if(arg1) return Msg_Expand(gDataStr+0x348);
return Msg_Expand(gDataStr+0x34F);
case 8: return Msg_Expand(gDataStr+0x356);
case 9: return (char *)gDataStr+0x30B;
case 10: return (char *)gDataStr+0x30E;
case 11: return (char *)gDataStr+0x311;
default: return (char *)gDataStr+0x314;
}
}

void fn_8001E71C(u8 *arg0) {
    u8 v = arg0[0x12];

    if (v != 7) {
        if (v >= 7) {
            if (v == 0xB) {
                *(u32 *)(arg0 + 0x3C) |= 0x10;
            } else if (v < 0xC) {
                if (v >= 0xA) {
                    *(u32 *)(arg0 + 0x3C) |= 8;
                } else {
                    *(u32 *)(arg0 + 0x3C) |= 1;
                }
            }
        } else if (v >= 4) {
            *(u32 *)(arg0 + 0x3C) |= 3;
        } else if (v >= 0) {
            *(u32 *)(arg0 + 0x3C) |= 1;
        }
    } else if (arg0[0x19] != 0) {
        *(u32 *)(arg0 + 0x3C) |= 3;
    } else {
        *(u32 *)(arg0 + 0x3C) |= 4;
    }
}

/* Map a special item IID string to its ItemData kind (0x81–0x87), or 0xC for normal items. */
s32 Item_GetKindFromIid(char *iid) {
    s32 Str_Cmp(void *, void *);
    extern u8 gDataStr[];

    if (Str_Cmp(iid, gDataStr + 0x35D) == 0) { /* IID_LIVE */
        return 0x81;
    }
    if (Str_Cmp(iid, gDataStr + 0x366) == 0) { /* IID_RELIVE */
        return 0x81;
    }
    if (Str_Cmp(iid, gDataStr + 0x371) == 0) { /* IID_RECOVER */
        return 0x81;
    }
    if (Str_Cmp(iid, gDataStr + 0x37D) == 0) { /* IID_REBLOW */
        return 0x81;
    }
    if (Str_Cmp(iid, gDataStr + 0x388) == 0) { /* IID_RESERVE */
        return 0x81;
    }
    if (Str_Cmp(iid, gDataStr + 0x394) == 0) { /* IID_REST */
        return 0x83;
    }
    if (Str_Cmp(iid, gDataStr + 0x39D) == 0) { /* IID_SLEEP */
        return 0x84;
    }
    if (Str_Cmp(iid, gDataStr + 0x3A7) == 0) { /* IID_BERSERK */
        return 0x84;
    }
    if (Str_Cmp(iid, gDataStr + 0x3B3) == 0) { /* IID_SILENCE */
        return 0x84;
    }
    if (Str_Cmp(iid, gDataStr + 0x3BF) == 0) { /* IID_WARP */
        return 0x85;
    }
    if (Str_Cmp(iid, gDataStr + 0x3C8) == 0) { /* IID_RESCUE */
        return 0x85;
    }
    if (Str_Cmp(iid, gDataStr + 0x3D3) == 0) { /* IID_HAMMERNE */
        return 0x86;
    }
    if (Str_Cmp(iid, gDataStr + 0x3E0) == 0) { /* IID_MSHIELD */
        return 0x87;
    }
    if (Str_Cmp(iid, gDataStr + 0x3EC) == 0) { /* IID_TORCH */
        return 0x87;
    }
    if (Str_Cmp(iid, gDataStr + 0x3F6) == 0) { /* IID_UNLOCK */
        return 0x85;
    }
    if (Str_Cmp(iid, gDataStr + 0x401) == 0) { /* IID_VULNERARY */
        return 0x81;
    }
    if (Str_Cmp(iid, gDataStr + 0x40F) == 0) { /* IID_ELIXIR */
        return 0x81;
    }
    if (Str_Cmp(iid, gDataStr + 0x41A) == 0) { /* IID_TREASUREKEY */
        return 0x85;
    }
    if (Str_Cmp(iid, gDataStr + 0x42A) == 0) { /* IID_DOORKEY */
        return 0x85;
    }
    if (Str_Cmp(iid, gDataStr + 0x436) == 0) { /* IID_ROBBERSKEY */
        return 0x85;
    }
    if (Str_Cmp(iid, gDataStr + 0x445) == 0) { /* IID_DETOXDRUG */
        return 0x83;
    }
    if (Str_Cmp(iid, gDataStr + 0x453) == 0) { /* IID_HOLYWATER */
        return 0x87;
    }
    if (Str_Cmp(iid, gDataStr + 0x461) == 0) { /* IID_JACKLIGHT */
        return 0x87;
    }
    return Str_Cmp(iid, gDataStr + 0x46F) ? 0xC : 0x85; /* IID_MINE or default item */
}

s32 fn_8001EB44(const char *arg0)
{
    extern u8 gDataStr[];
    extern s32 Str_Cmp(const char *, const char *);

    if (Str_Cmp(arg0, (char *)gDataStr + 0x478) == 0) {
        return 0;
    }

    if (Str_Cmp(arg0, (char *)gDataStr + 0x47E) == 0) {
        return 1;
    }

    if (Str_Cmp(arg0, (char *)gDataStr + 0x484) == 0) {
        return 2;
    }

    if (Str_Cmp(arg0, (char *)gDataStr + 0x488) == 0) {
        return 3;
    }

    if (Str_Cmp(arg0, (char *)gDataStr + 0x48C) == 0) {
        return 4;
    }

    if (Str_Cmp(arg0, (char *)gDataStr + 0x492) == 0) {
        return 5;
    }

    if (Str_Cmp(arg0, (char *)gDataStr + 0x49A) == 0) {
        return 6;
    }

    if (Str_Cmp(arg0, (char *)gDataStr + 0x49F) == 0) {
        return 7;
    }

    if (Str_Cmp(arg0, (char *)gDataStr + 0x4A3) == 0) {
        return 8;
    }

    if (Str_Cmp(arg0, (char *)gDataStr + 0x188) == 0) {
        return 9;
    }

    if (Str_Cmp(arg0, (char *)gDataStr + 0x4A9) == 0) {
        return 10;
    }

    return Str_Cmp(arg0, (char *)gDataStr + 0x4AE) == 0 ? 11 : 0;
}

void *fn_8001ED1C(void *arg0) {
    void *Msg_Expand(void *);
    extern u8 gDataStr[];
    void *v;

    v = *(void **)((char *)arg0 + 8);
    if (v == NULL) {
        return gDataStr + 0x4BE;
    }
    return Msg_Expand(v);
}

s32 fn_8001ED58(void *arg0) {
    s32 Msg_Expand(s32);
    if (Res_GetByName(M2C_FIELD(arg0, s32 *, 4)) != 0U) {
        return Msg_Expand(M2C_FIELD(arg0, s32 *, 4));
    }
    return M2C_FIELD(arg0, s32 *, 0);
}

void fn_8001EDA0(u8 *arg0) {
    u8 temp_r4;

    temp_r4 = *arg0;
    if (temp_r4 & 0x80) {
        *arg0 = temp_r4 | 3;
    }
}

void Item_GetKeyFlags(u8 *out, void *key) {
    void *Item_GetByIid(void *);
    extern u8 gDataStr[];
    s32 flags;

    flags = 0;
    if (key == Item_GetByIid(gDataStr + 0x41A)) {
        flags |= 1;
    } else if (key == Item_GetByIid(gDataStr + 0x42A)) {
        flags |= 2;
    } else if (key == Item_GetByIid(gDataStr + 0x436)) {
        flags |= 0x80;
    }
    *out = (u8)flags;
}

extern void *lbl_80367204;
extern s32 lbl_80367208;
#include "common.h"
extern void *lbl_80367204;
extern s32 lbl_80367208;
#include "common.h"
extern void *gPadInput;
extern f64 lbl_80368C98;
extern f64 lbl_80368D18;
extern f32 lbl_80368C88;
extern f32 lbl_80368C8C;
extern f32 lbl_80368CA4;
extern f32 lbl_80368CE4;
extern f32 lbl_80368D08;
extern f32 lbl_80368D0C;
extern f32 lbl_80368D10;
#include "common.h"
#include "global.h"
#include "m2c_macros.h"
extern u16 gIconSlots;
s32 Icon_AllocSlot(u16 *);
s32 fn_800C2D74(u16 *, s32, s32);
