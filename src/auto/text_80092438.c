/* Functions from 0x8007C5E4 to 0x8009F0BC, found by decomp-toolkit. */
#include "common.h"
#include "global.h"
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

/* record returned by Unit_GetItemSlot; bit 6 of byte 5 is set/cleared by fn_800946F0 */
typedef struct {
    u32 unk0;
    u8 unk4;
    u8 unk5_bit7:1;
    u8 unk5_bit6:1;
    u8 unk5:6;
} Unk80037BD0;

extern u8 lbl_80289EB8[16];
extern u8 lbl_8026CFE8[72];

extern f32 lbl_803697E0;
extern f32 lbl_803697E4;

#pragma scheduling reset

/* If status 0x24-0x28 is set and the matching wpnExp slot is 0, set that slot to 1. */
void Unit_ApplyStatusWpnExp(void *unit) {
    u8 Status_Test(void *, s32);

    if (*(u8 *)((u8 *)unit + 0x20C) == 0 && Status_Test((u8 *)unit + 0x1BC, 0x24) != 0) {
        *(u8 *)((u8 *)unit + 0x20C) = 1;
    }
    if (*(u8 *)((u8 *)unit + 0x20D) == 0 && Status_Test((u8 *)unit + 0x1BC, 0x25) != 0) {
        *(u8 *)((u8 *)unit + 0x20D) = 1;
    }
    if (*(u8 *)((u8 *)unit + 0x20E) == 0 && Status_Test((u8 *)unit + 0x1BC, 0x26) != 0) {
        *(u8 *)((u8 *)unit + 0x20E) = 1;
    }
    if (*(u8 *)((u8 *)unit + 0x20F) == 0 && Status_Test((u8 *)unit + 0x1BC, 0x27) != 0) {
        *(u8 *)((u8 *)unit + 0x20F) = 1;
    }
    if (*(u8 *)((u8 *)unit + 0x213) == 0 && Status_Test((u8 *)unit + 0x1BC, 0x28) != 0) {
        *(u8 *)((u8 *)unit + 0x213) = 1;
    }
}

