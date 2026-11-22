/* Functions from 0x8022CD68 to 0x80267A7C, found by decomp-toolkit. */
#include "common.h"
typedef struct SoundBucketNode { struct SoundBucketNode *next, *prev; u8 flags, index; u16 pad; } SoundBucketNode;
static inline void SoundBucket_Unlink(SoundBucketNode *node, s32 offset) {
extern u8 lbl_8034C964[];
SoundBucketNode *next = node->next;
SoundBucketNode *prev;
if(next) next->prev=node->prev;
prev=node->prev;
if(prev) prev->next=node->next;
else *(SoundBucketNode **)(lbl_8034C964+node->index*12+offset)=node->next;
}
extern u64 lbl_8029F3D0[4];
extern u32 lbl_8029F3F0[4];
extern u8 lbl_8034D034[];
extern f32 lbl_802A4590[512];
extern u32 lbl_803596F0[8];
extern u32 lbl_8029F400[8];
extern u32 lbl_8029F420[4];
extern u8 lbl_8034CBB4[];

typedef struct AudioGroupSlot { void *node; s32 id; void *data; } AudioGroupSlot;
typedef struct AudioGroupState { u8 pad[8]; s16 count; u16 padA; AudioGroupSlot slots[128]; } AudioGroupState;
typedef struct SynthMessageSlots { u8 pad[0xAC]; u32 slots[32]; } SynthMessageSlots;
typedef struct SynthMessageQueue { u8 pad[0x444]; u32 slots[4]; } SynthMessageQueue;
typedef struct SynthMsgSlot { u8 pad[0x444]; u32 value; } SynthMsgSlot;
typedef struct SampleKey { s32 data; u16 id; u16 type; u16 ref; u16 pad; } SampleKey;
typedef struct SoundKeyEntry { u16 id; s8 key; u8 pan; s16 volume; u16 pad; } SoundKeyEntry;
/* 10-byte bank table entry looked up by Sound_FindEntry / used by Sound_Start. */
typedef struct SoundEntry {
    u16 id;
    u16 progId;
    u8 group;
    u8 channel;
    u8 volume;
    u8 pan;
    u8 key;
    u8 flags;
} SoundEntry;
typedef struct AudioTableRange { u16 count; u16 start; } AudioTableRange;
typedef struct AudioTableEntry { s32 data; u16 id; u16 ref; } AudioTableEntry;
typedef struct SynthVmState { u8 pad[0xAC]; s32 regs[16]; } SynthVmState;
typedef struct SynthInsn {
    u32 flagA : 8;
    u32 storeReg : 8;
    u32 storeMode : 8;
    u32 pad0 : 8;
    union {
        struct { u32 pad1 : 8; s32 imm : 16; u32 regA : 8; } f;
        struct { u32 pad1 : 8; u32 regB : 8; u32 modeB : 8; u32 regA : 8; } b;
    } u;
} SynthInsn;
static inline u8 *FindAudioResource(void *data, u16 id, u32 offset) {
    u8 *node;
    if (data == NULL) return NULL;
    node = (u8 *)data + *(u32 *)((u8 *)data + offset);
    while (*(u32 *)node != 0xFFFFFFFF) {
        if (*(u16 *)(node + 4) == id) return node;
        node += *(u32 *)node;
    }
    return NULL;
}
typedef struct SynthStateLink { u8 pad[0xEC]; s32 next; u8 padF0[0x458 - 0xF0]; } SynthStateLink;
typedef s32 Fn80256FF0Arg;
typedef struct ThpDecodeState { f32 tables[3][64]; u8 pad[0x398]; u16 count; u16 pad69A; u8 *cursor; u32 pad6A0; u32 bits; } ThpDecodeState;
static inline u32 ThpReadByte(void) {
extern ThpDecodeState *lbl_80368950;
u8 *p=lbl_80368950->cursor;
lbl_80368950->cursor=p+1;
return *p;
}
static inline u16 ThpReadWord(void) {
extern ThpDecodeState *lbl_80368950;
u8 **cursor=&lbl_80368950->cursor;
u8 *p=*cursor;
u16 value=(p[0]<<8)|p[1];
*cursor=p+2;
return value;
}
static inline u8 SynthAllocateStream(void) {
extern u8 gSoundStreamCtrl[];
u8 i;
for(i=0;i<gSoundStreamCtrl[0];i++){
if(gSoundStreamCtrl[i*0x2c+8]==0){
u8 *p=gSoundStreamCtrl+i*0x2c;
p[8]=1;*(u32*)(p+12)=0;return i;
}
}
return 255;
}
typedef struct SynthFreeNode { u8 prev, next; u16 active; } SynthFreeNode;

/* Sound ARAM DMA slot: ARQRequest plus user completion (MusyX owner 0x2A). */
typedef struct SoundAramDmaSlot {
    s32 next;
    s32 owner;
    s32 type;
    s32 priority;
    s32 mramAddr;
    s32 aramAddr;
    s32 length;
    void *callback;
    s32 userCb;
    s32 userArg;
} SoundAramDmaSlot;
typedef struct SoundAramDmaQueue {
    SoundAramDmaSlot slots[16];
    volatile u8 next;
    volatile u8 count;
} SoundAramDmaQueue;

extern u16 lbl_80366F28;
extern char lbl_80282AE8[];
extern u8 gSoundReady;
extern u8 lbl_803689B0;
extern u8 gSoundData[]; char lbl_80282B20[];
extern u8 gSoundData[];
extern f64 lbl_8036C368;
extern u16 Ecb_8033E188[192];u16 *D_80256B30;
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
extern void (*__atexit_funcs[])(void);
extern s32 __atexit_curr_func;
extern void (*__console_exit)(void);
extern s32 __aborting;
extern void (*__stdio_exit)(void);
extern void (**_dtors)(void);
extern void _ExitProcess(void);
extern s16 lbl_802A1E90[];
extern u8 lbl_80368AAE;
extern u8 lbl_80368AAD;
extern u16 lbl_8035BF18[];
extern u32 lbl_8035C918[];

u32 fn_8026367C(void);
u16 Sound_GetChanParam(u8 arg0, u8 arg1, u8 arg2);
s32 __cvt_fp2unsigned(f32 arg0);
void Sound_SetVoiceEnvelope(u8 arg0, void *arg1, s32 arg2);
void fn_8026146C(s32 *);
void fn_8025FFC8(void *arg0, u8 arg1, s32 arg2, u8 arg3, u8 arg4, u8 arg5);
s32 Sound_LookupVid();
extern void func_80013934(s32 arg0);
extern s32 gSynthVoices;
extern u8 lbl_803548B8[1536];
extern u16 lbl_80368A08;
extern u16 lbl_8035A510[];
extern u16 lbl_8035D118[256];
extern u16 gSoundChanParamsDefault[4288];
extern f32 lbl_802831BC[];
extern f64 lbl_8036C348;
extern u16 lbl_803670C0;
extern u32 lbl_803670C8;
extern u32 lbl_800000F8;

#include "musyx/select_source.h"

typedef struct StreamQueueNode StreamQueueNode;
struct StreamQueueNode { StreamQueueNode *next, *prev; u32 time; };
typedef struct StreamTempo { u32 *start, *cursor; u32 value; u32 timing[4]; StreamQueueNode *head; u32 buffers[4]; u8 active, pad31; u16 scale, count; } StreamTempo;
static inline void StreamQueueInsert(StreamQueueNode **head, StreamQueueNode *node) {
StreamQueueNode *prev=0,*cur=*head;
while(cur){if(cur->time>node->time){node->next=cur;node->prev=prev;if(prev)prev->next=node;else *head=node;cur->prev=node;return;}prev=cur;cur=cur->next;}
node->prev=prev;if(prev)prev->next=node;else *head=node;node->next=0;
}
typedef struct StreamMsg {
    u32 unk0;   /* 0x0 */
    u32 unk4;   /* 0x4 */
    u32 unk8;   /* 0x8 */
    void *unkC; /* 0xC */
    void *unk10; /* 0x10 */
    u8 unk14;   /* 0x14 */
    u8 unk15;   /* 0x15 */
    u8 pad16[2];
} StreamMsg; /* 0x18 */

typedef struct StreamSeqEvent {
    u32 unk0; /* 0x0 */
    u8 pad4[4];
    u16 unk8; /* 0x8 */
    u16 unkA; /* 0xA */
} StreamSeqEvent; /* 0xC */

typedef struct StreamSeqChan {
    u32 unk0; /* 0x0 */
    StreamSeqEvent *unk4; /* 0x4 */
} StreamSeqChan; /* 0x8 */

typedef struct StreamChannel {
    u32 unk0; /* 0x0 */
    u32 unk4; /* 0x4 */
    u8 *unk8; /* 0x8 */
    u8 padC[0xC];
    u32 unk18; /* 0x18 */
    u8 pad1C[8];
    u32 unk24; /* 0x24 */
    u8 pad28[4];
} StreamChannel; /* 0x2C */

typedef struct StreamVoice {
    u8 unk0;
    u8 pad1[0x37];
} StreamVoice;

typedef struct StreamState {
    u8 pad0[0x124];
    StreamSeqChan seqChans[72]; /* 0x124 */
    StreamChannel channels[67]; /* 0x364 */
    u8 padEE8[0x1C];
    StreamMsg msgs[64]; /* 0xF04 */
    u8 *voices; /* 0x1504 */
    u8 pad1508[0x36];
    u8 unk153E; /* 0x153E */
    StreamVoice voiceFlags[1];
} StreamState;

extern StreamState *lbl_80368968;

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
    u8 pad124[0xE64 - 0x124];
    VidList *lists[2];
    VidList *listE6C;
    u8 padE70[0xEF0 - 0xE70];
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

extern s32 fn_802314D8(s32, s32, s32);

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern f64 lbl_8036C148;

#pragma use_lmw_stmw on
#pragma global_optimizer off
#pragma inline_depth(0)

#pragma inline_depth(8)
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma push
#pragma global_optimizer on

#pragma pop

#pragma opt_strength_reduction off
#pragma use_lmw_stmw on

#pragma use_lmw_stmw off
#pragma opt_strength_reduction on

#pragma global_optimizer off
#pragma scheduling off

#pragma scheduling reset
#pragma global_optimizer reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma optimization_level 3

#pragma optimization_level reset

static inline u32 SynthFindVoice(u32 arg0) {
    extern SynthVoice *gActiveVoices;
    extern SynthVoice *gKeyedVoices;
    SynthVoice *p;
    for (p = gKeyedVoices; p != NULL; p = p->next) {
        if (p->vid == (arg0 & 0x7FFFFFFF)) {
            return p->id | (arg0 & 0x80000000);
        }
    }
    for (p = gActiveVoices; p != NULL; p = p->next) {
        if (p->vid == (arg0 & 0x7FFFFFFF)) {
            return p->id | (arg0 & 0x80000000);
        }
    }
    return -1;
}

#pragma global_optimizer on

/* Key off a synth voice by vid: demote active to keyed list, or clear deferred key-off flag. */

#pragma dont_inline on
#pragma opt_common_subs off

#pragma opt_common_subs reset
#pragma dont_inline reset

#pragma dont_inline on

#pragma dont_inline reset

#pragma opt_strength_reduction off

#pragma opt_common_subs reset
#pragma opt_loop_invariants reset
#pragma opt_strength_reduction reset

#pragma opt_strength_reduction off
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma opt_strength_reduction reset

#pragma global_optimizer off

#pragma global_optimizer reset

void fn_80249DD0(s32 arg0) {
    void fn_80249C1C(s32, s32, s32);
    fn_80249C1C(arg0, 0, 0);
    fn_80249C1C(arg0, 1, 0);
}

void fn_80249E14(void *arg0) {
    void fn_80249C1C(void *, s32, s32);
    fn_80249C1C(arg0, 2, 0);
}

void fn_80249E3C(s32 arg0) {
    void fn_80254F00(u32);
    void fn_80248D28(s32);
    void fn_8024946C(s32);
    u32 Sound_IsHwVoiceActive(s32);
    u16 fn_8026083C(void *);
    void fn_802551F0(void *, u32);
    void fn_80261B64(s32, s32);
    void fn_80261BA0(s32);
    u32 fn_80257D7C(void *);
    u8 fn_802616EC(void);
    void fn_80244D64(s32);
    void fn_80244AE8(s32);
    void fn_80245290(s32, s32, s32);
    s32 fn_80260A7C(u32, u32, u32, u32);
    s32 fn_80260B30(u32, u32, u32, u32);
    void fn_802624D8(void);

    extern u8 lbl_8034BED0[];
    extern u8 lbl_80368979;
    extern s32 gSynthVoices;
    extern s32 lbl_803689A0;
    extern s32 lbl_8036899C;
    extern f32 lbl_8036C208;
    extern u8 lbl_80368994;
    extern u8 lbl_8036898C;
    extern u8 lbl_80368984;
    extern u8 lbl_8036897C;
    extern s32 lbl_803689B8;
    extern s32 lbl_803689BC;

    typedef void (*AudioCb)(s32, s16 *, s32);

    s16 bufA[4];
    s16 bufB[4];
    u8 *base;
    u8 *slot;
    u8 *node;
    u8 *next;
    u8 *voice;
    u8 fill;
    u8 id;
    u8 oldIdx;
    u32 bit;
    u32 i;
    u32 j;
    u32 off;
    f32 *anim;
    s32 *c14;
    AudioCb *c34;
    s32 *c54;
    AudioCb *c74;
    u8 *p94;
    u8 *p8c;
    u8 *p84;
    u8 *p7c;
    u32 sum;
    s32 kind;
    u32 *gate;

    base = lbl_8034BED0;
    gate = (u32 *)(base + 0x240);
    if (gate[1] == 0) {
        return;
    }

    fn_80254F00((u32)arg0);

    slot = base + 0xA94;
    fill = 0xFF;
    slot += lbl_80368979 * 0xC;

    node = *(u8 **)slot;
    while (node != NULL) {
        next = *(u8 **)node;
        node[9] = fill;
        id = node[8];
        off = id * 0x458;
        if (((u8 *)gSynthVoices)[off + 0x11C] == 0) {
            fn_80248D28(id);
        }
        node = next;
    }
    *(u8 **)slot = NULL;

    node = *(u8 **)(slot + 4);
    while (node != NULL) {
        next = *(u8 **)node;
        node[9] = 0xFF;
        id = node[8];
        off = id * 0x458;
        if (((u8 *)gSynthVoices)[off + 0x11C] == 0) {
            voice = (u8 *)gSynthVoices + off;
            if (Sound_IsHwVoiceActive(id) != 0 || *(u32 *)(voice + 0x34) != 0) {
                fn_802551F0(voice, (u32)(0x1F80 - (u16)fn_8026083C(voice)) >> 31);
                if ((*(u32 *)(voice + 0x118) & 0x20) != 0) {
                    *(u32 *)(voice + 0x118) = (*(u32 *)(voice + 0x118) & ~0x20u) | 0x10u;
                    fn_80261B64(id, voice[0x11F]);
                }
                if ((*(u32 *)(voice + 0x118) & 0x90) == 0x90 &&
                    (*(u32 *)(voice + 0x114) & 0x100) == 0) {
                    *(u32 *)(voice + 0x118) &= ~0x90u;
                    fn_80261BA0(id);
                    if ((*(u32 *)(voice + 0x114) & 0x200) != 0 &&
                        fn_80257D7C(voice + 0x1E8) != 0) {
                        *(u32 *)(voice + 0x114) &= ~0x200u;
                    }
                }
            }
            if (voice[0xA8] != 0) {
                voice[0xA8] = 0;
                *(u32 *)(voice + 0x220) = 0x7FFF;
            }
        }
        node = next;
    }
    *(u8 **)(slot + 4) = NULL;

    fill = 0xFF;
    node = *(u8 **)(slot + 8);
    while (node != NULL) {
        next = *(u8 **)node;
        node[9] = fill;
        id = node[8];
        off = id * 0x458;
        if (((u8 *)gSynthVoices)[off + 0x11C] == 0) {
            fn_8024946C(id);
        }
        node = next;
    }
    *(u8 **)(slot + 8) = NULL;

    oldIdx = lbl_80368979;
    lbl_80368979 = (u8)((oldIdx + 1) & 0x1F);

    if (fn_802616EC() == 0) {
        if (((u32)lbl_803689A0 | (u32)lbl_8036899C) != 0) {
            anim = (f32 *)(base + 0x454);
            i = 0;
            bit = 1;
            do {
                if (((u32)lbl_803689A0 & bit) != 0) {
                    anim[0] = anim[1] - anim[3] * (anim[1] - anim[2]);
                    anim[3] -= anim[4];
                    if (anim[3] <= lbl_8036C208) {
                        anim[0] = anim[1];
                        kind = ((s8 *)anim)[0x2C];
                        switch (kind) {
                        case 1:
                            fn_80244D64(*(s32 *)((u8 *)anim + 0x28));
                            break;
                        case 2:
                            fn_80244AE8(*(s32 *)((u8 *)anim + 0x28));
                            break;
                        case 3:
                            fn_80245290(*(s32 *)((u8 *)anim + 0x28), 0, 0);
                            break;
                        }
                        lbl_803689A0 = (s32)((u32)lbl_803689A0 & ~bit);
                        if (lbl_803689A0 == 0 && lbl_8036899C == 0) {
                            break;
                        }
                    }
                }
                if (((u32)lbl_8036899C & bit) != 0) {
                    anim[5] = anim[6] - anim[8] * (anim[6] - anim[7]);
                    anim[8] -= anim[9];
                    if (anim[8] <= lbl_8036C208) {
                        anim[5] = anim[6];
                        lbl_8036899C = (s32)((u32)lbl_8036899C & ~bit);
                        if (lbl_8036899C == 0 && lbl_803689A0 == 0) {
                            break;
                        }
                    }
                }
                i += 1;
                bit <<= 1;
                anim = (f32 *)((u8 *)anim + 0x30);
            } while (i < 0x20);
        }

        c14 = (s32 *)(base + 0xC14);
        c34 = (AudioCb *)(base + 0xC34);
        c54 = (s32 *)(base + 0xC54);
        c74 = (AudioCb *)(base + 0xC74);
        p94 = &lbl_80368994;
        p8c = &lbl_8036898C;
        p84 = &lbl_80368984;
        p7c = &lbl_8036897C;

        for (i = 0; i < 8; i++) {
            if (p94[i] != 0xFF) {
                for (j = 0; j < 4; j++) {
                    bufA[j] = (s16)fn_80260A7C((u8)i, (u8)j, p94[i], p8c[i]);
                }
                c34[i](1, bufA, c14[i]);
            }
            if (p84[i] != 0xFF) {
                for (j = 0; j < 4; j++) {
                    bufB[j] = (s16)fn_80260B30((u8)i, (u8)j, p84[i], p7c[i]);
                }
                c74[i](1, bufB, c54[i]);
            }
        }
    }

    fn_802624D8();

    sum = (u32)lbl_803689BC + (u32)arg0;
    lbl_803689B8 += (sum < (u32)lbl_803689BC);
    lbl_803689BC = (s32)sum;
}

s32 fn_802488C8(u16, u8, u8, s32, u8, s32, s32, u8, s32, s32, s32, s32, s32, s32, s32, s32);
/* Look up a sound by id and start it; 0xFF key/vol/pan use the SoundEntry defaults. */
s32 Sound_Start(s32 soundId, s32 key, s32 volume, s32 pan, s32 a4, s32 a5)
{
    SoundEntry *entry;
    s32 handle;

    handle = -1;
    entry = (SoundEntry *)Sound_FindEntry(soundId);
    if (entry != NULL) {
        if ((u8)key == 0xff) {
            key = entry->key;
        }
        if ((u8)volume == 0xff) {
            volume = entry->volume;
        }
        if ((u8)pan == 0xff) {
            pan = entry->pan;
        }
        handle = fn_802488C8(
            entry->progId,
            entry->channel,
            entry->group,
            (soundId & 0xffff) | 0x80000000,
            (u8)(key | 0x80),
            volume,
            pan,
            0xff,
            0xff,
            0,
            0,
            0xff,
            entry->flags,
            0,
            a4,
            a5);
    }
    return handle;
}

s32 fn_8024A430(u16 arg0) {
    void *Sound_FindEntry();
    s32 fn_80256738(u8, u8, s32, M2C_UNK, s32 *);
    s32 sp8;
    s32 temp_r31;
    void *temp_r3;

    temp_r3 = Sound_FindEntry();
    if (temp_r3 == NULL) {
        return 0;
    }
    temp_r31 = arg0 | 0x80000000;
    if (fn_80256738(M2C_FIELD(temp_r3, u8 *, 5), M2C_FIELD(temp_r3, u8 *, 4), temp_r31, 1, &sp8) != 0) {
        return temp_r31 == sp8;
    }
    return 0;
}

/* Walk a sound handle's voice chain and set a u8 synth control on each matching voice. */
s32 Sound_SetParamU8(s32 handle, s32 ctrl, s32 value) {
    s32 voiceOff;
    s32 ret;
    s32 vid;
    char *voice;

    ret = 0;
    vid = Sound_LookupVid();
    while ((u32)(vid + 0x10000) != 0xFFFF) {
        u8 idx = (u8)vid;
        voiceOff = idx * 0x458;
        voice = (char *)gSynthVoices + voiceOff;
        if ((u32)vid == *(u32 *)(voice + 0xF4)) {
            if (*(u64 *)(voice + 0x114) & 2) {
                Sound_WriteParamU8(ctrl, idx, *(u8 *)(voice + 0x217), value);
            } else {
                Sound_WriteParamU8(ctrl, idx, *(u8 *)(voice + 0x122), value);
            }
            ret = 1;
            vid = *(s32 *)((char *)gSynthVoices + voiceOff + 0xEC);
        } else {
            return ret;
        }
    }
    return ret;
}

/* Apply a 16-bit MIDI CC (ctrl) to all voices under handle; returns whether any were updated. */
s32 Sound_SetParamU16(s32 handle, s32 ctrl, s32 value) {
    s32 voiceOff;
    s32 ret;
    s32 vid;
    char *voice;

    ret = 0;
    vid = Sound_LookupVid();
    while ((u32)(vid + 0x10000) != 0xFFFF) {
        u8 idx = (u8)vid;
        voiceOff = idx * 0x458;
        voice = (char *)gSynthVoices + voiceOff;
        if ((u32)vid == *(u32 *)(voice + 0xF4)) {
            if (*(u64 *)(voice + 0x114) & 2) {
                fn_8025FA50(ctrl, idx, *(u8 *)(voice + 0x217), value);
            } else {
                fn_8025FA50(ctrl, idx, *(u8 *)(voice + 0x122), value);
            }
            ret = 1;
            vid = *(s32 *)((char *)gSynthVoices + voiceOff + 0xEC);
        } else {
            return ret;
        }
    }
    return ret;
}

void fn_8024A674(s32 arg0, s32 arg1) {
    M2C_UNK fn_80260060(M2C_UNK, s32, s32);
    fn_80260060(7, arg0, arg1);
    fn_80260060(0xA, arg0, arg1);
    fn_80260060(0x5B, arg0, arg1);
    fn_80260060(0x80, arg0, arg1);
    fn_80260060(0x84, arg0, arg1);
}

s32 fn_8024A6F8(void) {
    s32 Sound_LookupVid(void);
    void fn_80255100(void *);
    s32 voiceOff;
    s32 ret;
    s32 vid;
    u8 *voice;

    ret = 0;
    if (gSoundReady != 0) {
        for (vid = Sound_LookupVid(); (u32)(vid + 0x10000) != 0xFFFF;
             vid = *(s32 *)((u8 *)gSynthVoices + voiceOff + 0xEC)) {
            voice = (u8 *)gSynthVoices;
            voiceOff = (u8)vid * 0x458;
            voice += voiceOff;
            if ((u32)vid == *(u32 *)(voice + 0xF4)) {
                fn_80255100(voice);
                ret = 1;
            }
        }
    }
    return ret;
}

