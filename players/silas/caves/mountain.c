inherit "room/room";
object ob;

reset(arg) {
  if (!ob) {
  ob = clone_object("players/silas/monster/rogliosi");
  move_object(ob,this_object());
  }
    if (arg) return;

    set_light(1);
    short_desc = "Roglosi's Room";
    no_castle_flag = 0;
    long_desc = 
        "This room is modeled to resemble a beautiful mountain landscape, complete\n"
        + "with towering mountains, alpine wildflowers and a wild mountain stream\n"
        + "rushing towards the valley. Cold winds chill you to the bone but you still\n"
        + "feel a sense of happiness as you gaze about.\n";
    dest_dir = 
        ({
        "/players/silas/caves/hall3", "west",
        });
    smell = "The wildflowers emanate a potpourri of fragrances.\n";
    ::reset();
    replace_program("room/room");
}

query_light() {
    return 1;
}
