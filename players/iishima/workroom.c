inherit "room/room";



void reset(int arg) {

    set_light(1);

    short_desc="Iishima's workroom";

    long_desc=
"This is the workroom of the Almighty, Peeping, Iishima.  He is an awesome "+
"kiwi. No, he is not from New Zealand and he is not a fruit. He is a BIRD!\n";
"Please be kind to him and pat him on the head sometimes and he will be happy.\n";

    dest_dir=({
               "room/post", "post",
               "room/church", "church",
               "room/adv_guild", "guild", 
               "/players/matt/newworld/city/rooms/votebooth", "vote",
             });

    property = ({
                 "no_teleport","no_sneak","no_steal","has_fire","no_fight",
               });

    ::reset(arg);
    replace_program("room/room");
}
