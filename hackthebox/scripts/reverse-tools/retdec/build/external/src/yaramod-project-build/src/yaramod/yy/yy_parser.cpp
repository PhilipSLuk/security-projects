// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.
// //                    "%code top" blocks.
#line 26 "parser/yy/parser.y" // lalr1.cc:397

#include "yaramod/parser/parser_driver.h"

using namespace yaramod;

static yy::Parser::symbol_type yylex(ParserDriver& driver)
{
	return driver.getLexer().getNextToken();
}

#line 45 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:397


// First part of user declarations.

#line 50 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "yy_parser.hpp"

// User implementation prologue.

#line 64 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:412


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 46 "parser/yy/parser.y" // lalr1.cc:479
namespace  yaramod { namespace yy  {
#line 150 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
   Parser ::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
   Parser :: Parser  (yaramod::ParserDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

   Parser ::~ Parser  ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
   Parser ::by_state::by_state ()
    : state (empty_state)
  {}

  inline
   Parser ::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
   Parser ::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
   Parser ::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
   Parser ::symbol_number_type
   Parser ::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
   Parser ::stack_symbol_type::stack_symbol_type ()
  {}


  inline
   Parser ::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 109: // condition
      case 110: // expression
      case 113: // primary_expression
      case 114: // range
      case 115: // for_expression
      case 116: // integer_set
      case 118: // string_set
      case 120: // identifier
        value.move< Expression::Ptr > (that.value);
        break;

      case 124: // boolean
      case 138: // regexp_greedy
        value.move< bool > (that.value);
        break;

      case 91: // REGEXP_RANGE
        value.move< std::pair<nonstd::optional<std::uint64_t>, nonstd::optional<std::uint64_t>> > (that.value);
        break;

      case 129: // hex_or
      case 131: // hex_jump
        value.move< std::shared_ptr<yaramod::HexStringUnit> > (that.value);
        break;

      case 135: // regexp_or
      case 137: // regexp_repeat
      case 139: // regexp_single
        value.move< std::shared_ptr<yaramod::RegexpUnit> > (that.value);
        break;

      case 105: // strings
      case 106: // strings_body
        value.move< std::shared_ptr<yaramod::Rule::StringsTrie> > (that.value);
        break;

      case 107: // string
      case 132: // regexp
      case 134: // regexp_body
        value.move< std::shared_ptr<yaramod::String> > (that.value);
        break;

      case 57: // SLASH
      case 58: // STRING_LITERAL
      case 59: // INTEGER
      case 60: // DOUBLE
      case 61: // STRING_ID
      case 62: // STRING_ID_WILDCARD
      case 63: // STRING_LENGTH
      case 64: // STRING_OFFSET
      case 65: // STRING_COUNT
      case 66: // ID
      case 67: // INTEGER_FUNCTION
      case 90: // REGEXP_CHAR
      case 92: // REGEXP_CLASS
        value.move< std::string > (that.value);
        break;

      case 122: // string_mods
        value.move< std::uint32_t > (that.value);
        break;

      case 74: // HEX_INTEGER
        value.move< std::uint64_t > (that.value);
        break;

      case 73: // HEX_NIBBLE
        value.move< std::uint8_t > (that.value);
        break;

      case 117: // integer_enumeration
      case 119: // string_enumeration
      case 121: // arguments
        value.move< std::vector<Expression::Ptr> > (that.value);
        break;

      case 130: // hex_or_body
        value.move< std::vector<std::shared_ptr<yaramod::HexString>> > (that.value);
        break;

      case 125: // hex_string
      case 126: // hex_string_edge
      case 127: // hex_byte
      case 128: // hex_string_body
        value.move< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > (that.value);
        break;

      case 136: // regexp_concat
        value.move< std::vector<std::shared_ptr<yaramod::RegexpUnit>> > (that.value);
        break;

      case 101: // tags
      case 102: // tag_list
        value.move< std::vector<std::string> > (that.value);
        break;

      case 103: // metas
      case 104: // metas_body
        value.move< std::vector<yaramod::Meta> > (that.value);
        break;

      case 123: // literal
        value.move< yaramod::Literal > (that.value);
        break;

      case 97: // rule
        value.move< yaramod::Rule > (that.value);
        break;

      case 100: // rule_mod
        value.move< yaramod::Rule::Modifier > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 109: // condition
      case 110: // expression
      case 113: // primary_expression
      case 114: // range
      case 115: // for_expression
      case 116: // integer_set
      case 118: // string_set
      case 120: // identifier
        value.copy< Expression::Ptr > (that.value);
        break;

      case 124: // boolean
      case 138: // regexp_greedy
        value.copy< bool > (that.value);
        break;

      case 91: // REGEXP_RANGE
        value.copy< std::pair<nonstd::optional<std::uint64_t>, nonstd::optional<std::uint64_t>> > (that.value);
        break;

      case 129: // hex_or
      case 131: // hex_jump
        value.copy< std::shared_ptr<yaramod::HexStringUnit> > (that.value);
        break;

      case 135: // regexp_or
      case 137: // regexp_repeat
      case 139: // regexp_single
        value.copy< std::shared_ptr<yaramod::RegexpUnit> > (that.value);
        break;

      case 105: // strings
      case 106: // strings_body
        value.copy< std::shared_ptr<yaramod::Rule::StringsTrie> > (that.value);
        break;

      case 107: // string
      case 132: // regexp
      case 134: // regexp_body
        value.copy< std::shared_ptr<yaramod::String> > (that.value);
        break;

      case 57: // SLASH
      case 58: // STRING_LITERAL
      case 59: // INTEGER
      case 60: // DOUBLE
      case 61: // STRING_ID
      case 62: // STRING_ID_WILDCARD
      case 63: // STRING_LENGTH
      case 64: // STRING_OFFSET
      case 65: // STRING_COUNT
      case 66: // ID
      case 67: // INTEGER_FUNCTION
      case 90: // REGEXP_CHAR
      case 92: // REGEXP_CLASS
        value.copy< std::string > (that.value);
        break;

      case 122: // string_mods
        value.copy< std::uint32_t > (that.value);
        break;

      case 74: // HEX_INTEGER
        value.copy< std::uint64_t > (that.value);
        break;

      case 73: // HEX_NIBBLE
        value.copy< std::uint8_t > (that.value);
        break;

      case 117: // integer_enumeration
      case 119: // string_enumeration
      case 121: // arguments
        value.copy< std::vector<Expression::Ptr> > (that.value);
        break;

      case 130: // hex_or_body
        value.copy< std::vector<std::shared_ptr<yaramod::HexString>> > (that.value);
        break;

      case 125: // hex_string
      case 126: // hex_string_edge
      case 127: // hex_byte
      case 128: // hex_string_body
        value.copy< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > (that.value);
        break;

      case 136: // regexp_concat
        value.copy< std::vector<std::shared_ptr<yaramod::RegexpUnit>> > (that.value);
        break;

      case 101: // tags
      case 102: // tag_list
        value.copy< std::vector<std::string> > (that.value);
        break;

      case 103: // metas
      case 104: // metas_body
        value.copy< std::vector<yaramod::Meta> > (that.value);
        break;

      case 123: // literal
        value.copy< yaramod::Literal > (that.value);
        break;

      case 97: // rule
        value.copy< yaramod::Rule > (that.value);
        break;

      case 100: // rule_mod
        value.copy< yaramod::Rule::Modifier > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
   Parser ::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
   Parser ::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
   Parser ::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline  Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 109: // condition
      case 110: // expression
      case 113: // primary_expression
      case 114: // range
      case 115: // for_expression
      case 116: // integer_set
      case 118: // string_set
      case 120: // identifier
        yylhs.value.build< Expression::Ptr > ();
        break;

      case 124: // boolean
      case 138: // regexp_greedy
        yylhs.value.build< bool > ();
        break;

      case 91: // REGEXP_RANGE
        yylhs.value.build< std::pair<nonstd::optional<std::uint64_t>, nonstd::optional<std::uint64_t>> > ();
        break;

      case 129: // hex_or
      case 131: // hex_jump
        yylhs.value.build< std::shared_ptr<yaramod::HexStringUnit> > ();
        break;

      case 135: // regexp_or
      case 137: // regexp_repeat
      case 139: // regexp_single
        yylhs.value.build< std::shared_ptr<yaramod::RegexpUnit> > ();
        break;

      case 105: // strings
      case 106: // strings_body
        yylhs.value.build< std::shared_ptr<yaramod::Rule::StringsTrie> > ();
        break;

      case 107: // string
      case 132: // regexp
      case 134: // regexp_body
        yylhs.value.build< std::shared_ptr<yaramod::String> > ();
        break;

      case 57: // SLASH
      case 58: // STRING_LITERAL
      case 59: // INTEGER
      case 60: // DOUBLE
      case 61: // STRING_ID
      case 62: // STRING_ID_WILDCARD
      case 63: // STRING_LENGTH
      case 64: // STRING_OFFSET
      case 65: // STRING_COUNT
      case 66: // ID
      case 67: // INTEGER_FUNCTION
      case 90: // REGEXP_CHAR
      case 92: // REGEXP_CLASS
        yylhs.value.build< std::string > ();
        break;

      case 122: // string_mods
        yylhs.value.build< std::uint32_t > ();
        break;

      case 74: // HEX_INTEGER
        yylhs.value.build< std::uint64_t > ();
        break;

      case 73: // HEX_NIBBLE
        yylhs.value.build< std::uint8_t > ();
        break;

      case 117: // integer_enumeration
      case 119: // string_enumeration
      case 121: // arguments
        yylhs.value.build< std::vector<Expression::Ptr> > ();
        break;

      case 130: // hex_or_body
        yylhs.value.build< std::vector<std::shared_ptr<yaramod::HexString>> > ();
        break;

      case 125: // hex_string
      case 126: // hex_string_edge
      case 127: // hex_byte
      case 128: // hex_string_body
        yylhs.value.build< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ();
        break;

      case 136: // regexp_concat
        yylhs.value.build< std::vector<std::shared_ptr<yaramod::RegexpUnit>> > ();
        break;

      case 101: // tags
      case 102: // tag_list
        yylhs.value.build< std::vector<std::string> > ();
        break;

      case 103: // metas
      case 104: // metas_body
        yylhs.value.build< std::vector<yaramod::Meta> > ();
        break;

      case 123: // literal
        yylhs.value.build< yaramod::Literal > ();
        break;

      case 97: // rule
        yylhs.value.build< yaramod::Rule > ();
        break;

      case 100: // rule_mod
        yylhs.value.build< yaramod::Rule::Modifier > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 4:
#line 197 "parser/yy/parser.y" // lalr1.cc:859
    { YYACCEPT; }
#line 864 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 203 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!driver._file.addImport(yystack_[0].value.as< std::string > ()))
			{
				error(driver.getLocation(), "Unrecognized module '" + yystack_[0].value.as< std::string > () + "' imported");
				YYABORT;
			}
		}
#line 876 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 214 "parser/yy/parser.y" // lalr1.cc:859
    {
			driver.markStartOfRule();
		}
#line 884 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 218 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (driver.ruleExists(yystack_[0].value.as< std::string > ()))
			{
				error(driver.getLocation(), "Redefinition of rule '" + yystack_[0].value.as< std::string > () + "'");
				YYABORT;
			}
		}
#line 896 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 226 "parser/yy/parser.y" // lalr1.cc:859
    {
			driver.addRule(Rule(std::move(yystack_[7].value.as< std::string > ()), yystack_[10].value.as< yaramod::Rule::Modifier > (), std::move(yystack_[3].value.as< std::vector<yaramod::Meta> > ()), std::move(yystack_[2].value.as< std::shared_ptr<yaramod::Rule::StringsTrie> > ()), std::move(yystack_[1].value.as< Expression::Ptr > ()), std::move(yystack_[5].value.as< std::vector<std::string> > ())));
		}
#line 904 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 232 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< yaramod::Rule::Modifier > () = Rule::Modifier::Global; }
#line 910 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 233 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< yaramod::Rule::Modifier > () = Rule::Modifier::Private; }
#line 916 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 234 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< yaramod::Rule::Modifier > () = Rule::Modifier::None; }
#line 922 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 238 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[0].value.as< std::vector<std::string> > ()); }
#line 928 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 239 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::vector<std::string> > ().clear(); }
#line 934 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 244 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[1].value.as< std::vector<std::string> > ());
			yylhs.value.as< std::vector<std::string> > ().push_back(std::move(yystack_[0].value.as< std::string > ()));
		}
