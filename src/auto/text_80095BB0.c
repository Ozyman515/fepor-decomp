/* Functions from 0x8007C5E4 to 0x8009F0BC, found by decomp-toolkit. */
#include "common.h"
typedef struct EventResourceRequest { s16 code; s16 active; u32 flags; } EventResourceRequest;
#include "global.h"
static inline u8 Event_ScanPositiveArg(u8 *s,s32 start) {
u8 found;
*(s16 *)s=start;
*(s16 *)s=(s16)start+1;
found=0;
for(;;){
switch(s[(*(s16 *)s*4)+4]){
case 0:case 0x20:case 0x21:case 0x22:case 0x24:
case 0x50:case 0x51:case 0x52:return found;
case 9:case 0x15:
if((s8)*(s16 *)(s+(*(s16 *)s*4)+6)>0)found=1;
break;
}
++*(s16*)s;
}
}

static inline u32 Event_ScanCommandFlagsInline(s16 *idx,s32 cur) {
extern u8 gBattle[];
void fn_800973F0(void *,s32);
s16 saved=(s16)cur;
s32 flagb,cursor,offset;
u8 ok;
*idx=cur;flagb=0;*idx=(s16)cur+1;
for(;;){
cursor=*idx;offset=cursor*4+4;
switch((s32)((u8*)idx)[offset]){
case 0:case 0x20:case 0x21:case 0x22:case 0x24:case 0x50:case 0x51:case 0x52:case 0x54:goto scan3done;
case 9:case 0x15:
if((s8)*(s16*)((u8*)idx+cursor*4+6)==0)flagb|=0x20000;break;
default:offset=cursor*4+4;fn_800973F0(&flagb,((u8*)idx)[offset]);break;
}
(*idx)++;
}
scan3done:
*idx=saved;
if(flagb&0x10000004){
*idx=cur;*idx=(s16)cur+1;ok=0;
for(;;){
cursor=*idx;offset=cursor*4+4;
switch((s32)((u8*)idx)[offset]){
case 0:case 0x20:case 0x21:case 0x22:case 0x24:case 0x50:case 0x51:case 0x52:goto scan4done;
case 9:case 0x15:
if((s8)*(s16*)((u8*)idx+cursor*4+6)>0)ok=1;break;
default:break;
}
(*idx)++;
}
scan4done:
*idx=cur;if(ok)flagb|=1;
}

return flagb;
}

static inline void *Event_SelectCommandResource(void **slot,u32 flags,s32 code,s32 kind) {
extern u8 gEventCmdStrings[];
void *fn_80055204(void *,s32);
void *str;
if(kind==1)return 0;
if(code==0x52)return 0;
if(flags&0x1000000)return gEventCmdStrings+0xDB;
if(flags&0x20000)return gEventCmdStrings+0xED;
if(flags&2)return gEventCmdStrings+0xFA;
if(slot){str=fn_80055204(*slot,1);if(str)return str;}
if(flags&0x40)return gEventCmdStrings+0x105;
if(code==0x51)return gEventCmdStrings+0x114;
if(code==0x50)return gEventCmdStrings+0xFA;
return 0;
}

extern void* lbl_803674E8;
extern f32 lbl_803696C8;

extern s32 gSaveDataBase;
extern void *lbl_8026CC58;
extern void *lbl_80289998;
extern f32 gScreenOrigin;
extern f32 lbl_803696A8;
extern f32 lbl_803696AC;

extern void* gActiveFace;
extern s32 gFaceDbgMouthStartStr;
extern s32 gFaceDbgMouthEndStr;
extern f64 lbl_803693C8;
extern f32 lbl_803693D4;
extern f32 lbl_803693D8;
extern f32 gFaceDbgTextScale;

extern u8 gBattleState[1400];

extern u16 *lbl_803674E0;

#pragma inline

extern f32 lbl_8036A118;
extern f32 lbl_8036A120;
extern f32 lbl_8036A130;
extern f32 gTextScale2;

extern f32 lbl_80369768;
extern u16 lbl_80289A60[];

extern u8 lbl_80289B00[16];

extern void* fn_800980D4(s32 arg0);
extern void fn_8017E394(void* arg0, void* arg1, void* arg2, s32 arg3);

extern u8 lbl_80289EB8[16];

extern f32 lbl_803697E0;
extern f32 lbl_803697E4;

#pragma scheduling reset

s32 fn_80095BB0(s32 arg0) {
    extern s32 lbl_80367500, lbl_80367504;
    switch(arg0) {
    case (s32)0x80000000:
    case 0x100: case 0x200: case 0x400: case 0x800:
    case 0x2000: case 0x8000: case 0x40000:
    case 0x800000: case 0x1000000: case 0x2000000:
    case 0x4000000: case 0x8000000: case 0x10000000:
    case 0x20000000: case 0x40000000:
        return lbl_80367500;
    case 2: case 8: case 0x10: case 0x20: case 0x80:
    case 0x1000: case 0x4000: case 0x10000:
        return lbl_80367504;
    default: return 0;
    }
}

