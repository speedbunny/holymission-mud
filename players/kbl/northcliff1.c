/* One square north of Ole man on High Cliff */

inherit "room/room";

int mess;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    mess = 0;
    set_light(2);
    short_desc = "High Cliff trail";
    long_desc = "You are along High Cliff on the north/south trail. The\n"+
                "endless planes stretch out to the northeast and west is\n"+
                "is a sea of soft blue trees. Southward are some mountains\n"+
                "and southeast you see the top of a pyramid. The wind blows\n"+
                "constantly here. You see giant pines to the north look\n"+
                "beautifully crimson against the sea of soft blue trees.\n";
    smell = "Air is fresh with a hint of pine";
    dest_dir = ({"players/kbl/northcliff2","north",
                 "players/kbl/clifftop","south"});
    property = "no_hide";
  }
}


eve()
{
int val;
string dire;
object mon;
object drow;

  val = random(16);
  if(val == 10)
  {
   say("You hear a screechy noise coing from the giant pine area.\n");
   write("You hear a screechy noise, coming from the giant pine area.\n");
  }
  if(val == 8)
  {
    say("You see a large bird flying overhead.\n");
   write("A large bird flies over head going north.\n");
  }
  if(val == 6)
  {
   write("A red and black beetle jumps onto your foot, you flick it off.\n");
   say("A bettle jumps on "+this_player()->query_name()+"'s foot.\n");
  }
  if(val == 4)
  {
   write("You get a wirlwind of dust in your face.\n");
   say("You get a wirlwind of dust in your face.\n");
  }
  if(val == 15 || val == 14)
  {
    val = random(2);
    switch(val)
    {
      case 0: dire = "north";
              break;
      case 1: dire = "south";
              break;
    }
    write("A Drow elf comes from the "+dire+" and attacks!\n");
    say("A Drow elf comes from the "+dire+" and attacks!\n");
    drow = clone_object("players/kbl/objs/drow");
    drow->set_aggressive(1);
    mon = clone_object("obj/money");
    mon->set_money(random(500)+800);
    transfer(drow,this_object());
    transfer(mon,drow);
  }
  mess = val;
}

init()
{
  ::init();
  eve();
  add_action("look_it","look");
  add_action("look_it","scan");
}


look_it(str)
{
  if(!str)
   return;
  if(str == "at plane" || str == "plane" || str == "at planes" || str == "planes")
  {
    say(this_player()->query_name()+" scans the Endless plane.\n");
    write("You see nothing on the plane but short bluegreen grass. In the\n");
    write("distance to the southeast, you see a pyramid top. Looking\n"); 
    write("northwest or directly west the plane seems infinite.\n");
    return 1;
  }
  if(str == "at soft blue trees" || str == "soft blue trees")
  {
    say(this_player()->query_name()+" looks out over the soft blue trees.\n");
    write("You see the soft blue effect is caused by the movement of the\n");
    write("leaves in the shifting winds. The valley looks like a shimmering\n");
   write("sea of soft blue water flowing from side to side.\n");
    return 1;
  }
  if((str == "at bird" || str == "bird") && mess == 8)
  {
   say(this_player()->query_name()+" looks at the bird going overhead.\n");
    write("Looks like a giant vultur gryphus! Its red and black wings are\n");
   write("in sharp contrast to its bald head. The vultur disappears out\n");
    write("of sight.\n");
    mess = 0;
    return 1;
  }
  if((str == "at beetle" || str == "beetle") && mess == 6)
  {
    say(this_player()->query_name()+" looks down at beetle.\n");
    write("A small armoured beetle. Has Purple wings and a blue head with\n");
    write("a small yellow design on its back in the shape of a butterfly.\n");
   write("The beetle vanishes under a piece of broken quartz.\n");
    mess = 0;
    return 1;
  }
  if(str == "at pyramid" || str == "pyramid")
  {
    say(this_player()->query_name()+" looks towards peak of pyramid.\n");
    write("Not much to see but a black peak of the pyramid rising\n");
    write("above the plane.\n");
    return 1;
  }
  if(str == "at giant pines" || str == "giant pines")
  {
    say(this_player()->query_name()+" looks at giant pines.\n");
    write("You see that pines are very healthy and look awesome with\n");
    write("their shiney crimson needles gleaming in the sunlight.\n");
    return 1;
  }
  if(str == "at mountains" || str == "mountains")
  {
    say(this_player()->query_name()+" looks at the distant mountains.\n");
    write("You look at the distant mountains. They are tall, new looking\n");
    write("mountains which haven't faced the elements for so long yet.\n");
    return 1;
  }
  if(str == "at trail" || str == "trail")
  {
    say(this_player()->query_name()+" looks down at the trail.\n");
    write("You see that many a creature has traveled this pathway. The\n");
    write("runs north to south.\n");
    return 1;
  }
}