#pragma use_lmw_stmw on
s32 fn_80092528(void *arg0, s32 arg1) {
    u8 Status_Test(void *, s32);
    u8 WpnRank_GetNext(u8);
    u32 fn_8001CFA8(u8);
    void *self;
    s32 a1;
    u32 idx;
    u8 result;
    u8 result2;
    u32 a;
    u32 b;

    idx = (u8)arg1;
    self = arg0;
    a1 = arg1;
    result = ((u8 *)self)[idx + 0x20C];

    if (idx == 7) {
        if (Status_Test((u8 *)self + 0x1BC, 0x28) != 0) {
            goto clamp79;
        }
    }

    if ((*(u8 **)((u8 *)self + 0x18C))[idx + 0x2C] != 0) {
        goto block_default;
    }

    switch ((u8)a1) {
    case 0:
        if (Status_Test((u8 *)self + 0x1BC, 0x24) != 0) {
            goto block_default;
        }
        result = 0;
        goto done1;
    case 1:
        if (Status_Test((u8 *)self + 0x1BC, 0x25) != 0) {
            goto block_default;
        }
        result = 0;
        goto done1;
    case 2:
        if (Status_Test((u8 *)self + 0x1BC, 0x26) != 0) {
            goto block_default;
        }
        result = 0;
        goto done1;
    case 3:
        if (Status_Test((u8 *)self + 0x1BC, 0x27) != 0) {
            goto block_default;
        }
        result = 0;
        goto done1;
    case 7:
        if (Status_Test((u8 *)self + 0x1BC, 0x28) != 0) {
            goto block_default;
        }
        result = 0;
        goto done1;
    }

block_default:
    if (Status_Test((u8 *)self + 0x1BC, 2) == 0) {
        goto clamp79;
    }
    if (result > 0xFB) {
        result = 0xFB;
    }
    goto done1;

clamp79:
    if (result > 0x79) {
        result = 0x79;
    }
done1:
    result2 = WpnRank_GetNext(result);

    if ((u8)a1 == 7) {
        if (Status_Test((u8 *)self + 0x1BC, 0x28) != 0) {
            goto clamp79_2;
        }
    }

    if ((*(u8 **)((u8 *)self + 0x18C))[idx + 0x2C] != 0) {
        goto block_default2;
    }

    switch ((u8)a1) {
    case 0:
        if (Status_Test((u8 *)self + 0x1BC, 0x24) != 0) {
            goto block_default2;
        }
        result2 = 0;
        goto done2;
    case 1:
        if (Status_Test((u8 *)self + 0x1BC, 0x25) != 0) {
            goto block_default2;
        }
        result2 = 0;
        goto done2;
    case 2:
        if (Status_Test((u8 *)self + 0x1BC, 0x26) != 0) {
            goto block_default2;
        }
        result2 = 0;
        goto done2;
    case 3:
        if (Status_Test((u8 *)self + 0x1BC, 0x27) != 0) {
            goto block_default2;
        }
        result2 = 0;
        goto done2;
    case 7:
        if (Status_Test((u8 *)self + 0x1BC, 0x28) != 0) {
            goto block_default2;
        }
        result2 = 0;
        goto done2;
    }

block_default2:
    if (Status_Test((u8 *)self + 0x1BC, 2) == 0) {
        goto clamp79_2;
    }
    if ((u8)result2 > 0xFB) {
        result2 = 0xFB;
    }
    goto done2;

clamp79_2:
    if ((u8)result2 > 0x79) {
        result2 = 0x79;
    }
done2:
    ((u8 *)self + 0x20C)[idx] = (u8)result2;
    a = fn_8001CFA8(result);
    b = fn_8001CFA8(result2);
    return (u8)a != (u8)b;
}
s32 Unit_AddWpnExp(void *arg0, void *arg1) {
    u8 Status_Test(void *, s32);
    s8 fn_8001CBA0(void *);
    u32 fn_8001CFA8(u8);
    s32 other;
    s32 result;
    void *self;
    u32 idx;
    s32 kept;

    kept = 0;
    self = arg0;
    other = (s32)arg1;
    idx = *((u8 *)other + 0x12);
    result = ((u8 *)self)[idx + 0x20C];

    if (idx != 7) {
        goto after_first7;
    }
    if (Status_Test((u8 *)self + 0x1BC, 0x28) != 0) {
        goto clamp79;
    }
after_first7:
    if ((*(u8 **)((u8 *)self + 0x18C))[idx + 0x2C] != 0) {
        goto block_default;
    }

    switch ((s32)idx) {
    case 0:
        if (Status_Test((u8 *)self + 0x1BC, 0x24) != 0) {
            goto block_default;
        }
        result = 0;
        goto done1;
    case 1:
        if (Status_Test((u8 *)self + 0x1BC, 0x25) != 0) {
            goto block_default;
        }
        result = 0;
        goto done1;
    case 2:
        if (Status_Test((u8 *)self + 0x1BC, 0x26) != 0) {
            goto block_default;
        }
        result = 0;
        goto done1;
    case 3:
        if (Status_Test((u8 *)self + 0x1BC, 0x27) != 0) {
            goto block_default;
        }
        result = 0;
        goto done1;
    case 7:
        if (Status_Test((u8 *)self + 0x1BC, 0x28) != 0) {
            goto block_default;
        }
        result = 0;
        goto done1;
    }

block_default:
    if (Status_Test((u8 *)self + 0x1BC, 2) == 0) {
        goto clamp79;
    }
    if ((u8)result > 0xFB) {
        result = 0xFB;
    }
    goto done1;

clamp79:
    if ((u8)result > 0x79) {
        result = 0x79;
    }
done1:
    kept = (u8)result;
    if (kept >= 0xFB) {
        return 0;
    }
    {
        s32 t = kept + *((u8 *)other + 0x17);
        if (t > 0xFB) {
            t = 0xFB;
        }
        result = (u8)t;
    }

    if (idx != 7) {
        goto after_second7;
    }
    if (Status_Test((u8 *)self + 0x1BC, 0x28) != 0) {
        goto clamp79_2;
    }
after_second7:
    if ((*(u8 **)((u8 *)self + 0x18C))[idx + 0x2C] != 0) {
        goto block_default2;
    }

    switch ((s32)idx) {
    case 0:
        if (Status_Test((u8 *)self + 0x1BC, 0x24) != 0) {
            goto block_default2;
        }
        result = 0;
        goto done2;
    case 1:
        if (Status_Test((u8 *)self + 0x1BC, 0x25) != 0) {
            goto block_default2;
        }
        result = 0;
        goto done2;
    case 2:
        if (Status_Test((u8 *)self + 0x1BC, 0x26) != 0) {
            goto block_default2;
        }
        result = 0;
        goto done2;
    case 3:
        if (Status_Test((u8 *)self + 0x1BC, 0x27) != 0) {
            goto block_default2;
        }
        result = 0;
        goto done2;
    case 7:
        if (Status_Test((u8 *)self + 0x1BC, 0x28) != 0) {
            goto block_default2;
        }
        result = 0;
        goto done2;
    }

block_default2:
    if (Status_Test((u8 *)self + 0x1BC, 2) == 0) {
        goto clamp79_2;
    }
    if ((u8)result > 0xFB) {
        result = 0xFB;
    }
    goto done2;

clamp79_2:
    if ((u8)result > 0x79) {
        result = 0x79;
    }
done2:
    other = (u8)result;
    if (other >= 0xFB) {
        if (fn_8001CBA0((u8 *)self + 0x20C) >= 0) {
            return 0;
        }
    }
    ((u8 *)self + 0x20C)[idx] = (u8)other;
    {
        u32 a = fn_8001CFA8((u8)kept);
        return (u8)a != (u8)fn_8001CFA8((u8)other);
    }
}
#pragma optimization_level 3
u8 Unit_GetWpnExp(void *arg0, s32 arg1) {
    u8 Status_Test(void *, s32);
    void *self;
    s32 a1;
    u32 idx;
    u8 result;

    self = arg0;
    a1 = arg1;
    idx = (u8)arg1;
    result = ((u8 *)self)[idx + 0x20C];

    if (idx == 7) {
        if (Status_Test((u8 *)self + 0x1BC, 0x28) != 0) {
            goto clamp79;
        }
    }

    if ((*(u8 **)((u8 *)self + 0x18C))[idx + 0x2C] != 0) {
        goto block_default;
    }

    switch ((u8)a1) {
    case 0:
        if (Status_Test((u8 *)self + 0x1BC, 0x24) != 0) goto block_default;
        result = 0;
        goto done;
    case 1:
        if (Status_Test((u8 *)self + 0x1BC, 0x25) != 0) goto block_default;
        result = 0;
        goto done;
    case 2:
        if (Status_Test((u8 *)self + 0x1BC, 0x26) != 0) goto block_default;
        result = 0;
        goto done;
    case 3:
        if (Status_Test((u8 *)self + 0x1BC, 0x27) != 0) goto block_default;
        result = 0;
        goto done;
    case 7:
        if (Status_Test((u8 *)self + 0x1BC, 0x28) != 0) goto block_default;
        result = 0;
        goto done;
    }

block_default:
    if (Status_Test((u8 *)self + 0x1BC, 2) == 0) {
        goto clamp79;
    }
    if (result > 0xFB) {
        result = 0xFB;
    }
    goto done;

clamp79:
    if (result > 0x79) {
        result = 0x79;
    }
done:
    return result;
}
#pragma optimization_level reset
u8 fn_80092C50(void *arg0, u8 arg1, u8 arg2) {
    u8 Status_Test(void *, s32);
    if (arg1==7 && Status_Test((u8 *)arg0+0x1BC,0x28)) goto clamp;
    if ((*(u8 **)((u8 *)arg0+0x18C))[arg1+0x2C]==0) {
        switch(arg1) {
        case 0: if(!Status_Test((u8 *)arg0+0x1BC,0x24)) return 0; break;
        case 1: if(!Status_Test((u8 *)arg0+0x1BC,0x25)) return 0; break;
        case 2: if(!Status_Test((u8 *)arg0+0x1BC,0x26)) return 0; break;
        case 3: if(!Status_Test((u8 *)arg0+0x1BC,0x27)) return 0; break;
        case 7: if(!Status_Test((u8 *)arg0+0x1BC,0x28)) return 0; break;
        }
    }
    if(Status_Test((u8 *)arg0+0x1BC,2)) {
        if(arg2>0xFB) arg2=0xFB;
        return arg2;
    }
clamp:
    if(arg2>0x79) arg2=0x79;
    return arg2;
}

s32 fn_80092DC4(void *arg0, u16 *arg1) {
    u8 Status_Test(void *, s32);
    void *fn_80037C20(void *);
    u64 *Item_GetFlagsPtr(void *);
    u16 flags;
    void *item;
    if ((*arg1 & 0x800) && Status_Test((u8 *)arg0+0x1BC,6)) return 1;
    if ((*arg1 & 0x200) && Status_Test((u8 *)arg0+0x1BC,7)) return 1;
    flags=*arg1;
    item=fn_80037C20(arg0);
    if(item && (*Item_GetFlagsPtr(item)&0x40000ULL)) return 0;
    if(item && (*Item_GetFlagsPtr(item)&0x8000ULL)) flags &= ~2;
    if(item && (*Item_GetFlagsPtr(item)&0x10000ULL)) flags &= ~0x10;
    return (*(u16 *)(*(u8 **)((u8 *)arg0+0x18C)+0x3A)&flags)!=0;
}