/* Return the debug name string for a single event command flag bit. */
char *Event_GetCmdFlagName(s32 flag)
{
    extern char gEventCmdStrings[];

    switch (flag) {
    case 0x8000000:
        return gEventCmdStrings + 0x122;
    case 0x20000000:
        return gEventCmdStrings + 0x12A;
    case 0x10000000:
        return gEventCmdStrings + 0x132;
    case 0x40000000:
        return gEventCmdStrings + 0x13A;
    case 0x80000000:
        return gEventCmdStrings + 0x142;
    case 0x2000000:
        return gEventCmdStrings + 0x14A;
    case 0x4000000:
        return gEventCmdStrings + 0x152;
    case 0x1000000:
        return gEventCmdStrings + 0x15E;
    case 2:
        return gEventCmdStrings + 0x166;
    case 0x2000:
        return gEventCmdStrings + 0x174;
    case 0x4000:
        return gEventCmdStrings + 0x174;
    case 0x1000:
        return gEventCmdStrings + 0x17E;
    case 0x800000:
        return gEventCmdStrings + 0x18A;
    case 0x100:
        return gEventCmdStrings + 0x192;
    case 0x200:
        return gEventCmdStrings + 0x19A;
    case 0x400:
        return gEventCmdStrings + 0x1A2;
    case 0x800:
        return gEventCmdStrings + 0x1AA;
    case 0x8000:
        return gEventCmdStrings + 0x1B4;
    case 0x10000:
        return gEventCmdStrings + 0x1B4;
    case 0x40000:
        return gEventCmdStrings + 0x1C0;
    case 0x10:
        return gEventCmdStrings + 0x1D2;
    case 8:
        return gEventCmdStrings + 0x1E0;
    case 0x80:
        return gEventCmdStrings + 0x1EC;
    case 0x20:
        return gEventCmdStrings + 0x1F4;
    default:
        return NULL;
    }
}

/* Look up the resource pointer for a single event command flag bit. */
u32 Event_GetCmdFlagRes(s32 flag) {
    void *Res_GetEntry(u8);
    void fn_800056A0(s32);
    u32 res;
    u8 entryId;

    entryId = 0xFF;
    switch (flag) { /* irregular */
    case 0x8000000:
        entryId = 0x31;
        break;
    case 0x20000000:
        entryId = 0x30;
        break;
    case 0x10000000:
        entryId = 0x2F;
        break;
    case 0x40000000:
        entryId = 0x38;
        break;
    case 0x80000000:
        entryId = 0x39;
        break;
    case 0x2000000:
        entryId = 0x35;
        break;
    case 0x4000000:
        entryId = 0x4C;
        break;
    case 0x1000000:
        entryId = 0x33;
        break;
    case 0x800000:
        entryId = 0x5A;
        break;
    case 0x400:
        entryId = 0x32;
        break;
    case 0x2000:
        entryId = 0x2A;
        break;
    case 0x4000:
        entryId = 0x2A;
        break;
    case 0x1000:
        entryId = 0x29;
        break;
    case 0x100:
        entryId = 0x2B;
        break;
    case 0x200:
        entryId = 0x10;
        break;
    case 0x800:
        entryId = 0x3F;
        break;
    case 0x8000:
        entryId = 0x41;
        break;
    case 0x10000:
        entryId = 0x41;
        break;
    case 0x2:
        entryId = 0x37;
        break;
    case 0x8:
        entryId = 0x34;
        break;
    case 0x80:
        entryId = 0x2E;
        break;
    case 0x10:
        entryId = 0x2C;
        break;
    case 0x20:
        entryId = 0x2D;
        break;
    case 0x40000:
        entryId = 0x54;
        break;
    }
    if (entryId == 0xFF) {
        fn_800056A0(0);
        return 0U;
    }
    res = *(u32 *)((u8 *)Res_GetEntry(entryId) + 0x14);
    if (res == 0U) {
        fn_800056A0(0);
        return 0U;
    }
    return res;
}

void fn_80096264(void) {
extern void **lbl_80367500;
extern u8 gBattle[];
void *Item_GetFlagsPtr(void*);
void *fn_80055204(void *, s32);
void GActor_RequestRes(void *);
void *item;
u8 *unit=*lbl_80367500;
s32 kind;
if(!unit) item=0;
else {item=unit+0x28C;if(!*(u32*)item) item=0;}
if(item) {
if(*(u64*)Item_GetFlagsPtr(item)&2ULL) {kind=1;goto done;}
if(*(u64*)Item_GetFlagsPtr(item)&0x800000000ULL) {kind=2;goto done;}
if(*(u64*)Item_GetFlagsPtr(item)&0x8000000000ULL) {kind=1;goto done;}
if(*(s32*)(gBattle+0xCA8)>1) {
if(*(u64*)Item_GetFlagsPtr(item)&0x40ULL) {kind=1;goto done;}
if(*(u64*)Item_GetFlagsPtr(item)&0x4000000000ULL) {kind=3;goto done;}
}
}
kind=0;
done:
switch(kind) {case 1: case 2: case 3: GActor_RequestRes(fn_80055204(unit,0));break;}
}

