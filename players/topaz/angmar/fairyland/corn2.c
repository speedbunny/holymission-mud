/* 12.11.93 Airborne: Change to room/room */

inherit "room/room";
 object scarecrow, corncob;

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc =  "In a cornfield";
  long_desc =
	"You are in a large cornfield. It is full of corn plants.\n";
  dest_dir = ({ "players/topaz/angmar/fairyland/corn1", "south" });

  if(!scarecrow||!living(scarecrow)) {
    object boots;
    scarecrow=clone_object("obj/monster");
    scarecrow->set_name("scarecrow");
    scarecrow->set_level(5);
    scarecrow->set_hp(80);
    scarecrow->set_wc(10);
    scarecrow->set_short("A scarecrow");
    scarecrow->set_long(
         "He is seeing to that nobody steals the corns...\n");
    scarecrow->set_al(-10);
    
    boots=clone_object("obj/armour");
    boots->set_name("boots");
    boots->set_short("A pair of waterproofed boots");
    boots->set_alias("waterproofed boots");
    boots->set_value(40);
    boots->set_weight(1);
    boots->set_ac(0);
    boots->set_type("boot");
    move_object(boots, scarecrow);
    move_object(scarecrow, this_object());
  }

  if(!present("corncob")) {
    object corncob;
    corncob=clone_object("obj/food");
    corncob->set_id("corncob");
    corncob->set_short("A corncob");
    corncob->set_long(
        "It still seems ok. You could probably eat it.\n");
    corncob->set_alias("corncob");
    corncob->set_alt_name("cob");
    corncob->set_value(10);
    corncob->set_strength(5);
    corncob->set_eater_mess("Ahh! Corn on the cob is good!.\n");
    move_object(corncob, this_object());
  }
}

init() {
 ::init();
  add_action("get", "get");
  add_action("get", "take");
}


get(str) {
  string who;
  if(!present("corncob") || (str!="corncob" && str!="cob" && str!="all") ||
     !present("scarecrow")) return 0;
  
  who=this_player()->query_name(0);
  if(!who) who=" ";
  write("The scarecrow notices your attempt to\n"+
        "steal the corn and grabs your hand!\n");
  say("The scarecrow notices "+who+"'s attempt to\n"+
      "steal the corn and grabs his hand!\n");
  present("scarecrow")->attacked_by(this_player());
  return 1;
}  
