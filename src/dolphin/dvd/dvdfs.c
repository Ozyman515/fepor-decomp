/* Functions from 0x801FC634 to 0x8022C1E8, found by decomp-toolkit. */
#include "common.h"
#include <dolphin/os.h>
#include "global.h"

/* Minimal DVDCommandBlock layout used by the DVD state machine. */
typedef struct DVDReadyCommand {
    u8 pad[8];
    s32 command; /* +0x08 */
    s32 state;   /* +0x0C */
    u8 pad10[0x18];
    void (*callback)(s32, void *); /* +0x28 */
} DVDReadyCommand;
extern u16 Scb_80339420[];
extern volatile u32 __DIRegs[16];

static inline void dvdClearDiStatus(void) {
    u32 *base = (u32 *)0xCC000000;
    u32 tmp = base[0x1801];
    u32 *di = base + 0x1800;
    di[1] = tmp;
}

typedef struct {
    u8 unk0;
    u8 pad1;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    u16 unk20;
} VITiming;
extern s32 PauseFlag_803685A4;
extern s32 PausingFlag_803685A8;
extern s32 FatalErrorFlag_803685B0;
extern void* executing_80368598;
extern u8 DummyCommandBlock_80339F80[48];
extern u32 lbl_803685B8;
extern void (*lbl_803685BC)(void*, void*);
extern void stateReady(void);
s32 fn_8020F0B8(DVDReadyCommand *block, void (*callback)(s32, void *));
extern void __DVDClearWaitingQueue(void);
extern u8 bb2Buf_80339FF8[];
extern s32 __DVDPopWaitingQueue(void);;
extern s32 gSaveDataBase;;
extern s32 fn_80013E50(s32);
extern s32 fn_80013E60(s32, s32);
extern s32 fn_80013E74(void*, s32);
extern s32 lbl_80366F60;
  extern char lbl_8029CFE8[];


extern s32 lbl_80368614;
extern void (*lbl_803685E8)(void);
extern void* lbl_80368618;
extern void* lbl_8036861C;
extern void* lbl_80368620;
extern void* lbl_80368624;
extern void* lbl_80368628;
extern void* lbl_8036862C;
extern void* lbl_80368630;
extern void* lbl_80368634;
extern void* lbl_80368638;
extern void* lbl_8036863C;
extern void* lbl_80368640;
extern void* lbl_80368644;
extern u16* lbl_80368648;
extern void* lbl_8036864C;
extern void* lbl_80368650;
extern void* lbl_80368654;

u8 ErrorCode2Num(s32);

extern u8 lbl_802820B8[];
extern u32 lbl_80368448;

static u32 sFaceResAddrs[8];
static u32 sFaceResIds[8];
static s16 lbl_80339328[8];
static s16 lbl_80339338[8];

extern s32 lbl_803679F0;

extern u16 lbl_8029B634[10];

#pragma opt_common_subs off

#pragma opt_common_subs reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

extern u16 lbl_8029B7FC[10];

#pragma opt_common_subs off

#pragma opt_common_subs reset

extern u16 lbl_8029B7A4[10];

#pragma opt_common_subs off

#pragma opt_common_subs reset

extern void *IDShouldBe_8036859C;
void fn_8020DAE0(u32 arg0);
extern void fn_8020C1A4(u8, u32, void *);

extern u8 lbl_80289EB8[16];

typedef struct OSResetFunctionInfo OSResetFunctionInfo;
struct OSResetFunctionInfo {
    BOOL (*func)(BOOL final);
    u32 priority;
    OSResetFunctionInfo *next;
    OSResetFunctionInfo *prev;
};

typedef struct OSResetFunctionQueue {
    OSResetFunctionInfo *head;
    OSResetFunctionInfo *tail;
} OSResetFunctionQueue;

extern OSResetFunctionQueue ResetFunctionQueue_803684E8;

typedef struct OSContext {
    u8 data[0x2C8];
} OSContext;

void OSRegisterResetFunction(OSResetFunctionInfo *info);
BOOL __OSCallResetFunctions(BOOL final);
void __OSReboot(u32 resetCode, u32 bootDol);
void OSClearContext(OSContext *context);
void OSSetCurrentContext(OSContext *context);
void fn_80206E1C(u32 bootDol, u32 resetCode, char **argv);
s32 __OSSyncSram(void);

extern void DecrementerExceptionCallback(void);

extern u32 __SPR_392;

extern u16 InterruptHandlerTable_803684C8[];

extern s32 StopAtNextInt_80368530;
extern u16 lbl_80368550;

extern u32 lbl_80368514;
extern u32 lbl_80368510;
extern s32 lbl_803684FC;
extern s32 lbl_80368500;
extern void (*lbl_803684F8)();

extern void* __OSSystemCallVectorStart;
extern void* __OSSystemCallVectorEnd;

typedef struct FSTEntry {
    u32 isDirAndStringOff;
    u32 parentOrPosition;
    u32 nextEntryOrLength;
} FSTEntry;

extern FSTEntry *FstStart_8036857C;
extern char *FstStringStart_80368580;
extern s32 currentDirectory;

#define entryIsDir(i) (((FstStart_8036857C[i].isDirAndStringOff & 0xFF000000) == 0) ? FALSE : TRUE)
#define stringOff(i) (FstStart_8036857C[i].isDirAndStringOff & ~0xFF000000)
#define parentDir(i) (FstStart_8036857C[i].parentOrPosition)

static inline BOOL DVDComparePathComponent(char *path, char *name) {
    s32 fn_80230CE0(s32);
    while (*name) {
        s32 first = fn_80230CE0(*name++);
        if (first != fn_80230CE0(*path++)) return FALSE;
    }
    if (*path == '/' || *path == 0) return TRUE;
    return FALSE;
}

static u32 myStrncpy(char *dest, char *src, u32 maxlen) {
    u32 i = maxlen;

    while ((i > 0) && (*src != 0)) {
        *dest++ = *src++;
        i--;
    }

    return maxlen - i;
}

extern u16 Scb_803394;

u32 __OSGetResetSWState(void);

extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);

void __DVDFSInit(void) {
extern void *BootInfo_80368578;
extern u32 MaxEntryNum_80368584;
FSTEntry *fst;
BootInfo_80368578=(void*)0x80000000;
FstStart_8036857C=*(FSTEntry**)0x80000038;
fst=FstStart_8036857C;
if(fst) {
MaxEntryNum_80368584=fst->nextEntryOrLength;
FstStringStart_80368580=(char*)(fst+MaxEntryNum_80368584);
}
}

u32 fn_8020C3E0(char *path) {
    extern u32 __DVDLongFileNameFlag;
    extern char lbl_8029CEE8[];
    extern s32 lbl_80366F60;
    void OSPanic(void *, s32, char *, ...);

    s32 more;
    u32 parent;
    char *end;
    s32 length;
    u32 entry;
    char *original;
    char *extension;
    s32 invalid;
    s32 dotted;

    original = path;
    entry = (u32)currentDirectory;

    for (;;) {
        if (*path == 0) {
            return entry;
        }
        if (*path == '/') {
            entry = 0;
            path++;
            continue;
        }
        if (*path == '.') {
            if (path[1] == '.') {
                if (path[2] == '/') {
                    entry = parentDir(entry);
                    path += 3;
                    continue;
                }
                if (path[2] == 0) {
                    return parentDir(entry);
                }
            } else {
                if (path[1] == '/') {
                    path += 2;
                    continue;
                }
                if (path[1] == 0) {
                    return entry;
                }
            }
        }
        if (!__DVDLongFileNameFlag) {
            end = path;
            dotted = 0;
            invalid = 0;
            while (*end && *end != '/') {
                if (*end == '.') {
                    if (end - path > 8 || dotted == 1) {
                        invalid = 1;
                        break;
                    }
                    extension = end + 1;
                    dotted = 1;
                } else if (*end == ' ') {
                    invalid = 1;
                }
                end++;
            }
            if (dotted == 1 && end - extension > 3) {
                invalid = 1;
            }
            if (invalid) {
                OSPanic(&lbl_80366F60, 0x183, lbl_8029CEE8, original);
            }
        } else {
            for (end = path; *end && *end != '/'; end++) {
            }
        }
        if (*end == 0) {
            more = 0;
        } else {
            more = 1;
        }
        parent = entry;
        length = end - path;
        for (entry++; entry < FstStart_8036857C[parent].nextEntryOrLength;) {
            if (entryIsDir(entry) || more != 1) {
                if (DVDComparePathComponent(path, FstStringStart_80368580 + stringOff(entry)) == 1) {
                    goto found;
                }
            }
            entry = entryIsDir(entry) ? FstStart_8036857C[entry].nextEntryOrLength : entry + 1;
        }
        return -1;
    found:
        if (!more) {
            return entry;
        }
        path += length;
        path++;
    }
}

s32 fn_8020C6D4(char *path, void *info) {
BOOL DVDGetCurrentDir(char *, u32);
void OSReport(char *, ...);
extern char lbl_8029CFB0[];
char currentPath[0x80];
s32 entry = fn_8020C3E0(path);
if (entry < 0) {
DVDGetCurrentDir(currentPath, 0x80);
OSReport(lbl_8029CFB0, path, currentPath);
return 0;
}
if (entryIsDir(entry)) return 0;
*(u32 *)((u8 *)info+0x30)=FstStart_8036857C[entry].parentOrPosition;
*(u32 *)((u8 *)info+0x34)=FstStart_8036857C[entry].nextEntryOrLength;
*(u32 *)((u8 *)info+0x38)=0;
*(u32 *)((u8 *)info+0xC)=0;
return 1;
}

s32 fn_8020C79C(void) {
    M2C_UNK fn_8020F334();
    fn_8020F334();
    return 1;
}

/* Recursively write "/parent/.../name" for an FST entry into path; returns length used. */
u32 entryToPath(u32 entry, char *path, u32 maxlen) {
    char *name;
    u32 loc;

    if (entry == 0) {
        return 0;
    }

    name = FstStringStart_80368580 + stringOff(entry);

    loc = entryToPath(parentDir(entry), path, maxlen);

    if (loc == maxlen) {
        return loc;
    }

    *(path + loc++) = '/';

    loc += myStrncpy(path + loc, name, maxlen - loc);

    return loc;
}

BOOL DVDConvertEntrynumToPath(s32 entrynum, char *path, u32 maxlen) {
    /* Build an absolute DVD path for entrynum; append '/' for directories. FALSE if truncated. */
    u32 loc;

    loc = entryToPath((u32)entrynum, path, maxlen);

    if (loc == maxlen) {
        path[maxlen - 1] = '\0';
        return FALSE;
    }

    if (entryIsDir(entrynum)) {
        if (loc == maxlen - 1) {
            path[loc] = '\0';
            return FALSE;
        }
        path[loc++] = '/';
    }

    path[loc] = '\0';
    return TRUE;
}

/* Build an absolute path for the current DVD directory into path. */
BOOL DVDGetCurrentDir(char *path, u32 maxlen) {
    return DVDConvertEntrynumToPath((s32)currentDirectory, path, maxlen);
}

#pragma use_lmw_stmw on
s32 fn_8020CB38(void *arg0, s32 arg1, s32 arg2, s32 arg3, void (*arg4)(s32, void *), s32 arg5) {
  void OSPanic(void *, s32, char *, ...);
  s32 DVDReadAbsAsyncPrio(void *, s32, s32, s32, void (*)(s32, void *), s32);
  void fn_8020CBF8(s32, void *);
  extern s32 lbl_80366F60;
  s32 temp_r4;

  if ((arg3 < 0) || ((u32)arg3 > *(u32 *)((u8 *)arg0 + 0x34))) {
    OSPanic(&lbl_80366F60, 0x2EE, lbl_8029CFE8);
  }
  temp_r4 = arg3 + arg2;
  if ((temp_r4 < 0) || ((u32)temp_r4 >= *(u32 *)((u8 *)arg0 + 0x34) + 0x20)) {
    OSPanic(&lbl_80366F60, 0x2F4, lbl_8029CFE8);
  }
  *(void (**)(s32, void *))((u8 *)arg0 + 0x38) = arg4;
  DVDReadAbsAsyncPrio(arg0, arg1, arg2, *(s32 *)((u8 *)arg0 + 0x30) + arg3, fn_8020CBF8, arg5);
  return 1;
}
#pragma use_lmw_stmw reset
void fn_8020CBF8(s32 result, void *arg1) { if (*(void (**)(s32, void *))((char *)arg1+0x38) != NULL) (*(void (**)(s32, void *))((char *)arg1+0x38))(result,arg1); }

s32 fn_8020CC28(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void OSPanic(void *, s32, char *, ...);
    void fn_8020CD40(void);
    s32 DVDReadAbsAsyncPrio(void *, s32, s32, s32, void (*)(void), s32);
    void OSSleepThread(void *);
    extern void *__DVDThreadQueue;
    extern char lbl_8029D01C[];
    s32 state;
    s32 interrupts;
    s32 end;
    void *block;
    s32 result;
    if (arg3 < 0 || (u32)arg3 > *(u32 *)((u8 *)arg0 + 0x34))
        OSPanic(&lbl_80366F60, 0x334, lbl_8029D01C);
    end = arg3 + arg2;
    if (end < 0 || (u32)end >= *(u32 *)((u8 *)arg0 + 0x34) + 0x20)
        OSPanic(&lbl_80366F60, 0x33A, lbl_8029D01C);
    block = arg0;
    result = DVDReadAbsAsyncPrio(block, arg1, arg2, *(u32 *)((u8 *)arg0+0x30)+arg3, fn_8020CD40, arg4);
    if (result == 0)
        return -1;
    interrupts = OSDisableInterrupts();
    for (;;) {
        state = ((DVDReadyCommand *)arg0)->state;
        if (state == 0) { result = *(s32 *)((u8 *)arg0+0x20); break; }
        if (state == -1) { result = -1; break; }
        if (state == 10) { result = -3; break; }
        OSSleepThread(&__DVDThreadQueue);
    }
    OSRestoreInterrupts(interrupts);
    return result;
}

void fn_8020CD40(void) {
    extern void* __DVDThreadQueue;
    fn_8020AEC4(&__DVDThreadQueue);
}

s32 fn_8020CD64(char *path, void *dir) {
    BOOL DVDConvertEntrynumToPath(s32, char *, u32);
    void OSReport(char *, ...);
    extern char lbl_8029D04C[];
    char currentPath[0x80];
    s32 entry = fn_8020C3E0(path);
    if (entry < 0) {
        DVDConvertEntrynumToPath(currentDirectory, currentPath, 0x80);
        OSReport(lbl_8029D04C, path, currentPath);
        return 0;
    }
    if (!entryIsDir(entry)) return 0;
    *(s32 *)dir = entry;
    *(s32 *)((u8 *)dir + 4) = entry + 1;
    *(u32 *)((u8 *)dir + 8) = FstStart_8036857C[entry].nextEntryOrLength;
    return 1;
}

s32 fn_8020CE24(void *arg0, void *arg1) {
    u8 *dir;
    u8 *entry;
    u32 loc;
    u32 next;

    dir = (u8 *)arg0;
    entry = (u8 *)arg1;

    loc = *(u32 *)(dir + 4);

    if (loc <= *(u32 *)dir || *(u32 *)(dir + 8) <= loc) {
        return 0;
    }

    *(u32 *)entry = loc;
    *(u32 *)(entry + 4) = entryIsDir(loc);
    *(char **)(entry + 8) =
        FstStringStart_80368580 + stringOff(loc);

    if (entryIsDir(loc)) {
        next = FstStart_8036857C[loc].nextEntryOrLength;
    } else {
        next = loc + 1;
    }
    *(u32 *)(dir + 4) = next;

    return 1;
}

