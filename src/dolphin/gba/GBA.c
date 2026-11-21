/* Functions from 0x8022CD68 to 0x80267A7C, found by decomp-toolkit. */
#include "common.h"

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

#pragma opt_strength_reduction off
#pragma use_lmw_stmw on

#pragma use_lmw_stmw off
#pragma opt_strength_reduction on

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

s32 fn_802488C8(u16, u8, u8, s32, u8, s32, s32, u8, s32, s32, s32, s32, s32, s32, s32, s32);
/* Look up a sound by id and start it; 0xFF key/vol/pan use the SoundEntry defaults. */

/* Walk a sound handle's voice chain and set a u8 synth control on each matching voice. */

/* Apply a 16-bit MIDI CC (ctrl) to all voices under handle; returns whether any were updated. */

void fn_80255054(void *arg0);

void fn_80256FF0(Fn80256FF0Arg arg0);

/* Map distance into synth vol param 0x1F (inverted 80..16000 -> 16383..0) and enable flag 0x4F. */

#pragma global_optimizer off
#pragma optimization_level 2

#pragma optimization_level 2

#pragma optimization_level reset

#pragma optimization_level reset
#pragma global_optimizer on

#pragma optimization_level 3

#pragma optimization_level reset
/* Find the index of an active sound slot with the given instance id, or -1. */

#pragma global_optimizer off

#pragma global_optimizer on

#pragma global_optimizer off

#pragma global_optimizer off

#pragma global_optimizer off

#pragma global_optimizer on

#pragma global_optimizer on

#pragma global_optimizer on

#pragma dont_inline reset

/* Insert or bump-ref a sample key in the sorted table; returns 1 if a new entry was added. */

/* Insert or ref an audio-wave key by id into the sorted table; returns 1 if newly inserted. */

#pragma optimization_level 3
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset
#pragma optimization_level reset

#pragma opt_strength_reduction off

#pragma opt_strength_reduction off
/* Decrement audio table ref for id; remove the entry when the last ref drops. */

#pragma opt_strength_reduction on

/* Look up an audio group entry by id across gAudioGroups and fill out. */

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

/* Synth seq cmd: set or add voice volume (0..0x7F), store fine byte, apply if active. */

/* Build ADSR envelope from packed channel params and apply it to the synth voice. */

#pragma global_optimizer off

#pragma global_optimizer on

extern void (*lbl_803689AC)(u32,u32);
#pragma opt_strength_reduction off

#pragma opt_strength_reduction on

void Sound_DeactivateSynthVoice(void *arg0);

/* Set synth voice run-state; unlink from idle when leaving 0, clear schedule when entering 2. */

#pragma peephole off

#pragma peephole on

#pragma global_optimizer off

#pragma global_optimizer on

#pragma optimization_level 3

#pragma optimization_level reset

/* Set volume and per-step delta for the voice's current ADSR phase; return 1 when finished. */

#pragma global_optimizer off
#pragma inline_depth(0)
/* Free any prior stream for callId, allocate a slot, init it, and return id|serial or -1. */

#pragma optimization_level 3

#pragma optimization_level reset

#pragma inline_depth(8)
#pragma global_optimizer reset

/* Bind or unbind an audio resource id by type (table/bank/sample/wave/group). */

/* Find groupId in groupData and register its sample/macro/curve/keymap/layer id lists. */

#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset

/* Allocate and initialize sound voice slots and studio mix buffers. */

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

f64 fn_802387A8(f64, f64);
#pragma fp_contract off

#pragma fp_contract on

#pragma optimization_level 3

#pragma optimization_level reset

#pragma fp_contract off

#pragma optimization_level 3

#pragma optimization_level reset

#pragma global_optimizer off

#pragma global_optimizer on

#pragma optimization_level 3

#pragma optimization_level reset
/* Read channel param `op` from group/channel tables as a 14-bit value (0 if channel is 255). */

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma peephole off

#pragma peephole on

#pragma global_optimizer off

#pragma global_optimizer reset

/* Queue an MRAM→ARAM DMA on the low or high sound queue and post it to ARQ. */

