/* Edited by Colossus 030494 */

#pragma strict_types

inherit "obj/weapon";

void reset(int arg){
    ::reset(arg);
    if (arg) return;
    set_name("shovel");
    set_weight(1);
    set_value(100);
    set_short("Old and rusty shovel");
    set_long(
      "The shovel has definitely seen some use and abuse from the\n"+
      "time it was created till now. The metal spade head is rusted\n"+
      "but still looks like good enough to penetrate the soil and\n"+
      "fulfill its purpose. The handle's wood is rotting and soft\n"+
      "but it might be good for a few more digs.\n");
    set_type(0);
    set_class(10);
}

void init(){
    ::init();
    add_action("dig","dig");
}

status dig(string arg){
    if (this_player() != environment(this_object())) return(0);
    if (!environment(this_player())->dig()) {
	write("You dig a hole, just for the hell of it.\n");
	say((string)this_player()->query_name()+" desperately tries to "+
	  "dig a hole here and finds nothing.\n");
    }
    return(1);
}
