#pragma once

// ====================================================================
// imprint.keymap で使う #define 群
// ====================================================================

// レイヤー
// --------------------------------------------------------------------
#define DEFAULT_LAYER 0
#define NUM_LAYER 1
#define SYMBOL1_LAYER 2
#define SYMBOL2_LAYER 3
#define FN_LAYER 4
#define LL_LAYER 5
#define TAB_LAYER 6
#define DELETE_LAYER 7
#define LEFT_ARROW_LAYER 8
#define RIGHT_ARROW_LAYER 9
#define UP_ARROW_LAYER 10
#define DOWN_ARROW_LAYER 11

// --------------------------------------------------------------------
// エイリアス
// --------------------------------------------------------------------
// 効果音
#define X_SOUND_1 LANGUAGE_3
#define X_SOUND_2 LANGUAGE_4

// 和英
#define EIJI LANGUAGE_2
#define KANA LANGUAGE_1

// 親指
#define T_LL LEFT_SHIFT RETURN
#define T_LR LEFT_COMMAND BACKSPACE

// 和英 (X_QQ / X_PP)
#define X_QQ RG(RA(RS(RC(LANGUAGE_8))))
#define X_PP RG(RA(RS(RC(LANGUAGE_9))))

// --------------------------------------------------------------------
// キー位置
// https://github.com/KinesisCorporation/Adv360-Pro-ZMK/blob/V3.0/assets/key-positions.md
// --------------------------------------------------------------------
#define KEY_POSITION_LL 52
#define KEY_POSITION_LR 53
#define KEY_POSITION_RL 56
#define KEY_POSITION_RR 57
#define KEY_POSITION_UP_ARROW 32
#define KEY_POSITION_LEFT_ARROW 41
#define KEY_POSITION_DOWN_ARROW 42
#define KEY_POSITION_RIGHT_ARROW 43
#define KEY_POSITION_LEFT_SIDE \
   0  1  2  3  4  5 \
  12 13 14 15 16 17 \
  24 25 26 27 28 29 \
  36 37 38 39 40 \
  46 47 48 \
  52 53 54
#define KEY_POSITION_RIGHT_SIDE \
   6  7  8  9 10 11 \
  18 19 20 21 22 23 \
  30 31 32 33 34 35 \
  41 42 43 44 45 \
  49 50 51 \
  55 56 57
#define KEY_POSITION_L_THUMB KEY_POSITION_LL KEY_POSITION_LR

// --------------------------------------------------------------------
// OS に渡す用ショートカット
// --------------------------------------------------------------------
#define X_LL_LL KP_N0
#define X_LH_NUM RG(RA(RS(RC(LANGUAGE_5))))
#define X_LH_SYM1 RG(RA(RS(RC(LANGUAGE_6))))
#define X_LH_SYM2 RG(RA(RS(RC(LANGUAGE_7))))
#define X_LH_FN RG(RA(RS(RC(LANGUAGE_8))))

// LL レイヤー（INTERNATIONAL_* / KP_*）
#define X_LL_AA INTERNATIONAL_1
#define X_LL_ZZ INTERNATIONAL_2
#define X_LL_QQ INTERNATIONAL_3
#define X_LL_NUM INTERNATIONAL_4
#define X_LL_SYM1 INTERNATIONAL_5
#define X_LL_SYM2 INTERNATIONAL_6
#define X_LL_T_LL INTERNATIONAL_7
#define X_LL_T_LR INTERNATIONAL_8
#define X_LL_Q KP_N1
#define X_LL_W KP_N2
#define X_LL_E KP_N3
#define X_LL_R KP_N4
#define X_LL_T KP_N5
#define X_LL_A KP_N6
#define X_LL_S KP_N7
#define X_LL_D KP_N8
#define X_LL_F KP_N9
#define X_LL_G KP_PLUS
#define X_LL_Z KP_EQUAL
#define X_LL_X KP_DOT
#define X_LL_C KP_MINUS
#define X_LL_V KP_SLASH
#define X_LL_B KP_ASTERISK

// --------------------------------------------------------------------
// TAB/DELETE/<arrow> レイヤー: 修飾子ラッパー + 共通ベースキー + 派生定義
// --------------------------------------------------------------------
// 各レイヤーの修飾子ラッパー（k はベースキー）
#define X_TAB(k) RS(RA(k))
#define X_DELETE(k) RS(RG(k))
#define X_LEFT_ARROW(k) RA(RC(k))
#define X_RIGHT_ARROW(k) RG(RC(k))
#define X_UP_ARROW(k) RS(RC(k))
#define X_DOWN_ARROW(k) RG(RA(k))

