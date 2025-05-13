inherit "room/room";

object orc, weapon;
int i, n;

void reset(int arg) 
{
  i = 0;
  ::reset(arg);
  if(!arg) 
  {
    set_light(1);
    short_desc = "Cold Orc Fort";
    long_desc =
"The ground here is trampled and dirty. Tents and cooking\n"+
"fires lie scattered in a random array of chaos. The smell\n"+
"of burn food and unwashed bodies fills the air.\n";

    dest_dir = ({"players/tamina/teds/cold/cold_path", "south"});

  }

  if (!present("orc")) 
  {
    while(i < 4) 
    {
      i = i + 1;
      orc = clone_object("obj/monster");

      orc->set_name("cold orc");
      orc->set_race("orc");
      orc->set_long("An orc that is suited to colder weather.\n");
      orc->set_gender(1);
      orc->set_level(2 + random(3));
      orc->set_al(-60);

      n = random(3);
      switch(n)
      {
        case 0:
         weapon = clone_object("players/ted/weapons/orc_hand_axe");
         move_object(weapon, orc);
         orc->command("wield axe");
        break;
        case 1:
/*
         weapon = clone_object("players/ted/weapons/orc_scimitar");
         move_object(weapon, orc);
         orc->command("wield scimitar");
*/
        break;
        case 2:
         weapon = clone_object("players/ted/weapons/orc_short_sword");
         move_object(weapon, orc);
         orc->command("wield short sword");
        break;
      }
      move_object(orc, this_object());
    }
  }
}
