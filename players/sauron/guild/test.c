object test() {
  return previous_object();
}

int main() {
  write(test());
  write("\n");
  return 1;
}

void init() {
  add_action("main","test");
}
