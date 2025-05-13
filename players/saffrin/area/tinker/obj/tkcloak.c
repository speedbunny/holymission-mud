inherit "/obj/armour";

void reset(int flag) {

  ::reset(flag);
  if (flag == 0) {
        set_name("cloak");
        set_short("Tinker king's cloak");
        set_long("A long, flowing cloak patched together from colorful pieces of cloth.\n");
        set_ac(2);
        set_type("cloak");
        set_size(3);
        set_value(247);
        set_weight(1);
  }
}
