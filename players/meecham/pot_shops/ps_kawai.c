inherit "/players/meecham/pot_shops/apothecary";
#define PMI "/players/meecham/items/"

void reset(status arg) {
  set_alch_name("rasputin");
  set_alch_file("players/meecham/monsters/alchemists/rasputin");
  add_potion("minor mana",PMI + "minor_mana",1500,20);
  add_potion("major mana",PMI + "major_mana",4000,20);
  add_potion("minor healing",PMI + "minor_healing",1500,20);
  add_potion("major healing",PMI + "major_healing",4000,20);
  add_potion("minor restoration",PMI + "minor_restoration",2500,20);
  add_potion("major restoration",PMI + "major_restoration",6000,20);
  ::reset();
  dest_dir = ({
    "/players/kawai/areas/dwarves/village29","east"
  });
}
