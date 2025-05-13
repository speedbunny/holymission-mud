/* Three squars north of Ole Man on High Cliff */
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
  return "Cliff near top of giant pine";
}

long()
{
int val;
object dark,leaf;
  write(short()+".\n");
  write("You see the top of a giant pine peaking over the cliff top. In\n");
  write("fact its 50 feet higher than the cliff. Its majestic limbs\n");
  write("gleam bright crimson in the sunlight. One the bigger branches\n");
  write("brushes up against the cliff here, maybe you can jump on to it.\n");
  write("Obvious exits are south and limb.\n");
  val = random(16);
  if(val == 10)
  write("You hear a loud screeching noise come from the pine tree.\n");
  if(val == 8)
   write("A large bird flies southward from pine tree.\n");
  if(val == 6)
 {
   say("You see a dark elf coming from the tree limb!\n");
   write("You see a dark elf coming from the tree limb!\n");
   dark = clone_object("players/kbl/objs/drow");
   transfer(dark,this_object());
   leaf = clone_object("players/kbl/objs/leaf");
   transfer(leaf,dark);
  transfer(clone_object("players/kbl/objs/blackheart"),dark);
   command("toss "+this_player()->query_real_name(),dark);
  }
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
  add_action("limb","limb");
  add_action("south","south");
  add_action("look_it","scan");
}

south()
{
  write("You leave south to...\n");
  this_player()->move_player("south#players/kbl/northcliff2");
  return 1;
}

limb()
{
  write("You jump onto limb.\n");
  this_player()->move_player("by jumping onto limb#players/kbl/pine/toplimb3");
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
  if((str == "at bird" || str == "bird") && mess == 8)
  {
   say(this_player()->query_name()+" looks at bird flying southward.\n");
    write("You see a giant vultur leave the giant pine and head south.\n");
    write("It seems to be following the cliff.\n");
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
