/* Main door to KBLs Castle in the mountains */

inherit "room/room";
int wind_set;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    wind_set = 0;
    set_light(2);
    short_desc = "Main door into castle";
    long_desc = "You stand infront of a rugged looking castle set firmly\n"+
                "into these young mountains. The walls are a steel gray\n"+ 
                "color and look very solid. North leads directly up\n"+
                "to the door which is slightly ajar. A small path leads\n"+
                "east and down around castle but west is a 100 meter drop.\n"+
                "South the path leads down to a valley. The view is stunning.\n"+
                "Various symbols can be seen carved into the door frame.\n"+
                "Three short towers with louvered firing slits can be seen\n"+
                "above the walls. One at either end and one in the middle\n"+
                "of the castle above the door. Hard to see if anybody is\n"+
                "up there.\n";
   dest_dir = ({"players/kbl/corridor","north",
                "players/kbl/grounds/gro2","south",
                 "players/kbl/grounds/gro3","east"});
   items = ({"castle","More like a stone fortress than a castle. Its\n"+
                      "placement into the mountains was done more than by\n"+
                      "some guess work. Giant spires of rock come from\n"+
                      "both sides of the castle, jutting 100 meters or so\n"+
                      "into the air. The castle has the look of having\n"+
                      "fallen into this spot! But not a crack can be seen\n"+
                      "in the structure of the castle. This block type\n"+
                      "architecture looks more like a fortress/prison castle!",
             "mountains","Tall peaks show the age of these rugged mountains",
             "walls","The walls look more like steel in a sword than stone.\n"+
                     "They show no signs of weathering or any bombardment",
             "pathway","Broken stones and flat rock makeup the north/south\n"+
                       "pathway your on",
             "path","Steep pathway leading east then down",
             "door","a very sturdy door made from solid oak with woven metal\n"+
                    "bindings and hinges. Has taken a few hits in its time",
             "valley","You look out at a valley that stretches from the\n"+
                      "eastern horizon to a blue sea at the far west horizon.\n"+
                      "You are looking down through some clouds to view\n"+
                      "this expansive valley. You see smoke trails coming\n"+
                      "from various parts of the forested parts and the\n"+
                      "farther you look west, the less dense the forest gets.\n"+
                      "Directly south can be seen another mountain range\n"+ 
                      "growing up from the valley going south",
             "symbols","    The symbol of Kbls' origin.\n\n"+
                       "         |         /\n"+
                       "         |        /\n"+
                       "         |       /\n"+
                       "         |      /\n"+
                       "         ---------\n"+
                       "         |         )\n"+
                       "         |_________)\n"+
                       "         |         )\n"+
                       "         |         )       |\n"+
                       "         ------------------",
             "door frame","There are symbols on the red metal door frame",
             "towers","They are all 6 meter towers above a 20 meter wall.\n"+
                      "Made from the same material as the walls and seem\n"+
                      "more polished than the walls",
             "louvered firing slits","Your a nut for detail! Well, the slits\n"+
                                     "a white metal of some sort, no much\n"+
                                     "detail can be seen from here"});
   smell = "Fresh mountain air ... ahhhh ... it expands your lungs!";
   property = "no_hide";
  }
}

init()
{
  ::init();
  wind();
}

wind()
{

int val;

 val = random(9);
 switch(val)
 {
   case 0: 
     say("The wind starts coming from the south.\n");
     write("The wind starts coming from the south.\n");
     say("Winds coming from the south are warm and smell of animals.\n");
     write("Winds coming from the south are warm and smell of animals.\n");
     smell = "The odor of live stock animals greets your nose";
     wind_set = 1;
     break;
   case 1:
     say("The wind shifts directions.\n");
     write("The wind shifts directions.\n");
     say("Swirling cold winds from the north have a fresh scent to them.\n");
     write("Swirling cold winds from the north have a fresh scent to them.\n");
     smell = "The air has a clean cool taste to it";
     wind_set = 1;
     break;
  case 2:
  case 3:
     say("A cool breeze starts up.\n");
     write("A cool breeze starts up.\n");
     say("Breeze from the east feels very cool and smells of plant life.\n");
     write("Breeze from the east feels very cool and smells of plant life.\n");
     smell = "You detect the odor of grass and other plants in the air";
     wind_set = 1;
     break;
  case 4:
  case 5:
     say("Wind shifts.\n");
     write("Wind shifts.\n");
     say("Steady flow of warm air from the west brings a sea weed odor.\n");
     write("Steady flow of warm air from the west brings a sea weed odor.\n");
     smell = "The air smells like a salt sea is not too far away.";
     wind_set = 1;
     break;
  default:
     smell = "Fresh mountain air ... Ahhhh ... it expands your lungs!";
     wind_set = 0;
 }
}

query_wind_smell()
{
  return smell;
}

query_wind_set()
{
  return wind_set;
}
