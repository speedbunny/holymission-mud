
inherit "room/room";
object o1,o2;
 
reset(arg) 
{
if (!o1) {
  o1=clone_object("players/whisky/garden/monster/panther");
  move_object(o1,this_object());
  }
  if (!(o2=present("crowbar",this_object()))) {
  o2=clone_object("players/whisky/garden/obj/crowbar");
   move_object(o2,this_object());
  }
  if (arg) return;
  set_light(1);
  property = "no_teleport";
  short_desc = "On a strange roof";
  long_desc = 
        "You have now reached the roof of that strange building. "+
        "If you gaze skyward you see the moon shining on the roof "+
        "and stars sparkling back at you. This seems to be the "+
       "backside of the house's roof. "+
       "It appears to be a steep climb further up the other side\n";
  dest_dir = 
    ({
      "/players/whisky/garden/room/attic", "down",
    });
  
  items = 
    ({ 
      "roof","You see a big shindle roof ",
      "moon","You see the full moon shining at your face",
      "waterchannel","You see a metal black painted waterchannel",
      "exit","You see the contours little exit"
      });
}
   
     
     
 
