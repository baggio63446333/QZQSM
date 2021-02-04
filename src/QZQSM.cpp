/*********************************************************************************
 * BSD 3-Clause License
 *
 * Copyright (c) 2019, baggio63446333
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************************/

#include <QZQSM.h>

//===============================================================
// Private Functions
//===============================================================

//===============================================================
// Disaster Category Code 1
// JMA-DC Report (Earthquake Early Warning)

#ifdef QZQSM_ENABLE_DC1

#define DC1_REPORT \
  "災危通報(緊急地震速報)(%s)\n"

#define DC1_REPORT2 \
  "%s\n"

#define DC1_REPORT3 \
  "\n" \
  "発表時刻：%d月%d日%d時%d分\n\n" \
  "震央地名：%s\n" \
  "地震発生時刻：%d日%d時%d分\n" \
  "深さ(km)：%s\n" \
  "マグニチュード：%s\n" \
  "震度(下限)：%s\n" \
  "震度(上限)：%s\n"

#define DC1_REPORT4 \
  "%s\n"

#endif // QZQSM_ENABLE_DC1

#if defined(QZQSM_ENABLE_DC1) || defined(QZQSM_ENABLE_DC2) || defined(QZQSM_ENABLE_DC5)

// Notification on Disaster Prevention (Information)
const char* QZQSM::dc1co2str(int code)
{
  switch (code) {
  case   0: return "なし";
  case 101: return "今後若干の海面変動があるかもしれません。";
  case 102: return "今後若干の海面変動があるかもしれませんが、被害の心配はありません。";
  case 103: return "今後もしばらく海面変動が続くと思われます。";
  case 104: return "今後もしばらく海面変動が続くと思われますので、海水浴や磯釣り等を行う際は注意してください。";
  case 105: return "今後もしばらく海面変動が続くと思われますので、磯釣り等を行う際は注意してください。";
  case 107: return "現在、大津波警報・津波警報・津波注意報を発表している沿岸はありません。 ";
  case 109: return "津波と満潮が重なると、津波はより高くなりますので 一層厳重な警戒が必要です。";
  case 110: return "津波と満潮が重なると、津波はより高くなりますので十分な注意が必要です。";
  case 111: return "場所によっては、観測した津波の高さよりさらに大きな津波が到達しているおそれがあります。";
  case 112: return "今後、津波の高さは更に高くなることも考えられます。";
  case 113: return "沖合での観測値をもとに津波が推定されている沿岸では、早いところでは、既に津波が到達していると推定されます。";
  case 114: return "津波による潮位変化が観測されてから最大波が観測されるまでに数時間以上かかることがあります。";
  case 115: return "沖合での観測値であり、沿岸では津波はさらに高くなます。";
  case 121: return "＜大津波警報＞\n"
                   "　大きな津波が襲い甚大な被害が発生します。\n"
                   "　沿岸部や川沿いにる人はただちに高台や避難ビルなど安全な場所へ避難してください。\n"
                   "　津波は繰り返し襲ってきます。警報が解除されるまで安全な場所から離れないでください。";
  case 122: return "＜津波警報＞\n"
                   "　津波による被害が発生します。\n"
                   "　沿岸部や川沿いにる人はただちに高台や避難ビルなど安全な場所へ避難してください。\n"
                   "　津波は繰り返し襲ってきます。警報が解除されるまで安全な場所から離れないでください。";
  case 123: return "＜津波注意報＞\n"
                   "　海の中や海岸付近は危険です。\n"
                   "　海の中にいる人はただちに海から上がって、海岸から離れてください。\n"
                   "　潮の流れが速い状態が続きますで、注意報が解除さるるまで海に入ったり海岸に近づいたりしないようにしてください。";
  case 124: return "＜津波予報(若干の海面変動)＞\n"
                   "　若干の海面変動が予想されますが、被害の心配はありせん。";
  case 131: return "警報が発表された沿岸部や川沿いにいる人はただちに高台や避難ビルなど安全な場所へ避難してください。\n"
                   "到達予想時刻は、予報区のなかで最も早く津波が到達する時刻です。場所によっては、この時刻よりもかなり遅れて津波が襲ってくることがあります。\n"
                   "到達予想時刻から津波が最も高くなるまでに数時間以上かかることがありますので、観測された津波の高さにかかわらず、警報が解除されるまで安全な場所から離れないでください。";
  case 132: return "場所によっては津波の高さが「予想される津波の高さ」より高くなる可能性があります。";
  case 141: return "東日本大震災クラスの津波が来襲します。";
  case 142: return "沖合で高い津波を観測したため大津波警報・津波警報に切り替えました。";
  case 143: return "沖合で高い津波を観測したため大津波警報・津波警報を切り替えました。";
  case 144: return "沖合で高い津波を観測したため大津波警報に切り替えました。";
  case 145: return "沖合で高い津波を観測したため大津波警報を切り替えました。";
  case 146: return "沖合で高い津波を観測したため津波警報に切り替えました。";
  case 147: return "沖合で高い津波を観測したため津波警報を切り替えました。";
  case 148: return "沖合で高い津波を観測したため予想される津波の高さを切り替えました。";
  case 149: return "ただちに避難してくさい。";
  case 201: return "強い揺れに警戒してください。";
  case 211: return "津波警報等(大津波警報・津波警報あるいは津波注意報)を発表中です。";
  case 212: return "この地震により、日本の沿岸では若干の海面変動があるかもしれませんが、被害の心配はありません。";
  case 213: return "今後もしばらく海面変動が続と思われますので、海水浴や磯釣り等を行う際は注意してください。";
  case 214: return "今後もしばらく海面変動が続くと思われますので、磯釣り等を行う際は注意してください";
  case 215: return "この地震による津波の心配はありません。";
  case 216: return "震源が海底の場合、津波が発生するおそれがあります。";
  case 217: return "今後の情報に注意してください。";
  case 221: return "太平洋の広域に津波発生の可能性があります。";
  case 222: return "太平洋で津波発生の可能性があります。";
  case 223: return "北西太平洋で津波発生の可能性があります。";
  case 224: return "インド洋の広域に津波発生の可能性があります。";
  case 225: return "インド洋で津波発生の可能性があります。";
  case 226: return "震源の近傍で津波発生の可能性があります。";
  case 227: return "震源の近傍で小さな津波発生の可能性がありますが、被害をもたらす津波の心配はありません。";
  case 228: return "一般的に、この規模の地震が海域の浅い領域で発生すると 津波が発生することがあります。";
  case 229: return "日本への津波の有無については現在調査中です。";
  case 230: return "この地震による日本への津波の影響はありません。";
  case 241: return "この地震について、緊急地震速報を発表しています。";
  case 242: return "この地震について、緊急地震速報を発表しています。この地震の最大震度は2でした。";
  case 243: return "この地震について、緊急地震速報を発表しています。この地震の最大震度は1でした。";
  case 244: return "この地震について、緊急地震速報を発表しています。この地震で震度1以上は観測されていません。";
  case 245: return "この地震で緊急地震速報を発表しましたが、強い揺れは観測されませんでした。";
  case 256: return "震源要素を訂正します。";
  case 500: return "その他の防災上の留意事項";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "防災上の留意事項(コード番号：%d)", code);
    return _undefMessage;
  }
}
#endif // defined(QZQSM_ENABLE_DC1) || defined(QZQSM_ENABLE_DC2) || defined(QZQSM_ENABLE_DC5)

#if defined(QZQSM_ENABLE_DC1) || defined(QZQSM_ENABLE_DC2)

// Depth of Seismic Epicenter
const char* QZQSM::dc1de2str(int de)
{
  static char destr[8];
  if (511 == de) {
    return "不明";
  } else if (501 <= de) {
    return "500以上";
  } else {
    snprintf(destr, sizeof(destr), "%d", de);
    return destr;
  }
}

// Magnitude
const char* QZQSM::dc1ma2str(int ma)
{
  static char mastr[8];
  if (127 == ma) {
    return "不明";
  } else if (101 <= ma) {
    return "10.0以上";
  } else {
    snprintf(mastr, sizeof(mastr), "%d.%d", ma / 10, ma % 10);
    return mastr;
  }
}

// Seismic Epicenter
const char* QZQSM::dc1ep2str(int code)
{
  switch (code) {
  case  11: return "北海道地方";
  case  12: return "東北地方";
  case  13: return "北陸地方";
  case  14: return "関東甲信地方";
  case  15: return "小笠原地方";
  case  16: return "東海地方";
  case  17: return "近畿地方";
  case  18: return "中国地方";
  case  19: return "四国地方";
  case  20: return "九州地方";
  case  21: return "沖縄地方";
  case 100: return "石狩地方北部";
  case 101: return "石狩地方中部";
  case 102: return "石狩地方南部";
  case 105: return "渡島地方北部";
  case 106: return "渡島地方東部";
  case 107: return "渡島地方西部";
  case 110: return "檜山地方";
  case 115: return "後志地方北部";
  case 116: return "後志地方東部";
  case 117: return "後志地方西部";
  case 120: return "空知地方北部";
  case 121: return "空知地方中部";
  case 122: return "空知地方南部";
  case 125: return "上川地方北部";
  case 126: return "上川地方中部";
  case 127: return "上川地方南部";
  case 130: return "留萌地方中北部";
  case 131: return "留萌地方南部";
  case 135: return "宗谷地方北部";
  case 136: return "宗谷地方南部";
  case 140: return "網走地方";
  case 141: return "北見地方";
  case 142: return "紋別地方";
  case 145: return "胆振地方西部";
  case 146: return "胆振地方中東部";
  case 150: return "日高地方西部";
  case 151: return "日高地方中部";
  case 152: return "日高地方東部";
  case 155: return "十勝地方北部";
  case 156: return "十勝地方中部";
  case 157: return "十勝地方南部";
  case 160: return "釧路地方北部";
  case 161: return "釧路地方中南部";
  case 165: return "根室地方北部";
  case 166: return "根室地方中部";
  case 167: return "根室地方南部";
  case 180: return "北海道南西沖";
  case 181: return "北海道西方沖";
  case 182: return "石狩湾";
  case 183: return "北海道西沖";
  case 184: return "宗谷海峡";
  case 186: return "国後島付近";
  case 187: return "択捉島付近";
  case 188: return "北海道東方沖";
  case 189: return "根室半島南東沖";
  case 190: return "釧路沖";
  case 191: return "十勝沖";
  case 192: return "浦河沖";
  case 193: return "苫小牧沖";
  case 194: return "内浦湾";
  case 195: return "宗谷東方沖";
  case 196: return "網走沖";
  case 197: return "択捉島南東沖";
  case 200: return "青森県津軽北部";
  case 201: return "青森県津軽南部";
  case 202: return "青森県三八上北地方";
  case 203: return "青森県下北地方";
  case 210: return "岩手県沿岸北部";
  case 211: return "岩手県沿岸南部";
  case 212: return "岩手県内陸北部";
  case 213: return "岩手県内陸南部";
  case 220: return "宮城県北部";
  case 221: return "宮城県南部";
  case 222: return "宮城県中部";
  case 230: return "秋田県沿岸北部";
  case 231: return "秋田県沿岸南部";
  case 232: return "秋田県内陸北部";
  case 233: return "秋田県内陸南部";
  case 240: return "山形県庄内地方";
  case 241: return "山形県最上地方";
  case 242: return "山形県村地方";
  case 243: return "山形県置賜地方";
  case 250: return "福島県中通り";
  case 251: return "福島県浜通り";
  case 252: return "福島県会津";
  case 280: return "津軽海峡";
  case 281: return "山形県沖";
  case 282: return "秋田県沖";
  case 283: return "青森県西方沖";
  case 284: return "陸奥湾";
  case 285: return "青森県東方沖";
  case 286: return "岩手県沖";
  case 287: return "宮城県沖";
  case 288: return "三陸沖";
  case 289: return "福島県沖";
  case 300: return "茨城県北部";
  case 301: return "茨城県南部";
  case 309: return "千葉県南東沖";
  case 310: return "栃木県北部";
  case 311: return "栃木県南部";
  case 320: return "群馬県北部";
  case 321: return "群馬県南部";
  case 330: return "埼玉県北部";
  case 331: return "埼玉県南部";
  case 332: return "埼玉県秩父地方";
  case 340: return "千葉県北東部";
  case 341: return "千葉県北西部";
  case 342: return "千葉県南部";
  case 349: return "房総半島南方沖";
  case 350: return "東京都２３区";
  case 351: return "東京都多摩東部";
  case 352: return "東京都多摩西部";
  case 360: return "神奈川県東部";
  case 361: return "神奈川県西部";
  case 370: return "新潟県上越地方";
  case 371: return "新潟県中越地方";
  case 372: return "新潟県下越地方";
  case 378: return "新潟県下越沖";
  case 379: return "新潟県上中越沖";
  case 380: return "富山県東部";
  case 381: return "富山県西部";
  case 390: return "石川県能登地方";
  case 391: return "石川県加賀地方";
  case 400: return "福井県嶺北";
  case 401: return "福井県嶺南";
  case 411: return "山梨県中・西部";
  case 412: return "山梨県東部・富士五湖";
  case 420: return "長野県北部";
  case 421: return "長野県中部";
  case 422: return "長野県南部";
  case 430: return "岐阜県飛騨地方";
  case 431: return "岐阜県美濃東部";
  case 432: return "岐阜県美濃中西部";
  case 440: return "静岡県伊豆地方";
  case 441: return "静岡県東部";
  case 442: return "静岡県中部";
  case 443: return "静岡県西部";
  case 450: return "愛知県東部";
  case 451: return "愛知県西部";
  case 460: return "三重県北部";
  case 461: return "三重県中部";
  case 462: return "三重県南部";
  case 469: return "三重県南東沖";
  case 471: return "茨城県沖";
  case 472: return "関東東方沖";
  case 473: return "千葉県東方沖";
  case 475: return "八丈島東方沖";
  case 476: return "八丈島近海";
  case 477: return "東京湾";
  case 478: return "相模湾";
  case 480: return "伊豆大島近海";
  case 481: return "伊豆半島東方沖";
  case 482: return "三宅島近海";
  case 483: return "新島・神津島近海";
  case 485: return "駿河湾";
  case 486: return "駿河湾南方沖";
  case 487: return "遠州灘";
  case 489: return "三河湾";
  case 490: return "伊勢湾";
  case 492: return "若狭湾";
  case 493: return "福井県沖";
  case 494: return "石川県西方沖";
  case 495: return "能登半島沖";
  case 497: return "富山湾";
  case 498: return "佐渡付近";
  case 499: return "東海道南方沖";
  case 500: return "滋賀県北部";
  case 501: return "滋賀県南部";
  case 510: return "京都府北部";
  case 511: return "京都府南部";
  case 520: return "大阪府北部";
  case 521: return "大阪府南部";
  case 530: return "兵庫県北部";
  case 531: return "兵庫県南東部";
  case 532: return "兵庫県南西部";
  case 540: return "奈良県";
  case 550: return "和歌山県北部";
  case 551: return "和歌山県南部";
  case 560: return "鳥取県東部";
  case 562: return "鳥取県中部";
  case 563: return "鳥取県西部";
  case 570: return "島根県東部";
  case 571: return "島根県西部";
  case 580: return "岡山県北部";
  case 581: return "岡山県南部";
  case 590: return "広島県北部";
  case 591: return "広島県南東部";
  case 592: return "広島県南西部";
  case 600: return "徳島県北部";
  case 601: return "徳島県南部";
  case 610: return "香川県東部";
  case 611: return "香川県西部";
  case 620: return "愛媛県東予";
  case 621: return "愛媛県中予";
  case 622: return "愛媛県南予";
  case 630: return "高知県東部";
  case 631: return "高知県中部";
  case 632: return "高知県西部";
  case 673: return "土佐湾";
  case 674: return "紀伊水道";
  case 675: return "大阪湾";
  case 676: return "播磨灘";
  case 677: return "瀬戸内海中部";
  case 678: return "安芸灘";
  case 679: return "周防灘";
  case 680: return "伊予灘";
  case 681: return "豊後水道";
  case 682: return "山口県北西沖";
  case 683: return "島根県沖";
  case 684: return "鳥取県沖";
  case 685: return "隠岐島近海";
  case 686: return "兵庫県北方沖";
  case 687: return "京都府沖";
  case 688: return "淡路島付近";
  case 689: return "和歌山県南方沖";
  case 700: return "山口県北部";
  case 702: return "山口県西部";
  case 703: return "山口県東部";
  case 704: return "山口県中部";
  case 710: return "福岡県福岡地方";
  case 711: return "福岡県北九州地方";
  case 712: return "福岡県筑豊地方";
  case 713: return "福岡県筑後地方";
  case 720: return "佐賀県北部";
  case 721: return "佐賀県南部";
  case 730: return "長崎県北部";
  case 731: return "長崎県南西部";
  case 732: return "長崎県島原半島";
  case 740: return "熊本県阿蘇地方";
  case 741: return "熊本県熊本地方";
  case 742: return "熊本県球磨地方";
  case 743: return "熊本県天草・芦北地方";
  case 750: return "大分県北部";
  case 751: return "大分県中部";
  case 752: return "大分県南部";
  case 753: return "大分県西部";
  case 760: return "宮崎県北部平野部";
  case 761: return "宮崎県北部山沿い";
  case 762: return "宮崎県南部平野部";
  case 763: return "宮崎県南部山沿い";
  case 770: return "鹿児島県薩摩地方";
  case 771: return "鹿児島県大隅地方";
  case 783: return "五島列島近海";
  case 784: return "天草灘";
  case 785: return "有明海";
  case 786: return "橘湾";
  case 787: return "鹿児島湾";
  case 790: return "種子島近海";
  case 791: return "日向灘";
  case 793: return "奄美大島近海";
  case 795: return "壱岐・対馬近海";
  case 796: return "福岡県北西沖";
  case 797: return "薩摩半島西方沖";
  case 798: return "トカラ列島近海";
  case 799: return "奄美大島北西沖";
  case 820: return "大隅半島東方沖";
  case 821: return "九州地方南東沖";
  case 822: return "種子島南東沖";
  case 823: return "奄美大島北東沖";
  case 850: return "沖縄本島近海";
  case 851: return "南大東島近海";
  case 852: return "沖縄本島南方沖";
  case 853: return "宮古島近海";
  case 854: return "石垣島近海";
  case 855: return "石垣島南方沖";
  case 856: return "西表島付近";
  case 857: return "与那国島近海";
  case 858: return "沖縄本島北西沖";
  case 859: return "宮古島北西沖";
  case 860: return "石垣島北西沖";
  case 900: return "台湾付近";
  case 901: return "東シナ海";
  case 902: return "四国沖";
  case 903: return "鳥島近海";
  case 904: return "鳥島東方沖";
  case 905: return "オホーツク海南部";
  case 906: return "サハリン西方沖";
  case 907: return "日本海北部";
  case 908: return "日本海中部";
  case 909: return "日本海西部";
  case 911: return "父島近海";
  case 912: return "千島列島";
  case 913: return "千島列島南東沖";
  case 914: return "北海道南東沖";
  case 915: return "東北地方東方沖";
  case 916: return "小笠原諸島西方沖";
  case 917: return "硫黄島近海";
  case 918: return "小笠原諸島東方沖";
  case 919: return "南海道南方沖";
  case 920: return "薩南諸島東方沖";
  case 921: return "本州南方沖";
  case 922: return "サハリン南部付近";
  case 930: return "北西太平洋";
  case 932: return "マリアナ諸島";
  case 933: return "黄海";
  case 934: return "朝鮮半島南部";
  case 935: return "朝鮮半島北部";
  case 936: return "中国東北部";
  case 937: return "ウラジオストク付近";
  case 938: return "シベリア南部";
  case 939: return "サハリン近海";
  case 940: return "アリューシャン列島";
  case 941: return "カムチャツカ半島付近";
  case 942: return "北米西部";
  case 943: return "北米中部";
  case 944: return "北米東部";
  case 945: return "中米";
  case 946: return "南米西部";
  case 947: return "南米中部";
  case 948: return "南米東部";
  case 949: return "北東太平洋";
  case 950: return "南太平洋";
  case 951: return "インドシナ半島付近";
  case 952: return "フィリピン付近";
  case 953: return "インドネシア付近";
  case 954: return "グアム付近";
  case 955: return "ニューギア付近";
  case 956: return "ニュージランド付近";
  case 957: return "オーストラリア付近";
  case 958: return "シベリア付近";
  case 959: return "ロシア西部";
  case 960: return "ロシア中部";
  case 961: return "ロシア東部";
  case 962: return "中央アジア";
  case 963: return "中国西部";
  case 964: return "中国中部";
  case 965: return "中国東部";
  case 966: return "インド付近";
  case 967: return "インド洋";
  case 968: return "中東";
  case 969: return "ヨーロッパ西部";
  case 970: return "ヨーロッパ中部";
  case 971: return "ヨーロッパ東部";
  case 972: return "地中海";
  case 973: return "アフリカ西部";
  case 974: return "アフリカ中部";
  case 975: return "アフリカ東部";
  case 976: return "北大西洋";
  case 977: return "南大西洋";
  case 978: return "北極付近";
  case 979: return "南極付近";
  case 999: return "遠地";
  case 1000: return "その他震央地名";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "震央地名(コード番号：%d)", code);
    return _undefMessage;
  }
}
#endif // defined(QZQSM_ENABLE_DC1) || defined(QZQSM_ENABLE_DC2)

#ifdef QZQSM_ENABLE_DC1

// Seismic Intensity
const char* QZQSM::dc1si2str(int code)
{
  switch (code) {
  case  1: return "震度0";
  case  2: return "震度1";
  case  3: return "震度2";
  case  4: return "震度3";
  case  5: return "震度4";
  case  6: return "震度5弱";
  case  7: return "震度5強";
  case  8: return "震度6弱";
  case  9: return "震度6強";
  case 10: return "震度7";
  case 11: return "～程度以上";
  case 14: return "なし";
  case 15: return "不明";
  default: return "";
  }
}

// Forecast Region Earthquake Early Warning (Region)
const char* QZQSM::dc1pl2str(int code)
{
  switch (code) {
  case  1: return "北海道道央";
  case  2: return "北海道道南";
  case  3: return "北海道道北";
  case  4: return "北海道道東";
  case  5: return "青森";
  case  6: return "岩手";
  case  7: return "宮城";
  case  8: return "秋田";
  case  9: return "山形";
  case 10: return "福島";
  case 11: return "茨城";
  case 12: return "栃木";
  case 13: return "群馬";
  case 14: return "埼玉";
  case 15: return "千葉";
  case 16: return "東京";
  case 17: return "伊豆諸島";
  case 18: return "小笠原";
  case 19: return "神奈川";
  case 20: return "新潟";
  case 21: return "富山";
  case 22: return "石川";
  case 23: return "福井";
  case 24: return "山梨";
  case 25: return "長野";
  case 26: return "岐阜";
  case 27: return "静岡";
  case 28: return "愛知";
  case 29: return "三重";
  case 30: return "滋賀";
  case 31: return "京都";
  case 32: return "大阪";
  case 33: return "兵庫";
  case 34: return "奈良";
  case 35: return "和歌山";
  case 36: return "鳥取";
  case 37: return "島根";
  case 38: return "岡山";
  case 39: return "広島";
  case 40: return "山口";
  case 41: return "徳島";
  case 42: return "香川";
  case 43: return "愛媛";
  case 44: return "高知";
  case 45: return "福岡";
  case 46: return "佐賀";
  case 47: return "長崎";
  case 48: return "熊本";
  case 49: return "大分";
  case 50: return "宮崎";
  case 51: return "鹿児島";
  case 52: return "奄美(群島)";
  case 53: return "沖縄本島";
  case 54: return "大東島";
  case 55: return "宮古島";
  case 56: return "八重山";
  case 57: return "北海道";
  case 58: return "東北";
  case 59: return "関東";
  case 60: return "伊豆諸島";
  case 61: return "小笠原";
  case 62: return "北陸";
  case 63: return "甲信";
  case 64: return "東海";
  case 65: return "近畿";
  case 66: return "中国";
  case 67: return "四国";
  case 68: return "九州";
  case 69: return "奄美(群島)";
  case 70: return "沖縄";
  case 80: return "その他府県予報区および地方予報区";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "府県予報区および地方予報区(地点：%d)", code);
    return _undefMessage;
  }
}