s32 fn_8020CEC8(void) {
    return 1;
}

void fn_8020CED0(void) {

}

#pragma dont_inline on
#pragma optimization_level 3
void DVDInit(void) {
 extern s32 DVDInitialized_803685DC;
 extern const char *__DVDVersion;
 extern u32 MotorState_803685D8;
 extern u8 *bootInfo_803685A0;
 extern s32 FirstTimeInBootrom_803685D4;
 extern void *__DVDThreadQueue;
 extern void __DVDInitWA(void);
 extern void __DVDInterruptHandler(s16, OSContext *);
 extern void __fstLoad(void);
 void OSReport(const char*,...);
 if(DVDInitialized_803685DC==0) {
 OSRegisterVersion(__DVDVersion); DVDInitialized_803685DC=1;
 __DVDFSInit(); __DVDClearWaitingQueue(); __DVDInitWA();
 MotorState_803685D8=0; bootInfo_803685A0=(u8*)0x80000000; IDShouldBe_8036859C=bootInfo_803685A0;
 __OSSetInterruptHandler(0x15,__DVDInterruptHandler); __OSUnmaskInterrupts(0x400); OSInitThreadQueue((void*)&__DVDThreadQueue);
 *(volatile u32*)0xCC006000=0x2a; *(volatile u32*)0xCC006004=0;
 if(*(u32*)(bootInfo_803685A0+0x20)==0xE5207C22) { OSReport("load fst\n"); __fstLoad(); }
 else if(*(u32*)(bootInfo_803685A0+0x20)!=0x0D15EA5E) FirstTimeInBootrom_803685D4=1;
 }
}
#pragma optimization_level reset
#pragma dont_inline reset
void fn_8020CFAC(void) {
    extern void (*lbl_803685E0)(void *);
    extern u8 *bootInfo_803685A0;
    extern u8 BB2_80339F40[];
    extern s32 lbl_80366F74;
    extern char lbl_8029D0DC[];

    void OSPanic(void *, s32, char *, ...);
    s32 fn_8020BAD0(void *, u32, u32, void (*)(u32));
    void fn_8020D040(u32);

    lbl_803685E0 = (void (*)(void *))fn_8020CFAC;

    if (*(u32 *)(bootInfo_803685A0 + 0x3C) < *(u32 *)(BB2_80339F40 + 8)) {
        OSPanic(&lbl_80366F74, 0x295, lbl_8029D0DC);
    }

    fn_8020BAD0(
        *(void **)(bootInfo_803685A0 + 0x38),
        (*(u32 *)(BB2_80339F40 + 8) + 0x1F) & ~0x1F,
        *(u32 *)(BB2_80339F40 + 4),
        fn_8020D040
    );
}
#pragma global_optimizer reset
void fn_8020D040(u32 arg0) {
    void __DVDFSInit(void);
    void fn_8020D16C(void);
    void fn_8020D1A0(void);
    void stateReady(void);
    extern s32 lbl_803685CC;
    extern void *executing_80368598;
    extern u8 DummyCommandBlock_80339F80[];
    DVDReadyCommand *block;
    s32 zero;

    if (arg0 == 0x10) {
        fn_8020D16C();
        return;
    }
    if (arg0 & 1) {
        zero = 0;
        lbl_803685CC = zero;
        __DVDFSInit();
        block = (DVDReadyCommand *)executing_80368598;
        executing_80368598 = DummyCommandBlock_80339F80;
        block->state = zero;
        if (block->callback != NULL) {
            (*block->callback)(0, block);
        }
        stateReady();
        return;
    }
    fn_8020D1A0();
}

#pragma global_optimizer off
void cbForStateError(u32 arg0) {
    void fn_8020D16C(void);
    void fn_8020FAE0(void);
    void stateReady(void);

    DVDReadyCommand *block;
    void (*callback)(void *, void *);
    s32 one;

    ((DVDReadyCommand *)executing_80368598)->state = -1;

    if (arg0 == 0x10) {
        fn_8020D16C();
        return;
    }

    fn_8020FAE0();

    one = 1;
    block = (DVDReadyCommand *)executing_80368598;
    executing_80368598 = DummyCommandBlock_80339F80;
    FatalErrorFlag_803685B0 = one;

    if (block->callback != 0) {
        (*block->callback)(-1, block);
    }

    if (lbl_803685B8 != 0) {
        callback = lbl_803685BC;
        lbl_803685B8 = 0;

        if (callback != 0) {
            (*callback)(0, block);
        }
    }

    stateReady();
}
#pragma global_optimizer on
void fn_8020D16C(void) {
    M2C_UNK DVDReset();
    M2C_UNK __DVDStoreErrorCode(M2C_UNK);
    M2C_UNK cbForStateError(M2C_UNK);
    __DVDStoreErrorCode(0x01234568);
    DVDReset();
    cbForStateError(0);
}

void fn_8020D1A0(void) {
    void fn_8020BF58(void (*)(void));
    extern void fn_8020D27C(void);

    fn_8020BF58(fn_8020D27C);
}

s32 fn_8020D1C8(u32 arg0) {
    /* CategorizeError */
    extern void *executing_80368598;
    extern u32 lbl_803685C8;
    extern s32 lbl_803685CC;
    u32 temp_r4;

    if ((u32) (arg0 + 0xFFFE0000) == 0x400U) {
        lbl_803685C8 = arg0;
        return 1;
    }
    temp_r4 = arg0 & 0xFFFFFF;
    if (((u32) (temp_r4 + 0xFFFA0000) == 0x2800U) || ((u32) (temp_r4 + 0xFFFE0000) == 0x3A00U) || ((u32) (temp_r4 + 0xFFF50000) == 0x5A01U)) {
        return 0;
    }
    lbl_803685CC += 1;
    if ((s32) lbl_803685CC == 2) {
        if (temp_r4 == (u32) lbl_803685C8) {
            lbl_803685C8 = temp_r4;
            return 1;
        }
        lbl_803685C8 = temp_r4;
        return 2;
    }
    lbl_803685C8 = temp_r4;
    if (((u32) (temp_r4 + 0xFFFD0000) == 0x1100U) || (M2C_FIELD(executing_80368598, u32 *, 8) == 5U)) {
        return 2;
    }
    return 3;
}

void fn_8020D27C(u32 arg0) {
    void __DVDStoreErrorCode(u32);
    void DVDReset(void);
    void cbForStateError(u32);
    void DVDLowStopMotor(void (*)(u32));
    u32 fn_8020D1C8(u32);
    void stateReady(void);
    void fn_8020D5BC(void);
    void fn_8020BD68(u32, void *, void *);
    void fn_8020DD7C(void);
    void fn_8020DC14(void);
    extern void *executing_80368598;
    extern u32 lbl_803685B8;
    extern s32 ResumeFromHere_803685C0;
    extern u8 DummyCommandBlock_80339F80[];
    extern void (*lbl_803685BC)(void *, void *);
    extern void (*lbl_803685E0)(void *);
    extern void fn_8020D4E0(u32);

    typedef struct DVDReadyCommand {
        u8 pad[8];
        s32 command;
        s32 state;
        u8 pad10[0x18];
        void (*callback)(s32, void *);
    } DVDReadyCommand;

    DVDReadyCommand *temp_r30;
    u32 temp_r29;
    u32 temp_r28;
    u32 temp_r31;
    s32 var_r4;
    s32 var_r0;

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }
    if (arg0 & 2) {
        __DVDStoreErrorCode(0x01234567);
        DVDLowStopMotor(cbForStateError);
        return;
    }
    temp_r29 = *(u32 *)0xCC006020;
    temp_r28 = temp_r29 & 0xFF000000;
    temp_r31 = fn_8020D1C8(temp_r29);
    if (temp_r31 == 1) {
        __DVDStoreErrorCode(temp_r29);
        DVDLowStopMotor(cbForStateError);
        return;
    }
    if ((u32)(temp_r31 - 2) <= 1) {
        var_r4 = 0;
    } else if (temp_r28 == 0x01000000) {
        var_r4 = 4;
    } else if (temp_r28 == 0x02000000) {
        var_r4 = 6;
    } else if (temp_r28 == 0x03000000) {
        var_r4 = 3;
    } else {
        var_r4 = 5;
    }
    if (lbl_803685B8 != 0) {
        ResumeFromHere_803685C0 = var_r4;
        lbl_803685B8 = 0;
        temp_r30 = executing_80368598;
        executing_80368598 = DummyCommandBlock_80339F80;
        temp_r30->state = 0xA;
        if (temp_r30->callback != NULL) {
            temp_r30->callback(-3, temp_r30);
        }
        if (lbl_803685BC != NULL) {
            lbl_803685BC((void *)0, temp_r30);
        }
        stateReady();
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 == 0) {
        if (temp_r31 == 2) {
            __DVDStoreErrorCode(temp_r29);
            fn_8020D5BC();
            return;
        }
        if (temp_r31 == 3) {
            if ((temp_r29 & 0xFFFFFF) == 0x031100) {
                fn_8020BD68(*(u32 *)((u8 *)executing_80368598 + 0x10), (void *)fn_8020D4E0, executing_80368598);
                return;
            }
            lbl_803685E0(executing_80368598);
            return;
        }
        if (temp_r28 == 0x01000000) {
            ((DVDReadyCommand *)executing_80368598)->state = 5;
            fn_8020DD7C();
            return;
        }
        if (temp_r28 == 0x02000000) {
            ((DVDReadyCommand *)executing_80368598)->state = 3;
            fn_8020DC14();
            return;
        }
        if (temp_r28 == 0x03000000) {
            ((DVDReadyCommand *)executing_80368598)->state = 4;
            fn_8020DD7C();
            return;
        }
        __DVDStoreErrorCode(0x01234567);
        DVDLowStopMotor(cbForStateError);
    }
}

void fn_8020D4E0(u32 arg0) {
    /* cbForUnrecoveredError */
    void DVDReset(void);
    void __DVDStoreErrorCode(u32);
    void cbForStateError(u32);
    void fn_8020BF58(void *);
    void fn_8020D5BC(void);
    void fn_8020D53C(void);

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }
    if (arg0 & 1) {
        fn_8020D5BC();
        return;
    }
    fn_8020BF58(fn_8020D53C);
}

void fn_8020D53C(u32 arg0) {
    /* cbForUnrecoveredErrorRetry */
    void DVDReset(void);
    void __DVDStoreErrorCode(u32);
    void DVDLowStopMotor(void (*)(u32));
    void cbForStateError(u32);

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }

    if (arg0 & 2) {
        __DVDStoreErrorCode(0x01234567);
        DVDLowStopMotor(cbForStateError);
        return;
    }

    __DVDStoreErrorCode(__DIRegs[8]);
    DVDLowStopMotor(cbForStateError);
}

void fn_8020D5BC(void) {
    /* stateGoToRetry */
    void DVDLowStopMotor(void (*)(void));
    extern void fn_8020D5E4(void);

    DVDLowStopMotor(fn_8020D5E4);
}

void fn_8020D5E4(u32 arg0) {
    /* cbForStateGoToRetry */
    void __DVDStoreErrorCode(u32);
    void DVDReset(void);
    void cbForStateError(u32);
    void DVDLowStopMotor(void (*)(u32));
    void fn_8020DD7C(void);

    extern s32 lbl_803685CC;
    extern volatile s32 CurrCommand_803685B4;
    extern s32 ResetRequired_803685D0;
    extern u32 lbl_803685B8;
    extern void *executing_80368598;
    extern u8 DummyCommandBlock_80339F80[];
    extern s32 ResumeFromHere_803685C0;
    extern void (*lbl_803685BC)(void *, void *);

    DVDReadyCommand *finished;

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }

    if (arg0 & 2) {
        __DVDStoreErrorCode(0x01234567);
        DVDLowStopMotor(cbForStateError);
        return;
    }

    lbl_803685CC = 0;

    if (CurrCommand_803685B4 == 4 ||
        CurrCommand_803685B4 == 5 ||
        CurrCommand_803685B4 == 13 ||
        CurrCommand_803685B4 == 15) {
        ResetRequired_803685D0 = 1;
    }

    if (lbl_803685B8 != 0) {
        ResumeFromHere_803685C0 = 2;
        lbl_803685B8 = 0;

        finished = (DVDReadyCommand *)executing_80368598;
        executing_80368598 = DummyCommandBlock_80339F80;

        finished->state = 10;

        if (finished->callback != 0) {
            finished->callback(-3, finished);
        }

        if (lbl_803685BC != 0) {
            lbl_803685BC(0, finished);
        }

        stateReady();
        return;
    }

    ((DVDReadyCommand *)executing_80368598)->state = 11;
    fn_8020DD7C();
}

#pragma global_optimizer off
void fn_8020D724(void) {
    /* stateCheckID */
    extern u16 BB2_80339F40[];
    extern volatile s32 CurrCommand_803685B4;
    extern void *executing_80368598;
    extern void *IDShouldBe_8036859C;
    extern void (*lbl_803685E0)(void *);

    s32 fn_8020F9E8(u8 *, u8 *);
    s32 fn_80231944(const void *, const void *, u32);
    void fn_8020D838();
    void fn_8020D804();
    void fn_8020D90C(u32);
    void DVDLowStopMotor(void (*)(u32));
    void DCInvalidateRange(void *, u32);

    u8 *base;
    DVDReadyCommand *block;
    base = (u8 *)BB2_80339F40;

    switch (CurrCommand_803685B4) {
    case 3:
        if (fn_8020F9E8(
                (base + 0x20),
                *(u8 **)((u8 *)executing_80368598 + 0x24))) {

            memcpy(IDShouldBe_8036859C, (base + 0x20), 0x20);

            block = (DVDReadyCommand *)executing_80368598;
            block->state = 1;

            DCInvalidateRange(base, 0x20);

            lbl_803685E0 = (void (*)(void *))fn_8020D838;
            fn_8020D838(executing_80368598);
        } else {
            DVDLowStopMotor(fn_8020D90C);
        }
    break;
    default:
        if (fn_80231944((base + 0x20), IDShouldBe_8036859C, 0x20) != 0) {
            DVDLowStopMotor(fn_8020D90C);
        } else {
            lbl_803685E0 = (void (*)(void *))fn_8020D804;
            fn_8020D804(executing_80368598);
        }
    }
}
#pragma global_optimizer on
void fn_8020D804(void) {
      /* DVD Disc ID Check */
      void fn_8020C1A4(u8, s32, void *);
      void fn_8020DAE0(u32);
    extern void *IDShouldBe_8036859C;

    fn_8020C1A4(
        ((u8 *)IDShouldBe_8036859C)[8],
        0xA,
        fn_8020DAE0
    );
}

void fn_8020D838(void) {
    /* DVD Disc ID Check */
    void fn_8020C1A4(u8, s32, void *);
    void fn_8020D86C(u32 arg0);
    extern void *IDShouldBe_8036859C;

    fn_8020C1A4(M2C_FIELD(IDShouldBe_8036859C, u8 *, 8), 0xA, fn_8020D86C);
}

void fn_8020D86C(u32 arg0) {
    void __DVDStoreErrorCode(u32);
    void DVDReset(void);
    void cbForStateError(u32);
    void fn_8020BF58(void *);
    void fn_8020D8D4();

    extern s32 lbl_803685CC;

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }

    if (arg0 & 1) {
        lbl_803685CC = 0;
        fn_8020D8D4(executing_80368598);
        return;
    }

    fn_8020BF58((void *)fn_8020D27C);
}

