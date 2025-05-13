inherit "/obj/treasure";

int get() {
  write("Removing the wreath would not feel right to you.\n");
  return 0;
}

int drop() {
  return 0;
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_name("wreath");
    set_short("A wreath, in memorium of Diana, Princess of Wales.");
    set_long("A beautiful wreath of white lillies has been placed on the \
floor of the church. A note reads \"In memorium Diana, Princess of \
Wales. May she rest in peace. She will never be forgotten.\"\n");
  }
}
