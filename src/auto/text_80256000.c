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

#pragma scheduling on

#pragma scheduling reset

/* Synth seq cmd: set or add voice volume (0..0x7F), store fine byte, apply if active. */

#pragma dont_inline on

#pragma dont_inline reset

#pragma global_optimizer off

#pragma global_optimizer reset

/* Build ADSR envelope from packed channel params and apply it to the synth voice. */

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma optimization_level 4
#pragma global_optimizer on
#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
#pragma global_optimizer reset
#pragma optimization_level reset

#pragma global_optimizer on

#pragma optimization_level 3
#pragma global_optimizer off
#pragma use_lmw_stmw off

#pragma global_optimizer reset
#pragma use_lmw_stmw reset
#pragma optimization_level reset
#pragma optimization_level 3
#pragma global_optimizer off
#pragma use_lmw_stmw off

#pragma use_lmw_stmw reset
#pragma global_optimizer reset
#pragma optimization_level reset

#pragma opt_common_subs off

#pragma opt_common_subs reset
extern void (*lbl_803689AC)(u32,u32);
#pragma opt_strength_reduction off

#pragma opt_strength_reduction on

void Sound_DeactivateSynthVoice(void *arg0);

/* Set synth voice run-state; unlink from idle when leaving 0, clear schedule when entering 2. */

#pragma opt_peephole off

#pragma opt_peephole reset

int fn_80256000(u32 arg0)
{
    extern VidList *vidListRoot;
    extern s32 gSynthVoices;
    VidList *vl;
    u32 index;

    vl = vidListRoot;
    while (vl != NULL) {
        index = vl->root;
        while ((u32)(index + 0x10000) != 0xFFFFU) {
            if (index == arg0) {
                return vl->vid;
            }
            index = *(u32 *)((u8 *)gSynthVoices + ((u8)index * 0x458) + 0xEC);
        }
        vl = vl->next;
    }
    return -1;
}

#pragma global_optimizer off
void fn_80256054(void *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, u16 arg5) {
 extern u8 lbl_80359710[]; extern u16 lbl_80368A4C;
 void fn_8026171C(s32,s32);
 u16 previous, current;
 u8 *base, *node, *old, *n2, *heads, *back, *tbl;
 u32 id; u32 off; u8 next; u8 prev; u16 p; u16 n; u8 priority;
 previous=arg5;
 base=lbl_80359710;
 id=(u8)*(u32*)((u8*)arg0+0xF4);
 off=(u8)id*4;
 node=base+0x800; node+=off;
 if(*(u16*)(node+2)==1) {
  if(((u8*)arg0)[0x10C]==arg1) return;
  old=base+0x800; old+=off;
  if(*(u16*)(old+2)==1) {
   prev=old[0];
   if(prev!=0xFF) {
    tbl=base+0x800; tbl+=(u8)prev*4; tbl[1]=old[1];
   } else { tbl=base+0x900; tbl[((u8*)arg0)[0x10C]]=old[1]; }
   next=old[1];
   if(next!=0xFF) {
    tbl=base+0x800; tbl[(u8)next*4]=old[0];
   } else if(old[0]==0xFF) {
    n2=base+0xA00; n2+=((u8*)arg0)[0x10C]*4;
    p=*(u16*)(n2+2);
    if(p!=0xFFFF) { tbl=base+0xA00; *(u16*)(tbl+(u16)p*4)=*(u16*)n2; }
    else lbl_80368A4C=*(u16*)n2;
    n=*(u16*)n2;
    if(n!=0xFFFF) {
     tbl=base+0xA00; tbl+=(u16)n*4;
     *(u16*)(tbl+2)=*(u16*)(n2+2);
    }
   }
   *(u16*)(old+2)=0;
  }
 }
 *(u16*)(node+2)=1;
 priority=arg1;
 heads=base+0x900;
 next=heads[priority];
 node[0]=0xFF; node[1]=next;
 if(next!=0xFF) { tbl=base+0x800; tbl[next*4]=(u8)id; }
 else if(lbl_80368A4C!=0xFFFF) {
  if((s32)priority>=(s32)lbl_80368A4C) {
   current=lbl_80368A4C;
   tbl=base+0xA00;
   while(current!=0xFFFF) {
    if((s32)current>(s32)priority) break;
    previous=current;
    current=*(u16*)(tbl+(u16)current*4);
   }
   tbl=base+0xA00; back=tbl+2;
   *(u16*)(tbl+(u16)previous*4)=arg1;
   *(u16*)(back+priority*4)=previous;
   *(u16*)(tbl+priority*4)=current;
   if(current!=0xFFFF) *(u16*)(back+(u16)current*4)=arg1;
  } else {
   tbl=base+0xA00;
   *(u16*)(tbl+priority*4)=lbl_80368A4C;
   *(u16*)(back+priority*4)=0xFFFF;
   *(u16*)(back+(u16)lbl_80368A4C*4)=priority;
   lbl_80368A4C=priority;
  }
 } else {
  tbl=base+0xA00;
  lbl_80368A4C=priority;
  *(u16*)(tbl+priority*4)=0xFFFF;
  *(u16*)(tbl+priority*4+2)=0xFFFF;
 }
 heads[priority]=(u8)id;
 ((u8*)arg0)[0x10C]=arg1;
 off=*(u32*)((u8*)arg0+0x110)>>15;
 off=(off & ~0xFF000000) | (priority<<24);
 fn_8026171C((u8)*(u32*)((u8*)arg0+0xF4),off);
}

s32 fn_802562A0(u8 arg0, u8 arg1, s32 arg2, u8 arg3)
{
    extern u8 lbl_80359710[];
    extern u16 lbl_80368A4C;
    extern u8 lbl_80368A4E;
    extern u8 lbl_80368A4F;
    extern u8 lbl_80368A51;

    u8 *base;
    u8 *voices;
    u8 *voice;
    u8 *node;
    u8 *group;
    u8 *nextTable;
    u8 *priorityTable;
    u32 limit;
    u32 count;
    u32 index;
    u32 next;
    u32 groupIndex;
    u32 priority;
    s32 candidate;
    s32 restricted;
    s32 offset;

    base = lbl_80359710;

    if (lbl_803689B0 != 0) {
        return -1;
    }

    restricted = 0;

    if (arg3 != 0) {
        limit = gSoundData[0x212];

        if (lbl_80368A4F >= limit &&
            gSoundData[0x210] > limit) {
            restricted = 1;
        }
    } else {
        limit = gSoundData[0x211];

        if (lbl_80368A4E >= limit &&
            gSoundData[0x210] > limit) {
            restricted = 1;
        }
    }

    voices = (u8 *)gSynthVoices;

    if (arg1 < limit) {
        group = base + 0x900;
        nextTable = base + 0x800;
        priorityTable = base + 0xA00;

        groupIndex = lbl_80368A4C;
        count = 0;
        candidate = -1;

        while (groupIndex != 0xFFFF) {
            index = group[groupIndex];

            while (index != 0xFF) {
                voice = voices + index * 0x458;

                if (*(u32 *)(voice + 0x100) == (u32)arg2) {
                    count++;

                    if (*(u8 *)(voice + 0x11C) == 0) {
                        if (restricted == 0 ||
                            (*(u8 *)(voice + 0x11D) == arg3 &&
                             (*(u32 *)(voice + 0x118) & 2) == 0)) {

                            if (candidate == -1) {
                                candidate = index;
                            } else {
                                u8 *selected;

                                selected = voices + candidate * 0x458;

                                if (*(u32 *)(voice + 0x110) <
                                    *(u32 *)(selected + 0x110)) {
                                    candidate = index;
                                }
                            }
                        }
                    }
                }

                node = nextTable + index * 4;
                next = node[1];

                if (next == 0xFF) {
                    break;
                }

                index = next;
            }

            next = *(u16 *)(priorityTable + groupIndex * 4);

            if (next == 0xFFFF || arg0 < next) {
                break;
            }

            groupIndex = next;
        }

        if (candidate != -1 && count >= arg1) {
            return candidate;
        }
    }

    if (lbl_80368A51 != 0xFF && restricted == 0) {
        return lbl_80368A51;
    }

    if (arg0 < lbl_80368A4C) {
        return -1;
    }

    group = base + 0x900;
    nextTable = base + 0x800;
    priorityTable = base + 0xA00;

    groupIndex = lbl_80368A4C;
    candidate = -1;

    while (groupIndex != 0xFFFF) {
        index = group[groupIndex];

        while (index != 0xFF) {
            voice = voices + index * 0x458;

            if (*(u8 *)(voice + 0x11C) == 0) {
                if (restricted == 0 ||
                    (*(u8 *)(voice + 0x11D) == arg3 &&
                     (*(u32 *)(voice + 0x118) & 2) == 0)) {

                    if (candidate == -1) {
                        candidate = index;
                    } else {
                        u8 *selected;

                        selected = voices + candidate * 0x458;

                        if (*(u32 *)(voice + 0x110) >=
                            *(u32 *)(selected + 0x110)) {
                            candidate = index;
                        }
                    }
                }
            }

            node = nextTable + index * 4;
            next = node[1];

            if (next == 0xFF) {
                break;
            }

            index = next;
        }

        next = *(u16 *)(priorityTable + groupIndex * 4);

        if (next == 0xFFFF || arg0 < next) {
            break;
        }

        groupIndex = next;
    }

    if (candidate == -1) {
        return -1;
    }

    offset = candidate * 0x458;
    priority = *(u8 *)(voices + offset + 0x10C);

    if (priority > arg0) {
        return -1;
    }

    return candidate;
}

s32 fn_80256628(u8 a,u8 b,s32 c,u8 d) {
extern u8 lbl_80368A4E,lbl_80368A4F,lbl_80368A50,lbl_80368A51;
struct VoiceFlag { u8 pad[0x11D]; u8 flag; u8 tail[0x33A]; };
s32 index;
u8 *node;
index=fn_802562A0(a,b,c,d);
if(index != -1) {
node=(u8 *)lbl_8035A510+index*4;
if(*(u16 *)(node+2)==1) {
if((s32)node[0]!=255) ((u8 *)lbl_8035A510+node[0]*4)[1]=node[1];
else lbl_80368A51=node[1];
if((s32)node[1]!=255) ((u8 *)lbl_8035A510)[node[1]*4]=node[0];
if(index==lbl_80368A50) lbl_80368A50=node[0];
*(u16 *)(node+2)=0;
} else if(((struct VoiceFlag *)gSynthVoices)[index].flag) --lbl_80368A4F;
else --lbl_80368A4E;
if(d) ++lbl_80368A4F; else ++lbl_80368A4E;
}
return index;
}

#pragma global_optimizer on
s32 fn_80256738(u8 arg0, u8 arg1, s32 arg2, u8 arg3, s32 *out) {
s32 fn_802562A0(u8,u8,s32,u8);
s32 idx; u8 *table; u16 *flag;
idx=fn_802562A0(arg0,arg1,arg2,arg3);
if(idx == -1) return 0;
flag=lbl_8035A510;
flag += idx * 2;
if(flag[1] == 1) return 0;
table=(u8 *)gSynthVoices;
table += idx * 0x458;
*out=*(s32 *)(table+0x100);
return 1;
}

#pragma global_optimizer off
#pragma dont_inline on
void fn_802567B0(void *arg0) {
 extern u8 lbl_80359710[3584];
 extern u16 lbl_80368A4C;
 extern u8 lbl_80368A4E, lbl_80368A4F, lbl_80368A50, lbl_80368A51;
 u8 *base=lbl_80359710;
 u8 *node,*tbl,*n2;
 u8 prev,next,id;
 u16 p,n;
 Sound_SetSynthVoiceState(arg0,2);
 node=base+0x800; node+=(u8)*(u32*)((u8*)arg0+0xF4)*4;
 if(*(u16*)(node+2)==1) {
 prev=node[0];
 if(prev!=255) { tbl=base+0x800; tbl+=(u8)prev*4; tbl[1]=node[1]; }
 else {tbl=base+0x900;tbl[((u8*)arg0)[0x10C]]=node[1];}
 next=node[1];
 if(next!=255) {tbl=base+0x800;tbl[(u8)next*4]=node[0];}
 else if(node[0]==255) {
 n2=base+0xA00;n2+=((u8*)arg0)[0x10C]*4;
 p=*(u16*)(n2+2);
 if(p!=65535){tbl=base+0xA00;*(u16*)(tbl+(u16)p*4)=*(u16*)n2;}
 else lbl_80368A4C=*(u16*)n2;
 n=*(u16*)n2;
 if(n!=65535){tbl=base+0xA00;tbl+=(u16)n*4;*(u16*)(tbl+2)=*(u16*)(n2+2);}
 }
 *(u16*)(node+2)=0;
 }
 *(u32*)((u8*)arg0+0x34)=0;
 ((u8*)arg0)[0x10C]=0;
 id=*(u32*)((u8*)arg0+0xF4);
 n2=base+0xE00;n2+=id*4;
 if(*(u16*)(n2+2)==0) {
 *(u16*)(n2+2)=1;
 if(lbl_80368A51!=255) {
 n2[1]=255;n2[0]=lbl_80368A50;
 tbl=base+0xE00;tbl+=lbl_80368A50*4;tbl[1]=id;
 }else{lbl_80368A51=id;n2[1]=255;n2[0]=255;}
 lbl_80368A50=id;
 if(((u8*)arg0)[0x11D]) lbl_80368A4F--;else lbl_80368A4E--;
 }
 *(u32*)((u8*)arg0+0xF4)=-1;
}
#pragma dont_inline reset
#pragma global_optimizer reset
void fn_80256974(void) {
extern u8 lbl_80359710[3584];
extern u16 lbl_80368A4C;
extern u8 lbl_80368A4E,lbl_80368A4F,lbl_80368A50,lbl_80368A51;
u32 i;
u32 n=gSoundData[0x210];
for(i=0;i<n;i++){
lbl_80359710[0xE00+i*4]=i-1;
lbl_80359710[0xE01+i*4]=i+1;
*(u16*)(lbl_80359710+0xE02+i*4)=1;
}
lbl_80359710[0xE00]=255;
lbl_80368A51=0;
lbl_80359710[0xE00+gSoundData[0x210]*4-3]=255;
lbl_80368A50=gSoundData[0x210]-1;
for(i=0;i<n;i++) *(u16*)(lbl_80359710+0x802+i*4)=0;
for(i=0;i<256;i++) lbl_80359710[0x900+i]=255;
lbl_80368A4F=0;lbl_80368A4C=65535;lbl_80368A4E=0;
}

s32 fn_80256C14(u8 arg0)
{
    extern u16 lbl_8035A510[];
    extern s32 gSynthVoices;
    extern u8 lbl_80368A50;
    extern u8 lbl_80368A51;
    extern u8 lbl_80368A4E;
    extern u8 lbl_80368A4F;

    s32 fn_802562A0(u8, u8, s32, u8);
    void fn_80255B20(void *);
    s32 Sound_IsHwVoiceActive(s32);
    void fn_802618E4(int);
    void Sound_SetSynthVoiceState(void *, s32);
    void fn_80256054(void *, u8);

    s32 index;
    s32 offset;
    u8 *voice;
    u8 *node;
    u8 *table;
    u8 previous;
    u8 next;

    index = fn_802562A0(arg0, 0xFF, 0xFFFF, 1);

    if (index == -1) {
        return -1;
    }

    table = (u8 *)lbl_8035A510;
    node = table + (index << 2);

    if (*(u16 *)(node + 2) == 1) {
        previous = node[0];

        if (previous != 0xFF) {
            table[(previous << 2) + 1] = node[1];
        } else {
            lbl_80368A51 = node[1];
        }

        next = node[1];

        if (next != 0xFF) {
            table[next << 2] = node[0];
        }

        if (index == lbl_80368A50) {
            lbl_80368A50 = node[0];
        }

        *(u16 *)(node + 2) = 0;
    } else {
        offset = index * 0x458;
        voice = (u8 *)gSynthVoices + offset;

        if (*(u8 *)(voice + 0x11D) != 0) {
            lbl_80368A4F--;
        } else {
            lbl_80368A4E--;
        }
    }

    lbl_80368A4F++;

    offset = index * 0x458;

    voice = (u8 *)gSynthVoices + offset;
    *(u8 *)(voice + 0x11C) = 1;

    voice = (u8 *)gSynthVoices + offset;
    *(u8 *)(voice + 0x11D) = 1;

    voice = (u8 *)gSynthVoices + offset;
    *(s32 *)(voice + 0x100) = -1;

    voice = (u8 *)gSynthVoices + offset;
    fn_80255B20(voice);

    voice = (u8 *)gSynthVoices + offset;
    *(u32 *)(voice + 0xF4) =
        (u32)index | 0xFFFFFF00;

    if (Sound_IsHwVoiceActive(index) != 0) {
        fn_802618E4(index);

        voice = (u8 *)gSynthVoices + offset;
        Sound_SetSynthVoiceState(voice, 2);
    }

    voice = (u8 *)gSynthVoices + offset;
    *(u32 *)(voice + 0x34) = 0;

    voice = (u8 *)gSynthVoices + offset;
    fn_80256054(voice, arg0);

    return index;
}

void fn_80256DD8(int arg0) {
    u32 Sound_IsHwVoiceActive(void);
    void fn_802618E4(s32);
    void Sound_SetSynthVoiceState(void *, s32);
    extern u8 lbl_80359710[];
    extern s32 gSynthVoices;
    extern u16 lbl_80368A4C;
    extern u8 lbl_80368A4E;
    extern u8 lbl_80368A4F;
    extern u8 lbl_80368A50;
    extern u8 lbl_80368A51;

    u8 *base;
    u8 *voice;
    u8 *node;
    u8 *n2;
    u8 *tbl;
    s32 off;
    u16 p2;
    u16 n2v;
    s32 id;
    u8 *freeNode;
    u8 id8;

    base = lbl_80359710;
    if ((u32)(arg0 + 0x10000) != 0xFFFFU) {
        if (Sound_IsHwVoiceActive() != 0) {
            fn_802618E4(arg0);
        }
        off = arg0 * 0x458;
        voice = (u8 *)gSynthVoices + off;
        *(s32 *)(voice + 0xF4) = arg0;
        voice = (u8 *)gSynthVoices + off;
        Sound_SetSynthVoiceState(voice, 2);

        id = *(s32 *)(voice + 0xF4);
        node = base + 0x800;
        node += ((u8)id << 2);
        if (*(u16 *)(node + 2) == 1) {
            if (node[0] != 0xFF) {
                tbl = base + 0x800;
                tbl += (node[0] << 2);
                tbl[1] = node[1];
            } else {
                tbl = base + 0x900;
                tbl += voice[0x10C];
                *tbl = node[1];
            }
            if (node[1] != 0xFF) {
                tbl = base + 0x800;
                tbl += (node[1] << 2);
                *tbl = node[0];
            } else if (node[0] == 0xFF) {
                n2 = base + 0xA00;
                n2 += (voice[0x10C] << 2);
                if (*(u16 *)(n2 + 2) != 0xFFFF) {
                    p2 = *(u16 *)(n2 + 2);
                    tbl = base + 0xA00;
                    tbl += p2 << 2;
                    *(u16 *)tbl = *(u16 *)n2;
                } else {
                    lbl_80368A4C = *(u16 *)n2;
                }
                if (*(u16 *)n2 != 0xFFFF) {
                    n2v = *(u16 *)n2;
                    tbl = base + 0xA00;
                    tbl += n2v << 2;
                    *(u16 *)(tbl + 2) = *(u16 *)(n2 + 2);
                }
            }
            *(u16 *)(node + 2) = 0;
        }

        *(s32 *)(voice + 0x34) = 0;
        voice[0x10C] = 0;
        id = *(s32 *)(voice + 0xF4);
        id8 = (u8)id;
        freeNode = base + 0xE00;
        freeNode += (id8 << 2);
        if (*(u16 *)(freeNode + 2) == 0) {
            *(u16 *)(freeNode + 2) = 1;
            if (lbl_80368A51 != 0xFF) {
                freeNode[1] = 0xFF;
                freeNode[0] = lbl_80368A50;
                tbl = base + 0xE00;
                tbl += (lbl_80368A50 << 2);
                tbl[1] = id8;
            } else {
                lbl_80368A51 = id8;
                freeNode[1] = 0xFF;
                freeNode[0] = 0xFF;
            }
            lbl_80368A50 = id8;
            if (voice[0x11D] != 0) {
                lbl_80368A4F -= 1;
            } else {
                lbl_80368A4E -= 1;
            }
        }
        *(s32 *)(voice + 0xF4) = -1;
        ((u8 *)gSynthVoices + off)[0x11C] = 0;
    }
}

void fn_80256FF0(Fn80256FF0Arg arg0) {
    void fn_80255B20(void *);
    void Sound_SetSynthVoiceState(void *, s32);
    void fn_8024C5CC(s32);
    void fn_802618E4(s32);
    extern u8 lbl_80359710[];
    extern s32 gSynthVoices;
    extern u16 lbl_80368A4C;
    extern u8 lbl_80368A4E;
    extern u8 lbl_80368A4F;
    extern u8 lbl_80368A50;
    extern u8 lbl_80368A51;

    u8 *base;
    u8 *voice;
    u8 *node;
    u8 *n2;
    u8 *tbl;
    u8 prev;
    u8 next;
    u16 p2;
    u16 n2v;
    s32 id;
    u8 *freeNode;
    u8 id8;
    s32 t118;
    s32 t114;

    base = lbl_80359710;
    voice = (u8 *)gSynthVoices + arg0 * 0x458;
    if (*(u32 *)(voice + 0x34) != 0) {
        fn_80255B20(voice);
        t118 = *(s32 *)(voice + 0x118);
        t114 = *(s32 *)(voice + 0x114);
        t118 = t118 & -4;
        t114 = t114 & -1;
        *(s32 *)(voice + 0x118) = t118;
        *(s32 *)(voice + 0x114) = t114;
        *(s32 *)(voice + 0x110) = 0;
        Sound_SetSynthVoiceState(voice, 2);

        id = *(s32 *)(voice + 0xF4);
        node = base + 0x800;
        node += ((u8)id << 2);
        if (*(u16 *)(node + 2) == 1) {
            if (node[0] != 0xFF) {
                prev = node[0];
                tbl = base + 0x800;
                tbl += (prev << 2);
                tbl[1] = node[1];
            } else {
                next = node[1];
                tbl = base + 0x900;
                tbl += voice[0x10C];
                *tbl = next;
            }
            if (node[1] != 0xFF) {
                next = node[1];
                prev = node[0];
                tbl = base + 0x800;
                tbl += next << 2;
                *tbl = prev;
            } else if (node[0] == 0xFF) {
                n2 = base + 0xA00;
                n2 += (voice[0x10C] << 2);
                if (*(u16 *)(n2 + 2) != 0xFFFF) {
                    p2 = *(u16 *)(n2 + 2);
                    tbl = base + 0xA00;
                    tbl += p2 << 2;
                    *(u16 *)tbl = *(u16 *)n2;
                } else {
                    lbl_80368A4C = *(u16 *)n2;
                }
                if (*(u16 *)n2 != 0xFFFF) {
                    n2v = *(u16 *)n2;
                    tbl = base + 0xA00;
                    tbl += n2v << 2;
                    *(u16 *)(tbl + 2) = *(u16 *)(n2 + 2);
                }
            }
            *(u16 *)(node + 2) = 0;
        }

        *(s32 *)(voice + 0x34) = 0;
        voice[0x10C] = 0;
        id = *(s32 *)(voice + 0xF4);
        id8 = (u8)id;
        freeNode = base + 0xE00;
        freeNode += (id8 << 2);
        if (*(u16 *)(freeNode + 2) == 0) {
            *(u16 *)(freeNode + 2) = 1;
            if (lbl_80368A51 != 0xFF) {
                freeNode[1] = 0xFF;
                freeNode[0] = lbl_80368A50;
                tbl = base + 0xE00;
                tbl += (lbl_80368A50 << 2);
                tbl[1] = id8;
            } else {
                lbl_80368A51 = id8;
                freeNode[1] = 0xFF;
                freeNode[0] = 0xFF;
            }
            lbl_80368A50 = id8;
            if (voice[0x11D] != 0) {
                lbl_80368A4F -= 1;
            } else {
                lbl_80368A4E -= 1;
            }
        }
        *(s32 *)(voice + 0xF4) = -1;
    }
    if (voice[0x11C] != 0) {
        fn_8024C5CC(arg0);
    }
    fn_802618E4(arg0);
}

#pragma optimization_level 3
s32 fn_80257224(u32 arg0) {
    extern u8 gSoundReady;
    extern s32 gSynthVoices;
    void fn_80256FF0(Fn80256FF0Arg);
    s32 result;
    s32 root;
    u8 *voice;
    s32 next;
    u32 cur;

    result = -1;
    if (gSoundReady != 0) {
        root = Sound_LookupVid(arg0);
        cur = (u32)root;
        while ((u32)(cur + 0x10000) != 0xFFFFU) {
            voice = (u8 *)gSynthVoices + (u8)cur * 0x458;
            next = *(s32 *)(voice + 0xEC);
            if (cur == *(u32 *)(voice + 0xF4)) {
                fn_80256FF0((u8)cur);
                result = 0;
            }
            cur = (u32)next;
        }
    }
    return result;
}
#pragma optimization_level reset
void fn_802572E8(u16 *arg0)
{
    extern u8 gSoundData[];
    extern s32 gSynthVoices;

    void fn_80256FF0(u8);

    u16 *list;
    u32 index;
    u32 offset;
    u32 id;
    u8 *voice;

    list = arg0;
    index = 0;
    offset = 0;

    while (index < gSoundData[0x210]) {
        voice = (u8 *)gSynthVoices + offset;

        if (*(u32 *)(voice + 0x34) == 0) {
            if (voice[0x11C] == 0) {
                fn_80256FF0(index);
            }
        }

        offset += 0x458;
        index++;
    }

    while (*list != 0xFFFF) {
        if (*list & 0x8000) {
            id = *list & 0x3FFF;

            while ((u16)id <= list[1]) {
                index = 0;
                offset = 0;

                while (index < gSoundData[0x210]) {
                    voice = (u8 *)gSynthVoices + offset;

                    if (*(u32 *)(voice + 0x34) != 0) {
                        if (*(u16 *)(voice + 0x104) ==
                            (u16)id) {
                            fn_80256FF0(index);
                        }
                    }

                    offset += 0x458;
                    index++;
                }

                id++;
            }

            list += 2;
        } else {
            index = 0;
            offset = 0;

            while (index < gSoundData[0x210]) {
                voice = (u8 *)gSynthVoices + offset;

                if (*(u32 *)(voice + 0x34) != 0) {
                    if (*(u16 *)(voice + 0x104) == *list) {
                        fn_80256FF0(index);
                    }
                }

                offset += 0x458;
                index++;
            }

            list++;
        }
    }
}

void fn_80257444(u16 *arg0)
{
  extern s32 gSynthVoices;
  extern u8 gSoundData[];
  void fn_80256FF0(s32);
  u16 key;
  u8 *voice;
  u32 index;
  u32 j;
  for (index = 0; index < gSoundData[0x210]; index++)
  {
    voice = ((u8 *) gSynthVoices) + (index * 0x458);
    if (((*((u32 *) (voice + 0x34))) == 0) && ((*((u8 *) (voice + 0x11c))) == 0))
    {
      fn_80256FF0(index);
    }
  }

  while ((*arg0) != 0xFFFF)
  {
    if (((*arg0) & 0x8000) != 0)
    {
      j = (*arg0) & 0x3FFF;
      while (((u16) j) <= arg0[1])
      {
        key = (u16) j;
        for (index = 0; index < gSoundData[0x210]; index++)
        {
          ;
          j = key;
          if (((*((u32 *) ((((u8 *) gSynthVoices) + (index * 0x458)) + 0x34))) != 0) && ((*((u16 *) ((((u8 *) gSynthVoices) + (index * 0x458)) + 0x12c))) == j))
          {
            fn_80256FF0(index);
          }
        }

        j++;
      }

      arg0 = (u16 *) (((u8 *) arg0) + 4);
    }
    else
    {
      for (index = 0; index < gSoundData[0x210]; index++)
      {
        voice = ((u8 *) gSynthVoices) + (index * 0x458);
        if (((*((u32 *) (voice + 0x34))) != 0) && ((*arg0) == (*((u16 *) (voice + 0x12c)))))
        {
          fn_80256FF0(index);
        }
      }

      arg0 = (u16 *) (((u8 *) arg0) + 2);
    }
  }

}