void fn_8020D8D4(void) {
    extern u16 BB2_80339F40[16];
    void fn_8020DA08(u32);
    void fn_8020BAD0(u16 *, s32, s32, void (*)(u32));

    fn_8020BAD0(BB2_80339F40, 0x20, 0x420, fn_8020DA08);
}

#pragma optimization_level 3
void fn_8020D90C(u32 arg0) {
    void __DVDStoreErrorCode(u32);
    void DVDReset(void);
    void cbForStateError(u32);
    void DVDLowStopMotor(void (*)(u32));
    void fn_8020DD7C(void);

    extern s32 lbl_803685CC;
    extern u32 lbl_803685B8;
    extern s32 ResumeFromHere_803685C0;
    extern void *executing_80368598;
    extern u8 DummyCommandBlock_80339F80[];
    extern void (*lbl_803685BC)(void *, void *);

    s32 flag;
    DVDReadyCommand *block;

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }

    if (arg0 & 2) {
        __DVDStoreErrorCode(0x01234567);
        DVDLowStopMotor(cbForStateError);
        return;
    }

    flag = 0;
    lbl_803685CC = flag;
    if (lbl_803685B8 != 0) {
        block = (DVDReadyCommand *)executing_80368598;
        ResumeFromHere_803685C0 = 1;
        lbl_803685B8 = flag;
        executing_80368598 = DummyCommandBlock_80339F80;
        block->state = 0xA;
        if (block->callback != NULL) {
            block->callback(-3, block);
        }
        if (lbl_803685BC != NULL) {
            lbl_803685BC((void *)0, block);
        }
        stateReady();
        flag = 1;
    }
    if (flag == 0) {
        ((DVDReadyCommand *)executing_80368598)->state = 6;
        fn_8020DD7C();
    }
}
#pragma optimization_level reset
void fn_8020DA08(u32 arg0) {
    void __DVDStoreErrorCode(u32);
    void DVDReset(void);
    void fn_8020BF58(void *);
    s32 fn_8020BAD0(void *, u32, u32, void (*)(u32));
    void fn_8020D040(u32);
    void OSPanic(void *, s32, char *, ...);
    extern void (*lbl_803685E0)(void *);
    extern u8 *bootInfo_803685A0;
    extern u8 BB2_80339F40[];
    extern s32 lbl_80366F74;
    extern char lbl_8029D0DC[];
    extern s32 lbl_803685CC;
    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
    } else if (arg0 & 1) {
        lbl_803685CC = 0;
        lbl_803685E0 = (void (*)(void *))fn_8020CFAC;
        if (*(u32 *)(bootInfo_803685A0 + 0x3C) < *(u32 *)(BB2_80339F40 + 8))
            OSPanic(&lbl_80366F74, 0x295, lbl_8029D0DC);
        fn_8020BAD0(
            *(void **)(bootInfo_803685A0 + 0x38),
            (*(u32 *)(BB2_80339F40 + 8) + 0x1F) & ~0x1F,
            *(u32 *)(BB2_80339F40 + 4),
            fn_8020D040
        );
    } else {
        fn_8020BF58((void *)fn_8020D27C);
    }
}
#pragma optimization_level reset
void fn_8020DAE0(u32 arg0) {
    void __DVDStoreErrorCode(u32);
    void DVDReset(void);
    void cbForStateError(u32);
    void fn_8020BF58(void *);
    void stateBusy_8020E178(void *);
    void fn_8020D27C(void);

    extern s32 lbl_803685CC;
    extern s32 ResumeFromHere_803685C0;

    DVDReadyCommand *block;
    s32 cleaned;

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }

    if (arg0 & 1) {
        cleaned = 0;
        lbl_803685CC = 0;
        if (lbl_803685B8 != 0) {
            ResumeFromHere_803685C0 = 0;
            block = (DVDReadyCommand *)executing_80368598;
            lbl_803685B8 = 0;
            executing_80368598 = DummyCommandBlock_80339F80;
            block->state = 10;
            if (block->callback != 0) {
                block->callback(-3, block);
            }
            if (lbl_803685BC != 0) {
                lbl_803685BC((void *)0, block);
            }
            stateReady();
            cleaned = 1;
        }
        if (cleaned == 0) {
            ((DVDReadyCommand *)executing_80368598)->state = 1;
            stateBusy_8020E178(executing_80368598);
        }
    } else {
        fn_8020BF58((void *)fn_8020D27C);
    }
}

void AlarmHandler(void *alarm, void *context) {
    void DVDReset(void);
    void DCInvalidateRange(void *, u32);
    void fn_8020DCE8(void *);
    extern u8 lbl_80339F60[];
    extern void *executing_80368598;
    extern void (*lbl_803685E0)(void *);

    DVDReset();
    DCInvalidateRange(lbl_80339F60, 0x20);
    lbl_803685E0 = fn_8020DCE8;
    fn_8020DCE8(executing_80368598);
}

void fn_8020DC14(void) {
    extern u16 BB2_80339F40[];
    extern volatile s32 CurrCommand_803685B4;
    extern u32 MotorState_803685D8;
    void DVDReset(void);
    void OSCreateAlarm(void *);
    void OSSetAlarm(void *, u64, void (*)(void *, void *));
    void AlarmHandler(void *, void *);
    void __DVDClearWaitingQueue(void);

    u8 *bb2;
    DVDReadyCommand *block;

    bb2 = (u8 *)BB2_80339F40;

    switch (CurrCommand_803685B4) {
    case 4:
    case 5:
    case 13:
    case 15:
        __DVDClearWaitingQueue();
        block = (DVDReadyCommand *)executing_80368598;
        executing_80368598 = bb2 + 0x40;
        if (block->callback != 0) {
            block->callback(-4, block);
        }
        stateReady();
        break;
    default:
        MotorState_803685D8 = 0;
        DVDReset();
        OSCreateAlarm(bb2 + 0x70);
        OSSetAlarm(bb2 + 0x70, (u64)(((*(u32 *)0x800000f8 / 4) / 1000) * 1150), AlarmHandler);
        break;
    }
}

void fn_8020DCE8(void *block) {
    void fn_8020BE28(void *, void *);
    void fn_8020DD18(void);
    extern u8 lbl_80339F60[];

    fn_8020BE28(lbl_80339F60, fn_8020DD18);
}

void fn_8020DD18(u32 arg0)
{
    void __DVDStoreErrorCode(u32);
    void DVDReset(void);
    void cbForStateError(u32);
    void fn_8020BF58(void *);
    void fn_8020D724(void);
    void fn_8020D27C(void);
    extern s32 lbl_803685CC;

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }

    if (arg0 & 1) {
        lbl_803685CC = 0;
        fn_8020D724();
        return;
    }

    fn_8020BF58((void *)fn_8020D27C);
}

void fn_8020DD7C(void) {
    void DVDLowWaitCoverClose(void (*)(void));
    extern void cbForStateMotorStopped(void);
    DVDLowWaitCoverClose(cbForStateMotorStopped);
}

void cbForStateMotorStopped(void) {
    extern u16 BB2_80339F40[];
    extern volatile s32 CurrCommand_803685B4;
    extern u32 MotorState_803685D8;
    void DVDReset(void);
    void OSCreateAlarm(void *);
    void OSSetAlarm(void *, u64, void (*)(void *, void *));
    void AlarmHandler(void *, void *);
    void __DVDClearWaitingQueue(void);
    u8 *bb2;
    DVDReadyCommand *block;
    u32 pad[2];
    bb2 = (u8 *)BB2_80339F40;
    *(u32 *)0xCC006004=0;
    ((DVDReadyCommand *)executing_80368598)->state=3;
    switch (CurrCommand_803685B4) {
    case 4:
    case 5:
    case 13:
    case 15:
        __DVDClearWaitingQueue();
        block = (DVDReadyCommand *)executing_80368598;
        executing_80368598 = bb2 + 0x40;
        if (block->callback != 0) {
            block->callback(-4, block);
        }
        stateReady();
        break;
    default:
        MotorState_803685D8 = 0;
        DVDReset();
        OSCreateAlarm(bb2 + 0x70);
        OSSetAlarm(bb2 + 0x70, (u64)(((*(u32 *)0x800000f8 / 4) / 1000) * 1150), AlarmHandler);
        break;
    }
}

#pragma opt_common_subs off
/* Pop the next DVD command and enter its busy/resume path (Dolphin DVD state machine). */
void stateReady(void) {
    extern u16 BB2_80339F40[];
    extern volatile s32 CurrCommand_803685B4;
    extern s32 CancelLastError_803685C4;
    extern volatile u32 ResumeFromHere_803685C0;
    extern u32 MotorState_803685D8;
    s32 __DVDCheckWaitingQueue(void);
    void stateBusy_8020E178(void *);
    void DVDLowWaitCoverClose(void (*)(void));
    void cbForStateMotorStopped(void);
    void DVDReset(void);
    void OSCreateAlarm(void *);
    void OSSetAlarm(void *, u64, void (*)(void *, void *));
    void __DVDStoreErrorCode(s32);
    void DVDLowStopMotor(void (*)(u32));
    void cbForStateError(u32);
    u8 *bb2 = (u8 *)BB2_80339F40;
    void *block;
    void (*callback)(s32, void *);

    if (!__DVDCheckWaitingQueue()) {
        executing_80368598 = 0;
        return;
    }
    if (PauseFlag_803685A4) {
        PausingFlag_803685A8 = 1;
        executing_80368598 = 0;
        return;
    }
    executing_80368598 = (void *)__DVDPopWaitingQueue();
    if (FatalErrorFlag_803685B0) {
        ((DVDReadyCommand *)executing_80368598)->state = -1;
        block = executing_80368598;
        executing_80368598 = bb2 + 0x40;
        callback = *(void (**)(s32, void *))((u8 *)block + 0x28);
        if (callback)
            callback(-1, block);
        stateReady();
        return;
    }
    block = executing_80368598;
    CurrCommand_803685B4 = ((DVDReadyCommand *)block)->command;
    if (ResumeFromHere_803685C0 != 0U) {
        switch ((s32)ResumeFromHere_803685C0) {
        case 2:
            ((DVDReadyCommand *)executing_80368598)->state = 11;
            DVDLowWaitCoverClose(cbForStateMotorStopped);
            break;
        case 3:
            ((DVDReadyCommand *)executing_80368598)->state = 4;
            DVDLowWaitCoverClose(cbForStateMotorStopped);
            break;
        case 4:
            ((DVDReadyCommand *)executing_80368598)->state = 5;
            DVDLowWaitCoverClose(cbForStateMotorStopped);
            break;
        case 1:
        case 6:
        case 7:
            ((DVDReadyCommand *)block)->state = 3;
            switch (CurrCommand_803685B4) {
            case 4:
            case 5:
            case 13:
            case 15:
                __DVDClearWaitingQueue();
                block = executing_80368598;
                executing_80368598 = bb2 + 0x40;
                callback = *(void (**)(s32, void *))((u8 *)block + 0x28);
                if (callback)
                    callback(-4, block);
                stateReady();
                break;
            default:
                MotorState_803685D8 = 0;
                DVDReset();
                OSCreateAlarm(bb2 + 0x70);
                OSSetAlarm(bb2 + 0x70, (u64)(((*(u32 *)0x800000f8 / 4) / 1000) * 1150), AlarmHandler);
                break;
            }
            break;
        case 5:
            __DVDStoreErrorCode(CancelLastError_803685C4);
            DVDLowStopMotor(cbForStateError);
            break;
        }
        ResumeFromHere_803685C0 = 0;
        return;
    }
    if (MotorState_803685D8 == 0) {
        ((DVDReadyCommand *)executing_80368598)->state = 1;
        stateBusy_8020E178(executing_80368598);
        return;
    }
    switch (CurrCommand_803685B4) {
    case 4:
    case 5:
    case 13:
    case 15:
        __DVDClearWaitingQueue();
        block = executing_80368598;
        executing_80368598 = bb2 + 0x40;
        callback = *(void (**)(s32, void *))((u8 *)block + 0x28);
        if (callback)
            callback(-4, block);
        stateReady();
        break;
    default:
        MotorState_803685D8 = 0;
        DVDReset();
        OSCreateAlarm(bb2 + 0x70);
        OSSetAlarm(bb2 + 0x70, (u64)(((*(u32 *)0x800000f8 / 4) / 1000) * 1150), AlarmHandler);
        break;
    }
}
#pragma opt_common_subs reset
#pragma global_optimizer off
#pragma peephole off
void stateBusy_8020E178(void *arg0) {
    extern void (*lbl_803685E0)(void *);
    extern void *executing_80368598;
    extern u8 DummyCommandBlock_80339F80[];
    extern s32 lbl_803685AC;
    extern void (*lbl_80366F70)(void *, void *);
    void fn_8020BE28(void *, void *);
    void fn_8020BAD0(void *, void *, void *, void *);
    void fn_8020BD68(void *, void *);
    void DVDLowStopMotor(void *);
    void fn_8020C118(void *, void *);
    void fn_8020C080(void *, void *, void *, void *);
    void fn_8020C1A4(void *, void *, void *);
    void fn_8020BFE4(void *, void *);
    void stateReady(void);
    void fn_8020E4B8(void);
    u8 *b;
    void *old;
    void (*cb)(void *, void *);
    u32 remaining;
    u32 len;

    lbl_803685E0 = stateBusy_8020E178;
    b = (u8 *)arg0;

    switch (*(u32 *)(b + 0x8)) {
    case 5:
        dvdClearDiStatus();
        *(u32 *)(b + 0x1c) = 0x20;
        fn_8020BE28(*(void **)(b + 0x18), (void *)fn_8020E4B8);
        break;
    case 1:
    case 4:
        if (*(u32 *)(b + 0x14) == 0) {
            old = executing_80368598;
            executing_80368598 = DummyCommandBlock_80339F80;
            *(u32 *)((u8 *)old + 0xc) = 0;
            cb = *(void **)((u8 *)old + 0x28);
            if (cb) {
                cb(NULL, old);
            }
            stateReady();
        } else {
            dvdClearDiStatus();
            remaining = *(u32 *)(b + 0x14) - *(u32 *)(b + 0x20);
            if (remaining > 0x80000) {
                len = 0x80000;
            } else {
                len = remaining;
            }
            *(u32 *)(b + 0x1c) = len;
            fn_8020BAD0((void *)(*(u32 *)(b + 0x18) + *(u32 *)(b + 0x20)),
                        *(void **)(b + 0x1c),
                        (void *)(*(u32 *)(b + 0x10) + *(u32 *)(b + 0x20)),
                        (void *)fn_8020E4B8);
        }
        break;
    case 2:
        dvdClearDiStatus();
        fn_8020BD68(*(void **)(b + 0x10), (void *)fn_8020E4B8);
        break;
    case 3:
        DVDLowStopMotor((void *)fn_8020E4B8);
        break;
    case 15:
        DVDLowStopMotor((void *)fn_8020E4B8);
        break;
    case 6:
        dvdClearDiStatus();
        if (lbl_803685AC != 0) {
            *(u32 *)((u8 *)executing_80368598 + 0x1c) = 0;
            fn_8020C118(NULL, (void *)fn_8020E4B8);
        } else {
            *(u32 *)((u8 *)executing_80368598 + 0x1c) = 1;
            fn_8020C080(NULL, (void *)(u32)*(u32 *)(b + 0x14), (void *)(u32)*(u32 *)(b + 0x10), (void *)fn_8020E4B8);
        }
        break;
    case 7:
        dvdClearDiStatus();
        fn_8020C080((void *)0x10000, NULL, NULL, (void *)fn_8020E4B8);
        break;
    case 8:
        dvdClearDiStatus();
        lbl_803685AC = 1;
        fn_8020C080(NULL, NULL, NULL, (void *)fn_8020E4B8);
        break;
    case 9:
        dvdClearDiStatus();
        fn_8020C118(NULL, (void *)fn_8020E4B8);
        break;
    case 10:
        dvdClearDiStatus();
        fn_8020C118((void *)0x10000, (void *)fn_8020E4B8);
        break;
    case 11:
        dvdClearDiStatus();
        fn_8020C118((void *)0x20000, (void *)fn_8020E4B8);
        break;
    case 12:
        dvdClearDiStatus();
        fn_8020C118((void *)0x30000, (void *)fn_8020E4B8);
        break;
    case 13:
        dvdClearDiStatus();
        fn_8020C1A4(*(void **)(b + 0x10), *(void **)(b + 0x14), (void *)fn_8020E4B8);
        break;
    case 14:
        dvdClearDiStatus();
        *(u32 *)(b + 0x1c) = 0x20;
        fn_8020BFE4(*(void **)(b + 0x18), (void *)fn_8020E4B8);
        break;
    case 16:
        dvdClearDiStatus();
        DVDLowStopMotor((void *)fn_8020E4B8);
        break;
    case 0:
    default:
        lbl_80366F70(arg0, (void *)fn_8020E4B8);
        break;
    }
}
#pragma peephole reset
#pragma global_optimizer on

