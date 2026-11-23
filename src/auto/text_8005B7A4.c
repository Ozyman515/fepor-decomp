/* Functions from 0x8005AE20 to 0x80072408, found by decomp-toolkit. */
#include "common.h"
#include "global.h"
#pragma cplusplus on
struct UiSelectionHandler {
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
virtual void select(void *, void *) = 0;
virtual void deselect(void *, void *) = 0;
};
#pragma cplusplus reset

typedef struct MaterialColor { u8 r, g, b, a; } MaterialColor;
static inline u8 *GActor_FindAnimation(u8 *p) {
    while (p) {
        u8 *anim = *(u8 **)(p + 0x44);
        if (anim) return anim;
        p = *(u8 **)(p + 4);
    }
    return 0;
}

typedef struct {
    s32 at0[16];
    s32 at40[8];
    s32 at60[8];
    s32 at80[16];
} StagePool;

// Structure definition for the argument passed to fn_80063A14
typedef struct {
    void* unk0;
    void* unk4;
    void* unk8;
    void* unkC;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    s32 unk34;
} SomeStruct;

struct UnkStruct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
};

extern u16 gBattleState[1400];
extern f32 lbl_803692E0;
extern f32 lbl_80369300;
extern f32 lbl_8036930C;
extern f64 lbl_803692C0;
extern f32 lbl_803692B8;
extern u16 lbl_80285D18[];
extern char lbl_8026B590[];
extern f32 lbl_803691E0;
extern f32 lbl_803691E4;
extern f32 lbl_803691E8;
extern u8 lbl_8026B658[];

static inline u8 *FindEntryByName(char *name) {
    extern u8 gFileCache[];
    s32 Str_Cmp();
    u8 *e;
    char *start;
    u32 hash;
    s32 i;

    if (*name == '/') {
        name++;
    }
    start = name;
    hash = 0;
    while (*name != 0) {
        if (*name >= 'A' && *name <= 'Z') {
            *name += 0x20;
        }
        hash = *name++ + hash * 37;
    }
    for (i = 0, e = gFileCache; i < 0x400; i++, e += 0x7C) {
        if (hash == *(u32 *)(e + 0x2C) && Str_Cmp(start, e) == 0) {
            return gFileCache + i * 0x7C;
        }
    }
    return NULL;
}

static inline u32 FindUnk48(void *arg0) {
    while (arg0 != NULL) {
        u32 temp = M2C_FIELD(arg0, u32 *, 0x48);
        if (temp != 0U) {
            return temp;
        }
        arg0 = M2C_FIELD(arg0, void **, 4);
    }
    return 0U;
}

static inline u32 CalcUnk48Size(u32 found) {
    s16 t = M2C_FIELD(M2C_FIELD(found, void **, 0x48), s16 *, 0xA);
    return (((t * 12) + 31) & ~31) / 2 * 2;
}

static inline u32 AddUnk48Size(u32 base, void *node) {
    void *current = node;

    while (current != NULL) {
        u32 temp = M2C_FIELD(current, u32 *, 0x48);
        if (temp != 0U) {
            return base + CalcUnk48Size(temp);
        }
        current = M2C_FIELD(current, void **, 4);
    }
    return base + CalcUnk48Size(0);
}

#pragma use_lmw_stmw on

#pragma use_lmw_stmw off

#pragma global_optimizer off

static inline u32 HashString(u8 *s) {
    u32 hash;
    u8 b;
    hash = 0;
    while ((b = *s, (s8)b != 0)) {
        hash += b;
        s++;
        hash <<= 4;
    }
    return hash;
}

static inline u32 ColFromHash(u32 hash) {
    extern u32 lbl_802F03A8[0x4D];
    u32 *p;
    s32 i;
    s32 ctr;
    p = lbl_802F03A8;
    i = 0;
    for (ctr = 0x4D; ctr != 0; ctr--) {
        if (hash == *p) {
            switch (i) {
            case 9:
            case 0x21:
                return 0x1C;
            default:
                return (u8)i;
            }
        }
        p++;
        i++;
    }
    return 0;
}

#pragma use_lmw_stmw on

#pragma optimization_level reset
#pragma use_lmw_stmw off

#pragma optimization_level 4

#pragma optimization_level reset

u8 fn_8005B7A4(u8 *s) {
extern u32 lbl_802F03A8[0x4D];
u32 hash; u8 b; u32 *p; s32 i; s32 ctr;
hash=0;
while((b=*s,(s8)b!=0)) { hash+=b; s++; hash<<=4;}
p=lbl_802F03A8; i=0;
for(ctr=0x4D;ctr!=0;ctr--) {
if(hash==*p) {
switch(i) { case 9: case 0x21: return 0x1C; default: return (u8)i; }
}
p++; i++;
}
return 0;
}

void fn_8005B820(void) {
    void *fn_80019DBC(u8);
    extern u32 lbl_802F03A8[];
    u32 *out;
    u8 *entry;
    s32 i;
    u32 acc;
    u8 *s;
    u8 b;

    entry = fn_80019DBC(0);
    out = lbl_802F03A8;
    for (i = 0x4D; i != 0; i--) {
        s = *(u8 **)entry;
        acc = 0;
        while ((b = *s, (s8)b != 0)) {
            acc = (acc + b) << 4;
            s++;
        }
        *out = acc;
        out++;
        entry += 0xC;
    }
}

u8 fn_8005B888(s32 arg0) {
    extern void *lbl_803672F4;
    struct Entry { u8 pad[0x3f]; u8 f; };
    struct Entry *entries = lbl_803672F4;
    if (entries == NULL) return 0;
    return entries[arg0].f;
}

void *fn_8005B8AC(s32 arg0) {
    extern void *lbl_803672F4;
    if (lbl_803672F4 == NULL) {
        return NULL;
    }
    return (u8 *)lbl_803672F4 + (arg0 << 6);
}

s32 fn_8005B8CC(void) {
    extern void *lbl_803672F4;
    if ((void *) lbl_803672F4 == NULL) {
        return 0;
    }
    return M2C_FIELD(lbl_803672F4, s32 *, 0x4000);
}

extern void *lbl_803672F4;
s32 fn_8005B8E8(void) {
    void Heap_Free(void *);
    Heap_Free(lbl_803672F4);
    lbl_803672F4 = 0;
    return 1;
}

s32 fn_8005B918(s32 arg0) {
    void *fn_800C45B8(s32, void *, s32);
    s32 fn_8020CD64(s32, void *);
    s32 fn_8020CE24(void *, void *);
    void fn_8020CEC8(void *);
    void Str_CopyPad(void *, s32, s32);
    extern void *lbl_803672F4;
    extern u8 lbl_8026B330[];
    u8 iter[0xC];
    s32 out[3];
    void *p;
    s32 flag, name;
    if (lbl_803672F4 != NULL) return 0;
    if (fn_8020CD64(arg0, iter) == 0) return 0;
    p = fn_800C45B8(-0x4004, lbl_8026B330 + 5, 0);
    if (p != NULL) { *(u32 *)((u8 *)p + 0x4000) = 0; }
    lbl_803672F4 = p;
    while (fn_8020CE24(iter, out) != 0) {
        p = lbl_803672F4;
        name = out[2];
        flag = out[1] != 0;
        ((u8 *)p)[(*(u32 *)((u8 *)p + 0x4000) << 6) + 0x3f] = flag;
        Str_CopyPad((u8 *)p + (*(u32 *)((u8 *)p + 0x4000) << 6), name, 0x3e);
        *(u32 *)((u8 *)p + 0x4000) += 1;
    }
    fn_8020CEC8(iter);
    return 1;
}

u8 fn_8005BA00(void) {
    extern u8 lbl_803672E8;
    return lbl_803672E8;
}

void fn_8005BA08(s8 arg0) {
    extern s8 lbl_803672E8;
    lbl_803672E8 = arg0;
}

/* Return whether the named file is ready: load-done (0x2000) or absent (0x8000). */
s32 FileCache_IsReady(char *name) {
    u8 *entry = FindEntryByName(name);
    u16 flags;

    if (entry == NULL) {
        flags = 0x8000;
    } else {
        flags = *(u16 *)(entry + 0x30);
    }
    if (flags & 0x2000) {
        return 1;
    }
    return (flags >> 15) & 1;
}

s32 fn_8005BB2C(void) {
    u8 fn_800B2FF4(s32);
    s64 OSGetTime(void);
    extern u8 gFileCache[];
    typedef struct {
        s8 name;
        u8 pad[0x2F];
        volatile u16 flags;
        u16 ref;
        u32 stamp;
        u8 rest[0x7C - 0x38];
    } Entry;
    Entry *e;
    u32 time;
    s32 i;

    if ((u8)fn_800B2FF4(0) == 0) {
        return 0;
    }
    time = (u32)(OSGetTime() / (*(u32 *)0x800000F8 >> 2));
    e = (Entry *)gFileCache;
    for (i = 0; i < 0x100; i++) {
        if (e->name != 0) {
            if (!(e->flags & 0x2000) && (e->flags & 0x200) && time <= e->stamp + 0xA) {
                return 0;
            }
        }
        if ((++e)->name != 0) {
            if (!(e->flags & 0x2000) && (e->flags & 0x200) && time <= e->stamp + 0xA) {
                return 0;
            }
        }
        if ((++e)->name != 0) {
            if (!(e->flags & 0x2000) && (e->flags & 0x200) && time <= e->stamp + 0xA) {
                return 0;
            }
        }
        if ((++e)->name != 0) {
            if (!(e->flags & 0x2000) && (e->flags & 0x200) && time <= e->stamp + 0xA) {
                return 0;
            }
        }
        e++;
    }
    return 1;
}

void fn_8005C8D8();
void fn_8005BC8C() {
    void fn_8005C8D8();
    fn_8005C8D8();
}

void fn_8005BCAC(void) {
    fn_8005C8D8(-1);
}

void fn_8005BCD0(void) {
    M2C_UNK fn_8005CBC8();
    fn_8005CBC8();
}