s32 fn_802575A0(void *arg0)
{
    extern u8 lbl_8035A610[];
    extern u8 lbl_8035A650[];

    u8 *voice;
    u32 value;
    u8 index;
    u8 group;
    u8 voiceId;
    u8 *table;

    voice = (u8 *)arg0;
    value = *(u32 *)(voice + 0xF4);

    if ((u32)(value + 0x10000) != 0xFFFF) {
        index = voice[0x121];
        if (index != 0xFF) {
            group = voice[0x122];
            voiceId = (u8)value;
            if (group == 0xFF) {
                if (lbl_8035A610[voiceId] == voiceId) {
                    return 1;
                }
            } else {
                table = lbl_8035A650 + ((u32)group << 4);
                if (table[index] == voiceId) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void fn_80257614(void *arg0)
{
    extern u8 lbl_8035A610[];
    extern u8 lbl_8035A650[];

    u8 *voice;
    u32 value;
    u8 index;
    u8 group;
    u8 voiceId;
    u8 *table;

    voice = (u8 *)arg0;

    value = *(u32 *)(voice + 0xF4);

    if (value == 0xFFFFFFFF) {
        return;
    }

    index = *(u8 *)(voice + 0x121);

    if (index == 0xFF) {
        return;
    }

    group = *(u8 *)(voice + 0x122);
    voiceId = (u8)value;

    if (group == 0xFF) {
        lbl_8035A610[voiceId] = voiceId;
    } else {
        table = lbl_8035A650 + ((u32)group << 4);

        table[index] = voiceId;
    }
}

void fn_80257668(void *arg0)
{
    extern u8 lbl_8035A610[];
    extern u8 lbl_8035A650[];

    u8 *voice;
    u32 value;
    u8 index;
    u8 group;
    u8 voiceId;
    u8 *table;

    voice = (u8 *)arg0;

    value = *(u32 *)(voice + 0xF4);

    if (value == 0xFFFFFFFF) {
        return;
    }

    index = *(u8 *)(voice + 0x121);

    if (index == 0xFF) {
        return;
    }

    group = *(u8 *)(voice + 0x122);
    voiceId = (u8)value;

    if (group == 0xFF) {
        if (lbl_8035A610[voiceId] == voiceId) {
            lbl_8035A610[voiceId] = 0xFF;
        }
    } else {
        table = lbl_8035A650 + ((u32)group << 4);

        if (table[index] == voiceId) {
            table[index] = 0xFF;
        }
    }
}

void fn_802576DC(void) {
    extern u8 lbl_8035A650[];
    extern u8 lbl_8035A610[];
    s32 i;
    u8 *p;
    u8 c;

    c = 0xFF;
    p = lbl_8035A650;
    for (i = 0; i < 4; i++) {
        p[0] = c;
        p[1] = c;
        p[2] = c;
        p[3] = c;
        p[4] = c;
        p[5] = c;
        p[6] = c;
        p[7] = c;
        p[8] = c;
        p[9] = c;
        p[10] = c;
        p[11] = c;
        p[12] = c;
        p[13] = c;
        p[14] = c;
        p[15] = c;
        p += 16;
        p[0] = c;
        p[1] = c;
        p[2] = c;
        p[3] = c;
        p[4] = c;
        p[5] = c;
        p[6] = c;
        p[7] = c;
        p[8] = c;
        p[9] = c;
        p[10] = c;
        p[11] = c;
        p[12] = c;
        p[13] = c;
        p[14] = c;
        p[15] = c;
        p += 16;
    }
    p = lbl_8035A610;
    for (i = 0; i < 2; i++) {
        p[0] = c;
        p[1] = c;
        p[2] = c;
        p[3] = c;
        p[4] = c;
        p[5] = c;
        p[6] = c;
        p[7] = c;
        p[8] = c;
        p[9] = c;
        p[10] = c;
        p[11] = c;
        p[12] = c;
        p[13] = c;
        p[14] = c;
        p[15] = c;
        p[16] = c;
        p[17] = c;
        p[18] = c;
        p[19] = c;
        p[20] = c;
        p[21] = c;
        p[22] = c;
        p[23] = c;
        p[24] = c;
        p[25] = c;
        p[26] = c;
        p[27] = c;
        p[28] = c;
        p[29] = c;
        p[30] = c;
        p[31] = c;
        p += 32;
    }
}

s32 fn_8025785C(u8 arg0, s32 arg1)
{
    extern f32 lbl_8036C278;
    extern f32 lbl_8029F5F8[];
    extern f32 lbl_8029F7F8[];
    f32 scale;
    f32 factor;
    f32 tval;
    f32 frac;
    u32 pitch;
    u32 hi;

    pitch = (u32)arg1;
    if ((u32)(arg1 + 0x10000) == 0xFFFFU) {
        pitch = 0x40005622;
    }
    hi = pitch >> 24;
    factor = lbl_8036C278;
    if (arg0 != hi) {
        frac = (f32)(pitch & 0xFFFFFF);
        if (hi < arg0) {
            tval = lbl_8029F5F8[arg0 - hi];
        } else {
            tval = lbl_8029F7F8[hi - arg0];
        }
        scale = frac * tval;
    } else {
        scale = (f32)(pitch & 0xFFFFFF);
    }
    return __cvt_fp2unsigned((factor * scale) / (f32)(*(u32 *)gSoundData));
}

s32 fn_80257820(u16 arg0) {
    extern f32 lbl_8036C268;
    return (s32) (lbl_8036C268 * (f32) arg0);
}

void fn_80257940(s32 arg0) {
    f64 fn_802387C8(f64, f32, f32);
    extern f64 lbl_8036C280;
    extern f32 lbl_8036C288;
    extern f32 lbl_8036C28C;
    fn_8022C568(lbl_8036C28C * (f32) fn_802387C8(lbl_8036C280, lbl_8036C288 * (f32) arg0, lbl_8036C288));
}

/* Set volume and per-step delta for the voice's current ADSR phase; return 1 when finished. */
s32 Sound_SetupAdsrPhase(u8 *env) {
    extern u16 gAdsrVolCurve[];
    s32 done;
    u32 tmp;
    s32 x;
    s32 y;

    done = 0;
    switch (env[0]) {
    case 0:
        switch (env[1]) {
        case 0:
            tmp = *(u32 *)(env + 0x14);
            *(u32 *)(env + 4) = tmp;
            if (tmp != 0) {
                env[1] = 1;
                *(u32 *)(env + 8) = 0;
                *(u32 *)(env + 0x10) = 0x7FFF0000U / *(u32 *)(env + 0x14);
                break;
            }
        case 1:
            tmp = *(u32 *)(env + 0x18);
            *(u32 *)(env + 4) = tmp;
            if (tmp != 0) {
                env[1] = 2;
                *(u32 *)(env + 8) = 0x7FFF0000;
                *(u32 *)(env + 0x10) =
                    (u32)(-(s32)((0x7FFF0000U - ((u32)*(u16 *)(env + 0x1C) << 16)) /
                                 *(u32 *)(env + 0x18)));
                break;
            }
        case 2:
            if (*(u16 *)(env + 0x1C) != 0) {
                env[1] = 3;
                *(u32 *)(env + 8) = (u32)*(u16 *)(env + 0x1C) << 16;
                *(u32 *)(env + 0x10) = 0;
                break;
            }
        case 4:
            done = 1;
            *(u32 *)(env + 8) = 0;
            break;
        }
        break;
    case 1:
        switch (env[1]) {
        case 0:
            tmp = *(u32 *)(env + 0x14);
            *(u32 *)(env + 4) = tmp;
            if (tmp != 0) {
                env[1] = 1;
                if (env[0x26] == 0) {
                    *(u32 *)(env + 8) = 0;
                    *(u32 *)(env + 0x10) = 0x7FFF0000U / *(u32 *)(env + 4);
                } else {
                    *(u32 *)(env + 0xC) = 0;
                    *(u32 *)(env + 8) = 0;
                    *(u32 *)(env + 0x10) = 0xC10000U / *(u32 *)(env + 4);
                }
                break;
            }
        case 1:
            *(u32 *)(env + 4) =
                (*(u32 *)(env + 0x18) *
                 (((0xC1U - *(u16 *)(env + 0x1C)) << 16) / 193U)) >>
                16;
            if (*(u32 *)(env + 4) != 0) {
                env[1] = 2;
                *(u32 *)(env + 8) = 0x7FFF0000;
                *(u32 *)(env + 0xC) = 0xC10000;
                *(u32 *)(env + 0x10) =
                    (u32)(-(s32)(((0xC1U - *(u16 *)(env + 0x1C)) << 16) /
                                 *(u32 *)(env + 4)));
                break;
            }
        case 2:
            if (*(u16 *)(env + 0x1C) != 0) {
                env[1] = 3;
                *(u32 *)(env + 0xC) = (u32)*(u16 *)(env + 0x1C) << 16;
                x = (s32)(*(u32 *)(env + 0xC) + 0x8000) >> 16;
                y = 0xC1 - x;
                x = y & ~(y >> 31);
                *(u32 *)(env + 8) = (u32)gAdsrVolCurve[x] << 16;
                *(u32 *)(env + 0x10) = 0;
                break;
            }
        case 4:
            done = 1;
            *(u32 *)(env + 8) = 0;
            break;
        }
        break;
    }
    return done;
}

void fn_80257C04(void *arg0) {
    M2C_UNK Sound_SetupAdsrPhase();
    M2C_FIELD(arg0, s8 *, 1) = 0;
    Sound_SetupAdsrPhase();
}

s32 fn_80257C2C(u8 *arg0, u32 arg1) {
    u32 __cvt_fp2unsigned(f32, f32, f32);
    extern u8 gSoundLevelCurve[];
    extern f32 lbl_8036C298;
    f32 temp_f2;
    u32 temp_r3;

    switch (arg0[0]) {
    case 0:
        arg0[1] = 4;
        *(u32 *)(arg0 + 4) = arg1;
        if (arg1 == 0) {
            *(u32 *)(arg0 + 4) = 1;
            *(s32 *)(arg0 + 0x10) = 0;
            return 1;
        }
        *(s32 *)(arg0 + 0x10) = -(s32)(*(u32 *)(arg0 + 8) / arg1);
        break;
    case 1:
        if (arg0[0x26] == 0 && arg0[1] == 1) {
            *(s32 *)(arg0 + 0xC) = (0xC1 - gSoundLevelCurve[*(s32 *)(arg0 + 8) >> 21]) << 16;
        }
        temp_f2 = lbl_8036C298 * (f32)*(s32 *)(arg0 + 0xC);
        *(u32 *)(arg0 + 4) = __cvt_fp2unsigned(temp_f2 * (f32)arg1, temp_f2, lbl_8036C298) >> 12;
        arg0[1] = 4;
        temp_r3 = *(u32 *)(arg0 + 4);
        if (temp_r3 == 0) {
            *(u32 *)(arg0 + 4) = 1;
            *(u32 *)(arg0 + 8) = 0;
            *(s32 *)(arg0 + 0xC) = 0;
            *(s32 *)(arg0 + 0x10) = 0;
            return 1;
        }
        *(s32 *)(arg0 + 0x10) = -(s32)((u32)*(s32 *)(arg0 + 0xC) / temp_r3);
        break;
    }
    return 0;
}

s32 fn_80257D7C(u8 *arg0) {
    u32 __cvt_fp2unsigned(f32, f32, f32);
    extern u8 gSoundLevelCurve[];
    extern f32 lbl_8036C298;
    f32 temp_f2;
    u32 temp_r3;
    u32 temp_r4;
    u8 temp_r0;

    temp_r0 = arg0[0];
    if ((s32)temp_r0 < 2) {
        if ((s32)temp_r0 < 0) {
            return 0;
        }
        temp_r4 = *(u32 *)(arg0 + 0x20);
        switch ((s32)temp_r0) {
        case 0:
            arg0[1] = 4;
            *(u32 *)(arg0 + 4) = temp_r4;
            if (temp_r4 == 0) {
                *(u32 *)(arg0 + 4) = 1;
                *(s32 *)(arg0 + 0x10) = 0;
                return 1;
            }
            *(s32 *)(arg0 + 0x10) = -(s32)(*(u32 *)(arg0 + 8) / temp_r4);
            break;
        case 1:
            if (arg0[0x26] == 0 && arg0[1] == 1) {
                *(s32 *)(arg0 + 0xC) = (0xC1 - gSoundLevelCurve[*(s32 *)(arg0 + 8) >> 21]) << 16;
            }
            temp_f2 = lbl_8036C298 * (f32)*(s32 *)(arg0 + 0xC);
            *(u32 *)(arg0 + 4) = __cvt_fp2unsigned(temp_f2 * (f32)temp_r4, temp_f2, lbl_8036C298) >> 12;
            arg0[1] = 4;
            temp_r3 = *(u32 *)(arg0 + 4);
            if (temp_r3 == 0) {
                *(u32 *)(arg0 + 4) = 1;
                *(u32 *)(arg0 + 8) = 0;
                *(s32 *)(arg0 + 0xC) = 0;
                *(s32 *)(arg0 + 0x10) = 0;
                return 1;
            }
            *(s32 *)(arg0 + 0x10) = -(s32)((u32)*(s32 *)(arg0 + 0xC) / temp_r3);
            break;
        }
    }
    return 0;
}

s32 Sound_TickAdsr(u8 *env, s16 *outVol, s16 *outDelta) {
    /* Advance one ADSR tick; write current volume and per-tick delta. */
    extern u16 gAdsrVolCurve[];
    s32 Sound_SetupAdsrPhase(u8 *);
    s32 done;
    s32 oldVol;
    s32 delta;
    s32 idx;
    s32 clipped;
    s32 ticks;
    u8 phase;

    done = 0;
    switch (env[0]) {
    case 0:
        if (env[1] != 3) {
            oldVol = *(s32 *)(env + 8);
            *(s32 *)(env + 8) = oldVol + *(s32 *)(env + 0x10);
            *outVol = (s16)(oldVol >> 16);
            delta = *(s32 *)(env + 0x10);
            if (delta >= 0) {
                *outDelta = (s16)(delta >> 21);
            } else {
                *outDelta = (s16) -(-delta >> 21);
            }
            ticks = *(s32 *)(env + 4) - 1;
            *(s32 *)(env + 4) = ticks;
            if (ticks == 0) {
                done = Sound_SetupAdsrPhase(env);
            }
        } else {
            *outVol = (s16)(*(s32 *)(env + 8) >> 16);
            *outDelta = 0;
        }
        break;
    case 1:
        phase = env[1];
        if (phase != 3) {
            oldVol = *(s32 *)(env + 8);
            if (env[0x26] == 0 && phase == 1) {
                *(s32 *)(env + 8) = oldVol + *(s32 *)(env + 0x10);
            } else {
                *(s32 *)(env + 0xC) = *(s32 *)(env + 0xC) + *(s32 *)(env + 0x10);
                idx = (s32)(*(u32 *)(env + 0xC) + 0x8000) >> 16;
                clipped = 0xC1 - idx;
                idx = clipped & ~(clipped >> 31);
                *(s32 *)(env + 8) = (s32)gAdsrVolCurve[idx] << 16;
            }
            *outVol = (s16)(oldVol >> 16);
            delta = *(s32 *)(env + 8) - oldVol;
            if (delta >= 0) {
                *outDelta = (s16)(delta >> 21);
            } else {
                *outDelta = (s16) -(-delta >> 21);
            }
            ticks = *(s32 *)(env + 4) - 1;
            *(s32 *)(env + 4) = ticks;
            if (ticks == 0) {
                done = Sound_SetupAdsrPhase(env);
            }
        } else {
            *outVol = (s16)(*(s32 *)(env + 8) >> 16);
            *outDelta = 0;
        }
        break;
    }
    return done;
}

s32 fn_8025807C(s32 arg0, s32 arg1, s32 arg2) {
    u32 Sound_TickAdsr(s32, s32, s32);
    u8 i;
    for (i = 0; i < 15; i++) {
        if (Sound_TickAdsr(arg0, arg1, arg2) != 0) {
            return 1;
        }
    }
    return 0;
}

void fn_80258100(void) { extern u8 gSoundStreamCtrl[]; u32 i; gSoundStreamCtrl[0]=0; for(i=0;i<64;i++) gSoundStreamCtrl[0xB08+i]=0xFF; *(u16*)(gSoundStreamCtrl+0xB48)=0; *(u32*)(gSoundStreamCtrl+0xB4C)=0; }

#pragma global_optimizer off
#pragma inline_depth(0)
/* Free any prior stream for callId, allocate a slot, init it, and return id|serial or -1. */
int Sound_AllocStream(u32 callIdIn) {
extern u8 gSoundStreamCtrl[];
s32 fn_802631AC(u8,s32*);
void Sound_SetVoiceStreamParams(s32,s32,s32);
u16 fn_80261B28(s32);
s32 fn_80261B3C(s32);
u8 fn_80261B14(s32);
u16 serial;
u32 count;
u8 i, slot, j;
s32 offset;
u8 callId;
u16 *serialPtr;
u8 *slotMap;
u32 id=(u8)callIdIn;
u8 *idPtr;
s32 result;u32 *handle;
u8 *scan;
u32 limit;
for(i=0;i<(count=gSoundStreamCtrl[0]);i++){
u8 *entry=gSoundStreamCtrl+i*0x2c;
u8 *state=entry+8;u8 *owner;
if(*state!=0){ owner=entry+11;
if(*owner==(u8)callIdIn){*state=0;(*(gSoundStreamCtrl+*owner+0xb08))=255;}}
}
for(slot=0;slot<count;slot++) {
if((*(gSoundStreamCtrl+slot*0x2c+8))==0) {
u8 *entry;u8 state=1;
entry=gSoundStreamCtrl+slot*0x2c;
entry[8]=state;*(u32*)(entry+12)=0;goto allocated;
}
}
slot=255;
allocated:
callId=id;
slotMap=gSoundStreamCtrl+0xb08;
slotMap[callId]=slot;
if(slot!=255){
{s32 value=fn_802631AC(slotMap[callId],0);Sound_SetVoiceStreamParams(callId,value,*(s32*)(gSoundStreamCtrl+4));}
{u16 value=fn_80261B28(callId);offset=slot*0x2c;
*(u16*)(gSoundStreamCtrl+offset+0x18)=value;}
limit=gSoundStreamCtrl[0];
do {
serial=(*(u16*)(gSoundStreamCtrl+0xb48))++;
for(j=0;j<limit;j++){
scan=gSoundStreamCtrl+j*0x2c;
if(scan[8]!=0 && *(u16*)(scan+0x1a)==serial) break;
}
}while(j!=limit);
serialPtr=(u16*)(gSoundStreamCtrl+offset);
*(serialPtr+=13)=serial;
result=fn_80256000(callIdIn);
handle=(u32*)(gSoundStreamCtrl+offset);
*(handle+=7)=result;
if((u32)result+0x10000U!=0xffffU)
*(s32*)(gSoundStreamCtrl+offset+0x20)=fn_8024B5B0(*handle);
else *(s32*)(gSoundStreamCtrl+offset+0x20)=-1;
*(s32*)(gSoundStreamCtrl+offset+0x24)=fn_80261B3C(callId);
*(gSoundStreamCtrl+offset+10)=fn_80261B14(callId);
idPtr=gSoundStreamCtrl+offset+11;
*idPtr=id;
if(*(u32*)(gSoundStreamCtrl+0xb4c)!=0 && (*(u32(**)(s32,void*))(gSoundStreamCtrl+0xb4c))(0,gSoundStreamCtrl+offset+0x18)==0) return (id&~0xffff00)|((*serialPtr<<8)&0xffff00);
Sound_SetVoiceStreamParams(callId,0,0);
*(gSoundStreamCtrl+offset+8)=0;
slotMap[*idPtr]=255;
}
else Sound_SetVoiceStreamParams(callId,0,0);
return -1;
}

#pragma optimization_level 3
int fn_80258488(u32 arg0)
{
    extern u8 gSoundStreamCtrl[];
    s32 offset;
    u8 *slotMap;
    u8 *ctrl;
    u8 slot;
    u16 *entry;
    if (((u32) (arg0 + 0x10000)) != 0xFFFFU)
    {
        ctrl = gSoundStreamCtrl;
        slotMap = ctrl + 0xB08;
        slot = slotMap[(u8) arg0];
        if (slot != 0xFF)
        {
            offset = slot * 0x2C;
            entry = (u16 *)(ctrl + offset);
            if (entry[0xD] == ((u16) (arg0 >> 8)))
            {
                if ((*((u32 *) (ctrl + 0xB4C))) != 0)
                {
                    (*((void (**)(s32, void *)) (ctrl + 0xB4C)))(2, entry + 0xC);
                }
                (gSoundStreamCtrl + offset)[8] = 0;
                slotMap[(gSoundStreamCtrl + offset)[0xB]] = 0xFF;
            }
        }
    }
}
#pragma optimization_level reset
void Sound_SeekStreamPos(void *arg0, u32 arg1) {
    /* Seek a stream entry toward sample arg1 (ADPCM type 5 / PCM type 6). */
    extern u8 gSoundStreamCtrl[];
    u8 *self = arg0;
    u32 pos = *(u32 *)(self + 4);
    u32 result;
    u8 *state;

    if (pos != arg1) {
        if (pos < arg1) {
            switch (self[2]) {
            case 5:
                *(u32 *)(self + 0x1C) = (pos / 14) * 8;
                *(u32 *)(self + 0x20) = arg1 - *(u32 *)(self + 4);
                *(u32 *)(self + 0x24) = 0;
                *(u32 *)(self + 0x28) = 0;
                result = (*(u32 (**)(s32, void *))(gSoundStreamCtrl + 0xB4C))(1, self + 0x10);
                if (result)
                    *(u32 *)(self + 4) = (*(u32 *)(self + 4) + result) % *(u32 *)(gSoundStreamCtrl + 4);
                break;
            case 6:
                *(u32 *)(self + 0x1C) = pos * 2;
                *(u32 *)(self + 0x20) = arg1 - *(u32 *)(self + 4);
                *(u32 *)(self + 0x24) = 0;
                *(u32 *)(self + 0x28) = 0;
                result = (*(u32 (**)(s32, void *))(gSoundStreamCtrl + 0xB4C))(1, self + 0x10);
                if (result)
                    *(u32 *)(self + 4) = (*(u32 *)(self + 4) + result) % *(u32 *)(gSoundStreamCtrl + 4);
                break;
            }
        } else if (arg1 == 0) {
            switch (self[2]) {
            case 5:
                *(u32 *)(self + 0x1C) = (pos / 14) * 8;
                state = gSoundStreamCtrl;
                *(u32 *)(self + 0x20) = *(u32 *)(state + 4) - *(u32 *)(self + 4);
                *(u32 *)(self + 0x24) = 0;
                *(u32 *)(self + 0x28) = 0;
                result = (*(u32 (**)(s32, void *))(state + 0xB4C))(1, self + 0x10);
                if (result)
                    *(u32 *)(self + 4) = (*(u32 *)(self + 4) + result) % *(u32 *)(state + 4);
                break;
            case 6:
                *(u32 *)(self + 0x1C) = pos * 2;
                state = gSoundStreamCtrl;
                *(u32 *)(self + 0x20) = *(u32 *)(state + 4) - *(u32 *)(self + 4);
                *(u32 *)(self + 0x24) = 0;
                *(u32 *)(self + 0x28) = 0;
                result = (*(u32 (**)(s32, void *))(state + 0xB4C))(1, self + 0x10);
                if (result)
                    *(u32 *)(self + 4) = (*(u32 *)(self + 4) + result) % *(u32 *)(state + 4);
                break;
            }
        } else {
            switch (self[2]) {
            case 5:
                *(u32 *)(self + 0x1C) = (pos / 14) * 8;
                state = gSoundStreamCtrl;
                *(u32 *)(self + 0x20) = *(u32 *)(state + 4) - *(u32 *)(self + 4);
                *(u32 *)(self + 0x24) = 0;
                *(u32 *)(self + 0x28) = arg1;
                result = (*(u32 (**)(s32, void *))(state + 0xB4C))(1, self + 0x10);
                if (result)
                    *(u32 *)(self + 4) = (*(u32 *)(self + 4) + result) % *(u32 *)(state + 4);
                break;
            case 6:
                *(u32 *)(self + 0x1C) = pos * 2;
                state = gSoundStreamCtrl;
                *(u32 *)(self + 0x20) = *(u32 *)(state + 4) - *(u32 *)(self + 4);
                *(u32 *)(self + 0x24) = 0;
                *(u32 *)(self + 0x28) = arg1;
                result = (*(u32 (**)(s32, void *))(state + 0xB4C))(1, self + 0x10);
                if (result)
                    *(u32 *)(self + 4) = (*(u32 *)(self + 4) + result) % *(u32 *)(state + 4);
                break;
            }
        }
    }
}

#pragma inline_depth(8)
#pragma global_optimizer reset
void fn_80258888(void) {
    u32 fn_80261B00(u32);
    u32 fn_80262154(u32, void *);
    void Sound_SeekStreamPos(void *, u32);
    u32 fn_80262510(u8);
    u32 fn_80262538(void);
    void fn_802618E4(u8);
    void fn_80255054(void *);
    void fn_80256FF0(u8);
    extern u8 gSoundStreamCtrl[];
    extern s32 gSynthVoices;

    u8 *ctrl;
    u8 *walk;
    u32 i;
    u32 pos;
    u8 *e;
    u32 adj;
    s32 thresh;
    u8 state;

    ctrl = gSoundStreamCtrl;
    if (*(u32 *)(ctrl + 0xB4C) == 0) {
        return;
    }

    i = 0;
    walk = ctrl;
    do {
        if (walk[0xB08] != 0xFF && fn_80261B00(i) != 0) {
            e = gSoundStreamCtrl + walk[0xB08] * 0x2C + 8;
            pos = fn_80262154(i, e - 8);
            if (e[2] == 5) {
                adj = pos / 7;
                adj *= 14;
            } else {
                adj = pos;
            }
            state = e[0];
            switch (state) {
            case 1:
                Sound_SeekStreamPos(e, adj);
                break;
            case 2:
            case 3:
                if (((*(u16 *)(e + 0x12) << 8) | e[3]) == fn_80262510(e[3])) {
                    Sound_SeekStreamPos(e, adj);
                    if (pos >= *(u32 *)(e + 0xC)) {
                        *(u32 *)(e + 8) = *(u32 *)(e + 8) - (pos - *(u32 *)(e + 0xC));
                    } else {
                        *(u32 *)(e + 8) = *(u32 *)(e + 8) - (*(u32 *)(ctrl + 4) - (*(u32 *)(e + 0xC) - pos));
                    }
                    *(u32 *)(e + 0xC) = pos;
                    {
                        u8 id = e[3];
                        u8 *sb = (u8 *)gSynthVoices;
                        s32 t = *(u16 *)(sb + id * 0x458 + 0x212);
                        thresh = (t * 0xA0 + 0xFFF) / 4096;
                    }
                    if (thresh > (s32)*(u32 *)(e + 8)) {
                        if (fn_80262538() == 0) {
                            if (e[0] == 2) {
                                fn_802618E4(e[3]);
                                fn_80255054((u8 *)gSynthVoices + e[3] * 0x458);
                            } else {
                                fn_80256FF0(e[3]);
                            }
                        }
                        e[0] = 0;
                        gSoundStreamCtrl[0xB08 + e[3]] = 0xFF;
                    }
                } else {
                    e[0] = 0;
                    gSoundStreamCtrl[0xB08 + e[3]] = 0xFF;
                }
                break;
            }
        }
        i += 1;
        walk += 1;
    } while (i < 0x40);
}

void fn_80258A98(s32 arg0, s32 arg1) {
    extern s32 lbl_8035B220[];
    extern s32 *lbl_80368A60;
    extern s32 *gAudioGroupState;
    extern s32 *lbl_80368A58;

    lbl_80368A60 = NULL;
    lbl_8035B220[1] = -2;
    M2C_FIELD(lbl_8035B220, u16 *, 8) = 0;
    lbl_8035B220[0x183] = arg0;
    lbl_8035B220[0x185] = arg0;
    lbl_8035B220[0x184] = arg0 + arg1;
    lbl_8035B220[0] = 0;
    lbl_80368A60 = lbl_8035B220;
    lbl_80368A58 = NULL;
    gAudioGroupState = lbl_8035B220;
}

void *fn_80258AD8(void) {
    extern u16 lbl_8035B220[];
    return (u8 *)lbl_8035B220 + 0x60c;
}

/* Bind or unbind an audio resource id by type (table/bank/sample/wave/group). */
void Sound_SetResource(s32 id, void *data, u8 type, u32 remove) {
    void AudioTable_Insert(s32, s32);
    s32 AudioTable_Remove();
    void AudioBank_Insert(s32, s32);
    void AudioBank_Remove(s32);
    s32 SampleKey_Insert();
    void SampleKey_Remove(s32);
    s32 AudioWave_Insert();
    void AudioWave_Remove(s32);
    void AudioGroup_Register(s32, s32);
    s32 AudioGroup_Unregister();
    extern s32 *gAudioGroupState;
    u8 *node;

    switch (type) {
    case 0:
        if (remove == 0) {
            node = FindAudioResource(data, (u16)(id), 0);
            if (node != NULL) {
                AudioTable_Insert(id, (s32)(node + 8));
            } else {
                AudioTable_Insert(id, 0);
            }
        } else {
            AudioTable_Remove(id);
        }
        break;
    case 2:
        if (remove == 0) {
            node = FindAudioResource(data, (u16)(id | 0x4000), 8);
            if (node != NULL) {
                AudioBank_Insert(id | 0x4000, (s32)(node + 8));
            } else {
                AudioBank_Insert(id | 0x4000, 0);
            }
        } else {
            AudioBank_Remove(id | 0x4000);
        }
        break;
    case 3:
        if (remove == 0) {
            node = FindAudioResource(data, (u16)(id | 0x8000), 12);
            if (node != NULL) {
                SampleKey_Insert(id | 0x8000, (s32)(node + 12), (u16)*(u32 *)(node + 8));
            } else {
                SampleKey_Insert(id | 0x8000, 0, 0);
            }
        } else {
            SampleKey_Remove(id | 0x8000);
        }
        break;
    case 4:
        if (remove == 0) {
            node = FindAudioResource(data, (u16)(id), 4);
            if (node != NULL) {
                AudioWave_Insert(id, (s32)(node + 8));
            } else {
                AudioWave_Insert(id, 0);
            }
        } else {
            AudioWave_Remove(id);
        }
        break;
    case 1:
        if (remove == 0) {
            AudioGroup_Register(id, (s32)((u8 *)gAudioGroupState + 0x60C));
        } else {
            AudioGroup_Unregister(id, (s32)((u8 *)gAudioGroupState + 0x60C));
        }
        break;
    }
}

void fn_80258D74(void) {
    M2C_UNK fn_80262410();
    fn_80262410();
}

/* Find groupId in groupData and register its sample/macro/curve/keymap/layer id lists. */
s32 Sound_PushGroup(void *groupData, u16 groupId, s32 translate, s32 sampleDir, s32 poolData) {
extern u8 gSoundReady;
extern s32 *gAudioGroupState;
s32 fn_802622F4(s32);
u32 fn_8024F964(s32,s32);
void Sound_SetResource(s32,void *,u8,u32);
s32 fn_8024FE1C(u16,void *,u16);
void fn_802624B8(void);
s16 n;
AudioGroupState *state;
u32 i; u16 *p; u8 *node;
if(gSoundReady && (state=(AudioGroupState *)gAudioGroupState, n=state->count)<128) {
for(node=groupData; *(u32 *)node != 0xFFFFFFFF; node=(u8 *)groupData+*(u32 *)node) {
if(*(u16 *)(node+4)==groupId) {
state=(AudioGroupState *)((u8 *)state+n*12); state->slots[0].node=node;
state=(AudioGroupState *)gAudioGroupState; state=(AudioGroupState *)((u8 *)state+state->count*12); state->slots[0].data=groupData;
state=(AudioGroupState *)gAudioGroupState; state=(AudioGroupState *)((u8 *)state+state->count*12); state->slots[0].id=sampleDir;
p=(u16 *)((u8 *)groupData+*(u32 *)(node+12));
if(fn_8024F964(sampleDir,fn_802622F4(translate))) {
while(*p!=0xFFFF) { if(*p & 0x8000) { for(i=*p & 0x3FFF;(u16)i<=p[1];i++) Sound_SetResource(i,(void *)sampleDir,1,0); p+=2; } else { Sound_SetResource(*p++,(void *)sampleDir,1,0); } }
}
{ u32 j; u16 *q;
q=(u16 *)((u8 *)groupData+*(u32 *)(node+8));
while(*q!=0xFFFF) { if(*q & 0x8000) { for(j=*q & 0x3FFF;(u16)j<=q[1];j++) Sound_SetResource(j,(void *)poolData,0,0); q+=2; } else { Sound_SetResource(*q++,(void *)poolData,0,0); } }
}
{ u32 j; u16 *q;
q=(u16 *)((u8 *)groupData+*(u32 *)(node+16));
while(*q!=0xFFFF) { if(*q & 0x8000) { for(j=*q & 0x3FFF;(u16)j<=q[1];j++) Sound_SetResource(j,(void *)poolData,4,0); q+=2; } else { Sound_SetResource(*q++,(void *)poolData,4,0); } }
}
{ u32 j; u16 *q;
q=(u16 *)((u8 *)groupData+*(u32 *)(node+20));
while(*q!=0xFFFF) { if(*q & 0x8000) { for(j=*q & 0x3FFF;(u16)j<=q[1];j++) Sound_SetResource(j,(void *)poolData,2,0); q+=2; } else { Sound_SetResource(*q++,(void *)poolData,2,0); } }
}
{ u32 j; u16 *q;
q=(u16 *)((u8 *)groupData+*(u32 *)(node+24));
while(*q!=0xFFFF) { if(*q & 0x8000) { for(j=*q & 0x3FFF;(u16)j<=q[1];j++) Sound_SetResource(j,(void *)poolData,3,0); q+=2; } else { Sound_SetResource(*q++,(void *)poolData,3,0); } }
if(*(u16 *)(node+6)==1) { q=(u16 *)((u8 *)groupData+*(u32 *)(node+28)); fn_8024FE1C(groupId,(u8 *)q+4,*q); }
}
fn_802624B8(); (*(s16 *)((u8 *)gAudioGroupState+8))++; return 1;
}
}
}
return 0;
}

#pragma opt_strength_reduction off
s32 fn_802590E0(void) {
extern s32 *gAudioGroupState;
void Audio_Lock(void); void Audio_Unlock(void);
void fn_8025D9A4(void *,u16); void fn_80245014(u16);
void fn_802572E8(void *); void fn_80257444(void *);
void fn_8024FACC(s32); void fn_8024FF5C(u16);
void Sound_SetResource(s32,void *,u8,u32);
u8 *node; s32 id; u8 *base; u16 *p; u16 *start; s16 i;
AudioGroupState *state=(AudioGroupState *)gAudioGroupState;
s16 n=--state->count;
AudioGroupState *slot;
slot=(AudioGroupState *)((u8 *)state+n*12); node=slot->slots[0].node;
state=(AudioGroupState *)((u8 *)state+state->count*12);
base=state->slots[0].data;
id=state->slots[0].id;
Audio_Lock();
if(*(u16 *)(node+6)==1) {u16 *p; p=(u16 *)(base+*(u32 *)(node+28)); fn_8025D9A4((u8 *)p+4,*p);}
else fn_80245014(*(u16 *)(node+4));
fn_802572E8(base+*(u32 *)(node+8));
fn_80257444(base+*(u32 *)(node+12));
Audio_Unlock();
start=(u16 *)(base+*(u32 *)(node+12));
if(*start!=0xFFFF) {
p=start; while(*p!=0xFFFF) p++; p--;
while(p>=start) {
if(p!=start) {
if(p[-1]&0x8000) { for(i=(s16)*p;(s16)i>=(p[-1]&0x3FFF);i--) Sound_SetResource((u16)i,0,1,1); p-=2; }
else {Sound_SetResource(*p,0,1,1);p--;}
} else {Sound_SetResource(*p,0,1,1);p--;}
}
}
fn_8024FACC(id);
{ u32 j; u16 *q=(u16 *)(base+*(u32 *)(node+8)); while(*q!=0xFFFF) { if(*q&0x8000) { for(j=*q&0x3FFF;(u16)j<=q[1];j++) Sound_SetResource(j,0,0,1);q+=2;}else Sound_SetResource(*q++,0,0,1); } }
{ u32 j; u16 *q=(u16 *)(base+*(u32 *)(node+16)); while(*q!=0xFFFF) { if(*q&0x8000) { for(j=*q&0x3FFF;(u16)j<=q[1];j++) Sound_SetResource(j,0,4,1);q+=2;}else Sound_SetResource(*q++,0,4,1); } }
{ u32 j; u16 *q=(u16 *)(base+*(u32 *)(node+20)); while(*q!=0xFFFF) { if(*q&0x8000) { for(j=*q&0x3FFF;(u16)j<=q[1];j++) Sound_SetResource(j,0,2,1);q+=2;}else Sound_SetResource(*q++,0,2,1); } }
{ u32 j; u16 *q=(u16 *)(base+*(u32 *)(node+24)); while(*q!=0xFFFF) { if(*q&0x8000) { for(j=*q&0x3FFF;(u16)j<=q[1];j++) Sound_SetResource(j,0,3,1);q+=2;}else Sound_SetResource(*q++,0,3,1); } }
if(*(u16 *)(node+6)==1) fn_8024FF5C(*(u16 *)(node+4));return 1;
}
#pragma opt_strength_reduction reset
s32 fn_80259430(u16 gid,u16 sid,s32 arg2,s32 *arg3,s32 unlocked,u8 arg5) {
extern GroupNode *lbl_80368A60;
s32 fn_80243FB8(void*,void*,GroupItem*,s32,s32*,u8,u16);
void Audio_Lock(void);void Audio_Unlock(void);
GroupNode *node;
s32 i;
GroupData *data;
u32 base;
void *a;
void *b;
GroupItem *item;
s32 ret;
for(node=lbl_80368A60;node!=NULL;node=node->next) {
for(i=0;i<node->count;i++) {
if(node->entries[i].data->id==gid) {
data=node->entries[i].data;
if(data->type==0) {
base=node->entries[i].base;
a=(void*)(base+data->unk1C);
b=(void*)(base+data->unk20);
for(item=(GroupItem*)(base+data->unk24);item->id!=0xFFFF;item++) {
if(item->id==sid) {
if((u8)unlocked) ret=fn_80243FB8(a,b,item,arg2,arg3,arg5,gid);
else {Audio_Lock();ret=fn_80243FB8(a,b,item,arg2,arg3,arg5,gid);Audio_Unlock();}
return ret;
}
}
return -1;
}
return -1;
}
}
}
return -1;
}

s32 fn_80259584(u16 gid, u16 sid, s32 arg2, s32 arg3, s32 arg4) {
    extern GroupNode *lbl_80368A60;
    s32 fn_80243FB8(void *, void *, GroupItem *, s32, s32, s32, u16);
    s32 ret;
    GroupNode *node;
    s32 i;
    GroupData *data;
    u32 base;
    GroupItem *item;
    void *b;
    void *a;

    for (node = lbl_80368A60; node != NULL; node = node->next) {
        for (i = 0; i < node->count; i++) {
            if (node->entries[i].data->id == gid) {
                data = node->entries[i].data;
                if (data->type == 0) {
                    base = node->entries[i].base;
                    a = (void *)(base + data->unk1C);
                    b = (void *)(base + data->unk20);
                    for (item = (GroupItem *)(base + data->unk24); item->id != 0xFFFF; item++) {
                        if (item->id == sid) {
                            Audio_Lock();
                            ret = fn_80243FB8(a, b, item, arg2, arg3, arg4, gid);
                            Audio_Unlock();
                            goto done;
                        }
                    }
                    ret = -1;
                } else {
                    ret = -1;
                }
                goto done;
            }
        }
    }
    ret = -1;
done:
    return ret;
}

/* Allocate and initialize sound voice slots and studio mix buffers. */
s32 Sound_InitVoices(u8 voiceCount, u8 studioCount, s32 flag) {
    extern u8 gSoundVoiceCount, gSoundStudioCount;
    extern u8 *gSoundAuxBuf, *lbl_80368A98, *gSoundVoices, *gSoundVoiceParams, *lbl_80368A94;
    extern s32 lbl_80368A68;
    extern u8 gSoundStudios[];
    void *fn_802637D0(u32); void *fn_802637A4(u32);
    s32 fn_80262AD0(void); void fn_80259A94(s32, s32, s32); void fn_80259A5C(void);
    void fn_8020516C(void *, u16);
    void DCFlushRange(void *, u32); void DCFlushRangeNoSync(void *, u32); void DCInvalidateRange(void *, u32);
    u32 i; u32 off; u8 *params; u8 *studio;
    gSoundVoiceCount = voiceCount; gSoundStudioCount = studioCount;
    lbl_80368A68 = fn_80262AD0();
    if (!(gSoundAuxBuf = fn_802637D0(0x800))) goto fail;
    if (!(lbl_80368A98 = fn_802637D0(0x280))) goto fail;
    memset(lbl_80368A98, 0, 0x280); DCFlushRange(lbl_80368A98, 0x280);
    if (!(gSoundVoices = fn_802637A4(gSoundVoiceCount * 0xF8))) goto fail;
    if (!(gSoundVoiceParams = fn_802637D0(gSoundVoiceCount * 0x40))) goto fail;
    DCInvalidateRange(gSoundVoiceParams, gSoundVoiceCount * 0x40);
    params = gSoundVoiceParams;
    for (i = 0, off = 0; i < gSoundVoiceCount; off += 0xF8, i++) {
        gSoundVoices[off + 240] = 0;
        gSoundVoices[off + 241] = 0;
        gSoundVoices[off + 242] = 0;
        gSoundVoices[off + 232] = 255;
        gSoundVoices[off + 233] = 255;
        gSoundVoices[off + 234] = 255;
        gSoundVoices[off + 235] = 255;
        *(void **)(gSoundVoices + off) = fn_802637D0(0xC4);
        memset(*(void **)(gSoundVoices + off), 0, 0xC4);
        *(void **)(gSoundVoices + off + 4) = fn_802637D0(0x80);
        *(u16 *)(*(u8 **)(gSoundVoices + off) + 4) = (u32)*(void **)(gSoundVoices + off) >> 16;
        *(u16 *)(*(u8 **)(gSoundVoices + off) + 6) = (u32)*(void **)(gSoundVoices + off);
        *(u16 *)(*(u8 **)(gSoundVoices + off) + 0x4E) = (u32)*(void **)(gSoundVoices + off + 4) >> 16;
        *(u16 *)(*(u8 **)(gSoundVoices + off) + 0x50) = (u32)*(void **)(gSoundVoices + off + 4);
        *(u16 *)(*(u8 **)(gSoundVoices + off) + 0x38) = (u32)params >> 16;
        *(u16 *)(*(u8 **)(gSoundVoices + off) + 0x3A) = (u32)params;
        *(u8 **)(gSoundVoices + off + 8) = params; params += 0x40;
        *(s32 *)(gSoundVoices + off + 0xEC) = -1;
        fn_8020516C(*(void **)(gSoundVoices + off), 0xC4);
        *(u32 *)(gSoundVoices + off + 36) = 0;
        *(u32 *)(gSoundVoices + off + 40) = 0;
        *(u32 *)(gSoundVoices + off + 44) = 0;
        *(u32 *)(gSoundVoices + off + 48) = 0;
        *(u32 *)(gSoundVoices + off + 52) = 0;
    }
    for (off = 0, i = (u32)gSoundStudios; off < gSoundStudioCount; i += 0xBC, off++) {
        ((u8 *)i)[0x50] = 0;
        if (!(*(void **)i = fn_802637D0(0x36))) return 0;
        if (!(*(void **)(i + 0x28) = fn_802637D0(0x3C00))) return 0;
        memset(*(void **)(i + 0x28), 0, 0x3C00);
        DCFlushRangeNoSync(*(void **)(i + 0x28), 0x3C00);
        *(u8 **)(i + 44) = *(u8 **)(i + 40) + 0x780;
        *(u8 **)(i + 48) = *(u8 **)(i + 44) + 0x780;
        *(u8 **)(i + 52) = *(u8 **)(i + 48) + 0x780;
        *(u8 **)(i + 56) = *(u8 **)(i + 52) + 0x780;
        *(u8 **)(i + 60) = *(u8 **)(i + 56) + 0x780;
        *(u8 **)(i + 64) = *(u8 **)(i + 60) + 0x780;
        *(u8 **)(i + 68) = *(u8 **)(i + 64) + 0x780;
        memset(*(void **)i, 0, 0x36);
        *(u32 *)(i + 12) = 0;
        *(u32 *)(i + 8) = 0;
        *(u32 *)(i + 4) = 0;
        *(u32 *)(i + 24) = 0;
        *(u32 *)(i + 20) = 0;
        *(u32 *)(i + 16) = 0;
        *(u32 *)(i + 36) = 0;
        *(u32 *)(i + 32) = 0;
        *(u32 *)(i + 28) = 0;
        DCFlushRangeNoSync(*(void **)i, 0x36);
    }
    fn_80259A94(0, 1, flag != 0);
    if (!(lbl_80368A94 = fn_802637D0(0x100))) return 0;
    fn_80259A5C(); return 1;
fail: return 0;
}

void fn_80259A5C(void) {
    M2C_UNK DCFlushRangeNoSync(s32, M2C_UNK);
    M2C_UNK memset(s32, M2C_UNK, M2C_UNK);
    extern s32 lbl_80368A94;
    memset(lbl_80368A94, 0, 0x100);
    DCFlushRangeNoSync(lbl_80368A94, 0x100);
}

void fn_80259A94(s32 arg0,s32 arg1,s32 arg2) {
extern u8 gSoundStudios[];
void *memset(void*,s32,u32);
void DCFlushRangeNoSync(void*,u32);
s32 offset=(u8)arg0*0xBC;
u8 *p;
p=gSoundStudios+offset;
memset(*(void**)(p+0x28),0,0x3C00);
DCFlushRangeNoSync(*(void**)(p+0x28),0x3C00);
memset(*(void**)(gSoundStudios+offset),0,0x36);
p=gSoundStudios+offset;
*(u32*)(p+0xC)=*(u32*)(p+8)=*(u32*)(p+4)=0;
*(u32*)(p+0x18)=*(u32*)(p+0x14)=*(u32*)(p+0x10)=0;
*(u32*)(p+0x24)=*(u32*)(p+0x20)=*(u32*)(p+0x1C)=0;
DCFlushRangeNoSync(*(void**)(gSoundStudios+offset),0x36);
p=gSoundStudios+offset;
memset(*(void**)(p+0x30),0,0x780);
DCFlushRangeNoSync(*(void**)(p+0x30),0x780);
p=gSoundStudios+offset;
memset(*(void**)(p+0x3C),0,0x780);
DCFlushRangeNoSync(*(void**)(p+0x3C),0x780);
p=gSoundStudios+offset;
*(u32*)(p+0x48)=0;
*(u32*)(p+0x4C)=0;
p[0x50]=1;
p[0x51]=arg1;
p[0x52]=0;
*(u32*)(p+0x54)=arg2;
*(u32*)(p+0xB0)=0;
*(u32*)(p+0xAC)=0;
}

s32 Sound_ApplyParamStep(s16 *related, u16 *dir, u16 *current, u16 target, u16 *flags, u16 flagBit) {
    /* Step *current toward target in units of 32; set *dir and OR flagBit into flags[idx]. */
    s16 diff;
    s16 idx;

    if (target != *current) {
        diff = (s16)target - (s16)*current;
        if (diff >= 0x20 && diff < 0xA0) {
            idx = (s16)(diff >> 5);
            if (idx < 5) {
                flags[idx] |= flagBit;
            }
            *dir = 1;
            *current += idx << 5;
            return 1;
        }
        if (diff <= -0x20 && diff > -0xA0) {
            idx = (s16)(-diff >> 5);
            if (idx < 5) {
                flags[idx] |= flagBit;
            }
            *dir = 0xFFFF;
            *current -= idx << 5;
            return 1;
        }
        if (target == 0 && diff > -0x20) {
            *current = 0;
            *related = 0;
        }
    }
    *dir = 0;
    return 0;
}

void fn_80259CD8(u16 *arg0, u16 *arg1, s16 arg2) {
    *arg0 = (arg2 - (s16) *arg1) / 160;
    *arg1 += (s16) *arg0 * 0xA0;
}

void fn_80259D20(void *arg0)
{
    u32 temp_r4;
    u32 var_r5;

    if (*(u32 *)((char *)arg0 + 0x8C) == 0U) {
        if (*(u16 *)((char *)*(void **)arg0 + 8) != 2) {
            var_r5 = *(s32 *)((char *)arg0 + 0xE4) << 5;
        } else {
            var_r5 = 0x200000;
        }
        temp_r4 = *(u32 *)((char *)arg0 + 0xE0);
        *(u32 *)((char *)arg0 + 0xE0) = (u32)(temp_r4 + (var_r5 << 16));
        if (temp_r4 > *(u32 *)((char *)arg0 + 0xE0)) {
            temp_r4 = *(u32 *)((char *)arg0 + 0xDC);
            temp_r4 = (var_r5 >> 16) + temp_r4;
            *(u32 *)((char *)arg0 + 0xDC) = temp_r4 + 1;
            return;
        }
        *(u32 *)((char *)arg0 + 0xDC) =
            *(u32 *)((char *)arg0 + 0xDC) + (var_r5 >> 16);
    }
}

void fn_80259D94(s32 *arg0, s16 *arg1, s32 *arg2) {
    s16 var_r0;
    s16 var_r0_2;
    s32 temp_r0;

    temp_r0 = *arg2;
    if (temp_r0 <= -0xA0) {
        if (temp_r0 <= -0xC80) {
            var_r0 = 0x14;
        } else {
            var_r0 = (s16) (-temp_r0 / 160);
        }
        *arg1 = var_r0;
    } else if (temp_r0 >= 0xA0) {
        if (temp_r0 >= 0xC80) {
            var_r0_2 = -0x14;
        } else {
            var_r0_2 = (s16) (-temp_r0 / 160);
        }
        *arg1 = var_r0_2;
    } else {
        *arg1 = 0;
    }
    *arg0 = *arg2;
    *arg2 += *arg1 * 0xA0;
}

void fn_80259E40(void *arg0, void *arg1) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r0_5;
    s32 temp_r0_6;
    s32 temp_r0_7;
    s32 temp_r0_8;
    s32 temp_r0_9;
    s32 var_r4;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r5_3;
    s32 var_r5_4;
    s32 var_r5_5;
    s32 var_r5_6;
    s32 var_r5_7;
    s32 var_r5_8;
    void *temp_r4;

    M2C_FIELD(arg1, s8 *, 0xF1) = 0;
    M2C_FIELD(M2C_FIELD(arg1, void **, 0), s16 *, 0xE) = 0;
    temp_r4 = M2C_FIELD(arg1, void **, 0);
    if (M2C_FIELD(temp_r4, u16 *, 0xC) & 1) {
        var_r5 = 0x7FFFFF;
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + (s16) M2C_FIELD(temp_r4, u16 *, 0x52));
        temp_r0 = M2C_FIELD(arg0, s32 *, 4);
        if (temp_r0 > 0x7FFFFF) {

        } else {
            var_r5 = -0x7FFFFF;
            if (temp_r0 < 0xFF800001) {

            } else {
                var_r5 = temp_r0;
            }
        }
        M2C_FIELD(arg0, s32 *, 4) = var_r5;
    }
    if (M2C_FIELD(temp_r4, u16 *, 0xC) & 2) {
        var_r5_2 = 0x7FFFFF;
        M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + (s16) M2C_FIELD(temp_r4, u16 *, 0x58));
        temp_r0_2 = M2C_FIELD(arg0, s32 *, 8);
        if (temp_r0_2 > 0x7FFFFF) {

        } else {
            var_r5_2 = -0x7FFFFF;
            if (temp_r0_2 < 0xFF800001) {

            } else {
                var_r5_2 = temp_r0_2;
            }
        }
        M2C_FIELD(arg0, s32 *, 8) = var_r5_2;
    }
    if (M2C_FIELD(temp_r4, u16 *, 0xC) & 4) {
        var_r5_3 = 0x7FFFFF;
        M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) + (s16) M2C_FIELD(temp_r4, u16 *, 0x5E));
        temp_r0_3 = M2C_FIELD(arg0, s32 *, 0xC);
        if (temp_r0_3 > 0x7FFFFF) {

        } else {
            var_r5_3 = -0x7FFFFF;
            if (temp_r0_3 < 0xFF800001) {

            } else {
                var_r5_3 = temp_r0_3;
            }
        }
        M2C_FIELD(arg0, s32 *, 0xC) = var_r5_3;
    }
    if (M2C_FIELD(temp_r4, u16 *, 0xC) & 0x10) {
        var_r5_4 = 0x7FFFFF;
        M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + (s16) M2C_FIELD(temp_r4, u16 *, 0x54));
        temp_r0_4 = M2C_FIELD(arg0, s32 *, 0x10);
        if (temp_r0_4 > 0x7FFFFF) {

        } else {
            var_r5_4 = -0x7FFFFF;
            if (temp_r0_4 < 0xFF800001) {

            } else {
                var_r5_4 = temp_r0_4;
            }
        }
        M2C_FIELD(arg0, s32 *, 0x10) = var_r5_4;
    }
    if (M2C_FIELD(temp_r4, u16 *, 0xC) & 0x20) {
        var_r5_5 = 0x7FFFFF;
        M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg0, s32 *, 0x14) + (s16) M2C_FIELD(temp_r4, u16 *, 0x5A));
        temp_r0_5 = M2C_FIELD(arg0, s32 *, 0x14);
        if (temp_r0_5 > 0x7FFFFF) {

        } else {
            var_r5_5 = -0x7FFFFF;
            if (temp_r0_5 < 0xFF800001) {

            } else {
                var_r5_5 = temp_r0_5;
            }
        }
        M2C_FIELD(arg0, s32 *, 0x14) = var_r5_5;
    }
    if (M2C_FIELD(temp_r4, u16 *, 0xC) & 0x80) {
        var_r5_6 = 0x7FFFFF;
        M2C_FIELD(arg0, s32 *, 0x18) = (s32) (M2C_FIELD(arg0, s32 *, 0x18) + (s16) M2C_FIELD(temp_r4, u16 *, 0x60));
        temp_r0_6 = M2C_FIELD(arg0, s32 *, 0x18);
        if (temp_r0_6 > 0x7FFFFF) {

        } else {
            var_r5_6 = -0x7FFFFF;
            if (temp_r0_6 < 0xFF800001) {

            } else {
                var_r5_6 = temp_r0_6;
            }
        }
        M2C_FIELD(arg0, s32 *, 0x18) = var_r5_6;
    }
    if (M2C_FIELD(temp_r4, u16 *, 0xC) & 0x200) {
        var_r5_7 = 0x7FFFFF;
        M2C_FIELD(arg0, s32 *, 0x1C) = (s32) (M2C_FIELD(arg0, s32 *, 0x1C) + (s16) M2C_FIELD(temp_r4, u16 *, 0x56));
        temp_r0_7 = M2C_FIELD(arg0, s32 *, 0x1C);
        if (temp_r0_7 > 0x7FFFFF) {

        } else {
            var_r5_7 = -0x7FFFFF;
            if (temp_r0_7 < 0xFF800001) {

            } else {
                var_r5_7 = temp_r0_7;
            }
        }
        M2C_FIELD(arg0, s32 *, 0x1C) = var_r5_7;
    }
    if (M2C_FIELD(temp_r4, u16 *, 0xC) & 0x400) {
        var_r5_8 = 0x7FFFFF;
        M2C_FIELD(arg0, s32 *, 0x20) = (s32) (M2C_FIELD(arg0, s32 *, 0x20) + (s16) M2C_FIELD(temp_r4, u16 *, 0x5C));
        temp_r0_8 = M2C_FIELD(arg0, s32 *, 0x20);
        if (temp_r0_8 > 0x7FFFFF) {

        } else {
            var_r5_8 = -0x7FFFFF;
            if (temp_r0_8 < 0xFF800001) {

            } else {
                var_r5_8 = temp_r0_8;
            }
        }
        M2C_FIELD(arg0, s32 *, 0x20) = var_r5_8;
    }
    if (M2C_FIELD(temp_r4, u16 *, 0xC) & 0x1000) {
        var_r4 = 0x7FFFFF;
        M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) + (s16) M2C_FIELD(temp_r4, u16 *, 0x62));
        temp_r0_9 = M2C_FIELD(arg0, s32 *, 0x24);
        if (temp_r0_9 > 0x7FFFFF) {

        } else {
            var_r4 = -0x7FFFFF;
            if (temp_r0_9 < 0xFF800001) {

            } else {
                var_r4 = temp_r0_9;
            }
        }
        M2C_FIELD(arg0, s32 *, 0x24) = var_r4;
    }
}

