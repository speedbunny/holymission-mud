inherit "room/room";
object gl_hole;
reset(arg) {
    if (arg) return;

    set_light(1);
    property = "no_teleport";
    short_desc = "Underground";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc=
        "You have entered a large cave. A strange light comes from the\n"+
        "walls, lighting the place in a dim way.\n"+
        "You hear a distant rumble coming from below, and smell something\n"+
         "really weird. It appears that you have entered the center cave of a\n"+
        "large volcano which has suddenly become active.\n";
          items = ({
              "light","Dimmed light",
              "strange light","Really weird light coming from the walls",
              "walls","They seem solid",
             "wall","It seems solid",
              "cave","It seems like the center cave of an active volcano",
              "place","A really weird place",
              "rumble","A distant rumble",
              "volcano","A large underground volcano",
              "ground","Soft and warm earth",
              "walls","Solid walls reaching the ground",
              "east wall","A solid wall reaching the ground",
              "west wall","A solid wall reaching the ground",
              "north wall","A solid wall reaching the ground",
              "south wall","A solid wall reaching the ground",
              "floor","Soft and warm earth",
              "earth","It looks messed up, maybe someone dug there",
              });
    smell = "The air smells like sulphur, and ashes.";
}
init(){  
    ::init(); 
    add_action("dig","dig");
   }
dig(str){
    if(!str){
     notify_fail("Dig where ?\n");
     return 0;
     }
  if((str=="down"||str=="in ground"||str=="in earth"||str=="ground")){
     if(gl_hole){
     write("There already is a hole.\n");
     return 1;
     }
     if(!gl_hole){
    write("You dig in the warm soft ground, and make a hole.\n");
   say(this_player()->query_name()+" has dug a hole in the ground.\n");
     gl_hole=clone_object("players/dice/quest/gl_hole");
     move_object(gl_hole,this_object());
     return 1;
     }
  }
 }
