inherit "obj/monster";

string chat_str;
object sword, arm;

reset(arg) {
  ::reset(arg);
 chat_str = ({"Bill says: Hello!  Sorry, but Jake's place is closed!\n"});
  if(arg) return 1;
  set_alias("guard");
  set_name("bill");
  set_short("Bill the guard");
  set_long("This is Bill the guard.\n" + "He looks at you with a big smile.\n");
  set_level(20);
  set_size(3);
  set_al(1000);
  set_hp(700);
  set_wc(15);
  set_ac(7);
  load_chat(15,chat_str);
  add_money(500);
  set_whimpy();
  if(!present("longsword")) {
sword=clone_object("players/jake/weapons/longsword");
    move_object(sword,this_object());
/*** this does not exist. temp removed by James
arm=clone_object("players/jake/armour/chainmail");
    move_object (arm,this_object());
    init_command ("wear chainmail");
*******/
    init_command ("wield longsword");
  }
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