#pragma global_optimizer off

#pragma global_optimizer reset

#pragma scheduling off

#pragma scheduling on

#pragma peephole off

#pragma peephole on

extern u8 lbl_80363F18[16];

#pragma optimization_level 3

#pragma optimization_level reset

/* Mix wet aux into ch0/ch1 if needed, then run aux FX on all three PCM channels. */

extern s32 lbl_803631FC;
extern s32 lbl_80363200;

void fn_80265430(s32 arg0) {
    extern u16 lbl_803669A0[1024];
    u8 *temp_r3;

    temp_r3 = (u8 *) &lbl_803669A0 + (arg0 << 8);
    if ((s32) *(s32 *) (temp_r3 + 0x20) == 0) {
        if (*((u8 *) temp_r3 + 5) != 0 || *((u8 *) temp_r3 + 6) != 4) {
            *(s32 *) (temp_r3 + 0x20) = 1;
            return;
        }
        *(u8 *) *(u32 *) (temp_r3 + 0x14) = *(u8 *) (temp_r3 + 7) & 0x3A;
    }
}

#pragma use_lmw_stmw on
void fn_80265484(void) {
void OSRegisterVersion(char *); void OSInitThreadQueue(void *); void OSInitAlarm(void); void OSRegisterResetFunction(void *); void fn_80215F8C(void);
extern s32 lbl_80368B28; extern char *lbl_803670D8; extern u8 lbl_803669A0[]; extern u8 lbl_803668A0[]; extern s32 lbl_80368B2C; extern u8 lbl_802A4DD8[];
u32 __mulhwu(u32, u32);
u8 *chan; u8 *buf; u32 period; s32 zero; s32 i;
if(lbl_80368B28==0) {
lbl_80368B28=1; OSRegisterVersion(lbl_803670D8);
period = *(u32*)0x800000F8;
period >>= 2;
period = __mulhwu(0x431BDE83, period);
period >>= 15;
period *= 0x3C;
period >>= 3;
zero=0;
for(i=0;i<4;i++){chan=lbl_803669A0+i*0x100; buf=lbl_803668A0+i*0x40; *(u32*)(chan+0x34)=period; *(u32*)(chan+0x30)=zero; OSInitThreadQueue(chan+0x24); *(u8**)(chan+0xF8)=buf; }
OSInitAlarm(); fn_80215F8C(); lbl_80368B2C=0; OSRegisterResetFunction(lbl_802A4DD8);
}}
#pragma use_lmw_stmw reset

s32 fn_80265544(s32 arg0, s32 arg1, u32 arg2) {
 extern u8 lbl_803669A0[];
 extern int fn_80266CFC(int,int,int,void *);
 void fn_80265430(void);
 u8 *entry;
 entry=lbl_803669A0+(arg0<<8);
 if (*(u32 *)(entry+0x1c)!=0) return 2;
 *entry=0;
 *(s32 *)(entry+0x14)=arg1;
 *(u32 *)(entry+0x1c)=arg2;
 return fn_80266CFC(arg0,1,3,fn_80265430);
}

#pragma scheduling on
void GBAGetStatus(s32 chan, s32 dest) {
extern u8 lbl_803669A0[];
extern s32 fn_80266CFC(s32,s32,s32,void*);
extern void fn_80266B6C(s32);
void fn_80265430(s32); void fn_80266B38(void);
u8 *entry;
s32 ret;
u8 dummy[8];

entry = lbl_803669A0 + (chan << 8);
if (*(u32*)(entry+0x1c)) ret=2;
else {
*entry=0;
*(s32*)(entry+0x14)=dest;
*(void**)(entry+0x1c)=fn_80266B38;
ret=fn_80266CFC(chan,1,3,fn_80265430);
}
switch(ret) { case 0: fn_80266B6C(chan); break; default: break; }
}
#pragma scheduling on
s32 fn_80265638(s32 arg0, s32 arg1, u32 arg2) {
    extern u8 lbl_803669A0[];
    extern int fn_80266CFC(int, int, int, void *);
    void fn_80265430(void);
    u8 *entry;

    entry = lbl_803669A0 + (arg0 << 8);
    if (*(u32 *)(entry + 0x1C) != 0) {
        return 2;
    }
    *entry = 0xFF;
    *(s32 *)(entry + 0x14) = arg1;
    *(u32 *)(entry + 0x1C) = arg2;
    return fn_80266CFC(arg0, 1, 3, fn_80265430);
}

