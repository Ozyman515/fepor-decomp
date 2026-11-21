/* Functions from 0x80006264 to 0x80011968, found by decomp-toolkit. */
#include "common.h"
#include "process.h"

static inline u32 Process_CompareName(const s8 *a, const s8 *b)
{
    while (*a | *b) {
        if (*a != *b) return *a - *b;
        a++;
        b++;
    }
    return 0;
}

static inline u32 Process_CompareNameExt(const u8 *a, const u8 *b)
{
    u32 raw1;
    u32 raw2;
    s32 c1;
    s32 c2;
    goto ld;
cmp:
    if ((s8)raw1 != (s8)raw2)
        return (u32)(c1 - c2);
    a++;
    b++;
ld:
    raw1 = *a;
    raw2 = *b;
    c1 = (s8)raw1;
    c2 = (s8)raw2;
    if ((c1 | c2) != 0)
        goto cmp;
    return 0;
}

static inline void *Process_FindName(const s8 *source)
{
    extern u8 gProcesses[];
    u8 *entry = gProcesses;
    s32 i;
    for (i = 0; i < 256; i++, entry += 0x70) {
        if (*(u32 *)entry != 0 && Process_CompareName(*(s8 **)(entry + 0x14), source) == 0) return entry;
    }
    return 0;
}

typedef struct {
    void *unk0;
    void *unk4;
    s32 unk8;
} Struct_8000B090;

extern s32 lbl_802AEE20[5]; // array of 5 pointers
extern f64 lbl_80368C28;    // global float constant
extern u16 jumptable_80283AE8[];

#pragma optimization_level 2

#pragma optimization_level reset

#pragma opt_unroll off

#pragma global_optimizer reset

#pragma global_optimizer on
#pragma opt_strength_reduction on

#pragma optimization_level 4
#pragma scheduling on

#pragma scheduling reset
#pragma optimization_level reset

#pragma optimization_level 3

#pragma optimization_level reset

s32 fn_80006AF4(s32 *arg0) { s32 sum=0; s32 n=0; --arg0; do { sum+=*++arg0; } while (++n !=28); return sum; }
#pragma opt_unroll reset
void fn_80006B18(s32 arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4)
{
    extern void *gPrim2D;
    extern char lbl_80366DA4[];
    extern double lbl_80368B88;

    char buffer[32];
    char *destination;
    char *source;
    void *text;
    void *textBuffer;
    u8 *prim;
    s32 value;
    s32 length;
    s32 width;
    s32 x;
    s32 i;
    s32 j;
    s32 allocationSize;
    float yPosition;

    prim = (u8 *)gPrim2D;
    value = arg4;
    i = 0;

    if (arg3 != 0) {
        if (value < 0) {
            buffer[i++] = '-';
            value = -value;
        } else {
            buffer[i++] = '+';
        }
    } else if (value < 0) {
        buffer[0] = '-';
        buffer[1] = '-';
        buffer[2] = '\0';
        goto format_done;
    }

    length = 0;

    do {
        buffer[i++] = (value % 10) + '0';
        value /= 10;
        length++;
    } while (value != 0);

    buffer[i] = '\0';

    for (j = 0; j < length / 2; j++) {
        char temp;

        temp = buffer[(arg3 != 0 && arg4 < 0 ? 1 : 0) + j];
        buffer[(arg3 != 0 && arg4 < 0 ? 1 : 0) + j] =
            buffer[i - 2 - j];
        buffer[i - 2 - j] = temp;
    }

format_done:
    text = *(void **)(prim + 0xC);
    textBuffer = *(void **)((u8 *)text + 4);

    width = Text_MeasureWidth(buffer, -1, *(float *)((u8 *)textBuffer + 0x1C));

    x = arg0;

    if (arg2 == 0) {
        x -= width;
    } else if (arg2 == 2) {
        x -= (width + (width < 0)) / 2;
    }

    *(float *)((u8 *)textBuffer + 0x10) = (float)x;
    *(float *)((u8 *)textBuffer + 0x14) = (float)arg1;

    source = buffer;
    length = 1;

    while (*source++ != '\0') {
        length++;
    }

    allocationSize = (length + 3) & 0xFC;

    if (allocationSize > 0xD4) {
        allocationSize = 0xD4;
    }

    textBuffer = *(void **)(prim + 8);
    destination = (char *)textBuffer;
    destination += allocationSize;

    *(void **)(prim + 8) = destination;

    source = buffer;

    while (*source != '\0') {
        *destination++ = *source++;
    }

    *destination = '\0';

    *(u8 *)((u8 *)text + 5) += allocationSize;

    for (i = 0; i < 4; i++) {
        *((u8 *)text + 0x18 + i) = *((u8 *)text + 0x0C + i);
    }
}

#pragma global_optimizer off
#pragma use_lmw_stmw on
void fn_80006E8C(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
f32 y, yend, v, uend, vend, x, xend, u;
f32 a,c,b,z;
f32 d,f,e,delta,limit;
u8 red=arg1, green=arg2, blue=arg3, alpha=arg4;
a=*(f32*)((u8*)arg0+0x2C);
b=*(f32*)((u8*)arg0+0x1C);
c=*(f32*)((u8*)arg0+0x34);
vend=a;
y=*(f32*)((u8*)arg0+0x14);
v=b+c;
yend=(y+(a-b))-c;
for (;;) {
limit=*(f32*)((u8*)arg0+0x24);
if(yend>limit) {
delta=yend-limit;
yend=limit;
vend-=delta;
}
d=*(f32*)((u8*)arg0+0x28);
e=*(f32*)((u8*)arg0+0x18);
f=*(f32*)((u8*)arg0+0x30);
uend=d;
x=*(f32*)((u8*)arg0+0x10);
u=e+f;
xend=(x+(d-e))-f;
for (;;) {
c=*(f32*)((u8*)arg0+0x20);
if(xend>c) {
a=xend-c;
xend=c;
uend-=a;
}
GXBegin(0x98,0,4);
z=*(f32*)((u8*)arg0+8);
*(volatile f32*)0xCC008000=x;
*(volatile f32*)0xCC008000=y;
*(volatile f32*)0xCC008000=z;
*(volatile u8*)0xCC008000=red;
*(volatile u8*)0xCC008000=green;
*(volatile u8*)0xCC008000=blue;
*(volatile u8*)0xCC008000=alpha;
*(volatile f32*)0xCC008000=u;
*(volatile f32*)0xCC008000=v;
z=*(f32*)((u8*)arg0+8);
*(volatile f32*)0xCC008000=xend;
*(volatile f32*)0xCC008000=y;
*(volatile f32*)0xCC008000=z;
*(volatile u8*)0xCC008000=red;
*(volatile u8*)0xCC008000=green;
*(volatile u8*)0xCC008000=blue;
*(volatile u8*)0xCC008000=alpha;
*(volatile f32*)0xCC008000=uend;
*(volatile f32*)0xCC008000=v;
z=*(f32*)((u8*)arg0+8);
*(volatile f32*)0xCC008000=x;
*(volatile f32*)0xCC008000=yend;
*(volatile f32*)0xCC008000=z;
*(volatile u8*)0xCC008000=red;
*(volatile u8*)0xCC008000=green;
*(volatile u8*)0xCC008000=blue;
*(volatile u8*)0xCC008000=alpha;
*(volatile f32*)0xCC008000=u;
*(volatile f32*)0xCC008000=vend;
z=*(f32*)((u8*)arg0+8);
*(volatile f32*)0xCC008000=xend;
*(volatile f32*)0xCC008000=yend;
*(volatile f32*)0xCC008000=z;
*(volatile u8*)0xCC008000=red;
*(volatile u8*)0xCC008000=green;
*(volatile u8*)0xCC008000=blue;
*(volatile u8*)0xCC008000=alpha;
*(volatile f32*)0xCC008000=uend;
*(volatile f32*)0xCC008000=vend;
if(xend>=*(f32*)((u8*)arg0+0x20)) break;
c=*(f32*)((u8*)arg0+0x18);
x=xend;u=c;xend+=*(f32*)((u8*)arg0+0x28)-c;
}
if(yend>=*(f32*)((u8*)arg0+0x24)) break;
c=*(f32*)((u8*)arg0+0x1C);
y=yend;v=c;yend+=*(f32*)((u8*)arg0+0x2C)-c;
}
}
#pragma use_lmw_stmw reset
#pragma global_optimizer reset
extern f64 lbl_80368C28;
void fn_800070C8(s32 *arg0, s16 *arg1, s16 *arg2, s32 *arg3) {
    extern void *gPrim2D;

    if (arg0 != NULL) {
        *arg0 = *(s32 *)((u8 *)gPrim2D + 0xA4);
    }
    if (arg1 != NULL) {
        *arg1 = *(s16 *)((u8 *)gPrim2D + 0x92);
    }
    if (arg2 != NULL) {
        *arg2 = *(s16 *)((u8 *)gPrim2D + 0x90);
    }
    if (arg3 != NULL) {
        *arg3 = *(s32 *)((u8 *)gPrim2D + 8) - *(s32 *)gPrim2D;
    }
}

void Prim2D_SetText(u8 *arg0) {
    extern void *gPrim2D;
    extern u8 lbl_80366DA4;
    u8 *g;
    u32 n;
    u8 *out;
    u8 *dst;
    s8 *s;
    u32 len;
    u8 *mid;

    g = (u8 *)gPrim2D;
    n = 1;
    mid = *(u8 **)(g + 0xC);
    dst = *(u8 **)(mid + 4);
    s = (s8 *)arg0;
    if (s == NULL) {
        s = (s8 *)&lbl_80366DA4;
    }
    while (*s++) {
        n++;
    }
    s -= n;
    len = (n + 3) & 0xFC;
    if (len > 0xD4) {
        len = 0xD4;
    }
    out = *(u8 **)(g + 8);
    *(u8 **)(g + 8) = out + len;
    while (*s) {
        *out++ = (u8)*s++;
    }
    *out = 0;
    dst[5] += (u8)len;
    dst[0x18] = dst[0xC];
    dst[0x19] = dst[0xD];
    dst[0x1A] = dst[0xE];
    dst[0x1B] = dst[0xF];
}

