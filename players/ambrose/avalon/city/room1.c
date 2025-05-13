#include "/players/ambrose/room.h"
#include "/players/ambrose/defs.h"


reset(arg) {
set_light(1);
short_desc = "City Entrance";
long_desc =
"This is the main entrance to the city of Avalon.  White marble cover\n"+
"covers everything which you see on the street.  In front of you the \n"+
"road splits into three directions.  The architecture seems to have both\n"+
"Roman and Greek influences, but seems slightly different from both.  From\n"+
"where you stand you see a tower to the left and the right, with a large\n"+
"spire directly in front of you.  The spire in front looks like the roof\n"+
"of a church.  The streets seem strangely deserted, except for the few\n"+
"city guards you see patrolling the streets.\n";
dest_dir = ({
         "/players/ambrose/avalon/city/room2","north",
      });
items = ({"marble","White Marble from the finest quarries",
          "street","The street seems to glow with a light of its own",
          "gate","Stands behind you, Mithril Doors polished bright"});
}

init() {
  ::init();
  add_action("enter","enter");
  }
 enter(str) {
 if(str!="gate"){
notify_fail("Enter what ?\n");
 return 0;
}
  MOVEP("into the wilderness#players/ambrose/avalon/city/out1");

  return 1; }