#pragma scheduling on
void fn_8026569C(s32 chan, s32 dest) {
extern u8 lbl_803669A0[];
extern s32 fn_80266CFC(s32,s32,s32,void*);
extern void fn_80266B6C(s32);
void fn_80265430(s32);
void fn_80266B38(void);
s32 ret;
u8 dummy[8];
u8 *entry = lbl_803669A0 + (chan << 8);
if (*(u32*)(entry+0x1C)) ret=2;
else {
entry[0]=0xFF;
*(s32*)(entry+0x14)=dest;
*(void**)(entry+0x1C)=fn_80266B38;
ret=fn_80266CFC(chan,1,3,fn_80265430);
}
switch(ret) { case 0: fn_80266B6C(chan); break; default: break; }
}
#pragma peephole on
#pragma global_optimizer reset

#pragma scheduling off
BOOL fn_8026572C(void) {
    extern s32 lbl_80368B2C;
    lbl_80368B2C = 1;
    return 1;
}
#pragma scheduling on
#pragma peephole on
#pragma global_optimizer on
#pragma use_lmw_stmw on
s32 fn_8026573C(s32 arg0, u8 *arg1)
{
    extern u8 lbl_803669A0[];
    extern u32 OSDisableInterrupts(void);
    extern void OSRestoreInterrupts(u32);
    extern s64 OSGetTime(void);
    u8 *entry;
    u8 *queue;
    u32 interruptState;
    s32 status;
    s32 percent;
    s64 elapsed;
    entry = lbl_803669A0 + (arg0 << 8);
    queue = entry + 0x40;
    interruptState = OSDisableInterrupts();
    if (*(u32 *)(queue + 0x14) != 0) {
        status = 2;
        arg0 = (*(s32 *)(queue + 0x34) * 100) / *(s32 *)(queue + 0x64);
        percent = arg0 & 255;
        if (*(s64 *)(queue + 0x28) != 0) {
            elapsed = OSGetTime() - *(s64 *)(queue + 0x28);
            if (elapsed / ((*(volatile u32 *)0x800000F8 >> 2) / 1000) < 5500) {
                percent = (s64)percent * elapsed / ((s64)((*(volatile u32 *)0x800000F8 >> 2) / 1000) * 5500);
                }
            if ((u8)percent >= 100) percent = 100;
        }
        complete:
        if (arg1 != 0) *arg1 = percent;
    } else {
        if (*(u32 *)(entry + 0x1C) != 0) status = 2;
        else status = 0;
    }
    OSRestoreInterrupts(interruptState);
    return status;
}
#pragma use_lmw_stmw on
#pragma global_optimizer reset
#pragma peephole reset
#pragma scheduling on
s32 fn_802658B0(s32 chan,s32 mode,s32 offset,u8 *data,s32 length,void *input,void *callback) {
extern u8 lbl_803669A0[],lbl_802A4DE8[];
s32 fn_8026573C(s32,u8*);
s32 fn_80265544(s32,void*,void*);
void fn_802659EC(s32,s32);
u8 status;
s32 result;
u8 *queue=lbl_803669A0+(chan<<8)+0x40;
if(chan & ~3) return 4;
if(length==0 || 0x40000 < length) return 4;
if(offset< -4 || offset>4) return 4;
if(mode<0 || mode>6) return 4;
if(data[0xAC]*data[0xAD]*data[0xAE]*data[0xAF]==0) return 4;
result=fn_8026573C(chan,&status);
if(result!=0) return result;
*(s32*)(queue)=mode;
*(s32*)(queue+4)=offset;
*(void**)(queue+8)=data;
*(s32*)(queue+12)=length;
*(void**)(queue+16)=input;
*(void**)(queue+20)=callback;
*(u32*)(queue+0x34)=lbl_802A4DE8[8];
result=fn_80265544(chan,*(void**)(queue+16),fn_802659EC);
if(result!=0) *(u32*)(queue+20)=0;
return result;
}

