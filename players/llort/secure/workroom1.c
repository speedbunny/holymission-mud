inherit "/room/room";

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
/*
   call_out("schaffner",20,this_object());
*/
   ::init();

   add_action("suicide","suicide");

   if(!interactive(this_player())) return;

   if(member_array(this_player()->query_real_name(),
         ({ "llort","patience"})) ==-1)
   {
       if(!this_player()->query_archwiz())
       if(!this_player()->query_level()>39)
       {
           write("Huh ??\n");
           move_object(this_player(),"room/church");
           tell_room(this_object(),this_player()->query_name_true()+
              " tried to enter the workroom!!!\n");
       } 
       return;
   }

   add_action("chamber","chamber");
   add_action("church","chu",3);
   add_action("sm","sm");
   add_action("am","am");
   add_action("skm","skm");
   add_action("post","post");
   add_action("inner","inner");
   add_action("outer","outer");
   add_action("arena","arena");

   if ( this_player()->query_invis() < 50 ) {
      this_player()->set_invis(50);
      write( "------------------------------------------------\n"+
             "You were not invis. This fault is corrected now.\n"+
             "------------------------------------------------\n" );
   }
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

am()
{
   this_player()->move_player("X#abilities/master");
   return 1;
}

skm()
{
   this_player()->move_player("X#masters/skills");
   return 1;
}

sm()
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

   hidden_dir = ({ "/room/adv_guild","gui" });
}

arena(a)
{
   this_player()->move_player( "to the arena#/players/patience/arena/prep_room" );
   return( 1 );
}