void fn_800071D8(u32 arg0, f32 arg1)
{
    extern void *gPrim2D;
    s16 value = (s16)(256.0f * arg1);
    u8 disabled = (u8)arg0 == 0;
    u8 *object = *(u8 **)((u8 *)gPrim2D + 12);
    object = *(u8 **)(object + 4);
    *(s16 *)(object + 0x26) = disabled ? 0 : value;
}

void Prim2D_SetTextScale(u32 arg0, f32 arg1)
{
    extern void *gPrim2D;
    s16 value = (s16)(256.0f * arg1);
    u8 disabled = (u8)arg0 == 0;
    u8 *object = *(u8 **)((u8 *)gPrim2D + 12);
    object = *(u8 **)(object + 4);
    *(s16 *)(object + 0x24) = disabled ? 0 : value;
}

void fn_80007268(f32 arg0) {
    extern void *gPrim2D;

    u8 *ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);
    *(f32 *)(ptr + 0x20) = arg0;
}

void Prim2D_SetScale(f32 arg0) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);
    *(f32 *)(ptr + 0x1C) = arg0;
}

void Prim2D_SetTint(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
 extern void *gPrim2D;
 u8 *ptr = (u8 *)gPrim2D;
 ptr = *(u8 **)(ptr + 0xC);
 ptr = *(u8 **)(ptr + 4);
 ptr[0x18] = arg0;
 ptr[0x19] = arg1;
 ptr[0x1A] = arg2;
 ptr[0x1B] = arg3;
}

void Prim2D_SetCornerColors(u8 *a, u8 *b, u8 *c, u8 *d) {
    extern void *gPrim2D;
    u8 *dst;
    u8 *mid;
    u8 t0, t1, t2, t3;

    t0 = a[0];
    mid = *(u8 **)((u8 *)gPrim2D + 0xC);
    t1 = a[1];
    dst = *(u8 **)(mid + 4);
    t2 = a[2];
    dst[0xC] = t0;
    t3 = a[3];
    dst[0xD] = t1;
    t0 = b[0];
    dst[0xE] = t2;
    t1 = b[1];
    dst[0xF] = t3;
    t2 = b[2];
    dst[0x50] = t0;
    t3 = b[3];
    dst[0x51] = t1;
    t0 = c[0];
    dst[0x52] = t2;
    t1 = c[1];
    dst[0x53] = t3;
    t2 = c[2];
    dst[0x54] = t0;
    t3 = c[3];
    dst[0x55] = t1;
    t0 = d[0];
    dst[0x56] = t2;
    t1 = d[1];
    dst[0x57] = t3;
    t2 = d[2];
    dst[0x58] = t0;
    t3 = d[3];
    dst[0x59] = t1;
    dst[0x5A] = t2;
    dst[0x5B] = t3;
}

void fn_80007340(s32 arg0, s32 arg1) {
    extern void *gPrim2D;

    u8 *ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(s32 *)(ptr + 0x10) = arg0;
    *(s32 *)(ptr + 0x14) = arg1;
}

void fn_80007358(f32 arg0, f32 arg1) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x30) = arg0;
    *(f32 *)(ptr + 0x34) = arg1;
}

void fn_80007370(float arg0, float arg1, float arg2)
{
    extern void *gPrim2D;
    extern float lbl_80368B98;
    extern float lbl_80368B9C;

    float matrix1[12];
    float matrix2[12];
    float sine;
    float cosine;
    float scale;
    void *object;

    object = *(void **)((u8 *)gPrim2D + 0xC);
    object = *(void **)((u8 *)object + 4);

    PSMTXTrans(matrix1, -arg0, -arg1, lbl_80368B98);

    scale = lbl_80368B9C * arg2;
    PSMTXRotRad(matrix2, 0x5A, scale);

    PSMTXConcat(matrix2, matrix1, matrix2);

    PSMTXTrans(matrix1, arg0, arg1, lbl_80368B98);

    PSMTXConcat(matrix1, matrix2, matrix1);

    sine = matrix2[0];
    cosine = matrix2[1];

    *(float *)((u8 *)object + 0x10) =
        matrix2[2] +
        sine * *(float *)((u8 *)object + 0x30) +
        cosine * *(float *)((u8 *)object + 0x34);

    *(float *)((u8 *)object + 0x14) =
        matrix2[5] +
        matrix2[4] * *(float *)((u8 *)object + 0x30) +
        matrix2[3] * *(float *)((u8 *)object + 0x34);

    *(float *)((u8 *)object + 0x30) =
        matrix2[2] +
        sine * *(float *)((u8 *)object + 0x30) +
        cosine * *(float *)((u8 *)object + 0x34);

    *(float *)((u8 *)object + 0x34) =
        matrix2[5] +
        matrix2[4] * *(float *)((u8 *)object + 0x30) +
        matrix2[3] * *(float *)((u8 *)object + 0x34);

    *(float *)((u8 *)object + 0x40) =
        matrix2[2] +
        sine * *(float *)((u8 *)object + 0x40) +
        cosine * *(float *)((u8 *)object + 0x44);

    *(float *)((u8 *)object + 0x44) =
        matrix2[5] +
        matrix2[4] * *(float *)((u8 *)object + 0x40) +
        matrix2[3] * *(float *)((u8 *)object + 0x44);

    *(float *)((u8 *)object + 0x20) =
        matrix2[2] +
        sine * *(float *)((u8 *)object + 0x20) +
        cosine * *(float *)((u8 *)object + 0x24);

    *(float *)((u8 *)object + 0x24) =
        matrix2[5] +
        matrix2[4] * *(float *)((u8 *)object + 0x20) +
        matrix2[3] * *(float *)((u8 *)object + 0x24);
}

void Prim2D_RotateUvCw(void)
{
    extern void *gPrim2D;

    void *object;
    f32 x;
    f32 y;

    object = *(void **)((u8 *)gPrim2D + 0xC);
    object = *(void **)((u8 *)object + 4);

    x = *(f32 *)((u8 *)object + 0x18);
    y = *(f32 *)((u8 *)object + 0x1C);

    *(f32 *)((u8 *)object + 0x18) = *(f32 *)((u8 *)object + 0x48);
    *(f32 *)((u8 *)object + 0x1C) = *(f32 *)((u8 *)object + 0x4C);

    *(f32 *)((u8 *)object + 0x48) = *(f32 *)((u8 *)object + 0x28);
    *(f32 *)((u8 *)object + 0x4C) = *(f32 *)((u8 *)object + 0x2C);

    *(f32 *)((u8 *)object + 0x28) = *(f32 *)((u8 *)object + 0x38);
    *(f32 *)((u8 *)object + 0x2C) = *(f32 *)((u8 *)object + 0x3C);

    *(f32 *)((u8 *)object + 0x38) = x;
    *(f32 *)((u8 *)object + 0x3C) = y;
}

void Prim2D_RotateUvCcw(void)
{
    extern void *gPrim2D;

    void *object;
    f32 x;
    f32 y;

    object = *(void **)((u8 *)gPrim2D + 0xC);
    object = *(void **)((u8 *)object + 4);

    x = *(f32 *)((u8 *)object + 0x18);
    y = *(f32 *)((u8 *)object + 0x1C);

    *(f32 *)((u8 *)object + 0x18) = *(f32 *)((u8 *)object + 0x38);
    *(f32 *)((u8 *)object + 0x1C) = *(f32 *)((u8 *)object + 0x3C);

    *(f32 *)((u8 *)object + 0x38) = *(f32 *)((u8 *)object + 0x28);
    *(f32 *)((u8 *)object + 0x3C) = *(f32 *)((u8 *)object + 0x2C);

    *(f32 *)((u8 *)object + 0x28) = *(f32 *)((u8 *)object + 0x48);
    *(f32 *)((u8 *)object + 0x2C) = *(f32 *)((u8 *)object + 0x4C);

    *(f32 *)((u8 *)object + 0x48) = x;
    *(f32 *)((u8 *)object + 0x4C) = y;
}

void Prim2D_EmitQuad(void) {
    extern void *gPrim2D;
    void *object;

    object = *(void **)((u8 *)gPrim2D + 0xC);
    object = *(void **)((u8 *)object + 4);

    *(f32 *)((u8 *)object + 0x30) = *(f32 *)((u8 *)object + 0x20);
    *(f32 *)((u8 *)object + 0x34) = *(f32 *)((u8 *)object + 0x14);
    *(f32 *)((u8 *)object + 0x40) = *(f32 *)((u8 *)object + 0x10);
    *(f32 *)((u8 *)object + 0x44) = *(f32 *)((u8 *)object + 0x24);
    *(f32 *)((u8 *)object + 0x38) = *(f32 *)((u8 *)object + 0x28);
    *(f32 *)((u8 *)object + 0x3C) = *(f32 *)((u8 *)object + 0x1C);
    *(f32 *)((u8 *)object + 0x48) = *(f32 *)((u8 *)object + 0x18);
    *(f32 *)((u8 *)object + 0x4C) = *(f32 *)((u8 *)object + 0x2C);
}

void fn_80007628(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
 extern void *gPrim2D;
 u8 *ptr = (u8 *)gPrim2D;
 ptr = *(u8 **)(ptr + 0xC);
 ptr = *(u8 **)(ptr + 4);
 *(f32 *)(ptr + 0x40) = arg0;
 *(f32 *)(ptr + 0x44) = arg1;
 *(f32 *)(ptr + 0x48) = arg2;
 *(f32 *)(ptr + 0x4C) = arg3;
}

void fn_80007648(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x30) = arg0;
    *(f32 *)(ptr + 0x34) = arg1;
    *(f32 *)(ptr + 0x38) = arg2;
    *(f32 *)(ptr + 0x3C) = arg3;
}

