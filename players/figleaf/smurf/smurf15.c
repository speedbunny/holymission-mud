inherit "/players/figleaf/smurf/def_room";

void reset(int arg) {
  check="papa";
  msg="Papa smurf stands beside his desk scribbling in a small book.";
  set_light(1);
  short_desc="Papa smurf's house.";
  base_long_desc="This is Papa smurf's house. It is very tidy and \
organized. One area is his alchemy lab with a large table covered in \
beakers, flasks and retorts of various sizes and shapes. Against one \
part of the wall are shelves holding thick books and to the side of \
that is his bed.";

  dest_dir=({
    "/players/figleaf/smurf/smurf7","north",
           });

  items=({
    "room", "The only room in the house",
    "lab", "The area where Papa smurf conducts his experiments",
    "table", "A heavy wooden table",
    "beakers", "Glass beakers",
    "flasks", "Glass flasks",
    "retorts", "Tall stands holding flasks and beakers",
    "shelves", "Built to hold many heavy books",
    "books", "Thick books, well used",
    "bed", "Papa smurf's bed",
    "book", "A little notebook that Papa smurf records his observations in",
        });

  clone_list=({
    1, 1, "papa", "players/figleaf/smurf/beasties/papa", 0,
    -1, 1, "cane", "players/figleaf/smurf/things/cane", 0,
             });

  ::reset(arg);
  replace_program("/players/figleaf/smurf/def_room");
}

