inherit "obj/soft_drink";

 object locket;

int locket(string arg)
 {
  tell_room( environment( environment( this_object() ) ) , "Bertl says: "+arg+"\n" );
  return 1;
 }
reset(arg) {
    ::reset(arg);
    set_name("beer");
    set_alias("drink");
    set_alias("double");
    set_short("Double beer");
    set_long("Really full and cold double of beer.\n");
    set_drinker_mess("Ahhh, refreshing...be a beer, drink  another one !\n");
    set_drinking_mess(" buuurrrps loudly and obnoxiously!!!  'What a pig!' you think.\n");
    set_value(10);
    strength=20;

 }
void init()
 {
  ::init();
  add_action("locket","q");
 }
