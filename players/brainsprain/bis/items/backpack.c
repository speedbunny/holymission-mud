inherit "obj/container";
inherit "obj/armour";

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
    set_name("backpack");
    set_alias("pack");
    set_max_weight(30);
    set_short("A backpack");
    set_long(
"A big backpack.  There are straps, pockets, loops, and pouches "+
"all over it.  It looks like it could carry a lot of stuff.  You "+
"also notice that there are shoulder straps, perhaps you could wear "+
"it!\n");
    set_type("other");
    set_ac(0);
    set_value(150);
    set_weight(1);
}
int no_clear()
{
    return 1;
}
void init(){
  ::init();
  add_action("wear","wear");
}
