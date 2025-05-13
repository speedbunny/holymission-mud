inherit "/room/room";

#include "/sys/vt100.h"

schaffner(obj)
{
   write("As the worm passes by, you hear a strange voice echoing\n"+
         "trough your head:\n"+
         "   'Wir erreichen in Kuerze Wien-Huetteldorf,'\n"+
         "   'umsteigen zu den Linien U3,14,5a und 7'\n"+
         "You wonder what that strange spellike words could mean?\n");
}
 
long() {
   write("You are in the torture-chamber of the Palace of the\n"+
         "one and only LLort, Master of nothing and its half,\n"+
         "Ruler of this and that (especially that) and Killer\n"+
         "of nonexisting somethings.\n"+
         "Suddenly a gigantic gray worm with multicolored drawings\n"+
         "along its sides is charging out of a hole in the western\n"+
         "wall, heading for a similar hole in the opposit wall.\n"+
         "You think there is absolutly no way to stop it!\n");
   write("  exit: suicide\n");
}
suicide()
{
   shout(this_player()->query_real_name()+" commits SUICIDE!\n");
   destruct(this_player());

   return 1;
}
 
nomask init() {
   object llort;
/*
   call_out("schaffner",20,this_object());
*/
   add_action("suicide","suicide");
   add_action("trust","trust");
   add_action("chamber","chamber");
   add_action("church","church");
   add_action("spells","sm");
   add_action("post","post");
   add_action("inner","inner");
   add_action("outer","outer");

   llort=find_player("llort");
   if(llort) tell_object(llort,
       VT_TA_B+"---- "+this_player()->query_real_name()+
       " entered your workroom -----------\n"+VT_TA_AO);
}

inner()
{
   this_player()->move_player("X#players/llort/guild/tower/inner_chamber");
   return 1;
}

outer()
{
   this_player()->move_player("X#players/llort/guild/tower/outer_chamber");
   return 1;
}

post()
{
   this_player()->move_player("X#room/post");
   return 1;
}

spells()
{
   this_player()->move_player("X#spells/master");
   return 1;
}

church()
{
   this_player()->move_player("X#room/church");
   return 1;
}

chamber()
{
   this_player()->move_player("X#players/llort/guild/tower/chamber");
   return 1;
}

trust()
{
   this_player()->move_player("X#players/llort/secure/trust");
   return 1;
}
 
short() {
   return "Llort's summer residenz";
}
 
reset(a) {
   if(a) return;
   set_light(1);
}

