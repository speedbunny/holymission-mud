inherit "room/room";

reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc="Narrow path";
    long_desc=
"You are on a narrow path leading westward, away from the shore. To the \n"+
"southwest you recognize the silhouette of a sinister building.\n";
    dest_dir=({ "room/shore/s50","east",
                "room/shore/p02","west" });
    items= ({
       "building","Somehow you remember a castle looking at it",
       "silhuette","Strange, it seems to be the outline of the building",  
           });
}

