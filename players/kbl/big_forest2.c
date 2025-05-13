/* A quiet spot in the middle of the Blue leaf maple forest */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "A small clearing in the forest";
    long_desc = "Blue leaf maple trees tower above you. The color of the\n"+
                "leafs casts a blue glow all around you. A gentle breeze\n"+
                "blows from a thick area of trees to the east. The forest\n"+
                "thins out a little to the north and a well used pathway\n"+
                "leads north. There's a large hole in the ground here with\n"+
                "a vine or two growing down into it. You can hear the sound\n"+
                "of water somewhere near by.\n";
    dest_dir = ({
                 "players/kbl/big_forest3","north",
                 "players/kbl/falls2","south",
                });
    smell = "The air tastes so sweet here. Every break brings tingles\n"+
            "in your lungs as they drink in this sweet tasting air";
    property = "no_sneak";
    items = ({"forest","A expansive array of blue leaf maples everywhere\n"+
                       "you look",
              "blue leaf maples","80 meter tall trees with blue leafs",
              "ground","Soft moist dirt, very rich. No wonder the trees grow\n"+
                       "like mad here",
              "pathway","Well worn pathway has many small foot prints on it",
              "vines","Thick vines grow from the ground and down into hole",
              "vine","Thick vines grow from the ground and down into hole",
              "maple","80 meter tall tree with blue leafs",
              "blue leaf maple","80 meter tall tree with blue leafs",
              "trees","80 meter tall blue leaf maple trees",
              "hole","A deep dark hole with vines growing down into it"});
  }
}

init()
{
  ::init();
  add_action("climb","climb");
}

climb(str)
{
  if(!str)
   return;
  if(str == "down vines" || str == "down vine")
  {
    write("You start to climb down vines into hole.\n");
    this_player()->move_player("climbing down into hole#players/kbl/dungeon/dun11");
    return 1;
  }
  if(str == "tree" || str == "trees" || str == "maple trees" || str == "maple tree")
  {
    write("You cannot find branches low enough to help climbing these\n"+
          "trees and the trunks are so smooth that it makes it impossible\n"+
          "to climb anyway.\n");
    say(this_player()->query_name()+" tries to climb maple trees but fails.\n");
    return 1;
  }
}
