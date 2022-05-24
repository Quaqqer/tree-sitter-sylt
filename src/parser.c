#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 16
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 25
#define ALIAS_COUNT 0
#define TOKEN_COUNT 16
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 2

enum {
  sym_identifier = 1,
  anon_sym_void = 2,
  anon_sym_bool = 3,
  anon_sym_int = 4,
  anon_sym_float = 5,
  anon_sym_str = 6,
  anon_sym_COLON = 7,
  sym_int = 8,
  aux_sym_float_token1 = 9,
  aux_sym_float_token2 = 10,
  aux_sym_float_token3 = 11,
  sym_nil = 12,
  anon_sym_true = 13,
  anon_sym_false = 14,
  sym_str = 15,
  sym_source_file = 16,
  sym_type_primitive = 17,
  sym_type = 18,
  sym_outer_statement = 19,
  sym_assignment = 20,
  sym_float = 21,
  sym_bool = 22,
  sym_expression = 23,
  aux_sym_source_file_repeat1 = 24,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_void] = "void",
  [anon_sym_bool] = "bool",
  [anon_sym_int] = "int",
  [anon_sym_float] = "float",
  [anon_sym_str] = "str",
  [anon_sym_COLON] = ":",
  [sym_int] = "int",
  [aux_sym_float_token1] = "float_token1",
  [aux_sym_float_token2] = "float_token2",
  [aux_sym_float_token3] = "float_token3",
  [sym_nil] = "nil",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_str] = "str",
  [sym_source_file] = "source_file",
  [sym_type_primitive] = "type_primitive",
  [sym_type] = "type",
  [sym_outer_statement] = "outer_statement",
  [sym_assignment] = "assignment",
  [sym_float] = "float",
  [sym_bool] = "bool",
  [sym_expression] = "expression",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_void] = anon_sym_void,
  [anon_sym_bool] = anon_sym_bool,
  [anon_sym_int] = anon_sym_int,
  [anon_sym_float] = anon_sym_float,
  [anon_sym_str] = anon_sym_str,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_int] = sym_int,
  [aux_sym_float_token1] = aux_sym_float_token1,
  [aux_sym_float_token2] = aux_sym_float_token2,
  [aux_sym_float_token3] = aux_sym_float_token3,
  [sym_nil] = sym_nil,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_str] = sym_str,
  [sym_source_file] = sym_source_file,
  [sym_type_primitive] = sym_type_primitive,
  [sym_type] = sym_type,
  [sym_outer_statement] = sym_outer_statement,
  [sym_assignment] = sym_assignment,
  [sym_float] = sym_float,
  [sym_bool] = sym_bool,
  [sym_expression] = sym_expression,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
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
  [anon_sym_void] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bool] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_str] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
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
  [sym_type_primitive] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym_outer_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_assignment] = {
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
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_expression = 1,
  field_mutability = 2,
  field_name = 3,
  field_type = 4,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_expression] = "expression",
  [field_mutability] = "mutability",
  [field_name] = "name",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 4},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_expression, 4},
    {field_mutability, 3},
    {field_name, 0},
    {field_type, 2},
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
      if (eof) ADVANCE(28);
      if (lookahead == '"') ADVANCE(1);
      if (lookahead == '.') ADVANCE(25);
      if (lookahead == ':') ADVANCE(35);
      if (lookahead == 'b') ADVANCE(15);
      if (lookahead == 'f') ADVANCE(2);
      if (lookahead == 'i') ADVANCE(12);
      if (lookahead == 'n') ADVANCE(8);
      if (lookahead == 's') ADVANCE(22);
      if (lookahead == 't') ADVANCE(17);
      if (lookahead == 'v') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(36);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(43);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == 'a') ADVANCE(9);
      if (lookahead == 'l') ADVANCE(13);
      END_STATE();
    case 3:
      if (lookahead == 'a') ADVANCE(21);
      END_STATE();
    case 4:
      if (lookahead == 'd') ADVANCE(30);
      END_STATE();
    case 5:
      if (lookahead == 'e') ADVANCE(41);
      END_STATE();
    case 6:
      if (lookahead == 'e') ADVANCE(42);
      END_STATE();
    case 7:
      if (lookahead == 'i') ADVANCE(4);
      END_STATE();
    case 8:
      if (lookahead == 'i') ADVANCE(10);
      END_STATE();
    case 9:
      if (lookahead == 'l') ADVANCE(19);
      END_STATE();
    case 10:
      if (lookahead == 'l') ADVANCE(40);
      END_STATE();
    case 11:
      if (lookahead == 'l') ADVANCE(31);
      END_STATE();
    case 12:
      if (lookahead == 'n') ADVANCE(20);
      END_STATE();
    case 13:
      if (lookahead == 'o') ADVANCE(3);
      END_STATE();
    case 14:
      if (lookahead == 'o') ADVANCE(7);
      END_STATE();
    case 15:
      if (lookahead == 'o') ADVANCE(16);
      END_STATE();
    case 16:
      if (lookahead == 'o') ADVANCE(11);
      END_STATE();
    case 17:
      if (lookahead == 'r') ADVANCE(23);
      END_STATE();
    case 18:
      if (lookahead == 'r') ADVANCE(34);
      END_STATE();
    case 19:
      if (lookahead == 's') ADVANCE(6);
      END_STATE();
    case 20:
      if (lookahead == 't') ADVANCE(32);
      END_STATE();
    case 21:
      if (lookahead == 't') ADVANCE(33);
      END_STATE();
    case 22:
      if (lookahead == 't') ADVANCE(18);
      END_STATE();
    case 23:
      if (lookahead == 'u') ADVANCE(5);
      END_STATE();
    case 24:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(39);
      END_STATE();
    case 25:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(38);
      END_STATE();
    case 26:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(39);
      END_STATE();
    case 27:
      if (eof) ADVANCE(28);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(27)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_void);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_bool);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_float);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_str);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_int);
      if (lookahead == '.') ADVANCE(37);
      if (lookahead == 'e') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(36);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(aux_sym_float_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(37);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(aux_sym_float_token2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(38);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym_float_token3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(39);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_nil);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_str);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 27},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 27},
  [5] = {.lex_state = 27},
  [6] = {.lex_state = 27},
  [7] = {.lex_state = 27},
  [8] = {.lex_state = 27},
  [9] = {.lex_state = 27},
  [10] = {.lex_state = 27},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_void] = ACTIONS(1),
    [anon_sym_bool] = ACTIONS(1),
    [anon_sym_int] = ACTIONS(1),
    [anon_sym_float] = ACTIONS(1),
    [anon_sym_str] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
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
    [sym_source_file] = STATE(12),
    [sym_outer_statement] = STATE(4),
    [sym_assignment] = STATE(6),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_identifier] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(7), 1,
      sym_int,
    ACTIONS(11), 1,
      aux_sym_float_token2,
    STATE(10), 1,
      sym_expression,
    ACTIONS(9), 2,
      aux_sym_float_token1,
      aux_sym_float_token3,
    ACTIONS(13), 2,
      sym_nil,
      sym_str,
    ACTIONS(15), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(7), 2,
      sym_float,
      sym_bool,
  [26] = 3,
    STATE(14), 1,
      sym_type_primitive,
    STATE(15), 1,
      sym_type,
    ACTIONS(17), 5,
      anon_sym_void,
      anon_sym_bool,
      anon_sym_int,
      anon_sym_float,
      anon_sym_str,
  [40] = 4,
    ACTIONS(5), 1,
      sym_identifier,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    STATE(6), 1,
      sym_assignment,
    STATE(5), 2,
      sym_outer_statement,
      aux_sym_source_file_repeat1,
  [54] = 4,
    ACTIONS(21), 1,
      ts_builtin_sym_end,
    ACTIONS(23), 1,
      sym_identifier,
    STATE(6), 1,
      sym_assignment,
    STATE(5), 2,
      sym_outer_statement,
      aux_sym_source_file_repeat1,
  [68] = 1,
    ACTIONS(26), 2,
      ts_builtin_sym_end,
      sym_identifier,
  [73] = 1,
    ACTIONS(28), 2,
      ts_builtin_sym_end,
      sym_identifier,
  [78] = 1,
    ACTIONS(30), 2,
      ts_builtin_sym_end,
      sym_identifier,
  [83] = 1,
    ACTIONS(32), 2,
      ts_builtin_sym_end,
      sym_identifier,
  [88] = 1,
    ACTIONS(34), 2,
      ts_builtin_sym_end,
      sym_identifier,
  [93] = 1,
    ACTIONS(36), 1,
      anon_sym_COLON,
  [97] = 1,
    ACTIONS(38), 1,
      ts_builtin_sym_end,
  [101] = 1,
    ACTIONS(40), 1,
      anon_sym_COLON,
  [105] = 1,
    ACTIONS(42), 1,
      anon_sym_COLON,
  [109] = 1,
    ACTIONS(44), 1,
      anon_sym_COLON,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 26,
  [SMALL_STATE(4)] = 40,
  [SMALL_STATE(5)] = 54,
  [SMALL_STATE(6)] = 68,
  [SMALL_STATE(7)] = 73,
  [SMALL_STATE(8)] = 78,
  [SMALL_STATE(9)] = 83,
  [SMALL_STATE(10)] = 88,
  [SMALL_STATE(11)] = 93,
  [SMALL_STATE(12)] = 97,
  [SMALL_STATE(13)] = 101,
  [SMALL_STATE(14)] = 105,
  [SMALL_STATE(15)] = 109,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(11),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_outer_statement, 1),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float, 1),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool, 1),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment, 5, .production_id = 1),
  [36] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [38] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_primitive, 1),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
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