void fn_8025A14C(void **arr, s32 lo, s32 hi) {
    s32 mid;
    s32 store;
    s32 j;
    s32 left_hi;
    s32 right_lo;
    s32 store4;
    void **p;
    void **q;
    void **store_ptr;
    void *tmp;
    void *pivot;
    void *t;
    void **arr_save;
    s32 hi_save;

    arr_save = arr;
    hi_save = hi;
    if (lo >= hi_save) {
        return;
    }

    mid = lo + hi_save;
    mid = (s32)((u32)mid + ((u32)mid >> 31)) >> 1;
    p = &arr_save[lo];
    tmp = *p;
    *p = arr_save[mid];
    arr_save[mid] = tmp;

    store = lo;
    q = p;
    j = lo + 1;
    for (; j <= hi_save; j++) {
        t = arr_save[j];
        pivot = *p;
        if (*(u32 *)((u8 *)t + 0x1C) < *(u32 *)((u8 *)pivot + 0x1C)) {
            tmp = q[1];
            store += 1;
            q += 1;
            *q = t;
            arr_save[j] = tmp;
        }
    }

    left_hi = store - 1;
    store4 = store << 2;
    store_ptr = (void **)((u8 *)arr_save + store4);
    tmp = *p;
    *p = *store_ptr;
    *store_ptr = tmp;

    if (lo < left_hi) {
        mid = store + lo;
        mid = mid - 1;
        mid = (s32)((u32)mid + ((u32)mid >> 31)) >> 1;
        tmp = *p;
        *p = arr_save[mid];
        arr_save[mid] = tmp;

        right_lo = lo;
        q = p;
        j = lo + 1;
        for (; j <= left_hi; j++) {
            t = arr_save[j];
            pivot = *p;
            if (*(u32 *)((u8 *)t + 0x1C) < *(u32 *)((u8 *)pivot + 0x1C)) {
                tmp = q[1];
                right_lo += 1;
                q += 1;
                *q = t;
                arr_save[j] = tmp;
            }
        }

        tmp = *p;
        *p = arr_save[right_lo];
        arr_save[right_lo] = tmp;

        fn_8025A14C(arr_save, lo, right_lo - 1);
        fn_8025A14C(arr_save, right_lo + 1, store - 1);
    }

    right_lo = store + 1;
    if (right_lo < hi_save) {
        p = store_ptr;
        mid = store + hi_save;
        mid = mid + 1;
        mid = (s32)((u32)mid + ((u32)mid >> 31)) >> 1;
        tmp = p[1];
        p[1] = arr_save[mid];
        arr_save[mid] = tmp;

        q = &arr_save[right_lo];
        j = store + 2;
        for (; j <= hi_save; j++) {
            t = arr_save[j];
            pivot = p[1];
            if (*(u32 *)((u8 *)t + 0x1C) < *(u32 *)((u8 *)pivot + 0x1C)) {
                tmp = q[1];
                right_lo += 1;
                q += 1;
                *q = t;
                arr_save[j] = tmp;
            }
        }

        tmp = p[1];
        p[1] = arr_save[right_lo];
        arr_save[right_lo] = tmp;

        fn_8025A14C(arr_save, store + 1, right_lo - 1);
        fn_8025A14C(arr_save, right_lo + 1, hi_save);
    }
}

#pragma use_lmw_stmw on
void fn_8025A3A4(void *arg0, u32 arg1) {
    void fn_80259E40(void *, void *);
    void fn_8025C99C(void *, s32);
    void fn_8025CA80(void *);
    void fn_8020516C(void *, u16);
    extern u8 *gSoundAuxBuf;
    extern u32 lbl_80368A6C;
    extern u8 *lbl_80368A80;
    extern u8 *lbl_80368A78;
    extern u8 *lbl_80368A7C;
    extern u32 lbl_80368A90;
    extern u32 lbl_80368A8C;
    extern u8 gSoundStudios[];
    extern void *lbl_80368A70;
    extern u16 lbl_80368A74;
    extern u16 lbl_80368A84;
    u32 tick;
    u8 *aux;
    u8 *studio;
    void *voice;
    void *next;
    u16 pad0;
    u8 studioIdx;
    u8 *studioBase;
    void *saved;
    u32 tmp;
    u32 len;

    saved = arg0;
    aux = gSoundAuxBuf;
    lbl_80368A6C = 0;
    lbl_80368A80 = aux;
    lbl_80368A78 = aux;
    lbl_80368A7C = aux + 0x180;
    if (arg1 < 0xC8) {
        tick = 0x28BE;
    } else {
        tmp = *(u32 *)0x800000F8;
        tmp = ((u32)(((u64)(tmp) * 0x51EB851Fu) >> 32)) >> 7;
        tmp = ((u32)(((u64)(tmp) * 0xD1B71759u) >> 32)) >> 12;
        tick = (arg1 - 0xC8) * tmp + 0x28BE;
    }
    if (lbl_80368A90 != 0) {
        tick += 0xAFC8;
    }
    if (lbl_80368A8C != 0) {
        tick += 0xBB8;
    }
    pad0 = 0;
    studioBase = gSoundStudios;
    studioIdx = 0;
    for (;;) {
        studio = studioBase + studioIdx * 0xBC;
        if (studio[0x50] != 1) {
            break;
        }
        voice = *(void **)(studio + 0x48);
        while (voice != NULL) {
            next = *(void **)((u8 *)voice + 0xC);
            if (*(u8 *)((u8 *)voice + 0xF1) == 0) {
                if ((*(u32 *)((u8 *)voice + 0x24) & 0x20) != 0) {
                    fn_80259E40(studio, voice);
                }
            } else {
                if ((u32)(*(u32 *)((u8 *)voice + 0xEC) + 0x10000) != 0xFFFFU) {
                    fn_8025C99C(voice, 3);
                }
                if (*(u8 *)((u8 *)voice + 0xF0) == 1) {
                    if (*(u8 *)((u8 *)voice + 0xF2) != 0) {
                        fn_8025CA80(voice);
                        *(u8 *)((u8 *)voice + 0xF2) = 0;
                    }
                }
            }
            voice = next;
        }
        voice = *(void **)(studio + 0x4C);
        while (voice != NULL) {
            next = *(void **)((u8 *)voice + 0x14);
            fn_80259E40(studio, voice);
            voice = next;
        }
        *(u32 *)(studio + 0x4C) = 0;
        if (lbl_80368A80 + 6 > lbl_80368A7C - 8) {
            *(u16 *)lbl_80368A80 = 0xD;
            *(u16 *)(lbl_80368A80 + 2) = (u16)((u32)lbl_80368A7C >> 16);
            *(u16 *)(lbl_80368A80 + 4) = (u16)(u32)lbl_80368A7C;
            len = (u32)(lbl_80368A80 + 8) - (u32)lbl_80368A78;
            len = (len + 3) & 0xFFFC;
            if (lbl_80368A6C != 0) {
                *(u16 *)((u8 *)lbl_80368A6C + 6) = (u16)len;
                fn_8020516C(lbl_80368A70, lbl_80368A74);
            } else {
                lbl_80368A84 = (u16)len;
            }
            lbl_80368A6C = (u32)lbl_80368A80;
            lbl_80368A74 = (u16)len;
            lbl_80368A70 = lbl_80368A78;
            lbl_80368A80 = lbl_80368A7C;
            lbl_80368A78 = lbl_80368A7C;
            lbl_80368A7C = lbl_80368A7C + 0x180;
        }
        *(u16 *)lbl_80368A80 = 0;
        *(u16 *)(lbl_80368A80 + 2) = (u16)(*(u32 *)studio >> 16);
        *(u16 *)(lbl_80368A80 + 4) = (u16)*(u32 *)studio;
        lbl_80368A80 += 6;
        tick += 0x2C62;
        studioIdx++;
        if (studioIdx > 10) {
            break;
        }
    }
    (void)saved;
    (void)pad0;
    (void)tick;
}

s32 fn_8025C99C(void *arg0, s32 arg1)
{
    extern u32 lbl_80368AA4;

    s32 (*callback)(s32, s32);

    callback = (s32 (*)(s32, s32))lbl_80368AA4;

    if (callback == 0) {
        return 0;
    }

    return callback(arg1, *(s32 *)((u8 *)arg0 + 0x18));
}

#pragma use_lmw_stmw reset
void fn_8025C9E0(void *arg0, u8 arg1)
{
    void fn_8025CA80(void);
    typedef struct SoundStudio { u8 pad[0xBC]; } SoundStudio;
    extern SoundStudio gSoundStudios[];
    u8 *base;
    void *node;

    if (((u8 *)arg0)[0xF0] != 0) {
        fn_8025CA80();
        *(u32 *)((u8 *)arg0 + 0x24) |= 0x20;
    }

    ((u8 *)arg0)[0xF1] = 0;
    base = (u8 *)&gSoundStudios[arg1];
    node = *(void **)(base += 0x48);
    *(void **)((u8 *)arg0 + 0xC) = node;
    if (node != 0) {
        *(void **)((u8 *)*(void **)((u8 *)arg0 + 0xC) + 0x10) = arg0;
    }
    *(void **)((u8 *)arg0 + 0x10) = 0;
    *(void **)base = arg0;
    ((u8 *)arg0)[0xF2] = 0;
    ((u8 *)arg0)[0xF0] = 1;
    ((u8 *)arg0)[0xF3] = arg1;
}

void fn_8025CA80(void *arg0) {
    typedef struct { u8 pad[0x48]; u32 val; u8 pad2[0xBC - 0x4C]; } SoundStudio;
    extern SoundStudio gSoundStudios[];
    void *node;

    if (*(u8 *)((u8 *)arg0 + 0xF0) != 0) {
        node = *(void **)((u8 *)arg0 + 0x10);
        if (node != NULL) {
            *(void **)((u8 *)node + 0xC) = *(void **)((u8 *)arg0 + 0xC);
        } else {
            u8 idx = *(u8 *)((u8 *)arg0 + 0xF3);
            gSoundStudios[idx].val = *(u32 *)((u8 *)arg0 + 0xC);
        }
        node = *(void **)((u8 *)arg0 + 0xC);
        if (node != NULL) {
            *(void **)((u8 *)node + 0x10) = *(void **)((u8 *)arg0 + 0x10);
        }
        *(u8 *)((u8 *)arg0 + 0xF0) = 0;
    }
}

void fn_8025CAE0(void) {
  extern u8 gSoundStudios[];
  extern u8 gSoundStudioCount;
  extern u8 lbl_80368AD3;
  void DCFlushRangeNoSync(void *, u32);

  u8 i;
  u8 *studio;
  void *bufs[3];
  void *buf;
  void (*cb)(s32, void **, s32, s32, s32);
  s32 idx;

  i = 0;
  studio = gSoundStudios;
  while (i < gSoundStudioCount) {
    if (studio[0x50] == 1) {
      cb = *(void (**)(s32, void **, s32, s32, s32))(studio + 0xAC);
      if (cb != NULL) {
        idx = (lbl_80368AD3 + 2) % 3;
        buf = *(void **)(studio + 0x30 + idx * 4);
        bufs[0] = buf;
        bufs[1] = (u8 *)buf + 0x280;
        bufs[2] = (u8 *)buf + 0x500;
        cb(0, bufs, *(s32 *)(studio + 0xB4), (s32)((u8 *)buf + 0x280),
           lbl_80368AD3 + 2);
        DCFlushRangeNoSync(buf, 0x780);
      }
      if (*(s32 *)(studio + 0x54) == 0) {
        cb = *(void (**)(s32, void **, s32, s32, s32))(studio + 0xB0);
        if (cb != NULL) {
          idx = (lbl_80368AD3 + 2) % 3;
          buf = *(void **)(studio + 0x3C + idx * 4);
          bufs[0] = buf;
          bufs[1] = (u8 *)buf + 0x280;
          bufs[2] = (u8 *)buf + 0x500;
          cb(0, bufs, *(s32 *)(studio + 0xB8), (s32)((u8 *)buf + 0x280),
             lbl_80368AD3 + 2);
          DCFlushRangeNoSync(buf, 0x780);
        }
      }
    }
    i += 1;
    studio += 0xBC;
  }
}

