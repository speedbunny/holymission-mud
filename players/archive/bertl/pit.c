 /* Bertls Pit HM 24.11.94 */

inherit "room/room";


reset(arg)
{  
   if(!arg)
   {
      set_light(1);
      
       short_desc="A dark dungeon.";
       long_desc= "You have entered one of the nightmares of this Mud.\n" +
                   "Scattered bones and corpses are spread all over the floor\n" +
                  "and the walls drop of blood and other liquids....\n\n";

      items=({
               "bones","You get the feeling of unnatural strength",
               "corpses","Half rotten corpses, dont look good anymore"
            });
/*
      dest_dir=({
                 "/room/church.c", "church",
                 "/players/whisky/magic/mages_bar.c", "magebar",
                 "/players/matt/newworld/city/rooms/votebooth.c", "vote"
               });
*/
       smell = "A smell of blood and rotten corpses hangs in the air";

   }
}

init()
{
 ::init();
}

