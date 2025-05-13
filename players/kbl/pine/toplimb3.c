/* The highest limb that touches the top of High Cliff */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Limb that scrapes High Cliff";
    long_desc = "The wind blows constantly here and threathens to blow you\n"+
                "off this limb. The limb scrapes the cliff with a grating\n"+
                "noise, makes a shiver run up your spine. Your hear the\n"+
                "sounds of many birds within the tree along with creaking\n"+
                "noises of the branches. The winds blowing through the\n"+
                "pine needles makes a humming sound.\n";
    dest_dir = ({"players/kbl/northcliff3","cliff",
                 "players/kbl/pine/toplimb2","west"});
    smell = "Intense pine odor almost puts you to sleep";
    property = "no_hide";
    items = ({"smaller branches","They do not have many needles growing on them",
              "trunk of the tree","Its bark is very crinkled and looks like its\n"+
                                  "peeling off",
              "bark","Too far away to get any detail"});
  }
}


init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
  add_action("wes_b","west");
}


wes_b()
{
  write("A voice sooths you: Open soon! Please send your ideas to kbl\n"+
        "via <idea> command.\n");
  say(this_player()->query_name()+" stops from going west.\n");
  return 1;
}
look_it(str)
{
  if(!str)
   return;
  if(str == "at limb" || str == "limb")
  {
    say(this_player()->query_name()+" looks at limb.\n");
    write("The limb is very wide and could support alot of weight. Small\n");
    write("clumps of needles grow here and there along the limb. Many\n");
    write("smaller branches grow off the limb here.\n");
    return 1;
  }
  if(str == "at cliff" || str == "cliff")
  {
    say(this_player()->query_name()+" looks out at cliff.\n");
    write("You can barely see the cliff through the thick needles that\n");
    write("grow here. The cliff is being scraped away by the needles\n");
    write("rubbing against it.\n");
    return 1;
  }
  if(str == "at tree" || str == "tree")
  {
    say(this_player()->query_name()+" looks in at main  part of tree.\n");
    write("You see the large main trunk of the tree. It is huge!\n");
    return 1;
  }
  if(str == "at branches" || str == "branches")
  {
    say(this_player()->query_name()+" looks at the branches here.\n");
    write("The branches are covered in thick groupings of needle clusters.\n");
    write("The pine needles cover the branches in a clover like pattern\n");
    write("which creates a sense of symmetry in your mind.\n");
    return 1;
  }
  if(str == "at needles" || str == "needles")
  {
    say(this_player()->query_name()+" looks at the pine needles.\n");
    write("Beautiful crimson red and patterned in clovers these needles\n");
    write("seem to radiate from their own internal light. They move\n");
    write("in a waving type motion, your not sure if its the wind or\n");
    write("the needles themselves.\n");
    return 1;
  }
}
