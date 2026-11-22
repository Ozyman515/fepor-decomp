/* Functions from 0x801F196C to 0x801FC620, found by decomp-toolkit. */
#include "common.h"

typedef struct {
    u8 pad[0xB0];
    char *msg;
} BattlePreviewMsgSlot;

extern void *lbl_803683F4;
extern struct {
    u32 pad0;
    u32 pad4;
    u32 *pad8;
    u32 padC;
} gCardLinkProc;
extern void* Event_StartByName(void *, s32, void *);

extern f32 lbl_8036B910;
extern f32 lbl_8036B914;
extern f32 lbl_8036B918;
extern f32 lbl_8036B91C;
extern f32 lbl_8036B920;
extern f32 lbl_8036B924;
extern f32 lbl_8036B928;
extern f32 lbl_8036B92C;
extern f32 lbl_8036B930;
extern f32 lbl_8036B934;
extern f32 lbl_8036B938;
extern f32 lbl_8036B93C;
extern f32 lbl_8036B940;
extern f32 lbl_8036B944;
extern f64 lbl_8036B900;
extern f64 lbl_8036B948;
extern void* lbl_8029A8C8[];
extern void fn_80050E80(void);
extern void fn_8005C7C8(void*);
extern void fn_8003F670();
extern void ScriptCmd_CmFreeScript(void);
extern void fn_8005BCAC(void);
extern void fn_800C4B8C(void);

extern void* gPadInput;
extern u16 gCardLinkStr[18];

void fn_801F196C(M2C_UNK **arg0) {
    extern u16 lbl_8028459C[];
    extern u16 lbl_80286610[];
    extern u16 lbl_802862E4[];
    extern u16 lbl_8029A874[];
    *arg0 = (M2C_UNK *)&lbl_8028459C;
    *arg0 = (M2C_UNK *)&lbl_80286610;
    *arg0 = (M2C_UNK *)&lbl_802862E4;
    *arg0 = (M2C_UNK *)&lbl_8029A874;
}

void fn_801F1D70(s32 arg0) {
    void *Process_CreateChild(void *, s32);
    s32 fn_800C4638(s32, void *, s32);
    extern u8 lbl_8029A910[];
    extern u8 gCardLinkStrings[];
    void *temp_r31;

    temp_r31 = Process_CreateChild(lbl_8029A910, arg0);
    *(s32 *)((u8 *)temp_r31 + 0x30) = fn_800C4638(0xB0, gCardLinkStrings + 0xA4, 0);
}

void fn_801F1DC4(void *arg0) {
    s32 *temp_r3;

    temp_r3 = M2C_FIELD(arg0, s32 **, 0x30);
    *temp_r3 &= 0xFFFFFFFE;
}

void fn_801F1DD8(s32 arg0) {
    u8 fn_800A5C88(s32, void *);
    extern void *gPadInput;
    s32 temp_r31;
    s32 temp_r3;

    temp_r3 = M2C_FIELD(gPadInput, s32 *, 4);
    temp_r31 = temp_r3 & (M2C_FIELD(gPadInput, s32 *, 8) ^ temp_r3);
    if ((fn_800A5C88(temp_r3, gPadInput) == 0) || (temp_r31 & 0x1000)) {
        Process_ClearFunc(arg0);
    }
}

void fn_801F1E38(void *arg0) {
    void fn_800A5D1C(void *, s32, s32);
    void *inner;
    s32 idx;
    inner = *(void **)((u8 *)arg0 + 0x30);
    idx = *(s32 *)((u8 *)inner + 4);
    fn_800A5D1C(*(void **)((u8 *)lbl_8029A8C8 + idx * 0xC), 0, 1);
}

void fn_801F1E78(void *arg0) {
    s32 *temp_r3;

    temp_r3 = M2C_FIELD(arg0, s32 **, 0x30);
    *temp_r3 |= 1;
}

void fn_801F1E8C(void *arg0) {
    M2C_UNK FileCache_ReleaseSlot(s32);
    M2C_UNK fn_800C4588(s32);
    s32 temp_r31;

    temp_r31 = M2C_FIELD(arg0, s32 *, 0x30);
    FileCache_ReleaseSlot(temp_r31 + 0x4C);
    fn_800C4588(temp_r31);
}

void fn_801F1EC4(void *arg0) {
void Ui_PlaySeCue(void *,s32);
void Process_Goto(void *,s32);
void Process_ClearFunc(void *);
extern u8 gCardLinkStrings[];
struct Slot {s16 x,y,w; u8 flag,pad;};
u8 *p=*(u8 **)((u8 *)arg0+0x30);
u32 held=*(u32 *)((u8 *)gPadInput+4);
u32 pressed=held & (*(u32 *)((u8 *)gPadInput+8)^held);
u32 repeat=*(u32 *)((u8 *)gPadInput+12);
s32 old=*(s32 *)(p+4);

if (pressed&0x100) {
Ui_PlaySeCue(gCardLinkStrings+0xA5,100);
Process_Goto(arg0,1);
} else if (pressed&0x200) {
Ui_PlaySeCue(gCardLinkStrings+0xB5,100);
Process_ClearFunc(arg0);
} else {
if ((repeat&0x01000001)&&(*(s32 *)(p+4)%3>0)) {
*(s32 *)(p+4)=old-1;
if (*(s32 *)(p+4)<0) *(s32 *)(p+4)=0;
}
if ((repeat&0x02000002)&&(*(s32 *)(p+4)%3<2)) {
*(s32 *)(p+4)+=1;
if (*(s32 *)(p+4)>=6) *(s32 *)(p+4)=5;
}
if ((repeat&0x08000008)&&(*(s32 *)(p+4)>=3)) *(s32 *)(p+4)-=3;
if ((repeat&0x04000004)&&(*(s32 *)(p+4)<3)) *(s32 *)(p+4)+=3;
if(old!=*(s32 *)(p+4)){
*(s16 *)(p+0xC)=4;
*(s16 *)(p+0xE)=*(s16 *)(p+8);
*(s16 *)(p+0x10)=*(s16 *)(p+0xA);
*(s16 *)(p+0x12)=((struct Slot *)(p+0x1A))[*(s32 *)(p+4)].x;
*(s16 *)(p+0x14)=((struct Slot *)(p+0x1A))[*(s32 *)(p+4)].y;
Ui_PlaySeCue(gCardLinkStrings+0xC5,100);
}
}
}

void fn_801F20A8(s32 arg0) {
    extern u8 gCardLinkStrings[];
    s32 FileCache_GetFlags(void *);
    void Process_ClearFunc(s32);

    if (FileCache_GetFlags(gCardLinkStrings + 0xE1) & 0x2000) {
        Process_ClearFunc(arg0);
    }
}

/* Initialize Card Link UI: place six slots, build the caption, load the panel texture. */
void CardLink_InitUi(void *proc) {
    void *Msg_Expand(void *);
    void fn_8006EEFC(void *, void *);
    void fn_80147188(s32);
    void strcat(void *, void *);
    void strcpy(void *, void *);
    extern u8 gCardLinkStrings[];

    struct Slot {
        s16 x;
        s16 y;
        s16 w;
        u8 flag;
        u8 pad;
    };
    struct Obj {
        s32 unk0;
        s32 unk4;
        s16 unk8;
        s16 unkA;
        s16 unkC;
        s16 unkE;
        s16 unk10;
        s16 unk12;
        s16 unk14;
        s16 unk16;
        s16 unk18;
        struct Slot slots[6];
        s16 pad4A;
        u8 unk4C[4];
        u8 unk50[4];
    };
    struct Obj *ui;
    void *caption;
    u8 *str;
    s32 slotW;
    s32 zero;

    ui = *(struct Obj **)((u8 *)proc + 0x30);
    zero = 0;
    ui->unk0 = zero;
    ui->unk4 = zero;
    ui->unk8 = -0x64;
    ui->unkA = -0x64;
    ui->unk16 = 0x30;
    ui->unk18 = 0x70;
    fn_80147188(0);
    str = gCardLinkStrings;
    slotW = 0x40;
    ui->slots[0].x = *(s16 *)((u8 *)ui + 0x16) + 0x2A;
    zero = 0;
    caption = (u8 *)ui + 0x50;
    str = str + 0xF6;
    ui->slots[0].y = ui->unk18 + 0xB;
    ui->slots[0].w = slotW;
    ui->slots[0].flag = zero;
    ui->slots[1].x = ui->unk16 + 0xC4;
    ui->slots[1].y = ui->unk18 + 0xB;
    ui->slots[1].w = slotW;
    ui->slots[1].flag = zero;
    ui->slots[2].x = ui->unk16 + 0x15E;
    ui->slots[2].y = ui->unk18 + 0xB;
    ui->slots[2].w = slotW;
    ui->slots[2].flag = zero;
    ui->slots[3].x = ui->unk16 + 0x2A;
    ui->slots[3].y = ui->unk18 + 0x93;
    ui->slots[3].w = slotW;
    ui->slots[3].flag = zero;
    ui->slots[4].x = ui->unk16 + 0xC4;
    ui->slots[4].y = ui->unk18 + 0x93;
    ui->slots[4].w = slotW;
    ui->slots[4].flag = zero;
    ui->slots[5].x = ui->unk16 + 0x15E;
    ui->slots[5].y = ui->unk18 + 0x93;
    ui->slots[5].w = slotW;
    ui->slots[5].flag = zero;
    strcpy(caption, str);
    strcat(ui->unk50, Msg_Expand(gCardLinkStrings + 0xFC));
    strcat(ui->unk50, gCardLinkStrings + 0x107);
    strcat(ui->unk50, Msg_Expand(gCardLinkStrings + 0x10F));
    strcat(ui->unk50, gCardLinkStrings + 0x118);
    strcat(ui->unk50, Msg_Expand(gCardLinkStrings + 0x120));
    ui->unkC = 4;
    ui->unkE = ui->unk8;
    ui->unk10 = ui->unkA;
    ui->unk12 = ui->slots[ui->unk4].x;
    ui->unk14 = ui->slots[ui->unk4].y;
    ui->unkC = 0;
    ui->unk8 = ui->unk12;
    ui->unkA = ui->unk14;
    fn_8006EEFC(ui->unk4C, gCardLinkStrings + 0xE1);
}

