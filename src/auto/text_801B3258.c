/* Functions from 0x801B3258 to 0x801E4380, found by decomp-toolkit. */
#include "common.h"
static inline u8 *Battle_FindActiveSideUnit(void) {
    extern u8 gBattle[];
    u8 *unit;
    u8 type;
    unit = *(u8 **)(gBattle + 0x280);
    if (unit) {
        type = (*(u8 **)(unit + 0x190))[8];
        if (type == 0 || type == 5) return unit;
    }
    unit = *(u8 **)(gBattle + 0x560);
    if (unit) {
        type = (*(u8 **)(unit + 0x190))[8];
        if (type == 0 || type == 5) return unit;
    }
    return 0;
}
static inline u8 *MenuResource_FindIn(u8 *p, s32 id) {
s32 i;
for(i=0;i<40;p+=12,i++) { if(id==*(s32*)p) return p; }
return 0;
}
static inline u8 *MenuResource_Find(s32 id) {
extern u8 lbl_80299A78[];
u8 *p=lbl_80299A78;
s32 i;
for(i=0;i<40;i++,p+=12) { if(id==*(s32*)p) return p; }
return 0;
}
#pragma cplusplus on
struct MenuD28 {
virtual s32 v0()=0;
virtual s32 v1()=0;
virtual s32 v2()=0;
virtual s32 v3()=0;
virtual s32 v4()=0;
virtual s32 v5()=0;
virtual s32 v6()=0;
virtual s32 v7()=0;
virtual s32 v8()=0;
virtual s32 v9()=0;
virtual s32 v10()=0;
};
struct UnitHireItem {
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual void v9();
virtual void v10();
virtual void v11();
virtual void v12();
virtual void v13();
virtual void v14();
virtual void v15();
virtual void v16();
virtual void v17();
virtual void set2(s32);
virtual void v19();
virtual void set3(s32);
};
struct UnitHireMenuBase { u32 unknown; };
struct UnitHireMenu : UnitHireMenuBase {
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual void v9();
virtual void v10();
virtual void v11();
virtual void v12();
virtual void v13();
virtual void v14();
virtual UnitHireItem *get(s32);
};
static inline void InitUnitHireWidget(u8 *w) {
    extern u8 lbl_8028FDB0[], lbl_80292230[], lbl_8029186C[];
        *(void **)(w+0) = lbl_8028FDB0;
        *(s32 *)(w+4) = 0;
        *(void **)(w+0) = lbl_80292230;
        *(s16 *)(w+8) = -1;
        *(s16 *)(w+0xA) = 0x260;
        *(s16 *)(w+0xC) = 0x7C;
        *(s16 *)(w+0xE) = 0x368;
        *(s16 *)(w+0x10) = 0x16E;
        *(s16 *)(w+0x12) = 0;
        *(s16 *)(w+0x14) = 0;
        *(s16 *)(w+0x16) = 0x108;
        *(s16 *)(w+0x18) = 0xF2;
        *(s16 *)(w+0x1A) = 0;
        *(s16 *)(w+0x1C) = 0;
        w[0x1E] = 255; w[0x1F] = 255; w[0x20] = 255; w[0x21] = 255;
        *(s16 *)(w+0x22) = 0x1E0;
        *(s16 *)(w+0x24) = 0;
        *(f32 *)(w+0x28) = 1.0f;
        *(f32 *)(w+0x2C) = 1.0f;
        *(f32 *)(w+0x30) = 1.0f;
        *(s32 *)(w+0x34) = 0;
        *(s32 *)(w+0x38) = 0;
        *(void **)(w+0) = lbl_8029186C;
        *(s32 *)(w+0x3C) = 0;
        *(s16 *)(w+0x40) = 20;
        *(s16 *)(w+0x42) = 8;
}
struct UnitHireWidgetFields {
    void *vtable; s32 refcount;
    s16 id, x, y, right, bottom, offX, offY, width, height, scrollX, scrollY;
    u8 color[4]; s16 style, mode; f32 scale[3]; u32 flags, unk38;
    void *entry; s16 unk40, unk42;
};
struct UnitHireWidget {
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void init();
};
#pragma cplusplus reset




typedef struct ParseValue801CB41C { f32 v[8]; } ParseValue801CB41C;
typedef struct String801CB41C { u32 a, b, c; } String801CB41C;

typedef struct Self801CAF94 {
    s32 unk0;
    u8 pad4[0x50];
    s32 unk54;
    u8 pad58[0x14];
    void *unk6C;
    u8 pad70[4];
    s32 unk74;
    s8 unk78;
    s8 unk79;
} Self801CAF94;

void *Process_Create(void *, s32);
void *fn_801BEB9C(void *arg0, s16 *arg1, s16 *arg2, s16 arg3);

typedef struct ListNode {
    struct ListNode *prev;
    struct ListNode *next;
    void *val;
} ListNode;

typedef struct ListIter {
    ListNode *node;
} ListIter;

typedef struct MonitorWin {
    u8 pad0[0x30];
    u32 field30;
} MonitorWin;
typedef MonitorWin Arg801C838C;

typedef struct List {
    s32 size;
} List;

typedef struct UIListObj {
    u8 unk00[0x4E];
    s16 field4E;
    u8 unk50[4];
    s16 field54;
    u8 unk56[0x16];
    u32 count;
    u8 unk70[4];
    void *field74;
} UIListObj;


static inline s32 MsgBoxAddPad(s32 h, s32 pad) {
    return h + pad;
}

void fn_801E00EC(void *arg0, void *arg1);
extern u8 gFxChannels[];
extern u16 gScriptObjSlots[];
extern f32 lbl_8036B4A8;
extern f32 lbl_8027D528[3];
extern f32 lbl_8027D534[3];

typedef struct {
    u8 pad[0xC];
    u32 flags;
} Fn801C797CEnt;

struct Unit {
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
    u16 unk30;
    u16 unk32;
    u16 unk34;
    u16 unk36;
    u16 unk38;
    u16 unk3A;
    u16 unk3C;
    u16 unk3E;
    u16 unk40;
    u16 unk42;
    u16 unk44;
    u16 unk46;
    u16 unk48;
    u16 unk4A;
    u16 unk4C;
    u16 unk4E;
    u16 unk50;
    u16 unk52;
    u16 unk54;
    u16 unk56;
    u16 unk58;
    u16 unk5A;
    u16 unk5C;
    u16 unk5E;
    u16 unk60;
    u16 unk62;
    u16 unk64;
    u16 unk66;
};

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    u32 unk40;
    u32 unk44;
    u32 unk48;
    u32 unk4C;
    u32 unk50;
    u32 unk54;
    u32 unk58;
    u32 unk5C;
    u32 unk60;
    u32 unk62;
} struct0;


/* Message box: up to 7 text lines, opened/closed through state (0x64/0x6E open, 0xC8/0xD2 close). */
typedef struct MsgBox {
    /* 0x000 */ s16 flags;
    /* 0x002 */ s16 state;
    /* 0x004 */ s16 type;
    /* 0x006 */ u8 unk6[4];
    /* 0x00A */ s16 width;
    /* 0x00C */ s16 height;
    /* 0x00E */ u8 unkE[0x10];
    /* 0x01E */ s16 timer;
    /* 0x020 */ char lines[7][0x41];
    /* 0x1E7 */ s8 numLines;
    /* 0x1E8 */ u8 unk1E8[2];
} MsgBox;

static inline s32 MsgBoxPadHeight(s32 h, s32 pad) {
    return h + pad;
}

void fn_801B3258(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void *fn_800C4638(s32, void *, s32);
    extern u8 lbl_802979C8[];
    extern u8 gUnitStatusStr[];
    void *temp_r31;

    temp_r31 = Process_CreateChild(lbl_802979C8, arg1);
    *(void **)((u8 *)temp_r31 + 0x30) = fn_800C4638(0x114, gUnitStatusStr + 0x68, 0);
    *(s32 *)((u8 *)*(void **)((u8 *)temp_r31 + 0x30) + 0x14) = arg0;
    *(s32 *)((u8 *)*(void **)((u8 *)temp_r31 + 0x30) + 0x10) = 1;
}

void fn_801B32C8(s32 arg0, s32 arg1) {
    void *Process_CreateChild(void *, s32);
    void *fn_800C4638(s32, void *, s32);
    extern u8 lbl_80297984[];
    extern u8 gUnitStatusStr[];
    void *temp_r31;

    temp_r31 = Process_CreateChild(lbl_80297984, arg1);
    *(void **)((u8 *)temp_r31 + 0x30) = fn_800C4638(0x114, gUnitStatusStr + 0x68, 0);
    *(s32 *)((u8 *)*(void **)((u8 *)temp_r31 + 0x30) + 0x14) = arg0;
    *(s32 *)((u8 *)*(void **)((u8 *)temp_r31 + 0x30) + 0x10) = 0;
}

void fn_801B3338(void *arg0) {
    void fn_8005C7E8(void *);
    void fn_800C4588(void *);
    void *temp_r31;
    void *ptr;

    temp_r31 = *(void **)((u8 *)arg0 + 0x30);
    ptr = *(void **)((u8 *)temp_r31 + 0x18);
    if (ptr != NULL) {
        fn_8005C7E8(ptr);
    }
    fn_800C4588(temp_r31);
}

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
void fn_801B3378(void *proc) {
extern u32 *gPadInput;
extern u8 lbl_80297928[], gUnitStatusStr[];
extern f32 lbl_8036B0C0,lbl_8036B0C4,lbl_8036B0C8,lbl_8036B0CC,lbl_8036B0D0,lbl_8036B0D4,lbl_8036B0D8,lbl_8036B0DC,lbl_8036B0E0,lbl_8036B0E4,lbl_8036B0E8,lbl_8036B0EC,lbl_8036B0F0,lbl_8036B0F4,lbl_8036B0F8,lbl_8036B0FC,lbl_8036B100,lbl_8036B104,lbl_8036B108,lbl_8036B10C,lbl_8036B110,lbl_8036B114,lbl_8036B118,lbl_8036B11C,lbl_8036B120,lbl_8036B124,lbl_8036B140,lbl_8036B144;
f32 Math_Ease(s32,f32,f32,f32,f32);
void Ui_PlaySeCue(void *,s32);
void *fn_8005397C(void *,void *);
void Effect_SetPos(void *,f32,f32,f32);
void Process_ClearFunc(void *);
void Prim2D_Begin(void); void Prim2D_PrepareTex(void);
void Prim2D_SetTransform(f32,f32,f32,f32);
void Prim2D_SetColorByte(s32);
void Prim2D_SetTex(s32,s32); void Prim2D_AddPrim(s32);
void Prim2D_SetQuadMin(f32,f32,f32,f32); void Prim2D_SetQuadMax(f32,f32,f32,f32);
void Prim2D_SetColor(s32,s32,s32,s32);
void Prim2D_EmitQuad(void); void Prim2D_EndPrim(void); void Prim2D_AddZ(f32);
void *Face_Create(void *,s32); void fn_8007B4D8(s32,s32,s32,void *); void fn_8007AD6C(void *);
u32 *Ui_GetColor(s32); void *fn_8006EDD8(void *,s32); void Prim2D_BindTexture(void *,s32,s32);
void *Msg_ResolveName(void *); s16 Text_MeasureWidth(void *,s32,f32); void fn_8001003C(s32,s32,s32,s32,s32,void *,f32,f32,...); void fn_801B484C(void *,f32,f32,f32,f32);
void *Res_GetByName(void *);
typedef struct { u8 pad[0x64]; s32 state; u8 rest[8]; } Anim;
u32 color; void *name; s16 width; s32 timer;
f32 y,x,w,h,faceX;
u8 *p;
s32 alpha,backAlpha,skipped,stat;
u8 *table=lbl_80297928;
u32 pressed=gPadInput[1] & (gPadInput[2]^gPadInput[1]);
void *effect,*face; u16 *tex;
p=*(u8 **)((u8 *)proc+0x30);alpha=255;backAlpha=255;skipped=0;
faceX=445.0f;
if(*(s32 *)(p+4)>=9 && (pressed&0x1000)) *(u32 *)p|=1;
switch(*(s32 *)(p+4)) {
case 0: *(s32 *)(p+4)=1; *(s32 *)(p+12)=0;
case 1:
++*(s32 *)(p+12); alpha=0; timer=15; if(*(s32 *)(p+12)<=15)timer=*(s32 *)(p+12);
backAlpha=(s32)Math_Ease(0,lbl_8036B0C4,lbl_8036B0C8,(f32)timer,lbl_8036B0CC);
if(*(s32 *)(p+12)>=20) {*(s32 *)(p+4)=2;*(s32 *)(p+12)=0;} break;
case 2:
++*(s32 *)(p+12);
faceX=Math_Ease(4,465.0f,445.0f,(f32)*(s32 *)(p+12),10.0f);
Math_Ease(4,lbl_8036B0D8,lbl_8036B0DC,(f32)*(s32 *)(p+12),10.0f);
alpha=(s32)Math_Ease(0,lbl_8036B0C4,lbl_8036B0C8,(f32)*(s32 *)(p+12),10.0f);
if(*(s32 *)(p+12)>=10) {*(s32 *)(p+4)=5;*(s32 *)(p+12)=0;} break;
case 5:
++*(s32 *)(p+12);
if(*(s32 *)(p+12)>=30) {*(s32 *)(p+4)=6;*(s32 *)(p+12)=0;Ui_PlaySeCue(gUnitStatusStr+0x69,100);} break;
case 6:
++*(s32 *)(p+12);
*(f32 *)(p+0x104)=Math_Ease(0,lbl_8036B0E0,lbl_8036B0C4,(f32)*(s32 *)(p+12),lbl_8036B0D4);
if(*(s32 *)(p+12)>=10) {*(s32 *)(p+4)=7;*(s32 *)(p+12)=0;} break;
case 7:
*(s32 *)(p+4)=8; *(s32 *)(p+12)=0; p[0x1c]=1;
{
    u32 *e = *(u32 **)(p+0x108);
    *(void **)(p+0x108) = e[3] ? Res_GetByName((void *)e[3]) : 0;
}
break;
case 8:
++*(s32 *)(p+12);
*(f32 *)(p+0x104)=Math_Ease(0,lbl_8036B0C4,lbl_8036B0E0,(f32)*(s32 *)(p+12),lbl_8036B0D4);
if(*(s32 *)(p+12)>=10) {*(s32 *)(p+4)=9;*(s32 *)(p+12)=0;} break;
case 9:
++*(s32 *)(p+12);
if(*(s32 *)(p+12)>=20) {*(s32 *)(p+4)=10;*(s32 *)(p+12)=0;} break;
case 10:
scan:
for(;;) {
stat=(table+0x50)[*(s32 *)(p+8)];
if(*(s32 *)(p+8)>=10) {*(s32 *)(p+4)=19; goto draw;}
if(*(s8 *)(p+0x27+stat)) {
*(s32 *)(p+4)=15;*(s32 *)(p+12)=0;
if(*(u32 *)p&1) goto animate;
goto draw;
}
++*(s32 *)(p+8);
}
case 15:
animate:
stat=(table+0x50)[*(s32 *)(p+8)];
if(!skipped) Ui_PlaySeCue(gUnitStatusStr+0x7F,100);
if(*(u32 *)p&1) skipped=1;
effect=fn_8005397C(gUnitStatusStr+0x95,proc);
Effect_SetPos(effect,lbl_8036B0E4+(lbl_8036B0E8+(f32)((s16 *)(table+0x28))[stat]),lbl_8036B0EC+(lbl_8036B0F0+(f32)((s16 *)(table+0x3C))[stat]),lbl_8036B0C4);
((Anim *)(p+stat*16))->state=5;
*(s32 *)(p+4)=16; *(s32 *)(p+12)=0; ((f32 *)(p+stat*4))[14]=2.0f;
if(*(u32 *)p&1) {*(s32 *)(p+4)=10;++*(s32 *)(p+8);*(s32 *)(p+12)=0;goto scan;} break;
case 16:
++*(s32 *)(p+12);
if(*(s32 *)(p+12)>=20 || (*(u32 *)p&1)) {*(s32 *)(p+4)=10;++*(s32 *)(p+8);*(s32 *)(p+12)=0;} break;
case 19:
++*(s32 *)(p+12);
if(*(s32 *)(p+12)>=160 || (*(s32 *)(p+12)>=20 && (pressed&0x1000))) {*(s32 *)(p+4)=20;*(s32 *)(p+12)=0;} break;
case 20:
++*(s32 *)(p+12);
faceX=Math_Ease(4,445.0f,465.0f,(f32)*(s32 *)(p+12),10.0f);
Math_Ease(4,lbl_8036B0DC,lbl_8036B0D8,(f32)*(s32 *)(p+12),10.0f);
alpha=(s32)Math_Ease(0,lbl_8036B0C8,lbl_8036B0C4,(f32)*(s32 *)(p+12),10.0f);
if(*(s32 *)(p+12)>=10) {*(s32 *)(p+4)=25;*(s32 *)(p+12)=0;} break;
case 25:
++*(s32 *)(p+12); alpha=0; timer=15; if(*(s32 *)(p+12)<=15)timer=*(s32 *)(p+12);
backAlpha=(s32)Math_Ease(0,lbl_8036B0C8,lbl_8036B0C4,(f32)timer,lbl_8036B0CC);
if(*(s32 *)(p+12)>=20) Process_ClearFunc(proc);
break;
}
draw:
Prim2D_Begin(); Prim2D_SetTransform(lbl_8036B0C4,lbl_8036B0C4,lbl_8036B0F8,lbl_8036B0E0);
Prim2D_SetColorByte(backAlpha);Prim2D_PrepareTex();Prim2D_Begin();Prim2D_SetTex(0,18);Prim2D_PrepareTex();Prim2D_AddPrim(1);
Prim2D_SetQuadMin(lbl_8036B0C4,lbl_8036B0C4,lbl_8036B0C4,lbl_8036B0C4);
Prim2D_SetQuadMax(lbl_8036B0FC,lbl_8036B100,lbl_8036B0C4,lbl_8036B0C4);
Prim2D_SetColor(0,0,0,128);Prim2D_EmitQuad();Prim2D_EndPrim();
Prim2D_Begin();Prim2D_SetColorByte(alpha);Prim2D_PrepareTex();Prim2D_Begin();Prim2D_AddZ(lbl_8036B104);Prim2D_PrepareTex();
face=Face_Create(*(void **)(p+0x110),0);
fn_8007B4D8((s32)faceX,(s32)lbl_8036B108,255,face);fn_8007AD6C(face);
Prim2D_Begin();Prim2D_AddZ(lbl_8036B10C);Prim2D_PrepareTex();color=*Ui_GetColor(1);
tex=*(u16 **)fn_8006EDD8(*(void **)(p+0x18),7);
h=tex[1];w=tex[0];
Prim2D_Begin();Prim2D_BindTexture(*(void **)(p+0x18),7,17);Prim2D_PrepareTex();
x=lbl_8036B0C4*(lbl_8036B114*h)+(faceX-lbl_8036B110);
y=lbl_8036B0C4*(lbl_8036B114*w)+lbl_8036B118;
Prim2D_AddPrim(1);Prim2D_SetQuadMin(x,y,lbl_8036B0C4,lbl_8036B0C4);
Prim2D_SetQuadMax(h*lbl_8036B0E0+x,w*lbl_8036B0E0+y,h,w);
Prim2D_SetColor(((u8 *)&color)[0],((u8 *)&color)[1],((u8 *)&color)[2],255);Prim2D_EmitQuad();Prim2D_EndPrim();
Prim2D_Begin();Prim2D_AddZ(lbl_8036B104);Prim2D_PrepareTex();Prim2D_Begin();Prim2D_SetTex(0,19);Prim2D_PrepareTex();
name=Msg_ResolveName(*(void **)(*(u8 **)(p+0x14)+0x188));
width=Text_MeasureWidth(name,-1,lbl_8036B0E0);
fn_8001003C((s32)((faceX-2.0f)-(width/2)),(s32)lbl_8036B108,1,1,0,name,lbl_8036B0E0,lbl_8036B0C4);
Prim2D_Begin();Prim2D_AddZ(lbl_8036B11C);Prim2D_PrepareTex();Prim2D_Begin();Prim2D_SetColorByte(backAlpha);Prim2D_PrepareTex();
fn_801B484C(p,lbl_8036B120,lbl_8036B124,35.0f,160.0f);
}
#pragma opt_strength_reduction reset
#pragma use_lmw_stmw reset
void fn_801B3D30(void *arg0) {
    void UnitStatus_Init(void *);
    void *temp_r31;
    
    temp_r31 = *(void **)((char *)arg0 + 0x30);
    UnitStatus_Init(temp_r31);
    *(s32 *)((char *)temp_r31 + 0x18) = 0;
}

void fn_801B3D68(void *arg0) {
    void fn_8005C7E8(void *);
    void fn_800C4588(void *);
    void *temp_r31;
    void *ptr;

    temp_r31 = M2C_FIELD(arg0, void **, 0x30);
    fn_8014876C(gFxChannels + (M2C_FIELD(temp_r31, u8 *, 0x10C) * 0x30), 0x64, 0x3E8);
    ptr = M2C_FIELD(temp_r31, void **, 0x18);
    if (ptr != NULL) {
        fn_8005C7E8(ptr);
    }
    fn_800C4588(temp_r31);
}

void fn_801B3DC8(void *proc) {
extern u32 *gPadInput;
extern u8 lbl_80297928[], gUnitStatusStr[];
extern f32 lbl_8036B0C0,lbl_8036B0C4,lbl_8036B0C8,lbl_8036B0CC,lbl_8036B0D0,lbl_8036B0D4,lbl_8036B0E0,lbl_8036B0E4,lbl_8036B0E8,lbl_8036B0EC,lbl_8036B0F0,lbl_8036B0F4,lbl_8036B0F8,lbl_8036B0FC,lbl_8036B100,lbl_8036B104,lbl_8036B108,lbl_8036B10C,lbl_8036B110,lbl_8036B114,lbl_8036B118,lbl_8036B138,lbl_8036B13C,lbl_8036B140,lbl_8036B144;
f32 Math_Ease(s32,f32,f32,f32,f32);
void fn_8014876C(void *,s32,s32);
void Ui_PlaySeCue(void *,s32);
void *fn_8005397C(void *,void *);
void Effect_SetPos(void *,f32,f32,f32);
void Process_ClearFunc(void *);
void Prim2D_Begin(void); void Prim2D_PrepareTex(void);
void Prim2D_SetTransform(f32,f32,f32,f32);
void Prim2D_SetColorByte(s32);
void Prim2D_SetTex(s32,s32); void Prim2D_AddPrim(s32);
void Prim2D_SetQuadMin(f32,f32,f32,f32); void Prim2D_SetQuadMax(f32,f32,f32,f32);
void Prim2D_SetColor(s32,s32,s32,s32);
void Prim2D_EmitQuad(void); void Prim2D_EndPrim(void); void Prim2D_AddZ(f32);
void *Face_Create(void *,s32); void fn_8007B4D8(s32,s32,s32,void *); void fn_8007AD6C(void *);
u32 *Ui_GetColor(s32); void *fn_8006EDD8(void *,s32); void Prim2D_BindTexture(void *,s32,s32);
extern f32 lbl_8036B11C,lbl_8036B120,lbl_8036B124;
void *Msg_ResolveName(void *); s16 Text_MeasureWidth(void *,s32,f32); void fn_8001003C(s32,s32,s32,s32,s32,void *,f32,f32,...); void fn_801B484C(void *,f32,f32,f32,f32);
typedef struct { u8 pad[0x64]; s32 state; u8 rest[8]; } Anim;
u32 color; void *name; s16 width; s32 timer; s32 tick;
f32 y,x,w,h,faceX;
u8 *p;
s32 alpha,backAlpha,skipped,stat;
u8 *table=lbl_80297928;
u32 pressed=gPadInput[1] & (gPadInput[2]^gPadInput[1]);
void *effect,*face; u16 *tex;
p=*(u8 **)((u8 *)proc+0x30);alpha=255;backAlpha=255;skipped=0;
faceX=445.0f;
if(*(s32 *)(p+4)>=9 && (pressed&0x1000)) *(u32 *)p|=1;
switch(*(s32 *)(p+4)) {
case 0: *(s32 *)(p+4)=1; *(s32 *)(p+12)=0;
case 1:
++*(s32 *)(p+12); alpha=0; tick=*(s32 *)(p+12); timer=15; if(tick<=15)timer=tick;
backAlpha=(s32)Math_Ease(0,lbl_8036B0C4,lbl_8036B0C8,(f32)timer,lbl_8036B0CC);
if(*(s32 *)(p+12)==15) fn_8014876C(gFxChannels+p[0x10C]*0x30,100,1000);
if(*(s32 *)(p+12)>=20) {*(s32 *)(p+4)=2;*(s32 *)(p+12)=0;} break;
case 2:
++*(s32 *)(p+12);
faceX=Math_Ease(4,465.0f,445.0f,(f32)*(s32 *)(p+12),10.0f);
Math_Ease(4,lbl_8036B138,lbl_8036B13C,(f32)*(s32 *)(p+12),10.0f);
alpha=(s32)Math_Ease(0,lbl_8036B0C4,lbl_8036B0C8,(f32)*(s32 *)(p+12),10.0f);
if(*(s32 *)(p+12)>=10) {*(s32 *)(p+4)=5;*(s32 *)(p+12)=0;} break;
case 5:
++*(s32 *)(p+12);
if(*(s32 *)(p+12)>=30) {*(s32 *)(p+4)=8;*(s32 *)(p+12)=0;} break;
case 8:
Ui_PlaySeCue(gUnitStatusStr+0xA2,100);
effect=fn_8005397C(gUnitStatusStr+0x95,proc);
Effect_SetPos(effect,lbl_8036B140,lbl_8036B144,lbl_8036B0C4);
*(f32 *)(p+0x34)=2.0f; *(s32 *)(p+4)=9;*(s32 *)(p+12)=0;++p[0x1C];
case 9:
++*(s32 *)(p+12);
if(*(s32 *)(p+12)>=35) {*(s32 *)(p+4)=10;*(s32 *)(p+12)=0;} break;
case 10:
scan:
for(;;) {
stat=(table+0x50)[*(s32 *)(p+8)];
if(*(s32 *)(p+8)>=10) {*(s32 *)(p+4)=19; goto draw;}
if(stat<8 && *(s8 *)(p+0x27+stat)) {
*(s32 *)(p+4)=15;*(s32 *)(p+12)=0;
if(*(u32 *)p&1) goto animate;
goto draw;
}
++*(s32 *)(p+8);
}
case 15:
animate:
stat=(table+0x50)[*(s32 *)(p+8)];
if(!skipped) Ui_PlaySeCue(gUnitStatusStr+0x7F,100);
if(*(u32 *)p&1) skipped=1;
effect=fn_8005397C(gUnitStatusStr+0x95,proc);
Effect_SetPos(effect,lbl_8036B0E4+(lbl_8036B0E8+(f32)((s16 *)(table+0x28))[stat]),lbl_8036B0EC+(lbl_8036B0F0+(f32)((s16 *)(table+0x3C))[stat]),lbl_8036B0C4);
((Anim *)(p+stat*16))->state=5;
*(s32 *)(p+4)=16; *(s32 *)(p+12)=0; ((f32 *)(p+stat*4))[14]=2.0f;
if(*(u32 *)p&1) {*(s32 *)(p+4)=10;++*(s32 *)(p+8);*(s32 *)(p+12)=0;goto scan;} break;
case 16:
++*(s32 *)(p+12);
if(*(s32 *)(p+12)>=20 || (*(u32 *)p&1)) {*(s32 *)(p+4)=10;++*(s32 *)(p+8);*(s32 *)(p+12)=0;} break;
case 19:
++*(s32 *)(p+12);
if(*(s32 *)(p+12)>=160 || (*(s32 *)(p+12)>=20 && (pressed&0x1000))) {*(s32 *)(p+4)=20;*(s32 *)(p+12)=0;} break;
case 20:
++*(s32 *)(p+12);
faceX=Math_Ease(4,445.0f,465.0f,(f32)*(s32 *)(p+12),10.0f);
Math_Ease(4,lbl_8036B13C,lbl_8036B138,(f32)*(s32 *)(p+12),10.0f);
alpha=(s32)Math_Ease(0,lbl_8036B0C8,lbl_8036B0C4,(f32)*(s32 *)(p+12),10.0f);
if(*(s32 *)(p+12)>=10) {*(s32 *)(p+4)=25;*(s32 *)(p+12)=0;} break;
case 25:
++*(s32 *)(p+12); alpha=0; tick=*(s32 *)(p+12); timer=15; if(tick<=15)timer=tick;
backAlpha=(s32)Math_Ease(0,lbl_8036B0C8,lbl_8036B0C4,(f32)timer,lbl_8036B0CC);
if(*(s32 *)(p+12)>=20) Process_ClearFunc(proc);
break;
}
draw:
Prim2D_Begin(); Prim2D_SetTransform(lbl_8036B0C4,lbl_8036B0C4,lbl_8036B0F8,lbl_8036B0E0);
Prim2D_SetColorByte(backAlpha);Prim2D_PrepareTex();Prim2D_Begin();Prim2D_SetTex(0,18);Prim2D_PrepareTex();Prim2D_AddPrim(1);
Prim2D_SetQuadMin(lbl_8036B0C4,lbl_8036B0C4,lbl_8036B0C4,lbl_8036B0C4);
Prim2D_SetQuadMax(lbl_8036B0FC,lbl_8036B100,lbl_8036B0C4,lbl_8036B0C4);
Prim2D_SetColor(0,0,0,128);Prim2D_EmitQuad();Prim2D_EndPrim();
Prim2D_Begin();Prim2D_SetColorByte(alpha);Prim2D_PrepareTex();Prim2D_Begin();Prim2D_AddZ(lbl_8036B104);Prim2D_PrepareTex();
face=Face_Create(*(void **)(p+0x110),0);
fn_8007B4D8((s32)faceX,(s32)lbl_8036B108,255,face);fn_8007AD6C(face);
Prim2D_Begin();Prim2D_AddZ(lbl_8036B10C);Prim2D_PrepareTex();color=*Ui_GetColor(1);
tex=*(u16 **)fn_8006EDD8(*(void **)(p+0x18),7);
h=tex[1];w=tex[0];
Prim2D_Begin();Prim2D_BindTexture(*(void **)(p+0x18),7,17);Prim2D_PrepareTex();
x=lbl_8036B0C4*(lbl_8036B114*h)+(faceX-lbl_8036B110);
y=lbl_8036B0C4*(lbl_8036B114*w)+lbl_8036B118;
Prim2D_AddPrim(1);Prim2D_SetQuadMin(x,y,lbl_8036B0C4,lbl_8036B0C4);

Prim2D_SetQuadMax(h*lbl_8036B0E0+x,w*lbl_8036B0E0+y,h,w);
Prim2D_SetColor(((u8 *)&color)[0],((u8 *)&color)[1],((u8 *)&color)[2],255);Prim2D_EmitQuad();Prim2D_EndPrim();
Prim2D_Begin();Prim2D_AddZ(lbl_8036B104);Prim2D_PrepareTex();Prim2D_Begin();Prim2D_SetTex(0,19);Prim2D_PrepareTex();
name=Msg_ResolveName(*(void **)(*(u8 **)(p+0x14)+0x188));
width=Text_MeasureWidth(name,-1,lbl_8036B0E0);
fn_8001003C((s32)((faceX-2.0f)-(width/2)),(s32)lbl_8036B108,1,1,0,name,lbl_8036B0E0,lbl_8036B0C4);
Prim2D_Begin();Prim2D_AddZ(lbl_8036B11C);Prim2D_PrepareTex();Prim2D_Begin();Prim2D_SetColorByte(backAlpha);Prim2D_PrepareTex();
fn_801B484C(p,lbl_8036B120,lbl_8036B124,35.0f,160.0f);
}

void fn_801B46FC(void *arg0) {
    void UnitStatus_Init(void *);
    u8 fn_80028640(void);
    void *fn_8005397C(void *, void *);
    void *Process_FindByName(void *);
    void *Effect_Create(void *, void *);
    void Effect_SetPos(void *, f32, f32, f32);
    void Ui_PlaySeCue(void *, s32);
    void fn_8014876C(void *, s32, s32);

    extern u8 gUnitStatusStr[];
    extern u8 gFxChannels[];
    extern f32 lbl_8036B148;
    extern f32 lbl_8036B14C;
    extern f32 lbl_8036B0C4;

    u8 *self;
    u8 *unitStatus;
    u8 *position;
    void *effect;

    self = (u8 *)arg0;
    unitStatus = *(u8 **)(self + 0x30);

    UnitStatus_Init(unitStatus);

    if (fn_80028640() != 0) {
        effect = fn_8005397C(gUnitStatusStr + 0xB1, self);

        Effect_SetPos(
            effect,
            lbl_8036B148,
            lbl_8036B14C,
            lbl_8036B0C4
        );
    } else {
        if (Process_FindByName(gUnitStatusStr + 0xBD) != 0) {
            effect = fn_8005397C(gUnitStatusStr + 0xB1, self);

            Effect_SetPos(
                effect,
                lbl_8036B148,
                lbl_8036B14C,
                lbl_8036B0C4
            );
        } else {
            effect = Effect_Create(gUnitStatusStr + 0xB1, self);

            position = *(u8 **)(unitStatus + 0x14);

            Effect_SetPos(
                effect,
                *(f32 *)(position + 4),
                *(f32 *)(position + 8),
                *(f32 *)(position + 0xC)
            );

            Ui_PlaySeCue(gUnitStatusStr + 0xC7, 0x64);

            fn_8014876C(
                gFxChannels + unitStatus[0x10C] * 0x30,
                0x32,
                0xFA
            );
        }
    }

    *(s32 *)(unitStatus + 0x18) = 0;
}

void fn_801B4810(void) {
    extern u16 gUnitStatusStr[];
    GActor_RequestRes((u8 *)gUnitStatusStr + 0xb1);
    GActor_RequestRes((u8 *)gUnitStatusStr + 0x95);
}

void fn_801B484C(void *arg0, f32 f1, f32 f2, f32 f3, f32 f4)
{
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Prim2D_BindTexture(void *, s32, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetColor(u8, u8, u8, u8);
    void Prim2D_EmitQuad(void);
    void Prim2D_EndPrim(void);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_SetCallback(void (*)(s32, s16 *), s16 *);
    void Prim2D_ClearCallbacks(void);
    void fn_801B6064(s32, s16 *);
    u32 *Ui_GetColor(s32);
    void **fn_8006EDD8(void *, s32);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, f32, f32, ...);
    s32 Text_MeasureWidth(void *, s32, f32);
    s32 fn_80010770(void *, s32, f32);
    void *fn_800A8978(void *);
    void *Msg_Expand(void *);
    s32 sprintf(char *, const char *, ...);
    s64 OSGetTime(void);
    u32 OSGetTick(void);
    s64 __div2i(s64, s64);
    s64 __mod2i(s64, s64);
    f32 fn_8022CB78(s64);
    f64 sin(f32);
    f32 Math_Ease(s32, f32, f32, f32, f32);

    extern s8 lbl_80368240;
    extern s16 lbl_80368244[4];
    extern u8 lbl_80297928[];
    extern u8 gUnitStatusStr[];
    extern f32 lbl_8036B0C4;
    extern f32 lbl_8036B0D4;
    extern f32 lbl_8036B0E0;
    extern f32 lbl_8036B0EC;
    extern f32 lbl_8036B0F8;
    extern f32 lbl_8036B104;
    extern f32 lbl_8036B10C;
    extern f32 lbl_8036B114;
    extern f32 lbl_8036B11C;
    extern f32 lbl_8036B150;
    extern f32 lbl_8036B154;
    extern f32 lbl_8036B158;
    extern f32 lbl_8036B15C;
    extern f32 lbl_8036B160;
    extern f32 lbl_8036B164;
    extern f32 lbl_8036B168;
    extern f32 lbl_8036B16C;
    extern f32 lbl_8036B170;
    extern f32 lbl_8036B174;
    extern f32 lbl_8036B178;
    extern f32 lbl_8036B17C;
    extern f32 lbl_8036B180;
    extern f32 lbl_8036B184;
    extern f32 lbl_8036B188;
    extern f32 lbl_8036B18C;
    extern f32 lbl_8036B190;
    extern f32 lbl_8036B194;
    extern f32 lbl_8036B198;
    extern f32 lbl_8036B19C;
    extern f32 lbl_8036B1A0;
    extern f32 lbl_8036B1A4;
    extern f32 lbl_8036B1A8;
    extern f32 lbl_8036B1AC;

    u8 *self = (u8 *)arg0;
    void *texture;
    u16 *tex;
    u32 color;
    u8 *rgb;
    s32 count, i, value, extra, widthDiff, heightDiff;
    s32 alpha, period;
    f32 tw, th, x, y, x2, y2, factor, scale, pulse;
    char buf[48];
    void *text;

    if (lbl_80368240 == 0) {
        lbl_80368240 = 1;
    }
    count = (*(s32 *)(self + 0x10) == 0) ? 8 : 10;
    texture = *(void **)(self + 0x18);

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B150);
    Prim2D_PrepareTex();

    if (*(s32 *)(self + 0x10) == 0) {
        factor = *(f32 *)(self + 0x104);
        color = *Ui_GetColor(1);
        tex = *(u16 **)fn_8006EDD8(texture, 1);
        tw = (f32)tex[1];
        th = (f32)tex[0];
        Prim2D_Begin();
        Prim2D_BindTexture(texture, 1, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        x = f1 + lbl_8036B0C4 * (lbl_8036B114 * tw);
        y = f2 + (lbl_8036B0E0 - factor) * (lbl_8036B114 * th);
        Prim2D_SetQuadMin(x, y, lbl_8036B0C4, lbl_8036B0C4);
        Prim2D_SetQuadMax(x + tw * lbl_8036B0E0, y + th * factor, tw, th);
        rgb = (u8 *)&color;
        Prim2D_SetColor(rgb[0], rgb[1], rgb[2], 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        factor = *(f32 *)(self + 0x104);
        color = *Ui_GetColor(1);
        tex = *(u16 **)fn_8006EDD8(texture, 1);
        tw = (f32)tex[1];
        th = (f32)tex[0];
        Prim2D_Begin();
        Prim2D_BindTexture(texture, 1, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        x = (f1 + lbl_8036B154) + lbl_8036B0C4 * (lbl_8036B114 * tw);
        y = f2 + (lbl_8036B0E0 - factor) * (lbl_8036B114 * th);
        Prim2D_SetQuadMin(x, y, tw, th);
        Prim2D_SetQuadMax(x + tw * lbl_8036B0E0, y + th * factor, lbl_8036B0C4, th);
        rgb = (u8 *)&color;
        Prim2D_SetColor(rgb[0], rgb[1], rgb[2], 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        color = *Ui_GetColor(1);
        tex = *(u16 **)fn_8006EDD8(texture, 3);
        tw = (f32)tex[1];
        th = (f32)tex[0];
        Prim2D_Begin();
        Prim2D_BindTexture(texture, 3, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        x = f3 + lbl_8036B0C4 * (lbl_8036B114 * tw);
        y = f4 + lbl_8036B0C4 * (lbl_8036B114 * th);
        Prim2D_SetQuadMin(x, y, lbl_8036B0C4, lbl_8036B0C4);
        Prim2D_SetQuadMax(x + tw * lbl_8036B0E0, y + th * lbl_8036B0E0, tw, th);
        rgb = (u8 *)&color;
        Prim2D_SetColor(rgb[0], rgb[1], rgb[2], 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

    } else {
        factor = *(f32 *)(self + 0x104);
        color = *Ui_GetColor(1);
        tex = *(u16 **)fn_8006EDD8(texture, 2);
        tw = (f32)tex[1];
        th = (f32)tex[0];
        Prim2D_Begin();
        Prim2D_BindTexture(texture, 2, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        x = f1 + lbl_8036B0C4 * (lbl_8036B114 * tw);
        y = f2 + (lbl_8036B0E0 - factor) * (lbl_8036B114 * th);
        Prim2D_SetQuadMin(x, y, lbl_8036B0C4, lbl_8036B0C4);
        Prim2D_SetQuadMax(x + tw * lbl_8036B0E0, y + th * factor, tw, th);
        rgb = (u8 *)&color;
        Prim2D_SetColor(rgb[0], rgb[1], rgb[2], 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        factor = *(f32 *)(self + 0x104);
        color = *Ui_GetColor(1);
        tex = *(u16 **)fn_8006EDD8(texture, 2);
        tw = (f32)tex[1];
        th = (f32)tex[0];
        Prim2D_Begin();
        Prim2D_BindTexture(texture, 2, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        x = (f1 + lbl_8036B154) + lbl_8036B0C4 * (lbl_8036B114 * tw);
        y = f2 + (lbl_8036B0E0 - factor) * (lbl_8036B114 * th);
        Prim2D_SetQuadMin(x, y, tw, th);
        Prim2D_SetQuadMax(x + tw * lbl_8036B0E0, y + th * factor, lbl_8036B0C4, th);
        rgb = (u8 *)&color;
        Prim2D_SetColor(rgb[0], rgb[1], rgb[2], 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        color = *Ui_GetColor(1);
        tex = *(u16 **)fn_8006EDD8(texture, 4);
        tw = (f32)tex[1];
        th = (f32)tex[0];
        Prim2D_Begin();
        Prim2D_BindTexture(texture, 4, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        x = f3 + lbl_8036B0C4 * (lbl_8036B114 * tw);
        y = f4 + lbl_8036B0C4 * (lbl_8036B114 * th);
        Prim2D_SetQuadMin(x, y, lbl_8036B0C4, lbl_8036B0C4);
        Prim2D_SetQuadMax(x + tw * lbl_8036B0E0, y + th * lbl_8036B0E0, tw, th);
        rgb = (u8 *)&color;
        Prim2D_SetColor(rgb[0], rgb[1], rgb[2], 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B104);
    Prim2D_PrepareTex();

    pulse = fn_8022CB78(__mod2i(__div2i(OSGetTime(),
        (s64)((*(u32 *)0x800000F8 >> 2) / 1000)), (s64)1500));
    pulse = (f32)sin(lbl_8036B15C * (pulse / lbl_8036B158));
    alpha = (s32)(lbl_8036B160 + lbl_8036B114 * (lbl_8036B164 * (lbl_8036B0E0 + pulse)));

    for (i = 0; i < count; i++) {
        if (*(s32 *)(self + 0x64 + i * 0x10) != 0) {
            x = f3 + (f32)*(s16 *)(lbl_80297928 + 0x28 + i * 2);
            y = f4 + (f32)*(s16 *)(lbl_80297928 + 0x3C + i * 2);
            x -= lbl_8036B0F8;
            y += lbl_8036B168;
            color = *Ui_GetColor(0x18);
            tex = *(u16 **)fn_8006EDD8(texture, 6);
            tw = (f32)tex[1];
            th = (f32)tex[0];
            Prim2D_Begin();
            Prim2D_BindTexture(texture, 6, 0x11);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            x2 = x + lbl_8036B0C4 * (lbl_8036B114 * tw);
            y2 = y + lbl_8036B0C4 * (lbl_8036B114 * th);
            Prim2D_SetQuadMin(x2, y2, lbl_8036B0C4, lbl_8036B0C4);
            Prim2D_SetQuadMax(x2 + tw * lbl_8036B0E0, y2 + th * lbl_8036B0E0, tw, th);
            rgb = (u8 *)&color;
            Prim2D_SetColor(rgb[0], rgb[1], rgb[2], alpha);
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
        }
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B104);
    Prim2D_PrepareTex();

    scale = *(f32 *)(self + 0x104);
    if (scale < lbl_8036B16C) {
        lbl_80368244[0] = (s16)f1;
        lbl_80368244[1] = (s16)(f2 + lbl_8036B170 + lbl_8036B11C * (lbl_8036B0E0 - scale));
        lbl_80368244[2] = 0x120;
        lbl_80368244[3] = (s16)(lbl_8036B174 * scale);

        if (*(s32 *)(self + 0x10) == 1) {
            Prim2D_Begin();
            Prim2D_SetCallback(fn_801B6064, lbl_80368244);
            Prim2D_PrepareTex();
        }

        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();

        sprintf(buf, (char *)gUnitStatusStr + 0xD8, (s8)self[0x1C]);
        text = fn_800A8978(*(void **)(self + 0x108));
        fn_8001003C((s32)(f1 + lbl_8036B178), (s32)(f2 + lbl_8036B11C),
                       1, 1, 0, text, lbl_8036B0E0, lbl_8036B0C4);
        text = Msg_Expand(gUnitStatusStr + 0xDB);
        fn_8001003C((s32)(f1 + lbl_8036B17C), (s32)(f2 + lbl_8036B11C),
                       6, 1, 0, text, lbl_8036B0E0, lbl_8036B0C4);
        value = (s8)self[0x1C];
        extra = (value < 10) ? 10 : 0;
        fn_8001003C((s32)(f1 + lbl_8036B180 + (f32)extra), (s32)(f2 + lbl_8036B11C),
                       1, 1, 0, buf, lbl_8036B0E0, lbl_8036B0C4);

        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B10C);
        Prim2D_PrepareTex();
        widthDiff = (s16)(Text_MeasureWidth(buf, -1, *(f32 *)(self + 0x34)) -
                          Text_MeasureWidth(buf, -1, lbl_8036B0E0));
        heightDiff = (s16)(fn_80010770(buf, -1, *(f32 *)(self + 0x34)) -
                           fn_80010770(buf, -1, lbl_8036B0E0));
        fn_8001003C((s32)(f1 + lbl_8036B180 + (f32)extra - (f32)(widthDiff / 2)),
                       (s32)(f2 + lbl_8036B11C - (f32)(heightDiff / 2)),
                       1, 1, 0, buf, *(f32 *)(self + 0x34), lbl_8036B0C4);
        if (*(f32 *)(self + 0x34) > lbl_8036B0E0) {
            *(f32 *)(self + 0x34) -= lbl_8036B184;
            if (*(f32 *)(self + 0x34) < lbl_8036B0E0) {
                *(f32 *)(self + 0x34) = lbl_8036B0E0;
            }
        }
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B0D4);
        Prim2D_PrepareTex();
    }

    if (*(s32 *)(self + 0x10) == 1) {
        Prim2D_Begin();
        Prim2D_ClearCallbacks();
        Prim2D_PrepareTex();
    }

    for (i = 0; i < count; i++) {
        value = (s8)self[0x1D + i];
        extra = (s8)self[0x27 + i];
        if (*(s32 *)(self + 0x64 + i * 0x10) == 0) {
            Prim2D_Begin();
            Prim2D_SetTex(0, 0x13);
            Prim2D_PrepareTex();
            sprintf(buf, (char *)gUnitStatusStr + 0xD8, value);
            text = Msg_Expand(*(void **)(lbl_80297928 + i * 4));
            x = f3 + (f32)*(s16 *)(lbl_80297928 + 0x28 + i * 2);
            y = f4 + (f32)*(s16 *)(lbl_80297928 + 0x3C + i * 2);
            fn_8001003C((s32)x, (s32)y, 6, 1, 0, text, lbl_8036B0E0, lbl_8036B0C4);
            fn_8001003C((s32)(x + lbl_8036B178 + (f32)(value < 10 ? 10 : 0)),
                           (s32)y, 1, 1, 0, buf, lbl_8036B0E0, lbl_8036B0C4);
        } else {
            Prim2D_Begin();
            Prim2D_SetTex(0, 0x13);
            Prim2D_PrepareTex();
            value += extra;
            sprintf(buf, (char *)gUnitStatusStr + 0xD8, value);
            text = Msg_Expand(*(void **)(lbl_80297928 + i * 4));
            x = f3 + (f32)*(s16 *)(lbl_80297928 + 0x28 + i * 2);
            y = f4 + (f32)*(s16 *)(lbl_80297928 + 0x3C + i * 2);
            fn_8001003C((s32)x, (s32)y, 6, 1, 0, text, lbl_8036B0E0, lbl_8036B0C4);
            fn_8001003C((s32)(x + lbl_8036B178 + (f32)(value < 10 ? 10 : 0)),
                           (s32)y, 1, 1, 0, buf, lbl_8036B0E0, lbl_8036B0C4);

            Prim2D_Begin();
            Prim2D_AddZ(lbl_8036B10C);
            Prim2D_PrepareTex();
            scale = *(f32 *)(self + 0x38 + i * 0x10);
            widthDiff = (s16)(Text_MeasureWidth(buf, -1, scale) -
                              Text_MeasureWidth(buf, -1, lbl_8036B0E0));
            heightDiff = (s16)(fn_80010770(buf, -1, scale) -
                               fn_80010770(buf, -1, lbl_8036B0E0));
            fn_8001003C((s32)(x + lbl_8036B178 + (f32)(value < 10 ? 10 : 0) -
                              (f32)(widthDiff / 2)),
                           (s32)(y - (f32)(heightDiff / 2)),
                           1, 1, 0, buf, scale, lbl_8036B0C4);
            if (scale > lbl_8036B0E0) {
                scale -= lbl_8036B184;
                if (scale < lbl_8036B0E0) {
                    scale = lbl_8036B0E0;
                }
                *(f32 *)(self + 0x38 + i * 0x10) = scale;
            }
            Prim2D_Begin();
            Prim2D_AddZ(lbl_8036B0D4);
            Prim2D_PrepareTex();

            extra = (s8)self[0x27 + i];
            if (extra > 0) {
                x2 = x + lbl_8036B18C;
                y2 = y + lbl_8036B188;
                Prim2D_Begin();
                Prim2D_BindTexture(texture, 5, 0x11);
                Prim2D_PrepareTex();
                Prim2D_AddPrim(1);
                Prim2D_SetQuadMin((f32)(s16)(s32)x2, (f32)(s16)(s32)y2,
                                  lbl_8036B0C4, lbl_8036B0C4);
                Prim2D_SetQuadMax((f32)(s16)((s16)(s32)x2 + 14),
                                   (f32)(s16)((s16)(s32)y2 + 20),
                                   lbl_8036B0EC, lbl_8036B190);
                Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
                Prim2D_EmitQuad();
                Prim2D_EndPrim();

                Prim2D_AddPrim(1);
                Prim2D_SetQuadMin((f32)(s16)(s32)(x2 + lbl_8036B0EC),
                                  (f32)(s16)(s32)y2,
                                  (f32)(s16)((extra + 1) * 14), lbl_8036B0C4);
                Prim2D_SetQuadMax((f32)(s16)((s16)(s32)(x2 + lbl_8036B0EC) + 14),
                                   (f32)(s16)((extra + 1) * 14 + 14),
                                   (f32)(s16)((s16)(s32)y2 + 20), lbl_8036B190);
                Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
                Prim2D_EmitQuad();
                Prim2D_EndPrim();
            }
        }
    }

    period = (OSGetTick() / ((*(u32 *)0x800000F8 >> 2) / 1000)) % 450;
    for (i = 0; i < count; i++) {
        if (period <= 150) {
            *(f32 *)(self + 0x70 + i * 0x10) = Math_Ease(
                0, lbl_8036B0C4, lbl_8036B194, (f32)period, lbl_8036B198);
        } else {
            *(f32 *)(self + 0x70 + i * 0x10) = Math_Ease(
                0, lbl_8036B194, lbl_8036B0C4, (f32)(period - 150), lbl_8036B19C);
        }
    }
    *(s32 *)(self + 0x60) += 1;
    if (*(s32 *)(self + 0x60) > 16) {
        *(s32 *)(self + 0x60) = 0;
    }

    for (i = 0; i < count; i++) {
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B104);
        Prim2D_PrepareTex();
        if (*(s32 *)(self + 0x64 + i * 0x10) != 0) {
            x = f3 + (f32)*(s16 *)(lbl_80297928 + 0x28 + i * 2);
            y = f4 + (f32)*(s16 *)(lbl_80297928 + 0x3C + i * 2);
            x += lbl_8036B1A4 + *(f32 *)(self + 0x6C + i * 0x10) - lbl_8036B1A8;
            y += lbl_8036B1A0 + *(f32 *)(self + 0x70 + i * 0x10);
            color = *Ui_GetColor(1);
            tex = *(u16 **)fn_8006EDD8(texture, 0);
            tw = (f32)tex[1];
            th = (f32)tex[0];
            Prim2D_Begin();
            Prim2D_BindTexture(texture, 0, 0x11);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            x2 = x + lbl_8036B0C4 * (lbl_8036B114 * tw);
            y2 = y + lbl_8036B0C4 * (lbl_8036B114 * th);
            Prim2D_SetQuadMin(x2, y2, lbl_8036B0C4, lbl_8036B0C4);
            Prim2D_SetQuadMax(x2 + tw * lbl_8036B0E0, y2 + th * lbl_8036B0E0, tw, th);
            rgb = (u8 *)&color;
            Prim2D_SetColor(rgb[0], rgb[1], rgb[2], 0xFF);
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
        }
    }

    Prim2D_Begin();
    Prim2D_AddZ((f32)count);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B1AC);
    Prim2D_PrepareTex();
}

#pragma opt_common_subs off
void fn_801B5DB0(void *arg0) {
    s32 FileCache_GetFlags(void *);
    void fn_8006EEFC(void *, void *);
    s32 fn_8007C3BC(s32);
    u8 fn_8007C484(s32);
    extern u8 gUnitStatusStr[];
    u8 *temp_r31;

    temp_r31 = M2C_FIELD(arg0, u8 **, 0x30);
    if (FileCache_GetFlags(gUnitStatusStr + 0xE1) & 0x2000) {
        if (fn_8007C484(fn_8007C3BC(M2C_FIELD(temp_r31, s32 *, 0x110)))) {
            fn_8006EEFC(temp_r31 + 0x18, gUnitStatusStr + 0xE1);
            Process_ClearFunc(arg0);
        }
    }
}

void UnitStatus_Init(void *arg0) {
    /* Init unit status display from unit at +0x14: copy stats and resolve portrait sprite. */
    void *memset(void *, s32, s32);
    void fn_8005C8B4(void *);
    u8 Unit_GetHp(void *);
    u8 Unit_GetStr(void *);
    u8 Unit_GetMag(void *);
    u8 Unit_GetSkl(void *);
    u8 Unit_GetSpd(void *);
    u8 Unit_GetLck(void *);
    u8 Unit_GetDef(void *);
    u8 Unit_GetRes(void *);
    u8 Unit_GetCon(void *);
    u8 Unit_GetMov(void *);
    void fn_801B6BE4(void *);
    u8 Unit_MatchesId(void *, void *);
    void *fn_8003A064(void *);
    void *fn_8007C3BC(void *);
    void fn_8007C4D4(void *, s32);
    u8 fn_80028640(void);
    extern u8 gUnitStatusStr[];
    extern f32 lbl_8036B0E0;

    u8 growths[0x20];
    void *unit;
    f32 one;
    void *classKey;
    u8 b;

    unit = *(void **)((u8 *)arg0 + 0x14);
    *(s32 *)((u8 *)arg0 + 0x0) = 0;
    *(s32 *)((u8 *)arg0 + 0x4) = 0;
    *(s32 *)((u8 *)arg0 + 0x8) = 0;
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(s32 *)((u8 *)arg0 + 0x108) = *(s32 *)((u8 *)unit + 0x18C);
    *(f32 *)((u8 *)arg0 + 0x104) = 1.0f;
    *(s32 *)((u8 *)arg0 + 0x60) = 0;
    memset((u8 *)arg0 + 0x64, 0, 0xA0);
    fn_8005C8B4(gUnitStatusStr + 0xE1);
    *(u8 *)((u8 *)arg0 + 0x1C) = *(u8 *)((u8 *)unit + 0x19A);
    *(u8 *)((u8 *)arg0 + 0x1D) = Unit_GetHp(unit);
    *(u8 *)((u8 *)arg0 + 0x1E) = Unit_GetStr(unit);
    *(u8 *)((u8 *)arg0 + 0x1F) = Unit_GetMag(unit);
    *(u8 *)((u8 *)arg0 + 0x20) = Unit_GetSkl(unit);
    *(u8 *)((u8 *)arg0 + 0x21) = Unit_GetSpd(unit);
    *(u8 *)((u8 *)arg0 + 0x22) = Unit_GetLck(unit);
    *(u8 *)((u8 *)arg0 + 0x23) = Unit_GetDef(unit);
    *(u8 *)((u8 *)arg0 + 0x24) = Unit_GetRes(unit);
    *(u8 *)((u8 *)arg0 + 0x25) = Unit_GetCon(unit);
    *(u8 *)((u8 *)arg0 + 0x26) = Unit_GetMov(unit);
    fn_801B6BE4(growths);
    b = growths[0xA];
    one = (classKey = gUnitStatusStr, 1.0f);
    *(u8 *)((u8 *)arg0 + 0x27) = b;
    classKey = (u8 *)classKey + 0xF2;
    *(u8 *)((u8 *)arg0 + 0x28) = growths[0xB];
    *(u8 *)((u8 *)arg0 + 0x29) = growths[0xC];
    *(u8 *)((u8 *)arg0 + 0x2A) = growths[0xD];
    *(u8 *)((u8 *)arg0 + 0x2B) = growths[0xE];
    *(u8 *)((u8 *)arg0 + 0x2C) = growths[0xF];
    *(u8 *)((u8 *)arg0 + 0x2D) = growths[0x10];
    *(u8 *)((u8 *)arg0 + 0x2E) = growths[0x11];
    *(u8 *)((u8 *)arg0 + 0x2F) = growths[0x12];
    *(u8 *)((u8 *)arg0 + 0x30) = growths[0x13];
    *(f32 *)((u8 *)arg0 + 0x34) = one;
    *(f32 *)((u8 *)arg0 + 0x38) = one;
    *(f32 *)((u8 *)arg0 + 0x3C) = one;
    *(f32 *)((u8 *)arg0 + 0x40) = one;
    *(f32 *)((u8 *)arg0 + 0x44) = one;
    *(f32 *)((u8 *)arg0 + 0x48) = one;
    *(f32 *)((u8 *)arg0 + 0x4C) = one;
    *(f32 *)((u8 *)arg0 + 0x50) = one;
    *(f32 *)((u8 *)arg0 + 0x54) = one;
    *(f32 *)((u8 *)arg0 + 0x58) = one;
    *(f32 *)((u8 *)arg0 + 0x5C) = one;
    if (Unit_MatchesId(*(void **)((u8 *)arg0 + 0x14), classKey) != 0 && *(s32 *)((u8 *)arg0 + 0x10) == 1) {
        *(void **)((u8 *)arg0 + 0x110) = gUnitStatusStr + 0xFA;
    } else if (Unit_MatchesId(*(void **)((u8 *)arg0 + 0x14), gUnitStatusStr + 0x105) != 0 && *(s32 *)((u8 *)arg0 + 0x10) == 1) {
        *(void **)((u8 *)arg0 + 0x110) = gUnitStatusStr + 0x10E;
    } else {
        *(void **)((u8 *)arg0 + 0x110) = fn_8003A064(*(void **)((u8 *)arg0 + 0x14));
    }
    fn_8007C4D4(fn_8007C3BC(*(void **)((u8 *)arg0 + 0x110)), 0);
    if (fn_80028640() != 0) {
        *(u8 *)((u8 *)arg0 + 0x10C) = 1;
    } else {
        *(u8 *)((u8 *)arg0 + 0x10C) = 0;
    }
}

void fn_801B6064(s32 unused, s16 *p) {
    extern void GXSetScissor(s16, s16, s16, s16);
    GXSetScissor(p[0], p[1], p[2], p[3]);
}

#pragma opt_common_subs reset

s32 fn_801B6098(void *arg0)
{
    void fn_801B32C8(void *, void *);
    extern u8 gBattle[];
    u32 flags = *(u32 *)(gBattle + 0xCAC);
    u8 enabled;
    if ((flags >> 4) & 1) enabled = 0;
    else if (flags & 0x800) enabled = 1;
    else enabled = 0;
    if (!enabled) return 0;
    fn_801B32C8(Battle_FindActiveSideUnit(), arg0);
    return 1;
}

s32 fn_801B6164(u32 arg0) {
    void *Process_CreateChild(void *, u32);
    void *Process_Create(void *, s32);
    extern u8 lbl_80297AC8[];
    extern u8 gBattle[];

    if (!(M2C_FIELD(gBattle, s32 *, 0xCAC) & 0x400)) {
        return 0;
    }
    if (arg0 == 0) {
        Process_Create(lbl_80297AC8, 3);
    } else {
        Process_CreateChild(lbl_80297AC8, arg0);
    }
    return 1;
}

s32 Battle_TryStartGrowSeq(u32 parent) {
    /* If battle has exp/level-up/max-level flags, start E_GrowSeq (standalone or as child). */
    void Process_CreateChild(void *, u32);
    void Process_Create(void *, s32);
    extern u8 Proc_E_GrowSeq[];
    extern u8 gBattle[];
    u32 flags;
    u32 maxLevelBit;
    u8 leveledUp;
    u8 shouldStart;

    flags = *(u32 *)((u8 *)gBattle + 0xCAC);
    maxLevelBit = flags & 0x10;
    if ((flags >> 4) & 1) {
        leveledUp = 0;
    } else if (flags & 0x800) {
        leveledUp = 1;
    } else {
        leveledUp = 0;
    }
    if (leveledUp != 0) {
        shouldStart = 1;
    } else if (flags & 0x400) {
        shouldStart = 1;
    } else if (maxLevelBit != 0) {
        shouldStart = 1;
    } else {
        shouldStart = 0;
    }
    if (shouldStart == 0) {
        return 0;
    }
    if (parent == 0) {
        Process_Create(Proc_E_GrowSeq, 3);
    } else {
        Process_CreateChild(Proc_E_GrowSeq, parent);
    }
    return 1;
}

void fn_801B6290(void *arg0) {
    u8 fn_800AA188(void);
    void fn_8004BE88(void *, s32);
    void fn_8000C070(void *, s32);
    extern u8 lbl_80330EAC[];
    u8 byte;
    void *obj;
    void *sub;

    if (fn_800AA188() != 0) {
        obj = *(void **)(lbl_80330EAC + 0x280);
        if (obj != NULL) {
            sub = *(void **)((u8 *)obj + 0x190);
            byte = *(u8 *)((u8 *)sub + 8);
            if (byte != 0 && byte != 5) {
                goto try_second;
            }
        } else {
        try_second:
            obj = *(void **)(lbl_80330EAC + 0x560);
            if (obj != NULL) {
                sub = *(void **)((u8 *)obj + 0x190);
                byte = *(u8 *)((u8 *)sub + 8);
                if (byte != 0 && byte != 5) {
                    goto set_null;
                }
            } else {
            set_null:
                obj = NULL;
            }
        }
        if (obj != NULL) {
            fn_8004BE88(obj, 0);
        }
    } else {
        fn_8000C070(arg0, 0);
    }
}

#pragma opt_common_subs off
s32 fn_801B6348(void *arg0)
{
    void fn_801B32C8(void *, void *);
    extern u8 gBattle[];
    u32 flags = *(u32 *)(gBattle + 0xCAC);
    u8 enabled;
    if ((flags >> 4) & 1) enabled = 0;
    else if (flags & 0x800) enabled = 1;
    else enabled = 0;
    if (!enabled) return 0;
    fn_801B32C8(Battle_FindActiveSideUnit(), arg0);
    return 1;
}
#pragma opt_common_subs reset
s32 fn_801B6414(u32 arg0) {
    void *Process_CreateChild(void *, u32);
    void *Process_Create(void *, s32);
    extern u8 lbl_80297AC8[];
    extern u8 gBattle[];

    if (!(M2C_FIELD(gBattle, s32 *, 0xCAC) & 0x400)) {
        return 0;
    }
    if (arg0 == 0) {
        Process_Create(lbl_80297AC8, 3);
    } else {
        Process_CreateChild(lbl_80297AC8, arg0);
    }
    return 1;
}

void fn_801B647C(void *arg0) {
    void *fn_8005381C(void *, void *);
    void Effect_SetPos(void *, f32, f32, f32);
    void Ui_PlaySeCue(void *, s32);
    void fn_8014876C(void *, s32, s32);
    extern u8 gBattle[];
    extern u8 lbl_8027C248[];
    extern u8 gFxChannels[];
    extern f32 lbl_8036B1B0;
    extern f32 lbl_8036B1B4;
    extern f32 lbl_8036B1B8;

    if (*(u32 *)(gBattle + 0xCAC) & 0x10) {
        Effect_SetPos(fn_8005381C(lbl_8027C248 + 0xE4, arg0), lbl_8036B1B0, lbl_8036B1B4, lbl_8036B1B8);
        Ui_PlaySeCue(lbl_8027C248 + 0xF1, 0x64);
        fn_8014876C(gFxChannels + ((u8 *)arg0)[0x3A] * 0x30, 0x32, 0xFA);
    }
}

void fn_801B6510(void *arg0) {
    void fn_8006D8E8(void *);
    void fn_8014876C(void *, s32, s32);
    extern u8 gBattle[];
    extern u8 gFxChannels[];
    void *p;

    p = *(void **)((u8 *)arg0 + 0x40);
    if (p != NULL) {
        fn_8006D8E8(p);
    }
    if (*(u32 *)(gBattle + 0xCAC) & 0x10) {
        fn_8014876C(gFxChannels + ((u8 *)arg0)[0x3A] * 0x30, 0x64, 0x3E8);
    }
}

void fn_801B657C(void *arg0) {
    f32 Math_Lerp(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    u16 old;

    old = *(u16 *)((u8 *)arg0 + 0x3C);
    *(u16 *)((u8 *)arg0 + 0x3C) = (u16)(old + 1);
    *(u8 *)((u8 *)arg0 + 0x39) = (u8)(s32)Math_Lerp(old, 0.0f, 255.0f, 8.0f, (f32)*(u16 *)((u8 *)arg0 + 0x3C));
    if (*(u16 *)((u8 *)arg0 + 0x3C) == 8) {
        Process_ClearFunc(arg0);
    }
}

void fn_801B6600(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x3C) = 0;
}

/* Advance the EXP bar fill: lerp displayed EXP, play a tick SE on odd frames, clear when finished. */
void Ui_ExpBarFillProc(void *proc) {
    f32 Math_Lerp(f32, f32, f32, f32);
    void Ui_PlaySeCue(void *, s32);
    void Process_ClearFunc(void *);
    extern u8 lbl_8027C248[];
    s16 frames;
    s16 startExp;

    *(u16 *)((u8 *)proc + 0x3C) = (u16)(*(u16 *)((u8 *)proc + 0x3C) + 1);
    frames = *(s16 *)((u8 *)proc + 0x4A);
    startExp = *(s16 *)((u8 *)proc + 0x48);
    *(s16 *)((u8 *)proc + 0x3E) = (s16)Math_Lerp((f32)startExp, (f32)(startExp + frames), (f32)frames, (f32)*(u16 *)((u8 *)proc + 0x3C));
    if (*(u16 *)((u8 *)proc + 0x3C) & 1) {
        Ui_PlaySeCue(lbl_8027C248 + 0x102, 0x64);
    }
    if ((s32)*(u16 *)((u8 *)proc + 0x3C) == *(s16 *)((u8 *)proc + 0x4A)) {
        Process_ClearFunc(proc);
    }
}

void fn_801B66F4(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x3C) = 0;
}

void fn_801B6700(void *arg0) {
    f32 Math_Lerp(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    u16 old;

    old = *(u16 *)((u8 *)arg0 + 0x3C);
    *(u16 *)((u8 *)arg0 + 0x3C) = (u16)(old + 1);
    *(u8 *)((u8 *)arg0 + 0x39) = (u8)(s32)Math_Lerp(old, 0.0f, 255.0f, 8.0f, (f32)*(u16 *)((u8 *)arg0 + 0x3C));
    if (*(u16 *)((u8 *)arg0 + 0x3C) == 8) {
        Process_ClearFunc(arg0);
    }
}

void fn_801B6784(void *arg0) {
    s32 fn_8006D948(void *);
    void Process_AttachFunc(void *, void *);
    void Ui_DrawExpBar(void);
    extern u8 lbl_8027C248[];

    M2C_FIELD(arg0, s32 *, 0x40) = fn_8006D948(lbl_8027C248 + 0x114);
    Process_AttachFunc(Ui_DrawExpBar, arg0);
}

#pragma global_optimizer off
#pragma opt_common_subs off
void fn_801B67D0(u8 *out) {
extern u8 gBattle[];
extern u8 lbl_8027C248[];
void Process_Goto(void *,s32);
u8 fn_80028640(void);
void fn_8005C8B4(void *);
void fn_800340E4(void *);
void fn_801B6DAC(u8 *);
u8 *unit;
u8 *p;
u8 *arg0=out;
s32 count;
s16 saved;
u32 off;
u8 type;
unit=Battle_FindActiveSideUnit();
found:
*(u8 **)(arg0+0x44)=unit;
count=0;
p=gBattle+0x8A0;
saved=*(s16 *)p;
fn_800340E4(p);
for(;;) {
off=*(s16 *)p*4;
switch(*(u8 *)(p+off+4)) { case 0: goto done1; case 0x29: count++; break; }
*(s16 *)p+=1;
}
done1:
*(s16 *)p=saved;
arg0[0x4c]=count;
{ s32 value=0; s16 saved2=*(s16 *)p;
fn_800340E4(p);
for(;;) {
off=*(s16 *)p*4;
switch(*(u8 *)(p+off+4)) { case 0: goto done2; case 0x27: value=(s8)*(s16 *)(p+off+6); break; }
*(s16 *)p+=1;
}
done2:
*(s16 *)p=saved2;
*(s16 *)(arg0+0x48)=value;
}
count=0;
saved=*(s16 *)p;
fn_800340E4(p);
for(;;) {
off=*(s16 *)p*4;
switch(*(u8 *)(p+off+4)) { case 0: goto done3; case 0x28: count=(s8)*(s16 *)(p+off+6); break; }
*(s16 *)p+=1;
}
done3:
*(s16 *)p=saved;
*(s16 *)(arg0+0x4a)=count;
fn_801B6DAC(arg0+0x4e);
if (*(s16 *)(arg0+0x4a)==0) Process_Goto(arg0,0x63);
else {
*(s16 *)(arg0+0x3e)=*(s16 *)(arg0+0x48);
*(s16 *)(arg0+0x3c)=0;
arg0[0x39]=0;
*(s32 *)(arg0+0x40)=0;
if (fn_80028640()) arg0[0x3a]=1; else arg0[0x3a]=0;
fn_8005C8B4(lbl_8027C248+0x114);
}
}
#pragma opt_common_subs reset
#pragma global_optimizer reset
void Ui_DrawExpBar(void *bar) {
    void Prim2D_EmitQuad(void);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_ResetState(void);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_BindTexture(void *, s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void fn_8005926C(s32, s32, s32, s32, s32, s32, s32, s32);
    extern f32 lbl_8036B1B8;
    extern f64 lbl_8036B1D0;
    extern f32 lbl_8036B1DC;
    extern f32 lbl_8036B1E0;
    extern f32 lbl_8036B1E4;
    extern f32 lbl_8036B1E8;
    extern f32 lbl_8036B1EC;
    extern f32 lbl_8036B1F0;
    extern f32 lbl_8036B1F4;
    extern f32 lbl_8036B1F8;
    extern f32 lbl_8036B1FC;
    extern f32 lbl_8036B200;
    extern f32 lbl_8036B204;
    s32 expPct;
    s32 barW;
    u16 exp;

    // Draw EXP digits and a fill bar for the current EXP percent (0-99).
    exp = *(u16 *)((u8 *)bar + 0x3E);
    expPct = exp % 100;
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B1DC, lbl_8036B1E0, lbl_8036B1E4, lbl_8036B1E8);
    Prim2D_BindTexture(*(void **)((u8 *)bar + 0x40), 2, 0x11);
    Prim2D_SetColorByte(*(u8 *)((u8 *)bar + 0x39));
    Prim2D_PrepareTex();
    fn_8005926C(0, 0, 0, 0, 0x13, 0x14, 0xF, expPct);
    barW = (expPct * 0xAF) / 100;
    if (expPct > 0 && barW < 2) {
        barW = 2;
    }
    if (barW > 0) {
        Prim2D_Begin();
        Prim2D_SetTransform(lbl_8036B1EC, lbl_8036B1F0, lbl_8036B1E4, lbl_8036B1E8);
        Prim2D_BindTexture(*(void **)((u8 *)bar + 0x40), 1, 0x11);
        Prim2D_SetColorByte(*(u8 *)((u8 *)bar + 0x39));
        Prim2D_PrepareTex();
        Prim2D_AddPrim(2);
        Prim2D_SetRectUv(lbl_8036B1B8, lbl_8036B1B8, lbl_8036B1B8, lbl_8036B1B8, (f32)barW, lbl_8036B1F4);
        Prim2D_EmitQuad();
        Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
        Prim2D_EndPrim();
    }
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B1F8, lbl_8036B1FC, lbl_8036B1E4, lbl_8036B1E8);
    Prim2D_BindTexture(*(void **)((u8 *)bar + 0x40), 0, 0x11);
    Prim2D_SetColorByte(*(u8 *)((u8 *)bar + 0x39));
    Prim2D_PrepareTex();
    Prim2D_AddPrim(2);
    Prim2D_SetRectUv(lbl_8036B1B8, lbl_8036B1B8, lbl_8036B1B8, lbl_8036B1B8, lbl_8036B200, lbl_8036B204);
    Prim2D_EmitQuad();
    Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
    Prim2D_EndPrim();
    Prim2D_ResetState();
}

#pragma global_optimizer off
void fn_801B6BE4(u8 *out) {
extern u8 gBattle[];
void fn_800340E4(void *);
void fn_801B6DAC(u8 *);
u8 *unit;
u8 *p;
u8 *arg0=out;
s8 count;
s16 saved;
u32 off;
u8 type;
unit=*(u8 **)(gBattle+0x280);
if (unit && ((type=(*(u8 **)(unit+0x190))[8])==0 || type==5)) {
} else {
unit=*(u8 **)(gBattle+0x560);
if (unit && ((type=(*(u8 **)(unit+0x190))[8])==0 || type==5)) {
} else unit=0;
}
found:
*(u8 **)arg0=unit;
count=0;
p=gBattle+0x8A0;
saved=*(s16 *)p;
fn_800340E4(p);
for(;;) {
off=*(s16 *)p*4;
switch(*(u8 *)(p+off+4)) { case 0: goto done1; case 0x29: count++; break; }
*(s16 *)p+=1;
}
done1:
*(s16 *)p=saved;
arg0[8]=count;
{ s8 value=0; s16 saved2=*(s16 *)p;
fn_800340E4(p);
for(;;) {
off=*(s16 *)p*4;
switch(*(u8 *)(p+off+4)) { case 0: goto done2; case 0x27: value=(s8)*(s16 *)(p+off+6); break; }
*(s16 *)p+=1;
}
done2:
*(s16 *)p=saved2;
*(s16 *)(arg0+4)=value;
}
count=0;
saved=*(s16 *)p;
fn_800340E4(p);
for(;;) {
off=*(s16 *)p*4;
switch(*(u8 *)(p+off+4)) { case 0: goto done3; case 0x28: count=(s8)*(s16 *)(p+off+6); break; }
*(s16 *)p+=1;
}
done3:
*(s16 *)p=saved;
*(s16 *)(arg0+6)=count;
fn_801B6DAC(arg0+10);
}
#pragma global_optimizer reset
#pragma global_optimizer off
void fn_801B6DAC(u8 *arg0) {
    extern u8 gBattle[];
    void fn_800340E4(void *);
    s16 saved = *(s16 *)(gBattle + 0x8A0);
    u8 *p = gBattle + 0x8A0;
    u32 off;
    u8 type;
    fn_800340E4(p);
    arg0[0] = 0; arg0[1] = 0; arg0[2] = 0; arg0[3] = 0; arg0[4] = 0;
    arg0[5] = 0; arg0[6] = 0; arg0[7] = 0; arg0[8] = 0; arg0[9] = 0;
    for (;;) {
        off = *(s16 *)p * 4;
        type = *(u8 *)(p + off + 4);
        switch (type) {
        case 0: goto done;
        case 0x2A: arg0[0] = *(s16 *)(p + off + 6); break;
        case 0x2B: arg0[1] = *(s16 *)(p + off + 6); break;
        case 0x2C: arg0[2] = *(s16 *)(p + off + 6); break;
        case 0x2D: arg0[3] = *(s16 *)(p + off + 6); break;
        case 0x2E: arg0[4] = *(s16 *)(p + off + 6); break;
        case 0x2F: arg0[5] = *(s16 *)(p + off + 6); break;
        case 0x30: arg0[6] = *(s16 *)(p + off + 6); break;
        case 0x31: arg0[7] = *(s16 *)(p + off + 6); break;
        case 0x32: arg0[9] = *(s16 *)(p + off + 6); break;
        case 0x33: arg0[8] = *(s16 *)(p + off + 6); break;
        }
        *(s16 *)p = *(s16 *)p + 1;
    }
done:
    *(s16 *)p = saved;
}
#pragma global_optimizer reset
void Script_RegisterWinCondCommands(void) {
    /* Register chapter win/lose condition script command handlers. */
    void Script_RegisterCommand(void *, void *, s32);
    extern u8 gWinCondCmdNames[];
    void ScriptCmd_AchieveSet(void);
    void ScriptCmd_PlayerDeadCheck(void);
    void ScriptCmd_EnemyDeadCheck(void);
    void ScriptCmd_EnemyUnitCheckByPID(void);
    void ScriptCmd_EnemyMonkCheck(void);
    void ScriptCmd_EnemySelfDefenceCheck(void);
    void ScriptCmd_EnemyTigerCheck(void);
    void ScriptCmd_PlayerEscapeCheck(void);
    void ScriptCmd_PlayerEscapeCount(void);
    void ScriptCmd_ShooterBulletCheck(void);
    void ScriptCmd_GetDiedPlayerCount(void);

    Script_RegisterCommand(gWinCondCmdNames + 0xCE, ScriptCmd_AchieveSet, 2);
    Script_RegisterCommand(gWinCondCmdNames + 0xD9, ScriptCmd_PlayerDeadCheck, 0);
    Script_RegisterCommand(gWinCondCmdNames + 0xE9, ScriptCmd_EnemyDeadCheck, 0);
    Script_RegisterCommand(gWinCondCmdNames + 0xF8, ScriptCmd_EnemyUnitCheckByPID, 1);
    Script_RegisterCommand(gWinCondCmdNames + 0x10C, ScriptCmd_EnemyMonkCheck, 0);
    Script_RegisterCommand(gWinCondCmdNames + 0x11B, ScriptCmd_EnemySelfDefenceCheck, 0);
    Script_RegisterCommand(gWinCondCmdNames + 0x131, ScriptCmd_EnemyTigerCheck, 0);
    Script_RegisterCommand(gWinCondCmdNames + 0x141, ScriptCmd_PlayerEscapeCheck, 0);
    Script_RegisterCommand(gWinCondCmdNames + 0x153, ScriptCmd_PlayerEscapeCount, 0);
    Script_RegisterCommand(gWinCondCmdNames + 0x165, ScriptCmd_ShooterBulletCheck, 0);
    Script_RegisterCommand(gWinCondCmdNames + 0x178, ScriptCmd_GetDiedPlayerCount, 0);
}

s32 ScriptCmd_GetDiedPlayerCount(void) {
    extern u16 gUnitLists[50];
    s32 count;
    s32 flags;
    void *p;

    count = 0;
    p = M2C_FIELD(gUnitLists, void **, 0x48);
    while (p != NULL) {
        flags = M2C_FIELD(p, s32 *, 0x1A0);
        p = M2C_FIELD(p, void **, 0x184);
        if (flags & 0x8000) {
            count++;
        }
    }
    return count;
}

#pragma use_lmw_stmw on
s32 ScriptCmd_ShooterBulletCheck(void) {
    void DebugPrint(void *, ...);
    void *MapObjEvent_Find(void *, s8, s8, s32);
    extern u8 gWinCondCmdNames[];
    extern u8 gBattleMap[];
    extern u8 gMapObjEventList[];
    void *table;
    u8 *map;
    s32 sum;
    s32 y;
    s32 x;
    void *tmp;

    sum = 0;
    DebugPrint(gWinCondCmdNames + 0x18B);
    map = gBattleMap;
    y = (s8)map[9];
    table = gMapObjEventList;
    for (; y <= (s8)map[0xB] - 1; y++) {
        for (x = (s8)map[8]; x <= (s8)map[0xA] - 1; x++) {
            tmp = MapObjEvent_Find(table, (s8)x, (s8)y, 7);
            if (tmp != NULL) {
                sum += 5 - ((u8 *)tmp)[5];
            }
        }
    }
    return sum;
}

s32 ScriptCmd_PlayerEscapeCount(void) {
    /* Count player-faction units that have already escaped (stateFlags 0x4000). */
    void DebugPrint(const char *, ...);
    void Allegiance_SetMask(s32, s32, s32, s32, s32, s32, s32, s32, void *);
    extern u8 gWinCondCmdNames[];
    extern u8 gUnits[];
    u8 allegMask[8];
    u8 *unit;
    s32 count;
    s32 i;

    count = 0;
    DebugPrint((const char *)(gWinCondCmdNames + 0x19C));
    Allegiance_SetMask(1, 0, 0, 0, 0, 1, 0, 0, allegMask);
    for (i = 1; i <= 0x9F; i++) {
        if ((u8)i != 0) {
            unit = gUnits + ((u8)i - 1) * 0x280;
        } else {
            unit = NULL;
        }
        if (*(u32 *)(unit + 0x188) != 0
            && allegMask[*(u8 *)(*(u8 **)(unit + 0x190) + 8)] != 0
            && (*(u32 *)(unit + 0x1A0) & 0x4000)) {
            count += 1;
        }
    }
    return count;
}

/* Return 1 if every player/faction-5 unit has escaped (stateFlags 0x4000); else 0. */
s32 ScriptCmd_PlayerEscapeCheck(void) {
    void DebugPrint(const char *, ...);
    void Allegiance_SetMask(s32, s32, s32, s32, s32, s32, s32, s32, void *);
    extern u8 gWinCondCmdNames[];
    extern u8 gUnits[];
    u8 allegMask[8];
    u8 *unit;
    s32 i;

    DebugPrint((const char *)(gWinCondCmdNames + 0x19C));
    Allegiance_SetMask(1, 0, 0, 0, 0, 1, 0, 0, allegMask);
    for (i = 1; i <= 0x9F; i++) {
        if ((u8)i != 0) {
            unit = gUnits + ((u8)i - 1) * 0x280;
        } else {
            unit = NULL;
        }
        if (*(u32 *)(unit + 0x188) != 0
            && allegMask[*(u8 *)(*(u8 **)(unit + 0x190) + 8)] != 0
            && !(*(u32 *)(unit + 0x1A0) & 0x4000)) {
            return 0;
        }
    }
    return 1;
}

#pragma use_lmw_stmw reset
s32 ScriptCmd_EnemyTigerCheck(void) {
    void DebugPrint(void *, ...);
    s32 Str_Cmp(void *, void *);
    extern u8 gWinCondCmdNames[];
    extern u8 gUnitLists[];
    u8 *base;
    void *next;
    s32 count;
    void *node;

    count = 0;
    DebugPrint(gWinCondCmdNames + 0x1A9);
    node = *(void **)(gUnitLists + 0xC);
    base = gWinCondCmdNames;
    while (node != NULL) {
        next = *(void **)((u8 *)node + 0x184);
        if (Str_Cmp(*(void **)(*(void **)((u8 *)node + 0x18C)), base + 0x1B0) == 0) {
            count += 1;
        }
        node = next;
    }
    DebugPrint(gWinCondCmdNames + 0x1BA, count);
    return count;
}

s32 ScriptCmd_EnemySelfDefenceCheck(void) {
    void DebugPrint(void *, ...);
    s32 Str_Cmp(void *, void *);
    extern u8 gWinCondCmdNames[];
    extern u8 gUnitLists[];
    u8 *base;
    void *next;
    s32 count;
    void *node;

    count = 0;
    DebugPrint(gWinCondCmdNames + 0x1C0);
    node = *(void **)(gUnitLists + 0xC);
    base = gWinCondCmdNames;
    while (node != NULL) {
        next = *(void **)((u8 *)node + 0x184);
        if (Str_Cmp(*(void **)(*(void **)((u8 *)node + 0x188)), base + 0x1CB) == 0) {
            count += 1;
        }
        node = next;
    }
    DebugPrint(gWinCondCmdNames + 0x1DE, count);
    return count;
}

/* Count enemy units whose job JID is Priest, Bishop, or Saint. */
s32 ScriptCmd_EnemyMonkCheck(void) {
    void DebugPrint(void *, ...);
    s32 Str_Cmp(void *, void *);
    extern u8 gWinCondCmdNames[];
    extern u8 gUnitLists[];
    u8 *names;
    void *next;
    void *job;
    s32 count;
    void *unit;

    count = 0;
    DebugPrint(gWinCondCmdNames + 0x1E8);
    unit = *(void **)(gUnitLists + 0xC);
    names = gWinCondCmdNames;
    while (unit != NULL) {
        job = *(void **)((u8 *)unit + 0x18C);
        next = *(void **)((u8 *)unit + 0x184);
        if (Str_Cmp(*(void **)job, names + 0x1F1) == 0
            || Str_Cmp(*(void **)job, names + 0x1FC) == 0
            || Str_Cmp(*(void **)job, names + 0x207) == 0) {
            count += 1;
        }
        unit = next;
    }
    DebugPrint(gWinCondCmdNames + 0x214, count);
    return count;
}

s32 ScriptCmd_EnemyUnitCheckByPID(void *arg0) {
    void DebugPrint(void *, ...);
    s32 Str_Cmp(void *, void *);
    extern u8 gWinCondCmdNames[];
    extern u8 gUnitLists[];
    void *next;
    s32 count;
    void *node;

    count = 0;
    DebugPrint(gWinCondCmdNames + 0x21C);
    node = *(void **)(gUnitLists + 0xC);
    while (node != NULL) {
        next = *(void **)((u8 *)node + 0x184);
        if (Str_Cmp(*(void **)(*(void **)((u8 *)node + 0x188)), arg0) == 0) {
            count += 1;
        }
        node = next;
    }
    return count;
}

s32 ScriptCmd_EnemyDeadCheck(void)
{
    void DebugPrint(const char *, ...);
    extern u8 gWinCondCmdNames[];
    extern u8 gUnitLists[];

    DebugPrint((char *)gWinCondCmdNames + 0x225);
    return *(s32 *)(gUnitLists + 0xC) == 0;
}

s32 ScriptCmd_PlayerDeadCheck(void)
{
    void DebugPrint(const char *, ...);
    extern u8 gWinCondCmdNames[];
    extern u8 gUnitLists[];

    DebugPrint((char *)gWinCondCmdNames + 0x22e);
    return *(s32 *)(gUnitLists + 0x48) == 0;
}

s32 AchieveList_GetTotalGold(void *arg0) {
    s32 var_r8;
    s32 temp_r4;
    s32 temp_r6;
    s32 temp_r0;
    s32 var_r5;
    s32 var_r6;
    s32 var_ctr;
    void *var_r7;

    var_r8 = *(s32 *)((char *)arg0 + 0x224);
    var_r6 = 0;
    var_r5 = 0;
    
    if (var_r8 > 0) {
        temp_r4 = var_r8 - 8;
        
        if (var_r8 <= 8) {
            goto skip_loop1;
        }
        
        var_r7 = arg0;
        var_ctr = ((temp_r4 + 7) >> 3);
        
        do {
            var_r5 += 8;
            temp_r0 = *(s32 *)((char *)var_r7 + 0x21C);
            temp_r6 = var_r6 + *(s32 *)((char *)var_r7 + 0x200) 
                      + *(s32 *)((char *)var_r7 + 0x204)
                      + *(s32 *)((char *)var_r7 + 0x208)
                      + *(s32 *)((char *)var_r7 + 0x20C)
                      + *(s32 *)((char *)var_r7 + 0x210)
                      + *(s32 *)((char *)var_r7 + 0x214)
                      + *(s32 *)((char *)var_r7 + 0x218);
            var_r7 = (char *)var_r7 + 0x20;
            var_r6 = temp_r6 + temp_r0;
            var_ctr--;
        } while (var_ctr != 0);
        
skip_loop1:
        temp_r4 = var_r8 - var_r5;
        if (temp_r4 > 0) {
            s32 *var_r4_ptr = (s32 *)((char *)arg0 + (var_r5 * 4));
            
            do {
                temp_r0 = *var_r4_ptr;
                var_r4_ptr++;
                var_r6 += temp_r0;
                temp_r4--;
            } while (temp_r4 != 0);
        }
    }
    
    return *(s32 *)((char *)arg0 + 0x228) + var_r6;
}

s32 AchieveList_SumBonuses(void *arg0) {
    s32 n;
    s32 sum;
    s32 i;
    s32 rem;
    s32 ctr;
    u8 *p;
    s32 t0;
    s32 t1;

    n = *(s32 *)((u8 *)arg0 + 0x224);
    sum = 0;
    i = 0;
    if (n > 0) {
        rem = n - 8;
        if (n > 8) {
            p = arg0;
            ctr = (u32)(rem + 7) >> 3;
            if (rem > 0) {
                do {
                    t0 = *(s32 *)(p + 0x200);
                    i += 8;
                    t1 = *(s32 *)(p + 0x204);
                    sum += t0;
                    t0 = *(s32 *)(p + 0x208);
                    sum += t1;
                    t1 = *(s32 *)(p + 0x20C);
                    sum += t0;
                    t0 = *(s32 *)(p + 0x210);
                    sum += t1;
                    t1 = *(s32 *)(p + 0x214);
                    sum += t0;
                    t0 = *(s32 *)(p + 0x218);
                    sum += t1;
                    t1 = *(s32 *)(p + 0x21C);
                    sum += t0;
                    p += 0x20;
                    sum += t1;
                } while (--ctr);
            }
        }
        p = (u8 *)arg0 + (i << 2);
        ctr = n - i;
        if (i < n) {
            do {
                t0 = *(s32 *)(p + 0x200);
                p += 4;
                sum += t0;
            } while (--ctr);
        }
    }
    return sum;
}

void AchieveList_SetBaseGold(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x228) = arg1;
}

void fn_801B77F0(s32 arg0, s32 arg1) {
    M2C_UNK Msg_Expand(s32);
    Msg_Expand(arg0 + (arg1 << 6));
}

#pragma opt_strength_reduction off
s32 ScriptCmd_AchieveSet(s32 arg0, s32 arg1) {
    void strcpy(char *, char *);
    extern u8 gBattleState[];
    extern s32 lbl_80368250;
    extern s32 lbl_80368254;
    s32 var_r31;
    u8 *p;
    u8 v;

    var_r31 = arg1;
    strcpy((char *)(lbl_80368254 + (lbl_80368250 << 6)), (char *)arg0);
    v = gBattleState[0xA6];
    if (v == 2) {
        var_r31 /= 2;
    }
    if (v == 3) {
        var_r31 += var_r31 / 2;
    }
    p = (u8 *)lbl_80368254;
    p += lbl_80368250 << 2;
    *(s32 *)(p + 0x200) = var_r31;
    return 1;
}
#pragma opt_strength_reduction reset
u8 fn_801B78A8(void *arg0) {
    void fn_80013778(s32, void *);
    s32 fn_80013880(void);
    u8 EventFlag_IsSet(void *, u8 *);
    u8 *Event_GetString(void *, u16);
    extern u8 gBattleState[];
    extern s32 lbl_80368250;
    u8 *temp_r3;
    u8 var_r31;

    var_r31 = 0;
    temp_r3 = Event_GetString(arg0, (u16)M2C_FIELD(arg0, s16 *, 0x14));
    if (((s8)*temp_r3 != 0) && (EventFlag_IsSet(gBattleState + 0xB4, temp_r3) == 0)) {
        return 0;
    }
    fn_80013778(0, arg0);
    if (fn_80013880() != 0) {
        var_r31 = 1;
    }
    if (var_r31 != 0) {
        lbl_80368250 += 1;
    }
    return var_r31;
}

void AchieveList_Build(void *arg0) {
    s32 fn_800C044C(s32);
    u8 fn_801B78A8(void *);
    s32 fn_800C04B0(s32, u8 (*)(void *));
    extern s32 lbl_80368250;
    extern u8 *lbl_80368254;

    lbl_80368250 = 0;
    lbl_80368254 = (u8 *)arg0;
    *(s32 *)((u8 *)arg0 + 0x224) = fn_800C04B0(0xC, fn_801B78A8);
    *(s32 *)((u8 *)arg0 + 0x220) = fn_800C044C(0xC);
}

void Ui_OpenHelpPopup(s32 arg0, s32 arg1, s32 arg2, s8 arg3) {
    void *Process_CreateChild(void *, s32);
    void *fn_800C4638(s32, void *, s32);
    void strcpy(void *, s32);
    extern u8 lbl_80297B78[];
    extern u8 lbl_8027C5A8[];
    void *temp_r31;
    u8 *work;

    temp_r31 = Process_CreateChild(lbl_80297B78, arg2);
    M2C_FIELD(temp_r31, void **, 0x30) = fn_800C4638(0x19C, lbl_8027C5A8 + 9, 0);
    work = M2C_FIELD(temp_r31, u8 **, 0x30);
    strcpy(work + 0x10, arg0);
    M2C_FIELD(work, s32 *, 0x90) = arg1;
    M2C_FIELD(work, s8 *, 0x198) = arg3;
}

void fn_801B7A34(void *arg0) {
    void fn_8005C7C8(void *);
    void fn_800C4588(void *);
    extern u8 lbl_8027C5A8[];
    void *temp_r31;

    temp_r31 = M2C_FIELD(arg0, void **, 0x30);
    fn_8005C7C8(lbl_8027C5A8 + 0xA);
    fn_800C4588(temp_r31);
}

void fn_801B7A74(void *arg0) {
    void Process_ClearFunc(void *);
    s8 fn_80146BE4(void *);
    void fn_80148980(void *, s32);
    void fn_801B7B5C(void *, s32, f32);
    extern void *gPadInput;
    extern u8 gSeCueSlots[1344];

    void *self;
    s32 count;
    s32 btn;
    s32 prev;
    s32 pressed;
    void *p;
    s8 slot;

    self = *(void **)((u8 *)arg0 + 0x30);
    btn = *(s32 *)((u8 *)gPadInput + 4);
    prev = *(s32 *)((u8 *)gPadInput + 8);
    count = *(s32 *)((u8 *)self + 4);
    *(s32 *)((u8 *)self + 4) = count + 1;
    pressed = btn & (prev ^ btn);
    if (*(s32 *)((u8 *)self + 4) >= 0x78 || (*(s32 *)((u8 *)self + 4) >= 0x14 && ((pressed & 0x100) != 0 || (pressed & 0x200) != 0))) {
        p = *(void **)((u8 *)self + 0x90);
        if (p != NULL) {
            slot = fn_80146BE4(p);
            if (slot != -1) {
                fn_80148980(gSeCueSlots + (slot & 0xFF) * 0x30, 0x1F4);
            }
        }
        Process_ClearFunc(arg0);
    }
    fn_801B7B5C(self, *(s32 *)((u8 *)self + 0x194), (f32)(*(s32 *)((u8 *)self + 0xC) + 0x34));
}

void fn_801B7B5C(void *arg0, s32 arg1, f32 farg0) {
    void Prim2D_EmitQuad(void);
    void Prim2D_SetAlpha(s32);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_BindTexture(void *, s32, s32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, void *, f32, f32);
    s32 Text_MeasureWidth(void *, s32, f32);
    extern u8 lbl_8027C5A8[];
    extern f32 lbl_8036B210, lbl_8036B214, lbl_8036B218, lbl_8036B21C;
    extern f32 lbl_8036B220, lbl_8036B224, lbl_8036B228, lbl_8036B22C;
    extern f32 lbl_8036B230, lbl_8036B234, lbl_8036B238, lbl_8036B23C;
    extern f32 lbl_8036B240, lbl_8036B244, lbl_8036B248, lbl_8036B24C;
    extern f32 lbl_8036B250, lbl_8036B254, lbl_8036B258, lbl_8036B25C;
    extern f32 lbl_8036B260, lbl_8036B264, lbl_8036B268;

    void *self = arg0;
    s32 mode = arg1;
    f32 width = farg0;
    u16 h;
    f32 f28, f27, f30, f29, f25, f22, f31, f24, f23;
    f32 w2, y2, x3;
    s16 tx;

    if ((s8)*(u8 *)((u8 *)self + 0x198) == 0) {
        f28 = lbl_8036B210 - lbl_8036B214 * width;
        if (mode == 2) {
            f27 = lbl_8036B218;
            h = 0x50;
        } else {
            f27 = lbl_8036B21C;
            h = 0x32;
        }
        Prim2D_Begin();
        Prim2D_SetTransform(lbl_8036B220, lbl_8036B220, lbl_8036B224, lbl_8036B228);
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x12);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        f30 = lbl_8036B228 + f28;
        Prim2D_SetRect(f30, lbl_8036B228 + f27, width - lbl_8036B22C, (f32)(h - 2));
        Prim2D_EmitQuad();
        Prim2D_SetColor(0, 0, 0x2C, 0xB3);
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B230);
        Prim2D_PrepareTex();

        Prim2D_Begin();
        Prim2D_BindTexture(*(void **)((u8 *)self + 8), 0, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin(f28, f27, lbl_8036B220, lbl_8036B220);
        Prim2D_SetQuadMax(f28 + lbl_8036B234, f27 + lbl_8036B238, lbl_8036B234, lbl_8036B238);
        Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        Prim2D_Begin();
        Prim2D_BindTexture(*(void **)((u8 *)self + 8), 1, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        f29 = f28 + width;
        f25 = f29 - lbl_8036B234;
        Prim2D_SetQuadMin(f25, f27, lbl_8036B220, lbl_8036B220);
        f22 = f25 + lbl_8036B234;
        Prim2D_SetQuadMax(f22, f27 + lbl_8036B238, lbl_8036B234, lbl_8036B238);
        Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        Prim2D_Begin();
        Prim2D_BindTexture(*(void **)((u8 *)self + 8), 2, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        f31 = f27 + (f32)h;
        f24 = f31 - lbl_8036B23C;
        Prim2D_SetQuadMin(f28, f24, lbl_8036B220, lbl_8036B220);
        f23 = f24 + lbl_8036B23C;
        Prim2D_SetQuadMax(f28 + lbl_8036B234, f23, lbl_8036B234, lbl_8036B23C);
        Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        Prim2D_Begin();
        Prim2D_BindTexture(*(void **)((u8 *)self + 8), 3, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin(f25, f24, lbl_8036B220, lbl_8036B220);
        Prim2D_SetQuadMax(f22, f23, lbl_8036B234, lbl_8036B23C);
        Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        Prim2D_Begin();
        Prim2D_BindTexture(*(void **)((u8 *)self + 8), 4, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin(f28 + lbl_8036B234, f27, lbl_8036B220, lbl_8036B220);
        w2 = (width - lbl_8036B234) - lbl_8036B234;
        x3 = (f28 + lbl_8036B234) + w2;
        Prim2D_SetQuadMax(x3, f27 + lbl_8036B224, w2, lbl_8036B224);
        Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        Prim2D_Begin();
        Prim2D_BindTexture(*(void **)((u8 *)self + 8), 4, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        y2 = f31 - lbl_8036B240;
        Prim2D_SetQuadMin(f28 + lbl_8036B234, y2, lbl_8036B220, lbl_8036B220);
        Prim2D_SetQuadMax(x3, y2 + lbl_8036B224, w2, lbl_8036B224);
        Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        Prim2D_Begin();
        Prim2D_BindTexture(*(void **)((u8 *)self + 8), 5, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin(f30, f27 + lbl_8036B238, lbl_8036B220, lbl_8036B220);
        w2 = ((f32)h - lbl_8036B238) - lbl_8036B23C;
        y2 = (f27 + lbl_8036B238) + w2;
        Prim2D_SetQuadMax(f30 + lbl_8036B224, y2, lbl_8036B224, w2);
        Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        Prim2D_Begin();
        Prim2D_BindTexture(*(void **)((u8 *)self + 8), 5, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        x3 = f29 - lbl_8036B244;
        Prim2D_SetQuadMin(x3, f27 + lbl_8036B238, lbl_8036B220, lbl_8036B220);
        Prim2D_SetQuadMax(x3 + lbl_8036B224, y2, lbl_8036B224, w2);
        Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B230);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();

        if (mode == 1) {
            tx = (s16)(0x130 - ((Text_MeasureWidth((u8 *)self + 0x94, -1, lbl_8036B228) >> 1) & 0x7FFF));
            fn_8001003C(tx, (s32)(lbl_8036B248 + f27), 1, 1, 0, lbl_8027C5A8 + 0x1C, (u8 *)self + 0x94, lbl_8036B228, lbl_8036B220);
        } else {
            tx = (s16)(0x130 - ((Text_MeasureWidth((u8 *)self + 0x94, -1, lbl_8036B228) >> 1) & 0x7FFF));
            fn_8001003C(tx, (s32)(lbl_8036B24C + f27), 1, 1, 0, lbl_8027C5A8 + 0x1C, (u8 *)self + 0x94, lbl_8036B228, lbl_8036B220);
            Text_MeasureWidth((u8 *)self + 0x114, -1, lbl_8036B228);
            fn_8001003C(tx, (s32)(lbl_8036B250 + f27), 1, 1, 0, lbl_8027C5A8 + 0x1C, (u8 *)self + 0x114, lbl_8036B228, lbl_8036B220);
        }
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B22C);
        Prim2D_PrepareTex();
    } else {
        Prim2D_Begin();
        Prim2D_SetTransform(lbl_8036B220, lbl_8036B220, lbl_8036B224, lbl_8036B228);
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_BindTexture(*(void **)((u8 *)self + 8), 6, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin(lbl_8036B254, lbl_8036B21C, lbl_8036B220, lbl_8036B220);
        Prim2D_SetQuadMax(lbl_8036B258, lbl_8036B25C, lbl_8036B260, lbl_8036B264);
        Prim2D_SetAlpha(0xFF);
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B230);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        tx = (s16)(0x130 - ((Text_MeasureWidth((u8 *)self + 0x94, -1, lbl_8036B228) >> 1) & 0x7FFF));
        fn_8001003C(tx, (s32)lbl_8036B268, 2, 0, 0, lbl_8027C5A8 + 0x1C, (u8 *)self + 0x94, lbl_8036B228, lbl_8036B220);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B228);
        Prim2D_PrepareTex();
    }
}

#pragma opt_common_subs off
void fn_801B8334(void *arg0) {
    s32 FileCache_GetFlags(void *);
    void fn_8006EEFC(void *, void *);
    extern u8 lbl_8027C5A8[];
    u8 *temp_r31;

    temp_r31 = M2C_FIELD(arg0, u8 **, 0x30);
    if (FileCache_GetFlags(lbl_8027C5A8 + 0xA) & 0x2000) {
        fn_8006EEFC(temp_r31 + 8, lbl_8027C5A8 + 0xA);
        Process_ClearFunc(arg0);
    }
}

extern f32 lbl_8036B228;
void fn_801B839C(void *arg0) {
#pragma push
#pragma use_lmw_stmw on
void fn_8005C8B4(void *);
void Ui_PlaySeCue(void *,s32);
s32 Text_MeasureWidth(void *,s32,f32);
void Process_ClearFunc(void *);
extern u8 lbl_8027C5A8[];
extern f32 lbl_8036B228;
s32 width, second;
struct TextState { s32 a,b,c,width; char text[128]; void *sound; char first[128],second[128]; s32 lines; };
struct TextState *self;
u8 *p;
s32 i;
u8 c;
if (arg0 != NULL) {
self=*(struct TextState**)((u8*)arg0+0x30);
self->a=0;
self->b=0;
fn_8005C8B4(lbl_8027C5A8+10);
if (self->sound) Ui_PlaySeCue(self->sound,100);
self->lines=1;
strcpy(self->first,self->text);
for(p=(u8*)self->text,i=0;(s8)(c=*p)!=0;++p,++i) {
if ((s8)c==10) {
memcpy(self->first,(u8*)self->text,i);
self->first[i]=0;
strcpy(self->second,(char*)p+1);
self->lines=2;
}
}
width=Text_MeasureWidth(self->first,-1,lbl_8036B228);
if (self->lines==2) second=Text_MeasureWidth(self->second,-1,lbl_8036B228);
else second=0;
if(width>second) self->width=width;
else self->width=second;
Process_ClearFunc(arg0);
}
#pragma pop
}

#pragma opt_common_subs reset
#pragma opt_loop_invariants off
void fn_801B84C0(void) {
    char *Msg_Expand(u32);
    u32 Msg_ResolveName(u32);
    void DebugPrint(const char *, ...);
    extern char lbl_8027C5C8[];
    extern struct {
        u32 unk0;
        u32 unk4;
        u8 unk8;
        s8 unk9;
    } *lbl_80367214;
    struct {
        u32 unk0;
        u32 unk4;
        u8 unk8;
        s8 unk9;
    } *p;

    for (p = (void *)lbl_80367214; p->unk0 != 0; p++) {
        DebugPrint(lbl_8027C5C8 + 8, Msg_Expand(Msg_ResolveName(p->unk0)), Msg_Expand(Msg_ResolveName(p->unk4)), p->unk8, p->unk9);
    }
}

s32 fn_801B8550(void *arg0) {
void *Unit_FindByPerson(void *);
u8 Unit_GetDistance(void *,void *);
s32 fn_8001F85C(void *,s32,s32,s32,s32);
extern u8 gBattleMap[];
extern struct { void *personA,*personB; u8 flag; s8 value; } *lbl_80367214;
struct Entry { void *personA,*personB; u8 flag; s8 value; };
struct Entry *entry;
u8 *unit=(u8*)arg0;
u8 *other;
u8 *mapFlag=gBattleMap+0x24EEA;
s32 valid;
for(entry=(struct Entry*)lbl_80367214;entry->personA;entry++) {
if (entry->flag==2 && *(void**)(unit+0x188)==entry->personB) {
other=(u8*)Unit_FindByPerson(entry->personA);
if(unit==NULL || other==NULL) valid=0;
else if((u8)Unit_GetDistance(unit,other)!=1) valid=0;
else {
*mapFlag=0;
if((u8)fn_8001F85C(gBattleMap,unit[0x19E],unit[0x19F],other[0x19E],other[0x19F])==0) valid=0;
else if(*(void**)(unit+0x190)!=*(void**)(other+0x190)) valid=0;
else valid=1;
}
if((u8)valid) return 1;
}
}
return 0;
}

s8 fn_801B8674(void *arg0) {
    void *Unit_FindByPerson(void *);
    u8 Unit_GetDistance(void *, void *);
    s32 fn_8001F85C(void *, s32, s32, s32, s32);

    extern u8 gBattleMap[];
    extern struct {
        void *personA;
        void *personB;
        u8 flag;
        s8 value;
    } *lbl_80367214;

    u8 *unit;
    u8 *unitA;
    u8 *unitB;
    s32 total;
    s32 valid;
    struct {
        void *personA;
        void *personB;
        u8 flag;
        s8 value;
    } *entry;

    unit = (u8 *)arg0;
    entry = (void *)lbl_80367214;
    total = 0;

    while (entry->personA != NULL) {
        if (entry->flag == 1) {
            if (*(void **)(unit + 0x188) == entry->personA) {
                valid = 0;
            } else if (*(void **)(unit + 0x188) == entry->personB) {
                unitA = Unit_FindByPerson(entry->personB);
                unitB = Unit_FindByPerson(entry->personA);

                if (unitB == NULL || unitA == NULL) {
                    valid = 0;
                } else if ((u8)Unit_GetDistance(unitB, unitA) != 1) {
                    valid = 0;
                } else {
                    gBattleMap[0x24EEA] = 0;

                    if ((u8)fn_8001F85C(
                            gBattleMap,
                            unitB[0x19E],
                            unitB[0x19F],
                            unitA[0x19E],
                            unitA[0x19F]
                        ) == 0) {
                        valid = 0;
                    } else if (*(void **)(unitB + 0x190) !=
                               *(void **)(unitA + 0x190)) {
                        valid = 0;
                    } else {
                        valid = 1;
                    }
                }
            } else {
                valid = 0;
            }

            if ((u8)valid != 0) {
                total += entry->value;
            }
        }

        entry++;
    }

    return (s8)total;
}

#pragma opt_loop_invariants reset
void fn_801B8798(void) {
    u32 Person_GetByPid(u32);
    extern struct {
        u32 unk0;
        u32 unk4;
        u8 unk8;
        s8 unk9;
    } *lbl_80367214;
    u32 *p;

    for (p = (u32 *)lbl_80367214; p[0] != 0; p += 3) {
        p[0] = Person_GetByPid(p[0]);
        p[1] = Person_GetByPid(p[1]);
    }
}

/* Apply chapter achievement gold to funds; open bonus tally UI when unlocked. */
void Battle_ApplyAchieveBonuses(s32 parent) {
    void *Heap_Alloc(s32);
    void AchieveList_SetBaseGold(void *, s32);
    void AchieveList_Build(void *);
    s32 AchieveList_SumBonuses(void *);
    s32 AchieveList_GetTotalGold(void *);
    u8 SystemSave_TestFlag0(void *);
    void *Process_CreateChild(void *, s32);
    void *fn_800C4638(s32, void *, s32);
    extern u8 gBattleState[];
    extern u8 gSystemSave[];
    extern u8 lbl_80297BA8[];
    extern u8 lbl_8027C5E8[];
    void *list;
    void *proc;
    void *work;
    u8 *battle;

    list = Heap_Alloc(0x22C);
    battle = gBattleState;
    AchieveList_SetBaseGold(list, *(s32 *)(battle + 0x1C));
    AchieveList_Build(list);
    *(s16 *)(gBattleState + 0x72) = AchieveList_SumBonuses(list);
    *(s32 *)(battle + 0x1C) = AchieveList_GetTotalGold(list);
    if (((u32)(gBattleState[0x9E] & 1) != 1) && SystemSave_TestFlag0(gSystemSave)) {
        proc = Process_CreateChild(lbl_80297BA8, parent);
        *(void **)((u8 *)proc + 0x30) = fn_800C4638(0x2C, lbl_8027C5E8 + 0x57, 0);
        *(s32 *)((u8 *)proc + 0x34) = 0;
        work = *(void **)((u8 *)proc + 0x30);
        *(s32 *)((u8 *)work + 8) = 0;
        *(void **)((u8 *)work + 0xC) = list;
    }
}

void fn_801B88D4(void *arg0) {
    void Heap_Free(s32);
    void Process_Unlink(void *);
    void FileCache_ReleaseSlot(void *);
    void fn_800C4588(void *);
    struct {
        u8 pad[8];
        void *unk8;
        s32 unkC;
    } *work = M2C_FIELD(arg0, void **, 0x30);

    Heap_Free(work->unkC);
    if (M2C_FIELD(arg0, void **, 0x34) != NULL) {
        Process_Unlink(M2C_FIELD(arg0, void **, 0x34));
    }
    if (work->unk8 != NULL) {
        FileCache_ReleaseSlot(&work->unk8);
    }
    fn_800C4588(work);
}

#pragma global_optimizer off
void fn_801B893C(void *arg0) {
    void Process_ClearFunc(void);
    void Ui_PlaySeCue(void *, s32);
    s32 AchieveList_GetTotalGold(void *);
    s32 AchieveList_SumBonuses(void *);
    extern u8 lbl_8027C5E8[];
    extern void *gPadInput;
    extern s32 lbl_80368258;
    extern s8 lbl_8036825C;

    void *pad;
    void *st;
    void *data;
    s32 state;
    s32 btn;

    pad = gPadInput;
    st = *(void **)((u8 *)arg0 + 0x30);
    btn = *(s32 *)((u8 *)pad + 4);
    {
        s32 x = *(s32 *)((u8 *)pad + 8);
        data = *(void **)((u8 *)st + 0xc);
        btn = btn & (x ^ btn);
    }
    if (lbl_8036825C == 0) {
        pad = 0;
        lbl_80368258 = (s32)pad;
        lbl_8036825C = 1;
    }
    state = *(s32 *)st;
    switch (state) {
    case 0:
        *(s32 *)st = 1;
        *(s32 *)((u8 *)st + 4) = 0;
        lbl_80368258 = 0;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        if (*(s32 *)((u8 *)data + 0x224) == 0) {
            *(s32 *)st = 6;
            *(s32 *)((u8 *)st + 4) = 0;
            break;
        }
        if ((btn & 0x100) != 0 || (btn & 0x200) != 0) {
            void *p = data;
            void *q = st;
            s32 i = 0;
            goto loop_cond;
        loop_body:
            *(s32 *)((u8 *)q + 0x10) = *(s32 *)((u8 *)p + 0x200);
            p = (u8 *)p + 4;
            i += 1;
            q = (u8 *)q + 4;
        loop_cond:
            if (i < *(s32 *)((u8 *)data + 0x224)) {
                goto loop_body;
            }
            *(s32 *)((u8 *)st + 0x24) = AchieveList_SumBonuses(data);
            *(s32 *)((u8 *)st + 0x28) = AchieveList_GetTotalGold(data);
            *(s32 *)st = 6;
            break;
        }
        {
            s32 idx = state - 1;
            void *slot = (u8 *)st + (idx * 4);
            void *src = (u8 *)data + (idx * 4);
            s32 cur = *(s32 *)((u8 *)slot + 0x10);
            if (cur >= *(s32 *)((u8 *)src + 0x200)) {
                *(s32 *)((u8 *)slot + 0x10) = *(s32 *)((u8 *)src + 0x200);
                *(s32 *)((u8 *)st + 4) = *(s32 *)((u8 *)st + 4) + 1;
                if (*(s32 *)((u8 *)st + 4) >= 0xA) {
                    if (idx < *(s32 *)((u8 *)data + 0x224) - 1) {
                        *(s32 *)st = *(s32 *)st + 1;
                        *(s32 *)((u8 *)st + 4) = 0;
                        lbl_80368258 = 0;
                    } else {
                        *(s32 *)st = 6;
                        *(s32 *)((u8 *)st + 4) = 0;
                    }
                }
                break;
            }
            *(s32 *)((u8 *)slot + 0x10) = cur + 7;
            *(s32 *)((u8 *)st + 0x24) = *(s32 *)((u8 *)st + 0x24) + 7;
            if (*(s32 *)((u8 *)st + 0x24) > AchieveList_SumBonuses(data)) {
                *(s32 *)((u8 *)st + 0x24) = AchieveList_SumBonuses(data);
            }
            *(s32 *)((u8 *)st + 0x28) = *(s32 *)((u8 *)st + 0x28) + 7;
            if (*(s32 *)((u8 *)st + 0x28) > AchieveList_GetTotalGold(data)) {
                *(s32 *)((u8 *)st + 0x28) = AchieveList_GetTotalGold(data);
            }
            if (lbl_80368258 == 0) {
                Ui_PlaySeCue(lbl_8027C5E8 + 0x58, 0x64);
            }
            {
                s32 t = lbl_80368258 + 1;
                lbl_80368258 = t;
                lbl_80368258 = t % 4;
            }
        }
        break;
    case 6:
        if ((btn & 0x100) != 0 || (btn & 0x200) != 0) {
            Process_ClearFunc();
        }
        break;
    }
}

#pragma use_lmw_stmw on
void fn_801B8B94(void *arg0) {
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_PrepareTex(void);
    void Prim2D_AddZ(f32);
    void Prim2D_BindTexture(void *, s32, s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_EmitQuad(void);
    void Prim2D_EndPrim(void);
    void Prim2D_SetTex(s32, s32);
    void *Msg_Expand(void *);
    s32 Text_MeasureWidth(void *, s32, f32);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, ...);
    void **fn_8006EDD8(void *, s32);
    s32 *Ui_GetColor(s32);
    void Prim2D_SetPrimParam(f32);
    void Prim2D_SetColor(u8, u8, u8, s32);
    void *fn_801B77F0(void *, s32);
    extern f32 lbl_8036B278, lbl_8036B27C, lbl_8036B280, lbl_8036B284, lbl_8036B288;
    extern f32 lbl_8036B28C, lbl_8036B290, lbl_8036B294, lbl_8036B298, lbl_8036B29C;
    extern f32 lbl_8036B2A0, lbl_8036B2A4, lbl_8036B2A8, lbl_8036B2AC, lbl_8036B2B0;
    extern f32 lbl_8036B2B4, lbl_8036B2B8;
    extern u8 lbl_8027C5E8[];

    u8 color[4];
    u8 color2[4];
    void *self;
    void *str;
    f32 w, h;
    u16 tw, th;
    u16 tw2, th2;
    s32 i;
    s32 y;
    void *p;
    void **tex;

    self = *(void **)((u8 *)arg0 + 0x30);
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B278, lbl_8036B278, lbl_8036B27C, lbl_8036B280);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B284);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_BindTexture(*(void **)((u8 *)self + 8), 1, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B288, lbl_8036B28C, lbl_8036B278, lbl_8036B278);
    Prim2D_SetQuadMax(lbl_8036B290, lbl_8036B294, lbl_8036B288, lbl_8036B298);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B278, lbl_8036B28C, lbl_8036B288, lbl_8036B278);
    Prim2D_SetQuadMax(lbl_8036B288, lbl_8036B294, lbl_8036B278, lbl_8036B298);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B284);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    str = Msg_Expand(lbl_8027C5E8 + 0x6C);
    fn_8001003C((s32)(lbl_8036B288 - lbl_8036B29C * (f32)Text_MeasureWidth(str, -1, lbl_8036B280)),
                0x20, 2, 0, 0, str, lbl_8036B280, lbl_8036B278);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B2A0);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B284);
    Prim2D_PrepareTex();
    tex = fn_8006EDD8(*(void **)((u8 *)self + 8), 0);
    {
        u16 *dims = (u16 *)*tex;
        w = (f32)dims[0];
        h = (f32)dims[1];
    }
    *(s32 *)color = *Ui_GetColor(1);
    tex = fn_8006EDD8(*(void **)((u8 *)self + 8), 0);
    {
        u16 *dims = (u16 *)*tex;
        th = dims[1];
        tw = dims[0];
    }
    Prim2D_Begin();
    Prim2D_BindTexture(*(void **)((u8 *)self + 8), 0, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetPrimParam(lbl_8036B278);
    Prim2D_SetQuadMin(lbl_8036B2A4, lbl_8036B2A8, lbl_8036B278, lbl_8036B278);
    Prim2D_SetQuadMax(lbl_8036B2A4 + h, lbl_8036B2A8 + w, (f32)th, (f32)tw);
    Prim2D_SetColor(color[0], color[1], color[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B284);
    Prim2D_PrepareTex();
    i = 0;
    y = 0;
    p = self;
    while (i < *(s32 *)((u8 *)*(void **)((u8 *)self + 0xC) + 0x224)) {
        f32 fy = lbl_8036B2AC + (f32)y;
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        fn_8001003C(0x68, (s32)fy, 1, 1, 0, fn_801B77F0(*(void **)((u8 *)self + 0xC), i),
                    lbl_8036B280, lbl_8036B278);
        fn_8001003C(0x19E, (s32)fy, 6, 1, 0, lbl_8027C5E8 + 0x79,
                    lbl_8036B280, lbl_8036B278, *(void **)((u8 *)p + 0x10));
        y += 0x20;
        p = (u8 *)p + 4;
        i += 1;
    }
    fn_8001003C(0x166, 0x114, 0x19, 0, 1, Msg_Expand(lbl_8027C5E8 + 0x7D),
                lbl_8036B280, lbl_8036B278);
    fn_8001003C(0x19E, 0x114, 6, 1, 0, lbl_8027C5E8 + 0x79,
                lbl_8036B280, lbl_8036B278, *(void **)((u8 *)self + 0x24));
    fn_8001003C(0x1F2, 0x114, 0x19, 0, 1, lbl_8027C5E8 + 0x8B,
                lbl_8036B280, lbl_8036B278);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B2A0);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B284);
    Prim2D_PrepareTex();
    tex = fn_8006EDD8(*(void **)((u8 *)self + 8), 2);
    {
        u16 *dims = (u16 *)*tex;
        w = (f32)dims[0];
        h = (f32)dims[1];
    }
    *(s32 *)color2 = *Ui_GetColor(1);
    tex = fn_8006EDD8(*(void **)((u8 *)self + 8), 2);
    {
        u16 *dims = (u16 *)*tex;
        th2 = dims[1];
        tw2 = dims[0];
    }
    Prim2D_Begin();
    Prim2D_BindTexture(*(void **)((u8 *)self + 8), 2, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetPrimParam(lbl_8036B278);
    Prim2D_SetQuadMin(lbl_8036B288, lbl_8036B2B0, lbl_8036B278, lbl_8036B278);
    Prim2D_SetQuadMax(lbl_8036B288 + h, lbl_8036B2B0 + w, (f32)th2, (f32)tw2);
    Prim2D_SetColor(color2[0], color2[1], color2[2], 0xCD);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B284);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    fn_8001003C((s32)lbl_8036B2B4, 0x15E, 0x19, 1, 0, Msg_Expand(lbl_8027C5E8 + 0x8E),
                lbl_8036B280, lbl_8036B278);
    fn_8001003C(0x17E, 0x158, 6, 1, 0, lbl_8027C5E8 + 0x79,
                lbl_8036B2B8, lbl_8036B278, *(void **)((u8 *)self + 0x28));
    fn_8001003C(0x1F0, 0x158, 0x19, 1, 1, lbl_8027C5E8 + 0x8B,
                lbl_8036B2B8, lbl_8036B278);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B2A0);
    Prim2D_PrepareTex();
}

#pragma global_optimizer off
void fn_801B91D8(void *arg0) {
    s32 Process_AttachFunc(void *, void *);
    s32 FileCache_GetFlags(void *);
    void fn_8006EEFC(void *, void *);
    void Process_ClearFunc(void *);
    void fn_801B8B94(void *);
    extern u8 lbl_8027C5E8[];
    void *temp_r31;

    temp_r31 = *(void **)((char *)arg0 + 0x30);
    if (FileCache_GetFlags(lbl_8027C5E8 + 0x9C) & 0x2000) {
        fn_8006EEFC((char *)temp_r31 + 8, lbl_8027C5E8 + 0x9C);
        *(s32 *)((char *)arg0 + 0x34) = Process_AttachFunc(fn_801B8B94, arg0);
        Process_ClearFunc(arg0);
    }
}
#pragma global_optimizer on
void fn_801B9254(void *arg0) {
    M2C_UNK Process_Goto(void *, M2C_UNK);
    M2C_UNK fn_8005C8B4(void *);
    M2C_UNK fn_80147188(M2C_UNK);
    s32 AchieveList_GetTotalGold(void *);
    s32 AchieveList_SumBonuses(void *);
    extern u8 lbl_8027C5E8[];
    s32 temp_r31;
    void *temp_r30;

    temp_r30 = *(void **)((u8 *)arg0 + 0x30);
    fn_80147188(0x3E8);
    if (*(s32 *)((u8 *)*(void **)((u8 *)temp_r30 + 0xC) + 0x220) == 0) {
        Process_Goto(arg0, 0x63);
        return;
    }
    *(s32 *)((u8 *)temp_r30 + 0) = 0;
    *(s32 *)((u8 *)temp_r30 + 4) = 0;
    *(s32 *)((u8 *)temp_r30 + 0x10) = 0;
    *(s32 *)((u8 *)temp_r30 + 0x14) = 0;
    *(s32 *)((u8 *)temp_r30 + 0x18) = 0;
    *(s32 *)((u8 *)temp_r30 + 0x1C) = 0;
    *(s32 *)((u8 *)temp_r30 + 0x20) = 0;
    *(s32 *)((u8 *)temp_r30 + 0x24) = 0;
    temp_r31 = AchieveList_GetTotalGold(*(void **)((u8 *)temp_r30 + 0xC));
    *(s32 *)((u8 *)temp_r30 + 0x28) = temp_r31 - AchieveList_SumBonuses(*(void **)((u8 *)temp_r30 + 0xC));
    fn_8005C8B4(lbl_8027C5E8 + 0x9C);
}

/* Focus the unit-manage list on gBattleState's unit, sync portrait/skill widgets, then Process_Goto. */
void Ui_ApplyUnitManageFocus(void *panel) {
    void fn_8013AD70(void *, s32);
    s32 Ui_ListGetSelected(void *);
    void Ui_SetPortraitUnit(void *, s32);
    void fn_80137EA0(void *, s32);
    void fn_8017BB94(void *);
    s32 Unit_GetSkillCapacityUsed(s32);
    void Process_Goto(void *, u8);
    extern u8 gBattleState[];
    extern f64 lbl_8036B2D0;
    void *self;
    void *list;
    s32 unit;
    void *side;
    u8 kind;

    self = panel;
    list = *(void **)((u8 *)self + 0x48);
    fn_8013AD70(list, *(s32 *)(gBattleState + 0xB0));
    unit = Ui_ListGetSelected(list);
    kind = *(u8 *)((u8 *)self + 0x44);
    switch (kind) {
    case 4:
        list = *(void **)((u8 *)self + 0x54);
        side = *(void **)((u8 *)self + 0x58);
        Ui_SetPortraitUnit(*(void **)((u8 *)self + 0x4C), unit);
        fn_80137EA0(list, unit);
        *(s32 *)((u8 *)side + 0x3C) = unit;
        break;
    case 16:
        *(s32 *)((u8 *)*(void **)((u8 *)self + 0x64) + 0x3C) = unit;
        list = *(void **)((u8 *)self + 0x60);
        *(s32 *)((u8 *)list + 0x4C) = unit;
        fn_8017BB94(list);
        *(f32 *)((u8 *)list + 0x50) = (f32)Unit_GetSkillCapacityUsed(unit);
        break;
    }
    Process_Goto(self, *(u8 *)((u8 *)self + 0x44));
}

/* Focus the unit-manage list on gBattleState+0xAC's unit and sync portrait/skill widgets. */
void Ui_SyncUnitManageFocus(void *panel) {
    void fn_8013AD70(void *, s32);
    s32 Ui_ListGetSelected(void *);
    void Ui_SetPortraitUnit(void *, s32);
    void fn_80137EA0(void *, s32);
    void fn_8017BB94(void *);
    s32 Unit_GetSkillCapacityUsed(s32);
    extern u8 gBattleState[];
    extern f64 lbl_8036B2D0;
    void *self;
    void *list;
    s32 unit;
    void *side;
    u8 kind;

    self = panel;
    list = *(void **)((u8 *)self + 0x48);
    fn_8013AD70(list, *(s32 *)(gBattleState + 0xAC));
    unit = Ui_ListGetSelected(list);
    kind = *(u8 *)((u8 *)self + 0x44);
    switch (kind) {
    case 4:
        list = *(void **)((u8 *)self + 0x54);
        side = *(void **)((u8 *)self + 0x58);
        Ui_SetPortraitUnit(*(void **)((u8 *)self + 0x4C), unit);
        fn_80137EA0(list, unit);
        *(s32 *)((u8 *)side + 0x3C) = unit;
        break;
    case 16:
        *(s32 *)((u8 *)*(void **)((u8 *)self + 0x64) + 0x3C) = unit;
        list = *(void **)((u8 *)self + 0x60);
        *(s32 *)((u8 *)list + 0x4C) = unit;
        fn_8017BB94(list);
        *(f32 *)((u8 *)list + 0x50) = (f32)Unit_GetSkillCapacityUsed(unit);
        break;
    }
}

void fn_801B94DC(void *arg0)
{
    void Process_Goto(void *, u8);
    Process_Goto(arg0, *(u8 *)((char *)arg0 + 0x44));
}

#pragma cplusplus on
extern "C" void Ui_ReleaseUnitManageWidgets(void *panel) {
    /* Remove and release unit-manage list (0x48), side (0x64), help (0x50), and inventory (0x60) widgets. */
    void Ui_RemoveChild(void *, void *);
    struct Obj {
        virtual void destroy(s32) = 0;
        s32 refcount;
    };
    Obj *child;
    s32 refs;

    Ui_RemoveChild(panel, M2C_FIELD(panel, void **, 0x48));
    Ui_RemoveChild(panel, M2C_FIELD(panel, void **, 0x64));
    Ui_RemoveChild(panel, M2C_FIELD(panel, void **, 0x50));
    Ui_RemoveChild(panel, M2C_FIELD(panel, void **, 0x60));

    child = M2C_FIELD(panel, Obj **, 0x48);
    if (child != NULL) {
        refs = child->refcount - 1;
        child->refcount = refs;
        if (refs == 0 && child != NULL) {
            child->destroy(1);
        }
        M2C_FIELD(panel, void **, 0x48) = NULL;
    }

    child = M2C_FIELD(panel, Obj **, 0x64);
    if (child != NULL) {
        refs = child->refcount - 1;
        child->refcount = refs;
        if (refs == 0 && child != NULL) {
            child->destroy(1);
        }
        M2C_FIELD(panel, void **, 0x64) = NULL;
    }

    child = M2C_FIELD(panel, Obj **, 0x50);
    if (child != NULL) {
        refs = child->refcount - 1;
        child->refcount = refs;
        if (refs == 0 && child != NULL) {
            child->destroy(1);
        }
        M2C_FIELD(panel, void **, 0x50) = NULL;
    }

    child = M2C_FIELD(panel, Obj **, 0x60);
    if (child != NULL) {
        refs = child->refcount - 1;
        child->refcount = refs;
        if (refs == 0 && child != NULL) {
            child->destroy(1);
        }
        M2C_FIELD(panel, void **, 0x60) = NULL;
    }
}

extern "C" void fn_801B9654(void *arg0) {
    void *Ui_FindChild(void *, s32, s32);
    void fn_8017BB94(void *);
    u32 fn_8017BC94(void *);
    void Ui_SlideWidgetChild(void *, void *, s16 *, s32);
    void Process_Goto(void *, s32);
    struct { s16 x; s16 y; } spC;
    struct { s16 x; s16 y; } sp8;
    void *list;
    void *obj82;
    void *obj108;
    s16 tmp;
    f32 f;

    list = *(void **)((u8 *)arg0 + 0x60);
    obj82 = Ui_FindChild(arg0, 0x82, 0);
    obj108 = Ui_FindChild(arg0, 0x108, 0);
    fn_8017BB94(list);
    if (fn_8017BC94(list) == 0) {
        spC.x = *(s16 *)((u8 *)obj82 + 0xA);
        spC.y = -0x3A;
        Ui_SlideWidgetChild(arg0, obj82, &spC.x, 0);
        tmp = *(s16 *)((u8 *)obj108 + 0xC);
        sp8.x = 0x260;
        sp8.y = tmp;
        Ui_SlideWidgetChild(arg0, obj108, &sp8.x, 1);
        Process_Goto(arg0, 0x11);
    } else {
        *(u8 *)((u8 *)list + 0x3C) = 1;
        f = 0.0f;
        *(f32 *)((u8 *)obj82 + 0x30) = f;
        *(f32 *)((u8 *)obj108 + 0x30) = f;
    }
}

#pragma cplusplus reset
void fn_801B9748(void *a) {
    void *Ui_FindChild(void *, s32, s32);
    s32 Res_GetEntry(u8);
    void fn_8017A9F0(void *, s32, void *);
    extern u8 gUiContext[];
    extern f32 lbl_8036B2DC;

    void *p;
    void *q;
    s32 x;

    p = Ui_FindChild(a, 0x82, 0);
    *(f32 *)((u8 *)p + 0x30) = lbl_8036B2DC;

    p = Ui_FindChild(a, 0x108, 0);
    *(f32 *)((u8 *)p + 0x30) = lbl_8036B2DC;

    x = Res_GetEntry(gUiContext[0x14]);
    q = *(void **)((u8 *)a + 0x60);
    *(u8 *)((u8 *)q + 0x3C) = 0;
    fn_8017A9F0(q, x, a);
}

void fn_801B97C8(s32 arg0) {
    extern u8 gUiContext[];
    switch ((s32)gUiContext[8]) {
    case 0x81:
        Process_ClearFunc(arg0);
        return;
    case 0x80:
        Process_Goto(arg0, 0x18);
        return;
    }
}

void fn_801B9818(void *arg0) {
    extern u8 gUiUnitPanelStrings[];
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *, void *);
    void *fn_8013BC10(void *, void *);
    void Ui_CreateMenu(void *, void *, s32);
    s32 strlen(const char *);
    void String_AssignCStr(void *, const void *, s32);
#pragma cplusplus on
    struct Item {
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
        virtual void set2(s32) = 0;
        virtual void v19() = 0;
        virtual void set3(s32) = 0;
    };
    struct Base { u32 unknown; };
    struct Menu: Base {
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
        virtual Item *get(s32) = 0;
    };
    void *self = arg0;
    Menu *menu;
    s32 i;
    Item *item;
    void *child;
    menu = (Menu *)fn_8013BC10(gUiUnitPanelStrings + 0xDF, gUiUnitPanelStrings + 0xEC);
    M2C_FIELD(menu, s16 *, 0xC) = 0xE8;
    M2C_FIELD(menu, s16 *, 8) = 0x148;
    M2C_FIELD(menu, s16 *, 0xA) = 0x38;
    M2C_FIELD(menu, u8 *, 0x24) = 1;
    for (i = 0; menu->get(i) != 0; i++) {
        item = menu->get(i);
        item->set2(2);
        item->set3(3);
    }
    Ui_CreateMenu(menu, self, 0);
    child = Ui_FindChild(self, 0x82, 0);
    String_AssignCStr((u8 *)child + 0x3C, gUiUnitPanelStrings + 0xF7, strlen((char *)gUiUnitPanelStrings + 0xF7));
    child = Ui_FindChild(self, -0x1000, 0);
    if (child) Ui_SetWidgetText(child, gUiUnitPanelStrings + 0xF8);
#pragma cplusplus reset
}

#pragma cplusplus on
#pragma use_lmw_stmw on
/* Handle unit select-list input: A picks the unit, X opens info, B hides/backs out. */
extern "C" void Ui_HandleUnitSelectListInput(void *arg0) {
 void Process_Goto(void *,s32); void Process_ClearFunc(void *);
 s32 fn_80105814(void *); void Ui_UpdatePanelWidgets(void *); void *Ui_FindChild(void *,s32,s32);
 void Ui_PlaySeCue(void *,s32); u8 Ui_IsUnitInfoPopupOpen(void *);
 void Ui_ShowUnitInfoText(void *,s32,f32,f32); void Ui_HideUnitInfoPopup(void *);
 void Ui_OpenUnitInfoText(void *,void *,s32,f32,f32); void *fn_8017B908(void *);
 extern u8 gUiUnitPanelStrings[],gUiContext[],gUnitInfoPopup[];
 extern u32 gUiInputFlags; extern void *gPadInput; extern s32 gUnitInfoPopupFlag;
 class Pair { public: s16 x,y; Pair() {} Pair(s16 a,s16 b):x(a),y(b) {} Pair(const Pair &o) { *(u32 *)this=*(u32 *)&o; } Pair &operator=(const Pair &o) { *(u32 *)this=*(u32 *)&o; return *this; } };
 void Ui_SlideWidgetChild(void *,void *,const Pair &,s32);
 struct Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual Pair v9(); };
 void *list,*slot,*unit,*self,*temp;
 register int btn;
 s32 held;
 u8 gate;
 s32 flags;
 u32 pos1,pos2;
 self=arg0;
 list=M2C_FIELD(self,void **,0x60);
 slot=Ui_FindChild(self,0x108,0);
 unit=fn_8017B908(list);
 Ui_UpdatePanelWidgets(self);
 if(unit!=fn_8017B908(list)) {
 unit=fn_8017B908(list);
 if(Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
 if(unit) {
 *(Pair *)&pos1=((Obj *)list)->v9();
 Ui_ShowUnitInfoText(gUnitInfoPopup,fn_80105814(unit),(f32)*(s16 *)&pos1,(f32)*((s16 *)&pos1+1));
 } else Ui_HideUnitInfoPopup(gUnitInfoPopup);
 }
 }
 M2C_FIELD(slot,void **,0x3C)=unit;
 gate=0; flags=gUiInputFlags;
 if((flags&0x10)&&!(flags&0x20)) gate=1;
 if(!gate) {
 held=M2C_FIELD(gPadInput,s32 *,4);
 btn=held&(M2C_FIELD(gPadInput,s32 *,8)^held);
 if((btn&0x100)&&unit&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
 gUiContext[0x14]=M2C_FIELD(unit,u8 *,0x18);
 Ui_PlaySeCue(gUiUnitPanelStrings+0x10C,100); Process_ClearFunc(self);
 } else if((btn&0x800)&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)&&unit) {
 *(Pair *)&pos2=((Obj *)list)->v9();
 Ui_OpenUnitInfoText(gUnitInfoPopup,self,fn_80105814(unit),(f32)*(s16 *)&pos2,(f32)*((s16 *)&pos2+1));
 *(s32 *)gUnitInfoPopup|=gUnitInfoPopupFlag;
 } else if((btn&0xA00)&&Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
 Ui_HideUnitInfoPopup(gUnitInfoPopup);
 } else if((btn&0x200)&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
 Ui_SlideWidgetChild(self,slot,Pair(0x260,M2C_FIELD(slot,s16 *,0xC)),1);
 temp=Ui_FindChild(self,0x82,0);
 Ui_SlideWidgetChild(self,temp,Pair(M2C_FIELD(temp,s16 *,0xA),-0x3A),0);
 Ui_PlaySeCue(gUiUnitPanelStrings+0x11C,100);
 Process_Goto(self,0x11);
 }
 }
}

extern "C" void fn_801B9C90(void *arg0) {
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SlideWidgetChildMode1(void *, void *, s16 *, s32);
    void Ui_SetWidgetText(void *, void *);
    void Ui_BringChildToFront(void *, void *);
    extern u8 gUiUnitPanelStrings[];
    s16 listPos[2], captionPos[2];
    void *front;
    void *list;
    void *caption;
    void *help;
    s16 x,y;
    front=*(void **)((u8 *)arg0+0x60);
    list=Ui_FindChild(arg0,0x108,0);
    if(*(s16 *)((u8 *)list+0xA)!=0x148) {
        y=*(s16 *)((u8 *)list+0xC);
        listPos[0]=0x148; listPos[1]=y;
        Ui_SlideWidgetChildMode1(arg0,list,listPos,0);
    }
    caption=Ui_FindChild(arg0,0x82,0);
    if(*(s16 *)((u8 *)caption+0xC)<0x28) {
        x=*(s16 *)((u8 *)caption+0xA);
        captionPos[0]=x; captionPos[1]=0x28;
        Ui_SlideWidgetChildMode1(arg0,caption,captionPos,0);
    }
    Ui_SetWidgetText(caption,gUiUnitPanelStrings+0x12C);
    Ui_BringChildToFront(arg0,front);
    help=Ui_FindChild(arg0,-0x1000,0);
    if(help) Ui_SetWidgetText(help,gUiUnitPanelStrings+0x142);
}

#pragma cplusplus reset
#pragma use_lmw_stmw reset

#pragma cplusplus on
extern "C" void fn_801B9D94(void *arg0) {
    void *Heap_Alloc(s32);
    void Ui_BringChildToFront(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_AddChild(void *, void *);
    void Ui_SlideWidgetChild(void *, void *, s16 *, s32);
    void fn_801402A0(void *, void *, s16 *, s32);
    void Ui_PlaySeCue(void *, s32);
    void Ui_SetWidgetText(void *, void *, s32, s32);
    s32 fn_8017B908(void *);
    void fn_8017BB94(void *);

    extern u8 gUiUnitPanelStrings[];
    extern void *lbl_8028FDB0[];
    extern void *lbl_8029186C[];
    extern void *lbl_80292230[];
    extern void *lbl_80293C2C[];
    extern void *lbl_80293C84[];
    extern f32 lbl_8036B2D8;

    s16 pairC[2];
    s16 pair8[2];
    void *temp;
    void *obj1;
    void *obj2;
    void *child;
    s16 t0;
    s16 t1;
    s16 w;

    #pragma use_lmw_stmw on

    temp = Ui_FindChild(arg0, 0x100, 0);
    t0 = *(s16 *)((u8 *)temp + 0xC);
    t1 = *(s16 *)((u8 *)temp + 0x10);
    w = (s16)(t1 - t0);
    pairC[0] = *(s16 *)((u8 *)temp + 0xA);
    pairC[1] = -w;
    Ui_SlideWidgetChild(arg0, temp, pairC, 0);
    child = *(void **)((u8 *)arg0 + 0x60);
    fn_8017BB94(child);
    *(u8 *)((u8 *)child + 0x3C) = 1;
    if (*(s16 *)((u8 *)child + 0xC) != 0x7C) {
        pair8[0] = *(s16 *)((u8 *)child + 0xA);
        pair8[1] = 0x7C;
        fn_801402A0(arg0, child, pair8, 0);
    }
    obj1 = Heap_Alloc(0x4C);
    if (obj1 != NULL) {
        *(void **)obj1 = lbl_8028FDB0;
        *(s32 *)((u8 *)obj1 + 4) = 0;
        *(void **)obj1 = lbl_80292230;
        *(s16 *)((u8 *)obj1 + 8) = -1;
        *(s16 *)((u8 *)obj1 + 0xA) = 0x260;
        *(s16 *)((u8 *)obj1 + 0xC) = 0x7C;
        *(s16 *)((u8 *)obj1 + 0xE) = 0x368;
        *(s16 *)((u8 *)obj1 + 0x10) = 0x16E;
        *(s16 *)((u8 *)obj1 + 0x12) = 0;
        *(s16 *)((u8 *)obj1 + 0x14) = 0;
        *(s16 *)((u8 *)obj1 + 0x16) = 0x108;
        *(s16 *)((u8 *)obj1 + 0x18) = 0xF2;
        *(s16 *)((u8 *)obj1 + 0x1A) = 0;
        *(s16 *)((u8 *)obj1 + 0x1C) = 0;
        ((u8 *)obj1)[0x1E] = 0xFF;
        ((u8 *)obj1)[0x1F] = 0xFF;
        ((u8 *)obj1)[0x20] = 0xFF;
        ((u8 *)obj1)[0x21] = 0xFF;
        *(s16 *)((u8 *)obj1 + 0x22) = 0x1E0;
        *(s16 *)((u8 *)obj1 + 0x24) = 0;
        *(f32 *)((u8 *)obj1 + 0x28) = lbl_8036B2D8;
        *(f32 *)((u8 *)obj1 + 0x2C) = lbl_8036B2D8;
        *(f32 *)((u8 *)obj1 + 0x30) = lbl_8036B2D8;
        *(s32 *)((u8 *)obj1 + 0x34) = 0;
        *(s32 *)((u8 *)obj1 + 0x38) = 0;
        *(void **)obj1 = lbl_8029186C;
        *(s32 *)((u8 *)obj1 + 0x3C) = 0;
        *(s16 *)((u8 *)obj1 + 0x40) = 0x14;
        *(s16 *)((u8 *)obj1 + 0x42) = 8;
        ((void (*)(void *))*(u32 *)(((u8 *)obj1) + 0x28))(obj1);
        *(s16 *)((u8 *)obj1 + 8) = 0x108;
        *(s16 *)((u8 *)obj1 + 0x24) = 8;
        *(s32 *)((u8 *)obj1 + 0x34) |= 0x10;
        *(s32 *)((u8 *)obj1 + 0x3C) = fn_8017B908(child);
        Ui_AddChild(arg0, obj1);
    }
    obj2 = Heap_Alloc(0x58);
    if (obj2 != NULL) {
        *(void **)obj2 = lbl_8028FDB0;
        *(s32 *)((u8 *)obj2 + 4) = 0;
        *(void **)obj2 = lbl_80292230;
        *(s16 *)((u8 *)obj2 + 8) = -1;
        *(s16 *)((u8 *)obj2 + 0xA) = 0;
        *(s16 *)((u8 *)obj2 + 0xC) = -0x3A;
        *(s16 *)((u8 *)obj2 + 0xE) = 0x260;
        *(s16 *)((u8 *)obj2 + 0x10) = 0;
        *(s16 *)((u8 *)obj2 + 0x12) = 0;
        *(s16 *)((u8 *)obj2 + 0x14) = 0;
        *(s16 *)((u8 *)obj2 + 0x16) = 0x260;
        *(s16 *)((u8 *)obj2 + 0x18) = 0x3A;
        *(s16 *)((u8 *)obj2 + 0x1A) = 0;
        *(s16 *)((u8 *)obj2 + 0x1C) = 0;
        ((u8 *)obj2)[0x1E] = 0xFF;
        ((u8 *)obj2)[0x1F] = 0xFF;
        ((u8 *)obj2)[0x20] = 0xFF;
        ((u8 *)obj2)[0x21] = 0xFF;
        *(s16 *)((u8 *)obj2 + 0x22) = 0x258;
        *(s16 *)((u8 *)obj2 + 0x24) = 0;
        *(f32 *)((u8 *)obj2 + 0x28) = lbl_8036B2D8;
        *(f32 *)((u8 *)obj2 + 0x2C) = lbl_8036B2D8;
        *(f32 *)((u8 *)obj2 + 0x30) = lbl_8036B2D8;
        *(s32 *)((u8 *)obj2 + 0x34) = 0;
        *(s32 *)((u8 *)obj2 + 0x38) = 0;
        *(void **)obj2 = lbl_80293C84;
        *(s32 *)((u8 *)obj2 + 0x3C) = 0;
        *(s32 *)((u8 *)obj2 + 0x40) = 0;
        *(s32 *)((u8 *)obj2 + 0x44) = 0;
        *(s32 *)((u8 *)obj2 + 0x40) = 0;
        *(s32 *)((u8 *)obj2 + 0x48) = 0;
        ((u8 *)obj2)[0x4C] = 1;
        *(s16 *)((u8 *)obj2 + 0x4E) = 0;
        *(s16 *)((u8 *)obj2 + 0x50) = 0;
        *(s16 *)((u8 *)obj2 + 0x52) = 0;
        *(s16 *)((u8 *)obj2 + 0x54) = 0;
        *(void **)obj2 = lbl_80293C2C;
        *(s16 *)((u8 *)obj2 + 8) = 0x82;
        *(s32 *)((u8 *)obj2 + 0x34) |= 0x10;
        *(s16 *)((u8 *)obj2 + 0x4E) = 0x130;
        ((u8 *)obj2)[0x4C] = 2;
        *(s32 *)((u8 *)obj2 + 0x48) = 1;
        Ui_SetWidgetText(obj2, gUiUnitPanelStrings + 0x12C, 2, 0x130);
        *(s16 *)((u8 *)obj2 + 0x24) = 8;
        Ui_AddChild(arg0, obj2);
    }
    Ui_BringChildToFront(arg0, child);
    Ui_PlaySeCue(gUiUnitPanelStrings + 0x156, 0x64);
}

extern "C" void fn_801BA0C4(void *arg0) {
#pragma cplusplus reset
void *Ui_FindChild(void *,s32,s32);
void Ui_SlideWidgetChild(void *,void *,s16 *,s32);
void Process_Goto(void *,s32);
u32 Unit_CountExtraSkills(void *);
s32 Unit_GetSkillCapacityUsed(void *);
void *Res_GetEntry(u8);
u8 Skill_UnitMeetsReqs(void *,void *);
extern u8 gUiContext[];
s16 pos1[2],pos2[2];
void *unit;
s32 capacity;
u8 blocked;
void *a,*b;
s32 i;
s16 y;
void *skill;
a=Ui_FindChild(arg0,0x82,0);
b=Ui_FindChild(arg0,0x108,0);
y=M2C_FIELD(b,s16 *,0xC);
pos1[0]=0x260; pos1[1]=y;
Ui_SlideWidgetChild(arg0,b,pos1,0);
unit=*(void **)gUiContext;
if(Unit_CountExtraSkills(M2C_FIELD(arg0,void **,0x60))>=5U) blocked=1;
else {
capacity=M2C_FIELD(M2C_FIELD(unit,void **,0x18C),u8 *,0x40);
if(capacity<=Unit_GetSkillCapacityUsed(unit)) blocked=1;
else {
blocked=1;
for(i=0;i<0x62;i++) {
skill=Res_GetEntry((u8)i);
if(M2C_FIELD(skill,u8 *,0x19)!=0 && Skill_UnitMeetsReqs(skill,unit)) { blocked=0;break; }
}
}
}
if(blocked) {
pos2[0]=M2C_FIELD(a,s16 *,0xA);pos2[1]=-0x3A;
Ui_SlideWidgetChild(arg0,a,pos2,0);
Process_Goto(arg0,0x11);
} else {
M2C_FIELD(a,f32 *,0x30)=1.0f;
M2C_FIELD(b,f32 *,0x30)=1.0f;
}
}

#pragma cplusplus reset

void fn_801BA200(void *self) {
void *Ui_FindChild(void*,s32,s32); void *Res_GetEntry(s32); void fn_8017AA48(void*,void*,void*); void *fn_80105710(void*);
s8 Unit_FindItemSlot(void*,void*);s8 fn_80093010(void*,void*);void Unit_RemoveItem(void*,s32);u8 fn_8014D8DC(void*);
s32 fn_800C39A4(void*,void*);void fn_800C3864(void*,s32);void Allegiance_SetMask(s32,s32,s32,s32,s32,s32,s32,s32,void*);
extern u8 gUiContext[],gBattleState[],gConvoy[],gUnits[];extern f32 lbl_8036B2DC;
u8 mask[8];
void *child;
void *entry;
u8 *unit;
void *item;
s32 i;
child=Ui_FindChild(self,0x82,0);
*(f32*)((u8*)child+0x30)=lbl_8036B2DC;
child=Ui_FindChild(self,0x108,0);
*(f32*)((u8*)child+0x30)=lbl_8036B2DC;
Ui_FindChild(self,0x109,0);
entry=Res_GetEntry(gUiContext[0x14]);
fn_8017AA48(*(void**)((u8*)self+0x60),entry,self);
unit=*(u8**)gUiContext;
item=fn_80105710(entry);
if(item) {
if(Unit_FindItemSlot(unit,item)>=0) {
Unit_RemoveItem(unit,fn_80093010(unit,item));
} else if(fn_8014D8DC(gBattleState) && fn_800C39A4(gConvoy,item)>=0) {
fn_800C3864(gConvoy,fn_800C39A4(gConvoy,item));
} else {
Allegiance_SetMask(1,0,0,0,0,1,0,0,mask);
for(i=1;i<=0x9f;i++) {
if((u8)i) unit=gUnits+((u8)i-1)*0x280;else unit=0;
if(*(u32*)(unit+0x188) && mask[*(u8*)(*(u8**)(unit+0x190)+8)] && Unit_FindItemSlot(unit,item)>=0) {
Unit_RemoveItem(unit,fn_80093010(unit,item)); break;
}
}
}
}
}

#pragma cplusplus on
extern "C" void fn_801BA3E8(void *arg0) {
    void *Ui_FindChild(void *, s32, s32);
    void Process_ClearFunc(void *);
    void Process_Goto(void *, s32);
    extern u8 gUiContext[];
    class Pair {
    public:
        s16 x, y;
        Pair() {}
        Pair(s16 a, s16 b) : x(a), y(b) {}
        Pair(const Pair &o) { *(u32 *)this = *(u32 *)&o; }
        Pair &operator=(const Pair &o) {
            *(u32 *)this = *(u32 *)&o;
            return *this;
        }
    };
    void Ui_SlideWidgetChild(void *, void *, const Pair &, s32);
    void *temp;

    temp = Ui_FindChild(arg0, 0x108, 0);
    switch ((s32)gUiContext[8]) {
    case 0x81:
        Process_ClearFunc(arg0);
        return;
    case 0x80:
        Ui_SlideWidgetChild(arg0, temp, Pair(0x260, *(s16 *)((u8 *)temp + 0xC)), 0);
        Process_Goto(arg0, 0x13);
        return;
    }
}

#pragma cplusplus on
#pragma opt_common_subs off
extern "C" void fn_801BA47C(void *arg0) {
    void *Heap_Alloc(s32);
    void *Res_GetEntry(u8);
    void Ui_AddChild(void *, void *);
    void Ui_SlideWidgetChildMode1(void *, void *, s16 *, s32);
    void *fn_8013BC10(void *, void *);
    void Ui_CreateMenu(void *, void *, s32);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *, void *);
    s32 strlen(const char *);
    void String_AssignCStr(void *, const void *, s32);
    extern u8 lbl_8028FDB0[], lbl_80292230[], lbl_8029186C[], gUiContext[], gUiUnitPanelStrings[];
    extern f32 lbl_8036B2D8;
    s16 pos[2];
    s32 i;
    UnitHireMenu *menu;
    UnitHireItem *item;
    u8 *w;
    void *self = arg0;
    void *child;
    w = (u8 *)Heap_Alloc(0x4C);
    if (w) {
        *(void **)(w+0) = lbl_8028FDB0;
        *(s32 *)(w+4) = 0;
        *(void **)(w+0) = lbl_80292230;
        *(s16 *)(w+8) = -1;
        *(s16 *)(w+0xA) = 0x260;
        *(s16 *)(w+0xC) = 0x7C;
        *(s16 *)(w+0xE) = 0x368;
        *(s16 *)(w+0x10) = 0x16E;
        *(s16 *)(w+0x12) = 0;
        *(s16 *)(w+0x14) = 0;
        *(s16 *)(w+0x16) = 0x108;
        *(s16 *)(w+0x18) = 0xF2;
        *(s16 *)(w+0x1A) = 0;
        *(s16 *)(w+0x1C) = 0;
        w[0x1E] = 255; w[0x1F] = 255; w[0x20] = 255; w[0x21] = 255;
        *(s16 *)(w+0x22) = 0x1E0;
        *(s16 *)(w+0x24) = 0;
        *(f32 *)(w+0x28) = 1.0f;
        *(f32 *)(w+0x2C) = 1.0f;
        *(f32 *)(w+0x30) = 1.0f;
        *(s32 *)(w+0x34) = 0;
        *(s32 *)(w+0x38) = 0;
        *(void **)(w+0) = lbl_8029186C;
        *(s32 *)(w+0x3C) = 0;
        *(s16 *)(w+0x40) = 20;
        *(s16 *)(w+0x42) = 8;
        ((UnitHireWidget *)w)->init();
    }
    child = Res_GetEntry(gUiContext[0x14]);
    *(s16 *)(w+8) = 0x108;
    *(s16 *)(w+0x24) = 8;
    *(u32 *)(w+0x34) |= 0x10;
    *(void **)(w+0x3C) = child;
    Ui_AddChild(self,w);
    s16 y = *(s16 *)(w+0xC);
    pos[0] = 0x148;
    pos[1] = y;
    Ui_SlideWidgetChildMode1(self,w,pos,0);
    menu = (UnitHireMenu *)fn_8013BC10(gUiUnitPanelStrings+0x16E,gUiUnitPanelStrings+0xEC);
    M2C_FIELD(menu,s16 *,0xC)=0xE8;
    M2C_FIELD(menu,s16 *,8)=0x148;
    M2C_FIELD(menu,s16 *,0xA)=0x38;
    M2C_FIELD(menu,u8 *,0x24)=1;
    for(i=0;menu->get(i)!=0;i++) {
        item=menu->get(i);
        item->set2(2);
        item->set3(3);
    }
    Ui_CreateMenu(menu,self,0);
    child=Ui_FindChild(self,0x82,0);
    String_AssignCStr((u8 *)child+0x3C,gUiUnitPanelStrings+0xF7,strlen((char *)gUiUnitPanelStrings+0xF7));
    child=Ui_FindChild(self,-0x1000,0);
    if(child) Ui_SetWidgetText(child,gUiUnitPanelStrings+0xF8);
}
#pragma opt_common_subs reset
#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on
extern "C" void Ui_HandleUnitCursorInput(void *arg0) {
/* Handle map-cursor input over a unit: select/deploy with A, info with X, cancel with B. */
void Process_Goto(void *,s32); void Process_ClearFunc(void *);
s32 fn_80105814(void *); u8 Status_Test(void *,u8); void *fn_801362C8(void *);
void Ui_UpdatePanelWidgets(void *); void *Ui_FindChild(void *,s32,s32);
void Ui_PlaySeCue(void *,s32); u8 Ui_IsUnitInfoPopupOpen(void *);
void Ui_ShowUnitInfoText(void *,s32,f32,f32); void Ui_HideUnitInfoPopup(void *);
void Ui_OpenUnitInfoText(void *,void *,s32,f32,f32);
void Ui_CreateMsgPopup(void *,void *,f32,f32); s32 Unit_GetSkillCapacityUsed(void *);
extern u8 gUiUnitPanelStrings[],gUiContext[],gUnitInfoPopup[];
extern u32 gUiInputFlags; extern void *gPadInput; extern s32 gUnitInfoPopupFlag;
class Pair { public: s16 x,y; Pair() {} Pair(s16 a,s16 b):x(a),y(b) {} Pair(const Pair &o) { *(u32 *)this=*(u32 *)&o; } Pair &operator=(const Pair &o) { *(u32 *)this=*(u32 *)&o; return *this; } };
void Ui_SlideWidgetChild(void *,void *,const Pair &,s32);
struct Obj { virtual void destroy(s32); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual Pair v9(); s32 refs; };
void *self,*owner,*unit,*temp;
s32 btn; u8 gate; s32 flags;
u32 pos1,pos2,pos3,pos4;
self=arg0; owner=*(void **)gUiContext;
unit=fn_801362C8(M2C_FIELD(self,void **,0x68));
Ui_UpdatePanelWidgets(self);
if(unit!=fn_801362C8(M2C_FIELD(self,void **,0x68))) {
unit=fn_801362C8(M2C_FIELD(self,void **,0x68));
if(Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
if(unit) {
*(Pair *)&pos1=((Obj *)M2C_FIELD(self,void **,0x68))->v9();
Ui_ShowUnitInfoText(gUnitInfoPopup,fn_80105814(unit),(f32)*(s16 *)&pos1,(f32)*((s16 *)&pos1+1));
} else Ui_HideUnitInfoPopup(gUnitInfoPopup);
}
}
gate=0; flags=gUiInputFlags;
if((flags&0x10)&&!(flags&0x20)) gate=1;
if(!gate) {
s32 a=M2C_FIELD(gPadInput,s32 *,4);
s32 changed=M2C_FIELD(gPadInput,s32 *,8)^a;
M2C_FIELD(M2C_FIELD(self,void **,0x6c),void **,0x3c)=unit;
btn=a&changed;
if((btn&0x100)&&unit&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
s32 remaining=M2C_FIELD(M2C_FIELD(owner,void **,0x18c),u8 *,0x40);
remaining-=Unit_GetSkillCapacityUsed(owner);
if(Status_Test((u8 *)owner+0x1bc,M2C_FIELD(unit,u8 *,0x18))) {
*(Pair *)&pos2=((Obj *)M2C_FIELD(self,void **,0x68))->v9();
Ui_CreateMsgPopup(gUiUnitPanelStrings+0x17a,self,(f32)*(s16 *)&pos2,(f32)*((s16 *)&pos2+1));
return;
}
if(remaining<M2C_FIELD(unit,u8 *,0x1a)) {
*(Pair *)&pos3=((Obj *)M2C_FIELD(self,void **,0x68))->v9();
Ui_CreateMsgPopup(gUiUnitPanelStrings+0x18c,self,(f32)*(s16 *)&pos3,(f32)*((s16 *)&pos3+1));
return;
}
gUiContext[0x14]=M2C_FIELD(unit,u8 *,0x18);
temp=M2C_FIELD(self,void **,0x68);
Ui_SlideWidgetChild(self,temp,Pair(0x260,M2C_FIELD(temp,s16 *,0xc)),0);
temp=M2C_FIELD(self,void **,0x6c);
Ui_SlideWidgetChild(self,temp,Pair(0x260,M2C_FIELD(temp,s16 *,0xc)),0);
Ui_PlaySeCue(gUiUnitPanelStrings+0x10c,100); Process_ClearFunc(self); return;
}
if((btn&0x800)&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)&&unit) {
*(Pair *)&pos4=((Obj *)M2C_FIELD(self,void **,0x68))->v9();
Ui_OpenUnitInfoText(gUnitInfoPopup,self,fn_80105814(unit),(f32)*(s16 *)&pos4,(f32)*((s16 *)&pos4+1));
*(s32 *)gUnitInfoPopup|=gUnitInfoPopupFlag; return;
}
if((btn&0xa00)&&Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {Ui_HideUnitInfoPopup(gUnitInfoPopup);return;}
if((btn&0x200)&&!Ui_IsUnitInfoPopupOpen(gUnitInfoPopup)) {
temp=M2C_FIELD(self,void **,0x68);
Ui_SlideWidgetChild(self,temp,Pair(0x260,M2C_FIELD(temp,s16 *,0xc)),1);
{Obj *p=M2C_FIELD(self,Obj **,0x68);
if(p) {if(--p->refs==0 && p) p->destroy(1); M2C_FIELD(self,void **,0x68)=0;}}
temp=M2C_FIELD(self,void **,0x6c);
Ui_SlideWidgetChild(self,temp,Pair(0x260,M2C_FIELD(temp,s16 *,0xc)),0);
{Obj *p=M2C_FIELD(self,Obj **,0x6c);
if(p) {if(--p->refs==0 && p) p->destroy(1); M2C_FIELD(self,void **,0x6c)=0;}}
temp=Ui_FindChild(self,0x82,0);
Ui_SlideWidgetChild(self,temp,Pair(M2C_FIELD(temp,s16 *,0xa),-0x3a),0);
Ui_PlaySeCue(gUiUnitPanelStrings+0x11c,100); Process_Goto(self,0x11);
}
}
}
#pragma cplusplus reset

void fn_801BAC40(void *arg0) {
    void *Ui_FindChild(void *, s32, s32);
    void Ui_AddChild(void *, void *);
    void Ui_SlideWidgetChildMode1(void *, void *, s16 *, s32);
    void Ui_SetWidgetText(void *, void *);
    void Ui_BringChildToFront(void *, void *);
    extern u8 gUiUnitPanelStrings[];
    s16 a[2], b[2], c[2];
    void *first;
    void *child;
    void *caption;
    s16 x, y;
    first = Ui_FindChild(arg0, 0x107, 0);
    if (!first) {
        first = M2C_FIELD(arg0, void **, 0x68);
        Ui_AddChild(arg0, first);
    }
    if (M2C_FIELD(first, s16 *, 0xA) != 0x148) {
        y = M2C_FIELD(first, s16 *, 0xC);
        a[0] = 0x148; a[1] = y;
        Ui_SlideWidgetChildMode1(arg0, first, a, 0);
    }
    child = Ui_FindChild(arg0, 0x109, 0);
    if (!child) {
        child = M2C_FIELD(arg0, void **, 0x6C);
        Ui_AddChild(arg0, child);
    }
    if (M2C_FIELD(child, s16 *, 0xA) != 0x14C) {
        y = M2C_FIELD(child, s16 *, 0xC);
        b[0] = 0x14C; b[1] = y;
        Ui_SlideWidgetChildMode1(arg0, child, b, 0);
    }
    caption = Ui_FindChild(arg0, 0x82, 0);
    if (M2C_FIELD(caption, s16 *, 0xC) != 0x28) {
        x = M2C_FIELD(caption, s16 *, 0xA);
        c[0] = x; c[1] = 0x28;
        Ui_SlideWidgetChildMode1(arg0, caption, c, 0);
    }
    Ui_SetWidgetText(caption, gUiUnitPanelStrings + 0x12C);
    Ui_BringChildToFront(arg0, first);
    child = Ui_FindChild(arg0, -0x1000, 0);
    if (child) Ui_SetWidgetText(child, gUiUnitPanelStrings + 0x142);
}

#pragma cplusplus on
#pragma use_lmw_stmw on
#pragma global_optimizer off
extern "C" void fn_801BADB0(void *arg0) {
    void *Heap_Alloc(s32);
    s32 Res_GetEntry(u8);
    void List_Insert(void *, void *, void *, void *);
    void Ui_BringChildToFront(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_AddChild(void *, void *);
    void Ui_SlideWidgetChild(void *, void *, s16 *, s32);
    void fn_801402A0(void *, void *, s16 *, s32);
    void Ui_PlaySeCue(void *, s32);
    void Ui_SetWidgetText(void *, void *, s32, s32);
    void fn_8017BB94(void *);
    void *fn_801BEB24(void *, s16, s16, s16, s16);

    extern u8 gUiUnitPanelStrings[];
    extern void *lbl_8028FDB0[];
    extern void *lbl_80292230[];
    extern void *lbl_80293C2C[];
    extern void *lbl_80293C84[];
    extern void *lbl_80296194[];
    extern s32 lbl_80297E6C[];
    extern u8 gUiContext[];
    extern f32 lbl_8036B2D8;

    struct Obj {
        virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0;
        virtual void v3() = 0; virtual void v4() = 0; virtual void v5() = 0;
        virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0;
    };
    struct T { u8 f(s32); };
    typedef u8 (T::*PTMF)(s32);
    struct Pair { PTMF ptmf; s32 arg; };

    void *ctx;
    void *self;
    s32 id;
    s32 t2;
    s32 t1;
    s32 t0;
    s32 i;
    void *obj68;
    void *listBase;
    void *child;
    void *alloc;
    void *temp;
    f32 zf;
    s16 w;

    self = arg0;
    Pair call;
    Pair p[2];
    s16 pair18[2];
    s16 pair14[2];
    s32 sp10;
    void *spC;
    s32 sp8;

    temp = Ui_FindChild(self, 0x100, 0);
    w = (s16)(*(s16 *)((u8 *)temp + 0x10) - *(s16 *)((u8 *)temp + 0xC));
    pair18[0] = *(s16 *)((u8 *)temp + 0xA);
    pair18[1] = -w;
    Ui_SlideWidgetChild(self, temp, pair18, 0);
    child = *(void **)((u8 *)self + 0x60);
    fn_8017BB94(child);
    *(u8 *)((u8 *)child + 0x3C) = 0;
    if (*(s16 *)((u8 *)child + 0xC) != 0x7C) {
        pair14[0] = *(s16 *)((u8 *)child + 0xA);
        pair14[1] = 0x7C;
        fn_801402A0(self, child, pair14, 0);
    }
    ctx = *(void **)gUiContext;
    alloc = Heap_Alloc(0xD0);
    if (alloc) {
        alloc = fn_801BEB24(alloc, 0x260, 0x68, 0xE2, 0x1E0);
    }
    *(void **)((u8 *)self + 0x68) = alloc;
    {
        void *o = *(void **)((u8 *)self + 0x68);
        if (o) {
            *(s32 *)((u8 *)o + 4) += 1;
        }
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x68) + 8) = 0x107;
    i = 0;
    id = 0;
    p[0].arg = (s32)ctx;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x68) + 0x24) = 8;
    p[1].arg = (s32)ctx;
    {
        void *o = *(void **)((u8 *)self + 0x68);
        *(s32 *)((u8 *)o + 0x34) |= 0x10;
    }
    *(void **)((u8 *)*(void **)((u8 *)self + 0x68) + 0xCC) = ctx;
    t0 = lbl_80297E6C[0];
    obj68 = *(void **)((u8 *)self + 0x68);
    t1 = lbl_80297E6C[1];
    t2 = lbl_80297E6C[2];
    listBase = (u8 *)obj68 + 0x6C;
    *(s32 *)&p[0].ptmf = t0;
    *((s32 *)&p[0].ptmf + 1) = t1;
    *((s32 *)&p[0].ptmf + 2) = t2;
    *(s32 *)&p[1].ptmf = t0;
    *((s32 *)&p[1].ptmf + 1) = t1;
    *((s32 *)&p[1].ptmf + 2) = t2;
    for (; i < 0x62; i++) {
        id = Res_GetEntry((u8)i);
        *(s32 *)&call.ptmf = t0;
        *((s32 *)&call.ptmf + 1) = t1;
        *((s32 *)&call.ptmf + 2) = t2;
        call.arg = (s32)ctx;
        if ((((T *)id)->*call.ptmf)((s32)ctx) != 0) {
            sp10 = id;
            spC = listBase;
            List_Insert(&sp8, (u8 *)obj68 + 0x68, &spC, &sp10);
        }
    }
    Ui_AddChild(self, *(void **)((u8 *)self + 0x68));
    obj68 = Heap_Alloc(0x44);
    if (obj68) {
        s32 zero = 0;
        *(void **)obj68 = lbl_8028FDB0;
        *(s32 *)((u8 *)obj68 + 4) = zero;
        *(void **)obj68 = lbl_80292230;
        *(s16 *)((u8 *)obj68 + 8) = -1;
        *(s16 *)((u8 *)obj68 + 0xA) = 0x260;
        *(s16 *)((u8 *)obj68 + 0xC) = 0x14E;
        *(s16 *)((u8 *)obj68 + 0xE) = 0x349;
        *(s16 *)((u8 *)obj68 + 0x10) = 0x195;
        *(s16 *)((u8 *)obj68 + 0x12) = (s16)zero;
        *(s16 *)((u8 *)obj68 + 0x14) = (s16)zero;
        *(s16 *)((u8 *)obj68 + 0x16) = 0xE9;
        *(s16 *)((u8 *)obj68 + 0x18) = 0x47;
        *(s16 *)((u8 *)obj68 + 0x1A) = (s16)zero;
        *(s16 *)((u8 *)obj68 + 0x1C) = (s16)zero;
        ((u8 *)obj68)[0x1E] = 0xFF;
        ((u8 *)obj68)[0x1F] = 0xFF;
        ((u8 *)obj68)[0x20] = 0xFF;
        ((u8 *)obj68)[0x21] = 0xFF;
        *(s16 *)((u8 *)obj68 + 0x22) = 0x1F4;
        *(s16 *)((u8 *)obj68 + 0x24) = (s16)zero;
        zf = lbl_8036B2D8;
        *(f32 *)((u8 *)obj68 + 0x28) = zf;
        *(f32 *)((u8 *)obj68 + 0x2C) = zf;
        *(f32 *)((u8 *)obj68 + 0x30) = zf;
        *(s32 *)((u8 *)obj68 + 0x34) = zero;
        *(s32 *)((u8 *)obj68 + 0x38) = zero;
        *(void **)obj68 = lbl_80296194;
        *(s32 *)((u8 *)obj68 + 0x3C) = zero;
        ((Obj *)obj68)->v8();
    }
    *(void **)((u8 *)self + 0x6C) = obj68;
    {
        void *o = *(void **)((u8 *)self + 0x6C);
        if (o) {
            *(s32 *)((u8 *)o + 4) += 1;
        }
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x6C) + 8) = 0x109;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x6C) + 0x24) = 8;
    {
        void *o = *(void **)((u8 *)self + 0x6C);
        *(s32 *)((u8 *)o + 0x34) |= 0x10;
    }
    Ui_AddChild(self, *(void **)((u8 *)self + 0x6C));
    ctx = Heap_Alloc(0x58);
    if (ctx) {
        s32 zero = 0;
        *(void **)ctx = lbl_8028FDB0;
        *(s32 *)((u8 *)ctx + 4) = zero;
        *(void **)ctx = lbl_80292230;
        *(s16 *)((u8 *)ctx + 8) = -1;
        *(s16 *)((u8 *)ctx + 0xA) = (s16)zero;
        *(s16 *)((u8 *)ctx + 0xC) = -0x3A;
        *(s16 *)((u8 *)ctx + 0xE) = 0x260;
        *(s16 *)((u8 *)ctx + 0x10) = (s16)zero;
        *(s16 *)((u8 *)ctx + 0x12) = (s16)zero;
        *(s16 *)((u8 *)ctx + 0x14) = (s16)zero;
        *(s16 *)((u8 *)ctx + 0x16) = 0x260;
        *(s16 *)((u8 *)ctx + 0x18) = 0x3A;
        *(s16 *)((u8 *)ctx + 0x1A) = (s16)zero;
        *(s16 *)((u8 *)ctx + 0x1C) = (s16)zero;
        ((u8 *)ctx)[0x1E] = 0xFF;
        ((u8 *)ctx)[0x1F] = 0xFF;
        ((u8 *)ctx)[0x20] = 0xFF;
        ((u8 *)ctx)[0x21] = 0xFF;
        *(s16 *)((u8 *)ctx + 0x22) = 0x258;
        *(s16 *)((u8 *)ctx + 0x24) = (s16)zero;
        zf = lbl_8036B2D8;
        *(f32 *)((u8 *)ctx + 0x28) = zf;
        *(f32 *)((u8 *)ctx + 0x2C) = zf;
        *(f32 *)((u8 *)ctx + 0x30) = zf;
        *(s32 *)((u8 *)ctx + 0x34) = zero;
        *(s32 *)((u8 *)ctx + 0x38) = zero;
        *(void **)ctx = lbl_80293C84;
        *(s32 *)((u8 *)ctx + 0x3C) = zero;
        *(s32 *)((u8 *)ctx + 0x40) = zero;
        *(s32 *)((u8 *)ctx + 0x44) = zero;
        *(s32 *)((u8 *)ctx + 0x40) = zero;
        *(s32 *)((u8 *)ctx + 0x48) = zero;
        ((u8 *)ctx)[0x4C] = 1;
        *(s16 *)((u8 *)ctx + 0x4E) = (s16)zero;
        *(s16 *)((u8 *)ctx + 0x50) = (s16)zero;
        *(s16 *)((u8 *)ctx + 0x52) = (s16)zero;
        *(s16 *)((u8 *)ctx + 0x54) = (s16)zero;
        *(void **)ctx = lbl_80293C2C;
        *(s16 *)((u8 *)ctx + 8) = 0x82;
        *(s32 *)((u8 *)ctx + 0x34) |= 0x10;
        *(s16 *)((u8 *)ctx + 0x4E) = 0x130;
        *(s32 *)((u8 *)ctx + 0x48) = 1;
        ((u8 *)ctx)[0x4C] = 2;
        Ui_SetWidgetText(ctx, gUiUnitPanelStrings + 0x12C, 1, 0x130);
        *(s16 *)((u8 *)ctx + 0x24) = 8;
        Ui_AddChild(self, ctx);
    }
    Ui_BringChildToFront(self, *(void **)((u8 *)self + 0x68));
    Ui_PlaySeCue(gUiUnitPanelStrings + 0x156, 0x64);
}
#pragma global_optimizer reset
#pragma cplusplus reset

/* Layout the unit-manage panel: attach list, slide inventory into place, init help cursor, set caption. */
void Ui_LayoutUnitManagePanel(void *panel) {
    void *Ui_FindChild(void *, s32, s32);
    void Ui_AddChild(void *, void *);
    void Ui_SlideWidgetChildMode1(void *, void *, s16 *, s32);
    void fn_801402A0(void *, void *, s16 *, s32);
    void *Heap_Alloc(u32);
    void Ui_CreateMenu(void *, void *, s32);
    void Ui_SetWidgetText(void *, void *);
    extern u8 lbl_8028459C[];
    extern u8 lbl_80292090[];
    extern u8 lbl_80297ED4[];
    extern u8 lbl_80297E84[];
    extern u8 gUiMenuDrawVtbl[];
    extern u8 lbl_80297C08[];
    extern u8 lbl_802920E0[];
    extern u8 gUiUnitPanelStrings[];
    extern s8 lbl_80368260;
    extern void *volatile lbl_80368264;
    extern s8 lbl_8036826C;
    extern void *lbl_80368270;
    struct { s16 x; s16 y; } listPos;
    struct { s16 x; s16 y; } invPos;
    void *list;
    void *invPanel;
    void *help;

    list = Ui_FindChild(panel, 0x100, 0);
    if (list == NULL) {
        list = M2C_FIELD(panel, void **, 0x48);
        Ui_AddChild(panel, list);
    }
    if (M2C_FIELD(list, s16 *, 0xC) != 0x10) {
        listPos.x = M2C_FIELD(list, s16 *, 0xA);
        listPos.y = 0x10;
        Ui_SlideWidgetChildMode1(panel, list, &listPos.x, 0);
    }
    M2C_FIELD(list, u8 *, 0x4D) = 0;
    M2C_FIELD(list, f32 *, 0x30) = 0.5f;
    invPanel = M2C_FIELD(panel, void **, 0x60);
    M2C_FIELD(invPanel, u8 *, 0x3C) = 0;
    if (M2C_FIELD(invPanel, s16 *, 0xC) != 0x94) {
        invPos.x = M2C_FIELD(invPanel, s16 *, 0xA);
        invPos.y = 0x94;
        fn_801402A0(panel, invPanel, &invPos.x, 0);
    }
    if (lbl_80368260 == 0) {
        lbl_80368264 = lbl_8028459C;
        lbl_80368264 = lbl_80292090;
        lbl_80368264 = lbl_80297ED4;
        lbl_80368260 = 1;
    }
    if (lbl_8036826C == 0) {
        lbl_80368270 = lbl_80297E84;
        lbl_8036826C = 1;
    }
    help = Heap_Alloc(0x20);
    if (help != NULL) {
        M2C_FIELD(help, void **, 4) = gUiMenuDrawVtbl;
        M2C_FIELD(help, void **, 0) = lbl_80297C08;
        M2C_FIELD(help, void **, 4) = lbl_802920E0;
        M2C_FIELD(help, s16 *, 8) = 0;
        M2C_FIELD(help, s16 *, 0xA) = 0;
        M2C_FIELD(help, s16 *, 0xC) = 0x80;
        M2C_FIELD(help, s16 *, 0xE) = 0;
        M2C_FIELD(help, s16 *, 0x10) = 2;
        M2C_FIELD(help, s16 *, 0x12) = 0xC;
        M2C_FIELD(help, s16 *, 0x14) = 0x10;
        M2C_FIELD(help, s16 *, 0x16) = 0;
        M2C_FIELD(help, f32 *, 0x18) = 0.0f;
        M2C_FIELD(help, s16 *, 0x1C) = 0x20;
        M2C_FIELD(help, s16 *, 0x1E) = 4;
    }
    M2C_FIELD(help, s16 *, 0xC) = 0x78;
    M2C_FIELD(help, s16 *, 8) = 0x181;
    M2C_FIELD(help, s16 *, 0xA) = 0xB4;
    M2C_FIELD(help, s16 *, 0x14) = 0x1C;
    M2C_FIELD(help, f32 *, 0x18) = 200.0f;
    M2C_FIELD(help, s16 *, 0x1E) = 4;
    Ui_CreateMenu(help, panel, 0);
    help = Ui_FindChild(panel, -0x1000, 0);
    if (help != NULL) {
        Ui_SetWidgetText(help, gUiUnitPanelStrings + 0x142);
    }
}

/* Handle unit-manage list input: sync inventory widgets on selection change; A confirms unit, Y/X open side panels, B backs out. */
void Ui_HandleUnitManageCursorInput(void *panel) {
    void Process_Goto(void *, s32);
    void UiCtx_BindUnit(void *, u32);
    u32 Ui_ListGetSelected(void *);
    void Ui_UpdatePanelWidgets(void *);
    void Ui_CloseChildAnim(void *, void *, s32);
    void Ui_SlideWidgetChild(void *, void *, s16 *, s32);
    void Ui_PlaySeCue(void *, s32);
    void fn_801694AC(u32, void *);
    void fn_801695BC(u32, void *, s32);
    void fn_8017BB94(void *);
    s32 Unit_GetSkillCapacityUsed(u32);
    extern u8 gUiUnitPanelStrings[];
    extern u32 gUiContext[];
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    s16 slidePos[2];
    s32 held;
    s32 btn;
    register u8 gate;
    register int flags;
    s16 savedY;
    unsigned int unit;
    void *invPanel;
    void *sidePanel;

    unit = Ui_ListGetSelected(M2C_FIELD(panel, void **, 0x48));
    Ui_UpdatePanelWidgets(panel);
    if (unit != Ui_ListGetSelected(M2C_FIELD(panel, void **, 0x48))) {
        unit = Ui_ListGetSelected(M2C_FIELD(panel, void **, 0x48));
        sidePanel = M2C_FIELD(panel, void **, 0x64);
        M2C_FIELD(sidePanel, u32 *, 0x3C) = unit;
        invPanel = M2C_FIELD(panel, void **, 0x60);
        M2C_FIELD(invPanel, u32 *, 0x4C) = unit;
        fn_8017BB94(invPanel);
        M2C_FIELD(invPanel, f32 *, 0x50) = (f32)Unit_GetSkillCapacityUsed(unit);
    }
    flags = gUiInputFlags;
    gate = 0;
    if ((flags & 0x10) && !(flags & 0x20)) {
        gate = 1;
    }
    if (!gate) {
        held = M2C_FIELD(gPadInput, s32 *, 4);
        btn = held & (M2C_FIELD(gPadInput, s32 *, 8) ^ held);
        if ((btn & 0x100) && unit) {
            UiCtx_BindUnit(gUiContext, unit);
            M2C_FIELD(M2C_FIELD(panel, void **, 0x48), f32 *, 0x30) = 0.5f;
            sidePanel = M2C_FIELD(panel, void **, 0x64);
            savedY = M2C_FIELD(sidePanel, s16 *, 0xC);
            slidePos[0] = 0x260;
            slidePos[1] = savedY;
            Ui_SlideWidgetChild(panel, sidePanel, slidePos, 0);
            Ui_CloseChildAnim(panel, M2C_FIELD(panel, void **, 0x50), 0);
            invPanel = M2C_FIELD(panel, void **, 0x60);
            M2C_FIELD(invPanel, u8 *, 0x54) = 1;
            Process_Goto(panel, 0x11);
            Ui_PlaySeCue(gUiUnitPanelStrings + 0x10C, 0x64);
        } else if ((btn & 0x800) && unit) {
            fn_801695BC(unit, panel, 0x1000000);
            M2C_FIELD(panel, u8 *, 0x44) = 0x10;
            Process_Goto(panel, 0x1D);
        } else if ((btn & 0x400) && unit) {
            fn_801694AC(unit, panel);
            M2C_FIELD(panel, u8 *, 0x44) = 0x10;
            Process_Goto(panel, 0x1E);
        } else if (btn & 0x200) {
            Process_Goto(panel, 0x1C);
            Ui_PlaySeCue(gUiUnitPanelStrings + 0x11C, 0x64);
        }
    }
}

void fn_801BB608(void *arg0)
{
    void *Ui_FindChild(void *, s32, s32);
    void Ui_AddChild(void *, void *);
    void Ui_SlideWidgetChildMode1(void *, void *, s16 *, s32);
    void fn_801402A0(void *, void *, s16 *, s32);
    f32 Ui_GetWorldScale(void *);
    void Ui_OpenChildAnim(void *, void *, s32);
    void Ui_BringChildToFront(void *, void *);
    void Ui_SetWidgetText(void *, void *);

    extern u8 gUiUnitPanelStrings[];
    extern f32 lbl_8036B2D8;

    u8 *self;
    u8 *first;
    u8 *child;
    s16 pos10[2];
    s16 posC[2];
    s16 pos8[2];

    self = (u8 *)arg0;

    first = (u8 *)Ui_FindChild(self, 0x100, 0);

    if (first == 0) {
        first = *(u8 **)(self + 0x48);
        Ui_AddChild(self, first);
    }

    if (*(s16 *)(first + 0xC) != 0x10) {
        pos10[0] = *(s16 *)(first + 0xA);
        pos10[1] = 0x10;

        Ui_SlideWidgetChildMode1(self, first, pos10, 0);
    }

    first[0x4D] = 0;
    *(f32 *)(first + 0x30) = lbl_8036B2D8;

    child = (u8 *)Ui_FindChild(self, 0x101, 0);

    if (child == 0) {
        child = *(u8 **)(self + 0x64);
        Ui_AddChild(self, child);
    }

    if (*(s16 *)(child + 0xA) != 0x148) {
        posC[0] = 0x148;
        posC[1] = *(s16 *)(child + 0xC);

        Ui_SlideWidgetChildMode1(self, child, posC, 0);
    }

    child = (u8 *)Ui_FindChild(self, 0x102, 0);

    if (child == 0) {
        child = *(u8 **)(self + 0x50);
        Ui_AddChild(self, child);
    }

    if (Ui_GetWorldScale(child) < lbl_8036B2D8) {
        Ui_OpenChildAnim(self, child, 0);
    }

    child = (u8 *)Ui_FindChild(self, 0x106, 0);

    if (child == 0) {
        child = *(u8 **)(self + 0x60);
        Ui_AddChild(self, child);
    }

    if (*(s16 *)(child + 0xC) != 0x94) {
        pos8[0] = *(s16 *)(child + 0xA);
        pos8[1] = 0x94;

        fn_801402A0(self, child, pos8, 0);
    }

    child[0x54] = 0;
    child[0x3C] = 0;

    Ui_BringChildToFront(self, first);

    child = (u8 *)Ui_FindChild(self, -0x1000, 0);

    if (child != 0) {
        Ui_SetWidgetText(
            child,
            gUiUnitPanelStrings + 0x1A3
        );
    }
}

#pragma cplusplus on
extern "C" void fn_801BB7E0(void *arg0) {
#pragma opt_common_subs off
    void *Heap_Alloc(s32);
    void *Ui_ListGetSelected(void *);
    void fn_8013B064(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_RemoveChild(void *, void *);
    void Ui_AddChild(void *, void *);
    void *fn_80179F8C(void *, s16, s16, s16, s16, s32);
    void fn_8017BB94(void *);
    s32 Unit_GetSkillCapacityUsed(s32);
    u8 *Ui_GetColor(s32);
    extern u8 gUiUnitPanelStrings[];
    extern u8 lbl_8028FDB0[];
    extern u8 lbl_80291988[];
    extern u8 lbl_80292178[];
    extern u8 lbl_80292230[];
    extern u8 lbl_80295404[];
    extern u8 gUnitLists[];
    extern f32 lbl_8036B2D8;
    extern f32 lbl_8036B2E0;

    struct Obj {
        virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0;
        virtual void v3() = 0; virtual void v4() = 0; virtual void v5() = 0;
        virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0;
        virtual void v9() = 0; virtual void v10() = 0; virtual void v11(void *) = 0;
        virtual void v12(s32) = 0;
    };

    void *self = arg0;
    void *p;
    void *q;

    Ui_RemoveChild(self, Ui_FindChild(self, 0x80, 0));
    Ui_RemoveChild(self, Ui_FindChild(self, 0x81, 0));

    p = Heap_Alloc(0xD8);
    if (p != NULL) {
        p = fn_80179F8C(p, 0x38, 0x10, 0x1F0, 0x90, 0x226);
    }
    *(void **)((u8 *)self + 0x48) = p;
    q = *(void **)((u8 *)self + 0x48);
    if (q != NULL) {
        *(s32 *)((u8 *)q + 4) = *(s32 *)((u8 *)q + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 0x24) = 8;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 0x64) = 8;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 8) = 0x100;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 0x5A) = 0x1C;
    ((Obj *)*(void **)((u8 *)self + 0x48))->v12(4);
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 0x58) = 3;

    {
        void *hold = *(void **)((u8 *)self + 0x48);
        void *entry = *(void **)gUnitLists;
        while (entry != NULL) {
            fn_8013B064(hold, entry);
            entry = *(void **)((u8 *)entry + 0x184);
        }
    }
    {
        void *hold2 = *(void **)((u8 *)self + 0x48);
        void *entry2 = *(void **)(gUnitLists + 0x3C);
        while (entry2 != NULL) {
            fn_8013B064(hold2, entry2);
            entry2 = *(void **)((u8 *)entry2 + 0x184);
        }
    }
    Ui_AddChild(self, *(void **)((u8 *)self + 0x48));

    p = Heap_Alloc(0x50);
    if (p != NULL) {
        register s32 z = 0;
        *(void **)p = lbl_8028FDB0;
        *(s32 *)((u8 *)p + 4) = z;
        *(void **)p = lbl_80292230;
        *(s16 *)((u8 *)p + 8) = -1;
        *(s16 *)((u8 *)p + 0xA) = 0x138;
        *(s16 *)((u8 *)p + 0xC) = 0xA8;
        *(s16 *)((u8 *)p + 0xE) = 0x250;
        *(s16 *)((u8 *)p + 0x10) = 0xE8;
        *(s16 *)((u8 *)p + 0x12) = z;
        *(s16 *)((u8 *)p + 0x14) = z;
        *(s16 *)((u8 *)p + 0x16) = 0x118;
        *(s16 *)((u8 *)p + 0x18) = 0x40;
        *(s16 *)((u8 *)p + 0x1A) = z;
        *(s16 *)((u8 *)p + 0x1C) = z;
        *(u8 *)((u8 *)p + 0x1E) = 0xFF;
        *(u8 *)((u8 *)p + 0x1F) = 0xFF;
        *(u8 *)((u8 *)p + 0x20) = 0xFF;
        *(u8 *)((u8 *)p + 0x21) = 0xFF;
        *(s16 *)((u8 *)p + 0x22) = 0x1FE;
        *(s16 *)((u8 *)p + 0x24) = z;
        *(f32 *)((u8 *)p + 0x28) = lbl_8036B2D8;
        *(f32 *)((u8 *)p + 0x2C) = lbl_8036B2D8;
        *(f32 *)((u8 *)p + 0x30) = lbl_8036B2D8;
        *(s32 *)((u8 *)p + 0x34) = z;
        *(s32 *)((u8 *)p + 0x38) = z;
        *(void **)p = lbl_80292178;
        *(u8 *)((u8 *)p + 0x3C) = 0xFF;
        *(u8 *)((u8 *)p + 0x3D) = 0xFF;
        *(u8 *)((u8 *)p + 0x3E) = 0xFF;
        *(u8 *)((u8 *)p + 0x3F) = 0xFF;
        *(s32 *)((u8 *)p + 0x40) = z;
        *(s16 *)((u8 *)p + 0x44) = z;
        *(s16 *)((u8 *)p + 0x46) = z;
        ((Obj *)p)->v8();
    }
    *(void **)((u8 *)self + 0x50) = p;
    q = *(void **)((u8 *)self + 0x50);
    if (q != NULL) {
        *(s32 *)((u8 *)q + 4) = *(s32 *)((u8 *)q + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x50) + 0x24) = 8;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x50) + 8) = 0x102;
    q = *(void **)((u8 *)self + 0x50);
    *(u32 *)((u8 *)q + 0x34) |= 0x10;
    {
        u8 col[4];
        u8 *color = Ui_GetColor(2);
        u8 first = color[0];
        col[0] = first;
        col[1] = color[1];
        col[2] = color[2];
        col[3] = color[3];
        q = *(void **)((u8 *)self + 0x50);
        if ((u8 *)q + 0x3C != col) {
            *(u8 *)((u8 *)q + 0x3C) = first;
            *(u8 *)((u8 *)q + 0x3D) = col[1];
            *(u8 *)((u8 *)q + 0x3E) = col[2];
            *(u8 *)((u8 *)q + 0x3F) = col[3];
        }
    }
    *(f32 *)((u8 *)*(void **)((u8 *)self + 0x50) + 0x2C) = lbl_8036B2E0;
    *(void **)((u8 *)*(void **)((u8 *)self + 0x50) + 0x40) = gUiUnitPanelStrings + 0x1B7;
    Ui_AddChild(self, *(void **)((u8 *)self + 0x50));

    p = Heap_Alloc(0x40);
    if (p != NULL) {
        register s32 z = 0;
        *(void **)p = lbl_8028FDB0;
        *(s32 *)((u8 *)p + 4) = z;
        *(void **)p = lbl_80292230;
        *(s16 *)((u8 *)p + 8) = -1;
        *(s16 *)((u8 *)p + 0xA) = 0x148;
        *(s16 *)((u8 *)p + 0xC) = 0x11C;
        *(s16 *)((u8 *)p + 0xE) = 0x250;
        *(s16 *)((u8 *)p + 0x10) = 0x16C;
        *(s16 *)((u8 *)p + 0x12) = z;
        *(s16 *)((u8 *)p + 0x14) = z;
        *(s16 *)((u8 *)p + 0x16) = 0x108;
        *(s16 *)((u8 *)p + 0x18) = 0x50;
        *(s16 *)((u8 *)p + 0x1A) = z;
        *(s16 *)((u8 *)p + 0x1C) = z;
        *(u8 *)((u8 *)p + 0x1E) = 0xFF;
        *(u8 *)((u8 *)p + 0x1F) = 0xFF;
        *(u8 *)((u8 *)p + 0x20) = 0xFF;
        *(u8 *)((u8 *)p + 0x21) = 0xFF;
        *(s16 *)((u8 *)p + 0x22) = 0x1F4;
        *(s16 *)((u8 *)p + 0x24) = z;
        *(f32 *)((u8 *)p + 0x28) = lbl_8036B2D8;
        *(f32 *)((u8 *)p + 0x2C) = lbl_8036B2D8;
        *(f32 *)((u8 *)p + 0x30) = lbl_8036B2D8;
        *(s32 *)((u8 *)p + 0x34) = z;
        *(s32 *)((u8 *)p + 0x38) = z;
        *(void **)p = lbl_80291988;
        *(s32 *)((u8 *)p + 0x3C) = z;
    }
    *(void **)((u8 *)self + 0x64) = p;
    q = *(void **)((u8 *)self + 0x64);
    if (q != NULL) {
        *(s32 *)((u8 *)q + 4) = *(s32 *)((u8 *)q + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x64) + 8) = 0x101;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x64) + 0x24) = 8;
    q = *(void **)((u8 *)self + 0x64);
    *(u32 *)((u8 *)q + 0x34) |= 0x10;
    *(void **)((u8 *)*(void **)((u8 *)self + 0x64) + 0x3C) = Ui_ListGetSelected(*(void **)((u8 *)self + 0x48));
    Ui_AddChild(self, *(void **)((u8 *)self + 0x64));

    p = Heap_Alloc(0x64);
    if (p != NULL) {
        register s32 z = 0;
        *(void **)p = lbl_8028FDB0;
        *(s32 *)((u8 *)p + 4) = z;
        *(void **)p = lbl_80292230;
        *(s16 *)((u8 *)p + 8) = -1;
        *(s16 *)((u8 *)p + 0xA) = 0x10;
        *(s16 *)((u8 *)p + 0xC) = 0x94;
        *(s16 *)((u8 *)p + 0xE) = 0x138;
        *(s16 *)((u8 *)p + 0x10) = 0x186;
        *(s16 *)((u8 *)p + 0x12) = z;
        *(s16 *)((u8 *)p + 0x14) = z;
        *(s16 *)((u8 *)p + 0x16) = 0x128;
        *(s16 *)((u8 *)p + 0x18) = 0xF2;
        *(s16 *)((u8 *)p + 0x1A) = z;
        *(s16 *)((u8 *)p + 0x1C) = z;
        *(u8 *)((u8 *)p + 0x1E) = 0xFF;
        *(u8 *)((u8 *)p + 0x1F) = 0xFF;
        *(u8 *)((u8 *)p + 0x20) = 0xFF;
        *(u8 *)((u8 *)p + 0x21) = 0xFF;
        *(s16 *)((u8 *)p + 0x22) = 0x1F4;
        *(s16 *)((u8 *)p + 0x24) = z;
        *(f32 *)((u8 *)p + 0x28) = lbl_8036B2D8;
        *(f32 *)((u8 *)p + 0x2C) = lbl_8036B2D8;
        *(f32 *)((u8 *)p + 0x30) = lbl_8036B2D8;
        *(s32 *)((u8 *)p + 0x34) = z;
        *(s32 *)((u8 *)p + 0x38) = z;
        *(void **)p = lbl_80295404;
        *(u8 *)((u8 *)p + 0x3C) = z;
        *(s16 *)((u8 *)p + 0x3E) = z;
        *(s16 *)((u8 *)p + 0x40) = -1;
        *(s16 *)((u8 *)p + 0x42) = -1;
        *(s32 *)((u8 *)p + 0x4C) = z;
        *(f32 *)((u8 *)p + 0x50) = lbl_8036B2E0;
        *(u8 *)((u8 *)p + 0x54) = z;
        *(s32 *)((u8 *)p + 0x58) = z;
        *(s32 *)((u8 *)p + 0x5C) = z;
        *(f32 *)((u8 *)p + 0x60) = lbl_8036B2E0;
        ((Obj *)p)->v8();
    }
    *(void **)((u8 *)self + 0x60) = p;
    q = *(void **)((u8 *)self + 0x60);
    if (q != NULL) {
        *(s32 *)((u8 *)q + 4) = *(s32 *)((u8 *)q + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x60) + 8) = 0x106;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x60) + 0x24) = 8;
    q = *(void **)((u8 *)self + 0x60);
    *(u32 *)((u8 *)q + 0x34) |= 0x10;
    {
        s32 ac = (s32)Ui_ListGetSelected(*(void **)((u8 *)self + 0x48));
        void *obj60 = *(void **)((u8 *)self + 0x60);
        *(s32 *)((u8 *)obj60 + 0x4C) = ac;
        fn_8017BB94(obj60);
        *(f32 *)((u8 *)obj60 + 0x50) = (f32)Unit_GetSkillCapacityUsed(ac);
    }
    Ui_AddChild(self, *(void **)((u8 *)self + 0x60));
}

#pragma cplusplus on
extern "C" void fn_801BBDA0(void *arg0) {
#pragma opt_common_subs off
    void *Heap_Alloc(s32);
    void *Ui_ListGetSelected(void *);
    void fn_8013AD70(void *, s32);
    void fn_8013B064(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_RemoveChild(void *, void *);
    void Ui_AddChild(void *, void *);
    void *fn_80179F8C(void *, s16, s16, s16, s16, s32);
    u8 *Ui_GetColor(s32);
    void Ui_SetPortraitUnit(void *, void *);
    void fn_80137EA0(void *, void *);
    void fn_801BC71C(void);
    void Ui_SetWidgetText(void *, void *);
    void *fn_801BEDC4(void *, s32, s32, s32);
    extern u8 gUiUnitPanelStrings[];
    extern u8 lbl_8028FDB0[];
    extern u8 lbl_802919B0[];
    extern u8 lbl_80291A0C[];
    extern u8 lbl_80291A3C[];
    extern u8 lbl_80292178[];
    extern u8 lbl_80292230[];
    extern u8 lbl_80293C00[];
    extern u8 lbl_80293C2C[];
    extern u8 lbl_80293C84[];
    extern u8 gUnitLists[];
    extern u8 gUiContext[];
    extern f32 lbl_8036B2D8;
    extern f32 lbl_8036B2DC;
    extern f32 lbl_8036B2E0;
    extern f32 lbl_8036B2E4;

    struct Obj {
        virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0;
        virtual void v3() = 0; virtual void v4() = 0; virtual void v5() = 0;
        virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0;
        virtual void v9() = 0; virtual void v10() = 0; virtual void v11(void *) = 0;
        virtual void v12(s32) = 0;
    };

    void *self;
    void *entry;
    void *p;
    void *hold;
    void *q;
    void *tmp;
    s32 saved;
    f32 zero;
    s16 t;
    s16 n;

    self = arg0;
    saved = *(s32 *)gUiContext;
    tmp = Ui_FindChild(self, -0x1000, 0);
    if (tmp != NULL) {
        Ui_RemoveChild(self, tmp);
    }

    p = Heap_Alloc(0xD8);
    if (p != NULL) {
        p = fn_80179F8C(p, 0x38, -0x90, 0x1F0, 0x90, 0x226);
    }
    *(void **)((u8 *)self + 0x48) = p;
    q = *(void **)((u8 *)self + 0x48);
    if (q != NULL) {
        *(s32 *)((u8 *)q + 4) = *(s32 *)((u8 *)q + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 0x24) = 8;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 0x64) = 8;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 8) = 0x100;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 0x5A) = 0x1C;
    ((Obj *)*(void **)((u8 *)self + 0x48))->v12(4);
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 0x58) = 3;

    hold = *(void **)((u8 *)self + 0x48);
    entry = *(void **)gUnitLists;
    while (entry != NULL) {
        fn_8013B064(hold, entry);
        entry = *(void **)((u8 *)entry + 0x184);
    }
    hold = *(void **)((u8 *)self + 0x48);
    entry = *(void **)(gUnitLists + 0x3C);
    while (entry != NULL) {
        fn_8013B064(hold, entry);
        entry = *(void **)((u8 *)entry + 0x184);
    }
    fn_8013AD70(*(void **)((u8 *)self + 0x48), saved);
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 0x56) = gUiContext[0x15];
    q = *(void **)((u8 *)self + 0x48);
    *(void **)((u8 *)q + 0x7C) = (void *)fn_801BC71C;
    *(s32 *)((u8 *)q + 0x80) = 0;
    *(f32 *)((u8 *)q + 0x30) = lbl_8036B2E4;

    p = Heap_Alloc(0x50);
    if (p != NULL) {
        *(void **)p = lbl_8028FDB0;
        *(s32 *)((u8 *)p + 4) = 0;
        *(void **)p = lbl_80292230;
        *(s16 *)((u8 *)p + 8) = -1;
        *(s16 *)((u8 *)p + 0xA) = 0x130;
        *(s16 *)((u8 *)p + 0xC) = 0xA8;
        *(s16 *)((u8 *)p + 0xE) = 0x248;
        *(s16 *)((u8 *)p + 0x10) = 0xE8;
        *(s16 *)((u8 *)p + 0x12) = 0;
        *(s16 *)((u8 *)p + 0x14) = 0;
        *(s16 *)((u8 *)p + 0x16) = 0x118;
        *(s16 *)((u8 *)p + 0x18) = 0x40;
        *(s16 *)((u8 *)p + 0x1A) = 0;
        *(s16 *)((u8 *)p + 0x1C) = 0;
        *(u8 *)((u8 *)p + 0x1E) = 0xFF;
        *(u8 *)((u8 *)p + 0x1F) = 0xFF;
        *(u8 *)((u8 *)p + 0x20) = 0xFF;
        *(u8 *)((u8 *)p + 0x21) = 0xFF;
        *(s16 *)((u8 *)p + 0x22) = 0x1FE;
        *(s16 *)((u8 *)p + 0x24) = 0;
        zero = lbl_8036B2D8;
        *(f32 *)((u8 *)p + 0x28) = zero;
        *(f32 *)((u8 *)p + 0x2C) = zero;
        *(f32 *)((u8 *)p + 0x30) = zero;
        *(s32 *)((u8 *)p + 0x34) = 0;
        *(s32 *)((u8 *)p + 0x38) = 0;
        *(void **)p = lbl_80292178;
        *(u8 *)((u8 *)p + 0x3C) = 0xFF;
        *(u8 *)((u8 *)p + 0x3D) = 0xFF;
        *(u8 *)((u8 *)p + 0x3E) = 0xFF;
        *(u8 *)((u8 *)p + 0x3F) = 0xFF;
        *(s32 *)((u8 *)p + 0x40) = 0;
        *(s16 *)((u8 *)p + 0x44) = 0;
        *(s16 *)((u8 *)p + 0x46) = 0;
        ((Obj *)p)->v8();
    }
    *(void **)((u8 *)self + 0x50) = p;
    q = *(void **)((u8 *)self + 0x50);
    if (q != NULL) {
        *(s32 *)((u8 *)q + 4) = *(s32 *)((u8 *)q + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x50) + 0x24) = 8;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x50) + 8) = 0x102;
    q = *(void **)((u8 *)self + 0x50);
    *(u32 *)((u8 *)q + 0x34) |= 0x10;
    {
        u8 col[4];
        u8 *color = Ui_GetColor(2);
        u8 first = color[0];
        col[0] = first;
        col[1] = color[1];
        col[2] = color[2];
        col[3] = color[3];
        q = *(void **)((u8 *)self + 0x50);
        if ((u8 *)q + 0x3C != col) {
            *(u8 *)((u8 *)q + 0x3C) = first;
            *(u8 *)((u8 *)q + 0x3D) = col[1];
            *(u8 *)((u8 *)q + 0x3E) = col[2];
            *(u8 *)((u8 *)q + 0x3F) = col[3];
        }
    }
    *(f32 *)((u8 *)*(void **)((u8 *)self + 0x50) + 0x2C) = lbl_8036B2E0;
    *(void **)((u8 *)*(void **)((u8 *)self + 0x50) + 0x40) = gUiUnitPanelStrings + 0x1B7;

    p = Heap_Alloc(0x54);
    if (p != NULL) {
        register s32 z = 0;
        *(void **)p = lbl_8028FDB0;
        *(s32 *)((u8 *)p + 4) = z;
        *(void **)p = lbl_80292230;
        *(s16 *)((u8 *)p + 8) = -1;
        *(s16 *)((u8 *)p + 0xA) = 0x20;
        *(s16 *)((u8 *)p + 0xC) = 0x98;
        *(s16 *)((u8 *)p + 0xE) = 0x128;
        *(s16 *)((u8 *)p + 0x10) = 0xED;
        *(s16 *)((u8 *)p + 0x12) = z;
        *(s16 *)((u8 *)p + 0x14) = z;
        *(s16 *)((u8 *)p + 0x16) = 0x108;
        *(s16 *)((u8 *)p + 0x18) = 0x55;
        *(s16 *)((u8 *)p + 0x1A) = z;
        *(s16 *)((u8 *)p + 0x1C) = z;
        *(u8 *)((u8 *)p + 0x1E) = 0xFF;
        *(u8 *)((u8 *)p + 0x1F) = 0xFF;
        *(u8 *)((u8 *)p + 0x20) = 0xFF;
        *(u8 *)((u8 *)p + 0x21) = 0xFF;
        *(s16 *)((u8 *)p + 0x22) = 0x1F4;
        *(s16 *)((u8 *)p + 0x24) = z;
        zero = lbl_8036B2D8;
        *(f32 *)((u8 *)p + 0x28) = zero;
        *(f32 *)((u8 *)p + 0x2C) = zero;
        *(f32 *)((u8 *)p + 0x30) = zero;
        *(s32 *)((u8 *)p + 0x34) = z;
        *(s32 *)((u8 *)p + 0x38) = z;
        *(void **)p = lbl_80291A3C;
        *(s32 *)((u8 *)p + 0x3C) = z;
        *(s32 *)((u8 *)p + 0x40) = 0x1003C;
        *(s32 *)((u8 *)p + 0x4C) = z;
        *(s32 *)((u8 *)p + 0x50) = z;
        ((Obj *)p)->v8();
    }
    *(void **)((u8 *)self + 0x4C) = p;
    q = *(void **)((u8 *)self + 0x4C);
    t = *(s16 *)((u8 *)q + 0xE) - *(s16 *)((u8 *)q + 0xA);
    n = -t;
    *(s16 *)((u8 *)q + 0xE) = n + t;
    *(s16 *)((u8 *)q + 0xA) = n;
    *(s16 *)((u8 *)q + 0x10) = *(s16 *)((u8 *)q + 0xC) + (*(s16 *)((u8 *)q + 0x10) - *(s16 *)((u8 *)q + 0xC));
    if (q != NULL) {
        *(s32 *)((u8 *)q + 4) = *(s32 *)((u8 *)q + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x4C) + 8) = 0x101;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x4C) + 0x24) = 8;
    *(s32 *)((u8 *)*(void **)((u8 *)self + 0x4C) + 0x4C) = 1;
    q = *(void **)((u8 *)self + 0x4C);
    *(u32 *)((u8 *)q + 0x34) |= 0x10;
    Ui_SetPortraitUnit(*(void **)((u8 *)self + 0x4C), Ui_ListGetSelected(*(void **)((u8 *)self + 0x48)));
    *(f32 *)((u8 *)*(void **)((u8 *)self + 0x48) + 0x30) = lbl_8036B2DC;

    p = Heap_Alloc(0x4C);
    if (p != NULL) {
        *(void **)p = lbl_8028FDB0;
        *(s32 *)((u8 *)p + 4) = 0;
        *(void **)p = lbl_80292230;
        *(s16 *)((u8 *)p + 8) = -1;
        *(s16 *)((u8 *)p + 0xA) = 0x20;
        *(s16 *)((u8 *)p + 0xC) = 0xF8;
        *(s16 *)((u8 *)p + 0xE) = 0x128;
        *(s16 *)((u8 *)p + 0x10) = 0x18D;
        *(s16 *)((u8 *)p + 0x12) = 0;
        *(s16 *)((u8 *)p + 0x14) = 0;
        *(s16 *)((u8 *)p + 0x16) = 0x108;
        *(s16 *)((u8 *)p + 0x18) = 0x95;
        *(s16 *)((u8 *)p + 0x1A) = 0;
        *(s16 *)((u8 *)p + 0x1C) = 0;
        *(u8 *)((u8 *)p + 0x1E) = 0xFF;
        *(u8 *)((u8 *)p + 0x1F) = 0xFF;
        *(u8 *)((u8 *)p + 0x20) = 0xFF;
        *(u8 *)((u8 *)p + 0x21) = 0xFF;
        *(s16 *)((u8 *)p + 0x22) = 0x1F4;
        *(s16 *)((u8 *)p + 0x24) = 0;
        zero = lbl_8036B2D8;
        *(f32 *)((u8 *)p + 0x28) = zero;
        *(f32 *)((u8 *)p + 0x2C) = zero;
        *(f32 *)((u8 *)p + 0x30) = zero;
        *(s32 *)((u8 *)p + 0x34) = 0;
        *(s32 *)((u8 *)p + 0x38) = 0;
        *(void **)p = lbl_80291A0C;
        *(s32 *)((u8 *)p + 0x44) = 0;
        *(u8 *)((u8 *)p + 0x48) = 1;
        ((Obj *)p)->v8();
    }
    *(void **)((u8 *)self + 0x54) = p;
    q = *(void **)((u8 *)self + 0x54);
    t = *(s16 *)((u8 *)q + 0xE) - *(s16 *)((u8 *)q + 0xA);
    n = -t;
    *(s16 *)((u8 *)q + 0xE) = n + t;
    *(s16 *)((u8 *)q + 0xA) = n;
    *(s16 *)((u8 *)q + 0x10) = *(s16 *)((u8 *)q + 0xC) + (*(s16 *)((u8 *)q + 0x10) - *(s16 *)((u8 *)q + 0xC));
    if (q != NULL) {
        *(s32 *)((u8 *)q + 4) = *(s32 *)((u8 *)q + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x54) + 8) = 0x103;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x54) + 0x24) = 8;
    q = *(void **)((u8 *)self + 0x54);
    *(u32 *)((u8 *)q + 0x34) |= 0x10;
    fn_80137EA0(*(void **)((u8 *)self + 0x54), Ui_ListGetSelected(*(void **)((u8 *)self + 0x48)));
    *(f32 *)((u8 *)*(void **)((u8 *)self + 0x54) + 0x30) = lbl_8036B2DC;

    p = Heap_Alloc(0x40);
    if (p != NULL) {
        *(void **)p = lbl_8028FDB0;
        *(s32 *)((u8 *)p + 4) = 0;
        *(void **)p = lbl_80292230;
        *(s16 *)((u8 *)p + 8) = -1;
        *(s16 *)((u8 *)p + 0xA) = 0x260;
        *(s16 *)((u8 *)p + 0xC) = 0x110;
        *(s16 *)((u8 *)p + 0xE) = 0x370;
        *(s16 *)((u8 *)p + 0x10) = 0x18D;
        *(s16 *)((u8 *)p + 0x12) = 0;
        *(s16 *)((u8 *)p + 0x14) = 0;
        *(s16 *)((u8 *)p + 0x16) = 0x110;
        *(s16 *)((u8 *)p + 0x18) = 0x7D;
        *(s16 *)((u8 *)p + 0x1A) = 0;
        *(s16 *)((u8 *)p + 0x1C) = 0;
        *(u8 *)((u8 *)p + 0x1E) = 0xFF;
        *(u8 *)((u8 *)p + 0x1F) = 0xFF;
        *(u8 *)((u8 *)p + 0x20) = 0xFF;
        *(u8 *)((u8 *)p + 0x21) = 0xFF;
        *(s16 *)((u8 *)p + 0x22) = 0x1F4;
        *(s16 *)((u8 *)p + 0x24) = 0;
        zero = lbl_8036B2D8;
        *(f32 *)((u8 *)p + 0x28) = zero;
        *(f32 *)((u8 *)p + 0x2C) = zero;
        *(f32 *)((u8 *)p + 0x30) = zero;
        *(s32 *)((u8 *)p + 0x34) = 0;
        *(s32 *)((u8 *)p + 0x38) = 0;
        *(void **)p = lbl_802919B0;
        *(s32 *)((u8 *)p + 0x3C) = 0;
        ((Obj *)p)->v8();
    }
    *(void **)((u8 *)self + 0x58) = p;
    q = *(void **)((u8 *)self + 0x58);
    if (q != NULL) {
        *(s32 *)((u8 *)q + 4) = *(s32 *)((u8 *)q + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x58) + 8) = 0x104;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x58) + 0x24) = 8;
    q = *(void **)((u8 *)self + 0x58);
    *(u32 *)((u8 *)q + 0x34) |= 0x10;
    *(void **)((u8 *)*(void **)((u8 *)self + 0x58) + 0x3C) = Ui_ListGetSelected(*(void **)((u8 *)self + 0x48));
    *(f32 *)((u8 *)*(void **)((u8 *)self + 0x58) + 0x30) = lbl_8036B2DC;

    p = Heap_Alloc(0x60);
    if (p != NULL) {
        register s32 z = 0;
        *(void **)p = lbl_8028FDB0;
        *(s32 *)((u8 *)p + 4) = z;
        *(void **)p = lbl_80292230;
        *(s16 *)((u8 *)p + 8) = -1;
        *(s16 *)((u8 *)p + 0xA) = z;
        *(s16 *)((u8 *)p + 0xC) = 0x28;
        *(s16 *)((u8 *)p + 0xE) = 0x260;
        *(s16 *)((u8 *)p + 0x10) = 0x62;
        *(s16 *)((u8 *)p + 0x12) = z;
        *(s16 *)((u8 *)p + 0x14) = z;
        *(s16 *)((u8 *)p + 0x16) = 0x260;
        *(s16 *)((u8 *)p + 0x18) = 0x3A;
        *(s16 *)((u8 *)p + 0x1A) = z;
        *(s16 *)((u8 *)p + 0x1C) = z;
        *(u8 *)((u8 *)p + 0x1E) = 0xFF;
        *(u8 *)((u8 *)p + 0x1F) = 0xFF;
        *(u8 *)((u8 *)p + 0x20) = 0xFF;
        *(u8 *)((u8 *)p + 0x21) = 0xFF;
        *(s16 *)((u8 *)p + 0x22) = 0x1F4;
        *(s16 *)((u8 *)p + 0x24) = z;
        zero = lbl_8036B2D8;
        *(f32 *)((u8 *)p + 0x28) = zero;
        *(f32 *)((u8 *)p + 0x2C) = zero;
        *(f32 *)((u8 *)p + 0x30) = zero;
        *(s32 *)((u8 *)p + 0x34) = z;
        *(s32 *)((u8 *)p + 0x38) = z;
        *(void **)p = lbl_80293C84;
        *(s32 *)((u8 *)p + 0x3C) = z;
        *(s32 *)((u8 *)p + 0x40) = z;
        *(s32 *)((u8 *)p + 0x44) = z;
        *(s32 *)((u8 *)p + 0x40) = z;
        *(s32 *)((u8 *)p + 0x48) = z;
        *(u8 *)((u8 *)p + 0x4C) = 1;
        *(s16 *)((u8 *)p + 0x4E) = z;
        *(s16 *)((u8 *)p + 0x50) = z;
        *(s16 *)((u8 *)p + 0x52) = z;
        *(s16 *)((u8 *)p + 0x54) = z;
        *(void **)p = lbl_80293C2C;
        *(void **)p = lbl_80293C00;
        *(s32 *)((u8 *)p + 0x58) = z;
        *(s16 *)((u8 *)p + 0x5C) = 0xB;
        *(s16 *)((u8 *)p + 0x5E) = 0x10;
    }
    *(s16 *)((u8 *)p + 8) = 0x80;
    *(s16 *)((u8 *)p + 0x24) = 8;
    *(s16 *)((u8 *)p + 0x4E) = 0x10;
    *(s32 *)((u8 *)p + 0x58) = 1;
    *(u32 *)((u8 *)p + 0x34) |= 0x10;
    *(u8 *)((u8 *)p + 0x4C) = 2;
    *(s32 *)((u8 *)p + 0x48) = 1;
    Ui_SetWidgetText(p, gUiUnitPanelStrings + 0x1CE);
    Ui_AddChild(self, p);

    q = Heap_Alloc(0x94);
    if (q != NULL) {
        q = fn_801BEDC4(q, 0x260, 0x78, 0x1C2);
    }
    *(void **)((u8 *)self + 0x5C) = q;
    tmp = *(void **)((u8 *)self + 0x5C);
    if (tmp != NULL) {
        *(s32 *)((u8 *)tmp + 4) = *(s32 *)((u8 *)tmp + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x5C) + 8) = 0x105;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x5C) + 0x24) = 8;
    tmp = *(void **)((u8 *)self + 0x5C);
    *(u32 *)((u8 *)tmp + 0x34) |= 0x10;
    *(s32 *)((u8 *)*(void **)((u8 *)self + 0x5C) + 0x40) = saved;
    tmp = Ui_FindChild(self, -0x1000, 0);
    if (tmp != NULL) {
        Ui_SetWidgetText(gUiUnitPanelStrings + 0x1E6, tmp);
    }
}

#pragma global_optimizer off
extern "C" s32 fn_801BC71C(s32 arg0) {
    u8 fn_8003D13C(void);
    s16 Unit_GetGoldCost(s32, s32, u8 *);
    extern u8 gBattleState[];
    s32 t;
    u8 *p;

    if (fn_8003D13C() == 0) {
        return 0;
    }
    p = gBattleState;
    t = *(s32 *)(p + 0x1C);
    return (Unit_GetGoldCost(arg0, 1, p) <= t) ? 1 : 0;
}
#pragma global_optimizer reset

#pragma cplusplus reset

#pragma cplusplus on
extern "C" void Ui_DetachChildSlots(void *panel) {
    void Ui_RemoveChild(void *, void *);
    struct Obj {
        virtual void destroy(s32) = 0;
        s32 refcount;
    };
    // Detach and release the five child widgets at +0x48..+0x58.
    Obj *child;
    s32 refs;

    Ui_RemoveChild(panel, M2C_FIELD(panel, void **, 0x48));
    Ui_RemoveChild(panel, M2C_FIELD(panel, void **, 0x4C));
    Ui_RemoveChild(panel, M2C_FIELD(panel, void **, 0x50));
    Ui_RemoveChild(panel, M2C_FIELD(panel, void **, 0x54));
    Ui_RemoveChild(panel, M2C_FIELD(panel, void **, 0x58));

    child = M2C_FIELD(panel, Obj **, 0x48);
    if (child != NULL) {
        refs = child->refcount - 1;
        child->refcount = refs;
        if (refs == 0 && child != NULL) {
            child->destroy(1);
        }
        M2C_FIELD(panel, void **, 0x48) = NULL;
    }

    child = M2C_FIELD(panel, Obj **, 0x4C);
    if (child != NULL) {
        refs = child->refcount - 1;
        child->refcount = refs;
        if (refs == 0 && child != NULL) {
            child->destroy(1);
        }
        M2C_FIELD(panel, void **, 0x4C) = NULL;
    }

    child = M2C_FIELD(panel, Obj **, 0x50);
    if (child != NULL) {
        refs = child->refcount - 1;
        child->refcount = refs;
        if (refs == 0 && child != NULL) {
            child->destroy(1);
        }
        M2C_FIELD(panel, void **, 0x50) = NULL;
    }

    child = M2C_FIELD(panel, Obj **, 0x54);
    if (child != NULL) {
        refs = child->refcount - 1;
        child->refcount = refs;
        if (refs == 0 && child != NULL) {
            child->destroy(1);
        }
        M2C_FIELD(panel, void **, 0x54) = NULL;
    }

    child = M2C_FIELD(panel, Obj **, 0x58);
    if (child != NULL) {
        refs = child->refcount - 1;
        child->refcount = refs;
        if (refs == 0 && child != NULL) {
            child->destroy(1);
        }
        M2C_FIELD(panel, void **, 0x58) = NULL;
    }
}

#pragma cplusplus on
#pragma use_lmw_stmw on
/* Allocate the unit-panel caption and position child widgets, or exit if the panel is not ready. */
extern "C" void Ui_InitUnitPanel(void *arg0) {
void *Heap_Alloc(u32); void Ui_AddChild(void *,void *);
s32 strlen(const char *); void String_AssignCStr(void *,const void *,s32);
void Unit_SetHp(void *,s8); s32 Unit_GetMaxHp(void *);
void *Ui_FindChild(void *,s32,s32); u8 Ui_CanAffordNextGoldCost(void *);
void Ui_PlaySeCue(void *,s32); void Process_Goto(void *,s32); void Ui_BringChildToFront(void *,void *);
extern u8 lbl_8028FDB0[],lbl_80292230[],lbl_80293C84[],lbl_80293C58[],gUiUnitPanelStrings[],gUiContext[];
class Pair { public: s16 x,y; Pair(s16 a,s16 b):x(a),y(b) {} };
void Ui_SlideWidgetChild(void *,void *,const Pair &,s32);
void Ui_SlideWidgetChildMode1(void *,void *,const Pair &,s32);
struct Obj { virtual void destroy(s32); s32 refs; };
void *p,*unit,*a,*b,*c,*self,*temp;
Obj *ref;
s32 refs;
self=arg0;
a=M2C_FIELD(self,void **,0x4C); b=M2C_FIELD(self,void **,0x54); c=M2C_FIELD(self,void **,0x58);
M2C_FIELD(a,f32 *,0x30)=1.0f; M2C_FIELD(b,f32 *,0x30)=1.0f; M2C_FIELD(c,f32 *,0x30)=1.0f;
M2C_FIELD(M2C_FIELD(self,void **,0x5C),f32 *,0x30)=1.0f;
unit=*(void **)gUiContext;
p=Heap_Alloc(0x5C);
if(p) {M2C_FIELD(p,void **,0)=lbl_8028FDB0;
M2C_FIELD(p,u32 *,4)=0;
M2C_FIELD(p,void **,0)=lbl_80292230;
M2C_FIELD(p,s16 *,8)=-1;
M2C_FIELD(p,s16 *,10)=0;
M2C_FIELD(p,s16 *,12)=400;
M2C_FIELD(p,s16 *,14)=608;
M2C_FIELD(p,s16 *,16)=448;
M2C_FIELD(p,s16 *,18)=0;
M2C_FIELD(p,s16 *,20)=0;
M2C_FIELD(p,s16 *,22)=608;
M2C_FIELD(p,s16 *,24)=48;
M2C_FIELD(p,s16 *,26)=0;
M2C_FIELD(p,s16 *,28)=0;
M2C_FIELD(p,u8 *,30)=255;
M2C_FIELD(p,u8 *,31)=255;
M2C_FIELD(p,u8 *,32)=255;
M2C_FIELD(p,u8 *,33)=255;
M2C_FIELD(p,s16 *,34)=90;
M2C_FIELD(p,s16 *,36)=0;
M2C_FIELD(p,f32 *,40)=1.0f;
M2C_FIELD(p,f32 *,44)=1.0f;
M2C_FIELD(p,f32 *,48)=1.0f;
M2C_FIELD(p,u32 *,52)=0;
M2C_FIELD(p,u32 *,56)=0;
M2C_FIELD(p,void **,0)=lbl_80293C84;
M2C_FIELD(p,u32 *,60)=0;
M2C_FIELD(p,u32 *,64)=0;
M2C_FIELD(p,u32 *,68)=0;
M2C_FIELD(p,u32 *,64)=0;
M2C_FIELD(p,u32 *,72)=0;
M2C_FIELD(p,u8 *,76)=1;
M2C_FIELD(p,s16 *,78)=0;
M2C_FIELD(p,s16 *,80)=0;
M2C_FIELD(p,s16 *,82)=0;
M2C_FIELD(p,s16 *,84)=0;
M2C_FIELD(p,void **,0)=lbl_80293C58;
M2C_FIELD(p,u32 *,88)=1;
M2C_FIELD(p,s16 *,78)=48;
M2C_FIELD(p,s16 *,82)=48;
}
M2C_FIELD(p,s16 *,8)=-0x1000;
M2C_FIELD(p,u32 *,0x48)=1;
String_AssignCStr((u8 *)p+0x3C,gUiUnitPanelStrings+0xF7,strlen((char *)gUiUnitPanelStrings+0xF7));
M2C_FIELD(p,u32 *,0x34)|=0x10;
M2C_FIELD(p,u32 *,0x58)=1;
Ui_AddChild(self,p);
Unit_SetHp(unit,(s8)Unit_GetMaxHp(unit));
M2C_FIELD(M2C_FIELD(self,void **,0x5C),s16 *,0x3E)=0;
if(!Ui_CanAffordNextGoldCost(M2C_FIELD(self,void **,0x5C))) {
temp=Ui_FindChild(self,0x80,0);
Ui_SlideWidgetChild(self,temp,Pair(M2C_FIELD(temp,s16 *,0xA),-0x3A),0);
ref=M2C_FIELD(self,Obj **,0x5C);
if(ref) {
refs=ref->refs-1; ref->refs=refs;
if(refs==0 && ref) ref->destroy(1);
M2C_FIELD(self,void **,0x5C)=0;
}
Ui_PlaySeCue(gUiUnitPanelStrings+0x11C,100); Process_Goto(self,3); return;
}
Ui_AddChild(self,a); Ui_SlideWidgetChildMode1(self,a,Pair(0x20,M2C_FIELD(a,s16 *,0xC)),0);
Ui_AddChild(self,b); Ui_SlideWidgetChildMode1(self,b,Pair(0x20,M2C_FIELD(b,s16 *,0xC)),0);
Ui_AddChild(self,c); Ui_SlideWidgetChildMode1(self,c,Pair(0x134,M2C_FIELD(c,s16 *,0xC)),0);
Ui_AddChild(self,M2C_FIELD(self,void **,0x5C));
temp=M2C_FIELD(self,void **,0x5C);
Ui_SlideWidgetChildMode1(self,temp,Pair(0x118,M2C_FIELD(temp,s16 *,0xC)),1);
Ui_BringChildToFront(self,M2C_FIELD(self,void **,0x5C));
#pragma cplusplus off
}
#pragma cplusplus off
#pragma use_lmw_stmw reset

#pragma cplusplus reset
void fn_801BCC60(s32 arg0) {
    void Battle_Apply(void *);
    void fn_801ED970(s32, s32);
    extern u8 gUiContext[];
    extern u8 gBattle[];
    s32 saved;

    saved = *(s32 *)gUiContext;
    Battle_Apply(gBattle);
    if (*(u32 *)(gBattle + 0xCAC) & 0x10) {
        fn_801ED970(saved, arg0);
    }
}

#pragma optimization_level 3
void fn_801BCCC4(void *arg0) {
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *, void *);
    s32 fn_8017D52C(void *, s16);
    void fn_80034A8C(void *, s32, u8, void *, s32);
    void Ui_RemoveChild(void *, void *);
    extern u8 gUiUnitPanelStrings[];
    extern u8 gUiContext[];
    extern u8 gBattleState[];
    extern u8 gBattle[];
    s32 v;
    s32 saved;
    void *obj;
    void *base;
    void *self;
    void *p;

    self = arg0;
    p = Ui_FindChild(self, 0x80, 0);
    Ui_SetWidgetText(p, gUiUnitPanelStrings + 0x1CE);
    obj = *(void **)((u8 *)self + 0x5C);
    base = gBattleState;
    v = *(s32 *)gUiContext;
    saved = *(s32 *)((u8 *)base + 0x1C);
    *(s32 *)((u8 *)base + 0x1C) = saved - (s16)fn_8017D52C(obj, *(s16 *)((u8 *)obj + 0x3E));
    fn_80034A8C(gBattle, v, (u8)*(s16 *)((u8 *)obj + 0x3E), self, 0);
    *(s16 *)(gBattleState + 0x70) = 0;
    p = Ui_FindChild(self, -0x1000, 0);
    if (p != NULL) {
        Ui_RemoveChild(self, p);
    }
}
#pragma optimization_level reset
void fn_801BCD8C(void *arg0) {
    extern u8 gUiContext[];
    extern f32 lbl_8036B2D8;
    void Ui_SlideWidgetChild(void *, void *, void *, s32);
    void Process_ClearFunc(void *);
    void Process_Goto(void *, s32);
    typedef struct {
        s16 x;
        s16 y;
    } Pair;
    Pair p1;
    Pair p2;
    Pair p3;
    Pair p4;
    Pair *pp;
    void *obj1;
    void *obj4;
    s32 t;
    s32 flag;
    f32 f;
    void *obj3;
    void *self;
    void *obj2;

    flag = gUiContext[8];
    obj1 = *(void **)((u8 *)arg0 + 0x4C);
    obj2 = *(void **)((u8 *)arg0 + 0x54);
    obj3 = *(void **)((u8 *)arg0 + 0x58);
    self = arg0;

    switch (flag) {
    case 0x81:
        pp = &p1;
        t = *(s16 *)((u8 *)obj1 + 0xA);
        t = *(s16 *)((u8 *)obj1 + 0xE) - t;
        pp->y = *(s16 *)((u8 *)obj1 + 0xC);
        pp->x = -(s16)t;
        Ui_SlideWidgetChild(arg0, obj1, pp, 1);

        t = *(s16 *)((u8 *)obj2 + 0xA);
        t = *(s16 *)((u8 *)obj2 + 0xE) - t;
        p2.y = *(s16 *)((u8 *)obj2 + 0xC);
        p2.x = -(s16)t;
        Ui_SlideWidgetChild(self, obj2, &p2, 0);

        t = *(s16 *)((u8 *)obj3 + 0xC);
        p3.x = 0x260;
        p3.y = t;
        Ui_SlideWidgetChild(self, obj3, &p3, 0);

        obj4 = *(void **)((u8 *)self + 0x5C);
        t = *(s16 *)((u8 *)obj4 + 0xC);
        p4.x = 0x260;
        p4.y = t;
        Ui_SlideWidgetChild(self, obj4, &p4, 0);

        Process_ClearFunc(self);
        break;
    case 0x80:
        f = lbl_8036B2D8;
        *(f32 *)((u8 *)obj1 + 0x30) = f;
        *(f32 *)((u8 *)obj2 + 0x30) = f;
        *(f32 *)((u8 *)obj3 + 0x30) = f;
        Process_Goto(arg0, 6);
        break;
    }
}

void fn_801BCEC4(void *arg0) {
extern u8 gUiUnitPanelStrings[];
void *Ui_FindChild(void *,s32,s32);
void Ui_SetWidgetText(void *,void *);
void *fn_8013BC10(s32,s32);
void Ui_CreateMenu(void *,void *,s32);
#pragma cplusplus on
struct Item { virtual void v0()=0;
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
virtual void set2(s32)=0;
virtual void v19()=0;
virtual void set3(s32)=0; };
struct Base { u32 unknown; };
struct Menu: Base { virtual void v0()=0;
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
virtual Item *get(s32)=0; };
Menu *menu;
s32 i;
Item *item;
void *child;
void *a, *b, *c;
b=M2C_FIELD(arg0,void **,0x54);
c=M2C_FIELD(arg0,void **,0x58);
a=M2C_FIELD(arg0,void **,0x4C);
M2C_FIELD(a,f32 *,0x30)=0.3f;
M2C_FIELD(b,f32 *,0x30)=0.3f;
M2C_FIELD(c,f32 *,0x30)=0.3f;
menu=(Menu *)fn_8013BC10(0,0);
M2C_FIELD(menu,s16 *,8)=0x198;
M2C_FIELD(menu,s16 *,0xA)=0x38;
M2C_FIELD(menu,u8 *,0x24)=1;
for(i=0;menu->get(i)!=0;i++) {
item=menu->get(i);
item->set2(2);
item->set3(3);
}
Ui_CreateMenu(menu,arg0,0);
child=Ui_FindChild(arg0,-0x1000,0);
if(child) Ui_SetWidgetText(child,(u8 *)gUiUnitPanelStrings+0x1E6);
#pragma cplusplus reset
}

#pragma cplusplus on
extern "C" void fn_801BCFF4(void *arg0) {
    void Process_Goto(void *, s32);
    void Process_ClearFunc(void *);
    void fn_8000D8BC(s32, s32);
    void Ui_UpdatePanelWidgets(void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SlideWidgetChild(void *, void *, s16 *, s32);
    void Ui_PlaySeCue(void *, s32);
    void Ui_SetWidgetText(void *, void *);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_HideUnitInfoPopup(void *);
    void Ui_OpenUnitInfoText(void *, void *, s32, f32, f32);
    extern u8 gUiUnitPanelStrings[];
    extern u8 gUnitInfoPopup[];
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern s32 gUnitInfoPopupFlag;

    class Vec2s {
    public:
        s16 x;
        s16 y;
        Vec2s() {}
        Vec2s(const Vec2s &o) { *(u32 *)this = *(u32 *)&o; }
        Vec2s &operator=(const Vec2s &o) { *(u32 *)this = *(u32 *)&o; return *this; }
    };
    struct Obj {
        virtual void destroy(s32) = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual Vec2s v9() = 0;
        s32 refcount;
    };

    void *obj;
    register int btn;
    register u8 gate;
    register int flags;
    u32 sp14;
    s16 sp8[2];
    s16 spC[2];
    u8 pad[8];
    Obj *temp;
    s32 refs;
    s16 tmp;

    obj = Ui_FindChild(arg0, 0x80, 0);
    Ui_UpdatePanelWidgets(arg0);

    flags = gUiInputFlags;
    gate = 0;
    if ((flags & 0x10) && !(flags & 0x20)) {
        gate = 1;
    }
    if (!gate) {
        btn = *(s32 *)((u8 *)gPadInput + 4);
        btn = btn & (*(s32 *)((u8 *)gPadInput + 8) ^ btn);
        if ((btn & 0x100) && (s16)*(s16 *)((u8 *)*(void **)((u8 *)arg0 + 0x5C) + 0x3E) != 0 && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            fn_8000D8BC(0, *(s16 *)((u8 *)*(void **)((u8 *)arg0 + 0x5C) + 0x3E));
            Ui_SetWidgetText(obj, gUiUnitPanelStrings + 0x1FA);
            Ui_PlaySeCue(gUiUnitPanelStrings + 0x10C, 0x64);
            Process_ClearFunc(arg0);
        } else if ((btn & 0x800) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            *(Vec2s *)&sp14 = ((Obj *)*(void **)((u8 *)arg0 + 0x5C))->v9();
            s32 text = (s32)(gUiUnitPanelStrings + 0x215);
            Ui_OpenUnitInfoText(gUnitInfoPopup, arg0, text, (f32)*(s16 *)&sp14, (f32)*((s16 *)&sp14 + 1));
            *(s32 *)gUnitInfoPopup = *(s32 *)gUnitInfoPopup | gUnitInfoPopupFlag;
        } else if ((btn & 0xa00) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            Ui_HideUnitInfoPopup(gUnitInfoPopup);
        } else if ((btn & 0x200) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            spC[0] = *(s16 *)((u8 *)obj + 0xA);
            spC[1] = -0x3A;
            Ui_SlideWidgetChild(arg0, obj, spC, 0);
            tmp = *(s16 *)((u8 *)*(void **)((u8 *)arg0 + 0x5C) + 0xC);
            sp8[0] = 0x260;
            sp8[1] = tmp;
            Ui_SlideWidgetChild(arg0, *(void **)((u8 *)arg0 + 0x5C), sp8, 1);
            temp = *(Obj **)((u8 *)arg0 + 0x5C);
            if (temp != NULL) {
                refs = temp->refcount - 1;
                temp->refcount = refs;
                if (refs == 0 && temp != NULL) {
                    temp->destroy(1);
                }
                *(void **)((u8 *)arg0 + 0x5C) = NULL;
            }
            Ui_PlaySeCue(gUiUnitPanelStrings + 0x11C, 0x64);
            Process_Goto(arg0, 3);
        }
    }
    (void)pad;
}

extern "C" void Ui_LayoutUnitHirePanel(void *panel) {
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SlideWidgetChildMode1(void *, void *, s16 *, s32);
    void Ui_SetWidgetText(void *, void *);
    void Ui_BringChildToFront(void *, void *);
    extern u8 gUiUnitPanelStrings[];
    struct { s16 x; s16 y; } captionPos;
    struct { s16 x; s16 y; } listPos;
    void *caption;
    void *list;
    void *help;
    s16 savedY;

    /* Slide hire caption/list into place, set hire strings, raise list and help text. */
    caption = Ui_FindChild(panel, 0x80, 0);
    if (*(s16 *)((u8 *)caption + 0xC) < 0x28) {
        captionPos.x = *(s16 *)((u8 *)caption + 0xA);
        captionPos.y = 0x28;
        Ui_SlideWidgetChildMode1(panel, caption, &captionPos.x, 0);
    }
    *(s32 *)((u8 *)caption + 0x48) = 1;
    Ui_SetWidgetText(caption, gUiUnitPanelStrings + 0x227);
    list = *(void **)((u8 *)panel + 0x5C);
    if (*(s16 *)((u8 *)list + 0xA) != 0x118) {
        savedY = *(s16 *)((u8 *)list + 0xC);
        listPos.x = 0x118;
        listPos.y = savedY;
        Ui_SlideWidgetChildMode1(panel, list, &listPos.x, 0);
    }
    Ui_BringChildToFront(panel, *(void **)((u8 *)panel + 0x5C));
    help = Ui_FindChild(panel, -0x1000, 0);
    if (help != NULL) {
        Ui_SetWidgetText(help, gUiUnitPanelStrings + 0x23B);
    }
}

#pragma cplusplus reset

/* Build the unit-hire panel: caption widget plus list child bound to gUiContext. */
void Ui_InitUnitHirePanel(void *panel) {
    void *Heap_Alloc(u32);
    void Ui_SetWidgetText(void *, void *);
    void Ui_AddChild(void *, void *);
    void *fn_801BEDC4(void *, s32, s32, s32);
    void Ui_BringChildToFront(void *, void *);
    extern u8 lbl_8028FDB0[];
    extern u8 lbl_80292230[];
    extern u8 lbl_80293C84[];
    extern u8 lbl_80293C2C[];
    extern u8 lbl_80293C00[];
    extern u8 gUiUnitPanelStrings[];
    extern u32 gUiContext[];
    void *list;
    void *caption;
    void *box;
    void *tmp;

    caption = Heap_Alloc(0x60);
    if (caption != NULL) {
        M2C_FIELD(caption, void **, 0) = lbl_8028FDB0;
        M2C_FIELD(caption, u32 *, 4) = 0;
        M2C_FIELD(caption, void **, 0) = lbl_80292230;
        M2C_FIELD(caption, s16 *, 8) = -1;
        M2C_FIELD(caption, s16 *, 0xA) = 0;
        M2C_FIELD(caption, s16 *, 0xC) = -0x3A;
        M2C_FIELD(caption, s16 *, 0xE) = 0x260;
        M2C_FIELD(caption, s16 *, 0x10) = 0;
        M2C_FIELD(caption, s16 *, 0x12) = 0;
        M2C_FIELD(caption, s16 *, 0x14) = 0;
        M2C_FIELD(caption, s16 *, 0x16) = 0x260;
        M2C_FIELD(caption, s16 *, 0x18) = 0x3A;
        M2C_FIELD(caption, s16 *, 0x1A) = 0;
        M2C_FIELD(caption, s16 *, 0x1C) = 0;
        M2C_FIELD(caption, u8 *, 0x1E) = 0xFF;
        M2C_FIELD(caption, u8 *, 0x1F) = 0xFF;
        M2C_FIELD(caption, u8 *, 0x20) = 0xFF;
        M2C_FIELD(caption, u8 *, 0x21) = 0xFF;
        M2C_FIELD(caption, s16 *, 0x22) = 0x1F4;
        M2C_FIELD(caption, s16 *, 0x24) = 0;
        M2C_FIELD(caption, f32 *, 0x28) = 1.0f;
        M2C_FIELD(caption, f32 *, 0x2C) = 1.0f;
        M2C_FIELD(caption, f32 *, 0x30) = 1.0f;
        M2C_FIELD(caption, u32 *, 0x34) = 0;
        M2C_FIELD(caption, u32 *, 0x38) = 0;
        M2C_FIELD(caption, void **, 0) = lbl_80293C84;
        M2C_FIELD(caption, u32 *, 0x3C) = 0;
        M2C_FIELD(caption, u32 *, 0x40) = 0;
        M2C_FIELD(caption, u32 *, 0x44) = 0;
        M2C_FIELD(caption, u32 *, 0x40) = 0;
        M2C_FIELD(caption, u32 *, 0x48) = 0;
        M2C_FIELD(caption, u8 *, 0x4C) = 1;
        M2C_FIELD(caption, s16 *, 0x4E) = 0;
        M2C_FIELD(caption, s16 *, 0x50) = 0;
        M2C_FIELD(caption, s16 *, 0x52) = 0;
        M2C_FIELD(caption, s16 *, 0x54) = 0;
        M2C_FIELD(caption, void **, 0) = lbl_80293C2C;
        M2C_FIELD(caption, void **, 0) = lbl_80293C00;
        M2C_FIELD(caption, u32 *, 0x58) = 0;
        M2C_FIELD(caption, s16 *, 0x5C) = 0xB;
        M2C_FIELD(caption, s16 *, 0x5E) = 0x10;
    }
    M2C_FIELD(caption, s16 *, 8) = 0x80;
    M2C_FIELD(caption, s16 *, 0x24) = 8;
    M2C_FIELD(caption, s16 *, 0x4E) = 0x10;
    M2C_FIELD(caption, u32 *, 0x58) = 1;
    M2C_FIELD(caption, u32 *, 0x34) |= 0x10;
    M2C_FIELD(caption, u8 *, 0x4C) = 2;
    M2C_FIELD(caption, u32 *, 0x48) = 1;
    Ui_SetWidgetText(caption, gUiUnitPanelStrings + 0x227);
    Ui_AddChild(panel, caption);
    box = Heap_Alloc(0x94);
    if (box != NULL) {
        box = fn_801BEDC4(box, 0x260, 0x78, 0x1C2);
    }
    M2C_FIELD(panel, void **, 0x5C) = box;
    tmp = M2C_FIELD(panel, void **, 0x5C);
    if (tmp != NULL) {
        M2C_FIELD(tmp, s32 *, 4) = M2C_FIELD(tmp, s32 *, 4) + 1;
    }
    list = M2C_FIELD(panel, void **, 0x5C);
    M2C_FIELD(list, s16 *, 8) = 0x105;
    M2C_FIELD(M2C_FIELD(panel, void **, 0x5C), s16 *, 0x24) = 8;
    tmp = M2C_FIELD(panel, void **, 0x5C);
    M2C_FIELD(tmp, u32 *, 0x34) |= 0x10;
    M2C_FIELD(M2C_FIELD(panel, void **, 0x5C), u32 *, 0x40) = gUiContext[0];
    Ui_AddChild(panel, M2C_FIELD(panel, void **, 0x5C));
    Ui_BringChildToFront(panel, M2C_FIELD(panel, void **, 0x5C));
}

#pragma cplusplus on
/* Handle unit-hire panel input: A buys if affordable, X/Y open side panels, B backs out. */
extern "C" void Ui_HandleUnitHireCursorInput(void *arg0) {
 void Process_Goto(void *,s32); void UiCtx_BindUnit(void *,u32);
 u8 fn_8003D13C(u32); void fn_80137EA0(void *,u32); void Ui_SetPortraitUnit(void *,u32);
 u32 Ui_ListGetSelected(void *); void Ui_UpdatePanelWidgets(void *);
 void Ui_CloseChildAnim(void *,void *,s32);
 void Ui_PlaySeCue(void *,s32); void fn_801694AC(u32,void *); void fn_801695BC(u32,void *,s32);
 void Ui_CreateMsgPopup(void *,void *,f32,f32); s16 Unit_GetGoldCost(u32,s32);
 extern u8 gUiUnitPanelStrings[]; extern u8 gUiContext[]; extern u8 gBattleState[];
 extern u32 gUiInputFlags; extern void *gPadInput; extern f32 lbl_8036B2E4;
 class Pair { public: s16 x,y; Pair() {} Pair(s16 a,s16 b): x(a), y(b) {} Pair(const Pair &o) { *(u32 *)this=*(u32 *)&o; } Pair &operator=(const Pair &o) { *(u32 *)this=*(u32 *)&o; return *this; } };
 void Ui_SlideWidgetChild(void *,void *,const Pair &,s32);
 struct Obj {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
 virtual Pair v9();
 };
 u32 pos1,pos2;

 s32 held,btn;
 u8 gate;
 s32 flags;
 s16 height;
 u32 unit;
 s32 money;
 void *list;
 unit=Ui_ListGetSelected(M2C_FIELD(arg0,void **,0x48));
 Ui_UpdatePanelWidgets(arg0);
 if(unit!=Ui_ListGetSelected(M2C_FIELD(arg0,void **,0x48))) {
 unit=Ui_ListGetSelected(M2C_FIELD(arg0,void **,0x48));
 Ui_SetPortraitUnit(M2C_FIELD(arg0,void **,0x4C),unit);
 fn_80137EA0(M2C_FIELD(arg0,void **,0x54),unit);
 M2C_FIELD(M2C_FIELD(arg0,void **,0x58),u32 *,0x3C)=unit;
 }
 flags=gUiInputFlags; gate=0;
 if((flags&0x10)&&!(flags&0x20)) gate=1;
 if(!gate) {
 held=M2C_FIELD(gPadInput,s32 *,4);
 btn=held&(M2C_FIELD(gPadInput,s32 *,8)^held);
 if((btn&0x100)&&unit) {
 if(!fn_8003D13C(unit)) {
 *(Pair *)&pos1=((Obj *)M2C_FIELD(arg0,void **,0x48))->v9();
 Ui_CreateMsgPopup(gUiUnitPanelStrings+0x24F,arg0,(f32)*(s16 *)&pos1,(f32)*((s16 *)&pos1+1));
 return;
 }
 money=*(s32 *)(gBattleState+0x1C);
 if(money<Unit_GetGoldCost(unit,1)) {
 *(Pair *)&pos2=((Obj *)M2C_FIELD(arg0,void **,0x48))->v9();
 Ui_CreateMsgPopup(gUiUnitPanelStrings+0x263,arg0,(f32)*(s16 *)&pos2,(f32)*((s16 *)&pos2+1));
 return;
 }
 {

 UiCtx_BindUnit(gUiContext,unit);
 list=M2C_FIELD(arg0,void **,0x48);
 gUiContext[0x15]=M2C_FIELD(list,s16 *,0x56);
 M2C_FIELD(list,f32 *,0x30)=lbl_8036B2E4;
 list=M2C_FIELD(arg0,void **,0x48);
 height=M2C_FIELD(list,s16 *,0x10)-M2C_FIELD(list,s16 *,0xC);
 Ui_SlideWidgetChild(arg0,list,Pair(M2C_FIELD(list,s16 *,0xA),-height),0);
 Ui_CloseChildAnim(arg0,M2C_FIELD(arg0,void **,0x50),0);
 Process_Goto(arg0,5);
 Ui_PlaySeCue(gUiUnitPanelStrings+0x10C,0x64);
 }
 } else if((btn&0x800)&&unit) {
 fn_801695BC(unit,arg0,0x1000000); M2C_FIELD(arg0,u8 *,0x44)=4; Process_Goto(arg0,0x1D);
 } else if((btn&0x400)&&unit) {
 fn_801694AC(unit,arg0); M2C_FIELD(arg0,u8 *,0x44)=4; Process_Goto(arg0,0x1E);
 } else if(btn&0x200) {
 Process_Goto(arg0,12); Ui_PlaySeCue(gUiUnitPanelStrings+0x11C,0x64);
 }
 }
}
#pragma cplusplus reset

#pragma cplusplus on
/* Attach cached unit-panel children, size them for the open layout, and set the caption text. */
extern "C" void Ui_LayoutUnitPanel(void *arg0) {
    f32 Ui_GetWorldScale(void *);
    void Ui_BringChildToFront(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_AddChild(void *, void *);
    void Ui_OpenChildAnim(void *, void *, s32);
    void Ui_SlideWidgetChildMode1(void *, void *, s16 *, s32);
    void Ui_SetWidgetText(u32, s32);
    extern u8 gUiUnitPanelStrings[];

    struct Obj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
    };

    s16 size0[2];
    s16 size1[2];
    s16 size3[2];
    s16 size4[2];
    void *child0;
    void *panel;
    void *child;
    u32 caption;
    s16 savedH;

    panel = arg0;
    if ((child0 = Ui_FindChild(arg0, 0x100, 0)) == 0) {
        child0 = *(void **)((u8 *)panel + 0x48);
        Ui_AddChild(panel, child0);
    }
    if (*(s16 *)((u8 *)child0 + 0xC) != 0x10) {
        size0[0] = *(s16 *)((u8 *)child0 + 0xA);
        size0[1] = 0x10;
        Ui_SlideWidgetChildMode1(panel, child0, size0, 0);
    }
    *(u8 *)((u8 *)child0 + 0x4D) = 0;
    *(f32 *)((u8 *)child0 + 0x30) = 1.0f;
    if ((child = Ui_FindChild(panel, 0x101, 0)) == 0) {
        child = *(void **)((u8 *)panel + 0x4C);
        Ui_AddChild(panel, child);
    }
    *(s32 *)((u8 *)child + 0x40) = 0x1003C;
    ((Obj *)child)->v8();
    if (*(s16 *)((u8 *)child + 0xA) != 0x20) {
        savedH = *(s16 *)((u8 *)child + 0xC);
        size1[0] = 0x20;
        size1[1] = savedH;
        Ui_SlideWidgetChildMode1(panel, child, size1, 0);
    }
    if ((child = Ui_FindChild(panel, 0x102, 0)) == 0) {
        child = *(void **)((u8 *)panel + 0x50);
        Ui_AddChild(panel, child);
    }
    if (Ui_GetWorldScale(child) < 1.0f) {
        Ui_OpenChildAnim(panel, child, 0);
    }
    if ((child = Ui_FindChild(panel, 0x103, 0)) == 0) {
        child = *(void **)((u8 *)panel + 0x54);
        Ui_AddChild(panel, child);
    }
    if (*(s16 *)((u8 *)child + 0xA) != 0x20) {
        savedH = *(s16 *)((u8 *)child + 0xC);
        size3[0] = 0x20;
        size3[1] = savedH;
        Ui_SlideWidgetChildMode1(panel, child, size3, 0);
    }
    if ((child = Ui_FindChild(panel, 0x104, 0)) == 0) {
        child = *(void **)((u8 *)panel + 0x58);
        Ui_AddChild(panel, child);
    }
    if (*(s16 *)((u8 *)child + 0xA) != 0x134) {
        savedH = *(s16 *)((u8 *)child + 0xC);
        size4[0] = 0x134;
        size4[1] = savedH;
        Ui_SlideWidgetChildMode1(panel, child, size4, 0);
    }
    Ui_BringChildToFront(panel, child0);
    caption = (u32)Ui_FindChild(panel, -0x1000, 0);
    if (caption != 0U) {
        Ui_SetWidgetText(caption, (s32)(gUiUnitPanelStrings + 0x277));
    }
}

#pragma cplusplus on
extern "C" void fn_801BDAF8(void *arg0) {
#pragma opt_common_subs off
    void *Heap_Alloc(s32);
    void *Ui_ListGetSelected(void *);
    void fn_8013B064(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_RemoveChild(void *, void *);
    void Ui_AddChild(void *, void *);
    void Ui_BringChildToFront(void *, void *);
    void *fn_80179F8C(void *, s16, s16, s16, s16, s32);
    u8 *Ui_GetColor(s32);
    void Ui_SetPortraitUnit(void *, void *);
    void fn_80137EA0(void *, void *);
    void fn_801BC71C(void);
    extern u8 gUiUnitPanelStrings[];
    extern u8 lbl_8028FDB0[];
    extern u8 lbl_802919B0[];
    extern u8 lbl_80291A0C[];
    extern u8 lbl_80291A3C[];
    extern u8 lbl_80292178[];
    extern u8 lbl_80292230[];
    extern u8 gUnitLists[];
    extern f32 lbl_8036B2D8;
    extern f32 lbl_8036B2E0;

    struct Obj {
        virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0;
        virtual void v3() = 0; virtual void v4() = 0; virtual void v5() = 0;
        virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0;
        virtual void v9() = 0; virtual void v10() = 0; virtual void v11(void *) = 0;
        virtual void v12(s32) = 0;
    };

    void *self = arg0;
    void *entry;
    void *p;
    void *hold;
    void *q;
    f32 zero;

    Ui_RemoveChild(self, Ui_FindChild(self, 0x80, 0));
    Ui_RemoveChild(self, Ui_FindChild(self, 0x81, 0));

    p = Heap_Alloc(0xD8);
    if (p != NULL) {
        p = fn_80179F8C(p, 0x38, 0x10, 0x1F0, 0x90, 0x226);
    }
    *(void **)((u8 *)self + 0x48) = p;
    q = *(void **)((u8 *)self + 0x48);
    if (q != NULL) {
        *(s32 *)((u8 *)q + 4) = *(s32 *)((u8 *)q + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 0x24) = 8;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 0x64) = 8;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 8) = 0x100;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 0x5A) = 0x1C;
    ((Obj *)*(void **)((u8 *)self + 0x48))->v12(4);
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x48) + 0x58) = 3;

    hold = *(void **)((u8 *)self + 0x48);
    entry = *(void **)gUnitLists;
    while (entry != NULL) {
        fn_8013B064(hold, entry);
        entry = *(void **)((u8 *)entry + 0x184);
    }
    hold = *(void **)((u8 *)self + 0x48);
    entry = *(void **)(gUnitLists + 0x3C);
    while (entry != NULL) {
        fn_8013B064(hold, entry);
        entry = *(void **)((u8 *)entry + 0x184);
    }
    q = *(void **)((u8 *)self + 0x48);
    *(void **)((u8 *)q + 0x7C) = (void *)fn_801BC71C;
    *(s32 *)((u8 *)q + 0x80) = 0;
    Ui_AddChild(self, *(void **)((u8 *)self + 0x48));

    p = Heap_Alloc(0x50);
    if (p != NULL) {
        *(void **)p = lbl_8028FDB0;
        *(s32 *)((u8 *)p + 4) = 0;
        *(void **)p = lbl_80292230;
        *(s16 *)((u8 *)p + 8) = -1;
        *(s16 *)((u8 *)p + 0xA) = 0x130;
        *(s16 *)((u8 *)p + 0xC) = 0xA8;
        *(s16 *)((u8 *)p + 0xE) = (s16)(0x130 + 0x118);
        *(s16 *)((u8 *)p + 0x10) = (s16)(0xA8 + 0x40);
        *(s16 *)((u8 *)p + 0x12) = 0;
        *(s16 *)((u8 *)p + 0x14) = 0;
        *(s16 *)((u8 *)p + 0x16) = 0x118;
        *(s16 *)((u8 *)p + 0x18) = 0x40;
        *(s16 *)((u8 *)p + 0x1A) = 0;
        *(s16 *)((u8 *)p + 0x1C) = 0;
        *(u8 *)((u8 *)p + 0x1E) = 0xFF;
        *(u8 *)((u8 *)p + 0x1F) = 0xFF;
        *(u8 *)((u8 *)p + 0x20) = 0xFF;
        *(u8 *)((u8 *)p + 0x21) = 0xFF;
        *(s16 *)((u8 *)p + 0x22) = 0x1FE;
        *(s16 *)((u8 *)p + 0x24) = 0;
        zero = lbl_8036B2D8;
        *(f32 *)((u8 *)p + 0x28) = zero;
        *(f32 *)((u8 *)p + 0x2C) = zero;
        *(f32 *)((u8 *)p + 0x30) = zero;
        *(s32 *)((u8 *)p + 0x34) = 0;
        *(s32 *)((u8 *)p + 0x38) = 0;
        *(void **)p = lbl_80292178;
        *(u8 *)((u8 *)p + 0x3C) = 0xFF;
        *(u8 *)((u8 *)p + 0x3D) = 0xFF;
        *(u8 *)((u8 *)p + 0x3E) = 0xFF;
        *(u8 *)((u8 *)p + 0x3F) = 0xFF;
        *(s32 *)((u8 *)p + 0x40) = 0;
        *(s16 *)((u8 *)p + 0x44) = 0;
        *(s16 *)((u8 *)p + 0x46) = 0;
        ((Obj *)p)->v8();
    }
    *(void **)((u8 *)self + 0x50) = p;
    q = *(void **)((u8 *)self + 0x50);
    if (q != NULL) {
        *(s32 *)((u8 *)q + 4) = *(s32 *)((u8 *)q + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x50) + 0x24) = 8;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x50) + 8) = 0x102;
    q = *(void **)((u8 *)self + 0x50);
    *(u32 *)((u8 *)q + 0x34) |= 0x10;
    {
        u8 col[4];
        u8 *color = Ui_GetColor(2);
        u8 first = color[0];
        col[0] = first;
        col[1] = color[1];
        col[2] = color[2];
        col[3] = color[3];
        q = *(void **)((u8 *)self + 0x50);
        if ((u8 *)q + 0x3C != col) {
            *(u8 *)((u8 *)q + 0x3C) = first;
            *(u8 *)((u8 *)q + 0x3D) = col[1];
            *(u8 *)((u8 *)q + 0x3E) = col[2];
            *(u8 *)((u8 *)q + 0x3F) = col[3];
        }
    }
    *(f32 *)((u8 *)*(void **)((u8 *)self + 0x50) + 0x2C) = lbl_8036B2E0;
    *(void **)((u8 *)*(void **)((u8 *)self + 0x50) + 0x40) = gUiUnitPanelStrings + 0x1B7;
    Ui_AddChild(self, *(void **)((u8 *)self + 0x50));

    p = Heap_Alloc(0x54);
    if (p != NULL) {
        *(void **)p = lbl_8028FDB0;
        *(s32 *)((u8 *)p + 4) = 0;
        *(void **)p = lbl_80292230;
        *(s16 *)((u8 *)p + 8) = -1;
        *(s16 *)((u8 *)p + 0xA) = 0x20;
        *(s16 *)((u8 *)p + 0xC) = 0x98;
        *(s16 *)((u8 *)p + 0xE) = (s16)(0x20 + 0x108);
        *(s16 *)((u8 *)p + 0x10) = (s16)(0x98 + 0x55);
        *(s16 *)((u8 *)p + 0x12) = 0;
        *(s16 *)((u8 *)p + 0x14) = 0;
        *(s16 *)((u8 *)p + 0x16) = 0x108;
        *(s16 *)((u8 *)p + 0x18) = 0x55;
        *(s16 *)((u8 *)p + 0x1A) = 0;
        *(s16 *)((u8 *)p + 0x1C) = 0;
        *(u8 *)((u8 *)p + 0x1E) = 0xFF;
        *(u8 *)((u8 *)p + 0x1F) = 0xFF;
        *(u8 *)((u8 *)p + 0x20) = 0xFF;
        *(u8 *)((u8 *)p + 0x21) = 0xFF;
        *(s16 *)((u8 *)p + 0x22) = 0x1F4;
        *(s16 *)((u8 *)p + 0x24) = 0;
        zero = lbl_8036B2D8;
        *(f32 *)((u8 *)p + 0x28) = zero;
        *(f32 *)((u8 *)p + 0x2C) = zero;
        *(f32 *)((u8 *)p + 0x30) = zero;
        *(s32 *)((u8 *)p + 0x34) = 0;
        *(s32 *)((u8 *)p + 0x38) = 0;
        *(void **)p = lbl_80291A3C;
        *(s32 *)((u8 *)p + 0x3C) = 0;
        *(s32 *)((u8 *)p + 0x40) = 0x1003C;
        *(s32 *)((u8 *)p + 0x4C) = 0;
        *(s32 *)((u8 *)p + 0x50) = 0;
        ((Obj *)p)->v8();
    }
    *(void **)((u8 *)self + 0x4C) = p;
    q = *(void **)((u8 *)self + 0x4C);
    if (q != NULL) {
        *(s32 *)((u8 *)q + 4) = *(s32 *)((u8 *)q + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x4C) + 8) = 0x101;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x4C) + 0x24) = 8;
    *(s32 *)((u8 *)*(void **)((u8 *)self + 0x4C) + 0x4C) = 1;
    q = *(void **)((u8 *)self + 0x4C);
    *(u32 *)((u8 *)q + 0x34) |= 0x10;
    Ui_SetPortraitUnit(*(void **)((u8 *)self + 0x4C), Ui_ListGetSelected(*(void **)((u8 *)self + 0x48)));
    Ui_AddChild(self, *(void **)((u8 *)self + 0x4C));

    p = Heap_Alloc(0x4C);
    if (p != NULL) {
        *(void **)p = lbl_8028FDB0;
        *(s32 *)((u8 *)p + 4) = 0;
        *(void **)p = lbl_80292230;
        *(s16 *)((u8 *)p + 8) = -1;
        *(s16 *)((u8 *)p + 0xA) = 0x20;
        *(s16 *)((u8 *)p + 0xC) = 0xF8;
        *(s16 *)((u8 *)p + 0xE) = (s16)(0x20 + 0x108);
        *(s16 *)((u8 *)p + 0x10) = (s16)(0xF8 + 0x95);
        *(s16 *)((u8 *)p + 0x12) = 0;
        *(s16 *)((u8 *)p + 0x14) = 0;
        *(s16 *)((u8 *)p + 0x16) = 0x108;
        *(s16 *)((u8 *)p + 0x18) = 0x95;
        *(s16 *)((u8 *)p + 0x1A) = 0;
        *(s16 *)((u8 *)p + 0x1C) = 0;
        *(u8 *)((u8 *)p + 0x1E) = 0xFF;
        *(u8 *)((u8 *)p + 0x1F) = 0xFF;
        *(u8 *)((u8 *)p + 0x20) = 0xFF;
        *(u8 *)((u8 *)p + 0x21) = 0xFF;
        *(s16 *)((u8 *)p + 0x22) = 0x1F4;
        *(s16 *)((u8 *)p + 0x24) = 0;
        zero = lbl_8036B2D8;
        *(f32 *)((u8 *)p + 0x28) = zero;
        *(f32 *)((u8 *)p + 0x2C) = zero;
        *(f32 *)((u8 *)p + 0x30) = zero;
        *(s32 *)((u8 *)p + 0x34) = 0;
        *(s32 *)((u8 *)p + 0x38) = 0;
        *(void **)p = lbl_80291A0C;
        *(s32 *)((u8 *)p + 0x44) = 0;
        *(u8 *)((u8 *)p + 0x48) = 1;
        ((Obj *)p)->v8();
    }
    *(void **)((u8 *)self + 0x54) = p;
    q = *(void **)((u8 *)self + 0x54);
    if (q != NULL) {
        *(s32 *)((u8 *)q + 4) = *(s32 *)((u8 *)q + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x54) + 8) = 0x103;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x54) + 0x24) = 8;
    q = *(void **)((u8 *)self + 0x54);
    *(u32 *)((u8 *)q + 0x34) |= 0x10;
    fn_80137EA0(*(void **)((u8 *)self + 0x54), Ui_ListGetSelected(*(void **)((u8 *)self + 0x48)));
    Ui_AddChild(self, *(void **)((u8 *)self + 0x54));

    p = Heap_Alloc(0x40);
    if (p != NULL) {
        *(void **)p = lbl_8028FDB0;
        *(s32 *)((u8 *)p + 4) = 0;
        *(void **)p = lbl_80292230;
        *(s16 *)((u8 *)p + 8) = -1;
        *(s16 *)((u8 *)p + 0xA) = 0x134;
        *(s16 *)((u8 *)p + 0xC) = 0x110;
        *(s16 *)((u8 *)p + 0xE) = (s16)(0x134 + 0x110);
        *(s16 *)((u8 *)p + 0x10) = (s16)(0x110 + 0x7D);
        *(s16 *)((u8 *)p + 0x12) = 0;
        *(s16 *)((u8 *)p + 0x14) = 0;
        *(s16 *)((u8 *)p + 0x16) = 0x110;
        *(s16 *)((u8 *)p + 0x18) = 0x7D;
        *(s16 *)((u8 *)p + 0x1A) = 0;
        *(s16 *)((u8 *)p + 0x1C) = 0;
        *(u8 *)((u8 *)p + 0x1E) = 0xFF;
        *(u8 *)((u8 *)p + 0x1F) = 0xFF;
        *(u8 *)((u8 *)p + 0x20) = 0xFF;
        *(u8 *)((u8 *)p + 0x21) = 0xFF;
        *(s16 *)((u8 *)p + 0x22) = 0x1F4;
        *(s16 *)((u8 *)p + 0x24) = 0;
        zero = lbl_8036B2D8;
        *(f32 *)((u8 *)p + 0x28) = zero;
        *(f32 *)((u8 *)p + 0x2C) = zero;
        *(f32 *)((u8 *)p + 0x30) = zero;
        *(s32 *)((u8 *)p + 0x34) = 0;
        *(s32 *)((u8 *)p + 0x38) = 0;
        *(void **)p = lbl_802919B0;
        *(s32 *)((u8 *)p + 0x3C) = 0;
        ((Obj *)p)->v8();
    }
    *(void **)((u8 *)self + 0x58) = p;
    q = *(void **)((u8 *)self + 0x58);
    if (q != NULL) {
        *(s32 *)((u8 *)q + 4) = *(s32 *)((u8 *)q + 4) + 1;
    }
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x58) + 8) = 0x104;
    *(s16 *)((u8 *)*(void **)((u8 *)self + 0x58) + 0x24) = 8;
    q = *(void **)((u8 *)self + 0x58);
    *(u32 *)((u8 *)q + 0x34) |= 0x10;
    *(void **)((u8 *)*(void **)((u8 *)self + 0x58) + 0x3C) = Ui_ListGetSelected(*(void **)((u8 *)self + 0x48));
    Ui_AddChild(self, *(void **)((u8 *)self + 0x58));
    Ui_BringChildToFront(self, *(void **)((u8 *)self + 0x48));
}
#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_801BE1EC(void *arg0) {
    struct Obj {
        u8 pad[0x40];
        virtual void m08(s32) = 0;
    };
    ((Obj *) arg0)->m08(-1);
}

#pragma cplusplus on
/* Destroy a unit panel: release ten refcounted children, run base dtor, optionally free. */
extern "C" void *Ui_DestroyUnitPanel(void *panel, s16 doFree) {
    void Ui_DtorPanelBase(void *, s32);
    void Heap_Free(void *);
    extern void gUiPanelBaseVt;

    struct RefObj {
        virtual void destroy(s32);
        s32 refCount;
    };

    struct UnitPanel {
        u8 pad[0x40];
        void *vt;
        u8 pad44[4];
        RefObj *slot0;
        RefObj *slot1;
        RefObj *slot2;
        RefObj *slot3;
        RefObj *slot4;
        RefObj *slot5;
        RefObj *slot6;
        RefObj *slot7;
        RefObj *slot8;
        RefObj *slot9;
    };

    s16 freeFlag;
    RefObj *child;
    UnitPanel *self;

    freeFlag = doFree;
    if (panel != NULL) {
        self = (UnitPanel *)panel;
        self->vt = &gUiPanelBaseVt;
        child = self->slot0;
        if (child != NULL) {
            if (--child->refCount == 0 && child != NULL) {
                child->destroy(1);
            }
            self->slot0 = (RefObj *)0;
        }
        child = self->slot1;
        if (child != NULL) {
            if (--child->refCount == 0 && child != NULL) {
                child->destroy(1);
            }
            self->slot1 = (RefObj *)0;
        }
        child = self->slot2;
        if (child != NULL) {
            if (--child->refCount == 0 && child != NULL) {
                child->destroy(1);
            }
            self->slot2 = (RefObj *)0;
        }
        child = self->slot3;
        if (child != NULL) {
            if (--child->refCount == 0 && child != NULL) {
                child->destroy(1);
            }
            self->slot3 = (RefObj *)0;
        }
        child = self->slot4;
        if (child != NULL) {
            if (--child->refCount == 0 && child != NULL) {
                child->destroy(1);
            }
            self->slot4 = (RefObj *)0;
        }
        child = self->slot5;
        if (child != NULL) {
            if (--child->refCount == 0 && child != NULL) {
                child->destroy(1);
            }
            self->slot5 = (RefObj *)0;
        }
        child = self->slot6;
        if (child != NULL) {
            if (--child->refCount == 0 && child != NULL) {
                child->destroy(1);
            }
            self->slot6 = (RefObj *)0;
        }
        child = self->slot7;
        if (child != NULL) {
            if (--child->refCount == 0 && child != NULL) {
                child->destroy(1);
            }
            self->slot7 = (RefObj *)0;
        }
        child = self->slot8;
        if (child != NULL) {
            if (--child->refCount == 0 && child != NULL) {
                child->destroy(1);
            }
            self->slot8 = (RefObj *)0;
        }
        child = self->slot9;
        if (child != NULL) {
            if (--child->refCount == 0 && child != NULL) {
                child->destroy(1);
            }
            self->slot9 = (RefObj *)0;
        }
        Ui_DtorPanelBase(panel, 0);
        if (freeFlag > 0) {
            Heap_Free(panel);
        }
    }
    return panel;
}

extern "C" void fn_801BE500(void *arg0) {
    void *Heap_Alloc(s32);
    void String_AssignCStr(void *, void *, s32);
    s32 strlen(const char *);
    void Ui_AddChild(void *, void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *, void *);
    extern u8 lbl_8028FDB0[];
    extern u8 lbl_80292230[];
    extern u8 lbl_80293C84[];
    extern u8 lbl_80293C58[];
    extern u8 gUiUnitPanelStrings[];
    u8 *w;
    void *child;
    void *text;
    s32 len;

    w = (u8 *)Heap_Alloc(0x5C);
    if (w) {
        *(void **)(w + 0x0) = lbl_8028FDB0;
        *(s32 *)(w + 0x4) = 0;
        *(void **)(w + 0x0) = lbl_80292230;
        *(s16 *)(w + 0x8) = -1;
        *(s16 *)(w + 0xA) = 0;
        *(s16 *)(w + 0xC) = 0x190;
        *(s16 *)(w + 0xE) = 0x260;
        *(s16 *)(w + 0x10) = 0x1C0;
        *(s16 *)(w + 0x12) = 0;
        *(s16 *)(w + 0x14) = 0;
        *(s16 *)(w + 0x16) = 0x260;
        *(s16 *)(w + 0x18) = 0x30;
        *(s16 *)(w + 0x1A) = 0;
        *(s16 *)(w + 0x1C) = 0;
        w[0x1E] = 0xFF;
        w[0x1F] = 0xFF;
        w[0x20] = 0xFF;
        w[0x21] = 0xFF;
        *(s16 *)(w + 0x22) = 0x5A;
        *(s16 *)(w + 0x24) = 0;
        *(f32 *)(w + 0x28) = 1.0f;
        *(f32 *)(w + 0x2C) = 1.0f;
        *(f32 *)(w + 0x30) = 1.0f;
        *(s32 *)(w + 0x34) = 0;
        *(s32 *)(w + 0x38) = 0;
        *(void **)(w + 0x0) = lbl_80293C84;
        *(s32 *)(w + 0x3C) = 0;
        *(s32 *)(w + 0x40) = 0;
        *(s32 *)(w + 0x44) = 0;
        *(s32 *)(w + 0x40) = 0;
        *(s32 *)(w + 0x48) = 0;
        w[0x4C] = 1;
        *(s16 *)(w + 0x4E) = 0;
        *(s16 *)(w + 0x50) = 0;
        *(s16 *)(w + 0x52) = 0;
        *(s16 *)(w + 0x54) = 0;
        *(void **)(w + 0x0) = lbl_80293C58;
        *(s32 *)(w + 0x58) = 1;
        *(s16 *)(w + 0x4E) = 0x30;
        *(s16 *)(w + 0x52) = 0x30;
    }
    *(s16 *)(w + 0x8) = -0x1000;
    *(s32 *)(w + 0x48) = 1;
    len = strlen((const char *)gUiUnitPanelStrings + 0xF7);
    String_AssignCStr(w + 0x3C, gUiUnitPanelStrings + 0xF7, len);
    *(s32 *)(w + 0x34) |= 0x10;
    *(s32 *)(w + 0x58) = 1;
    Ui_AddChild(arg0, w);
    child = Ui_FindChild(arg0, -0x1000, 0);
    if (child) {
        Ui_SetWidgetText(child, gUiUnitPanelStrings + 0x28B);
    }
}

#pragma cplusplus reset

#pragma cplusplus reset
void *fn_801BE6A8(s32 arg0) {
    void *Process_CreateChild(void *, s32);
    void fn_801403F0(void);
    void Process_Goto(void *, s32);
    extern u8 gUiUnitPanelClass[];
    extern u8 gUiPanelBaseVt[];
    extern u8 gUiContext[];
    extern u8 lbl_80368274;
    void *temp_r3;

    gUiContext[8] = 0x80;
    temp_r3 = Process_CreateChild(gUiUnitPanelClass, arg0);
    if (temp_r3 != NULL) {
        fn_801403F0();
        *(void **)((char *)temp_r3 + 0x40) = gUiPanelBaseVt;
        *(s32 *)((char *)temp_r3 + 0x48) = 0;
        *(s32 *)((char *)temp_r3 + 0x4C) = 0;
        *(s32 *)((char *)temp_r3 + 0x50) = 0;
        *(s32 *)((char *)temp_r3 + 0x54) = 0;
        *(s32 *)((char *)temp_r3 + 0x58) = 0;
        *(s32 *)((char *)temp_r3 + 0x5C) = 0;
        *(s32 *)((char *)temp_r3 + 0x60) = 0;
        *(s32 *)((char *)temp_r3 + 0x64) = 0;
        *(s32 *)((char *)temp_r3 + 0x68) = 0;
        *(s32 *)((char *)temp_r3 + 0x6C) = 0;
        lbl_80368274 = 0x80;
    }
    Process_Goto(temp_r3, 0xB);
    return temp_r3;
}

void *fn_801BE748(s32 arg0) {
    void *Process_CreateChild(void *, s32);
    void fn_801403F0(void);
    extern u8 gUiUnitPanelClass[];
    extern u8 gUiPanelBaseVt[];
    extern u8 lbl_80368274;
    void *temp_r3;

    temp_r3 = Process_CreateChild(gUiUnitPanelClass, arg0);
    if (temp_r3 != NULL) {
        fn_801403F0();
        *(void **)((char *)temp_r3 + 0x40) = gUiPanelBaseVt;
        *(s32 *)((char *)temp_r3 + 0x48) = 0;
        *(s32 *)((char *)temp_r3 + 0x4C) = 0;
        *(s32 *)((char *)temp_r3 + 0x50) = 0;
        *(s32 *)((char *)temp_r3 + 0x54) = 0;
        *(s32 *)((char *)temp_r3 + 0x58) = 0;
        *(s32 *)((char *)temp_r3 + 0x5C) = 0;
        *(s32 *)((char *)temp_r3 + 0x60) = 0;
        *(s32 *)((char *)temp_r3 + 0x64) = 0;
        *(s32 *)((char *)temp_r3 + 0x68) = 0;
        *(s32 *)((char *)temp_r3 + 0x6C) = 0;
        lbl_80368274 = 0x80;
    }
    return temp_r3;
}

void fn_801BE7CC(void) {
    extern u16 gUiUnitPanelStrings[];
    Msg_Expand((u8 *)gUiUnitPanelStrings + 0xDF);
}

void *fn_801BE7F8(void){extern u8 gUiUnitPanelStrings[];return gUiUnitPanelStrings+0x29b;}

u8 fn_801BE808(void)
{
    void *Process_Find(void *);
    void Ui_FindChild(void *, s32, s32);
    u32 fn_8017BC94(void);
    extern u8 gUiUnitPanelClass[];
    u32 result;
    s32 ret;

    Ui_FindChild(Process_Find(gUiUnitPanelClass), 0x106, 0);
    result = fn_8017BC94();
    ret = 2;
    if (result != 0) {
        ret = 0;
    }
    return (u8)ret;
}

s32 Ui_SkillCapacityMenuItem(s32 unused, void *parent, void *entry) {
    void Ui_CreateMsgPopup(void *, void *, f32, f32);
    extern u8 gUiUnitPanelStrings[];
    extern u32 gUiContext[];
    f32 x;
    f32 y;

    if (*(u8 *)((u8 *)entry + 0x39) == 2) {
        x = (f32)(*(s16 *)((u8 *)parent + 0x30) + *(s16 *)((u8 *)entry + 0x30));
        y = (f32)(*(s16 *)((u8 *)parent + 0x32) + *(s16 *)((u8 *)entry + 0x32));
        Ui_CreateMsgPopup(gUiUnitPanelStrings + 0x2AB, parent, x, y);
        return 0;
    }
    *((u8 *)gUiContext + 8) = 0x83;
    return 5;
}

void fn_801BE8F0(void) {
    extern u16 gUiUnitPanelStrings[];
    Msg_Expand((u8 *)gUiUnitPanelStrings + 0x16E);
}

void *fn_801BE91C(void) { extern u8 gUiUnitPanelStrings[]; return gUiUnitPanelStrings+0x2D4; }

/* Validate skill assign on the unit panel; store error -1/-2/-3 at +4, return 2 on fail or 0. */
s32 Ui_ValidateSkillAssign(void *item) {
    void *Process_Find(void *);
    void *Res_GetEntry(u8);
    u8 Skill_UnitMeetsReqs(void *, void *);
    void Ui_FindChild(void *, s32, s32);
    u32 Unit_CountExtraSkills(void);
    s32 Unit_GetSkillCapacityUsed(void *);
    extern u8 gUiUnitPanelClass[];
    extern u32 gUiContext[];
    void *unit;
    void *cls;
    void *skill;
    s32 capacity;
    u8 found;
    s32 i;
    void *panel;

    *((s8 *)item + 4) = 0;
    panel = Process_Find(gUiUnitPanelClass);
    unit = (void *)gUiContext[0];
    Ui_FindChild(panel, 0x106, 0);
    if (Unit_CountExtraSkills() >= 5U) {
        *((s8 *)item + 4) = -1;
        return 2;
    }
    cls = *(void **)((u8 *)unit + 0x18C);
    capacity = *((u8 *)cls + 0x40);
    if (capacity <= Unit_GetSkillCapacityUsed(unit)) {
        *((s8 *)item + 4) = -2;
        return 2;
    }
    found = 0;
    i = 0;
    do {
        skill = Res_GetEntry((u8)i);
        if (*((u8 *)skill + 0x19) != 0 && Skill_UnitMeetsReqs(skill, unit) != 0) {
            found = 1;
            break;
        }
        i += 1;
    } while (i < 0x62);
    if (found == 0) {
        *((s8 *)item + 4) = -3;
        return 2;
    }
    return 0;
}

/* Menu item for skill assign: draw error popup from item+4, or enter state 0x82. */
s32 Ui_SkillAssignMenuItem(void *item, void *parent, void *slot) {
    void Ui_CreateMsgPopup(void *, void *, f32, f32);
    extern u8 gUiUnitPanelStrings[];
    extern u8 gUiContext[];
    f32 x;
    f32 y;

    if (*(u8 *)((u8 *)slot + 0x39) == 2) {
        x = (f32)(*(s16 *)((u8 *)parent + 0x30) + *(s16 *)((u8 *)slot + 0x30));
        y = (f32)(*(s16 *)((u8 *)parent + 0x32) + *(s16 *)((u8 *)slot + 0x32));
        switch (*(s8 *)((u8 *)item + 4)) {
        case -1:
            Ui_CreateMsgPopup(gUiUnitPanelStrings + 0x2E3, parent, x, y);
            break;
        case -2:
            Ui_CreateMsgPopup(gUiUnitPanelStrings + 0x18C, parent, x, y);
            break;
        case -3:
            Ui_CreateMsgPopup(gUiUnitPanelStrings + 0x2FA, parent, x, y);
            break;
        }
        return 0;
    }
    gUiContext[8] = 0x82;
    return 5;
}

#pragma cplusplus on
extern "C" void *fn_801BEB24(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    struct Obj {
        virtual void m08() = 0;
        virtual void m0C() = 0;
        virtual void m10() = 0;
        virtual void m14() = 0;
        virtual void m18() = 0;
        virtual void m1C() = 0;
        virtual void m20() = 0;
        virtual void m24() = 0;
        virtual void m28() = 0;
    };
    void fn_801BEB9C(void *, s16 *, s16 *, s16);
    extern u8 lbl_802918A0[];
    s16 spC[2];
    s16 sp8[2];

    sp8[1] = arg3;
    spC[0] = arg1;
    spC[1] = arg2;
    sp8[0] = 0x108;
    fn_801BEB9C(arg0, spC, sp8, arg4);
    *(void **)arg0 = lbl_802918A0;
    *(s32 *)((u8 *)arg0 + 0xCC) = 0;
    ((Obj *)arg0)->m28();
    return arg0;
}
#pragma cplusplus reset

#pragma cplusplus on
#pragma global_optimizer off
extern "C" void *fn_801BEB9C(void *arg0, s16 *arg1, s16 *arg2, s16 arg3) {
    void fn_80142060(void *);
    extern void *lbl_8028FDB0[];
    extern void *lbl_80292230[];
    extern void *lbl_80292208[];
    extern void *gUiUnitPanelMidVtbl[];
    extern void *gEmptyVtbl[];
    extern f32 lbl_8036B2D8;
    extern f32 lbl_8036B2E0;
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
    };
    struct Sub {
        virtual void v0() = 0;
        virtual void v1() = 0;
    };
    typedef struct { s16 x; s16 y; } Pair;
    void *vt92230;
    s32 zero;
    s16 neg1;
    s16 y0;
    void *self;
    s16 x1;
    s16 x0;
    void *vt92208;
    void *tmp;
    f32 one;
    s16 y1;

    vt92230 = lbl_80292230;
    zero = 0;
    neg1 = -1;
    y0 = ((Pair *)arg1)->y;
    self = arg0;
    x1 = ((Pair *)arg2)->x;
    x0 = ((Pair *)arg1)->x;
    vt92208 = lbl_80292208;
    *(void **)self = lbl_8028FDB0;
    *(s32 *)((u8 *)self + 4) = zero;
    tmp = self;
    one = lbl_8036B2D8;
    *(void **)self = vt92230;
    *(s16 *)((u8 *)self + 8) = neg1;
    y1 = ((Pair *)arg2)->y;
    *(s16 *)((u8 *)self + 0xA) = x0;
    *(s16 *)((u8 *)self + 0xC) = y0;
    *(s16 *)((u8 *)self + 0xE) = (s16)(x0 + x1);
    *(s16 *)((u8 *)self + 0x10) = (s16)(y0 + y1);
    *(s16 *)((u8 *)self + 0x12) = zero;
    *(s16 *)((u8 *)self + 0x14) = zero;
    *(s16 *)((u8 *)self + 0x16) = x1;
    *(s16 *)((u8 *)self + 0x18) = y1;
    *(s16 *)((u8 *)self + 0x1A) = zero;
    *(s16 *)((u8 *)self + 0x1C) = zero;
    *(u8 *)((u8 *)self + 0x1E) = 0xFF;
    *(u8 *)((u8 *)self + 0x1F) = 0xFF;
    *(u8 *)((u8 *)self + 0x20) = 0xFF;
    *(u8 *)((u8 *)self + 0x21) = 0xFF;
    *(s16 *)((u8 *)self + 0x22) = arg3;
    *(s16 *)((u8 *)self + 0x24) = zero;
    *(f32 *)((u8 *)self + 0x28) = one;
    *(f32 *)((u8 *)self + 0x2C) = one;
    *(f32 *)((u8 *)self + 0x30) = one;
    *(s32 *)((u8 *)self + 0x34) = zero;
    *(s32 *)((u8 *)self + 0x38) = zero;
    *(void **)self = vt92208;
    fn_80142060((u8 *)tmp + 0x3C);
    *(void **)self = gUiUnitPanelMidVtbl;
    *(s32 *)((u8 *)self + 0x48) = 0;
    *(u8 *)((u8 *)self + 0x4C) = 1;
    *(s16 *)((u8 *)self + 0x4E) = 0;
    *(s16 *)((u8 *)self + 0x50) = -1;
    *(s16 *)((u8 *)self + 0x52) = -1;
    *(s16 *)((u8 *)self + 0x54) = 0;
    *(s16 *)((u8 *)self + 0x56) = 1;
    *(f32 *)((u8 *)self + 0x58) = lbl_8036B2E0;
    *(s16 *)((u8 *)self + 0x5C) = 0x18;
    *(s16 *)((u8 *)self + 0x5E) = 0;
    fn_80142060((u8 *)self + 0x68);
    *(s32 *)((u8 *)self + 0x74) = 0;
    *(void **)((u8 *)self + 0x7C) = gEmptyVtbl;
    {
        Sub *sub;
        f32 f1;
        f32 f0;
        f1 = lbl_8036B2D8;
        sub = (Sub *)((u8 *)self + 0x7C);
        *(s32 *)((u8 *)self + 0x80) = 0;
        f0 = lbl_8036B2E0;
        *(s32 *)((u8 *)self + 0x84) = 2;
        *(u8 *)((u8 *)self + 0x88) = 1;
        *(u8 *)((u8 *)self + 0x89) = 1;
        *(s16 *)((u8 *)self + 0x90) = 0;
        *(s16 *)((u8 *)self + 0x92) = 0;
        *(f32 *)((u8 *)self + 0x94) = f1;
        *(f32 *)((u8 *)self + 0x98) = f1;
        *(u8 *)((u8 *)self + 0x9C) = 0xFF;
        *(u8 *)((u8 *)self + 0x9D) = 0xFF;
        *(u8 *)((u8 *)self + 0x9E) = 0xFF;
        *(u8 *)((u8 *)self + 0x9F) = 0xFF;
        *(f32 *)((u8 *)self + 0xA0) = f0;
        sub->v1();
    }
    *(void **)((u8 *)self + 0xA4) = gEmptyVtbl;
    {
        Sub *sub;
        f32 f1;
        f32 f0;
        f1 = lbl_8036B2D8;
        sub = (Sub *)((u8 *)self + 0xA4);
        *(s32 *)((u8 *)self + 0xA8) = 0;
        f0 = lbl_8036B2E0;
        *(s32 *)((u8 *)self + 0xAC) = 3;
        *(u8 *)((u8 *)self + 0xB0) = 1;
        *(u8 *)((u8 *)self + 0xB1) = 1;
        *(s16 *)((u8 *)self + 0xB8) = 0;
        *(s16 *)((u8 *)self + 0xBA) = 0;
        *(f32 *)((u8 *)self + 0xBC) = f1;
        *(f32 *)((u8 *)self + 0xC0) = f1;
        *(u8 *)((u8 *)self + 0xC4) = 0xFF;
        *(u8 *)((u8 *)self + 0xC5) = 0xFF;
        *(u8 *)((u8 *)self + 0xC6) = 0xFF;
        *(u8 *)((u8 *)self + 0xC7) = 0xFF;
        *(f32 *)((u8 *)self + 0xC8) = f0;
        sub->v1();
    }
    ((Obj *)self)->v8();
    return self;
}
#pragma global_optimizer reset
#pragma cplusplus reset

#pragma cplusplus on
#pragma opt_common_subs off
#pragma dont_inline on
#pragma global_optimizer off
#pragma use_lmw_stmw on
extern "C" void *fn_801BEDC4(void *arg0,s32 x,s32 y,s32 id) {
extern u8 lbl_8028FDB0[],lbl_80292230[],gUiGoldCostPanelVtbl[],gEmptyVtbl[],gBattleState[];
extern const f32 lbl_8036B2D8,lbl_8036B2E0;
struct Obj {virtual void v0()=0;virtual void v1()=0;virtual void v2()=0;virtual void v3()=0;virtual void v4()=0;virtual void v5()=0;virtual void v6()=0;virtual void v7()=0;virtual void v8()=0;};
u8 *base; s32 zero; s32 right; s32 bottom; u8 *self; f32 scale; f32 one;
self=(u8 *)arg0;
zero=0;
right=x+0x130;bottom=y+0x90;
base=self;
one=lbl_8036B2D8;scale=lbl_8036B2E0;
*(void **)self=lbl_8028FDB0;
*(s32 *)(base+4)=zero;
*(void **)base=lbl_80292230;
*(s16 *)(base+8)=-1;
*(s16 *)(base+0xA)=x;*(s16 *)(base+0xC)=y;*(s16 *)(base+0xE)=right;*(s16 *)(base+0x10)=bottom;
*(s16 *)(base+0x12)=zero;*(s16 *)(base+0x14)=zero;*(s16 *)(base+0x16)=right-x;*(s16 *)(base+0x18)=0x90;
*(s16 *)(base+0x1A)=zero;*(s16 *)(base+0x1C)=zero;
base[0x1E]=255;base[0x1F]=255;base[0x20]=255;base[0x21]=255;
*(s16 *)(base+0x22)=id;*(s16 *)(base+0x24)=zero;
*(f32 *)(base+0x28)=one;*(f32 *)(base+0x2C)=one;*(f32 *)(base+0x30)=one;
*(s32 *)(base+0x34)=zero;*(s32 *)(base+0x38)=zero;
*(void **)self=gUiGoldCostPanelVtbl;
*(s16 *)(self+0x3C)=*(s32 *)(gBattleState+0x1C);*(s16 *)(self+0x3E)=zero;*(s32 *)(self+0x40)=zero;
*(void **)(self+68)=gEmptyVtbl;
*(s32 *)(self+72)=0;
*(s32 *)(self+76)=2;
self[80]=1;self[81]=1;
*(s16 *)(self+88)=0;*(s16 *)(self+90)=0;
*(f32 *)(self+92)=one;*(f32 *)(self+96)=one;
self[100]=255;self[101]=255;self[102]=255;self[103]=255;
*(f32 *)(self+104)=scale;
((Obj *)(self+68))->v1();
one=lbl_8036B2D8;scale=lbl_8036B2E0;
*(void **)(self+108)=gEmptyVtbl;
*(s32 *)(self+112)=0;
*(s32 *)(self+116)=3;
self[120]=1;self[121]=1;
*(s16 *)(self+128)=0;*(s16 *)(self+130)=0;
*(f32 *)(self+132)=one;*(f32 *)(self+136)=one;
self[140]=255;self[141]=255;self[142]=255;self[143]=255;
*(f32 *)(self+144)=scale;
((Obj *)(self+108))->v1();
((Obj *)self)->v8();return self;
}
#pragma global_optimizer reset
#pragma dont_inline reset
#pragma opt_common_subs reset
#pragma cplusplus reset
void *fn_801BEF90(void *arg0)
{
    typedef struct { u32 size, capacity, data; } LocalString;
    typedef union { u32 word[8]; f32 real[8]; char text[32]; } LocalXmlValue;
    typedef struct {
        u32 allocator[99];
        LocalString name[100];
        LocalXmlValue value[97];
        LocalXmlValue copied;
        u32 padding;
        double conversion;
    } LocalFrame;

    void String_Init(void *, char *, void *);
    void String_ConcatCStr(void *, void *, char *);
    void *Xml_ParseFile(void *, void *, void *);
    void Xml_GetNamedValue(void *, void *, void *);
    void String_Destroy(void *, s32);
    void String_AssignCStr(void *, const void *, s32);
    void Xml_Destroy(void *, s32);
    void *Heap_Alloc(s32);
    s32 strlen(const char *);

    extern char lbl_8027C9F8[];
    extern f32 lbl_8036B2F0;
    extern f32 lbl_8036B2F4;
    extern f32 lbl_8036B2F8;
    extern f32 lbl_8036B2FC;
    extern f32 lbl_8036B300;
    extern f32 lbl_8036B304;

    LocalFrame frame;
    u8 *self = (u8 *)arg0;
    void *allocated;
    void *xml;
    char *str;
    s8 madePath = 0;
    s8 madeName = 0;
    f32 zero = lbl_8036B2F0;

    *(u32 *)(self + 0x0) = 0;
    *(u32 *)(self + 0x4) = 0;
    *(u32 *)(self + 0x8) = 0;
    *(u32 *)(self + 0x4) = 0;
    *(f32 *)(self + 0x14) = zero;
    *(f32 *)(self + 0x10) = zero;
    *(f32 *)(self + 0xC) = zero;
    *(f32 *)(self + 0x20) = zero;
    *(f32 *)(self + 0x1C) = zero;
    *(f32 *)(self + 0x18) = zero;
    *(f32 *)(self + 0x2C) = zero;
    *(f32 *)(self + 0x28) = zero;
    *(f32 *)(self + 0x24) = zero;
    *(f32 *)(self + 0x10C) = zero;
    *(f32 *)(self + 0x108) = zero;
    *(f32 *)(self + 0x104) = zero;
    *(u32 *)(self + 0x19C) = 0;
    *(u32 *)(self + 0x1A0) = 0;
    *(u32 *)(self + 0x1A4) = 0;
    *(u32 *)(self + 0x1A0) = 0;
    *(u32 *)(self + 0x1A8) = 0;
    *(u32 *)(self + 0x1AC) = 0;
    *(u32 *)(self + 0x1B0) = 0;
    *(u32 *)(self + 0x1AC) = 0;

    String_Init(&frame.name[99], lbl_8027C9F8 + 0x8, &frame.allocator[98]);
    allocated = Heap_Alloc(0x60);
    xml = allocated;
    if (allocated != 0) {
        String_Init(&frame.name[98], lbl_8027C9F8 + 0xE, &frame.allocator[97]);
        madeName = 1;
        String_ConcatCStr(&frame.name[97], &frame.name[99], lbl_8027C9F8 + 0x13);
        madePath = 1;
        xml = Xml_ParseFile(allocated, &frame.name[97], &frame.name[98]);
    }
    if (madePath) String_Destroy(&frame.name[97], -1);
    if (madeName) String_Destroy(&frame.name[98], -1);

    /* Attribute +0x1D, XML output at original stack +0x1244. */
    String_Init(&frame.name[96], lbl_8027C9F8 + 0x1D, &frame.allocator[96]);
    Xml_GetNamedValue(&frame.value[96], xml, &frame.name[96]);
    str = frame.value[96].text;
    String_AssignCStr(self, str, strlen(str));
    String_Destroy(&frame.name[96], -1);

    /* Attribute +0x24, XML output at original stack +0x1224. */
    String_Init(&frame.name[95], lbl_8027C9F8 + 0x24, &frame.allocator[95]);
    Xml_GetNamedValue(&frame.value[95], xml, &frame.name[95]);
    frame.copied = frame.value[95];
    String_Destroy(&frame.name[95], -1);
    *(f32 *)(self + 0xC) = frame.copied.real[0];
    *(f32 *)(self + 0x10) = frame.copied.real[1];
    *(f32 *)(self + 0x14) = frame.copied.real[2];

    /* Attribute +0x2D, XML output at original stack +0x1204. */
    String_Init(&frame.name[94], lbl_8027C9F8 + 0x2D, &frame.allocator[94]);
    Xml_GetNamedValue(&frame.value[94], xml, &frame.name[94]);
    frame.copied = frame.value[94];
    String_Destroy(&frame.name[94], -1);
    *(f32 *)(self + 0x18) = frame.copied.real[0];
    *(f32 *)(self + 0x1C) = frame.copied.real[1];
    *(f32 *)(self + 0x20) = frame.copied.real[2];

    /* Attribute +0x36, XML output at original stack +0x11E4. */
    String_Init(&frame.name[93], lbl_8027C9F8 + 0x36, &frame.allocator[93]);
    Xml_GetNamedValue(&frame.value[93], xml, &frame.name[93]);
    frame.copied = frame.value[93];
    String_Destroy(&frame.name[93], -1);
    *(f32 *)(self + 0x24) = frame.copied.real[0];
    *(f32 *)(self + 0x28) = frame.copied.real[1];
    *(f32 *)(self + 0x2C) = frame.copied.real[2];

    /* Attribute +0x3F, XML output at original stack +0x11C4. */
    String_Init(&frame.name[92], lbl_8027C9F8 + 0x3F, &frame.allocator[92]);
    Xml_GetNamedValue(&frame.value[92], xml, &frame.name[92]);
    *(f32 *)(self + 0x30) = frame.value[92].real[0];
    String_Destroy(&frame.name[92], -1);

    /* Attribute +0x4A, XML output at original stack +0x11A4. */
    String_Init(&frame.name[91], lbl_8027C9F8 + 0x4A, &frame.allocator[91]);
    Xml_GetNamedValue(&frame.value[91], xml, &frame.name[91]);
    *(u32 *)(self + 0x34) = frame.value[91].word[0];
    String_Destroy(&frame.name[91], -1);

    /* Attribute +0x53, XML output at original stack +0x1184. */
    String_Init(&frame.name[90], lbl_8027C9F8 + 0x53, &frame.allocator[90]);
    Xml_GetNamedValue(&frame.value[90], xml, &frame.name[90]);
    *(u32 *)(self + 0x38) = frame.value[90].word[0];
    String_Destroy(&frame.name[90], -1);

    /* Attribute +0x5B, XML output at original stack +0x1164. */
    String_Init(&frame.name[89], lbl_8027C9F8 + 0x5B, &frame.allocator[89]);
    Xml_GetNamedValue(&frame.value[89], xml, &frame.name[89]);
    *(u32 *)(self + 0x3C) = frame.value[89].word[0];
    String_Destroy(&frame.name[89], -1);

    /* Attribute +0x64, XML output at original stack +0x1144. */
    String_Init(&frame.name[88], lbl_8027C9F8 + 0x64, &frame.allocator[88]);
    Xml_GetNamedValue(&frame.value[88], xml, &frame.name[88]);
    *(u32 *)(self + 0x40) = frame.value[88].word[0];
    String_Destroy(&frame.name[88], -1);

    /* Attribute +0x6D, XML output at original stack +0x1124. */
    String_Init(&frame.name[87], lbl_8027C9F8 + 0x6D, &frame.allocator[87]);
    Xml_GetNamedValue(&frame.value[87], xml, &frame.name[87]);
    *(u32 *)(self + 0x44) = frame.value[87].word[0];
    String_Destroy(&frame.name[87], -1);

    /* Attribute +0x76, XML output at original stack +0x1104. */
    String_Init(&frame.name[86], lbl_8027C9F8 + 0x76, &frame.allocator[86]);
    Xml_GetNamedValue(&frame.value[86], xml, &frame.name[86]);
    *(u32 *)(self + 0x48) = frame.value[86].word[0];
    String_Destroy(&frame.name[86], -1);

    /* Attribute +0x80, XML output at original stack +0x10E4. */
    String_Init(&frame.name[85], lbl_8027C9F8 + 0x80, &frame.allocator[85]);
    Xml_GetNamedValue(&frame.value[85], xml, &frame.name[85]);
    *(u32 *)(self + 0x4C) = frame.value[85].word[0];
    String_Destroy(&frame.name[85], -1);

    /* Attribute +0x8B, XML output at original stack +0x10C4. */
    String_Init(&frame.name[84], lbl_8027C9F8 + 0x8B, &frame.allocator[84]);
    Xml_GetNamedValue(&frame.value[84], xml, &frame.name[84]);
    *(u32 *)(self + 0x50) = frame.value[84].word[0];
    String_Destroy(&frame.name[84], -1);

    /* Attribute +0x96, XML output at original stack +0x10A4. */
    String_Init(&frame.name[83], lbl_8027C9F8 + 0x96, &frame.allocator[83]);
    Xml_GetNamedValue(&frame.value[83], xml, &frame.name[83]);
    *(u32 *)(self + 0x54) = frame.value[83].word[0];
    String_Destroy(&frame.name[83], -1);

    /* Attribute +0xA1, XML output at original stack +0x1084. */
    String_Init(&frame.name[82], lbl_8027C9F8 + 0xA1, &frame.allocator[82]);
    Xml_GetNamedValue(&frame.value[82], xml, &frame.name[82]);
    *(u32 *)(self + 0x58) = frame.value[82].word[0];
    String_Destroy(&frame.name[82], -1);

    /* Attribute +0xAA, XML output at original stack +0x1064. */
    String_Init(&frame.name[81], lbl_8027C9F8 + 0xAA, &frame.allocator[81]);
    Xml_GetNamedValue(&frame.value[81], xml, &frame.name[81]);
    *(u32 *)(self + 0x5C) = frame.value[81].word[0];
    String_Destroy(&frame.name[81], -1);

    /* Attribute +0xB4, XML output at original stack +0x1044. */
    String_Init(&frame.name[80], lbl_8027C9F8 + 0xB4, &frame.allocator[80]);
    Xml_GetNamedValue(&frame.value[80], xml, &frame.name[80]);
    *(f32 *)(self + 0x60) = frame.value[80].real[0];
    String_Destroy(&frame.name[80], -1);

    /* Attribute +0xC4, XML output at original stack +0x1024. */
    String_Init(&frame.name[79], lbl_8027C9F8 + 0xC4, &frame.allocator[79]);
    Xml_GetNamedValue(&frame.value[79], xml, &frame.name[79]);
    *(f32 *)(self + 0x64) = frame.value[79].real[0];
    String_Destroy(&frame.name[79], -1);

    /* Attribute +0xD3, XML output at original stack +0x1004. */
    String_Init(&frame.name[78], lbl_8027C9F8 + 0xD3, &frame.allocator[78]);
    Xml_GetNamedValue(&frame.value[78], xml, &frame.name[78]);
    *(f32 *)(self + 0x68) = frame.value[78].real[0];
    String_Destroy(&frame.name[78], -1);

    /* Attribute +0xE2, XML output at original stack +0xFE4. */
    String_Init(&frame.name[77], lbl_8027C9F8 + 0xE2, &frame.allocator[77]);
    Xml_GetNamedValue(&frame.value[77], xml, &frame.name[77]);
    *(f32 *)(self + 0x6C) = frame.value[77].real[0];
    String_Destroy(&frame.name[77], -1);

    /* Attribute +0xF0, XML output at original stack +0xFC4. */
    String_Init(&frame.name[76], lbl_8027C9F8 + 0xF0, &frame.allocator[76]);
    Xml_GetNamedValue(&frame.value[76], xml, &frame.name[76]);
    *(f32 *)(self + 0x70) = frame.value[76].real[0];
    String_Destroy(&frame.name[76], -1);

    /* Attribute +0xFC, XML output at original stack +0xFA4. */
    String_Init(&frame.name[75], lbl_8027C9F8 + 0xFC, &frame.allocator[75]);
    Xml_GetNamedValue(&frame.value[75], xml, &frame.name[75]);
    *(f32 *)(self + 0x74) = frame.value[75].real[0];
    String_Destroy(&frame.name[75], -1);

    /* Attribute +0x107, XML output at original stack +0xF84. */
    String_Init(&frame.name[74], lbl_8027C9F8 + 0x107, &frame.allocator[74]);
    Xml_GetNamedValue(&frame.value[74], xml, &frame.name[74]);
    *(u32 *)(self + 0x78) = frame.value[74].word[0];
    String_Destroy(&frame.name[74], -1);

    /* Attribute +0x112, XML output at original stack +0xF64. */
    String_Init(&frame.name[73], lbl_8027C9F8 + 0x112, &frame.allocator[73]);
    Xml_GetNamedValue(&frame.value[73], xml, &frame.name[73]);
    *(u32 *)(self + 0x7C) = frame.value[73].word[0];
    String_Destroy(&frame.name[73], -1);

    /* Attribute +0x11A, XML output at original stack +0xF44. */
    String_Init(&frame.name[72], lbl_8027C9F8 + 0x11A, &frame.allocator[72]);
    Xml_GetNamedValue(&frame.value[72], xml, &frame.name[72]);
    *(f32 *)(self + 0x80) = frame.value[72].real[0];
    String_Destroy(&frame.name[72], -1);

    /* Attribute +0x126, XML output at original stack +0xF24. */
    String_Init(&frame.name[71], lbl_8027C9F8 + 0x126, &frame.allocator[71]);
    Xml_GetNamedValue(&frame.value[71], xml, &frame.name[71]);
    *(f32 *)(self + 0x84) = frame.value[71].real[0];
    String_Destroy(&frame.name[71], -1);

    /* Attribute +0x130, XML output at original stack +0xF04. */
    String_Init(&frame.name[70], lbl_8027C9F8 + 0x130, &frame.allocator[70]);
    Xml_GetNamedValue(&frame.value[70], xml, &frame.name[70]);
    *(f32 *)(self + 0x88) = frame.value[70].real[0];
    String_Destroy(&frame.name[70], -1);

    /* Attribute +0x13B, XML output at original stack +0xEE4. */
    String_Init(&frame.name[69], lbl_8027C9F8 + 0x13B, &frame.allocator[69]);
    Xml_GetNamedValue(&frame.value[69], xml, &frame.name[69]);
    *(f32 *)(self + 0x8C) = frame.value[69].real[0];
    String_Destroy(&frame.name[69], -1);

    /* Attribute +0x146, XML output at original stack +0xEC4. */
    String_Init(&frame.name[68], lbl_8027C9F8 + 0x146, &frame.allocator[68]);
    Xml_GetNamedValue(&frame.value[68], xml, &frame.name[68]);
    *(f32 *)(self + 0x90) = frame.value[68].real[0];
    String_Destroy(&frame.name[68], -1);

    /* Attribute +0x151, XML output at original stack +0xEA4. */
    String_Init(&frame.name[67], lbl_8027C9F8 + 0x151, &frame.allocator[67]);
    Xml_GetNamedValue(&frame.value[67], xml, &frame.name[67]);
    *(f32 *)(self + 0x94) = frame.value[67].real[0];
    String_Destroy(&frame.name[67], -1);

    /* Attribute +0x15E, XML output at original stack +0xE84. */
    String_Init(&frame.name[66], lbl_8027C9F8 + 0x15E, &frame.allocator[66]);
    Xml_GetNamedValue(&frame.value[66], xml, &frame.name[66]);
    *(f32 *)(self + 0x98) = frame.value[66].real[0];
    String_Destroy(&frame.name[66], -1);

    /* Attribute +0x164, XML output at original stack +0xE64. */
    String_Init(&frame.name[65], lbl_8027C9F8 + 0x164, &frame.allocator[65]);
    Xml_GetNamedValue(&frame.value[65], xml, &frame.name[65]);
    *(f32 *)(self + 0x9C) = frame.value[65].real[0];
    String_Destroy(&frame.name[65], -1);

    /* Attribute +0x16E, XML output at original stack +0xE44. */
    String_Init(&frame.name[64], lbl_8027C9F8 + 0x16E, &frame.allocator[64]);
    Xml_GetNamedValue(&frame.value[64], xml, &frame.name[64]);
    *(f32 *)(self + 0xA0) = frame.value[64].real[0];
    String_Destroy(&frame.name[64], -1);

    /* Attribute +0x178, XML output at original stack +0xE24. */
    String_Init(&frame.name[63], lbl_8027C9F8 + 0x178, &frame.allocator[63]);
    Xml_GetNamedValue(&frame.value[63], xml, &frame.name[63]);
    *(f32 *)(self + 0xA4) = frame.value[63].real[0];
    String_Destroy(&frame.name[63], -1);

    /* Attribute +0x185, XML output at original stack +0xE04. */
    String_Init(&frame.name[62], lbl_8027C9F8 + 0x185, &frame.allocator[62]);
    Xml_GetNamedValue(&frame.value[62], xml, &frame.name[62]);
    *(f32 *)(self + 0xA8) = frame.value[62].real[0];
    String_Destroy(&frame.name[62], -1);

    /* Attribute +0x192, XML output at original stack +0xDE4. */
    String_Init(&frame.name[61], lbl_8027C9F8 + 0x192, &frame.allocator[61]);
    Xml_GetNamedValue(&frame.value[61], xml, &frame.name[61]);
    *(f32 *)(self + 0xAC) = frame.value[61].real[0];
    String_Destroy(&frame.name[61], -1);

    /* Attribute +0x19F, XML output at original stack +0xDC4. */
    String_Init(&frame.name[60], lbl_8027C9F8 + 0x19F, &frame.allocator[60]);
    Xml_GetNamedValue(&frame.value[60], xml, &frame.name[60]);
    *(f32 *)(self + 0xB0) = frame.value[60].real[0];
    String_Destroy(&frame.name[60], -1);

    /* Attribute +0x1AB, XML output at original stack +0xDA4. */
    String_Init(&frame.name[59], lbl_8027C9F8 + 0x1AB, &frame.allocator[59]);
    Xml_GetNamedValue(&frame.value[59], xml, &frame.name[59]);
    *(f32 *)(self + 0xB4) = frame.value[59].real[0];
    String_Destroy(&frame.name[59], -1);

    /* Attribute +0x1B7, XML output at original stack +0xD84. */
    String_Init(&frame.name[58], lbl_8027C9F8 + 0x1B7, &frame.allocator[58]);
    Xml_GetNamedValue(&frame.value[58], xml, &frame.name[58]);
    *(u32 *)(self + 0xB8) = frame.value[58].word[0];
    String_Destroy(&frame.name[58], -1);

    /* Attribute +0x1C3, XML output at original stack +0xD64. */
    String_Init(&frame.name[57], lbl_8027C9F8 + 0x1C3, &frame.allocator[57]);
    Xml_GetNamedValue(&frame.value[57], xml, &frame.name[57]);
    *(f32 *)(self + 0xBC) = frame.value[57].real[0];
    String_Destroy(&frame.name[57], -1);

    /* Attribute +0x1D3, XML output at original stack +0xD44. */
    String_Init(&frame.name[56], lbl_8027C9F8 + 0x1D3, &frame.allocator[56]);
    Xml_GetNamedValue(&frame.value[56], xml, &frame.name[56]);
    *(f32 *)(self + 0xC0) = frame.value[56].real[0];
    String_Destroy(&frame.name[56], -1);

    /* Attribute +0x1E3, XML output at original stack +0xD24. */
    String_Init(&frame.name[55], lbl_8027C9F8 + 0x1E3, &frame.allocator[55]);
    Xml_GetNamedValue(&frame.value[55], xml, &frame.name[55]);
    *(u32 *)(self + 0xC4) = frame.value[55].word[0];
    String_Destroy(&frame.name[55], -1);

    /* Attribute +0x1F3, XML output at original stack +0xD04. */
    String_Init(&frame.name[54], lbl_8027C9F8 + 0x1F3, &frame.allocator[54]);
    Xml_GetNamedValue(&frame.value[54], xml, &frame.name[54]);
    *(f32 *)(self + 0xC8) = frame.value[54].real[0];
    String_Destroy(&frame.name[54], -1);

    /* Attribute +0x201, XML output at original stack +0xCE4. */
    String_Init(&frame.name[53], lbl_8027C9F8 + 0x201, &frame.allocator[53]);
    Xml_GetNamedValue(&frame.value[53], xml, &frame.name[53]);
    *(f32 *)(self + 0xCC) = frame.value[53].real[0];
    String_Destroy(&frame.name[53], -1);

    /* Attribute +0x20F, XML output at original stack +0xCC4. */
    String_Init(&frame.name[52], lbl_8027C9F8 + 0x20F, &frame.allocator[52]);
    Xml_GetNamedValue(&frame.value[52], xml, &frame.name[52]);
    *(u32 *)(self + 0xD0) = frame.value[52].word[0];
    String_Destroy(&frame.name[52], -1);

    /* Attribute +0x21D, XML output at original stack +0xCA4. */
    String_Init(&frame.name[51], lbl_8027C9F8 + 0x21D, &frame.allocator[51]);
    Xml_GetNamedValue(&frame.value[51], xml, &frame.name[51]);
    *(f32 *)(self + 0xD4) = frame.value[51].real[0];
    String_Destroy(&frame.name[51], -1);

    /* Attribute +0x22B, XML output at original stack +0xC84. */
    String_Init(&frame.name[50], lbl_8027C9F8 + 0x22B, &frame.allocator[50]);
    Xml_GetNamedValue(&frame.value[50], xml, &frame.name[50]);
    *(f32 *)(self + 0xD8) = frame.value[50].real[0];
    String_Destroy(&frame.name[50], -1);

    /* Attribute +0x234, XML output at original stack +0xC64. */
    String_Init(&frame.name[49], lbl_8027C9F8 + 0x234, &frame.allocator[49]);
    Xml_GetNamedValue(&frame.value[49], xml, &frame.name[49]);
    *(f32 *)(self + 0xDC) = frame.value[49].real[0];
    String_Destroy(&frame.name[49], -1);

    /* Attribute +0x244, XML output at original stack +0xC44. */
    String_Init(&frame.name[48], lbl_8027C9F8 + 0x244, &frame.allocator[48]);
    Xml_GetNamedValue(&frame.value[48], xml, &frame.name[48]);
    *(f32 *)(self + 0xE0) = frame.value[48].real[0];
    String_Destroy(&frame.name[48], -1);

    /* Attribute +0x24F, XML output at original stack +0xC24. */
    String_Init(&frame.name[47], lbl_8027C9F8 + 0x24F, &frame.allocator[47]);
    Xml_GetNamedValue(&frame.value[47], xml, &frame.name[47]);
    *(f32 *)(self + 0xE4) = frame.value[47].real[0];
    String_Destroy(&frame.name[47], -1);

    /* Attribute +0x25A, XML output at original stack +0xC04. */
    String_Init(&frame.name[46], lbl_8027C9F8 + 0x25A, &frame.allocator[46]);
    Xml_GetNamedValue(&frame.value[46], xml, &frame.name[46]);
    *(u32 *)(self + 0xE8) = frame.value[46].word[0];
    String_Destroy(&frame.name[46], -1);

    /* Attribute +0x268, XML output at original stack +0xBE4. */
    String_Init(&frame.name[45], lbl_8027C9F8 + 0x268, &frame.allocator[45]);
    Xml_GetNamedValue(&frame.value[45], xml, &frame.name[45]);
    *(f32 *)(self + 0xEC) = frame.value[45].real[0];
    String_Destroy(&frame.name[45], -1);

    /* Attribute +0x273, XML output at original stack +0xBC4. */
    String_Init(&frame.name[44], lbl_8027C9F8 + 0x273, &frame.allocator[44]);
    Xml_GetNamedValue(&frame.value[44], xml, &frame.name[44]);
    *(f32 *)(self + 0xF0) = frame.value[44].real[0];
    String_Destroy(&frame.name[44], -1);

    /* Attribute +0x281, XML output at original stack +0xBA4. */
    String_Init(&frame.name[43], lbl_8027C9F8 + 0x281, &frame.allocator[43]);
    Xml_GetNamedValue(&frame.value[43], xml, &frame.name[43]);
    *(f32 *)(self + 0xF4) = frame.value[43].real[0];
    String_Destroy(&frame.name[43], -1);

    /* Attribute +0x290, XML output at original stack +0xB84. */
    String_Init(&frame.name[42], lbl_8027C9F8 + 0x290, &frame.allocator[42]);
    Xml_GetNamedValue(&frame.value[42], xml, &frame.name[42]);
    *(f32 *)(self + 0xF8) = frame.value[42].real[0];
    String_Destroy(&frame.name[42], -1);

    /* Attribute +0x29F, XML output at original stack +0xB64. */
    String_Init(&frame.name[41], lbl_8027C9F8 + 0x29F, &frame.allocator[41]);
    Xml_GetNamedValue(&frame.value[41], xml, &frame.name[41]);
    *(u32 *)(self + 0xFC) = frame.value[41].word[0];
    String_Destroy(&frame.name[41], -1);

    /* Attribute +0x2AF, XML output at original stack +0xB44. */
    String_Init(&frame.name[40], lbl_8027C9F8 + 0x2AF, &frame.allocator[40]);
    Xml_GetNamedValue(&frame.value[40], xml, &frame.name[40]);
    *(f32 *)(self + 0x100) = frame.value[40].real[0];
    String_Destroy(&frame.name[40], -1);

    /* Attribute +0x2BA, XML output at original stack +0xB24. */
    String_Init(&frame.name[39], lbl_8027C9F8 + 0x2BA, &frame.allocator[39]);
    Xml_GetNamedValue(&frame.value[39], xml, &frame.name[39]);
    frame.copied = frame.value[39];
    String_Destroy(&frame.name[39], -1);
    *(f32 *)(self + 0x104) = frame.copied.real[0];
    *(f32 *)(self + 0x108) = frame.copied.real[1];
    *(f32 *)(self + 0x10C) = frame.copied.real[2];

    /* Attribute +0x2C7, XML output at original stack +0xB04. */
    String_Init(&frame.name[38], lbl_8027C9F8 + 0x2C7, &frame.allocator[38]);
    Xml_GetNamedValue(&frame.value[38], xml, &frame.name[38]);
    *(f32 *)(self + 0x110) = frame.value[38].real[0];
    String_Destroy(&frame.name[38], -1);

    /* Attribute +0x2D2, XML output at original stack +0xAE4. */
    String_Init(&frame.name[37], lbl_8027C9F8 + 0x2D2, &frame.allocator[37]);
    Xml_GetNamedValue(&frame.value[37], xml, &frame.name[37]);
    *(f32 *)(self + 0x114) = frame.value[37].real[0];
    String_Destroy(&frame.name[37], -1);

    /* Attribute +0x2DD, XML output at original stack +0xAC4. */
    String_Init(&frame.name[36], lbl_8027C9F8 + 0x2DD, &frame.allocator[36]);
    Xml_GetNamedValue(&frame.value[36], xml, &frame.name[36]);
    *(f32 *)(self + 0x118) = frame.value[36].real[0];
    String_Destroy(&frame.name[36], -1);

    /* Attribute +0x2E9, XML output at original stack +0xAA4. */
    String_Init(&frame.name[35], lbl_8027C9F8 + 0x2E9, &frame.allocator[35]);
    Xml_GetNamedValue(&frame.value[35], xml, &frame.name[35]);
    *(f32 *)(self + 0x11C) = frame.value[35].real[0];
    String_Destroy(&frame.name[35], -1);

    /* Attribute +0x2F6, XML output at original stack +0xA84. */
    String_Init(&frame.name[34], lbl_8027C9F8 + 0x2F6, &frame.allocator[34]);
    Xml_GetNamedValue(&frame.value[34], xml, &frame.name[34]);
    *(f32 *)(self + 0x120) = frame.value[34].real[0];
    String_Destroy(&frame.name[34], -1);

    /* Attribute +0x301, XML output at original stack +0xA64. */
    String_Init(&frame.name[33], lbl_8027C9F8 + 0x301, &frame.allocator[33]);
    Xml_GetNamedValue(&frame.value[33], xml, &frame.name[33]);
    *(f32 *)(self + 0x124) = frame.value[33].real[0];
    String_Destroy(&frame.name[33], -1);

    /* Attribute +0x30E, XML output at original stack +0xA44. */
    String_Init(&frame.name[32], lbl_8027C9F8 + 0x30E, &frame.allocator[32]);
    Xml_GetNamedValue(&frame.value[32], xml, &frame.name[32]);
    *(f32 *)(self + 0x128) = frame.value[32].real[0];
    String_Destroy(&frame.name[32], -1);

    /* Attribute +0x317, XML output at original stack +0xA24. */
    String_Init(&frame.name[31], lbl_8027C9F8 + 0x317, &frame.allocator[31]);
    Xml_GetNamedValue(&frame.value[31], xml, &frame.name[31]);
    *(f32 *)(self + 0x12C) = frame.value[31].real[0];
    String_Destroy(&frame.name[31], -1);

    /* Attribute +0x321, XML output at original stack +0xA04. */
    String_Init(&frame.name[30], lbl_8027C9F8 + 0x321, &frame.allocator[30]);
    Xml_GetNamedValue(&frame.value[30], xml, &frame.name[30]);
    *(f32 *)(self + 0x130) = frame.value[30].real[0];
    String_Destroy(&frame.name[30], -1);

    /* Attribute +0x32D, XML output at original stack +0x9E4. */
    String_Init(&frame.name[29], lbl_8027C9F8 + 0x32D, &frame.allocator[29]);
    Xml_GetNamedValue(&frame.value[29], xml, &frame.name[29]);
    *(f32 *)(self + 0x134) = frame.value[29].real[0];
    String_Destroy(&frame.name[29], -1);

    /* Attribute +0x339, XML output at original stack +0x9C4. */
    String_Init(&frame.name[28], lbl_8027C9F8 + 0x339, &frame.allocator[28]);
    Xml_GetNamedValue(&frame.value[28], xml, &frame.name[28]);
    *(f32 *)(self + 0x138) = frame.value[28].real[0];
    String_Destroy(&frame.name[28], -1);

    /* Attribute +0x341, XML output at original stack +0x9A4. */
    String_Init(&frame.name[27], lbl_8027C9F8 + 0x341, &frame.allocator[27]);
    Xml_GetNamedValue(&frame.value[27], xml, &frame.name[27]);
    *(f32 *)(self + 0x13C) = frame.value[27].real[0];
    String_Destroy(&frame.name[27], -1);

    /* Attribute +0x34C, XML output at original stack +0x984. */
    String_Init(&frame.name[26], lbl_8027C9F8 + 0x34C, &frame.allocator[26]);
    Xml_GetNamedValue(&frame.value[26], xml, &frame.name[26]);
    *(f32 *)(self + 0x140) = frame.value[26].real[0];
    String_Destroy(&frame.name[26], -1);

    /* Attribute +0x357, XML output at original stack +0x964. */
    String_Init(&frame.name[25], lbl_8027C9F8 + 0x357, &frame.allocator[25]);
    Xml_GetNamedValue(&frame.value[25], xml, &frame.name[25]);
    *(f32 *)(self + 0x144) = frame.value[25].real[0];
    String_Destroy(&frame.name[25], -1);

    /* Attribute +0x367, XML output at original stack +0x944. */
    String_Init(&frame.name[24], lbl_8027C9F8 + 0x367, &frame.allocator[24]);
    Xml_GetNamedValue(&frame.value[24], xml, &frame.name[24]);
    *(f32 *)(self + 0x148) = (f32)(s32)frame.value[24].word[0];
    String_Destroy(&frame.name[24], -1);

    /* Attribute +0x373, XML output at original stack +0x924. */
    String_Init(&frame.name[23], lbl_8027C9F8 + 0x373, &frame.allocator[23]);
    Xml_GetNamedValue(&frame.value[23], xml, &frame.name[23]);
    *(f32 *)(self + 0x14C) = frame.value[23].real[0];
    String_Destroy(&frame.name[23], -1);

    /* Attribute +0x37F, XML output at original stack +0x904. */
    String_Init(&frame.name[22], lbl_8027C9F8 + 0x37F, &frame.allocator[22]);
    Xml_GetNamedValue(&frame.value[22], xml, &frame.name[22]);
    *(f32 *)(self + 0x150) = frame.value[22].real[0];
    String_Destroy(&frame.name[22], -1);

    /* Attribute +0x38B, XML output at original stack +0x8E4. */
    String_Init(&frame.name[21], lbl_8027C9F8 + 0x38B, &frame.allocator[21]);
    Xml_GetNamedValue(&frame.value[21], xml, &frame.name[21]);
    *(f32 *)(self + 0x154) = frame.value[21].real[0];
    String_Destroy(&frame.name[21], -1);

    /* Attribute +0x394, XML output at original stack +0x8C4. */
    String_Init(&frame.name[20], lbl_8027C9F8 + 0x394, &frame.allocator[20]);
    Xml_GetNamedValue(&frame.value[20], xml, &frame.name[20]);
    *(f32 *)(self + 0x158) = frame.value[20].real[0];
    String_Destroy(&frame.name[20], -1);
    if (*(f32 *)(self + 0x158) == zero)
        *(f32 *)(self + 0x158) = lbl_8036B2F4;

    /* Attribute +0x39E, XML output at original stack +0x8A4. */
    String_Init(&frame.name[19], lbl_8027C9F8 + 0x39E, &frame.allocator[19]);
    Xml_GetNamedValue(&frame.value[19], xml, &frame.name[19]);
    *(f32 *)(self + 0x15C) = frame.value[19].real[0];
    String_Destroy(&frame.name[19], -1);
    if (*(f32 *)(self + 0x15C) == zero)
        *(f32 *)(self + 0x15C) = lbl_8036B2F8;

    /* Attribute +0x3A9, XML output at original stack +0x884. */
    String_Init(&frame.name[18], lbl_8027C9F8 + 0x3A9, &frame.allocator[18]);
    Xml_GetNamedValue(&frame.value[18], xml, &frame.name[18]);
    *(f32 *)(self + 0x164) = frame.value[18].real[0];
    String_Destroy(&frame.name[18], -1);

    /* Attribute +0x3B6, XML output at original stack +0x864. */
    String_Init(&frame.name[17], lbl_8027C9F8 + 0x3B6, &frame.allocator[17]);
    Xml_GetNamedValue(&frame.value[17], xml, &frame.name[17]);
    *(u32 *)(self + 0x168) = frame.value[17].word[0];
    String_Destroy(&frame.name[17], -1);

    /* Attribute +0x3C4, XML output at original stack +0x844. */
    String_Init(&frame.name[16], lbl_8027C9F8 + 0x3C4, &frame.allocator[16]);
    Xml_GetNamedValue(&frame.value[16], xml, &frame.name[16]);
    *(u32 *)(self + 0x16C) = frame.value[16].word[0];
    String_Destroy(&frame.name[16], -1);

    /* Attribute +0x3D4, XML output at original stack +0x824. */
    String_Init(&frame.name[15], lbl_8027C9F8 + 0x3D4, &frame.allocator[15]);
    Xml_GetNamedValue(&frame.value[15], xml, &frame.name[15]);
    *(u32 *)(self + 0x170) = frame.value[15].word[0];
    String_Destroy(&frame.name[15], -1);

    /* Attribute +0x3E7, XML output at original stack +0x804. */
    String_Init(&frame.name[14], lbl_8027C9F8 + 0x3E7, &frame.allocator[14]);
    Xml_GetNamedValue(&frame.value[14], xml, &frame.name[14]);
    *(u32 *)(self + 0x174) = frame.value[14].word[0];
    String_Destroy(&frame.name[14], -1);

    /* Attribute +0x3F7, XML output at original stack +0x7E4. */
    String_Init(&frame.name[13], lbl_8027C9F8 + 0x3F7, &frame.allocator[13]);
    Xml_GetNamedValue(&frame.value[13], xml, &frame.name[13]);
    *(u32 *)(self + 0x178) = frame.value[13].word[0];
    String_Destroy(&frame.name[13], -1);

    /* Attribute +0x40A, XML output at original stack +0x7C4. */
    String_Init(&frame.name[12], lbl_8027C9F8 + 0x40A, &frame.allocator[12]);
    Xml_GetNamedValue(&frame.value[12], xml, &frame.name[12]);
    *(f32 *)(self + 0x17C) = frame.value[12].real[0];
    String_Destroy(&frame.name[12], -1);

    /* Attribute +0x416, XML output at original stack +0x7A4. */
    String_Init(&frame.name[11], lbl_8027C9F8 + 0x416, &frame.allocator[11]);
    Xml_GetNamedValue(&frame.value[11], xml, &frame.name[11]);
    *(u32 *)(self + 0x180) = frame.value[11].word[0];
    String_Destroy(&frame.name[11], -1);

    /* Attribute +0x420, XML output at original stack +0x784. */
    String_Init(&frame.name[10], lbl_8027C9F8 + 0x420, &frame.allocator[10]);
    Xml_GetNamedValue(&frame.value[10], xml, &frame.name[10]);
    *(u32 *)(self + 0x184) = frame.value[10].word[0];
    String_Destroy(&frame.name[10], -1);

    /* Attribute +0x42F, XML output at original stack +0x764. */
    String_Init(&frame.name[9], lbl_8027C9F8 + 0x42F, &frame.allocator[9]);
    Xml_GetNamedValue(&frame.value[9], xml, &frame.name[9]);
    *(u32 *)(self + 0x188) = frame.value[9].word[0];
    String_Destroy(&frame.name[9], -1);

    /* Attribute +0x43C, XML output at original stack +0x744. */
    String_Init(&frame.name[8], lbl_8027C9F8 + 0x43C, &frame.allocator[8]);
    Xml_GetNamedValue(&frame.value[8], xml, &frame.name[8]);
    *(u32 *)(self + 0x18C) = frame.value[8].word[0];
    String_Destroy(&frame.name[8], -1);

    /* Attribute +0x446, XML output at original stack +0x724. */
    String_Init(&frame.name[7], lbl_8027C9F8 + 0x446, &frame.allocator[7]);
    Xml_GetNamedValue(&frame.value[7], xml, &frame.name[7]);
    *(u32 *)(self + 0x190) = frame.value[7].word[0];
    String_Destroy(&frame.name[7], -1);

    /* Attribute +0x454, XML output at original stack +0x704. */
    String_Init(&frame.name[6], lbl_8027C9F8 + 0x454, &frame.allocator[6]);
    Xml_GetNamedValue(&frame.value[6], xml, &frame.name[6]);
    *(u32 *)(self + 0x194) = frame.value[6].word[0];
    String_Destroy(&frame.name[6], -1);

    /* Attribute +0x45E, XML output at original stack +0x6E4. */
    String_Init(&frame.name[5], lbl_8027C9F8 + 0x45E, &frame.allocator[5]);
    Xml_GetNamedValue(&frame.value[5], xml, &frame.name[5]);
    str = frame.value[5].text;
    String_AssignCStr(self + 0x19C, str, strlen(str));
    String_Destroy(&frame.name[5], -1);

    /* Attribute +0x46A, XML output at original stack +0x6C4. */
    String_Init(&frame.name[4], lbl_8027C9F8 + 0x46A, &frame.allocator[4]);
    Xml_GetNamedValue(&frame.value[4], xml, &frame.name[4]);
    *(u32 *)(self + 0x1B4) = frame.value[4].word[0];
    String_Destroy(&frame.name[4], -1);

    /* Attribute +0x477, XML output at original stack +0x6A4. */
    String_Init(&frame.name[3], lbl_8027C9F8 + 0x477, &frame.allocator[3]);
    Xml_GetNamedValue(&frame.value[3], xml, &frame.name[3]);
    *(u32 *)(self + 0x1B8) = frame.value[3].word[0];
    String_Destroy(&frame.name[3], -1);

    /* Attribute +0x484, XML output at original stack +0x684. */
    String_Init(&frame.name[2], lbl_8027C9F8 + 0x484, &frame.allocator[2]);
    Xml_GetNamedValue(&frame.value[2], xml, &frame.name[2]);
    *(f32 *)(self + 0x1BC) = frame.value[2].real[0];
    String_Destroy(&frame.name[2], -1);
    if (*(f32 *)(self + 0x1BC) == zero)
        *(f32 *)(self + 0x1BC) = lbl_8036B2FC;

    /* Attribute +0x48F, XML output at original stack +0x664. */
    String_Init(&frame.name[1], lbl_8027C9F8 + 0x48F, &frame.allocator[1]);
    Xml_GetNamedValue(&frame.value[1], xml, &frame.name[1]);
    *(f32 *)(self + 0x1C0) = frame.value[1].real[0];
    String_Destroy(&frame.name[1], -1);
    if (*(f32 *)(self + 0x1C0) == zero)
        *(f32 *)(self + 0x1C0) = lbl_8036B300;

    /* Attribute +0x49A, XML output at original stack +0x644. */
    String_Init(&frame.name[0], lbl_8027C9F8 + 0x49A, &frame.allocator[0]);
    Xml_GetNamedValue(&frame.value[0], xml, &frame.name[0]);
    *(f32 *)(self + 0x1C4) = frame.value[0].real[0];
    String_Destroy(&frame.name[0], -1);
    if (*(f32 *)(self + 0x1C4) == zero)
        *(f32 *)(self + 0x1C4) = lbl_8036B304;

    Xml_Destroy(xml, 1);
    String_Destroy(&frame.name[99], -1);
    return self;
}

void fn_801C09B0(void *arg0) {
    s32 temp_r31;

    temp_r31 = Ui_FindChild(arg0, 0x81, 0);
    fn_8016A57C(*(s32 *)((char *)arg0 + 0x18));
    fn_8013FEE0();
    if (*(u32 *)((char *)temp_r31 + 0x6C) == 0) {
        Process_Goto(arg0, 6);
    }
    fn_8014876C(gFxChannels, 0x64, 0x2EE);
}

void fn_801C0A28(void *arg0) {
    s32 temp_r31;

    temp_r31 = Ui_FindChild(arg0, 0x81, 0);
    fn_8016A5AC(*(s32 *)((char *)arg0 + 0x18));
    fn_8013FEF0();
    fn_8014876C(gFxChannels, 0x46, 0x2EE);
    Event_StartTalkByIndex(fn_801D2AAC(temp_r31), arg0);
}

void fn_801C0A9C(void *arg0) {
    extern u8 gUiContext[];
    switch ((s32)gUiContext[8]) {
    case 0x80:
        break;
    case 0x81:
        Process_Goto(arg0, 4);
        break;
    }
}

void fn_801C0ADC(void *arg0) {
    void *Ui_FindChild(void *, s32, s32);
    void Ui_SetWidgetText(void *, void *);
    void *fn_8013BC10(s32, s32);
    void Ui_CreateMenu(void *, void *, s32);
    void fn_8000D864(s32, s32);
    s32 fn_801D2B04(void *);
    void *Msg_Expand(void *);
    extern u8 gUiScrollListStrings[];
#pragma cplusplus on
    struct Item {
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
        virtual void set2(s32) = 0;
        virtual void v19() = 0;
        virtual void set3(s32) = 0;
    };
    struct Base {
        u32 unknown;
    };
    struct Menu : Base {
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
        virtual Item *get(s32) = 0;
    };
    void *list;
    Menu *menu;
    s32 i;
    Item *item;
    void *t2;

    list = Ui_FindChild(arg0, 0x81, 0);
    menu = (Menu *)Ui_FindChild(arg0, 0x80, 0);
    fn_8000D864(0, fn_801D2B04(list));
    Ui_SetWidgetText(menu, gUiScrollListStrings + 0x31);
    *(u32 *)((u8 *)menu + 0x48) = 0;
    menu = (Menu *)fn_8013BC10(0, 0);
    M2C_FIELD(menu, s16 *, 8) = 0x198;
    M2C_FIELD(menu, s16 *, 0xA) = 0x38;
    M2C_FIELD(menu, u8 *, 0x24) = 1;
    for (i = 0; menu->get(i) != 0; i++) {
        item = menu->get(i);
        item->set2(2);
        item->set3(3);
    }
    Ui_CreateMenu(menu, arg0, 0);
    menu = (Menu *)Msg_Expand(gUiScrollListStrings + 0x43);
    t2 = Ui_FindChild(arg0, -0x1000, 0);
    if (t2) {
        Ui_SetWidgetText(t2, menu);
    }
#pragma cplusplus reset
}

#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void Ui_HandleScrollListInput(void *arg0) {
    /* Handle scroll-list pad input: A confirm/error, X unit-info, B back; refresh popup on selection change. */
    void Process_Goto(void *, s32);
    void Process_ClearFunc(void *);
    void Ui_UpdatePanelWidgets(void *);
    void *Ui_FindChild(void *, s32, s32);
    void Ui_PlaySeCue(void *, s32);
    u8 Ui_IsUnitInfoPopupOpen(void *);
    void Ui_ShowUnitInfoText(void *, s32, f32, f32);
    void Ui_HideUnitInfoPopup(void *);
    void Ui_OpenUnitInfoText(void *, void *, s32, f32, f32);
    void Ui_CreateMsgPopup(void *, void *, f32, f32);
    u8 fn_801D2A38(void *);
    s32 fn_801D2AAC(void *);
    s32 fn_801D2C20(void *);
    extern char gUiScrollListStrings[];
    extern u8 gUnitInfoPopup[];
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern s32 gUnitInfoPopupFlag;

    class Vec2s {
    public:
        s16 x;
        s16 y;
        Vec2s() {}
        Vec2s(const Vec2s &o) { *(u32 *)this = *(u32 *)&o; }
        Vec2s &operator=(const Vec2s &o) { *(u32 *)this = *(u32 *)&o; return *this; }
    };
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
        virtual Vec2s v9() = 0;
    };

    void *list;
    register int btn;
    void *self;
    register u8 gate;
    register int flags;
    u32 pos1;
    u32 pos2;
    u32 pos3;

    self = arg0;
    list = Ui_FindChild(arg0, 0x81, 0);
    btn = fn_801D2AAC(list);
    Ui_UpdatePanelWidgets(self);
    if (btn != fn_801D2AAC(list)) {
        fn_801D2AAC(list);
        if (Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            *(Vec2s *)&pos1 = ((Obj *)list)->v9();
            Ui_ShowUnitInfoText(gUnitInfoPopup, fn_801D2C20(list), (f32)*(s16 *)&pos1, (f32)*((s16 *)&pos1 + 1));
        }
    }

    flags = gUiInputFlags;
    gate = 0;
    if ((flags & 0x10) && !(flags & 0x20)) {
        gate = 1;
    }
    if (!gate) {
        btn = *(s32 *)((u8 *)gPadInput + 4);
        btn = btn & (*(s32 *)((u8 *)gPadInput + 8) ^ btn);
        if ((btn & 0x100) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            if (fn_801D2A38(list) != 0) {
                *(Vec2s *)&pos2 = ((Obj *)list)->v9();
                Ui_CreateMsgPopup(gUiScrollListStrings + 0x54, self, (f32)*(s16 *)&pos2, (f32)*((s16 *)&pos2 + 1));
            } else {
                Process_ClearFunc(self);
                Ui_PlaySeCue(gUiScrollListStrings + 0x66, 0x64);
            }
        } else if ((btn & 0x800) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            *(Vec2s *)&pos3 = ((Obj *)list)->v9();
            Ui_OpenUnitInfoText(gUnitInfoPopup, self, fn_801D2C20(list), (f32)*(s16 *)&pos3, (f32)*((s16 *)&pos3 + 1));
            *(s32 *)gUnitInfoPopup = *(s32 *)gUnitInfoPopup | gUnitInfoPopupFlag;
        } else if ((btn & 0xa00) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) != 0) {
            Ui_HideUnitInfoPopup(gUnitInfoPopup);
        } else if ((btn & 0x200) && Ui_IsUnitInfoPopupOpen(gUnitInfoPopup) == 0) {
            Process_Goto(self, 5);
            Ui_PlaySeCue(gUiScrollListStrings + 0x76, 0x64);
        }
    }
}
#pragma use_lmw_stmw reset
#pragma cplusplus reset

#pragma optimization_level 3
void fn_801C0F54(s32 arg0) {
    u32 fn_8013FF94(s32, s32, s32);
    void fn_801658DC(u32, void *);
    void *fn_8000E0E4(void *);
    extern char lbl_8027CF10[];
    void *tmp;
    void *str;
    u32 result;

    tmp = (void *)fn_8013FF94(arg0, 0x80, 0);
    *(s32 *)((u8 *)tmp + 0x48) = 1;
    fn_801658DC((u32)tmp, lbl_8027CF10 + 0x86);
    str = fn_8000E0E4(lbl_8027CF10 + 0x99);
    result = fn_8013FF94(arg0, -0x1000, 0);
    if (result != 0) {
        fn_801658DC(result, str);
    }
}
#pragma optimization_level reset
void fn_801C0FDC(void *arg0) {
    void *Heap_Alloc(s32);
    void Ui_AddChild(void *);
    void *fn_801C14B4(void *, s32, s32, s32);
    void *obj;

    obj = Heap_Alloc(0xC8);
    if (obj != NULL) {
        obj = fn_801C14B4(obj, 0x80, 0x70, 0x1F4);
    }
    *(s16 *)((u8 *)obj + 8) = 0x81;
    *(u32 *)((u8 *)obj + 0x34) |= 0x10;
    Ui_AddChild(arg0);
}

#pragma cplusplus on
extern "C" void fn_801C1044(void *arg0) {
    struct Obj {
        u8 pad[0x40];
        virtual void m08(s32) = 0;
    };
    ((Obj *) arg0)->m08(-1);
}

extern "C" void *fn_801C1074(void *arg0, s16 arg1) {
    void Ui_DtorPanelBase(void *, s16);
    void Heap_Free(void *);
    extern u8 lbl_80297FEC[];
    if (arg0 != NULL) {
        *(void **)((char *)arg0 + 0x40) = lbl_80297FEC;
        Ui_DtorPanelBase(arg0, 0);
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

#pragma cplusplus off
void fn_801C10D4(void *arg0) {
void *Heap_Alloc(u32); void Ui_SetWidgetText(void *,void *); void Ui_AddChild(void *,void *);
s32 strlen(const char *); void String_AssignCStr(void *,const void *,s32);
s32 Msg_Expand(void *); s32 Ui_FindChild(void *,s32,s32);
extern u8 lbl_8028FDB0[],lbl_80292230[],lbl_80293C84[],lbl_80293C2C[],lbl_80293C00[],lbl_80293C58[],gUiScrollListStrings[];
extern f32 lbl_8036B318;
s32 text;
 void *p;
 void *obj;
 void *self=arg0;
p=Heap_Alloc(0x60);
if(p) {
text=0;M2C_FIELD(p,void **,0)=lbl_8028FDB0;
M2C_FIELD(p,u32 *,4)=text;
M2C_FIELD(p,void **,0)=lbl_80292230;
M2C_FIELD(p,s16 *,8)=-1;
M2C_FIELD(p,s16 *,10)=text;
M2C_FIELD(p,s16 *,12)=40;
M2C_FIELD(p,s16 *,14)=608;
M2C_FIELD(p,s16 *,16)=98;
M2C_FIELD(p,s16 *,18)=text;
M2C_FIELD(p,s16 *,20)=text;
M2C_FIELD(p,s16 *,22)=608;
M2C_FIELD(p,s16 *,24)=58;
M2C_FIELD(p,s16 *,26)=text;
M2C_FIELD(p,s16 *,28)=text;
M2C_FIELD(p,u8 *,30)=255;
M2C_FIELD(p,u8 *,31)=255;
M2C_FIELD(p,u8 *,32)=255;
M2C_FIELD(p,u8 *,33)=255;
M2C_FIELD(p,s16 *,34)=510;
M2C_FIELD(p,s16 *,36)=text;
M2C_FIELD(p,f32 *,40)=1.0f;
M2C_FIELD(p,f32 *,44)=1.0f;
M2C_FIELD(p,f32 *,48)=1.0f;
M2C_FIELD(p,u32 *,52)=text;
M2C_FIELD(p,u32 *,56)=text;
M2C_FIELD(p,void **,0)=lbl_80293C84;
M2C_FIELD(p,u32 *,60)=text;
M2C_FIELD(p,u32 *,64)=text;
M2C_FIELD(p,u32 *,68)=text;
M2C_FIELD(p,u32 *,64)=text;
M2C_FIELD(p,u32 *,72)=text;
M2C_FIELD(p,u8 *,76)=1;
M2C_FIELD(p,s16 *,78)=text;
M2C_FIELD(p,s16 *,80)=text;
M2C_FIELD(p,s16 *,82)=text;
M2C_FIELD(p,s16 *,84)=text;
M2C_FIELD(p,void **,0)=lbl_80293C2C;
M2C_FIELD(p,void **,0)=lbl_80293C00;
M2C_FIELD(p,u32 *,88)=text;
M2C_FIELD(p,s16 *,92)=12;
M2C_FIELD(p,s16 *,94)=16;
}
M2C_FIELD(p,s16 *,8)=0x80;
M2C_FIELD(p,u32 *,0x34)|=0x10;
M2C_FIELD(p,u32 *,0x58)=1;
M2C_FIELD(p,s16 *,0x4E)=0x60;
M2C_FIELD(p,s16 *,0x52)=0x60;
M2C_FIELD(p,u8 *,0x4C)=2;
M2C_FIELD(p,u32 *,0x48)=1;
Ui_SetWidgetText(p,gUiScrollListStrings+0x86);
Ui_AddChild(self,p);
p=Heap_Alloc(0x5C);
if(p) {M2C_FIELD(p,void **,0)=lbl_8028FDB0;
M2C_FIELD(p,u32 *,4)=0;
M2C_FIELD(p,void **,0)=lbl_80292230;
M2C_FIELD(p,s16 *,8)=-1;
M2C_FIELD(p,s16 *,10)=0;
M2C_FIELD(p,s16 *,12)=400;
M2C_FIELD(p,s16 *,14)=608;
M2C_FIELD(p,s16 *,16)=448;
M2C_FIELD(p,s16 *,18)=0;
M2C_FIELD(p,s16 *,20)=0;
M2C_FIELD(p,s16 *,22)=608;
M2C_FIELD(p,s16 *,24)=48;
M2C_FIELD(p,s16 *,26)=0;
M2C_FIELD(p,s16 *,28)=0;
M2C_FIELD(p,u8 *,30)=255;
M2C_FIELD(p,u8 *,31)=255;
M2C_FIELD(p,u8 *,32)=255;
M2C_FIELD(p,u8 *,33)=255;
M2C_FIELD(p,s16 *,34)=90;
M2C_FIELD(p,s16 *,36)=0;
M2C_FIELD(p,f32 *,40)=1.0f;
M2C_FIELD(p,f32 *,44)=1.0f;
M2C_FIELD(p,f32 *,48)=1.0f;
M2C_FIELD(p,u32 *,52)=0;
M2C_FIELD(p,u32 *,56)=0;
M2C_FIELD(p,void **,0)=lbl_80293C84;
M2C_FIELD(p,u32 *,60)=0;
M2C_FIELD(p,u32 *,64)=0;
M2C_FIELD(p,u32 *,68)=0;
M2C_FIELD(p,u32 *,64)=0;
M2C_FIELD(p,u32 *,72)=0;
M2C_FIELD(p,u8 *,76)=1;
M2C_FIELD(p,s16 *,78)=0;
M2C_FIELD(p,s16 *,80)=0;
M2C_FIELD(p,s16 *,82)=0;
M2C_FIELD(p,s16 *,84)=0;
M2C_FIELD(p,void **,0)=lbl_80293C58;
M2C_FIELD(p,u32 *,88)=1;
M2C_FIELD(p,s16 *,78)=48;
M2C_FIELD(p,s16 *,82)=48;
}
M2C_FIELD(p,s16 *,8)=-0x1000;
M2C_FIELD(p,u32 *,0x48)=1;
String_AssignCStr((u8 *)p+0x3C,gUiScrollListStrings+0xAA,strlen((char *)gUiScrollListStrings+0xAA));
M2C_FIELD(p,u32 *,0x34)|=0x10;
M2C_FIELD(p,u32 *,0x58)=1;
Ui_AddChild(arg0,p);
text=Msg_Expand(gUiScrollListStrings+0x99);
if((obj=(void *)Ui_FindChild(self,-0x1000,0))!=0) Ui_SetWidgetText(obj,(void *)text);
}
#pragma cplusplus off

s32 fn_801C13F0(void) {
    u8 fn_800BE800(s32);
    u8 fn_800BE890(s32);
    s32 fn_800BE914(void);
    s32 n;
    s32 i;

    n = fn_800BE914();
    for (i = 0; i < n; i++) {
        if (fn_800BE800(i) != 0 && fn_800BE890(i) == 0) {
            return 1;
        }
    }
    return 0;
}

s32 fn_801C1464(s32 arg0) {
    s32 Process_CreateChild(void *, s32);
    void fn_801403F0(void);
    extern u8 lbl_80297F28[];
    extern u8 lbl_80297FEC[];
    s32 result;

    result = Process_CreateChild(lbl_80297F28, arg0);
    if (result != 0) {
        fn_801403F0();
        *(u32 *)(result + 0x40) = (u32)lbl_80297FEC;
    }
    return result;
}

#pragma cplusplus on
extern "C" void fn_80142060(void *);
extern "C" int fn_801C18E4(void *);
extern "C" void fn_801D2C30(void *);
extern "C" void *fn_801C14B4(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    extern void *lbl_8028FDB0[];
    extern void *lbl_80292230[];
    extern void *lbl_80292208[];
    extern void *gUiScrollListPanelVtbl[];
    extern void *gEmptyVtbl[];
    extern f32 lbl_8036B318;
    extern f32 lbl_8036B31C;
    struct Work {
        virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0;
        virtual void v3() = 0; virtual void v4() = 0; virtual void v5() = 0;
        virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0;
    };
    struct Sub { virtual void v0() = 0; virtual void v1() = 0; };
    u32 pad;
    s32 z = 0;
    s32 temp_r11;
    s32 temp_r10;
    void *self;
    f32 one = lbl_8036B318;

    pad = 0;
    self = arg0;
    *(void **)((u8 *)self + 0x0) = lbl_8028FDB0;
    *(s32 *)((u8 *)self + 0x4) = z;
    *(void **)((u8 *)self + 0x0) = lbl_80292230;
    *(s16 *)((u8 *)self + 0x8) = -1;
    temp_r11 = (s16)(arg1 + 0x160);
    temp_r10 = (s16)(arg2 + 0xF0);
    *(s16 *)((u8 *)self + 0xA) = arg1;
    *(s16 *)((u8 *)self + 0xC) = arg2;
    *(s16 *)((u8 *)self + 0xE) = temp_r11;
    *(s16 *)((u8 *)self + 0x10) = temp_r10;
    *(s16 *)((u8 *)self + 0x12) = z;
    *(s16 *)((u8 *)self + 0x14) = z;
    *(s16 *)((u8 *)self + 0x16) = 0x160;
    *(s16 *)((u8 *)self + 0x18) = 0xF0;
    *(s16 *)((u8 *)self + 0x1A) = z;
    *(s16 *)((u8 *)self + 0x1C) = z;
    *(u8 *)((u8 *)self + 0x1E) = 0xFF;
    *(u8 *)((u8 *)self + 0x1F) = 0xFF;
    *(u8 *)((u8 *)self + 0x20) = 0xFF;
    *(u8 *)((u8 *)self + 0x21) = 0xFF;
    *(s16 *)((u8 *)self + 0x22) = arg3;
    *(s16 *)((u8 *)self + 0x24) = z;
    *(f32 *)((u8 *)self + 0x28) = one;
    *(f32 *)((u8 *)self + 0x2C) = one;
    *(f32 *)((u8 *)self + 0x30) = one;
    *(s32 *)((u8 *)self + 0x34) = z;
    *(s32 *)((u8 *)self + 0x38) = z;
    *(void **)((u8 *)self + 0x0) = lbl_80292208;
    fn_80142060((u8 *)self + 0x3C);
    *(void **)((u8 *)self + 0x0) = gUiScrollListPanelVtbl;
    *(s32 *)((u8 *)self + 0x48) = z;
    *(u8 *)((u8 *)self + 0x4C) = 1;
    *(s16 *)((u8 *)self + 0x4E) = z;
    *(s16 *)((u8 *)self + 0x50) = -1;
    *(s16 *)((u8 *)self + 0x52) = -1;
    *(s16 *)((u8 *)self + 0x54) = z;
    *(s16 *)((u8 *)self + 0x56) = 0x20;
    *(s16 *)((u8 *)self + 0x58) = 6;
    *(f32 *)((u8 *)self + 0x5C) = lbl_8036B31C;
    *(s16 *)((u8 *)self + 0x60) = 0x40;
    *(s16 *)((u8 *)self + 0x62) = 8;
    fn_801C18E4((u8 *)self + 0x6C);
    *(void **)((u8 *)self + 0x78) = gEmptyVtbl;
    *(s32 *)((u8 *)self + 0x7C) = z;
    *(s32 *)((u8 *)self + 0x80) = 2;
    *(u8 *)((u8 *)self + 0x84) = 1;
    *(u8 *)((u8 *)self + 0x85) = 1;
    *(s16 *)((u8 *)self + 0x8C) = z;
    *(s16 *)((u8 *)self + 0x8E) = z;
    *(f32 *)((u8 *)self + 0x90) = lbl_8036B318;
    *(f32 *)((u8 *)self + 0x94) = lbl_8036B318;
    *(u8 *)((u8 *)self + 0x98) = 0xFF;
    *(u8 *)((u8 *)self + 0x99) = 0xFF;
    *(u8 *)((u8 *)self + 0x9A) = 0xFF;
    *(u8 *)((u8 *)self + 0x9B) = 0xFF;
    *(f32 *)((u8 *)self + 0x9C) = lbl_8036B31C;
    ((Sub *)((u8 *)self + 0x78))->v1();
    *(void **)((u8 *)self + 0xA0) = gEmptyVtbl;
    *(s32 *)((u8 *)self + 0xA4) = z;
    *(s32 *)((u8 *)self + 0xA8) = 3;
    *(u8 *)((u8 *)self + 0xAC) = 1;
    *(u8 *)((u8 *)self + 0xAD) = 1;
    *(s16 *)((u8 *)self + 0xB4) = z;
    *(s16 *)((u8 *)self + 0xB6) = z;
    *(f32 *)((u8 *)self + 0xB8) = lbl_8036B318;
    *(f32 *)((u8 *)self + 0xBC) = lbl_8036B318;
    *(u8 *)((u8 *)self + 0xC0) = 0xFF;
    *(u8 *)((u8 *)self + 0xC1) = 0xFF;
    *(u8 *)((u8 *)self + 0xC2) = 0xFF;
    *(u8 *)((u8 *)self + 0xC3) = 0xFF;
    *(f32 *)((u8 *)self + 0xC4) = lbl_8036B31C;
    ((Sub *)((u8 *)self + 0xA0))->v1();
    ((Work *)self)->v8();
    fn_801D2C30(self);
    return self;
}

extern "C" void fn_801C16F0(void *arg0) {
#pragma cplusplus reset
void *Heap_Alloc(s32);
void *fn_8013692C(void *,s32,s32,s32,s32,s32);
void fn_8013F0F0(void *,void *);
void fn_8013F1A0(void *,void *);
#pragma cplusplus on
struct Rect {
s16 left,top,right,bottom;
s16 width() { return right-left; }
s16 height() { return bottom-top; }
void set(s16 l,s16 t,s16 r,s16 b) { left=l; top=t; right=r; bottom=b; }
};
void *child;
s16 mid,height;
Rect *outer=(Rect *)((u8 *)arg0+0xA);
Rect *inner=(Rect *)((u8 *)arg0+0x12);
inner->set(2,8,outer->width()-2,outer->height()-8);
M2C_FIELD(arg0,s16 *,0x86)=(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))>>1;
M2C_FIELD(arg0,s16 *,0x88)=0;
M2C_FIELD(arg0,s16 *,0x8A)=0;
mid=(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))>>1;
height=M2C_FIELD(arg0,s16 *,0x18)-M2C_FIELD(arg0,s16 *,0x14);
M2C_FIELD(arg0,s16 *,0xAE)=mid;
M2C_FIELD(arg0,s16 *,0xB0)=height;
M2C_FIELD(arg0,s16 *,0xB2)=0;
if(M2C_FIELD(arg0,void **,0x48)) fn_8013F0F0(arg0,M2C_FIELD(arg0,void **,0x48));
child=Heap_Alloc(0x9C);
if(child) child=fn_8013692C(child,(s16)(M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x12))-16,0,9,(s16)(M2C_FIELD(arg0,s16 *,0x18)-M2C_FIELD(arg0,s16 *,0x14))-16,M2C_FIELD(arg0,s16 *,0x22)-5);
M2C_FIELD(arg0,void **,0x48)=child;
M2C_FIELD(M2C_FIELD(arg0,void **,0x48),s32 *,0x48)=2;
fn_8013F1A0(arg0,M2C_FIELD(arg0,void **,0x48));
#pragma cplusplus reset
}

#pragma cplusplus reset

void Heap_Free(void *);
void *fn_801D2E40(void *, s16);
void fn_801C1824(ListIter *ret, List *list, ListIter *start, ListIter *end) {
    ListNode *first;
    ListNode *last;
    ListNode *a;
    ListNode *node;

    first = start->node;
    last = end->node;
    if (first == last) {
        ret->node = last;
        return;
    }
    a = last->prev;
    first->prev->next = a->next;
    a->next->prev = first->prev;
    while (start->node != end->node) {
        fn_801D2E40((u8 *)start->node + 8, -1);
        node = start->node;
        start->node = node->next;
        Heap_Free(node);
        list->size--;
    }
    ret->node = end->node;
}

int fn_801C18E4(void *arg0) {
    u32 *ptr;

    ptr = (u32 *)((u8 *)arg0 + 0x4);
    *(u32 *)arg0 = 0;
    ptr[1] = (u32)ptr;
    ptr[0] = (u32)ptr;
}

void fn_801C18FC(s32 arg0) {
    void GfxEnt_ForEachKey(void *, void *, void *, void *);
    extern void fn_801C19E4(void *, s32);
    extern u8 lbl_80297FF8[];
    extern s8 lbl_80368280;
    extern f32 lbl_8036B328;
    void *c;

    c = &lbl_80368280;
    lbl_80368280 = -1;
    *(s32 *)((char *)c + 4) = (s32)((f32)arg0 / lbl_8036B328);
    GfxEnt_ForEachKey(lbl_80297FF8, (void *)fn_801C19E4, &lbl_80368280, c);
}

void fn_801C1970(s8 arg0, s32 arg1) {
void GfxEnt_ForEachKey(void *, void *, void *);
extern void fn_801C19E4(void *, s32);
extern u8 lbl_80297FF8[];
extern s8 lbl_80368280;
extern f32 lbl_8036B328;
void *c = &lbl_80368280;
lbl_80368280 = arg0;
*(s32 *)((char *)c + 4) = (s32)((f32)arg1 / 16.666666f);
GfxEnt_ForEachKey(lbl_80297FF8, (void *)fn_801C19E4, &lbl_80368280);
}

void fn_801C19E4(u8 *arg0, u8 *arg1) {
    s32 a;
    s32 b;

    a = arg0[0x30];
    b = arg1[0];
    a = (s8)a;
    b = (s8)b;
    if (a == b || b == -1) {
        arg0[0x31] = 0xA;
        *(s16 *)(arg0 + 0x3A) = *(s32 *)(arg1 + 4);
    }
}

#pragma global_optimizer off
void fn_801C1A18(s8 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6) {
    void *fn_8000CAF0(void *, s32);
    extern u8 lbl_80297FF8[];
    extern f64 lbl_8036B330;
    extern f32 lbl_8036B328;
    void *obj;
    union { f64 d; struct { u32 hi; u32 lo; } w; } conv;
    s16 v;

    obj = fn_8000CAF0(lbl_80297FF8, arg6);
    conv.w.hi = 0x43300000;
    conv.w.lo = (u32)arg5 ^ 0x80000000;
    v = (s16)((f32)(conv.d - lbl_8036B330) / lbl_8036B328);
    *(s16 *)((u8 *)obj + 0x3C) = arg1;
    *(s16 *)((u8 *)obj + 0x3E) = arg2;
    *(s16 *)((u8 *)obj + 0x40) = arg3;
    *(s32 *)((u8 *)obj + 0x44) = arg4;
    *(s8 *)((u8 *)obj + 0x30) = arg0;
    *(s16 *)((u8 *)obj + 0x36) = v;
    *(s16 *)((u8 *)obj + 0x38) = -1;
    *(s16 *)((u8 *)obj + 0x3A) = 0;
    *(u8 *)((u8 *)obj + 0x48) = 1;
}
#pragma global_optimizer off
void fn_801C1AC8(s16 arg0, s16 arg1, s16 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    void *Process_Create(void *, s32);
    extern u8 lbl_80297FF8[];
    extern f32 lbl_8036B328;
    extern f64 lbl_8036B330;
    void *obj;
    f32 div;

    obj = Process_Create(lbl_80297FF8, arg7);
    div = lbl_8036B328;
    (void)lbl_8036B330;
    *(s16 *)((u8 *)obj + 0x3C) = arg0;
    *(s16 *)((u8 *)obj + 0x3E) = arg1;
    *(s16 *)((u8 *)obj + 0x40) = arg2;
    *(s32 *)((u8 *)obj + 0x44) = arg3;
    *(s8 *)((u8 *)obj + 0x30) = -1;
    *(s16 *)((u8 *)obj + 0x36) = (s16)((f32)arg4 / div);
    *(s16 *)((u8 *)obj + 0x38) = (s16)((f32)arg5 / div);
    *(s16 *)((u8 *)obj + 0x3A) = (s16)((f32)arg6 / div);
    *(u8 *)((u8 *)obj + 0x48) = 1;
}
#pragma global_optimizer on
void fn_801C1BC0(s8 arg0, s16 arg1, s16 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void *Process_Create(void *, s32);
    extern u8 lbl_80297FF8[];
    extern f32 lbl_8036B328;
    extern f64 lbl_8036B330;
    void *obj;
    union { f64 d; struct { u32 hi; u32 lo; } w; } conv;
    union { f64 d; struct { f32 hi; f32 lo; } f; } diff;
    s16 v;

    obj = Process_Create(lbl_80297FF8, arg5);
    conv.w.hi = 0x43300000;
    conv.w.lo = (u32)arg4 ^ 0x80000000;
    diff.d = conv.d - lbl_8036B330;
    v = (s16)(diff.f.hi / lbl_8036B328);
    *(s16 *)((u8 *)obj + 0x3C) = arg1;
    *(s16 *)((u8 *)obj + 0x3E) = arg2;
    *(s32 *)((u8 *)obj + 0x44) = arg3;
    *(s8 *)((u8 *)obj + 0x30) = arg0;
    *(s16 *)((u8 *)obj + 0x36) = v;
    *(s16 *)((u8 *)obj + 0x38) = -1;
    *(s16 *)((u8 *)obj + 0x3A) = 0;
    *(u8 *)((u8 *)obj + 0x48) = 0;
}
void fn_801C1C64(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    void *Process_Create(void *, s32);
    extern u8 lbl_80297FF8[];
    extern f32 lbl_8036B328;
    extern f64 lbl_8036B330;
    void *obj;
    f32 div;

    obj = Process_Create(lbl_80297FF8, arg6);
    div = lbl_8036B328;
    (void)lbl_8036B330;
    *(s16 *)((u8 *)obj + 0x3C) = arg0;
    *(s16 *)((u8 *)obj + 0x3E) = arg1;
    *(s32 *)((u8 *)obj + 0x44) = arg2;
    *(s8 *)((u8 *)obj + 0x30) = -1;
    *(s16 *)((u8 *)obj + 0x36) = (s16)((f32)arg3 / div);
    *(s16 *)((u8 *)obj + 0x38) = (s16)((f32)arg4 / div);
    *(s16 *)((u8 *)obj + 0x3A) = (s16)((f32)arg5 / div);
    *(u8 *)((u8 *)obj + 0x48) = 0;
}
void fn_801C1D54(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *Process_Create(void *, s32);
    extern u8 lbl_8029801C[];
    extern f32 lbl_8036B328;
    extern f64 lbl_8036B330;
    void *obj;
    union { f64 d; struct { u32 hi; u32 lo; } w; } conv2;
    union { f64 d; struct { u32 hi; u32 lo; } w; } conv;
    s16 v;

    obj = Process_Create(lbl_8029801C, 3);
    conv.w.hi = 0x43300000;
    conv.w.lo = (u32)arg3 ^ 0x80000000;
    conv2.w.hi = 0x43300000;
    conv2.w.lo = (u32)arg4 ^ 0x80000000;
    v = (s16)((f32)(conv.d - lbl_8036B330) / lbl_8036B328);
    *(s16 *)((u8 *)obj + 0x3C) = arg0;
    *(s16 *)((u8 *)obj + 0x3E) = arg1;
    *(s32 *)((u8 *)obj + 0x44) = arg2;
    *(s16 *)((u8 *)obj + 0x36) = v;
    *(s16 *)((u8 *)obj + 0x38) = (s16)((f32)(conv2.d - lbl_8036B330) / lbl_8036B328);
    *(s16 *)((u8 *)obj + 0x3A) = v;
}
void fn_801C1E0C(void *arg0) {
    void Prim2D_SetCornerColors(void *, void *, void *, void *);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetColorByte(u8);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void *Msg_Expand(void *);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, ...);
    s32 Text_MeasureWidth(void *, s32, f32);
    void **fn_8006EDD8(void *, s32);
    extern void *gUiAtlas;
    extern u32 lbl_8036B320;
    extern u32 lbl_8036B324;
    extern f32 lbl_8036B338;
    extern f32 lbl_8036B33C;
    extern f32 lbl_8036B340;
    extern f32 lbl_8036B344;
    extern f32 lbl_8036B348;
    extern f32 lbl_8036B34C;
    extern u32 lbl_8036C508;
    extern u32 lbl_8036C50C;

    u32 sp14;
    u32 sp10;
    u32 spC;
    u32 sp8;
    void *mgr;
    void *self;
    u16 *pair;
    u16 h;
    u16 h4;
    s32 x;
    s16 y;
    s32 textW;
    void *str;
    f32 tw;

    self = arg0;
    mgr = gUiAtlas;
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B338, lbl_8036B338, lbl_8036B33C, lbl_8036B340);
    Prim2D_SetColorByte(*(u8 *)((u8 *)self + 0x32));
    Prim2D_PrepareTex();
    pair = (u16 *)*fn_8006EDD8(mgr, 0x1F);
    h = pair[1];
    h4 = (u16)(pair[0] - 4);
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect((f32)*(s16 *)((u8 *)self + 0x3C), (f32)*(s16 *)((u8 *)self + 0x3E), (f32)h, (f32)h4);
    Prim2D_SetColor(0, 0, 0, 0xA0);
    Prim2D_EndPrim();
    Prim2D_AddPrim(3);
    Prim2D_SetRect((f32)(*(s16 *)((u8 *)self + 0x3C) + h), (f32)*(s16 *)((u8 *)self + 0x3E), lbl_8036B344, (f32)h4);
    Prim2D_EmitQuad();
    sp8 = lbl_8036C50C;
    spC = lbl_8036B324;
    sp10 = lbl_8036C508;
    sp14 = lbl_8036B320;
    Prim2D_SetCornerColors(&sp14, &sp10, &spC, &sp8);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B348);
    Prim2D_PrepareTex();
    textW = Text_MeasureWidth(Msg_Expand(*(void **)((u8 *)self + 0x44)), -1, lbl_8036B340);
    tw = (f32)textW;
    x = (s32)((f32)(*(s16 *)((u8 *)self + 0x3C) + 0x4E) - lbl_8036B34C * tw);
    y = *(s16 *)((u8 *)self + 0x3E);
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    str = Msg_Expand(*(void **)((u8 *)self + 0x44));
    fn_8001003C(x, y, 0xD, 0, 0, str, lbl_8036B340, lbl_8036B338);
    Prim2D_Begin();
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();
}

void fn_801C2084(void *arg0)
{
    extern u32 gUiInputFlags;
    extern f32 lbl_8036B338;
    extern f32 lbl_8036B358;

    void Process_ClearFunc(void *);
    f32 Math_Ease(s32, f32, f32, f32, f32);

    u8 *self;
    s16 timer;
    s16 duration;
    s32 value;

    self = (u8 *)arg0;

    if (*(s16 *)(self + 0x38) != -1) {
        if (gUiInputFlags & 1) {
            Process_ClearFunc(self);
            return;
        }

        if (gUiInputFlags & 2) {
            self[0x31] = 10;
            *(s16 *)(self + 0x34) = 0;
            return;
        }
    }

    switch ((s8)self[0x31]) {
    case 0:
        timer = *(s16 *)(self + 0x34);
        *(s16 *)(self + 0x34) = timer + 1;

        timer = *(s16 *)(self + 0x34);
        duration = *(s16 *)(self + 0x36);

        value = (s32)Math_Ease(
            0,
            lbl_8036B338,
            lbl_8036B358,
            (f32)timer,
            (f32)duration
        );

        self[0x32] = value;

        if (*(s16 *)(self + 0x34) >=
            *(s16 *)(self + 0x36)) {
            self[0x31] = 5;
            *(s16 *)(self + 0x34) = 0;
        }
        break;

    case 5:
        if (*(s16 *)(self + 0x38) != -1) {
            timer = *(s16 *)(self + 0x34);
            *(s16 *)(self + 0x34) = timer + 1;

            if (*(s16 *)(self + 0x34) >=
                *(s16 *)(self + 0x38)) {
                self[0x31] = 10;
                *(s16 *)(self + 0x34) = 0;
            }
        }
        break;

    case 10:
        timer = *(s16 *)(self + 0x34);
        *(s16 *)(self + 0x34) = timer + 1;

        timer = *(s16 *)(self + 0x34);
        duration = *(s16 *)(self + 0x3A);

        value = (s32)Math_Ease(
            0,
            lbl_8036B358,
            lbl_8036B338,
            (f32)timer,
            (f32)duration
        );

        self[0x32] = value;

        if (*(s16 *)(self + 0x34) >=
            *(s16 *)(self + 0x3A)) {
            Process_ClearFunc(self);
        }
        break;
    }
}

void fn_801C2250(void *arg0) {
    if (arg0 != NULL) {
        *(u8 *)((u32)arg0 + 0x31) = 0;
        *(u16 *)((u32)arg0 + 0x34) = 0;
        Process_ClearFunc();
    }
}

void fn_801C2284(void *arg0) {
    void Prim2D_EmitQuad(void);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetColorByte(u8);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_BindTexture(void *, s32, s32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void *Msg_Expand(void *);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, ...);
    s32 Text_MeasureWidth(void *, s32, f32);
    extern void *gUiAtlas;
    extern f32 lbl_8036B338;
    extern f32 lbl_8036B340;
    extern f32 lbl_8036B344;
    extern f32 lbl_8036B348;
    extern f32 lbl_8036B34C;
    extern f32 lbl_8036B35C;
    extern f32 lbl_8036B360;
    extern f32 lbl_8036B364;
    extern f32 lbl_8036B368;
    extern f32 lbl_8036B36C;

    s32 tx;
    void *self;
    s32 x;
    s32 i;
    s32 tiles;
    void *mgr;
    u16 barW;
    f32 tw;
    s16 ty;

    self = arg0;
    mgr = gUiAtlas;
    tw = (f32)Text_MeasureWidth(Msg_Expand(*(void **)((u8 *)self + 0x44)), -1, lbl_8036B340);
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B338, lbl_8036B338, lbl_8036B35C, lbl_8036B340);
    Prim2D_SetColorByte(*(u8 *)((u8 *)self + 0x32));
    Prim2D_PrepareTex();

    if (*(u8 *)((u8 *)self + 0x48) == 0) {
        x = *(s16 *)((u8 *)self + 0x3C);
        Prim2D_Begin();
        Prim2D_BindTexture(mgr, 0x3D, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin((f32)x, (f32)*(s16 *)((u8 *)self + 0x3E), lbl_8036B338, lbl_8036B338);
        Prim2D_SetQuadMax((f32)(x + 0x1A), (f32)(*(s16 *)((u8 *)self + 0x3E) + 0x28), lbl_8036B360, lbl_8036B364);
        Prim2D_EmitQuad();
        Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
        Prim2D_EndPrim();
        x += 0x1A;
        Prim2D_Begin();
        Prim2D_BindTexture(mgr, 0x3E, 0x11);
        Prim2D_PrepareTex();
        barW = (u16)(((((s32)(u16)(s32)tw - 1) / 16) * 16) + 0x10);
        tiles = barW >> 4;
        for (i = 0; i < tiles; i++) {
            Prim2D_AddPrim(1);
            Prim2D_SetQuadMin((f32)(s16)x, (f32)(*(s16 *)((u8 *)self + 0x3E) + 2), lbl_8036B338, lbl_8036B338);
            Prim2D_SetQuadMax((f32)((s16)x + 0x10), (f32)(*(s16 *)((u8 *)self + 0x3E) + 0x22), lbl_8036B368, lbl_8036B344);
            Prim2D_EmitQuad();
            Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
            Prim2D_EndPrim();
            x += 0x10;
        }
        Prim2D_Begin();
        Prim2D_BindTexture(mgr, 0x3F, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin((f32)(s16)x, (f32)(*(s16 *)((u8 *)self + 0x3E) - 1), lbl_8036B36C, lbl_8036B338);
        Prim2D_SetQuadMax((f32)((s16)x + 0x1A), (f32)(*(s16 *)((u8 *)self + 0x3E) + 0x27), lbl_8036B344, lbl_8036B364);
        Prim2D_EmitQuad();
        Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B348);
        Prim2D_PrepareTex();
        tx = (s32)((f32)(*(s16 *)((u8 *)self + 0x3C) + (s32)(barW >> 1) + 0x1A) - lbl_8036B34C * tw);
        ty = (s16)(*(s16 *)((u8 *)self + 0x3E) + 2);
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        fn_8001003C(tx, ty, 2, 0, 0, Msg_Expand(*(void **)((u8 *)self + 0x44)), lbl_8036B340, lbl_8036B338);
    }

    if (*(u8 *)((u8 *)self + 0x48) == 1) {
        barW = (u16)(((((s32)(u16)(s32)tw - 1) / 16) * 16) + *(s16 *)((u8 *)self + 0x40) + 0x30);
        x = *(s16 *)((u8 *)self + 0x3C);
        Prim2D_Begin();
        Prim2D_BindTexture(mgr, 0x40, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin((f32)x, (f32)(*(s16 *)((u8 *)self + 0x3E) + 2), lbl_8036B338, lbl_8036B338);
        Prim2D_SetQuadMax((f32)(x + 0x1A), (f32)(*(s16 *)((u8 *)self + 0x3E) + 0x2A), lbl_8036B360, lbl_8036B364);
        Prim2D_EmitQuad();
        Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
        Prim2D_EndPrim();
        x += 0x1A;
        Prim2D_Begin();
        Prim2D_BindTexture(mgr, 0x41, 0x11);
        Prim2D_PrepareTex();
        tiles = barW >> 4;
        for (i = 0; i < tiles; i++) {
            Prim2D_AddPrim(1);
            Prim2D_SetQuadMin((f32)(s16)x, (f32)(*(s16 *)((u8 *)self + 0x3E) + 2), lbl_8036B338, lbl_8036B338);
            Prim2D_SetQuadMax((f32)((s16)x + 0x10), (f32)(*(s16 *)((u8 *)self + 0x3E) + 0x22), lbl_8036B368, lbl_8036B344);
            Prim2D_EmitQuad();
            Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
            Prim2D_EndPrim();
            x += 0x10;
        }
        Prim2D_Begin();
        Prim2D_BindTexture(mgr, 0x42, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin((f32)(s16)x, (f32)(*(s16 *)((u8 *)self + 0x3E) + 2), lbl_8036B338, lbl_8036B338);
        Prim2D_SetQuadMax((f32)((s16)x + 0x28), (f32)(*(s16 *)((u8 *)self + 0x3E) + 0x2A), lbl_8036B364, lbl_8036B364);
        Prim2D_EmitQuad();
        Prim2D_SetColor(0xFF, 0xFF, 0xFF, 0xFF);
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B348);
        Prim2D_PrepareTex();
        tx = (s32)((f32)(*(s16 *)((u8 *)self + 0x3C) + (s32)(barW >> 1) + 0x28) - lbl_8036B34C * tw);
        ty = (s16)(*(s16 *)((u8 *)self + 0x3E) + 1);
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        fn_8001003C(tx, ty, 2, 0, 0, Msg_Expand(*(void **)((u8 *)self + 0x44)), lbl_8036B340, lbl_8036B338);
    }

    Prim2D_Begin();
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();
}

void fn_801C29E8(s32 arg0) {
    void *Process_CreateChild(void *, s32);
    s32 fn_800C4638(s32, void *, s32);
    extern u8 lbl_80298140[];
    extern u8 lbl_8027D030[];
    void *temp_r31;

    temp_r31 = Process_CreateChild(lbl_80298140, arg0);
    M2C_FIELD(temp_r31, s32 *, 0x30) = fn_800C4638(0x160, lbl_8027D030 + 0x3F1, 0);
}

#pragma cplusplus on
extern "C" void fn_801C2A3C(void *arg0) {
    void *Sound_FindByName(void *);
    void Process_Unlink(void *);
    void FileCache_ReleaseSlot(void *);
    void fn_80161F7C(void);
    void fn_8003F670(void *);
    void fn_800C4588(void *);
    struct Obj {
        u8 pad[0x2C];
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6(s32) = 0;
    };
    void *obj;
    Obj *p;

    obj = *(void **)((u8 *)arg0 + 0x30);
    if (*(void **)((u8 *)obj + 0x30) != NULL) {
        if (Sound_FindByName(*(void **)((u8 *)obj + 0x30)) != NULL) {
            Process_Unlink(Sound_FindByName(*(void **)((u8 *)obj + 0x30)));
        }
    }
    Process_Unlink(Sound_FindByName(*(void **)((u8 *)obj + 0x2C)));
    p = *(Obj **)((u8 *)obj + 0x38);
    if (p != NULL) {
        p->v6(1);
    }
    FileCache_ReleaseSlot(obj);
    fn_80161F7C();
    fn_8003F670(*(void **)((u8 *)obj + 4));
    fn_800C4588(obj);
}
extern "C" void fn_801C2AD0(void *arg0) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Process_ClearFunc(void *);
    void Process_Unlink(void);
    void *Sound_FindByName(void *);
    void *Sound_Create(void *, s32);
    void fn_80109BB4(void *, s32);
    void Sound_FadeFromZero(void *, s32);
    s8 Fx_FindSlotByName(void *);
    void fn_80147188(s32);
    void Ui_PlaySeCue(void *, s32);
    void Fx_StartSlot(s32, void *, s32, s32);
    void fn_80148980(void *, s32);
    extern void *lbl_80298040[];
    extern u8 lbl_8027D030[];
    extern u8 gFxChannels[];
    extern void *gPadInput;
    extern f32 lbl_8036B374, lbl_8036B378, lbl_8036B37C, lbl_8036B380;
    extern f32 lbl_8036B384, lbl_8036B388;

    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual u8 v2() = 0;
    };

    s32 t;
    s32 off;
    void *p;
    void *q;
    s16 *row;
    f32 x, y;
    u8 flag;
    s32 old24;
    void *st;
    s32 held;
    s32 trig;
    void *pad;
    void *self;

    self = arg0;
    st = *(void **)((u8 *)self + 0x30);
    pad = gPadInput;
    {
        f32 zero = lbl_8036B374;
        f32 cur = *(f32 *)((u8 *)st + 0x140);
        trig = *(s32 *)((u8 *)pad + 4);
        held = *(s32 *)((u8 *)pad + 0xC);
        old24 = *(s32 *)((u8 *)st + 0x24);
        trig = trig & (*(s32 *)((u8 *)pad + 8) ^ trig);
        if (cur > zero) {
            *(f32 *)((u8 *)st + 0x140) = cur - lbl_8036B378;
            if (*(f32 *)((u8 *)st + 0x140) < zero)
                *(f32 *)((u8 *)st + 0x140) = zero;
        }
        cur = *(f32 *)((u8 *)st + 0x140);
        if (cur < zero) {
            *(f32 *)((u8 *)st + 0x140) = cur + lbl_8036B378;
            if (*(f32 *)((u8 *)st + 0x140) > zero)
                *(f32 *)((u8 *)st + 0x140) = zero;
        }
    }

    if (*(s16 *)((u8 *)st + 0x148) > 0) {
        *(s16 *)((u8 *)st + 0x148) = (s16)(*(s16 *)((u8 *)st + 0x148) - 1);
        t = 4 - *(s16 *)((u8 *)st + 0x148);
        *(s16 *)((u8 *)st + 0x144) = (s16)Math_Ease(4, (f32)*(s16 *)((u8 *)st + 0x14A), (f32)*(s16 *)((u8 *)st + 0x14E), (f32)t, lbl_8036B37C);
        *(s16 *)((u8 *)st + 0x146) = (s16)Math_Ease(4, (f32)*(s16 *)((u8 *)st + 0x14C), (f32)*(s16 *)((u8 *)st + 0x150), (f32)t, lbl_8036B37C);
    }
    *(s16 *)((u8 *)st + 0x15A) = 0x78;

    if (*(s32 *)((u8 *)st + 0x28) != -1) {
        *(s16 *)((u8 *)st + 0x15C) = (s16)(*(s16 *)((u8 *)st + 0x15C) - 4);
        if (*(s16 *)((u8 *)st + 0x15C) < 0x6E)
            *(s16 *)((u8 *)st + 0x15C) = 0x6E;
        *(s16 *)((u8 *)st + 0x15E) = (s16)(*(s16 *)((u8 *)st + 0x15E) + 8);
        if (*(s16 *)((u8 *)st + 0x15E) > 0xFF)
            *(s16 *)((u8 *)st + 0x15E) = 0xFF;
    } else {
        *(s16 *)((u8 *)st + 0x15C) = (s16)(*(s16 *)((u8 *)st + 0x15C) + 4);
        if (*(s16 *)((u8 *)st + 0x15C) > *(s16 *)((u8 *)st + 0x154))
            *(s16 *)((u8 *)st + 0x15C) = *(s16 *)((u8 *)st + 0x154);
        *(s16 *)((u8 *)st + 0x15E) = (s16)(*(s16 *)((u8 *)st + 0x15E) - 0x10);
        if (*(s16 *)((u8 *)st + 0x15E) < 0)
            *(s16 *)((u8 *)st + 0x15E) = 0;
    }

    if (*(s16 *)((u8 *)st + 0x34) > *(s16 *)((u8 *)st + 0x36)) {
        *(s16 *)((u8 *)st + 0x34) = (s16)(*(s16 *)((u8 *)st + 0x34) - 0x18);
        if (*(s16 *)((u8 *)st + 0x34) < *(s16 *)((u8 *)st + 0x36))
            *(s16 *)((u8 *)st + 0x34) = *(s16 *)((u8 *)st + 0x36);
    }
    if (*(s16 *)((u8 *)st + 0x34) < *(s16 *)((u8 *)st + 0x36)) {
        *(s16 *)((u8 *)st + 0x34) = (s16)(*(s16 *)((u8 *)st + 0x34) + 0x18);
        if (*(s16 *)((u8 *)st + 0x34) > *(s16 *)((u8 *)st + 0x36))
            *(s16 *)((u8 *)st + 0x34) = *(s16 *)((u8 *)st + 0x36);
    }

    if (*(s32 *)((u8 *)st + 0x20) >= 0) {
        if (*(s32 *)((u8 *)st + 0x20) == 0)
            Fx_StartSlot(0, lbl_80298040[*(s32 *)((u8 *)st + 0x28)], 0x64, 1);
        *(s32 *)((u8 *)st + 0x20) = *(s32 *)((u8 *)st + 0x20) - 1;
    }

    if (*(s16 *)((u8 *)st + 0x36) != 0) {
        if (trig & 0x100) {
            if (*(s32 *)((u8 *)st + 0x20) < 0) {
                *(s32 *)((u8 *)st + 0x10) = *(s32 *)((u8 *)st + 0x10) + 1;
                if (*(s32 *)((u8 *)st + 0x10) > *(s32 *)((u8 *)st + 8) - 1)
                    *(s32 *)((u8 *)st + 0x10) = 0;
                if (*(void **)((u8 *)st + 0x30) != NULL && Sound_FindByName(*(void **)((u8 *)st + 0x30)) != NULL) {
                    Sound_FindByName(*(void **)((u8 *)st + 0x30));
                    Process_Unlink();
                }
                *(void **)((u8 *)st + 0x30) = *(void **)((u8 *)st + 0x2C);
                off = *(s32 *)((u8 *)st + 0x10) << 3;
                *(void **)((u8 *)st + 0x2C) = *(void **)(*(u8 **)((u8 *)st + 0xC) + off);
                p = Sound_FindByName(*(void **)((u8 *)st + 0x30));
                fn_80109BB4(p, 0x40);
                *(f32 *)((u8 *)p + 0x48) = lbl_8036B374;
                q = Sound_Create(*(void **)((u8 *)st + 0x2C), 0);
                Sound_FadeFromZero(q, 0x40);
                row = (s16 *)(*(u8 **)((u8 *)st + 0xC) + off);
                y = (f32)row[3];
                x = (f32)row[2];
                q = Sound_FindByName(*(void **)((u8 *)st + 0x2C));
                *(f32 *)((u8 *)q + 0x40) = x;
                *(f32 *)((u8 *)q + 0x44) = y;
                *(f32 *)((u8 *)q + 0x48) = lbl_8036B380;
                if (Fx_FindSlotByName(lbl_80298040[*(s32 *)((u8 *)st + 0x24)]) == -1) {
                    flag = 0;
                    if ((gFxChannels[0xC] & 1) && ((Obj *)gFxChannels)->v2() != 0)
                        flag = 1;
                    if (flag)
                        fn_80148980(gFxChannels, 0x64);
                    *(s32 *)((u8 *)st + 0x20) = 0xA;
                    *(s32 *)((u8 *)st + 0x28) = *(s32 *)((u8 *)st + 0x24);
                }
            }
        } else if (trig & 0x200) {
            fn_80147188(0xFA);
            if (*(s32 *)((u8 *)st + 0x28) != -1) {
                *(s32 *)((u8 *)st + 0x20) = -1;
                *(s32 *)((u8 *)st + 0x28) = -1;
            } else {
                Ui_PlaySeCue(lbl_8027D030 + 0x3F2, 0x64);
                Process_ClearFunc(self);
            }
        } else if (trig & 0x400) {
            *(s16 *)((u8 *)st + 0x36) = 0;
        } else {
            if (held & 0x08000008) {
                *(s32 *)((u8 *)st + 0x24) = *(s32 *)((u8 *)st + 0x24) - 1;
                if (*(s32 *)((u8 *)st + 0x24) < 0)
                    *(s32 *)((u8 *)st + 0x24) = 0;
                t = *(s32 *)((u8 *)st + 0x13C);
                if (*(s32 *)((u8 *)st + 0x24) - t <= 0 && t > 0) {
                    *(s32 *)((u8 *)st + 0x13C) = t - 1;
                    *(f32 *)((u8 *)st + 0x140) = lbl_8036B384;
                }
            }
            if (held & 0x04000004) {
                *(s32 *)((u8 *)st + 0x24) = *(s32 *)((u8 *)st + 0x24) + 1;
                if (*(s32 *)((u8 *)st + 0x24) >= 0x40)
                    *(s32 *)((u8 *)st + 0x24) = 0x3F;
                t = *(s32 *)((u8 *)st + 0x13C);
                if (*(s32 *)((u8 *)st + 0x24) - t >= 6 && t < 0x39) {
                    *(s32 *)((u8 *)st + 0x13C) = t + 1;
                    *(f32 *)((u8 *)st + 0x140) = lbl_8036B388;
                }
            }
            if (old24 != *(s32 *)((u8 *)st + 0x24)) {
                *(s16 *)((u8 *)st + 0x148) = 4;
                *(s16 *)((u8 *)st + 0x14A) = *(s16 *)((u8 *)st + 0x144);
                *(s16 *)((u8 *)st + 0x14C) = *(s16 *)((u8 *)st + 0x146);
                *(s16 *)((u8 *)st + 0x14E) = (s16)(*(s16 *)((u8 *)st + 0x152) + 0x16);
                *(s16 *)((u8 *)st + 0x150) = (s16)(*(s16 *)((u8 *)st + 0x154) + (*(s32 *)((u8 *)st + 0x24) - *(s32 *)((u8 *)st + 0x13C)) * 0x1C + 0x16);
            }
        }
    } else if ((trig & 0x100) || (trig & 0x02000002)) {
        *(s32 *)((u8 *)st + 0x10) = *(s32 *)((u8 *)st + 0x10) + 1;
        if (*(s32 *)((u8 *)st + 0x10) > *(s32 *)((u8 *)st + 8) - 1)
            *(s32 *)((u8 *)st + 0x10) = 0;
        if (*(void **)((u8 *)st + 0x30) != NULL && Sound_FindByName(*(void **)((u8 *)st + 0x30)) != NULL) {
            Sound_FindByName(*(void **)((u8 *)st + 0x30));
            Process_Unlink();
        }
        *(void **)((u8 *)st + 0x30) = *(void **)((u8 *)st + 0x2C);
        off = *(s32 *)((u8 *)st + 0x10) << 3;
        *(void **)((u8 *)st + 0x2C) = *(void **)(*(u8 **)((u8 *)st + 0xC) + off);
        p = Sound_FindByName(*(void **)((u8 *)st + 0x30));
        fn_80109BB4(p, 0x40);
        *(f32 *)((u8 *)p + 0x48) = lbl_8036B374;
        q = Sound_Create(*(void **)((u8 *)st + 0x2C), 0);
        Sound_FadeFromZero(q, 0x40);
        row = (s16 *)(*(u8 **)((u8 *)st + 0xC) + off);
        y = (f32)row[3];
        x = (f32)row[2];
        q = Sound_FindByName(*(void **)((u8 *)st + 0x2C));
        *(f32 *)((u8 *)q + 0x40) = x;
        *(f32 *)((u8 *)q + 0x44) = y;
        *(f32 *)((u8 *)q + 0x48) = lbl_8036B380;
    } else if (trig & 0x01000001) {
        *(s32 *)((u8 *)st + 0x10) = *(s32 *)((u8 *)st + 0x10) - 1;
        if (*(s32 *)((u8 *)st + 0x10) < 0)
            *(s32 *)((u8 *)st + 0x10) = *(s32 *)((u8 *)st + 8) - 1;
        if (*(void **)((u8 *)st + 0x30) != NULL && Sound_FindByName(*(void **)((u8 *)st + 0x30)) != NULL) {
            Sound_FindByName(*(void **)((u8 *)st + 0x30));
            Process_Unlink();
        }
        *(void **)((u8 *)st + 0x30) = *(void **)((u8 *)st + 0x2C);
        off = *(s32 *)((u8 *)st + 0x10) << 3;
        *(void **)((u8 *)st + 0x2C) = *(void **)(*(u8 **)((u8 *)st + 0xC) + off);
        p = Sound_FindByName(*(void **)((u8 *)st + 0x30));
        fn_80109BB4(p, 0x40);
        *(f32 *)((u8 *)p + 0x48) = lbl_8036B374;
        q = Sound_Create(*(void **)((u8 *)st + 0x2C), 0);
        Sound_FadeFromZero(q, 0x40);
        row = (s16 *)(*(u8 **)((u8 *)st + 0xC) + off);
        y = (f32)row[3];
        x = (f32)row[2];
        q = Sound_FindByName(*(void **)((u8 *)st + 0x2C));
        *(f32 *)((u8 *)q + 0x40) = x;
        *(f32 *)((u8 *)q + 0x44) = y;
        *(f32 *)((u8 *)q + 0x48) = lbl_8036B380;
    } else if ((trig & 0x200) || (trig & 0x400) || (trig & 0x1000)) {
        *(s16 *)((u8 *)st + 0x36) = 0xFF;
    }
}
#pragma cplusplus reset

void fn_801C32D4(s32 arg0) {
    extern u8 lbl_8027D030[];
    s32 FileCache_GetFlags(void *);
    s32 fn_80161FB8(void);
    void fn_80162054(void);
    void Process_ClearFunc(s32);

    if (FileCache_GetFlags(lbl_8027D030 + 0x402) & 0x2000) {
        if (fn_80161FB8() != 0) {
            fn_80162054();
            Process_ClearFunc(arg0);
        }
    }
}

#pragma opt_common_subs off
void Ui_InitScrollListPanel(void *arg0) {
    /* Initialize scroll-list panel: clear state, load script, build texture paths, size list. */
    void *memset(void *, int, u32);
    s32 Archive_Load();
    void Sound_Create(u32, void *);
    u32 Sound_FindByName(u32);
    void fn_80147188(s32);
    void *Heap_Alloc(s32);
    void fn_80057998(void *);
    void fn_80057898(void *, s32);
    void fn_80057880(void *, s32);
    void ScrollBar_RecreateArrows(void *, s32);
    void strcpy(char *, char *);
    void strcat(char *, char *);
    char *Msg_Expand(char *);
    void fn_8006EEFC(void *, char *);
    void fn_80162018(void);
    extern char lbl_8027D030[];
    extern u8 lbl_802981AC[];
    extern const f32 lbl_8036B374, lbl_8036B380;
    u8 *panel = *(u8 **)((u8 *)arg0+0x30);
    u8 *entry;
    s32 off;
    f32 x, y;
    memset(panel+0x14, 0xFFFF, 12);
    *(s32 *)(panel+32)=-1;
    *(s32 *)(panel+36)=0;
    *(s32 *)(panel+40)=-1;
    *(s16 *)(panel+52)=255;
    *(s16 *)(panel+54)=255;
    *(s32 *)(panel+316)=0;
    *(f32 *)(panel+320)=lbl_8036B374;
    *(s16 *)(panel+324)=-100;
    *(s16 *)(panel+326)=-100;
    *(s16 *)(panel+338)=108;
    *(s16 *)(panel+340)=152;
    *(s16 *)(panel+342)=392;
    *(s16 *)(panel+344)=240;
    *(s16 *)(panel+350)=0;
    *(s32 *)(panel+4)=Archive_Load(lbl_8027D030+0x417);
    entry=*(u8 **)(panel+4);
    *(s32 *)(panel+8)=*(s32 *)entry;
    *(u8 **)(panel+12)=entry+4;
    *(s32 *)(panel+16)=0;
    off=*(s32 *)(panel+16)*8;
    Sound_Create(*(u32 *)(*(u8 **)(panel+12)+off),arg0);
    *(u32 *)(panel+44)=*(u32 *)(*(u8 **)(panel+12)+off);
    entry=*(u8 **)(panel+12)+off;
    y=*(s16 *)(entry+6);
    x=*(s16 *)(entry+4);
    entry=(u8 *)Sound_FindByName(*(u32 *)(panel+44));
    *(f32 *)(entry+64)=x; *(f32 *)(entry+68)=y; *(f32 *)(entry+72)=lbl_8036B380;
    *(s32 *)(panel+48)=0;
    fn_80147188(0);
    entry=Heap_Alloc(48);
    if(entry){fn_80057998(entry);*(void **)(entry+44)=lbl_802981AC;}
    *(u8 **)(panel+56)=entry;
    fn_80057898(*(void **)(panel+56),64);
    fn_80057880(*(void **)(panel+56),7);
    ScrollBar_RecreateArrows(*(void **)(panel+56),1);
    strcpy((char *)panel+60,lbl_8027D030+0x425);
    strcat((char *)panel+60,Msg_Expand(lbl_8027D030+1067));
    strcat((char *)panel+60,lbl_8027D030+1078);
    strcat((char *)panel+60,Msg_Expand(lbl_8027D030+1085));
    strcat((char *)panel+60,lbl_8027D030+1094);
    strcat((char *)panel+60,Msg_Expand(lbl_8027D030+1101));
    strcat((char *)panel+60,lbl_8027D030+1109);
    strcat((char *)panel+60,Msg_Expand(lbl_8027D030+1116));
    strcpy((char *)panel+188,lbl_8027D030+0x425);
    strcat((char *)panel+188,Msg_Expand(lbl_8027D030+1067));
    strcat((char *)panel+188,lbl_8027D030+1078);
    strcat((char *)panel+188,Msg_Expand(lbl_8027D030+1085));
    strcat((char *)panel+188,lbl_8027D030+1094);
    strcat((char *)panel+188,Msg_Expand(lbl_8027D030+1125));
    strcat((char *)panel+188,lbl_8027D030+1109);
    strcat((char *)panel+188,Msg_Expand(lbl_8027D030+1116));
    fn_8006EEFC(panel,lbl_8027D030+0x402);
    fn_80162018();
    *(s16 *)(panel+0x148)=4;
    *(s16 *)(panel+0x14a)=*(s16 *)(panel+0x144);
    *(s16 *)(panel+0x14c)=*(s16 *)(panel+0x146);
    *(s16 *)(panel+0x14e)=*(s16 *)(panel+0x152)+22;
    *(s16 *)(panel+0x150)=(*(s32 *)(panel+0x24)-*(s32 *)(panel+0x13c))*28+(*(s16 *)(panel+0x154)+22);
    *(s16 *)(panel+0x148)=0;
    *(s16 *)(panel+0x144)=*(s16 *)(panel+0x14e);
    *(s16 *)(panel+0x146)=*(s16 *)(panel+0x150);
}

#pragma use_lmw_stmw on
void fn_801C36E8(void *arg0) {
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetColorByte(u8);
    void Prim2D_ClearCallbacks(void);
    void Prim2D_SetCallback(void (*)(s32, s16 *), s16 *);
    void Prim2D_AddZ(f32);
    void Prim2D_BindTexture(void *, s32, s32);
    void Prim2D_SetTex(s32, s32);
    void *Msg_Expand(void *);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, ...);
    void **fn_8006EDD8(void *, s32);
    s32 *Ui_GetColor(s32);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetColor(u8, u8, u8, s32);
    void Prim2D_EmitQuad(void);
    void Prim2D_EndPrim(void);
    void strcpy(char *, char *);
    void strcat(char *, char *);
    void fn_8015E848(s16, s16, s16, s16, s32 *, s32);
    void fn_80152010(s16, s16, s32, s32, s32);
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    void Ui_DrawCaptionBar(void *, s32);
    void fn_800578A8(void *, s32, s32, s32);
    void fn_80057860(void *, s32);
    void fn_80057020(void *);
    void fn_801C4394(s32, s16 *);
    s64 OSGetTime(void);
    s64 __div2i(s64, s64);
    s64 __mod2i(s64, s64);
    f32 fn_8022CB78(s64);
    f64 sin(f32);
    extern s8 lbl_80368288;
    extern s8 lbl_80368294;
    extern s16 lbl_8036828C[4];
    extern s16 lbl_80368298[4];
    extern char lbl_8027D030[];
    extern char *lbl_80298040[];
    extern f32 lbl_8036B370;
    extern f32 lbl_8036B374;
    extern f32 lbl_8036B37C;
    extern f32 lbl_8036B384;
    extern f32 lbl_8036B388;
    extern f64 lbl_8036B390;
    extern f32 lbl_8036B398;
    extern f32 lbl_8036B39C;
    extern f32 lbl_8036B3A0;
    extern f32 lbl_8036B3A4;
    extern f32 lbl_8036B3A8;
    extern f32 lbl_8036B3AC;
    extern f32 lbl_8036B3B0;
    extern f32 lbl_8036B3B4;
    extern f32 lbl_8036B3B8;
    extern f32 lbl_8036B3BC;
    extern f32 lbl_8036B3C0;
    extern f32 lbl_8036B3C4;
    extern f32 lbl_8036B3C8;
    extern f32 lbl_8036B3CC;
    extern f32 lbl_8036B3D0;
    extern f64 lbl_8036B3D8;

    char buf[0x60];
    s32 frameCol;
    u8 color[4];
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    s32 i;
    s32 idx;
    u16 tw;
    u16 th;
    s16 x;
    s16 y;
    void *self;

    self = *(void **)((u8 *)arg0 + 0x30);
    if ((s8)lbl_80368288 == 0) {
        lbl_80368288 = 1;
    }
    if ((s8)lbl_80368294 == 0) {
        lbl_80368294 = 1;
    }

    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B374, lbl_8036B374, lbl_8036B398, lbl_8036B388);
    Prim2D_SetColorByte((u8)*(s16 *)((u8 *)self + 0x34));
    Prim2D_PrepareTex();

    *(s32 *)color = *Ui_GetColor(1);
    {
        u16 *dims = (u16 *)*fn_8006EDD8(*(void **)((u8 *)self + 0), 2);
        th = dims[1];
        tw = dims[0];
    }
    Prim2D_Begin();
    Prim2D_BindTexture(*(void **)((u8 *)self + 0), 2, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B374, lbl_8036B39C, lbl_8036B374, lbl_8036B374);
    a = lbl_8036B374 + (f32)th;
    Prim2D_SetQuadMax(a, lbl_8036B39C + (f32)tw, a, lbl_8036B374 + (f32)tw);
    Prim2D_SetColor(color[0], color[1], color[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    *(s32 *)color = *Ui_GetColor(1);
    {
        u16 *dims = (u16 *)*fn_8006EDD8(*(void **)((u8 *)self + 0), 2);
        th = dims[1];
        tw = dims[0];
    }
    Prim2D_Begin();
    Prim2D_BindTexture(*(void **)((u8 *)self + 0), 2, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B3A0, lbl_8036B39C, lbl_8036B374 + (f32)th, lbl_8036B374);
    Prim2D_SetQuadMax(lbl_8036B3A0 + (f32)th, lbl_8036B39C + (f32)tw, lbl_8036B374, lbl_8036B374 + (f32)tw);
    Prim2D_SetColor(color[0], color[1], color[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B384);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    fn_8001003C(0xB4, 0x3D, 2, 0, 0, Msg_Expand(lbl_8027D030 + 0x46E), lbl_8036B388, lbl_8036B374);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B384);
    Prim2D_PrepareTex();

    *(s32 *)color = *Ui_GetColor(1);
    {
        u16 *dims = (u16 *)*fn_8006EDD8(*(void **)((u8 *)self + 0), 0);
        th = dims[1];
        tw = dims[0];
    }
    Prim2D_Begin();
    Prim2D_BindTexture(*(void **)((u8 *)self + 0), 0, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B3A4, lbl_8036B3A8, lbl_8036B374, lbl_8036B374);
    Prim2D_SetQuadMax(lbl_8036B3A4 + (f32)th, lbl_8036B3A8 + (f32)tw, lbl_8036B374 + (f32)th, lbl_8036B374 + (f32)tw);
    Prim2D_SetColor(color[0], color[1], color[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B384);
    Prim2D_PrepareTex();

    *(s32 *)color = *Ui_GetColor(1);
    {
        u16 *dims = (u16 *)*fn_8006EDD8(*(void **)((u8 *)self + 0), 1);
        th = dims[1];
        tw = dims[0];
    }
    Prim2D_Begin();
    Prim2D_BindTexture(*(void **)((u8 *)self + 0), 1, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B3AC, lbl_8036B3B0, lbl_8036B374, lbl_8036B374);
    Prim2D_SetQuadMax(lbl_8036B3AC + (f32)th, lbl_8036B3B0 + (f32)tw, lbl_8036B374 + (f32)th, lbl_8036B374 + (f32)tw);
    Prim2D_SetColor(color[0], color[1], color[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B3B4);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B3B8);
    Prim2D_SetColorByte((u8)((*(s16 *)((u8 *)self + 0x34) * *(s16 *)((u8 *)self + 0x15E)) / 255));
    Prim2D_PrepareTex();

    {
        s16 t6 = *(s16 *)((u8 *)self + 0x15C);
        lbl_8036828C[0] = *(s16 *)((u8 *)self + 0x15A);
        lbl_8036828C[1] = t6;
        lbl_8036828C[2] = 0x170;
        lbl_8036828C[3] = (s16)(*(s16 *)((u8 *)self + 0x154) - t6);
    }
    Prim2D_Begin();
    Prim2D_SetCallback(fn_801C4394, lbl_8036828C);
    Prim2D_PrepareTex();

    b = (f32)*(s16 *)((u8 *)self + 0x15C);
    a = (f32)*(s16 *)((u8 *)self + 0x15A);
    *(s32 *)color = *Ui_GetColor(1);
    {
        u16 *dims = (u16 *)*fn_8006EDD8(*(void **)((u8 *)self + 0), 3);
        th = dims[1];
        tw = dims[0];
    }
    Prim2D_Begin();
    Prim2D_BindTexture(*(void **)((u8 *)self + 0), 3, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(a, b, lbl_8036B374, lbl_8036B374);
    Prim2D_SetQuadMax(a + (f32)th, b + (f32)tw, lbl_8036B374 + (f32)th, lbl_8036B374 + (f32)tw);
    Prim2D_SetColor(color[0], color[1], color[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    b = (f32)*(s16 *)((u8 *)self + 0x15C);
    a = (f32)(*(s16 *)((u8 *)self + 0x15A) + 0xB8);
    *(s32 *)color = *Ui_GetColor(1);
    {
        u16 *dims = (u16 *)*fn_8006EDD8(*(void **)((u8 *)self + 0), 3);
        th = dims[1];
        tw = dims[0];
    }
    Prim2D_Begin();
    Prim2D_BindTexture(*(void **)((u8 *)self + 0), 3, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(a, b, lbl_8036B374 + (f32)th, lbl_8036B374);
    Prim2D_SetQuadMax(a + (f32)th, b + (f32)tw, lbl_8036B374, lbl_8036B374 + (f32)tw);
    Prim2D_SetColor(color[0], color[1], color[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    if (*(s32 *)((u8 *)self + 0x28) != -1) {
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B384);
        Prim2D_PrepareTex();
        strcpy(buf, lbl_8027D030 + 0x47E);
        strcat(buf, lbl_80298040[*(s32 *)((u8 *)self + 0x28)]);
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        x = (s16)(*(s16 *)((u8 *)self + 0x15A) + 0x16);
        y = (s16)(*(s16 *)((u8 *)self + 0x15C) + 4);
        fn_8001003C(x, y, 1, 1, 0, lbl_8027D030 + 0x483, lbl_8036B388, lbl_8036B374, *(s32 *)((u8 *)self + 0x28) + 1);
        fn_8001003C((s16)(x + 0x24), y, 1, 1, 0, Msg_Expand(buf), lbl_8036B388, lbl_8036B374);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B388);
        Prim2D_PrepareTex();
    }

    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B3BC);
    Prim2D_SetColorByte((u8)*(s16 *)((u8 *)self + 0x34));
    Prim2D_PrepareTex();
    frameCol = *(s32 *)&lbl_8036B370;
    fn_8015E848(*(s16 *)((u8 *)self + 0x152), *(s16 *)((u8 *)self + 0x154), *(s16 *)((u8 *)self + 0x156), *(s16 *)((u8 *)self + 0x158), &frameCol, 0x10);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B3B8);
    Prim2D_PrepareTex();

    {
        s16 t4 = *(s16 *)((u8 *)self + 0x152);
        s16 t5 = (s16)(*(s16 *)((u8 *)self + 0x154) + 0x16);
        s16 t6 = (s16)(*(s16 *)((u8 *)self + 0x156) - 0x28);
        s16 t7 = (s16)(*(s16 *)((u8 *)self + 0x158) - 0x2C);
        lbl_80368298[0] = (s16)(t4 + 8);
        lbl_80368298[1] = t5;
        lbl_80368298[2] = t6;
        lbl_80368298[3] = t7;
    }
    Prim2D_Begin();
    Prim2D_SetCallback(fn_801C4394, lbl_80368298);
    Prim2D_PrepareTex();

    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();

    for (i = 0; i < 9; i++) {
        idx = *(s32 *)((u8 *)self + 0x13C) + (i - 1);
        if (idx >= 0 && idx < 0x40) {
            strcpy(buf, lbl_8027D030 + 0x47E);
            strcat(buf, lbl_80298040[idx]);
            x = (s16)(*(s16 *)((u8 *)self + 0x152) + 0x1C);
            y = (s16)((lbl_8036B3C0 * *(f32 *)((u8 *)self + 0x140)) + (f32)(*(s16 *)((u8 *)self + 0x154) + ((i - 1) * 0x1C) + 0x16));
            fn_8001003C(x, y, 1, 1, 0, lbl_8027D030 + 0x483, lbl_8036B388, lbl_8036B374, idx + 1);
            fn_8001003C((s16)(x + 0x24), y, 1, 1, 0, Msg_Expand(buf), lbl_8036B388, lbl_8036B374);
            Prim2D_Begin();
            Prim2D_AddZ(lbl_8036B388);
            Prim2D_PrepareTex();
            fn_80152010((s16)(x - 8), (s16)(y + 0xC), 0x154, 0x4B, 0x10);
            Prim2D_Begin();
            Prim2D_AddZ(lbl_8036B384);
            Prim2D_PrepareTex();
        }
    }

    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B3BC);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B384);
    Prim2D_PrepareTex();
    fn_8008AB7C(*(s16 *)((u8 *)self + 0x144) + 0xA8, *(s16 *)((u8 *)self + 0x146) + 0xE, 0x164, 0x17, 0x19, 0x64, 1);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B3C4);
    Prim2D_PrepareTex();

    c = fn_8022CB78(__mod2i(__div2i(OSGetTime(), (s64)((*(u32 *)0x800000F8 >> 2) / 1000)), 0x7D0)) / lbl_8036B3C8;
    d = lbl_8036B37C * (f32)sin(lbl_8036B3CC * (lbl_8036B3BC * c));
    b = (f32)(*(s16 *)((u8 *)self + 0x146) - 8) + d;
    a = (f32)(*(s16 *)((u8 *)self + 0x144) - 0x24);
    *(s32 *)color = *Ui_GetColor(1);
    {
        u16 *dims = (u16 *)*fn_8006EDD8(*(void **)((u8 *)self + 0), 4);
        th = dims[1];
        tw = dims[0];
    }
    Prim2D_Begin();
    Prim2D_BindTexture(*(void **)((u8 *)self + 0), 4, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(a, b, lbl_8036B374, lbl_8036B374);
    Prim2D_SetQuadMax(a + (f32)th, b + (f32)tw, lbl_8036B374 + (f32)th, lbl_8036B374 + (f32)tw);
    Prim2D_SetColor(color[0], color[1], color[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B3D0);
    Prim2D_PrepareTex();
    if (*(s32 *)((u8 *)self + 0x28) == -1) {
        Ui_DrawCaptionBar((u8 *)self + 0x3C, 0);
    } else {
        Ui_DrawCaptionBar((u8 *)self + 0xBC, 0);
    }
    fn_800578A8(*(void **)((u8 *)self + 0x38), *(s16 *)((u8 *)self + 0x152) + 0x172, *(s16 *)((u8 *)self + 0x154) + 0x10, 0xD0);
    fn_80057860(*(void **)((u8 *)self + 0x38), *(s32 *)((u8 *)self + 0x13C));
    fn_80057020(*(void **)((u8 *)self + 0x38));
    Prim2D_Begin();
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();
}

#pragma opt_common_subs on
void fn_801C4394(s32 unused, s16 *p) {
    extern void GXSetScissor(s16, s16, s16, s16);
    GXSetScissor(p[0], p[1], p[2], p[3]);
}

void *fn_801C43C8(void *arg0, s16 arg1) {
    void fn_800578F0(void *, s16);
    void Heap_Free(void *);
    extern u8 lbl_802981AC[];
    if (arg0 != NULL) {
        *(void **)((char *)arg0 + 0x2C) = lbl_802981AC;
        fn_800578F0(arg0, 0);
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

s32 fn_801C4428(void) {
    return 3;
}

s32 fn_801C4430(void) {
    return 4;
}

s32 fn_801C4438(void) {
    return 5;
}

extern u8 lbl_8029824C[];
void fn_801C4440(void){extern u8 lbl_8029824C[];void Process_UnlinkByKey(void*);Process_UnlinkByKey(lbl_8029824C);}

void fn_801C4468(s32 arg0) {
    void *Process_Create(void *, s32);
    M2C_FIELD(Process_Create(&lbl_8029824C, 4), s32 *, 0x3C) = arg0;
}

#pragma optimization_level 3
void fn_801C44A4(void *arg0) {
    void fn_800616A0();
    void fn_800C426C(void *);
    void fn_800C428C(void *);
    s32 i;
    s32 offset;
    void *work;
    void *ptr;

    i = 0;
    offset = i;
    do {
        work = *(void **)((u8 *)arg0 + 0x44);
        fn_800616A0((u8 *)*(void **)work + offset + 8, work);
        i += 1;
        offset += 0xA8;
    } while (i < 0x10);
    fn_800616A0(*(void **)((u8 *)arg0 + 0x40));
    work = *(void **)((u8 *)arg0 + 0x44);
    if (work != NULL) {
        ptr = *(void **)work;
        if (ptr != NULL) {
            if (ptr != NULL) {
                fn_800C426C((u8 *)ptr - 0x10);
            }
            *(void **)work = NULL;
        }
        ptr = *(void **)((u8 *)work + 4);
        if (ptr != NULL) {
            fn_800C426C(ptr);
            *(void **)((u8 *)work + 4) = NULL;
        }
        fn_800C428C(work);
        *(void **)((u8 *)arg0 + 0x44) = NULL;
    }
}
#pragma optimization_level reset
void fn_801C4564(void) { M2C_UNK fn_801C45A4(); fn_801C45A4(); }

void fn_801C4584(void){ void fn_801C5B80(void); fn_801C5B80(); /*try*/ }

void fn_801C45A4(void *arg0) {
    u32 Rand_Next(void);
    f32 Math_Lerp(f32, f32, f32, f32);
    void fn_8005FEE8(void *, f32);
    void fn_80060060(void *);
    void fn_800606BC(void *);
    void fn_80060F70(void *, s32, void *);
    s32 GActor_FindNode(void *, char *);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXRotRad(void *, s32, f32, f32, f32, f32);
    void PSMTXTrans(void *, f32, f32, f32);
    void PSMTXScale(void *, f32, f32, f32);
    extern u8 lbl_8027D594[];
    extern f32 lbl_8036B40C;
    extern f32 lbl_8036B410;
    extern f32 lbl_8036B414;
    extern f32 lbl_8036B418;
    extern f32 lbl_8036B41C;
    extern f32 lbl_8036B420;
    extern f32 lbl_8036B424;
    extern f32 lbl_8036B428;
    extern f32 lbl_8036B42C;
    extern f32 lbl_8036B430;
    extern f32 lbl_8036B434;
    extern f32 lbl_8036B438;

    f32 mtxA[12];
    f32 mtxB[12];
    f32 mtxC[12];
    f32 mtxD[12];
    f32 sp104[3];
    f32 spF8[3];
    f32 spEC[3];
    f32 spE0[3];
    f32 spD4[3];
    f32 spC8[3];
    f32 spBC[3];
    f32 sp5C[3];
    void *self;
    void *list;
    void *n;
    void *prev;
    void *node;
    void *entry;
    s32 id;
    s32 id2;
    s32 id3;
    s32 id4;
    s32 id5;
    f32 f31, f30, f29, ftmp;

    self = arg0;
    if (*(u8 *)((u8 *)*(void **)((u8 *)self + 0x3C) + 0xB) == 0xFF
        && (*(s32 *)((u8 *)self + 0x30) % 6) == 0) {
        id = GActor_FindNode(*(void **)((u8 *)self + 0x3C), (char *)lbl_8027D594 + 0x127);
        if (id >= 0) {
            fn_80060F70(*(void **)((u8 *)self + 0x3C), id, sp104);
            if (sp104[1] < lbl_8036B40C) {
                list = *(void **)((u8 *)self + 0x44);
                n = **(void ***)((u8 *)list + 8);
                spBC[0] = sp104[0];
                spBC[1] = sp104[1];
                spBC[2] = sp104[2];
                if (n == NULL) {
                    n = NULL;
                } else {
                    *(void **)((u8 *)n + 4) = *(void **)((u8 *)list + 0x10);
                    *(void **)n = NULL;
                    prev = *(void **)((u8 *)list + 0x10);
                    if (prev != NULL) {
                        *(void **)prev = n;
                    }
                    if (*(void **)((u8 *)list + 0xC) == NULL) {
                        *(void **)((u8 *)list + 0xC) = n;
                    }
                    *(void **)((u8 *)list + 0x10) = n;
                    *(u8 **)((u8 *)list + 8) = *(u8 **)((u8 *)list + 8) + 4;
                    *(s32 *)((u8 *)list + 0x14) = *(s32 *)((u8 *)list + 0x14) + 1;
                }
                if (n != NULL) {
                    entry = (u8 *)n + 8;
                    sp5C[0] = spBC[0];
                    sp5C[1] = spBC[1];
                    sp5C[2] = spBC[2];
                    f31 = Math_Lerp(lbl_8036B410, lbl_8036B414, lbl_8036B418, (f32)(Rand_Next() % 1000));
                    f30 = Math_Lerp(lbl_8036B410, lbl_8036B414, lbl_8036B418, (f32)(Rand_Next() % 1000));
                    f29 = Math_Lerp(lbl_8036B41C, lbl_8036B420, lbl_8036B418, (f32)(Rand_Next() % 1000));
                    ftmp = lbl_8036B430 * Math_Lerp(lbl_8036B424, lbl_8036B428, lbl_8036B418, (f32)(Rand_Next() % 1000));
                    sp5C[0] = sp5C[0] + f31;
                    sp5C[1] = lbl_8036B42C;
                    sp5C[2] = sp5C[2] + f30;
                    PSMTXRotRad(mtxA, 0x59, ftmp, sp5C[2], lbl_8036B42C, sp5C[0]);
                    PSMTXScale(mtxB, f29, f29, f29);
                    PSMTXTrans(mtxC, sp5C[0], sp5C[1], sp5C[2]);
                    PSMTXConcat(mtxB, mtxA, mtxD);
                    PSMTXConcat(mtxC, mtxD, (u8 *)entry + 0x10);
                    fn_8005FEE8(entry, lbl_8036B424);
                }
            }
            id = GActor_FindNode(*(void **)((u8 *)self + 0x3C), (char *)lbl_8027D594 + 0xDE);
            id2 = GActor_FindNode(*(void **)((u8 *)self + 0x3C), (char *)lbl_8027D594 + 0xE4);
            id3 = GActor_FindNode(*(void **)((u8 *)self + 0x3C), (char *)lbl_8027D594 + 0xEA);
            id4 = GActor_FindNode(*(void **)((u8 *)self + 0x3C), (char *)lbl_8027D594 + 0xF1);
            id5 = GActor_FindNode(*(void **)((u8 *)self + 0x3C), (char *)lbl_8027D594 + 0xF8);
            if (id >= 0) {
                if (id2 < 0) {
                    goto done;
                }
                fn_80060F70(*(void **)((u8 *)self + 0x3C), id, spF8);
                fn_80060F70(*(void **)((u8 *)self + 0x3C), id2, spEC);
                fn_80060F70(*(void **)((u8 *)self + 0x3C), id3, spE0);
                fn_80060F70(*(void **)((u8 *)self + 0x3C), id4, spD4);
                fn_80060F70(*(void **)((u8 *)self + 0x3C), id5, spC8);
                *(s32 *)((u8 *)self + 0x34) = *(s32 *)((u8 *)self + 0x34) + 1;
            }
        }
    }
done:
    node = NULL;
    for (;;) {
        if (node == NULL) {
            node = *(void **)((u8 *)*(void **)((u8 *)self + 0x44) + 0xC);
        } else {
            node = *(void **)node;
        }
        if (node == NULL) {
            break;
        }
        entry = (u8 *)node + 8;
        fn_80060060(entry);
        fn_800606BC(entry);
        if ((u8)((((*(u32 *)((u8 *)node + 8)) >> 4) & 1) ^ 1) == 0) {
            list = *(void **)((u8 *)self + 0x44);
            if (node != NULL) {
                void *nx = *(void **)node;
                void *pv = *(void **)((u8 *)node + 4);
                if (nx != NULL) {
                    *(void **)((u8 *)nx + 4) = pv;
                }
                if (pv != NULL) {
                    *(void **)pv = nx;
                }
                if (node == *(void **)((u8 *)list + 0xC)) {
                    *(void **)((u8 *)list + 0xC) = nx;
                }
                if (node == *(void **)((u8 *)list + 0x10)) {
                    *(void **)((u8 *)list + 0x10) = pv;
                }
                *(u8 **)((u8 *)list + 8) = *(u8 **)((u8 *)list + 8) - 4;
                *(s32 *)((u8 *)list + 0x14) = *(s32 *)((u8 *)list + 0x14) - 1;
                **(void ***)((u8 *)list + 8) = node;
            }
        }
    }
    *(s32 *)((u8 *)self + 0x30) = *(s32 *)((u8 *)self + 0x30) + 1;
}

#pragma use_lmw_stmw on
void fn_801C5B80(void *arg0) {
    void *Map_Get(void);
    s32 Str_Cmp(void *, void *);
    void fn_800056A0(s32);
    void *Heap_Alloc(s32);
    void *Heap_AllocRaw(s32);
    void *fn_8022C414(void *, void (*)(void *), void *, s32, s32);
    void DCFlushRange(void *, u32);
    void *GActor_Create(void);
    void sprintf(void *, void *, ...);
    void GActor_LoadGs(void *, void *);
    void GActor_LoadG(void *, void *);
    void fn_8005F5B4(void *, void *);
    void GActor_LoadTpl(void *, void *);
    void GActor_Finalize(void *);
    void fn_80061824(void *);
    void fn_801C7BF8(void *);
    extern u32 lbl_8036B3EC;
    extern u32 lbl_8036B3F0;
    extern u32 lbl_8036B3F4;
    extern u32 lbl_8036B3F8;
    extern u32 lbl_8036B3FC;
    extern u32 lbl_8036B400;
    extern u32 lbl_8036B404;
    extern u32 lbl_8036B408;
    extern u16 lbl_8027D594[];

    u32 sp24, sp20, sp1C, sp18, sp14, sp10, spC, sp8;
    char sp28[0x40];
    s32 i;
    s32 off;
    s32 tmp;
    void *self;
    void *ctrl;
    void *cam;
    void *pool;
    s32 count;
    s32 idx;
    u8 *tbl;
    s32 three;

    self = arg0;
    sp24 = lbl_8036B3EC;
    ((u8 *)self)[0x38] = ((u8 *)&sp24)[0];
    ((u8 *)self)[0x39] = ((u8 *)&sp24)[1];
    ((u8 *)self)[0x3A] = ((u8 *)&sp24)[2];
    ((u8 *)self)[0x3B] = ((u8 *)&sp24)[3];

    cam = Map_Get();
    if (cam != NULL) {
        tmp = (s32)((u8 *)cam + 0x3C);
        if (Str_Cmp((void *)tmp, (u8 *)lbl_8027D594 + 0x12C) == 0) {
            sp20 = lbl_8036B3F0;
            ((u8 *)self)[0x38] = ((u8 *)&sp20)[0];
            ((u8 *)self)[0x39] = ((u8 *)&sp20)[1];
            ((u8 *)self)[0x3A] = ((u8 *)&sp20)[2];
            ((u8 *)self)[0x3B] = ((u8 *)&sp20)[3];
        } else if (Str_Cmp((void *)tmp, (u8 *)lbl_8027D594 + 0x136) == 0) {
            sp1C = lbl_8036B3F4;
            ((u8 *)self)[0x38] = ((u8 *)&sp1C)[0];
            ((u8 *)self)[0x39] = ((u8 *)&sp1C)[1];
            ((u8 *)self)[0x3A] = ((u8 *)&sp1C)[2];
            ((u8 *)self)[0x3B] = ((u8 *)&sp1C)[3];
        } else if (Str_Cmp((void *)tmp, (u8 *)lbl_8027D594 + 0x140) == 0) {
            sp18 = lbl_8036B3F8;
            ((u8 *)self)[0x38] = ((u8 *)&sp18)[0];
            ((u8 *)self)[0x39] = ((u8 *)&sp18)[1];
            ((u8 *)self)[0x3A] = ((u8 *)&sp18)[2];
            ((u8 *)self)[0x3B] = ((u8 *)&sp18)[3];
        } else if (Str_Cmp((void *)tmp, (u8 *)lbl_8027D594 + 0x14A) == 0) {
            sp14 = lbl_8036B3FC;
            ((u8 *)self)[0x38] = ((u8 *)&sp14)[0];
            ((u8 *)self)[0x39] = ((u8 *)&sp14)[1];
            ((u8 *)self)[0x3A] = ((u8 *)&sp14)[2];
            ((u8 *)self)[0x3B] = ((u8 *)&sp14)[3];
        } else if (Str_Cmp((void *)tmp, (u8 *)lbl_8027D594 + 0x156) == 0) {
            sp10 = lbl_8036B400;
            ((u8 *)self)[0x38] = ((u8 *)&sp10)[0];
            ((u8 *)self)[0x39] = ((u8 *)&sp10)[1];
            ((u8 *)self)[0x3A] = ((u8 *)&sp10)[2];
            ((u8 *)self)[0x3B] = ((u8 *)&sp10)[3];
        } else if (Str_Cmp((void *)tmp, (u8 *)lbl_8027D594 + 0x162) == 0) {
            spC = lbl_8036B404;
            ((u8 *)self)[0x38] = ((u8 *)&spC)[0];
            ((u8 *)self)[0x39] = ((u8 *)&spC)[1];
            ((u8 *)self)[0x3A] = ((u8 *)&spC)[2];
            ((u8 *)self)[0x3B] = ((u8 *)&spC)[3];
        } else if (Str_Cmp((void *)tmp, (u8 *)lbl_8027D594 + 0x16E) == 0) {
            sp8 = lbl_8036B408;
            ((u8 *)self)[0x38] = ((u8 *)&sp8)[0];
            ((u8 *)self)[0x39] = ((u8 *)&sp8)[1];
            ((u8 *)self)[0x3A] = ((u8 *)&sp8)[2];
            ((u8 *)self)[0x3B] = ((u8 *)&sp8)[3];
        } else {
            fn_800056A0(0);
        }
    }

    pool = Heap_Alloc(0x1C);
    if (pool != NULL) {
        *(s32 *)((u8 *)pool + 0x0) = 0;
        *(s32 *)((u8 *)pool + 0x4) = 0;
        *(s32 *)((u8 *)pool + 0x8) = 0;
        *(s32 *)((u8 *)pool + 0x14) = 0;
        *(s32 *)((u8 *)pool + 0xC) = 0;
        *(s32 *)((u8 *)pool + 0x10) = 0;
    }
    *(void **)((u8 *)self + 0x44) = pool;
    ctrl = *(void **)((u8 *)self + 0x44);
    *(s32 *)((u8 *)ctrl + 0x18) = 0x10;
    count = *(s32 *)((u8 *)ctrl + 0x18);
    tmp = count * 0xA8;
    *(void **)((u8 *)ctrl + 0x0) = fn_8022C414(Heap_AllocRaw(tmp + 0x10), fn_801C7BF8, NULL, 0xA8, count);
    *(void **)((u8 *)ctrl + 0x4) = Heap_AllocRaw((*(s32 *)((u8 *)ctrl + 0x18) + 1) << 2);
    DCFlushRange(*(void **)((u8 *)ctrl + 0x0), (u32)tmp);
    DCFlushRange(*(void **)((u8 *)ctrl + 0x4), (u32)((*(s32 *)((u8 *)ctrl + 0x18) + 1) << 2));
    {
        s32 z = 0;
        *(s32 *)((u8 *)ctrl + 0x14) = z;
        i = z;
        off = z;
        idx = z;
    }
    while (i < *(s32 *)((u8 *)ctrl + 0x18)) {
        *(void **)((u8 *)*(void **)((u8 *)ctrl + 0x4) + idx) =
            (u8 *)*(void **)((u8 *)ctrl + 0x0) + off;
        i += 1;
        off += 0xA8;
        idx += 4;
    }
    {
        s32 n = *(s32 *)((u8 *)ctrl + 0x18);
        *(s32 *)((u8 *)*(void **)((u8 *)ctrl + 0x4) + (n << 2)) = 0;
    }
    *(void **)((u8 *)ctrl + 0x8) = *(void **)((u8 *)ctrl + 0x4);
    *(s32 *)((u8 *)ctrl + 0xC) = 0;
    *(s32 *)((u8 *)ctrl + 0x10) = 0;
    *(s32 *)((u8 *)self + 0x30) = 0;
    *(s32 *)((u8 *)self + 0x34) = 0;
    *(void **)((u8 *)self + 0x40) = GActor_Create();

    tbl = (u8 *)lbl_8027D594;
    sprintf(sp28, tbl + 0x17A, tbl + 0x18E, tbl + 0x194);
    GActor_LoadGs(*(void **)((u8 *)self + 0x40), sp28);
    tbl = (u8 *)lbl_8027D594;
    sprintf(sp28, tbl + 0x17A, tbl + 0x18E, tbl + 0x198);
    GActor_LoadG(*(void **)((u8 *)self + 0x40), sp28);
    tbl = (u8 *)lbl_8027D594;
    sprintf(sp28, tbl + 0x17A, tbl + 0x18E, tbl + 0x19B);
    fn_8005F5B4(*(void **)((u8 *)self + 0x40), sp28);
    tbl = (u8 *)lbl_8027D594;
    sprintf(sp28, tbl + 0x17A, tbl + 0x18E, tbl + 0x19F);
    GActor_LoadTpl(*(void **)((u8 *)self + 0x40), sp28);
    GActor_Finalize(*(void **)((u8 *)self + 0x40));

    i = 0;
    off = 0;
    three = 3;
    while (i < 0x10) {
        tmp = (s32)((u8 *)*(void **)(*(void **)((u8 *)self + 0x44)) + off + 8);
        fn_80061824((void *)tmp);
        *(void **)((u8 *)tmp + 4) = *(void **)((u8 *)self + 0x40);
        ((u8 *)tmp)[8] = ((u8 *)self)[0x38];
        ((u8 *)tmp)[9] = ((u8 *)self)[0x39];
        ((u8 *)tmp)[0xA] = ((u8 *)self)[0x3A];
        ((u8 *)tmp)[0xB] = ((u8 *)self)[0x3B];
        ((u8 *)tmp)[0x87] = (u8)three;
        GActor_Finalize((void *)tmp);
        i += 1;
        off += 0xA8;
    }
}
void fn_801C6008(s32 arg0) {
    extern u8 lbl_80298224[];
    M2C_FIELD(Process_Create(&lbl_80298224, 4), s32 *, 0x30) = arg0;
}

void fn_801C6044(void *arg0) {
    void Heap_FreeRaw(void *);
    void Heap_Free(void *);

    u8 *obj;
    u8 *data;
    void *ptr;

    obj = (u8 *)arg0;
    data = *(u8 **)(obj + 0x44);

    if (data != NULL) {
        ptr = *(void **)data;

        if (ptr != NULL) {
            if (ptr != NULL) {
                Heap_FreeRaw((u8 *)ptr - 0x10);
            }
            *(void **)data = NULL;
        }

        ptr = *(void **)(data + 4);

        if (ptr != NULL) {
            Heap_FreeRaw(ptr);
            *(void **)(data + 4) = NULL;
        }

        Heap_Free(data);
    }
    *(void **)(obj + 0x44) = NULL;
}

void fn_801C60C8(void) { int pad; void fn_801C6234(void); fn_801C6234(); }

void fn_801C60E8(void *arg0) {
    void *Heap_Alloc(s32);
    void *Heap_AllocRaw(s32);
    void *fn_8022C414(void *, void (*)(void *), void *, s32, s32);
    void fn_801C7C08(void *);
    void DCFlushRange(void *, u32);
#pragma cplusplus on
    struct Entry { u8 pad[0x1C]; };
    struct Pool {
        Entry *data;
        Entry **table, **cur;
        s32 a, b, used, count;
        void init() {
            data = 0; table = 0; cur = 0; used = 0; a = 0; b = 0;
        }
        void reset() {
            s32 i;
            used = 0;
            for (i = 0; i < count; i++) table[i] = &data[i];
            table[count] = 0;
            cur = table; a = 0; b = 0;
        }
        void allocate(s32 n) {
            s32 num;
            s32 bytes;
            count = n;
            num = count;
            bytes = num * sizeof(struct Entry);
            data = (struct Entry *)fn_8022C414(Heap_AllocRaw(bytes + 0x10), fn_801C7C08, 0, 0x1C, num);
            table = (struct Entry **)Heap_AllocRaw((count + 1) * 4);
            DCFlushRange(data, bytes);
            DCFlushRange(table, (count + 1) * 4);
            reset();
        }
    };
    struct Owner {
        u8 pad[0x34];
        f32 a,b,c,d;
        struct Pool *pool;
        void init() {
            struct Pool *p = (struct Pool *)Heap_Alloc(0x1C);
            if (p) p->init();
            pool = p;
            pool->allocate(16);
            a = 0.0f; b = 0.0f; c = 0.0f; d = 0.0f;
        }
    };
    ((Owner *)arg0)->init();
#pragma cplusplus reset
}

#pragma use_lmw_stmw on
void fn_801C6234(void *arg0) {
    s32 GActor_FindNode(void *, void *);
    void fn_80060F70(void *, s32, f32 *);
    void fn_80067708(s32, s32, void (*)(void), s32);
    void PSMTXConcat(void *, void *, void *);
    void fn_802029C4(void *, void *, void *);
    void fn_802031E8(f32 *, f32 *);
    f32 Vec_Length(f32 *);
    f32 fn_80203270(f32 *, f32 *);
    f64 fn_80238788(f64);
    void fn_801C65E0(void);
    extern u8 lbl_8027D4B8[];
    extern f32 lbl_8036B414;
    extern f32 lbl_8036B424;
    extern f32 lbl_8036B428;
    extern f32 lbl_8036B434;
    extern f32 lbl_8036B448;
    extern f32 lbl_8036B44C;
    extern f32 lbl_8036B450;
    extern f32 lbl_8036B454;
    extern f32 lbl_8036B458;
    f32 mtx[3][4];
    s32 names[4];
    f32 pos[3];
    s32 refv[3];
    s32 vec[3];
    f32 sp14[3];
    f32 sp8[3];
    u8 *rodata;
    s32 *namep;
    void *walk;
    void *cur;
    void *self;
    u8 ok;
    f32 angle;
    f32 dot;
    s32 idx;

    self = arg0;
    rodata = lbl_8027D4B8;
    if (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x30) + 0xB) == 0xFF) {
        walk = self;
        namep = names;
        cur = NULL;
        names[0] = *(s32 *)(rodata + 0xB4);
        names[1] = *(s32 *)(rodata + 0xB8);
        names[2] = *(s32 *)(rodata + 0xBC);
        names[3] = *(s32 *)(rodata + 0xC0);
        do {
            idx = GActor_FindNode(*(void **)((u8 *)self + 0x30), (void *)*namep);
            if (0 <= idx) {
                fn_80060F70(*(void **)((u8 *)self + 0x30), idx, pos);
                if (*(f32 *)((u8 *)walk + 0x34) > (pos[1] + lbl_8036B448) && pos[1] < lbl_8036B44C) {
                    refv[0] = *(s32 *)(rodata + 0xC4);
                    angle = lbl_8036B424;
                    refv[1] = *(s32 *)(rodata + 0xC8);
                    refv[2] = *(s32 *)(rodata + 0xCC);
                    vec[0] = *(s32 *)(rodata + 0xD0);
                    vec[1] = *(s32 *)(rodata + 0xD4);
                    vec[2] = *(s32 *)(rodata + 0xD8);
                    {
                        void *obj = *(void **)((u8 *)self + 0x30);
                        PSMTXConcat((u8 *)obj + 0x10, (u8 *)*(void **)((u8 *)obj + 0x60) + idx * 0x30, mtx);
                    }
                    mtx[0][3] = lbl_8036B424;
                    mtx[1][3] = lbl_8036B424;
                    mtx[2][3] = lbl_8036B424;
                    fn_802029C4(mtx, vec, vec);
                    ((f32 *)vec)[1] = lbl_8036B424;
                    if (Vec_Length((f32 *)vec) > lbl_8036B424) {
                        fn_802031E8((f32 *)vec, (f32 *)vec);
                        dot = fn_80203270((f32 *)refv, (f32 *)vec);
                        if (lbl_8036B434 <= dot) {
                            angle = lbl_8036B424;
                        } else if (dot <= lbl_8036B450) {
                            angle = lbl_8036B454;
                        } else {
                            angle = lbl_8036B458 * (f32)fn_80238788(dot);
                        }
                        if (((f32 *)vec)[0] < lbl_8036B424) {
                            angle = lbl_8036B428 - angle;
                        }
                    }
                    {
                        void *n;
                        void *list;
                        void *prev;
                        list = *(void **)((u8 *)self + 0x44);
                        *(s32 *)&sp14[1] = *(s32 *)&pos[1];
                        n = **(void ***)((u8 *)list + 0x8);
                        *(s32 *)&sp14[0] = *(s32 *)&pos[0];
                        *(s32 *)&sp14[2] = *(s32 *)&pos[2];
                        sp14[1] = lbl_8036B414;
                        if (n == NULL) {
                            n = NULL;
                        } else {
                            *(void **)((u8 *)n + 4) = *(void **)((u8 *)list + 0x10);
                            *(void **)n = NULL;
                            prev = *(void **)((u8 *)list + 0x10);
                            if (prev != NULL) {
                                *(void **)prev = n;
                            }
                            if (*(void **)((u8 *)list + 0xC) == NULL) {
                                *(void **)((u8 *)list + 0xC) = n;
                            }
                            *(void **)((u8 *)list + 0x10) = n;
                            *(u8 **)((u8 *)list + 0x8) = *(u8 **)((u8 *)list + 0x8) + 4;
                            *(s32 *)((u8 *)list + 0x14) = *(s32 *)((u8 *)list + 0x14) + 1;
                        }
                        if (n != NULL) {
                            *(s32 *)&sp8[0] = *(s32 *)&sp14[0];
                            *(s32 *)&sp8[1] = *(s32 *)&sp14[1];
                            *(s16 *)((u8 *)n + 0x18) = 0xB4;
                            *(s32 *)&sp8[2] = *(s32 *)&sp14[2];
                            *(f32 *)((u8 *)n + 0x8) = sp8[0];
                            *(f32 *)((u8 *)n + 0xC) = sp8[1];
                            *(f32 *)((u8 *)n + 0x10) = sp8[2];
                            *(f32 *)((u8 *)n + 0x14) = angle;
                            *(f32 *)((u8 *)n + 0xC) = lbl_8036B414;
                        }
                    }
                    *(f32 *)((u8 *)walk + 0x34) = pos[1];
                }
                if (pos[1] > *(f32 *)((u8 *)walk + 0x34)) {
                    *(f32 *)((u8 *)walk + 0x34) = pos[1];
                }
            }
            cur = (void *)((s32)cur + 1);
            walk = (u8 *)walk + 4;
            ++namep;
        } while ((s32)cur < 4);
    }
    cur = NULL;
    goto get_next;
loop_body:
    {
        u32 cb_arg = (s32)((u8 *)cur + 8);
        *(s16 *)((u8 *)cur + 0x18) = *(s16 *)((u8 *)cur + 0x18) - 1;
        if (*(s16 *)((u8 *)cur + 0x18) <= 0) {
            ok = 0;
        } else {
            fn_80067708(2, 1, fn_801C65E0, cb_arg);
            ok = 1;
        }
        if (!ok) {
            void *list = *(void **)((u8 *)self + 0x44);
            if (cur != NULL) {
                void *next = *(void **)cur;
                void *prev;
                if (next != NULL) {
                    *(void **)((u8 *)next + 4) = *(void **)((u8 *)cur + 4);
                }
                prev = *(void **)((u8 *)cur + 4);
                if (prev != NULL) {
                    *(void **)prev = *(void **)cur;
                }
                if (cur == *(void **)((u8 *)list + 0xC)) {
                    *(void **)((u8 *)list + 0xC) = *(void **)cur;
                }
                if (cur == *(void **)((u8 *)list + 0x10)) {
                    *(void **)((u8 *)list + 0x10) = *(void **)((u8 *)cur + 4);
                }
                *(u8 **)((u8 *)list + 0x8) = *(u8 **)((u8 *)list + 0x8) - 4;
                *(s32 *)((u8 *)list + 0x14) = *(s32 *)((u8 *)list + 0x14) - 1;
                **(void ***)((u8 *)list + 0x8) = cur;
            }
        }
    }
get_next:
    if (cur == NULL) {
        cur = *(void **)((u8 *)*(void **)((u8 *)self + 0x44) + 0xC);
    } else {
        cur = *(void **)cur;
    }
    if (cur != NULL) {
        goto loop_body;
    }
}
void fn_801C65E0(void *arg0) {
    void *Map_Get(void);
    f32 Math_Lerp(f32, f32, f32, f32);
    void fn_80066D00(s32);
    void *Camera_GetViewMtx(void);
    void Ui_LoadAtlasTex(void *, void *, s32);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXRotRad(void *, s32, f32);
    void PSMTXTrans(void *, f32, f32, f32);
    void GXSetVtxDesc(s32, s32);
    void GXClearVtxDesc(void);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    void GXSetNumChans(s32);
    void GXBegin(s32, s32, s32);
    void fn_8022100C(s32);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void fn_80222C50(void *, s32);
    void GXSetNumTexGens(s32, s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetNumTevStages(s32);
    void fn_802245D8(s32, s32, s32, s32);
    void GXLoadPosMtxImm(void *, s32);
    void GXSetCurrentMtx(s32);
    extern f32 lbl_8036B424;
    extern f32 lbl_8036B430;
    extern f32 lbl_8036B434;
    extern f32 lbl_8036B45C;
    extern f32 lbl_8036B460;
    extern f32 lbl_8036B464;
    extern f32 lbl_8036B468;
    f32 mtxA[3][4];
    f32 mtxB[3][4];
    f32 mtxC[3][4];
    u8 tex[0x20];
    f32 z, y, x;
    void *obj;
    f32 scale;
    s32 alpha;
    s16 t;
    u8 c;

    obj = Map_Get();
    if (obj != NULL) {
        *(u32 *)&x = *(u32 *)((u8 *)arg0 + 0);
        *(u32 *)&y = *(u32 *)((u8 *)arg0 + 4);
        *(u32 *)&z = *(u32 *)((u8 *)arg0 + 8);
        scale = *(f32 *)((u8 *)arg0 + 0xC);
        PSMTXTrans(mtxA, x, y, z);
        PSMTXRotRad(mtxB, 0x79, lbl_8036B430 * scale);
        PSMTXConcat(mtxA, mtxB, mtxC);
        PSMTXConcat(Camera_GetViewMtx(), mtxC, mtxC);
        GXLoadPosMtxImm(mtxC, 0);
        GXSetCurrentMtx(0);
        Ui_LoadAtlasTex(*(void **)((u8 *)obj + 0x38), tex, 9);
        fn_80222C50(tex, 0);
        GXClearVtxDesc();
        GXSetVtxDesc(9, 1);
        GXSetVtxDesc(0xB, 1);
        GXSetVtxDesc(0xD, 1);
        GXSetVtxAttrFmt(0, 9, 1, 4, 0);
        GXSetVtxAttrFmt(0, 0xB, 1, 5, 0);
        GXSetVtxAttrFmt(0, 0xD, 1, 4, 0);
        fn_8022100C(2);
        GXSetCullMode(1);
        GXSetBlendMode(4, 0, 1, 1, 0, 0, 2);
        GXSetNumChans(1);
        GXSetNumTevStages(1);
        GXSetTevOrder(0, 0, 0, 4);
        fn_802201A8(0, 1, 4, 0x3C, 0, 0x7D);
        fn_802245D8(1, 4, 5, 7);
        GXSetNumTexGens(0, 0);
        t = *(s16 *)((u8 *)arg0 + 0x10);
        alpha = 0xFF;
        if (t < 0x3C) {
            alpha = (s32)Math_Lerp(lbl_8036B424, lbl_8036B45C, lbl_8036B460, (f32)t);
        }
        GXBegin(0x98, 0, 4);
        c = 0xFF;
        {
            f64 f3 = lbl_8036B434;
            f32 f2 = lbl_8036B424;
            f32 f4 = -f3;
            f32 f0;
            f32 f1 = lbl_8036B464;
            f0 = f4 + lbl_8036B468;
            *(f32 *)0xCC008000 = f3;
            *(f32 *)0xCC008000 = f2;
            *(f32 *)0xCC008000 = f1;
            *(u8 *)0xCC008000 = c;
            *(u8 *)0xCC008000 = c;
            *(u8 *)0xCC008000 = c;
            *(u8 *)0xCC008000 = alpha;
            *(f32 *)0xCC008000 = f2;
            *(f32 *)0xCC008000 = f2;
            *(f32 *)0xCC008000 = f4;
            *(f32 *)0xCC008000 = f2;
            *(f32 *)0xCC008000 = f1;
            *(u8 *)0xCC008000 = c;
            *(u8 *)0xCC008000 = c;
            *(u8 *)0xCC008000 = c;
            *(u8 *)0xCC008000 = alpha;
            *(f32 *)0xCC008000 = f3;
            *(f32 *)0xCC008000 = f2;
            *(f32 *)0xCC008000 = f3;
            *(f32 *)0xCC008000 = f2;
            *(f32 *)0xCC008000 = f0;
            *(u8 *)0xCC008000 = c;
            *(u8 *)0xCC008000 = c;
            *(u8 *)0xCC008000 = c;
            *(u8 *)0xCC008000 = alpha;
            *(f32 *)0xCC008000 = f2;
            *(f32 *)0xCC008000 = f3;
            *(f32 *)0xCC008000 = f4;
            *(f32 *)0xCC008000 = f2;
            *(f32 *)0xCC008000 = f0;
            *(u8 *)0xCC008000 = c;
            *(u8 *)0xCC008000 = c;
            *(u8 *)0xCC008000 = c;
            *(u8 *)0xCC008000 = alpha;
            *(f32 *)0xCC008000 = f3;
            *(f32 *)0xCC008000 = f3;
        }
        fn_80066D00(-1);
    }
}

#pragma global_optimizer off
void fn_801C68D0(u32 arg0) {
    extern u8 LightFade_script[];
    void *Process_Find(void *);
    void fn_8005FA14(void *, s32);
    void *x;
    u8 *table;
    s32 i;
    u8 *ptr;
    s32 ctr;
    s32 off;
    void *obj;

    x = Process_Find(LightFade_script);
    if ((u32)x == 0U) {
        table = NULL;
    } else {
        table = *(u8 **)((u8 *)x + 0x30);
    }
    if ((u32)table != 0U) {
        ptr = table;
        i = 0;
        for (ctr = 0x20; ctr != 0; ctr--) {
            if (*(u32 *)(ptr + 4) == arg0) {
                off = i * 0x14 + 4;
                obj = *(void **)((s32)table + off);
                if ((u32)obj != 0U) {
                    fn_8005FA14(obj, 0);
                    *(u32 *)((s32)table + off) = 0;
                }
                break;
            }
            ptr += 0x14;
            i += 1;
        }
    }
}
#pragma global_optimizer on
void fn_801C6978(u32 arg0) {
    extern u8 LightFade_script[];
    extern u32 lbl_8027D540[];
    extern f32 lbl_8036B424;
    extern f32 lbl_8036B434;
    void *Process_Find(void *);
    f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
    f32 Math_Lerp(f32, f32, f32, f32);
    void fn_8005FA14(void *, s32);
    void PSMTXTrans(void *, void *, f32, f32, f32);
    void PSMTXConcat(void *, void *, void *);

    f32 mtx[12];
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 t;
    void *p;
    u8 *base;
    u8 *entry;
    s32 i;
    u8 *walk;
    s16 max;
    s16 counter;
    u8 flag;
    void *obj;
    void *obj_plus;

    p = Process_Find(LightFade_script);
    if (p == NULL) {
        base = NULL;
    } else {
        base = *(u8 **)((u8 *)p + 0x30);
    }
    if (base != NULL) {
        i = 0;
        walk = base;
        for (; i < 0x20; walk += 0x14, i++) {
            if (*(u32 *)(walk + 4) == arg0) {
                entry = base + i * 0x14 + 4;
                goto found;
            }
        }
        entry = NULL;
    found:
        if (entry != NULL) {
            *(s16 *)(entry + 4) = (s16)(*(s16 *)(entry + 4) + 1);
            counter = *(s16 *)(entry + 4);
            max = *(s16 *)(entry + 6);
            if (counter >= max) {
                *(s16 *)(entry + 4) = max;
                flag = 0;
            } else {
                *(u32 *)&sp8 = lbl_8027D540[0];
                *(u32 *)&spC = lbl_8027D540[1];
                *(u32 *)&sp10 = lbl_8027D540[2];
                t = Math_EaseOutPow(2, lbl_8036B424, lbl_8036B434, (f32)max, (f32)counter);
                sp8 = -Math_Lerp(*(f32 *)(entry + 8), lbl_8036B424, lbl_8036B434, t);
                sp10 = -Math_Lerp(*(f32 *)(entry + 0x10), lbl_8036B424, lbl_8036B434, t);
                obj = *(void **)entry;
                *(f32 *)((u8 *)obj + 0x78) = t;
                PSMTXTrans(mtx, obj, sp8, spC, sp10);
                obj = *(void **)entry;
                obj_plus = (u8 *)obj + 0x10;
                PSMTXConcat(mtx, obj_plus, obj_plus);
                flag = 1;
            }
            if (flag == 0) {
                i = 0;
                walk = base;
                for (; i < 0x20; walk += 0x14, i++) {
                    if (*(u32 *)(walk + 4) == arg0) {
                        entry = base + i * 0x14 + 4;
                        obj = *(void **)entry;
                        if (obj != NULL) {
                            fn_8005FA14(obj, 0);
                            *(u32 *)entry = 0;
                        }
                        break;
                    }
                }
            }
        }
    }
}

s32 fn_801C6B7C(u32 arg0,s32 arg1,s32 arg2,f32 *arg3,s32 arg4) {
void *Process_Find(void *);
void fn_801C797C(void *,void *,u32,s32,s32,u8);
extern u8 LightFade_script[];
#pragma cplusplus on
struct Pool {
u32 unknown;
struct Entry {u32 key;u8 rest[16];} entries[32];
Entry *find(u32 key) {
s32 i;
for(i=0;i<32;i++) if(entries[i].key==key) return &entries[i];
return NULL;
}
};
f32 result[3];
void *proc;
Pool *pool;
Pool::Entry *entry;
if(arg2==0) return 0;
proc=Process_Find(LightFade_script);
if(proc==NULL) pool=0;
else pool=M2C_FIELD(proc,Pool **,0x30);
if(pool==NULL) return 0;
entry=pool->find(arg0);
if(entry==NULL) {
entry=pool->find(0);
if(entry==NULL) return 0;
}
fn_801C797C(result,entry,arg0,arg1,arg2,(u8)arg4);
arg3[0]=result[0];arg3[1]=result[1];arg3[2]=result[2];
return 1;
#pragma cplusplus reset
}

void fn_801C6CBC(u32 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    void *Process_Find(void *);
    void Process_Goto(void *, s32);
    void *Process_Create(void *, s32);

    extern u8 lbl_802981F4[];
    extern u8 LightFade_script[];

    u8 *entry;
    u8 *source;
    u8 *dest;
    struct { u32 temp; u32 value; } s;
    u32 z;

    entry = (u8 *)Process_Find(lbl_802981F4);
    if (entry != NULL) {
        if (*(s32 *)(entry + 0x38) < arg3) {
            return;
        }
        Process_Goto(entry, 0);
    } else {
        entry = (u8 *)Process_Create(lbl_802981F4, arg2);
    }

    z = 0;
    s.value = *arg0;
    *(u32 *)(entry + 0x30) = z;
    *(s32 *)(entry + 0x34) = arg1;
    *(s32 *)(entry + 0x38) = arg3;

    source = (u8 *)Process_Find(LightFade_script);
    if (source == NULL) {
        dest = NULL;
    } else {
        dest = *(u8 **)(source + 0x30);
    }

    if (dest == NULL) {
        return;
    }

    dest[0x288] = dest[0x284];
    s.temp = s.value;
    dest[0x289] = dest[0x285];
    dest[0x28A] = dest[0x286];
    dest[0x28B] = dest[0x287];

    dest[0x284] = ((u8 *)&s.temp)[0];
    dest[0x285] = ((u8 *)&s.temp)[1];
    dest[0x286] = ((u8 *)&s.temp)[2];
    dest[0x287] = ((u8 *)&s.temp)[3];
}

void fn_801C6DB8(u32 arg0)
{
    extern u8 LightFade_script[];
    void *Process_Find(void *);
    void fn_8005F788(u32, s32, s32);
    s32 i;
    u8 *list;
    s32 clear;
    void *p;

    p = Process_Find(LightFade_script);
    if (p == NULL) {
        list = NULL;
    } else {
        list = *(u8 **)((u8 *)p + 0x30);
    }
    if (list != NULL && arg0 != 0) {
        i = 0;
        clear = i;
        for (; i < 0x40; i++) {
            if (*(u32 *)(list + 0x290) == arg0) {
                *(u32 *)(list + 0x290) = clear;
                fn_8005F788(arg0, 0, 1);
            }
            list += 4;
        }
    }
}

#pragma optimization_level 3
void fn_801C6E60(u32 arg0)
{
    extern u8 LightFade_script[];
    void *Process_Find(void *);
    void fn_8005F788(u32, s32, s32);
    s32 i;
    s32 clear;
    u8 *list;
    void *p;

    p = Process_Find(LightFade_script);
    if (p == NULL) {
        list = NULL;
    } else {
        list = *(u8 **)((u8 *)p + 0x30);
    }
    if (list != NULL && arg0 != 0) {
        clear = (s32)list;
        for (i = 0; i < 0x40; i++) {
            if (*(u32 *)(list + 0x290) == arg0) {
                return;
            }
            list += 4;
        }
        list = (u8 *)clear;
        for (i = 0; i < 0x40; i++) {
            if (*(u32 *)(list + 0x290) == 0) {
                list = (u8 *)clear + i * 4;
                *(u32 *)(list + 0x290) = arg0;
                fn_8005F788(arg0, 1, 1);
                break;
            }
            list += 4;
        }
    }
}
#pragma optimization_level reset
void fn_801C6F7C(void){void Light_FadeProcess(void);Light_FadeProcess();}

/* Copy LightFade source channels onto display lights, release extras, restore fog color. */
void LightFade_RestoreLights(void) {
    extern u8 LightFade_script[];
    void *Process_Find(void *);
    s32 Light_GetChannel(s32);
    void Light_CopyChannel(s32, s32);
    u8 *Fog_GetColor(void);
    void fn_8005F788(u32, s32, s32);
    void *proc = Process_Find(LightFade_script);
    u8 *work;
    if (proc == NULL) {
        work = 0;
    } else {
        work = *(u8 **)((u8 *)proc + 0x30);
    }
    if (work) {
        u8 *data = work + 0x284;
        u8 *fog;
        s32 i;
        u32 *ptr;

        Light_CopyChannel(Light_GetChannel(1), Light_GetChannel(0));
        Light_CopyChannel(Light_GetChannel(3), Light_GetChannel(2));
        for (i = 0, ptr = (u32 *)data; i < 64; i++, ptr++) {
            if (ptr[3]) {
                fn_8005F788(ptr[3], 0, 1);
            }
        }
        fog = Fog_GetColor();
        fog[1] = data[8];
        fog[2] = data[9];
        fog[3] = data[10];
    }
}

void fn_801C7080(void) {
    extern u8 LightFade_script[];
    extern u32 lbl_8036B3E0;
    extern u32 lbl_8036B3E4;
    void *Process_Find(void *);
    u8 *Light_GetChannel(s32);
    void Light_CopyChannel(u8 *, u8 *);
    u8 *Fog_GetColor(void);
    void *proc;
    u8 *work;
    u8 *data;
    u8 *fog;
    u32 tmp2;
    u32 tmp;
    s32 i;
    u32 zero;

    proc = Process_Find(LightFade_script);
    if (proc == NULL)
        work = NULL;
    else
        work = *(u8 **)((u8 *)proc + 0x30);
    if (work != NULL) {
        data = work + 0x284;
        Light_CopyChannel(Light_GetChannel(0), Light_GetChannel(1));
        Light_CopyChannel(Light_GetChannel(2), Light_GetChannel(3));

        tmp = lbl_8036B3E0;
        data[4] = ((u8 *)&tmp)[0];
        data[5] = ((u8 *)&tmp)[1];
        data[6] = ((u8 *)&tmp)[2];
        data[7] = ((u8 *)&tmp)[3];

        tmp2 = lbl_8036B3E4;
        data[0] = ((u8 *)&tmp2)[0];
        data[1] = ((u8 *)&tmp2)[1];
        data[2] = ((u8 *)&tmp2)[2];
        data[3] = ((u8 *)&tmp2)[3];

        fog = Fog_GetColor();
        {
            u8 b1 = fog[1];
            zero = 0;
            data[8] = b1;
            data[9] = fog[2];
            data[10] = fog[3];
        }

        for (i = 0; i < 2; i++) {
            *(u32 *)(data + 0x0c) = zero;
            *(u32 *)(data + 0x10) = zero;
            *(u32 *)(data + 0x14) = zero;
            *(u32 *)(data + 0x18) = zero;
            *(u32 *)(data + 0x1c) = zero;
            *(u32 *)(data + 0x20) = zero;
            *(u32 *)(data + 0x24) = zero;
            *(u32 *)(data + 0x28) = zero;
            *(u32 *)(data + 0x2c) = zero;
            *(u32 *)(data + 0x30) = zero;
            *(u32 *)(data + 0x34) = zero;
            *(u32 *)(data + 0x38) = zero;
            *(u32 *)(data + 0x3c) = zero;
            *(u32 *)(data + 0x40) = zero;
            *(u32 *)(data + 0x44) = zero;
            *(u32 *)(data + 0x48) = zero;
            *(u32 *)(data + 0x4c) = zero;
            *(u32 *)(data + 0x50) = zero;
            *(u32 *)(data + 0x54) = zero;
            *(u32 *)(data + 0x58) = zero;
            *(u32 *)(data + 0x5c) = zero;
            *(u32 *)(data + 0x60) = zero;
            *(u32 *)(data + 0x64) = zero;
            *(u32 *)(data + 0x68) = zero;
            *(u32 *)(data + 0x6c) = zero;
            *(u32 *)(data + 0x70) = zero;
            *(u32 *)(data + 0x74) = zero;
            *(u32 *)(data + 0x78) = zero;
            *(u32 *)(data + 0x7c) = zero;
            *(u32 *)(data + 0x80) = zero;
            *(u32 *)(data + 0x84) = zero;
            *(u32 *)(data + 0x88) = zero;
            data += 0x80;
        }
    }
}

#pragma use_lmw_stmw on
/* Fade GX light and fog colors toward the linked unit's target colors over time. */
void Light_FadeProcess(void *proc) {
    void *Process_Find(void *);
    void Process_ClearFunc(void *);
    void Process_Unlink(void *);
    f32 Math_EaseOutPow(s32, f32, f32, f32, f32);
    u8 *Light_GetChannel(s32);
    u8 *Fog_GetColor(void);
    extern u8 LightFade_script[];
    extern f64 lbl_8036B440;
    extern f64 lbl_8036B470;

    u8 *self = (u8 *)proc;
    void *node;
    void *unit;
    u32 sp10;
    u32 spC;
    u32 sp8;
    u8 *srcLight;
    u8 *dst0;
    u8 *dst2;
    s32 t0, t1, t2;
    s32 v;
    u8 *fog;

    node = Process_Find(LightFade_script);
    if (node == NULL)
        unit = NULL;
    else
        unit = *(void **)((u8 *)node + 0x30);
    if (unit == NULL)
        Process_Unlink(proc);

    sp10 = *(u32 *)((u8 *)unit + 0x288);
    spC = *(u32 *)((u8 *)unit + 0x284);
    sp8 = *(u32 *)((u8 *)unit + 0x28C);
    *(s32 *)(self + 0x30) = *(s32 *)(self + 0x30) + 1;

    srcLight = Light_GetChannel(1);
    dst0 = Light_GetChannel(0);
    dst2 = Light_GetChannel(2);

    t0 = (s32)Math_EaseOutPow(2, (f32)*(u8 *)&sp10, (f32)*(u8 *)&spC,
                          (f32)*(s32 *)(self + 0x34), (f32)*(s32 *)(self + 0x30));
    t1 = (s32)Math_EaseOutPow(2, (f32)*(u8 *)&sp10, (f32)*(u8 *)&spC,
                          (f32)*(s32 *)(self + 0x34), (f32)*(s32 *)(self + 0x30));
    t2 = (s32)Math_EaseOutPow(2, (f32)*(u8 *)&sp10, (f32)*(u8 *)&spC,
                          (f32)*(s32 *)(self + 0x34), (f32)*(s32 *)(self + 0x30));

    v = (srcLight[4] * t0) / 128;
    if (v > 0xFF) v = 0xFF;
    dst0[4] = (u8)v;
    dst2[4] = (u8)v;

    v = (srcLight[5] * t1) / 128;
    if (v > 0xFF) v = 0xFF;
    dst0[5] = (u8)v;
    dst2[5] = (u8)v;

    v = (srcLight[6] * t2) / 128;
    if (v > 0xFF) v = 0xFF;
    dst0[6] = (u8)v;
    dst2[6] = (u8)v;

    v = (srcLight[0] * t0) / 128;
    if (v > 0xFF) v = 0xFF;
    dst0[0] = (u8)v;
    dst2[0] = (u8)v;

    v = (srcLight[1] * t1) / 128;
    if (v > 0xFF) v = 0xFF;
    dst0[1] = (u8)v;
    dst2[1] = (u8)v;

    v = (srcLight[2] * t2) / 128;
    if (v > 0xFF) v = 0xFF;
    dst0[2] = (u8)v;
    dst2[2] = (u8)v;

    fog = Fog_GetColor();
    v = (((u8 *)&sp8)[0] * t0) / 128;
    if (v > 0xFF) v = 0xFF;
    fog[1] = (u8)v;
    v = (((u8 *)&sp8)[1] * t1) / 128;
    if (v > 0xFF) v = 0xFF;
    fog[2] = (u8)v;
    v = (((u8 *)&sp8)[2] * t2) / 128;
    if (v > 0xFF) v = 0xFF;
    fog[3] = (u8)v;

    if (*(s32 *)(self + 0x30) >= *(s32 *)(self + 0x34)) {
        *(s32 *)(self + 0x34) = 0;
        if (t0 == 0x80 && t1 == 0x80 && t2 == 0x80)
            Process_Unlink(proc);
        else
            Process_ClearFunc(proc);
    }
}
#pragma use_lmw_stmw reset

extern u32 lbl_8036C510;
void fn_801C7598(void *arg0) {
    void *tmp = (void *)Fog_GetColor();
    if (tmp != NULL && *(u8 *)tmp != 0) {
        u32 local_c;
        u8 local_b1;
        u8 local_b2;
        u8 local_b3;
        u32 local_8;
        local_c = lbl_8036C510;
        local_b1 = ((u8 *)tmp)[1];
        local_b2 = ((u8 *)tmp)[2];
        local_b3 = ((u8 *)tmp)[3];
        ((u8 *)&local_c)[0] = local_b1;
        ((u8 *)&local_c)[1] = local_b2;
        ((u8 *)&local_c)[2] = local_b3;
        local_8 = local_c;
        GXSetCopyClear(&local_8, 0xFFFFFF, local_b2, local_b1);
    }
}

void fn_801C7604(void) {
    M2C_UNK Gfx_FillRect(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK fn_80067984(M2C_UNK);
    M2C_UNK Camera_ApplyOrtho(M2C_UNK);
    Camera_ApplyOrtho(0);
    Gfx_FillRect(0, 0, 0x260, 0x1C0);
    fn_80067984(0);
}

void fn_801C7644(s32 arg0) {
    extern f32 lbl_8036B3E8;
    extern f32 lbl_8036B424;
    u32 fn_80055D94(s32);
    void Camera_ApplyOrtho(s32);
    void fn_800599D0(s32,s32,s32,s32,s32);
    void fn_8005956C(s32,s32,s32,s32,s32,s32*,s32,f32);
    void fn_80059C2C(s32,s32,s32,s32,s32);
    void fn_80067984(s32);
    s32 tmp = *(s32 *)&lbl_8036B3E8;
    Camera_ApplyOrtho(0);
    if (fn_80055D94(0x80) == 0) {
       fn_800599D0(0,0,0x260,0x1c0,arg0);
       fn_8005956C(0,0,0x260,0x1c0,1,&tmp,arg0,lbl_8036B424);
    }
    fn_80059C2C(0,0,0x260,0x1c0,0);
    fn_80067984(0);
}

void LightFade_Start(void) {
    extern u8 LightFade_script[];
    void *Process_Find(void *);
    void fn_80067708(s32, s32, void (*)(void), s32);
    void fn_801C7598(void), fn_801C7604(void), fn_801C7644(void);
    void *x;
    s32 *p;

    x = Process_Find(LightFade_script);
    if (x == NULL) {
        p = NULL;
    } else {
        p = *(s32 **)((u8 *)x + 0x30);
    }
    if (p != NULL) {
        fn_80067708(3, 0, fn_801C7598, 0);
        fn_80067708(1, 4, fn_801C7644, *p);
        fn_80067708(2, 0, fn_801C7604, 0);
    }
}

extern u8 LightFade_script[];
void fn_801C777C(void){extern u8 LightFade_script[];void Process_UnlinkByKey(void*);Process_UnlinkByKey(LightFade_script);}

void fn_801C77A4(void) {
    Process_Create((void*)&LightFade_script, 4);
}

void GActor_FreeTexWork(void *arg0) {
    void Process_UnlinkByKey(void *);
    void GActor_UnlinkNodeLink(void);
    void fn_8005376C(void);
    void fn_800C4588(void *);
    void fn_8005FA14(void *, s32);
    void Heap_Free(void *);
    extern u8 LightFade_script[];
    s32 i;
    void **ptr;
    void **walk;
    s32 zero;
    s32 base;

    base = (s32)LightFade_script;
    Process_UnlinkByKey((void *)(base + 0x54));
    Process_UnlinkByKey((void *)(base + 0x7c));
    GActor_UnlinkNodeLink();
    Process_UnlinkByKey((void *)(base + 0x24));
    fn_8005376C();
    ptr = *(void ***)((u8 *)arg0 + 0x30);
    if (ptr != NULL) {
        fn_800C4588(*ptr);
        zero = 0;
        walk = ptr;
        *ptr = (void *)zero;
        i = zero | 0;
        *ptr = (void *)zero;
        do {
            if (walk[1] != NULL) {
                fn_8005FA14(walk[1], 0);
                walk[1] = (void *)zero;
            }
            i += 1;
            walk = (void **)((u8 *)walk + 0x14);
        } while (i < 0x20);
        Heap_Free(ptr);
    }
    *(void **)((u8 *)arg0 + 0x30) = 0;
}

void GActor_InitTexWork(void *proc) {
    /* Alloc 32-slot tex work, load 608x448 texture into slot 0, attach to proc. */
    void *Heap_Alloc(s32);
    s32 fn_800C45B8(void *, void *, s32);
    void *GXGetTexBufferSize(s32, s32, s32, s32, s32);
    void fn_8005376C(void);
    extern u16 lbl_8027D594[];
    void *work;

    work = Heap_Alloc(0x390);
    if (work != NULL) {
        *(s32 *)((u8 *)work + 0x4) = 0;
        *(s32 *)((u8 *)work + 0x18) = 0;
        *(s32 *)((u8 *)work + 0x2C) = 0;
        *(s32 *)((u8 *)work + 0x40) = 0;
        *(s32 *)((u8 *)work + 0x54) = 0;
        *(s32 *)((u8 *)work + 0x68) = 0;
        *(s32 *)((u8 *)work + 0x7C) = 0;
        *(s32 *)((u8 *)work + 0x90) = 0;
        *(s32 *)((u8 *)work + 0xA4) = 0;
        *(s32 *)((u8 *)work + 0xB8) = 0;
        *(s32 *)((u8 *)work + 0xCC) = 0;
        *(s32 *)((u8 *)work + 0xE0) = 0;
        *(s32 *)((u8 *)work + 0xF4) = 0;
        *(s32 *)((u8 *)work + 0x108) = 0;
        *(s32 *)((u8 *)work + 0x11C) = 0;
        *(s32 *)((u8 *)work + 0x130) = 0;
        *(s32 *)((u8 *)work + 0x144) = 0;
        *(s32 *)((u8 *)work + 0x158) = 0;
        *(s32 *)((u8 *)work + 0x16C) = 0;
        *(s32 *)((u8 *)work + 0x180) = 0;
        *(s32 *)((u8 *)work + 0x194) = 0;
        *(s32 *)((u8 *)work + 0x1A8) = 0;
        *(s32 *)((u8 *)work + 0x1BC) = 0;
        *(s32 *)((u8 *)work + 0x1D0) = 0;
        *(s32 *)((u8 *)work + 0x1E4) = 0;
        *(s32 *)((u8 *)work + 0x1F8) = 0;
        *(s32 *)((u8 *)work + 0x20C) = 0;
        *(s32 *)((u8 *)work + 0x220) = 0;
        *(s32 *)((u8 *)work + 0x234) = 0;
        *(s32 *)((u8 *)work + 0x248) = 0;
        *(s32 *)((u8 *)work + 0x25C) = 0;
        *(s32 *)((u8 *)work + 0x270) = 0;
        *(s32 *)work = fn_800C45B8(GXGetTexBufferSize(0x260, 0x1C0, 0x27, 0, 0), (u8 *)lbl_8027D594 + 0x1A8, 0);
    }
    *(void **)((u8 *)proc + 0x30) = work;
    fn_8005376C();
}

#pragma use_lmw_stmw on
void fn_801C797C(void *arg0, void *arg1, void *arg2, s32 arg3, s16 arg4, u8 arg5) {
    s32 GActor_FindNode(void *, void *);
    s32 fn_80060440(void *);
    void fn_8005FA14(void *, s32);
    void fn_800608AC(void *);
    void fn_80060F70(void *, s32, f32 *);
    void *GActor_GetNodeTable(void *);
    void fn_8005FC74(void *, s32, s32);
    void fn_8005FEE8(void *, f32);
    void fn_802031A8(f32 *, f32 *, f32 *);
    extern f32 lbl_8027D528[3];
    extern f32 lbl_8027D534[3];
    extern u16 lbl_8027D594[];
    extern f32 lbl_8036B424;
    extern f32 lbl_8036B434;
    void *obj;
    void *dst;
    void *out;
    s32 param;
    u8 flag;
    s32 id1;
    s32 id2;
    s32 kind;
    f32 save;
    void *base;
    void *entry;
    u32 sp38[3];
    u32 sp2c[3];
    f32 sp20[3];
    f32 sp14[3];
    f32 sp8[3];

    obj = arg2;
    *(void **)arg1 = obj;
    dst = arg1;
    out = arg0;
    *(s16 *)((u8 *)dst + 6) = arg4;
    *(s16 *)((u8 *)dst + 4) = 0;
    param = arg3;
    flag = arg5;

    sp38[0] = ((u32 *)lbl_8027D528)[0];
    sp38[1] = ((u32 *)lbl_8027D528)[1];
    sp38[2] = ((u32 *)lbl_8027D528)[2];
    sp2c[0] = ((u32 *)lbl_8027D534)[0];
    sp2c[1] = ((u32 *)lbl_8027D534)[1];
    sp2c[2] = ((u32 *)lbl_8027D534)[2];

    id1 = GActor_FindNode(obj, (u8 *)lbl_8027D594 + 0x127);
    id2 = GActor_FindNode(obj, (u8 *)lbl_8027D594 + 0x1A4);

    if (id1 != -1) {
        kind = fn_80060440(obj);
        if (kind == 4) {
            fn_8005FA14(obj, 0);
            fn_800608AC(obj);
            fn_80060F70(obj, id1, sp14);
            sp20[0] = sp14[0];
            sp20[1] = sp14[1];
            sp20[2] = sp14[2];
        } else if (kind > 1) {
            fn_80060F70(obj, id1, sp14);
            save = *(f32 *)((u8 *)obj + 0x78);
            *(f32 *)((u8 *)obj + 0x78) = lbl_8036B434;
            fn_800608AC(obj);
            *(f32 *)((u8 *)obj + 0x78) = save;
            fn_80060F70(obj, id1, sp20);
        } else {
            fn_80060F70(obj, id1, sp14);
            sp20[0] = sp14[0];
            sp20[1] = sp14[1];
            sp20[2] = sp14[2];
        }

        if (id2 != -1) {
            base = GActor_GetNodeTable(obj);
            if (flag != 0) {
                entry = (u8 *)(*(void **)((u8 *)base + 0xC)) + id2 * 0xF4;
                *(u32 *)((u8 *)entry + 0xC) |= 0x40000000;
            } else {
                entry = (u8 *)(*(void **)((u8 *)base + 0xC)) + id2 * 0xF4;
                *(u32 *)((u8 *)entry + 0xC) &= ~0x40000000;
            }
        }

        fn_8005FC74(obj, param, 0);
        fn_8005FEE8(obj, lbl_8036B424);
        *(f32 *)((u8 *)obj + 0x78) = lbl_8036B434;
        fn_800608AC(obj);
        *(f32 *)((u8 *)obj + 0x78) = lbl_8036B424;
        fn_80060F70(obj, id1, sp8);
        fn_802031A8(sp20, sp8, (f32 *)sp38);
        fn_802031A8(sp14, sp8, (f32 *)sp2c);
        ((f32 *)sp2c)[1] = lbl_8036B424;
        ((f32 *)sp38)[1] = lbl_8036B424;
        *(f32 *)((u8 *)dst + 8) = ((f32 *)sp2c)[0];
        *(f32 *)((u8 *)dst + 0xC) = ((f32 *)sp2c)[1];
        *(f32 *)((u8 *)dst + 0x10) = ((f32 *)sp2c)[2];
    }

    *(u32 *)((u8 *)out + 0) = sp38[0];
    *(u32 *)((u8 *)out + 4) = sp38[1];
    *(u32 *)((u8 *)out + 8) = sp38[2];
}
void fn_801C7BF8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
}

void fn_801C7C08(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
}

void fn_801C7C18(u8 arg0,u8 arg1,u8 arg2) {
    void *fn_8006E658(void);
    void VIConfigure(void *);
    void fn_8009E574(void);
    void fn_802204F8(void);
    void fn_80221824(u8, void *, s32, void *);
    void *memcpy(void *, void *, u32);
    extern s16 lbl_80366E98;
    extern s16 lbl_80366E9A;
    extern u8 lbl_80366E9C;
    extern s32 gGameFlags;
    extern s8 lbl_803682B0;
    extern s8 lbl_803682B1;
    extern f32 lbl_8036B478;
    extern f32 lbl_8036B47C;
    extern f32 lbl_8036B480;
    extern f32 lbl_8036B484;
    extern s32 lbl_8036C51C;
    extern u16 lbl_8036C520;
    extern u8 lbl_8036C522;

    struct {
        s32 unk0;
        u16 unk4;
        u8 unk6;
    } sp10;
    u32 sp8;
    u32 spC;
    void *temp_r3;
    void *initial;
    f32 var_f2;
    s32 temp_r0;
    u16 temp_r8;
    u8 *var_r6;
    s32 var_r9;
    s32 count;
    s32 temp_r9;
    s32 var_ctr;
    u8 *var_r6_2;
    s32 var_r8;

    initial=fn_8006E658();
    if(lbl_80366E98<0 || lbl_80366E9A<0) {
    lbl_80366E98=*(u16 *)((u8 *)initial+0xA);
    lbl_80366E9A=*(u16 *)((u8 *)initial+0xC);
    }
    lbl_803682B0=arg0; lbl_803682B1=arg1; lbl_80366E9C=arg2;
    fn_8009E574();
    temp_r3 = fn_8006E658();
    *(s16 *)((u8 *)temp_r3 + 0xA) = (s16)(lbl_80366E98 + lbl_803682B0);
    *(s16 *)((u8 *)temp_r3 + 0xC) = (s16)(lbl_80366E9A + lbl_803682B1);
    VIConfigure(temp_r3);
    if (gGameFlags & 0x40) {
        var_f2 = lbl_8036B478;
    } else {
        var_f2 = lbl_8036B47C;
    }
    var_r6 = (u8 *)&spC;
    var_r9 = 0;
    temp_r0 = (s32)((f32)(s8)lbl_80366E9C * var_f2);
    temp_r8 = (s8)lbl_80366E9C - (u16)temp_r0;
    count = temp_r8 % 4;
    for (var_ctr = 2; var_ctr != 0; var_ctr--) {
        if (var_r9 < count) {
            *var_r6 = (u8)(s32)((f32)temp_r8 * lbl_8036B480 + lbl_8036B478);
        } else {
            *var_r6 = (u8)(s32)((f32)temp_r8 * lbl_8036B480);
        }
        var_r9 += 1;
        if (var_r9 < count) {
            var_r6[1] = (u8)(s32)((f32)temp_r8 * lbl_8036B480 + lbl_8036B478);
        } else {
            var_r6[1] = (u8)(s32)((f32)temp_r8 * lbl_8036B480);
        }
        var_r6 += 2;
        var_r9 += 1;
    }
    var_r6_2 = (u8 *)&sp8;
    var_r8 = 0;
    for (var_ctr = 3; var_ctr != 0; var_ctr--) {
        if (var_r8 < (s32)((u16)temp_r0 % 3)) {
            *var_r6_2 = (u8)(s32)(lbl_8036B478 + (f32)(u16)temp_r0 / lbl_8036B484);
        } else {
            *var_r6_2 = (u8)(s32)((f32)(u16)temp_r0 / lbl_8036B484);
        }
        var_r6_2 += 1;
        var_r8 += 1;
    }
    sp10.unk0 = lbl_8036C51C;
    sp10.unk4 = lbl_8036C520;
    sp10.unk6 = lbl_8036C522;
    *(u8 *)&sp10.unk0 = *((u8 *)&spC + 2);
    *((u8 *)&sp10.unk0 + 1) = *(u8 *)&spC;
    *((u8 *)&sp10.unk0 + 2) = *((u8 *)&sp8 + 1);
    *((u8 *)&sp10.unk0 + 3) = *(u8 *)&sp8;
    *(u8 *)&sp10.unk4 = *((u8 *)&sp8 + 2);
    *((u8 *)&sp10.unk4 + 1) = *((u8 *)&spC + 1);
    sp10.unk6 = *((u8 *)&spC + 3);
    fn_80221824(*(u8 *)((u8 *)temp_r3 + 0x19), (u8 *)temp_r3 + 0x1A, 1, &sp10);
    memcpy((u8 *)temp_r3 + 0x32, &sp10, 7);
    fn_802204F8();
}

void fn_801C7F60(void){void fn_801C7F80(void);fn_801C7F80();}

s32 fn_801C7F80(void *arg0)
{
    s32 Process_CreateChild(void *, void *);
    void fn_801C7FC0(void);

    extern u8 lbl_802983C0[];

    s32 result;

    result = Process_CreateChild(lbl_802983C0, arg0);

    fn_801C7FC0();

    return result;
}

void fn_801C7FC0(u32 arg0) {
    M2C_UNK fn_801C7FE8();
    if (arg0 != 0U) {
        fn_801C7FE8();
    }
    return;
}

#pragma cplusplus on
extern "C" void MonitorWin_Release(MonitorWin *panel) {
    void FileCache_ReleaseSlot(void *);
    struct Obj {
        virtual void destroy(s32) = 0;
    };
    Obj *child;

    /* Release the monitor atlas key and destroy its child widgets. */
    if (panel->field30 != 0) {
        FileCache_ReleaseSlot(&panel->field30);
    }
    if (panel != NULL) {
        child = M2C_FIELD(panel, Obj **, 0x40);
        if (child != NULL) {
            child->destroy(1);
        }
        child = M2C_FIELD(panel, Obj **, 0x44);
        if (child != NULL) {
            child->destroy(1);
        }
        child = M2C_FIELD(panel, Obj **, 0x38);
        if (child != NULL) {
            child->destroy(1);
        }
        child = M2C_FIELD(panel, Obj **, 0x3C);
        if (child != NULL) {
            child->destroy(1);
        }
        child = M2C_FIELD(panel, Obj **, 0x48);
        if (child != NULL) {
            child->destroy(1);
        }
        child = M2C_FIELD(panel, Obj **, 0x4C);
        if (child != NULL) {
            child->destroy(1);
        }
    }
}
#pragma cplusplus reset
void fn_801C8490(void) {
    void fn_8005C8B4(void *);
    extern u8 lbl_802983A4[];
    fn_8005C8B4(*(void **)(lbl_802983A4 + 4));
}

void fn_801C84BC(s32 arg0) {
    u8 FileCache_IsReady(s32);
    extern s32 lbl_802983A4[];
    if (FileCache_IsReady(lbl_802983A4[1])) {
        Process_ClearFunc(arg0);
    }
}

void fn_801C8504(void *arg0) {
    void *fn_8006E658(void);
    void fn_8006EEFC(void *, void *);
    extern s16 lbl_80366E98, lbl_80366E9A;
    extern u8 lbl_80366E9C, lbl_802983A4[];
    u8 *p = fn_8006E658();
    u8 z;
    int i;
    if (lbl_80366E98 < 0 || lbl_80366E9A < 0) {
        z = 0;
        lbl_80366E98 = *(u16 *)(p + 0xA);
        lbl_80366E9A = *(u16 *)(p + 0xC);
        lbl_80366E9C = z;
        for (i=0; i<7; i++) lbl_80366E9C += p[0x32+i];
        *((u8 *)arg0+0x34) = z;
    }
    fn_8006EEFC((u8 *)arg0+0x30, *(void **)(lbl_802983A4+4));
}

#pragma use_lmw_stmw on
void fn_801C85E0(void *arg0) {
    void fn_80007340(void *, s32);
    void Prim2D_SetRectUv(f32, f32, f32, f32, f32, f32);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Text_Draw(s32, s32, s32, void *, ...);
    s32 Text_MeasureHeight(s32, f32);
    void Ui_LoadAtlasTex(void *, void *, s32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    void fn_80230BBC(s32);
    void fn_80238ABC(char *, s32);
    s32 strlen(char *);
    extern void fn_801C8E84;
    extern u8 lbl_8027D740[];
    extern s8 lbl_80366E9C;
    extern s8 lbl_803682B0;
    extern s8 lbl_803682B1;
    extern f32 lbl_8036B478;
    extern f32 lbl_8036B498;
    extern f32 lbl_8036B49C;
    extern f32 lbl_8036B4A0;

    struct TexWh { u8 tex[0x20]; u16 w; u16 h; } t0, t1, t2, t3;
    char buf0[16];
    char buf1[16];
    char buf2[16];
    s16 rect0[4];
    s16 sc0[4];
    s16 rect1[4];
    s16 sc1[4];
    s16 rect2[4];
    s16 sc2[4];
    void *self = arg0;
    s8 v0, v1, v2;
    s32 len;
    s16 step, x, y, dig;
    char *p;
    s32 pair0, pair1;
    void *obj;
    void (*meth)(void *, s32);
    s8 raw;
    s32 tmp;
    s16 yy;

    if (*(u8 *)((u8 *)self + 0x34) != 0) {
        Prim2D_Begin();
        Prim2D_SetTex((void *)0, 0x410);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(0xB);
        fn_80007340(&fn_801C8E84, 0);
        Prim2D_EndPrim();
        *(u8 *)((u8 *)self + 0x34) = 0;
    }
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B498, lbl_8036B498, lbl_8036B49C, lbl_8036B478);
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();
    Ui_LoadAtlasTex(*(void **)((u8 *)self + 0x30), &t0, 0);
    t0.w = GXGetTexObjWidth(&t0);
    t0.h = GXGetTexObjHeight(&t0);
    Prim2D_Begin();
    Prim2D_SetTex(&t0, 0x10);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetRect(lbl_8036B498, lbl_8036B498, (f32)t0.w, (f32)t0.h);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B4A0);
    Prim2D_PrepareTex();

    raw = lbl_803682B1;
    rect0[0] = 1;
    v0 = -raw;
    rect0[1] = 1;
    rect0[2] = 0x13;
    rect0[3] = 0x1F;
    fn_80230BBC(v0);
    fn_80238ABC(buf0, 0xA);
    len = strlen(buf0);
    Ui_LoadAtlasTex(*(void **)((u8 *)self + 0x30), &t1, 1);
    t1.w = GXGetTexObjWidth(&t1);
    t1.h = GXGetTexObjHeight(&t1);
    Prim2D_Begin();
    Prim2D_SetTex(&t1, 0x11);
    Prim2D_PrepareTex();
    step = (s16)(rect0[2] - rect0[0]);
    pair0 = *(s32 *)&rect0[0];
    pair1 = *(s32 *)&rect0[2];
    x = (s16)(0x108 - (s16)(len * step));
    y = (s16)(((0x30 - (s16)(rect0[3] - rect0[1])) >> 1) + 0x40);
    p = buf0;
    while ((s8)*p != 0) {
        dig = (s16)(((s8)*p - 0x30) * (step + 1));
        *(s32 *)&sc0[0] = pair0;
        *(s32 *)&sc0[2] = pair1;
        sc0[0] = (s16)(sc0[0] + dig);
        sc0[2] = (s16)(sc0[2] + dig);
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)y, (f32)sc0[0], (f32)sc0[1], (f32)(s16)(sc0[2] - sc0[0]),
                    (f32)(s16)(sc0[3] - sc0[1]));
        Prim2D_EndPrim();
        x = (s16)(x + step);
        p++;
    }
    Prim2D_Begin();
    Prim2D_SetTex((void *)0, 0x13);
    Prim2D_PrepareTex();
    tmp = Text_MeasureHeight(-1, lbl_8036B478);
    yy = (s16)(((0x30 - tmp) >> 1) + 0x40);
    if (v0 > 0) {
        Text_Draw(0xC8, yy, 0x10, lbl_8027D740 + 0xDA);
    } else if (v0 < 0) {
        Text_Draw(0xC8, yy, 0x10, lbl_8027D740 + 0xDD);
    }

    raw = lbl_803682B0;
    rect1[0] = 1;
    v1 = raw;
    rect1[1] = 1;
    rect1[2] = 0x13;
    rect1[3] = 0x1F;
    fn_80230BBC(v1);
    fn_80238ABC(buf1, 0xA);
    len = strlen(buf1);
    Ui_LoadAtlasTex(*(void **)((u8 *)self + 0x30), &t2, 1);
    t2.w = GXGetTexObjWidth(&t2);
    t2.h = GXGetTexObjHeight(&t2);
    Prim2D_Begin();
    Prim2D_SetTex(&t2, 0x11);
    Prim2D_PrepareTex();
    step = (s16)(rect1[2] - rect1[0]);
    pair0 = *(s32 *)&rect1[0];
    pair1 = *(s32 *)&rect1[2];
    x = (s16)(0x108 - (s16)(len * step));
    y = (s16)(((0x30 - (s16)(rect1[3] - rect1[1])) >> 1) + 0x90);
    p = buf1;
    while ((s8)*p != 0) {
        dig = (s16)(((s8)*p - 0x30) * (step + 1));
        *(s32 *)&sc1[0] = pair0;
        *(s32 *)&sc1[2] = pair1;
        sc1[0] = (s16)(sc1[0] + dig);
        sc1[2] = (s16)(sc1[2] + dig);
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)y, (f32)sc1[0], (f32)sc1[1], (f32)(s16)(sc1[2] - sc1[0]),
                    (f32)(s16)(sc1[3] - sc1[1]));
        Prim2D_EndPrim();
        x = (s16)(x + step);
        p++;
    }
    Prim2D_Begin();
    Prim2D_SetTex((void *)0, 0x13);
    Prim2D_PrepareTex();
    tmp = Text_MeasureHeight(-1, lbl_8036B478);
    yy = (s16)(((0x30 - tmp) >> 1) + 0x90);
    if (v1 > 0) {
        Text_Draw(0xC8, yy, 0x10, lbl_8027D740 + 0xDA);
    } else if (v1 < 0) {
        Text_Draw(0xC8, yy, 0x10, lbl_8027D740 + 0xDD);
    }

    raw = lbl_80366E9C;
    rect2[0] = 1;
    v2 = (s8)(raw - 0x40);
    rect2[1] = 1;
    rect2[2] = 0x13;
    rect2[3] = 0x1F;
    fn_80230BBC(v2);
    fn_80238ABC(buf2, 0xA);
    len = strlen(buf2);
    Ui_LoadAtlasTex(*(void **)((u8 *)self + 0x30), &t3, 1);
    t3.w = GXGetTexObjWidth(&t3);
    t3.h = GXGetTexObjHeight(&t3);
    Prim2D_Begin();
    Prim2D_SetTex(&t3, 0x11);
    Prim2D_PrepareTex();
    step = (s16)(rect2[2] - rect2[0]);
    pair0 = *(s32 *)&rect2[0];
    pair1 = *(s32 *)&rect2[2];
    x = (s16)(0x108 - (s16)(len * step));
    y = (s16)(((0x30 - (s16)(rect2[3] - rect2[1])) >> 1) + 0x100);
    p = buf2;
    while ((s8)*p != 0) {
        dig = (s16)(((s8)*p - 0x30) * (step + 1));
        *(s32 *)&sc2[0] = pair0;
        *(s32 *)&sc2[2] = pair1;
        sc2[0] = (s16)(sc2[0] + dig);
        sc2[2] = (s16)(sc2[2] + dig);
        Prim2D_AddPrim(1);
        Prim2D_SetRectUv((f32)x, (f32)y, (f32)sc2[0], (f32)sc2[1], (f32)(s16)(sc2[2] - sc2[0]),
                    (f32)(s16)(sc2[3] - sc2[1]));
        Prim2D_EndPrim();
        x = (s16)(x + step);
        p++;
    }
    Prim2D_Begin();
    Prim2D_SetTex((void *)0, 0x13);
    Prim2D_PrepareTex();
    tmp = Text_MeasureHeight(-1, lbl_8036B478);
    yy = (s16)(((0x30 - tmp) >> 1) + 0x100);
    if (v2 > 0) {
        Text_Draw(0xC8, yy, 0x10, lbl_8027D740 + 0xDA);
    } else if (v2 < 0) {
        Text_Draw(0xC8, yy, 0x10, lbl_8027D740 + 0xDD);
    }

    obj = *(void **)((u8 *)self + 0x38);
    meth = *(void (**)(void *, s32))(*(u8 **)obj + 0x2C);
    meth(obj, 0x10);
    obj = *(void **)((u8 *)self + 0x3C);
    meth = *(void (**)(void *, s32))(*(u8 **)obj + 0x2C);
    meth(obj, 0x10);
    obj = *(void **)((u8 *)self + 0x40);
    meth = *(void (**)(void *, s32))(*(u8 **)obj + 0x2C);
    meth(obj, 0x10);
    obj = *(void **)((u8 *)self + 0x44);
    meth = *(void (**)(void *, s32))(*(u8 **)obj + 0x2C);
    meth(obj, 0x10);
    obj = *(void **)((u8 *)self + 0x48);
    meth = *(void (**)(void *, s32))(*(u8 **)obj + 0x2C);
    meth(obj, 0x10);
    obj = *(void **)((u8 *)self + 0x4C);
    meth = *(void (**)(void *, s32))(*(u8 **)obj + 0x2C);
    meth(obj, 0x10);
}
void fn_801C8E84(void) {
    void *fn_8006E658(void);
    void VIConfigure(void *);
    void fn_80221824(u8, void *, s32, void *);
    void *memcpy(void *, void *, u32);
    extern s16 lbl_80366E98;
    extern s16 lbl_80366E9A;
    extern u8 lbl_80366E9C;
    extern s32 gGameFlags;
    extern s8 lbl_803682B0;
    extern s8 lbl_803682B1;
    extern f32 lbl_8036B478;
    extern f32 lbl_8036B47C;
    extern f32 lbl_8036B480;
    extern f32 lbl_8036B484;
    extern s32 lbl_8036C51C;
    extern u16 lbl_8036C520;
    extern u8 lbl_8036C522;

    struct {
        s32 unk0;
        u16 unk4;
        u8 unk6;
    } sp10;
    u32 spC;
    u32 sp8;
    void *temp_r3;
    f32 var_f2;
    s32 temp_r0;
    u16 temp_r8;
    u8 *var_r6;
    s32 var_r9;
    s32 count;
    s32 temp_r9;
    s32 var_ctr;
    u8 *var_r6_2;
    s32 var_r8;

    temp_r3 = fn_8006E658();
    *(s16 *)((u8 *)temp_r3 + 0xA) = (s16)(lbl_80366E98 + lbl_803682B0);
    *(s16 *)((u8 *)temp_r3 + 0xC) = (s16)(lbl_80366E9A + lbl_803682B1);
    VIConfigure(temp_r3);
    if (gGameFlags & 0x40) {
        var_f2 = lbl_8036B478;
    } else {
        var_f2 = lbl_8036B47C;
    }
    var_r6 = (u8 *)&sp8;
    var_r9 = 0;
    temp_r0 = (s32)((f32)(s8)lbl_80366E9C * var_f2);
    temp_r8 = (s8)lbl_80366E9C - (u16)temp_r0;
    count = temp_r8 % 4;
    for (var_ctr = 2; var_ctr != 0; var_ctr--) {
        if (var_r9 < count) {
            *var_r6 = (u8)(s32)((f32)temp_r8 * lbl_8036B480 + lbl_8036B478);
        } else {
            *var_r6 = (u8)(s32)((f32)temp_r8 * lbl_8036B480);
        }
        var_r9 += 1;
        if (var_r9 < count) {
            var_r6[1] = (u8)(s32)((f32)temp_r8 * lbl_8036B480 + lbl_8036B478);
        } else {
            var_r6[1] = (u8)(s32)((f32)temp_r8 * lbl_8036B480);
        }
        var_r6 += 2;
        var_r9 += 1;
    }
    var_r6_2 = (u8 *)&spC;
    var_r8 = 0;
    for (var_ctr = 3; var_ctr != 0; var_ctr--) {
        if (var_r8 < (s32)((u16)temp_r0 % 3)) {
            *var_r6_2 = (u8)(s32)(lbl_8036B478 + (f32)(u16)temp_r0 / lbl_8036B484);
        } else {
            *var_r6_2 = (u8)(s32)((f32)(u16)temp_r0 / lbl_8036B484);
        }
        var_r6_2 += 1;
        var_r8 += 1;
    }
    sp10.unk0 = lbl_8036C51C;
    sp10.unk4 = lbl_8036C520;
    sp10.unk6 = lbl_8036C522;
    *(u8 *)&sp10.unk0 = *((u8 *)&sp8 + 2);
    *((u8 *)&sp10.unk0 + 1) = *(u8 *)&sp8;
    *((u8 *)&sp10.unk0 + 2) = *((u8 *)&spC + 1);
    *((u8 *)&sp10.unk0 + 3) = *(u8 *)&spC;
    *(u8 *)&sp10.unk4 = *((u8 *)&spC + 2);
    *((u8 *)&sp10.unk4 + 1) = *((u8 *)&sp8 + 1);
    sp10.unk6 = *((u8 *)&sp8 + 3);
    fn_80221824(*(u8 *)((u8 *)temp_r3 + 0x19), (u8 *)temp_r3 + 0x1A, 1, &sp10);
    memcpy((u8 *)temp_r3 + 0x32, &sp10, 7);
}

void fn_801C9170(void *arg0) {
    void Process_ClearFunc(void *);
    void Ui_PlaySeCue(void *, s32);
    void fn_801E3560(void *, u8, u8, u8);
    extern char lbl_8027D740[];
    extern u8 gBattleState[];
    extern u8 gSystemSave[];
    extern u8 lbl_80366E9C;
    extern void *gPadInput;
    extern s8 lbl_803682B0;
    extern s8 lbl_803682B1;
    void *self;
    s32 *pad;
    s32 held;
    s32 trig;
    s32 buttons;
    void *obj;
    u8 b0;
    u8 b1;
    u8 b2;

    self = arg0;
    pad = (s32 *)gPadInput;
    b0 = lbl_803682B0;
    buttons = pad[3];
    held = pad[1];
    trig = held & (pad[2] ^ held);

    if ((s8)b0 > -0x14 && (buttons & 0x01000001)) {
        lbl_803682B0 = b0 - 1;
        *(u8 *)((u8 *)self + 0x34) = 1;
        obj = *(void **)((u8 *)self + 0x40);
        *(s16 *)((u8 *)obj + 0x16) = 1;
        *(u8 *)((u8 *)obj + 0xD) = 0;
        Ui_PlaySeCue(lbl_8027D740 + 0xE0, 0x64);
    } else if ((s8)b0 < 0x14 && (buttons & 0x02000002)) {
        lbl_803682B0 += 1;
        *(u8 *)((u8 *)self + 0x34) = 1;
        obj = *(void **)((u8 *)self + 0x44);
        *(s16 *)((u8 *)obj + 0x16) = 1;
        *(u8 *)((u8 *)obj + 0xD) = 0;
        Ui_PlaySeCue(lbl_8027D740 + 0xE0, 0x64);
    }

    b1 = lbl_803682B1;
    if ((s8)b1 > -0xF && (buttons & 0x08000008)) {
        lbl_803682B1 = b1 - 1;
        *(u8 *)((u8 *)self + 0x34) = 1;
        obj = *(void **)((u8 *)self + 0x38);
        *(s16 *)((u8 *)obj + 0x16) = 1;
        *(u8 *)((u8 *)obj + 0xD) = 0;
        Ui_PlaySeCue(lbl_8027D740 + 0xF5, 0x64);
    } else if ((s8)b1 < 0xF && (buttons & 0x04000004)) {
        lbl_803682B1 += 1;
        *(u8 *)((u8 *)self + 0x34) = 1;
        obj = *(void **)((u8 *)self + 0x3C);
        *(s16 *)((u8 *)obj + 0x16) = 1;
        *(u8 *)((u8 *)obj + 0xD) = 0;
        Ui_PlaySeCue(lbl_8027D740 + 0xF5, 0x64);
    }

    b2 = lbl_80366E9C;
    if ((s8)b2 > 0xE && (buttons & 0x40000000)) {
        lbl_80366E9C = b2 - 1;
        *(u8 *)((u8 *)self + 0x34) = 1;
        obj = *(void **)((u8 *)self + 0x4C);
        *(s16 *)((u8 *)obj + 0x16) = 1;
        *(u8 *)((u8 *)obj + 0xD) = 0;
        Ui_PlaySeCue(lbl_8027D740 + 0x10A, 0x64);
    } else if ((s8)b2 < 0x72 && (buttons & 0x80000000)) {
        lbl_80366E9C += 1;
        *(u8 *)((u8 *)self + 0x34) = 1;
        obj = *(void **)((u8 *)self + 0x48);
        *(s16 *)((u8 *)obj + 0x16) = 1;
        *(u8 *)((u8 *)obj + 0xD) = 0;
        Ui_PlaySeCue(lbl_8027D740 + 0x10A, 0x64);
    }

    if (trig & 0x100) {
        fn_801E3560(gSystemSave, lbl_803682B0, lbl_803682B1, lbl_80366E9C);
        gBattleState[0xA3] = lbl_803682B1;
        gBattleState[0xA2] = lbl_803682B0;
        gBattleState[0xA1] = lbl_80366E9C;
        Ui_PlaySeCue(lbl_8027D740 + 0x121, 0x64);
        Process_ClearFunc(self);
    } else if (trig & 0x200) {
        lbl_803682B0 = gBattleState[0xA2];
        lbl_803682B1 = gBattleState[0xA3];
        lbl_80366E9C = gBattleState[0xA1];
        *(u8 *)((u8 *)self + 0x34) = 1;
        Ui_PlaySeCue(lbl_8027D740 + 0x131, 0x64);
        Process_ClearFunc(self);
    }
}

void Game_InitVideo(void) {
    /* Init VI, pick TV render modes from soft-reset, DEMOInit, then clear and copy the display. */
    void VIInit(void);
    s32 VIGetTvFormat(void);
    u32 OSGetResetCode(void);
    s32 DemoGetCurrentBuffer(void);
    void DEMOInit(void *);
    void OSPanic(char *, s32, char *, ...);
    void GXSetCopyClear(void *, s32);
    void GXCopyDisp(s32, s32);
    extern s32 gGameFlags;
    extern void *gGameRenderMode;
    extern void *gGameRenderModeProg;
    extern u8 GameNtsc480IntDf[];
    extern u8 GameNtsc480Prog[];
    extern u8 GamePal528IntDf[];
    extern u8 GameEurgb60Hz480IntDf[];
    extern u8 GameMpal480IntDf[];
    extern char lbl_8027D740[];
    extern s32 gClearColor;

    s32 clearColor;
    s32 tvFormat;

    VIInit();
    tvFormat = VIGetTvFormat();
    switch (tvFormat) {
    case 0:
        gGameRenderMode = GameNtsc480IntDf;
        gGameRenderModeProg = GameNtsc480Prog;
        gGameFlags |= 0x10000;
        break;
    case 1:
        gGameRenderMode = GamePal528IntDf;
        gGameRenderModeProg = GameEurgb60Hz480IntDf;
        gGameFlags |= 0x20000;
        break;
    case 5:
        gGameRenderMode = GameEurgb60Hz480IntDf;
        gGameRenderModeProg = GameEurgb60Hz480IntDf;
        gGameFlags |= 0x40000;
        break;
    case 2:
        gGameRenderMode = GameMpal480IntDf;
        gGameRenderModeProg = GameNtsc480Prog;
        gGameFlags |= 0x80000;
        break;
    default:
        OSPanic(lbl_8027D740 + 0x141, 0xE1, lbl_8027D740 + 0x14B);
        break;
    }

    if (gGameFlags & 0x10000) {
        if ((OSGetResetCode() >> 31) == 0 || (OSGetResetCode() & 2)) {
            DEMOInit(gGameRenderMode);
            gGameFlags &= ~0x40;
        } else {
            if (!(OSGetResetCode() & 1)) {
                DEMOInit(gGameRenderMode);
                gGameFlags &= ~0x40;
            } else {
                DEMOInit(gGameRenderModeProg);
                gGameFlags |= 0x40;
            }
            gGameFlags |= 0x30;
        }
    } else if (gGameFlags & 0x80000) {
        if ((OSGetResetCode() >> 31) == 0 || (OSGetResetCode() & 2)) {
            DEMOInit(gGameRenderMode);
            gGameFlags &= ~0x40;
        } else {
            if (!(OSGetResetCode() & 1)) {
                DEMOInit(gGameRenderMode);
                gGameFlags &= ~0x40;
            } else {
                DEMOInit(gGameRenderModeProg);
                gGameFlags |= 0x40;
            }
            gGameFlags |= 0x30;
        }
    } else if (gGameFlags & 0x60000) {
        if ((OSGetResetCode() >> 31) == 0 || (OSGetResetCode() & 0x20)) {
            DEMOInit(gGameRenderMode);
            gGameFlags &= ~0x100;
        } else {
            if (!(OSGetResetCode() & 0x10)) {
                DEMOInit(gGameRenderMode);
                gGameFlags &= ~0x100;
            } else {
                DEMOInit(gGameRenderModeProg);
                gGameFlags |= 0x100;
            }
            gGameFlags |= 0x30;
        }
    }

    clearColor = gClearColor;
    GXSetCopyClear(&clearColor, 0xFFFFFF);
    GXCopyDisp(DemoGetCurrentBuffer(), 1);
}

s32 fn_801C9704(void) {
    extern s32 gGameRenderModeProg;
    return gGameRenderModeProg;
}

s32 fn_801C970C(void) {
    extern s32 gGameRenderMode;
    return gGameRenderMode;
}

void fn_801C9714(void) {
    extern s32 gGameFlags;
    gGameFlags &= 0xFFFFFFFE;
}

void fn_801C9724(void) {
    extern s32 gGameFlags;
    gGameFlags |= 1;
}

s32 CameraWin_OnCancel(void) {
    s32 String_Compare(void *, u32, u32, char *, u32);
    void String_Assign(void *, void *, u32, u32);
    void fn_800C992C(void *, const char *, u32);
    void fn_800C99A0(void *, void *, u32, u32);
    void String_Destroy(void *, s16);
    void String_ConcatCStr(void *, void *, char *);
    void fn_800DF6DC(void *, s32);
    s32 fn_8011C984(s32, s32);
    s32 fn_8011C9E4(s32);
    void fn_801CA814(s32, void *);
    void fn_801CB25C(void *, s32);
    u32 strlen(const char *);
    extern char CameraWin_str[];
    extern void *gGame;
    extern void *gCameraWin;
    struct Str {
        u32 size;
        u32 cap;
        char *data;
    };
    // Build {gGame}xcam/[dir/]name.dbx from the anime box and write it out.
    struct Str path;
    struct Str dirName;
    struct Str dirTmp;
    struct Str dirSlash;
    struct Str baseName;
    void *win;
    u32 len;

    path.cap = 0;
    win = gCameraWin;
    dirName.cap = 0;
    path.size = 0;
    path.data = 0;
    path.cap = 0;
    dirName.size = 0;
    dirName.data = 0;
    dirName.cap = 0;

    win = (void *)fn_8011C984(*(s32 *)((u8 *)win + 0x430), fn_8011C9E4(*(s32 *)((u8 *)win + 0x430)));

    fn_801CB25C(&dirTmp, (s32)win);
    String_Assign(&dirName, &dirTmp, 0, -1);
    String_Destroy(&dirTmp, -1);
    String_Assign(&path, gGame, 0, -1);

    len = strlen(&CameraWin_str[8]);
    fn_800C992C(&path, (char *)CameraWin_str + 8, len);

    len = strlen((char *)CameraWin_str + 0xE);
    if (String_Compare(&dirName, 0, dirName.size, &CameraWin_str[0xE], len) != 0) {
        String_ConcatCStr(&dirSlash, &dirName, (char *)CameraWin_str + 0xF);
        fn_800C99A0(&path, &dirSlash, 0, -1);
        String_Destroy(&dirSlash, -1);
    }

    fn_800DF6DC(&baseName, (s32)win);
    fn_800C99A0(&path, &baseName, 0, -1);
    String_Destroy(&baseName, -1);

    len = strlen(&CameraWin_str[0x11]);
    fn_800C992C(&path, (char *)CameraWin_str + 0x11, len);

    fn_801CA814((s32)win, &path);
    String_Destroy(&dirName, -1);
    String_Destroy(&path, -1);
    return 0;
}

s32 fn_801C98EC(void) {
    s32 fn_8011C984(s32, s32);
    s32 fn_8011C9E4(s32);
    void fn_801CAF94(s32, s32, s32, s32, s32);
    extern void *gCameraWin;
    void *temp_r31;

    temp_r31 = gCameraWin;
    fn_801CAF94(
        fn_8011C984(M2C_FIELD(temp_r31, s32 *, 0x430), fn_8011C9E4(M2C_FIELD(temp_r31, s32 *, 0x430))),
        0, 0, 0, 1);
    return 0;
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
s32 CameraWin_CaptureKeyframe(void) {
    /* Snapshot current camera eye/look-at/FOV and slot id into the selected CameraWin keyframe. */
    void *fn_800DC3B0(void *);
    s32 fn_8011C9E4(s32);
    s32 fn_8011C984(s32, s32);
    void *CameraAnim_GetKeyframe(void *, s32);
    void *CameraAnim_GetCamera(void *);
    void Camera_GetEyePos(f32 *, void *);
    void Camera_GetLookAt(f32 *, void *);
    f32 Camera_GetFov(void *);
    extern void *gCameraWin;

    f32 eyeZ;
    f32 eyeY;
    f32 eyeX;
    f32 lookZ;
    f32 lookY;
    f32 lookX;
    void *keyframe;
    void *cam;
    s32 index;
    f32 eye[3];
    f32 lookAt[3];
    f32 fov;
    u32 slot;

    index = (s32)fn_800DC3B0(*(void **)((u8 *)gCameraWin + 0x438));
    cam = gCameraWin;
    cam = (void *)fn_8011C984(*(s32 *)((u8 *)cam + 0x430), fn_8011C9E4(*(s32 *)((u8 *)cam + 0x430)));
    keyframe = CameraAnim_GetKeyframe(cam, index);
    Camera_GetEyePos(eye, cam = CameraAnim_GetCamera(cam));
    eyeX = eye[0];
    eyeY = eye[1];
    eyeZ = eye[2];
    Camera_GetLookAt(lookAt, cam);
    lookX = lookAt[0];
    lookY = lookAt[1];
    lookZ = lookAt[2];
    fov = Camera_GetFov(cam);
    slot = *(u32 *)((u8 *)*(void **)((u8 *)gCameraWin + 0x42C) + (index << 2));
    *(f32 *)((u8 *)keyframe + 0x00) = eyeX;
    *(f32 *)((u8 *)keyframe + 0x04) = eyeY;
    *(f32 *)((u8 *)keyframe + 0x08) = eyeZ;
    *(f32 *)((u8 *)keyframe + 0x0C) = lookX;
    *(f32 *)((u8 *)keyframe + 0x10) = lookY;
    *(f32 *)((u8 *)keyframe + 0x14) = lookZ;
    *(f32 *)((u8 *)keyframe + 0x18) = fov;
    *(u32 *)((u8 *)keyframe + 0x1C) = slot;
    return 0;
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset
s32 fn_801C9A88(void) {
    return 0;
}

s32 fn_801C9A90(void) {
    s32 fn_800DC3B0(s32);
    s32 fn_8011C984(s32, s32);
    s32 fn_8011C9E4(s32);
    void CameraWin_LoadList(void *, s32);
    void fn_801CACE4(void *, s32);
    extern void *gCameraWin;
    s32 temp_r30;
    void *temp_r31;

    temp_r30 = fn_800DC3B0(M2C_FIELD(gCameraWin, s32 *, 0x438));
    temp_r31 = gCameraWin;
    fn_801CACE4((void *)fn_8011C984(M2C_FIELD(temp_r31, s32 *, 0x430), fn_8011C9E4(M2C_FIELD(temp_r31, s32 *, 0x430))), temp_r30);
    CameraWin_LoadList(gCameraWin, fn_8011C9E4(M2C_FIELD(gCameraWin, s32 *, 0x430)));
    return 0;
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
s32 fn_801C9B08(void) {
    void *fn_800DC3B0(void *);
    s32 fn_8011C9E4(s32);
    s32 fn_8011C984(s32, s32);
    void *CameraAnim_GetCamera(void *);
    void Camera_GetEyePos(f32 *, void *);
    void Camera_GetLookAt(f32 *, void *);
    f32 Camera_GetFov(void *);
    void fn_801CAD38(s32, s32, void *);
    void CameraWin_LoadList(void *, s32);
    extern void *gCameraWin;

    f32 eyeZ;
    f32 eyeY;
    f32 eyeX;
    f32 lookZ;
    f32 lookY;
    f32 lookX;
    void *handle;
    void *cam;
    s32 index;
    f32 eye[3];
    f32 lookAt[3];
    f32 fov;
    struct {
        f32 eyeX, eyeY, eyeZ;
        f32 lookX, lookY, lookZ;
        f32 fov;
        u32 unk;
    } data;

    index = (s32)fn_800DC3B0(*(void **)((u8 *)gCameraWin + 0x438));
    handle = gCameraWin;
    handle = (void *)fn_8011C984(*(s32 *)((u8 *)handle + 0x430), fn_8011C9E4(*(s32 *)((u8 *)handle + 0x430)));
    Camera_GetEyePos(eye, cam = CameraAnim_GetCamera(handle));
    eyeX = eye[0];
    eyeY = eye[1];
    eyeZ = eye[2];
    Camera_GetLookAt(lookAt, cam);
    lookX = lookAt[0];
    lookY = lookAt[1];
    lookZ = lookAt[2];
    fov = Camera_GetFov(cam);
    data.eyeX = eyeX;
    data.eyeY = eyeY;
    data.eyeZ = eyeZ;
    data.lookX = lookX;
    data.lookY = lookY;
    data.lookZ = lookZ;
    data.fov = fov;
    data.unk = 0x14;
    fn_801CAD38((s32)handle, index, &data);
    CameraWin_LoadList(gCameraWin, fn_8011C9E4(*(s32 *)((u8 *)gCameraWin + 0x430)));
    return 0;
}
#pragma global_optimizer reset
#pragma use_lmw_stmw reset

s32 fn_801C9C5C(void) {
    s32 fn_800DC3B0(s32);
    s32 fn_8011C984(s32, s32);
    s32 fn_8011C9E4(s32);
    void fn_801CADBC(s32, s32);
    extern void *gCameraWin;
    void *temp_r31;
    s32 temp_r31_2;
    s32 temp_r0;

    temp_r31 = gCameraWin;
    temp_r31_2 = fn_8011C984(M2C_FIELD(temp_r31, s32 *, 0x430), fn_8011C9E4(M2C_FIELD(temp_r31, s32 *, 0x430)));
    temp_r0 = fn_800DC3B0(M2C_FIELD(gCameraWin, s32 *, 0x438));
    fn_801CADBC(temp_r31_2, temp_r0);
    return 0;
}

s32 fn_801C9CBC(void) {
    extern void *gCameraWin;
    void String_Assign(void *, void *, s32, s32);
    void String_Destroy(void *, s32);
    void fn_801C9D94(void *, void *);
    void fn_801CAF58(void *, void *);
    s32 fn_8011C984(s32, s32);
    s32 fn_8011C9E4(s32);

    struct Str {
        u32 size;
        u32 cap;
        char *data;
    };
    struct Str sp14;
    struct Str sp8;
    void *obj;
    s32 handle;

    sp14.cap = 0;
    obj = gCameraWin;
    sp14.size = 0;
    sp14.data = 0;
    sp14.cap = 0;

    handle = fn_8011C984(*(s32 *)((u8 *)obj + 0x430),
                         fn_8011C9E4(*(s32 *)((u8 *)obj + 0x430)));

    fn_801C9D94(&sp8, gCameraWin);
    String_Assign(&sp14, &sp8, 0, -1);
    String_Destroy(&sp8, -1);
    fn_801CAF58((void *)handle, &sp14);
    String_Destroy(&sp14, -1);

    return 0;
}

s32 fn_801C9D58(void) {
    s32 fn_8011C9E4(s32);
    void CameraWin_LoadList(void *, s32);
    extern void *gCameraWin;

    s32 temp_r3 = fn_8011C9E4(*(s32 *)((char *)gCameraWin + 0x430));
    CameraWin_LoadList(gCameraWin, temp_r3);
    return 0;
}

void fn_801C9D94(void *dst, void *win) {
    void *__register_global_object(void *, void (*)(void), void *);
    void *String_Init(void *, char *, void *);
    void String_Destroy(void);
    void String_Copy(void *, void *);
    s32 fn_8011C9E4(void *);
    extern char CameraWin_str[];
    extern u8 lbl_80331C88[];
    extern s8 lbl_803682BC;

    typedef struct Str { u32 size; u32 cap; char *data; } Str;
    typedef struct Blk {
        u8 reg[0x3C];
        Str strs[5];
    } Blk;
    void *sp18;
    void *sp14;
    void *sp10;
    void *spC;
    void *sp8;
    Blk *base;

    base = (Blk *)lbl_80331C88;

    if ((s8)lbl_803682BC == 0) {
        __register_global_object(String_Init(&base->strs[0], CameraWin_str + 0x21, &sp18),
                                 String_Destroy, (u8 *)base + 0);
        __register_global_object(String_Init(&base->strs[1], CameraWin_str + 0x2C, &sp14),
                                 String_Destroy, (u8 *)base + 0xC);
        __register_global_object(String_Init(&base->strs[2], CameraWin_str + 0x37, &sp10),
                                 String_Destroy, (u8 *)base + 0x18);
        __register_global_object(String_Init(&base->strs[3], CameraWin_str + 0x42, &spC),
                                 String_Destroy, (u8 *)base + 0x24);
        __register_global_object(String_Init(&base->strs[4], CameraWin_str + 0x4D, &sp8),
                                 String_Destroy, (u8 *)base + 0x30);
        lbl_803682BC = 1;
    }
    String_Copy(dst, &base->strs[fn_8011C9E4(*(void **)((u8 *)win + 0x434))]);
}

#pragma use_lmw_stmw on
#pragma optimization_level 2
#pragma global_optimizer off
/* Reload CameraWin anim list for a category and set the camChara side mode. */
void CameraWin_LoadList(void *arg0, s32 arg1) {
    s32 String_Compare(void *, s32, u32, char *, u32);
    void String_AssignCStr(void *, char *, u32);
    void String_Assign(void *, void *, s32, s32);
    void String_Destroy(void *, s32);
    void String_Copy(void *, void *);
    void fn_800C9BC4(void *, void *, s32, void *);
    void fn_800DC454(void *);
    void fn_800DC518(void *, void *, void *);
    void fn_800DF6DC(void *, s32);
    s32 fn_8011C984(s32, s32);
    void fn_8011C9A8(s32, s32);
    void fn_801CADBC(s32, s32);
    void *CameraAnim_GetKeyframe(s32, s32);
    s32 fn_801CAF50(void);
    s32 CameraAnim_GetCamera(s32);
    void sprintf(char *, char *, ...);
    u32 strlen(const char *);
    extern char CameraWin_str[];

    struct Str {
        u32 size;
        u32 cap;
        char *data;
    };
    struct Entry {
        u8 pad[0x1C];
        s32 nameId;
    };
    char label[0x30];
    struct Str tempStr;
    struct Str pathStr;
    struct Str listStr;
    struct Str pathTmp;
    void *self;
    s32 handle;
    s32 count;
    struct Entry *entry;
    u32 len;
    char *base;

    self = arg0;
    tempStr.cap = 0;
    pathStr.cap = 0;
    tempStr.size = 0;
    tempStr.data = 0;
    tempStr.cap = 0;
    pathStr.size = 0;
    pathStr.data = 0;
    pathStr.cap = 0;

    fn_800DC454(*(void **)((u8 *)self + 0x438));
    *(s32 *)((u8 *)self + 0x428) = 0;
    handle = fn_8011C984(*(s32 *)((u8 *)self + 0x430), arg1);
    count = fn_801CAF50();
    base = CameraWin_str;
    for (arg1 = 0; arg1 < count; arg1++) {
        entry = (struct Entry *)CameraAnim_GetKeyframe(handle, arg1);
        sprintf(label, base + 0x16, arg1, entry->nameId);
        String_AssignCStr(&tempStr, label, strlen(label));
        String_Copy(&listStr, &tempStr);
        fn_800DC518(*(void **)((u8 *)self + 0x438), &listStr, entry);
        String_Destroy(&listStr, -1);
        fn_800C9BC4((u8 *)self + 0x424,
                    (void *)(*(s32 *)((u8 *)self + 0x42C) + (*(s32 *)((u8 *)self + 0x428) * 4)),
                    1, &entry->nameId);
    }

    fn_800DF6DC(&pathTmp, CameraAnim_GetCamera(handle));
    String_Assign(&pathStr, &pathTmp, 0, -1);
    String_Destroy(&pathTmp, -1);

    len = strlen((char *)((u8 *)CameraWin_str + 0x21));
    if (String_Compare(&pathStr, 0, pathStr.size, (char *)((u32)CameraWin_str + 0x21), len) == 0) {
        fn_8011C9A8(*(s32 *)((u8 *)self + 0x434), 0);
    } else {
        len = strlen((char *)((u8 *)CameraWin_str + 0x2C));
        if (String_Compare(&pathStr, 0, pathStr.size, (char *)((u32)CameraWin_str + 0x2C), len) == 0) {
            fn_8011C9A8(*(s32 *)((u8 *)self + 0x434), 1);
        } else {
            len = strlen((char *)((u8 *)CameraWin_str + 0x37));
            if (String_Compare(&pathStr, 0, pathStr.size, (char *)((u32)CameraWin_str + 0x37), len) == 0) {
                fn_8011C9A8(*(s32 *)((u8 *)self + 0x434), 2);
            } else {
                len = strlen((char *)((u8 *)CameraWin_str + 0x42));
                if (String_Compare(&pathStr, 0, pathStr.size, (char *)((u32)CameraWin_str + 0x42), len) == 0) {
                    fn_8011C9A8(*(s32 *)((u8 *)self + 0x434), 3);
                } else {
                    len = strlen((char *)((u8 *)CameraWin_str + 0x4D));
                    if (String_Compare(&pathStr, 0, pathStr.size, (char *)((u32)CameraWin_str + 0x4D), len) == 0) {
                        fn_8011C9A8(*(s32 *)((u8 *)self + 0x434), 4);
                    }
                }
            }
        }
    }

    fn_801CADBC(handle, 0);
    String_Destroy(&pathStr, -1);
    String_Destroy(&tempStr, -1);
}
#pragma global_optimizer reset
#pragma optimization_level reset
#pragma use_lmw_stmw reset

void fn_801CA1B8(s32 arg0) {
    void CameraWin_LoadList(s32, s32);
    CameraWin_LoadList(arg0, 0);
}

void fn_801CA1DC(void *arg0, s32 arg1) {
    M2C_UNK String_Destroy(M2C_UNK *, M2C_UNK);
    M2C_UNK fn_8011CAAC(s32, M2C_UNK *, s32);
    M2C_UNK fn_801CB280(M2C_UNK *);
    M2C_UNK sp8;

    fn_801CB280(&sp8);
    fn_8011CAAC(M2C_FIELD(arg0, s32 *, 0x430), &sp8, arg1);
    String_Destroy(&sp8, -1);
}

void fn_801CA234(void *arg0, s32 arg1, u32 arg2, u32 arg3)
{
    void fn_800D7254(void *, s32, u32, u32);
    s32 fn_800DC3B0(void *);
    void fn_800DC408(void *, s32, void *);
    void String_AssignCStr(void *, const char *, u32);
    void String_Destroy(void *, s32);
    s32 sprintf(char *, const char *, ...);
    u32 strlen(const char *);

    extern char CameraWin_str[];

    struct String {
        u32 size;
        u32 cap;
        char *data;
    };

    u8 *self;
    s32 index;
    s32 value;
    s32 *values;

    self = (u8 *)arg0;

    if (self[0x420] != 0 || (arg2 & 0x1000) != 0) {
        fn_800D7254(arg0, arg1, arg2, arg3);
    }

    if (*(s32 *)self != 0 || *(s32 *)(self + 4) != 3) {
        return;
    }

    index = fn_800DC3B0(*(void **)(self + 0x438));
    values = *(s32 **)(self + 0x42C);
    value = values[index];

    if (arg3 & 1) {
        struct String str;
        char buffer[0x3C];

        value--;

        if (value < 0) {
            value = 0;
        }

        str.size = 0;
        str.cap = 0;
        str.data = 0;
        str.cap = 0;

        values[index] = value;

        sprintf(buffer, CameraWin_str + 0x16, index, value);
        String_AssignCStr(&str, buffer, strlen(buffer));

        fn_800DC408(
            *(void **)(self + 0x438),
            index,
            &str
        );

        String_Destroy(&str, -1);
    } else if (arg3 & 2) {
        struct String str;
        char buffer[0x60];

        value++;

        if (value > 0x3E7) {
            value = 0x3E7;
        }

        str.size = 0;
        str.cap = 0;
        str.data = 0;
        str.cap = 0;

        values[index] = value;

        sprintf(buffer, CameraWin_str + 0x16, index, value);
        String_AssignCStr(&str, buffer, strlen(buffer));

        fn_800DC408(
            *(void **)(self + 0x438),
            index,
            &str
        );

        String_Destroy(&str, -1);
    }
}

#pragma cplusplus off
/* Construct the ztool CameraWin window and wire its child controls. */
void *CameraWin_Create(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void fn_801C9B08(void);
    void String_Init(void *, char *, void *);
    void String_ConcatCStr(void *, void *, char *);
    void String_Destroy(void *, s16);
    void fn_800D764C(void *, s32, s32, s32, void *, void *);
    void *fn_800D75FC(void *, void *);
    void fn_800E3F54(void *);
    extern char CameraWin_str[];
    extern u8 CameraWin_vtable[];
    u32 pathBase[3];
    u32 dbxPath[3];
    u32 winName[3];
    u32 camAnimeBox[3];
    u32 cameraBox[3];
    u32 animeList[3];
    u32 addBtn[3];
    u32 deleteBtn[3];
    u32 clearBtn[3];
    u32 setBtn[3];
    u32 okBtn[3];
    u32 cancelBtn[3];
    void *sp30;
    void *sp2C;
    void *sp28;
    void *sp24;
    void *sp20;
    void *sp1C;
    void *sp18;
    void *sp14;
    void *sp10;
    void *spC;
    void *sp8;
    u8 *self;
    void *ok;
    self = (u8 *)arg0;
    String_Init(pathBase, CameraWin_str + 0x52, &sp30);
    String_ConcatCStr(dbxPath, pathBase, CameraWin_str + 0x59);
    String_Init(winName, CameraWin_str + 0x67, &sp2C);
    fn_800D764C(self, arg1, arg2, arg3, dbxPath, winName);
    String_Destroy(winName, -1);
    String_Destroy(dbxPath, -1);
    String_Destroy(pathBase, -1);
    *(void **)(self + 0xC) = CameraWin_vtable;
    *(u32 *)(self + 0x424) = 0;
    *(u32 *)(self + 0x428) = 0;
    *(u32 *)(self + 0x42C) = 0;
    String_Init(camAnimeBox, CameraWin_str + 0x71, &sp28);
    *(void **)(self + 0x430) = fn_800D75FC(self, camAnimeBox);
    String_Destroy(camAnimeBox, -1);
    String_Init(cameraBox, CameraWin_str + 0x7d, &sp24);
    *(void **)(self + 0x434) = fn_800D75FC(self, cameraBox);
    String_Destroy(cameraBox, -1);
    String_Init(animeList, CameraWin_str + 0x87, &sp20);
    *(void **)(self + 0x438) = fn_800D75FC(self, animeList);
    String_Destroy(animeList, -1);
    String_Init(addBtn, CameraWin_str + 0x91, &sp1C);
    *(void **)(self + 0x43c) = fn_800D75FC(self, addBtn);
    String_Destroy(addBtn, -1);
    String_Init(deleteBtn, CameraWin_str + 0x98, &sp18);
    *(void **)(self + 0x440) = fn_800D75FC(self, deleteBtn);
    String_Destroy(deleteBtn, -1);
    String_Init(clearBtn, CameraWin_str + 0xa2, &sp14);
    *(void **)(self + 0x444) = fn_800D75FC(self, clearBtn);
    String_Destroy(clearBtn, -1);
    String_Init(setBtn, CameraWin_str + 0xab, &sp10);
    *(void **)(self + 0x448) = fn_800D75FC(self, setBtn);
    String_Destroy(setBtn, -1);
    String_Init(okBtn, CameraWin_str + 0xb2, &spC);
    ok = fn_800D75FC(self, okBtn);
    *(void **)(self + 0x44C) = ok;
    *(void **)(self + 0x418) = ok;
    String_Destroy(okBtn, -1);
    String_Init(cancelBtn, CameraWin_str + 0xb8, &sp8);
    *(void **)(self + 0x450) = fn_800D75FC(self, cancelBtn);
    String_Destroy(cancelBtn, -1);
    *(void **)(*(u8 **)(self + 0x430) + 0xFC) = (void *)fn_801C9D58;
    *(void **)(*(u8 **)(self + 0x434) + 0xFC) = (void *)fn_801C9CBC;
    *(void **)(*(u8 **)(self + 0x438) + 0x118) = (void *)fn_801C9C5C;
    *(void **)(*(u8 **)(self + 0x43c) + 0xA4) = (void *)fn_801C9B08;
    *(void **)(*(u8 **)(self + 0x440) + 0xA4) = (void *)fn_801C9A90;
    *(void **)(*(u8 **)(self + 0x444) + 0xA4) = (void *)fn_801C9A88;
    *(void **)(*(u8 **)(self + 0x448) + 0xA4) = (void *)CameraWin_CaptureKeyframe;
    *(void **)(*(u8 **)(self + 0x44c) + 0xA4) = (void *)fn_801C98EC;
    *(void **)(*(u8 **)(self + 0x450) + 0xA4) = (void *)CameraWin_OnCancel;
    *(void **)(self + 0x14) = *(void **)(self + 0x430);
    *(void **)(self + 0x54) = *(void **)(self + 0x434);
    *(void **)(self + 0x94) = *(void **)(self + 0x43c);
    *(void **)(self + 0x98) = *(void **)(self + 0x440);
    *(void **)(self + 0x9c) = *(void **)(self + 0x444);
    *(void **)(self + 0xd4) = *(void **)(self + 0x438);
    *(void **)(self + 0x114) = *(void **)(self + 0x448);
    *(void **)(self + 0x154) = *(void **)(self + 0x44c);
    *(void **)(self + 0x158) = *(void **)(self + 0x450);
    *(void **)(self + 0x414) = *(void **)(self + 0x430);
    fn_800E3F54(*(void **)(self + 0x414));
    return self;
}

void *fn_801CA77C(void *p, s16 n) {
    extern u8 lbl_80298428[];
    void String_Destroy(void *, s32);
    void fn_801CBFD0(void *, s32);
    void fn_800DF724(void *, s32);
    void Heap_Free(void *);
    struct T {
        u8 pad[0x48];
        u8 sub;
    } *t;

    if (p != NULL) {
        t = (struct T *)p;
        *(u8 **)((u8 *)p + 0x40) = lbl_80298428;
        String_Destroy((u8 *)p + 0x60, -1);
        String_Destroy((u8 *)p + 0x54, -1);
        if (&t->sub != NULL) {
            if (&t->sub != NULL) {
                fn_801CBFD0(&t->sub, 0);
            }
        }
        fn_800DF724(p, 0);
        if (n > 0) {
            Heap_Free(p);
        }
    }
    return p;
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
#pragma opt_strength_reduction off
#pragma cplusplus on
extern "C" void fn_801CA814(void *arg0, void *arg1) {
    u32 strlen(const char *);
    void String_AssignCStr(void *, char *, u32);
    void String_JoinCStr(void *, char *, void *);
    void String_ConcatCStr(void *, void *, char *);
    void fn_800C99A0(void *, void *, s32, s32);
    void String_Destroy(void *, s16);
    void fn_800C992C(void *, char *, u32);
    char *String_CStr(void *);
    void sprintf(char *, char *, ...);
    void fn_800DF6DC(void *, void *);
    void *Heap_Alloc(s32);
    void *fn_800C4638(s32, char *, s32);
    void Stream_Write(void *, s32, char *);
    void fn_8017A310(void *, char *);
    extern char lbl_8027DAB0[];
    extern u8 gStreamBaseVtbl[];
    extern u8 gMemStreamVtbl[];
    struct Str { u32 size; u32 cap; char *data; };
    struct WObj {
        u8 pad[0x10];
        virtual void v0();
        virtual void v1();
        virtual void close(s32);
    };
    struct Str sp2C;
    struct Str sp20;
    struct Str sp14;
    struct Str sp8;
    char sp38[0x40];
    s32 i;
    f32 *ent;
    char *base;
    s32 off;
    void *copy;
    u32 len;

    sp2C.cap = 0;
    sp2C.size = 0;
    sp2C.data = 0;
    sp2C.cap = 0;
    {
        u32 n = strlen(lbl_8027DAB0);
        String_AssignCStr(&sp2C, lbl_8027DAB0, n);
    }
    String_JoinCStr(&sp20, (char *)lbl_8027DAB0 + 4, (void *)((u8 *)arg0 + 0x54));
    String_ConcatCStr(&sp14, &sp20, (char *)((u8 *)lbl_8027DAB0 + 0x1C));
    fn_800C99A0(&sp2C, &sp14, 0, -1);
    String_Destroy(&sp14, -1);
    String_Destroy(&sp20, -1);
    len = strlen(lbl_8027DAB0);
    fn_800C992C(&sp2C, lbl_8027DAB0, len);
    len = strlen(&lbl_8027DAB0[0x1C]);
    fn_800C992C(&sp2C, (char *)lbl_8027DAB0 + 0x1C, len);
    len = strlen(&lbl_8027DAB0[0x1F]);
    fn_800C992C(&sp2C, (char *)lbl_8027DAB0 + 0x1F, len);
    len = strlen(&lbl_8027DAB0[0x23]);
    fn_800C992C(&sp2C, (char *)lbl_8027DAB0 + 0x23, len);
    sprintf(sp38, (char *)lbl_8027DAB0 + 0x38, String_CStr((u8 *)arg0 + 0x10));
    fn_800C992C(&sp2C, sp38, strlen(sp38));
    sprintf(sp38, (char *)lbl_8027DAB0 + 0x43, String_CStr((u8 *)arg0 + 0x60));
    fn_800C992C(&sp2C, sp38, strlen(sp38));
    sprintf(sp38, (char *)lbl_8027DAB0 + 0x50, String_CStr((void *)((s8 *)arg0 + 0x54)));
    fn_800C992C(&sp2C, sp38, strlen(sp38));
    fn_800DF6DC(&sp8, *(void **)((u8 *)arg0 + 0x6C));
    sprintf(sp38, (char *)lbl_8027DAB0 + 0x5E, String_CStr(&sp8));
    String_Destroy(&sp8, -1);
    fn_800C992C(&sp2C, sp38, strlen(sp38));
    sprintf(sp38, (char *)lbl_8027DAB0 + 0x6B, *(s32 *)((u8 *)arg0 + 0x70));
    fn_800C992C(&sp2C, sp38, strlen(sp38));
    i = 0;
    base = lbl_8027DAB0;
    off = 0;
    while (i < *(s32 *)((u8 *)arg0 + 0x70)) {
        ent = (f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + off);
        sprintf(sp38, base + 0x76, *(ent), *(ent + 1), *(ent + 2));
        fn_800C992C(&sp2C, sp38, strlen(sp38));
        sprintf(sp38, base + 0x8F, *(ent + 3), *(ent + 4), *(ent + 5));
        fn_800C992C(&sp2C, sp38, strlen(sp38));
        sprintf(sp38, base + 0xA8, *(ent + 6));
        fn_800C992C(&sp2C, sp38, strlen(sp38));
        sprintf(sp38, base + 0xB5, *(s32 *)(ent + 7));
        fn_800C992C(&sp2C, sp38, strlen(sp38));
        i = i + 1;
        off = off + 0x20;
    }
    len = strlen(&lbl_8027DAB0[0xC0]);
    fn_800C992C(&sp2C, (char *)lbl_8027DAB0 + 0xC0, len);
    len = strlen(&lbl_8027DAB0[0x1C]);
    fn_800C992C(&sp2C, (char *)lbl_8027DAB0 + 0x1C, len);
    len = strlen(&lbl_8027DAB0[0xC4]);
    fn_800C992C(&sp2C, (char *)lbl_8027DAB0 + 0xC4, len);
    if ((arg0 = Heap_Alloc(0x14)) != 0) {
        *(void **)((u8 *)arg0 + 0x10) = gStreamBaseVtbl;
        copy = (u8 *)arg0 + i;
        copy = (u8 *)copy - i;
        *(u32 *)((u8 *)arg0 + 4) = 0;
        *(u32 *)arg0 = 0;
        *(u32 *)((u8 *)arg0 + 8) = 0;
        *(u8 *)((u8 *)arg0 + 0xC) = 0;
        *(void **)((u8 *)arg0 + 0x10) = gMemStreamVtbl;
        *(void **)copy = fn_800C4638(0x8000, (char *)lbl_8027DAB0 + 0xC8, 0);
        *(void **)((u8 *)copy + 4) = *(void **)copy;
        *(u32 *)((u8 *)copy + 8) = 0x8000;
        *(u8 *)((u8 *)copy + 0xC) = 1;
    }
    {
        char *s = String_CStr(&sp2C);
        Stream_Write(arg0, sp2C.size, s);
    }
    fn_8017A310(arg0, String_CStr(arg1));
    if (arg0 != 0) {
        ((WObj *)arg0)->close(1);
    }
    String_Destroy(&sp2C, -1);
}
#pragma cplusplus reset
#pragma opt_strength_reduction reset
#pragma global_optimizer reset
void fn_801CACE4(void *arg0, s32 arg1) {
    if (arg1 < *(s32*)((char*)arg0 + 0x70)) {
        s32 temp_r5 = *(s32*)((char*)arg0 + 0x50);
        fn_801CB7F0((char*)arg0 + 0x48, (void *)(temp_r5 + (arg1 << 5)));
        *(s32*)((char*)arg0 + 0x70) = *(s32*)((char*)arg0 + 0x70) - 1;
    }
}

void fn_801CAD38(void *p,s32 n,s32 v){void fn_801CB934(void*,void*,s32,s32);s32 x=n+1; if(x<*(s32*)((u8*)p+0x70))fn_801CB934((u8*)p+0x48,(u8*)(*(u32*)((u8*)p+0x50)+(x<<5)),1,v);else fn_801CB934((u8*)p+0x48,(u8*)(*(u32*)((u8*)p+0x50)+(*(s32*)((u8*)p+0x4c)<<5)),1,v);(*(s32*)((u8*)p+0x70))++;}

#pragma global_optimizer off
void fn_801CADBC(void *arg0, s32 arg1) {
    u8 Camera_IsEnabled(void *);
    void fn_800DF6DC(void *, void *);
    void fn_800E7B80(s32, void *);
    void String_Destroy(void *, s32);
    void *fn_800E8BB4(void *);
    void fn_800E8BBC(void *, s32);
    void fn_800E8FAC(void *, s32);
    void fn_800E8BF8(void *, f32 *, f32 *, s32, f32);
    struct Str { u32 size; u32 cap; char *data; };
    struct Vec3 { f32 x, y, z; };
    struct Fl { f32 sp2C; f32 sp30; f32 sp34; f32 sp38; f32 sp3C; f32 sp40; };
    struct Fl fl;
    struct Str sp20;
    struct Vec3 sp14;
    struct Vec3 sp8;
    f32 *entry;
    s32 unk0;
    void *child;
    f32 f1, f5, f4, f3, f2, f0;

    fl.sp40 = 0.0f;
    unk0 = *(s32 *)arg0;
    fl.sp3C = 0.0f;
    fl.sp38 = 0.0f;
    fl.sp34 = 0.0f;
    fl.sp30 = 0.0f;
    fl.sp2C = 0.0f;
    if (arg1 < *(s32 *)((u8 *)arg0 + 0x70)) {
        entry = (f32 *)(*(u8 **)((u8 *)arg0 + 0x50) + (arg1 << 5));
    } else {
        entry = NULL;
    }
    if ((u32)entry != 0 && (u32)*(void **)((u8 *)arg0 + 0x6C) != 0) {
        if (Camera_IsEnabled(*(void **)((u8 *)arg0 + 0x6C)) == 0) {
            fn_800DF6DC(&sp20, *(void **)((u8 *)arg0 + 0x6C));
            fn_800E7B80(unk0, &sp20);
            String_Destroy(&sp20, -1);
        }
        child = fn_800E8BB4(*(void **)((u8 *)arg0 + 0x6C));
        if ((u32)child != 0 && (u32)*(void **)((u8 *)child + 0x6C) != 0) {
            *(s32 *)((u8 *)child + 0x74) = -1;
            fn_800E8BBC(*(void **)((u8 *)child + 0x6C), 0);
        }
        fn_800E8FAC(*(void **)((u8 *)arg0 + 0x6C), 0);
        f1 = entry[0];
        f5 = entry[1];
        fl.sp38 = f1;
        f4 = entry[2];
        f3 = entry[3];
        f2 = entry[4];
        f0 = entry[5];
        fl.sp3C = f5;
        f1 = entry[6];
        fl.sp40 = f4;
        fl.sp2C = f3;
        fl.sp30 = f2;
        fl.sp34 = f0;
        sp8 = *(struct Vec3 *)&fl.sp2C;
        sp14 = *(struct Vec3 *)&fl.sp38;
        fn_800E8BF8(*(void **)((u8 *)arg0 + 0x6C), &sp14.x, &sp8.x, 0, f1);
    }
}
#pragma global_optimizer on
s32 CameraAnim_GetKeyframe(void *arg0, s32 arg1) {
    if (arg1 < (s32) M2C_FIELD(arg0, s32 *, 0x70)) {
        return M2C_FIELD(arg0, s32 *, 0x50) + (arg1 << 5);
    }
    return 0;
}

s32 fn_801CAF50(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x70);
}

void fn_801CAF58(void *arg0) {
    s32 fn_800E7F60(s32);
    M2C_FIELD(arg0, s32 *, 0x6C) = fn_800E7F60(M2C_FIELD(arg0, s32 *, 0));
}

s32 CameraAnim_GetCamera(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x6C);
}

#pragma cplusplus on
extern "C" void fn_801CAF94(void *arg0, s32 arg1, s8 arg2, s8 arg3, s32 arg4) {
    u8 Camera_IsEnabled(void *);
    void fn_800DF6DC(void *, s32);
    void fn_800E7B80(s32, void *);
    void String_Destroy(void *, s32);
    void *fn_800E8BB4(void *);
    void fn_800E8BBC(void *, void *);
    void fn_800E8FAC(void *, s32);
    s32 fn_800E8F00(void *);
    void String_Substr(void *, void *, s32, s32);
    void String_ConcatCStr(void *, void *, char *);
    void String_Assign(void *, void *, s32, s32);
    s32 String_Compare(void *, s32, u32, char *, u32);
    void String_AssignCStr(void *, char *, u32);
    void fn_800C99A0(void *, void *, s32, s32);
    void *String_CStr(void *);
    void fn_800E574C(void *, void *, f32, s32, s32, s32, s32);
    u32 strlen(const char *);
    extern char lbl_8027DAB0[];
    extern f32 lbl_8036B4AC;

    struct Str {
        u32 size;
        u32 cap;
        char *data;
    };
    struct Obj {
        u8 pad[0x40];
        virtual void m08(s32) = 0;
    };
    struct Self {
        s32 unk0;
        u8 pad4[0x50];
        s32 unk54;
        u8 pad58[0x14];
        void *unk6C;
        u8 pad70[4];
        s32 unk74;
        s8 unk78;
        s8 unk79;
    };

    struct Str sp44;
    struct Str sp38;
    struct Str sp2C;
    struct Str sp20;
    struct Str sp14;
    struct Str sp8;
    Self *self;
    s32 a1;
    s32 unk0;
    void *child;
    u32 len;

    self = (Self *)arg0;
    a1 = arg1;
    unk0 = self->unk0;
    if (self->unk6C != NULL) {
        if (Camera_IsEnabled(self->unk6C) == 0) {
            fn_800DF6DC(&sp2C, (s32)self->unk6C);
            fn_800E7B80(unk0, &sp2C);
            String_Destroy(&sp2C, -1);
        }
        child = fn_800E8BB4(self->unk6C);
        if (child != NULL && *(u32 *)((u8 *)child + 0x6C) != 0) {
            *(s32 *)((u8 *)child + 0x74) = -1;
            fn_800E8BBC(*(void **)((u8 *)child + 0x6C), NULL);
        }
        fn_800E8FAC(self->unk6C, a1);
        fn_800E8BBC(self->unk6C, self);
        if ((u8)arg4 != 0) {
            sp44.cap = 0;
            sp38.cap = 0;
            sp44.size = 0;
            sp44.data = 0;
            sp44.cap = 0;
            sp38.size = 0;
            sp38.data = 0;
            sp38.cap = 0;
            arg4 = fn_800E8F00(self->unk6C);
            if (arg4 != 0) {
                unk0 = self->unk54;
                String_Substr(&sp20, &self->unk54, unk0 - 2, 2);
                String_ConcatCStr(&sp14, &sp20, lbl_8027DAB0 + 0xC9);
                String_Assign(&sp44, &sp14, 0, -1);
                String_Destroy(&sp14, -1);
                String_Destroy(&sp20, -1);
                len = strlen((char *)lbl_8027DAB0 + 0xCB);
                if (String_Compare(&sp44, 0, sp44.size, &lbl_8027DAB0[0xCB], len) == 0) {
                    len = strlen((char *)lbl_8027DAB0 + 0xCF);
                    String_AssignCStr(&sp44, &lbl_8027DAB0[0xCF], len);
                }
                String_Substr(&sp8, &self->unk54, 5, unk0 - 8);
                String_Assign(&sp38, &sp8, 0, -1);
                String_Destroy(&sp8, -1);
                len = strlen((char *)lbl_8027DAB0 + 0xD3);
                if (String_Compare(&sp38, 0, sp38.size, &lbl_8027DAB0[0xD3], len) == 0) {
                    len = strlen((char *)lbl_8027DAB0 + 0xD8);
                    String_AssignCStr(&sp38, &lbl_8027DAB0[0xD8], len);
                }
                fn_800C99A0(&sp44, &sp38, 0, -1);
                fn_800E574C((void *)arg4, String_CStr(&sp44), lbl_8036B4AC, 0, 1, 0, 0xA);
            }
            String_Destroy(&sp38, -1);
            String_Destroy(&sp44, -1);
        }
        self->unk74 = 0;
        self->unk78 = arg2;
        self->unk79 = arg3;
        ((Obj *)self)->m08(1);
    }
}
#pragma cplusplus reset

void fn_801CB25C(s32 arg0, s32 arg1) {
    String_Copy(arg0, arg1 + 0x60);
}

void fn_801CB280(s32 arg0, s32 arg1) {
    String_Copy(arg0, arg1 + 0x54);
}

void fn_801CB2A4(void *arg0) {
    u8 Camera_IsEnabled(void *);
    u8 fn_800E8BC4(void *);
    void fn_800E8BF8(void *, f32 *, f32 *, s32, f32);
    extern f32 lbl_8036B4B4;
    extern f32 lbl_8036B4B0;
    extern f32 lbl_8036B4B8;

    f32 eyeZ;
    f32 eyeY;
    f32 eyeX;
    f32 lookZ;
    f32 lookY;
    f32 lookX;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    void *self;
    f32 *entry;
    f32 t0, t1, t2, t3, t4, t5, t6;
    u32 slot;

    self = arg0;
    eyeZ = 0.0f;
    eyeY = 0.0f;
    eyeX = 0.0f;
    lookZ = 0.0f;
    lookY = 0.0f;
    lookX = 0.0f;

    if (*(void **)((u8 *)self + 0x6C) == NULL) {
        return;
    }
    if (*(s32 *)((u8 *)self + 0x74) < 0) {
        return;
    }
    if (Camera_IsEnabled(*(void **)((u8 *)self + 0x6C)) == 0) {
        *(s32 *)((u8 *)self + 0x74) = -1;
        return;
    }
    if (*(s32 *)((u8 *)self + 0x74) != 0) {
        if (fn_800E8BC4(*(void **)((u8 *)self + 0x6C)) != 0) {
            return;
        }
    }

    entry = (f32 *)(*(u8 **)((u8 *)self + 0x50) + (*(s32 *)((u8 *)self + 0x74) << 5));
    t0 = entry[0];
    t1 = entry[1];
    t2 = entry[2];
    t3 = entry[3];
    t4 = entry[4];
    t5 = entry[5];
    eyeX = t0;
    eyeY = t1;
    eyeZ = t2;
    lookX = t3;
    lookY = t4;
    lookZ = t5;
    t6 = entry[6];
    slot = *(u32 *)((u8 *)entry + 0x1C);

    if (*(u8 *)((u8 *)self + 0x78) != 0) {
        lookY = lbl_8036B4B0 - (t4 - lbl_8036B4B4);
    }
    if (*(u8 *)((u8 *)self + 0x79) != 0) {
        eyeX = eyeX * lbl_8036B4B8;
    }

    *(u32 *)&sp8 = *(u32 *)&lookX;
    *(u32 *)&spC = *(u32 *)&lookY;
    *(u32 *)&sp10 = *(u32 *)&lookZ;
    *(u32 *)&sp14 = *(u32 *)&eyeX;
    *(u32 *)&sp18 = *(u32 *)&eyeY;
    *(u32 *)&sp1C = *(u32 *)&eyeZ;
    fn_800E8BF8(*(void **)((u8 *)self + 0x6C), &sp14, &sp8, (s32)slot, t6);

    *(s32 *)((u8 *)self + 0x74) = *(s32 *)((u8 *)self + 0x74) + 1;
    if (*(s32 *)((u8 *)self + 0x74) >= *(s32 *)((u8 *)self + 0x70)) {
        *(s32 *)((u8 *)self + 0x74) = -1;
    }
}

#pragma cplusplus on
#pragma opt_common_subs off
extern "C" void *fn_801CB41C(void *arg0, void *arg1, void *arg2) {
void fn_800DF7A0(void *);
void String_Init(void *,void *,void *); void Xml_GetNamedValue(void *,void *,void *);
u32 strlen(void *); void String_AssignCStr(void *,void *,u32); void String_Destroy(void *,s32);
s32 String_Compare(void *,s32,u32,void *,u32); u8 *fn_80117CC0(void *,s32);
void String_Substr(void *,void *,s32,s32); void String_Assign(void *,void *,s32,s32);
void *fn_800E7F60(void *,void *); void Xml_AdvanceChild(void *); void Xml_GetChildValue(void *,void *);
void fn_801CB934(void *,void *,s32,s32);
extern u8 lbl_80298428[],lbl_8027DAB0[];
ParseValue801CB41C p180,p160,p140,p120,p100,pe0,pc0,pa0;
ParseValue801CB41C tmp;
f32 record[8];
String801CB41C str,s48,s3c,s30,s24,s18;
u32 a14,a10,ac,a8;
void *saved;
s32 i;
u8 *self=(u8 *)arg0;
fn_800DF7A0(arg0);
saved=arg1;
*(void **)(self+0x40)=lbl_80298428;
*(u32 *)(self+0x48)=0; *(u32 *)(self+0x4c)=0; *(u32 *)(self+0x50)=0;
*(u32 *)(self+0x54)=0; *(u32 *)(self+0x58)=0; *(u32 *)(self+0x5c)=0; *(u32 *)(self+0x58)=0;
*(u32 *)(self+0x60)=0; *(u32 *)(self+0x64)=0; *(u32 *)(self+0x68)=0; *(u32 *)(self+0x64)=0;
str.b=0;str.a=0;str.c=0;str.b=0;
String_Init(&s48,lbl_8027DAB0+0xdd,&a14);
Xml_GetNamedValue(&p180,arg2,&s48);arg1=&p180;
String_AssignCStr(self+0x54,arg1,strlen(arg1));String_Destroy(&s48,-1);
String_Init(&s3c,lbl_8027DAB0+0xe5,&a10);
Xml_GetNamedValue(&p160,arg2,&s3c);arg1=&p160;
String_AssignCStr(self+0x60,arg1,strlen(arg1));String_Destroy(&s3c,-1);
if(String_Compare(self+0x60,0,*(u32 *)(self+0x60),lbl_8027DAB0+0xc8,strlen(lbl_8027DAB0+0xc8))==0 && (s32)*fn_80117CC0(self+0x54,4)=='_'){
String_Substr(&s30,self+0x54,0,4);String_Assign(self+0x60,&s30,0,-1);String_Destroy(&s30,-1);
}
String_Init(&s24,lbl_8027DAB0+0xec,&ac);
Xml_GetNamedValue(&p140,arg2,&s24);arg1=&p140;
String_AssignCStr(&str,arg1,strlen(arg1));String_Destroy(&s24,-1);
*(void **)(self+0x6c)=fn_800E7F60(saved,&str);
String_Init(&s18,lbl_8027DAB0+0xf3,&a8);
Xml_GetNamedValue(&p120,arg2,&s18);
*(u32 *)(self+0x70)=*(u32 *)&p120;String_Destroy(&s18,-1);
Xml_AdvanceChild(arg2);
for(i=0;i<*(s32 *)(self+0x70);i++){
Xml_GetChildValue(&pa0,arg2);tmp=pa0;
record[0]=tmp.v[0];record[1]=tmp.v[1];record[2]=tmp.v[2];Xml_AdvanceChild(arg2);
Xml_GetChildValue(&pc0,arg2);tmp=pc0;
record[3]=tmp.v[0];record[4]=tmp.v[1];record[5]=tmp.v[2];Xml_AdvanceChild(arg2);
Xml_GetChildValue(&pe0,arg2);record[6]=pe0.v[0];Xml_AdvanceChild(arg2);
Xml_GetChildValue(&p100,arg2);((u32 *)record)[7]=*(u32 *)&p100;Xml_AdvanceChild(arg2);
fn_801CB934(self+0x48,*(u8 **)(self+0x50)+(*(u32 *)(self+0x4c)<<5),1,(s32)record);
}
*(s32 *)(self+0x74)=-1;self[0x78]=0;self[0x79]=0;String_Destroy(&str,-1);
return self;
}

#pragma cplusplus reset
int fn_801CB7F0(void *arg0, void *arg1, void *unused) {
    s32 count;
    u8 *end;
    u8 *src;
    u8 *dst;
    u32 n;
    u32 i;
    (void)unused;
    count = *(s32 *)((u8 *)arg0 + 4);
    end = *(u8 **)((u8 *)arg0 + 8) + (count << 5);
    if ((((s32)(end - (u8 *)arg1) / 32) - 1) != 0) {
        src = (u8 *)arg1 + 0x20;
        dst = (u8 *)arg1;
        n = (u32)((end + 0x1F) - src) >> 5;
        if (src < end) {
            for (i = 0; i < n; i++) {
                ((f32 *)dst)[0] = ((f32 *)src)[0];
                ((f32 *)dst)[1] = ((f32 *)src)[1];
                ((f32 *)dst)[2] = ((f32 *)src)[2];
                ((f32 *)dst)[3] = ((f32 *)src)[3];
                ((f32 *)dst)[4] = ((f32 *)src)[4];
                ((f32 *)dst)[5] = ((f32 *)src)[5];
                ((f32 *)dst)[6] = ((f32 *)src)[6];
                ((u32 *)dst)[7] = ((u32 *)src)[7];
                src += 0x20;
                dst += 0x20;
            }
        }
    }
    *(s32 *)((u8 *)arg0 + 4) = count - 1;
    return (int)arg1;
}

#pragma use_lmw_stmw on
void fn_801CB934(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    void fprintf(void *, void *, ...);
    void abort(void);
    void *Heap_Alloc(s32);
    void fn_801CC030(void *);
    void Heap_Free(void *);
    extern u8 __files[];
    extern u8 lbl_8027DAB0[];
    u32 n = (u32)arg2;
    void *fill = (void *)arg3;
    if (n == 0) {
        return;
    }
    if (n > 0x07FFFFFFU || *(u32 *)((u8 *)arg0 + 4) > (0x07FFFFFFU - n)) {
        fprintf(__files + 0xA0, lbl_8027DAB0 + 0x1A7);
        abort();
    }
    (void)fill;
    (void)arg1;
}

#pragma opt_common_subs on
#pragma cplusplus off

void *fn_801CBFD0(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    void fn_801CC030(void *);

    if (arg0 != NULL) {
        fn_801CC030(arg0);
        if (M2C_FIELD(arg0, void **, 8) != NULL) {
            Heap_Free(M2C_FIELD(arg0, void **, 8));
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void fn_801CC030(u32 *arg0) {
    u8 *start = (u8 *)arg0[2];
    u8 *end = start + (arg0[1] << 5);
    while (end > start) {
        end -= 0x20;
    }
    arg0[1] = 0;
}

#pragma cplusplus on
extern "C" void fn_801CC068(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
    };
    ((Obj *)arg0)->v6();
}

#pragma global_optimizer off
#pragma peephole off
extern "C" void fn_801CC094(void *arg0) {
    u8 *fn_801CD480(void *, s16, s16);
    void Ui_PlaySeCue(void *, s32);
    extern u32 gUiInputFlags;
    extern void *gPadInput;
    extern f64 lbl_8036B4C0;
    extern u8 lbl_8027DD30[];

    struct Obj {
        virtual void v0() {}
        virtual void v1() {}
        virtual void v2() {}
        virtual void v3() {}
        virtual void v4() {}
        virtual void v5() {}
        virtual void v6() {}
        virtual void v7() {}
        virtual void v8() {}
        virtual void v9() {}
        virtual s16 v10() { return 0; }
        virtual void v11() {}
        virtual s16 v12() { return 0; }
        virtual s16 v13() { return 0; }
        virtual s16 v14() { return 0; }
    };

    Obj *self;
    u32 held;
    u32 pressed;
    s16 saveX;
    s16 saveY;
    s16 saveTop;
    s8 done;
    s8 dir;

    self = (Obj *)arg0;
    {
        u8 skip = 0;
        if ((gUiInputFlags & 0x10) != 0 && (gUiInputFlags & 0x20) == 0) {
            skip = 1;
        }
        if (skip != 0) {
            return;
        }
    }

    {
        u32 *pad = (u32 *)gPadInput;
        u32 buttons = pad[1];
        u32 prev = pad[2];

        saveX = *(s16 *)((u8 *)self + 0x48);
        held = pad[3];
        saveY = *(s16 *)((u8 *)self + 0x4A);
        saveTop = *(s16 *)((u8 *)self + 0x46);
        pressed = buttons & (prev ^ buttons);
    }

    if ((held & 0x01000001) != 0) {
        s32 x = saveX - 1;
        *(s16 *)((u8 *)self + 0x48) = x;
        if ((s16)x < 0) {
            if (pressed == held) {
                s32 w = self->v13();
                x = w - 1;
            } else {
                x = *(s16 *)((u8 *)self + 0x48) + 1;
                *(s16 *)((u8 *)self + 0x48) = x;
            }
            *(s16 *)((u8 *)self + 0x48) = x;
        }
        *(s16 *)((u8 *)self + 0x48) = (s16)x;
        done = 0;
        dir = -1;
        while (done == 0) {
            s8 ch = (s8)*fn_801CD480(*(void **)((u8 *)self + 0x3C),
                                      *(s16 *)((u8 *)self + 0x48),
                                      *(s16 *)((u8 *)self + 0x4A));
            switch (ch) {
            case 0xA:
                if (pressed == held) {
                    s32 w = self->v13();
                    *(s16 *)((u8 *)self + 0x48) = (s16)(w - dir - 1);
                } else {
                    dir *= -1;
                }
                break;
            case 9:
                break;
            default:
                done = 1;
                break;
            }
            *(s16 *)((u8 *)self + 0x48) =
                (s16)(*(s16 *)((u8 *)self + 0x48) + (dir & -(done == 0)));
        }
    } else if ((held & 0x02000002) != 0) {
        s32 w = self->v13();
        s16 x = (s16)(*(s16 *)((u8 *)self + 0x48) + 1);
        *(s16 *)((u8 *)self + 0x48) = x;
        if (x >= (s16)w) {
            if (pressed == held) {
                x = 0;
            } else {
                x = (s16)(*(s16 *)((u8 *)self + 0x48) - 1);
                *(s16 *)((u8 *)self + 0x48) = x;
            }
            *(s16 *)((u8 *)self + 0x48) = (s16)x;
        }
        done = 0;
        dir = 1;
        while (done == 0) {
            s8 ch = (s8)*fn_801CD480(*(void **)((u8 *)self + 0x3C),
                                      *(s16 *)((u8 *)self + 0x48),
                                      *(s16 *)((u8 *)self + 0x4A));
            switch (ch) {
            case 0xA:
                if (pressed == held) {
                    *(s16 *)((u8 *)self + 0x48) = (s16)(-dir);
                } else {
                    dir *= -1;
                }
                break;
            case 9:
                break;
            default:
                done = 1;
                break;
            }
            *(s16 *)((u8 *)self + 0x48) =
                (s16)(*(s16 *)((u8 *)self + 0x48) + (dir & -(done == 0)));
        }
    }

    if ((held & 0x08000008) != 0) {
        s32 y = *(s16 *)((u8 *)self + 0x4A);
        if (y == 0) {
            if (held == pressed) {
                s16 h;
                s16 view;
                *(s16 *)((u8 *)self + 0x4A) = (s16)self->v14() - 1;
                h = (s16)self->v14();
                view = (s16)self->v12();
                if (view < h) {
                    h = (s16)self->v14();
                    view = (s16)self->v12();
                    *(s16 *)((u8 *)self + 0x46) = (s16)(h - view);
                } else {
                    *(s16 *)((u8 *)self + 0x46) = 0;
                }
            }
        } else {
            *(s16 *)((u8 *)self + 0x4A) = (s16)(y - 1);
            y = *(s16 *)((u8 *)self + 0x4A);
            if (y > 0) {
                if (y - *(s16 *)((u8 *)self + 0x46) == 0) {
                    *(s16 *)((u8 *)self + 0x46) = (s16)(*(s16 *)((u8 *)self + 0x46) - 1);
                    *(f32 *)((u8 *)self + 0x58) = (f32)(-(s16)self->v10());
                }
            }
        }
    } else if ((held & 0x04000004) != 0) {
        s16 h = (s16)self->v14();
        s16 y = *(s16 *)((u8 *)self + 0x4A);
        if (y == h - 1) {
            if (held == pressed) {
                *(s16 *)((u8 *)self + 0x46) = 0;
                *(s16 *)((u8 *)self + 0x4A) = 0;
            }
        } else {
            *(s16 *)((u8 *)self + 0x4A) = (s16)(y + 1);
            h = (s16)self->v14();
            if (*(s16 *)((u8 *)self + 0x4A) < h - 1) {
                s16 view = (s16)self->v12();
                if (*(s16 *)((u8 *)self + 0x4A) - *(s16 *)((u8 *)self + 0x46) == view - 1) {
                    *(s16 *)((u8 *)self + 0x46) = (s16)(*(s16 *)((u8 *)self + 0x46) + 1);
                    *(f32 *)((u8 *)self + 0x58) = (f32)(s16)self->v10();
                }
            }
        }
    }

    done = 0;
    dir = -1;
    while (done == 0) {
        s8 ch = (s8)*fn_801CD480(*(void **)((u8 *)self + 0x3C),
                                  *(s16 *)((u8 *)self + 0x48),
                                  *(s16 *)((u8 *)self + 0x4A));
        switch (ch) {
        case 0xA:
            dir *= -1;
            break;
        case 9:
            break;
        default:
            done = 1;
            break;
        }
        *(s16 *)((u8 *)self + 0x48) =
            (s16)(*(s16 *)((u8 *)self + 0x48) + (dir & -(done == 0)));
    }

    if (saveX != *(s16 *)((u8 *)self + 0x48) || saveY != *(s16 *)((u8 *)self + 0x4A) ||
        saveTop != *(s16 *)((u8 *)self + 0x46)) {
        Ui_PlaySeCue(lbl_8027DD30 + 8, 0x64);
    }
}
#pragma peephole on
#pragma global_optimizer reset

#pragma use_lmw_stmw on
#pragma cplusplus on
extern "C" void fn_801CC5C4(void *arg0, void *arg1) {
    void Prim2D_Begin(void);
    void Prim2D_AddZ(f32);
    void Prim2D_PrepareTex(void);
    void Ui_DrawLine(s16, s16, s16, s16, s32, u8 *);
    extern f32 lbl_8036B4C8;

    struct Obj {
        virtual void v0() {}
        virtual void v1() {}
        virtual void v2() {}
        virtual void v3() {}
        virtual void v4() {}
        virtual void v5() {}
        virtual void v6() {}
        virtual void v7() {}
        virtual void v8() {}
        virtual s16 v9() { return 0; }
        virtual s16 v10() { return 0; }
        virtual s16 v11() { return 0; }
        virtual void v12() {}
        virtual void v13() {}
    };

    u8 color[4];
    s16 w;
    s16 h;
    s32 x0;
    void *arg;
    void *self;
    s16 y0;

    self = arg0;
    arg = arg1;
    ((Obj *)self)->v3();
    x0 = *(s16 *)((u8 *)self + 0x48);
    y0 = (s16)(*(s16 *)((u8 *)self + 0x4A) - ((Obj *)self)->v11());
    w = ((Obj *)self)->v9();
    h = ((Obj *)self)->v10();
    {
        s16 t3;
        s16 t5;
        s16 old4c;

        t3 = (s16)(x0 * w);
        t5 = (s16)(y0 * h);
        if ((old4c = *(s16 *)((u8 *)self + 0x4C)) == -1 && *(s16 *)((u8 *)self + 0x4E) == -1) {
            *(s16 *)((u8 *)self + 0x4C) = t3;
            *(s16 *)((u8 *)self + 0x4E) = t5;
        } else {
            *(s16 *)((u8 *)self + 0x4C) = (old4c + t3 + 1) >> 1;
            *(s16 *)((u8 *)self + 0x4E) = (*(s16 *)((u8 *)self + 0x4E) + t5 + 1) >> 1;
        }
    }
    x0 = *(s16 *)((u8 *)self + 0x4C);
    {
        s16 py;
        void *ptr;
        struct { unsigned b : 8; } eq;

        py = *(s16 *)((u8 *)self + 0x4E);
        if (*(u32 *)((u8 *)arg + 0x34) != 0) {
            ptr = (*(void ***)((u8 *)arg + 0x38))[2];
        } else {
            ptr = 0;
        }
        eq.b = (ptr == self);
        if (eq.b) {
            s32 x1;
            s32 y1;
            s32 x2;
            s32 y2;
            u8 alpha;

            Prim2D_Begin();
            Prim2D_AddZ(lbl_8036B4C8);
            Prim2D_PrepareTex();
            color[0] = 0x9C;
            x1 = (s16)(x0 + ((w - 0x30) >> 1));
            y1 = (s16)(py + ((h - 0x30) >> 1));
            color[1] = 0x2F;
            x2 = (s16)(x1 + 0x30);
            alpha = 0x80;
            y2 = (s16)(y1 + 0x30);
            color[2] = 0x12;
            if (eq.b) {
                alpha = 0xFF;
            }
            color[3] = alpha;
            Ui_DrawLine((s16)x1, (s16)(y1 - 1), (s16)x2, (s16)(y1 - 1), *(s32 *)((u8 *)self + 0x34), color);
            Ui_DrawLine((s16)x1, (s16)y2, (s16)x2, (s16)y2, *(s32 *)((u8 *)self + 0x34), color);
            Ui_DrawLine((s16)(x1 - 1), (s16)y1, (s16)(x1 - 1), (s16)y2, *(s32 *)((u8 *)self + 0x34), color);
            Ui_DrawLine((s16)x2, (s16)y1, (s16)x2, (s16)y2, *(s32 *)((u8 *)self + 0x34), color);
            Ui_DrawLine((s16)x1, (s16)y1, (s16)x2, (s16)y1, *(s32 *)((u8 *)self + 0x34), color);
            Ui_DrawLine((s16)x1, (s16)(y2 - 1), (s16)x2, (s16)(y2 - 1), *(s32 *)((u8 *)self + 0x34), color);
            Ui_DrawLine((s16)x1, (s16)y1, (s16)x1, (s16)y2, *(s32 *)((u8 *)self + 0x34), color);
            Ui_DrawLine((s16)(x2 - 1), (s16)y1, (s16)(x2 - 1), (s16)y2, *(s32 *)((u8 *)self + 0x34), color);
        }
    }
}

#pragma global_optimizer off
#pragma use_lmw_stmw on
#pragma cplusplus on
extern "C" void fn_801CC844(void *arg0, void *arg1) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5(void *) = 0;
        virtual void v6() = 0;
        virtual void v7() = 0;
        virtual void v8() = 0;
        virtual void v9() = 0;
        virtual void v10() = 0;
        virtual s16 v11() = 0;
        virtual s16 v12() = 0;
        virtual s16 v13() = 0;
        virtual s16 v14() = 0;
        virtual s16 v15() = 0;
        virtual s16 v16() = 0;
        virtual void v17() = 0;
        virtual void v18() = 0;
        virtual void v19() = 0;
        u8 pad4[0xE];
        s16 a12, a14, a16, a18;
        u8 pad1A[0x34 - 0x1A];
        u32 unk34;
        u8 pad38[0x3C - 0x38];
        void *unk3C;
        u8 pad40[0x48 - 0x40];
        s16 unk48, unk4A;
        s16 rect[4];
        f32 unk58;
        u8 pad5C[0x68 - 0x5C];
        u8 unk68;
        u8 pad69[0x90 - 0x69];
        u8 unk90;
    };
    struct Sub {
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
        virtual void v11(s32) = 0;
    };
    void fn_8013F748(void *, s16 *, s16 *);
    void Prim2D_Begin(void);
    void Prim2D_PrepareTex(void);
    void Prim2D_ClearCallbacks(void);
    void Prim2D_ScissorFromRect(void *);
    void Prim2D_SetCallback(void (*)(void *), s16 *);
    void Prim2D_SetTex(s32, u16);
    s32 Text_MeasureHeight(s32, f32);
    s32 fn_8001059C(u8 *, s32, f32);
    s32 Text_MeasureWidth(u8 *, s32, f32);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, f32, f32);
    u8 *fn_801CD480(void *, s16, s16);
    extern f32 lbl_8036B4CC;
    extern f32 lbl_8036B4D0;
    extern f32 lbl_8036B4D4;
    extern f32 lbl_8036B4D8;
    extern f32 lbl_8036B4DC;
    extern f32 lbl_80367098[];

    Obj *self;
    void *arg;
    s16 *rect;
    s16 half;
    s16 scroll;
    s16 sign;
    s16 row;
    s16 endrow;
    s16 col;
    s16 ybase;
    u8 same;
    u8 sel;
    f32 scale;
    f32 dx;
    f32 dy;
    u8 *cell;
    s16 x;
    void *ptr;

    self = (Obj *)arg0;
    arg = arg1;
    self->v19();
    self->v5(arg);
    rect = self->rect;
    {
        s16 h = (s16)(self->a18 - self->a14);
        s16 w = (s16)(self->a16 - self->a12);
        rect[0] = 0;
        rect[1] = 0;
        rect[2] = w;
        rect[3] = h;
    }
    fn_8013F748(self, rect, rect);
    rect = self->rect + 2;
    fn_8013F748(self, rect, rect);
    Prim2D_Begin();
    Prim2D_SetCallback(Prim2D_ScissorFromRect, self->rect);
    Prim2D_SetTex(0, (u16)(self->unk34 | 3));
    Prim2D_PrepareTex();

    half = (s16)((self->v12() - Text_MeasureHeight(-1, lbl_8036B4CC)) >> 1);
    scroll = (s16)(s32)self->unk58;
    {
        f32 zero = lbl_8036B4D0;
        f32 fval = self->unk58;
        if (fval < zero) {
            f32 value = (f32)self->v12() * lbl_8036B4D4 + self->unk58;
            self->unk58 = value;
            if (value >= -lbl_80367098[0]) {
                self->unk58 = zero;
            }
        } else if (fval > zero) {
            f32 value = self->unk58 - (f32)self->v12() * lbl_8036B4D4;
            self->unk58 = value;
            if (value <= lbl_80367098[0]) {
                self->unk58 = zero;
            }
        }
    }

    if (scroll < 0) {
        sign = -1;
    } else {
        sign = (s16)(scroll > 0);
    }

    if (*(u32 *)((u8 *)arg + 0x34) != 0) {
        ptr = (*(void ***)((u8 *)arg + 0x38))[2];
    } else {
        ptr = 0;
    }
    same = (ptr == self);
    row = (s16)((-sign & ~sign) >> 31);
    if (sign < 0) {
        endrow = (s16)(self->v14() + 1);
    } else {
        endrow = (s16)self->v14();
    }

    for (; row < endrow; row++) {
        if ((s16)(row + self->v13()) >= 0) {
            if (self->v16() >= (s16)(row + self->v13())) {
                ybase = (s16)(half + (row * self->v12() + scroll));
                for (col = 0; col < self->v15(); col++) {
                    sel = 0;
                    if (same != 0 && col == self->unk48 &&
                        self->unk4A == (s16)(row + self->v13())) {
                        sel = 1;
                    }
                    if (sel != 0) {
                        scale = lbl_8036B4D8;
                    } else {
                        scale = lbl_8036B4CC;
                    }
                    cell = fn_801CD480(self->unk3C, col, (s16)(row + self->v13()));
                    if (*cell != 9) {
                        x = (s16)(((self->v11() - fn_8001059C(cell, -1, lbl_8036B4CC)) >> 1) +
                                  (col * self->v11()));
                        dx = lbl_8036B4D0;
                        dy = dx;
                        if (sel != 0) {
                            dx = lbl_8036B4DC *
                                 (f32)(Text_MeasureWidth(cell, -1, lbl_8036B4CC) -
                                       Text_MeasureWidth(cell, -1, scale));
                            dy = lbl_8036B4DC *
                                 (f32)(Text_MeasureHeight(-1, lbl_8036B4CC) -
                                       Text_MeasureHeight(-1, scale));
                        }
                        fn_8001003C((s32)((f32)x + dx), (s32)((f32)ybase + dy), 1, 0, 0,
                                    cell, scale, lbl_8036B4D0);
                    }
                }
            }
        }
    }

    Prim2D_Begin();
    Prim2D_ClearCallbacks();
    Prim2D_PrepareTex();
    self->unk68 = (u8)(self->v13() > 0);
    {
        s16 diff = (s16)(self->v16() - self->v14());
        self->unk90 = (u8)(self->v13() < diff);
    }
    ((Sub *)((u8 *)self + 0x5C))->v11(0x10);
    ((Sub *)((u8 *)self + 0x84))->v11(0x10);
}
#pragma cplusplus reset
#pragma use_lmw_stmw reset
#pragma global_optimizer reset

#pragma cplusplus reset

#pragma cplusplus reset

#pragma cplusplus on
extern "C" void fn_801CCE7C(void *arg0) {
    struct Obj {
        virtual void v0() = 0;
        virtual void v1() = 0;
        virtual void v2() = 0;
        virtual void v3() = 0;
        virtual void v4() = 0;
        virtual void v5() = 0;
        virtual void v6() = 0;
    };
    ((Obj *)arg0)->v2();
}
#pragma cplusplus reset

#pragma optimization_level 1
