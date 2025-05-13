inherit "room/room";
reset(arg) {
    if (arg) return;
    set_light(1);
short_desc="Inside the mayor's house.";
long_desc=
"It appears that the oppulance of the mayor's house outside is\n"+
"not what the mayor wants for his private quarters as there is\n"+
"only a chair and a bed inside this single-roomed house.\n";
                "are a chair and a bed.\n";
    dest_dir=({
   });

    items = ({ "chair","A regular old chair. Does not look very comfortable",
               "bed","Small feather mattress over hard planks",
            });
    property = ({ "no_clean_up" });
}
