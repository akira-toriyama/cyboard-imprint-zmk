# ZMK Configuration Template
Wireless Cyboard keyboard configuration repository template for using ZMK firmware. [Instructions for use are located on our documentation site](https://docs.cyboard.digital/user-manual/quick-start/configure-layout).

## Keymap

![keymap](keymap-drawer/imprint.svg)

SVG は push 時に [`.github/workflows/draw-keymap.yml`](.github/workflows/draw-keymap.yml) が [keymap-drawer](https://github.com/caksoylar/keymap-drawer) で自動生成・コミットします。

## Build

```bash
# zmk-workspace/
just build imprint_left

# 書き込みモード
cp ~/Documents/zmk/zmk-workspace/firmware/imprint_left-assimilator-bt.uf2 '/Volumes/NO NAME/'
```
