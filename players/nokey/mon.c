inherit "obj/monster";

void reset(int arg)
  {
  ::reset(arg);
  if(arg) return;
  set_name("stupid");
  set_level(10000);
  set_al(-100000);
  set_short("A stupid, but VERY tough monster");
  set_long("This monster may look stupid, but you get the uneasy feeling it could\n"+
  "kill you as easily as it breathes.\n");
  }