void fn_801F230C(void *arg0) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetColor(u8, u8, u8, s32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetAlphaByte(u8);
    void Prim2D_SetColorByte(s32);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_BindTexture(s32, s32, s32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void *Msg_Expand(void *);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, ...);
    s32 Text_MeasureWidth(void *, s32, f32);
    void **fn_8006EDD8(s32, s32);
    void Ui_DrawCaptionBar(void *, s32);
    void Ui_DrawRouteIconEx(s16, s16, s32);
    s32 *Ui_GetColor(s32);
    extern u8 gCardLinkStrings[];
    extern void *lbl_8029A8C8[];
    extern f32 lbl_8036B808;
    extern f32 lbl_8036B80C;
    extern f32 lbl_8036B810;
    extern f32 lbl_8036B814;
    extern f32 lbl_8036B818;
    extern f32 lbl_8036B81C;
    extern f32 lbl_8036B820;
    extern f32 lbl_8036B824;
    extern f32 lbl_8036B828;
    extern f32 lbl_8036B82C;
    extern f32 lbl_8036B830;
    extern f32 lbl_8036B834;
    extern f32 lbl_8036B838;
    extern f32 lbl_8036B83C;
    extern f64 lbl_8036B840;
    extern f64 lbl_8036B848;

    u8 col0[4];
    u8 col1[4];
    u8 col2[4];
    u8 col3[4];
    u8 col4[4];
    u8 col5[4];
    u8 col6[4];
    void *obj;
    void *p;
    u8 *ep;
    s32 i;
    s32 n;
    s32 t;
    s32 tw;
    u16 h;
    u16 w;
    f32 f29;
    f32 f30;
    f32 f31;
    f32 fx;
    f32 fy;
    s32 tex;
    void **pp;
    void *texp;
    s16 tmp;

    obj = *(void **)((u8 *)arg0 + 0x30);
    if (!(*(s32 *)obj & 1)) {
        if (*(s16 *)((u8 *)obj + 0xC) > 0) {
            *(s16 *)((u8 *)obj + 0xC) = (s16)(*(s16 *)((u8 *)obj + 0xC) - 1);
            {
                s16 c = *(s16 *)((u8 *)obj + 0xC);
                s16 e = *(s16 *)((u8 *)obj + 0xE);
                s16 x = *(s16 *)((u8 *)obj + 0x12);
                t = 4 - c;
                *(s16 *)((u8 *)obj + 8) =
                    (s16)Math_Ease(4, (f32)e, (f32)x, (f32)t, lbl_8036B808);
            }
            {
                s16 y0 = *(s16 *)((u8 *)obj + 0x10);
                s16 y1 = *(s16 *)((u8 *)obj + 0x14);
                *(s16 *)((u8 *)obj + 0xA) =
                    (s16)Math_Ease(4, (f32)y0, (f32)y1, (f32)t, lbl_8036B808);
            }
        }
        p = obj;
        i = 0;
        for (n = 3; n != 0; n--) {
            if (i == *(s32 *)((u8 *)obj + 4)) {
                *((u8 *)p + 0x20) = 1;
            } else {
                *((u8 *)p + 0x20) = 0;
            }
            if (*((u8 *)p + 0x20) != 0) {
                tmp = (s16)(*(s16 *)((u8 *)p + 0x1E) + 0xA);
                *(s16 *)((u8 *)p + 0x1E) = tmp;
                if (*(s16 *)((u8 *)p + 0x1E) > 0x80) {
                    *(s16 *)((u8 *)p + 0x1E) = 0x80;
                }
            } else {
                tmp = (s16)(*(s16 *)((u8 *)p + 0x1E) - 0xA);
                *(s16 *)((u8 *)p + 0x1E) = tmp;
                if (*(s16 *)((u8 *)p + 0x1E) < 0x20) {
                    *(s16 *)((u8 *)p + 0x1E) = 0x20;
                }
            }
            i++;
            if (i == *(s32 *)((u8 *)obj + 4)) {
                *((u8 *)p + 0x28) = 1;
            } else {
                *((u8 *)p + 0x28) = 0;
            }
            if (*((u8 *)p + 0x28) != 0) {
                tmp = (s16)(*(s16 *)((u8 *)p + 0x26) + 0xA);
                *(s16 *)((u8 *)p + 0x26) = tmp;
                if (*(s16 *)((u8 *)p + 0x26) > 0x80) {
                    *(s16 *)((u8 *)p + 0x26) = 0x80;
                }
            } else {
                tmp = (s16)(*(s16 *)((u8 *)p + 0x26) - 0xA);
                *(s16 *)((u8 *)p + 0x26) = tmp;
                if (*(s16 *)((u8 *)p + 0x26) < 0x20) {
                    *(s16 *)((u8 *)p + 0x26) = 0x20;
                }
            }
            p = (u8 *)p + 0x10;
            i++;
        }

        Prim2D_Begin();
        Prim2D_SetTransform(lbl_8036B80C, lbl_8036B80C, lbl_8036B810, lbl_8036B814);
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
        *(s32 *)col0 = *Ui_GetColor(1);
        pp = fn_8006EDD8(*(s32 *)((u8 *)obj + 0x4C), 0);
        texp = *pp;
        h = *(u16 *)((u8 *)texp + 2);
        w = *(u16 *)texp;
        Prim2D_Begin();
        Prim2D_BindTexture(*(s32 *)((u8 *)obj + 0x4C), 0, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin(lbl_8036B80C, lbl_8036B80C, lbl_8036B80C, lbl_8036B80C);
        fy = lbl_8036B80C + (f32)w;
        fx = lbl_8036B80C + (f32)h;
        Prim2D_SetQuadMax(fx, fy, fx, fy);
        Prim2D_SetColor(col0[0], col0[1], col0[2], 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B818);
        Prim2D_PrepareTex();
        *(s32 *)col1 = *Ui_GetColor(1);
        pp = fn_8006EDD8(*(s32 *)((u8 *)obj + 0x4C), 3);
        texp = *pp;
        h = *(u16 *)((u8 *)texp + 2);
        w = *(u16 *)texp;
        Prim2D_Begin();
        Prim2D_BindTexture(*(s32 *)((u8 *)obj + 0x4C), 3, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin(lbl_8036B80C, lbl_8036B81C, lbl_8036B80C, lbl_8036B80C);
        fx = lbl_8036B80C + (f32)h;
        Prim2D_SetQuadMax(fx, lbl_8036B81C + (f32)w, fx, lbl_8036B80C + (f32)w);
        Prim2D_SetColor(col1[0], col1[1], col1[2], 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        *(s32 *)col2 = *Ui_GetColor(1);
        pp = fn_8006EDD8(*(s32 *)((u8 *)obj + 0x4C), 3);
        texp = *pp;
        h = *(u16 *)((u8 *)texp + 2);
        w = *(u16 *)texp;
        Prim2D_Begin();
        Prim2D_BindTexture(*(s32 *)((u8 *)obj + 0x4C), 3, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin(lbl_8036B820, lbl_8036B81C, lbl_8036B80C + (f32)h, lbl_8036B80C);
        Prim2D_SetQuadMax(lbl_8036B820 + (f32)h, lbl_8036B81C + (f32)w, lbl_8036B80C, lbl_8036B80C + (f32)w);
        Prim2D_SetColor(col2[0], col2[1], col2[2], 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B818);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        fn_8001003C(0xF0, 0x3D, 2, 0, 0, Msg_Expand(gCardLinkStrings + 0x128), lbl_8036B814, lbl_8036B80C);

        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B818);
        Prim2D_PrepareTex();
        *(s32 *)col3 = *Ui_GetColor(1);
        pp = fn_8006EDD8(*(s32 *)((u8 *)obj + 0x4C), 1);
        texp = *pp;
        h = *(u16 *)((u8 *)texp + 2);
        w = *(u16 *)texp;
        Prim2D_Begin();
        Prim2D_BindTexture(*(s32 *)((u8 *)obj + 0x4C), 1, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin(lbl_8036B824, lbl_8036B828, lbl_8036B80C, lbl_8036B80C);
        Prim2D_SetQuadMax(lbl_8036B824 + (f32)h, lbl_8036B828 + (f32)w, lbl_8036B80C + (f32)h, lbl_8036B80C + (f32)w);
        Prim2D_SetColor(col3[0], col3[1], col3[2], 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B818);
        Prim2D_PrepareTex();
        *(s32 *)col4 = *Ui_GetColor(1);
        pp = fn_8006EDD8(*(s32 *)((u8 *)obj + 0x4C), 2);
        texp = *pp;
        h = *(u16 *)((u8 *)texp + 2);
        w = *(u16 *)texp;
        Prim2D_Begin();
        Prim2D_BindTexture(*(s32 *)((u8 *)obj + 0x4C), 2, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin(lbl_8036B82C, lbl_8036B830, lbl_8036B80C, lbl_8036B80C);
        Prim2D_SetQuadMax(lbl_8036B82C + (f32)h, lbl_8036B830 + (f32)w, lbl_8036B80C + (f32)h, lbl_8036B80C + (f32)w);
        Prim2D_SetColor(col4[0], col4[1], col4[2], 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B834);
        Prim2D_PrepareTex();
        f30 = (f32)*(s16 *)((u8 *)obj + 0x18);
        f29 = (f32)*(s16 *)((u8 *)obj + 0x16);
        *(s32 *)col5 = *Ui_GetColor(1);
        pp = fn_8006EDD8(*(s32 *)((u8 *)obj + 0x4C), 4);
        texp = *pp;
        h = *(u16 *)((u8 *)texp + 2);
        w = *(u16 *)texp;
        Prim2D_Begin();
        Prim2D_BindTexture(*(s32 *)((u8 *)obj + 0x4C), 4, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin(f29, f30, lbl_8036B80C, lbl_8036B80C);
        Prim2D_SetQuadMax(f29 + (f32)h, f30 + (f32)w, lbl_8036B80C + (f32)h, lbl_8036B80C + (f32)w);
        Prim2D_SetColor(col5[0], col5[1], col5[2], 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B818);
        Prim2D_PrepareTex();
        ep = (u8 *)lbl_8029A8C8;
        f31 = lbl_8036B80C;
        p = obj;
        i = 0;
        do {
            Prim2D_Begin();
            Prim2D_SetAlphaByte((u8)*(s16 *)((u8 *)p + 0x1E));
            Prim2D_PrepareTex();
            Prim2D_Begin();
            Prim2D_SetTex(0, 0x13);
            Prim2D_PrepareTex();
            Msg_Expand(*(void **)(ep + 4));
            tw = (u16)Text_MeasureWidth((void *)0, -1, lbl_8036B814);
            fn_8001003C(
                (s16)((*(s16 *)((u8 *)p + 0x1A) + 0x3C) - ((tw >> 1) & 0x7FFF)),
                *(s16 *)((u8 *)p + 0x1C), 1, 1, 0,
                Msg_Expand(*(void **)(ep + 4)), lbl_8036B814, lbl_8036B80C);
            tex = (u16)(ep[8] + 5);
            fy = (f32)(*(s16 *)((u8 *)p + 0x1C) + 0x28);
            fx = (f32)(*(s16 *)((u8 *)p + 0x1A) + 4);
            *(s32 *)col6 = *Ui_GetColor(1);
            pp = fn_8006EDD8(*(s32 *)((u8 *)obj + 0x4C), tex);
            texp = *pp;
            h = *(u16 *)((u8 *)texp + 2);
            w = *(u16 *)texp;
            Prim2D_Begin();
            Prim2D_BindTexture(*(s32 *)((u8 *)obj + 0x4C), tex, 0x11);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetQuadMin(fx, fy, lbl_8036B80C, lbl_8036B80C);
            Prim2D_SetQuadMax(fx + (f32)h, fy + (f32)w, f31 + (f32)h, f31 + (f32)w);
            Prim2D_SetColor(col6[0], col6[1], col6[2], 0xFF);
            Prim2D_EmitQuad();
            Prim2D_EndPrim();
            Prim2D_Begin();
            Prim2D_SetAlphaByte(0x80);
            Prim2D_PrepareTex();
            i++;
            ep += 0xC;
            p = (u8 *)p + 8;
        } while (i < 6);

        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B814);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B838);
        Prim2D_PrepareTex();
        Ui_DrawRouteIconEx(*(s16 *)((u8 *)obj + 8), *(s16 *)((u8 *)obj + 0xA), 1);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B83C);
        Prim2D_PrepareTex();
        Ui_DrawCaptionBar((u8 *)obj + 0x50, 0);
        Prim2D_Begin();
        Prim2D_SetColorByte(0xFF);
        Prim2D_PrepareTex();
    }
}

void fn_801F2DB4(s32 arg0) {
    void *Process_CreateChild(void *, s32);
    s32 fn_800C4638(s32, void *, s32);
    extern u8 lbl_8029AF78[];
    extern u8 gOptionsStrs[];
    void *temp_r31;

    temp_r31 = Process_CreateChild(lbl_8029AF78, arg0);
    M2C_FIELD(temp_r31, s32 *, 0x30) = fn_800C4638(0xE8, gOptionsStrs + 0x11BC, 0);
}

#pragma use_lmw_stmw on
void fn_801F2E08(void *arg0) {
    s32 Person_GetByPid(s32);
    void Process_Goto(void *, s32);
    void fn_80057E6C(s32);
    void fn_8008A290(s32, s32);
    u8 fn_8008A59C(void);
    void Ui_PlaySeCue(char *, s32);
    u8 fn_801E3570(void *, s32);
    extern void *gPadInput;
    extern char gOptionsStrs[];
    extern u8 gOptionsList1[];
    extern u8 gSystemSave[];
    void *obj;
    s32 pressed;
    s32 stick;
    s32 held;
    s32 tmp;
    s32 pages;
    s16 idx;

    obj = *(void **)((u8 *)arg0 + 0x30);
    held = *(s32 *)((u8 *)gPadInput + 4);
    stick = *(s32 *)((u8 *)gPadInput + 0xC);
    pressed = held & (*(s32 *)((u8 *)gPadInput + 8) ^ held);
    if (((pressed & 0x100) && (fn_8008A59C() == 0)) || ((pressed & 0x200) && (fn_8008A59C() == 0))) {
        Ui_PlaySeCue(gOptionsStrs + 0x11BD, 0x64);
        Process_Goto(arg0, 1);
        fn_8008A290(3, 0xB4);
        return;
    }
    if ((stick & 0x08000008) && (fn_8008A59C() == 0)) {
        for (;;) {
            *(s16 *)((u8 *)obj + 0xE) = (s16)(*(s16 *)((u8 *)obj + 0xE) - 1);
            if (*(s16 *)((u8 *)obj + 0xE) < 0) {
                *(s16 *)((u8 *)obj + 0xE) = (s16)(*(u8 *)((u8 *)obj + 0x29) - 1);
            }
            if (*(u8 *)((u8 *)obj + 0x11) != 1) {
                break;
            }
            if (fn_801E3570(gSystemSave, Person_GetByPid(*(s32 *)(gOptionsList1 + *(s16 *)((u8 *)obj + 0xE) * 8))) != 0) {
                break;
            }
        }
        goto scroll_dec_test;
    scroll_dec_body:
        *(s16 *)((u8 *)obj + 0x2C) = (s16)(*(s16 *)((u8 *)obj + 0x2C) - 1);
    scroll_dec_test:
        idx = *(s16 *)((u8 *)obj + 0xE);
        if ((idx / 3) - *(s16 *)((u8 *)obj + 0x2C) > 0) {
            goto scroll_inc_test;
        }
        if (*(s16 *)((u8 *)obj + 0x2C) > 0) {
            goto scroll_dec_body;
        }
        goto scroll_inc_test;
    scroll_inc_body:
        *(s16 *)((u8 *)obj + 0x2C) = (s16)(*(s16 *)((u8 *)obj + 0x2C) + 1);
    scroll_inc_test:
        idx = *(s16 *)((u8 *)obj + 0xE);
        if ((idx / 3) - *(s16 *)((u8 *)obj + 0x2C) < 7) {
            goto scroll_done;
        }
        pages = *(u8 *)((u8 *)obj + 0x29) / 3;
        if ((*(u8 *)((u8 *)obj + 0x29) % 3) > 0) {
            pages += 1;
        }
        if (*(s16 *)((u8 *)obj + 0x2C) < (s32)(pages - 8)) {
            goto scroll_inc_body;
        }
    scroll_done:
        fn_80057E6C(*(s32 *)((u8 *)obj + 0xDC));
        tmp = *(s16 *)((u8 *)obj + 0xE) - *(s16 *)((u8 *)obj + 0x2C) * 3;
        *(s16 *)((u8 *)obj + 0x16) = 0;
        *(s16 *)((u8 *)obj + 0x12) = (s16)((tmp % 3) * 0xA0 + 0x45);
        *(s16 *)((u8 *)obj + 0x14) = (s16)((tmp / 3) * 0x1C + 0x9C);
        Ui_PlaySeCue(gOptionsStrs + 0x11CD, 0x64);
        Process_Goto(arg0, 3);
        return;
    }
    if ((stick & 0x04000004) && (fn_8008A59C() == 0)) {
        for (;;) {
            *(s16 *)((u8 *)obj + 0xE) = (s16)(*(s16 *)((u8 *)obj + 0xE) + 1);
            if (*(s16 *)((u8 *)obj + 0xE) >= *(u8 *)((u8 *)obj + 0x29)) {
                *(s16 *)((u8 *)obj + 0xE) = 0;
            }
            if (*(u8 *)((u8 *)obj + 0x11) != 1) {
                break;
            }
            if (fn_801E3570(gSystemSave, Person_GetByPid(*(s32 *)(gOptionsList1 + *(s16 *)((u8 *)obj + 0xE) * 8))) != 0) {
                break;
            }
        }
        goto scroll2_dec_test;
    scroll2_dec_body:
        *(s16 *)((u8 *)obj + 0x2C) = (s16)(*(s16 *)((u8 *)obj + 0x2C) - 1);
    scroll2_dec_test:
        idx = *(s16 *)((u8 *)obj + 0xE);
        if ((idx / 3) - *(s16 *)((u8 *)obj + 0x2C) > 0) {
            goto scroll2_inc_test;
        }
        if (*(s16 *)((u8 *)obj + 0x2C) > 0) {
            goto scroll2_dec_body;
        }
        goto scroll2_inc_test;
    scroll2_inc_body:
        *(s16 *)((u8 *)obj + 0x2C) = (s16)(*(s16 *)((u8 *)obj + 0x2C) + 1);
    scroll2_inc_test:
        idx = *(s16 *)((u8 *)obj + 0xE);
        if ((idx / 3) - *(s16 *)((u8 *)obj + 0x2C) < 7) {
            goto scroll2_done;
        }
        pages = *(u8 *)((u8 *)obj + 0x29) / 3;
        if ((*(u8 *)((u8 *)obj + 0x29) % 3) > 0) {
            pages += 1;
        }
        if (*(s16 *)((u8 *)obj + 0x2C) < (s32)(pages - 8)) {
            goto scroll2_inc_body;
        }
    scroll2_done:
        fn_80057E6C(*(s32 *)((u8 *)obj + 0xE0));
        tmp = *(s16 *)((u8 *)obj + 0xE) - *(s16 *)((u8 *)obj + 0x2C) * 3;
        *(s16 *)((u8 *)obj + 0x16) = 0;
        *(s16 *)((u8 *)obj + 0x12) = (s16)((tmp % 3) * 0xA0 + 0x45);
        *(s16 *)((u8 *)obj + 0x14) = (s16)((tmp / 3) * 0x1C + 0x9C);
        Ui_PlaySeCue(gOptionsStrs + 0x11CD, 0x64);
        Process_Goto(arg0, 3);
    }
}
void fn_801F31D0(void *arg0) {
    s32 FileCache_GetFlags(s32);
    if (FileCache_GetFlags(M2C_FIELD(arg0, s32 *, 0x30) + 0xB4) & 0x2000) {
        Process_ClearFunc(arg0);
    }
}

void Options_LoadSelectedEntry(void *proc) {
    struct Entry {
        s32 unk0;
        char *name;
    };
    struct Work {
        u8 pad0[4];
        void *asset;
        s32 state;
        u8 padC[2];
        s16 cursor;
        u8 pad10[0x10];
        u8 flag20;
        u8 pad21[5];
        u8 flag26;
        u8 pad27;
        u8 flag28;
        u8 pad29[0xB];
        struct Entry *list;
        u8 pad38[0x1C];
        char caption[0x60];
        char path[0x28];
        s32 btnLeft;
        s32 btnRight;
    };
    void fn_80057E64(s32, s32);
    char *Msg_Expand(char *);
    void FileCache_ReleaseSlot(void *);
    void fn_8006EEFC(void *, char *);
    char *strcpy(char *, const char *);
    char *strcat(char *, const char *);
    extern char gOptionsStrs[];
    char buf[64];
    struct Work *work;

    // Show nav buttons, build the caption, and load the asset for the cursor entry.
    work = M2C_FIELD(proc, struct Work **, 0x30);
    work->state = 2;
    work->caption[0] = 0;
    work->flag20 = 0;
    work->flag26 = 0;
    work->flag28 = 0;
    fn_80057E64(work->btnLeft, 1);
    fn_80057E64(work->btnRight, 1);
    strcpy(work->caption, gOptionsStrs + 0x11E9);
    strcat(work->caption, Msg_Expand(gOptionsStrs + 0x11EF));
    strcat(work->caption, gOptionsStrs + 0x11FA);
    strcat(work->caption, Msg_Expand(gOptionsStrs + 0x1209));
    if (work->asset != NULL) {
        if (work->asset != NULL) {
            FileCache_ReleaseSlot(&work->asset);
            work->asset = NULL;
        }
    }
    strcpy(buf, gOptionsStrs + 0x1214);
    strcat(buf, work->list[work->cursor].name);
    fn_8006EEFC(&work->asset, buf);
    strcpy(work->path, buf);
}

void fn_801F3338(void *arg0) {
    s32 Person_GetByPid(s32);
    M2C_UNK fn_8008A290(M2C_UNK, M2C_UNK);
    u8 fn_8008A59C();
    u8 fn_801E3570(void *, s32);
    extern u8 gOptionsStrs[];
    extern u8 gOptionsList1[];
    extern u8 gSystemSave[];
    extern f32 lbl_8036B850;
    extern f32 lbl_8036B854;
    s32 temp_r27;
    s16 temp_r29;
    void *temp_r30;
    s32 temp_r31;
    s32 temp_r3;
    s16 temp_r3_2;
    s16 temp_r4;
    s16 temp_r4_2;
    s16 temp_r4_3;
    s16 temp_r5;
    s16 temp_r7;
    s32 temp_r5_2;
    s32 temp_r5_3;
    u32 temp_r6;
    u32 var_r3;

    temp_r30 = M2C_FIELD(arg0, void **, 0x30);
    temp_r3 = M2C_FIELD(gPadInput, s32 *, 4);
    temp_r31 = M2C_FIELD(gPadInput, s32 *, 0xC);
    temp_r29 = M2C_FIELD(temp_r30, s16 *, 0xE);
    temp_r27 = temp_r3 & (M2C_FIELD(gPadInput, s32 *, 8) ^ temp_r3);
    if ((temp_r27 & 0x100) && (fn_8008A59C() == 0)) {
        if (M2C_FIELD(temp_r30, u8 *, 0x11) == 1) {
            if (fn_801E3570(gSystemSave, Person_GetByPid(*(s32 *)(gOptionsList1 + M2C_FIELD(temp_r30, s16 *, 0xE) * 8))) != 0) {
                Ui_PlaySeCue(gOptionsStrs + 0x121C, 0x64);
                Process_Goto(arg0, 2);
                fn_8008A290(3, 0xB4);
                return;
            }
        }
    }
    if ((temp_r27 & 0x200) && (fn_8008A59C() == 0)) {
        Ui_PlaySeCue(gOptionsStrs + 0x11BD, 0x64);
        Process_Goto(arg0, 0);
        fn_8008A290(3, 0xB4);
        return;
    }
    if (temp_r31 & 0x08000008) {
        temp_r3_2 = M2C_FIELD(temp_r30, s16 *, 0xE);
        if (temp_r3_2 >= 3) {
            M2C_FIELD(temp_r30, s16 *, 0xE) = (s16)(temp_r3_2 - 3);
            temp_r4 = M2C_FIELD(temp_r30, s16 *, 0x2C);
            if ((((M2C_FIELD(temp_r30, s16 *, 0xE) / 3) - temp_r4) <= 0) && (temp_r4 > 0)) {
                M2C_FIELD(temp_r30, s16 *, 0x2C) = (s16)(temp_r4 - 1);
                M2C_FIELD(temp_r30, f32 *, 0x30) = (f32)lbl_8036B850;
            }
        }
    }
    if (temp_r31 & 0x04000004) {
        temp_r4_2 = M2C_FIELD(temp_r30, s16 *, 0xE) + 3;
        if (temp_r4_2 <= (s32)(M2C_FIELD(temp_r30, u8 *, 0x29) - 1)) {
            M2C_FIELD(temp_r30, s16 *, 0xE) = temp_r4_2;
            temp_r5 = M2C_FIELD(temp_r30, s16 *, 0x2C);
            if ((s32)((M2C_FIELD(temp_r30, s16 *, 0xE) / 3) - temp_r5) >= 7) {
                var_r3 = M2C_FIELD(temp_r30, u8 *, 0x29) / 3;
                if ((M2C_FIELD(temp_r30, u8 *, 0x29) % 3) > 0) {
                    var_r3 += 1;
                }
                if (temp_r5 < (s32)(var_r3 - 8)) {
                    M2C_FIELD(temp_r30, s16 *, 0x2C) = (s16)(M2C_FIELD(temp_r30, s16 *, 0x2C) + 1);
                    M2C_FIELD(temp_r30, f32 *, 0x30) = (f32)lbl_8036B854;
                }
            }
        }
    }
    if ((temp_r31 & 0x01000001) && ((M2C_FIELD(temp_r30, s16 *, 0xE) % 3) != 0)) {
        M2C_FIELD(temp_r30, s16 *, 0xE) = (s16)(M2C_FIELD(temp_r30, s16 *, 0xE) - 1);
    }
    if ((temp_r31 & 0x02000002) && ((s32)(M2C_FIELD(temp_r30, s16 *, 0xE) % 3) != 2)) {
        temp_r4_3 = M2C_FIELD(temp_r30, s16 *, 0xE) + 1;
        if (temp_r4_3 <= (s32)(M2C_FIELD(temp_r30, u8 *, 0x29) - 1)) {
            M2C_FIELD(temp_r30, s16 *, 0xE) = temp_r4_3;
        }
    }
    temp_r7 = M2C_FIELD(temp_r30, s16 *, 0xE);
    if (temp_r29 != temp_r7) {
        temp_r5_2 = M2C_FIELD(temp_r30, s16 *, 0x2C) * 3;
        M2C_FIELD(temp_r30, s16 *, 0x16) = 4;
        M2C_FIELD(temp_r30, s16 *, 0x18) = (s16)M2C_FIELD(temp_r30, s16 *, 0x12);
        M2C_FIELD(temp_r30, s16 *, 0x1A) = (s16)M2C_FIELD(temp_r30, s16 *, 0x14);
        temp_r6 = (temp_r7 - temp_r5_2) / 3;
        temp_r5_3 = temp_r6 * 0x1C;
        M2C_FIELD(temp_r30, s16 *, 0x1C) = (s16)((((temp_r7 - temp_r5_2) % 3) * 0xA0) + 0x45);
        M2C_FIELD(temp_r30, s16 *, 0x1E) = (s16)(temp_r5_3 + 0x9C);
        Ui_PlaySeCue(gOptionsStrs + 0x122C, 0x64);
    }
}

/* Initialize an options panel: select entry list, compute layout, build title. */
void Options_InitPanel(void *proc) {
    struct OptEntry {
        u32 id;
        char *name;
    };
    struct OptPanel {
        u8 pad0[4];
        void *tex;
        s32 state;
        u8 padC[2];
        s16 cursor;
        u8 pad10;
        u8 category;
        s16 posX;
        s16 posY;
        s16 scroll;
        u8 pad18[8];
        u8 flag20;
        u8 pad21[5];
        u8 flag26;
        u8 prevCategory;
        u8 flag28;
        u8 entryCount;
        s16 panelH;
        s16 unk2C;
        u8 pad30[4];
        struct OptEntry *entries;
        u8 pad38[4];
        char title[0x18];
        char header[0x60];
        char padB4[0x28];
        s32 handleDC;
        s32 handleE0;
    };
    void fn_80057E64(s32, s32);
    char *Msg_Expand(char *);
    void FileCache_ReleaseSlot(void *);
    char *strcpy(char *, const char *);
    char *strcat(char *, const char *);
    extern char gOptionsStrs[];
    extern u8 gOptionsList1[];
    extern u8 gOptionsList2[];
    extern u8 gOptionsList3[];
    extern u8 gOptionsList4[];
    struct OptPanel *p;
    struct OptEntry *entry;
    s32 rows;
    s32 diff;
    s32 quotient;
    s32 remainder;

    p = M2C_FIELD(proc, struct OptPanel **, 0x30);
    p->state = 5;
    p->header[0] = 0;
    p->flag20 = 0;
    p->flag26 = 1;
    p->flag28 = 1;
    fn_80057E64(p->handleDC, 0);
    fn_80057E64(p->handleE0, 0);
    strcpy(p->title, gOptionsStrs + 0x1248);
    p->prevCategory = p->category;
    switch (p->category) {
    case 1:
        p->entries = (struct OptEntry *)gOptionsList1;
        break;
    case 2:
        p->entries = (struct OptEntry *)gOptionsList2;
        break;
    case 3:
        p->entries = (struct OptEntry *)gOptionsList3;
        break;
    case 4:
        p->entries = (struct OptEntry *)gOptionsList4;
        break;
    }
    entry = p->entries;
    p->entryCount = 0;
    while (entry->id != 0) {
        entry++;
        p->entryCount = (u8)(p->entryCount + 1);
    }
    rows = p->entryCount / 3;
    if (p->entryCount % 3 > 0) {
        rows++;
    }
    p->panelH = (s16)(rows * 0x1C + 0x30);
    if (p->panelH > 0x10C) {
        p->panelH = 0x10C;
    }
    diff = (s32)p->cursor - (s32)p->unk2C * 3;
    p->scroll = 0;
    quotient = diff / 3;
    remainder = diff % 3;
    p->posX = (s16)(remainder * 0xA0 + 0x45);
    p->posY = (s16)(quotient * 0x1C + 0x9C);
    strcpy(p->header, gOptionsStrs + 0x1259);
    strcat(p->header, Msg_Expand(gOptionsStrs + 0x11EF));
    strcat(p->header, gOptionsStrs + 0x125F);
    strcat(p->header, Msg_Expand(gOptionsStrs + 0x1267));
    strcat(p->header, gOptionsStrs + 0x1272);
    strcat(p->header, Msg_Expand(gOptionsStrs + 0x1209));
    if (p->tex != NULL) {
        if (p->tex != NULL) {
            FileCache_ReleaseSlot(&p->tex);
            p->tex = NULL;
        }
    }
}

void fn_801F3890(void *arg0) {
void Ui_PlaySeCue(void *,s32);
void Process_Goto(void *,s32);
u8 fn_8008A59C(void);
void fn_8008A290(s32,s32);
extern char gOptionsStrs[];
extern f32 lbl_8036B858;
u32 pressed;
u32 repeat;
s32 old;
u8 *p;
u8 *list;
u32 held;
u8 category;
p=*(u8 **)((u8 *)arg0+0x30);
old=*(s16 *)(p+0xC);
list=p+0x20;
held=*(u32 *)((u8 *)gPadInput+4);
pressed=held & (*(u32 *)((u8 *)gPadInput+8)^held);
repeat=*(u32 *)((u8 *)gPadInput+12);
category=p[0x11];
if(category!=list[old+2]){
s16 tmp;
p[0x10]=category;
p[0x11]=list[*(s16 *)(p+0xC)+2];
tmp=*(s16 *)(p+0x38);
*(s16 *)(p+0x38)=*(s16 *)(p+0x3A);
*(s16 *)(p+0x3A)=tmp;
}
if((pressed&0x100)&&!fn_8008A59C()){
*(s16 *)(p+0xE)=0;
*(s16 *)(p+0x2C)=0;
*(f32 *)(p+0x30)=0.0f;
Ui_PlaySeCue(gOptionsStrs+0x121C,100);
Process_Goto(arg0,1);
fn_8008A290(3,180);
} else if((pressed&0x200)&&!fn_8008A59C()){
Ui_PlaySeCue(gOptionsStrs+0x11BD,100);
Process_Goto(arg0,4);
} else {
if(repeat&0x08000008){
s32 y;
*(s16 *)(p+0xC)-=1;
if(*(s16 *)(p+0xC)<0) *(s16 *)(p+0xC)=0;
y=*(s16 *)(p+0xC)*0x30+0x78;
*(s16 *)(p+0x16)=4;
*(s16 *)(p+0x18)=*(s16 *)(p+0x12);
*(s16 *)(p+0x1A)=*(s16 *)(p+0x14);
*(s16 *)(p+0x1C)=0x40;
*(s16 *)(p+0x1E)=y;
}
if(repeat&0x04000004){
s32 y;
*(s16 *)(p+0xC)+=1;
if(*(s16 *)(p+0xC)>=list[1]) *(s16 *)(p+0xC)=list[1]-1;
y=*(s16 *)(p+0xC)*0x30+0x78;
*(s16 *)(p+0x16)=4;
*(s16 *)(p+0x18)=*(s16 *)(p+0x12);
*(s16 *)(p+0x1A)=*(s16 *)(p+0x14);
*(s16 *)(p+0x1C)=0x40;
*(s16 *)(p+0x1E)=y;
}
if(old!=*(s16 *)(p+0xC)) Ui_PlaySeCue(gOptionsStrs+0x122C,100);
}
}

void fn_801F3A88(void *arg0) {
void fn_80057E64(s32,s32);
char *strcpy(char *,const char *);
char *strcat(char *,const char *);
char *Msg_Expand(char *);
extern char gOptionsStrs[];
extern u8 gSystemSave[];
struct Panel { u8 pad0[8]; s32 state; s16 cursor; s16 unkE; u8 category,previous; s16 x,y,scroll; u8 pad18[0x24]; char title[0x18]; char header[0x88]; s32 dc,e0; };
struct Panel *p = *(struct Panel **)((u8 *)arg0+0x30);
u8 *list;
s32 n;
p->state=13;
list=(u8 *)p+(short)0x20;
p->unkE=0;
p->header[0]=0;
((u8 *)p)[0x20]=1;
((u8 *)p)[0x26]=0;
((u8 *)p)[0x28]=0;
fn_80057E64(p->dc,0);
fn_80057E64(p->e0,0);
strcpy(p->title,gOptionsStrs+0x127A);
list[2]=1;
n=1;
if (*(u16 *)(gSystemSave+0x10)&0x10) {list[3]=3;n=2;}
if (*(u16 *)(gSystemSave+0x10)&(unsigned short)0x20) {list[n+2]=4;n++;}
list[1]=n;
p->category=p->previous=list[p->cursor+2];
p->scroll=0;
p->x=0x40;
p->y=p->cursor*0x30+0x78;
strcpy(p->header,gOptionsStrs+0x11E9);
strcat(p->header,Msg_Expand(gOptionsStrs+0x11EF));
strcat(p->header,gOptionsStrs+0x125F);
strcat(p->header,Msg_Expand(gOptionsStrs+0x1267));
strcat(p->header,gOptionsStrs+0x1272);
strcat(p->header,Msg_Expand(gOptionsStrs+0x128B));
}

#pragma cplusplus on
extern "C" void fn_801F3C1C(void *arg0) {
 void FileCache_ReleaseSlot(void *); void fn_80161F7C(void); void fn_80057A10(void *, s32); void fn_800C4588(void *);
 struct Obj { u8 pad[0x2C]; virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0; virtual void v4()=0; virtual void v5()=0; virtual void v6(s32)=0; };
 u32 *obj=*(u32 **)((u8 *)arg0+0x30); Obj *p;
 if(obj[1]) { if(obj[1]) { FileCache_ReleaseSlot(obj+1); obj[1]=0; } }
 FileCache_ReleaseSlot(obj); fn_80161F7C();
 fn_80057A10((void *)obj[0xDC/4],1); fn_80057A10((void *)obj[0xE0/4],1);
 p=(Obj *)obj[0xE4/4]; if(p) p->v6(1);
 fn_800C4588(obj);
}
#pragma cplusplus reset

void fn_801F3CB0(s32 arg0) {
    extern u8 gOptionsStrs[];
    s32 FileCache_GetFlags(void *);
    s32 fn_80161FB8(void);
    void fn_80162054(void);
    void Process_ClearFunc(s32);

    if (FileCache_GetFlags(gOptionsStrs + 0x1293) & 0x2000) {
        if (fn_80161FB8() != 0) {
            fn_80162054();
            Process_ClearFunc(arg0);
        }
    }
}

void fn_801F3D08(void *arg0) {
    void *Heap_Alloc(s32);
    void *fn_80057A64(void *,s32);
    void *fn_80057998(void *);
    void fn_80057E98(void *,s32,s32);
    void fn_80057E5C(void *,s32);
    void fn_80057E64(void *,s32);
    void ScrollBar_RecreateArrows(void *,s32);
    void fn_80147188(s32);
    void fn_8006EEFC(void *,void *);
    void fn_80162018(void);
    extern char gOptionsStrs[];
    u8 *p=*(u8 **)((u8 *)arg0+0x30);
    void *obj;
    *(s32*)(p+4)=0;
    *(s32*)(p+8)=0;
    *(s16*)(p+0xC)=0;
    *(s16*)(p+0xE)=0;
    *(s16*)(p+0x12)=-100;
    *(s16*)(p+0x14)=-100;
    p[0x54]=0;
    p[0xB4]=0;
    *(s16*)(p+0x38)=0;
    *(s16*)(p+0x3A)=255;
    obj=Heap_Alloc(0x58);
    if(obj) obj=fn_80057A64(obj,8);
    *(void **)(p+0xDC)=obj;
    fn_80057E98(*(void **)(p+0xDC),300,24);
    fn_80057E5C(*(void **)(p+0xDC),1);
    obj=Heap_Alloc(0x58);
    if(obj) obj=fn_80057A64(obj,4);
    *(void **)(p+0xE0)=obj;
    fn_80057E98(*(void **)(p+0xE0),300,400);
    fn_80057E5C(*(void **)(p+0xE0),1);
    fn_80057E64(*(void **)(p+0xDC),0);
    fn_80057E64(*(void **)(p+0xE0),0);
    obj=Heap_Alloc(0x30);
    if(obj) obj=fn_80057998(obj);
    *(void **)(p+0xE4)=obj;
    ScrollBar_RecreateArrows(*(void **)(p+0xE4),1);
    fn_80147188(0);
    *(s16*)(p+0x16)=4;
    *(s16*)(p+0x18)=*(s16*)(p+0x12);
    *(s16*)(p+0x1A)=*(s16*)(p+0x14);
    *(s16*)(p+0x1C)=-100;
    *(s16*)(p+0x1E)=-100;
    fn_8006EEFC(p,gOptionsStrs+0x1293);
    fn_80162018();
}

#pragma use_lmw_stmw on
void fn_801F3E60(void *arg0) {
    typedef struct { u8 r, g, b, a; } Color;
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetColor(s32, s32, s32, s32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetAlphaByte(s32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_ClearCallbacks(void);
    void Prim2D_SetCallback(void (*)(s32, s16 *), s16 *);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_BindTexture(s32, s32, s32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void *Msg_Expand(void *);
    void fn_8001003C(s16, s16, s32, s32, s32, void *, ...);
    s32 Text_MeasureWidth(void *, s32, f32);
    s32 Person_GetByPid(s32);
    void fn_80057020(s32);
    void fn_80057860(s32, s16);
    void fn_80057880(s32, s32);
    void fn_80057898(s32, s32);
    void fn_800578A0(s32, f32);
    void fn_800578A8(s32, s32, s32, s32);
    void fn_80057AE0(s32);
    u16 **fn_8006EDD8(s32, s32);
    void Ui_DrawCaptionBar(void *, s32);
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    void Ui_DrawRouteIconEx(s16, s16, s32);
    void *Msg_ResolveName(s32);
    void fn_80152010(s16, s16, s32, s32, s32);
    void fn_8015F24C(s32, s32, s32, s32, s32);
    Color *Ui_GetColor(s32);
    u8 fn_801E3570(void *, s32, void *);
    void fn_801F52A8(s32, s16 *);
    void __mod2i(s32, s32);
    f32 fn_8022CB78(void);
    f64 sin(f32);
    extern s32 OSGetTime(void);
    extern void __div2i(s32, s32);
    extern u8 gOptionsStrs[];
    extern u8 gSystemSave[];
    extern s8 lbl_803683E0;
    extern s16 lbl_803683E4[4];
    extern f32 lbl_8036B850;
    extern f32 lbl_8036B854;
    extern f32 lbl_8036B858;
    extern f32 lbl_8036B85C;
    extern f32 lbl_8036B860;
    extern f32 lbl_8036B864;
    extern f32 lbl_8036B868;
    extern f32 lbl_8036B86C;
    extern f32 lbl_8036B870;
    extern f32 lbl_8036B874;
    extern f32 lbl_8036B878;
    extern f32 lbl_8036B87C;
    extern f32 lbl_8036B880;
    extern f32 lbl_8036B884;
    extern f32 lbl_8036B888;
    extern f32 lbl_8036B88C;
    extern f32 lbl_8036B890;
    extern f32 lbl_8036B894;
    extern f32 lbl_8036B898;
    extern f32 lbl_8036B89C;
    extern f32 lbl_8036B8A0;
    extern f32 lbl_8036B8A4;
    extern f32 lbl_8036B8A8;
    extern f32 lbl_8036B8AC;
    extern f32 lbl_8036B8B0;
    extern f32 lbl_8036B8B4;
    extern f32 lbl_8036B8B8;
    extern f32 lbl_8036B8BC;
    extern f32 lbl_8036B8C0;
    extern f32 lbl_8036B8C4;
    extern f32 lbl_8036B8C8;

    Color c0, c1, c2, c3, c4, c5, c6, c7, c8;
    void *p;
    u8 *slot;
    s32 t;
    s32 texA;
    s32 texB;
    s32 alpha;
    u16 *tex;
    u16 tw, th;
    s32 i;
    s32 y;
    void *str;
    void *label;
    s32 w;
    s32 rows;
    f32 f31v, f30v, f29v;

    p = *(void **)((u8 *)arg0 + 0x30);
    slot = (u8 *)p + 0x20;
    if (*(s16 *)((u8 *)p + 0x16) > 0) {
        *(s16 *)((u8 *)p + 0x16) = (s16)(*(s16 *)((u8 *)p + 0x16) - 1);
        t = 4 - *(s16 *)((u8 *)p + 0x16);
        *(s16 *)((u8 *)p + 0x12) = (s16)Math_Ease(4, (f32)*(s16 *)((u8 *)p + 0x18), (f32)*(s16 *)((u8 *)p + 0x1C), (f32)t, lbl_8036B85C);
        *(s16 *)((u8 *)p + 0x14) = (s16)Math_Ease(4, (f32)*(s16 *)((u8 *)p + 0x1A), (f32)*(s16 *)((u8 *)p + 0x1E), (f32)t, lbl_8036B85C);
    }
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B858, lbl_8036B858, lbl_8036B860, lbl_8036B854);
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();
    switch (*(u8 *)((u8 *)p + 0x10)) {
    case 1: texA = 5; break;
    case 2: texA = 6; break;
    case 3: texA = 7; break;
    case 4: texA = 8; break;
    default: texA = 0; break;
    }
    switch (*(u8 *)((u8 *)p + 0x11)) {
    case 1: texB = 5; break;
    case 2: texB = 6; break;
    case 3: texB = 7; break;
    case 4: texB = 8; break;
    default: texB = 0; break;
    }
    *(s16 *)((u8 *)p + 0x38) = (s16)(*(s16 *)((u8 *)p + 0x38) - 0x10);
    if (*(s16 *)((u8 *)p + 0x38) < 0) {
        *(s16 *)((u8 *)p + 0x38) = 0;
    }
    *(s16 *)((u8 *)p + 0x3A) = (s16)(*(s16 *)((u8 *)p + 0x3A) + 0x10);
    if (*(s16 *)((u8 *)p + 0x3A) > 0xFF) {
        *(s16 *)((u8 *)p + 0x3A) = 0xFF;
    }
    c0 = *Ui_GetColor(1);
    tex = *fn_8006EDD8(*(s32 *)p, texA);
    tw = tex[1];
    th = tex[0];
    Prim2D_Begin();
    Prim2D_BindTexture(*(s32 *)p, texA, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B858, lbl_8036B858, lbl_8036B858, lbl_8036B858);
    Prim2D_SetQuadMax(lbl_8036B858 + (f32)tw, lbl_8036B858 + (f32)th, lbl_8036B858 + (f32)tw, lbl_8036B858 + (f32)th);
    Prim2D_SetColor(c0.r, c0.g, c0.b, 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B864);
    Prim2D_PrepareTex();
    alpha = (u8)*(s16 *)((u8 *)p + 0x3A);
    c1 = *Ui_GetColor(1);
    tex = *fn_8006EDD8(*(s32 *)p, texB);
    tw = tex[1];
    th = tex[0];
    Prim2D_Begin();
    Prim2D_BindTexture(*(s32 *)p, texB, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B858, lbl_8036B858, lbl_8036B858, lbl_8036B858);
    Prim2D_SetQuadMax(lbl_8036B858 + (f32)tw, lbl_8036B858 + (f32)th, lbl_8036B858 + (f32)tw, lbl_8036B858 + (f32)th);
    Prim2D_SetColor(c1.r, c1.g, c1.b, alpha);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B868);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B850);
    Prim2D_PrepareTex();
    if (*(u32 *)((u8 *)p + 8) & 4) {
        c2 = *Ui_GetColor(1);
        tex = *fn_8006EDD8(*(s32 *)p, 2);
        tw = tex[1];
        th = tex[0];
        Prim2D_Begin();
        Prim2D_BindTexture(*(s32 *)p, 2, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin(lbl_8036B858, lbl_8036B86C, lbl_8036B858, lbl_8036B858);
        Prim2D_SetQuadMax(lbl_8036B858 + (f32)tw, lbl_8036B86C + (f32)th, lbl_8036B858 + (f32)tw, lbl_8036B858 + (f32)th);
        Prim2D_SetColor(c2.r, c2.g, c2.b, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        c3 = *Ui_GetColor(1);
        tex = *fn_8006EDD8(*(s32 *)p, 2);
        tw = tex[1];
        th = tex[0];
        Prim2D_Begin();
        Prim2D_BindTexture(*(s32 *)p, 2, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin(lbl_8036B870, lbl_8036B86C, lbl_8036B858 + (f32)tw, lbl_8036B858);
        Prim2D_SetQuadMax(lbl_8036B870 + (f32)tw, lbl_8036B86C + (f32)th, lbl_8036B858, lbl_8036B858 + (f32)th);
        Prim2D_SetColor(c3.r, c3.g, c3.b, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B850);
        Prim2D_PrepareTex();
        Prim2D_Begin();
        Prim2D_SetTex(0, 0x13);
        Prim2D_PrepareTex();
        fn_8001003C(0xB4, 0x3D, 2, 0, 0, Msg_Expand((u8 *)p + 0x3C), lbl_8036B854, lbl_8036B858);
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B850);
        Prim2D_PrepareTex();
        c4 = *Ui_GetColor(1);
        tex = *fn_8006EDD8(*(s32 *)p, 0);
        tw = tex[1];
        th = tex[0];
        Prim2D_Begin();
        Prim2D_BindTexture(*(s32 *)p, 0, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin(lbl_8036B874, lbl_8036B878, lbl_8036B858, lbl_8036B858);
        Prim2D_SetQuadMax(lbl_8036B874 + (f32)tw, lbl_8036B878 + (f32)th, lbl_8036B858 + (f32)tw, lbl_8036B858 + (f32)th);
        Prim2D_SetColor(c4.r, c4.g, c4.b, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B850);
        Prim2D_PrepareTex();
        c5 = *Ui_GetColor(1);
        tex = *fn_8006EDD8(*(s32 *)p, 1);
        tw = tex[1];
        th = tex[0];
        Prim2D_Begin();
        Prim2D_BindTexture(*(s32 *)p, 1, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin(lbl_8036B87C, lbl_8036B880, lbl_8036B858, lbl_8036B858);
        Prim2D_SetQuadMax(lbl_8036B87C + (f32)tw, lbl_8036B880 + (f32)th, lbl_8036B858 + (f32)tw, lbl_8036B858 + (f32)th);
        Prim2D_SetColor(c5.r, c5.g, c5.b, 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();
        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B884);
        Prim2D_PrepareTex();
    }
    if (slot[0] == 1) {
        y = 0x78;
        for (i = 0; i < 4; i++) {
            switch (slot[2 + i]) {
            case 1: label = Msg_Expand(gOptionsStrs + 0x12A9); break;
            case 2: label = Msg_Expand(gOptionsStrs + 0x12B2); break;
            case 3: label = Msg_Expand(gOptionsStrs + 0x12BB); break;
            case 4: label = Msg_Expand(gOptionsStrs + 0x12C4); break;
            default: label = NULL; break;
            }
            if (label != NULL) {
                Prim2D_Begin();
                if (i == *(s16 *)((u8 *)p + 0xC)) {
                    Prim2D_SetAlphaByte(0x80);
                } else {
                    Prim2D_SetAlphaByte(0x40);
                }
                Prim2D_AddZ(lbl_8036B850);
                Prim2D_PrepareTex();
                c6 = *Ui_GetColor(1);
                tex = *fn_8006EDD8(*(s32 *)p, 3);
                tw = tex[1];
                th = tex[0];
                Prim2D_Begin();
                Prim2D_BindTexture(*(s32 *)p, 3, 0x11);
                Prim2D_PrepareTex();
                Prim2D_AddPrim(1);
                Prim2D_SetQuadMin(lbl_8036B888, (f32)y, lbl_8036B858, lbl_8036B858);
                Prim2D_SetQuadMax(lbl_8036B888 + (f32)tw, (f32)y + (f32)th, lbl_8036B858 + (f32)tw, lbl_8036B858 + (f32)th);
                Prim2D_SetColor(c6.r, c6.g, c6.b, 0xFF);
                Prim2D_EmitQuad();
                Prim2D_EndPrim();
                Prim2D_Begin();
                Prim2D_AddZ(lbl_8036B850);
                Prim2D_PrepareTex();
                str = Msg_Expand(label);
                w = Text_MeasureWidth(str, -1, lbl_8036B854);
                fn_8001003C((s16)(0xB0 - (w / 2)), (s16)(y + 7), 1, 1, 0, str, lbl_8036B854, lbl_8036B858);
                Prim2D_Begin();
                Prim2D_SetAlphaByte(0x80);
                Prim2D_AddZ(lbl_8036B854);
                Prim2D_PrepareTex();
                y += 0x30;
            }
        }
    }
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B854);
    Prim2D_PrepareTex();
    fn_80057AE0(*(s32 *)((u8 *)p + 0xDC));
    fn_80057AE0(*(s32 *)((u8 *)p + 0xE0));
    if (*(u8 *)((u8 *)p + 0x28) == 1) {
        rows = *(u8 *)((u8 *)p + 0x29) / 3;
        if ((*(u8 *)((u8 *)p + 0x29) % 3) > 0) {
            rows += 1;
        }
        if (rows > 8) {
            fn_800578A8(*(s32 *)((u8 *)p + 0xE4), 0x22D, 0x98, 0xE0);
            fn_80057860(*(s32 *)((u8 *)p + 0xE4), *(s16 *)((u8 *)p + 0x2C));
            rows = *(u8 *)((u8 *)p + 0x29) / 3;
            if ((*(u8 *)((u8 *)p + 0x29) % 3) > 0) {
                rows += 1;
            }
            fn_80057898(*(s32 *)((u8 *)p + 0xE4), rows);
            fn_80057880(*(s32 *)((u8 *)p + 0xE4), 8);
            fn_800578A0(*(s32 *)((u8 *)p + 0xE4), lbl_8036B8C8);
            fn_80057020(*(s32 *)((u8 *)p + 0xE4));
        }
    }
    Prim2D_Begin();
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();
    (void)c7; (void)c8; (void)f31v; (void)f30v; (void)f29v;
    (void)Prim2D_SetCallback; (void)fn_801F52A8; (void)fn_8015F24C;
    (void)fn_80152010; (void)fn_801E3570; (void)Person_GetByPid;
    (void)Msg_ResolveName; (void)Ui_DrawCaptionBar; (void)fn_8008AB7C;
    (void)Ui_DrawRouteIconEx; (void)__mod2i; (void)fn_8022CB78;
    (void)sin; (void)OSGetTime; (void)__div2i;
    (void)lbl_803683E0; (void)lbl_803683E4; (void)gSystemSave;
}
#pragma use_lmw_stmw reset

void fn_801F52A8(s32 unused, s16 *p) {
    extern void GXSetScissor(s16, s16, s16, s16);
    GXSetScissor(p[0], p[1], p[2], p[3]);
}

extern u8 lbl_8029B0E0[16];
void fn_801F52DC(s32 arg0) {
    void Process_CreateChild(void *, s32);
    extern u8 lbl_8029B0E0[16];
    Process_CreateChild(lbl_8029B0E0, arg0);
}

void fn_801F5308(void* arg0) {
    s32 temp_r3;
    void* temp_r4;

    temp_r3 = *(s32*)((u8*)gPadInput + 4);
    if (temp_r3 & (*(s32*)((u8*)gPadInput + 8) ^ temp_r3) & 0x100) {
        u16* ptr = (u16*)((u8*)&gCardLinkStr + 0x5A);
        Ui_PlaySeCue(ptr, 0x64);
        temp_r4 = *(void**)((u8*)arg0 + 0x50);
        *(u16*)((u8*)temp_r4 + 0x2) = 0xC8;
        Process_ClearFunc(arg0, temp_r4);
    }
}

void fn_801F5374(void* arg0) {
    s32 temp_r3;
    void* temp_r4;

    temp_r3 = *(s32*)((u8*)gPadInput + 4);
    if (temp_r3 & (*(s32*)((u8*)gPadInput + 8) ^ temp_r3) & 0x100) {
        u16* ptr = (u16*)((u8*)&gCardLinkStr + 0x5A);
        Ui_PlaySeCue(ptr, 0x64);
        temp_r4 = *(void**)((u8*)arg0 + 0x50);
        *(u16*)((u8*)temp_r4 + 0x2) = 0xC8;
        Process_ClearFunc(arg0, temp_r4);
    }
}

void fn_801F53E0(void *arg0)
{
    extern u8 gSaveDataBase;

    SaveData_Release(&gSaveDataBase);

    if (Card_GetResult() == 0) {
        MsgBox_Init(
            *(void **)((u8 *)arg0 + 0x50),
            Msg_Expand((u8 *)gCardLinkStr + 0x6A),
            0,
            0,
            0
        );
        return;
    }

    Ui_PlaySeCue((u8 *)gCardLinkStr + 0x77, 0x64);

    MsgBox_Init(
        *(void **)((u8 *)arg0 + 0x50),
        Msg_Expand((u8 *)gCardLinkStr + 0x8A),
        0,
        1,
        0
    );
}

void fn_801F5484(void *arg0)
{
    extern u8 gSaveDataBase;

    if (Card_GetResult() == 0) {
        fn_801DFE60(&gSaveDataBase, arg0);
        return;
    }

    SaveData_Release(&gSaveDataBase);

    Ui_PlaySeCue((u8 *)gCardLinkStr + 0x77, 0x64);

    MsgBox_Init(
        *(void **)((u8 *)arg0 + 0x50),
        Msg_Expand((u8 *)gCardLinkStr + 0x8A),
        0,
        1,
        0
    );

    Process_Goto(arg0, 0x4B);
}

void fn_801F5518(s32 arg0) {
    M2C_UNK fn_801E3118(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK gSaveDataBase;
    fn_801E3118(&gSaveDataBase, arg0, 1);
}

/* After a card-link scan: unlock link bonuses from the found game ID, or show an error. */
void CardLink_ApplyBonus(void *proc) {
    void *Process_Find(void *);
    void Process_Goto(void *, s32);
    void Process_UnlinkByKey(void *);
    s32 Msg_Expand(void *);
    void Ui_PlaySeCue(void *, s32);
    void MsgBox_Init(void *, s32, s32, s32, s32);
    extern u8 gSystemSave[];
    void *cardProc;
    s32 gameId;
    s32 status;

    cardProc = Process_Find(&gCardLinkProc);
    if (cardProc == NULL) {
        status = 0;
    } else {
        status = *(u8 *)((u8 *)cardProc + 0x4C);
    }
    if (status == 4) {
        Ui_PlaySeCue((u8 *)gCardLinkStr + 0x77, 0x64);
        MsgBox_Init(*(void **)((u8 *)proc + 0x50), Msg_Expand((u8 *)gCardLinkStr + 0x9A), 0, 1, 0);
        Process_Goto(proc, 0x59);
    } else {
        cardProc = Process_Find(&gCardLinkProc);
        if (cardProc == NULL) {
            gameId = -1;
        } else {
            gameId = *(s32 *)((u8 *)cardProc + 0x40);
        }
        switch (gameId) {
        case GAME_ID_AFEJ:
            Ui_PlaySeCue((u8 *)gCardLinkStr + 0xAB, 0x64);
            MsgBox_Init(*(void **)((u8 *)proc + 0x50), Msg_Expand((u8 *)gCardLinkStr + 0xBB), 0, 0, 0);
            *(u16 *)(gSystemSave + 0x10) |= LINK_BONUS_FLAG_AC;
            break;
        case GAME_ID_AE7J:
        case GAME_ID_AE7E:
        case GAME_ID_AE7X:
        case GAME_ID_AE7Y:
            Ui_PlaySeCue((u8 *)gCardLinkStr + 0xAB, 0x64);
            MsgBox_Init(*(void **)((u8 *)proc + 0x50), Msg_Expand((u8 *)gCardLinkStr + 0xC8), 0, 0, 0);
            *(u16 *)(gSystemSave + 0x10) |= LINK_BONUS_FLAG_POKEMON;
            break;
        case GAME_ID_BE8J:
        case GAME_ID_BE8E:
        case GAME_ID_BE8P:
            Ui_PlaySeCue((u8 *)gCardLinkStr + 0xAB, 0x64);
            MsgBox_Init(*(void **)((u8 *)proc + 0x50), Msg_Expand((u8 *)gCardLinkStr + 0xD5), 0, 0, 0);
            *(u16 *)(gSystemSave + 0x10) |= LINK_BONUS_FLAG_FE8;
            break;
        case 0:
            Ui_PlaySeCue((u8 *)gCardLinkStr + 0x77, 0x64);
            MsgBox_Init(*(void **)((u8 *)proc + 0x50), Msg_Expand((u8 *)gCardLinkStr + 0xE2), 0, 1, 0);
            Process_Goto(proc, 0x59);
            break;
        default:
            Ui_PlaySeCue((u8 *)gCardLinkStr + 0x77, 0x64);
            MsgBox_Init(*(void **)((u8 *)proc + 0x50), Msg_Expand((u8 *)gCardLinkStr + 0xF1), 0, 1, 0);
            Process_Goto(proc, 0x59);
            break;
        }
    }
    Process_UnlinkByKey(&gCardLinkProc);
}

void fn_801F5830(u8 *self) {
void *Process_Find(void *);
s32 Msg_Expand(void *);
void MsgBox_Init(void *,s32,s32,s32,s32);
void Prim2D_SetTransform(f32,f32,f32,f32);
void Prim2D_SetRect(f32,f32,f32,f32);
void Prim2D_AddZ(f32);
extern f32 lbl_8036B8E0,lbl_8036B8E4,lbl_8036B8E8,lbl_8036B8EC,lbl_8036B8F0,lbl_8036B8F4,lbl_8036B8F8;
extern f64 lbl_8036B900;
u32 progress;
u8 *p;
s32 state;
progress = ((u8 *)Process_Find(&gCardLinkProc))[0x4A];
if (!(*(s16 *)*(void **)(self+0x50)&1))
 MsgBox_Init(*(void **)(self+0x50),Msg_Expand((u8 *)gCardLinkStr+0x104),0,0,0);
if (progress & 0xFF) {
 Prim2D_Begin();
 Prim2D_SetTransform(lbl_8036B8E0,lbl_8036B8E4,lbl_8036B8E8,lbl_8036B8EC);
 Prim2D_SetTex(0,0x10); Prim2D_PrepareTex(); Prim2D_AddPrim(1);
 Prim2D_SetRect(lbl_8036B8E8,lbl_8036B8E8,lbl_8036B8F0,lbl_8036B8F4);
 Prim2D_SetColor(100,100,100,255); Prim2D_EndPrim();
 Prim2D_Begin(); Prim2D_AddZ(lbl_8036B8F8);
 Prim2D_PrepareTex(); Prim2D_AddPrim(1);
 Prim2D_SetRect(lbl_8036B8E8,lbl_8036B8E8,(f32)((progress & 0xFF)*3),lbl_8036B8F4);
 Prim2D_SetColor(0,255,0,255); Prim2D_EndPrim();
} else {
 self[0x54]++;
 if(self[0x54]>240) {
 Ui_PlaySeCue((u8 *)gCardLinkStr+0x77,100);
 MsgBox_Init(*(void **)(self+0x50),Msg_Expand((u8 *)gCardLinkStr+0x9A),0,1,0);
 Process_Goto(self,0x59); Process_UnlinkByKey(&gCardLinkProc);
 }
 return;
}
 p=Process_Find(&gCardLinkProc);
 if(p==0) state=0; else state=p[0x4C];
 if(state==3 || state==4) {
 *(s16 *)(*(u8 **)(self+0x50)+2)=200;
 Process_ClearFunc(self);
 }
}

/* While waiting on a card-link scan: end when status is 2, or cancel on B. */
void CardLink_UpdateScanWait(void *proc) {
    void *Process_Find(void *);
    void Process_ClearFunc(void *);
    void Process_Goto(void *, s32);
    void Ui_PlaySeCue(void *, s32);
    void Process_UnlinkByKey(void *);
    extern void *gPadInput;
    extern u16 gCardLinkStr[18];
    void *cardProc;
    s32 status;
    s32 buttons;
    void *msgBox;

    cardProc = Process_Find(&gCardLinkProc);
    if (cardProc == NULL) {
        status = 0;
    } else {
        status = *(u8 *)((u8 *)cardProc + 0x4C);
    }
    if (status == 2) {
        *(u8 *)((u8 *)proc + 0x54) = 0;
        msgBox = *(void **)((u8 *)proc + 0x50);
        *(s16 *)((u8 *)msgBox + 2) = 0xC8;
        Process_ClearFunc(proc);
        return;
    }
    buttons = *(s32 *)((u8 *)gPadInput + 4);
    if ((buttons & (*(s32 *)((u8 *)gPadInput + 8) ^ buttons) & 0x200) != 0) {
        Ui_PlaySeCue((u8 *)&gCardLinkStr + 0x111, 0x64);
        msgBox = *(void **)((u8 *)proc + 0x50);
        *(s16 *)((u8 *)msgBox + 2) = 0xC8;
        Process_Goto(proc, 0);
        Process_UnlinkByKey(&gCardLinkProc);
    }
}

/* CardLink confirm prompt: A shows the result message and ends; B dismisses and jumps to 0x63. */
void CardLink_UpdateConfirmPrompt(void *proc) {
    s32 Msg_Expand(void *);
    void MsgBox_Init(void *, s32, s32, s32, s32);
    void Ui_PlaySeCue(void *, s32);
    void Process_ClearFunc(void *);
    void Process_Goto(void *, s32);
    extern void *gPadInput;
    extern u16 gCardLinkStr[18];
    s32 held;
    s32 pressed;
    void *msgBox;

    held = *(s32 *)((u8 *)gPadInput + 4);
    pressed = held & (*(s32 *)((u8 *)gPadInput + 8) ^ held);
    if (pressed & 0x100) {
        Ui_PlaySeCue((u8 *)&gCardLinkStr + 0x5A, 0x64);
        MsgBox_Init(*(void **)((u8 *)proc + 0x50), Msg_Expand((u8 *)&gCardLinkStr + 0x121), 0, 0, 0);
        Process_ClearFunc(proc);
        return;
    }
    if (pressed & 0x200) {
        Ui_PlaySeCue((u8 *)&gCardLinkStr + 0x111, 0x64);
        msgBox = *(void **)((u8 *)proc + 0x50);
        *(s16 *)((u8 *)msgBox + 2) = 0xC8;
        Process_Goto(proc, 0x63);
    }
}

void fn_801F5BAC(void) {

}

void fn_801F5BB0(void *arg0) {
    void *tmp = *(void **)((u8 *)arg0 + 0x50);
    if (tmp != NULL) {
        fn_800C4588(tmp);
        *(void **)((u8 *)arg0 + 0x50) = NULL;
    }
    fn_80109020(0);
    Process_UnlinkByKey(&gCardLinkProc);
}

void fn_801F5C04(void *arg0) {
    void *fn_800C4638(s32, void *, s32);
    void Sound_Create(void *, void *);
    void *memset(void *, s32, s32);
    extern u16 gCardLinkStr[18];
    void *temp_r31;

    *(void **)((u8 *)arg0 + 0x50) = fn_800C4638(0x1EA, (u8 *)&gCardLinkStr + 0x12A, 0);
    temp_r31 = *(void **)((u8 *)arg0 + 0x50);
    memset(temp_r31, 0, 0x1EA);
    *((s16 *)temp_r31) = (*(((s16 *)temp_r31) + 1) = 0);
    *(((s16 *)temp_r31) + 0xF) = 0;
    Sound_Create((u8 *)&gCardLinkStr + 0x12B, arg0);
}

void fn_801F5C88(void *arg0) {
    M2C_UNK Prim2D_SetTransform(f32, f32, f32, f32);
    M2C_UNK Prim2D_PrepareTex();
    M2C_UNK Prim2D_Begin();
    M2C_UNK fn_801DCD3C(s32);
    M2C_UNK MsgBox_Update(s32);
    extern f32 lbl_8036B8E8;
extern f32 lbl_8036B8EC;
extern f32 lbl_8036B908;
extern s32 lbl_80368408;
extern s32 lbl_8036840C;
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B8E8, lbl_8036B8E8, lbl_8036B908, lbl_8036B8EC);
    Prim2D_PrepareTex();
    MsgBox_Update(M2C_FIELD(arg0, s32 *, 0x50));
    fn_801DCD3C(M2C_FIELD(arg0, s32 *, 0x50));
}

void fn_801F5CDC(void) {
    Process_Create(&gCardLinkProc, 3);
}

void fn_801F5D08(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x4C) = 4;
}

#pragma global_optimizer off
void fn_801F5D14(void *arg0) {
    s32 fn_802655A8(void *, u8 *);
    void fn_80266840(void *, void *, u8 *);
    void fn_800056CC(void *, ...);
    void fn_8000C070(void *, s32);
    void fn_8000C188(void *);
    extern u16 lbl_80280B58[18];
    s32 ret;

    ret = fn_802655A8(*(void **)((u8 *)arg0 + 0x38), (u8 *)arg0 + 0x4B);
    if (ret == 0) {
        if ((*(u8 *)((u8 *)arg0 + 0x4B) & 0x30) != 0x30) {
            fn_8000C070(arg0, 2);
            return;
        }
    } else if ((u32)ret != 0x38U) {
        return;
    }
    fn_80266840(*(void **)((u8 *)arg0 + 0x38), (u8 *)arg0 + 0x40, (u8 *)arg0 + 0x4B);
    fn_800056CC((u8 *)lbl_80280B58 + 0x136, *(u32 *)((u8 *)arg0 + 0x40));
    if (*(u32 *)((u8 *)arg0 + 0x40) + 0x10000 != 0xFFFF) {
        fn_8000C070(arg0, 3);
        *(u8 *)((u8 *)arg0 + 0x4C) = 3;
    } else {
        fn_8000C188(arg0);
    }
}
#pragma global_optimizer on
void fn_801F5DD0(void *arg0)
{
    u8 *object;
    s32 r;

    object = (u8 *)arg0;

    r = GBAGetStatus(*(u32 *)(object + 0x38), object + 0x4B);
    if (r == 0) {
        r = object[0x4B];
        if ((r & 0x30) != 0x30) {
            fn_8000C070(arg0, 2);
            return;
        }
    }
    if (r & 2) {
        return;
    }

    if (GBAWrite(*(u32 *)(object + 0x38), object + 0x44, object + 0x4B) == 0) {
        r = object[0x4B];
        if ((r & 0x30) != 0x30) {
            fn_8000C070(arg0, 2);
            return;
        }
    }

    fn_8000C188(arg0);
}

#pragma opt_common_subs off
void CardLink_PollSendKey(void *proc) {
    /* Timeout or poll GBA status, write gCardLinkKey, then debug-print it and clear this callback. */
    void Process_Goto(void *, s32);
    s32 GBAGetStatus(void *, void *);
    s32 GBAWrite(void *, void *, void *);
    void DebugPrint(const char *, ...);
    void Process_ClearFunc(void *);
    extern s8 *gCardLinkKey;
    s8 *key;

    *(s16 *)((u8 *)proc + 0x48) = *(s16 *)((u8 *)proc + 0x48) + 1;
    if (*(s16 *)((u8 *)proc + 0x48) > 0xF0) {
        Process_Goto(proc, 2);
        return;
    }
    if (GBAGetStatus(*(void **)((u8 *)proc + 0x38), (u8 *)proc + 0x4B) != 0) {
        return;
    }
    if (*(u8 *)((u8 *)proc + 0x4B) != 0x20) {
        return;
    }
    if (GBAWrite(*(void **)((u8 *)proc + 0x38), gCardLinkKey, (u8 *)proc + 0x4B) != 0) {
        return;
    }
    GBAGetStatus(*(void **)((u8 *)proc + 0x38), (u8 *)proc + 0x4B);
    if (*(u8 *)((u8 *)proc + 0x4B) != 0x30) {
        return;
    }
    key = gCardLinkKey;
    DebugPrint((char *)gCardLinkStr + 0x149, (s32)key[0], (s32)key[1], (s32)key[2], (s32)key[3]);
    Process_ClearFunc(proc);
    *(s16 *)((u8 *)proc + 0x48) = 0;
}
#pragma opt_common_subs on
void fn_801F5F58(void *arg0) {
    extern s8 *gCardLinkKey;
    u32 v;
    s8 *p;

    v = *(u32 *)((u8 *)arg0 + 0x40);
    p = gCardLinkKey;
    if ((v >> 24) == (u32)p[0] && ((v >> 16) & 0xFF) == (u32)p[1] && ((v >> 8) & 0xFF) == (u32)p[2] && (v & 0xFF) == (u32)p[3]) {
        *(u32 *)((u8 *)arg0 + 0x40) = -1;
    } else {
        Process_Goto(arg0, 2);
    }
}

#pragma opt_common_subs off
#pragma global_optimizer off
void fn_801F5FE0(void *arg0) {
    void Process_Goto(void *, s32);
    s32 fn_8026569C(void *, void *);
    s32 GBAGetStatus(void *, void *);
    s32 fn_80266840(void *, void *, void *);
    void DebugPrint(const char *, ...);
    void Process_ClearFunc(void *);
    u8 *self;
    void *v;
    s32 d0, d1, d2, d3;
    char *fmt;

    self = (u8 *)arg0;
    *(s16 *)(self + 0x48) = *(s16 *)(self + 0x48) + 1;
    if (*(s16 *)(self + 0x48) > 0xF0) {
        Process_Goto(self, 2);
        return;
    }
    if (fn_8026569C(*(void **)(self + 0x38), self + 0x4B) != 0) {
        return;
    }
    if (GBAGetStatus(*(void **)(self + 0x38), self + 0x4B) != 0) {
        return;
    }
    if (*(u8 *)(self + 0x4B) != 0x28) {
        return;
    }
    if (fn_80266840(*(void **)(self + 0x38), self + 0x40, self + 0x4B) != 0) {
        return;
    }
    v = *(void **)(self + 0x40);
    d0 = (u32)v >> 24;
    d1 = ((u32)v >> 16) & 0xFF;
    fmt = (char *)gCardLinkStr + 0x164;
    d2 = ((u32)v >> 8) & 0xFF;
    d3 = (u32)v & 0xFF;
    DebugPrint(fmt, d0, d1, d2, d3);
    *(s16 *)(self + 0x48) = 0;
    Process_ClearFunc(self);
}
#pragma global_optimizer on
#pragma opt_common_subs on
void fn_801F60B0(void *arg0) {
    void Process_Goto(void *, s32);
    void Process_ClearFunc(void *);
    s32 fn_8026573C(void *, u8 *);
    void fn_802658B0(void *, void *, s32, void *, void *, void *, void *);
    void fn_801F6164(s32, s32);
    extern void *lbl_803683F4;
    void *tmp;
    s32 ret;

    if (*(u32 *)((u8 *)arg0 + 0x3C) == 0) {
        Process_ClearFunc(arg0);
        *(s16 *)((u8 *)arg0 + 0x48) = 0;
        *(u8 *)((u8 *)arg0 + 0x4A) = 0x64;
        return;
    }
    *(u8 *)((u8 *)arg0 + 0x4C) = 2;
    lbl_803683F4 = arg0;
    tmp = *(void **)((u8 *)arg0 + 0x38);
    fn_802658B0(tmp, tmp, 1,
                *(void **)((u8 *)arg0 + 0x30),
                *(void **)((u8 *)arg0 + 0x34),
                (u8 *)arg0 + 0x4B,
                &fn_801F6164);
    ret = fn_8026573C(*(void **)((u8 *)arg0 + 0x38), (u8 *)arg0 + 0x4A);
    *(s16 *)((u8 *)arg0 + 0x48) = (s16)(*(s16 *)((u8 *)arg0 + 0x48) + 1);
    if (*(s16 *)((u8 *)arg0 + 0x48) > 0xF0 && ret == 0) {
        Process_Goto(arg0, 1);
    }
}

void fn_801F6164(s32 unused, s32 arg1) {
    extern void *lbl_803683F4;
    M2C_FIELD(lbl_803683F4, s32 *, 0x3C) = arg1;
}

#pragma global_optimizer off
void fn_801F6170(void *arg0)
{
    extern u32 lbl_80280B48[4];
    u32 fn_8023C410(u32);
    void Process_ClearFunc(void *);
    u32 local[4];
    u32 tmp[4];
    u32 *const src = lbl_80280B48;
    s32 i;
    u32 *p;

    *(u8 *)((u8 *)arg0 + 0x4C) = 1;

    p = local;
    i = 0;
    while (i < 4) {
        local[0] = src[0];
        local[1] = src[1];
        local[2] = src[2];
        local[3] = src[3];
        if (fn_8023C410(*p) == 0x40000) {
            tmp[0] = lbl_80280B48[0];
            tmp[1] = lbl_80280B48[1];
            tmp[2] = lbl_80280B48[2];
            tmp[3] = lbl_80280B48[3];
            *(u32 *)((u8 *)arg0 + 0x38) = tmp[i];
            *(s32 *)((u8 *)arg0 + 0x3C) = 2;
            *(s16 *)((u8 *)arg0 + 0x48) = 0;
            Process_ClearFunc(arg0);
            return;
        }
        i++;
        p++;
    }
}
#pragma global_optimizer reset
void fn_801F6260(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x4C) = 0;
    fn_8005C7C8((u8 *)&gCardLinkStr + 0x18C);
}

#pragma opt_common_subs off
void fn_801F6294(void *arg0) {
    void *FileCache_Load(void *);
    s32 FileCache_GetSize(void *);
    void FileCache_OrFlags(void *, s32);
    void *fn_8020F404(void);
    void fn_80265484(void);
    extern u16 gCardLinkStr[18];
    extern u8 lbl_803683F8;
    extern u8 lbl_803683F9;
    extern s8 *gCardLinkKey;
    s32 size;
    u8 *key;
    u8 *buf;
    s32 i;
    s32 sum;
    u8 *p;
    s32 n;

    if ((s8)lbl_803683F9 == 0) {
        lbl_803683F8 = 0;
        lbl_803683F9 = 1;
    }
    if (lbl_803683F8 == 0) {
        fn_80265484();
        lbl_803683F8 = 1;
    }
    *(void **)((u8 *)arg0 + 0x30) = FileCache_Load((u8 *)&gCardLinkStr + 0x18c);
    size = FileCache_GetSize((u8 *)&gCardLinkStr + 0x18c);
    if (size < 0xE400) {
        size = 0xE400;
    }
    *(s32 *)((u8 *)arg0 + 0x34) = size;
    *(s16 *)((u8 *)arg0 + 0x48) = 0;
    *(u8 *)((u8 *)arg0 + 0x4a) = 0;
    *(u8 *)((u8 *)arg0 + 0x4c) = 0;
    FileCache_OrFlags((u8 *)&gCardLinkStr + 0x18c, 4);
    key = fn_8020F404();
    gCardLinkKey = (s8 *)key;
    i = 0xa0;
    sum = 0xe7;
    buf = *(u8 **)((u8 *)arg0 + 0x30);
    buf[0xac] = key[0];
    buf[0xad] = key[1];
    buf[0xae] = key[2];
    buf[0xaf] = key[3];
    if (i < 0xbd) {
        i = 0xbc;
        p = buf + 0xbc;
        sum = (((((((((((((((((((((((((((0xe7 - buf[0xa0]) - buf[0xa1]) - buf[0xa2]) - buf[0xa3]) - buf[0xa4]) - buf[0xa5]) - buf[0xa6]) - buf[0xa7]) - buf[0xa8]) - buf[0xa9]) - buf[0xaa]) - buf[0xab]) - buf[0xac]) - buf[0xad]) - buf[0xae]) - buf[0xaf]) - buf[0xb0]) - buf[0xb1]) - buf[0xb2]) - buf[0xb3]) - buf[0xb4]) - buf[0xb5]) - buf[0xb6]) - buf[0xb7]) - buf[0xb8]) - buf[0xb9]) - buf[0xba]) - buf[0xbb];
        n = 0xbd - i;
        if (i < 0xbd) {
            do {
                sum -= *p;
                i += 1;
                p += 1;
            } while (--n);
        }
    }
    buf[i] = (u8)sum;
}
#pragma opt_common_subs reset
extern u8 lbl_8029B198[16];
void fn_801F649C(s32 arg0) {
    void Process_CreateChild(void *, s32);
    extern u8 lbl_8029B198[16];
    Process_CreateChild(lbl_8029B198, arg0);
}

void fn_801F64C8(void) {
    extern u16 lbl_80280CF0[];
    fn_80109020((u8 *)lbl_80280CF0 + 0x20);
}

void fn_801F64F4(s32 arg0) {
    void Process_ClearFunc(s32);
    void fn_801480D8(s32);
    extern void *gPadInput;
    s32 temp_r5;

    temp_r5 = M2C_FIELD(gPadInput, s32 *, 4);
    if (temp_r5 & (M2C_FIELD(gPadInput, s32 *, 8) ^ temp_r5) & 0x300) {
        Process_ClearFunc(arg0);
        fn_801480D8(0x1388);
    }
}

void fn_801F6538(void) {
    extern u16 lbl_80280CF0[];
    fn_80147188(0xFA);
    Fx_StartSlot(0, (u8 *)lbl_80280CF0 + 0x33, 0x64, 1);
    Sound_Create((u8 *)lbl_80280CF0 + 0x20, 0);
    fn_800A84A0();
    fn_8018DC98();
}

void fn_801F6594(void) {
    void fn_80108FA8(void *);
    void fn_801480D8(s32);
    extern u16 lbl_80280CF0[];
    fn_80108FA8(lbl_80280CF0 + 0x10);
    fn_801480D8(0x1388);
}

void fn_801F65C8(s32 arg0) {
    void *Process_CreateChild(void *, s32);
    s32 fn_800C4638(s32, void *, s32);
    extern u8 lbl_8029B27C[];
    extern u8 gBattlePreviewStrings[];
    void *temp_r31;

    temp_r31 = Process_CreateChild(lbl_8029B27C, arg0);
    M2C_FIELD(temp_r31, s32 *, 0x30) = fn_800C4638(0x18, gBattlePreviewStrings + 0x6A, 0);
}

void fn_801F661C(s32 arg0) {
    void *Process_CreateChild(void *, s32);
    s32 fn_800C4638(s32, void *, s32);
    extern u8 lbl_8029B1F8[];
    extern u8 gBattlePreviewStrings[];
    void *temp_r31;

    temp_r31 = Process_CreateChild(lbl_8029B1F8, arg0);
    M2C_FIELD(temp_r31, s32 *, 0x30) = fn_800C4638(0x210, gBattlePreviewStrings + 0x6A, 0);
}

void fn_801F6670(void *arg0)
{
    void fn_80161F7C(void);
    void Process_Unlink(void *);
    void FileCache_ReleaseSlot(void *);
    void fn_800C4588(void *);
    struct {
        u8 pad[0x10];
        void *unk10;
    } *work = *(void **)((u8 *)arg0 + 0x30);

    fn_80161F7C();
    if (*(void **)((u8 *)arg0 + 0x34) != NULL) {
        Process_Unlink(*(void **)((u8 *)arg0 + 0x34));
    }
    if (work->unk10 != NULL) {
        FileCache_ReleaseSlot(&work->unk10);
    }
    fn_800C4588(work);
}

extern s32 lbl_80368400;
extern u8 lbl_80368404;
void fn_801F66D4(void *arg0) {
    void Process_ClearFunc(void *);
    s32 held;
    s32 pressed;
    void *obj;
    s32 state;

    held = M2C_FIELD(gPadInput, s32 *, 4);
    pressed = held & (M2C_FIELD(gPadInput, s32 *, 8) ^ held);
    obj = M2C_FIELD(arg0, void **, 0x30);
    if ((s8)lbl_80368404 == 0) {
        lbl_80368400 = 0;
        lbl_80368404 = 1;
    }
    state = M2C_FIELD(obj, s32 *, 0);
    switch (state) {
    case 0:
        M2C_FIELD(obj, s32 *, 0) = 1;
        M2C_FIELD(obj, s32 *, 4) = 0;
        lbl_80368400 = 0;
        break;
    case 1:
        if ((pressed & 0x100) || (pressed & 0x200)) {
            Process_ClearFunc(arg0);
        }
        break;
    }
}

/* Draw the battle preview overlay: banner quads, title, and detail panel. */
void BattlePreview_Draw(void *proc) {
    void Prim2D_EmitQuad(void);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_BindTexture(s32, s32, s32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void *Msg_Expand(void *);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, ...);
    s32 Text_MeasureWidth(void *, s32, f32);
    void BattlePreview_DrawDetails(void *, f32, f32);
    extern u8 gBattlePreviewStrings[];
    void *title;
    void *work;
    f32 titleW;

    work = *(void **)((u8 *)proc + 0x30);
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B910, lbl_8036B910, lbl_8036B914, lbl_8036B918);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B91C);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_BindTexture(*(s32 *)((u8 *)work + 0x10), 1, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B920, lbl_8036B924, lbl_8036B910, lbl_8036B910);
    Prim2D_SetQuadMax(lbl_8036B928, lbl_8036B92C, lbl_8036B920, lbl_8036B930);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B910, lbl_8036B924, lbl_8036B920, lbl_8036B910);
    Prim2D_SetQuadMax(lbl_8036B920, lbl_8036B92C, lbl_8036B910, lbl_8036B930);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B91C);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();
    title = Msg_Expand(gBattlePreviewStrings + 0x6B);
    titleW = (f32)Text_MeasureWidth(title, -1, lbl_8036B934);
    fn_8001003C((s32)(lbl_8036B920 - lbl_8036B938 * titleW), 0x1E, 2, 0, 0, title, lbl_8036B934, lbl_8036B910);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B93C);
    Prim2D_PrepareTex();
    BattlePreview_DrawDetails(work, lbl_8036B940, lbl_8036B944);
}