f64 fn_802387A8(f64, f64);
#pragma fp_contract off
void fn_8025CC38(u8 arg0, f32 *out, u32 arg2, u32 arg3, u32 arg4, u32 arg5, f32 fx, f32 fy, f32 fz) {
    extern f32 gSoundVolCurve[];
    extern f32 lbl_802A1BD8[];
    extern f32 lbl_8036C2A8;
    extern f32 lbl_8036C2AC;
    extern f32 lbl_8036C2B0;
    extern f32 lbl_8036C2C0;
    extern f64 lbl_8036C2C8;
    extern f32 lbl_8036C2D0;
    extern f32 lbl_8036C2D4;
    extern f32 lbl_8036C2D8;
    f32 *tbl;
    f32 *base;
    f32 f24, f20;
    f32 f26, f25, f30, f29, f28, f27, f23;
    f32 f31v, f21v, f22v;
    s32 r29, r28, r22, r23, r24, r26i;
    f32 *t204;
    f32 *t208;
    f32 *t214;
    s32 idx;
    f32 t, a, b, c, d, e, u, v;
    u32 xa, xb;

    tbl = gSoundVolCurve;
    f22v = fx;
    f31v = fy;
    f21v = fz;
    base = lbl_802A1BD8;
    if (arg0 == 0) {
        tbl = base;
    }
    if (arg2 == 0x80000000) {
        arg2 = 0;
        arg3 = 0x7F0000;
    }
    xa = (arg2 < 0x10000U) ? 0 : (arg2 - 0x10000U);
    xb = (arg3 < 0x10000U) ? 0 : (arg3 - 0x10000U);
    f24 = lbl_8036C2C0 * (f32)xa;
    f20 = lbl_8036C2C0 * (f32)xb;

    f26 = 0.0f;
    f25 = 0.0f;
    r29 = 0;
    r28 = 0;
    if (arg5 != 0) {
        f26 = (f32)fn_802387A8(f24, lbl_8036C2C8);
        r29 = __cvt_fp2unsigned(f24);
        f23 = lbl_8036C2D0 - f24;
        f25 = (f32)fn_802387A8(f23, lbl_8036C2C8);
        r28 = __cvt_fp2unsigned(f23);
    }
    if (arg4 != 0) {
        f24 = lbl_8036C2AC + (lbl_8036C2D4 * (f24 - lbl_8036C2AC));
    }
    f30 = (f32)fn_802387A8(f24, lbl_8036C2C8);
    r22 = __cvt_fp2unsigned(f24);
    f29 = (f32)fn_802387A8(f20, lbl_8036C2C8);
    r23 = __cvt_fp2unsigned(f20);
    f23 = lbl_8036C2D0 - f24;
    f20 = lbl_8036C2D0 - f20;
    f28 = (f32)fn_802387A8(f23, lbl_8036C2C8);
    r24 = __cvt_fp2unsigned(f23);
    f27 = (f32)fn_802387A8(f20, lbl_8036C2C8);
    r26i = __cvt_fp2unsigned(f20);

    if (arg5 == 0) {
        f20 = lbl_8036C2A8 * f22v;
        idx = __cvt_fp2unsigned(f20);
        t204 = base + (0x204 / 4);
        t208 = t204 + 1;
        f26 = lbl_8036C2AC - f29;
        t = f20 - (f32)(u32)idx;
        u = (lbl_8036C2AC - t) * tbl[idx];
        v = t * tbl[idx + 1];
        a = u + v;
        f25 = lbl_8036C2A8 * f31v;
        f31v = lbl_8036C2AC - f27;
        f24 = lbl_8036C2AC - f30;
        f23 = lbl_8036C2AC - f28;
        u = f26 * t204[r23];
        v = f29 * t208[r23];
        b = u + v;
        out[2] = lbl_8036C2B0 * (a * b);
        u = f31v * t204[r26i];
        v = f27 * t208[r26i];
        c = u + v;
        a = a * c;
        u = f24 * t204[r22];
        v = f30 * t208[r22];
        out[1] = a * (u + v);
        u = f23 * t204[r24];
        v = f28 * t208[r24];
        out[0] = a * (u + v);

        idx = __cvt_fp2unsigned(f25);
        f22v = lbl_8036C2A8 * f21v;
        t = f25 - (f32)(u32)idx;
        u = (lbl_8036C2AC - t) * tbl[idx];
        v = t * tbl[idx + 1];
        a = u + v;
        u = f26 * t204[r23];
        v = f29 * t208[r23];
        out[5] = lbl_8036C2B0 * (a * (u + v));
        u = f31v * t204[r26i];
        v = f27 * t208[r26i];
        a = a * (u + v);
        u = f24 * t204[r22];
        v = f30 * t208[r22];
        out[4] = a * (u + v);
        u = f23 * t204[r24];
        v = f28 * t208[r24];
        out[3] = a * (u + v);

        idx = __cvt_fp2unsigned(f22v);
        t = f22v - (f32)(u32)idx;
        u = (lbl_8036C2AC - t) * tbl[idx];
        v = t * tbl[idx + 1];
        a = u + v;
        u = f26 * t204[r23];
        v = f29 * t208[r23];
        out[8] = lbl_8036C2B0 * (a * (u + v));
        u = f31v * t204[r26i];
        v = f27 * t208[r26i];
        a = a * (u + v);
        u = f24 * t204[r22];
        v = f30 * t208[r22];
        out[7] = a * (u + v);
        u = f23 * t204[r24];
        v = f28 * t208[r24];
        out[6] = a * (u + v);
    } else {
        f20 = lbl_8036C2A8 * f22v;
        idx = __cvt_fp2unsigned(f20);
        t204 = base + (0x204 / 4);
        t208 = t204 + 1;
        t214 = base + (0x214 / 4);
        f23 = lbl_8036C2AC - f29;
        f24 = lbl_8036C2AC - f27;
        t = f20 - (f32)(u32)idx;
        u = (lbl_8036C2AC - t) * tbl[idx];
        v = t * tbl[idx + 1];
        a = u + v;
        f21v = lbl_8036C2AC - f30;
        u = f23 * t204[r23];
        v = f29 * t208[r23];
        b = u + v;
        c = a * b;
        u = f24 * t204[r26i];
        v = f27 * t208[r26i];
        d = a * (u + v);
        e = lbl_8036C2AC - f28;
        f22v = lbl_8036C2A8 * f31v;
        u = f21v * t204[r22];
        v = f30 * t208[r22];
        out[1] = d * (u + v);
        u = e * t204[r24];
        v = f28 * t208[r24];
        out[0] = d * (u + v);
        u = (lbl_8036C2AC - f26) * t214[r29];
        v = f26 * t208[r29];
        out[7] = c * (u + v);
        u = (lbl_8036C2AC - f25) * t214[r28];
        v = f25 * t208[r28];
        out[6] = c * (u + v);

        idx = __cvt_fp2unsigned(f22v);
        t = f22v - (f32)(u32)idx;
        u = (lbl_8036C2AC - t) * tbl[idx];
        v = t * tbl[idx + 1];
        a = u + v;
        u = f23 * t204[r23];
        v = f29 * t208[r23];
        out[5] = lbl_8036C2B0 * (a * (u + v));
        u = f24 * t204[r26i];
        v = f27 * t208[r26i];
        a = a * (u + v);
        u = f21v * t204[r22];
        v = f30 * t208[r22];
        out[4] = a * (u + v);
        u = e * t204[r24];
        v = f28 * t208[r24];
        out[3] = a * (u + v);
        out[2] = lbl_8036C2D8;
        out[8] = lbl_8036C2D8;
    }
}
#pragma fp_contract on
void fn_8025D328(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6) {
    extern f32 lbl_8036C2E0;
    extern f32 lbl_8036C2E4;
    extern f64 lbl_8036C2E8;
    extern f64 lbl_8036C2F0;
    extern f32 lbl_8036C2F8;
    extern f32 lbl_8036C2FC;
    extern f32 lbl_8036C300;
    extern f32 lbl_8036C304;
    extern void *lbl_80368AB8;
    extern void (*lbl_80368AA8)(void *, void *, void *, void *, void *, void *, f32 *, f32 *);
    extern u8 lbl_80368AAF;
    void fn_8025ED88(void *, void *, f32 *);
    void fn_8025EE34(f32 *);
    f64 __frsqrte(f64);

    f32 sp1C;
    f32 sp20;
    f32 sp24;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f31;
    f32 var_f29;
    f32 var_f25;
    f32 var_f26;
    f32 var_f28;
    f32 var_f27;
    f32 var_f30;
    f32 var_f24;
    f32 temp_f6;
    f32 temp_f4;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f0;
    f32 temp_f5;
    f32 temp_f8;
    f32 temp_f1;
    f32 var_f0;
    f32 var_f1;
    f32 var_f5;
    f64 temp_f1d;
    f64 temp_f1d2;
    f64 temp_f1d3;
    u32 var_r30;
    void *var_r31;
    s32 temp_r3;

    temp_f31 = lbl_8036C2E0;
    *arg1 = temp_f31;
    var_f29 = temp_f31;
    var_f25 = lbl_8036C2E4;
    *arg2 = lbl_8036C2E4;
    var_f26 = lbl_8036C2E4;
    var_f28 = temp_f31;
    var_f27 = temp_f31;
    var_r31 = lbl_80368AB8;
    var_r30 = 0;
    while (var_r31 != NULL) {
        temp_f6 = *(f32 *)((u8 *)var_r31 + 0x18);
        temp_f4 = *(f32 *)((u8 *)arg0 + 0x10) - (*(f32 *)((u8 *)var_r31 + 0xC) + (*(f32 *)((u8 *)var_r31 + 0x28) * temp_f6));
        temp_f2 = *(f32 *)((u8 *)arg0 + 0x14) - (*(f32 *)((u8 *)var_r31 + 0x10) + (*(f32 *)((u8 *)var_r31 + 0x2C) * temp_f6));
        temp_f3 = *(f32 *)((u8 *)arg0 + 0x18) - (*(f32 *)((u8 *)var_r31 + 0x14) + (*(f32 *)((u8 *)var_r31 + 0x30) * temp_f6));
        var_f30 = (temp_f3 * temp_f3) + ((temp_f4 * temp_f4) + (temp_f2 * temp_f2));
        if (var_f30 > temp_f31) {
            temp_f1d = __frsqrte(var_f30);
            temp_f1d2 = lbl_8036C2E8 * temp_f1d * (lbl_8036C2F0 - ((f64)var_f30 * (temp_f1d * temp_f1d)));
            temp_f1d3 = lbl_8036C2E8 * temp_f1d2 * (lbl_8036C2F0 - ((f64)var_f30 * (temp_f1d2 * temp_f1d2)));
            sp10 = (f32)((f64)var_f30 * (lbl_8036C2E8 * temp_f1d3 * (lbl_8036C2F0 - ((f64)var_f30 * (temp_f1d3 * temp_f1d3)))));
            var_f30 = sp10;
        }
        temp_f0 = *(f32 *)((u8 *)arg0 + 0x28);
        if (temp_f0 >= var_f30) {
            temp_f8 = var_f30 / temp_f0;
            temp_f5 = *(f32 *)((u8 *)arg0 + 0x34);
            if (temp_f5 >= lbl_8036C2E0) {
                temp_f6 = *(f32 *)((u8 *)arg0 + 0x30);
                var_f24 = *(f32 *)((u8 *)var_r31 + 0x88) * (temp_f6 + ((*(f32 *)((u8 *)arg0 + 0x2C) - temp_f6) * (lbl_8036C2E4 - (((lbl_8036C2E4 - temp_f5) * temp_f8) + (temp_f8 * (temp_f5 * temp_f8))))));
            } else {
                temp_f7:
                ;
                {
                    f32 temp_f7 = *(f32 *)((u8 *)arg0 + 0x30);
                    f32 temp_f6b = lbl_8036C2E4 - temp_f8;
                    var_f24 = *(f32 *)((u8 *)var_r31 + 0x88) * (temp_f7 + ((*(f32 *)((u8 *)arg0 + 0x2C) - temp_f7) * (lbl_8036C2E4 - (((lbl_8036C2E4 + temp_f5) * temp_f8) - (temp_f5 * (lbl_8036C2E4 - (temp_f6b * temp_f6b)))))));
                }
            }
            if ((*(u32 *)((u8 *)arg0 + 0xC) & 0x180) && lbl_80368AA8 != NULL) {
                lbl_80368AA8(arg0, (u8 *)var_r31 + 0xC, (u8 *)var_r31 + 0x28, (u8 *)var_r31 + 0x40, (u8 *)arg0 + 0x10, (u8 *)arg0 + 0x1C, &sp14, &sp18);
                var_f24 *= lbl_8036C2E4 - sp14;
            } else {
                sp18 = lbl_8036C2E0;
            }
            if (lbl_80368AAF != 0) {
                *arg1 += var_f24;
            } else if (*arg1 < var_f24) {
                *arg1 = var_f24;
            }
            temp_r3 = *(s32 *)((u8 *)arg0 + 0xC);
            if (!(temp_r3 & 0x80000)) {
                if ((temp_r3 & 8) || (*(u32 *)((u8 *)var_r31 + 8) & 1)) {
                    temp_f2 = *(f32 *)((u8 *)var_r31 + 0x1C) - *(f32 *)((u8 *)arg0 + 0x1C);
                    temp_f4 = *(f32 *)((u8 *)var_r31 + 0x20) - *(f32 *)((u8 *)arg0 + 0x20);
                    temp_f3 = *(f32 *)((u8 *)var_r31 + 0x24) - *(f32 *)((u8 *)arg0 + 0x24);
                    var_f1 = (temp_f3 * temp_f3) + ((temp_f2 * temp_f2) + (temp_f4 * temp_f4));
                    if (var_f1 > lbl_8036C2E0) {
                        temp_f1d = __frsqrte(var_f1);
                        temp_f1d2 = lbl_8036C2E8 * temp_f1d * (lbl_8036C2F0 - ((f64)var_f1 * (temp_f1d * temp_f1d)));
                        temp_f1d3 = lbl_8036C2E8 * temp_f1d2 * (lbl_8036C2F0 - ((f64)var_f1 * (temp_f1d2 * temp_f1d2)));
                        spC = (f32)((f64)var_f1 * (lbl_8036C2E8 * temp_f1d3 * (lbl_8036C2F0 - ((f64)var_f1 * (temp_f1d3 * temp_f1d3)))));
                        var_f1 = spC;
                    }
                    if (var_f1 > lbl_8036C2E0) {
                        temp_f8 = (*(f32 *)((u8 *)arg0 + 0x10) + (*(f32 *)((u8 *)arg0 + 0x1C) * lbl_8036C2F8)) - (*(f32 *)((u8 *)var_r31 + 0xC) + (*(f32 *)((u8 *)var_r31 + 0x1C) * lbl_8036C2F8));
                        temp_f6 = (*(f32 *)((u8 *)arg0 + 0x14) + (*(f32 *)((u8 *)arg0 + 0x20) * lbl_8036C2F8)) - (*(f32 *)((u8 *)var_r31 + 0x10) + (*(f32 *)((u8 *)var_r31 + 0x20) * lbl_8036C2F8));
                        temp_f4 = (*(f32 *)((u8 *)arg0 + 0x18) + (*(f32 *)((u8 *)arg0 + 0x24) * lbl_8036C2F8)) - (*(f32 *)((u8 *)var_r31 + 0x14) + (*(f32 *)((u8 *)var_r31 + 0x24) * lbl_8036C2F8));
                        var_f5 = (temp_f4 * temp_f4) + ((temp_f8 * temp_f8) + (temp_f6 * temp_f6));
                        if (var_f5 > lbl_8036C2E0) {
                            temp_f1d = __frsqrte(var_f5);
                            temp_f1d2 = lbl_8036C2E8 * temp_f1d * (lbl_8036C2F0 - ((f64)var_f5 * (temp_f1d * temp_f1d)));
                            temp_f1d3 = lbl_8036C2E8 * temp_f1d2 * (lbl_8036C2F0 - ((f64)var_f5 * (temp_f1d2 * temp_f1d2)));
                            sp8 = (f32)((f64)var_f5 * (lbl_8036C2E8 * temp_f1d3 * (lbl_8036C2F0 - ((f64)var_f5 * (temp_f1d3 * temp_f1d3)))));
                            var_f5 = sp8;
                        }
                        if (var_f5 < var_f30) {
                            temp_f2 = *(f32 *)((u8 *)var_r31 + 0x84);
                            temp_f1 = temp_f2 - var_f1;
                            if (temp_f1 >= lbl_8036C2FC) {
                                *arg2 = temp_f2 / temp_f1;
                            } else {
                                *arg2 = lbl_8036C300 * temp_f2;
                            }
                        } else {
                            temp_f2 = *(f32 *)((u8 *)var_r31 + 0x84);
                            *arg2 = temp_f2 / (temp_f2 + var_f1);
                        }
                    }
                }
                if (lbl_8036C2E0 != var_f30) {
                    fn_8025ED88((u8 *)var_r31 + 0x4C, (u8 *)arg0 + 0x10, &sp1C);
                    if (sp24 <= lbl_8036C2E0) {
                        temp_f1 = *(f32 *)((u8 *)var_r31 + 0x7C);
                        if (-temp_f1 < sp24) {
                            var_f0 = -sp24 / temp_f1;
                        } else {
                            var_f0 = lbl_8036C2E4;
                        }
                        var_f29 += var_f0;
                    } else {
                        temp_f1 = *(f32 *)((u8 *)var_r31 + 0x80);
                        if (temp_f1 > sp24) {
                            var_f0 = -sp24 / temp_f1;
                        } else {
                            var_f0 = lbl_8036C304;
                        }
                        var_f29 += var_f0;
                    }
                    if ((lbl_8036C2E0 != sp1C) || (lbl_8036C2E0 != sp20) || (lbl_8036C2E0 != sp24)) {
                        fn_8025EE34(&sp1C);
                    }
                    var_f27 += sp1C;
                    var_f28 -= sp20;
                    if ((*(u32 *)((u8 *)arg0 + 0xC) & 0x80) && (var_f25 > lbl_8036C2E0)) {
                        var_f25 = lbl_8036C2E0;
                    }
                    if (var_f26 > sp18) {
                        var_f26 = sp18;
                    }
                } else {
                    *arg6 = lbl_8036C2E0;
                }
            }
        }
        var_r31 = *(void **)var_r31;
        var_r30 += 1;
    }
    if (var_r30 != 0) {
        *arg3 = var_f27 / (f32)var_r30;
        *arg4 = var_f28 / (f32)var_r30;
        *arg5 = var_f29 / (f32)var_r30;
    }
    temp_r3 = *(s32 *)((u8 *)arg0 + 0xC);
    if (temp_r3 & 0x80) {
        if (temp_r3 & 0x100) {
            if (var_f25 < var_f26) {
                var_f0 = var_f26;
            } else {
                var_f0 = var_f25;
            }
            *arg6 = var_f0;
        } else {
            *arg6 = var_f25;
        }
    } else if (temp_r3 & 0x100) {
        *arg6 = var_f26;
    } else {
        *arg6 = lbl_8036C2E0;
    }
}
#pragma optimization_level 3
void fn_8025D9A4(u16 *arg0, u32 arg1)
{
    extern void *lbl_80368ABC;
    extern u8 gSoundReady;

    void Audio_Lock(void);
    void Audio_Unlock(void);
    void fn_8024A6F8(u32);

    u8 *next;
    u8 *current;
    u16 *p;
    u32 i;

    current = lbl_80368ABC;
    while (current != 0) {
        next = *(u8 **)current;
        p = arg0;

        for (i = 0; i < arg1; i++) {
            if (*(u16 *)(current + 0x40) == *p) {
                if (gSoundReady != 0) {
                    Audio_Lock();
                    if (*(u32 *)(current + 0xC) & 0x10000) {
                        if (*(void **)current != 0) {
                            *(void **)((u8 *)*(void **)current + 4) = *(void **)(current + 4);
                        }
                        if (*(void **)(current + 4) != 0) {
                            *(void **)*(void **)(current + 4) = *(void **)current;
                        } else {
                            lbl_80368ABC = *(void **)current;
                        }
                        *(u32 *)(current + 0xC) &= 0xFFFF;
                        {
                            u32 handle = *(u32 *)(current + 0x38);
                            if (handle + 0x10000 != 0xFFFF) {
                                fn_8024A6F8(handle);
                            }
                        }
                    }
                    Audio_Unlock();
                }
                break;
            }
            p = (u16 *)((u8 *)p + 0xa);
        }
        current = next;
    }
}
#pragma optimization_level reset
s32 fn_8025DAA0(
    void *arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    f32 arg5,
    f32 arg6)
{
    typedef struct { u32 key; u32 next; u32 f8; u16 count; u16 pad; } Entry;
    typedef struct { u32 next; f32 v1; f32 v2; f32 v3; f32 v4; f32 v5; f32 v6; void *arg0; } Node;
    extern u8 lbl_80368AAD;

    u8 count;
    s32 index;
    Entry *base;
    u8 **next;
    u8 *current;
    u8 *previous;
    u8 nodeIndex;
    Node *node;

    count = lbl_80368AAE;
    index = 0;
    base = (Entry *)lbl_8035BF18;

    for (; index < (s32)count; index++) {
        if (*(u32 *)((u8 *)arg0 + 0x3C) == base[index].key) {
            break;
        }
    }

    if (index == (s32)count) {
        if (count == 0x40) {
            return 0;
        }

        base = (Entry *)lbl_8035BF18;
        base[index].next = 0;
        base[index].f8 = 0;
        base[index].count = 0;
        *(u32 *)((u8 *)base + (index << 4)) = *(u32 *)((u8 *)arg0 + 0x3C);

        lbl_80368AAE = lbl_80368AAE + 1;
    }

    nodeIndex = lbl_80368AAD;

    if (nodeIndex == 0x40) {
        return 0;
    }

    base = (Entry *)lbl_8035BF18;
    next = (u8 **)(base + index);
    current = *++next;
    previous = current;

    if (current != 0) {
        goto check;
        do {
            if (*(f32 *)((u8 *)previous + 4) < arg1) {
                break;
            }
            previous = current;
        check:
            current = *(u8 **)previous;
        } while (current != 0);

        node = (Node *)((u8 *)lbl_8035C918 + ((u8)nodeIndex << 5));
        node->next = (u32)current;
        *(u8 **)previous = (u8 *)node;
    } else {
        node = (Node *)((u8 *)lbl_8035C918 + ((u8)nodeIndex << 5));
        node->next = (u32)current;
        *next = (u8 *)node;
    }

    nodeIndex = lbl_80368AAD;
    node = (Node *)((u8 *)lbl_8035C918 + (nodeIndex << 5));
    node->arg0 = arg0;
    node->v5 = arg5;
    node->v6 = arg6;
    node->v2 = arg2;
    node->v3 = arg3;
    node->v4 = arg4;
    lbl_80368AAD = nodeIndex + 1;
    ((Node *)lbl_8035C918)[(u8)nodeIndex].v1 = arg1;

    return 1;
}

void fn_8025DBF4(void) {
    s32 Sound_Start(u16, u8, s32, s32, u8, s32);
    s32 fn_8024A430(u16);
    void Sound_SetParamU8(s32, s32, s32);
    void Sound_SetParamU16(s32, s32, s32);
    void fn_80257224(s32);
    extern u16 lbl_8035BF18[];
    extern u8 lbl_8035C318[];
    extern u8 lbl_80368AAC;
    extern u8 lbl_80368AAE;
    extern u8 lbl_80368AAF;
    extern u8 lbl_80368AB0;
    extern f32 lbl_8036C2E0;
    extern f32 lbl_8036C2E4;
    extern f32 lbl_8036C310;
    extern f32 lbl_8036C314;
    extern f32 lbl_8036C318;
    extern f32 lbl_8036C31C;
    extern f32 lbl_8036C320;
    extern f32 lbl_8036C324;

    u8 *entry;
    u8 *p_list;
    u8 *p_head;
    u8 *p_count;
    u8 *node;
    u8 *other;
    u8 *voice;
    u8 *cmd;
    u8 *list;
    u8 *cur;
    u8 *slot;
    f32 fpan;
    f32 fspan;
    f32 fvar;
    f32 ftime;
    f32 fvol;
    f32 dt;
    f32 ft;
    s32 handle;
    s32 i;
    s32 v;
    s32 tmp;
    u8 vel;
    u8 n;
    u16 w;
    u32 flags;

    if (lbl_80368AAF != 0) {
        i = 0;
        entry = (u8 *)lbl_8035BF18;
        while (i < (s32)lbl_80368AAE) {
            node = *(u8 **)(entry + 4);
            p_list = entry + 8;
            p_head = entry + 4;
            p_count = entry + 0xC;
            while (node != NULL) {
                other = *(u8 **)p_list;
                if (other != NULL && (lbl_80368AB0 == 0 || !(*(u32 *)entry & 0x80000000) ||
                    (s32)*(u16 *)p_count >= (s32)*(*(u8 **)(*(u8 **)p_head + 0x1C) + 0x43))) {
                    dt = *(f32 *)(node + 4) - *(f32 *)(other + 4);
                    if (!(dt <= lbl_8036C320)) {
                        if (dt <= lbl_8036C324) {
                            voice = *(u8 **)(node + 0x1C);
                            tmp = *(u16 *)(voice + 0x44) + 1;
                            *(u16 *)(voice + 0x44) = tmp;
                            if ((u16)tmp < 0x14) {
                                goto next1;
                            }
                        } else {
                            *(u16 *)(*(u8 **)(node + 0x1C) + 0x44) = 0;
                        }
                    } else {
                        goto next1;
                    }
                }
                voice = *(u8 **)(node + 0x1C);
                list = *(u8 **)(voice + 8);
                if (list == NULL) {
                    vel = 0xFF;
                } else {
                    cmd = *(u8 **)(list + 4);
                    n = 0;
                    vel = 0xFF;
                    while (n < *list) {
                        if (*(u16 *)cmd == 0x8000) {
                            vel = cmd[2];
                            break;
                        }
                        cmd += 4;
                        n++;
                    }
                }
                handle = Sound_Start(*(u16 *)(voice + 0x40), vel, 0x7F, 0x40, *(u8 *)(voice + 0x42),
                                     (*(u32 *)(voice + 0xC) >> 4) & 1);
                *(s32 *)(voice + 0x38) = handle;
                if (handle == -1) {
                    flags = *(u32 *)(voice + 0xC);
                    if (!(flags & 2)) {
                        *(u32 *)(voice + 0xC) = flags | 0x40000;
                        *(u32 *)(voice + 0xC) = *(u32 *)(voice + 0xC) & ~0x20000;
                    }
                } else {
                    flags = *(u32 *)(voice + 0xC);
                    if (!(flags & 0x20)) {
                        *(u32 *)(voice + 0xC) = flags | 0x100000;
                        *(f32 *)(voice + 0x48) = lbl_8036C2E0;
                    } else {
                        *(f32 *)(voice + 0x48) = lbl_8036C2E4;
                    }
                    ftime = *(f32 *)(node + 0x18);
                    fvar = *(f32 *)(node + 0x14);
                    fspan = *(f32 *)(node + 0x10);
                    fpan = *(f32 *)(node + 8);
                    fvol = *(f32 *)(node + 4);
                    handle = *(s32 *)(voice + 0x38);
                    if (*(u32 *)(voice + 0xC) & 0x100000) {
                        v = 0x7F;
                        tmp = (s32)(lbl_8036C314 * (*(f32 *)(voice + 0x48) * fvol));
                        if ((u8)tmp <= 0x7F) {
                            v = tmp;
                        }
                        Sound_SetParamU8(handle, 7, v);
                    } else {
                        v = 0x7F;
                        ft = lbl_8036C314 * fvol;
                        tmp = (s32)ft;
                        if ((u8)tmp <= 0x7F) {
                            v = tmp;
                        }
                        Sound_SetParamU8(handle, 7, v);
                    }
                    v = 0x7F;
                    ft = lbl_8036C318 * (lbl_8036C2E4 + fpan);
                    tmp = (s32)ft;
                    if ((u8)tmp <= 0x7F) {
                        v = tmp;
                    }
                    Sound_SetParamU8(handle, 0xA, v);
                    v = 0x7F;
                    ft = lbl_8036C318 * (lbl_8036C2E4 - fspan);
                    tmp = (s32)ft;
                    if ((u8)tmp <= 0x7F) {
                        v = tmp;
                    }
                    Sound_SetParamU8(handle, 0x83, v);
                    ft = lbl_8036C31C * fvar;
                    if (ft > lbl_8036C310) {
                        v = 0x3FFF;
                    } else {
                        v = (s32)ft;
                    }
                    Sound_SetParamU16(handle, 0x84, v);
                    if (*(u32 *)(voice + 0xC) & 0x180) {
                        if (lbl_8036C2E0 != ftime) {
                            ft = lbl_8036C310 * ftime;
                            if (ft > lbl_8036C310) {
                                v = 0x3FFF;
                            } else {
                                v = (s32)ft;
                            }
                            Sound_SetParamU16(handle, 0x1F, v);
                            Sound_SetParamU8(handle, 0x4F, 0x7F);
                        } else {
                            Sound_SetParamU8(handle, 0x4F, 0);
                        }
                    }
                    list = *(u8 **)(voice + 8);
                    if (list != NULL) {
                        cmd = *(u8 **)(list + 4);
                        n = 0;
                        while (n < *(u8 *)list) {
                            w = *(u16 *)cmd;
                            if (!(w & 0xFF00)) {
                                if (w < 0x40 || w == 0x80 || w == 0x84) {
                                    Sound_SetParamU16(handle, (u8)w, *(u16 *)(cmd + 2));
                                } else {
                                    Sound_SetParamU8(handle, (u8)w, cmd[2]);
                                }
                            }
                            cmd += 4;
                            n++;
                            list = *(u8 **)(voice + 8);
                        }
                    }
                    *(u32 *)(voice + 0xC) = *(u32 *)(voice + 0xC) & ~0x20000;
                    *(u16 *)p_count = *(u16 *)p_count + 1;
                    other = *(u8 **)p_list;
                    if (other != NULL) {
                        *(u8 **)p_list = *(u8 **)other;
                    }
                }
            next1:
                node = *(u8 **)node;
            }
            entry += 0x10;
            i++;
        }
        return;
    }

    i = 0;
    entry = (u8 *)lbl_8035BF18;
    while (i < (s32)lbl_80368AAE) {
        node = *(u8 **)(entry + 4);
        p_list = entry + 8;
        p_head = entry + 4;
        p_count = entry + 0xC;
        while (node != NULL) {
            if (*(u8 **)p_list != NULL &&
                (lbl_80368AB0 == 0 || fn_8024A430(*(u16 *)(*(u8 **)(*(u8 **)p_head + 0x1C) + 0x40)) != 0)) {
                other = *(u8 **)p_list;
                dt = *(f32 *)(node + 4) - *(f32 *)(other + 4);
                if (!(dt <= lbl_8036C320)) {
                    if (dt <= lbl_8036C324) {
                        voice = *(u8 **)(node + 0x1C);
                        tmp = *(u16 *)(voice + 0x44) + 1;
                        *(u16 *)(voice + 0x44) = tmp;
                        if ((u16)tmp < 0x14) {
                            goto next2;
                        }
                    } else {
                        *(u16 *)(*(u8 **)(node + 0x1C) + 0x44) = 0;
                    }
                    other = *(u8 **)p_list;
                    fn_80257224(*(s32 *)(*(u8 **)(other + 8) + 0x38));
                    *(u8 **)p_list = *(u8 **)other;
                    *(u16 *)p_count = *(u16 *)p_count - 1;
                } else {
                    goto next2;
                }
            }
            voice = *(u8 **)(node + 0x1C);
            list = *(u8 **)(voice + 8);
            if (list == NULL) {
                vel = 0xFF;
            } else {
                cmd = *(u8 **)(list + 4);
                n = 0;
                vel = 0xFF;
                while (n < *list) {
                    if (*(u16 *)cmd == 0x8000) {
                        vel = cmd[2];
                        break;
                    }
                    cmd += 4;
                    n++;
                }
            }
            handle = Sound_Start(*(u16 *)(voice + 0x40), vel, 0x7F, 0x40, *(u8 *)(voice + 0x42),
                                 (*(u32 *)(voice + 0xC) >> 4) & 1);
            *(s32 *)(voice + 0x38) = handle;
            if (handle == -1) {
                flags = *(u32 *)(voice + 0xC);
                if (!(flags & 2)) {
                    *(u32 *)(voice + 0xC) = flags | 0x40000;
                    *(u32 *)(voice + 0xC) = *(u32 *)(voice + 0xC) & ~0x20000;
                }
            } else {
                flags = *(u32 *)(voice + 0xC);
                if (!(flags & 0x20)) {
                    *(u32 *)(voice + 0xC) = flags | 0x100000;
                    *(f32 *)(voice + 0x48) = lbl_8036C2E0;
                } else {
                    *(f32 *)(voice + 0x48) = lbl_8036C2E4;
                }
                ftime = *(f32 *)(node + 0x18);
                fvar = *(f32 *)(node + 0x14);
                fspan = *(f32 *)(node + 0x10);
                fpan = *(f32 *)(node + 8);
                fvol = *(f32 *)(node + 4);
                handle = *(s32 *)(voice + 0x38);
                if (*(u32 *)(voice + 0xC) & 0x100000) {
                    v = 0x7F;
                    tmp = (s32)(lbl_8036C314 * (*(f32 *)(voice + 0x48) * fvol));
                    if ((u8)tmp <= 0x7F) {
                        v = tmp;
                    }
                    Sound_SetParamU8(handle, 7, v);
                } else {
                    v = 0x7F;
                    ft = lbl_8036C314 * fvol;
                    tmp = (s32)ft;
                    if ((u8)tmp <= 0x7F) {
                        v = tmp;
                    }
                    Sound_SetParamU8(handle, 7, v);
                }
                v = 0x7F;
                ft = lbl_8036C318 * (lbl_8036C2E4 + fpan);
                tmp = (s32)ft;
                if ((u8)tmp <= 0x7F) {
                    v = tmp;
                }
                Sound_SetParamU8(handle, 0xA, v);
                v = 0x7F;
                ft = lbl_8036C318 * (lbl_8036C2E4 - fspan);
                tmp = (s32)ft;
                if ((u8)tmp <= 0x7F) {
                    v = tmp;
                }
                Sound_SetParamU8(handle, 0x83, v);
                ft = lbl_8036C31C * fvar;
                if (ft > lbl_8036C310) {
                    v = 0x3FFF;
                } else {
                    v = (s32)ft;
                }
                Sound_SetParamU16(handle, 0x84, v);
                if (*(u32 *)(voice + 0xC) & 0x180) {
                    if (lbl_8036C2E0 != ftime) {
                        ft = lbl_8036C310 * ftime;
                        if (ft > lbl_8036C310) {
                            v = 0x3FFF;
                        } else {
                            v = (s32)ft;
                        }
                        Sound_SetParamU16(handle, 0x1F, v);
                        Sound_SetParamU8(handle, 0x4F, 0x7F);
                    } else {
                        Sound_SetParamU8(handle, 0x4F, 0);
                    }
                }
                list = *(u8 **)(voice + 8);
                if (list != NULL) {
                    cmd = *(u8 **)(list + 4);
                    n = 0;
                    while (n < *(u8 *)list) {
                        w = *(u16 *)cmd;
                        if (!(w & 0xFF00)) {
                            if (w < 0x40 || w == 0x80 || w == 0x84) {
                                Sound_SetParamU16(handle, (u8)w, *(u16 *)(cmd + 2));
                            } else {
                                Sound_SetParamU8(handle, (u8)w, cmd[2]);
                            }
                        }
                        cmd += 4;
                        n++;
                        list = *(u8 **)(voice + 8);
                    }
                }
                *(u32 *)(voice + 0xC) = *(u32 *)(voice + 0xC) & ~0x20000;
                cur = *(u8 **)p_list;
                while (cur != NULL) {
                    if (!(*(f32 *)(cur + 4) < *(f32 *)(node + 4))) {
                        slot = lbl_8035C318 + lbl_80368AAC * 0xC;
                        *(void **)(slot + 8) = voice;
                        *(u8 **)p_list = slot;
                        *(f32 *)(slot + 4) = *(f32 *)(node + 4);
                        *(u8 **)slot = cur;
                        *(u16 *)p_count = *(u16 *)p_count + 1;
                        lbl_80368AAC += 1;
                        break;
                    }
                    cur = *(u8 **)cur;
                }
            }
        next2:
            node = *(u8 **)node;
        }
        entry += 0x10;
        i++;
    }
}

void fn_8025E4E8(void) {
    void fn_8024A6F8(u32);
    void fn_8025D328(void *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *);
    s32 fn_8025DAA0(void *, f32, f32, f32, f32, f32, f32);
    s32 Sound_Start(u16, u8, s32, s32, u8, s32);
    s32 fn_8024B7DC(s32);
    void Sound_SetParamU8(s32, u8, u8);
    void Sound_SetParamU16(s32, u8, u16);
    void fn_8025DBF4(void);
    extern s32 lbl_80368ABC;
    extern u8 lbl_80368AC0;
    extern u8 lbl_80368AAE;
    extern u8 lbl_80368AAD;
    extern u8 lbl_80368AAC;
    extern f32 lbl_8036C2E0;
    extern f32 lbl_8036C2E4;
    extern f32 lbl_8036C310;
    extern f32 lbl_8036C314;
    extern f32 lbl_8036C318;
    extern f32 lbl_8036C31C;
    extern f32 lbl_8036C328;
    extern u16 lbl_8035BF18[];
    extern u8 lbl_8035C318[];

    f32 sp1C, sp18, sp14, sp10, spC, sp8;
    u8 *node;
    u8 *next;
    u32 flags;
    s32 handle;
    s32 i;
    s32 v;
    s32 t;
    u8 *entry;
    u8 *cur;
    u8 *prev;
    u8 *pool;
    u8 *cmd;
    u8 idx;
    u8 n;
    u8 vel;
    u16 w;
    f32 f1;

    if (lbl_80368AC0 != 0) {
        lbl_80368AC0 -= 1;
        return;
    }
    lbl_80368AC0 = 3;
    node = (u8 *)lbl_80368ABC;
    lbl_80368AAE = 0;
    lbl_80368AAD = 0;
    lbl_80368AAC = 0;

    while (node != NULL) {
        next = *(u8 **)node;
        flags = *(u32 *)(node + 0xC);

        if (flags & 0x40000) {
            if (next != NULL) {
                *(u8 **)(next + 4) = *(u8 **)(node + 4);
            }
            if (*(u8 **)(node + 4) != NULL) {
                **(u8 ***)(node + 4) = next;
            } else {
                lbl_80368ABC = (s32)next;
            }
            *(u32 *)(node + 0xC) = (u16)*(u32 *)(node + 0xC);
            handle = *(s32 *)(node + 0x38);
            if (handle != -1) {
                fn_8024A6F8(handle);
            }
        } else {
            if (flags & 0x20001) {
                fn_8025D328(node, &sp1C, &spC, &sp18, &sp14, &sp10, &sp8);
            }
            flags = *(u32 *)(node + 0xC);
            if (flags & 0x80000) {
                if (lbl_8036C2E0 != sp1C) {
                    *(u32 *)(node + 0xC) = (flags & ~0x80000) | 0x20000;
                }
            } else if (flags & 0x20000) {
                if (lbl_8036C2E0 == sp1C && (flags & 4)) {
                    *(u32 *)(node + 0xC) = (flags | 0x80000) & ~0x20000;
                    goto apply;
                }
                if (lbl_8036C2E0 == sp1C && (flags & 0x40)) {
                    if (next != NULL) {
                        *(u8 **)(next + 4) = *(u8 **)(node + 4);
                    }
                    if (*(u8 **)(node + 4) != NULL) {
                        **(u8 ***)(node + 4) = next;
                    } else {
                        lbl_80368ABC = (s32)next;
                    }
                    *(u32 *)(node + 0xC) = (u16)*(u32 *)(node + 0xC);
                    handle = *(s32 *)(node + 0x38);
                    if (handle != -1) {
                        fn_8024A6F8(handle);
                    }
                } else if (flags & 1) {
                    if (fn_8025DAA0(node, sp1C, sp18, sp14, sp10, spC, sp8) == 0) {
                        goto apply;
                    }
                } else {
                    if (*(u8 **)(node + 8) == NULL) {
                        vel = 0xFF;
                    } else {
                        cmd = *(u8 **)(*(u8 **)(node + 8) + 4);
                        n = 0;
                        vel = 0xFF;
                        while (n < **(u8 **)(node + 8)) {
                            if (*(u16 *)cmd == 0x8000) {
                                vel = cmd[2];
                                break;
                            }
                            cmd += 4;
                            n++;
                        }
                    }
                    handle = Sound_Start(*(u16 *)(node + 0x40), vel, 0x7F, 0x40, *(u8 *)(node + 0x42), (flags >> 4) & 1);
                    *(s32 *)(node + 0x38) = handle;
                    if (handle == -1) {
                        flags = *(u32 *)(node + 0xC);
                        if (!(flags & 2)) {
                            *(u32 *)(node + 0xC) = (flags | 0x40000) & ~0x20000;
                            goto apply;
                        }
                    } else {
                        goto apply;
                    }
                }
            } else {
                handle = fn_8024B7DC(*(s32 *)(node + 0x38));
                *(s32 *)(node + 0x38) = handle;
                if (handle == -1) {
                    flags = *(u32 *)(node + 0xC);
                    if (flags & 2) {
                        *(u32 *)(node + 0xC) = flags | 0x20000;
                    } else {
                        *(u32 *)(node + 0xC) = flags | 0x40000;
                    }
                }
            apply:
                if (*(s32 *)(node + 0x38) != -1) {
                    if (*(u32 *)(node + 0xC) & 1) {
                        i = 0;
                        entry = (u8 *)lbl_8035BF18;
                        n = lbl_80368AAE;
                        while (i < (s32)n) {
                            if (*(u32 *)(node + 0x3C) == *(u32 *)entry) break;
                            entry += 0x10;
                            i++;
                        }
                        if (i == (s32)lbl_80368AAE) {
                            entry = (u8 *)lbl_8035BF18 + (i << 4);
                            *(u32 *)(entry + 4) = 0;
                            *(u32 *)(entry + 8) = 0;
                            *(u16 *)(entry + 0xC) = 0;
                            *(u32 *)entry = *(u32 *)(node + 0x3C);
                            lbl_80368AAE += 1;
                        }
                        entry = (u8 *)lbl_8035BF18 + (i << 4);
                        *(u16 *)(entry + 0xC) += 1;
                        cur = *(u8 **)(entry + 8);
                        prev = NULL;
                        while (cur != NULL) {
                            if (*(f32 *)(cur + 4) > sp1C) break;
                            prev = cur;
                            cur = *(u8 **)cur;
                        }
                        pool = lbl_8035C318 + lbl_80368AAC * 0xC;
                        if (prev == NULL) {
                            *(u8 **)(entry + 8) = pool;
                        } else {
                            *(u8 **)prev = pool;
                        }
                        lbl_80368AAC += 1;
                        *(u8 **)pool = cur;
                        *(void **)(pool + 8) = node;
                        *(f32 *)(pool + 4) = sp1C;
                    }
                    if (lbl_8036C2E0 == sp1C && (*(u32 *)(node + 0xC) & 4)) {
                        fn_8024A6F8(*(u32 *)(node + 0x38));
                        *(s32 *)(node + 0x38) = -1;
                        flags = *(u32 *)(node + 0xC);
                        if (flags & 2) {
                            *(u32 *)(node + 0xC) = flags | 0x80000;
                        } else {
                            *(u32 *)(node + 0xC) = flags | 0x40000;
                        }
                    } else {
                        handle = *(s32 *)(node + 0x38);
                        if (*(u32 *)(node + 0xC) & 0x100000) {
                            v = 0x7F;
                            t = (s32)(lbl_8036C314 * (*(f32 *)(node + 0x48) * sp1C));
                            if ((u8)t <= 0x7F) v = t;
                            Sound_SetParamU8(handle, 7, (u8)v);
                        } else {
                            v = 0x7F;
                            f1 = lbl_8036C314 * sp1C;
                            t = (s32)f1;
                            if ((u8)t <= 0x7F) v = t;
                            Sound_SetParamU8(handle, 7, (u8)v);
                        }
                        v = 0x7F;
                        f1 = lbl_8036C318 * (lbl_8036C2E4 + sp18);
                        t = (s32)f1;
                        if ((u8)t <= 0x7F) v = t;
                        Sound_SetParamU8(handle, 0xA, (u8)v);
                        v = 0x7F;
                        f1 = lbl_8036C318 * (lbl_8036C2E4 - sp10);
                        t = (s32)f1;
                        if ((u8)t <= 0x7F) v = t;
                        Sound_SetParamU8(handle, 0x83, (u8)v);
                        f1 = lbl_8036C31C * spC;
                        if (f1 > lbl_8036C310) v = 0x3FFF;
                        else v = (s32)f1;
                        Sound_SetParamU16(handle, 0x84, (u16)v);
                        if (*(u32 *)(node + 0xC) & 0x180) {
                            if (lbl_8036C2E0 != sp8) {
                                f1 = lbl_8036C310 * sp8;
                                if (f1 > lbl_8036C310) v = 0x3FFF;
                                else v = (s32)f1;
                                Sound_SetParamU16(handle, 0x1F, (u16)v);
                                Sound_SetParamU8(handle, 0x4F, 0x7F);
                            } else {
                                Sound_SetParamU8(handle, 0x4F, 0);
                            }
                        }
                        if (*(u8 **)(node + 8) != NULL) {
                            cmd = *(u8 **)(*(u8 **)(node + 8) + 4);
                            idx = 0;
                            while (idx < **(u8 **)(node + 8)) {
                                w = *(u16 *)cmd;
                                if (!(w & 0xFF00)) {
                                    if (w < 0x40 || w == 0x80 || w == 0x84) {
                                        Sound_SetParamU16(handle, (u8)w, *(u16 *)(cmd + 2));
                                    } else {
                                        Sound_SetParamU8(handle, (u8)w, cmd[2]);
                                    }
                                }
                                cmd += 4;
                                idx++;
                            }
                        }
                    }
                }
                if (*(u32 *)(node + 0xC) & 0x100000) {
                    *(f32 *)(node + 0x48) += lbl_8036C328;
                    if (*(f32 *)(node + 0x48) >= lbl_8036C2E4) {
                        *(u32 *)(node + 0xC) &= ~0x100000;
                    }
                }
            }
        }
        node = next;
    }
    fn_8025DBF4();
}

