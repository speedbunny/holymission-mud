inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg){


}

if(arg) return;

  set_light(1);

  long_desc = "Rising into the sky next to the river stands a granite obelisk "+
              "with strange picture figures covering its surface.  It seems "+
              "very out of place here.  The path continues south"+
              ".\n";

  short_desc= "Along the Shayla river";

  dest_dir = ({ HPATH+"pr12","north", HPATH+"pr14","south" });

  items = ({  "valley","Umm, the valley is to the north",
              "stone structure","go south and see for yourself",
              "structure","It lies to the south",
              "river","Same ole river",
              "land","Yes it is, thank god"
              "obelisk","Something has been scratched into its surface near the "+
                         "base, perhaps you should look at the inscription",
              ({"base","inscription"}),
              "It seems as if someone has translated the picture writing on this part.\n"+
              "written in common: \n"+
               "'Oh traveler to whom this is found.  None in my land have the heart\n"+
               "to undo the curse placed upon me an eternity ago.  My soul has \n"+
               "commanded my mighty vizer who serves me in death as in life to send\n"+
               "this (untranslated) before you in order that journey to the world\n"+
               "of (untranslated) to undo the curse and free the land.  It is\n"+
               "(untranslated) of this (untranslated) to send you forth on speaking\n"+
               "my name.  Sneferu"

               });

}

void init(){
 ::init();

 add_action("_say","say");
 add_action("_say","speak");

}

int _say(string arg){

  if(!arg && arg != "sneferu" && arg != "Sneferu") return 0;

  write("The magic must be gone, for nothing happens");
  return 1;
}

