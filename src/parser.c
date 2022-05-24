#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 37
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 37
#define ALIAS_COUNT 0
#define TOKEN_COUNT 21
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 5
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 7

enum {
  sym_identifier = 1,
  sym_t_void = 2,
  sym_t_bool = 3,
  sym_t_int = 4,
  sym_t_float = 5,
  sym_t_str = 6,
  anon_sym_COLON = 7,
  anon_sym_COMMA = 8,
  anon_sym_fn = 9,
  anon_sym_DASH_GT = 10,
  anon_sym_pu = 11,
  anon_sym_EQ = 12,
  sym_int = 13,
  aux_sym_float_token1 = 14,
  aux_sym_float_token2 = 15,
  aux_sym_float_token3 = 16,
  sym_nil = 17,
  anon_sym_true = 18,
  anon_sym_false = 19,
  sym_str = 20,
  sym_source_file = 21,
  sym__type_primitive = 22,
  sym_parameter = 23,
  sym_parameters = 24,
  sym_t_fn = 25,
  sym_t_pu = 26,
  sym__type = 27,
  sym__outer_statement = 28,
  sym__declaration = 29,
  sym_const_declaration = 30,
  sym_mut_declaration = 31,
  sym_float = 32,
  sym_bool = 33,
  sym__expression = 34,
  aux_sym_source_file_repeat1 = 35,
  aux_sym_parameters_repeat1 = 36,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [sym_t_void] = "t_void",
  [sym_t_bool] = "t_bool",
  [sym_t_int] = "t_int",
  [sym_t_float] = "t_float",
  [sym_t_str] = "t_str",
  [anon_sym_COLON] = ":",
  [anon_sym_COMMA] = ",",
  [anon_sym_fn] = "fn",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_pu] = "pu",
  [anon_sym_EQ] = "=",
  [sym_int] = "int",
  [aux_sym_float_token1] = "float_token1",
  [aux_sym_float_token2] = "float_token2",
  [aux_sym_float_token3] = "float_token3",
  [sym_nil] = "nil",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_str] = "str",
  [sym_source_file] = "source_file",
  [sym__type_primitive] = "_type_primitive",
  [sym_parameter] = "parameter",
  [sym_parameters] = "parameters",
  [sym_t_fn] = "t_fn",
  [sym_t_pu] = "t_pu",
  [sym__type] = "_type",
  [sym__outer_statement] = "_outer_statement",
  [sym__declaration] = "_declaration",
  [sym_const_declaration] = "const_declaration",
  [sym_mut_declaration] = "mut_declaration",
  [sym_float] = "float",
  [sym_bool] = "bool",
  [sym__expression] = "_expression",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_parameters_repeat1] = "parameters_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [sym_t_void] = sym_t_void,
  [sym_t_bool] = sym_t_bool,
  [sym_t_int] = sym_t_int,
  [sym_t_float] = sym_t_float,
  [sym_t_str] = sym_t_str,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_fn] = anon_sym_fn,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_pu] = anon_sym_pu,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_int] = sym_int,
  [aux_sym_float_token1] = aux_sym_float_token1,
  [aux_sym_float_token2] = aux_sym_float_token2,
  [aux_sym_float_token3] = aux_sym_float_token3,
  [sym_nil] = sym_nil,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_str] = sym_str,
  [sym_source_file] = sym_source_file,
  [sym__type_primitive] = sym__type_primitive,
  [sym_parameter] = sym_parameter,
  [sym_parameters] = sym_parameters,
  [sym_t_fn] = sym_t_fn,
  [sym_t_pu] = sym_t_pu,
  [sym__type] = sym__type,
  [sym__outer_statement] = sym__outer_statement,
  [sym__declaration] = sym__declaration,
  [sym_const_declaration] = sym_const_declaration,
  [sym_mut_declaration] = sym_mut_declaration,
  [sym_float] = sym_float,
  [sym_bool] = sym_bool,
  [sym__expression] = sym__expression,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_parameters_repeat1] = aux_sym_parameters_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_t_void] = {
    .visible = true,
    .named = true,
  },
  [sym_t_bool] = {
    .visible = true,
    .named = true,
  },
  [sym_t_int] = {
    .visible = true,
    .named = true,
  },
  [sym_t_float] = {
    .visible = true,
    .named = true,
  },
  [sym_t_str] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fn] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pu] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym_int] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_float_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_float_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_float_token3] = {
    .visible = false,
    .named = false,
  },
  [sym_nil] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_str] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__type_primitive] = {
    .visible = false,
    .named = true,
  },
  [sym_parameter] = {
    .visible = true,
    .named = true,
  },
  [sym_parameters] = {
    .visible = true,
    .named = true,
  },
  [sym_t_fn] = {
    .visible = true,
    .named = true,
  },
  [sym_t_pu] = {
    .visible = true,
    .named = true,
  },
  [sym__type] = {
    .visible = false,
    .named = true,
  },
  [sym__outer_statement] = {
    .visible = false,
    .named = true,
  },
  [sym__declaration] = {
    .visible = false,
    .named = true,
  },
  [sym_const_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_mut_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_float] = {
    .visible = true,
    .named = true,
  },
  [sym_bool] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_parameters_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_expression = 1,
  field_name = 2,
  field_parameters = 3,
  field_return = 4,
  field_type = 5,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_expression] = "expression",
  [field_name] = "name",
  [field_parameters] = "parameters",
  [field_return] = "return",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 1},
  [3] = {.index = 3, .length = 1},
  [4] = {.index = 4, .length = 3},
  [5] = {.index = 7, .length = 3},
  [6] = {.index = 10, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_expression, 3},
    {field_name, 0},
  [2] =
    {field_name, 0},
  [3] =
    {field_return, 2},
  [4] =
    {field_expression, 4},
    {field_name, 0},
    {field_type, 2},
  [7] =
    {field_name, 0},
    {field_type, 1},
    {field_type, 2},
  [10] =
    {field_parameters, 1},
    {field_return, 3},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(30);
      if (lookahead == '"') ADVANCE(1);
      if (lookahead == ',') ADVANCE(38);
      if (lookahead == '-') ADVANCE(2);
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == ':') ADVANCE(37);
      if (lookahead == '=') ADVANCE(42);
      if (lookahead == 'b') ADVANCE(16);
      if (lookahead == 'f') ADVANCE(3);
      if (lookahead == 'i') ADVANCE(13);
      if (lookahead == 'n') ADVANCE(9);
      if (lookahead == 'p') ADVANCE(24);
      if (lookahead == 's') ADVANCE(23);
      if (lookahead == 't') ADVANCE(19);
      if (lookahead == 'v') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(43);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(50);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '>') ADVANCE(40);
      END_STATE();
    case 3:
      if (lookahead == 'a') ADVANCE(10);
      if (lookahead == 'l') ADVANCE(14);
      if (lookahead == 'n') ADVANCE(39);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(22);
      END_STATE();
    case 5:
      if (lookahead == 'd') ADVANCE(32);
      END_STATE();
    case 6:
      if (lookahead == 'e') ADVANCE(48);
      END_STATE();
    case 7:
      if (lookahead == 'e') ADVANCE(49);
      END_STATE();
    case 8:
      if (lookahead == 'i') ADVANCE(5);
      END_STATE();
    case 9:
      if (lookahead == 'i') ADVANCE(11);
      END_STATE();
    case 10:
      if (lookahead == 'l') ADVANCE(20);
      END_STATE();
    case 11:
      if (lookahead == 'l') ADVANCE(47);
      END_STATE();
    case 12:
      if (lookahead == 'l') ADVANCE(33);
      END_STATE();
    case 13:
      if (lookahead == 'n') ADVANCE(21);
      END_STATE();
    case 14:
      if (lookahead == 'o') ADVANCE(4);
      END_STATE();
    case 15:
      if (lookahead == 'o') ADVANCE(8);
      END_STATE();
    case 16:
      if (lookahead == 'o') ADVANCE(17);
      END_STATE();
    case 17:
      if (lookahead == 'o') ADVANCE(12);
      END_STATE();
    case 18:
      if (lookahead == 'r') ADVANCE(36);
      END_STATE();
    case 19:
      if (lookahead == 'r') ADVANCE(25);
      END_STATE();
    case 20:
      if (lookahead == 's') ADVANCE(7);
      END_STATE();
    case 21:
      if (lookahead == 't') ADVANCE(34);
      END_STATE();
    case 22:
      if (lookahead == 't') ADVANCE(35);
      END_STATE();
    case 23:
      if (lookahead == 't') ADVANCE(18);
      END_STATE();
    case 24:
      if (lookahead == 'u') ADVANCE(41);
      END_STATE();
    case 25:
      if (lookahead == 'u') ADVANCE(6);
      END_STATE();
    case 26:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(46);
      END_STATE();
    case 27:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(45);
      END_STATE();
    case 28:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(46);
      END_STATE();
    case 29:
      if (eof) ADVANCE(30);
      if (lookahead == ',') ADVANCE(38);
      if (lookahead == '-') ADVANCE(2);
      if (lookahead == ':') ADVANCE(37);
      if (lookahead == '=') ADVANCE(42);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(29)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(31);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_t_void);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_t_bool);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_t_int);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_t_float);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_t_str);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_pu);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_int);
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == 'e') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(43);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(aux_sym_float_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym_float_token2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(45);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym_float_token3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(46);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_nil);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_str);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 29},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 29},
  [13] = {.lex_state = 29},
  [14] = {.lex_state = 29},
  [15] = {.lex_state = 29},
  [16] = {.lex_state = 29},
  [17] = {.lex_state = 29},
  [18] = {.lex_state = 29},
  [19] = {.lex_state = 29},
  [20] = {.lex_state = 29},
  [21] = {.lex_state = 29},
  [22] = {.lex_state = 29},
  [23] = {.lex_state = 29},
  [24] = {.lex_state = 29},
  [25] = {.lex_state = 29},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 29},
  [28] = {.lex_state = 29},
  [29] = {.lex_state = 29},
  [30] = {.lex_state = 29},
  [31] = {.lex_state = 29},
  [32] = {.lex_state = 29},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_t_void] = ACTIONS(1),
    [sym_t_bool] = ACTIONS(1),
    [sym_t_int] = ACTIONS(1),
    [sym_t_float] = ACTIONS(1),
    [sym_t_str] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_fn] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_pu] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [sym_int] = ACTIONS(1),
    [aux_sym_float_token1] = ACTIONS(1),
    [aux_sym_float_token2] = ACTIONS(1),
    [aux_sym_float_token3] = ACTIONS(1),
    [sym_nil] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_str] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(34),
    [sym__outer_statement] = STATE(12),
    [sym__declaration] = STATE(12),
    [sym_const_declaration] = STATE(12),
    [sym_mut_declaration] = STATE(12),
    [aux_sym_source_file_repeat1] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_identifier] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 6,
    ACTIONS(9), 1,
      anon_sym_COLON,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      anon_sym_pu,
    ACTIONS(15), 1,
      anon_sym_EQ,
    STATE(26), 4,
      sym__type_primitive,
      sym_t_fn,
      sym_t_pu,
      sym__type,
    ACTIONS(7), 5,
      sym_t_void,
      sym_t_bool,
      sym_t_int,
      sym_t_float,
      sym_t_str,
  [26] = 4,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      anon_sym_pu,
    STATE(16), 4,
      sym__type_primitive,
      sym_t_fn,
      sym_t_pu,
      sym__type,
    ACTIONS(17), 5,
      sym_t_void,
      sym_t_bool,
      sym_t_int,
      sym_t_float,
      sym_t_str,
  [46] = 4,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      anon_sym_pu,
    STATE(17), 4,
      sym__type_primitive,
      sym_t_fn,
      sym_t_pu,
      sym__type,
    ACTIONS(19), 5,
      sym_t_void,
      sym_t_bool,
      sym_t_int,
      sym_t_float,
      sym_t_str,
  [66] = 4,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      anon_sym_pu,
    STATE(18), 4,
      sym__type_primitive,
      sym_t_fn,
      sym_t_pu,
      sym__type,
    ACTIONS(21), 5,
      sym_t_void,
      sym_t_bool,
      sym_t_int,
      sym_t_float,
      sym_t_str,
  [86] = 6,
    ACTIONS(23), 1,
      sym_int,
    ACTIONS(27), 1,
      aux_sym_float_token2,
    ACTIONS(25), 2,
      aux_sym_float_token1,
      aux_sym_float_token3,
    ACTIONS(29), 2,
      sym_nil,
      sym_str,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(27), 3,
      sym_float,
      sym_bool,
      sym__expression,
  [110] = 4,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      anon_sym_pu,
    STATE(24), 4,
      sym__type_primitive,
      sym_t_fn,
      sym_t_pu,
      sym__type,
    ACTIONS(33), 5,
      sym_t_void,
      sym_t_bool,
      sym_t_int,
      sym_t_float,
      sym_t_str,
  [130] = 6,
    ACTIONS(27), 1,
      aux_sym_float_token2,
    ACTIONS(35), 1,
      sym_int,
    ACTIONS(25), 2,
      aux_sym_float_token1,
      aux_sym_float_token3,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(37), 2,
      sym_nil,
      sym_str,
    STATE(32), 3,
      sym_float,
      sym_bool,
      sym__expression,
  [154] = 6,
    ACTIONS(27), 1,
      aux_sym_float_token2,
    ACTIONS(39), 1,
      sym_int,
    ACTIONS(25), 2,
      aux_sym_float_token1,
      aux_sym_float_token3,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(41), 2,
      sym_nil,
      sym_str,
    STATE(31), 3,
      sym_float,
      sym_bool,
      sym__expression,
  [178] = 6,
    ACTIONS(27), 1,
      aux_sym_float_token2,
    ACTIONS(43), 1,
      sym_int,
    ACTIONS(25), 2,
      aux_sym_float_token1,
      aux_sym_float_token3,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(45), 2,
      sym_nil,
      sym_str,
    STATE(30), 3,
      sym_float,
      sym_bool,
      sym__expression,
  [202] = 4,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      anon_sym_pu,
    STATE(19), 4,
      sym__type_primitive,
      sym_t_fn,
      sym_t_pu,
      sym__type,
    ACTIONS(47), 5,
      sym_t_void,
      sym_t_bool,
      sym_t_int,
      sym_t_float,
      sym_t_str,
  [222] = 3,
    ACTIONS(5), 1,
      sym_identifier,
    ACTIONS(49), 1,
      ts_builtin_sym_end,
    STATE(13), 5,
      sym__outer_statement,
      sym__declaration,
      sym_const_declaration,
      sym_mut_declaration,
      aux_sym_source_file_repeat1,
  [236] = 3,
    ACTIONS(51), 1,
      ts_builtin_sym_end,
    ACTIONS(53), 1,
      sym_identifier,
    STATE(13), 5,
      sym__outer_statement,
      sym__declaration,
      sym_const_declaration,
      sym_mut_declaration,
      aux_sym_source_file_repeat1,
  [250] = 6,
    ACTIONS(56), 1,
      sym_identifier,
    ACTIONS(58), 1,
      anon_sym_COMMA,
    ACTIONS(60), 1,
      anon_sym_DASH_GT,
    STATE(21), 1,
      aux_sym_parameters_repeat1,
    STATE(23), 1,
      sym_parameter,
    STATE(35), 1,
      sym_parameters,
  [269] = 6,
    ACTIONS(56), 1,
      sym_identifier,
    ACTIONS(58), 1,
      anon_sym_COMMA,
    ACTIONS(62), 1,
      anon_sym_DASH_GT,
    STATE(21), 1,
      aux_sym_parameters_repeat1,
    STATE(23), 1,
      sym_parameter,
    STATE(33), 1,
      sym_parameters,
  [288] = 1,
    ACTIONS(64), 5,
      sym_identifier,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
      anon_sym_EQ,
  [296] = 1,
    ACTIONS(66), 5,
      sym_identifier,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
      anon_sym_EQ,
  [304] = 1,
    ACTIONS(68), 5,
      sym_identifier,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
      anon_sym_EQ,
  [312] = 1,
    ACTIONS(70), 5,
      sym_identifier,
      anon_sym_COLON,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
      anon_sym_EQ,
  [320] = 2,
    ACTIONS(74), 1,
      anon_sym_COLON,
    ACTIONS(72), 3,
      sym_identifier,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
  [329] = 4,
    ACTIONS(56), 1,
      sym_identifier,
    ACTIONS(76), 1,
      anon_sym_COMMA,
    STATE(22), 1,
      aux_sym_parameters_repeat1,
    STATE(25), 1,
      sym_parameter,
  [342] = 3,
    ACTIONS(78), 1,
      sym_identifier,
    ACTIONS(81), 1,
      anon_sym_COMMA,
    STATE(22), 2,
      sym_parameter,
      aux_sym_parameters_repeat1,
  [353] = 2,
    ACTIONS(86), 1,
      anon_sym_DASH_GT,
    ACTIONS(84), 2,
      sym_identifier,
      anon_sym_COMMA,
  [361] = 1,
    ACTIONS(88), 3,
      sym_identifier,
      anon_sym_COMMA,
      anon_sym_DASH_GT,
  [367] = 2,
    ACTIONS(90), 1,
      anon_sym_DASH_GT,
    ACTIONS(84), 2,
      sym_identifier,
      anon_sym_COMMA,
  [375] = 2,
    ACTIONS(92), 1,
      anon_sym_COLON,
    ACTIONS(94), 1,
      anon_sym_EQ,
  [382] = 1,
    ACTIONS(96), 2,
      ts_builtin_sym_end,
      sym_identifier,
  [387] = 1,
    ACTIONS(98), 2,
      ts_builtin_sym_end,
      sym_identifier,
  [392] = 1,
    ACTIONS(100), 2,
      ts_builtin_sym_end,
      sym_identifier,
  [397] = 1,
    ACTIONS(102), 2,
      ts_builtin_sym_end,
      sym_identifier,
  [402] = 1,
    ACTIONS(104), 2,
      ts_builtin_sym_end,
      sym_identifier,
  [407] = 1,
    ACTIONS(106), 2,
      ts_builtin_sym_end,
      sym_identifier,
  [412] = 1,
    ACTIONS(108), 1,
      anon_sym_DASH_GT,
  [416] = 1,
    ACTIONS(110), 1,
      ts_builtin_sym_end,
  [420] = 1,
    ACTIONS(112), 1,
      anon_sym_DASH_GT,
  [424] = 1,
    ACTIONS(114), 1,
      anon_sym_COLON,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 26,
  [SMALL_STATE(4)] = 46,
  [SMALL_STATE(5)] = 66,
  [SMALL_STATE(6)] = 86,
  [SMALL_STATE(7)] = 110,
  [SMALL_STATE(8)] = 130,
  [SMALL_STATE(9)] = 154,
  [SMALL_STATE(10)] = 178,
  [SMALL_STATE(11)] = 202,
  [SMALL_STATE(12)] = 222,
  [SMALL_STATE(13)] = 236,
  [SMALL_STATE(14)] = 250,
  [SMALL_STATE(15)] = 269,
  [SMALL_STATE(16)] = 288,
  [SMALL_STATE(17)] = 296,
  [SMALL_STATE(18)] = 304,
  [SMALL_STATE(19)] = 312,
  [SMALL_STATE(20)] = 320,
  [SMALL_STATE(21)] = 329,
  [SMALL_STATE(22)] = 342,
  [SMALL_STATE(23)] = 353,
  [SMALL_STATE(24)] = 361,
  [SMALL_STATE(25)] = 367,
  [SMALL_STATE(26)] = 375,
  [SMALL_STATE(27)] = 382,
  [SMALL_STATE(28)] = 387,
  [SMALL_STATE(29)] = 392,
  [SMALL_STATE(30)] = 397,
  [SMALL_STATE(31)] = 402,
  [SMALL_STATE(32)] = 407,
  [SMALL_STATE(33)] = 412,
  [SMALL_STATE(34)] = 416,
  [SMALL_STATE(35)] = 420,
  [SMALL_STATE(36)] = 424,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(36),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_t_fn, 3, .production_id = 3),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_t_pu, 4, .production_id = 6),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_t_fn, 4, .production_id = 6),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_t_pu, 3, .production_id = 3),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 1, .production_id = 2),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2), SHIFT_REPEAT(20),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2), SHIFT_REPEAT(22),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 1),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 1),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 3, .production_id = 5),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 2),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_declaration, 4, .production_id = 1),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float, 1),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool, 1),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_declaration, 5, .production_id = 4),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mut_declaration, 5, .production_id = 4),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mut_declaration, 4, .production_id = 1),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [110] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_sylt(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