#line 943 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 248 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::vector<std::string> > ().push_back(std::move(yystack_[0].value.as< std::string > ())); }
#line 949 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 252 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::vector<yaramod::Meta> > () = std::move(yystack_[0].value.as< std::vector<yaramod::Meta> > ()); }
#line 955 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 253 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::vector<yaramod::Meta> > ().clear(); }
#line 961 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 258 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< std::vector<yaramod::Meta> > () = std::move(yystack_[3].value.as< std::vector<yaramod::Meta> > ());
			yylhs.value.as< std::vector<yaramod::Meta> > ().emplace_back(std::move(yystack_[2].value.as< std::string > ()), std::move(yystack_[0].value.as< yaramod::Literal > ()));
		}
#line 970 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 262 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::vector<yaramod::Meta> > ().clear(); }
#line 976 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 266 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::Rule::StringsTrie> > () = std::move(yystack_[0].value.as< std::shared_ptr<yaramod::Rule::StringsTrie> > ()); }
#line 982 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 268 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< std::shared_ptr<yaramod::Rule::StringsTrie> > () = std::make_shared<Rule::StringsTrie>();
			driver.setCurrentStrings(yylhs.value.as< std::shared_ptr<yaramod::Rule::StringsTrie> > ());
		}
#line 991 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 276 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< std::shared_ptr<yaramod::Rule::StringsTrie> > () = std::move(yystack_[3].value.as< std::shared_ptr<yaramod::Rule::StringsTrie> > ());
			yystack_[0].value.as< std::shared_ptr<yaramod::String> > ()->setIdentifier(std::move(yystack_[2].value.as< std::string > ()));

			if (!yylhs.value.as< std::shared_ptr<yaramod::Rule::StringsTrie> > ()->insert(yystack_[0].value.as< std::shared_ptr<yaramod::String> > ()->getIdentifier(), std::move(yystack_[0].value.as< std::shared_ptr<yaramod::String> > ())))
			{
				error(driver.getLocation(), "Redefinition of string '" + yystack_[0].value.as< std::shared_ptr<yaramod::String> > ()->getIdentifier() + "'");
				YYABORT;
			}
		}
#line 1006 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 287 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< std::shared_ptr<yaramod::Rule::StringsTrie> > () = std::make_shared<Rule::StringsTrie>();
			driver.setCurrentStrings(yylhs.value.as< std::shared_ptr<yaramod::Rule::StringsTrie> > ());
		}
#line 1015 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 295 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< std::shared_ptr<yaramod::String> > () = std::make_shared<PlainString>(std::move(yystack_[1].value.as< std::string > ()));
			yylhs.value.as< std::shared_ptr<yaramod::String> > ()->setModifiers(yystack_[0].value.as< std::uint32_t > ());
		}
#line 1024 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 300 "parser/yy/parser.y" // lalr1.cc:859
    {
			driver.getLexer().switchToHexLexer();
		}
#line 1032 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 304 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< std::shared_ptr<yaramod::String> > () = std::make_shared<HexString>(std::move(yystack_[1].value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ()));
			driver.getLexer().switchToYaraLexer();
		}
#line 1041 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 309 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< std::shared_ptr<yaramod::String> > () = std::move(yystack_[1].value.as< std::shared_ptr<yaramod::String> > ());
			yylhs.value.as< std::shared_ptr<yaramod::String> > ()->setModifiers(yystack_[0].value.as< std::uint32_t > ());
		}
#line 1050 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 316 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< Expression::Ptr > () = std::move(yystack_[0].value.as< Expression::Ptr > ()); }
#line 1056 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 321 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<BoolLiteralExpression>(yystack_[0].value.as< bool > ());
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);
		}