#pragma cplusplus on
#pragma global_optimizer off
#pragma use_lmw_stmw on
extern "C" void fn_80096418(s32 arg0) {
void *Item_GetFlagsPtr(void *);
void fn_8004FC70(s32,s32);
void *fn_80055204(void *,s32);
void GActor_RequestRes(void *);
u32 Event_GetCmdFlagRes(s32);
s32 fn_80096EEC(s32 *,u32);
void fn_800973F0(void *,s32);
extern u8 gBattle[],gEventCmdStrings[];
extern void **lbl_80367500,**lbl_80367504;
EventResourceRequest ents[20];s32 buf[20];s32 flaga,flagb;
u8 *battle;
void **g0;
s32 arg_save;
EventResourceRequest *ep;
s32 i;
s32 count;
s32 *p;
s32 n;
s32 cur;
s16 saved;
register s16 *idx;
s32 cursor,offset,c,kind;
u8 ok;
u32 flags;
void *item,*str,*unit;
g0=lbl_80367500;
if(!lbl_80367504)arg_save=0;
else if(*lbl_80367504)arg_save=M2C_FIELD(*lbl_80367504,s32 *,0x280);
else arg_save=0;
idx=(s16 *)(gBattle+0x8A0);
saved=*idx;flaga=0;*idx=arg0;*idx=(s16)arg0+1;
for(;;){
cursor=*idx;offset=cursor*4+4;
switch((s32)((u8*)idx)[offset]){
case 0:case 0x20:case 0x21:case 0x22:case 0x24:case 0x54:goto scan1done;
default:offset=cursor*4+4;fn_800973F0(&flaga,((u8*)idx)[offset]);break;
}
(*idx)++;
}
scan1done:
*idx=saved;n=fn_80096EEC(buf,flaga);
p=buf;for(i=0;i<n;p++,i++)GActor_RequestRes((void*)Event_GetCmdFlagRes(*p));
saved=*idx;ep=ents;*idx=arg0;count=0;*idx=(s16)arg0+1;
for(;;){
cur=*idx;offset=cur*4+4;c=((u8*)idx)[offset];
switch(c){
case 0:case 0x20:case 0x21:case 0x22:case 0x24:goto scan2done;
case 0x56:
ep->flags=Event_ScanCommandFlagsInline(idx,cur);break;
case 0x50:case 0x51:case 0x52:
ep->code=c;ep->active=1;count++;ep++;break;
default:break;
}
(*idx)++;
}
scan2done:
*idx=saved;ep=ents;battle=gBattle;
for(i=0;i<count;ep++,i++){
unit=*lbl_80367500;flags=ep->flags;cur=ep->code;
if(!unit)item=0;
else {item=(u8*)unit+0x28C;if(!*(u32*)item)item=0;}
if(item){
if(*(u64*)Item_GetFlagsPtr(item)&2ULL){kind=1;goto kindDone;}
if(*(u64*)Item_GetFlagsPtr(item)&0x800000000ULL){kind=2;goto kindDone;}
if(*(u64*)Item_GetFlagsPtr(item)&0x8000000000ULL){kind=1;goto kindDone;}
if(*(s32*)(battle+0xCA8)>1){
if(*(u64*)Item_GetFlagsPtr(item)&0x40ULL){kind=1;goto kindDone;}
if(*(u64*)Item_GetFlagsPtr(item)&0x4000000000ULL){kind=3;goto kindDone;}
}
}
kind=0;
kindDone:
str=Event_SelectCommandResource(g0,flags,cur,kind);
if(str)GActor_RequestRes(str);
flags=ep->flags;
if(flags&0x80)str=(void*)Event_GetCmdFlagRes(0x80);
else if(flags&0x20)str=(void*)Event_GetCmdFlagRes(0x20);
else if(flags&8)str=(void*)Event_GetCmdFlagRes(8);
else if(flags&0x10)str=(void*)Event_GetCmdFlagRes(0x10);
else str=0;
if(str)GActor_RequestRes(str);
if(!(*(u32*)(battle+0xCAC)&0x100)){
switch(ep->code){
case 0x50:case 0x51:if(!(ep->flags&0x20000))fn_8004FC70(arg_save,9);break;
case 0x52:fn_8004FC70(arg_save,7);break;
}
}
}
}
#pragma cplusplus reset
#pragma global_optimizer reset
/* Load model/gfx (mode 8) for the units stored in event slots 0-2. */
void Event_LoadSlotUnitGfx(void) {
    void fn_8017F9A8(void);
    void fn_8004FC70(u32, s32);
    extern u8 gEventSlots[];
    u32 unit0;
    u32 unit1;
    u32 unit2;
    void *slot;

    fn_8017F9A8();
    slot = *(void **)gEventSlots;
    if (slot != NULL) {
        unit0 = *(u32 *)((u8 *)slot + 0x280);
    } else {
        unit0 = 0U;
    }
    slot = *(void **)(gEventSlots + 0x14);
    if (slot != NULL) {
        unit1 = *(u32 *)((u8 *)slot + 0x280);
    } else {
        unit1 = 0U;
    }
    slot = *(void **)(gEventSlots + 0x28);
    if (slot != NULL) {
        unit2 = *(u32 *)((u8 *)slot + 0x280);
    } else {
        unit2 = 0U;
    }
    if (unit0 != 0U) {
        fn_8004FC70(unit0, 8);
    }
    if (unit1 != 0U) {
        fn_8004FC70(unit1, 8);
    }
    if (unit2 != 0U) {
        fn_8004FC70(unit2, 8);
    }
}

