/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Interface/Parser.yy"

#include <cstdio>
#include <iostream>
#include "PonyCore.h"
#include "PonyInt.h"
#include "Expression.hpp"
#include <cmath>
#define PONY_VERSION "Pony Version 0.6"

using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int line_number;
void yyerror(const char *);
int yywrap();


/* Line 189 of yacc.c  */
#line 93 "Obj/Parser.tab.cc"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 21 "Interface/Parser.yy"

	int ival;
	float fval;
	char *sval;
	struct tagSExpression *exp;



/* Line 214 of yacc.c  */
#line 215 "Obj/Parser.tab.cc"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 227 "Obj/Parser.tab.cc"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  78
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   715

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNRULES -- Number of states.  */
#define YYNSTATES  219

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   332

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    79,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    78,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      20,    22,    25,    27,    29,    33,    35,    37,    39,    43,
      47,    51,    55,    57,    61,    65,    69,    73,    77,    81,
      85,    89,    93,    97,    99,   105,   107,   111,   113,   117,
     119,   123,   125,   129,   131,   135,   137,   141,   145,   147,
     151,   155,   159,   163,   165,   169,   173,   175,   179,   183,
     186,   188,   192,   196,   200,   204,   206,   209,   212,   217,
     222,   227,   232,   235,   240,   245,   250,   255,   260,   265,
     270,   272,   275,   278,   284,   292,   298,   300,   303,   307,
     311,   316,   319,   322,   325,   329,   331,   334,   340,   345,
     347,   349,   351,   353,   355,   357,   361,   363,   366,   368,
     372,   374,   376,   378,   380,   382,   384,   386,   388,   393,
     397
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      81,     0,    -1,    83,    -1,    84,    -1,   102,    -1,   106,
      -1,   103,    -1,   105,    -1,    82,    -1,    83,    82,    -1,
      61,    -1,    86,    61,    -1,   115,    -1,   114,    -1,    57,
      86,    58,    -1,    88,    -1,    87,    -1,   115,    -1,   115,
      60,   115,    -1,   115,    60,    86,    -1,    86,    60,   115,
      -1,    87,    60,    87,    -1,    89,    -1,   100,    52,    88,
      -1,   100,    56,    88,    -1,   100,    31,    88,    -1,   100,
      30,    88,    -1,   100,    32,    88,    -1,   100,    33,    88,
      -1,   100,    39,    88,    -1,   100,    37,    88,    -1,   100,
      35,    88,    -1,   100,    34,    88,    -1,    90,    -1,    90,
      24,    86,    22,    86,    -1,    91,    -1,    90,    28,    91,
      -1,    92,    -1,    91,    43,    92,    -1,    93,    -1,    92,
      69,    93,    -1,    94,    -1,    93,    68,    94,    -1,    95,
      -1,    94,    67,    95,    -1,    96,    -1,    95,    52,    96,
      -1,    95,    56,    96,    -1,    97,    -1,    96,    48,    97,
      -1,    96,    51,    97,    -1,    96,    45,    97,    -1,    96,
      44,    97,    -1,    98,    -1,    97,    41,    98,    -1,    97,
      40,    98,    -1,    99,    -1,    98,    65,    99,    -1,    98,
      64,    99,    -1,    98,    99,    -1,   100,    -1,    99,    72,
     100,    -1,    99,    71,   100,    -1,    99,    70,   100,    -1,
      99,    66,   100,    -1,   101,    -1,    47,   100,    -1,    46,
     100,    -1,    54,    57,    86,    58,    -1,    19,    57,    86,
      58,    -1,    20,    57,    86,    58,    -1,     6,    57,    86,
      58,    -1,     6,    87,    -1,     7,    57,    86,    58,    -1,
       5,    57,    86,    58,    -1,    16,    57,    25,    58,    -1,
      16,    57,    21,    58,    -1,    16,    57,    23,    58,    -1,
      16,    57,    26,    58,    -1,    16,    57,    26,    58,    -1,
      85,    -1,   101,    47,    -1,   101,    46,    -1,    13,    57,
      86,    58,   104,    -1,    13,    57,    86,    58,   104,    14,
     104,    -1,     8,    57,    86,    58,   104,    -1,    82,    -1,
       3,     4,    -1,     3,    83,     4,    -1,     3,   110,     4,
      -1,     3,   110,    83,     4,    -1,    11,    61,    -1,     9,
      61,    -1,   107,    61,    -1,   107,   113,    61,    -1,   108,
      -1,   108,   107,    -1,    18,    48,   107,    51,    77,    -1,
      18,    77,    29,    86,    -1,    25,    -1,    23,    -1,    26,
      -1,    21,    -1,    42,    -1,    77,    -1,    57,   109,    58,
      -1,   106,    -1,   110,   106,    -1,   109,    -1,   109,    52,
     112,    -1,    88,    -1,   111,    -1,    73,    -1,    49,    -1,
      50,    -1,    74,    -1,    75,    -1,    76,    -1,    53,    57,
      86,    58,    -1,    16,    57,    58,    -1,    16,    57,    42,
      58,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   109,   109,   114,   118,   119,   120,   121,   125,   126,
     130,   134,   141,   142,   143,   147,   148,   152,   153,   154,
     155,   156,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   178,   179,   190,   191,   195,   196,   200,
     201,   205,   206,   210,   211,   215,   216,   217,   220,   221,
     222,   223,   224,   228,   229,   230,   234,   235,   236,   237,
     241,   242,   243,   244,   245,   249,   250,   251,   252,   256,
     260,   264,   270,   276,   282,   287,   291,   295,   299,   303,
     317,   318,   319,   323,   330,   334,   338,   339,   340,   341,
     342,   346,   347,   352,   353,   357,   358,   359,   360,   364,
     365,   366,   367,   368,   372,   373,   377,   378,   386,   387,
     391,   399,   403,   404,   405,   406,   410,   411,   412,   416,
     420
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_BEGIN", "TOKEN_END", "SYSCALL",
  "PRINTLN", "PRINTNL", "WHILE", "BREAK", "FOR", "CONTINUE", "ENDL", "IF",
  "ELSE", "RETURN", "TOKEN_READ", "PONY", "VAR", "SQRT", "CBRT",
  "TYPE_BYTE", "COLON", "TYPE_SHORT", "TERNARY", "TYPE_INT", "TYPE_LONG",
  "TYPE_FLOAT", "OR_OP", "EQUAL", "ADD_EQU", "MUL_EQU", "SUB_EQU",
  "DIV_EQU", "R_EQU", "L_EQU", "MOD_EQU", "OR_EQU", "XOR_EQU", "AND_EQU",
  "R_OP", "L_OP", "TYPE_STRING", "AND_OP", "GEQU", "LEQU", "DEC", "INC",
  "LTHAN", "TRUE", "FALSE", "GTHAN", "EQ_OP", "TO_STRING", "TO_INT",
  "SYSTEM", "NE_OP", "LPAREN", "RPAREN", "COMMA", "CONCAT", "SEMICOLON",
  "ELLIPSIS", "WS", "SUB", "ADD", "POW", "AND", "XOR", "OR", "MOD", "DIV",
  "MUL", "INT", "FLOAT", "STRING", "STRING_LITERAL", "TOKEN_ID", "'~'",
  "'!'", "$accept", "pony", "statement", "statement_list",
  "expression_statement", "primary_expression", "expression",
  "concat_expression", "assignment_expression", "conditional_expression",
  "logical_or_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "if_statement", "loop_statement",
  "compound_statement", "jump_statement", "declaration",
  "declaration_specifiers", "type_specifier", "direct_declarator",
  "declaration_list", "init_declarator", "initializer",
  "init_declarator_list", "number", "string", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   126,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    80,    81,    82,    82,    82,    82,    82,    83,    83,
      84,    84,    85,    85,    85,    86,    86,    87,    87,    87,
      87,    87,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    93,    93,    94,    94,    95,    95,    95,    96,    96,
      96,    96,    96,    97,    97,    97,    98,    98,    98,    98,
      99,    99,    99,    99,    99,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     101,   101,   101,   102,   102,   103,   104,   104,   104,   104,
     104,   105,   105,   106,   106,   107,   107,   107,   107,   108,
     108,   108,   108,   108,   109,   109,   110,   110,   111,   111,
     112,   113,   114,   114,   114,   114,   115,   115,   115,   115,
     115
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     1,     1,     3,     1,     1,     1,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     5,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     2,
       1,     3,     3,     3,     3,     1,     2,     2,     4,     4,
       4,     4,     2,     4,     4,     4,     4,     4,     4,     4,
       1,     2,     2,     5,     7,     5,     1,     2,     3,     3,
       4,     2,     2,     2,     3,     1,     2,     5,     4,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   102,   100,    99,   101,   103,     0,     0,   113,
     114,     0,     0,     0,    10,   112,   115,   116,   117,     0,
       8,     2,     3,    80,     0,    16,    15,    22,    33,    35,
      37,    39,    41,    43,    45,    48,    53,    56,    60,    65,
       4,     6,     7,     5,     0,    95,    13,    12,     0,     0,
       0,    72,     0,     0,    92,    91,     0,     0,     0,     0,
       0,     0,    67,    12,    66,     0,     0,     0,     1,     9,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    59,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,    81,     0,    93,   104,
     108,   111,     0,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,    14,     0,    20,    21,     0,    36,    38,    40,
      42,    44,    46,    47,    52,    51,    49,    50,    55,    54,
      58,    57,    64,    63,    62,    61,    26,    25,    27,    28,
      32,    31,    30,    29,    23,    24,     0,     0,    94,    19,
      12,    74,    14,    73,     0,     0,    76,    77,    75,    78,
     120,     0,    98,    69,    70,   118,    68,     0,     0,   105,
     110,   109,     0,    86,    85,    83,    97,    34,    87,     0,
       5,     0,     0,    88,    89,     0,     5,    84,    90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,   204,    52,    53,    54,    55,   120,
     211,   121,   201,   122,    56,    73
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -170
static const yytype_int16 yypact[] =
{
     575,   -28,   607,   -13,   -10,   -22,     8,    45,    61,   -31,
      73,    94,  -170,  -170,  -170,  -170,  -170,   639,   639,  -170,
    -170,   117,   124,   639,  -170,  -170,  -170,  -170,  -170,   187,
    -170,   575,  -170,  -170,    55,   135,  -170,  -170,    97,   156,
     132,   138,   136,    75,    84,   100,   103,    72,   210,   108,
    -170,  -170,  -170,  -170,   -21,     1,  -170,   147,   639,   639,
     148,   135,   639,   639,  -170,  -170,   639,     9,     1,   181,
     639,   639,  -170,  -170,  -170,   639,   639,    -3,  -170,  -170,
      58,  -170,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,   639,   639,   639,   639,    72,
    -170,   639,   639,   639,   639,   639,   639,   639,   639,   639,
     639,   639,   639,   639,   639,  -170,  -170,   -29,  -170,  -170,
     161,  -170,   160,  -170,   639,   105,   106,   111,   112,   115,
     165,   167,   168,   170,   175,  -170,   184,   639,   122,   130,
     133,   134,  -170,   182,  -170,   135,   -19,   156,   132,  -170,
    -170,    75,    84,    84,   100,   100,   100,   100,   639,   639,
      72,    72,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,   180,   639,  -170,   148,
     147,  -170,    59,  -170,   211,   211,  -170,  -170,  -170,  -170,
    -170,   169,   148,  -170,  -170,  -170,  -170,    -4,   639,  -170,
    -170,  -170,   284,  -170,  -170,   234,  -170,   148,  -170,   357,
    -170,   430,   211,  -170,  -170,   503,  -170,  -170,  -170
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -170,  -170,   -26,  -169,  -170,  -170,     2,     4,   -98,  -170,
    -170,   166,   171,   173,   164,   179,   107,    54,   109,   -45,
       3,  -170,  -170,  -170,  -167,  -170,   -99,   -18,  -170,   137,
    -170,  -170,  -170,  -170,  -170,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -72
static const yytype_int16 yytable[] =
{
      57,    99,    57,   198,    60,    79,    61,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    68,   205,     9,
      72,    74,    12,    57,    13,    77,    14,    15,   117,    58,
     130,    57,   131,   209,   132,   133,   117,   123,   134,    64,
     118,    80,   215,    16,    62,   217,    69,    63,   119,   100,
     136,   134,   160,   161,   135,   142,   119,    80,    57,    57,
     125,   126,    57,    57,   127,   128,    57,   135,   129,    65,
      57,    57,   138,   139,   143,    57,    57,   140,   141,   200,
     144,   -71,    57,    57,    60,   146,   145,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,    66,   210,   162,   163,   164,   165,     1,     2,
       3,    21,   216,    99,    99,    80,    81,   -71,    67,     8,
     -71,    83,    10,    11,   180,    84,   179,    89,    91,    92,
      70,    90,    93,    27,    28,    94,   -71,    57,   101,   192,
      95,    96,   102,   103,   104,   154,   155,   156,   157,    17,
      18,    71,    19,    20,   115,   116,    21,    22,   203,   203,
      23,   100,   100,   181,   182,    80,    80,    97,    98,   183,
     184,    80,    80,   185,    75,    80,    25,    26,    27,    28,
     193,    76,    80,    79,    57,    57,   203,    78,   194,    79,
      80,   195,   196,    80,    80,    82,   152,   153,    57,    85,
     207,    86,    57,    88,   158,   159,    87,   124,    80,    57,
     137,    57,    57,   177,   202,    57,     1,     2,     3,     4,
       5,   178,     6,   186,     7,   187,   188,     8,   189,     9,
      10,    11,    12,   190,    13,   191,    14,    15,   199,   197,
     105,   106,   107,   108,   109,   110,   206,   111,   212,   112,
     147,   150,     0,    16,   176,     0,   148,    17,    18,   149,
      19,    20,   113,     0,    21,    22,   114,   151,    23,     0,
       0,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,    27,    28,   208,     1,
       2,     3,     4,     5,     0,     6,     0,     7,     0,     0,
       8,     0,     9,    10,    11,    12,     0,    13,     0,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,     0,     0,     0,
      17,    18,     0,    19,    20,     0,     0,    21,    22,     0,
       0,    23,     0,     0,     0,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,    27,
      28,   213,     1,     2,     3,     4,     5,     0,     6,     0,
       7,     0,     0,     8,     0,     9,    10,    11,    12,     0,
      13,     0,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
       0,     0,     0,    17,    18,     0,    19,    20,     0,     0,
      21,    22,     0,     0,    23,     0,     0,     0,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,    27,    28,   214,     1,     2,     3,     4,     5,
       0,     6,     0,     7,     0,     0,     8,     0,     9,    10,
      11,    12,     0,    13,     0,    14,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,     0,     0,    17,    18,     0,    19,
      20,     0,     0,    21,    22,     0,     0,    23,     0,     0,
       0,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    27,    28,   218,     1,     2,
       3,     4,     5,     0,     6,     0,     7,     0,     0,     8,
       0,     9,    10,    11,    12,     0,    13,     0,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,     0,     0,    17,
      18,     0,    19,    20,     0,     0,    21,    22,     0,     0,
      23,     0,     0,     0,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,    27,    28,
       1,     2,     3,     4,     5,     0,     6,     0,     7,     0,
       0,     8,     0,     9,    10,    11,    12,     0,    13,     0,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     0,     0,    16,     0,     0,
       0,    17,    18,     8,    19,    20,    10,    11,    21,    22,
       0,     0,    23,     0,     0,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     0,    25,    26,
      27,    28,     0,    17,    18,     8,    19,    20,    10,    11,
      21,    22,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,    27,    28,     0,    17,    18,     0,    19,    20,
       0,     0,    21,    22,     0,     0,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,    27,    28
};

static const yytype_int16 yycheck[] =
{
       0,    46,     2,    22,     2,    31,     2,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    48,   185,    18,
      17,    18,    21,    23,    23,    23,    25,    26,    57,    57,
      21,    31,    23,   202,    25,    26,    57,    55,    42,    61,
      61,    60,   211,    42,    57,   212,    77,    57,    77,    46,
      68,    42,    97,    98,    58,    58,    77,    60,    58,    59,
      58,    59,    62,    63,    62,    63,    66,    58,    66,    61,
      70,    71,    70,    71,    16,    75,    76,    75,    76,   177,
      80,    22,    82,    83,    82,    83,    82,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    57,   202,   101,   102,   103,   104,     5,     6,
       7,    53,   211,   158,   159,    60,    61,    58,    57,    16,
      61,    24,    19,    20,   124,    28,   124,    52,    44,    45,
      57,    56,    48,    75,    76,    51,    77,   137,    66,   137,
      40,    41,    70,    71,    72,    91,    92,    93,    94,    46,
      47,    57,    49,    50,    46,    47,    53,    54,   184,   185,
      57,   158,   159,    58,    58,    60,    60,    64,    65,    58,
      58,    60,    60,    58,    57,    60,    73,    74,    75,    76,
      58,    57,    60,   209,   184,   185,   212,     0,    58,   215,
      60,    58,    58,    60,    60,    60,    89,    90,   198,    43,
     198,    69,   202,    67,    95,    96,    68,    60,    60,   209,
      29,   211,   212,    52,     3,   215,     5,     6,     7,     8,
       9,    61,    11,    58,    13,    58,    58,    16,    58,    18,
      19,    20,    21,    58,    23,    51,    25,    26,    58,    57,
      30,    31,    32,    33,    34,    35,    77,    37,    14,    39,
      84,    87,    -1,    42,   117,    -1,    85,    46,    47,    86,
      49,    50,    52,    -1,    53,    54,    56,    88,    57,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    13,    -1,    -1,
      16,    -1,    18,    19,    20,    21,    -1,    23,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      46,    47,    -1,    49,    50,    -1,    -1,    53,    54,    -1,
      -1,    57,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      13,    -1,    -1,    16,    -1,    18,    19,    20,    21,    -1,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    46,    47,    -1,    49,    50,    -1,    -1,
      53,    54,    -1,    -1,    57,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    13,    -1,    -1,    16,    -1,    18,    19,
      20,    21,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    47,    -1,    49,
      50,    -1,    -1,    53,    54,    -1,    -1,    57,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    13,    -1,    -1,    16,
      -1,    18,    19,    20,    21,    -1,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,
      47,    -1,    49,    50,    -1,    -1,    53,    54,    -1,    -1,
      57,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
       5,     6,     7,     8,     9,    -1,    11,    -1,    13,    -1,
      -1,    16,    -1,    18,    19,    20,    21,    -1,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,     7,    -1,    -1,    42,    -1,    -1,
      -1,    46,    47,    16,    49,    50,    19,    20,    53,    54,
      -1,    -1,    57,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,     7,    -1,    73,    74,
      75,    76,    -1,    46,    47,    16,    49,    50,    19,    20,
      53,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    -1,    46,    47,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    11,    13,    16,    18,
      19,    20,    21,    23,    25,    26,    42,    46,    47,    49,
      50,    53,    54,    57,    61,    73,    74,    75,    76,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   105,   106,   107,   108,   114,   115,    57,    57,
      86,    87,    57,    57,    61,    61,    57,    57,    48,    77,
      57,    57,   100,   115,   100,    57,    57,    86,     0,    82,
      60,    61,    60,    24,    28,    43,    69,    68,    67,    52,
      56,    44,    45,    48,    51,    40,    41,    64,    65,    99,
     100,    66,    70,    71,    72,    30,    31,    32,    33,    34,
      35,    37,    39,    52,    56,    46,    47,    57,    61,    77,
     109,   111,   113,   107,    60,    86,    86,    86,    86,    86,
      21,    23,    25,    26,    42,    58,   107,    29,    86,    86,
      86,    86,    58,    16,   115,    87,    86,    91,    92,    93,
      94,    95,    96,    96,    97,    97,    97,    97,    98,    98,
      99,    99,   100,   100,   100,   100,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,   109,    52,    61,    86,
     115,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    51,    86,    58,    58,    58,    58,    57,    22,    58,
      88,   112,     3,    82,   104,   104,    77,    86,     4,    83,
     106,   110,    14,     4,     4,    83,   106,   104,     4
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1464 of yacc.c  */
#line 110 "Interface/Parser.yy"
    { cout << "done with a pony file!" << endl; ;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 115 "Interface/Parser.yy"
    {
			deleteExpression(&(yyvsp[(1) - (1)].exp));
		;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 131 "Interface/Parser.yy"
    {
			//nothing!
		;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 135 "Interface/Parser.yy"
    { 
			(yyval.exp) =  (yyvsp[(1) - (2)].exp);
		;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 141 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 142 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 143 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(2) - (3)].exp); ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 147 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 148 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 152 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 153 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eCONCAT, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 154 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eCONCAT, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 155 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eCONCAT, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 156 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eCONCAT, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 160 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 178 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 180 "Interface/Parser.yy"
    {
			 if(evaluateIntExpression((yyvsp[(1) - (5)].exp)))
			 	(yyval.exp) = createNumber(evaluateIntExpression((yyvsp[(3) - (5)].exp)));
			 else
			 	(yyval.exp) = createNumber(evaluateIntExpression((yyvsp[(5) - (5)].exp)));
			 
		;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 190 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 191 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eLOGIC_OR, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));  ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 195 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 196 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eLOGIC_AND, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));  ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 200 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 201 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eOR, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));  ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 205 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 206 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eXOR, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));  ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 210 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 211 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eAND, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));  ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 215 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 216 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eEQUAL, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));  ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 217 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eNEQUAL, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));  ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 220 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 221 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eLTHAN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));  ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 222 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eGTHAN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));  ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 223 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eLETHAN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));  ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 224 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eGETHAN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));  ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 228 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 229 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eLEFT, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));  ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 230 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eRIGHT, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));  ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 234 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp);;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 235 "Interface/Parser.yy"
    {(yyval.exp) = createOperation(ePLUS, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 236 "Interface/Parser.yy"
    {(yyval.exp) = createOperation(eSUBTRACT, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 237 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(ePLUS, (yyvsp[(1) - (2)].exp), (yyvsp[(2) - (2)].exp)); ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 241 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 242 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eMULTIPLY, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 243 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eDIVIDE, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 244 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(eMOD, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 245 "Interface/Parser.yy"
    { (yyval.exp) = createOperation(ePOW, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 249 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp);;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 250 "Interface/Parser.yy"
    { (yyval.ival) = ++(yyvsp[(2) - (2)].ival); ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 251 "Interface/Parser.yy"
    { (yyval.ival) = --(yyvsp[(2) - (2)].ival); ;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 253 "Interface/Parser.yy"
    {
			(yyval.exp) = createNumber(to_int((yyvsp[(3) - (4)].exp)));
		;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 257 "Interface/Parser.yy"
    {
			(yyval.exp) = createNumber((int)sqrt(evaluateIntExpression((yyvsp[(3) - (4)].exp))));
		;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 261 "Interface/Parser.yy"
    {
			(yyval.exp) = createNumber((int)cbrt(evaluateIntExpression((yyvsp[(3) - (4)].exp))));
		;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 265 "Interface/Parser.yy"
    {
			cout << evaluateExpression((yyvsp[(3) - (4)].exp)) << endl;
			fflush(stdout);
			(yyval.exp) = createNumber(0);
		;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 271 "Interface/Parser.yy"
    {
			cout << evaluateExpression((yyvsp[(2) - (2)].exp)) << endl;
			fflush(stdout);
			(yyval.exp) = createNumber(0);
		;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 277 "Interface/Parser.yy"
    {
			cout << evaluateExpression((yyvsp[(3) - (4)].exp));
			fflush(stdout);
			(yyval.exp) = createNumber(0);
		;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 283 "Interface/Parser.yy"
    {
			system(evaluateExpression((yyvsp[(3) - (4)].exp)).c_str());
			(yyval.exp) = createNumber(0);
		;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 288 "Interface/Parser.yy"
    {
			(yyval.exp) = createNumber(intInput());
		;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 292 "Interface/Parser.yy"
    {
			(yyval.exp) = createNumber(byteInput());
		;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 296 "Interface/Parser.yy"
    {
			(yyval.exp) = createNumber(shortInput());
		;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 300 "Interface/Parser.yy"
    {
			(yyval.exp) = createNumber(longInput());
		;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 304 "Interface/Parser.yy"
    {
			(yyval.exp) = createNumber(longInput());
		;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 317 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp);;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 324 "Interface/Parser.yy"
    { 
			if(evaluateIntExpression((yyvsp[(3) - (5)].exp)))
			{
				(yyval.exp) = (yyvsp[(5) - (5)].exp);
			} 
		;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 334 "Interface/Parser.yy"
    { cout << "el while!: " << endl; ;}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 403 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp);;}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 404 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp);;}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 405 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp);;}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 406 "Interface/Parser.yy"
    { (yyval.exp) = createFloatNumber((yyvsp[(1) - (1)].fval)); ;}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 410 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 411 "Interface/Parser.yy"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 413 "Interface/Parser.yy"
    {
			(yyval.exp) = createStr((char*)to_string((yyvsp[(3) - (4)].exp)).c_str());
		;}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 417 "Interface/Parser.yy"
    {
			(yyval.exp) = createStr(strInput());
		;}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 421 "Interface/Parser.yy"
    {
			(yyval.exp) = createStr(strInput());
		;}
    break;



/* Line 1464 of yacc.c  */
#line 2320 "Obj/Parser.tab.cc"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 426 "Interface/Parser.yy"


extern "C" int yyparse();

int main(int argc, char * argv[]) {
	if(argc <= 1)
	{
		cerr << "No input file detected!" << endl;
		return	1;
	}
	FILE *myfile = fopen(argv[1], "r");
	
	if (!myfile) {
		cerr << "Can't open file: " << argv[1] << endl;
		return -1;
	}
	
	yyin = myfile;
	
	do 
	{
		yyparse();
	} while (!feof(yyin));
	return 0;
}

