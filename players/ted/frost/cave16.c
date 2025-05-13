inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Marble Hallway";
    long_desc =
"The walls and floor are made of white marble. Carvings along\n"+
"the junction of floor and wall and on the pillars supporting\n"+
"the ceiling add an air of finery to your surroundings.\n";
    dest_dir = ({
"players/ted/frost/cave15", "southeast",
"players/ted/frost/guard", "west"
    });
    items = ({
"marble","Polished to a bright shine, this marble is cold to touch",
"carvings","Pretty ornamentation carven into the marble",
"pillars","These help support the ceiling"
    });
  }
}
