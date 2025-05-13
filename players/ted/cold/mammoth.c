inherit "room/room";

object mammoth, tusk;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Frozen Wasteland";
    long_desc =
"There is nothing as far as the eye can see\n"+
"except snow and ice.\n";
    dest_dir = ({
"players/ted/cold/snow", "north"
    });
  }
  if(!present("mammoth")) {
    mammoth = clone_object("players/ted/monsters/mammoth");
    move_object(mammoth, this_object());
    tusk = clone_object("obj/treasure");
    call_other(tusk, "set_id", "tusk");
    call_other(tusk, "set_short", "A valuable ivory mammoth tusk");
    call_other(tusk, "set_alias", "tusk");
    call_other(tusk, "set_value", 400 );
    call_other(tusk, "set_weight", 5 );
    move_object(tusk, mammoth);
  }
}
