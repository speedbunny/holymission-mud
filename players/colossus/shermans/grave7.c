/* Edited by Colossus 030294 */

#pragma strict_types

inherit "room/room";

int dug;

void reset(int arg){
    dug=0;

    if (arg) return;
    set_light(1);
    short_desc = "At a grave with a peculiar aura of fear";
    long_desc=
    "In this part of the graveyard there is only one lone grave. The grave has\n"+
    "a tombstone shaped like a headboard with an inscription that reads: Anton\n"+
    "the Cook, may he rest in peace. There is a strong feeling of fear and of\n"+
    "malicious intent that eminates from that grave. Someone or something terrible\n"+
    "must be the cause of it. Here, the stench of rotting bodies is not as\n"+
    "prevalent as in other places.\n";
    items=({
      "grave", "The grave radiates fear and malicious intent like an aura. The\n"+
      "inscription on the grave reads: Anton the Cook, may he rest in peace",
      "tombstone", "A headboard-shaped tombstone reads: Anton the Cook, may he\n"+
      "rest in peace",
    });
    dest_dir=({
      "/players/sherman/grave4","south",
      "/players/sherman/grave8","east",
      "/players/sherman/grave10","north"
    });
    smell = "The smell of death and decay is thankfully not so overpowering here.";
}

status dig(){
    object mon,gh;
    if (present("ghost")) {
	write("The ghost stops your attempt.\n");
	say((string)this_player()->query_name()+
	  " tries to dig but the ghost stops him.\n");
	return 1;
    }
    if (!dug) {
	write("As you dig in the grave, a horrible ghost rises from it.\n");
	say((string)this_player()->query_name()+" disturbs an angry ghost.\n");
	move_object(gh=clone_object("/players/sherman/ghost"),this_object());
	mon=clone_object("/obj/money");
	mon->set_money(1000+random(1000));
	move_object(mon,gh);
	dug=1;
    } else {
	write("You dig a hole and find nothing.\n");
	say(this_player()->query_name() +" digs a hole and finds nothing.\n");
    }
    return 1;
}
