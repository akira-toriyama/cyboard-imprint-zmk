#pragma once

// ====================================================================
// imprint.keymap で使う #define 群
// ====================================================================

// レイヤー
// --------------------------------------------------------------------
#define DEFAULT_LAYER 0
#define NUMBER_LAYER 1
#define SYMBOL1_LAYER 2
#define SYMBOL2_LAYER 3
#define FUNCTION_LAYER 4
#define LEFT_ARROW_LAYER 5
#define RIGHT_ARROW_LAYER 6
#define UP_ARROW_LAYER 7
#define DOWN_ARROW_LAYER 8
#define T_LL_LAYER 9
#define T_LM_LAYER 10
#define T_RM_LAYER 11
#define T_RR_LAYER 12

// --------------------------------------------------------------------
// エイリアス
// --------------------------------------------------------------------
// 和英
#define EIJI LANGUAGE_2
#define KANA LANGUAGE_1

// 親指下段 (TD = Thumb Down)。mod-tap: hold=修飾子 / tap=キー
#define TD_LL &mt LEFT_SHIFT RETURN
#define TD_LM &mt LEFT_COMMAND BACKSPACE
#define TD_RM &mt LEFT_ALT ESCAPE
#define TD_RR &mt LEFT_CONTROL SPACE

// --------------------------------------------------------------------
// キー位置
// --------------------------------------------------------------------
#define KEY_POSITION_LL 52
#define KEY_POSITION_LM 53
#define KEY_POSITION_RM 56
#define KEY_POSITION_RR 57
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
#define KEY_POSITION_L_THUMB KEY_POSITION_LL KEY_POSITION_LM

// --------------------------------------------------------------------
// base key エイリアス
//   T_*_LAYER の chord (*_kp) と DEFAULT の &kp X_1 で使う素キー。
//   修飾子は付けない (chord 用の右 modifier は *_kp マクロ側で付与)。
// --------------------------------------------------------------------

// 左
#define X_Q Q
#define X_W W
#define X_E E
#define X_R R
#define X_T T
#define X_A A
#define X_S S
#define X_D D
#define X_F F
#define X_G G
#define X_Z Z
#define X_X X
#define X_C C
#define X_V V
#define X_B B

// 右
#define X_Y Y
#define X_U U
#define X_I I
#define X_O O
#define X_P P
#define X_H H
#define X_J J
#define X_K K
#define X_L L
#define X_N N
#define X_M M
#define X_1 KP_N1
#define X_2 KP_N2
#define X_3 KP_N3
#define X_4 KP_N4

// --------------------------------------------------------------------
// 共通マクロ
// --------------------------------------------------------------------

// 全 modifier (LGUI / LSFT / LCTL / LALT)。mod-morph の mods / keep-mods で使う
#define ALL_MODS (MOD_LGUI|MOD_LSFT|MOD_LCTL|MOD_LALT)

// シンプルな hold-tap (flavor=hold-preferred / tapping-term-ms=200ms / hold=&kp)。
// name        : 生成する behavior 名
// tap_binding : tap 時の binding (&kp / &kana / &eiji 等)
#define HOLD_TAP_HP200(name, tap_binding) \
    name: name { \
      compatible = "zmk,behavior-hold-tap"; \
      #binding-cells = <2>; \
      tapping-term-ms = <200>; \
      flavor = "hold-preferred"; \
      bindings = <&kp>, <tap_binding>; \
    };

// DEFAULT_LAYER 左親指列で使う momentary layer 呼出。
// NAME : SYMBOL1 / SYMBOL2 / NUMBER / FUNCTION
#define MO_LAYER(NAME) &mo NAME##_LAYER

// 親指上段 (TU = Thumb Upper)。layer 起動 (+ LL/LM は修飾子も同時 hold)。
#define TU_LL &t_ll_ctrl       // T_LL_LAYER + LCtrl hold (macros.dtsi)
#define TU_LM &t_lm_alt        // T_LM_LAYER + LAlt  hold (macros.dtsi)
#define TU_RM &mo T_RM_LAYER   // T_RM_LAYER のみ
#define TU_RR &mo T_RR_LAYER   // T_RR_LAYER のみ

// トラックボールでスクロールするための input-processors 共通設定。
//   - zip_xy_scaler 3 64                     : 感度を 1/3 にしてスクロールを遅くする
//   - zip_xy_to_scroll_mapper                 : カーソル移動でなくスクロール出力にする
//   - zip_scroll_transform Y_INVERT           : ボール上方向 = ビュー上方向 (top of trackball = view up)
#define TRACKBALL_SCROLL_PROCESSORS \
      <&zip_xy_scaler 3 64>, \
      <&zip_xy_to_scroll_mapper>, \
      <&zip_scroll_transform INPUT_TRANSFORM_Y_INVERT>

// 矢印 mod-morph + 対応 hold-tap の 1 ペアを生成。
// name : ベース名 (例: ar_up → ar_up と ar_up_ht を生成)
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
      mods = <ALL_MODS>; \
      keep-mods = <ALL_MODS>; \
    };

// al_a 〜 al_z 系 letter mod-morph を生成。
// Shift 未押下 → 素のキー / Shift 押下 → eiji_macro 経由で英語入力モードへ切替えてから大文字出力。
// name   : 生成する behavior 名 (例: al_a)
// letter : 出力キー (例: A)
#define LETTER_MORPH(name, letter) \
    name: name { \
      compatible = "zmk,behavior-mod-morph"; \
      #binding-cells = <0>; \
      bindings = <&kp letter>, <&eiji_macro letter>; \
      mods = <(MOD_LSFT)>; \
      keep-mods = <(MOD_LSFT)>; \
    };

// EIJI 切替 → 指定キー press → pause → release (long-press でリピート可能)。
// name : 生成する behavior 名 (例: en_0 / en_under)
// key  : 出力キー (例: N0 / UNDERSCORE)
// 注: keymap-drawer 上の表示は keymap_drawer.config.yaml の raw_binding_map で設定する。
#define EN_MACRO(name, key) \
    name: name { \
      compatible = "zmk,behavior-macro"; \
      #binding-cells = <0>; \
      bindings = <&macro_tap &kp EIJI>, <&macro_press &kp key>, <&macro_pause_for_release>, <&macro_release &kp key>; \
    };

