int yylex();
int yyerror();
int yyparse();
char* yytext; // utile se si vuole accedere al valore di yytext
void copyID();
void copyNUM();
void copyString();
void copyChar();
void copyEscape();
