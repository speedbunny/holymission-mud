inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    property = "no_teleport";
    short_desc = "Light";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc=
        "You are standing in a strange illuminated room "+
        "with strange walls.\n"+
        "A cold blue light is shining here, seemingly coming from nowhere.\n";
          items = ({
              "light","A strange cold light, maybe you could enter it",
              "hole","A sinister black hole in space and time",
              "walls","Solid walls, you feel unable to break them down",
              "room","A strange illuminated room",
              "strange walls","Solid walls",
              "wall","A solid wall, you feel unable to tear them down",
         "strange wall","A solid wall",
              "nowhere","A black hole in the magic of space and time",
              });

    smell = "The air smells weird here.";
}
init(){  
    ::init(); 
    add_action("enter_light","enter");
   }
enter_light(str){
    if(!str){
     notify_fail("Enter what ?\n");
     return 0;
     }
     if((str=="light")||(str=="blue light")||(str=="cold light")){
     this_player()->move_player("into the light#/players/dice/quest/q2");
     return 1;
     }
 }
