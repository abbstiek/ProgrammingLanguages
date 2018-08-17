#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 5 "calc.y"
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  
  FILE *outfile;
  int yyline = 1; 
  int yycolumn = 1;
  char string_table[20000];
  extern int yyleng;
  extern char* yytext;

  /*used from trans.y example//*/
  void print_header(void);
  void print_end(void);
  void yyerror(const char *str);
  int yywrap(void);
  void print_exp(const char *s);
  
  void error(const char * str);

  
  struct symbolTable
  {
	char name[10];
	int init;
	int decl;
	int value;
  };
  struct symbolTable table[20];
#line 36 "calc.y"
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
#line 66 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    9,    8,    1,    1,    1,    3,    3,    4,    2,
    2,    6,    6,    6,    6,    7,    7,    7,    5,    5,
    5,
};
static const short yylen[] = {                            2,
    4,    0,    4,    3,    2,    1,    1,    3,    2,    1,
    3,    3,    3,    2,    1,    3,    3,    1,    1,    1,
    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    2,    1,    0,    0,    0,    0,
    7,    0,    6,   20,    0,    0,   19,   18,    0,    0,
   10,    0,    0,    3,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    8,   21,    0,    0,   17,   16,   11,
};
static const short yydgoto[] = {                          2,
   11,   22,   12,   13,   18,   19,   20,    6,    7,
};
static const short yysindex[] = {                      -255,
 -257,    0, -235, -231,    0,    0, -252, -258, -241, -228,
    0, -260,    0,    0, -258, -256,    0,    0, -264, -250,
    0, -232, -258,    0, -252, -217, -250, -256, -256, -256,
 -256, -227, -264,    0,    0, -250, -250,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -242, -243,
    0, -210,    0,    0,    0,    0, -236,    0,    0,    0,
    0,    0, -206,    0,    0, -229, -222,    0,    0,    0,
};
static const short yygindex[] = {                         0,
   27,    0,    0,    0,   28,   25,  -15,    0,    0,
};
#define YYTABLESIZE 60
static const short yytable[] = {                         14,
   27,   14,   24,   28,    1,   25,    8,   29,   15,   16,
   15,    9,   36,   37,   30,   17,    3,   17,   31,   15,
    5,   10,   15,    5,   15,    4,   14,   15,   15,   14,
    5,   14,   21,   13,   14,   14,   13,   32,   13,   26,
   12,   13,   13,   12,   23,   12,   40,   33,   12,   12,
   28,   34,    9,   35,   29,    9,    4,   38,   39,    4,
};
static const short yycheck[] = {                        258,
   16,  258,  263,  268,  260,  266,  259,  272,  267,  268,
  267,  264,   28,   29,  265,  274,  274,  274,  269,  263,
  263,  274,  266,  266,  268,  261,  263,  271,  272,  266,
  262,  268,  274,  263,  271,  272,  266,  270,  268,   15,
  263,  271,  272,  266,  273,  268,  274,   23,  271,  272,
  268,   25,  263,  271,  272,  266,  263,   30,   31,  266,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 274
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"EOFnumber","ICONSTnumber",
"PRINTnumber","PROGRAMnumber","ISnumber","BEGINnumber","ENDnumber","VARnumber",
"DIVnumber","SEMInumber","LPARENnumber","MINUSnumber","TIMESnumber",
"COMMAnumber","RPARENnumber","PLUSnumber","EQnumber","IDnumber",
};
static const char *yyrule[] = {
"$accept : Program",
"Program : PROGRAMnumber IDnumber ISnumber compound",
"$$1 :",
"compound : BEGINnumber $$1 statement_list ENDnumber",
"statement : IDnumber EQnumber exp",
"statement : PRINTnumber exp",
"statement : declaration",
"statement_list : statement",
"statement_list : statement_list SEMInumber statement",
"declaration : VARnumber id_list",
"id_list : IDnumber",
"id_list : id_list COMMAnumber IDnumber",
"exp : exp PLUSnumber term",
"exp : exp MINUSnumber term",
"exp : MINUSnumber term",
"exp : term",
"term : term TIMESnumber factor",
"term : term DIVnumber factor",
"term : factor",
"factor : IDnumber",
"factor : ICONSTnumber",
"factor : LPARENnumber exp RPARENnumber",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 277 "calc.y"


void print_header()
{
	if ((outfile = fopen("mya.cpp", "w")) == NULL) {
		printf("Can't open file mya.cpp.\n");
		exit(0);
	}
	fprintf(outfile, "#include <iostream>\n");
	fprintf(outfile, "#include <stdio.h>\n");
	fprintf(outfile, "using namespace std;\n");
	fprintf(outfile, "\nint main()\n");
	fprintf(outfile, "{\n");
}

void print_end()
{
	fprintf(outfile, "}\n");
	fclose(outfile);
}
void error(const char * str)
{
	printf("%s %d.\n", str, yyline);
}
void yyerror(const char *str)
{    
	printf("line %d: %s\n", yyline , str);
}
int main()
{
	if (!yyparse())
	{
		//printf("accept\n");
		return 0;
	}
	else 
	{
		//printf("reject\n");
		return 1;
	}
}    
int yywrap()
	{return 1;}
void print_exp(const char *s)
{fprintf(outfile, "cout << %s << endl;", s);}





#line 299 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 79 "calc.y"
	{}
break;
case 2:
#line 83 "calc.y"
	{
					print_header();
				}
break;
case 3:
#line 88 "calc.y"
	{
					print_end();
				}
break;
case 4:
#line 94 "calc.y"
	{
					int x = 0;	
					for(; x < 20; x++)
					{
						if((table[x].decl == 1) && (!strcmp(table[x].name, string_table + yystack.l_mark[-2].sv)))
						{
							table[x].value = yystack.l_mark[0].attr.v;
							table[x].init = 1;
							break;
						}
					}
					if(x == 20)
					{
						error("Referencing an undeclared variable on line");
						return 0;
					}
					
					sprintf(yyval.attr.s, "%s = %s;", table[x].name, yystack.l_mark[0].attr.s);
				}
break;
case 5:
#line 115 "calc.y"
	{
				print_exp(yystack.l_mark[0].attr.s);
				printf("%d\n", yystack.l_mark[0].attr.v);
			}
break;
case 6:
#line 120 "calc.y"
	{
				sprintf(yyval.attr.s, "%s;", yystack.l_mark[0].attr.s);
			}
break;
case 7:
#line 126 "calc.y"
	{
				fprintf(outfile, "%s\n", yystack.l_mark[0].attr.s);
			}
break;
case 8:
#line 130 "calc.y"
	{
				fprintf(outfile, "%s\n", yystack.l_mark[0].attr.s);	
			}
break;
case 9:
#line 136 "calc.y"
	{
				sprintf(yyval.attr.s, "int %s", yystack.l_mark[0].attr.s); 	
			}
break;
case 10:
#line 142 "calc.y"
	{
				yyval.attr.v = yystack.l_mark[0].sv;
				
				int x = 0;
				for(; x < 20; x++)
				{
					if(!strcmp(table[x].name, string_table + yyval.attr.v))
					{
						error("Duplicate declaration on line");
						return 0;
					}
				}
				for(x = 0; x < 20; x++)
				{
					if(table[x].decl != 1)
					{
						strcpy(table[x].name, string_table + yyval.attr.v);
						table[x].decl = 1;
						break;
					}
				}
				sprintf(yyval.attr.s, "%s", table[x].name);	
			}
break;
case 11:
#line 166 "calc.y"
	{
				yyval.attr.v = yystack.l_mark[0].sv;
				
				int x = 0;
				for(; x < 20; x++)
				{
					if (!strcmp(table[x].name, string_table + yyval.attr.v))
					{
						error("Duplicate declaration on line");
					}
				}
				for(x = 0; x < 20; x++)
				{				
					if (table[x].decl == 0)
					{
						strcpy(table[x].name, string_table + yyval.attr.v);
						table[x].decl = 1;
						break;
					}
				}
				sprintf(yyval.attr.s, "%s, %s", yystack.l_mark[-2].attr.s, table[x].name);
			}
break;
case 12:
#line 190 "calc.y"
	{
				yyval.attr.v = yystack.l_mark[-2].attr.v + yystack.l_mark[0].attr.v;
				sprintf(yyval.attr.s, "%s + %s", yystack.l_mark[-2].attr.s, yystack.l_mark[0].attr.s);
			}
break;
case 13:
#line 195 "calc.y"
	{
				yyval.attr.v = yystack.l_mark[-2].attr.v - yystack.l_mark[0].attr.v;
				sprintf(yyval.attr.s, "%s - %s", yystack.l_mark[-2].attr.s, yystack.l_mark[0].attr.s);
			}
break;
case 14:
#line 200 "calc.y"
	{
				yyval.attr.v = (-1) * yystack.l_mark[0].attr.v;
				sprintf(yyval.attr.s, "-%s", yystack.l_mark[0].attr.s);				
			}
break;
case 15:
#line 205 "calc.y"
	{
				yyval.attr.v = yystack.l_mark[0].attr.v;
				sprintf(yyval.attr.s, "%s", yystack.l_mark[0].attr.s);
			}
break;
case 16:
#line 211 "calc.y"
	{
				yyval.attr.v = yystack.l_mark[-2].attr.v * yystack.l_mark[0].attr.v;
				sprintf(yyval.attr.s, "%s * %s", yystack.l_mark[-2].attr.s, yystack.l_mark[0].attr.s);
			}
break;
case 17:
#line 216 "calc.y"
	{	
				if (yystack.l_mark[0].attr.v == 0)
				{
					error("Dividing by zero on line");
					return 0;
				}
				else
				{
					yyval.attr.v = yystack.l_mark[-2].attr.v / yystack.l_mark[0].attr.v;
					sprintf(yyval.attr.s, "%s / %s", yystack.l_mark[-2].attr.s, yystack.l_mark[0].attr.s);
				}	
			}
break;
case 18:
#line 229 "calc.y"
	{
				yyval.attr.v = yystack.l_mark[0].attr.v;
				sprintf(yyval.attr.s, "%s", yystack.l_mark[0].attr.s);
			}
break;
case 19:
#line 236 "calc.y"
	{
				yyval.attr.v = yystack.l_mark[0].sv;
				
				int x = 0;
				for(; x < 20; x++)
				{			
					if ((table[x].decl == 1) && (!strcmp(table[x].name, string_table + yystack.l_mark[0].sv)))
					{
						if(table[x].init == 0)
						{
							error("Referencing an uninitialized variable on line");
							return 0;
						}
						else
						{
							yyval.attr.v = table[x].value;
							break;
						}
					}
				}
				if(x == 20)
				{
					error("Referencing an undeclared variable on line");
					return 0;
				}
				
				sprintf(yyval.attr.s, "%s", table[x].name);
			}
break;
case 20:
#line 265 "calc.y"
	{
				yyval.attr.v = yystack.l_mark[0].sv;
				sprintf(yyval.attr.s, "%d", yystack.l_mark[0].sv);
			}
break;
case 21:
#line 270 "calc.y"
	{
				yyval.attr.v = yystack.l_mark[-1].attr.v;
				sprintf(yyval.attr.s, "(%s)", yystack.l_mark[-1].attr.s);
			}
break;
#line 727 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