void fn_8024A780(u8 arg0, u16 arg1, u8 arg2, u8 arg3, s32 arg4) {
    void fn_8026146C(u32 *);
    void fn_80244D64(s32);
    void fn_80244AE8(s32);
    void fn_80245290(s32, s32, s32);
    extern f32 lbl_8034C324[];
    extern s32 lbl_803689A0;
    extern f32 lbl_8036C1D0;
    extern f32 lbl_8036C1E0;
    extern f32 lbl_8036C20C;

    u32 sp8;
    f32 f31;
    u8 *var_r29;
    u32 var_r28;
    u8 var_r4;
    s32 id;
    u8 kind;
    f32 t;
    s32 off;
    u8 *base;
    u8 *e;
    s32 *p28;
    u8 *p2c;

    sp8 = arg1;
    if (arg1 != 0) {
        fn_8026146C(&sp8);
    }
    switch ((s32)arg2) {
    case 0xFF:
        var_r29 = (u8 *)lbl_8034C324;
        var_r28 = 0;
        f31 = lbl_8036C1D0 * (f32)arg0;
        do {
            kind = var_r29[0x2D];
            if (kind == 0 || kind == 1) {
                var_r29[0x2C] = arg3;
                *(s32 *)(var_r29 + 0x28) = -1;
                if (sp8 != 0) {
                    *(f32 *)(var_r29 + 8) = *(f32 *)var_r29;
                    *(f32 *)(var_r29 + 4) = f31;
                    *(f32 *)(var_r29 + 0xC) = lbl_8036C1E0;
                    *(f32 *)(var_r29 + 0x10) = lbl_8036C20C / (f32)sp8;
                } else {
                    *(f32 *)(var_r29 + 4) = f31;
                    *(f32 *)var_r29 = f31;
                    id = *(s32 *)(var_r29 + 0x28);
                    if ((u32)(id + 0x10000) != 0xFFFFU) {
                        switch ((s32)var_r29[0x2C]) {
                        case 1:
                            fn_80244D64(id);
                            break;
                        case 2:
                            fn_80244AE8(id);
                            break;
                        case 3:
                            fn_80245290(id, 0, 0);
                            break;
                        }
                    }
                }
                lbl_803689A0 |= 1 << var_r28;
            }
            var_r28 += 1;
            var_r29 += 0x30;
        } while (var_r28 < 0x20U);
        return;
    case 0xFC:
        var_r29 = (u8 *)lbl_8034C324;
        var_r28 = 0;
        f31 = lbl_8036C1D0 * (f32)arg0;
        do {
            kind = var_r29[0x2D];
            if (kind == 2 || kind == 3) {
                var_r29[0x2C] = arg3;
                *(s32 *)(var_r29 + 0x28) = -1;
                if (sp8 != 0) {
                    *(f32 *)(var_r29 + 8) = *(f32 *)var_r29;
                    *(f32 *)(var_r29 + 4) = f31;
                    *(f32 *)(var_r29 + 0xC) = lbl_8036C1E0;
                    *(f32 *)(var_r29 + 0x10) = lbl_8036C20C / (f32)sp8;
                } else {
                    *(f32 *)(var_r29 + 4) = f31;
                    *(f32 *)var_r29 = f31;
                    id = *(s32 *)(var_r29 + 0x28);
                    if ((u32)(id + 0x10000) != 0xFFFFU) {
                        switch ((s32)var_r29[0x2C]) {
                        case 1:
                            fn_80244D64(id);
                            break;
                        case 2:
                            fn_80244AE8(id);
                            break;
                        case 3:
                            fn_80245290(id, 0, 0);
                            break;
                        }
                    }
                }
                lbl_803689A0 |= 1 << var_r28;
            }
            var_r28 += 1;
            var_r29 += 0x30;
        } while (var_r28 < 0x20U);
        return;
    case 0xFA:
        var_r4 = 2;
        goto shared;
    case 0xFB:
        var_r4 = 3;
        goto shared;
    case 0xFD:
        var_r4 = 0;
        goto shared;
    case 0xFE:
        var_r4 = 1;
    shared:
        var_r29 = (u8 *)lbl_8034C324;
        var_r28 = 0;
        f31 = lbl_8036C1D0 * (f32)arg0;
        do {
            if (var_r29[0x2D] == var_r4) {
                var_r29[0x2C] = arg3;
                *(s32 *)(var_r29 + 0x28) = -1;
                if (sp8 != 0) {
                    *(f32 *)(var_r29 + 8) = *(f32 *)var_r29;
                    *(f32 *)(var_r29 + 4) = f31;
                    *(f32 *)(var_r29 + 0xC) = lbl_8036C1E0;
                    *(f32 *)(var_r29 + 0x10) = lbl_8036C20C / (f32)sp8;
                } else {
                    *(f32 *)(var_r29 + 4) = f31;
                    *(f32 *)var_r29 = f31;
                    id = *(s32 *)(var_r29 + 0x28);
                    if ((u32)(id + 0x10000) != 0xFFFFU) {
                        switch ((s32)var_r29[0x2C]) {
                        case 1:
                            fn_80244D64(id);
                            break;
                        case 2:
                            fn_80244AE8(id);
                            break;
                        case 3:
                            fn_80245290(id, 0, 0);
                            break;
                        }
                    }
                }
                lbl_803689A0 |= 1 << var_r28;
            }
            var_r28 += 1;
            var_r29 += 0x30;
        } while (var_r28 < 0x20U);
        return;
    default:
        off = (u8)arg2 * 0x30;
        base = (u8 *)lbl_8034C324;
        e = base + off;
        e[0x2C] = arg3;
        p28 = (s32 *)(e + 0x28);
        p2c = e + 0x2C;
        *p28 = arg4;
        if (sp8 != 0) {
            *(f32 *)(base + off + 8) = *(f32 *)(base + off);
            *(f32 *)(base + off + 4) = lbl_8036C1D0 * (f32)arg0;
            *(f32 *)(base + off + 0xC) = lbl_8036C1E0;
            *(f32 *)(base + off + 0x10) = lbl_8036C20C / (f32)sp8;
        } else {
            t = lbl_8036C1D0 * (f32)arg0;
            *(f32 *)(base + off + 4) = t;
            *(f32 *)(base + off) = t;
            id = *p28;
            if ((u32)(id + 0x10000) != 0xFFFFU) {
                switch ((s32)*p2c) {
                case 1:
                    fn_80244D64(id);
                    break;
                case 2:
                    fn_80244AE8(id);
                    break;
                case 3:
                    fn_80245290(id, 0, 0);
                    break;
                }
            }
        }
        lbl_803689A0 |= 1 << (u8)arg2;
        return;
    }
}

s32 fn_8024ACB0(u8 arg0) {
    extern s32 lbl_803689A0;
    u8 *temp_r4;

    temp_r4 = (u8 *)lbl_8034C324 + arg0 * 0x30;
    if ((temp_r4[0x2D] != 4) && (lbl_803689A0 & (1 << arg0)) && (*(f32 *)(temp_r4 + 8) > *(f32 *)(temp_r4 + 4))) {
        return 1;
    }
    return 0;
}

void fn_8024AD04(u8 arg0, u8 arg1) {
    typedef struct {
        u8 pad[0x2D];
        u8 unk2D;
        u8 pad2[0x30 - 0x2E];
    } Entry;
    extern u8 gSoundReady;
    extern f32 lbl_8034C324[];
    Entry *tbl;

    if (gSoundReady != 0) {
        tbl = (Entry *)lbl_8034C324;
        tbl[arg0].unk2D = arg1;
    }
}

void fn_80255054(void *arg0);

void fn_80256FF0(Fn80256FF0Arg arg0);

s32 fn_8024AD2C(s32 arg0, s32 arg1) {
s32 offset; s32 ret; u8 *base; u32 address;
ret=0;
switch(arg0) {
case 0:
offset=(u8)arg1*0x458;
address=(u32)gSynthVoices; base=(u8*)(address+offset);
if(base[0x11c]==0) {
fn_80262510((u8)arg1); fn_80258488();
address=(u32)gSynthVoices; base=(u8*)(address+offset);
if((u32)arg1==*(u32*)(base+0xf4)) fn_80255054(base);
}
break;
case 1: fn_80256FF0((u8)arg1); break;
case 2: ret=Sound_AllocStream(arg1); break;
case 3: fn_80262510((u8)arg1); fn_80258488(); break;
}
return ret;
}

void fn_8024ADFC(s32 arg0, u32 arg1) {
    void *fn_802637A4(s32);
    void *memset(void *, s32, u32);
    void fn_80260BE4(u8 *);
    void fn_802559D8(void);
    void fn_80255A40(void);
    void fn_80256974(void);
    void fn_802576DC(void);
    void fn_80261714(void *);
    s32 fn_8024AD2C(s32, s32);
    extern u8 lbl_8034BED0[];
    extern s32 lbl_803689BC;
    extern s32 lbl_803689B8;
    extern s32 lbl_803689A4;
    extern s32 lbl_803689AC;
    extern s32 gSynthVoices;
    extern s32 lbl_803689A0;
    extern s32 lbl_8036899C;
    extern u8 lbl_80368994;
    extern u8 lbl_80368984;
    extern s8 lbl_80368979;
    extern f32 lbl_8036C208;
    extern f32 lbl_8036C1E0;

    u8 *bed;
    s32 size;
    s32 off;
    s8 n;
    u32 ctr;
    u8 *t9;
    void *p;
    s32 k;
    u8 *r7;
    u8 *r6p;
    u8 *r4p;
    u8 j;
    u8 *slot;

    bed = lbl_8034BED0;
    size = arg1 * 0x458;
    *(s32 *)(bed + 0x240) = arg0;
    lbl_803689BC = 0;
    lbl_803689B8 = 0;
    *(s32 *)(bed + 0x200) = 0x1800;
    lbl_803689A4 = 0;
    lbl_803689AC = 0;
    gSynthVoices = (s32)fn_802637A4(size);
    memset((void *)gSynthVoices, 0, size);

    n = 0;
    off = 0;
    ctr = arg1;
    if (arg1 > 0U) {
        do {
            *(s32 *)(gSynthVoices + (off + 0xF4)) = -1;
            t9 = (u8 *)(gSynthVoices + (off + 0x114));
            *(s32 *)(t9 + 4) = 0;
            *(s32 *)t9 = 0;
            *(s32 *)(gSynthVoices + (off + 0x110)) = 0;
            *((u8 *)gSynthVoices + (off + 0x10C)) = 0;
            *((u8 *)gSynthVoices + (off + 0x121)) = 0xFF;
            *(s32 *)(gSynthVoices + (off + 0x158)) = 0;
            *((u8 *)gSynthVoices + (off + 0x196)) = 0;
            *((u8 *)gSynthVoices + (off + 0x194)) = 0x80;
            *((u8 *)gSynthVoices + (off + 0x195)) = 0;
            *(s32 *)(gSynthVoices + (off + 0x184)) = 0x400000;
            *(s32 *)(gSynthVoices + (off + 0x174)) = 0x400000;
            *(s32 *)(gSynthVoices + (off + 0x188)) = 0;
            *(s32 *)(gSynthVoices + (off + 0x178)) = 0;
            *(s32 *)(gSynthVoices + (off + 0x1A4)) = 0;
            *(s32 *)(gSynthVoices + (off + 0x1A8)) = 0;
            *((u8 *)gSynthVoices + (off + 0x1BC)) = 0;
            *((u8 *)gSynthVoices + (off + 0x1BD)) = 0;
            *((u8 *)gSynthVoices + (off + 0x11C)) = 0;
            *((u8 *)gSynthVoices + (off + 0x11E)) = 0x17;
            *((u8 *)gSynthVoices + (off + 0x106)) = 0;
            *((u8 *)gSynthVoices + (off + 0x197)) = 1;
            *(s32 *)(gSynthVoices + (off + 0x1C4)) = 0;
            *(u16 *)(gSynthVoices + (off + 0x1C8)) = 0;
            *(u16 *)(gSynthVoices + (off + 0x1CA)) = 0x7FFF;
            *(s32 *)(gSynthVoices + (off + 0x1D0)) = 0;
            *(u16 *)(gSynthVoices + (off + 0x1D4)) = 0;
            *(u16 *)(gSynthVoices + (off + 0x1D6)) = 0x7FFF;
            *(s32 *)(gSynthVoices + (off + 0x140)) = 0x6400;
            *((u8 *)gSynthVoices + (off + 0x133)) = 0;
            *((u8 *)gSynthVoices + (off + 0x11F)) = 0;
            *((u8 *)gSynthVoices + (off + 8)) = n;
            *((u8 *)gSynthVoices + (off + 9)) = 0xFF;
            *((u8 *)gSynthVoices + (off + 0x14)) = n;
            *((u8 *)gSynthVoices + (off + 0x15)) = 0xFF;
            *((u8 *)gSynthVoices + (off + 0x20)) = n;
            n += 1;
            *((u8 *)gSynthVoices + (off + 0x21)) = 0xFF;
            off += 0x458;
            ctr -= 1;
        } while (ctr != 0);
    }

    p = bed + 0x454;
    k = 2;
    do {
        *(f32 *)((u8 *)p + 0) = lbl_8036C208;
        *(f32 *)((u8 *)p + 0x14) = lbl_8036C1E0;
        ((u8 *)p)[0x2D] = 4;
        *(f32 *)((u8 *)p + 0x30) = lbl_8036C208;
        *(f32 *)((u8 *)p + 0x44) = lbl_8036C1E0;
        ((u8 *)p)[0x5D] = 4;
        *(f32 *)((u8 *)p + 0x60) = lbl_8036C208;
        *(f32 *)((u8 *)p + 0x74) = lbl_8036C1E0;
        ((u8 *)p)[0x8D] = 4;
        *(f32 *)((u8 *)p + 0x90) = lbl_8036C208;
        *(f32 *)((u8 *)p + 0xA4) = lbl_8036C1E0;
        ((u8 *)p)[0xBD] = 4;
        *(f32 *)((u8 *)p + 0xC0) = lbl_8036C208;
        *(f32 *)((u8 *)p + 0xD4) = lbl_8036C1E0;
        ((u8 *)p)[0xED] = 4;
        *(f32 *)((u8 *)p + 0xF0) = lbl_8036C208;
        *(f32 *)((u8 *)p + 0x104) = lbl_8036C1E0;
        ((u8 *)p)[0x11D] = 4;
        *(f32 *)((u8 *)p + 0x120) = lbl_8036C208;
        *(f32 *)((u8 *)p + 0x134) = lbl_8036C1E0;
        ((u8 *)p)[0x14D] = 4;
        *(f32 *)((u8 *)p + 0x150) = lbl_8036C208;
        *(f32 *)((u8 *)p + 0x164) = lbl_8036C1E0;
        ((u8 *)p)[0x17D] = 4;
        *(f32 *)((u8 *)p + 0x180) = lbl_8036C208;
        *(f32 *)((u8 *)p + 0x194) = lbl_8036C1E0;
        ((u8 *)p)[0x1AD] = 4;
        *(f32 *)((u8 *)p + 0x1B0) = lbl_8036C208;
        *(f32 *)((u8 *)p + 0x1C4) = lbl_8036C1E0;
        ((u8 *)p)[0x1DD] = 4;
        *(f32 *)((u8 *)p + 0x1E0) = lbl_8036C208;
        *(f32 *)((u8 *)p + 0x1F4) = lbl_8036C1E0;
        ((u8 *)p)[0x20D] = 4;
        *(f32 *)((u8 *)p + 0x210) = lbl_8036C208;
        *(f32 *)((u8 *)p + 0x224) = lbl_8036C1E0;
        ((u8 *)p)[0x23D] = 4;
        *(f32 *)((u8 *)p + 0x240) = lbl_8036C208;
        *(f32 *)((u8 *)p + 0x254) = lbl_8036C1E0;
        ((u8 *)p)[0x26D] = 4;
        *(f32 *)((u8 *)p + 0x270) = lbl_8036C208;
        *(f32 *)((u8 *)p + 0x284) = lbl_8036C1E0;
        ((u8 *)p)[0x29D] = 4;
        *(f32 *)((u8 *)p + 0x2A0) = lbl_8036C208;
        *(f32 *)((u8 *)p + 0x2B4) = lbl_8036C1E0;
        ((u8 *)p)[0x2CD] = 4;
        *(f32 *)((u8 *)p + 0x2D0) = lbl_8036C208;
        *(f32 *)((u8 *)p + 0x2E4) = lbl_8036C1E0;
        ((u8 *)p)[0x2FD] = 4;
        p = (u8 *)p + 0x300;
        k -= 1;
    } while (k != 0);

    {
        u8 *t = bed + 0x454;
        lbl_803689A0 = 0;
        lbl_8036899C = 0;
        t[0x5FD] = 1;
        t[0x47D] = 0;
        t[0x4AD] = 0;
        t[0x4DD] = 0;
        t[0x50D] = 0;
        t[0x53D] = 0;
        t[0x56D] = 0;
        t[0x59D] = 0;
        t[0x5CD] = 0;
        *(f32 *)(t + 0x3F0) = lbl_8036C1E0;
        *(f32 *)(t + 0x420) = lbl_8036C1E0;
        fn_80260BE4(0);
    }

    r7 = bed + 0xC94;
    r6p = bed + 0xC34;
    r4p = bed + 0xC74;
    *(s32 *)(bed + 0xC34) = 0;
    (&lbl_80368994)[0] = 0xFF;
    *(s32 *)(bed + 0xC74) = 0;
    (&lbl_80368984)[0] = 0xFF;
    r7[1] = 0;
    bed[0xC94] = 0;
    *(s32 *)(r6p + 4) = 0;
    (&lbl_80368994)[1] = 0xFF;
    *(s32 *)(r4p + 4) = 0;
    (&lbl_80368984)[1] = 0xFF;
    r7[3] = 0;
    r7[2] = 0;
    *(s32 *)(r6p + 8) = 0;
    (&lbl_80368994)[2] = 0xFF;
    *(s32 *)(r4p + 8) = 0;
    (&lbl_80368984)[2] = 0xFF;
    r7[5] = 0;
    r7[4] = 0;
    *(s32 *)(r6p + 0xC) = 0;
    (&lbl_80368994)[3] = 0xFF;
    *(s32 *)(r4p + 0xC) = 0;
    (&lbl_80368984)[3] = 0xFF;
    r7[7] = 0;
    r7[6] = 0;
    *(s32 *)(r6p + 0x10) = 0;
    (&lbl_80368994)[4] = 0xFF;
    *(s32 *)(r4p + 0x10) = 0;
    (&lbl_80368984)[4] = 0xFF;
    r7[9] = 0;
    r7[8] = 0;
    *(s32 *)(r6p + 0x14) = 0;
    (&lbl_80368994)[5] = 0xFF;
    *(s32 *)(r4p + 0x14) = 0;
    (&lbl_80368984)[5] = 0xFF;
    r7[0xB] = 0;
    r7[0xA] = 0;
    *(s32 *)(r6p + 0x18) = 0;
    (&lbl_80368994)[6] = 0xFF;
    *(s32 *)(r4p + 0x18) = 0;
    (&lbl_80368984)[6] = 0xFF;
    r7[0xD] = 0;
    r7[0xC] = 0;
    *(s32 *)(r6p + 0x1C) = 0;
    (&lbl_80368994)[7] = 0xFF;
    *(s32 *)(r4p + 0x1C) = 0;
    (&lbl_80368984)[7] = 0xFF;
    r7[0xF] = 0;
    r7[0xE] = 0;
    fn_802559D8();
    fn_80255A40();
    fn_80256974();

    {
        s32 *w = (s32 *)(bed + 0xCA4);
        w[0] = 0; w[1] = 0; w[2] = 0; w[3] = 0;
        w[4] = 0; w[5] = 0; w[6] = 0; w[7] = 0;
        w[8] = 0; w[9] = 0; w[10] = 0; w[11] = 0;
        w[12] = 0; w[13] = 0; w[14] = 0; w[15] = 0;
        fn_802576DC();
    }

    j = 0;
loop:
    if (j < 0x20U) {
        slot = bed + 0xA94 + j * 0xC;
        j += 8;
        ((s32 *)slot)[0] = 0; ((s32 *)slot)[1] = 0; ((s32 *)slot)[2] = 0;
        ((s32 *)slot)[3] = 0; ((s32 *)slot)[4] = 0; ((s32 *)slot)[5] = 0;
        ((s32 *)slot)[6] = 0; ((s32 *)slot)[7] = 0; ((s32 *)slot)[8] = 0;
        ((s32 *)slot)[9] = 0; ((s32 *)slot)[10] = 0; ((s32 *)slot)[11] = 0;
        ((s32 *)slot)[12] = 0; ((s32 *)slot)[13] = 0; ((s32 *)slot)[14] = 0;
        ((s32 *)slot)[15] = 0; ((s32 *)slot)[16] = 0; ((s32 *)slot)[17] = 0;
        ((s32 *)slot)[18] = 0; ((s32 *)slot)[19] = 0; ((s32 *)slot)[20] = 0;
        ((s32 *)slot)[21] = 0; ((s32 *)slot)[22] = 0; ((s32 *)slot)[23] = 0;
        goto loop;
    }

    lbl_80368979 = 0;
    fn_80261714(fn_8024AD2C);
}

u32 fn_8024B370(void) {
    s32 Sound_FindVoiceId();
    s32 temp_r3;

    temp_r3 = Sound_FindVoiceId();
    return (u32) ((-1 - temp_r3) | (temp_r3 + 1)) >> 0x1FU;
}

void fn_8024B3A0(s32 arg0) {
    M2C_UNK fn_80244D64(s32);
    M2C_UNK Audio_Unlock();
    M2C_UNK Audio_Lock();
    Audio_Lock();
    fn_80244D64(arg0);
    Audio_Unlock();
}

void fn_8024B3D8(s32 arg0, s32 arg1) {
    M2C_UNK Sound_SetVoicePortU16(s32, s32);
    Audio_Lock();
    Sound_SetVoicePortU16(arg0, arg1);
    Audio_Unlock();
}

void fn_8024B420(s32 arg0) {
    M2C_UNK Sound_VoiceKeyOff(s32);
    Audio_Lock();
    Sound_VoiceKeyOff(arg0);
    Audio_Unlock();
}

void fn_8024B458(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK fn_80245290(s32, s32, s32);
    Audio_Lock();
    fn_80245290(arg0, arg1, arg2);
    Audio_Unlock();
}

void fn_8024B4B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Audio_Lock();
    fn_8024534C(arg0, arg1, arg2, arg3);
    Audio_Unlock();
}

s32 fn_8024B518(s32 arg0, s32 arg1, s32 arg2, s32 arg3, M2C_UNK arg_sp0) {
    s32 Audio_Lock(void);
    s32 Sound_FindVoiceId(s32);
    s32 Sound_WriteParamU8(s32, s32, u8, s32);
    s32 Audio_Unlock(void);
    s32 var_r31;
    s32 temp_r3;

    var_r31 = 0;
    Audio_Lock();
    temp_r3 = Sound_FindVoiceId(arg0);
    if ((u32) (temp_r3 + 0x10000) != 0xFFFFU) {
        Sound_WriteParamU8(arg2, arg1, (u8) temp_r3, arg3);
        var_r31 = 1;
    }
    Audio_Unlock();
    return var_r31;
}

u16 fn_8024B594(s32 arg0, s32 arg1) {
    extern u8 lbl_8034BDD0[];
    return *(u16 *)(lbl_8034BDD0 + ((arg0 & 0xFF) << 5) + ((arg1 & 0xFF) << 1));
}

s32 fn_8024B5B0(u32 arg0)
{
    extern SynthVoice *gKeyedVoices;
    SynthVoice *head;
    SynthVoice *sv;
    VidList *vl;
    s32 n;

    head = gKeyedVoices;
    n = 8;
    do {
        sv = head;
        while (sv != NULL) {
            vl = *(VidList **)((u8 *)sv + 0xE64);
            while (vl != NULL) {
                if (vl->vid == arg0) {
                    return (s32)sv->vid;
                }
                vl = vl->next;
            }
            vl = *(VidList **)((u8 *)sv + 0xE68);
            while (vl != NULL) {
                if (vl->vid == arg0) {
                    return (s32)sv->vid;
                }
                vl = vl->next;
            }
            vl = *(VidList **)((u8 *)sv + 0xE6C);
            while (vl != NULL) {
                if (vl->vid == arg0) {
                    return (s32)sv->vid;
                }
                vl = vl->next;
            }
            sv = sv->next;
        }
    } while (--n != 0);
    return -1;
}

s32 Snd_SetParamU8(s32 arg0, s32 arg1, s32 arg2) {
    s32 Sound_SetParamU8(s32, s32, s32);
    s32 temp_r31;

    Audio_Lock();
    temp_r31 = Sound_SetParamU8(arg0, arg1, arg2);
    Audio_Unlock();
    return temp_r31;
}

s32 Snd_SetParamU16(s32 arg0, s32 arg1, s32 arg2) {
    s32 Sound_SetParamU16(s32, s32, s32);
    s32 temp_r31;

    Audio_Lock();
    temp_r31 = Sound_SetParamU16(arg0, arg1, arg2);
    Audio_Unlock();
    return temp_r31;
}

s32 fn_8024B714(s32 arg0) {
    s32 fn_8024A6F8(s32);
    s32 temp_r31;

    Audio_Lock();
    temp_r31 = fn_8024A6F8(arg0);
    Audio_Unlock();
    return temp_r31;
}

s32 Snd_Start(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 Sound_Start(s32, s32, s32, s32, s32, u8);
    void Audio_Lock(void);
    void Audio_Unlock(void);
    extern u8 lbl_8034CB64[];
    s32 temp;

    Audio_Lock();
    temp = Sound_Start(arg0, 0xFF, arg1, arg2, arg3, lbl_8034CB64[((arg3 & 0xFF) << 1) + 1]);
    Audio_Unlock();
    return temp;
}

s32 fn_8024B7DC(s32 arg0) {
    s32 Sound_LookupVid(s32);
    void Audio_Lock(void);
    void Audio_Unlock(void);
    s32 var_r31;

    var_r31 = arg0;
    Audio_Lock();
    if ((u32)(Sound_LookupVid(var_r31) + 0x10000) == 0xFFFFU) {
        var_r31 = -1;
    }
    Audio_Unlock();
    return var_r31;
}

/* Map distance into synth vol param 0x1F (inverted 80..16000 -> 16383..0) and enable flag 0x4F. */
void Sound_SetDistanceVol(s32 handle, s32 enable, s32 distance) {
#pragma dont_inline on
    if (enable == 1) {
        Audio_Lock();
        Sound_SetParamU16(handle, 0x1F, (s32)(16383.0f * (1.0f - (f32)(u32)(distance - 0x50) / 15920.0f)));
        Audio_Unlock();
        Audio_Lock();
        Sound_SetParamU8(handle, 0x4F, 0x7F);
        Audio_Unlock();
    } else {
        Audio_Lock();
        Sound_SetParamU8(handle, 0x4F, 0);
        Audio_Unlock();
    }
}

void fn_8024B8EC(s32 arg0, s32 arg1, s32 arg2) {
#pragma dont_inline reset
    M2C_UNK fn_8024A780(s32, s32, s32, M2C_UNK, M2C_UNK);
    Audio_Lock();
    fn_8024A780(arg0, arg1, arg2, 0, -1);
    Audio_Unlock();
}

