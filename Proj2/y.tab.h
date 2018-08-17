#define EOFnumber 257
#define ICONSTnumber 258
#define PRINTnumber 259
#define PROGRAMnumber 260
#define ISnumber 261
#define BEGINnumber 262
#define ENDnumber 263
#define VARnumber 264
#define DIVnumber 265
#define SEMInumber 266
#define LPARENnumber 267
#define MINUSnumber 268
#define TIMESnumber 269
#define COMMAnumber 270
#define RPARENnumber 271
#define PLUSnumber 272
#define EQnumber 273
#define IDnumber 274
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union 
{
  int sv;
  struct 
  {
	int v;
    char s[1000];
  } attr;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
