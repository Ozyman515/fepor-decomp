/* Functions from 0x8022CD68 to 0x80267A7C, found by decomp-toolkit. */
#include "common.h"

extern u8 gSoundData[];
extern f64 lbl_8036C368;
extern u16 *D_80256B30;
extern s32 UART_Initialized;
extern f32 lbl_8036C374;
extern s32 gSynthTimeHi;
extern s32 gSynthTimeLo;
extern s32 gSynthSchedList;
extern s32 gSynthIdleList;
extern u32* lbl_80368A38;
extern void (*lbl_80368B34)(s16);
extern f32 lbl_8034C324[];
extern s32 D_80368AD0;
extern s32 lbl_80368B0C;
extern s16 lbl_802A1E90[];
extern u8 lbl_80368AAE;
extern u8 lbl_80368AAD;
extern u16 lbl_8035BF18[];
extern u32 lbl_8035C918[];

u32 fn_8026367C(void);

typedef struct {
    s32 x;
    s32 y;
} Pair_80266D70;

typedef struct Voice {
    u8 pad0[0x110];
    u64 flags;
    u8 pad118[0x5C];
    s32 unk174;
    s32 unk178;
    s32 unk17C;
    s32 unk180;
    s32 unk184;
    s32 unk188;
    u32 unk18C;
    u32 unk190;
} Voice;

typedef struct VidList {
    struct VidList *next; /* 0x0 */
    struct VidList *prev; /* 0x4 */
    u32 vid;              /* 0x8 */
    u32 root;             /* 0xC */
} VidList;

extern u32 vidGenerator;

static u32 GetNewVid(void) {
    u32 vid;

    do {
        vid = vidGenerator++;
    } while (vid == 0xFFFFFFFF);
    return vid;
}

typedef struct GroupData {
    u8 pad0[4];
    u16 id;     /* 0x04 */
    u16 type;   /* 0x06 */
    u8 pad8[0x1C - 0x8];
    u32 unk1C;  /* 0x1C */
    u32 unk20;  /* 0x20 */
    u32 unk24;  /* 0x24 */
} GroupData;

typedef struct GroupEntry {
    GroupData *data; /* 0x0 */
    u32 unk4;        /* 0x4 */
    u32 base;        /* 0x8 */
} GroupEntry;

typedef struct GroupNode {
    struct GroupNode *next; /* 0x0 */
    u32 unk4;               /* 0x4 */
    s16 count;              /* 0x8 */
    GroupEntry entries[1];  /* 0xC */
} GroupNode;

typedef struct GroupItem {
    u16 id;
    u8 pad2[0x52];
} GroupItem;

typedef struct SynthVoice {
    struct SynthVoice *next; /* 0x000 */
    struct SynthVoice *prev; /* 0x004 */
    u8 state;                /* 0x008 */
    u8 id;                   /* 0x009 */
    u16 unkA;                /* 0x00A */
    u32 vid;                 /* 0x00C */
    u8 pad10[0xF4 - 0x10];
    u32 unkF4;               /* 0x0F4 */
    struct VidList *unkF8;   /* 0x0F8 */
    struct VidList *unkFC;   /* 0x0FC */
    u8 pad100[0x11C - 0x100];
    s32 unk11C;              /* 0x11C */
    s32 unk120;              /* 0x120 */
    u8 pad124[0xEF0 - 0x124];
    s32 unkEF0;              /* 0xEF0 */
    s32 unkEF4;              /* 0xEF4 */
    u16 unkEF8;              /* 0xEF8 */
    u8 unkEFA;               /* 0xEFA */
    u8 padEFB[0x1508 - 0xEFB];
    struct {
        u8 pad0[0x32];
        u16 unk32;
        u8 pad34[4];
    } unk1508[16];           /* 0x1508 */
} SynthVoice;

typedef struct {
    char gpr;
    char fpr;
    char reserved[2];
    char *input_arg_area;
    char *reg_save_area;
} __va_list;
typedef __va_list va_list[1];

typedef struct {
    char *buffer;
    s32 length;
    s32 position;
} __OutStr;

s32 __pformatter(s32 (*)(void *, const char *, u32), void *, const char *, va_list);
s32 fn_80232220(void *, const char *, u32);