s32 fn_80096B80(void) {
 extern u8 gBattle[]; void fn_800340E4(void *);
 s32 saved; s32 result; s16 *idx;
 result=0;
 idx=(s16 *)(gBattle+0x8a0);
 saved=*idx;
 fn_800340E4(idx);
 for(;;) {
 s32 c=((u8 *)idx)[4+*idx*4];
 switch(c) {
 case 0x52: result=1; break;
 case 0: break;
 default: ++*idx; continue;
 }
 break;
 }
 *idx=saved;
 return result;
}

s32 fn_80096C18(void) {
    extern u8 gBattle[];
    extern u8 gEventSlots[];
    extern u8 *lbl_80367504;
    extern u8 *lbl_80367500;
    extern f32 lbl_803697BC;
    u8 *p[2];

    if (*(u32 *)(gBattle + 0xCAC) & 0x100) {
        p[0] = gEventSlots + 0x14;
    } else if (lbl_80367504 != NULL) {
        p[0] = lbl_80367504;
    } else {
        p[0] = lbl_80367500;
    }
    if (p[0] == NULL) return 0;
    return lbl_803697BC == *(f32 *)(p[0] + 0x10);
}

u8 fn_80096C78(s32 arg0)
{
  extern u8 gBattle[];
  s16 saved;
  s16 *idx;
  s32 count;
  count = 0;
  idx = (s16 *) (gBattle + 0x8A0);
  saved = *idx;
  *idx = (s16) arg0;
  (*idx)++;
  for (;;)
  {
    switch (((u8 *) idx)[((*idx) * 4) + 4])
    {
      case 0:
      case 0x20:
      case 0x21:
      case 0x22:
      case 0x24:
      case 0x37:
      case 0x38:
      case 0x39:
      case 0x3D:
      case 0x3F:
      case 0x40:
      case 0x41:
      case 0x42:
      case 0x48:
        goto done;
      case 0x50:
      case 0x51:
      case 0x52:
        ++count;
        break;
    }
    *idx += 1;
  }
  done:
  *idx = saved;
  return (u8) (count >= 2);
}

s32 fn_80096D64(void) {
extern void **lbl_80367500;
extern u8 gBattle[];
void *Item_GetFlagsPtr(void*);
u8 *unit=*lbl_80367500;
void *item;
if(!unit) item=0;
else {item=unit+0x28C;if(!*(u32*)item) item=0;}
if(item) {
if(*(u64*)Item_GetFlagsPtr(item)&2ULL) return 1;
if(*(u64*)Item_GetFlagsPtr(item)&0x800000000ULL) return 2;
if(*(u64*)Item_GetFlagsPtr(item)&0x8000000000ULL) return 1;
if(*(s32*)(gBattle+0xCA8)>1) {
if(*(u64*)Item_GetFlagsPtr(item)&0x40ULL) return 1;
if(*(u64*)Item_GetFlagsPtr(item)&0x4000000000ULL) return 3;
}
}
return 0;
}

s32 fn_80096EEC(s32 *arg0, u32 arg1) {
    s32 var_r5;

    var_r5 = 0;
    if (arg1 & 0x2000) {
        var_r5 = (arg0[var_r5] = 0x2000, 1);
    }
    if (arg1 & 0x4000) {
        arg0[var_r5] = 0x4000;
        var_r5 += 1;
    }
    if (arg1 & 0x800) {
        arg0[var_r5] = 0x800;
        var_r5 += 1;
    }
    if (arg1 & 0x8000) {
        arg0[var_r5] = 0x8000;
        var_r5 += 1;
    }
    if (arg1 & 0x10000) {
        arg0[var_r5] = 0x10000;
        var_r5 += 1;
    }
    if (arg1 & 0x1000) {
        arg0[var_r5] = 0x1000;
        var_r5 += 1;
    }
    if (arg1 & 0x200) {
        arg0[var_r5] = 0x200;
        var_r5 += 1;
    }
    if (arg1 & 0x100) {
        arg0[var_r5] = 0x100;
        var_r5 += 1;
    }
    if (arg1 & 0x400) {
        arg0[var_r5] = 0x400;
        var_r5 += 1;
    }
    if (arg1 & 2) {
        arg0[var_r5] = 2;
        var_r5 += 1;
    }
    if (arg1 & 0x04000000) {
        arg0[var_r5] = 0x04000000;
        var_r5 += 1;
    } else {
        if (arg1 & 0x10000000) {
            arg0[var_r5] = 0x10000000;
            var_r5 += 1;
        }
        if (arg1 & 0x20000000) {
            arg0[var_r5] = 0x20000000;
            var_r5 += 1;
        }
    }
    if (arg1 & 0x08000000) {
        arg0[var_r5] = 0x08000000;
        var_r5 += 1;
    }
    if (arg1 & 0x40000000) {
        arg0[var_r5] = 0x40000000;
        var_r5 += 1;
    }
    if (arg1 & 0x80000000) {
        arg0[var_r5] = (s32)0x80000000;
        var_r5 += 1;
    }
    if (arg1 & 0x02000000) {
        arg0[var_r5] = 0x02000000;
        var_r5 += 1;
    }
    if (arg1 & 0x01000000) {
        arg0[var_r5] = 0x01000000;
        var_r5 += 1;
    }
    if (arg1 & 0x800000) {
        arg0[var_r5] = 0x800000;
        var_r5 += 1;
    }
    return var_r5;
}

