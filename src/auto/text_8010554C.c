/* Functions from 0x8010554C to 0x80110128, found by decomp-toolkit. */
#include "common.h"

typedef struct SoundTweenProc {
    u8 pad0[0x18];
    void *parent;
    u8 pad1C[0x14];
    void *target;
    u8 param, mode;
    u8 pad36[2];
    f32 time, duration, start, end;
} SoundTweenProc;

static inline s32 fn_8010EF74_cost(u8 *map, s8 x, s8 y) {
    return (*(s16 **)(map + 0x14190))[x + (y << 6)];
}

static inline u8 fn_8010CF28_check(void *a, void *b) {
    u8 Allegiance_Compare(void *, void *);
    return Allegiance_Compare(a, b) == 1;
}

extern double lbl_8036A128;
extern double lbl_8036A120;
extern f32 lbl_8036A134;
extern f32 lbl_8036A130;

typedef struct AiParam {
    void *p;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    s32 unk8;
    u8 bC[4];
} AiParam;

typedef struct AiBest {
    void *unit;
    s16 y;
    s16 x;
    u8 rank;
} AiBest;

#pragma cplusplus on
struct UnkObject {
    u8 pad[4];
    virtual void v0();
    virtual void v1(s32);
};
#pragma cplusplus off

struct UnkCycler {
    u8 pad0[4];
    u8 unk4;
    u8 unk5;
    u16 unk6;
    u8 pad8[0x14 - 8];
    struct UnkObject *unk14[];
};

struct Arg0 {
    u8 pad0[0x30];
    struct UnkCycler *unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    u8 unk60;
    u8 unk61;
};

extern u16 lbl_802737A0[];

static inline void *GetUnitIfBitSet(u32 *bits, u8 id) {
    void *Res_GetEntry(u8);
    s32 n = id;

    if (n < 0) {
        return NULL;
    } else {
        u32 *p = bits;

        while (n >= 32) {
            p++;
            n -= 32;
        }
        if (!(*p & (1 << n))) {
            return NULL;
        }
        return Res_GetEntry(id);
    }
}

void fn_8010554C(void) {
    extern u16 lbl_802737A0[];
    extern u16 lbl_8028F2D0[];
    
    fn_8000D3EC(&lbl_802737A0[0xCE/2], &lbl_8028F2D0[0], &lbl_802737A0[0]);
    fn_8000D3EC(&lbl_802737A0[0xE2/2], &lbl_8028F2D0[0], &lbl_802737A0[0]);
    fn_8000D3EC(&lbl_802737A0[0xF2/2], &lbl_8028F2D0[0], &lbl_802737A0[0]);
}

s32 fn_801055B0(s32 arg0) {
    void fn_800BEAC0(s32, s32, s32, s32);
    void fn_80094A08(s32, s32);
    extern struct {
        s32 unk0;
        s32 unk4;
        u8 unk8;
        u8 unk9;
        s8 unkA;
        u8 padB[4];
        u8 unkF;
        u8 unk10;
    } gUiContext;
    extern u8 gBattle[];
    s8 temp;

    fn_800BEAC0(arg0, gUiContext.unk8, gUiContext.unkF, gUiContext.unk10);

    temp = gUiContext.unkA;
    if (temp < 0) {
        return 1;
    }

    fn_80094A08(gUiContext.unk0, temp);
    *(u32 *)(gBattle + 0xCAC) |= 0x2000;
    return 1;
}

void fn_80105624(s32 arg0) {
    void *UiCtx_GetItemSlot(void *);
    void Item_GetKeyFlags(void *, s32);
    void fn_80026770(void *, void *);
    void fn_800319E8(s32);
    extern struct {
        s32 unk0;
        s32 unk4;
        u8 unk8;
        u8 unk9;
        s8 unkA;
        u8 padB[4];
        u8 unkF;
        u8 unk10;
    } gUiContext;
    u8 sp8;
    void *temp;

    gUiContext.unk8 = 0xA;
    temp = UiCtx_GetItemSlot(&gUiContext);
    Item_GetKeyFlags(&sp8, *(s32 *)temp);
    fn_80026770(&gUiContext, &sp8);
    fn_800319E8(arg0);
}

s32 fn_8010568C(s32 arg0) {
    void fn_8001EDA0(u8 *);
    void Item_GetKeyFlags(u8 *);
    void fn_8002A784(s32, u8 *);
    u8 Status_Test(s32, s32);
    extern s32 gTargetList[];
    u32 sp10;
    u32 spC;
    u32 sp8;

    Item_GetKeyFlags((u8 *)&spC);
    *(u8 *)&sp10 = *(u8 *)&spC;
    if (Status_Test(arg0 + 0x1BC, 0x3C) != 0) {
        fn_8001EDA0((u8 *)&sp10);
    }
    *(u8 *)&sp8 = *(u8 *)&sp10;
    fn_8002A784(arg0, (u8 *)&sp8);
    if (gTargetList[0] != 0) {
        return 1;
    }
    return 0;
}

s32 fn_80105710(void *arg0) {
    u8 Id_GetKind(void *);
    s32 Item_GetByIid(void *);
    s32 off;
    s32 i;
    u8 status;

    if (*(u8 *)((u8 *)arg0 + 0x1B) == 0) {
        return 0;
    }
    i = 0;
    off = 0;
    while (i < *(u8 *)((u8 *)arg0 + 0x1B)) {
        status = Id_GetKind(*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x20) + off));
        switch (status) {
        case 3:
            return Item_GetByIid(*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x20) + (i * 4)));
        case 0:
        default:
            break;
        }
        off += 4;
        i += 1;
    }
    return 0;
}

void *fn_801057BC(void *arg0) {
    extern u8 lbl_802738A8[];
    void *Msg_Expand(u32);
    u8 *base;
    void *result;
    u32 value;

    base = lbl_802738A8 + 8;
    value = M2C_FIELD(arg0, u32 *, 0x10);
    if (value == 0) {
        return base;
    }
    result = Msg_Expand(value);
    if (result != NULL) {
        return result;
    }
    return base;
}

void *fn_80105814(void *arg0) {
    extern u8 lbl_802738A8[];
    void *Msg_Expand(u32);
    u8 *base;
    void *result;
    u32 value;

    base = lbl_802738A8 + 8;
    value = M2C_FIELD(arg0, u32 *, 0xC);
    if (value == 0) {
        return base;
    }
    result = Msg_Expand(value);
    if (result != NULL) {
        return result;
    }
    return base;
}

void *fn_8010586C(void *arg0) {
    extern u8 lbl_802738A8[];
    void *Msg_Expand(u32);
    u8 *base;
    void *result;
    u32 value;

    base = lbl_802738A8 + 0x2D;
    value = M2C_FIELD(arg0, u32 *, 8);
    if (value == 0) {
        return base;
    }
    result = Msg_Expand(value);
    if (result != NULL) {
        return result;
    }
    return base;
}

s32 Skill_UnitMeetsReqs(void *arg0, void *arg1) {
#pragma use_lmw_stmw on
u8 Unit_MatchesId(void *, void *);
u8 *skill=arg0;
s32 offset;
s32 count;
s32 i;
s32 result;
s32 j;
s32 off;
if(skill[0x19]==0) return 0;
if(skill[0x1B]==0) return 0;
count=0;
i=0;
offset=0;
while(i<skill[0x1B]) {
if(Unit_MatchesId(arg1,*(void **)((u8*)*(void **)(skill+0x20)+offset))) count++;
offset+=4; i++;
}
if(count!=skill[0x1B]) return 0;
result=0; j=0; off=0;
while(j<skill[0x1C]) {
if(Unit_MatchesId(arg1,*(void **)((u8*)*(void **)(skill+0x24)+off))) {result=1; break;}
off+=4; j++;
}
if(skill[0x1C]==0) result=1;
if(skill[0x18]==0x45) {
void *Res_GetEntry(u8);
void *entry;
s32 bit=0x44;
u32 *bits=(u32*)((u8*)arg1+0x1BC);
while(bit>=32) { bits++; bit-=32; }
if(*bits&(1<<bit)) entry=Res_GetEntry(0x44);
else entry=NULL;
if(entry==NULL) return 0;
}
return result;
}

void fn_80105A04(s32 arg0, s32 arg1) {
    M2C_UNK Stream_Read(s32, M2C_UNK, s32);
    Stream_Read(arg1, 0x10, arg0);
}

void fn_80105A30(s32 arg0, s32 arg1) {
    M2C_UNK Stream_Write(s32, M2C_UNK, s32);
    Stream_Write(arg1, 0x10, arg0);
}

/* Sum Res entry byte 0x1A for every set bit in a status/ability mask (ids 0..0x61). */
s32 Status_SumBonus(s32 *bits) {
    s32 total = 0;
    u8 i;

    for (i = 0; i < 0x62; i++) {
        if (GetUnitIfBitSet((u32 *)bits, i) != NULL) {
            total += M2C_FIELD(GetUnitIfBitSet((u32 *)bits, i), u8 *, 0x1A);
        }
    }
    return total;
}

s32 Status_Test(void *arg0, u8 arg1) {
    s32 Res_GetEntry(u8);
    u32 *p = arg0;
    s32 n = arg1;
    s32 r;

    if (n < 0) {
        r = 0;
    } else {
        while (n >= 32) {
            p++;
            n -= 32;
        }
        if (!(*p & (1 << n))) {
            r = 0;
        } else {
            r = Res_GetEntry(arg1);
        }
    }
    return r != 0;
}

s32 fn_80105C5C(s32 *arg0, u8 arg1) {
    s32 Res_GetEntry(u8);
    u32 *p = (u32 *)arg0;
    s32 n = arg1;

    if (n < 0) {
        return 0;
    }
    while (n >= 32) {
        p++;
        n -= 32;
    }
    if (*p & (1 << n)) {
        return Res_GetEntry(arg1);
    }
    return 0;
}

void Status_Set(s32 *arg0, u8 arg1) {
    u32 *p = (u32 *)arg0;
    s32 n = arg1;

    if (n < 0) {
        return;
    }
    while (n >= 32) {
        p++;
        n -= 32;
    }
    *p &= ~(1 << n);
}

void Status_Clear(s32 *arg0, u8 arg1) {
    u32 *p = (u32 *)arg0;
    s32 n = arg1;

    if (n < 0) {
        return;
    }
    while (n >= 32) {
        p++;
        n -= 32;
    }
    *p |= 1 << n;
}

/* Set the status bit whose Res entry name matches name (ids 0..0x61). */
void Status_OrByName(s32 *bits, s32 name) {
    s32 *Res_GetEntry(u8);
    s32 Str_Cmp(s32, s32);
    u8 i;
    u32 *p;
    s32 n;

    if (name != 0) {
        for (i = 0; i < 0x62; i++) {
            if (Str_Cmp(name, *Res_GetEntry(i)) == 0) {
                n = i;
                if (n >= 0) {
                    p = (u32 *)bits;
                    while (n >= 32) {
                        p++;
                        n -= 32;
                    }
                    *p |= 1 << n;
                }
                break;
            }
        }
    }
}

u8 fn_80105E88(s32 arg0, s32 arg1) {
    s32 Res_GetByName(s32);
    void *fn_80234198(void *, u8 *);
    extern u8 gDisposStrings[];
    void *temp_r3;
    if (Res_GetByName(arg0) == 0U) {
        return 0U;
    }
    temp_r3 = fn_80234198((void *)arg0, gDisposStrings + 0x26);
    if (temp_r3 == NULL) {
        return 0U;
    }
    return (u8)((s8) * (u8 *)((u8 *)temp_r3 + 5) == (arg1 + 0x30));
}

#pragma use_lmw_stmw on
/* Load a dispos file and place units / build move paths; mode selects how entries are applied. */
void Dispos_Apply(void *path, u32 defer, s32 mode) {
    void DebugPrint(const char *, ...);
    void *Process_CreateChild(void *, u32);
    u32 Res_GetByName(void *);
    void fn_80016180(void);
    void fn_800163F8(void);
    void *Unit_FindByName(void *);
    void Map_RefreshUnitMap(void *);
    void Unit_SetMapPos(void *, u8, u8);
    void fn_8004FE98(void *, s32);
    void fn_800C1BDC(void);
    void fn_800C4588(void *);
    void *fn_800C45B8(s32, void *, s32);
    void *fn_80107468(void *);
    s32 fn_80107874(void *, void *);
    void Dispos_ParseEntry(void *, u32 *, u8);
    u8 *Unit_ResolveWarpPos(void *, u8 *, u8 *, s32, s32, void *);
    void fn_80184750(void *, s32, s32, s32);
    s32 fn_801A1CC8(void);
    void strcpy(void *, void *);
    extern u8 gDisposStrings[];
    extern u8 lbl_8028F2E0[];
    extern u16 gUnits[];
    extern u8 gBattleMap[];
    extern u32 gUiInputFlags;
    u8 sp8[0x68];
    void *self;
    u32 arg1b;
    s32 mode_local;
    s32 nibble;
    void *base;
    s32 count;
    u8 *entry;
    s32 i;
    void *obj;
    void *unit;
    u8 *src;
    u8 *dst;
    u8 t;
    u8 *p;
    u8 last;
    void *tmp;

    self = path;
    arg1b = defer;
    mode_local = mode;
    DebugPrint((const char *)(gDisposStrings + 0x33), self);
    if (Res_GetByName(self) != 0) {
        nibble = fn_801A1CC8() & 0xF;
        if (gUiInputFlags & 1) {
            arg1b = 0;
        }
        if (arg1b == 0) {
            base = fn_800C45B8(-0x6A40, gDisposStrings + 0x46, 0);
            count = fn_80107874(self, base);
            if (count > 0) {
                entry = (u8 *)base;
                i = 0;
                while (i < count) {
                    if (mode_local == 2) {
                        goto case2;
                    }
                    if (mode_local >= 2) {
                        goto check4;
                    }
                    if (mode_local == 0) {
                        goto case0;
                    }
                    if (mode_local >= 0) {
                        goto case1;
                    }
                    goto after_sw;
                check4:
                    if (mode_local >= 4) {
                        goto after_sw;
                    }
                case0:
                    if ((u8)(s32)fn_80107468(entry) != 0) {
                        src = Unit_ResolveWarpPos(*(void **)(entry + 4), entry + 0xA, entry + 0xB, 1, count, base);
                        dst = entry + 0xC;
                        if (src != 0) {
                        copy0:
                            t = *src;
                            if (t == 0x10) {
                                goto copy0_done;
                            }
                            *dst = t;
                            dst += 1;
                            src += 1;
                            goto copy0;
                        copy0_done:
                            ;
                        }
                        *dst = 0x10;
                    }
                    goto after_sw;
                case1:
                    if ((u8)(s32)fn_80107468(entry) != 0) {
                        entry[0xA] = entry[0x8];
                        entry[0xB] = entry[0x9];
                        entry[0xC] = 0x10;
                    }
                    goto after_sw;
                case2:
                    obj = *(void **)entry;
                    {
                        u32 *buf = (u32 *)sp8;
                        *(s32 *)(sp8 + 0x10) = 0;
                        sp8[0x30] = 0;
                        *(s32 *)(sp8 + 0x48) = 0;
                        *(s32 *)(sp8 + 0x14) = 0;
                        sp8[0x31] = 0;
                        *(s32 *)(sp8 + 0x4C) = 0;
                        *(s32 *)(sp8 + 0x18) = 0;
                        sp8[0x32] = 0;
                        *(s32 *)(sp8 + 0x50) = 0;
                        *(s32 *)(sp8 + 0x1C) = 0;
                        sp8[0x33] = 0;
                        *(s32 *)(sp8 + 0x54) = 0;
                        *(s32 *)(sp8 + 0x20) = 0;
                        sp8[0x34] = 0;
                        *(s32 *)(sp8 + 0x58) = 0;
                        *(s32 *)(sp8 + 0x24) = 0;
                        sp8[0x35] = 0;
                        *(s32 *)(sp8 + 0x5C) = 0;
                        *(s32 *)(sp8 + 0x28) = 0;
                        sp8[0x36] = 0;
                        *(s32 *)(sp8 + 0x60) = 0;
                        *(s32 *)(sp8 + 0x2C) = 0;
                        sp8[0x37] = 0;
                        *(s32 *)(sp8 + 0x64) = 0;
                        Dispos_ParseEntry(entry, buf, entry[0x10D]);
                    }
                    unit = 0;
                    {
                        u8 id = *(u8 *)((u8 *)obj + 0x3C);
                        if (id != 0) {
                            if (id != 0) {
                                unit = (u8 *)gUnits + (id - 1) * 0x280;
                            }
                        } else if (!(entry[0x10C] & 1) && *(u32 *)sp8 != 0) {
                            unit = Unit_FindByName(*(void **)sp8);
                            if (unit != 0) {
                                *(u8 *)((u8 *)obj + 0x3C) = *(u8 *)((u8 *)unit + 0x198);
                            }
                        }
                    }
                    if (unit != 0 && (*(u32 *)((u8 *)unit + 0x1A0) & 0x9D)) {
                        unit = 0;
                    }
                    *(void **)(entry + 4) = unit;
                    if (unit != 0) {
                        src = Unit_ResolveWarpPos(*(void **)(entry + 4), entry + 0xA, entry + 0xB, 1, count, base);
                        dst = entry + 0xC;
                        if (src != 0) {
                        copy2:
                            t = *src;
                            if (t == 0x10) {
                                goto copy2_done;
                            }
                            *dst = t;
                            dst += 1;
                            src += 1;
                            goto copy2;
                        copy2_done:
                            ;
                        }
                        *dst = 0x10;
                    }
                after_sw:
                    if (*(void **)(entry + 4) != 0) {
                        Unit_SetMapPos(*(void **)(entry + 4), entry[0xA], entry[0xB]);
                    }
                    obj = *(void **)(entry + 4);
                    if (obj != 0) {
                        if (nibble != 0) {
                            fn_80184750(obj, nibble, 0, 0);
                        } else {
                            s32 ch;
                            p = entry + 0xC;
                            ch = 0x10;
                            last = 0x10;
                            goto scan_chk;
                        scan_lp:
                            ch = t;
                            last = t;
                            p += 1;
                        scan_chk:
                            t = *p;
                            if (t != 0x10) {
                                goto scan_lp;
                            }
                            fn_80184750(obj, ch, 0, 0);
                        }
                        fn_8004FE98(obj, 0);
                    }
                    i += 1;
                    entry += 0x110;
                }
            }
            fn_800C4588(base);
            Map_RefreshUnitMap(gBattleMap);
            fn_800163F8();
            fn_80016180();
            fn_800C1BDC();
        } else {
            tmp = Process_CreateChild(lbl_8028F2E0, arg1b);
            strcpy((u8 *)tmp + 0x30, self);
            *(u8 *)((u8 *)tmp + 0x60) = (u8)mode_local;
            *(u8 *)((u8 *)tmp + 0x64) = (u8)nibble;
        }
    }
}

void fn_80106290(u8 *arg0)
{
    void *fn_80107468(void *);
    void Dispos_ParseEntry(void *, u32 *, u8);
    u8 *Unit_ResolveWarpPos(void *, u8 *, u8 *, s32, s32, void *);
    void *Unit_FindByName(void *);
    void Unit_SetMapPos(void *, u8, u8);
    void fn_80184750(void *, s32, s32, s32);
    void fn_8004FE98(void *, s32);
    void Map_RefreshUnitMap(void *);
    void fn_800163F8(void);
    void fn_800C4588(void *);

    extern u16 gUnits[];
    extern u8 gBattleMap[];

    u8 sp8[0x68];
    u8 *self;
    u8 *base;
    u8 *entry;
    u8 *obj;
    u8 *unit;
    u8 *src;
    u8 *dst;
    u8 *p;
    u8 id;
    u8 t;
    s32 mode;
    s32 count;
    s32 i;
    s32 offset;
    s32 ch;

    self = arg0;

    if (self[0x61] == 0) {
        i = self[0x62];
        offset = i * 0x110;

        goto check_first;

    first_loop:
        mode = self[0x60];
        base = *(u8 **)(self + 0x68);
        entry = base + offset;

        if (mode == 2) {
            goto case2;
        }

        if (mode >= 2) {
            goto check4;
        }

        if (mode == 0) {
            goto case0;
        }

        if (mode >= 0) {
            goto case1;
        }

        goto after_switch;

    check4:
        if (mode >= 4) {
            goto after_switch;
        }

    case0:
        if ((u8)(s32)fn_80107468(entry) != 0) {
            src = Unit_ResolveWarpPos(
                *(void **)(entry + 4),
                entry + 0xA,
                entry + 0xB,
                1,
                count,
                base
            );

            dst = entry + 0xC;

            if (src != 0) {
            copy0:
                t = *src;

                if (t == 0x10) {
                    goto copy0_done;
                }

                *dst = t;
                dst++;
                src++;

                goto copy0;

            copy0_done:
                ;
            }

            *dst = 0x10;
        }

        goto after_switch;

    case1:
        if ((u8)(s32)fn_80107468(entry) != 0) {
            entry[0xA] = entry[0x8];
            entry[0xB] = entry[0x9];
            entry[0xC] = 0x10;
        }

        goto after_switch;

    case2:
        obj = *(u8 **)entry;

        *(s32 *)(sp8 + 0x10) = 0;
        sp8[0x30] = 0;
        *(s32 *)(sp8 + 0x48) = 0;

        *(s32 *)(sp8 + 0x14) = 0;
        sp8[0x31] = 0;
        *(s32 *)(sp8 + 0x4C) = 0;

        *(s32 *)(sp8 + 0x18) = 0;
        sp8[0x32] = 0;
        *(s32 *)(sp8 + 0x50) = 0;

        *(s32 *)(sp8 + 0x1C) = 0;
        sp8[0x33] = 0;
        *(s32 *)(sp8 + 0x54) = 0;

        *(s32 *)(sp8 + 0x20) = 0;
        sp8[0x34] = 0;
        *(s32 *)(sp8 + 0x58) = 0;

        *(s32 *)(sp8 + 0x24) = 0;
        sp8[0x35] = 0;
        *(s32 *)(sp8 + 0x5C) = 0;

        *(s32 *)(sp8 + 0x28) = 0;
        sp8[0x36] = 0;
        *(s32 *)(sp8 + 0x60) = 0;

        *(s32 *)(sp8 + 0x2C) = 0;
        sp8[0x37] = 0;
        *(s32 *)(sp8 + 0x64) = 0;

        Dispos_ParseEntry(
            entry,
            (u32 *)sp8,
            entry[0x10D]
        );

        unit = 0;
        id = obj[0x3C];

        if (id != 0) {
            if (id != 0) {
                unit = (u8 *)gUnits +
                       (id - 1) * 0x280;
            }
        } else if (!(entry[0x10C] & 1) &&
                   *(u32 *)sp8 != 0) {
            unit = Unit_FindByName(
                *(void **)sp8
            );

            if (unit != 0) {
                obj[0x3C] = unit[0x198];
            }
        }

        if (unit != 0) {
            if (*(u32 *)(unit + 0x1A0) & 0x9D) {
                unit = 0;
            }
        }

        *(u8 **)(entry + 4) = unit;

        if (unit != 0) {
            src = Unit_ResolveWarpPos(
                *(void **)(entry + 4),
                entry + 0xA,
                entry + 0xB,
                1,
                count,
                base
            );

            dst = entry + 0xC;

            if (src != 0) {
            copy2:
                t = *src;

                if (t == 0x10) {
                    goto copy2_done;
                }

                *dst = t;
                dst++;
                src++;

                goto copy2;

            copy2_done:
                ;
            }

            *dst = 0x10;
        }

    after_switch:
        if (*(void **)(entry + 4) != 0) {
            Unit_SetMapPos(
                *(void **)(entry + 4),
                entry[0xA],
                entry[0xB]
            );
        }

        offset += 0x110;
        i++;

    check_first:
        count = self[0x63];

        if (i < count) {
            goto first_loop;
        }
    }

    i = 0;
    offset = 0;

    goto check_second;

second_loop:
    base = *(u8 **)(self + 0x68);
    entry = base + offset;
    unit = *(u8 **)(entry + 4);

    if (unit != 0) {
        ch = self[0x64];

        if (ch != 0) {
            fn_80184750(unit, ch, 0, 0);
        } else {
            p = entry + 0xC;
            ch = 0x10;

            goto scan_check;

        scan_loop:
            ch = t;
            p++;

        scan_check:
            t = *p;

            if (t != 0x10) {
                goto scan_loop;
            }

            fn_80184750(unit, ch, 0, 0);
        }

        fn_8004FE98(unit, 0);
    }

    offset += 0x110;
    i++;

check_second:
    if (i < self[0x63]) {
        goto second_loop;
    }

    Map_RefreshUnitMap(gBattleMap);
    fn_800163F8();

    fn_800C4588(*(void **)(self + 0x68));

    *(void **)(self + 0x68) = 0;
}

#pragma use_lmw_stmw reset

extern void Map_RefreshUnitMap(void* arg0);
extern s32 MuEvent_Create(s32 arg0, s8 arg1, s8 arg2, void* arg3);
extern s32 MoveAnim_BindPath(void* arg0, u16 arg1, void* arg2);
/* Bind move or warp anims for each dispos entry, then refresh the unit map. */
void Dispos_StartMoveAnims(void *proc) {
    void MuEvent_Create(void *, s32, s32, s32, void *);
    void MoveAnim_BindPath(void *, void *, u16, void *);
    void Map_RefreshUnitMap(void *);
    extern u8 gBattleMap[];
    u16 flags;
    void *entry;
    s32 count;
    void *self;
    s32 mode;
    void *unit;
    u32 flagByte;

    self = proc;
    mode = *(u8 *)((u8 *)proc + 0x60);
    flagByte = *(u8 *)((u8 *)proc + 0x64);
    entry = *(void **)((u8 *)self + 0x68);
    flags = flagByte | 0x80;

    switch (mode) {
    case 0:
    case 1:
        flags |= 0x10;
        break;
    }

    count = 0;
    while (count < *(u8 *)((u8 *)self + 0x63)) {
        unit = *(void **)((u8 *)entry + 4);
        if (unit != NULL) {
            if (*(u8 *)((u8 *)self + 0x60) == 3) {
                MuEvent_Create(unit, 1, *(s8 *)((u8 *)entry + 0xA), *(s8 *)((u8 *)entry + 0xB), self);
            } else {
                MoveAnim_BindPath(unit, (u8 *)entry + 0xC, flags, self);
            }
        }
        count++;
        entry = (u8 *)entry + 0x110;
    }

    Map_RefreshUnitMap(gBattleMap);
    *(u8 *)((u8 *)self + 0x61) = 1;
}

void fn_80106690(void *arg0) {
    s32 Unit_IsDisplayReady(void *);
    void Process_ClearFunc(void *);
    void *entry;
    s32 count;
    s32 value;
    void *p;

    value = *(u8 *)((u8 *)arg0 + 0x65);
    *(u8 *)((u8 *)arg0 + 0x65) = (u8)(value + 1);

    if (value <= 0x2A30) {
        entry = *(void **)((u8 *)arg0 + 0x68);
        count = 0;
        while (count < *(u8 *)((u8 *)arg0 + 0x63)) {
            p = *(void **)((u8 *)entry + 4);
            if (p != NULL) {
                if ((u8)Unit_IsDisplayReady(p) == 0) {
                    return;
                }
            }
            count++;
            entry = (u8 *)entry + 0x110;
        }
    }
    Process_ClearFunc(arg0);
}

void fn_8010671C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x65) = 0;
}