void fn_8005BCF0(void) {
    extern u8 lbl_803672E9;
    extern s8 gFileCacheWorkRead;
    extern s8 gFileCacheWorkWrite;
    extern u8 gFileCacheWorkThreadQueue[8];
    extern u8 gFileCache[126976];
    extern u8 lbl_8030FAF8[8192];
    extern u8 lbl_8030F7E0[792];
    void OSInitThreadQueue(u8 *queue);
    s32 fn_8020A558(u8 *a, void *b, s32 c, u8 *d, s32 e, s32 f, s32 g);
    s32 fn_8020A9E0(u8 *a);
    extern void FileCache_WorkerThread(void);
    s32 i;
    u8 (*e)[0x3E0];

    for (i = 0, e = (u8 (*)[0x3E0])gFileCache; i < 0x80; i++, e++) {
        *(s8 *)(*e + 0x0) = 0;
        *(s32 *)(*e + 0x2C) = 0;
        *(s16 *)(*e + 0x30) = 0;
        *(s16 *)(*e + 0x32) = 0;
        *(s32 *)(*e + 0x38) = 0;
        *(s32 *)(*e + 0x3C) = 0;
        *(s8 *)(*e + 0x7C) = 0;
        *(s32 *)(*e + 0xA8) = 0;
        *(s16 *)(*e + 0xAC) = 0;
        *(s16 *)(*e + 0xAE) = 0;
        *(s32 *)(*e + 0xB4) = 0;
        *(s32 *)(*e + 0xB8) = 0;
        *(s8 *)(*e + 0xF8) = 0;
        *(s32 *)(*e + 0x124) = 0;
        *(s16 *)(*e + 0x128) = 0;
        *(s16 *)(*e + 0x12A) = 0;
        *(s32 *)(*e + 0x130) = 0;
        *(s32 *)(*e + 0x134) = 0;
        *(s8 *)(*e + 0x174) = 0;
        *(s32 *)(*e + 0x1A0) = 0;
        *(s16 *)(*e + 0x1A4) = 0;
        *(s16 *)(*e + 0x1A6) = 0;
        *(s32 *)(*e + 0x1AC) = 0;
        *(s32 *)(*e + 0x1B0) = 0;
        *(s8 *)(*e + 0x1F0) = 0;
        *(s32 *)(*e + 0x21C) = 0;
        *(s16 *)(*e + 0x220) = 0;
        *(s16 *)(*e + 0x222) = 0;
        *(s32 *)(*e + 0x228) = 0;
        *(s32 *)(*e + 0x22C) = 0;
        *(s8 *)(*e + 0x26C) = 0;
        *(s32 *)(*e + 0x298) = 0;
        *(s16 *)(*e + 0x29C) = 0;
        *(s16 *)(*e + 0x29E) = 0;
        *(s32 *)(*e + 0x2A4) = 0;
        *(s32 *)(*e + 0x2A8) = 0;
        *(s8 *)(*e + 0x2E8) = 0;
        *(s32 *)(*e + 0x314) = 0;
        *(s16 *)(*e + 0x318) = 0;
        *(s16 *)(*e + 0x31A) = 0;
        *(s32 *)(*e + 0x320) = 0;
        *(s32 *)(*e + 0x324) = 0;
        *(s8 *)(*e + 0x364) = 0;
        *(s32 *)(*e + 0x390) = 0;
        *(s16 *)(*e + 0x394) = 0;
        *(s16 *)(*e + 0x396) = 0;
        *(s32 *)(*e + 0x39C) = 0;
        *(s32 *)(*e + 0x3A0) = 0;
    }
    if ((u8) lbl_803672E9 == 0) {
        gFileCacheWorkWrite = 0;
        gFileCacheWorkRead = 0;
        OSInitThreadQueue(gFileCacheWorkThreadQueue);
        fn_8020A558(lbl_8030F7E0, &FileCache_WorkerThread, 0, lbl_8030FAF8 + 0x2000, 0x2000, 0x10, 1);
        fn_8020A9E0(lbl_8030F7E0);
        lbl_803672E9 = 1;
    }
}

/* Forever drain the FileCache async work ring, sleeping when empty. */
void FileCache_WorkerThread(void) {
    void DCFlushRange(s32, s32);
    void FileCache_OnCancel(void *, s32);
    void FileCache_OnLoadDone(void *, s32);
    void FileCache_SpawnArchiveEntries(void *);
    void fn_800C4588(s32);
    void OSSleepThread(u8 *);
    extern u8 gFileCacheWorkQueue[];
    extern volatile u8 gFileCacheWorkRead;
    extern volatile u8 gFileCacheWorkWrite;
    extern u8 gFileCacheWorkThreadQueue[8];
    void *entry;
    s32 val;
    u8 type;

    goto check;
loop:
    entry = gFileCacheWorkQueue + gFileCacheWorkRead * 0xC;
    type = *(u8 *)entry;
    switch (type) {
    case 0:
        FileCache_OnLoadDone(*(void **)((u8 *)entry + 4), *(s32 *)((u8 *)entry + 8));
        break;
    case 1:
        FileCache_OnCancel(*(void **)((u8 *)entry + 4), *(s32 *)((u8 *)entry + 8));
        break;
    case 2:
        val = *(s32 *)((u8 *)entry + 8);
        entry = *(void **)((u8 *)entry + 4);
        if (*(volatile u16 *)((u8 *)entry + 0x30) & 0x400) {
            if (*(volatile u16 *)((u8 *)entry + 0x30) & 0x2000) {
                fn_800C4588(val);
            }
        } else {
            if (*(volatile u16 *)((u8 *)entry + 0x30) & 0x800) {
                FileCache_SpawnArchiveEntries(entry);
            }
            *(volatile u16 *)((u8 *)entry + 0x30) |= 0x2000;
        }
        *(volatile u16 *)((u8 *)entry + 0x30) &= ~0x80;
        break;
    case 3:
        val = *(s32 *)((u8 *)entry + 8);
        entry = *(void **)((u8 *)entry + 4);
        DCFlushRange(*(s32 *)((u8 *)entry + 0x38), *(s32 *)((u8 *)entry + 0x3C));
        if (!(*(u16 *)((u8 *)entry + 0x30) & 0x80)) {
            fn_800C4588(val);
        }
        if (*(u16 *)((u8 *)entry + 0x30) & 0x800) {
            FileCache_SpawnArchiveEntries(entry);
        }
        *(u16 *)((u8 *)entry + 0x30) |= 0x2000;
        break;
    }
    gFileCacheWorkRead = (gFileCacheWorkRead + 1) & 0x3F;
check:
    if (gFileCacheWorkRead != gFileCacheWorkWrite) {
        goto loop;
    }
    OSSleepThread(gFileCacheWorkThreadQueue);
    goto check;
}

void FileCache_OnCancel(void *arg0, s32 arg1) {
    void FileCache_SpawnArchiveEntries(void *);
    void FileCache_ExpandBuffer(void *);

    if (*(volatile u16 *)((u8 *)arg0 + 0x30) & 0x400) {
        FileCache_ExpandBuffer(arg0);
    } else {
        if (*(volatile u16 *)((u8 *)arg0 + 0x30) & 0x800) {
            FileCache_SpawnArchiveEntries(arg0);
        }
        *(volatile u16 *)((u8 *)arg0 + 0x30) |= 0x2004;
    }
}

/* After DVD load: optionally start ARAM DMA (flag 8), else expand buffer / spawn archive children and mark load-done. */
void FileCache_OnLoadDone(void *entry) {
    void FileCache_SpawnArchiveEntries(void *);
    void FileCache_ExpandBuffer(void *);
    u32 AramCache_Find(void);
    u8 AramCache_Request(void *, s32, s32, void *, void *);
    extern u8 FileCache_QueueAramDone[];
    volatile u16 *flags = (u16 *)((u8 *)entry + 0x30);

    if ((*flags & 8) && AramCache_Find() == 0 &&
        AramCache_Request(entry, *(s32 *)((u8 *)entry + 0x38), *(s32 *)((u8 *)entry + 0x3c),
                          FileCache_QueueAramDone, entry)) {
        *flags |= 0x80;
        *(s32 *)((u8 *)entry + 0x6c) = *(s32 *)((u8 *)entry + 0x38);
        if (*flags & 0x400) {
            FileCache_ExpandBuffer(entry);
        }
    } else {
        if (*flags & 0x400) {
            FileCache_ExpandBuffer(entry);
            return;
        }
        if (*flags & 0x800) {
            FileCache_SpawnArchiveEntries(entry);
        }
        *flags |= 0x2000;
    }
}

s32 fn_8005C0AC(void *arg0, u8 *arg1) {
    void *fn_80234200(void *, s32);
    void strcpy(void *, void *);
    void fn_80238ADC(void *);
    s32 Str_Cmp(void *, void *);
    char sp18[0x10];
    char sp8[0x10];
    void *temp_r3;
    u8 *var_r31;

    var_r31 = arg1;
    if ((s32)*arg1 == 0x2E) {
        var_r31 += 1;
    }
    temp_r3 = fn_80234200(arg0, 0x2E);
    if (temp_r3 == 0) {
        return (s8)*var_r31 == 0;
    }
    strcpy(sp18, (u8 *)temp_r3 + 1);
    fn_80238ADC(sp18);
    strcpy(sp8, var_r31);
    fn_80238ADC(sp8);
    return Str_Cmp(sp18, sp8) == 0;
}

#pragma use_lmw_stmw on
u16 FileCache_Probe(char *name) {
    s32 fn_8020C3E0(char *);
    u8 *entry = FindEntryByName(name);
    u16 flags;
    s32 tmp;

    if (entry == NULL) {
        flags = 0x8000;
    } else {
        flags = *(u16 *)(entry + 0x30);
    }
    if (!(flags & 0x8000)) {
        return flags;
    }
    tmp = fn_8020C3E0(name);
    tmp = ~((tmp + 1) | (-1 - tmp));
    tmp >>= 31;
    tmp &= 0x8000;
    return (u16)tmp;
}
#pragma use_lmw_stmw reset
/* Return the byte size of the named file-cache entry, or 0 if absent. */
s32 FileCache_GetSize(char *name) {
    u8 *entry = FindEntryByName(name);
    if (entry != NULL) {
        return *(s32 *)(entry + 0x3C);
    }
    return 0;
}

s32 fn_8005C368(u32 arg0)
{
    extern u8 gFileCache[];
    struct { u8 *e; unsigned long j; } s;
    u8 *found;
    s32 ctr;

    s.j = 0;
    s.e = gFileCache;
    for (ctr = 0x400; ctr > 0; ctr--) {
        if (*(u32 *)(s.e + 0x38) == arg0) {
            found = gFileCache + s.j * 0x7C;
            goto done;
        }
        s.e += 0x7C;
        s.j += 1;
    }
    found = 0;
done:
    if (found == 0) return -1;
    return *(u16 *)(found + 0x32);
}

/* Return 1 if a file-cache entry with this name exists, else 0. */
s32 FileCache_Exists(char *name) {
    if (FindEntryByName(name) == NULL) {
        return 0;
    }
    return 1;
}

#pragma no_register_save_helpers on
#pragma use_lmw_stmw on
void FileCache_OrFlags(char *name, s32 flags) {
    /* OR flags into the named file-cache entry's flag word at +0x30. */
    u8 *entry = FindEntryByName(name);
    s32 v = *(u16 *)(entry + 0x30);
    v |= flags;
    *(u16 *)(entry + 0x30) = v;
}
/* Mark the named file-cache entry as relocated (flags |= 0x4000). */
void FileCache_MarkRelocated(char *name) {
    u8 *e = FindEntryByName(name);
    u16 v = *(u16 *)(e + 0x30);
    v |= 0x4000;
    *(u16 *)(e + 0x30) = v;
}

u16 FileCache_GetFlags(char *name) {
    /* Return the named file-cache entry's flags, or 0x8000 if not cached. */
    u8 *entry = FindEntryByName(name);
    if (entry == NULL) {
        return 0x8000;
    }
    return *(u16 *)(entry + 0x30);
}

void fn_8005C7A4(s32 arg0) {
    arg0 = (s8)arg0;
    fn_8005CF6C(arg0);
}

void fn_8005C7C8(void) {
    M2C_UNK FileCache_ReleaseByName();
    FileCache_ReleaseByName();
}

void fn_8005C7E8(void) {
    M2C_UNK FileCache_ReleaseByKey();
    FileCache_ReleaseByKey();
}

void fn_8005C808(void *arg0) {
    M2C_UNK fn_8005D474(void *, M2C_UNK);
    fn_8005D474(arg0, 2);
}

M2C_UNK fn_8005C82C() {
    M2C_UNK fn_8005D474();
    return fn_8005D474();
}

void FileCache_Load(s32 arg0) {
    void fn_8005D474(s32, s32);
    fn_8005D474(arg0, 0);
}

void fn_8005C870(void) {
    M2C_UNK fn_8005D330();
    fn_8005D330();
}

void fn_8005C890(s32 arg0) {
    extern void fn_8005D330(s32, s32);
    fn_8005D330(arg0, 0xC);
}

void fn_8005C8B4(s32 arg0) {
    void fn_8005D330(s32, s32);
    fn_8005D330(arg0, 0);
}

