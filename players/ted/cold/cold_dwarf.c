inherit "room/room";

object orc, weapon;
int i, n;

reset(arg) {
 i = 0;
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Cold Orc Fort";
    long_desc =
"The ground here is trampled and dirty. Tents and cooking\n"+
"fires lie scattered in a random array of chaos. The smell\n"+
"of burn food and unwashed bodies fills the air.\n";
    dest_dir = ({"players/ted/cold/cold_path", "south"});
  }
 if(!present("orc")) {
   while(i < 4) {
   i = i + 1;
   orc = clone_object("players/ted/monsters/cold_orc");
   move_object(orc, this_object());
   n = random(3);
   if(n == 0) {
     weapon = clone_object("players/ted/weapons/orc_hand_axe");
     move_object(weapon, orc);
     call_other(orc,"init_command","wield axe");
   }
   if(n == 1) {
     weapon = clone_object("players/ted/weapons/orc_scimitar");
     move_object(weapon,orc);
     call_other(orc,"init_command","wield scimitar");
   }
   if(n == 2) {
     weapon = clone_object("players/ted/weapons/orc_short_sword");
     move_object(weapon,orc);
     call_other(orc,"init_command","wield short sword");
   }
  }
 }
}