int QZQSM::filter_dc1()
{
  // You can filter out the specific region or information.
  return 1;
}

void QZQSM::report_dc1()
{
  _len += snprintf(&_message[_len], sizeof(_message) - _len,
                   DC1_REPORT, it2str(_Header.It));
  int num;
  for (num = 0; num < 3; num++) {
    if (_u.Dc1.Co[num] != 0) {
      _len += snprintf(&_message[_len], sizeof(_message) - _len,
                       DC1_REPORT2, dc1co2str(_u.Dc1.Co[num]));
    }
  }
  _len += snprintf(&_message[_len], sizeof(_message) - _len,
                   DC1_REPORT3, _jstAtMo, _jstAtD, _jstAtH, _jstAtMi,
                   dc1ep2str(_u.Dc1.Ep),
                   _u.Dc1.OtD, _u.Dc1.OtH, _u.Dc1.OtM,
                   dc1de2str(_u.Dc1.De),
                   dc1ma2str(_u.Dc1.Ma),
                   dc1si2str(_u.Dc1.Ll), dc1si2str(_u.Dc1.Ul));
  int b;
  for (b = 0; b < 32; b++) {
    if (_u.Dc1.Pl[0] & (1 << (31 - b))) {
      _len += snprintf(&_message[_len], sizeof(_message) - _len,
                       DC1_REPORT4, dc1pl2str(b + 1));
    }
  }
  for (b = 0; b < 32; b++) {
    if (_u.Dc1.Pl[1] & (1 << (31 - b))) {
      _len += snprintf(&_message[_len], sizeof(_message) - _len,
                       DC1_REPORT4, dc1pl2str(b + 32 + 1));
    }
  }
  for (b = 0; b < 16; b++) {
    if (_u.Dc1.Pl[2] & (1 << (15 - b))) {
      _len += snprintf(&_message[_len], sizeof(_message) - _len,
                       DC1_REPORT4, dc1pl2str(b + 64 + 1));
    }
  }
}

void QZQSM::decode_dc1()
{
  int num;
  for (num = 0; num < 3; num++) {
    _u.Dc1.Co[num] = get_val(53 + (9 * num), 9);
  }
  _u.Dc1.OtD = get_val(80, 5);
  _u.Dc1.OtH = get_val(85, 5);
  _u.Dc1.OtM = get_val(90, 6);
  _u.Dc1.De  = get_val(96, 9);
  _u.Dc1.Ma  = get_val(105, 7);
  _u.Dc1.Ep  = get_val(112, 10);
  _u.Dc1.Ll  = get_val(122, 4);
  _u.Dc1.Ul  = get_val(126, 4);
  _u.Dc1.Pl[0] = get_val(130, 32);
  _u.Dc1.Pl[1] = get_val(162, 32);
  _u.Dc1.Pl[2] = get_val(194, 16);

  utc2jst(_Header.AtMo, _u.Dc1.OtD, _u.Dc1.OtH, _u.Dc1.OtM);
}
#endif // QZQSM_ENABLE_DC1

//===============================================================
// Disaster Category Code 2
// JMA-DC Report (Hypocenter)

#ifdef QZQSM_ENABLE_DC2

#define DC2_REPORT \
  "災危通報(震源)(%s)\n" \
  "%d日%d時%d分ころ、地震がありました。\n"

#define DC2_REPORT2 \
  "%s\n"

#define DC2_REPORT3 \
  "\n" \
  "発表時刻：%d月%d日%d時%d分\n\n" \
  "震央地名：%s\n" \
  "緯度・経度：%s%d度%d分%d秒 %s%d度%d分%d秒\n" \
  "深さ(km)：%s\n" \
  "マグニチュード：%s\n"

int QZQSM::filter_dc2()
{
  // You can filter out the specific region or information.
  return 1;
}

void QZQSM::report_dc2()
{
  _len += snprintf(&_message[_len], sizeof(_message) - _len,
                   DC2_REPORT, it2str(_Header.It), _u.Dc2.OtD, _u.Dc2.OtH, _u.Dc2.OtM);
  int num;
  for (num = 0; num < 3; num++) {
    if (_u.Dc2.Co[num] != 0) {
      _len += snprintf(&_message[_len], sizeof(_message) - _len,
                       DC2_REPORT2, dc1co2str(_u.Dc2.Co[num]));
    }
  }
  _len += snprintf(&_message[_len], sizeof(_message) - _len,
                   DC2_REPORT3, _jstAtMo, _jstAtD, _jstAtH, _jstAtMi,
                   dc1ep2str(_u.Dc2.Ep),
                   _u.Dc2.LatNs ? "南緯" : "北緯", _u.Dc2.LatD, _u.Dc2.LatM, _u.Dc2.LatS,
                   _u.Dc2.LonEw ? "西経" : "東経", _u.Dc2.LonD, _u.Dc2.LonM, _u.Dc2.LonS,
                   dc1de2str(_u.Dc2.De),
                   dc1ma2str(_u.Dc2.Ma));
}

void QZQSM::decode_dc2()
{
  _u.Dc2.OtD = get_val(80, 5);
  _u.Dc2.OtH = get_val(85, 5);
  _u.Dc2.OtM = get_val(90, 6);
  int num;
  for (num = 0; num < 3; num++) {
    _u.Dc2.Co[num] = get_val(53 + (9 * num), 9);
  }
  _u.Dc2.De = get_val(96, 9);
  _u.Dc2.Ma = get_val(105, 7);
  _u.Dc2.Ep = get_val(112, 10);
  _u.Dc2.LatNs = get_val(122, 1);
  _u.Dc2.LatD = get_val(123, 7);
  _u.Dc2.LatM = get_val(130, 6);
  _u.Dc2.LatS = get_val(136, 6);
  _u.Dc2.LonEw = get_val(142, 1);
  _u.Dc2.LonD = get_val(143, 8);
  _u.Dc2.LonM = get_val(151, 6);
  _u.Dc2.LonS = get_val(157, 6);

  utc2jst(_Header.AtMo, _u.Dc2.OtD, _u.Dc2.OtH, _u.Dc2.OtM);
}
#endif // QZQSM_ENABLE_DC2

//===============================================================
// Disaster Category Code 3
// JMA-DC Report (Seismic Intensity)

#ifdef QZQSM_ENABLE_DC3

#define DC3_REPORT \
  "災危通報(震度)(%s)\n" \
  "%d日%d時%d分ころ、地震による強い揺れを感じました。\n" \
  "\n" \
  "発表時刻：%d月%d日%d時%d分\n\n"

#define DC3_REPORT2 \
  "%s：%s\n"

// Seismic Intensity (Region)
const char* QZQSM::dc3es2str(int code)
{
  switch (code) {
  case 1: return "震度4未満";
  case 2: return "震度4";
  case 3: return "震度5弱";
  case 4: return "震度5強";
  case 5: return "震度6弱";
  case 6: return "震度6強";
  case 7: return "震度7";
  default: return "";
  }
}

// Prefecture (Region)
const char* QZQSM::dc3pl2str(int code)
{
  switch (code) {
  case  1: return "北海道";
  case  2: return "青森県";
  case  3: return "岩手県";
  case  4: return "宮城県";
  case  5: return "秋田県";
  case  6: return "山形県";
  case  7: return "福島県";
  case  8: return "茨城県";
  case  9: return "栃木県";
  case 10: return "群馬県";
  case 11: return "埼玉県";
  case 12: return "千葉県";
  case 13: return "東京都";
  case 14: return "神奈川県";
  case 15: return "新潟県";
  case 16: return "富山県";
  case 17: return "石川県";
  case 18: return "福井県";
  case 19: return "山梨県";
  case 20: return "長野県";
  case 21: return "岐阜県";
  case 22: return "静岡県";
  case 23: return "愛知県";
  case 24: return "三重県";
  case 25: return "滋賀県";
  case 26: return "京都府";
  case 27: return "大阪府";
  case 28: return "兵庫県";
  case 29: return "奈良県";
  case 30: return "和歌山県";
  case 31: return "鳥取県";
  case 32: return "島根県";
  case 33: return "岡山県";
  case 34: return "広島県";
  case 35: return "山口県";
  case 36: return "徳島県";
  case 37: return "香川県";
  case 38: return "愛媛県";
  case 39: return "高知県";
  case 40: return "福岡県";
  case 41: return "佐賀県";
  case 42: return "長崎県";
  case 43: return "熊本県";
  case 44: return "大分県";
  case 45: return "宮崎県";
  case 46: return "鹿児島県";
  case 47: return "沖縄県";
  default: return "";
  }
}

int QZQSM::filter_dc3()
{
  // You can filter out the specific region or information.
  return 1;
}

void QZQSM::report_dc3()
{
  _len += snprintf(&_message[_len], sizeof(_message) - _len,
                   DC3_REPORT, it2str(_Header.It), _u.Dc3.OtD, _u.Dc3.OtH, _u.Dc3.OtM,
                   _jstAtMo, _jstAtD, _jstAtH, _jstAtMi);
  int num;
  for (num = 0; num < 16; num++) {
    if ((_u.Dc3.site[num].Es != 0) && (_u.Dc3.site[num].Pl != 0)) {
      _len += snprintf(&_message[_len], sizeof(_message) - _len,
                       DC3_REPORT2, dc3es2str(_u.Dc3.site[num].Es), dc3pl2str(_u.Dc3.site[num].Pl));
    }
  }
}

void QZQSM::decode_dc3()
{
  _u.Dc3.OtD = get_val(53, 5);
  _u.Dc3.OtH = get_val(58, 5);
  _u.Dc3.OtM = get_val(63, 6);
  int num;
  for (num = 0; num < 16; num++) {
    _u.Dc3.site[num].Es = get_val(69 + (9 * num), 3);
    _u.Dc3.site[num].Pl = get_val(72 + (9 * num), 6);
  }
  utc2jst(_Header.AtMo, _u.Dc3.OtD, _u.Dc3.OtH, _u.Dc3.OtM);
}
#endif // QZQSM_ENABLE_DC3

//===============================================================
// Disaster Category Code 4
// JMA-DC Report (Nankai Trough Earthquake)

#ifdef QZQSM_ENABLE_DC4

#define DC4_REPORT \
  "災危通報(南海トラフ地震)(%s)(%d/%d)\n\n" \
  "発表時刻：%d月%d日%d時%d分\n\n"

#define DC4_REPORT2 \
  "%s\n"

int QZQSM::filter_dc4()
{
  // You can filter out the specific region or information.
  return 1;
}

void QZQSM::report_dc4()
{
  _len += snprintf(&_message[_len], sizeof(_message) - _len,
                   DC4_REPORT, it2str(_Header.It), _u.Dc4.Pn, _u.Dc4.Pm, _jstAtMo, _jstAtD, _jstAtH, _jstAtMi);
  int num;
  for (num = 0; num < 18; num++) {
    if (_u.Dc4.Te[num] == 0) {
      break;
    }
  }
  _len += snprintf(&_message[_len], sizeof(_message) - _len,
                   DC4_REPORT2, _u.Dc4.Te);
}

void QZQSM::decode_dc4()
{
  _u.Dc4.Pn = get_val(201, 6);
  _u.Dc4.Pm = get_val(207, 6);
  int num;
  for (num = 0; num < 18; num++) {
    _u.Dc4.Te[num] = get_val(57 + (8 * num), 8);
  }
}
#endif // QZQSM_ENABLE_DC4

//===============================================================
// Disaster Category Code 5
// JMA-DC Report (Tsunami)

#ifdef QZQSM_ENABLE_DC5

#define DC5_REPORT \
  "災危通報(津波)(%s)\n" \
  "%sを発表しました。\n"

#define DC5_REPORT2 \
  "%s\n"

#define DC5_REPORT3 \
  "\n" \
  "発表時刻：%d月%d日%d時%d分\n\n"

#define DC5_REPORT4 \
  "津波到達予想時刻：%s\n" \
  "津波の高さ：%s\n" \
  "%s\n\n"

// Warning Code
const char* QZQSM::dc5dw2str(int code)
{
  switch (code) {
  case  1: return "津波なし";
  case  2: return "警報解除";
  case  3: return "津波警報";
  case  4: return "大津波警報";
  case  5: return "大津波警報：発表";
  case 15: return "その他の警報";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "警報(コード番号：%d)", code);
    return _undefMessage;
  }
}

// Tsunami Arrival Time
const char* QZQSM::dc5ta2str(int h, int m)
{
  if ((h == 31) && (m == 63)) {
    return "到達";
  }
  snprintf(_undefMessage, sizeof(_undefMessage),
           "%d時%d分", h, m);
  return _undefMessage;
}

// Tsunami Height
const char* QZQSM::dc5th2str(int code)
{
  switch (code) {
  case  1: return "0.2m未満";
  case  2: return "1m";
  case  3: return "3m";
  case  4: return "5m";
  case  5: return "10m";
  case  6: return "10m超";
  case 14: return "不明";
  case 15: return "その他の津波の高さ";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "津波の高さ(コード番号：%d)", code);
    return _undefMessage;
  }
}

// Tsunami Forecast Region
const char* QZQSM::dc5pl2str(int code)
{
  switch (code) {
  case  11000: return "宗谷地方";
  case 100: return "北海道太平洋沿岸東部";
  case 101: return "北海道太平洋沿岸中部";
  case 102: return "北海道太平洋沿岸西部";
  case 110: return "北海道日本沿岸北部";
  case 111: return "北海道日本沿岸南部";
  case 120: return "オホーツク海沿岸";
  case 191: return "北海道太平洋沿岸";
  case 192: return "北海道日本海沿岸";
  case 193: return "オホーツク海沿岸";
  case 200: return "青森県日本海沿岸";
  case 201: return "青森県太平洋沿岸";
  case 202: return "陸奥湾";
  case 210: return "岩手県";
  case 220: return "宮城県";
  case 230: return "秋田県";
  case 240: return "山形県";
  case 250: return "福島県";
  case 281: return "青森県";
  case 291: return "東北地方太平洋沿岸";
  case 292: return "東北地方日本海沿岸";
  case 300: return "茨城県";
  case 310: return "千葉県九十里・外房";
  case 311: return "千葉県内房";
  case 312: return "東京湾内湾";
  case 320: return "伊豆諸島";
  case 321: return "小笠原諸島";
  case 330: return "相模湾・三浦半島";
  case 340: return "新潟県上中下越";
  case 341: return "佐渡";
  case 350: return "富山県";
  case 360: return "石川県能登";
  case 361: return "石川県加賀";
  case 370: return "福井県";
  case 380: return "静岡県";
  case 390: return "愛知県外海";
  case 391: return "伊勢・三河湾";
  case 400: return "三重県南部";
  case 481: return "千葉県";
  case 482: return "神奈川県";
  case 483: return "新潟県";
  case 484: return "石川県";
  case 485: return "愛知県";
  case 486: return "三重県";
  case 491: return "関東地方";
  case 492: return "伊豆・小笠原諸島";
  case 493: return "北陸地方";
  case 494: return "東海地方";
  case 500: return "京都府";
  case 510: return "大阪府";
  case 520: return "兵庫県北部";
  case 521: return "兵庫県瀬戸内海沿岸";
  case 522: return "淡路島南部";
  case 530: return "和歌山県";
  case 540: return "鳥取県";
  case 550: return "島根県出雲・石見";
  case 551: return "隠岐";
  case 560: return "岡山県";
  case 570: return "広島県";
  case 580: return "徳島県";
  case 590: return "香川県";
  case 600: return "愛媛県宇和海沿岸";
  case 601: return "愛媛県瀬戸内海沿岸";
  case 610: return "高知県";
  case 681: return "兵庫県";
  case 682: return "島根県";
  case 683: return "愛媛県";
  case 691: return "近畿四国太平洋沿岸";
  case 692: return "近畿中国日本海沿岸";
  case 693: return "瀬戸内海沿岸";
  case 700: return "山口県日本海沿岸";
  case 701: return "山口県瀬戸内海沿岸";
  case 710: return "福岡県瀬戸内海沿岸";
  case 711: return "福岡県日本海沿岸";
  case 712: return "有明・八代海";
  case 720: return "佐賀県北部";
  case 730: return "長崎県西方";
  case 731: return "壱岐・対馬";
  case 740: return "熊本県天草灘沿岸";
  case 750: return "大分県瀬戸内海沿岸";
  case 751: return "大分県豊後水道沿岸";
  case 760: return "宮崎県";
  case 770: return "鹿児島県東部";
  case 771: return "種子島・屋久島地方";
  case 772: return "奄美群島・トカラ列島";
  case 773: return "鹿児島県西部";
  case 781: return "山口県";
  case 782: return "福岡県";
  case 783: return "佐賀県";
  case 784: return "長崎県";
  case 785: return "熊本県";
  case 786: return "大分県";
  case 787: return "鹿児島県";
  case 791: return "九州地方東部";
  case 792: return "九州地方西部";
  case 793: return "薩南諸島";
  case 800: return "沖縄本島地方";
  case 801: return "大東島地方";
  case 802: return "宮古島・八重山地方";
  case 891: return "沖縄県地方";
  case 990: return "GPS波浪計";
  case 1000: return "その他津波予報区";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "津波予報区(コード番号：%d)", code);
    return _undefMessage;
  }
}

int QZQSM::filter_dc5()
{
  // You can filter out the specific region or information.
  return 1;
}

void QZQSM::report_dc5()
{
  _len += snprintf(&_message[_len], sizeof(_message) - _len,
                   DC5_REPORT, it2str(_Header.It), dc5dw2str(_u.Dc5.Dw));
  int num;
  for (num = 0; num < 3; num++) {
    if (_u.Dc5.Co[num] != 0) {
      _len += snprintf(&_message[_len], sizeof(_message) - _len,
                       DC5_REPORT2, dc1co2str(_u.Dc5.Co[num]));
    }
  }
  _len += snprintf(&_message[_len], sizeof(_message) - _len,
                   DC5_REPORT3, _jstAtMo, _jstAtD, _jstAtH, _jstAtMi);
  for (num = 0; num < 5; num++) {
    if (_u.Dc5.site[num].Pl != 0) {
      _len += snprintf(&_message[_len], sizeof(_message) - _len,
                       DC5_REPORT4, dc5ta2str(_u.Dc5.site[num].TaH, _u.Dc5.site[num].TaM),
                       dc5th2str(_u.Dc5.site[num].Th), dc5pl2str(_u.Dc5.site[num].Pl));
    }
  }
}

void QZQSM::decode_dc5()
{
  _u.Dc5.Dw = get_val(80, 4);
  int num;
  for (num = 0; num < 3; num++) {
    _u.Dc5.Co[num] = get_val(53 + (9 * num), 9);
  }
  for (num = 0; num < 5; num++) {
    _u.Dc5.site[num].TaD = get_val(84 + (26 * num), 1);
    _u.Dc5.site[num].TaH = get_val(85 + (26 * num), 5);
    _u.Dc5.site[num].TaM = get_val(90 + (26 * num), 6);
    _u.Dc5.site[num].Th  = get_val(96 + (26 * num), 4);
    _u.Dc5.site[num].Pl  = get_val(100 + (26 * num), 10);
    utc2jst(_Header.AtMo, _Header.AtD, _u.Dc5.site[num].TaH, _u.Dc5.site[num].TaM);
  }
}
#endif // QZQSM_ENABLE_DC5

//===============================================================
// Disaster Category Code 6
// JMA-DC Report (Northwest Pacific Tsunami)

#ifdef QZQSM_ENABLE_DC6

#define DC6_REPORT \
  "災危通報(北西太平洋津波)(%s)\n" \
  "%s\n\n" \
  "発表時刻：%d月%d日%d時%d分\n\n"

#define DC6_REPORT2 \
  "津波到達予想時刻：%s\n" \
  "津波の高さ：%s\n" \
  "%s\n\n"

// Tsunamigenic Potential
const char* QZQSM::dc6tp2str(int code)
{
  switch (code) {
  case 0: return "THERE IS NO POSSIBILITY OF A TSUNAMI";
  case 1: return "THERE IS A POSSIBILITY OF A DESTRUCTIVE OCEAN-WIDE TSUNAMI";
  case 2: return "THERE IS A POSSIBILITY OF A DESTRUCTIVE REGIONAL TSUNAMI";
  case 3: return "THERE IS A POSSIBILITY OF A DESTRUCTIVE LOCAL TSUNAMI NEAR THE EPICENTER";
  case 4: return "THERE IS A VERY SMALL POSSIBILITY OF A DESTRUCTIVE LOCAL TSUNAMI";
  case 7: return "その他の津波発生の可能性有無";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "津波発生の可能性有無(コード番号：%d)", code);
    return _undefMessage;
  }
}

// Tsunami Arrival Time
const char* QZQSM::dc6ta2str(int h, int m)
{
  if ((h == 31) && (m == 63)) {
    return "到達or不明";
  }
  snprintf(_undefMessage, sizeof(_undefMessage),
           "%d時%d分", h, m);
  return _undefMessage;
}

// Tsunami Height
const char* QZQSM::dc6th2str(int code)
{
  switch (code) {
  case   1: return "0.3m～1m";
  case   2: return "1m～3m";
  case   3: return "3m～5m";
  case   4: return "5m～10m";
  case 508: return "10m超";
  case 509: return "巨大";
  case 510: return "高い";
  case 511: return "不明";
  default: return "";
  }
}

// Coastal Region
const char* QZQSM::dc6pl2str(int code)
{
  switch (code) {
  case  1: return "Ust-Kamchatsk (Kamchatka Peninsula east coast)";
  case  2: return "Petropavlovsk (Kamchatka Peninsula east coast)";
  case  3: return "Severo Kurilsk (Kuril Islands)";
  case  4: return "Urup Islands (Kuril Islands)";
  case  5: return "Busan (Korean Peninsula south coast)";
  case  6: return "Nohwa (Korean Peninsula south coast)";
  case  7: return "Seogwipo (Korean Peninsula south coast)";
  case  8: return "Fualien (Taiwan east coast)";
  case  9: return "Basco (Philippines east coast)";
  case 10: return "Palanan (Philippines east coast)";
  case 11: return "Legaspi (Philippines east coast)";
  case 12: return "Laoang (Philippines east coast)";
  case 13: return "Madrid (Philippines east coast)";
  case 14: return "Davao (Philippines east coast)";
  case 15: return "Berebere (Irian Jaya north coast)";
  case 16: return "Patani (Irian Jaya north coast)";
  case 17: return "Sorong (Irian Jaya north coast)";
  case 18: return "Manokwari (Irian Jaya north coast)";
  case 19: return "Warsa (Irian Jaya north coast)";
  case 20: return "Jayapura (Irian Jaya north coast)";
  case 21: return "Vanimo (Papua New Guinea north coast)";
  case 22: return "Wewak (Papua New Guinea north coast)";
  case 23: return "Madang (Papua New Guinea north coast)";
  case 24: return "Manus Islands (Papua New Guinea north coast)";
  case 25: return "Rabaul (Papua New Guinea north coast)";
  case 26: return "Kavieng (Papua New Guinea north coast)";
  case 27: return "Kimbe (Papua New Guinea north coast)";
  case 28: return "Kieta (Papua New Guinea north coast)";
  case 29: return "Guam (Mariana Islands)";
  case 30: return "Saipan (Mariana Islands)";
  case 31: return "Malakal (Palau Islands)";
  case 32: return "Yap Island (Micronesia)";
  case 33: return "Chuuk Island (Micronesia)";
  case 34: return "Pohnpei Island (Micronesia)";
  case 35: return "Kosrae Island (Micronesia)";
  case 36: return "Eniwetok Island (Marshall Islands)";
  case 37: return "Panggoe (Solomon Islands north coast)";
  case 38: return "Auki (Solomon Islands north coast)";
  case 39: return "Kirakira (Solomon Islands north coast)";
  case 40: return "Munda (Solomon Sea)";
  case 41: return "Honiara (Solomon Sea)";
  case 42: return "Hong Kong (South China Sea north coast)";
  case 43: return "Sanya (South China Sea north coast)";
  case 44: return "Vinh (Tonkin Gulf coast)";
  case 45: return "Qui Nhon (Indochina Peninsula east coast)";
  case 46: return "Bac Lieu (Indochina Peninsula east coast)";
  case 47: return "Prachuap Khiri Khan (Thailand Gulf coast)";
  case 48: return "Sihanoukville (Thailand Gulf coast)";
  case 49: return "Nakhon Si Thammarat (Thailand Gulf coast)";
  case 50: return "Muara (Kalimantan northwest coast)";
  case 51: return "Bintulu (Kalimantan northwest coast)";
  case 52: return "Laoag (Philippines west coast)";
  case 53: return "San Fernando (Philippines west coast)";
  case 54: return "Manila (Philippines west coast)";
  case 55: return "Iloilo (Sulu Sea coast)";
  case 56: return "Puerto Princesa (Sulu Sea coast)";
  case 57: return "Sandakan (Sulu Sea coast)";
  case 58: return "Kuara Terengganu (Malay Peninsula east coast)";
  case 59: return "Singapore (Malay Peninsula east coast)";
  case 60: return "Zamboanga (Celebes Sea coast)";
  case 61: return "Tarakan (Celebes Sea coast)";
  case 62: return "Manado (Celebes Sea coast)";
  case 63: return "Tolitoli (Celebes Sea coast)";
  case 64: return "Singkawang (Natuna Sea coast)";
  case 65: return "Pangkalpinang (Natuna Sea coast)";
  case 99: return "Unknown";
  case 100: return "Other region";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "Coastal Region(Code:%d)", code);
    return _undefMessage;
  }
}