void BattlePreview_DrawDetails(void *arg0, f32 farg0, f32 farg1) {
    void fn_800066B4(s32, s32, u32 *, s32 *, s32 *);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetColor(u8, u8, u8, s32);
    void Prim2D_SetQuadMax(f32, f32, f32, f32);
    void Prim2D_SetQuadMin(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_AddZ(f32);
    void Prim2D_BindTexture(s32, s32, s32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void *Msg_Expand(void *);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, ...);
    s32 Text_MeasureWidth(void *, s32, f32);
    void **fn_8006EDD8(s32, s32);
    u8 fn_8014BC10(void *);
    u8 fn_8014BEE0(void *);
    u8 fn_8014C078(void *);
    u8 fn_8014C12C(void *);
    void fn_8015A2D8(s32, s32, s32, s32, s32, s32);
    s32 *Ui_GetColor(s32);
    extern u8 gBattlePreviewStrings[];
    extern u8 gBattleState[];
    extern f32 lbl_8036B910;
    extern f32 lbl_8036B918;
    extern f32 lbl_8036B91C;
    extern f32 lbl_8036B934;
    extern f64 lbl_8036B948;
    extern f32 lbl_8036B950;
    extern f32 lbl_8036B954;
    extern f32 lbl_8036B958;
    extern f32 lbl_8036B95C;
    extern f32 lbl_8036B960;
    extern f32 lbl_8036B964;
    extern f32 lbl_8036B968;
    extern f32 lbl_8036B96C;
    extern f32 lbl_8036B970;
    extern f32 lbl_8036B974;
    extern f32 lbl_8036B978;
    extern f32 lbl_8036B97C;
    extern f32 lbl_8036B980;
    extern f32 lbl_8036B984;
    extern f32 lbl_8036B988;
    extern f32 lbl_8036B98C;
    extern f32 lbl_8036B990;
    extern f32 lbl_8036B994;
    extern f32 lbl_8036B998;
    extern f64 lbl_8036B9A0;

    u32 sp1C;
    s32 sp18;
    s32 sp14;
    u8 sp10[4];
    s32 spC;
    s32 sp8;
    void *self = arg0;
    f32 fx = farg0;
    f32 fy = farg1;
    u16 h;
    u16 w;
    void *str;
    u8 val;
    f32 f31;
    f32 f28;
    f32 f27;
    s32 tw;
    void *label;

    fn_800066B4(*(s32 *)((u8 *)self + 8), *(s32 *)((u8 *)self + 0xC), &sp1C, &sp18, &sp14);
    if (sp1C > 0x63U) {
        sp1C = 0x63U;
        sp18 = 0x3B;
        sp14 = 0x3B;
    }
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B91C);
    Prim2D_PrepareTex();
    *(s32 *)sp10 = *Ui_GetColor(1);
    {
        void **p = fn_8006EDD8(*(s32 *)((u8 *)self + 0x10), 0);
        void *tex = *p;
        h = *(u16 *)((u8 *)tex + 2);
        w = *(u16 *)tex;
    }
    Prim2D_Begin();
    Prim2D_BindTexture(*(s32 *)((u8 *)self + 0x10), 0, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(fx, fy, lbl_8036B910, lbl_8036B910);
    Prim2D_SetQuadMax(fx + (f32)h, fy + (f32)w, (f32)h, (f32)w);
    Prim2D_SetColor(sp10[0], sp10[1], sp10[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B91C);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();

    str = Msg_Expand(gBattlePreviewStrings + 0x7D);
    fn_8001003C((s32)(lbl_8036B950 + fx), (s32)(lbl_8036B954 + fy), 1, 1, 0, str, lbl_8036B918, lbl_8036B910);

    fn_8001003C((s32)(lbl_8036B958 + fx), (s32)(lbl_8036B95C + fy), 6, 1, 0, gBattlePreviewStrings + 0x93,
                *(s16 *)(gBattleState + 0x12), lbl_8036B934, lbl_8036B910);

    f31 = lbl_8036B960 + fx;
    str = Msg_Expand(gBattlePreviewStrings + 0xB4);
    sp8 = sp18;
    spC = sp14;
    fn_8001003C((s32)f31, (s32)(lbl_8036B964 + fy), 1, 1, 0, gBattlePreviewStrings + 0x96, str, (s32)sp1C,
                lbl_8036B918, lbl_8036B910);

    f28 = lbl_8036B968 + fy;
    fn_8001003C((s32)f31, (s32)f28, 1, 1, 0, Msg_Expand(gBattlePreviewStrings + 0xC9), lbl_8036B918, lbl_8036B910);

    val = fn_8014C12C(gBattleState);
    Msg_Expand(gBattlePreviewStrings + 0xC9);
    tw = Text_MeasureWidth((void *)0, -1, lbl_8036B918);
    f27 = lbl_8036B970 + fy;
    fn_8001003C((s32)(lbl_8036B96C + (f31 + (f32)tw)), (s32)f27, 6, 1, 0, gBattlePreviewStrings + 0xDF, val,
                lbl_8036B934, lbl_8036B910);

    f28 = lbl_8036B974 + fx;
    fn_8001003C((s32)f28, (s32)(lbl_8036B968 + fy), 1, 1, 0, Msg_Expand(gBattlePreviewStrings + 0xE2), lbl_8036B918,
                lbl_8036B910);

    val = fn_8014C078(gBattleState);
    Msg_Expand(gBattlePreviewStrings + 0xE2);
    tw = Text_MeasureWidth((void *)0, -1, lbl_8036B918);
    fn_8001003C((s32)(lbl_8036B96C + (f28 + (f32)tw)), (s32)f27, 6, 1, 0, gBattlePreviewStrings + 0xDF, val,
                lbl_8036B934, lbl_8036B910);

    fn_8001003C((s32)f31, (s32)(lbl_8036B978 + fy), 1, 1, 0, Msg_Expand(gBattlePreviewStrings + 0xF9), lbl_8036B918,
                lbl_8036B910);

    val = fn_8014BEE0(gBattleState);
    Msg_Expand(gBattlePreviewStrings + 0xF9);
    tw = Text_MeasureWidth((void *)0, -1, lbl_8036B918);
    fn_8001003C((s32)(lbl_8036B96C + (f31 + (f32)tw)), (s32)(lbl_8036B97C + fy), 6, 1, 0,
                gBattlePreviewStrings + 0xDF, val, lbl_8036B934, lbl_8036B910);

    f28 = lbl_8036B980 + fx;
    f27 = lbl_8036B984 + fy;
    fn_8001003C((s32)f28, (s32)f27, 0x19, 1, 0, Msg_Expand(gBattlePreviewStrings + 0x10E), lbl_8036B934,
                lbl_8036B910);

    val = fn_8014BC10(gBattleState);
    Msg_Expand(gBattlePreviewStrings + 0x10E);
    tw = Text_MeasureWidth((void *)0, -1, lbl_8036B918);
    fn_8001003C((s32)(lbl_8036B96C + (f28 + (f32)tw)), (s32)f27, 6, 1, 0, gBattlePreviewStrings + 0xDF, val,
                lbl_8036B934, lbl_8036B910);

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B988);
    Prim2D_PrepareTex();
    fn_8015A2D8((s32)(lbl_8036B968 + fx), (s32)(fy - lbl_8036B98C), 0x10A, 0x30, 0xFF, 0x10);
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B91C);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();

    switch (gBattleState[0x10]) {
    case 0x5B:
        label = Msg_Expand(gBattlePreviewStrings + 0x125);
        break;
    case 0x5C:
        label = Msg_Expand(gBattlePreviewStrings + 0x132);
        break;
    case 0x5D:
        label = Msg_Expand(gBattlePreviewStrings + 0x13F);
        break;
    case 0x5E:
        label = Msg_Expand(gBattlePreviewStrings + 0x14C);
        break;
    case 0x5F:
        label = Msg_Expand(gBattlePreviewStrings + 0x159);
        break;
    case 0x60:
        label = Msg_Expand(gBattlePreviewStrings + 0x166);
        break;
    default:
        label = 0;
        break;
    }
    tw = Text_MeasureWidth(label, -1, lbl_8036B918);
    {
        f32 x = lbl_8036B990 + fx;
        x = x - (f32)(((s32)tw + ((u32)(s32)tw >> 31)) >> 1);
        fn_8001003C((s32)x, (s32)(fy - lbl_8036B994), 1, 1, 0, label, lbl_8036B918, lbl_8036B910);
    }
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B998);
    Prim2D_PrepareTex();
}