// The structure being used in functions in this file - assumed based on offset 0xF4
typedef struct {
    u8 unkF4;  // This is likely the member accessed in function with 0xF4 offset 
} SStructType;

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern s32 gSynthVoices;
s32 Sound_LookupVid(void);

#pragma dont_inline on

#pragma dont_inline reset

extern u16 lbl_803548B8;
extern u16 lbl_80368A08;

u16 Sound_GetChanParam(u8 arg0, u8 arg1, u8 arg2);
s32 __cvt_fp2unsigned(f32 arg0);
void Sound_SetVoiceEnvelope(u8 arg0, void *arg1, s32 arg2);

void fn_8026146C(s32 *);
void fn_8025FFC8(void *arg0, u8 arg1, s32 arg2, u8 arg3, u8 arg4, u8 arg5);

static void SelectSource(void *svoice, void *dest, u32 *cstep, u64 tstflag, u32 dirtyflag) {
    u8 comb;
    s32 scale;
    u32 inv;

    if ((*(u64 *)((u8 *)svoice + 0x114) & tstflag) == 0) {
        *(u64 *)((u8 *)svoice + 0x114) |= tstflag;
        comb = 0;
    } else {
        comb = cstep[1];
    }
    scale = (s32)(cstep[0] & 0xFFFF0000) / 100;
    if (scale < 0) {
        scale -= ((s8)(cstep[1] >> 16) << 8) / 100;
    } else {
        scale += ((s8)(cstep[1] >> 16) << 8) / 100;
    }
    inv = (cstep[1] >> 8) & 0xFF;
    fn_8025FFC8(dest, cstep[0] >> 8, scale, comb, inv != 0, inv);
    *(u32 *)((u8 *)svoice + 0x220) |= dirtyflag;
}

extern void func_80013934(s32 arg0);

extern u8 gSoundData[];

extern u16 lbl_8035A510[];

extern u16 lbl_8035D118[256];

extern u16 gSoundChanParamsDefault[4288];

extern f32 lbl_802831BC[];
extern f64 lbl_8036C348;

extern u16 lbl_803670C0;

extern u32 lbl_803670C8;

extern u32 lbl_800000F8;

extern s32 lbl_80368B30;
  extern u32 lbl_80368B38;
  extern s32 lbl_80368B3C;
  extern u8 lbl_80368B44;


extern u16 lbl_802A1E10[4];
extern u16 lbl_8034CBB4[288];
extern u16 lbl_8035D118[];
#include "common.h"

extern s32 lbl_80368B2C;
extern u16 gSoundVoices[];
extern u16 lbl_803670C0;
#include "common.h"
#include "include/common.h"
#include "global.h"
#include "structs.h"
extern u16 lbl_80368AFC;
extern s32 lbl_80368AF8;
extern u16 lbl_80368AFC;
extern s32 lbl_80368AF8;
extern u8 lbl_8035A610[];
extern u8 lbl_8035A650[];
extern s32 gSoundStudios[];
typedef struct {
    u32 field_0x0;
    u32 field_0x4;
    u32 field_0x8;
    // ... padding ...
    u32 field_0xF8;
    u32 field_0xFC;
    u32 field_0x100;
    u32 field_0x104;
    u32 field_0x108;
} SomeStruct;
extern u16 gSoundStreamCtrl[];
#include "global.h"
#include "structs.h"

typedef struct {
    u16 id;
    u16 ref;
    u32 unk4;
    u32 unk8;
    u8 unkC[0x14];
} Entry;

extern struct Entry gAudioGroups[];
extern u16 gAudioGroupCount;
extern u32 lbl_80368A14;
#include "global.h"
#include "structs.h"

extern s32 lbl_8035B220[];
extern s32 lbl_80368A58;
extern s32 *gAudioGroupState;
extern s32 *lbl_80368A60;
extern void *lbl_80368950;
extern u8 *lbl_803688E8;
extern u16 lbl_803688EC[10];
extern s32 lbl_8036894C;
extern s32 lbl_8033E578[];