#pragma global_optimizer off
#pragma optimization_level 2
void fn_8024B94C(s32 arg0)
{
    void fn_802624F8(void);
    void fn_8024C84C(void);

    extern u32 lbl_803689A4;
    extern u8 gSoundData[];
    extern s32 gSynthVoices;

    u32 oldFlags;

    oldFlags = lbl_803689A4;

    switch (arg0) {
    case 0:
        lbl_803689A4 = oldFlags | 1;
        lbl_803689A4 = lbl_803689A4 & ~2;
        fn_802624F8();
        break;
    case 1:
        lbl_803689A4 = oldFlags & ~1;
        lbl_803689A4 = oldFlags & ~3;
        fn_802624F8();
        break;
    case 2:
        lbl_803689A4 = oldFlags & ~1;
        lbl_803689A4 = lbl_803689A4 | 2;
        fn_802624F8();
        break;
    }

    if (oldFlags != lbl_803689A4) {
        u32 i;
        u32 table;
        u32 offset;
        u32 base;
        u32 off;
        u32 *p1;
        u32 w0;
        u32 w1;

        for (i = 0, table = (u32)gSoundData, offset = 0; i < *(u8 *)(table + 0x210);) {
            base = (u32)gSynthVoices;
            off = offset + 0x114;
            offset = offset + 0x458;
            i = i + 1;
            p1 = (u32 *)(base + off);
            base = base + off;
            w0 = *p1;
            w1 = *(p1 + 1);
            *(volatile u32 *)(base + 4) = w1;
            *(u32 *)base = w0 | 0x2000;
        }
        fn_8024C84C();
    }
}

void fn_8024BA38(u8 arg0,u32 arg1,s32 arg2,u8 arg3,u32 arg4,u32 arg5,s32 arg6,u8 arg7,u32 arg8) {
void Audio_Lock(void);void Audio_Unlock(void);
void fn_8026212C(u8,s32,s32,s32,s32);
u32 Sound_FindVoiceId(u32);
extern u8 lbl_80368994[8],lbl_8036898C[8],lbl_80368984[8],lbl_8036897C[8];
extern u32 lbl_8034CB04[8],lbl_8034CB44[8];
extern s32 lbl_8034CAE4[8],lbl_8034CB24[8];
Audio_Lock();
if(arg1!=0) {
lbl_80368994[arg0]=arg3;
if(arg3!=255) {
lbl_8036898C[arg0]=Sound_FindVoiceId(arg4);
lbl_8034CB04[arg0]=arg1;
lbl_8034CAE4[arg0]=arg2;
}
} else {
lbl_8034CB04[arg0]=0;
lbl_80368994[arg0]=255;
}
if(arg5!=0) {
lbl_80368984[arg0]=arg7;
if(arg7!=255) {
lbl_8036897C[arg0]=Sound_FindVoiceId(arg8);
lbl_8034CB44[arg0]=arg5;
lbl_8034CB24[arg0]=arg6;
}
} else {
lbl_8034CB44[arg0]=0;
lbl_80368984[arg0]=255;
}
fn_8026212C(arg0,arg1,arg2,arg5,arg6);
Audio_Unlock();
}

#pragma optimization_level 2
void fn_8024BB90(void) {
    extern u8 gSoundData[];
    extern u8 gSoundSlots[];
    extern u8 lbl_803689CD;
    extern u8 lbl_803689CC;
    extern s32 lbl_803689C0;
    extern u8 lbl_803689C4[8];
    u8 *data;
    u8 *slot;
    u8 *p;
    s32 count;
    s32 i;
    u8 zero;

    data = gSoundData;
    zero = 0;
    i = 0;
    lbl_803689CD = zero;
    count = data[0x210];
    lbl_803689CC = 3;
    if (count > 0) {
        if (count > 8) {
            slot = gSoundSlots;
            for (; i < count; i += 8) {
                slot[0xC] = zero;
                slot[0x74] = zero;
                slot[0xDC] = zero;
                slot[0x144] = zero;
                slot[0x1AC] = zero;
                slot[0x214] = zero;
                slot[0x27C] = zero;
                slot[0x2E4] = zero;
                slot += 0x340;
            }
        }
        count = data[0x210];
        slot = gSoundSlots + (i * 0x68);
        for (; i < count; i++) {
            slot[0xC] = 0;
            slot += 0x68;
        }
    }
    p = lbl_803689C4;
    lbl_803689C0 = 0;
    *p = 0;
    *(s32 *)(p + 4) = 0;
}
#pragma optimization_level reset
void fn_8024BC58(void *arg0) {
    M2C_UNK fn_80261E6C(s32, M2C_UNK, s32, s32, f32, f32, f32, f32);
    extern f32 lbl_8036C228;
    fn_80261E6C(M2C_FIELD(arg0, s32 *, 0x4C), 0, M2C_FIELD(arg0, u8 *, 0x5A) << 0x10, M2C_FIELD(arg0, u8 *, 0x5B) << 0x10, lbl_8036C228 * (f32)(u32) M2C_FIELD(arg0, u8 *, 0x59), lbl_8036C228 * (f32)(u32) M2C_FIELD(arg0, u8 *, 0x5C), lbl_8036C228 * (f32)(u32) M2C_FIELD(arg0, u8 *, 0x5D), lbl_8036C228);
}

void fn_8024BCE4(void) {
    void fn_80261730(s32, s32, void *, s32, s32, s32, s32, s32);
    void fn_80261B50(s32, u8);
    void fn_80261B64(s32, u8);
    void fn_80261BC8(s32, s32);
    void fn_80261D90(s32, s32, u16, u16);
    void fn_80261E6C(s32, s32, s32, s32, f32, f32, f32);
    u32 fn_80262154(s32);
    void fn_80262200(void *, s32, s32, u8, s32, s32);
    s32 fn_802622D0(u8);
    extern u8 gSoundSlots[];
    extern u8 gSoundData[];
    extern s32 gSynthVoices;
    extern u8 lbl_803689CC;
    extern u8 lbl_803689CD;
    extern f32 lbl_8036C228;
    extern f32 lbl_8036C238;

    u8 *slot;
    u32 i;
    u32 lim;
    s32 sp8[8];
    u32 pos;
    u32 need;
    u8 mode;

    if (lbl_803689CD != 0) {
        lbl_803689CD = (u8)(lbl_803689CD - 1);
        return;
    }
    lbl_803689CD = lbl_803689CC;
    slot = gSoundSlots;
    lim = gSoundData[0x210];
    for (i = 0; i < lim; slot += 0x68, i++) {
        mode = slot[0xC];
        if (mode == 1) {
            sp8[0] = *(s32 *)(slot + 0x54) | 0x40000000;
            sp8[1] = fn_802622D0(slot[0xE]);
            sp8[3] = 0;
            sp8[4] = *(s32 *)(slot + 0x18);
            sp8[5] = 0;
            sp8[6] = *(s32 *)(slot + 0x18);
            if (slot[0xD] == 0) {
                ((u8 *)&sp8[0])[0x1C] = 2;
            } else if (slot[0xD] == 1) {
                *(u8 **)((u8 *)&sp8[0] + 8) = slot + 0x24;
                ((u8 *)&sp8[0])[0x1C] = 4;
                fn_80261B50(*(s32 *)(slot + 0x4C), slot[0xF]);
                slot[0x26] = slot[0xF];
                slot[0x27] = slot[0xF];
            }
            {
                s32 v = *(s32 *)(slot + 0x4C);
                fn_80261730(v, 0xFFFF, sp8, 1, -1,
                            *(s32 *)((u8 *)gSynthVoices + v * 0x458 + 0xF4), 1, 1);
            }
            if (slot[0x61] == 0) {
                fn_80261D90(*(s32 *)(slot + 0x4C), 0, 0, 0);
            } else {
                fn_80261D90(*(s32 *)(slot + 0x4C), 1, *(u16 *)(slot + 0x62), *(u16 *)(slot + 0x64));
            }
            fn_80261BC8(*(s32 *)(slot + 0x4C),
                        (s32)(lbl_8036C238 * ((f32)*(u32 *)(slot + 0x54) / (f32)*(u32 *)gSoundData)));
            fn_80261E6C(*(s32 *)(slot + 0x4C), 0, (s32)slot[0x5A] << 16, (s32)slot[0x5B] << 16,
                        lbl_8036C228 * (f32)slot[0x59], lbl_8036C228 * (f32)slot[0x5C],
                        lbl_8036C228 * (f32)slot[0x5D]);
            fn_80261B64(*(s32 *)(slot + 0x4C), slot[0x60]);
            slot[0xC] = 2;
            if ((*(u32 *)(slot + 8) & 0x20000) == 0) {
                fn_80262200(*(void **)(slot + 0x14), 0, *(s32 *)(slot + 0x1C), slot[0xE], 0, 0);
            }
        } else if (mode == 2) {
            need = fn_80262154(*(s32 *)(slot + 0x4C));
            if (slot[0xD] == 1) {
                need = ((need * 0x24924925U) >> 3) * 0xE;
            }
            pos = *(u32 *)(slot + 0x20);
            if (pos != need) {
            }
        }
    }
}

#pragma optimization_level reset
#pragma global_optimizer on
void fn_8024C5C8(void) {

}

#pragma optimization_level 3
void fn_8024C5CC(u32 arg0) {
    extern u8 gSoundSlots[];
    extern void fn_80256DD8(u32);
    register u8 *slot = gSoundSlots;
    s32 i;
    u32 id;

    for (i = 0x40; i != 0; i--) {
        if (slot[0xC] == 1 || slot[0xC] == 2) {
            id = *(u32 *)(slot + 0x4C);
            if (id == arg0) {
                if (slot[0xC] == 2) {
                    fn_80256DD8(id);
                }
                slot[0xC] = 3;
                (*(void (**)(s32, s32, s32, s32, s32))(slot + 0x10))(
                    0, 0, 0, 0, *(s32 *)(slot + 0x50));
                return;
            }
        }
        slot += 0x68;
    }
}
#pragma optimization_level reset
/* Find the index of an active sound slot with the given instance id, or -1. */
s32 Sound_FindSlotById(u32 id)
{
  extern u8 gSoundSlots[];
  u8 *entry;
  s32 i;
  u32 slotId;
  entry = gSoundSlots;
  for (i = 0; i < 64; i++)
  {
    if ((*((u8 *) (entry + 0xC))) != 0)
    {
      if ((slotId = *((u32 *) (entry + 4))) == id)
      {
        return i;
      }
    }
    entry += 0x68;
  }

  return -1;
}

void fn_8024C7C4(s8 *arg0, s8 *arg1) {
    extern s32 lbl_803689A4;
    if (lbl_803689A4 & 1) {
        *arg0 = 0x40;
        *arg1 = 0;
        return;
    }
    if (!(lbl_803689A4 & 2)) {
        *arg1 = 0;
    }
}

void fn_8024C7F8(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    M2C_FIELD(arg0, s8 *, 0x59) = arg1;
    M2C_FIELD(arg0, s8 *, 0x5C) = arg2;
    M2C_FIELD(arg0, s8 *, 0x5D) = arg3;
}

void fn_8024C808(void *arg0, u8 arg1, u8 arg2, u8 arg3,
                 u8 arg4, u8 arg5)
{
    extern u32 lbl_803689A4;
    u32 flags;

    *(u8 *)((u8 *)arg0 + 0x59) = arg1;
    *(u8 *)((u8 *)arg0 + 0x5C) = arg4;
    *(u8 *)((u8 *)arg0 + 0x5D) = arg5;
    *(u8 *)((u8 *)arg0 + 0x5E) = arg2;
    *(u8 *)((u8 *)arg0 + 0x5F) = arg3;

    flags = lbl_803689A4;
    if ((flags & 1) != 0) {
        arg2 = 0x40;
        arg3 = 0;
    } else if ((flags & 2) == 0) {
        arg3 = 0;
    }

    *(u8 *)((u8 *)arg0 + 0x5A) = arg2;
    *(u8 *)((u8 *)arg0 + 0x5B) = arg3;
}

void fn_8024C84C(u32 arg0) {
extern u8 gSoundSlots[],gSoundData[];
extern u32 lbl_803689A4;
extern f32 lbl_8036C228;
void Audio_Lock(void); void Audio_Unlock(void);
void fn_80261E6C(s32,s32,s32,s32,f32,f32,f32);
u8 *slot;
u32 i;
Audio_Lock();
for(i=0;i<gSoundData[0x210];i++) {
slot=&gSoundSlots[i*0x68];
if(slot[0xC]) {
slot[0x5A]=slot[0x5E]; slot[0x5B]=slot[0x5F];
if(lbl_803689A4&1) {slot[0x5A]=0x40;slot[0x5B]=0;}
else if(!(lbl_803689A4&2)) slot[0x5B]=0;
if(slot[0xC]!=3) fn_80261E6C(*(s32*)(slot+0x4C),0,slot[0x5A]<<16,slot[0x5B]<<16,lbl_8036C228*(f32)slot[0x59],lbl_8036C228*(f32)slot[0x5C],lbl_8036C228*(f32)slot[0x5D]);
}
}
Audio_Unlock();
}

#pragma global_optimizer off
u32 fn_8024C97C(s8 a,s32 b,s32 c,s32 d,s8 e,s8 f,s8 g,s8 h,u8 p,u8 q,u32 flags,s32 data,s32 extra,s16 *coef){
extern u8 gSoundSlots[],lbl_803689C4[8];extern u32 lbl_803689C0,lbl_803689A4;
void Audio_Lock(void);void Audio_Unlock(void);s32 fn_8024CE1C(s32,s32);u32 fn_8024E100(u32);void fn_80261C98(s32,void*,void*);u32 fn_80262290(s32);
u8 *state,*slot,*scan,*base;u32 next,id,j,index; s32 offset,size,k;u8 voice; s8 pan,span;
Audio_Lock();
base=gSoundSlots;scan=base;for(index=0;index<64;scan+=0x68,index++){if(scan[0xc]==0)break;}
if(index!=64){
next=lbl_803689C0;
do{
id=next++;if(id==0xffffffffU)id=next++;
scan=base;for(j=0;j<64;scan+=0x68,j++){if(scan[0xc]&&id==*(u32*)(scan+4))break;}
}while(j!=64);
offset=index*0x68;lbl_803689C0=next;slot=gSoundSlots+offset;
*(u32*)(slot+4)=id;*(u32*)(slot+8)=flags;
size=fn_8024CE1C(c,flags);
slot=gSoundSlots+offset;*(s32*)(slot+0x14)=b;*(s32*)(slot+0x18)=c;*(s32*)(slot+0x1c)=size;*(s32*)(slot+0x10)=data;*(s32*)(slot+0x4c)=-1;
if(flags&1){if(coef){*(s16*)(slot+44)=coef[0];*(s16*)(slot+46)=coef[1];*(s16*)(slot+48)=coef[2];*(s16*)(slot+50)=coef[3];*(s16*)(slot+52)=coef[4];*(s16*)(slot+54)=coef[5];*(s16*)(slot+56)=coef[6];*(s16*)(slot+58)=coef[7];*(s16*)(slot+60)=coef[8];*(s16*)(slot+62)=coef[9];*(s16*)(slot+64)=coef[10];*(s16*)(slot+66)=coef[11];*(s16*)(slot+68)=coef[12];*(s16*)(slot+70)=coef[13];*(s16*)(slot+72)=coef[14];*(s16*)(slot+74)=coef[15];*(s16*)(slot+0x24)=8;} (gSoundSlots+offset)[0xd]=1;}else slot[0xd]=0;
slot=gSoundSlots+offset;*(s32*)(slot+0x54)=d;slot[0x60]=q;slot[0x58]=a;slot[0x59]=e;slot[0x5c]=h;slot[0x5d]=p;slot[0x5e]=f;slot[0x5f]=g;
span=g;pan=f;
if(lbl_803689A4&1){pan=0x40;span=0;}else if(!(lbl_803689A4&2))span=0;
slot=gSoundSlots+offset;slot[0x5a]=pan;slot[0x5b]=span;slot[0x61]=lbl_803689C4[0];
if(lbl_803689C4[0])fn_80261C98(*(s32*)(lbl_803689C4+4),slot+0x62,slot+0x64);
else{*(s16*)(slot+0x64)=0;*(s16*)(slot+0x62)=0;}
slot=gSoundSlots+offset;*(s32*)(slot+0x50)=extra;*(s32*)(gSoundSlots+offset)=-1;slot[0xc]=3;state=slot+0xc;
voice=(u8)fn_80262290(size);(gSoundSlots+offset)[0xe]=voice;
if(voice!=0xff){if(!(flags&0x10000)&&!fn_8024E100(id))id=-1;}else id=-1;
if(id==0xffffffffU)*state=0;
}else id=-1;
Audio_Unlock();return id;
}
#pragma global_optimizer on
s32 fn_8024CE1C(s32 arg0, s32 arg1)
{
    u32 value;
    u32 result;

    if (arg1 & 1) {
        value = (u32)(arg0 + 0xD);

        result = (value / 7) << 2;
        result &= ~7U;

        return (result + 0x1F) & ~31U;
    }

    return ((arg0 << 1) + 0x1F) & ~31;
}

#pragma global_optimizer off
void fn_8024CE60(u32 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4)
{
    extern u8 gSoundSlots[];
    extern u32 lbl_803689A4;
    extern f32 lbl_8036C228;
    extern f64 lbl_8036C230;
    void Audio_Lock(void);
    void Audio_Unlock(void);
    void fn_80261E6C(s32, s32, s32, s32, f32, f32, f32);
    void fn_8024C7F8(void *, u8, u8, u8);
    void fn_8024C7C4(u8 *, u8 *);
    s32 Sound_FindSlotById(u32);
    void fn_8024C808(void *, u8, u8, u8, u8, u8);
    void fn_8024BC58(void *);

    u8 sp9;
    u8 sp8;
    u8 *base;
    u8 *scan;
    u8 *slot;
    u8 *typep;
    s32 index;
    s32 offset;
    u32 parent;
    u8 pan;
    u8 span;
    s32 i;

    Audio_Lock();
    base = gSoundSlots;
    scan = base;
    index = 0;
    for (i = 0; i < 64; i++, scan += 0x68) {
        if (scan[0xC] != 0 && *(u32 *)(scan + 4) == arg0) {
            index = i;
            goto found1;
        }
    }
    index = -1;
found1:
    if ((u32)(index + 0x10000) != 0xFFFFU) {
        offset = index * 0x68;
        slot = gSoundSlots + offset;
        slot[0x59] = arg1;
        slot[0x5C] = arg4;
        pan = arg2;
        span = arg3;
        slot[0x5D] = 0;
        slot[0x5E] = arg2;
        slot[0x5F] = arg3;
        if (lbl_803689A4 & 1) {
            span = 0;
            pan = 0x40;
        } else if (!(lbl_803689A4 & 2)) {
            span = 0;
        }
        slot = gSoundSlots + offset;
        slot[0x5A] = pan;
        typep = gSoundSlots + 0xC;
        slot[0x5B] = span;
        if (typep[offset] == 2) {
            slot = gSoundSlots + offset;
            fn_80261E6C(
                *(s32 *)(slot + 0x4C),
                0,
                slot[0x5A] << 16,
                slot[0x5B] << 16,
                lbl_8036C228 * (f32)slot[0x59],
                lbl_8036C228 * (f32)slot[0x5C],
                lbl_8036C228 * (f32)slot[0x5D]);
        }
        parent = *(u32 *)(gSoundSlots + offset);
        if ((u32)(parent + 0x10000) != 0xFFFFU) {
            Audio_Lock();
            scan = base;
            index = 0;
            for (i = 0; i < 64; i++, scan += 0x68) {
                if (scan[0xC] != 0 && *(u32 *)(scan + 4) == parent) {
                    index = i;
                    goto found2;
                }
            }
            index = -1;
found2:
            if ((u32)(index + 0x10000) != 0xFFFFU) {
                offset = index * 0x68;
                sp8 = arg3;
                slot = gSoundSlots + offset;
                sp9 = arg2;
                fn_8024C7F8(slot, arg1, arg4, 0);
                slot[0x5E] = sp9;
                slot[0x5F] = sp8;
                fn_8024C7C4(&sp9, &sp8);
                slot[0x5A] = sp9;
                slot[0x5B] = sp8;
                if (typep[offset] == 2) {
                    fn_80261E6C(
                        *(s32 *)(slot + 0x4C),
                        0,
                        slot[0x5A] << 16,
                        slot[0x5B] << 16,
                        lbl_8036C228 * (f32)slot[0x59],
                        lbl_8036C228 * (f32)slot[0x5C],
                        lbl_8036C228 * (f32)slot[0x5D]);
                }
                parent = *(u32 *)slot;
                if ((u32)(parent + 0x10000) != 0xFFFFU) {
                    Audio_Lock();
                    index = Sound_FindSlotById(parent);
                    if ((u32)(index + 0x10000) != 0xFFFFU) {
                        offset = index * 0x68;
                        slot = gSoundSlots + offset;
                        fn_8024C808(slot, arg1, arg2, arg3, arg4, 0);
                        if (typep[offset] == 2) {
                            fn_8024BC58(slot);
                        }
                        if ((u32)(*(u32 *)slot + 0x10000) != 0xFFFFU) {
                            fn_8024CE60(*(u32 *)slot, arg1, arg2, arg3, arg4);
                        }
                    }
                    Audio_Unlock();
                }
                Audio_Unlock();
            }
            Audio_Unlock();
        }
    }
    Audio_Unlock();
}

void Sound_SetVolume(u32 arg0, u32 arg1) {
    extern u8 gSoundSlots[];
    extern u8 gSoundData[];
    extern f64 lbl_8036C230;
    extern f32 lbl_8036C238;
    void Audio_Lock(void);
    void Audio_Unlock(void);
    void fn_80261BC8(s32, s32);
    s32 Sound_FindSlotById(u32);

    u8 *base;
    u8 *scan;
    u8 *valp;
    u8 *typep;
    s32 index;
    s32 offset;
    u32 parent;
    s32 i;
    f32 f1;

    Audio_Lock();
    base = gSoundSlots;
    scan = base;
    index = 0;
    for (i = 0; i < 64; i++, scan += 0x68) {
        if (scan[0xC] != 0 && *(u32 *)(scan + 4) == arg0) {
            index = i;
            goto found1;
        }
    }
    index = -1;
found1:
    if ((u32)(index + 0x10000) != 0xFFFFU) {
        offset = index * 0x68;
        valp = gSoundSlots + 0x54;
        typep = gSoundSlots + 0xC;
        *(u32 *)(valp + offset) = arg1;
        if (typep[offset] == 2) {
            f1 = lbl_8036C238 * (f32)arg1;
            fn_80261BC8(*(s32 *)(gSoundSlots + offset + 0x4C), (s32)(f1 / (f32)*(u32 *)gSoundData));
        }
        parent = *(u32 *)(gSoundSlots + offset);
        if ((u32)(parent + 0x10000) != 0xFFFFU) {
            Audio_Lock();
            scan = base;
            index = 0;
            for (i = 0; i < 64; i++, scan += 0x68) {
                if (scan[0xC] != 0 && *(u32 *)(scan + 4) == parent) {
                    index = i;
                    goto found2;
                }
            }
            index = -1;
found2:
            if ((u32)(index + 0x10000) != 0xFFFFU) {
                offset = index * 0x68;
                *(u32 *)(valp + offset) = arg1;
                if (typep[offset] == 2) {
                    f1 = lbl_8036C238 * (f32)arg1;
                    fn_80261BC8(*(s32 *)(gSoundSlots + offset + 0x4C), (s32)(f1 / (f32)*(u32 *)gSoundData));
                }
                parent = *(u32 *)(gSoundSlots + offset);
                if ((u32)(parent + 0x10000) != 0xFFFFU) {
                    Audio_Lock();
                    scan = base;
                    index = 0;
                    for (i = 0; i < 64; i++, scan += 0x68) {
                        if (scan[0xC] != 0 && *(u32 *)(scan + 4) == parent) {
                            index = i;
                            goto found3;
                        }
                    }
                    index = -1;
found3:
                    if ((u32)(index + 0x10000) != 0xFFFFU) {
                        offset = index * 0x68;
                        *(u32 *)(valp + offset) = arg1;
                        if (typep[offset] == 2) {
                            f1 = lbl_8036C238 * (f32)arg1;
                            fn_80261BC8(*(s32 *)(gSoundSlots + offset + 0x4C), (s32)(f1 / (f32)*(u32 *)gSoundData));
                        }
                        parent = *(u32 *)(gSoundSlots + offset);
                        if ((u32)(parent + 0x10000) != 0xFFFFU) {
                            Audio_Lock();
                            index = Sound_FindSlotById(parent);
                            if ((u32)(index + 0x10000) != 0xFFFFU) {
                                offset = index * 0x68;
                                *(u32 *)(valp + offset) = arg1;
                                if (typep[offset] == 2) {
                                    f1 = lbl_8036C238 * (f32)arg1;
                                    fn_80261BC8(*(s32 *)(gSoundSlots + offset + 0x4C), (s32)(f1 / (f32)*(u32 *)gSoundData));
                                }
                                parent = *(u32 *)(gSoundSlots + offset);
                                if ((u32)(parent + 0x10000) != 0xFFFFU) {
                                    Sound_SetVolume(parent, arg1);
                                }
                            }
                            Audio_Unlock();
                        }
                        Audio_Unlock();
                    }
                    Audio_Unlock();
                }
                Audio_Unlock();
            }
        }
    }
    Audio_Unlock();
}