#pragma global_optimizer off
#pragma opt_strength_reduction off
s32 Event_GetCmdKind(s32 arg0)
{
    extern u8 gBattle[];
    u8 *base;
    s32 result;
    s16 *s;
    s16 saved;
    s16 next;

    base = gBattle;
    result = -1;
    s = (s16 *)(base + 0x8A0);
    next = (s16)arg0 + 1;
    saved = *s;
    *(s16 *)(base + 0x8A0) = arg0;
    *(s16 *)(base + 0x8A0) = next;
    for (;;) {
        s16 idx = *(volatile s16 *)s;
        s32 c = *((volatile u8 *)s + (idx << 2) + 4);
        switch (c) {
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x24:
            goto done;
        case 0x50:
        case 0x51:
        case 0x52:
            result = *((volatile u8 *)s + (idx << 2) + 4);
            goto done;
        case 0:
            *(volatile s16 *)s = *(volatile s16 *)s + 1;
            continue;
        default:
            goto restore;
        }
    }
restore:
    *s = saved;
done:
    return result;
}
#pragma opt_strength_reduction reset
#pragma global_optimizer reset
s32 fn_80097168(s32 arg0) {
 extern u8 gBattle[];
 s16 *s = (s16 *)(gBattle + 0x8A0);
 s32 count=0;
 s16 saved=*s;
 *s=arg0;
 *s=(s16)arg0+1;
 for (;;) {
 s32 c=((u8 *)s)[(*s << 2)+4];
 switch(c) {
 case 0: case 0x20: case 0x21: case 0x22: case 0x24: goto done;
 case 0x50: case 0x51: case 0x52: count++; break;
 default: break;
 }
 ++*s;
 }
done:
 *s=saved;
 return count;
}

#pragma cplusplus on
extern "C" u32 Event_GetCmdFlags(s32 arg0) {
 extern u8 gBattle[];
 void fn_800973F0(void *, s32);
 s16 saved;
 u8 *s;
 s32 flags;
 s=gBattle+0x8A0;
 flags=0;
 saved=*(s16 *)s;
 *(s16 *)s=arg0;
 *(s16 *)s=(s16)(*(s16 *)s)+1;
 for (;;) {
 switch(s[(*(s16 *)s * 4)+4]) {
 case 0: case 0x20: case 0x21: case 0x22: case 0x24:
 case 0x50: case 0x51: case 0x52: case 0x54: goto done;
 case 9: case 0x15:
 if ((s8)*(s16 *)(s+(*(s16 *)s*4)+6)==0) flags|=0x20000;
 break;
 default: fn_800973F0(&flags,s[(*(s16 *)s*4)+4]); break;
 }
 ++*(s16 *)s;
 }
done:
 *(s16 *)s=saved;
 if(flags & 0x10000004) {
 u8 found=Event_ScanPositiveArg(s,arg0);

 *(s16 *)s=saved;
 if(found) flags|=1;
 }
 return flags;
}
#pragma cplusplus reset
void fn_800973F0(void *arg0, s32 arg1) {
u32 *ptr = arg0;
if(arg1 < 0 || arg1 > 0x45) return;
switch(arg1) {
case 0: *ptr |= 0x8000000U; break;
case 1: *ptr |= 0x10000000U; break;
case 2: *ptr |= 0x20000000U; break;
case 3: *ptr |= 0x2000000U; break;
case 4: *ptr |= 0x4000000U; break;
case 5: *ptr |= 0x1000000U; break;
case 6: *ptr |= 0x80000000U; break;
case 7: *ptr |= 0x40000000U; break;
case 8: *ptr |= 0x400000U; break;
case 9: *ptr |= 0x800000U; break;
case 10: *ptr |= 0x80U; break;
case 11: *ptr |= 0x8U; break;
case 12: *ptr |= 0x10U; break;
case 13: *ptr |= 0x20U; break;
case 14: *ptr |= 0x2U; break;
case 15: *ptr |= 0x4U; break;
case 16: *ptr |= 0x40U; break;
case 17: *ptr |= 0x100U; break;
case 18: *ptr |= 0x200U; break;
case 19: *ptr |= 0x400U; break;
case 20: *ptr |= 0x4000U; break;
case 21: *ptr |= 0x2000U; break;
case 22: *ptr |= 0x8000U; break;
case 23: *ptr |= 0x10000U; break;
case 24: *ptr |= 0x800U; break;
case 25: *ptr |= 0x1000U; break;
case 26: *ptr |= 0x40000U; break;
}
}

