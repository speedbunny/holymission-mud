inherit "obj/armour";
void reset(int arg) {
  ::reset(arg);

    set_name("robe");
    set_alias("robe");
    set_short("A purple robe");
    set_long(
"A long, purple cloak with a bat fur lining.  There is a massive silver "+
"star in the middle of the back of the cloak.  A black staff is behind "+
"the star.  The collar has a red fringe on it.  The cloak seems to weigh "+
"almost nothing.\n");
    set_value(400);
    set_weight(1);
    set_type("cloak");
    set_ac(2);
  }
