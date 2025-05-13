inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("shark");
    set_alias("fish");
    set_level(15);
    set_wc(10);
    set_short("A ferocious dog shark");
    set_long("A ferocious dog shark with rows and rows of sharp teeth.\n");
    set_aggressive(1);
}