void fn_8024DA2C(u32 arg0)
{
    extern u8 gSoundSlots[];
    void Audio_Lock(void);
    void Audio_Unlock(void);
    void fn_8024E758(u32);
    void fn_802622B0(u8);
    s32 Sound_FindSlotById(u32);

    u8 *base;
    u8 *scan;
    u8 *voicep;
    s32 index;
    s32 off1;
    s32 off2;
    s32 off3;
    s32 off4;
    s32 off5;
    u32 parent;
    s32 i;

    Audio_Lock();
    base = gSoundSlots;
    scan = base;
    index = 0;
    for (i = 0; i < 64; i++, scan += 0x68) {
        if (scan[0xC] != 0 && *(u32 *)(scan + 4) == arg0) {
            index = i;
            goto found1;
        }
    }
    index = -1;
found1:
    if ((u32)(index + 0x10000) != 0xFFFFU) {
        fn_8024E758(arg0);
        off1 = index * 0x68;
        voicep = gSoundSlots + 0xE;
        fn_802622B0(voicep[off1]);
        parent = *(u32 *)(gSoundSlots + off1);
        if ((u32)(parent + 0x10000) != 0xFFFFU) {
            Audio_Lock();
            scan = base;
            index = 0;
            for (i = 0; i < 64; i++, scan += 0x68) {
                if (scan[0xC] != 0 && *(u32 *)(scan + 4) == parent) {
                    index = i;
                    goto found2;
                }
            }
            index = -1;
found2:
            if ((u32)(index + 0x10000) != 0xFFFFU) {
                fn_8024E758(parent);
                off2 = index * 0x68;
                fn_802622B0(voicep[off2]);
                parent = *(u32 *)(gSoundSlots + off2);
                if ((u32)(parent + 0x10000) != 0xFFFFU) {
                    Audio_Lock();
                    scan = base;
                    index = 0;
                    for (i = 0; i < 64; i++, scan += 0x68) {
                        if (scan[0xC] != 0 && *(u32 *)(scan + 4) == parent) {
                            index = i;
                            goto found3;
                        }
                    }
                    index = -1;
found3:
                    if ((u32)(index + 0x10000) != 0xFFFFU) {
                        fn_8024E758(parent);
                        off3 = index * 0x68;
                        fn_802622B0(voicep[off3]);
                        parent = *(u32 *)(gSoundSlots + off3);
                        if ((u32)(parent + 0x10000) != 0xFFFFU) {
                            Audio_Lock();
                            index = 0;
                            for (i = 0; i < 64; i++, base += 0x68) {
                                if (base[0xC] != 0 && *(u32 *)(base + 4) == parent) {
                                    index = i;
                                    goto found4;
                                }
                            }
                            index = -1;
found4:
                            if ((u32)(index + 0x10000) != 0xFFFFU) {
                                fn_8024E758(parent);
                                off4 = index * 0x68;
                                fn_802622B0(voicep[off4]);
                                parent = *(u32 *)(gSoundSlots + off4);
                                if ((u32)(parent + 0x10000) != 0xFFFFU) {
                                    Audio_Lock();
                                    index = Sound_FindSlotById(parent);
                                    if ((u32)(index + 0x10000) != 0xFFFFU) {
                                        fn_8024E758(parent);
                                        off5 = index * 0x68;
                                        fn_802622B0(voicep[off5]);
                                        if ((u32)(*(u32 *)(gSoundSlots + off5) + 0x10000) != 0xFFFFU) {
                                            fn_8024DA2C(*(u32 *)(gSoundSlots + off5));
                                        }
                                        (gSoundSlots + off5)[0xC] = 0;
                                    }
                                    Audio_Unlock();
                                }
                                (gSoundSlots + off4)[0xC] = 0;
                            }
                            Audio_Unlock();
                        }
                        (gSoundSlots + off3)[0xC] = 0;
                    }
                    Audio_Unlock();
                }
                (gSoundSlots + off2)[0xC] = 0;
            }
            Audio_Unlock();
        }
        (gSoundSlots + off1)[0xC] = 0;
    }
    Audio_Unlock();
}

#pragma global_optimizer off
s32 fn_8024E100(u32 arg0) {
    extern u8 gSoundSlots[];
    void Audio_Lock(void);
    void Audio_Unlock(void);
    s32 fn_80256C14(u8);
    s32 Sound_FindSlotById(u32);

    u8 *base;
    u8 *scan;
    u8 *typep;
    u8 *slot;
    s32 index;
    s32 offset;
    s32 i;
    s32 voice;
    u32 parent;
    u32 id;
    s32 result;

    result = 0;
    Audio_Lock();
    base = gSoundSlots;
    scan = base;
    index = 0;
    for (i = 0; i < 64; i++, scan += 0x68) {
        if (scan[0xC] != 0 && arg0 == *(u32 *)(scan + 4)) {
            index = i;
            goto found1;
        }
    }
    index = -1;
found1:
    if ((u32)(index + 0x10000) != 0xFFFFU) {
        offset = index * 0x68;
        typep = gSoundSlots + 0xC;
        if (typep[offset] == 3) {
            slot = gSoundSlots + offset;
            voice = fn_80256C14(slot[0x58]);
            slot = gSoundSlots + offset;
            *(s32 *)(slot + 0x4C) = voice;
            if ((u32)(voice + 0x10000) == 0xFFFFU) {
                Audio_Unlock();
                return 0;
            }
            *(s32 *)(slot + 0x20) = 0;
            typep[offset] = 1;
        }
        parent = *(u32 *)(gSoundSlots + offset);
        if ((u32)(parent + 0x10000) != 0xFFFFU) {
            result = 0;
            Audio_Lock();
            scan = base;
            index = 0;
            for (i = 0; i < 64; i++, scan += 0x68) {
                if (scan[0xC] != 0 && parent == *(u32 *)(scan + 4)) {
                    index = i;
                    goto found2;
                }
            }
            index = -1;
found2:
            if ((u32)(index + 0x10000) != 0xFFFFU) {
                offset = index * 0x68;
                if (typep[offset] == 3) {
                    slot = gSoundSlots + offset;
                    voice = fn_80256C14(slot[0x58]);
                    slot = gSoundSlots + offset;
                    *(s32 *)(slot + 0x4C) = voice;
                    if ((u32)(voice + 0x10000) == 0xFFFFU) {
                        Audio_Unlock();
                        result = 0;
                        goto done2;
                    }
                    *(s32 *)(slot + 0x20) = 0;
                    typep[offset] = 1;
                }
                parent = *(u32 *)(gSoundSlots + offset);
                if ((u32)(parent + 0x10000) != 0xFFFFU) {
                    result = 0;
                    Audio_Lock();
                    scan = base;
                    index = 0;
                    for (i = 0; i < 64; i++, scan += 0x68) {
                        if (scan[0xC] != 0 && parent == *(u32 *)(scan + 4)) {
                            index = i;
                            goto found3;
                        }
                    }
                    index = -1;
found3:
                    if ((u32)(index + 0x10000) != 0xFFFFU) {
                        offset = index * 0x68;
                        if (typep[offset] == 3) {
                            slot = gSoundSlots + offset;
                            voice = fn_80256C14(slot[0x58]);
                            slot = gSoundSlots + offset;
                            *(s32 *)(slot + 0x4C) = voice;
                            if ((u32)(voice + 0x10000) == 0xFFFFU) {
                                Audio_Unlock();
                                result = 0;
                                goto done3;
                            }
                            *(s32 *)(slot + 0x20) = 0;
                            typep[offset] = 1;
                        }
                        parent = *(u32 *)(gSoundSlots + offset);
                        if ((u32)(parent + 0x10000) != 0xFFFFU) {
                            result = 0;
                            Audio_Lock();
                            index = Sound_FindSlotById(parent);
                            if ((u32)(index + 0x10000) != 0xFFFFU) {
                                offset = index * 0x68;
                                if (typep[offset] == 3) {
                                    slot = gSoundSlots + offset;
                                    voice = fn_80256C14(slot[0x58]);
                                    slot = gSoundSlots + offset;
                                    *(s32 *)(slot + 0x4C) = voice;
                                    if ((u32)(voice + 0x10000) == 0xFFFFU) {
                                        Audio_Unlock();
                                        result = 0;
                                        goto done4;
                                    }
                                    *(s32 *)(slot + 0x20) = 0;
                                    typep[offset] = 1;
                                }
                                id = *(u32 *)(gSoundSlots + offset);
                                if ((u32)(id + 0x10000) != 0xFFFFU) {
                                    result = fn_8024E100(id);
                                } else {
                                    result = 1;
                                }
                            }
                            Audio_Unlock();
                            goto after4;
done4:
                            ;
after4:
                            ;
                        } else {
                            result = 1;
                        }
                        Audio_Unlock();
                        goto after3;
done3:
                        ;
after3:
                        ;
                    } else {
                        Audio_Unlock();
                    }
                } else {
                    result = 1;
                }
                Audio_Unlock();
                goto after2;
done2:
                ;
after2:
                ;
            } else {
                Audio_Unlock();
            }
        } else {
            result = 1;
        }
        Audio_Unlock();
    } else {
        Audio_Unlock();
    }
    return result;
}

void fn_8024E758(u32 arg0)
{
    extern u8 gSoundSlots[];
    void Audio_Lock(void);
    void Audio_Unlock(void);
    void fn_80256DD8(s32);
    s32 Sound_FindSlotById(u32);

    u8 *base;
    u8 *scan;
    u8 *typep;
    s32 index;
    s32 offset;
    u32 parent;
    u8 type;
    s32 i;

    Audio_Lock();
    base = gSoundSlots;
    scan = base;
    index = 0;
    for (i = 0; i < 64; i++, scan += 0x68) {
        if (scan[0xC] != 0 && arg0 == *(u32 *)(scan + 4)) {
            index = i;
            goto found1;
        }
    }
    index = -1;
found1:
    if ((u32)(index + 0x10000) != 0xFFFFU) {
        offset = index * 0x68;
        typep = gSoundSlots + 0xC;
        type = typep[offset];
        if (type == 1 || type == 2) {
            fn_80256DD8(*(s32 *)(gSoundSlots + offset + 0x4C));
            typep[offset] = 3;
        }
        parent = *(u32 *)(gSoundSlots + offset);
        if ((u32)(parent + 0x10000) != 0xFFFFU) {
            Audio_Lock();
            scan = base;
            index = 0;
            for (i = 0; i < 64; i++, scan += 0x68) {
                if (scan[0xC] != 0 && parent == *(u32 *)(scan + 4)) {
                    index = i;
                    goto found2;
                }
            }
            index = -1;
found2:
            if ((u32)(index + 0x10000) != 0xFFFFU) {
                offset = index * 0x68;
                type = typep[offset];
                if (type == 1 || type == 2) {
                    fn_80256DD8(*(s32 *)(gSoundSlots + offset + 0x4C));
                    typep[offset] = 3;
                }
                parent = *(u32 *)(gSoundSlots + offset);
                if ((u32)(parent + 0x10000) != 0xFFFFU) {
                    Audio_Lock();
                    scan = base;
                    index = 0;
                    for (i = 0; i < 64; i++, scan += 0x68) {
                        if (scan[0xC] != 0 && parent == *(u32 *)(scan + 4)) {
                            index = i;
                            goto found3;
                        }
                    }
                    index = -1;
found3:
                    if ((u32)(index + 0x10000) != 0xFFFFU) {
                        offset = index * 0x68;
                        type = typep[offset];
                        if (type == 1 || type == 2) {
                            fn_80256DD8(*(s32 *)(gSoundSlots + offset + 0x4C));
                            typep[offset] = 3;
                        }
                        parent = *(u32 *)(gSoundSlots + offset);
                        if ((u32)(parent + 0x10000) != 0xFFFFU) {
                            Audio_Lock();
                            index = 0;
                            for (i = 0; i < 64; i++, base += 0x68) {
                                if (base[0xC] != 0 && parent == *(u32 *)(base + 4)) {
                                    index = i;
                                    goto found4;
                                }
                            }
                            index = -1;
found4:
                            if ((u32)(index + 0x10000) != 0xFFFFU) {
                                offset = index * 0x68;
                                type = typep[offset];
                                if (type == 1 || type == 2) {
                                    fn_80256DD8(*(s32 *)(gSoundSlots + offset + 0x4C));
                                    typep[offset] = 3;
                                }
                                parent = *(u32 *)(gSoundSlots + offset);
                                if ((u32)(parent + 0x10000) != 0xFFFFU) {
                                    Audio_Lock();
                                    index = Sound_FindSlotById(parent);
                                    if ((u32)(index + 0x10000) != 0xFFFFU) {
                                        offset = index * 0x68;
                                        type = typep[offset];
                                        if (type == 1 || type == 2) {
                                            fn_80256DD8(*(s32 *)(gSoundSlots + offset + 0x4C));
                                            typep[offset] = 3;
                                        }
                                        if ((u32)(*(u32 *)(gSoundSlots + offset) + 0x10000) != 0xFFFFU) {
                                            fn_8024E758(*(u32 *)(gSoundSlots + offset));
                                        }
                                    }
                                    Audio_Unlock();
                                }
                            }
                            Audio_Unlock();
                        }
                    }
                    Audio_Unlock();
                }
            }
            Audio_Unlock();
        }
    }
    Audio_Unlock();
}

#pragma global_optimizer off
s32 AudioBank_Insert(u16 id, s32 data) {
    void Audio_Lock(void);
    void Audio_Unlock(void);
    extern AudioTableEntry lbl_8034EEB8[];
    extern u16 lbl_80368A0E;

    u16 count;
    s32 i;
    s32 j;

    Audio_Lock();
    count = lbl_80368A0E;
    {
        AudioTableEntry *p;
        p = lbl_8034EEB8;
        for (i = 0; i < (s32)count && p->id < id; p++, i++) {
        }
    }

    if (i < (s32)count) {
        if (id != lbl_8034EEB8[i].id) {
            if (count < 0x100U) {
                AudioTableEntry *moving;
                for (j = (s32)count - 1, moving = &lbl_8034EEB8[j]; j >= i; j--, moving--) {
                    moving[1] = moving[0];
                }
                lbl_80368A0E++;
                goto insert;
            }
            Audio_Unlock();
            return 0;
        }
        lbl_8034EEB8[i].ref++;
        Audio_Unlock();
        return 0;
    }

    if (count < 0x100U) {
        lbl_80368A0E++;
        goto insert;
    }
    Audio_Unlock();
    return 0;

insert:
    lbl_8034EEB8[i].id = id;
    lbl_8034EEB8[i].data = data;
    lbl_8034EEB8[i].ref = 1;
    Audio_Unlock();
    return 1;
}
#pragma global_optimizer on
s32 AudioBank_Remove(u16 id) {
    struct AudioBankKey {
        s32 data;
        u16 id;
        u16 ref;
    };
    void Audio_Lock(void);
    void Audio_Unlock(void);
    extern struct AudioBankKey lbl_8034EEB8[];
    extern u16 lbl_80368A0E;

    s32 i;
    u16 count;

    Audio_Lock();
    count = lbl_80368A0E;
    for (i = 0; i < (s32)count && lbl_8034EEB8[i].id != id; ++i) {
    }

    if (i != (s32)count) {
        struct AudioBankKey *base;
        struct AudioBankKey *entry;
        base = lbl_8034EEB8;
        entry = base + i;
        if (--entry->ref == 0) {
            s32 j;
            struct AudioBankKey *moving;
            for (j = i + 1, moving = base + j; j < (s32)count; j++, moving++) {
                moving[-1] = *moving;
            }
            lbl_80368A0E--;
            Audio_Unlock();
            return 1;
        }
    }
    Audio_Unlock();
    return 0;
}
#pragma global_optimizer on

#pragma global_optimizer on

#pragma dont_inline reset

/* Insert or bump-ref a sample key in the sorted table; returns 1 if a new entry was added. */
s32 SampleKey_Insert(u16 id, s32 data, s16 type) {
    void Audio_Lock(void);
    void Audio_Unlock(void);
    extern SampleKey gSampleKeys[];
    extern u16 gSampleKeyCount;
    s32 i;
    s32 j;
    u16 count;

    Audio_Lock();
    count = gSampleKeyCount;
    for (i = 0; i < (s32)count && gSampleKeys[i].id < id; i++) {
    }
    if (i < (s32)count) {
        if (id != gSampleKeys[i].id) {
            if (count < 0x100U) {
                for (j = (s32)count - 1; j >= i; j--) {
                    gSampleKeys[j + 1] = gSampleKeys[j];
                }
                gSampleKeyCount++;
                goto insert;
            }
            Audio_Unlock();
            return 0;
        }
        gSampleKeys[i].ref++;
        Audio_Unlock();
        return 0;
    }
    if (count < 0x100U) {
        gSampleKeyCount++;
        goto insert;
    }
    Audio_Unlock();
    return 0;
insert:
    gSampleKeys[i].id = id;
    gSampleKeys[i].data = data;
    gSampleKeys[i].type = type;
    gSampleKeys[i].ref = 1;
    Audio_Unlock();
    return 1;
}

s32 SampleKey_Remove(u16 id) {
    void Audio_Lock(void);
    void Audio_Unlock(void);
    extern SampleKey gSampleKeys[];
    extern u16 gSampleKeyCount;

    u16 uid;
    s32 i;
    u16 count;

    uid = id;
    Audio_Lock();
    count = gSampleKeyCount;
    for (i = 0; i < (s32)count && gSampleKeys[i].id != uid; ++i) {
    }

    if (i != (s32)count) {
        SampleKey *base;
        SampleKey *entry;
        base = gSampleKeys;
        entry = base + i;
        if (--entry->ref == 0) {
            s32 j;
            SampleKey *moving;
            for (j = i + 1, moving = base + j; j < (s32)count; j++, moving++) {
                moving[-1] = *moving;
            }
            gSampleKeyCount--;
            Audio_Unlock();
            return 1;
        }
    }
    Audio_Unlock();
    return 0;
}

/* Insert or ref an audio-wave key by id into the sorted table; returns 1 if newly inserted. */
s32 AudioWave_Insert(u16 id, s32 data) {
    struct AudioWaveKey {
        s32 data;
        u16 id;
        u16 ref;
    };
    void Audio_Lock(void);
    void Audio_Unlock(void);
    extern struct AudioWaveKey gAudioWaveKeys[];
    extern u16 gAudioWaveKeyCount;

    s32 i;
    s32 j;
    u16 count;

    Audio_Lock();
    count = gAudioWaveKeyCount;
    for (i = 0; i < (s32)count && gAudioWaveKeys[i].id < id; i++) {
    }

    if (i < (s32)count) {
        if (id != gAudioWaveKeys[i].id) {
            if (count < 0x800U) {
                for (j = (s32)count - 1; j >= i; j--) {
                    gAudioWaveKeys[j + 1] = gAudioWaveKeys[j];
                }
                gAudioWaveKeyCount++;
                goto insert;
            }
            Audio_Unlock();
            return 0;
        }
        Audio_Unlock();
        gAudioWaveKeys[i].ref++;
        return 0;
    }

    if (count < 0x800U) {
        gAudioWaveKeyCount++;
        goto insert;
    }
    Audio_Unlock();
    return 0;

insert:
    gAudioWaveKeys[i].id = id;
    gAudioWaveKeys[i].data = data;
    gAudioWaveKeys[i].ref = 1;
    Audio_Unlock();
    return 1;
}

s32 AudioWave_Remove(u16 id) {
    struct AudioWaveKey {
        s32 data;
        u16 id;
        u16 ref;
    };
    void Audio_Lock(void);
    void Audio_Unlock(void);
    extern struct AudioWaveKey gAudioWaveKeys[];
    extern u16 gAudioWaveKeyCount;

    s32 i;
    u16 count;
    struct AudioWaveKey *p;

    Audio_Lock();
    count = gAudioWaveKeyCount;
    for (i = 0; i < (s32)count && gAudioWaveKeys[i].id != id; ++i) {
    }

    if (i != (s32)count) {
        struct AudioWaveKey *base;
        struct AudioWaveKey *entry;
        base = gAudioWaveKeys;
        entry = base + i;
        if (--entry->ref == 0) {
            s32 j;
            struct AudioWaveKey *moving;
            for (j = i + 1, moving = base + j; j < (s32)count; j++, moving++) {
                moving[-1] = *moving;
            }
            gAudioWaveKeyCount--;
            Audio_Unlock();
            return 1;
        }
    }
    Audio_Unlock();
    return 0;
}

s32 fn_8024F964(void *entries, s32 data) {
    struct AudioGroupEntry {
        u16 id;
        u16 ref;
        u8 pad[0x1C];
    };
    struct AudioGroup {
        struct AudioGroupEntry *entries;
        s32 data;
        u16 count;
        u16 pad;
    };
    void Audio_Lock(void);
    void Audio_Unlock(void);
    extern struct AudioGroup gAudioGroups[];
    extern u16 gAudioGroupCount;
    extern void *lbl_80368A14;
    s32 i;
    u16 j;
    s32 n;
    u16 groupCount;
    struct AudioGroupEntry *e;

    i = 0;
    groupCount = gAudioGroupCount;
    while (i < (s32)groupCount && gAudioGroups[i].entries != (struct AudioGroupEntry *)entries) {
        i++;
    }
    lbl_80368A14 = entries;
    if (i == (s32)groupCount) {
        if (groupCount < 0x80U) {
            Audio_Lock();
            e = (struct AudioGroupEntry *)entries;
            n = 0;
            while (e->id != 0xFFFF) {
                n++;
                e++;
            }
            j = 0;
            if ((u16)n > j) {
                s32 limit = n - 8;
                if ((u16)n > 8) {
                    u16 z = 0;
                    while (j < (u16)limit) {
                        u16 *p = (u16 *)((u8 *)entries + (j << 5) + 2);
                        j += 8;
                        *p = z;
                        *(u16 *)((u8 *)p + 0x20) = z;
                        *(u16 *)((u8 *)p + 0x40) = z;
                        *(u16 *)((u8 *)p + 0x60) = z;
                        *(u16 *)((u8 *)p + 0x80) = z;
                        *(u16 *)((u8 *)p + 0xA0) = z;
                        *(u16 *)((u8 *)p + 0xC0) = z;
                        *(u16 *)((u8 *)p + 0xE0) = z;
                    }
                }
                {
                    u16 z = 0;
                    while (j < (u16)n) {
                        *(u16 *)((u8 *)entries + (j << 5) + 2) = z;
                        j++;
                    }
                }
            }
            {
                u16 c = gAudioGroupCount++;
                gAudioGroups[c].entries = (struct AudioGroupEntry *)entries;
                gAudioGroups[c].count = n;
                gAudioGroups[c].data = data;
            }
            Audio_Unlock();
            return 1;
        }
        return 0;
    }
    return 1;
}

s32 fn_8024FACC(void *arg0)
{
    struct AudioGroup {
        void *entries;
        u32 data;
        u16 count;
        u16 pad;
    };

    extern struct AudioGroup gAudioGroups[];
    extern u16 gAudioGroupCount;

    void Audio_Lock(void);
    void Audio_Unlock(void);

    struct AudioGroup *group;
    u8 *entry;
    s32 i;
    s32 j;
    s32 count;

    group = gAudioGroups;
    i = 0;
    count = gAudioGroupCount;

    while (i < count) {
        if (group->entries == arg0) {
            break;
        }

        group++;
        i++;
    }

    if (i == count) {
        return 0;
    }

    Audio_Lock();

    entry = (u8 *)arg0;

    while (*(u16 *)entry != 0xFFFF) {
        if (*(u16 *)(entry + 2) != 0) {
            Audio_Unlock();
            return 0;
        }

        entry += 0x20;
    }

    for (j = i + 1; j < gAudioGroupCount; j++) {
        gAudioGroups[j - 1] = gAudioGroups[j];
    }

    gAudioGroupCount--;

    Audio_Unlock();

    return 1;
}

#pragma optimization_level 3
#pragma opt_strength_reduction off
s32 AudioGroup_Register(u16 id, void *arg1)
{
    struct Entry {
        u16 id;
        u16 ref;
        u32 unk4;
        u32 unk8;
        u8 unkC[0x14];
    };
    struct Group {
        struct Entry *entries;
        u32 unk4;
        u32 unk8;
    };
    void fn_80262378(void *, void *, void *);
    extern struct Group gAudioGroups[];
    extern u16 gAudioGroupCount;
    extern struct Entry *lbl_80368A14;

    struct Group *group;
    struct Entry *base;
    struct Entry *entries;
    struct Entry *e;
    struct Entry *selected;
    struct Group *selectedGroup;
    u32 count;
    void *stackPtr;

    group = gAudioGroups;
    selected = NULL;
    count = gAudioGroupCount;
    base = lbl_80368A14;

    for (; count > 0; count--) {
        entries = group->entries;
        e = entries;
        while (e->id != 0xFFFF) {
            if (e->id == id) {
                if (e->ref != 0) {
                    e->ref = (u16)(e->ref + 1);
                    return 1;
                }
                if (base == entries) {
                    selected = e;
                    selectedGroup = group;
                }
                break;
            }
            e++;
        }
        group++;
    }

    selected->unk8 = selected->unk4 + selectedGroup->unk4;
    stackPtr = selected->unkC;
    fn_80262378(&stackPtr, &selected->unk8, arg1);
    selected->ref = 1;
    return 1;
}
#pragma opt_strength_reduction reset
#pragma optimization_level reset
s32 AudioGroup_Unregister(u16 id, s32 arg1) {
    struct Entry {
        u16 id;
        u16 ref;
        u32 unk4;
        u32 unk8;
        u8 unkC[0x14];
    };
    struct Group {
        struct Entry *entries;
        u32 unk4;
        u32 unk8;
    };
    void fn_80262430(void *, u32, s32);
    extern struct Group gAudioGroups[];
    extern u16 gAudioGroupCount;
    struct Entry *e;
    u32 i;

    for (i = 0; i < gAudioGroupCount; i++) {
        e = gAudioGroups[i].entries;
        while (e->id != 0xFFFF) {
            if (e->id == id && e->ref != 0) {
                e->ref--;
                if (e->ref == 0) {
                    fn_80262430(e->unkC, e->unk8, arg1);
                }
                return 1;
            }
            e++;
        }
    }
    return 0;
}

