/* SLOPE.C - Original MUDLIB file */
/* 120593: Airborne: replace_program added for optimization */
/* 020993: Ethereal Cashimor: Orc-guard added against walking orcs */

inherit "room/room";
#include "/obj/lw.h"
 
object guard;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="A slope";
    long_desc="The forest gets light here, and slopes down to the west.\n";
    set_light(1);
    dest_dir=({"room/orc_vall","west",
               "room/forest2","east",
               "room/forest3","south"});
    smell="The forest has fresh air, but something stinks to the west.";
    items=({"forest","Just a lot of trees standing around"});
  }
  if(!guard) {
    guard=clone_object("obj/monster");
    guard->set_name("guard");
    guard->set_level(11);
    guard->set_long(lw("This guard is from the village to the east, and stands"
                     + " here to protect this village against the orcs from "
                     + "the valley to the west.\n"));
    guard->set_race("human");
    guard->set_gender(2);
    guard->load_chat(1,({"Guard says: Orcs should remain in their valley.",
                         "Guard murmers something about orcs.",
                         "Guard looks around."}));
    guard->set_match(this_object(),({"handle_arrival"}),({"arrives"}),({""}));
    move_object(guard,this_object());
  }
}

handle_arrival(str) {
string strexp;
object who;

  strexp=explode(str," ");
  if(strexp[sizeof(strexp)-1]!="arrives.") return;
  who=present(strexp[sizeof(strexp)-2],this_object());
  if(!who) return;
  if(who->query_race()!="orc") return;
  tell_room(this_object(),"Guard says: You! Orc! Go back to your valley!\n");
  if(who->query_npc()) command("west",who);
}