int QZQSM::filter_dc6()
{
  // You can filter out the specific region or information.
  return 1;
}

void QZQSM::report_dc6()
{
  _len += snprintf(&_message[_len], sizeof(_message) - _len,
                   DC6_REPORT, it2str(_Header.It), dc6tp2str(_u.Dc6.Tp),
                   _jstAtMo, _jstAtD, _jstAtH, _jstAtMi);
  int num;
  for (num = 0; num < 5; num++) {
    if (_u.Dc6.site[num].Pl != 0) {
      _len += snprintf(&_message[_len], sizeof(_message) - _len,
                       DC6_REPORT2, dc6ta2str(_u.Dc6.site[num].TaH, _u.Dc6.site[num].TaM),
                       dc6th2str(_u.Dc6.site[num].Th), dc6pl2str(_u.Dc6.site[num].Pl));
    }
  }
}

void QZQSM::decode_dc6()
{
  _u.Dc6.Tp = get_val(53, 3);
  int num;
  for (num = 0; num < 5; num++) {
    _u.Dc6.site[num].TaD = get_val(56 + (28 * num), 1);
    _u.Dc6.site[num].TaH = get_val(57 + (28 * num), 5);
    _u.Dc6.site[num].TaM = get_val(62 + (28 * num), 6);
    _u.Dc6.site[num].Th  = get_val(68 + (28 * num), 9);
    _u.Dc6.site[num].Pl  = get_val(77 + (28 * num), 7);
    utc2jst(_Header.AtMo, _Header.AtD, _u.Dc6.site[num].TaH, _u.Dc6.site[num].TaM);
  }
}
#endif // QZQSM_ENABLE_DC6

//===============================================================
// Disaster Category Code 8
// JMA-DC Report (Volcano)

#ifdef QZQSM_ENABLE_DC8

#define DC8_REPORT \
  "災危通報(火山)(%s)\n\n" \
  "発表時刻：%d月%d日%d時%d分\n\n" \
  "火山名：%s\n" \
  "日時：%s\n" \
  "現象：%s\n" \

#define DC8_REPORT2 \
  "%s\n"

// Activity Time
const char* QZQSM::dc8td2str(int d, int h, int m)
{
  if ((h == 31) && (m == 63)) {
    return "不明";
  }
  snprintf(_undefMessage, sizeof(_undefMessage),
           "%d日%d時%d分", d, h, m);
  return _undefMessage;
}

// Warning Code
const char* QZQSM::dc8dw2str(int code)
{
  switch (code) {
  case 1: return "噴火警報";
  case 2: return "火口周辺警報";
  case 3: return "噴火警報(周辺海域)";
  case 4: return "噴火予報：警報解除";
  case 5: return "噴火予報";
  case 11: return "レベル 1(活火山であることに留意)";
  case 12: return "レベル 2(火口周辺規制)";
  case 13: return "レベル 3(入山規制)";
  case 14: return "レベル 4(避難準備)";
  case 15: return "レベル 5(避難)";
  case 21: return "活火山であることに留意";
  case 22: return "火口周辺危険";
  case 23: return "入山危険";
  case 24: return "山麓厳重警戒";
  case 25: return "居住地域厳重警戒";
  case 31: return "海上警報(噴火警報)";
  case 32: return "海上警報(噴火警報解除)";
  case 33: return "海上予報(噴火予報)";
  case 35: return "活火山であることに留意(海底火山)";
  case 36: return "周辺海域警戒";
  case 41: return "噴火警報：避難等";
  case 42: return "噴火警報：入山規制等";
  case 43: return "火口周辺警報：入山規制等";
  case 44: return "噴火警報(周辺海域)：周辺海域警戒";
  case 45: return "活火山であることに留意";
  case 46: return "噴火警報：当該居住地域厳重警戒";
  case 47: return "噴火警報：当該山麓厳重警戒";
  case 48: return "噴火警報：火口周辺警戒";
  case 49: return "火口周辺警報：火口周辺警戒";
  case 51: return "爆発";
  case 52: return "噴火";
  case 53: return "噴火開始";
  case 54: return "連続噴火継続";
  case 55: return "連続噴火停止";
  case 56: return "噴火多発";
  case 61: return "爆発したもよう";
  case 62: return "噴火したもよう";
  case 63: return "噴火開始したもよう";
  case 64: return "連続噴火が継続しているもよう";
  case 65: return "連続噴火は停止したもよう";
  case 91: return "不明";
  case 99: return "その他の現象";
  case 127: return "その他の防災気象情報要素";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "防災気象情報要素(コード番号：%d)", code);
    return _undefMessage;
  }
}

// Volcano name
const char* QZQSM::dc8vo2str(int code)
{
  switch (code) {
  case 101: return "知床硫黄山";
  case 102: return "羅臼岳";
  case 103: return "摩周";
  case 104: return "アトサヌプリ";
  case 105: return "雌阿寒岳";
  case 106: return "丸山";
  case 107: return "大雪山";
  case 108: return "十勝岳";
  case 109: return "樽前山";
  case 110: return "恵庭岳";
  case 111: return "倶多楽";
  case 112: return "有珠山";
  case 113: return "北海道駒ヶ岳";
  case 114: return "恵山";
  case 115: return "渡島大島";
  case 116: return "利尻山";
  case 117: return "羊蹄山";
  case 118: return "ニセコ";
  case 119: return "天頂山";
  case 120: return "雄阿寒岳";
  case 151: return "茂世路岳";
  case 152: return "散布山";
  case 153: return "指臼岳";
  case 154: return "小田萌山";
  case 155: return "択捉焼山";
  case 156: return "択捉阿登佐岳";
  case 157: return "ベルタルベ山";
  case 158: return "爺爺岳";
  case 159: return "羅臼山";
  case 160: return "泊山";
  case 161: return "ルルイ岳";
  case 201: return "恐山";
  case 202: return "岩木山";
  case 203: return "八甲田山";
  case 204: return "十和田";
  case 205: return "秋田焼山";
  case 206: return "八幡平";
  case 207: return "岩手山";
  case 208: return "秋田駒ヶ岳";
  case 209: return "鳥海山";
  case 210: return "栗駒山";
  case 211: return "鳴子";
  case 212: return "蔵王山";
  case 213: return "吾妻山";
  case 214: return "安達太良山";
  case 215: return "磐梯山";
  case 216: return "燧ヶ岳";
  case 217: return "肘折";
  case 218: return "沼沢";
  case 301: return "那須岳";
  case 302: return "日光白根山";
  case 303: return "赤城山";
  case 304: return "榛名山";
  case 305: return "草津白根山";
  case 306: return "浅間山";
  case 307: return "新潟焼山";
  case 308: return "妙高山";
  case 309: return "弥陀ヶ原";
  case 310: return "焼岳";
  case 311: return "乗鞍岳";
  case 312: return "御嶽山";
  case 313: return "白山";
  case 314: return "富士山";
  case 315: return "箱根山";
  case 316: return "伊豆東部火山群";
  case 317: return "伊豆大島";
  case 318: return "新島";
  case 319: return "神津島";
  case 320: return "三宅島";
  case 321: return "八丈島";
  case 322: return "青ヶ島";
  case 323: return "ベヨネース列岩";
  case 324: return "須美寿島";
  case 325: return "伊豆鳥島";
  case 326: return "西之島";
  case 327: return "海徳海山";
  case 328: return "噴火浅根";
  case 329: return "硫黄島";
  case 330: return "北福徳堆";
  case 331: return "福徳岡ノ場";
  case 333: return "高原山";
  case 334: return "横岳";
  case 335: return "アカンダナ山";
  case 336: return "利島";
  case 337: return "御蔵島";
  case 338: return "孀婦岩";
  case 339: return "海形海山";
  case 340: return "南日吉海山";
  case 341: return "日光海山";
  case 342: return "男体山";
  case 350: return "草津白根山(白根山(湯釜付近))";
  case 351: return "草津白根山(本白根山)";
  case 401: return "三瓶山";
  case 502: return "九重山";
  case 503: return "阿蘇山";
  case 504: return "雲仙岳";
  case 505: return "霧島山";
  case 506: return "桜島";
  case 507: return "開聞岳";
  case 508: return "薩摩硫黄島";
  case 509: return "口永良部島";
  case 510: return "中之島";
  case 511: return "諏訪之瀬島";
  case 512: return "阿武火山群";
  case 513: return "鶴見岳・伽藍岳";
  case 514: return "由布岳";
  case 515: return "福江火山群";
  case 516: return "米丸・住吉池";
  case 517: return "若尊";
  case 518: return "池田・山川";
  case 519: return "口之島";
  case 550: return "霧島山(御鉢)";
  case 551: return "霧島山(新燃岳)";
  case 552: return "霧島山(えびの高原(硫黄山)周辺)";
  case 601: return "硫黄鳥島";
  case 602: return "西表島北北東海底火山";
  case 900: return "全国の活火山";
  case 901: return "その他の活火山";
  case 902: return "新たな活火山";
  case 4000: return "その他の火山";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "火山(コード番号：%d)", code);
    return _undefMessage;
  }
}
#endif // QZQSM_ENABLE_DC8

#if defined(QZQSM_ENABLE_DC8) || defined(QZQSM_ENABLE_DC9)