#pragma scheduling on
void fn_802659EC(s32 arg0,s32 arg1) {
extern u8 lbl_803669A0[];
s32 fn_80265638(s32,s32,void*);
void fn_80265A94(s32,s32);
u8 *entry;
u8 *queue;
s32 result=arg1;
void (*callback)(s32,s32);
u8 dummy[8];
entry=lbl_803669A0+(arg0<<8);
queue=entry+0x40;
if(result==0) {
if((result=fn_80265638(arg0,*(s32*)(queue+0x10),fn_80265A94))==0) goto done;
}
*(u32*)(queue+0x2C)=0;
*(u32*)(queue+0x28)=0;
callback=*(void(**)(s32,s32))(queue+0x14);
if(callback) {*(u32*)(queue+0x14)=0; callback(arg0,result);}
done: *(s32*)(entry+0x20)=result;
}
#pragma scheduling on
void fn_80265A94(s32 arg0, s32 arg1)
{
    extern u8 lbl_803669A0[];
    extern u8 lbl_802A4DE8[];
    extern int fn_80265544(s32, void *, void *);
    extern void fn_80265B64(s32, s32);
    u8 *entry;
    u8 *queue;
    s32 result=arg1;
    void (*callback)(s32, s32);
    u8 dummy[8];

    entry = lbl_803669A0 + (arg0 << 8);
    queue = entry + 0x40;
    if (result == 0) {
        if (*(u8 *)*(u32 *)(queue + 0x10) != lbl_802A4DE8[0x25]) result = 3;
    }
    if (result == 0) {
        if ((result = fn_80265544(arg0, *(void **)(queue + 0x10), fn_80265B64)) == 0) goto done;
    }
    *(u32 *)(queue + 0x2C) = 0;
    *(u32 *)(queue + 0x28) = 0;
    callback = *(void (**)(s32, s32))(queue + 0x14);
    if (callback) {
        *(u32 *)(queue + 0x14) = 0;
        callback(arg0, result);
    }
done:
    *(u32 *)(entry + 0x20) = result;
}