void Sound_ApplyInitFlags(u32 arg0) {
    extern s8 lbl_80368AAF;
    extern s8 lbl_80368AB0;
    extern s8 lbl_80368AB1;
    extern s8 lbl_80368AB2;
    extern s32 lbl_80368AB4;
    extern s32 lbl_80368AB8;
    extern s32 lbl_80368ABC;
    extern s8 lbl_80368AC0;
    lbl_80368ABC = 0;
    lbl_80368AB8 = 0;
    lbl_80368AB4 = 0;
    lbl_80368AB2 = 1;
    lbl_80368AB1 = 3;
    lbl_80368AC0 = 0;
    lbl_80368AB0 = (arg0 >> 1U) & 1;
    lbl_80368AAF = (arg0 >> 2U) & 1;
}

s32 Sound_Init(u8 voices, u8 music, u8 sfx, u8 studios, u32 flags, u32 aramSize) {
#pragma dont_inline on
    /* Initialize the sound driver: clamp voice/studio counts, set up ARAM, mark ready. */
    s32 fn_80261620(u32 *, u8, u8, u32);
    s32 fn_80262AF0(void);
    s32 fn_80262B14(u32);
    void fn_80258A98(s32, s32);
    void fn_80250A74(s32, u32);
    void fn_80247D74(void);
    void fn_8024ADFC(u32, u8);
    void fn_8024BB90(void);
    void fn_80258100(void);
    extern u8 gSoundReady;
    extern u8 lbl_803689B0;
    u32 rate;
    s32 ret;
    u8 voiceCount;
    s32 aramBase;

    gSoundReady = 0;
    if (voices <= 64) {
        gSoundData[0x210] = voices;
    } else {
        gSoundData[0x210] = 64;
    }
    if (studios <= 8) {
        gSoundData[0x213] = studios;
    } else {
        gSoundData[0x213] = 8;
    }
    rate = 32000;
    gSoundData[0x211] = music;
    gSoundData[0x212] = sfx;
    ret = fn_80261620(&rate, gSoundData[0x210], gSoundData[0x213], flags);
    if (ret == 0) {
        aramBase = fn_80262AF0();
        voiceCount = gSoundData[0x210];
        fn_80258A98(aramBase, fn_80262B14(aramSize));
        fn_80250A74(0, aramSize);
        fn_80247D74();
        lbl_803689B0 = 0;
        fn_8024ADFC(32000, voiceCount);
        fn_8024BB90();
        fn_80258100();
        Sound_ApplyInitFlags(flags);
        ret = 0;
        gSoundReady = 1;
    }
    return ret;
}

u8 Sound_IsReady(void) {
#pragma dont_inline reset
    extern u8 gSoundReady;
    return gSoundReady;
}

#pragma fp_contract off
void fn_8025ED88(f32 *m, f32 *v, f32 *out)
{
    out[0] = ((m[0] * v[0] + m[1] * v[1]) + m[2] * v[2]) + m[9];
    out[1] = ((m[3] * v[0] + m[4] * v[1]) + m[5] * v[2]) + m[10];
    out[2] = ((m[6] * v[0] + m[7] * v[1]) + m[8] * v[2]) + m[11];
}
#pragma optimization_level 3
void fn_8025EE34(f32 *arg0)
{
 extern f32 lbl_8036C330; extern f64 lbl_8036C338; extern f64 lbl_8036C340;
 volatile f32 sp8;
 f32 x=arg0[0], y=arg0[1], z=arg0[2];
 f32 len2=z*z+(x*x+y*y);
 if(len2>lbl_8036C330){
 f64 est=__frsqrte(len2); f64 half=lbl_8036C338; f64 three=lbl_8036C340;
 est=(half*est)*(three-len2*(est*est));
 est=(half*est)*(three-len2*(est*est));
 est=(half*est)*(three-len2*(est*est));
 sp8=(f32)(len2*est);
 len2=sp8;
 arg0[0]/=len2; arg0[1]/=len2; arg0[2]/=len2;
 }
}
#pragma optimization_level reset
void fn_8025EEE8(s32 arg0, s32 arg1, s32 arg2) {
    u8 *temp_r4;

    temp_r4 = (u8 *) lbl_8035D118 + ((arg1 & 0xFF) << 6);
    *(u32 *) (temp_r4 + ((arg0 & 0xFF) << 2)) |= arg2;
}

void fn_8025EF0C(u8 arg0, s32 arg1, s32 arg2)
{
    extern u8 gSoundChanParams[];
    extern u8 lbl_80361618[];
    extern u8 gSoundData[];
    extern s32 gSynthVoices;

    u8 *cell;
    u8 *row;
    u8 *voice;
    u8 *p;
    u16 code;
    u32 value;
    u32 i;
    u32 offset;
    s32 mul90;
    s32 mul9;
    u8 bank;
    u8 channel;
    u8 val;

    bank = arg0;
    channel = (u8)arg1;

    cell = gSoundChanParams +
           bank * 0x860 +
           channel * 0x86;

    code = (u16)((cell[0x64] << 8) | cell[0x65]);

    switch (code) {
    case 0:
        val = (u8)arg2;

        if (val > 0x18) {
            val = 0x18;
        }

        mul90 = bank * 0x90;
        mul9 = channel * 9;

        row = lbl_80361618 + mul90;
        row[mul9] = val;

        i = 0;
        offset = 0;

        while (i < gSoundData[0x210]) {
            voice = (u8 *)gSynthVoices + offset;

            if (bank == voice[0x122] &&
                channel == voice[0x121]) {
                voice[0x1DB] = val;
                ((u8 *)gSynthVoices)[offset + 0x1DA] = val;
            }

            offset += 0x458;
            i++;
        }
        return;

    case 0x7F7D:
        mul90 = bank * 0x90;
        mul9 = channel * 9;

        p = lbl_80361618 + mul90 + mul9;

        value = *(u32 *)(p + 1);
        value = (value & 0x1FF) | (((u8)arg2) << 9);
        *(u32 *)(p + 1) = value;

        i = 0;
        offset = 0;

        while (i < gSoundData[0x210]) {
            voice = (u8 *)gSynthVoices + offset;

            if (bank == voice[0x122] &&
                channel == voice[0x121]) {
                *(u32 *)(voice + 0x1E0) = value;
            }

            offset += 0x458;
            i++;
        }
        return;

    case 0x7F7E:
        mul90 = bank * 0x90;
        mul9 = channel * 9;

        p = lbl_80361618 + mul90 + mul9;

        value = *(u32 *)(p + 5);
        value = (value & 0x1FF) | (((u8)arg2) << 9);
        *(u32 *)(p + 5) = value;

        i = 0;
        offset = 0;

        while (i < gSoundData[0x210]) {
            voice = (u8 *)gSynthVoices + offset;

            if (bank == voice[0x122] &&
                channel == voice[0x121]) {
                *(u32 *)(voice + 0x1E4) = value;
            }

            offset += 0x458;
            i++;
        }
        return;
    }
}

#pragma global_optimizer off
void fn_8025F0EC(u8 arg0, u8 arg1) {
    extern u8 gSoundChanParams[];
    extern u8 lbl_80361618[];
    extern u8 gSoundData[];
    extern s32 gSynthVoices;

    u8 *cell;
    u16 code;
    s32 mul90;
    s32 mul9;
    u8 *row;
    u8 *p;
    s32 off;
    u32 i;
    u8 val;
    u8 *vp;
    u8 a0;
    u8 a1;
    s32 idx;
    s32 t0;
    s32 t1;

    t0 = arg0 * 0x860;
    t1 = arg1 * 0x86;
    cell = gSoundChanParams + t0 + t1;
    code = (u16)(cell[0x64] | (cell[0x65] << 8));
    switch ((s32)code) {
    case 0:
        mul90 = arg0 * 0x90;
        mul9 = arg1 * 9;
        row = lbl_80361618 + mul90;
        val = *(row + mul9);
        if (val != 0) {
            val = (u8)(val - 1);
        }
        *(row + mul9) = val;
        a0 = arg0;
        a1 = arg1;
        i = 0;
        off = 0;
        while (i < gSoundData[0x210]) {
            vp = (u8 *)gSynthVoices + off;
            if (a0 == vp[0x122] && a1 == vp[0x121]) {
                idx = off + 0x1DA;
                vp[0x1DB] = val;
                ((u8 *)gSynthVoices)[idx] = val;
            }
            off += 0x458;
            i += 1;
        }
        return;
    case 0x7F7D:
        mul90 = arg0 * 0x90;
        mul9 = arg1 * 9;
        p = lbl_80361618 + mul90 + mul9;
        if (*(u32 *)(p += 1) != 0) {
            *(u32 *)p = *(u32 *)p - 1;
        }
        i = 0;
        p = lbl_80361618 + mul90 + mul9;
        off = i;
        p += 1;
        a0 = arg0;
        a1 = arg1;
        while (i < gSoundData[0x210]) {
            vp = (u8 *)gSynthVoices + off;
            if (a0 == vp[0x122] && a1 == vp[0x121]) {
                *(u32 *)(vp + 0x1E0) = *(u32 *)p;
            }
            off += 0x458;
            i += 1;
        }
        return;
    case 0x7F7E:
        mul90 = arg0 * 0x90;
        mul9 = arg1 * 9;
        p = lbl_80361618 + mul90 + mul9;
        if (*(u32 *)(p += 5) != 0) {
            *(u32 *)p = *(u32 *)p - 1;
        }
        i = 0;
        p = lbl_80361618 + mul90 + mul9;
        off = i;
        p += 5;
        a0 = arg0;
        a1 = arg1;
        while (i < gSoundData[0x210]) {
            vp = (u8 *)gSynthVoices + off;
            if (a0 == vp[0x122] && a1 == vp[0x121]) {
                *(u32 *)(vp + 0x1E4) = *(u32 *)p;
            }
            off += 0x458;
            i += 1;
        }
        return;
    }
}
#pragma global_optimizer off
void fn_8025F310(u8 arg0, u8 arg1) {
    extern u8 gSoundChanParams[];
    extern u8 lbl_80361618[];
    extern u8 gSoundData[];
    extern s32 gSynthVoices;

    u8 *cell;
    u16 code;
    s32 mul90;
    s32 mul9;
    u8 *row;
    u8 *p;
    s32 off;
    u32 i;
    u8 val;
    u8 *vp;
    u8 a0;
    u8 a1;
    s32 idx;
    s32 t0;
    s32 t1;

    t0 = arg0 * 0x860;
    t1 = arg1 * 0x86;
    cell = gSoundChanParams + t0 + t1;
    code = (u16)(cell[0x64] | (cell[0x65] << 8));
    switch ((s32)code) {
    case 0:
        mul90 = arg0 * 0x90;
        mul9 = arg1 * 9;
        row = lbl_80361618 + mul90;
        val = *(row + mul9);
        if (val < 0x18U) {
            val = (u8)(val + 1);
        }
        *(row + mul9) = val;
        a0 = arg0;
        a1 = arg1;
        i = 0;
        off = 0;
        while (i < gSoundData[0x210]) {
            vp = (u8 *)gSynthVoices + off;
            if (a0 == vp[0x122] && a1 == vp[0x121]) {
                idx = off + 0x1DA;
                vp[0x1DB] = val;
                ((u8 *)gSynthVoices)[idx] = val;
            }
            off += 0x458;
            i += 1;
        }
        return;
    case 0x7F7D:
        mul90 = arg0 * 0x90;
        mul9 = arg1 * 9;
        p = lbl_80361618 + mul90 + mul9;
        if (*(u32 *)(p += 1) != 0x3FFFU) {
            *(u32 *)p = *(u32 *)p + 1;
        }
        i = 0;
        p = lbl_80361618 + mul90 + mul9;
        off = i;
        p += 1;
        a0 = arg0;
        a1 = arg1;
        while (i < gSoundData[0x210]) {
            vp = (u8 *)gSynthVoices + off;
            if (a0 == vp[0x122] && a1 == vp[0x121]) {
                *(u32 *)(vp + 0x1E0) = *(u32 *)p;
            }
            off += 0x458;
            i += 1;
        }
        return;
    case 0x7F7E:
        mul90 = arg0 * 0x90;
        mul9 = arg1 * 9;
        p = lbl_80361618 + mul90 + mul9;
        if (*(u32 *)(p += 5) != 0x3FFFU) {
            *(u32 *)p = *(u32 *)p + 1;
        }
        i = 0;
        p = lbl_80361618 + mul90 + mul9;
        off = i;
        p += 5;
        a0 = arg0;
        a1 = arg1;
        while (i < gSoundData[0x210]) {
            vp = (u8 *)gSynthVoices + off;
            if (a0 == vp[0x122] && a1 == vp[0x121]) {
                *(u32 *)(vp + 0x1E4) = *(u32 *)p;
            }
            off += 0x458;
            i += 1;
        }
        return;
    }
}
#pragma global_optimizer on
int Sound_WriteParamU8(param,channel,bank,value)
s32 param;
s32 channel;
u8 bank;
s32 value;
{
    void fn_8025EF0C(u8,s32,s32);
    void fn_8025F0EC(u8,s32);
    void fn_8025F310(u8,s32);
    void fn_80249E14(void *);
    u8 *base=(u8 *)lbl_8035D118;
    u32 changed;
    if((u8)channel!=255) {
        if(bank!=255) {
switch(param & 255U) {
        case 6: fn_8025EF0C(bank,channel,value); changed=1; break;
        case 0x26: {
            u8 *entry=(base+0x200)+(u8)bank*0x860+(u8)channel*0x86;
            u16 code=entry[0x64] | (entry[0x65]<<8);
            switch(code) {
            case 0x7F7D: {
                u8 *control=base+0x4500+(u8)bank*0x90+(u8)channel*9;
                u32 v=(*(u32 *)(control+1)&0xFE00)|(((u32)value<<2)&0x3FC);
                u32 i=0;
                u32 offset=0;
                *(u32 *)(control+1)=v;
                while(i<gSoundData[0x210]) {
                    u8 *voice=(u8 *)gSynthVoices+offset;
                    if((u8)bank==voice[0x122] && (u8)channel==voice[0x121]) *(u32 *)(voice+0x1E0)=v;
                    offset+=0x458; i++;
                }
                break;
            }
            case 0x7F7E: {
                u8 *control=base+0x4500+(u8)bank*0x90+(u8)channel*9;
                u32 v=(*(u32 *)(control+5)&0xFE00)|(((u32)value<<2)&0x3FC);
                u32 i=0;
                u32 offset=0;
                *(u32 *)(control+5)=v;
                while(i<gSoundData[0x210]) {
                    u8 *voice=(u8 *)gSynthVoices+offset;
                    if((u8)bank==voice[0x122] && (u8)channel==voice[0x121]) *(u32 *)(voice+0x1E4)=v;
                    offset+=0x458; i++;
                }
                break;
            }
            }
            changed=1; break;
        }
        case 0x60: fn_8025F0EC(bank,channel); changed=1; break;
        case 0x61: fn_8025F310(bank,channel); changed=1; break;
        default: changed=(value&0x7F)!=((u8 *)(base+0x200))[(u8)bank*0x860+(u8)channel*0x86+(u8)param]; break;
        }
        ((u8 *)(base+0x200))[(u8)bank*0x860+(u8)channel*0x86+(u8)param]=value&0x7F;
        if(changed) {
            u32 i=0;
            u32 offset=0;
            while(i<gSoundData[0x210]) {
                u8 *voice=(u8 *)gSynthVoices+offset;
                if((u8)bank==voice[0x122] && (u8)channel==voice[0x121]) {
                    *(u32 *)(voice+0x220)=0x7FFF;
                    fn_80249E14((u8 *)gSynthVoices+offset);
                }
                offset+=0x458; i++;
            }
            *(u32 *)(base+((u8)bank<<6)+((u8)channel<<2))=255;
        }
        } else {
switch(param & 255U) {
        case 6: fn_8025EF0C(bank,channel,value); changed=1; break;
        case 0x26: {
            u8 *entry=(base+0x200)+(u8)bank*0x860+(u8)channel*0x86;
            u16 code=entry[0x64] | (entry[0x65]<<8);
            switch(code) {
            case 0x7F7D: {
                u8 *control=base+0x4500+(u8)bank*0x90+(u8)channel*9;
                u32 v=(*(u32 *)(control+1)&0xFE00)|(((u32)value<<2)&0x3FC);
                u32 i=0;
                u32 offset=0;
                *(u32 *)(control+1)=v;
                while(i<gSoundData[0x210]) {
                    u8 *voice=(u8 *)gSynthVoices+offset;
                    if((u8)bank==voice[0x122] && (u8)channel==voice[0x121]) *(u32 *)(voice+0x1E0)=v;
                    offset+=0x458; i++;
                }
                break;
            }
            case 0x7F7E: {
                u8 *control=base+0x4500+(u8)bank*0x90+(u8)channel*9;
                u32 v=(*(u32 *)(control+5)&0xFE00)|(((u32)value<<2)&0x3FC);
                u32 i=0;
                u32 offset=0;
                *(u32 *)(control+5)=v;
                while(i<gSoundData[0x210]) {
                    u8 *voice=(u8 *)gSynthVoices+offset;
                    if((u8)bank==voice[0x122] && (u8)channel==voice[0x121]) *(u32 *)(voice+0x1E4)=v;
                    offset+=0x458; i++;
                }
                break;
            }
            }
            changed=1; break;
        }
        case 0x60: fn_8025F0EC(bank,channel); changed=1; break;
        case 0x61: fn_8025F310(bank,channel); changed=1; break;
        default: changed=(value&0x7F)!=((u8 *)(base+0x4980))[(u8)channel*0x86+(u8)param]; break;
        }
        ((u8 *)(base+0x4980))[(u8)channel*0x86+(u8)param]=value&0x7F;
        if(changed) {
            u32 i=0;
            u32 offset=0;
            while(i<gSoundData[0x210]) {
                u8 *voice=(u8 *)gSynthVoices+offset;
                if((u8)bank==voice[0x122] && (u8)channel==voice[0x121]) {
                    *(u32 *)(voice+0x220)=0x7FFF;
                    fn_80249E14((u8 *)gSynthVoices+offset);
                }
                offset+=0x458; i++;
            }
            
        }
        }
    }
}

int fn_8025FA50(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
void Sound_WriteParamU8(s32, s32, s32, u8);
u8 a,b,c;
if((u8)arg1 != 255) {
 if((u8)arg0 < 0x40U) { u16 value=(u16)arg3; a=arg0&31; Sound_WriteParamU8(a,arg1,arg2,(u8)(value>>7)); Sound_WriteParamU8((u8)(a+32),arg1,arg2,value&127); }
 else if((u8)arg0==0x80 || (u8)arg0==0x81) { u16 value=(u16)arg3; b=arg0&254; Sound_WriteParamU8(b,arg1,arg2,(u8)(value>>7)); Sound_WriteParamU8((u8)(b+1),arg1,arg2,value&127); }
 else if((u8)arg0==0x84 || (u8)arg0==0x85) { u16 value=(u16)arg3; c=arg0&254; Sound_WriteParamU8(c,arg1,arg2,(u8)(value>>7)); Sound_WriteParamU8((u8)(c+1),arg1,arg2,value&127); }
 else Sound_WriteParamU8(arg0,arg1,arg2,(u8)((u16)arg3>>7));
}
}

#pragma optimization_level 3
void fn_8025FB74(u32 arg0, u32 arg1, u32 arg2)
{
    extern u8 lbl_80283128[];
    extern u8 lbl_802830A0[];
    extern u8 gSoundChanParams[];
    extern u16 gSoundChanParamsDefault[4288];

    void *memcpy(void *, void *, u32);
    void fn_80260174(u32, u32, u32);

    u8 *dst;
    u8 *src;
    s32 i;

    src = lbl_80283128;

    if (arg2 != 0) {
        src = lbl_802830A0;
    }

    if ((u8)arg1 != 0xFF) {
        dst = gSoundChanParams + ((u8)arg1 * 0x860) + ((u8)arg0 * 0x86);
    } else {
        dst = (u8 *)gSoundChanParamsDefault + ((u8)arg0 * 0x86);
    }

    if (arg2 != 0) {
        memcpy(dst, src, 0x86);
    } else {
        for (i = 0; i < 0x43; i++) {
            if (src[0] != 0xFF) {
                dst[0] = src[0];
            }
            if (src[1] != 0xFF) {
                dst[1] = src[1];
            }
            dst += 2;
            src += 2;
        }
    }

    fn_80260174(arg0, arg1, 0xFF);
}
#pragma optimization_level reset
/* Read channel param `op` from group/channel tables as a 14-bit value (0 if channel is 255). */
u16 Sound_GetChanParam(u8 op,u8 channel,u8 group) {
extern u8 gSoundChanParams[];
if(channel!=255) {
if(group!=255) {if(op<0x40U){u32 index=op&31;return (((gSoundChanParams+group*0x860+channel*0x86)[index]<<7)|(gSoundChanParams+group*0x860+channel*0x86)[index+0x20]);}
if(op<0x46U) return (gSoundChanParams+group*0x860+channel*0x86)[op]<0x40 ? 0 : 0x3fff;
if(op>=0x60U && op<0x66U) return 0;
if(op==0x80U || op==0x81U) {u32 index=op&0xfe;return (((gSoundChanParams+group*0x860+channel*0x86)[index]<<7)|(gSoundChanParams+group*0x860+channel*0x86)[index+1]);}
if(op==0x84U || op==0x85U) {u32 index=op&0xfe;return (((gSoundChanParams+group*0x860+channel*0x86)[index]<<7)|(gSoundChanParams+group*0x860+channel*0x86)[index+1]);}
return (gSoundChanParams+group*0x860+channel*0x86)[op]<<7;}
else {if(op<0x40U){u32 index; s32 offset; offset=channel*0x86;index=op&31;return ((((u8*)gSoundChanParamsDefault+offset)[index]<<7)|((u8*)gSoundChanParamsDefault+offset)[index+0x20]);}
if(op<0x46U) return ((u8*)gSoundChanParamsDefault+channel*0x86)[op]<0x40 ? 0 : 0x3fff;
if(op>=0x60U && op<0x66U) return 0;
if(op==0x80U || op==0x81U) {u32 index; s32 offset; offset=channel*0x86;index=op&0xfe;return ((((u8*)gSoundChanParamsDefault+offset)[index]<<7)|((u8*)gSoundChanParamsDefault+offset)[index+1]);}
if(op==0x84U || op==0x85U) {u32 index; s32 offset; offset=channel*0x86;index=op&0xfe;return ((((u8*)gSoundChanParamsDefault+offset)[index]<<7)|((u8*)gSoundChanParamsDefault+offset)[index+1]);}
return ((u8*)gSoundChanParamsDefault+channel*0x86)[op]<<7;}
}
else return 0;
}

void *fn_8025FF28(u8 arg0, u8 arg1) {
    extern u8 lbl_80363C18[];
    extern u8 lbl_80361618[];

    if (arg1 == 0xFF) {
        return lbl_80363C18 + arg0 * 9;
    }
    return lbl_80361618 + arg1 * 0x90 + arg0 * 9;
}

void fn_8025FF6C(u8 arg0, u8 arg1) {
    extern u8 lbl_80361618[];
    extern u8 lbl_80363C18[];
    extern s32 lbl_80368AC8;
    extern s32 lbl_80368ACC;
    
    char *var_r3;

    if (arg1 != 0xFF) {
        var_r3 = (char *)&lbl_80361618 + (arg1 * 0x90) + (arg0 * 9);
    } else {
        var_r3 = (char *)&lbl_80363C18 + (arg0 * 9);
    }
    *(u8 *)var_r3 = 2;
    *(s32 *)((char *)var_r3 + 1) = lbl_80368ACC;
    *(s32 *)((char *)var_r3 + 5) = lbl_80368AC8;
}

void fn_8025FFC8(void *arg0, u8 arg1, s32 arg2, u8 arg3, u8 arg4, u8 arg5)
{
    extern u32 fn_80260EA8(u8);
    u8 *p;
    u8 idx;
    u32 off;

    p = (u8 *)arg0;

    if (arg3 == 0) {
        p[0x22] = 0;
    }

    idx = p[0x22];
    if (idx >= 4) {
        return;
    }

    p[0x22] = idx + 1;

    if (arg4 == 0) {
        arg1 = fn_80260EA8(arg1);
    }
    if (arg4 != 0) {
        arg3 |= 0x10;
    }

    off = (u8)idx << 3;
    p[off] = arg1;
    {
        u8 *q = p + off;
        q[1] = arg3;
        *(s32 *)(q + 4) = arg2;
    }
}

void fn_80260060(u8 op, void *a,void *b) {
u8 dest=*(u32 *)((u8 *)a+0xF4); u8 source=*(u32 *)((u8 *)b+0xF4);
if(op<0x40U) {u32 index=op & 31; s32 src=source*0x86; s32 dst=dest*0x86; ((u8 *)gSoundChanParamsDefault+dst)[index]=((u8 *)gSoundChanParamsDefault+src)[index]; ((u8 *)gSoundChanParamsDefault+32)[dst+index]=((u8 *)gSoundChanParamsDefault+32)[src+index];}
else if(op==0x80U || op==0x81U) {u32 index=op & 0xFE; s32 src=source*0x86; s32 dst=dest*0x86; ((u8 *)gSoundChanParamsDefault+dst)[index]=((u8 *)gSoundChanParamsDefault+src)[index]; ((u8 *)gSoundChanParamsDefault+1)[dst+index]=((u8 *)gSoundChanParamsDefault+1)[src+index];}
else if(op==0x84U || op==0x85U) {u32 index=op & 0xFE; s32 src=source*0x86; s32 dst=dest*0x86; ((u8 *)gSoundChanParamsDefault+dst)[index]=((u8 *)gSoundChanParamsDefault+src)[index]; ((u8 *)gSoundChanParamsDefault+1)[dst+index]=((u8 *)gSoundChanParamsDefault+1)[src+index];}
else { ((u8 *)gSoundChanParamsDefault+dest*0x86)[op]=((u8 *)gSoundChanParamsDefault+source*0x86)[op]; }
}

void fn_80260174(u8 arg0, u8 arg1, u8 arg2) {
    extern u8 lbl_80363E58[8][16];
    extern u8 lbl_80363ED8[64];
    if (arg1 != 0xFF) {
        lbl_80363E58[arg1][arg0] = arg2;
        return;
    }
    lbl_80363ED8[arg0] = arg2;
}

u8 fn_802601B0(u8 arg0, u8 arg1) {
    extern u8 lbl_80363E58[8][16];
    extern u8 lbl_80363ED8[64];
    if (arg1 != 0xFF) {
        return lbl_80363E58[arg1][arg0];
    }
    return lbl_80363ED8[arg0];
}

#pragma global_optimizer off
u16 fn_802601EC(void *arg0, void *arg1, u8 arg2, u8 arg3) {
    s16 fn_802537F8(void *, s32, u8);
    u16 Sound_GetChanParam(u8, u8, u8);
    extern s32 lbl_803689B8;
    extern s32 lbl_803689BC;

    u8 *entry;
    s32 acc;
    u32 i;
    u32 signed_mode;
    u8 a3;
    u8 a2;
    u8 *list;
    void *obj;
    s32 val;
    s32 tmp;
    s32 scaled;
    u8 op;
    u8 mode;
    s32 r5;
    u64 diff;
    s32 mul;
    s32 idx;

    list = (u8 *)arg1;
    obj = arg0;
    a2 = arg2;
    a3 = arg3;
    entry = list;
    acc = 0;
    i = 0;

    while (i < list[0x22]) {
        if ((entry[1] & 0x10) != 0) {
            val = obj != 0 ? (s16)fn_802537F8(obj, 0, entry[0]) : 0;
            goto apply_signed;
        }

        op = entry[0];
        if (op == 0x80 || op == 1 || op == 0xA || (u8)(op - 0xA0) <= 1 || op == 0x83) {
            switch (op) {
            case 0xA0:
            case 0xA1:
                if (obj != 0) {
                    mul = op * 0xC;
                    idx = op + 0x138;
                    val = 1;
                    mul -= 0x5B8;
                    tmp = *(s16 *)((s32)obj + mul);
                    *((u8 *)obj + idx) = val;
                    val = tmp << 1;
                } else {
                    val = 0;
                }
                break;
            default:
                val = (u16)Sound_GetChanParam(op, a2, a3) - 0x2000;
                break;
            }

apply_signed:
            scaled = (val * (*(s32 *)(entry + 4) >> 1)) >> 15;
            if (scaled < -0x2000) {
                val = -0x2000;
            } else {
                val = 0x1FFF;
                if (scaled <= 0x1FFF) {
                    val = scaled;
                }
            }

            mode = (u8)(entry[1] & 0xF);
            switch (mode) {
            case 0:
                acc = val + 0x2000;
                signed_mode = 1;
                break;
            case 1:
                if (signed_mode != 0) {
                    tmp = acc + val;
                    tmp -= 0x2000;
                    if (tmp < -0x2000) {
                        val = -0x2000;
                    } else {
                        val = 0x1FFF;
                        if (tmp <= 0x1FFF) {
                            val = tmp;
                        }
                    }
                    acc = val + 0x2000;
                } else {
                    val = acc + val;
                    if (val > 0x3FFF) {
                        acc = 0x3FFF;
                    } else {
                        acc = val & ~(val >> 31);
                    }
                }
                break;
            case 2:
                if (signed_mode != 0) {
                    scaled = ((acc - 0x2000) * val) >> 13;
                } else {
                    signed_mode = 1;
                    scaled = (s32)((u32)(val * acc) >> 13);
                }
                if (scaled < -0x2000) {
                    val = -0x2000;
                } else {
                    val = 0x1FFF;
                    if (scaled <= 0x1FFF) {
                        val = scaled;
                    }
                }
                acc = val + 0x2000;
                break;
            case 3:
                if (signed_mode != 0) {
                    scaled = acc - 0x2000;
                    scaled -= val;
                    if (scaled < -0x2000) {
                        val = -0x2000;
                    } else {
                        val = 0x1FFF;
                        if (scaled <= 0x1FFF) {
                            val = scaled;
                        }
                    }
                    acc = val + 0x2000;
                } else {
                    val = acc - val;
                    if (val > 0x3FFF) {
                        acc = 0x3FFF;
                    } else {
                        acc = val & ~(val >> 31);
                    }
                }
                break;
            }
        } else {
            switch ((s32)op) {
            case 0xA2:
                if (obj != 0) {
                    r5 = ((u8 *)obj)[0x131] << 7;
                } else {
                    r5 = 0;
                }
                goto unsigned_mul;
            case 0xA3:
                if (obj != 0) {
                    r5 = (s32)(*(u32 *)((u8 *)obj + 0x15C) >> 9);
                } else {
                    r5 = 0;
                }
                goto unsigned_mul;
            case 0xA4:
                if (obj != 0) {
                    diff = (((u64)(u32)lbl_803689B8 << 32) | (u32)lbl_803689BC)
                         - (((u64)*(u32 *)((u8 *)obj + 0x90) << 32) | *(u32 *)((u8 *)obj + 0x94));
                    r5 = (s32)(diff >> 8);
                    if (r5 > 0x3FFF) {
                        r5 = 0x3FFF;
                    }
                    ((u8 *)obj)[0xA8] = 1;
                } else {
                    r5 = 0;
                }
                goto unsigned_mul;
            default:
                r5 = a3;
                r5 = (u16)Sound_GetChanParam(op, a2, (u8)r5);
                break;
            }

unsigned_mul:
            val = (r5 * (*(s32 *)(entry + 4) >> 1)) >> 15;
            if (val > 0x3FFF) {
                val = 0x3FFF;
            }

            mode = (u8)(entry[1] & 0xF);
            switch (mode) {
            case 0:
                acc = val;
                signed_mode = 0;
                break;
            case 1:
                if (signed_mode != 0) {
                    tmp = acc + val;
                    tmp -= 0x2000;
                    if (tmp < -0x2000) {
                        val = -0x2000;
                    } else {
                        val = 0x1FFF;
                        if (tmp <= 0x1FFF) {
                            val = tmp;
                        }
                    }
                    acc = val + 0x2000;
                } else {
                    acc += val;
                    idx = 0x3FFF;
                    if ((u32)acc <= 0x3FFFU) {
                        idx = acc;
                    }
                    acc = idx;
                }
                break;
            case 2:
                if (signed_mode != 0) {
                    scaled = (val * (acc - 0x2000)) >> 14;
                    if (scaled < -0x2000) {
                        val = -0x2000;
                    } else {
                        val = 0x1FFF;
                        if (scaled <= 0x1FFF) {
                            val = scaled;
                        }
                    }
                    acc = val + 0x2000;
                } else {
                    scaled = (s32)((u32)(acc * val) >> 14);
                    acc = 0x3FFF;
                    if ((u32)scaled <= 0x3FFFU) {
                        acc = scaled;
                    }
                }
                break;
            case 3:
                if (signed_mode != 0) {
                    scaled = acc - 0x2000;
                    scaled -= val;
                    if (scaled < -0x2000) {
                        val = -0x2000;
                    } else {
                        val = 0x1FFF;
                        if (scaled <= 0x1FFF) {
                            val = scaled;
                        }
                    }
                    acc = val + 0x2000;
                } else {
                    val = acc - val;
                    if (val > 0x3FFF) {
                        acc = 0x3FFF;
                    } else {
                        acc = val & ~(val >> 31);
                    }
                }
                break;
            }
        }

        entry += 8;
        i += 1;
    }

    *(s16 *)(list + 0x20) = (s16)acc;
    return (u16)acc;
}
#pragma global_optimizer reset
u16 fn_8026068C(void *arg0) {
    u16 fn_802601EC(void *, void *, u8, u8);
    s32 temp_r4;

    temp_r4 = *(s32 *)((u8 *)arg0 + 0x220);
    if (!(temp_r4 & 1)) {
        return *(u16 *)((u8 *)arg0 + 0x244);
    }
    *(s32 *)((u8 *)arg0 + 0x220) = temp_r4 & ~1;
    return fn_802601EC(arg0, (u8 *)arg0 + 0x224, *(u8 *)((u8 *)arg0 + 0x121), *(u8 *)((u8 *)arg0 + 0x122));
}