// Local Government
const char* QZQSM::dc8pl2str(int code)
{
  switch (code) {
  case  110000: return "北海道札幌市";
  case  120200: return "北海道函館市";
  case  120300: return "北海道小樽市";
  case  120400: return "北海道旭川市";
  case  120500: return "北海道室蘭市";
  case  120600: return "北海道釧路市";
  case  120700: return "北海道帯広市";
  case  120800: return "北海道北見市";
  case  120900: return "北海道夕張市";
  case  121000: return "北海道岩見沢市";
  case  121100: return "北海道網走市";
  case  121200: return "北海道留萌市";
  case  121300: return "北海道苫小牧市";
  case  121400: return "北海道稚内市";
  case  121500: return "北海道美唄市";
  case  121600: return "北海道芦別市";
  case  121700: return "北海道江別市";
  case  121800: return "北海道赤平市";
  case  121900: return "北海道紋別市";
  case  122000: return "北海道士別市";
  case  122100: return "北海道名寄市";
  case  122200: return "北海道三笠市";
  case  122300: return "北海道根室市";
  case  122400: return "北海道千歳市";
  case  122500: return "北海道滝川市";
  case  122600: return "北海道砂川市";
  case  122700: return "北海道歌志内市";
  case  122800: return "北海道深川市";
  case  122900: return "北海道富良野市";
  case  123000: return "北海道登別市";
  case  123100: return "北海道恵庭市";
  case  123300: return "北海道伊達市";
  case  123400: return "北海道北広島市";
  case  123500: return "北海道石狩市";
  case  123600: return "北海道北斗市";
  case  130300: return "北海道当別町";
  case  130400: return "北海道新篠津村";
  case  133100: return "北海道松前町";
  case  133200: return "北海道福島町";
  case  133300: return "北海道知内町";
  case  133400: return "北海道木古内町";
  case  133700: return "北海道七飯町";
  case  134300: return "北海道鹿部町";
  case  134500: return "北海道森町";
  case  134600: return "北海道八雲町";
  case  134700: return "北海道長万部町";
  case  136100: return "北海道江差町";
  case  136200: return "北海道上ノ国町";
  case  136300: return "北海道厚沢部町";
  case  136400: return "北海道乙部町";
  case  136700: return "北海道奥尻町";
  case  137000: return "北海道今金町";
  case  137100: return "北海道せたな町";
  case  139100: return "北海道島牧村";
  case  139200: return "北海道寿都町";
  case  139300: return "北海道黒松内町";
  case  139400: return "北海道蘭越町";
  case  139500: return "北海道ニセコ町";
  case  139600: return "北海道真狩村";
  case  139700: return "北海道留寿都村";
  case  139800: return "北海道喜茂別町";
  case  139900: return "北海道京極町";
  case  140000: return "北海道倶知安町";
  case  140100: return "北海道共和町";
  case  140200: return "北海道岩内町";
  case  140300: return "北海道泊村";
  case  140400: return "北海道神恵内村";
  case  140500: return "北海道積丹町";
  case  140600: return "北海道古平町";
  case  140700: return "北海道仁木町";
  case  140800: return "北海道余市町";
  case  140900: return "北海道赤井川村";
  case  142300: return "北海道南幌町";
  case  142400: return "北海道奈井江町";
  case  142500: return "北海道上砂川町";
  case  142700: return "北海道由仁町";
  case  142800: return "北海道長沼町";
  case  142900: return "北海道栗山町";
  case  143000: return "北海道月形町";
  case  143100: return "北海道浦臼町";
  case  143200: return "北海道新十津川町";
  case  143300: return "北海道妹背牛町";
  case  143400: return "北海道秩父別町";
  case  143600: return "北海道雨竜町";
  case  143700: return "北海道北竜町";
  case  143800: return "北海道沼田町";
  case  145200: return "北海道鷹栖町";
  case  145300: return "北海道東神楽町";
  case  145400: return "北海道当麻町";
  case  145500: return "北海道比布町";
  case  145600: return "北海道愛別町";
  case  145700: return "北海道上川町";
  case  145800: return "北海道東川町";
  case  145900: return "北海道美瑛町";
  case  146000: return "北海道上富良野町";
  case  146100: return "北海道中富良野町";
  case  146200: return "北海道南富良野町";
  case  146300: return "北海道占冠村";
  case  146400: return "北海道和寒町";
  case  146500: return "北海道剣淵町";
  case  146800: return "北海道下川町";
  case  146900: return "北海道美深町";
  case  147000: return "北海道音威子府村";
  case  147100: return "北海道中川町";
  case  147200: return "北海道幌加内町";
  case  148100: return "北海道増毛町";
  case  148200: return "北海道小平町";
  case  148300: return "北海道苫前町";
  case  148400: return "北海道羽幌町";
  case  148500: return "北海道初山別村";
  case  148600: return "北海道遠別町";
  case  148700: return "北海道天塩町";
  case  151100: return "北海道猿払村";
  case  151200: return "北海道浜頓別町";
  case  151300: return "北海道中頓別町";
  case  151400: return "北海道枝幸町";
  case  151600: return "北海道豊富町";
  case  151700: return "北海道礼文町";
  case  151800: return "北海道利尻町";
  case  151900: return "北海道利尻富士町";
  case  152000: return "北海道幌延町";
  case  154300: return "北海道美幌町";
  case  154400: return "北海道津別町";
  case  154500: return "北海道斜里町";
  case  154600: return "北海道清里町";
  case  154700: return "北海道小清水町";
  case  154900: return "北海道訓子府町";
  case  155000: return "北海道置戸町";
  case  155200: return "北海道佐呂間町";
  case  155500: return "北海道遠軽町";
  case  155900: return "北海道湧別町";
  case  156000: return "北海道滝上町";
  case  156100: return "北海道興部町";
  case  156200: return "北海道西興部村";
  case  156300: return "北海道雄武町";
  case  156400: return "北海道大空町";
  case  157100: return "北海道豊浦町";
  case  157500: return "北海道壮瞥町";
  case  157800: return "北海道白老町";
  case  158100: return "北海道厚真町";
  case  158400: return "北海道洞爺湖町";
  case  158500: return "北海道安平町";
  case  158600: return "北海道むかわ町";
  case  160100: return "北海道日高町";
  case  160200: return "北海道平取町";
  case  160400: return "北海道新冠町";
  case  160700: return "北海道浦河町";
  case  160800: return "北海道様似町";
  case  160900: return "北海道えりも町";
  case  161000: return "北海道新ひだか町";
  case  163100: return "北海道音更町";
  case  163200: return "北海道士幌町";
  case  163300: return "北海道上士幌町";
  case  163400: return "北海道鹿追町";
  case  163500: return "北海道新得町";
  case  163600: return "北海道清水町";
  case  163700: return "北海道芽室町";
  case  163800: return "北海道中札内村";
  case  163900: return "北海道更別村";
  case  164100: return "北海道大樹町";
  case  164200: return "北海道広尾町";
  case  164300: return "北海道幕別町";
  case  164400: return "北海道池田町";
  case  164500: return "北海道豊頃町";
  case  164600: return "北海道本別町";
  case  164700: return "北海道足寄町";
  case  164800: return "北海道陸別町";
  case  164900: return "北海道浦幌町";
  case  166100: return "北海道釧路町";
  case  166200: return "北海道厚岸町";
  case  166300: return "北海道浜中町";
  case  166400: return "北海道標茶町";
  case  166500: return "北海道弟子屈町";
  case  166700: return "北海道鶴居村";
  case  166800: return "北海道白糠町";
  case  169001: return "北海道国後島";
  case  169002: return "北海道択捉島";
  case  169100: return "北海道別海町";
  case  169200: return "北海道中標津町";
  case  169300: return "北海道標津町";
  case  169400: return "北海道羅臼町";
  case  169500: return "北海道色丹村";
  case  199999: return "北海道のその他の市町村";
  case  220100: return "青森県青森市";
  case  220200: return "青森県弘前市";
  case  220300: return "青森県八戸市";
  case  220400: return "青森県黒石市";
  case  220500: return "青森県五所川原市";
  case  220600: return "青森県十和田市";
  case  220700: return "青森県三沢市";
  case  220800: return "青森県むつ市";
  case  220900: return "青森県つがる市";
  case  221000: return "青森県平川市";
  case  230100: return "青森県平内町";
  case  230300: return "青森県今別町";
  case  230400: return "青森県蓬田村";
  case  230700: return "青森県外ヶ浜町";
  case  232100: return "青森県鰺ヶ沢町";
  case  232300: return "青森県深浦町";
  case  234300: return "青森県西目屋村";
  case  236100: return "青森県藤崎町";
  case  236200: return "青森県大鰐町";
  case  236700: return "青森県田舎館村";
  case  238100: return "青森県板柳町";
  case  238400: return "青森県鶴田町";
  case  238700: return "青森県中泊町";
  case  240100: return "青森県野辺地町";
  case  240200: return "青森県七戸町";
  case  240500: return "青森県六戸町";
  case  240600: return "青森県横浜町";
  case  240800: return "青森県東北町";
  case  241100: return "青森県六ヶ所村";
  case  241200: return "青森県おいらせ町";
  case  242300: return "青森県大間町";
  case  242400: return "青森県東通村";
  case  242500: return "青森県風間浦村";
  case  242600: return "青森県佐井村";
  case  244100: return "青森県三戸町";
  case  244200: return "青森県五戸町";
  case  244300: return "青森県田子町";
  case  244500: return "青森県南部町";
  case  244600: return "青森県階上町";
  case  245000: return "青森県新郷村";
  case  299999: return "青森県のその他の市町村";
  case  320100: return "岩手県盛岡市";
  case  320200: return "岩手県宮古市";
  case  320300: return "岩手県大船渡市";
  case  320500: return "岩手県花巻市";
  case  320600: return "岩手県北上市";
  case  320700: return "岩手県久慈市";
  case  320800: return "岩手県遠野市";
  case  320900: return "岩手県一関市";
  case  321000: return "岩手県陸前高田市";
  case  321100: return "岩手県釜石市";
  case  321300: return "岩手県二戸市";
  case  321400: return "岩手県八幡平市";
  case  321500: return "岩手県奥州市";
  case  321600: return "岩手県滝沢市";
  case  330100: return "岩手県雫石町";
  case  330200: return "岩手県葛巻町";
  case  330300: return "岩手県岩手町";
  case  332100: return "岩手県紫波町";
  case  332200: return "岩手県矢巾町";
  case  336600: return "岩手県西和賀町";
  case  338100: return "岩手県金ケ崎町";
  case  340200: return "岩手県平泉町";
  case  344100: return "岩手県住田町";
  case  346100: return "岩手県大槌町";
  case  348200: return "岩手県山田町";
  case  348300: return "岩手県岩泉町";
  case  348400: return "岩手県田野畑村";
  case  348500: return "岩手県普代村";
  case  350100: return "岩手県軽米町";
  case  350300: return "岩手県野田村";
  case  350600: return "岩手県九戸村";
  case  350700: return "岩手県洋野町";
  case  352400: return "岩手県一戸町";
  case  399999: return "岩手県のその他の市町村";
  case  410000: return "宮城県仙台市";
  case  420200: return "宮城県石巻市";
  case  420300: return "宮城県塩竈市";
  case  420500: return "宮城県気仙沼市";
  case  420600: return "宮城県白石市";
  case  420700: return "宮城県名取市";
  case  420800: return "宮城県角田市";
  case  420900: return "宮城県多賀城市";
  case  421100: return "宮城県岩沼市";
  case  421200: return "宮城県登米市";
  case  421300: return "宮城県栗原市";
  case  421400: return "宮城県東松島市";
  case  421500: return "宮城県大崎市";
  case  421600: return "宮城県富谷市";
  case  430100: return "宮城県蔵王町";
  case  430200: return "宮城県七ヶ宿町";
  case  432100: return "宮城県大河原町";
  case  432200: return "宮城県村田町";
  case  432300: return "宮城県柴田町";
  case  432400: return "宮城県川崎町";
  case  434100: return "宮城県丸森町";
  case  436100: return "宮城県亘理町";
  case  436200: return "宮城県山元町";
  case  440100: return "宮城県松島町";
  case  440400: return "宮城県七ヶ浜町";
  case  440600: return "宮城県利府町";
  case  442100: return "宮城県大和町";
  case  442200: return "宮城県大郷町";
  case  442400: return "宮城県大衡村";
  case  444400: return "宮城県色麻町";
  case  444500: return "宮城県加美町";
  case  450100: return "宮城県涌谷町";
  case  450500: return "宮城県美里町";
  case  458100: return "宮城県女川町";
  case  460600: return "宮城県南三陸町";
  case  499999: return "宮城県のその他の市町村";
  case  520100: return "秋田県秋田市";
  case  520200: return "秋田県能代市";
  case  520300: return "秋田県横手市";
  case  520400: return "秋田県大館市";
  case  520600: return "秋田県男鹿市";
  case  520700: return "秋田県湯沢市";
  case  520900: return "秋田県鹿角市";
  case  521000: return "秋田県由利本荘市";
  case  521100: return "秋田県潟上市";
  case  521200: return "秋田県大仙市";
  case  521300: return "秋田県北秋田市";
  case  521400: return "秋田県にかほ市";
  case  521500: return "秋田県仙北市";
  case  530300: return "秋田県小坂町";
  case  532700: return "秋田県上小阿仁村";
  case  534600: return "秋田県藤里町";
  case  534800: return "秋田県三種町";
  case  534900: return "秋田県八峰町";
  case  536100: return "秋田県五城目町";
  case  536300: return "秋田県八郎潟町";
  case  536600: return "秋田県井川町";
  case  536800: return "秋田県大潟村";
  case  543400: return "秋田県美郷町";
  case  546300: return "秋田県羽後町";
  case  546400: return "秋田県東成瀬村";
  case  599999: return "秋田県のその他の市町村";
  case  620100: return "山形県山形市";
  case  620200: return "山形県米沢市";
  case  620300: return "山形県鶴岡市";
  case  620400: return "山形県酒田市";
  case  620500: return "山形県新庄市";
  case  620600: return "山形県寒河江市";
  case  620700: return "山形県上山市";
  case  620800: return "山形県村山市";
  case  620900: return "山形県長井市";
  case  621000: return "山形県天童市";
  case  621100: return "山形県東根市";
  case  621200: return "山形県尾花沢市";
  case  621300: return "山形県南陽市";
  case  630100: return "山形県山辺町";
  case  630200: return "山形県中山町";
  case  632100: return "山形県河北町";
  case  632200: return "山形県西川町";
  case  632300: return "山形県朝日町";
  case  632400: return "山形県大江町";
  case  634100: return "山形県大石田町";
  case  636100: return "山形県金山町";
  case  636200: return "山形県最上町";
  case  636300: return "山形県舟形町";
  case  636400: return "山形県真室川町";
  case  636500: return "山形県大蔵村";
  case  636600: return "山形県鮭川村";
  case  636700: return "山形県戸沢村";
  case  638100: return "山形県高畠町";
  case  638200: return "山形県川西町";
  case  640100: return "山形県小国町";
  case  640200: return "山形県白鷹町";
  case  640300: return "山形県飯豊町";
  case  642600: return "山形県三川町";
  case  642800: return "山形県庄内町";
  case  646100: return "山形県遊佐町";
  case  699999: return "山形県のその他の市町村";
  case  720100: return "福島県福島市";
  case  720200: return "福島県会津若松市";
  case  720300: return "福島県郡山市";
  case  720400: return "福島県いわき市";
  case  720500: return "福島県白河市";
  case  720700: return "福島県須賀川市";
  case  720800: return "福島県喜多方市";
  case  720900: return "福島県相馬市";
  case  721000: return "福島県二本松市";
  case  721100: return "福島県田村市";
  case  721200: return "福島県南相馬市";
  case  721300: return "福島県伊達市";
  case  721400: return "福島県本宮市";
  case  730100: return "福島県桑折町";
  case  730300: return "福島県国見町";
  case  730800: return "福島県川俣町";
  case  732200: return "福島県大玉村";
  case  734200: return "福島県鏡石町";
  case  734400: return "福島県天栄村";
  case  736200: return "福島県下郷町";
  case  736400: return "福島県檜枝岐村";
  case  736700: return "福島県只見町";
  case  736800: return "福島県南会津町";
  case  740200: return "福島県北塩原村";
  case  740500: return "福島県西会津町";
  case  740700: return "福島県磐梯町";
  case  740800: return "福島県猪苗代町";
  case  742100: return "福島県会津坂下町";
  case  742200: return "福島県湯川村";
  case  742300: return "福島県柳津町";
  case  744400: return "福島県三島町";
  case  744500: return "福島県金山町";
  case  744600: return "福島県昭和村";
  case  744700: return "福島県会津美里町";
  case  746100: return "福島県西郷村";
  case  746400: return "福島県泉崎村";
  case  746500: return "福島県中島村";
  case  746600: return "福島県矢吹町";
  case  748100: return "福島県棚倉町";
  case  748200: return "福島県矢祭町";
  case  748300: return "福島県塙町";
  case  748400: return "福島県鮫川村";
  case  750100: return "福島県石川町";
  case  750200: return "福島県玉川村";
  case  750300: return "福島県平田村";
  case  750400: return "福島県浅川町";
  case  750500: return "福島県古殿町";
  case  752100: return "福島県三春町";
  case  752200: return "福島県小野町";
  case  754100: return "福島県広野町";
  case  754200: return "福島県楢葉町";
  case  754300: return "福島県富岡町";
  case  754400: return "福島県川内村";
  case  754500: return "福島県大熊町";
  case  754600: return "福島県双葉町";
  case  754700: return "福島県浪江町";
  case  754800: return "福島県葛尾村";
  case  756100: return "福島県新地町";
  case  756400: return "福島県飯舘村";
  case  799999: return "福島県のその他の市町村";
  case  820100: return "茨城県水戸市";
  case  820200: return "茨城県日立市";
  case  820300: return "茨城県土浦市";
  case  820400: return "茨城県古河市";
  case  820500: return "茨城県石岡市";
  case  820700: return "茨城県結城市";
  case  820800: return "茨城県龍ケ崎市";
  case  821000: return "茨城県下妻市";
  case  821100: return "茨城県常総市";
  case  821200: return "茨城県常陸太田市";
  case  821400: return "茨城県高萩市";
  case  821500: return "茨城県北茨城市";
  case  821600: return "茨城県笠間市";
  case  821700: return "茨城県取手市";
  case  821900: return "茨城県牛久市";
  case  822000: return "茨城県つくば市";
  case  822100: return "茨城県ひたちなか市";
  case  822200: return "茨城県鹿嶋市";
  case  822300: return "茨城県潮来市";
  case  822400: return "茨城県守谷市";
  case  822500: return "茨城県常陸大宮市";
  case  822600: return "茨城県那珂市";
  case  822700: return "茨城県筑西市";
  case  822800: return "茨城県坂東市";
  case  822900: return "茨城県稲敷市";
  case  823000: return "茨城県かすみがうら市";
  case  823100: return "茨城県桜川市";
  case  823200: return "茨城県神栖市";
  case  823300: return "茨城県行方市";
  case  823400: return "茨城県鉾田市";
  case  823500: return "茨城県つくばみらい市";
  case  823600: return "茨城県小美玉市";
  case  830200: return "茨城県茨城町";
  case  830900: return "茨城県大洗町";
  case  831000: return "茨城県城里町";
  case  834100: return "茨城県東海村";
  case  836400: return "茨城県大子町";
  case  844200: return "茨城県美浦村";
  case  844300: return "茨城県阿見町";
  case  844700: return "茨城県河内町";
  case  852100: return "茨城県八千代町";
  case  854200: return "茨城県五霞町";
  case  854600: return "茨城県境町";
  case  856400: return "茨城県利根町";
  case  899999: return "茨城県のその他の市町村";
  case  920100: return "栃木県宇都宮市";
  case  920200: return "栃木県足利市";
  case  920300: return "栃木県栃木市";
  case  920400: return "栃木県佐野市";
  case  920500: return "栃木県鹿沼市";
  case  920600: return "栃木県日光市";
  case  920800: return "栃木県小山市";
  case  920900: return "栃木県真岡市";
  case  921000: return "栃木県大田原市";
  case  921100: return "栃木県矢板市";
  case  921300: return "栃木県那須塩原市";
  case  921400: return "栃木県さくら市";
  case  921500: return "栃木県那須烏山市";
  case  921600: return "栃木県下野市";
  case  930100: return "栃木県上三川町";
  case  934200: return "栃木県益子町";
  case  934300: return "栃木県茂木町";
  case  934400: return "栃木県市貝町";
  case  934500: return "栃木県芳賀町";
  case  936100: return "栃木県壬生町";
  case  936400: return "栃木県野木町";
  case  938400: return "栃木県塩谷町";
  case  938600: return "栃木県高根沢町";
  case  940700: return "栃木県那須町";
  case  941100: return "栃木県那珂川町";
  case  999999: return "栃木県のその他の市町村";
  case 1020100: return "群馬県前橋市";
  case 1020200: return "群馬県高崎市";
  case 1020300: return "群馬県桐生市";
  case 1020400: return "群馬県伊勢崎市";
  case 1020500: return "群馬県太田市";
  case 1020600: return "群馬県沼田市";
  case 1020700: return "群馬県館林市";
  case 1020800: return "群馬県渋川市";
  case 1020900: return "群馬県藤岡市";
  case 1021000: return "群馬県富岡市";
  case 1021100: return "群馬県安中市";
  case 1021200: return "群馬県みどり市";
  case 1034400: return "群馬県榛東村";
  case 1034500: return "群馬県吉岡町";
  case 1036600: return "群馬県上野村";
  case 1036700: return "群馬県神流町";
  case 1038200: return "群馬県下仁田町";
  case 1038300: return "群馬県南牧村";
  case 1038400: return "群馬県甘楽町";
  case 1042100: return "群馬県中之条町";
  case 1042400: return "群馬県長野原町";
  case 1042500: return "群馬県嬬恋村";
  case 1042600: return "群馬県草津町";
  case 1042800: return "群馬県高山村";
  case 1042900: return "群馬県東吾妻町";
  case 1044300: return "群馬県片品村";
  case 1044400: return "群馬県川場村";
  case 1044800: return "群馬県昭和村";
  case 1044900: return "群馬県みなかみ町";
  case 1046400: return "群馬県玉村町";
  case 1052100: return "群馬県板倉町";
  case 1052200: return "群馬県明和町";
  case 1052300: return "群馬県千代田町";
  case 1052400: return "群馬県大泉町";
  case 1052500: return "群馬県邑楽町";
  case 1099999: return "群馬県のその他の市町村";
  case 1110000: return "埼玉県さいたま市";
  case 1120100: return "埼玉県川越市";
  case 1120200: return "埼玉県熊谷市";
  case 1120300: return "埼玉県川口市";
  case 1120600: return "埼玉県行田市";
  case 1120700: return "埼玉県秩父市";
  case 1120800: return "埼玉県所沢市";
  case 1120900: return "埼玉県飯能市";
  case 1121000: return "埼玉県加須市";
  case 1121100: return "埼玉県本庄市";
  case 1121200: return "埼玉県東松山市";
  case 1121400: return "埼玉県春日部市";
  case 1121500: return "埼玉県狭山市";
  case 1121600: return "埼玉県羽生市";
  case 1121700: return "埼玉県鴻巣市";
  case 1121800: return "埼玉県深谷市";
  case 1121900: return "埼玉県上尾市";
  case 1122100: return "埼玉県草加市";
  case 1122200: return "埼玉県越谷市";
  case 1122300: return "埼玉県蕨市";
  case 1122400: return "埼玉県戸田市";
  case 1122500: return "埼玉県入間市";
  case 1122700: return "埼玉県朝霞市";
  case 1122800: return "埼玉県志木市";
  case 1122900: return "埼玉県和光市";
  case 1123000: return "埼玉県新座市";
  case 1123100: return "埼玉県桶川市";
  case 1123200: return "埼玉県久喜市";
  case 1123300: return "埼玉県北本市";
  case 1123400: return "埼玉県八潮市";
  case 1123500: return "埼玉県富士見市";
  case 1123700: return "埼玉県三郷市";
  case 1123800: return "埼玉県蓮田市";
  case 1123900: return "埼玉県坂戸市";
  case 1124000: return "埼玉県幸手市";
  case 1124100: return "埼玉県鶴ヶ島市";
  case 1124200: return "埼玉県日高市";
  case 1124300: return "埼玉県吉川市";
  case 1124500: return "埼玉県ふじみ野市";
  case 1124600: return "埼玉県白岡市";
  case 1130100: return "埼玉県伊奈町";
  case 1132400: return "埼玉県三芳町";
  case 1132600: return "埼玉県毛呂山町";
  case 1132700: return "埼玉県越生町";
  case 1134100: return "埼玉県滑川町";
  case 1134200: return "埼玉県嵐山町";
  case 1134300: return "埼玉県小川町";
  case 1134600: return "埼玉県川島町";
  case 1134700: return "埼玉県吉見町";
  case 1134800: return "埼玉県鳩山町";
  case 1134900: return "埼玉県ときがわ町";
  case 1136100: return "埼玉県横瀬町";
  case 1136200: return "埼玉県皆野町";
  case 1136300: return "埼玉県長瀞町";
  case 1136500: return "埼玉県小鹿野町";
  case 1136900: return "埼玉県東秩父村";
  case 1138100: return "埼玉県美里町";
  case 1138300: return "埼玉県神川町";
  case 1138500: return "埼玉県上里町";
  case 1140800: return "埼玉県寄居町";
  case 1144200: return "埼玉県宮代町";
  case 1146400: return "埼玉県杉戸町";
  case 1146500: return "埼玉県松伏町";
  case 1199999: return "埼玉県のその他の市町村";
  case 1210000: return "千葉県千葉市";
  case 1220200: return "千葉県銚子市";
  case 1220300: return "千葉県市川市";
  case 1220400: return "千葉県船橋市";
  case 1220500: return "千葉県館山市";
  case 1220600: return "千葉県木更津市";
  case 1220700: return "千葉県松戸市";
  case 1220800: return "千葉県野田市";
  case 1221000: return "千葉県茂原市";
  case 1221100: return "千葉県成田市";
  case 1221200: return "千葉県佐倉市";
  case 1221300: return "千葉県東金市";
  case 1221500: return "千葉県旭市";
  case 1221600: return "千葉県習志野市";
  case 1221700: return "千葉県柏市";
  case 1221800: return "千葉県勝浦市";
  case 1221900: return "千葉県市原市";
  case 1222000: return "千葉県流山市";
  case 1222100: return "千葉県八千代市";
  case 1222200: return "千葉県我孫子市";
  case 1222300: return "千葉県鴨川市";
  case 1222400: return "千葉県鎌ケ谷市";
  case 1222500: return "千葉県君津市";
  case 1222600: return "千葉県富津市";
  case 1222700: return "千葉県浦安市";
  case 1222800: return "千葉県四街道市";
  case 1222900: return "千葉県袖ケ浦市";
  case 1223000: return "千葉県八街市";
  case 1223100: return "千葉県印西市";
  case 1223200: return "千葉県白井市";
  case 1223300: return "千葉県富里市";
  case 1223400: return "千葉県南房総市";
  case 1223500: return "千葉県匝瑳市";
  case 1223600: return "千葉県香取市";
  case 1223700: return "千葉県山武市";
  case 1223800: return "千葉県いすみ市";
  case 1223900: return "千葉県大網白里市";
  case 1232200: return "千葉県酒々井町";
  case 1232900: return "千葉県栄町";
  case 1234200: return "千葉県神崎町";
  case 1234700: return "千葉県多古町";
  case 1234900: return "千葉県東庄町";
  case 1240300: return "千葉県九十九里町";
  case 1240900: return "千葉県芝山町";
  case 1241000: return "千葉県横芝光町";
  case 1242100: return "千葉県一宮町";
  case 1242200: return "千葉県睦沢町";
  case 1242300: return "千葉県長生村";
  case 1242400: return "千葉県白子町";
  case 1242600: return "千葉県長柄町";
  case 1242700: return "千葉県長南町";
  case 1244100: return "千葉県大多喜町";
  case 1244300: return "千葉県御宿町";
  case 1246300: return "千葉県鋸南町";
  case 1299999: return "千葉県のその他の市町村";
  case 1310100: return "東京都千代田区";
  case 1310200: return "東京都中央区";
  case 1310300: return "東京都港区";
  case 1310400: return "東京都新宿区";
  case 1310500: return "東京都文京区";
  case 1310600: return "東京都台東区";
  case 1310700: return "東京都墨田区";
  case 1310800: return "東京都江東区";
  case 1310900: return "東京都品川区";
  case 1311000: return "東京都目黒区";
  case 1311100: return "東京都大田区";
  case 1311200: return "東京都世田谷区";
  case 1311300: return "東京都渋谷区";
  case 1311400: return "東京都中野区";
  case 1311500: return "東京都杉並区";
  case 1311600: return "東京都豊島区";
  case 1311700: return "東京都北区";
  case 1311800: return "東京都荒川区";
  case 1311900: return "東京都板橋区";
  case 1312000: return "東京都練馬区";
  case 1312100: return "東京都足立区";
  case 1312200: return "東京都葛飾区";
  case 1312300: return "東京都江戸川区";
  case 1320100: return "東京都八王子市";
  case 1320200: return "東京都立川市";
  case 1320300: return "東京都武蔵野市";
  case 1320400: return "東京都三鷹市";
  case 1320500: return "東京都青梅市";
  case 1320600: return "東京都府中市";
  case 1320700: return "東京都昭島市";
  case 1320800: return "東京都調布市";
  case 1320900: return "東京都町田市";
  case 1321000: return "東京都小金井市";
  case 1321100: return "東京都小平市";
  case 1321200: return "東京都日野市";
  case 1321300: return "東京都東村山市";
  case 1321400: return "東京都国分寺市";
  case 1321500: return "東京都国立市";
  case 1321800: return "東京都福生市";
  case 1321900: return "東京都狛江市";
  case 1322000: return "東京都東大和市";
  case 1322100: return "東京都清瀬市";
  case 1322200: return "東京都東久留米市";
  case 1322300: return "東京都武蔵村山市";
  case 1322400: return "東京都多摩市";
  case 1322500: return "東京都稲城市";
  case 1322700: return "東京都羽村市";
  case 1322800: return "東京都あきる野市";
  case 1322900: return "東京都西東京市";
  case 1330300: return "東京都瑞穂町";
  case 1330500: return "東京都日の出町";
  case 1330700: return "東京都檜原村";
  case 1330800: return "東京都奥多摩町";
  case 1336100: return "東京都大島町";
  case 1336200: return "東京都利島村";
  case 1336300: return "東京都新島村";
  case 1336400: return "東京都神津島村";
  case 1338100: return "東京都三宅村";
  case 1338200: return "東京都御蔵島村";
  case 1340000: return "東京都八丈支庁";
  case 1340100: return "東京都八丈町";
  case 1340200: return "東京都青ヶ島村";
  case 1342100: return "東京都小笠原村";
  case 1399999: return "東京都のその他の市町村";
  case 1410000: return "神奈川県横浜市";
  case 1413000: return "神奈川県川崎市";
  case 1415000: return "神奈川県相模原市";
  case 1420100: return "神奈川県横須賀市";
  case 1420300: return "神奈川県平塚市";
  case 1420400: return "神奈川県鎌倉市";
  case 1420500: return "神奈川県藤沢市";
  case 1420600: return "神奈川県小田原市";
  case 1420700: return "神奈川県茅ヶ崎市";
  case 1420800: return "神奈川県逗子市";
  case 1421000: return "神奈川県三浦市";
  case 1421100: return "神奈川県秦野市";
  case 1421200: return "神奈川県厚木市";
  case 1421300: return "神奈川県大和市";
  case 1421400: return "神奈川県伊勢原市";
  case 1421500: return "神奈川県海老名市";
  case 1421600: return "神奈川県座間市";
  case 1421700: return "神奈川県南足柄市";
  case 1421800: return "神奈川県綾瀬市";
  case 1430100: return "神奈川県葉山町";
  case 1432100: return "神奈川県寒川町";
  case 1434100: return "神奈川県大磯町";
  case 1434200: return "神奈川県二宮町";
  case 1436100: return "神奈川県中井町";
  case 1436200: return "神奈川県大井町";
  case 1436300: return "神奈川県松田町";
  case 1436400: return "神奈川県山北町";
  case 1436600: return "神奈川県開成町";
  case 1438200: return "神奈川県箱根町";
  case 1438300: return "神奈川県真鶴町";
  case 1438400: return "神奈川県湯河原町";
  case 1440100: return "神奈川県愛川町";
  case 1440200: return "神奈川県清川村";
  case 1499999: return "神奈川県のその他の市町村";
  case 1510000: return "新潟県新潟市";
  case 1520200: return "新潟県長岡市";
  case 1520400: return "新潟県三条市";
  case 1520500: return "新潟県柏崎市";
  case 1520600: return "新潟県新発田市";
  case 1520800: return "新潟県小千谷市";
  case 1520900: return "新潟県加茂市";
  case 1521000: return "新潟県十日町市";
  case 1521100: return "新潟県見附市";
  case 1521200: return "新潟県村上市";
  case 1521300: return "新潟県燕市";
  case 1521600: return "新潟県糸魚川市";
  case 1521700: return "新潟県妙高市";
  case 1521800: return "新潟県五泉市";
  case 1522200: return "新潟県上越市";
  case 1522300: return "新潟県阿賀野市";
  case 1522400: return "新潟県佐渡市";
  case 1522500: return "新潟県魚沼市";
  case 1522600: return "新潟県南魚沼市";
  case 1522700: return "新潟県胎内市";
  case 1530700: return "新潟県聖籠町";
  case 1534200: return "新潟県弥彦村";
  case 1536100: return "新潟県田上町";
  case 1538500: return "新潟県阿賀町";
  case 1540500: return "新潟県出雲崎町";
  case 1546100: return "新潟県湯沢町";
  case 1548200: return "新潟県津南町";
  case 1550400: return "新潟県刈羽村";
  case 1558100: return "新潟県関川村";
  case 1558600: return "新潟県粟島浦村";
  case 1599999: return "新潟県のその他の市町村";
  case 1620100: return "富山県富山市";
  case 1620200: return "富山県高岡市";
  case 1620400: return "富山県魚津市";
  case 1620500: return "富山県氷見市";
  case 1620600: return "富山県滑川市";
  case 1620700: return "富山県黒部市";
  case 1620800: return "富山県砺波市";
  case 1620900: return "富山県小矢部市";
  case 1621000: return "富山県南砺市";
  case 1621100: return "富山県射水市";
  case 1632100: return "富山県舟橋村";
  case 1632200: return "富山県上市町";
  case 1632300: return "富山県立山町";
  case 1634200: return "富山県入善町";
  case 1634300: return "富山県朝日町";
  case 1699999: return "富山県のその他の市町村";
  case 1720100: return "石川県金沢市";
  case 1720200: return "石川県七尾市";
  case 1720300: return "石川県小松市";
  case 1720400: return "石川県輪島市";
  case 1720500: return "石川県珠洲市";
  case 1720600: return "石川県加賀市";
  case 1720700: return "石川県羽咋市";
  case 1720900: return "石川県かほく市";
  case 1721000: return "石川県白山市";
  case 1721100: return "石川県能美市";
  case 1721200: return "石川県野々市市";
  case 1732400: return "石川県川北町";
  case 1736100: return "石川県津幡町";
  case 1736500: return "石川県内灘町";
  case 1738400: return "石川県志賀町";
  case 1738600: return "石川県宝達志水町";
  case 1740700: return "石川県中能登町";
  case 1746100: return "石川県穴水町";
  case 1746300: return "石川県能登町";
  case 1799999: return "石川県のその他の市町村";
  case 1820100: return "福井県福井市";
  case 1820200: return "福井県敦賀市";
  case 1820400: return "福井県小浜市";
  case 1820500: return "福井県大野市";
  case 1820600: return "福井県勝山市";
  case 1820700: return "福井県鯖江市";
  case 1820800: return "福井県あわら市";
  case 1820900: return "福井県越前市";
  case 1821000: return "福井県坂井市";
  case 1832200: return "福井県永平寺町";
  case 1838200: return "福井県池田町";
  case 1840400: return "福井県南越前町";
  case 1842300: return "福井県越前町";
  case 1844200: return "福井県美浜町";
  case 1848100: return "福井県高浜町";
  case 1848300: return "福井県おおい町";
  case 1850100: return "福井県若狭町";
  case 1899999: return "福井県のその他の市町村";
  case 1920100: return "山梨県甲府市";
  case 1920200: return "山梨県富士吉田市";
  case 1920400: return "山梨県都留市";
  case 1920500: return "山梨県山梨市";
  case 1920600: return "山梨県大月市";
  case 1920700: return "山梨県韮崎市";
  case 1920800: return "山梨県南アルプス市";
  case 1920900: return "山梨県北杜市";
  case 1921000: return "山梨県甲斐市";
  case 1921100: return "山梨県笛吹市";
  case 1921200: return "山梨県上野原市";
  case 1921300: return "山梨県甲州市";
  case 1921400: return "山梨県中央市";
  case 1934600: return "山梨県市川三郷町";
  case 1936400: return "山梨県早川町";
  case 1936500: return "山梨県身延町";
  case 1936600: return "山梨県南部町";
  case 1936800: return "山梨県富士川町";
  case 1938400: return "山梨県昭和町";
  case 1942200: return "山梨県道志村";
  case 1942300: return "山梨県西桂町";
  case 1942400: return "山梨県忍野村";
  case 1942500: return "山梨県山中湖村";
  case 1942900: return "山梨県鳴沢村";
  case 1943000: return "山梨県富士河口湖町";
  case 1944200: return "山梨県小菅村";
  case 1944300: return "山梨県丹波山村";
  case 1999999: return "山梨県のその他の市町村";
  case 2020100: return "長野県長野市";
  case 2020200: return "長野県松本市";
  case 2020300: return "長野県上田市";
  case 2020400: return "長野県岡谷市";
  case 2020500: return "長野県飯田市";
  case 2020600: return "長野県諏訪市";
  case 2020700: return "長野県須坂市";
  case 2020800: return "長野県小諸市";
  case 2020900: return "長野県伊那市";
  case 2021000: return "長野県駒ヶ根市";
  case 2021100: return "長野県中野市";
  case 2021200: return "長野県大町市";
  case 2021300: return "長野県飯山市";
  case 2021400: return "長野県茅野市";
  case 2021500: return "長野県塩尻市";
  case 2021700: return "長野県佐久市";
  case 2021800: return "長野県千曲市";
  case 2021900: return "長野県東御市";
  case 2022000: return "長野県安曇野市";
  case 2030300: return "長野県小海町";
  case 2030400: return "長野県川上村";
  case 2030500: return "長野県南牧村";
  case 2030600: return "長野県南相木村";
  case 2030700: return "長野県北相木村";
  case 2030900: return "長野県佐久穂町";
  case 2032100: return "長野県軽井沢町";
  case 2032300: return "長野県御代田町";
  case 2032400: return "長野県立科町";
  case 2034900: return "長野県青木村";
  case 2035000: return "長野県長和町";
  case 2036100: return "長野県下諏訪町";
  case 2036200: return "長野県富士見町";
  case 2036300: return "長野県原村";
  case 2038200: return "長野県辰野町";
  case 2038300: return "長野県箕輪町";
  case 2038400: return "長野県飯島町";
  case 2038500: return "長野県南箕輪村";
  case 2038600: return "長野県中川村";
  case 2038800: return "長野県宮田村";
  case 2040200: return "長野県松川町";
  case 2040300: return "長野県高森町";
  case 2040400: return "長野県阿南町";
  case 2040700: return "長野県阿智村";
  case 2040900: return "長野県平谷村";
  case 2041000: return "長野県根羽村";
  case 2041100: return "長野県下條村";
  case 2041200: return "長野県売木村";
  case 2041300: return "長野県天龍村";
  case 2041400: return "長野県泰阜村";
  case 2041500: return "長野県喬木村";
  case 2041600: return "長野県豊丘村";
  case 2041700: return "長野県大鹿村";
  case 2042200: return "長野県上松町";
  case 2042300: return "長野県南木曽町";
  case 2042500: return "長野県木祖村";
  case 2042900: return "長野県王滝村";
  case 2043000: return "長野県大桑村";
  case 2043200: return "長野県木曽町";
  case 2044600: return "長野県麻績村";
  case 2044800: return "長野県生坂村";
  case 2045000: return "長野県山形村";
  case 2045100: return "長野県朝日村";
  case 2045200: return "長野県筑北村";
  case 2048100: return "長野県池田町";
  case 2048200: return "長野県松川村";
  case 2048500: return "長野県白馬村";
  case 2048600: return "長野県小谷村";
  case 2052100: return "長野県坂城町";
  case 2054100: return "長野県小布施町";
  case 2054300: return "長野県高山村";
  case 2056100: return "長野県山ノ内町";
  case 2056200: return "長野県木島平村";
  case 2056300: return "長野県野沢温泉村";
  case 2058300: return "長野県信濃町";
  case 2058800: return "長野県小川村";
  case 2059000: return "長野県飯綱町";
  case 2060200: return "長野県栄村";
  case 2099999: return "長野県のその他の市町村";
  case 2120100: return "岐阜県岐阜市";
  case 2120200: return "岐阜県大垣市";
  case 2120300: return "岐阜県高山市";
  case 2120400: return "岐阜県多治見市";
  case 2120500: return "岐阜県関市";
  case 2120600: return "岐阜県中津川市";
  case 2120700: return "岐阜県美濃市";
  case 2120800: return "岐阜県瑞浪市";
  case 2120900: return "岐阜県羽島市";
  case 2121000: return "岐阜県恵那市";
  case 2121100: return "岐阜県美濃加茂市";
  case 2121200: return "岐阜県土岐市";
  case 2121300: return "岐阜県各務原市";
  case 2121400: return "岐阜県可児市";
  case 2121500: return "岐阜県山県市";
  case 2121600: return "岐阜県瑞穂市";
  case 2121700: return "岐阜県飛騨市";
  case 2121800: return "岐阜県本巣市";
  case 2121900: return "岐阜県郡上市";
  case 2122000: return "岐阜県下呂市";
  case 2122100: return "岐阜県海津市";
  case 2130200: return "岐阜県岐南町";
  case 2130300: return "岐阜県笠松町";
  case 2134100: return "岐阜県養老町";
  case 2136100: return "岐阜県垂井町";
  case 2136200: return "岐阜県関ケ原町";
  case 2138100: return "岐阜県神戸町";
  case 2138200: return "岐阜県輪之内町";
  case 2138300: return "岐阜県安八町";
  case 2140100: return "岐阜県揖斐川町";
  case 2140300: return "岐阜県大野町";
  case 2140400: return "岐阜県池田町";
  case 2142100: return "岐阜県北方町";
  case 2150100: return "岐阜県坂祝町";
  case 2150200: return "岐阜県富加町";
  case 2150300: return "岐阜県川辺町";
  case 2150400: return "岐阜県七宗町";
  case 2150500: return "岐阜県八百津町";
  case 2150600: return "岐阜県白川町";
  case 2150700: return "岐阜県東白川村";
  case 2152100: return "岐阜県御嵩町";
  case 2160400: return "岐阜県白川村";
  case 2199999: return "岐阜県のその他の市町村";
  case 2210000: return "静岡県静岡市";
  case 2213000: return "静岡県浜松市";
  case 2220300: return "静岡県沼津市";
  case 2220500: return "静岡県熱海市";
  case 2220600: return "静岡県三島市";
  case 2220700: return "静岡県富士宮市";
  case 2220800: return "静岡県伊東市";
  case 2220900: return "静岡県島田市";
  case 2221000: return "静岡県富士市";
  case 2221100: return "静岡県磐田市";
  case 2221200: return "静岡県焼津市";
  case 2221300: return "静岡県掛川市";
  case 2221400: return "静岡県藤枝市";
  case 2221500: return "静岡県御殿場市";
  case 2221600: return "静岡県袋井市";
  case 2221900: return "静岡県下田市";
  case 2222000: return "静岡県裾野市";
  case 2222100: return "静岡県湖西市";
  case 2222200: return "静岡県伊豆市";
  case 2222300: return "静岡県御前崎市";
  case 2222400: return "静岡県菊川市";
  case 2222500: return "静岡県伊豆の国市";
  case 2222600: return "静岡県牧之原市";
  case 2230100: return "静岡県東伊豆町";
  case 2230200: return "静岡県河津町";
  case 2230400: return "静岡県南伊豆町";
  case 2230500: return "静岡県松崎町";
  case 2230600: return "静岡県西伊豆町";
  case 2232500: return "静岡県函南町";
  case 2234100: return "静岡県清水町";
  case 2234200: return "静岡県長泉町";
  case 2234400: return "静岡県小山町";
  case 2242400: return "静岡県吉田町";
  case 2242900: return "静岡県川根本町";
  case 2246100: return "静岡県森町";
  case 2299999: return "静岡県のその他の市町村";
  case 2310000: return "愛知県名古屋市";
  case 2320100: return "愛知県豊橋市";
  case 2320200: return "愛知県岡崎市";
  case 2320300: return "愛知県一宮市";
  case 2320400: return "愛知県瀬戸市";
  case 2320500: return "愛知県半田市";
  case 2320600: return "愛知県春日井市";
  case 2320700: return "愛知県豊川市";
  case 2320800: return "愛知県津島市";
  case 2320900: return "愛知県碧南市";
  case 2321000: return "愛知県刈谷市";
  case 2321100: return "愛知県豊田市";
  case 2321200: return "愛知県安城市";
  case 2321300: return "愛知県西尾市";
  case 2321400: return "愛知県蒲郡市";
  case 2321500: return "愛知県犬山市";
  case 2321600: return "愛知県常滑市";
  case 2321700: return "愛知県江南市";
  case 2321900: return "愛知県小牧市";
  case 2322000: return "愛知県稲沢市";
  case 2322100: return "愛知県新城市";
  case 2322200: return "愛知県東海市";
  case 2322300: return "愛知県大府市";
  case 2322400: return "愛知県知多市";
  case 2322500: return "愛知県知立市";
  case 2322600: return "愛知県尾張旭市";
  case 2322700: return "愛知県高浜市";
  case 2322800: return "愛知県岩倉市";
  case 2322900: return "愛知県豊明市";
  case 2323000: return "愛知県日進市";
  case 2323100: return "愛知県田原市";
  case 2323200: return "愛知県愛西市";
  case 2323300: return "愛知県清須市";
  case 2323400: return "愛知県北名古屋市";
  case 2323500: return "愛知県弥富市";
  case 2323600: return "愛知県みよし市";
  case 2323700: return "愛知県あま市";
  case 2323800: return "愛知県長久手市";
  case 2330200: return "愛知県東郷町";
  case 2334200: return "愛知県豊山町";
  case 2336100: return "愛知県大口町";
  case 2336200: return "愛知県扶桑町";
  case 2342400: return "愛知県大治町";
  case 2342500: return "愛知県蟹江町";
  case 2342700: return "愛知県飛島村";
  case 2344100: return "愛知県阿久比町";
  case 2344200: return "愛知県東浦町";
  case 2344500: return "愛知県南知多町";
  case 2344600: return "愛知県美浜町";
  case 2344700: return "愛知県武豊町";
  case 2350100: return "愛知県幸田町";
  case 2356100: return "愛知県設楽町";
  case 2356200: return "愛知県東栄町";
  case 2356300: return "愛知県豊根村";
  case 2399999: return "愛知県のその他の市町村";
  case 2420100: return "三重県津市";
  case 2420200: return "三重県四日市市";
  case 2420300: return "三重県伊勢市";
  case 2420400: return "三重県松阪市";
  case 2420500: return "三重県桑名市";
  case 2420700: return "三重県鈴鹿市";
  case 2420800: return "三重県名張市";
  case 2420900: return "三重県尾鷲市";
  case 2421000: return "三重県亀山市";
  case 2421100: return "三重県鳥羽市";
  case 2421200: return "三重県熊野市";
  case 2421400: return "三重県いなべ市";
  case 2421500: return "三重県志摩市";
  case 2421600: return "三重県伊賀市";
  case 2430300: return "三重県木曽岬町";
  case 2432400: return "三重県東員町";
  case 2434100: return "三重県菰野町";
  case 2434300: return "三重県朝日町";
  case 2434400: return "三重県川越町";
  case 2444100: return "三重県多気町";
  case 2444200: return "三重県明和町";
  case 2444300: return "三重県大台町";
  case 2446100: return "三重県玉城町";
  case 2447000: return "三重県度会町";
  case 2447100: return "三重県大紀町";
  case 2447200: return "三重県南伊勢町";
  case 2454300: return "三重県紀北町";
  case 2456100: return "三重県御浜町";
  case 2456200: return "三重県紀宝町";
  case 2499999: return "三重県のその他の市町村";
  case 2520100: return "滋賀県大津市";
  case 2520200: return "滋賀県彦根市";
  case 2520300: return "滋賀県長浜市";
  case 2520400: return "滋賀県近江八幡市";
  case 2520600: return "滋賀県草津市";
  case 2520700: return "滋賀県守山市";
  case 2520800: return "滋賀県栗東市";
  case 2520900: return "滋賀県甲賀市";
  case 2521000: return "滋賀県野洲市";
  case 2521100: return "滋賀県湖南市";
  case 2521200: return "滋賀県高島市";
  case 2521300: return "滋賀県東近江市";
  case 2521400: return "滋賀県米原市";
  case 2538300: return "滋賀県日野町";
  case 2538400: return "滋賀県竜王町";
  case 2542500: return "滋賀県愛荘町";
  case 2544100: return "滋賀県豊郷町";
  case 2544200: return "滋賀県甲良町";
  case 2544300: return "滋賀県多賀町";
  case 2599999: return "滋賀県のその他の市町村";
  case 2610000: return "京都府京都市";
  case 2620100: return "京都府福知山市";
  case 2620200: return "京都府舞鶴市";
  case 2620300: return "京都府綾部市";
  case 2620400: return "京都府宇治市";
  case 2620500: return "京都府宮津市";
  case 2620600: return "京都府亀岡市";
  case 2620700: return "京都府城陽市";
  case 2620800: return "京都府向日市";
  case 2620900: return "京都府長岡京市";
  case 2621000: return "京都府八幡市";
  case 2621100: return "京都府京田辺市";
  case 2621200: return "京都府京丹後市";
  case 2621300: return "京都府南丹市";
  case 2621400: return "京都府木津川市";
  case 2630300: return "京都府大山崎町";
  case 2632200: return "京都府久御山町";
  case 2634300: return "京都府井手町";
  case 2634400: return "京都府宇治田原町";
  case 2636400: return "京都府笠置町";
  case 2636500: return "京都府和束町";
  case 2636600: return "京都府精華町";
  case 2636700: return "京都府南山城村";
  case 2640700: return "京都府京丹波町";
  case 2646300: return "京都府伊根町";
  case 2646500: return "京都府与謝野町";
  case 2699999: return "京都府のその他の市町村";
  case 2710000: return "大阪府大阪市";
  case 2714000: return "大阪府堺市";
  case 2720200: return "大阪府岸和田市";
  case 2720300: return "大阪府豊中市";
  case 2720400: return "大阪府池田市";
  case 2720500: return "大阪府吹田市";
  case 2720600: return "大阪府泉大津市";
  case 2720700: return "大阪府高槻市";
  case 2720800: return "大阪府貝塚市";
  case 2720900: return "大阪府守口市";
  case 2721000: return "大阪府枚方市";
  case 2721100: return "大阪府茨木市";
  case 2721200: return "大阪府八尾市";
  case 2721300: return "大阪府泉佐野市";
  case 2721400: return "大阪府富田林市";
  case 2721500: return "大阪府寝屋川市";
  case 2721600: return "大阪府河内長野市";
  case 2721700: return "大阪府松原市";
  case 2721800: return "大阪府大東市";
  case 2721900: return "大阪府和泉市";
  case 2722000: return "大阪府箕面市";
  case 2722100: return "大阪府柏原市";
  case 2722200: return "大阪府羽曳野市";
  case 2722300: return "大阪府門真市";
  case 2722400: return "大阪府摂津市";
  case 2722500: return "大阪府高石市";
  case 2722600: return "大阪府藤井寺市";
  case 2722700: return "大阪府東大阪市";
  case 2722800: return "大阪府泉南市";
  case 2722900: return "大阪府四條畷市";
  case 2723000: return "大阪府交野市";
  case 2723100: return "大阪府大阪狭山市";
  case 2723200: return "大阪府阪南市";
  case 2730100: return "大阪府島本町";
  case 2732100: return "大阪府豊能町";
  case 2732200: return "大阪府能勢町";
  case 2734100: return "大阪府忠岡町";
  case 2736100: return "大阪府熊取町";
  case 2736200: return "大阪府田尻町";
  case 2736600: return "大阪府岬町";
  case 2738100: return "大阪府太子町";
  case 2738200: return "大阪府河南町";
  case 2738300: return "大阪府千早赤阪村";
  case 2799999: return "大阪府のその他の市町村";
  case 2810000: return "兵庫県神戸市";
  case 2820100: return "兵庫県姫路市";
  case 2820200: return "兵庫県尼崎市";
  case 2820300: return "兵庫県明石市";
  case 2820400: return "兵庫県西宮市";
  case 2820500: return "兵庫県洲本市";
  case 2820600: return "兵庫県芦屋市";
  case 2820700: return "兵庫県伊丹市";
  case 2820800: return "兵庫県相生市";
  case 2820900: return "兵庫県豊岡市";
  case 2821000: return "兵庫県加古川市";
  case 2821200: return "兵庫県赤穂市";
  case 2821300: return "兵庫県西脇市";
  case 2821400: return "兵庫県宝塚市";
  case 2821500: return "兵庫県三木市";
  case 2821600: return "兵庫県高砂市";
  case 2821700: return "兵庫県川西市";
  case 2821800: return "兵庫県小野市";
  case 2821900: return "兵庫県三田市";
  case 2822000: return "兵庫県加西市";
  case 2822100: return "兵庫県丹波篠山市";
  case 2822200: return "兵庫県養父市";
  case 2822300: return "兵庫県丹波市";
  case 2822400: return "兵庫県南あわじ市";
  case 2822500: return "兵庫県朝来市";
  case 2822600: return "兵庫県淡路市";
  case 2822700: return "兵庫県宍粟市";
  case 2822800: return "兵庫県加東市";
  case 2822900: return "兵庫県たつの市";
  case 2830100: return "兵庫県猪名川町";
  case 2836500: return "兵庫県多可町";
  case 2838100: return "兵庫県稲美町";
  case 2838200: return "兵庫県播磨町";
  case 2844200: return "兵庫県市川町";
  case 2844300: return "兵庫県福崎町";
  case 2844600: return "兵庫県神河町";
  case 2846400: return "兵庫県太子町";
  case 2848100: return "兵庫県上郡町";
  case 2850100: return "兵庫県佐用町";
  case 2858500: return "兵庫県香美町";
  case 2858600: return "兵庫県新温泉町";
  case 2899999: return "兵庫県のその他の市町村";
  case 2920100: return "奈良県奈良市";
  case 2920200: return "奈良県大和高田市";
  case 2920300: return "奈良県大和郡山市";
  case 2920400: return "奈良県天理市";
  case 2920500: return "奈良県橿原市";
  case 2920600: return "奈良県桜井市";
  case 2920700: return "奈良県五條市";
  case 2920800: return "奈良県御所市";
  case 2920900: return "奈良県生駒市";
  case 2921000: return "奈良県香芝市";
  case 2921100: return "奈良県葛城市";
  case 2921200: return "奈良県宇陀市";
  case 2932200: return "奈良県山添村";
  case 2934200: return "奈良県平群町";
  case 2934300: return "奈良県三郷町";
  case 2934400: return "奈良県斑鳩町";
  case 2934500: return "奈良県安堵町";
  case 2936100: return "奈良県川西町";
  case 2936200: return "奈良県三宅町";
  case 2936300: return "奈良県田原本町";
  case 2938500: return "奈良県曽爾村";
  case 2938600: return "奈良県御杖村";
  case 2940100: return "奈良県高取町";
  case 2940200: return "奈良県明日香村";
  case 2942400: return "奈良県上牧町";
  case 2942500: return "奈良県王寺町";
  case 2942600: return "奈良県広陵町";
  case 2942700: return "奈良県河合町";
  case 2944100: return "奈良県吉野町";
  case 2944200: return "奈良県大淀町";
  case 2944300: return "奈良県下市町";
  case 2944400: return "奈良県黒滝村";
  case 2944600: return "奈良県天川村";
  case 2944700: return "奈良県野迫川村";
  case 2944900: return "奈良県十津川村";
  case 2945000: return "奈良県下北山村";
  case 2945100: return "奈良県上北山村";
  case 2945200: return "奈良県川上村";
  case 2945300: return "奈良県東吉野村";
  case 2999999: return "奈良県のその他の市町村";
  case 3020100: return "和歌山県和歌山市";
  case 3020200: return "和歌山県海南市";
  case 3020300: return "和歌山県橋本市";
  case 3020400: return "和歌山県有田市";
  case 3020500: return "和歌山県御坊市";
  case 3020600: return "和歌山県田辺市";
  case 3020700: return "和歌山県新宮市";
  case 3020800: return "和歌山県紀の川市";
  case 3020900: return "和歌山県岩出市";
  case 3030400: return "和歌山県紀美野町";
  case 3034100: return "和歌山県かつらぎ町";
  case 3034300: return "和歌山県九度山町";
  case 3034400: return "和歌山県高野町";
  case 3036100: return "和歌山県湯浅町";
  case 3036200: return "和歌山県広川町";
  case 3036600: return "和歌山県有田川町";
  case 3038100: return "和歌山県美浜町";
  case 3038200: return "和歌山県日高町";
  case 3038300: return "和歌山県由良町";
  case 3039000: return "和歌山県印南町";
  case 3039100: return "和歌山県みなべ町";
  case 3039200: return "和歌山県日高川町";
  case 3040100: return "和歌山県白浜町";
  case 3040400: return "和歌山県上富田町";
  case 3040600: return "和歌山県すさみ町";
  case 3042100: return "和歌山県那智勝浦町";
  case 3042200: return "和歌山県太地町";
  case 3042400: return "和歌山県古座川町";
  case 3042700: return "和歌山県北山村";
  case 3042800: return "和歌山県串本町";
  case 3099999: return "和歌山県のその他の市町村";
  case 3120100: return "鳥取県鳥取市";
  case 3120200: return "鳥取県米子市";
  case 3120300: return "鳥取県倉吉市";
  case 3120400: return "鳥取県境港市";
  case 3130200: return "鳥取県岩美町";
  case 3132500: return "鳥取県若桜町";
  case 3132800: return "鳥取県智頭町";
  case 3132900: return "鳥取県八頭町";
  case 3136400: return "鳥取県三朝町";
  case 3137000: return "鳥取県湯梨浜町";
  case 3137100: return "鳥取県琴浦町";
  case 3137200: return "鳥取県北栄町";
  case 3138400: return "鳥取県日吉津村";
  case 3138600: return "鳥取県大山町";
  case 3138900: return "鳥取県南部町";
  case 3139000: return "鳥取県伯耆町";
  case 3140100: return "鳥取県日南町";
  case 3140200: return "鳥取県日野町";
  case 3140300: return "鳥取県江府町";
  case 3199999: return "鳥取県のその他の市町村";
  case 3220100: return "島根県松江市";
  case 3220200: return "島根県浜田市";
  case 3220300: return "島根県出雲市";
  case 3220400: return "島根県益田市";
  case 3220500: return "島根県大田市";
  case 3220600: return "島根県安来市";
  case 3220700: return "島根県江津市";
  case 3220900: return "島根県雲南市";
  case 3234300: return "島根県奥出雲町";
  case 3238600: return "島根県飯南町";
  case 3244100: return "島根県川本町";
  case 3244800: return "島根県美郷町";
  case 3244900: return "島根県邑南町";
  case 3250100: return "島根県津和野町";
  case 3250500: return "島根県吉賀町";
  case 3252500: return "島根県海士町";
  case 3252600: return "島根県西ノ島町";
  case 3252700: return "島根県知夫村";
  case 3252800: return "島根県隠岐の島町";
  case 3299999: return "島根県のその他の市町村";
  case 3310000: return "岡山県岡山市";
  case 3320200: return "岡山県倉敷市";
  case 3320300: return "岡山県津山市";
  case 3320400: return "岡山県玉野市";
  case 3320500: return "岡山県笠岡市";
  case 3320700: return "岡山県井原市";
  case 3320800: return "岡山県総社市";
  case 3320900: return "岡山県高梁市";
  case 3321000: return "岡山県新見市";
  case 3321100: return "岡山県備前市";
  case 3321200: return "岡山県瀬戸内市";
  case 3321300: return "岡山県赤磐市";
  case 3321400: return "岡山県真庭市";
  case 3321500: return "岡山県美作市";
  case 3321600: return "岡山県浅口市";
  case 3334600: return "岡山県和気町";
  case 3342300: return "岡山県早島町";
  case 3344500: return "岡山県里庄町";
  case 3346100: return "岡山県矢掛町";
  case 3358600: return "岡山県新庄村";
  case 3360600: return "岡山県鏡野町";
  case 3362200: return "岡山県勝央町";
  case 3362300: return "岡山県奈義町";
  case 3364300: return "岡山県西粟倉村";
  case 3366300: return "岡山県久米南町";
  case 3366600: return "岡山県美咲町";
  case 3368100: return "岡山県吉備中央町";
  case 3399999: return "岡山県のその他の市町村";
  case 3410000: return "広島県広島市";
  case 3420200: return "広島県呉市";
  case 3420300: return "広島県竹原市";
  case 3420400: return "広島県三原市";
  case 3420500: return "広島県尾道市";
  case 3420700: return "広島県福山市";
  case 3420800: return "広島県府中市";
  case 3420900: return "広島県三次市";
  case 3421000: return "広島県庄原市";
  case 3421100: return "広島県大竹市";
  case 3421200: return "広島県東広島市";
  case 3421300: return "広島県廿日市市";
  case 3421400: return "広島県安芸高田市";
  case 3421500: return "広島県江田島市";
  case 3430200: return "広島県府中町";
  case 3430400: return "広島県海田町";
  case 3430700: return "広島県熊野町";
  case 3430900: return "広島県坂町";
  case 3436800: return "広島県安芸太田町";
  case 3436900: return "広島県北広島町";
  case 3443100: return "広島県大崎上島町";
  case 3446200: return "広島県世羅町";
  case 3454500: return "広島県神石高原町";
  case 3499999: return "広島県のその他の市町村";
  case 3520100: return "山口県下関市";
  case 3520200: return "山口県宇部市";
  case 3520300: return "山口県山口市";
  case 3520400: return "山口県萩市";
  case 3520600: return "山口県防府市";
  case 3520700: return "山口県下松市";
  case 3520800: return "山口県岩国市";
  case 3521000: return "山口県光市";
  case 3521100: return "山口県長門市";
  case 3521200: return "山口県柳井市";
  case 3521300: return "山口県美祢市";
  case 3521500: return "山口県周南市";
  case 3521600: return "山口県山陽小野田市";
  case 3530500: return "山口県周防大島町";
  case 3532100: return "山口県和木町";
  case 3534100: return "山口県上関町";
  case 3534300: return "山口県田布施町";
  case 3534400: return "山口県平生町";
  case 3550200: return "山口県阿武町";
  case 3599999: return "山口県のその他の市町村";
  case 3620100: return "徳島県徳島市";
  case 3620200: return "徳島県鳴門市";
  case 3620300: return "徳島県小松島市";
  case 3620400: return "徳島県阿南市";
  case 3620500: return "徳島県吉野川市";
  case 3620600: return "徳島県阿波市";
  case 3620700: return "徳島県美馬市";
  case 3620800: return "徳島県三好市";
  case 3630100: return "徳島県勝浦町";
  case 3630200: return "徳島県上勝町";
  case 3632100: return "徳島県佐那河内村";
  case 3634100: return "徳島県石井町";
  case 3634200: return "徳島県神山町";
  case 3636800: return "徳島県那賀町";
  case 3638300: return "徳島県牟岐町";
  case 3638700: return "徳島県美波町";
  case 3638800: return "徳島県海陽町";
  case 3640100: return "徳島県松茂町";
  case 3640200: return "徳島県北島町";
  case 3640300: return "徳島県藍住町";
  case 3640400: return "徳島県板野町";
  case 3640500: return "徳島県上板町";
  case 3646800: return "徳島県つるぎ町";
  case 3648900: return "徳島県東みよし町";
  case 3699999: return "徳島県のその他の市町村";
  case 3720100: return "香川県高松市";
  case 3720200: return "香川県丸亀市";
  case 3720300: return "香川県坂出市";
  case 3720400: return "香川県善通寺市";
  case 3720500: return "香川県観音寺市";
  case 3720600: return "香川県さぬき市";
  case 3720700: return "香川県東かがわ市";
  case 3720800: return "香川県三豊市";
  case 3732200: return "香川県土庄町";
  case 3732400: return "香川県小豆島町";
  case 3734100: return "香川県三木町";
  case 3736400: return "香川県直島町";
  case 3738600: return "香川県宇多津町";
  case 3738700: return "香川県綾川町";
  case 3740300: return "香川県琴平町";
  case 3740400: return "香川県多度津町";
  case 3740600: return "香川県まんのう町";
  case 3799999: return "香川県のその他の市町村";
  case 3820100: return "愛媛県松山市";
  case 3820200: return "愛媛県今治市";
  case 3820300: return "愛媛県宇和島市";
  case 3820400: return "愛媛県八幡浜市";
  case 3820500: return "愛媛県新居浜市";
  case 3820600: return "愛媛県西条市";
  case 3820700: return "愛媛県大洲市";
  case 3821000: return "愛媛県伊予市";
  case 3821300: return "愛媛県四国中央市";
  case 3821400: return "愛媛県西予市";
  case 3821500: return "愛媛県東温市";
  case 3835600: return "愛媛県上島町";
  case 3838600: return "愛媛県久万高原町";
  case 3840100: return "愛媛県松前町";
  case 3840200: return "愛媛県砥部町";
  case 3842200: return "愛媛県内子町";
  case 3844200: return "愛媛県伊方町";
  case 3848400: return "愛媛県松野町";
  case 3848800: return "愛媛県鬼北町";
  case 3850600: return "愛媛県愛南町";
  case 3899999: return "愛媛県のその他の市町村";
  case 3920100: return "高知県高知市";
  case 3920200: return "高知県室戸市";
  case 3920300: return "高知県安芸市";
  case 3920400: return "高知県南国市";
  case 3920500: return "高知県土佐市";
  case 3920600: return "高知県須崎市";
  case 3920800: return "高知県宿毛市";
  case 3920900: return "高知県土佐清水市";
  case 3921000: return "高知県四万十市";
  case 3921100: return "高知県香南市";
  case 3921200: return "高知県香美市";
  case 3930100: return "高知県東洋町";
  case 3930200: return "高知県奈半利町";
  case 3930300: return "高知県田野町";
  case 3930400: return "高知県安田町";
  case 3930500: return "高知県北川村";
  case 3930600: return "高知県馬路村";
  case 3930700: return "高知県芸西村";
  case 3934100: return "高知県本山町";
  case 3934400: return "高知県大豊町";
  case 3936300: return "高知県土佐町";
  case 3936400: return "高知県大川村";
  case 3938600: return "高知県いの町";
  case 3938700: return "高知県仁淀川町";
  case 3940100: return "高知県中土佐町";
  case 3940200: return "高知県佐川町";
  case 3940300: return "高知県越知町";
  case 3940500: return "高知県檮原町";
  case 3941000: return "高知県日高村";
  case 3941100: return "高知県津野町";
  case 3941200: return "高知県四万十町";
  case 3942400: return "高知県大月町";
  case 3942700: return "高知県三原村";
  case 3942800: return "高知県黒潮町";
  case 3999999: return "高知県のその他の市町村";
  case 4010000: return "福岡県北九州市";
  case 4013000: return "福岡県福岡市";
  case 4020200: return "福岡県大牟田市";
  case 4020300: return "福岡県久留米市";
  case 4020400: return "福岡県直方市";
  case 4020500: return "福岡県飯塚市";
  case 4020600: return "福岡県田川市";
  case 4020700: return "福岡県柳川市";
  case 4021000: return "福岡県八女市";
  case 4021100: return "福岡県筑後市";
  case 4021200: return "福岡県大川市";
  case 4021300: return "福岡県行橋市";
  case 4021400: return "福岡県豊前市";
  case 4021500: return "福岡県中間市";
  case 4021600: return "福岡県小郡市";
  case 4021700: return "福岡県筑紫野市";
  case 4021800: return "福岡県春日市";
  case 4021900: return "福岡県大野城市";
  case 4022000: return "福岡県宗像市";
  case 4022100: return "福岡県太宰府市";
  case 4022300: return "福岡県古賀市";
  case 4022400: return "福岡県福津市";
  case 4022500: return "福岡県うきは市";
  case 4022600: return "福岡県宮若市";
  case 4022700: return "福岡県嘉麻市";
  case 4022800: return "福岡県朝倉市";
  case 4022900: return "福岡県みやま市";
  case 4023000: return "福岡県糸島市";
  case 4023100: return "福岡県那珂川市";
  case 4034100: return "福岡県宇美町";
  case 4034200: return "福岡県篠栗町";
  case 4034300: return "福岡県志免町";
  case 4034400: return "福岡県須恵町";
  case 4034500: return "福岡県新宮町";
  case 4034800: return "福岡県久山町";
  case 4034900: return "福岡県粕屋町";
  case 4038100: return "福岡県芦屋町";
  case 4038200: return "福岡県水巻町";
  case 4038300: return "福岡県岡垣町";
  case 4038400: return "福岡県遠賀町";
  case 4040100: return "福岡県小竹町";
  case 4040200: return "福岡県鞍手町";
  case 4042100: return "福岡県桂川町";
  case 4044700: return "福岡県筑前町";
  case 4044800: return "福岡県東峰村";
  case 4050300: return "福岡県大刀洗町";
  case 4052200: return "福岡県大木町";
  case 4054400: return "福岡県広川町";
  case 4060100: return "福岡県香春町";
  case 4060200: return "福岡県添田町";
  case 4060400: return "福岡県糸田町";
  case 4060500: return "福岡県川崎町";
  case 4060800: return "福岡県大任町";
  case 4060900: return "福岡県赤村";
  case 4061000: return "福岡県福智町";
  case 4062100: return "福岡県苅田町";
  case 4062500: return "福岡県みやこ町";
  case 4064200: return "福岡県吉富町";
  case 4064600: return "福岡県上毛町";
  case 4064700: return "福岡県築上町";
  case 4099999: return "福岡県のその他の市町村";
  case 4120100: return "佐賀県佐賀市";
  case 4120200: return "佐賀県唐津市";
  case 4120300: return "佐賀県鳥栖市";
  case 4120400: return "佐賀県多久市";
  case 4120500: return "佐賀県伊万里市";
  case 4120600: return "佐賀県武雄市";
  case 4120700: return "佐賀県鹿島市";
  case 4120800: return "佐賀県小城市";
  case 4120900: return "佐賀県嬉野市";
  case 4121000: return "佐賀県神埼市";
  case 4132700: return "佐賀県吉野ヶ里町";
  case 4134100: return "佐賀県基山町";
  case 4134500: return "佐賀県上峰町";
  case 4134600: return "佐賀県みやき町";
  case 4138700: return "佐賀県玄海町";
  case 4140100: return "佐賀県有田町";
  case 4142300: return "佐賀県大町町";
  case 4142400: return "佐賀県江北町";
  case 4142500: return "佐賀県白石町";
  case 4144100: return "佐賀県太良町";
  case 4199999: return "佐賀県のその他の市町村";
  case 4220100: return "長崎県長崎市";
  case 4220200: return "長崎県佐世保市";
  case 4220300: return "長崎県島原市";
  case 4220400: return "長崎県諫早市";
  case 4220500: return "長崎県大村市";
  case 4220700: return "長崎県平戸市";
  case 4220800: return "長崎県松浦市";
  case 4220900: return "長崎県対馬市";
  case 4221000: return "長崎県壱岐市";
  case 4221100: return "長崎県五島市";
  case 4221200: return "長崎県西海市";
  case 4221300: return "長崎県雲仙市";
  case 4221400: return "長崎県南島原市";
  case 4230700: return "長崎県長与町";
  case 4230800: return "長崎県時津町";
  case 4232100: return "長崎県東彼杵町";
  case 4232200: return "長崎県川棚町";
  case 4232300: return "長崎県波佐見町";
  case 4238300: return "長崎県小値賀町";
  case 4239100: return "長崎県佐々町";
  case 4241100: return "長崎県新上五島町";
  case 4299999: return "長崎県のその他の市町村";
  case 4310000: return "熊本県熊本市";
  case 4320200: return "熊本県八代市";
  case 4320300: return "熊本県人吉市";
  case 4320400: return "熊本県荒尾市";
  case 4320500: return "熊本県水俣市";
  case 4320600: return "熊本県玉名市";
  case 4320800: return "熊本県山鹿市";
  case 4321000: return "熊本県菊池市";
  case 4321100: return "熊本県宇土市";
  case 4321200: return "熊本県上天草市";
  case 4321300: return "熊本県宇城市";
  case 4321400: return "熊本県阿蘇市";
  case 4321500: return "熊本県天草市";
  case 4321600: return "熊本県合志市";
  case 4334800: return "熊本県美里町";
  case 4336400: return "熊本県玉東町";
  case 4336700: return "熊本県南関町";
  case 4336800: return "熊本県長洲町";
  case 4336900: return "熊本県和水町";
  case 4340300: return "熊本県大津町";
  case 4340400: return "熊本県菊陽町";
  case 4342300: return "熊本県南小国町";
  case 4342400: return "熊本県小国町";
  case 4342500: return "熊本県産山村";
  case 4342800: return "熊本県高森町";
  case 4343200: return "熊本県西原村";
  case 4343300: return "熊本県南阿蘇村";
  case 4344100: return "熊本県御船町";
  case 4344200: return "熊本県嘉島町";
  case 4344300: return "熊本県益城町";
  case 4344400: return "熊本県甲佐町";
  case 4344700: return "熊本県山都町";
  case 4346800: return "熊本県氷川町";
  case 4348200: return "熊本県芦北町";
  case 4348400: return "熊本県津奈木町";
  case 4350100: return "熊本県錦町";
  case 4350500: return "熊本県多良木町";
  case 4350600: return "熊本県湯前町";
  case 4350700: return "熊本県水上村";
  case 4351000: return "熊本県相良村";
  case 4351100: return "熊本県五木村";
  case 4351200: return "熊本県山江村";
  case 4351300: return "熊本県球磨村";
  case 4351400: return "熊本県あさぎり町";
  case 4353100: return "熊本県苓北町";
  case 4399999: return "熊本県のその他の市町村";
  case 4420100: return "大分県大分市";
  case 4420200: return "大分県別府市";
  case 4420300: return "大分県中津市";
  case 4420400: return "大分県日田市";
  case 4420500: return "大分県佐伯市";
  case 4420600: return "大分県臼杵市";
  case 4420700: return "大分県津久見市";
  case 4420800: return "大分県竹田市";
  case 4420900: return "大分県豊後高田市";
  case 4421000: return "大分県杵築市";
  case 4421100: return "大分県宇佐市";
  case 4421200: return "大分県豊後大野市";
  case 4421300: return "大分県由布市";
  case 4421400: return "大分県国東市";
  case 4432200: return "大分県姫島村";
  case 4434100: return "大分県日出町";
  case 4446100: return "大分県九重町";
  case 4446200: return "大分県玖珠町";
  case 4499999: return "大分県のその他の市町村";
  case 4520100: return "宮崎県宮崎市";
  case 4520200: return "宮崎県都城市";
  case 4520300: return "宮崎県延岡市";
  case 4520400: return "宮崎県日南市";
  case 4520500: return "宮崎県小林市";
  case 4520600: return "宮崎県日向市";
  case 4520700: return "宮崎県串間市";
  case 4520800: return "宮崎県西都市";
  case 4520900: return "宮崎県えびの市";
  case 4534100: return "宮崎県三股町";
  case 4536100: return "宮崎県高原町";
  case 4538200: return "宮崎県国富町";
  case 4538300: return "宮崎県綾町";
  case 4540100: return "宮崎県高鍋町";
  case 4540200: return "宮崎県新富町";
  case 4540300: return "宮崎県西米良村";
  case 4540400: return "宮崎県木城町";
  case 4540500: return "宮崎県川南町";
  case 4540600: return "宮崎県都農町";
  case 4542100: return "宮崎県門川町";
  case 4542900: return "宮崎県諸塚村";
  case 4543000: return "宮崎県椎葉村";
  case 4543100: return "宮崎県美郷町";
  case 4544100: return "宮崎県高千穂町";
  case 4544200: return "宮崎県日之影町";
  case 4544300: return "宮崎県五ヶ瀬町";
  case 4599999: return "宮崎県のその他の市町村";
  case 4620100: return "鹿児島県鹿児島市";
  case 4620300: return "鹿児島県鹿屋市";
  case 4620400: return "鹿児島県枕崎市";
  case 4620600: return "鹿児島県阿久根市";
  case 4620800: return "鹿児島県出水市";
  case 4621000: return "鹿児島県指宿市";
  case 4621300: return "鹿児島県西之表市";
  case 4621400: return "鹿児島県垂水市";
  case 4621500: return "鹿児島県薩摩川内市";
  case 4621600: return "鹿児島県日置市";
  case 4621700: return "鹿児島県曽於市";
  case 4621800: return "鹿児島県霧島市";
  case 4621900: return "鹿児島県いちき串木野市";
  case 4622000: return "鹿児島県南さつま市";
  case 4622100: return "鹿児島県志布志市";
  case 4622200: return "鹿児島県奄美市";
  case 4622300: return "鹿児島県南九州市";
  case 4622400: return "鹿児島県伊佐市";
  case 4622500: return "鹿児島県姶良市";
  case 4630300: return "鹿児島県三島村";
  case 4630400: return "鹿児島県十島村";
  case 4639200: return "鹿児島県さつま町";
  case 4640400: return "鹿児島県長島町";
  case 4645200: return "鹿児島県湧水町";
  case 4646800: return "鹿児島県大崎町";
  case 4648200: return "鹿児島県東串良町";
  case 4649000: return "鹿児島県錦江町";
  case 4649100: return "鹿児島県南大隅町";
  case 4649200: return "鹿児島県肝付町";
  case 4650100: return "鹿児島県中種子町";
  case 4650200: return "鹿児島県南種子町";
  case 4650500: return "鹿児島県屋久島町";
  case 4652300: return "鹿児島県大和村";
  case 4652400: return "鹿児島県宇検村";
  case 4652500: return "鹿児島県瀬戸内町";
  case 4652700: return "鹿児島県龍郷町";
  case 4652900: return "鹿児島県喜界町";
  case 4653000: return "鹿児島県徳之島町";
  case 4653100: return "鹿児島県天城町";
  case 4653200: return "鹿児島県伊仙町";
  case 4653300: return "鹿児島県和泊町";
  case 4653400: return "鹿児島県知名町";
  case 4653500: return "鹿児島県与論町";
  case 4699999: return "鹿児島県のその他の市町村";
  case 4720100: return "沖縄県那覇市";
  case 4720500: return "沖縄県宜野湾市";
  case 4720700: return "沖縄県石垣市";
  case 4720800: return "沖縄県浦添市";
  case 4720900: return "沖縄県名護市";
  case 4721000: return "沖縄県糸満市";
  case 4721100: return "沖縄県沖縄市";
  case 4721200: return "沖縄県豊見城市";
  case 4721300: return "沖縄県うるま市";
  case 4721400: return "沖縄県宮古島市";
  case 4721500: return "沖縄県南城市";
  case 4730100: return "沖縄県国頭村";
  case 4730200: return "沖縄県大宜味村";
  case 4730300: return "沖縄県東村";
  case 4730600: return "沖縄県今帰仁村";
  case 4730800: return "沖縄県本部町";
  case 4731100: return "沖縄県恩納村";
  case 4731300: return "沖縄県宜野座村";
  case 4731400: return "沖縄県金武町";
  case 4731500: return "沖縄県伊江村";
  case 4732400: return "沖縄県読谷村";
  case 4732500: return "沖縄県嘉手納町";
  case 4732600: return "沖縄県北谷町";
  case 4732700: return "沖縄県北中城村";
  case 4732800: return "沖縄県中城村";
  case 4732900: return "沖縄県西原町";
  case 4734800: return "沖縄県与那原町";
  case 4735000: return "沖縄県南風原町";
  case 4735300: return "沖縄県渡嘉敷村";
  case 4735400: return "沖縄県座間味村";
  case 4735500: return "沖縄県粟国村";
  case 4735600: return "沖縄県渡名喜村";
  case 4735700: return "沖縄県南大東村";
  case 4735800: return "沖縄県北大東村";
  case 4735900: return "沖縄県伊平屋村";
  case 4736000: return "沖縄県伊是名村";
  case 4736100: return "沖縄県久米島町";
  case 4736200: return "沖縄県八重瀬町";
  case 4737500: return "沖縄県多良間村";
  case 4738100: return "沖縄県竹富町";
  case 4738200: return "沖縄県与那国町";
  case 4799999: return "沖縄県のその他の市町村";
  default:
    const char *pref;
    switch (code / 100000) {
    case  1: pref = "北海道"; break;
    case  2: pref = "青森県"; break;
    case  3: pref = "岩手県"; break;
    case  4: pref = "宮城県"; break;
    case  5: pref = "秋田県"; break;
    case  6: pref = "山形県"; break;
    case  7: pref = "福島県"; break;
    case  8: pref = "茨城県"; break;
    case  9: pref = "栃木県"; break;
    case 10: pref = "群馬県"; break;
    case 11: pref = "埼玉県"; break;
    case 12: pref = "千葉県"; break;
    case 13: pref = "東京都"; break;
    case 14: pref = "神奈川県"; break;
    case 15: pref = "新潟県"; break;
    case 16: pref = "富山県"; break;
    case 17: pref = "石川県"; break;
    case 18: pref = "福井県"; break;
    case 19: pref = "山梨県"; break;
    case 20: pref = "長野県"; break;
    case 21: pref = "岐阜県"; break;
    case 22: pref = "静岡県"; break;
    case 23: pref = "愛知県"; break;
    case 24: pref = "三重県"; break;
    case 25: pref = "滋賀県"; break;
    case 26: pref = "京都府"; break;
    case 27: pref = "大阪府"; break;
    case 28: pref = "兵庫県"; break;
    case 29: pref = "奈良県"; break;
    case 30: pref = "和歌山県"; break;
    case 31: pref = "鳥取県"; break;
    case 32: pref = "島根県"; break;
    case 33: pref = "岡山県"; break;
    case 34: pref = "広島県"; break;
    case 35: pref = "山口県"; break;
    case 36: pref = "徳島県"; break;
    case 37: pref = "香川県"; break;
    case 38: pref = "愛媛県"; break;
    case 39: pref = "高知県"; break;
    case 40: pref = "福岡県"; break;
    case 41: pref = "佐賀県"; break;
    case 42: pref = "長崎県"; break;
    case 43: pref = "熊本県"; break;
    case 44: pref = "大分県"; break;
    case 45: pref = "宮崎県"; break;
    case 46: pref = "鹿児島県"; break;
    case 47: pref = "沖縄県"; break;
    default: pref = "その他"; break;
    }
    snprintf(_undefMessage, sizeof(_undefMessage),
             "%sの市町村(コード番号：%d)", pref, code);
    return _undefMessage;
  }
}
#endif // defined(QZQSM_ENABLE_DC8) || defined(QZQSM_ENABLE_DC9)

