#pragma strict_types

inherit "room/room";

void reset(int arg) {
  if (arg)
    return;
  set_light(1);
  short_desc = "The top of the stairs";
  long_desc = "You are standing at the top of a set of spiral stairs,"
    + " dust motes dance before you where your footfalls have kicked "
    + "up small puffs of dust. To the north you can see a bedroom.\n";
  dest_dir = ({
    "players/paris/house/inside1", "down",
    "players/paris/house/bedroom", "north",
  });
  items = ({
    "stairs", "An ornate spiral staircase.",
    "staircase", "An ornate spiral staircase.",
    "spiral staircase", "An ornate spiral staircase.",
    "air", "Motes of dust dance in the light.",
    "dust", "Ooooh, no one looks as if they have cleaned in here for years.",
    "panels", "Heavy oaken panels, you can't make out what they depict.",
  });
  smell = "All the dust in the air makes you want to sneeze\nAcchoooo!\n";
  ::reset(arg);
  replace_program("room/room");
}




