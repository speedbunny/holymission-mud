inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg) {

   if(!present("child")){ MO(CO(HMON+"hchild"),TO);
                          MO(CO(HMON+"hchild"),TO); 
                          MO(CO(HMON+"hchild"),TO);
                          MO(CO(HMON+"hchild"),TO);
                          MO(CO(HMON+"hchild"),TO);
                          MO(CO(HMON+"hchild"),TO);
                          MO(CO(HMON+"halfling"),TO); }

  if(arg) return;
    ::reset(arg);
    long_desc= "The cobblestone path continues along the bank here."+
               "  On the opposite shore is a small stone mill, with "+
               "wooden paddle wheel on its side.  A small circle has "+
               "been etched on the pavement in charcoal and a few "+
               "small stones lie in and around it.\n";
    
    short_desc = "On the path to the Halfling village";
 
  set_light(1);
  
  dest_dir = ({ HPATH+"p5","south", HPATH+"p3","northwest" });

  items = ({  "path","go northwest and look at the frog",
              "bank","There is a mill on the opposite bank",
              ({"wheel","wooden paddle wheel","paddle wheel"}),
              "Hard to make out details from this distance",
              "circle","It is for game played by young halflings",
              "stones","Leave em alone, they are for the kids",
              "small stones","Leave em alone, they are for the kids"
           });



   replace_program("room/room");
}



