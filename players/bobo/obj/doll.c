inherit "/obj/treasure";
reset (arg) {
    if (arg) return 1;
    set_name("doll");
    set_alt_name("doll_for_girl");
    set_short("A little doll");
    set_long("A pitiful looking doll.  You can barely even tell that it is\n"+
      "supposed to be a doll at all.\n");
    set_value(5);
    set_weight(1);
}