s32 fn_8024FE1C(u16 arg0, void *arg1, u16 arg2) {
void Audio_Lock(void); void Audio_Unlock(void);
s32 i;
u8 *entry;
for(i=0;i<lbl_80368A08 && *(u16*)(lbl_803548B8+i*12)!=arg0;i++) {}
if(i==lbl_80368A08) {
if(lbl_80368A08<128) {
Audio_Lock();
*(u16*)(lbl_803548B8+lbl_80368A08*12)=arg0;
entry=lbl_803548B8+lbl_80368A08*12;
*(u16*)(entry+2)=arg2;
*(void**)(entry+8)=arg1;
*(u16*)(entry+4)=1;
for(i=arg2;i>0;i--) {((u8*)arg1)[9]=31;arg1=(u8*)arg1+10;}
lbl_80368A08++;
Audio_Unlock();
return 1;
}
} else {
u8 *found=lbl_803548B8+i*12;
++*(u16*)(found+4);
}
return 0;
}

s32 fn_8024FF5C(u16 arg0)
{
    extern u8 lbl_803548B8[1536];
    extern u16 lbl_80368A08;

    void Audio_Lock(void);
    void Audio_Unlock(void);

    struct Entry {
        u16 id;
        u16 field2;
        u16 refCount;
        u16 field6;
        void *data;
    };

    struct Entry *entries;
    struct Entry *entry;
    s32 i;
    s32 j;
    s32 count;

    entries = (struct Entry *)lbl_803548B8;
    i = 0;

    while (i < lbl_80368A08) {
        if (entries[i].id == arg0) {
            break;
        }
        i++;
    }

    if (i == lbl_80368A08) {
        return 0;
    }

    entry = &entries[i];
    entry->refCount--;

    if (entry->refCount != 0) {
        return 0;
    }

    Audio_Lock();

    count = lbl_80368A08;

    for (j = i + 1; j < count; j++) {
        entries[j - 1] = entries[j];
    }

    lbl_80368A08--;

    Audio_Unlock();

    return 1;
}

#pragma opt_strength_reduction off
s32 AudioTable_Insert(u16 id, s32 data) {
    /* Insert id/data into the audio hash table, or bump ref if id already exists. */
    void Audio_Lock(void);
    void Audio_Unlock(void);
    extern AudioTableRange gAudioTableRanges[];
    extern AudioTableEntry gAudioTableEntries[];
    extern u16 gAudioTableCount;
    u16 count;
    s32 start, i, j, index;
    AudioTableRange *range;
    AudioTableEntry *moving;
    u32 bucket;

    Audio_Lock();
    bucket = (id >> 6) & 1023;
    count = gAudioTableRanges[bucket].count;
    if (count == 0) {
        gAudioTableRanges[bucket].start = gAudioTableCount;
        start = gAudioTableCount;
        index = gAudioTableCount;
    } else {
        start = gAudioTableRanges[bucket].start;
        for (i = 0; i < (s32)count && gAudioTableEntries[start + i].id < id; i++) {}
        if (i < (s32)count) {
            index = start + i;
            if (id == gAudioTableEntries[index].id) {
                gAudioTableEntries[index].ref++;
                Audio_Unlock();
                return 0;
            }
        } else {
            index = start + i;
        }
    }
    for (j = 0, range = gAudioTableRanges; j < 512; range++, j++) {
        if ((s32)range->start > (s32)start) {
            range->start++;
        }
    }
    for (j = gAudioTableCount - 1, moving = &gAudioTableEntries[j]; j >= index; j--, moving--) {
        moving[1] = moving[0];
    }
    gAudioTableEntries[index].id = id;
    gAudioTableEntries[index].data = data;
    gAudioTableEntries[index].ref = 1;
    gAudioTableRanges[bucket].count++;
    gAudioTableCount++;
    Audio_Unlock();
    return 1;
}
#pragma opt_strength_reduction off
/* Decrement audio table ref for id; remove the entry when the last ref drops. */
s32 AudioTable_Remove(u16 id) {
    void Audio_Lock(void);
    void Audio_Unlock(void);
    extern AudioTableRange gAudioTableRanges[];
    extern AudioTableEntry gAudioTableEntries[];
    extern u16 gAudioTableCount;
    s32 total;
    s32 index;
    s32 j;
    u32 bucket;
    u16 count;
    u16 start;
    s32 i;
    AudioTableRange *range;
    AudioTableEntry *moving;

    Audio_Lock();
    bucket = (id >> 6) & 1023;
    count = gAudioTableRanges[bucket].count;
    if (count != 0) {
        start = gAudioTableRanges[bucket].start;
        for (i = 0; i < (s32)count && id != gAudioTableEntries[start + i].id; i++) {
        }
        if (i < (s32)count) {
            index = start + i;
            if (--gAudioTableEntries[index].ref == 0) {
                total = gAudioTableCount;
                for (j = index + 1, moving = &gAudioTableEntries[j]; j < total; j++, moving++) {
                    moving[-1] = moving[0];
                }
                for (j = 0, range = gAudioTableRanges; j < 512; range++, j++) {
                    if ((s32)range->start > (s32)start) {
                        range->start--;
                    }
                }
                gAudioTableRanges[bucket].count--;
                gAudioTableCount--;
            }
        }
    }
    Audio_Unlock();
    return 0;
}
#pragma opt_strength_reduction on
s32 fn_80250698(void *arg0, void *arg1) {
    return M2C_FIELD(arg0, u16 *, 4) - M2C_FIELD(arg1, u16 *, 4);
}

void *fn_802506A8(u32 arg0) {
    s32 *Bsearch(void *, void *, u16, s32, s32 (*)(void *, void *));
    s32 fn_80250698(void *, void *);
    extern AudioTableRange gAudioTableRanges[];
    extern AudioTableEntry gAudioTableEntries[];
    extern struct { s32 data; u16 id; u16 pad; } lbl_803689F8;
    extern s32 *lbl_803689F4;
    extern u32 lbl_80368A00;
    extern u32 lbl_80368A04;
    u16 count;
    u16 start;

    count = gAudioTableRanges[(arg0 >> 6) & 1023].count;
    lbl_80368A00 = (arg0 >> 6) & 1023;
    if (count != 0) {
        start = gAudioTableRanges[(arg0 >> 6) & 1023].start;
        lbl_803689F8.id = (u16)arg0;
        lbl_80368A04 = start;
        if ((lbl_803689F4 = Bsearch(&lbl_803689F8, &gAudioTableEntries[start], count, 8, fn_80250698)) != NULL) {
            return (void *)*lbl_803689F4;
        }
    }
    return NULL;
}