#line 1065 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 326 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!driver.stringExists(yystack_[0].value.as< std::string > ()))
			{
				error(driver.getLocation(), "Reference to undefined string '" + yystack_[0].value.as< std::string > () + "'");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<StringExpression>(std::move(yystack_[0].value.as< std::string > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);
		}
#line 1080 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 337 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!driver.stringExists(yystack_[2].value.as< std::string > ()))
			{
				error(driver.getLocation(), "Reference to undefined string '" + yystack_[2].value.as< std::string > () + "'");
				YYABORT;
			}

			if (!yystack_[0].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "operator 'at' expects integer on the right-hand side of the expression");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<StringAtExpression>(std::move(yystack_[2].value.as< std::string > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);
		}
#line 1101 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 354 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!driver.stringExists(yystack_[2].value.as< std::string > ()))
			{
				error(driver.getLocation(), "Reference to undefined string '" + yystack_[2].value.as< std::string > () + "'");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<StringInRangeExpression>(std::move(yystack_[2].value.as< std::string > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);
		}
#line 1116 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 365 "parser/yy/parser.y" // lalr1.cc:859
    {
			auto symbol = std::make_shared<ValueSymbol>(yystack_[0].value.as< std::string > (), Expression::Type::Int);
			if (!driver.addLocalSymbol(symbol))
			{
				error(driver.getLocation(), "Redefinition of identifier '" + yystack_[0].value.as< std::string > () + "'");
				YYABORT;
			}
		}
#line 1129 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 374 "parser/yy/parser.y" // lalr1.cc:859
    {
			/* Delete $id before we move it to ForIntExpression */
			driver.removeLocalSymbol(yystack_[7].value.as< std::string > ());
			yylhs.value.as< Expression::Ptr > () = std::make_shared<ForIntExpression>(std::move(yystack_[8].value.as< Expression::Ptr > ()), std::move(yystack_[7].value.as< std::string > ()), std::move(yystack_[4].value.as< Expression::Ptr > ()), std::move(yystack_[1].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);
		}
#line 1140 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 381 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (driver.isInStringLoop())
			{
				error(driver.getLocation(), "Nesting of for-loop over strings is not allowed");
				YYABORT;
			}

			driver.stringLoopEnter();
		}
#line 1154 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 391 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<ForStringExpression>(std::move(yystack_[7].value.as< Expression::Ptr > ()), std::move(yystack_[5].value.as< Expression::Ptr > ()), std::move(yystack_[1].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);

			driver.stringLoopLeave();
		}
#line 1165 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 398 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<OfExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);
		}
#line 1174 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 403 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<NotExpression>(std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);
		}
#line 1183 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 408 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<AndExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);
		}
#line 1192 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 413 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<OrExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);
		}
#line 1201 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 418 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<LtExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);
		}
#line 1210 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 423 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<GtExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);
		}
#line 1219 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 428 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<LeExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);
		}
#line 1228 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 433 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<GeExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);
		}
#line 1237 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 438 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<EqExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);
		}
#line 1246 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 443 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<NeqExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);
		}
#line 1255 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 448 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[2].value.as< Expression::Ptr > ()->isString())
			{
				error(driver.getLocation(), "operator 'contains' expects string on the left-hand side of the expression");
				YYABORT;
			}

			if (!yystack_[0].value.as< Expression::Ptr > ()->isString())
			{
				error(driver.getLocation(), "operator 'contains' expects string on the right-hand side of the expression");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<ContainsExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);
		}
#line 1276 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 465 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[2].value.as< Expression::Ptr > ()->isString())
			{
				error(driver.getLocation(), "operator 'matches' expects string on the left-hand side of the expression");
				YYABORT;
			}

			auto regexp = std::make_shared<RegexpExpression>(std::move(yystack_[0].value.as< std::shared_ptr<yaramod::String> > ()));
			yylhs.value.as< Expression::Ptr > () = std::make_shared<MatchesExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(regexp));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Bool);
		}
#line 1292 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 477 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::move(yystack_[0].value.as< Expression::Ptr > ());
		}
#line 1300 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 481 "parser/yy/parser.y" // lalr1.cc:859
    {
			auto type = yystack_[1].value.as< Expression::Ptr > ()->getType();
			yylhs.value.as< Expression::Ptr > () = std::make_shared<ParenthesesExpression>(std::move(yystack_[1].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(type);
		}
#line 1310 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 490 "parser/yy/parser.y" // lalr1.cc:859
    {
			auto type = yystack_[1].value.as< Expression::Ptr > ()->getType();
			yylhs.value.as< Expression::Ptr > () = std::make_shared<ParenthesesExpression>(std::move(yystack_[1].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(type);
		}
#line 1320 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 496 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<FilesizeExpression>();
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Int);
		}
#line 1329 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 501 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<EntrypointExpression>();
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Int);
		}
#line 1338 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 506 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<IntLiteralExpression>(std::move(yystack_[0].value.as< std::string > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Int);
		}
#line 1347 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 511 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<DoubleLiteralExpression>(std::move(yystack_[0].value.as< std::string > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Float);
		}
#line 1356 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 516 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<StringLiteralExpression>(std::move(yystack_[0].value.as< std::string > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::String);
		}
#line 1365 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 521 "parser/yy/parser.y" // lalr1.cc:859
    {
			// Replace '#' for '$' to get string id
			auto stringId = yystack_[0].value.as< std::string > ();
			stringId[0] = '$';

			if (!driver.stringExists(stringId))
			{
				error(driver.getLocation(), "Reference to undefined string '" + yystack_[0].value.as< std::string > () + "'");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<StringCountExpression>(std::move(yystack_[0].value.as< std::string > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Int);
		}
#line 1384 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 536 "parser/yy/parser.y" // lalr1.cc:859
    {
			// Replace '@' for '$' to get string id
			auto stringId = yystack_[0].value.as< std::string > ();
			stringId[0] = '$';

			if (!driver.stringExists(stringId))
			{
				error(driver.getLocation(), "Reference to undefined string '" + yystack_[0].value.as< std::string > () + "'");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<StringOffsetExpression>(std::move(yystack_[0].value.as< std::string > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Int);
		}
#line 1403 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 551 "parser/yy/parser.y" // lalr1.cc:859
    {
			// Replace '@' for '$' to get string id
			auto stringId = yystack_[3].value.as< std::string > ();
			stringId[0] = '$';

			if (!driver.stringExists(stringId))
			{
				error(driver.getLocation(), "Reference to undefined string '" + yystack_[3].value.as< std::string > () + "'");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<StringOffsetExpression>(std::move(yystack_[3].value.as< std::string > ()), std::move(yystack_[1].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Int);
		}
#line 1422 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 566 "parser/yy/parser.y" // lalr1.cc:859
    {
			// Replace '!' for '$' to get string id
			auto stringId = yystack_[0].value.as< std::string > ();
			stringId[0] = '$';

			if (!driver.stringExists(stringId))
			{
				error(driver.getLocation(), "Reference to undefined string '" + yystack_[0].value.as< std::string > () + "'");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<StringLengthExpression>(std::move(yystack_[0].value.as< std::string > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Int);
		}
#line 1441 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 581 "parser/yy/parser.y" // lalr1.cc:859
    {
			// Replace '!' for '$' to get string id
			auto stringId = yystack_[3].value.as< std::string > ();
			stringId[0] = '$';

			if (!driver.stringExists(stringId))
			{
				error(driver.getLocation(), "Reference to undefined string '" + yystack_[3].value.as< std::string > () + "'");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<StringLengthExpression>(std::move(yystack_[3].value.as< std::string > ()), std::move(yystack_[1].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Int);
		}
#line 1460 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 596 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[0].value.as< Expression::Ptr > ()->isInt() && !yystack_[0].value.as< Expression::Ptr > ()->isFloat())
			{
				error(driver.getLocation(), "unary minus expects integer or float type");
				YYABORT;
			}

			auto type = yystack_[0].value.as< Expression::Ptr > ()->getType();
			yylhs.value.as< Expression::Ptr > () = std::make_shared<UnaryMinusExpression>(std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(type);
		}
#line 1476 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 64:
#line 608 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[2].value.as< Expression::Ptr > ()->isInt() && !yystack_[2].value.as< Expression::Ptr > ()->isFloat())
			{
				error(driver.getLocation(), "operator '+' expects integer or float on the left-hand side");
				YYABORT;
			}

			if (!yystack_[0].value.as< Expression::Ptr > ()->isInt() && !yystack_[0].value.as< Expression::Ptr > ()->isFloat())
			{
				error(driver.getLocation(), "operator '+' expects integer or float on the right-hand side");
				YYABORT;
			}

			auto type = (yystack_[2].value.as< Expression::Ptr > ()->isInt() && yystack_[0].value.as< Expression::Ptr > ()->isInt()) ? Expression::Type::Int : Expression::Type::Float;
			yylhs.value.as< Expression::Ptr > () = std::make_shared<PlusExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(type);
		}
#line 1498 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 65:
#line 626 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[2].value.as< Expression::Ptr > ()->isInt() && !yystack_[2].value.as< Expression::Ptr > ()->isFloat())
			{
				error(driver.getLocation(), "operator '-' expects integer or float on the left-hand side");
				YYABORT;
			}

			if (!yystack_[0].value.as< Expression::Ptr > ()->isInt() && !yystack_[0].value.as< Expression::Ptr > ()->isFloat())
			{
				error(driver.getLocation(), "operator '-' expects integer or float on the right-hand side");
				YYABORT;
			}

			auto type = (yystack_[2].value.as< Expression::Ptr > ()->isInt() && yystack_[0].value.as< Expression::Ptr > ()->isInt()) ? Expression::Type::Int : Expression::Type::Float;
			yylhs.value.as< Expression::Ptr > () = std::make_shared<MinusExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(type);
		}
#line 1520 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 644 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[2].value.as< Expression::Ptr > ()->isInt() && !yystack_[2].value.as< Expression::Ptr > ()->isFloat())
			{
				error(driver.getLocation(), "operator '*' expects integer or float on the left-hand side");
				YYABORT;
			}

			if (!yystack_[0].value.as< Expression::Ptr > ()->isInt() && !yystack_[0].value.as< Expression::Ptr > ()->isFloat())
			{
				error(driver.getLocation(), "operator '*' expects integer or float on the right-hand side");
				YYABORT;
			}

			auto type = (yystack_[2].value.as< Expression::Ptr > ()->isInt() && yystack_[0].value.as< Expression::Ptr > ()->isInt()) ? Expression::Type::Int : Expression::Type::Float;
			yylhs.value.as< Expression::Ptr > () = std::make_shared<MultiplyExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(type);
		}
#line 1542 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 662 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[2].value.as< Expression::Ptr > ()->isInt() && !yystack_[2].value.as< Expression::Ptr > ()->isFloat())
			{
				error(driver.getLocation(), "operator '\\' expects integer or float on the left-hand side");
				YYABORT;
			}

			if (!yystack_[0].value.as< Expression::Ptr > ()->isInt() && !yystack_[0].value.as< Expression::Ptr > ()->isFloat())
			{
				error(driver.getLocation(), "operator '\\' expects integer or float on the right-hand side");
				YYABORT;
			}

			auto type = (yystack_[2].value.as< Expression::Ptr > ()->isInt() && yystack_[0].value.as< Expression::Ptr > ()->isInt()) ? Expression::Type::Int : Expression::Type::Float;
			yylhs.value.as< Expression::Ptr > () = std::make_shared<DivideExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(type);
		}
#line 1564 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 680 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[2].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "operator '%' expects integer on the left-hand side");
				YYABORT;
			}

			if (!yystack_[0].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "operator '%' expects integer on the right-hand side");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<ModuloExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Int);
		}
#line 1585 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 697 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[2].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "operator '^' expects integer on the left-hand side");
				YYABORT;
			}

			if (!yystack_[0].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "operator '^' expects integer on the right-hand side");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<BitwiseXorExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Int);
		}
