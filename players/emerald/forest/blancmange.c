int id(string str) {
  return str=="blancmange_curse";
}

string extra_look() {
  return (string)environment()->query_name() + " is covered in pink smudges";
}

int drop() {
  return 1;
}