void fn_8020E4B8(u32 arg0) {
    void __DVDStoreErrorCode(u32);
    void DVDReset(void);
    void cbForStateError(u32);
    void DVDLowStopMotor(void (*)(u32));
    void DVDLowWaitCoverClose(void (*)(void));
    void cbForStateMotorStopped(void);
    void stateReady(void);
    void stateBusy_8020E178(void *);
    void fn_8020BF58(void *);
    void fn_8020C080(u32, u32, u32, void (*)(u32));
    void fn_8020D27C(u32);
    extern u16 BB2_80339F40[];
    extern volatile u32 CurrCommand_803685B4;
    extern s32 lbl_803685CC;
    extern s32 ResetRequired_803685D0;
    extern u32 lbl_803685B8;
    extern void *executing_80368598;
    extern s32 ResumeFromHere_803685C0;
    extern void (*lbl_803685BC)(void *, void *);
    extern u32 lbl_80366F7C;
    extern s32 MotorState_803685D8;
    extern u32 lbl_8029D154[];
    extern s32 lbl_803685AC;

    typedef struct DVDReadyCommand {
        u8 pad[8];
        s32 command;
        s32 state;
        u32 unk10;
        u32 unk14;
        u32 unk18;
        u32 unk1C;
        u32 unk20;
        u8 pad24[4];
        void (*callback)(s32, void *);
    } DVDReadyCommand;

    DVDReadyCommand *block;
    u8 *base;
    u32 cmd;
    s32 flag;
    s32 zero;
    u32 *di;
    u32 *tbl;
    u32 val;

    base = (u8 *)BB2_80339F40;
    di = (u32 *)0xCC006000;

    if (arg0 == 0x10) {
        __DVDStoreErrorCode(0x01234568);
        DVDReset();
        cbForStateError(0);
        return;
    }

    if (CurrCommand_803685B4 == 3 || CurrCommand_803685B4 == 0xF) {
        if (arg0 & 2) {
            __DVDStoreErrorCode(0x01234567);
            DVDLowStopMotor(cbForStateError);
            return;
        }
        zero = 0;
        lbl_803685CC = zero;
        if (CurrCommand_803685B4 == 0xF) {
            ResetRequired_803685D0 = 1;
        }
        if (lbl_803685B8 != 0) {
            ResumeFromHere_803685C0 = 7;
            block = (DVDReadyCommand *)executing_80368598;
            lbl_803685B8 = zero;
            executing_80368598 = base + 0x40;
            block->state = 0xA;
            if (block->callback != NULL) {
                block->callback(-3, block);
            }
            if (lbl_803685BC != NULL) {
                lbl_803685BC((void *)0, block);
            }
            stateReady();
            flag = 1;
        } else {
            flag = 0;
        }
        if (flag == 0) {
            ((DVDReadyCommand *)executing_80368598)->state = 7;
            DVDLowWaitCoverClose(cbForStateMotorStopped);
        }
        return;
    }

    cmd = CurrCommand_803685B4;
    if (cmd == 1 || (cmd - 4) <= 1 || cmd == 0xE) {
        flag = 1;
    } else if (cmd == lbl_80366F7C) {
        flag = 1;
    } else {
        flag = 0;
    }
    if (flag != 0) {
        block = (DVDReadyCommand *)executing_80368598;
        block->unk20 = block->unk20 + (block->unk1C - di[6]);
    }

    if (arg0 & 8) {
        zero = 0;
        block = (DVDReadyCommand *)executing_80368598;
        lbl_803685B8 = zero;
        executing_80368598 = base + 0x40;
        block->state = 0xA;
        if (block->callback != NULL) {
            block->callback(-3, block);
        }
        if (lbl_803685BC != NULL) {
            lbl_803685BC((void *)0, block);
        }
        stateReady();
        return;
    }

    if (arg0 & 1) {
        zero = 0;
        lbl_803685CC = zero;
        if (CurrCommand_803685B4 == 0x10) {
            block = (DVDReadyCommand *)executing_80368598;
            MotorState_803685D8 = 1;
            executing_80368598 = base + 0x40;
            block->state = zero;
            if (block->callback != NULL) {
                block->callback(0, block);
            }
            stateReady();
            return;
        }
        if (lbl_803685B8 != 0) {
            ResumeFromHere_803685C0 = zero;
            block = (DVDReadyCommand *)executing_80368598;
            lbl_803685B8 = zero;
            executing_80368598 = base + 0x40;
            block->state = 0xA;
            if (block->callback != NULL) {
                block->callback(-3, block);
            }
            if (lbl_803685BC != NULL) {
                lbl_803685BC((void *)0, block);
            }
            stateReady();
            flag = 1;
        } else {
            flag = 0;
        }
        if (flag != 0) {
            return;
        }
        cmd = CurrCommand_803685B4;
        if (cmd == 1 || (cmd - 4) <= 1 || cmd == 0xE) {
            flag = 1;
        } else if (cmd == lbl_80366F7C) {
            flag = 1;
        } else {
            flag = 0;
        }
        if (flag != 0) {
            block = (DVDReadyCommand *)executing_80368598;
            if (block->unk20 != block->unk14) {
                stateBusy_8020E178(block);
                return;
            }
            executing_80368598 = base + 0x40;
            block->state = 0;
            if (block->callback != NULL) {
                block->callback((s32)block->unk20, block);
            }
            stateReady();
            return;
        }
        cmd = CurrCommand_803685B4;
        if ((cmd - 9) <= 3) {
            flag = 1;
        } else {
            tbl = lbl_8029D154;
            if (cmd == *tbl) {
                flag = 1;
            } else {
                tbl++;
                if (cmd == *tbl) {
                    flag = 1;
                } else if (cmd == tbl[1]) {
                    flag = 1;
                } else {
                    flag = 0;
                }
            }
        }
        if (flag != 0) {
            if (CurrCommand_803685B4 == 0xB || CurrCommand_803685B4 == 0xA) {
                val = di[8] << 2;
            } else {
                val = di[8];
            }
            block = (DVDReadyCommand *)executing_80368598;
            executing_80368598 = base + 0x40;
            block->state = 0;
            if (block->callback != NULL) {
                block->callback((s32)val, block);
            }
            stateReady();
            return;
        }
        if (CurrCommand_803685B4 == 6) {
            block = (DVDReadyCommand *)executing_80368598;
            if (block->unk1C == 0) {
                if (di[8] & 1) {
                    executing_80368598 = base + 0x40;
                    block->state = 9;
                    if (block->callback != NULL) {
                        block->callback(-2, block);
                    }
                    stateReady();
                    return;
                }
                lbl_803685AC = 0;
                block->unk1C = 1;
                fn_8020C080(0, ((DVDReadyCommand *)executing_80368598)->unk14,
                            ((DVDReadyCommand *)executing_80368598)->unk10, fn_8020E4B8);
                return;
            }
            executing_80368598 = base + 0x40;
            block->state = 0;
            if (block->callback != NULL) {
                block->callback(0, block);
            }
            stateReady();
            return;
        }
        block = (DVDReadyCommand *)executing_80368598;
        executing_80368598 = base + 0x40;
        block->state = 0;
        if (block->callback != NULL) {
            block->callback(0, block);
        }
        stateReady();
        return;
    }

    if (CurrCommand_803685B4 == 0xE) {
        __DVDStoreErrorCode(0x01234567);
        DVDLowStopMotor(cbForStateError);
        return;
    }

    if (CurrCommand_803685B4 == 1 || CurrCommand_803685B4 == 4 || CurrCommand_803685B4 == 5 ||
        CurrCommand_803685B4 == 0xE) {
        block = (DVDReadyCommand *)executing_80368598;
        if (block->unk20 == block->unk14) {
            zero = 0;
            if (lbl_803685B8 != 0) {
                ResumeFromHere_803685C0 = zero;
                lbl_803685B8 = zero;
                executing_80368598 = base + 0x40;
                block->state = 0xA;
                if (block->callback != NULL) {
                    block->callback(-3, block);
                }
                if (lbl_803685BC != NULL) {
                    lbl_803685BC((void *)0, block);
                }
                stateReady();
                flag = 1;
            } else {
                flag = 0;
            }
            if (flag == 0) {
                block = (DVDReadyCommand *)executing_80368598;
                executing_80368598 = base + 0x40;
                block->state = 0;
                if (block->callback != NULL) {
                    block->callback((s32)block->unk20, block);
                }
                stateReady();
            }
            return;
        }
    }
    fn_8020BF58(fn_8020D27C);
}

s32 DVDReadAbsAsyncPrio(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, s32 arg5)
{
    void DCInvalidateRange(void *, u32);
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    s32 __DVDPushWaitingQueue(s32, void *);
    void stateReady(void);

    extern s32 autoInvalidation_80366F6C;
    extern void *executing_80368598;
    extern s32 PauseFlag_803685A4;

    u8 *block;
    u32 addr;
    u32 length;
    u32 command;
    s32 result;
    u32 interrupts;

    block = (u8 *)arg0;
    addr=arg1;
    length=arg2;

    *(u32 *)(block + 0x08) = 1;
    *(u32 *)(block + 0x18) = addr;
    *(u32 *)(block + 0x14) = length;
    *(u32 *)(block + 0x10) = arg3;
    *(u32 *)(block + 0x20) = 0;
    *(u32 *)(block + 0x28) = arg4;

    if (autoInvalidation_80366F6C) {
        command = *(u32 *)(block + 0x08);

        if (command == 1 ||
            (u32)(command - 4) <= 1 ||
            command == 14) {
            DCInvalidateRange(
                *(void **)(block + 0x18),
                *(u32 *)(block + 0x14)
            );
        }
    }

    interrupts = OSDisableInterrupts();

    *(u32 *)(block + 0x0C) = 2;

    result = __DVDPushWaitingQueue(arg5, arg0);

    if (executing_80368598 == 0 &&
        PauseFlag_803685A4 == 0) {
        stateReady();
    }

    OSRestoreInterrupts(interrupts);

    return result;
}

s32 fn_8020EBEC(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
    void DCInvalidateRange(void *, u32);
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    s32 __DVDPushWaitingQueue(s32, void *);
    void stateReady(void);

    extern s32 autoInvalidation_80366F6C;
    extern void *executing_80368598;
    extern s32 PauseFlag_803685A4;

    s32 result;
    u32 interrupts;
    u32 command;
    u32 addr;
    u32 length;
    register u8 *block;

    block = (u8 *)arg0;
    addr = arg1;
    length = arg2;

    *(u32 *)(block + 0x08) = 4;
    *(u32 *)(block + 0x18) = addr;
    *(u32 *)(block + 0x14) = length;
    *(u32 *)(block + 0x10) = arg3;
    *(u32 *)(block + 0x20) = 0;
    *(u32 *)(block + 0x28) = arg4;

    if (autoInvalidation_80366F6C) {
        command = *(u32 *)(block + 0x08);

        if (command == 1 ||
            (u32)(command - 4) <= 1 ||
            command == 14) {
            DCInvalidateRange(
                *(void **)(block + 0x18),
                *(u32 *)(block + 0x14)
            );
        }
    }

    interrupts = OSDisableInterrupts();

    *(u32 *)(block + 0x0C) = 2;

    result = __DVDPushWaitingQueue(2, block);

    if (executing_80368598 == 0 &&
        PauseFlag_803685A4 == 0) {
        stateReady();
    }

    OSRestoreInterrupts(interrupts);

    return result;
}

s32 DVDReadDiskID(u8 *block, void *arg1, void *callback) {
    void DCInvalidateRange(void *, u32);
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    s32 __DVDPushWaitingQueue(s32, void *);
    extern s32 autoInvalidation_80366F6C;
    s32 result;
    u8 pad[8];
    *(u32 *)(block + 8) = 5;
    *(void **)(block + 0x18) = arg1;
    *(u32 *)(block + 0x14) = 0x20;
    *(u32 *)(block + 0x10) = 0;
    *(u32 *)(block + 0x20) = 0;
    *(void **)(block + 0x28) = callback;
    {
        u32 enabled;
        u32 command;
        if (autoInvalidation_80366F6C != 0) {
            command = *(u32 *)(block + 8);
            if (command == 1 || command - 4 <= 1 || command == 14)
                DCInvalidateRange(*(void **)(block + 0x18), *(u32 *)(block + 0x14));
        }
        enabled = OSDisableInterrupts();
        *(u32 *)(block + 0xC) = 2;
        result = __DVDPushWaitingQueue(2, block);
        if (executing_80368598 == 0 && PauseFlag_803685A4 == 0)
            stateReady();
        OSRestoreInterrupts(enabled);
    }
    return result;
}

s32 fn_8020ED90(u8 *block, u32 callback) {
  void DCInvalidateRange(void *, u32);
  u32 OSDisableInterrupts(void);
  void OSRestoreInterrupts(u32);
  s32 __DVDPushWaitingQueue(s32, void *);
  void stateReady(void);
  extern s32 autoInvalidation_80366F6C;
  extern void *executing_80368598;
  extern s32 PauseFlag_803685A4;
  s32 result;
  u32 interrupts;
  u32 command;
  u32 pad[2];

  (void)pad;
  *(u32 *)(block + 8) = 7;
  *(u32 *)(block + 0x28) = callback;
  if (autoInvalidation_80366F6C != 0) {
    command = *(u32 *)(block + 8);
    if (command == 1 || command - 4 <= 1 || command == 14)
      DCInvalidateRange(*(void **)(block + 0x18), *(u32 *)(block + 0x14));
  }
  interrupts = OSDisableInterrupts();
  *(u32 *)(block + 0xC) = 2;
  result = __DVDPushWaitingQueue(1, block);
  if (executing_80368598 == 0 && PauseFlag_803685A4 == 0)
    stateReady();
  OSRestoreInterrupts(interrupts);
  return result;
}

s32 DVDInquiryAsync(u8 *block, s32 arg1, s32 arg2) {
    void DCInvalidateRange(void *, u32);
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    s32 __DVDPushWaitingQueue(s32, void *);
    extern s32 autoInvalidation_80366F6C;
    s32 result;
    u8 pad[8];
    *(u32 *)(block + 8) = 14;
    *(s32 *)(block + 0x18) = arg1;
    *(u32 *)(block + 0x14) = 32;
    *(u32 *)(block + 0x20) = 0;
    *(s32 *)(block + 0x28) = arg2;
    {
        u32 enabled;
        u32 command;
        if (autoInvalidation_80366F6C != 0) {
            command = *(u32 *)(block + 8);
            if (command == 1 || command - 4 <= 1 || command == 14)
                DCInvalidateRange(*(void **)(block + 0x18), *(u32 *)(block + 0x14));
        }
        enabled = OSDisableInterrupts();
        *(u32 *)(block + 0xC) = 2;
        result = __DVDPushWaitingQueue(2, block);
        if (executing_80368598 == 0 && PauseFlag_803685A4 == 0)
            stateReady();
        OSRestoreInterrupts(enabled);
    }
    return result;
}

