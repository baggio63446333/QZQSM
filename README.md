# QZSS DC Report Service Decode Library

## はじめに

みちびき災害・危機管理通報サービスってご存知ですか？

> 災害・危機管理通報サービス  
> https://qzss.go.jp/overview/services/sv08_dc-report.html

防災機関から、地震、津波などの災害情報、避難勧告などの発令状況について、みちびきから送信するサービスです。このサービスは、利用者に災害情報などのメッセージを届けるサービスで、L1S信号を受信することができる端末で利用することができます。L1S信号は、衛星測位で一般的に利用しているGPSやみちびきのL1C/A信号と同じ周波数で同じ波形のため、受信機の価格を安く抑えることができます。

## 開発環境

GPS L1S信号受信機: [SPRESENSEボード](https://developer.sony.com/ja/develop/spresense/)

開発環境のセットアップ手順: [Spresense Arduino スタートガイド](https://developer.sony.com/develop/spresense/docs/arduino_set_up_ja.html) 

1. ボードマネージャのURLに追加  
https://github.com/sonydevworld/spresense-arduino-compatible/releases/download/generic/package_spresense_index.json
2. ボードマネージャからインストール


## NMEA QZQSM フォーマット

* `QZQSM` というNMEAセンテンスが送られてきます。仕様書はこちらにあります  
  https://qzss.go.jp/technical/download/ps-is-qzss.html

* 災害情報がいくつかのカテゴリに分かれています。
```cpp
#define QZQSM_ENABLE_DC1  // 緊急地震速報
#define QZQSM_ENABLE_DC2  // 震源
#define QZQSM_ENABLE_DC3  // 震度
#define QZQSM_ENABLE_DC4  // 南海トラフ地震
#define QZQSM_ENABLE_DC5  // 津波
#define QZQSM_ENABLE_DC6  // 北西太平洋津波
#define QZQSM_ENABLE_DC8  // 火山
#define QZQSM_ENABLE_DC9  // 降灰
#define QZQSM_ENABLE_DC10 // 気象
#define QZQSM_ENABLE_DC11 // 洪水
#define QZQSM_ENABLE_DC12 // 台風
#define QZQSM_ENABLE_DC14 // 海上
````

## サンプル

`DcReportMonitor` サンプルスケッチを実行してください。

`QZQSM` を受信するとシリアルモニタにデコードした文字列が表示されます。

![DCReport.png](https://qiita-image-store.s3.ap-northeast-1.amazonaws.com/0/432852/8f007cbd-507a-7765-2b51-a1675719a426.png)

## さいごに

災害の無い平和な世の中になりますように。