void Prim2D_SetColorPacked(u8 *src)
{
  extern void *gPrim2D;
  u8 *base;
  u8 a;
  u8 b;
  u8 *new_var;
  u8 c;
  u8 *new_var2;
  u8 *ptr;
  u8 d;
  base = (u8 *) gPrim2D;
  new_var = src;
  a = new_var[0];
  base = *((u8 **) (base + 0xC));
  new_var2 = new_var;
  b = new_var2[1];
  ptr = *((u8 **) (base + 0x4));
  if ((c && c) && c)
  {
  }
  c = new_var[2];
  ptr[0xC] = a;
  d = src[3];
  ptr[0xD] = b;
  ptr[0xE] = c;
  ptr[0xF] = d;
}

void Prim2D_SetAlpha(u8 arg0) {
    extern void *gPrim2D;

    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(u8 *)(ptr + 0xF) = arg0;
}

void Prim2D_SetColor(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    ptr[0xC] = arg0;
    ptr[0xD] = arg1;
    ptr[0xE] = arg2;
    ptr[0xF] = arg3;
}

void Prim2D_SwapUvV(void) {
 extern void *gPrim2D;
 u8 *ptr;
 f32 temp;
 ptr = (u8 *)gPrim2D;
 ptr = *(u8 **)(ptr + 0xC);
 ptr = *(u8 **)(ptr + 4);
 temp = *(f32 *)(ptr + 0x1C);
 *(f32 *)(ptr + 0x1C) = *(f32 *)(ptr + 0x2C);
 *(f32 *)(ptr + 0x2C) = temp;
}

void Prim2D_SwapUvU(void) {
    extern void *gPrim2D;

    u8 *ptr;
    f32 temp;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    temp = *(f32 *)(ptr + 0x18);
    *(f32 *)(ptr + 0x18) = *(f32 *)(ptr + 0x28);
    *(f32 *)(ptr + 0x28) = temp;
}

void Prim2D_SetRectUv(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f)
{
    extern void *gPrim2D;
    void *p;
    f32 t0, t1, t2, t3;
    p = *(void **)((u8 *)gPrim2D + 0xC);
    p = *(void **)((u8 *)p + 4);
    t0 = a + e;
    t1 = b + f;
    t2 = c + e;
    t3 = d + f;
    *(f32 *)((u8 *)p + 0x10) = a;
    *(f32 *)((u8 *)p + 0x20) = t0;
    *(f32 *)((u8 *)p + 0x14) = b;
    *(f32 *)((u8 *)p + 0x24) = t1;
    *(f32 *)((u8 *)p + 0x1C) = 0.0f;
    *(f32 *)((u8 *)p + 0x18) = 0.0f;
    *(f32 *)((u8 *)p + 0x2C) = 1.0f;
    *(f32 *)((u8 *)p + 0x28) = 1.0f;
    p = *(void **)((u8 *)gPrim2D + 0xC);
    p = *(void **)((u8 *)p + 4);
    *(f32 *)((u8 *)p + 0x18) = c;
    *(f32 *)((u8 *)p + 0x1C) = d;
    *(f32 *)((u8 *)p + 0x28) = t2;
    *(f32 *)((u8 *)p + 0x2C) = t3;
}

void Prim2D_SetUvCorners(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x18) = arg0;
    *(f32 *)(ptr + 0x1C) = arg1;
    *(f32 *)(ptr + 0x28) = arg2;
    *(f32 *)(ptr + 0x2C) = arg3;
}

void Prim2D_SetPosCorners(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x10) = arg0;
    *(f32 *)(ptr + 0x14) = arg1;
    *(f32 *)(ptr + 0x20) = arg2;
    *(f32 *)(ptr + 0x24) = arg3;
}

void Prim2D_SetUvRect(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x18) = arg0;
    *(f32 *)(ptr + 0x1C) = arg1;
    *(f32 *)(ptr + 0x28) = arg0 + arg2;
    *(f32 *)(ptr + 0x2C) = arg1 + arg3;
}

#pragma global_optimizer off
#pragma scheduling off
void Prim2D_SetRect(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    extern void *gPrim2D;
    extern f32 lbl_80368B98;
    extern f32 gFloat1;
    u8 *ptr;
    f32 o;
    f32 z;
    f32 sum_x;

    ptr = (u8 *)gPrim2D;
    sum_x = arg0 + arg2;
    arg3 = arg1 + arg3;
    z = lbl_80368B98;
    ptr = *(u8 **)(ptr + 0xC);
    o = gFloat1;
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x10) = arg0;
    *(f32 *)(ptr + 0x20) = sum_x;
    *(f32 *)(ptr + 0x14) = arg1;
    *(f32 *)(ptr + 0x24) = arg3;
    *(f32 *)(ptr + 0x1C) = z;
    *(f32 *)(ptr + 0x18) = z;
    *(f32 *)(ptr + 0x2C) = o;
    *(f32 *)(ptr + 0x28) = o;
}
#pragma scheduling reset
#pragma global_optimizer reset
void Prim2D_SetQuadMax(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x20) = arg0;
    *(f32 *)(ptr + 0x24) = arg1;
    *(f32 *)(ptr + 0x28) = arg2;
    *(f32 *)(ptr + 0x2C) = arg3;
}

void Prim2D_SetQuadMin(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x10) = arg0;
    *(f32 *)(ptr + 0x14) = arg1;
    *(f32 *)(ptr + 0x18) = arg2;
    *(f32 *)(ptr + 0x1C) = arg3;
}

void Prim2D_SetPos(f32 arg0, f32 arg1) {
    extern void *gPrim2D;

    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);

    *(f32 *)(ptr + 0x10) = arg0;
    *(f32 *)(ptr + 0x14) = arg1;
}

void Prim2D_SetPrimParam(f32 arg0) {
    extern void *gPrim2D;
    u8 *ptr;

    ptr = (u8 *)gPrim2D;
    ptr = *(u8 **)(ptr + 0xC);
    ptr = *(u8 **)(ptr + 0x4);
    *(f32 *)(ptr + 0x8) = arg0;
}

