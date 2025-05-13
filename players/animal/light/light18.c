/* LIGHT18.C - Programmed by Animal */
/* 090793: Ethereal Cashimor: Call_other bug removed */

#include "/obj/lw.h"
inherit "room/room";

object stag,weapon;
 
reset(arg) {
  if(!arg) {
    set_light(1);
    long_desc="The home of the stag. A beautiful white stag makes his home "
            + "here. If you are lucky you might catch a glimpse of the stag "
            + "eating some grass.\n";
    short_desc="The home of the stag";
    dest_dir=({"players/animal/light/light16","south"});
    smell="The place has the scent of grass.";
  }
  extra_reset();
}

query_outdoorness() {
    return 4;
}
 
query_light() {
    return 1;
}

init() {
  ::init();
  add_action("search","search");
}
 
extra_reset()  {
  if((!stag)||(!living(stag))) {
    stag=clone_object("obj/monster");
    stag->set_name("white stag");
    stag->set_alias("stag");
    stag->set_race("deer");
    stag->set_level(13);
    stag->set_hp(270);
    stag->set_al(700);
    stag->set_short("A beautiful white stag");
    stag->set_long(lw("The stag is a proud and majestic animal. It looks like "
                 + "it can take care of itself.\n"));
    stag->set_ac(7);
    stag->set_wc(16);
    stag->set_aggressive(0);
    weapon=clone_object("obj/weapon");
    weapon->set_name("antlers");
    weapon->set_alias("horns");
    weapon->set_short("A large set of deer antlers");
    weapon->set_long("The antlers look sharp and could do some damage.\n");
    weapon->set_class(14);
    weapon->set_value(1100);
    weapon->set_weight(2);
    transfer(weapon,stag);
    command("wield antlers",stag);
    move_object(stag,this_object());
  }
}
 
search(str) {
  if(!str) str="room";
  if(str=="room") {
    write("You find nothing unusual.\n");
    say(this_player()->query_name()+" searches the room.\n");
    return 1;
  }
  return 0;
}