u16 fn_802606D4(void *arg0) {
    u16 fn_802601EC(void *, void *, u8, u8);
    s32 temp_r4;

    temp_r4 = *(s32 *)((u8 *)arg0 + 0x220);
    if (!(temp_r4 & 2)) {
        return *(u16 *)((u8 *)arg0 + 0x268);
    }
    *(s32 *)((u8 *)arg0 + 0x220) = temp_r4 & ~2;
    return fn_802601EC(arg0, (u8 *)arg0 + 0x248, *(u8 *)((u8 *)arg0 + 0x121), *(u8 *)((u8 *)arg0 + 0x122));
}

u16 fn_8026071C(void *arg0) {
    u16 fn_802601EC(void *, void *, u8, u8);
    s32 temp_r4;

    temp_r4 = *(s32 *)((u8 *)arg0 + 0x220);
    if (!(temp_r4 & 4)) {
        return *(u16 *)((u8 *)arg0 + 0x28C);
    }
    *(s32 *)((u8 *)arg0 + 0x220) = temp_r4 & ~4;
    return fn_802601EC(arg0, (u8 *)arg0 + 0x26C, *(u8 *)((u8 *)arg0 + 0x121), *(u8 *)((u8 *)arg0 + 0x122));
}

s32 fn_80260764(void *arg0)
{
    s32 fn_802601EC(void *, void *, u8, u8);

    u32 flags;

    flags = *(u32 *)((u8 *)arg0 + 0x220);

    if ((flags & 0x8) == 0) {
        return *(u16 *)((u8 *)arg0 + 0x2B0);
    }

    flags &= ~0x8;
    *(u32 *)((u8 *)arg0 + 0x220) = flags;

    return fn_802601EC(
        arg0,
        (u8 *)arg0 + 0x290,
        *(u8 *)((u8 *)arg0 + 0x121),
        *(u8 *)((u8 *)arg0 + 0x122)
    );
}

u16 fn_802607AC(void *arg0) {
    u16 fn_802601EC(void *, void *, u8, u8);
    s32 temp_r4;

    temp_r4 = *(s32 *)((u8 *)arg0 + 0x220);
    if (!(temp_r4 & 0x10)) {
        return *(u16 *)((u8 *)arg0 + 0x2D4);
    }
    *(s32 *)((u8 *)arg0 + 0x220) = temp_r4 & ~0x10;
    return fn_802601EC(arg0, (u8 *)arg0 + 0x2B4, *(u8 *)((u8 *)arg0 + 0x121), *(u8 *)((u8 *)arg0 + 0x122));
}

s32 fn_802607F4(void *arg0) {
    s32 fn_802601EC(void *, void *, u8, u8);
    s32 temp_r4;

    temp_r4 = *(s32 *)((u8 *)arg0 + 0x220);
    if (!(temp_r4 & 0x20)) {
        return *(u16 *)((u8 *)arg0 + 0x2F8);
    }
    *(s32 *)((u8 *)arg0 + 0x220) = temp_r4 & 0xFFFFFFDF;
    return fn_802601EC(arg0, (u8 *)arg0 + 0x2D8, *(u8 *)((u8 *)arg0 + 0x121), *(u8 *)((u8 *)arg0 + 0x122));
}

s32 fn_8026083C(void *arg0) {
    s32 fn_802601EC(void *, void *, u8, u8);
    s32 temp_r4;

    temp_r4 = *(s32 *)((u8 *)arg0 + 0x220);
    if (!(temp_r4 & 0x40)) {
        return *(u16 *)((u8 *)arg0 + 0x31C);
    }
    *(s32 *)((u8 *)arg0 + 0x220) = temp_r4 & 0xFFFFFFBF;
    return fn_802601EC(arg0, (u8 *)arg0 + 0x2FC, *(u8 *)((u8 *)arg0 + 0x121), *(u8 *)((u8 *)arg0 + 0x122));
}

s32 fn_80260884(void *arg0) {
    s32 fn_802601EC(void *, void *, u8, u8);
    s32 temp_r4;

    temp_r4 = *(s32 *)((u8 *)arg0 + 0x220);
    if (!(temp_r4 & 0x100)) {
        return *(u16 *)((u8 *)arg0 + 0x364);
    }
    *(s32 *)((u8 *)arg0 + 0x220) = temp_r4 & 0xFFFFFEFF;
    return fn_802601EC(arg0, (u8 *)arg0 + 0x344, *(u8 *)((u8 *)arg0 + 0x121), *(u8 *)((u8 *)arg0 + 0x122));
}

s32 fn_802608CC(void *arg0) {
    s32 fn_802601EC(void *, void *, u8, u8);
    s32 temp_r4;

    temp_r4 = *(s32 *)((u8 *)arg0 + 0x220);
    if (!(temp_r4 & 0x200)) {
        return *(u16 *)((u8 *)arg0 + 0x388);
    }
    *(s32 *)((u8 *)arg0 + 0x220) = temp_r4 & 0xFFFFFDFF;
    return fn_802601EC(arg0, (u8 *)arg0 + 0x368, *(u8 *)((u8 *)arg0 + 0x121), *(u8 *)((u8 *)arg0 + 0x122));
}

s32 fn_80260914(void *arg0) {
    s32 fn_802601EC(void *, void *, u8, u8);
    s32 temp_r4;

    temp_r4 = *(s32 *)((u8 *)arg0 + 0x220);
    if (!(temp_r4 & 0x400)) {
        return *(u16 *)((u8 *)arg0 + 0x3AC);
    }
    *(s32 *)((u8 *)arg0 + 0x220) = temp_r4 & 0xFFFFFBFF;
    return fn_802601EC(arg0, (u8 *)arg0 + 0x38C, *(u8 *)((u8 *)arg0 + 0x121), *(u8 *)((u8 *)arg0 + 0x122));
}

s32 fn_8026095C(void *arg0)
{
    s32 fn_802601EC(void *, void *, u8, u8);
    u32 flags;

    flags = *(u32 *)((u8 *)arg0 + 0x220);

    if ((flags & 0x800) == 0) {
        return *(u16 *)((u8 *)arg0 + 0x3D0);
    }

    flags &= ~0x800;
    *(u32 *)((u8 *)arg0 + 0x220) = flags;

    return fn_802601EC(
        arg0,
        (u8 *)arg0 + 0x3B0,
        *(u8 *)((u8 *)arg0 + 0x121),
        *(u8 *)((u8 *)arg0 + 0x122)
    );
}

s32 fn_802609A4(void *arg0) {
    s32 fn_802601EC(void *, void *, u8, u8);
    s32 temp_r4;

    temp_r4 = *(s32 *)((u8 *)arg0 + 0x220);
    if (!(temp_r4 & 0x1000)) {
        return *(u16 *)((u8 *)arg0 + 0x3F4);
    }
    *(s32 *)((u8 *)arg0 + 0x220) = temp_r4 & 0xFFFFEFFF;
    return fn_802601EC(arg0, (u8 *)arg0 + 0x3D4, *(u8 *)((u8 *)arg0 + 0x121), *(u8 *)((u8 *)arg0 + 0x122));
}

s32 fn_802609EC(void *arg0)
{
    s32 fn_802601EC(void *, void *, u8, u8);
    u32 flags;

    flags = *(u32 *)((u8 *)arg0 + 0x220);

    if ((flags & 0x2000) == 0) {
        return *(u16 *)((u8 *)arg0 + 0x418);
    }

    flags &= ~0x2000;
    *(u32 *)((u8 *)arg0 + 0x220) = flags;

    return fn_802601EC(
        arg0,
        (u8 *)arg0 + 0x3f8,
        *(u8 *)((u8 *)arg0 + 0x121),
        *(u8 *)((u8 *)arg0 + 0x122)
    );
}

s32 fn_80260A34(void *arg0)
{
    s32 fn_802601EC(void *, void *, u8, u8);
    u32 flags;

    flags = *(u32 *)((u8 *)arg0 + 0x220);

    if ((flags & 0x4000) == 0) {
        return *(u16 *)((u8 *)arg0 + 0x43C);
    }

    flags &= ~0x4000;
    *(u32 *)((u8 *)arg0 + 0x220) = flags;

    return fn_802601EC(
        arg0,
        (u8 *)arg0 + 0x41C,
        *(u8 *)((u8 *)arg0 + 0x121),
        *(u8 *)((u8 *)arg0 + 0x122)
    );
}

s32 fn_80260A7C(u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
    extern u16 lbl_8035D118[256];
    extern u32 lbl_802A1E00[];
    extern u8 lbl_8034D034[];
    s32 fn_802601EC(void *, void *, u32, u32);
    u8 *row;
    u32 *entry;
    u32 mask;
    u32 value;
    u32 index;
    u32 result;

    index = arg1 & 0xFF;
    row = (u8 *)lbl_8035D118 + ((arg3 & 0xFF) << 6);
    mask = lbl_802A1E00[arg1 & 0xFF];
    entry = (u32 *)(row + ((arg2 & 0xFF) << 2));
    value = *entry;
    result = (mask & value) != 0;

    if (result != 0) {
        *entry = ~mask & value;
    }

    if (result != 0) {
        return fn_802601EC(
            0,
            lbl_8034D034 + (arg0 & 0xFF) * 0x90 + index * 0x24,
            arg2,
            arg3
        );
    }

    return *(u16 *)(
        lbl_8034D034
        + (arg0 & 0xFF) * 0x90
        + index * 0x24
        + 0x20
    );
}

static inline u32 Sound_TakeChannelFlag(u32 index, u32 channel, u32 set)
{
    extern u16 lbl_8035D118[256];
    extern u32 lbl_802A1E10[];
    u32 *row = (u32 *)((u8 *)lbl_8035D118 + ((set & 0xFF) << 6));
    u32 mask = lbl_802A1E10[index & 0xFF];
    u32 result = (mask & row[channel & 0xFF]) != 0;
    if (result) row[channel & 0xFF] &= ~mask;
    return result;
}

s32 fn_80260B30(u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
 s32 fn_802601EC(void *, void *, u32, u32);
 if(Sound_TakeChannelFlag(arg1,arg2,arg3))
  return fn_802601EC(0, lbl_8034CBB4 + (arg0&255)*0x90 + (arg1&255)*0x24,arg2,arg3);
 { u8 *base = lbl_8034CBB4; arg0 = (arg0&255)*0x90; return *(u16 *)(base + arg0 + (arg1&255)*0x24 + 0x20); }
}

void fn_80260BE4(u8 *arg0)
{
    extern u8 lbl_8034D034[];
    extern u8 lbl_8034CBB4[];
    extern s32 lbl_80368ACC;
    extern s32 lbl_80368AC8;

    s32 i;
    u32 *ptr;

    if (arg0 != 0) {
        arg0[0x224] = 7;
        arg0[0x225] = 0;
        *(u32 *)(arg0 + 0x228) = 1;
        arg0[0x22C] = 0x0B;
        arg0[0x22D] = 2;
        *(u32 *)(arg0 + 0x230) = 1;
        arg0[0x246] = 2;
        arg0[0x248] = 10;
        arg0[0x249] = 0;
        *(u32 *)(arg0 + 0x24C) = 1;
        arg0[0x26A] = 1;
        arg0[0x26C] = 0x83;
        arg0[0x26D] = 0;
        *(u32 *)(arg0 + 0x270) = 1;
        arg0[0x28E] = 1;
        arg0[0x290] = 0x80;
        arg0[0x291] = 0;
        *(u32 *)(arg0 + 0x294) = 1;
        arg0[0x2B2] = 1;
        arg0[0x2B4] = 0x84;
        arg0[0x2B5] = 0;
        *(u32 *)(arg0 + 0x2B8) = 1;
        arg0[0x2D6] = 1;
        arg0[0x2D8] = 1;
        arg0[0x2D9] = 0;
        *(u32 *)(arg0 + 0x2DC) = 1;
        arg0[0x2FA] = 1;
        arg0[0x2FC] = 0x40;
        arg0[0x2FD] = 0;
        *(u32 *)(arg0 + 0x300) = 1;
        arg0[0x31E] = 1;
        arg0[0x320] = 0x41;
        arg0[0x321] = 0;
        *(u32 *)(arg0 + 0x324) = 1;
        arg0[0x342] = 1;
        arg0[0x366] = 0;
        arg0[0x368] = 0x5B;
        arg0[0x369] = 0;
        *(u32 *)(arg0 + 0x36C) = 1;
        arg0[0x38A] = 1;
        arg0[0x3AE] = 0;
        arg0[0x3B0] = 0x5D;
        arg0[0x3B1] = 0;
        *(u32 *)(arg0 + 0x3B4) = 1;
        arg0[0x3D2] = 1;
        arg0[0x3F6] = 0;
        arg0[0x3F8] = 0x4F;
        arg0[0x3F9] = 0;
        *(u32 *)(arg0 + 0x3FC) = 1;
        arg0[0x41A] = 1;
        arg0[0x41C] = 0x1F;
        arg0[0x41D] = 0;
        *(u32 *)(arg0 + 0x420) = 1;
        arg0[0x43E] = 1;
        *(u32 *)(arg0 + 0x220) = 0x7FFF;
        arg0[0x1D8] = 0;
        arg0[0x1D9] = 0;
        arg0[0xA8] = 0;
    }

    for (i = 0; i < 2; i++) {
        for (ptr = (u32 *)(lbl_8034D034 + i * 0x240 + 0x22);
             (u8 *)ptr < lbl_8034D034 + i * 0x240 + 0x240;
             ptr = (u32 *)((u8 *)ptr + 0x24)) {
            *(u8 *)ptr = 0;
        }
        for (ptr = (u32 *)(lbl_8034CBB4 + i * 0x240 + 0x22);
             (u8 *)ptr < lbl_8034CBB4 + i * 0x240 + 0x240;
             ptr = (u32 *)((u8 *)ptr + 0x24)) {
            *(u8 *)ptr = 0;
        }
    }

    for (i = 0; i < 4; i++) {
        ptr = (u32 *)((u8 *)lbl_8035D118 + i * 0x40);
        ptr[0] = 0xFF;
        ptr[1] = 0xFF;
        ptr[2] = 0xFF;
        ptr[3] = 0xFF;
        ptr[4] = 0xFF;
        ptr[5] = 0xFF;
        ptr[6] = 0xFF;
        ptr[7] = 0xFF;
        ptr[8] = 0xFF;
        ptr[9] = 0xFF;
        ptr[10] = 0xFF;
        ptr[11] = 0xFF;
        ptr[12] = 0xFF;
        ptr[13] = 0xFF;
        ptr[14] = 0xFF;
        ptr[15] = 0xFF;
    }

    lbl_80368ACC = 0x50;
    lbl_80368AC8 = 0x3E80;
}

s32 fn_80260EA8(s32 arg0) {
    switch ((u8)arg0) {
    case 0x80:
        return 0x80;
    case 0x81:
        return 0x82;
    case 0x82:
        return 0xA0;
    case 0x83:
        return 0xA1;
    case 0x84:
        return 0x83;
    case 0x85:
        return 0x84;
    case 0x86:
        return 0xA2;
    case 0x87:
        return 0xA3;
    case 0x88:
        return 0xA4;
    default:
        return arg0;
    }
}

u16 fn_80260F18(void *arg0, s32 arg1) {
u32 Sound_GetChanParam(s32, u8, u8);
s32 mapped=arg1;
u32 result;
switch ((u8)arg1) {
case 128: mapped=128; break;
case 129: mapped=130; break;
case 130: mapped=160; break;
case 131: mapped=161; break;
case 132: mapped=131; break;
case 133: mapped=132; break;
case 134: mapped=162; break;
case 135: mapped=163; break;
case 136: mapped=164; break;
}
switch ((u8)mapped) {
case 0xa0: return (u16)((*(s16 *)((u8 *)arg0+0x1c8)<<1)+0x2000);
case 0xa1: return (u16)((*(s16 *)((u8 *)arg0+0x1d4)<<1)+0x2000);
default:
if (((u8 *)arg0)[0x121]!=0xff) result=(u16)Sound_GetChanParam(arg1,((u8 *)arg0)[0x121],((u8 *)arg0)[0x122]);
else result=0;
return result;
}
}

#pragma dont_inline on
void fn_80261014(SynthVmState *arg0, s32 arg1, s32 arg2) {
 void Sound_WriteParamU8(u8,u8,u8,u8);
 u32 bank,channel;
 u16 v;
 u32 a,b,c;
 u32 param;
 s32 mapped;
 if((s16)arg2<0) arg2=0; else arg2=(s16)arg2>0x3FFF?0x3FFF:(s16)arg2;
 arg2=(s16)arg2;
 param=(u8)arg1;
 mapped=arg1;
 switch(param) {
 case 128:mapped=128;break;case 129:mapped=130;break;
 case 130:mapped=160;break;case 131:mapped=161;break;
 case 132:mapped=131;break;case 133:mapped=132;break;
 case 134:mapped=162;break;case 135:mapped=163;break;
 case 136:mapped=164;break;
 }
 switch((u8)mapped) {case 160:case 161:break;default:
 channel=((u8*)arg0)[0x121];
 if(channel!=255) {
 bank=((u8*)arg0)[0x122];
 if(channel!=255) {
 if((u8)arg1<0x40U) {v=arg2;a=param&31;Sound_WriteParamU8(a,channel,bank,(u8)(v>>7));Sound_WriteParamU8((u8)(a+32),channel,bank,v&127);}
 else if((u8)arg1==128||(u8)arg1==129) {v=arg2;b=param&254;Sound_WriteParamU8(b,channel,bank,(u8)(v>>7));Sound_WriteParamU8((u8)(b+1),channel,bank,v&127);}
 else if((u8)arg1==132||(u8)arg1==133) {v=arg2;c=param&254;Sound_WriteParamU8(c,channel,bank,(u8)(v>>7));Sound_WriteParamU8((u8)(c+1),channel,bank,v&127);}
 else Sound_WriteParamU8(arg1,channel,bank,(u8)((u16)arg2>>7));
 }
 }
 }
}
#pragma dont_inline reset
u16 fn_802611F8(void) {
    extern u32 lbl_803670B8;
    u32 temp_r0;

    temp_r0 = lbl_803670B8 * 0xA8351D63;
    lbl_803670B8 = temp_r0;
    return (u16) (temp_r0 >> 6U);
}

s16 fn_80261214(s32 arg0) {
    u32 temp_r0;
    s16 *ptr;

    temp_r0 = arg0 & 0xFFF;
    if (temp_r0 < 0x400U) {
        ptr = (s16*)((char*)lbl_802A1E90 + ((temp_r0 * 2) & 0x1FFFE));
        return *ptr;
    }
    if (temp_r0 < 0x800U) {
        ptr = (s16*)((char*)lbl_802A1E90 + ((0x3FF - (temp_r0 & 0x3FF)) * 2));
        return *ptr;
    }
    if (temp_r0 < 0xC00U) {
        ptr = (s16*)((char*)lbl_802A1E90 + ((temp_r0 * 2) & 0x7FE));
        return -(*ptr);
    }
    ptr = (s16*)((char*)lbl_802A1E90 + ((0x3FF - (temp_r0 & 0x3FF)) * 2));
    return -(*ptr);
}

void *Bsearch(void *key, void *base, s32 count, s32 stride, s32 (*cmp)(void *, void *)) {
    s32 low;
    s32 high;
    s32 mid;
    void *ptr;
    s32 result;

    if (count != 0) {
        low = 1;
        high = count;
        do {
            mid = (low + high) >> 1;
            ptr = (u8 *)base + (stride * (mid - 1));
            result = cmp(key, ptr);
            if (result == 0) {
                return ptr;
            }
            if (result < 0) {
                high = mid - 1;
            }
            if (((u32)result >> 31) == 0) {
                low = mid + 1;
            }
        } while (low <= high);
    }
    return NULL;
}

#pragma fp_contract on
#pragma opt_lifetimes off
#pragma scheduling off
#pragma opt_common_subs off
f64 fn_80261344(f32 x) {
    f64 three;
    f64 half;
    f64 guess;
    f64 square;
    f64 zero;
    zero = *(f32 *)0x802831B8;
    three = *(f32 *)0x802831B0;
    half = *(f32 *)0x802831B4;
    guess = __frsqrte(x);
    if (!(x > (f32)zero || x < (f32)zero))
        return x;
    square = guess * guess;
    guess = guess * half;
    square = three - x * square;
    guess = guess * square;
    square = guess * guess;
    guess = guess * half;
    square = three - x * square;
    guess = guess * square;
    square = guess * guess;
    guess = guess * half;
    square = three - x * square;
    guess = guess * square;
    return x * guess;
}
#pragma opt_common_subs reset
#pragma scheduling reset
#pragma opt_lifetimes reset
#pragma fp_contract off
f32 fn_80261398(f32 x) {
    extern f32 lbl_802831BC[];
    return x * lbl_802831BC[3];
}

void fn_8026146C(s32 *arg0) {
    *arg0 <<= 8;
}

void fn_8026147C(u32 *arg0, s32 arg1) {
    u32 fn_80247F60(s32);
    *arg0 = (u32) (((u32) (*arg0 << 0x10) / fn_80247F60(arg1)) * 0x3E8) >> 5U;
}

u32 fn_802614C4(u32 arg0) {
    return arg0 >> 8U;
}

void fn_802614CC(void) {
    extern u8 gSoundReady;
    extern u8 gSoundVoiceCount;
    extern u8 lbl_80368AD3;
    extern u8 lbl_80368AD4;
    extern u32 gSoundVoices;
    void fn_8024C5C8(void);
    void fn_80263764(void);
    void fn_80263504(void);
    void fn_80263608(void);
    void fn_80263784(void);
    void fn_8025CAE0(void);
    void fn_802616E4(s32);
    void fn_80247358(s32);
    void fn_80249E3C(s32);
    void fn_8025E4E8(void);
    void fn_8024BCE4(void);
    void fn_80258888(void);

    u8 i;
    s32 next;
    u8 ad4;
    u32 zero;
    s32 j;
    u32 off;

    if (gSoundReady != 0) {
        fn_8024C5C8();
        fn_80263764();
        fn_80263504();
        fn_80263608();
        fn_80263784();
        fn_80263764();
        fn_8025CAE0();
        fn_80263784();
        fn_80263764();

        i = 0;
        next = lbl_80368AD3 + 1;
        ad4 = lbl_80368AD4;
        zero = 0;
        lbl_80368AD4 = ad4 ^ 1;
        lbl_80368AD3 = (u8)(next % 3);

        while (i < gSoundVoiceCount) {
            off = i * 0xF8 + 0x24;
            *(u32 *)((u8 *)gSoundVoices + off) = zero;
            *(u32 *)((u8 *)gSoundVoices + off + 4) = zero;
            *(u32 *)((u8 *)gSoundVoices + off + 8) = zero;
            *(u32 *)((u8 *)gSoundVoices + off + 0xC) = zero;
            *(u32 *)((u8 *)gSoundVoices + off + 0x10) = zero;
            i += 1;
        }

        fn_80263784();

        j = 0;
        goto loop2_test;
    loop2_body:
        fn_80263764();
        fn_802616E4(j);
        fn_80247358(0x100);
        fn_80249E3C(0x100);
        fn_80263784();
        j += 1;
    loop2_test:
        if ((u8)j < 5) {
            goto loop2_body;
        }

        fn_80263764();
        fn_802616E4(0);
        fn_8025E4E8();
        fn_80263784();

        fn_80263764();
        fn_8024BCE4();
        fn_80263784();

        fn_80263764();
        fn_80258888();
        fn_80263784();
    }
}

s32 fn_80261620(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 fn_802636C8(void);
    s32 fn_8026341C(void (*)(void), s32, s32);
    s32 Sound_InitVoices(u8, u8, u32);
    void fn_80262504(void);
    s32 fn_80263534(s32);
    void Audio_Unlock(void);
    void fn_802634E4(void);
    extern void fn_802614CC(void);
    extern u8 lbl_80368AD4;
    extern u8 lbl_80368AD3;
    extern u32 lbl_80368AA4;
    s32 a0 = arg0;
    s32 a1 = arg1;
    s32 a2 = arg2;
    s32 a3 = arg3;
    s32 t;

    fn_802636C8();
    lbl_80368AD4 = 0;
    t = 0;
    lbl_80368AD3 = t;
    lbl_80368AA4 = t;

    if ((u32)fn_8026341C(fn_802614CC, a3, a0) == 0) {
        goto error;
    }
    t = a3 & 1;
    a1 = (u8)a1;
    a2 = (u8)a2;
    if ((u32)Sound_InitVoices(a1, a2, t) == 0) {
        goto error;
    }
    if (a3 & 8) {
        fn_80262504();
    }
    if ((u32)fn_80263534(a3) == 0) {
        goto error;
    }
    Audio_Unlock();
    fn_802634E4();
    return 0;
error:
    return -1;
}

int fn_802616E4(int arg0) {
    extern s8 lbl_80368AD0;
    lbl_80368AD0 = arg0;
}

u8 fn_802616EC(void) {
    extern u8 lbl_80368AD0;
    return lbl_80368AD0;
}

s32 Sound_IsHwVoiceActive(s32 arg0) {
    typedef struct {
        u8 pad[0xF0];
        u8 unkF0;
        u8 pad2[0xF8 - 0xF1];
    } Entry;
    extern Entry *gSoundVoices;

    return gSoundVoices[arg0].unkF0 != 0;
}

void fn_80261714(s32 arg0) {
    extern s32 lbl_80368AA4;
    lbl_80368AA4 = arg0;
}

void fn_8026171C(s32 arg0, s32 arg1) {
    typedef struct {
        u8 pad[0x1C];
        s32 unk1C;
        u8 pad2[0xF8 - 0x20];
    } Entry;
    extern Entry *gSoundVoices;

    gSoundVoices[arg0].unk1C = arg1;
}

void fn_80261730(u8 arg0, u16 arg1, void *arg2, u32 arg3,
                 u32 arg4, u32 arg5, u32 arg6, u32 arg7)
{
    extern u8 *gSoundVoices;
    extern u8 lbl_80368AD0;

    extern void fn_80261C40();
    extern void fn_80261C6C();
    extern void fn_80261E10();

    u8 *entry;
    u32 offset;
    u32 flags;
    u32 index;
    u32 i;

    offset = arg0 * 0xF8;
    flags = 0;

    for (index = 0; index <= lbl_80368AD0; index++) {
        entry = gSoundVoices + offset;

        flags |= *(u32 *)(entry + 0x24 + index * 4) & 0x20;
        *(u32 *)(entry + 0x24 + index * 4) = 0;
    }

    entry = gSoundVoices + offset;
    *(u32 *)(entry + 0x24) = flags;

    entry = gSoundVoices + offset;
    *(u32 *)(entry + 0x1C) = arg4;

    entry = gSoundVoices + offset;
    *(u32 *)(entry + 0x18) = arg5;

    entry = gSoundVoices + offset;
    *(u32 *)(entry + 0xF4) = 0;

    entry = gSoundVoices + offset;
    *(u16 *)(entry + 0x70) = arg1;

    entry = gSoundVoices + offset;

    for (i = 0; i < 8; i++) {
        *(u32 *)(entry + 0x74 + i * 4) =
            *(u32 *)((u8 *)arg2 + i * 4);
    }

    if (arg3 != 0) {
        entry = gSoundVoices + offset;
        *(u8 *)(entry + 0xA4) = 0;

        entry = gSoundVoices + offset;
        *(u32 *)(entry + 0xB8) = 0;

        entry = gSoundVoices + offset;
        *(u32 *)(entry + 0xBC) = 0;

        entry = gSoundVoices + offset;
        *(u16 *)(entry + 0xC0) = 0x7FFF;

        entry = gSoundVoices + offset;
        *(u32 *)(entry + 0xC4) = 0;

        entry = gSoundVoices + offset;
        *(u8 *)(entry + 0xE8) = 0xFF;

        entry = gSoundVoices + offset;
        *(u8 *)(entry + 0xE9) = 0xFF;

        entry = gSoundVoices + offset;
        *(u8 *)(entry + 0xEA) = 0xFF;

        entry = gSoundVoices + offset;
        *(u8 *)(entry + 0xEB) = 0xFF;
    }

    if (arg6 != 0) {
        fn_80261C40(arg0, 0);
        fn_80261C6C(arg0, 1);
        fn_80261E10(arg0, arg7);
    }
}

#pragma peephole off
void fn_802618E4(s32 arg0)
{
    extern u8 *lbl_80368AA0;
    extern u8 lbl_80368AD0;
    u8 *object;
    u8 *q;
    s32 off;

    off = arg0 * 0xF8;
    object = lbl_80368AA0 + off;

    if (object[0xF0] != 1 || lbl_80368AD0 != 0) {
        goto end;
    }
    object[0xF2] = 1;
    q = lbl_80368AA0;
    q = q + off;
    q = q + (lbl_80368AD0 << 2);
    *(u32 *)(q + 0x24) |= 0x20;
end:
    return;
}
#pragma peephole on
void Sound_SetVoiceEnvelope(u8 arg0, void *arg1, s32 arg2)
{
    extern u8 *gSoundVoices;
    extern u8 gSoundLevelCurve[];
    extern u32 fn_80257940(u32);

    u8 *entry;
    u8 *data;
    u32 value;
    u32 index;

    data = (u8 *)arg1;
    entry = gSoundVoices + (arg0 * 0xF8);

    switch ((u8)arg2) {
    case 0:
        *(u8 *)(entry + 0xA4) = 0;

        *(u32 *)(entry + 0xB8) = *(u16 *)(data + 0x00);
        *(u32 *)(entry + 0xBC) = *(u16 *)(data + 0x02);

        value = *(u16 *)(data + 0x04) << 3;

        if (value > 0x7FFF) {
            value = 0x7FFF;
        }

        *(u16 *)(entry + 0xC0) = value;
        *(u32 *)(entry + 0xC4) = *(u16 *)(data + 0x06);
        break;

    case 1:
        *(u8 *)(entry + 0xA4) = 1;
        *(u8 *)(entry + 0xCA) = 0;

        value = *(u32 *)(data + 0x00);
        *(u32 *)(entry + 0xB8) = (u16)fn_80257940(value);

        value = *(u32 *)(data + 0x04);
        *(u32 *)(entry + 0xBC) = (u16)fn_80257940(value);

        index = *(u16 *)(data + 0x08) >> 2;

        if (index > 0x3FF) {
            index = 0x3FF;
        }

        value = gSoundLevelCurve[index];
        *(u16 *)(entry + 0xC0) = 0xC1 - value;
        break;

    case 2:
        *(u8 *)(entry + 0xA4) = 1;
        *(u8 *)(entry + 0xCA) = 0;

        *(u32 *)(entry + 0xB8) =
            *(u32 *)(data + 0x00) & 0xFFFF;

        *(u32 *)(entry + 0xBC) =
            *(u32 *)(data + 0x04) & 0xFFFF;

        *(u16 *)(entry + 0xC0) = *(u16 *)(data + 0x08);
        *(u32 *)(entry + 0xC4) = *(u16 *)(data + 0x0A);
        break;

    default:
        return;
    }

    *(u32 *)(entry + 0x24) |= 0x10;
}

void Sound_SetVoiceStreamParams(s32 arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad[0x94];
        s32 unk94;
        s32 unk98;
        u8 pad2[0xF8 - 0x9C];
    } Entry;
    extern Entry *gSoundVoices;

    gSoundVoices[arg0].unk94 = arg1;
    gSoundVoices[arg0].unk98 = arg2;
}

u8 fn_80261B00(s32 arg0) {
    typedef struct {
        u8 pad[0x9C];
        u8 unk9C;
        u8 pad2[0xF8 - 0x9D];
    } Entry;
    extern Entry *gSoundVoices;

    return gSoundVoices[arg0].unk9C;
}

u8 fn_80261B14(s32 arg0) {
    typedef struct {
        u8 pad[0x90];
        u8 unk90;
        u8 pad2[0xF8 - 0x91];
    } Entry;
    extern Entry *gSoundVoices;

    return gSoundVoices[arg0].unk90;
}

u16 fn_80261B28(s32 arg0) {
    typedef struct {
        u8 pad[0x70];
        u16 unk70;
        u8 pad2[0xF8 - 0x72];
    } Entry;
    extern Entry *gSoundVoices;

    return gSoundVoices[arg0].unk70;
}

s32 fn_80261B3C(s32 arg0) {
    typedef struct {
        u8 pad[0x7C];
        s32 unk7C;
        u8 pad2[0xF8 - 0x80];
    } Entry;
    extern Entry *gSoundVoices;

    return gSoundVoices[arg0].unk7C;
}

void fn_80261B50(s32 arg0, s8 arg1) {
    typedef struct {
        u8 pad[0xA0];
        s8 unkA0;
        u8 pad2[0xF8 - 0xA1];
    } Entry;
    extern Entry *gSoundVoices;

    gSoundVoices[arg0].unkA0 = arg1;
}

void fn_80261B64(s32 arg0, s32 arg1)
{
    extern void fn_8025C9E0(void *, s32);
    typedef struct { u8 pad[0xF8]; } Voice;
    extern Voice *gSoundVoices;
    extern u8 lbl_80368AD0;

    gSoundVoices[arg0].pad[0xDA] = lbl_80368AD0;
    fn_8025C9E0(&gSoundVoices[arg0], arg1);
}

void fn_80261BA0(s32 arg0) {
    extern u8 *gSoundVoices;
    extern u8 lbl_80368AD0;

    u8 *ptr;
    u32 index;
    u32 value;

    ptr = gSoundVoices + (arg0 * 0xF8);
    index = lbl_80368AD0 * 4;
    ptr += index;

    value = *(u32 *)(ptr + 0x24);
    value |= 0x40;
    *(u32 *)(ptr + 0x24) = value;
}

void fn_80261BC8(s32 arg0, u16 arg1)
{
  extern u8 *gSoundVoices;
  extern u8 lbl_80368AD0;
  u8 *entry;
  u8 *p;
  int new_var;
  u8 index;
  entry = gSoundVoices + (arg0 * 0xF8);
  if (arg1 >= 0x4000)
  {
    arg1 = 0x3FFF;
  }
  index = *((u8 *) (entry + 0xE8));
  if (index != 0xFF)
  {
    p = entry + (index << 2);
    new_var = 0x38;
    index = ((u32) arg1) << 4;
    if ((*((u32 *) (p + new_var))) == index)
    {
      return;
    }
  }
  p = entry + (lbl_80368AD0 << 2);
  *((u32 *) (p + 0x38)) = index;
  p = entry + (lbl_80368AD0 << 2);
  *((u32 *) (p + 0x24)) = (*((u32 *) (p + 0x24))) | 8;
  *((u8 *) (entry + 0xE8)) = lbl_80368AD0;
}

void fn_80261C40(s32 arg0, s32 arg1) {
    typedef struct {
        u8 pad[0x24];
        u32 unk24;
        u8 pad2[0xCC - 0x28];
        u16 unkCC;
        u8 pad3[0xF8 - 0xCE];
    } Entry;
    extern Entry *gSoundVoices;
    extern u16 lbl_803670C0;
    Entry *e;

    e = &gSoundVoices[arg0];
    e->unkCC = ((u16 *)&lbl_803670C0)[arg1 & 0xFF];
    e->unk24 |= 0x100;
}