#ifdef QZQSM_ENABLE_DC8

int QZQSM::filter_dc8()
{
  // You can filter out the specific region or information.
  return 1;
}

void QZQSM::report_dc8()
{
  _len += snprintf(&_message[_len], sizeof(_message) - _len,
                   DC8_REPORT, it2str(_Header.It), _jstAtMo, _jstAtD, _jstAtH, _jstAtMi,
                   dc8vo2str(_u.Dc8.Vo), dc8td2str(_u.Dc8.TdD, _u.Dc8.TdH, _u.Dc8.TdM),
                   dc8dw2str(_u.Dc8.Dw));
  int num;
  for (num = 0; num < 5; num++) {
    if (_u.Dc8.Pl[num] != 0) {
      _len += snprintf(&_message[_len], sizeof(_message) - _len,
                       DC8_REPORT2, dc8pl2str(_u.Dc8.Pl[num]));
    }
  }
}

void QZQSM::decode_dc8()
{
  _u.Dc8.TdD   = get_val(53, 5);
  _u.Dc8.TdH   = get_val(58, 5);
  _u.Dc8.TdM   = get_val(63, 6);
  _u.Dc8.Dw    = get_val(69, 7);
  _u.Dc8.Vo    = get_val(76, 12);
  int num;
  for (num = 0; num < 5; num++) {
    _u.Dc8.Pl[num] = get_val(88 + (23 * num), 23);
  }
  if ((_u.Dc8.TdH != 31) && (_u.Dc8.TdM != 63))
    utc2jst(_Header.AtMo, _u.Dc8.TdD, _u.Dc8.TdH, _u.Dc8.TdM);
}
#endif // QZQSM_ENABLE_DC8