void fn_801F7194(void *arg0) {
    s32 Process_AttachFunc(void (*)(void *), void *);
    s32 fn_80161FB8(void);
    void fn_80162054(void);
    void Process_ClearFunc(void *);
    void BattlePreview_Draw(void *);
    s32 FileCache_GetFlags(void *);
    extern u8 gBattlePreviewStrings[];
    if ((FileCache_GetFlags(gBattlePreviewStrings + 0x173) & 0x2000) && (fn_80161FB8() != 0)) {
        fn_80162054();
        M2C_FIELD(arg0, s32 *, 0x34) = Process_AttachFunc(BattlePreview_Draw, arg0);
        Process_ClearFunc(arg0);
    }
}

void fn_801F7200(void *arg0) {
    extern u8 gBattleState[];
    extern u8 gBattlePreviewStrings[];
    void fn_80147188(s32);
    void fn_8006EEFC(void *, void *);
    void fn_80162018(void);
    u32 *obj;
    u64 v;

    obj = *(u32 **)((u8 *)arg0 + 0x30);
    fn_80147188(0x3E8);
    obj[0] = 0;
    obj[1] = 0;
    v = *(u64 *)(gBattleState + 0x60);
    obj[3] = (u32)v;
    obj[2] = (u32)(v >> 32);
    fn_8006EEFC(obj + 4, gBattlePreviewStrings + 0x173);
    fn_80162018();
}

void fn_801F726C(void *arg0) {
    s32 temp_r31;

    temp_r31 = M2C_FIELD(arg0, s32 *, 0x30);
    FileCache_ReleaseSlot(temp_r31);
    fn_800C4588(temp_r31);
}

void fn_801F72A4(void *arg0) {
    void Ui_PlaySeCue(void *, s32);
    void Process_Goto(void *, s32);
    void Game_SetState(s32);
    void fn_80006160(s32);
    extern char gBattlePreviewStrings[];
    u8 *p = *(u8 **)((u8 *)arg0 + 0x30);
    u32 held = *(u32 *)((u8 *)gPadInput + 4);
    u32 pressed = held & (*(u32 *)((u8 *)gPadInput + 8) ^ held);
    u32 repeat = *(u32 *)((u8 *)gPadInput + 12);
    s32 previous = *(s16 *)(p + 0x18);

    if (pressed & 0x100) {
        if (previous == 0) {
            Ui_PlaySeCue(gBattlePreviewStrings + 0x186, 100);
            fn_80006160(p[0xC8 + *(s16 *)(p + 6)] + 0x5B);
            Game_SetState(0x1F);
            Process_Goto(arg0, 2);
        } else {
            Ui_PlaySeCue(gBattlePreviewStrings + 0x196, 100);
            Process_Goto(arg0, 0);
        }
    } else if (pressed & 0x200) {
        Ui_PlaySeCue(gBattlePreviewStrings + 0x1A6, 100);
        Process_Goto(arg0, 0);
    } else {
        if (repeat & 0x01000001) {
            *(s16 *)(p + 0x18) = 0;
            *(s16 *)(p + 0x1E) = 4;
            *(s16 *)(p + 0x20) = *(s16 *)(p + 0x1A);
            *(s16 *)(p + 0x22) = *(s16 *)(p + 0x1C);
            *(s16 *)(p + 0x24) = 0x1BD;
            *(s16 *)(p + 0x26) = 0x3D;
        }
        if (repeat & 0x02000002) {
            *(s16 *)(p + 0x18) = 1;
            *(s16 *)(p + 0x1E) = 4;
            *(s16 *)(p + 0x20) = *(s16 *)(p + 0x1A);
            *(s16 *)(p + 0x22) = *(s16 *)(p + 0x1C);
            *(s16 *)(p + 0x24) = 0x1FE;
            *(s16 *)(p + 0x26) = 0x3D;
        }
        if (previous != *(s16 *)(p + 0x18)) {
            Ui_PlaySeCue(gBattlePreviewStrings + 0x1B6, 100);
        }
    }
}

void fn_801F7434(void *arg0) {
    void Ui_PlaySeCue(void *, s32);
    char *Msg_Expand(char *);
    void *memcpy(void *, const void *, unsigned long);
    char *strcpy(char *, const char *);
    char *strcat(char *, const char *);
    extern char gBattlePreviewStrings[];
    u8 *p = *(u8 **)((u8 *)arg0 + 0x30);
    char *src;
    char *seg;
    s32 len;
    s32 lines;
    u8 *dst;
    s8 c;

    p[0x88] = 1;
    p[5] = 0;
    p[0x16] = 1;
    p[0x17] = 1;
    *(s16 *)(p + 0x18) = 0;
    *(s16 *)(p + 0x1A) = 0x1C2;
    *(s16 *)(p + 0x1C) = 0x3D;
    p[0xCE] = 0;
    p[0x10E] = 0;
    p[0x14E] = 0;
    p[0x18E] = 0;
    p[0x1CE] = 0;

    src = Msg_Expand(*(char **)(p + (*(s16 *)(p + 6) << 2) + 0xB0));
    len = 0;
    lines = 0;
    dst = p;
    seg = src;

    for (;;) {
        c = *src;
        if (c == 0 || c == '\n') {
            if (len > 0) {
                memcpy(dst + 0xCE, seg, len);
            }
            *(dst + len + 0xCE) = 0;
            len = 0;
            dst += 0x40;
            lines++;
            if ((s8)*src == 0) {
                break;
            }
            src++;
            seg = src;
        } else {
            src++;
            len++;
        }
    }

    p[0x95] = (u8)lines;
    Ui_PlaySeCue(gBattlePreviewStrings + 0x1D2, 100);
    strcpy((char *)(p + 0x28), gBattlePreviewStrings + 0x1EB);
    strcat((char *)(p + 0x28), Msg_Expand(gBattlePreviewStrings + 0x1F1));
    strcat((char *)(p + 0x28), gBattlePreviewStrings + 0x1FC);
    strcat((char *)(p + 0x28), Msg_Expand(gBattlePreviewStrings + 0x204));
    strcat((char *)(p + 0x28), gBattlePreviewStrings + 0x20F);
    strcat((char *)(p + 0x28), Msg_Expand(gBattlePreviewStrings + 0x217));
}

void fn_801F75D4(void *arg0) {
    void Ui_PlaySeCue(void *,s32);
    void Process_Goto(void *,s32);
    void Game_SetState(s32);
    extern char gBattlePreviewStrings[];
    u8 *p=*(u8**)((u8*)arg0+0x30);
    u32 held=*(u32*)((u8*)gPadInput+4);
    u32 pressed=held & (*(u32*)((u8*)gPadInput+8)^held);
    u32 repeat=*(u32*)((u8*)gPadInput+12);
    s16 previous=*(s16*)(p+6);
    s32 selected=*(s16*)(p+6);
    if(pressed&0x100) {
        Ui_PlaySeCue(gBattlePreviewStrings+0x196,100);
        Process_Goto(arg0,1);
    } else if(pressed&0x200) {
        Ui_PlaySeCue(gBattlePreviewStrings+0x1A6,100);
        Game_SetState(6);
        Process_Goto(arg0,2);
    } else {
        if(repeat&0x08000008) {
            *(s16*)(p+6)=previous-1;
            if(*(s16*)(p+6)<0) *(s16*)(p+6)=0;
        }
        if(repeat&0x04000004) {
            *(s16*)(p+6)+=1;
            if(*(s16*)(p+6)>p[0x94]-1) *(s16*)(p+6)=p[0x94]-1;
        }
        selected=*(s16*)(p+6);
        if(previous!=selected) {
            *(s16*)(p+0xC)=4;
            *(s16*)(p+0xE)=*(s16*)(p+8);
            *(s16*)(p+0x10)=*(s16*)(p+0xA);
            *(s16*)(p+0x12)=0x31;
            *(s16*)(p+0x14)=selected*24+0x78;
            Ui_PlaySeCue(gBattlePreviewStrings+0x222,100);
            p[0x8A]=p[0x89];
            p[0x89]=p[0xC8+*(s16*)(p+6)];
            *(s16*)(p+0x8C)=0;
        }
    }
}

/* Layout the battle-preview caption widget and build its text from message fragments. */
void BattlePreview_InitCaption(void *proc)
{
    extern u8 gBattlePreviewStrings[];
    extern void strcpy(s32 arg0, s32 arg1);
    extern void *Msg_Expand(const char *arg0);
    extern void strcat(void *arg0, const char *arg1);

    u8 *widget;
    u8 *strings;

    widget = *(u8 **)((u8 *)proc + 0x30);
    strings = gBattlePreviewStrings;

    widget[0x88] = 0;
    widget[0x4] = 1;
    widget[0x5] = 1;
    *(u16 *)(widget + 0x8) = 0x31;
    *(u16 *)(widget + 0xA) =
        (u16)(*(s16 *)(widget + 0x6) * 0x18 + 0x78);
    widget[0x16] = 0;

    strcpy((s32)(widget + 0x28), (s32)(strings + 0x23E));

    strcat(widget + 0x28, Msg_Expand((const char *)(strings + 0x1F1)));
    strcat(widget + 0x28, (const char *)(strings + 0x1FC));

    strcat(widget + 0x28, Msg_Expand((const char *)(strings + 0x204)));
    strcat(widget + 0x28, (const char *)(strings + 0x20F));

    strcat(widget + 0x28, Msg_Expand((const char *)(strings + 0x244)));
}

void fn_801F7838(s32 arg0) {
    extern u8 gBattlePreviewStrings[];
    s32 FileCache_GetFlags(void *);
    void Process_ClearFunc(s32);

    if (FileCache_GetFlags(gBattlePreviewStrings + 0x24F) & 0x2000) {
        Process_ClearFunc(arg0);
    }
}

void fn_801F7880(void *arg0) {
extern u8 gSystemSave[];
extern char gBattlePreviewStrings[];
void fn_8006EEFC(void *,void *);
s32 n;
struct Panel { u8 pad0[6]; s16 cursor; u8 pad8[0x81]; s8 current,previous; u8 pad8B; u16 value; u8 pad8E[6]; u8 count; u8 pad95[3]; char *names[6]; char *descs[6]; u8 ids[6]; };
struct Panel *p;
p=*(struct Panel **)((u8 *)arg0+0x30);
memset(p,0,0x210);
p->value=0xFF;
n=0;
if (*(u16 *)(gSystemSave+0x10)&1) {
p->names[0]=gBattlePreviewStrings+0x125;
p->descs[0]=gBattlePreviewStrings+0x264;
p->ids[0]=0;n=1;
}
if (*(u16 *)(gSystemSave+0x10)&2) {
p->names[n]=gBattlePreviewStrings+306;
p->descs[n]=gBattlePreviewStrings+628;
p->ids[n]=1;
n++;
}
if (*(u16 *)(gSystemSave+0x10)&4) {
p->names[n]=gBattlePreviewStrings+319;
p->descs[n]=gBattlePreviewStrings+644;
p->ids[n]=2;
n++;
}
if ((*(u16 *)(gSystemSave+0x10)&0x10)||(*(u16 *)(gSystemSave+0x10)&0x20)) {
p->names[n]=gBattlePreviewStrings+332;
p->descs[n]=gBattlePreviewStrings+660;
p->ids[n]=3;
n++;
}
if (*(u16 *)(gSystemSave+0x10)&16) {
p->names[n]=gBattlePreviewStrings+345;
p->descs[n]=gBattlePreviewStrings+676;
p->ids[n]=4;
n++;
}
if (*(u16 *)(gSystemSave+0x10)&32) {
p->names[n]=gBattlePreviewStrings+358;
p->descs[n]=gBattlePreviewStrings+692;
p->ids[n]=5;
n++;
}
p->count=n;p->previous=-1;
p->current=p->ids[p->cursor];
fn_8006EEFC(p,gBattlePreviewStrings+0x24F);
}