#pragma opt_peephole off
u8 fn_80092F38(void *arg0) {
u8 count=0;
s32 i;
for(i=0;i<4;i++) {
if (*(u32*)((u8*)arg0+0x1ec+i*8) != 0) count=(u8)count+1;
}
return count;
}
#pragma opt_peephole reset
u8 fn_80092F9C(void *arg0)
{
  extern void *Unit_GetHeldItemSlot(void *, s32);
  unsigned long new_var;
  u8 count;
  s32 i;
  count = 0;
  for (i = 0; i < 4; i++)
  {
    if ((*((u32 *) Unit_GetHeldItemSlot(arg0, i))) != 0)
    {
      new_var = 1;
      if (new_var)
      {
        count = (u8) (count + new_var);
      }
    }
  }

  return count;
}

s32 fn_80093010(void *arg0, void *arg1)
{
    extern void *Unit_GetItemSlot(void *, s32);

    s32 i;
    void *value;

    for (i = 0; i < 8; i++) {
        value = *(void **)Unit_GetItemSlot(arg0, i);

        if (value != 0 && value == arg1) {
            return i;
        }
    }

    return -1;
}

void *Unit_GetHeldItemSlot(void *, s32);
static inline s32 fn_80093088_FindEmptyHeld(void *unit) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (*(u32 *)Unit_GetHeldItemSlot(unit, i) == 0) return i;
    }
    return -1;
}

s32 fn_80093088(void *arg0) {
    s32 i;
    s32 r;
    u8 ok;

    i = fn_80093088_FindEmptyHeld(arg0);
    r = i == 0;
    ok = r;
    if (ok) {
        if (*(u32 *)((u8 *)arg0 + 0x1ec) == 0) i = 0;
        else if (*(u32 *)((u8 *)arg0 + 0x1f4) == 0) i = 1;
        else if (*(u32 *)((u8 *)arg0 + 0x1fc) == 0) i = 2;
        else if (*(u32 *)((u8 *)arg0 + 0x204) == 0) i = 3;
        else i = -1;
        r = i == 0;
    }
    return r;
}

void Unit_SetHeldItem(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK Item_Copy(s32, s32);
    s32 self = arg0;

    if ((u8)arg1 < 4) {
        Item_Copy(self + (((u8)arg1) << 3) + 0x1CC, arg2);
    } else {
        Item_Copy(self + (((u8)(arg1 - 4)) << 3) + 0x1EC, arg2);
    }
}

void fn_800931B0(s32 arg0, u8 arg1, s32 arg2) {
    M2C_UNK Item_Copy(s32, s32);
    Item_Copy(arg0 + (arg1 << 3) + 0x1EC, arg2);
}

void fn_800931E4(s32 arg0, u8 arg1, s32 arg2) {
    Item_Copy(arg0 + (arg1 << 3) + 0x1CC, arg2);
}

s32 fn_80093218(void *arg0, void *arg1) {
 u64 flags = *(u64 *)((u8 *)arg1 + 0x38);
 if ((flags & 8ULL) == 0) return 0;
 return (flags & 0x10000000000ULL) == 0;
}

u8 fn_8009326C(void *arg0, void *arg1) {
    u8 fn_800940B0(void *, void *);
    u8 tmp;
    struct { unsigned ok : 8; } t;
    u32 lo;
    u32 hi;
    u32 z;
    u64 flags;

    t.ok = 0;
    lo = *(u32 *)((u8 *)arg1 + 0x3C);
    hi = *(u32 *)((u8 *)arg1 + 0x38);
    z = 0;
    flags = ((u64)hi << 32) | lo;
    if (!(flags & 4)) {
        return (u8)z;
    }
    if (flags & 0x200) {
        tmp = Status_Test((u8 *)arg0 + 0x1BC, 9);
        if (tmp) {
            t.ok = 1;
        } else {
            t.ok = (u8)z;
        }
    } else if (((*(u8 *)((u8 *)arg0 + 0x1A5) >> 4) & 7) == 0) {
        t.ok = 1;
    } else if (flags & 2) {
        t.ok = (u8)z;
    } else if (flags & 4) {
        t.ok = (u8)z;
    } else if (flags & 0x40) {
        t.ok = 1;
    } else {
        t.ok = 1;
    }
    if (t.ok == 0) {
        return (u8)z;
    }
    return fn_800940B0(arg0, arg1) != 0;
}