#pragma optimization_level 3
#pragma peephole on
void fn_80265B64(s32 arg0, s32 arg1)
{
    extern u8 lbl_803669A0[];
    extern u8 lbl_802A4DE8[];
    extern s32 fn_802667D4(s32, void *, void *, void *);
    extern void fn_80265C34(s32, s32);

    u8 *entry;
    u8 *queue;
    s32 result;
    void (*callback)(s32, s32);

    result = arg1;
    entry = lbl_803669A0 + (arg0 << 8);
    queue = entry + 0x40;

    if (result == 0) {
        if (*(u8 *)*(u32 *)(queue + 0x10) != lbl_802A4DE8[0]) {
            result = 3;
        }
        if (result != 0) goto error;
        if ((result = fn_802667D4(arg0, queue + 0x18, *(void **)(queue + 0x10), fn_80265C34)) == 0) goto done;
    }
error:
    *(u32 *)(queue + 0x2C) = 0;
    *(u32 *)(queue + 0x28) = 0;
    callback = *(void (**)(s32, s32))(queue + 0x14);
    if (callback != 0) {
        *(u32 *)(queue + 0x14) = 0;
        callback(arg0, result);
    }
done:
    *(u32 *)(entry + 0x20) = result;
}
#pragma push
#pragma global_optimizer off
#pragma scheduling on
#pragma peephole on
#pragma push
#pragma optimization_level 4
#pragma global_optimizer off
#pragma scheduling on
#pragma peephole on
void fn_80265C34(s32 arg0, s32 arg1)
{
  extern u8 lbl_803669A0[];
  void fn_80266F18(s32, void *);
  u8 *entry;
  u8 *queue;
  void (*callback)(s32, s32);
  unsigned int pad;
  entry = lbl_803669A0 + (arg0 << 8);
  queue = entry + 0x40;
  if (arg1 == 0)
  {
    fn_80266F18(arg0, queue + 0x18);
  }
  else
  {
    *((u32 *) (queue + 0x2C)) = 0;
    *((u32 *) (queue + 0x28)) = 0;
    callback = *((void (**)(s32, s32)) (queue + 0x14));
    if (callback)
    {
      *((u32 *) (queue + 0x14)) = 0;
      callback(arg0, arg1);
    }
  }
  *((u32 *) (entry + 0x20)) = arg1;
}
#pragma pop
void fn_80265CB4(s32 arg0, s32 arg1)
{
    extern u8 lbl_803669A0[];
    extern u8 lbl_802A4DE8[];
    extern u64 OSGetTime(void);
    extern int fn_80266904(s32, void *, void *, void *);
    extern void fn_80265E90(s32, s32);

    u8 *entry;
    u8 *queue;
    u8 *config;
    u32 value;
    u32 threshold;
    s32 result;
    void (*callback)(s32, s32);

    entry = lbl_803669A0 + (arg0 << 8);
    queue = entry + 0x40;
    config = lbl_802A4DE8;
    result = arg1;

    if (arg1 == 0) {
        value = *(u32 *)((u8 *)*(u32 *)(entry + 0xF8) + 0x20);
        *(u32 *)(queue + 0x58) = value;

        value = *(u32 *)((u8 *)*(u32 *)(entry + 0xF8) + 0x24);
        *(u32 *)(queue + 0x5C) = value;

        if (queue[0x1B] != 0 &&
            queue[0x1A] != 0 &&
            (value = *(u32 *)(queue + 0x58),
             (value & ((u32)config[0x05] << 9)) != 0) &&
            queue[0x19] != 0 &&
            (value >> 15) != 0 &&
            queue[0x18] != 0) {
            result = 3;
            goto done;
        }

        value = (*(u32 *)(queue + 0x0C) + config[0x24])
              & ~(u32)config[0x24];

        *(u32 *)(queue + 0x20) = value;

        threshold = (u32)config[0x14] << config[0x21];

        if (value < threshold) {
            *(u32 *)(queue + 0x20) = threshold;
            *(u32 *)(queue + 0x64) = threshold;
            value = threshold - threshold;
            *(u32 *)(queue + 0x20) = value;
            *(u32 *)(queue + 0x20) =
                (u32)((s32)value >> config[0x20]);
        }

        value = *(u32 *)(queue + 0x5C);

        queue[0x1C] = (u8)value;
        queue[0x1D] = (u8)((s32)value >> 8);
        queue[0x1E] = (u8)((s32)value >> 16);
        queue[0x1F] = (u8)((s32)value >> 24);

        *(u32 *)(queue + 0x38) =
            ((u32)config[0x26] + 1) << config[0x22];

        *(u32 *)(queue + 0x34) = config[0x08];

        *(u64 *)(queue + 0x28) = OSGetTime();

        *(u32 *)(queue + 0x30) = 1;

        result = fn_80266904(
            arg0,
            queue + 0x1C,
            *(void **)(queue + 0x10),
            fn_80265E90
        );
    }

done:
    if (result != 0) {
        *(u32 *)(queue + 0x2C) = 0;
        *(u32 *)(queue + 0x28) = 0;

        callback = *(void (**)(s32, s32))(queue + 0x14);

        if (callback != 0) {
            *(u32 *)(queue + 0x14) = 0;
            callback(arg0, result);
        }
    }

    *(u32 *)(entry + 0x20) = result;
}