void fn_801F7A60(void *arg0) {
    f32 Math_Ease(s32, f32, f32, f32, f32);
    void Prim2D_EmitQuad(void);
    void Prim2D_SetAlpha(s32);
    void Prim2D_SetColor(u8, u8, u8, s32);
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
    void *Msg_Expand(void *);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, ...);
    s32 Text_MeasureWidth(void *, s32, f32);
    s32 fn_80019F04(s32);
    void **fn_8006EDD8(void *, s32);
    void Ui_DrawCaptionBar(void *, s32);
    void fn_8007D024(s32, s32, f32, f32, f32, f32);
    void fn_8008AB7C(s32, s32, s32, s32, s32, s32, s32);
    void Ui_DrawRouteIconEx(s16, s16, s32);
    void *fn_8016614C(s32, s32);
    s32 *Ui_GetColor(s32);
    extern u8 gBattlePreviewStrings[];
    extern f32 lbl_8036B910;
    extern f32 lbl_8036B918;
    extern f32 lbl_8036B91C;
    extern f32 lbl_8036B920;
    extern f32 lbl_8036B924;
    extern f32 lbl_8036B938;
    extern f32 lbl_8036B93C;
    extern f32 lbl_8036B95C;
    extern f32 lbl_8036B988;
    extern f64 lbl_8036B9A0;
    extern f32 lbl_8036B9A8;
    extern f32 lbl_8036B9AC;
    extern f32 lbl_8036B9B0;
    extern f32 lbl_8036B9B4;
    extern f32 lbl_8036B9B8;
    extern f32 lbl_8036B9BC;
    extern f32 lbl_8036B9C0;
    extern f32 lbl_8036B9C4;
    extern f32 lbl_8036B9C8;
    extern f32 lbl_8036B9CC;
    extern f32 lbl_8036B9D0;
    extern f32 lbl_8036B9D4;
    extern f32 lbl_8036B9D8;
    extern f32 lbl_8036B9DC;
    extern f32 lbl_8036B9E0;
    extern f32 lbl_8036B9E4;
    extern f32 lbl_8036B9E8;
    extern f32 lbl_8036B9EC;
    extern f32 lbl_8036B9F0;
    extern f32 lbl_8036B9F4;
    extern f32 lbl_8036B9F8;
    extern f32 lbl_8036B9FC;
    extern f64 lbl_8036B948;

    u8 c0[4], c1[4], c2[4], c3[4], c4[4];
    f32 f0, f1, f2;
    f32 fx;
    s32 i;
    s32 t;
    s32 tw;
    s32 item;
    s32 flag;
    u16 h, w;
    s16 y;
    s16 maxw;
    void **pp;
    void *p;
    void *str;
    void *self;
    u8 *slot;

    self = *(void **)((u8 *)arg0 + 0x30);
    if ((s8)*(u8 *)((u8 *)self + 0x88) == 0) {
        *(s16 *)((u8 *)self + 0x8E) = (s16)(*(s16 *)((u8 *)self + 0x8E) - 0x1E);
        if (*(s16 *)((u8 *)self + 0x8E) < 0) {
            *(s16 *)((u8 *)self + 0x8E) = 0;
        }
        f2 = *(f32 *)((u8 *)self + 0x90);
        f1 = lbl_8036B9A8;
        f0 = lbl_8036B910;
        f1 = f2 - f1;
        *(f32 *)((u8 *)self + 0x90) = f1;
        f1 = *(f32 *)((u8 *)self + 0x90);
        if (f1 < f0) {
            *(f32 *)((u8 *)self + 0x90) = f0;
        }
    }
    flag = *(u8 *)((u8 *)self + 0x88);
    if (flag == 1) {
        *(s16 *)((u8 *)self + 0x8E) = (s16)(*(s16 *)((u8 *)self + 0x8E) + 0x1E);
        if (*(s16 *)((u8 *)self + 0x8E) > 0x80) {
            *(s16 *)((u8 *)self + 0x8E) = 0x80;
        }
        f2 = *(f32 *)((u8 *)self + 0x90);
        f1 = lbl_8036B9A8;
        f0 = lbl_8036B918;
        f1 = f2 + f1;
        *(f32 *)((u8 *)self + 0x90) = f1;
        f1 = *(f32 *)((u8 *)self + 0x90);
        if (f1 > f0) {
            *(f32 *)((u8 *)self + 0x90) = f0;
        }
    }
    *(s16 *)((u8 *)self + 0x8C) = (s16)(*(s16 *)((u8 *)self + 0x8C) + 0x14);
    if (*(s16 *)((u8 *)self + 0x8C) > 0xFF) {
        *(s16 *)((u8 *)self + 0x8C) = 0xFF;
    }

    i = 0;
    slot = (u8 *)self;
    do {
        if (*(s16 *)(slot + 0xC) > 0) {
            *(s16 *)(slot + 0xC) = (s16)(*(s16 *)(slot + 0xC) - 1);
            t = 4 - *(s16 *)(slot + 0xC);
            *(s16 *)(slot + 8) = (s16)Math_Ease(4, (f32)*(s16 *)(slot + 0xE), (f32)*(s16 *)(slot + 0x12), (f32)t, lbl_8036B9AC);
            *(s16 *)(slot + 0xA) = (s16)Math_Ease(4, (f32)*(s16 *)(slot + 0x10), (f32)*(s16 *)(slot + 0x14), (f32)t, lbl_8036B9AC);
        }
        i += 1;
        slot += 0x12;
    } while (i < 2);

    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B910, lbl_8036B910, lbl_8036B9B0, lbl_8036B918);
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();

    if ((s8)*(u8 *)((u8 *)self + 0x8A) != -1) {
        Prim2D_Begin();
        Prim2D_BindTexture(*(void **)((u8 *)self + 0), (s8)*(u8 *)((u8 *)self + 0x8A) + 4, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin(lbl_8036B9B4, lbl_8036B9B8, lbl_8036B910, lbl_8036B910);
        Prim2D_SetQuadMax(lbl_8036B9BC, lbl_8036B9C0, lbl_8036B9C4, lbl_8036B9C8);
        Prim2D_SetAlpha(0xFF);
        Prim2D_EndPrim();
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B91C);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_BindTexture(*(void **)((u8 *)self + 0), (s8)*(u8 *)((u8 *)self + 0x89) + 4, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B9B4, lbl_8036B9B8, lbl_8036B910, lbl_8036B910);
    Prim2D_SetQuadMax(lbl_8036B9BC, lbl_8036B9C0, lbl_8036B9C4, lbl_8036B9C8);
    Prim2D_SetAlpha((u8)*(s16 *)((u8 *)self + 0x8C));
    Prim2D_EndPrim();

    fn_8007D024(0xB3, 0xFB, lbl_8036B95C, lbl_8036B9B8, lbl_8036B9CC, (f32)(*(u8 *)((u8 *)self + 0x94) * 0x18 + 0x18));

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B91C);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();

    p = self;
    i = 0;
    y = 0x78;
    while (i < *(u8 *)((u8 *)self + 0x94)) {
        fn_8001003C(0x38, y, 1, 1, 0, Msg_Expand(*(void **)((u8 *)p + 0x98)), lbl_8036B918, lbl_8036B910);
        p = (u8 *)p + 4;
        y = (s16)(y + 0x18);
        i += 1;
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B918);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B9D0);
    Prim2D_PrepareTex();

    if (*(u8 *)((u8 *)self + 4) != 0) {
        Ui_DrawRouteIconEx(*(s16 *)((u8 *)self + 8), *(s16 *)((u8 *)self + 0xA), *(u8 *)((u8 *)self + 5));
        fn_8008AB7C(*(s16 *)((u8 *)self + 8) + 0x50, *(s16 *)((u8 *)self + 0xA) + 0xE, 0xA0, 0x17, 0x19, 0x64, *(u8 *)((u8 *)self + 5));
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B9D0);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x12);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B910, lbl_8036B910, lbl_8036B910, lbl_8036B910);
    Prim2D_SetQuadMax(lbl_8036B9D4, lbl_8036B9D8, lbl_8036B910, lbl_8036B910);
    Prim2D_SetColor(0, 0, 0, (u8)*(s16 *)((u8 *)self + 0x8E));
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B91C);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B988);
    Prim2D_PrepareTex();

    *(s32 *)c0 = *Ui_GetColor(1);
    pp = fn_8006EDD8(*(void **)((u8 *)self + 0), 0);
    h = ((u16 *)*pp)[1];
    w = ((u16 *)*pp)[0];
    Prim2D_Begin();
    Prim2D_BindTexture(*(void **)((u8 *)self + 0), 0, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B9DC, lbl_8036B924, lbl_8036B910, lbl_8036B910);
    Prim2D_SetQuadMax(lbl_8036B9DC + (f32)h, lbl_8036B924 + (f32)w, lbl_8036B910 + (f32)h, lbl_8036B910 + (f32)w);
    Prim2D_SetColor(c0[0], c0[1], c0[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B91C);
    Prim2D_PrepareTex();

    *(s32 *)c1 = *Ui_GetColor(1);
    pp = fn_8006EDD8(*(void **)((u8 *)self + 0), 1);
    h = ((u16 *)*pp)[1];
    w = ((u16 *)*pp)[0];
    Prim2D_Begin();
    Prim2D_BindTexture(*(void **)((u8 *)self + 0), 1, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B9E0, lbl_8036B9E4, lbl_8036B910, lbl_8036B910);
    Prim2D_SetQuadMax(lbl_8036B9E0 + (f32)h, lbl_8036B9E4 + (f32)w, lbl_8036B910 + (f32)h, lbl_8036B910 + (f32)w);
    Prim2D_SetColor(c1[0], c1[1], c1[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B93C);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B91C);
    Prim2D_PrepareTex();

    *(s32 *)c2 = *Ui_GetColor(1);
    pp = fn_8006EDD8(*(void **)((u8 *)self + 0), 2);
    h = ((u16 *)*pp)[1];
    w = ((u16 *)*pp)[0];
    Prim2D_Begin();
    Prim2D_BindTexture(*(void **)((u8 *)self + 0), 2, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B910, lbl_8036B9E8, lbl_8036B910, lbl_8036B910);
    f1 = lbl_8036B910 + (f32)h;
    Prim2D_SetQuadMax(f1, lbl_8036B9E8 + (f32)w, f1, lbl_8036B910 + (f32)w);
    Prim2D_SetColor(c2[0], c2[1], c2[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    *(s32 *)c3 = *Ui_GetColor(1);
    pp = fn_8006EDD8(*(void **)((u8 *)self + 0), 2);
    h = ((u16 *)*pp)[1];
    w = ((u16 *)*pp)[0];
    Prim2D_Begin();
    Prim2D_BindTexture(*(void **)((u8 *)self + 0), 2, 0x11);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(1);
    Prim2D_SetQuadMin(lbl_8036B920, lbl_8036B9E8, lbl_8036B910 + (f32)h, lbl_8036B910);
    Prim2D_SetQuadMax(lbl_8036B920 + (f32)h, lbl_8036B9E8 + (f32)w, lbl_8036B910, lbl_8036B910 + (f32)w);
    Prim2D_SetColor(c3[0], c3[1], c3[2], 0xFF);
    Prim2D_EmitQuad();
    Prim2D_EndPrim();

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B91C);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    Prim2D_PrepareTex();

    if ((s8)*(u8 *)((u8 *)self + 0x88) == 0) {
        fn_8001003C(0xF0, 0x3D, 2, 0, 0, Msg_Expand(gBattlePreviewStrings + 0x2C4), lbl_8036B918, lbl_8036B910);
    }
    flag = *(u8 *)((u8 *)self + 0x88);
    if (flag == 1) {
        fn_8001003C(0x8C, 0x3D, 2, 0, 0, Msg_Expand(gBattlePreviewStrings + 0x2D4), lbl_8036B918, lbl_8036B910);
        fn_8001003C(0x1C2, 0x3D, 2, 0, 0, Msg_Expand(gBattlePreviewStrings + 0x2E0), lbl_8036B918, lbl_8036B910);
        fn_8001003C(0x1FE, 0x3D, 2, 0, 0, Msg_Expand(gBattlePreviewStrings + 0x2E8), lbl_8036B918, lbl_8036B910);
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B93C);
    Prim2D_PrepareTex();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B9D0);
    Prim2D_PrepareTex();

    if (*(u8 *)((u8 *)self + 0x16) != 0) {
        Ui_DrawRouteIconEx(*(s16 *)((u8 *)self + 0x1A), *(s16 *)((u8 *)self + 0x1C), *(u8 *)((u8 *)self + 0x17));
        fn_8008AB7C(*(s16 *)((u8 *)self + 0x1A) + 0x1C, *(s16 *)((u8 *)self + 0x1C) + 0xC, 0x50, 0x18, 0x19, 0x4B, *(u8 *)((u8 *)self + 0x17));
    }

    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036B9EC);
    Prim2D_PrepareTex();

    if (*(f32 *)((u8 *)self + 0x90) != lbl_8036B910) {
        Prim2D_Begin();
        Prim2D_SetTransform(lbl_8036B920, lbl_8036B9F0, lbl_8036B9F4, *(f32 *)((u8 *)self + 0x90));
        Prim2D_PrepareTex();

        *(s32 *)c4 = *Ui_GetColor(1);
        pp = fn_8006EDD8(*(void **)((u8 *)self + 0), 3);
        h = ((u16 *)*pp)[1];
        w = ((u16 *)*pp)[0];
        Prim2D_Begin();
        Prim2D_BindTexture(*(void **)((u8 *)self + 0), 3, 0x11);
        Prim2D_PrepareTex();
        Prim2D_AddPrim(1);
        Prim2D_SetQuadMin(lbl_8036B9F8, lbl_8036B9FC, lbl_8036B910, lbl_8036B910);
        Prim2D_SetQuadMax(lbl_8036B9F8 + (f32)h, lbl_8036B9FC + (f32)w, lbl_8036B910 + (f32)h, lbl_8036B910 + (f32)w);
        Prim2D_SetColor(c4[0], c4[1], c4[2], 0xFF);
        Prim2D_EmitQuad();
        Prim2D_EndPrim();

        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B91C);
        Prim2D_PrepareTex();

        str = Msg_Expand(*(void **)((u8 *)self + 0x98 + *(s16 *)((u8 *)self + 6) * 4));
        tw = Text_MeasureWidth(str, -1, lbl_8036B918);
        fn_8001003C((s16)(-6 - (tw / 2)), -0x68, 2, 0, 0, str, lbl_8036B918, lbl_8036B910);

        item = fn_80019F04(*(s32 *)((u8 *)self + 0xC8) + *(s16 *)((u8 *)self + 6) + 0x5B);
        str = fn_8016614C(item, 0);
        if (str != 0) {
            fn_8001003C(-0x50, -0x42, 2, 0, 0, Msg_Expand(str), lbl_8036B918, lbl_8036B910);
        }
        str = fn_8016614C(item, 1);
        if (str != 0) {
            fn_8001003C(0x28, -0x42, 2, 0, 0, Msg_Expand(str), lbl_8036B918, lbl_8036B910);
        }

        p = self;
        maxw = 0;
        i = 0;
        while (i < *(u8 *)((u8 *)self + 0x95)) {
            tw = Text_MeasureWidth((u8 *)p + 0xCE, -1, lbl_8036B918);
            if ((s16)tw > maxw) {
                maxw = (s16)tw;
            }
            p = (u8 *)p + 0x40;
            i += 1;
        }

        fx = (lbl_8036B938 * (f32)(0x1D0 - maxw)) + lbl_8036B9F8;
        p = self;
        i = 0;
        y = -0x16;
        while (i < *(u8 *)((u8 *)self + 0x95)) {
            fn_8001003C((s16)fx, y, 0xF, 0, 0, (u8 *)p + 0xCE, lbl_8036B918, lbl_8036B910);
            p = (u8 *)p + 0x40;
            y = (s16)(y + 0x18);
            i += 1;
        }

        Prim2D_Begin();
        Prim2D_AddZ(lbl_8036B918);
        Prim2D_PrepareTex();
    }

    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036B910, lbl_8036B910, lbl_8036B9F4, lbl_8036B918);
    Prim2D_PrepareTex();
    Ui_DrawCaptionBar((u8 *)self + 0x28, 0);
    Prim2D_Begin();
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();
}

extern u8 lbl_8029B438[16];
void fn_801F8798(s32 arg0) {
    void Process_CreateChild(void *, s32);
    extern u8 lbl_8029B438[16];
    Process_CreateChild(lbl_8029B438, arg0);
}

s32 fn_801F87C4(void) {
    extern u8 gBattleState[];
    return gBattleState[0x10] == 0x20;
}

void fn_801F87E0(void) {
    void ScriptCmd_CmFreeScript(void);
    void fn_8003F670(void *);
    void fn_80050E80(void);
    void fn_8005BCAC(void);
    void fn_8005C7C8(void *);
    void fn_800C4B8C(void);
    extern u8 StaffRoll_str[];
    extern void *lbl_80368408;
    extern void *lbl_8036840C;
    void *p;

    fn_80050E80();
    fn_8005C7C8(StaffRoll_str + 0x1FE);
    p = lbl_80368408;
    if (p != NULL) {
        fn_8003F670(p);
        lbl_80368408 = NULL;
    }
    p = lbl_8036840C;
    if (p != NULL) {
        fn_8003F670(p);
        lbl_8036840C = NULL;
    }
    ScriptCmd_CmFreeScript();
    fn_8005BCAC();
    fn_800C4B8C();
    fn_800C4B8C();
}

void fn_801F8850(s32 arg0) {
    extern u16 StaffRoll_str[];

    Event_StartByName((u8 *)StaffRoll_str + 0x20E, arg0, StaffRoll_str);
}

#pragma global_optimizer off
void fn_801F8880(void) {
    void Heap_Create();
    s32 Heap_GetFree(void);
    void Heap_Select(void *);
    void ScriptCmd_CmLoadScript(void *);
    void *Archive_Load(void *);
    void FileCache_Load(void *);
    void Map_InitGfx(void);
    extern u8 StaffRoll_str[];
    extern u8 lbl_8029B41C[];
    extern void *lbl_80368408;
    extern void *lbl_8036840C;
    extern u8 lbl_80367708;

    Heap_Create(StaffRoll_str + 0x215, 0x180000);
    Heap_Create(StaffRoll_str + 0x220, Heap_GetFree(), StaffRoll_str);
    Heap_Select(StaffRoll_str + 0x215);
    ScriptCmd_CmLoadScript(StaffRoll_str + 0x22C);
    lbl_80368408 = Archive_Load(*(void **)(lbl_8029B41C + 4));
    lbl_8036840C = Archive_Load(StaffRoll_str + 0x23F);
    FileCache_Load(StaffRoll_str + 0x1FE);
    Map_InitGfx();
    lbl_80367708 = 0;
}
#pragma global_optimizer on
void fn_801F892C(void) {
    M2C_UNK fn_8002D4B8();
    fn_8002D4B8();
}

void fn_801F894C(s32 arg0) {
    extern u16 StaffRoll_str[];

    Event_StartByName((u8 *)StaffRoll_str + 0x24D, arg0, StaffRoll_str);
}

void fn_801F897C(void) {
    void Battle_SetPhase(void *, s32);
    void Battle_LoadMap(void);
    extern u8 gBattleState[];

    Battle_SetPhase(gBattleState, 0x1F);
    Battle_LoadMap();
}

void fn_801F89AC(void *arg0, s32 arg1) {
extern u8 lbl_8029B394[];
extern f32 lbl_8036BA00;
void *Process_CreateChild(void *,s32);
void fn_801FB410(void *);
u8 *entry=(u8*)Process_CreateChild(lbl_8029B394,arg1);
if(entry) {
fn_801FB410(entry+0x30);
*(f32*)(entry+0x3c)=lbl_8036BA00;
*(u32*)(entry+0x4c)=0;
*(u32*)(entry+0x50)=0;
entry[0x54]=5;
}
*(void**)(entry+0x48)=arg0;
}

void fn_801F8A18(void *arg0) {
    struct Node {
        struct Node *prev;
        struct Node *next;
    };
    struct List {
        s32 unk0;
        struct Node node;
    };
    struct Obj {
        u8 pad[0x30];
        struct List list;
    };
    void FileCache_ReleaseSlot(void *);
    void fn_801FB220(void *, struct List *, struct Node **, struct Node **);
    struct Node *sp10;
    struct Node *spC;
    u8 sp8[4];
    struct Node *end;
    struct Obj *self;

    self = (struct Obj *)arg0;
    if (*(u32 *)((u8 *)arg0 + 0x50) != 0) {
        FileCache_ReleaseSlot((u8 *)self + 0x50);
    }
    if (self != NULL) {
        if (&self->list != NULL) {
            if (&self->list != NULL) {
                if (&self->list != NULL) {
                    end = &self->list.node;
                    sp10 = end;
                    spC = end->next;
                    fn_801FB220(sp8, &self->list, &spC, &sp10);
                }
            }
        }
    }
}

#pragma optimization_level 2
#pragma use_lmw_stmw on
#pragma opt_pointer_aliasing off
void fn_801F8A98(void *arg0) {
    void Allegiance_SetMask(s32, s32, s32, s32, s32, s32, s32, s32, void *);
    void fn_800506E0(void *, s32, void *);
    void fn_800616A0(void *);
    void GActor_Finalize(void *);
    void *GActor_Create(void);
    s32 fn_800639B4(void);
    void fn_8006EEFC(void *, void *);
    void *fn_800A8A00(void *);
    void fn_80108FA8(void *);
    void *Sound_Create(void *, void *);
    void fn_801FA8B4(void *, void *);
    void StaffRoll_ListInsertActor(void *, void *, void *, void *);
    void sprintf(void *, void *, ...);
    void *memset(void *, s32, u32);
    u32 StaffRoll_CompareUnits(void **, void **);
    extern u8 gUnits[];
    extern u8 StaffRoll_str[];
    extern void *lbl_8029B378[];
    extern f32 lbl_8036BA00;
    extern f32 lbl_8036BA04;

    typedef struct Node {
        struct Node *unk0;
        struct Node *unk4;
        void *unk8;
    } Node;

    char buf[0x20];
    u8 flags[8];
    struct {
        void *owner;
        void *obj;
    } pair;
    void *sp14;
    void *sp10;
    void *self;
    void *unit;
    void *base;
    register void *strs;
    Node *n;
    void *fmt259;
    register s32 i;

    self = arg0;
    Allegiance_SetMask(1, 0, 0, 0, 0, 1, 1, 0, flags);
    i = 1;
    base = (u8 *)self + 0x34;
    do {
        if ((u8)i != 0) {
            unit = gUnits + ((u8)i - 1) * 0x280;
        } else {
            unit = NULL;
        }
        if (*(void **)((u8 *)unit + 0x188) != NULL) {
            if (flags[((u8 *)*(void **)((u8 *)unit + (short)0x190))[8]] != 0) {
                u32 *p;
                pair.owner = unit;
                pair.obj = (void *)0;
                if (pair.obj != (void *)0) {
                    fn_800616A0(pair.obj);
                }
                pair.obj = GActor_Create();
                p = (u32 *)pair.obj;
                *(void **)((u8 *)pair.obj + 4) = (u8 *)unit + 0x1C;
                *p |= 0x50028400;
                fn_800506E0(unit, 0, p);
                *(s32 *)((u8 *)pair.obj + 0x44) = fn_800639B4();
                GActor_Finalize(pair.obj);
                sp14 = base;
                StaffRoll_ListInsertActor(&sp10, (u8 *)self + 0x30, &sp14, &pair.owner);
                if (pair.obj != (void *)0) {
                    fn_800616A0(pair.obj);
                }
            }
        }
        i += 1;
    } while (0x9F >= i);
    fn_801FA8B4((void *)((u32)self + 0x30U), StaffRoll_CompareUnits);
    n = *(Node **)base;
    strs = StaffRoll_str;
    n = n->unk0;
    fmt259 = (u8 *)strs + 0x259;
    n = n->unk0;
    n = n->unk0;
    n = n->unk0;
    while (n != (Node *)base) {
        sprintf(buf, (u8 *)strs + 0x268, fn_800A8A00(*(void **)((u8 *)n->unk8 + 0x188)));
        sprintf(fmt259, (u8 *)strs + 0x273, *(s8 *)((u8 *)self + 0x54));
        fn_80108FA8(buf);
        fn_80108FA8(fmt259);
        n = n->unk4;
    }
    memset((u8 *)self + 0x58, 0, 0x10);
    {
        f32 lim = lbl_8036BA00;
        f32 f = lbl_8036BA04 + *(f32 *)((u8 *)self + 0x3C);
        s32 count = ((s32 *)self)[0xC];
        *(f32 *)((u8 *)self + 0x40) = f + (f32)(u32)((count - 5) * 0x50);
        *(s32 *)((u8 *)self + 0x48) = (s32)((*(f32 *)((u8 *)self + 0x40) / lim) * (f32)*(s32 *)((u8 *)self + 0x48));
        *(f32 *)((u8 *)self + 0x44) = *(f32 *)((u8 *)self + 0x40) / (f32)*(s32 *)((u8 *)self + 0x48);
        Sound_Create(StaffRoll_str + 0x284, self);
        *(void **)((u8 *)self + 0x4C) = Sound_Create(StaffRoll_str + 0x293, self);
    }
    fn_8006EEFC((u8 *)self + 0x50, lbl_8029B378[1]);
}
#pragma opt_pointer_aliasing reset
#pragma optimization_level reset
#pragma use_lmw_stmw on

/* Compare two staff-roll units: allegiance 6 first, then chapter/battles/class id. */
u32 StaffRoll_CompareUnits(void **lhs, void **rhs) {
    u16 battlesB;
    u16 battlesRhs;
    u16 battlesA;
    u8 allegLhs;
    u8 chapterRhs;
    u8 chapterLhs;
    u16 battlesLhs;
    void *unitLhs;
    void *personLhs;
    void *unitRhs;
    void *p;
    u16 classIdA;
    u16 classIdB;

    unitLhs = *lhs;
    unitRhs = *rhs;
    personLhs = M2C_FIELD(unitLhs, void **, 0x190);
    if ((u8)M2C_FIELD((s32)personLhs, u8 *, 8) == 6) {
        if ((u8)M2C_FIELD(M2C_FIELD(unitRhs, void **, 0x190), u8 *, 8) != 6) {
            return 1U;
        }
    }
    allegLhs = M2C_FIELD(personLhs, u8 *, 8);
    if (allegLhs != 6) {
        if ((u8)M2C_FIELD(M2C_FIELD(unitRhs, void **, 0x190), u8 *, 8) == 6) {
            return 0U;
        }
    }
    if (allegLhs == 6) {
        if ((u8)M2C_FIELD(M2C_FIELD(unitRhs, void **, 0x190), u8 *, 8) == 6) {
            chapterLhs = M2C_FIELD(unitLhs, u8 *, 0x234);
            chapterRhs = M2C_FIELD(unitRhs, u8 *, 0x234);
            if (chapterLhs == chapterRhs) {
                battlesLhs = M2C_FIELD(unitLhs, u16 *, 0x22A);
                battlesRhs = M2C_FIELD(unitRhs, u16 *, 0x22A);
                if (battlesLhs == battlesRhs) {
                    p = M2C_FIELD(unitLhs, void **, 0x188);
                    classIdA = M2C_FIELD(p, u16 *, 0x5A);
                    p = M2C_FIELD(unitRhs, void **, 0x188);
                    classIdB = M2C_FIELD(p, u16 *, 0x5A);
                    return (u32)(classIdA - classIdB) >> 0x1FU;
                }
                return (u32)(battlesLhs - battlesRhs) >> 0x1FU;
            }
            return (u32)(chapterLhs - chapterRhs) >> 0x1FU;
        }
    }
    battlesA = M2C_FIELD(unitLhs, u16 *, 0x22A);
    battlesB = M2C_FIELD(unitRhs, u16 *, 0x22A);
    if (battlesA == battlesB) {
        p = M2C_FIELD(unitLhs, void **, 0x188);
        classIdA = M2C_FIELD(p, u16 *, 0x5A);
        p = M2C_FIELD(unitRhs, void **, 0x188);
        classIdB = M2C_FIELD(p, u16 *, 0x5A);
        return (u32)(classIdA - classIdB) >> 0x1FU;
    }
    return (u32)(battlesA - battlesB) >> 0x1FU;
}