#ifdef QZQSM_ENABLE_DC9
//===============================================================
// Disaster Category Code 9
// JMA-DC Report (Ash Fall)

#define DC9_REPORT \
  "災危通報(降灰)(%s)\n\n" \
  "発表時刻：%d月%d日%d時%d分\n\n" \
  "%s\n" \
  "火山名：%s\n" \
  "日時：%d日%d時%d分\n\n"

#define DC9_REPORT2 \
  "基点時刻からの時間：%d時間\n" \
  "現象：%s\n" \
  "%s\n\n"

// Warning State
const char* QZQSM::dc9dw2str(int code)
{
  switch (code) {
  case 1: return "少量の降灰";
  case 2: return "やや多量の降灰";
  case 3: return "多量の降灰";
  case 4: return "小さな噴石の落下";
  case 7: return "その他の防災気象情報要素 2";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "防災気象情報要素 2(コード番号：%d)", code);
    return _undefMessage;
  }
}

int QZQSM::filter_dc9()
{
  // You can filter out the specific region or information.
  return 1;
}

void QZQSM::report_dc9()
{
  _len += snprintf(&_message[_len], sizeof(_message) - _len,
                   DC9_REPORT, it2str(_Header.It), _jstAtMo, _jstAtD, _jstAtH, _jstAtMi,
                   (_u.Dc9.Dw1 == 1) ? "降灰予報(速報)" : "降灰予報(詳細)",
                   dc8vo2str(_u.Dc9.Vo), _u.Dc9.TdD, _u.Dc9.TdH, _u.Dc9.TdM);
  int num;
  for (num = 0; num < 4; num++) {
    if (_u.Dc9.site[num].Pl != 0) {
      _len += snprintf(&_message[_len], sizeof(_message) - _len,
                       DC9_REPORT2, _u.Dc9.site[num].Ho, dc9dw2str(_u.Dc9.site[num].Dw2),
                       dc8pl2str(_u.Dc9.site[num].Pl));
    }
  }
}