s32 AudioGroup_CompareId(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

/* Look up an audio group entry by id across gAudioGroups and fill out. */
s32 AudioGroup_Lookup(u16 id, void *out) {
    struct AudioGroupHeader {
        u32 unk0;
        u32 sizeAndFmt;
        u32 unk8;
        u32 unkC;
    };
    struct AudioGroupEntry {
        u16 id;
        u16 ref;
        u32 unk4;
        u32 data;
        struct AudioGroupHeader header;
        u32 relOff;
    };
    struct AudioGroup {
        struct AudioGroupEntry *entries;
        u32 unk4;
        u16 count;
        u16 pad;
    };
    struct AudioGroupInfo {
        u32 unk0;
        u32 data;
        u32 extra;
        u32 unkC;
        u32 size;
        u32 unk14;
        u32 unk18;
        u8 fmt;
    };
    void *Bsearch(void *, void *, u16, s32, s32 (*)(u16 *, u16 *));
    extern struct AudioGroupEntry gAudioGroupLookupKey;
    extern struct AudioGroup gAudioGroups[];
    extern u16 gAudioGroupCount;
    extern struct AudioGroupEntry *gAudioGroupFound;
    extern struct AudioGroupHeader *gAudioGroupHeader;
    struct AudioGroupInfo *info = out;
    s32 i;

    gAudioGroupLookupKey.id = id;
    for (i = 0; i < gAudioGroupCount; i++) {
        if ((gAudioGroupFound = Bsearch(&gAudioGroupLookupKey, gAudioGroups[i].entries, gAudioGroups[i].count, 0x20, AudioGroup_CompareId)) != NULL && gAudioGroupFound->ref != 0) {
            gAudioGroupHeader = &gAudioGroupFound->header;
            info->unk0 = gAudioGroupHeader->unk0;
            info->data = gAudioGroupFound->data;
            info->unkC = 0;
            info->unk14 = gAudioGroupHeader->unk8;
            info->size = gAudioGroupHeader->sizeAndFmt & 0xFFFFFF;
            info->unk18 = gAudioGroupHeader->unkC;
            info->fmt = gAudioGroupHeader->sizeAndFmt >> 24;
            if (gAudioGroupFound->relOff != 0) {
                info->extra = gAudioGroupFound->relOff + (u32)gAudioGroups[i].entries;
            } else {
                info->extra = 0;
            }
            return 0;
        }
    }
    return -1;
}

s32 fn_80250874(void *arg0, void *arg1) {
    return M2C_FIELD(arg0, u16 *, 4) - M2C_FIELD(arg1, u16 *, 4);
}

s32 fn_80250884(u16 id) {
    struct Key {
        s32 data;
        u16 id;
        u16 pad;
    };
    s32 *Bsearch(void *, void *, u16, s32, s32 (*)(void *, void *));
    extern struct Key lbl_803689E4;
    extern struct Key gAudioWaveKeys[];
    extern u16 gAudioWaveKeyCount;
    extern s32 *lbl_803689E0;

    lbl_803689E4.id = id;
    if ((lbl_803689E0 = Bsearch(&lbl_803689E4, gAudioWaveKeys, gAudioWaveKeyCount, 8, fn_80250874)) != NULL) {
        return *lbl_803689E0;
    }
    return 0;
}

s32 fn_802508E0(u16 id) {
    struct Key {
        s32 data;
        u16 id;
        u16 pad;
    };
    s32 *Bsearch(void *, void *, u16, s32, s32 (*)(void *, void *));
    extern struct Key lbl_803689D8;
    extern struct Key lbl_8034EEB8[];
    extern u16 lbl_80368A0E;
    extern s32 *lbl_803689D4;

    lbl_803689D8.id = id;
    if ((lbl_803689D4 = Bsearch(&lbl_803689D8, lbl_8034EEB8, lbl_80368A0E, 8, fn_80250874)) != NULL) {
        return *lbl_803689D4;
    }
    return 0;
}

s32 fn_8025093C(void *arg0, void *arg1) {
    return M2C_FIELD(arg0, u16 *, 4) - M2C_FIELD(arg1, u16 *, 4);
}

s32 fn_8025094C(u16 arg0, u16 *arg1)
{
    extern u8 lbl_803596D8[12];
    extern u16 gSampleKeys[];
    extern u16 gSampleKeyCount;
    extern void *lbl_803689D0;

    void *BSearch(void *, void *, s32, s32, s32 (*)(void *, void *));
    s32 fn_8025093C(void *, void *);

    *(u16 *)(lbl_803596D8 + 4) = arg0;

    lbl_803689D0 = BSearch(
        lbl_803596D8,
        gSampleKeys,
        gSampleKeyCount,
        0xC,
        fn_8025093C
    );

    if (lbl_803689D0 != 0) {
        *arg1 = *(u16 *)((u8 *)lbl_803689D0 + 6);
        return *(s32 *)lbl_803689D0;
    }

    return 0;
}

s32 fn_802509C8(u16 *arg0, u16 *arg1) {
    return *arg0 - *arg1;
}

int Sound_FindEntry(int arg0)
{
    extern u8 lbl_803596E4[12];

    void *Bsearch(void *, void *, s32, s32, s32 (*)(void *, void *));
    s32 fn_802509C8(void *, void *);

    s32 i;
    u8 *entry;
    u8 *key;
    void *cmp;
    void *result;

    key = lbl_803596E4;
    entry = lbl_803548B8;
    cmp = fn_802509C8;
    i = 0;
    *(u16 *)key = arg0;

    while (i < (s32)lbl_80368A08) {
        result = Bsearch(
            key,
            *(void **)(entry + 8),
            *(u16 *)(entry + 2),
            0xA,
            (s32 (*)(void *, void *))cmp
        );
        if (result != 0) {
            return (int)result;
        }
        entry += 0xC;
        i++;
    }
    return 0;
}

void fn_80250A74(s32 arg0, s32 arg1) {
    void fn_80262354(s32, s32);
    extern u16 gAudioGroupCount, gAudioWaveKeyCount, lbl_80368A0E, gSampleKeyCount, lbl_80368A08, gAudioTableCount;
    extern u16 gAudioTableRanges[];
    s32 i;
    gAudioGroupCount = 0;
    gAudioWaveKeyCount = 0;
    lbl_80368A0E = 0;
    gSampleKeyCount = 0;
    lbl_80368A08 = 0;
    gAudioTableCount = 0;
    for (i = 0; i < 0x200; i++) {
        gAudioTableRanges[i * 2] = 0;
        gAudioTableRanges[i * 2 + 1] = 0;
    }
    fn_80262354(arg0, arg1);
}

int fn_80250B58(void *arg0, u32 *arg1)
{
    extern s32 gSynthTimeHi;
    extern s32 gSynthTimeLo;

    u16 fn_802611F8(void);
    s32 Sound_IsHwVoiceActive(s32);
    void fn_8026146C(s32 *);
    void fn_8026147C(u32 *, s32);
    void fn_802552F8(void *);
    void Sound_SetSynthVoiceState(void *, s32);

    u8 *voice;
    u32 flags;
    u32 flags2;
    u32 time;
    u32 mode;
    u32 low;
    u32 high;
    u32 baseLow;
    u32 baseHigh;

    voice = (u8 *)arg0;
    flags = arg1[0];
    mode = arg1[1];

    time = mode >> 16;

    if (time == 0) {
        return 0;
    }

    if (flags & 0x100) {
        flags2 = *(u32 *)(voice + 0x118);

        if ((flags2 & 8) != 0) {
            if ((*(u32 *)(voice + 0x114) & 0x100) == 0) {
                return 0;
            }
        }

        *(u32 *)(voice + 0x114) |= 0x400;
        *(u32 *)(voice + 0x118) |= 4;
    } else {
        *(u32 *)(voice + 0x118) &= ~4U;
    }

    if (flags & 0x1000000) {
        if ((*(u32 *)(voice + 0x118) & 0x20) == 0) {
            if (Sound_IsHwVoiceActive(*(u8 *)(voice + 0xF4)) == 0) {
                return 0;
            }
        }

        *(u32 *)(voice + 0x118) |= 0x40000;
    } else {
        *(u32 *)(voice + 0x118) &= ~0x40000U;
    }

    if (flags & 0x10000) {
        time = (u32)fn_802611F8() % time;
    }

    if (time == 0xFFFF) {
        *(u32 *)(voice + 0x98) = 0xFFFFFFFF;
        *(u32 *)(voice + 0x9C) = 0xFFFFFFFF;
    } else {
        if (mode & 0x100) {
            fn_8026146C((s32 *)&time);
        } else {
            fn_8026147C(&time, (s32)arg0);
        }

        if (mode & 1) {
            if (mode & 0x100) {
                baseHigh = *(u32 *)(voice + 0x90);
                baseLow = *(u32 *)(voice + 0x94);
            } else {
                baseHigh = gSynthTimeHi;
                baseLow = gSynthTimeLo;
            }
        } else {
            if (mode & 0x100) {
                baseHigh = 0;
                baseLow = time;
                time = 0;
            } else {
                baseHigh = *(u32 *)(voice + 0xA0);
                baseLow = *(u32 *)(voice + 0xA4);
            }
        }

        if ((mode & 0x101) != 0x100) {
            low = baseLow + time;
            high = baseHigh + (low < baseLow);
        } else {
            low = baseLow;
            high = baseHigh;
        }

        *(u32 *)(voice + 0x98) = high;
        *(u32 *)(voice + 0x9C) = low;

        if (high > gSynthTimeHi ||
            (high == gSynthTimeHi && low > gSynthTimeLo)) {
            *(u32 *)(voice + 0xA0) = high;
            *(u32 *)(voice + 0xA4) = low;
            *(u32 *)(voice + 0x98) = 0;
            *(u32 *)(voice + 0x9C) = 0;
        }
    }

    high = *(u32 *)(voice + 0x98);
    low = *(u32 *)(voice + 0x9C);

    if (high == 0 && low == 0) {
        return 0;
    }

    if (high == 0xFFFFFFFF && low == 0xFFFFFFFF) {
        return 0;
    }

    fn_802552F8(arg0);
    Sound_SetSynthVoiceState(arg0, 1);

    return 1;
}

#pragma opt_strength_reduction off
s32 fn_80250E48(void *arg0, u32 *arg1)
{
    void *fn_802506A8(u32);
    void fn_80255B20(void *);
    void fn_802567B0(void *);

    u32 *src;
    u8 *voice;
    u8 *data;
    u8 *slot;
    u32 index;
    u32 count;

    src = arg1;
    voice = (u8 *)arg0;

    data = fn_802506A8(src[0] >> 16);

    if (data != 0) {
        index = (voice[0x8D] + 1) & 3;
        voice[0x8D] = index;

        index = voice[0x8D];
        slot = voice + (index << 3);
        *(u32 *)(slot + 0x6C) = *(u32 *)(voice + 0x34);

        index = voice[0x8D];
        slot = voice + (index << 3);
        *(u32 *)(slot + 0x70) = *(u32 *)(voice + 0x38);

        count = voice[0x8C] + 1;
        voice[0x8C] = count;

        if ((u8)count > 4) {
            voice[0x8C] = 4;
        }

        *(void **)(voice + 0x34) = data;
        *(u8 **)(voice + 0x38) = data + ((src[1] & 0xFFFF) << 3);

        return 0;
    }

    fn_80255B20(voice);
    fn_802567B0(voice);

    return 1;
}
#pragma scheduling on
void fn_80250F18(void *arg0, u32 *arg1)
{
    u16 fn_802611F8(void);
    u32 Sound_IsHwVoiceActive(s32);

    u8 *voice;
    u32 flags;
    s32 value;
    u32 count;
    s32 divisor;
    u64 vf;

    voice = (u8 *)arg0;
    count = *(u16 *)(voice + 0xAA);

    if (count == 0) {
        flags = arg1[0];
        if ((flags >> 16) & 1) {
            value = fn_802611F8();
            divisor = arg1[1] >> 16;
            count = value % divisor;
            *(u16 *)(voice + 0xAA) = count;
        } else {
            count = arg1[1] >> 16;
            *(u16 *)(voice + 0xAA) = count;
        }
        count = *(u16 *)(voice + 0xAA);
        if (count == 0xFFFF)
            goto flags;
        *(u16 *)(voice + 0xAA) = count + 1;
    } else if (count == 0xFFFF) {
        goto flags;
    }

    count = *(u16 *)(voice + 0xAA) - 1;
    *(u16 *)(voice + 0xAA) = count;
    if ((count & 0xFFFF) == 0)
        return;

flags:
    flags = arg1[0];

    if ((flags >> 8) & 1) {
        vf = *(u64 *)(voice + 0x114);
        if ((vf & 0x10000000008ULL) == 8ULL) {
            *(u16 *)(voice + 0xAA) = 0;
            return;
        }
    }

    if ((flags >> 24) & 1) {
        vf = *(u64 *)(voice + 0x114);
        if ((vf & 0x20ULL) == 0) {
            if (Sound_IsHwVoiceActive(*(u32 *)(voice + 0xF4) & 0xFF) == 0) {
                *(u16 *)(voice + 0xAA) = 0;
                return;
            }
        }
    }

    value = (arg1[1] & 0xFFFF) << 3;
    *(u32 *)(voice + 0x38) = *(u32 *)(voice + 0x34) + value;
}
#pragma scheduling reset
void fn_8025106C(void *arg0, u32 *arg1)
{
    extern s32 gSynthVoices;

    s32 fn_802555A0(
        u32, u32, u32, u32, u32,
        u32, u32, u32, u32, u32,
        u32, u32, u32, u32, u32
    );

    void fn_8024A674(s32, s32);

    u8 *voice;
    u8 *entry;
    u32 word;
    u32 command;
    u32 value;
    u32 index;
    s32 volume;
    s32 result;
    s32 previous;

    voice = (u8 *)arg0;
    command = arg1[0];
    word = arg1[1];

    volume = (s32)*(u8 *)(voice + 0x131);
    volume += (s8)((command >> 8) & 0xFF);

    if (volume < 0) {
        volume = 0;
    } else if (volume > 0x7F) {
        volume = 0x7F;
    }

    if (*(u8 *)(voice + 0x11D) != 0) {
        volume |= 0x80;
    }

    *(u8 *)(voice + 0x11C) = 1;

    result = fn_802555A0(
        command >> 16,
        (word >> 16) & 0xFF,
        word >> 24,
        *(u32 *)(voice + 0x100),
        (u8)volume,
        (*(u32 *)(voice + 0x158) >> 16) & 0xFF,
        (*(u32 *)(voice + 0x174) >> 16) & 0xFF,
        *(u8 *)(voice + 0x121),
        *(u8 *)(voice + 0x122),
        *(u8 *)(voice + 0x123),
        word & 0xFFFF,
        *(u8 *)(voice + 0x120),
        0,
        *(u8 *)(voice + 0x11E),
        *(u8 *)(voice + 0x11F)
    );

    *(u8 *)(voice + 0x11C) = 0;

    if (result == -1) {
        *(s32 *)(voice + 0x108) = -1;
        return;
    }

    index = (u8)result;
    entry = (u8 *)gSynthVoices + index * 0x458;

    *(u32 *)(voice + 0x108) =
        *(u32 *)(*(u8 **)(entry + 0xF8) + 8);

    *(u32 *)(entry + 0xF0) =
        *(u32 *)(voice + 0xF4);

    previous = *(s32 *)(voice + 0xEC);

    if (previous != -1) {
        *(s32 *)(entry + 0xEC) = previous;

        *(s32 *)(
            (u8 *)gSynthVoices
            + ((u8)previous * 0x458)
            + 0xF0
        ) = result;
    }

    *(s32 *)(voice + 0xEC) = result;

    if (*(u8 *)(voice + 0x11D) != 0) {
        fn_8024A674((s32)entry, (s32)voice);
    }
}

/* Synth seq cmd: set or add voice volume (0..0x7F), store fine byte, apply if active. */
void Sound_CmdVolume(void *voice, u32 *cmd) {
    M2C_UNK fn_80250B58(void *, u32 *);
    u32 fn_802575A0(void *);
    M2C_UNK fn_80260174(u8, u8, u8);
    u16 volume;
    u16 clamped;
    u32 word;

    word = *cmd;
    if ((word >> 0x18U) == 0) {
        M2C_FIELD(voice, u16 *, 0x12E) = (u16)(M2C_FIELD(voice, u16 *, 0x12E) + (s8)(u8)(word >> 8U));
    } else {
        M2C_FIELD(voice, u16 *, 0x12E) = (u16)(M2C_FIELD(voice, u8 *, 0x131) + (s8)(u8)(word >> 8U));
    }
    volume = M2C_FIELD(voice, u16 *, 0x12E);
    if ((s16)volume < 0) {
        clamped = 0;
    } else {
        clamped = 0x7F;
        if (volume <= 0x7FU) {
            clamped = volume;
        }
    }
    M2C_FIELD(voice, u16 *, 0x12E) = clamped;
    M2C_FIELD(voice, s8 *, 0x130) = (s8)((u32)*cmd >> 0x10U);
    if (fn_802575A0(voice) != 0U) {
        fn_80260174(M2C_FIELD(voice, u8 *, 0x121), M2C_FIELD(voice, u8 *, 0x122), (u8)M2C_FIELD(voice, u16 *, 0x12E));
    }
    *cmd = 4;
    fn_80250B58(voice, cmd);
}

#pragma dont_inline on
void fn_802512D0(void *arg0, void *arg1) {
void fn_80261730(u8,u16,void*,u32,u32,u32,u32,u8);
void fn_8025164C(void *);
void fn_80249E14(void *);
u16 id;
u8 *voice=arg0;
u32 *cmd=arg1;
id=(u16)(cmd[0]>>8);
if(AudioGroup_Lookup(id,lbl_803596F0)==0) {
switch((s32)(cmd[0]>>24)) {
case 0: lbl_803596F0[3]=cmd[1];break;
case 1: lbl_803596F0[3]=((u8)(127-(*(u32*)(voice+0x158)>>16))*cmd[1])/127;break;
case 2: lbl_803596F0[3]=((u8)(*(u32*)(voice+0x158)>>16)*cmd[1])/127;break;
default: lbl_803596F0[3]=0;break;
}
if(lbl_803596F0[3]>=lbl_803596F0[4]) lbl_803596F0[3]=lbl_803596F0[4]-1;
fn_80261730((u8)*(u32*)(voice+0xf4),id,lbl_803596F0,
(*(u64*)(voice+0x114)&0x100)==0,
(voice[0x10c]<<24)|((*(u32*)(voice+0x110)>>15)&0xffffff),
*(u32*)(voice+0xf4),(*(u64*)(voice+0x114)&0x80000000000ULL)==0,voice[0x197]);
*(u32*)(voice+0x124)=lbl_803596F0[0];
*(u16*)(voice+0x12c)=id;
if(*(u32*)(voice+0x128)!=0xffffffff) fn_8025164C(voice);
*(u32*)(voice+0x118)|=0x20;
fn_80249E14(voice);
}
}
#pragma dont_inline reset

#pragma global_optimizer off
void fn_802514D0(u8 *voice, u32 *command) {
void fn_8026146C(s32 *);
void fn_8026147C(u32 *,s32);
u32 time;
s8 a,b;
if((command[0]>>24)&3) *(u64 *)(voice+0x114)|=0x4000;
else *(u64 *)(voice+0x114)&=~0x4000ULL;
time=command[1]>>16;
if((command[1]>>8)&1) fn_8026146C((s32 *)&time);
else fn_8026147C(&time,(s32)voice);
if(time) {
*(u64 *)(voice+0x114)|=0x2000;
*(u32 *)(voice+0x148)=time;
a=command[0]>>8;
b=command[0]>>16;
if(a<0) {
if(b<0) *(u8 *)(voice+0x145)=-b;else *(u8 *)(voice+0x145)=b;
*(u8 *)(voice+0x144)=-a;
*(u32 *)(voice+0x14c)=*(u32 *)(voice+0x148)>>1;
} else {
if(b<0) {
if(a==0) {
*(u8 *)(voice+0x145)=-b;
*(u32 *)(voice+0x14c)=*(u32 *)(voice+0x148)>>1;
} else {
*(u8 *)(voice+0x145)=100-b;
*(u32 *)(voice+0x14c)=0;
a--;
}
} else {
*(u8 *)(voice+0x145)=b;
*(u32 *)(voice+0x14c)=0;
}
*(u8 *)(voice+0x144)=a;
}
} else *(u64 *)(voice+0x114)&=~0x2000ULL;
}
#pragma global_optimizer reset
void fn_8025164C(void *arg0)
{
    extern u16 lbl_8029F1B0[];

    u8 *data;
    u32 value1;
    u32 value2;
    u32 ratio;
    u32 scaled;
    u32 count;
    u32 index;
    u32 value;
    u32 base;
    u32 lower;
    u32 upper;
    u32 i;

    data = (u8 *)arg0;

    value1 = *(u32 *)(data + 0x124);
    value2 = *(u32 *)(data + 0x128);

    ratio = value1 & 0xFFFFFF;
    scaled = value2 & 0xFFFFFF;

    if (ratio == scaled) {
        *(u16 *)(data + 0x12E) = value1 >> 24;
        *(u8 *)(data + 0x130) = 0;
        return;
    }

    if (ratio < scaled) {
        value = (scaled << 12) / ratio;
        count = 0;

        scaled = value >> 12;

        for (i = 0; i < 11; i++) {
            if (scaled < (1U << (count + 1))) {
                break;
            }
            count++;
        }

        value = value / (1U << count);

        index = 11;

        while (value <= lbl_8029F1B0[index]) {
            index--;
        }

        base = value1 >> 24;

        *(u16 *)(data + 0x12E) =
            base + count * 12 + index;

        lower = lbl_8029F1B0[index];
        upper = lbl_8029F1B0[index + 1];

        *(u8 *)(data + 0x130) =
            ((value - lower) * 100) / (upper - lower);

        return;
    }

    value = (ratio << 12) / scaled;
    count = 0;

    ratio = value >> 12;

    for (i = 0; i < 11; i++) {
        if (ratio < (1U << (count + 1))) {
            break;
        }
        count++;
    }

    value = value / (1U << count);

    index = 11;

    while (value <= lbl_8029F1B0[index]) {
        index--;
    }

    base = count * 12 + index;
    scaled = value1 >> 24;

    if (base > scaled) {
        *(u8 *)(data + 0x130) = 0;
        *(u16 *)(data + 0x12E) = 0;
        return;
    }

    *(u16 *)(data + 0x12E) = scaled - base;

    lower = lbl_8029F1B0[index];
    upper = lbl_8029F1B0[index + 1];

    *(u8 *)(data + 0x130) =
        ((lower - value) * 100) / (upper - lower);
}

void fn_802517EC(void *arg0, u32 *arg1) {
    s32 fn_80250884(u16);
    void Sound_SetVoiceEnvelope(u8, void *, s32);
    extern f32 gSoundVolCurve[];
    extern f32 lbl_8036C240;
    extern f32 lbl_8036C244;
    extern f32 lbl_8036C248;

    f32 vol;
    union {
        s16 h[4];
        struct { s32 v0; s32 v4; s16 c; s16 d; u8 pad[0xC]; } s;
        u8 all[0x18];
    } env;
    void *sv;
    u8 *data;
    u16 h8;
    s32 vC;
    s32 v10;

    sv = arg0;
    data = (u8 *)fn_80250884((u16)(arg1[0] >> 8));
    if (data != NULL) {
        if ((arg1[0] >> 24) == 0) {
            env.h[0] = (u16)((*(u16 *)(data + 0) >> 8) | (*(u16 *)(data + 0) << 8));
            env.h[1] = (u16)((*(u16 *)(data + 2) >> 8) | (*(u16 *)(data + 2) << 8));
            env.h[2] = (u16)((*(u16 *)(data + 4) >> 8) | (*(u16 *)(data + 4) << 8));
            env.h[3] = (u16)((*(u16 *)(data + 6) >> 8) | (*(u16 *)(data + 6) << 8));
            Sound_SetVoiceEnvelope((u8)*(u32 *)((u8 *)sv + 0xF4), &env, 0);
        } else {
            h8 = (u16)((*(u16 *)(data + 8) >> 8) | (*(u16 *)(data + 8) << 8));
            vol = lbl_8036C240 * gSoundVolCurve[h8 >> 5];
            env.s.v0 = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
            env.s.v4 = data[4] | (data[5] << 8) | (data[6] << 16) | (data[7] << 24);
            env.s.c = (s16)vol;
            env.s.d = (u16)((*(u16 *)(data + 0xA) >> 8) | (*(u16 *)(data + 0xA) << 8));
            vC = data[0xC] | (data[0xD] << 8) | (data[0xE] << 16) | (data[0xF] << 24);
            v10 = data[0x10] | (data[0x11] << 8) | (data[0x12] << 16) | (data[0x13] << 24);
            if ((u32)(vC + 0x80000000) != 0) {
                env.s.v0 += (s32)(lbl_8036C244 * (f32)*(u32 *)((u8 *)sv + 0x15C) * (f32)vC);
            }
            if ((u32)(v10 + 0x80000000) != 0) {
                env.s.v4 += (s32)(lbl_8036C248 * (f32)*(u8 *)((u8 *)sv + 0x131) * (f32)v10);
            }
            Sound_SetVoiceEnvelope((u8)*(u32 *)((u8 *)sv + 0xF4), &env, 1);
        }
        *(u32 *)((u8 *)sv + 0x118) |= 0x100;
    }
}

/* Build ADSR envelope from packed channel params and apply it to the synth voice. */
void Sound_ApplyVoiceAdsr(SynthVoice *sv, u32 *paramsIn) {
    extern f32 gSoundVolCurve[];
    extern s32 gSoundTimeCurve[];
    extern u8 gSoundLevelCurve[];
    extern f32 gSoundVolIndexScale;
    struct {
        s32 attack;
        s32 decay;
        s16 sustain;
        s16 release;
        s32 unkC;
        s32 unk10;
    } env;
    f32 vol;

    vol = gSoundVolCurve[Sound_GetChanParam(paramsIn[0] >> 24, M2C_FIELD(sv, u8 *, 0x121), M2C_FIELD(sv, u8 *, 0x122)) >> 7];
    env.attack = gSoundTimeCurve[Sound_GetChanParam(paramsIn[0] >> 8, M2C_FIELD(sv, u8 *, 0x121), M2C_FIELD(sv, u8 *, 0x122)) >> 7];
    env.decay = gSoundTimeCurve[Sound_GetChanParam(paramsIn[0] >> 16, M2C_FIELD(sv, u8 *, 0x121), M2C_FIELD(sv, u8 *, 0x122)) >> 7];
    env.sustain = 0xC1 - gSoundLevelCurve[__cvt_fp2unsigned(gSoundVolIndexScale * vol)];
    env.release = gSoundTimeCurve[Sound_GetChanParam(paramsIn[1], M2C_FIELD(sv, u8 *, 0x121), M2C_FIELD(sv, u8 *, 0x122)) >> 7];
    env.unkC = 0x80000000;
    env.unk10 = 0x80000000;
    Sound_SetVoiceEnvelope(sv->unkF4, &env, 2);
    M2C_FIELD(sv, u32 *, 0x118) |= 0x100;
}

void fn_80251B70(void *arg0, u32 *arg1) {
    s32 fn_80250884(u16);
    s32 fn_80257940(s32);
    void fn_80257C04(void *);
    extern f32 lbl_8036C244;
    extern f32 lbl_8036C248;
    extern u8 gSoundLevelCurve[];

    void *sv;
    u8 *data;
    s32 pitch;
    s32 v0;
    s32 v4;
    s32 vC;
    s32 v10;
    u16 h8;
    u16 hA;
    u32 idx;
    u8 *p;

    sv = arg0;
    data = (u8 *)fn_80250884((u16)(arg1[0] >> 8));
    if (data != NULL) {
        pitch = (s8)arg1[1] << 8;
        *(s16 *)((u8 *)sv + 0x210) = pitch;
        pitch = *(s16 *)((u8 *)sv + 0x210);
        if (pitch >= 0) {
            *(s16 *)((u8 *)sv + 0x210) = (s16)(pitch + ((((s8)(arg1[1] >> 8)) << 8) / 100));
        } else {
            *(s16 *)((u8 *)sv + 0x210) = (s16)(pitch - ((((s8)(arg1[1] >> 8)) << 8) / 100));
        }

        p = data;
        vC = (p[0xD] << 8) | p[0xC] | (p[0xE] << 16) | (p[0xF] << 24);
        v0 = (p[0x1] << 8) | p[0x0] | (p[0x2] << 16) | (p[0x3] << 24);
        h8 = (u16)((*(u16 *)(p + 8) >> 8) | (*(u16 *)(p + 8) << 8));
        v4 = (p[0x5] << 8) | p[0x4] | (p[0x6] << 16) | (p[0x7] << 24);
        hA = (u16)((*(u16 *)(p + 0xA) >> 8) | (*(u16 *)(p + 0xA) << 8));
        v10 = (p[0x11] << 8) | p[0x10] | (p[0x12] << 16) | (p[0x13] << 24);

        if ((u32)(vC + 0x80000000) != 0) {
            v0 += (s32)(lbl_8036C244 * (f32)*(u32 *)((u8 *)sv + 0x15C) * (f32)vC);
        }
        if ((u32)(v10 + 0x80000000) != 0) {
            v4 += (s32)(lbl_8036C248 * (f32)*(u8 *)((u8 *)sv + 0x131) * (f32)v10);
        }

        *(u8 *)((u8 *)sv + 0x1E8) = 1;
        *(u8 *)((u8 *)sv + 0x20E) = 0;
        *(s32 *)((u8 *)sv + 0x1FC) = fn_80257940(v0);
        *(s32 *)((u8 *)sv + 0x200) = fn_80257940(v4);

        idx = (h8 >> 2) & 0x3FFF;
        if (idx > 0x3FF) {
            idx = 0x3FF;
        }
        *(s16 *)((u8 *)sv + 0x204) = 0xC1 - gSoundLevelCurve[idx];
        *(u32 *)((u8 *)sv + 0x208) = hA;
        fn_80257C04((u8 *)sv + 0x1E8);
        *(u32 *)((u8 *)sv + 0x114) |= 0x200;
    }
}

void fn_80251DEC(Voice *arg0, u32 *arg1) {
    u32 time;
    s32 delta;

    time = arg1[0] >> 16;
    arg0->unk18C = time;
    fn_8026146C((s32 *)&arg0->unk18C);
    delta = (s8)arg1[1] << 16;
    arg0->unk174 = (arg1[0] << 8) & 0xFF0000;
    arg0->unk184 = arg0->unk174 + delta;
    if (arg0->unk18C != 0) {
        arg0->unk17C = delta / (s32)time;
    } else {
        arg0->unk17C = delta;
    }
    arg0->flags |= 0x2000;
}

void fn_80251E88(Voice *arg0, u32 *arg1) {
    u32 time;
    s32 delta;

    time = arg1[0] >> 16;
    arg0->unk190 = time;
    fn_8026146C((s32 *)&arg0->unk190);
    delta = (s8)arg1[1] << 16;
    arg0->unk178 = (arg1[0] << 8) & 0xFF0000;
    arg0->unk188 = arg0->unk178 + delta;
    if (arg0->unk190 != 0) {
        arg0->unk180 = delta / (s32)time;
    } else {
        arg0->unk180 = delta;
    }
    arg0->flags |= 0x2000;
}

#pragma use_lmw_stmw on
void fn_80251F24(void *arg0, u32 *arg1)
{
    s32 fn_80250884(u16);

    u8 *data;
    u32 word0;
    u32 word1;
    u32 value;
    u32 factor;
    u32 mode;
    u16 tableId;
    u32 index;
    u32 fraction;
    u32 result;
    u8 *table;

    data = (u8 *)arg0;

    word0 = arg1[0];
    word1 = arg1[1];

    factor = (word0 >> 8) & 0xFF;
    mode = (word1 >> 8) & 0xFF;

    if (mode == 0) {
        *(u32 *)(data + 0x158) = (*(u32 *)(data + 0x158) * factor) / 127;
    } else {
        *(u32 *)(data + 0x158) = (*(u32 *)(data + 0x15C) * factor) / 127;
    }
    *(u32 *)(data + 0x158) += arg1[0] & 0x00FF0000;

    if (*(u32 *)(data + 0x158) > 0x7F0000) {
        *(u32 *)(data + 0x158) = 0x7F0000;
    }

    tableId = __rlwimi(arg1[0] >> 24, arg1[1], 8, 16, 23);

    result = *(u32 *)(data + 0x158);

    if (tableId != 0xFFFF) {
        table = (u8 *)fn_80250884((u16)tableId);

        if (table != 0) {
            index = result >> 16;
            fraction = result & 0xFFFF;

            if (index < 0x7F) {
                s32 next;
                s32 current;

                current = table[index];
                next = table[index + 1];

                next -= current;
next = fraction * next;
result = next + ((u8)current << 16);
            } else {
                result = table[index] << 16;
            }
        }
    }

    *(u32 *)(data + 0x158) = result;

    *(u32 *)(data + 0x114) |= 0x1000;
}
#pragma use_lmw_stmw reset
void fn_80252058(void *arg0, u32 *arg1) {
void fn_8026146C(s32 *);
void fn_8026147C(u32 *, s32);
u32 fn_802614C4(u32);
s32 fn_80250884(u16);
u32 time;
u32 duration;
u32 original;
u8 *voice;
s32 value;
u32 *command=arg1;
u32 word0;
u16 tableId;
u8 *table;
u32 index, fraction;
voice=arg0;
original=*(u32*)(voice+0x158);
time=command[1]>>16;
if((command[1]>>8)&1) fn_8026146C((s32*)&time);
else fn_8026147C(&time,(s32)voice);
duration=fn_802614C4(time);
if(!duration) duration=1;
word0=command[0];
value=(*(u32*)(voice+0x158)*((word0>>8)&255))>>7;
value+=word0&0xFF0000;
if((u32)value>0x7F0000) value=0x7F0000;
tableId=__rlwimi(word0>>24,command[1],8,16,23);
if(tableId!=65535) {
table=(u8*)fn_80250884(tableId);
if(table) {
index=(u32)value>>16; fraction=value&65535;
if(index<127) {s32 current=table[index]; s32 next=table[index+1]; value=fraction*(next-current)+((u8)current<<16);}
else value=table[index]<<16;
}
}
*(u32*)(voice+0x19C)=value;
*(u32*)(voice+0x1A0)=original;
*(s32*)(voice+0x198)=(s32)(value-original)/(s32)duration;
*(u32*)(voice+0x158)=original;
*(unsigned long long*)(voice+0x114)|=0x8000;
}

void fn_80252188(void *arg0, u32 *arg1)
{
    void fn_8026146C(s32 *);
    void fn_8026147C(u32 *, s32);
    u32 fn_802614C4(u32);
    s32 fn_80250884(u16);

    u8 *voice;
    u32 time;
    u32 word0;
    u32 word1;
    u32 value;
    u32 factor;
    u32 tableId;
    u32 index;
    u32 fraction;
    u32 current;
    u32 next;
    u32 duration;
    u8 *table;

    voice = (u8 *)arg0;

    word0 = arg1[0];
    word1 = arg1[1];

    time = word1 >> 16;

    if (word1 & 0x100) {
        fn_8026146C((s32 *)&time);
    } else {
        fn_8026147C(&time, (s32)arg0);
    }

    duration = fn_802614C4(time);

    if (duration == 0) {
        duration = 1;
    }

    factor = (word0 >> 8) & 0xFF;

    value = *(u32 *)(voice + 0x158);

    value = ((value * factor) >> 7) +
            (word0 & 0x00FF0000);

    if (value > 0x7F0000) {
        value = 0x7F0000;
    }

    tableId = (word0 >> 24) | ((word1 & 0xFF) << 8);

    if (tableId != 0xFFFF) {
        table = (u8 *)fn_80250884((u16)tableId);

        if (table != 0) {
            index = value >> 16;
            fraction = value & 0xFFFF;

            if (index < 0x7F) {
                current = table[index];
                next = table[index + 1];

                value = (current << 16) +
                        fraction * (next - current);
            } else {
                value = table[index] << 16;
            }
        }
    }

    *(u32 *)(voice + 0x19C) = value;
    *(u32 *)(voice + 0x1A0) = 0;
    *(s32 *)(voice + 0x198) = (s32)value / (s32)duration;
    *(u32 *)(voice + 0x158) = 0;

    *(u32 *)(voice + 0x118) |= 0x8000;
}

void fn_802522C4(void *arg0, u32 *arg1)
{
    u16 fn_802611F8(void);
    s32 fn_802575A0(void *);
    void fn_80260174(u8, u8, u8);
    s32 fn_80250B58(void *, u32 *);

    u8 *voice;
    u32 word0;
    u32 word1;
    u32 minimum;
    u32 maximum;
    u32 randomValue;
    u32 pitch;
    u32 command;
    s32 temp;

    voice = (u8 *)arg0;
    word0 = arg1[0];
    word1 = arg1[1];

    if (((word1 >> 8) & 0xFF) == 0) {
        minimum = (word0 >> 8) & 0xFF;
        maximum = word0 >> 24;

        if (minimum > maximum) {
            temp = minimum;
            minimum = maximum;
            maximum = temp;
        }
    } else {
        temp = *(u16 *)(voice + 0x12E);
        minimum = temp - ((word0 >> 8) & 0xFF);
        maximum = temp + (word0 >> 24);

        if ((s32)minimum < 0) {
            minimum = 0;
        } else if ((s32)minimum > 0x7F) {
            minimum = 0x7F;
        }

        if ((s32)maximum < 0) {
            maximum = 0;
        } else if ((s32)maximum > 0x7F) {
            maximum = 0x7F;
        }
    }

    if ((word1 & 0xFF) != 0) {
        randomValue = fn_802611F8();
        pitch = (randomValue % 201) - 100;
        pitch &= 0xFF;
    } else {
        pitch = (word0 >> 16) & 0xFF;
    }

    randomValue = fn_802611F8();

    temp = (s32)maximum - (s32)minimum + 1;
    randomValue = (s32)randomValue % temp;

    randomValue += minimum;

    command = (pitch << 16) | 0x19;
    command |= randomValue << 8;

    arg1[0] = command;
    arg1[1] = 0;

    *(u16 *)(voice + 0x12E) = (command >> 8) & 0x7F;
    *(u8 *)(voice + 0x130) = command >> 16;

    if (fn_802575A0(arg0) != 0) {
        fn_80260174(
            *(u8 *)(voice + 0x121),
            *(u8 *)(voice + 0x122),
            (u8)*(u16 *)(voice + 0x12E)
        );
    }

    arg1[0] = 4;
    fn_80250B58(arg0, arg1);
}

void Sound_SelectSource0(void *voice, u32 *step) {
    /* MusyX select-source macro for modulator slot 0 (voice+0x224). */
    SelectSource(voice, (u8 *)voice + 0x224, step, 0x80000, 1);
}

void fn_80252564(void *voice, u32 *step) { SelectSource(voice, (u8*)voice+0x248, step, 0x100000, 2); }

void Sound_SelectSource3(void *voice, u32 *step) {
    /* MusyX select-source macro for modulator slot 3 (voice+0x290). */
    SelectSource(voice, (u8 *)voice + 0x290, step, 0x200000, 8);
}

void fn_8025276C(void *voice, u32 *step) { SelectSource(voice, (u8*)voice+0x2D8, step, 0x400000, 0x20); }

void fn_80252870(void *arg0, u32 *arg1)
{
    void fn_8025FFC8(void *, u8, s32, u8, u8, u8);

    u8 *voice;
    u32 flags114;
    u32 flags118;
    u32 word0;
    u32 word1;
    u8 value;
    s32 scale;
    s32 adjustment;

    voice = (u8 *)arg0;

    flags114 = *(u32 *)(voice + 0x114);
    flags118 = *(u32 *)(voice + 0x118);

    if ((flags118 & 0x02000000) == 0) {
        *(u32 *)(voice + 0x118) = flags118 | 0x02000000;
        *(u32 *)(voice + 0x114) = flags114;
    } else {
        word0 = arg1[0];
        word1 = arg1[1];

        scale = (s32)(word0 & 0xFFFF0000) / 100;

        adjustment =
            ((s32)(s8)(word1 >> 16) << 8) / 100;

        if (scale < 0) {
            scale -= adjustment;
        } else {
            scale += adjustment;
        }

        value = (u8)(word1 >> 8);

        fn_8025FFC8(
            voice + 0x2FC,
            (u8)(word0 >> 8),
            scale,
            (u8)word1,
            value != 0,
            value
        );
    }

    *(u32 *)(voice + 0x220) |= 0x40;
}

void Sound_SelectSource7(void *voice, u32 *step) {
    /* MusyX select-source macro for modulator slot 7 (voice+0x320). */
    SelectSource(voice, (u8 *)voice + 0x320, step, 0x01000000, 0x80);
}

#pragma optimization_level 4
#pragma global_optimizer on
#pragma use_lmw_stmw on
void fn_80252A78(void *voice, u32 *step) { SelectSource(voice, (u8*)voice+0x368, step, 0x800000, 0x200); }
#pragma use_lmw_stmw reset
#pragma global_optimizer reset
#pragma optimization_level reset
void fn_80252B7C(void *voice, u32 *step) { SelectSource(voice, (u8*)voice+0x344, step, 0x20000000, 0x100); }
#pragma global_optimizer on
void Sound_SelectSource10(void *voice, u32 *step) {
    /* MusyX select-source macro for modulator slot 10 (voice+0x38C). */
    SelectSource(voice, (u8 *)voice + 0x38C, step, 0x40000000, 0x400);
}

void Sound_SelectSource11(void *voice, u32 *step) {
    /* MusyX select-source macro for modulator slot 11 (voice+0x3B0). */
    SelectSource(voice, (u8 *)voice + 0x3B0, step, 0x80000000, 0x800);
}

void Sound_SelectSource2(void *voice, u32 *step) {
    /* MusyX select-source macro for modulator slot 2 (voice+0x26C). */
    SelectSource(voice, (u8 *)voice + 0x26C, step, 0x4000000, 4);
}

void fn_80252F8C(void *voice, u32 *step) { SelectSource(voice, (u8 *)voice + 0x2B4, step, 0x08000000, 0x10); }

void Sound_SelectSource12(void *voice, u32 *step) {
    /* MusyX select-source macro for modulator slot 12 (voice+0x3D4). */
    SelectSource(voice, (u8 *)voice + 0x3D4, step, 0x10000000, 0x1000);
}

void fn_80253194(void *voice, u32 *step) { SelectSource(voice, (u8 *)voice + 0x3F8, step, 0x40, 0x2000); }

void fn_80253298(void *voice, u32 *step) { SelectSource(voice, (u8 *)voice + 0x41C, step, 0x800, 0x4000); }

#pragma optimization_level 3
#pragma global_optimizer off
#pragma use_lmw_stmw off
void fn_8025339C(void *voice, u32 *step) {
    void fn_8025FFC8(void *, u8, s32, u8, s32, u8);
    void fn_8025EEE8(u8, u8, s32);
    u32 tableIndex;
u32 word;
    u32 word0;
    s64 flags;
    s64 mask;
    u8 slot;
u8 controller;
    u32 key;
    s32 pitch;
    s32 adj;
    u32 param;
    void *dest;
    word = step[1];
    mask = *(s64 *)((u8 *)lbl_8029F3D0 + __rlwinm(word,11,21,28));
    flags = *(s64 *)((u8 *)voice + 0x114);
    slot = 0;
    key=word>>24;
    dest = lbl_8034D034 + *(u8 *)((u8 *)voice + 0x11F) * 0x90 + key * 0x24;
    tableIndex = __rlwinm(word,10,22,29);
    key = *(u32 *)((u8 *)lbl_8029F3F0 + tableIndex);
    if ((flags & mask) == 0) {
        *(s64 *)((u8 *)voice + 0x114) = flags | mask;
    } else {
        slot = (u8)word;
    }
    word0 = step[0];
    pitch = (s32)(word0 & 0xFFFF0000) / 100;
    if (pitch < 0) {
        adj = ((s32)((s8)(step[1] >> 16) << 8)) / 100;
        pitch = pitch - adj;
    } else {
        adj = ((s32)((s8)(step[1] >> 16) << 8)) / 100;
        pitch = pitch + adj;
    }
    controller = (u8)(word0 >> 8);
    param = (step[1] >> 8)&255;
    fn_8025FFC8(dest, controller, pitch, slot, (u8)(param != 0), param);
    if (key & 0x80000000) {
        fn_8025EEE8(*(u8 *)((u8 *)voice + 0x121), *(u8 *)((u8 *)voice + 0x122), key);
    } else {
        *(u32 *)((u8 *)voice + 0x220) |= key;
    }
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset
#pragma optimization_level reset
#pragma optimization_level 3
#pragma global_optimizer off
#pragma use_lmw_stmw off
void fn_80253518(void *voice, u32 *step) {
    void fn_8025FFC8(void *, u8, s32, u8, s32, u8);
    void fn_8025EEE8(u8, u8, s32);
    u32 tableIndex;
u32 word;
    u32 word0;
    u64 flags;
    u64 mask;
    u8 slot;
u8 controller;
    u32 key;
    s32 pitch;
    s32 adj;
    u8 param;
    void *dest;
    word = step[1];
    mask = *(u64 *)((u8 *)lbl_8029F400 + __rlwinm(word,11,21,28));
    flags = *(u64 *)((u8 *)voice + 0x114);
    slot = 0;
    key=word>>24;
    dest = lbl_8034CBB4 + *(u8 *)((u8 *)voice + 0x11F) * 0x90 + key * 0x24;
    tableIndex = __rlwinm(word,10,22,29);
    key = *(u32 *)((u8 *)lbl_8029F420 + tableIndex);
    if ((flags & mask) == 0) {
        *(u64 *)((u8 *)voice + 0x114) = flags | mask;
    } else {
        slot = (u8)word;
    }
    word0 = step[0];
    pitch = (s32)(word0 & 0xFFFF0000) / 100;
    if (pitch < 0) {
        adj = ((s32)((s8)(step[1] >> 16) << 8)) / 100;
        pitch = pitch - adj;
    } else {
        adj = ((s32)((s8)(step[1] >> 16) << 8)) / 100;
        pitch = pitch + adj;
    }
    controller = (u8)(word0 >> 8);
    param = (u8)(step[1] >> 8);
    fn_8025FFC8(dest, controller, pitch, slot, (u8)(param != 0), param);
    if (key & 0x80000000) {
        fn_8025EEE8(*(u8 *)((u8 *)voice + 0x121), *(u8 *)((u8 *)voice + 0x122), key);
    } else {
        *(u32 *)((u8 *)voice + 0x220) |= key;
    }
}
#pragma use_lmw_stmw reset
#pragma global_optimizer reset
#pragma optimization_level reset

void fn_80253694(void *arg0, u32 *cmd) {
  void fn_8026146C(s32 *);
  void fn_8026147C(u32 *, s32);
  void Sound_WriteParamU8(s32, s32, u8, s32);
  u16 Sound_GetChanParam(u8, u8, u8);
  void fn_80247F94(void *);
  u8 *voice;
  u32 time;
  u32 mode;

  voice = (u8 *)arg0;
  voice[0x133] = (cmd[0] >> 16) & 0xFF;
  time = cmd[1] >> 16;
  if ((cmd[1] >> 8) & 1) {
    fn_8026146C((s32 *)&time);
  } else {
    fn_8026147C(&time, (s32)voice);
  }
  *(u32 *)(voice + 0x138) = time;

  mode = (cmd[0] >> 8) & 0xFF;
  switch (mode) {
  case 0:
    if (voice[0x121] != 0xFF) {
      Sound_WriteParamU8(0x41, voice[0x121], voice[0x122], 0);
    }
    *(u64 *)(voice + 0x114) &= ~0x400ULL;
    break;
  case 1:
    if (voice[0x121] != 0xFF) {
      Sound_WriteParamU8(0x41, voice[0x121], voice[0x122], 0x7F);
    }
  set_flag:
    if ((*(u64 *)(voice + 0x114) & 0x400ULL) == 0) {
      fn_80247F94(voice);
    }
    *(u32 *)(voice + 0x118) |= 0x400;
    break;
  case 2:
    if (voice[0x121] != 0xFF) {
      if (Sound_GetChanParam(0x41, voice[0x121], voice[0x122]) > 0x1F80U) {
        goto set_flag;
      }
    }
    break;
  }
}

s16 fn_802537F8(SynthVmState *arg0, u32 arg1, s32 arg2) {
    u16 fn_80260F18(SynthVmState *, s32);
    extern s32 lbl_8034CB74[];
    s32 val;
    u8 idx;

    if (arg1 != 0) {
        val = (u16)fn_80260F18(arg0, arg2);
    } else {
        idx = (u8)(arg2 & 0x1F);
        if (idx < 16) {
            val = arg0->regs[idx];
        } else {
            val = lbl_8034CB74[idx - 16];
        }
    }
    return (s16)val;
}

void fn_80253860(SynthVmState *arg0, u32 *arg1, u8 op) {
    u16 fn_80260F18(SynthVmState *);
    void fn_80261014(SynthVmState *, s32, s16);
    extern s32 lbl_8034CB74[];
    s32 res;
    s32 lhs;
    s16 rhs;
    u32 v1;
    u32 raw;
    u32 a;
    u32 w;
    u8 idx;
    u8 b0;
    u8 b1;
    u8 b2;

    b0 = arg1[1];
    a = arg1[0];
    if (a >> 24) {
        v1 = fn_80260F18(arg0);
    } else {
        idx = b0 & 0x1F;
        if (idx < 16) {
            v1 = arg0->regs[idx];
        } else {
            v1 = lbl_8034CB74[idx - 16];
        }
    }
    lhs = (s16)v1;

    if (op == 4) {
        rhs = (s16)(arg1[1] >> 8);
    } else {
        w = arg1[1];
        b1 = (w >> 16) & 0xFF;
        if ((w >> 8) & 0xFF) {
            raw = fn_80260F18(arg0);
        } else {
            idx = b1 & 0x1F;
            if (idx < 16) {
                raw = arg0->regs[idx];
            } else {
                raw = lbl_8034CB74[idx - 16];
            }
        }
        rhs = (s16)raw;
    }

    switch (op) {
    case 0:
    case 4:
        res = lhs + rhs;
        break;
    case 1:
        res = lhs - rhs;
        break;
    case 2:
        res = lhs * rhs;
        break;
    case 3:
        if (rhs != 0) {
            res = lhs / rhs;
        } else {
            res = 0;
        }
        break;
    }

    b2 = (arg1[0] >> 16) & 0xFF;
    if ((arg1[0] >> 8) & 0xFF) {
        s32 c = res < -0x8000 ? -0x8000 : (res > 0x7FFF ? 0x7FFF : res);
        fn_80261014(arg0, b2, (s16)c);
    } else {
        idx = b2 & 0x1F;
        if (idx < 16) {
            s32 c = res < -0x8000 ? -0x8000 : (res > 0x7FFF ? 0x7FFF : res);
            arg0->regs[idx] = (s16)c;
        } else {
            s32 c = res < -0x8000 ? -0x8000 : (res > 0x7FFF ? 0x7FFF : res);
            lbl_8034CB74[idx - 16] = (s16)c;
        }
    }
}

#pragma opt_common_subs off
void fn_80253A80(void *arg0, u32 *arg1, u8 arg2)
{
  extern u32 lbl_8034CB74[];
  u16 fn_80260F18(s32, s32);
  u8 *voice;
  u32 word0;
  u32 word1;
  u8 index;
  u32 selector;
  u32 left;
  u32 right;
  u8 condition;
  voice = (u8 *) arg0;
  word0 = arg1[0];
  selector = (word0 >> 16) & 0xFF;
  if (((word0 >> 8) & 0xFF) != 0)
  {
    left = fn_80260F18((s32) arg0, selector);
  }
  else
  {
    index = selector & 0x1F;
    if (index < 0x10)
    {
      left = (((0, (u32 *) voice)) + index)[0x2B];
    }
    else
    {
      left = lbl_8034CB74[index - 16];
    }
  }
  word0 = arg1[0];
  word1 = arg1[1];
  selector = word1 & 0xFF;
  if ((word0 >> 24) != 0)
  {
    right = fn_80260F18((s32) arg0, selector);
  }
  else
  {
    index = selector & 0x1F;
    if (index < 0x10)
    {
      right = (((0, (u32 *) voice)) + index)[0x2B];
    }
    else
    {
      right = lbl_8034CB74[index - 16];
    }
  }
  switch (arg2)
  {
    case 0:
      condition = left == right;
      break;
    case 1:
      condition = ((s32) right) > ((s32) left);
      break;
  }
  word1 = arg1[1];
  if (((word1 >> 8) & 0xFF) != 0)
  {
    condition = !condition;
  }
  if (condition != 0)
  {
    *((u32 *) (voice + 0x38)) = (*((u32 *) (voice + 0x34))) + ((word1 >> 16) << 3);
  }
}
#pragma opt_common_subs reset
extern void (*lbl_803689AC)(u32,u32);
#pragma opt_strength_reduction off
void fn_80253BCC(SynthVmState *arg0, void *arg1) {
    s32 Sound_LookupVid();
    extern s32 lbl_8034CB74[];
    extern void (*lbl_803689AC)(u32, u32);
    void Sound_DeactivateSynthVoice(void *);
    extern u8 gSoundData[];
    extern s32 gSynthVoices;
    u32 id;
    u32 value;
    u8 i;
    u8 *state;
    u32 bits;
    u32 raw;
    u8 index;
    s32 result;
    u32 *p;
    u32 *dummy;

    bits = *(u32 *)((u8 *)arg1 + 4);
    index = (bits >> 8) & 31;
    if (index < 16) {
        value = arg0->regs[index];
    } else {
        value = lbl_8034CB74[index - 16];
    }
    raw = *(u32 *)arg1;
    if ((u8)(raw >> 8) == 0) {
        id = raw >> 16;
        if (id != 0xFFFF) {
            for (i = 0; i < gSoundData[0x210]; i++) {
                state = (u8 *)gSynthVoices + i * 0x458;
                if (*(u32 *)(state + 0x34) != 0 && id == *(u16 *)(state + 0x104)) {
                    result = Sound_LookupVid(*(u32 *)(*(u8 **)(state + 0xF8) + 8));
                    if ((u32)result != 0xFFFFFFFF) {
                        state = (u8 *)gSynthVoices + (u8)result * 0x458;
                        if (state[0x440] < 4) {
                            state[0x440]++;
                            ((SynthMessageQueue *)state)->slots[state[0x442]] = value;
                            state[0x442] = (state[0x442] + 1) & 3;
                            if (state[0x68] != 0 && *(u32 *)(state + 0x58) != 0) {
                                *(u32 *)(state + 0x38) = *(u32 *)(state + 0x64);
                                *(u32 *)(state + 0x34) = *(u32 *)(state + 0x58);
                                *(u32 *)(state + 0x58) = 0;
                                Sound_DeactivateSynthVoice(state);
                            }
                        }
                    }
                }
            }
        } else if (lbl_803689AC) {
            lbl_803689AC(*(u32 *)(*(u8 **)((u8 *)arg0 + 0xF8) + 8), value);
        }
    } else {
        index = bits & 31;
        if (index < 16) {
            result = arg0->regs[index];
        } else {
            result = lbl_8034CB74[index - 16];
        }
        result = Sound_LookupVid(result);
        if ((u32)result != 0xFFFFFFFF) {
            state = (u8 *)gSynthVoices + (u8)result * 0x458;
            if (state[0x440] < 4) {
                state[0x440]++;
                p = (u32 *)state + state[0x442];
                dummy = *&p;
                dummy[0x111] = value;
                state[0x442] = (state[0x442] + 1) & 3;
                if (state[0x68] != 0 && *(u32 *)(state + 0x58) != 0) {
                    *(u32 *)(state + 0x38) = *(u32 *)(state + 0x64);
                    *(u32 *)(state + 0x34) = *(u32 *)(state + 0x58);
                    *(u32 *)(state + 0x58) = 0;
                    Sound_DeactivateSynthVoice(state);
                }
            }
        }
    }
}
#pragma opt_strength_reduction on
void fn_80253E10(SynthVmState *arg0, u32 *arg1) {
    extern s32 lbl_8034CB74[];
    u32 val;
    u8 idx;

    val = *arg1;
    if ((u8)(val >> 16) == 0) {
        idx = (val >> 8) & 0x1F;
        val = *(u32 *)(*(u8 **)((u8 *)arg0 + 0xF8) + 8);
        if (idx < 16) {
            arg0->regs[idx] = (s32)val;
        } else {
            lbl_8034CB74[idx - 16] = (s32)val;
        }
    } else {
        idx = (val >> 8) & 0x1F;
        val = *(u32 *)((u8 *)arg0 + 0x108);
        if (idx < 16) {
            arg0->regs[idx] = (s32)val;
        } else {
            lbl_8034CB74[idx - 16] = (s32)val;
        }
    }
}

void fn_80253E90(u8 *self, u32 *arg1) {
  extern u8 gSoundData[];
  extern s32 gSynthVoices;
  void fn_80255100(void *);
  void fn_80256FF0(u32);
  u8 *voice;
  u32 word;
  u32 offset;
  u32 i;
  u32 midByte;
  u32 nonzero;
  u32 hiByte;
  u8 *sd;

  self[0x106] = (offset = 0);
  word = *arg1;
  hiByte = (word >> 16) & 255;
  midByte = (word >> 8) & 255;
  nonzero = hiByte != 0;
  if (midByte == 0)
    return;
  i = 0;
  sd = gSoundData;
  for (; i < sd[0x210]; offset += 0x458, i++) {
    voice = (u8 *)gSynthVoices + offset;
    if (*(u32 *)(voice + 0x34) == 0)
      continue;
    if ((*(u64 *)(voice + 0x114) & 2ULL) != 0)
      continue;
    if (midByte != voice[0x106])
      continue;
    if (nonzero == 0)
      fn_80255100(voice);
    else
      fn_80256FF0(i);
  }
  self[0x106] = midByte;
}

void fn_80253F6C(void *arg0) {
void *fn_8025FF28(u8,u8);
u8 fn_802601B0(u8,u8);
void fn_80260174(u8,u8,u8);
void fn_80257614(void *);
void fn_802618E4(s32);
void fn_80260BE4(u8 *);
void fn_80255B20(void *);
void fn_802567B0(void *);
void fn_80255100(void *);
s32 fn_802607F4(void *);
u16 fn_802611F8(void);
extern u32 lbl_80368A20[2];
u32 *cmd,*pc;
s32 value;
u32 id, i, insn;
s32 done;
u8 *v=arg0;
u8 key;
u8 *p;
if (M2C_FIELD(v,u64 *,0x114)&3) {
 if(M2C_FIELD(v,u64 *,0x114)&1) {
 M2C_FIELD(v,u64 *,0x114)&=~1ULL;
 fn_802618E4((u8)M2C_FIELD(v,u32 *,0xf4));
 }
 M2C_FIELD(v,u32 *,0x174)=M2C_FIELD(v,u32 *,0x184)=v[0x215]<<16;
 M2C_FIELD(v,u32 *,0x178)=M2C_FIELD(v,u32 *,0x188)=0;
 M2C_FIELD(v,u32 *,0x158)=v[0x214]<<16;
 v[0x196]=0;
 M2C_FIELD(v,u32 *,0x15c)=M2C_FIELD(v,u32 *,0x158);
 v[0x121]=v[0x216];v[0x122]=v[0x217];v[0x123]=v[0x218];v[0x120]=v[0x219];
 v[0x197]=v[0x21c];v[0x106]=0;
 M2C_FIELD(v,u16 *,0x154)=0;M2C_FIELD(v,u16 *,0x170)=0;
 fn_80260BE4(v);
 key=fn_802601B0(v[0x121],v[0x122]);
 if(key!=255) v[0x132]=key; else v[0x132]=v[0x131];
 fn_80260174(v[0x121],v[0x122],v[0x131]);
 fn_80257614(v);
 v[0x11e]=v[0x21a];v[0x11f]=v[0x21b];
 M2C_FIELD(v,u32 *,0x140)=0;M2C_FIELD(v,u32 *,0x138)=0x6400;v[0x133]=0;
 if(v[0x121]!=255) M2C_FIELD(v,u16 *,0x134)=Sound_GetChanParam(0x41,v[0x121],v[0x122]);
 else M2C_FIELD(v,u16 *,0x134)=0;
 p=fn_8025FF28(v[0x121],v[0x122]);
 v[0x1da]=p[0];v[0x1db]=p[0];
 M2C_FIELD(v,u32 *,0x1e0)=M2C_FIELD(p,u32 *,1);
 M2C_FIELD(v,u32 *,0x1e4)=M2C_FIELD(p,u32 *,5);
 v[0x194]=0x80;v[0x195]=0;
 M2C_FIELD(v,u16 *,0xaa)=0;
 v[0x1bc]=0;v[0x1bd]=0;
 M2C_FIELD(v,u32 *,0x1a4)=0;M2C_FIELD(v,u32 *,0x1a8)=0;
 M2C_FIELD(v,u32 *,0x1c4)=0;M2C_FIELD(v,u16 *,0x1c8)=0;M2C_FIELD(v,u16 *,0x1ca)=0x7fff;
 M2C_FIELD(v,u32 *,0x1d0)=0;M2C_FIELD(v,u16 *,0x1d4)=0;M2C_FIELD(v,u16 *,0x1d6)=0x7fff;
 M2C_FIELD(v,u32 *,0x50)=0;M2C_FIELD(v,u32 *,0x54)=0;M2C_FIELD(v,u32 *,0x58)=0;v[0x68]=0;
 M2C_FIELD(v,u32 *,0x124)=-1;M2C_FIELD(v,u32 *,0x128)=-1;
 M2C_FIELD(v,u16 *,0x12c)=0xffff;M2C_FIELD(v,u16 *,0x1dc)=0x2000;M2C_FIELD(v,u16 *,0x454)=0;
 M2C_FIELD(v,u64 *,0x114)&=8;
 M2C_FIELD(v,u32 *,0x114)|=0x3000;
 memset(v+0xac,0,0x40);
 M2C_FIELD(v,u64 *,0xa0)=((u64)(u32)gSynthTimeHi<<32)|(u32)gSynthTimeLo;
 M2C_FIELD(v,u64 *,0x90)=((u64)(u32)gSynthTimeHi<<32)|(u32)gSynthTimeLo;
 fn_80249D6C(v);
}

*(u8 *)&lbl_80368A38=0;
cmd=lbl_80368A20;
do {
 if(++*(u8 *)&lbl_80368A38>32) break;
 pc=M2C_FIELD(v,u32 **,0x38);
 done=0;
 cmd[0]=pc[0];cmd[1]=pc[1];
 M2C_FIELD(v,u32 **,0x38)=pc+2;
 insn=cmd[0];
 switch(insn&127) {
 case 0:
 fn_80255B20(v);fn_802567B0(v);done=1;break;
 case 1:
 fn_80255B20(v);fn_802567B0(v);done=1;break;
 case 2:
 if(M2C_FIELD(v,u16 *,0x12e)>=(s32)((insn>>8)&255)) {
 p=fn_802506A8(insn>>16);if(p) {M2C_FIELD(v,void **,0x34)=p;M2C_FIELD(v,void **,0x38)=p+(u16)cmd[1]*8;}
 } break;
 case 3:
 if(((M2C_FIELD(v,u32 *,0x158)>>16)&255)>=((insn>>8)&255)) {
 p=fn_802506A8(insn>>16);if(p) {M2C_FIELD(v,void **,0x34)=p;M2C_FIELD(v,void **,0x38)=p+(u16)cmd[1]*8;}
 } break;
 case 4: done=fn_80250B58(v,cmd);break;
 case 5: fn_80250F18(v,cmd);break;
 case 6:
 p=fn_802506A8(insn>>16);
 if(p) {M2C_FIELD(v,void **,0x34)=p;M2C_FIELD(v,void **,0x38)=p+(u16)cmd[1]*8;done=0;}
 else {fn_80255B20(v);fn_802567B0(v);done=1;}break;
 case 7: ((u8 *)cmd)[6]=1;done=fn_80250B58(v,cmd);break;
 case 8: fn_8025106C(v,cmd);break;
 case 9:
 insn=((v[0x131]+((insn>>8)&255))<<8)|(insn&0xffff0000);
 for(i=0;i<gSoundData[0x210];i++) {
 u8 *voice=(u8 *)gSynthVoices+i*0x458;
 id=insn|i;
 if(M2C_FIELD(voice,u32 *,0xf4)==id && id!=0xffffffff) {
 voice=(u8 *)gSynthVoices+(u8)id*0x458;
 if(M2C_FIELD(voice,u32 *,0xf4)==id) fn_80255100(voice);
 }}break;
 case 10:
 if(v[0x121]!=255 && (((u32)fn_802607F4(v)>>7)&255)>=((cmd[0]>>8)&255)) {
 p=fn_802506A8(cmd[0]>>16);if(p){M2C_FIELD(v,void **,0x34)=p;M2C_FIELD(v,void **,0x38)=p+(u16)cmd[1]*8;}
 }break;
 case 11:
 value=(((M2C_FIELD(v,u16 *,0x12e)-(s32)((insn>>16)&255))<<16)*(s8)(insn>>8)>>7)+((insn>>8)&0xff0000);
 if(value<0) value=0;else if(value>0x7f0000)value=0x7f0000;
 M2C_FIELD(v,s32 *,0x174)=M2C_FIELD(v,s32 *,0x184)=value;break;
 case 12: fn_802517EC(v,cmd);break;
 case 13: fn_80251F24(v,cmd);break;
 case 14: fn_80251DEC((Voice *)v,cmd);break;
 case 15: fn_80252058(v,cmd);break;
 case 16: fn_802512D0(v,cmd);break;
 case 17: fn_802618E4((u8)M2C_FIELD(v,u32 *,0xf4));break;
 case 18: M2C_FIELD(v,u32 *,0x118)|=0x80;fn_80249E14(v);break;
 case 19:
 if((u8)fn_802611F8()>=((cmd[0]>>8)&255)) {
 p=fn_802506A8(cmd[0]>>16);if(p){M2C_FIELD(v,void **,0x34)=p;M2C_FIELD(v,void **,0x38)=p+(u16)cmd[1]*8;}
 }break;
 case 20: fn_80252188(v,cmd);break;
 case 21: fn_80251E88((Voice *)v,cmd);break;
 case 22: Sound_ApplyVoiceAdsr((SynthVoice *)v,cmd);break;
 case 23: fn_802522C4(v,cmd);break;
 }
} while(!done);
}

void fn_80254F00(u32 arg0) {
 void Sound_DeactivateSynthVoice(void *);
 void fn_80253F6C(void *);
 s32 Sound_IsHwVoiceActive(s32);
 u64 scheduled;
 u8 *current;
 u8 *next;
 u8 *voice;
 u8 *nextVoice;
 u64 now;
 u32 active;
 current=(u8*)gSynthSchedList;
 goto check;
 while(1) {
  next=*(u8**)(current+0x44);
  Sound_DeactivateSynthVoice(current);
  *(u64*)(current+0xa0)=scheduled;
  current=next;
 check:
  if(current==0) break;
  scheduled=*(u64*)(current+0x98);
  now=((u64)(u32)gSynthTimeHi<<32)|(u32)gSynthTimeLo;
  if(scheduled>now) break;
 }
 voice=(u8*)gSynthIdleList;
 while(voice!=0) {
  nextVoice=*(u8**)(voice+0x3c);
  active=*(u8*)(voice+0x68)? (*(u32*)(voice+0x54)!=0):0;
  if(active && (*(u64*)(voice+0x114)&0x20ULL)==0 && (u32)Sound_IsHwVoiceActive((u8)*(u32*)(voice+0xf4))==0) {
   if(*(u8*)(voice+0x68)!=0 && *(u32*)(voice+0x54)!=0) {
    *(u32*)(voice+0x38)=*(u32*)(voice+0x60);
    *(u32*)(voice+0x34)=*(u32*)(voice+0x54);
    *(u32*)(voice+0x54)=0;
    Sound_DeactivateSynthVoice(voice);
   }
  }
  fn_80253F6C(voice);
  voice=nextVoice;
 }
 now=*(u64*)&gSynthTimeHi+arg0;
 gSynthTimeLo=(u32)now;
 gSynthTimeHi=(u32)(now>>32);
}

void Sound_DeactivateSynthVoice(void *arg0);

void fn_80255054(void *arg0) {
    void Sound_DeactivateSynthVoice(void *);
    u32 var_r0;

    if (*(s32 *)((u8 *)arg0 + 0x4C) == 1) {
        if (*(u8 *)((u8 *)arg0 + 0x68) != 0 && *(void **)((u8 *)arg0 + 0x54) != NULL) {
            *(s32 *)((u8 *)arg0 + 0x38) = *(s32 *)((u8 *)arg0 + 0x60);
            *(void **)((u8 *)arg0 + 0x34) = *(void **)((u8 *)arg0 + 0x54);
            *(void **)((u8 *)arg0 + 0x54) = NULL;
            Sound_DeactivateSynthVoice(arg0);
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        if (var_r0 == 0 && (*(u64 *)((u8 *)arg0 + 0x114) & 0x40000ULL)) {
            Sound_DeactivateSynthVoice(arg0);
        }
    }
}

void fn_80255100(void *arg0) {
    void Sound_DeactivateSynthVoice(void *);
    u32 var_r0;
    u32 flags_hi;
    u32 flags_lo;
    *(u64 *)((u8 *)arg0 + 0x114) |= 8ULL;
    if (*(u32 *)((u8 *)arg0 + 0x34) != 0) {
        flags_hi = *(u32 *)((u8 *)arg0 + 0x114);
        flags_lo = *(u32 *)((u8 *)arg0 + 0x118);
        if ((*(u64 *)((u8 *)arg0 + 0x114) & 0x10000000000ULL) == 0) {
            if (*(u8 *)((u8 *)arg0 + 0x68) != 0 && *(void **)((u8 *)arg0 + 0x50) != NULL) {
                *(s32 *)((u8 *)arg0 + 0x38) = *(s32 *)((u8 *)arg0 + 0x5C);
                *(void **)((u8 *)arg0 + 0x34) = *(void **)((u8 *)arg0 + 0x50);
                *(void **)((u8 *)arg0 + 0x50) = NULL;
                Sound_DeactivateSynthVoice(arg0);
                var_r0 = 1;
            } else { var_r0 = 0; }
            if (var_r0 == 0 && (*(u64 *)((u8 *)arg0 + 0x114) & 4ULL)) {
                Sound_DeactivateSynthVoice(arg0);
            }
        } else {
            *(u32 *)((u8 *)arg0 + 0x118) = flags_lo;
            *(u32 *)((u8 *)arg0 + 0x114) = flags_hi | 0x400;
        }
    }
}

void fn_802551F0(void *arg0, u32 arg1) {
u32 done;
if(arg1) { *(u32 *)((u8 *)arg0+0x114) |= 0x100; return; }
if(*(u32 *)((u8 *)arg0+0x34) && (*(u64 *)((u8 *)arg0+0x114)&0x40000000000ULL)) {
if(*(u8 *)((u8 *)arg0+0x68) && *(void **)((u8 *)arg0+0x50)) {
*(u32 *)((u8 *)arg0+0x38)=*(u32 *)((u8 *)arg0+0x5C);
*(void **)((u8 *)arg0+0x34)=*(void **)((u8 *)arg0+0x50);
*(void **)((u8 *)arg0+0x50)=0;
Sound_DeactivateSynthVoice(arg0); done=1;
} else {done=0;}
if(done==0 && (*(u64 *)((u8 *)arg0+0x114)&4ULL)) Sound_DeactivateSynthVoice(arg0);
}
*(u64 *)((u8 *)arg0+0x114) &= ~0x50000000000ULL;
}

void fn_802552F8(void *arg0)
{
    void *iter;
    void *prev;
    void *p;

    iter = (void *)gSynthSchedList;
    prev = NULL;
    while (iter != NULL && *(u64 *)((u8 *)iter + 0x98) < *(u64 *)((u8 *)arg0 + 0x98)) {
        prev = iter;
        iter = *(void **)((u8 *)iter + 0x44);
    }

    if (iter == NULL) {
        if (prev == NULL) {
            gSynthSchedList = (s32)arg0;
            *(void **)((u8 *)arg0 + 0x44) = NULL;
            *(void **)((u8 *)arg0 + 0x48) = NULL;
        } else {
            *(void **)((u8 *)prev + 0x44) = arg0;
            *(void **)((u8 *)arg0 + 0x48) = prev;
            *(void **)((u8 *)arg0 + 0x44) = NULL;
        }
    } else {
        *(void **)((u8 *)arg0 + 0x44) = iter;
        p = *(void **)((u8 *)iter + 0x48);
        *(void **)((u8 *)arg0 + 0x48) = p;
        if (p != NULL) {
            *(void **)((u8 *)(*(void **)((u8 *)iter + 0x48)) + 0x44) = arg0;
        } else {
            gSynthSchedList = (s32)arg0;
        }
        *(void **)((u8 *)iter + 0x48) = arg0;
    }
}

void Sound_DeactivateSynthVoice(void *voice) {
    /* If active, unlink from the schedule list, clear its timer, and push onto the idle list. */
    void fn_80249DD0(void *);
    extern s32 gSynthTimeHi;
    extern s32 gSynthSchedList;
    extern s32 gSynthIdleList;
    void *prev;
    void *next;
    s32 head;
    u64 schedTime;

    if (*(s32 *)((u8 *)voice + 0x4C) != 0) {
        schedTime = *(u64 *)((u8 *)voice + 0x98);
        if (schedTime != 0) {
            if (schedTime != 0xFFFFFFFFFFFFFFFFULL) {
                prev = *(void **)((u8 *)voice + 0x48);
                if (prev == NULL) {
                    gSynthSchedList = (s32)*(void **)((u8 *)voice + 0x44);
                } else {
                    *(void **)((u8 *)prev + 0x44) = *(void **)((u8 *)voice + 0x44);
                }
                next = *(void **)((u8 *)voice + 0x44);
                if (next != NULL) {
                    *(void **)((u8 *)next + 0x48) = *(void **)((u8 *)voice + 0x48);
                }
            }
            fn_80249DD0(voice);
            *(s32 *)((u8 *)voice + 0x9C) = 0;
            *(s32 *)((u8 *)voice + 0x98) = 0;
            *(u64 *)((u8 *)voice + 0xA0) = *(u64 *)&gSynthTimeHi;
            *(u64 *)((u8 *)voice + 0x114) &= ~0x40004ULL;
        }
        head = gSynthIdleList;
        *(s32 *)((u8 *)voice + 0x3C) = head;
        if ((u32)head != 0) {
            *(void **)((u8 *)gSynthIdleList + 0x40) = voice;
        }
        *(s32 *)((u8 *)voice + 0x40) = 0;
        gSynthIdleList = (s32)voice;
        *(s32 *)((u8 *)voice + 0x4C) = 0;
    }
}

/* Set synth voice run-state; unlink from idle when leaving 0, clear schedule when entering 2. */
void Sound_SetSynthVoiceState(void *voice, s32 newState) {
    extern s32 gSynthIdleList;
    extern s32 gSynthSchedList;
    extern s32 gSynthTimeHi;
    extern s32 gSynthTimeLo;
    void *prev;
    void *next;
    s32 state;
    u64 schedTime;

    state = *(s32 *)((u8 *)voice + 0x4C);
    if (state == newState) {
        return;
    }

    if (state == 0) {
        prev = *(void **)((u8 *)voice + 0x40);
        if (prev == NULL) {
            gSynthIdleList = (s32)*(void **)((u8 *)voice + 0x3C);
        } else {
            *(void **)((u8 *)prev + 0x3C) = *(void **)((u8 *)voice + 0x3C);
        }
        next = *(void **)((u8 *)voice + 0x3C);
        if (next != NULL) {
            *(void **)((u8 *)next + 0x40) = *(void **)((u8 *)voice + 0x40);
        }
    }

    if (newState == 2) {
        schedTime = *(u64 *)((u8 *)voice + 0x98);
        if (schedTime != 0) {
            if (schedTime != 0xFFFFFFFFFFFFFFFFULL) {
                prev = *(void **)((u8 *)voice + 0x48);
                if (prev == NULL) {
                    gSynthSchedList = (s32)*(void **)((u8 *)voice + 0x44);
                } else {
                    *(void **)((u8 *)prev + 0x44) = *(void **)((u8 *)voice + 0x44);
                }
                next = *(void **)((u8 *)voice + 0x44);
                if (next != NULL) {
                    *(void **)((u8 *)next + 0x48) = *(void **)((u8 *)voice + 0x48);
                }
            }
            *(s32 *)((u8 *)voice + 0x9C) = 0;
            *(s32 *)((u8 *)voice + 0x98) = 0;
            *(u64 *)((u8 *)voice + 0xA0) = *(u64 *)&gSynthTimeHi;
            *(u64 *)((u8 *)voice + 0x114) &= ~0x40004ULL;
        }
    }

    *(s32 *)((u8 *)voice + 0x4C) = newState;
}

s32 fn_802555A0(
    u16 arg0, u8 arg1, u32 arg2, u32 arg3,
    u32 arg4, u8 arg5, u8 arg6, u8 arg7,
    u8 arg8, u8 arg9, u16 arg10, u16 arg11,
    u8 arg12, u8 arg13, u8 arg14, u32 arg15)
{
    void fn_8025FF6C(u8, u8);
    void fn_802567B0(void *);
    void fn_80255B20(void *);
    s32 fn_80256628(u8, u32, u32, u32);
    void fn_80256054(void *, u8);
    void fn_8025FB74(u8, u8, u8);
    void *fn_802506A8(u16);
    u16 fn_8024B594(u8, u8);
    u32 Sound_AddVid(SynthVoice *, u32);
    s32 Sound_IsHwVoiceActive(s32);
    void fn_802618E4(int);
    void fn_80249DD0(s32);

    s32 result;
    u32 flags;
    s32 index;
    u8 *sample;
    u8 *voice;
    u8 v13;

    v13 = arg13;
    sample = (u8 *)fn_802506A8(arg0);
    if (sample == 0) {
        goto fail;
    }

    flags = arg4 & 0x80;
    if (flags == 0) {
        u16 mapped = fn_8024B594(arg8, arg7);
        if (mapped != 0xFFFF) {
            arg1 = (u8)mapped;
        }
    }

    index = fn_80256628(arg1, arg2, arg3, flags != 0);
    if ((u32)index == 0xFFFFFFFFu) {
        goto fail;
    }

    voice = (u8 *)gSynthVoices + index * 0x458;
    fn_80255B20(voice);

    if (*(s32 *)(voice + 0x4C) != 2) {
        if (*(s32 *)(voice + 0x4C) == 0) {
            if (*(u8 **)(voice + 0x40) == 0) {
                gSynthIdleList = (s32)*(u8 **)(voice + 0x3C);
            } else {
                *(u8 **)(*(u8 **)(voice + 0x40) + 0x3C) = *(u8 **)(voice + 0x3C);
            }
            if (*(u8 **)(voice + 0x3C) != 0) {
                *(u8 **)(*(u8 **)(voice + 0x3C) + 0x40) = *(u8 **)(voice + 0x40);
            }
        }

        if (*(u64 *)(voice + 0x98) != 0) {
            if (*(u64 *)(voice + 0x98) != 0xFFFFFFFFFFFFFFFFULL) {
                if (*(u8 **)(voice + 0x48) == 0) {
                    gSynthSchedList = (s32)*(u8 **)(voice + 0x44);
                } else {
                    *(u8 **)(*(u8 **)(voice + 0x48) + 0x44) = *(u8 **)(voice + 0x44);
                }
                if (*(u8 **)(voice + 0x44) != 0) {
                    *(u8 **)(*(u8 **)(voice + 0x44) + 0x48) = *(u8 **)(voice + 0x48);
                }
            }
        }

        *(u32 *)(voice + 0x9C) = 0;
        *(u32 *)(voice + 0x98) = 0;
        *(u32 *)(voice + 0xA4) = (u32)gSynthTimeLo;
        *(u32 *)(voice + 0xA0) = (u32)gSynthTimeHi;
        *(u32 *)(voice + 0x118) &= 0xFFFBFFFB;
        *(u32 *)(voice + 0x4C) = 2;
    }

    *(u32 *)(voice + 0x118) =
        (*(u32 *)(voice + 0x118) & 0x10) | 2;
    *(u32 *)(voice + 0x114) = 0;

    if (Sound_IsHwVoiceActive(index) != 0) {
        *(u32 *)(voice + 0x118) |= 1;
    }

    *(u32 *)(voice + 0x9C) = 0;
    *(u32 *)(voice + 0x98) = 0;

    if (flags != 0) {
        *(u8 *)(voice + 0x11D) = 1;
        arg4 &= 0x7F;
        fn_8025FB74((u8)index, 0xFF, 1);
        fn_8025FF6C((u8)index, 0xFF);
        *(u8 *)(voice + 0x216) = (u8)index;
        *(u8 *)(voice + 0x217) = 0xFF;
        *(u8 *)(voice + 0x218) = 0;
    } else {
        *(u8 *)(voice + 0x11D) = 0;
        *(u8 *)(voice + 0x216) = arg7;
        *(u8 *)(voice + 0x217) = arg8;
        *(u8 *)(voice + 0x218) = arg9;
    }

    *(u16 *)(voice + 0x104) = arg0;
    *(u32 *)(voice + 0x100) = arg3;
    *(u32 *)(voice + 0x110) = 0x75300000;
    *(u16 *)(voice + 0x10E) = 0x400;
    *(u32 *)(voice + 0x34) = (u32)sample;
    *(u32 *)(voice + 0x38) = (u32)(sample + ((u32)arg10 << 3));
    *(u8 *)(voice + 0x131) = arg4;
    *(u16 *)(voice + 0x12E) = arg4;
    *(u8 *)(voice + 0x130) = 0;
    *(u8 *)(voice + 0x214) = arg5;
    *(u8 *)(voice + 0x215) = arg6;
    *(u8 *)(voice + 0x219) = (u8)arg11;
    *(u8 *)(voice + 0x8C) = 0;
    *(u8 *)(voice + 0x8D) = 0;
    *(u32 *)(voice + 0xEC) = 0xFFFFFFFF;
    *(u32 *)(voice + 0xF0) = 0xFFFFFFFF;
    *(u32 *)(voice + 0x108) = 0xFFFFFFFF;
    *(u8 *)(voice + 0x21A) = v13;
    *(u8 *)(voice + 0x21B) = arg14;
    *(u8 *)(voice + 0x21C) = arg15 == 0;
    *(u8 *)(voice + 0x442) = 0;
    *(u8 *)(voice + 0x441) = 0;
    *(u8 *)(voice + 0x440) = 0;
    *(u32 *)(voice + 0xF4) =
        (u32)(u8)index | ((u32)arg4 << 8) | ((u32)arg0 << 16);

    fn_80256054(voice, arg1);
    result = (s32)Sound_AddVid((SynthVoice *)voice, arg12);

    if ((u32)result != 0xFFFFFFFFu) {
        if (*(s32 *)(voice + 0x4C) != 0) {
            if (*(u64 *)(voice + 0x98) != 0) {
                if (*(u64 *)(voice + 0x98) != 0xFFFFFFFFFFFFFFFFULL) {
                    if (*(u8 **)(voice + 0x48) == 0) {
                        gSynthSchedList = (s32)*(u8 **)(voice + 0x44);
                    } else {
                        *(u8 **)(*(u8 **)(voice + 0x48) + 0x44) = *(u8 **)(voice + 0x44);
                    }
                    if (*(u8 **)(voice + 0x44) != 0) {
                        *(u8 **)(*(u8 **)(voice + 0x44) + 0x48) = *(u8 **)(voice + 0x48);
                    }
                }
            }

            fn_80249DD0((s32)voice);
            *(u32 *)(voice + 0x9C) = 0;
            *(u32 *)(voice + 0x98) = 0;
            *(u32 *)(voice + 0xA4) = (u32)gSynthTimeLo;
            *(u32 *)(voice + 0xA0) = (u32)gSynthTimeHi;
            *(u32 *)(voice + 0x118) &= 0xFFFBFFFB;
            *(u32 *)(voice + 0x4C) = 0;
            *(u32 *)(voice + 0x114) = 0;

            if (*(u8 **)gSynthIdleList != 0) {
                *(u8 **)(*(u8 **)gSynthIdleList + 0x40) = voice;
            }
            *(u32 *)(voice + 0x40) = 0;
            *(u8 **)(voice + 0x3C) = (u8 *)gSynthIdleList;
            gSynthIdleList = (s32)voice;
            *(u32 *)(voice + 0x4C) = 0;
        }
        return result;
    }

fail:
    if (Sound_IsHwVoiceActive(index) != 0) {
        fn_802618E4(index);
    }
    fn_802567B0(voice);
    return -1;
}

void fn_802559D8(void) {
    s32 *zero;
    s32 offset;
    u32 i;
    s32 two;

    zero = NULL;
    offset = (s32)zero;
    gSynthIdleList = (s32)zero;
    i = 0;
    gSynthSchedList = (s32)zero;
    two = 2;
    gSynthTimeLo = (s32)zero;
    gSynthTimeHi = (s32)zero;

    while (i < gSoundData[0x210]) {
        *(s32 *)(gSynthVoices + offset + 0x34) = (s32)zero;
        *(s32 *)(gSynthVoices + offset + 0x4C) = two;
        *(u16 *)(gSynthVoices + offset + 0xAA) = 0;
        offset += 0x458;
        i++;
    }
}

void fn_80255A40(void)
{
 extern u8 lbl_80359710[];
 extern void *vidListRoot;
 extern void *vidListFree;
 VidList *cur; s32 i; VidList *prev;
 vidGenerator = 0; vidListRoot = NULL;
 cur = (VidList *)lbl_80359710; prev = NULL;
 vidListFree = cur;
 for (i=0; i<128; ++i) {
 cur->prev=prev;
 if(prev) prev->next=cur;
 prev=cur++;
 }
 prev->next=NULL;
}

void fn_80255B20(void *arg0) {
    void fn_80257668(void *);
    extern s32 gSynthVoices;
    extern void *vidListFree;
    extern void *vidListRoot;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r4_3;
    s32 val;
    void **temp_r4;
    void **temp_r4_10;
    void **temp_r4_4;
    void **temp_r4_6;
    void **temp_r4_8;
    void *temp_r3_10;
    void *temp_r3_11;
    void *temp_r3_12;
    void *temp_r3_3;
    void *temp_r3_4;
    void *temp_r3_5;
    void *temp_r3_6;
    void *temp_r3_7;
    void *temp_r3_8;
    void *temp_r3_9;
    void *temp_r4_11;
    void *temp_r4_2;
    void *temp_r4_5;
    void *temp_r4_7;
    void *temp_r4_9;
    void *vp;

    if ((u32)(*(s32 *)((u8 *)arg0 + 0xF4) + 0x10000) != 0xFFFFU) {
        fn_80257668(arg0);
        temp_r3 = *(s32 *)((u8 *)arg0 + 0xF0);
        if ((u32)(temp_r3 + 0x10000) != 0xFFFFU) {
            vp = (void *)(gSynthVoices + ((u8)temp_r3 * 0x458));
            val = *(s32 *)((u8 *)arg0 + 0xEC);
            *(s32 *)((u8 *)vp + 0xEC) = val;
            temp_r3_2 = *(s32 *)((u8 *)arg0 + 0xEC);
            if ((u32)(temp_r3_2 + 0x10000) != 0xFFFFU) {
                vp = (void *)(gSynthVoices + ((u8)temp_r3_2 * 0x458));
                val = *(s32 *)((u8 *)arg0 + 0xF0);
                *(s32 *)((u8 *)vp + 0xF0) = val;
            }
            temp_r3_3 = *(void **)((u8 *)arg0 + 0xF8);
            temp_r4 = *(void ***)((u8 *)temp_r3_3 + 4);
            if (temp_r4 != NULL) {
                *temp_r4 = *(void **)temp_r3_3;
            } else {
                vidListRoot = *(void **)temp_r3_3;
            }
            temp_r3_4 = *(void **)((u8 *)arg0 + 0xF8);
            temp_r4_2 = *(void **)temp_r3_4;
            if (temp_r4_2 != NULL) {
                *(void **)((u8 *)temp_r4_2 + 4) = *(void **)((u8 *)temp_r3_4 + 4);
            }
            *(void **)(*(void **)((u8 *)arg0 + 0xF8)) = vidListFree;
            if (vidListFree != NULL) {
                *(void **)((u8 *)vidListFree + 4) = *(void **)((u8 *)arg0 + 0xF8);
            }
            *(void **)((u8 *)*(void **)((u8 *)arg0 + 0xF8) + 4) = NULL;
            vidListFree = *(void **)((u8 *)arg0 + 0xF8);
            *(void **)((u8 *)arg0 + 0xF8) = NULL;
            return;
        }
        temp_r4_3 = *(s32 *)((u8 *)arg0 + 0xEC);
        if ((u32)(temp_r4_3 + 0x10000) != 0xFFFFU) {
            *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0xF8) + 0xC) = temp_r4_3;
            temp_r3_5 = *(void **)((u8 *)arg0 + 0xFC);
            if (*(void **)((u8 *)arg0 + 0xF8) != temp_r3_5) {
                *(s32 *)((u8 *)temp_r3_5 + 0xC) = *(s32 *)((u8 *)arg0 + 0xEC);
            }
            vp = (void *)(gSynthVoices + ((u8)*(s32 *)((u8 *)arg0 + 0xEC) * 0x458));
            *(s32 *)((u8 *)vp + 0xF0) = -1;
            vp = (void *)(gSynthVoices + ((u8)*(s32 *)((u8 *)arg0 + 0xEC) * 0x458));
            val = (s32)*(void **)((u8 *)arg0 + 0xFC);
            *(s32 *)((u8 *)vp + 0xFC) = val;
            temp_r3_6 = *(void **)((u8 *)arg0 + 0xF8);
            if (temp_r3_6 != *(void **)((u8 *)arg0 + 0xFC)) {
                temp_r4_4 = *(void ***)((u8 *)temp_r3_6 + 4);
                if (temp_r4_4 != NULL) {
                    *temp_r4_4 = *(void **)temp_r3_6;
                } else {
                    vidListRoot = *(void **)temp_r3_6;
                }
                temp_r3_7 = *(void **)((u8 *)arg0 + 0xF8);
                temp_r4_5 = *(void **)temp_r3_7;
                if (temp_r4_5 != NULL) {
                    *(void **)((u8 *)temp_r4_5 + 4) = *(void **)((u8 *)temp_r3_7 + 4);
                }
                *(void **)(*(void **)((u8 *)arg0 + 0xF8)) = vidListFree;
                if (vidListFree != NULL) {
                    *(void **)((u8 *)vidListFree + 4) = *(void **)((u8 *)arg0 + 0xF8);
                }
                *(void **)((u8 *)*(void **)((u8 *)arg0 + 0xF8) + 4) = NULL;
                vidListFree = *(void **)((u8 *)arg0 + 0xF8);
                *(void **)((u8 *)arg0 + 0xF8) = NULL;
            }
            *(void **)((u8 *)arg0 + 0xF8) = NULL;
            *(void **)((u8 *)arg0 + 0xFC) = NULL;
            return;
        }
        temp_r3_8 = *(void **)((u8 *)arg0 + 0xF8);
        if (temp_r3_8 != *(void **)((u8 *)arg0 + 0xFC)) {
            temp_r4_6 = *(void ***)((u8 *)temp_r3_8 + 4);
            if (temp_r4_6 != NULL) {
                *temp_r4_6 = *(void **)temp_r3_8;
            } else {
                vidListRoot = *(void **)temp_r3_8;
            }
            temp_r3_9 = *(void **)((u8 *)arg0 + 0xF8);
            temp_r4_7 = *(void **)temp_r3_9;
            if (temp_r4_7 != NULL) {
                *(void **)((u8 *)temp_r4_7 + 4) = *(void **)((u8 *)temp_r3_9 + 4);
            }
            *(void **)(*(void **)((u8 *)arg0 + 0xF8)) = vidListFree;
            if (vidListFree != NULL) {
                *(void **)((u8 *)vidListFree + 4) = *(void **)((u8 *)arg0 + 0xF8);
            }
            *(void **)((u8 *)*(void **)((u8 *)arg0 + 0xF8) + 4) = NULL;
            vidListFree = *(void **)((u8 *)arg0 + 0xF8);
            *(void **)((u8 *)arg0 + 0xF8) = NULL;
            temp_r3_10 = *(void **)((u8 *)arg0 + 0xFC);
            temp_r4_8 = *(void ***)((u8 *)temp_r3_10 + 4);
            if (temp_r4_8 != NULL) {
                *temp_r4_8 = *(void **)temp_r3_10;
            } else {
                vidListRoot = *(void **)temp_r3_10;
            }
            temp_r3_11 = *(void **)((u8 *)arg0 + 0xFC);
            temp_r4_9 = *(void **)temp_r3_11;
            if (temp_r4_9 != NULL) {
                *(void **)((u8 *)temp_r4_9 + 4) = *(void **)((u8 *)temp_r3_11 + 4);
            }
            *(void **)(*(void **)((u8 *)arg0 + 0xFC)) = vidListFree;
            if (vidListFree != NULL) {
                *(void **)((u8 *)vidListFree + 4) = *(void **)((u8 *)arg0 + 0xFC);
            }
            *(void **)((u8 *)*(void **)((u8 *)arg0 + 0xFC) + 4) = NULL;
            vidListFree = *(void **)((u8 *)arg0 + 0xFC);
            *(void **)((u8 *)arg0 + 0xFC) = NULL;
            return;
        }
        temp_r4_10 = *(void ***)((u8 *)temp_r3_8 + 4);
        if (temp_r4_10 != NULL) {
            *temp_r4_10 = *(void **)temp_r3_8;
        } else {
            vidListRoot = *(void **)temp_r3_8;
        }
        temp_r3_12 = *(void **)((u8 *)arg0 + 0xF8);
        temp_r4_11 = *(void **)temp_r3_12;
        if (temp_r4_11 != NULL) {
            *(void **)((u8 *)temp_r4_11 + 4) = *(void **)((u8 *)temp_r3_12 + 4);
        }
        *(void **)(*(void **)((u8 *)arg0 + 0xF8)) = vidListFree;
        if (vidListFree != NULL) {
            *(void **)((u8 *)vidListFree + 4) = *(void **)((u8 *)arg0 + 0xF8);
        }
        *(void **)((u8 *)*(void **)((u8 *)arg0 + 0xF8) + 4) = NULL;
        vidListFree = *(void **)((u8 *)arg0 + 0xF8);
        *(void **)((u8 *)arg0 + 0xF8) = NULL;
        *(void **)((u8 *)arg0 + 0xFC) = NULL;
    }
}

s32 fn_80255E88(void *arg0) {
    M2C_FIELD(arg0, void **, 0xFC) = (void *) M2C_FIELD(arg0, void **, 0xF8);
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0xF8), s32 *, 8);
}