#pragma global_optimizer off
void fn_801F8E30(void *arg0) {
    void fn_80007340(void *, void *);
    void Prim2D_SetRect(f32, f32, f32, f32);
    void Prim2D_EndPrim(void);
    void Prim2D_AddPrim(s32);
    void Prim2D_SetAlphaByte(s32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_AddZ(f32);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetTex(void *, s32);
    void Prim2D_PrepareTex(void);
    void Prim2D_Begin(void);
    void Process_Goto(void *, s32);
    void *Msg_Expand(void *);
    void Text_Draw(s32, s32, s32, void *, ...);
    s32 Text_MeasureHeight(s32, f32);
    void fn_8004BD1C(void *, f32 *, f32);
    void fn_8004DDB8(s32);
    void fn_8005F780(void *, s32);
    void Model_SetAlpha(void *, s32);
    void Model_SetColor(void *, s32, s32, s32);
    void fn_80060060(void *);
    void fn_800609DC(void *);
    void Ui_LoadAtlasTex(void *, void *, s32);
    void *fn_800A8978(void *);
    void *Msg_ResolveName(void *);
    void fn_80109020(void *);
    void PSMTXConcat(void *, void *, void *);
    void PSMTXRotRad(void *, s32, f32);
    void fn_80202574(void *, void *, f32, f32, f32);
    void fn_802025E8(void *, void *, f32, f32, f32);
    u16 GXGetTexObjWidth(void *);
    u16 GXGetTexObjHeight(void *);
    void sprintf(void *, void *, ...);
    f64 fmod(f64, f64);
    void fn_80069F04(void);
    void fn_801F9464(void);
    extern s32 gUiInputFlags;
    extern u8 StaffRoll_str[];
    extern f32 lbl_8036BA00, lbl_8036BA04, lbl_8036BA18, lbl_8036BA1C, lbl_8036BA20;
    extern f32 lbl_8036BA38, lbl_8036BA3C, lbl_8036BA40, lbl_8036BA44, lbl_8036BA48;
    extern f32 lbl_8036BA4C, lbl_8036BA50, lbl_8036BA54, lbl_8036BA58, lbl_8036BA5C;
    extern f32 lbl_8036BA60, lbl_8036BA64, lbl_8036BA68, lbl_8036BA6C, lbl_8036BA70;
    extern f64 lbl_8036BA28, lbl_8036BA30;

    f32 sp8[2];
    u8 sp14[0x30];
    u8 sp44[0x30];
    u8 sp74[0x20];
    u16 sp94, sp96;
    f32 f26, f27, f28, f29, f30, f31;
    f32 scroll, period, y, limit, step, y2;
    void *obj, *node, *end, *unit, *draw;
    void **p;
    u8 flag;
    char buf[0x20];

    if (gUiInputFlags & 1) {
        Process_Goto(arg0, 3);
        return;
    }
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036BA18, lbl_8036BA18, lbl_8036BA1C, lbl_8036BA20);
    Prim2D_SetColorByte(0xFF);
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
    f29 = *(f32 *)((u8 *)arg0 + 0x3C);
    period = (f32)fmod(lbl_8036BA28, lbl_8036BA30);
    f27 = (f32)(s32)(period * (f29 + lbl_8036BA38 / period)) / period;
    obj = *(void **)((u8 *)arg0 + 0x4C);
    if (obj != NULL) {
        flag = 0;
        if (f27 <= lbl_8036BA00) {
            if (lbl_8036BA18 < f27 + lbl_8036BA04) {
                flag = 1;
            }
        }
        if (flag) {
            *(f32 *)((u8 *)obj + 0x40) = lbl_8036BA3C;
            *(f32 *)((u8 *)obj + 0x44) = f27;
        } else {
            goto clear;
        }
    } else {
clear:
        fn_80109020(StaffRoll_str + 0x293);
        *(void **)((u8 *)arg0 + 0x4C) = NULL;
    }
    f30 = f27 + lbl_8036BA04;
    f30 = f30 + lbl_8036BA38 * (f32)(0x50 - Text_MeasureHeight(-1, lbl_8036BA20));
    p = *(void ***)((u8 *)arg0 + 0x34);
    p = (void **)*p;
    p = (void **)*p;
    p = (void **)*p;
    end = *p;
    node = *(void **)((u8 *)arg0 + 0x38);
    f31 = lbl_8036BA00;
    f29 = lbl_8036BA40;
    for (; node != end; node = *(void **)((u8 *)node + 4), f30 += f29) {
        flag = 0;
        if (f30 <= f31) {
            if (lbl_8036BA18 < f30 + lbl_8036BA40) {
                flag = 1;
            }
        }
        if (flag) {
            unit = *(void **)((u8 *)node + 8);
            Prim2D_Begin();
            Prim2D_SetTex(NULL, 0x13);
            Prim2D_PrepareTex();
            Text_Draw((s32)lbl_8036BA44, (s32)f30, 2, Msg_ResolveName(*(void **)((u8 *)unit + 0x188)));
            Text_Draw((s32)lbl_8036BA48, (s32)f30, 2, fn_800A8978(*(void **)((u8 *)unit + 0x18C)));
            if (*(u8 *)(*(u8 **)((u8 *)unit + 0x190) + 8) != 6) {
                Text_Draw((s32)lbl_8036BA4C, (s32)f30, 2, StaffRoll_str + 0x29F,
                    Msg_Expand(StaffRoll_str + 0x2A6), (s8)*(u8 *)((u8 *)unit + 0x19A));
                Text_Draw((s32)lbl_8036BA50, (s32)f30, 2, StaffRoll_str + 0x2B1,
                    *(u16 *)((u8 *)unit + 0x22A), Msg_Expand(StaffRoll_str + 0x2B8));
            } else {
                sprintf(buf, StaffRoll_str + 0x2D4, *(u8 *)((u8 *)unit + 0x234));
                Text_Draw((s32)lbl_8036BA4C, (s32)f30, 2, Msg_Expand(buf));
            }
            f28 = f30 + (f32)Text_MeasureHeight(-1, lbl_8036BA20);
            Ui_LoadAtlasTex(*(void **)((u8 *)arg0 + 0x50), sp74, 2);
            sp94 = GXGetTexObjWidth(sp74);
            sp96 = GXGetTexObjHeight(sp74);
            Prim2D_Begin();
            Prim2D_SetTex(sp74, 0x10);
            Prim2D_PrepareTex();
            Prim2D_AddPrim(1);
            Prim2D_SetRect(lbl_8036BA54, f28, (f32)sp94, (f32)sp96);
            Prim2D_EndPrim();
        }
    }
    f26 = lbl_8036BA04 + *(f32 *)((u8 *)arg0 + 0x3C);
    Prim2D_Begin();
    Prim2D_SetTex(NULL, 0x410);
    Prim2D_SetColorByte(0xFF);
    Prim2D_PrepareTex();
    Prim2D_AddPrim(0xB);
    fn_80007340(fn_801F9464, NULL);
    Prim2D_EndPrim();
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036BA58);
    Prim2D_PrepareTex();
    p = *(void ***)((u8 *)arg0 + 0x34);
    p = (void **)*p;
    p = (void **)*p;
    p = (void **)*p;
    end = *p;
    node = *(void **)((u8 *)arg0 + 0x38);
    f29 = lbl_8036BA5C;
    f31 = lbl_8036BA00;
    f30 = lbl_8036BA40;
    for (; node != end; node = *(void **)((u8 *)node + 4), f26 += f30) {
        y2 = f26 - f29;
        flag = 0;
        if (y2 <= f31) {
            if (lbl_8036BA18 < y2 + lbl_8036BA60) {
                flag = 1;
            }
        }
        if (flag) {
            PSMTXRotRad(sp44, 0x79, lbl_8036BA64);
            PSMTXRotRad(sp14, 0x78, lbl_8036BA68);
            PSMTXConcat(sp14, sp44, sp14);
            fn_802025E8(sp14, sp14, lbl_8036BA6C, lbl_8036BA6C, lbl_8036BA6C);
            draw = *(void **)((u8 *)node + 0xC);
            f28 = lbl_8036BA40 + f26;
            f27 = lbl_8036BA70;
            fn_8004BD1C(*(void **)((u8 *)node + 8), sp8, lbl_8036BA6C);
            fn_80202574(sp14, (u8 *)draw + 0x10, f27 + sp8[0], f28 + sp8[1], lbl_8036BA1C);
            Model_SetColor(draw, 0x80, 0x80, 0x80);
            Model_SetAlpha(draw, 0xFF);
            fn_8005F780(draw, 0xFF);
            fn_80060060(draw);
            fn_800609DC(draw);
            Prim2D_AddPrim(0xB);
            fn_80007340(fn_80069F04, draw);
            Prim2D_EndPrim();
        }
    }
    fn_8004DDB8(0x63);
}
#pragma global_optimizer on

void fn_801F9464(void) {
    M2C_UNK fn_80059C2C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    fn_80059C2C(0, 0, 0x260, 0x1C0, 0);
}

void fn_801F9498(void *arg0) {
    M2C_UNK Process_ClearFunc();
    s32 temp_r0;

    M2C_FIELD(arg0, f32 *, 0x3C) = (f32) (M2C_FIELD(arg0, f32 *, 0x3C) - M2C_FIELD(arg0, f32 *, 0x44));
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x48) - 1;
    M2C_FIELD(arg0, s32 *, 0x48) = temp_r0;
    if (temp_r0 < 0) {
        Process_ClearFunc();
    }
}

#pragma use_lmw_stmw on
void fn_801F94D8(void *arg0) {
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetAlphaByte(s32);
    void Prim2D_PrepareTex(void);
    void Process_Goto(void *, s32);
    void Prim2D_SetTex(s32, s32);
    void Prim2D_AddZ(f32);
    void *Msg_Expand(void *);
    s16 Text_MeasureWidth(void *, s32, f32);
    void fn_8001003C(s32, s32, s32, s32, s32, void *, f32, f32, ...);
    void *fn_800A8978(void *);
    f32 fn_801099A0(void *, s32);
    void sprintf(void *, void *, ...);
    extern s32 gUiInputFlags;
    extern u8 StaffRoll_str[];
    extern f32 lbl_8036BA18;
    extern f32 lbl_8036BA20;
    extern f32 lbl_8036BA74;
    extern f64 lbl_8036BA10;
    extern f32 lbl_8036BA78;
    extern f32 lbl_8036BA7C;
    extern f32 lbl_8036BA80;
    extern f32 lbl_8036BA84;

    char sp8[0x80];
    void *temp_r29;
    void **var_r31;
    u8 sel_byte;
    s32 sel;
    s32 n;
    void *nameStr;
    void *other;
    void *entry;
    void *str;
    void *fmtStr;
    void *obj;
    f32 f31;
    f32 f30;
    s16 w;
    u16 val22a;
    s8 val19a;

    temp_r29 = arg0;
    if (gUiInputFlags & 1) {
        Process_Goto(temp_r29, 3);
        return;
    }
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036BA18, lbl_8036BA18, lbl_8036BA74, lbl_8036BA20);
    Prim2D_SetColorByte(0xFF);
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
    sel_byte = ((u8 *)temp_r29)[0x54];
    Prim2D_Begin();
    Prim2D_SetTex(0, 0x13);
    sel = (s8)sel_byte;
    Prim2D_AddZ((f32)(sel * 2));
    Prim2D_PrepareTex();
    n = -sel;
    var_r31 = (void **)((u8 *)temp_r29 + 0x34);
    if (n >= 0) {
        for (; n > 0; n--) {
            var_r31 = (void **)var_r31[1];
        }
    } else {
        for (n = sel; n > 0; n--) {
            var_r31 = (void **)*var_r31;
        }
    }
    if ((s8)sel_byte > 0) {
        entry = *(void **)((u8 *)temp_r29 + ((sel & 1) << 3) + 0x58);
        if (entry != 0) {
            Prim2D_Begin();
            Prim2D_SetColorByte((s32)fn_801099A0(entry, 9));
            Prim2D_PrepareTex();
            f31 = fn_801099A0(entry, 1);
            f30 = lbl_8036BA78;
            str = fn_800A8978(*(void **)((u8 *)var_r31[2] + 0x18C));
            w = Text_MeasureWidth(str, -1, lbl_8036BA20);
            f30 = f30 - (f32)(w >> 1);
            fn_8001003C((s32)f30, (s32)(lbl_8036BA7C + f31), 1, 1, 0, str, lbl_8036BA20, lbl_8036BA18);
            obj = var_r31[2];
            val22a = *(u16 *)((u8 *)obj + 0x22A);
            val19a = *(s8 *)((u8 *)obj + 0x19A);
            nameStr = Msg_Expand(StaffRoll_str + 0x2B8);
            fmtStr = Msg_Expand(StaffRoll_str + 0x2A6);
            sprintf(sp8, StaffRoll_str + 0x2E6, fmtStr, val19a, val22a, nameStr);
            f30 = lbl_8036BA78;
            w = Text_MeasureWidth(sp8, -1, lbl_8036BA20);
            f30 = f30 - (f32)(w >> 1);
            fn_8001003C((s32)f30, (s32)(lbl_8036BA80 + f31), 1, 1, 0, sp8, lbl_8036BA20, lbl_8036BA18);
        }
    }
    Prim2D_Begin();
    Prim2D_AddZ(lbl_8036BA84);
    Prim2D_PrepareTex();
    other = *var_r31;
    if ((s8)(sel + 1) < 5) {
        entry = *(void **)((u8 *)temp_r29 + (((sel + 1) & 1) << 3) + 0x58);
        if (entry != 0) {
            Prim2D_Begin();
            Prim2D_SetColorByte((s32)fn_801099A0(entry, 9));
            Prim2D_PrepareTex();
            f31 = fn_801099A0(entry, 1);
            f30 = lbl_8036BA78;
            str = fn_800A8978(*(void **)((u8 *)((void **)other)[2] + 0x18C));
            w = Text_MeasureWidth(str, -1, lbl_8036BA20);
            f30 = f30 - (f32)(w >> 1);
            fn_8001003C((s32)f30, (s32)(lbl_8036BA7C + f31), 1, 1, 0, str, lbl_8036BA20, lbl_8036BA18);
            obj = ((void **)other)[2];
            val22a = *(u16 *)((u8 *)obj + 0x22A);
            val19a = *(s8 *)((u8 *)obj + 0x19A);
            nameStr = Msg_Expand(StaffRoll_str + 0x2B8);
            fmtStr = Msg_Expand(StaffRoll_str + 0x2A6);
            sprintf(sp8, StaffRoll_str + 0x2E6, fmtStr, val19a, val22a, nameStr);
            f30 = lbl_8036BA78;
            w = Text_MeasureWidth(sp8, -1, lbl_8036BA20);
            f30 = f30 - (f32)(w >> 1);
            fn_8001003C((s32)f30, (s32)(lbl_8036BA80 + f31), 1, 1, 0, sp8, lbl_8036BA20, lbl_8036BA18);
        }
    }
}
void fn_801F99C4(void *arg0) {
    s32 fn_800A8A00(void *);
    void *Sound_Create(void *, void *);
    void Sound_TweenParam(void *, s32, s32, f32, f32, f32);
    void Sound_FadeFromZero(void *, s32);
    void sprintf(void *, void *, ...);
    extern u8 StaffRoll_str[];
    extern f32 lbl_8036BA18;
    extern f32 lbl_8036BA88;
    extern f32 lbl_8036BA8C;

    char sp8[0x20];
    void **var_r4;
    void *temp_r28;
    void *temp_r31;
    void *temp_r29;
    s8 var_r30;
    s32 var_r3;
    void *temp_r3;
    void *temp_r3_2;
    s32 temp_r4;
    f32 f2;

    temp_r29 = arg0;
    var_r4 = (void **)((u8 *)temp_r29 + 0x34);
    var_r30 = *(s8 *)((u8 *)arg0 + 0x54);
    var_r3 = -var_r30;
    temp_r31 = (u8 *)temp_r29 + ((var_r30 & 1) << 3);
    if (var_r3 >= 0) {
        if (var_r3) {
            for (; var_r3 != 0; var_r3--) {
                var_r4 = (void **)var_r4[1];
            }
        }
    } else {
        var_r3 = -var_r3;
        for (; var_r3 != 0; var_r3--) {
            var_r4 = (void **)*var_r4;
        }
    }
    temp_r28 = StaffRoll_str + 0x259;
    sprintf(sp8, StaffRoll_str + 0x268, fn_800A8A00(*(void **)((u8 *)*(void **)((u8 *)var_r4 + 8) + 0x188)));
    sprintf(temp_r28, StaffRoll_str + 0x273, *(s8 *)((u8 *)temp_r29 + 0x54));
    *(void **)((u8 *)temp_r31 + 0x58) = Sound_Create(sp8, temp_r29);
    *(void **)((u8 *)temp_r31 + 0x5C) = Sound_Create(temp_r28, *(void **)((u8 *)temp_r31 + 0x58));
    temp_r4 = var_r30 * 2;
    f2 = lbl_8036BA18;
    temp_r3 = *(void **)((u8 *)temp_r31 + 0x58);
    *(f32 *)((u8 *)temp_r3 + 0x40) = f2;
    *(f32 *)((u8 *)temp_r3 + 0x44) = f2;
    *(f32 *)((u8 *)temp_r3 + 0x48) = (f32)temp_r4;
    temp_r3_2 = *(void **)((u8 *)temp_r31 + 0x5C);
    *(f32 *)((u8 *)temp_r3_2 + 0x40) = f2;
    *(f32 *)((u8 *)temp_r3_2 + 0x44) = f2;
    *(f32 *)((u8 *)temp_r3_2 + 0x48) = (f32)temp_r4;
    Sound_FadeFromZero(*(void **)((u8 *)temp_r31 + 0x58), 0x18);
    Sound_TweenParam(*(void **)((u8 *)temp_r31 + 0x58), 1, 5, lbl_8036BA88, lbl_8036BA18, lbl_8036BA8C);
    Sound_FadeFromZero(*(void **)((u8 *)temp_r31 + 0x5C), 0x18);
    Sound_TweenParam(*(void **)((u8 *)temp_r31 + 0x5C), 1, 5, lbl_8036BA88, lbl_8036BA18, lbl_8036BA8C);
    *(u16 *)((u8 *)temp_r29 + 0x28) = 0xF0;
}

void fn_801F9BD8(void *arg0) {
    void Sound_FadeToVol(void *, s32);
    void Sound_TweenParam(void *, s32, s32, f32, f32, f32);
    extern f32 lbl_8036BA18;
    extern f32 lbl_8036BA90;
    extern f32 lbl_8036BA8C;
    u8 *self;
    s32 idx;
    void *a;
    void *b;
    s8 v;

    self = (u8 *)arg0;
    v = *(s8 *)(self + 0x54);
    if (v > 1) {
        idx = (v & 1) << 3;
        a = *(void **)(self + idx + 0x58);
        Sound_FadeToVol(a, 0x18);
        Sound_TweenParam(a, 1, 2, lbl_8036BA18, lbl_8036BA90, lbl_8036BA8C);
        b = *(void **)(self + idx + 0x5C);
        Sound_FadeToVol(b, 0x18);
        Sound_TweenParam(b, 1, 2, lbl_8036BA18, lbl_8036BA90, lbl_8036BA8C);
    }
    *(u16 *)(self + 0x28) = 0x18;
}

void fn_801F9C8C(void *arg0) {
    void Process_Goto(void *, s32);
    void Process_Unlink(void *);
    s32 v;

    v = *(u8 *)((u8 *)arg0 + 0x54) - 1;
    *(u8 *)((u8 *)arg0 + 0x54) = v;
    if ((s8)v == 0) {
        Process_Goto(arg0, 2);
    } else {
        arg0 = (u8 *)arg0 + ((v & 1) << 3);
        arg0 = *(void **)((u8 *)arg0 + 0x58);
        if (arg0 != NULL) {
            Process_Unlink(arg0);
        }
    }
}

void fn_801F9CE0(s32 arg0) {
    extern void *gPadInput;
    s32 temp_r5;

    temp_r5 = M2C_FIELD(gPadInput, s32 *, 4);
    if (temp_r5 & (M2C_FIELD(gPadInput, s32 *, 8) ^ temp_r5) & 0x1F70) {
        Process_ClearFunc(arg0);
    }
}

void fn_801F9D1C(s32 arg0, s32 arg1) {
    void *fn_801F9D50(s32);
    M2C_FIELD(fn_801F9D50(arg1), s32 *, 0x48) = arg0;
}

void *fn_801F9D50(void *arg0)
{
    extern u8 lbl_8029B32C[];
    extern f32 lbl_8036BA00;
    void *Process_CreateChild(void *, void *);
    void StaffRoll_VecReserve(void *, u32);
    u8 *entry;
    u8 *tmp;
    u32 *vec;
    f32 zero;

    entry = (u8 *)Process_CreateChild(lbl_8029B32C, arg0);
    tmp = entry;
    if (entry != NULL) {
        vec = (u32 *)(tmp + 0x30);
        *(u32 *)(tmp + 0x30) = 0;
        zero = lbl_8036BA00;
        *(u32 *)(tmp + 0x34) = 0;
        vec[2] = 0;
        *(f32 *)(tmp + 0x3C) = zero;
        *(u32 *)(tmp + 0x4C) = 0;
        StaffRoll_VecReserve(vec, 0x28);
    }
    return entry;
}

void fn_801F9DC0(u32 arg0) {
    M2C_UNK fn_801FB1C0(s32, M2C_UNK);
    if ((arg0 != 0U) && ((arg0 + 0x30) != 0) && ((arg0 + 0x30) != 0)) {
        fn_801FB1C0(arg0 + 0x30, 0);
    }
}

#pragma use_lmw_stmw on
#pragma global_optimizer off
void fn_801F9E00(void *arg0) {
    s32 Sound_Create(void *, void *);
    void fn_8014DBE0(void *, s32, u8 *, u16 *, s32 *);
    s32 fn_8014DC04(void *);
    void fn_801FAA9C(void *, void *, s32, void *);
    extern u8 gBattleState[];
    extern u8 StaffRoll_str[];
    extern f32 lbl_8036BA00;
    extern f32 lbl_8036BA04;
    extern f64 lbl_8036BA08;
    extern f64 lbl_8036BA10;

    typedef struct {
        u8 pad[0x30];
        u32 unk30;
        s32 unk34;
        u8 *unk38;
        f32 unk3C;
        f32 unk40;
        f32 unk44;
        s32 unk48;
        s32 unk4C;
    } Obj;

    struct {
        u8 kind;
        u8 pad;
        u16 field;
        s32 val;
    } packet;
    s32 spC;
    u16 spA;
    u8 sp8;
    s32 temp_r31;
    s32 *p_spC;
    u16 *p_spA;
    void *temp_r28;
    s32 var_r27;
    s32 var_r26;
    Obj *obj;
    s32 temp_r0;
    u8 pk;
    f32 lim;
    f32 f;
    s32 count;

    temp_r28 = gBattleState + 0x3C4;
    obj = (Obj *)arg0;
    var_r27 = 0;
    packet.kind = 0xFF;
    packet.val = 0;
    packet.field = 0;
    temp_r31 = fn_8014DC04(temp_r28);
    p_spC = &spC;
    p_spA = &spA;
    var_r26 = 0;
    goto loop_check;
loop_body:
    fn_8014DBE0(temp_r28, var_r26, &sp8, p_spA, p_spC);
    pk = packet.kind;
    if (pk == sp8) {
        goto accumulate;
    }
    if (pk != 0x1C) {
        goto else_path;
    }
    if (sp8 != 0x1D) {
        goto else_path;
    }
accumulate:
    temp_r0 = spC - var_r27;
    var_r27 = spC;
    packet.field += spA;
    packet.val += temp_r0;
    goto loop_next;
else_path:
    if (pk != 0xFF) {
        fn_801FAA9C(&obj->unk30, obj->unk38 + (obj->unk34 << 3), 1, &packet);
    }
    packet.kind = sp8;
    temp_r0 = spC - var_r27;
    packet.field = spA;
    var_r27 = spC;
    packet.val = temp_r0;
loop_next:
    var_r26 += 1;
loop_check:
    if (var_r26 < temp_r31) {
        goto loop_body;
    }
    if (packet.kind != 0xFF) {
        fn_801FAA9C(&obj->unk30, obj->unk38 + (obj->unk34 << 3), 1, &packet);
    }
    lim = lbl_8036BA00;
    f = lbl_8036BA04 + obj->unk3C;
    count = obj->unk34;
    obj->unk40 = f + (f32)(u32)(count << 6);
    obj->unk48 = (s32)((obj->unk40 / lim) * (f32)obj->unk48);
    obj->unk44 = obj->unk40 / (f32)obj->unk48;
    Sound_Create(StaffRoll_str + 0x2F3, obj);
    obj->unk4C = Sound_Create(StaffRoll_str + 0x301, obj);
}

#pragma global_optimizer off
void fn_801FA00C(void *arg0) {
void Prim2D_Begin(void); void Prim2D_SetTransform(f32,f32,f32,f32);
void Prim2D_SetColorByte(s32); void Prim2D_SetAlphaByte(s32); void Prim2D_PrepareTex(void);
void Process_Goto(void*,s32); void fn_80109020(void*);
void Prim2D_SetTex(s32,s32); void *Msg_Expand(void*);
s32 Text_MeasureHeight(s32,f32); s16 Text_MeasureWidth(void*,s32,f32);
void fn_8001003C(s32,s32,s32,s32,s32,void*,f32,f32,...);
void sprintf(void*,void*,...); f64 fmod(f64,f64);
extern s32 gUiInputFlags;
extern u8 StaffRoll_str[];
extern f32 lbl_8036BA18,lbl_8036BA1C,lbl_8036BA20,lbl_8036BA38,lbl_8036BA00,lbl_8036BA04,lbl_8036BA88,lbl_8036BA94,lbl_8036BA98,lbl_8036BA9C,lbl_8036BAA0,lbl_8036BAA4,lbl_8036BAA8;
extern f64 lbl_8036BA28,lbl_8036BA30;
f32 limit, y, scroll, step, x, period, offset;
u8 *end, *ent, *base;
void *str, *a, *b, *obj;
u8 flag;
u32 minutes, seconds, hours, time;
f32 tx, scale, zero;
if(gUiInputFlags & 1) {Process_Goto(arg0,1);return;}
Prim2D_Begin();
Prim2D_SetTransform(lbl_8036BA18,lbl_8036BA18,lbl_8036BA1C,lbl_8036BA20);
Prim2D_SetColorByte(255); Prim2D_SetAlphaByte(128); Prim2D_PrepareTex();
scroll=*(f32*)((u8*)arg0+0x3c);
period=(f32)fmod(lbl_8036BA28,lbl_8036BA30);
scroll=(f32)(s32)(period*(scroll+lbl_8036BA38/period))/period;
obj=*(void**)((u8*)arg0+0x4c);
if(obj) {
flag=0;
if(scroll<=lbl_8036BA00) { if(lbl_8036BA18<scroll+lbl_8036BA04) flag=1;}
if(flag) {*(f32*)((u8*)obj+0x40)=lbl_8036BA94;*(f32*)((u8*)obj+0x44)=scroll;}
else goto clear;
} else {
clear:
fn_80109020(StaffRoll_str+0x301);*(void**)((u8*)arg0+0x4c)=0;
}
y=scroll+lbl_8036BA04;
offset=lbl_8036BA38*(f32)(64-Text_MeasureHeight(-1,lbl_8036BA20));
y=y+offset;
base=*(u8**)((u8*)arg0+0x38);
ent=base;
end=base+*(u32*)((u8*)arg0+0x34)*8;
limit=lbl_8036BA00;step=lbl_8036BA88;
for(;ent!=end;ent+=8,y+=step){
flag=0;
if(y<=limit) {if(lbl_8036BA18<y+lbl_8036BA88)flag=1;}
if(flag){
a=StaffRoll_str+0x30c;b=StaffRoll_str+0x31b;
sprintf(a,StaffRoll_str+0x32c,*ent);
sprintf(b,StaffRoll_str+0x33d,*ent);
Prim2D_Begin();Prim2D_SetTex(0,19);Prim2D_PrepareTex();
str=Msg_Expand(a);
fn_8001003C((s32)((f32)(128-(Text_MeasureWidth(str,-1,lbl_8036BA20)>>1))-lbl_8036BA98),(s32)y,1,1,0,str,lbl_8036BA20,lbl_8036BA18);
fn_8001003C((s32)(lbl_8036BA9C+lbl_8036BA98),(s32)y,1,1,0,Msg_Expand(b),lbl_8036BA20,lbl_8036BA18);
x=lbl_8036BAA0;
x=x+lbl_8036BA98;
fn_8001003C((s32)x,(s32)y,1,1,0,StaffRoll_str+0x350,lbl_8036BA20,lbl_8036BA18,*(u16*)(ent+2));
fn_8001003C((s32)(lbl_8036BAA4+x),(s32)y,32,1,0,StaffRoll_str+0x354,lbl_8036BA20,lbl_8036BA18,Msg_Expand(StaffRoll_str+0x357));
tx=lbl_8036BAA8+lbl_8036BA98;scale=lbl_8036BA20;zero=lbl_8036BA18;
time=*(u32*)(ent+4);
hours=time/3600;time%=3600;seconds=time%60;minutes=time/60;
fn_8001003C((s32)tx,(s32)y,33,1,0,StaffRoll_str+0x364,scale,zero,hours,minutes,seconds);
}
}
}
#pragma global_optimizer on

void fn_801FA478(void *arg0) {
    s32 temp_r0;

    M2C_FIELD(arg0, f32 *, 0x3C) = (f32) (M2C_FIELD(arg0, f32 *, 0x3C) - M2C_FIELD(arg0, f32 *, 0x44));
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x48) - 1;
    M2C_FIELD(arg0, s32 *, 0x48) = temp_r0;
    if (temp_r0 < 0) {
        Process_ClearFunc();
    }
}

