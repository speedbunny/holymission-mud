#include "/players/gareth/define.h"
inherit "/room/room";

reset(arg) {
   if (!arg) {
   set_light(1);
   short_desc= "Town road";
   long_desc= "You stand at the base of the cliff and on the\n"+
              "road leading into the heart of town. You get a\n"+
              "sense of deep evil from this village. The top of\n"+ 
              "of the cavern can't be seen through the purple glow\n"+ 
              "that lights up the town. There is a great deal of\n"+
              "noise coming from the building to the west. A nasty\n"+ 
              "stench eminates from a broken shack to the east. There\n"+
              "is a skull lying under a sign. \n";
   items = ({
            "shack","A broken down old building, have a look.",
            "building","A building where it sounds like a party is there",
            "cavern","A hollowed out place in which you are standing",
            "skull","A white skull, looks human",
            "glow","An illumination the lights up the town",
            "sign","Maybe you should try reading it",
           });
   dest_dir =({
     ETOWN+"tr3","north",
     ETOWN+"jail","east",
     ETOWN+"bar","west",
     ETOWN+"tr1","up",
     });
   
   }

}

init() {
  AA("read","read");
  ::init();
}
  read(str) {
    if (str!="sign") return;
    write("Welcome to Fantoma, the land of the absolute darkness.\n"+
	  "For the brave drow who return from a gloruis victory -\n"+
	  "WELCOME back. For any intruders and trepassers beware\n"+
	  "for Fantoma is not a land for the weak and timid, obey\n"+
	  "the only rule here or die!  Kill or be killed, for there\n"+
          "is no second place in this race.\n");


    say(TPN+" reads the sign.\n");
    return 1;
} 