// 共通ベースキー（各レイヤーで shared）
#define X_BASE_AA NON_US_BACKSLASH
#define X_BASE_ZZ K_APPLICATION
#define X_BASE_QQ LANGUAGE_5
#define X_BASE_NUM LANGUAGE_6
#define X_BASE_SYM1 LANGUAGE_7
#define X_BASE_SYM2 LANGUAGE_8
#define X_BASE_T_LL INSERT
#define X_BASE_T_LR KP_ENTER
#define X_BASE_Q F13
#define X_BASE_W F14
#define X_BASE_E F15
#define X_BASE_R F16
#define X_BASE_T F17
#define X_BASE_A F18
#define X_BASE_S F19
#define X_BASE_D F20
#define X_BASE_F F21
#define X_BASE_G F22
#define X_BASE_Z F23
#define X_BASE_X F24
#define X_BASE_C NON_US_HASH
#define X_BASE_V PRINTSCREEN
#define X_BASE_B PAUSE_BREAK

// TAB: SHIFT ALT
#define X_TAB_AA X_TAB(X_BASE_AA)
#define X_TAB_ZZ X_TAB(X_BASE_ZZ)
#define X_TAB_QQ X_TAB(X_BASE_QQ)
#define X_TAB_NUM X_TAB(X_BASE_NUM)
#define X_TAB_SYM1 X_TAB(X_BASE_SYM1)
#define X_TAB_SYM2 X_TAB(X_BASE_SYM2)
#define X_TAB_T_LL X_TAB(X_BASE_T_LL)
#define X_TAB_T_LR X_TAB(X_BASE_T_LR)
#define X_TAB_Q X_TAB(X_BASE_Q)
#define X_TAB_W X_TAB(X_BASE_W)
#define X_TAB_E X_TAB(X_BASE_E)
#define X_TAB_R X_TAB(X_BASE_R)
#define X_TAB_T X_TAB(X_BASE_T)
#define X_TAB_A X_TAB(X_BASE_A)
#define X_TAB_S X_TAB(X_BASE_S)
#define X_TAB_D X_TAB(X_BASE_D)
#define X_TAB_F X_TAB(X_BASE_F)
#define X_TAB_G X_TAB(X_BASE_G)
#define X_TAB_Z X_TAB(X_BASE_Z)
#define X_TAB_X X_TAB(X_BASE_X)
#define X_TAB_C X_TAB(X_BASE_C)
#define X_TAB_V X_TAB(X_BASE_V)
#define X_TAB_B X_TAB(X_BASE_B)

// DELETE: SHIFT, COMMAND
#define X_DELETE_AA X_DELETE(X_BASE_AA)
#define X_DELETE_ZZ X_DELETE(X_BASE_ZZ)
#define X_DELETE_QQ X_DELETE(X_BASE_QQ)
#define X_DELETE_NUM X_DELETE(X_BASE_NUM)
#define X_DELETE_SYM1 X_DELETE(X_BASE_SYM1)
#define X_DELETE_SYM2 X_DELETE(X_BASE_SYM2)
#define X_DELETE_T_LL X_DELETE(X_BASE_T_LL)
#define X_DELETE_T_LR X_DELETE(X_BASE_T_LR)
#define X_DELETE_Q X_DELETE(X_BASE_Q)
#define X_DELETE_W X_DELETE(X_BASE_W)
#define X_DELETE_E X_DELETE(X_BASE_E)
#define X_DELETE_R X_DELETE(X_BASE_R)
#define X_DELETE_T X_DELETE(X_BASE_T)
#define X_DELETE_A X_DELETE(X_BASE_A)
#define X_DELETE_S X_DELETE(X_BASE_S)
#define X_DELETE_D X_DELETE(X_BASE_D)
#define X_DELETE_F X_DELETE(X_BASE_F)
#define X_DELETE_G X_DELETE(X_BASE_G)
#define X_DELETE_Z X_DELETE(X_BASE_Z)
#define X_DELETE_X X_DELETE(X_BASE_X)
#define X_DELETE_C X_DELETE(X_BASE_C)
#define X_DELETE_V X_DELETE(X_BASE_V)
#define X_DELETE_B X_DELETE(X_BASE_B)