#pragma global_optimizer off
#pragma peephole off
void DVDReset(void) {
    extern s32 ResetRequired_803685D0;
    extern s32 ResumeFromHere_803685C0;
    u32 *base;
    u32 *di;
    u32 tmp;
    DVDLowReset();
    base = (u32 *)0xCC000000;
    base[0x1800] = 0x2A;
    di = base + 0x1800;
    tmp = base[0x1801];
    di[1] = tmp;
    ResetRequired_803685D0 = 0;
    ResumeFromHere_803685C0 = 0;
}
#pragma peephole reset
#pragma global_optimizer reset

s32 DVDGetCommandBlockStatus(void *arg0) {
    s32 temp_r0;
    s32 var_r31;

    OSDisableInterrupts();
    temp_r0 = *(s32 *)((char *)arg0 + 0xC);
    if (temp_r0 == 3) {
        var_r31 = 1;
    } else {
        var_r31 = temp_r0;
    }
    OSRestoreInterrupts();
    return var_r31;
}

s32 DVDGetDriveStatus(void) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    s32 enabled;
    s32 ret;
    s32 level[2];
    void *exec;

    enabled = OSDisableInterrupts();
    if (FatalErrorFlag_803685B0 != 0) {
        ret = -1;
    } else if (PausingFlag_803685A8 != 0) {
        ret = 8;
    } else {
        exec = executing_80368598;
        if (exec == NULL) {
            ret = 0;
        } else if (exec == DummyCommandBlock_80339F80) {
            ret = 0;
        } else {
            level[0] = OSDisableInterrupts();
            ret = *(s32 *)((u8 *)exec + 0xC);
            if (ret == 3) {
                ret = 1;
            }
            OSRestoreInterrupts(level[0]);
        }
    }
    OSRestoreInterrupts(enabled);
    return ret;
}

s32 fn_8020F058(s32 arg0) {
    extern s32 autoInvalidation_80366F6C;
    s32 temp_r0;

    temp_r0 = autoInvalidation_80366F6C;
    autoInvalidation_80366F6C = arg0;
    return temp_r0;
}

#pragma peephole off
#pragma global_optimizer off
void fn_8020F068(void) {
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    u32 enabled;
    enabled = OSDisableInterrupts();
    *(volatile s32 *)&PauseFlag_803685A4 = 0;
    if (*(volatile s32 *)&PausingFlag_803685A8 != 0) {
        *(volatile s32 *)&PausingFlag_803685A8 = 0;
        stateReady();
    }
    OSRestoreInterrupts(enabled);
}

#pragma opt_common_subs off
s32 fn_8020F0B8(DVDReadyCommand *block, void (*callback)(s32, void *)) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    BOOL fn_8020C2FC(void);
    void *fn_8020C310(void);
    s32 fn_8020F7F0(void *);
    void cbForStateMotorStopped(void);
    extern s32 ResumeFromHere_803685C0;
    void (*cb)(s32, void *);
    s32 enabled;
    u8 pad[8];

    enabled = OSDisableInterrupts();
    cb = callback;

    switch (block->state) {
    case -1:
    case 0:
    case 10:
        if (cb) {
            cb(0, block);
        }
        break;
    case 1:
        if (lbl_803685B8) {
            OSRestoreInterrupts(enabled);
            return 0;
        }
        lbl_803685BC = (void (*)(void *, void *))cb;
        lbl_803685B8 = 1;
        if ((u32)block->command == 4U) {
            goto state2;
        }
        if ((u32)block->command == 1U) {
            fn_8020C2FC();
        }
        break;
    case 2:
    state2:
        fn_8020F7F0(block);
        block->state = 10;
        cb = block->callback;
        if (cb) {
            cb(-3, block);
        }
        cb = callback;
    case 3:
        if (cb) {
            cb(0, block);
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 11:
        switch (block->command) {
        case 4:
        case 5:
        case 13:
        case 15:
            if (cb) {
                cb(0, block);
            }
            break;
        default:
            if (lbl_803685B8) {
                OSRestoreInterrupts(enabled);
                return 0;
            }
            lbl_803685BC = (void (*)(void *, void *))cb;
            lbl_803685B8 = 1;
            break;
        }
        break;
    case 8:
    case 9:
        if (fn_8020C310() != (void *)cbForStateMotorStopped) {
            OSRestoreInterrupts(enabled);
            return 0;
        }
        if (block->state == 4) {
            ResumeFromHere_803685C0 = 3;
        }
        if (block->state == 5) {
            ResumeFromHere_803685C0 = 4;
        }
        if (block->state == 6) {
            ResumeFromHere_803685C0 = 1;
        }
        if (block->state == 11) {
            ResumeFromHere_803685C0 = 2;
        }
        if (block->state == 7) {
            ResumeFromHere_803685C0 = 7;
        }
        executing_80368598 = DummyCommandBlock_80339F80;
        block->state = 10;
        cb = block->callback;
        if (cb) {
            cb(-3, block);
        }
        cb = callback;
        if (cb) {
            cb(0, block);
        }
        stateReady();
        break;
    }

    OSRestoreInterrupts(enabled);
    return 1;
}
#pragma opt_common_subs reset
s32 fn_8020F334(void *arg0) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void OSSleepThread(void *);
    s32 fn_8020F0B8(void *, void *);
    extern M2C_UNK __DVDThreadQueue;
    extern M2C_UNK fn_8020F3E0;
    s32 interrupts;
    s32 state;
    u32 command;

    if (fn_8020F0B8(arg0, &fn_8020F3E0) == 0) {
        return -1;
    }
    interrupts = OSDisableInterrupts();
    while (1) {
        state = ((DVDReadyCommand *)arg0)->state;
        if ((u32)(state + 1) <= 1U) break;
        if (state == 10) break;
        if (state == 3) {
            command = (u32)((DVDReadyCommand *)arg0)->command;
            if ((u32)(command - 4) <= 1U) break;
            if (command == 13) break;
            if (command == 15) break;
        }
        OSSleepThread(&__DVDThreadQueue);
    }
    OSRestoreInterrupts(interrupts);
    return 0;
}

#pragma global_optimizer on
#pragma peephole on
void fn_8020F3E0(void) {
    extern void* __DVDThreadQueue;
    fn_8020AEC4(&__DVDThreadQueue);
}

s32 fn_8020F404(void) {
    return 0x80000000;
}

s32 DVDKeepAlive(void)
{
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    extern s32 FatalErrorFlag_803685B0;
    extern s32 PausingFlag_803685A8;
    extern void *executing_80368598;
    extern u32 ResumeFromHere_803685C0;
    extern u8 DummyCommandBlock_80339F80[];
    extern volatile u32 __DIRegs[16];
    s32 enabled;
    s32 state;
    void *exec;
    u32 diStatus;
    s32 result;

    enabled = OSDisableInterrupts();

    if (FatalErrorFlag_803685B0 != 0) {
        state = -1;
    } else if (PausingFlag_803685A8 != 0) {
        state = 8;
    } else {
        exec = executing_80368598;
        if (exec == 0) {
            state = 0;
        } else if (exec == (void *)DummyCommandBlock_80339F80) {
            state = 0;
        } else {
            state = *(s32 *)((u8 *)exec + 0xC);
        }
    }

    switch (state) {
    case 1:
    case 2:
    case 9:
    case 10:
        result = 1;
        break;
    case -1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 11:
        result = 0;
        break;
    case 0:
    case 8:
        diStatus = ((u32 *)__DIRegs)[1];
        if ((((diStatus >> 2) & 1) != 0) || ((diStatus & 1) != 0)) {
            result = 0;
        } else if (ResumeFromHere_803685C0 != 0) {
            result = 0;
        } else {
            result = 1;
        }
        break;
    }

    OSRestoreInterrupts(enabled);
    return result;
}

void fn_8020F504(void (*arg0)(void *, void *)) {
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
void fn_8020F0B8(void *, void (*)(void *, void *));
s32 inner, resume, outer, pause;
void *block;
outer = OSDisableInterrupts();
__DVDClearWaitingQueue();
if (lbl_803685B8 != 0) lbl_803685BC = arg0;
else {
if (executing_80368598 != 0) ((DVDReadyCommand *)executing_80368598)->callback = 0;
inner = OSDisableInterrupts();
pause = OSDisableInterrupts();
PauseFlag_803685A4 = 1;
if (executing_80368598 == 0) PausingFlag_803685A8 = 1;
OSRestoreInterrupts(pause);
while ((block = (void *)__DVDPopWaitingQueue()) != 0) fn_8020F0B8(block, 0);
if (executing_80368598 != 0) fn_8020F0B8(executing_80368598, arg0);
else if (arg0 != 0) arg0(0,0);
resume = OSDisableInterrupts();
PauseFlag_803685A4 = 0;
if (PausingFlag_803685A8 != 0) { PausingFlag_803685A8 = 0; stateReady(); }
OSRestoreInterrupts(resume);
OSRestoreInterrupts(inner);
}
OSRestoreInterrupts(outer);
}

int fn_8020F620(void *arg0) {
    extern u8 lbl_80339FB0[];

    if (arg0 == lbl_80339FB0) {
        return 1;
    }

    return fn_8020C370(arg0);
}

void __DVDClearWaitingQueue(void) {
    struct DVDQueue {
        struct DVDQueue *next;
        struct DVDQueue *prev;
    };
    extern struct DVDQueue WaitingQueue_80339FD8[4];
    struct DVDQueue *ptr;
    u32 i;

    for (i = 0; i < 4; i++) {
        ptr = &WaitingQueue_80339FD8[i];
        ptr->next = ptr;
        ptr->prev = ptr;
    }
}

int __DVDPushWaitingQueue(s32 priority, void *block) {
    struct DVDQueue {
        struct DVDQueue *next;
        struct DVDQueue *prev;
    };
    extern struct DVDQueue WaitingQueue_80339FD8[4];
    extern u32 OSDisableInterrupts(void);
    extern void OSRestoreInterrupts(u32);
    struct DVDQueue *queue;
    struct DVDQueue *entry;
    u32 interrupts;

    entry = (struct DVDQueue *)block;
    interrupts = OSDisableInterrupts();
    queue = &WaitingQueue_80339FD8[priority];
    queue->prev->next = entry;
    entry->prev = queue->prev;
    entry->next = queue;
    queue->prev = entry;
    OSRestoreInterrupts(interrupts);
    return 1;
}

s32 __DVDPopWaitingQueue(void)
{
    struct DVDQueue {
        struct DVDQueue *next;
        struct DVDQueue *prev;
    };
    extern struct DVDQueue WaitingQueue_80339FD8[4];
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    struct DVDQueue *entry;
    s32 i;
    u32 interrupts;

    interrupts = OSDisableInterrupts();
    for (i = 0; i < 4; i++) {
        if (WaitingQueue_80339FD8[i].next != &WaitingQueue_80339FD8[i]) {
            OSRestoreInterrupts(interrupts);
            interrupts = OSDisableInterrupts();
            entry = WaitingQueue_80339FD8[i].next;
            WaitingQueue_80339FD8[i].next = entry->next;
            entry->next->prev = &WaitingQueue_80339FD8[i];
            OSRestoreInterrupts(interrupts);
            entry->next = 0;
            entry->prev = 0;
            return (s32)entry;
        }
    }
    OSRestoreInterrupts(interrupts);
    return 0;
}

s32 __DVDCheckWaitingQueue(void) {
    struct DVDQueue {
        struct DVDQueue *next;
        struct DVDQueue *prev;
    };
    extern struct DVDQueue WaitingQueue_80339FD8[4];
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);

    u32 enabled;
    struct DVDQueue *q;
    s32 i;

    enabled = OSDisableInterrupts();

    for (i = 0; i < 4; i++) {
        q = &WaitingQueue_80339FD8[i];
        if (q->next != q) {
            OSRestoreInterrupts(enabled);
            return 1;
        }
    }

    OSRestoreInterrupts(enabled);
    return 0;
}

s32 fn_8020F7F0(void *arg0) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    void **prev;
    void *next;
    s32 enabled;

    enabled = OSDisableInterrupts();
    prev = *(void ***)((char *)arg0 + 4);
    next = *(void **)arg0;
    if (prev == NULL || next == NULL) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    *prev = next;
    *(void **)((char *)next + 4) = prev;
    OSRestoreInterrupts(enabled);
    return 1;
}

u8 ErrorCode2Num(s32 error)
{
    extern u16 lbl_8029D210[];

    u32 *table;
    u32 i;

    table = (u32 *)lbl_8029D210;

    for (i = 0; i < 20; i++) {
        if ((u32)error == table[i]) {
            return (u8)i;
        }
    }

    if ((u32)error >= 0x100000 && (u32)error <= 0x100008) {
        return 0x11;
    }

    return 0x1D;
}

void __DVDStoreErrorCode(u32 arg0) {
    u8 ErrorCode2Num(s32);
    void *__OSLockSramEx(void);
    void __OSUnlockSramEx(s32);
    u8 var_r31;
    u32 temp_r0;
    u32 var_r31_2;
    u8 temp_r3;

    temp_r0 = arg0 + 0xFEDD0000;
    if (temp_r0 == 0x4567U) {
        var_r31 = 0xFFU;
    } else if (temp_r0 == 0x4568U) {
        var_r31 = 0xFEU;
    } else {
        var_r31_2 = arg0 >> 0x18U;
        temp_r3 = ErrorCode2Num(arg0 & 0xFFFFFF);
        if (var_r31_2 >= 6U) {
            var_r31_2 = 6;
        }
        var_r31 = temp_r3 + (var_r31_2 * 0x1E);
    }
    M2C_FIELD(__OSLockSramEx(), u8 *, 0x24) = var_r31;
    __OSUnlockSramEx(1);
}

s32 fn_8020F9E8(u8 *arg0, u8 *arg1)
{
    s32 Str_NCmp(u8 *, u8 *, u32);
    u8 *b;
    u8 *a;

    b = arg1;
    a = arg0;

    if ((s8)a[0] != 0 && (s8)b[0] != 0) {
        if (Str_NCmp(a, b, 4) != 0) {
            return 0;
        }
    }

    if (!((s8)a[4] != 0 && (s8)b[4] != 0 && Str_NCmp(a + 4, b + 4, 2) == 0)) {
        return 0;
    }

    if (a[6] != 0xFF && b[6] != 0xFF) {
        if (a[6] != b[6]) {
            return 0;
        }
    }

    if (a[7] != 0xFF && b[7] != 0xFF) {
        if (a[7] != b[7]) {
            return 0;
        }
    }

    return 1;
}

void fn_8020FAE0(void) {
    if (lbl_803685E8 != NULL) {
        lbl_803685E8();
    }
}