void fn_80261C6C(s32 arg0, s32 arg1) {
    typedef struct {
        u8 pad[0x24];
        u32 unk24;
        u8 pad2[0xCE - 0x28];
        u16 unkCE;
        u8 pad3[0xF8 - 0xD0];
    } Entry;
    extern Entry *gSoundVoices;
    extern u32 lbl_803670C8;
    Entry *e;

    e = &gSoundVoices[arg0];
    e->unkCE = ((u16 *)&lbl_803670C8)[arg1 & 0xFF];
    e->unk24 |= 0x80;
}

void fn_80261C98(u32 arg0, s16 *arg1, s16 *arg2) {
f32 fn_80261398(f32); f32 fn_80261344(f32);
extern f32 lbl_8036C354;
f32 a,b,c; s16 x,y;
a=2.0f-fn_80261398(lbl_8036C354*(f32)arg0/32000.0f);
if(a>1.0f) b=fn_80261344(a*a-1.0f)-a; else b=-1.0f;
c=b>1.0f?1.0f:b<-1.0f?-1.0f:b;
x=32768.0f*(1.0f+c);
y=32768.0f*-c;
*arg1=x; *arg2=y;
}

void fn_80261D90(s32 arg0, u8 arg1, u16 arg2, u16 arg3)
{
    extern u8 *gSoundVoices;

    u8 *entry;

    entry = gSoundVoices + (arg0 * 0xF8);

    if (*(u8 *)(entry + 0xD4) == 0) {
        if (arg1 != 1) {
            return;
        }

        *(u8 *)(entry + 0xD4) = 1;
        *(u16 *)(entry + 0xD6) = arg2;
        *(u16 *)(entry + 0xD8) = arg3;
        *(u32 *)(entry + 0x24) |= 0xC00;
    } else {
        if (arg1 == 1) {
            *(u16 *)(entry + 0xD6) = arg2;
            *(u16 *)(entry + 0xD8) = arg3;
            *(u32 *)(entry + 0x24) |= 0x800;
        } else {
            *(u8 *)(entry + 0xD4) = 0;
            *(u32 *)(entry + 0x24) |= 0x400;
        }
    }
}

#pragma global_optimizer off
void fn_80261E10(s32 arg0, u8 arg1) {
extern u8 *gSoundVoices;
u8 *entry; u16 ten; s32 offset;
if(arg1==0) {
offset=arg0*0xF8; ten=0x10;
entry=gSoundVoices+offset; *(u32 *)(entry+0xF4)|=0x80000000;
entry=gSoundVoices+offset; *(u16 *)(entry+0xD0)=ten;
entry=gSoundVoices+offset; *(u16 *)(entry+0xD2)=ten;
} else { entry=gSoundVoices+arg0*0xF8; *(u32 *)(entry+0xF4)&=0x7FFFFFFF; }
}
#pragma global_optimizer reset
void fn_80261E6C(s32 arg0, s32 arg1, s32 arg2,
                 f32 arg3, f32 arg4, f32 arg5)
{
    extern u8 *gSoundVoices;
    extern u8 gSoundStudios[];
    extern u16 lbl_802831E0[];
    extern const f32 lbl_8036C35C;
    extern const f32 lbl_8036C370;

    extern void fn_8025CC38();

    u8 *entry;
    u8 *table;
    f32 values[9];
    u32 flags;
    u32 index;
    u32 value;
    u32 sign;
    u32 option;
    s32 x;
    s32 y;
    s32 z;

    entry = gSoundVoices + arg0 * 0xF8;

    if (arg3 >= lbl_8036C35C) {
        arg3 = lbl_8036C35C;
    }
    if (arg4 >= lbl_8036C35C) {
        arg4 = lbl_8036C35C;
    }
    if (arg5 >= lbl_8036C35C) {
        arg5 = lbl_8036C35C;
    }

    index = *(u8 *)(entry + 0xF3);
    flags = *(u32 *)(entry + 0xF4);

    table = gSoundStudios + index * 0xBC;

    sign = flags >> 31;
    option = (*(u32 *)(table + 0x54) == 1);

    fn_8025CC38(arg1, values, arg2, 0, sign, option,
                  arg3, arg4, arg5);

    x = (s32)(lbl_8036C370 * values[0]);
    y = (s32)(lbl_8036C370 * values[1]);
    z = (s32)(lbl_8036C370 * values[2]);

    if (*(u8 *)(entry + 0xE9) == 0xFF ||
        *(u16 *)(entry + 0x4C) != (u16)x ||
        *(u16 *)(entry + 0x4E) != (u16)y ||
        *(u16 *)(entry + 0x50) != (u16)z) {

        *(u16 *)(entry + 0x4C) = (u16)x;
        *(u16 *)(entry + 0x4E) = (u16)y;
        *(u16 *)(entry + 0x50) = (u16)z;

        *(u32 *)(entry + 0x24) |= 1;
        *(u8 *)(entry + 0xE9) = 0;
    }

    x = (s32)(lbl_8036C370 * values[3]);
    y = (s32)(lbl_8036C370 * values[4]);
    z = (s32)(lbl_8036C370 * values[5]);

    if (*(u8 *)(entry + 0xEA) == 0xFF ||
        *(u16 *)(entry + 0x52) != (u16)x ||
        *(u16 *)(entry + 0x54) != (u16)y ||
        *(u16 *)(entry + 0x56) != (u16)z) {

        *(u16 *)(entry + 0x52) = (u16)x;
        *(u16 *)(entry + 0x54) = (u16)y;
        *(u16 *)(entry + 0x56) = (u16)z;

        *(u32 *)(entry + 0x24) |= 2;
        *(u8 *)(entry + 0xEA) = 0;
    }

    x = (s32)(lbl_8036C370 * values[6]);
    y = (s32)(lbl_8036C370 * values[7]);
    z = (s32)(lbl_8036C370 * values[8]);

    if (*(u8 *)(entry + 0xEB) == 0xFF ||
        *(u16 *)(entry + 0x58) != (u16)x ||
        *(u16 *)(entry + 0x5A) != (u16)y ||
        *(u16 *)(entry + 0x5C) != (u16)z) {

        *(u16 *)(entry + 0x58) = (u16)x;
        *(u16 *)(entry + 0x5A) = (u16)y;
        *(u16 *)(entry + 0x5C) = (u16)z;

        *(u32 *)(entry + 0x24) |= 4;
        *(u8 *)(entry + 0xEB) = 0;
    }

    if (*(u32 *)(entry + 0xF4) & 0x80000000) {
        index = __rlwinm((u32)arg2, 17, 23, 30);

        value = *(u16 *)((u8 *)lbl_802831E0 + index);

        *(u16 *)(entry + 0xD0) = (u16)value;
        *(u16 *)(entry + 0xD2) = (u16)(0x20 - value);

        *(u32 *)(entry + 0x24) |= 0x200;
    }
}

void fn_8026212C(u8 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    extern u16 gSoundStudios[];
    void *temp_r3;

    temp_r3 = (char *)gSoundStudios + (arg0 * 0xBC);
    *(s32 *)((char *)temp_r3 + 0xAC) = arg1;
    *(s32 *)((char *)temp_r3 + 0xB4) = arg2;
    *(s32 *)((char *)temp_r3 + 0xB0) = arg3;
    *(s32 *)((char *)temp_r3 + 0xB8) = arg4;
}

u32 fn_80262154(u32 arg0)
{
    extern u8 *gSoundVoices;
    u8 *voices;
    u8 *entry;
    u32 value;
    u32 count;
    u32 remainder;

    voices = gSoundVoices;
    entry = arg0 * 0xF8 + voices;

    if (*(u8 *)(entry + 0xF0) != 2) {
        return 0;
    }

    switch (*(u8 *)(entry + 0x90)) {
    case 0:
    case 1:
    case 4:
    case 5:
        entry = arg0 * 0xF8 + voices;
        count = *(u32 *)(entry + 0x78);
        value = *(u32 *)(entry + 0x20);
        remainder = value & 0xF;
        value = ((value - (count * 2)) >> 4) * 14;
        if (remainder >= 2) {
            value = remainder + value;
            value = value - 2;
        }
        return value;

    case 3:
        count = *(u32 *)(entry + 0x78);
        value = *(u32 *)(entry + 0x20);
        return value - count;

    case 2:
    case 6:
        entry = arg0 * 0xF8 + voices;
        count = *(u32 *)(entry + 0x78);
        value = *(u32 *)(entry + 0x20);
        return value - (count >> 1);

    default:
        return arg0;
    }
}

void fn_80262200(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void fn_80205110(s32, s32);
    void Sound_QueueAramDma(s32, s32, s32, s32, s32, s32);
    s32 fn_802631AC(s32, s32 *);
    s32 sp8;
    s32 fnResult;
    s32 aligned;
    s32 off;

    fnResult = fn_802631AC(arg3, &sp8);
    off = arg1;
    aligned = off & ~0x1F;
    arg2 += off & 0x1F;
    off = arg0 + aligned;
    arg2 = (arg2 + 0x1F) & ~0x1F;
    fn_80205110(off, arg2);
    Sound_QueueAramDma(off, fnResult + aligned, arg2, 1, arg4, arg5);
}

u32 fn_80262290(s32 arg0) {
    u32 fn_80263074(s32);
    return fn_80263074(arg0);
}

void fn_802622B0(void) {
    M2C_UNK fn_802631E4();
    fn_802631E4();
}

void fn_802622D0(s32 arg0) {
    void fn_802631AC(s32, s32);
    fn_802631AC(arg0, 0);
}

void fn_802622F4(void) {

}

u32 fn_802622F8(u32 arg0) {
    extern u8 gSoundData[];
    extern f32 lbl_8036C374;

    return (u32)((lbl_8036C374 * (f32)arg0) / (f32)*(u32 *)gSoundData);
}

void fn_80262354(void *arg0, void *arg1) {
    void fn_802627EC(void *);
    fn_802627EC(arg1);
}

void fn_80262378(void **arg0, s32 *arg1, void *arg2) {
    s32 fn_80262B74(s32, s32, void *);
    u32 temp_r3;
    u32 temp_r0;
    u32 var_r4;

    temp_r3 = *(u32 *)((u8 *)*arg0 + 4);
    temp_r0 = temp_r3 >> 24;
    var_r4 = temp_r3 & 0xFFFFFF;
    switch ((s32)temp_r0) {
    case 0:
    case 1:
    case 4:
    case 5:
        var_r4 = (((var_r4 + 0xD) / 7u) << 2) & ~7u;
        break;
    case 2:
    case 6:
        var_r4 *= 2;
        break;
    }
    *arg1 = fn_80262B74(*arg1, (s32)var_r4, arg2);
}

void fn_80262410(void) {
    M2C_UNK fn_80262B1C();
    fn_80262B1C();
}

void fn_80262430(void *arg0, s32 arg1, void *arg2) {
 void fn_80262F98(s32,s32,void*);
 u32 temp_r3; u32 temp_r0; u32 var_r6;
 temp_r3=*(u32*)((u8*)arg0+4);
 temp_r0=temp_r3>>24;
 var_r6=temp_r3&0xFFFFFF;
 switch((s32)temp_r0) {
 case 0: case 1: case 4: case 5: var_r6=(((var_r6+13)/7u)<<2)&~7u; break;
 case 2: case 6: var_r6*=2; break;
 }
 fn_80262F98(arg1,(s32)var_r6,arg2);
}

void fn_802624B8(void) {
    M2C_UNK fn_802627D4();
    fn_802627D4();
}

void fn_802624D8(void) {

}

void fn_802624DC(void *arg0) {
    extern s32 lbl_80363F18[];
    s32 temp_r0;

    temp_r0 = *(s32 *)arg0;
    lbl_80363F18[0] = temp_r0;
    lbl_80363F18[1] = temp_r0;
    lbl_80363F18[2] = *(s32 *)((u8 *)arg0 + 4);
}

void fn_802624F8(void) {
    extern s32 lbl_80368A90;
    lbl_80368A90 = 0;
}

int fn_80262504(void) {
    extern s32 lbl_80368A8C;
    lbl_80368A8C = 1;
}

int fn_80262510(int arg0) {
    extern u8 *gSoundVoices;
    u8 *ptr;

    ptr = gSoundVoices + (arg0 * 0xF8);

    if (ptr[0xF0] == 0) {
        return -1;
    }

    return *(int *)(ptr + 0xEC);
}

s32 fn_80262538(s32 arg0) {
    typedef struct {
        u8 pad[0xF0];
        u8 unkF0;
        u8 pad2[0xF8 - 0xF1];
    } Entry;
    extern Entry *gSoundVoices;

    return gSoundVoices[arg0].unkF0 == 1;
}

void Sound_AramDmaCallback(void *arg0) {
    extern u8 gSoundAramQueue[0x284];
    extern u8 gSoundAramQueueHi[0x284];
    u8 *base;
    u8 *ptr;
    u32 count;

    if (*(u32 *)((char *)arg0 + 0xC) == 1) {
        base = gSoundAramQueueHi;
    } else {
        base = gSoundAramQueue;
    }

    count = 0;
    ptr = base;
    do {
        if (arg0 == ptr) {
            void (*func)(s32) = *(void (**)(s32))(ptr + 0x20);
            if (func != NULL) {
                func(*(s32 *)(ptr + 0x24));
            }
        }
        count += 1;
        ptr += 0x28;
    } while (count < 0x10);

    *(u8 *)(base + 0x281) -= 1;
}

/* Queue an MRAM→ARAM DMA on the low or high sound queue and post it to ARQ. */
void Sound_QueueAramDma(s32 mramAddr, s32 aramAddr, s32 length, s32 useHiQueue, s32 userCb, s32 userArg) {
    BOOL OSDisableInterrupts(void);
    void OSRestoreInterrupts(BOOL);
    void ARQPostRequest(void *, s32, s32, s32, s32, void *, s32, void *);
    void Sound_AramDmaCallback(void *);
    extern u8 gSoundAramQueue[];
    extern u8 gSoundAramQueueHi[];
    SoundAramDmaQueue *queue;
    BOOL enabled;
    s32 priority;
    s32 next;

    queue = useHiQueue != 0 ? (SoundAramDmaQueue *)gSoundAramQueueHi : (SoundAramDmaQueue *)gSoundAramQueue;

start:
    enabled = OSDisableInterrupts();
    if (queue->count < 0x10) {
        next = queue->next;
        queue->slots[next].owner = 0x2A;
        priority = useHiQueue ? 1 : 0;
        queue->slots[queue->next].type = 0;
        queue->slots[queue->next].priority = priority;
        queue->slots[queue->next].mramAddr = mramAddr;
        queue->slots[queue->next].aramAddr = aramAddr;
        queue->slots[queue->next].length = length;
        queue->slots[queue->next].callback = (void *)Sound_AramDmaCallback;
        queue->slots[queue->next].userCb = userCb;
        queue->slots[queue->next].userArg = userArg;

        ARQPostRequest(
            &queue->slots[queue->next],
            queue->slots[queue->next].owner,
            queue->slots[queue->next].type,
            queue->slots[queue->next].priority,
            queue->slots[queue->next].mramAddr,
            (void *)queue->slots[queue->next].aramAddr,
            queue->slots[queue->next].length,
            queue->slots[queue->next].callback);

        queue->count = (u8)(queue->count + 1);
        queue->next = (u8)(((s32)queue->next + 1) % 16);
        OSRestoreInterrupts(enabled);
        return;
    }
    OSRestoreInterrupts(enabled);
    goto start;
}

void fn_802627D4(void) {
    extern u8 gSoundAramQueue[];
    typedef struct {
        u8 pad[0x280];
        volatile u8 next;
        volatile u8 count;
    } Queue;
    Queue *q = (Queue *)gSoundAramQueue;
    while (q->count != 0) {
    }
}

void fn_802627EC(u32 arg0)
{
    extern u8 gSoundAramQueue[];
    extern u8 gSoundAramQueueHi[];

    extern u32 lbl_80368AF0;
    extern u32 lbl_80368AE8;

    extern u32 fn_802142B0(void);
    extern void *fn_802637D0(u32);
    extern void fn_80263800(void *);
    extern u32 fn_802142B8(void);
    extern void fn_80262FB0(void);
    extern void Sound_AramDmaCallback(void);

    extern void DCFlushRange(void *, u32);
    extern u32 OSDisableInterrupts(void);
    extern void OSRestoreInterrupts(u32);
    extern void ARQPostRequest();

    u8 *queue;
    u8 *entry;
    u16 *buffer;
    u32 base;
    u32 interrupts;
    u32 index;
    u32 i;
    u32 j;

    base = fn_802142B0();
    buffer = fn_802637D0(0x500);

    for (i = 0; i < 0x10; i++) {
        for (j = 0; j < 0x28; j++) {
            buffer[i * 0x28 + j] = 0;
        }
    }

    DCFlushRange(buffer, 0x500);

    queue = gSoundAramQueue;

    *(u8 *)(queue + 0x281) = 0;
    *(u8 *)(queue + 0x280) = 0;

    *(u8 *)(gSoundAramQueueHi + 0x281) = 0;
    *(u8 *)(gSoundAramQueueHi + 0x280) = 0;

    for (;;) {
        interrupts = OSDisableInterrupts();

        if (*(u8 *)(queue + 0x281) < 0x10) {
            index = *(u8 *)(queue + 0x280);
            entry = queue + index * 0x28;

            *(u32 *)(entry + 0x04) = 0x2A;
            *(u32 *)(entry + 0x08) = 0;
            *(u32 *)(entry + 0x0C) = 0;
            *(void **)(entry + 0x10) = buffer;
            *(u32 *)(entry + 0x14) = base;
            *(u32 *)(entry + 0x18) = 0x500;
            *(void (**)(void))(entry + 0x1C) = Sound_AramDmaCallback;
            *(u32 *)(entry + 0x20) = 0;
            *(u32 *)(entry + 0x24) = 0;

            ARQPostRequest(
                entry,
                *(u32 *)(entry + 0x04),
                *(u32 *)(entry + 0x08),
                *(u32 *)(entry + 0x0C),
                *(u32 *)(entry + 0x10),
                *(u32 *)(entry + 0x14),
                *(u32 *)(entry + 0x18),
                *(u32 *)(entry + 0x1C)
            );

            *(u8 *)(queue + 0x281) =
                *(u8 *)(queue + 0x281) + 1;

            *(u8 *)(queue + 0x280) =
                (*(u8 *)(queue + 0x280) + 1) & 0xF;

            OSRestoreInterrupts(interrupts);
            break;
        }

        OSRestoreInterrupts(interrupts);
    }

    while (*(u8 *)(queue + 0x281) != 0) {
    }

    fn_80263800(buffer);

    lbl_80368AF0 = base + arg0;

    if (lbl_80368AF0 > fn_802142B8()) {
        lbl_80368AF0 = fn_802142B8();
    }

    lbl_80368AE8 = 0;

    fn_80262FB0();
}

void fn_80262AD0(void) {
    M2C_UNK fn_802142B0();
    fn_802142B0();
}

s32 fn_80262AF0(void) {
    return fn_802142B0() + 0x500;
}

s32 fn_80262B14(s32 arg0) {
    return arg0 - 0x500;
}

void fn_80262B1C(s32 arg0, s32 arg1) {
    u32 fn_80215F30();
    extern u32 lbl_80368AE4;
    extern s32 lbl_80368AE8;
    u32 temp_r31;
    u32 temp_r3;
    u32 var_r0;

    if (arg0 != 0) {
        temp_r31 = (arg1 + 0x1F) & 0xFFFFFFE0;
        temp_r3 = fn_80215F30();
        var_r0 = temp_r31;
        if (temp_r31 < temp_r3) {
            var_r0 = temp_r3;
        }
        lbl_80368AE4 = var_r0;
    }
    lbl_80368AE8 = arg0;
}

u32 fn_80262B74(void *arg0, u32 arg1, void *arg2)
{
    extern u8 gSoundAramQueue[];
    extern u32 lbl_80368AEC;
    extern u32 lbl_80368AE4;
    extern u32 (*lbl_80368AE8)(void *, u32);

    extern u32 fn_802142B0(void);
    extern void Sound_AramDmaCallback(void);
    extern void ARQPostRequest(
        void *, u32, u32, u32, u32, u32, u32, u32
    );

    extern void DCFlushRange(void *, u32);
    extern u32 OSDisableInterrupts(void);
    extern void OSRestoreInterrupts(u32);

    u8 *queue;
    u8 *entry;
    u8 *state;
    u8 *data;
    u32 size;
    u32 offset;
    u32 originalOffset;
    u32 chunkSize;
    u32 result;
    u32 interrupts;
    u32 index;

    data = (u8 *)arg0;
    state = (u8 *)arg2;
    size = (arg1 + 0x1F) & ~0x1F;

    if (*(u32 *)(state + 0) ==
        fn_802142B0() + 0x500) {

        if (*(u32 *)(state + 8) + size > lbl_80368AEC) {
            return 0;
        }
    } else {
        if (*(u32 *)(state + 8) + size >
            *(u32 *)(state + 4)) {
            return 0;
        }
    }

    originalOffset = *(u32 *)(state + 8);
    offset = originalOffset;

    queue = gSoundAramQueue;

    if (lbl_80368AE8 == 0) {
        DCFlushRange(data, size);

        for (;;) {
            interrupts = OSDisableInterrupts();

            if (*(u8 *)(queue + 0x281) < 0x10) {
                index = *(u8 *)(queue + 0x280);
                entry = queue + index * 0x28;

                *(u32 *)(entry + 4) = 0x2A;
                *(u32 *)(entry + 8) = 0;
                *(u32 *)(entry + 0x0C) = 0;
                *(void **)(entry + 0x10) = data;
                *(u32 *)(entry + 0x14) = offset;
                *(u32 *)(entry + 0x18) = size;
                *(void (**)(void))(entry + 0x1C) =
                    Sound_AramDmaCallback;
                *(u32 *)(entry + 0x20) = 0;
                *(u32 *)(entry + 0x24) = 0;

                ARQPostRequest(
                    entry,
                    *(u32 *)(entry + 4),
                    *(u32 *)(entry + 8),
                    *(u32 *)(entry + 0x0C),
                    *(u32 *)(entry + 0x10),
                    *(u32 *)(entry + 0x14),
                    *(u32 *)(entry + 0x18),
                    *(u32 *)(entry + 0x1C)
                );

                ++*(u8 *)(queue + 0x281);

                *(u8 *)(queue + 0x280) =
                    (*(u8 *)(queue + 0x280) + 1) & 0xF;

                OSRestoreInterrupts(interrupts);
                break;
            }

            OSRestoreInterrupts(interrupts);
        }

        *(u32 *)(state + 8) += size;
        return originalOffset;
    }

    while (size != 0) {
        while (*(u8 *)(queue + 0x281) != 0) {
        }

        chunkSize = size;

        if (chunkSize >= lbl_80368AE4) {
            chunkSize = lbl_80368AE4;
        }

        result = lbl_80368AE8(data, chunkSize);

        DCFlushRange((void *)result, chunkSize);

        for (;;) {
            interrupts = OSDisableInterrupts();

            if (*(u8 *)(queue + 0x281) < 0x10) {
                index = *(u8 *)(queue + 0x280);
                entry = queue + index * 0x28;

                *(u32 *)(entry + 4) = 0x2A;
                *(u32 *)(entry + 8) = 0;
                *(u32 *)(entry + 0x0C) = 0;
                *(u32 *)(entry + 0x10) = result;
                *(u32 *)(entry + 0x14) = offset;
                *(u32 *)(entry + 0x18) = chunkSize;
                *(void (**)(void))(entry + 0x1C) =
                    Sound_AramDmaCallback;
                *(u32 *)(entry + 0x20) = 0;
                *(u32 *)(entry + 0x24) = 0;

                ARQPostRequest(
                    entry,
                    *(u32 *)(entry + 4),
                    *(u32 *)(entry + 8),
                    *(u32 *)(entry + 0x0C),
                    *(u32 *)(entry + 0x10),
                    *(u32 *)(entry + 0x14),
                    *(u32 *)(entry + 0x18),
                    *(u32 *)(entry + 0x1C)
                );

                ++*(u8 *)(queue + 0x281);

                *(u8 *)(queue + 0x280) =
                    (*(u8 *)(queue + 0x280) + 1) & 0xF;

                OSRestoreInterrupts(interrupts);
                break;
            }

            OSRestoreInterrupts(interrupts);
        }

        size -= chunkSize;
        data += chunkSize;
        offset += chunkSize;

        *(u32 *)(state + 8) = offset;
    }

    return originalOffset;
}

void fn_80262F98(s32 unused, s32 arg1, void *arg2) {
    *(s32 *)((u8 *)arg2 + 8) = *(s32 *)((u8 *)arg2 + 8) - ((arg1 + 0x1F) & ~0x1F);
}

void fn_80262FB0(void) {
    extern u8 lbl_80364430[];
    extern void *lbl_80368AE0;
    extern void *lbl_80368ADC;
    extern void *lbl_80368AD8;
    extern u32 lbl_80368AF0;
    extern u32 lbl_80368AEC;

    u8 *base;
    u8 *p;
    u32 i;
    u32 z;
    s32 n;

    base = lbl_80364430;
    z = 0;
    n = 7;
    lbl_80368AE0 = (void *)z;
    p = base + 0x10;
    i = 1;
    lbl_80368ADC = (void *)z;
    lbl_80368AD8 = base;
    for (; n > 0; n--) {
        *(u8 **)(p - 0x10) = p;
        *(u8 **)(p + 0x00) = p + 0x10;
        *(u8 **)(p + 0x10) = p + 0x20;
        *(u8 **)(p + 0x20) = p + 0x30;
        *(u8 **)(p + 0x30) = p + 0x40;
        *(u8 **)(p + 0x40) = p + 0x50;
        *(u8 **)(p + 0x50) = p + 0x60;
        *(u8 **)(p + 0x60) = p + 0x70;
        i += 8;
        p += 0x80;
    }

    base = lbl_80364430;
    p = base + (i << 4);
    if (i < 0x40U) {
        do {
            *(u8 **)(p - 0x10) = p;
            p += 0x10;
            i += 1;
        } while (i < 0x40U);
    }

    base = lbl_80364430;
    {
        u32 af0 = lbl_80368AF0;
        p = base + (i << 4);
        z = 0;
        *(u8 **)(p - 0x10) = (u8 *)z;
        lbl_80368AEC = af0;
    }
}

typedef struct { void *prev; u32 smallest; } HeapWalk80263074;

u8 fn_80263074(u32 arg0, u32 smallest, void *previous)
{
    extern u8 lbl_80364430[];
    extern void *lbl_80368ADC;
    extern void *lbl_80368AD8;
    extern void *lbl_80368AE0;
    extern u32 lbl_80368AEC;
    extern void *fn_80258AD8(void);

    void *selected;
    u32 size;
    void *current;

    previous = 0;
    smallest = -1;
    size = (arg0 + 0x1F) & ~0x1F;
    selected = 0;
    current = lbl_80368ADC;

    while (current != 0) {
        if (*(u32 *)((u8 *)current + 0x0C) == size) {
            selected = current;
            break;
        }

        if (*(u32 *)((u8 *)current + 0x0C) > size) {
            if (smallest > *(u32 *)((u8 *)current + 0x0C)) {
                selected = current;
                smallest = *(u32 *)((u8 *)current + 0x0C);
                previous = current;
            }
        }

        current = *(void **)current;
    }

    if (selected == 0) {
        if (lbl_80368AD8 != 0) {
            current = fn_80258AD8();
            if (*(u32 *)((u8 *)current + 8) <= lbl_80368AEC - size) {
                current = lbl_80368AD8;
                selected = current;
                lbl_80368AD8 = *(void **)current;

                *(u32 *)((u8 *)current + 0x0C) = size;
                *(u32 *)((u8 *)current + 8) = size;

                lbl_80368AEC -= size;
                *(u32 *)((u8 *)current + 4) = lbl_80368AEC;

                *(void **)current = lbl_80368AE0;
                lbl_80368AE0 = current;
            }
        }
    } else {
        if (previous != 0) {
            *(void **)previous = *(void **)selected;
        } else {
            lbl_80368ADC = *(void **)selected;
        }

        *(u32 *)((u8 *)selected + 8) = size;
        *(void **)selected = lbl_80368AE0;
        lbl_80368AE0 = selected;
    }

    if (selected == 0) {
        return 0xFF;
    }

    return (u8)((s32)((u8 *)selected - lbl_80364430) / 16);
}

s32 fn_802631AC(u8 arg0, s32 *arg1) {
    extern struct { s32 unk00; s32 unk04; s32 unk08; s32 unk0C; } lbl_80364430[];

    if (arg1 != NULL) {
        *arg1 = lbl_80364430[arg0].unk08;
    }
    return lbl_80364430[arg0].unk04;
}

void fn_802631E4(s32 arg0)
{
    extern u8 lbl_80364430[];
    extern void *lbl_80368AE0;
    extern void *lbl_80368AD8;
    extern void *lbl_80368ADC;
    extern u32 lbl_80368AEC;
    extern u32 lbl_80368AF0;

    u8 *entry;
    u8 *current;
    u8 *previous;
    u8 *next;
    u8 *node;
    u32 value;
    u32 new_aec;

    entry = lbl_80364430 + ((u32)arg0 & 0xFF) * 0x10;
    current = lbl_80368AE0;
    previous = 0;

    while (current != 0) {
        if (current == entry) {
            if (previous != 0) {
                *(void **)previous = *(void **)entry;
            } else {
                lbl_80368AE0 = *(void **)entry;
            }
            break;
        }
        previous = current;
        current = *(u8 **)current;
    }

    if (*(u32 *)(entry + 4) == lbl_80368AEC) {
        *(void **)entry = lbl_80368AD8;
        lbl_80368AD8 = entry;

        value = 0xFFFFFFFF;
        current = lbl_80368AE0;

        while (current != 0) {
            u32 size;

            size = *(u32 *)(current + 4);
            if (size <= value) {
                value = size;
            }
            current = *(u8 **)current;
        }

        node = lbl_80368ADC;

        while (node != 0) {
            next = *(u8 **)node;
            if (*(u32 *)(node + 4) < value) {
                lbl_80368ADC = next;
                *(void **)node = lbl_80368AD8;
                lbl_80368AD8 = node;
            }
            node = next;
        }

        new_aec = lbl_80368AF0;
        if ((value + 0x10000) != 0xFFFF) {
            new_aec = value;
        }
        lbl_80368AEC = new_aec;
    } else {
        *(void **)entry = lbl_80368ADC;
        lbl_80368ADC = entry;
    }
}

#pragma global_optimizer off
void fn_802632DC(void)
{
    extern u8 lbl_80368B20;
    extern u32 lbl_80368B1C;
    extern s32 lbl_80368B0C;
    extern u32 lbl_80368B18;
    extern u32 lbl_80368B10;
    extern u32 lbl_80368B14;
    extern void (*lbl_80368B24)(void);

    void fn_80213760(void *arg0, s32 arg1);
    u32 OSGetTick(void);
    BOOL OSEnableInterrupts(void);
    BOOL OSDisableInterrupts(void);

    s32 index;

    index = (lbl_80368B20 + 1) % 4;
    lbl_80368B20 = (u8)index;
    fn_80213760((void *)(lbl_80368B1C + 0x80000000 + (u8)index * 0x280), 0x280);

    lbl_80368B0C = OSGetTick();
    if (lbl_80368B18 != 0) {
        if (lbl_80368B10 == 0) {
            lbl_80368B10 = 1;
            OSEnableInterrupts();
            lbl_80368B24();
            OSDisableInterrupts();
            lbl_80368B10 = 0;
        }
    } else {
        lbl_80368B14 = 1;
    }
}
#pragma global_optimizer reset
void fn_80263384(void) {
    extern s32 lbl_80368B08;
    extern s32 lbl_80368B18;
    lbl_80368B18 = 1;
    lbl_80368B08 = 1;
}

#pragma scheduling off
void fn_80263394(void) {
extern u32 lbl_80368B18, lbl_80368B14, lbl_80368B10;
extern void (*lbl_80368B24)(void);
u32 one = 1; u32 zero = 0;
lbl_80368B18=one;
if(lbl_80368B14) {
lbl_80368B14=zero;
if(!lbl_80368B10) {
lbl_80368B10=one; OSEnableInterrupts(); lbl_80368B24(); OSDisableInterrupts(); lbl_80368B10=zero;
}
}
}
#pragma scheduling on
void fn_802633F8(void) {
    M2C_UNK fn_8020AEC4(M2C_UNK *);
    extern M2C_UNK lbl_80368B00;
    fn_8020AEC4(&lbl_80368B00);
}

s32 fn_8026341C(void (*callback)(void), s32 unused, s32 *outSize) {
    void *fn_802637D0(u32);
    void *memset(void *, s32, u32);
    void DCFlushRange(void *, u32);
    void fn_8021371C(void (*)(void));
    void fn_80213760(void *, s32);
    void fn_802632DC(void);
    extern void *lbl_80368B1C;
    extern s32 lbl_80368B14;
    extern s32 lbl_80368B18;
    extern u8 lbl_80368B20;
    extern s32 lbl_80368B10;
    extern void (*lbl_80368B24)(void);
    extern u8 gSoundData[];
    void *buf;
    void (*cb)(void);
    s32 *out;
    s32 one;
    s32 zero;

    cb = callback;
    out = outSize;
    buf = fn_802637D0(0xA00);
    lbl_80368B1C = buf;
    if (buf != NULL) {
        memset(buf, 0, 0xA00);
        DCFlushRange(lbl_80368B1C, 0xA00);
        one = 1;
        zero = 0;
        lbl_80368B14 = zero;
        lbl_80368B18 = one;
        lbl_80368B20 = one;
        lbl_80368B10 = zero;
        lbl_80368B24 = cb;
        fn_8021371C(fn_802632DC);
        fn_80213760((void *)((u32)lbl_80368B1C + 0x80000000 + (u8)lbl_80368B20 * 0x280), 0x280);
        *(s32 *)(gSoundData + 4) = 0x20;
        *out = 0x7D00;
        return 1;
    }
    return 0;
}

int fn_802634E4(void) {
    M2C_UNK fn_802137E8();
    fn_802137E8();
}

int fn_80263504(void) {
    extern s32 lbl_80368B1C;
    extern u8 lbl_80368B20;
    s32 x;

    x = lbl_80368B20 + 2;
    return lbl_80368B1C + (u8)(x % 4) * 0x280;
}

s32 fn_80263534(void)
{
    extern u8 lbl_80364840[];
    extern u8 lbl_803648A0[];
    extern u8 lbl_802A26A0[];
    extern u8 lbl_80368B00;
    extern u16 lbl_803670D0;
    extern u32 lbl_80368B08;

    extern void fn_80263384(void);
    extern void fn_80263394(void);
    extern void fn_802633F8(void);
    extern void OSInitThreadQueue(void *queue);
    extern void fn_80215F8C(void);
    extern void fn_80216050(void *arg0);
    extern void Audio_Unlock(void);
    extern void Audio_Lock(void);

    u8 *config;
    u32 zero;

    config = lbl_80364840;
    zero = 0;

    *(void **)(config + 0x0C) = lbl_802A26A0;
    *(u32 *)(config + 0x10) = lbl_803670D0;
    *(u32 *)(config + 0x14) = zero;
    *(void **)(config + 0x18) = lbl_803648A0;
    *(u32 *)(config + 0x1C) = 0x2000;
    *(u32 *)(config + 0x20) = zero;
    *(u16 *)(config + 0x24) = 0x10;
    *(u16 *)(config + 0x26) = 0x30;
    *(void **)(config + 0x28) = fn_80263384;
    *(void **)(config + 0x2C) = fn_80263394;
    *(void **)(config + 0x30) = fn_802633F8;
    *(u32 *)(config + 0x34) = zero;
    *(u32 *)(config + 0x04) = zero;

    OSInitThreadQueue(&lbl_80368B00);
    fn_80215F8C();
    fn_80216050(config);

    lbl_80368B08 = zero;
    Audio_Unlock();

    while (*(volatile u32 *)&lbl_80368B08 == 0) {
    }
    Audio_Lock();

    return 1;
}