void Prim2D_EndPrim(void) {
    extern u8 *gPrim2D;
    *(s16 *)(gPrim2D + 0x92) += 1;
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
void Prim2D_AddPrim(u8 arg0) {
    extern void *gPrim2D;
    extern f32 lbl_80368B98;
    extern f32 gFloat1;
    extern char lbl_80267C70[];
    s32 fn_80006AF4(void *);
    s32 fn_80006264(void *, void *, s32);
    void fn_800062CC(void *, void *, s32);
    void OSPanic(char *, ...);
    u8 *Ui_GetColor(s32);

    void *prev;
    void *node;
    void *self;
    s32 size;

    if (*(u8 *)((u8 *)gPrim2D + 0xA8) == 2) {
        s32 tmp;
        tmp = fn_80006AF4((u8 *)gPrim2D + 0x20);
        prev = 0;
        *(s32 *)((u8 *)gPrim2D + 0x18) = tmp;
        self = gPrim2D;
        node = *(void **)((u8 *)self + 0xC);
        while (node) {
            if (*(u32 *)((u8 *)node + 8) == *(u32 *)((u8 *)self + 0x18)) {
                if (fn_80006264((u8 *)node + 0x10, (u8 *)self + 0x20, 0x70) == 0) {
                    if (*(void **)((u8 *)gPrim2D + 0xC) != node)
                        goto unlink;
                    goto after_loop;
                unlink:
                    if (prev != 0) {
                        *(void **)prev = *(void **)node;
                    }
                    *(void **)node = *(void **)((u8 *)gPrim2D + 0xC);
                    *(void **)((u8 *)gPrim2D + 0xC) = node;
                    goto after_loop;
                }
            }
            prev = node;
            node = *(void **)node;
        }
        node = 0;
    after_loop:
        if (node == 0) {
            void *ctx;
            void *entry;
            ctx = gPrim2D;
            entry = *(void **)((u8 *)ctx + 8);
            *(void **)((u8 *)ctx + 8) = (u8 *)entry + 0x80;
            *(void **)entry = *(void **)((u8 *)gPrim2D + 0xC);
            *(void **)((u8 *)gPrim2D + 0xC) = entry;
            *(s32 *)((u8 *)entry + 4) = 0;
            *(s16 *)((u8 *)entry + 0xC) = -1;
            *(s32 *)((u8 *)entry + 8) = *(s32 *)((u8 *)gPrim2D + 0x18);
            fn_800062CC((u8 *)entry + 0x10, (u8 *)gPrim2D + 0x20, 0x70);
            ctx = gPrim2D;
            *(s16 *)((u8 *)ctx + 0x90) = (s16)(*(s16 *)((u8 *)ctx + 0x90) + 1);
        }
        *(u8 *)((u8 *)gPrim2D + 0xA8) = 3;
    }
    {
        u32 type;
        register void *entry;
        void *ctx;
        s32 neg1;
        f32 ftmp;
        type = arg0;
        switch (type) {
        case 1:
        case 4:
            size = 0x30;
            break;
        case 2:
            size = 0x50;
            break;
        case 3:
            size = 0x5C;
            break;
        case 5:
        case 6:
        case 7:
        case 10:
            size = 0x28;
            break;
        case 9:
            size = 0x38;
            break;
        case 11:
            size = 0x18;
            break;
        default:
            OSPanic(lbl_80267C70 + 0x1A, 0x54B, lbl_80267C70 + 0x23);
        }
        ctx = gPrim2D;
        neg1 = -1;
        ftmp = lbl_80368B98;
        entry = *(void **)((u8 *)ctx + 8);
        *(void **)((u8 *)ctx + 8) = (u8 *)entry + size;
        *(u8 *)((u8 *)entry + 4) = arg0;
        *(u8 *)((u8 *)entry + 5) = (u8)size;
        *(f32 *)((u8 *)entry + 8) = ftmp;
        *(s32 *)((u8 *)entry + 0xC) = (unsigned)neg1;
        {
            void *head;
            head = *(void **)((u8 *)gPrim2D + 0xC);
            *(void **)entry = *(void **)((u8 *)head + 4);
            head = *(void **)((u8 *)gPrim2D + 0xC);
            *(void **)((u8 *)head + 4) = entry;
        }
        if ((s32)type == 10) {
            goto init_extra;
        }
        if ((s32)type >= 10) {
            goto skip_extra;
        }
        if ((s32)type >= 8) {
            goto skip_extra;
        }
        if ((s32)type >= 5) {
            goto init_extra;
        }
        goto skip_extra;
    init_extra:
        {
            f32 f1;
            f32 f0;
            s16 z;
            void *e;
            u8 *p;
            z = 0;
            f1 = gFloat1;
            ctx = gPrim2D;
            f0 = lbl_80368B98;
            e = *(void **)((u8 *)*(void **)((u8 *)ctx + 0xC) + 4);
            *(f32 *)((u8 *)e + 0x20) = f0;
            *(f32 *)((u8 *)e + 0x1C) = f1;
            *(s16 *)((u8 *)e + 0x24) = z;
            *(s16 *)((u8 *)e + 0x26) = z;
            p = Ui_GetColor(1);
            *(u8 *)((u8 *)e + 0x18) = p[0];
            *(u8 *)((u8 *)e + 0x19) = p[1];
            *(u8 *)((u8 *)e + 0x1A) = p[2];
            *(u8 *)((u8 *)e + 0x1B) = p[3];
        }
    skip_extra:
        ;
    }
}

void fn_80007B04(void)
{
    s32 OSGetTick(void);
    void C_MTXOrtho(void *, f32, f32, f32, f32, f32, f32);
    void GXSetProjection(void *, s32);
    void GXClearVtxDesc(void);
    void GXSetVtxDesc(s32, s32);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void GXSetNumTevStages(s32);
    void fn_802250D0(u32 *, u32 *, u32 *, u32 *);
    void GXSetViewport(f32, f32, f32, f32, f32, f32);
    void GXSetZMode(s32, s32, s32);
    void fn_802246B8(s32);
    void fn_80223E5C(s32, s32, s32, s32, s32);
    void GXSetScissor(u32, u32, u32);
    void fn_80009728(void *, void *, u8);
    void GXLoadPosMtxImm(void *, s16);
    void GXSetCurrentMtx(s16);
    void fn_80009008(s32, u8, u8);
    extern void *gPrim2D;
    extern f32 lbl_80368B98;
    extern f32 lbl_80368BA0;
    extern f32 lbl_80368BA4;
    extern f32 lbl_80368BA8;
    extern f32 lbl_80368BAC;
    extern f32 lbl_80368BB0;
    extern f32 lbl_80368BB4;
    extern s16 lbl_802837B0[];

    u8 sp128[0x40];
    u32 sp24, sp20, sp1C, sp18;
    u32 sp14, sp10, spC, sp8;
    void **buf;
    void **slot;
    void *node;
    void **walk;
    u8 swapped;
    s32 i;
    u16 flags;
    f32 f3, f2, f1;
    void *mgr;

    mgr = gPrim2D;
    M2C_FIELD(mgr, s32 *, 0xA4) = OSGetTick();
    f1 = lbl_80368B98;
    C_MTXOrtho(sp128, f1, lbl_80368BAC, f1, lbl_80368BB0, f1, lbl_80368BB4);
    GXSetProjection(sp128, 1);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xB, 1);
    GXSetVtxDesc(0xD, 1);
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);
    GXSetVtxAttrFmt(0, 0xD, 1, 4, 0);
    GXSetCullMode(1);
    GXSetBlendMode(4, 0, 0, 1, 0, 0, 2);
    GXSetNumTevStages(1);

    mgr = gPrim2D;
    f3 = lbl_80368BA0;
    f2 = lbl_80368BA4;
    f1 = lbl_80368BA8;
    buf = M2C_FIELD(mgr, void ***, 8);
    M2C_FIELD(mgr, void ***, 8) = (void **)((u8 *)buf + ((M2C_FIELD(mgr, s16 *, 0x90) + 1) << 2));
    slot = buf;
    node = M2C_FIELD(gPrim2D, void **, 0xC);
    while (node != NULL) {
        *slot = node;
        slot++;
        flags = M2C_FIELD(node, u16 *, 0x10);
        if (!(flags & 0xF0)) {
            if (flags & 0x800) {
                M2C_FIELD(node, f32 *, 0x18) = f3;
            } else {
                M2C_FIELD(node, f32 *, 0x18) = f2;
            }
        } else if (flags & 0x800) {
            M2C_FIELD(node, f32 *, 0x18) += f1;
        }
        node = M2C_FIELD(node, void **, 0);
    }

    do {
        swapped = 0;
        walk = buf;
        for (i = 0; i < M2C_FIELD(gPrim2D, s16 *, 0x90) - 1; i++, walk++) {
            void *a = walk[0];
            void *b = walk[1];
            if (M2C_FIELD(a, f32 *, 0x18) < M2C_FIELD(b, f32 *, 0x18)) {
                walk[0] = b;
                swapped = 1;
                walk[1] = a;
            }
        }
    } while (swapped);

    buf[M2C_FIELD(gPrim2D, s16 *, 0x90)] = NULL;
    fn_802250D0(&sp24, &sp20, &sp1C, &sp18);
    mgr = gPrim2D;
    GXSetViewport(lbl_80368B98, lbl_80368B98, lbl_80368BB0, lbl_80368BAC,
                M2C_FIELD(mgr, f32 *, 0x9C), M2C_FIELD(mgr, f32 *, 0xA0));
    GXSetZMode(1, 3, 1);
    fn_802246B8(0);
    fn_80223E5C(6, 0x80, 1, 0, 0);

    walk = buf;
    while (*walk != NULL) {
        node = *walk;
        flags = M2C_FIELD(node, u16 *, 0x10);
        if (!(flags & 0xF0) && !(flags & 0x800)) {
            fn_802250D0(&sp14, &sp10, &spC, &sp8);
            if (sp24 != sp14 || sp20 != sp10 || sp1C != spC || sp18 != sp8) {
                GXSetScissor(sp20, sp1C, sp18);
            }
            node = *walk;
            if (M2C_FIELD(node, u16 *, 0x10) & 0x1000) {
                void (*cb)(void *, void *, void *, u8) =
                    (void (*)(void *, void *, void *, u8))M2C_FIELD(node, void **, 0x1C);
                cb(M2C_FIELD(node, void **, 0x20), (u8 *)node + 0x24, (u8 *)node + 0x44,
                   M2C_FIELD(node, u8 *, 0x12));
            } else {
                fn_80009728((u8 *)node + 0x24, (u8 *)node + 0x44, M2C_FIELD(node, u8 *, 0x12));
            }
            if (M2C_FIELD(*walk, s16 *, 0xC) < 0) {
                void **p = walk;
                s16 *tbl = lbl_802837B0;
                s32 n = 0;
                while (*p != NULL && n < 0xA) {
                    void *e = *p;
                    if (M2C_FIELD(e, u16 *, 0x10) & 0x400) {
                        M2C_FIELD(e, s16 *, 0xC) = lbl_802837B0[n];
                        GXLoadPosMtxImm((u8 *)*p + 0x50, lbl_802837B0[n]);
                        break;
                    }
                    M2C_FIELD(e, s16 *, 0xC) = *tbl;
                    GXLoadPosMtxImm((u8 *)*p + 0x50, *tbl);
                    p++;
                    tbl++;
                    n++;
                }
            }
            GXSetCurrentMtx(M2C_FIELD(*walk, s16 *, 0xC));
            node = *walk;
            if (M2C_FIELD(node, u16 *, 0x10) & 0x2000) {
                void (*cb)(void *, void *, void *, u8) =
                    (void (*)(void *, void *, void *, u8))M2C_FIELD(node, void **, 0x1C);
                cb(M2C_FIELD(node, void **, 0x20), (u8 *)node + 0x24, (u8 *)node + 0x44,
                   M2C_FIELD(node, u8 *, 0x12));
            }
            {
                u8 a9 = M2C_FIELD(gPrim2D, u8 *, 0xA9);
                node = *walk;
                if (a9 == 0xFF || (M2C_FIELD(node, u16 *, 0x10) & 0x400)) {
                    node = *walk;
                    fn_80009008(M2C_FIELD(node, s32 *, 4), M2C_FIELD(node, u8 *, 0x13),
                                M2C_FIELD(node, u8 *, 0x14));
                } else if (a9 != 0) {
                    fn_80009008(M2C_FIELD(node, s32 *, 4),
                                (u8)((s32)(a9 * M2C_FIELD(node, u8 *, 0x13)) >> 8),
                                M2C_FIELD(node, u8 *, 0x14));
                }
            }
            node = *walk;
            if (M2C_FIELD(node, u16 *, 0x10) & 0x4000) {
                void (*cb)(void *, void *, void *, u8) =
                    (void (*)(void *, void *, void *, u8))M2C_FIELD(node, void **, 0x1C);
                cb(M2C_FIELD(node, void **, 0x20), (u8 *)node + 0x24, (u8 *)node + 0x44,
                   M2C_FIELD(node, u8 *, 0x12));
            }
            flags = M2C_FIELD(*walk, u16 *, 0x10);
            if (flags & 0x400) {
                if (!(flags & 0xF0)) {
                    GXSetZMode(1, 3, 1);
                    fn_802246B8(0);
                    fn_80223E5C(6, 0x80, 1, 0, 0);
                } else {
                    GXSetZMode(1, 3, 0);
                    fn_802246B8(1);
                    fn_80223E5C(7, 0, 1, 7, 0);
                }
                {
                    u8 mat[0x40];
                    f32 z = lbl_80368B98;
                    C_MTXOrtho(mat, z, lbl_80368BAC, z, lbl_80368BB0, z, lbl_80368BB4);
                    GXSetProjection(mat, 1);
                }
                GXClearVtxDesc();
                GXSetVtxDesc(9, 1);
                GXSetVtxDesc(0xB, 1);
                GXSetVtxDesc(0xD, 1);
                GXSetVtxAttrFmt(0, 9, 1, 4, 0);
                GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);
                GXSetVtxAttrFmt(0, 0xD, 1, 4, 0);
                GXSetCullMode(1);
                GXSetBlendMode(4, 0, 0, 1, 0, 0, 2);
                GXSetNumTevStages(1);
            }
        }
        walk++;
    }

    mgr = gPrim2D;
    GXSetViewport(lbl_80368B98, lbl_80368B98, lbl_80368BB0, lbl_80368BAC,
                M2C_FIELD(mgr, f32 *, 0x94), M2C_FIELD(mgr, f32 *, 0x98));
    mgr = gPrim2D;
    M2C_FIELD(mgr, s32 *, 0xA4) = OSGetTick() - M2C_FIELD(mgr, s32 *, 0xA4);
    M2C_FIELD(gPrim2D, u8 *, 0xA9) = 0xFF;
}

