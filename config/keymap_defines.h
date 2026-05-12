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

// 現行 matrix transform (imprint_letters_only_full_bottom_row, 58 pos = 0..57) では範囲外。
// 別 transform (dactyl_manuform_number_row 等) に切替時のみ有効になる右側追加位置の保険。
#define KEY_POSITION_R_EXTRA 62 63 64

// --------------------------------------------------------------------
// OS に渡す用ショートカット
// --------------------------------------------------------------------
#define X_LL_LL KP_N0
#define X_LH_NUM RG(RA(RS(RC(LANGUAGE_5))))
#define X_LH_SYMBOL1 RG(RA(RS(RC(LANGUAGE_6))))
#define X_LH_SYMBOL2 RG(RA(RS(RC(LANGUAGE_7))))
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
// TAB/DELETE/<arrow> レイヤー: 修飾子ラッパー + 共通ベースキー
// --------------------------------------------------------------------
// 各レイヤーの修飾子ラッパー。k はキー suffix (AA / QQ / Q / W / ... B 等)。
// MORPH_LAYER が WRAP(QQ) のように呼び出すので、内部で X_BASE_##k を組合せる。
#define X_TAB(k) RS(RA(X_BASE_##k))
#define X_DELETE(k) RS(RG(X_BASE_##k))
#define X_LEFT_ARROW(k) RA(RC(X_BASE_##k))
#define X_RIGHT_ARROW(k) RG(RC(X_BASE_##k))
#define X_UP_ARROW(k) RS(RC(X_BASE_##k))
#define X_DOWN_ARROW(k) RG(RA(X_BASE_##k))

// LL レイヤー用 wrapper。LL のキーマッピングはユニークなので X_LL_<suffix> 個別 define を参照する。
// 例: X_LL(QQ) → X_LL_QQ → INTERNATIONAL_3
#define X_LL(k) X_LL_##k

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


// --------------------------------------------------------------------
// 共通マクロ
// --------------------------------------------------------------------

// 全 modifier (LGUI / LSFT / LCTL / LALT)。mod-morph の mods / keep-mods で使う
#define ALL_MODS (MOD_LGUI|MOD_LSFT|MOD_LCTL|MOD_LALT)

// NUM/SYM1/SYM2/FN レイヤー row 4 (左右どちらも &none x 5 で共通)
#define LAYER_NONE_ROW_4 \
        &none  &none  &none  &none  &none              &none  &none  &none  &none  &none

// NUM/SYM1/SYM2/FN レイヤー末尾 2 行（DEFAULT 以外で共通）
#define LAYER_THUMB_COMMON \
        &kp LEFT_CONTROL  &kp LEFT_ALT  &none          &mkp MB3  &mkp MB1                &mkp MB2 \
        &mt T_LL          &mt T_LR      &bootloader    &none     &thumb_mt LEFT_ALT ESC  &thumb_mt LEFT_CONTROL SPACE

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

// DEFAULT_LAYER 親指列で使う _layer 呼出（layer hold + OS 通知用 X_LH_<NAME> 送出）。
// NAME : SYMBOL1 / SYMBOL2 / NUM / FN (LAYER 番号と X_LH_ 接尾辞の共通部分)
#define LH_LAYER(NAME) &_layer NAME##_LAYER X_LH_##NAME

// 左親指 layer-tap (FN/SYMBOL1/SYMBOL2/NUM を起動する hold-tap)。
// hold-trigger は RIGHT_SIDE。左親指 hold 中に左手キーを誤打しても layer 側で取られないため。
// tapping-term-ms = 400ms / quick-tap-ms = 200ms で連打に強い。
#define HOLD_TAP_LAYER_RIGHT(name) \
    name: name { \
      compatible = "zmk,behavior-hold-tap"; \
      #binding-cells = <2>; \
      flavor = "hold-preferred"; \
      tapping-term-ms = <400>; \
      quick-tap-ms = <200>; \
      bindings = <&mo>, <&kp>; \
      hold-trigger-key-positions = <KEY_POSITION_RIGHT_SIDE KEY_POSITION_R_EXTRA>; \
    };