void fn_801FA4B8(s32 arg0, s32 arg1) {
    extern u8 lbl_8029B2F4[];
    extern f32 lbl_8036BA00;
    void *Process_Create(void *, s32);
    struct Fields { s32 a; s32 pad0; f32 b; s32 pad1; s32 pad2; s32 c; };
    void *temp;
    s32 zero;
    f32 f;

    temp = Process_Create(lbl_8029B2F4, arg1);
    if (temp != NULL) {
        zero = 0;
        f = lbl_8036BA00;
        ((struct Fields *)((u8 *)temp + 0x30))->a = zero;
        ((struct Fields *)((u8 *)temp + 0x30))->b = f;
        ((struct Fields *)((u8 *)temp + 0x30))->c = arg0;
    }
}

void fn_801FA508(void *arg0) {
    void *x = *(void **)((u8 *)arg0 + 0x30);
    if (x != NULL) {
        fn_8003F670(x);
    }
}

void fn_801FA534(void *arg0)
{
    void *Archive_Load(void *);
    s32 *Hash_Lookup(void *);
    extern u8 lbl_8029B2D8[];
    extern u8 StaffRoll_str[];
    s32 *tmp;

    *(void **)((u8 *)arg0 + 0x30) = Archive_Load(*(void **)(lbl_8029B2D8 + 4));
    tmp = Hash_Lookup(StaffRoll_str + 0x373);
    *(s32 *)((u8 *)arg0 + 0x34) = *tmp;
    *(f32 *)((u8 *)arg0 + 0x3C) =
        *(f32 *)((u8 *)arg0 + 0x38) + (f32)(u32)(*(s32 *)((u8 *)arg0 + 0x34) * 0x30);
    *(f32 *)((u8 *)arg0 + 0x40) =
        *(f32 *)((u8 *)arg0 + 0x3C) / (f32)*(s32 *)((u8 *)arg0 + 0x44);
}

__declspec(section ".rodata") static const char staff_fmt[] = "#F04%s";

#pragma global_optimizer off
void StaffRoll_Draw(void *proc) {
    /* Draw visible staff-roll credit lines for the current scroll position. */
    void Prim2D_Begin(void);
    void Prim2D_SetTransform(f32, f32, f32, f32);
    void Prim2D_SetColorByte(s32);
    void Prim2D_SetAlphaByte(s32);
    void Prim2D_PrepareTex(void);
    void Process_Goto(void *, s32);
    void *Hash_Lookup(void *);
    void Prim2D_SetTex(s32, s32);
    s16 Text_MeasureWidth(void *, s32, f32);
    void Text_Draw(s32, s32, s32, void *, ...);
    f64 fmod(f64, f64);
    extern s32 gUiInputFlags;
    extern f32 lbl_8036BA18;
    extern f32 lbl_8036BA1C;
    extern f32 lbl_8036BA20;
    extern f64 lbl_8036BA28;
    extern f64 lbl_8036BA30;
    extern f32 lbl_8036BA38;
    extern f64 lbl_8036BA10;
    extern f32 lbl_8036BA00;
    extern f32 lbl_8036BAAC;
    extern f32 lbl_8036BAB0;
    extern u8 StaffRoll_str[];

    typedef struct {
        void *left;
        void *center;
        void *right;
    } CreditLine;

    f32 limit;
    f32 scrollY;
    f32 lineHeight;
    f32 period;
    s16 width;
    u8 visible;
    CreditLine *line;
    u32 i;

    if (gUiInputFlags & 1) {
        Process_Goto(proc, 1);
        return;
    }
    Prim2D_Begin();
    Prim2D_SetTransform(lbl_8036BA18, lbl_8036BA18, lbl_8036BA1C, lbl_8036BA20);
    Prim2D_SetColorByte(0xFF);
    Prim2D_SetAlphaByte(0x80);
    Prim2D_PrepareTex();
    lineHeight = *(f32 *)((u8 *)proc + 0x38);
    period = (f32)fmod(lbl_8036BA28, lbl_8036BA30);
    scrollY = (f32)(s32)(period * (lineHeight + lbl_8036BA38 / period)) / period;
    line = (CreditLine *)Hash_Lookup(StaffRoll_str + 0x387);
    limit = lbl_8036BA00;
    lineHeight = lbl_8036BAAC;
    for (i = 0; i < *(u32 *)((u8 *)proc + 0x34); i++) {
        visible = 0;
        if (scrollY <= limit) {
            if (lbl_8036BA18 < scrollY + lbl_8036BAAC) {
                visible = 1;
            }
        }
        if (visible != 0) {
            Prim2D_Begin();
            Prim2D_SetTex(0, 0x13);
            Prim2D_PrepareTex();
            if ((u32)line->left != 0U) {
                width = Text_MeasureWidth(line->left, -1, lbl_8036BA20);
                Text_Draw((s32)(f32)(0x120 - width), (s32)scrollY, 1, line->left);
            }
            if ((u32)line->center != 0U) {
                width = Text_MeasureWidth(line->center, -1, lbl_8036BA20);
                Text_Draw((s32)(f32)(0x130 - (width >> 1)), (s32)scrollY, 1, line->center);
            }
            if ((u32)line->right != 0U) {
                Text_MeasureWidth(line->right, -1, lbl_8036BA20);
                Text_Draw((s32)lbl_8036BAB0, (s32)scrollY, 1, (void *)(StaffRoll_str + 0x39A), line->right);
            }
        }
        scrollY += lineHeight;
        line++;
    }
}
#pragma global_optimizer reset
void fn_801FA874(void *arg0) {
    s32 temp_r0;

    M2C_FIELD(arg0, f32 *, 0x38) = (f32) (M2C_FIELD(arg0, f32 *, 0x38) - M2C_FIELD(arg0, f32 *, 0x40));
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x44) - 1;
    M2C_FIELD(arg0, s32 *, 0x44) = temp_r0;
    if (temp_r0 < 0) {
        Process_ClearFunc();
    }
}

void fn_801FA8B4(void *arg0, s32 (*compare)(void *, void *)) {
    typedef struct Node {
        struct Node *prev;
        struct Node *next;
        void *unit;
        void *actor;
    } Node;

    typedef struct List {
        s32 count;
        Node sentinel;
    } List;

    void fn_801FB428(void *, void *, s32 (*)(void *, void *));
    void fn_800616A0(void *);
    void Heap_Free(void *);

    List *list;
    List other;
    Node *first;
    Node *second;
    Node *node;
    Node *last;
    Node *previous;
    Node *next;
    Node *temp;
    s32 half;
    s32 i;

    list = (List *)arg0;

    switch (list->count) {
    case 0:
    case 1:
        break;

    case 2:
        first = list->sentinel.next;
        second = first->next;

        if (compare(
                (u8 *)second + 8,
                (u8 *)first + 8
            )) {
            temp = first->prev;
            first->prev = first->next;
            first->next = temp;

            temp = second->prev;
            second->prev = second->next;
            second->next = temp;

            temp = list->sentinel.prev;
            list->sentinel.prev = list->sentinel.next;
            list->sentinel.next = temp;
        }
        break;

    default:
        half = (u32)list->count >> 1;
        node = list->sentinel.next;

        for (i = 0; i < half; i++) {
            node = node->next;
        }

        other.count = 0;
        other.sentinel.prev = &other.sentinel;
        other.sentinel.next = &other.sentinel;

        last = list->sentinel.prev;
        previous = node->prev;

        previous->next = last->next;
        last->next->prev = previous;

        other.sentinel.prev->next = node;
        node->prev = other.sentinel.prev;

        other.sentinel.prev = last;
        last->next = &other.sentinel;

        other.count = list->count - half;
        list->count = half;

        fn_801FA8B4(list, compare);
        fn_801FA8B4(&other, compare);

        fn_801FB428(list, &other, compare);

        first = other.sentinel.next;

        if (first != &other.sentinel) {
            last = other.sentinel.prev;

            first->prev->next = last->next;
            last->next->prev = first->prev;

            while (first != &other.sentinel) {
                if (&first->unit != NULL) {
                    if (first->actor != NULL) {
                        fn_800616A0(first->actor);
                    }
                }

                next = first->next;
                Heap_Free(first);
                first = next;

                other.count--;
            }
        }
        break;
    }
}

#pragma peephole off
void fn_801FAA9C(void *arg0, void *arg1, u32 arg2, void *arg3) {
    typedef struct {
        s32 a;
        s32 b;
    } Elem;
    typedef struct {
        u32 cap;
        u32 size;
        Elem *data;
    } Vec;
    void Heap_Free(void *);
    void *Heap_Alloc(u32);
    void StaffRoll_VecClear(Vec *);
    void abort(void);
    void fprintf(void *, const char *, ...);
    extern char __files[];
    extern char StaffRoll_str[];

    Vec *vec;
    Elem *fill;
    u32 count;
    Elem *pos;
    Vec tmp;

    count = arg2;
    vec = (Vec *)arg0;
    pos = (Elem *)arg1;
    fill = (Elem *)arg3;
    if (count == 0) {
        return;
    }
    if (count > 0x1FFFFFFFU || vec->size > 0x1FFFFFFFU - count) {
        char *files = __files;
        char *msg = StaffRoll_str;
        fprintf(files + 0xA0, msg + 0x3A1);
        abort();
    }
    if (vec->size + count <= vec->cap) {
        Elem *dst = vec->data + vec->size;
        Elem *fill_out = fill;
        s32 n = dst - pos;
        if (count > (u32)n) {
            Elem *p = dst;
            Elem *src;
            u32 ctr;
            for (ctr = count - (u32)n; ctr != 0; ctr--) {
                if (p != NULL) {
                    *p = *fill;
                }
                p++;
                count--;
                vec->size++;
            }
            for (src = pos; src < dst; src++, p++) {
                if (p != NULL) {
                    *p = *src;
                }
                vec->size++;
            }
        } else {
            Elem *src = dst - count;
            Elem *p = dst;
            u32 words;
            u8 *from_b;
            u8 *to_b;
            s32 off;

            for (; src < dst; src++, p++) {
                if (p != NULL) {
                    *p = *src;
                }
                vec->size++;
            }
            off = (n - (s32)count) * 8;
            if ((u8 *)dst - off <= (u8 *)fill && (u8 *)fill < (u8 *)dst) {
                fill_out = (Elem *)((u8 *)fill + count * 8);
            }
            from_b = (u8 *)pos + off;
            to_b = (u8 *)dst;
            if (from_b > (u8 *)pos) {
                words = (u32)(from_b + 7 - (u8 *)pos) >> 3;
                for (; (words >> 3) != 0;) {
                    u32 ctr = words >> 3;
                    do {
                        to_b[-8] = from_b[-8];
                        *(u16 *)(to_b - 6) = *(u16 *)(from_b - 6);
                        *(s32 *)(to_b - 4) = *(s32 *)(from_b - 4);
                        to_b[-0x10] = from_b[-0x10];
                        *(u16 *)(to_b - 0xe) = *(u16 *)(from_b - 0xe);
                        *(s32 *)(to_b - 0xc) = *(s32 *)(from_b - 0xc);
                        to_b[-0x18] = from_b[-0x18];
                        *(u16 *)(to_b - 0x16) = *(u16 *)(from_b - 0x16);
                        *(s32 *)(to_b - 0x14) = *(s32 *)(from_b - 0x14);
                        to_b[-0x20] = from_b[-0x20];
                        *(u16 *)(to_b - 0x1e) = *(u16 *)(from_b - 0x1e);
                        *(s32 *)(to_b - 0x1c) = *(s32 *)(from_b - 0x1c);
                        to_b[-0x28] = from_b[-0x28];
                        *(u16 *)(to_b - 0x26) = *(u16 *)(from_b - 0x26);
                        *(s32 *)(to_b - 0x24) = *(s32 *)(from_b - 0x24);
                        to_b[-0x30] = from_b[-0x30];
                        *(u16 *)(to_b - 0x2e) = *(u16 *)(from_b - 0x2e);
                        *(s32 *)(to_b - 0x2c) = *(s32 *)(from_b - 0x2c);
                        to_b[-0x38] = from_b[-0x38];
                        *(u16 *)(to_b - 0x36) = *(u16 *)(from_b - 0x36);
                        *(s32 *)(to_b - 0x34) = *(s32 *)(from_b - 0x34);
                        to_b[-0x40] = from_b[-0x40];
                        *(u16 *)(to_b - 0x3e) = *(u16 *)(from_b - 0x3e);
                        *(s32 *)(to_b - 0x3c) = *(s32 *)(from_b - 0x3c);
                        from_b -= 0x40;
                        to_b -= 0x40;
                    } while (--ctr != 0);
                    break;
                }
                words &= 7;
                if (words != 0) {
                    do {
                        to_b[-8] = from_b[-8];
                        *(u16 *)(to_b - 6) = *(u16 *)(from_b - 6);
                        *(s32 *)(to_b - 4) = *(s32 *)(from_b - 4);
                        from_b -= 8;
                        to_b -= 8;
                    } while (--words != 0);
                }
            }
        }
        {
            Elem *out = pos;
            u32 left = count;
            if (left != 0) {
                u32 ctr = left >> 3;
                if (ctr != 0) {
                    do {
                        ((u8 *)out)[0] = ((u8 *)fill_out)[0];
                        *(u16 *)((u8 *)out + 2) = *(u16 *)((u8 *)fill_out + 2);
                        *(s32 *)((u8 *)out + 4) = *(s32 *)((u8 *)fill_out + 4);
                        ((u8 *)out)[8] = ((u8 *)fill_out)[0];
                        *(u16 *)((u8 *)out + 0xa) = *(u16 *)((u8 *)fill_out + 2);
                        *(s32 *)((u8 *)out + 0xc) = *(s32 *)((u8 *)fill_out + 4);
                        ((u8 *)out)[0x10] = ((u8 *)fill_out)[0];
                        *(u16 *)((u8 *)out + 0x12) = *(u16 *)((u8 *)fill_out + 2);
                        *(s32 *)((u8 *)out + 0x14) = *(s32 *)((u8 *)fill_out + 4);
                        ((u8 *)out)[0x18] = ((u8 *)fill_out)[0];
                        *(u16 *)((u8 *)out + 0x1a) = *(u16 *)((u8 *)fill_out + 2);
                        *(s32 *)((u8 *)out + 0x1c) = *(s32 *)((u8 *)fill_out + 4);
                        ((u8 *)out)[0x20] = ((u8 *)fill_out)[0];
                        *(u16 *)((u8 *)out + 0x22) = *(u16 *)((u8 *)fill_out + 2);
                        *(s32 *)((u8 *)out + 0x24) = *(s32 *)((u8 *)fill_out + 4);
                        ((u8 *)out)[0x28] = ((u8 *)fill_out)[0];
                        *(u16 *)((u8 *)out + 0x2a) = *(u16 *)((u8 *)fill_out + 2);
                        *(s32 *)((u8 *)out + 0x2c) = *(s32 *)((u8 *)fill_out + 4);
                        ((u8 *)out)[0x30] = ((u8 *)fill_out)[0];
                        *(u16 *)((u8 *)out + 0x32) = *(u16 *)((u8 *)fill_out + 2);
                        *(s32 *)((u8 *)out + 0x34) = *(s32 *)((u8 *)fill_out + 4);
                        ((u8 *)out)[0x38] = ((u8 *)fill_out)[0];
                        *(u16 *)((u8 *)out + 0x3a) = *(u16 *)((u8 *)fill_out + 2);
                        *(s32 *)((u8 *)out + 0x3c) = *(s32 *)((u8 *)fill_out + 4);
                        out = (Elem *)((u8 *)out + 0x40);
                    } while (--ctr != 0);
                }
                left &= 7;
                if (left != 0) {
                    do {
                        ((u8 *)out)[0] = ((u8 *)fill_out)[0];
                        *(u16 *)((u8 *)out + 2) = *(u16 *)((u8 *)fill_out + 2);
                        *(s32 *)((u8 *)out + 4) = *(s32 *)((u8 *)fill_out + 4);
                        out = (Elem *)((u8 *)out + 8);
                    } while (--left != 0);
                }
            }
        }
        return;
    }

    {
        u32 cap;
        Elem *p;
        Elem *dst;
        Elem *src;
        Elem *end;
        u32 t;
        Elem *tp;
        u32 ts;
        u32 z;

        z = 0;
        tmp.cap = z;
        tmp.size = z;
        tmp.data = (Elem *)z;
        cap = 1;
        z = vec->cap;
        if (z != 0) {
            cap = z;
        }
        while (vec->size + count > cap) {
            if (cap < 0x0FFFFFFFU) {
                cap *= 2;
            } else {
                cap = 0x1FFFFFFFU;
            }
        }
        p = (Elem *)Heap_Alloc(cap * 8);
        if (p == NULL) {
            char *files = __files;
            char *msg = StaffRoll_str;
            fprintf(files + 0xA0, msg + 0x3BE);
            abort();
        }
        tmp.data = p;
        tmp.cap = cap;
        dst = p;
        src = vec->data;
        end = vec->data + vec->size;
        for (; src < pos; src++, dst++) {
            if (dst != NULL) {
                *dst = *src;
            }
            tmp.size++;
        }
        {
            u32 ctr;
            for (ctr = count; ctr != 0; ctr--) {
                if (dst != NULL) {
                    *dst = *fill;
                }
                dst++;
                tmp.size++;
            }
        }
        for (; src < end; src++, dst++) {
            if (dst != NULL) {
                *dst = *src;
            }
            tmp.size++;
        }
        if (&tmp != vec) {
            t = tmp.cap;
            tmp.cap = vec->cap;
            vec->cap = t;
            tp = tmp.data;
            tmp.data = vec->data;
            vec->data = tp;
            ts = tmp.size;
            tmp.size = vec->size;
            vec->size = ts;
        }
        StaffRoll_VecClear(&tmp);
        if (tmp.data != NULL) {
            Heap_Free(tmp.data);
        }
    }
}
#pragma peephole on
/* Grow the staff-roll vector so it can hold at least newCap elements. */
void StaffRoll_VecReserve(void *arg0, u32 newCap) {
    typedef struct {
        s32 unk0;
        s32 unk4;
    } Elem;
    typedef struct {
        u32 cap;
        s32 size;
        Elem *data;
    } Vec;
    void Heap_Free(void *);
    void *Heap_Alloc(u32);
    void StaffRoll_VecClear(Vec *);
    M2C_UNK abort(void);
    M2C_UNK fprintf(void *, const char *, ...);
    extern char __files[];
    extern char StaffRoll_str[];
    Vec *vec = arg0;
    Vec tmp;
    Elem *p;
    Elem *src;
    Elem *dst;
    Elem *end;
    u32 t;
    Elem *tp;
    s32 ts;

    if (newCap > vec->cap) {
        if (newCap > 0x1FFFFFFF) {
            fprintf(__files + 0xA0, StaffRoll_str + 0x3D8);
            abort();
        }
        tmp.cap = 0;
        tmp.size = 0;
        tmp.data = NULL;
        p = Heap_Alloc(newCap * 8);
        if (p == NULL) {
            fprintf(__files + 0xA0, StaffRoll_str + 0x3BE);
            abort();
        }
        tmp.data = p;
        dst = p;
        tmp.cap = newCap;
        src = vec->data;
        end = src + vec->size;
        for (; src < end; src++, dst++) {
            if (dst != NULL) {
                *dst = *src;
            }
            tmp.size++;
        }
        if (&tmp != vec) {
            t = tmp.cap;
            tmp.cap = vec->cap;
            vec->cap = t;
            tp = tmp.data;
            tmp.data = vec->data;
            vec->data = tp;
            ts = tmp.size;
            tmp.size = vec->size;
            vec->size = ts;
        }
        StaffRoll_VecClear(&tmp);
        if (tmp.data != NULL) {
            Heap_Free(tmp.data);
        }
    }
}

void *fn_801FB1C0(void *arg0, s16 arg1) {
    void Heap_Free(void *);
    void StaffRoll_VecClear(void *);

    if (arg0 != NULL) {
        StaffRoll_VecClear(arg0);
        if (M2C_FIELD(arg0, void **, 8) != NULL) {
            Heap_Free(M2C_FIELD(arg0, void **, 8));
        }
        if (arg1 > 0) {
            Heap_Free(arg0);
        }
    }
    return arg0;
}

void fn_801FB220(void **ret, s32 *list, void **start, void **end) {
    struct Node {
        struct Node *prev;
        struct Node *next;
        s32 owner;
        void *obj;
    };
    void fn_800616A0(void *);
    void Heap_Free(void *);
    struct Node *first;
    struct Node *last;
    struct Node *a;
    struct Node *node;
    void **value;

    first = (struct Node *)*start;
    last = (struct Node *)*end;
    if (first == last) {
        *ret = last;
        return;
    }
    a = last->prev;
    first->prev->next = a->next;
    a->next->prev = first->prev;
    while (*start != *end) {
        value = (void **)((u8 *)*(struct Node **)start + 8);
        if (value != NULL) {
            if (value[1] != NULL) {
                fn_800616A0(value[1]);
            }
        }
        node = (struct Node *)*start;
        *start = node->next;
        Heap_Free(node);
        (*list)--;
    }
    *ret = *end;
}

#pragma cplusplus on
#pragma use_lmw_stmw on
extern "C" void *Heap_Alloc(u32);
extern "C" void Heap_Free(void *);
extern "C" void fn_800506E0(s32, s32, void *);
extern "C" void GActor_Finalize(void *);
extern "C" void fn_800616A0(void *);
extern "C" void *GActor_Create(void);
extern "C" s32 fn_800639B4(void);
extern "C" M2C_UNK abort(void);
extern "C" M2C_UNK fprintf(void *, const char *, ...);
extern "C" void StaffRoll_ListInsertActor(void **outNode, s32 *listHead, void ***insertBefore, s32 *unitPtr) {
    struct Obj {
        u32 flags;
        s32 unk4;
        u8 pad8[0x3C];
        s32 anim;
    };
    struct Value {
        s32 unit;
        Obj *actor;
    };
    struct Node {
        Node *prev;
        Node *next;
        Value value;
    };
    struct Holder {
        void *list;
        Node *node;
        Holder(void *l, Node *n) : list(l), node(n) {}
        ~Holder() {
            if (node != 0) {
                Heap_Free(node);
            }
        }
    };
    extern char __files[];
    extern char StaffRoll_str[];
    Value *value;
    Node *node;
    s32 unit;
    void *list;
    Obj *actor;
    Node *pos;
    Node *n;

    // Create a GActor for the unit and splice its node into the staff-roll list.
    list = listHead + 1;
    node = (Node *)Heap_Alloc(0x10);
    if (node == 0) {
        fprintf(__files + 0xA0, StaffRoll_str + 0x3BE);
        abort();
    }
    {
        Holder h(list, node);
        value = &h.node->value;
        if (value != 0) {
            unit = *unitPtr;
            value->unit = unit;
            value->actor = 0;
            if (value->actor != 0) {
                fn_800616A0(value->actor);
            }
            value->actor = (Obj *)GActor_Create();
            value->actor->unk4 = unit + 0x1C;
            actor = value->actor;
            actor->flags |= 0x50028400;
            fn_800506E0(unit, 0, actor);
            value->actor->anim = fn_800639B4();
            GActor_Finalize(value->actor);
        }
        pos = (Node *)*insertBefore;
        n = h.node;
        h.node = 0;
        pos->prev->next = n;
        n->prev = pos->prev;
        pos->prev = n;
        n->next = pos;
        (*listHead)++;
        *outNode = n;
    }
}

#pragma use_lmw_stmw reset
#pragma cplusplus reset

int fn_801FB410(void *arg0) {
    u32 *ptr;

    ptr = (u32 *)((u8 *)arg0 + 0x4);
    *(u32 *)arg0 = 0;
    ptr[1] = (u32)ptr;
    ptr[0] = (u32)ptr;
}

void fn_801FB428(void *arg0, void *arg1, s32 (*compare)(void *, void *))
{
    typedef struct Node {
        struct Node *prev;
        struct Node *next;
    } Node;

    typedef struct List {
        s32 count;
        Node sentinel;
        Node *first;
    } List;

    extern void fn_801FB580(void *, void *, void *);

    List *dst;
    List *src;
    Node *dstNode;
    Node *srcNode;
    Node *dstEnd;
    Node *srcEnd;
    Node *rangeEnd;
    Node *last;
    Node *prev;
    s32 count;

    dst = (List *)arg0;
    src = (List *)arg1;

    if (dst == src) {
        return;
    }

    dstNode = dst->first;
    dstEnd = &dst->sentinel;
    srcNode = src->first;
    srcEnd = &src->sentinel;

    while (dstNode != dstEnd) {
        if (srcNode != srcEnd) {
            if (compare((u8 *)srcNode + 8, (u8 *)dstNode + 8)) {
                rangeEnd = srcNode->next;
                count = 1;

                while (rangeEnd != srcEnd) {
                    if (!compare((u8 *)rangeEnd + 8, (u8 *)dstNode + 8)) {
                        break;
                    }

                    rangeEnd = rangeEnd->next;
                    count++;
                }

                last = rangeEnd->prev;
                prev = srcNode->prev;

                prev->next = last->next;
                last->next->prev = prev;

                dstNode->prev->next = srcNode;
                srcNode->prev = dstNode->prev;

                srcNode = rangeEnd;

                dstNode->prev = last;
                last->next = dstNode;

                src->count -= count;
                dst->count += count;
            }
        }

        dstNode = dstNode->next;

        if (srcNode == srcEnd) {
            break;
        }
    }

    if (srcNode != srcEnd) {
        fn_801FB580(dst, &dstNode, src);
    }
}

#pragma peephole off
void StaffRoll_VecClear(u32 *arg0) {
    u8 *start = (u8 *)arg0[2];
    u8 *end = start + (arg0[1] << 3);
    while (end > start) {
        end -= 8;
    }
    arg0[1] = 0;
}
#pragma peephole reset
void fn_801FB580(u32 *arg0, void **arg1, void *arg2)
{
    struct ListNode {
        struct ListNode *prev;
        struct ListNode *next;
    };
    struct ListNode *list;
    struct ListNode *sentinel;
    struct ListNode *next;
    struct ListNode *prev;

    if (*(u32 *)arg2 == 0) {
        return;
    }

    sentinel = (struct ListNode *)((u8 *)arg2 + 4);
    list = *(struct ListNode **)arg1;
    next = sentinel->next;
    prev = sentinel->prev;

    sentinel->next = sentinel;
    sentinel->prev = sentinel;

    list->prev->next = next;
    next->prev = list->prev;
    list->prev = prev;
    prev->next = list;

    *arg0 = *arg0 + *(u32 *)arg2;
    *(u32 *)arg2 = 0;
}

#pragma use_lmw_stmw on
void fn_801FB5D8(s32 *arg0, u8 *arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    void GXClearVtxDesc(void);
    void GXSetVtxDesc(s32, s32);
    void GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
    void GXSetCullMode(s32);
    void GXSetBlendMode(s32, s32, s32, s32, s32, s32, s32);
    void GXSetChanMatColor(s32, s32 *);
    void GXSetNumTevStages(s32);
    void GXSetTevOrder(s32, s32, s32, s32);
    void GXSetTevColorIn(s32, s32, s32, s32, s32);
    void GXSetTevColorOp(s32, s32, s32, s32, s32, s32);
    void GXSetTevAlphaIn(s32, s32, s32, s32, s32);
    void GXSetTevAlphaOp(s32, s32, s32, s32, s32, s32);
    void GXSetNumChans(s32);
    void fn_802201A8(s32, s32, s32, s32, s32, s32);
    u16 fn_802072A0(void);
    void *fn_801FBF98(void *, void *, u16 *, u32 (*)(void *, u16));
    u32 fn_801FB9CC(void *, u16);
    void fn_80222644(void *, void *, s32, s32, s32, s32, s32, s32);
    void fn_80222C50(void *, s32);
    void GXBegin(s32, s32, s32);
    extern f32 lbl_8036BAB8;
    extern f64 lbl_8036BAC0;
    extern u32 lbl_80368410[2];

    u8 tex[0x20];
    s32 color;
    u16 code;
    s32 *var_r21;
    u8 *var_r20;
    u8 *var_r22;
    s32 var_r24;
    s32 var_r25;
    s32 var_r23;
    s32 var_r26;
    s32 var_r27;
    s32 var_r28;
    s32 var_r30;
    u32 *var_r29;
    void *var_r31;
    void *found;
    void *end;
    u8 temp_r3;
    u8 temp_r0;
    u8 temp_r0_2;
    u8 var_r0;
    s16 var_r4;
    f32 temp_f1;
    s32 conv_hi;
    s32 conv_lo;
    volatile u8 *wg;
    s16 temp_r6;
    f32 fadv;

    var_r21 = arg0;
    var_r20 = arg1;

    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xD, 1);
    GXSetVtxAttrFmt(0, 9, 1, 3, 0);
    GXSetVtxAttrFmt(0, 0xD, 1, 0, 0);
    GXSetCullMode(1);
    GXSetBlendMode(4, 0, 0, 0, 0, 0, 2);
    color = *var_r21;
    GXSetChanMatColor(4, &color);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevColorIn(0, 0xF, 0xF, 0xF, 0xA);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 4, 5, 7);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetNumChans(1);
    fn_802201A8(0, 1, 4, 0x3C, 0, 0x7D);

    var_r22 = var_r20;
    temp_f1 = lbl_8036BAB8 * farg3;
    var_r24 = (s32)farg1;
    var_r28 = (s16)(s32)farg2;
    var_r23 = (s32)temp_f1;
    var_r27 = (s16)(s32)temp_f1;
    var_r25 = (s32)farg0;
    var_r26 = (s16)var_r23;
    var_r30 = (s16)var_r24 + var_r26;
    var_r29 = lbl_80368410;

    goto loop_check;