#pragma peephole off
void fn_80263608(s32 arg0)
{
    extern u32 gSoundAuxBuf;
    extern u16 lbl_80368A84;
    extern u32 lbl_80368B18;
    extern u32 fn_8026367C(void);
    extern void fn_8025A3A4(s32, s32);
    extern void PPCSync(void);
    extern void fn_80215F78(u32);
    extern u32 fn_80215F40(void);

    s32 self;
    u32 aux;
    u32 zero;

    self = arg0;
    fn_8025A3A4(self, fn_8026367C());

    zero = 0;
    aux = gSoundAuxBuf;
    lbl_80368B18 = zero;
    PPCSync();

    fn_80215F78((u32)lbl_80368A84 | 0xBABE0000);
    if (fn_80215F40() == 0) {
        fn_80215F78(aux);
        if (fn_80215F40() != 0) {
            return;
        }
    }
}
#pragma peephole on
u32 fn_8026367C(void) {
    u32 OSGetTick(void);
    extern s32 lbl_80368B0C;
    return ((OSGetTick() - lbl_80368B0C) * 8) / ((*(u32 *)0x800000F8 >> 2) / 125000);
}

int fn_802636C8(void) {
    extern s32 lbl_80368AF8;
    extern s16 lbl_80368AFC;
    lbl_80368AF8 = OSDisableInterrupts();
    lbl_80368AFC = 1;
}

int Audio_Unlock(void) {
    int OSRestoreInterrupts(int);
    extern u16 lbl_80368AFC;
    extern int lbl_80368AF8;
    int count;
    count = lbl_80368AFC;
    count -= 1;
    lbl_80368AFC = count;
    if ((u16)count == 0) {
        return OSRestoreInterrupts(lbl_80368AF8);
    }
    return count;
}

#pragma push
#pragma optimization_level 2
int Audio_Lock(void) {
    int OSDisableInterrupts(void);
    extern u16 lbl_80368AFC;
    extern int lbl_80368AF8;
    int count;
    int flag;

    count = lbl_80368AFC;
    flag = count & 0xFFFF;
    count = count + 1;
    lbl_80368AFC = count;
    if (flag == 0) {
        return lbl_80368AF8 = OSDisableInterrupts();
    }
    return count;
}
#pragma pop
int fn_80263764(void) {
    M2C_UNK OSDisableInterrupts();
    OSDisableInterrupts();
}

int fn_80263784(void) {
    M2C_UNK OSEnableInterrupts();
    OSEnableInterrupts();
}

extern u8 lbl_80363F18[16];

void fn_802637A4(s32 arg0) {
    ((void (*)(s32))*(void **)(lbl_80363F18 + 0))(arg0);
}

void fn_802637D0(s32 arg0) {
    extern u8 lbl_80363F18[16];
    ((void (*)(s32))*(void **)(lbl_80363F18 + 4))(arg0);
}

void fn_80263800(s32 arg0) {
    extern u8 lbl_80363F18[16];
    ((void (*)(s32))*(void **)(lbl_80363F18 + 8))(arg0);
}

void fn_80263830(void *arg0) {
    M2C_UNK fn_8026386C(f32, f32, f32, f32, f32);
    M2C_FIELD(arg0, s8 *, 0x13C) = 0;
    fn_8026386C(M2C_FIELD(arg0, f32 *, 0x140), M2C_FIELD(arg0, f32 *, 0x148), M2C_FIELD(arg0, f32 *, 0x144), M2C_FIELD(arg0, f32 *, 0x14C), M2C_FIELD(arg0, f32 *, 0x150));
}

s32 fn_8026386C(
    void *arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    f32 arg5
)
{
    extern f32 lbl_8036C378;
    extern f32 lbl_8036C37C;
    extern f32 lbl_8036C380;
    extern f32 lbl_8036C384;
    extern f32 lbl_8036C388;
    extern f32 lbl_8036C38C;
    extern f32 lbl_8036C398;
    extern f32 lbl_8036C39C;
    extern f64 lbl_8036C390;
    extern u32 lbl_802A4560[];

    extern void *fn_802637A4(s32);
    extern f64 fmod(f64, f32);
    extern void *memset(void *, s32, u32);

    u8 *data;
    u8 *record;
    u32 channel;
    u32 sub;
    u32 index;
    u32 length;
    u32 size;
    s32 offset;
    f32 minimum;
    f32 frequency;
    f32 value;

    data = (u8 *)arg0;
    minimum = lbl_8036C378;

    if (arg1 < minimum ||
        arg1 > lbl_8036C37C ||
        arg2 < lbl_8036C380 ||
        arg2 > lbl_8036C384 ||
        arg3 < minimum ||
        arg3 > lbl_8036C37C ||
        arg4 < minimum ||
        arg4 > lbl_8036C37C ||
        arg5 < minimum ||
        arg5 > lbl_8036C388) {
        return 0;
    }

    memset(data, 0, 0x13C);

    frequency = lbl_8036C38C * arg2;

    for (channel = 0; channel < 3; channel++) {
        for (sub = 0; sub < 2; sub++) {
            index = channel * 2 + sub;
            record = data + index * 0x14;

            length = lbl_802A4560[index] + 2;
            size = length * 4;

            *(u32 *)(record + 0x80) = size;
            *(void **)(record + 0x84) = fn_802637A4(size);

            memset(*(void **)(record + 0x84), 0, size);
            *(f32 *)(record + 0x88) = minimum;

            offset = *(s32 *)(record + 0x78) -
                     ((s32)length >> 1) * 4;

            offset += size;

            if (offset < 0) {
                *(s32 *)(record + 0x78) = 0;
                offset = -(s32)(lbl_802A4560[index] * 4);

                while (offset < 0) {
                    offset += size;
                }
            }

            *(s32 *)(record + 0x7C) = offset;

            value = (f32)fmod(
                lbl_8036C390,
                (f32)(-(s32)(lbl_802A4560[index] * 3)) / frequency
            );

            *(f32 *)(data + index * 4 + 0xF4) = value;
        }
    }

    for (channel = 0; channel < 3; channel++) {
        for (sub = 0; sub < 2; sub++) {
            index = channel * 2 + sub;
            record = data + index * 0x14;

            length = lbl_802A4560[sub + 2] + 2;
            size = length * 4;

            *(u32 *)(record + 0x08) = size;
            *(void **)(record + 0x0C) = fn_802637A4(size);

            memset(*(void **)(record + 0x0C), 0, size);
            *(f32 *)(record + 0x10) = minimum;

            offset = *(s32 *)(record + 0x00) -
                     ((s32)length >> 1) * 4;

            offset += size;

            if (offset < 0) {
                *(s32 *)(record + 0x00) = 0;
                offset = -(s32)(lbl_802A4560[sub + 2] * 4);

                while (offset < 0) {
                    offset += size;
                }
            }

            *(s32 *)(record + 0x04) = offset;
        }

        *(f32 *)(data + channel * 4 + 0x10C) = minimum;
    }

    *(f32 *)(data + 0xF0) = arg1;
    *(f32 *)(data + 0x118) = arg3;
    *(f32 *)(data + 0x11C) = arg4;

    value = *(f32 *)(data + 0x11C);

    if (value < lbl_8036C398) {
        *(f32 *)(data + 0x11C) = lbl_8036C398;

        value = lbl_8036C398 +
                lbl_8036C39C * *(f32 *)(data + 0x11C);

        *(f32 *)(data + 0x11C) =
            lbl_8036C37C - value;
    }

    if (arg5 != minimum) {
        value = lbl_8036C38C * arg5;
        *(u32 *)(data + 0x120) = (u32)(s32)value;

        for (channel = 0; channel < 3; channel++) {
            record = data + channel * 4;
            size = *(u32 *)(data + 0x120) * 4;

            *(void **)(record + 0x124) = fn_802637A4(size);

            memset(*(void **)(record + 0x124), 0, size);

            *(void **)(record + 0x130) =
                *(void **)(record + 0x124);
        }
    } else {
        *(u32 *)(data + 0x120) = 0;
        *(u32 *)(data + 0x130) = 0;
        *(u32 *)(data + 0x124) = 0;
        *(u32 *)(data + 0x134) = 0;
        *(u32 *)(data + 0x128) = 0;
        *(u32 *)(data + 0x138) = 0;
        *(u32 *)(data + 0x12C) = 0;
    }

    return 1;
}

void fn_80263C94(u8 arg0, void *arg1, void *arg2) {
    M2C_UNK Sound_ProcessAux(s32, s32, s32, void *);
    switch ((s32) arg0) {                           /* irregular */
    case 0:
        if ((u8) M2C_FIELD(arg2, u8 *, 0x1C4) == 0) {
            Sound_ProcessAux(M2C_FIELD(arg1, s32 *, 0), M2C_FIELD(arg1, s32 *, 4), M2C_FIELD(arg1, s32 *, 8), arg2);
        }
        /* fallthrough */
    case 1:
        return;
    }
}

void fn_80263CF0(void *arg0) {
    M2C_UNK fn_80263D30(f32, f32, f32, f32, f32, f32);
    M2C_FIELD(arg0, s8 *, 0x1C4) = 0;
    fn_80263D30(M2C_FIELD(arg0, f32 *, 0x1C8), M2C_FIELD(arg0, f32 *, 0x1D0), M2C_FIELD(arg0, f32 *, 0x1CC), M2C_FIELD(arg0, f32 *, 0x1D4), M2C_FIELD(arg0, f32 *, 0x1D8), M2C_FIELD(arg0, f32 *, 0x1DC));
}

s32 fn_80263D30(
    void *arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    f32 arg5,
    f32 arg6
)
{
    extern f32 lbl_8036C3A8;
    extern f32 lbl_8036C3AC;
    extern f32 lbl_8036C3B0;
    extern f32 lbl_8036C3B4;
    extern f32 lbl_8036C3B8;
    extern f32 lbl_8036C3BC;
    extern f32 lbl_8036C3C8;
    extern f32 lbl_8036C3CC;
    extern f64 lbl_8036C3C0;
    extern f64 lbl_8036C3D0;
    extern u32 lbl_802A4570[];

    extern void *fn_802637A4(s32);
    extern f64 fmod(f64, f32);
    extern void *memset(void *, s32, u32);

    u8 *data;
    u8 *record;
    u32 channel;
    u32 sub;
    u32 index;
    u32 length;
    u32 size;
    s32 offset;
    f32 minimum;
    f32 frequency;
    f32 value;

    data = (u8 *)arg0;

    minimum = lbl_8036C3A8;

    if (arg1 < minimum ||
        arg1 > lbl_8036C3AC ||
        arg2 < lbl_8036C3B0 ||
        arg2 > lbl_8036C3B4 ||
        arg3 < minimum ||
        arg3 > lbl_8036C3AC ||
        arg6 < minimum ||
        arg6 > lbl_8036C3AC ||
        arg4 < minimum ||
        arg4 > lbl_8036C3AC ||
        arg5 < minimum ||
        arg5 > lbl_8036C3B8) {
        return 0;
    }

    memset(data, 0, 0x1C4);

    frequency = lbl_8036C3BC * arg2;

    /*
     * Initialize the first three buffers for each channel.
     */
    for (channel = 0; channel < 3; channel++) {
        for (sub = 0; sub < 3; sub++) {
            index = channel * 3 + sub;
            record = data + index * 0x14;

            length = lbl_802A4570[index] + 2;
            size = length * 4;

            *(u32 *)(record + 0xBC) = size;
            *(void **)(record + 0xC0) = fn_802637A4(size);

            memset(*(void **)(record + 0xC0), 0, size);
            *(f32 *)(record + 0xC4) = minimum;

            offset = *(s32 *)(record + 0xB4) -
                     ((s32)length >> 1) * 4;

            while (offset < 0) {
                offset += size;
            }

            if (offset >= 0) {
                *(s32 *)(record + 0xB4) = 0;
                offset = -(s32)(lbl_802A4570[index] * 4);

                while (offset < 0) {
                    offset += size;
                }
            }

            *(s32 *)(record + 0xB8) = offset;

            value = (f32)fmod(
                lbl_8036C3C0,
                (f32)(-(s32)(lbl_802A4570[index] * 3)) / frequency
            );

            *(f32 *)(data + index * 0x14 + 0x16C) = value;
        }
    }

    /*
     * Initialize the next two buffers for each channel.
     */
    for (channel = 0; channel < 3; channel++) {
        for (sub = 0; sub < 2; sub++) {
            index = channel * 3 + sub;
            record = data + index * 0x14;

            length = lbl_802A4570[sub + 3] + 2;
            size = length * 4;

            *(u32 *)(record + 0x08) = size;
            *(void **)(record + 0x0C) = fn_802637A4(size);

            memset(*(void **)(record + 0x0C), 0, size);
            *(f32 *)(record + 0x10) = minimum;

            offset = *(s32 *)(record + 0x00) -
                     ((s32)length >> 1) * 4;

            while (offset < 0) {
                offset += size;
            }

            if (offset >= 0) {
                *(s32 *)(record + 0x00) = 0;
                offset = -(s32)(lbl_802A4570[sub + 3] * 4);

                while (offset < 0) {
                    offset += size;
                }
            }

            *(s32 *)(record + 0x04) = offset;
        }
    }

    /*
     * Initialize the final buffer for each channel.
     */
    for (channel = 0; channel < 3; channel++) {
        record = data + channel * 0x3C;

        length = lbl_802A4570[channel + 5] + 2;
        size = length * 4;

        *(u32 *)(record + 0x30) = size;
        *(void **)(record + 0x34) = fn_802637A4(size);

        memset(*(void **)(record + 0x34), 0, size);
        *(f32 *)(record + 0x38) = minimum;

        offset = *(s32 *)(record + 0x28) -
                 ((s32)length >> 1) * 4;

        while (offset < 0) {
            offset += size;
        }

        if (offset >= 0) {
            *(s32 *)(record + 0x28) = 0;
            offset = -(s32)(lbl_802A4570[channel + 5] * 4);

            while (offset < 0) {
                offset += size;
            }
        }

        *(s32 *)(record + 0x2C) = offset;

        *(f32 *)(data + channel * 4 + 0x190) = minimum;
    }

    *(f32 *)(data + 0x168) = arg1;
    *(f32 *)(data + 0x19C) = arg3;
    *(f32 *)(data + 0x1A8) = arg6;
    *(f32 *)(data + 0x1A0) = arg4;

    value = *(f32 *)(data + 0x1A0);

    if (value < lbl_8036C3C8) {
        *(f32 *)(data + 0x1A0) = lbl_8036C3C8;

        value = lbl_8036C3C8 +
                lbl_8036C3CC * *(f32 *)(data + 0x1A0);

        *(f32 *)(data + 0x1A0) =
            lbl_8036C3AC - value;
    }

    if (arg5 != minimum) {
        value = lbl_8036C3BC * arg5;
        *(u32 *)(data + 0x1A4) = (u32)(s32)value;

        for (channel = 0; channel < 3; channel++) {
            record = data + channel * 4;

            size = *(u32 *)(data + 0x1A4) * 4;

            *(void **)(record + 0x1AC) = fn_802637A4(size);

            memset(*(void **)(record + 0x1AC), 0, size);

            *(void **)(record + 0x1B8) =
                *(void **)(record + 0x1AC);
        }
    } else {
        *(u32 *)(data + 0x1A4) = 0;
        *(u32 *)(data + 0x1B8) = 0;
        *(u32 *)(data + 0x1AC) = 0;
        *(u32 *)(data + 0x1BC) = 0;
        *(u32 *)(data + 0x1B0) = 0;
        *(u32 *)(data + 0x1C0) = 0;
        *(u32 *)(data + 0x1B4) = 0;
    }

    return 1;
}

#pragma optimization_level 3
void Sound_MixSampleBuffers(s32 *a, s32 *b, f32 c0, f32 c1) {
 s32 i; f32 x0, x1, y0, y1;
 for(i=0x50;i!=0;i--) {
 x0=(f32)a[0]; y0=(f32)b[0]; x1=(f32)a[1]; y1=(f32)b[1];
 a[0]=(s32)(x0*c1+y0*c0); b[0]=(s32)(x0*c0+y0*c1);
 a[1]=(s32)(x1*c1+y1*c0); b[1]=(s32)(x1*c0+y1*c1);
 a+=2; b+=2;
 }
}
#pragma optimization_level reset
void Sound_ProcessAuxChannel(s32 *arg0, u8 *arg1, s32 arg2)
{
    extern f32 lbl_8036C3E0;
    extern f32 lbl_8036C3E4;
    extern f64 lbl_8036C3D8;

    u32 channel;
    u32 count;
    u32 ring_length;
    u32 ring_start;
    u32 ring_pos;

    u8 *src;
    u8 *dst;
    u8 *src_state;
    u8 *dst_state;
    u8 *ring_state;

    f32 coeff;
    f32 scale;
    f32 feedback;
    f32 phase;
    f32 previous;
    f32 channel_coeff[3];
    f32 src_value[3];
    f32 dst_value[3];

    u32 src_index[3];
    u32 src_limit[3];
    u32 dst_index[3];
    u32 dst_limit[3];

    u8 *src_buffer[3];
    u8 *dst_buffer[3];

    s32 pass;
    s32 i;
    s32 output;

    channel = (u32)arg2;
    count = *(u32 *)(arg1 + 0x1A4);

    src_state = arg1 + 0xB4 + channel * 0x3C;
    dst_state = arg1 + channel * 0x3C;
    ring_state = arg1 + channel * 4;

    coeff = *(f32 *)(arg1 + 0x168);
    scale = lbl_8036C3E0;
    feedback = *(f32 *)(arg1 + 0x19C) * lbl_8036C3E4;

    channel_coeff[0] = *(f32 *)(arg1 + channel * 12 + 0x16C);
    channel_coeff[1] = *(f32 *)(arg1 + channel * 12 + 0x170);
    channel_coeff[2] = *(f32 *)(arg1 + channel * 12 + 0x174);

    src_value[0] = *(f32 *)(arg1 + channel * 4 + 0x190);

    src_buffer[0] = *(u8 **)(src_state + 0x0C);
    src_buffer[1] = *(u8 **)(src_state + 0x20);
    src_buffer[2] = *(u8 **)(src_state + 0x34);

    dst_buffer[0] = *(u8 **)(dst_state + 0x0C);
    dst_buffer[1] = *(u8 **)(dst_state + 0x20);
    dst_buffer[2] = *(u8 **)(dst_state + 0x34);

    src_index[0] = *(u32 *)(src_state + 0x00);
    src_index[1] = *(u32 *)(src_state + 0x14);
    src_index[2] = *(u32 *)(src_state + 0x28);

    src_limit[0] = *(u32 *)(src_state + 0x08);
    src_limit[1] = *(u32 *)(src_state + 0x1C);
    src_limit[2] = *(u32 *)(src_state + 0x30);

    dst_index[0] = *(u32 *)(dst_state + 0x00);
    dst_index[1] = *(u32 *)(dst_state + 0x14);
    dst_index[2] = *(u32 *)(dst_state + 0x28);

    dst_limit[0] = *(u32 *)(dst_state + 0x08);
    dst_limit[1] = *(u32 *)(dst_state + 0x1C);
    dst_limit[2] = *(u32 *)(dst_state + 0x30);

    src_value[0] = *(f32 *)(src_state + 0x10);
    src_value[1] = *(f32 *)(src_state + 0x24);
    src_value[2] = *(f32 *)(src_state + 0x38);

    dst_value[0] = *(f32 *)(dst_state + 0x10);
    dst_value[1] = *(f32 *)(dst_state + 0x24);
    dst_value[2] = *(f32 *)(dst_state + 0x38);

    src_limit[0] = *(u32 *)(src_state + 0x08);
    src_limit[1] = *(u32 *)(src_state + 0x1C);
    src_limit[2] = *(u32 *)(src_state + 0x30);

    dst_limit[0] = *(u32 *)(dst_state + 0x08);
    dst_limit[1] = *(u32 *)(dst_state + 0x1C);
    dst_limit[2] = *(u32 *)(dst_state + 0x30);

    phase = (f32)*arg0;
    previous = phase;

    /*
     * The original has one pass when count is zero and two passes
     * when count is nonzero.
     */
    for (pass = 0; pass < (count != 0 ? 2 : 1); pass++) {
        if (count != 0) {
            ring_start = *(u32 *)(arg1 + 0x1AC);
            ring_pos = *(u32 *)(arg1 + 0x1B8);
            ring_length = (count - 1) * 4;

            ring_pos += 4;
            previous = *(f32 *)(ring_pos - 4);

            *(f32 *)(ring_pos - 4) = phase;

            if (ring_pos == ring_start + ring_length) {
                ring_pos = ring_start;
            }

            *(u32 *)(arg1 + 0x1B8) = ring_pos;
        }

        for (i = 0; i < 0x9F; i++) {
            f32 mixed;
            f32 value;

            value = channel_coeff[0] * src_value[0] + previous;
            *(f32 *)(src_buffer[0] + src_index[0]) = value;
            src_index[0] += 4;

            value = channel_coeff[1] * src_value[1] + previous;
            *(f32 *)(src_buffer[1] + src_index[1]) = value;
            src_index[1] += 4;

            src_value[0] = *(f32 *)(src_buffer[0] + src_index[0]);
            src_index[0] += 4;

            src_value[1] = *(f32 *)(src_buffer[1] + src_index[1]);
            src_index[1] += 4;

            if (src_index[0] == src_limit[0]) {
                src_index[0] = 0;
            }
            if (src_index[1] == src_limit[1]) {
                src_index[1] = 0;
            }

            mixed = src_value[0] + src_value[1];

            value = channel_coeff[2] * src_value[2] + previous;
            *(f32 *)(src_buffer[2] + src_index[2]) = value;
            src_index[2] += 4;

            src_value[2] = *(f32 *)(src_buffer[2] + src_index[2]);
            src_index[2] += 4;

            if (src_index[2] == src_limit[2]) {
                src_index[2] = 0;
            }

            mixed += src_value[2];

            value = coeff * dst_value[0] + mixed;
            *(f32 *)(dst_buffer[0] + dst_index[0]) = value;
            dst_index[0] += 4;

            dst_value[0] = *(f32 *)(dst_buffer[0] + dst_index[0]);
            dst_index[0] += 4;

            if (dst_index[0] == dst_limit[0]) {
                dst_index[0] = 0;
            }

            value = coeff * dst_value[1] + (mixed - coeff * value);
            *(f32 *)(dst_buffer[1] + dst_index[1]) = value;
            dst_index[1] += 4;

            dst_value[1] = *(f32 *)(dst_buffer[1] + dst_index[1]);
            dst_index[1] += 4;

            if (dst_index[1] == dst_limit[1]) {
                dst_index[1] = 0;
            }

            value = coeff * dst_value[2] + (mixed - coeff * value);
            *(f32 *)(dst_buffer[2] + dst_index[2]) = value;
            dst_index[2] += 4;

            dst_value[2] = *(f32 *)(dst_buffer[2] + dst_index[2]);
            dst_index[2] += 4;

            if (dst_index[2] == dst_limit[2]) {
                dst_index[2] = 0;
            }

            feedback = (feedback - coeff * value) * scale;
            feedback += *(f32 *)(arg1 + 0x1A0) * src_value[0];

            src_value[0] = feedback;

            output = (s32)(feedback + phase * lbl_8036C3E4);
            *arg0++ = output;

            phase -= (f32)lbl_8036C3D8;
            previous = phase;
        }
    }

    *(u32 *)(src_state + 0x00) = src_index[0];
    *(u32 *)(src_state + 0x04) = src_index[0];
    *(u32 *)(src_state + 0x14) = src_index[1];
    *(u32 *)(src_state + 0x18) = src_index[1];
    *(u32 *)(src_state + 0x28) = src_index[2];
    *(u32 *)(src_state + 0x2C) = src_index[2];

    *(f32 *)(src_state + 0x10) = src_value[0];
    *(f32 *)(src_state + 0x24) = src_value[1];
    *(f32 *)(src_state + 0x38) = src_value[2];

    *(u32 *)(dst_state + 0x00) = dst_index[0];
    *(u32 *)(dst_state + 0x04) = dst_index[0];
    *(u32 *)(dst_state + 0x14) = dst_index[1];
    *(u32 *)(dst_state + 0x18) = dst_index[1];
    *(u32 *)(dst_state + 0x28) = dst_index[2];
    *(u32 *)(dst_state + 0x2C) = dst_index[2];

    *(f32 *)(dst_state + 0x10) = dst_value[0];
    *(f32 *)(dst_state + 0x24) = dst_value[1];
    *(f32 *)(dst_state + 0x38) = dst_value[2];

    *(f32 *)(arg1 + 0x190 + channel * 4) = src_value[0];
}

/* Mix wet aux into ch0/ch1 if needed, then run aux FX on all three PCM channels. */
void Sound_ProcessAux(s32 ch0, s32 ch1, s32 ch2, void *aux) {
    void Sound_MixSampleBuffers(s32, s32, f32, f32);
    void Sound_ProcessAuxChannel(s32, void *, s32);
    extern f32 lbl_8036C3A8;
    extern f32 lbl_8036C3AC;
    extern f32 lbl_8036C3E8;
    f32 halfWet;
    f32 wet;
    u8 i;

    for (i = 0; i < 3; i++) {
        switch (i) {
        case 0:
            if (lbl_8036C3A8 != *(f32 *)((char *)aux + 0x1A8)) {
                wet = *(f32 *)((char *)aux + 0x1A8);
                halfWet = lbl_8036C3E8 * wet;
                Sound_MixSampleBuffers(ch0, ch1, halfWet, lbl_8036C3AC - halfWet);
            }
            Sound_ProcessAuxChannel(ch0, aux, 0);
            break;
        case 1:
            Sound_ProcessAuxChannel(ch1, aux, 1);
            break;
        case 2:
            Sound_ProcessAuxChannel(ch2, aux, 2);
            break;
        }
    }
}

s32 fn_802649AC(void *arg0)
{
    extern void fn_80264BA4(void *arg0);
    extern void *fn_802637A4(s32 arg0);

    u32 *state;
    u32 zero;
    u32 i;
    u32 *p0;
    u32 *p1;
    u32 *p2;

    state = (u32 *)arg0;

    fn_80264BA4(arg0);

    zero = 0;

    state[0] = (((state[0x3C / 4] - 5) << 5) + 0x9F) / 160U;
    state[0xC / 4] = zero;

    state[0x18 / 4] = (state[0x48 / 4] << 7) / 100U;

    state[0x24 / 4] = (state[0x54 / 4] << 7) / 100U;

    state[1] = (((state[0x40 / 4] - 5) << 5) + 0x9F) / 160U;
    state[0x10 / 4] = zero;

    state[0x1C / 4] = (state[0x4C / 4] << 7) / 100U;

    state[0x28 / 4] = (state[0x58 / 4] << 7) / 100U;

    state[2] = (((state[0x44 / 4] - 5) << 5) + 0x9F) / 160U;
    state[0x14 / 4] = zero;

    state[0x20 / 4] = (state[0x50 / 4] << 7) / 100U;

    state[0x2C / 4] = (state[0x5C / 4] << 7) / 100U;

    state[0x30 / 4] = (u32)fn_802637A4((s32)(state[0] * 0x280));
    state[0x34 / 4] = (u32)fn_802637A4((s32)(state[1] * 0x280));
    state[0x38 / 4] = (u32)fn_802637A4((s32)(state[2] * 0x280));

    p0 = (u32 *)state[0x30 / 4];
    p1 = (u32 *)state[0x34 / 4];
    p2 = (u32 *)state[0x38 / 4];

    for (i = 0, zero = 0; i < state[0] * 0xA0U; i++) {
        *p0++ = zero;
    }

    for (i = 0, zero = 0; i < state[1] * 0xA0U; i++) {
        *p1++ = zero;
    }

    for (i = 0, zero = 0; i < state[2] * 0xA0U; i++) {
        *p2++ = zero;
    }

    return 1;
}

void fn_80264B7C(void *arg0) {
    M2C_UNK fn_802649AC();
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    fn_802649AC();
}

s32 fn_80264BA4(void *arg0) {
    void fn_80263800(void *);
    void *p;

    p = *(void **)((u8 *)arg0 + 0x30);
    if (p != NULL) {
        fn_80263800(p);
        fn_80263800(*(void **)((u8 *)arg0 + 0x34));
        fn_80263800(*(void **)((u8 *)arg0 + 0x38));
    }
    return 1;
}

#pragma fp_contract on
void fn_80264BF0(void *arg0) {
u8 *state=(u8*)arg0;
s32 *out=*(s32**)(state+0);
s32 *samples=*(s32**)(state+4);
s32 *history=*(s32**)(state+8);
u32 phase=*(u32*)(state+0xc);
s32 index=*(s32*)(state+0x10);
u32 step=*(u32*)(state+0x14);
s32 end=*(s32*)(state+0x1c);
s32 restart=*(s32*)(state+0x20);
f32 a=(f32)history[0], b=(f32)history[1], c=(f32)history[2], d=(f32)samples[index];
s32 count=160;
do {
u32 oldPhase=phase;
u32 offset=(phase<<7)&0x7f0;
f32 *coef=(f32*)((u8*)lbl_802A4590+offset);
f32 value;
phase+=step;
value=a*coef[0];
value=b*coef[1]+value;
value=c*coef[2]+value;
value=d*coef[3]+value;
*out++=(s32)value;
if(phase<oldPhase) {
index++;
a=b; b=c; c=d;
if(index==end) index=restart;
d=(f32)samples[index];
}
} while(--count!=0);
history=*(s32**)(state+8);
history[0]=(s32)a; history[1]=(s32)b; history[2]=(s32)c;
*(u32*)(state+0xc)=phase;
*(s32*)(state+0x10)=index;
}
#pragma fp_contract off
void fn_80264D88(void *arg0) {
u8 *state=(u8*)arg0;
u32 phase=*(u32*)(state+12);
s32 index=*(s32*)(state+16);
u32 step=*(u32*)(state+20);
s32 end=*(s32*)(state+28), restart=*(s32*)(state+32);
s32 *samples=*(s32**)(state+4), *out=*(s32**)state, *history=*(s32**)(state+8);
f32 a=history[0],b=history[1],c=history[2],d=samples[index];
s32 count=160;
do {
u32 old=phase;
f32 *coef=(f32*)((u8*)lbl_802A4590+(((phase<<7)|(phase>>25))&0x7f0));
f32 value;
phase+=step;
index++;
value=a*coef[0]; value=b*coef[1]+value; value=c*coef[2]+value; value=d*coef[3]+value;
if(phase<old) { a=b;b=c;c=d; }
else { if(index==end) index=restart; a=c;b=d;c=samples[index];index++; }
if(index==end) index=restart;
*out++=(s32)value;
if(--count==0) break;
d=samples[index];
} while(1);
history=*(s32**)(state+8); history[0]=(s32)a;history[1]=(s32)b;history[2]=(s32)c;
*(u32*)(state+12)=phase;*(s32*)(state+16)=index;
}
void fn_80264F74(u8 arg0, void *arg1, u8 *state) {
u32 channel;
u8 bufferIndex;
u32 *d0,*d1,*d2;
u32 *s0,*s1,*s2;
u32 i;
switch(arg0) {
case 0:
bufferIndex=(state[0x24]+1)%3;
s0=*(u32**)arg1; s1=*(u32**)((u8*)arg1+4); s2=*(u32**)((u8*)arg1+8);
d0=((u32**)state)[bufferIndex];
d1=((u32**)(state+12))[bufferIndex];
d2=((u32**)(state+24))[bufferIndex];
for(i=0;i<160;i++) { *d0++=*s0++; *d1++=*s1++; *d2++=*s2++; }
*(s32*)(state+0x84)=(*(s32*)(state+0x60)>>16)+1;
*(u32*)(state+0x80)=*(u32*)(state+0x60)<<16;
if(--*(u32*)(state+0x64)==0) {
*(u32*)(state+0x64)=*(u32*)(state+0x68);
*(s32*)(state+0x60)=-*(s32*)(state+0x60);
}
for(channel=0;channel<3;channel++) {
*(u32*)(state+0x7c)=*(u32*)(state+0x5c);
*(u32*)(state+0x78)=*(u32*)(state+0x58);
switch(channel) {
case 0:
*(u32*)(state+0x70)=*(u32*)state;
*(u32*)(state+0x6c)=*(u32*)arg1;
*(void**)(state+0x74)=state+0x28; break;
case 1:
*(u32*)(state+0x70)=*(u32*)(state+12);
*(u32*)(state+0x6c)=*(u32*)((u8*)arg1+4);
*(void**)(state+0x74)=state+0x38; break;
case 2:
*(u32*)(state+0x70)=*(u32*)(state+24);
*(u32*)(state+0x6c)=*(u32*)((u8*)arg1+8);
*(void**)(state+0x74)=state+0x48; break;
}
switch(*(s32*)(state+0x84)) {
case 0: fn_80264BF0(state+0x6c); break;
case 1: fn_80264D88(state+0x6c); break;
}
}
*(u32*)(state+0x5c)=*(u32*)(state+0x7c)%480;
*(u32*)(state+0x58)=*(u32*)(state+0x78);
state[0x24]=bufferIndex;
break;
case 1: break;
}
}

extern s32 lbl_803631FC;
extern s32 lbl_80363200;
s32 fn_80265230(void *arg0) {
extern void *fn_802637A4(s32);
u8 *state=arg0;
s32 *a,*b,*c;
u32 i;
*(void **)state=fn_802637A4(0x1680);
if(*(void **)state!=0) {
*(u8 **)(state+12)=*(u8 **)state+0x780;
*(u8 **)(state+24)=*(u8 **)(state+12)+0x780;
*(u8 **)(state+4)=*(u8 **)state+0x280;
*(u8 **)(state+16)=*(u8 **)(state+12)+0x280;
*(u8 **)(state+28)=*(u8 **)(state+24)+0x280;
*(u8 **)(state+8)=*(u8 **)state+0x500;
*(u8 **)(state+20)=*(u8 **)(state+12)+0x500;
*(u8 **)(state+32)=*(u8 **)(state+24)+0x500;
a=*(s32**)state;b=*(s32**)(state+12);c=*(s32**)(state+24);
for(i=0;i<320;i++) { a[i]=0;b[i]=0;c[i]=0; }
state[0x24]=1;
*(u32*)(state+0x28)=*(u32*)(state+0x2c)=*(u32*)(state+0x30)=*(u32*)(state+0x34)=0;
*(u32*)(state+0x38)=*(u32*)(state+0x3c)=*(u32*)(state+0x40)=*(u32*)(state+0x44)=0;
*(u32*)(state+0x48)=*(u32*)(state+0x4c)=*(u32*)(state+0x50)=*(u32*)(state+0x54)=0;
*(u32*)(state+0x88)=480;*(u32*)(state+0x8c)=0;
*(u32*)(state+0x5c)=320-(*(u32*)(state+0x90)-5)*32;
*(u32*)(state+0x58)=0;
*(u32*)(state+0x5c)=(*(u32*)(state+0x5c)+(state[0x24]-1)*160)%480;
*(u32*)(state+0x68)=(*(u32*)(state+0x98)/5+1)&~1;
*(u32*)(state+0x64)=*(u32*)(state+0x68)/2;
*(u32*)(state+0x60)=(*(u32*)(state+0x94)<<16)/(*(u32*)(state+0x68)*5);
return 1;
}
return 0;
}
extern u64 lbl_8029F3D0[4];
extern u32 lbl_8029F3F0[4];