// LEFT_ARROW: ALT, CTRL
#define X_LEFT_ARROW_AA X_LEFT_ARROW(X_BASE_AA)
#define X_LEFT_ARROW_ZZ X_LEFT_ARROW(X_BASE_ZZ)
#define X_LEFT_ARROW_QQ X_LEFT_ARROW(X_BASE_QQ)
#define X_LEFT_ARROW_NUM X_LEFT_ARROW(X_BASE_NUM)
#define X_LEFT_ARROW_SYM1 X_LEFT_ARROW(X_BASE_SYM1)
#define X_LEFT_ARROW_SYM2 X_LEFT_ARROW(X_BASE_SYM2)
#define X_LEFT_ARROW_T_LL X_LEFT_ARROW(X_BASE_T_LL)
#define X_LEFT_ARROW_T_LR X_LEFT_ARROW(X_BASE_T_LR)
#define X_LEFT_ARROW_Q X_LEFT_ARROW(X_BASE_Q)
#define X_LEFT_ARROW_W X_LEFT_ARROW(X_BASE_W)
#define X_LEFT_ARROW_E X_LEFT_ARROW(X_BASE_E)
#define X_LEFT_ARROW_R X_LEFT_ARROW(X_BASE_R)
#define X_LEFT_ARROW_T X_LEFT_ARROW(X_BASE_T)
#define X_LEFT_ARROW_A X_LEFT_ARROW(X_BASE_A)
#define X_LEFT_ARROW_S X_LEFT_ARROW(X_BASE_S)
#define X_LEFT_ARROW_D X_LEFT_ARROW(X_BASE_D)
#define X_LEFT_ARROW_F X_LEFT_ARROW(X_BASE_F)
#define X_LEFT_ARROW_G X_LEFT_ARROW(X_BASE_G)
#define X_LEFT_ARROW_Z X_LEFT_ARROW(X_BASE_Z)
#define X_LEFT_ARROW_X X_LEFT_ARROW(X_BASE_X)
#define X_LEFT_ARROW_C X_LEFT_ARROW(X_BASE_C)
#define X_LEFT_ARROW_V X_LEFT_ARROW(X_BASE_V)
#define X_LEFT_ARROW_B X_LEFT_ARROW(X_BASE_B)

// RIGHT_ARROW: COMMAND, CTRL
#define X_RIGHT_ARROW_AA X_RIGHT_ARROW(X_BASE_AA)
#define X_RIGHT_ARROW_ZZ X_RIGHT_ARROW(X_BASE_ZZ)
#define X_RIGHT_ARROW_QQ X_RIGHT_ARROW(X_BASE_QQ)
#define X_RIGHT_ARROW_NUM X_RIGHT_ARROW(X_BASE_NUM)
#define X_RIGHT_ARROW_SYM1 X_RIGHT_ARROW(X_BASE_SYM1)
#define X_RIGHT_ARROW_SYM2 X_RIGHT_ARROW(X_BASE_SYM2)
#define X_RIGHT_ARROW_T_LL X_RIGHT_ARROW(X_BASE_T_LL)
#define X_RIGHT_ARROW_T_LR X_RIGHT_ARROW(X_BASE_T_LR)
#define X_RIGHT_ARROW_Q X_RIGHT_ARROW(X_BASE_Q)
#define X_RIGHT_ARROW_W X_RIGHT_ARROW(X_BASE_W)
#define X_RIGHT_ARROW_E X_RIGHT_ARROW(X_BASE_E)
#define X_RIGHT_ARROW_R X_RIGHT_ARROW(X_BASE_R)
#define X_RIGHT_ARROW_T X_RIGHT_ARROW(X_BASE_T)
#define X_RIGHT_ARROW_A X_RIGHT_ARROW(X_BASE_A)
#define X_RIGHT_ARROW_S X_RIGHT_ARROW(X_BASE_S)
#define X_RIGHT_ARROW_D X_RIGHT_ARROW(X_BASE_D)
#define X_RIGHT_ARROW_F X_RIGHT_ARROW(X_BASE_F)
#define X_RIGHT_ARROW_G X_RIGHT_ARROW(X_BASE_G)
#define X_RIGHT_ARROW_Z X_RIGHT_ARROW(X_BASE_Z)
#define X_RIGHT_ARROW_X X_RIGHT_ARROW(X_BASE_X)
#define X_RIGHT_ARROW_C X_RIGHT_ARROW(X_BASE_C)
#define X_RIGHT_ARROW_V X_RIGHT_ARROW(X_BASE_V)
#define X_RIGHT_ARROW_B X_RIGHT_ARROW(X_BASE_B)

