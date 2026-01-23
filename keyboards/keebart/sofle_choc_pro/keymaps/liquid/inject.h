switch (combo_index) {
  // paste from clipboard surrounded by markdown link with label "here"
  case CMB_HJ_HERE:
    if (!pressed) {
      SEND_STRING("[here](" SS_LCTL("v") ")");
    }
    break;

  // cut out marked text and paste it surrounded by grv quotes
  case CMB_J_GRVWP:
    if (!pressed) {
      SEND_STRING(SS_LCTL("x") "`" SS_LCTL("v") "`");
    }
    break;
}
