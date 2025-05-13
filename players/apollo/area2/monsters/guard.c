
inherit "/obj/npc";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("guard");
  set_alias("guard");
  set_short("A guard");
  set_long("This guard has lived here for many years, undisturbed \n" +
	   "until you decided to come along. It looks as if he is \n" +
	   "guarding the northern path from intruders that do not \n" +
	   "possess the proper knowledge and experience to continue \n" +
	   "onward.\n");
  set_level(25);
  set_al(-100);
  set_hp(100000);
  set_wc(1);
  set_ac(1000);
  set_aggressive(0);
  set_dodge(100);  

  move_object(clone_object("players/apollo/area2/weapons/doom_sword"),
  	this_object());
  init_command("wield doom sword");

}

init() {
 ::init();
 add_action("_north","north");
}

_north() {
   if (this_player()->query_level()>=20) {
	this_player()->move_player("north#players/gareth/evil/cave/entcave");
	return 1;
     }
   else {
     write("The golem firmly grips your shoulder and pulls you back.\n"+
           "It rumbles: 'Sorry, no adventurers allowed.'\n");
     return 1;
   }
}

int hit_player(int dam,int type,mixed *elem) {
    printf("Guard parries your blow with ease.\n");
    return ::hit_player(0,type,elem);
}