/* write fn_80265E90 here */void fn_80265E90(s32 arg0, s32 arg1)
{
    extern u8 lbl_803669A0[];
    extern u8 lbl_802A4DE8[];
    extern u32 OSGetTick(void);
    extern void fn_80266328(s32 channel, s32 arg1);
    extern int fn_80266904(s32, void *, void *, void *);
    extern int fn_802667D4(s32, void *, void *, void *);

    u8 *entry;
    u8 *queue;
    u8 *config;
    u32 value;
    u32 accumulator;
    u32 crc;
    u32 polynomial;
    u32 mask;
    u32 state;
    u32 position;
    u32 count;
    u32 shift;
    u32 temp;
    u32 callbackValue;
    s32 result;
    s32 status;
    void (*callback)(s32, s32);

    entry = lbl_803669A0 + (arg0 << 8);
    queue = entry + 0x40;
    config = lbl_802A4DE8;
    result = arg1;

    if (arg1 != 0) {
        goto done;
    }

    if (*(u32 *)(queue + 0x30) != 0) {
        *(u32 *)(queue + 0x30) = 0;
    } else {
        status = *(u8 *)(*(u8 **)(queue + 0x10));

        if ((status & config[0x14]) != 0) {
            if (((status & config[0x2A]) >> config[0x21]) !=
                ((*(u32 *)(queue + 0x34) & config[0x21]) >> config[0x1F])) {
                result = 3;
                goto done;
            }

            *(u32 *)(queue + 0x34) =
                *(u32 *)(queue + 0x34) + config[0x17] - config[0x19];
        }
    }

    position = *(u32 *)(queue + 0x34);
    count = *(u32 *)(queue + 0x64);

    if ((s32)position > (s32)count) {
        goto retry;
    }

    accumulator = 0;

    if (position < count) {
        state = config[0x1D];
        *(u32 *)(queue + 0x20) = state;

        while (state < config[0x21]) {
            if (*(u32 *)(queue + 0x0C) != 0) {
                u8 *input;

                input = (u8 *)(*(u32 *)(queue + 0x08));
                *(u32 *)(queue + 0x08) += 1;

                shift = state * config[0x25];
                value = *input;

                *(u32 *)(queue + 0x0C) -= 1;
                accumulator |= value << shift;
            }

            state++;
            *(u32 *)(queue + 0x20) = state;
        }

        if (position == config[0x26]) {
            *(u32 *)(queue + 0x60) = accumulator;
        } else if (position == config[0x27]) {
            accumulator = arg0 << config[0x25];
        }

        if (position >= config[0x02]) {
            polynomial =
                (config[0x26] << 8) +
                config[0x28] +
                config[0x2B] -
                (config[0x2B] << 4) -
                config[0x23];

            crc = *(u32 *)(queue + 0x38);
            value = accumulator;
            count = config[0x14];

            while (count > config[0x1E]) {
                if (((value ^ crc) & 1) != 0) {
                    crc = (crc >> 1) ^ polynomial;
                } else {
                    crc >>= 1;
                }

                value >>= 1;
                count--;
            }

            *(u32 *)(queue + 0x38) = crc;

            if (position == config[0x28] + 0x100) {
                *(u32 *)(queue + 0x3C) = accumulator;
            } else if (position == config[0x01] + 0x100) {
                state = config[0x07];
                *(u32 *)(queue + 0x20) = state;
                *(u32 *)(queue + 0x3C + (state * 4)) = accumulator;
            }
        }
    }

    position = *(u32 *)(queue + 0x34);
    accumulator = *(u32 *)(queue + 0x38) | (position << 16);

    if (position > config[0x2B]) {
        mask = config[0x15] |
               (config[0x18] << config[0x25]) |
               (config[0x18] << config[0x2C]) |
               (config[0x17] << config[0x2A]);

        value = *(u32 *)(queue + 0x58) * mask;
        value -= config[0x1B] - config[0x1A];
        *(u32 *)(queue + 0x58) = value;

        temp = position + (config[0x0B] << 20);

        accumulator ^= value;
        accumulator ^= (u32)(-temp);

        value = (config[0x0B] << 24) |
                (config[0x13] << 16) |
                (config[0x12] << 8) |
                config[0x0B];

        accumulator ^= value;

        *(u8 *)(queue + 0x1F) = accumulator >> config[0x00];
        *(u8 *)(queue + 0x1C) = accumulator >> config[0x1E];
        *(u8 *)(queue + 0x1D) = accumulator >> config[0x29];
        *(u8 *)(queue + 0x1E) = accumulator >> config[0x2A];
    }

    if (position == config[0x01] + config[0x01]) {
        *(u32 *)(queue + 0x44) = accumulator;
    }

    state = *(u32 *)(queue + 0x20);

    if (state < config[0x21]) {
        *(u32 *)(queue + 0x3C + ((state + 2) * 4)) = accumulator;

        value = *(u32 *)(queue + 0x3C + ((state + 1) * 4));
        temp = *(u32 *)(queue + 0x3C + ((4 - state) * 4));
        *(u32 *)(queue + 0x3C + ((5 - state) * 4)) = value * temp;

        value = *(u32 *)(queue + 0x3C + ((state - 1) * 4));
        temp = *(u32 *)(queue + 0x3C + ((4 - state) * 4));
        *(u32 *)(queue + 0x3C + ((7 - state) * 4)) = value * temp;
    }

    result = fn_80266904(
        arg0,
        queue + 0x1C,
        *(void **)(queue + 0x10),
        fn_80265E90
    );

    goto done;

retry:
    *(u32 *)(queue + 0x24) = OSGetTick();

    result = fn_802667D4(
        arg0,
        queue + 0x18,
        *(void **)(queue + 0x10),
        fn_80266328
    );

done:
    if (result != 0) {
        *(u32 *)(queue + 0x2C) = 0;
        *(u32 *)(queue + 0x28) = 0;

        callback = *(void (**)(s32, s32))(queue + 0x14);

        if (callback != 0) {
            *(u32 *)(queue + 0x14) = 0;
            callback(arg0, result);
        }
    }

    *(u32 *)(entry + 0x20) = result;
}