void QZQSM::decode_dc9()
{
  _u.Dc9.TdD   = get_val(53, 5);
  _u.Dc9.TdH   = get_val(58, 5);
  _u.Dc9.TdM   = get_val(63, 6);
  _u.Dc9.Dw1   = get_val(69, 2);
  _u.Dc9.Vo    = get_val(71, 12);
  int num;
  for (num = 0; num < 4; num++) {
    _u.Dc9.site[num].Ho  = get_val(83 + (29 * num), 3);
    _u.Dc9.site[num].Dw2 = get_val(86 + (29 * num), 3);
    _u.Dc9.site[num].Pl  = get_val(89 + (29 * num), 23);
  }
  utc2jst(_Header.AtMo, _u.Dc9.TdD, _u.Dc9.TdH, _u.Dc9.TdM);
}
#endif // QZQSM_ENABLE_DC9

#ifdef QZQSM_ENABLE_DC10
//===============================================================
// Disaster Category Code 10
// JMA-DC Report (Weather)

#define DC10_REPORT \
  "災危通報(気象)(%s)\n\n" \
  "発表時刻：%d月%d日%d時%d分\n\n"

#define DC10_REPORT2 \
  "%s：%s\n"

// Warning State
const char* QZQSM::dc10ar2str(int code)
{
  switch (code) {
  case 1: return "発表";
  case 2: return "解除";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "発表状況(コード番号：%d)", code);
    return _undefMessage;
  }
}

// Disaster Sub-Category (Region)
const char* QZQSM::dc10ww2str(int code)
{
  switch (code) {
  case  1: return "暴風雪特別警報";
  case  2: return "大雨特別警報";
  case  3: return "暴風特別警報";
  case  4: return "大雪特別警報";
  case  5: return "波浪特別警報";
  case  6: return "高潮特別警報";
  case  7: return "全ての気象特別警報";
  case 21: return "記録的短時間大雨警報";
  case 22: return "竜巻注意情報";
  case 23: return "土砂災害警戒情報";
  case 31: return "その他の警報等情報要素";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "警報等情報要素(コード番号：%d)", code);
    return _undefMessage;
  }
}

// Prefectual Forecast Region
const char* QZQSM::dc10pl2str(int code)
{
  switch (code) {
  case  11000: return "宗谷地方";
  case  12000: return "上川・留萌地方";
  case  12010: return "上川地方";
  case  12020: return "留萌地方";
  case  13000: return "網走・北見紋別地方";
  case  14010: return "根室地方";
  case  14020: return "釧路地方";
  case  14030: return "十勝地方";
  case  14100: return "釧路・根室地方";
  case  15000: return "胆振・日高地方";
  case  15010: return "胆振地方";
  case  15020: return "日高地方";
  case  16000: return "石狩・空知・後志地方";
  case  16010: return "石狩地方";
  case  16020: return "空知地方";
  case  16030: return "後志地方";
  case  16100: return "石狩・空知地方";
  case  17000: return "渡島・檜山地方";
  case  17010: return "渡島地方";
  case  17020: return "檜山地方";
  case  20000: return "青森県";
  case  30000: return "岩手県";
  case  40000: return "宮城県";
  case  50000: return "秋田県";
  case  60000: return "山形県";
  case  70000: return "福島県";
  case  80000: return "茨城県";
  case  90000: return "栃木県";
  case 100000: return "群馬県";
  case 110000: return "埼玉県";
  case 120000: return "千葉県";
  case 130000: return "東京都";
  case 130010: return "東京地方";
  case 130020: return "伊豆諸島北部";
  case 130030: return "伊豆諸島南部";
  case 140000: return "神奈川県";
  case 150000: return "新潟県";
  case 160000: return "富山県";
  case 170000: return "石川県";
  case 180000: return "福井県";
  case 190000: return "山梨県";
  case 200000: return "長野県";
  case 210000: return "岐阜県";
  case 220000: return "静岡県";
  case 230000: return "愛知県";
  case 240000: return "三重県";
  case 250000: return "滋賀県";
  case 260000: return "京都府";
  case 270000: return "大阪府";
  case 280000: return "兵庫県";
  case 290000: return "奈良県";
  case 300000: return "和歌山県";
  case 310000: return "鳥取県";
  case 320000: return "島根県";
  case 330000: return "岡山県";
  case 340000: return "広島県";
  case 350000: return "山口県";
  case 360000: return "徳島県";
  case 370000: return "香川県";
  case 380000: return "愛媛県";
  case 390000: return "高知県";
  case 400000: return "福岡県";
  case 410000: return "佐賀県";
  case 420000: return "長崎県";
  case 430000: return "熊本県";
  case 440000: return "大分県";
  case 450000: return "宮崎県";
  case 460000: return "鹿児島県";
  case 460040: return "奄美地方";
  case 460100: return "鹿児島県(奄美地方除く)";
  case 471000: return "沖縄本島地方";
  case 472000: return "大東島地方";
  case 473000: return "宮古島地方";
  case 474000: return "八重山地方";
  case 500000: return "その他の府県予報区";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "府県予報区(コード番号：%d)", code);
    return _undefMessage;
  }
}

int QZQSM::filter_dc10()
{
  // You can filter out the specific region or information.
  return 1;
}

void QZQSM::report_dc10()
{
  _len += snprintf(&_message[_len], sizeof(_message) - _len,
                   DC10_REPORT, dc10ar2str(_u.Dc10.Ar),
                   _jstAtMo, _jstAtD, _jstAtH, _jstAtMi);
  int num;
  for (num = 0; num < 6; num++) {
    if (_u.Dc10.site[num].Ww == 0) break;
    _len += snprintf(&_message[_len], sizeof(_message) - _len,
                     DC10_REPORT2, dc10ww2str(_u.Dc10.site[num].Ww), dc10pl2str(_u.Dc10.site[num].Pl));
  }
}

void QZQSM::decode_dc10()
{
  _u.Dc10.Ar = get_val(53, 3);
  int num;
  for (num = 0; num < 6; num++) {
    _u.Dc10.site[num].Ww = get_val(56 + (24 * num), 5);
    _u.Dc10.site[num].Pl = get_val(61 + (24 * num), 19);
  }
}
#endif // QZQSM_ENABLE_DC10

#ifdef QZQSM_ENABLE_DC11
//===============================================================
// Disaster Category Code 11
// JMA-DC Report (Flood)

#define DC11_REPORT \
  "災危通報(洪水)(%s)\n\n" \
  "発表時刻：%d月%d日%d時%d分\n\n"

#define DC11_REPORT2 \
  "%s：%s\n"

// Warning Level
const char* QZQSM::dc11lv2str(int code)
{
  switch (code) {
  case  1: return "警報解除";
  case  2: return "氾濫警戒情報";
  case  3: return "氾濫危険情報";
  case  4: return "氾濫発生情報";
  case 15: return "その他の警戒レベル";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "警戒レベル(コード番号：%d)", code);
    return _undefMessage;
  }
}

const char* QZQSM::dc11pl2str(uint64_t code)
{
  switch (code) {
  case  10175000100: return "新川(北海道道央)";
  case  19999999999: return "北海道のその他の河川";
  case  20036000100: return "堤川・駒込川(青森県)";
  case  29999999999: return "青森県のその他の河川";
  case  39999999999: return "岩手県のその他の河川";
  case  40028000100: return "七北田川(宮城県)";
  case  49999999999: return "宮城県のその他の河川";
  case  59999999999: return "秋田県のその他の河川";
  case  60016000100: return "日向川(山形県)";
  case  69999999999: return "山形県のその他の河川";
  case  70006000100: return "宇多川(福島県)";
  case  70010000100: return "新田川(福島県)";
  case  70028000100: return "夏井川(福島県)";
  case  79999999999: return "福島県のその他の河川";
  case  89999999999: return "茨城県のその他の河川";
  case  99999999999: return "栃木県のその他の河川";
  case 109999999999: return "群馬県のその他の河川";
  case 119999999999: return "埼玉県のその他の河川";
  case 129999999999: return "千葉県のその他の河川";
  case 130005000100: return "目黒川(東京都)";
  case 130006000100: return "渋谷川・古川(東京都)";
  case 139999999999: return "東京都のその他の河川";
  case 140019000100: return "酒匂川(神奈川県)";
  case 149999999999: return "神奈川県のその他の河川";
  case 159999999999: return "新潟県のその他の河川";
  case 169999999999: return "富山県のその他の河川";
  case 179999999999: return "石川県のその他の河川";
  case 180006000100: return "南川(福井県)";
  case 180014000100: return "笙の川(福井県)";
  case 189999999999: return "福井県のその他の河川";
  case 199999999999: return "山梨県のその他の河川";
  case 209999999999: return "長野県のその他の河川";
  case 219999999999: return "岐阜県のその他の河川";
  case 220062000100: return "瀬戸川・朝比奈川(静岡県)";
  case 220079000100: return "太田川・原野谷川(静岡県)";
  case 220081000100: return "都田川(静岡県)";
  case 229999999999: return "静岡県のその他の河川";
  case 230029000100: return "境川・逢妻川(愛知県)";
  case 230052000100: return "天白川(愛知県)";
  case 230054000100: return "日光川(愛知県)";
  case 239999999999: return "愛知県のその他の河川";
  case 249999999999: return "三重県のその他の河川";
  case 259999999999: return "滋賀県のその他の河川";
  case 269999999999: return "京都府のその他の河川";
  case 270013000100: return "大津川・槇尾川(大阪府)";
  case 270013000200: return "牛滝川(大阪府)";
  case 279999999999: return "大阪府のその他の河川";
  case 280014000100: return "武庫川(兵庫県)";
  case 280053000100: return "市川(兵庫県)";
  case 280064000100: return "千種川(兵庫県)";
  case 289999999999: return "兵庫県のその他の河川";
  case 299999999999: return "奈良県のその他の河川";
  case 300013000100: return "古座川(和歌山県)";
  case 300066000100: return "日高川(和歌山県)";
  case 300077000100: return "有田川(和歌山県)";
  case 309999999999: return "和歌山県のその他の河川";
  case 310027000100: return "由良川(鳥取県)";
  case 319999999999: return "鳥取県のその他の河川";
  case 320004000100: return "益田川(島根県)";
  case 320011000100: return "周布川(島根県)";
  case 329999999999: return "島根県のその他の河川";
  case 330009000100: return "笹ヶ瀬川・足守川(岡山県)";
  case 339999999999: return "岡山県のその他の河川";
  case 340013000100: return "沼田川(広島県)";
  case 340021000100: return "黒瀬川(広島県)";
  case 349999999999: return "広島県のその他の河川";
  case 350002000102: return "錦川下流部(山口県)";
  case 350002000103: return "錦川中流部(山口県)";
  case 350019000100: return "島田川(山口県)";
  case 350036000100: return "椹野川(山口県)";
  case 350036001900: return "仁保川(山口県)";
  case 350046000100: return "厚東川(山口県)";
  case 359999999999: return "山口県のその他の河川";
  case 360007000100: return "勝浦川(徳島県)";
  case 369999999999: return "徳島県のその他の河川";
  case 370026000100: return "香東川(香川県)";
  case 379999999999: return "香川県のその他の河川";
  case 389999999999: return "愛媛県のその他の河川";
  case 399999999999: return "高知県のその他の河川";
  case 400018000100: return "御笠川(福岡県)";
  case 409999999999: return "福岡県のその他の河川";
  case 419999999999: return "佐賀県のその他の河川";
  case 429999999999: return "長崎県のその他の河川";
  case 439999999999: return "熊本県のその他の河川";
  case 440008000100: return "駅館川(大分県)";
  case 449999999999: return "大分県のその他の河川";
  case 450026000100: return "清武川(宮崎県)";
  case 450040000100: return "広渡川(宮崎県)";
  case 450040000700: return "酒谷川(宮崎県)";
  case 459999999999: return "宮崎県のその他の河川";
  case 460060000100: return "万之瀬川・加世田川(鹿児島県)";
  case 469999999999: return "鹿児島県のその他の河川";
  case 479999999999: return "沖縄県のその他の河川";
  case 809999999999: return "沖縄県のその他の河川";
  case 810101000100: return "天塩川(北海道道北)";
  case 810101008500: return "名寄川(北海道道北)";
  case 810102000100: return "留萌川(北海道道北)";
  case 810103000101: return "石狩川上流(北海道道北)";
  case 810103000102: return "石狩川下流(北海道道央)";
  case 810103003100: return "豊平川(北海道道央)";
  case 810103008100: return "千歳川(北海道道央)";
  case 810103011900: return "夕張川(北海道道央)";
  case 810103018200: return "幾春別川(北海道道央)";
  case 810103025001: return "空知川上流(北海道道北)";
  case 810103025002: return "空知川下流(北海道道央)";
  case 810103033400: return "雨竜川(北海道道央)";
  case 810103040900: return "忠別川(北海道道北)";
  case 810103041000: return "美瑛川(北海道道北)";
  case 810103044200: return "牛朱別川(北海道道北)";
  case 810104000100: return "尻別川(北海道道央)";
  case 810105000100: return "後志利別川(北海道道南)";
  case 810106000100: return "鵡川(北海道道南)";
  case 810107000100: return "沙流川(北海道道南)";
  case 810108000100: return "十勝川(北海道道東)";
  case 810108003400: return "利別川(北海道道東)";
  case 810108011400: return "札内川(北海道道東)";
  case 810108013900: return "音更川(北海道道東)";
  case 810109000100: return "釧路川・新釧路川(北海道道東)";
  case 810110000100: return "網走川(北海道道東)";
  case 810110001000: return "美幌川(北海道道東)";
  case 810111000100: return "常呂川(北海道道東)";
  case 810111002400: return "無加川(北海道道東)";
  case 810112000100: return "湧別川(北海道道東)";
  case 810113000100: return "渚滑川(北海道道東)";
  case 819999999999: return "北海道のその他の河川";
  case 820201000101: return "阿武隈川上流(福島県・宮城県)";
  case 820201000102: return "阿武隈川下流(宮城県)";
  case 820201000400: return "白石川(宮城県)";
  case 820201009900: return "荒川(福島県)";
  case 820202000100: return "名取川(宮城県)";
  case 820202001100: return "広瀬川(宮城県)";
  case 820203000100: return "鳴瀬川(宮城県)";
  case 820203000400: return "吉田川(宮城県)";
  case 820204000101: return "北上川上流(岩手県)";
  case 820204000102: return "北上川下流(宮城県)";
  case 820204001800: return "旧北上川(宮城県)";
  case 820204001900: return "迫川(宮城県)";
  case 820204007100: return "江合川(宮城県)";
  case 820204035600: return "猿ヶ石川(岩手県)";
  case 820204048200: return "雫石川(岩手県)";
  case 820205000102: return "馬淵川下流(青森県)";
  case 820205000103: return "馬淵川中流(青森県)";
  case 820206000100: return "高瀬川(小川原湖)(青森県)";
  case 820207000100: return "岩木川(青森県)";
  case 820207003500: return "十川(青森県)";
  case 820207006101: return "平川上流(青森県)";
  case 820207006102: return "平川下流(青森県)";
  case 820208000100: return "米代川(秋田県)";
  case 820209000101: return "雄物川上流(秋田県)";
  case 820209000102: return "雄物川下流(秋田県)";
  case 820209000400: return "太平川(秋田県)";
  case 820209005500: return "玉川(秋田県)";
  case 820209018700: return "皆瀬川(秋田県)";
  case 820210000100: return "子吉川(秋田県)";
  case 820211000101: return "最上川上流(山形県)";
  case 820211000102: return "最上川下流(山形県)";
  case 820211000103: return "最上川中流(山形県)";
  case 820211007300: return "鮭川(山形県)";
  case 820211017000: return "最上小国川(山形県)";
  case 820211022100: return "丹生川(山形県)";
  case 820211030701: return "須川上流(山形県)";
  case 820211030702: return "須川下流(山形県)";
  case 820211048700: return "屋代川(山形県)";
  case 820212000100: return "赤川(山形県)";
  case 820212000200: return "大山川(山形県)";
  case 829999999999: return "東北地方のその他の河川";
  case 830301000100: return "久慈川(茨城県)";
  case 830302000100: return "那珂川(栃木県・茨城県)";
  case 830302000101: return "那珂川上流部(栃木県)";
  case 830302008300: return "逆川(栃木県)";
  case 830302009400: return "荒川(栃木県)";
  case 830302014300: return "箒川(栃木県)";
  case 830302014700: return "蛇尾川(栃木県)";
  case 830302018300: return "余笹川(栃木県)";
  case 830303000101: return "利根川上流部(群馬県・茨城県・千葉県・埼玉県)";
  case 830303000102: return "利根川下流部(茨城県・千葉県)";
  case 830303000103: return "利根川中流部(茨城県・千葉県)";
  case 830303002800: return "霞ヶ浦・北浦(茨城県・千葉県)";
  case 830303004600: return "桜川(茨城県)";
  case 830303015200: return "小貝川(栃木県・茨城県)";
  case 830303015201: return "小貝川上流部(栃木県)";
  case 830303017900: return "五行川(栃木県)";
  case 830303020300: return "鬼怒川(栃木県・茨城県)";
  case 830303021100: return "田川(栃木県)";
  case 830303030400: return "江戸川(茨城県・埼玉県・東京都・千葉県)";
  case 830303033900: return "中川(埼玉県・東京都)";
  case 830303043600: return "綾瀬川(谷古宇区間)(埼玉県・東京都)";
  case 830303043603: return "綾瀬川中流部(一の橋区間)(埼玉県)";
  case 830303046101: return "渡良瀬川上流部(群馬県・栃木県)";
  case 830303046102: return "渡良瀬川下流部(栃木県・茨城県・群馬県)";
  case 830303048000: return "思川(栃木県)";
  case 830303048100: return "姿川(栃木県)";
  case 830303049400: return "黒川(栃木県)";
  case 830303051700: return "永野川(栃木県)";
  case 830303053000: return "秋山川(栃木県)";
  case 830303054800: return "袋川(栃木県)";
  case 830303060000: return "石田川(群馬県・埼玉県)";
  case 830303068900: return "烏川流域(群馬県・埼玉県)";
  case 830303069600: return "神流川(群馬県・埼玉県)";
  case 830304000100: return "荒川(埼玉県・東京都)";
  case 830304000300: return "芝川・新芝川(埼玉県・東京都)";
  case 830304001200: return "新河岸川(埼玉県)";
  case 830304004400: return "神田川(東京都)";
  case 830304004700: return "妙正寺川(東京都)";
  case 830304006400: return "入間川流域(埼玉県)";
  case 830305000100: return "多摩川(東京都・神奈川県)";
  case 830305000500: return "野川・仙川(東京都)";
  case 830305002000: return "浅川(東京都)";
  case 830306000100: return "鶴見川(神奈川県)";
  case 830307000102: return "相模川下流(神奈川県)";
  case 830307000103: return "相模川中流(神奈川県)";
  case 830308000100: return "富士川(釜無川を含む)(山梨県・静岡県)";
  case 830308039500: return "笛吹川(山梨県)";
  case 830308045500: return "荒川(山梨県)";
  case 830308065700: return "塩川(山梨県)";
  case 839999999999: return "関東地方のその他の河川";
  case 840401000100: return "荒川(新潟県)";
  case 840402000100: return "阿賀野川(新潟県)";
  case 840402000101: return "阿賀川(福島県)";
  case 840403000100: return "千曲川(長野県)";
  case 840403000101: return "千曲川上流(長野県)";
  case 840403000102: return "信濃川下流・中ノ口川(新潟県)";
  case 840403000103: return "信濃川中流(新潟県)";
  case 840403023700: return "魚野川(新潟県)";
  case 840403070500: return "犀川(長野県)";
  case 840403070600: return "裾花川(長野県)";
  case 840403089800: return "奈良井川(長野県)";
  case 840404000100: return "関川(新潟県)";
  case 840405000100: return "姫川(新潟県)";
  case 840406000100: return "黒部川(富山県)";
  case 840407000100: return "常願寺川(富山県)";
  case 840408000101: return "宮川(岐阜県)";
  case 840408000102: return "神通川(富山県)";
  case 840409000100: return "庄川(富山県)";
  case 840410000100: return "小矢部川(富山県)";
  case 840411000100: return "手取川(石川県)";
  case 840412000100: return "梯川(石川県)";
  case 849999999999: return "北陸地方のその他の河川";
  case 850501000100: return "狩野川(静岡県)";
  case 850502000100: return "安倍川(静岡県)";
  case 850503000100: return "大井川(静岡県)";
  case 850504000100: return "菊川(静岡県)";
  case 850505000101: return "天竜川上流(長野県)";
  case 850505000102: return "天竜川下流(静岡県)";
  case 850505071753: return "諏訪湖(長野県)";
  case 850506000100: return "豊川及び豊川放水路(愛知県)";
  case 850507000100: return "矢作川(愛知県)";
  case 850508000100: return "庄内川(岐阜県・愛知県)";
  case 850508000200: return "新川(愛知県)";
  case 850509000102: return "木曽川下流(愛知県・岐阜県・三重県)";
  case 850509000103: return "木曽川中流(岐阜県・愛知県)";
  case 850509000202: return "揖斐川下流(岐阜県・三重県)";
  case 850509000203: return "揖斐川中流(岐阜県)";
  case 850509000401: return "長良川上流(岐阜県)";
  case 850509000402: return "長良川下流(岐阜県・愛知県・三重県)";
  case 850509000403: return "長良川中流(岐阜県)";
  case 850509025500: return "飛騨川(岐阜県)";
  case 850510000100: return "鈴鹿川及び鈴鹿川派川(三重県)";
  case 850511000100: return "雲出川及び雲出古川(三重県)";
  case 850512000100: return "櫛田川(三重県)";
  case 850513000100: return "宮川(三重県)";
  case 859999999999: return "中部地方のその他の河川";
  case 860601000102: return "熊野川下流(三重県・和歌山県)";
  case 860601000103: return "熊野川中流(本宮区間)(和歌山県)";
  case 860601000105: return "熊野川中流(日足区間)(和歌山県)";
  case 860602000100: return "紀の川(奈良県・和歌山県)";
  case 860603000101: return "大和川上流(奈良県・大阪府)";
  case 860603000102: return "大和川下流(奈良県・大阪府)";
  case 860603001300: return "石川(大阪府)";
  case 860604000101: return "瀬田川(滋賀県)";
  case 860604000102: return "淀川(京都府・大阪府)";
  case 860604000103: return "宇治川(京都府・大阪府)";
  case 860604000600: return "寝屋川流域(大阪府)";
  case 860604004700: return "神崎川・安威川(大阪府)";
  case 860604007300: return "猪名川(大阪府・兵庫県)";
  case 860604016702: return "桂川下流(京都府・大阪府)";
  case 860604016703: return "桂川中流・園部川(京都府)";
  case 860604018200: return "鴨川・高野川(京都府)";
  case 860604037101: return "木津川上流(三重県・京都府)";
  case 860604037102: return "木津川下流(京都府)";
  case 860604051600: return "名張川(三重県・奈良県)";
  case 860604086300: return "琵琶湖(滋賀県)";
  case 860604101200: return "姉川(滋賀県)";
  case 860604101300: return "高時川(滋賀県)";
  case 860604120300: return "日野川(滋賀県)";
  case 860604127501: return "野洲川上流(滋賀県)";
  case 860604127502: return "野洲川下流(滋賀県)";
  case 860604131100: return "杣川(滋賀県)";
  case 860605000101: return "加古川上流(兵庫県)";
  case 860605000102: return "加古川下流(兵庫県)";
  case 860606000101: return "揖保川上流(兵庫県)";
  case 860606000102: return "揖保川下流(兵庫県)";
  case 860607000100: return "九頭竜川(福井県)";
  case 860607000200: return "竹田川(福井県)";
  case 860607001902: return "日野川下流(福井県)";
  case 860607001903: return "日野川中流(福井県)";
  case 860607002200: return "足羽川(福井県)";
  case 860608000100: return "北川(福井県)";
  case 860609000102: return "由良川下流(京都府)";
  case 860609000103: return "由良川中流(京都府)";
  case 860610000100: return "円山川(兵庫県)";
  case 860610002600: return "出石川(兵庫県)";
  case 869999999999: return "近畿地方のその他の河川";
  case 870701000100: return "千代川(鳥取県)";
  case 870701000900: return "袋川・新袋川(鳥取県)";
  case 870702000100: return "天神川(鳥取県)";
  case 870702000300: return "小鴨川(鳥取県)";
  case 870702000400: return "国府川(鳥取県)";
  case 870703000100: return "日野川(鳥取県)";
  case 870703000300: return "法勝寺川(鳥取県)";
  case 870704000100: return "斐伊川(島根県)";
  case 870704002800: return "飯梨川(島根県)";
  case 870704024400: return "神戸川(島根県)";
  case 870705000101: return "江の川上流(広島県・島根県)";
  case 870705000102: return "江の川下流(広島県・島根県)";
  case 870705015700: return "神野瀬川(広島県)";
  case 870705016300: return "馬洗川(広島県)";
  case 870705016400: return "西城川(広島県)";
  case 870706000100: return "高津川(島根県)";
  case 870706001700: return "匹見川(島根県)";
  case 870707000100: return "佐波川(山口県)";
  case 870708000100: return "小瀬川(広島県・山口県)";
  case 870709000101: return "太田川上流(広島県)";
  case 870709000102: return "太田川下流(広島県)";
  case 870709002900: return "三篠川(広島県)";
  case 870709004700: return "根谷川(広島県)";
  case 870710000100: return "芦田川(広島県)";
  case 870710001100: return "高屋川(広島県)";
  case 870711000100: return "高梁川(岡山県)";
  case 870711000500: return "小田川(岡山県)";
  case 870712000100: return "旭川(岡山県)";
  case 870712000103: return "旭川水系旭川中流部(岡山県)";
  case 870712000400: return "百間川(岡山県)";
  case 870713000100: return "吉井川(岡山県)";
  case 870713002800: return "金剛川(岡山県)";
  case 879999999999: return "中国地方のその他の河川";
  case 880801000100: return "重信川(愛媛県)";
  case 880802000100: return "肱川(愛媛県)";
  case 880803000100: return "四万十川(高知県)";
  case 880804000100: return "仁淀川(高知県)";
  case 880805000100: return "物部川(高知県)";
  case 880806000100: return "那賀川(徳島県)";
  case 880807000100: return "吉野川(徳島県)";
  case 880808000100: return "土器川(香川県)";
  case 889999999999: return "四国地方のその他の河川";
  case 890901000101: return "遠賀川上流部(福岡県)";
  case 890901000102: return "遠賀川下流部(福岡県)";
  case 890901010300: return "彦山川(福岡県)";
  case 890902000100: return "松浦川(佐賀県)";
  case 890902001300: return "徳須恵川(佐賀県)";
  case 890902004900: return "厳木川(佐賀県)";
  case 890903000100: return "本明川(長崎県)";
  case 890904000100: return "六角川(佐賀県)";
  case 890904000300: return "牛津川(佐賀県)";
  case 890905000100: return "嘉瀬川(佐賀県)";
  case 890906000102: return "筑後川下流部(福岡県・佐賀県)";
  case 890906000104: return "筑後川上中流部(大分県・福岡県)";
  case 890907000100: return "矢部川(福岡県)";
  case 890908000100: return "菊池川水系(熊本県)";
  case 890909000100: return "白川(熊本県)";
  case 890910000100: return "緑川水系(熊本県)";
  case 890911000100: return "球磨川(熊本県)";
  case 890912000101: return "川内川上流部(宮崎県・鹿児島県)";
  case 890912000102: return "川内川下流部(鹿児島県)";
  case 890913000100: return "肝属川水系(鹿児島県)";
  case 890914000101: return "大淀川上流部(宮崎県)";
  case 890914000102: return "大淀川下流部(宮崎県)";
  case 890914003300: return "本庄川(宮崎県)";
  case 890915000100: return "小丸川(宮崎県)";
  case 890916000100: return "五ヶ瀬川・大瀬川(宮崎県)";
  case 890917000100: return "番匠川(大分県)";
  case 890918000100: return "大野川水系(大分県)";
  case 890919000100: return "大分川(大分県)";
  case 890919001100: return "七瀬川(大分県)";
  case 890920000101: return "山国川上流部(大分県・福岡県)";
  case 890920000102: return "山国川下流部(大分県・福岡県)";
  case 899999999999: return "九州地方のその他の河川";
  default:
    const char *pref;
    switch (code / 10000000000) {
    case  1: pref = "北海道"; break;
    case  2: pref = "青森県"; break;
    case  3: pref = "岩手県"; break;
    case  4: pref = "宮城県"; break;
    case  5: pref = "秋田県"; break;
    case  6: pref = "山形県"; break;
    case  7: pref = "福島県"; break;
    case  8: pref = "茨城県"; break;
    case  9: pref = "栃木県"; break;
    case 10: pref = "群馬県"; break;
    case 11: pref = "埼玉県"; break;
    case 12: pref = "千葉県"; break;
    case 13: pref = "東京都"; break;
    case 14: pref = "神奈川県"; break;
    case 15: pref = "新潟県"; break;
    case 16: pref = "富山県"; break;
    case 17: pref = "石川県"; break;
    case 18: pref = "福井県"; break;
    case 19: pref = "山梨県"; break;
    case 20: pref = "長野県"; break;
    case 21: pref = "岐阜県"; break;
    case 22: pref = "静岡県"; break;
    case 23: pref = "愛知県"; break;
    case 24: pref = "三重県"; break;
    case 25: pref = "滋賀県"; break;
    case 26: pref = "京都府"; break;
    case 27: pref = "大阪府"; break;
    case 28: pref = "兵庫県"; break;
    case 29: pref = "奈良県"; break;
    case 30: pref = "和歌山県"; break;
    case 31: pref = "鳥取県"; break;
    case 32: pref = "島根県"; break;
    case 33: pref = "岡山県"; break;
    case 34: pref = "広島県"; break;
    case 35: pref = "山口県"; break;
    case 36: pref = "徳島県"; break;
    case 37: pref = "香川県"; break;
    case 38: pref = "愛媛県"; break;
    case 39: pref = "高知県"; break;
    case 40: pref = "福岡県"; break;
    case 41: pref = "佐賀県"; break;
    case 42: pref = "長崎県"; break;
    case 43: pref = "熊本県"; break;
    case 44: pref = "大分県"; break;
    case 45: pref = "宮崎県"; break;
    case 46: pref = "鹿児島県"; break;
    case 47: pref = "沖縄県"; break;
    case 80: pref = "沖縄県"; break;
    case 81: pref = "北海道"; break;
    case 82: pref = "東北地方"; break;
    case 83: pref = "関東地方"; break;
    case 84: pref = "北陸地方"; break;
    case 85: pref = "中部地方"; break;
    case 86: pref = "近畿地方"; break;
    case 87: pref = "中国地方"; break;
    case 88: pref = "四国地方"; break;
    case 89: pref = "九州地方"; break;
    default: pref = "その他"; break;
    }
    snprintf(_undefMessage, sizeof(_undefMessage),
             "%sの河川(コード番号：%d)", pref, code);
    return _undefMessage;
  }
}