#pragma global_optimizer on
void fn_80008B94(void)
{
    extern u8 *gPrim2D;
    extern void PSMTXIdentity(void *);

    *(s32 *)(gPrim2D + 8) = *(s32 *)gPrim2D + 0xAC;
    *(s32 *)(gPrim2D + 0xC) = 0;
    *(s16 *)(gPrim2D + 0x92) = 0;
    *(s16 *)(gPrim2D + 0x90) = 0;
    PSMTXIdentity(gPrim2D + 0x60);
    *(s32 *)(gPrim2D + 0x2C) = 0;
    *(s32 *)(gPrim2D + 0x30) = 0;
    gPrim2D[0x23] = 0xFF;
    gPrim2D[0x24] = 0x80;
    *(s16 *)(gPrim2D + 0x20) = 0;
    gPrim2D[0xA8] = 0;
}

void fn_80008C24(void *arg0, void *arg1, u8 *arg2, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    s32 fn_80011010(s32);
    void *fn_80005C40();
    void *fn_801047DC(u8 *);
    u8 *fn_801049E0(u8 *, s32 *, s32 *, s32 *, s32 *, s32 *, u8, u8, f32);
    void PSMTXScale(void *, u16, f32, f32, f32);
    void GXBegin(u32, u32, u32);
    void fn_80222644(void *, s32, u16, u16, u16, u32, u32, u32);
    void fn_80222C50(void *, u32);
    void fn_80224E50(void *, u16, u32);
    extern f32 gFloat1;
    extern f32 lbl_80368BB8;
    s32 sp7C;
    s32 sp78;
    u32 sp3C;
    u32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    f32 temp_f0;
    f32 temp_f18;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f23;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 temp_f25;
    f32 temp_f26;
    f32 temp_f27;
    f32 temp_f28;
    f32 temp_f29;
    f32 temp_f2;
    f32 temp_f3;
    f32 var_f19;
    s32 temp_r28;
    u16 temp_r5;
    u8 *var_r27;
    u8 temp_r0;
    u8 temp_r10;
    u8 temp_r3_3;
    u8 temp_r4;
    u8 temp_r5_2;
    u8 temp_r6;
    u8 temp_r7;
    u8 temp_r8;
    u8 temp_r9;
    u8 temp_r9_2;
    void *temp_r3;
    void *temp_r3_2;

    var_f19 = farg0;
    var_r27 = arg2;
    temp_r28 = fn_80011010(-1);
    temp_r3 = fn_80005C40();
    temp_r5 = *(u16 *)((char *)temp_r3 + 0x1E);
    PSMTXScale(&sp3C, temp_r5, gFloat1 / (f32) temp_r5, gFloat1 / (f32) *(u16 *)((char *)temp_r3 + 0x20), gFloat1);
    fn_80224E50(&sp3C, 0x1E, 1);
    temp_f18 = lbl_80368BB8;
loop_2:
    if ((s8) *var_r27 != 0) {
        temp_r3_2 = fn_801047DC(var_r27);
        temp_r10 = *(u8 *)((char *)temp_r3_2 + 8);
        temp_r9 = *(u8 *)((char *)temp_r3_2 + 9);
        temp_f24 = ((f32) (s8) *(u8 *)((char *)temp_r3_2 + 0xA) * farg3) + var_f19;
        sp7C = (s32) temp_r10;
        temp_f1 = (f32) (s8) *(u8 *)((char *)temp_r3_2 + 0xB);
        sp78 = 0x43300000;
        temp_f23 = -((temp_f1 * farg3) - (((f32) *(u16 *)((char *)temp_r3 + 8) * farg3) + farg1));
        temp_f26 = (f32) temp_r10;
        temp_f25 = (f32) temp_r9;
        var_r27 = fn_801049E0(var_r27, &sp18, &sp14, &sp10, &spC, &sp8, temp_r9, temp_r10, temp_f1);
        temp_f29 = (f32) sp14;
        temp_f28 = (f32) sp10;
        temp_f27 = (f32) sp8;
        fn_80222644(&sp1C, sp18, *(u16 *)((char *)temp_r3 + 0x1E), *(u16 *)((char *)temp_r3 + 0x20), *(u16 *)((char *)temp_r3 + 0x18), 0, 0, 0);
        fn_80222C50(&sp1C, 0);
        temp_f24_2 = (farg3 * (temp_f18 * (temp_f27 - (f32) spC))) + temp_f24;
        GXBegin(0x80, 0, 4);
        *(f32 *)0xCC008000 = temp_f24_2;
        temp_r6 = *(u8 *)((char *)arg0 + 0);
        *(f32 *)0xCC008000 = temp_f23;
        temp_f2 = temp_f29 + temp_f26;
        temp_r7 = *(u8 *)((char *)arg0 + 1);
        *(f32 *)0xCC008000 = farg2;
        temp_r8 = *(u8 *)((char *)arg0 + 2);
        temp_f1_2 = temp_f24_2 + (temp_f26 * farg3);
        *(f32 *)0xCC008000 = temp_r6;
        temp_f0 = temp_f23 + (temp_f25 * farg3);
        temp_r9_2 = *(u8 *)((char *)arg0 + 3);
        temp_f3 = temp_f28 + temp_f25;
        *(f32 *)0xCC008000 = temp_r7;
        temp_r0 = *(u8 *)((char *)arg1 + 0);
        var_f19 += temp_f27 * farg3;
        *(f32 *)0xCC008000 = temp_r8;
        temp_r3_3 = *(u8 *)((char *)arg1 + 1);
        *(f32 *)0xCC008000 = temp_r9_2;
        temp_r4 = *(u8 *)((char *)arg1 + 2);
        *(f32 *)0xCC008000 = temp_f29;
        temp_r5_2 = *(u8 *)((char *)arg1 + 3);
        *(f32 *)0xCC008000 = temp_f28;
        *(f32 *)0xCC008000 = temp_f1_2;
        *(f32 *)0xCC008000 = temp_f23;
        *(f32 *)0xCC008000 = farg2;
        *(f32 *)0xCC008000 = temp_r6;
        *(f32 *)0xCC008000 = temp_r7;
        *(f32 *)0xCC008000 = temp_r8;
        *(f32 *)0xCC008000 = temp_r9_2;
        *(f32 *)0xCC008000 = temp_f2;
        *(f32 *)0xCC008000 = temp_f28;
        *(f32 *)0xCC008000 = temp_f1_2;
        *(f32 *)0xCC008000 = temp_f0;
        *(f32 *)0xCC008000 = farg2;
        *(f32 *)0xCC008000 = temp_r0;
        *(f32 *)0xCC008000 = temp_r3_3;
        *(f32 *)0xCC008000 = temp_r4;
        *(f32 *)0xCC008000 = temp_r5_2;
        *(f32 *)0xCC008000 = temp_f2;
        *(f32 *)0xCC008000 = temp_f3;
        *(f32 *)0xCC008000 = temp_f24_2;
        *(f32 *)0xCC008000 = temp_f0;
        *(f32 *)0xCC008000 = farg2;
        *(f32 *)0xCC008000 = temp_r0;
        *(f32 *)0xCC008000 = temp_r3_3;
        *(f32 *)0xCC008000 = temp_r4;
        *(f32 *)0xCC008000 = temp_r5_2;
        *(f32 *)0xCC008000 = temp_f29;
        *(f32 *)0xCC008000 = temp_f3;
        goto loop_2;
    }
    fn_80011010(temp_r28);
}

