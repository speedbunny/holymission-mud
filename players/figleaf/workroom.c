#define NAME "figleaf"
inherit "room/room";

#define CNAME   capitalize(NAME)

void reset(int arg) {
    set_light(1);
    short_desc=CNAME + "'s workroom",
    long_desc=
              "This is the office of the HM deputy sheriff, Figleaf. There's\n"+
              "not much in here besides his desk and chair. There's\n"+
              "some clutter on his desk, but the rest of the room is\n"+
              "immaculate. If you need him to know something, either\n"+
              "mail him or post on the conveniently placed board.\n";
    dest_dir=({
               "room/post", "post",
               "room/church", "church",
               "room/adv_guild", "guild", 
               "players/exos/rooms/player_office", "sheriff",
               "players/matt/newworld/city/rooms/votebooth", "booth",
             });
   clone_list=({ 1, 1, "board", "boards/private_boards/figleaf", 0, });

    items=({ 
            "desk","A large rosewood desk.",
            "chair","A comfy, dark green leather chair.",
          });
    property = ({
                 "no_sneak","no_steal"
               });
    ::reset(arg);
    replace_program("room/room");

}
init() {
    ::init();
    add_action("_blah","blah");
}
