inherit "/players/kryll/test/std_book";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Book of Player Rules");
  set_short("Book of Player Rules");
  set_alias("book");
  set_pages(10);
  set_book("/doc/rules/pbook/pbook");
}