#pragma use_lmw_stmw on
void fn_80106728(u8 *arg0) {
    void Process_ClearFunc(void *);
    void *Unit_FindByName(void *);
    void Unit_SetMapPos(void *, u8, u8);
    void fn_8004F5EC(void *, s32);
    void *fn_80107468(void *);
    void Dispos_ParseEntry(void *, u32 *, u8);
    u8 *Unit_ResolveWarpPos(void *, u8 *, u8 *, s32, s32, void *);
    extern u16 gUnits[];
    u8 sp8[0x68];
    u8 idx;
    void *base;
    u8 count;
    u8 *entry;
    s32 kind;
    void *obj;
    void *unit;
    u8 *src;
    u8 *dst;
    u8 t;
    int i;

    idx = arg0[0x62];
    count = arg0[0x63];
    if (idx >= count) {
        Process_ClearFunc(arg0);
        return;
    }
    kind = arg0[0x60];
    base = *(void **)(arg0 + 0x68);
    entry = (u8 *)base + idx * 0x110;
    switch (kind) {
    case 0:
    case 3:
        goto case0;
    case 1:
        goto case1;
    case 2:
        goto case2;
    default:
        goto after_sw;
    }
case0:
    if ((u8)(s32)fn_80107468(entry) != 0) {
        src = Unit_ResolveWarpPos(*(void **)(entry + 4), entry + 0xA, entry + 0xB, 1, count, base);
        dst = entry + 0xC;
        if (src != 0) {
        copy0:
            t = *src;
            if (t == 0x10) {
                goto copy0_done;
            }
            *dst = t;
            dst += 1;
            src += 1;
            goto copy0;
        copy0_done:
            ;
        }
        *dst = 0x10;
    }
    goto after_sw;
case1:
    if ((u8)(s32)fn_80107468(entry) != 0) {
        entry[0xA] = entry[0x8];
        entry[0xB] = entry[0x9];
        entry[0xC] = 0x10;
    }
    goto after_sw;
case2:
    obj = *(void **)entry;
    for (i = 0; i < 8; i++) {
        *(s32 *)(sp8 + 0x10 + i * 4) = 0;
        sp8[0x30 + i] = 0;
        *(s32 *)(sp8 + 0x48 + i * 4) = 0;
    }
    Dispos_ParseEntry(entry, (u32 *)sp8, entry[0x10D]);
    unit = 0;
    {
        u8 id = *(u8 *)((u8 *)obj + 0x3C);
        if (id != 0) {
            if (id != 0) {
                unit = (u8 *)gUnits + (id - 1) * 0x280;
            }
        } else if (!(entry[0x10C] & 1) && *(u32 *)sp8 != 0) {
            unit = Unit_FindByName(*(void **)sp8);
            if (unit != 0) {
                *(u8 *)((u8 *)obj + 0x3C) = *(u8 *)((u8 *)unit + 0x198);
            }
        }
    }
    if (unit != 0 && (*(u32 *)((u8 *)unit + 0x1A0) & 0x9D)) {
        unit = 0;
    }
    *(void **)(entry + 4) = unit;
    if (unit != 0) {
        src = Unit_ResolveWarpPos(*(void **)(entry + 4), entry + 0xA, entry + 0xB, 1, count, base);
        dst = entry + 0xC;
        if (src != 0) {
        copy2:
            t = *src;
            if (t == 0x10) {
                goto copy2_done;
            }
            *dst = t;
            dst += 1;
            src += 1;
            goto copy2;
        copy2_done:
            ;
        }
        *dst = 0x10;
    }
after_sw:
    if (*(void **)(entry + 4) != 0) {
        Unit_SetMapPos(*(void **)(entry + 4), entry[0xA], entry[0xB]);
    }
    if (*(void **)(entry + 4) != 0) {
        fn_8004F5EC(*(void **)(entry + 4), 0);
    }
    arg0[0x62] = (u8)(arg0[0x62] + 1);
}
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on
void fn_801069A0(u8 *arg0) {
    void *fn_800C45B8(s32, void *, s32);
    u8 fn_80107874(void *, void *);
    void Process_Goto(void *, s32);
    u8 fn_801A2300(void);
    u32 Hash_Lookup(void *);
    u8 Bin_ReadU8(u32 *);
    u32 Bin_ReadU32(u32 *);
    void Dispos_ParseEntry(u32 *, void *, s32);
    void BattleState_SetCamPos(void *, f32, f32);
    extern u8 gDisposStrings[];
    extern u8 gBattleState[];
    u8 *self;
    u32 spC;
    u32 sp8;
    u8 sp10[0x68];
    s32 var_r26;
    s32 var_r27;
    s32 var_r28;
    s32 var_r29;
    s32 var_r30;
    s32 var_r31;
    u32 var_r0;

    self = arg0;
    *(void **)(self + 0x68) = fn_800C45B8(-0x6A40, gDisposStrings + 0x46, 0);
    self[0x63] = fn_80107874(self + 0x30, *(void **)(self + 0x68));
    self[0x62] = 0;
    self[0x61] = 0;
    if (self[0x63] == 0) {
        Process_Goto(self, 0x63);
        return;
    }
    if (fn_801A2300() == 0) {
        return;
    }
    var_r31 = 0;
    var_r30 = var_r31;
    sp8 = Hash_Lookup((void *)(self + 0x30));
    if (sp8 == 0) {
        var_r0 = 0;
    } else {
        var_r29 = Bin_ReadU8(&sp8);
        switch ((u8)Bin_ReadU8(&sp8)) {
        case 2:
            var_r28 = 0;
            break;
        case 3:
            Bin_ReadU8(&sp8);
            var_r28 = Bin_ReadU8(&sp8);
            Bin_ReadU32(&sp8);
            break;
        case 4:
            Bin_ReadU8(&sp8);
            var_r28 = Bin_ReadU8(&sp8);
            break;
        }
        var_r0 = (sp8 + 3) & ~3;
        sp8 = var_r0;
    }
    spC = var_r0;
    if (var_r0 != 0) {
        var_r26 = 0;
        var_r27 = (u8)var_r29;
        *(s32 *)(sp10 + 0x10) = var_r26;
        sp10[0x30] = var_r26;
        *(s32 *)(sp10 + 0x48) = var_r26;
        *(s32 *)(sp10 + 0x14) = var_r26;
        sp10[0x31] = var_r26;
        *(s32 *)(sp10 + 0x4C) = var_r26;
        *(s32 *)(sp10 + 0x18) = var_r26;
        sp10[0x32] = var_r26;
        *(s32 *)(sp10 + 0x50) = var_r26;
        *(s32 *)(sp10 + 0x1C) = var_r26;
        sp10[0x33] = var_r26;
        *(s32 *)(sp10 + 0x54) = var_r26;
        *(s32 *)(sp10 + 0x20) = var_r26;
        sp10[0x34] = var_r26;
        *(s32 *)(sp10 + 0x58) = var_r26;
        *(s32 *)(sp10 + 0x24) = var_r26;
        sp10[0x35] = var_r26;
        *(s32 *)(sp10 + 0x5C) = var_r26;
        *(s32 *)(sp10 + 0x28) = var_r26;
        sp10[0x36] = var_r26;
        *(s32 *)(sp10 + 0x60) = var_r26;
        *(s32 *)(sp10 + 0x2C) = var_r26;
        sp10[0x37] = var_r26;
        *(s32 *)(sp10 + 0x64) = var_r26;
        goto loop_cmp;
    loop_body:
        Dispos_ParseEntry(&spC, sp10, var_r28);
        var_r26 += 1;
        var_r30 += (s8)sp10[0xD];
        var_r31 += (s8)sp10[0xE];
    loop_cmp:
        if (var_r26 < var_r27) {
            goto loop_body;
        }
        var_r27 = (s8)(var_r30 / var_r27);
        var_r26 = (s8)(var_r31 / (s32)(u8)var_r29);
    }
    BattleState_SetCamPos(gBattleState, (f32)(s8)var_r27, (f32)(s8)var_r26);
}

#pragma optimization_level 3
u8 fn_80106BCC(void *name) {
    void *Hash_Lookup(void *);
    u8 Bin_ReadU8(u32 *);
    u32 Bin_ReadU32(u32 *);
    void Dispos_ParseEntry(u32 *, u32 *, u8);
    void Unit_SetMapPos(void *, u8, u8);
    void Unit_SetModelAlpha(void *, s32);
    void fn_80050C90(void *);
    extern struct { u8 pad[0x3C]; void *unk3C; } gUnitLists;
    struct Ret { u8 v; };
    u8 parsed[0x68];
    u32 cursor;
    u32 header;
    u32 data;
    u8 applied;
    void *next;
    void *unit;
    u8 *entry;
    s32 i;
    struct Ret c;
    struct Ret d;

    applied = 0;
    for (i = 0; i < 8; i++) {
        *(s32 *)((unsigned)parsed + 0x10 + i * 4) = 0;
        parsed[0x30 + i] = 0;
        *(s32 *)(parsed + 0x48 + i * 4) = 0;
    }

    header = (u32)Hash_Lookup(name);
    if (!header) {
        data = 0;
    } else {
        c.v = Bin_ReadU8(&header);
        switch (Bin_ReadU8(&header)) {
        case 2:
            d.v = 0;
            break;
        case 3:
            Bin_ReadU8(&header);
            d.v = Bin_ReadU8(&header);
            Bin_ReadU32(&header);
            break;
        case 4:
            Bin_ReadU8(&header);
            d.v = Bin_ReadU8(&header);
            break;
        }
        header = (header + 3) & ~3;
        data = header;
    }
    cursor = data;
    if (data == 0) {
        return 0;
    }

    unit = gUnitLists.unk3C;
    while (unit != NULL) {
        next = *(void **)((u8 *)unit + 0x184);
        if (*(u32 *)((u8 *)unit + 0x1A0) & 0x400000) {
            entry = (u8 *)cursor;
            Dispos_ParseEntry(&cursor, (u32 *)parsed, d.v);
            Unit_SetMapPos(unit, parsed[0xB], parsed[0xC]);
            fn_80050C90(unit);
            Unit_SetModelAlpha(unit, 0);
            applied += 1;
            entry[0x3C] = *(u8 *)((u8 *)unit + 0x198);
            if (applied == c.v) {
                break;
            }
        }
        unit = next;
    }

    {
        u8 j = applied;
        u8 lim = c.v;
        register u8 zero = 0;
        while (j < lim) {
            entry = (u8 *)cursor;
            entry[0x3C] = zero;
            Dispos_ParseEntry(&cursor, (u32 *)parsed, d.v);
            j += 1;
        }
    }
    return (u8)applied;
}
#pragma optimization_level reset
u8 fn_80106DC8(void *name, u8 *out)
{
    u32 Hash_Lookup(void *);
    s32 Bin_ReadU8(u32 *);
    u32 Bin_ReadU32(u32 *);
    void Dispos_ParseEntry(u32 *, void *, s32);
    struct Ret { s32 v; };
    struct Ret c;
    struct Ret d;
    u8 parsed[0x68];
    u32 cursor;
    u32 header;
    u32 data;
    s32 count;
    s32 i;

    header = Hash_Lookup(name);
    if (!header) {
        data = 0;
    } else {
        c.v = Bin_ReadU8(&header);
        switch ((u8)Bin_ReadU8(&header)) {
        case 2:
            d.v = 0;
            break;
        case 3:
            Bin_ReadU8(&header);
            d.v = Bin_ReadU8(&header);
            Bin_ReadU32(&header);
            break;
        case 4:
            Bin_ReadU8(&header);
            d.v = Bin_ReadU8(&header);
            break;
        }
        header = (header + 3) & ~3;
        data = header;
    }
    cursor = data;
    if (data == 0) {
        return 0;
    }
    count = c.v;
    for (i = 0; i < 8; i++) {
        *((u32 *)((parsed + 0x10) + (i * 4))) = 0;
        parsed[0x30 + i] = 0;
        *((u32 *)((parsed + 0x48) + ((unsigned)i * 4))) = 0;
    }
    count = (u8)count;
    for (i = 0; i < count; i++) {
        Dispos_ParseEntry(&cursor, parsed, d.v);
        out[0] = parsed[0xd];
        out[1] = parsed[0xe];
        out += 2;
    }
    *(s8 *)out = -1;
    return (u8)count;
}
#pragma optimization_level reset
#pragma use_lmw_stmw reset

u32 Hash_Lookup();                                  /* extern */
u8 Bin_ReadU8(u32 *);                              /* extern */
u8 Bin_ReadU32(u32 *);                              /* extern */
void Dispos_ParseEntry(u32 *, u32 *, u8);                 /* extern */
void fn_80106F68(void *name, s8 *outX, s8 *outY)
{
  u8 parsed[0x68];
  u8 new_var2;
  u32 cursor;
  u32 header;
  u8 new_var;
  u32 data;
  s32 sumX = 0;
  s32 sumY = 0;
  u8 new_var3[2];
  s32 i;
  header = Hash_Lookup(name);
  if (!header)
  {
    data = 0;
  }
  else
  {
    new_var3[0] = Bin_ReadU8(&header);
    switch (Bin_ReadU8(&header))
    {
      case 2:
        new_var3[1] = 0;
        break;

      case 3:
        Bin_ReadU8(&header);
        new_var3[1] = Bin_ReadU8(&header);
        Bin_ReadU32(&header);
        break;

      case 4:
        Bin_ReadU8(&header);
        new_var3[1] = Bin_ReadU8(&header);
        break;

    }

    header = (header + 3) & (~3);
    data = header;
  }
  cursor = data;
  if (data)
  {
    for (i = 0; i < 8; i++)
    {
      *((u32 *) ((parsed + 0x10) + (i * 4))) = 0;
      parsed[0x30 + i] = 0;
      *((u32 *) ((parsed + 0x48) + (i * 4))) = 0;
    }

    for (i = 0; i < ((u8) new_var3[0]); i++)
    {
      Dispos_ParseEntry(&cursor, (u32 *) parsed, new_var3[1]);
      sumX += (s8) parsed[0xd];
      new_var2 = parsed[0xe];
      sumY += (s8) new_var2;
    }

    new_var = (u8) new_var3[0];
    *outX = sumX / new_var;
    *outY = sumY / ((u8) new_var3[0]);
  }
}

extern u16 gUnits[];
void fn_801070FC(void *name) {
#pragma global_optimizer off
    extern u16 gUnits[];
    void fn_8004EB14(void *,s32);
    u8 parsed[0x68];
    u32 cursor;
    u32 header;
    u32 data;
    u8 new_var3[2];
    s32 i;
    for(i=0;i<8;i++) {
        *(u32 *)(parsed+0x10+i*4)=0;
        parsed[0x30+i]=0;
        *(u32 *)(parsed+0x48+i*4)=0;
    }
    header = Hash_Lookup(name);
    if (!header) data = 0;
    else {
        new_var3[0] = Bin_ReadU8(&header);
        switch (Bin_ReadU8(&header)) {
        case 2: new_var3[1] = 0; break;
        case 3:
            Bin_ReadU8(&header);
            new_var3[1] = Bin_ReadU8(&header);
            Bin_ReadU32(&header);
            break;
        case 4:
            Bin_ReadU8(&header);
            new_var3[1] = Bin_ReadU8(&header);
            break;
        }
        header = (header + 3) & ~3;
        data = header;
    }
    cursor = data;
    if (data) {
        for (i=0;i<new_var3[0];i++) {
            u8 *entry = (u8 *)cursor;
            void *unit;
            Dispos_ParseEntry(&cursor,(u32 *)parsed,new_var3[1]);
            if (entry[0x3c]) unit = (u8 *)gUnits+(entry[0x3c]-1)*0x280;
            else unit = 0;
            if (unit) fn_8004EB14(unit,0);
        }
    }
#pragma global_optimizer reset
}

#pragma use_lmw_stmw on
#pragma optimization_level 3
void fn_80107294(void *name, s32 arg1) {
    u32 Hash_Lookup(void *);
    s32 Bin_ReadU8(u32 *);
    void Bin_ReadU32(u32 *);
    void Dispos_ParseEntry(u32 *, void *, s32);
    void *Unit_FindByName(void *);
    void Unit_MoveToList(void *, s32);
    void Unit_InitFromDispos(void *, void *);
    extern struct { u8 pad[0x30]; void *unk30; } gUnitLists;
    struct Ret { s32 v; };
    struct Ret d;
    u32 spC;
    u32 sp8;
    u8 sp10[0x68];
    s32 faction;
    s32 lists;
    struct Ret c;
    s32 faction_u8;
    s32 count;
    s32 count_u8;
    s32 idx;
    s32 var_r0;
    u8 *entry;
    void *unit;

    faction = arg1;
    *(s32 *)(sp10 + 0x10) = 0;
    sp10[0x30] = 0;
    *(s32 *)(sp10 + 0x48) = 0;
    *(s32 *)(sp10 + 0x14) = 0;
    sp10[0x31] = 0;
    *(s32 *)(sp10 + 0x4C) = 0;
    *(s32 *)(sp10 + 0x18) = 0;
    sp10[0x32] = 0;
    *(s32 *)(sp10 + 0x50) = 0;
    *(s32 *)(sp10 + 0x1C) = 0;
    sp10[0x33] = 0;
    *(s32 *)(sp10 + 0x54) = 0;
    *(s32 *)(sp10 + 0x20) = 0;
    sp10[0x34] = 0;
    *(s32 *)(sp10 + 0x58) = 0;
    *(s32 *)(sp10 + 0x24) = 0;
    sp10[0x35] = 0;
    *(s32 *)(sp10 + 0x5C) = 0;
    *(s32 *)(sp10 + 0x28) = 0;
    sp10[0x36] = 0;
    *(s32 *)(sp10 + 0x60) = 0;
    *(s32 *)(sp10 + 0x2C) = 0;
    sp10[0x37] = 0;
    *(s32 *)(sp10 + 0x64) = 0;
    sp8 = Hash_Lookup(name);
    if (sp8 == 0) {
        var_r0 = 0;
    } else {
        c.v = Bin_ReadU8(&sp8);
        switch ((u8)Bin_ReadU8(&sp8)) {
        case 2: d.v = 0; break;
        case 3:
            Bin_ReadU8(&sp8);
            d.v = Bin_ReadU8(&sp8);
            Bin_ReadU32(&sp8);
            break;
        case 4:
            Bin_ReadU8(&sp8);
            d.v = Bin_ReadU8(&sp8);
            break;
        }
        sp8 = (sp8 + 3) & ~3;
        var_r0 = sp8;
    }
    spC = var_r0;
    if ((u32)var_r0 != 0) {
        lists = (s32)&gUnitLists;
        faction_u8 = (u8)faction;
        count = c.v;
        count_u8 = (u8)count;
        idx = 0;
        goto loop_cmp;
    loop_body:
        entry = (u8 *)spC;
        Dispos_ParseEntry(&spC, sp10, d.v);
        if ((s8)faction >= 0) {
            sp10[9] = (u8)faction_u8;
        }
        unit = Unit_FindByName(*(void **)sp10);
        if (unit == NULL) {
            count = *(s32 *)(lists + 0x30);
            var_r0 = sp10[9];
            if (var_r0 == 4) {
                goto after_sw;
            } else if (var_r0 >= 4) {
                goto check6;
            }
            if (var_r0 >= 0) {
                goto do_move;
            }
            goto after_sw;
        check6:
            if (var_r0 >= 6) {
                goto after_sw;
            }
        do_move:
            Unit_MoveToList((void*)count, var_r0);
        after_sw:
            Unit_InitFromDispos((void*)count, sp10);
            unit = (void*)count;
        }
        idx += 1;
        entry[0x3C] = *(u8 *)((u8 *)unit + 0x198);
    loop_cmp:
        if (idx < count_u8) {
            goto loop_body;
        }
    }
}
#pragma optimization_level reset
#pragma use_lmw_stmw reset

extern void *Unit_FindByName(char *);
#pragma optimization_level 3
s32 fn_80107468(u8 *entry) {
    void Dispos_ParseEntry(u32 *, u32 *, u8);
    s32 Dispos_ResolveUnit(u8 *);
    void *Unit_FindByName(void *);
    void Unit_SetMapPos(void *, u8, u8);
    void Unit_SetDisposId(void *, u8);
    void Unit_MoveToList(void *, s32);
    void Unit_InitFromDispos(void *, void *);
    void Unit_SetModelAlpha(void *, s32);
    void fn_80050C90(void *);
    void fn_800056A0(s32);
    extern struct { u8 pad[0x30]; void *unk30; } gUnitLists;
    u8 parsed[0x68];
    void *unit;
    void *obj;
    s32 kind;
    s32 i;

    if (entry[0x10C] & 1) {
        return Dispos_ResolveUnit(entry);
    }

    for (i = 0; i < 8; i++) {
        *(s32 *)(parsed + 0x10 + i * 4) = 0;
        parsed[0x30 + i] = 0;
        *(s32 *)(parsed + 0x48 + i * 4) = 0;
    }
    obj = *(void **)entry;
    *((u8 *)obj + 0x3C) = 0;
    Dispos_ParseEntry((u32 *)entry, (u32 *)parsed, entry[0x10D]);
    unit = Unit_FindByName(*(void **)parsed);
    if (unit != NULL) {
        u8 type = *(u8 *)(*(s32 *)((u8 *)unit + 0x190) + 8);
        if (type == 6) {
            return 0;
        }
        if (type == 7) {
            Unit_MoveToList(unit, parsed[9]);
            Unit_SetDisposId(unit, parsed[0x67]);
            Unit_SetMapPos(unit, parsed[0xB], parsed[0xC]);
            goto finish;
        }
        if (parsed[9] != 0) {
            goto create;
        }
        if (type != 5) {
            fn_800056A0(0);
        }
        Unit_MoveToList(unit, parsed[9]);
        Unit_SetMapPos(unit, parsed[0xB], parsed[0xC]);
    finish:
        fn_80050C90(unit);
        Unit_SetModelAlpha(unit, 0);
        *(void **)(entry + 4) = unit;
        *((u8 *)obj + 0x3C) = *((u8 *)unit + 0x198);
        return 1;
    }
create:
    kind = parsed[9];
    unit = gUnitLists.unk30;
    if (kind == 4) {
        goto after_sw;
    } else if (kind >= 4) {
        goto check6;
    }
    if (kind >= 0) {
        goto do_call;
    }
    goto after_sw;
check6:
    if (kind >= 6) {
        goto after_sw;
    }
do_call:
    Unit_MoveToList(unit, kind);
after_sw:
    Unit_InitFromDispos(unit, parsed);
    fn_80050C90(unit);
    Unit_SetModelAlpha(unit, 0);
    *(void **)(entry + 4) = unit;
    *((u8 *)obj + 0x3C) = *((u8 *)unit + 0x198);
    return 1;
}
#pragma optimization_level reset
/* Parse a dispos entry and bind it to a map unit (create or pick from list 5). */
s32 Dispos_ResolveUnit(u8 *entry) {
    void Dispos_ParseEntry(u32 *, u32 *, u8);
    void *Unit_FindByName(void *);
    void Unit_SetMapPos(void *, u8, u8);
    void Unit_SetDisposId(void *, u8);
    void Unit_MoveToList(void *, s32);
    void Unit_MoveToListHead(void *, s32);
    void Unit_InitFromDispos(void *, void *);
    void Unit_SetModelAlpha(void *, s32);
    void fn_80050C90(void *);
    extern u8 gDisposStrings[];
    extern struct { u8 pad[0x30]; void *unk30; u8 pad34[8]; void *unk3C; } gUnitLists;
    u8 parsed[0x68];
    void *unit;
    void *obj;
    void *named;
    s32 kind;
    s32 i;

    for (i = 0; i < 8; i++) {
        *(s32 *)(parsed + 0x10 + i * 4) = 0;
        parsed[0x30 + i] = 0;
        *(s32 *)(parsed + 0x48 + i * 4) = 0;
    }
    obj = *(void **)entry;
    Dispos_ParseEntry((u32 *)entry, (u32 *)parsed, entry[0x10D]);
    unit = Unit_FindByName(*(void **)parsed);
    if (unit == NULL) {
        if ((entry[0x10C] & 2) || (parsed[8] & 8)) {
            kind = parsed[9];
            unit = gUnitLists.unk30;
            if (kind == 4) {
                goto after_sw;
            } else if (kind >= 4) {
                goto check6;
            }
            if (kind >= 0) {
                goto do_call;
            }
            goto after_sw;
        check6:
            if (kind >= 6) {
                goto after_sw;
            }
        do_call:
            Unit_MoveToList(unit, kind);
        after_sw:
            Unit_InitFromDispos(unit, parsed);
            Unit_MoveToList(unit, 5);
        } else {
            unit = NULL;
            goto skip_type;
        }
    }
    {
        u8 t = *(u8 *)(*(s32 *)((u8 *)unit + 0x190) + 8);
        if (t == 6) {
            unit = NULL;
        } else if (t == 7) {
            Unit_MoveToList(unit, 5);
            Unit_SetDisposId(unit, parsed[0x67]);
        }
    }
skip_type:
    named = Unit_FindByName(gDisposStrings + 0x50);
    if (named != NULL && unit == named) {
        Unit_MoveToListHead(unit, 0);
        goto ok;
    }
    {
        void *var_r4;
        void *var_r5;

        var_r4 = &gUnitLists;
        var_r5 = *(void **)((u8 *)var_r4 + 0x3C);
        goto loop_cmp;
    loop_body:
        var_r4 = *(void **)((u8 *)var_r5 + 0x184);
        if ((named != var_r5) && !(*(s32 *)((u8 *)var_r5 + 0x1A0) & 0x200000)) {
            unit = var_r5;
            Unit_MoveToList(var_r5, 0);
            goto ok;
        }
        var_r5 = var_r4;
    loop_cmp:
        if (var_r5 != NULL) {
            goto loop_body;
        }
    }
    *(void **)(entry + 4) = NULL;
    *((u8 *)obj + 0x3C) = 0;
    return 0;
ok:
    Unit_SetMapPos(unit, parsed[0xB], parsed[0xC]);
    fn_80050C90(unit);
    Unit_SetModelAlpha(unit, 0);
    *(void **)(entry + 4) = unit;
    *((u8 *)obj + 0x3C) = *((u8 *)unit + 0x198);
    return 1;
}

#pragma use_lmw_stmw on
s32 fn_80107874(void *arg0, void *arg1) {
    void DebugPrint(const char *, ...);
    void *Hash_Lookup(void *);
    s32 fn_80015680(void *);
    void Bin_ReadU32(u32 *);
    s32 Bin_ReadU8(u32 *);
    void Dispos_ParseEntry(u32 *, void *, u8);
    void *fn_80234198(void *, void *);
    extern u8 gDisposStrings[];
    extern u8 gUnitLists[];
    extern s32 gBattleMap[];
    u32 spC;
    u32 sp8;
    u8 sp10[0x68];
    s32 a;
    s32 r30v;
    s32 b;
    s32 n;
    s32 count;
    u8 flags;
    void *self;
    void *out;
    s32 i;

    self = arg0;
    out = arg1;
    count = 0;
    flags = 0;
    *(s32 *)(sp10 + 0x10) = 0; sp10[0x30] = 0; *(s32 *)(sp10 + 0x48) = 0;
    *(s32 *)(sp10 + 0x14) = 0; sp10[0x31] = 0; *(s32 *)(sp10 + 0x4C) = 0;
    *(s32 *)(sp10 + 0x18) = 0; sp10[0x32] = 0; *(s32 *)(sp10 + 0x50) = 0;
    *(s32 *)(sp10 + 0x1C) = 0; sp10[0x33] = 0; *(s32 *)(sp10 + 0x54) = 0;
    *(s32 *)(sp10 + 0x20) = 0; sp10[0x34] = 0; *(s32 *)(sp10 + 0x58) = 0;
    *(s32 *)(sp10 + 0x24) = 0; sp10[0x35] = 0; *(s32 *)(sp10 + 0x5C) = 0;
    *(s32 *)(sp10 + 0x28) = 0; sp10[0x36] = 0; *(s32 *)(sp10 + 0x60) = 0;
    *(s32 *)(sp10 + 0x2C) = 0; sp10[0x37] = 0; *(s32 *)(sp10 + 0x64) = 0;
    if (fn_80234198(self, gDisposStrings + 0x58) != 0) {
        flags |= 1;
    }
    if (fn_80015680(gUnitLists) == 0 && fn_80015680(gUnitLists + 0x3C) == 0) {
        flags |= 2;
    }
    sp8 = (u32)Hash_Lookup(self);
    if (sp8 == 0) {
        spC = 0;
    } else {
        r30v = Bin_ReadU8(&sp8);
        switch ((u8)Bin_ReadU8(&sp8)) {
        case 2:
            a = 1;
            b = 0;
            break;
        case 3:
            a = Bin_ReadU8(&sp8);
            b = Bin_ReadU8(&sp8);
            Bin_ReadU32(&sp8);
            break;
        case 4:
            a = Bin_ReadU8(&sp8);
            b = Bin_ReadU8(&sp8);
            break;
        }
        sp8 = (sp8 + 3) & ~3;
        spC = sp8;
    }
    n = (u8)r30v;
    r30v = (s32)gBattleMap;
    a = (u8)a;
    for (i = 0; i < n; i++) {
        *(s32 *)((u8 *)out + 4) = 0;
        ((u8 *)out)[0xC] = 0x10;
        ((u8 *)out)[0x10D] = 0;
        *(u32 *)out = spC;
        ((u8 *)out)[0x10C] = flags;
        ((u8 *)out)[0x10D] = (u8)b;
        Dispos_ParseEntry(&spC, sp10, ((u8 *)out)[0x10D]);
        if (a == 0) {
            s8 x = sp10[0xB];
            s8 y = sp10[0xC];
            u8 *map = (u8 *)gBattleMap + x + (y << 6);
            if (map[0xD] != 0 || map[0x300D] != 0) {
                DebugPrint((const char *)(gDisposStrings + 0x61), x, y, *(void **)sp10);
                continue;
            }
        }
        if ((s8)sp10[0xB] < gBattleMap[0] && (s8)sp10[0xC] < ((s32 *)r30v)[1]
            && (s8)sp10[0xD] < gBattleMap[0] && (s8)sp10[0xE] < ((s32 *)r30v)[1]) {
            count += 1;
            *(s32 *)((u8 *)out + 4) = 0;
            ((u8 *)out)[8] = sp10[0xB];
            ((u8 *)out)[9] = sp10[0xC];
            ((u8 *)out)[0xA] = sp10[0xD];
            ((u8 *)out)[0xB] = sp10[0xE];
            out = (u8 *)out + 0x110;
        }
    }
    return count;
}
#pragma use_lmw_stmw on
/* Parse one dispos unit record from a BE binary cursor into a 0x68-byte buffer. */
void Dispos_ParseEntry(u32 *cursor, u32 *out, u8 dispos_id) {
    s32 Bin_ReadU32(u32 *);
    u8 Bin_ReadU8(u32 *);
    void DebugPrint(const char *, ...);
    extern u8 gDisposStrings[];
    u32 *p_cursor;
    u32 *parsed;
    u8 id;
    s32 j;
    u32 *q;
    s32 i;
    s32 temp;
    s32 off;

    p_cursor = cursor;
    parsed = out;
    id = dispos_id;
    parsed[0] = Bin_ReadU32(p_cursor);
    parsed[1] = Bin_ReadU32(p_cursor);
    Bin_ReadU32(p_cursor);
    j = 0;
    q = parsed;
    do {
        temp = Bin_ReadU32(p_cursor);
        j += 1;
        *(u32 *)((u8 *)q + 0x10) = temp;
        q += 1;
    } while (j < 8);
    q = 0;
    j = (s32)parsed;
    do {
        temp = Bin_ReadU32(p_cursor);
        q = (u32 *)((s32)q + 1);
        *(u32 *)((u8 *)j + 0x48) = temp;
        j = j + 4;
    } while ((s32)q < 5);
    Bin_ReadU8(p_cursor);
    Bin_ReadU8(p_cursor);
    Bin_ReadU8(p_cursor);
    ((u8 *)parsed)[0x5C] = Bin_ReadU8(p_cursor);
    ((u8 *)parsed)[0x5D] = Bin_ReadU8(p_cursor);
    ((u8 *)parsed)[0x5E] = Bin_ReadU8(p_cursor);
    ((u8 *)parsed)[0x5F] = Bin_ReadU8(p_cursor);
    ((u8 *)parsed)[0x60] = Bin_ReadU8(p_cursor);
    ((u8 *)parsed)[0x61] = Bin_ReadU8(p_cursor);
    ((u8 *)parsed)[0x62] = Bin_ReadU8(p_cursor);
    ((u8 *)parsed)[0x63] = Bin_ReadU8(p_cursor);
    ((u8 *)parsed)[0x64] = Bin_ReadU8(p_cursor);
    *(u32 *)((u8 *)parsed + 0x38) = Bin_ReadU32(p_cursor);
    *(u32 *)((u8 *)parsed + 0x3C) = Bin_ReadU32(p_cursor);
    *(u32 *)((u8 *)parsed + 0x40) = Bin_ReadU32(p_cursor);
    *(u32 *)((u8 *)parsed + 0x44) = Bin_ReadU32(p_cursor);
    ((u8 *)parsed)[0x65] = 0;
    ((u8 *)parsed)[0xB] = Bin_ReadU8(p_cursor);
    ((u8 *)parsed)[0xC] = Bin_ReadU8(p_cursor);
    ((u8 *)parsed)[0xD] = Bin_ReadU8(p_cursor);
    ((u8 *)parsed)[0xE] = Bin_ReadU8(p_cursor);
    ((u8 *)parsed)[0xA] = Bin_ReadU8(p_cursor);
    ((u8 *)parsed)[0x9] = Bin_ReadU8(p_cursor);
    ((u8 *)parsed)[0x8] = Bin_ReadU8(p_cursor);
    ((u8 *)parsed)[0x66] = Bin_ReadU8(p_cursor);
    j = 0;
    do {
        temp = Bin_ReadU8(p_cursor);
        off = j + 0x30;
        j += 1;
        ((u8 *)parsed)[off] = temp;
    } while (j < 8);
    *p_cursor = (*p_cursor + 3) & ~3;
    ((u8 *)parsed)[0x67] = id;
    DebugPrint((const char *)(gDisposStrings + 0x9A),
                parsed[0],
                parsed[1],
                *(s8 *)((u8 *)parsed + 0xD),
                *(s8 *)((u8 *)parsed + 0xE));
}

