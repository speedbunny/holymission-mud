inherit "/players/figleaf/smurf/def_room";

void reset(int arg) {
  check="brainy";
  msg="Brainy sits at the desk poring over some large tome.";
  set_light(1);
  short_desc="Brainy smurf's house.";
  base_long_desc="This is Brainy smurf's house. The room is cluttered \
with books. They lay everywhere you look. Bookshelves line the walls \
except for one place where brainy has his bed. In the middle of the room \
is a desk that fairly groans under the weight of the books that sit on it.";

  dest_dir=({
    "/players/figleaf/smurf/smurf6","south",
           });

  items=({
    "room","The only room in the house",
    "books","There must be hundreds of books in all sizes and colors",
    "bookshelves", "They run almost the entire way around the room and \
are crammed full",
    "shelves","They run almost the entire way around the room and are \
crammed full",
    "bed","Brainy smurf's bed",
    "desk","The desk where Brainy does most of his reading",
    "tome","A huge book written in a language you don't understand",
        });

  clone_list=({
    1, 1, "brainy", "players/figleaf/smurf/beasties/brainy", 0,
    -1, 1, "glasses", "players/figleaf/smurf/things/glasses", 0,
             });

  ::reset(arg);
  replace_program("/players/figleaf/smurf/def_room");
}