void cb(s32 arg0, void *arg1) {
    extern u8 *bb2_803685F4;
    extern void *idTmp_803685F8;
    extern s32 lbl_803685F0;
    void DVDReset(void);
    if (arg0 > 0) {
        switch (lbl_803685F0) {
        case 0:
            lbl_803685F0=1;
            fn_8020EBEC(arg1,(u32)bb2_803685F4,32,0x420,(u32)cb);
            break;
        case 1:
            lbl_803685F0=2;
            fn_8020EBEC(arg1,*(u32 *)(bb2_803685F4+0x10),(*(u32 *)(bb2_803685F4+8)+31)&~31,*(u32 *)(bb2_803685F4+4),(u32)cb);
            break;
        }
    } else {
        if (arg0 == -1) return;
        if (arg0 == -4) {
            lbl_803685F0=0;
            DVDReset();
            DVDReadDiskID(arg1,idTmp_803685F8,(void *)cb);
        }
    }
}

void __fstLoad(void) {
void *OSGetArenaHi(void);
void OSSetArenaHi(void *);
void DVDReset(void);
void OSReport(char *, ...);
void *memcpy(void *, const void *, u32);
extern u8 *bb2_803685F4;
extern void *idTmp_803685F8;
extern char lbl_8029D258[];
extern char lbl_80366F80[2], lbl_80366F84[4], lbl_80366F88[3];
static u8 block[48];
u8 idBuffer[64];
register char *format;
u8 *id;
u8 *boot;
format = lbl_8029D258;
OSGetArenaHi();
idTmp_803685F8 = (void *)(((u32)idBuffer + 31) & ~31);
bb2_803685F4 = (u8 *)(((u32)bb2Buf_80339FF8 + 31) & ~31);
DVDReset();
DVDReadDiskID(block,idTmp_803685F8,(void *)cb);
while (DVDGetDriveStatus() != 0) {}
id=(u8 *)0x80000000;
boot=(u8 *)0x80000000;
*(u32 *)(boot+0x38)=*(u32 *)(bb2_803685F4+0x10);
*(u32 *)(boot+0x3C)=*(u32 *)(bb2_803685F4+0xC);
memcpy(id,idTmp_803685F8,32);
OSReport(lbl_80366F80);
OSReport(format,(s8)id[0],(s8)id[1],(s8)id[2],(s8)id[3]);
OSReport(format+0x1C,(s8)id[4],(s8)id[5]);
OSReport(format+0x34,id[6]);
OSReport(format+0x48,id[7]);
OSReport(format+0x5C,boot[8] == 0 ? lbl_80366F84 : lbl_80366F88);
OSReport(lbl_80366F80);
OSSetArenaHi(*(void **)(bb2_803685F4+0x10));
}

#pragma use_lmw_stmw on
void fn_8020FD50(s32 unused, OSContext *arg1) {
    void fn_80211B30(s32, s32);
    u32 fn_802116D4(void);
    u32 fn_8022CB2C(u32, u32, s32);
    u32 fn_8022CB08(u32, u32, s32, s32);
    void fn_8023C518(void);
    void fn_8020AEC4(s32 *);
    extern u8 lbl_8033A068[];
    extern u32 lbl_80368604;
    extern u32 lbl_80368608;
    extern s32 lbl_8036860C;

    struct {
        s16 sp14;
        s16 sp16;
        OSContext ctx;
    } local;
    volatile u16 *r5;
    volatile u16 *rp;
    u16 val0;
    u16 val1;
    s32 regMask;
    s32 didFlush;
    s32 bit;
    u32 lo;
    u32 tmp;
    u32 tmp2;
    u8 *regsBase;
    OSContext *ctxArg;
    u8 *timing;
    u32 t27;

    ctxArg = arg1;
    timing = lbl_8033A068;
    regMask = 0;
    r5 = (volatile u16 *)0xCC002000;
    val0 = *(r5 += 0x18);
    if (val0 & 0x8000) {
        *r5 = (u16)(val0 & ~0x8000);
        regMask |= 1;
    }
    rp = (volatile u16 *)0xCC000000;
    val1 = *(rp += 0x101A);
    if (val1 & 0x8000) {
        *rp = (u16)(val1 & ~0x8000);
        regMask |= 2;
    }
    rp = (volatile u16 *)0xCC000000;
    val1 = *(rp += 0x101C);
    if (val1 & 0x8000) {
        *rp = (u16)(val1 & ~0x8000);
        regMask |= 4;
    }
    rp = (volatile u16 *)0xCC000000;
    val1 = *(rp += 0x101E);
    if (val1 & 0x8000) {
        *rp = (u16)(val1 & ~0x8000);
        regMask |= 8;
    }
    if ((regMask & 4) || (regMask & 8)) {
        OSClearContext(&local.ctx);
        OSSetCurrentContext(&local.ctx);
        if (lbl_8036861C != NULL) {
            fn_80211B30((s32)&local.sp16, (s32)&local.sp14);
            ((void (*)(s16, s16))lbl_8036861C)(local.sp16, local.sp14);
        }
        OSClearContext(&local.ctx);
        OSSetCurrentContext(ctxArg);
        return;
    }
    lbl_80368604 += 1;
    OSClearContext(&local.ctx);
    OSSetCurrentContext(&local.ctx);
    if ((u32)lbl_80368614 != 0) {
        ((void (*)(u32))lbl_80368614)(lbl_80368604);
    }
    if (lbl_80368608 != 0) {
        if ((u32)lbl_80368638 != 1 || fn_802116D4() != 0) {
            regsBase = (u8 *)0xCC002000;
            lo = 0;
            while ((((u32)lbl_80368640 ^ lo) | ((u32)lbl_80368644 ^ lo)) != 0) {
                t27 = (u32)lbl_80368644;
                tmp = fn_8022CB2C((u32)lbl_80368640, t27, 0x20);
                bit = __cntlzw(tmp);
                if (bit >= 0x20) {
                    bit = __cntlzw(t27) + 0x20;
                }
                *(volatile u16 *)(regsBase + (bit << 1)) = *(u16 *)((u8 *)(timing + (bit << 1)) + 0x78);
                tmp = 0;
                tmp2 = 1;
                tmp2 = fn_8022CB08(tmp, tmp2, 0x3F - bit, bit << 1);
                lbl_80368640 = (void *)((u32)lbl_80368640 & ~tmp);
                lbl_80368644 = (void *)((u32)lbl_80368644 & ~tmp2);
            }
            lbl_80368638 = (void *)0;
            didFlush = 1;
            lbl_80368648 = (u16 *)*(u32 *)(timing + 0x144);
            lbl_8036864C = *(void **)(timing + 0x118);
            lbl_80368654 = lbl_80368650;
        } else {
            didFlush = 0;
        }
        if (didFlush != 0) {
            lbl_80368608 = 0;
            fn_8023C518();
        }
    }
    if (lbl_80368618 != NULL) {
        OSClearContext(&local.ctx);
        ((void (*)(u32))lbl_80368618)(lbl_80368604);
    }
    fn_8020AEC4(&lbl_8036860C);
    OSClearContext(&local.ctx);
    OSSetCurrentContext(ctxArg);
}
#pragma use_lmw_stmw reset

s32 fn_8020FFC4(s32 arg0) {
    extern s32 lbl_80368614;
    s32 temp_r31;

    temp_r31 = lbl_80368614;
    OSDisableInterrupts();
    lbl_80368614 = arg0;
    OSRestoreInterrupts();
    return temp_r31;
}

void* fn_80210008(void* arg0) {
    void* temp_r31;

    temp_r31 = lbl_80368618;
    OSDisableInterrupts();
    lbl_80368618 = arg0;
    OSRestoreInterrupts();
    return temp_r31;
}

VITiming *fn_8021004C(u32 arg0) {
extern u8 lbl_8029D2C8[];
extern VITiming *lbl_8036865C;
u8 *data = lbl_8029D2C8;
switch(arg0) {
case 0: return (VITiming *)(data+0x44);
case 1: return (VITiming *)(data+0x6A);
case 4: return (VITiming *)(data+0x90);
case 5: return (VITiming *)(data+0xB6);
case 20: return (VITiming *)(data+0x44);
case 21: return (VITiming *)(data+0x6A);
case 8: return (VITiming *)(data+0xDC);
case 9: return (VITiming *)(data+0x102);
case 2: return (VITiming *)(data+0x128);
case 3: return (VITiming *)(data+0x14E);
case 16: return (VITiming *)(data+0x90);
case 17: return (VITiming *)(data+0xB6);
case 24: return (VITiming *)(data+0x174);
case 25: return (VITiming *)(data+0x19A);
case 30: return lbl_8036865C;
default: return 0;
}
}

VITiming *fn_8021004C(u32 arg0);

void fn_802100F4(u32 arg0) {
    VITiming *fn_8021004C(u32);
    volatile u16 *regs;
    VITiming *tm;
    u32 tv;
    u32 mode;
    u32 val;
    volatile u32 grit;
    u32 pad0;
    u32 pad1;
    u32 pad2;
    u8 lo;
    u8 hi;
    u16 tmp;
    u16 tmp2;

    mode = arg0 >> 2;
    tv = arg0 & 3;
    *(u32 *)0x800000CC = mode;
    tm = fn_8021004C(arg0);
    regs = (volatile u16 *)(0xCC000000 + 0x2000);
    *++regs = 2;
    grit = 0;
    if (grit < 1000) {
        while (grit < 1000) {
            grit += 8;
        }
    }
    *regs = 0;
    tmp = tm->unk1A;
    *(volatile u16 *)(0xCC000000 + 0x2006) = tmp;
    hi = tm->unk1D;
    lo = tm->unk1E;
    *(volatile u16 *)(0xCC000000 + 0x2004) = lo | (hi << 8);
    hi = tm->unk1F;
    lo = tm->unk1C;
    *(volatile u16 *)(0xCC000000 + 0x200A) = lo | (hi << 7);
    tmp = tm->unk20;
    *(volatile u16 *)(0xCC000000 + 0x2008) = (tmp & 0x7FFF) << 1;
    tmp = tm->unk2;
    lo = tm->unk0;
    tmp = (tmp * 2) - 2;
    *(volatile u16 *)(0xCC000000 + 0x2000) = lo;
    *(volatile u16 *)(0xCC000000 + 0x200E) = tm->unk4 + tmp;
    *(volatile u16 *)(0xCC000000 + 0x200C) = tm->unk8 + 2;
    tmp = tm->unk2;
    tmp = (tmp * 2) - 2;
    *(volatile u16 *)(0xCC000000 + 0x2012) = tm->unk6 + tmp;
    *(volatile u16 *)(0xCC000000 + 0x2010) = tm->unkA + 2;
    *(volatile u16 *)(0xCC000000 + 0x2016) = tm->unkC | (tm->unk10 << 5);
    *(volatile u16 *)(0xCC000000 + 0x2014) = tm->unkE | (tm->unk14 << 5);
    *(volatile u16 *)(0xCC000000 + 0x201A) = tm->unkD | (tm->unk12 << 5);
    *(volatile u16 *)(0xCC000000 + 0x2018) = tm->unkF | (tm->unk16 << 5);
    *(volatile u16 *)(0xCC000000 + 0x2048) = 0x2828;
    *(volatile u16 *)(0xCC000000 + 0x2036) = 1;
    *(volatile u16 *)(0xCC000000 + 0x2034) = 0x1001;
    tmp = tm->unk18;
    tmp2 = tm->unk1A;
    *(volatile u16 *)(0xCC000000 + 0x2032) = tmp2 + 1;
    *(volatile u16 *)(0xCC000000 + 0x2030) = ((s16)tmp / 2 + 1) | 0x1000;
    if ((s32)mode < 4) {
        if ((s32)mode >= 1) {
            val = mode;
        } else {
            val = 0;
        }
    } else {
        val = 0;
    }
    if (tv <= 1) {
        *regs = (u16)((((tv & 1) << 2) | 1) | (val << 8));
        *(volatile u16 *)(0xCC000000 + 0x206C) = 0;
    } else {
        *regs = (u16)((val << 8) | 5);
        *(volatile u16 *)(0xCC000000 + 0x206C) = 1;
    }
}

