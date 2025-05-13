#define NAME "emerald"
inherit "room/room";

#define CNAME   capitalize(NAME)
void reset(int arg) {

    set_light(1);

    short_desc=CNAME + "'s workroom",

    long_desc=
              "In the brilliant early morning sunlight, you find the elf\n"+
               "quietly sitting among her herbs, strumming a golden harp.\n";

    dest_dir=({
               "room/post", "post",
               "room/church", "church",
               "room/adv_guild", "guild", 
               "players/emerald/castle/rooms/stair", "area",
               "/players/emerald/quest/pond","pond",
             });

    items=({ 
            "elf","Sharp, intelligent eyes meet your gaze",
             "herbs","A riotous profusion of healing and culinary herbs",
             "harp","Golden-strung with a beautiful, full, rich tone",
          });

    property = ({
                 "no_teleport","no_sneak","no_steal",
               });

    ::reset(arg);
    replace_program("room/room");
}