#line 1606 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 714 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[2].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "operator '&' expects integer on the left-hand side");
				YYABORT;
			}

			if (!yystack_[0].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "operator '&' expects integer on the right-hand side");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<BitwiseAndExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Int);
		}
#line 1627 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 731 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[2].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "operator '|' expects integer on the left-hand side");
				YYABORT;
			}

			if (!yystack_[0].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "operator '|' expects integer on the right-hand side");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<BitwiseOrExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Int);
		}
#line 1648 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 748 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[0].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "bitwise not expects integer");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<BitwiseNotExpression>(std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Int);
		}
#line 1663 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 759 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[2].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "operator '<<' expects integer on the left-hand side");
				YYABORT;
			}

			if (!yystack_[0].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "operator '<<' expects integer on the right-hand side");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<ShiftLeftExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Int);
		}
#line 1684 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 776 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[2].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "operator '>>' expects integer on the left-hand side");
				YYABORT;
			}

			if (!yystack_[0].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "operator '>>' expects integer on the right-hand side");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<ShiftRightExpression>(std::move(yystack_[2].value.as< Expression::Ptr > ()), std::move(yystack_[0].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Int);
		}
#line 1705 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 793 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[1].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "operator '" + yystack_[3].value.as< std::string > () + "' expects integer");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<IntFunctionExpression>(std::move(yystack_[3].value.as< std::string > ()), std::move(yystack_[1].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Int);
		}
#line 1720 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 804 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::move(yystack_[0].value.as< Expression::Ptr > ());
		}
#line 1728 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 808 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< Expression::Ptr > () = std::make_shared<RegexpExpression>(std::move(yystack_[0].value.as< std::shared_ptr<yaramod::String> > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(Expression::Type::Regexp);
		}
#line 1737 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 78:
#line 816 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[3].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "operator '..' expects integer as lower bound of the interval");
				YYABORT;
			}

			if (!yystack_[1].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "operator '..' expects integer as higher bound of the interval");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<RangeExpression>(std::move(yystack_[3].value.as< Expression::Ptr > ()), std::move(yystack_[1].value.as< Expression::Ptr > ()));
		}
#line 1757 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 834 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< Expression::Ptr > () = std::move(yystack_[0].value.as< Expression::Ptr > ()); }
#line 1763 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 835 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< Expression::Ptr > () = std::make_shared<AllExpression>(); }
#line 1769 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 836 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< Expression::Ptr > () = std::make_shared<AnyExpression>(); }
#line 1775 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 82:
#line 840 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< Expression::Ptr > () = std::make_shared<SetExpression>(std::move(yystack_[1].value.as< std::vector<Expression::Ptr> > ())); }
#line 1781 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 841 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< Expression::Ptr > () = std::move(yystack_[0].value.as< Expression::Ptr > ()); }
#line 1787 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 84:
#line 846 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[0].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "integer set expects integer type");
				YYABORT;
			}

			yylhs.value.as< std::vector<Expression::Ptr> > ().push_back(std::move(yystack_[0].value.as< Expression::Ptr > ()));
		}
#line 1801 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 85:
#line 856 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[0].value.as< Expression::Ptr > ()->isInt())
			{
				error(driver.getLocation(), "integer set expects integer type");
				YYABORT;
			}

			yylhs.value.as< std::vector<Expression::Ptr> > () = std::move(yystack_[2].value.as< std::vector<Expression::Ptr> > ());
			yylhs.value.as< std::vector<Expression::Ptr> > ().push_back(std::move(yystack_[0].value.as< Expression::Ptr > ()));
		}
#line 1816 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 86:
#line 869 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< Expression::Ptr > () = std::make_shared<SetExpression>(std::move(yystack_[1].value.as< std::vector<Expression::Ptr> > ())); }
#line 1822 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 87:
#line 870 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< Expression::Ptr > () = std::make_shared<ThemExpression>(); }
#line 1828 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 88:
#line 875 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!driver.stringExists(yystack_[0].value.as< std::string > ()))
			{
				error(driver.getLocation(), "Reference to undefined string '" + yystack_[0].value.as< std::string > () + "'");
				YYABORT;
			}

			yylhs.value.as< std::vector<Expression::Ptr> > ().push_back(std::make_shared<StringExpression>(std::move(yystack_[0].value.as< std::string > ())));
		}
#line 1842 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 89:
#line 885 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!driver.stringExists(yystack_[0].value.as< std::string > ()))
			{
				error(driver.getLocation(), "No string matched with wildcard '" + yystack_[0].value.as< std::string > () + "'");
				YYABORT;
			}

			yylhs.value.as< std::vector<Expression::Ptr> > ().push_back(std::make_shared<StringWildcardExpression>(std::move(yystack_[0].value.as< std::string > ())));
		}
#line 1856 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 90:
#line 895 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!driver.stringExists(yystack_[0].value.as< std::string > ()))
			{
				error(driver.getLocation(), "Reference to undefined string '" + yystack_[0].value.as< std::string > () + "'");
				YYABORT;
			}

			yylhs.value.as< std::vector<Expression::Ptr> > () = std::move(yystack_[2].value.as< std::vector<Expression::Ptr> > ());
			yylhs.value.as< std::vector<Expression::Ptr> > ().push_back(std::make_shared<StringExpression>(std::move(yystack_[0].value.as< std::string > ())));
		}