int QZQSM::filter_dc11()
{
  // You can filter out the specific region or information.
  return 1;
}

void QZQSM::report_dc11()
{
  _len += snprintf(&_message[_len], sizeof(_message) - _len,
                   DC11_REPORT, it2str(_Header.It), _jstAtMo, _jstAtD, _jstAtH, _jstAtMi);
  int num;
  for (num = 0; num < 3; num++) {
    if (_u.Dc11.site[num].Lv == 0) break;
    _len += snprintf(&_message[_len], sizeof(_message) - _len,
                     DC11_REPORT2, dc11lv2str(_u.Dc11.site[num].Lv), dc11pl2str(_u.Dc11.site[num].Pl));
  }
}

void QZQSM::decode_dc11()
{
  uint64_t tmp;
  int num;
  for (num = 0; num < 3; num++) {
    _u.Dc11.site[num].Lv = get_val(53 + (44 * num), 4);
    tmp = (uint64_t)get_val(57 + (44 * num), 20);
    _u.Dc11.site[num].Pl = (tmp << 20) | get_val(77 + (44 * num), 20);
  }
}
#endif // QZQSM_ENABLE_DC11

#ifdef QZQSM_ENABLE_DC12
//===============================================================
// Disaster Category Code 12
// JMA-DC Report (Typhoon)

#define DC12_REPORT \
  "災危通報(台風)(%s)\n\n" \
  "発表時刻：%d月%d日%d時%d分\n\n"

#define DC12_REPORT2 \
  "台風：%d号\n" \
  "基点時刻：%d日%d時%d分 (%s) %d時間後\n" \
  "大きさ：%s\n" \
  "強さ：%s\n" \
  "緯度・経度：%s%d度%d分%d秒 %s%d度%d分%d秒\n" \
  "中心気圧(hPa)：%d\n" \
  "最大風速(m/s)：%s\n" \
  "最大瞬間風速(m/s)：%s\n"

// Type of Reference Time
const char* QZQSM::dc12dt2str(int code)
{
  switch (code) {
  case 1: return "実況";
  case 2: return "推定";
  case 3: return "予報";
  default: return "";
  }
}

// Typhoon Scale
const char* QZQSM::dc12sr2str(int code)
{
  switch (code) {
  case  0: return "なし";
  case  1: return "大型";
  case  2: return "超大型";
  case 15: return "その他の大きさ階級分類";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "大きさ階級分類(コード番号：%d)", code);
    return _undefMessage;
  }
}

// Typhoon Intensity
const char* QZQSM::dc12ic2str(int code)
{
  switch (code) {
  case  0: return "なし";
  case  1: return "強い";
  case  2: return "非常に強い";
  case  3: return "猛烈な";
  case 15: return "その他の強さ階級分類";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "強さ階級分類(コード番号：%d)", code);
    return _undefMessage;
  }
}

// Typhoon Intensity
const char* QZQSM::dc12w2str1(int w)
{
  static char wstr1[8];
  if (w == 0) {
    return "不明";
  } else {
    snprintf(wstr1, sizeof(wstr1), "%d", w);
    return wstr1;
  }
}

const char* QZQSM::dc12w2str2(int w)
{
  static char wstr2[8];
  if (w == 0) {
    return "不明";
  } else {
    snprintf(wstr2, sizeof(wstr2), "%d", w);
    return wstr2;
  }
}

int QZQSM::filter_dc12()
{
  // You can filter out the specific region or information.
  return 1;
}

void QZQSM::report_dc12()
{
  _len += snprintf(&_message[_len], sizeof(_message) - _len,
                   DC12_REPORT, it2str(_Header.It), _jstAtMo, _jstAtD, _jstAtH, _jstAtMi);
  _len += snprintf(&_message[_len], sizeof(_message) - _len,
                   DC12_REPORT2, _u.Dc12.Tn, _u.Dc12.BtD, _u.Dc12.BtH, _u.Dc12.BtM,
                   dc12dt2str(_u.Dc12.Dt), _u.Dc12.Du,
                   dc12sr2str(_u.Dc12.Sr), dc12ic2str(_u.Dc12.Ic),
                   _u.Dc12.LatNs ? "南緯" : "北緯", _u.Dc12.LatD, _u.Dc12.LatM, _u.Dc12.LatS,
                   _u.Dc12.LonEw ? "西経" : "東経", _u.Dc12.LonD, _u.Dc12.LonM, _u.Dc12.LonS,
                   _u.Dc12.Pr, dc12w2str1(_u.Dc12.W1), dc12w2str2(_u.Dc12.W2));
}

void QZQSM::decode_dc12()
{
  _u.Dc12.BtD   = get_val( 53, 5);
  _u.Dc12.BtH   = get_val( 58, 5);
  _u.Dc12.BtM   = get_val( 63, 6);
  _u.Dc12.Dt    = get_val( 69, 3);
  _u.Dc12.Du    = get_val( 80, 7);
  _u.Dc12.Tn    = get_val( 87, 7);
  _u.Dc12.Sr    = get_val( 94, 4);
  _u.Dc12.Ic    = get_val( 98, 4);
  _u.Dc12.LatNs = get_val(102, 1);
  _u.Dc12.LatD  = get_val(103, 7);
  _u.Dc12.LatM  = get_val(110, 6);
  _u.Dc12.LatS  = get_val(116, 6);
  _u.Dc12.LonEw = get_val(122, 1);
  _u.Dc12.LonD  = get_val(123, 8);
  _u.Dc12.LonM  = get_val(131, 6);
  _u.Dc12.LonS  = get_val(137, 6);
  _u.Dc12.Pr    = get_val(143, 11);
  _u.Dc12.W1    = get_val(154, 7);
  _u.Dc12.W2    = get_val(161, 7);
  utc2jst(_Header.AtMo, _u.Dc12.BtD, _u.Dc12.BtH, _u.Dc12.BtM);
}
#endif // QZQSM_ENABLE_DC12

#ifdef QZQSM_ENABLE_DC14
//===============================================================
// Disaster Category Code 14
// JMA-DC Report (Marine)

#define DC14_REPORT \
  "災危通報(海上)(%s)\n\n" \
  "発表時刻：%d月%d日%d時%d分\n\n"

#define DC14_REPORT2 \
  "%s：%s\n"

// Warning Code (Region)
const char* QZQSM::dc14dw2str(int code)
{
  switch (code) {
  case  0: return "海上警報解除";
  case 10: return "海上着氷警報";
  case 11: return "海上濃霧警報";
  case 12: return "海上うねり警報";
  case 20: return "海上風警報";
  case 21: return "海上強風警報";
  case 22: return "海上暴風警報";
  case 23: return "海上台風警報";
  case 31: return "その他海上警報";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "海上警報(コード番号：%d)", code);
    return _undefMessage;
  }
}

// Marine Forecast Region
const char* QZQSM::dc14pl2str(int code)
{
  switch (code) {
  case 1000: return "日本海北部及びオホーツク南日本海北部";
  case 1010: return "サハリン東方海上";
  case 1020: return "サハリン西方海上";
  case 1030: return "網走沖";
  case 1040: return "宗谷海峡";
  case 1050: return "北海道西方海上";
  case 1100: return "北海道南方及び東方海上";
  case 1110: return "北海道東方海上";
  case 1120: return "釧路沖";
  case 1130: return "日高沖";
  case 1140: return "津軽海峡";
  case 1150: return "檜山津軽沖";
  case 2000: return "三陸沖";
  case 2010: return "三陸沖東部";
  case 2020: return "三陸沖西部";
  case 3000: return "関東海域";
  case 3010: return "関東海域北部";
  case 3020: return "関東海域南部";
  case 3100: return "日本海中部";
  case 3110: return "沿海州南部沖";
  case 3120: return "秋田沖";
  case 3130: return "佐渡沖";
  case 3140: return "能登沖";
  case 3200: return "東海海域";
  case 3210: return "東海海域東部";
  case 3220: return "東海海域西部";
  case 3230: return "東海海域南部";
  case 4000: return "四国沖及び瀬戸内海";
  case 4010: return "瀬戸内海";
  case 4020: return "四国沖北部";
  case 4030: return "四国沖南部";
  case 4100: return "日本海西部";
  case 4110: return "日本海北西部";
  case 4120: return "山陰沖東部及び若狭湾付近";
  case 4130: return "山陰沖西部";
  case 5000: return "対馬海峡";
  case 5100: return "九州西方海上";
  case 5110: return "済州島西海上";
  case 5120: return "長崎西海上";
  case 5130: return "女島南西海上";
  case 5200: return "九州南方海上及び日向灘";
  case 5210: return "日向灘";
  case 5220: return "鹿児島海域";
  case 5230: return "奄美海域";
  case 6000: return "沖縄海域";
  case 6010: return "東シナ海南部";
  case 6020: return "沖縄東方海上";
  case 6030: return "沖縄南方海上";
  case 10000: return "その他地方海上予報区";
  default:
    snprintf(_undefMessage, sizeof(_undefMessage),
             "地方海上予報区(コード番号：%04d)", code);
    return _undefMessage;
  }
}

int QZQSM::filter_dc14()
{
  // You can filter out the specific region or information.
  return 1;
}

void QZQSM::report_dc14()
{
  _len += snprintf(&_message[_len], sizeof(_message) - _len,
                   DC14_REPORT, it2str(_Header.It), _jstAtMo, _jstAtD, _jstAtH, _jstAtMi);
  int num;
  for (num = 0; num < 8; num++) {
    if (_u.Dc14.site[num].Pl != 0) {
      _len += snprintf(&_message[_len], sizeof(_message) - _len,
                       DC14_REPORT2, dc14dw2str(_u.Dc14.site[num].Dw), dc14pl2str(_u.Dc14.site[num].Pl));
    }
  }
}

void QZQSM::decode_dc14()
{
  int num;
  for (num = 0; num < 8; num++) {
    _u.Dc14.site[num].Dw = get_val(53 + (19 * num), 5);
    _u.Dc14.site[num].Pl = get_val(58 + (19 * num), 14);
  }
}
#endif // QZQSM_ENABLE_DC14

// Information Type
const char* QZQSM::it2str(int code)
{
  switch (code) {
  case 0: return "発表";
  case 1: return "訂正";
  case 2: return "取消";
  default: return "";
  }
}

int QZQSM::get_val(int startbit, int bitwidth)
{
  int val = 0;
  int index = (startbit + bitwidth - 1) / 8;
  int lsb = 7 - (startbit + bitwidth - 1) % 8;

  int i;
  for (i = 0; i < bitwidth; i++, lsb++) {
    if (lsb > 7) {
      index -= 1;
      lsb = 0;
    }
    val |= ((_buf[index] >> lsb) & 1) << i;
  }
  return val;
}

void QZQSM::utc2jst(int& month, int& day, int& hour, int& minute)
{
  uint32_t sec;
  struct tm tm;

  tm.tm_sec  = 0;
  tm.tm_min  = minute;
  tm.tm_hour = hour;
  tm.tm_mday = day;
  tm.tm_mon  = month - 1;
  tm.tm_year = _year - 1900;
  sec = mktime(&tm);

  sec += (9 * 60 * 60); // UTC -> JST

  gmtime_r(&sec, &tm);

  _year = tm.tm_year + 1900;
  month = tm.tm_mon + 1;
  day = tm.tm_mday;
  hour = tm.tm_hour;
  minute = tm.tm_min;
}

//===============================================================
// Public Functions
//===============================================================

QZQSM::QZQSM() : _len(0)
{
  memset(_buf, 0, sizeof(_buf));
  memset(_message, 0, sizeof(_message));
}

QZQSM::~QZQSM()
{
}

QZQSM::QZQSM(const QZQSM &val)
{
  memcpy(_message, val._message, sizeof(_message));
  _len = val._len;
}

QZQSM& QZQSM::operator = (const QZQSM &rhs)
{
  memcpy(_message, rhs._message, sizeof(_message));
  _len = rhs._len;
  return *this;
}

bool QZQSM::operator == (const QZQSM &rhs)
{
  return (0 == strncmp(_message, rhs._message, sizeof(_message)));
}

bool QZQSM::operator != (const QZQSM &rhs)
{
  return (0 != strncmp(_message, rhs._message, sizeof(_message)));
}

void QZQSM::Decode(const char *nmea)
{
  uint8_t data[32];
  String str(nmea);

  int i;
  int n = 0;
  str.setCharAt(73,'0');
  for (i = 10; i < 74; i += 2) {
    String ch = str.substring(i, i + 2);
    data[n++] = strtoul(ch.c_str(), NULL, 16) & 0xff;
  }
  Decode(data);
}

void QZQSM::Decode(const uint8_t *data)
{
  memset(_buf, 0, sizeof(_buf));
  memset(_message, 0, sizeof(_message));
  _len = 0;

  memcpy(_buf, data, sizeof(_buf));

  _Header.PAB  = get_val( 0, 8);
  _Header.MT   = get_val( 8, 6);
  _Header.Rc   = get_val(14, 3);
  _Header.Dc   = get_val(17, 4);
  _Header.AtMo = get_val(21, 4);
  _Header.AtD  = get_val(25, 5);
  _Header.AtH  = get_val(30, 5);
  _Header.AtMi = get_val(35, 6);
  _Header.It   = get_val(41, 2);

  _jstAtMo = _Header.AtMo;
  _jstAtD  = _Header.AtD;
  _jstAtH  = _Header.AtH;
  _jstAtMi = _Header.AtMi;
  utc2jst(_jstAtMo, _jstAtD, _jstAtH, _jstAtMi);

  if (0 == (_category & (1 << _Header.Dc))) {
    return;
  }

  switch (_Header.Dc) {
#ifdef QZQSM_ENABLE_DC1
  case 1:
    decode_dc1();
    if (filter_dc1())
      report_dc1();
    break;
#endif
#ifdef QZQSM_ENABLE_DC2
  case 2:
    decode_dc2();
    if (filter_dc2())
      report_dc2();
    break;
#endif
#ifdef QZQSM_ENABLE_DC3
  case 3:
    decode_dc3();
    if (filter_dc3())
      report_dc3();
    break;
#endif
#ifdef QZQSM_ENABLE_DC4
  case 4:
    decode_dc4();
    if (filter_dc4())
      report_dc4();
    break;
#endif
#ifdef QZQSM_ENABLE_DC5
  case 5:
    decode_dc5();
    if (filter_dc5())
      report_dc5();
    break;
#endif
#ifdef QZQSM_ENABLE_DC6
  case 6:
    decode_dc6();
    if (filter_dc6())
      report_dc6();
    break;
#endif
#ifdef QZQSM_ENABLE_DC8
  case 8:
    decode_dc8();
    if (filter_dc8())
      report_dc8();
    break;
#endif
#ifdef QZQSM_ENABLE_DC9
  case 9:
    decode_dc9();
    if (filter_dc9())
      report_dc9();
    break;
#endif
#ifdef QZQSM_ENABLE_DC10
  case 10:
    decode_dc10();
    if (filter_dc10())
      report_dc10();
    break;
#endif
#ifdef QZQSM_ENABLE_DC11
  case 11:
    decode_dc11();
    if (filter_dc11())
      report_dc11();
    break;
#endif
#ifdef QZQSM_ENABLE_DC12
  case 12:
    decode_dc12();
    if (filter_dc12())
      report_dc12();
    break;
#endif
#ifdef QZQSM_ENABLE_DC14
  case 14:
    decode_dc14();
    if (filter_dc14())
      report_dc14();
    break;
#endif
  default:
    printf("Not Supported Category = %d\n", _Header.Dc);
    break;
  }
}

const char* QZQSM::GetReport()
{
  //printf("*** _len=%d\n", _len);
  return _message;
}

uint16_t QZQSM::_year = 2019;

void QZQSM::SetYear(int year)
{
  _year = year;
}

uint32_t QZQSM::_category = 0xffffffff;

void QZQSM::EnableCategory(int category)
{
  _category |= (1 << category);
}

void QZQSM::DisableCategory(int category)
{
  _category &= ~(1 << category);
}