s32 Unit_ResolveWarpPos(void *arg0, u8 *arg1, u8 *arg2, u8 arg3, s32 arg4, void *arg5) {
    void *Map_Get(void);
    u8 fn_8004434C(void *, s32, s32);
    u8 fn_80040B1C(void *, s32, s32);
    void fn_800AAC64(void *);
    void *Terrain_GetEntry(u8);
    void fn_800056A0(s32);
    void fn_8001FC24(void *);
    s32 fn_8001FC40(void *, s8, s8);
    extern u8 gBattleMap[];
    extern u16 gUnits[];

    u8 *yp;
    s32 x;
    s32 y;
    u8 terrain;
    s32 cost;
    s32 ring;
    s32 bestCost;
    s32 bestX;
    s32 bestY;
    s32 i;
    void *unit;
    u8 *p;
    u8 *map;
    u8 *map1;
    s32 row;
    u8 id;
    void *tmp;
    u8 *cell;

    yp = arg2;
    x = (s8)*arg1;
    y = (s8)*arg2;
    if (fn_8004434C(Map_Get(), x, y) != 0) {
        return 0;
    }
    terrain = fn_80040B1C(Map_Get(), x, y);
    if (arg3 != 0 && arg0 != NULL) {
        fn_800AAC64(arg0);
    }
    if (x < 0 || y < 0 || x >= *(s32 *)gBattleMap || y >= *(s32 *)(gBattleMap + 4)) {
        cost = -1;
    } else if ((u8)terrain != (u8)fn_80040B1C(Map_Get(), x, y)) {
        cost = -1;
    } else {
        row = y << 6;
        tmp = Terrain_GetEntry(gBattleMap[0x100D + x + row]);
        if (*(u8 *)(*(u8 **)((u8 *)tmp + 8) + 7) != 0) {
            cost = -1;
        } else {
            id = gBattleMap[0xD + x + row];
            if (id != 0) {
                unit = (u8 *)gUnits + ((id - 1) * 0x280);
            } else {
                unit = NULL;
            }
            if (arg0 != NULL && unit == arg0) {
                cost = 0;
            } else if (unit != NULL) {
                cost = -1;
            } else if (gBattleMap[0x300D + x + row] != 0) {
                cost = -1;
            } else if (arg3 != 0) {
                cost = (*(s16 **)(gBattleMap + 0x14190))[x + row];
            } else {
                cost = 0;
            }
        }
    }
    if (cost < 0) {
        ring = 0;
        map = gBattleMap;
        map1 = map + 0x10000;
        do {
            bestX = -1;
            bestY = -1;
            bestCost = 0x2710;
            i = 0;
            ring += 1;
            y -= 1;
            while (i < ring) {
                p = arg5;
                if (x < 0 || y < 0 || x >= *(s32 *)map || y >= *(s32 *)(map + 4)) {
                    cost = -1;
                } else if ((u8)terrain != (u8)fn_80040B1C(Map_Get(), x, y)) {
                    cost = -1;
                } else {
                    if (arg5 != NULL && arg4 > 0) {
                        { s32 k;
                        for (k = 0; k < arg4; k++) {
                            if ((s8)p[0xA] == x && (s8)p[0xB] == y) {
                                cost = -1;
                                goto arm1_done;
                            }
                            p += 0x110;
                        } }
                    }
                    {
                        s32 xx = (s8)x;
                        s32 yy = (s8)y << 6;
                        cell = map + xx + yy;
                        tmp = Terrain_GetEntry(cell[0x100D]);
                        if (*(u8 *)(*(u8 **)((u8 *)tmp + 8) + 7) != 0) {
                            cost = -1;
                        } else {
                            id = cell[0xD];
                            if (id != 0) {
                                unit = (u8 *)gUnits + ((id - 1) * 0x280);
                            } else {
                                unit = NULL;
                            }
                            if (arg0 != NULL && unit == arg0) {
                                cost = 0;
                            } else if (unit != NULL) {
                                cost = -1;
                            } else if (cell[0x300D] != 0) {
                                cost = -1;
                            } else if (arg3 != 0) {
                                cost = (*(s16 **)(map1 + 0x4190))[xx + yy];
                            } else {
                                cost = 0;
                            }
                        }
                    }
                }
            arm1_done:
                if (cost >= 0 && cost < bestCost) {
                    bestCost = cost;
                    bestX = x;
                    bestY = y;
                }
                i += 1;
                x -= 1;
                y += 1;
            }
            i = 0;
            while (i < ring) {
                p = arg5;
                if (x < 0 || y < 0 || x >= *(s32 *)map || y >= *(s32 *)(map + 4)) {
                    cost = -1;
                } else if ((u8)terrain != (u8)fn_80040B1C(Map_Get(), x, y)) {
                    cost = -1;
                } else {
                    if (arg5 != NULL && arg4 > 0) {
                        { s32 k;
                        for (k = 0; k < arg4; k++) {
                            if ((s8)p[0xA] == x && (s8)p[0xB] == y) {
                                cost = -1;
                                goto arm2_done;
                            }
                            p += 0x110;
                        } }
                    }
                    {
                        s32 xx = (s8)x;
                        s32 yy = (s8)y << 6;
                        cell = map + xx + yy;
                        tmp = Terrain_GetEntry(cell[0x100D]);
                        if (*(u8 *)(*(u8 **)((u8 *)tmp + 8) + 7) != 0) {
                            cost = -1;
                        } else {
                            id = cell[0xD];
                            if (id != 0) {
                                unit = (u8 *)gUnits + ((id - 1) * 0x280);
                            } else {
                                unit = NULL;
                            }
                            if (arg0 != NULL && unit == arg0) {
                                cost = 0;
                            } else if (unit != NULL) {
                                cost = -1;
                            } else if (cell[0x300D] != 0) {
                                cost = -1;
                            } else if (arg3 != 0) {
                                cost = (*(s16 **)(map1 + 0x4190))[xx + yy];
                            } else {
                                cost = 0;
                            }
                        }
                    }
                }
            arm2_done:
                if (cost >= 0 && cost < bestCost) {
                    bestCost = cost;
                    bestX = x;
                    bestY = y;
                }
                i += 1;
                x += 1;
                y += 1;
            }
            i = 0;
            while (i < ring) {
                p = arg5;
                if (x < 0 || y < 0 || x >= *(s32 *)map || y >= *(s32 *)(map + 4)) {
                    cost = -1;
                } else if ((u8)terrain != (u8)fn_80040B1C(Map_Get(), x, y)) {
                    cost = -1;
                } else {
                    if (arg5 != NULL && arg4 > 0) {
                        { s32 k;
                        for (k = 0; k < arg4; k++) {
                            if ((s8)p[0xA] == x && (s8)p[0xB] == y) {
                                cost = -1;
                                goto arm3_done;
                            }
                            p += 0x110;
                        } }
                    }
                    {
                        s32 xx = (s8)x;
                        s32 yy = (s8)y << 6;
                        cell = map + xx + yy;
                        tmp = Terrain_GetEntry(cell[0x100D]);
                        if (*(u8 *)(*(u8 **)((u8 *)tmp + 8) + 7) != 0) {
                            cost = -1;
                        } else {
                            id = cell[0xD];
                            if (id != 0) {
                                unit = (u8 *)gUnits + ((id - 1) * 0x280);
                            } else {
                                unit = NULL;
                            }
                            if (arg0 != NULL && unit == arg0) {
                                cost = 0;
                            } else if (unit != NULL) {
                                cost = -1;
                            } else if (cell[0x300D] != 0) {
                                cost = -1;
                            } else if (arg3 != 0) {
                                cost = (*(s16 **)(map1 + 0x4190))[xx + yy];
                            } else {
                                cost = 0;
                            }
                        }
                    }
                }
            arm3_done:
                if (cost >= 0 && cost < bestCost) {
                    bestCost = cost;
                    bestX = x;
                    bestY = y;
                }
                i += 1;
                x += 1;
                y -= 1;
            }
            i = 0;
            while (i < ring) {
                p = arg5;
                if (x < 0 || y < 0 || x >= *(s32 *)map || y >= *(s32 *)(map + 4)) {
                    cost = -1;
                } else if ((u8)terrain != (u8)fn_80040B1C(Map_Get(), x, y)) {
                    cost = -1;
                } else {
                    if (arg5 != NULL && arg4 > 0) {
                        { s32 k;
                        for (k = 0; k < arg4; k++) {
                            if ((s8)p[0xA] == x && (s8)p[0xB] == y) {
                                cost = -1;
                                goto arm4_done;
                            }
                            p += 0x110;
                        } }
                    }
                    {
                        s32 xx = (s8)x;
                        s32 yy = (s8)y << 6;
                        cell = map + xx + yy;
                        tmp = Terrain_GetEntry(cell[0x100D]);
                        if (*(u8 *)(*(u8 **)((u8 *)tmp + 8) + 7) != 0) {
                            cost = -1;
                        } else {
                            id = cell[0xD];
                            if (id != 0) {
                                unit = (u8 *)gUnits + ((id - 1) * 0x280);
                            } else {
                                unit = NULL;
                            }
                            if (arg0 != NULL && unit == arg0) {
                                cost = 0;
                            } else if (unit != NULL) {
                                cost = -1;
                            } else if (cell[0x300D] != 0) {
                                cost = -1;
                            } else if (arg3 != 0) {
                                cost = (*(s16 **)(map1 + 0x4190))[xx + yy];
                            } else {
                                cost = 0;
                            }
                        }
                    }
                }
            arm4_done:
                if (cost >= 0 && cost < bestCost) {
                    bestCost = cost;
                    bestX = x;
                    bestY = y;
                }
                i += 1;
                x -= 1;
                y -= 1;
            }
            if (bestCost != 0x2710) {
                x = bestX;
                y = bestY;
                goto found;
            }
        } while (ring < 0x10);
        fn_800056A0(0);
        fn_8001FC24(gBattleMap);
        return 0;
    }
found:
    if (arg3 == 0) {
        return 0;
    }
    *arg1 = (u8)x;
    *yp = (u8)y;
    if (x != (s8)*((u8 *)arg0 + 0x19E) || y != (s8)*((u8 *)arg0 + 0x19F)) {
        return fn_8001FC40(gBattleMap, (s8)x, (s8)y);
    }
    fn_8001FC24(gBattleMap);
    return 0;
}

#pragma use_lmw_stmw reset

s32 fn_8010866C(void) {
    M2C_UNK fn_800D758C(s32);
    extern s32 lbl_803679C8;
    fn_800D758C(lbl_803679C8);
    return 0;
}

s32 fn_80108694(void) {
    M2C_UNK **fn_800D758C(s32);
    extern s32 lbl_803679C8;
    M2C_UNK fn_800DC3B0(s32);
    M2C_UNK fn_800DAA38(void);
    s32 *global;
    s32 *object;

    global = &lbl_803679C8;
    fn_800D758C(*global);

    object = (s32 *)*global;
    fn_800DC3B0(*(s32 *)((u8 *)object + 0x424));

    fn_800DAA38();
    return 0;
}

void fn_801086CC(void *arg0) {
    M2C_UNK String_Destroy(M2C_UNK *, M2C_UNK);
    M2C_UNK String_Copy(M2C_UNK *);
    M2C_UNK fn_800DC518(s32, M2C_UNK *, M2C_UNK);
    M2C_UNK sp8;

    String_Copy(&sp8);
    fn_800DC518(M2C_FIELD(arg0, s32 *, 0x424), &sp8, 0);
    String_Destroy(&sp8, -1);
}

#pragma cplusplus on
extern "C" void fn_80108718(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void fn_800D7254(void);
    struct Obj {
        u8 pad[0x40];
        virtual void v0(s32, s32, s32) = 0;
        virtual void v1(s32, s32, s32) = 0;
        virtual void v2(s32, s32, s32) = 0;
        virtual void v3(s32, s32, s32) = 0;
        virtual void v4(s32, s32, s32) = 0;
        virtual void v5(s32, s32, s32) = 0;
        virtual void v6(s32, s32, s32) = 0;
        virtual void v7(s32, s32, s32) = 0;
        virtual void v8(s32, s32, s32) = 0;
        virtual void v9(s32, s32, s32) = 0;
        virtual void v10(s32, s32, s32) = 0;
        virtual void v11(s32, s32, s32) = 0;
        virtual void v12(s32, s32, s32) = 0;
        virtual void v13(s32, s32, s32) = 0;
        virtual void v14(s32, s32, s32) = 0;
        virtual void v15(s32, s32, s32) = 0;
        virtual void v16(s32, s32, s32) = 0;
        virtual void v17(s32, s32, s32) = 0;
        virtual void v18(s32, s32, s32) = 0;
        virtual void v19(s32, s32, s32) = 0;
        virtual void v20(s32, s32, s32) = 0;
    };
    fn_800D7254();
    (*(Obj **)((u8 *)arg0 + 0x424))->v20(arg1, arg2, arg3);
}

extern "C" void *fn_80108788(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    typedef struct { u32 size; u32 cap; char *data; } String;
    void String_Init(void *, char *, void *);
    void String_ConcatCStr(void *, void *, char *);
    void fn_800D764C(void *, s32, s32, s32, void *, void *);
    void String_Destroy(void *, s32);
    void *fn_800D75FC(void *, void *);
    void fn_800E3F54(void *);
    extern char lbl_802739B0[];
    extern u8 lbl_8028F340[];
    extern void fn_80108694(void);
    extern void fn_8010866C(void);
    String pathBase;
    String dbxPath;
    String winName;
    String ctrl0;
    String okBtn;
    String cancelBtn;
    void *sp18;
    void *sp14;
    void *sp10;
    void *spC;
    void *sp8;
    void *temp;
    void *self;

    self = arg0;
    String_Init(&pathBase, lbl_802739B0, &sp18);
    String_ConcatCStr(&dbxPath, &pathBase, lbl_802739B0 + 7);
    String_Init(&winName, lbl_802739B0 + 0x11, &sp14);
    fn_800D764C(self, arg1, arg2, arg3, &dbxPath, &winName);
    String_Destroy(&winName, -1);
    String_Destroy(&dbxPath, -1);
    String_Destroy(&pathBase, -1);
    *(void **)((u8 *)self + 0xC) = lbl_8028F340;
    String_Init(&ctrl0, lbl_802739B0 + 0x17, &sp10);
    *(void **)((u8 *)self + 0x424) = fn_800D75FC(self, &ctrl0);
    String_Destroy(&ctrl0, -1);
    String_Init(&okBtn, lbl_802739B0 + 0x22, &spC);
    temp = fn_800D75FC(self, &okBtn);
    *(void **)((u8 *)self + 0x428) = temp;
    *(void **)((u8 *)self + 0x418) = temp;
    String_Destroy(&okBtn, -1);
    String_Init(&cancelBtn, lbl_802739B0 + 0x28, &sp8);
    temp = fn_800D75FC(self, &cancelBtn);
    *(void **)((u8 *)self + 0x42C) = temp;
    *(void **)((u8 *)self + 0x41C) = temp;
    String_Destroy(&cancelBtn, -1);
    temp = *(void **)((u8 *)self + 0x428);
    *(void **)((u8 *)temp + 0xA4) = (void *)fn_80108694;
    temp = *(void **)((u8 *)self + 0x42C);
    *(void **)((u8 *)temp + 0xA4) = (void *)fn_8010866C;
    *(void **)((u8 *)self + 0x14) = *(void **)((u8 *)self + 0x428);
    *(void **)((u8 *)self + 0x414) = *(void **)((u8 *)self + 0x428);
    fn_800E3F54(*(void **)((u8 *)self + 0x414));
    return self;
}

#pragma cplusplus reset
s32 fn_80108948(void) {
    M2C_UNK fn_800D758C(s32);
    extern s32 lbl_803679D0;
    fn_800D758C(lbl_803679D0);
    return 0;
}

s32 fn_80108970(void) {
    M2C_UNK **fn_800D758C(s32);
    extern s32 lbl_803679D0;
    M2C_UNK fn_800DC3B0(s32);
    M2C_UNK fn_800DA748(void);
    s32 *global;
    s32 *object;

    global = &lbl_803679D0;
    fn_800D758C(*global);

    object = (s32 *)*global;
    fn_800DC3B0(*(s32 *)((u8 *)object + 0x424));

    fn_800DA748();
    return 0;
}

#pragma cplusplus on
extern "C" void fn_801089A8(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void fn_800D7254(void);
    struct Obj {
        u8 pad[0x40];
        virtual void v0(s32, s32, s32) = 0;
        virtual void v1(s32, s32, s32) = 0;
        virtual void v2(s32, s32, s32) = 0;
        virtual void v3(s32, s32, s32) = 0;
        virtual void v4(s32, s32, s32) = 0;
        virtual void v5(s32, s32, s32) = 0;
        virtual void v6(s32, s32, s32) = 0;
        virtual void v7(s32, s32, s32) = 0;
        virtual void v8(s32, s32, s32) = 0;
        virtual void v9(s32, s32, s32) = 0;
        virtual void v10(s32, s32, s32) = 0;
        virtual void v11(s32, s32, s32) = 0;
        virtual void v12(s32, s32, s32) = 0;
        virtual void v13(s32, s32, s32) = 0;
        virtual void v14(s32, s32, s32) = 0;
        virtual void v15(s32, s32, s32) = 0;
        virtual void v16(s32, s32, s32) = 0;
        virtual void v17(s32, s32, s32) = 0;
        virtual void v18(s32, s32, s32) = 0;
        virtual void v19(s32, s32, s32) = 0;
        virtual void v20(s32, s32, s32) = 0;
    };
    fn_800D7254();
    (*(Obj **)((u8 *)arg0 + 0x424))->v20(arg1, arg2, arg3);
}

extern "C" void *fn_80108A18(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    typedef struct { u32 size; u32 cap; char *data; } String;
    void String_Init(void *, char *, void *);
    void String_ConcatCStr(void *, void *, char *);
    void fn_800D764C(void *, s32, s32, s32, void *, void *);
    void String_Destroy(void *, s32);
    void *fn_800D75FC(void *, void *);
    void fn_800E3F54(void *);
    extern char lbl_80273A58[];
    extern u8 lbl_8028F350[];
    extern void fn_80108970(void);
    extern void fn_80108948(void);
    String pathBase;
    String dbxPath;
    String winName;
    String ctrl0;
    String okBtn;
    String cancelBtn;
    void *sp18;
    void *sp14;
    void *sp10;
    void *spC;
    void *sp8;
    void *temp;
    void *self;

    self = arg0;
    String_Init(&pathBase, lbl_80273A58, &sp18);
    String_ConcatCStr(&dbxPath, &pathBase, lbl_80273A58 + 7);
    String_Init(&winName, lbl_80273A58 + 0x12, &sp14);
    fn_800D764C(self, arg1, arg2, arg3, &dbxPath, &winName);
    String_Destroy(&winName, -1);
    String_Destroy(&dbxPath, -1);
    String_Destroy(&pathBase, -1);
    *(void **)((u8 *)self + 0xC) = lbl_8028F350;
    String_Init(&ctrl0, lbl_80273A58 + 0x19, &sp10);
    *(void **)((u8 *)self + 0x424) = fn_800D75FC(self, &ctrl0);
    String_Destroy(&ctrl0, -1);
    String_Init(&okBtn, lbl_80273A58 + 0x25, &spC);
    temp = fn_800D75FC(self, &okBtn);
    *(void **)((u8 *)self + 0x428) = temp;
    *(void **)((u8 *)self + 0x418) = temp;
    String_Destroy(&okBtn, -1);
    String_Init(&cancelBtn, lbl_80273A58 + 0x2B, &sp8);
    temp = fn_800D75FC(self, &cancelBtn);
    *(void **)((u8 *)self + 0x42C) = temp;
    *(void **)((u8 *)self + 0x41C) = temp;
    String_Destroy(&cancelBtn, -1);
    temp = *(void **)((u8 *)self + 0x428);
    *(void **)((u8 *)temp + 0xA4) = (void *)fn_80108970;
    temp = *(void **)((u8 *)self + 0x42C);
    *(void **)((u8 *)temp + 0xA4) = (void *)fn_80108948;
    *(void **)((u8 *)self + 0x414) = *(void **)((u8 *)self + 0x418);
    fn_800E3F54(*(void **)((u8 *)self + 0x414));
    return self;
}

#pragma cplusplus reset

void fn_80108BD0(void *arg0, s32 x, s32 y, s32 w) {
    void *Hash_Lookup(void *);
    void *p;
    s32 a;
    s32 b;
    s32 sum;

    arg0 = Hash_Lookup(arg0);
    p = *(void **)((u8 *)arg0 + 0x14);
    a = x + 2;
    sum = x + w;
    b = y + 2;
    *(s16 *)((u8 *)p + 0x8) = a;
    a = sum - 4;
    b = y + 0x72;
    sum -= 0x32;
    *(s16 *)((u8 *)p + 0xA) = y + 2;
    *(s16 *)((u8 *)p + 0xC) = a;
    *(s16 *)((u8 *)p + 0xE) = b;
    a = x + 0x32;

    p = *(void **)((u8 *)arg0 + 0x18);
    *(s16 *)((u8 *)p + 0x18) = x;
    *(s16 *)((u8 *)p + 0x14) = x;
    *(s16 *)((u8 *)p + 0x1A) = y;
    *(s16 *)((u8 *)p + 0x16) = y;

    p = *(void **)((u8 *)arg0 + 0x1C);
    *(s16 *)((u8 *)p + 0x18) = sum;
    *(s16 *)((u8 *)p + 0x14) = sum;
    *(s16 *)((u8 *)p + 0x1A) = y;
    *(s16 *)((u8 *)p + 0x16) = y;

    p = *(void **)((u8 *)arg0 + 0x20);
    *(s16 *)((u8 *)p + 0x14) = a;
    *(s16 *)((u8 *)p + 0x18) = sum;
    *(s16 *)((u8 *)p + 0x1A) = y;
    *(s16 *)((u8 *)p + 0x16) = y;
}

void fn_80108C80(s32 arg0, s32 arg1) {
    extern u8 lbl_8028F3AC[];
    void *Process_CreateChild(u8 *, s32);
    s32 *obj;
    obj = (s32 *)Process_CreateChild(lbl_8028F3AC, arg1);
    obj[0x30 / 4] = arg0;
}

void fn_80108CB8(void *arg0) {
void Process_ClearFunc(void *);
extern u32 *gPadInput;
extern f32 lbl_8036A110;
extern f32 lbl_8036A114;
extern f32 lbl_8036A118;
extern f32 lbl_8036A11C;
s32 held;
f32 fb;
f32 scale;
f32 divisor;
f32 one;
f32 v64;
f32 v1b;
held=(s32)gPadInput[1];
if(held&((s32)gPadInput[2]^held)&0x200){
Process_ClearFunc(arg0);
}
fb=(f32)(s8)*((u8*)gPadInput[0]+2);
scale=lbl_8036A110;
*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x40)=*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x40)-(fb*scale);
divisor=lbl_8036A114;
one=lbl_8036A118;
fb=(f32)(s8)*((u8*)gPadInput[0]+3);
*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x44)=*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x44)+(fb*scale);
fb=(f32)*((u8*)gPadInput[0]+6);
*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x54)=*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x54)-(fb/divisor);
fb=(f32)*((u8*)gPadInput[0]+7);
*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x54)=*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x54)+(fb/divisor);
if(*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x54)<one){
*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x54)=one;
}
*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x58)=*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x54);
held=(s32)gPadInput[1];
if(held&((s32)gPadInput[2]^held)&0x1000){
v64=lbl_8036A11C;
v1b=one;
*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x40)=v64;
*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x44)=v64;
*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x54)=v1b;
*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x58)=v1b;
}
if((s32)gPadInput[3]&1){
*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x3C)=*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x3C)+(f32)(*(u8*)(*(u8**)((u8*)*(void**)((u8*)arg0+0x34)+0x30)+4)-1);
*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x3C)=(f32)((s32)*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x3C)%*(u8*)(*(u8**)((u8*)*(void**)((u8*)arg0+0x34)+0x30)+4));
}
if((s32)gPadInput[3]&2){
*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x3C)=*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x3C)+one;
*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x3C)=(f32)((s32)*(f32*)((u8*)*(void**)((u8*)arg0+0x34)+0x3C)%*(u8*)(*(u8**)((u8*)*(void**)((u8*)arg0+0x34)+0x30)+4));
}
}

void fn_80108F38(void) {
    M2C_UNK fn_800AA208();
    fn_800AA208();
}

void fn_80108F58(void *arg0) {
    void fn_800AA1CC(void *);
    void *Sound_Create(s32, void *);
    extern f32 lbl_8036A130;
    f32 f;
    void *p;

    *(void **)((char *)arg0 + 0x34) = Sound_Create(*(s32 *)((char *)arg0 + 0x30), arg0);
    f = lbl_8036A130;
    p = *(void **)((char *)arg0 + 0x34);
    *(f32 *)((char *)p + 0x38) = f;
    p = *(void **)((char *)arg0 + 0x34);
    *(f32 *)((char *)p + 0x3C) = f;
    fn_800AA1CC(p);
}

void fn_80108FA8(void) {
    void *Hash_Lookup(void);
    void fn_8005C8B4(s32);
    s32 i;
    void *entry;
    void *list;
    s8 *ptr;

    list = Hash_Lookup();
    i = 0;
    entry = list;
    goto check;
loop:
    ptr = *(s8 **)((char *)entry + 0x14);
    switch (*ptr) {
    case 1:
        fn_8005C8B4(*(s32 *)(ptr + 8));
        break;
    }
    entry = (char *)entry + 4;
    i += 1;
check:
    if (i < *(u8 *)((char *)list + 4)) {
        goto loop;
    }
}

void fn_80109020(u8 *arg0) {
    extern u8 lbl_8028F390[];
    extern void *lbl_803679D8;
    extern void *lbl_803679DC;
    void Process_UnlinkByKey(void *);
    void fn_8000BF6C(void *, void *);
    void Process_Unlink(void *);
    void *fn_8011D484(void);
    void fn_8010913C(void);
    void *var_r3;

    if (arg0 == NULL) {
        Process_UnlinkByKey(lbl_8028F390);
        return;
    }
    if ((s8)arg0[0] == 0x54 && (s8)arg0[1] == 0x42 && (s8)arg0[2] == 0x47 && (s8)arg0[3] == 0) {
        var_r3 = fn_8011D484();
    } else {
        lbl_803679DC = NULL;
        lbl_803679D8 = arg0;
        fn_8000BF6C(lbl_8028F390, fn_8010913C);
        var_r3 = lbl_803679DC;
    }
    if (var_r3 != NULL) {
        Process_Unlink(var_r3);
    }
}

s32 Sound_FindByName(s8 *arg0) {
extern s32 lbl_803679DC; extern s8 *lbl_803679D8; extern u8 lbl_8028F390[];
s32 fn_8011D484(s8 *); void fn_8010913C(void); void fn_8000BF6C(void *, void (*)(void));
s32 ret;
if(arg0[0]==0x54 && arg0[1]==0x42 && arg0[2]==0x47 && arg0[3]==0) {
ret=fn_8011D484(arg0);
} else {
lbl_803679DC=0; lbl_803679D8=arg0;
fn_8000BF6C(lbl_8028F390,fn_8010913C);
ret=lbl_803679DC;
}
return ret;
}

void fn_8010913C(void *arg0) {
    s32 Str_Cmp(s32, s32);
    extern s32 lbl_803679D8;
    extern void *lbl_803679DC;
    if (Str_Cmp(*M2C_FIELD(arg0, s32 **, 0x30), lbl_803679D8) == 0) {
        lbl_803679DC = arg0;
    }
}

void *Sound_Create(s32 arg0, u32 arg1) {
    void *Process_Create(void *, u32);
    void fn_80109F88(void *, s32);
    extern u8 lbl_8028F390[];
    void *tbl;
    void *result;

    tbl = lbl_8028F390;
    switch (arg1) {
    case 0:
        arg1 = 3U;
        break;
    }
    result = Process_Create(tbl, arg1);
    fn_80109F88(result, arg0);
    return result;
}

#pragma cplusplus on
extern "C" void fn_801091D8(void *arg0) {
    struct Obj {
        u8 pad[4];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
    };
    s32 i;
    u8 *list;
    u8 *entry;

    i = 0;
    list = *(u8 **)((u8 *)arg0 + 0x30);
    entry = list;
    goto check;
loop:
    ((Obj *)*(void **)(entry + 0x14))->v2();
    entry += 4;
    i += 1;
check:
    if (i < list[4]) {
        goto loop;
    }
}
#pragma cplusplus reset
void Prim2D_SetAlphaByte(s8 arg0);
void Prim2D_SetColorByte(s8 arg0);
void fn_80009C20(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8);
void fn_80109244(struct Arg0 *arg0) {
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetColorByte(u8);
    void Prim2D_SetAlphaByte(u8);
    extern f64 lbl_8036A128;
    extern f64 lbl_8036A120;
    extern f32 lbl_8036A134;
    extern f32 lbl_8036A130;
    struct UnkCycler *outer;
    struct Arg0 *self;
    s32 i;
    s32 temp_r31;
    s32 next;
    s32 count;
    s32 rem;
    f32 f1_2;
    f32 pos;
    f32 f0;
    f32 f1;
    u8 *p;
    struct UnkObject *obj;

    self = arg0;
    self->unk3C = self->unk3C + self->unk38;
    f0 = self->unk3C;
    f1 = self->unk34;
    if (f0 >= f1) {
        self->unk3C = f0 - f1;
    }
    Prim2D_Begin();
    fn_80009C20(self->unk30, self->unk40, self->unk44, self->unk48 + (f32)self->unk30->unk6, self->unk4C, self->unk50, self->unk54, self->unk58, self->unk5C);
    Prim2D_SetColorByte(self->unk60);
    Prim2D_SetAlphaByte(self->unk61);
    Prim2D_PrepareTex();
    outer = self->unk30;
    pos = self->unk3C;
    if (outer->unk5 == 0) {
        i = outer->unk4 - 1;
        p = (u8 *)outer + (i << 2);
        while (i >= 0) {
            obj = *(struct UnkObject **)(p + 0x14);
            obj->v1(0xFF);
            p -= 4;
            i--;
        }
    } else if (outer->unk5 == 2) {
        temp_r31 = (s32)pos;
        count = outer->unk4;
        next = temp_r31 + 1;
        f1_2 = lbl_8036A134 * (pos - (f32)temp_r31);
        rem = next - (next / count) * count;
        if (f1_2 != lbl_8036A130) {
            obj = *(struct UnkObject **)((u8 *)outer + (rem << 2) + 0x14);
            obj->v1((s32)f1_2);
        }
        obj = *(struct UnkObject **)((u8 *)outer + (temp_r31 << 2) + 0x14);
        obj->v1(0xFF);
    } else if (outer->unk5 == 1) {
        obj = *(struct UnkObject **)((u8 *)outer + (((s32)pos) << 2) + 0x14);
        obj->v1(0xFF);
    }
    Prim2D_Begin();
    Prim2D_SetColorByte(0xFF);
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
}

