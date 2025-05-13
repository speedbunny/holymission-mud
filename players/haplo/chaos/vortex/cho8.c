/* DOC bunk room */

inherit "room/room";
reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "A natural dark crystal cave `bunk' room";
    long_desc = "Flat outcroppings of crystal double as beds for DOC. You\n"+
                "see only four such beds or bunks. The whole room seems\n"+
                "to glow a brightgreen and it feels very warm here. Your\n"+
                "skin crawls from all the static electricity, everything\n"+
                "you go near gives you a snap!\n";
    dest_dir = ({"players/kbl/chaos/cho7","up",
                 "players/kbl/chaos/cho9","down"});
    smell = "intense lemon odor";
    property = "no_steal","no_hide";
  }
}

init()
{
  ::init();
  add_action("search","search");
  add_action("look_it","look");
  add_action("look_it","scan");
}

search(str)
{
  object doc;
  int val;

  if(!str)
   return;
  if(str == "lower bed" || str == "Lower bed")
  {
    val = random(30);
    if(val > 28)
    {
      doc = clone_object("obj/monster");
      fix_up(doc);
      transfer(doc,this_object());
      write("A DOC comes from under a crystal covering and attacks!\n");
      say("A DOC comes from under a crystal covering on lower bed.\n");
      return 1;
    }
    write("You find a dark crystal bed covering, a sheet of crystal shaped\n");
    write("like a cape. Its actually part of the bed, not just laided on.\n");
    write("You cannot remove it.\n");
    say(this_player()->query_name()+" looks in lower bed, but finds nothing.\n");
    return 1;
  }
  if(str == "mid bed" || str == "Mid bed")
  {
    val = random(30);
    if(val > 27)
    {
      doc = clone_object("obj/monster");
      fix_up(doc);
      transfer(doc,this_object());
      write("DOC jumps out from under a covering and attacks!\n");
      say("DOC jumps out from under a covering on mid bed.\n");
      return 1;
    }
    write("A little larger than the lower bed but same configuration.\n");
    say(this_player()->query_name()+" finds nothing in mid bed.\n");
    return 1;
  }
  if(str == "upper bed" || str == "Upper bed")
  {
    val = random(30);
    if(val > 25)
    {
      doc = clone_object("obj/monster");
      fix_up(doc);
      transfer(doc,this_object());
      write("You disturbed a sleeping DOC!\n");
      say(this_player()->query_name()+" disturbed a sleeping DOC!\n");
      return 1;
    }
    write("You find nothing in upper bed.\n");
    say(this_player()->query_name()+" finds nothing in upper bed.\n");
    return 1;
  }
  if(str == "left upper bed" || str == "Left upper bed")
  {
    val = random(30);
    if(val > 24)
    {
      doc = clone_object("obj/monster");
      fix_up(doc);
      transfer(doc,this_object());
      write("DOC comes screeming out from under a covering!\n");
      say("DOC comes screeming out from under a covering!\n");
      return 1;
    }
   write("You see nothing here but this be is the largest of the four.\n");
    say(this_player()->query_name()+" searchs upper right bed in vain.\n");
    return 1;
  }
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at lower bed" || str == "lower bed")
  {
    say(this_player()->query_name()+" looks at lower bed.\n");
    write("A bed of dark crystal shards that glows green. Maybe there's\n");
    write("something under that covering. This bed is 2 feet of the ground.\n");
    return 1;
  }
  if(str == "at mid bed" || str == "mid bed")
  {
    say(this_player()->query_name()+" looks at mid bed.\n");
    write("This bed is a little bigger than the lower bed. Glows a little\n");
    write("brighter green and the crystal bed is 3 feet/90.44cm tall.\n");
    return 1;
  }
  if(str == "at upper bed" || str == "upper bed")
  {
    say(this_player()->query_name()+" looks at upper bed.\n");
    write("This bed of crystal is 4 feet/120.92cm tall and glows a bright\n");
    write("sickening green.\n");
    return 1;
  }
  if(str == "at upper left bed" || str == "upper left bed")
  {
    say(this_player()->query_name()+" scans upper right bed.\n");
    write("This is a huge bed of crystal approximately 5 feet/151.4cm tall.\n");
    write("This bed of crystal is multicolored, dark, blue and purple\n");
    write("crystal. This bed was specially enhanced, but by whom? DOC?\n");
    return 1;
  }
  if(str == "at beds" || str == "at bed" || str == "bed" || str == "beds"
   || str == "at bunk" || str == "at bunks" || str == "bunk" || str == "bunks")
  {
    say(this_player()->query_name()+" scans the beds.\n");
    write("There's a lower bed, mid bed, upper bed and upper left bed.\n");
    return 1;
  }
  if(str == "at walls" || str == "walls")
  {
    say(this_player()->query_name()+" look around at the walls.\n");
    write("You see the energy of this place bounching around the cracks\n");
    write("and crannies of the crystal structures on the walls of this\n");
    write("naturally formed room. No real passageways noticeable.\n");
    return 1;
  }
}

fix_up(doc)
{
int val;
  doc->set_name("Demon Of Chaos");
  doc->set_alias("doc");
  doc->set_alt_name("demon");
  doc->set_level(random(19)+21);
  doc->set_hp(random(150)+220);
  doc->set_sp(random(100)+150);
  doc->set_race("krajar");
  doc->set_gender(random(2));
  doc->set_al(-2000);
  doc->set_aggressive(1);
  doc->set_str(random(25)+15);
  doc->set_dex(random(30)+15);
  doc->set_int(random(20)+15);
  doc->set_wis(random(15)+15);
  doc->set_con(random(30)+15);
  doc->set_chr(random(3)+8);
  doc->set_whimpy(50);
  doc->set_ac(random(15)+15);
  doc->set_wc(random(20)+15);
  val = random(5);
  if(val == 1)
   doc->set_short("Lower Demon Of Chaos");
  if(val == 2)
   doc->set_short("Worker Demon Of Chaos");
  if(val == 3)
   doc->set_short("Guard Demon Of Chaos");
  if(val == 4)
   doc->set_short("Lower Demon Of Chaos");
  if(val == 5)
   doc->set_short("High DOC");
  if(val == 0)
   doc->set_short("Worker Demon Of Chaos");
  doc->set_long("You typical DOC. Sharpe claws, tall lean musclar look.\n"+
                "It has a daring glare in its eyes for you!\n");
  doc->set_chance(random(10)+5);
  doc->set_spell_mess1("DOC slams you a good one!");
  doc->set_spell_mess2("DOC roundhouse kicks you silly!");
  doc->set_spell_dam(20);
}
