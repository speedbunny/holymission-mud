inherit "room/room";  

void reset(int arg) {

  if(arg) return;  

  set_light(1);

  short_desc="A faint, overgrown path"; 
  long_desc="\nAs thick as the forest is here, a casual passerby would not\n"
            "even notice the faint, overgrown path leading south through\n"
            "the woods. The only thing that even attracts attention is a\n" 
            "strange sound echoing amongst the trees. However, if you look\n"
            "closely, you can glimpse a few half-buried pieces of flagstone\n"
            "hidden beneath the undergrowth.\n\n";

  dest_dir=({"/players/raindell/areas/IWheel/approach/a2","south",      
           });

  items=({"forest","Dark and lush, the forest teems with unseen life", 
          "path","Clogged with undergrowth, the path is in ruin",
          "woods","The forest seems to thin somewhat to the south",
          "undergrowth","This menagerie of small plantlife has grown up through what used to be a perfectly good stone pathway",
          "flagstone","Broken in many places, these paving stones have seen much better days",
          "plantlife","The plantlife is in serious need of a good groundskeeper",
	    "trees","Tall and foreboding, the trees tower above you",
         });




  ::reset(arg);

   replace_program("/room/room");



}