#pragma opt_common_subs off
void fn_8005C8D8(arg0)
s8 arg0;
{
    void DebugPrint(char *, ...);
    s64 OSGetTime(void);
    void OS_YieldThread(void);
    void fn_8003FED8(void *);
    void fn_800C4588(void *);
    extern u8 gFileCache[];
    extern u8 lbl_8026B330[];
    u8 *entry;
    u32 time;
    s32 index;

    DebugPrint((char *)(lbl_8026B330 + 6), arg0);
    time = (u32)(OSGetTime() / (*(u32 *)0x800000F8 >> 2));

    index = 0;
    entry = gFileCache;
    do {
        if (*(s8 *)entry != 0 && *(u16 *)(entry + 0x32) == 0 &&
            (arg0 < 0 || *(s8 *)(entry + 0x29) == arg0) &&
            *(void **)(entry + 0x38) != NULL &&
            (*(volatile u16 *)(entry + 0x30) & 0x2000) &&
            !(*(volatile u16 *)(entry + 0x30) & 0x1000)) {
            if ((*(volatile u16 *)(entry + 0x30) & 0x200) && time < *(u32 *)(entry + 0x34) + 0xA) {
                DebugPrint((char *)(lbl_8026B330 + 0x1C), entry);
            } else {
                DebugPrint((char *)(lbl_8026B330 + 0x4E), entry, *(u32 *)(entry + 0x3C));
                if (*(volatile u16 *)(entry + 0x30) & 0x1000) {
                    goto next;
                }
                while (*(volatile u16 *)(entry + 0x30) & 0x80) {
                    OS_YieldThread();
                }
                if (*(volatile u16 *)(entry + 0x30) & 0x800) {
                    if (*(volatile u16 *)(entry + 0x30) & 0x2000) {
                        s32 i;
                        u8 *item;
                        u8 *list;
                        list = *(u8 **)(entry + 0x38);
                        i = 0;
                        item = list + 8;
                        for (; i < *(u16 *)(list + 4); item += 0x10, i++) {
                            u8 *found;
                            u32 j;
                            u32 key;
                            u8 *e;
                            unsigned ctr;
                            e = gFileCache;
                            key = *(u32 *)(item + 8);
                            j = 0;
                            for (ctr = 0x400; ctr > 0; ctr--) {
                                if (*(u32 *)(e + 0x38) == key) {
                                    found = gFileCache + j * 0x7C;
                                    goto found1;
                                }
                                e += 0x7C;
                                j++;
                            }
                            found = 0;
                        found1:
                            if (found && (*(u16 *)(found + 0x30) & 1)) {
                                fn_8003FED8(*(void **)(found + 0x38));
                                *(u16 *)(found + 0x30) &= 0xFFFE;
                            }
                        }
                    } else if (*(volatile u16 *)(entry + 0x30) & 1) {
                        fn_8003FED8(*(void **)(entry + 0x38));
                        *(u16 *)(entry + 0x30) &= 0xFFFE;
                    }
                }
                if ((*(volatile u16 *)(entry + 0x30) & 0x800) && (*(volatile u16 *)(entry + 0x30) & 0x2000)) {
                    s32 i;
                    u8 *item;
                    u8 *list;
                    list = *(u8 **)(entry + 0x38);
                    i = 0;
                    item = list + 8;
                    for (; i < *(u16 *)(list + 4); item += 0x10, i++) {
                        u8 *found;
                        u32 j;
                        u32 key;
                        u8 *e;
                        unsigned ctr;
                        e = gFileCache;
                        key = *(u32 *)(item + 8);
                        j = 0;
                        for (ctr = 0x400; ctr > 0; ctr--) {
                            if (*(u32 *)(e + 0x38) == key) {
                                found = gFileCache + j * 0x7C;
                                goto found2;
                            }
                            e += 0x7C;
                            j++;
                        }
                        found = 0;
                    found2:
                        if (found) {
                            *(found) = 0;
                            *(u32 *)(found + 0x2C) = 0;
                            *(u16 *)(found + 0x30) = 0;
                            *(u16 *)(found + 0x32) = 0;
                            *(u32 *)(found + 0x38) = 0;
                            *(u32 *)(found + 0x3C) = 0;
                        }
                    }
                }
                fn_800C4588(*(void **)(entry + 0x38));
                *(u8 *)entry = 0;
                *(u32 *)(entry + 0x2C) = 0;
                *(u16 *)(entry + 0x30) = 0;
                *(u16 *)(entry + 0x32) = 0;
                *(u32 *)(entry + 0x38) = 0;
                *(u32 *)(entry + 0x3C) = 0;
            }
        }
    next:
        index++;
        entry += 0x7C;
    } while (index < 0x400);
}
#pragma opt_common_subs reset
void fn_8005CBC8(void)
{
    extern char lbl_8026B330[];
    extern unsigned char gFileCache[];
    extern float lbl_803691A8;
    extern float lbl_803691AC;
    extern float lbl_803691B0;
    extern void DebugPrint(const char *, ...);
    extern long long OSGetTime(void);

    unsigned char *entry;
    unsigned short flags;
    int count;
    int total;
    int i;
    char buffer[16];
    char *p;
    float size1;
    float size2;

    DebugPrint(lbl_8026B330 + 0x69);

    entry = gFileCache;
    count = 0;
    total = 0;
    i = 0;

    do {
        if ((signed char)*entry != 0) {
            unsigned int ticks;

            ticks = (unsigned int)(
                OSGetTime() /
                (long long)(*(volatile unsigned int *)0x800000F8 >> 2)
            );

            DebugPrint(
                lbl_8026B330 + 0x8C,
                *(unsigned short *)(entry + 0x32),
                ticks - *(unsigned int *)(entry + 0x34),
                *(unsigned int *)(entry + 0x38),
                *(unsigned int *)(entry + 0x3C)
            );

            if (*(volatile unsigned short *)(entry + 0x30) & 0x5E07) {
                flags = *(volatile unsigned short *)(entry + 0x30);

                p = buffer;
                *p++ = '[';

                if (flags & 0x0001) *p++ = 'I';
                if (flags & 0x0002) *p++ = 'Z';
                if (flags & 0x0004) *p++ = 'V';
                if (flags & 0x0400) *p++ = 'c';
                if (flags & 0x0800) *p++ = 'P';
                if (flags & 0x1000) *p++ = 'C';
                if (flags & 0x4000) *p++ = 'U';
                if (flags & 0x0200) *p++ = 'R';

                *p++ = ']';
                *p = 0;

                DebugPrint(buffer);
            }

            DebugPrint(lbl_8026B330 + 0x9C, entry);

            count++;
            total += *(unsigned int *)(entry + 0x3C);
        }

        i++;
        entry += 0x7C;
    } while (i < 0x400);

    DebugPrint(lbl_8026B330 + 0xA0);
    DebugPrint(lbl_8026B330 + 0xCF);
    DebugPrint(lbl_8026B330 + 0xF9);
    DebugPrint(lbl_8026B330 + 0x121);
    DebugPrint(lbl_8026B330 + 0x145);
    DebugPrint(lbl_8026B330 + 0x165);
    DebugPrint(lbl_8026B330 + 0x185);
    DebugPrint(lbl_8026B330 + 0x1A9);
    DebugPrint(lbl_8026B330 + 0x1CD);
    DebugPrint(lbl_8026B330 + 0x1CF, count);

    size1 = (float)total / lbl_803691B0;
    size1 = lbl_803691AC * size1;
    size2 = (float)total / lbl_803691A8;

    DebugPrint(lbl_8026B330 + 0x1F1, size2, size1);
    DebugPrint(lbl_8026B330 + 0x21D);
}

#pragma global_optimizer off
void *fn_8005CEC0(void) {
    void fn_8005C8D8(s32);
    extern u8 lbl_802F04E0[];
    u8 *base;
    u8 *e;
    s32 i;
    s32 j;
    unsigned ctr;

    i = 0;
    base = lbl_802F04E0;
    e = base;
    for (ctr = 0x400; ctr > 0; ctr--) {
        if ((s8)*e == 0) {
            return lbl_802F04E0 + i * 0x7C;
        }
        e += 0x7C;
        i += 1;
    }
    fn_8005C8D8(-1);
    j = 0;
    for (ctr = 0x400; ctr > 0; ctr--) {
        if ((s8)*base == 0) {
            return lbl_802F04E0 + j * 0x7C;
        }
        base += 0x7C;
        j += 1;
    }
    return NULL;
}
#pragma global_optimizer on
int fn_8005CF6C(int arg0) {
 void fn_8020F334(void *); void fn_800C4588(void *); void fn_8003FED8(void *); void OS_YieldThread(void); extern u8 gFileCache[];
 u8 *entry; s32 index;
 index=0;entry=gFileCache;
 do {
 if(*(s8 *)entry && *(s8 *)(entry+0x29)==(s8)arg0) {
 if((*(volatile u16 *)(entry+0x30)&0x200) && !(*(volatile u16 *)(entry+0x30)&0x2000)) {
 fn_8020F334(entry+0x40); fn_800C4588(*(void **)(entry+0x38)); *(entry)=0; *(u32 *)(entry+0x2c)=0; *(u16 *)(entry+0x30)=0; *(u16 *)(entry+0x32)=0; *(u32 *)(entry+0x38)=0; *(u32 *)(entry+0x3c)=0;
 } else {
 if(!(*(volatile u16 *)(entry+0x30)&0x1000)) {

 while (*(volatile u16 *)(entry+0x30)&0x80) OS_YieldThread();
 if(*(volatile u16 *)(entry+0x30)&0x800) { if(*(volatile u16 *)(entry+0x30)&0x2000)
 { s32 i; u8 *item; u8 *list; list=*(u8 **)(entry+0x38); i=0; item=list+8; for(;i<*(u16 *)(list+4);item+=0x10,i++) { u8 *found; unsigned long j; u32 key; u8 *e; unsigned ctr; e=gFileCache; key=*(u32 *)(item+8); j=0; for(ctr=0x400;ctr>0;ctr--) {if(*(u32 *)(e+0x38)==key){found=gFileCache+j*0x7c;goto found1;}e+=0x7c;j++;}found=0;found1: if(found) {if(*(u16 *)(found+0x30)&1){fn_8003FED8(*(void **)(found+0x38)); *(u16 *)(found+0x30)&=0xfffe;}} } }
 } else if(*(volatile u16 *)(entry+0x30)&1) {fn_8003FED8(*(void **)(entry+0x38));*(u16 *)(entry+0x30)&=0xfffe;}
 if((*(volatile u16 *)(entry+0x30)&0x800) && (*(volatile u16 *)(entry+0x30)&0x2000))
 { s32 i; u8 *item; u8 *list; list=*(u8 **)(entry+0x38); i=0; item=list+8; for(;i<*(u16 *)(list+4);item+=0x10,i++) { u8 *found; unsigned long j; u32 key; u8 *e; unsigned ctr; e=gFileCache; key=*(u32 *)(item+8); j=0; for(ctr=0x400;ctr>0;ctr--) {if(*(u32 *)(e+0x38)==key){found=gFileCache+j*0x7c;goto found2;}e+=0x7c;j++;}found=0;found2: if(found) {*(found)=0; *(u32 *)(found+0x2c)=0; *(u16 *)(found+0x30)=0; *(u16 *)(found+0x32)=0; *(u32 *)(found+0x38)=0; *(u32 *)(found+0x3c)=0;} } }
 *(entry)=0; *(u32 *)(entry+0x2c)=0; *(u16 *)(entry+0x30)=0; *(u16 *)(entry+0x32)=0; *(u32 *)(entry+0x38)=0; *(u32 *)(entry+0x3c)=0;
 }
 }
 }
 next: index++;entry+=0x7c;
 }while(index<0x400);
return;
}

#pragma global_optimizer on
void FileCache_Release(u8 *);
/* Look up a file-cache entry by path/name and release it. */
void FileCache_ReleaseByName(char *name) {
    FileCache_Release(FindEntryByName(name));
}