void fn_8026649C(s32 arg0, s32 arg1)
{
    extern u8 lbl_803669A0[];
    extern u32 OSGetTick(void);
    extern s32 fn_80265544(s32 channel, void *callback);
    extern s32 fn_80266D70(s32 channel, s32 arg1, u32 ticks);
    extern s32 fn_802667D4(s32 channel, void *input, void *callback,
                           void *outputCallback);
    extern void fn_802665F8(s32 channel, s32 result);

    u8 *entry;
    u8 *queue;
    u32 tickRate;
    u32 elapsed;
    u32 timeout;
    s32 result;
    void (*callback)(s32, s32);

    entry = lbl_803669A0 + (arg0 << 8);
    queue = entry + 0x40;

    if (arg1 != 0) {
        return;
    }

    elapsed = OSGetTick() - *(u32 *)(queue + 0x24);
    tickRate = *(u32 *)0x800000F8 >> 2;
    timeout = tickRate * 10;

    if (timeout <= elapsed) {
        result = 3;
    } else {
        u8 status;

        status = **(u8 **)(queue + 0x10);

        if ((status & 0x32) != 0) {
            result = 3;
        } else if (status != 8) {
            result = fn_80265544(arg0, fn_8026649C);
        } else {
            u32 ticks;
            u32 frequency;

            frequency = *(u32 *)0x800000F8 >> 2;
            ticks = (frequency * 60) / 1000;

            fn_80266D70(arg0, 0, ticks);

            result = fn_802667D4(
                arg0,
                queue + 0x18,
                *(void **)(queue + 0x10),
                fn_802665F8
            );

            frequency = *(u32 *)0x800000F8 >> 2;
            ticks = (frequency * 1000) / 60;

            fn_80266D70(arg0, 0, ticks);
        }
    }

    if (result != 0) {
        *(u32 *)(queue + 0x2C) = 0;
        *(u32 *)(queue + 0x28) = 0;

        callback = *(void (**)(s32, s32))(queue + 0x14);
        if (callback != 0) {
            *(u32 *)(queue + 0x14) = 0;
            callback(arg0, result);
        }
    }

    *(s32 *)(entry + 0x20) = result;
}

#pragma global_optimizer off
void fn_802665F8(s32 arg0, s32 arg1)
{
    extern u8 lbl_803669A0[];
    s32 fn_80266904(s32, void *, void *, void *);
    void fn_802666F4(void);

    u8 *base;
    u8 *q;
    s32 result;
    u32 v;
    void (*cb)(s32, s32);
    u8 dummy[8];

    base = &lbl_803669A0[arg0 << 8];
    q = base + 0x40;
    result = arg1;

    if (result == 0) {
        v = *(u32 *)(q + 0x60);
        if (((q[0x1B] ^ (v >> 24)) | (q[0x1A] ^ (v >> 16)) | (q[0x19] ^ (v >> 8)) | (q[0x18] ^ v)) << 24) {
            result = 3;
        } else {
            result = fn_80266904(arg0, q + 0x18, *(void **)(q + 0x10), fn_802666F4);
        }
    }
    if (result != 0) {
        *(u32 *)(q + 0x2C) = 0;
        *(u32 *)(q + 0x28) = 0;
        if ((cb = *(void (**)(s32, s32))(q + 0x14)) != 0) {
            *(u32 *)(q + 0x14) = 0;
            (*cb)(arg0, result);
        }
    }
    *(s32 *)(base + 0x20) = result;
}
#pragma global_optimizer on
void fn_802666F4(s32 arg0, void *arg1)
{
    extern u8 lbl_803669A0[];
    u8 *entry;
    u8 *queue;
    void (*callback)(s32, void *);

    entry = lbl_803669A0 + (arg0 << 8);
    queue = entry + 0x40;

    if (arg1 == 0) {
        **(u8 **)(queue + 0x10) = 0;
        *(u32 *)(queue + 0x2C) = 0;
        *(u32 *)(queue + 0x28) = 0;
        callback = *(void (**)(s32, void *))(queue + 0x14);
        if (callback != 0) {
            *(u32 *)(queue + 0x14) = 0;
            callback(arg0, arg1);
        }
    }
    *(void **)(entry + 0x20) = arg1;
}
#pragma global_optimizer on
void fn_80266774(s32 arg0) {
    extern u8 lbl_803669A0[];
    void *memcpy(void *, const void *, u32);
    u8 *entry = lbl_803669A0 + (arg0 << 8);

    if (*(s32 *)(entry + 0x20) != 0) {
        return;
    }
    memcpy(*(void **)(entry + 0x18), entry + 0x5, 4);
    *(u8 *)(*(void **)(entry + 0x14)) = entry[0x9] & 0x3A;
}