#line 1871 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 91:
#line 906 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!driver.stringExists(yystack_[0].value.as< std::string > ()))
			{
				error(driver.getLocation(), "No string matched with wildcard '" + yystack_[0].value.as< std::string > () + "'");
				YYABORT;
			}

			yylhs.value.as< std::vector<Expression::Ptr> > () = std::move(yystack_[2].value.as< std::vector<Expression::Ptr> > ());
			yylhs.value.as< std::vector<Expression::Ptr> > ().push_back(std::make_shared<StringWildcardExpression>(std::move(yystack_[0].value.as< std::string > ())));
		}
#line 1886 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 92:
#line 920 "parser/yy/parser.y" // lalr1.cc:859
    {
			auto symbol = driver.findSymbol(yystack_[0].value.as< std::string > ());
			if (!symbol)
			{
				error(driver.getLocation(), "Unrecognized identifier '" + yystack_[0].value.as< std::string > () + "' referenced");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<IdExpression>(symbol);
			yylhs.value.as< Expression::Ptr > ()->setType(symbol->getDataType());
		}
#line 1902 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 93:
#line 932 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[2].value.as< Expression::Ptr > ()->isObject())
			{
				error(driver.getLocation(), "Identifier '" + yystack_[2].value.as< Expression::Ptr > ()->getText() + "' is not an object");
				YYABORT;
			}

			auto parentSymbol = std::static_pointer_cast<const IdExpression>(yystack_[2].value.as< Expression::Ptr > ())->getSymbol();
			if (!parentSymbol->isStructure())
			{
				error(driver.getLocation(), "Identifier '" + parentSymbol->getName() + "' is not a structure");
				YYABORT;
			}

			auto structParentSymbol = std::static_pointer_cast<const StructureSymbol>(parentSymbol);
			auto attr = structParentSymbol->getAttribute(yystack_[0].value.as< std::string > ());
			if (!attr)
			{
				error(driver.getLocation(), "Unrecognized identifier '" + yystack_[0].value.as< std::string > () + "' referenced");
				YYABORT;
			}

			auto symbol = attr.value();
			yylhs.value.as< Expression::Ptr > () = std::make_shared<StructAccessExpression>(symbol, std::move(yystack_[2].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(symbol->getDataType());
		}
#line 1933 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 94:
#line 959 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[3].value.as< Expression::Ptr > ()->isObject())
			{
				error(driver.getLocation(), "Identifier '" + yystack_[3].value.as< Expression::Ptr > ()->getText() + "' is not an object");
				YYABORT;
			}

			auto parentSymbol = std::static_pointer_cast<const IdExpression>(yystack_[3].value.as< Expression::Ptr > ())->getSymbol();
			if (!parentSymbol->isArray() && !parentSymbol->isDictionary())
			{
				error(driver.getLocation(), "Identifier '" + parentSymbol->getName() + "' is not an array nor dictionary");
				YYABORT;
			}

			auto iterParentSymbol = std::static_pointer_cast<const IterableSymbol>(parentSymbol);
			yylhs.value.as< Expression::Ptr > () = std::make_shared<ArrayAccessExpression>(iterParentSymbol->getStructuredElementType(), std::move(yystack_[3].value.as< Expression::Ptr > ()), std::move(yystack_[1].value.as< Expression::Ptr > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(iterParentSymbol->getElementType());
		}
#line 1956 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 95:
#line 978 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[3].value.as< Expression::Ptr > ()->isObject())
			{
				error(driver.getLocation(), "Identifier '" + yystack_[3].value.as< Expression::Ptr > ()->getText() + "' is not an object");
				YYABORT;
			}

			auto parentSymbol = std::static_pointer_cast<const IdExpression>(yystack_[3].value.as< Expression::Ptr > ())->getSymbol();
			if (!parentSymbol->isFunction())
			{
				error(driver.getLocation(), "Identifier '" + parentSymbol->getName() + "' is not a function");
				YYABORT;
			}

			auto funcParentSymbol = std::static_pointer_cast<const FunctionSymbol>(parentSymbol);

			// Make copy of just argument types because symbols are not aware of expressions
			std::vector<Expression::Type> argTypes;
			std::for_each(yystack_[1].value.as< std::vector<Expression::Ptr> > ().begin(), yystack_[1].value.as< std::vector<Expression::Ptr> > ().end(),
				[&argTypes](const Expression::Ptr& expr)
				{
					argTypes.push_back(expr->getType());
				});

			if (!funcParentSymbol->overloadExists(argTypes))
			{
				error(driver.getLocation(), "No matching overload of function '" + funcParentSymbol->getName() + "' for these types of parameters");
				YYABORT;
			}

			yylhs.value.as< Expression::Ptr > () = std::make_shared<FunctionCallExpression>(std::move(yystack_[3].value.as< Expression::Ptr > ()), std::move(yystack_[1].value.as< std::vector<Expression::Ptr> > ()));
			yylhs.value.as< Expression::Ptr > ()->setType(funcParentSymbol->getReturnType());
		}
#line 1994 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 96:
#line 1015 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< std::vector<Expression::Ptr> > () = std::move(yystack_[2].value.as< std::vector<Expression::Ptr> > ());
			yylhs.value.as< std::vector<Expression::Ptr> > ().push_back(std::move(yystack_[0].value.as< Expression::Ptr > ()));
		}
#line 2003 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 97:
#line 1019 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::vector<Expression::Ptr> > ().push_back(std::move(yystack_[0].value.as< Expression::Ptr > ())); }
#line 2009 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 98:
#line 1020 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::vector<Expression::Ptr> > ().clear(); }
#line 2015 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 99:
#line 1024 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::uint32_t > () = yystack_[1].value.as< std::uint32_t > () | String::Modifiers::Ascii; }
#line 2021 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 100:
#line 1025 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::uint32_t > () = yystack_[1].value.as< std::uint32_t > () | String::Modifiers::Wide; }
#line 2027 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 101:
#line 1026 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::uint32_t > () = yystack_[1].value.as< std::uint32_t > () | String::Modifiers::Nocase; }
#line 2033 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 102:
#line 1027 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::uint32_t > () = yystack_[1].value.as< std::uint32_t > () | String::Modifiers::Fullword; }
#line 2039 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 103:
#line 1028 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::uint32_t > () = String::Modifiers::None; }
#line 2045 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 104:
#line 1032 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< yaramod::Literal > () = Literal(std::move(yystack_[0].value.as< std::string > ()), Literal::Type::String); }
#line 2051 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 105:
#line 1033 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< yaramod::Literal > () = Literal(std::move(yystack_[0].value.as< std::string > ()), Literal::Type::Int); }
#line 2057 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 106:
#line 1034 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< yaramod::Literal > () = Literal(yystack_[0].value.as< bool > ()); }
#line 2063 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 107:
#line 1038 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< bool > () = true; }
#line 2069 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 108:
#line 1039 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< bool > () = false; }
#line 2075 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 109:
#line 1043 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > () = std::move(yystack_[0].value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ()); }
#line 2081 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 110:
#line 1045 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ());
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().reserve(yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().size() + yystack_[1].value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().size() + yystack_[0].value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().size());
			std::move(yystack_[1].value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().begin(), yystack_[1].value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().end(), std::back_inserter(yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ()));
			std::move(yystack_[0].value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().begin(), yystack_[0].value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().end(), std::back_inserter(yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ()));
		}
#line 2092 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 111:
#line 1053 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > () = std::move(yystack_[0].value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ()); }
#line 2098 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 112:
#line 1054 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<yaramod::HexStringUnit> > ())); }
#line 2104 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 113:
#line 1059 "parser/yy/parser.y" // lalr1.cc:859
    {
			auto first = std::make_shared<HexStringNibble>(yystack_[1].value.as< std::uint8_t > ());
			auto second = std::make_shared<HexStringNibble>(yystack_[0].value.as< std::uint8_t > ());
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().reserve(2);
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().push_back(std::move(first));
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().push_back(std::move(second));
		}
#line 2116 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 114:
#line 1067 "parser/yy/parser.y" // lalr1.cc:859
    {
			auto first = std::make_shared<HexStringNibble>(yystack_[1].value.as< std::uint8_t > ());
			auto second = std::make_shared<HexStringWildcard>();
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().reserve(2);
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().push_back(std::move(first));
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().push_back(std::move(second));
		}
#line 2128 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 115:
#line 1075 "parser/yy/parser.y" // lalr1.cc:859
    {
			auto first = std::make_shared<HexStringWildcard>();
			auto second = std::make_shared<HexStringNibble>(yystack_[0].value.as< std::uint8_t > ());
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().reserve(2);
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().push_back(std::move(first));
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().push_back(std::move(second));
		}