#pragma opt_common_subs off
void Event_AdvanceCmd(s32 arg0) {
    extern u8 gBattle[];
    extern u8 gEventSlots[];
    extern f32 lbl_803697BC;
    extern f64 lbl_803697C8;
    s16 saved;
    s16 *idx;
    u8 *slots;
    s16 t;
    s32 c;
    s8 param;
    f32 sum;
    f32 lim;

    idx = (s16 *)(gBattle + 0x8A0);
    saved = *idx;
    if (arg0 >= 0) {
        *idx = arg0;
        for (;;) {
            t = *idx;
            slots = gEventSlots;
            *idx = t + 1;
            c = ((u8 *)idx)[*idx * 4 + 4];
            switch (c) {
            case 9: {
                u8 *es = gEventSlots;
                param = (s8)((s16 *)idx)[*idx * 2 + 3];
                sum = *(f32 *)(es + 0x10) + (f32)param;
                lim = *(f32 *)(es + 0x8);
                *(f32 *)(es + 0x10) = sum;
                *(f32 *)(es + 0xC) = (f32)param;
                if (sum > lim) {
                    *(f32 *)(es + 0x10) = lim;
                }
                if (*(f32 *)(es + 0x10) < lbl_803697BC) {
                    *(f32 *)(es + 0x10) = lbl_803697BC;
                }
                break;
            }
            case 0x15:
                param = (s8)((s16 *)idx)[*idx * 2 + 3];
                sum = *(f32 *)(slots + 0x24) + (f32)param;
                lim = *(f32 *)(slots + 0x1C);
                *(f32 *)(slots + 0x24) = sum;
                *(f32 *)(slots + 0x20) = (f32)param;
                if (sum > lim) {
                    *(f32 *)(slots + 0x24) = lim;
                }
                if (*(f32 *)(slots + 0x24) < lbl_803697BC) {
                    *(f32 *)(slots + 0x24) = lbl_803697BC;
                }
                break;
            case 0:
            case 0x50:
            case 0x51:
            case 0x52:
                goto done;
            }
            *idx = *idx + 1;
        }
    }
done:
    *idx = saved;
}
#pragma opt_common_subs reset
typedef struct {
    u8 pad[0x8A0];
    s16 value;
} lbl_80330EAC_t;

s16 fn_80097740(void) {
    extern s16 gBattle[];
    extern u8 gEventSlots[];
    extern void *lbl_80367500;
    extern void *lbl_80367504;
    s16 *idx;
    s16 n;
    s16 result;
    s32 c;
    void *p;
    void *t;
    u32 v;
    s32 init;

    idx = &gBattle[0x450];
    init = gBattle[0x450];
    if (init != 0) {
        *idx = init + 1;
    }
    for (;;) {
        n = *idx;
        c = ((u8 *)idx)[(n << 2) + 4];
        switch (c) {
        case 0x00:
        case 0x50:
        case 0x51:
        case 0x52:
            return result;
        case 0x54:
            result = n;
            break;
        case 0x20:
            p = (void *)gEventSlots;
            if (p != NULL) {
                t = *(void **)p;
                v = (t != NULL) ? M2C_FIELD(t, u32 *, 0x280) : 0;
                if (v != 0) {
                    lbl_80367500 = p;
                    goto h1;
                }
            }
            lbl_80367500 = NULL;
        h1:
            p = (void *)(gEventSlots + 0x14);
            if (p != NULL) {
                t = *(void **)p;
                v = (t != NULL) ? M2C_FIELD(t, u32 *, 0x280) : 0;
                if (v != 0) {
                    lbl_80367504 = p;
                    goto h2;
                }
            }
            lbl_80367504 = NULL;
        h2:
            result = *idx;
            break;
        case 0x21:
            p = (void *)(gEventSlots + 0x14);
            if (p != NULL) {
                t = *(void **)p;
                v = (t != NULL) ? M2C_FIELD(t, u32 *, 0x280) : 0;
                if (v != 0) {
                    lbl_80367500 = p;
                    goto h3;
                }
            }
            lbl_80367500 = NULL;
        h3:
            p = (void *)gEventSlots;
            if (p != NULL) {
                t = *(void **)p;
                v = (t != NULL) ? M2C_FIELD(t, u32 *, 0x280) : 0;
                if (v != 0) {
                    lbl_80367504 = p;
                    goto h4;
                }
            }
            lbl_80367504 = NULL;
        h4:
            result = *idx;
            break;
        case 0x22:
            p = (void *)(gEventSlots + 0x28);
            if (p != NULL) {
                t = *(void **)p;
                v = (t != NULL) ? M2C_FIELD(t, u32 *, 0x280) : 0;
                if (v != 0) {
                    lbl_80367500 = p;
                    goto h5;
                }
            }
            lbl_80367500 = NULL;
        h5:
            p = (void *)(gEventSlots + 0x14);
            if (p != NULL) {
                t = *(void **)p;
                v = (t != NULL) ? M2C_FIELD(t, u32 *, 0x280) : 0;
                if (v != 0) {
                    lbl_80367504 = p;
                    goto h6;
                }
            }
            lbl_80367504 = NULL;
        h6:
            result = *idx;
            break;
        case 0x24:
            result = n;
            break;
        }
        *idx = *idx + 1;
    }
}