// UP_ARROW: SHIFT, CTRL
#define X_UP_ARROW_AA X_UP_ARROW(X_BASE_AA)
#define X_UP_ARROW_ZZ X_UP_ARROW(X_BASE_ZZ)
#define X_UP_ARROW_QQ X_UP_ARROW(X_BASE_QQ)
#define X_UP_ARROW_NUM X_UP_ARROW(X_BASE_NUM)
#define X_UP_ARROW_SYM1 X_UP_ARROW(X_BASE_SYM1)
#define X_UP_ARROW_SYM2 X_UP_ARROW(X_BASE_SYM2)
#define X_UP_ARROW_T_LL X_UP_ARROW(X_BASE_T_LL)
#define X_UP_ARROW_T_LR X_UP_ARROW(X_BASE_T_LR)
#define X_UP_ARROW_Q X_UP_ARROW(X_BASE_Q)
#define X_UP_ARROW_W X_UP_ARROW(X_BASE_W)
#define X_UP_ARROW_E X_UP_ARROW(X_BASE_E)
#define X_UP_ARROW_R X_UP_ARROW(X_BASE_R)
#define X_UP_ARROW_T X_UP_ARROW(X_BASE_T)
#define X_UP_ARROW_A X_UP_ARROW(X_BASE_A)
#define X_UP_ARROW_S X_UP_ARROW(X_BASE_S)
#define X_UP_ARROW_D X_UP_ARROW(X_BASE_D)
#define X_UP_ARROW_F X_UP_ARROW(X_BASE_F)
#define X_UP_ARROW_G X_UP_ARROW(X_BASE_G)
#define X_UP_ARROW_Z X_UP_ARROW(X_BASE_Z)
#define X_UP_ARROW_X X_UP_ARROW(X_BASE_X)
#define X_UP_ARROW_C X_UP_ARROW(X_BASE_C)
#define X_UP_ARROW_V X_UP_ARROW(X_BASE_V)
#define X_UP_ARROW_B X_UP_ARROW(X_BASE_B)

// DOWN_ARROW: COMMAND, ALT
#define X_DOWN_ARROW_AA X_DOWN_ARROW(X_BASE_AA)
#define X_DOWN_ARROW_ZZ X_DOWN_ARROW(X_BASE_ZZ)
#define X_DOWN_ARROW_QQ X_DOWN_ARROW(X_BASE_QQ)
#define X_DOWN_ARROW_NUM X_DOWN_ARROW(X_BASE_NUM)
#define X_DOWN_ARROW_SYM1 X_DOWN_ARROW(X_BASE_SYM1)
#define X_DOWN_ARROW_SYM2 X_DOWN_ARROW(X_BASE_SYM2)
#define X_DOWN_ARROW_T_LL X_DOWN_ARROW(X_BASE_T_LL)
#define X_DOWN_ARROW_T_LR X_DOWN_ARROW(X_BASE_T_LR)
#define X_DOWN_ARROW_Q X_DOWN_ARROW(X_BASE_Q)
#define X_DOWN_ARROW_W X_DOWN_ARROW(X_BASE_W)
#define X_DOWN_ARROW_E X_DOWN_ARROW(X_BASE_E)
#define X_DOWN_ARROW_R X_DOWN_ARROW(X_BASE_R)
#define X_DOWN_ARROW_T X_DOWN_ARROW(X_BASE_T)
#define X_DOWN_ARROW_A X_DOWN_ARROW(X_BASE_A)
#define X_DOWN_ARROW_S X_DOWN_ARROW(X_BASE_S)
#define X_DOWN_ARROW_D X_DOWN_ARROW(X_BASE_D)
#define X_DOWN_ARROW_F X_DOWN_ARROW(X_BASE_F)
#define X_DOWN_ARROW_G X_DOWN_ARROW(X_BASE_G)
#define X_DOWN_ARROW_Z X_DOWN_ARROW(X_BASE_Z)
#define X_DOWN_ARROW_X X_DOWN_ARROW(X_BASE_X)
#define X_DOWN_ARROW_C X_DOWN_ARROW(X_BASE_C)
#define X_DOWN_ARROW_V X_DOWN_ARROW(X_BASE_V)
#define X_DOWN_ARROW_B X_DOWN_ARROW(X_BASE_B)

// --------------------------------------------------------------------
// 共通マクロ
// --------------------------------------------------------------------

