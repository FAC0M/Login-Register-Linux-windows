/*** Definition Section has one variable
%{
int count = 0;
%}

/*** Rule Section has three rules, first rule 
%%
[A-Z] {printf("%s capital letter\n", yytext);
       count++;}
.     {printf("%s not a capital letter\n", yytext);}
\n    {return 0;}
%%

int yywrap(){}
int main(){

    yylex();
    printf("\nNumber of Capital letters " 
        "in the given input - %d\n", count);

return 0;
}