#pragma optimization_level 2
s32 fn_8009339C(void *arg0,void *arg1) {
u8 fn_800940B0(void*,void*);
u8 Status_Test(void*,s32);
u8 allowed=1;
u64 flags;
flags=*(u64*)((u8*)arg1+0x38);
if((flags&1)==0) return 0;
if(flags&0x200) {
if(Status_Test((u8*)arg0+0x1BC,9)!=0) allowed=1;
else allowed=0;
} else if((((u8*)arg0)[0x1A5]>>4&7)!=0) {
if(flags&2) allowed=0;
else if(flags&4) allowed=0;
else if(flags&0x40) allowed=1;
}
if(allowed==0) return 0;
return fn_800940B0(arg0,arg1)!=0;
}
#pragma optimization_level reset
u8 fn_800934CC(void *arg0, void *arg1) {
    u8 fn_800940B0(void *, void *);
    u8 Status_Test(void *, s32);
    u8 ok;
    u32 lo;
    u8 result;
    u32 hi;
    u64 flags;

    ok = 1;
    lo = *(u32 *)((u8 *)arg1 + 0x3C);
    result = 0;
    hi = *(u32 *)((u8 *)arg1 + 0x38) & result;
    flags = ((u64)hi << 32) | lo;

    if (flags & 1) {
        if (!(flags & 1)) {
        } else {
            if (flags & 0x200) {
                if (Status_Test((u8 *)arg0 + 0x1BC, 9) != 0) {
                    ok = 1;
                } else {
                    ok = 0;
                }
            } else if (((*(u8 *)((u8 *)arg0 + 0x1A5) >> 4) & 7) == 0) {
            } else if (flags & 2) {
                ok = result;
            } else if (flags & 4) {
                ok = result;
                          } else if (flags & 0x40) {
              }
                              if (ok == 0) {
                    result = 0;
                } else {
                    result = fn_800940B0(arg0, arg1) != 0;
                }
            }
            return result;
        }
        if (flags & 4) {
          if (!(flags & 4)) {
          } else {
              if (flags & 0x200) {
                  if (Status_Test((u8 *)arg0 + 0x1BC, 9) != 0) {
                      ok = 1;
                  } else {
                      ok = 0;
                  }
              } else if (((*(u8 *)((u8 *)arg0 + 0x1A5) >> 4) & 7) == 0) {
              } else if (flags & 2) {
                  ok = result;
              } else if (flags & 4) {
                  ok = result;
              } else if (flags & 0x40) {
              }
                              if (ok == 0) {
                    result = 0;
                } else {
                    result = fn_800940B0(arg0, arg1) != 0;
                }
            }
            return result;
        }
        return 0;
  }
  
  u8 fn_80093708(void *arg0, void *arg1) {
          u8 fn_800940B0(void *, void *);
      u8 Status_Test(void *, s32);
      struct { unsigned ok : 8; unsigned result : 8; } t;
      u64 flags;
      u64 flags2;
      u8 tmp;
      u32 m;
  
      t.result = 0;
      flags = *(u64 *)((u8 *)arg1 + 0x38);
      flags2 = flags;
      m = 5;
  
      if (flags & m) {
          t.ok = 1;
          if (flags & 1) {
              if (!(flags2 & 1)) {
              } else {
                  if (flags & 0x200) {
                      if (Status_Test((u8 *)arg0 + 0x1BC, 9) != 0) {
                          t.ok = 1;
                      } else {
                          t.ok = 0;
                      }
                  } else if (((*(u8 *)((u8 *)arg0 + 0x1A5) >> 4) & 7) == 0) {
                  } else if (flags & 2) {
                      t.ok = t.result;
                  } else if (flags & 4) {
                      t.ok = t.result;
                  } else if (flags & 0x40) {
                      t.ok = 1;
                  }
                  if (t.ok == 0) {
                      t.result = 0;
                  } else {
                      t.result = fn_800940B0(arg0, arg1) != 0;
                  }
              }
          } else {
              if (flags & 4) {
                  if (!(flags2 & 4)) {
                  } else {
                      if (flags & 0x200) {
                          if (Status_Test((u8 *)arg0 + 0x1BC, 9) != 0) {
                              t.ok = 1;
                          } else {
                              t.ok = 0;
                          }
                      } else if (((*(u8 *)((u8 *)arg0 + 0x1A5) >> 4) & 7) == 0) {
                      } else if (flags & 2) {
                          t.ok = t.result;
                      } else if (flags & 4) {
                          t.ok = t.result;
                      } else if (flags & 0x40) {
                          t.ok = 1;
                      }
                      if (t.ok == 0) {
                          t.result = 0;
                      } else {
                          t.result = fn_800940B0(arg0, arg1) != 0;
                      }
                  }
              }
          }
          return t.result;
      }
    if (flags & 0x18) {
        if (flags & 8) {
            if (!(flags2 & 8)) {
            } else if (flags & ((u64)0x100 << 32)) {
            } else {
                t.result = 1;
            }
        } else {
            if (flags & 0x10) {
                if (!(flags2 & 0x10)) {
                    tmp = t.result;
                } else {
                    tmp = fn_800940B0(arg0, arg1);
                }
                t.result = tmp;
            }
        }
        return t.result;
    }
    return 0;
}

u8 fn_800939FC(void *arg0, void *arg1) {
    s32 Game_GetState(void);
    u8 Item_CallUfx(void *, void *);
    void *Item_GetUfx(void *);
    u8 fn_800940B0(void *, void *);
    u8 Status_Test(void *, s32);
    struct { unsigned ok : 8; unsigned result : 8; } t;
    u32 lo;
    u32 hi;
    u64 flags;
    u64 bit;
    u8 tmp;
    void *rec;
    u8 var_r0;

    t.result = 0;
    lo = *(u32 *)((u8 *)arg1 + 0x3C);
    hi = *(u32 *)((u8 *)arg1 + 0x38);
    flags = (u64)lo | ((u64)hi << 32);

    bit = flags & 8;
    if (bit) {
        if (Game_GetState() == 0x10) {
            rec = Item_GetUfx(arg1);
            if (rec == NULL) {
                var_r0 = 0;
            } else if (*(u32 *)rec == 0) {
                var_r0 = 0;
            } else {
                var_r0 = *((u8 *)rec + 4);
            }
            if (var_r0 == 0) {
                return 0;
            }
            return Item_CallUfx(arg0, arg1);
        }
        rec = Item_GetUfx(arg1);
        if (rec == NULL) {
            var_r0 = 0;
        } else if (*(u32 *)rec == 0) {
            var_r0 = 0;
        } else {
            var_r0 = *((u8 *)rec + 5);
        }
        if (var_r0 == 0) {
            return 0;
        }
        return Item_CallUfx(arg0, arg1);
    }
    if (flags & 5) {
        t.ok = 1;
                  bit = flags & 1;
          if (bit) {
              if (!bit) {
              } else {
                  if (flags & 0x200) {
                      if (Status_Test((u8 *)arg0 + 0x1BC, 9) != 0) {
                          t.ok = 1;
                      } else {
                          t.ok = 0;
                      }
                  } else if (((*(u8 *)((u8 *)arg0 + 0x1A5) >> 4) & 7) == 0) {
                  } else if (flags & 2) {
                      t.ok = t.result;
                  } else if (flags & 4) {
                      t.ok = t.result;
                  } else if (flags & 0x40) {
                      t.ok = 1;
                  }
                  if (t.ok == 0) {
                      t.result = 0;
                  } else {
                      t.result = fn_800940B0(arg0, arg1) != 0;
                  }
              }
          } else {
              bit = flags & 4;
              if (bit) {
                  if (!bit) {
                  } else {
                      if (flags & 0x200) {
                          if (Status_Test((u8 *)arg0 + 0x1BC, 9) != 0) {
                              t.ok = 1;
                          } else {
                              t.ok = 0;
                          }
                      } else if (((*(u8 *)((u8 *)arg0 + 0x1A5) >> 4) & 7) == 0) {
                      } else if (flags & 2) {
                          t.ok = t.result;
                      } else if (flags & 4) {
                          t.ok = t.result;
                      } else if (flags & 0x40) {
                          t.ok = 1;
                      }
                      if (t.ok == 0) {
                          t.result = 0;
                      } else {
                          t.result = fn_800940B0(arg0, arg1) != 0;
                      }
                  }
              }
          }
          return t.result;
      }
      if (flags & 0x18) {
          bit = flags & 8;
        if (bit) {
            if (!bit) {
            } else if (flags & ((u64)0x100 << 32)) {
            } else {
                t.result = 1;
            }
        } else {
            bit = flags & 0x10;
            if (bit) {
                if (!bit) {
                    tmp = t.result;
                } else {
                    tmp = fn_800940B0(arg0, arg1);
                }
                t.result = tmp;
            }
        }
        return t.result;
    }
    return 0;
}

