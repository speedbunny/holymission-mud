inherit "obj/monster";
 
#define NAME this_player()->query_real_name()
#define ONAME this_object()->query_name()
 
object hunt;
 
reset(arg) {
::reset(arg);
if (arg) return;
 set_name("palestinian");
 set_race("human");
 set_size(2); 
 set_level(10);
 set_ep(1000);
 set_hp(70);
 set_wc(9);
 set_ac(5);
 set_al(0);
 set_alias("pali");
 set_short("An ugly looking palestinian");
 set_long("He is in good shape. So you should not attack him.\n"+
          "Maybe he is fighting for the Liberty of Palestina.\n");
 set_aggressive(0);
 set_heart_beat(1);
}
 
attack();
  ::attack();
  
