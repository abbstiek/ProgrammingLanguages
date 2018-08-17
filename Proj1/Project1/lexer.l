%{

#include <stdio.h>
#include <stdlib.h>

extern int put_string(char *str, int len);
char **string_table;

int yylval=1;
int yycolumn=1;
int yyline = 1;
int table_i;
%}

intg		[a-zA-Z_][a-zA-Z_0-9]*

%%

\n					{yyline++; yycolumn= 1;}

\;					 {yycolumn += yyleng; return SEMInumber;}

\( 					 {yycolumn += yyleng; return LPARENnumber;}

[0-9]+					{
						yycolumn += yyleng; 
						yylval = atoi(yytext);
						return (ICONSTnumber);
						}

begin				 {yycolumn += yyleng; return BEGINnumber;}

program				 {yycolumn += yyleng; return PROGRAMnumber;}

\-					 {yycolumn += yyleng; return MINUSnumber;}

\* 					 {yycolumn += yyleng; return TIMESnumber;}

var					 {yycolumn += yyleng; return VARnumber;}

<<EOF>> 			 {yycolumn += yyleng; return EOFnumber;}

\, 					 {yycolumn += yyleng; return COMMAnumber;}

\)					 {yycolumn += yyleng; return RPARENnumber;}

intg				{
					yycolumn += yyleng; 
					yylval = put_string(yytext, yyleng);
					return (IDnumber); 
					}

end					 {yycolumn += yyleng; return ENDnumber;}
 
is					 {yycolumn += yyleng; return ISnumber;}

\+					 {yycolumn += yyleng; return PLUSnumber;}

div					 {yycolumn += yyleng; return DIVnumber;}

print				 {yycolumn += yyleng; return PRINTnumber;}

\=					 {yycolumn += yyleng; return EQnumber;}

[ \t]

.					{printf("Invalid character: %s. Line %d, column %d\n", yytext, yyline, yycolumn);
					 yytext, (yyline + 1), yycolumn;}
	

"(*"		{
            char c1; 
            char c2 = input();

            if(c2 <= 0) {
              printf("Unfinished comment");
            }
            else {
              c1 = c2; 
              c2 = input();

              while(((c1!='*') || (c2 != ')')) && (c2  > 0)) {
                c1 = c2; 
                c2 = input();
              }

              if (c2 <= 0) {
                printf("unended comment, line = %d, column = %d\n",
                (yyline + 2), (yycolumn - yyleng) + 2
                );
              }
			  }
		}

%%


int put_string (char *str, int len)
{
  string_table[table_i++] = str;

  return (table_i - 1);
}

int yywrap()
{
	return 1;
}
