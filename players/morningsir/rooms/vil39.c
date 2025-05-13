inherit "/room/room";

#include "/players/morningsir/defs.h"

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="At a crossing.";
  long_desc=
    "You have arrived at a forest crossing. The north-eastern dirty road leads to\n" +
    "a rather dense forest partly growing on the north-western side of the hill\n" +
    "while the south-eastern road descends on the southern foot of it. There is also\n" +
    "a road which leads to village in the north-western direction. You can see vast\n" +
    "corn fields down in the south-east. There is a signpost with a sign.\n";

  dest_dir=({ PATHR + "vil38.c", "northwest",
              PATHR + "vil39.c", "northeast"
              PATHR + "vil39.c", "southeast"
             });

  items=({ "crossing", "It's a crossing of two forest roads and one western road leading to a village.",
           "village", "You can see smoke coming from the many village houses.",
           "road", "The road is more a forest path, but it's dry and wide.",
           "hill", "The hill is overgrown with a dense forest which seems unpassable.",
           "fields", "Yes, those fields are definitely corn fields and are rather large.",
           "signpost", "It's a ordinary wooden pole with a sign posted on it.",
           "sign", "It's a wooden sign and you could probably read it."
          });

  smell="You can feel a damp forest aroma.";

}

init() {
  ::init(); 
  add_action("read_sign", "read");
}

read_sign(string str1) {
  if (str1 != "sign") return;
  write("You read the sign:\n" +
        "       N                                              /\            /\      \n" +
        "     \ | /             /\    / \       /\    /\     /    \ /\  /\ /    \/\  \n" +
        "     --x--           / ~  \/ ~~  \/\ / ~~ \/ ~ ~\ / ~ ~~ ~ \~/ ~~ \~~ ~/ : \\n" +
        "     / | \         / ~~~~~  \~~~/~~/~ ~~ / ~ ~~~  \~ ~~ ~ ~/ ~~ ~ ~ \/ ~ |a \n" +
        "                                 Misty Mountains                         |n \n" +
        "                                                              /~\       / d \n" +
        "  Village     dark forest                       /~\       /~\ / \       | u \n" +
        "         \   /                              /~\ / \   /~\ / \  | /~\   /  i \n" +
        " .        [+]      @  @ @@@ @   @    @@@    / \  |/~\ / \  |  /~\/ \   :  n \n" +
        " ......      \     @  @  @  @   @   @        |    / \  |   /~\/ \ | /~\:    \n" +
        " ...........   \   @@@@  @  @   @    @@@  /~\  /~\ |   /~\ / \ |    / \     \n" +
        " ............   |  @  @  @  @   @       @ / \  / \ /~\ / \  |        |      \n" +
        " corn fields.   |  @  @ @@@ @@@ @@@ @@@@   |/~\ |  / \  | /~\   |^|     |^| \n" +
        " ...........    \                           / \ /~\ | /~\ / \|^||-|==|^| /| \n" +
        " ........         \              Green Forest|  / \   / \  | |-|=====|-|/ | \n" +
        " ...         Devil's lake            /~\     /~\ | /~\ |/~\  |  o   o  |  | \n" +
        "            /~~~~~~~~~~~~\           / \ /~\ / \   / \  / \  |o   _   o| /  \n" +
        "    /======|~~~~~~~~~~~~~~|====\      |  / \  |     |    |   |___(_)___|/   \n" +
        "====/       \~~~~~~~~~~~~/     \===\      |   /=======\                     \n" +
        "               --------            \==========/       \========....         \n" +
        "                                     Anduin                                 \n" +
        " This place is at [+]                                                       \n"
        );              
  say(TPN + " reads the sign on the signpost.\n");
  return 1;
}