#pragma use_lmw_stmw on
void fn_80009008(void *list, s32 a, s32 b) {
    void GXBegin(s32, s32, s32);
    void fn_80008C24(void *, void *, void *, f32, f32, f32, f32);
    void fn_8014B388(void *, void *, f32, f32, f32);
    void fn_8000E684(s16, s16, s32, void *, void *, void *, f32, f32, f32, f32, f32);
    void fn_8000E50C(s16, s16, s32, void *, void *, void *, f32, f32, f32, f32, f32);
    void fn_8000E394(s16, s16, s32, void *, void *, void *, f32, f32, f32, f32, f32);
    void fn_80006E8C(void *, u32, u32, u32, u32);

    u8 *node;
    s32 bsave;
    u8 scale;
    u8 scale1;
    u8 cr, cg, cb, ca;
    u8 type;
    u8 c0[4], c1[4];
    u32 col;
    f32 fx, fy, fz;
    void (*vfn)(s32);

    bsave = b;
    node = list;
    scale = (u8)b;
    scale1 = (u8)a + 1;

    while (node != NULL) {
        cr = (u8)((node[0xC] * scale) >> 7);
        cg = (u8)((node[0xD] * scale) >> 7);
        cb = (u8)((node[0xE] * scale) >> 7);
        ca = (u8)((node[0xF] * scale1) >> 8);
        type = node[4];
        if (type <= 11) {
            switch (type) {
            case 1:
                GXBegin(0x98, 0, 4);
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x14); fx = *(f32 *)(node + 0x10);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = cr; *(volatile u8 *)0xCC008000 = cg; *(volatile u8 *)0xCC008000 = cb; *(volatile u8 *)0xCC008000 = ca;
                *(volatile f32 *)0xCC008000 = *(f32 *)(node + 0x18); *(volatile f32 *)0xCC008000 = *(f32 *)(node + 0x1C);
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x14); fx = *(f32 *)(node + 0x20);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = cr; *(volatile u8 *)0xCC008000 = cg; *(volatile u8 *)0xCC008000 = cb; *(volatile u8 *)0xCC008000 = ca;
                *(volatile f32 *)0xCC008000 = *(f32 *)(node + 0x28); *(volatile f32 *)0xCC008000 = *(f32 *)(node + 0x1C);
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x24); fx = *(f32 *)(node + 0x10);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = cr; *(volatile u8 *)0xCC008000 = cg; *(volatile u8 *)0xCC008000 = cb; *(volatile u8 *)0xCC008000 = ca;
                *(volatile f32 *)0xCC008000 = *(f32 *)(node + 0x18); *(volatile f32 *)0xCC008000 = *(f32 *)(node + 0x2C);
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x24); fx = *(f32 *)(node + 0x20);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = cr; *(volatile u8 *)0xCC008000 = cg; *(volatile u8 *)0xCC008000 = cb; *(volatile u8 *)0xCC008000 = ca;
                *(volatile f32 *)0xCC008000 = *(f32 *)(node + 0x28); *(volatile f32 *)0xCC008000 = *(f32 *)(node + 0x2C);
                break;
            case 4:
                GXBegin(0xA8, 0, 2);
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x14); fx = *(f32 *)(node + 0x10);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = cr; *(volatile u8 *)0xCC008000 = cg; *(volatile u8 *)0xCC008000 = cb; *(volatile u8 *)0xCC008000 = ca;
                *(volatile f32 *)0xCC008000 = *(f32 *)(node + 0x18); *(volatile f32 *)0xCC008000 = *(f32 *)(node + 0x1C);
                fz = *(f32 *)(node + 0x8); fy = *(f32 *)(node + 0x24); fx = *(f32 *)(node + 0x20);
                *(volatile f32 *)0xCC008000 = fx; *(volatile f32 *)0xCC008000 = fy; *(volatile f32 *)0xCC008000 = fz;
                *(volatile u8 *)0xCC008000 = cr; *(volatile u8 *)0xCC008000 = cg; *(volatile u8 *)0xCC008000 = cb; *(volatile u8 *)0xCC008000 = ca;
                *(volatile f32 *)0xCC008000 = *(f32 *)(node + 0x28); *(volatile f32 *)0xCC008000 = *(f32 *)(node + 0x2C);
                break;
            case 5:
                col = (cr << 24) | (cg << 16) | (cb << 8) | ca;
                *(u32 *)c1 = col;
                c0[0] = (u8)((node[0x18] * scale) >> 7);
                c0[1] = (u8)((node[0x19] * scale) >> 7);
                c0[2] = (u8)((node[0x1A] * scale) >> 7);
                c0[3] = (u8)((node[0x1B] * scale1) >> 8);
                *(u32 *)c1 = col;
                fn_80008C24(c0, c1, node + 0x28, *(f32 *)(node + 0x10), *(f32 *)(node + 0x14), *(f32 *)(node + 0x8), *(f32 *)(node + 0x1C));
                break;
            case 6:
                col = (cr << 24) | (cg << 16) | (cb << 8) | ca;
                *(u32 *)c1 = col;
                c0[0] = node[0x18]; c0[1] = node[0x19]; c0[2] = node[0x1A];
                c0[3] = (u8)((node[0x1B] * scale1) >> 8);
                fn_8000E684(*(s16 *)(node + 0x24), *(s16 *)(node + 0x26), bsave, c0, c1, node + 0x28,
                    *(f32 *)(node + 0x10), *(f32 *)(node + 0x14), *(f32 *)(node + 0x8), *(f32 *)(node + 0x1C), *(f32 *)(node + 0x20));
                break;
            case 7:
                col = (cr << 24) | (cg << 16) | (cb << 8) | ca;
                *(u32 *)c1 = col;
                c0[0] = node[0x18]; c0[1] = node[0x19]; c0[2] = node[0x1A];
                c0[3] = (u8)((node[0x1B] * scale1) >> 8);
                fn_8000E50C(*(s16 *)(node + 0x24), *(s16 *)(node + 0x26), bsave, c0, c1, node + 0x28,
                    *(f32 *)(node + 0x10), *(f32 *)(node + 0x14), *(f32 *)(node + 0x8), *(f32 *)(node + 0x1C), *(f32 *)(node + 0x20));
                break;
            case 8:
                col = (cr << 24) | (cg << 16) | (cb << 8) | ca;
                *(u32 *)c1 = col;
                c0[0] = node[0x18]; c0[1] = node[0x19]; c0[2] = node[0x1A];
                c0[3] = (u8)((node[0x1B] * scale1) >> 8);
                fn_8000E394(*(s16 *)(node + 0x24), *(s16 *)(node + 0x26), bsave, c0, c1, node + 0x28,
                    *(f32 *)(node + 0x10), *(f32 *)(node + 0x14), *(f32 *)(node + 0x8), *(f32 *)(node + 0x1C), *(f32 *)(node + 0x20));
                break;
            case 9:
                fn_80006E8C(node, cr, cg, cb, ca);
                break;
            case 10:
                col = (cr << 24) | (cg << 16) | (cb << 8) | ca;
                *(u32 *)c1 = col; *(u32 *)c0 = col;
                fn_8014B388(c0, node + 0x28, *(f32 *)(node + 0x10), *(f32 *)(node + 0x14), *(f32 *)(node + 0x8));
                break;
            case 11:
                vfn = *(void (**)(s32))(node + 0x10);
                vfn(*(s32 *)(node + 0x14));
                break;
            default:
                break;
            }
        }
        node = *(u8 **)node;
    }
}

void fn_80009728(u32 arg0, void *arg1, s32 arg2, s32 arg3) {
    void PSMTXScale(void *, f32, f32, f32);
    void GXSetNumChans(s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void fn_80222CF0(s32, s32);
    void fn_80222C50(void *, s32);
    u32 GXGetTexObjWidth(void *);
    u32 GXGetTexObjHeight(void *);
    s32 fn_80222AA0(void *);
    void fn_80224E50(void *, s32, s32);
    void fn_802245D8(s32, s32, s32, s32);
    void GXSetNumTexGens(s32, s32);
    void GXSetTevColorIn(s32, s32, s32, s32, s32);
    void GXSetTevColorOp(s32, s32, s32, s32, s32, s32);
    void GXSetTevAlphaIn(s32, s32, s32, s32, s32);
    void GXSetTevAlphaOp(s32, s32, s32, s32, s32, s32);
    extern f32 gFloat1;
    u8 sp8[0x30];
    u16 temp_r31;
    u8 var_r30;
    f32 temp_f31;
    f32 temp_f1;
    s32 temp_r3;
    s32 a;
    s32 b;

    temp_r31 = (u16)arg0;
    var_r30 = 1;
    switch (arg0 & 3) {
    case 2:
        var_r30 = 0;
        GXSetNumChans(0);
        GXSetTevOrder(0, 0xFF, 0xFF, 4);
        break;
    case 0:
        if (temp_r31 & 0x8000) {
            fn_80222CF0(arg2, arg3);
        }
        fn_80222C50(arg1, 0);
        GXSetNumChans(1);
        fn_802201A8(0, 1, 4, 0x3C, 0, 0x7D);
        GXSetTevOrder(0, 0, 0, 4);
        break;
    case 1:
        if (temp_r31 & 0x8000) {
            fn_80222CF0(arg2, arg3);
        }
        fn_80222C50(arg1, 0);
        temp_f31 = gFloat1 / (f32)(u16)GXGetTexObjHeight(arg1);
        temp_f1 = gFloat1 / (f32)(u16)GXGetTexObjWidth(arg1);
        PSMTXScale(sp8, temp_f1, temp_f31, gFloat1);
        fn_80224E50(sp8, 0x1E, 1);
        GXSetNumChans(1);
        fn_802201A8(0, 1, 4, 0x1E, 0, 0x7D);
        GXSetTevOrder(0, 0, 0, 4);
        break;
    case 3:
        GXSetNumChans(1);
        fn_802201A8(0, 1, 4, 0x1E, 0, 0x7D);
        GXSetTevOrder(0, 0, 0, 4);
        break;
    }

#pragma scheduling off
    switch (temp_r31 & 0xF0) {
    case 0x0:
        fn_802245D8(0, 0, 0, 0);
        a = 0;
        b = 4;
        if (var_r30 != 0) {
            b = 0;
        }
        GXSetNumTexGens(a, b);
        break;
    case 0x10:
        fn_802245D8(1, 4, 5, 0);
        if (var_r30 != 0) {
            temp_r3 = fn_80222AA0(arg1);
            switch (temp_r3) {
            case 0:
            case 1:
                GXSetTevColorIn(0, 0xF, 0xF, 0xF, 0xA);
                GXSetTevColorOp(0, 0, 0, 0, 1, 0);
                GXSetTevAlphaIn(0, 7, 4, 5, 7);
                GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
                break;
            default:
                GXSetNumTexGens(0, 0);
                break;
            }
        } else {
            GXSetNumTexGens(0, 4);
        }
        break;
    case 0x20:
        fn_802245D8(1, 4, 1, 0);
        a = 0;
        b = 4;
        if (var_r30 != 0) {
            b = 0;
        }
        GXSetNumTexGens(a, b);
        break;
    case 0x30:
        fn_802245D8(3, 4, 1, 0);
        a = 0;
        b = 4;
        if (var_r30 != 0) {
            b = 0;
        }
        GXSetNumTexGens(a, b);
        break;
    case 0x40:
        GXSetTevColorIn(0, 0xF, 0xF, 0xF, 0xA);
        GXSetTevColorOp(0, 0, 0, 0, 1, 0);
        GXSetTevAlphaIn(0, 7, 4, 5, 7);
        GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
        break;
    }
#pragma scheduling reset
}

void Prim2D_ResetState(void) {
    extern u16 gPrim2D;

    *(u8 *)(*(u8 **)&gPrim2D + 0xa8) = 1;
    *(u8 *)(*(u8 **)&gPrim2D + 0x23) = 0xff;
    *(u8 *)(*(u8 **)&gPrim2D + 0x24) = 0x80;
    *(u32 *)(*(u8 **)&gPrim2D + 0x2c) = 0;
    *(u32 *)(*(u8 **)&gPrim2D + 0x30) = 0;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) &= ~0x7000;
    *(u8 *)(*(u8 **)&gPrim2D + 0xa8) = 2;
}