void fn_80266328(s32 arg0, s32 arg1)
{
    extern u8 lbl_803669A0[];
    extern u8 lbl_802A4DE8[];
    extern u32 OSGetTick(void);
    extern s32 fn_80265544(s32 channel, void *input, void *callback);
    extern void fn_8026649C(s32 channel, s32 arg1);

    u8 *entry;
    u8 *queue;
    u8 *table;
    u32 value;
    u32 checksum;
    s32 result;
    s32 count;
    void (*callback)(s32, s32);

    entry = lbl_803669A0 + (arg0 << 8);
    queue = entry + 0x40;

    if (arg1 != 0) {
        return;
    }

    *(u32 *)(queue + 0x20) = 0x21;
    table = lbl_802A4DE8;

    value = *(u32 *)(queue + 0x60);
    checksum = ((u32)queue[0x18] ^ (value >> 24))
             | ((u32)queue[0x19] ^ (value >> 16))
             | ((u32)queue[0x1A] ^ (value >> 8))
             | ((u32)queue[0x1B] ^ value);

    if ((checksum << 24) != 0) {
        count = *(s32 *)(queue + 0x20) + 1;
        *(s32 *)(queue + 0x20) = count;

        if (count < 0x24) {
            return;
        }

        result = 3;
    } else {
        *(u32 *)(queue + 0x24) = OSGetTick();

        result = fn_80265544(
            arg0,
            *(void **)(queue + 0x10),
            fn_8026649C
        );
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

#include "common.h"
extern f32 lbl_8036C3F0;
extern u8 lbl_802A4590[];
#include "global.h"
#include "ef.h"

extern s32 gSoundVoices;
extern u16 gSoundLevelCurve[];
extern s32 gSoundVoices;
extern u8 lbl_80368AD0;
#include "global.h"

extern s32 lbl_80368AF8;
extern u16 gSampleKeyCount;
extern u16 lbl_80368AFC;
extern u16 gSampleKeys[];
extern u16 lbl_803596F0[16];
extern u32* lbl_80368950;
extern u8* lbl_803688E4;
extern u16* lbl_803688EC;
#include "common.h"

typedef struct {
    s32 field_0x0;
    s32 field_0x4;
    s32 field_0x8;
    s16 field_0xC;
    s16 field_0xE;
    s32 field_0x10;
    s32 field_0x14;
    s32 field_0x18;
    s32 field_0x1C;
} Struct_80246288;

extern u16 lbl_80366F28;
extern char lbl_80282AE8[];
extern s32 lbl_80368960;
extern s32 lbl_80368964;
