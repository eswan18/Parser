#include <string.h>
#include "token.h"
#include "decl.h"
#include "parser.tab.h"

extern FILE *yyin;
extern char *yytext;
extern int yyparse();
extern struct decl *parser_result;
extern int yylex();
extern void convertString(char *);

int scan(char *filename);
int parse(char *filename);

int main(int argc, char *argv[]) {
        char *filename;
	char *option;
        if (argc >= 3) {
                option = argv[1];
		filename = argv[2];
        } else {
		fprintf(stderr,"error: provide both an option (e.g. -scan, -parse) and a filename when invoking cminor.\nfor example: './cminor -parse myfile.cminor'\n");
		return(1);
        }
	
	if (strcmp(option,"-scan") == 0) {
		scan(filename);
	} else if (strcmp(option,"-parse") == 0) {
		return parse(filename);
	}
	
        return 0;
}

int scan(char *filename) {
        yyin  = fopen(filename,"r");
	if (!yyin) {
		fprintf(stderr,"scan error: unable to open %s\n",filename);
		exit(1);
	}
        while(yyin) {
        	int t = yylex();
                if (!t)
                        break;
                printf("%s", token_string(t));
                if ( t == TOKEN_STRING_LITERAL || t == TOKEN_CHAR_LITERAL) {
                        char string[600];
                        strcpy(string,yytext);
                        convertString(string);
                        printf(" %s", string);
                }
                printf("\n");
        }
        fclose(yyin);
	return 0;
}

int parse(char *filename) {
	yyin = fopen(filename,"r");
	if (!yyin) {
		fprintf(stderr,"unable to open %s\n",filename);
		exit(1);
	}
	if (yyparse() == 0) {
		decl_print(parser_result,0);
		return 0;
	} else {
		printf("Parse Failed!\n");
		return 1;
	}
	/*while(yyin) {
		token_t t = yylex();
		printf("one\n");
		if(!t)
			break;
		if(yyparse() == 0){
			return 0;
		} else {
			printf("Parse Failed!\n");
			return 1;
		}
		return 0;
	}*/
	fclose(yyin);
	return 1;
}