void Prim2D_SetAlphaByte(s8 arg0) {
    extern void *gPrim2D;
    M2C_FIELD(gPrim2D, s8 *, 0x24) = arg0;
}

extern u16 gPrim2D;
void Prim2D_SetColorByte(s8 arg0) {
    *(u8 *)(*(u8 **)&gPrim2D + 0x23) = (u8)arg0;
}

void Prim2D_ClearCallbacks(void) {
    extern u16 gPrim2D;

    *(u32 *)(*(u8 **)&gPrim2D + 0x2c) = 0;
    *(u32 *)(*(u8 **)&gPrim2D + 0x30) = 0;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) &= ~0x7000;
}

void Prim2D_SetCallback(s32 arg0, s32 arg1) {
    extern u16 gPrim2D;

    *(u32 *)(*(u8 **)&gPrim2D + 0x2c) = arg0;
    *(u32 *)(*(u8 **)&gPrim2D + 0x30) = arg1;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) &= ~0x7000;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) |= 0x2000;
}

void fn_80009BF4(f32 farg0) {
    *(f32 *)(*(u8 **)&gPrim2D + 0x28) = farg0;
}

f32 fn_80009C00(void) {
    return *(f32 *)(*(u8 **)&gPrim2D + 0x28);
}

void Prim2D_AddZ(f32 farg0) {
    extern u16 gPrim2D;
    *(f32 *)(*(u8 **)&gPrim2D + 0x28) += farg0;
}

void fn_80009C20(
    float arg0,
    float arg1,
    float arg2,
    float arg3,
    float arg4,
    float arg5,
    float arg6,
    float arg7
)
{
    extern float gFloat1;
    extern float lbl_80368B98;
    extern float lbl_80368B9C;

    float matrix0[12];
    float matrix1[12];
    float matrix2[12];
    float matrix3[12];
    float matrix4[12];
    float result[12];
    float scalar;

    scalar = arg2;

    PSMTXTrans(matrix0, arg0, arg1);

    PSMTXScale(matrix1, arg5, arg6, gFloat1);

    PSMTXRotRad(matrix2, 0x5A, lbl_80368B9C * arg7);

    PSMTXTrans(matrix3, -arg3, -arg4, lbl_80368B98);
    PSMTXTrans(matrix4, arg3, arg4, lbl_80368B98);

    PSMTXConcat(matrix1, matrix3, result);
    PSMTXConcat(matrix2, result, result);
    PSMTXConcat(matrix4, result, result);
    PSMTXConcat(matrix0, result, result);

    PSMTXCopy(result, (u8 *)gPrim2D + 0x60);

    *(float *)((u8 *)gPrim2D + 0x28) = scalar;
    *(u16 *)((u8 *)gPrim2D + 0x20) &= ~(1 << 10);
}

/* Build XY(Z) translate and optional uniform scale into gPrim2D's matrix; store z and clear flag 0x800. */
void Prim2D_SetTransform(f32 x, f32 y, f32 z, f32 scale) {
    void PSMTXTrans(void *, f32, f32, f32);
    void PSMTXScale(void *, f32, f32, f32);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXCopy(void *, void *);
    extern f32 gFloat1;
    extern u16 gPrim2D;
    f32 tmp[12];
    f32 mtx[12];

    if (gFloat1 == scale) {
        PSMTXTrans(mtx, x, y, z);
    } else {
        PSMTXScale(tmp, scale, scale, gFloat1);
        PSMTXTrans(mtx, x, y, z);
        PSMTXConcat(mtx, tmp, mtx);
    }
    PSMTXCopy(mtx, (*(u8 **)&gPrim2D) + 0x60);
    *(f32 *)((*(u8 **)&gPrim2D) + 0x28) = z;
    *(u16 *)((*(u8 **)&gPrim2D) + 0x20) &= ~0x800;
}

#pragma peephole off
void *Prim2D_PushZ(f32 *arg0) {
    extern u16 gPrim2D;

    if (arg0 != NULL) {
        *arg0 = *(f32 *)(*(u8 *volatile *)&gPrim2D + 0x28);
    }

    return *(u8 *volatile *)&gPrim2D + 0x60;
}
#pragma peephole on
void Prim2D_PopZ(void *src, f32 farg0) {
    void PSMTXCopy(void *, void *);
    extern u16 gPrim2D;

    PSMTXCopy(src, *(u8 **)&gPrim2D + 0x60);
    *(f32 *)(*(u8 **)&gPrim2D + 0x28) = farg0;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) = (u16)(*(u16 *)(*(u8 **)&gPrim2D + 0x20) & ~0x800);
}

#pragma optimization_level 3
void fn_80009EB0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void fn_8006EBC4(void *, void *, void *, s32, s32);
    extern u16 lbl_80367140;
    register s32 mask;
    unsigned long a;
    u32 b;
    u8 sp8[0xC];
    u8 sp14[0x20];
    register u8 *p;
    register u16 flags;

    fn_8006EBC4(arg0, sp14, sp8, arg2, arg1);
    p = *(u8 **)&lbl_80367140;
    mask = 0xFFFF7B0C;
    a = *(u32 *)(sp14 + 0);
    flags = (u16)(arg3 | 0x8000);
    b = *(u32 *)(sp14 + 4);
    *(u32 *)(p + 0x34) = a;
    *(u32 *)(p + 0x38) = b;
    a = *(u32 *)(sp14 + 8);
    b = *(u32 *)(sp14 + 0xC);
    *(u32 *)(p + 0x3C) = a;
    *(u32 *)(p + 0x40) = b;
    a = *(u32 *)(sp14 + 0x10);
    b = *(u32 *)(sp14 + 0x14);
    *(u32 *)(p + 0x44) = a;
    *(u32 *)(p + 0x48) = b;
    a = *(u32 *)(sp14 + 0x18);
    b = *(u32 *)(sp14 + 0x1C);
    *(u32 *)(p + 0x4C) = a;
    *(u32 *)(p + 0x50) = b;
    p = *(u8 **)&lbl_80367140;
    a = *(u32 *)(sp8 + 0);
    b = *(u32 *)(sp8 + 4);
    *(u32 *)(p + 0x58) = b;
    *(u32 *)(p + 0x54) = a;
    *(u32 *)(p + 0x5C) = *(u32 *)(sp8 + 8);
    (*(u8 **)&lbl_80367140)[0x22] = arg2;
    *(u16 *)(*(u8 **)&lbl_80367140 + 0x20) =
        *(u16 *)(*(u8 **)&lbl_80367140 + 0x20) & mask;
    *(u16 *)(*(u8 **)&lbl_80367140 + 0x20) =
        *(u16 *)(*(u8 **)&lbl_80367140 + 0x20) | flags;
}
#pragma optimization_level reset
void Prim2D_BindTexture(void *arg0, s32 arg1, u16 flags) {
    void Ui_LoadAtlasTex(void *, void *, s32);
    extern u16 gPrim2D;
    int mask;
    unsigned long a;
    int b;
    u32 sp[8];
    register u8 *p;
    register u8 ff;

    Ui_LoadAtlasTex(arg0, sp, arg1);
    mask = 0xFFFF7B0C;
    p = *(u8 **)&gPrim2D;
    b = sp[1];
    a = sp[0];
    ff = 0xFF;
    *(u32 *)(p + 0x38) = b;
    *(u32 *)(p + 0x34) = a;
    a = sp[2];
    b = sp[3];
    *(u32 *)(p + 0x3C) = a;
    *(u32 *)(p + 0x40) = b;
    a = sp[4];
    b = sp[5];
    *(u32 *)(p + 0x44) = a;
    *(u32 *)(p + 0x48) = b;
    a = sp[6];
    b = sp[7];
    *(u32 *)(p + 0x50) = b;
    *(u32 *)(p + 0x4C) = a;
    (*(u8 **)&gPrim2D)[0x22] = ff;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) =
        *(u16 *)(*(u8 **)&gPrim2D + 0x20) & mask;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) =
        *(u16 *)(*(u8 **)&gPrim2D + 0x20) | flags;
}

void fn_8000A03C(void *arg0, void *arg1, s8 arg2, u32 arg3) {
void fn_80006298(void *,s32,u32);
extern u16 gPrim2D;
u32 *src;
u32 b;
u32 a;
u8 *g;
u32 tmp;
u32 flags=arg3;
if (arg0) {
typedef struct { u32 words[8]; } Tex;
*(Tex *)(*(u8 **)&gPrim2D+0x34)=*(Tex *)arg0;
} else {
fn_80006298(*(u8 **)&gPrim2D+0x34,0,0x20);
if ((flags&3)==0) { flags &= 0xFFFC; tmp=flags|2; flags=tmp&0xFFFF; }
}
if (arg1) {
g=*(u8 **)&gPrim2D;
flags = (flags | 0x8000)&0xFFFF;
*(Struct_8000B090 *)(g+0x54)=*(Struct_8000B090 *)arg1;
(*(u8 **)&gPrim2D)[0x22]=arg2;
} else {
fn_80006298(*(u8 **)&gPrim2D+0x54,0,0xC);
(*(u8 **)&gPrim2D)[0x22]=0xFF;
}
*(u16 *)(*(u8 **)&gPrim2D+0x20)&=0xFFFF7B0C;
*(u16 *)(*(u8 **)&gPrim2D+0x20)|=flags;
}

