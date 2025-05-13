/* Top of ONE Falls */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Top of One Falls";
    long_desc = "The water gushes out of a slit in the cliffs here. The\n"+
                "volume of water coming out of the slit makes it impossible\n"+
                "for you to enter the slit. The cliffs go up from here well\n"+
                "above the tree tops. The water falls down into a pool below\n"+
                "and then flows down through a narrow gorge going west.\n";
    dest_dir = ({"players/kbl/big_forest1","south",
                 "players/kbl/falls2","down"});
    smell = "The air is fresh and moist here.";
    items = ({"pool","The water swirls and churns in the pools making the\n"+
                     "water look very deadly. Maybe you might jump into\n"+
                     "the pool",
              "gorge","The gorge heads west down into the trees and out of sight",
              "tree tops","You see soft blue leaves moving in the breeze.\n"+
                          "The branches gently sway and you feel your mind\n"+
                          "wandering, you think of a place underwater",
              "leaves","Soft blue leaves",
              "branches","Brownish limbs carry many branches to the suns rays",
              "trees","Many maple type trees approximately 80 meters high\n"+
                      "surround this area upto the cliffs. They grow denser\n"+
                      "looking west",
              "limbs","Long limbs come the main trunks of the trees. No\n"+
                      "or very few, lower limbs or branches can be seen on\n"+
                      "any of the maples around here",
              "trunks of the trees","You are really bent on detail! They are\n"+
              "thick trunks, well nourished by the steady flow of water from\n"+
              "the slit in the cliffs"});
    transfer(clone_object("players/kbl/objs/elf"),this_object());
  }
}


init()
{
  ::init();
  add_action("jump","jump");
  add_action("look_it","scan");
  add_action("climb","climb");
  add_action("look_it","look");
}


jump()
{
  write("You jump into the water which carries you over the falls!\n");
  say(this_player()->query_name()+" jumps into the water!\n");
  say(this_player()->query_name()+" is carried over the falls...\n");
  write("The water is pushing you down, down, down and your lungs start\n");
  write("to explode as you reach a ledge underwater...\n");
  if(this_player()->query_dex() >= 12)
  {
    write("By your best dexterity, you go under the ledge and you find\n");
    write("a pocket of fresh air!\n");
    this_player()->move_player("no remaining trace in the pool at the bottom of the falls#players/kbl/fall_under");
    return 1;
  }
  else
  {
    write("You push off the ledge towards the surface behind the falls.\n");
    this_player()->move_player("the water to behind the falls#players/kbl/falls_cav1");
    return 1;
  }
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at water" || str == "water")
  {
    write("Water is crystal clear, but moving so fast you dare not drink!\n");
    return 1;
  }
  if(str == "at cliffs" || str == "cliffs")
  {
    say(this_player()->query_name()+" looks at cliffs.\n");
    write("You see the cliffs are very steep, but probably climbable to\n");
    write("those with good dexterity. The cliffs are quartz crystal and\n");
    write("sparkle in the constant sun light.\n");
    return 1;
  }
  if(str == "at slit" || str == "slit")
  {
    say(this_player()->query_name()+" looks at slit in cliff.\n");
    write("The water flows at a tremendous rate from the slit. The slit\n");
    write("is liken to a rip in the quartz cliff.\n");
    return 1;
  }
  if(str == "at falls" || str == "falls")
  {
    say(this_player()->query_name()+" looks at the falls.\n");
    write("The water spills down into a pool at the bottom of the falls.\n");
    return 1;
  }
  if(str == "up")
  {
    say(this_player()->query_name()+" looks up at the high cliffs.\n");
    write("The cliffs run north to south and are so tall, the features at\n"+
          "top are blurred.\n");
    return 1;
  }
  if(str == "down")
  {
    say(this_player()->query_name()+" looks down.\n");
     write("You look down and see the path and the pool that the water\n"+
           "falls down into.\n");
     return 1;
  }
}

climb(str)
{
  if(!str)
   return;
  if(str == "cliff" || str == "cliffs")
  {
    if(this_player()->query_dex()-(this_player()->query_intoxination()/5) > 14)
    {
      write("You start to climb up...\n");
      this_player()->move_player("climbing up#players/kbl/cliff1");
      return 1;
    }
    if(this_player()->query_dex() > 7)
    {
      write("You try to climb the cliff, you fall!\n");
      say(this_player()->query_name()+" tries to climb the cliff, but falls!\n");
      this_player()->hit_player(3);
      write("You feel a pain in your butt!\n");
      return 1;
    }
    write("You are to afraid to climb!\n");
    say(this_player()->query_name()+" is to afraid to climb the cliff.\n");
    return 1;
  }
}
