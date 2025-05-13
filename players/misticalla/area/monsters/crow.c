
inherit "/obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {

  set_name("black crow");
  set_alias("crow");
  load_chat(8,({"CAAaaawww!  CaaawwWWW!\n"}));
  set_short("A mean black crow");
  set_long("A nasty looking vegitarian crow.  He is\n" +
	   "agitated with your presence. He has a black\n" +
	   "bill and black feet.\n");
  set_level(7);
  set_size(1);
  set_aggressive(1);
  add_money(20);
 }
}