#pragma global_optimizer off
void FileCache_ReleaseByKey(u32 arg0) {
    void FileCache_Release(void *);
    extern u8 gFileCache[];
    u8 *found = 0;
    u8 *e;
    u32 i;

    for (i = 0, e = gFileCache; i < 1024; ++i, e += 124) {
        if (*(u32 *)(e + 56) == arg0) {
            found = gFileCache + 124 * i;
            break;
        }
    }
    FileCache_Release(found);
}

#pragma use_lmw_stmw on
void fn_8005D330(char *name, u16 flags) {
    s64 OSGetTime(void);
    void *fn_8005CEC0(void);
    void fn_8005E12C(u8 *, char *, u16);
    void *AramCache_Find(char *);
    void fn_801ED7D0(void *);
    u8 *entry = FindEntryByName(name);
    u32 f;
    void *aram;

    if (entry) {
        *(u32 *)(entry + 0x34) = (u32)(OSGetTime() / (*(u32 *)0x800000F8 >> 2));
        return;
    }
    aram = AramCache_Find(name);
    if (aram) {
        fn_801ED7D0(aram);
        return;
    }
    entry = fn_8005CEC0();
    f = (u16)flags | 0x200U;
    {
        u16 cur = *(u16 *)(entry + 0x30);
        *(u16 *)(entry + 0x30) = cur | f;
    }
    fn_8005E12C(entry, name, f);
}

void *fn_8005D474(char *name,u16 flags) {
 s64 OSGetTime(void);
 void OS_YieldThread(void);
 void *fn_8005CEC0(void);
 void fn_8005DB40(void *,char *,void *,u16);
 void fn_8005E12C(void *,char *,u16);
 void *AramCache_Find(char *);
 s32 Str_Cmp(void *,void *);
 extern u8 gFileCache[];
 u8 *entry;
 {
 s32 i;
 u32 hash;
 u8 *start;
 u8 *p=(u8 *)name;
 u8 *e;
 u8 c;
 if((s32)*(u8 *)name=='/')p++;
 start=p;hash=0;
 while((s8)(c=*p)!=0) {
 if((s8)c>='A' && (s8)c<='Z') *p+=0x20;
 hash=(s8)*p++ + hash*37;
 }
 i=0;
 for(e=gFileCache;i<0x400;i++,e+=0x7c) {
 if(hash==*(u32 *)(e+0x2c)&&Str_Cmp(start,e)==0){entry=gFileCache+i*0x7c;goto found;}
 }
 entry=0;
 found:;
 }
 if(entry) {
 *(u16 *)(entry+0x30)|=flags;
 while(!(*(u16 *)(entry+0x30)&0x2000)) OS_YieldThread();
 *(u32 *)(entry+0x34)=(u32)(OSGetTime()/(*(u32 *)0x800000F8>>2));
 (*(u16 *)(entry+0x32))++;
 *(u16 *)(entry+0x30)&=~0x200;
 return *(void **)(entry+0x38);
 }
 { void *aram=AramCache_Find(name);
 if(aram) {
 entry=fn_8005CEC0();
 fn_8005DB40(entry,name,aram,flags);
 while(!(*(u16 *)(entry+0x30)&0x2000)) OS_YieldThread();
 *(u32 *)(entry+0x34)=(u32)(OSGetTime()/(*(u32 *)0x800000F8>>2));
 (*(u16 *)(entry+0x32))++;
 *(u16 *)(entry+0x30)&=~0x200;
 return *(void **)(entry+0x38);
 }
 }
 entry=fn_8005CEC0();
 fn_8005E12C(entry,name,flags);
 while(!(*(u16 *)(entry+0x30)&0x2000)) OS_YieldThread();
 *(u32 *)(entry+0x34)=(u32)(OSGetTime()/(*(u32 *)0x800000F8>>2));
 (*(u16 *)(entry+0x32))++;
 *(u16 *)(entry+0x30)&=~0x200;
 return *(void **)(entry+0x38);
}

#pragma use_lmw_stmw reset

