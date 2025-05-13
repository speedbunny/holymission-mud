/* Edited by Colossus: 070994 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    int i;
    if (arg) return;
    set_light(0);
    short_desc = "The throne room of a Demonlord";
    long_desc=
    "You enter another part of the cave complex that is distinctly\n\
different from the others. A huge throne sits at the end of the\n\
room and two braziers are burning with a sickly green flame. On\n\
one of the walls is a huge black portal.\n";
    items=({ 
      "throne", "The throne is made of skulls and bones",
      "braziers", "The braziers are made of black iron and they burn with green\n"+
      "flame",
      "portal", "The portal is shiny black and it shows your reflection but\n\
upon touching the portal you cringe back as the forces\n\
from the negative plane sear your soul",
    });
    dest_dir=({
      "/players/sherman/hills/cave3","west"
    });
    clone_list = ({1,1, "demonlord", "/players/sherman/hills/demonlord", 0 });
    ::reset();
    replace_program("room/room");
}