void Sound_TweenParam(void *arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5) {
extern const f32 lbl_8036A138;
extern f32 lbl_8036A130;
extern u32 gUiInputFlags;
void *Process_Create(void *,void *);
extern u8 lbl_8028F374[];
SoundTweenProc *proc;
void *target;
f32 cur;
if(gUiInputFlags&1) { if(lbl_8036A138 != arg4) {switch((u8)arg1) {
case 0: *(f32 *)((u8 *)arg0+64)=arg4; break;
case 1: *(f32 *)((u8 *)arg0+68)=arg4; break;
case 2: *(f32 *)((u8 *)arg0+72)=arg4; break;
case 3: *(f32 *)((u8 *)arg0+76)=arg4; break;
case 4: *(f32 *)((u8 *)arg0+80)=arg4; break;
case 5: *(f32 *)((u8 *)arg0+84)=arg4; break;
case 6: *(f32 *)((u8 *)arg0+88)=arg4; break;
case 7: *(f32 *)((u8 *)arg0+84)=arg4; *(f32 *)((u8 *)arg0+88)=arg4; break;
case 8: *(f32 *)((u8 *)arg0+92)=arg4; break;
case 9: *((u8 *)arg0+96)=(s32)arg4; break;
case 10: *((u8 *)arg0+97)=(s32)arg4; break;
}
} return; }
if(arg3==arg4) {if(lbl_8036A138 != arg3) {switch((u8)arg1) {
case 0: *(f32 *)((u8 *)arg0+64)=arg3; break;
case 1: *(f32 *)((u8 *)arg0+68)=arg3; break;
case 2: *(f32 *)((u8 *)arg0+72)=arg3; break;
case 3: *(f32 *)((u8 *)arg0+76)=arg3; break;
case 4: *(f32 *)((u8 *)arg0+80)=arg3; break;
case 5: *(f32 *)((u8 *)arg0+84)=arg3; break;
case 6: *(f32 *)((u8 *)arg0+88)=arg3; break;
case 7: *(f32 *)((u8 *)arg0+84)=arg3; *(f32 *)((u8 *)arg0+88)=arg3; break;
case 8: *(f32 *)((u8 *)arg0+92)=arg3; break;
case 9: *((u8 *)arg0+96)=(s32)arg3; break;
case 10: *((u8 *)arg0+97)=(s32)arg3; break;
}
} return;}
proc=Process_Create(lbl_8028F374,arg0);
proc->target=proc->parent;
proc->param=arg1; proc->mode=arg2;
if(lbl_8036A138==arg3) {
target=proc->target;
switch((u8)arg1) {
case 0: cur=*(f32 *)((u8 *)target+64); break;
case 1: cur=*(f32 *)((u8 *)target+68); break;
case 2: cur=*(f32 *)((u8 *)target+72); break;
case 3: cur=*(f32 *)((u8 *)target+76); break;
case 4: cur=*(f32 *)((u8 *)target+80); break;
case 5: cur=*(f32 *)((u8 *)target+84); break;
case 6: cur=*(f32 *)((u8 *)target+88); break;
case 8: cur=*(f32 *)((u8 *)target+92); break;
case 9: cur=*((u8 *)target+96); break;
case 10: cur=*((u8 *)target+97); break;
default:cur=lbl_8036A130;break;}
proc->start=cur;
} else { proc->start=arg3; }
proc->end=arg4;
proc->duration=(f32)(s32)arg5;
proc->time=0.0f;
if(lbl_8036A138!=arg3) {switch((u8)arg1) {
case 0: *(f32 *)((u8 *)arg0+64)=arg3; break;
case 1: *(f32 *)((u8 *)arg0+68)=arg3; break;
case 2: *(f32 *)((u8 *)arg0+72)=arg3; break;
case 3: *(f32 *)((u8 *)arg0+76)=arg3; break;
case 4: *(f32 *)((u8 *)arg0+80)=arg3; break;
case 5: *(f32 *)((u8 *)arg0+84)=arg3; break;
case 6: *(f32 *)((u8 *)arg0+88)=arg3; break;
case 7: *(f32 *)((u8 *)arg0+84)=arg3; *(f32 *)((u8 *)arg0+88)=arg3; break;
case 8: *(f32 *)((u8 *)arg0+92)=arg3; break;
case 9: *((u8 *)arg0+96)=(s32)arg3; break;
case 10: *((u8 *)arg0+97)=(s32)arg3; break;
}
} }

#pragma global_optimizer off
void fn_801097DC(void *arg0) {
    extern f32 lbl_8036A138;
    f32 zero;
    f32 val;
    u8 kind;
    void *target;

    zero = lbl_8036A138;
    val = *(f32 *)((u8 *)arg0 + 0x44);
    kind = *(u8 *)((u8 *)arg0 + 0x34);
    target = *(void **)((u8 *)arg0 + 0x30);
    if (zero == val) {
        return;
    }
    switch (kind) {
    case 0:
        *(f32 *)((u8 *)target + 0x40) = val;
        break;
    case 1:
        *(f32 *)((u8 *)target + 0x44) = val;
        break;
    case 2:
        *(f32 *)((u8 *)target + 0x48) = val;
        break;
    case 3:
        *(f32 *)((u8 *)target + 0x4C) = val;
        break;
    case 4:
        *(f32 *)((u8 *)target + 0x50) = val;
        break;
    case 5:
        *(f32 *)((u8 *)target + 0x54) = val;
        break;
    case 6:
        *(f32 *)((u8 *)target + 0x58) = val;
        break;
    case 7:
        *(f32 *)((u8 *)target + 0x54) = val;
        *(f32 *)((u8 *)target + 0x58) = val;
        break;
    case 8:
        *(f32 *)((u8 *)target + 0x5C) = val;
        break;
    case 9:
        *(u8 *)((u8 *)target + 0x60) = (u8)(s32)val;
        break;
    case 10:
        *(u8 *)((u8 *)target + 0x61) = (u8)(s32)val;
        break;
    }
}
#pragma global_optimizer reset
void fn_80109890(void *arg0) {
    extern f32 lbl_8036A138, lbl_8036A13C;
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    f32 zero;
    f32 val;
    u8 kind;
    void *target;
    *(f32*)((u8*)arg0+0x38) += 16.666666f;
    if (*(f32*)((u8*)arg0+0x38) >= *(f32*)((u8*)arg0+0x3C)) {
        *(f32*)((u8*)arg0+0x38) = *(f32*)((u8*)arg0+0x3C);
        Process_ClearFunc(arg0);
    }
    val = Math_Ease(*(u8*)((u8*)arg0+0x35), *(f32*)((u8*)arg0+0x40), *(f32*)((u8*)arg0+0x44), *(f32*)((u8*)arg0+0x38), *(f32*)((u8*)arg0+0x3C));
    zero=lbl_8036A138;
    kind=*(u8*)((u8*)arg0+0x34);
    target=*(void**)((u8*)arg0+0x30);
    if(zero==val) return;
    switch(kind) {
case 0: *(f32*)((u8*)target+64)=val; break;
case 1: *(f32*)((u8*)target+68)=val; break;
case 2: *(f32*)((u8*)target+72)=val; break;
case 3: *(f32*)((u8*)target+76)=val; break;
case 4: *(f32*)((u8*)target+80)=val; break;
case 5: *(f32*)((u8*)target+84)=val; break;
case 6: *(f32*)((u8*)target+88)=val; break;
    case 7: *(f32*)((u8*)target+0x54)=val; *(f32*)((u8*)target+0x58)=val; break;
    case 8: *(f32*)((u8*)target+0x5C)=val; break;
    case 9: *(u8*)((u8*)target+0x60)=(u8)(s32)val; break;
    case 10: *(u8*)((u8*)target+0x61)=(u8)(s32)val; break;
    }
}

f32 fn_801099A0(void *arg0, u8 arg1) {
    extern f32 lbl_8036A130;

    switch (arg1) {
    case 0:
        return *(f32 *)((u8 *)arg0 + 0x40);
    case 1:
        return *(f32 *)((u8 *)arg0 + 0x44);
    case 2:
        return *(f32 *)((u8 *)arg0 + 0x48);
    case 3:
        return *(f32 *)((u8 *)arg0 + 0x4C);
    case 4:
        return *(f32 *)((u8 *)arg0 + 0x50);
    case 5:
        return *(f32 *)((u8 *)arg0 + 0x54);
    case 6:
        return *(f32 *)((u8 *)arg0 + 0x58);
    case 7:
        return *(f32 *)((u8 *)arg0 + 0x5C);
    case 8:
        return (f32)*(u8 *)((u8 *)arg0 + 0x60);
    case 9:
        return (f32)*(u8 *)((u8 *)arg0 + 0x61);
    case 10:
    default:
        return lbl_8036A130;
    }
}

void fn_80109A54(void *arg0, u8 arg1, f32 arg2)
{
  extern f32 lbl_8036A138;
  void **new_var;
  if (lbl_8036A138 == arg2)
  {
    return;
  }
  new_var = &arg0;
  switch (arg1)
  {
    case 0:
      *((f32 *) (((u8 *) arg0) + 0x40)) = arg2;
      break;

    case 1:
      *((f32 *) (((u8 *) arg0) + 0x44)) = arg2;
      break;

    case 2:
      *((f32 *) (((u8 *) arg0) + 0x48)) = arg2;
      break;

    case 3:
      *((f32 *) (((u8 *) arg0) + 0x4C)) = arg2;
      break;

    case 4:
      *((f32 *) (((u8 *) arg0) + 0x50)) = arg2;
      break;

    case 5:
      *((f32 *) (((u8 *) arg0) + 0x54)) = arg2;
      break;

    case 6:
      *((f32 *) (((u8 *) arg0) + 0x58)) = arg2;
      break;

    case 7:
      *((f32 *) (((u8 *) arg0) + 0x54)) = arg2;
      *((f32 *) (((u8 *) arg0) + 0x58)) = arg2;
      break;

    case 8:
      *((f32 *) (((u8 *) arg0) + 0x5C)) = arg2;
      break;

    case 9:
      *((u8 *) (((u8 *) (*new_var)) + 0x60)) = (u8) ((s32) arg2);
      break;

    case 10:
      *((u8 *) (((u8 *) (*new_var)) + 0x61)) = (u8) ((s32) arg2);
      break;

  }

}

void fn_80109B00(void *arg0, s8 arg1) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s8 *, 0xE) = arg1;
}

u8 fn_80109B0C(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), u8 *, 0xE);
}

void fn_80109B18(void *arg0, s8 arg1) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s8 *, 0xD) = arg1;
}

u8 fn_80109B24(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), u8 *, 0xD);
}

void fn_80109B30(void *arg0, u8 arg1) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), u8 *, 0xC) = arg1;
    M2C_FIELD(arg0, s8 *, 0x61) = (s8) (((arg1 >> 1U) & 0x7F) + 1);
}

u8 fn_80109B48(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), u8 *, 0xC);
}

#pragma global_optimizer off
void fn_80109B54(void *arg0, f32 farg0) {
    extern const f32 lbl_8036A140;
    void *p;
    f32 c;
    f32 t34;
    f32 t8;

    p = *(void **)((u8 *)arg0 + 0x30);
    *(volatile f32 *)((u8 *)p + 8) = farg0;
    c = lbl_8036A140;
    p = *(void **)((u8 *)arg0 + 0x30);
    *(f32 *)((u8 *)arg0 + 0x34) = (f32)*(u8 *)((u8 *)p + 4);
    p = *(void **)((u8 *)arg0 + 0x30);
    t34 = *(f32 *)((u8 *)arg0 + 0x34);
    t8 = *(f32 *)((u8 *)p + 8);
    *(f32 *)((u8 *)arg0 + 0x38) = t34 / (c * t8);
}
#pragma global_optimizer on
f32 fn_80109BA8(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), f32 *, 8);
}

void fn_80109BB4(void *arg0, u8 arg1) {
    void *Process_Create(void *, void *);
    extern u8 lbl_8028F360[];
    void *temp_r3;
    s16 temp_r5;

    temp_r3 = Process_Create(lbl_8028F360, arg0);
    *(void **)((char *)temp_r3 + 0x30) = arg0;
    temp_r5 = (s16)arg1;
    *(u32 *)((char *)temp_r3 + 0x34) = 0;
    *(u32 *)((char *)temp_r3 + 0x38) = (u32)temp_r5;
    *(u32 *)((char *)temp_r3 + 0x3C) = (u32)*(u8 *)((char *)arg0 + 0x60);
    *(u32 *)((char *)temp_r3 + 0x40) = 0;
    *(s16 *)((char *)arg0 + 0x28) = temp_r5;
}

void Sound_FadeToVol(void *arg0, u8 arg1) {
    void *Process_Create(void *, void *);
    extern u8 lbl_8028F360[];
    void *temp_r3;

    temp_r3 = Process_Create(lbl_8028F360, arg0);
    *(void **)((char *)temp_r3 + 0x30) = arg0;
    *(u32 *)((char *)temp_r3 + 0x34) = 0;
    *(u32 *)((char *)temp_r3 + 0x38) = (u32)arg1;
    *(u32 *)((char *)temp_r3 + 0x3C) = (u32)*(u8 *)((char *)arg0 + 0x60);
    *(u32 *)((char *)temp_r3 + 0x40) = 0;
}

void Sound_FadeFromZero(void *arg0, u8 arg1) {
    void *Process_Create(void *, void *);
    extern u8 lbl_8028F360[];
    void *temp_r3;

    temp_r3 = Process_Create(lbl_8028F360, arg0);
    *(void **)((char *)temp_r3 + 0x30) = arg0;
    *(u32 *)((char *)temp_r3 + 0x34) = 0;
    *(u32 *)((char *)temp_r3 + 0x38) = (u32)arg1;
    *(u32 *)((char *)temp_r3 + 0x3C) = 0;
    *(u32 *)((char *)temp_r3 + 0x40) = 0xFF;
    *(u8 *)((char *)arg0 + 0x60) = 0;
}

/* Process tick: ease the sound object's volume byte (+0x60), then clear when done. */
void Sound_FadeVolProc(void *proc) {
    f32 Math_Ease(M2C_UNK, f32, f32, f32, f32);
    M2C_UNK Process_ClearFunc(void *);
    void *sound;

    sound = M2C_FIELD(proc, void **, 0x30);
    M2C_FIELD(proc, s32 *, 0x34) = (s32)(M2C_FIELD(proc, s32 *, 0x34) + 1);
    M2C_FIELD(sound, s8 *, 0x60) = (s8)Math_Ease(
        0,
        (f32)M2C_FIELD(proc, s32 *, 0x3C),
        (f32)M2C_FIELD(proc, s32 *, 0x40),
        (f32)M2C_FIELD(proc, s32 *, 0x34),
        (f32)M2C_FIELD(proc, s32 *, 0x38));
    if ((s32)M2C_FIELD(proc, s32 *, 0x34) >= (s32)M2C_FIELD(proc, s32 *, 0x38)) {
        Process_ClearFunc(proc);
    }
}

void fn_80109DC0(void *arg0, u32 kind) {
    f32 width;
    f32 height;
    f32 x,y,cx,cy;
    u8 *image=*(u8**)(*(u8**)((u8*)arg0+0x30)+0x14);
    width=height=0.0f;
    switch(image[0]) {
    case 1:
        width=(f32)(*(u16*)(image+0x20)-*(u16*)(image+0x1C));
        height=(f32)(*(u16*)(image+0x22)-*(u16*)(image+0x1E));
        break;
    }
    x=608.0f-width; y=448.0f-height;
    cx=x/2.0f; cy=y/2.0f;
    switch(kind) {
case 1: *(f32*)((u8*)arg0+0x40)=0.0f; *(f32*)((u8*)arg0+0x44)=y; break;
case 2: *(f32*)((u8*)arg0+0x40)=cx; *(f32*)((u8*)arg0+0x44)=y; break;
case 3: *(f32*)((u8*)arg0+0x40)=x; *(f32*)((u8*)arg0+0x44)=y; break;
case 4: *(f32*)((u8*)arg0+0x40)=0.0f; *(f32*)((u8*)arg0+0x44)=cy; break;
case 5: *(f32*)((u8*)arg0+0x40)=cx; *(f32*)((u8*)arg0+0x44)=cy; break;
case 6: *(f32*)((u8*)arg0+0x40)=x; *(f32*)((u8*)arg0+0x44)=cy; break;
case 7: *(f32*)((u8*)arg0+0x40)=0.0f; *(f32*)((u8*)arg0+0x44)=0.0f; break;
case 8: *(f32*)((u8*)arg0+0x40)=cx; *(f32*)((u8*)arg0+0x44)=0.0f; break;
case 9: *(f32*)((u8*)arg0+0x40)=x; *(f32*)((u8*)arg0+0x44)=0.0f; break;
    }
}

void fn_80109EEC(void *arg0) {
    extern f32 lbl_8036A130;
    extern f32 lbl_8036A14C;
    f32 zero;
    void *temp_r4;
    u8 *temp_r6;
    s32 kind;
    f32 t;
    f32 scale;

    zero = lbl_8036A130;
    temp_r4 = *(void **)((u8 *)arg0 + 0x30);
    *(f32 *)((u8 *)arg0 + 0x50) = zero;
    *(f32 *)((u8 *)arg0 + 0x4C) = zero;
    temp_r6 = *(u8 **)((u8 *)temp_r4 + 0x14);
    kind = temp_r6[0];
    switch (kind) {
    case 1:
        *(f32 *)((u8 *)arg0 + 0x4C) = (f32)(s32)(*(u16 *)(temp_r6 + 0x20) - *(u16 *)(temp_r6 + 0x1C));
        *(f32 *)((u8 *)arg0 + 0x50) = (f32)(s32)(*(u16 *)(temp_r6 + 0x22) - *(u16 *)(temp_r6 + 0x1E));
        break;
    }
    t = *(f32 *)((u8 *)arg0 + 0x4C);
    *(f32 *)((u8 *)arg0 + 0x4C) = t * (scale = lbl_8036A14C);
    t = *(f32 *)((u8 *)arg0 + 0x50);
    *(f32 *)((u8 *)arg0 + 0x50) = t * scale;
}

#pragma cplusplus on
extern "C" void fn_80109F88(void *arg0, void *arg1) {
    void *Hash_Lookup(void *);
    void FallingParticle_Spawn(void *);
    void fn_801FCC68(void *);
    void fn_801FC6E0(void *, f32);
    void fn_801FC634(void *, f32);
    extern f32 lbl_8036A118;
    extern f32 lbl_8036A130;
    extern f32 lbl_8036A140;
    extern f32 lbl_8036A14C;
    extern f32 lbl_8036A150;
    extern u32 lbl_8028F594[];
    extern u32 lbl_8028F5E4[];
    extern u32 lbl_8028FEEC[];
    extern u32 lbl_8028F5BC[];
    extern u32 lbl_8028F5A8[];
    extern u32 lbl_8028F3F8[];
    extern u32 lbl_8028F5D0[];
    struct Obj {
        u8 pad[4];
        virtual void v0();
    };
    f32 one;
    f32 zerof;
    s32 var_r31;
    void *temp_r30;
    void *var_r29;
    u8 *temp_r3;
    u8 temp_r0;
    u8 *temp_r6;
    f32 scale;
    f32 *p;
    u8 temp_r0_3;
    u8 temp_r4;
    void *temp_r3_3;
    void *ptr1;
    void *ptr2;

    one = lbl_8036A130;
    zerof = lbl_8036A118;
    *(f32 *)((u8 *)arg0 + 0x48) = one;
    *(f32 *)((u8 *)arg0 + 0x44) = one;
    *(f32 *)((u8 *)arg0 + 0x40) = one;
    *(f32 *)((u8 *)arg0 + 0x50) = one;
    *(f32 *)((u8 *)arg0 + 0x4C) = one;
    *(f32 *)((u8 *)arg0 + 0x58) = zerof;
    *(f32 *)((u8 *)arg0 + 0x54) = zerof;
    *(f32 *)((u8 *)arg0 + 0x5C) = one;
    *((u8 *)arg0 + 0x60) = 0xFF;
    *((u8 *)arg0 + 0x61) = 0x80;
    *(void **)((u8 *)arg0 + 0x30) = Hash_Lookup(arg1);
    var_r31 = 0;
    temp_r30 = *(void **)((u8 *)arg0 + 0x30);
    var_r29 = temp_r30;
    while (var_r31 < (s32)*((u8 *)temp_r30 + 4)) {
        temp_r3 = (u8 *)*(void **)((u8 *)var_r29 + 0x14);
        temp_r0 = temp_r3[0];
        switch ((s32)temp_r0) {
        case 1:
            if (temp_r3 != NULL) {
                ptr1 = lbl_8028F594;
                ptr2 = lbl_8028F5E4;
                *(void **)(temp_r3 + 4) = ptr1;
                *(void **)(temp_r3 + 4) = ptr2;
                temp_r3[0] = temp_r0;
                temp_r3[1] = 0x24;
            }
            break;
        case 2:
            if (temp_r3 != NULL) {
                ptr1 = lbl_8028F594;
                ptr2 = lbl_8028FEEC;
                *(void **)(temp_r3 + 4) = ptr1;
                *(void **)(temp_r3 + 4) = ptr2;
                temp_r3[0] = temp_r0;
                temp_r3[1] = 0x28;
            }
            break;
        case 3:
            if (temp_r3 != NULL) {
                ptr1 = lbl_8028F594;
                ptr2 = lbl_8028F5BC;
                *(void **)(temp_r3 + 4) = ptr1;
                *(void **)(temp_r3 + 4) = ptr2;
                temp_r3[0] = temp_r0;
                temp_r3[1] = 0x18;
            }
            break;
        case 4:
            if (temp_r3 != NULL) {
                ptr1 = lbl_8028F594;
                ptr2 = lbl_8028F5A8;
                *(void **)(temp_r3 + 4) = ptr1;
                *(void **)(temp_r3 + 4) = ptr2;
                temp_r3[0] = temp_r0;
                temp_r3[1] = 0x14;
            }
            break;
        case 5:
            if (temp_r3 != NULL) {
                ptr1 = lbl_8028F594;
                ptr2 = lbl_8028F3F8;
                *(void **)(temp_r3 + 4) = ptr1;
                *(void **)(temp_r3 + 4) = ptr2;
                temp_r3[0] = temp_r0;
                temp_r3[1] = 0x20;
            }
            break;
        case 6:
            if (temp_r3 != NULL) {
                ptr1 = lbl_8028F594;
                ptr2 = lbl_8028F5E4;
                *(void **)(temp_r3 + 4) = ptr1;
                *(void **)(temp_r3 + 4) = ptr2;
                *(void **)(temp_r3 + 4) = lbl_8028F5D0;
                temp_r3[0] = temp_r0;
                temp_r3[1] = 0x34;
            }
            break;
        }
        ((Obj *)*(void **)((u8 *)var_r29 + 0x14))->v0();
        var_r29 = (u8 *)var_r29 + 4;
        var_r31 += 1;
    }
    switch ((s32)*((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0xE)) {
    case 1:
        FallingParticle_Spawn(arg0);
        break;
    case 2:
        fn_801FCC68(arg0);
        break;
    case 3:
        fn_801FC6E0(arg0, lbl_8036A150);
        break;
    case 4:
        fn_801FC634(arg0, lbl_8036A150);
        break;
    }
    temp_r3_3 = *(void **)((u8 *)arg0 + 0x30);
    *(f32 *)((u8 *)arg0 + 0x50) = lbl_8036A130;
    *(f32 *)((u8 *)arg0 + 0x4C) = lbl_8036A130;
    temp_r6 = *(u8 **)((u8 *)temp_r3_3 + 0x14);
    if ((s32)temp_r6[0] == 1) {
        *(f32 *)((u8 *)arg0 + 0x4C) = (f32)(s32)(*(u16 *)(temp_r6 + 0x20) - *(u16 *)(temp_r6 + 0x1C));
        *(f32 *)((u8 *)arg0 + 0x50) = (f32)(s32)(*(u16 *)(temp_r6 + 0x22) - *(u16 *)(temp_r6 + 0x1E));
    }
    scale = lbl_8036A14C;
    p = (f32 *)((u8 *)arg0 + 0x4C);
    *p = *p * scale;
    p = (f32 *)((u8 *)arg0 + 0x50);
    *p = *p * scale;
    temp_r0_3 = *((u8 *)temp_r3_3 + 0xC);
    if (temp_r0_3 != 0 && temp_r0_3 != 0xFF) {
        *((u8 *)arg0 + 0x61) = (u8)((temp_r0_3 >> 1) + 1);
    }
    *(f32 *)((u8 *)arg0 + 0x3C) = lbl_8036A130;
    temp_r4 = *((u8 *)*(void **)((u8 *)arg0 + 0x30) + 4);
    if (temp_r4 == 1 || lbl_8036A130 == *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 8)) {
        *(f32 *)((u8 *)arg0 + 0x34) = lbl_8036A118;
        *(f32 *)((u8 *)arg0 + 0x38) = lbl_8036A130;
    } else {
        *(f32 *)((u8 *)arg0 + 0x34) = (f32)(u32)temp_r4;
        *(f32 *)((u8 *)arg0 + 0x38) = *(f32 *)((u8 *)arg0 + 0x34) / (lbl_8036A140 * *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 8));
    }
}

extern "C" void fn_8010A330(void *arg0) {
    void Prim2D_Begin(void);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPosCorners(f32, f32, f32, f32);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetCornerColors(s32 *, s32 *, s32 *, s32 *);
    void Prim2D_EndPrim(void);
    u32 sp24;
    u32 sp20;
    u32 sp1C;
    u32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    u8 *p;

    p = (u8 *)arg0;
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(3);
    Prim2D_SetPosCorners(
        (f32)*(s16 *)(p + 8),
        (f32)*(s16 *)(p + 0xA),
        (f32)*(s16 *)(p + 0xC),
        (f32)*(s16 *)(p + 0xE)
    );
    Prim2D_EmitQuad();
    sp18 = (p[0x10] << 24) + ((p[0x11] << 16) + (p[0x12] << 8) + p[0x13]);
    sp1C = (p[0x14] << 24) + ((p[0x15] << 16) + (p[0x16] << 8) + p[0x17]);
    sp20 = (p[0x18] << 24) + ((p[0x19] << 16) + (p[0x1A] << 8) + p[0x1B]);
    sp24 = (p[0x1C] << 24) + ((p[0x1D] << 16) + (p[0x1E] << 8) + p[0x1F]);
    sp8 = sp24;
    spC = sp20;
    sp10 = sp1C;
    sp14 = sp18;
    Prim2D_SetCornerColors(&sp14, &sp10, &spC, &sp8);
    Prim2D_EndPrim();
}

#pragma cplusplus off

extern u16 lbl_80312060[32];
void fn_8010A4D4(void *arg0) {
    s32 off;
    s16 a;
    s16 b;
    u8 c;
    char *p;
    u8 *out;
    s32 i;
    s32 dest;

    p = arg0;
    out = (u8 *)lbl_80312060;
    dest = 0;
    i = 0;
    while (i < *(s16 *)((char *)arg0 + 8)) {
        switch (*(u8 *)(p + 0xE)) {
        default:
            break;
        case 0: {
            off = (s8)dest;
            c = *(u8 *)(p + 0x10);
            off *= 6;
            b = *(s16 *)(p + 0xC);
            a = *(s16 *)(p + 0xA);
            dest++;
            out = (u8 *)lbl_80312060 + off;
            *(s16 *)(out + 0) = a;
            *(s16 *)(out + 2) = b;
            *(s16 *)(out + 4) = c;
        }
        }
        p += 8;
        i++;
    }
}