void fn_80097970(void) {
    extern u16 gBattle[];
    fn_800340E4(&gBattle[0x8A0 / sizeof(u16)]);
}

void fn_8009799C(void) {
    extern u8 gEventSlots[];
    u8 *p = gEventSlots;
    s32 i;
    for (i = 0; i < 3; i++, p += 0x14) {
        void *u = *(void **)p;
        if (u != NULL) {
            void *t = *(void **)((u8 *)u + 0x280);
            if (t != NULL) *(s8 *)((u8 *)t + 0x16C) = -1;
        }
    }
}

void fn_800979FC(void) {
 s8 fn_8004ABD4(void *,s32);
 extern u8 gBattle[]; extern u8 gEventSlots[];
 u8 *it; u8 *tbl; s32 i; void *p; void *q; s32 ca8;
 for(i=0, it=gEventSlots, tbl=gBattle; i<3; i++) {
 p=*(void **)it;
 if(p!=NULL && *(u32 *)((u8 *)p+0x280)!=0) {
 if(p==NULL) q=NULL;
 else if(*(u32 *)(q=(u8 *)p+0x28C)==0) q=NULL;
 ca8=*(s32 *)(tbl+0xCA8);
 *(u8 *)((u8 *)*(void **)((u8 *)*(void **)it+0x280)+0x16C)=fn_8004ABD4(q,ca8<=1);
 }
 it+=0x14;
 }
}