#line 2140 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 116:
#line 1083 "parser/yy/parser.y" // lalr1.cc:859
    {
			auto first = std::make_shared<HexStringWildcard>();
			auto second = std::make_shared<HexStringWildcard>();
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().reserve(2);
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().push_back(std::move(first));
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().push_back(std::move(second));
		}
#line 2152 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 117:
#line 1094 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > () = std::move(yystack_[1].value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ());
			std::move(yystack_[0].value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().begin(), yystack_[0].value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().end(), std::back_inserter(yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ()));
		}
#line 2161 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 118:
#line 1099 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > () = std::move(yystack_[1].value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ());
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<yaramod::HexStringUnit> > ()));
		}
#line 2170 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 119:
#line 1104 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > () = std::move(yystack_[1].value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ());
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<yaramod::HexStringUnit> > ()));
		}
#line 2179 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 120:
#line 1108 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ().clear(); }
#line 2185 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 121:
#line 1112 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::HexStringUnit> > () = std::make_shared<HexStringOr>(std::move(yystack_[1].value.as< std::vector<std::shared_ptr<yaramod::HexString>> > ())); }
#line 2191 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 122:
#line 1116 "parser/yy/parser.y" // lalr1.cc:859
    {
			auto hexStr = std::make_shared<HexString>(std::move(yystack_[0].value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ()));
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexString>> > ().push_back(std::move(hexStr));
		}
#line 2200 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 123:
#line 1121 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexString>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<yaramod::HexString>> > ());
			auto hexStr = std::make_shared<HexString>(std::move(yystack_[0].value.as< std::vector<std::shared_ptr<yaramod::HexStringUnit>> > ()));
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::HexString>> > ().push_back(std::move(hexStr));
		}
#line 2210 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 124:
#line 1129 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::HexStringUnit> > () = std::make_shared<HexStringJump>(yystack_[1].value.as< std::uint64_t > (), yystack_[1].value.as< std::uint64_t > ()); }
#line 2216 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 125:
#line 1130 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::HexStringUnit> > () = std::make_shared<HexStringJump>(yystack_[3].value.as< std::uint64_t > (), yystack_[1].value.as< std::uint64_t > ()); }
#line 2222 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 126:
#line 1131 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::HexStringUnit> > () = std::make_shared<HexStringJump>(yystack_[2].value.as< std::uint64_t > ()); }
#line 2228 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 127:
#line 1132 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::HexStringUnit> > () = std::make_shared<HexStringJump>(); }
#line 2234 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 128:
#line 1137 "parser/yy/parser.y" // lalr1.cc:859
    {
			driver.getLexer().switchToRegexpLexer();
		}
#line 2242 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 129:
#line 1141 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< std::shared_ptr<yaramod::String> > () = std::move(yystack_[1].value.as< std::shared_ptr<yaramod::String> > ());
			std::static_pointer_cast<Regexp>(yylhs.value.as< std::shared_ptr<yaramod::String> > ())->setSuffixModifiers(yystack_[0].value.as< std::string > ());
			driver.getLexer().switchToYaraLexer();
		}
#line 2252 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 130:
#line 1148 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::String> > () = std::make_shared<Regexp>(std::move(yystack_[0].value.as< std::shared_ptr<yaramod::RegexpUnit> > ())); }
#line 2258 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 131:
#line 1152 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpConcat>(std::move(yystack_[0].value.as< std::vector<std::shared_ptr<yaramod::RegexpUnit>> > ())); }
#line 2264 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 132:
#line 1154 "parser/yy/parser.y" // lalr1.cc:859
    {
			auto concat = std::make_shared<RegexpConcat>(std::move(yystack_[0].value.as< std::vector<std::shared_ptr<yaramod::RegexpUnit>> > ()));
			yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpOr>(std::move(yystack_[2].value.as< std::shared_ptr<yaramod::RegexpUnit> > ()), std::move(concat));
		}
#line 2273 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 133:
#line 1161 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::vector<std::shared_ptr<yaramod::RegexpUnit>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<yaramod::RegexpUnit> > ())); }
#line 2279 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 134:
#line 1163 "parser/yy/parser.y" // lalr1.cc:859
    {
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::RegexpUnit>> > () = std::move(yystack_[1].value.as< std::vector<std::shared_ptr<yaramod::RegexpUnit>> > ());
			yylhs.value.as< std::vector<std::shared_ptr<yaramod::RegexpUnit>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<yaramod::RegexpUnit> > ()));
		}
#line 2288 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 135:
#line 1170 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpIteration>(std::move(yystack_[2].value.as< std::shared_ptr<yaramod::RegexpUnit> > ()), yystack_[0].value.as< bool > ()); }
#line 2294 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 136:
#line 1171 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpPositiveIteration>(std::move(yystack_[2].value.as< std::shared_ptr<yaramod::RegexpUnit> > ()), yystack_[0].value.as< bool > ()); }
#line 2300 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 137:
#line 1172 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpOptional>(std::move(yystack_[2].value.as< std::shared_ptr<yaramod::RegexpUnit> > ()), yystack_[0].value.as< bool > ()); }
#line 2306 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 138:
#line 1174 "parser/yy/parser.y" // lalr1.cc:859
    {
			if (!yystack_[1].value.as< std::pair<nonstd::optional<std::uint64_t>, nonstd::optional<std::uint64_t>> > ().first && !yystack_[1].value.as< std::pair<nonstd::optional<std::uint64_t>, nonstd::optional<std::uint64_t>> > ().second)
			{
				error(driver.getLocation(), "Range in regular expression does not have defined lower bound nor higher bound");
				YYABORT;
			}

			if (yystack_[1].value.as< std::pair<nonstd::optional<std::uint64_t>, nonstd::optional<std::uint64_t>> > ().first && yystack_[1].value.as< std::pair<nonstd::optional<std::uint64_t>, nonstd::optional<std::uint64_t>> > ().second && yystack_[1].value.as< std::pair<nonstd::optional<std::uint64_t>, nonstd::optional<std::uint64_t>> > ().first.value() > yystack_[1].value.as< std::pair<nonstd::optional<std::uint64_t>, nonstd::optional<std::uint64_t>> > ().second.value())
			{
				error(driver.getLocation(), "Range in regular expression has greater lower bound than higher bound");
				YYABORT;
			}

			yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpRange>(std::move(yystack_[2].value.as< std::shared_ptr<yaramod::RegexpUnit> > ()), std::move(yystack_[1].value.as< std::pair<nonstd::optional<std::uint64_t>, nonstd::optional<std::uint64_t>> > ()), yystack_[0].value.as< bool > ());
		}
#line 2326 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 139:
#line 1189 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::move(yystack_[0].value.as< std::shared_ptr<yaramod::RegexpUnit> > ()); }
#line 2332 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 140:
#line 1190 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpWordBoundary>(); }
#line 2338 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 141:
#line 1191 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpNonWordBoundary>(); }
#line 2344 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 142:
#line 1192 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpStartOfLine>(); }
#line 2350 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 143:
#line 1193 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpEndOfLine>(); }
#line 2356 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 144:
#line 1197 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< bool > () = true; }
#line 2362 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 145:
#line 1198 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< bool > () = false; }
#line 2368 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 146:
#line 1202 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpGroup>(std::move(yystack_[1].value.as< std::shared_ptr<yaramod::RegexpUnit> > ())); }
#line 2374 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 147:
#line 1203 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpAnyChar>(); }
#line 2380 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 148:
#line 1204 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpText>(std::move(yystack_[0].value.as< std::string > ())); }
#line 2386 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 149:
#line 1205 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpWordChar>(); }
#line 2392 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 150:
#line 1206 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpNonWordChar>(); }
#line 2398 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 151:
#line 1207 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpSpace>(); }
#line 2404 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 152:
#line 1208 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpNonSpace>(); }
#line 2410 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 153:
#line 1209 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpDigit>(); }
#line 2416 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 154:
#line 1210 "parser/yy/parser.y" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpNonDigit>(); }
#line 2422 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;

  case 155:
