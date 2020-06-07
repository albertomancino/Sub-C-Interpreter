/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     CHAR = 259,
     IDENTIFIER = 260,
     NUMBER = 261,
     EQUAL = 262,
     END_COMMA = 263,
     OPEN_ROUND = 264,
     CLOSED_ROUND = 265,
     OPEN_SQUARED = 266,
     CLOSED_SQUARED = 267,
     OPEN_BRACKET = 268,
     CLOSED_BRACKET = 269,
     RETURN = 270,
     STRING = 271,
     CH = 272,
     IF = 273,
     ELSE = 274,
     WHILE = 275,
     INC = 276,
     DEC = 277,
     AMP = 278,
     COMMA = 279,
     DF = 280,
     ET = 281,
     LT = 282,
     GT = 283,
     OR = 284,
     AND = 285,
     MINUS = 286,
     PLUS = 287,
     MODULO = 288,
     DIVIDE = 289,
     STAR = 290
   };
#endif
/* Tokens.  */
#define INT 258
#define CHAR 259
#define IDENTIFIER 260
#define NUMBER 261
#define EQUAL 262
#define END_COMMA 263
#define OPEN_ROUND 264
#define CLOSED_ROUND 265
#define OPEN_SQUARED 266
#define CLOSED_SQUARED 267
#define OPEN_BRACKET 268
#define CLOSED_BRACKET 269
#define RETURN 270
#define STRING 271
#define CH 272
#define IF 273
#define ELSE 274
#define WHILE 275
#define INC 276
#define DEC 277
#define AMP 278
#define COMMA 279
#define DF 280
#define ET 281
#define LT 282
#define GT 283
#define OR 284
#define AND 285
#define MINUS 286
#define PLUS 287
#define MODULO 288
#define DIVIDE 289
#define STAR 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 33 "parser.y"
{
    long intValue;
    char * string;
    char charValue;
    struct TreeNode *node;
}
/* Line 1529 of yacc.c.  */
#line 126 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