u32 Sound_AddVid(SynthVoice *sv, u32 isMaster) {
    /* Take a free VidList node, assign a unique vid, insert sorted into the active list, and attach it to the synth voice. */
    extern VidList *vidListRoot;
    extern VidList *vidListFree;
    u32 vid;
    VidList *nvl;
    VidList *vl;
    VidList *lvl;

    vid = GetNewVid();
restart:
    lvl = NULL;
    for (vl = vidListRoot; vl != NULL; vl = vl->next) {
        if (vl->vid > vid) {
            break;
        }
        if (vl->vid == vid) {
            vid = GetNewVid();
            if (vid < vl->vid) {
                goto restart;
            }
        }
        lvl = vl;
    }
    nvl = vidListFree;
    if (nvl == NULL) {
        return -1;
    }
    vidListFree = nvl->next;
    if (vidListFree != NULL) {
        vidListFree->prev = NULL;
    }
    if (lvl == NULL) {
        vidListRoot = nvl;
    } else {
        lvl->next = nvl;
    }
    nvl->prev = lvl;
    nvl->next = vl;
    if (vl != NULL) {
        vl->prev = nvl;
    }
    nvl->vid = vid;
    nvl->root = sv->unkF4;
    sv->unkFC = isMaster ? nvl : NULL;
    sv->unkF8 = nvl;
    return isMaster ? vid : sv->unkF4;
}

#pragma opt_peephole off