/* Draw a UI text label with left/center/right alignment and the given alpha. */
void Ui_DrawTextLabel(void *label, s32 alpha) {
    void *Msg_Expand(void *);
    s32 Text_MeasureWidth(void *, s32, f32);
    void Prim2D_Begin(void);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetPrimParam(f32);
    s32 *Ui_GetColor(u8);
    void Prim2D_SetColorPacked(s32 *);
    void Prim2D_SetAlpha(s32);
    void Prim2D_SetTextScale(u8, f32);
    void fn_800071D8(u8, f32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    extern f32 lbl_8036A130;
    extern f32 lbl_8036A118;
    extern f32 gTextScale2;
    s32 color;
    f32 drawX;
    void *text;
    s32 alphaLocal;
    void *lab;
    s8 align;
    s32 width;

    lab = label;
    drawX = lbl_8036A130;
    text = Msg_Expand(*(void **)((u8 *)label + 8));
    alphaLocal = alpha;
    align = *(s8 *)((u8 *)lab + 0x14);
    switch (align) {
    case -1:
        drawX = (f32)*(s16 *)((u8 *)lab + 0xC);
        break;
    case 0:
        width = Text_MeasureWidth(text, -1, lbl_8036A118);
        drawX = (f32)(*(s16 *)((u8 *)lab + 0xC) - (width / 2));
        break;
    case 1:
        drawX = (f32)(*(s16 *)((u8 *)lab + 0xC) - Text_MeasureWidth(text, -1, lbl_8036A118));
        break;
    }
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(6);
    Prim2D_SetPos(drawX, (f32)*(s16 *)((u8 *)lab + 0xE));
    Prim2D_SetPrimParam((f32)*(s8 *)((u8 *)lab + 2));
    color = *Ui_GetColor(*(u8 *)((u8 *)lab + 0x12));
    Prim2D_SetColorPacked(&color);
    Prim2D_SetAlpha(alphaLocal);
    Prim2D_SetTextScale(*(u8 *)((u8 *)lab + 0x10), gTextScale2);
    fn_800071D8(*(u8 *)((u8 *)lab + 0x11), lbl_8036A118);
    Prim2D_SetText(text);
    Prim2D_EndPrim();
}

#pragma use_lmw_stmw on
void fn_8010A704(void *arg0, u8 arg1) {
    void Prim2D_SetCornerColors(s32 *, s32 *, s32 *, s32 *);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetUvCorners(f32, f32, f32, f32);
    void Prim2D_SetPosCorners(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void fn_80009EB0(s32, u8, u8, s32);
    void Prim2D_BindTexture(s32, u8, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    extern s32 lbl_8036C4D8;
    extern s32 lbl_8036C4DC;
    extern s32 lbl_8036C4E0;
    extern s32 lbl_8036C4E4;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    u8 *p;
    u8 alpha;
    s16 a;
    s16 b;

    Prim2D_Begin();
    if (*(u8 *)((u8 *)arg0 + 0x10) & 2) {
        fn_80009EB0(*(s32 *)((u8 *)arg0 + 0xC), *(u8 *)((u8 *)arg0 + 0x12), *(u8 *)((u8 *)arg0 + 0x11), 0x11);
    } else {
        Prim2D_BindTexture(*(s32 *)((u8 *)arg0 + 0xC), *(u8 *)((u8 *)arg0 + 0x12), 0x11);
    }
    Prim2D_PrepareTex();
    a = *(s16 *)((u8 *)arg0 + 0x18);
    b = *(s16 *)((u8 *)arg0 + 0x14);
    if (a == b) {
        *(s16 *)((u8 *)arg0 + 0x18) = (s16)(b + *(u16 *)((u8 *)arg0 + 0x20) - *(u16 *)((u8 *)arg0 + 0x1C));
    }
    a = *(s16 *)((u8 *)arg0 + 0x1A);
    b = *(s16 *)((u8 *)arg0 + 0x16);
    if (a == b) {
        *(s16 *)((u8 *)arg0 + 0x1A) = (s16)(b + *(u16 *)((u8 *)arg0 + 0x22) - *(u16 *)((u8 *)arg0 + 0x1E));
    }
    alpha = arg1;
    if (arg1 == 0xFF) {
        alpha = *(u8 *)((u8 *)arg0 + 0x13);
    }
    sp24 = lbl_8036C4D8;
    sp20 = lbl_8036C4DC;
    sp1C = lbl_8036C4E0;
    sp18 = lbl_8036C4E4;
    p = (u8 *)&sp24;
    p[0] = ((u8 *)arg0)[0x24];
    p[1] = ((u8 *)arg0)[0x25];
    p[2] = ((u8 *)arg0)[0x26];
    p[3] = (u8)((alpha * ((u8 *)arg0)[0x27]) >> 8);
    p = (u8 *)&sp20;
    p[0] = ((u8 *)arg0)[0x28];
    p[1] = ((u8 *)arg0)[0x29];
    p[2] = ((u8 *)arg0)[0x2A];
    p[3] = (u8)((alpha * ((u8 *)arg0)[0x2B]) >> 8);
    p = (u8 *)&sp1C;
    p[0] = ((u8 *)arg0)[0x2C];
    p[1] = ((u8 *)arg0)[0x2D];
    p[2] = ((u8 *)arg0)[0x2E];
    p[3] = (u8)((alpha * ((u8 *)arg0)[0x2F]) >> 8);
    p = (u8 *)&sp18;
    p[0] = ((u8 *)arg0)[0x30];
    p[1] = ((u8 *)arg0)[0x31];
    p[2] = ((u8 *)arg0)[0x32];
    p[3] = (u8)((alpha * ((u8 *)arg0)[0x33]) >> 8);
    Prim2D_AddPrim(3);
    Prim2D_SetPosCorners(
        (f32)*(s16 *)((u8 *)arg0 + 0x14),
        (f32)*(s16 *)((u8 *)arg0 + 0x16),
        (f32)*(s16 *)((u8 *)arg0 + 0x18),
        (f32)*(s16 *)((u8 *)arg0 + 0x1A));
    Prim2D_SetUvCorners(
        (f32)*(u16 *)((u8 *)arg0 + 0x1C),
        (f32)*(u16 *)((u8 *)arg0 + 0x1E),
        (f32)*(u16 *)((u8 *)arg0 + 0x20),
        (f32)*(u16 *)((u8 *)arg0 + 0x22));
    Prim2D_EmitQuad();
    sp8 = sp18;
    spC = sp1C;
    sp10 = sp20;
    sp14 = sp24;
    Prim2D_SetCornerColors(&sp14, &sp10, &spC, &sp8);
    Prim2D_EndPrim();
}
#pragma use_lmw_stmw reset

#pragma cplusplus on
extern "C" void Sprite_Draw(void *sprite, u8 alpha) {
    void Prim2D_SetAlpha(u8);
    void Prim2D_SetUvCorners(f32, f32, f32, f32);
    void Prim2D_SetPosCorners(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void fn_80009EB0(s32, u8, u8, s32);
    void Prim2D_BindTexture(s32, u8, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);

    struct Obj {
        u8 pad[4];
        virtual void method();
    };

    // Draw sprite: bind texture, expand zero-size rect from UVs, apply alpha.
    s16 uvW;
    s16 uvH;
    s16 x1;
    s16 x0;
    u8 a;

    a = alpha;
    if (!(*(u8 *)((u8 *)sprite + 0x10) & 0x80)) {
        ((Obj *)sprite)->method();
    }
    Prim2D_Begin();
    if (*(u8 *)((u8 *)sprite + 0x10) & 2) {
        fn_80009EB0(*(s32 *)((u8 *)sprite + 0xC), *(u8 *)((u8 *)sprite + 0x12), *(u8 *)((u8 *)sprite + 0x11), 0x11);
    } else {
        Prim2D_BindTexture(*(s32 *)((u8 *)sprite + 0xC), *(u8 *)((u8 *)sprite + 0x12), 0x11);
    }
    Prim2D_PrepareTex();
    uvW = *(u16 *)((u8 *)sprite + 0x20) - *(u16 *)((u8 *)sprite + 0x1C);
    if (uvW < 0) {
        uvW = -uvW;
    }
    uvH = *(u16 *)((u8 *)sprite + 0x22) - *(u16 *)((u8 *)sprite + 0x1E);
    if (uvH < 0) {
        uvH = -uvH;
    }
    x1 = *(s16 *)((u8 *)sprite + 0x18);
    x0 = *(s16 *)((u8 *)sprite + 0x14);
    if (x1 == x0) {
        *(s16 *)((u8 *)sprite + 0x18) = x0 + uvW;
    }
    x1 = *(s16 *)((u8 *)sprite + 0x1A);
    x0 = *(s16 *)((u8 *)sprite + 0x16);
    if (x1 == x0) {
        *(s16 *)((u8 *)sprite + 0x1A) = x0 + uvH;
    }
    if (a == 0xFF) {
        a = *(u8 *)((u8 *)sprite + 0x13);
    }
    Prim2D_AddPrim(1);
    Prim2D_SetPosCorners(
        (f32)*(s16 *)((u8 *)sprite + 0x14),
        (f32)*(s16 *)((u8 *)sprite + 0x16),
        (f32)*(s16 *)((u8 *)sprite + 0x18),
        (f32)*(s16 *)((u8 *)sprite + 0x1A));
    Prim2D_SetUvCorners(
        (f32)*(u16 *)((u8 *)sprite + 0x1C),
        (f32)*(u16 *)((u8 *)sprite + 0x1E),
        (f32)*(u16 *)((u8 *)sprite + 0x20),
        (f32)*(u16 *)((u8 *)sprite + 0x22));
    Prim2D_SetAlpha(a);
    Prim2D_EndPrim();
}
#pragma cplusplus reset
void fn_8010AB78(void *arg0) {
    if (*(u8*)((char*)arg0 + 0x10) & 0x80) {
        FileCache_ReleaseSlot((char*)arg0 + 0xC);
        *(u8*)((char*)arg0 + 0x10) = *(u8*)((char*)arg0 + 0x10) & 0x7F;
    }
}

void fn_8010ABC0(void *arg0)
{
    void fn_8006EEFC(void *, void *);
    void FileCache_OrFlags(void *, s32);
    u8 fn_8006EBA4(void *, s32);

    u8 *obj;
    u8 flags;

    obj = (u8 *)arg0;

    if (!(obj[0x10] & 0x80)) {
        fn_8006EEFC(obj + 0x0C, *(void **)(obj + 0x08));

        if (obj[0x10] & 1) {
            FileCache_OrFlags(*(void **)(obj + 0x08), 4);
        }

        if ((u8)fn_8006EBA4(*(void **)(obj + 0x0C), obj[0x12]) != 0) {
            flags = obj[0x10];
            obj[0x10] = flags | 2;
            obj[0x11] = 0;
        }

        obj[0x10] |= 0x80;
    }
}

void fn_8010AC4C(void) {

}

void fn_8010AC50(void) {

}

void fn_8010AC54(void) {

}

s32 fn_8010AC58(void *arg0) {
u8 fn_80102EA8(void);
u8 fn_8010B30C(void *, s8, s16);
s32 fn_8010B01C(void *, s8, s8);
u8 fn_8018D294(void *, void *);
u8 Status_Test(void *, u8);
void Map_SelectRangeBuffer(void *, s32);
void Map_FillLayer(void *, s32, s32);
extern u8 gUiContext[], gBattleMap[], gAiState[], Ai_UnitIsHostileToActive[];
#pragma cplusplus on
struct Range {
static u8 Test(void *arg0, s32 x, s32 y) {
u8 *map;
u8 result;
map=gBattleMap;
if(Status_Test((u8*)arg0+0x1BC,0x3C) &&
(Map_SelectRangeBuffer(map,5), Map_FillLayer(map,11,-1),
(*(s16**)(map+0x14190))[x+(y<<6)]=0,
fn_8018D294(arg0,Ai_UnitIsHostileToActive))) result=gAiState[0x21C];
else result=0;
return result;
}
};
s32 x;
s32 y;
u8 result;
if(fn_80102EA8()) return 0;
x=((s8*)gUiContext)[0xD]; y=((s8*)gUiContext)[0xE];
if(fn_8010B30C(arg0,x,y)) return 1;
result=Range::Test(arg0,x,y);
if(result) return 1;
return (u8)fn_8010B01C(arg0,x,y)!=0;
#pragma cplusplus reset
}

s32 fn_8010AD94(void *arg0) {
    u8 fn_80102EA8(void);
    u8 fn_8010B30C(void *, s8, s16);
    u8 fn_8018D294(void *, void *);
    u8 Status_Test(void *, u8);
    void Map_SelectRangeBuffer(void *, s32);
    void Map_FillLayer(void *, s32, s32);
    extern u8 gUiContext[], gBattleMap[], gAiState[], Ai_UnitIsHostileToActive[];
#pragma cplusplus on
struct Range {
static u8 Test(void *arg0, s32 x, s32 y) {
u8 *map;
u8 result;
map=gBattleMap;
if(Status_Test((u8*)arg0+0x1BC,0x3C) &&
(Map_SelectRangeBuffer(map,5), Map_FillLayer(map,11,-1),
(*(s16**)(map+0x14190))[x+(y<<6)]=0,
fn_8018D294(arg0,Ai_UnitIsHostileToActive))) result=gAiState[0x21C];
else result=0;
return result;
}
};
s32 x;
s32 y;
u8 result;
if(fn_80102EA8()) return 0;
if(gUiContext[8]==0x2C) return 0;
x=((s8*)gUiContext)[0xD]; y=((s8*)gUiContext)[0xE];
if(fn_8010B30C(arg0,x,y)) return 1;
result=Range::Test(arg0,x,y);
if(result) return 1;
return 0;
#pragma cplusplus reset
}

s32 fn_8010AEC8(void *arg0, s32 arg1) {
u8 fn_80102EA8(void);
u8 fn_8010B30C(void *, s8, s16);
s32 fn_8010B01C(void *, s8, s8);
u8 fn_8018D294(void *, void *);
u8 Status_Test(void *, u8);
void Map_SelectRangeBuffer(void *, s32);
void Map_FillLayer(void *, s32, s32);
extern u8 gUiContext[], gBattleMap[], gAiState[], Ai_UnitIsHostileToActive[];
#pragma cplusplus on
struct Range {
static u8 Test(void *arg0, s32 x, s32 y) {
u8 *map;
u8 result;
map=gBattleMap;
if(Status_Test((u8*)arg0+0x1BC,0x3C) &&
(Map_SelectRangeBuffer(map,5), Map_FillLayer(map,11,-1),
(*(s16**)(map+0x14190))[x+(y<<6)]=0,
fn_8018D294(arg0,Ai_UnitIsHostileToActive))) result=gAiState[0x21C];
else result=0;

return result;
}
};
s32 x;
s32 y;
u8 result;
if(fn_80102EA8()) return 0;
if(arg1==gUiContext[8]) return 0;
x=((s8*)gUiContext)[0xD]; y=((s8*)gUiContext)[0xE];
if(fn_8010B30C(arg0,x,y)) return 1;
result=Range::Test(arg0,x,y);
if(result) return 1;
return (u8)fn_8010B01C(arg0,x,y)!=0;
#pragma cplusplus reset
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
s32 fn_8010B01C(void *arg0, s8 arg1, s8 arg2) {
    void Allegiance_FillMask(s32, void *);
    s32 Item_GetRangeForUnit(void *, void *);
    void Map_FillLayer(void *, s32, s32);
    void Map_SelectRangeBuffer(void *, s32);
    void **Unit_GetHeldItemSlot(void *, s32);
    u8 fn_8009339C(void *);
    void fn_800951D0(void *, s32);
    u8 Unit_IsInMovAttackRange(void *, void *, void **);
    u8 fn_800F7E9C(void *, s8, s8, void *);
    void fn_800FB96C(s32, s8, s8, void *, u8, u8, s8, s32, s32);
    void fn_800FDDBC(s8, s8, u8, u8, s32);
    u8 fn_80100FD0(s8, s8, s8, s8, u8);
    extern u8 gBattleMap[];
    extern u16 gUnits[];

    struct Unit {
        u8 pad0[0x188];
        u32 unk188;
        u8 pad18C[4];
        void *unk190;
        u8 pad194[0xA];
        u8 unk19E;
        u8 unk19F;
        u32 unk1A0;
    };
    struct Item {
        u8 pad0[0x1D];
        u8 unk1D;
    };
    struct Result {
        u8 x;
        u8 y;
        u16 slot;
        struct Unit *unit;
        s32 score;
    } result;
    struct Result best;
    u8 flags[8];
    s32 pad;
    u8 *map;
    struct Unit *unit;
    s32 slot;
    void **item;
    s32 unitId;

    best.score = 0x80000000;
    best.unit = NULL;
    Map_FillLayer(gBattleMap, 5, -1);
    Map_SelectRangeBuffer(gBattleMap, 5);
    map = gBattleMap;
    (*(s16 **)(map + 0x14190))[(s8)arg1 + ((s8)arg2 << 6)] = 0;

    slot = 0;
loop_slot:
    item = Unit_GetHeldItemSlot(arg0, slot);
    if (*item != NULL) {
        if (fn_8009339C(arg0) != 0) {
            result.slot = (u16)slot;
            Allegiance_FillMask(1, flags);
            unitId = 1;
            do {
                if ((u8)unitId != 0) {
                    unit = (struct Unit *)((u8 *)gUnits + (((u8)unitId - 1) * 0x280));
                } else {
                    unit = NULL;
                }
                if (unit->unk188 != 0) {
                    if (flags[((u8 *)unit->unk190)[8]] != 0) {
                        if (Unit_IsInMovAttackRange(arg0, unit, item) != 0) {
                            if ((unit->unk1A0 & 0x010000DC) == 0) {
                                u8 temp_r3_2 = unit->unk19E;
                                u8 var_r5 = 0;
                                u8 temp_r6 = unit->unk19F;
                                if (((s8)temp_r3_2 < (s8)map[8])
                                    || ((s32)((s8)map[0xA] - 1) < (s8)temp_r3_2)
                                    || ((s8)temp_r6 < (s8)map[9])
                                    || ((s32)((s8)map[0xB] - 1) < (s8)temp_r6)) {
                                    var_r5 = 1;
                                }
                                if (var_r5 == 0) {
                                    u8 var_r0;
                                    if (*item != NULL) {
                                        var_r0 = Item_GetRangeForUnit(*item, arg0);
                                    } else {
                                        var_r0 = 0;
                                    }
                                    if (fn_80100FD0(arg1, arg2, (s8)unit->unk19E, (s8)unit->unk19F, (u32)var_r0) != 0) {
                                        u8 var_r0_2;
                                        u8 var_r0_3;
                                        if (*item != NULL) {
                                            var_r0_2 = Item_GetRangeForUnit(*item, unit);
                                        } else {
                                            var_r0_2 = 0;
                                        }
                                        if (*item != NULL) {
                                            var_r0_3 = ((struct Item *)*item)->unk1D;
                                        } else {
                                            var_r0_3 = 0;
                                        }
                                        fn_800FDDBC((s8)unit->unk19E, (s8)unit->unk19F, var_r0_3, var_r0_2, 6);
                                        result.unit = unit;
                                        if (fn_800F7E9C(arg0, arg1, arg2, &result) != 0) {
                                            if (result.score > best.score) {
                                                best.x = result.x;
                                                best.score = result.score;
                                                best.y = result.y;
                                                best.slot = result.slot;
                                                best.unit = result.unit;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                ++unitId;
            } while (unitId <= 0x9F);
        }
        slot += 1;
        if (slot < 4) {
            goto loop_slot;
        }
    }

    if (best.unit != NULL) {
        fn_800951D0(arg0, best.slot);
        pad = 0;
        fn_800FB96C(0xF, (s8)best.x, (s8)best.y, best.unit,
                    best.unit->unk19E, best.unit->unk19F,
                    (s8)best.slot, 0, 0);
        return 1;
    }
    return 0;
}
u8 fn_8010B30C(void *arg0, s16 arg1, s16 arg2) {
    u8 Allegiance_Compare(s32, s32);
    void fn_8001F9C4(u8 *, s8, s8, s8, s32);
    void Map_FillLayer(u8 *, s32, s32);
    void Map_SelectRangeBuffer(u8 *, s32);
    u8 fn_8003863C(void *);
    void fn_800FB96C(s32, s8, s8, void *, u8, u8, s8, s32, s32);
    u8 Map_IsAiTerrainBlocked(s8, s8);
    u8 Status_Test(void *, u8);
    extern u8 gBattleMap[151280];
    extern u16 gUnits[];
    extern s32 lbl_8036A158;
    extern s32 lbl_80273B30[];
    extern u8 gAiState[];

    s16 sp10;
    s32 sp8;
    u8 found;
    s32 *scan;
    s32 xMin;
    s32 yMin;
    s32 xMax;
    s32 yMax;
    s32 y;
    s32 x;
    s32 xShift;
    u8 *cell;
    void *unit;
    s32 *ent;
    s32 pri;
    s32 bestPri;
    s32 bestId;
    void *bestUnit;

    found = 0;
    sp10 = arg2;
    scan = &lbl_8036A158;
    goto scan_cmp;
scan_loop:
    if (Status_Test((u8 *)arg0 + 0x1BC, (u8)*scan) != 0) {
        found = 1;
    } else {
        scan += 1;
        goto scan_cmp;
    }
    goto scan_done;
scan_cmp:
    if (*scan != -1) {
        goto scan_loop;
    }
scan_done:
    if (found == 0) {
        return 0;
    }

    Map_SelectRangeBuffer(gBattleMap, 5);
    Map_FillLayer(gBattleMap, 0xB, -1);
    fn_8001F9C4(gBattleMap, (s8)arg1, (s8)sp10, 1, 0);

    bestPri = 0x7F;
    xMin = arg1 - 1;
    if (xMin < (s8)gBattleMap[8]) {
        xMin = (s8)gBattleMap[8];
    }
    yMin = sp10 - 1;
    if (yMin < (s8)gBattleMap[9]) {
        yMin = (s8)gBattleMap[9];
    }
    xMax = arg1 + 1;
    if (xMax > (s8)gBattleMap[0xA] - 1) {
        xMax = (s8)gBattleMap[0xA] - 1;
    }
    yMax = sp10 + 1;
    if (yMax > (s8)gBattleMap[0xB] - 1) {
        yMax = (s8)gBattleMap[0xB] - 1;
    }

    y = yMin;
    goto outer_cmp;
outer:
    x = xMin;
    xShift = (s8)y << 6;
    goto inner_cmp;
inner:
    if ((*(s16 **)(gBattleMap + 0x14190))[(s8)x + xShift] >= 0) {
        cell = gBattleMap + xShift + (s8)x;
        if ((s8)cell[0xE18E] == 0 && Map_IsAiTerrainBlocked((s8)x, (s8)y) == 0) {
            if (cell[0xD] != 0) {
                if (cell[0xD] != 0) {
                    unit = (u8 *)gUnits + (cell[0xD] - 1) * 0x280;
                } else {
                    unit = NULL;
                }
                if (Allegiance_Compare(*(s32 *)((u8 *)arg0 + 0x190), *(s32 *)((u8 *)unit + 0x190)) == 0) {
                    pri = 0;
                    ent = lbl_80273B30;
                    goto tab_cmp;
tab_loop:
                    if (Status_Test((u8 *)arg0 + 0x1BC, (u8)ent[0]) == 0
                        || ((u8 (*)(void *, void *))ent[1])(arg0, unit) == 0) {
                        ent += 2;
                        pri += 1;
                        goto tab_cmp;
                    }
                    goto tab_found;
tab_cmp:
                    if ((u32)ent[1] != 0) {
                        goto tab_loop;
                    }
tab_found:
                    if ((s8)ent[0] >= 0) {
                        if ((s8)pri <= (s8)bestPri) {
                            if ((s8)pri != (s8)bestPri
                                || fn_8003863C(unit) >= fn_8003863C(bestUnit)) {
                                bestPri = pri;
                                bestId = (s8)ent[0];
                                bestUnit = unit;
                            }
                        }
                    }
                }
            }
        }
    }
    x += 1;
inner_cmp:
    if (x <= xMax) {
        goto inner;
    }
    y += 1;
outer_cmp:
    if (y <= yMax) {
        goto outer;
    }

    if ((s8)bestPri != 0x7F) {
        sp8 = 0;
        fn_800FB96C(0x12, (s8)arg1, (s8)sp10, bestUnit,
                    *(u8 *)((u8 *)bestUnit + 0x19E),
                    *(u8 *)((u8 *)bestUnit + 0x19F),
                    (s8)(bestId - 0x18), 0, sp8);
    }
    return gAiState[0x21C];
}
#pragma use_lmw_stmw reset

s32 fn_8010B60C(void *arg0, void *arg1) {
    u8 Status_Test(void *, s32);
    if (Status_Test((u8 *)arg1 + 0x1BC, 0x18) != 0) {
        return 0;
    }
    return *(u32 *)((u8 *)arg1 + 0x1A0) & 1;
}

#pragma use_lmw_stmw on
u8 Ai_TryApproachHealer(void *arg0) {
    void Map_BuildUnitMoveRange(void *, s32, s32);
    u8 Map_IsAiTerrainBlocked(s8, s8);
    u8 Allegiance_Compare(s32, s32);
    void **Unit_GetItemSlot(void *, s8);
    s32 Map_CountNeighborUnits(s16, s16, void *);
    void Ai_SetUnitMoveTo(void *, s32, s32, s32, s32, s32, s32, s32);
    extern u8 gAiState[];
    extern u8 gBattleMap[151280];
    extern u16 gUnits[];
    extern u8 Ai_UnitIsHostileToActive[];

    void *other;
    s8 found;
    s8 idx;
    u8 *map;
    u8 *map2;
    void *self;
    s32 xShift;
    u8 *row;
    s32 t;
    s32 bestDist;
    u8 bestCost;
    s16 bestX;
    s16 bestY;
    s32 y;
    s32 x;

    self = arg0;
    if ((gAiState[1] & 2) || (*(u32 *)((u8 *)self + 0x254) & 0x03000000)) {
        return 0;
    }
    map = gBattleMap;
    bestCost = 0xFF;
    bestDist = 0x7FFFFFFF;
    Map_BuildUnitMoveRange(self, 5, *(s32 *)map * *(s32 *)(map + 4));
    map2 = gBattleMap;
    y = ((s8 *)map2)[9];
    goto outer_cmp;
outer:
    x = ((s8 *)map2)[8];
    xShift = (s8)y << 6;
    row = map2 + xShift;
    goto inner_cmp;
inner:
    t = (s8)x + xShift;
    if (((s16 *)(map2 + 0x610E))[t] >= 0) {
        other = row + (s8)x;
        if (*(s8 *)((u8 *)other + 0xE18E) == 0) {
            if (Map_IsAiTerrainBlocked((s8)x, (s8)y) == 0) {
                u8 id = ((u8 *)other)[0xD];
                if (id != 0) {
                    if (id != 0) {
                        other = (void *)((s32)((u8 *)gUnits + (id - 1) * 0x280) + (0 & (s32)other));
                    } else {
                        other = (void *)(0 & (s32)other);
                    }
                    if (self != other && Allegiance_Compare(*(s32 *)((u8 *)self + 0x190), *(s32 *)((u8 *)other + 0x190)) != 1) {
                        void *item;
                        u8 typ;
                        u8 sub;
                        s32 dist;
                        s16 cost;
                        found = -1;
                        idx = 4;
                        goto slot_cmp;
                    slot_loop:
                        item = *Unit_GetItemSlot(other, idx);
                        if (item == NULL) {
                            goto slot_done;
                        }
                        if (item != NULL) {
                            typ = ((u8 *)item)[0x12];
                        } else {
                            typ = 0xC;
                        }
                        if (typ == 0xA) {
                            if (item != NULL) {
                                sub = ((u8 *)item)[0x14];
                            } else {
                                sub = 0xC;
                            }
                            if (sub == 0x81) {
                                found = idx;
                                goto slot_done;
                            }
                        }
                        idx += 1;
                    slot_cmp:
                        if (idx < 8) {
                            goto slot_loop;
                        }
                    slot_done:
                        if (found >= 0) {
                            dist = Map_CountNeighborUnits((s16)x, (s16)y, Ai_UnitIsHostileToActive);
                            if (dist <= bestDist) {
                                u8 bc = bestCost;
                                cost = *(s16 *)((s32)*(s16 **)(map + 0x14190) + (t << 1));
                                if (cost < (s32)bc) {
                                    bestDist = dist;
                                    bestCost = (u8)cost;
                                    bestX = (s16)x;
                                    bestY = (s16)y;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    x += 1;
inner_cmp:
    if (x <= (s8)map2[0xA] - 1) {
        goto inner;
    }
    y += 1;
outer_cmp:
    if (y <= (s8)map2[0xB] - 1) {
        goto outer;
    }
    if ((u32)(bestDist - 0x7FFF0000) != 0xFFFFU) {
        s32 bx;
        s32 by;
        u8 *p;
        u8 tile;
        u8 v;
        bx = (s8)bestX;
        by = (s8)bestY;
        p = map + bx;
        v = ((u8 *)self)[0x198];
        p = (u8 *)((s32)p + (by << 6));
        tile = p[0xD];
        if (tile != v) {
            Ai_SetUnitMoveTo(self, bestX, bestY, 1, 0xFFFF, 0, 0, -1);
        }
    }
    return gAiState[0x21C];
}
#pragma use_lmw_stmw reset
/* AI: pick a reachable approach tile and set the unit's move destination. */
u8 Ai_TrySelectApproachTile(void *unit) {
    void Map_BuildUnitMoveRange(void *, s32, s32);
    u8 Map_IsAiTerrainBlocked(s8, s8);
    void *Terrain_GetEntry(u8);
    u8 Allegiance_Compare(s32, s32);
    s32 Map_CountNeighborUnits(s16, s16, void *);
    void Ai_SetUnitMoveTo(void *, s32, s32, s32, s32, s32, s32, s32);
    extern u8 gAiState[];
    extern u8 gBattleMap[151280];
    extern u16 gUnits[];
    extern u8 Ai_UnitIsHostileToActive[];

    void *self;
    s32 xShift;
    u8 *row;
    u8 *row2;
    s32 t;
    s32 bestDist;
    u8 bestCost;
    s16 bestX;
    s16 bestY;
    s32 y;
    s32 x;
    u8 *map;
    u8 *map2;
    void *other;

    self = unit;
    if ((gAiState[1] & 2) || (*(u32 *)((u8 *)self + 0x254) & 0x03000000)) {
        return 0;
    }
    map = gBattleMap;
    bestCost = 0xFF;
    bestDist = 0x7FFFFFFF;
    Map_BuildUnitMoveRange(self, 5, *(s32 *)map * *(s32 *)(map + 4));
    map2 = gBattleMap;
    y = ((s8 *)map2)[9];
    goto outer_cmp;
outer:
    x = ((s8 *)map2)[8];
    xShift = (s8)y << 6;
    row = map2 + xShift;
    row2 = map + xShift;
    goto inner_cmp;
inner:
    other = (void *)(s32)(s8)x;
    t = (s32)other + xShift;
    if (((s16 *)(map2 + 0x610E))[t] >= 0) {
        if ((s8)*(row + (s32)other + 0xE18E) == 0) {
            if (Map_IsAiTerrainBlocked((s8)(s32)other, (s8)y) == 0) {
                u8 id;
                void *info;
                s32 flags;

                other = row2 + (s32)other;
                info = Terrain_GetEntry(((u8 *)other)[0x100D]);
                if (*(u8 *)(*(u8 **)((u8 *)info + 8) + 6) != 0) {
                    id = ((u8 *)other)[0xD];
                    if (id != 0) {
                        if (id != 0) {
                            other = (u8 *)gUnits + (id - 1) * 0x280;
                        } else {
                            other = NULL;
                        }
                        if (Allegiance_Compare(*(s32 *)((u8 *)self + 0x190), *(s32 *)((u8 *)other + 0x190)) != 1) {
                            flags = *(s32 *)((u8 *)other + 0x254);
                            if (!(flags & 0x03000000)) {
                                goto block_23;
                            }
                            if (!(flags & 4)) {
                                goto skip;
                            }
                            goto block_23;
                        }
                    } else {
                        goto block_23;
                    }
                } else {
                    id = ((u8 *)other)[0xD];
                    if (id != 0) {
                        if (id != 0) {
                            other = (u8 *)gUnits + (id - 1) * 0x280;
                        } else {
                            other = NULL;
                        }
                        if (Allegiance_Compare(*(s32 *)((u8 *)self + 0x190), *(s32 *)((u8 *)other + 0x190)) != 1) {
                            if (*(s32 *)((u8 *)other + 0x254) & 4) {
                                goto block_23;
                            }
                        }
                    }
                }
                goto skip;
            block_23:
                {
                    s32 dist;
                    s16 cost;
                    dist = Map_CountNeighborUnits((s16)x, (s16)y, Ai_UnitIsHostileToActive);
                    if (dist <= bestDist) {
                        u8 bc = bestCost;
                        cost = *(s16 *)((s32)*(s16 **)(map + 0x14190) + (t << 1));
                        if (cost < (s32)bc) {
                            bestDist = dist;
                            bestCost = (u8)cost;
                            bestX = (s16)x;
                            bestY = (s16)y;
                        }
                    }
                }
            }
        }
    }
skip:
    x += 1;
inner_cmp:
    if (x <= (s8)map2[0xA] - 1) {
        goto inner;
    }
    y += 1;
outer_cmp:
    if (y <= (s8)map2[0xB] - 1) {
        goto outer;
    }
    if ((u32)(bestDist - 0x7FFF0000) != 0xFFFFU) {
        s32 bx;
        s32 by;
        u8 *p;
        u8 tile;
        u8 v;
        bx = (s8)bestX;
        by = (s8)bestY;
        p = map + bx;
        v = ((u8 *)self)[0x198];
        p = (u8 *)((s32)p + (by << 6));
        tile = p[0xD];
        if (tile != v) {
            Ai_SetUnitMoveTo(self, bestX, bestY, 1, 0xFFFF, 0, 0, -1);
        }
    }
    return gAiState[0x21C];
}
#pragma use_lmw_stmw on
u8 Ai_TrySeekHealTerrain(void *arg0) {
    void Map_BuildUnitMoveRange(void *, s32, s32);
    s8 Unit_GetMov(void *);
    u8 Map_IsAiTerrainBlocked(s8, s8);
    void *Terrain_GetEntry(u8);
    s32 Map_CountNeighborUnits(s16, s16, void *);
    void Ai_SetUnitMoveTo(void *, s32, s32, s32, s32, s32, s32, s32);
    extern u8 gAiState[];
    extern u8 gBattleMap[151280];
    extern u8 Ai_UnitIsHostileToActive[];
    void *self;
    s8 bx;
    s8 by;
    s32 xShift;
    u8 *row;
    u8 *row2;
    s32 t;
    s32 bestDist;
    u8 bestCost;
    s16 best1;
    s16 best2;
    s32 xMin;
    s32 xMax;
    s32 yMax;
    s32 y;
    s32 x;
    u8 *map;
    u8 *map2;

    self = arg0;
    if ((gAiState[1] & 2) || (*(u32 *)((u8 *)self + 0x254) & 0x03000000)) {
        return 0;
    }
    map = gBattleMap;
    bestCost = 0xFF;
    bestDist = 0x7FFFFFFF;
    Map_BuildUnitMoveRange(self, 5, -1);
    bx = *(s8 *)((u8 *)self + 0x19E);
    by = *(s8 *)((u8 *)self + 0x19F);
    {
        s32 x0 = bx;
        s32 y0 = by;
        s8 range;
        s32 lim;
        s32 yMin;
        range = Unit_GetMov(self);
        xMin = x0 - range;
        if (xMin < (s8)gBattleMap[8]) {
            xMin = (s8)gBattleMap[8];
        }
        yMin = y0 - range;
        if (yMin < (s8)gBattleMap[9]) {
            yMin = (s8)gBattleMap[9];
        }
        xMax = x0 + range;
        lim = (s8)gBattleMap[0xA] - 1;
        if (xMax > lim) {
            xMax = lim;
        }
        yMax = y0 + range;
        lim = (s8)gBattleMap[0xB] - 1;
        if (yMax > lim) {
            yMax = lim;
        }
        y = yMin;
    }
    map2 = gBattleMap;
    goto outer_cmp;
outer:
    x = xMin;
    xShift = (s8)y << 6;
    row = map2 + xShift;
    row2 = map + xShift;
    goto inner_cmp;
inner:
    t = (s8)x + xShift;
    if (((s16 *)(map2 + 0x610E))[t] >= 0) {
        u8 *cell = row + (s8)x;
        if ((s8)cell[0xE18E] == 0 && Map_IsAiTerrainBlocked((s8)x, (s8)y) == 0 && cell[0xD] == 0) {
            void *tmp = Terrain_GetEntry(*(row2 + ((s8)x + 0x100D)));
            if (*(u8 *)(*(u8 **)((u8 *)tmp + 8) + 6) != 0) {
                s32 dist = Map_CountNeighborUnits((s16)x, (s16)y, Ai_UnitIsHostileToActive);
                if (dist <= bestDist) {
                    s16 cost = *(s16 *)((s32)*(s16 **)(map + 0x14190) + (t << 1));
                    if (cost < (s32)bestCost) {
                        bestDist = dist;
                        bestCost = (u8)cost;
                        best1 = (s16)x;
                        best2 = (s16)y;
                    }
                }
            }
        }
    }
    x += 1;
inner_cmp:
    if (x <= xMax) {
        goto inner;
    }
    y += 1;
outer_cmp:
    if (y <= yMax) {
        goto outer;
    }
    if ((u32)(bestDist - 0x7FFF0000) != 0xFFFFU) {
        s32 bx2;
        s32 by2;
        u8 *p;
        u8 tile;
        u8 v;
        bx2 = (s8)best1;
        by2 = (s8)best2;
        p = map + bx2;
        v = ((u8 *)self)[0x198];
        p = (u8 *)((s32)p + (by2 << 6));
        tile = p[0xD];
        if (tile != v) {
            Ai_SetUnitMoveTo(self, best1, best2, 1, 0xFFFF, 0, 0, -1);
        }
    }
    return gAiState[0x21C];
}
#pragma use_lmw_stmw reset

u8 Ai_TryEscapeMove(s32 unit) {
    /* Move unit to an escape tile; if it is the scripted escape point, commit escape action. */
    u8 Ai_FindEscapeTile(s32, s32, s16 *, s16 *);
    extern u8 gAiState[];
    extern u8 gUiContext[];
    s16 x;
    s16 y;

    if (Ai_FindEscapeTile(unit, 0, &x, &y) != 0) {
        Ai_SetUnitMoveTo(unit, x, y, 1, 0xFFFF, 1, 0, -1);
        if ((gAiState[0x21C] != 0)) {
            if ((x == (s8) gUiContext[0xD]) && (y == (s8) gUiContext[0xE])) {
                Ai_SetDecision(0x2C, 0, (s8) x, (s8) y, -1, 0, 0);
            }
        }
        return gAiState[0x21C];
    }
    return 0U;
}

#pragma use_lmw_stmw on
#pragma optimization_level 2
#pragma opt_strength_reduction off
u8 Ai_TrySeekHealer(void *arg0) {
    u8 fn_80092F38(void *);
    void fn_80022DAC(void *, s32, s32);
    void fn_80022FD8(void *, s32);
    void fn_800FE2A0(void *, s32, s32);
    void fn_8018D7A4(void *, void *);
    void fn_8002F658(void *, s32);
    void *fn_8002F740(void);
    void **fn_80037BD0(void *, s32);
    void *fn_80019E04(void *);
    s8 fn_8003B2D0(void *);
    s32 fn_80230BCC(s32);
    void fn_8010F3F4(void *, s8, s8, s16 *, s16 *);
    void fn_80094ABC(void *, void *);
    s32 fn_80093010(void *, void *);
    void fn_800FB96C(s32, s8, s8, void *, s8, s8, s8, s32, s32);
    void fn_800949A4(void *, s8);
    extern u8 lbl_802CA518[];
    extern u8 lbl_8032B3C0[];
    extern u8 lbl_802EF4E0[];
    extern u8 lbl_80273B40[];
    extern void fn_800FB60C(void);

    s16 sp12;
    void *grp;
    s8 slot;
    s8 rem;
    s32 sp8;
    int distB;
    int i;
    s16 sp10;
    s8 cur;
    u8 *tbl;
    s8 lo;
    register void **pick;
    void **other;
    s8 priA;
    void *key;
    register u8 *map;
    void *bestUnit;
    long distA;
    s8 bestSlot;
    s8 hi;
    void **bestItem;
    u8 t;
    void *p;
    void **cand;

    map = lbl_802CA518;
    if ((u8)fn_80092F38(arg0) >= 4U) {
        return 0U;
    }
    if ((lbl_8032B3C0[1] & 2) || (*(u32 *)((u8 *)arg0 + 0x254) & 0x03000000)) {
        fn_80022DAC(map, 5, -1);
        fn_80022FD8(map, 5);
        (*(s16 **)(map + 0x14190))[(s8)((u8 *)arg0)[0x19E] + ((s8)((u8 *)arg0)[0x19F] << 6)] = 0;
    } else {
        fn_800FE2A0(arg0, 5, -1);
    }
    fn_8018D7A4(arg0, fn_800FB60C);
    bestUnit = NULL;
    tbl = lbl_802EF4E0;
    bestItem = NULL;
    i = 0;
    while (i < *(s32 *)tbl) {
        fn_8002F658(tbl, i);
        grp = fn_8002F740();
        for (slot = 4; slot < 8; slot++) {
            p = *fn_80037BD0(grp, slot);
            if (p != NULL) {
                if (p != NULL) {
                    t = *(u8 *)((u8 *)p + 0x12);
                } else {
                    t = 0xC;
                }
                if (t == 0xA) {
                    if (p != NULL) {
                        t = *(u8 *)((u8 *)p + 0x14);
                    } else {
                        t = 0xC;
                    }
                    if (t == 0x81) {
                        cand = fn_80037BD0(grp, slot);
                        if (bestItem == NULL) {
                            bestUnit = grp;
                            bestSlot = slot;
                            bestItem = cand;
                        } else {
                            key = *(void **)cand;
                            other = bestItem;
                            pick = cand;
                            if (key == fn_80019E04(&lbl_80273B40[0x1D])) {
                                priA = 0xA;
                            } else if (key == fn_80019E04(&lbl_80273B40[0x2B])) {
                                priA = fn_8003B2D0(arg0);
                            } else {
                                priA = 0;
                            }
                            lo = priA;
                            key = *(void **)bestItem;
                            if (key == fn_80019E04((u8 *)lbl_80273B40 + 0x1D)) {
                                cur = 0xA;
                            } else if (key == fn_80019E04((u8 *)lbl_80273B40 + 0x2B)) {
                                cur = fn_8003B2D0(arg0);
                            } else {
                                cur = 0;
                            }
                            hi = cur;
                            if (priA != cur) {
                                if (priA > cur) {
                                    lo = cur;
                                    hi = priA;
                                    pick = bestItem;
                                    other = cand;
                                }
                                rem = (s8)(fn_8003B2D0(arg0) - ((u8 *)arg0)[0x1A8]);
                                distA = fn_80230BCC(rem - hi);
                                distB = fn_80230BCC(rem - lo);
                                pick = (distB > distA) ? other : pick;
                            } else {
                                t = *(u8 *)((u8 *)bestItem + 4);
                                if (*(u8 *)((u8 *)cand + 4) < t) {
                                    pick = cand;
                                } else if (*(u8 *)((u8 *)cand + 4) > t) {
                                    pick = bestItem;
                                } else {
                                    pick = cand;
                                }
                            }
                            if (pick != bestItem) {
                                bestUnit = grp;
                                bestSlot = slot;
                                bestItem = pick;
                            }
                        }
                    }
                }
            } else {
                break;
            }
        }
        i += 1;
    }
    if (bestUnit != NULL) {
        fn_8010F3F4(arg0, (s8)((u8 *)bestUnit)[0x19E], (s8)((u8 *)bestUnit)[0x19F], &sp12, &sp10);
        fn_80094ABC(arg0, bestItem);
        rem = (s8)fn_80093010(arg0, *bestItem);
        sp8 = 0;
        fn_800949A4(bestUnit, bestSlot);
        fn_800FB96C(0x34, (s8)sp12, (s8)sp10, arg0, (s8)sp12, (s8)sp10, rem, 0, 0);
    }
    return lbl_8032B3C0[0x21C];
}
#pragma optimization_level reset
#pragma use_lmw_stmw reset

#pragma optimization_level 2
#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
s32 Ai_TryUseHealItem(void *arg0) {
    void *Item_GetByIid(void *);
    void *Unit_GetItemSlot(void *, s32);
    s8 Unit_GetMaxHp(void *);
    void fn_800FB96C(s32, s8, s8, void *, s8, s8, s8, s32, s32);
    void fn_801025BC(void *, s16 *, s16 *);
    s32 Abs(s32);
    extern u8 lbl_80273B40[];
    extern u8 gAiState[];
    s16 sp12;
    s16 sp10;
    s32 sp8;
    s32 idx;
    s32 a;
    s8 temp;
    s8 valCur;
    void *chosen;
    s8 valBest;
    void *item;
    void *slot;
    u8 *p;
    void *best;
    s32 i;
    void *key;
    s32 vb;
    s32 vc;

    best = 0;
    i = 0;
    p = arg0;
loop:
    slot = p + 0x1EC;
    item = *(void **)slot;
    if (item == 0) {
        goto after_loop;
    }
    if (*(u8 *)((u8 *)item + 0x12) == 0xA && *(u8 *)((u8 *)item + 0x14) == 0x81) {
        if (best == 0) {
            best = slot;
        } else {
            key = *(void **)best;
            chosen = best;
            if (key == Item_GetByIid((u8 *)lbl_80273B40 + 0x1D)) {
                valBest = 0xA;
            } else if (key == Item_GetByIid(&lbl_80273B40[0x2B])) {
                valBest = Unit_GetMaxHp(arg0);
            } else {
                valBest = 0;
            }
            key = *(void **)slot;
            temp = valBest;
            if (key == Item_GetByIid(&lbl_80273B40[0x1D])) {
                valCur = 0xA;
            } else if (key == Item_GetByIid((u8 *)lbl_80273B40 + 0x2B)) {
                valCur = Unit_GetMaxHp(arg0);
            } else {
                valCur = 0;
            }
            vb = (s8)valBest;
            vc = (s8)valCur;
            if (vb != vc) {
                if (vb > vc) {
                    temp = valCur;
                    valCur = valBest;
                    chosen = slot;
                    slot = best;
                }
                valBest = (s8)(Unit_GetMaxHp(arg0) - ((u8 *)arg0)[0x1A8]);
                a = Abs((s8)(valBest - vc));
                if (Abs((s8)(valBest - (s8)temp)) > a) {
                    goto set_other;
                }
                goto after_dist;
            set_other:
                chosen = slot;
            after_dist:
                ;
            } else if (*(u8 *)((u8 *)best + 4) < *(u8 *)((u8 *)slot + 4)) {
                chosen = best;
            } else if (*(u8 *)((u8 *)best + 4) > *(u8 *)((u8 *)slot + 4)) {
                chosen = slot;
            } else {
                chosen = best;
            }
            best = chosen;
        }
    }
    i += 1;
    p += 8;
    if (i < 4) {
        goto loop;
    }
after_loop:
    if (best != 0) {
        for (idx = 4; idx < 8; idx++) {
            if (best == Unit_GetItemSlot(arg0, idx)) {
                break;
            }
        }
        sp12 = (s8)((u8 *)arg0)[0x19E];
        sp10 = (s8)((u8 *)arg0)[0x19F];
        if (!(gAiState[1] & 2) && !(*(u32 *)((u8 *)arg0 + 0x254) & 0x03000000)) {
            fn_801025BC(arg0, &sp12, &sp10);
        }
        sp8 = 0;
        fn_800FB96C(4, (s8)sp12, (s8)sp10, arg0, (s8)sp12, (s8)sp10, (s8)idx, 0, 0);
    }
    return best != 0;
}
#pragma opt_strength_reduction on
#pragma use_lmw_stmw reset
#pragma optimization_level reset

s32 Unit_HasLowHpAi(void *arg0) {
    void *Res_GetByName(s32);
    u8 fn_80102EA8();
    if (fn_80102EA8() != 0) {
        return 1;
    }
    return M2C_FIELD(Res_GetByName(M2C_FIELD(arg0, s32 *, 0x240)), u8 *, 7) != 0;
}

/* Latch and return whether unit HP is below the AI low-HP threshold (hysteresis via flag bit0). */
s32 Unit_IsLowHp(void *unit) {
    u8 fn_80102EA8(void);
    s8 Unit_GetMaxHp(void *);
    s32 __cvt_fp2unsigned(f32);
    void *Res_GetByName(void *);
    extern f64 lbl_8036A168;
    extern f32 sLowHpRatio;
    extern f32 sHpPercentScale;
    u8 curHp;
    s32 result;
    u32 percent;
    u32 flags;
    u8 *aiData;
    f32 ratio;

    if (fn_80102EA8() != 0) {
        curHp = *(u8 *)((u8 *)unit + 0x1A8);
        ratio = (f32)(s8)curHp / (f32)Unit_GetMaxHp(unit);
        if (ratio <= sLowHpRatio) {
            *(u32 *)((u8 *)unit + 0x254) |= 1;
            return 1;
        }
        *(u32 *)((u8 *)unit + 0x254) &= ~1U;
        return 0;
    }

    result = 0;
    {
        s8 maxHp = Unit_GetMaxHp(unit);
        s8 hp = (s8)*(u8 *)((u8 *)unit + 0x1A8);
        percent = __cvt_fp2unsigned((sHpPercentScale * (f32)hp) / (f32)maxHp);
    }
    aiData = Res_GetByName(*(void **)((u8 *)unit + 0x240));
    flags = *(u32 *)((u8 *)unit + 0x254);
    if (flags & 1) {
        if (aiData[6] <= percent) {
            *(u32 *)((u8 *)unit + 0x254) = flags & ~1U;
        } else {
            result = 1;
        }
    } else if (aiData[5] > percent) {
        result = 1;
        *(u32 *)((u8 *)unit + 0x254) = flags | 1;
    }
    return result;
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
s32 fn_8010C674(void *arg0, s32 arg1, u8 (*arg2)(void *)) {
    s32 fn_8001DD54(void *,void *);
    void fn_80022DAC(void *,s32,s32); void fn_80022FD8(void *,s32);
    void **fn_80037BBC(void *,s32);
    s8 fn_8003A398(void *); s8 fn_8003A778(void *);
    s32 fn_800F7838(void *,s16,s16); s32 fn_800F7994(void *,s16,s16);
    void fn_800FB96C(s32,s8,s8,void *,u8,u8,s8,s32,s32);
    u32 fn_800FCF48(s8,s8);
    void fn_800FE2A0(void *,s32,s32); void fn_80100D18(void *,void *,s32);
    extern u8 lbl_8032B3C0[],lbl_802CA518[];
    extern u16 lbl_802B14E4[];
    extern s16 lbl_80273B78[];
    u8 *flags=lbl_8032B3C0;
    u8 *map=lbl_802CA518;
    s16 bestX,bestY;
    void *best;
    s32 minX,maxX,maxY,row;
    s32 slot=arg1;
    s32 y,range,minY;
    void *item;
    u8 extra;
    s32 score;
    s32 k,bestScore;
    s16 ny,nx;
    void *unit;
    s16 *dir;
    u8 rank;
    s16 chosenX,chosenY;
    long x;
    if ((flags[1]&2) || (*(u32 *)((u8 *)arg0+0x254)&0x03000000)) {
        fn_80022DAC(map,5,-1); fn_80022FD8(map,5);
        (*(s16 **)(map+0x14190))[(s8)*((u8 *)arg0+0x19e)+((s8)*((u8 *)arg0+0x19f)<<6)]=0;
    } else fn_800FE2A0(arg0,5,-1);
    fn_80100D18(arg0,fn_80037BBC(arg0,slot),-1);
    x=*(s8 *)((u8 *)arg0+0x19e); y=*(s8 *)((u8 *)arg0+0x19f);
    best=NULL; rank=255;
    item=*fn_80037BBC(arg0,slot);
    if(item) extra=fn_8001DD54(item,arg0); else extra=0;
    range=fn_8003A398(arg0)+(u8)extra;
    minX=x-range; if(minX<(s8)lbl_802CA518[8]) minX=(s8)lbl_802CA518[8];
    minY=y-range; if(minY<(s8)lbl_802CA518[9]) minY=(s8)lbl_802CA518[9];
    maxX=x+range; if(maxX>(s8)lbl_802CA518[10]-1) maxX=(s8)lbl_802CA518[10]-1;
    maxY=y+range; if(maxY>(s8)lbl_802CA518[11]-1) maxY=(s8)lbl_802CA518[11]-1;
    for(row=minY;row<=maxY;row++) {
        for(x=minX;x<=maxX;x++) {
            u8 id=map[((s8)row<<6)+(s8)x+13];
            if(id && id!=*((u8 *)arg0+0x198)) {
                if(id) unit=(u8 *)lbl_802B14E4+(id-1)*0x280; else unit=NULL;
                if(!(flags[1]&4) && arg2 && arg2(unit)) continue;
                if((u8)rank<fn_8003A778(unit)) continue;
                {
                u8 *grid=lbl_802CA518;
                dir=lbl_80273B78; score=0; k=0; bestScore=0x80000000;
                do {
                    s32 index;
                    nx=(s16)x+dir[0]; ny=(s16)row+dir[1];
                    index=(s8)nx+((s8)ny<<6);
                    if((s16)(*(s16 **)(grid+0x14190))[index]>=0) {
                        u8 *p=grid+index;
                        if((s8)p[0xe18e]==0) {
                            u8 occupant=p[13];
                            if(occupant==0 || occupant==*((u8 *)arg0+0x198)) {
                                score+=fn_800F7994(arg0,nx,ny);
                                score+=fn_800F7838(arg0,nx,ny);
                                score-=(fn_800FCF48((s8)nx,(s8)ny)>>4)&0xfff;
                                if(bestScore<score) {chosenX=nx;chosenY=ny;bestScore=score;}
                            }
                        }
                    }
                    k += 1; score=0; dir+=2;
                } while(k<4);
                }
                if((u32)(bestScore+0x80000000)!=0) {
                    rank=fn_8003A778(unit);bestX=chosenX;bestY=chosenY;best=unit;
                }
            }
        }
    }
    if(best) {
        fn_800FB96C(16,(s8)bestX,(s8)bestY,best,*((u8 *)best+0x19e),*((u8 *)best+0x19f),(s8)slot,0,0);
    }
    return best!=NULL;
}
#pragma opt_strength_reduction reset

s32 fn_8010CA94(void) {
    return 0;
}

s32 fn_8010CA9C(void) {
    return 0;
}

s32 fn_8010CAA4(void) {
    return 0;
}

void fn_8010CAAC(void) {
    M2C_UNK fn_8010EA20();
    fn_8010EA20();
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
s32 fn_8010CACC(void *arg0, s32 arg1, u8 (*arg2)(void *)) {
    s32 Item_GetRangeForUnit(void *,void *);
    void Map_FillLayer(void *,s32,s32); void Map_SelectRangeBuffer(void *,s32);
    void **Unit_GetHeldItemSlot(void *,s32);
    s8 Unit_GetMov(void *); u8 fn_8003863C(void *); u8 fn_8010CF28(void *,void *,s16 *,s16 *);
    s32 fn_800F7838(void *,s16,s16); s32 fn_800F7994(void *,s16,s16);
    void fn_800FB96C(s32,s8,s8,void *,u8,u8,s8,s32,s32);
    u32 fn_800FCF48(s8,s8);
    void Map_BuildUnitMoveRange(void *,s32,s32); void fn_80100D18(void *,void *,s32);
    extern u8 gAiState[],gBattleMap[];
    extern u16 gUnits[];
    extern s16 lbl_80273B78[];
    u8 *map=gBattleMap;
    u8 *flags=gAiState;
    s16 bestX,bestY;
    void *best;
    s32 minX,maxY,row;
    s32 slot=arg1;
    s32 range,minY;
    s32 startX,startY;
    void *item;
    u8 extra;
    s32 k,score;
    s32 bestScore;
    s16 ny,nx;
    void *unit;
    s16 *dir;
    u8 *rowMap;
    u8 rank;
    s32 maxX;
    s16 chosenX,chosenY;
    s32 x;
    if ((flags[1]&2) || (*(u32 *)((u8 *)arg0+0x254)&0x03000000)) {
        Map_FillLayer(map,5,-1); Map_SelectRangeBuffer(map,5);
        (*(s16 **)(map+0x14190))[(s8)*((u8 *)arg0+0x19e)+((s8)*((u8 *)arg0+0x19f)<<6)]=0;
    } else Map_BuildUnitMoveRange(arg0,5,-1);
    fn_80100D18(arg0,Unit_GetHeldItemSlot(arg0,slot),-1);
    startX=*(s8 *)((u8 *)arg0+0x19e); startY=*(s8 *)((u8 *)arg0+0x19f);
    best=NULL; rank=0;
    item=*Unit_GetHeldItemSlot(arg0,slot);
    if(item) extra=Item_GetRangeForUnit(item,arg0); else extra=0;
    range=(s8)Unit_GetMov(arg0); range+=(u8)extra;
    minX=startX-range; if(minX<(s8)gBattleMap[8]) minX=(s8)gBattleMap[8];
    minY=startY-range; if(minY<(s8)gBattleMap[9]) minY=(s8)gBattleMap[9];
    maxX=startX+range; if(maxX>(s8)gBattleMap[10]-1) maxX=(s8)gBattleMap[10]-1;
    maxY=startY+range; if(maxY>(s8)gBattleMap[11]-1) maxY=(s8)gBattleMap[11]-1;
    for(row=minY;maxY>=row;++row) {
        rowMap=map+((s8)row<<6);
        for(x=minX;x<=maxX;x++) {
            u8 id=rowMap[(s8)x+13];
            if(id && id!=*((u8 *)arg0+0x198)) {
                if(id) unit=(u8 *)gUnits+(id-1)*0x280; else unit=NULL;
                if((*(u32 *)((u8 *)unit+0x1a0)&1)!=0) continue;
                if(!(flags[1]&4) && arg2 && arg2(unit)) continue;
                if((*(u32 *)((u8 *)unit+0x254)&9)!=0) continue;
                if((u8)rank>fn_8003863C(unit)) continue;
                {
                u8 *grid=gBattleMap;
                score=0; dir=lbl_80273B78; k=score; bestScore=0x80000000;
                do {
                    s32 index;
                    s16 *heightTable;
                    nx=(s16)x+dir[0];
                    heightTable=*(s16 **)(grid+0x14190);
                    ny=(s16)row+dir[1];
                    index=(s8)nx+((s8)ny<<6);
                    if((s16)heightTable[index]>=0) {
                        u8 *p=grid+index;
                        if((s8)p[0xe18e]==0) {
                            u8 occupant=p[13];
                            if(occupant==0 || occupant==*((u8 *)arg0+0x198)) {
                                score+=fn_800F7994(arg0,nx,ny);
                                score+=fn_800F7838(arg0,nx,ny);
                                score-=(fn_800FCF48((s8)nx,(s8)ny)>>4)&0xfff;
                                if(bestScore<score) {chosenX=nx;chosenY=ny;bestScore=score;}
                            }
                        }
                    }
                    ++k; score=0; dir+=2;
                } while(k<4);
                }
                if((u32)(bestScore+0x80000000)!=0) {
                    rank=fn_8003863C(unit);bestX=chosenX;bestY=chosenY;best=unit;
                }
            }
        }
    }
    if(best) {
        if(fn_8010CF28(arg0,best,&chosenX,&chosenY)==1) {
            fn_800FB96C(16,(s8)bestX,(s8)bestY,best,*((u8 *)best+0x19e),*((u8 *)best+0x19f),(s8)slot,(u8)chosenX,(u8)chosenY);
        } else best=NULL;
    }
    return best!=NULL;
}
#pragma opt_strength_reduction reset

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
s32 fn_8010CF28(s32 arg0, void *arg1, s16 *arg2, s16 *arg3) {
void Allegiance_FillMask(s32,void *);
u8 Allegiance_Compare(void *,void *); u8 fn_8001DD04(s32);
void fn_800FC6B0(void *);
u16 fn_800FCF48(s8,s8);
void fn_800FCF74(s32,s32); void fn_800FD774(s32);
void Map_BuildUnitMoveRange(void *,s32,s32);
void fn_800FE490(s8,s8,void *,s32,s32); u8 Map_IsAiTerrainBlocked(s8,s8);
extern u8 gBattleMap[]; extern u16 gUnits[];

    u8 sp8[8];
    s16 temp_r3_3;
    s32 temp_cr0_eq;
    void *var_r27;
    s32 temp_r21;
    s32 temp_r22;
    s32 temp_r23;
    s32 var_r0;
    s32 var_r4;
    s32 var_r16_2;
    void *var_r20;
    s32 var_r21;
    s32 var_r17;
    s32 var_r17_2;
    s32 var_r18_2;
    u16 temp_r3_4;
    u16 var_r16;
    u8 temp_r24_2;
    u8 temp_r3;
    u8 temp_r3_2;
    u8 temp_r4;
    u8 temp_r4_2;
    u8 temp_r5;
    u8 var_r19;
    u8 var_r7;
    void *temp_r19;
    void *temp_r24;
    void *var_r18;
    void *var_r24;

    u8 *map=gBattleMap;
    fn_800FC6B0(*(void **)((u8 *)arg1+0x190));
    var_r20 = NULL;
    Allegiance_FillMask(0, &sp8);
    var_r21 = 1;
    do {
        if ((u8)var_r21 != 0) {
            var_r27 = (u8 *)gUnits + (((u8)var_r21 - 1) * 0x280);
        } else {
            var_r27 = NULL;
        }
        if (((u32) *(u32 *)((u8 *)var_r27+0x188) != 0U) && (sp8[(*(u8 **)((u8 *)var_r27+0x190))[8]] != 0)) {
            temp_r3 = *(u8 *)((u8 *)var_r27+0x19E);
            var_r7 = 0;
            temp_r4 = *(u8 *)((u8 *)var_r27+0x19F);
            if (((s8) temp_r3 < (s8) *(s8 *)(gBattleMap+0x8)) || ((s32) ((s8) *(s8 *)(gBattleMap+0xA) - 1) < (s8) temp_r3) || ((s8) temp_r4 < (s8) *(s8 *)(gBattleMap+0x9)) || ((s32) ((s8) *(s8 *)(gBattleMap+0xB) - 1) < (s8) temp_r4)) {
                var_r7 = 1;
            }
            if ((var_r7 == 0) && !(*(u32 *)((u8 *)var_r27+0x1A0) & 0x010000DC) && (fn_800FCF48((s8)temp_r3,(s8)temp_r4) > 0U)) {
                var_r20 = var_r27;
            }
        }
        var_r21 += 1;
    } while ((s32) var_r21 <= 0x9F);
    if (var_r20 == NULL) {
        fn_800FD774(arg0);
        fn_800FCF74(arg0, 0x9F);
        return 0;
    }
    Map_BuildUnitMoveRange(var_r20, 6, *(s32 *)gBattleMap * *(s32 *)(gBattleMap+4));
    var_r19 = 0xFF;
    var_r17 = (s8) *(s8 *)(gBattleMap+0x9);
    var_r18 = NULL;
for (; var_r17 <= (s32) ((s8) *(s8 *)(gBattleMap+0xB) - 1); var_r17++) {
        temp_r23 = (s8)var_r17 << 6;
        var_r16_2 = (s8) *(s8 *)(gBattleMap+0x8);
for (; var_r16_2 <= (s32) ((s8) *(s8 *)(gBattleMap+0xA) - 1); var_r16_2++) {
            temp_r21 = ((s8)var_r16_2 + temp_r23) * 2;
            if (*(s16 *)(gBattleMap+temp_r21+0x818e) >= 0) {
                temp_r24 = gBattleMap + temp_r23 + (s8)var_r16_2;
                if ((*(s8 *)((u8 *)temp_r24+0xe18e) == 0) && (Map_IsAiTerrainBlocked((s8)var_r16_2,(s8)var_r17) == 0)) {
                    temp_r3_2 = *(u8 *)((u8 *)temp_r24+13);
                    if (temp_r3_2 != 0) {
                        if (temp_r3_2 != 0) {
                            var_r24 = (u8 *)gUnits + ((temp_r3_2 - 1) * 0x280);
                        } else {
                            var_r24 = NULL;
                        }
                        if (fn_8010CF28_check(*(void **)((u8 *)var_r20+0x190), *(void **)((u8 *)var_r24+0x190)) != 0) {
                            temp_r3_3 = *(s16 *)(map + (temp_r21 + 0x818E));
                            if (temp_r3_3 < (s32) var_r19) {
                                var_r19 = (u8) temp_r3_3;
                                var_r18 = var_r24;
                            }
                        }
                    }
                }
            }
        }
    }
    if (var_r18 == NULL) {
        fn_800FD774(arg0);
        fn_800FCF74(arg0, 0x9F);
        return 0;
    }
    fn_800FE490((s8) *(u8 *)((u8 *)var_r18+0x19E), (s8) *(u8 *)((u8 *)var_r18+0x19F), arg1, 6, -1);
    var_r16 = 0xFFFF;
    temp_r24_2 = fn_8001DD04(arg0);
    var_r17_2 = (s8) *(s8 *)(gBattleMap+0x9);
for (; var_r17_2 <= (s32) ((s8) *(s8 *)(gBattleMap+0xB) - 1); var_r17_2++) {
        temp_r22 = (s8)var_r17_2 << 6;
        var_r18_2 = (s8) *(s8 *)(gBattleMap+0x8);
for (; var_r18_2 <= (s32) ((s8) *(s8 *)(gBattleMap+0xA) - 1); var_r18_2++) {
            if (*(s16 *)(gBattleMap+((s8)var_r18_2+temp_r22)*2+0x818e) >= 0) {
                temp_r19 = gBattleMap + temp_r22 + (s8)var_r18_2;
                if ((*(s8 *)((u8 *)temp_r19+0xe18e) == 0) && (Map_IsAiTerrainBlocked((s8)var_r18_2,(s8)var_r17_2) == 0) && ((u8) *(u8 *)((u8 *)temp_r19+13) == 0)) {
                    temp_r3_4 = fn_800FCF48(var_r18_2, var_r17_2);
                    temp_r4_2 = *(u8 *)((u8 *)arg1+0x19f);
                    var_r4 = (s8) temp_r4_2 - var_r17_2;
                    if (((s8) temp_r4_2 - var_r17_2) < 0) {
                        var_r4 = -var_r4;
                    }
                    temp_r5 = *(u8 *)((u8 *)arg1+0x19e);
                    var_r0 = (s8) temp_r5 - var_r18_2;
                    if (((s8) temp_r5 - var_r18_2) < 0) {
                        var_r0 = -var_r0;
                    }
                    if (((s32) temp_r24_2 >= (s16) (var_r0 + var_r4)) && (temp_r3_4 < var_r16)) {
                        *arg2 = (s16) var_r18_2;
                        var_r16 = temp_r3_4;
                        *arg3 = (s16) var_r17_2;
                    }
                }
            }
        }
    }
    fn_800FD774(arg0);
    fn_800FCF74(arg0, 0x9F);
    return var_r16 != 0xFFFF;
}
#pragma opt_strength_reduction reset

void fn_8010D364(void) {
    M2C_UNK fn_8010D384();
    fn_8010D384();
}

#pragma use_lmw_stmw on
s32 fn_8010D384(void *arg0, s32 arg1, u8 (*arg2)(void *)) {
    s32 fn_8001DD54(void *, void *);
    void fn_80022DAC(void *, s32, s32);
    void fn_80022FD8(void *, s32);
    void **fn_80037BBC(void *, s32);
    s8 fn_80037E00(void *);
    u8 fn_8003863C(void *);
    s8 fn_8003A398(void *);
    s8 fn_8003CFF0(void *, void *);
    u8 fn_800934CC(void *);
    s32 fn_800F7838(void *, s8, s8);
    s32 fn_800F7994(void *, s8, s8);
    void fn_800FB96C(s32, s8, s8, void *, u8, u8, s8, s32, s32);
    u32 fn_800FCF48(s8, s8);
    void fn_800FDDBC(s8, s8, u8, u8, s32);
    void fn_800FE2A0(void *, s32, s32);
    u8 fn_800FE84C(s8, s8);
    void fn_80100D18(void *, void *, s32);
    u8 fn_801044FC(void *);
    void fn_801A49AC(void *, s8);
    void fn_801A7A68(void *, void *, void *);
    extern u8 lbl_8032B3C0[];
    extern u8 lbl_802CA518[];
    extern u16 lbl_802B14E4[];
    extern AiParam lbl_80273BB8;
    extern AiParam lbl_80273BA8;
    extern u8 lbl_80330EAC[];

    AiParam sp28;
    AiParam sp18;
    u8 *flags;
    u8 *map;
    s32 slot;
    void **weapon;
    void *best;
    s16 bestY;
    s16 bestX;
    u8 bestRank;
    s32 minX;
    s32 maxX;
    s32 maxY;
    s32 row;
    s32 minY;
    u8 *map9;
    long x;
    s32 y;
    u8 extra;
    s32 range;
    void *item;
    void *unit;
    s32 score;
    s32 bestScore;
    s32 i;
    s16 chosenX;
    s16 chosenY;
    u8 *pMaxX;
    u8 *map11;
    s8 iy;
    s8 ix;

    flags = lbl_8032B3C0;
    map = lbl_802CA518;
    slot = arg1;

    if ((flags[1] & 2) || (*(u32 *)((u8 *)arg0 + 0x254) & 0x03000000)) {
        fn_80022DAC(map, 5, -1);
        fn_80022FD8(map, 5);
        (*(s16 **)(map + 0x14190))[(s8)*((u8 *)arg0 + 0x19e) + ((s8)*((u8 *)arg0 + 0x19f) << 6)] = 0;
    } else {
        fn_800FE2A0(arg0, 5, -1);
    }

    weapon = fn_80037BBC(arg0, slot);
    fn_80100D18(arg0, weapon, -1);
    bestRank = 0;
    best = NULL;
    x = *(s8 *)((u8 *)arg0 + 0x19e);
    y = *(s8 *)((u8 *)arg0 + 0x19f);
    item = *weapon;
    if (item) {
        extra = fn_8001DD54(item, arg0);
    } else {
        extra = 0;
    }
    range = (s8)fn_8003A398(arg0);
    range += (u8)extra;

    minX = x - range;
    if (minX < (s8)lbl_802CA518[8]) {
        minX = (s8)lbl_802CA518[8];
    }
    minY = y - range;
    map9 = lbl_802CA518;
    if (minY < (s8)map9[9]) {
        minY = (s8)map9[9];
    }
    maxX = x + range;
    pMaxX = &lbl_802CA518[10];
    if (maxX > (s8)*pMaxX - 1) {
        maxX = (s8)*pMaxX - 1;
    }
    maxY = y + range;
    map11 = lbl_802CA518;
    if (maxY > (s8)map11[11] - 1) {
        maxY = (s8)map11[11] - 1;
    }

    for (row = minY; row <= maxY; row++) {
        for (x = minX; x <= maxX; x++) {
            u8 id = map[((s8)row << 6) + (s8)x + 0xD];
            u8 ok;
            u8 wextra, wrange;
            s8 ciff;

            if (id == 0 || id == *((u8 *)arg0 + 0x198)) {
                continue;
            }
            if (id != 0) {
                unit = (u8 *)lbl_802B14E4 + (id - 1) * 0x280;
            } else {
                unit = NULL;
            }
            if (!(flags[1] & 4) && arg2 != NULL && arg2(unit) == 0) {
                continue;
            }
            if (fn_801044FC((u8 *)unit + 0x1a4) == 1) {
                continue;
            }

            for (i = 0; i < 4; i++) {
                if (*fn_80037BBC(unit, i) != NULL) {
                    if (fn_800934CC(unit) != 0) {
                        ok = 1;
                        goto ok_done;
                    }
                }
            }
            ok = 0;
ok_done:
            if (ok == 0) {
                continue;
            }

            item = *weapon;
            if (item != NULL) {
                wextra = fn_8001DD54(item, arg0);
            } else {
                wextra = 0;
            }
            item = *weapon;
            if (item != NULL) {
                wrange = *((u8 *)item + 0x1d);
            } else {
                wrange = 0;
            }
            fn_800FDDBC((s8)*((u8 *)unit + 0x19e), (s8)*((u8 *)unit + 0x19f), wrange, wextra, 6);

            {
                u8 *grid = lbl_802CA518;
                u8 *grid2 = lbl_802CA518;
                bestScore = 0x80000000;
                for (iy = (s8)map9[9]; iy <= (s8)map11[11] - 1; iy++) {
                    s32 yoff = (s8)iy << 6;
                    u8 *rowY = grid + yoff;
                    u8 *rowY2 = grid2 + yoff;
                    for (ix = (s8)lbl_802CA518[8]; ix <= (s8)*pMaxX - 1; ix++) {
                        s32 t = (s8)ix + yoff;
                        s32 t2 = t * 2;
                        if (*(s16 *)(grid + t2 + 0x610e) >= 0
                            && (s8)rowY[(s32)ix + 0xe18e] == 0
                            && fn_800FE84C(ix, iy) == 0
                            && *(u16 *)(grid2 + t2 + 0xc18e) != 0) {
                            u8 occ = rowY2[(s8)ix + 0xd];
                            if (occ == 0 || occ == *((u8 *)arg0 + 0x198)) {
                                score = fn_800F7994(arg0, ix, iy);
                                score += fn_800F7838(arg0, ix, iy);
                                score -= (fn_800FCF48(ix, iy) >> 4) & 0xfff;
                                if (bestScore < score) {
                                    bestScore = score;
                                    chosenX = (s16)ix;
                                    chosenY = (s16)iy;
                                }
                            }
                        }
                    }
                }
            }

            if ((u32)(bestScore + 0x80000000) == 0) {
                continue;
            }

            sp18 = lbl_80273BB8;
            sp18.p = unit;
            sp18.b4 = *((u8 *)unit + 0x19e);
            sp18.b5 = *((u8 *)unit + 0x19f);
            sp18.b6 = fn_80037E00(unit);
            sp28 = lbl_80273BA8;
            sp28.p = arg0;
            sp28.b4 = (u8)(s8)chosenX;
            sp28.b5 = (u8)(s8)chosenY;
            fn_801A7A68(lbl_80330EAC, &sp28, &sp18);
            fn_801A49AC(lbl_80330EAC, (s8)slot);

            ciff = fn_8003CFF0(arg0, unit);
            if (ciff < 5) {
                continue;
            }
            if ((s32)bestRank > (s32)(ciff + fn_8003863C(unit))) {
                continue;
            }
            bestRank = (u8)(ciff + fn_8003863C(unit));
            bestX = chosenX;
            bestY = chosenY;
            best = unit;
        }
    }

    if (best != NULL) {
        fn_800FB96C(0x10, (s8)bestX, (s8)bestY, best,
                    *((u8 *)best + 0x19e), *((u8 *)best + 0x19f), (s8)slot, 0, 0);
    }
    return best != NULL;
}

#pragma use_lmw_stmw on
s32 fn_8010D984(void *arg0, s32 arg1, u8 (*arg2)(void *)) {
    s32 Item_GetRangeForUnit(void *, void *);
    void Map_FillLayer(void *, s32, s32);
    void Map_SelectRangeBuffer(void *, s32);
    void **Unit_GetHeldItemSlot(void *, s32);
    s8 Unit_GetActiveItemSlot(void *);
    s8 Unit_GetMov(void *);
    s8 Unit_GetMagAtk(void *);
    s8 Unit_CalcHitRate(void *, void *);
    u8 fn_800934CC(void *, void *);
    u64 *Item_GetFlagsPtr(void *);
    s32 fn_800F7838(void *, s8, s8);
    s32 fn_800F7994(void *, s8, s8);
    void fn_800FB96C(s32, s8, s8, void *, u8, u8, s8, s32, s32);
    u32 fn_800FCF48(s8, s8);
    void fn_800FDDBC(s8, s8, u8, u8, s32);
    void Map_BuildUnitMoveRange(void *, s32, s32);
    u8 Map_IsAiTerrainBlocked(s8, s8);
    void fn_80100D18(void *, void *, s32);
    void Battle_SelectWeapon(void *, s8);
    void Battle_SetupFromParams(void *, void *, void *);
    extern u8 gAiState[];
    extern u8 gBattleMap[];
    extern u16 gUnits[];
    extern AiParam lbl_80273B98;
    extern AiParam lbl_80273B88;
    extern u8 gBattle[];

    AiParam sp28;
    AiParam sp18;
    u8 *flags;
    u8 *map;
    s32 slot;
    void **weapon;
    u8 bestRank;
    void *best;
    s16 bestY;
    s16 bestX;
    s32 minX;
    s32 maxX;
    s32 maxY;
    s32 row;
    s32 minY;
    u8 *map9;
    long x;
    s32 y;
    u8 extra;
    s32 range;
    void *item;
    void *unit;
    s32 score;
    s32 bestScore;
    s32 i;
    s16 chosenX;
    s16 chosenY;
    u8 *pMaxX;
    u8 *map11;
    s8 iy;
    s8 ix;

    flags = gAiState;
    map = gBattleMap;
    slot = arg1;

    if ((flags[1] & 2) || (*(u32 *)((u8 *)arg0 + 0x254) & 0x03000000)) {
        Map_FillLayer(map, 5, -1);
        Map_SelectRangeBuffer(map, 5);
        (*(s16 **)(map + 0x14190))[(s8)*((u8 *)arg0 + 0x19e) + ((s8)*((u8 *)arg0 + 0x19f) << 6)] = 0;
    } else {
        Map_BuildUnitMoveRange(arg0, 5, -1);
    }

    weapon = Unit_GetHeldItemSlot(arg0, slot);
    fn_80100D18(arg0, weapon, -1);
    bestRank = 0;
    best = NULL;
    x = *(s8 *)((u8 *)arg0 + 0x19e);
    y = *(s8 *)((u8 *)arg0 + 0x19f);
    item = *weapon;
    if (item) {
        extra = Item_GetRangeForUnit(item, arg0);
    } else {
        extra = 0;
    }
    range = (s8)Unit_GetMov(arg0);
    range += (u8)extra;

    minX = x - range;
    if (minX < (s8)gBattleMap[8]) {
        minX = (s8)gBattleMap[8];
    }
    minY = y - range;
    map9 = gBattleMap;
    if (minY < (s8)map9[9]) {
        minY = (s8)map9[9];
    }
    maxX = x + range;
    pMaxX = &gBattleMap[10];
    if (maxX > (s8)*pMaxX - 1) {
        maxX = (s8)*pMaxX - 1;
    }
    maxY = y + range;
    map11 = gBattleMap;
    if (maxY > (s8)map11[11] - 1) {
        maxY = (s8)map11[11] - 1;
    }

    for (row = minY; row <= maxY; row++) {
        for (x = minX; x <= maxX; x++) {
            u8 id = map[((s8)row << 6) + (s8)x + 0xD];
            u8 ok;
            u8 wextra, wrange;
            s8 ciff;

            if (id == 0 || id == *((u8 *)arg0 + 0x198)) {
                continue;
            }
            if (id != 0) {
                unit = (u8 *)gUnits + (id - 1) * 0x280;
            } else {
                unit = NULL;
            }
            if (!(flags[1] & 4) && arg2 != NULL && arg2(unit) == 0) {
                continue;
            }
            if (((*((u8 *)unit + 0x1A5) >> 4) & 7) != 0) {
                continue;
            }
            if ((*(u16 *)((u8 *)*(void **)((u8 *)unit + 0x18C) + 0x3A) & 1) == 0) {
                continue;
            }

            for (i = 0; i < 4; i++) {
                void **sp = Unit_GetHeldItemSlot(unit, i);
                if (*sp != NULL) {
                    if ((*Item_GetFlagsPtr(sp) & 6ULL) != 0 && fn_800934CC(unit, *sp) != 0) {
                        ok = 1;
                        goto ok_done;
                    }
                }
            }
            ok = 0;
ok_done:
            if (ok == 0) {
                continue;
            }

            item = *weapon;
            if (item != NULL) {
                wextra = Item_GetRangeForUnit(item, arg0);
            } else {
                wextra = 0;
            }
            item = *weapon;
            if (item != NULL) {
                wrange = *((u8 *)item + 0x1d);
            } else {
                wrange = 0;
            }
            fn_800FDDBC((s8)*((u8 *)unit + 0x19e), (s8)*((u8 *)unit + 0x19f), wrange, wextra, 6);

            {
                u8 *grid = gBattleMap;
                u8 *grid2 = gBattleMap;
                bestScore = 0x80000000;
                for (iy = (s8)map9[9]; iy <= (s8)map11[11] - 1; iy++) {
                    s32 yoff = (s8)iy << 6;
                    u8 *rowY = grid + yoff;
                    u8 *rowY2 = grid2 + yoff;
                    for (ix = (s8)gBattleMap[8]; ix <= (s8)*pMaxX - 1; ix++) {
                        s32 t = (s8)ix + yoff;
                        s32 t2 = t * 2;
                        if (*(s16 *)(grid + t2 + 0x610e) >= 0
                            && (s8)rowY[(s32)ix + 0xe18e] == 0
                            && Map_IsAiTerrainBlocked(ix, iy) == 0
                            && *(u16 *)(grid2 + t2 + 0xc18e) != 0) {
                            u8 occ = rowY2[(s8)ix + 0xd];
                            if (occ == 0 || occ == *((u8 *)arg0 + 0x198)) {
                                score = fn_800F7994(arg0, ix, iy);
                                score += fn_800F7838(arg0, ix, iy);
                                score -= (fn_800FCF48(ix, iy) >> 4) & 0xfff;
                                if (bestScore < score) {
                                    bestScore = score;
                                    chosenX = (s16)ix;
                                    chosenY = (s16)iy;
                                }
                            }
                        }
                    }
                }
            }

            if ((u32)(bestScore + 0x80000000) == 0) {
                continue;
            }

            sp18 = lbl_80273B98;
            sp18.p = unit;
            sp18.b4 = *((u8 *)unit + 0x19e);
            sp18.b5 = *((u8 *)unit + 0x19f);
            sp18.b6 = Unit_GetActiveItemSlot(unit);
            sp28 = lbl_80273B88;
            sp28.p = arg0;
            sp28.b4 = (u8)(s8)chosenX;
            sp28.b5 = (u8)(s8)chosenY;
            Battle_SetupFromParams(gBattle, &sp28, &sp18);
            Battle_SelectWeapon(gBattle, (s8)slot);

            ciff = Unit_CalcHitRate(arg0, unit);
            if (ciff < 5) {
                continue;
            }
            if ((s32)bestRank > (s32)(ciff + Unit_GetMagAtk(unit))) {
                continue;
            }
            bestRank = (u8)(ciff + Unit_GetMagAtk(unit));
            bestX = chosenX;
            bestY = chosenY;
            best = unit;
        }
    }

    if (best != NULL) {
        fn_800FB96C(0x10, (s8)bestX, (s8)bestY, best,
                    *((u8 *)best + 0x19e), *((u8 *)best + 0x19f), (s8)slot, 0, 0);
    }
    return best != NULL;
}
#pragma use_lmw_stmw reset

#pragma opt_propagation off
s32 fn_8010DFC0(void *arg0, s32 arg1, u8 (*arg2)(void *)) {
    s32 fn_8001DD54(void *,void *);
    void fn_80022DAC(void *,s32,s32); void fn_80022FD8(void *,s32);
    void **fn_80037BBC(void *,s32);
    s8 fn_8003A398(void *); u8 fn_8003863C(void *); u8 fn_801044FC(void *);
    s32 fn_800F7838(void *,s16,s16); s32 fn_800F7994(void *,s16,s16);
    void fn_800FB96C(s32,s8,s8,void *,u8,u8,s8,s32,s32);
    u32 fn_800FCF48(s8,s8);
    void fn_800FE2A0(void *,s32,s32); void fn_80100D18(void *,void *,s32);
    extern u8 lbl_8032B3C0[],lbl_802CA518[];
    extern u16 lbl_802B14E4[];
    extern s16 lbl_80273B78[];
    u8 *flags=lbl_8032B3C0;
    u8 *map=lbl_802CA518;
    s16 bestX,bestY;
    void *best;
    s32 minX,maxX,maxY,row;
    s32 slot=arg1;
    s32 range,minY;
    s32 startX,startY;
    void *item;
    u8 extra;
    s32 k,score;
    s32 bestScore;
    s16 ny,nx;
    void *unit;
    s16 *dir;
    u8 rank;
    s16 chosenX,chosenY;
    s32 x;
    if ((flags[1]&2) || (*(u32 *)((u8 *)arg0+0x254)&0x03000000)) {
        fn_80022DAC(map,5,-1); fn_80022FD8(map,5);
        (*(s16 **)(map+0x14190))[(s8)*((u8 *)arg0+0x19e)+((s8)*((u8 *)arg0+0x19f)<<6)]=0;
    } else fn_800FE2A0(arg0,5,-1);
    fn_80100D18(arg0,fn_80037BBC(arg0,slot),-1);
    startX=*(s8 *)((u8 *)arg0+0x19e); startY=*(s8 *)((u8 *)arg0+0x19f);
    best=NULL; rank=0;
    item=*fn_80037BBC(arg0,slot);
    if(item) extra=fn_8001DD54(item,arg0); else extra=0;
    range=(s8)fn_8003A398(arg0); range+=(u8)extra;
    minX=startX-range; if(minX<(s8)lbl_802CA518[8]) minX=(s8)lbl_802CA518[8];
    minY=startY-range; if(minY<(s8)lbl_802CA518[9]) minY=(s8)lbl_802CA518[9];
    maxX=startX+range; if(maxX>(s8)lbl_802CA518[10]-1) maxX=(s8)lbl_802CA518[10]-1;
    maxY=startY+range; if(maxY>(s8)lbl_802CA518[11]-1) maxY=(s8)lbl_802CA518[11]-1;
    for(row=minY;row<=maxY;row++) {
        for(x=minX;x<=maxX;x++) {
            u8 id=map[((s8)row<<6)+(s8)x+13];
            if(id && id!=*((u8 *)arg0+0x198)) {
                if(id) unit=(u8 *)lbl_802B14E4+(id-1)*0x280; else unit=NULL;
                if(!(flags[1]&4) && arg2 && arg2(unit)) continue;
                if(!fn_801044FC((u8 *)unit+0x1a4)) continue;
                if((u8)rank>fn_8003863C(unit)) continue;
                {
                u8 *grid=lbl_802CA518;
                score=0; dir=lbl_80273B78; k=score; bestScore=0x80000000;
                do {
                    s32 index;
                    nx=(s16)x+dir[0]; ny=(s16)row+dir[1];
                    index=(s8)nx+((s8)ny<<6);
                    if((s16)(*(s16 **)(grid+0x14190))[index]>=0) {
                        u8 *p=grid+index;
                        if((s8)p[0xe18e]==0) {
                            u8 occupant=p[13];
                            if(occupant==0 || occupant==*((u8 *)arg0+0x198)) {
                                score+=fn_800F7994(arg0,nx,ny);
                                score+=fn_800F7838(arg0,nx,ny);
                                score-=(fn_800FCF48((s8)nx,(s8)ny)>>4)&0xfff;
                                if(bestScore<score) {chosenX=nx;chosenY=ny;bestScore=score;}
                            }
                        }
                    }
                    ++k; score=0; dir+=2;
                } while(k<4);
                }
                if((u32)(bestScore+0x80000000)!=0) {
                    rank=fn_8003863C(unit);bestX=chosenX;bestY=chosenY;best=unit;
                }
            }
        }
    }
    if(best) {
        fn_800FB96C(16,(s8)bestX,(s8)bestY,best,*((u8 *)best+0x19e),*((u8 *)best+0x19f),(s8)slot,0,0);
    }
    return best!=NULL;
}

#pragma use_lmw_stmw on
u32 fn_8010E3F0(void *arg0, s32 arg1) {
    u8 Allegiance_Compare(s32, s32);
    u8 Item_GetRangeForUnit(void *);
    void Map_FillLayer(void *, s32, s32);
    void Map_SelectRangeBuffer(void *, s32);
    void *Unit_GetHeldItemSlot(void *, s32);
    s8 Unit_GetMov(void *);
    s32 fn_800F7838(void *, s16, s16);
    s32 fn_800F7994(void *, s16, s16);
    void fn_800FB96C(s32, s8, s8, s32, s8, s8, s8, s32);
    u32 fn_800FCF48(s8, s8);
    void Map_BuildUnitMoveRange(void *, s32, s32);
    u8 Map_IsAiTerrainBlocked(s8, s8);
    s32 fn_8010E804(void *, s16, s16, s32, u8);
    extern u8 gAiState[];
    extern u8 gBattleMap[151280];
    extern u16 gUnits[];

    s32 sp14;
    s32 sp8;
    s32 sp10;
    s16 bestY;
    s16 bestX;
    s32 bestScore;
    void *list;
    s8 range;
    s32 yMax;
    s32 xMax;
    s8 yCur;
    s32 xCur;
    s32 rowOff;
    u8 *row;
    u8 id;
    u8 ok;
    s32 score;
    s32 a;
    s32 b;
    s8 y;
    s8 x;
    s32 count;
    void *other;
    u8 *mapBase;
    void *self;
    u8 *map;
    u8 *flags;
    s32 *pSp10;

    flags = gAiState;
    map = gBattleMap;
    self = arg0;
    sp10 = arg1;
    pSp10 = &sp10;
    mapBase = map;
    if ((flags[1] & 4) != 0) {
        return 0;
    }
    count = 0;
    for (y = (s8)map[9]; y <= (s8)map[0xB] - 1; y++) {
        row = map + ((s8)y << 6);
        for (x = (s8)map[8]; x <= (s8)map[0xA] - 1; x++) {
            id = row[(s8)x + 0xD];
            if (id != 0) {
                if (id != 0) {
                    other = (u8 *)gUnits + (id - 1) * 0x280;
                } else {
                    other = NULL;
                }
                if ((Allegiance_Compare(*(s32 *)((u8 *)self + 0x190), *(s32 *)((u8 *)other + 0x190)) != 1)
                    && ((*(u32 *)((u8 *)other + 0x254) & 1) != 0)) {
                    count += 1;
                }
            }
        }
    }
    if (count < 3) {
        return 0;
    }
    if (((flags[1] & 2) != 0) || ((*(u32 *)((u8 *)self + 0x254) & 0x03000000) != 0)) {
        Map_FillLayer(mapBase, 5, -1);
        Map_SelectRangeBuffer(mapBase, 5);
        {
            s8 uy = (s8)((u8 *)self)[0x19F];
            s8 ux = (s8)((u8 *)self)[0x19E];
            s16 *tbl = *(s16 **)(mapBase + 0x14190);
            tbl[(s8)ux + ((s8)uy << 6)] = 0;
        }
    } else {
        Map_BuildUnitMoveRange(self, 5, -1);
    }
    bestScore = -1;
    bestX = -1;
    list = Unit_GetHeldItemSlot(self, sp10);
    {
        s8 ux = (s8)((u8 *)self)[0x19E];
        s8 uy = (s8)((u8 *)self)[0x19F];
        range = Unit_GetMov(self);
        sp14 = ux - range;
        if (sp14 < (s8)map[8]) {
            sp14 = (s8)map[8];
        }
        yCur = uy - range;
        if (yCur < (s8)map[9]) {
            yCur = (s8)map[9];
        }
        xMax = ux + range;
        if (xMax > (s8)map[0xA] - 1) {
            xMax = (s8)map[0xA] - 1;
        }
        yMax = uy + range;
        if (yMax > (s8)map[0xB] - 1) {
            yMax = (s8)map[0xB] - 1;
        }
    }
    for (; yCur <= yMax; yCur++) {
        xCur = sp14;
        rowOff = (s8)yCur << 6;
        for (; xCur <= xMax; xCur++) {
            if (((s16 *)(map + 0x610E))[(s8)xCur + rowOff] >= 0
                && (s8)map[rowOff + ((s8)xCur + 0xE18E)] == 0
                && Map_IsAiTerrainBlocked((s8)xCur, (s8)yCur) == 0) {
                id = map[rowOff + ((s8)xCur + 0xD)];
                if (id == 0 || id == ((u8 *)self)[0x198]) {
                    if (*(u32 *)list != 0) {
                        ok = Item_GetRangeForUnit(self);
                    } else {
                        ok = 0;
                    }
                    score = fn_8010E804(self, (s16)xCur, (s16)yCur, 1, ok);
                    if (score != 0 && score > bestScore) {
                        bestScore = score;
                        bestX = (s16)xCur;
                        bestY = (s16)yCur;
                    } else if (score == bestScore) {
                        a = fn_800F7994(self, bestX, bestY) + fn_800F7838(self, bestX, bestY);
                        a -= (fn_800FCF48((s8)bestX, (s8)bestY) >> 4) & 0xFFF;
                        b = fn_800F7994(self, (s16)xCur, (s16)yCur) + fn_800F7838(self, (s16)xCur, (s16)yCur);
                        b -= (fn_800FCF48((s8)(s16)xCur, (s8)(s16)yCur) >> 4) & 0xFFF;
                        if (a < b) {
                            bestX = (s16)xCur;
                            bestY = (s16)yCur;
                        }
                    }
                }
            }
        }
    }
    if (bestScore != -1) {
        sp8 = 0;
        fn_800FB96C(0x10, (s8)bestX, (s8)bestY, 0, (s8)bestX, (s8)bestY, (s8)*pSp10, 0);
    }
    return (u32)((-1 - bestScore) | (bestScore + 1)) >> 31;
}
s32 fn_8010E804(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 Allegiance_Compare(s32, s32);
    void fn_8001F9C4(u8 *, s8, s8, s8, s32);
    void Map_FillLayer(u8 *, s32, s32);
    void Map_SelectRangeBuffer(u8 *, s32);
    u8 Map_IsAiTerrainBlocked(s8, s8);
    extern u8 gBattleMap[151280];
    extern u16 gUnits[];
    register int var_r26;
    int var_r28;
    register u8 temp_r3;
    int temp_r0;
    s32 var_r27;
    register unsigned int temp_r30;
    register s32 var_r25;
    u8 *var_r21;
    s32 var_r24;
    s32 var_r23;
    int var_r7;
    register u8 *temp_r21;

    var_r28 = 0;
    Map_SelectRangeBuffer(gBattleMap, 6);
    Map_FillLayer(gBattleMap, 0xB, -1);
    fn_8001F9C4(gBattleMap, arg1, arg2, arg4, 1);
    fn_8001F9C4(gBattleMap, arg1, arg2, arg3 - 1, -1);
    Map_SelectRangeBuffer(gBattleMap, 5);

    var_r27 = (s16)arg1 - (s16)arg4;
    if (var_r27 < (s8)gBattleMap[8]) {
        var_r27 = (s8)gBattleMap[8];
    }
    var_r7 = (s16)arg2 - (s16)arg4;
    if (var_r7 < (s8)gBattleMap[9]) {
        var_r7 = (s8)gBattleMap[9];
    }
    var_r26 = (s16)arg1 + (s16)arg4;
    temp_r0 = (s8)gBattleMap[0xA] - 1;
    if (var_r26 > temp_r0) {
        var_r26 = temp_r0;
    }
    var_r25 = (s16)arg2 + (s16)arg4;
    temp_r0 = (s8)gBattleMap[0xB] - 1;
    if (var_r25 > temp_r0) {
        var_r25 = temp_r0;
    }

    var_r24 = var_r7;
    for (; var_r24 <= (int)var_r25; ++var_r24) {
    var_r23 = var_r27;
    temp_r30 = (s8)var_r24 << 6;
    goto loop_inner_cmp;
loop_inner:
    if (*(s16 *)(gBattleMap + (((s8)var_r23 + temp_r30) * 2) + 0x818E) >= 0) {
        temp_r21 = gBattleMap + temp_r30 + (s8)var_r23;
        if (((s8)temp_r21[0xE18E] == 0) && (Map_IsAiTerrainBlocked((s8)var_r23, (s8)var_r24) == 0)) {
            temp_r3 = temp_r21[0xD];
            if (temp_r3) {
                if (temp_r3) {
                    var_r21 = (u8 *)gUnits + (temp_r3 - 1) * 0x280;
                } else {
                    var_r21 = NULL;
                }
                if ((Allegiance_Compare(*(s32 *)((u8 *)arg0 + 0x190), *(s32 *)(var_r21 + 0x190)) != 1)
                    && (*(s32 *)(var_r21 + 0x254) & 1)) {
                    ++var_r28;
                }
            }
        }
    }
    var_r23 += 1;
loop_inner_cmp:
    if (var_r23 <= var_r26) {
        goto loop_inner;
    }
    }
    return var_r28;
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
s32 fn_8010EA20(void *arg0, s32 arg1, u8 (*arg2)(void *)) {
    u8 Item_GetRangeForUnit(void *, void *);
    void Map_FillLayer(void *, s32, s32);
    void Map_SelectRangeBuffer(void *, s32);
    void **Unit_GetHeldItemSlot(void *, s32);
    s8 Unit_GetMov(void *);
    s8 Unit_GetMaxHp(void *);
    s32 fn_800F7838(void *, s8, s8);
    s32 fn_800F7994(void *, s8, s8);
    void fn_800FB96C(s32, s8, s8, void *, u8, u8, s8, s32, s32);
    u32 fn_800FCF48(s8, s8);
    void fn_800FDDBC(s8, s8, u8, u8, s32);
    void Map_BuildUnitMoveRange(void *, s32, s32);
    u8 Map_IsAiTerrainBlocked(s8, s8);
    extern u8 gAiState[];
    extern u8 gBattleMap[];
    extern u16 gUnits[];
    extern f32 lbl_8036A170;

    u8 *flags;
    u8 *map;
    s32 slot;
    u8 (*cb)(void *);
    u8 bestCost;
    s16 bestX;
    s16 bestY;
    void *best;
    s32 minX;
    s32 maxX;
    s32 maxY;
    s32 minY;
    void **itemSlot_store[1];
    s8 ax;
    s8 ay;
    u8 extra;
    s32 range;
    s32 x;
    s32 y;
    void *unit;
    u8 id;
    u8 extra2;
    u8 kind;
    s32 bestScore;
    s8 iy;
    s8 ix;
    s32 score;
    s32 idx;
    s32 idx2;
    s8 maximum;
    f32 numerator;
    f32 denominator;
    s32 ratio;
    s16 chosenX;
    s16 chosenY;
    u8 occ;
    u8 *mapBase;
    u8 *rowY;
    void *item;
    u8 *map2;
    u8 *map3;

    flags = gAiState;
    slot = arg1;
    cb = arg2;
    map = gBattleMap;
    if ((flags[1] & 2) || (*(u32 *)((u8 *)arg0 + 0x254) & 0x03000000)) {
        Map_FillLayer(map, 5, -1);
        Map_SelectRangeBuffer(map, 5);
        (*(s16 **)(map + 0x14190))[(s8)*((u8 *)arg0 + 0x19e) + ((s8)*((u8 *)arg0 + 0x19f) << 6)] = 0;
    } else {
        Map_BuildUnitMoveRange(arg0, 5, -1);
    }
    bestCost = 0x64;
    best = NULL;
    itemSlot_store[0] = Unit_GetHeldItemSlot(arg0, slot);
    item = *itemSlot_store[0];
    ax = (s8)*((u8 *)arg0 + 0x19e);
    ay = (s8)*((u8 *)arg0 + 0x19f);
    if (item != NULL) {
        extra = (u8)Item_GetRangeForUnit(item, arg0);
    } else {
        extra = 0;
    }
    range = (s8)Unit_GetMov(arg0);
    range += (u8)extra;
    minX = ax - range;
    if (minX < (s8)gBattleMap[8]) {
        minX = (s8)gBattleMap[8];
    }
    minY = ay - range;
    mapBase = gBattleMap;
    if (minY < (s8)mapBase[9]) {
        minY = (s8)mapBase[9];
    }
    maxX = ax + range;
    if (maxX > (s8)gBattleMap[10] - 1) {
        maxX = (s8)gBattleMap[10] - 1;
    }
    maxY = ay + range;
    if (maxY > (s8)gBattleMap[11] - 1) {
        maxY = (s8)gBattleMap[11] - 1;
    }
    map2 = gBattleMap;
    map3 = gBattleMap;
    for (y = minY; y <= maxY; y++) {
        for (x = minX; x <= maxX; x++) {
            id = map3[((s8)y << 6) + (s8)x + 0xD];
            if (id != 0) {
                if (id != 0) {
                    unit = (u8 *)gUnits + (id - 1) * 0x280;
                } else {
                    unit = NULL;
                }
                if (unit != arg0) {
                    if ((flags[1] & 4) || cb == NULL || cb(unit) == 0) {
                        if (*(u32 *)((u8 *)unit + 0x254) & 1) {
                            item = *itemSlot_store[0];
                            if (item != NULL) {
                                extra2 = (u8)Item_GetRangeForUnit(item, arg0);
                            } else {
                                extra2 = 0;
                            }
                            item = *itemSlot_store[0];
                            if (item != NULL) {
                                kind = *((u8 *)item + 0x1D);
                            } else {
                                kind = 0;
                            }
                            fn_800FDDBC((s8)*((u8 *)unit + 0x19e), (s8)*((u8 *)unit + 0x19f), kind, extra2, 6);
                            bestScore = 0x80000000;
                            for (iy = (s8)mapBase[9]; iy <= (s8)gBattleMap[11] - 1; iy++) {
                                rowY = map + ((s8)iy << 6);
                                for (ix = (s8)gBattleMap[8]; ix <= (s8)gBattleMap[10] - 1; ix++) {
                                    idx = (s8)ix + ((s8)iy << 6);
                                    idx2 = idx * 2;
                                    if (*(s16 *)(map + idx2 + 0x610e) >= 0
                                        && (s8)rowY[(s32)ix + 0xE18E] == 0
                                        && Map_IsAiTerrainBlocked(ix, iy) == 0
                                        && *(u16 *)(map2 + idx2 + 0xC18E) != 0) {
                                        occ = rowY[(s8)ix + 0xD];
                                        if (occ == 0 || occ == *((u8 *)arg0 + 0x198)) {
                                            score = fn_800F7994(arg0, ix, iy);
                                            score += fn_800F7838(arg0, ix, iy);
                                            score -= (fn_800FCF48(ix, iy) >> 4) & 0xFFF;
                                            if (bestScore < score) {
                                                bestScore = score;
                                                chosenX = (s16)ix;
                                                chosenY = (s16)iy;
                                            }
                                        }
                                    }
                                }
                            }
                            if ((u32)(bestScore + 0x80000000) != 0) {
                                maximum = Unit_GetMaxHp(unit);
                                numerator = (f32)(s8)*((u8 *)unit + 0x1A8);
                                denominator = (f32)maximum;
                                ratio = (s32)((lbl_8036A170 * numerator) / denominator);
                                if ((u8)ratio <= bestCost) {
                                    bestCost = (u8)ratio;
                                    bestX = chosenX;
                                    bestY = chosenY;
                                    best = unit;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (best != NULL) {
        fn_800FB96C(0x10, (s8)bestX, (s8)bestY, best,
            *((u8 *)best + 0x19e), *((u8 *)best + 0x19f), (s8)slot, 0, 0);
    }
    return best != NULL;
}
#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw reset

void fn_8010EF34(void) {
    M2C_UNK fn_8010EF74();
    fn_8010EF74();
}

void fn_8010EF54(void) {
    M2C_UNK fn_8010EF74();
    fn_8010EF74();
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
s32 fn_8010EF74(void *arg0, s32 arg1, u8 (*arg2)(void *)) {
    s32 Item_GetRangeForUnit(void *,void *);
    void Map_FillLayer(void *,s32,s32); void Map_SelectRangeBuffer(void *,s32);
    void **Unit_GetHeldItemSlot(void *,s32);
    s8 Unit_GetMov(void *); s8 Unit_GetMaxHp(void *);
    extern f32 lbl_8036A170;
    s32 fn_800F7838(void *,s16,s16); s32 fn_800F7994(void *,s16,s16);
    void fn_800FB96C(s32,s8,s8,void *,u8,u8,s8,s32,s32);
    u32 fn_800FCF48(s8,s8);
    void Map_BuildUnitMoveRange(void *,s32,s32); void fn_80100D18(void *,void *,s32);
    extern u8 gAiState[],gBattleMap[];
    extern u16 gUnits[];
    extern s16 lbl_80273B78[];
    u8 *flags=gAiState;
    u8 *map=gBattleMap;
    s16 bestX,bestY;
    void *best;
    s32 minX,maxX,maxY,row;
    s32 slot=arg1;
    s32 range,minY;
    s32 startX;
    s32 startY;
    void *item;
    u8 extra;
    s32 k,score;
    s32 bestScore;
    s16 ny,nx;
    void *unit;
    s16 *dir;
    s32 rank;
    s16 chosenX,chosenY;
    s32 x;
    s32 ratio;
    if ((flags[1]&2) || (*(u32 *)((u8 *)arg0+0x254)&0x03000000)) {
        Map_FillLayer(map,5,-1); Map_SelectRangeBuffer(map,5);
        (*(s16 **)(map+0x14190))[(s8)*((u8 *)arg0+0x19e)+((s8)*((u8 *)arg0+0x19f)<<6)]=0;
    } else Map_BuildUnitMoveRange(arg0,5,-1);
    fn_80100D18(arg0,Unit_GetHeldItemSlot(arg0,slot),-1);
    startX=*(s8 *)((u8 *)arg0+0x19e); startY=*(s8 *)((u8 *)arg0+0x19f);
    best=NULL; rank=100;
    item=*Unit_GetHeldItemSlot(arg0,slot);
    if(item) extra=Item_GetRangeForUnit(item,arg0); else extra=0;
    range=(s8)Unit_GetMov(arg0); range+=(u8)extra;
    minX=startX-range; if(minX<(s8)gBattleMap[8]) minX=(s8)gBattleMap[8];
    minY=startY-range; if(minY<(s8)gBattleMap[9]) minY=(s8)gBattleMap[9];
    maxX=startX+range; if(maxX>(s8)gBattleMap[10]-1) maxX=(s8)gBattleMap[10]-1;
    maxY=startY+range; if(maxY>(s8)gBattleMap[11]-1) maxY=(s8)gBattleMap[11]-1;
    for(row=minY;row<=maxY;row++) {
        for(x=minX;x<=maxX;x++) {
            u8 id=map[((s8)row<<6)+(s8)x+13];
            if(id && id!=*((u8 *)arg0+0x198)) {
                if(id) unit=(u8 *)gUnits+(id-1)*0x280; else unit=NULL;
                if(!(flags[1]&4) && arg2 && arg2(unit)) continue;
                if((*(u32 *)((u8 *)unit+0x254)&1)==0) continue;
                {
                    s8 maximum=Unit_GetMaxHp(unit);
                    u8 value=*((u8 *)unit+0x1a8);
                    f32 numerator=(f32)(s8)value;
                    f32 denominator=(f32)maximum;
                    ratio=(s32)((lbl_8036A170*numerator)/denominator);
                }
                if((u8)ratio>(u8)rank) continue;
                {
                u8 *grid=gBattleMap;
                score=0; dir=lbl_80273B78; k=score; bestScore=0x80000000;
                do {
                    s32 index;
                    nx=(s16)x+dir[0]; ny=(s16)row+dir[1];
                    index=(s8)nx+((s8)ny<<6);
                    if((s16)(*(s16 **)(grid+0x14190))[index]>=0) {
                        u8 *p=grid+index;
                        if((s8)p[0xe18e]==0) {
                            u8 occupant=p[13];
                            if(occupant==0 || occupant==*((u8 *)arg0+0x198)) {
                                score+=fn_800F7994(arg0,nx,ny);
                                score+=fn_800F7838(arg0,nx,ny);
                                score-=(fn_800FCF48((s8)nx,(s8)ny)>>4)&0xfff;
                                if(bestScore<score) {chosenX=nx;chosenY=ny;bestScore=score;}
                            }
                        }
                    }
                    ++k; score=0; dir+=2;
                } while(k<4);
                }
                if((u32)(bestScore+0x80000000)!=0) {
                    rank=ratio;bestX=chosenX;bestY=chosenY;best=unit;
                }
            }
        }
    }
    if(best) {
        fn_800FB96C(16,(s8)bestX,(s8)bestY,best,*((u8 *)best+0x19e),*((u8 *)best+0x19f),(s8)slot,0,0);
    }
    return best!=NULL;
}

s32 fn_8010F3F4(void *arg0, s16 arg1, s16 arg2, s16 *arg3, s16 *arg4)
{
    extern u8 gBattleMap[];
    extern u8 lbl_80273B78[];

    extern s32 fn_800F7994(void *, s32, s32);
    extern s32 fn_800F7838(void *, s32, s32);
    extern u32 fn_800FCF48(s8, s8);

    u8 *base;
    const s16 *direction;
    s32 ax;
    s32 ay;
    s16 x;
    s16 y;
    s32 bestScore;
    s32 score;
    s32 i;

    base = gBattleMap;
    direction = (const s16 *)lbl_80273B78;
    ax = arg1;
    ay = arg2;
    bestScore = (s32)0x80000000;
    score = 0;

    for (i = 0; i < 4; i++, score = 0, direction += 2) {
        const s16 *heightTable;
        s32 index;
        u32 value;

        x = ax + direction[0];
        heightTable = *(s16 **)(base + 0x14190);
        y = ay + direction[1];

        index = (s8)x + ((s8)y << 6);

        if (heightTable[index] < 0) {
            continue;
        }

        if ((s8)base[0xE18E + index] != 0) {
            continue;
        }

        value = base[0xD + index];

        if (value != 0) {
            if (value != *((u8 *)arg0 + 0x198)) {
                continue;
            }
        }

        score += fn_800F7994(arg0, x, y);
        score += fn_800F7838(arg0, x, y);

        value = fn_800FCF48((s8)x, (s8)y);
        score -= (value >> 4) & 0xFFF;

        if (bestScore < score) {
            *arg3 = x;
            *arg4 = y;
            bestScore = score;
        }
    }

    return bestScore != (s32)0x80000000;
}

#pragma opt_strength_reduction reset

u8 fn_8010F52C(void *arg0, s32 arg1) {
#pragma use_lmw_stmw on
void **Unit_GetHeldItemSlot(void *, s32);
u8 fn_8009326C(void *, void *);
extern u32 lbl_8028F5F8[48];
extern u8 gAiState[];
u8 best;
s32 i;
u8 *item;
void **slot;
u32 *entry;
void *unit;
s32 mode;
unit=arg0;
mode=arg1;
if((((u8*)unit)[0x1A5]>>4&7)==0) {
best=0;
for(i=0;i<4;i++) {
slot=Unit_GetHeldItemSlot(unit,i);
item=*slot;
if(item==NULL) break;
if((u8)(item ? item[0x14]:0xC)==0x81) continue;
if((u8)(item ? item[0x16]:0)<best) continue;
if(fn_8009326C(unit,item)) {
for(entry=lbl_8028F5F8;entry[1]!=0;entry+=3) {
if(item==(u8*)entry[1] && entry[2]!=0) goto found;
}
}
entry=NULL;
found:
if(entry!=NULL && ((u8 (*)(void*,s32,s32))entry[2])(unit,i,mode)) {
item=*slot;
best=item ? item[0x16]:0;
}
}
}
return gAiState[0x21C];
}

void fn_8010F970(void) {
    u32 Item_GetByIid(u32);
    extern u32 lbl_8028F5F8[48];
    u32 *p;

    for (p = lbl_8028F5F8; p[0] != 0; p += 3) {
        p[1] = Item_GetByIid(p[0]);
    }
}

void *fn_8010F9BC(void *arg0, s8 arg1, s8 arg2, u8 arg3) {
    s32 count;
    s32 i;
    char *p;
    s32 dx;
    s32 dy;

    count = *(s32 *)((char *)arg0 + 0x200);
    p = (char *)arg0;
    for (i = 0; i < count; i++, p += 8) {
        dx = arg1 - *(s8 *)(p + 0);
        dy = arg2 - *(s8 *)(p + 1);
        if (dx * dx + dy * dy <= 1) {
            if (arg3 == 0 || arg3 == *(u8 *)(p + 2)) {
                return p;
            }
        }
    }
    return NULL;
}

extern u8 lbl_803679E0;
extern M2C_UNK lbl_803679E4;
void Item_Destroy(void);
extern u8 lbl_8032BDDC[];
M2C_UNK *fn_8010FA2C(void *arg0) {
    s32 Item_Get(s32 arg0);
    M2C_UNK *Item_Init(M2C_UNK *);
    M2C_UNK Item_SetUses(M2C_UNK *, u8);
    M2C_UNK UnitRef_Set(M2C_UNK *, s32);
    M2C_UNK *__register_global_object(M2C_UNK *, M2C_UNK *, M2C_UNK *);

    if ((s8) lbl_803679E0 == 0) {
        __register_global_object(Item_Init(&lbl_803679E4), (M2C_UNK *)Item_Destroy, (M2C_UNK *)lbl_8032BDDC);
        lbl_803679E0 = 1;
    }
    UnitRef_Set(&lbl_803679E4, Item_Get(M2C_FIELD(arg0, u8 *, 4)));
    Item_SetUses(&lbl_803679E4, M2C_FIELD(arg0, u8 *, 5));
    return &lbl_803679E4;
}

void fn_8010FAA8(void) {
    void fn_8001F91C(void *, u8, u8, s8);
    extern u8 lbl_8032BB58[];
    extern u8 gBattleMap[];
    s32 i;
    u8 *base;
    u8 *p;
    i = 0;
    base = lbl_8032BB58;
    p = base;
    while (i < *(s32 *)(base + 0x200)) {
        switch (p[2]) {
        case 6:
            fn_8001F91C(gBattleMap, p[0], p[1], (s8)p[3]);
            break;
        case 9: {
            s32 y = (s8)p[1];
            s32 x = (s8)p[0];
            u8 *cell = gBattleMap + x + (y << 6);
            if (cell[0xd] == 0) cell[0x300d] |= 2;
            break;
        }
        }
        p += 8;
        i++;
    }
}

void fn_8010FB7C(s32 arg0, s32 arg1) {
    Stream_Read(arg1, 0x204, arg0);
}

void fn_8010FBA8(s32 arg0, s32 arg1) {
    Stream_Write(arg1, 0x204, arg0);
}

void fn_8010FBD4(void) {

}

extern u8 lbl_8028F2D0[];
#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_8010FBD8(void *arg0)
{
    void DebugPrint(const char *, ...);
    typedef struct { char *a[11]; } T1;
    typedef struct { char *a[10]; } T2;
    extern char lbl_80273CE4[];
    extern T1 lbl_80273C90;
    extern T2 lbl_80273CBC;
    struct { T1 t1; T2 t2; } sp;
    void *self;
    char *strBase;
    T1 *p1;
    T2 *p2;
    u8 *entry;
    s32 i;
    u8 type;
    s32 b0;
    s32 b1;
    u8 b3;
    u8 b4;
    u8 b5;
    char *name;

    self = arg0;
    if (*(s32 *)((u8 *)self + 0x200) == 0) {
        DebugPrint(lbl_80273CE4 + 0xCE);
        return;
    }
    DebugPrint(lbl_80273CE4 + 0xDE);
    p1 = &lbl_80273C90;
    p2 = &lbl_80273CBC;
    strBase = lbl_80273CE4;
    entry = (u8 *)self;
    for (i = 0; i < *(s32 *)((u8 *)self + 0x200); i++) {
        type = entry[2];
        sp.t1 = *p1;
        sp.t2 = *p2;
        b0 = entry[0];
        b1 = entry[1];
        b3 = entry[3];
        b4 = entry[4];
        b5 = entry[5];
        if (type >= 0x20) {
            name = *(char **)((u8 *)&sp.t2 + (type << 2) - 0x80);
        } else {
            name = *(char **)((u8 *)&sp.t1 + (type << 2));
        }
        DebugPrint(strBase + 0xEC, i, (s32)(s8)b0, (s32)(s8)b1, b3, b4, b5, name);
        entry += 8;
    }
}
#pragma global_optimizer on
void fn_8010FD70(void *arg0, s8 arg1, s8 arg2, s8 arg3, s8 arg4) {
    char *temp_r9;

    temp_r9 = (char*)arg0 + (*(s32*)((char*)arg0 + 0x200) << 3);
    *(u8*)(temp_r9 + 0x0) = arg1;
    *(u8*)(temp_r9 + 0x1) = arg2;
    *(u8*)(temp_r9 + 0x2) = 0xA;
    *(u8*)(temp_r9 + 0x3) = arg3;
    *(u8*)(temp_r9 + 0xA) = 0x0;
    *(s32*)((char*)arg0 + 0x200) = *(s32*)((char*)arg0 + 0x200) + 1;
    *(u8*)(temp_r9 + 0x4) = 0x0;
    *(u8*)(temp_r9 + 0x5) = 0x0;
    *(u8*)(temp_r9 + 0x6) = 0x0;
    *(u8*)(temp_r9 + 0x7) = arg4;
}

#pragma global_optimizer off
void fn_8010FDB8(void *arg0, s8 arg1, s8 arg2, s8 arg3, void *arg4) {
    u16 temp_r9;
    u8 temp_r10;
    char *temp_r8;
    s8 zero;

    temp_r9 = *(u16 *)((char *)arg4 + 0xE);
    temp_r10 = *(u8 *)((char *)arg4 + 0x18);
    temp_r8 = (char *)arg0 + (*(s32 *)((char *)arg0 + 0x200) << 3);
    temp_r8[0] = arg1;
    temp_r8[1] = arg2;
    temp_r8[2] = 7;
    temp_r8[3] = arg3;
    zero = (s8)(temp_r9 & ~temp_r9);
    temp_r8[0xA] = zero;
    *(s32 *)((char *)arg0 + 0x200) = *(s32 *)((char *)arg0 + 0x200) + 1;
    temp_r8[4] = (s8)temp_r9;
    temp_r8[5] = temp_r10;
    temp_r8[6] = zero;
    temp_r8[7] = zero;
}
#pragma global_optimizer reset
void MapObjEvent_Remove(void *arg0, s8 arg1, s8 arg2, u8 arg3) {
    s32 n;
    u8 *walk;
    s32 i;

restart:
    n = *(s32 *)((u8 *)arg0 + 0x200);
    walk = (u8 *)arg0;
    i = 0;
    for (; i < n; i++) {
            if (arg1 == (s8)walk[0] && arg2 == (s8)walk[1] && (arg3 == 0 || arg3 == walk[2])) {
                u8 *dst = (u8 *)arg0 + (i << 3);
                s32 j = i;
                while (j < *(s32 *)((u8 *)arg0 + 0x200) - 1) {
                    u8 *src;
                    src = (u8 *)arg0 + ((j + 1) << 3);
                    j = j + 1;
                    dst[0] = src[0];
                    dst[1] = src[1];
                    dst[2] = src[2];
                    dst[3] = src[3];
                    dst[4] = src[4];
                    dst[5] = src[5];
                    dst[6] = src[6];
                    dst[7] = src[7];
                    dst = dst + 8;
                }
                *(s32 *)((u8 *)arg0 + 0x200) = *(s32 *)((u8 *)arg0 + 0x200) - 1;
                goto restart;
            }
            walk = walk + 8;
    }
}

void *MapObjEvent_Push(void *arg0, s8 arg1, s8 arg2, s8 arg3, s8 arg4) {
    char *temp_r8;

    temp_r8 = (char *)arg0 + (*(s32 *)((char *)arg0 + 0x200) << 3);
    *(u8 *)(temp_r8 + 0x0) = arg1;
    *(u8 *)(temp_r8 + 0x1) = arg2;
    *(u8 *)(temp_r8 + 0x2) = arg3;
    *(u8 *)(temp_r8 + 0x3) = arg4;
    *(u8 *)(temp_r8 + 0xA) = 0;
    *(s32 *)((char *)arg0 + 0x200) = *(s32 *)((char *)arg0 + 0x200) + 1;
    return temp_r8;
}

void *MapObjEvent_Find(void *arg0, s8 arg1, s8 arg2, u8 arg3) {
    s32 count;
    s32 i;
    char *p;

    count = *(s32 *)((char *)arg0 + 0x200);
    p = (char *)arg0;
    for (i = 0; i < count; i++, p += 8) {
        if (arg1 == *(s8 *)(p + 0) && arg2 == *(s8 *)(p + 1)) {
            if (arg3 == 0 || arg3 == *(u8 *)(p + 2)) {
                return p;
            }
        }
    }
    return NULL;
}

s32 fn_8010FF88(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x200);
}

void fn_8010FF90(void *arg0) {
    extern u32 lbl_8032BD5C[32];

    *(s32 *)((char *)arg0 + 0x200) = 0;
    *(u8 *)((char *)arg0 + 0) = 0;
    *(u8 *)((char *)arg0 + 1) = 0;
    *(u8 *)((char *)arg0 + 2) = 0;
    *(u8 *)((char *)arg0 + 3) = 0;
    lbl_8032BD5C[0] = 0;
    lbl_8032BD5C[1] = 0;
    lbl_8032BD5C[2] = 0;
    lbl_8032BD5C[3] = 0;
    lbl_8032BD5C[4] = 0;
    lbl_8032BD5C[5] = 0;
    lbl_8032BD5C[6] = 0;
    lbl_8032BD5C[7] = 0;
    lbl_8032BD5C[8] = 0;
    lbl_8032BD5C[9] = 0;
    lbl_8032BD5C[10] = 0;
    lbl_8032BD5C[11] = 0;
    lbl_8032BD5C[12] = 0;
    lbl_8032BD5C[13] = 0;
    lbl_8032BD5C[14] = 0;
    lbl_8032BD5C[15] = 0;
    lbl_8032BD5C[16] = 0;
    lbl_8032BD5C[17] = 0;
    lbl_8032BD5C[18] = 0;
    lbl_8032BD5C[19] = 0;
    lbl_8032BD5C[20] = 0;
    lbl_8032BD5C[21] = 0;
    lbl_8032BD5C[22] = 0;
    lbl_8032BD5C[23] = 0;
    lbl_8032BD5C[24] = 0;
    lbl_8032BD5C[25] = 0;
    lbl_8032BD5C[26] = 0;
    lbl_8032BD5C[27] = 0;
    lbl_8032BD5C[28] = 0;
    lbl_8032BD5C[29] = 0;
    lbl_8032BD5C[30] = 0;
    lbl_8032BD5C[31] = 0;
}

s32 fn_80110030(void *arg0) {
    extern s32 lbl_8032BD5C[];
    return lbl_8032BD5C[*(u8 *)((u8 *)arg0 + 7)];
}

s32 fn_80110048(void *arg0) {
    extern void *lbl_8032BD5C[0x20];
    void **p;
    s32 i;

    p = lbl_8032BD5C;
    for (i = 0; i < 0x20; i++) {
        if (*p == NULL) {
            lbl_8032BD5C[i] = arg0;
            goto done;
        }
        p++;
    }
    i = -1;
done:
    return i;
}

#pragma peephole off
s32 fn_80110094(void) {
    extern u32 lbl_8032BD5C[32];
    s32 ret;

    *lbl_8032BD5C = 0;
    ret = 1;
    lbl_8032BD5C[1] = 0;
    lbl_8032BD5C[2] = 0;
    lbl_8032BD5C[3] = 0;
    lbl_8032BD5C[4] = 0;
    lbl_8032BD5C[5] = 0;
    lbl_8032BD5C[6] = 0;
    lbl_8032BD5C[7] = 0;
    lbl_8032BD5C[8] = 0;
    lbl_8032BD5C[9] = 0;
    lbl_8032BD5C[10] = 0;
    lbl_8032BD5C[11] = 0;
    lbl_8032BD5C[12] = 0;
    lbl_8032BD5C[13] = 0;
    lbl_8032BD5C[14] = 0;
    lbl_8032BD5C[15] = 0;
    lbl_8032BD5C[16] = 0;
    lbl_8032BD5C[17] = 0;
    lbl_8032BD5C[18] = 0;
    lbl_8032BD5C[19] = 0;
    lbl_8032BD5C[20] = 0;
    lbl_8032BD5C[21] = 0;
    lbl_8032BD5C[22] = 0;
    lbl_8032BD5C[23] = 0;
    lbl_8032BD5C[24] = 0;
    lbl_8032BD5C[25] = 0;
    lbl_8032BD5C[26] = 0;
    lbl_8032BD5C[27] = 0;
    lbl_8032BD5C[28] = 0;
    lbl_8032BD5C[29] = 0;
    lbl_8032BD5C[30] = 0;
    lbl_8032BD5C[31] = 0;
    return ret;
}
#pragma peephole reset
#include "global.h"
extern u16 lbl_8028F3AC;
#include "common.h"
#include "units.h"
extern u8 D_801A39D4;
extern u8 D_8017C3CC;

#pragma optimization_level 3
#pragma use_lmw_stmw on
u8 fn_8010F670(void *arg0, s32 arg1) {
void **Unit_GetHeldItemSlot(void *, s32);
u8 fn_8009326C(void *, void *);
extern u32 lbl_8028F5F8[48];
extern u8 gAiState[];
#pragma cplusplus on
struct Handler {
static u32 *Find(void *unit, u8 *item) {
u32 *p;
if(fn_8009326C(unit,item)) {
for(p=lbl_8028F5F8;p[1]!=0;p+=3) {
if(item==(u8*)p[1] && p[2]!=0) return p;
}
}
return NULL;
}
};
u8 *item;
void **slot;
u8 best;
s32 i;
u32 *entry;
if((((u8*)arg0)[0x1A5]>>4&7)==0) {
best=0;
for(i=0;i<4;i++) {
slot=Unit_GetHeldItemSlot(arg0,i);
item=(u8*)*slot;
if(item==NULL) break;
if((u8)(item ? item[0x14]:0xC)!=0x81) continue;
if((u8)(item ? item[0x16]:0)<best) continue;
entry=Handler::Find(arg0,item);
if(entry!=NULL && ((u8 (*)(void*,s32,s32))entry[2])(arg0,i,arg1)) {
item=(u8*)*slot;
best=item ? item[0x16]:0;
}
}
}
return gAiState[0x21C];
#pragma cplusplus reset
}
#pragma optimization_level reset
u8 Ai_TryHeldItemAction(void *arg0, s32 arg1) {
    void **Unit_GetHeldItemSlot(void *, s32);
    u8 fn_8009326C(void *, void *);
    extern u32 lbl_8028F5F8[48];
    extern u8 gAiState[];
#pragma cplusplus on
    struct Handler {
        static u32 *Find(void *unit, u8 *item) {
            u32 *p;
            if (fn_8009326C(unit, item)) {
                for (p = lbl_8028F5F8; p[1] != 0; p += 3) {
                    if (item == (u8 *)p[1]) {
                        if (p[2] != 0) {
                            return p;
                        }
                    }
                }
            }
            return NULL;
        }
    };
    void **slot;
    u8 *item;
    u8 hasHeal;
    u8 bestHeal;
    u8 bestOther;
    s32 i;
    u32 *entry;
    u8 type;
    u8 val;

    if ((((u8 *)arg0)[0x1A5] >> 4 & 7) == 0) {
        hasHeal = 0;
        bestHeal = 0;
        bestOther = 0;
        for (i = 0; i < 4; i++) {
            slot = Unit_GetHeldItemSlot(arg0, i);
            item = (u8 *)*slot;
            if (item == NULL) {
                break;
            }
            type = item ? item[0x14] : 0xC;
            if (type == 0x81) {
                val = item ? item[0x16] : 0;
                if (val < bestHeal) {
                    continue;
                }
            } else {
                if (hasHeal != 0) {
                    continue;
                }
                val = item ? item[0x16] : 0;
                if (val < bestOther) {
                    continue;
                }
            }
            entry = Handler::Find(arg0, item);
            if (entry != NULL && ((u8 (*)(void *, s32, s32))entry[2])(arg0, i, arg1)) {
                item = (u8 *)*slot;
                type = item ? item[0x14] : 0xC;
                if (type == 0x81) {
                    bestHeal = item ? item[0x16] : 0;
                    hasHeal = 1;
                } else {
                    bestOther = item ? item[0x16] : 0;
                }
            }
        }
    }
    return gAiState[0x21C];
#pragma cplusplus reset
}