#pragma global_optimizer off
void Prim2D_SetTex(void *arg0, u32 arg1) {
    void fn_80006298(void *, s32, u32);
    extern u16 gPrim2D;
    u32 *src;
    u32 b;
    u32 a;
    u8 *g;
    u32 tmp;

    if (arg0) {
        g = *(u8 **)&gPrim2D;
        src = (u32 *)arg0;
        a = src[0];
        b = src[1];
        *(u32 *)(g + 0x34) = a;
        *(u32 *)(g + 0x38) = b;
        a = src[2];
        b = src[3];
        *(u32 *)(g + 0x3C) = a;
        *(u32 *)(g + 0x40) = b;
        a = src[4];
        b = src[5];
        *(u32 *)(g + 0x44) = a;
        *(u32 *)(g + 0x48) = b;
        a = src[6];
        b = src[7];
        *(u32 *)(g + 0x4C) = a;
        *(u32 *)(g + 0x50) = b;
    } else {
        fn_80006298(*(u8 **)&gPrim2D + 0x34, 0, 0x2C);
        if ((arg1 & 3) == 0) {
            arg1 &= 0xFFFC;
            tmp = arg1 | 2;
            arg1 = tmp & 0xFFFF;
        }
    }
    (*(u8 **)&gPrim2D)[0x22] = 0xFF;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) &= 0xFFFF7B0C;
    *(u16 *)(*(u8 **)&gPrim2D + 0x20) |= arg1;
}
#pragma global_optimizer reset
void Prim2D_PrepareTex(void) {
    extern u16 gPrim2D;
    *(u8 *)(*(u8 **)&gPrim2D + 0xa8) = 2;
}

void Prim2D_Begin(void) {
*(u8 *)(*(u8 **)&gPrim2D+0xA8)=1;
}

u8 fn_8000A268(void) {
    return *(u8 *)(*(u8 **)&gPrim2D + 0xA9);
}

void fn_8000A274(u8 arg0) {
    *(u8 *)(*(u8 **)&gPrim2D + 0xa9) = arg0;
}

void fn_8000A280(void) {

}

void fn_8000A284(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    *(f32 *)(*(u8 **)&gPrim2D + 0x98) = arg0;
    *(f32 *)(*(u8 **)&gPrim2D + 0x94) = arg1;
    *(f32 *)(*(u8 **)&gPrim2D + 0xa0) = arg2;
    *(f32 *)(*(u8 **)&gPrim2D + 0x9c) = arg3;
}

#pragma global_optimizer off
void *fn_8000A2A8(u32 arg0)
{
  extern void *(*lbl_80366DA0)(u32);
  extern u16 gPrim2D;
  extern f32 gFloat1;
  extern f32 lbl_80368B98;
  extern f32 lbl_80368BB8;
  u32 n;
  void *p;
  u8 *new_var;
  f32 f2;
  f32 f1;
  f32 f0;
  if (arg0 == 0)
  {
    arg0 = 0xFFE0;
  }
  n = arg0 & (~7);
  p = lbl_80366DA0(n);
  *((void **) (&gPrim2D)) = p;
  f2 = gFloat1;
  new_var = ((u8 *) (*((void **) (&gPrim2D)))) + 4;
  f1 = lbl_80368BB8;
  *((void **) p) = p;
  f0 = lbl_80368B98;
  *((u32 *) new_var) = n;
  *((f32 *) (((u8 *) (*((void **) (&gPrim2D)))) + 0x98)) = f2;
  *((f32 *) (((u8 *) (*((void **) (&gPrim2D)))) + 0x94)) = f1;
  *((f32 *) (((u8 *) (*((void **) (&gPrim2D)))) + 0xa0)) = f1;
  *((f32 *) (((u8 *) (*((void **) (&gPrim2D)))) + 0x9c)) = f0;
  *((u32 *) (((u8 *) (*((void **) (&gPrim2D)))) + 0x10)) = 0;
  *((u32 *) (((u8 *) (*((void **) (&gPrim2D)))) + 0x14)) = 0;
  *((u16 *) (((u8 *) (*((void **) (&gPrim2D)))) + 0x20)) = 0;
  *(((u8 *) (*((void **) (&gPrim2D)))) + 0xa9) = 0xFF;
  return *((void **) (&gPrim2D));
}
#pragma global_optimizer reset
void *fn_800C4638(s32, void *, s32);
void fn_8000A358(s32 arg0) {
    extern u8 lbl_80267C70[];
    fn_800C4638(arg0, lbl_80267C70 + 0x3A, 0);
}

void GfxEnt_ForEachKey(u32 arg0, void (*arg1)(void *, s32), s32 arg2) {
    extern u8 gProcesses[];
    u8 *var_r31;
    s32 var_r30;

    var_r31 = gProcesses;
    var_r30 = 0;
    do {
        if (*(u32 *)var_r31 == arg0) {
            arg1(var_r31, arg2);
        }
        var_r30 += 1;
        var_r31 += 0x70;
    } while (var_r30 < 0x100);
}

void Process_DecRef(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x2E) = (u8) (M2C_FIELD(arg0, u8 *, 0x2E) - 1);
}

void fn_8000A408(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x2E) = (u8) (M2C_FIELD(arg0, u8 *, 0x2E) + 1);
}

u8 fn_8000A418(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x2E);
}

void Process_RetreatStep(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x2D) = (u8) (M2C_FIELD(arg0, u8 *, 0x2D) - 1);
}

void Process_AdvanceStep(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x2D) = (u8) (M2C_FIELD(arg0, u8 *, 0x2D) + 1);
}

void fn_8000A440(s32 arg0, s32 arg1) {
    extern s32 gProcessOpcodeTables[];
    gProcessOpcodeTables[arg0] = arg1;
}

void fn_8000A454(void *arg0, s32 *arg1, s32 *arg2)
{
    extern u8 lbl_80267CB0[];

    u8 *node;
    u8 *current;
    u8 *text;
    s32 length;
    u32 color;
    s32 depth;

    current = (u8 *)arg0;
    node = *(u8 **)(current + 0x24);

    if (node != 0) {
        if (*(u8 **)(node + 0x24) != 0) {
            fn_8000A454(*(void **)(node + 0x24), arg1, arg2);
        }

        color = 0xFFFFFFFF;
        depth = *arg1;
        *arg1 = depth + 1;

        if ((node[0x2C] & 2) != 0) {
            color = 0xFFC0C0FF;
        }

        if (node[0x2D] != 0) {
            color = 0xA0A0A0FF;
        }

        if ((node[0x2C] & 4) != 0) {
            if ((*(u8 **)(node + 0x18))[0x2D] != 0) {
                color = 0xA0A0A0FF;
            }
        }

        if (node[0x2E] != 0) {
            color = 0x4040FFFF;
        }

        fn_8014BB58(
            depth * 8,
            *arg2 * 8,
            &color,
            *(void **)(node + 0x14)
        );

        if (*(u32 *)(node + 0x0C) != 0) {
            text = *(u8 **)(node + 0x14);
            length = 0;

            while (text[length] != 0) {
                length++;
            }

            fn_8014BB58(
                (depth + length + 1) * 8,
                *arg2 * 8,
                &color,
                lbl_80267CB0 + 0x76
            );

            (*arg2)++;
        }

        if (*(u8 **)(node + 0x1C) != 0) {
            fn_8000A454(*(void **)(node + 0x1C), arg1, arg2);
        }

        (*arg1)--;
    }

    color = 0xFFFFFFFF;
    depth = *arg1;
    *arg1 = depth + 1;

    if ((current[0x2C] & 2) != 0) {
        color = 0xFFC0C0FF;
    }

    if (current[0x2D] != 0) {
        color = 0xA0A0A0FF;
    }

    if ((current[0x2C] & 4) != 0) {
        if ((*(u8 **)(current + 0x18))[0x2D] != 0) {
            color = 0xA0A0A0FF;
        }
    }

    if (current[0x2E] != 0) {
        color = 0x4040FFFF;
    }

    fn_8014BB58(
        depth * 8,
        *arg2 * 8,
        &color,
        *(void **)(current + 0x14)
    );

    if (*(u32 *)(current + 0x0C) != 0) {
        text = *(u8 **)(current + 0x14);
        length = 0;

        while (text[length] != 0) {
            length++;
        }

        fn_8014BB58(
            (depth + length + 1) * 8,
            *arg2 * 8,
            &color,
            lbl_80267CB0 + 0x76
        );

        (*arg2)++;
    }

    if (*(u8 **)(current + 0x1C) != 0) {
        fn_8000A454(*(void **)(current + 0x1C), arg1, arg2);
    }

    (*arg1)--;
    (*arg1)--;
}

void fn_8000A860(void) {
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_PrepareTex(void);
    void fn_8014BB58(s32, s32, s32 *, s32);
    void fn_8000A454(u32, s32 *, s32 *, s32);
    extern f32 lbl_80368BCC;
    extern f32 lbl_80368BD0;
    extern f32 lbl_80368BD4;
    extern s32 lbl_80368BC8;
    extern u32 lbl_802ADADC[];
    extern s32 lbl_802838C8[];

    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 i;

    sp10 = 1;
    spC = 0;
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_80368BCC, lbl_80368BCC, lbl_80368BD0, lbl_80368BD4);
    Prim2D_PrepareTex();

    for (i = 0; i < 8; i++) {
        if (lbl_802ADADC[i] != 0) {
            sp8 = lbl_80368BC8;
            fn_8014BB58(0, spC << 3, &sp8, lbl_802838C8[i]);
            {
                s32 old = spC;
                spC = old + 1;
                fn_8000A454(lbl_802ADADC[i], &sp10, &spC, old);
            }
        }
    }
}

s32 fn_8000A930(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x2C) = (u8) (M2C_FIELD(arg0, u8 *, 0x2C) | 0x10);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 4);
    return 1;
}

#pragma peephole on
