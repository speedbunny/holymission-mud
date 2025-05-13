inherit "/obj/armour";

reset(arg) {

  ::reset(arg);
  if (!arg) {
     set_name("crown");
     set_short("Royal crown of Denmark");
     set_long("This is the royal crown that is worn by the king of Denmark.  It is has a huge\n"+
                    "diamond set in gold on its crest.\n");
     set_ac(1);
     set_type("helmet");
     set_size(3);
     set_value(1000);
     set_weight(1);
  }
}
