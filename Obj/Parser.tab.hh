/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
     TOKEN_BEGIN = 258,
     TOKEN_END = 259,
     SYSCALL = 260,
     PRINTLN = 261,
     PRINTNL = 262,
     WHILE = 263,
     BREAK = 264,
     FOR = 265,
     CONTINUE = 266,
     ENDL = 267,
     IF = 268,
     ELSE = 269,
     RETURN = 270,
     TOKEN_READ = 271,
     PONY = 272,
     VAR = 273,
     SQRT = 274,
     CBRT = 275,
     TYPE_BYTE = 276,
     COLON = 277,
     TYPE_SHORT = 278,
     TERNARY = 279,
     TYPE_INT = 280,
     TYPE_LONG = 281,
     TYPE_FLOAT = 282,
     OR_OP = 283,
     EQUAL = 284,
     ADD_EQU = 285,
     MUL_EQU = 286,
     SUB_EQU = 287,
     DIV_EQU = 288,
     R_EQU = 289,
     L_EQU = 290,
     MOD_EQU = 291,
     OR_EQU = 292,
     XOR_EQU = 293,
     AND_EQU = 294,
     R_OP = 295,
     L_OP = 296,
     TYPE_STRING = 297,
     AND_OP = 298,
     GEQU = 299,
     LEQU = 300,
     DEC = 301,
     INC = 302,
     LTHAN = 303,
     TRUE = 304,
     FALSE = 305,
     GTHAN = 306,
     EQ_OP = 307,
     TO_STRING = 308,
     TO_INT = 309,
     SYSTEM = 310,
     NE_OP = 311,
     LPAREN = 312,
     RPAREN = 313,
     COMMA = 314,
     CONCAT = 315,
     SEMICOLON = 316,
     ELLIPSIS = 317,
     WS = 318,
     SUB = 319,
     ADD = 320,
     POW = 321,
     AND = 322,
     XOR = 323,
     OR = 324,
     MOD = 325,
     DIV = 326,
     MUL = 327,
     INT = 328,
     FLOAT = 329,
     STRING = 330,
     STRING_LITERAL = 331,
     TOKEN_ID = 332
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 21 "Interface/Parser.yy"

	int ival;
	float fval;
	char *sval;
	struct tagSExpression *exp;



/* Line 1685 of yacc.c  */
#line 137 "Obj/Parser.tab.hh"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