u8 fn_80093DA8(void *arg0, void *arg1) {
      u8 fn_800940B0(void *, void *);
      u8 Status_Test(void *, s32);
      struct { unsigned ok : 8; unsigned result : 8; } t;
      u32 *p;
      u32 lo;
      u32 hi;
      u64 flags;
      u64 flags2;
      u8 tmp;
      u32 m;
  
      t.result = 0;
      p = (u32 *)((u8 *)arg1 + 0x38);
      lo = p[1];
      hi = p[0];
      flags = ((u64)hi << 32) | lo;
      flags2 = flags;
      m = 8;
  
      if (flags & m) {
          return 1;
      }
      m = 5;
      if (flags & m) {
          t.ok = 1;
          if (flags & 1) {
              if (!(flags2 & 1)) {
              } else {
                  if (flags & 0x200) {
                      if (Status_Test((u8 *)arg0 + 0x1BC, 9) != 0) {
                          t.ok = 1;
                      } else {
                          t.ok = 0;
                      }
                  } else if (((*(u8 *)((u8 *)arg0 + 0x1A5) >> 4) & 7) == 0) {
                  } else if (flags & 2) {
                      t.ok = t.result;
                  } else if (flags & 4) {
                      t.ok = t.result;
                  } else if (flags & 0x40) {
                      t.ok = 1;
                  }
                  if (t.ok == 0) {
                      t.result = 0;
                  } else {
                      t.result = fn_800940B0(arg0, arg1) != 0;
                  }
              }
          } else {
              if (flags & 4) {
                  if (!(flags2 & 4)) {
                  } else {
                      if (flags & 0x200) {
                          if (Status_Test((u8 *)arg0 + 0x1BC, 9) != 0) {
                              t.ok = 1;
                          } else {
                              t.ok = 0;
                          }
                      } else if (((*(u8 *)((u8 *)arg0 + 0x1A5) >> 4) & 7) == 0) {
                      } else if (flags & 2) {
                          t.ok = t.result;
                      } else if (flags & 4) {
                          t.ok = t.result;
                      } else if (flags & 0x40) {
                          t.ok = 1;
                      }
                      if (t.ok == 0) {
                          t.result = 0;
                      } else {
                          t.result = fn_800940B0(arg0, arg1) != 0;
                      }
                  }
              }
        }
        return t.result;
    }
    if (flags & 0x18) {
        if (flags & 8) {
            if (!(flags2 & 8)) {
            } else if (flags & ((u64)0x100 << 32)) {
            } else {
                t.result = 1;
            }
        } else {
            if (flags & 0x10) {
                if (!(flags2 & 0x10)) {
                    tmp = t.result;
                } else {
                    tmp = fn_800940B0(arg0, arg1);
                }
                t.result = tmp;
            }
        }
        return t.result;
    }
    return 0;
}

u8 fn_800940B0(void *arg0, void *arg1) {
    u8 Status_Test(void *, s32);
    void *Job_GetByJid(void *);

    void *other;
    void *self;
    u8 type;
    u8 result;
    u8 lim;
    void *unit;

    other = arg1;
    self = arg0;

    if (!(*(u64 *)((u8 *)other + 0x38) & 4)) {
        if (*(u64 *)((u8 *)other + 0x38) & 0x7FF80000) {
            if (*(u64 *)((u8 *)other + 0x38) & 0x200000) {
                if (Status_Test((u8 *)self + 0x1BC, 0) == 0) {
                    return 0;
                }
            }
            if (*(u64 *)((u8 *)other + 0x38) & 0x400000) {
                unit = *(void **)((u8 *)self + 0x18C);
                if ((*(u16 *)((u8 *)unit + 0x3A) & 0x20) == 0) {
                    return 0;
                }
            }
            if (*(u64 *)((u8 *)other + 0x38) & 0x800000) {
                if (Status_Test((u8 *)self + 0x1BC, 8) == 0) {
                    return 0;
                }
            }
            if (*(u64 *)((u8 *)other + 0x38) & 0x1000000) {
                unit = *(void **)((u8 *)self + 0x18C);
                if ((*(u16 *)((u8 *)unit + 0x3A) & 4) == 0) {
                    return 0;
                }
            }
            if (*(u64 *)((u8 *)other + 0x38) & 0x2000000) {
                if (Status_Test((u8 *)self + 0x1BC, 0x4F) == 0) {
                    return 0;
                }
            }
            if (*(u64 *)((u8 *)other + 0x38) & 0x4000000) {
                if (Status_Test((u8 *)self + 0x1BC, 0x56) == 0) {
                    return 0;
                }
            }
            if (*(u64 *)((u8 *)other + 0x38) & 0x8000000) {
                if (Status_Test((u8 *)self + 0x1BC, 0x57) == 0) {
                    return 0;
                }
            }
            if (*(u64 *)((u8 *)other + 0x38) & 0x10000000) {
                if (Status_Test((u8 *)self + 0x1BC, 0x58) == 0) {
                    return 0;
                }
            }
            if (*(u64 *)((u8 *)other + 0x38) & 0x20000000) {
                if (Status_Test((u8 *)self + 0x1BC, 0x5D) == 0) {
                    return 0;
                }
            }
            if (*(u64 *)((u8 *)other + 0x38) & 0x40000000) {
                if (Status_Test((u8 *)self + 0x1BC, 0x5E) != 0) {
                    return 0;
                }
            }
            if (*(u64 *)((u8 *)other + 0x38) & 0x80000) {
                if (Status_Test((u8 *)self + 0x1BC, 7) == 0) {
                    return 0;
                }
            }
            if (*(u64 *)((u8 *)other + 0x38) & 0x100000) {
                unit = *(void **)((u8 *)self + 0x18C);
                if (unit != Job_GetByJid(lbl_8026CFE8 + 0x39)) {
                    return 0;
                }
            }
        }
        type = *((u8 *)other + 0x12);
        switch (type) {
        case 8:
            return Status_Test((u8 *)self + 0x1BC, 0x22);
        case 9:
            return Status_Test((u8 *)self + 0x1BC, 9);
        case 7:
            if (Status_Test((u8 *)self + 0x1BC, 0x23) == 0) {
                return 0;
            }
            break;
        case 11:
            return 1;
        case 10:
            return 0;
        }
    }

    type = *((u8 *)other + 0x12);
    result = ((u8 *)self)[type + 0x20C];

    if (type == 7) {
        if (Status_Test((u8 *)self + 0x1BC, 0x28) != 0) {
            goto clamp79;
        }
    }

    if ((*(u8 **)((u8 *)self + 0x18C))[type + 0x2C] != 0) {
        goto block_default;
    }

    switch (type) {
    case 0:
        if (Status_Test((u8 *)self + 0x1BC, 0x24) != 0) {
            goto block_default;
        }
        result = 0;
        goto done;
    case 1:
        if (Status_Test((u8 *)self + 0x1BC, 0x25) != 0) {
            goto block_default;
        }
        result = 0;
        goto done;
    case 2:
        if (Status_Test((u8 *)self + 0x1BC, 0x26) != 0) {
            goto block_default;
        }
        result = 0;
        goto done;
    case 3:
        if (Status_Test((u8 *)self + 0x1BC, 0x27) != 0) {
            goto block_default;
        }
        result = 0;
        goto done;
    case 7:
        if (Status_Test((u8 *)self + 0x1BC, 0x28) != 0) {
            goto block_default;
        }
        result = 0;
        goto done;
    }

block_default:
    if (Status_Test((u8 *)self + 0x1BC, 2) == 0) {
        goto clamp79;
    }
    if (result > 0xFB) {
        result = 0xFB;
    }
    goto done;

clamp79:
    if (result > 0x79) {
        result = 0x79;
    }
done:
    lim = *((u8 *)other + 0x16);
    lim = (u8)(lim + (lim == 0));
    return (u8)(lim < result);
}