// NUM/SYM1/SYM2/FN レイヤー末尾 2 行（DEFAULT 以外で共通）
#define LAYER_THUMB_COMMON \
        &kp LEFT_CONTROL  &kp LEFT_ALT  &none          &mkp MB3  &mkp MB1                &mkp MB2 \
        &mt T_LL          &mt T_LR      &bootloader    &none     &thumb_mt LEFT_ALT ESC  &thumb_mt LEFT_CONTROL SPACE

// LL/TAB/DELETE/<arrow> レイヤー全体を 1 行で生成。
// LAYER  : レイヤー名 (例: LL_LAYER)
// P      : キー接頭辞 (例: X_LL → X_LL_QQ などに展開)
// R4R    : row4 右側 5 セル分（例: &none &none &none &none &none）
#define MORPH_LAYER(LAYER, P, R4R) \
    LAYER { \
      bindings = < \
        &kp P##_QQ  &kp P##_Q  &kp P##_W  &kp P##_E  &kp P##_R  &kp P##_T    &none  &none  &none  &none  &none  &none \
        &kp P##_AA  &kp P##_A  &kp P##_S  &kp P##_D  &kp P##_F  &kp P##_G    &none  &none  &none  &none  &none  &none \
        &kp P##_ZZ  &kp P##_Z  &kp P##_X  &kp P##_C  &kp P##_V  &kp P##_B    &none  &none  &none  &none  &none  &none \
        &none  &none  &kp P##_SYM2  &kp P##_SYM1  &kp P##_NUM                R4R \
        &none         &none         &none                                    &none  &none  &none \
        &kp P##_T_LL  &kp P##_T_LR  &none                                    &none  &none  &none \
      >; \
    };

// 矢印 mod-morph + 対応 hold-tap の 1 ペアを生成。
// name : ベース名 (例: _up → _up と _up_ht を生成)
// LAYER, KEY : tap 時に潜るレイヤーと出力キー
// P1, P2     : hold-trigger-key-positions に追加する 2 つの矢印キー位置
#define ARROW_BEHAVIOR(name, LAYER, KEY, P1, P2) \
    name##_ht: name##_ht { \
      compatible = "zmk,behavior-hold-tap"; \
      #binding-cells = <2>; \
      flavor = "tap-unless-interrupted"; \
      tapping-term-ms = <800>; \
      hold-while-undecided; \
      hold-while-undecided-linger; \
      bindings = <&mo>, <&kp>; \
      hold-trigger-key-positions = <KEY_POSITION_LEFT_SIDE KEY_POSITION_L_THUMB P1 P2>; \
    }; \
    name: name { \
      compatible = "zmk,behavior-mod-morph"; \
      #binding-cells = <0>; \
      bindings = <&name##_ht LAYER KEY>, <&name##_ht LAYER KEY>; \
      mods = <( MOD_LGUI|MOD_LSFT|MOD_LCTL|MOD_LALT )>; \
      keep-mods = <( MOD_LGUI|MOD_LSFT|MOD_LCTL|MOD_LALT )>; \
    };

// Ctrl+letter を別キーへ remap する 3 段ネスト mod-morph を生成。
// Shift+Ctrl+letter はパススルー（OS に Shift+Ctrl+letter として届く）。
// name    : 既存 letter morph 名 (例: _p) — letter_morphs.dtsi で定義済みのもの
// letter  : Shift+Ctrl 時にパススルー出力するキー (例: P)
// out_key : Ctrl 単体時に出力するキー (例: UP_ARROW)
// 生成される behavior 名: name##_ctrl / name##_decide / name##_strip
#define CTRL_LETTER_MORPH(name, letter, out_key) \
    name##_ctrl: name##_ctrl { \
      compatible = "zmk,behavior-mod-morph"; \
      #binding-cells = <0>; \
      bindings = <&name>, <&name##_decide>; \
      mods = <(MOD_LCTL)>; \
      keep-mods = <(MOD_LCTL)>; \
    }; \
    name##_decide: name##_decide { \
      compatible = "zmk,behavior-mod-morph"; \
      #binding-cells = <0>; \
      bindings = <&name##_strip>, <&kp letter>; \
      mods = <(MOD_LSFT)>; \
      keep-mods = <(MOD_LSFT)>; \
    }; \
    name##_strip: name##_strip { \
      compatible = "zmk,behavior-mod-morph"; \
      #binding-cells = <0>; \
      bindings = <&none>, <&kp out_key>; \
      mods = <(MOD_LCTL)>; \
    };