#pragma optimization_level 3
void VIInit(void){
extern u8 lbl_8029D2C8[],lbl_8033A068[];extern s32 lbl_80368600,lbl_80368604,lbl_80368608;extern const char *lbl_80366F90;
extern s16 lbl_80368626;extern u32 CurrTvMode_8036864C;extern u8 lbl_8036860C[8];
void OSRegisterVersion(const char*);void *__OSLockSram(void);void __OSUnlockSram(s32);
void OSInitThreadQueue(void*);void __OSSetInterruptHandler(s32,void(*)(void));void __OSUnmaskInterrupts(u32);void fn_8020FD50(void);
u8 *data=lbl_8029D2C8,*v=lbl_8033A068;volatile u16 *regs=(volatile u16*)0xcc002000;volatile u16 *controlp;
u16 *tim;u32 *modep,*progp;u16 control;u32 tv,mode; s16 maxx,x,zero; s32 divisor,parity,y,limit,high,low,tmp;
if(!lbl_80368600){
OSRegisterVersion(lbl_80366F90);lbl_80368600=1;lbl_80368620=(void*)1;
controlp=(volatile u16*)0xcc002000;if(!(*++controlp&1))fn_802100F4(0);
lbl_80368604=0;lbl_80368634=0;lbl_80368630=0;lbl_80368644=0;lbl_80368640=0;lbl_80368628=0;lbl_80368638=0;lbl_80368608=0;
regs[39]=*(u16*)(data+0x1c0)|((*(u16*)(data+0x1c2)<<10)&0xfc00);
regs[38]=((s32)*(u16*)(data+0x1c2)>>6)|(*(u16*)(data+0x1c4)<<4);
regs[41]=*(u16*)(data+0x1c6)|((*(u16*)(data+0x1c8)<<10)&0xfc00);
regs[40]=((s32)*(u16*)(data+0x1c8)>>6)|(*(u16*)(data+0x1ca)<<4);
regs[43]=*(u16*)(data+0x1cc)|((*(u16*)(data+0x1ce)<<10)&0xfc00);
regs[42]=((s32)*(u16*)(data+0x1ce)>>6)|(*(u16*)(data+0x1d0)<<4);
regs[45]=*(u16*)(data+0x1d2)|(*(u16*)(data+0x1d4)<<8);
regs[44]=*(u16*)(data+0x1d6)|(*(u16*)(data+0x1d8)<<8);
regs[47]=*(u16*)(data+0x1da)|(*(u16*)(data+0x1dc)<<8);
regs[46]=*(u16*)(data+0x1de)|(*(u16*)(data+0x1e0)<<8);
regs[49]=*(u16*)(data+0x1e2)|(*(u16*)(data+0x1e4)<<8);
regs[48]=*(u16*)(data+0x1e6)|(*(u16*)(data+0x1e8)<<8);
regs[51]=*(u16*)(data+0x1ea)|(*(u16*)(data+0x1ec)<<8);
regs[50]=*(u16*)(data+0x1ee)|(*(u16*)(data+0x1f0)<<8);

regs[0x70/2]=640;
*(s16*)&lbl_80368624=(s8)((u8*)__OSLockSram())[0x10];lbl_80368626=0;__OSUnlockSram(0);
control=*controlp;progp=(u32*)(v+0x114);modep=(u32*)(v+0x118);*progp=(control>>2)&1;*modep=(control>>8)&3;
if(*(u32*)0x800000cc==1&&*modep==0)*modep=5;
tv=*modep;if(tv==3)tv=0;
*(VITiming**)(v+0x144)=fn_8021004C(tv*4+*progp);
*(u16*)(v+0x2)=control;lbl_80368648=*(u16**)(v+0x144);CurrTvMode_8036864C=*modep;
tim=lbl_80368648;*(u16*)(v+0xf4)=640;*(u16*)(v+0xf6)=(tim[1]*2)&0xfffe;
*(u16*)(v+0xf0)=(720-*(u16*)(v+0xf4))/2;*(u16*)(v+0xf2)=0;
maxx=720-*(u16*)(v+0xf4);x=*(s16*)(v+0xf0)+*(s16*)&lbl_80368624;
if(x>maxx){}else{zero=0;if(x>=0)zero=x;maxx=zero;}
*(u16*)(v+0xf8)=maxx;
if(*(u32*)(v+0x110)==0)divisor=2;else divisor=1;
parity=*(u16*)(v+0xf2)&1;y=(s16)*(u16*)(v+0xf2)+lbl_80368626;if(y<=parity)y=parity;*(u16*)(v+0xfa)=y;
limit=(s16)tim[1]*2-parity;
tmp=*(s16*)(v+0xf2)+((s16)*(u16*)(v+0xf6)+lbl_80368626);if(tmp-limit>0)high=tmp-limit;else high=0;
tmp=*(s16*)(v+0xf2)+lbl_80368626;if(tmp-parity<0)low=tmp-parity;else low=0;
*(u16*)(v+0xfc)=*(u16*)(v+0xf6)+low-high;
tmp=*(s16*)(v+0xf2)+lbl_80368626;if(tmp-parity<0)low=tmp-parity;else low=0;
*(u16*)(v+0xfe)=*(u16*)(v+0x108)-low/divisor;
tmp=*(s16*)(v+0xf2)+((s16)*(u16*)(v+0xf6)+lbl_80368626);if(tmp-limit>0)high=tmp-limit;else high=0;
tmp=*(s16*)(v+0xf2)+lbl_80368626;if(tmp-parity<0)low=tmp-parity;else low=0;
*(u16*)(v+0x100)=*(u16*)(v+0x10c)+low/divisor-high/divisor;
*(u16*)(v+0x102)=640;*(u16*)(v+0x104)=(tim[1]*2)&0xfffe;
*(u16*)(v+0x106)=0;*(u16*)(v+0x108)=0;*(u16*)(v+0x10a)=640;*(u16*)(v+0x10c)=(tim[1]*2)&0xfffe;
*(u32*)(v+0x110)=0;v[0x11c]=v[0x11d]=v[0x11e]=40;v[0x12c]=0;*(u32*)(v+0x130)=1;*(u32*)(v+0x134)=0;
OSInitThreadQueue(lbl_8036860C);regs[0x30/2]=regs[0x30/2]&0x7fff;regs[0x34/2]=regs[0x34/2]&0x7fff;
lbl_80368614=0;lbl_80368618=0;__OSSetInterruptHandler(24,fn_8020FD50);__OSUnmaskInterrupts(0x80);
}
}
#pragma peephole on
void VIWaitForRetrace(void) {
extern u32 lbl_80368604;
extern u8 lbl_8036860C;
BOOL OSDisableInterrupts(void);
void OSRestoreInterrupts(BOOL);
void OSSleepThread(void *);
BOOL enabled;
u32 previous;
enabled=OSDisableInterrupts();
previous=lbl_80368604;
do { OSSleepThread(&lbl_8036860C); } while(previous==lbl_80368604);
OSRestoreInterrupts(enabled);
}
#pragma peephole reset
void fn_80210AD0(u16 arg0, u16 arg1, u8 arg2, u16 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 nonInterlace) {
    extern u8 lbl_8033A068[];
    s32 ni;
    u8 *v;
    u16 equOfs;
    u16 fldOfs;
    s32 h0000;
    s32 v0000;
    s32 h0100;
    s32 v0100;
    s32 tmp;
    u16 half;

    ni = nonInterlace;
    v = lbl_8033A068;
    if (*(u16 *)(v + 0x6C) & 1) {
        equOfs = 1;
        fldOfs = 2;
    } else {
        equOfs = 2;
        fldOfs = 1;
    }
    if ((arg0 % 2) == 0) {
        tmp = fldOfs * arg0;
        h0000 = arg4 + tmp;
        v0000 = arg6 + (fldOfs * ((equOfs * arg3 - arg1) - arg0));
        h0100 = arg5 + tmp;
        v0100 = arg7 + (fldOfs * ((equOfs * arg3 - arg1) - arg0));
    } else {
        tmp = fldOfs * arg0;
        h0000 = arg5 + tmp;
        v0000 = arg7 + (fldOfs * ((equOfs * arg3 - arg1) - arg0));
        h0100 = arg4 + tmp;
        v0100 = arg6 + (fldOfs * ((equOfs * arg3 - arg1) - arg0));
    }
    half = (u16)(arg1 / equOfs);
    if (ni != 0) {
        tmp = (half * 2) - 2;
        h0000 += tmp;
        h0100 += tmp;
        half = 0;
        v0000 += 2;
        v0100 += 2;
    }
    *(u16 *)(v + 0) = (u16)(arg2 | ((half * 0x10) & 0xFFFF0));
    *(u64 *)&lbl_80368630 |= 0x8000000000000000ULL;
    *(u16 *)(v + 0xE) = (u16)h0000;
    *(u64 *)&lbl_80368630 |= 0x0100000000000000ULL;
    *(u16 *)(v + 0xC) = (u16)v0000;
    *(u64 *)&lbl_80368630 |= 0x0200000000000000ULL;
    *(u16 *)(v + 0x12) = (u16)h0100;
    *(u64 *)&lbl_80368630 |= 0x0040000000000000ULL;
    *(u16 *)(v + 0x10) = (u16)v0100;
    *(u64 *)&lbl_80368630 |= 0x0080000000000000ULL;
}

#pragma peephole on
void VIConfigure(void *arg0) {
    BOOL OSDisableInterrupts(void);
    void OSRestoreInterrupts(BOOL);
    void OSReport(char *, ...);
    void OSPanic(void *, s32, char *, ...);
    VITiming *fn_8021004C(u32);
    void fn_802107FC(void *, void *, void *, void *, void *);
    void fn_80210AD0(u16, u16, u8, u16, u16, u16, u16, u16);
    extern u8 lbl_8029D2C8[];
    extern u8 lbl_8033A068[];
    extern char lbl_80366F94[];
    extern u32 lbl_80368658;
    extern u32 lbl_80368660;
    extern s16 lbl_80368626;

    void *self;
    u8 *data;
    u8 *v;
    BOOL irq;
    u32 *progp;
    u32 tv;
    u32 mode;
    u32 tmp;
    VITiming *tm;
    u16 *pF2, *pF4, *p102, *p10A, *p10C, *p106, *p108, *pF6, *pFA, *pFC;
    u32 *p110, *p134, *p118;
    s16 maxx, x;
    s32 divisor, parity, y, limit, high, low, tmpi;
    u16 val, r2, r6c;
    u32 r0;

    self = arg0;
    data = lbl_8029D2C8;
    v = lbl_8033A068;
    irq = OSDisableInterrupts();
    progp = (u32 *)(v + 0x114);
    tmp = *(u32 *)self & 3;
    if (*progp != tmp) {
        lbl_80368628 = (void *)1;
        *progp = tmp;
    }
    tv = *(u32 *)0x800000CC;
    mode = *(u32 *)self >> 2;
    if (mode == 4 && lbl_80368660 == 0) {
        lbl_80368660 = 1;
        OSReport((char *)(data + 0x270));
        OSReport((char *)(data + 0x29c));
        OSReport((char *)(data + 0x2c8));
        OSReport((char *)(data + 0x2f4));
        OSReport((char *)(data + 0x320));
        OSReport((char *)(data + 0x34c));
        OSReport((char *)(data + 0x270));
    }
    if (tv == 2) {
        goto path_02;
    } else if (tv >= 2) {
        if (tv == 5) {
            goto path_157;
        } else if (tv < 5) {
            goto path_err;
        } else if (tv >= 8) {
            goto path_err;
        } else {
            goto path_157;
        }
    } else if (tv == 0) {
        goto path_02;
    } else if (tv >= 0) {
        goto path_157;
    } else {
        goto path_err;
    }
path_02:
    if (mode == 0 || mode == 2 || (mode - 6) <= 1) {
        goto path_ok;
    }
    goto path_err;
path_157:
    if (mode == 1 || mode == 5) {
        goto path_ok;
    }
path_err:
    OSPanic(lbl_80366F94, 0x7bb, (char *)(data + 0x378), tv, mode);
path_ok:
    p118 = (u32 *)(v + 0x118);
    if (mode == 0 || mode == 2) {
        *p118 = tv;
    } else {
        *p118 = mode;
    }
    *(u16 *)(v + 0xf0) = *(u16 *)((u8 *)self + 0xa);
    if (*progp == 1) {
        val = (u16)((*(u16 *)((u8 *)self + 0xc) * 2) & 0xfffe);
    } else {
        val = *(u16 *)((u8 *)self + 0xc);
    }
    *(u16 *)(v + 0xf2) = val;
    pF2 = (u16 *)(v + 0xf2);
    pF4 = (u16 *)(v + 0xf4);
    p102 = (u16 *)(v + 0x102);
    p110 = (u32 *)(v + 0x110);
    p10A = (u16 *)(v + 0x10a);
    p10C = (u16 *)(v + 0x10c);
    p106 = (u16 *)(v + 0x106);
    p108 = (u16 *)(v + 0x108);
    *pF4 = *(u16 *)((u8 *)self + 0xe);
    *p102 = *(u16 *)((u8 *)self + 4);
    *(u16 *)(v + 0x104) = *(u16 *)((u8 *)self + 8);
    *p110 = *(u32 *)((u8 *)self + 0x14);
    *p10A = *p102;
    *p10C = *(u16 *)(v + 0x104);
    *p106 = 0;
    *p108 = 0;
    if (*progp == 2) {
        val = *p10C;
    } else if (*progp == 3) {
        val = *p10C;
    } else if (*p110 == 0) {
        val = (u16)((*p10C * 2) & 0xfffe);
    } else {
        val = *p10C;
    }
    pF6 = (u16 *)(v + 0xf6);
    *pF6 = val;
    p134 = (u32 *)(v + 0x134);
    if (*progp == 3) {
        *p134 = 1;
    } else {
        *p134 = 0;
    }
    tm = fn_8021004C((*p118 << 2) + *progp);
    *(VITiming **)(v + 0x144) = tm;
    maxx = (s16)(0x2d0 - *pF4);
    x = (s16)*(u16 *)(v + 0xf0) + *(s16 *)&lbl_80368624;
    if (x > maxx) {
    } else {
        if (x < 0) {
            x = 0;
        }
        maxx = x;
    }
    *(u16 *)(v + 0xf8) = maxx;
    if (*p110 == 0) {
        divisor = 2;
    } else {
        divisor = 1;
    }
    parity = *pF2 & 1;
    y = (s16)*pF2 + lbl_80368626;
    if (y > parity) {
    } else {
        y = (s16)parity;
    }
    pFA = (u16 *)(v + 0xfa);
    *pFA = y;
    limit = ((s16)tm->unk2 * 2) - parity;
    tmpi = (s16)*pF2 + ((s16)*pF6 + lbl_80368626);
    if (tmpi - limit > 0) {
        high = tmpi - limit;
    } else {
        high = 0;
    }
    tmpi = (s16)*pF2 + lbl_80368626;
    if (tmpi - parity < 0) {
        low = tmpi - parity;
    } else {
        low = 0;
    }
    pFC = (u16 *)(v + 0xfc);
    *pFC = (u16)(*pF6 + low - high);
    tmpi = (s16)*pF2 + lbl_80368626;
    if (tmpi - parity < 0) {
        low = tmpi - parity;
    } else {
        low = 0;
    }
    *(u16 *)(v + 0xfe) = (u16)(*p108 - low / divisor);
    tmpi = (s16)*pF2 + ((s16)*pF6 + lbl_80368626);
    if (tmpi - limit > 0) {
        high = tmpi - limit;
    } else {
        high = 0;
    }
    tmpi = (s16)*pF2 + lbl_80368626;
    if (tmpi - parity < 0) {
        low = tmpi - parity;
    } else {
        low = 0;
    }
    *(u16 *)(v + 0x100) = (u16)(*p10C + low / divisor - high / divisor);
    if (lbl_80368620 == 0) {
        *p118 = 3;
    }
    if ((tm->unk18 % 2) != 0) {
        val = tm->unk1A;
    } else {
        val = 0;
    }
    *(u16 *)(v + 0x32) = (u16)(val + 1);
    lbl_80368634 = lbl_80368634;
    lbl_80368630 = (void *)((u32)lbl_80368630 | 0x40);
    *(u16 *)(v + 0x30) = (u16)(((tm->unk18 / 2) + 1) | 0x1000);
    lbl_80368634 = lbl_80368634;
    lbl_80368630 = (void *)((u32)lbl_80368630 | 0x80);
    r2 = *(u16 *)(v + 2);
    r6c = *(u16 *)(v + 0x6c);
    if (*progp == 2 || *progp == 3) {
        r2 = (u16)((r2 & ~4) | 4);
        r6c = (u16)((r6c & ~1) | 1);
    } else {
        r2 = (u16)((r2 & ~4) | ((*progp << 2) & 4));
        r6c = (u16)(r6c & ~1);
    }
    r2 = (u16)((r2 & ~8) | (*p134 << 3));
    if (*p118 == 1 || (*p118 - 2) <= 1) {
        r2 = (u16)((r2 & 0xFCFF) | (*p118 << 8));
    } else {
        r2 = (u16)(r2 & 0xFCFF);
    }
    *(u16 *)(v + 2) = r2;
    *(u16 *)(v + 0x6c) = r6c;
    lbl_80368634 = lbl_80368634;
    lbl_80368630 = (void *)((u32)lbl_80368630 | 0x40000000);
    lbl_80368634 = (void *)((u32)lbl_80368634 | 0x200);
    lbl_80368630 = lbl_80368630;
    if (*p134 != 0) {
        val = (u16)(*p10A * 2);
    } else {
        val = *p10A;
    }
    if (val < *pF4) {
        *(u16 *)(v + 0x4a) = (u16)(((*pF4 + ((val << 8) - 1)) / *pF4) | 0x1000);
        lbl_80368634 = (void *)((u32)lbl_80368634 | 0x04000000);
        lbl_80368630 = lbl_80368630;
        *(u16 *)(v + 0x70) = val;
        lbl_80368634 = (void *)((u32)lbl_80368634 | 0x80);
        lbl_80368630 = lbl_80368630;
    } else {
        *(u16 *)(v + 0x4a) = 0x100;
        lbl_80368634 = (void *)((u32)lbl_80368634 | 0x04000000);
        lbl_80368630 = lbl_80368630;
    }
    *(u16 *)(v + 6) = tm->unk1A;
    lbl_80368634 = lbl_80368634;
    lbl_80368630 = (void *)((u32)lbl_80368630 | 0x10000000);
    *(u16 *)(v + 4) = (u16)(tm->unk1E | (tm->unk1D << 8));
    lbl_80368634 = lbl_80368634;
    lbl_80368630 = (void *)((u32)lbl_80368630 | 0x20000000);
    r0 = (tm->unk1F + *(u16 *)(v + 0xf8)) - 0x28;
    *(u16 *)(v + 0xa) = (u16)(tm->unk1C | ((r0 << 7) & 0xFF80));
    lbl_80368634 = lbl_80368634;
    lbl_80368630 = (void *)((u32)lbl_80368630 | 0x04000000);
    *(u16 *)(v + 8) = (u16)((r0 >> 9) | (((tm->unk20 + *(u16 *)(v + 0xf8) + 0x28) - (0x2d0 - *pF4)) * 2));
    lbl_80368634 = lbl_80368634;
    lbl_80368630 = (void *)((u32)lbl_80368630 | 0x08000000);
    *(u16 *)(v + 0x16) = (u16)(tm->unkC | (tm->unk10 << 5));
    lbl_80368634 = lbl_80368634;
    lbl_80368630 = (void *)((u32)lbl_80368630 | 0x100000);
    *(u16 *)(v + 0x14) = (u16)(tm->unkE | (tm->unk14 << 5));
    lbl_80368634 = lbl_80368634;
    lbl_80368630 = (void *)((u32)lbl_80368630 | 0x200000);
    *(u16 *)(v + 0x1a) = (u16)(tm->unkD | (tm->unk12 << 5));
    lbl_80368634 = lbl_80368634;
    lbl_80368630 = (void *)((u32)lbl_80368630 | 0x40000);
    *(u16 *)(v + 0x18) = (u16)(tm->unkF | (tm->unk16 << 5));
    lbl_80368634 = lbl_80368634;
    lbl_80368630 = (void *)((u32)lbl_80368630 | 0x80000);
    v[0x11c] = (u8)((*p102 + 0xf) / 16);
    if (*p110 == 0) {
        v[0x11d] = v[0x11c];
    } else {
        v[0x11d] = (u8)((v[0x11c] << 1) & 0xfe);
    }
    v[0x12c] = (u8)(*p106 % 16);
    v[0x11e] = (u8)((v[0x12c] + (*p10A + 0xf)) / 16);
    *(u16 *)(v + 0x48) = (u16)(v[0x11d] | (v[0x11e] << 8));
    lbl_80368634 = (void *)((u32)lbl_80368634 | 0x08000000);
    lbl_80368630 = lbl_80368630;
    if (lbl_80368658 != 0) {
        fn_802107FC(v + 0xf0, v + 0x124, v + 0x128, v + 0x13c, v + 0x140);
    }
    {
        u32 sp8 = *(u32 *)(v + 0x130);
        (void)sp8;
        fn_80210AD0(*pFA, *pFC, tm->unk0, tm->unk2, tm->unk4, tm->unk6, tm->unk8, tm->unkA);
    }
    OSRestoreInterrupts(irq);
}