// トラックボールでスクロールするための input-processors 共通設定。
//   - zip_xy_scaler 3 64                     : 感度を 1/3 にしてスクロールを遅くする
//   - zip_xy_to_scroll_mapper                 : カーソル移動でなくスクロール出力にする
//   - zip_scroll_transform Y_INVERT           : ボール上方向 = ビュー上方向 (top of trackball = view up)
#define TRACKBALL_SCROLL_PROCESSORS \
      <&zip_xy_scaler 3 64>, \
      <&zip_xy_to_scroll_mapper>, \
      <&zip_scroll_transform INPUT_TRANSFORM_Y_INVERT>

// TAB / DELETE 用の hold-tap + mod-morph ペア。
// 修飾子 (ALL_MODS) を押下していない時は hold-tap (tap=KEY, hold=mo LAYER)、
// 修飾子押下時は hold-tap をバイパスして単に &kp KEY を送出する。
// ARROW_BEHAVIOR は mod 押下時も hold-tap 経由でレイヤーに入れるが、こちらは bypass。
// name  : ベース名 (例: _tab → _tab と _tab_ht を生成)
// LAYER : hold 時に潜るレイヤー (例: TAB_LAYER)
// KEY   : tap 時に出すキー (例: TAB)
#define LAYER_TAP_MORPH_BYPASS(name, LAYER, KEY) \
    name##_ht: name##_ht { \
      compatible = "zmk,behavior-hold-tap"; \
      #binding-cells = <2>; \
      flavor = "tap-unless-interrupted"; \
      tapping-term-ms = <800>; \
      bindings = <&mo>, <&kp>; \
      hold-trigger-key-positions = <KEY_POSITION_LEFT_SIDE KEY_POSITION_L_THUMB>; \
    }; \
    name: name { \
      compatible = "zmk,behavior-mod-morph"; \
      #binding-cells = <0>; \
      bindings = <&name##_ht LAYER KEY>, <&kp KEY>; \
      mods = <ALL_MODS>; \
      keep-mods = <ALL_MODS>; \
    };

// LL/TAB/DELETE/<arrow> レイヤー全体を 1 行で生成。
// LAYER   : レイヤー名 (例: LL_LAYER)
// DISPLAY : keymap-drawer 用の表示名（例: "LL" / "⇥"）
// WRAP    : キー wrapper macro (例: X_LL / X_TAB / X_DOWN_ARROW)。WRAP(QQ) 等が
//           実際のキーコードに展開される (X_LL は object 参照、X_TAB 等は修飾子付与)
// R4R     : row4 右側 5 セル分（例: &none &none &none &none &none）
#define MORPH_LAYER(LAYER, DISPLAY, WRAP, R4R) \
    LAYER { \
      display-name = DISPLAY; \
      bindings = < \
        &kp WRAP(QQ)  &kp WRAP(Q)  &kp WRAP(W)  &kp WRAP(E)  &kp WRAP(R)  &kp WRAP(T)    &none  &none  &none  &none  &none  &none \
        &kp WRAP(AA)  &kp WRAP(A)  &kp WRAP(S)  &kp WRAP(D)  &kp WRAP(F)  &kp WRAP(G)    &none  &none  &none  &none  &none  &none \
        &kp WRAP(ZZ)  &kp WRAP(Z)  &kp WRAP(X)  &kp WRAP(C)  &kp WRAP(V)  &kp WRAP(B)    &none  &none  &none  &none  &none  &none \
        &none  &none  &kp WRAP(SYM2)  &kp WRAP(SYM1)  &kp WRAP(NUM)                      R4R \
        &none         &none         &none                                                &none  &none  &none \
        &kp WRAP(T_LL)  &kp WRAP(T_LR)  &none                                            &none  &none  &none \
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
      mods = <ALL_MODS>; \
      keep-mods = <ALL_MODS>; \
    };

// _a 〜 _z 系 letter mod-morph を生成。
// Shift 未押下 → 素のキー / Shift 押下 → eiji_macro 経由で英語入力モードへ切替えてから大文字出力。
// name   : 生成する behavior 名 (例: _a)
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
// name : 生成する behavior 名 (例: en0 / en_under)
// key  : 出力キー (例: N0 / UNDERSCORE)
// 注: keymap-drawer 上の表示は keymap_drawer.config.yaml の raw_binding_map で設定する。
#define EN_MACRO(name, key) \
    name: name { \
      compatible = "zmk,behavior-macro"; \
      #binding-cells = <0>; \
      bindings = <&macro_tap &kp EIJI>, <&macro_press &kp key>, <&macro_pause_for_release>, <&macro_release &kp key>; \
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
