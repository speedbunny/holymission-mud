inherit "room/room";
reset(arg) {
  if(arg) return 0;
  set_light(1);
    short_desc="Stanley's War Room";
  long_desc=
    "This is where Stanley fights other wizard's monsters.\n"
    "This is evidenced by the different types of fighting equipment seen\n"
    "strewn around the floor. Deep cuts can be seen in the walls, and the floor\n"

    "is stained with blood from some of Stanley's more serious wounds.\n"+
        " ";

    dest_dir=({
    "/players/stanley/testing/room1","up",
                                            });

items=({
        "floor","Permanantly stained by the blood of Stanley's more serious wounds",
        "ceiling","This is a high dome, mostly hidden in shadow",
        "cuts","Probably from a weapon of some kind",
        "cut","You have a cut? Need a band-aid?",
        "cut in wall","Oooooh! I thought you meant you had a cut!\n"+
        "I was going to offer you a band-aid!",
        "cuts in walls","Could be from some sort of weapon",
        "equipment","Most of it is ruined. Actually, to be honest, all of it is ruined",
        "blood","However it got there, it had to be painful",
        "stains","You can tell from the scrub marks that someone tried a stain remover",
        "stain","You can tell from the scrub marks that someone tried a stain remover",
                                    });

}
init(string str) {
  ::init();
  add_action("stick","put");
   add_action("stick","stick");
}
int stick(string str) {
  if(str=="finger in cut" || str=="head in cut")
  write("A grating noise is heard under your feet.\n");
return 1;
}
