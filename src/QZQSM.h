#ifndef __QZQSM_H__
#define __QZQSM_H__

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

#include <Arduino.h>
#include <stdint.h>

class QZQSM {
public:
  QZQSM();
  ~QZQSM();

  QZQSM(const QZQSM &val);
  QZQSM& operator = (const QZQSM &rhs);
  bool operator == (const QZQSM &rhs);
  bool operator != (const QZQSM &rhs);

  void Decode(const char *nmea);
  void Decode(const uint8_t *report);

  const char* GetReport();

  void SetYear(int year);

  void EnableCategory(int category);
  void DisableCategory(int category);

private:
  uint8_t _buf[32];
  char _message[2048];
  int _len;
  char _undefMessage[64];

  static uint16_t _year;

  static uint32_t _category;

  int _jstAtMo;
  int _jstAtD;
  int _jstAtH;
  int _jstAtMi;

  struct {
    int PAB;
    int MT;
    int Rc;
    int Dc;
    int AtMo;
    int AtD;
    int AtH;
    int AtMi;
    int It;
  } _Header;

  union {
    struct {
      int Co[3];
      int OtD;
      int OtH;
      int OtM;
      int De;
      int Ma;
      int Ep;
      int Ll;
      int Ul;
      int Pl[3];
    } Dc1;

    struct {
      int Co[3];
      int OtD;
      int OtH;
      int OtM;
      int De;
      int Ma;
      int Ep;
      int LatNs;
      int LatD;
      int LatM;
      int LatS;
      int LonEw;
      int LonD;
      int LonM;
      int LonS;
    } Dc2;

    struct {
      int OtD;
      int OtH;
      int OtM;
      struct {
        int Es;
        int Pl;
      } site[16];
    } Dc3;

    struct {
      char Te[18];
      int Pn;
      int Pm;
    } Dc4;

    struct {
      int Co[3];
      int Dw;
      struct {
        int TaD;
        int TaH;
        int TaM;
        int Th;
        int Pl;
      } site[5];
    } Dc5;

    struct {
      int Tp;
      struct {
        int TaD;
        int TaH;
        int TaM;
        int Th;
        int Pl;
      } site[5];
    } Dc6;

    struct {
      int TdD;
      int TdH;
      int TdM;
      int Dw;
      int Vo;
      int Pl[5];
    } Dc8;

    struct {
      int TdD;
      int TdH;
      int TdM;
      int Dw1;
      int Vo;
      struct {
        int Ho;
        int Dw2;
        int Pl;
      } site[4];
    } Dc9;

    struct {
      int Ar;
      struct {
        int Ww;
        int Pl;
      } site[6];
    } Dc10;

    struct {
      struct {
        int Lv;
        uint64_t Pl;
      } site[3];
    } Dc11;

    struct {
      int BtD;
      int BtH;
      int BtM;
      int Dt;
      int Du;
      int Tn;
      int Sr;
      int Ic;
      int LatNs;
      int LatD;
      int LatM;
      int LatS;
      int LonEw;
      int LonD;
      int LonM;
      int LonS;
      int Pr;
      int W1;
      int W2;
    } Dc12;

    struct {
      struct {
        int Dw;
        int Pl;
      } site[8];
    } Dc14;
  } _u;

  int get_val(int startbit, int bitwidth);
  void decode_dc1();
  void decode_dc2();
  void decode_dc3();
  void decode_dc4();
  void decode_dc5();
  void decode_dc6();
  void decode_dc8();
  void decode_dc9();
  void decode_dc10();
  void decode_dc11();
  void decode_dc12();
  void decode_dc14();
  int filter_dc1();
  int filter_dc2();
  int filter_dc3();
  int filter_dc4();
  int filter_dc5();
  int filter_dc6();
  int filter_dc8();
  int filter_dc9();
  int filter_dc10();
  int filter_dc11();
  int filter_dc12();
  int filter_dc14();
  void report_dc1();
  void report_dc2();
  void report_dc3();
  void report_dc4();
  void report_dc5();
  void report_dc6();
  void report_dc8();
  void report_dc9();
  void report_dc10();
  void report_dc11();
  void report_dc12();
  void report_dc14();
  const char* it2str(int code);
  const char* dc1co2str(int code);
  const char* dc1de2str(int de);
  const char* dc1ma2str(int ma);
  const char* dc1ep2str(int code);
  const char* dc1si2str(int code);
  const char* dc1pl2str(int code);
  const char* dc3es2str(int code);
  const char* dc3pl2str(int code);
  const char* dc5dw2str(int code);
  const char* dc5ta2str(int h, int m);
  const char* dc5th2str(int code);
  const char* dc5pl2str(int code);
  const char* dc6tp2str(int code);
  const char* dc6ta2str(int h, int m);
  const char* dc6th2str(int code);
  const char* dc6pl2str(int code);
  const char* dc8td2str(int d, int h, int m);
  const char* dc8dw2str(int code);
  const char* dc8vo2str(int code);
  const char* dc8pl2str(int code);
  const char* dc9dw2str(int code);
  const char* dc10ar2str(int code);
  const char* dc10ww2str(int code);
  const char* dc10pl2str(int code);
  const char* dc11lv2str(int code);
  const char* dc11pl2str(uint64_t code);
  const char* dc12dt2str(int code);
  const char* dc12sr2str(int code);
  const char* dc12ic2str(int code);
  const char* dc12w2str1(int w);
  const char* dc12w2str2(int w);
  const char* dc14dw2str(int code);
  const char* dc14pl2str(int code);

  void utc2jst(int& month, int& day, int& hour, int& minute);
};

#endif
