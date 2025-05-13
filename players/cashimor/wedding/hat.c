inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("hat");
    set_type("helmet");
    set_ac(1);
    set_short("A black hat");
    set_long("This is a black hat of poor quality. Although the quality is\n"
           + "bad, it still looks great!\n");
    set_value(25);
    set_weight(1);
    set_info("Used on Cashimor's wedding.");
    set_read("Original design by Mauer.\n");
  }
}

extra_look() {
  if(!worn) return;
  return capitalize(worn_by->query_pronoun())+" is wearing an "
       + "interesting black hat";
}