#pragma global_optimizer reset
/* Drop one ref on a file-cache entry; when the count hits zero, cancel loads, wait, and free it. */
void FileCache_Release(u8 *entry) {
    s64 OSGetTime(void);
    void fn_8003FED8(void *);
    void fn_800C4588(void *);
    void OS_YieldThread(void);
    extern u8 gFileCache[];

    *(u16 *)(entry + 0x32) = *(u16 *)(entry + 0x32) - 1;
    *(u32 *)(entry + 0x34) = (u32)(OSGetTime() / (*(u32 *)0x800000F8 >> 2));
    if (*(u16 *)(entry + 0x32) != 0) {
        return;
    }

    if (*(volatile u16 *)(entry + 0x30) & 0x800) {
        if (*(volatile u16 *)(entry + 0x30) & 0x2000) {
            s32 i;
            u8 *item;
            u8 *list;
            list = *(u8 **)(entry + 0x38);
            i = 0;
            item = list + 8;
            goto check1;
        body1:
            {
                u8 *found;
                unsigned long j;
                u32 key;
                u8 *e;
                unsigned ctr;
                e = gFileCache;
                key = *(u32 *)(item + 8);
                j = 0;
                for (ctr = 0x400; ctr > 0; ctr--) {
                    if (*(u32 *)(e + 0x38) == key) {
                        found = gFileCache + j * 0x7C;
                        goto found1;
                    }
                    e += 0x7C;
                    j += 1;
                }
                found = 0;
            found1:
                if (found) {
                    if (*(u16 *)(found + 0x30) & 1) {
                        fn_8003FED8(*(void **)(found + 0x38));
                        *(u16 *)(found + 0x30) &= 0xFFFE;
                    }
                }
            }
            item += 0x10;
            i += 1;
        check1:
            if (i < *(u16 *)(list + 4)) {
                goto body1;
            }
        }
    } else if (*(volatile u16 *)(entry + 0x30) & 1) {
        fn_8003FED8(*(void **)(entry + 0x38));
        *(u16 *)(entry + 0x30) &= 0xFFFE;
    }

    if (*(volatile u16 *)(entry + 0x30) & 4) {
        goto spin1_check;
    spin1_body:
        OS_YieldThread();
    spin1_check:
        if (*(volatile u16 *)(entry + 0x30) & 0x80) {
            goto spin1_body;
        }
        if (!(*(volatile u16 *)(entry + 0x30) & 0x1000)) goto spin2_check;
        else return;

        goto spin2_check;
    spin2_body:
        OS_YieldThread();
    spin2_check:
        if (*(volatile u16 *)(entry + 0x30) & 0x80) {
            goto spin2_body;
        }

        if (*(volatile u16 *)(entry + 0x30) & 0x800) {
            if (*(volatile u16 *)(entry + 0x30) & 0x2000) {
                s32 i;
            u8 *item;
            u8 *list;
            list = *(u8 **)(entry + 0x38);
                i = 0;
                item = list + 8;
                goto check2;
            body2:
                {
                    u8 *found;
                unsigned long j;
                u32 key;
                u8 *e;
                unsigned ctr;
                    key = *(u32 *)(item + 8);
                    e = gFileCache;
                    j = 0;
                    for (ctr = 0x400; ctr > 0; ctr--) {
                        if (*(u32 *)(e + 0x38) == key) {
                            found = gFileCache + j * 0x7C;
                            goto found2;
                        }
                        e += 0x7C;
                        ++j;
                    }
                    found = 0;
                found2:
                    if (found) {
                        if (*(u16 *)(found + 0x30) & 1) {
                            fn_8003FED8(*(void **)(found + 0x38));
                            *(u16 *)(found + 0x30) &= 0xFFFE;
                        }
                    }
                }
                item += 0x10;
                ++i;
            check2:
                if (i < *(u16 *)(list + 4)) {
                    goto body2;
                }
            }
        } else if (*(volatile u16 *)(entry + 0x30) & 1) {
            fn_8003FED8(*(void **)(entry + 0x38));
            *(u16 *)(entry + 0x30) &= 0xFFFE;
        }

        if (*(volatile u16 *)(entry + 0x30) & 0x800) {
            if (*(volatile u16 *)(entry + 0x30) & 0x2000) {
                s32 i;
            u8 *item;
            u8 *list;
            list = *(u8 **)(entry + 0x38);
                i = 0;
                item = list + 8;
                goto check3;
            body3:
                {
                    u8 *found;
                unsigned long j;
                u32 key;
                u8 *e;
                unsigned ctr;
                    e = gFileCache;
                    key = *(u32 *)(item + 8);
                    j = 0;
                    for (ctr = 0x400; ctr > 0; ctr--) {
                        if (*(u32 *)(e + 0x38) == key) {
                            found = gFileCache + j * 0x7C;
                            goto found3;
                        }
                        e += 0x7C;
                        j += 1;
                    }
                    found = 0;
                found3:
                    if (found) {
                        found[0] = 0;
                        *(u32 *)(found + (u32)0x2C) = 0;
                        *(u16 *)(found + 0x30) = 0;
                        *(u16 *)(found + 0x32) = 0;
                        *(u32 *)(found + 0x38) = 0;
                        *(u32 *)(found + 0x3C) = 0;
                    }
                }
                item += 0x10;
                i++;
            check3:
                if (i < *(u16 *)(list + 4)) {
                    goto body3;
                }
            }
        }

        fn_800C4588(*(void **)(entry + 0x38));
        entry[0] = 0;
        *(u32 *)(entry + 0x2C) = 0;
        *(u16 *)(entry + 0x30) = 0;
        *(u16 *)(entry + 0x32) = 0;
        *(u32 *)(entry + 0x38) = 0;
        *(u32 *)(entry + 0x3C) = 0;
    }
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
void FileCache_SpawnArchiveEntries(u8 *arg0) {
    s64 OSGetTime(void);
    void *fn_8005CEC0(void);
    void strcpy(char *, char *);
    char path[0x30];
    u8 *entry;
    u8 *list;
    u8 *item;
    s32 i;
    char *var_r3;
    char *var_r4;
    char *var_r6;
    unsigned ctr;
    s32 var_r7;
    u8 temp_r5;

    if (*(u16 *)(arg0 + 0x30) & 0x800) {
        list = *(u8 **)(arg0 + 0x38);
        i = 0;
        item = list + 8;
        goto check;
    body:
        var_r3 = &path[0];
        var_r4 = (char *)arg0;
        var_r6 = var_r3;
        *(u32 *)(item + 4) = *(u32 *)(item + 4) + (u32)list;
        var_r7 = 0;
        *(u32 *)(item + 8) = *(u32 *)(item + 8) + (u32)list;
        for (ctr = 0x29; ctr > 0; ctr--) {
            temp_r5 = *(u8 *)var_r4;
            if ((s8)temp_r5 == 0) {
                break;
            }
            if ((s8)temp_r5 == '\\' || (s8)temp_r5 == '/') {
                var_r3 = &path[0] + 1;
                var_r3 = var_r3 + var_r7;
            }
            *var_r6 = temp_r5;
            var_r6 += 1;
            var_r7 += 1;
            var_r4 += 1;
        }
        strcpy(var_r3, *(char **)(item + 4));

        {
            u8 *temp_r3 = fn_8005CEC0();
            entry = temp_r3;
            *(u16 *)(temp_r3 + 0x32) = 0;
            var_r6 = &path[0];
            *(u16 *)(temp_r3 + 0x30) = 0x3000;
            *(u32 *)(temp_r3 + 0x3C) = *(u32 *)(item + 0xC);
            *(u32 *)(temp_r3 + 0x38) = *(u32 *)(item + 8);
            temp_r3[0x29] = arg0[0x29];
            if ((s8)path[0] == '/') {
                var_r6 += 1;
            }
            var_r7 = 0;
            *(u32 *)(entry + 0x2C) = 0;
            var_r3 = (char *)entry;
            for (ctr = 0x29; ctr > 0; ctr--) {
                temp_r5 = *(u8 *)var_r6;
                if ((s8)temp_r5 >= 'A' && (s8)temp_r5 <= 'Z') {
                    *var_r6 = temp_r5 + 0x20;
                }
                *var_r3 = *var_r6;
                temp_r5 = *(u8 *)var_r6;
                if ((s8)temp_r5 == 0) {
                    break;
                }
                var_r7 += 1;
                var_r3 += 1;
                *(u32 *)(entry + 0x2C) = (s8)temp_r5 + *(u32 *)(entry + 0x2C) * 0x25;
                var_r6 += 1;
            }
            *(u32 *)(entry + 0x34) = (u32)(OSGetTime() / (*(u32 *)0x800000F8 >> 2));
        }
        item += 0x10;
        i += 1;
    check:
        if (i < *(u16 *)(list + 4)) {
            goto body;
        }
    }
}
#pragma global_optimizer on

#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_8005DB40(u8 *arg0, char *arg1, u8 *arg2, u16 arg3) {
    s64 OSGetTime(void);
    u32 fn_8005E594(s8, s32, char *);
    u32 fn_800C44F4(s8);
    u32 fn_800C45B8(s32, char *, s32);
    u32 fn_800C4604(s8, s32, char *, s32);
    void fn_801ED848(void *, u32, void *, u8 *);
    void fn_8005E014(void);
    extern char lbl_8026B330[];
    extern u8 lbl_803672E8;
    u32 strlen(char *);
    char *src;
    u8 *dst;
    s32 i;
    char *p;
    char *ext;
    s32 match;
    s8 c;
    s8 drive;
    s32 size;
    s32 off;

    src = arg1;
    if (*arg1 == '/') {
        src++;
    }
    dst = arg0;
    *(s32 *)(arg0 + 0x2C) = 0;
    i = 0x29;
    do {
        c = *src;
        if (c >= 'A' && c <= 'Z') {
            *src = (char)(c + 0x20);
        }
        *dst = *src;
        c = *src;
        if (c == 0) {
            break;
        }
        *(s32 *)(arg0 + 0x2C) = (s8)c + *(s32 *)(arg0 + 0x2C) * 0x25;
        dst++;
        src++;
    } while (--i != 0);

    arg0[0x29] = lbl_803672E8;
    *(u16 *)(arg0 + 0x32) = 0;
    *(u16 *)(arg0 + 0x30) = arg3;
    *(u32 *)(arg0 + 0x34) = (u32)(OSGetTime() / (*(u32 *)0x800000F8 >> 2));

    p = arg1;
    ext = lbl_8026B330 + 0x221;
    for (;;) {
        c = *p;
        if (c == 0) {
            break;
        }
        if (c != '.') {
            p++;
            continue;
        }
        break;
    }
    for (;;) {
        c = *p;
        if (c == 0) {
            match = 0;
            break;
        }
        if (c == (s8)*ext) {
            ext++;
            p++;
            if ((s8)*ext == 0 && (s8)*p == 0) {
                match = 1;
                break;
            }
            continue;
        }
        match = 0;
        break;
    }
    if ((u8)match) {
        *(u16 *)(arg0 + 0x30) = 0xC00;
    }

    p = arg1;
    ext = lbl_8026B330 + 0x226;
    for (;;) {
        c = *p;
        if (c == 0) {
            break;
        }
        if (c != '.') {
            p++;
            continue;
        }
        break;
    }
    for (;;) {
        c = *p;
        if (c == 0) {
            match = 0;
            break;
        }
        if (c == (s8)*ext) {
            ext++;
            p++;
            if ((s8)*ext == 0 && (s8)*p == 0) {
                match = 1;
                break;
            }
            continue;
        }
        match = 0;
        break;
    }
    if ((u8)match) {
        *(u16 *)(arg0 + 0x30) = 0x800;
    }

    p = arg1;
    ext = lbl_8026B330 + 0x22B;
    for (;;) {
        c = *p;
        if (c == 0) {
            break;
        }
        if (c != '.') {
            p++;
            continue;
        }
        break;
    }
    for (;;) {
        c = *p;
        if (c == 0) {
            match = 0;
            break;
        }
        if (c == (s8)*ext) {
            ext++;
            p++;
            if ((s8)*ext == 0 && (s8)*p == 0) {
                match = 1;
                break;
            }
            continue;
        }
        match = 0;
        break;
    }
    if ((u8)match) {
        *(u16 *)(arg0 + 0x30) = 0x400;
    }

    *(s32 *)(arg0 + 0x3C) = *(s32 *)(arg2 + 0x64);
    if (*(u16 *)(arg0 + 0x30) & 0x410) {
        *(u32 *)(arg0 + 0x38) = fn_800C45B8(-*(s32 *)(arg0 + 0x3C), lbl_8026B330 + 5, 0);
    } else {
        drive = arg0[0x29];
        size = *(s32 *)(arg0 + 0x3C);
        if (fn_800C44F4(drive) < (u32)size) {
            *(u32 *)(arg0 + 0x38) = 0;
        } else {
            off = (s32)strlen(arg1) - 0xF;
            if (off < 0) {
                off = 0;
            }
            *(u32 *)(arg0 + 0x38) = fn_800C4604(drive, size, arg1 + off, size);
        }
    }
    if (*(u32 *)(arg0 + 0x38) == 0) {
        *(u32 *)(arg0 + 0x38) = fn_8005E594((s8)arg0[0x29], *(s32 *)(arg0 + 0x3C), arg1);
    }
    fn_801ED848(arg2, *(u32 *)(arg0 + 0x38), fn_8005E014, arg0);
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

void FileCache_ExpandBuffer(void *a)
{
    u32 fn_80006AC0(u32);
    u32 fn_800C44F4(s8);
    u32 fn_800C4604(s8, u32, void *, u32);
    u32 fn_8005E594(s32, u32, void *);
    void fn_800065B0(u32, u32, void *, void *);
    s32 strlen(void *);
    extern u8 fn_8005DF60[];
    u32 n;
    s32 ch;
    u32 old;
    s32 len;
    u32 result;

    old = *(u32 *)((u8 *)a + 0x38);
    n = fn_80006AC0(old);
    *(u32 *)((u8 *)a + 0x3c) = n;
    ch = *(s8 *)((u8 *)a + 0x29);
    n = *(u32 *)((u8 *)a + 0x3c);
    if (fn_800C44F4(ch) < n) {
        result = 0;
    } else {
        len = strlen(a) - 0xf;
        if (len < 0) {
            len = 0;
        }
        result = fn_800C4604(ch, n, (u8 *)a + len, n);
    }
    *(u32 *)((u8 *)a + 0x38) = result;
    if (*(u32 *)((u8 *)a + 0x38) == 0) {
        *(u32 *)((u8 *)a + 0x38) =
            fn_8005E594(*(s8 *)((u8 *)a + 0x29), *(u32 *)((u8 *)a + 0x3c), a);
    }
    fn_800065B0(old, *(u32 *)((u8 *)a + 0x38), fn_8005DF60, a);
}

void fn_8005DF60(void *arg0, s32 arg1) {
    void fn_8020AEC4(u8 *);
    extern u8 gFileCacheWorkQueue[];
    extern volatile u8 gFileCacheWorkWrite;
    extern u8 gFileCacheWorkThreadQueue[8];
    u8 *entry;

    entry = gFileCacheWorkQueue + gFileCacheWorkWrite * 0xC;
    entry[0] = 3;
    *(void **)(entry + 4) = arg0;
    *(s32 *)(entry + 8) = arg1;
    gFileCacheWorkWrite = (gFileCacheWorkWrite + 1) & 0x3F;
    fn_8020AEC4(gFileCacheWorkThreadQueue);
}

void FileCache_QueueAramDone(void *arg0) {
    void fn_8020AEC4(u8 *);
    extern u8 gFileCacheWorkQueue[];
    extern volatile u8 gFileCacheWorkWrite;
    extern u8 gFileCacheWorkThreadQueue[8];
    u8 *entry;
    s32 val;

    entry = gFileCacheWorkQueue + gFileCacheWorkWrite * 0xC;
    val = *(s32 *)((u8 *)arg0 + 0x6c);
    entry[0] = 2;
    *(void **)(entry + 4) = arg0;
    *(s32 *)(entry + 8) = val;
    gFileCacheWorkWrite = (gFileCacheWorkWrite + 1) & 0x3F;
    fn_8020AEC4(gFileCacheWorkThreadQueue);
}

void fn_8005E014(void *arg0) {
    void fn_8020AEC4(u8 *);
    extern u8 gFileCacheWorkQueue[];
    extern volatile u8 gFileCacheWorkWrite;
    extern u8 gFileCacheWorkThreadQueue[8];
    u8 *entry;

    entry = gFileCacheWorkQueue + gFileCacheWorkWrite * 0xC;
    entry[0] = 1;
    *(void **)(entry + 4) = arg0;
    *(s32 *)(entry + 8) = 0;
    gFileCacheWorkWrite = (gFileCacheWorkWrite + 1) & 0x3F;
    fn_8020AEC4(gFileCacheWorkThreadQueue);
}

void fn_8005E070(s32 arg0, void *arg1) {
    void fn_8020C79C(void *);
    void fn_8020AEC4(u8 *);
    extern u8 gFileCacheWorkQueue[];
    extern volatile u8 gFileCacheWorkWrite;
    extern u8 gFileCacheWorkThreadQueue[8];
    u8 *entry;
    s32 val;

    val = *(s32 *)((u8 *)arg1 + 0x2C);
    fn_8020C79C(arg1);
    if (arg0 >= 0) {
        entry = gFileCacheWorkQueue + gFileCacheWorkWrite * 0xC;
        entry[0] = 0;
        *(s32 *)(entry + 4) = val;
        *(s32 *)(entry + 8) = 0;
        gFileCacheWorkWrite = (gFileCacheWorkWrite + 1) & 0x3F;
        fn_8020AEC4(gFileCacheWorkThreadQueue);
    }
}

void fn_8005E0F0(void) {
    void fn_8020A824(void *);
    extern u8 lbl_8030F7E0[];
    extern u8 lbl_803672E9;
    if (lbl_803672E9 != 0) {
        fn_8020A824(lbl_8030F7E0);
        lbl_803672E9 = 0;
    }
}

#pragma use_lmw_stmw on
void fn_8005E12C(u8 *arg0, char *arg1, u16 arg2) {
    s64 OSGetTime(void);
    u32 fn_8005E594(s8, s32, char *);
    u32 fn_800C44F4(s8);
    u32 fn_800C45B8(s32, char *, s32);
    u32 fn_800C4604(s8, s32, char *, s32);
    void fn_8020C6D4(char *, u8 *);
    void fn_8020CB38(u8 *, u32, s32, s32, void *, s32);
    extern void fn_8005E070(void);
    extern char lbl_8026B330[];
    extern u8 lbl_803672E8;
    u32 strlen(char *);
    char *src;
    u8 *dst;
    unsigned ctr;
    char *p;
    char *ext;
    u8 match;
    u8 ch;
    s8 sc;
    s8 drive;
    s32 size;
    s32 off;
    u32 res;
    s32 z;
    u16 flags;

    flags = arg2;
    src = arg1;
    if ((s8)arg1[0] == (s8)'/') {
        src = src + 1;
    }
    z = 0;
    dst = arg0;
    *(s32 *)(arg0 + 0x2C) = z;
    for (ctr = 0x29; ctr != 0; ctr--) {
        ch = *(u8 *)src;
        sc = (s8)ch;
        if (sc >= 'A' && sc <= 'Z') {
            *(u8 *)src = (u8)(ch + 0x20);
        }
        *dst = *(u8 *)src;
        ch = *(u8 *)src;
        sc = (s8)ch;
        if (sc == 0) {
            break;
        }
        sc = (s8)ch;
        *(s32 *)(arg0 + 0x2C) = sc + *(s32 *)(arg0 + 0x2C) * 0x25;
        dst = dst + 1;
        src = src + 1;
    }

    fn_8020C6D4(arg1, arg0 + 0x40);
    arg0[0x29] = lbl_803672E8;
    *(u16 *)(arg0 + 0x32) = 0;
    *(u16 *)(arg0 + 0x30) = flags;
    *(u32 *)(arg0 + 0x34) = (u32)(OSGetTime() / (*(u32 *)0x800000F8 >> 2));
    *(u8 **)(arg0 + 0x6C) = arg0;

    p = arg1;
    ext = lbl_8026B330 + 0x221;
    goto find1_chk;
find1:
    sc = (s8)sc;
    if (sc == '.') {
        goto cmp1;
    }
    p += 1;
find1_chk:
    sc = (s8)*p;
    if (sc != 0) {
        goto find1;
    }
    goto cmp1;
cmp1:
cmp1_body:
    ch = *(u8 *)ext;
    sc = (s8)sc;
    if (sc == (s8)ch) {
        ch = *(u8 *)++ext;
        p += 1;
        if ((s8)ch != 0) {
            sc = (s8)*p;
            goto cmp1_body;
        }
        if ((s8)*p != 0) {
            sc = (s8)*p;
            goto cmp1_body;
        }
        match = 1;
        goto done1;
    }
    sc = (s8)*p;
    if (sc != 0) {
        goto cmp1_body;
    }
    match = 0;
done1:
    if (match) {
        *(u16 *)(arg0 + 0x30) |= 0xC00;
    }

    p = arg1;
    ext = lbl_8026B330 + 0x226;
    goto find2_chk;
find2:
    sc = (s8)sc;
    if (sc == '.') {
        goto cmp2;
    }
    p += 1;
find2_chk:
    sc = (s8)*p;
    if (sc != 0) {
        goto find2;
    }
    goto cmp2;
cmp2:
cmp2_body:
    ch = *(u8 *)ext;
    sc = (s8)sc;
    if (sc == (s8)ch) {
        ch = *(u8 *)++ext;
        p += 1;
        if ((s8)ch != 0) {
            sc = (s8)*p;
            goto cmp2_body;
        }
        if ((s8)*p != 0) {
            sc = (s8)*p;
            goto cmp2_body;
        }
        match = 1;
        goto done2;
    }
    sc = (s8)*p;
    if (sc != 0) {
        goto cmp2_body;
    }
    match = 0;
done2:
    if (match) {
        *(u16 *)(arg0 + 0x30) |= 0x800;
    }

    p = arg1;
    ext = lbl_8026B330 + 0x22B;
    goto find3_chk;
find3:
    sc = (s8)sc;
    if (sc == '.') {
        goto cmp3;
    }
    p += 1;
find3_chk:
    sc = (s8)*p;
    if (sc != 0) {
        goto find3;
    }
    goto cmp3;
cmp3:
cmp3_body:
    ch = *(u8 *)ext;
    sc = (s8)sc;
    if (sc == (s8)ch) {
        ch = *(u8 *)++ext;
        p += 1;
        if ((s8)ch != 0) {
            sc = (s8)*p;
            goto cmp3_body;
        }
        if ((s8)*p != 0) {
            sc = (s8)*p;
            goto cmp3_body;
        }
        match = 1;
        goto done3;
    }
    sc = (s8)*p;
    if (sc != 0) {
        goto cmp3_body;
    }
    match = 0;
done3:
    if (match) {
        *(u16 *)(arg0 + 0x30) |= 0x400;
    }

    *(s32 *)(arg0 + 0x3C) = (*(s32 *)(arg0 + 0x74) + 0x1F) & ~0x1F;

    if (*(volatile u16 *)(arg0 + 0x30) & 0x410) {
        *(u32 *)(arg0 + 0x38) = fn_800C45B8(-*(s32 *)(arg0 + 0x3C), lbl_8026B330 + 5, 0);
    } else {
        if (*(volatile u16 *)(arg0 + 0x30) & 2) {
            drive = (s8)arg0[0x29];
            size = *(s32 *)(arg0 + 0x3C) + 1;
            if (fn_800C44F4(drive) < (u32)size) {
                res = 0;
            } else {
                off = (s32)strlen(arg1) - 0xF;
                if (off < 0) {
                    off = 0;
                }
                res = fn_800C4604(drive, size, arg1 + off, size);
            }
            *(u32 *)(arg0 + 0x38) = res;
            *(u8 *)(*(u8 **)(arg0 + 0x3C) + *(u32 *)(arg0 + 0x38)) = 0;
        } else {
            size = *(s32 *)(arg0 + 0x3C);
            drive = (s8)arg0[0x29];
            if (fn_800C44F4(drive) < (u32)size) {
                res = 0;
            } else {
                off = (s32)strlen(arg1) - 0xF;
                if (off < 0) {
                    off = 0;
                }
                res = fn_800C4604(drive, size, arg1 + off, size);
            }
            *(u32 *)(arg0 + 0x38) = res;
        }
        if (*(u32 *)(arg0 + 0x38) == 0) {
            *(u32 *)(arg0 + 0x38) = fn_8005E594((s8)arg0[0x29], *(s32 *)(arg0 + 0x3C), arg1);
        }
    }

    if ((*(u16 *)(arg0 + 0x30) & 0x300) == 0x300) {
        fn_8020CB38(arg0 + 0x40, *(u32 *)(arg0 + 0x38), *(s32 *)(arg0 + 0x3C), 0, (void *)fn_8005E070, 3);
    } else {
        fn_8020CB38(arg0 + 0x40, *(u32 *)(arg0 + 0x38), *(s32 *)(arg0 + 0x3C), 0, (void *)fn_8005E070, 2);
    }
}
u32 fn_8005E55C(void) {
    s64 OSGetTime(void);
    return OSGetTime() / (*(u32 *)0x800000F8 >> 2);
}

#pragma dont_inline on
void *fn_8005E594(s32 arg0, u32 arg1, char *arg2) {
    void DebugPrint(char *, ...);
    void fn_8005BC8C();
    u32 fn_800C44F4(s32);
    void *fn_800C4604(s32, u32, char *, u32);
    void fn_800C4384(void);
    unsigned long strlen(const char *);
    extern u8 lbl_8026B330[];
    void *result;
    char *a2;
    u32 a1;
    s32 ofs;

    result = (void *)arg0;
    a2 = arg2;
    a1 = arg1;
    DebugPrint((char *)(lbl_8026B330 + 0x230));
    fn_8005BC8C((s8)arg0);
    if (fn_800C44F4((s32)result) < a1) {
        result = NULL;
    } else {
        ofs = strlen(a2) - 0xF;
        if (ofs < 0) {
            ofs = 0;
        }
        result = fn_800C4604((s32)result, a1, a2 + ofs, a1);
    }
    if (result == 0) {
        fn_800C4384();
    }
    return result;
}
#pragma dont_inline reset
void fn_8005E644(void *arg0) {
    void fn_8005F12C(void *, void *);
    void fn_8005F230(void *);
    s32 fn_8005F378(void *);
    s32 fn_8005F3B8(void *);
    void *fn_8005F410(void *);
    void Model_SetAlpha(void *, u8);
    void Model_SetColor(void *, u8, u8, u8);
    void *GActor_GetNodeTable(void *);
    void fn_8006D378(void *);
    void fn_801505A8(void *, void *);
    void PSMTXCopy(void *, void *);

    u32 color;
    void *p;
    void *q;
    void *r;
    s32 n;
    s32 depth;
    s32 dist;
    s32 b;
    u8 ub;
    u8 alpha;
    u8 t;
    s32 off;
    void *great;
    s32 i;
    void *info;
    void *grand;
    void *child;

    child = *(void **)((u8 *)arg0 + 0x8C);
    if (child == NULL) {
        return;
    }

    grand = *(void **)((u8 *)child + 0x8C);
    if (grand != NULL) {
        great = *(void **)((u8 *)grand + 0x8C);
        if (great != NULL) {
            fn_8005E644(great);
            fn_8005F12C(grand, great);
            fn_8005F230(great);
        }

        if (child != NULL && grand != NULL) {
            info = GActor_GetNodeTable(child);
            i = 0;
            off = i;
            while (i < *(s32 *)((u8 *)info + 8)) {
                PSMTXCopy((u8 *)*(void **)((u8 *)child + 0x60) + off,
                            (u8 *)*(void **)((u8 *)grand + 0x60) + off);
                off += 0x30;
                i += 1;
            }
            if (*(u32 *)((u8 *)child + 0x64) != 0) {
                i = 0;
                off = i;
                while (i < *(s32 *)((u8 *)info + 8)) {
                    PSMTXCopy((u8 *)*(void **)((u8 *)child + 0x64) + off,
                                (u8 *)*(void **)((u8 *)grand + 0x64) + off);
                    off += 0x30;
                    i += 1;
                }
                fn_8006D378(grand);
            }
            PSMTXCopy((u8 *)child + 0x10, (u8 *)grand + 0x10);
            if (*(u32 *)((u8 *)child + 0x54) != 0) {
                fn_801505A8(child, grand);
            }
            *(f32 *)((u8 *)grand + 0x58) = *(f32 *)((u8 *)child + 0x58);
        }

        info = fn_8005F410(grand);
        if (info != NULL) {
            n = fn_8005F378(grand);
            b = fn_8005F3B8(grand);
            ub = ((u8 *)info)[0xB];
            color = *(u32 *)((u8 *)info + 0x88);
            alpha = (u8)(((ub - (ub * b) / (n + 1)) * ((u8 *)&color)[3]) / 255);
            ((u8 *)&color)[3] = alpha;
            Model_SetAlpha(grand, alpha);
            Model_SetColor(grand, ((u8 *)&color)[0], ((u8 *)&color)[1], ((u8 *)&color)[2]);
        }
    }

    if (arg0 != NULL && child != NULL) {
        p = arg0;
        goto loop_2;
    loop_1:
        if (*(u32 *)((u8 *)p + 0x40) != 0U) {
            goto block_7;
        }
        p = *(void **)((u8 *)p + 4);
    loop_2:
        if (p != NULL) {
            goto loop_1;
        }
        i = 0;
        goto block_8;
    block_7:
        i = *(s32 *)((u8 *)p + 0x40);
    block_8:
        info = (void *)i;

        i = 0;
        off = i;
        while (i < *(s32 *)((u8 *)info + 8)) {
            PSMTXCopy((u8 *)*(void **)((u8 *)arg0 + 0x60) + off,
                        (u8 *)*(void **)((u8 *)child + 0x60) + off);
            off += 0x30;
            i += 1;
        }
        if (*(u32 *)((u8 *)arg0 + 0x64) != 0) {
            i = 0;
            off = i;
            while (i < *(s32 *)((u8 *)info + 8)) {
                PSMTXCopy((u8 *)*(void **)((u8 *)arg0 + 0x64) + off,
                            (u8 *)*(void **)((u8 *)child + 0x64) + off);
                off += 0x30;
                i += 1;
            }
            fn_8006D378(child);
        }
        PSMTXCopy((u8 *)arg0 + 0x10, (u8 *)child + 0x10);
        if (*(u32 *)((u8 *)arg0 + 0x54) != 0) {
            fn_801505A8(arg0, child);
        }
        *(f32 *)((u8 *)child + 0x58) = *(f32 *)((u8 *)arg0 + 0x58);
    }

    p = child;
    for (;;) {
        q = *(void **)((u8 *)p + 4);
        if (q != NULL && *(u32 *)((u8 *)q + 0x8C) != 0) {
            p = q;
        } else {
            break;
        }
    }

    if (p != NULL) {
        q = child;
        for (;;) {
            r = *(void **)((u8 *)q + 4);
            if (r != NULL && *(u32 *)((u8 *)r + 0x8C) != 0) {
                q = r;
            } else {
                break;
            }
        }
        depth = 0;
        for (;;) {
            q = *(void **)((u8 *)q + 0x8C);
            if (q != NULL) {
                depth += 1;
            } else {
                break;
            }
        }

        r = child;
        for (;;) {
            q = *(void **)((u8 *)r + 4);
            if (q != NULL && *(u32 *)((u8 *)r + 0x8C) != 0) {
                r = q;
            } else {
                break;
            }
        }
        dist = 0;
        if (r != child) {
            for (;;) {
                r = *(void **)((u8 *)r + 0x8C);
                if (r != NULL) {
                    dist += 1;
                } else {
                    dist = 0;
                    break;
                }
            }
        }

        ub = ((u8 *)p)[0xB];
        color = *(u32 *)((u8 *)p + 0x88);
        t = (u8)(((ub - (ub * dist) / (depth + 1)) * ((u8 *)&color)[3]) / 255);
        ((u8 *)&color)[3] = t;
        ((u8 *)child)[0xB] = t;
        if (t != 0xFF) {
            *(u32 *)child |= 0x20;
        } else {
            *(u32 *)child &= ~0x20;
        }
        ((u8 *)child)[8] = ((u8 *)&color)[0];
        ((u8 *)child)[9] = ((u8 *)&color)[1];
        ((u8 *)child)[0xA] = ((u8 *)&color)[2];
    }
}

s32 fn_8005EA14(arg0)
u32 arg0;
{
    void fn_800616A0(void *);
    u32 r30, r29, r28, r27, r26, r25, r24, r23;

    if (arg0 != 0) {
        r30 = *(u32 *)(arg0 + 0x8C);
        if (r30 != 0) {
            r29 = *(u32 *)(r30 + 0x8C);
            if (r29 != 0) {
                r28 = *(u32 *)(r29 + 0x8C);
                if (r28 != 0) {
                    r27 = *(u32 *)(r28 + 0x8C);
                    if (r27 != 0) {
                        r26 = *(u32 *)(r27 + 0x8C);
                        if (r26 != 0) {
                            r25 = *(u32 *)(r26 + 0x8C);
                            if (r25 != 0) {
                                r24 = *(u32 *)(r25 + 0x8C);
                                if (r24 != 0) {
                                    r23 = *(u32 *)(r24 + 0x8C);
                                    if (r23 != 0) {
                                        fn_8005EA14(*(u32 *)(r23 + 0x8C));
                                        if (*(u32 *)r23 & 0xC00000) {
                                            fn_800616A0((void *)r23);
                                        }
                                    }
                                    if (*(u32 *)r24 & 0xC00000) {
                                        fn_800616A0((void *)r24);
                                    }
                                }
                                if (*(u32 *)r25 & 0xC00000) {
                                    fn_800616A0((void *)r25);
                                }
                            }
                            if (*(u32 *)r26 & 0xC00000) {
                                fn_800616A0((void *)r26);
                            }
                        }
                        if (*(u32 *)r27 & 0xC00000) {
                            fn_800616A0((void *)r27);
                        }
                    }
                    if (*(u32 *)r28 & 0xC00000) {
                        fn_800616A0((void *)r28);
                    }
                }
                if (*(u32 *)r29 & 0xC00000) {
                    fn_800616A0((void *)r29);
                }
            }
            if (*(u32 *)r30 & 0xC00000) {
                fn_800616A0((void *)r30);
            }
        }
        if (*(u32 *)arg0 & 0xC00000) {
            fn_800616A0((void *)arg0);
        }
    }
}

#pragma use_lmw_stmw reset

#pragma dont_inline reset
void fn_8005EB5C(u8 *dst, u8 *src)
{
  u8 b;
  u8 a;

  a = src[0];
  b = src[1];
  dst[0x88] = a;
  a = src[2];
  dst[0x89] = b;
  b = src[3];
  dst[0x8A] = a;
  dst[0x8B] = b;
}

void fn_8005EB80(s32 arg0, s32 arg1) {
    M2C_UNK fn_8005EA14();
    void fn_8005EC18(void *, s32, s32);
    if (arg0 != 0) {
        fn_8005EA14();
        fn_8005EC18((void *)arg0, arg1, 0x40800000);
    }
}

void fn_8005EBCC(s32 arg0, s32 arg1) {
    void fn_8005EC18(void *, s32, s32);
    if (arg0 != 0) {
        fn_8005EA14();
        fn_8005EC18((void *)arg0, arg1, 0x40400000);
    }
}

#pragma global_optimizer off
void fn_8005EC18(void *arg0, s32 arg1, s32 arg2) {
    void *fn_800C4638(s32, void *, s32);
    void Game_Assert(void *, s32, void *);
    void fn_800618E4(void *);
    void GActor_Finalize(void *);
    void *GActor_GetNodeTable(void *);
    void PSMTXCopy(void *, void *);
    void fn_8006D378(void *);
    void fn_801505A8(void *, void *);
    void *GActor_Create(void);
    void fn_8005F12C(void *, void *);
    s32 fn_8005F230(void *);
    void *fn_8005F410(void *);
    s32 fn_8005F378(void *);
    s32 fn_8005F3B8(void *);
    void Model_SetAlpha(void *, u8);
    void Model_SetColor(void *, u8, u8, u8);
    extern char lbl_8026B590[];

    u8 spC[4];
    u8 sp8[4];
    void *node;
    void *self;
    s32 count;
    s32 flags;
    s32 i;
    s32 off;
    void *anim;

    self = arg0;
    count = arg1;
    flags = arg2;

    if (count - 1 < 0) {
        return;
    }

    node = fn_800C4638(0xA0, lbl_8026B590 + 0x27, 0);
    if (node == 0) {
        Game_Assert(lbl_8026B590 + 0x28, 0x46, lbl_8026B590 + 0x31);
    }
    fn_800618E4(node);
    *(u32 *)node |= 4;
    *(u32 *)node |= *(u32 *)self | flags;
    *(void **)((u8 *)node + 4) = self;
    *(u32 *)((u8 *)node + 0x90) = *(u32 *)((u8 *)self + 0x90);
    *(void **)((u8 *)self + 0x8C) = node;
    GActor_Finalize(node);
    ((u8 *)node)[0x87] = ((u8 *)self)[0x87];

    if (self != 0 && node != 0) {
        void *p = self;
        goto anim_check;
    anim_load:
        anim = *(void **)((u8 *)p + 0x40);
        if (anim != 0) {

        } else {
            p = *(void **)((u8 *)p + 4);
            goto anim_check;
        }
        goto anim_found;
    anim_check:
        if (p != 0) {
            goto anim_load;
        }
        anim = 0;
    anim_found:
        i = 0;
        off = i;
        goto copy60_test;
    copy60_body:
        PSMTXCopy((u8 *)*(void **)((u8 *)self + 0x60) + off, (u8 *)*(void **)((u8 *)node + 0x60) + off);
        off += 0x30;
        i += 1;
    copy60_test:
        if (i < *(s32 *)((u8 *)anim + 8)) {
            goto copy60_body;
        }
        if (*(u32 *)((u8 *)self + 0x64) != 0) {
            i = 0;
            off = i;
            goto copy64_test;
        copy64_body:
            PSMTXCopy((u8 *)*(void **)((u8 *)self + 0x64) + off, (u8 *)*(void **)((u8 *)node + 0x64) + off);
            off += 0x30;
            i += 1;
        copy64_test:
            if (i < *(s32 *)((u8 *)anim + 8)) {
                goto copy64_body;
            }
        }
        fn_8006D378(node);
        PSMTXCopy((u8 *)self + 0x10, (u8 *)node + 0x10);
        if (*(u32 *)((u8 *)self + 0x54) != 0) {
            fn_801505A8(self, node);
        }
        *(f32 *)((u8 *)node + 0x58) = *(f32 *)((u8 *)self + 0x58);
    }

    self = (void *)(count - 1);
    if ((s32)self - 1 < 0) {
        goto root_walk;
    }

    count = (s32)fn_800C4638(0xA0, lbl_8026B590 + 0x27, 0);
    if ((void *)count == 0) {
        Game_Assert(lbl_8026B590 + 0x28, 0x46, lbl_8026B590 + 0x31);
    }
    fn_800618E4((void *)count);
    *(u32 *)count |= 4;
    *(u32 *)count |= *(u32 *)node | flags;
    *(void **)((u8 *)count + 4) = node;
    *(u32 *)((u8 *)count + 0x90) = *(u32 *)((u8 *)node + 0x90);
    *(void **)((u8 *)node + 0x8C) = (void *)count;
    GActor_Finalize((void *)count);
    ((u8 *)count)[0x87] = ((u8 *)node)[0x87];

    if (node != 0 && (void *)count != 0) {
        off = 0;
        i = (s32)GActor_GetNodeTable(node);
        anim = (void *)off;
        goto copy60b_test;
    copy60b_body:
        PSMTXCopy((u8 *)*(void **)((u8 *)node + 0x60) + (s32)anim, (u8 *)*(void **)((u8 *)count + 0x60) + (s32)anim);
        anim = (void *)((s32)anim + 0x30);
        off += 1;
    copy60b_test:
        if (off < *(s32 *)((u8 *)i + 8)) {
            goto copy60b_body;
        }
        if (*(u32 *)((u8 *)node + 0x64) != 0) {
            off = 0;
            anim = (void *)off;
            goto copy64b_test;
        copy64b_body:
            PSMTXCopy((u8 *)*(void **)((u8 *)node + 0x64) + (s32)anim, (u8 *)*(void **)((u8 *)count + 0x64) + (s32)anim);
            anim = (void *)((s32)anim + 0x30);
            off += 1;
        copy64b_test:
            if (off < *(s32 *)((u8 *)i + 8)) {
                goto copy64b_body;
            }
        }
        fn_8006D378((void *)count);
        PSMTXCopy((u8 *)node + 0x10, (u8 *)count + 0x10);
        if (*(u32 *)((u8 *)node + 0x54) != 0) {
            fn_801505A8(node, (void *)count);
        }
        *(f32 *)((u8 *)count + 0x58) = *(f32 *)((u8 *)node + 0x58);
    }

    i = (s32)self - 1;
    if (i - 1 >= 0) {
        off = (s32)GActor_Create();
        *(u32 *)off |= *(u32 *)count | flags;
        *(void **)((u8 *)off + 4) = (void *)count;
        *(u32 *)((u8 *)off + 0x90) = *(u32 *)((u8 *)count + 0x90);
        *(void **)((u8 *)count + 0x8C) = (void *)off;
        GActor_Finalize((void *)off);
        ((u8 *)off)[0x87] = ((u8 *)count)[0x87];
        fn_8005F12C((void *)count, (void *)off);
        fn_8005EC18((void *)off, i - 1, flags);
        fn_8005F230((void *)off);
    }

    self = fn_8005F410((void *)count);
    if (self != 0) {
        flags = fn_8005F378((void *)count);
        i = fn_8005F3B8((void *)count);
        {
            u8 t;
            u8 alpha;
            *(u32 *)sp8 = *(u32 *)((u8 *)self + 0x88);
            t = ((u8 *)self)[0xB];
            alpha = (u8)(((t - (t * i) / (flags + 1)) * sp8[3]) / 255);
            sp8[3] = alpha;
            Model_SetAlpha((void *)count, alpha);
            Model_SetColor((void *)count, sp8[0], sp8[1], sp8[2]);
        }
    }

root_walk:
    {
        void *root = node;
        void *w;
        void *n;
    root_loop:
        n = *(void **)((u8 *)root + 4);
        if (n != 0 && *(u32 *)((u8 *)n + 0x8C) != 0) {
            root = n;
            goto root_loop;
        }
        if (root == 0) {
            return;
        }

        w = node;
    count_parent:
        n = *(void **)((u8 *)w + 4);
        if (n != 0 && *(u32 *)((u8 *)n + 0x8C) != 0) {
            w = n;
            goto count_parent;
        }
        i = 0;
    count_child:
        w = *(void **)((u8 *)w + 0x8C);
        if (w != 0) {
            i += 1;
            goto count_child;
        }

        w = node;
    depth_parent:
        n = *(void **)((u8 *)w + 4);
        if (n != 0 && *(u32 *)((u8 *)n + 0x8C) != 0) {
            w = n;
            goto depth_parent;
        }
        off = 0;
    depth_loop:
        if (w != node) {
            goto depth_step;
        }
        goto depth_done;
    depth_step:
        w = *(void **)((u8 *)w + 0x8C);
        if (w != 0) {
            off += 1;
            goto depth_loop;
        }
        off = 0;
    depth_done:

        *(u32 *)spC = *(u32 *)((u8 *)root + 0x88);
        {
            u8 t = ((u8 *)root)[0xB];
            u8 alpha = (u8)(((t - (t * off) / (i + 1)) * spC[3]) / 255);
            spC[3] = alpha;
            ((u8 *)node)[0xB] = alpha;
            if (alpha != 0xFF) {
                *(u32 *)node |= 0x20;
            } else {
                *(u32 *)node &= ~0x20;
            }
        }
        ((u8 *)node)[8] = spC[0];
        ((u8 *)node)[9] = spC[1];
        ((u8 *)node)[10] = spC[2];
    }
}

void fn_8005F12C(void *arg0, void *arg1) {
    void PSMTXCopy(void *, void *);
    void fn_8006D378(void *);
    void fn_801505A8(void *, void *);

    u8 *source;
    u8 *dest;
    u8 *node;
    u8 *info;
    s32 i;
    s32 offset;

    source = (u8 *)arg0;
    dest = (u8 *)arg1;

    if (source == NULL || dest == NULL) {
        return;
    }

    node = source;

    while (node != NULL) {
        info = *(u8 **)(node + 0x40);
        if (info != NULL) {
            break;
        }
        node = *(u8 **)(node + 4);
    }

    if (node == NULL) {
        info = NULL;
    }

    i = 0;
    offset = 0;

    while (i < *(s32 *)(info + 8)) {
        PSMTXCopy(
            *(u8 **)(source + 0x60) + offset,
            *(u8 **)(dest + 0x60) + offset
        );
        offset += 0x30;
        i++;
    }

    if (*(void **)(source + 0x64) != NULL) {
        i = 0;
        offset = 0;

        while (i < *(s32 *)(info + 8)) {
            PSMTXCopy(
                *(u8 **)(source + 0x64) + offset,
                *(u8 **)(dest + 0x64) + offset
            );
            offset += 0x30;
            i++;
        }
    }

    fn_8006D378(dest);

    PSMTXCopy(source + 0x10, dest + 0x10);

    if (*(void **)(source + 0x54) != NULL) {
        fn_801505A8(source, dest);
    }

    *(f32 *)(dest + 0x58) = *(f32 *)(source + 0x58);
}

#pragma global_optimizer on
void fn_8005F230(void *node) {
#pragma cplusplus on
    struct Chain {
        static void *root(void *p) {
            for (;;) {
                void *n=M2C_FIELD(p,void **,4);
                if(n && M2C_FIELD(n,u32 *,0x8C)) p=n;
                else return p;
            }
        }
        static s32 count(void *p) {
            s32 i;
            p=root(p);
            i=0;
            for (;;) {
                p=M2C_FIELD(p,void **,0x8C);
                if(p) i++; else break;
            }
            return i;
        }
        static s32 index(void *node, void *p) {
            s32 i;
            i=0;
            for (;;) {
                if(p==node) return i;
                p=M2C_FIELD(p,void **,0x8C);
                if(p) i++; else break;
            }
            return 0;
        }
    };
    u8 color[4];
    void *root=Chain::root(node);
    if(root) {
        s32 count=Chain::count(node);
        s32 index=Chain::index(node,Chain::root(node));
        s32 alpha; s32 t;
        *(u32 *)color=M2C_FIELD(root,u32 *,0x88);
        t=M2C_FIELD(root,u8 *,0xB);
        alpha=((t-(t*index)/(count+1))*color[3])/255;
        color[3]=alpha;
        M2C_FIELD(node,u8 *,0xB)=alpha;
        if((u8)alpha!=255) M2C_FIELD(node,u32 *,0)|=0x20;
        else M2C_FIELD(node,u32 *,0)&=~0x20;
        M2C_FIELD(node,u8 *,8)=color[0];
        M2C_FIELD(node,u8 *,9)=color[1];
        M2C_FIELD(node,u8 *,10)=color[2];
    }
#pragma cplusplus reset
}

s32 fn_8005F378(void *node) {
    void *child;
    unsigned int count;

loop:
    child = *(void **)((u8 *)node + 4);
    if (child != NULL && *(u32 *)((u8 *)child + 0x8C) != 0U) {
        node = child;
        goto loop;
    }
    count = 0;
    for (;;) {
        node = *(void **)((u8 *)node + 0x8C);
        if (node == NULL) {
            break;
        }
        count += 1;
    }
    return count;
}

s32 fn_8005F3B8(void *arg0) {
    void *var_r4;
    void *temp_r0;
    void *temp_r5;
    unsigned int var_r5;

    var_r4 = arg0;
loop_1:
    temp_r5 = M2C_FIELD(var_r4, void **, 4);
    if ((temp_r5 != NULL) && (M2C_FIELD(temp_r5, u32 *, 0x8C) != 0U)) {
        var_r4 = temp_r5;
        goto loop_1;
    }
    var_r5 = 0;
loop_5:
    if (var_r4 == arg0) {
        return var_r5;
    }
    temp_r0 = M2C_FIELD(var_r4, void **, 0x8C);
    if (temp_r0 != NULL) {
        var_r4 = temp_r0;
        var_r5 += 1;
        goto loop_5;
    }
    return 0;
}

#pragma peephole off
void *fn_8005F410(void *arg0)
{
    void *next;

    for (;;) {
        next = *(void **)((u8 *)arg0 + 4);
        if (next == NULL) {
            return arg0;
        }
        if (*(void **)((u8 *)next + 0x8c) == NULL) {
            return arg0;
        }
        arg0 = next;
    }
}
#pragma peephole on
void fn_8005F434(void *arg0, void *arg1, void *arg2) {
    void *fn_8006D910(void *, void *);
    void fn_8006D8E8(void *);
    void *saved;
    void *temp;

    saved = *(void **)((u8 *)arg0 + 0x4C);
    temp = fn_8006D910(arg1, arg2);
    if (temp != *(void **)((u8 *)arg0 + 0x4C)) {
        *(void **)((u8 *)arg0 + 0x4C) = temp;
    }
    if (saved != NULL) {
        fn_8006D8E8(saved);
    }
}

void GActor_LoadTpl(void *arg0, void *arg1) {
    void *fn_8006D910(void *, void *);
    void fn_8006D8E8(void *);
    void *saved;
    void *temp;

    saved = *(void **)((u8 *)arg0 + 0x4C);
    temp = fn_8006D910(arg1, 0);
    if (temp != *(void **)((u8 *)arg0 + 0x4C)) {
        *(void **)((u8 *)arg0 + 0x4C) = temp;
    }
    if (saved != NULL) {
        fn_8006D8E8(saved);
    }
}

extern u32 fn_80065E88(s32, s32);
extern void fn_80065E68(void);
void GActor_LoadG(void *arg0, s32 arg1) {
    void *fn_80065E88(s32, s32);
    void fn_80065E68(void *);
    void *saved;
    void *temp;

    saved = *(void **)((u8 *)arg0 + 0x40);
    temp = fn_80065E88(arg1, 0);
    if (temp != *(void **)((u8 *)arg0 + 0x40)) {
        *(void **)((u8 *)arg0 + 0x40) = temp;
    }
    if (saved != NULL) {
        fn_80065E68(saved);
    }
}

void GActor_LoadGs(void *arg0, void *arg1) {
    void *fn_8006CCBC(void *, void *);
    void fn_8006CC6C(void *);
    void *saved;
    void *temp;

    saved = *(void **)((u8 *)arg0 + 0x48);
    temp = fn_8006CCBC(arg1, 0);
    if (temp != *(void **)((u8 *)arg0 + 0x48)) {
        *(void **)((u8 *)arg0 + 0x48) = temp;
    }
    if (saved != NULL) {
        fn_8006CC6C(saved);
    }
}

void fn_8005F5B4(void *arg0, s32 arg1) {
    void *fn_80063954(s32, s32);
    void fn_80063934(void *);
    void *fn_80065634(void ***, s32);
#pragma cplusplus on
    struct Lookup {
        static u8 *find(u8 *p) {
            while (p) {
                u8 *a = *(u8 **)(p + 0x44);
                if (a) return a;
                p = *(u8 **)(p + 4);
            }
            return 0;
        }
    };
    void *old;
    u8 *self;
    void *neu;
    u8 *anim;
    u8 *entry;
    s32 i;
    u8 *r5;
    u8 *r6;
    f32 frame;

    old = *(void **)((u8 *)arg0 + 0x44);
    self = (u8 *)arg0;
    neu = fn_80063954(arg1, 0);
    if (neu != *(void **)(self + 0x44)) {
        *(void **)(self + 0x44) = neu;
        frame = (f32)*(s32 *)((u8 *)neu + 0x14);
        anim = Lookup::find(self);
        if (anim) {
            *(u32 *)self &= ~0x10;
            if (frame < 0.0f || frame > (f32)*(s32 *)(anim + 0x18)) {
                frame = (f32)*(s32 *)(anim + 0x18);
                *(u32 *)self |= 0x10;
            }
            if (frame <= (f32)*(s32 *)(anim + 0x14))
                frame = (f32)*(s32 *)(anim + 0x14);
            *(u16 *)(self + 0x7C) = 0xFFFF;
            *(u16 *)(self + 0x7E) = 0xFFFF;
            *(u16 *)(self + 0x80) = 0xFFFF;
            *(u16 *)(self + 0x82) = 0xFFFF;
            entry = (u8 *)fn_80065634((void ***)anim, (s32)frame);
            if (entry) {
                r5 = entry;
                r6 = self;
                for (i = 0; i < *(u16 *)(entry + 2); i++) {
                    *(u16 *)(r6 + 0x7C) = *(u16 *)(r5 + 4);
                    r5 += 2;
                    r6 += 2;
                }
            }
            *(f32 *)(self + 0x58) = frame;
        }
    }
    if (old) {
        fn_80063934(old);
    }
#pragma cplusplus reset
}

void fn_8005F780(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x84) = arg1;
}

void fn_8005F788(u8 *arg0, s32 arg1, u8 arg2) {
    arg0[0x86] = arg1;
    arg0[0x85] = (u8)(1 << arg1);
    if (arg2 != 0) {
        arg0[0x85] |= 0xF0;
    }
}

void Model_SetAlpha(void *arg0, u8 arg1) {
    M2C_FIELD(arg0, u8 *, 0xB) = arg1;
    if (arg1 != 0xFF) {
        M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg0, s32 *, 0) | 0x20);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg0, s32 *, 0) & 0xFFFFFFDF);
}

void Model_SetColor(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    M2C_FIELD(arg0, s8 *, 8) = arg1;
    M2C_FIELD(arg0, s8 *, 9) = arg2;
    M2C_FIELD(arg0, s8 *, 0xA) = arg3;
}

#pragma global_optimizer off
#pragma opt_strength_reduction off