#line 1212 "parser/yy/parser.y" // lalr1.cc:859
    {
			// It is negative class
			if (yystack_[0].value.as< std::string > ()[0] == '^')
				yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpClass>(yystack_[0].value.as< std::string > ().substr(1, yystack_[0].value.as< std::string > ().length() - 1), true);
			else
				yylhs.value.as< std::shared_ptr<yaramod::RegexpUnit> > () = std::make_shared<RegexpClass>(std::move(yystack_[0].value.as< std::string > ()), false);
		}
#line 2434 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
    break;


#line 2438 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
   Parser ::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short int  Parser ::yypact_ninf_ = -188;

  const signed char  Parser ::yytable_ninf_ = -113;

  const short int
   Parser ::yypact_[] =
  {
    -188,    98,  -188,  -188,  -188,  -188,   -52,  -188,  -188,    -9,
    -188,  -188,   -37,  -188,    47,    48,    94,  -188,    57,   103,
    -188,   119,   136,  -188,   130,   141,   116,  -188,   167,   152,
     184,   172,   102,  -188,   140,   228,   171,   171,   102,  -188,
    -188,   102,  -188,  -188,   150,  -188,  -188,  -188,  -188,  -188,
    -188,   139,   187,   218,  -188,  -188,   281,   161,   252,   257,
      -1,  -188,  -188,  -188,  -188,  -188,  -188,    75,   171,  -188,
    -188,    93,   233,  -188,   336,    78,    23,   171,   283,   171,
     171,   171,   102,   102,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   263,   108,   253,   102,   171,  -188,  -188,  -188,  -188,
     297,  -188,  -188,   108,  -188,    23,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,   275,
     258,    23,  -188,   112,   336,   171,  -188,    -3,    65,   310,
    -188,   301,   336,   336,   336,   336,   336,   336,    20,    20,
     202,   202,  -188,  -188,  -188,   355,   262,   346,   336,  -188,
     162,  -188,  -188,  -188,   161,     1,    76,   104,   247,   247,
    -188,   293,    46,  -188,    23,  -188,   296,   296,   296,   296,
     278,  -188,  -188,  -188,  -188,  -188,     2,  -188,   102,  -188,
    -188,   -31,    68,   350,   351,  -188,  -188,  -188,  -188,  -188,
    -188,   352,   356,  -188,    23,  -188,  -188,  -188,  -188,  -188,
     171,  -188,   165,   161,    49,     3,  -188,  -188,  -188,  -188,
    -188,    49,   358,   171,  -188,   354,   323,  -188,  -188,   128,
    -188,  -188,  -188,  -188,  -188,  -188,   357,   359,   102,   278,
       4,   361,  -188,   308,   114,    49,   106,  -188,   171,   102,
    -188,  -188,   109,  -188,   336,   110,  -188,   316,  -188,  -188
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       5,    12,     1,     4,    11,    10,     0,     3,     2,     0,
       6,     7,     0,     8,    14,     0,     0,    16,    13,    18,
      15,     0,    22,    20,     0,     0,    17,    24,     0,     0,
       0,    21,     0,     9,     0,     0,     0,     0,     0,   107,
     108,     0,    80,    81,     0,    54,    53,   128,    57,    55,
      56,    31,    61,    59,    58,    92,     0,    29,    50,     0,
      76,    30,    77,   104,   105,    19,   106,     0,     0,    63,
      72,     0,    50,    39,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,     0,    26,   103,    23,   103,
       0,    51,    52,     0,    34,     0,   142,   143,   147,   149,
     150,   151,   152,   153,   154,   140,   141,   148,   155,     0,
     130,   131,   133,   139,    32,     0,    33,     0,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    73,    74,
      65,    64,    66,    67,    68,    69,    70,    71,    48,    49,
       0,    87,    38,    93,    97,     0,     0,     0,    25,    28,
      36,     0,     0,   129,     0,   134,   144,   144,   144,   144,
       0,    62,    60,    75,    88,    89,     0,    95,     0,    94,
     120,     0,     0,     0,   120,   111,   112,    99,   101,   100,
     102,     0,     0,   146,   132,   145,   135,   136,   137,   138,
       0,    86,     0,    96,   122,     0,   116,   115,   114,   113,
      27,     0,     0,     0,    83,     0,     0,    90,    91,     0,
     117,   118,   119,   121,   120,   110,   117,   118,     0,    84,
       0,     0,    78,     0,     0,   123,     0,    82,     0,     0,
     127,   124,     0,    37,    85,     0,   126,     0,    35,   125
  };

  const short int
   Parser ::yypgoto_[] =
  {
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,   -17,  -188,  -188,   -36,
     185,   344,  -188,  -188,   276,  -188,  -188,  -188,   282,  -188,
     360,  -188,   169,  -148,  -187,  -147,  -188,  -188,   -62,  -188,
    -188,   277,   219,  -128,   124,  -188
  };

  const short int
   Parser ::yydefgoto_[] =
  {
      -1,     1,     7,     8,    12,    14,     9,    16,    18,    22,
      26,    25,    31,   108,   167,    29,    57,   171,   201,    58,
     136,    59,   225,   240,   162,   186,    60,   165,   168,    65,
      61,   193,   194,   230,   214,   231,   215,   232,    62,    76,
     129,   130,   131,   132,   206,   133
  };

  const short int
   Parser ::yytable_[] =
  {
      69,    70,    72,   175,   103,   109,    10,   221,    74,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   195,
     196,    71,   104,    11,    73,   187,   211,   233,   247,    13,
     188,   212,   110,   248,    92,    93,    94,    95,    96,   159,
     216,   134,   217,   137,   138,   139,   115,   245,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   140,   141,   181,   105,   166,
     203,   234,   190,   236,   237,    15,   175,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   164,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,     2,   180,
     106,     3,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    17,   128,    36,   111,   229,    19,
     191,   174,   192,    20,    37,    38,   113,   190,     4,     5,
     253,   160,    47,   107,   258,   182,    21,    82,    83,   218,
       6,   219,    39,    40,   114,    41,   189,    23,    42,    43,
      82,    83,    44,    45,    82,    83,    46,   161,    27,    47,
      48,    49,    50,    51,    36,    52,    53,    54,    55,    56,
      24,   213,    37,    68,   226,   191,    28,   192,    33,   256,
      39,    40,    30,   257,   251,    36,   252,   239,   176,   177,
     178,    77,    78,    37,    68,    32,    42,    43,    63,    64,
     243,    45,   244,   179,    46,    82,    83,    47,    48,    49,
      50,    34,   254,    52,    53,    54,    55,    56,    94,    95,
      96,   246,    45,   184,   185,    46,   227,   228,    47,    48,
      49,    50,   255,    35,    52,    53,    54,    55,    56,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,    67,    79,   112,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,    90,    91,    92,    93,    94,    95,
      96,   -79,   210,   197,   198,   199,   200,    80,   100,   101,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     -79,   207,   208,   209,    81,   102,   135,   100,   101,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   163,
      47,   112,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   173,   174,   183,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,    82,   202,   242,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    90,    91,    92,
      93,    94,    95,    96,   205,    98,   220,  -109,   250,   223,
     222,   238,   241,  -111,   249,  -112,   259,   224,    75,   170,
     235,   169,   172,   204,    66
  };

  const unsigned char
   Parser ::yycheck_[] =
  {
      36,    37,    38,   131,     5,    67,    58,   194,    44,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   167,
     167,    38,    23,    32,    41,    24,    24,    24,    24,    66,
      29,    29,    68,    29,    14,    15,    16,    17,    18,   101,
      71,    77,    73,    79,    80,    81,    23,   234,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    82,    83,    70,    69,   105,
      24,    68,    23,   221,   221,    28,   204,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   104,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,   135,
      25,     3,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    66,    92,    14,    24,    69,    25,
      71,    75,    73,    66,    22,    23,    48,    23,    30,    31,
      24,    23,    57,    58,    24,    70,    33,    44,    45,    71,
      42,    73,    40,    41,    66,    43,    70,    28,    46,    47,
      44,    45,    50,    51,    44,    45,    54,    49,    28,    57,
      58,    59,    60,    61,    14,    63,    64,    65,    66,    67,
      34,   188,    22,    23,   210,    71,    35,    73,    26,    70,
      40,    41,    66,    74,    70,    14,    72,   223,    76,    77,
      78,    52,    53,    22,    23,    28,    46,    47,    58,    59,
      72,    51,    74,    91,    54,    44,    45,    57,    58,    59,
      60,    27,   248,    63,    64,    65,    66,    67,    16,    17,
      18,   238,    51,    61,    62,    54,    61,    62,    57,    58,
      59,    60,   249,    61,    63,    64,    65,    66,    67,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    27,    69,    24,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    12,    13,    14,    15,    16,    17,
      18,    48,     4,    36,    37,    38,    39,    69,    55,    56,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      48,   177,   178,   179,    23,    48,    23,    55,    56,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    66,
      57,    24,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    57,    75,    24,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    44,    53,    24,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    12,    13,    14,
      15,    16,    17,    18,    78,    20,    26,    26,    70,    23,
      28,    23,    28,    26,    23,    26,    70,   202,    44,   113,
     221,   109,   115,   174,    34
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,    95,     0,     3,    30,    31,    42,    96,    97,   100,
      58,    32,    98,    66,    99,    28,   101,    66,   102,    25,
      66,    33,   103,    28,    34,   105,   104,    28,    35,   109,
      66,   106,    28,    26,    27,    61,    14,    22,    23,    40,
      41,    43,    46,    47,    50,    51,    54,    57,    58,    59,
      60,    61,    63,    64,    65,    66,    67,   110,   113,   115,
     120,   124,   132,    58,    59,   123,   124,    27,    23,   113,
     113,   110,   113,   110,   113,   115,   133,    52,    53,    69,
      69,    23,    44,    45,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      55,    56,    48,     5,    23,    69,    25,    58,   107,   132,
     113,    24,    24,    48,    66,    23,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    92,   134,
     135,   136,   137,   139,   113,    23,   114,   113,   113,   113,
     110,   110,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   132,
      23,    49,   118,    66,   110,   121,   113,   108,   122,   122,
     118,   111,   135,    57,    75,   137,    76,    77,    78,    91,
     113,    70,    70,    24,    61,    62,   119,    24,    29,    70,
      23,    71,    73,   125,   126,   127,   129,    36,    37,    38,
      39,   112,    53,    24,   136,    78,   138,   138,   138,   138,
       4,    24,    29,   110,   128,   130,    71,    73,    71,    73,
      26,   128,    28,    23,   114,   116,   113,    61,    62,    69,
     127,   129,   131,    24,    68,   126,   127,   129,    23,   113,
     117,    28,    24,    72,    74,   128,   110,    24,    29,    23,
      70,    70,    72,    24,   113,   110,    70,    74,    24,    70
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    94,    95,    95,    95,    95,    96,    98,    99,    97,
     100,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   108,   107,   107,   109,
     110,   110,   110,   110,   111,   110,   112,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   114,   115,
     115,   115,   116,   116,   117,   117,   118,   118,   119,   119,
     119,   119,   120,   120,   120,   120,   121,   121,   121,   122,
     122,   122,   122,   122,   123,   123,   123,   124,   124,   125,
     125,   126,   126,   127,   127,   127,   127,   128,   128,   128,
     128,   129,   130,   130,   131,   131,   131,   131,   133,   132,
     134,   135,   135,   136,   136,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   138,   138,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139
  };

  const unsigned char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     2,     2,     0,     2,     0,     0,    11,
       1,     1,     0,     2,     0,     2,     1,     3,     0,     4,
       0,     3,     0,     4,     0,     2,     0,     4,     2,     3,
       1,     1,     3,     3,     0,    10,     0,     9,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     4,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     4,     1,     1,     5,     1,
       1,     1,     3,     1,     1,     3,     3,     1,     1,     1,
       3,     3,     1,     3,     4,     4,     3,     1,     0,     2,
       2,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       0,     3,     1,     3,     3,     5,     4,     3,     0,     4,
       1,     1,     3,     1,     2,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     0,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "$end", "error", "$undefined", "END", "RANGE", "DOT", "LT", "GT", "LE",
  "GE", "EQ", "NEQ", "SHIFT_LEFT", "SHIFT_RIGHT", "MINUS", "PLUS",
  "MULTIPLY", "DIVIDE", "MODULO", "BITWISE_XOR", "BITWISE_AND",
  "BITWISE_OR", "BITWISE_NOT", "LP", "RP", "LCB", "RCB", "ASSIGN", "COLON",
  "COMMA", "PRIVATE", "GLOBAL", "RULE", "META", "STRINGS", "CONDITION",
  "ASCII", "NOCASE", "WIDE", "FULLWORD", "BOOL_TRUE", "BOOL_FALSE",
  "IMPORT_MODULE", "NOT", "AND", "OR", "ALL", "ANY", "OF", "THEM", "FOR",
  "ENTRYPOINT", "OP_AT", "OP_IN", "FILESIZE", "CONTAINS", "MATCHES",
  "SLASH", "STRING_LITERAL", "INTEGER", "DOUBLE", "STRING_ID",
  "STRING_ID_WILDCARD", "STRING_LENGTH", "STRING_OFFSET", "STRING_COUNT",
  "ID", "INTEGER_FUNCTION", "HEX_OR", "LSQB", "RSQB", "HEX_WILDCARD",
  "DASH", "HEX_NIBBLE", "HEX_INTEGER", "REGEXP_OR", "REGEXP_ITER",
  "REGEXP_PITER", "REGEXP_OPTIONAL", "REGEXP_START_OF_LINE",
  "REGEXP_END_OF_LINE", "REGEXP_ANY_CHAR", "REGEXP_WORD_CHAR",
  "REGEXP_NON_WORD_CHAR", "REGEXP_SPACE", "REGEXP_NON_SPACE",
  "REGEXP_DIGIT", "REGEXP_NON_DIGIT", "REGEXP_WORD_BOUNDARY",
  "REGEXP_NON_WORD_BOUNDARY", "REGEXP_CHAR", "REGEXP_RANGE",
  "REGEXP_CLASS", "UNARY_MINUS", "$accept", "rules", "import", "rule",
  "$@1", "$@2", "rule_mod", "tags", "tag_list", "metas", "metas_body",
  "strings", "strings_body", "string", "$@3", "condition", "expression",
  "$@4", "$@5", "primary_expression", "range", "for_expression",
  "integer_set", "integer_enumeration", "string_set", "string_enumeration",
  "identifier", "arguments", "string_mods", "literal", "boolean",
  "hex_string", "hex_string_edge", "hex_byte", "hex_string_body", "hex_or",
  "hex_or_body", "hex_jump", "regexp", "$@6", "regexp_body", "regexp_or",
  "regexp_concat", "regexp_repeat", "regexp_greedy", "regexp_single", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
   Parser ::yyrline_[] =
  {
       0,   195,   195,   196,   197,   198,   202,   214,   218,   213,
     232,   233,   234,   238,   239,   243,   248,   252,   253,   257,
     262,   266,   267,   275,   286,   294,   300,   299,   308,   316,
     320,   325,   336,   353,   365,   364,   381,   380,   397,   402,
     407,   412,   417,   422,   427,   432,   437,   442,   447,   464,
     476,   480,   489,   495,   500,   505,   510,   515,   520,   535,
     550,   565,   580,   595,   607,   625,   643,   661,   679,   696,
     713,   730,   747,   758,   775,   792,   803,   807,   815,   834,
     835,   836,   840,   841,   845,   855,   869,   870,   874,   884,
     894,   905,   919,   931,   958,   977,  1014,  1019,  1020,  1024,
    1025,  1026,  1027,  1028,  1032,  1033,  1034,  1038,  1039,  1043,
    1044,  1053,  1054,  1058,  1066,  1074,  1082,  1093,  1098,  1103,
    1108,  1112,  1115,  1120,  1129,  1130,  1131,  1132,  1137,  1136,
    1148,  1152,  1153,  1161,  1162,  1170,  1171,  1172,  1173,  1189,
    1190,  1191,  1192,  1193,  1197,  1198,  1202,  1203,  1204,  1205,
    1206,  1207,  1208,  1209,  1210,  1211
  };

  // Print the state stack on the debug stream.
  void
   Parser ::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
   Parser ::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 46 "parser/yy/parser.y" // lalr1.cc:1167
} } //  yaramod::yy 
#line 3031 "/home/fortyfunbobby/hackthebox/scripts/reverse-tools/retdec/retdec-master/build/external/src/yaramod-project-build/src/yaramod/yy/yy_parser.cpp" // lalr1.cc:1167
#line 1221 "parser/yy/parser.y" // lalr1.cc:1168


// Bison expects implementation of error method by us
void yy::Parser::error(const yy::location& loc, const std::string& message)
{
	std::ostringstream os;
	os << "Error at " << loc << ": " << message;
	throw ParserError(os.str());
}
