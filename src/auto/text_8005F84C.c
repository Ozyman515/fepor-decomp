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

extern void *lbl_803672F4;

/* Return whether the named file is ready: load-done (0x2000) or absent (0x8000). */

void fn_8005C8D8();

/* Forever drain the FileCache async work ring, sleeping when empty. */

/* After DVD load: optionally start ARAM DMA (flag 8), else expand buffer / spawn archive children and mark load-done. */

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset
/* Return the byte size of the named file-cache entry, or 0 if absent. */

/* Return 1 if a file-cache entry with this name exists, else 0. */

#pragma no_register_save_helpers on
#pragma use_lmw_stmw on

/* Mark the named file-cache entry as relocated (flags |= 0x4000). */

#pragma opt_common_subs off

#pragma opt_common_subs reset

#pragma global_optimizer off

#pragma global_optimizer on
void FileCache_Release(u8 *);
/* Look up a file-cache entry by path/name and release it. */

#pragma global_optimizer off

#pragma use_lmw_stmw on

#pragma use_lmw_stmw reset

#pragma global_optimizer reset
/* Drop one ref on a file-cache entry; when the count hits zero, cancel loads, wait, and free it. */

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer on

#pragma use_lmw_stmw on
#pragma global_optimizer off

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma global_optimizer reset
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw on

#pragma dont_inline on

#pragma dont_inline reset

#pragma use_lmw_stmw reset

#pragma dont_inline reset

#pragma global_optimizer off

#pragma global_optimizer on

#pragma peephole off

#pragma peephole on

extern u32 fn_80065E88(s32, s32);
extern void fn_80065E68(void);

#pragma global_optimizer off
#pragma opt_strength_reduction off

#pragma opt_strength_reduction reset
#pragma global_optimizer reset
static inline u32 GetListField44(void *p) {
    while (p != NULL) {
        u32 v = *(u32 *)((u8 *)p + 0x44);
        if (v != 0) {
            return v;
        }
        p = *(void **)((u8 *)p + 4);
    }
    return 0;
}

void fn_8005F84C(void *arg0) {
    extern void *fn_80065484(u32);

    fn_80065484(GetListField44(arg0));
}

void fn_8005F894(void *arg0, s32 arg1) {
    void fn_80065484(u32, s32, s32);

    fn_80065484(GetListField44(arg0), -1, arg1);
}

void fn_8005F8E4(void *arg0) {
    extern void *fn_800653C8(u32);

    fn_800653C8(GetListField44(arg0));
}

u16 fn_8005F92C(void *arg0,u16 *arg1){ s32 i; u16 v; u16 *p; for(i=0;i<4;i++){v=((u16*)arg0)[0x3e+i]; if(v!=0xffff){for(p=arg1;*p!=0xffff;p++){if(*p==v)return v;}}} return 0xffff;}

#pragma global_optimizer off
s32 Pad_IsButton(u8 *arg0, u32 arg1) {
    u32 key;
    u32 v;

    key = arg1 & 0xFFFF;
    v = *(u16 *)(arg0 + 0x7C);
    if (v == key) {
        return 1;
    }
    v = *(u16 *)(arg0 + 0x7E);
    if (v == key) {
        return 1;
    }
    v = *(u16 *)(arg0 + 0x80);
    if (v == key) {
        return 1;
    }
    v = *(u16 *)(arg0 + 0x82);
    if (v == key) {
        return 1;
    }
    return 0;
}
#pragma global_optimizer reset
s32 fn_8005FA14(void *arg0, s32 arg1) {
    M2C_UNK fn_8005FA94(void *, s32);
    extern char lbl_8026B590[];

    if (arg0 == NULL) {
        Game_Assert(lbl_8026B590 + 0x28, 0x2D8, lbl_8026B590 + 0x5D);
    }
    if (M2C_FIELD(arg0, void **, 0x74) == NULL) {
        return 0;
    }
    fn_8005FA94(M2C_FIELD(arg0, void **, 0x74), arg1);
    M2C_FIELD(arg0, void **, 0x74) = NULL;
    M2C_FIELD(arg0, f32 *, 0x78) = 1.0f;
    return 1;
}

#pragma inline_depth(8)
#pragma scheduling off
void fn_8005FA94(void *arg0, s32 arg1)
{
    void fn_800616A0(void *);

    if (arg0 != NULL) {
        if (*(void **)((u8 *)arg0 + 0x74) != NULL) {
            fn_8005FA94(*(void **)((u8 *)arg0 + 0x74), arg1);
            *(u32 *)((u8 *)arg0 + 0x74) = 0;
        }
        if ((u8)arg1 == 0) {
            *(u32 *)((u8 *)arg0 + 0x44) = 0;
        }
        fn_800616A0(arg0);
    }
}
#pragma inline_max_size(48)
#pragma scheduling on
#pragma auto_inline off
void fn_8005FC74(u8 *self, void *arg1, s32 arg2) {
 void *fn_800C4638(s32,void*,s32);
 void fn_800618E4(void*);
 void PSMTXCopy(void*,void*);
 void *fn_80065634(void***,s32);
 extern char lbl_8026B590[];
 s32 count,i,last;
 u8 *node,*walk,*anim,*entry,*src,*dst;
 void *next;
 f32 frame;
 if(!self) Game_Assert(lbl_8026B590+0x28,0x2B2,lbl_8026B590+0x84);
 count=1;walk=self;
 while((walk=*(u8**)(walk+0x74))!=0) count++;
 if(count==4) fn_8005FA14(self,arg2);
 node=(u8*)fn_800C4638(0xA0,lbl_8026B590+0x27,0);
 if(!node) Game_Assert(lbl_8026B590+0x28,0x46,lbl_8026B590+0x31);
 fn_800618E4(node);
 *(u32*)node|=4;
 next=*(void**)(self+0x74);
 *(void**)(self+0x74)=node;
 *(void**)(node+0x74)=next;
 *(f32*)(node+0x58)=*(f32*)(self+0x58);
 *(f32*)(node+0x5C)=*(f32*)(self+0x5C);
 *(f32*)(node+0x78)=*(f32*)(self+0x78);
 *(u32*)node|=*(u32*)self&0x340;
 *(u32*)node&=~0x10;
 *(void**)(node+4)=self;
 *(void**)(node+0x44)=*(void**)(self+0x44);
 PSMTXCopy(self+0x10,node+0x10);
 frame=0.0f;
 *(f32*)(self+0x78)=frame;
 *(void**)(self+0x44)=arg1;
 anim=GActor_FindAnimation(self);
 if(anim) {
 *(u32*)self&=~0x10;
 last=*(s32*)(anim+0x18);
 if(0.0f>(f32)last) {
 *(u32*)self|=0x10;
 frame=(f32)last;
 }
 if(frame<=(f32)*(s32*)(anim+0x14)) frame=(f32)*(s32*)(anim+0x14);
 *(u16*)(self+0x7C)=65535;*(u16*)(self+0x7E)=65535;
 *(u16*)(self+0x80)=65535;*(u16*)(self+0x82)=65535;
 entry=(u8*)fn_80065634((void***)anim,(s32)frame);
 if(entry) {
 src=entry;dst=self;
 for(i=0;i<*(u16*)(entry+2);i++) {
 *(u16*)(dst+0x7C)=*(u16*)(src+4);src+=2;dst+=2;
 }
 }
 *(f32*)(self+0x58)=frame;
 }
}
#pragma auto_inline reset
#pragma inline_max_size reset
void fn_8005FEE8(void *arg0, f32 frame) {
void *fn_80065634(void ***,s32);
extern f32 lbl_803691C8;

#pragma cplusplus on
struct Lookup { static u8 *find(u8 *p) { while(p) {u8 *a=*(u8**)(p+0x44); if(a) return a; p=*(u8**)(p+4);} return 0;} };
u8 *self=(u8*)arg0;

u8 *anim;
u8 *entry;
u8 *src;
u8 *dst;
s32 i;
anim=Lookup::find(self);
if(anim) {
*(u32*)self &= ~0x10;
if(frame<0.0f || frame>(f32)*(s32*)(anim+0x18)) {
frame=(f32)*(s32*)(anim+0x18);
*(u32*)self |= 0x10;
}
if(frame <= (f32)*(s32*)(anim+0x14)) frame=(f32)*(s32*)(anim+0x14);
*(u16*)(self+0x7C)=0xFFFF;
*(u16*)(self+0x7E)=0xFFFF;
*(u16*)(self+0x80)=0xFFFF;
*(u16*)(self+0x82)=0xFFFF;
entry=(u8*)fn_80065634((void***)anim,(s32)frame);
if(entry) {
src=entry; dst=self;
for(i=0;i<*(u16*)(entry+2);i++) {
*(u16*)(dst+0x7C)=*(u16*)(src+4);
src+=2;dst+=2;
}
}
*(f32*)(self+0x58)=frame;
}
#pragma cplusplus reset
}

#pragma use_lmw_stmw on
void fn_80060060(void *arg0) {
    s32 fn_80064FC4(void *, void *, void *);
    s32 fn_800651FC(void *, void *, f32, f32);
    s32 fn_8006555C(void *, s32, s32);
    extern f64 lbl_803691D0;
    extern f32 lbl_803691D8;

    u16 sp8[4];
    void *node;
    void *var_r3;
    f32 lo;
    f32 hi;
    f32 t;
    f32 cur;
    s32 end;
    s32 start;
    s32 flag;
    u8 found;
    f32 delta;

    delta = *(f32 *)((u8 *)arg0 + 0x5C);
    var_r3 = arg0;
    goto loop_2;
loop_1:
    node = *(void **)((u8 *)var_r3 + 0x44);
    if (node != NULL) {
        goto block_7;
    }
    var_r3 = *(void **)((u8 *)var_r3 + 4);
loop_2:
    if (var_r3 != NULL) {
        goto loop_1;
    }
    node = NULL;
block_7:

    if (node == NULL) {
        return;
    }

    *(u32 *)arg0 &= ~0x10;
    if (*(u32 *)arg0 & 0x40) {
        return;
    }

    if (*(void **)((u8 *)arg0 + 0x74) != NULL) {
        fn_80060060(*(void **)((u8 *)arg0 + 0x74));
    }

    lo = *(f32 *)((u8 *)arg0 + 0x58);
    hi = lo + delta;
    *(f32 *)((u8 *)arg0 + 0x58) = hi;

    if (*(u32 *)arg0 & 0x80) {
        found = 0;
        if (*(u16 *)((u8 *)arg0 + 0x7C) == 4) {
            found = 1;
        } else if (*(u16 *)((u8 *)arg0 + 0x7E) == 4) {
            found = 1;
        } else if (*(u16 *)((u8 *)arg0 + 0x80) == 4) {
            found = 1;
        } else if (*(u16 *)((u8 *)arg0 + 4 + 0x7E) == 4) {
            found = 1;
        }
        if (found) {
            var_r3 = arg0;
            goto loop_2b;
        loop_1b:
            node = *(void **)((u8 *)var_r3 + 0x44);
            if (node != NULL) {
                goto block_7b;
            }
            var_r3 = *(void **)((u8 *)var_r3 + 4);
        loop_2b:
            if (var_r3 != NULL) {
                goto loop_1b;
            }
            node = NULL;
        block_7b:
            *(f32 *)((u8 *)arg0 + 0x58) = (f32)fn_8006555C(node, (s32)hi, 3);
        }
    }

    if (lo > hi) {
        t = lo;
        lo = hi;
        hi = t;
    }

    fn_800651FC(node, (u8 *)arg0 + 0x7C, lo, hi);

    end = *(s32 *)((u8 *)node + 0x18);
    cur = *(f32 *)((u8 *)arg0 + 0x58);
    if (cur >= (f32)end || cur <= (f32)*(s32 *)((u8 *)node + 0x14)) {
        flag = 0;
        switch (*(u32 *)arg0 & 0x300) {
        case 0x200:
            break;
        case 0x100:
            flag = 1;
            break;
        default:
            if (*(s32 *)((u8 *)node + 0x10) != 0) {
                flag = 1;
            }
            break;
        }

        if (flag) {
            if (cur >= (f32)end) {
                start = *(s32 *)((u8 *)node + 0x14);
                *(f32 *)((u8 *)arg0 + 0x58) = *(f32 *)((u8 *)arg0 + 0x58) - (f32)(end - start);
                hi = *(f32 *)((u8 *)arg0 + 0x58);
                lo = (f32)(start - 1);
            } else {
                start = *(s32 *)((u8 *)node + 0x14);
                if (cur <= (f32)start) {
                    *(f32 *)((u8 *)arg0 + 0x58) = *(f32 *)((u8 *)arg0 + 0x58) + (f32)(end - start);
                    lo = *(f32 *)((u8 *)arg0 + 0x58) - lbl_803691D8;
                    hi = (f32)*(s32 *)((u8 *)node + 0x18);
                }
            }
            if (lo > hi) {
                t = lo;
                lo = hi;
                hi = t;
            }
            if (fn_800651FC(node, sp8, lo, hi) > 0) {
                fn_80064FC4((u8 *)arg0 + 0x7C, sp8, (u8 *)arg0 + 0x7C);
            }
        } else {
            if (cur >= (f32)end) {
                *(f32 *)((u8 *)arg0 + 0x58) = (f32)end;
            } else {
                start = *(s32 *)((u8 *)node + 0x14);
                if (cur <= (f32)start) {
                    *(f32 *)((u8 *)arg0 + 0x58) = (f32)start;
                }
            }
        }
        *(u32 *)arg0 |= 0x10;
    }
}
#pragma use_lmw_stmw reset

s32 fn_80060440(void *arg0) {
    s32 var_r4;
    void *var_r3;

    var_r3 = arg0;
    var_r4 = 1;
    goto loop_2;
loop_1:
    var_r4 += 1;
loop_2:
    var_r3 = M2C_FIELD(var_r3, void **, 0x74);
    if (var_r3 != NULL) {
        goto loop_1;
    }
    return var_r4;
}

f32 fn_80060460(void *arg0) {
    return M2C_FIELD(arg0, f32 *, 0x78);
}

f32 fn_80060468(void *arg0) {
    return M2C_FIELD(arg0, f32 *, 0x58);
}

u32 fn_80060470(void *arg0) {
    void *current = arg0;

    while (current != NULL) {
        u32 temp = *(u32 *)((char *)current + 0x64);
        if (temp != 0U) {
            return temp;
        }
        current = *(void **)((char *)current + 4);
    }
    return 0U;
}

u32 fn_8006049C(void *arg0) {
    while (arg0 != NULL) {
        if (M2C_FIELD(arg0, u32 *, 0x60) != 0U) {
            return M2C_FIELD(arg0, u32 *, 0x60);
        }
        arg0 = M2C_FIELD(arg0, void **, 4);
    }
    return 0U;
}

u32 fn_800604C8(void *arg0) {
    void *current = arg0;
    while (current != NULL) {
        u32 value = M2C_FIELD(current, u32 *, 0x70);
        if (value != 0U) {
            return value;
        }
        current = M2C_FIELD(current, void **, 4);
    }
    return 0U;
}

u32 fn_800604F4(void *arg0) {
    void *current = arg0;

    while (current != NULL) {
        u32 temp = *(u32 *)((char *)current + 0x6C);
        if (temp != 0U) {
            return temp;
        }
        current = *(void **)((char *)current + 4);
    }
    return 0U;
}

u32 fn_80060520(void *arg0) {
    s32 Camera_Get(void);
    u32 var_r31;
    u32 value;
    void *var_r30;

    var_r30 = arg0;
    while (var_r30 != NULL) {
        if (M2C_FIELD(var_r30, u32 *, 0x68) != 0U) {
            var_r31 = M2C_FIELD(var_r30, u32 *, 0x68);
            goto found;
        }
        var_r30 = M2C_FIELD(var_r30, void **, 4);
    }
    return 0U;
found:
    if (((u8 *)Camera_Get())[3] & 1) {
        value = FindUnk48(var_r30);
        var_r31 += (((M2C_FIELD(M2C_FIELD(value, void **, 0x48), s16 *, 0xA) * 12) + 31) & ~31) / 2 * 2;
    }
    return var_r31;
}

u32 fn_800605E0(void *arg0) {
    void *current = arg0;
    u32 value;

    while (current != NULL) {
        value = M2C_FIELD(current, u32 *, 0x50);
        if (value != 0U) {
            return value;
        }
        current = M2C_FIELD(current, void **, 4);
    }
    
    return 0U;
}

u32 fn_8006060C(void *arg0) {
    void *current = arg0;
    u32 value;

    while (current != NULL) {
        value = M2C_FIELD(current, u32 *, 0x4C);
        if (value != 0U) {
            return value;
        }
        current = M2C_FIELD(current, void **, 4);
    }
    
    return 0U;
}

u32 fn_80060638(void *arg0) {
    void *current = arg0;
    
    while (current != NULL) {
        u32 temp = M2C_FIELD(current, u32 *, 0x48);
        if (temp != 0U) {
            return temp;
        }
        current = M2C_FIELD(current, void **, 4);
    }
    return 0U;
}

u32 fn_80060664(void *arg0) {
    void *current = arg0;

    while (current != NULL) {
        u32 temp = *(u32 *)((char *)current + 0x44);
        if (temp != 0U) {
            return temp;
        }
        current = *(void **)((char *)current + 4);
    }
    return 0U;
}

u32 GActor_GetNodeTable(void *arg0) {
    void *current = arg0;

    while (current != NULL) {
        u32 temp = *(u32 *)((char *)current + 0x40);
        if (temp != 0U) {
            return temp;
        }
        current = *(void **)((char *)current + 4);
    }
    return 0U;
}

void fn_800606BC(void *arg0) {
    void fn_80061A08(void *);
    void fn_80065AF8(s32, void *, void *, void *);
    void fn_8006CAD4(void *);
    void fn_8006CF60(void *);
    void fn_8006D378(void *);
    void fn_801506AC(void *);
    void Game_Assert(void *, s32, void *);
    void PSMTXCopy(void *, void *);
    extern char lbl_8026B590[];
#pragma cplusplus on
    struct Lookup {
        static void *model(void *p) {
            for (; p; p = M2C_FIELD(p, void **, 4)) {
                void *v = M2C_FIELD(p, void **, 0x40);
                if (v) return v;
            }
            return 0;
        }
        static void *mesh(void *p) {
            for (; p; p = M2C_FIELD(p, void **, 4)) {
                void *v = M2C_FIELD(p, void **, 0x48);
                if (v) return v;
            }
            return 0;
        }
        static void *geometry(void *p) {
            for (; p; p = M2C_FIELD(p, void **, 4)) {
                void *v = M2C_FIELD(p, void **, 0x50);
                if (v) return v;
            }
            return 0;
        }
        static void *matrices(void *p) {
            for (; p; p = M2C_FIELD(p, void **, 4)) {
                void *v = M2C_FIELD(p, void **, 0x60);
                if (v) return v;
            }
            return 0;
        }
        static void *matrices2(void *p) {
            for (; p; p = M2C_FIELD(p, void **, 4)) {
                void *v = M2C_FIELD(p, void **, 0x64);
                if (v) return v;
            }
            return 0;
        }
    };
    u8 *src;
    s32 i;
    u8 *dst;
    void *model;
    void *mesh;
    void *geometry;
    void *matrices;
    void *matrices2;
    void *p;
    if (!arg0) Game_Assert(lbl_8026B590 + 0x28, 0x16C, lbl_8026B590 + 0xAB);
    if (!arg0) Game_Assert(lbl_8026B590 + 0x28, 0x120, lbl_8026B590 + 0xAB);
    if (M2C_FIELD(arg0, void **, 0x60)) {
        model = Lookup::model(arg0);
        for (p = arg0; p; p = M2C_FIELD(p, void **, 4)) if (M2C_FIELD(p, void **, 0x44)) break;
        mesh = Lookup::mesh(arg0);
        geometry = Lookup::geometry(arg0);
        matrices = Lookup::matrices(arg0);
        matrices2 = Lookup::matrices2(arg0);
        src = M2C_FIELD(model, u8 **, 0xC);
        dst = (u8 *)matrices;
        for (i = 0; i < M2C_FIELD(model, s32 *, 8); dst += 0x30, i++, src += 0xF4)
            PSMTXCopy(src + 0xBC, dst);
        fn_80061A08(arg0);
        fn_80065AF8((s32)arg0, M2C_FIELD(model, void **, 0xC), matrices, matrices2);
        if (geometry) fn_8006CF60(arg0);
        if (mesh && M2C_FIELD(mesh, void **, 0x48)) fn_8006D378(arg0);
        if (M2C_FIELD(arg0, void **, 0x54)) fn_801506AC(arg0);
    }
    fn_8006CAD4(arg0);
#pragma cplusplus reset
}

void fn_800608AC(void *arg0) {
    void fn_80061A08(void *);
    void fn_80065AF8(s32, void *, void *, void *);
    void Game_Assert(void *, s32, void *);
    void PSMTXCopy(void *, void *);
#pragma cplusplus on
    struct Lookup {
        static void *model(void *p) {
            for (;p;p=M2C_FIELD(p,void **,4)) {
                void *v=M2C_FIELD(p,void **,0x40);
                if(v) return v;
            }
            return 0;
        }
        static void *matrices(void *p) {
            for (;p;p=M2C_FIELD(p,void **,4)) {
                void *v=M2C_FIELD(p,void **,0x60);
                if(v) return v;
            }
            return 0;
        }
    };
    u8 *dst;
    void *model;
    void *matrices;
    s32 i;
    u8 *src;
    void *p;
    if (!arg0) Game_Assert(lbl_8026B590 + 0x28, 0x150, lbl_8026B590 + 0xAB);
    if (!M2C_FIELD(arg0,void **,0x60)) return;
    model=Lookup::model(arg0);
    for(p=arg0;p;p=M2C_FIELD(p,void **,4)) if(M2C_FIELD(p,void **,0x44)) break;
    for(p=arg0;p;p=M2C_FIELD(p,void **,4)) if(M2C_FIELD(p,void **,0x48)) break;
    matrices=Lookup::matrices(arg0);
    src=M2C_FIELD(model,u8 **,0xC);
    dst=(u8 *)matrices;
    for(i=0;i<M2C_FIELD(model,s32 *,8);dst+=0x30,i++,src+=0xF4) PSMTXCopy(src+0xBC,dst);
    fn_80061A08(arg0);
    fn_80065AF8((s32)arg0,M2C_FIELD(model,void **,0xC),matrices,0);
#pragma cplusplus reset
}

void fn_800609DC(void *arg0) {
    void fn_80061A08(void *);
    void fn_80065AF8(s32, void *, void *, void *);
    void fn_8006CF60(void *);
    void fn_8006D378(void *);
    void fn_801506AC(void *);
    void Game_Assert(void *, s32, void *);
    void PSMTXCopy(void *, void *);
    extern char lbl_8026B590[];
#pragma cplusplus on
    struct Lookup {
        static void *model(void *p) {
            for (; p; p = M2C_FIELD(p, void **, 4)) {
                void *v = M2C_FIELD(p, void **, 0x40);
                if (v) return v;
            }
            return 0;
        }
        static void *mesh(void *p) {
            for (; p; p = M2C_FIELD(p, void **, 4)) {
                void *v = M2C_FIELD(p, void **, 0x48);
                if (v) return v;
            }
            return 0;
        }
        static void *geometry(void *p) {
            for (; p; p = M2C_FIELD(p, void **, 4)) {
                void *v = M2C_FIELD(p, void **, 0x50);
                if (v) return v;
            }
            return 0;
        }
        static void *matrices(void *p) {
            for (; p; p = M2C_FIELD(p, void **, 4)) {
                void *v = M2C_FIELD(p, void **, 0x60);
                if (v) return v;
            }
            return 0;
        }
        static void *matrices2(void *p) {
            for (; p; p = M2C_FIELD(p, void **, 4)) {
                void *v = M2C_FIELD(p, void **, 0x64);
                if (v) return v;
            }
            return 0;
        }
    };
    u8 *dst;
    void *model;
    void *mesh;
    void *geometry;
    void *matrices;
    void *matrices2;
    s32 i;
    u8 *src;
    void *p;
    if (!arg0) Game_Assert(lbl_8026B590 + 0x28, 0x120, lbl_8026B590 + 0xAB);
    if (!M2C_FIELD(arg0, void **, 0x60)) return;
    model = Lookup::model(arg0);
    for (p = arg0; p; p = M2C_FIELD(p, void **, 4)) if (M2C_FIELD(p, void **, 0x44)) break;
    mesh = Lookup::mesh(arg0);
    geometry = Lookup::geometry(arg0);
    matrices = Lookup::matrices(arg0);
    matrices2 = Lookup::matrices2(arg0);
    src = M2C_FIELD(model, u8 **, 0xC);
    dst = (u8 *)matrices;
    for (i = 0; i < M2C_FIELD(model, s32 *, 8); dst += 0x30, i++, src += 0xF4)
        PSMTXCopy(src + 0xBC, dst);
    fn_80061A08(arg0);
    fn_80065AF8((s32)arg0, M2C_FIELD(model, void **, 0xC), matrices, matrices2);
    if (geometry) fn_8006CF60(arg0);
    if (mesh && M2C_FIELD(mesh, void **, 0x48)) fn_8006D378(arg0);
    if (M2C_FIELD(arg0, void **, 0x54)) fn_801506AC(arg0);
#pragma cplusplus reset
}

f32 fn_80060BA4(void *actor, s32 index)
{
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXScale(void *, f32, f32, f32);
    void PSMTXCopy(void *, void *);
    void PSMTXTrans(void *, f32, f32, f32);
    void PSMTXConcat(void *, void *, void *);
    void QUATMtx(void *, void *);
    void fn_802029C4(void *, void *, void *);
    int Game_Assert(void *, int, void *);
    extern char lbl_8026B590[];
    extern f32 lbl_803691C8;
    extern f32 lbl_803691C4;
    f32 Vec_Length(void *);
    extern f32 lbl_803691D8;
    u8 result[0x30];
    u8 rot3[0x30];
    u8 rot2[0x30];
    u8 rot1[0x30];
    u8 trans[0x30];
    u8 scale[0x30];
    f32 vec[3];
    void *matrices;
    void *bone;
    void *p;
    void *model;
    unsigned long order;
    f32 zero;

    if (actor == NULL) {
        Game_Assert(lbl_8026B590 + 0x28, 0x102, lbl_8026B590 + 0xab);
    }

    p = actor;
    while (p != NULL) {
        matrices = *(void **)((u8 *)p + 0x60);
        if (matrices == NULL) {
            p = *(void **)((u8 *)p + 4);
        } else {
            goto got_matrices;
        }
    }
    matrices = NULL;
got_matrices:

    p = actor;
    while (p != NULL) {
        model = *(void **)((u8 *)p + 0x40);
        if (model == NULL) {
            p = *(void **)((u8 *)p + 4);
        } else {
            goto got_model;
        }
    }
    model = NULL;
got_model:

    order = *(u32 *)((u8 *)actor + 0xc);

    switch (order) {
    case 1:
        PSMTXRotRad(rot1, 0x58, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x1c));
        PSMTXRotRad(rot2, 0x59, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x20));
        PSMTXRotRad(rot3, 0x5a, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x24));
        break;
    case 2:
        PSMTXRotRad(rot1, 0x59, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x20));
        PSMTXRotRad(rot2, 0x5a, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x24));
        PSMTXRotRad(rot3, 0x58, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x1c));
        break;
    case 3:
        PSMTXRotRad(rot1, 0x5a, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x24));
        PSMTXRotRad(rot2, 0x58, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x1c));
        PSMTXRotRad(rot3, 0x59, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x20));
        break;
    case 4:
        PSMTXRotRad(rot1, 0x58, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x1c));
        PSMTXRotRad(rot2, 0x5a, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x24));
        PSMTXRotRad(rot3, 0x59, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x20));
        break;
    case 5:
        PSMTXRotRad(rot1, 0x59, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x20));
        PSMTXRotRad(rot2, 0x58, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x1c));
        PSMTXRotRad(rot3, 0x5a, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x24));
        break;
    case 6:
        PSMTXRotRad(rot1, 0x5a, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x24));
        PSMTXRotRad(rot2, 0x59, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x20));
        PSMTXRotRad(rot3, 0x58, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x1c));
        break;
    case 8:
        PSMTXScale(scale, *(f32 *)((u8 *)actor + 0x28), *(f32 *)((u8 *)actor + 0x2c),
                   *(f32 *)((u8 *)actor + 0x30));
        PSMTXTrans(trans, *(f32 *)((u8 *)actor + 0x10), *(f32 *)((u8 *)actor + 0x14),
                   *(f32 *)((u8 *)actor + 0x18));
        QUATMtx((u8 *)actor + 0x10, rot1);
        PSMTXConcat(rot1, scale, result);
        PSMTXConcat(rot1, result, result);
        PSMTXConcat(trans, result, result);
        goto after_xform;
    case 7:
        PSMTXCopy((u8 *)actor + 0x10, result);
        goto after_xform;
    default:
        Game_Assert(lbl_8026B590, 0xb8, lbl_8026B590 + 8);
        break;
    }

    PSMTXScale(scale, *(f32 *)((u8 *)actor + 0x28), *(f32 *)((u8 *)actor + 0x2c),
               *(f32 *)((u8 *)actor + 0x30));
    PSMTXTrans(trans, *(f32 *)((u8 *)actor + 0x10), *(f32 *)((u8 *)actor + 0x14),
               *(f32 *)((u8 *)actor + 0x18));
    PSMTXConcat(rot1, scale, result);
    PSMTXConcat(rot2, result, result);
    PSMTXConcat(rot3, result, result);
    PSMTXConcat(trans, result, result);

after_xform:
    PSMTXConcat(result, (u8 *)matrices + index * 0x30, result);
    *(f32 *)(result+12) = lbl_803691C8;
    *(f32 *)(result+28) = lbl_803691C8;
    *(f32 *)(result+44) = lbl_803691C8;
    vec[0]=lbl_803691D8; vec[1]=lbl_803691C8; vec[2]=lbl_803691C8;
    fn_802029C4(result,vec,vec);
    return Vec_Length(vec);
}

#pragma use_lmw_stmw on
#pragma opt_common_subs off
void fn_80060F70(void *actor, s32 index, f32 *out)
{
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXScale(void *, f32, f32, f32);
    void PSMTXTrans(void *, f32, f32, f32);
    void PSMTXCopy(void *, void *);
    void PSMTXConcat(void *, void *, void *);
    void QUATMtx(void *, void *);
    void fn_802029C4(void *, void *, void *);
    int Game_Assert(void *, int, void *);
    extern char lbl_8026B590[];
    extern f32 lbl_803691C4;
    extern f32 lbl_803691C8;
    u8 result[0x30];
    u8 rot3[0x30];
    u8 rot2[0x30];
    u8 rot1[0x30];
    u8 trans[0x30];
    u8 scale[0x30];
    void *matrices;
    void *bone;
    void *p;
    void *model;
    u32 order;
    f32 zero;

    if (actor == NULL) {
        Game_Assert(lbl_8026B590 + 0x28, 0xe3, lbl_8026B590 + 0xab);
    }
    if (index < 0) {
        return;
    }

    p = actor;
    while (p != NULL) {
        matrices = *(void **)((u8 *)p + 0x60);
        if (matrices == NULL) {
            p = *(void **)((u8 *)p + 4);
        } else {
            goto got_matrices;
        }
    }
    matrices = NULL;
got_matrices:

    p = actor;
    while (p != NULL) {
        model = *(void **)((u8 *)p + 0x40);
        if (model == NULL) {
            p = *(void **)((u8 *)p + 4);
        } else {
            goto got_model;
        }
    }
    model = NULL;
got_model:

    order = *(u32 *)((u8 *)actor + 0xc);
    bone = (u8 *)*(void **)((u8 *)model + 0xc) + index * 0xf4;

    switch (order) {
    case 1:
        PSMTXRotRad(rot1, 0x58, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x1c));
        PSMTXRotRad(rot2, 0x59, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x20));
        PSMTXRotRad(rot3, 0x5a, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x24));
        break;
    case 2:
        PSMTXRotRad(rot1, 0x59, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x20));
        PSMTXRotRad(rot2, 0x5a, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x24));
        PSMTXRotRad(rot3, 0x58, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x1c));
        break;
    case 3:
        PSMTXRotRad(rot1, 0x5a, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x24));
        PSMTXRotRad(rot2, 0x58, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x1c));
        PSMTXRotRad(rot3, 0x59, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x20));
        break;
    case 4:
        PSMTXRotRad(rot1, 0x58, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x1c));
        PSMTXRotRad(rot2, 0x5a, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x24));
        PSMTXRotRad(rot3, 0x59, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x20));
        break;
    case 5:
        PSMTXRotRad(rot1, 0x59, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x20));
        PSMTXRotRad(rot2, 0x58, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x1c));
        PSMTXRotRad(rot3, 0x5a, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x24));
        break;
    case 6:
        PSMTXRotRad(rot1, 0x5a, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x24));
        PSMTXRotRad(rot2, 0x59, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x20));
        PSMTXRotRad(rot3, 0x58, lbl_803691C4 * *(f32 *)((u8 *)actor + 0x1c));
        break;
    case 8:
        PSMTXScale(scale, *(f32 *)((u8 *)actor + 0x28), *(f32 *)((u8 *)actor + 0x2c),
                   *(f32 *)((u8 *)actor + 0x30));
        PSMTXTrans(trans, *(f32 *)((u8 *)actor + 0x10), *(f32 *)((u8 *)actor + 0x14),
                   *(f32 *)((u8 *)actor + 0x18));
        QUATMtx((u8 *)actor + 0x10, rot1);
        PSMTXConcat(rot1, scale, result);
        PSMTXConcat(rot1, result, result);
        PSMTXConcat(trans, result, result);
        goto after_xform;
    case 7:
        PSMTXCopy((u8 *)actor + 0x10, result);
        goto after_xform;
    default:
        Game_Assert(lbl_8026B590, 0xb8, lbl_8026B590 + 8);
        break;
    }

    PSMTXScale(scale, *(f32 *)((u8 *)actor + 0x28), *(f32 *)((u8 *)actor + 0x2c),
               *(f32 *)((u8 *)actor + 0x30));
    PSMTXTrans(trans, *(f32 *)((u8 *)actor + 0x10), *(f32 *)((u8 *)actor + 0x14),
               *(f32 *)((u8 *)actor + 0x18));
    PSMTXConcat(rot1, scale, result);
    PSMTXConcat(rot2, result, result);
    PSMTXConcat(rot3, result, result);
    PSMTXConcat(trans, result, result);

after_xform:
    PSMTXConcat(result, (u8 *)matrices + index * 0x30, result);

    if (*(u32 *)((u8 *)bone + 0xc) & 0x80) {
        out[0] = *(f32 *)((u8 *)bone + 0x70);
        out[1] = *(f32 *)((u8 *)bone + 0x74);
        out[2] = *(f32 *)((u8 *)bone + 0x78);
    } else {
        zero = lbl_803691C8;
        out[0] = zero;
        out[1] = zero;
        out[2] = zero;
    }
    fn_802029C4(result, out, out);
}
#pragma opt_common_subs reset
static inline void *GActor_FindNode_Model(void *p) {
    for (; p; p = M2C_FIELD(p, void **, 4)) {
        void *v = M2C_FIELD(p, void **, 0x40);
        if (v) return v;
    }
    return 0;
}

s32 GActor_FindNode(void *arg0, void *name) {
    u8 Str_MatchUnderscoreTag(void *, void *);
    void *node;
    void *entry;
    s32 i;

    node = GActor_FindNode_Model(arg0);
    entry = *(void **)((u8 *)node + 0xC);
    for (i = 0; i < *(s32 *)((u8 *)node + 8); i++, entry = (void *)((u8 *)entry + 0xF4)) {
        if (*(u32 *)((u8 *)entry + 0xC) & 0x80000000U) {
            if (Str_MatchUnderscoreTag(*(void **)((u8 *)entry + 0xF0), name) != 0) {
                return i;
            }
        }
    }
    return -1;
}

void GActor_Finalize(void *arg0)
{
    void Game_Assert(void *, s32, void *);
    void fn_800C4588(void *);
    void *fn_800C4638(s32, void *, s32);
    void PSMTXCopy(void *, void *);
    void DCFlushRange(void *, u32);
    void fn_80150FEC(void *);

    extern char lbl_8026B590[];

    u8 *self;
    u8 *cur;
    u8 *model;
    u8 *mesh;
    u8 *geometry;
    u8 *scaleNode;
    u8 *source;
    u8 *buffer;
    s32 i;
    s32 offset;
    s32 size;
    s32 count;

    self = (u8 *)arg0;

    if (self == 0) {
        Game_Assert(
            lbl_8026B590 + 0x28,
            0x93,
            lbl_8026B590 + 0xAB
        );
    }

    fn_800C4588(*(void **)(self + 0x60));
    *(void *volatile *)(self + 0x60) = 0;
    *(void *volatile *)(self + 0x60) = 0;

    fn_800C4588(*(void **)(self + 0x64));
    *(void *volatile *)(self + 0x64) = 0;
    *(void *volatile *)(self + 0x64) = 0;

    fn_800C4588(*(void **)(self + 0x68));
    *(void *volatile *)(self + 0x68) = 0;
    *(void *volatile *)(self + 0x68) = 0;

    fn_800C4588(*(void **)(self + 0x6C));
    *(void *volatile *)(self + 0x6C) = 0;
    *(void *volatile *)(self + 0x6C) = 0;

    cur = self;
    goto model_test;

model_loop:
    model = *(u8 **)(cur + 0x40);

    if (model != 0) {
        goto mesh_start;
    }

    cur = *(u8 **)(cur + 4);

model_test:
    if (cur != 0) {
        goto model_loop;
    }

    model = 0;

mesh_start:
    cur = self;
    goto mesh_test;

mesh_loop:
    mesh = *(u8 **)(cur + 0x48);

    if (mesh != 0) {
        goto geometry_start;
    }

    cur = *(u8 **)(cur + 4);

mesh_test:
    if (cur != 0) {
        goto mesh_loop;
    }

    mesh = 0;

geometry_start:
    cur = self;
    goto geometry_test;

geometry_loop:
    geometry = *(u8 **)(cur + 0x50);

    if (geometry != 0) {
        goto scale_start;
    }

    cur = *(u8 **)(cur + 4);

geometry_test:
    if (cur != 0) {
        goto geometry_loop;
    }

    geometry = 0;

scale_start:
    cur = self;
    goto scale_test;

scale_loop:
    scaleNode = *(u8 **)(cur + 0x44);

    if (scaleNode != 0) {
        goto allocate_start;
    }

    cur = *(u8 **)(cur + 4);

scale_test:
    if (cur != 0) {
        goto scale_loop;
    }

    scaleNode = 0;

allocate_start:
    if (model != 0) {
        count = *(s32 *)(model + 8);

        *(void **)(self + 0x60) = fn_800C4638(
            count * 0x30,
            lbl_8026B590 + 0x27,
            0
        );

        i = 0;
        offset = 0;
        source = *(u8 **)(model + 0xC);

        goto copy_test;

copy_loop:
        buffer = *(u8 **)(self + 0x60);

        PSMTXCopy(
            source + 0xBC,
            buffer + offset
        );

        offset += 0x30;
        i++;
        source += 0xF4;

copy_test:
        if (i < *(s32 *)(model + 8)) {
            goto copy_loop;
        }
    }

    if (mesh != 0) {
        cur = *(u8 **)(mesh + 0x48);

        if (cur != 0) {
            size = *(s16 *)(cur + 0xA) * 12;
            size = (size + 0x1F) & ~0x1F;

            *(void **)(self + 0x64) = fn_800C4638(
                *(s32 *)(model + 8) * 0x30,
                lbl_8026B590 + 0x27,
                0
            );

            size *= 2;

            *(void **)(self + 0x68) = fn_800C4638(
                size,
                lbl_8026B590 + 0x27,
                0
            );

            DCFlushRange(
                *(void **)(self + 0x64),
                *(s32 *)(model + 8) * 0x30
            );

            DCFlushRange(
                *(void **)(self + 0x68),
                size
            );
        }
    }

    if (geometry != 0) {
        if (*(u32 *)(geometry + 0xC) & 1) {
            offset = *(u16 *)(mesh + 0x4C) * 6;

            *(void **)(self + 0x6C) = fn_800C4638(
                offset + *(u16 *)(mesh + 0x4E) * 3,
                lbl_8026B590 + 0x27,
                0
            );

            *(void **)(self + 0x70) =
                *(u8 **)(self + 0x6C) + offset;
        }
    }

    if (scaleNode != 0) {
        *(f32 *)(self + 0x58) =
            (f32)*(s32 *)(scaleNode + 0x14);
    }

    fn_80150FEC(self);
}

void fn_800616A0(void *arg0) {
    void Game_Assert(void *, s32, void *);
    void fn_800C4588(void *);
    void fn_80065E68(void *);
    void fn_8006CC6C(void *);
    void fn_8006D8E8(void *);
    void fn_80063934(void *);
    void fn_80150F38(void *);
    extern char lbl_8026B590[];
    void *parent;
    void *child;

    if (arg0 == NULL) {
        Game_Assert(lbl_8026B590 + 0x28, 0x56, lbl_8026B590 + 0xAB);
    }
    parent = *(void **)((u8 *)arg0 + 4);
    if (parent != NULL) {
        if (*(void **)((u8 *)parent + 0x74) == arg0) {
            *(void **)((u8 *)parent + 0x74) = NULL;
        }
        if (*(void **)((u8 *)parent + 0x8C) == arg0) {
            *(void **)((u8 *)parent + 0x8C) = NULL;
        }
    }
    child = *(void **)((u8 *)arg0 + 0x74);
    if (child != NULL) {
        fn_800616A0(child);
        *(void **)((u8 *)arg0 + 0x74) = NULL;
    }
    child = *(void **)((u8 *)arg0 + 0x8C);
    if (child != NULL) {
        fn_800616A0(child);
        *(void **)((u8 *)arg0 + 0x8C) = NULL;
    }
    fn_800C4588(*(void **)((u8 *)arg0 + 0x64));
    *(void **)((u8 *)arg0 + 0x64) = NULL;
    *(void **)((u8 *)arg0 + 0x64) = NULL;
    fn_800C4588(*(void **)((u8 *)arg0 + 0x60));
    *(void **)((u8 *)arg0 + 0x60) = NULL;
    *(void **)((u8 *)arg0 + 0x60) = NULL;
    fn_800C4588(*(void **)((u8 *)arg0 + 0x68));
    *(void **)((u8 *)arg0 + 0x68) = NULL;
    *(void **)((u8 *)arg0 + 0x68) = NULL;
    fn_800C4588(*(void **)((u8 *)arg0 + 0x6C));
    *(void **)((u8 *)arg0 + 0x6C) = NULL;
    *(void **)((u8 *)arg0 + 0x6C) = NULL;
    if (*(void **)((u8 *)arg0 + 0x40) != NULL) {
        fn_80065E68(*(void **)((u8 *)arg0 + 0x40));
    }
    if (*(void **)((u8 *)arg0 + 0x48) != NULL) {
        fn_8006CC6C(*(void **)((u8 *)arg0 + 0x48));
    }
    if (*(void **)((u8 *)arg0 + 0x4C) != NULL) {
        fn_8006D8E8(*(void **)((u8 *)arg0 + 0x4C));
    }
    if (*(void **)((u8 *)arg0 + 0x44) != NULL) {
        fn_80063934(*(void **)((u8 *)arg0 + 0x44));
    }
    fn_80150F38(arg0);
    *(void **)((u8 *)arg0 + 0x74) = NULL;
    *(void **)((u8 *)arg0 + 0x8C) = NULL;
    *(void **)((u8 *)arg0 + 0x64) = NULL;
    *(void **)((u8 *)arg0 + 0x60) = NULL;
    *(void **)((u8 *)arg0 + 0x68) = NULL;
    *(void **)((u8 *)arg0 + 0x6C) = NULL;
    *(void **)((u8 *)arg0 + 0x40) = NULL;
    *(void **)((u8 *)arg0 + 0x48) = NULL;
    *(void **)((u8 *)arg0 + 0x4C) = NULL;
    *(void **)((u8 *)arg0 + 0x44) = NULL;
    *(void **)((u8 *)arg0 + 0x54) = NULL;
    if (*(u32 *)arg0 & 4) {
        fn_800C4588(arg0);
    }
}

s32 fn_80061824(s32 arg0) {
    extern char lbl_8026B590[];
    if (arg0 == 0) {
        Game_Assert(lbl_8026B590 + 0x28, 0x50, lbl_8026B590 + 0xAB);
    }
    return fn_800618E4(arg0);
}

void *GActor_Create(void) {
    void *fn_800C4638(s32, void *, s32);
    void Game_Assert(void *, s32, void *);
    void fn_800618E4(void *);
    extern char lbl_8026B590[];
    void *node;
    char *str;

    str = lbl_8026B590;
    node = fn_800C4638(0xA0, str + 0x27, 0);
    if (node == 0) {
        Game_Assert(lbl_8026B590 + 0x28, 0x46, lbl_8026B590 + 0x31);
    }
    fn_800618E4(node);
    *(u32 *)node |= 4;
    return node;
}

int fn_800618E4(void *arg0) {
    void PSMTXIdentity(void *);
    void fn_8006DA5C(s32 *, s32);
    extern char lbl_8026B590[];
    extern f32 lbl_803691C8;
    extern f32 lbl_803691D8;
    extern u32 lbl_803691C0;

    u8 *self;
    u32 color;
    u32 zero;

    self = (u8 *)arg0;

    if (self == NULL) {
        Game_Assert(
            lbl_8026B590 + 0x28,
            0x11,
            lbl_8026B590 + 0xAB
        );
    }

    zero = 0;

    *(u32 *)(self + 0x00) = zero;
    *(u32 *)(self + 0x04) = zero;

    *(u32 *)(self + 0x40) = zero;
    *(u32 *)(self + 0x44) = zero;
    *(u32 *)(self + 0x48) = zero;
    *(u32 *)(self + 0x4C) = zero;
    *(u32 *)(self + 0x50) = zero;

    *(u32 *)(self + 0x60) = zero;
    *(u32 *)(self + 0x64) = zero;
    *(u32 *)(self + 0x68) = zero;
    *(u32 *)(self + 0x6C) = zero;

    *(u32 *)(self + 0x54) = zero;
    *(f32 *)(self + 0x58) = lbl_803691C8;
    *(f32 *)(self + 0x5C) = lbl_803691D8;

    *(u32 *)(self + 0x74) = zero;
    *(f32 *)(self + 0x78) = lbl_803691D8;

    self[0x08] = 0x80;
    self[0x09] = 0x80;
    self[0x0A] = 0x80;
    self[0x0B] = 0xFF;

    *(u16 *)(self + 0x7C) = 0xFFFF;
    *(u16 *)(self + 0x7E) = 0xFFFF;
    *(u16 *)(self + 0x80) = 0xFFFF;
    *(u16 *)(self + 0x82) = 0xFFFF;

    self[0x84] = 0xFF;
    self[0x85] = 1;
    self[0x86] = 0;
    self[0x87] = 2;

    color = lbl_803691C0;

    self[0x88] = ((u8 *)&color)[0];
    self[0x89] = ((u8 *)&color)[1];
    self[0x8A] = ((u8 *)&color)[2];
    self[0x8B] = ((u8 *)&color)[3];

    *(u32 *)(self + 0x8C) = zero;
    *(u32 *)(self + 0x90) = zero;
    *(u32 *)(self + 0x94) = zero;

    fn_8006DA5C((s32 *)(self + 0x0C), 7);
    PSMTXIdentity(self + 0x10);

    return (int)self;
}

void fn_800062CC(void *, void *, s32);
void fn_800062EC(void *, void *, s32);
void fn_80062920(void *, s32, f32 *, u8 *, void *, void *);
void fn_80063614(void *, void *, s16, f32 *, f32);
void QUATMtx(f32 *, void *);
void QUATSlerp(f32 *, f32 *, f32 *, f32);
void fn_80061A08(void *arg0)
{
    f32 sp258[4];
    f32 sp24C[3];
    f32 sp240[3];
    f32 sp234[3];
    f32 sp228[3];
    f32 sp21C[3];
    f32 sp210[3];
    f32 sp204[3];
    f32 sp1F8[3];
    f32 sp1EC[0x2B];
    f32 sp140[0x2B];
    u8 sp100[0x50];
    u8 spD0[0x30];
    u8 spA0[0x30];
    u8 sp70[0x30];
    u8 sp40[0x30];
    void *sp30[5];
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s16 spC;
    s16 sp8;
    void *self = arg0;
    void *obj;
    void *base;
    u8 *ctx;
    f32 f26;
    f32 f31;
    s32 i;
    s32 n;
    s32 flags;
    s32 minId;
    s32 orFlags;
    s32 bit10;
    s32 j;
    void *entry;
    void *row;
    void *p;
    void *walk;
    u8 *slot;
    f32 *src;
    f32 *dst;
    s32 k;
    u16 rot;
    f32 fx, fy, fz;
    f32 w;
    f32 f27;
    void *curObj;
    void *sel;

    obj = (void *)fn_80060664(self);
    base = (void *)GActor_GetNodeTable(self);
    ctx = (u8 *)fn_8006049C(self);
    if (obj == NULL) {
        return;
    }

    if (M2C_FIELD(self, void **, 0x74) == NULL || lbl_803691E0 == M2C_FIELD(self, f32 *, 0x78)) {
        f26 = fn_80060468(self);
        spC = (s16)f26;
        row = M2C_FIELD(obj, void **, 0x20);
        for (i = 0; i < M2C_FIELD(obj, s32 *, 0x1C); i++, row = (void *)((u8 *)row + 0x10)) {
            entry = (void *)((u8 *)M2C_FIELD(base, void **, 0xC) + M2C_FIELD(row, s32 *, 0) * 0xF4);
            flags = M2C_FIELD(row, s32 *, 4) | M2C_FIELD(entry, s32 *, 0xC);
            if (flags & 8) {
                fn_800062CC(sp1EC, (u8 *)entry + 0x40, 0xC);
                if (flags & 0x100) {
                    fn_800062CC(sp228, (u8 *)entry + 0x7C, 0xC);
                    if (flags & 0x400) {
                        fn_800062CC(sp240, (u8 *)entry + 0x94, 0xC);
                    }
                }
            }
            if (flags & 0x20) {
                fn_800062CC(sp204, (u8 *)entry + 0x58, 0xC);
            }
            if (flags & 0x10) {
                fn_800062CC(sp1F8, (u8 *)entry + 0x4C, 0xC);
                if (flags & 0x40) {
                    fn_800062CC(sp210, (u8 *)entry + 0x64, 0xC);
                }
                if (flags & 0x800) {
                    fn_800062CC(sp24C, (u8 *)entry + 0xA0, 0xC);
                }
                if (flags & 0x80) {
                    fn_800062CC(sp21C, (u8 *)entry + 0x70, 0xC);
                    if (flags & 0x200) {
                        fn_800062CC(sp234, (u8 *)entry + 0x88, 0xC);
                    }
                }
                if (M2C_FIELD(obj, s32 *, 0xC) & 2) {
                    fn_800062EC(sp258, (u8 *)entry + 0xAC, 0x10);
                }
            }
            fn_80063614(obj, row, spC, sp1EC, f26);
            fn_80062920(entry, flags, sp1EC, ctx, NULL, obj);
        }
        return;
    }

    n = 0;
    walk = self;
    slot = sp100;
    while (walk != NULL) {
        *(void **)slot = walk;
        p = (void *)fn_80060664(walk);
        *(void **)(slot + 4) = p;
        n++;
        walk = M2C_FIELD(walk, void **, 0x74);
        *(void **)(slot + 8) = M2C_FIELD(p, void **, 0x20);
        slot[0xC] = 0;
        slot += 0x10;
    }
    if (n > 4) {
        Game_Assert(lbl_8026B658, 0x524, lbl_8026B658 + 8);
    }

    f31 = lbl_803691E4;

    for (;;) {
        minId = 0x2710;
        slot = sp100;
        for (i = 0; i < n; i++, slot += 0x10) {
            p = *(void **)(slot + 8);
            if (p != NULL) {
                k = M2C_FIELD(p, s32 *, 0);
                if (k < minId) {
                    minId = k;
                }
            }
        }
        if (minId == 0x2710) {
            minId = -1;
        } else {
            slot = sp100;
            for (i = 0; i < n; i++, slot += 0x10) {
                p = *(void **)(slot + 8);
                if (p == NULL || minId != M2C_FIELD(p, s32 *, 0)) {
                    sp30[i] = NULL;
                } else {
                    sp30[i] = p;
                    *(void **)(slot + 8) = (u8 *)p + 0x10;
                    slot[0xC]++;
                    if ((s32)slot[0xC] == M2C_FIELD(*(void **)(slot + 4), s32 *, 0x1C)) {
                        *(void **)(slot + 8) = NULL;
                    }
                }
            }
        }

        if (minId == -1) {
            return;
        }

        entry = (void *)((u8 *)M2C_FIELD(base, void **, 0xC) + minId * 0xF4);
        orFlags = 0;
        for (i = 0; i < n; i++) {
            if (sp30[i] != NULL) {
                orFlags |= M2C_FIELD(sp30[i], s32 *, 4);
            }
        }
        orFlags |= M2C_FIELD(entry, s32 *, 0xC);

        src = (f32 *)((u8 *)entry + 0x40);
        dst = sp1EC;
        j = 0;
        for (i = 0; i < 2; i++) {
            j += 0x15;
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst[3] = src[3];
            dst[4] = src[4];
            dst[5] = src[5];
            dst[6] = src[6];
            dst[7] = src[7];
            dst[8] = src[8];
            dst[9] = src[9];
            dst[10] = src[10];
            dst[11] = src[11];
            dst[12] = src[12];
            dst[13] = src[13];
            dst[14] = src[14];
            dst[15] = src[15];
            dst[16] = src[16];
            dst[17] = src[17];
            dst[18] = src[18];
            dst[19] = src[19];
            dst[20] = src[20];
            src = (f32 *)((u8 *)src + 0x54);
            dst += 0x15;
        }
        src = (f32 *)((u8 *)entry + j * 4 + 0x40);
        dst = sp1EC + j;
        while (j < 0x2B) {
            *dst++ = *src++;
            j++;
        }

        bit10 = orFlags & 0x10;
        if (bit10) {
            flags = M2C_FIELD(obj, s32 *, 0xC);
            if (flags & 1) {
                fz = M2C_FIELD(entry, f32 *, 0x54);
                fy = M2C_FIELD(entry, f32 *, 0x50);
                fx = M2C_FIELD(entry, f32 *, 0x4C);
                rot = M2C_FIELD(entry, u16 *, 0xEE);
                PSMTXIdentity(spD0);
                switch (rot) {
                case 1:
                    if (lbl_803691E4 != fx)
                        PSMTXRotRad(spD0, 0x58, lbl_803691E8 * fx);
                    if (lbl_803691E4 != fy) {
                        PSMTXRotRad(spA0, 0x59, lbl_803691E8 * fy);
                        PSMTXConcat(spA0, spD0, spD0);
                    }
                    if (lbl_803691E4 != fz) {
                        PSMTXRotRad(spA0, 0x5A, lbl_803691E8 * fz);
                        PSMTXConcat(spA0, spD0, spD0);
                    }
                    break;
                case 2:
                    if (lbl_803691E4 != fy)
                        PSMTXRotRad(spD0, 0x59, lbl_803691E8 * fy);
                    if (lbl_803691E4 != fz) {
                        PSMTXRotRad(spA0, 0x5A, lbl_803691E8 * fz);
                        PSMTXConcat(spA0, spD0, spD0);
                    }
                    if (lbl_803691E4 != fx) {
                        PSMTXRotRad(spA0, 0x58, lbl_803691E8 * fx);
                        PSMTXConcat(spA0, spD0, spD0);
                    }
                    break;
                case 3:
                    if (lbl_803691E4 != fz)
                        PSMTXRotRad(spD0, 0x5A, lbl_803691E8 * fz);
                    if (lbl_803691E4 != fx) {
                        PSMTXRotRad(spA0, 0x58, lbl_803691E8 * fx);
                        PSMTXConcat(spA0, spD0, spD0);
                    }
                    if (lbl_803691E4 != fy) {
                        PSMTXRotRad(spA0, 0x59, lbl_803691E8 * fy);
                        PSMTXConcat(spA0, spD0, spD0);
                    }
                    break;
                case 4:
                    if (lbl_803691E4 != fx)
                        PSMTXRotRad(spD0, 0x58, lbl_803691E8 * fx);
                    if (lbl_803691E4 != fz) {
                        PSMTXRotRad(spA0, 0x5A, lbl_803691E8 * fz);
                        PSMTXConcat(spA0, spD0, spD0);
                    }
                    if (lbl_803691E4 != fy) {
                        PSMTXRotRad(spA0, 0x59, lbl_803691E8 * fy);
                        PSMTXConcat(spA0, spD0, spD0);
                    }
                    break;
                case 5:
                    if (lbl_803691E4 != fy)
                        PSMTXRotRad(spD0, 0x59, lbl_803691E8 * fy);
                    if (lbl_803691E4 != fx) {
                        PSMTXRotRad(spA0, 0x58, lbl_803691E8 * fx);
                        PSMTXConcat(spA0, spD0, spD0);
                    }
                    if (lbl_803691E4 != fz) {
                        PSMTXRotRad(spA0, 0x5A, lbl_803691E8 * fz);
                        PSMTXConcat(spA0, spD0, spD0);
                    }
                    break;
                case 6:
                    if (lbl_803691E4 != fz)
                        PSMTXRotRad(spD0, 0x5A, lbl_803691E8 * fz);
                    if (lbl_803691E4 != fy) {
                        PSMTXRotRad(spA0, 0x59, lbl_803691E8 * fy);
                        PSMTXConcat(spA0, spD0, spD0);
                    }
                    if (lbl_803691E4 != fx) {
                        PSMTXRotRad(spA0, 0x58, lbl_803691E8 * fx);
                        PSMTXConcat(spA0, spD0, spD0);
                    }
                    break;
                default:
                    Game_Assert(lbl_8026B658 + 0x1B, 0xED, lbl_8026B658 + 0x23);
                    break;
                }
                QUATMtx(&sp20, spD0);
            } else if (flags & 2) {
                sp20 = M2C_FIELD(entry, f32 *, 0xAC);
                sp24 = M2C_FIELD(entry, f32 *, 0xB0);
                sp28 = M2C_FIELD(entry, f32 *, 0xB4);
                sp2C = M2C_FIELD(entry, f32 *, 0xB8);
            }
        }

        for (i = n - 1; i >= 0; i--) {
            slot = sp100 + i * 0x10;
            curObj = *(void **)(slot + 4);
            sel = sp30[i];
            f27 = fn_80060468(*(void **)slot);
            w = fn_80060460(*(void **)slot);
            if (f31 != w) {
                if (M2C_FIELD(entry, s32 *, 0xC) & 0x40000000) {
                    w = lbl_803691E0;
                }
                src = (f32 *)((u8 *)entry + 0x40);
                dst = sp140;
                j = 0;
                for (k = 0; k < 2; k++) {
                    j += 0x15;
                    dst[0] = src[0];
                    dst[1] = src[1];
                    dst[2] = src[2];
                    dst[3] = src[3];
                    dst[4] = src[4];
                    dst[5] = src[5];
                    dst[6] = src[6];
                    dst[7] = src[7];
                    dst[8] = src[8];
                    dst[9] = src[9];
                    dst[10] = src[10];
                    dst[11] = src[11];
                    dst[12] = src[12];
                    dst[13] = src[13];
                    dst[14] = src[14];
                    dst[15] = src[15];
                    dst[16] = src[16];
                    dst[17] = src[17];
                    dst[18] = src[18];
                    dst[19] = src[19];
                    dst[20] = src[20];
                    src = (f32 *)((u8 *)src + 0x54);
                    dst += 0x15;
                }
                src = (f32 *)((u8 *)entry + j * 4 + 0x40);
                dst = sp140 + j;
                while (j < 0x2B) {
                    *dst++ = *src++;
                    j++;
                }
                if (sel != NULL) {
                    sp8 = (s16)f27;
                    fn_80063614(curObj, sel, sp8, sp140, f27);
                }
                for (j = 0; j < 0x2B; j++) {
                    if (j < 0x1B) {
                        if (j < 6) {
                            if (j >= 3) {
                                continue;
                            }
                        }
                    } else if (j < 0x1F) {
                        continue;
                    }
                    sp1EC[j] = ((lbl_803691E0 - w) * sp1EC[j]) + (w * sp140[j]);
                }
                if (bit10) {
                    flags = M2C_FIELD(curObj, s32 *, 0xC);
                    if (flags & 1) {
                        rot = M2C_FIELD(entry, u16 *, 0xEE);
                        PSMTXIdentity(sp70);
                        fx = sp140[3];
                        fy = sp140[4];
                        fz = sp140[5];
                        switch (rot) {
                        case 1:
                            if (lbl_803691E4 != fx)
                                PSMTXRotRad(sp70, 0x58, lbl_803691E8 * fx);
                            if (lbl_803691E4 != fy) {
                                PSMTXRotRad(sp40, 0x59, lbl_803691E8 * fy);
                                PSMTXConcat(sp40, sp70, sp70);
                            }
                            if (lbl_803691E4 != fz) {
                                PSMTXRotRad(sp40, 0x5A, lbl_803691E8 * fz);
                                PSMTXConcat(sp40, sp70, sp70);
                            }
                            break;
                        case 2:
                            if (lbl_803691E4 != fy)
                                PSMTXRotRad(sp70, 0x59, lbl_803691E8 * fy);
                            if (lbl_803691E4 != fz) {
                                PSMTXRotRad(sp40, 0x5A, lbl_803691E8 * fz);
                                PSMTXConcat(sp40, sp70, sp70);
                            }
                            if (lbl_803691E4 != fx) {
                                PSMTXRotRad(sp40, 0x58, lbl_803691E8 * fx);
                                PSMTXConcat(sp40, sp70, sp70);
                            }
                            break;
                        case 3:
                            if (lbl_803691E4 != fz)
                                PSMTXRotRad(sp70, 0x5A, lbl_803691E8 * fz);
                            if (lbl_803691E4 != fx) {
                                PSMTXRotRad(sp40, 0x58, lbl_803691E8 * fx);
                                PSMTXConcat(sp40, sp70, sp70);
                            }
                            if (lbl_803691E4 != fy) {
                                PSMTXRotRad(sp40, 0x59, lbl_803691E8 * fy);
                                PSMTXConcat(sp40, sp70, sp70);
                            }
                            break;
                        case 4:
                            if (lbl_803691E4 != fx)
                                PSMTXRotRad(sp70, 0x58, lbl_803691E8 * fx);
                            if (lbl_803691E4 != fz) {
                                PSMTXRotRad(sp40, 0x5A, lbl_803691E8 * fz);
                                PSMTXConcat(sp40, sp70, sp70);
                            }
                            if (lbl_803691E4 != fy) {
                                PSMTXRotRad(sp40, 0x59, lbl_803691E8 * fy);
                                PSMTXConcat(sp40, sp70, sp70);
                            }
                            break;
                        case 5:
                            if (lbl_803691E4 != fy)
                                PSMTXRotRad(sp70, 0x59, lbl_803691E8 * fy);
                            if (lbl_803691E4 != fx) {
                                PSMTXRotRad(sp40, 0x58, lbl_803691E8 * fx);
                                PSMTXConcat(sp40, sp70, sp70);
                            }
                            if (lbl_803691E4 != fz) {
                                PSMTXRotRad(sp40, 0x5A, lbl_803691E8 * fz);
                                PSMTXConcat(sp40, sp70, sp70);
                            }
                            break;
                        case 6:
                            if (lbl_803691E4 != fz)
                                PSMTXRotRad(sp70, 0x5A, lbl_803691E8 * fz);
                            if (lbl_803691E4 != fy) {
                                PSMTXRotRad(sp40, 0x59, lbl_803691E8 * fy);
                                PSMTXConcat(sp40, sp70, sp70);
                            }
                            if (lbl_803691E4 != fx) {
                                PSMTXRotRad(sp40, 0x58, lbl_803691E8 * fx);
                                PSMTXConcat(sp40, sp70, sp70);
                            }
                            break;
                        default:
                            Game_Assert(lbl_8026B658 + 0x1B, 0xED, lbl_8026B658 + 0x23);
                            break;
                        }
                        QUATMtx(&sp10, sp70);
                    } else if (flags & 2) {
                        sp10 = sp140[0x1B];
                        sp14 = sp140[0x1C];
                        sp18 = sp140[0x1D];
                        sp1C = sp140[0x1E];
                    }
                    QUATSlerp(&sp20, &sp10, &sp20, w);
                }
            }
        }

        if (bit10) {
            fn_80202640(spD0, &sp20);
            fn_80062920(entry, orFlags, sp1EC, ctx, spD0, obj);
        } else {
            fn_80062920(entry, orFlags, sp1EC, ctx, NULL, obj);
        }
    }
}

void fn_80062920(void *arg0, s32 arg1, f32 *arg2, u8 *arg3, void *arg4, void *arg5)
{
    void fn_80201FC4(void *);
    void fn_80201FF0(void *, void *);
    void fn_80202024(void *, void *, void *);
    void fn_80202300(void *, s32, f32);
    void fn_80202540(void *, f32, f32, f32);
    void fn_802025C0(void *, f32, f32, f32);
    void fn_80202640(void *, f32 *);
    void fn_8006DA64(void *, s32, void *);
    extern f32 lbl_803691E4;
    extern f32 lbl_803691E8;
    extern u8 lbl_8026B658[];

    f32 m108[12];
    f32 mD8[12];
    f32 mA8[12];
    f32 m78[12];
    f32 m48[12];
    f32 m18[12];
    f32 q[4];
    s32 flags;
    s32 order;

    if (arg1 & 0x10) {
        if (arg4 != NULL) {
            fn_80201FF0(arg4, mD8);
        } else {
            flags = *(s32 *)((u8 *)arg5 + 0xC);
            if (flags & 1) {
                f32 rz, ry, rx;
                rz = arg2[5];
                ry = arg2[4];
                rx = arg2[3];
                order = *(u16 *)((u8 *)arg0 + 0xEE);
                fn_80201FC4(mD8);
                switch (order) {
                case 1:
                    if (lbl_803691E4 != rx) {
                        fn_80202300(mD8, 0x58, lbl_803691E8 * rx);
                    }
                    if (lbl_803691E4 != ry) {
                        fn_80202300(m78, 0x59, lbl_803691E8 * ry);
                        fn_80202024(m78, mD8, mD8);
                    }
                    if (lbl_803691E4 != rz) {
                        fn_80202300(m78, 0x5A, lbl_803691E8 * rz);
                        fn_80202024(m78, mD8, mD8);
                    }
                    break;
                case 2:
                    if (lbl_803691E4 != ry) {
                        fn_80202300(mD8, 0x59, lbl_803691E8 * ry);
                    }
                    if (lbl_803691E4 != rz) {
                        fn_80202300(m78, 0x5A, lbl_803691E8 * rz);
                        fn_80202024(m78, mD8, mD8);
                    }
                    if (lbl_803691E4 != rx) {
                        fn_80202300(m78, 0x58, lbl_803691E8 * rx);
                        fn_80202024(m78, mD8, mD8);
                    }
                    break;
                case 3:
                    if (lbl_803691E4 != rz) {
                        fn_80202300(mD8, 0x5A, lbl_803691E8 * rz);
                    }
                    if (lbl_803691E4 != rx) {
                        fn_80202300(m78, 0x58, lbl_803691E8 * rx);
                        fn_80202024(m78, mD8, mD8);
                    }
                    if (lbl_803691E4 != ry) {
                        fn_80202300(m78, 0x59, lbl_803691E8 * ry);
                        fn_80202024(m78, mD8, mD8);
                    }
                    break;
                case 4:
                    if (lbl_803691E4 != rx) {
                        fn_80202300(mD8, 0x58, lbl_803691E8 * rx);
                    }
                    if (lbl_803691E4 != rz) {
                        fn_80202300(m78, 0x5A, lbl_803691E8 * rz);
                        fn_80202024(m78, mD8, mD8);
                    }
                    if (lbl_803691E4 != ry) {
                        fn_80202300(m78, 0x59, lbl_803691E8 * ry);
                        fn_80202024(m78, mD8, mD8);
                    }
                    break;
                case 5:
                    if (lbl_803691E4 != ry) {
                        fn_80202300(mD8, 0x59, lbl_803691E8 * ry);
                    }
                    if (lbl_803691E4 != rx) {
                        fn_80202300(m78, 0x58, lbl_803691E8 * rx);
                        fn_80202024(m78, mD8, mD8);
                    }
                    if (lbl_803691E4 != rz) {
                        fn_80202300(m78, 0x5A, lbl_803691E8 * rz);
                        fn_80202024(m78, mD8, mD8);
                    }
                    break;
                case 6:
                    if (lbl_803691E4 != rz) {
                        fn_80202300(mD8, 0x5A, lbl_803691E8 * rz);
                    }
                    if (lbl_803691E4 != ry) {
                        fn_80202300(m78, 0x59, lbl_803691E8 * ry);
                        fn_80202024(m78, mD8, mD8);
                    }
                    if (lbl_803691E4 != rx) {
                        fn_80202300(m78, 0x58, lbl_803691E8 * rx);
                        fn_80202024(m78, mD8, mD8);
                    }
                    break;
                default:
                    fn_8006DA64(lbl_8026B658 + 0x1B, 0xED, lbl_8026B658 + 0x23);
                    break;
                }
            } else if (flags & 2) {
                q[0] = arg2[0x6C / 4];
                q[1] = arg2[0x70 / 4];
                q[2] = arg2[0x74 / 4];
                q[3] = arg2[0x78 / 4];
                fn_80202640(mD8, q);
            }
        }
        if (arg1 & 0x40) {
            f32 rx2, ry2, rz2;
            rz2 = arg2[0x2C / 4];
            ry2 = arg2[0x28 / 4];
            rx2 = arg2[0x24 / 4];
            order = *(u16 *)((u8 *)arg0 + 0xEE);
            fn_80201FC4(mA8);
            switch (order) {
            case 1:
                if (lbl_803691E4 != rx2) {
                    fn_80202300(mA8, 0x58, lbl_803691E8 * rx2);
                }
                if (lbl_803691E4 != ry2) {
                    fn_80202300(m48, 0x59, lbl_803691E8 * ry2);
                    fn_80202024(m48, mA8, mA8);
                }
                if (lbl_803691E4 != rz2) {
                    fn_80202300(m48, 0x5A, lbl_803691E8 * rz2);
                    fn_80202024(m48, mA8, mA8);
                }
                break;
            case 2:
                if (lbl_803691E4 != ry2) {
                    fn_80202300(mA8, 0x59, lbl_803691E8 * ry2);
                }
                if (lbl_803691E4 != rz2) {
                    fn_80202300(m48, 0x5A, lbl_803691E8 * rz2);
                    fn_80202024(m48, mA8, mA8);
                }
                if (lbl_803691E4 != rx2) {
                    fn_80202300(m48, 0x58, lbl_803691E8 * rx2);
                    fn_80202024(m48, mA8, mA8);
                }
                break;
            case 3:
                if (lbl_803691E4 != rz2) {
                    fn_80202300(mA8, 0x5A, lbl_803691E8 * rz2);
                }
                if (lbl_803691E4 != rx2) {
                    fn_80202300(m48, 0x58, lbl_803691E8 * rx2);
                    fn_80202024(m48, mA8, mA8);
                }
                if (lbl_803691E4 != ry2) {
                    fn_80202300(m48, 0x59, lbl_803691E8 * ry2);
                    fn_80202024(m48, mA8, mA8);
                }
                break;
            case 4:
                if (lbl_803691E4 != rx2) {
                    fn_80202300(mA8, 0x58, lbl_803691E8 * rx2);
                }
                if (lbl_803691E4 != rz2) {
                    fn_80202300(m48, 0x5A, lbl_803691E8 * rz2);
                    fn_80202024(m48, mA8, mA8);
                }
                if (lbl_803691E4 != ry2) {
                    fn_80202300(m48, 0x59, lbl_803691E8 * ry2);
                    fn_80202024(m48, mA8, mA8);
                }
                break;
            case 5:
                if (lbl_803691E4 != ry2) {
                    fn_80202300(mA8, 0x59, lbl_803691E8 * ry2);
                }
                if (lbl_803691E4 != rx2) {
                    fn_80202300(m48, 0x58, lbl_803691E8 * rx2);
                    fn_80202024(m48, mA8, mA8);
                }
                if (lbl_803691E4 != rz2) {
                    fn_80202300(m48, 0x5A, lbl_803691E8 * rz2);
                    fn_80202024(m48, mA8, mA8);
                }
                break;
            case 6:
                if (lbl_803691E4 != rz2) {
                    fn_80202300(mA8, 0x5A, lbl_803691E8 * rz2);
                }
                if (lbl_803691E4 != ry2) {
                    fn_80202300(m48, 0x59, lbl_803691E8 * ry2);
                    fn_80202024(m48, mA8, mA8);
                }
                if (lbl_803691E4 != rx2) {
                    fn_80202300(m48, 0x58, lbl_803691E8 * rx2);
                    fn_80202024(m48, mA8, mA8);
                }
                break;
            default:
                fn_8006DA64(lbl_8026B658 + 0x1B, 0xED, lbl_8026B658 + 0x23);
                break;
            }
            fn_80202024(mA8, mD8, mD8);
        }
        if (arg1 & 0x800) {
            f32 rx3, ry3, rz3;
            rz3 = arg2[0x68 / 4];
            ry3 = arg2[0x64 / 4];
            rx3 = arg2[0x60 / 4];
            order = *(u16 *)((u8 *)arg0 + 0xEE);
            fn_80201FC4(mA8);
            switch (order) {
            case 1:
                if (lbl_803691E4 != rx3) {
                    fn_80202300(mA8, 0x58, lbl_803691E8 * rx3);
                }
                if (lbl_803691E4 != ry3) {
                    fn_80202300(m18, 0x59, lbl_803691E8 * ry3);
                    fn_80202024(m18, mA8, mA8);
                }
                if (lbl_803691E4 != rz3) {
                    fn_80202300(m18, 0x5A, lbl_803691E8 * rz3);
                    fn_80202024(m18, mA8, mA8);
                }
                break;
            case 2:
                if (lbl_803691E4 != ry3) {
                    fn_80202300(mA8, 0x59, lbl_803691E8 * ry3);
                }
                if (lbl_803691E4 != rz3) {
                    fn_80202300(m18, 0x5A, lbl_803691E8 * rz3);
                    fn_80202024(m18, mA8, mA8);
                }
                if (lbl_803691E4 != rx3) {
                    fn_80202300(m18, 0x58, lbl_803691E8 * rx3);
                    fn_80202024(m18, mA8, mA8);
                }
                break;
            case 3:
                if (lbl_803691E4 != rz3) {
                    fn_80202300(mA8, 0x5A, lbl_803691E8 * rz3);
                }
                if (lbl_803691E4 != rx3) {
                    fn_80202300(m18, 0x58, lbl_803691E8 * rx3);
                    fn_80202024(m18, mA8, mA8);
                }
                if (lbl_803691E4 != ry3) {
                    fn_80202300(m18, 0x59, lbl_803691E8 * ry3);
                    fn_80202024(m18, mA8, mA8);
                }
                break;
            case 4:
                if (lbl_803691E4 != rx3) {
                    fn_80202300(mA8, 0x58, lbl_803691E8 * rx3);
                }
                if (lbl_803691E4 != rz3) {
                    fn_80202300(m18, 0x5A, lbl_803691E8 * rz3);
                    fn_80202024(m18, mA8, mA8);
                }
                if (lbl_803691E4 != ry3) {
                    fn_80202300(m18, 0x59, lbl_803691E8 * ry3);
                    fn_80202024(m18, mA8, mA8);
                }
                break;
            case 5:
                if (lbl_803691E4 != ry3) {
                    fn_80202300(mA8, 0x59, lbl_803691E8 * ry3);
                }
                if (lbl_803691E4 != rx3) {
                    fn_80202300(m18, 0x58, lbl_803691E8 * rx3);
                    fn_80202024(m18, mA8, mA8);
                }
                if (lbl_803691E4 != rz3) {
                    fn_80202300(m18, 0x5A, lbl_803691E8 * rz3);
                    fn_80202024(m18, mA8, mA8);
                }
                break;
            case 6:
                if (lbl_803691E4 != rz3) {
                    fn_80202300(mA8, 0x5A, lbl_803691E8 * rz3);
                }
                if (lbl_803691E4 != ry3) {
                    fn_80202300(m18, 0x59, lbl_803691E8 * ry3);
                    fn_80202024(m18, mA8, mA8);
                }
                if (lbl_803691E4 != rx3) {
                    fn_80202300(m18, 0x58, lbl_803691E8 * rx3);
                    fn_80202024(m18, mA8, mA8);
                }
                break;
            default:
                fn_8006DA64(lbl_8026B658 + 0x1B, 0xED, lbl_8026B658 + 0x23);
                break;
            }
            fn_80202024(mD8, mA8, mD8);
        }
        if (arg1 & 0x80) {
            fn_80202540(mA8, arg2[0x30 / 4], arg2[0x34 / 4], arg2[0x38 / 4]);
            fn_80202024(mA8, mD8, mD8);
            fn_80202540(mA8, -arg2[0x30 / 4], -arg2[0x34 / 4], -arg2[0x38 / 4]);
            fn_80202024(mD8, mA8, mD8);
            if (arg1 & 0x200) {
                fn_80202540(mA8, arg2[0x48 / 4], arg2[0x4C / 4], arg2[0x50 / 4]);
                fn_80202024(mA8, mD8, mD8);
            }
        }
    } else {
        fn_80201FC4(mD8);
    }
    if (arg1 & 8) {
        fn_802025C0(m108, arg2[0], arg2[1], arg2[2]);
        if (arg1 & 0x100) {
            fn_80202540(mA8, arg2[0x3C / 4], arg2[0x40 / 4], arg2[0x44 / 4]);
            fn_80202024(mA8, m108, m108);
            fn_80202540(mA8, -arg2[0x3C / 4], -arg2[0x40 / 4], -arg2[0x44 / 4]);
            fn_80202024(m108, mA8, m108);
            if (arg1 & 0x400) {
                fn_80202540(mA8, arg2[0x54 / 4], arg2[0x58 / 4], arg2[0x5C / 4]);
                fn_80202024(mA8, m108, m108);
            }
        }
        fn_80202024(mD8, m108, mD8);
    }
    if (arg1 & 0x20) {
        fn_80202540(mA8, arg2[0x18 / 4], arg2[0x1C / 4], arg2[0x20 / 4]);
        fn_80202024(mA8, mD8, mD8);
    }
    fn_80201FF0(mD8, arg3 + *(u16 *)((u8 *)arg0 + 0xEC) * 0x30);
}

#pragma opt_strength_reduction off
void fn_80063614(void *arg0, void *arg1, s16 arg2, f32 *arg3, f32 farg0)
{
    extern f32 lbl_803691E4;
    extern f32 lbl_803691EC;
    extern f32 lbl_803691F0;
    extern f32 lbl_803691F4;
    extern f32 lbl_803691F8;
    extern f64 lbl_80369200;
    s16 *keys;
    u8 *track;
    u8 *kf;
    s16 *table;
    s32 i;
    s32 count;
    s32 idx;
    s32 lo;
    s32 hi;
    s32 mid;
    s32 n;
    f32 v;
    f32 t0;
    f32 t1;
    f32 v0;
    f32 v1;
    f32 s0;
    f32 s1;
    f32 du;
    f32 u;
    f32 u2;
    f32 u3;
    f32 delta, tangent0, tangent1, h0, h1, h2;
    f32 scale;
    u32 gqr;

    if (*(u32 *)((u8 *)arg0 + 0xC) & 0x10) {
        s32 time = arg2;
        track = *(u8 **)((u8 *)arg0 + 0x24) + *(s32 *)((u8 *)arg1 + 8) * 0xC;
        i = 0;
        while (i < *(s32 *)((u8 *)arg1 + 0xC)) {
            gqr = (track[2] << 8) | 7;
            gqr = (gqr << 16) | (gqr & 0xFFFF);
            (void)gqr;
            keys = (s16 *)(*(u8 **)((u8 *)arg0 + 0x2C) + *(s32 *)(track + 8) * 4);
            count = *(u16 *)(track + 6);
            scale = 1.0f; /* placeholder: target uses GQR5+psq */
            if (time >= keys[count * 2 - 2]) {
                v = (f32)keys[count * 2 - 1] * scale;
            } else if (time < keys[0]) {
                v = (f32)keys[1] * scale;
            } else {
                if (count == 0) {
                    idx = -1;
                } else {
                    hi = count - 1;
                    lo = 0;
                    while (lo <= hi) {
                        mid = lo + ((hi - lo) >> 1);
                        if ((u16)keys[mid * 2] < (s32)time) {
                            lo = mid + 1;
                        } else if ((u16)keys[mid * 2] > (s32)time) {
                            hi = mid - 1;
                        } else {
                            idx = mid;
                            goto after_bs;
                        }
                    }
                    if (hi < 0) {
                        idx = -1;
                    } else if (lo > (s32)(count - 1)) {
                        idx = count - 1;
                    } else if (keys[lo * 2] <= time) {
                        idx = lo;
                    } else {
                        idx = lo - 1;
                    }
                }
            after_bs:
                {
                    s16 *p = keys + idx * 2;
                    v0 = (f32)p[1] * scale;
                    v1 = (f32)p[3] * scale;
                    t0 = (f32)p[0];
                    t1 = (f32)p[2];
                    v = v0 + (v1 - v0) * (farg0 - t0) / (t1 - t0);
                }
            }
            arg3[*(u16 *)track] = v;
            i += 1;
            track += 0xC;
        }
    } else {
        n = (s32)farg0;
        track = *(u8 **)((u8 *)arg0 + 0x24) + *(s32 *)((u8 *)arg1 + 8) * 0x14;
        i = 0;
        while (i < *(s32 *)((u8 *)arg1 + 0xC)) {
            count = *(s32 *)(track + 4);
            if (count == 0) {
                v = *(f32 *)(track + 0x10);
            } else {
                table = (s16 *)(*(u8 **)((u8 *)arg0 + 0x28) + *(s32 *)(track + 8) * 2);
                idx = table[n];
                kf = *(u8 **)((u8 *)arg0 + 0x2C) + *(s32 *)(track + 0xC) * 0x10;
                if (idx < 0) {
                    t0 = lbl_803691E4;
                    v = *(f32 *)(track + 0x10);
                } else {
                    kf += idx * 0x10;
                    t0 = (f32)*(s32 *)kf;
                    v = *(f32 *)(kf + 4);
                    kf += 0x10;
                }
                if (idx != count - 1) {
                    t1 = (f32)*(s32 *)kf;
                    v1 = *(f32 *)(kf + 4);
                    switch (*(s32 *)track) {
                    case 0x1B:
                    case 0x1C:
                    case 0x1D:
                    case 0x1E:
                        s1 = *(f32 *)(kf + 0xC);
                        if (s1 < lbl_803691EC) {
                            du = t1 - t0;
                            u = (farg0 - t0) / du;
                            u2 = u * u;
                            s0 = *(f32 *)(kf + 8);
                            u3 = u * u2;
                            delta = v1-v;
                            tangent0 = du*s0;
                            tangent1 = du*s1;
                            h0 = lbl_803691F0*u3 + lbl_803691F4*u2;
                            h1 = u + (u3-lbl_803691F8*u2);
                            h2 = u3-u2;
                            v += h0*delta + h1*tangent0 + h2*tangent1;
                        }
                        break;
                    default:
                        v += (v1 - v) * ((farg0 - t0) / (t1 - t0));
                        break;
                    }
                }
            }
            arg3[*(s32 *)track] = v;
            i += 1;
            track += 0x14;
        }
    }
}
#pragma opt_strength_reduction reset
void fn_80063934(void) {
    M2C_UNK fn_8005C7E8();
    fn_8005C7E8();
}

#pragma inline_depth(0)
M2C_UNK fn_80063954(char *arg0) {
    M2C_UNK fn_80063A14(M2C_UNK);
    M2C_UNK temp_r31;

    temp_r31 = fn_8005C82C();
    if (!(FileCache_GetFlags(arg0) & 0x4000)) {
        fn_80063A14(temp_r31);
        FileCache_MarkRelocated(arg0);
    }
    return temp_r31;
}

#pragma inline_depth(0)
void *fn_800639B4(char *arg0) {
    void fn_80063A14(void *);
    extern M2C_UNK fn_8005C82C(char *, s32);
    s32 flags;
    register void *result;
    result = (void *)fn_8005C82C(arg0, 0);
    flags = FileCache_GetFlags(arg0);
    if ((flags & 0x4000) == 0) {
        fn_80063A14(result);
        FileCache_MarkRelocated(arg0);
    }
    return result;
}

void fn_80063A14(SomeStruct *arg0) {
 void Game_Assert(void *,s32,void *);
 SomeStruct *inner;
 u8 *block;
 void *offset;
 if((u32)arg0->unkC & 8) Game_Assert(lbl_8026B658,0x201,lbl_8026B658+0x45);
 offset=arg0->unk4; if(offset) arg0->unk4=(u8 *)offset+(u32)arg0;
 offset=arg0->unk20; if(offset) arg0->unk20=(u8 *)offset+(u32)arg0;
 offset=arg0->unk24; if(offset) arg0->unk24=(u8 *)offset+(u32)arg0;
 offset=arg0->unk28; if(offset) arg0->unk28=(u8 *)offset+(u32)arg0;
 offset=arg0->unk2C; if(offset) arg0->unk2C=(u8 *)offset+(u32)arg0;
 offset=arg0->unk0;
 if(offset) {
 arg0->unk0=(u8 *)offset+(u32)arg0;
 inner=(SomeStruct *)arg0->unk0;offset=inner->unkC;
 if(offset) {inner->unkC=(u8 *)offset+(u32)arg0;
 block=(u8 *)((SomeStruct *)arg0->unk0)->unkC; *(void **)(block+4)=block+8;}
 inner=(SomeStruct *)arg0->unk0;offset=inner->unk10;
 if(offset) {inner->unk10=(u8 *)offset+(u32)arg0;
 block=(u8 *)((SomeStruct *)arg0->unk0)->unk10; *(void **)(block+4)=block+8;}
 inner=(SomeStruct *)arg0->unk0;offset=inner->unk14;
 if(offset) {inner->unk14=(u8 *)offset+(u32)arg0;
 block=(u8 *)((SomeStruct *)arg0->unk0)->unk14; *(void **)(block+4)=block+8;}
 inner=(SomeStruct *)arg0->unk0;offset=inner->unk18;
 if(offset) {inner->unk18=(u8 *)offset+(u32)arg0;
 block=(u8 *)((SomeStruct *)arg0->unk0)->unk18; *(void **)(block+4)=block+8;}
 inner=(SomeStruct *)arg0->unk0;offset=inner->unk1C;
 if(offset) {inner->unk1C=(u8 *)offset+(u32)arg0;
 block=(u8 *)((SomeStruct *)arg0->unk0)->unk1C; *(void **)(block+4)=block+8;}
 inner=(SomeStruct *)arg0->unk0;offset=inner->unk4;
 if(offset) {inner->unk4=(u8 *)offset+(u32)arg0;
 block=(u8 *)((SomeStruct *)arg0->unk0)->unk4; *(void **)(block+4)=block+8;}
 inner=(SomeStruct *)arg0->unk0;offset=inner->unk8;
 if(offset) {inner->unk8=(u8 *)offset+(u32)arg0;
 block=(u8 *)((SomeStruct *)arg0->unk0)->unk8; *(void **)(block+4)=block+8;}
 inner=(SomeStruct *)arg0->unk0;offset=inner->unk0;
 if(offset) {inner->unk0=(u8 *)offset+(u32)arg0;
 block=(u8 *)((SomeStruct *)arg0->unk0)->unk0; *(void **)(block+4)=block+8;}
inner=(SomeStruct *)arg0->unk0;offset=inner->unk20;if(offset)inner->unk20=(u8 *)offset+(u32)arg0;
 }
}

f32 fn_80063C2C(void **arg0, s32 arg1, f32 frame) {
    extern f32 lbl_803691E0, lbl_80369208;
    extern f64 lbl_80369200;
    s16 value, v0, t1, t0;
    s32 count, mode;
    s32 lo, hi, mid, time;
    u16 offset;
    u8 *base, *track, *keys;
    u8 interpolate;
    if (arg0 == 0) base = 0;
    else { void *p = *arg0; if (p) base = M2C_FIELD(p,u8 **,0x1C); else base = 0; }
    if (!base) return lbl_803691E0;
    offset = ((u16 *)M2C_FIELD(base,void **,4))[arg1];
    if (offset == 0xFFFF) track = 0; else track = base + offset;
    if (!track) return lbl_803691E0;
    count = *(u16 *)track;
    t0 = -1;
    mode = *(u16 *)(track + 2);
    t1 = t0;
    keys = track + 4;
    value = 0;
    if ((u16)count != 0) {
        if ((s32)count == 0) mid = -1;
        else {
            lo = value;
            hi = count - 1;
            time = (s32)frame;
            while (lo <= hi) {
                mid = lo + ((hi - lo) >> 1);
                if (*(u16 *)(keys + mid * 4) < time) lo = mid + 1;
                else if (*(u16 *)(keys + mid * 4) > time) hi = mid - 1;
                else break;
            }
            if (lo > hi) {
                if (hi < 0) mid = -1;
                else {
                    mid = count - 1;
                    if (lo <= mid) {
                        if (*(u16 *)(keys + lo * 4) <= time) mid = lo;
                        else mid = lo - 1;
                    }
                }
            }
        }
        if (mid < 0) { v0 = (s16)*(u16 *)(keys + 2); interpolate = 0; }
        else if (mid < count - 1) {
            t0 = *(u16 *)(keys + mid * 4);
            t1 = *(u16 *)(keys + (mid + 1) * 4);
            v0 = *(u16 *)(keys + mid * 4 + 2);
            value = *(u16 *)(keys + (mid + 1) * 4 + 2);
            interpolate = 1;
        } else { v0 = *(u16 *)(keys + mid * 4 + 2); interpolate = 0; }
        if (!interpolate) value = v0;
        else switch (mode) {
        case 0: value = (s16)((f32)v0 + ((f32)(value - v0) * (frame - (f32)t0)) / (f32)(t1 - t0)); break;
        case 1: value = v0; break;
        default: value = 0; break;
        }
    }
    return lbl_80369208 * (f32)value;
}

f32 fn_80063EC8(void **arg0, s32 arg1, f32 frame) {
    extern f32 lbl_803691E0, lbl_80369208;
    extern f64 lbl_80369200;
    s32 count;
    s16 value;
    s32 mid;
    s16 v0;
    s32 hi, mode;
    s16 t1, t0;
    u16 (*keys)[2];
    s32 lo, time;
    u16 offset;
    u8 *base, *track;
    u8 interpolate;
    if (arg0 == 0) base = 0;
    else { void *p = *arg0; if (p) base = M2C_FIELD(p,u8 **,0x18); else base = 0; }
    if (!base) return lbl_803691E0;
    offset = ((u16 *)M2C_FIELD(base,void **,4))[arg1];
    if (offset == 0xFFFF) track = 0; else track = base + offset;
    if (!track) return lbl_803691E0;
    count = *(u16 *)track;
    t0 = -1;
    mode = *(u16 *)(track + 2);
    t1 = t0;
    keys = (u16 (*)[2])(track + 4);
    value = 0;
    if ((u16)count != 0) {
        if ((s32)count == 0) mid = t0;
        else {
            lo = value;
            hi = count - 1;
            time = (s32)frame;
            while (lo <= hi) {
                mid = lo + ((hi - lo) >> 1);
                if (keys[mid][0] < time) lo = mid + 1;
                else if (keys[mid][0] > time) hi = mid - 1;
                else goto found;
            }
            if (hi < 0) mid = -1;
            else { mid = count - 1; if (lo <= mid) { if (keys[lo][0] <= time) mid = lo; else mid = lo - 1; } }
        }
found:
        if (mid < 0) { v0 = (s16)keys[0][1]; interpolate = 0; }
        else if (mid < count - 1) {
            s32 next = mid + 1;
            u16 a = keys[mid][0];
            u16 b = keys[next][0];
            u16 c = keys[mid][1];
            u16 d = keys[next][1];
            t0 = a; t1 = b; v0 = c; value = d;
            goto interpolate_pair;
        } else { v0 = keys[mid][1]; interpolate = 0; }
        goto interpolate_ready;
interpolate_pair:
        interpolate = 1;
interpolate_ready:
        if (!interpolate) value = v0;
        else switch (mode) {
        case 0: value = (s16)((f32)v0 + ((f32)(value - v0) * (frame - (f32)t0)) / (f32)(t1 - t0)); break;
        case 1: value = v0; break;
        default: value = 0; break;
        }
    }
    return lbl_80369208 * (f32)value;
}

extern f32 lbl_803691E4;
extern f32 lbl_8036920C;
f32 fn_80064164(void **arg0, s32 arg1, f32 frame) {
    extern f32 lbl_803691E4, lbl_8036920C;
    s32 count;
    s16 value;
    s32 mid;
    s16 v0;
    s32 hi, mode;
    s16 t1, t0;
    u16 (*keys)[2];
    s32 lo, time;
    u16 offset;
    u8 *base, *track;
    u8 interpolate;
    if (arg0 == 0) base = 0;
    else { void *p = *arg0; if (p) base = M2C_FIELD(p,u8 **,0x14); else base = 0; }
    if (!base) return lbl_803691E4;
    offset = ((u16 *)M2C_FIELD(base,void **,4))[arg1];
    if (offset == 0xFFFF) track = 0; else track = base + offset;
    if (!track) return lbl_803691E4;
    count = *(u16 *)track;
    t0 = -1;
    mode = *(u16 *)(track+2);
    t1 = t0;
    keys = (u16 (*)[2])(track+4);
    value = 0;
    if ((u32)count == 0) goto done;
    {
        if ((s32)count == 0) mid = -1;
        else {
            lo = value; hi = count-1; time = (s32)frame;
            goto search_test;
search_body: {
                mid = lo + ((hi-lo)>>1);
                if (keys[mid][0] < time) lo = mid+1;
                else if (keys[mid][0] > time) hi = mid-1;
                else goto found;
            }
search_test:
            if (lo <= hi) goto search_body;
            if (hi < 0) mid = -1;
            else { mid = count-1; if (lo <= mid) { if (keys[lo][0] <= time) mid = lo; else mid = lo-1; } }
        }
found:
        if (mid < 0) { v0 = (s16)keys[0][1]; interpolate = 0; }
        else if (mid < count-1) {
            s32 next = mid + 1;
            u16 a = keys[mid][0];
            u16 b = keys[next][0];
            u16 c = keys[mid][1];
            u16 d = keys[next][1];
            t0 = a; t1 = b; v0 = c; value = d;
            interpolate = 1;
        } else { v0 = keys[mid][1]; interpolate = 0; }
        if (!interpolate) value = v0;
        else switch(mode) {
        case 0: value = (s16)((f32)v0 + ((f32)(value-v0)*(frame-(f32)t0))/(f32)(t1-t0)); break;
        case 1: value = v0; break;
        default: value = 0; break;
        }
    }
done:
    return lbl_8036920C * (f32)value;
}

f32 fn_80064400(void **arg0, s32 arg1, f32 frame) {
    extern f32 lbl_803691E4, lbl_80369208;
    s32 count;
    s16 value;
    s32 mid;
    s16 v0;
    s32 hi, mode;
    s16 t1, t0;
    u16 (*keys)[2];
    s32 lo, time;
    u16 offset;
    u8 *base, *track;
    s32 interpolate;
    if (arg0 == 0) base = 0;
    else { void *p = *arg0; if (p) base = M2C_FIELD(p,u8 **,0x10); else base = 0; }
    if (!base) return lbl_803691E4;
    offset = ((u16 *)M2C_FIELD(base,void **,4))[arg1];
    if (offset == 0xFFFF) track = 0; else track = base + offset;
    if (!track) return lbl_803691E4;
    count = *(u16 *)track;
    t0 = -1;
    mode = *(u16 *)(track+2);
    t1 = t0;
    keys = (u16 (*)[2])(track+4);
    value = 0;
    if ((u32)count == 0) goto done;
    {
        if ((s32)count == 0) mid = -1;
        else {
            lo = value; hi = count-1; time = (s32)frame;
            while (lo <= hi) {
                mid = lo + ((hi-lo)>>1);
                if (keys[mid][0] < time) lo = mid+1;
                else if (keys[mid][0] > time) hi = mid-1;
                else goto found;
            }
            if (hi < 0) mid = -1;
            else { mid = count-1; if (lo <= mid) { if (keys[lo][0] <= time) mid = lo; else mid = lo-1; } }
        }
found:
        if (mid < 0) { v0 = (s16)keys[0][1]; interpolate = 0; }
        else if (mid < count-1) {
            t0 = keys[mid][0];
            t1 = keys[mid+1][0];
            v0 = keys[mid][1];
            value = keys[mid+1][1];
            interpolate = 1;
        } else { v0 = keys[mid][1]; interpolate = 0; }
        if (!(u8)interpolate) value = v0;
        else switch(mode) {
        case 0: value = (s16)((f32)v0 + ((f32)(value-v0)*(frame-(f32)t0))/(f32)(t1-t0)); break;
        case 1: value = v0; break;
        default: value = 0; break;
        }
    }
done:
    return lbl_80369208 * (f32)value;
}

f32 fn_8006469C(void **arg0, s32 arg1, f32 frame) {
    extern f32 lbl_803691E4, lbl_80369208;
    s32 count;
    s16 value;
    s32 mid;
    s16 v0;
    s32 hi, mode;
    s16 t1, t0;
    u16 (*keys)[2];
    s32 lo, time;
    u16 offset;
    u8 *base, *track;
    u8 interpolate;
    if (arg0 == 0) base = 0;
    else { void *p = *arg0; if (p) base = M2C_FIELD(p,u8 **,0xC); else base = 0; }
    if (!base) return lbl_803691E4;
    offset = ((u16 *)M2C_FIELD(base,void **,4))[arg1];
    if (offset == 0xFFFF) track = 0; else track = base + offset;
    if (!track) return lbl_803691E4;
    count = *(u16 *)track;
    t0 = -1;
    mode = *(u16 *)(track+2);
    t1 = t0;
    keys = (u16 (*)[2])(track+4);
    value = 0;
    if ((u32)count == 0) goto done;
    {
        if ((s32)count == 0) mid = -1;
        else {
            lo = value; hi = count-1; time = (s32)frame;
            while (lo <= hi) {
                mid = lo + ((hi-lo)>>1);
                if (keys[mid][0] < time) lo = mid+1;
                else if (keys[mid][0] > time) hi = mid-1;
                else goto found;
            }
            if (hi < 0) mid = -1;
            else { mid = count-1; if (lo <= mid) { if (keys[lo][0] <= time) mid = lo; else mid = lo-1; } }
        }
found:
        if (mid < 0) { v0 = (s16)keys[0][1]; interpolate = 0; }
        else if (mid < count-1) {
            s32 next = mid + 1;
            u16 a, c, b, d;
            a = keys[mid][0];
            b = keys[next][0];
            c = keys[mid][1];
            d = keys[next][1];
            t0 = a; t1 = b; v0 = c; value = d;
            interpolate = 1;
        } else { v0 = keys[mid][1]; interpolate = 0; }
        if (!interpolate) value = v0;
        else switch(mode) {
        case 0: value = (s16)((f32)v0 + ((f32)(value-v0)*(frame-(f32)t0))/(f32)(t1-t0)); break;
        case 1: value = v0; break;
        default: value = 0; break;
        }
    }
done:
    return lbl_80369208 * (f32)value;
}

void FileCache_Load(s32);
u8 GMaterial_EvalAlphaAnim(void **arg0, s32 arg1, void *arg2, f32 frame) {
    extern f64 lbl_80369200;
    s32 count;
    s16 value;
    s32 mid;
    s16 v0;
    s32 hi, mode;
    s16 t1, t0;
    u16 (*keys)[2];
    s32 lo, time;
    u16 offset;
    u8 *base, *track;
    u8 interpolate;
    if (arg0 == 0) base = 0;
    else { void *p = *arg0; if (p) base = M2C_FIELD(p,u8 **,4); else base = 0; }
    if (!base) return 0;
    offset = ((u16 *)M2C_FIELD(base,void **,4))[arg1];
    if (offset == 0xFFFF) track = 0; else track = base + offset;
    if (!track) return 0;
    count = *(u16 *)track;
    t0 = -1;
    mode = *(u16 *)(track+2);
    t1 = t0;
    keys = (u16 (*)[2])(track+4);
    value = 0;
    if ((u32)count != 0) {
        if ((s32)count == 0) mid = t0;
        else {
            lo = value; hi = count-1; time = (s32)frame;
            while (lo <= hi) {
                mid = lo + ((hi-lo)>>1);
                if (keys[mid][0] < time) lo = mid+1;
                else if (keys[mid][0] > time) hi = mid-1;
                else goto found;
            }
            if (hi < 0) mid = -1;
            else { mid = count-1; if (lo <= mid) { if (keys[lo][0] <= time) mid = lo; else mid = lo-1; } }
        }
found:
        if (mid < 0) { v0 = (s16)keys[0][1]; interpolate = 0; }
        else if (mid < count-1) {
            s32 next = mid + 1;
            t0 = keys[mid][0];
            v0 = keys[mid][1];
            t1 = keys[next][0];
            value = keys[next][1];
            goto interpolate_pair;
        } else { v0 = keys[mid][1]; interpolate = 0; }
        goto interpolate_ready;
interpolate_pair:
        interpolate = 1;
interpolate_ready:
        if (!interpolate) value = v0;
        else switch(mode) {
        case 0: value = (s16)((f32)v0 + ((f32)(value-v0)*(frame-(f32)t0))/(f32)(t1-t0)); break;
        case 1: value = v0; break;
        default: value = 0; break;
        }
    }
    *((u8 *)arg2 + 3) = (u8)value;
    return 1;
}

u8 GMaterial_EvalColorAnim(void *arg0, s32 arg1, void *arg2, f32 farg0)
{
    void fn_80064C4C(void *, void *, f32);

    u8 *base;
    u8 *node;
    void *entry;
    u16 offset;

    if (arg0 == 0) {
        base = 0;
    } else {
        node = *(u8 **)arg0;

        if (node != 0) {
            base = *(u8 **)(node + 8);
        } else {
            base = 0;
        }
    }

    if (base == 0) {
        return 0;
    }

    offset = ((u16 *)*(void **)(base + 4))[arg1];

    if (offset == 0xFFFF) {
        entry = 0;
    } else {
        entry = base + offset;
    }

    if (entry == 0) {
        return 0;
    }

    fn_80064C4C(entry, arg2, farg0);

    return 1;
}

void fn_80064C4C(void *arg0, void *arg1, f32 frame) {
    extern f32 lbl_803691E4;
    u16 (*keys)[2];
    s32 mode;
    s32 index, high, low, last, time;
    s16 time0, time1, value0, value1;
    u16 count;
    u8 interpolate;
    u32 r0, g0, b0, r1, g1, b1;
    f32 factor;
    keys = (u16 (*)[2])((u8 *)arg0+4);
    time0 = -1; time1 = -1; value1 = 0;
    count = *(u16 *)arg0;
    mode = *(u16 *)((u8 *)arg0+2);
    if (count == 0) return;
    if ((s32)count == 0) index = -1;
    else {
        last = count-1; high = last; low = 0; time = (s32)frame;
        while (low <= high) {
            index = low + ((high-low)>>1);
            if (keys[index][0] < time) low = index+1;
            else if (keys[index][0] > time) high = index-1;
            else goto found;
        }
        if (high < 0) index = -1;
        else if (low > last) index = last;
        else if (keys[low][0] <= time) index = low;
        else index = low-1;
    }
found:
    if (index < 0) { value0 = keys[0][1]; interpolate = 0; }
    else if (index < count-1) {
        s32 next = index+1;
        u16 a = keys[index][0];
        u16 b = keys[next][0];
        u16 c = keys[index][1];
        u16 d = keys[next][1];
        time0=a; value0=c; time1=b; value1=d;
        goto pair;
    } else { value0=keys[index][1]; interpolate=0; }
    goto ready;
pair:
    interpolate=1;
ready:
    if (!interpolate) {
        ((u8 *)arg1)[0] = ((s32)value0>>8)&0xF8;
        ((u8 *)arg1)[1] = ((s32)value0>>3)&0xFC;
        ((u8 *)arg1)[2] = ((u32)value0&31)<<3;
        return;
    }
    factor = lbl_803691E4;
    if (time1 != time0) factor = (frame-(f32)time0)/(f32)(time1-time0);
    r0 = ((s32)value0>>8)&0xF8;
    g0 = ((s32)value0>>3)&0xFC;
    b0 = ((u32)value0&31)<<3;
    r1 = ((s32)value1>>8)&0xF8;
    g1 = ((s32)value1>>3)&0xFC;
    b1 = ((u32)value1&31)<<3;
    switch(mode) {
    case 0: {
        s32 red = (s32)(factor*(f32)(s32)(r1-r0)+(f32)r0);
        s32 green = (s32)(factor*(f32)(s32)(g1-g0)+(f32)g0);
        s32 blue = (s32)(factor*(f32)(s32)(b1-b0)+(f32)b0);
        ((u8 *)arg1)[0] = red;
        ((u8 *)arg1)[1] = green;
        ((u8 *)arg1)[2] = blue;
        break;
    }
    case 1:
        ((u8 *)arg1)[0] = r0; ((u8 *)arg1)[1] = g0; ((u8 *)arg1)[2] = b0;
        break;
    }
}

s32 fn_80064F24(s16 *arr, s32 key, s32 n) {
    s32 mid;
    s32 high;
    s32 low;
    u16 val;

    if (n == 0) {
        mid = -1;
    } else {
        high = n - 1;
        low = 0;
        goto check;
    body:
        mid = low + ((high - low) >> 1);
        val = (u16)arr[mid * 2];
        if (val < key) {
            low = mid + 1;
            goto check;
        }
        if (val > key) {
            high = mid - 1;
            goto check;
        }
        goto done;
    check:
        if (low <= high) {
            goto body;
        }
        if (high < 0) {
            mid = -1;
        } else {
            mid = n - 1;
            do {
                if (low <= mid) {
                    if (arr[low * 2] <= key) {
                        mid = low;
                    } else {
                        mid = low - 1;
                    }
                } else {
                    break;
                }
            } while (0);
        }
    }
done:
    return mid;
}

s32 fn_80064FC4(u16 *a,u16 *b,u16 *out) {
 void Game_Assert(void *,s32,void *);
 extern u8 lbl_8026B658[];
 u16 tmp[4];
 s32 n=0;
 s32 i;
 for(i=0;i<4;i++) {
 if(a[i]!=0xFFFF) tmp[n++]=a[i];
 if(b[i]!=0xFFFF) tmp[n++]=b[i];
 }
 if(n>4) Game_Assert(lbl_8026B658,0xAD,lbl_8026B658+0x67);
 for(i=0;i<n;i++) out[i]=tmp[i];
 for(i=n;i<4;i++) out[i]=0xFFFF;
 return n;
}

s32 fn_800651FC(void ***arg0, u16 *out, f32 lo, f32 hi) {
    void fn_800056A0(s32);
    void **mid;
    u8 *base;
    u8 *entry;
    u8 *walk;
    u16 *table;
    u16 offset;
    u16 lim;
    s32 tmp;
    s32 result;
    s32 i;
    s32 j;
    s32 index;
    s32 diff1;
    s32 diff2;
    s32 mask;
    s32 remain;
    u16 val;

    if (arg0 == NULL) {
        base = NULL;
    } else {
        mid = *arg0;
        if (mid != NULL) {
            base = (u8 *)*mid;
        } else {
            base = NULL;
        }
    }

    result = 0;
    if (base != NULL) {
        tmp = 0x10000 - 1;
        i = 0;
        lim = (u16)tmp;
        index = 0;
        while (i < (s32)*(u16 *)base) {
            table = *(u16 **)(base + 4);
            offset = *(u16 *)((u8 *)table + index);
            diff1 = (s32)offset - (s32)lim;
            diff2 = (s32)lim - (s32)offset;
            mask = ~(diff1 | diff2) >> 31;
            entry = (u8 *)(((s32)base + (s32)offset) & ~mask);
            val = *(u16 *)entry;
            if (lo < (f32)val) {
                if ((f32)val <= hi) {
                    walk = entry;
                    j = 0;
                    while (j < (s32)*(u16 *)(entry + 2)) {
                        if (result >= 4) {
                            fn_800056A0(0);
                            break;
                        }
                        *out = *(u16 *)(walk + 4);
                        result += 1;
                        walk += 2;
                        j += 1;
                        out += 1;
                    }
                }
            }
            index += 2;
            i += 1;
        }
    }

    if (result < 4) {
        remain = 4 - result;
        while (remain != 0) {
            *out = 0xFFFF;
            out += 1;
            remain -= 1;
        }
    }
    return result;
}

#pragma global_optimizer off
s32 fn_800653C8(void ***arg0, u16 *out) {
    void **mid;
    u8 *base;
    u8 *entry;
    u8 *walk;
    u16 *table;
    u16 offset;
    u16 lim;
    s32 tmp;
    s32 result;
    s32 i;
    s32 j;
    s32 index;
    s32 diff1;
    s32 diff2;
    s32 mask;

    if (arg0 == NULL) {
        base = NULL;
    } else {
        mid = *arg0;
        if (mid != NULL) {
            base = (u8 *)*mid;
        } else {
            base = NULL;
        }
    }
    if (base == NULL) {
        return 0;
    }

    tmp = 0x10000 - 1;
    result = 0;
    i = 0;
    lim = (u16)tmp;
    index = 0;

    while (i < (s32)*(u16 *)base) {
        table = *(u16 **)(base + 4);
        j = 0;
        offset = *(u16 *)((u8 *)table + index);
        diff1 = (s32)offset - (s32)lim;
        diff2 = (s32)lim - (s32)offset;
        mask = ~(diff1 | diff2) >> 31;
        entry = (u8 *)(((s32)base + (s32)offset) & ~mask);
        walk = entry;
        while (j < (s32)*(u16 *)(entry + 2)) {
            *out = *(u16 *)(walk + 4);
            result += 1;
            walk += 2;
            j += 1;
            out += 1;
        }
        index += 2;
        i += 1;
    }
    return result;
}
#pragma global_optimizer reset

#pragma global_optimizer off
s32 fn_80065484(void ***arg0, s32 arg1, u16 arg2) {
    void **mid;
    u8 *entry;
    u16 lim;
    u16 *table;
    u16 offset;
    u8 *base;
    u8 *walk;
    s32 tmp;
    s32 best;
    s32 j;
    s32 index;
    s32 diff1;
    s32 diff2;
    s32 mask;
    u16 n;
    u16 v;
    u16 count;
    s32 i;

    if ((u32)arg0 == 0) {
        base = NULL;
    } else {
        mid = *arg0;
        if ((u32)mid != 0) {
            base = (u8 *)*mid;
        } else {
            base = NULL;
        }
    }
    if ((u32)base == 0) {
        return -1;
    }

    tmp = 0x10000 - 1;
    count = *(u16 *)base;
    lim = (u16)tmp;
    best = -1;
    i = 0;
    index = 0;

    while (i < (s32)count) {
        table = *(u16 **)(base + 4);
        offset = *(u16 *)((u8 *)table + index);
        diff1 = (s32)offset - (s32)lim;
        diff2 = (s32)lim - (s32)offset;
        mask = ~(diff1 | diff2) >> 31;
        entry = (u8 *)(((s32)base + (s32)offset) & ~mask);
        walk = entry;
        n = *(u16 *)(entry + 2);
        for (j = 0; j < (s32)n; j++) {
            if (*(u16 *)(walk + 4) == arg2) {
                v = *(u16 *)entry;
                if ((s32)v > arg1 && (best < 0 || (s32)v <= best)) {
                    best = v;
                }
            }
            walk += 2;
        }
        index += 2;
        i += 1;
    }
    return best;
}
#pragma global_optimizer reset
s32 fn_8006555C(void ***arg0, s32 arg1, u32 arg2) {
    void **temp;
    u8 *base;
    u16 n;
    u16 lim;
    u32 key;
    s32 best;
    s32 i;
    s32 off_idx;
    u8 *group;
    u8 *cursor;
    u16 *off_table;
    u16 off;
    s32 ctr;
    s32 j;
    u16 val;

    if (arg0 == NULL) {
        base = NULL;
    } else {
        temp = *arg0;
        if (temp != NULL) {
            base = (u8 *)*temp;
        } else {
            base = NULL;
        }
    }
    if (base == NULL) {
        return -1;
    }

    lim = (u16)(0x10000 - 1);
    n = *(u16 *)base;
    key = arg2 & 0xFFFF;
    best = -1;
    i = 0;
    off_idx = 0;
    goto check;
body:
    off_table = *(u16 **)(base + 4);
    off = *(u16 *)((u8 *)off_table + off_idx);
    {
        s32 a = off - lim;
        s32 b = lim - off;
        s32 m = (~(a | b)) >> 31;
        group = (u8 *)(((s32)base + off) & ~m);
    }
    ctr = *(u16 *)(group + 2);
    cursor = group;
    {
        for (j = 0; j < ctr; j++) {
            if (*(u16 *)(cursor + 4) == key) {
                val = *(u16 *)group;
                if ((s32)val < arg1) {
                    if (best < 0 || (s32)val >= best) {
                        best = val;
                    }
                }
            }
            cursor += 2;
        }
    }
    off_idx += 2;
    i += 1;
check:
    if (i < (s32)n) {
        goto body;
    }
    return best;
}

void *fn_80065634(void ***arg0, s32 arg1)
{
  void **mid;
  u8 *base;
  s32 index;
  s32 count;
  if (arg0 == NULL)
  {
    base = NULL;
  }
  else
  {
    mid = *arg0;
    if (mid != NULL)
    {
      base = (u8 *) (*mid);
    }
    else
    {
      base = NULL;
    }
  }
  if (base == NULL)
  {
    return NULL;
  }
  count = *((u16 *) base);
  index = 0;
  while (count > 0)
  {
    u16 offset = *((u16 *) (((u8 *) (*((void **) (base + 4)))) + index));
    u8 *entry = (u8 *) (((u32) (base + offset)) & (-((s32) (offset != ((u16) (-1))))));
    if ((*((u16 *) entry)) == arg1)
    {
      return entry;
    }
    index += 2;
    count--;
  }

  return NULL;
}

#pragma optimization_level 2
/* Walk a node chain and accumulate each node's euler rotations (degrees) into out, using the node's axis order. */
void *MTXRotDegOrder(void *node, void *out)
{
    void PSMTXIdentity(void *);
    void PSMTXConcat(void *, void *, void *);
    u32 PSMTXInverse(void *, void *);
    void PSMTXRotRad(void *, s32, f32);
    int Game_Assert(void *, int, void *);
    extern f32 gMtxZero;
    extern f32 gDegToRad;
    extern u8 gGUtilAssertMsg[];
    u8 rot[0x30];
    s32 order;
    f32 rx;
    f32 ry;
    u8 tmp[0x30];
    f32 rz;

    PSMTXIdentity(out);

    while (node != NULL) {
        if (*(u32 *)((u8 *)node + 0xC) & 0x40) {
            rx = *(f32 *)((u8 *)node + 0x64);
            ry = *(f32 *)((u8 *)node + 0x68);
            rz = *(f32 *)((u8 *)node + 0x6C);
            order = *(u16 *)((u8 *)node + 0xEE);
            PSMTXIdentity(rot);

            switch (order) {
            case 1:
                if (gMtxZero != rx) {
                    PSMTXRotRad(rot, 'X', gDegToRad * rx);
                }
                if (gMtxZero != ry) {
                    PSMTXRotRad(tmp, 'Y', gDegToRad * ry);
                    PSMTXConcat(tmp, rot, rot);
                }
                if (gMtxZero != rz) {
                    PSMTXRotRad(tmp, 'Z', gDegToRad * rz);
                    PSMTXConcat(tmp, rot, rot);
                }
                break;
            case 2:
                if (gMtxZero != ry) {
                    PSMTXRotRad(rot, 'Y', gDegToRad * ry);
                }
                if (gMtxZero != rz) {
                    PSMTXRotRad(tmp, 'Z', gDegToRad * rz);
                    PSMTXConcat(tmp, rot, rot);
                }
                if (gMtxZero != rx) {
                    PSMTXRotRad(tmp, 'X', gDegToRad * rx);
                    PSMTXConcat(tmp, rot, rot);
                }
                break;
            case 3:
                if (gMtxZero != rz) {
                    PSMTXRotRad(rot, 'Z', gDegToRad * rz);
                }
                if (gMtxZero != rx) {
                    PSMTXRotRad(tmp, 'X', gDegToRad * rx);
                    PSMTXConcat(tmp, rot, rot);
                }
                if (gMtxZero != ry) {
                    PSMTXRotRad(tmp, 'Y', gDegToRad * ry);
                    PSMTXConcat(tmp, rot, rot);
                }
                break;
            case 4:
                if (gMtxZero != rx) {
                    PSMTXRotRad(rot, 'X', gDegToRad * rx);
                }
                if (gMtxZero != rz) {
                    PSMTXRotRad(tmp, 'Z', gDegToRad * rz);
                    PSMTXConcat(tmp, rot, rot);
                }
                if (gMtxZero != ry) {
                    PSMTXRotRad(tmp, 'Y', gDegToRad * ry);
                    PSMTXConcat(tmp, rot, rot);
                }
                break;
            case 5:
                if (gMtxZero != ry) {
                    PSMTXRotRad(rot, 'Y', gDegToRad * ry);
                }
                if (gMtxZero != rx) {
                    PSMTXRotRad(tmp, 'X', gDegToRad * rx);
                    PSMTXConcat(tmp, rot, rot);
                }
                if (gMtxZero != rz) {
                    PSMTXRotRad(tmp, 'Z', gDegToRad * rz);
                    PSMTXConcat(tmp, rot, rot);
                }
                break;
            case 6:
                if (gMtxZero != rz) {
                    PSMTXRotRad(rot, 'Z', gDegToRad * rz);
                }
                if (gMtxZero != ry) {
                    PSMTXRotRad(tmp, 'Y', gDegToRad * ry);
                    PSMTXConcat(tmp, rot, rot);
                }
                if (gMtxZero != rx) {
                    PSMTXRotRad(tmp, 'X', gDegToRad * rx);
                    PSMTXConcat(tmp, rot, rot);
                }
                break;
            default:
                Game_Assert(gGUtilAssertMsg, 0xED, gGUtilAssertMsg + 8);
                break;
            }

            if (PSMTXInverse(rot, rot) != 0U) {
                PSMTXConcat(rot, out, out);
            }
        }
        node = *(void **)node;
    }

    return out;
}

#pragma optimization_level 4
#pragma inline_depth(3)
#pragma use_lmw_stmw on
void fn_80065AF8(s32 arg0, void *arg1, void *arg2, void *arg3) {
    void PSMTXConcat(void *, void *, void *);
    void *child;
    void *n;
    void *p;
    void *dst;
    u32 off;

    p = *(void **)arg1;
    if (p) {
        dst = (u8 *)arg2 + *(u16 *)((u8 *)arg1 + 0xEC) * 0x30;
        PSMTXConcat((u8 *)arg2 + *(u16 *)((u8 *)p + 0xEC) * 0x30, dst, dst);
    }
    if (arg3) {
        off = *(u16 *)((u8 *)arg1 + 0xEC) * 0x30;
        PSMTXConcat((u8 *)arg2 + off, (u8 *)arg1 + 0x10, (u8 *)arg3 + off);
    }
    child = *(void **)((u8 *)arg1 + 8);
    if (child) fn_80065AF8(arg0, child, arg2, arg3);
    arg1 = *(void **)((u8 *)arg1 + 4);
    if (arg1) fn_80065AF8(arg0, arg1, arg2, arg3);
}
#pragma optimization_level reset

#pragma optimization_level 4
void fn_80065E68(void) {
    M2C_UNK fn_8005C7E8();
    fn_8005C7E8();
}

#pragma inline_depth(0)
u32 fn_80065E88(s32 arg0, s32 arg1) {
    void fn_80065F48(s32);
    s32 temp_r31;

    (void)arg1;
    temp_r31 = fn_8005C82C();
    if (!(FileCache_GetFlags((char *)arg0) & 0x4000)) {
        fn_80065F48(temp_r31);
        FileCache_MarkRelocated((char *)arg0);
    }
    return temp_r31;
}
s32 fn_80065EE8(void *arg0) {
#pragma scheduling off
    void fn_80065F48(s32);
    s32 temp_r31;

    temp_r31 = fn_8005C82C(arg0, 0);
    if (!(FileCache_GetFlags((char *)arg0) & 0x4000)) {
        fn_80065F48(temp_r31);
        FileCache_MarkRelocated((char *)arg0);
    }
    return temp_r31;
#pragma scheduling reset
}

#pragma optimization_level 2
void fn_80065F48(void *arg0) {
    u8 Str_MatchUnderscoreTag(void *, void *);
    s32 Str_Cmp(void *, void *);
    extern u8 gGUtilAssertMsg[];
    s32 off;
    s32 idx;
    void *entry;
    void *base;

    if (*(u32 *)((u8 *)arg0 + 0xC) != 0) {
        *(u32 *)((u8 *)arg0 + 0xC) += (u32)arg0;
    }
    if (*(u32 *)((u8 *)arg0 + 4) != 0) {
        *(u32 *)((u8 *)arg0 + 4) += (u32)arg0;
    }
    idx = 0;
    off = 0;
    while (idx < *(s32 *)((u8 *)arg0 + 8)) {
        base = *(void **)((u8 *)arg0 + 0xC);
        entry = (u8 *)base + off;
        if (*(s32 *)entry == -1) {
            *(s32 *)entry = 0;
        } else {
            *(s32 *)entry = (s32)((u8 *)base + *(s32 *)entry * 0xF4);
        }
        if (*(s32 *)((u8 *)entry + 4) == -1) {
            *(s32 *)((u8 *)entry + 4) = 0;
        } else {
            *(s32 *)((u8 *)entry + 4) =
                (s32)((u8 *)*(void **)((u8 *)arg0 + 0xC) +
                      *(s32 *)((u8 *)entry + 4) * 0xF4);
        }
        if (*(s32 *)((u8 *)entry + 8) == -1) {
            *(s32 *)((u8 *)entry + 8) = 0;
        } else {
            *(s32 *)((u8 *)entry + 8) =
                (s32)((u8 *)*(void **)((u8 *)arg0 + 0xC) +
                      *(s32 *)((u8 *)entry + 8) * 0xF4);
        }
        if (*(void **)((u8 *)entry + 0xF0) != NULL) {
            *(u32 *)((u8 *)entry + 0xF0) += *(u32 *)((u8 *)arg0 + 4);
        }
        *(s16 *)((u8 *)entry + 0xEC) = idx;
        if (*(void **)((u8 *)entry + 0xF0) != NULL &&
            Str_MatchUnderscoreTag(*(void **)((u8 *)entry + 0xF0), NULL) != 0) {
            *(u32 *)((u8 *)entry + 0xC) |= 0x80000000;
            if (Str_MatchUnderscoreTag(*(void **)((u8 *)entry + 0xF0),
                                       gGUtilAssertMsg + 0x2A) != 0) {
                *(u32 *)((u8 *)entry + 0xC) |= 0x10000000;
            }
            if (Str_MatchUnderscoreTag(*(void **)((u8 *)entry + 0xF0),
                                       gGUtilAssertMsg + 0x2D) != 0) {
                *(u32 *)((u8 *)entry + 0xC) |= 0x20000000;
            }
        }
        if (*(void **)((u8 *)entry + 0xF0) != NULL &&
            Str_Cmp(*(void **)((u8 *)entry + 0xF0), gGUtilAssertMsg + 0x30) == 0) {
            *(u32 *)((u8 *)entry + 0xC) |= 0x08000000;
        }
        if (*(s32 *)((u8 *)entry + 0xC) & 0x40) {
            *(s32 *)((u8 *)entry + 0xC) |= 0x10;
        }
        off += 0xF4;
        idx += 1;
    }
}
#pragma optimization_level reset
void fn_80066124(u32 arg0) {
extern void *gCamera;
u8 *p=(u8 *)arg0;
if(p==NULL) p=gCamera;
if(p==NULL) return;
*(s16 *)(p+0x118)=0;
*(s32 *)(p+0x11c)=0;
*(s32 *)(p+0x130)=0;
*(s32 *)(p+0x144)=0;
*(s32 *)(p+0x158)=0;
*(s32 *)(p+0x16c)=0;
*(s32 *)(p+0x120)=0;
*(s32 *)(p+0x134)=0;
*(s32 *)(p+0x148)=0;
*(s32 *)(p+0x15c)=0;
*(s32 *)(p+0x170)=0;
*(s32 *)(p+0x124)=0;
*(s32 *)(p+0x138)=0;
*(s32 *)(p+0x14c)=0;
*(s32 *)(p+0x160)=0;
*(s32 *)(p+0x174)=0;
*(s32 *)(p+0x128)=0;
*(s32 *)(p+0x13c)=0;
*(s32 *)(p+0x150)=0;
*(s32 *)(p+0x164)=0;
*(s32 *)(p+0x178)=0;
*(s32 *)(p+0x12c)=0;
*(s32 *)(p+0x140)=0;
*(s32 *)(p+0x154)=0;
*(s32 *)(p+0x168)=0;
*(s32 *)(p+0x17c)=0;

}

void fn_800661A8(void *arg0) {
    void fn_802029C4(void *, void *, f32 *);
    void fn_80202A18(void *, f32 *, f32 *);
    void fn_802031CC(void *, f32 *, f32);
    void GXSetCopyClear(s32 *, s32);
    void fn_80221D6C(void *, f32, f32, f32, f32, f32, f32);
    void fn_80221D88(void *, s32, f32);
    void fn_80221F18(void *, s32, f32, f32);
    void fn_80221FE8(void *, f32, f32, f32);
    void fn_80221FF8(void *, f32, f32, f32);
    void fn_802220DC(void *, s32 *);
    void fn_802220E8(void *, s32);
    void GXSetTevSwapMode(s32, s32, s32);
    void fn_80223E5C(s32, s32, s32, s32, s32);
    void fn_802240F0(s32, s32 *, f32, f32, f32, f32);
    void fn_80224304(void *, s32, void *);
    void fn_802244B4(s32, s32, void *);
    void fn_802245D8(s32, s32, s32, s32);
    void fn_8022462C(s32);
    void fn_80224658(s32);
    void GXSetZMode(s32, s32, s32);
    void fn_802246B8(s32);
    extern s32 lbl_80285E70[];
    extern u8 lbl_80366DD0;
    extern u8 *lbl_80366DD4;
    extern u8 lbl_80366DD8;
    extern u8 *lbl_80366DDC;
    extern u8 *gCamera;
    extern s32 lbl_80369220;
    extern f32 lbl_80369224;
    extern f32 lbl_80369228;
    extern f32 lbl_8036922C;
    extern f32 lbl_80369230;
    extern f32 lbl_80369234;
    extern f32 lbl_80369238;
    extern f32 lbl_8036923C;
    extern f32 lbl_80369240;
    extern f32 lbl_80369244;
    extern s32 lbl_8036C440;
    extern s32 lbl_8036C44C;

    u8 mtx[0x44];
    u8 buf0[0x14];
    u8 buf1[0x14];
    u8 buf2[0x14];
    u8 buf3[0x14];
    u8 buf4[0x14];
    u8 buf5[0x14];
    u8 buf6[0x14];
    f32 vec2[3];
    f32 vec[3];
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    u8 *cam;
    u8 *p;
    u8 *node;
    void (*cb)(void *);
    s32 type;
    s32 n;
    u8 *lights;
    s32 i;

    lights = lbl_80366DDC;
    if (lights != NULL) {
        i = 0;
        do {
            if (i < 4) {
                if (i < 2) {
                    if (i < 0) {
                    } else {
                        fn_802031CC(lights + 0x14, vec, lbl_8036922C);
                        fn_80202A18(gCamera + 0xA4, vec, vec);
                        fn_80221FE8(mtx, vec[0], vec[1], vec[2]);
                        fn_80221F18(mtx, 0, lbl_80369228, lbl_80369230);
                        fn_80221D88(mtx, 0, lbl_80369234);
                    }
                } else {
                    fn_80202A18(gCamera + 0xA4, (f32 *)(lights + 0x14), vec2);
                    fn_80221FF8(mtx, vec2[0], vec2[1], vec2[2]);
                    fn_80221F18(mtx, 0, lbl_80369228, lbl_80369230);
                    fn_80221D88(mtx, 0, lbl_80369234);
                    fn_80221D6C(mtx, lbl_80369228, lbl_80369228, lbl_80369224, lbl_80369238, lbl_80369228, lbl_8036923C);
                }
            } else {
                if (i < 8) {
                    fn_802029C4(gCamera + 0xA4, lights + 8, vec);
                    fn_80221FE8(mtx, vec[0], vec[1], vec[2]);
                    fn_80221F18(mtx, 2, *(f32 *)(lights + 0x20), lbl_80369230);
                    fn_80221D88(mtx, 0, lbl_80369234);
                }
            }
            sp60 = *(s32 *)(lights + 4);
            fn_802220DC(mtx, &sp60);
            fn_802220E8(mtx, 1 << i);
            i += 1;
            lights += 0x2C;
        } while (i < 8);
    }

    type = lbl_80366DD4[0];
    lbl_80366DD8 = 8;
    if (type == 0) {
        sp58 = lbl_8036C440;
        fn_802240F0(0, &sp58, lbl_80369240, lbl_80369234, lbl_80369224, lbl_80369244);
        fn_802244B4(0, 0, NULL);
    } else {
        sp54 = lbl_80369220;
        ((u8 *)&sp54)[0] = lbl_80366DD4[1];
        ((u8 *)&sp54)[1] = lbl_80366DD4[2];
        ((u8 *)&sp54)[2] = lbl_80366DD4[3];
        cam = gCamera;
        sp5C = sp54;
        fn_802240F0(lbl_80285E70[type], &sp5C, *(f32 *)(lbl_80366DD4 + 4), *(f32 *)(lbl_80366DD4 + 8),
                    *(f32 *)(cam + 0x180), *(f32 *)(cam + 0x184));
        fn_80224304(buf0, 0x280, cam + 0x24);
        fn_802244B4(1, 0x140, buf0);
    }
    sp64 = lbl_8036C44C;
    GXSetCopyClear(&sp64, 0xFFFFFF);
    lbl_80366DD0 = 3;
    fn_802245D8(0, 1, 0, 7);
    fn_802246B8(1);
    fn_80223E5C(0, 0, 1, 7, 0);
    GXSetZMode(1, 3, 1);
    fn_8022462C(1);
    fn_80224658(0);
    GXSetTevSwapMode(0, 0, 0);

    if (lbl_80366DD8 != 6) {
        type = lbl_80366DD4[0];
        lbl_80366DD8 = 8;
        if (type == 0) {
            sp48 = lbl_8036C440;
            fn_802240F0(0, &sp48, lbl_80369240, lbl_80369234, lbl_80369224, lbl_80369244);
            fn_802244B4(0, 0, NULL);
        } else {
            sp44 = lbl_80369220;
            ((u8 *)&sp44)[0] = lbl_80366DD4[1];
            ((u8 *)&sp44)[1] = lbl_80366DD4[2];
            ((u8 *)&sp44)[2] = lbl_80366DD4[3];
            cam = gCamera;
            sp4C = sp44;
            fn_802240F0(lbl_80285E70[type], &sp4C, *(f32 *)(lbl_80366DD4 + 4), *(f32 *)(lbl_80366DD4 + 8),
                        *(f32 *)(cam + 0x180), *(f32 *)(cam + 0x184));
            fn_80224304(buf1, 0x280, cam + 0x24);
            fn_802244B4(1, 0x140, buf1);
        }
    }
    n = 0;
    p = (u8 *)arg0;
    do {
        node = *(u8 **)(p + 0x158);
        while (node != NULL) {
            cb = *(void (**)(void *))(node + 8);
            cb(*(void **)(node + 0xC));
            node = *(u8 **)node;
        }
        n += 1;
        p += 4;
    } while (n < 5);

    lbl_80366DD0 = 0;
    fn_802245D8(0, 1, 0, 7);
    fn_802246B8(1);
    fn_80223E5C(0, 0, 1, 7, 0);
    GXSetZMode(1, 3, 1);
    fn_8022462C(1);
    fn_80224658(0);
    GXSetTevSwapMode(0, 0, 0);
    if (lbl_80366DD8 != 6) {
        type = lbl_80366DD4[0];
        lbl_80366DD8 = 8;
        if (type == 0) {
            sp3C = lbl_8036C440;
            fn_802240F0(0, &sp3C, lbl_80369240, lbl_80369234, lbl_80369224, lbl_80369244);
            fn_802244B4(0, 0, NULL);
        } else {
            sp38 = lbl_80369220;
            ((u8 *)&sp38)[0] = lbl_80366DD4[1];
            ((u8 *)&sp38)[1] = lbl_80366DD4[2];
            ((u8 *)&sp38)[2] = lbl_80366DD4[3];
            cam = gCamera;
            sp40 = sp38;
            fn_802240F0(lbl_80285E70[type], &sp40, *(f32 *)(lbl_80366DD4 + 4), *(f32 *)(lbl_80366DD4 + 8),
                        *(f32 *)(cam + 0x180), *(f32 *)(cam + 0x184));
            fn_80224304(buf2, 0x280, cam + 0x24);
            fn_802244B4(1, 0x140, buf2);
        }
    }
    n = 0;
    p = (u8 *)arg0;
    do {
        node = *(u8 **)(p + 0x11C);
        while (node != NULL) {
            cb = *(void (**)(void *))(node + 8);
            cb(*(void **)(node + 0xC));
            node = *(u8 **)node;
        }
        n += 1;
        p += 4;
    } while (n < 5);

    lbl_80366DD0 = 1;
    fn_802245D8(0, 4, 5, 7);
    fn_802246B8(0);
    fn_80223E5C(6, 0x80, 1, 0, 0);
    GXSetZMode(1, 3, 1);
    fn_8022462C(1);
    fn_80224658(0);
    GXSetTevSwapMode(0, 0, 0);
    if (lbl_80366DD8 != 6) {
        type = lbl_80366DD4[0];
        lbl_80366DD8 = 8;
        if (type == 0) {
            sp30 = lbl_8036C440;
            fn_802240F0(0, &sp30, lbl_80369240, lbl_80369234, lbl_80369224, lbl_80369244);
            fn_802244B4(0, 0, NULL);
        } else {
            sp2C = lbl_80369220;
            ((u8 *)&sp2C)[0] = lbl_80366DD4[1];
            ((u8 *)&sp2C)[1] = lbl_80366DD4[2];
            ((u8 *)&sp2C)[2] = lbl_80366DD4[3];
            cam = gCamera;
            sp34 = sp2C;
            fn_802240F0(lbl_80285E70[type], &sp34, *(f32 *)(lbl_80366DD4 + 4), *(f32 *)(lbl_80366DD4 + 8),
                        *(f32 *)(cam + 0x180), *(f32 *)(cam + 0x184));
            fn_80224304(buf3, 0x280, cam + 0x24);
            fn_802244B4(1, 0x140, buf3);
        }
    }
    n = 0;
    p = (u8 *)arg0;
    do {
        node = *(u8 **)(p + 0x130);
        while (node != NULL) {
            cb = *(void (**)(void *))(node + 8);
            cb(*(void **)(node + 0xC));
            node = *(u8 **)node;
        }
        n += 1;
        p += 4;
    } while (n < 5);

    lbl_80366DD0 = 2;
    fn_802245D8(1, 4, 5, 7);
    fn_802246B8(1);
    fn_80223E5C(4, 0, 1, 0, 0);
    GXSetZMode(1, 3, 0);
    fn_8022462C(1);
    fn_80224658(0);
    GXSetTevSwapMode(0, 0, 0);
    if (lbl_80366DD8 != 6) {
        type = lbl_80366DD4[0];
        lbl_80366DD8 = 8;
        if (type == 0) {
            sp24 = lbl_8036C440;
            fn_802240F0(0, &sp24, lbl_80369240, lbl_80369234, lbl_80369224, lbl_80369244);
            fn_802244B4(0, 0, NULL);
        } else {
            sp20 = lbl_80369220;
            ((u8 *)&sp20)[0] = lbl_80366DD4[1];
            ((u8 *)&sp20)[1] = lbl_80366DD4[2];
            ((u8 *)&sp20)[2] = lbl_80366DD4[3];
            cam = gCamera;
            sp28 = sp20;
            fn_802240F0(lbl_80285E70[type], &sp28, *(f32 *)(lbl_80366DD4 + 4), *(f32 *)(lbl_80366DD4 + 8),
                        *(f32 *)(cam + 0x180), *(f32 *)(cam + 0x184));
            fn_80224304(buf4, 0x280, cam + 0x24);
            fn_802244B4(1, 0x140, buf4);
        }
    }
    n = 0;
    p = (u8 *)arg0;
    do {
        node = *(u8 **)(p + 0x144);
        while (node != NULL) {
            cb = *(void (**)(void *))(node + 8);
            cb(*(void **)(node + 0xC));
            node = *(u8 **)node;
        }
        n += 1;
        p += 4;
    } while (n < 5);

    lbl_80366DD0 = 4;
    fn_802245D8(1, 4, 5, 7);
    fn_802246B8(1);
    fn_80223E5C(4, 0, 1, 0, 0);
    GXSetZMode(1, 3, 0);
    fn_8022462C(1);
    fn_80224658(0);
    GXSetTevSwapMode(0, 0, 0);
    if (lbl_80366DD8 != 6) {
        type = lbl_80366DD4[0];
        lbl_80366DD8 = 8;
        if (type == 0) {
            sp18 = lbl_8036C440;
            fn_802240F0(0, &sp18, lbl_80369240, lbl_80369234, lbl_80369224, lbl_80369244);
            fn_802244B4(0, 0, NULL);
        } else {
            sp14 = lbl_80369220;
            ((u8 *)&sp14)[0] = lbl_80366DD4[1];
            ((u8 *)&sp14)[1] = lbl_80366DD4[2];
            ((u8 *)&sp14)[2] = lbl_80366DD4[3];
            cam = gCamera;
            sp1C = sp14;
            fn_802240F0(lbl_80285E70[type], &sp1C, *(f32 *)(lbl_80366DD4 + 4), *(f32 *)(lbl_80366DD4 + 8),
                        *(f32 *)(cam + 0x180), *(f32 *)(cam + 0x184));
            fn_80224304(buf5, 0x280, cam + 0x24);
            fn_802244B4(1, 0x140, buf5);
        }
    }
    n = 0;
    p = (u8 *)arg0;
    do {
        node = *(u8 **)(p + 0x16C);
        while (node != NULL) {
            cb = *(void (**)(void *))(node + 8);
            cb(*(void **)(node + 0xC));
            node = *(u8 **)node;
        }
        n += 1;
        p += 4;
    } while (n < 5);

    lbl_80366DD8 = 6;
    sp50 = lbl_8036C440;
    fn_802240F0(0, &sp50, lbl_80369240, lbl_80369234, lbl_80369224, lbl_80369244);
    fn_802244B4(0, 0, NULL);
    lbl_80366DD0 = 5;
    fn_80223E5C(7, 0, 1, 7, 0);
    GXSetZMode(1, 3, 0);
    fn_8022462C(1);
    fn_80224658(0);
    GXSetTevSwapMode(0, 0, 0);
    if (lbl_80366DD8 != 6) {
        type = lbl_80366DD4[0];
        lbl_80366DD8 = 8;
        if (type == 0) {
            spC = lbl_8036C440;
            fn_802240F0(0, &spC, lbl_80369240, lbl_80369234, lbl_80369224, lbl_80369244);
            fn_802244B4(0, 0, NULL);
        } else {
            sp8 = lbl_80369220;
            ((u8 *)&sp8)[0] = lbl_80366DD4[1];
            ((u8 *)&sp8)[1] = lbl_80366DD4[2];
            ((u8 *)&sp8)[2] = lbl_80366DD4[3];
            cam = gCamera;
            sp10 = sp8;
            fn_802240F0(lbl_80285E70[type], &sp10, *(f32 *)(lbl_80366DD4 + 4), *(f32 *)(lbl_80366DD4 + 8),
                        *(f32 *)(cam + 0x180), *(f32 *)(cam + 0x184));
            fn_80224304(buf6, 0x280, cam + 0x24);
            fn_802244B4(1, 0x140, buf6);
        }
    }
}

void fn_80066D00(s32 mode) {
void fn_802245D8(s32,s32,s32,s32);
void fn_802246B8(s32);
void fn_80223E5C(s32,s32,s32,s32,s32);
void GXSetZMode(s32,s32,s32);
void fn_8022462C(s32);
void fn_80224658(s32);
void GXSetTevSwapMode(s32,s32,s32);
void fn_802240F0(s32,s32 *,f32,f32,f32,f32);
void fn_80224304(void *,s32,void *);
void fn_802244B4(s32,s32,void *);
extern u8 *lbl_80366DD4;
extern u8 lbl_80366DD8;
extern s8 lbl_80366DD0;
extern u8 *gCamera;
extern s32 lbl_80285E70[],lbl_80369220,lbl_8036C440;
extern f32 lbl_80369240,lbl_80369234,lbl_80369224,lbl_80369244;
u16 buf[10];
s32 copy,clear,color;
u8 *cam,*fog;
s32 type;
u32 old=(u32)mode>>31;
if(old) mode=lbl_80366DD0;
if(!old) lbl_80366DD0=mode;
switch(mode) {
case 0: case 3:
fn_802245D8(0,1,0,7);fn_802246B8(1);fn_80223E5C(0,0,1,7,0);GXSetZMode(1,3,1);break;
case 1:
fn_802245D8(0,4,5,7);fn_802246B8(0);fn_80223E5C(6,128,1,0,0);GXSetZMode(1,3,1);break;
case 2: case 4:
fn_802245D8(1,4,5,7);fn_802246B8(1);fn_80223E5C(4,0,1,0,0);GXSetZMode(1,3,0);break;
case 5: fn_80223E5C(7,0,1,7,0);GXSetZMode(1,3,0);break;
}
fn_8022462C(1);fn_80224658(0);GXSetTevSwapMode(0,0,0);
fog=lbl_80366DD4;
if(lbl_80366DD8!=6) {
type=fog[0];lbl_80366DD8=8;
if(type==0) {
clear=lbl_8036C440;
fn_802240F0(0,&clear,lbl_80369240,lbl_80369234,lbl_80369224,lbl_80369244);
fn_802244B4(0,0,0);
} else {
color=lbl_80369220;
((u8 *)&color)[0]=fog[1];((u8 *)&color)[1]=fog[2];((u8 *)&color)[2]=fog[3];
cam=gCamera;copy=color;
fn_802240F0(lbl_80285E70[type],&copy,*(f32 *)(fog+4),*(f32 *)(fog+8),*(f32 *)(cam+0x180),*(f32 *)(cam+0x184));
fn_80224304(buf,0x280,cam+0x24);fn_802244B4(1,0x140,buf);
}
}
}

void fn_80066F64(void)
{
    typedef struct { f32 x, y, z; } Vec3;
    extern Vec3 lbl_8026B744;
    extern Vec3 lbl_8026B750;
    extern f32 lbl_80369224;
    extern f32 lbl_80369228;
    extern s32 lbl_8036C444;
    extern s32 lbl_8036C448;
    extern s32 lbl_80366DDC;
    f32 f20;
    f32 f24;
    u32 col2;
    u32 col1;
    Vec3 b;
    Vec3 a;
    u8 *p;
    s32 i;

    p = (u8 *)lbl_80366DDC;
    f20 = lbl_80369224;
    f24 = lbl_80369228;
    for (i = 8; i != 0; i--) {
        a = lbl_8026B744;
        *(f32 *)(p + 0x14) = a.x;
        *(f32 *)(p + 0x18) = a.y;
        *(f32 *)(p + 0x1C) = a.z;
        b = lbl_8026B750;
        *(f32 *)(p + 0x08) = b.x;
        *(f32 *)(p + 0x0C) = b.y;
        *(f32 *)(p + 0x10) = b.z;
        *(f32 *)(p + 0x20) = f20;
        col1 = lbl_8036C444;
        p[0] = ((u8 *)&col1)[0];
        p[1] = ((u8 *)&col1)[1];
        p[2] = ((u8 *)&col1)[2];
        p[3] = ((u8 *)&col1)[3];
        col2 = lbl_8036C448;
        p[4] = ((u8 *)&col2)[0];
        p[5] = ((u8 *)&col2)[1];
        p[6] = ((u8 *)&col2)[2];
        p[7] = ((u8 *)&col2)[3];
        *(f32 *)(p + 0x24) = f24;
        *(f32 *)(p + 0x28) = f24;
        p += 0x2C;
    }
}

#pragma optimization_level 3
void fn_80067058(void) {
    void fn_802029C4(void *, void *, f32 *);
    void fn_80202A18(void *, f32 *, f32 *);
    void fn_802031CC(void *, f32 *, f32);
    void fn_80221D6C(void *, f32, f32, f32, f32, f32, f32);
    void fn_80221D88(void *, s32, f32);
    void fn_80221F18(void *, s32, f32, f32);
    void fn_80221FE8(void *, f32, f32, f32);
    void fn_80221FF8(void *, f32, f32, f32);
    void fn_802220DC(void *, s32 *);
    void fn_802220E8(void *, s32);
    extern u8 *lbl_80366DDC;
    extern u8 *gCamera;
    extern f32 lbl_80369224;
    extern f32 lbl_80369228;
    extern f32 lbl_8036922C;
    extern f32 lbl_80369230;
    extern f32 lbl_80369234;
    extern f32 lbl_80369238;
    extern f32 lbl_8036923C;
    u8 mtx[0x44];
    f32 vec[3];
    f32 vec2[3];
    s32 color;
    u8 *lights;
    s32 i;

    lights = lbl_80366DDC;
    if (lights == NULL) {
        return;
    }
    for (i = 0; i < 8; i++, lights += 0x2C) {
        switch (i) {
        case 0:
        case 1:
            fn_802031CC(lights + 0x14, vec, lbl_8036922C);
            fn_80202A18(gCamera + 0xA4, vec, vec);
            fn_80221FE8(mtx, vec[0], vec[1], vec[2]);
            fn_80221F18(mtx, 0, lbl_80369228, lbl_80369230);
            fn_80221D88(mtx, 0, lbl_80369234);
            break;
        case 2:
        case 3:
            fn_80202A18(gCamera + 0xA4, (f32 *)(lights + 0x14), vec2);
            fn_80221FF8(mtx, vec2[0], vec2[1], vec2[2]);
            fn_80221F18(mtx, 0, lbl_80369228, lbl_80369230);
            fn_80221D88(mtx, 0, lbl_80369234);
            fn_80221D6C(mtx, lbl_80369228, lbl_80369228, lbl_80369224, lbl_80369238, lbl_80369228, lbl_8036923C);
            break;
        case 4:
        case 5:
        case 6:
        case 7:
            fn_802029C4(gCamera + 0xA4, lights + 8, vec);
            fn_80221FE8(mtx, vec[0], vec[1], vec[2]);
            fn_80221F18(mtx, 2, *(f32 *)(lights + 0x20), lbl_80369230);
            fn_80221D88(mtx, 0, lbl_80369234);
            break;
        }
        color = *(s32 *)(lights + 4);
        fn_802220DC(mtx, &color);
        fn_802220E8(mtx, 1 << i);
    }
}
#pragma optimization_level reset
void fn_8006720C(void *arg0) {
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXConcat(void *, void *, void *);
    void fn_802029C4(void *, void *, void *);
    extern void *lbl_80366DDC;
    extern f32 lbl_80369248;
    extern s32 lbl_8026B75C[];
    s32 vec[3];
    u8 m74[0x30];
    u8 m44[0x30];
    u8 m14[0x30];
    void *lights;
    s32 i;
    s32 *src;
    f32 scale;

    if ((lights = lbl_80366DDC) != NULL) {
        scale = lbl_80369248;
        i = 0;
        src = lbl_8026B75C + i;
        for (; i < 8; i++) {
            vec[0] = src[0];
            vec[1] = src[1];
            vec[2] = src[2];
            PSMTXRotRad(m44, 0x5A, scale * *(f32 *)((u8 *)lights + 0x28));
            PSMTXRotRad(m74, 0x59, scale * (-*(f32 *)((u8 *)lights + 0x24)));
            PSMTXConcat(m74, m44, m14);
            if (arg0 != NULL) {
                PSMTXConcat(arg0, m14, m14);
            }
            fn_802029C4(m14, vec, (u8 *)lights + 0x14);
            lights = (u8 *)lights + 0x2C;
        }
    }
}

#pragma global_optimizer off
void fn_80067304(void *arg0) {
    typedef struct { f32 x, y, z; } Vec3;
    extern Vec3 lbl_8026B744;
    extern Vec3 lbl_8026B750;
    extern f32 lbl_80369224;
    extern f32 lbl_80369228;
    extern s32 lbl_8036C444;
    extern s32 lbl_8036C448;
    Vec3 a;
    Vec3 b;
    f32 f20;
    f32 f24;
    u32 col1;
    u32 col2;

    a = lbl_8026B744;
    *(f32 *)((u8 *)arg0 + 0x14) = a.x;
    *(f32 *)((u8 *)arg0 + 0x18) = a.y;
    *(f32 *)((u8 *)arg0 + 0x1C) = a.z;

    f20 = lbl_80369224;
    f24 = lbl_80369228;

    b = lbl_8026B750;
    *(f32 *)((u8 *)arg0 + 0x08) = b.x;
    *(f32 *)((u8 *)arg0 + 0x0C) = b.y;
    *(f32 *)((u8 *)arg0 + 0x10) = b.z;
    *(f32 *)((u8 *)arg0 + 0x20) = f20;

    col1 = lbl_8036C444;
    ((u8 *)arg0)[0] = ((u8 *)&col1)[0];
    ((u8 *)arg0)[1] = ((u8 *)&col1)[1];
    ((u8 *)arg0)[2] = ((u8 *)&col1)[2];
    ((u8 *)arg0)[3] = ((u8 *)&col1)[3];

    col2 = lbl_8036C448;
    ((u8 *)arg0)[4] = ((u8 *)&col2)[0];
    ((u8 *)arg0)[5] = ((u8 *)&col2)[1];
    ((u8 *)arg0)[6] = ((u8 *)&col2)[2];
    ((u8 *)arg0)[7] = ((u8 *)&col2)[3];

    *(f32 *)((u8 *)arg0 + 0x24) = f24;
    *(f32 *)((u8 *)arg0 + 0x28) = f24;
}
#pragma global_optimizer reset
void Light_CopyChannel(void *arg0, void *arg1) {
    typedef struct { s32 x; s32 y; } Pair;
    Pair t;

    *(s32 *)((u8 *)arg1 + 0x00) = *(s32 *)((u8 *)arg0 + 0x00);
    *(s32 *)((u8 *)arg1 + 0x04) = *(s32 *)((u8 *)arg0 + 0x04);
    t = *(Pair *)((u8 *)arg0 + 0x08);
    *(Pair *)((u8 *)arg1 + 0x08) = t;
    *(s32 *)((u8 *)arg1 + 0x10) = *(s32 *)((u8 *)arg0 + 0x10);
    t = *(Pair *)((u8 *)arg0 + 0x14);
    *(Pair *)((u8 *)arg1 + 0x14) = t;
    *(s32 *)((u8 *)arg1 + 0x1C) = *(s32 *)((u8 *)arg0 + 0x1C);
    *(f32 *)((u8 *)arg1 + 0x20) = *(f32 *)((u8 *)arg0 + 0x20);
    *(f32 *)((u8 *)arg1 + 0x24) = *(f32 *)((u8 *)arg0 + 0x24);
    *(f32 *)((u8 *)arg1 + 0x28) = *(f32 *)((u8 *)arg0 + 0x28);
}

void *Light_GetChannel(s32 arg0) {
    extern void *lbl_80366DDC;
    if (lbl_80366DDC == NULL) {
        return NULL;
    }
    return (u8 *)lbl_80366DDC + arg0 * 0x2c;
}

#pragma scheduling off
void fn_80067460(void *arg0) {
 extern u8 lbl_80311B04[];
 extern void *lbl_80366DDC;
 if (arg0 == 0) arg0 = lbl_80311B04;
 lbl_80366DDC = arg0;
}
#pragma scheduling reset
s32 fn_80067478(void) {
    extern s32 lbl_80366DDC;
    return lbl_80366DDC;
}

void fn_80067480(void)
{
    extern void* lbl_80366DD4;
    *(u8*)lbl_80366DD4 = 0;
}

void fn_80067490(s32 type) {
    void fn_802240F0(s32,s32 *,f32,f32,f32,f32);
    void fn_80224304(void *,s32,void *);
    void fn_802244B4(s32,s32,void *);
    extern u8 *lbl_80366DD4;
    extern u8 lbl_80366DD8;
    extern u8 *gCamera;
    extern s32 lbl_80285E70[],lbl_80369220,lbl_8036C440;
    extern f32 lbl_80369240,lbl_80369234,lbl_80369224,lbl_80369244;
    u16 buf[10];
    s32 color;
    s32 clear;
    s32 copy;
    u8 *cam;
    u8 *fog=lbl_80366DD4;
    switch(type) {
    case 7:
        if(lbl_80366DD8==6) return;
        type=fog[0]; lbl_80366DD8=8; break;
    case 8:
        type=fog[0]; lbl_80366DD8=8; break;
    case 6:
        type=0; lbl_80366DD8=6; break;
    }
    if(type==0) {
        clear=lbl_8036C440;
        fn_802240F0(0,&clear,lbl_80369240,lbl_80369234,lbl_80369224,lbl_80369244);
        fn_802244B4(0,0,0);
    } else {
        color=lbl_80369220;
        ((u8 *)&color)[0]=fog[1];
        ((u8 *)&color)[1]=fog[2];
        ((u8 *)&color)[2]=fog[3];
        cam=gCamera;
        copy=color;
        fn_802240F0(lbl_80285E70[type],&copy,*(f32 *)(fog+4),*(f32 *)(fog+8),*(f32 *)(cam+0x180),*(f32 *)(cam+0x184));
        fn_80224304(buf,0x280,cam+0x24);
        fn_802244B4(1,0x140,buf);
    }
}

#pragma peephole off
void fn_800675C8(void *arg0) {
 extern u8 lbl_80311AF8[];
 extern void *lbl_80366DD4;
 if (arg0 == 0) arg0 = lbl_80311AF8;
 lbl_80366DD4 = arg0;
}
#pragma peephole on
s32 Fog_GetColor(void) {
    extern s32 lbl_80366DD4;
    return lbl_80366DD4;
}

void fn_800675E8(void *arg0) {
    void GXSetScissor(u16, u16, u16, u16);
    void GXSetViewport(f32, f32, f32, f32, f32, f32);
    void GXSetProjection(void *, s32);
    void fn_800661A8(void *);

    extern void *gCamera;

    u8 *cam;
    u8 *resetCam;
    u32 flags;

    cam = (u8 *)arg0;

    if (cam == NULL) {
        cam = (u8 *)gCamera;
    }

    if (cam == NULL) {
        return;
    }

    gCamera = cam;

    if (cam != NULL) {
        GXSetScissor(
            *(u16 *)(cam + 0x1C),
            *(u16 *)(cam + 0x1E),
            *(u16 *)(cam + 0x20),
            *(u16 *)(cam + 0x22)
        );

        GXSetViewport(
            *(f32 *)(cam + 4),
            *(f32 *)(cam + 8),
            *(f32 *)(cam + 0xC),
            *(f32 *)(cam + 0x10),
            *(f32 *)(cam + 0x14),
            *(f32 *)(cam + 0x18)
        );

        flags = *(u16 *)cam & 1;
        GXSetProjection(cam + 0x24, flags ^ 1);
    }

    fn_800661A8(cam);

    resetCam = cam;

    if (resetCam == NULL) {
        resetCam = (u8 *)gCamera;
    }

    if (resetCam != NULL) {
        *(u16 *)(resetCam + 0x118) = 0;

        *(u32 *)(resetCam + 0x11C) = 0;
        *(u32 *)(resetCam + 0x130) = 0;
        *(u32 *)(resetCam + 0x144) = 0;
        *(u32 *)(resetCam + 0x158) = 0;
        *(u32 *)(resetCam + 0x16C) = 0;

        *(u32 *)(resetCam + 0x120) = 0;
        *(u32 *)(resetCam + 0x134) = 0;
        *(u32 *)(resetCam + 0x148) = 0;
        *(u32 *)(resetCam + 0x15C) = 0;
        *(u32 *)(resetCam + 0x170) = 0;

        *(u32 *)(resetCam + 0x124) = 0;
        *(u32 *)(resetCam + 0x138) = 0;
        *(u32 *)(resetCam + 0x14C) = 0;
        *(u32 *)(resetCam + 0x160) = 0;
        *(u32 *)(resetCam + 0x174) = 0;

        *(u32 *)(resetCam + 0x128) = 0;
        *(u32 *)(resetCam + 0x13C) = 0;
        *(u32 *)(resetCam + 0x150) = 0;
        *(u32 *)(resetCam + 0x164) = 0;
        *(u32 *)(resetCam + 0x178) = 0;

        *(u32 *)(resetCam + 0x12C) = 0;
        *(u32 *)(resetCam + 0x140) = 0;
        *(u32 *)(resetCam + 0x154) = 0;
        *(u32 *)(resetCam + 0x168) = 0;
        *(u32 *)(resetCam + 0x17C) = 0;
    }

    cam[3]++;
}

#pragma use_lmw_stmw on
void fn_80067708(s32 arg0, s32 arg1, void *arg2, void *arg3) {
    void Game_Assert(void *, s32, void *);
    extern void *gCamera;
    extern u8 lbl_8026B768[];
    s32 idx = arg1;
    void *cb1 = arg2;
    s32 kind = arg0;
    void *cb2 = arg3;
    u8 *cam = (u8 *)gCamera;
    u16 index = *(u16 *)(cam + 0x118);
    u8 *buf = *(u8 **)(cam + 0x114);
    u8 *entry;
    u8 **head;
    u8 *node;

    *(u16 *)(cam + 0x118) = index + 1;
    entry = buf + ((u16)index << 4);

    if (*(u16 *)(cam + 0x118) > *(u16 *)(cam + 0x11A)) {
        Game_Assert(lbl_8026B768, 0x158, lbl_8026B768 + 0xA);
    }

    switch (kind) {
    case 3:
        head = (u8 **)((u8 *)gCamera + 0x158 + (idx << 2));
        break;
    case 0:
        head = (u8 **)((u8 *)gCamera + 0x11c + (idx << 2));
        break;
    case 1:
        head = (u8 **)((u8 *)gCamera + 0x130 + (idx << 2));
        break;
    case 2:
        head = (u8 **)((u8 *)gCamera + 0x144 + (idx << 2));
        break;
    case 4:
        head = (u8 **)((u8 *)gCamera + 0x16c + (idx << 2));
        break;
    default:
        Game_Assert(lbl_8026B768, 0x161, lbl_8026B768 + 0x50);
        break;
    }

    node = *head;
    if (node == NULL) {
        *(u8 **)entry = node;
        *head = entry;
    } else {
        while (*(u8 **)node != NULL) {
            node = *(u8 **)node;
        }
        *(u8 **)node = entry;
    }
    *(u32 *)entry = 0;
    *(void **)(entry + 8) = cb1;
    *(void **)(entry + 0xC) = cb2;
}
#pragma use_lmw_stmw reset
void fn_8006785C(s32 arg0, void *arg1, void *arg2) {
    void Game_Assert(void *, s32, void *);
    extern void *gCamera;
    extern u8 lbl_8026B768[];
    void *cb1 = arg1;
    void *cb2 = arg2;
    s32 kind = arg0;
    u8 *cam = (u8 *)gCamera;
    u16 index = *(u16 *)(cam + 0x118);
    u8 *buf = *(u8 **)(cam + 0x114);
    u8 *entry;
    u8 **head;
    u8 *node;

    *(u16 *)(cam + 0x118) = index + 1;
    entry = buf + ((u16)index << 4);

    if (*(u16 *)(cam + 0x118) > *(u16 *)(cam + 0x11A)) {
        Game_Assert(lbl_8026B768, 0x158, lbl_8026B768 + 0xA);
    }

    switch (kind) {
    case 3:
        head = (u8 **)((u8 *)gCamera + 0x160);
        break;
    case 0:
        head = (u8 **)((u8 *)gCamera + 0x124);
        break;
    case 1:
        head = (u8 **)((u8 *)gCamera + 0x138);
        break;
    case 2:
        head = (u8 **)((u8 *)gCamera + 0x14C);
        break;
    case 4:
        head = (u8 **)((u8 *)gCamera + 0x174);
        break;
    default:
        Game_Assert(lbl_8026B768, 0x161, lbl_8026B768 + 0x50);
        break;
    }

    node = *head;
    if (node == NULL) {
        *(u8 **)entry = node;
        *head = entry;
    } else {
        while (*(u8 **)node != NULL) {
            node = *(u8 **)node;
        }
        *(u8 **)node = entry;
    }
    *(u32 *)entry = 0;
    *(void **)(entry + 8) = cb1;
    *(void **)(entry + 0xC) = cb2;
}

#pragma global_optimizer off
void fn_80067984(void *camIn) {
    void fn_80202A6C(void *, s32, f32, f32, f32, f32);
    void C_MTXOrtho(void *, s32, f32, f32, f32, f32, f32, f32);
    void PSMTXIdentity(void *);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    void fn_802026E4(void *, void *, void *, void *);
    void PSMTXCopy(void *, void *);
    void fn_80202C18(void *, void *, void *);
    void GXSetScissor(u16, u16, u16, u16);
    void GXSetViewport(f32, f32, f32, f32, f32, f32);
    void GXSetProjection(void *, s32);
    extern void *gCamera;
    extern u8 gCameraProjMode;
    extern f32 lbl_80369228;
    extern f32 lbl_80369224;
    extern f32 gScreenWidthF;
    extern f32 gScreenHeightF;
    extern f32 gOrthoFarZ;
    f32 posPersp[12];
    f32 posOrtho[12];
    f32 view[16];
    f32 f_near;
    f32 f_h;
    f32 f_w;
    f32 f_zero;
    u8 *cam;
    s32 negFlag;
    u8 mode;

    f_zero = lbl_80369228;
    f_w = gScreenWidthF;
    f_h = gScreenHeightF;
    f_near = lbl_80369224;
    *(f32 *)((u8 *)gCamera + 4) = f_zero;
    *(f32 *)((u8 *)gCamera + 8) = f_zero;
    *(f32 *)((u8 *)gCamera + 0xC) = f_w;
    *(f32 *)((u8 *)gCamera + 0x10) = f_h;
    *(f32 *)((u8 *)gCamera + 0x14) = f_zero;
    *(f32 *)((u8 *)gCamera + 0x18) = f_near;
    *(u16 *)((u8 *)gCamera + 0x1C) = 0;
    *(u16 *)((u8 *)gCamera + 0x1E) = 0;
    *(u16 *)((u8 *)gCamera + 0x20) = 0x260;
    *(u16 *)((u8 *)gCamera + 0x22) = 0x1C0;

    mode = gCameraProjMode;
    if ((s8)mode != 0) {
        if (!camIn) {
            camIn = gCamera;
        }
        if (camIn) {
            switch ((s8)mode) {
            case 1:
                cam = camIn;
                if (!camIn) {
                    cam = gCamera;
                }
                if (cam) {
                    negFlag = -(*(u16 *)cam & 1);
                    gCameraProjMode = negFlag + 2;
                    fn_80202A6C(cam + 0x24, negFlag, *(f32 *)(cam + 0x18C), *(f32 *)(cam + 0x188),
                                *(f32 *)(cam + 0x180), *(f32 *)(cam + 0x184));
                    *(u16 *)cam |= 1;
                    PSMTXIdentity(posPersp);
                    GXLoadPosMtxImm(posPersp, 0);
                    GXSetCurrentMtx(0);
                    fn_802026E4((u8 *)gCamera + 0xA4, cam + 0xD4, cam + 0xEC, cam + 0xE0);
                    PSMTXCopy((u8 *)gCamera + 0xA4, view);
                    view[12] = lbl_80369228;
                    view[13] = lbl_80369228;
                    view[14] = lbl_80369228;
                    view[15] = lbl_80369224;
                    fn_80202C18((u8 *)gCamera + 0x24, view, (u8 *)gCamera + 0x64);
                    if (!cam) {
                        cam = gCamera;
                    }
                    if (cam) {
                        GXSetScissor(*(u16 *)(cam + 0x1C), *(u16 *)(cam + 0x1E), *(u16 *)(cam + 0x20),
                                     *(u16 *)(cam + 0x22));
                        GXSetViewport(*(f32 *)(cam + 4), *(f32 *)(cam + 8), *(f32 *)(cam + 0xC),
                                      *(f32 *)(cam + 0x10), *(f32 *)(cam + 0x14), *(f32 *)(cam + 0x18));
                        GXSetProjection(cam + 0x24, (*(u16 *)cam & 1) ^ 1);
                    }
                }
                break;
            case 2:
                cam = camIn;
                if (!camIn) {
                    cam = gCamera;
                }
                if (cam) {
                    negFlag = -(*(u16 *)cam & 1);
                    gCameraProjMode = negFlag + 2;
                    C_MTXOrtho(cam + 0x24, negFlag, lbl_80369228, gScreenHeightF, lbl_80369228,
                               gScreenWidthF, lbl_80369228, gOrthoFarZ);
                    *(u16 *)cam &= 0xFFFE;
                    PSMTXIdentity(posOrtho);
                    GXLoadPosMtxImm(posOrtho, 0);
                    GXSetCurrentMtx(0);
                    PSMTXIdentity(cam + 0xA4);
                    if (!cam) {
                        cam = gCamera;
                    }
                    if (cam) {
                        GXSetScissor(*(u16 *)(cam + 0x1C), *(u16 *)(cam + 0x1E), *(u16 *)(cam + 0x20),
                                     *(u16 *)(cam + 0x22));
                        GXSetViewport(*(f32 *)(cam + 4), *(f32 *)(cam + 8), *(f32 *)(cam + 0xC),
                                      *(f32 *)(cam + 0x10), *(f32 *)(cam + 0x14), *(f32 *)(cam + 0x18));
                        GXSetProjection(cam + 0x24, (*(u16 *)cam & 1) ^ 1);
                    }
                }
                break;
            }
        }
        gCameraProjMode = 0;
    }
}
#pragma global_optimizer reset
void fn_80067C48(void *camIn, f32 farg0, f32 farg1) {
    void C_MTXOrtho(void *, s32, f32, f32, f32, f32, f32, f32);
    void PSMTXIdentity(void *);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    void GXSetScissor(u16, u16, u16, u16);
    void GXSetViewport(f32, f32, f32, f32, f32, f32);
    void GXSetProjection(void *, s32);
    void fn_802026E4(void *, void *, void *, void *);
    void PSMTXCopy(void *, void *);
    void fn_80202C18(void *, void *, void *);
    extern u8 *gCamera;
    extern u8 gCameraProjMode;
    extern f32 lbl_80369230, lbl_80369228, lbl_80369224;
    f32 posMtx[12];
    f32 view[16];
    u8 *cam2;
    u8 *cam;
    s32 negFlag;

    cam = camIn;
    if (cam == NULL) {
        cam = gCamera;
    }
    if (cam != NULL) {
        negFlag = -(*(u16 *)cam & 1);
        gCameraProjMode = negFlag + 2;
        C_MTXOrtho(cam + 0x24, negFlag, farg1 * lbl_80369230, -farg1 * lbl_80369230,
                   -farg0 * lbl_80369230, farg0 * lbl_80369230, *(f32 *)(cam + 0x180),
                   *(f32 *)(cam + 0x184));
        *(u16 *)cam &= 0xFFFE;
        PSMTXIdentity(posMtx);
        GXLoadPosMtxImm(posMtx, 0);
        GXSetCurrentMtx(0);
        cam2 = cam;
        if (cam == NULL) {
            cam2 = gCamera;
        }
        if (cam2 != NULL) {
            GXSetScissor(*(u16 *)(cam2 + 0x1C), *(u16 *)(cam2 + 0x1E), *(u16 *)(cam2 + 0x20),
                         *(u16 *)(cam2 + 0x22));
            GXSetViewport(*(f32 *)(cam2 + 4), *(f32 *)(cam2 + 8), *(f32 *)(cam2 + 0xC),
                          *(f32 *)(cam2 + 0x10), *(f32 *)(cam2 + 0x14), *(f32 *)(cam2 + 0x18));
            GXSetProjection(cam2 + 0x24, (*(u16 *)cam2 & 1) ^ 1);
        }
        fn_802026E4(gCamera + 0xA4, cam + 0xD4, cam + 0xEC, cam + 0xE0);
        PSMTXCopy(gCamera + 0xA4, view);
        view[12] = lbl_80369228;
        view[13] = lbl_80369228;
        view[14] = lbl_80369228;
        view[15] = lbl_80369224;
        fn_80202C18(gCamera + 0x24, view, gCamera + 0x64);
    }
}

void fn_80067DA4(void *camIn) {
    void fn_80202A6C(void *,s32,f32,f32,f32,f32);
    void PSMTXIdentity(void *);
    void GXLoadPosMtxImm(void *,s32);
    void GXSetCurrentMtx(s32);
    void fn_802026E4(void *,void *,void *,void *);
    void PSMTXCopy(void *,void *);
    void fn_80202C18(void *,void *,void *);
    void GXSetScissor(u16,u16,u16,u16);
    void GXSetViewport(f32,f32,f32,f32,f32,f32);
    void GXSetProjection(void *,s32);
    extern u8 *gCamera;
    extern u8 gCameraProjMode;
    extern f32 lbl_80369228,lbl_80369224;
    f32 posMtx[12];
    f32 view[16];
    s32 negFlag;
    u8 *cam=camIn;
    if(!cam) cam=gCamera;
    if(!cam) return;
    negFlag=-(*(u16 *)cam & 1);
    gCameraProjMode=negFlag+2;
    fn_80202A6C(cam+0x24,negFlag,*(f32 *)(cam+0x18C),*(f32 *)(cam+0x188),*(f32 *)(cam+0x180),*(f32 *)(cam+0x184));
    *(u16 *)cam |= 1;
    PSMTXIdentity(posMtx);
    GXLoadPosMtxImm(posMtx,0);
    GXSetCurrentMtx(0);
    fn_802026E4(gCamera+0xA4,cam+0xD4,cam+0xEC,cam+0xE0);
    PSMTXCopy(gCamera+0xA4,view);
    view[12]=lbl_80369228;
    view[13]=lbl_80369228;
    view[14]=lbl_80369228;
    view[15]=lbl_80369224;
    fn_80202C18(gCamera+0x24,view,gCamera+0x64);
    if(!cam) cam=gCamera;
    if(!cam) return;
    GXSetScissor(*(u16 *)(cam+0x1C),*(u16 *)(cam+0x1E),*(u16 *)(cam+0x20),*(u16 *)(cam+0x22));
    GXSetViewport(*(f32 *)(cam+4),*(f32 *)(cam+8),*(f32 *)(cam+0xC),*(f32 *)(cam+0x10),*(f32 *)(cam+0x14),*(f32 *)(cam+0x18));
    GXSetProjection(cam+0x24,(*(u16 *)cam & 1)^1);
}

// Build default 640x480 ortho, reset view/pos matrices, and apply camera scissor/viewport/projection to GX.
void Camera_ApplyOrtho(void *camIn)
{
    void C_MTXOrtho(void *, s32, f32, f32, f32, f32, f32, f32);
    void PSMTXIdentity(void *);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    void GXSetScissor(u16, u16, u16, u16);
    void GXSetViewport(f32, f32, f32, f32, f32, f32);
    void GXSetProjection(void *, s32);
    extern void *gCamera;
    extern u8 gCameraProjMode;
    extern f32 lbl_80369228;
    extern f32 gScreenHeightF;
    extern f32 gScreenWidthF;
    extern f32 gOrthoFarZ;
    f32 posMtx[12];
    u8 *cam;
    s32 flagBit;
    s32 negFlag;
    f32 zero;

    cam = camIn;
    if (cam == NULL) {
        cam = gCamera;
    }
    if (cam == NULL) {
        return;
    }
    flagBit = *(u16 *)cam & 1;
    negFlag = -flagBit;
    gCameraProjMode = negFlag + 2;
    zero = lbl_80369228;
    C_MTXOrtho(cam + 0x24, negFlag, zero, gScreenHeightF, zero, gScreenWidthF, zero, gOrthoFarZ);
    *(u16 *)cam &= 0xFFFE;
    PSMTXIdentity(posMtx);
    GXLoadPosMtxImm(posMtx, 0);
    GXSetCurrentMtx(0);
    PSMTXIdentity(cam + 0xA4);
    if (cam == NULL) {
        cam = gCamera;
    }
    if (cam == NULL) {
        return;
    }
    GXSetScissor(*(u16 *)(cam + 0x1C), *(u16 *)(cam + 0x1E), *(u16 *)(cam + 0x20), *(u16 *)(cam + 0x22));
    GXSetViewport(*(f32 *)(cam + 4), *(f32 *)(cam + 8), *(f32 *)(cam + 0xC), *(f32 *)(cam + 0x10), *(f32 *)(cam + 0x14), *(f32 *)(cam + 0x18));
    GXSetProjection(cam + 0x24, (*(u16 *)cam & 1) ^ 1);
}

void *fn_80067FD0(void) {
    extern void *gCamera;
    return (u8 *)gCamera + 0x64;
}

s32 Camera_GetViewMtx(void) {
    extern void *gCamera;
    return (s32)((u8 *)gCamera + 0xA4);
}

void fn_80067FE8(void *arg0, void *arg1, void *arg2) {
    void fn_802026E4(void *, void *, void *, void *);
    void PSMTXCopy(void *, void *);
    void fn_80202C18(void *, void *, void *);
    extern void *gCamera;
    extern f32 lbl_80369228;
    extern f32 lbl_80369224;
    f32 buf[16];
    u8 *p;
    f32 x;
    f32 y;

    fn_802026E4((u8 *)gCamera + 0xA4, arg0, arg1, arg2);
    PSMTXCopy((u8 *)gCamera + 0xA4, buf);
    x = lbl_80369228;
    p = gCamera;
    y = lbl_80369224;
    buf[12] = x;
    buf[13] = x;
    buf[14] = x;
    buf[15] = y;
    fn_80202C18(p + 0x24, buf, p + 0x64);
}

void fn_8006805C(f32 arg0, f32 arg1) {
    extern void *gCamera;

    *(f32 *)((u8 *)gCamera + 0x180) = arg0;
    *(f32 *)((u8 *)gCamera + 0x184) = arg1;
}

#pragma global_optimizer off
void fn_80068070(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    extern f32 *gCamera;
    extern f32 lbl_80369228;
    extern f32 lbl_80369224;
    f32 *p;
    f32 y;
    f32 x;

    p = gCamera;
    x = lbl_80369228;
    p[1] = arg0;
    y = lbl_80369224;
    gCamera[2] = arg1;
    gCamera[3] = arg2;
    gCamera[4] = arg3;
    gCamera[5] = x;
    gCamera[6] = y;
}
#pragma global_optimizer reset
void fn_800680AC(u16 arg0, u16 arg1, u16 arg2, u16 arg3) {
    extern void *gCamera;

    *(u16 *)((u8 *)gCamera + 0x1C) = arg0;
    *(u16 *)((u8 *)gCamera + 0x1E) = arg1;
    *(u16 *)((u8 *)gCamera + 0x20) = arg2;
    *(u16 *)((u8 *)gCamera + 0x22) = arg3;
}

void fn_800680D0(void *arg0, u8 arg1)
{
    void fn_80202BD4(void *, void *);
    extern u32 gCamera;

    u8 *ptr;
    u16 flags;

    if (arg1 != 0) {
        ptr = (u8 *)gCamera;
        flags = *(u16 *)ptr;
        flags |= 1;
        *(u16 *)ptr = flags;
    } else {
        ptr = (u8 *)gCamera;
        flags = *(u16 *)ptr;
        flags &= ~1;
        *(u16 *)ptr = (unsigned)flags;
    }

    ptr = (u8 *)gCamera;
    fn_80202BD4(arg0, ptr + 0x24);
}

void fn_80068124(void *source, void *dest) {
    void fn_80202BD4(void *,void *);
    void PSMTXCopy(void *,void *);
    M2C_FIELD(dest,u16 *,0x0)=M2C_FIELD(source,u16 *,0x0);
    M2C_FIELD(dest,u8 *,0x2)=M2C_FIELD(source,u8 *,0x2);
    M2C_FIELD(dest,u8 *,0x3)=M2C_FIELD(source,u8 *,0x3);
    M2C_FIELD(dest,f32 *,0x4)=M2C_FIELD(source,f32 *,0x4);
    M2C_FIELD(dest,f32 *,0x8)=M2C_FIELD(source,f32 *,0x8);
    M2C_FIELD(dest,f32 *,0xc)=M2C_FIELD(source,f32 *,0xc);
    M2C_FIELD(dest,f32 *,0x10)=M2C_FIELD(source,f32 *,0x10);
    M2C_FIELD(dest,f32 *,0x14)=M2C_FIELD(source,f32 *,0x14);
    M2C_FIELD(dest,f32 *,0x18)=M2C_FIELD(source,f32 *,0x18);
    M2C_FIELD(dest,u16 *,0x1c)=M2C_FIELD(source,u16 *,0x1c);
    M2C_FIELD(dest,u16 *,0x1e)=M2C_FIELD(source,u16 *,0x1e);
    M2C_FIELD(dest,u16 *,0x20)=M2C_FIELD(source,u16 *,0x20);
    M2C_FIELD(dest,u16 *,0x22)=M2C_FIELD(source,u16 *,0x22);
    fn_80202BD4((u8 *)source+0x24,(u8 *)dest+0x24);
    fn_80202BD4((u8 *)source+0x64,(u8 *)dest+0x64);
    PSMTXCopy((u8 *)source+0xA4,(u8 *)dest+0xA4);
    M2C_FIELD(dest,f32 *,0xd4)=M2C_FIELD(source,f32 *,0xd4);
    M2C_FIELD(dest,f32 *,0xd8)=M2C_FIELD(source,f32 *,0xd8);
    M2C_FIELD(dest,f32 *,0xdc)=M2C_FIELD(source,f32 *,0xdc);
    M2C_FIELD(dest,f32 *,0xe0)=M2C_FIELD(source,f32 *,0xe0);
    M2C_FIELD(dest,f32 *,0xe4)=M2C_FIELD(source,f32 *,0xe4);
    M2C_FIELD(dest,f32 *,0xe8)=M2C_FIELD(source,f32 *,0xe8);
    M2C_FIELD(dest,f32 *,0xec)=M2C_FIELD(source,f32 *,0xec);
    M2C_FIELD(dest,f32 *,0xf0)=M2C_FIELD(source,f32 *,0xf0);
    M2C_FIELD(dest,f32 *,0xf4)=M2C_FIELD(source,f32 *,0xf4);
    M2C_FIELD(dest,f32 *,0xf8)=M2C_FIELD(source,f32 *,0xf8);
    M2C_FIELD(dest,f32 *,0xfc)=M2C_FIELD(source,f32 *,0xfc);
    M2C_FIELD(dest,f32 *,0x100)=M2C_FIELD(source,f32 *,0x100);
    M2C_FIELD(dest,f32 *,0x104)=M2C_FIELD(source,f32 *,0x104);
    M2C_FIELD(dest,f32 *,0x180)=M2C_FIELD(source,f32 *,0x180);
    M2C_FIELD(dest,f32 *,0x184)=M2C_FIELD(source,f32 *,0x184);
    M2C_FIELD(dest,f32 *,0x18c)=M2C_FIELD(source,f32 *,0x18c);
    M2C_FIELD(dest,f32 *,0x188)=M2C_FIELD(source,f32 *,0x188);
}

void *fn_8006826C(s32 arg0) {
    typedef struct { f32 x,y,z; } CameraVec;
    void *fn_800C4638(s32, void *, s32);
    void fn_802026E4(void *,void *,void *,void *);
    void PSMTXCopy(void *,void *);
    void fn_80202C18(void *,void *,void *);
    void fn_80202A6C(void *,f32,f32,f32,f32);
    void fn_80202BD4(void *,void *);
    extern u8 lbl_8026B768[];
    extern CameraVec lbl_8026B720[];
    extern void *gCamera;
    f32 proj[16];
    f32 view[16];
    CameraVec a,b,c;
    u8 *resetCam;
    u8 *cam;
    CameraVec *defaults;
    defaults=lbl_8026B720;
    cam=fn_800C4638(0x190,lbl_8026B768+0x88,0);
    gCamera=cam;
    *(u16 *)cam=2;
    cam[3]=0;
    M2C_FIELD(gCamera, u16 *, 28)=0;
    M2C_FIELD(gCamera, u16 *, 30)=0;
    M2C_FIELD(gCamera, u16 *, 32)=0x260;
    M2C_FIELD(gCamera, u16 *, 34)=0x1C0;
    M2C_FIELD(gCamera, f32 *, 4)=0.0f;
    M2C_FIELD(gCamera, f32 *, 8)=0.0f;
    M2C_FIELD(gCamera, f32 *, 12)=640.0f;
    M2C_FIELD(gCamera, f32 *, 16)=480.0f;
    M2C_FIELD(gCamera, f32 *, 20)=0.0f;
    M2C_FIELD(gCamera, f32 *, 24)=1.0f;
    M2C_FIELD(gCamera, f32 *, 384)=1.0f;
    M2C_FIELD(gCamera, f32 *, 388)=1000.0f;
    a=*defaults++;
    *(f32 *)(cam+212)=a.x;
    *(f32 *)(cam+216)=a.y;
    *(f32 *)(cam+220)=a.z;
    b=*defaults++;
    *(f32 *)(cam+224)=b.x;
    *(f32 *)(cam+228)=b.y;
    *(f32 *)(cam+232)=b.z;
    c=*defaults;
    *(f32 *)(cam+236)=c.x;
    *(f32 *)(cam+240)=c.y;
    *(f32 *)(cam+244)=c.z;
    *(f32 *)(cam+0xF8)=80.0f;
    *(f32 *)(cam+0xFC)=0.0f;
    *(f32 *)(cam+0x100)=0.0f;
    *(f32 *)(cam+0x104)=0.0f;
    *(f32 *)(cam+0x18C)=30.0f;
    *(f32 *)(cam+0x188)=*(f32 *)(cam+0xC) / *(f32 *)(cam+0x10);
    fn_802026E4((u8 *)gCamera+0xA4,cam+0xD4,cam+0xEC,cam+0xE0);
    PSMTXCopy((u8 *)gCamera+0xA4,view);
    view[12]=0.0f; view[13]=0.0f; view[14]=0.0f; view[15]=1.0f;
    fn_80202C18((u8 *)gCamera+0x24,view,(u8 *)gCamera+0x64);
    fn_80202A6C(proj,*(f32 *)(cam+0x18C),*(f32 *)(cam+0x188),*(f32 *)(cam+0x180),*(f32 *)(cam+0x184));
    *(u16 *)gCamera |=1;
    fn_80202BD4(proj,(u8 *)gCamera+0x24);
    *(void **)(cam+0x114)=fn_800C4638(arg0*16,lbl_8026B768+(unsigned)0x88,0);
    resetCam=cam;
    *(s16 *)(cam+0x11A)=arg0;
    if(resetCam==NULL) resetCam=gCamera;
    if(resetCam!=NULL) {
    *(u16 *)(resetCam+0x118)=0;
    *(u32 *)(resetCam+284)=0;
    *(u32 *)(resetCam+304)=0;
    *(u32 *)(resetCam+324)=0;
    *(u32 *)(resetCam+344)=0;
    *(u32 *)(resetCam+364)=0;
    *(u32 *)(resetCam+288)=0;
    *(u32 *)(resetCam+308)=0;
    *(u32 *)(resetCam+328)=0;
    *(u32 *)(resetCam+348)=0;
    *(u32 *)(resetCam+368)=0;
    *(u32 *)(resetCam+292)=0;
    *(u32 *)(resetCam+312)=0;
    *(u32 *)(resetCam+332)=0;
    *(u32 *)(resetCam+352)=0;
    *(u32 *)(resetCam+372)=0;
    *(u32 *)(resetCam+296)=0;
    *(u32 *)(resetCam+316)=0;
    *(u32 *)(resetCam+336)=0;
    *(u32 *)(resetCam+356)=0;
    *(u32 *)(resetCam+376)=0;
    *(u32 *)(resetCam+300)=0;
    *(u32 *)(resetCam+320)=0;
    *(u32 *)(resetCam+340)=0;
    *(u32 *)(resetCam+360)=0;
    *(u32 *)(resetCam+380)=0;
    }
    return cam;
}

s32 Camera_Get(void) {
    extern void *gCamera;
    return (s32)gCamera;
}

void fn_80068550(s32 arg0) {
    extern void *gCamera;
    gCamera = (void *)arg0;
}

#pragma use_lmw_stmw on
void fn_80068558(void *arg0, void *arg1, void *arg2)
{
    void *Res_GetByName(void *);
    void fn_800C4588(void *);
    s32 Str_Cmp(void *, void *);
    s32 i;
    void *entry;
    void *found;
    s32 j;
    void **arr;
    void **p;
    s32 k;
    s32 off;
    s32 n;

    found = NULL;
    if (arg0 != NULL && arg1 == NULL) {
        i = 0;
        j = 0;
        while (i < *(u16 *)((u8 *)arg0 + 0x54)) {
            entry = (u8 *)*(void **)((u8 *)arg0 + 0x34) + j;
            arr = *(void ***)((u8 *)entry + 0x18);
            if (arr != NULL) {
                if (arg2 != NULL) {
                    p = arr;
                    k = 0;
                    off = 0;
                    for (; k < 8; k++) {
                        if (*p == arg2) {
                            off = k * 4;
                            n = 7 - k;
                            if (k < 7) {
                                while (n != 0) {
                                    arr = *(void ***)((u8 *)entry + 0x18);
                                    *(void **)((u8 *)arr + off) = *(void **)((u8 *)arr + off + 4);
                                    off += 4;
                                    n -= 1;
                                }
                            }
                            *(void **)((u8 *)*(void **)((u8 *)entry + 0x18) + 0x1C) = NULL;
                            break;
                        }
                        p++;
                        off += 4;
                    }
                } else {
                    fn_800C4588(*(void **)((u8 *)entry + 0x18));
                    *(void **)((u8 *)entry + 0x18) = NULL;
                    *(void **)((u8 *)entry + 0x18) = NULL;
                    *(void **)((u8 *)entry + 0x18) = NULL;
                    *(u16 *)((u8 *)entry + 4) = *(u16 *)((u8 *)entry + 4) & 0x3FFF;
                }
            }
            j += 0x20;
            i += 1;
        }
    } else {
        if (arg0 == NULL) {
            found = Res_GetByName(arg1);
        } else {
            i = 0;
            j = i;
            while (i < *(u16 *)((u8 *)arg0 + 0x54)) {
                if (Str_Cmp(*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x34) + j), arg1) == 0) {
                    found = (u8 *)*(void **)((u8 *)arg0 + 0x34) + (i << 5);
                    break;
                }
                j += 0x20;
                i += 1;
            }
        }
        if (found != NULL && (arr = *(void ***)((u8 *)found + 0x18), arr != NULL)) {
            if (arg2 != NULL) {
                p = arr;
                for (k = 0; k < 8; k++) {
                    if (*p == arg2) {
                        off = k * 4;
                        n = 7 - k;
                        if (k < 7) {
                            while (n != 0) {
                                arr = *(void ***)((u8 *)found + 0x18);
                                *(void **)((u8 *)arr + off) = *(void **)((u8 *)arr + off + 4);
                                off += 4;
                                n -= 1;
                            }
                        }
                        *(void **)((u8 *)*(void **)((u8 *)found + 0x18) + 0x1C) = NULL;
                        break;
                    }
                    p++;
                }
            } else {
                fn_800C4588(arr);
                *(void **)((u8 *)found + 0x18) = NULL;
                *(void **)((u8 *)found + 0x18) = NULL;
                *(void **)((u8 *)found + 0x18) = NULL;
                *(u16 *)((u8 *)found + 4) = *(u16 *)((u8 *)found + 4) & 0x3FFF;
            }
        }
    }
}

#pragma opt_loop_invariants off
#pragma use_lmw_stmw on
s32 fn_800688D4(void *arg0, void *arg1,u32 arg2,s32 arg3) {
void *Res_GetByName(void*);void *fn_800C4638(s32,void*,s32);s32 Str_Cmp(void*,void*);
extern u8 gGMaterialAssertMsg[];
s32 i,off,j;
u32 value;
u32 *slots;
u8 *entry,*found;
found=0;
if(arg0 && !arg1){
for(i=0,off=0;i<*(u16*)((u8*)arg0+0x54);i++,off+=32){
entry=*(u8**)((u8*)arg0+0x34)+off;
if(arg2) {
if(!*(u32**)(entry+0x18)){
*(u32**)(entry+0x18)=fn_800C4638(32,gGMaterialAssertMsg,0);
for(j=0;j<8;j++) (*(u32**)(entry+0x18))[j]=0;
}
slots=*(u32**)(entry+0x18);
for(j=0;j<8;j++){
value=slots[j];if(value==arg2)break;
if(!value){slots[j]=arg2;break;}
}
*(u16*)(entry+4)|=arg3&0xc000;
}
}
return 1;
}
if(!arg0)found=Res_GetByName(arg1);
else for(i=0,off=0;i<*(u16*)((u8*)arg0+0x54);i++,off+=32){
if(!Str_Cmp(*(void**)(*(u8**)((u8*)arg0+0x34)+off),arg1)){
found=*(u8**)((u8*)arg0+0x34)+(i<<5);break;
}
}
if(found){
if(arg2) {
if(!*(u32**)(found+0x18)){
*(u32**)(found+0x18)=fn_800C4638(32,gGMaterialAssertMsg,0);
for(j=0;j<8;j++) (*(u32**)(found+0x18))[j]=0;
}
slots=*(u32**)(found+0x18);
for(j=0;j<8;j++){
value=slots[j];if(value==arg2)break;
if(!value){slots[j]=arg2;break;}
}
*(u16*)(found+4)|=arg3&0xc000;
}
return 1;
}
return 0;
}
#pragma opt_loop_invariants reset

s32 fn_80068CFC(void *arg0, s32 arg1) {
    s32 Str_Cmp(void *, s32);
    s32 offset;
    s32 i;
    void *base;

    offset = 0;
    i = 0;
    while (i < *(u16 *)((u8 *)arg0 + 0x54)) {
        base = *(void **)((u8 *)arg0 + 0x34);
        if (Str_Cmp(*(void **)((u8 *)base + offset), arg1) == 0) {
            return 1;
        }
        offset += 0x20;
        i += 1;
    }
    return 0;
}

s32 fn_80068D84(void *arg0, s32 arg1, void *arg2, void *arg3) {
    extern u8 gMaterialTevStageCount, lbl_80367301, lbl_80367302, lbl_80367303, lbl_80367304;
    extern s32 gMaterialStageIds[];
    void GXSetNumTevStages(u8);
    void GXSetNumChans(u8);
    void fn_802238A8(u8);
    void GXSetTevOrder(s32,s32,s32,s32);
    void GXSetNumTexGens(s32,s32);
    void fn_8022100C(s32);
    void fn_800690D4(void *,void *,void *);
    void fn_80069354(void *,void **,void *,void *,void *);
    s32 GMaterial_SetupColor(void *,s32,void *,void *);
    s32 i, stage, offset;
    u32 ctx = fn_8006060C(arg0);
    void (*cb)(void *,u32);
    gMaterialTevStageCount = 0;
    lbl_80367301 = 0;
    lbl_80367302 = 0;
    lbl_80367303 = 0;
    lbl_80367304 = 0;
    if (!(*(u32 *)arg0 & 0x20000) && (M2C_FIELD(arg3,u16 *,4)&0x4000)) {
        if (M2C_FIELD(arg3,void **,0x18)) {
            for (i=0;i<8;i++) {
                cb = ((void (**)(void *,u32))M2C_FIELD(arg3,void **,0x18))[i];
                if (cb) cb(arg3,ctx);
            }
        }
        GXSetNumTevStages(gMaterialTevStageCount);
        GXSetNumChans(lbl_80367302);
        fn_802238A8(lbl_80367304);
        return 1;
    }
    if (!(*(u32 *)arg0 & 0x2000) && M2C_FIELD(arg3,u8 *,6)) {
        fn_80069354(arg0,(void **)arg1,arg2,M2C_FIELD(arg3,void **,0x14),(void *)ctx);
    } else {
        stage=gMaterialStageIds[gMaterialTevStageCount++];
        GXSetTevOrder(stage,255,255,4);
        GXSetNumTexGens(stage,4);
    }
    if (!(u8)GMaterial_SetupColor(arg0,arg1,arg2,arg3)) return 0;
    fn_800690D4(arg0,arg2,arg3);
    if (*(u32 *)arg0 & 0x1000) {
        switch(M2C_FIELD(arg2,u16 *,8)&0x1800) {
        case 0x800: fn_8022100C(2); break;
        case 0x1000: fn_8022100C(1); break;
        case 0x1800: fn_8022100C(3); break;
        }
    } else {
        switch(M2C_FIELD(arg2,u16 *,8)&0x1800) {
        case 0x800: fn_8022100C(1); break;
        case 0x1000: fn_8022100C(2); break;
        case 0x1800: fn_8022100C(0); break;
        }
    }
    if (!(*(u32 *)arg0 & 0x20000) && (M2C_FIELD(arg3,u16 *,4)&0x8000) && M2C_FIELD(arg3,void **,0x18)) {
        for(offset=0,i=0;i<8;i++,offset+=4) {
            cb=*(void (**)(void *,u32))((u8 *)M2C_FIELD(arg3,void **,0x18)+offset);
            if(cb) cb(arg3,ctx);
        }
    }
    GXSetNumTevStages(gMaterialTevStageCount);
    GXSetNumChans(lbl_80367302);
    fn_802238A8(lbl_80367304);
    return 1;
}

/* Set GX cull mode from material mirror flag (0x1000) and node cull bits (0x1800). */
void GMaterial_SetCullMode(s32 *mat, void *node) {
    M2C_UNK fn_8022100C(M2C_UNK);
    s32 cullBits;
    s32 cullBits2;

    if (*mat & 0x1000) {
        cullBits = M2C_FIELD(node, u16 *, 8) & 0x1800;
        switch (cullBits) {
        case 0x800:
            fn_8022100C(2);
            return;
        case 0x1000:
            fn_8022100C(1);
            return;
        case 0x1800:
            fn_8022100C(3);
            return;
        }
    } else {
        cullBits2 = M2C_FIELD(node, u16 *, 8) & 0x1800;
        switch (cullBits2) {
        case 0x800:
            fn_8022100C(1);
            return;
        case 0x1000:
            fn_8022100C(2);
            return;
        case 0x1800:
            fn_8022100C(0);
            return;
        }
    }
}

void fn_800690D4(void *arg0, void *arg1, void *arg2) {
    void fn_80222164(s32, void *);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void *Light_GetChannel(s32);
    extern s32 lbl_80369260;
    extern f32 lbl_80369264;
    s32 var_r31;
    s32 var_r30;
    s32 temp;
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *chan;
    s32 r7;
    s32 r8;
    s32 r9;

    if (!(M2C_FIELD(arg1, u16 *, 8) & 8)) {
        temp = M2C_FIELD(arg1, s32 *, 0x10);
        var_r31 = 0;
        var_r30 = 0;
        if (temp & 0x1000) {
            var_r31 = 1;
            if (temp & 0x400000) {
                var_r30 = 1;
            }
        }
        GXSetCullMode(1);
        if (M2C_FIELD(arg0, s32 *, 0) & 0x400) {
            GXSetBlendMode(0, 0, 0, var_r31, 0, 2, 2);
            GXSetBlendMode(2, 0, 0, var_r30, 0, 0, 2);
            spC = lbl_80369260;
            fn_80222164(4, &spC);
            return;
        }
        chan = Light_GetChannel(M2C_FIELD(arg0, u8 *, 0x86));
        r9 = 1;
        r8 = 2;
        r7 = M2C_FIELD(arg0, u8 *, 0x85);
        sp10 = M2C_FIELD(chan, s32 *, 0);
        if (M2C_FIELD(arg2, u16 *, 4) & 1) {
            r7 = ((r7 << 2) & 0xC) | (r7 & 0xF0);
            r9 = 0;
            r8 = 0;
        } else if (M2C_FIELD(arg1, u16 *, 8) & 0x200) {
            r7 = 0;
            M2C_FIELD(&sp10, u8 *, 0) = (M2C_FIELD(&sp10, u8 *, 0) + M2C_FIELD(chan, u8 *, 4)) >> 1;
            M2C_FIELD(&sp10, u8 *, 1) = (M2C_FIELD(&sp10, u8 *, 1) + M2C_FIELD(chan, u8 *, 5)) >> 1;
            M2C_FIELD(&sp10, u8 *, 2) = (M2C_FIELD(&sp10, u8 *, 2) + M2C_FIELD(chan, u8 *, 6)) >> 1;
        }
        if (M2C_FIELD(arg0, s32 *, 0) & 0x1000000) {
            if (M2C_FIELD(&sp10, u8 *, 0) > 0xAA) {
                M2C_FIELD(&sp10, u8 *, 0) = 0xFF;
            } else {
                M2C_FIELD(&sp10, u8 *, 0) = (u8)((f32)M2C_FIELD(&sp10, u8 *, 0) * lbl_80369264);
            }
            if (M2C_FIELD(&sp10, u8 *, 1) > 0xAA) {
                M2C_FIELD(&sp10, u8 *, 1) = 0xFF;
            } else {
                M2C_FIELD(&sp10, u8 *, 1) = (u8)((f32)M2C_FIELD(&sp10, u8 *, 1) * lbl_80369264);
            }
            if (M2C_FIELD(&sp10, u8 *, 2) > 0xAA) {
                M2C_FIELD(&sp10, u8 *, 2) = 0xFF;
            } else {
                M2C_FIELD(&sp10, u8 *, 2) = (u8)((f32)M2C_FIELD(&sp10, u8 *, 2) * lbl_80369264);
            }
        }
        GXSetBlendMode(0, 1, 0, var_r31, r7, r8, r9);
        GXSetBlendMode(2, 0, 0, var_r30, 0, 0, 2);
        sp8 = sp10;
        fn_80222164(4, &sp8);
    }
}

#pragma use_lmw_stmw on
void fn_80069354(void *arg0, void **arg1, void *arg2, void *arg3, void *arg4) {
    void Ui_LoadAtlasTex(void *, void *, u16);
    void Game_Assert(void *, s32, void *);
    void fn_8006EBC4(void *, void *, void *, s32);
    f32 fn_80064164(void **, s16, f32);
    f32 fn_8006469C(void **, s16, f32);
    f32 fn_80064400(void **, s16, f32);
    f32 fn_80063EC8(void **, s16, f32);
    f32 fn_80063C2C(void **, s16, f32);
    void PSMTXIdentity(void *);
    void PSMTXTrans(void *, f32, f32, f32);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXScale(void *, f32, f32, f32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void fn_80224E50(void *, s32, s32);
    s32 fn_80222AA8(void *);
    s32 fn_80222AA0(void *);
    s32 GXGetTexObjHeight(void *);
    s32 GXGetTexObjWidth(void *);
    s32 fn_80222A74(void *);
    void fn_80222644(void *, s32, s32, s32, s32, s32, s32, s32);
    void fn_80222CF0(void *, s32);
    void fn_80222C50(void *, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTexGens(s32, s32);
    extern u8 gGMaterialAssertMsg[];
    extern s32 gMaterialStageIds[];
    extern u8 gMaterialTevStageCount;
    extern u8 lbl_80367301;
    extern u8 lbl_80367302;
    extern u8 lbl_80367303;
    extern f32 lbl_80369270;
    extern f32 lbl_80369274;
    extern f32 lbl_80369278;
    extern f32 lbl_8036927C;
    extern f32 lbl_80369280;
    extern f32 lbl_80369284;
    u8 spC4[0x30];
    u8 sp94[0x30];
    u8 sp64[0x30];
    u8 sp34[0x30];
    u8 sp14[0x20];
    u8 sp8[0xC];
    f32 f31, f30, f29, f28, f27;
    s32 r30, r29, r28, r22;
    void **obj;
    s32 t31, t25, t24, t23, t4;
    s32 *pool;
    s32 *base;
    u8 idx;

    pool = gMaterialStageIds;
    Ui_LoadAtlasTex(arg4, sp14, *(u16 *)((u8 *)arg3 + 4));
    if (lbl_80367301 >= 8) {
        Game_Assert(gGMaterialAssertMsg + 1, 0x4F, gGMaterialAssertMsg + 0xD);
    }
    idx = lbl_80367301;
    base = (s32 *)((u8 *)pool + 0x40);
    lbl_80367301 = idx + 1;
    r30 = base[idx];
    if (lbl_80367302 >= 8) {
        Game_Assert(gGMaterialAssertMsg + 1, 0x70, gGMaterialAssertMsg + 0x25);
    }
    idx = lbl_80367302;
    base = (s32 *)((u8 *)pool + 0x60);
    lbl_80367302 = idx + 1;
    r29 = base[idx];
    if (gMaterialTevStageCount >= 0x10) {
        Game_Assert(gGMaterialAssertMsg + 1, 0x2C, gGMaterialAssertMsg + 0x3F);
    }
    idx = gMaterialTevStageCount;
    base = pool;
    gMaterialTevStageCount = idx + 1;
    r28 = base[idx];

    if ((arg1 == 0 || *arg1 == 0) && (*(u16 *)arg3 & 1)) {
        fn_802201A8(r29, 1, 4, 0x3C, 0, 0x7D);
    } else {
        f31 = *(f32 *)((u8 *)arg3 + 0x18);
        f30 = *(f32 *)((u8 *)arg3 + 0x8);
        f29 = *(f32 *)((u8 *)arg3 + 0xC);
        f28 = *(f32 *)((u8 *)arg3 + 0x10);
        f27 = *(f32 *)((u8 *)arg3 + 0x14);
        if (arg1 != 0) {
            obj = (void **)*arg1;
            if (obj != 0) {
                if (obj[5] != 0) {
                    f31 = fn_80064164(arg1, *(s16 *)((u8 *)arg2 + 0xA), *(f32 *)((u8 *)arg0 + 0x58));
                }
                if (obj[3] != 0) {
                    f30 = fn_8006469C(arg1, *(s16 *)((u8 *)arg2 + 0xA), *(f32 *)((u8 *)arg0 + 0x58));
                }
                if (obj[4] != 0) {
                    f29 = fn_80064400(arg1, *(s16 *)((u8 *)arg2 + 0xA), *(f32 *)((u8 *)arg0 + 0x58));
                }
                if (obj[6] != 0) {
                    f28 = fn_80063EC8(arg1, *(s16 *)((u8 *)arg2 + 0xA), *(f32 *)((u8 *)arg0 + 0x58));
                }
                if (obj[7] != 0) {
                    f27 = fn_80063C2C(arg1, *(s16 *)((u8 *)arg2 + 0xA), *(f32 *)((u8 *)arg0 + 0x58));
                }
            }
        }
        PSMTXIdentity(sp34);
        if (lbl_80369270 != f31) {
            PSMTXTrans(sp64, lbl_80369274, lbl_80369274, lbl_80369270);
            PSMTXRotRad(sp94, 0x7A, lbl_80369278 * -f31);
            PSMTXConcat(sp94, sp64, sp94);
            PSMTXTrans(sp64, lbl_8036927C, lbl_8036927C, lbl_80369270);
            PSMTXConcat(sp64, sp94, sp34);
        }
        if (lbl_80369280 != f28 || lbl_80369280 != f27) {
            PSMTXTrans(sp64, lbl_80369270, lbl_80369284, lbl_80369270);
            PSMTXScale(spC4, f28, f27, lbl_80369280);
            PSMTXConcat(spC4, sp64, spC4);
            PSMTXTrans(sp64, lbl_80369270, lbl_80369280, lbl_80369270);
            PSMTXConcat(sp64, spC4, spC4);
            PSMTXConcat(spC4, sp34, sp34);
        }
        if (lbl_80369270 != f30 || lbl_80369270 != f29) {
            PSMTXTrans(sp64, f30, -f29, lbl_80369270);
            PSMTXConcat(sp64, sp34, sp34);
        }
        if (lbl_80367303 >= 0x3C) {
            Game_Assert(gGMaterialAssertMsg + 1, 0x96, gGMaterialAssertMsg + 0x5B);
        }
        idx = lbl_80367303;
        base = (s32 *)((u8 *)pool + 0x80);
        r22 = base[idx];
        lbl_80367303 = idx + 1;
        fn_80224E50(sp34, r22, 1);
        fn_802201A8(r29, 1, 4, r22, 0, 0x7D);
    }
    if (*(u16 *)arg3 & 0x20) {
        t31 = fn_80222AA8(sp14);
        t25 = fn_80222AA0(sp14);
        t24 = GXGetTexObjHeight(sp14);
        t23 = GXGetTexObjWidth(sp14);
        t4 = fn_80222A74(sp14);
        fn_80222644(sp14, t4, t23, t24, t25, 1, 1, t31);
    }
    {
        u16 n = *(u16 *)((u8 *)arg3 + 4);
        u8 *tbl = *(u8 **)((u8 *)arg4 + 8);
        if (*(u32 *)(tbl + (n << 3) + 4) != 0) {
            fn_8006EBC4(arg4, sp14, sp8, 0);
            fn_80222CF0(sp8, 0);
        }
    }
    fn_80222C50(sp14, r30);
    GXSetTevOrder(r28, r29, r30, 4);
    GXSetNumTexGens(r28, 0);
}
/* Compute material color/alpha and bind it to GX channel + optional TEV stages. */
s32 GMaterial_SetupColor(void *mat, s32 animCtx, void *matParam, void *obj)
{
    u8 GMaterial_EvalAlphaAnim(s32, s16, void *, f32);
    void GMaterial_EvalColorAnim(s32, s16, void *, f32);
    void Game_Assert(void *, s32, void *);
    void GXSetTevColor(s32, MaterialColor *);
    void GXSetChanMatColor(s32, MaterialColor *);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetTevColorIn(s32, s32, s32, s32, s32);
    void GXSetTevColorOp(s32, s32, s32, s32, s32, s32);
    void GXSetTevAlphaIn(s32, s32, s32, s32, s32);
    void GXSetTevAlphaOp(s32, s32, s32, s32, s32, s32);
    extern u8 gMaterialTevStageCount;
    extern u8 gGMaterialAssertMsg[];
    extern s32 gMaterialStageIds[16];
    extern f32 gInv255f;
    extern u32 gTevColorReg2Scratch, gChanMatColorScratch, gTevColorReg1Scratch;
    MaterialColor color, copy3, c3, copy4, c4, copy2, c2;
    s32 stage, r, g, b;
    s32 alpha;

    color.r = ((u8 *)obj)[8];
    color.g = ((u8 *)obj)[9];
    color.b = ((u8 *)obj)[10];
    color.a = ((u8 *)obj)[11];
    if ((*(u32 *)mat & 0x8020) == 0x8000)
        color.a = ((u8 *)mat)[0x84];
    else {
        if (GMaterial_EvalAlphaAnim(animCtx, *(s16 *)((u8 *)matParam + 10), &color,
                                    *(f32 *)((u8 *)mat + 0x58))) {
            alpha = (s32)(gInv255f * (f32)(((u8 *)mat)[11] * color.a));
            color.a = alpha;
            if (*(u16 *)((u8 *)matParam + 8) & 0x80) {
                color.b = alpha;
                color.g = alpha;
                color.r = alpha;
            }
        } else
            color.a = (s32)(gInv255f * (f32)(((u8 *)mat)[11] * color.a));
        if (!color.a)
            return 0;
    }
    GMaterial_EvalColorAnim(animCtx, *(s16 *)((u8 *)matParam + 10), &color,
                            *(f32 *)((u8 *)mat + 0x58));
    if (((u8 *)mat)[8] < 128)
        color.r = (((u8 *)mat)[8] * color.r) >> 7;
    if (((u8 *)mat)[9] < 128)
        color.g = (((u8 *)mat)[9] * color.g) >> 7;
    if (((u8 *)mat)[10] < 128)
        color.b = (((u8 *)mat)[10] * color.b) >> 7;
    if ((*(u32 *)((u8 *)matParam + 0x10) & 0x1000)
        && (((u8 *)mat)[8] < 128 || ((u8 *)mat)[9] < 128 || ((u8 *)mat)[10] < 128)) {
        if (gMaterialTevStageCount >= 16)
            Game_Assert(gGMaterialAssertMsg + 1, 44, gGMaterialAssertMsg + 0x3f);
        c3 = *(MaterialColor *)&gTevColorReg2Scratch;
        stage = gMaterialStageIds[gMaterialTevStageCount++];
        c3.r = color.r;
        c3.g = color.g;
        c3.b = color.b;
        c3.a = color.a;
        copy3 = c3;
        GXSetTevColor(3, &copy3);
        GXSetTevOrder(stage, 255, 255, 255);
        GXSetTevColorIn(stage, 15, 0, 6, 15);
        GXSetTevColorOp(stage, 0, 0, 0, 1, 0);
        GXSetTevAlphaIn(stage, 7, 7, 7, 0);
        GXSetTevAlphaOp(stage, 0, 0, 0, 1, 0);
    }
    c4 = *(MaterialColor *)&gChanMatColorScratch;
    c4.r = color.r;
    c4.g = color.g;
    c4.b = color.b;
    c4.a = color.a;
    copy4 = c4;
    GXSetChanMatColor(4, &copy4);
    if (((u8 *)mat)[8] > 128 || ((u8 *)mat)[9] > 128 || ((u8 *)mat)[10] > 128) {
        r = ((((u8 *)mat)[8] - 128) * 255) >> 7;
        g = ((((u8 *)mat)[9] - 128) * 255) >> 7;
        b = ((((u8 *)mat)[10] - 128) * 255) >> 7;
        if (r < 0)
            r = 0;
        if (g < 0)
            g = 0;
        if (b < 0)
            b = 0;
        if (gMaterialTevStageCount >= 16)
            Game_Assert(gGMaterialAssertMsg + 1, 44, gGMaterialAssertMsg + 0x3f);
        c2 = *(MaterialColor *)&gTevColorReg1Scratch;
        stage = gMaterialStageIds[gMaterialTevStageCount++];
        c2.r = r;
        c2.g = g;
        c2.b = b;
        copy2 = c2;
        GXSetTevColor(2, &copy2);
        GXSetTevOrder(stage, 255, 255, 255);
        GXSetTevColorIn(stage, 15, 12, 4, 0);
        GXSetTevColorOp(stage, 0, 0, 0, 1, 0);
        GXSetTevAlphaIn(stage, 7, 7, 7, 0);
        GXSetTevAlphaOp(stage, 0, 0, 0, 1, 0);
    }
    return 1;
}

void fn_80069C7C(void) {
    extern u8 gMaterialTevStageCount;
    extern u8 lbl_80367301;
    extern u8 lbl_80367302;
    extern u8 lbl_80367303;
    extern u8 lbl_80367304;

    gMaterialTevStageCount = 0;
    lbl_80367301 = 0;
    lbl_80367302 = 0;
    lbl_80367303 = 0;
    lbl_80367304 = 0;
}

#pragma global_optimizer off
void fn_80069C98(void) {
    void fn_802238A8(s32);
    void fn_802238CC(s32);
    extern s32 lbl_80285E88[];
    extern u8 lbl_80367304;
    s32 *var_r31;
    s32 var_r30;

    if (lbl_80367304 != 0) {
        var_r30 = 0;
        var_r31 = lbl_80285E88;
        do {
            fn_802238CC(*var_r31);
            var_r30 += 1;
            var_r31 += 1;
        } while (var_r30 < 8);
        fn_802238A8(0);
    }
}
#pragma global_optimizer off
void *fn_80069CFC(void) {
    extern u8 lbl_80367304;
    extern u8 gGMaterialAssertMsg[];
    extern void *lbl_80285F30[];
    void Game_Assert(const char *, s32, const char *);
    void **entry;
    u8 idx;
    if (lbl_80367304 >= 4)
        Game_Assert((const char *)gGMaterialAssertMsg+1,0xB5,(const char *)gGMaterialAssertMsg+0x74);
    idx=lbl_80367304;
    entry=&lbl_80285F30[idx];
    lbl_80367304 = ++idx;
    return *entry;
}
#pragma global_optimizer off
void *GMaterial_AllocMtx(void) {
    extern u8 lbl_80367303;
    extern u8 gGMaterialAssertMsg[];
    extern void *lbl_80285F08[];
    void Game_Assert(const char *, s32, const char *);
    void **entry;
    u8 idx;
    if (lbl_80367303 >= 0x3C)
        Game_Assert((const char *)gGMaterialAssertMsg + 1, 0x96, (const char *)gGMaterialAssertMsg + 0x5B);
    idx = lbl_80367303;
    entry = &lbl_80285F08[idx];
    lbl_80367303 = ++idx;
    return *entry;
}
#pragma global_optimizer reset
u8 fn_80069DB4(void) {
    extern u8 lbl_80367302;
    return lbl_80367302;
}

#pragma global_optimizer off
void *GMaterial_AllocTexCoord(void) {
    extern u8 lbl_80367302;
    extern u8 gGMaterialAssertMsg[];
    extern void *lbl_80285EE8[];
    void Game_Assert(const char *, s32, const char *);
    void **entry;
    u8 idx;
    if (lbl_80367302 >= 8)
        Game_Assert((const char *)gGMaterialAssertMsg+1,0x70,(const char *)gGMaterialAssertMsg+0x25);
    idx=lbl_80367302;
    entry=&lbl_80285EE8[idx];
    lbl_80367302 = ++idx;
    return *entry;
}
#pragma global_optimizer off
void *GMaterial_AllocTexMap(void) {
    extern u8 lbl_80367301;
    extern u8 gGMaterialAssertMsg[];
    extern void *lbl_80285EC8[];
    void Game_Assert(const char *, s32, const char *);
    void **entry;
    u8 idx;
    if (lbl_80367301 >= 8)
        Game_Assert((const char *)gGMaterialAssertMsg+1,0x4F,(const char *)gGMaterialAssertMsg+0xD);
    idx=lbl_80367301;
    entry=&lbl_80285EC8[idx];
    lbl_80367301 = ++idx;
    return *entry;
}
#pragma global_optimizer on

#pragma global_optimizer on
u8 fn_80069E74(void) {
    extern u8 gMaterialTevStageCount;
extern u8 lbl_80367301;
extern u8 lbl_80367302;
extern u8 lbl_80367303;
extern u8 lbl_80367304;
return gMaterialTevStageCount;
}

extern u16 gMaterialStageIds[0x20];
s32 fn_80069E7C(void)
{
  extern u8 gMaterialTevStageCount;
  extern u16 gMaterialStageIds[0x20];
  u8 idx = gMaterialTevStageCount;
  s32 *new_var;
  if (gMaterialTevStageCount == (((s32 *) gMaterialStageIds)[idx - 1] * 0))
  {
    return 0;
    if (gMaterialTevStageCount)
    {
    }
    idx += 0;
    if (((!idx) && (!idx)) && (!idx))
    {
    }
  }
  new_var = (s32 *) gMaterialStageIds;
  return new_var[(idx & 0xFFFFFFFF) - 1];
}

#pragma global_optimizer off
void *GMaterial_AllocTevStage(void) {
    extern u8 gMaterialTevStageCount;
    extern u8 gGMaterialAssertMsg[];
    extern u16 gMaterialStageIds[0x20];
    void Game_Assert(const char *, s32, const char *);
    void **entry;
    u8 idx;
    if (gMaterialTevStageCount >= 0x10)
        Game_Assert((const char *)gGMaterialAssertMsg+1,0x2C,(const char *)gGMaterialAssertMsg+0x3F);
    idx=gMaterialTevStageCount;
    entry=&((void **)gMaterialStageIds)[idx];
    gMaterialTevStageCount = ++idx;
    return *entry;
}
#pragma global_optimizer on
void fn_80069F04(s32 arg0) {
    M2C_UNK fn_80069F2C(M2C_UNK, s32);
    fn_80069F2C(-1, arg0);
}

#pragma use_lmw_stmw on
#pragma inline_depth(3)


#pragma use_lmw_stmw on
#pragma inline_depth(3)
#pragma opt_common_subs off
void fn_80069F2C(s32 arg0,void *arg1) {
u32 fn_80060638(void*);
void fn_8006C2A4(void*,s32);
void fn_8006CAB0(s32);void fn_8006CA8C(void*);void fn_8006CA68(void*);void fn_8014E7F8(void*);
u8 *child;
u8 *data;
child=*(u8**)((u8*)arg1+0x8c);
if(child)fn_80069F2C(arg0,child);
data=(u8*)fn_80060638(arg1);
if(*((u8*)arg1+0xb)){
switch(arg0) {
case 0:if(*(u32*)(data+0x3c))fn_8006C2A4(arg1,0);break;
case 1:if(*(u32*)(data+0x40))fn_8006C2A4(arg1,1);break;
case 2:
if(*(u32*)(data+0x44))fn_8006C2A4(arg1,2);
if(*(u32*)((u8*)arg1+0x54))fn_8014E7F8(arg1);
break;
default:
if(*(u32*)(data+0x3c))fn_8006C2A4(arg1,0);
if(*(u32*)(data+0x40))fn_8006C2A4(arg1,1);
if(*(u32*)(data+0x44))fn_8006C2A4(arg1,2);
if(*(u32*)((u8*)arg1+0x54))fn_8014E7F8(arg1);
break;
}
}
}
#pragma opt_common_subs reset
s32 GMaterial_GetNode(void) {
    extern s32 gGMaterialNode;
    return gGMaterialNode;
}

s32 GMaterial_GetCurrent(void) {
    extern s32 gGMaterialCurrent;
    return gGMaterialCurrent;
}

void fn_8006A384(s32 *arg0) {
void PSMTXRotRad(void *,s32,f32);
void PSMTXScale(void *,f32,f32,f32);
void PSMTXTrans(void *,f32,f32,f32);
void PSMTXConcat(void *,void *,void *);
void PSMTXCopy(void *,void *);
void QUATMtx(void *,void *);
void Game_Assert(void *,s32,void *);
extern f32 lbl_80369298;
extern u8 lbl_8026B8AC[];
extern void *gGMaterialCurrent,*gGMaterialNode;
f32 rz[12],ry[12],rx[12],trans[12],scale[12];
u8 *p=gGMaterialCurrent;
switch(*(u32 *)(p+12)) {
case 1:
PSMTXRotRad(rx,88,lbl_80369298 * *(f32 *)(p+28));
PSMTXRotRad(ry,89,lbl_80369298 * *(f32 *)(p+32));
PSMTXRotRad(rz,90,lbl_80369298 * *(f32 *)(p+36));
break;
case 2:
PSMTXRotRad(rx,89,lbl_80369298 * *(f32 *)(p+32));
PSMTXRotRad(ry,90,lbl_80369298 * *(f32 *)(p+36));
PSMTXRotRad(rz,88,lbl_80369298 * *(f32 *)(p+28));
break;
case 3:
PSMTXRotRad(rx,90,lbl_80369298 * *(f32 *)(p+36));
PSMTXRotRad(ry,88,lbl_80369298 * *(f32 *)(p+28));
PSMTXRotRad(rz,89,lbl_80369298 * *(f32 *)(p+32));
break;
case 4:
PSMTXRotRad(rx,88,lbl_80369298 * *(f32 *)(p+28));
PSMTXRotRad(ry,90,lbl_80369298 * *(f32 *)(p+36));
PSMTXRotRad(rz,89,lbl_80369298 * *(f32 *)(p+32));
break;
case 5:
PSMTXRotRad(rx,89,lbl_80369298 * *(f32 *)(p+32));
PSMTXRotRad(ry,88,lbl_80369298 * *(f32 *)(p+28));
PSMTXRotRad(rz,90,lbl_80369298 * *(f32 *)(p+36));
break;
case 6:
PSMTXRotRad(rx,90,lbl_80369298 * *(f32 *)(p+36));
PSMTXRotRad(ry,89,lbl_80369298 * *(f32 *)(p+32));
PSMTXRotRad(rz,88,lbl_80369298 * *(f32 *)(p+28));
break;
case 8:
PSMTXScale(scale,*(f32 *)(p+40),*(f32 *)(p+44),*(f32 *)(p+48));
PSMTXTrans(trans,*(f32 *)(p+16),*(f32 *)(p+20),*(f32 *)(p+24));
QUATMtx(p+16,rx);
PSMTXConcat(rx,scale,arg0); PSMTXConcat(rx,arg0,arg0); PSMTXConcat(trans,arg0,arg0);
goto done;
case 7: PSMTXCopy(p+16,arg0); goto done;
default: Game_Assert(lbl_8026B8AC,0xB8,lbl_8026B8AC+8); break;
}
PSMTXScale(scale,*(f32 *)(p+40),*(f32 *)(p+44),*(f32 *)(p+48));
PSMTXTrans(trans,*(f32 *)(p+16),*(f32 *)(p+20),*(f32 *)(p+24));
PSMTXConcat(rx,scale,arg0); PSMTXConcat(ry,arg0,arg0); PSMTXConcat(rz,arg0,arg0); PSMTXConcat(trans,arg0,arg0);
done:
if ((*(u16 *)((u8 *)gGMaterialNode+8)&3)==0) {
PSMTXConcat(arg0,*(u8 **)((u8 *)gGMaterialCurrent+0x60)+*(s16 *)((u8 *)gGMaterialNode+12)*48,arg0);
}
}

void GXSetCullMode(s32);
void GXClearVtxDesc(void);
void GXSetVtxDescv(s32 *);
void GXSetVtxAttrFmtv(s32, s32 *);
/* Build GX vtx-desc and attr-fmt lists from format flags, then apply them. */
void Gfx_SetupVtxFormat(s32 format, u8 fracA, u8 fracB, u8 texFrac, u8 useFracA) {
    s32 desc[0x36];
    s32 fmt[0x6C];
    s32 *dp;
    s32 *fp;

    dp = desc;
    fp = fmt;

    if (format & 1) {
        dp[0] = GX_VA_PNMTXIDX;
        dp[1] = GX_DIRECT;
        dp += 2;
    }

    if (format & 0x200) {
        dp[0] = GX_VA_POS;
        dp[1] = GX_INDEX16;
        dp += 2;
        fp[0] = GX_VA_POS;
        fp[1] = 1;
        fp[2] = 3;
        ((u8 *)fp)[0xc] = fracA;
        fp += 4;
    }

    if (format & 0x400) {
        dp[0] = GX_VA_NRM;
        dp[1] = GX_INDEX16;
        fp[0] = GX_VA_NRM;
        fp[1] = 0;
        if (useFracA != 0) {
            fp[2] = 3;
            ((u8 *)fp)[0xc] = fracA;
        } else {
            fp[2] = 1;
            ((u8 *)fp)[0xc] = fracB;
        }
        fp += 4;
        dp += 2;
    }

    if (format & 0x800) {
        dp[0] = GX_VA_NBT;
        dp[1] = GX_INDEX16;
        fp[0] = GX_VA_NBT;
        fp[1] = 1;
        if (useFracA != 0) {
            fp[2] = 3;
            ((u8 *)fp)[0xc] = fracA;
        } else {
            fp[2] = 1;
            ((u8 *)fp)[0xc] = fracB;
        }
        fp += 4;
        dp += 2;
    }

    if (format & 0x1000) {
        fp[0] = GX_VA_CLR0;
        fp[1] = 1;
        dp[0] = GX_VA_CLR0;
        dp[1] = GX_INDEX16;
        fp[2] = 5;
        dp += 2;
        ((u8 *)fp)[0xc] = 0;
        fp += 4;
        GXSetCullMode(1);
    }

    if (format & 0x4000) {
        dp[0] = GX_VA_TEX0;
        dp[1] = GX_INDEX16;
        dp += 2;
        fp[0] = GX_VA_TEX0;
        fp[1] = 1;
        fp[2] = 3;
        ((u8 *)fp)[0xc] = texFrac;
        fp += 4;
    }

    if (format & 0x8000) {
        dp[0] = GX_VA_TEX1;
        dp[1] = GX_INDEX16;
        dp += 2;
        fp[0] = GX_VA_TEX1;
        fp[1] = 1;
        fp[2] = 3;
        ((u8 *)fp)[0xc] = texFrac;
        fp += 4;
    }

    if (format & 0x10000) {
        dp[0] = GX_VA_TEX2;
        dp[1] = GX_INDEX16;
        dp += 2;
        fp[0] = GX_VA_TEX2;
        fp[1] = 1;
        fp[2] = 3;
        ((u8 *)fp)[0xc] = texFrac;
        fp += 4;
    }

    if (format & 0x20000) {
        dp[0] = GX_VA_TEX3;
        dp[1] = GX_INDEX16;
        dp += 2;
        fp[0] = GX_VA_TEX3;
        fp[1] = 1;
        fp[2] = 3;
        ((u8 *)fp)[0xc] = texFrac;
        fp += 4;
    }

    dp[0] = GX_VA_NULL;
    fp[0] = GX_VA_NULL;
    GXClearVtxDesc();
    GXSetVtxDescv(desc);
    GXSetVtxAttrFmtv(0, fmt);
}

void fn_8006A930(void *node, void *actor, s32 work) {
void *GActor_GetNodeTable(void *);
void PSMTXRotRad(void *,s32,f32); void PSMTXScale(void *,f32,f32,f32); void PSMTXTrans(void *,f32,f32,f32);
void PSMTXCopy(void *,void *); void PSMTXConcat(void *,void *,void *); void PSMTXIdentity(void *);
void QUATMtx(void *,void *); int Game_Assert(void *,int,void *);
void fn_802029C4(void *,void *,void *); void fn_802031E8(void *,void *);
f32 fn_80203270(void *,void *); void fn_80203290(void *,void *,void *);
double fn_80238788(double); double fn_80237E90(double);
void fn_802024D0(void *,void *,f32); void fn_802020F0(void *,void *);
void fn_802031A8(void *,void *,void *); void *Camera_Get(void); void *Camera_GetViewMtx(void);
void fn_80202238(void *,void *); void fn_80224DCC(void *,u32);
void GXLoadPosMtxImm(void *,u32);
extern f32 lbl_80369298,lbl_8036929C,lbl_803692A0,lbl_803692A4,lbl_803692A8;
extern u8 lbl_8026B8AC[]; extern s16 lbl_80285F40[]; extern f32 lbl_8026B888[];
f32 result[12], rz[12], ry[12], rx[12], trans[12], scale[12];
f32 rotation[12],translation[12],scaling[12],view[12];
f32 local[12],bone[12],turn[12],position[12],combined[12];
f32 trans3[12],scale3[12],view3[12];
f32 local4[12],turn4[12],trans4[12],temp4[12];
f32 align1[12],inv1[12],align3[12],inv3[12];
typedef struct { f32 v[9]; } Basis;
s16 seen[10];
f32 direction[3],direction4[3];
Basis basis1;
f32 axis1[3];
Basis basis3;
f32 axis3[3];
s32 count,i,index;
void *parent;
f32 dot,angle;
GActor_GetNodeTable(actor);
seen[0]=-1; seen[1]=-1; seen[2]=-1; seen[3]=-1; seen[4]=-1; seen[5]=-1; seen[6]=-1; seen[7]=-1; seen[8]=-1; seen[9]=-1;
count=0;
while(node && count<10) {
if (!(M2C_FIELD(node,u32 *,0x10)&1)) {
index=M2C_FIELD(node,s16 *,0xC);
for(i=0;i<count;i++) if(seen[i]==index) { M2C_FIELD(node,s16 *,0xE)=lbl_80285F40[i]; goto next; }
switch(M2C_FIELD(actor,u32 *,0xC)) {
case 1:
PSMTXRotRad(rx,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
PSMTXRotRad(ry,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
PSMTXRotRad(rz,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
break;
case 2:
PSMTXRotRad(rx,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
PSMTXRotRad(ry,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
PSMTXRotRad(rz,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
break;
case 3:
PSMTXRotRad(rx,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
PSMTXRotRad(ry,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
PSMTXRotRad(rz,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
break;
case 4:
PSMTXRotRad(rx,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
PSMTXRotRad(ry,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
PSMTXRotRad(rz,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
break;
case 5:
PSMTXRotRad(rx,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
PSMTXRotRad(ry,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
PSMTXRotRad(rz,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
break;
case 6:
PSMTXRotRad(rx,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
PSMTXRotRad(ry,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
PSMTXRotRad(rz,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
break;
case 8:
PSMTXScale(scale,M2C_FIELD(actor,f32 *,0x28),M2C_FIELD(actor,f32 *,0x2C),M2C_FIELD(actor,f32 *,0x30));
PSMTXTrans(trans,M2C_FIELD(actor,f32 *,0x10),M2C_FIELD(actor,f32 *,0x14),M2C_FIELD(actor,f32 *,0x18));
QUATMtx((u8 *)actor+0x10,rx);
PSMTXConcat(rx,scale,result); PSMTXConcat(rx,result,result); PSMTXConcat(trans,result,result); goto transformed;
case 7: PSMTXCopy((u8 *)actor+0x10,result); goto transformed;
default: Game_Assert(lbl_8026B8AC,0xB8,lbl_8026B8AC+8); break;
}
PSMTXScale(scale,M2C_FIELD(actor,f32 *,0x28),M2C_FIELD(actor,f32 *,0x2C),M2C_FIELD(actor,f32 *,0x30));
PSMTXTrans(trans,M2C_FIELD(actor,f32 *,0x10),M2C_FIELD(actor,f32 *,0x14),M2C_FIELD(actor,f32 *,0x18));
PSMTXConcat(rx,scale,result); PSMTXConcat(ry,result,result); PSMTXConcat(rz,result,result); PSMTXConcat(trans,result,result);
transformed:
if (!(M2C_FIELD(node,u16 *,8)&1)) {
switch((s32)(M2C_FIELD(node,u32 *,0x10)&0xE0000000)) {
case 0x20000000:
parent=(void *)(work+M2C_FIELD(node,s16 *,0xC)*0x30);
basis1=*(Basis *)lbl_8026B888;
PSMTXCopy(result,inv1);
inv1[3]=lbl_8036929C; inv1[7]=lbl_8036929C; inv1[11]=lbl_8036929C;
fn_802029C4(inv1,basis1.v,basis1.v);
if(lbl_8036929C==basis1.v[2]*basis1.v[2]+(basis1.v[0]*basis1.v[0]+basis1.v[1]*basis1.v[1])) {
PSMTXScale(scaling,lbl_8036929C,lbl_8036929C,lbl_8036929C);
} else {
fn_802031E8(basis1.v,basis1.v); dot=fn_80203270(basis1.v,basis1.v+3);
if(lbl_803692A0==dot) PSMTXIdentity(align1);
else if(lbl_803692A4==dot) PSMTXScale(align1,lbl_803692A4,lbl_803692A4,lbl_803692A4);
else { angle=fn_80238788(dot); fn_80203290(basis1.v,basis1.v+3,axis1); fn_802024D0(align1,axis1,angle); }
fn_802029C4(inv1,basis1.v+6,basis1.v+6); fn_802029C4(align1,basis1.v+6,basis1.v+6);
PSMTXScale(scaling,basis1.v[6],basis1.v[7],basis1.v[8]);
}
PSMTXConcat(result,parent,result);
PSMTXTrans(translation,result[3],result[7],result[11]);
PSMTXCopy(parent,rotation); rotation[3]=lbl_8036929C; rotation[7]=lbl_8036929C; rotation[11]=lbl_8036929C;
fn_802020F0(Camera_GetViewMtx(),view);
PSMTXConcat(scaling,rotation,result); PSMTXConcat(view,result,result); PSMTXConcat(translation,result,result);
break;
case 0x40000000:
parent=(void *)(work+M2C_FIELD(node,s16 *,0xC)*0x30);
PSMTXConcat(result,parent,combined); PSMTXTrans(position,combined[3],combined[7],combined[11]);
PSMTXCopy(parent,bone); PSMTXCopy(result,local);
bone[3]=lbl_8036929C; bone[7]=lbl_8036929C; bone[11]=lbl_8036929C; local[3]=lbl_8036929C; local[7]=lbl_8036929C; local[11]=lbl_8036929C;
{ u8 *camera=Camera_Get(); fn_802031A8(camera+0xE0,camera+0xD4,direction); }
fn_802020F0(result,combined); fn_802029C4(combined,direction,direction);
if(lbl_8036929C==direction[0]) PSMTXIdentity(turn);
else { angle=fn_80237E90(direction[2]/direction[0]);
if(direction[0]<lbl_8036929C) angle=lbl_803692A8-angle;
else angle=-angle-lbl_803692A8;
PSMTXRotRad(turn,'Y',angle); }
PSMTXConcat(turn,bone,combined); PSMTXConcat(local,combined,combined); PSMTXConcat(position,combined,result);
break;
case 0x60000000:
parent=(void *)(work+M2C_FIELD(node,s16 *,0xC)*0x30);
basis3=*(Basis *)lbl_8026B888;
PSMTXCopy(result,inv3);
inv3[3]=lbl_8036929C; inv3[7]=lbl_8036929C; inv3[11]=lbl_8036929C;
fn_802029C4(inv3,basis3.v,basis3.v);
if(lbl_8036929C==basis3.v[2]*basis3.v[2]+(basis3.v[0]*basis3.v[0]+basis3.v[1]*basis3.v[1])) {
PSMTXScale(scale3,lbl_8036929C,lbl_8036929C,lbl_8036929C);
} else {
fn_802031E8(basis3.v,basis3.v); dot=fn_80203270(basis3.v,basis3.v+3);
if(lbl_803692A0==dot) PSMTXIdentity(align3);
else if(lbl_803692A4==dot) PSMTXScale(align3,lbl_803692A4,lbl_803692A4,lbl_803692A4);
else { angle=fn_80238788(dot); fn_80203290(basis3.v,basis3.v+3,axis3); fn_802024D0(align3,axis3,angle); }
fn_802029C4(inv3,basis3.v+6,basis3.v+6); fn_802029C4(align3,basis3.v+6,basis3.v+6);
PSMTXScale(scale3,basis3.v[6],basis3.v[7],basis3.v[8]);
}
PSMTXTrans(trans3,result[3],result[7],result[11]);
fn_802020F0(Camera_GetViewMtx(),view3);
PSMTXConcat(scale3,parent,result); PSMTXConcat(view3,result,result); PSMTXConcat(trans3,result,result);
break;
case (s32)0x80000000:
parent=(void *)(work+M2C_FIELD(node,s16 *,0xC)*0x30);
PSMTXTrans(trans4,result[3],result[7],result[11]);
PSMTXCopy(result,local4);
local4[3]=lbl_8036929C; local4[7]=lbl_8036929C; local4[11]=lbl_8036929C;
{ u8 *camera=Camera_Get(); fn_802031A8(camera+0xE0,camera+0xD4,direction4); }
fn_802020F0(result,temp4); fn_802029C4(temp4,direction4,direction4);
angle=lbl_8036929C;
if(angle!=direction4[0]) {
angle=fn_80237E90(direction4[2]/direction4[0]);
if(direction4[0]<lbl_8036929C) angle=lbl_803692A8-angle;
else angle=-angle-lbl_803692A8;
}
PSMTXRotRad(turn4,'Y',angle);
PSMTXConcat(turn4,parent,result); PSMTXConcat(local4,result,result); PSMTXConcat(trans4,result,result); break;
default: PSMTXConcat(result,(void *)(work+M2C_FIELD(node,s16 *,0xC)*0x30),result); break;
}
}
PSMTXConcat(Camera_GetViewMtx(),result,result);
GXLoadPosMtxImm(result,lbl_80285F40[count]);
fn_80202238(result,result); fn_80224DCC(result,lbl_80285F40[count]);
M2C_FIELD(node,s16 *,0xE)=lbl_80285F40[count];
seen[count++]=index;
}
next: node=M2C_FIELD(node,void **,4);
}
}

#pragma global_optimizer off
#pragma fp_contract off
void fn_8006B39C(void *node, void *actor, s32 work) {
void *GActor_GetNodeTable(void *);
void PSMTXRotRad(void *,s32,f32); void PSMTXScale(void *,f32,f32,f32); void PSMTXTrans(void *,f32,f32,f32);
void PSMTXCopy(void *,void *); void PSMTXConcat(void *,void *,void *); void PSMTXIdentity(void *);
void QUATMtx(void *,void *); int Game_Assert(void *,int,void *);
void fn_802029C4(void *,void *,void *); void fn_802031E8(void *,void *);
f32 fn_80203270(void *,void *); void fn_80203290(void *,void *,void *);
double fn_80238788(double); double fn_80237E90(double);
void fn_802024D0(void *,void *,f32); void fn_802020F0(void *,void *);
void fn_802031A8(void *,void *,void *); void *Camera_Get(void); void *Camera_GetViewMtx(void);
void fn_80202238(void *,void *); void fn_80224DCC(void *,u32);
void GXLoadPosMtxImm(void *,u32);
extern f32 lbl_80369298,lbl_8036929C,lbl_803692A0,lbl_803692A4,lbl_803692A8;
extern u8 lbl_8026B8AC[]; extern s16 lbl_80285F40[]; extern f32 lbl_8026B888[];
f32 root[12],result[12],parentMtx[12];
f32 rootZ[12],rootY[12],rootX[12],rootT[12],rootS[12];
f32 rz[12], ry[12], rx[12], trans[12], scale[12];
f32 rotation[12],translation[12],scaling[12],view[12];
f32 local[12],bone[12],turn[12],position[12],combined[12];
f32 trans3[12],scale3[12],view3[12];
f32 local4[12],turn4[12],trans4[12],temp4[12];
f32 align1[12],inv1[12],align3[12],inv3[12];
typedef struct { f32 v[9]; } Basis;

u8 *table;
typedef struct { f32 v[3]; } Vector;
Vector direction,direction4;
Basis basis1;
Vector axis1;
Basis basis3;
Vector axis3;
s32 i; u8 *info; Basis *basis=(Basis *)lbl_8026B888; s16 *slots; u8 *transformData; s32 count; u8 *cursor; u8 *joint; u32 index;
f32 dot,angle,angle2,angle4;
info=GActor_GetNodeTable(actor);
table=M2C_FIELD(node,u8 **,0x1C);
if(table==0) {
s16 *rootSlots; u8 *rootTransform; s32 rootCount;
rootSlots=lbl_80285F40; rootTransform=(u8 *)actor+0x10;
for(rootCount=0;rootCount<10;rootCount++,rootSlots++) {
switch(M2C_FIELD(actor,u32 *,0xC)) {
case 1:
PSMTXRotRad(rootX,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
PSMTXRotRad(rootY,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
PSMTXRotRad(rootZ,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
break;
case 2:
PSMTXRotRad(rootX,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
PSMTXRotRad(rootY,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
PSMTXRotRad(rootZ,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
break;
case 3:
PSMTXRotRad(rootX,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
PSMTXRotRad(rootY,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
PSMTXRotRad(rootZ,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
break;
case 4:
PSMTXRotRad(rootX,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
PSMTXRotRad(rootY,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
PSMTXRotRad(rootZ,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
break;
case 5:
PSMTXRotRad(rootX,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
PSMTXRotRad(rootY,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
PSMTXRotRad(rootZ,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
break;
case 6:
PSMTXRotRad(rootX,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
PSMTXRotRad(rootY,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
PSMTXRotRad(rootZ,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
break;
case 8:
PSMTXScale(rootS,M2C_FIELD(actor,f32 *,0x28),M2C_FIELD(actor,f32 *,0x2C),M2C_FIELD(actor,f32 *,0x30));
PSMTXTrans(rootT,M2C_FIELD(actor,f32 *,0x10),M2C_FIELD(actor,f32 *,0x14),M2C_FIELD(actor,f32 *,0x18));
QUATMtx(rootTransform,rootX);
PSMTXConcat(rootX,rootS,root); PSMTXConcat(rootX,root,root); PSMTXConcat(rootT,root,root); goto rootDone;
case 7: PSMTXCopy(rootTransform,root); goto rootDone;
default: Game_Assert(lbl_8026B8AC,0xB8,lbl_8026B8AC+8); break;
}
PSMTXScale(rootS,M2C_FIELD(actor,f32 *,0x28),M2C_FIELD(actor,f32 *,0x2C),M2C_FIELD(actor,f32 *,0x30));
PSMTXTrans(rootT,M2C_FIELD(actor,f32 *,0x10),M2C_FIELD(actor,f32 *,0x14),M2C_FIELD(actor,f32 *,0x18));
PSMTXConcat(rootX,rootS,root); PSMTXConcat(rootY,root,root); PSMTXConcat(rootZ,root,root); PSMTXConcat(rootT,root,root);

rootDone:
PSMTXConcat(Camera_GetViewMtx(),root,root);
GXLoadPosMtxImm(root,*rootSlots);
fn_80202238(root,root); fn_80224DCC(root,*rootSlots);
}
return;
}
cursor=table+2; i=table[1];
if((s32)table[0]!=0x10) Game_Assert(lbl_8026B8AC+0x27,0x3D4,lbl_8026B8AC+0x30);
if(i>10) Game_Assert(lbl_8026B8AC+0x27,0x3D5,lbl_8026B8AC+0x50);
if(M2C_FIELD(info,s32 *,8)>=256) Game_Assert(lbl_8026B8AC+0x27,0x3D6,lbl_8026B8AC+0x76);
slots=lbl_80285F40; transformData=(u8 *)actor+0x10;
for(count=0;count<i;slots++,count++) {
index=*cursor++;
joint=M2C_FIELD(info,u8 **,0xC)+index*0xF4;
switch(M2C_FIELD(actor,u32 *,0xC)) {
case 1:
PSMTXRotRad(rx,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
PSMTXRotRad(ry,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
PSMTXRotRad(rz,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
break;
case 2:
PSMTXRotRad(rx,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
PSMTXRotRad(ry,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
PSMTXRotRad(rz,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
break;
case 3:
PSMTXRotRad(rx,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
PSMTXRotRad(ry,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
PSMTXRotRad(rz,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
break;
case 4:
PSMTXRotRad(rx,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
PSMTXRotRad(ry,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
PSMTXRotRad(rz,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
break;
case 5:
PSMTXRotRad(rx,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
PSMTXRotRad(ry,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
PSMTXRotRad(rz,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
break;
case 6:
PSMTXRotRad(rx,'Z',lbl_80369298*M2C_FIELD(actor,f32 *,0x24));
PSMTXRotRad(ry,'Y',lbl_80369298*M2C_FIELD(actor,f32 *,0x20));
PSMTXRotRad(rz,'X',lbl_80369298*M2C_FIELD(actor,f32 *,0x1C));
break;
case 8:
PSMTXScale(scale,M2C_FIELD(actor,f32 *,0x28),M2C_FIELD(actor,f32 *,0x2C),M2C_FIELD(actor,f32 *,0x30));
PSMTXTrans(trans,M2C_FIELD(actor,f32 *,0x10),M2C_FIELD(actor,f32 *,0x14),M2C_FIELD(actor,f32 *,0x18));
QUATMtx(transformData,rx);
PSMTXConcat(rx,scale,result); PSMTXConcat(rx,result,result); PSMTXConcat(trans,result,result); goto transformed;
case 7: PSMTXCopy(transformData,result); goto transformed;
default: Game_Assert(lbl_8026B8AC,0xB8,lbl_8026B8AC+8); break;
}
PSMTXScale(scale,M2C_FIELD(actor,f32 *,0x28),M2C_FIELD(actor,f32 *,0x2C),M2C_FIELD(actor,f32 *,0x30));
PSMTXTrans(trans,M2C_FIELD(actor,f32 *,0x10),M2C_FIELD(actor,f32 *,0x14),M2C_FIELD(actor,f32 *,0x18));
PSMTXConcat(rx,scale,result); PSMTXConcat(ry,result,result); PSMTXConcat(rz,result,result); PSMTXConcat(trans,result,result);

transformed:
PSMTXConcat((void *)(work+index*0x30),joint+0x10,parentMtx);
switch((s32)(M2C_FIELD(node,u32 *,0x10)&0xE0000000)) {
case 0x20000000:

basis1=*basis;
PSMTXCopy(result,inv1);
inv1[3]=lbl_8036929C; inv1[7]=lbl_8036929C; inv1[11]=lbl_8036929C;
fn_802029C4(inv1,basis1.v,basis1.v);
if(lbl_8036929C==basis1.v[2]*basis1.v[2]+(basis1.v[0]*basis1.v[0]+basis1.v[1]*basis1.v[1])) {
PSMTXScale(scaling,lbl_8036929C,lbl_8036929C,lbl_8036929C);
} else {
fn_802031E8(basis1.v,basis1.v); dot=fn_80203270(basis1.v,basis1.v+3);
if(lbl_803692A0==dot) PSMTXIdentity(align1);
else if(lbl_803692A4==dot) PSMTXScale(align1,lbl_803692A4,lbl_803692A4,lbl_803692A4);
else { angle=fn_80238788(dot); fn_80203290(basis1.v,basis1.v+3,axis1.v); fn_802024D0(align1,axis1.v,angle); }
fn_802029C4(inv1,basis1.v+6,basis1.v+6); fn_802029C4(align1,basis1.v+6,basis1.v+6);
PSMTXScale(scaling,basis1.v[6],basis1.v[7],basis1.v[8]);
}
PSMTXConcat(result,parentMtx,root);
PSMTXTrans(translation,root[3],root[7],root[11]);
PSMTXCopy(parentMtx,rotation); rotation[3]=lbl_8036929C; rotation[7]=lbl_8036929C; rotation[11]=lbl_8036929C;
fn_802020F0(Camera_GetViewMtx(),view);
PSMTXConcat(scaling,rotation,root); PSMTXConcat(view,root,root); PSMTXConcat(translation,root,root);
break;
case 0x40000000:

PSMTXConcat(result,parentMtx,combined); PSMTXTrans(position,combined[3],combined[7],combined[11]);
PSMTXCopy(parentMtx,bone); PSMTXCopy(result,local);
bone[3]=lbl_8036929C; bone[7]=lbl_8036929C; bone[11]=lbl_8036929C; local[3]=lbl_8036929C; local[7]=lbl_8036929C; local[11]=lbl_8036929C;
{ u8 *camera=Camera_Get(); fn_802031A8(camera+0xE0,camera+0xD4,direction.v); }
fn_802020F0(result,combined); fn_802029C4(combined,direction.v,direction.v);
if(lbl_8036929C==direction.v[0]) PSMTXIdentity(turn);
else { angle2=fn_80237E90(direction.v[2]/direction.v[0]);
if(direction.v[0]<lbl_8036929C) angle2=lbl_803692A8-angle2;
else angle2=-angle2-lbl_803692A8;
PSMTXRotRad(turn,'Y',angle2); }
PSMTXConcat(turn,bone,combined); PSMTXConcat(local,combined,combined); PSMTXConcat(position,combined,root);
break;
case 0x60000000:

basis3=*basis;
PSMTXCopy(result,inv3);
inv3[3]=lbl_8036929C; inv3[7]=lbl_8036929C; inv3[11]=lbl_8036929C;
fn_802029C4(inv3,basis3.v,basis3.v);
if(lbl_8036929C==basis3.v[2]*basis3.v[2]+(basis3.v[0]*basis3.v[0]+basis3.v[1]*basis3.v[1])) {
PSMTXScale(scale3,lbl_8036929C,lbl_8036929C,lbl_8036929C);
} else {
fn_802031E8(basis3.v,basis3.v); dot=fn_80203270(basis3.v,basis3.v+3);
if(lbl_803692A0==dot) PSMTXIdentity(align3);
else if(lbl_803692A4==dot) PSMTXScale(align3,lbl_803692A4,lbl_803692A4,lbl_803692A4);
else { angle=fn_80238788(dot); fn_80203290(basis3.v,basis3.v+3,axis3.v); fn_802024D0(align3,axis3.v,angle); }
fn_802029C4(inv3,basis3.v+6,basis3.v+6); fn_802029C4(align3,basis3.v+6,basis3.v+6);
PSMTXScale(scale3,basis3.v[6],basis3.v[7],basis3.v[8]);
}
PSMTXTrans(trans3,result[3],result[7],result[11]);
fn_802020F0(Camera_GetViewMtx(),view3);
PSMTXConcat(scale3,parentMtx,root); PSMTXConcat(view3,root,root); PSMTXConcat(trans3,root,root);
break;
case (s32)0x80000000:

PSMTXTrans(trans4,result[3],result[7],result[11]);
PSMTXCopy(result,local4);
local4[3]=lbl_8036929C; local4[7]=lbl_8036929C; local4[11]=lbl_8036929C;
{ u8 *camera=Camera_Get(); fn_802031A8(camera+0xE0,camera+0xD4,direction4.v); }
fn_802020F0(result,temp4); fn_802029C4(temp4,direction4.v,direction4.v);
angle4=lbl_8036929C;
if(angle4!=direction4.v[0]) {
angle4=fn_80237E90(direction4.v[2]/direction4.v[0]);
if(direction4.v[0]<lbl_8036929C) angle4=lbl_803692A8-angle4;
else angle4=-angle4-lbl_803692A8;
}
PSMTXRotRad(turn4,'Y',angle4);
PSMTXConcat(turn4,parentMtx,root); PSMTXConcat(local4,root,root); PSMTXConcat(trans4,root,root); break;
default: PSMTXConcat(result,parentMtx,root); break;
}
PSMTXConcat(Camera_GetViewMtx(),root,root);
GXLoadPosMtxImm(root,*slots);
fn_80202238(root,root); fn_80224DCC(root,*slots);
}
}
#pragma optimization_level 4
#pragma fp_contract on
#pragma global_optimizer reset

#pragma use_lmw_stmw on
void fn_8006C2A4(void *arg0,s32 arg1){
u32 fn_80060638(void*);s32 fn_80060664(void*);u32 fn_800605E0(void*);s32 fn_8006049C(void*);s32 fn_80060520(void*);s32 fn_800604F4(void*);s32 fn_800604C8(void*);
void fn_80220154(s32,s32,s32);void Game_Assert(void*,s32,void*);void GMaterial_ApplyRenderState(void*,s32);
void fn_8006B39C(void*,void*,s32);void fn_8006A930(void*,void*,s32);void GXSetCurrentMtx(s16);
void fn_802245D8(s32,s32,s32,s32);void GXSetZMode(s32,s32,s32);void fn_80067490(s32);
void Gfx_SetupVtxFormat(u32,u8,u8,u8,s32);u8 fn_80068D84(void*,s32,void*,s32);void fn_80224A68(s32,s32);void fn_80066D00(s32);void fn_80069C98(void);
extern u8 lbl_8026B8AC[];extern void *gGMaterialCurrent,*gGMaterialNode;
u8 *data,*node,*p;
s32 aux,work,addr1,addr2;
u32 geometry,last,format;
u8 draw,reset;
data=(u8*)fn_80060638(arg0);aux=fn_80060664(arg0);geometry=fn_800605E0(arg0);work=fn_8006049C(arg0);last=-1;
fn_80220154(11,*(s32*)(data+0x30),4);fn_80220154(12,*(s32*)(data+0x30),4);
fn_80220154(13,*(s32*)(data+0x2c),4);fn_80220154(14,*(s32*)(data+0x2c),4);
/* Original initializes GQR2 through GQR5 here. */
switch(arg1){
case 0:node=*(u8**)(data+0x3c);break;
case 1:node=*(u8**)(data+0x40);break;
case 2:node=*(u8**)(data+0x44);break;
default:Game_Assert(lbl_8026B8AC+0x27,0x162,lbl_8026B8AC+0x9d);break;
}
draw=1;GMaterial_ApplyRenderState(arg0,arg1);
for(p=node;p;p=*(u8**)(p+4))*(s16*)(p+0xe)=-1;
for(;node;node=*(u8**)(node+4)){
if(!(*(u16*)(node+8)&0x400)&&(!(*(u32*)arg0&0x400000)||(*(u16*)(node+8)&0x8000))){
if(*(u16*)(node+8)&2)fn_8006B39C(node,arg0,work);
else{if(*(s16*)(node+0xe)<0)fn_8006A930(node,arg0,work);GXSetCurrentMtx(*(s16*)(node+0xe));}
if(*(u16*)(node+8)&0x1e0){
if(*(u16*)(node+8)&0x40)fn_802245D8(1,4,1,0);
if(*(u16*)(node+8)&0x80)fn_802245D8(3,0,0,0);
if(*(u16*)(node+8)&0x100)GXSetZMode(0,3,0);
if(*(u16*)(node+8)&0x20)fn_80067490(0);
}
gGMaterialCurrent=arg0;gGMaterialNode=node;
format=*(u32*)(node+0x10)&0xfffffff;
if(last!=format){
last=format;
if(*(u16*)(node+8)&1){
Gfx_SetupVtxFormat(format,(*(u8**)(data+0x48))[0xc],0,data[0x5e],1);
fn_80220154(9,fn_80060520(arg0),12);
if(format&0x800)fn_80220154(25,fn_80060520(arg0)+6,12);
else fn_80220154(10,fn_80060520(arg0)+6,12);
}else {
Gfx_SetupVtxFormat(format,data[0x5c],data[0x5d],data[0x5e],0);
if(!geometry){
fn_80220154(9,*(s32*)(data+0x24),6);
if(format&0x800)fn_80220154(25,*(s32*)(data+0x28),3);
else fn_80220154(10,*(s32*)(data+0x28),3);
}else{
addr1=fn_800604F4(arg0);addr2=fn_800604C8(arg0);fn_80220154(9,addr1,6);
if(format&0x800)fn_80220154(25,addr2,3);else fn_80220154(10,addr2,3);
}
}
}
if((*(u32*)arg0&0xc00000)||!(*(u16*)(node+8)&4))draw=fn_80068D84(arg0,aux,node,*(s32*)(data+0x34)+(*(s16*)(node+0xa)<<5));
if(draw)fn_80224A68(*(s32*)(node+0x14),*(s32*)(node+0x18));
if(!(*(u16*)(node+8)&0x1e0))reset=0;else {fn_80066D00(-1);reset=1;}
if(reset)GMaterial_ApplyRenderState(arg0,arg1);
fn_80069C98();
}
}
if(*(u32*)arg0&0xf025c820){
if(*(u32*)arg0&0x80000000)(*(void(**)(void*,s32))((u8*)arg0+0x94))(arg0,1);
fn_80066D00(-1);
}
}
void fn_8006C6F8(void *arg0) {
    void fn_80066D00(s32);
    s32 temp_r5;

    temp_r5 = *(s32 *)arg0;
    if (temp_r5 & 0xF025C820) {
        if (temp_r5 & 0x80000000) {
            (*(void (**)(void *, s32))((u8 *)arg0 + 0x94))(arg0, 1);
        }
        fn_80066D00(-1);
    }
}

/* Apply GX blend, Z-mode, and channel-update state from a material's flag word. */
void GMaterial_ApplyRenderState(void *mat, s32 pass) {
    void fn_80067490(s32);
    void fn_80223E5C(s32, s32, s32, s32, s32);
    void fn_802245D8(s32, s32, s32, s32);
    void fn_8022462C(s32);
    void fn_80224658(s32);
    void GXSetZMode(s32, s32, s32);
    s32 flags;
    s32 zMode;

    flags = M2C_FIELD(mat, s32 *, 0);
    if (flags & 0xF025C820) {
        if (flags & 0x200020) {
            switch (pass) {
            case 0:
                fn_802245D8(1, 4, 5, 7);
                GXSetZMode(1, 3, 1);
                /* fallthrough */
            case 1:
                fn_80223E5C(4, 0, 1, 0, 0);
                break;
            }
        }
        if (flags & 0x8000) {
            fn_80223E5C(4, 0, 1, 0, 0);
            fn_80224658(1);
        }
        if (flags & 0x4000) {
            fn_8022462C(0);
        }
        if (flags & 0x800) {
            fn_802245D8(1, 4, 1, 0);
        }
        if (flags & 0x40000) {
            fn_80067490(0);
        }
        if (flags & 0x10000) {
            fn_802245D8(0, 0, 0, 0);
        }
        zMode = flags & 0x70000000;
        switch (zMode) {
        case 0x10000000:
            GXSetZMode(0, 7, 0);
            break;
        case 0x20000000:
            GXSetZMode(1, 4, 0);
            break;
        case 0x30000000:
            GXSetZMode(1, 5, 0);
            break;
        case 0x50000000:
            GXSetZMode(1, 3, 1);
            break;
        case 0x40000000:
            GXSetZMode(1, 3, 0);
            break;
        }
        if (M2C_FIELD(mat, s32 *, 0) & 0x80000000) {
            M2C_FIELD(mat, void (**)(void *, s32), 0x94)(mat, 0);
        }
    }
}

void fn_8006C944(u32 *arg0) {
    void fn_8006C2A4(void *, s32);
    void fn_80223E5C(s32, s32, s32, s32, s32);
    void fn_802246B8(s32);
    u32 saved_w;
    u8 saved_b;

    saved_b = *((u8 *)arg0 + 0xB);
    saved_w = *arg0;
    if (saved_b != 0) {
        *arg0 = saved_w & 0x8FFF7FDF;
        *arg0 = *arg0 | 0x50004000;
        *((u8 *)arg0 + 0xB) = 0xFF;
        fn_802246B8(0);
        fn_80223E5C(6, 0x80, 1, 0, 0);
        fn_8006C2A4(arg0, 1);
        *((u8 *)arg0 + 0xB) = saved_b;
        *arg0 = saved_w;
    }
}

void fn_8006C9E8(u32 *arg0) {
    void fn_8006C2A4(void *, s32);
    u32 saved_w;
    u8 saved_b;

    saved_b = *((u8 *)arg0 + 0xB);
    saved_w = *arg0;
    if (saved_b != 0) {
        *arg0 = saved_w & 0x8FFF7FDF;
        *arg0 = *arg0 | 0x50006000;
        *((u8 *)arg0 + 0xB) = 0xFF;
        fn_8006C2A4(arg0, 0);
        *((u8 *)arg0 + 0xB) = saved_b;
        *arg0 = saved_w;
    }
}



void fn_8006CA68(void *arg0) {
    M2C_UNK fn_8006C2A4(void *, M2C_UNK);
    fn_8006C2A4(arg0, 2);
}

void fn_8006CA8C(void *arg0) {
    M2C_UNK fn_8006C2A4(void *, M2C_UNK);
    fn_8006C2A4(arg0, 1);
}

void fn_8006CAB0(s32 arg0) {
    void fn_8006C2A4(s32, s32);
    fn_8006C2A4(arg0, 0);
}

#pragma optimization_level 1
void fn_8006CAD4(u32 *node) {
    u32 fn_80060638(void *);
    void fn_80067708(s32, s32, void *, void *);
    void fn_8006C9E8(u32 *);
    void fn_8006C944(u32 *);
    void fn_8006CAB0(s32);
    void fn_8006CA8C(void *);
    void fn_8006CA68(void *);
    void fn_8014E824(void *);
    u32 *data;
    s32 v0;
    s32 v1;
    s32 v2;
    s32 idx;
    u32 *child;
    u32 flags;

    child = *(u32 **)((u8 *)node + 0x8C);
    if (child != NULL) {
        fn_8006CAD4(child);
    }
    data = (u32 *)fn_80060638(node);
    if (*((u8 *)node + 0xB) == 0) {
        return;
    }
    flags = *node;
    idx = *((u8 *)node + 0x87);
    v0 = 0;
    v1 = 1;
    v2 = 2;
    if (flags & 0x380020) {
        if (flags & 0x80000) {
            v1 = 0;
            v2 = v0;
            v0 = v1;
        }
        if (flags & 0x100000) {
            v1 = 1;
            v2 = 1;
            v0 = v1;
        }
        if (flags & 0x200020) {
            v1 = 2;
            v2 = 2;
            v0 = v1;
        }
    }
    if ((flags & 0x20) && ((flags & 0x70000000) == 0x60000000)) {
        if (data[0xF] != 0) {
            fn_80067708(2, idx, fn_8006C9E8, node);
        }
        if (data[0x10] != 0) {
            fn_80067708(2, idx, fn_8006C944, node);
        }
    }
    if (data[0xF] != 0) {
        fn_80067708(v0, idx, fn_8006CAB0, node);
    }
    if (data[0x10] != 0) {
        fn_80067708(v1, idx, fn_8006CA8C, node);
    }
    if (data[0x11] != 0) {
        fn_80067708(v2, idx, fn_8006CA68, node);
    }
    if (*(u32 *)((u8 *)node + 0x54) != 0) {
        fn_8014E824(node);
    }
}
#pragma optimization_level reset
void fn_8006CC6C(s32 arg0) {
    M2C_UNK fn_8003F670(s32);
    M2C_UNK fn_8003FCF0();
    s32 fn_8005C368();
    M2C_UNK fn_80068558(s32, M2C_UNK, M2C_UNK);
    fn_8003FCF0();
    if (fn_8005C368() <= 1) {
        fn_80068558(arg0, 0, 0);
    }
    fn_8003F670(arg0);
}

void *fn_8006CCBC(char *name, s32 flags) {
extern u32 FileCache_GetFlags(void *);
void *Archive_LoadFlags(char *,s32);
extern f32 lbl_803692AC;
u8 fresh=1;
void *archive;
u32 *reloc;
s32 b,g,r;
u8 *material;
s32 i;
s32 offset;
f32 factor;
if(FileCache_GetFlags(name)&0x4000) fresh=0;
archive=Archive_LoadFlags(name,flags);
if(fresh) {
reloc=M2C_FIELD(archive,u32 **,0x48);
if(reloc) {reloc[0]+=(u32)reloc;reloc[1]+=(u32)reloc;}
i=0;
factor=lbl_803692AC;
offset=i;
for(;i<M2C_FIELD(archive,u16 *,0x54);offset+=0x20,i++) {
material=M2C_FIELD(archive,u8 **,0x34)+offset;
r=(s32)(factor*(f32)material[8]);
g=(s32)(factor*(f32)material[9]);
b=(s32)(factor*(f32)material[10]);
if(r>255) r=255;
if(g>255) g=255;
if(b>255) b=255;
material[8]=r;material[9]=g;material[10]=b;
}
}
return archive;
}

void *fn_8006CE14(char *name) {
    extern u32 FileCache_GetFlags(void *);
    void *Archive_LoadFlags(char *,s32);
    extern f32 lbl_803692AC;
    u8 fresh=1;
    void *archive;
    u32 *reloc;
    s32 b,g,r;
    u8 *material;
    s32 i;
    s32 offset;
    f32 factor;
    if(FileCache_GetFlags(name)&0x4000) fresh=0;
    archive=Archive_LoadFlags(name,0);
    if(fresh) {
        reloc=M2C_FIELD(archive,u32 **,0x48);
        if(reloc) {
            reloc[0]+=(u32)reloc;
            reloc[1]+=(u32)reloc;
        }
        i=0;
        factor=lbl_803692AC;
        offset=i;
        for(;i<M2C_FIELD(archive,u16 *,0x54);offset+=0x20,i++) {
            material=M2C_FIELD(archive,u8 **,0x34)+offset;
            r=(s32)(factor*(f32)material[8]);
            g=(s32)(factor*(f32)material[9]);
            b=(s32)(factor*(f32)material[10]);
            if(r>255) r=255;
            if(g>255) g=255;
            if(b>255) b=255;
            material[8]=r;
            material[9]=g;
            material[10]=b;
        }
    }
    return archive;
}

#pragma use_lmw_stmw on
void fn_8006CF60(void *arg0)
{
  volatile unsigned short new_var11;
  u8 *new_var6;
  void *memcpy(void *, const void *, u32);
  volatile unsigned int new_var12;
  s32 *kf_prev;
  void DCFlushRange(void *, u32);
  void __mtspr(s32, u32);
  s32 i;
  u8 new_var3;
  u8 **new_var4;
  u8 *self;
  u8 *mesh;
  s8 new_var10;
  unsigned int new_var9;
  int new_var2;
  u8 *anim;
  u8 *entry;
  u8 *new_var5;
  unsigned int new_var7;
  u8 *dst;
  u8 new_var8;
  s32 *kf;
  int new_var13;
  f32 t;
  s32 n;
  f32 w;
  f32 v;
  f32 d;
  char gqr;
  s32 **new_var;
  f32 new_var16;
  s8 tmp8;
  u16 tmp;
  u8 new_var15;
  short new_var14;
  self = (u8 *) arg0;
  mesh = *((u8 **) (self + 0x48));
  new_var5 = mesh + 0x4C;
  anim = *((u8 **) (self + 0x50));
  new_var12 = (*((u16 *) (mesh + 0x4E))) * 3;
  kf = *((s32 **) (anim + 0x20));
  memcpy(*((void **) (self + 0x6C)), *((void **) (mesh + 0x24)), ((*((u16 *) (mesh + 0x4E))) * 3) + ((*((u16 *) new_var5)) * 6));
  new_var11 = ((u32) anim[8]) << 8;
  n = *((s32 *) (anim - (-0x1C)));
  if (((n - 1) - 1) > ((0 - 1) - 1))
  {
    do
    {
      do
      {
        new_var16 = *((f32 *) (self + 0x58));
        if (new_var16 < ((f32) (*kf)))
        {
          if (((!tmp8) && (!tmp8)) && (!tmp8))
          {
          }
        }
        kf_prev = kf;
        kf = (s32 *) (((u8 *) kf) + 0x1C);
      }
      while (--n);
    }
    while (0);
  }
  gqr = ((long) new_var11) | 6;
  ;
  __mtspr(914, (gqr << 16) | (gqr & 0x7FFF));
  mesh = *((u8 **) (self + 0x48));
  gqr = (((u32) mesh[0x5C]) << 8) | 7;
  gqr = ((gqr << 5) << 11) | (gqr & 0xFFFF);
  i = 0;
  __mtspr(915, gqr);
  t = (new_var16 - ((f32) kf_prev[0])) / ((f32) (kf[0] - kf_prev[0]));
  new_var14 = 2;
  entry = (*((u8 **) (anim + 0x24))) + (kf[1] << new_var14);
  new_var6 = *((u8 **) (self + 0x6C));
  new_var7 = 0;
  new_var = &kf;
  dst = new_var6;
  while (i < (*new_var)[new_var14])
  {
    dst += entry[0] * 6;
    d = (f32) entry[1];
    v = d * t;
    v = ((f32) (*((s16 *) (dst + new_var7)))) + v;
    new_var9 = new_var7;
    tmp = (u16) ((s32) v);
    new_var7 = new_var9;
    *((u16 *) (dst + new_var7)) = tmp;
    d = (f32) ((s8) entry[new_var14]);
    v = d * t;
    v = ((f32) (*((s16 *) (dst + new_var14)))) + v;
    tmp = (u16) ((s32) v);
    *((u16 *) (dst + 4)) = (*((u16 *) (dst + new_var14)) = tmp);
    d = (f32) ((s8) entry[3]);
    v = d * t;
    v = ((f32) (*((s16 *) (dst + 4)))) + v;
    tmp = (u16) ((s32) v);
    i++;
    entry += 4;
  }

  w = lbl_803692B8 - t;
  i = new_var7;
  entry = (*((u8 **) (anim + 0x24))) + (kf_prev[1] << new_var14);
  new_var13 = 1;
  dst = new_var6;
  while (i < kf_prev[new_var14])
  {
    gqr = entry[0] * 6;
    dst += gqr;
    new_var15 = entry[1];
    d = (f32) ((s8) new_var15);
    v = d;
    v = v * w;
    v = ((f32) (*((s16 *) (dst + new_var7)))) + v;
    tmp = (u16) ((s32) v);
    *((u16 *) (dst + new_var7)) = tmp;
    break;
    d = (f32) ((s8) entry[new_var14]);
    v = d * w;
    v = ((f32) (*((s16 *) (dst + new_var14)))) + v;
    tmp = (u16) ((s32) v);
    *((u16 *) (dst + new_var14)) = tmp;
    d = (f32) ((s8) entry[3]);
    v = d * w;
    v = ((f32) (v = *((s16 *) (dst + 4)))) + v;
    i = new_var7;
    tmp = (u16) ((s32) v);
    *((u16 *) (dst + 4)) = (tmp & 0xFF) & 0xFF;
    i++;
    entry += 4;
  }

  gqr = (((u32) anim[9]) << 8) | 6;
  gqr = gqr << 16;
  gqr = gqr | (gqr & 0x7FFF);
  __mtspr(914, gqr);
  __mtspr(916, 0x07060706);
  w = lbl_803692B8 - w;
  ;
  entry = (*((u8 **) (anim + 0x28))) + ((*new_var)[3] << new_var14);
  dst = *((u8 **) (self + 0x70));
  while (new_var7 < (*new_var)[4])
  {
    dst += entry[0] * 3;
    tmp8 = (s8) ((s32) v);
    d = (f32) ((s8) entry[new_var13]);
    v = d * w;
    v = ((f32) ((s8) dst[new_var7])) + v;
    tmp8 = (s8) ((s32) v);
    dst[0] = (u8) tmp8;
    d = (f32) ((s8) entry[new_var14]);
    v = d * w;
    v = ((f32) ((s8) dst[1])) + v;
    dst[1] = (u8) tmp8;
    new_var8 = dst[new_var14];
    d = (f32) ((s8) entry[3]);
    v = d * w;
    v = ((f32) ((s8) new_var8)) + v;
    dst[new_var14] = (u8) tmp8;
    tmp8 = (s8) ((s32) v);
    i++;
    entry += 4;
  }

  w = lbl_803692B8 - w;
  entry = (*((u8 **) (anim + 0x28))) + (kf_prev[3] << new_var14);
  dst = *((u8 **) (self + 0x70));
  new_var4 = (u8 **) (self + 0x48);
  v = ((f32) ((s8) dst[new_var7])) + v;
  new_var10 = (s8) entry[new_var14];
  while (i < kf_prev[4])
  {
    dst += entry[new_var7] * 3;
    d = (f32) ((s8) entry[1]);
    new_var3 = entry[3];
    v = (v = d * w);
    tmp8 = (s8) ((s32) v);
    dst[0] = (u8) tmp8;
    d = (f32) new_var10;
    v = ((f32) ((s8) dst[new_var13])) + v;
    tmp8 = (tmp8 = (s8) ((s32) v));
    dst[new_var13] = (dst[new_var14] = (u8) tmp8);
    d = (f32) ((s8) new_var3);
    v = ((f32) ((s8) dst[new_var14])) + v;
    i++;
    entry += 4;
  }

  mesh = *new_var4;
  new_var2 = 6;
  DCFlushRange(*((void **) (self + 0x6C)), ((*((u16 *) (0x4C + mesh))) * new_var2) + ((*((u16 *) (mesh + 0x4E))) * 3));
  __mtspr(914, 0x00040004);
  __mtspr(915, 0x00050005);
  v = d * w;
  __mtspr(916, 0x00060006);
  __mtspr(917, 0x00070007);
}

#pragma optimization_level 3
void fn_8006D378(s32 arg0) {
    u32 fn_80060638(void *);
    u32 fn_80060520(void *);
    u32 fn_80060470(void *);
    void fn_8006D52C(s32);
    void fn_8006D53C(s32);
    void fn_8006D54C(s32, s32, s32, u16);
    void fn_8006D66C(s32, s32, s32, u16);
    void fn_8006D828(s32, void *, void *, s32);
    void fn_80205348(s32, s32, s32);
    void fn_8020536C(s32, s32, s32);
    void fn_8020543C(s32);
    s32 i;
    u8 *entry;
    u8 *mesh;
    u32 vtx;
    u32 tex;
    mesh = *(u8 **)((u8 *)fn_80060638((void *)arg0) + 0x48);
    tex = fn_80060520((void *)arg0);
    entry = *(u8 **)mesh;
    vtx = fn_80060470((void *)arg0);
    fn_8006D52C((mesh[0xc] << 8) + 7);
    fn_8006D53C(0x804);
    fn_80205348(0xE0000000, *(s32 *)(mesh + 4) + *(s32 *)(entry + 0xc), (s32)(*(u16 *)(entry + 0x10) + 0x1f) / 32);
    for (i = 0; i < *(s16 *)(mesh + 8) - 1; i++) {
        fn_80205348(0xE0000000 + (((i + 1) & 1) << 12), *(s32 *)(mesh + 4) + *(s32 *)(entry + 0x24), (s32)(*(u16 *)(entry + 0x28) + 0x1f) / 32);
        fn_8006D828(vtx, entry, entry + 8, entry[0x13]);
        fn_8020543C(1);
        arg0 = 0xE0000000 + ((i & 1) << 12);
        fn_8006D54C(0, arg0 + entry[0x12], arg0 + entry[0x12], *(u16 *)(entry + 0x14));
        fn_8006D66C(0, arg0 + entry[0x12], arg0 + entry[0x12], *(u16 *)(entry + 0x16));
        fn_8020536C(tex + *(s32 *)(entry + 0xc), arg0, (s32)(*(u16 *)(entry + 0x10) + 0x1f) / 32);
        entry += 0x18;
    }
    fn_8006D828(vtx, entry, entry + 8, entry[0x13]);
    arg0 = 0xE0000000 + ((i & 1) << 12);
    fn_8006D54C(0, arg0 + entry[0x12], arg0 + entry[0x12], *(u16 *)(entry + 0x14));
    fn_8006D66C(0, arg0 + entry[0x12], arg0 + entry[0x12], *(u16 *)(entry + 0x16));
    fn_8020536C(tex + *(s32 *)(entry + 0xc), arg0, (s32)(*(u16 *)(entry + 0x10) + 0x1f) / 32);
}
#pragma optimization_level reset
void fn_8006D52C(s32 arg0) {
    register u32 gqr;
    gqr = ((u32)arg0 << 16) + (u32)arg0;
    *(volatile u32 *)0 = gqr;
}

void fn_8006D53C(register s32 arg0) {
    register u32 gqr = ((u32)arg0 << 16) + (u32)arg0;
    *(volatile u32 *)0 = gqr;
}

void fn_8006D54C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r6;
    s32 temp_r7;
    s32 var_ctr;

    temp_r6 = arg3 & arg3;
    if (temp_r6 != 0) {
        temp_r7 = temp_r6 - 1;
        M2C_ERROR(/* unknown instruction: psq_lu $f12, 0x4($r4), 0x0, qr6 */);
        var_ctr = temp_r7;
        M2C_ERROR(/* unknown instruction: psq_lu $f13, 0x4($r4), 0x0, qr6 */);
        M2C_ERROR(/* unknown instruction: ps_madds0 $f15, $f0, $f12, $f6 */);
        M2C_ERROR(/* unknown instruction: ps_madds0 $f16, $f1, $f12, $f7 */);
        M2C_ERROR(/* unknown instruction: ps_muls1 $f17, $f0, $f13 */);
        M2C_ERROR(/* unknown instruction: psq_lu $f14, 0x4($r4), 0x0, qr6 */);
        M2C_ERROR(/* unknown instruction: ps_muls1 $f18, $f1, $f13 */);
        if (temp_r7 & temp_r7) {
            M2C_ERROR(/* unknown instruction: ps_madds1 $f15, $f2, $f12, $f15 */);
            M2C_ERROR(/* unknown instruction: ps_madds1 $f16, $f3, $f12, $f16 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f17, $f2, $f14, $f17 */);
            M2C_ERROR(/* unknown instruction: psq_lu $f12, 0x4($r4), 0x0, qr6 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f18, $f3, $f14, $f18 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f8, $f4, $f13, $f15 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f9, $f5, $f13, $f16 */);
            M2C_ERROR(/* unknown instruction: psq_lu $f13, 0x4($r4), 0x0, qr6 */);
            M2C_ERROR(/* unknown instruction: ps_madds1 $f10, $f4, $f14, $f17 */);
            M2C_ERROR(/* unknown instruction: ps_madds1 $f11, $f5, $f14, $f18 */);
            M2C_ERROR(/* unknown instruction: psq_lu $f14, 0x4($r4), 0x0, qr6 */);
            do {
                M2C_ERROR(/* unknown instruction: ps_madds0 $f15, $f0, $f12, $f6 */);
                M2C_ERROR(/* unknown instruction: psq_stu $f8, 0x2($r5), 0x0, qr6 */);
                M2C_ERROR(/* unknown instruction: ps_madds0 $f16, $f1, $f12, $f7 */);
                M2C_ERROR(/* unknown instruction: psq_stu $f9, 0x4($r5), 0x1, qr6 */);
                M2C_ERROR(/* unknown instruction: ps_muls1 $f17, $f0, $f13 */);
                M2C_ERROR(/* unknown instruction: psq_stu $f10, 0x2($r5), 0x0, qr6 */);
                M2C_ERROR(/* unknown instruction: ps_muls1 $f18, $f1, $f13 */);
                M2C_ERROR(/* unknown instruction: psq_stu $f11, 0x4($r5), 0x1, qr6 */);
                M2C_ERROR(/* unknown instruction: ps_madds1 $f15, $f2, $f12, $f15 */);
                M2C_ERROR(/* unknown instruction: ps_madds1 $f16, $f3, $f12, $f16 */);
                M2C_ERROR(/* unknown instruction: psq_lu $f12, 0x4($r4), 0x0, qr6 */);
                M2C_ERROR(/* unknown instruction: ps_madds0 $f17, $f2, $f14, $f17 */);
                M2C_ERROR(/* unknown instruction: ps_madds0 $f18, $f3, $f14, $f18 */);
                M2C_ERROR(/* unknown instruction: ps_madds0 $f8, $f4, $f13, $f15 */);
                M2C_ERROR(/* unknown instruction: ps_madds0 $f9, $f5, $f13, $f16 */);
                M2C_ERROR(/* unknown instruction: psq_lu $f13, 0x4($r4), 0x0, qr6 */);
                M2C_ERROR(/* unknown instruction: ps_madds1 $f10, $f4, $f14, $f17 */);
                M2C_ERROR(/* unknown instruction: ps_madds1 $f11, $f5, $f14, $f18 */);
                M2C_ERROR(/* unknown instruction: psq_lu $f14, 0x4($r4), 0x0, qr6 */);
                var_ctr -= 1;
            } while (var_ctr != 0);
        } else {
            M2C_ERROR(/* unknown instruction: ps_madds1 $f15, $f2, $f12, $f15 */);
            M2C_ERROR(/* unknown instruction: ps_madds1 $f16, $f3, $f12, $f16 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f17, $f2, $f14, $f17 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f18, $f3, $f14, $f18 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f8, $f4, $f13, $f15 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f9, $f5, $f13, $f16 */);
            M2C_ERROR(/* unknown instruction: ps_madds1 $f10, $f4, $f14, $f17 */);
            M2C_ERROR(/* unknown instruction: ps_madds1 $f11, $f5, $f14, $f18 */);
        }
        M2C_ERROR(/* unknown instruction: psq_stu $f8, 0x2($r5), 0x0, qr6 */);
        M2C_ERROR(/* unknown instruction: psq_stu $f9, 0x4($r5), 0x1, qr6 */);
        M2C_ERROR(/* unknown instruction: psq_stu $f10, 0x2($r5), 0x0, qr6 */);
        M2C_ERROR(/* unknown instruction: psq_stu $f11, 0x4($r5), 0x1, qr6 */);
    }
}

void fn_8006D66C(s32 arg1, s32 arg2, s32 arg3) {
    if (arg3 != 0) {
        s32 count = (arg3 >> 1) - 1;
        if (count != 0) {
            do {
                f32 a = *(f32*)(arg1);
                f32 b = *(f32*)(arg1 + 4);
                f32 c = *(f32*)(arg1 + 8);
                f32 d = *(f32*)(arg1 + 12);
                *(f32*)(arg2) = a;
                *(f32*)(arg2 + 4) = b;
                *(f32*)(arg2 + 8) = c;
                *(f32*)(arg2 + 12) = d;
                arg1 += 16;
                arg2 += 16;
                count--;
            } while (count != 0);
        } else {
            f32 a = *(f32*)(arg1);
            f32 b = *(f32*)(arg1 + 4);
            f32 c = *(f32*)(arg1 + 8);
            f32 d = *(f32*)(arg1 + 12);
            *(f32*)(arg2) = a;
            *(f32*)(arg2 + 4) = b;
            *(f32*)(arg2 + 8) = c;
            *(f32*)(arg2 + 12) = d;
        }
    }
}

f32 fn_8006D828(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r6;
    s32 var_ctr;

    temp_r6 = arg3 - 1;
    var_ctr = temp_r6;
    M2C_ERROR(/* unknown instruction: psq_lu $f6, 0x1($r5), 0x1, qr7 */);
    M2C_ERROR(/* unknown instruction: psq_lu $f9, 0x8($r12), 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lu $f10, 0x8($r12), 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lu $f11, 0x8($r12), 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lu $f12, 0x8($r12), 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lu $f13, 0x8($r12), 0x0, qr0 */);
    if (temp_r6 & temp_r6) {
        M2C_ERROR(/* unknown instruction: ps_muls0 $f8, $f8, $f6 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f9, $f9, $f6 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f10, $f10, $f6 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f11, $f11, $f6 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f12, $f12, $f6 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f13, $f13, $f6 */);
        do {
            M2C_ERROR(/* unknown instruction: psq_lu $f6, 0x1($r5), 0x1, qr7 */);
            M2C_ERROR(/* unknown instruction: psq_lu $f1, 0x8($r12), 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lu $f2, 0x8($r12), 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lu $f3, 0x8($r12), 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lu $f4, 0x8($r12), 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lu $f5, 0x8($r12), 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f8, $f0, $f6, $f8 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f9, $f1, $f6, $f9 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f10, $f2, $f6, $f10 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f11, $f3, $f6, $f11 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f12, $f4, $f6, $f12 */);
            M2C_ERROR(/* unknown instruction: ps_madds0 $f13, $f5, $f6, $f13 */);
            var_ctr -= 1;
        } while (var_ctr != 0);
    }
    M2C_ERROR(/* unknown instruction: ps_merge00 $f0, $f8, $f10 */);
    M2C_ERROR(/* unknown instruction: ps_merge11 $f2, $f8, $f10 */);
    M2C_ERROR(/* unknown instruction: ps_merge11 $f3, $f12, $f7 */);
    M2C_ERROR(/* unknown instruction: ps_merge00 $f4, $f9, $f11 */);
    M2C_ERROR(/* unknown instruction: ps_merge01 $f5, $f13, $f7 */);
    M2C_ERROR(/* unknown instruction: ps_merge11 $f6, $f9, $f11 */);
    M2C_ERROR(/* unknown instruction: ps_merge11 $f7, $f13, $f7 */);
    return M2C_ERROR(/* unknown instruction: ps_merge01 $f1, $f12, $f7 */);
}

void fn_8006D8E8(s32 arg0) {
    M2C_UNK FileCache_ReleaseSlot(s32 *);
    s32 sp8;

    sp8 = arg0;
    FileCache_ReleaseSlot(&sp8);
}

s32 fn_8006D910(s32 arg0, s32 arg1) {
    M2C_UNK fn_8006EDE8(s32 *, s32, s32);
    s32 sp8;

    sp8 = 0;
    fn_8006EDE8(&sp8, arg0, arg1);
    return sp8;
}

s32 fn_8006D948(s32 arg0) {
    s32 sp8;

    sp8 = 0;
    fn_8006EDE8(&sp8, arg0, 0);
    return sp8;
}

/* True if s contains _pat_ (or, if pat is null, if s is _..._). Used by GActor_FindNode. */
s32 Str_MatchUnderscoreTag(char *s, char *pat)
{
    char *match;
    u8 c;
    s8 ch;

    if (s == 0) {
        return 0;
    }
    if (pat != 0) {
        match = 0;
        for (;;) {
            c = *(u8 *)s;
            if (*s == 0) {
                return 0;
            }
            if (match != 0) {
                if (*s == *match) {
                    if (match[1] == 0) {
                        if (s[1] == 0x5f) {
                            return 1;
                        }
                    }
                    s++;
                    match++;
                } else {
                    match = 0;
                }
            } else {
                ch = *s;
                s++;
                if (ch == 0x5f) {
                    match = pat;
                }
            }
        }
    }
    c = *(u8 *)s;
    s++;
    if ((s8)c != 0x5f) {
        return 0;
    }
    while (*s != 0) {
        s++;
    }
    return (u8)(s[-1] == 0x5f);
}

void fn_8006DA5C(s32 *arg0, s32 arg1) {
    *arg0 = arg1;
}

int Game_Assert(void *arg0, int arg1, int arg2) {
    s32 fn_8005B010(void *, s32, void *, ...);
    extern u16 lbl_8026B980[8];
    fn_8005B010(arg0, arg1, lbl_8026B980, arg2);
    return 0;
}

#pragma use_lmw_stmw on
/* Set up GX fifos and VI render mode; reuse existing demo XFB pointers. */
void DEMOInitGX(void *rmode)
{
    void *fn_800C4638(s32, void *, s32);
    void fn_800C4588(void *);
    s32 fn_8021F4CC(void);
    s32 fn_8021F250(void);
    s32 fn_8021F258(s32);
    void fn_802206F4(void);
    void GXInitFifoBase(void *, void *, u32);
    void GXSetCPUFifo(void *);
    void GXSetGPFifo(void *);
    s32 VIGetTvFormat(void);
    void fn_8022C1B8(void *, void *, s32);
    void OSPanic(void *, s32, void *, ...);
    void GXAdjustForOverscan(void *, void *, s32, s32);
    void *GXInit(s32, s32);
    void GXSetViewport(f32, f32, f32, f32, f32, f32);
    void GXSetScissor(s32, s32, u16, u16);
    void fn_802214A8(u16, u16);
    s32 fn_802216E0(void);
    void fn_802211D0(s32, s32, u16, u16);
    void fn_802212C8(u16, u16);
    void fn_80221824(u8, void *, s32, void *);
    void fn_802246EC(s32, s32);
    void GXCopyDisp(void *, s32);
    void fn_80221A2C(s32);
    void VIConfigure(void *);
    void VISetNextFrameBuffer(void *);
    void VIFlush(void);
    void VIWaitForRetrace(void);
    extern char DEMOInit_str[];
    extern u8 DEMORmodeObj[];
    extern void *DEMORmode;
    extern void *DefaultFifoObj;
    extern void *DemoCurrentBuffer;
    extern void *DemoFrameBuffer2;
    extern void *DemoFrameBuffer1;
    extern u8 GXNtsc480IntDf[];
    extern u8 GXPal528IntDf[];
    extern u8 GXEurgb60Hz480IntDf[];
    extern u8 GXMpal480IntDf[];
    extern f32 lbl_803692C8;
    extern f32 lbl_803692CC;
    extern f64 lbl_803692D0;
    typedef struct { u32 x, y; } Pair;
    u8 fifo[0x80];
    void *buf;
    s32 a;
    s32 b;
    s32 c;
    u16 xfbHeight;
    u8 *dst;
    s32 fmt;

    buf = fn_800C4638(0x10000, DEMOInit_str, 0);
    a = fn_8021F4CC();
    b = fn_8021F250();
    c = fn_8021F258(a);
    fn_802206F4();
    GXInitFifoBase(fifo, buf, 0x10000);
    GXSetCPUFifo(fifo);
    GXSetGPFifo(fifo);
    if (rmode != NULL) {
        dst = DEMORmodeObj;
        *(u32 *)dst = *(u32 *)rmode;
        *(u16 *)(dst + 4) = *(u16 *)((u8 *)rmode + 4);
        *(u16 *)(dst + 6) = *(u16 *)((u8 *)rmode + 6);
        *(u16 *)(dst + 8) = *(u16 *)((u8 *)rmode + 8);
        *(u16 *)(dst + 0xa) = *(u16 *)((u8 *)rmode + 0xa);
        *(u16 *)(dst + 0xc) = *(u16 *)((u8 *)rmode + 0xc);
        *(u16 *)(dst + 0xe) = *(u16 *)((u8 *)rmode + 0xe);
        *(u16 *)(dst + 0x10) = *(u16 *)((u8 *)rmode + 0x10);
        *(u32 *)(dst + 0x14) = *(u32 *)((u8 *)rmode + 0x14);
        dst[0x18] = *((u8 *)rmode + 0x18);
        dst[0x19] = *((u8 *)rmode + 0x19);
        *(Pair *)(dst + 0x1a) = *(Pair *)((u8 *)rmode + 0x1a);
        *(Pair *)(dst + 0x22) = *(Pair *)((u8 *)rmode + 0x22);
        *(Pair *)(dst + 0x2a) = *(Pair *)((u8 *)rmode + 0x2a);
        fn_8022C1B8(dst + 0x32, (u8 *)rmode + 0x32, 7);
        DEMORmode = DEMORmodeObj;
    } else {
        switch (VIGetTvFormat()) {
        case 0:
            DEMORmode = GXNtsc480IntDf;
            break;
        case 1:
            DEMORmode = GXPal528IntDf;
            break;
        case 5:
            DEMORmode = GXEurgb60Hz480IntDf;
            break;
        case 2:
            DEMORmode = GXMpal480IntDf;
            break;
        default:
            OSPanic(DEMOInit_str + 1, 0xDF, DEMOInit_str + 0xC);
            break;
        }
        GXAdjustForOverscan(DEMORmode, DEMORmodeObj, 0, 0x10);
        DEMORmode = DEMORmodeObj;
    }
    DefaultFifoObj = GXInit(b, c);
    {
        void *rm = DEMORmode;
        u16 w = *(u16 *)((u8 *)rm + 4);
        u16 h = *(u16 *)((u8 *)rm + 6);
        GXSetViewport(lbl_803692C8, lbl_803692C8, (f32)w, (f32)h, lbl_803692C8, lbl_803692CC);
    }
    {
        void *rm = DEMORmode;
        GXSetScissor(0, 0, *(u16 *)((u8 *)rm + 4), *(u16 *)((u8 *)rm + 6));
    }
    {
        void *rm = DEMORmode;
        fn_802214A8(*(u16 *)((u8 *)rm + 6), *(u16 *)((u8 *)rm + 8));
    }
    xfbHeight = (u16)fn_802216E0();
    {
        void *rm = DEMORmode;
        fn_802211D0(0, 0, *(u16 *)((u8 *)rm + 4), *(u16 *)((u8 *)rm + 6));
    }
    fn_802212C8(*(u16 *)((u8 *)DEMORmode + 4), xfbHeight);
    {
        void *rm = DEMORmode;
        fn_80221824(*((u8 *)rm + 0x19), (u8 *)rm + 0x1a, 1, (u8 *)rm + 0x32);
    }
    if (*((u8 *)DEMORmode + 0x19) != 0) {
        fn_802246EC(2, 0);
    } else {
        fn_802246EC(1, 0);
    }
    GXCopyDisp(DemoCurrentBuffer, 1);
    fn_80221A2C(0);
    VIConfigure(DEMORmode);
    VISetNextFrameBuffer(DemoFrameBuffer1);
    DemoCurrentBuffer = DemoFrameBuffer2;
    VIFlush();
    VIWaitForRetrace();
    if (*(u32 *)DEMORmode & 1) {
        VIWaitForRetrace();
    }
    fn_800C4588(buf);
}

void fn_8006DDDC(void) {
    void fn_80225D6C(s32 *, s32 *, s32 *, s32 *);
    void fn_8021F168(void *, void *, u8 *, u8 *, void *, s32, s32);
    void OSReport(char *, ...);
    extern char DEMOInit_str[];
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    u8 spA;
    u8 sp9;
    u8 sp8;
    u8 eq28_18;
    u8 eq24_14;
    u32 ne20_10;
    u32 ne1C_C;
    s32 t0;
    s32 t1;

    fn_80225D6C(&sp24, &sp28, &sp1C, &sp20);
    fn_80225D6C(&sp14, &sp18, &spC, &sp10);

    t0 = sp20;
    t1 = sp10;
    t0 = t1 - t0;
    ne20_10 = ((u32)(t0 | -t0)) >> 31;
    t0 = sp28;
    t1 = sp18;
    eq28_18 = (t0 == t1);
    t0 = sp1C;
    t1 = spC;
    t0 = t1 - t0;
    ne1C_C = ((u32)(t0 | -t0)) >> 31;
    t0 = sp24;
    t1 = sp14;
    eq24_14 = (t0 == t1);

    fn_8021F168(&sp8, &sp8, &spA, &sp9, &sp8, sp14, sp24);
    OSReport(DEMOInit_str + 0x29, spA, sp9, eq28_18, eq24_14, ne20_10, ne1C_C);
    if (eq24_14 == 0 && ne20_10 != 0) {
        OSReport(DEMOInit_str + 0x45);
        return;
    }
    if (eq28_18 == 0 && eq24_14 != 0 && ne20_10 != 0) {
        OSReport(DEMOInit_str + 0x63);
        return;
    }
    if (sp9 == 0 && eq28_18 != 0 && eq24_14 != 0 && ne20_10 != 0) {
        OSReport(DEMOInit_str + 0x8B);
        return;
    }
    if (spA != 0 && sp9 != 0 && eq28_18 != 0 && eq24_14 != 0 && ne20_10 != 0 && ne1C_C != 0) {
        OSReport(DEMOInit_str + 0xB0);
        return;
    }
    OSReport(DEMOInit_str + 0xE0);
}

void fn_8006DFD8(void) {
    void *fn_800C4638(s32, void *, s32);
    void fn_800C4588(void *);
    s32 fn_8021F4CC(void);
    s32 fn_8021F250(void);
    s32 fn_8021F258(s32);
    void fn_802206F4(void);
    void GXInitFifoBase(void *, void *, u32);
    void GXSetCPUFifo(void *);
    void GXSetGPFifo(void *);
    s32 VIGetTvFormat(void);
    void fn_8022C1B8(void *, void *, s32);
    void OSPanic(void *, s32, void *, ...);
    void GXAdjustForOverscan(void *, void *, s32, s32);
    void *GXInit(s32, s32);
    void GXSetViewport(f32, f32, f32, f32, f32, f32);
    void GXSetScissor(s32, s32, u16, u16);
    void fn_802214A8(u16, u16);
    s32 fn_802216E0(void);
    void fn_802211D0(s32, s32, u16, u16);
    void fn_802212C8(u16, u16);
    void fn_80221824(u8, void *, s32, void *);
    void fn_802246EC(s32, s32);
    void GXCopyDisp(void *, s32);
    void fn_80221A2C(s32);
    void VIConfigure(void *);
    void VISetNextFrameBuffer(void *);
    void VIFlush(void);
    void VIWaitForRetrace(void);
    void GXSetZMode(s32, s32, s32);
    void fn_8022462C(s32);
    void fn_802208BC(s32);
    u16 fn_80220970(void);
    void fn_8006DDDC(void);
    void OSReport(char *, ...);
    void fn_8009E870(void);
    u32 fn_80211690(void);
    void fn_80211614(s32);
    void fn_80225204(s32, s32);
    extern char DEMOInit_str[];
    extern u8 DEMORmodeObj[];
    extern void *DEMORmode;
    extern void *DefaultFifoObj;
    extern void *DemoCurrentBuffer;
    extern void *DemoFrameBuffer2;
    extern void *DemoFrameBuffer1;
    extern u32 lbl_80367330;
    extern u32 gDemoStatHangLimit;
    extern u8 GXNtsc480IntDf[];
    extern u8 GXPal528IntDf[];
    extern u8 GXEurgb60Hz480IntDf[];
    extern u8 GXMpal480IntDf[];
    extern f32 lbl_803692C8;
    extern f32 lbl_803692CC;
    extern f64 lbl_803692D0;
    extern u32 gDvdCheckSnapshot;
    extern u32 gGameFlags;
    extern u8 lbl_80366DE0;
    typedef struct { u32 x, y; } Pair;
    u8 fifo[0x80];
    void *buf;
    s32 a;
    s32 b;
    s32 c;
    u16 xfbHeight;
    u8 *dst;
    void *src;
    s32 timed_out;
    volatile u8 *gx;

    timed_out = 0;
    GXSetZMode(1, 3, 1);
    fn_8022462C(1);
    GXCopyDisp(DemoCurrentBuffer, 1);
    fn_802208BC(0xB00B);
    lbl_80367330 = 0;
    goto check;
body:
    if (lbl_80367330 < gDemoStatHangLimit) {
        goto check;
    }
    OSReport(DEMOInit_str + 0xF9);
    timed_out = 1;
    fn_8006DDDC();
    src = DEMORmode;
    buf = fn_800C4638(0x10000, DEMOInit_str, 0);
    a = fn_8021F4CC();
    b = fn_8021F250();
    c = fn_8021F258(a);
    fn_802206F4();
    GXInitFifoBase(fifo, buf, 0x10000);
    GXSetCPUFifo(fifo);
    GXSetGPFifo(fifo);
    if (src != NULL) {
        dst = DEMORmodeObj;
        *(u32 *)dst = *(u32 *)src;
        *(u16 *)(dst + 4) = *(u16 *)((u8 *)src + 4);
        *(u16 *)(dst + 6) = *(u16 *)((u8 *)src + 6);
        *(u16 *)(dst + 8) = *(u16 *)((u8 *)src + 8);
        *(u16 *)(dst + 0xa) = *(u16 *)((u8 *)src + 0xa);
        *(u16 *)(dst + 0xc) = *(u16 *)((u8 *)src + 0xc);
        *(u16 *)(dst + 0xe) = *(u16 *)((u8 *)src + 0xe);
        *(u16 *)(dst + 0x10) = *(u16 *)((u8 *)src + 0x10);
        *(u32 *)(dst + 0x14) = *(u32 *)((u8 *)src + 0x14);
        dst[0x18] = *((u8 *)src + 0x18);
        dst[0x19] = *((u8 *)src + 0x19);
        *(Pair *)(dst + 0x1a) = *(Pair *)((u8 *)src + 0x1a);
        *(Pair *)(dst + 0x22) = *(Pair *)((u8 *)src + 0x22);
        *(Pair *)(dst + 0x2a) = *(Pair *)((u8 *)src + 0x2a);
        fn_8022C1B8(dst + 0x32, (u8 *)src + 0x32, 7);
        DEMORmode = DEMORmodeObj;
    } else {
        switch (VIGetTvFormat()) {
        case 0:
            DEMORmode = GXNtsc480IntDf;
            break;
        case 1:
            DEMORmode = GXPal528IntDf;
            break;
        case 5:
            DEMORmode = GXEurgb60Hz480IntDf;
            break;
        case 2:
            DEMORmode = GXMpal480IntDf;
            break;
        default:
            OSPanic(DEMOInit_str + 1, 0xDF, DEMOInit_str + 0xC);
            break;
        }
        GXAdjustForOverscan(DEMORmode, DEMORmodeObj, 0, 0x10);
        DEMORmode = DEMORmodeObj;
    }
    DefaultFifoObj = GXInit(b, c);
    {
        void *rm = DEMORmode;
        u16 w = *(u16 *)((u8 *)rm + 4);
        u16 h = *(u16 *)((u8 *)rm + 6);
        GXSetViewport(lbl_803692C8, lbl_803692C8, (f32)w, (f32)h, lbl_803692C8, lbl_803692CC);
    }
    {
        void *rm = DEMORmode;
        GXSetScissor(0, 0, *(u16 *)((u8 *)rm + 4), *(u16 *)((u8 *)rm + 6));
    }
    {
        void *rm = DEMORmode;
        fn_802214A8(*(u16 *)((u8 *)rm + 6), *(u16 *)((u8 *)rm + 8));
    }
    xfbHeight = (u16)fn_802216E0();
    {
        void *rm = DEMORmode;
        fn_802211D0(0, 0, *(u16 *)((u8 *)rm + 4), *(u16 *)((u8 *)rm + 6));
    }
    fn_802212C8(*(u16 *)((u8 *)DEMORmode + 4), xfbHeight);
    {
        void *rm = DEMORmode;
        fn_80221824(*((u8 *)rm + 0x19), (u8 *)rm + 0x1a, 1, (u8 *)rm + 0x32);
    }
    if (*((u8 *)DEMORmode + 0x19) != 0) {
        fn_802246EC(2, 0);
    } else {
        fn_802246EC(1, 0);
    }
    GXCopyDisp(DemoCurrentBuffer, 1);
    fn_80221A2C(0);
    VIConfigure(DEMORmode);
    VISetNextFrameBuffer(DemoFrameBuffer1);
    DemoCurrentBuffer = DemoFrameBuffer2;
    VIFlush();
    VIWaitForRetrace();
    if (*(u32 *)DEMORmode & 1) {
        VIWaitForRetrace();
    }
    fn_800C4588(buf);
    fn_80225204(0x23, 0x16);
    gx = (volatile u8 *)0xCC008000;
    *gx = 0x61;
    *(volatile u32 *)gx = 0x2402C004;
    *gx = 0x61;
    *(volatile u32 *)gx = 0x23000020;
    *gx = 0x10;
    *(volatile u16 *)gx = 0;
    *(volatile u16 *)gx = 0x1006;
    *(volatile u32 *)gx = 0x84400;
check:
    if (fn_80220970() == 0xB00B) {
        goto done;
    }
    if (timed_out == 0) {
        goto body;
    }
done:
    fn_8009E870();
    if (gDvdCheckSnapshot != fn_80211690() && !(gGameFlags & 8)) {
        gGameFlags |= 4;
    }
    VISetNextFrameBuffer(DemoCurrentBuffer);
    if (lbl_80366DE0 != 0) {
        fn_80211614(0);
        lbl_80366DE0 = 0;
    }
    VIFlush();
    if (gGameFlags & 1) {
        if (!(gGameFlags & 4)) {
            VIWaitForRetrace();
        }
        gGameFlags &= ~4;
    }
    VIWaitForRetrace();
    if (DemoCurrentBuffer == DemoFrameBuffer1) {
        DemoCurrentBuffer = DemoFrameBuffer2;
    }
}

#pragma use_lmw_stmw reset

void fn_8006E478(void) {
    void OSReport(char *, ...);
    void fn_8006DDDC(void);
    void OSPanic(char *, int, char *, ...);
    void fn_8021F168(u8 *, void *, void *, void *, void *);
    u32 fn_8021F4DC(void);
    extern char DEMOInit_str[];
    extern s32 lbl_80367330;
    extern u32 gDemoStatHangLimit, lbl_80367338, lbl_80367340;
    extern u8 lbl_8036733C, lbl_80367344;
    u8 sp9;
    u8 sp8;
    u32 result, count;
    if ((s8)lbl_8036733C == 0) { lbl_80367338=0; lbl_8036733C=1; }
    if ((s8)lbl_80367344 == 0) { lbl_80367340=0; lbl_80367344=1; }
    lbl_80367330++;
    fn_8021F168(&sp9,&sp8,&sp8,&sp8,&sp8);
    result=fn_8021F4DC();
    if(sp9 != 0 && result == lbl_80367340) {
        count=lbl_80367338+1; lbl_80367338=count;
        if(count>=gDemoStatHangLimit) {
            OSReport(DEMOInit_str+0x126); fn_8006DDDC();
            OSPanic(DEMOInit_str+1,0x326,DEMOInit_str+0x15b);
        }
    } else { lbl_80367340=result; lbl_80367338=0; }
}

extern s32 gDemoStatEnable;
extern u32 gDemoStatHangLimit;
extern s32 gDvdCheckSnapshot;
extern f32 lbl_803692C8;
extern f64 lbl_803692D0;
extern f32 lbl_803692CC;
/* Enable DEMO GP hang stats (non-zero limit) or disable them (0); program GX FIFO for the overlay. */
void DEMOSetStats(u32 hangLimit)
{
    void fn_8020FFC4(void (*)(void));
    void fn_80225204(s32, s32);
    void fn_8006E478(void);
    extern s32 gDemoStatEnable;
    extern u32 gDemoStatHangLimit;
    volatile u8 *gx;

    if (hangLimit != 0) {
        gDemoStatEnable = 1;
        gDemoStatHangLimit = hangLimit;
        fn_8020FFC4(fn_8006E478);
        fn_80225204(0x23, 0x16);
        gx = (volatile u8 *)0xCC008000;
        *gx = 0x61;
        *(volatile u32 *)gx = 0x2402C004;
        *gx = 0x61;
        *(volatile u32 *)gx = 0x23000020;
        *gx = 0x10;
        *(volatile u16 *)gx = 0;
        *(volatile u16 *)gx = 0x1006;
        *(volatile u32 *)gx = 0x84400;
    } else {
        gDemoStatEnable = 0;
        gDemoStatHangLimit = 0;
        gx = (volatile u8 *)0xCC008000;
        *gx = 0x61;
        *(volatile u32 *)gx = 0x24000000;
        *gx = 0x61;
        *(volatile u32 *)gx = 0x23000000;
        *gx = 0x10;
        *(volatile u16 *)gx = 0;
        *(volatile u16 *)gx = 0x1006;
        *(volatile u32 *)gx = 0;
        fn_8020FFC4(0);
    }
}

s32 DemoGetCurrentBuffer(void) {
    extern s32 DemoCurrentBuffer;
    return DemoCurrentBuffer;
}

s32 fn_8006E658(void) {
    extern s32 DEMORmode;
    return DEMORmode;
}

void fn_8006E660(void) {
extern s32 gDemoStatEnable;
extern void *DemoCurrentBuffer;
extern void *DemoFrameBuffer1;
extern void *DemoFrameBuffer2;
extern s32 gDvdCheckSnapshot;
extern u32 gGameFlags;
extern u8 lbl_80366DE0;
void fn_8006DFD8(void);
void GXSetZMode(s32,s32,s32);
void fn_8022462C(s32);
void GXCopyDisp(void *,s32);
void fn_8022097C(void);
void fn_8009E870(void);
u32 fn_80211690(void);
void VISetNextFrameBuffer(void *);
void fn_80211614(s32);
void VIFlush(void);
void VIWaitForRetrace(void);
void *next;
void *cur;
if(gDemoStatEnable) fn_8006DFD8();
else {
GXSetZMode(1,3,1); fn_8022462C(1); GXCopyDisp(DemoCurrentBuffer,1);
fn_8022097C(); fn_8009E870();
if((u32)gDvdCheckSnapshot != fn_80211690()) { if(!(gGameFlags&8)) gGameFlags|=4; }
VISetNextFrameBuffer(DemoCurrentBuffer);
if(lbl_80366DE0) { fn_80211614(0); lbl_80366DE0=0; }
VIFlush();
if(gGameFlags&1) { if(!(gGameFlags&4)) VIWaitForRetrace(); gGameFlags &= ~4; }
VIWaitForRetrace();
cur=DemoCurrentBuffer;
next=DemoFrameBuffer1;
if(cur==next) next=DemoFrameBuffer2;
DemoCurrentBuffer=next;
}
}

#pragma global_optimizer off
void DEMOBeforeRender(void)
{
    u32 fn_80211690(void);
    void fn_802208BC(s32);
    void fn_80225BF4(void);
    s32 fn_8021173C(void);
    void fn_80224F94(u32, f32, f32, f32, f32, f32, f32);
    void GXSetViewport(f32, f32, f32, f32, f32, f32);
    void fn_80220198(void);
    void fn_80222EB4(void);
    extern s32 gDemoStatEnable;
    extern s32 gDvdCheckSnapshot;
    extern void *DEMORmode;
    extern f32 lbl_803692C8;
    extern f32 lbl_803692CC;
    extern f64 lbl_803692D0;
    void *rmode;
    u16 w;
    u16 h;
    u32 field;

    /* Snapshot DVD check, optionally arm DEMO stats, set viewport, start GX frame. */
    gDvdCheckSnapshot = fn_80211690();
    if (gDemoStatEnable != 0) {
        fn_802208BC(0xFEEB);
        fn_80225BF4();
    }
    rmode = DEMORmode;
    if (*((u8 *)rmode + 0x18) != 0) {
        field = fn_8021173C();
        fn_80224F94(field, lbl_803692C8, lbl_803692C8, (f32)*(u16 *)((u8 *)rmode + 4), (f32)*(u16 *)((u8 *)rmode + 6), lbl_803692C8, lbl_803692CC);
    } else {
        GXSetViewport(lbl_803692C8, lbl_803692C8, (f32)*(u16 *)((u8 *)rmode + 4), (f32)*(u16 *)((u8 *)rmode + 6), lbl_803692C8, lbl_803692CC);
    }
    fn_80220198();
    fn_80222EB4();
}
#pragma global_optimizer on
void DEMOInit(void *arg0)
{
    /* Init OS/DVD/VI/PAD, pick render mode, allocate XFBs, and start GX. */
    void OSInit(void);
    void DVDInit(void);
    void VIInit(void);
    void PADInit(void);
    s32 VIGetTvFormat(void);
    void fn_8022C1B8(void *, void *, s32);
    void OSPanic(void *, s32, void *, ...);
    void GXAdjustForOverscan(void *, void *, s32, s32);
    void *OSGetArenaLo(void);
    void *OSGetArenaHi(void);
    void OSSetArenaLo(void *);
    void fn_800C5300(void);
    void Heap_Create(void *, s32);
    void VIConfigure(void *);
    void *fn_800C4638(s32, void *, s32);
    void *GXInit(void *, s32);
    void GXSetViewport(f32, f32, f32, f32, f32, f32);
    void GXSetScissor(s32, s32, u16, u16);
    void fn_802214A8(u16, u16);
    s32 fn_802216E0(void);
    void fn_802211D0(s32, s32, u16, u16);
    void fn_802212C8(u16, u16);
    void fn_80221824(u8, void *, s32, void *);
    void fn_802246EC(s32, s32);
    void GXCopyDisp(void *, s32);
    void fn_80221A2C(s32);
    void VISetNextFrameBuffer(void *);
    void VIFlush(void);
    void VIWaitForRetrace(void);
    extern char DEMOInit_str[];
    extern u8 DEMORmodeObj[];
    extern void *DEMORmode;
    extern void *DefaultFifoObj;
    extern void *DefaultFifo;
    extern void *DemoCurrentBuffer;
    extern void *DemoFrameBuffer2;
    extern void *DemoFrameBuffer1;
    extern s32 DemoFrameBufferSize;
    extern u8 GXNtsc480IntDf[];
    extern u8 GXPal528IntDf[];
    extern u8 GXEurgb60Hz480IntDf[];
    extern u8 GXMpal480IntDf[];
    extern f32 lbl_803692C8;
    extern f32 lbl_803692CC;
    extern f64 lbl_803692D0;
    typedef struct { u32 x, y; } Pair;
    void *arenaLo;
    s32 fbSize;
    u16 xfbHeight;
    u8 *dst;
    void *buf;
    void *rm;
    u32 w;

    OSInit();
    DVDInit();
    VIInit();
    PADInit();
    if (arg0 != NULL) {
        dst = DEMORmodeObj;
        *(u32 *)dst = *(u32 *)arg0;
        *(u16 *)(dst + 4) = *(u16 *)((u8 *)arg0 + 4);
        *(u16 *)(dst + 6) = *(u16 *)((u8 *)arg0 + 6);
        *(u16 *)(dst + 8) = *(u16 *)((u8 *)arg0 + 8);
        *(u16 *)(dst + 0xa) = *(u16 *)((u8 *)arg0 + 0xa);
        *(u16 *)(dst + 0xc) = *(u16 *)((u8 *)arg0 + 0xc);
        *(u16 *)(dst + 0xe) = *(u16 *)((u8 *)arg0 + 0xe);
        *(u16 *)(dst + 0x10) = *(u16 *)((u8 *)arg0 + 0x10);
        *(u32 *)(dst + 0x14) = *(u32 *)((u8 *)arg0 + 0x14);
        dst[0x18] = *((u8 *)arg0 + 0x18);
        dst[0x19] = *((u8 *)arg0 + 0x19);
        *(Pair *)(dst + 0x1a) = *(Pair *)((u8 *)arg0 + 0x1a);
        *(Pair *)(dst + 0x22) = *(Pair *)((u8 *)arg0 + 0x22);
        *(Pair *)(dst + 0x2a) = *(Pair *)((u8 *)arg0 + 0x2a);
        fn_8022C1B8(dst + 0x32, (u8 *)arg0 + 0x32, 7);
        DEMORmode = DEMORmodeObj;
    } else {
        switch (VIGetTvFormat()) {
        case 0:
            DEMORmode = GXNtsc480IntDf;
            break;
        case 1:
            DEMORmode = GXPal528IntDf;
            break;
        case 5:
            DEMORmode = GXEurgb60Hz480IntDf;
            break;
        case 2:
            DEMORmode = GXMpal480IntDf;
            break;
        default:
            OSPanic(DEMOInit_str + 1, 0xDF, DEMOInit_str + 0xC);
            break;
        }
        GXAdjustForOverscan(DEMORmode, DEMORmodeObj, 0, 0x10);
        DEMORmode = DEMORmodeObj;
    }
    arenaLo = OSGetArenaLo();
    OSGetArenaHi();
    rm = DEMORmode;
    w = (*(u16 *)((u8 *)rm + 4) + 0xF) & 0xFFF0;
    fbSize = w * *(u16 *)((u8 *)rm + 8) * 2;
    DemoFrameBuffer1 = (void *)(((u32)arenaLo + 0x1F) & ~0x1Fu);
    DemoFrameBufferSize = fbSize;
    DemoFrameBuffer2 = (void *)(((u32)DemoFrameBuffer1 + (fbSize + 0x1F)) & ~0x1Fu);
    DemoCurrentBuffer = DemoFrameBuffer2;
    OSSetArenaLo((void *)(((u32)DemoFrameBuffer2 + (fbSize + 0x1F)) & ~0x1Fu));
    fn_800C5300();
    Heap_Create(DEMOInit_str + 0x16b, 0x533333);
    VIConfigure(DEMORmode);
    buf = fn_800C4638(0x80000, DEMOInit_str + 0x170, 0x80000);
    DefaultFifo = buf;
    DefaultFifoObj = GXInit(buf, 0x80000);
    {
        void *rm2 = DEMORmode;
        u16 w2 = *(u16 *)((u8 *)rm2 + 4);
        u16 h2 = *(u16 *)((u8 *)rm2 + 6);
        GXSetViewport(lbl_803692C8, lbl_803692C8, (f32)w2, (f32)h2, lbl_803692C8, lbl_803692CC);
    }
    {
        void *rm2 = DEMORmode;
        GXSetScissor(0, 0, *(u16 *)((u8 *)rm2 + 4), *(u16 *)((u8 *)rm2 + 6));
    }
    {
        void *rm2 = DEMORmode;
        fn_802214A8(*(u16 *)((u8 *)rm2 + 6), *(u16 *)((u8 *)rm2 + 8));
    }
    xfbHeight = (u16)fn_802216E0();
    {
        void *rm2 = DEMORmode;
        fn_802211D0(0, 0, *(u16 *)((u8 *)rm2 + 4), *(u16 *)((u8 *)rm2 + 6));
    }
    fn_802212C8(*(u16 *)((u8 *)DEMORmode + 4), xfbHeight);
    {
        void *rm2 = DEMORmode;
        fn_80221824(*((u8 *)rm2 + 0x19), (u8 *)rm2 + 0x1a, 1, (u8 *)rm2 + 0x32);
    }
    if (*((u8 *)DEMORmode + 0x19) != 0) {
        fn_802246EC(2, 0);
    } else {
        fn_802246EC(1, 0);
    }
    GXCopyDisp(DemoCurrentBuffer, 1);
    fn_80221A2C(0);
    VISetNextFrameBuffer(DemoFrameBuffer1);
    DemoCurrentBuffer = DemoFrameBuffer2;
    VIFlush();
    VIWaitForRetrace();
    if (*(u32 *)DEMORmode & 1) {
        VIWaitForRetrace();
    }
}

s32 fn_8006EB9C(void) {
    extern s32 DefaultFifoObj;
    return DefaultFifoObj;
}

s32 fn_8006EBA4(void *arg0, s32 arg1) {
    u8 *base = M2C_FIELD(arg0, u8 **, 0x8);
    return *(s32 *)(base + (arg1 << 3) + 4) != 0;
}

void fn_8006EBC4(void *arg0, void *arg1, void *arg2, u32 arg3, s32 arg4) {
    void fn_80222CA4(u32 *, u32, u32, u16);
    void GXInitTexObjCI(void *, void *, u16, u16, s32, s32, s32, u8, u32);
    void GXInitTexObjLOD(void *, s32, s32, f32, f32, f32, u8, u8, s32);

    u8 *table;
    u8 *entry;
    u8 *texture;
    u8 *palette;
    s32 mipmap;

    table = *(u8 **)((u8 *)arg0 + 8);
    entry = table + (arg4 << 3);

    texture = *(u8 **)entry;
    palette = *(u8 **)(entry + 4);

    if (texture[0x21] == texture[0x22]) {
        mipmap = 0;
    } else {
        mipmap = 1;
    }

    fn_80222CA4(
        (u32 *)arg2,
        *(u32 *)(palette + 8),
        *(u32 *)(palette + 4),
        *(u16 *)palette
    );

    GXInitTexObjCI(
        arg1,
        *(void **)(texture + 8),
        *(u16 *)(texture + 2),
        *(u16 *)texture,
        *(s32 *)(texture + 4),
        *(s32 *)(texture + 0xC),
        *(s32 *)(texture + 0x10),
        (u8)mipmap,
        arg3
    );

    GXInitTexObjLOD(
        (u32 *)arg1,
        *(s32 *)(texture + 0x14),
        *(s32 *)(texture + 0x18),
        (f32)texture[0x21],
        (f32)texture[0x22],
        *(f32 *)(texture + 0x1C),
        0,
        texture[0x20],
        0
    );
}

#pragma global_optimizer off
void Ui_LoadAtlasTex(void *arg0, void *tex, s32 idx)
{
    void fn_80222644(void *, void *, u16, u16, s32, s32, s32, s32);
    void GXInitTexObjLOD(void *, s32, s32, f32, f32, f32, u8, u8, s32);
    s32 off;
    u8 *table;
    u8 *node;
    s32 flag;

    off = idx << 3;
    table = *(u8 **)((u8 *)arg0 + 8);
    node = *(u8 **)(table + off);
    if (node[0x21] == node[0x22]) {
        flag = 0;
    } else {
        flag = 1;
    }
    fn_80222644(tex, *(void **)(node + 8), *(u16 *)(node + 2), *(u16 *)(node + 0), *(s32 *)(node + 4), *(s32 *)(node + 0xC), *(s32 *)(node + 0x10), flag);
    {
    u8 *lod = *(u8 **)(table + off);
    GXInitTexObjLOD(tex, *(s32 *)(lod + 0x14), *(s32 *)(lod + 0x18), (f32)lod[0x21], (f32)lod[0x22], *(f32 *)(lod + 0x1C), 0, lod[0x20], 0);
    }
}
#pragma global_optimizer reset
extern void FileCache_ReleaseByKey(u32);
void FileCache_ReleaseSlot(s32 *arg0)
{
    void fn_8005C7E8();
    fn_8005C7E8(*arg0);
    *arg0 = 0;
}

s32 fn_8006EDD8(void *arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 8) + (arg1 * 8);
}

int fn_8006EDE8(void *arg0, void *arg1, int arg2) {
    u8 *file;
    u8 *table;
    u8 *record;
    u32 offset;
    u32 value;
    u32 i;

    file = (u8 *)fn_8005C82C(arg1, arg2);
    *(u8 **)arg0 = file;

    if (*(u32 *)file == 0x0020AF31U) {
        return;
    }

    *(u32 *)file += 1;
    *(u32 *)(file + 8) += (u32)file;

    i = 0;

    while ((i & 0xFFFF) < *(u32 *)(file + 4)) {
        table = *(u8 **)(file + 8);
        offset = (i & 0xFFFF) << 3;

        value = *(u32 *)(table + offset);

        if (value != 0) {
            *(u32 *)(table + offset) = value + (u32)file;

            table = *(u8 **)(file + 8);
            record = *(u8 **)(table + offset);

            if (record[0x23] == 0) {
                *(u32 *)(record + 8) += (u32)file;

                table = *(u8 **)(file + 8);
                record = *(u8 **)(table + offset);
                record[0x23] = 1;
            }
        }

        table = *(u8 **)(file + 8);
        offset += 4;
        value = *(u32 *)(table + offset);

        if (value != 0) {
            *(u32 *)(table + offset) = value + (u32)file;

            table = *(u8 **)(file + 8);
            record = *(u8 **)(table + offset);

            if (record[2] == 0) {
                *(u32 *)(record + 8) += (u32)file;

                table = *(u8 **)(file + 8);
                record = *(u8 **)(table + offset);
                record[2] = 1;
            }
        }

        i++;
    }
}

void fn_8006EEFC(void *arg0, void *arg1) {
    u8 *file;
    u8 *table;
    u8 *record;
    u32 offset;
    u32 value;
    u32 i;
    u32 count;

    file = ((u8 *(*)(s32))FileCache_Load)((s32)arg1);
    *(u8 **)arg0 = file;

    if (*(u32 *)file == 0x0020AF31U) {
        return;
    }

    *(u32 *)file += 1;
    *(u32 *)(file + 8) += (u32)file;

    i = 0;

    while (i < *(u32 *)(file + 4)) {
        table = *(u8 **)(file + 8);
        offset = (i & 0xFFFF) << 3;

        value = *(u32 *)(table + offset);

        if (value != 0) {
            *(u32 *)(table + offset) = value + (u32)file;

            table = *(u8 **)(file + 8);
            record = *(u8 **)(table + offset);

            if (record[0x23] == 0) {
                *(u32 *)(record + 8) += (u32)file;

                table = *(u8 **)(file + 8);
                record = *(u8 **)(table + offset);
                record[0x23] = 1;
            }
        }

        table = *(u8 **)(file + 8);
        offset += 4;
        value = *(u32 *)(table + offset);

        if (value != 0) {
            *(u32 *)(table + offset) = value + (u32)file;

            table = *(u8 **)(file + 8);
            record = *(u8 **)(table + offset);

            if (record[2] == 0) {
                *(u32 *)(record + 8) += (u32)file;

                table = *(u8 **)(file + 8);
                record = *(u8 **)(table + offset);
                record[2] = 1;
            }
        }

        i++;
    }
}

void fn_8006F00C(s8 arg0) {
    extern u8 lbl_80366DE9;
    lbl_80366DE9 = (u8)arg0;
}

s32 fn_8006F014(void) {
    extern s8 lbl_80366DE8;
    return lbl_80366DE8;
}

#pragma global_optimizer off
#pragma opt_strength_reduction off
void fn_8006F020(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *fn_800C0658(void);
    void Ui_CreateMenu(void *, void *, s32);
    extern u8 lbl_80311CA8[];
    struct MenuDef {
        u8 pad[0x4c];
        s32 args[8];
        void *table[5];
    };
    struct MenuDef *d = (struct MenuDef *)lbl_80311CA8;
    volatile void **tbl = (volatile void **)d->table;

    tbl[0] = d->args;
    d->args[1] = (s32)arg0;
    tbl[1] = &d->args[2];
    d->args[3] = (s32)arg1;
    tbl[2] = &d->args[4];
    d->args[5] = (s32)arg2;
    tbl[3] = &d->args[6];
    d->args[7] = (s32)arg3;
    tbl[4] = 0;
    Ui_CreateMenu((u8 *)d + 0x94, fn_800C0658(), 0);
}
#pragma opt_strength_reduction on
#pragma global_optimizer on
void fn_8006F09C(void *arg0, void *arg1, void *arg2) {
    void *fn_800C0658(void);
    void Ui_CreateMenu(void *, void *, s32);
    extern u8 lbl_80311CA8[];
    struct MenuDef {
        u8 pad[0x4c];
        s32 table[8];
        void *entries[4];
    };
    struct Entries { void *e[4]; };
    struct MenuDef *d = (struct MenuDef *)lbl_80311CA8;
    struct Entries *e = (struct Entries *)((u8 *)d + 0x6c);

    e->e[0] = (void *)d->table;
    d->table[1] = (s32)arg0;
    e->e[1] = (void *)(d->table + 2);
    d->table[3] = (s32)arg1;
    e->e[2] = (void *)(d->table + 4);
    d->table[5] = (s32)arg2;
    e->e[3] = 0;
    Ui_CreateMenu((u8 *)d + 0x80, fn_800C0658(), 0);
}
#pragma global_optimizer off
void fn_8006F10C(s32 arg0, s32 arg1) {
    extern u8 lbl_80311CA8[];
    s32 fn_800C0658(void);
    void Ui_CreateMenu(void *, s32, s32);
    u8 *base = lbl_80311CA8;
    volatile s32 *table = (volatile s32 *)(base + 0x4c);
    volatile void **entries = (volatile void **)(base + 0x6c);

    entries[0] = (void *)table;
    table[1] = arg0;
    table += 2;
    entries[1] = (void *)table;
    table[1] = arg1;
    entries[2] = 0;
    Ui_CreateMenu(base + 0x80, fn_800C0658(), 0);
}

void fn_8006F170(void *arg0, void *arg1, void *arg2) {
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32,f32);
    void Prim2D_SetColor(s32,s32,s32,s32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    s32 Text_MeasureHeight(s32,f32);
    extern f32 lbl_803692E0;
#pragma cplusplus on
    struct Model {
        u8 pad[4];
        virtual void v0()=0;
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
        virtual s32 height()=0;
    };
    struct Item {
        virtual void v0()=0;
        virtual void *text()=0;
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
        virtual void setup(void *)=0;
    };
    f32 x;
    f32 y;
    s32 height;
    Model *model;
    model=M2C_FIELD(arg1,Model **,0x3C);
    x=(f32)M2C_FIELD(arg2,s16 *,0x30);
    height=(s16)model->height();
    y=(f32)(M2C_FIELD(arg2,s16 *,0x32)+((height-Text_MeasureHeight(-1,lbl_803692E0))>>1));
    ((Item *)arg0)->setup(arg1);
    Prim2D_AddPrim(6);
    Prim2D_SetPos(x,y);
    Prim2D_SetColor(0,0,0,255);
    Prim2D_SetText(((Item *)arg0)->text());
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_803692E0);
    Prim2D_PrepareTex();
#pragma cplusplus reset
}

#pragma global_optimizer reset
s32 fn_8006F2B8(s32 arg0, s32 arg1) {
    M2C_UNK fn_80121630(s32);
    fn_80121630(arg1);
    return 0;
}

s32 fn_8006F2E0(void *arg0, void *arg1, void *arg2) {
    extern u8 lbl_80366DE8;
    lbl_80366DE8 = *(u8 *)((u8 *)arg2 + 0x3A);
    return 5;
}

#pragma cplusplus on
extern "C" void fn_8006F2F0(void *arg0) {
    void fn_8008B09C(s32, s32, s16, s16);
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
        virtual s32 v18() = 0;
        virtual s32 v19() = 0;
        virtual void v20() = 0;
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual void v25() = 0;
        virtual void v26() = 0;
        virtual void v27() = 0;
        virtual void v28() = 0;
        virtual void v29() = 0;
    };
    s16 t;
    ((Obj *)arg0)->v29();
    t = (s16)((Obj *)arg0)->v19();
    fn_8008B09C(0, 0, (s16)((Obj *)arg0)->v18(), t);
}
#pragma cplusplus reset

s32 fn_8006F370(void) {
    return 0;
}

void fn_8006F378(void) {
    M2C_UNK fn_80024DE4();
    fn_80024DE4();
}

void fn_8006F398(void *arg0, void *arg1) {
void *GfxEnt_Get(s32);
s32 Text_MeasureHeight(s32,f32);
void Prim2D_Begin(void);
void Prim2D_AddZ(f32);
void Prim2D_PrepareTex(void);
void Ui_DrawRouteIconEx(s32,s32,s32);
void fn_8008AB7C(s32,s32,s32,s32,s32,s32,s32);
extern f32 lbl_803692E0,lbl_803692F0,lbl_803692F4;
#pragma cplusplus on
struct Obj {u8 pad[4]; virtual void v0()=0;
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
virtual s16 v20()=0; };
u8 *self=(u8*)arg0;
u8 *obj=(u8*)arg1;
u8 *row;
void *ent;
register s32 sy;
register s32 sx;
s32 height,pulse;
s32 iconX,iconY;
row=obj;
row+=*(s8*)(row+0x62);
ent=GfxEnt_Get(row[0x40]);
sx=(s16)(*(s16*)((u8*)ent+0x30)-0x10);
row=obj;
row+=*(s8*)(row+0x62);
ent=GfxEnt_Get(row[0x40]);
sy=*(s16*)((u8*)ent+0x32);
height=(s16)((Obj*)arg0)->v20();
sy=(s16)(sy+((height-Text_MeasureHeight(-1,lbl_803692E0))>>1));
if(*(s16*)(obj+0x3A)<0) {
*(s16*)(obj+0x38)=sx; *(s16*)(obj+0x3A)=sy;
} else {
*(s16*)(obj+0x38)=(*(s16*)(obj+0x38)+sx)/2;
*(s16*)(obj+0x3A)=(*(s16*)(obj+0x3A)+sy)/2;
}
Prim2D_Begin();Prim2D_AddZ(lbl_803692F0);Prim2D_PrepareTex();
iconX=*(s16*)(obj+0x38);
iconY=*(s16*)(obj+0x3A);
pulse=0;
if(!obj[0x2D]&&!obj[0x2E]) pulse=1;
Ui_DrawRouteIconEx(iconX,iconY,pulse);
sy=(s16)(*(s16*)(self+0xC)+0x40);
sx=(s16)Text_MeasureHeight(-1,lbl_803692E0);
Prim2D_Begin();Prim2D_AddZ(lbl_803692F4);Prim2D_PrepareTex();
fn_8008AB7C(*(s16*)(obj+0x38)+(sy>>1)-0x10,*(s16*)(obj+0x3A)+(sx>>1),sy,0x18,0x19,0x4B,1);
#pragma cplusplus reset
}

#pragma cplusplus on
extern "C" void fn_8006F514(void *arg0) {
    void Ui_DrawMsgPanelBg(s32, s32);
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
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual void v25() = 0;
        virtual void v26() = 0;
        virtual void v27() = 0;
        virtual void v28() = 0;
        virtual void v29() = 0;
    };
    ((Obj *)arg0)->v29();
    Ui_DrawMsgPanelBg(0, 0);
}

extern "C" void fn_8006F54C(void *arg0, void *arg1) {
#pragma cplusplus off
void *GfxEnt_Get(u8);
s32 Text_MeasureWidth(void *,s32,f32);
#pragma cplusplus reset
struct Obj {u8 pad[4]; virtual void v0()=0;
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
virtual s16 v18()=0;
virtual s16 v19()=0;
virtual s16 v20()=0; };
struct TextObj {virtual void v0()=0; virtual void *v1()=0;};
u8 *self=(u8*)arg0;
u8 *group=(u8*)arg1;
s32 i;
s32 x;
s32 y;
s16 height;
u8 count;
*(s16*)(self+0xC)=0;
count=group[0x60];
height=((Obj*)arg0)->v20()*(s8)count;
for(i=0;i<(s8)group[0x60];i++) {
TextObj *obj=*(TextObj**)((u8*)GfxEnt_Get(group[i+0x40])+0x34);
s16 width=Text_MeasureWidth(obj->v1(),-1,1.0f);
if(width>=*(s16*)(self+0xC)) *(s16*)(self+0xC)=width;
}
*(s16*)(self+0xE)=(((Obj*)arg0)->v18()-*(s16*)(self+0xC))>>1;
*(s16*)(self+0x10)=(((Obj*)arg0)->v19()-height)>>1;
x=*(s16*)(self+0xE);
y=*(s16*)(self+0x10);
for(i=0;i<(s8)group[0x60];) {
*(s16*)((u8*)GfxEnt_Get(group[i+0x40])+0x30)=x;
*(u16*)((u8*)GfxEnt_Get(group[i+0x40])+0x32)=y;
i++;
y+=((Obj*)arg0)->v20();
}
}

#pragma cplusplus reset
void fn_8006F6A4(s32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    extern u32 lbl_80311CE0[];
    extern s8 lbl_80366DE8;
    extern u32 lbl_80367350[2];
    extern u32 lbl_80367358[2];

    lbl_80366DE8 = -1;
    if (arg1 != 0U) {
        lbl_80311CE0[3] = arg1;
    }
    if (arg2 != 0U) {
        lbl_80367350[1] = arg2;
    }
    if (arg3 != 0U) {
        lbl_80367358[1] = arg3;
    }
    Ui_CreateMenu(lbl_80311CE0, arg0, 0);
}

#pragma cplusplus on
/* Begin Prim2D for a UiWin: transform, fade-tinted color, and lock/pause alpha. */
extern "C"
void UiWin_SetupPrim2D(void *unused, void *win) {
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    f32 UiWin_GetFade(void *);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetAlphaByte(u8);
    struct Model {
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
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual f32 v25() = 0;
    };
    extern f32 lbl_803692E0;
    extern f32 lbl_803692F8;
    s32 idle;
    s32 alpha;

    Prim2D_Begin();
    Prim2D_SetTransform((f32)M2C_FIELD(win, s16 *, 0x30), (f32)M2C_FIELD(win, s16 *, 0x32),
                M2C_FIELD(win, Model **, 0x3C)->v25(), lbl_803692E0);
    Prim2D_SetColorByte((s32)(lbl_803692F8 * UiWin_GetFade(win)));
    idle = 0;
    if ((u8)M2C_FIELD(win, u8 *, 0x2D) == 0 && (u8)M2C_FIELD(win, u8 *, 0x2E) == 0) {
        idle = 1;
    }
    alpha = 0x58;
    if ((u8)idle != 0) {
        alpha = 0x80;
    }
    Prim2D_SetAlphaByte((u8)alpha);
    Prim2D_PrepareTex();
}
#pragma cplusplus reset

void fn_8006F7F0(void *arg0)
{
    void Ui_DrawMsgPanelAlt(s32, s32);
    void *Heap_AllocRaw(u32);
    void Heap_FreeRaw(void *);
    u32 strlen(const char *);
    char *strcpy(char *, const char *);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    s32 Text_MeasureHeight(s32, f32);

    extern f64 lbl_803692E8;
    extern f32 lbl_803692E0;
    extern f32 lbl_803692FC;
    extern f32 lbl_80369300;

    u8 *self;
    char *buffer;
    char *line;
    char *cursor;
    char *text;
    void **vtable;
    s32 length;
    s32 lineIndex;
    s32 height;
    f32 x;
    f32 y;

    self = (u8 *)arg0;

    vtable = *(void ***)(self + 4);
    ((void (*)(void *))vtable[31])(self);

    Ui_DrawMsgPanelAlt(0, 0);

    vtable = *(void ***)(self + 4);
    text = ((char *(*)(void *))vtable[2])(self);

    length = strlen(text);
    buffer = Heap_AllocRaw(length + 1);

    vtable = *(void ***)(self + 4);
    text = ((char *(*)(void *))vtable[2])(self);

    strcpy(buffer, text);

    x = (f32)*(s16 *)(self + 0x10);
    y = lbl_803692FC;
    lineIndex = 0;

    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369300);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();

    line = buffer;
    cursor = buffer;

    while (*cursor != 0) {
        if ((s8)*cursor == '\n') {
            *cursor = 0;

            Prim2D_AddPrim(6);
            Prim2D_SetPos(x, y);
            Prim2D_SetColor(0, 0, 0, 255);
            Prim2D_SetText(line);
            Prim2D_EndPrim();

            lineIndex++;

            x = (f32)*(s16 *)(self + 0x10 + (s16)lineIndex * 2);

            height = Text_MeasureHeight(-1, lbl_803692E0);
            y += (f32)(height + 2);

            line = cursor + 1;
        }

        cursor++;
    }

    Prim2D_AddPrim(6);
    Prim2D_SetPos(x, y);
    Prim2D_SetColor(0, 0, 0, 255);
    Prim2D_SetText(line);
    Prim2D_EndPrim();

    Heap_FreeRaw(buffer);

    Prim2D_Begin();
    Prim2D_AddZ(lbl_803692E0);
    Prim2D_PrepareTex();
}

void fn_8006F9F4(void *arg0, void *arg1) {
    void *GfxEnt_Get(u8);
    s32 Text_MeasureWidth(void *, s32, f32);
    s32 fn_80010428(u8 **, s32, f32);
    extern f32 lbl_803692E0;
#pragma cplusplus on
    struct Obj {
        u8 pad[4];
        virtual void *v0() = 0;
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
        virtual s16 v17() = 0;
        virtual s16 v18() = 0;
    };
    struct TextObj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void *v4(void *) = 0;
    };
    u8 *group;
    u8 *self;
    s16 y;
    s8 c;
    s32 j;
    s32 t26;
    s32 i;
    s16 lineW;
    s16 step;
    s16 lineIdx;
    u8 *text;
    s16 w;

    i = 0;
    self = (u8 *)arg0;
    group = (u8 *)arg1;
    *(s16 *)((u8 *)arg0 + 8) = i;
    goto check1;
loop1:
    t26 = (s32)GfxEnt_Get(group[i + 0x40]);
    w = (s16)Text_MeasureWidth(
        (*(TextObj **)((u8 *)GfxEnt_Get(group[i + 0x40]) + 0x34))->v4((void *)t26),
        -1, lbl_803692E0);
    if (w >= *(s16 *)(self + 8)) {
        *(s16 *)(self + 8) = w;
    }
    i += 1;
check1:
    t26 = group[0x60];
    if (i < (s8)t26) {
        goto loop1;
    }
    w = ((Obj *)arg0)->v18();
    c = (s8)t26;
    step = (s16)((s32)w / ((s32)c + 1));
    t26 = step;
    y = ((Obj *)arg0)->v17();
    j = 0;
    goto check2;
loop2:
    *(s16 *)((u8 *)GfxEnt_Get(group[j + 0x40]) + 0x30) = t26;
    *(s16 *)((u8 *)GfxEnt_Get(group[j + 0x40]) + 0x32) = y;
    t26 = t26 + step;
    j += 1;
check2:
    if (j < c) {
        goto loop2;
    }
    lineW = 0;
    lineIdx = 0;
    text = (u8 *)((Obj *)arg0)->v0();
    goto check3;
loop3:
    switch ((s8)*text) {
    case 10: {
        s16 v = ((Obj *)arg0)->v18();
        s16 centered = (s16)(((s32)v - (s32)lineW) >> 1);
        lineW = 0;
        *(s16 *)(self + ((s32)lineIdx << 1) + 0x10) = centered;
        lineIdx = (s16)(lineIdx + 1);
        text += 1;
        break;
    }
    default:
        lineW = (s16)(lineW + fn_80010428(&text, -1, lbl_803692E0));
        break;
    }
check3:
    if ((s8)*text != 0) {
        goto loop3;
    }
    {
        s16 v = ((Obj *)arg0)->v18();
        *(s16 *)(self + ((s32)lineIdx << 1) + 0x10) =
            (s16)(((s32)v - (s32)lineW) >> 1);
    }
#pragma cplusplus reset
}

void MsgWin_OpenMulti(s32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    extern u32 lbl_80311CB8[];
    extern s8 lbl_80366DE8;
    extern u32 lbl_80367350[2];
    extern u32 lbl_80367358[2];

    lbl_80366DE8 = -1;
    if (arg1 != 0U) {
        lbl_80311CB8[3] = arg1;
    }
    if (arg2 != 0U) {
        lbl_80367350[1] = arg2;
    }
    if (arg3 != 0U) {
        lbl_80367358[1] = arg3;
    }
    Ui_CreateMenu(lbl_80311CB8, arg0, 0);
}

void fn_8006FC50(void *arg0) {
    void Ui_DrawMsgPanelBg(s32, s32);
    void *Heap_AllocRaw(s32);
    void Heap_FreeRaw(void *);
    void strcpy(char *, char *);
    s32 strlen(char *);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    s32 Text_MeasureHeight(s32, f32);
    extern f32 lbl_803692E0;
    extern f64 lbl_803692E8;
    extern f32 lbl_803692FC;
    extern f32 lbl_80369300;
#pragma cplusplus on
    struct Obj {
        u8 pad[4];
        virtual char *v0() = 0;
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
        virtual s32 v16() = 0;
        virtual void v17() = 0;
        virtual void v18() = 0;
        virtual void v19() = 0;
        virtual void v20() = 0;
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual void v25() = 0;
        virtual void v26() = 0;
        virtual void v27() = 0;
        virtual void v28() = 0;
        virtual void v29() = 0;
    };
    char *buf = 0;
    char *line = 0;
    Obj *self;
    char *p;
    f32 posX;
    f32 posY;
    char c;

    self = (Obj *)arg0;
    self->v29();
    Ui_DrawMsgPanelBg(0, 0);
    buf = (char *)Heap_AllocRaw(strlen(self->v0()) + 1);
    line = buf;
    strcpy(buf, self->v0());
    posX = (f32)(s16)self->v16();
    posY = lbl_803692FC;
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369300);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    for (p = buf; (c = *p) != 0; p++) {
        if ((s8)c == 0xA) {
            *p = 0;
            Prim2D_AddPrim(6);
            Prim2D_SetPos(posX, posY);
            Prim2D_SetColor(0, 0, 0, 0xFF);
            Prim2D_SetText(line);
            Prim2D_EndPrim();
            posY += (f32)(Text_MeasureHeight(-1, lbl_803692E0) + 2);
            line = p + 1;
        }
    }
    Prim2D_AddPrim(6);
    Prim2D_SetPos(posX, posY);
    Prim2D_SetColor(0, 0, 0, 0xFF);
    Prim2D_SetText(line);
    Prim2D_EndPrim();
    Heap_FreeRaw(buf);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_803692E0);
    Prim2D_PrepareTex();
#pragma cplusplus reset
}

void fn_8006FE44(void *arg0, void *arg1) {
    void *GfxEnt_Get(u8);
    s32 Text_MeasureWidth(void *, s32, f32);
    s32 fn_80010428(u8 **, s32, f32);
#pragma cplusplus on
    struct Obj {
        u8 pad[4];
        virtual void *v0() = 0;
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
        virtual s16 v17() = 0;
        virtual s16 v18() = 0;
    };
    struct TextObj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void *v4(void *) = 0;
    };
    u8 *group;
    u8 *self;
    s16 y;
    s8 c;
    s32 j;
    s32 t26;
    s32 i;
    s16 lineW;
    s16 step;
    s16 maxLine;
    u8 *text;
    s16 w;

    i = 0;
    self = (u8 *)arg0;
    group = (u8 *)arg1;
    *(s16 *)((u8 *)arg0 + 8) = i;
    while (i < (s8)(t26 = group[0x60])) {
        t26 = (s32)GfxEnt_Get(group[i + 0x40]);
        w = (s16)Text_MeasureWidth(
            (*(TextObj **)((u8 *)GfxEnt_Get(group[i + 0x40]) + 0x34))->v4((void *)t26),
            -1, 1.0f);
        if (w >= *(s16 *)(self + 8)) {
            *(s16 *)(self + 8) = w;
        }
        i += 1;
    }
    w = ((Obj *)arg0)->v18();
    c = (s8)t26;
    step = (s16)((s32)w / ((s32)c + 1));
    t26 = step;
    y = ((Obj *)arg0)->v17();
    for (j = 0; j < c; j++) {
        *(s16 *)((u8 *)GfxEnt_Get(group[j + 0x40]) + 0x30) = t26;
        *(s16 *)((u8 *)GfxEnt_Get(group[j + 0x40]) + 0x32) = y;
        t26 = t26 + step;
    }
    lineW = 0;
    maxLine = -1;
    text = (u8 *)((Obj *)arg0)->v0();
    while ((s8)*text != 0) {
        switch ((s8)*text) {
        case 10:
            if (lineW > maxLine) {
                maxLine = lineW;
            }
            lineW = 0;
            text += 1;
            break;
        default:
            lineW += fn_80010428(&text, -1, 1.0f);
            break;
        }
    }
    if (lineW > maxLine) {
        maxLine = lineW;
    }
    *(s16 *)(self + 0x10) = (s16)((((Obj *)arg0)->v18() - maxLine) >> 1);
#pragma cplusplus reset
}

void MsgWin_OpenSingle(s32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    extern u32 lbl_80311CA8[];
    extern s8 lbl_80366DE8;
    extern u32 lbl_80367350[2];
    extern u32 lbl_80367358[2];

    lbl_80366DE8 = -1;
    if (arg1 != 0U) {
        lbl_80311CA8[3] = arg1;
    }
    if (arg2 != 0U) {
        lbl_80367350[1] = arg2;
    }
    if (arg3 != 0U) {
        lbl_80367358[1] = arg3;
    }
    Ui_CreateMenu(lbl_80311CA8, arg0, 0);
}

void fn_80070084(void *arg0, void *arg1, void *arg2) {
void Prim2D_AddPrim(s32);
void Prim2D_SetPos(f32,f32);
void Prim2D_SetColor(s32,s32,s32,s32);
void Prim2D_SetText(void *);
void Prim2D_EndPrim(void);
void Prim2D_Begin(void);
void Prim2D_AddZ(f32);
void Prim2D_PrepareTex(void);
s32 Text_MeasureHeight(s32,f32);
s32 Text_MeasureWidth(void *,s32,f32);
#pragma cplusplus on
struct Model {u8 pad[4]; virtual void v0()=0;
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
virtual s32 v20()=0; };
struct Item {virtual void v0()=0;
virtual void * v1()=0;
virtual void v2()=0;
virtual void v3()=0;
virtual void * v4(void *)=0;
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
virtual void v17(void *)=0; };
f32 x;
s16 y;
s32 height;
x=(f32)(M2C_FIELD(arg2,s16 *,0x30)-(Text_MeasureWidth(((Item*)arg0)->v1(),-1,1.0f)>>1));
height=(s16)M2C_FIELD(arg1,Model **,0x3C)->v20();
y=M2C_FIELD(arg2,s16 *,0x32)+((height-Text_MeasureHeight(-1,1.0f))>>1);
((Item*)arg0)->v17(arg1);
Prim2D_AddPrim(6);
Prim2D_SetPos(x,(f32)y);
Prim2D_SetColor(0,0,0,255);
Prim2D_SetText(((Item*)arg0)->v4(arg2));
Prim2D_EndPrim();Prim2D_Begin();Prim2D_AddZ(1.0f);Prim2D_PrepareTex();
#pragma cplusplus reset
}

extern u8 lbl_80366DE9;
u8 fn_800701E0(s32 arg0, s32 arg1, u8 arg2) {
    extern u8 lbl_80366DE9;
    s8 temp = lbl_80366DE9;
    return (u8)(arg2 == temp);
}

void fn_800701FC(void *arg0) {
    void Ui_DrawMsgPanelBg(s32, s32);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    s32 Text_MeasureWidth(void *, s32, f32);
    extern f32 lbl_80369304;
    extern f32 lbl_80369308;
#pragma cplusplus on
    struct Obj {
        u8 pad[4];
        virtual void *v0() = 0;
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
        virtual s32 v18() = 0;
        virtual void v19() = 0;
        virtual void v20() = 0;
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual void v25() = 0;
        virtual void v26() = 0;
        virtual void v27() = 0;
        virtual void v28() = 0;
        virtual void v29() = 0;
        virtual void *v30() = 0;
    };
    Obj *self = (Obj *)arg0;
    s32 width;
    void *text;
    f32 posX;

    self->v29();
    Ui_DrawMsgPanelBg(0, 0);
    Prim2D_Begin();
    Prim2D_AddZ(-1.0f);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();

    width = (s16)self->v18();
    text = self->v0();
    posX = (f32)((width - Text_MeasureWidth(text, -1, 1.0f)) / 2);
    Prim2D_AddPrim(6);
    Prim2D_SetPos(posX, lbl_80369304);
    Prim2D_SetColor(0, 0, 0, 0xFF);
    Prim2D_SetText(self->v0());
    Prim2D_EndPrim();

    width = (s16)self->v18();
    text = self->v30();
    posX = (f32)((width - Text_MeasureWidth(text, -1, 1.0f)) / 2);
    Prim2D_AddPrim(6);
    Prim2D_SetPos(posX, lbl_80369308);
    Prim2D_SetColor(0, 0, 0, 0xFF);
    Prim2D_SetText(self->v30());
    Prim2D_EndPrim();
#pragma cplusplus reset
}

u32 fn_800703C4(void) {
    extern u8 lbl_80366DE8;

    lbl_80366DE8 = 0;
    return 9;
}

s32 fn_800703D4(void) {
    return 0;
}

#pragma cplusplus on
extern "C" void fn_800703DC(void *arg0, void *arg1) {
    extern u8 *gPadInput;
    extern char lbl_8026BB84[];

    void *GfxEnt_Get(u8);
    void Ui_PlaySeCue(void *, s32);

    u8 *self;
    u8 *entity;
    UiSelectionHandler *obj;
    u32 buttons;
    u8 index;
    s32 limit;
    s8 *p;

    self = (u8 *)arg1;
    buttons = *(u32 *)(gPadInput + 0xC);

    self[0x63] = self[0x62];

    index = self[0x62];

    if ((s8)index != 0 && (buttons & 0x01000001) != 0) {
        self[0x62] = index - 1;
    }

    index = self[0x62];
    limit = (s8)self[0x60];

    if ((s8)index != limit - 1 && (buttons & 0x02000002) != 0) {
        self[0x62]++;
    }

    p = (s8 *)(self + 0x62);
    if (p[0] != p[1]) {
        entity = (u8 *)GfxEnt_Get(self[0x40 + p[1]]);

        obj = *(UiSelectionHandler **)(entity + 0x34);
        obj->deselect(self, entity);

        entity = (u8 *)GfxEnt_Get(self[0x40 + (s8)self[0x62]]);

        obj = *(UiSelectionHandler **)(entity + 0x34);
        obj->select(self, entity);

        Ui_PlaySeCue(lbl_8026BB84 + 0x53, 0x64);
    }
}
#pragma cplusplus reset
void fn_800704F0(void *arg0, void *arg1) {
void *GfxEnt_Get(s32);
s32 Text_MeasureHeight(s32,f32);
void Prim2D_Begin(void);
void Prim2D_AddZ(f32);
void Prim2D_PrepareTex(void);
void Ui_DrawRouteIconEx(s32,s32,s32);
void fn_8008AB7C(s32,s32,s32,s32,s32,s32,s32);
extern f32 lbl_803692E0,lbl_803692F0,lbl_803692F4;
#pragma cplusplus on
struct Obj {u8 pad[4]; virtual void v0()=0;
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
virtual s16 v20()=0; };
u8 *self=(u8*)arg0;
u8 *obj=(u8*)arg1;
u8 *row;
void *ent;
s32 sy;
s32 sx;
s32 height,pulse;
s32 iconX,iconY;
row=obj;
row+=*(s8*)(row+0x62);
ent=GfxEnt_Get(row[0x40]);
sx=*(s16*)((u8*)ent+0x30)-(*(s16*)(self+0x8)>>1);
sx=(s16)(sx-0x10);
row=obj;
row+=*(s8*)(row+0x62);
ent=GfxEnt_Get(row[0x40]);
sy=*(s16*)((u8*)ent+0x32);
height=(s16)((Obj*)arg0)->v20();
sy=(s16)(sy+((height-Text_MeasureHeight(-1,lbl_803692E0))>>1));
if(*(s16*)(obj+0x3A)<0) {
*(s16*)(obj+0x38)=sx; *(s16*)(obj+0x3A)=sy;
} else {
*(s16*)(obj+0x38)=(*(s16*)(obj+0x38)+sx)/2;
*(s16*)(obj+0x3A)=(*(s16*)(obj+0x3A)+sy)/2;
}
Prim2D_Begin();Prim2D_AddZ(lbl_803692F0);Prim2D_PrepareTex();
iconX=*(s16*)(obj+0x38);
iconY=*(s16*)(obj+0x3A);
pulse=0;
if(!obj[0x2D]&&!obj[0x2E]) pulse=1;
Ui_DrawRouteIconEx(iconX,iconY,pulse);
sy=(s16)(*(s16*)(self+0x8)+0x40);
sx=(s16)Text_MeasureHeight(-1,lbl_803692E0);
Prim2D_Begin();Prim2D_AddZ(lbl_803692F4);Prim2D_PrepareTex();
fn_8008AB7C(*(s16*)(obj+0x38)+(sy>>1)-0x10,*(s16*)(obj+0x3A)+(sx>>1),sy,0x18,0x19,0x4B,1);
#pragma cplusplus reset
}
#pragma optimization_level reset
void fn_80070678(void *arg0) {
    void Ui_DrawMsgPanelBg(s32, s32);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    s32 Text_MeasureWidth(void *, s32, f32);

    extern f32 lbl_80369300;
    extern f32 lbl_803692E0;
    extern f32 lbl_8036930C;

    u8 *self;
    void **vtable;
    void *text;
    s32 width;
    s32 textWidth;
    s32 x;
    f32 posX;

    self = (u8 *)arg0;

    vtable = *(void ***)(self + 4);
    ((void (*)(void *))vtable[0x1F])(self);

    Ui_DrawMsgPanelBg(0, 0);

    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369300);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();

    vtable = *(void ***)(self + 4);
    width = (s16)((s32 (*)(void *))vtable[0x14])(self);

    vtable = *(void ***)(self + 4);
    text = ((void *(*)(void *))vtable[2])(self);

    textWidth = Text_MeasureWidth(text, -1, lbl_803692E0);

    x = (width - textWidth);
    x = (x + ((u32)x >> 31)) >> 1;
    posX = (f32)x;

    Prim2D_AddPrim(6);
    Prim2D_SetPos(posX, lbl_8036930C);
    Prim2D_SetColor(0, 0, 0, 0xFF);

    vtable = *(void ***)(self + 4);
    text = ((void *(*)(void *))vtable[2])(self);

    Prim2D_SetText(text);
    Prim2D_EndPrim();
}

void fn_80070798(void *arg0, void *arg1) {
    void *GfxEnt_Get(u8);
    s32 Text_MeasureWidth(void *, s32, f32);
    extern f32 lbl_803692E0;

    u8 *self;
    u8 *group;
    u8 *entity;
    void *obj;
    void **vtable;
    void *text;
    s32 i;
    s32 j;
    s32 count;
    s32 spacing;
    s32 x;
    s32 y;
    s16 width;
    s16 available;

    self = (u8 *)arg0;
    group = (u8 *)arg1;

    *(s16 *)(self + 8) = 0;

    for (i = 0; i < (s8)group[0x60]; i++) {
        entity = (u8 *)GfxEnt_Get(group[i + 0x40]);

        entity = (u8 *)GfxEnt_Get(group[i + 0x40]);
        obj = *(void **)(entity + 0x34);
        vtable = *(void ***)obj;

        text = ((void *(*)(void *, void *))vtable[6])(obj, entity);

        width = (s16)Text_MeasureWidth(text, -1, lbl_803692E0);

        if (width >= *(s16 *)(self + 8)) {
            *(s16 *)(self + 8) = width;
        }
    }

    obj = self;
    vtable = *(void ***)(self + 4);
    available = (s16)((s32 (*)(void *))vtable[0x14])(obj);

    count = (s8)group[0x60];
    spacing = (s16)(available / (count + 1));
    x = spacing;

    vtable = *(void ***)(self + 4);
    y = ((s32 (*)(void *))vtable[0x13])(self);

    for (j = 0; j < count; j++) {
        entity = (u8 *)GfxEnt_Get(group[j + 0x40]);
        *(s16 *)(entity + 0x30) = (s16)x;

        entity = (u8 *)GfxEnt_Get(group[j + 0x40]);
        *(s16 *)(entity + 0x32) = (s16)y;

        x += spacing;
    }
}

extern u16 lbl_80286860[];
void fn_800708B0(void *arg0, void *arg1) { void *Process_Find(void *); void fn_8018DC58(void); extern u16 lbl_80286860[]; extern u8 lbl_80366DE9; void *p; p=*(void **)((u8*)arg1+0x18); if(p==Process_Find(&lbl_80286860)) fn_8018DC58(); *(s8*)&lbl_80366DE9=-1; }

#pragma cplusplus on
extern "C" void *GfxEnt_Get(u8);
#pragma cplusplus on
extern "C" void fn_80070B3C(void *arg0, void *arg1) {
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
        virtual s32 v17() = 0;
        virtual void v18() = 0;
        virtual void v19() = 0;
        virtual s32 v20() = 0;
    };
    struct Grp {
        u8 pad[0x3C];
        Obj *obj;
        u8 ids[0x20];
        s8 count;
    };
    struct Ent {
        u8 pad[0x32];
        s16 y;
        u8 pad2[6];
        u8 level;
    };
    Grp *g = (Grp *)arg1;
    s32 i;
    Ent *p;

    for (i = 0; i < g->count; i++) {
        p = (Ent *)GfxEnt_Get(g->ids[i]);
        if (p->level >= 4) {
            p->y = g->obj->v17() + 0x90;
            s32 step = g->obj->v20();
            step *= p->level - 4;
            p->y += step;
        }
    }
}
#pragma cplusplus reset
extern "C" void fn_80070BF4(s32 arg0, void *arg1) {
    void *Unit_GetItemSlot(s32, u8);
    extern s32 gUiContext[];
    Unit_GetItemSlot(gUiContext[0], *(u8 *)((char *)arg1 + 0x3A));
}

#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_80070C24(void *arg0, s32 arg1, void *arg2) {
    struct Obj {
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
        virtual s32 v16(void *) = 0;
        virtual void v17() = 0;
    };
    void UnitRef_Draw(s32, bool, s16, s16);
    ((Obj *)arg0)->v17();
    UnitRef_Draw(((Obj *)arg0)->v16(arg2), *(u8 *)((u8 *)arg2 + 0x39) == 0, *(s16 *)((u8 *)arg2 + 0x30), *(s16 *)((u8 *)arg2 + 0x32));
}
#pragma cplusplus reset
void fn_80070EDC(void) {

}

#pragma cplusplus on
extern "C" s32 fn_80070EE0(void *arg0, s32 unused, s32 arg2) {
    struct Obj {
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
        virtual s32 v16(s32) = 0;
    };
    extern s32 gUiContext[];
    extern u8 gBattle[];
    void fn_801A6FB4(void *, s32, s32);
    s32 saved;

    saved = gUiContext[0];
    fn_801A6FB4(gBattle, saved, ((Obj *)arg0)->v16(arg2));
    return 0;
}
#pragma cplusplus reset
void fn_80070F3C(void *arg0) {
    extern s32 gUiContext[];
    extern s32 gUiAtlas;
    *(s32 *)((u8 *)arg0 + 0xC) = gUiContext[0];
    *(s32 *)((u8 *)arg0 + 8) = gUiAtlas;
}

#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void Ui_DrawWeaponTriangle(void *self, void *unit, f32 x, f32 y) {
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
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual f32 v25() = 0;
    };
    void Ui_DrawWindowTexture(void *, s32, s32, s32, s32, f32, f32, f32);
    void Ui_DrawIcon(void *, s32, s32, s32);
    extern u8 gUiIconDrawer[];
    extern u8 gUiWeaponTriangleData[];
    extern s32 lbl_80367348;
    extern s8 lbl_8036734C;
    extern f32 lbl_8036933C;
    extern f32 lbl_80369340;
    extern f32 lbl_80369344;
    extern f32 lbl_80369348;
    extern f32 lbl_8036934C;
    extern f32 lbl_803692E0;
    u8 *tbl;
    s8 row;
    s32 col;
    s32 icons[2][3];
    s32 xOff[9];
    s32 yOff[9];
    s32 *p;
    s32 type;
    void *sub;
    s32 idx;
    s32 iy;

    tbl = gUiWeaponTriangleData;
    row = -1;
    col = 0;
    p = (s32 *)(tbl + 0x1C);
    icons[0][0] = p[0];
    icons[0][1] = p[1];
    icons[0][2] = p[2];
    icons[1][0] = p[3];
    icons[1][1] = p[4];
    icons[1][2] = p[5];
    if (unit == NULL) {
        return;
    }
    sub = (u8 *)unit + 0x28C;
    if (sub == NULL) {
        return;
    }
    sub = *(void **)sub;
    if (sub != NULL) {
        type = *((u8 *)sub + 0x13);
    } else {
        type = 0xC;
    }
    type = (s8)(u8)type;
    switch (type) {
    case 0:
        row = 0;
        col = 0;
        break;
    case 1:
        row = 0;
        col = 1;
        break;
    case 2:
        row = 0;
        col = 2;
        break;
    case 3:
        row = 1;
        col = 0;
        break;
    case 4:
        row = 1;
        col = 1;
        break;
    case 5:
        row = 1;
        col = 2;
        break;
    case 6:
        break;
    }
    if (row == -1) {
        return;
    }
    Ui_DrawWindowTexture(self, 1, 0xFF, 0x39, 0, x, y, ((Obj *)self)->v25());
    p = (s32 *)(tbl + 0x34);
    xOff[0] = p[0];
    xOff[1] = p[1];
    xOff[2] = p[2];
    xOff[3] = p[3];
    xOff[4] = p[4];
    xOff[5] = p[5];
    xOff[6] = p[6];
    xOff[7] = p[7];
    xOff[8] = p[8];
    p = (s32 *)(tbl + 0x58);
    yOff[0] = p[0];
    yOff[1] = p[1];
    yOff[2] = p[2];
    yOff[3] = p[3];
    yOff[4] = p[4];
    yOff[5] = p[5];
    yOff[6] = p[6];
    yOff[7] = p[7];
    yOff[8] = p[8];
    if ((s8)lbl_8036734C == 0) {
        lbl_80367348 = 0;
        lbl_8036734C = 1;
    }
    lbl_80367348 = lbl_80367348 + 1;
    lbl_80367348 = lbl_80367348 % 24;
    idx = lbl_80367348 / 8;
    Ui_DrawWindowTexture(self, 1, 0xFF, 0x3A, 0, x + (f32)xOff[idx], y + (f32)yOff[idx], ((Obj *)self)->v25() - lbl_803692E0);
    Ui_DrawWindowTexture(self, 1, 0xFF, 0x3B, 0, x + (f32)xOff[idx + 3], y + (f32)yOff[idx + 3], ((Obj *)self)->v25() - lbl_803692E0);
    Ui_DrawWindowTexture(self, 1, 0xFF, 0x3C, 0, x + (f32)xOff[idx + 6], y + (f32)yOff[idx + 6], ((Obj *)self)->v25() - lbl_803692E0);
    Ui_DrawIcon(gUiIconDrawer, (s32)(lbl_8036933C + x), (s32)(y - lbl_80369340), icons[row][col]);
    Ui_DrawIcon(gUiIconDrawer, (s32)(lbl_80369344 + x), (iy = (s32)(lbl_80369348 + y)), icons[row][(col + 1) % 3]);
    Ui_DrawIcon(gUiIconDrawer, (s32)(x - lbl_8036934C), iy, icons[row][(col + 2) % 3]);
}
#pragma cplusplus reset

void fn_80071410(s32 unused, void *arg1, f32 f1, f32 f2) {
    u64 *Item_GetFlagsPtr(void *);
    void fn_8007CFB8(void *, s32, f32, f32);
    void *p;

    if (arg1 != NULL) {
        p = (u8 *)arg1 + 0x28C;
        if (p != NULL) {
            if ((*Item_GetFlagsPtr(p) & 1ULL) != 0) {
                fn_8007CFB8(arg1, 0, f1, f2);
            }
        }
    }
}

#pragma cplusplus on
extern "C" void fn_8007149C(void *self, u8 *list, u8 *data, u8 mode, f32 x, f32 y) {
    void *GfxEnt_Get(u8);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void fn_8008BBF8(s32, s32, s32, u16, u8, s32);
    extern f32 lbl_80369348, lbl_80369350, lbl_80369354;
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
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual f32 v25() = 0;
    };
    f32 baseX = lbl_80369348 + x;
    f32 baseY = lbl_80369350 + y;
    f32 lowerY = lbl_80369354 + y;
    f32 px, py;
    s32 i;
    u32 height;
    for (i = 0; i < (s8)list[0x60]; i++) {
        u8 *ent = (u8 *)GfxEnt_Get(list[i + 0x40]);
        s32 row = ent[0x3a];
        if (mode == 2)
            row += 4;
        if (mode == 0) {
            px = baseX;
            if (row < 4)
                py = baseY + (f32)(row * 28);
            else
                py = lowerY + (f32)((row - 4) * 28);
        }
        if (mode == 1) {
            px = baseX;
            py = baseY + (f32)(row * 28);
        }
        if (mode == 2) {
            px = baseX;
            py = baseY + (f32)((row - 4) * 28);
        }
        if (mode == 3) {
            px = baseX;
            py = baseY + (f32)(row * 28);
        }
        *(s16 *)(ent + 0x30) = (s16)px;
        *(s16 *)(ent + 0x32) = (s16)py;
    }
    switch (mode) {
    case 0:
        height = 0x110;
        break;
    case 1:
    case 2:
        height = 0x88;
        break;
    default:
        return;
    }
    Prim2D_Begin();
    Prim2D_SetTransform(0.0f, 0.0f, ((Obj *)self)->v25(), 1.0f);
    Prim2D_PrepareTex();
    fn_8008BBF8((s32)x, (s32)y, 0x108, (u16)height, (*(u8 **)(data + 0x190))[8], 0x9a);
}
extern "C" M2C_UNK Prim2D_Begin();
extern "C" M2C_UNK Prim2D_PrepareTex();
extern "C" void Prim2D_SetTransform(f32, f32, f32, f32);
extern "C" void fn_8008B464(s32, s32, s32);
extern "C" void fn_80071740(void *arg0, s32 arg1, f32 x, f32 y) {
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
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual f32 v25() = 0;
    };

    Prim2D_Begin();
    Prim2D_SetTransform(0.0f, 0.0f, ((Obj *)arg0)->v25(), 1.0f);
    Prim2D_PrepareTex();
    fn_8008B464(arg1, (s32)x, (s32)y);
}

extern "C" void Ui_DrawWindowTexture(void *arg0, s32 color, s32 alpha, s32 texId, s32 flags, f32 x, f32 y, f32 z) {
#pragma inline_depth(0)
    u32 *Ui_GetColor(s32);
    s32 fn_8006EDD8(void *, u16);
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void fn_80009EB0(void *, u16, s32, s32);
    void Prim2D_BindTexture(void *, u16, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPrimParam(f32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetColor(u8, u8, u8, s32);
    void Prim2D_EmitQuad(void);
    void Prim2D_EndPrim(void);

    u32 packed;
    f32 u0;
    f32 u1;
    f32 v0;
    f32 v1;
    u16 w;
    u16 h;
    s32 *entry;

    packed = *Ui_GetColor(color);
    entry = (s32 *)fn_8006EDD8(*(void **)((u8 *)arg0 + 8), texId);
    w = (*(u16 **)entry)[1];
    h = (*(u16 **)entry)[0];
    u0 = 0.0f;
    v0 = u0;
    u1 = (f32)w;
    v1 = (f32)h;
    if (flags & 1) {
        u0 = u1;
        u1 = v0;
    }
    if (flags & 2) {
        v0 = v1;
        v1 = 0.0f;
    }
    Prim2D_Begin();
    Prim2D_SetTransform(0.0f, 0.0f, z, 1.0f);
    if ((u32)entry[1] != 0) {
        fn_80009EB0(*(void **)((u8 *)arg0 + 8), texId, 0, 0x11);
    } else {
        Prim2D_BindTexture(*(void **)((u8 *)arg0 + 8), texId, 0x11);
    }
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetPrimParam(0.0f);
    Prim2D_SetQuadMin(x, y, u0, v0);
    Prim2D_SetQuadMax(x + (f32)w, y + (f32)h, u1, v1);
    Prim2D_SetColor(((u8 *)&packed)[0], ((u8 *)&packed)[1], ((u8 *)&packed)[2], alpha);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
}

#pragma cplusplus reset
void fn_800719E4(void *arg0, void *arg1) {
#pragma cplusplus on
struct Obj { u8 pad[4];
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
virtual void v19() = 0;
virtual void v20() = 0;
virtual void v21() = 0;
virtual void v22() = 0;
virtual void v23() = 0;
virtual void v24() = 0;
virtual void v25() = 0;
virtual void v26() = 0;
virtual void v27() = 0;
virtual void v28() = 0;
virtual void v29() = 0;
};
s32 Text_MeasureHeight(s32, f32);
void fn_8008AB7C(s32,s32,s32,s32,s32,s32,s32);
void fn_8008C1D8(s32,s32,s32,s32,s32);
void Prim2D_AddZ(f32);
s32 flag;
s32 n = *(s8*)((u8*)arg1+0x60);
((Obj*)arg0)->v29();
fn_8008C1D8(0,0,0,(n<<5)+0x20,0);
if (*(s16*)((u8*)arg1+0x3A)>=5) {
Prim2D_Begin(); Prim2D_AddZ(-0.1f); Prim2D_PrepareTex();
flag=0;
if (!*(u8*)((u8*)arg1+0x2D) && !*(u8*)((u8*)arg1+0x2E)) flag=1;
fn_8008AB7C(((Obj*)arg0)->v18()/2, *(s16*)((u8*)arg1+0x3A)+Text_MeasureHeight(-1,1.0f)/2, (s32)(0.9f*((Obj*)arg0)->v18()),0x17,0x19,0x4B,flag);
Prim2D_Begin(); Prim2D_AddZ(0.1f); Prim2D_PrepareTex();
}
#pragma cplusplus reset
}
void fn_80071B34(void) {
    M2C_UNK fn_8018DAD4();
    fn_8018DAD4();
}

void fn_80071B54(void) {
    M2C_FIELD(&gBattleState, s8 *, 0x51D) = 0xF;
    fn_8018DBD8(&gBattleState);
    fn_8018DB10();
}

void fn_80071B88(void) {
    M2C_UNK Prim2D_AddZ(f32);
    M2C_UNK Prim2D_SetTex(M2C_UNK, M2C_UNK);
    M2C_UNK Prim2D_PrepareTex();
    M2C_UNK Prim2D_Begin();
    extern f32 lbl_80369300;
    Prim2D_Begin();
    Prim2D_AddZ(lbl_80369300);
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
}

#pragma cplusplus on
extern "C" void fn_80071BC0(void *arg0, void *arg1, void *arg2) {
    void Prim2D_AddPrim(s32);
    void Prim2D_SetPos(f32, f32);
    void Prim2D_SetText(void *);
    void Prim2D_EndPrim(void);
    s32 Text_MeasureWidth(void *, s32, f32);
    extern f32 lbl_803692E0;
    struct T { virtual void *a()=0; virtual void *b()=0; virtual void *c()=0; virtual void *d()=0; virtual void *e(void *)=0; };
    struct W { u8 pad[4]; virtual s32 a()=0; virtual s32 b()=0; virtual s32 c()=0; virtual s32 d()=0; virtual s32 e()=0; virtual s32 f()=0; virtual s32 g()=0; virtual s32 h()=0; virtual s32 i()=0; virtual s32 j()=0; virtual s32 k()=0; virtual s32 l()=0; virtual s32 m()=0; virtual s32 n()=0; virtual s32 o()=0; virtual s32 p()=0; virtual s32 q()=0; virtual s32 r()=0; virtual s32 s()=0; };
    struct S { virtual void a()=0; virtual void b()=0; virtual void c()=0; virtual void d()=0; virtual void e()=0; virtual void f()=0; virtual void g()=0; virtual void h()=0; virtual void i()=0; virtual void j()=0; virtual void k()=0; virtual void l()=0; virtual void m()=0; virtual void n()=0; virtual void o()=0; virtual void p()=0; virtual void q()=0; virtual void r(void*,s32)=0; virtual void s(void*)=0; };
    void *self; void *param; void *win; s32 textWidth; T *obj; void *text; s32 width; s32 diff;
    win=arg2; param=arg1; self=arg0;
    obj=*(T**)((u8*)win+0x34); text=obj->e(win);
    textWidth=Text_MeasureWidth(text,-1,lbl_803692E0);
    width=(s16)(*(W**)((u8*)param+0x3C))->s();
    diff=width-textWidth; textWidth=(s32)(diff+((u32)diff>>31))>>1;
    ((S*)self)->r(param,diff);
    Prim2D_AddPrim(6);
    Prim2D_SetPos((f32)textWidth,(f32)*(s16*)((u8*)win+0x32));
    ((S*)self)->s(win);
    obj=*(T**)((u8*)win+0x34); text=obj->e(win);
    Prim2D_SetText(text); Prim2D_EndPrim();
}
#pragma cplusplus reset
void fn_80071CE8(void *arg0, void *arg1) {
    void Prim2D_SetColorPacked(s32 *);
    s32 *Ui_GetColor(s32);
    s32 sp8;

    if (*(u8 *)((u8 *)arg1 + 0x39) == 2) {
        sp8 = *Ui_GetColor(0);
        Prim2D_SetColorPacked(&sp8);
    }
}

/* Average obj screen pos toward its linked gfx entity, then draw the route icon. */
void Ui_DrawObjRouteIcon(void *unused, void *obj) {
    void *GfxEnt_Get(s32);
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Ui_DrawRouteIconEx(s32, s32, s32);
    extern f32 lbl_803692F0;
    u8 *row;
    void *ent;
    s16 sx;
    s16 sy;
    s32 pulse;

    (void)unused;
    row = (u8 *)obj;
    row += *(s8 *)(row + 0x62);
    ent = GfxEnt_Get(*(u8 *)(row + 0x40));
    sx = *(s16 *)((u8 *)ent + 0x30);

    row = (u8 *)obj;
    row += *(s8 *)(row + 0x62);
    ent = GfxEnt_Get(*(u8 *)(row + 0x40));
    sy = *(s16 *)((u8 *)ent + 0x32);

    if (*(s16 *)((u8 *)obj + 0x3A) < 0) {
        *(s16 *)((u8 *)obj + 0x38) = sx;
        *(s16 *)((u8 *)obj + 0x3A) = sy;
    } else {
        *(s16 *)((u8 *)obj + 0x38) = (s16)((*(s16 *)((u8 *)obj + 0x38) + sx) / 2);
        *(s16 *)((u8 *)obj + 0x3A) = (s16)((*(s16 *)((u8 *)obj + 0x3A) + sy) / 2);
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_803692F0);
    Prim2D_PrepareTex();

    pulse = 0;
    if (((u8 *)obj)[0x2D] == 0 && ((u8 *)obj)[0x2E] == 0) {
        pulse = 1;
    }
    Ui_DrawRouteIconEx(*(s16 *)((u8 *)obj + 0x38), *(s16 *)((u8 *)obj + 0x3A), pulse);
}

void fn_80071E0C(void *arg0, void *arg1) {
#pragma cplusplus on
struct Obj { u8 pad[4];
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
virtual void v19() = 0;
virtual void v20() = 0;
virtual void v21() = 0;
virtual void v22() = 0;
virtual void v23() = 0;
virtual void v24() = 0;
virtual void v25() = 0;
virtual void v26() = 0;
virtual void v27() = 0;
virtual void v28() = 0;
virtual void v29() = 0;
};
s32 Text_MeasureHeight(s32, f32);
void fn_8008AB7C(s32,s32,s32,s32,s32,s32,s32);
void fn_8008C1D8(s32,s32,s32,s32,s32);
void Prim2D_AddZ(f32);
s32 flag;
s32 n = *(s8*)((u8*)arg1+0x60);
((Obj*)arg0)->v29();
fn_8008C1D8(0,0,0x90,(n<<5)+0x20,1);
if (*(s16*)((u8*)arg1+0x3A)>=5) {
Prim2D_Begin(); Prim2D_AddZ(-0.1f); Prim2D_PrepareTex();
flag=0;
if (!*(u8*)((u8*)arg1+0x2D) && !*(u8*)((u8*)arg1+0x2E)) flag=1;
fn_8008AB7C(((Obj*)arg0)->v18()/2, *(s16*)((u8*)arg1+0x3A)+Text_MeasureHeight(-1,1.0f)/2, (s32)(0.9f*((Obj*)arg0)->v18()),0x18,0x19,0x4B,flag);
Prim2D_Begin(); Prim2D_AddZ(0.1f); Prim2D_PrepareTex();
}
#pragma cplusplus reset
}

void fn_80071F5C(void *unused, void *win) {
#pragma cplusplus on
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetColorByte(s32);
    f32 UiWin_GetFade(void *);
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void fn_80009C20(f32,f32,f32,f32,f32,f32,f32,f32);
    extern f32 lbl_803692E0, lbl_80369314, lbl_803692F8;
    struct Model {
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
        virtual void v21() = 0;
        virtual void v22() = 0;
        virtual void v23() = 0;
        virtual void v24() = 0;
        virtual f32 v25() = 0;
    };
    f32 scale = Math_Ease(5, lbl_80369314, lbl_803692E0, UiWin_GetFade(win), lbl_803692E0);
    Prim2D_Begin();
    fn_80009C20((f32)M2C_FIELD(win,s16 *,0x30), (f32)M2C_FIELD(win,s16 *,0x32),
        M2C_FIELD(win,Model **,0x3C)->v25(), (f32)(M2C_FIELD(win,s16 *,0x34)/2),
        (f32)(M2C_FIELD(win,s16 *,0x36)/2), scale, scale, lbl_80369314);
    Prim2D_SetColorByte((s32)(lbl_803692F8 * UiWin_GetFade(win)));
    Prim2D_PrepareTex();
#pragma cplusplus reset
}

void fn_80072088(void *arg0, void *arg1) {
    void *Process_Find(void *);
    void fn_8018DC58(void);
    extern u16 lbl_80286860[];
    void *p;

    p = *(void **)((u8 *)arg1 + 0x18);
    if (p == Process_Find(&lbl_80286860)) {
        fn_8018DC58();
    }
}

void fn_800720C8(s32 unused, void *arg1) {
    s16 temp_r5;
    s32 temp_r3;

    temp_r5 = *(s16 *)((u8 *)arg1 + 0x36);
    temp_r3 = *(s16 *)((u8 *)arg1 + 0x32) + temp_r5;
    if (temp_r3 / 2 > 0xE0) {
        *(s16 *)((u8 *)arg1 + 0x32) = (s16)((0x1C0 - temp_r5) / 2);
    }
}

void fn_80072100(void *arg0, void *arg1) {
    void *Process_Find(void *);
    void fn_8018DBD8(void);
    void *temp_r31;
    void *result;

    *(u8 *)((u8 *)gBattleState + 0x51D) = 0xF;
    temp_r31 = *(void **)((u8 *)arg1 + 0x18);
    result = Process_Find(lbl_80286860);
    if (temp_r31 == result) {
        fn_8018DBD8();
    }
}

s32 fn_80072150(void) {
    extern s8 lbl_80366DE8;
    lbl_80366DE8 = 0;
    return 5;
}

u32 fn_80072160(void) {
    extern u8 lbl_80366DE8;

    lbl_80366DE8 = 1;
    return 5;
}

void fn_80072170(void *arg0) {
    Msg_Expand(M2C_FIELD(arg0, s32 *, 4));
}

s32 fn_80072194(void) {
    return 0xA0;
}

s32 fn_8007219C(void) {
    return 0x100;
}

s32 fn_800721A4(void) {
    return 0x20;
}

s32 fn_800721AC(void) {
    return 0x88;
}

void fn_800721B4(void *arg0) {
    Msg_Expand(M2C_FIELD(arg0, s32 *, 0xC));
}

s32 fn_800721D8(void) {
    return 0x160;
}

s32 fn_800721E0(void) {
    return 0x48;
}

s16 fn_800721E8(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x10);
}

void *fn_800721F0(void) {
    extern u16 lbl_8026BB84[];
    return (u8 *)lbl_8026BB84 + 0x46;
}

s32 fn_80072200(void) {
    return 0x108;
}

s32 fn_80072208(void) {
    return 0x78;
}

s32 fn_80072210(void) {
    return 0x78;
}

s32 fn_80072218(void) {
    return 0x98;
}

s16 fn_80072220(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0xE);
}

s16 fn_80072228(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x10);
}

s32 fn_80072230(void) {
    return 0xB0;
}

f32 fn_80072238(void) {
    extern f32 lbl_80369360;
    return lbl_80369360;
}

void *fn_80072240(void) {
    extern u8 lbl_8026BB84[];

    return lbl_8026BB84 + 0x6F;
}

void *fn_80072250(void) {
    extern u16 lbl_8026BB84[];
    return (u8 *)lbl_8026BB84 + 0x88;
}

void *fn_80072260(void) {
    extern u16 lbl_8026BB84[];
    return (u8 *)lbl_8026BB84 + 0xA2;
}

s32 fn_80072270(void) {
    return 4;
}

s32 fn_80072278(void) {
    return 4;
}

s32 fn_80072280(void) {
    return 0xB0;
}

s32 fn_80072288(void) {
    return 8;
}

s32 fn_80072290(void) {
    return 8;
}

#pragma cplusplus on
extern "C" s16 fn_80072298(void *arg0) {
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
    return (s16)(0x130 - (temp / 2));
}
extern "C" s16 fn_800722DC(void *arg0) {
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
        virtual s16 v19() = 0;
    };
    s16 temp = ((Obj *)arg0)->v19();
    return (s16)(0xE0 - (temp / 2));
}
#pragma cplusplus reset
s32 fn_80072320(void) {
    return 0x54;
}

s32 fn_80072328(u8 *arg0) {
    if (*(s16 *)(arg0 + 0x12) < *(s16 *)(arg0 + 0x10)) {
        arg0 += 0x12;
    } else {
        arg0 += 0x10;
    }
    return *(s16 *)arg0;
}

s32 fn_8007234C(void) {
    return 0x54;
}

s32 fn_80072354(void) {
    return 0x50;
}

s32 fn_8007235C(void) {
    return 0x42;
}

s32 fn_80072364(void) {
    return 0x12C;
}

s32 fn_8007236C(void) {
    return 0x1C;
}

s32 fn_80072374(void) {
    return 0x14;
}

s32 fn_8007237C(void) {
    return 0x1E;
}

s32 fn_80072384(void) {
    return 0x28;
}

s32 fn_8007238C(void) {
    return 0xB4;
}

s32 fn_80072394(void) {
    return 0;
}

s32 fn_8007239C(void) {
    return 0x90;
}

void *fn_800723A4(void) {
    extern u16 lbl_8026BB84[];
    return (u8 *)lbl_8026BB84 + 0xC2;
}

void *fn_800723B4(void) {
    extern u8 lbl_8026BB84[];

    return lbl_8026BB84 + 0xD7;
}

s32 fn_800723C4(void) {
    return 0;
}

s32 fn_800723CC(void) {
    return 0x14;
}

s32 fn_800723D4(void) {
    return 0x190;
}

s32 fn_800723DC(void) {
    return 0x80;
}

void fn_800723E4(void *arg0) {
    Msg_Expand(M2C_FIELD(arg0, s32 *, 4));
}
extern void *gCamera;
extern s32 *jumptable_80285D18;
extern u8 lbl_80366DE9;
extern struct Unit {
    /* Some fields are guessed based on usage and context of similar structs */
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
    u16 unk1C;
    u16 unk1E;
    u16 unk20;
    u16 unk22;
    u16 unk24;
    u16 unk26;
    u16 unk28;
    u16 unk2A;
    u16 unk2C;
    u16 unk2E;
} Unit; 
#include "common.h"
#include "global.h"

extern u16 lbl_8026B980[8];
#include "common.h"
#include "global.h"
extern f32 lbl_803692E0;
extern f32 lbl_80369310;
extern f32 lbl_80369314;
extern f32 lbl_80369318;
extern f32 lbl_8036931C;
extern f32 lbl_80369320;
extern f32 lbl_80369324;
extern f32 lbl_80369328;
extern f32 lbl_8036932C;
extern f32 lbl_80369330;
extern f32 lbl_80369334;
extern f32 lbl_80369338;
extern u8 gBattle[];

extern u8 gFileCacheWorkQueue[];
extern u8 gFileCacheWorkWrite;
extern u32 gFileCacheWorkThreadQueue;
extern s32 RunQueueBits_80368518;
extern s32 RunQueueHint_8036851C;
extern void *RunQueue_80339478[256];
/* Functions from 0x8005AE20 to 0x80072408, found by decomp-toolkit. */
#include "common.h"
#include "global.h"

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
} Struct_80067304;

typedef struct { f32 x, y, z; } Vec3f_67304;
extern Vec3f_67304 lbl_8026B744;
extern Vec3f_67304 lbl_8026B750;
extern f32 lbl_80369224;
extern f32 lbl_80369228;
extern s32 lbl_8036C444;
extern s32 lbl_8036C448;
#include "common.h"
#include "global.h"

extern f32 lbl_803692E0;
extern f32 lbl_803692F8;
extern f64 lbl_803692E8;
#include "global.h"

extern f32 lbl_803692F0;
#include "common.h"
#include "global.h"

extern s32 lbl_80366DDC;
extern f32 lbl_80369248;
extern const s32 lbl_8026B75C[3];
#include "common.h"
#include "global.h"

extern void fn_80225D6C(s32* a, s32* b, s32* c, s32* d);
extern void fn_8021F168(void* a, void* b, u8* c, u8* d, void* e, s32 f, s32 g, s32 h);
extern void OSReport(const char* fmt, ...);
extern char DEMOInit_str[];
#include "common.h"
#include "global.h"

extern f32 lbl_803691E0;
extern f32 lbl_80369200;
extern f32 lbl_80369208;
#include "common.h"
#include "structs.h"

extern f32 gMtxZero;
extern f32 gDegToRad;
extern u8 gGUtilAssertMsg[];