void fn_80097AB4(void) {
extern u8 gEventSlots[],gBattle[];
extern void *lbl_80367500,*lbl_80367504;
extern f32 lbl_803697BC;
void fn_800340E4(void *);
u8 *base=gEventSlots;
u8 *second=base+20;
u8 *script=gBattle+0x8a0;
u8 *other;
s16 saved=*(s16 *)script;
M2C_FIELD(gEventSlots,void **,0)=0;M2C_FIELD(base,f32 *,4)=lbl_803697BC;M2C_FIELD(base,f32 *,8)=lbl_803697BC;M2C_FIELD(base,f32 *,12)=lbl_803697BC;M2C_FIELD(base,f32 *,16)=lbl_803697BC;M2C_FIELD(second,void **,0)=0;M2C_FIELD(base,f32 *,24)=lbl_803697BC;M2C_FIELD(base,f32 *,28)=lbl_803697BC;M2C_FIELD(base,f32 *,32)=lbl_803697BC;M2C_FIELD(base,f32 *,36)=lbl_803697BC;M2C_FIELD(base,void **,40)=0;M2C_FIELD(base,f32 *,44)=lbl_803697BC;M2C_FIELD(base,f32 *,48)=lbl_803697BC;M2C_FIELD(base,f32 *,52)=lbl_803697BC;M2C_FIELD(base,f32 *,56)=lbl_803697BC;M2C_FIELD(gEventSlots,void **,0)=gBattle+0;{ s32 value=0; fn_800340E4(script); other=gBattle+0x2e0;
for(;;) {
s32 offset=*(s16 *)script*4;
switch((s32)script[offset+4]) {
case 0: case 0x54: goto done00;
case 4: if(gBattle==M2C_FIELD(gEventSlots,void **,0)) value=(s8)((s16 *)script)[*(s16 *)script*2+3]; break;
case 16: if(other==M2C_FIELD(gEventSlots,void **,0)) value=(s8)((s16 *)script)[*(s16 *)script*2+3]; break;
}
++*(s16 *)script;
}
done00:
*(s16 *)script=saved;
M2C_FIELD(base,f32 *,4)=value;
}
{ s32 value=0; fn_800340E4(script); 
for(;;) {
s32 offset=*(s16 *)script*4;
switch((s32)script[offset+4]) {
case 0: case 0x54: goto done01;
case 3: if(gBattle==M2C_FIELD(gEventSlots,void **,0)) value=(s8)((s16 *)script)[*(s16 *)script*2+3]; break;
case 15: if(other==M2C_FIELD(gEventSlots,void **,0)) value=(s8)((s16 *)script)[*(s16 *)script*2+3]; break;
}
++*(s16 *)script;
}
done01:
*(s16 *)script=saved;
M2C_FIELD(base,f32 *,8)=value;
}
M2C_FIELD(base,f32 *,16)=M2C_FIELD(base,f32 *,4); M2C_FIELD(base,f32 *,12)=lbl_803697BC;M2C_FIELD(second,void **,0)=gBattle+736;{ s32 value=0; fn_800340E4(script); 
for(;;) {
s32 offset=*(s16 *)script*4;
switch((s32)script[offset+4]) {
case 0: case 0x54: goto done10;
case 4: if(gBattle==M2C_FIELD(second,void **,0)) value=(s8)((s16 *)script)[*(s16 *)script*2+3]; break;
case 16: if(other==M2C_FIELD(second,void **,0)) value=(s8)((s16 *)script)[*(s16 *)script*2+3]; break;
}
++*(s16 *)script;
}
done10:
*(s16 *)script=saved;
M2C_FIELD(base,f32 *,24)=value;
}
{ s32 value=0; fn_800340E4(script); 
for(;;) {
s32 offset=*(s16 *)script*4;
switch((s32)script[offset+4]) {
case 0: case 0x54: goto done11;
case 3: if(gBattle==M2C_FIELD(second,void **,0)) value=(s8)((s16 *)script)[*(s16 *)script*2+3]; break;
case 15: if(other==M2C_FIELD(second,void **,0)) value=(s8)((s16 *)script)[*(s16 *)script*2+3]; break;
}
++*(s16 *)script;
}
done11:
*(s16 *)script=saved;
M2C_FIELD(base,f32 *,28)=value;
}
M2C_FIELD(base,f32 *,36)=M2C_FIELD(base,f32 *,24); M2C_FIELD(base,f32 *,32)=lbl_803697BC;M2C_FIELD(base,void **,40)=gBattle+1472;{ s32 value=0; fn_800340E4(script); 
for(;;) {
s32 offset=*(s16 *)script*4;
switch((s32)script[offset+4]) {
case 0: case 0x54: goto done20;
case 4: if(gBattle==M2C_FIELD(base,void **,40)) value=(s8)((s16 *)script)[*(s16 *)script*2+3]; break;
case 16: if(other==M2C_FIELD(base,void **,40)) value=(s8)((s16 *)script)[*(s16 *)script*2+3]; break;
}
++*(s16 *)script;
}
done20:
*(s16 *)script=saved;
M2C_FIELD(base,f32 *,44)=value;
}
{ s32 value=0; fn_800340E4(script); 
for(;;) {
s32 offset=*(s16 *)script*4;
switch((s32)script[offset+4]) {
case 0: case 0x54: goto done21;
case 3: if(gBattle==M2C_FIELD(base,void **,40)) value=(s8)((s16 *)script)[*(s16 *)script*2+3]; break;
case 15: if(other==M2C_FIELD(base,void **,40)) value=(s8)((s16 *)script)[*(s16 *)script*2+3]; break;
}
++*(s16 *)script;
}
done21:
*(s16 *)script=saved;
M2C_FIELD(base,f32 *,48)=value;
}
M2C_FIELD(base,f32 *,56)=M2C_FIELD(base,f32 *,44); M2C_FIELD(base,f32 *,52)=lbl_803697BC;{void *p=gEventSlots; u32 valid;
if(p) {void *unit=*(void **)p; if(unit) valid=M2C_FIELD(unit,u32 *,0x280); else valid=0; if(valid) lbl_80367500=p; else lbl_80367500=0;} else lbl_80367500=0;
p=second;
if(p) {void *unit=*(void **)p; if(unit) valid=M2C_FIELD(unit,u32 *,0x280); else valid=0; if(valid) lbl_80367504=p; else lbl_80367504=0;} else lbl_80367504=0;
}
fn_800340E4(script);
}

s32 fn_80098094(void) {
    extern s32 lbl_80367500;
    return lbl_80367500;
}

void *fn_8009809C(void) {
    extern u8 gBattle[];
    extern char gEventSlots[];
    extern void *lbl_80367500;
    extern void *lbl_80367504;

    if ((*(u32 *)(gBattle + 0xCAC) & 0x100) != 0) {
        return gEventSlots + 0x14;
    }
    if (lbl_80367504 == NULL) {
        return lbl_80367500;
    }
    return lbl_80367504;
}

void *fn_800980D4(s32 arg0) {
    extern u16 gEventSlots[];
    return (u8 *)gEventSlots + arg0 * 0x14;
}

s32 Event_GetSlotUnit(s32 arg0)
{
    extern u8 gEventSlots[];
    void *p = *(void **)(gEventSlots + arg0 * 0x14);
    if (p != NULL) {
        return M2C_FIELD(p, s32 *, 0x280);
    }
    return 0;
}

s32 fn_80098110(void) {
    extern void **lbl_80367504;
    void *temp_r3;

    if ((void **) lbl_80367504 == NULL) {
        return 0;
    }
    temp_r3 = *lbl_80367504;
    if (temp_r3 != NULL) {
        return M2C_FIELD(temp_r3, s32 *, 0x280);
    }
    return 0;
}

s32 fn_80098140(void) {
    extern void **lbl_80367500;
    void *temp_r3;

    if ((void **) lbl_80367500 == NULL) {
        return 0;
    }
    temp_r3 = *lbl_80367500;
    if (temp_r3 != NULL) {
        return M2C_FIELD(temp_r3, s32 *, 0x280);
    }
    return 0;
}