#pragma global_optimizer off
s32 fn_802667D4(s32 arg0, void *input, void *callback, void *outputCallback) {
    extern u8 lbl_803669A0[];
    extern int fn_80266CFC(int, int, int, void *);
    u8 *entry = lbl_803669A0 + (arg0 << 8);

    if (*(u32 *)(entry + 0x1C) != 0) {
        return 2;
    }
    entry[0] = 0x14;
    *(void **)(entry + 0x18) = input;
    *(void **)(entry + 0x14) = callback;
    *(void **)(entry + 0x1C) = outputCallback;
    return fn_80266CFC(arg0, 1, 5, fn_80266774);
}
#pragma global_optimizer off
s32 fn_80266840(s32 chan, s32 arg1, s32 arg2) {
    extern u8 lbl_803669A0[];
    extern s32 fn_80266CFC(s32, s32, s32, void *);
    extern void fn_80266B6C(s32);
    void fn_80266774(void);
    void fn_80266B38(void);
    u8 *entry;
    s32 ret;
    u8 dummy[8];

    entry = lbl_803669A0 + (chan << 8);
    if (*(u32 *)(entry + 0x1C) != 0) {
        ret = 2;
    } else {
        *entry = 0x14;
        *(s32 *)(entry + 0x18) = arg1;
        *(s32 *)(entry + 0x14) = arg2;
        *(void **)(entry + 0x1C) = fn_80266B38;
        ret = fn_80266CFC(chan, 1, 5, fn_80266774);
    }
    if (ret != 0) {
        return ret;
    } else {
        fn_80266B6C(chan);
    }
}
#pragma global_optimizer on

#pragma peephole on
void fn_802668D4(s32 arg0) {
    extern u8 lbl_803669A0[];
    u8 *temp_r3 = lbl_803669A0 + (arg0 << 8);

    if (*(s32 *)(temp_r3 + 0x20) == 0) {
        *(u8 *)(*(void **)(temp_r3 + 0x14)) = temp_r3[5] & 0x3A;
    }
}

#pragma global_optimizer off
s32 fn_80266904(s32 channel, void *input, void *callback, void *outputCallback)
{
    extern u8 lbl_803669A0[];
    extern void *memcpy(void *, const void *, u32);
    extern s32 fn_80266CFC(s32, s32, s32, void *);
    u8 *entry;

    entry = lbl_803669A0 + (channel << 8);

    if (*(u32 *)(entry + 0x1C) != 0U) {
        return 2;
    }
    *entry = 0x15;
    memcpy(entry + 1, input, 4);
    *(void **)(entry + 0x18) = input;
    *(void **)(entry + 0x14) = callback;
    *(void **)(entry + 0x1C) = outputCallback;
    return fn_80266CFC(channel, 5, 1, (void *)fn_802668D4);
}
#pragma global_optimizer off
s32 GBAWrite(s32 chan, void *input, void *callback) {
    extern u8 lbl_803669A0[];
    extern void *memcpy(void *, const void *, u32);
    extern s32 fn_80266CFC(s32, s32, s32, void *);
    extern void fn_80266B6C(s32);
    void fn_80266B38(void);
    void fn_802668D4(void);
    u8 *entry;
    s32 ret;
    u8 dummy[8];

    entry = lbl_803669A0 + (chan << 8);
    if (*(u32 *)(entry + 0x1C) != 0) {
        ret = 2;
    } else {
        *entry = 0x15;
        memcpy(entry + 1, input, 4);
        *(void **)(entry + 0x18) = input;
        *(void **)(entry + 0x14) = callback;
        *(void **)(entry + 0x1C) = fn_80266B38;
        ret = fn_80266CFC(chan, 5, 1, fn_802668D4);
    }
    if (ret != 0) {
        return ret;
    } else {
        fn_80266B6C(chan);
    }
}
#pragma global_optimizer on

#pragma optimization_level 2

#pragma optimization_level reset

#pragma use_lmw_stmw on
#pragma peephole on

#pragma peephole reset
#pragma use_lmw_stmw reset

#pragma global_optimizer off

#pragma peephole on

#pragma peephole reset

#pragma global_optimizer reset

#pragma peephole on

#pragma peephole reset
