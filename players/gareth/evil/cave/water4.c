inherit "room/room";
#include "/players/gareth/define.h"
reset(arg) {
  ::reset(arg);
  if(!arg) {

     set_light(0);
     short_desc = "Underground Lake";
     long_desc = 
      "You are standing in a large pool of pitch black water.\n"+ 
      "This wet area is filled with stalactites and stalamites\n"+
      "that glow a grayish hue. In certian places the stalagmites\n"+
      "and stalactites have grown together to form cloumns. You see\n"+ 
      "the glint of gold coming from the far side of the lake. A\n"+ 
      "foul, cold wind blows through the cave, your legs are becoming\n"+ 
      "numb from the ice cold water. \n"; 
     
     items = ({ 
      "water","cold, dark and of course, wet",
      "columns","pillar of natural ogrigin due to time",
      "column","pillar formed over time",
      "stalagmites","natural formation due to time, it's covered with moss",
      "stalactites","natural formation due to time, covered with moss",
      "moss","grey moss that seems to glow",
      "glint","a gold color shine coming from somewhere",
                });
     dest_dir = ({
       ECAVE+"water7","north",
       ECAVE+"water2","south",
       ECAVE+"water5","west",
                });

}
}