/* True if unit may equip itemData: flag 0x200 needs status 9; else allow when +0x1A5 high nibble is 0, deny on flags 2/4, else allow. */
s32 Unit_CanEquipItem(void *unit, void *itemData) {
    u8 Status_Test(void *, s32);
    u64 flags;

    flags = *(u64 *)((u8 *)itemData + 0x38);
    if (flags & 0x200) {
        return (u8)Status_Test((u8 *)unit + 0x1BC, 9) != 0;
    }
    if (((*(u8 *)((u8 *)unit + 0x1A5) >> 4) & 7) == 0) {
        return 1;
    }
    if (flags & 2) {
        return 0;
    }
    if (flags & 4) {
        return 0;
    }
    if (flags & 0x40) {
        return 1;
    }
    return 1;
}

void fn_800946F0(s32 arg0) {
    s32 r30;
    Unk80037BD0 *temp_r3;

    r30 = 0;
    do {
        temp_r3 = (Unk80037BD0 *)Unit_GetItemSlot(arg0, r30);
        if ((temp_r3 != NULL) && (temp_r3->unk0 != 0U)) {
            temp_r3->unk5_bit6 = 0;
        }
        r30 += 1;
    } while (r30 < 8);
}

s32 fn_80094768(void *arg0)
{
    extern void *Unit_GetItemSlot(void *, s32);

    s32 i;
    u8 *entry;

    for (i = 0; i < 8; i++) {
        entry = (u8 *)Unit_GetItemSlot(arg0, i);

        if (entry != 0) {
            if (*(u32 *)entry != 0) {
                if ((entry[5] >> 6) & 1) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

void Unit_CompactItems(s32 arg0) {
    void Item_Init(void *);
    void Item_Copy(void *, void *);
    void Item_Clear(void *);
    void Item_Destroy(void *, s32);
    void *Unit_GetHeldItemSlot(s32, s32);
#pragma cplusplus on
    struct TempItem {
        Unk80037BD0 item;
        TempItem() { Item_Init(this); }
        ~TempItem() { Item_Destroy(this, -1); }
    };
    Unk80037BD0 held[4];
    Unk80037BD0 spare[4];
    s32 i;
    s32 count;
    Item_Init(&held[0]); Item_Init(&held[1]); Item_Init(&held[2]); Item_Init(&held[3]);
    Item_Init(&spare[0]); Item_Init(&spare[1]); Item_Init(&spare[2]); Item_Init(&spare[3]);
    for (i = 0; i < 4; i++) {
        Item_Copy(&held[i], Unit_GetHeldItemSlot(arg0, i));
        Item_Clear(Unit_GetHeldItemSlot(arg0, i));
        Item_Copy(&spare[i], (u8 *)arg0 + 0x1EC + i * 8);
        Item_Clear((u8 *)arg0 + 0x1EC + i * 8);
    }
    i = 0;
    count = 0;
    for (; i < 4; i++) {
        if (held[i].unk0) {
            Item_Copy((u8 *)arg0 + 0x1CC + (u8)count++ * 8, &held[i]);
        }
    }
    i = 0;
    count = 0;
    for (; i < 4; i++) {
        if (spare[i].unk0) {
            Item_Copy((u8 *)arg0 + 0x1EC + (u8)count++ * 8, &spare[i]);
        }
    }
    Item_Destroy(&spare[3], -1); Item_Destroy(&spare[2], -1); Item_Destroy(&spare[1], -1); Item_Destroy(&spare[0], -1);
    Item_Destroy(&held[3], -1); Item_Destroy(&held[2], -1); Item_Destroy(&held[1], -1); Item_Destroy(&held[0], -1);
#pragma cplusplus reset
}

void Unit_RemoveItem(void *arg0, s8 arg1) {
    void *Unit_GetHeldItemSlot(void);
    void Item_Clear(void *);
    void Unit_CompactItems(void *);
    s32 t;

    if (arg1 < 4) {
        Item_Clear(Unit_GetHeldItemSlot());
        Unit_CompactItems(arg0);
        return;
    }
    t = (arg1 - 4) * 8;
    Item_Clear((u8 *)arg0 + t + 0x1EC);
    Unit_CompactItems(arg0);
}

s32 fn_80094A08(s32 arg0) {
    u8 Item_DecUses();
    M2C_UNK Unit_GetItemSlot();
    M2C_UNK Unit_CompactItems(s32);
    Unit_GetItemSlot();
    if (Item_DecUses() != 0) {
        Unit_CompactItems(arg0);
        return 1;
    }
    return 0;
}

s32 fn_80094A54(s32 arg0, s32 arg1)
{
  M2C_UNK fn_8001C5F8(M2C_UNK *, M2C_UNK);
  M2C_UNK fn_8001C76C(M2C_UNK *);
  M2C_UNK *new_var;
  M2C_UNK fn_8001D780(M2C_UNK *, s32);
  s32 fn_80094ABC(s32, M2C_UNK *);
  M2C_UNK sp8;
  short temp_r31;
  fn_8001C76C(&sp8);
  fn_8001D780(&sp8, arg1);
  new_var = &sp8;
  temp_r31 = fn_80094ABC(arg0, new_var);
  fn_8001C5F8(new_var, -1);
  return temp_r31;
}

s32 fn_80094ABC(void *arg0, void **arg1) {
    void *Unit_GetHeldItemSlot(void *, s32);
    s32 Unit_TryEquipItem(s32, void *);
    M2C_UNK Item_Copy(s32, s32);
    s32 i;
    Unk80037BD0 *slot;
    i = 0;
    if (*(u64 *)((u8 *)*arg1 + 0x38) & 5ULL) {
        while (1) {
            if (*(u32 *)Unit_GetHeldItemSlot(arg0,i)==0) goto found;
            i++;
            if (i >= 4) break;
        }
        i=-1;
found:
        if(i<0) return 0;
        slot=Unit_GetHeldItemSlot(arg0,i);
    } else {
        s32 index;
        if (*(u32 *)((u8 *)arg0+0x1EC)==0) index=0;
        else if (*(u32 *)((u8 *)arg0+0x1F4)==0) index=1;
        else if (*(u32 *)((u8 *)arg0+0x1FC)==0) index=2;
        else if (*(u32 *)((u8 *)arg0+0x204)==0) index=3;
        else index=-1;
        if(index<0) return 0;
        slot=(Unk80037BD0 *)((u8 *)arg0+(index*8+0x1EC));
    }
    Item_Copy((s32)slot,(s32)arg1);
    slot->unk5_bit7=0;
    Unit_TryEquipItem((s32)arg0,slot);
    return 1;
}

s32 Unit_TryEquipItem(s32 unit, void *item) {
    /* If the unit has no equipped item and may use this weapon, mark the item equipped (bit7) and return 1. */
    u64 *Item_GetFlagsPtr(void *);
    s8 Unit_GetActiveItemSlot(s32);
    u8 fn_80093708(s32, u32);
    struct { u8 pad[5]; u8 equipped : 1; u8 rest : 7; } *p;

    if (item == NULL || *(u32 *)item == 0) {
        return 0;
    }
    if ((*Item_GetFlagsPtr(item) & 1ULL) == 0) {
        return 0;
    }
    if (Unit_GetActiveItemSlot(unit) >= 0) {
        return 0;
    }
    if (fn_80093708(unit, *(u32 *)item) == 0) {
        return 0;
    }
    p = item;
    p->equipped = 1;
    return 1;
}

#pragma use_lmw_stmw off
#pragma optimization_level 2
void *fn_80094CDC(void *arg0, s32 arg1) {
    void **Unit_GetHeldItemSlot(void *, s32);
    u8 fn_800940B0(void *, void *);
    void *fn_8009542C(void *, s32);
    u8 Status_Test(void *, s32);
    void **slot;
    void *obj;
    u8 ok;
    u8 result;
    u64 flags;
    s32 var_r29;
    s32 var_r30;
    void *entry;
    u8 *p;

    if (arg1 < 4) {
        if (Status_Test((u8 *)arg0 + 0x1BC, 8) != 0) {
            return Unit_GetHeldItemSlot(arg0, 0);
        }
        var_r30 = 0;
        var_r29 = 0;
        do {
            slot = Unit_GetHeldItemSlot(arg0, var_r30);
            {
                u8 t = *((u8 *)slot + 5);
                var_r30 += 1;
                *((u8 *)slot + 5) = (u8)__rlwimi(t, var_r29, 7, 24, 24);
            }
        } while (var_r30 < 4);
        if (arg1 >= 0) {
            slot = Unit_GetHeldItemSlot(arg0, arg1);
            obj = *slot;
            result = 0;
            flags = *(u64 *)((u8 *)obj + 0x38);
            if ((flags & 1) == 0) {
            } else if (fn_800940B0(arg0, obj) == 0) {
                result = 0;
            } else {
                result = 1;
            }
            if (result == 0) {
                return NULL;
            }
        } else {
            var_r30 = 0;
            for (;;) {
                slot = Unit_GetHeldItemSlot(arg0, var_r30);
                obj = *slot;
                if (((u32)(-(s32)obj | (s32)obj) >> 31) == 0) {
                    return NULL;
                }
                result = 0;
                ok = 1;
                flags = *(u64 *)((u8 *)obj + 0x38);
                if ((flags & 1) == 0) {
                } else {
                    if (flags & 0x200) {
                        if (Status_Test((u8 *)arg0 + 0x1BC, 9) != 0) {
                            ok = 1;
                        } else {
                            ok = 0;
                        }
                    } else if (((*(u8 *)((u8 *)arg0 + 0x1A5) >> 4) & 7) == 0) {
                    } else if (flags & 2) {
                        ok = 0;
                    } else if (flags & 4) {
                        ok = 0;
                    } else if (flags & 0x40) {
                    }
                    if (ok == 0) {
                        result = 0;
                    } else if (fn_800940B0(arg0, obj) == 0) {
                        result = 0;
                    } else {
                        result = 1;
                    }
                }
                if (result != 0) {
                    break;
                }
                var_r30 += 1;
                if (var_r30 >= 4) {
                    return NULL;
                }
            }
        }
        {
            u8 t = *((u8 *)slot + 5);
            s32 one = 1;
            *((u8 *)slot + 5) = (u8)__rlwimi(t, one, 7, 24, 24);
        }
        return fn_8009542C(arg0, -1);
    }

    var_r29 = 0;
    {
        u8 t;
        t = *((u8 *)arg0 + 0x1F1);
        *((u8 *)arg0 + 0x1F1) = (u8)__rlwimi(t, var_r29, 7, 24, 24);
        t = *((u8 *)arg0 + 0x1F9);
        *((u8 *)arg0 + 0x1F9) = (u8)__rlwimi(t, var_r29, 7, 24, 24);
        t = *((u8 *)arg0 + 0x201);
        *((u8 *)arg0 + 0x201) = (u8)__rlwimi(t, var_r29, 7, 24, 24);
        t = *((u8 *)arg0 + 0x209);
        *((u8 *)arg0 + 0x209) = (u8)__rlwimi(t, var_r29, 7, 24, 24);
    }
    if (arg1 - 4 >= 0) {
        entry = (u8 *)arg0 + (((arg1 - 4) << 3) + 0x1EC);
        obj = *(void **)entry;
        flags = *(u64 *)((u8 *)obj + 0x38);
        if ((flags & 0x10) == 0) {
            result = 0;
        } else {
            result = fn_800940B0(arg0, obj);
        }
        if (result != 0) {
            u8 t = *((u8 *)entry + 5);
            s32 one = 1;
            *((u8 *)entry + 5) = (u8)__rlwimi(t, one, 7, 24, 24);
        } else {
            entry = NULL;
        }
        return entry;
    }
    p = arg0;
    var_r29 = 0;
    for (;;) {
        obj = *(void **)(p + 0x1EC);
        entry = p + 0x1EC;
        if (((u32)(-(s32)obj | (s32)obj) >> 31) != 0) {
            result = 0;
            flags = *(u64 *)((u8 *)obj + 0x38);
            if ((flags & 0x10) != 0) {
                result = fn_800940B0(arg0, obj);
            }
            if (result != 0) {
                u8 t = *((u8 *)entry + 5);
                s32 one = 1;
                *((u8 *)entry + 5) = (u8)__rlwimi(t, one, 7, 24, 24);
                return entry;
            }
        }
        var_r29 += 1;
        p += 8;
        if (var_r29 >= 4) {
            return NULL;
        }
    }
}
void *fn_80095070(void *arg0, s32 arg1) {
    u8 fn_800940B0(void *, void *);
    void *obj;
    u8 result;

    ((Unk80037BD0 *)((u8 *)arg0 + 0x1EC))->unk5_bit7 = 0;
    ((Unk80037BD0 *)((u8 *)arg0 + 0x1F4))->unk5_bit7 = 0;
    ((Unk80037BD0 *)((u8 *)arg0 + 0x1FC))->unk5_bit7 = 0;
    ((Unk80037BD0 *)((u8 *)arg0 + 0x204))->unk5_bit7 = 0;
    if (arg1 >= 0) {
        Unk80037BD0 *slot;
        slot = (Unk80037BD0 *)((arg1 << 3) + 0x1EC);
        slot = (Unk80037BD0 *)((u8 *)arg0 + (s32)slot);
        obj = *(void **)slot;
        if (*(u64 *)((u8 *)obj + 0x38) & 0x10ULL) {
            result = fn_800940B0(arg0, obj);
        } else {
            result = 0;
        }
        if (result) {
            slot->unk5_bit7 = 1;
            return slot;
        }
        return 0;
    } else {
        Unk80037BD0 *slot;
        u8 *p;
        s32 i;
        i = 0;
        p = arg0;
        do {
            slot = (Unk80037BD0 *)(p + 0x1EC);
            obj = *(void **)slot;
            if (!obj) {
                break;
            }
            if (*(u64 *)((u8 *)obj + 0x38) & 0x10ULL) {
                result = fn_800940B0(arg0, obj);
            } else {
                result = 0;
            }
            if (result) {
                slot->unk5_bit7 = 1;
                return slot;
            }
            i++;
            p += 8;
        } while (i < 4);
        return 0;
    }
}

#pragma optimization_level 2
void *fn_800951D0(void *arg0, s32 arg1) {
    void **Unit_GetHeldItemSlot(void *, s32);
    u8 fn_800940B0(void *, void *);
    void *fn_8009542C(void *, s32);
    u8 Status_Test(void *, s32);
    void **slot;
    void *obj;
    u8 ok;
    u8 result;
    u64 flags;
    s32 var_r29;
    s32 var_r30;

    if (Status_Test((u8 *)arg0 + 0x1BC, 8) != 0) {
        return Unit_GetHeldItemSlot(arg0, 0);
    }
    var_r30 = 0;
    var_r29 = 0;
    do {
        slot = Unit_GetHeldItemSlot(arg0, var_r30);
        {
            u8 t = *((u8 *)slot + 5);
            var_r30 += 1;
            *((u8 *)slot + 5) = (u8)__rlwimi(t, var_r29, 7, 24, 24);
        }
    } while (var_r30 < 4);
    if (arg1 >= 0) {
        slot = Unit_GetHeldItemSlot(arg0, arg1);
        obj = *slot;
        result = 0;
        flags = *(u64 *)((u8 *)obj + 0x38);
        if (flags & 1) {
            if (fn_800940B0(arg0, obj) == 0) {
                result = 0;
            } else {
                result = 1;
            }
        }
        if (result == 0) {
            return NULL;
        }
    } else {
        var_r29 = 0;
        for (;;) {
            slot = Unit_GetHeldItemSlot(arg0, var_r29);
            obj = *slot;
            if (obj == NULL) {
                return NULL;
            }
            result = 0;
            ok = 1;
            flags = *(u64 *)((u8 *)obj + 0x38);
            if (flags & 1) {
                if (flags & 0x200) {
                    if (Status_Test((u8 *)arg0 + 0x1BC, 9) != 0) {
                        ok = 1;
                    } else {
                        ok = 0;
                    }
                } else if (((*(u8 *)((u8 *)arg0 + 0x1A5) >> 4) & 7) == 0) {
                } else if (flags & 2) {
                    ok = result;
                } else if (flags & 4) {
                    ok = result;
                } else if (flags & 0x40) {
                }
                if (ok == 0) {
                    result = 0;
                } else if (fn_800940B0(arg0, obj) == 0) {
                    result = 0;
                } else {
                    result = 1;
                }
            }
            if (result != 0) {
                break;
            }
            var_r29 += 1;
            if (var_r29 >= 4) {
                return NULL;
            }
        }
    }
    {
        u8 t = *((u8 *)slot + 5);
        s32 one = 1;
        *((u8 *)slot + 5) = (u8)__rlwimi(t, one, 7, 24, 24);
    }
    return fn_8009542C(arg0, -1);
}

#pragma use_lmw_stmw on
void *fn_8009542C(void *unit, s8 slot) {
    void Item_Init(void *);
    void Item_Clear(void *);
    void Item_Copy(void *, void *);
    void *Unit_GetHeldItemSlot(void *, s32);
    void Item_Destroy(void *, s32);
    s8 Unit_GetActiveItemSlot(void *);
    u8 items[32];
    void *self;
    unsigned long off;
    u8 *item3;
    u8 *item2;
    u8 *item1;
    void *result;
    int i;

    self = unit;
    if (slot < 0) {
        slot = Unit_GetActiveItemSlot(self);
    }
    if (slot < 0) {
        return NULL;
    }

    Item_Init(items);
    item1 = items + 8;
    Item_Init(item1);
    item2 = items + 16;
    Item_Init(item2);
    item3 = items + 24;
    Item_Init(item3);

    off = (s8)slot;
    Item_Copy(items, Unit_GetHeldItemSlot(self, off));
    Item_Clear(Unit_GetHeldItemSlot(self, off));

    i = 0;
    off = 8;
    do {
        if (*(u32 *)Unit_GetHeldItemSlot(self, i) != 0) {
            Item_Copy(items + off + (off += 8) * 0, Unit_GetHeldItemSlot(self, i));
        }
        i += 1;
    } while (i < 4);

    i = 0;
    off = (s32)items;
    do {
        Item_Copy((u8 *)((s32)self + ((u8)i << 3) + 0x1CC), (void *)off);
        if (*(u32 *)Unit_GetHeldItemSlot(self, i) != 0) {
            if (((((u8 *)Unit_GetHeldItemSlot(self, i))[5] >> 7) & 1) != 0) {
                result = Unit_GetHeldItemSlot(self, i);
            }
        }
        i += 1;
        off += 8;
    } while (4 > i);

    Item_Destroy(item3, -1);
    Item_Destroy(item2, -1);
    Item_Destroy(item1, -1);
    Item_Destroy(items, -1);
    return result;
}
#pragma use_lmw_stmw reset
