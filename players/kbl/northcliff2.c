/* Two squares north of Ole Man on High Cliff */
/* One square = 3.26 miles *grin* */


int mess;

reset(arg)
{
  if(arg)
   return;
  mess = 0;
}

short()
{
  return "High Cliff trail";
}

long()
{
int val;
  write(short()+".\n");
  write("You walk along the north/south trail. The Endless planes stretch\n");
  write("east while a sea of soft blue trees stretch as far as you can see\n");
  write("westward. To the south, you see a mountain range. Tall peaks rise\n");
  write("high above the plane and you see the cliff ends at the base of\n");
  write("these mountains. The strong smell of pine brings a great feeling.\n");
  write("You see the giant pines to the north look beautifully crimson\n");
  write("against the sea of soft blue trees.\n");
  write("Obvious exits are north and south.\n");
  val = random(16);
  if(val == 10)
   write("You hear a screechy noise, coming from the giant pine area.\n");
  if(val == 8)
   write("A large bird flies over head going north.\n");
  if(val == 6)
   write("A lizard checks out your foot.\n");
  if(val == 4)
  {
   write("You get a wirlwind of dust in your face.\n");
   say("You get a wirlwind of dust in your face.\n");
  }
  mess = val;
}

init()
{
  set_light(1);
  add_action("look_it","look");
  add_action("north","north");
  add_action("south","south");
  add_action("look_it","scan");
}

north()
{
  write("You leave north to...\n");
  this_player()->move_player("north#players/kbl/northcliff3");
  return 1;
}

south()
{
  write("You head south to...\n");
  this_player()->move_player("south#players/kbl/northcliff1");
  return 1;
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at plane" || str == "plane")
  {
    say(this_player()->query_name()+" scans the Endless plane.\n");
   write("You see nothing on the plane besides the short bluegreen grass.\n");
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
  if((str == "at lizard" || str == "lizard") && mess == 6)
  {
    say(this_player()->query_name()+" looks down at lizard.\n");
    write("You see a lime green lizard, with red eyes. Its darting tongue\n");
    write("seems to check out your foot. The lizard almost vanishes into\n");
    write("its surroundings by blending right into the quartz crystal!\n");
    mess = 0;
    return 1;
  }
  if(str == "at giant pines" || str == "giant pines")
  {
    say(this_player()->query_name()+" looks at giant pines.\n");
    write("You see that pines are very healthy and look awesome with\n");
    write("their shiney crimson needles gleaming in the sunlight.\n");
    write("The main trunk of the tree must be huge, to support the large\n");
    write("limbs that are brushing against the cliff. The giant pines are\n");
    write("heavily clustered with pine needles and in a definite pattern.\n");
    return 1;
  }
  if(str == "at mountains" || str == "mountains")
  {
    say(this_player()->query_name()+" looks at the distant mountains.\n");
    write("The distant mountains are not very well detailed from this\n");
   write("but the great snows on their peaks shine with the luminosity\n");
    write("of the sun.\n");
    return 1;
  }
  if(str == "at trail" || str == "trail")
  {
    say(this_player()->query_name()+" looks down at trail.\n");
    write("You see a very well worn trail running north to south.\n");
    write("Here and there you see chunks of shattered white crystal.\n");
    return 1;
  }
}