void VIFlush(void) {
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
extern u8 lbl_8033A068[];
extern s32 lbl_80368608;
u8 *base = lbl_8033A068;
s32 interrupts;
u64 bits;
s32 bit;
interrupts = OSDisableInterrupts();
lbl_80368638 = (void *)((u32)lbl_80368638 | (u32)lbl_80368628);
lbl_80368628 = 0;
*(u64 *)&lbl_80368640 |= *(u64 *)&lbl_80368630;
while (*(u64 *)&lbl_80368630 != 0) {
bits = *(u64 *)&lbl_80368630;
bit = __cntlzw((u32)(bits >> 32));
if (bit >= 32) bit = __cntlzw((u32)bits) + 32;
*(u16 *)(base + 0x78 + bit*2) = *(u16 *)(base + bit*2);
*(u64 *)&lbl_80368630 &= ~((u64)1 << (63-bit));
}
lbl_80368608 = 1;
lbl_80368650 = *(void **)(base + 0x120);
OSRestoreInterrupts(interrupts);
}

void VISetNextFrameBuffer(void *frameBuffer)
{
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    void fn_802107FC(void *, void *, void *, void *, void *);
    extern u8 lbl_8033A068[];
    extern u32 lbl_80368658;
    u32 enabled;
    u8 *base = lbl_8033A068;
    enabled = OSDisableInterrupts();
    *(void **)(base + 0x120) = frameBuffer;
    lbl_80368658 = 1;
    fn_802107FC(base + 0xF0, base + 0x124, base + 0x128, base + 0x13C, base + 0x140);
    OSRestoreInterrupts(enabled);
}

void fn_80211614(s32 arg0)
{
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    void fn_80210AD0(u16, u16, u8, u16, u16, u16, u16, u16, s32);
    extern u8 lbl_8033A068[];
    u32 enabled;
    u8 *base = lbl_8033A068;
    u8 *timing;
    enabled = OSDisableInterrupts();
    *(s32 *)(base + 0x130) = arg0;
    timing = *(u8 **)(base + 0x144);
    fn_80210AD0(*(u16 *)(base + 0xFA), *(u16 *)(base + 0xF6),
        timing[0], *(u16 *)(timing + 2), *(u16 *)(timing + 4),
        *(u16 *)(timing + 6), *(u16 *)(timing + 8), *(u16 *)(timing + 10),
        *(s32 *)(base + 0x130));
    OSRestoreInterrupts(enabled);
}

#pragma use_lmw_stmw reset

#pragma peephole on
s32 fn_80211690(void) {
    extern s32 lbl_80368604;
    return lbl_80368604;
}

void fn_80211698(s32 *arg0, u32 *arg1) {
    u32 new_var3;
    volatile u16 *base;
    volatile u16 *bump = (volatile u16 *)0xCC002000;
    u32 previous;
    u32 vertical;
    u32 horizontal;
    u32 new_var;
    u32 new_var2;

    if (vertical) {}
    vertical = (*(bump += 0x16)) & 0x7FF;
    base = (volatile u16 *)0xCC002000;
    do {
        new_var3 = base[0x17];
        previous = vertical;
        horizontal = new_var3;
        vertical = (*bump) & 0x7FF;
        horizontal &= 0x7FF;
    } while (previous != vertical);
    new_var = horizontal;
    new_var2 = vertical;
    *arg0 = new_var;
    *arg1 = new_var2;
}

s32 fn_802116D4(void) {
volatile u16 *base;
u32 second;
u32 first;
volatile u16 *bump;
u32 third;
VITiming *info;
bump=(volatile u16 *)0xCC002000;
second=(*(bump += 0x16))&0x7ff;
base=(volatile u16 *)0xCC002000;
do { first=second; third=base[0x17]&0x7ff; second=(*bump)&0x7ff; } while(first!=second);
info=(VITiming *)lbl_80368648;
if (((second-1)*2+(third-1)/info->unk1A)<info->unk18) return 1;
return 0;
}

s32 fn_8021173C(void) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    extern u8 lbl_8033A158[];
    s32 field;
    s32 enabled;
    u32 vertical;
    s32 horizontal;
    void (*getPosition)(s32 *, u32 *) = fn_80211698;
    enabled = OSDisableInterrupts();
    getPosition(&horizontal, &vertical);
    {
        u32 halfLine = (vertical - 1) * 2 + (u32)(horizontal - 1) / lbl_80368648[13];
        field = halfLine < lbl_80368648[12] ? 1 : 0;
    }
    OSRestoreInterrupts(enabled);
    return field ^ 1 ^ (*(u16 *)(lbl_8033A158 + 0xA) & 1);
}

u32 fn_802117D8(void) {
    u32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(u32);
    u32 pad[4];
    volatile u16 *base;
    u32 vertical;
    u32 previous;
    volatile u16 *bump;
    u32 horizontal;
    u16 *timing;
    u32 irq;
    u32 line;

    timing = lbl_80368648;
    irq = OSDisableInterrupts();
    bump = (volatile u16 *)0xCC002000;
    vertical = (*(bump += 0x16)) & 0x7FF;
    base = (volatile u16 *)0xCC002000;
    do {
        previous = vertical;
        horizontal = base[0x17] & 0x7FF;
        vertical = (*bump) & 0x7FF;
    } while (previous != vertical);
    line = ((vertical - 1) << 1) + (horizontal - 1) / lbl_80368648[13];
    OSRestoreInterrupts(irq);
    if (line >= timing[12]) {
        line -= timing[12];
    }
    return line >> 1;
}

u32 VIGetTvFormat(void) {
extern u32 CurrTvMode_8036864C;
extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
u32 format;
s32 enabled;
enabled=OSDisableInterrupts();
switch(CurrTvMode_8036864C) {
case 0: case 3: case 6: case 7: format=0; break;
case 1: case 4: format=1; break;
case 2: case 5: format=CurrTvMode_8036864C; break;
}
OSRestoreInterrupts(enabled);
return format;
}

s32 fn_802118D8(void) {
    s32 OSDisableInterrupts(void);
    void OSRestoreInterrupts(s32);
    s32 enabled;
    s32 temp_r31;

    enabled = OSDisableInterrupts();
    temp_r31 = *(u16 *)0xCC00206E & 3;
    OSRestoreInterrupts(enabled);
    return temp_r31 & 1;
}

void fn_80211914(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern u16 *lbl_80368648;
    extern u8 lbl_8033A158[];
    s32 temp_r7;
    u16 temp_r8;
    u32 temp_r10;
    u32 mode;
    u32 var_r0;
    u16 *r9;

    r9 = lbl_80368648;
    var_r0 = ((u32)(arg1 - 1) * 2) + ((u32)(arg0 - 1) / (u32)*(u16 *)((u8 *)r9 + 0x1a));
    mode = *(u32 *)(lbl_8033A158 + 0x24);

    if (mode == 0) {
        temp_r10 = *(u16 *)((u8 *)r9 + 0x18);
        if (var_r0 < temp_r10) {
            temp_r8 = *(u16 *)((u8 *)r9 + 4);
            temp_r7 = *(u8 *)r9 * 3;
            if (var_r0 < (u32)temp_r8 + temp_r7) {
                *(s16 *)arg3 = -1;
            } else if (var_r0 >= temp_r10 - *(u16 *)((u8 *)r9 + 8)) {
                *(s16 *)arg3 = -1;
            } else {
                *(s16 *)arg3 = (var_r0 - temp_r7 - temp_r8) & ~1;
            }
        } else {
            var_r0 = var_r0 - temp_r10;
            temp_r8 = *(u16 *)((u8 *)r9 + 6);
            temp_r7 = *(u8 *)r9 * 3;
            if (var_r0 < (u32)temp_r8 + temp_r7) {
                *(s16 *)arg3 = -1;
            } else if (var_r0 >= temp_r10 - *(u16 *)((u8 *)r9 + 0xa)) {
                *(s16 *)arg3 = -1;
            } else {
                *(s16 *)arg3 = ((var_r0 - temp_r7 - temp_r8) & ~1) + 1;
            }
        }
    } else if (mode == 1) {
        temp_r10 = *(u16 *)((u8 *)r9 + 0x18);
        if (var_r0 >= temp_r10) {
            var_r0 = var_r0 - temp_r10;
        }
        temp_r8 = *(u16 *)((u8 *)r9 + 4);
        temp_r7 = *(u8 *)r9 * 3;
        if (var_r0 < (u32)temp_r8 + temp_r7) {
            *(s16 *)arg3 = -1;
        } else if (var_r0 >= temp_r10 - *(u16 *)((u8 *)r9 + 8)) {
            *(s16 *)arg3 = -1;
        } else {
            *(s16 *)arg3 = (var_r0 - temp_r7 - temp_r8) & ~1;
        }
    } else if (mode == 2) {
        temp_r10 = *(u16 *)((u8 *)r9 + 0x18);
        if (var_r0 < temp_r10) {
            temp_r8 = *(u16 *)((u8 *)r9 + 4);
            temp_r7 = *(u8 *)r9 * 3;
            if (var_r0 < (u32)temp_r8 + temp_r7) {
                *(s16 *)arg3 = -1;
            } else if (var_r0 >= temp_r10 - *(u16 *)((u8 *)r9 + 8)) {
                *(s16 *)arg3 = -1;
            } else {
                *(s16 *)arg3 = var_r0 - temp_r7 - temp_r8;
            }
        } else {
            var_r0 = var_r0 - temp_r10;
            temp_r8 = *(u16 *)((u8 *)r9 + 6);
            temp_r7 = *(u8 *)r9 * 3;
            if (var_r0 < (u32)temp_r8 + temp_r7) {
                *(s16 *)arg3 = -1;
            } else if (var_r0 >= temp_r10 - *(u16 *)((u8 *)r9 + 0xa)) {
                *(s16 *)arg3 = -1;
            } else {
                *(s16 *)arg3 = (var_r0 - temp_r7 - temp_r8) & ~1;
            }
        }
    }
    *(s16 *)arg2 = arg0 - 1;
}

void fn_80211B30(s32 arg0, s32 arg1) {
    void fn_80211914(s32, s32, s32, s32);
    u32 new_var3;
    volatile u16 *base;
    u32 vertical;
    volatile u16 *bump = (volatile u16 *)0xCC002000;
    u32 previous;
    u32 horizontal;
    u32 new_var;
    u32 new_var2;

    if (vertical) {}
    vertical = (*(bump += 0x16)) & 0x7FF;
    base = (volatile u16 *)0xCC002000;
    do {
        new_var3 = base[0x17];
        previous = vertical;
        horizontal = new_var3;
        vertical = (*bump) & 0x7FF;
        horizontal &= 0x7FF;
    } while (previous != vertical);
    new_var = horizontal;
    new_var2 = vertical;
    fn_80211914(new_var, new_var2, arg0, arg1);
}

void fn_80211B90(s8 *arg0, s8 *arg1, s8 arg2, s8 arg3, s8 arg4) {
    s32 sa;
    s32 a;
    s32 b;
    s32 sb;
    s32 t9;
    s32 t7;
    s32 t;

    sa = *arg0;
    b = *arg1;
    a = sa;
    if (sa >= 0) {
        sa = 1;
    } else {
        sa = -1;
        a = -a;
    }
    if (b >= 0) {
        sb = 1;
    } else {
        sb = -1;
        b = -b;
    }
    if (a <= arg4) {
        a = 0;
    } else {
        a = a - arg4;
    }
    if (b <= arg4) {
        b = 0;
    } else {
        b = b - arg4;
    }
    if (a == 0 && b == 0) {
        *arg1 = 0;
        *arg0 = 0;
        return;
    }
    t9 = arg3 * b;
    t7 = arg3 * a;
    if (t9 <= t7) {
        t = arg3 * arg2;
        t7 = t7 + b * (arg2 - arg3);
        if (t < t7) {
            a = (s8)((a * t) / t7);
            b = (s8)((b * t) / t7);
        }
    } else {
        t = arg3 * arg2;
        t7 = t9 + a * (arg2 - arg3);
        if (t < t7) {
            a = (s8)((a * t) / t7);
            b = (s8)((b * t) / t7);
        }
    }
    *arg0 = sa * a;
    *arg1 = sb * b;
}

void fn_80211CC0(void *arg0) {
    void fn_80211B90(s8 *, s8 *, s8, s8, s8);
    extern u8 lbl_80282268[];

    u8 *config;
    u8 *maximum;
    s32 i;
    u8 *input;
    u8 hi;
    u8 value;
    u8 lo;

    i = 0;
    input = (u8 *)arg0;
    config = lbl_80282268;
    maximum = config + 1;

    while (i < 4) {
        if ((s8)input[0xA] == 0) {
            fn_80211B90(
                (s8 *)(input + 2),
                (s8 *)(input + 3),
                (s8)config[3],
                (s8)config[4],
                (s8)config[2]
            );

            fn_80211B90(
                (s8 *)(input + 4),
                (s8 *)(input + 5),
                (s8)config[6],
                (s8)config[7],
                (s8)config[5]
            );

            if ((hi = maximum[0], value = input[6], lo = config[0], value <= lo)) {
                input[6] = 0;
            } else {
                if (hi < value) {
                    input[6] = hi;
                }
                input[6] = input[6] - config[0];
            }

            if ((hi = maximum[0], value = input[7], lo = config[0], value <= lo)) {
                input[7] = 0;
            } else {
                if (hi < value) {
                    input[7] = hi;
                }
                input[7] = input[7] - config[0];
            }
        }
        i += 1;
        input += 0xC;
    }
}

extern u16 Scb_80339420[4];
extern u16 lbl_80282268[8];
#include "common.h"
#include <dolphin/os.h>
#include "global.h"
extern u16 lbl_8029D210[];