loop_body:
    if ((s8)temp_r3 == 0xA) {
        var_r30 += var_r26;
        var_r24 += var_r23;
        var_r22 += 1;
        var_r25 = (s32)farg0;
        goto loop_check;
    }
    if (fn_802072A0() != 1) {
        var_r4 = (s8)var_r22[0];
        var_r22 += 1;
    } else {
        temp_r0 = var_r22[0];
        if (((temp_r0 >= 0x81U && temp_r0 <= 0x9FU) || (temp_r0 >= 0xE0U && temp_r0 <= 0xFCU))
            && (((temp_r0_2 = var_r22[1], temp_r0_2 >= 0x40U) && (temp_r0_2 <= 0x7EU))
                || ((temp_r0_2 >= 0x80U) && (temp_r0_2 <= 0xFCU)))) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        if (var_r0 == 0) {
            var_r4 = (s8)var_r22[0];
            var_r22 += 1;
        } else {
            var_r4 = *(s16 *)var_r22;
            var_r22 += 2;
        }
    }
    var_r31 = (void *)var_r29[0];
    code = (u16)var_r4;
    end = (u8 *)var_r31 + var_r29[1] * 0x140;
    found = fn_801FBF98(var_r31, end, &code, fn_801FB9CC);
    if (end == found || *(u16 *)((u8 *)found + 0x120) != code) {
        found = var_r31;
    }
    fn_80222644(tex, found, 0x18, 0x18, 0, 0, 0, 0);
    fn_80222C50(tex, 0);
    GXBegin(0x80, 0, 4);
    wg = (volatile u8 *)0xCC010000;
    temp_r6 = (s16)var_r25 + (s16)var_r27;
    *(volatile s16 *)(wg - 0x8000) = (s16)var_r25;
    *(volatile s16 *)(wg - 0x8000) = (s16)var_r24;
    *(volatile s16 *)(wg - 0x8000) = (s16)var_r28;
    *(wg - 0x8000) = 0;
    *(wg - 0x8000) = 0;
    *(volatile s16 *)(wg - 0x8000) = temp_r6;
    *(volatile s16 *)(wg - 0x8000) = (s16)var_r24;
    *(volatile s16 *)(wg - 0x8000) = (s16)var_r28;
    *(wg - 0x8000) = 1;
    *(wg - 0x8000) = 0;
    *(volatile s16 *)(wg - 0x8000) = temp_r6;
    *(volatile s16 *)(wg - 0x8000) = (s16)var_r30;
    *(volatile s16 *)(wg - 0x8000) = (s16)var_r28;
    *(wg - 0x8000) = 1;
    *(wg - 0x8000) = 1;
    *(volatile s16 *)(wg - 0x8000) = (s16)var_r25;
    *(volatile s16 *)(wg - 0x8000) = (s16)var_r30;
    *(volatile s16 *)(wg - 0x8000) = (s16)var_r28;
    *(wg - 0x8000) = 0;
    *(wg - 0x8000) = 1;
    conv_hi = 0x43300000;
    conv_lo = *(u16 *)((u8 *)found + 0x122);
    fadv = (f32)(*(f64 *)&conv_hi - lbl_8036BAC0);
    fadv = fadv * farg3;
    var_r25 = var_r25 + (s32)fadv;
loop_check:
    temp_r3 = *var_r22;
    if ((s8)temp_r3 != 0) {
        goto loop_body;
    }
}
u32 fn_801FB9CC(void *arg0, u16 arg1) {
    return *(u16 *)((u8 *)arg0 + 0x120) < arg1;
}

#pragma opt_common_subs off
#pragma global_optimizer off
s32 fn_801FB9E0(u8 *arg0)
{
    u16 fn_802072A0(s32);

    if ((s8)*arg0 == 0) {
        return 0;
    }
    {
        s32 var_r31;
        u8 *var_r30;
        u8 temp_r3;
        u8 temp_r0;
        u8 temp_r0_2;
        u8 var_r0;

        var_r30 = arg0;
        var_r31 = 0x18;
        goto loop_check;
    loop_body:
        if ((s32)(s8)temp_r3 == 0xA) {
            var_r31 += 0x18;
            var_r30 += 1;
            goto loop_check;
        }
        if (fn_802072A0(temp_r3) != 1) {
            var_r30 += 1;
            goto loop_check;
        }
        temp_r0 = var_r30[0];
        if ((((temp_r0 >= 0x81U) && (temp_r0 <= 0x9FU)) || ((temp_r0 >= 0xE0U) && (temp_r0 <= 0xFCU)))
            && (((temp_r0_2 = var_r30[1], temp_r0_2 >= 0x40U) && (temp_r0_2 <= 0x7EU))
                || ((temp_r0_2 >= 0x80U) && (temp_r0_2 <= 0xFCU)))) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        if (var_r0 == 0) {
            var_r30 += 1;
        } else {
            var_r30 += 2;
        }
    loop_check:
        temp_r3 = *var_r30;
        if ((s8)temp_r3 != 0) {
            goto loop_body;
        }
        return var_r31;
    }
}
#pragma global_optimizer reset
s32 fn_801FBAD4(u8 *arg0) {
    u16 fn_802072A0(s32);
    void *fn_801FBF98(void *,void *,u16 *,u32 (*)(void *,u16));
    u32 fn_801FB9CC(void *,u16);
    extern u32 lbl_80368410[2];
    u16 code;
    u8 *end;
    u8 *base;
    u32 *table;
    s32 maximum;
    s32 width;
    register u8 *p;
    u8 ch,a,b,multibyte;
    s32 c;
    u8 *found;
    maximum=0;
    p=arg0;
    width=0;
    table=lbl_80368410;
    while((s8)(ch=*p)!=0) {
        if((s8)ch==10) {
            if(maximum<width) maximum=width;
            width=0;
            p++;
            continue;
        }
        if(fn_802072A0(ch)!=1) {
            { c=*(s8*)p; p++; }
        } else {
            a=p[0];
            if(((a>=0x81U && a<=0x9FU)||(a>=0xE0U && a<=0xFCU)) &&
               (((b=p[1],b>=0x40U)&&b<=0x7EU)||(b>=0x80U && b<=0xFCU))) multibyte=1;
            else multibyte=0;
            if(!multibyte) { c=*(s8*)p; p++; }
            else { c=*(u16*)p; p+=2; }
        }
        base=(u8*)lbl_80368410[0];
        end=base+table[1]*0x140;
        code=c;
        found=fn_801FBF98(base,end,&code,fn_801FB9CC);
        if(end==found || *(u16*)(found+0x120)!=code) found=base;
        width+=*(u16*)(found+0x122);
    }
    return maximum<width?width:maximum;
}

#pragma opt_common_subs on
extern u16 lbl_8029B520[];
s32 fn_801FBC30(s32 arg0) {
    return ((s32 **)lbl_8029B520)[1][arg0];
}

void fn_801FBC84(void);

void fn_801FBC48(void) {
    extern u32 lbl_80368410[2];
    u32 *p = lbl_80368410;
    if (p[0] == 0) {
        p[0] = 0;
        p[1] = 0;
        fn_801FBC84();
    }
}

#pragma use_lmw_stmw on
void fn_801FBC84(void) {
    void DCFlushRange(void *, u32);
    void fn_800C4588(s32);
    s32 fn_800C45B8(s32, char *, s32);
    void *fn_800C4604(s32, s32, char *, s32);
    void fn_800DE9FC(void *);
    void Tree_Destroy(void *, void *);
    void Tree_InsertKey(void *, void *, u16 *);
    void Tree_Init(void *, void *, void *);
    u16 fn_802072A0(void);
    void fn_80207628(s32, s32);
    void fn_802078A4(u8 *, void *, s32, s32, s32 *);
    void *memset(void *, s32, u32);
    extern char lbl_80281420[];
    extern u8 lbl_8029B478[];
    extern u16 lbl_8029B520[];
    extern u32 lbl_80368410[2];

    struct Tree {
        s32 count;
        void *root;
        void *first;
    } tree;
    u8 sp30[8];
    u8 sp28[8];
    u8 sp20[8];
    u8 sp1C[4];
    u8 sp18b[4];
    u8 sp14b[4];
    u32 spC;
    u32 sp8;
    s16 sp12;
    s16 sp10;
    void *tables;
    void *list;
    u8 *str;
    s32 h1;
    s32 h2;
    void *glyphs;
    u32 *lbl;
    void *end;
    u8 temp_r3;
    u8 temp_r0;
    u8 temp_r0_2;
    u8 var_r0;
    u16 code;
    s8 tmp_ch;

    Tree_Init(&tree, &sp8, &spC);
    tables = (void *)lbl_8029B520;
    goto outer_cond;
outer_body:
    if (fn_802072A0() == 1) {
        goto do_list;
    }
    if (list == (void *)lbl_8029B478) {
        goto outer_next;
    }
do_list:
    goto list_cond;
list_body:
    str = *(u8 **)list;
    goto char_cond;
char_body:
    if ((s32)(s8)temp_r3 == 0xA) {
        str += 1;
        goto char_cond;
    }
    if (fn_802072A0() != 1) {
        tmp_ch = (s8)str[0];
        str += 1;
        sp12 = tmp_ch;
        Tree_InsertKey(sp30, &tree, (u16 *)&sp12);
        goto char_cond;
    }
    temp_r0 = str[0];
    if (((temp_r0 >= 0x81U && temp_r0 <= 0x9FU) || (temp_r0 >= 0xE0U && temp_r0 <= 0xFCU))
        && (((temp_r0_2 = str[1], temp_r0_2 >= 0x40U) && (temp_r0_2 <= 0x7EU))
            || ((temp_r0_2 >= 0x80U) && (temp_r0_2 <= 0xFCU)))) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 == 0) {
        tmp_ch = (s8)str[0];
        str += 1;
        sp10 = tmp_ch;
        Tree_InsertKey(sp28, &tree, (u16 *)&sp10);
    } else {
        Tree_InsertKey(sp20, &tree, (u16 *)str);
        str += 2;
    }
char_cond:
    temp_r3 = *str;
    if ((s8)temp_r3 != 0) {
        goto char_body;
    }
    list = (u8 *)list + 4;
list_cond:
    if (*(void **)list != NULL) {
        goto list_body;
    }
outer_next:
    tables = (u8 *)tables + 4;
outer_cond:
    list = *(void **)tables;
    if (list != NULL) {
        goto outer_body;
    }

    if (fn_802072A0() == 1) {
        h1 = fn_800C45B8(0xFFF6F11C, lbl_80281420 + 0xA6D, 0);
        h2 = fn_800C45B8(0xFFFB3000, lbl_80281420 + 0xA6D, 0);
    } else {
        h1 = fn_800C45B8(0xFFFEFEE0, lbl_80281420 + 0xA6D, 0);
        h2 = fn_800C45B8(-0x3000, lbl_80281420 + 0xA6D, 0);
    }
    fn_80207628(h1, h2);
    glyphs = fn_800C4604(0, tree.count * 0x140, lbl_80281420 + 0xA6D, 0);
    lbl_80368410[0] = (u32)glyphs;
    memset(glyphs, 0, tree.count * 0x140);
    *(void **)sp14b = tree.first;
    lbl = lbl_80368410;
    end = &tree.root;
    lbl_80368410[1] = tree.count;
    goto glyph_cond;
glyph_body:
    code = *(u16 *)((u8 *)*(void **)sp14b + 0xC);
    if ((code & 0xFF00) == 0) {
        sp1C[0] = (u8)code;
        sp1C[1] = 0;
    } else {
        sp1C[0] = (u8)((s32)(code & 0xFF00) >> 8);
        sp1C[1] = (u8)code;
        sp1C[2] = 0;
    }
    fn_802078A4(sp1C, glyphs, 0, 6, (s32 *)sp18b);
    *(u16 *)((u8 *)glyphs + 0x120) = *(u16 *)((u8 *)*(void **)sp14b + 0xC);
    *(u16 *)((u8 *)glyphs + 0x122) = (u16)*(s32 *)sp18b;
    fn_800DE9FC(sp14b);
    glyphs = (u8 *)glyphs + 0x140;
glyph_cond:
    if (*(void **)sp14b != end) {
        goto glyph_body;
    }
    DCFlushRange((void *)*lbl, tree.count * 0x140);
    fn_800C4588(h2);
    fn_800C4588(h1);
    if (tree.root != NULL) {
        Tree_Destroy(&tree, tree.root);
    }
}
s32 fn_801FBF98(s32 arg0, s32 arg1, u16 *arg2, u8 (*arg3)(s32, u16)) {
 s32 count; s32 mid_ptr; s32 mid;
 count=(arg1-arg0)/320;
 while(count>0) { mid=count/2; mid_ptr=arg0+mid*320; if(arg3(mid_ptr,*arg2)!=0) {arg0=mid_ptr+320; count-=mid+1;} else count=mid; }
 return arg0;
}

#pragma use_lmw_stmw on
void Tree_Destroy(void *arg0, void *arg1) {
    void Heap_Free(void *);
    void fn_801FC400(void *);
    void fn_801FC404(void *);
    void fn_801FC408(void *, void *, s32);
    void *fn_801FC42C(void *);
    void fn_801FC434(void *, void *);
    void *fn_801FC438(void *);
    void *v27;
    void *v28;
    void *v29;

    v29 = *(void **)((u8 *)arg1 + 0);
    if (v29 != 0) {
        v28 = *(void **)((u8 *)v29 + 0);
        if (v28 != 0) {
            v27 = *(void **)((u8 *)v28 + 0);
            if (v27 != 0) {
                if (*(void **)((u8 *)v27 + 0) != 0) {
                    Tree_Destroy(arg0, *(void **)((u8 *)v27 + 0));
                }
                if (*(void **)((u8 *)v27 + 4) != 0) {
                    Tree_Destroy(arg0, *(void **)((u8 *)v27 + 4));
                }
                fn_801FC434(fn_801FC438(arg0), (u8 *)v27 + 0xC);
                fn_801FC408(fn_801FC42C(arg0), v27, 1);
            }
            v27 = *(void **)((u8 *)v28 + 4);
            if (v27 != 0) {
                if (*(void **)((u8 *)v27 + 0) != 0) {
                    Tree_Destroy(arg0, *(void **)((u8 *)v27 + 0));
                }
                if (*(void **)((u8 *)v27 + 4) != 0) {
                    Tree_Destroy(arg0, *(void **)((u8 *)v27 + 4));
                }
                fn_801FC434(fn_801FC438(arg0), (u8 *)v27 + 0xC);
                fn_801FC408(fn_801FC42C(arg0), v27, 1);
            }
            fn_801FC438(arg0);
            fn_801FC42C(arg0);
            Heap_Free(v28);
        }
        v27 = *(void **)((u8 *)v29 + 4);
        if (v27 != 0) {
            v28 = *(void **)((u8 *)v27 + 0);
            if (v28 != 0) {
                if (*(void **)((u8 *)v28 + 0) != 0) {
                    Tree_Destroy(arg0, *(void **)((u8 *)v28 + 0));
                }
                if (*(void **)((u8 *)v28 + 4) != 0) {
                    Tree_Destroy(arg0, *(void **)((u8 *)v28 + 4));
                }
                fn_801FC434(fn_801FC438(arg0), (u8 *)v28 + 0xC);
                fn_801FC408(fn_801FC42C(arg0), v28, 1);
            }
            v28 = *(void **)((u8 *)v27 + 4);
            if (v28 != 0) {
                if (*(void **)((u8 *)v28 + 0) != 0) {
                    Tree_Destroy(arg0, *(void **)((u8 *)v28 + 0));
                }
                if (*(void **)((u8 *)v28 + 4) != 0) {
                    Tree_Destroy(arg0, *(void **)((u8 *)v28 + 4));
                }
                fn_801FC434(fn_801FC438(arg0), (u8 *)v28 + 0xC);
                fn_801FC408(fn_801FC42C(arg0), v28, 1);
            }
            fn_801FC438(arg0);
            fn_801FC42C(arg0);
            Heap_Free(v27);
        }
        fn_801FC404(arg0);
        fn_801FC400((u8 *)arg0 + 4);
        Heap_Free(v29);
    }
    v27 = *(void **)((u8 *)arg1 + 4);
    if (v27 != 0) {
        v28 = *(void **)((u8 *)v27 + 0);
        if (v28 != 0) {
            v29 = *(void **)((u8 *)v28 + 0);
            if (v29 != 0) {
                if (*(void **)((u8 *)v29 + 0) != 0) {
                    Tree_Destroy(arg0, *(void **)((u8 *)v29 + 0));
                }
                if (*(void **)((u8 *)v29 + 4) != 0) {
                    Tree_Destroy(arg0, *(void **)((u8 *)v29 + 4));
                }
                fn_801FC434(fn_801FC438(arg0), (u8 *)v29 + 0xC);
                fn_801FC408(fn_801FC42C(arg0), v29, 1);
            }
            v29 = *(void **)((u8 *)v28 + 4);
            if (v29 != 0) {
                if (*(void **)((u8 *)v29 + 0) != 0) {
                    Tree_Destroy(arg0, *(void **)((u8 *)v29 + 0));
                }
                if (*(void **)((u8 *)v29 + 4) != 0) {
                    Tree_Destroy(arg0, *(void **)((u8 *)v29 + 4));
                }
                fn_801FC434(fn_801FC438(arg0), (u8 *)v29 + 0xC);
                fn_801FC408(fn_801FC42C(arg0), v29, 1);
            }
            fn_801FC438(arg0);
            fn_801FC42C(arg0);
            Heap_Free(v28);
        }
        v28 = *(void **)((u8 *)v27 + 4);
        if (v28 != 0) {
            v29 = *(void **)((u8 *)v28 + 0);
            if (v29 != 0) {
                if (*(void **)((u8 *)v29 + 0) != 0) {
                    Tree_Destroy(arg0, *(void **)((u8 *)v29 + 0));
                }
                if (*(void **)((u8 *)v29 + 4) != 0) {
                    Tree_Destroy(arg0, *(void **)((u8 *)v29 + 4));
                }
                fn_801FC434(fn_801FC438(arg0), (u8 *)v29 + 0xC);
                fn_801FC408(fn_801FC42C(arg0), v29, 1);
            }
            v29 = *(void **)((u8 *)v28 + 4);
            if (v29 != 0) {
                if (*(void **)((u8 *)v29 + 0) != 0) {
                    Tree_Destroy(arg0, *(void **)((u8 *)v29 + 0));
                }
                if (*(void **)((u8 *)v29 + 4) != 0) {
                    Tree_Destroy(arg0, *(void **)((u8 *)v29 + 4));
                }
                fn_801FC434(fn_801FC438(arg0), (u8 *)v29 + 0xC);
                fn_801FC408(fn_801FC42C(arg0), v29, 1);
            }
            fn_801FC438(arg0);
            fn_801FC42C(arg0);
            Heap_Free(v28);
        }
        fn_801FC404(arg0);
        fn_801FC400((u8 *)arg0 + 4);
        Heap_Free(v27);
    }
    Heap_Free(arg1);
}
#pragma use_lmw_stmw reset

void fn_801FC400(void) {

}

void fn_801FC404(void) {

}

void fn_801FC408(void *arg0, void *arg1) {
    void Heap_Free(void *);
    Heap_Free(arg1);
}

s32 fn_801FC42C(s32 arg0) {
    return arg0 + 4;
}

void fn_801FC434(void) {

}

void fn_801FC438(void) {

}

void *Tree_InsertNode(void *arg0, void *arg1, s32 arg2, s32 arg3, u16 *arg4);

#pragma opt_common_subs off
void Tree_InsertKey(void *arg0, void *arg1, u16 *arg2) {
    extern u8 lbl_80366F08;
    extern u8 lbl_80366F09;
    void *key;
    void *found;
    void *parent;
    void *node;
    u16 *p;
    s32 flag6;
    s32 flag5;
    void *self;

    self = arg0;
    p = arg2;
    parent = (u8 *)arg1 + 4;
    found = NULL;
    flag6 = 1;
    key = (void *)(u32)*arg2;
    flag5 = 1;
    node = *(void **)((u8 *)arg1 + 4);

    while (node != NULL) {
        parent = node;
        if ((u32)key < *(u16 *)((u8 *)node + 0xC)) {
            node = *(void **)node;
            flag5 = 1;
        } else {
            found = node;
            node = *(void **)((u8 *)node + 4);
            flag5 = 0;
            flag6 = 0;
        }
    }

    if (found == NULL || *(u16 *)((u8 *)found + 0xC) < *p) {
        *(void **)self = Tree_InsertNode(arg1, parent, flag5, flag6, arg2);
        *((u8 *)self + 4) = lbl_80366F08;
    } else {
        *(void **)self = found;
        *((u8 *)self + 4) = lbl_80366F09;
    }
}
#pragma dont_inline on
#pragma global_optimizer off
#pragma scheduling off
void Tree_Init(void *arg0, u8 *arg1) {
    u8 *mid;
    u8 v;
    s32 z;
    z = 0;
    v = *arg1;
    *(u32 *)arg0 = z;
    mid = (u8 *)arg0 + 4;
    *(u32 *)((u8 *)arg0 + 4) = z;
    *((u8 *)arg0 + 8) = v;
    *(void **)((u8 *)arg0 + 8) = mid;
}
#pragma scheduling reset
#pragma global_optimizer reset
#pragma dont_inline reset
/* Allocate and link a new RB-tree node with u16 key under parent; rebalance and return it. */
void *Tree_InsertNode(void *tree, void *parent, s32 asLeft, s32 setFirst, u16 *key) {
    void *Heap_Alloc(u32);
    void Tree_InsertFixup(void *, void *);
    M2C_UNK abort(void);
    M2C_UNK fprintf(void *, const char *, ...);
    extern char __files[];
    extern char lbl_80281420[];
    void *node;
    u16 *value;

    if (M2C_FIELD(tree, u32 *, 0) > (u32)-2) {
        fprintf(__files + 0xA0, lbl_80281420 + 0xA6E);
        abort();
    }
    node = Heap_Alloc(0x10);
    if (node == NULL) {
        fprintf(__files + 0xA0, lbl_80281420 + 0xA89);
        abort();
    }
    value = (u16 *)((char *)node + 0xC);
    if (value != NULL) {
        *value = *key;
    }
    M2C_FIELD(node, void **, 4) = NULL;
    M2C_FIELD(node, void **, 0) = NULL;
    M2C_FIELD(node, u32 *, 8) = (u32)parent | (M2C_FIELD(node, u32 *, 8) & 1);
    if ((u8)asLeft) {
        M2C_FIELD(parent, void **, 0) = node;
    } else {
        M2C_FIELD(parent, void **, 4) = node;
    }
    M2C_FIELD(tree, u32 *, 0)++;
    Tree_InsertFixup(node, M2C_FIELD(tree, void **, 4));
    if ((u8)setFirst) {
        M2C_FIELD(tree, void **, 8) = node;
    }
    return node;
}
#pragma use_lmw_stmw reset
extern u16 gCardLinkStr[18];
extern u16* gCardLinkStrings;
extern u16* lbl_8029A910;
extern u8 lbl_8027F710[32];
extern u8 gBattleState[1400];

u8 fn_801F19A0(void) {
    s32 Res_GetByName(void *);
    s32 temp_r3;
    s8 var_r0;

    temp_r3 = Res_GetByName(lbl_8027F710 + 0x15);
    switch ((s32)gBattleState[0xA6]) {
    case 3:
        var_r0 = 3;
        break;
    case 0:
        var_r0 = 0;
        break;
    case 1:
        var_r0 = 1;
        break;
    case 2:
        var_r0 = 2;
        break;
    default:
        var_r0 = 0;
        break;
    }
    temp_r3 = temp_r3 + var_r0;
    return *(u8 *)(temp_r3 + 0x18);
}

u8 fn_801F1A2C(void) {
    void *Res_GetByName(void *);
    s8 var_r0;
    void *temp_r3;

    temp_r3 = Res_GetByName(lbl_8027F710 + 0x15);
    switch ((s32)gBattleState[0xA6]) {
    case 3:
        var_r0 = 3;
        break;
    case 0:
        var_r0 = 0;
        break;
    case 1:
        var_r0 = 1;
        break;
    case 2:
        var_r0 = 2;
        break;
    default:
        var_r0 = 0;
        break;
    }
    temp_r3 = (void *)((u8 *)temp_r3 + var_r0);
    return *(u8 *)((u8 *)temp_r3 + 0x14);
}

u8 fn_801F1AB8(void) {
    s32 Res_GetByName(void *);
    s32 temp_r3;
    s8 var_r0;

    temp_r3 = Res_GetByName(lbl_8027F710 + 0x15);
    switch ((s32)gBattleState[0xA6]) {
    case 3:
        var_r0 = 3;
        break;
    case 0:
        var_r0 = 0;
        break;
    case 1:
        var_r0 = 1;
        break;
    case 2:
        var_r0 = 2;
        break;
    default:
        var_r0 = 0;
        break;
    }
    temp_r3 = temp_r3 + var_r0;
    return *(u8 *)(temp_r3 + 0x10);
}

u8 fn_801F1B44(void) {
    s32 Res_GetByName(void *);
    s32 temp_r3;
    s8 var_r0;

    temp_r3 = Res_GetByName(lbl_8027F710 + 0x15);
    switch ((s32)gBattleState[0xA6]) {
    case 3:
        var_r0 = 3;
        break;
    case 0:
        var_r0 = 0;
        break;
    case 1:
        var_r0 = 1;
        break;
    case 2:
        var_r0 = 2;
        break;
    default:
        var_r0 = 0;
        break;
    }
    temp_r3 = temp_r3 + var_r0;
    return *(u8 *)(temp_r3 + 0xC);
}

u8 fn_801F1BD0(void) {
    void *Res_GetByName(void *);
    s8 var_r0;
    void *temp_r3;

    temp_r3 = Res_GetByName(lbl_8027F710 + 0x15);
    switch ((s32)gBattleState[0xA6]) {
    case 3:
        var_r0 = 3;
        break;
    case 0:
        var_r0 = 0;
        break;
    case 1:
        var_r0 = 1;
        break;
    case 2:
        var_r0 = 2;
        break;
    default:
        var_r0 = 0;
        break;
    }
    temp_r3 = (void *)((u8 *)temp_r3 + var_r0);
    return *(u8 *)((u8 *)temp_r3 + 0x8);
}

u8 fn_801F1C5C(void) {
    s32 Res_GetByName(void *);
    s32 temp_r3;
    s8 var_r0;

    temp_r3 = Res_GetByName(lbl_8027F710 + 0x15);
    switch ((s32)gBattleState[0xA6]) {
    case 3:
        var_r0 = 3;
        break;
    case 0:
        var_r0 = 0;
        break;
    case 1:
        var_r0 = 1;
        break;
    case 2:
        var_r0 = 2;
        break;
    default:
        var_r0 = 0;
        break;
    }
    temp_r3 = temp_r3 + var_r0;
    return *(u8 *)(temp_r3 + 4);
}

u8 fn_801F1CE8(void)
{
    s32 Res_GetByName(void *);

    s32 temp_r3;
    s8 var_r0;

    temp_r3 = Res_GetByName(lbl_8027F710 + 0x15);

    switch ((s32)gBattleState[0xA6]) {
    case 3:
        var_r0 = 3;
        break;
    case 0:
        var_r0 = 0;
        break;
    case 1:
        var_r0 = 1;
        break;
    case 2:
        var_r0 = 2;
        break;
    default:
        var_r0 = 0;
        break;
    }

    temp_r3 = temp_r3 + var_r0;
    return *(u8 *)temp_r3;
}

#include "common.h"
extern u8 lbl_8027F710[];
extern u8 gBattleState[];
#include "global.h"
#include "unit.h"

extern s32 lbl_802343E0(void *, void *);
extern s32 lbl_80234450(void *, void *, s32, s32);
#include "global.h"
#include "structs.h"

extern u16 gBattlePreviewStrings[40];
