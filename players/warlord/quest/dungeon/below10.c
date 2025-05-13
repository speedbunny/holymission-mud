#define TPN this_player()-query_name()
inherit"players/warlord/NEWSTUFF/room";
object drag,orb,corpse;
reset(arg) {
if (!drag) {
drag=clone_object("obj/monster");
drag->set_name("graymore");
drag->set_race("questdragon");
drag->set_alias("dragon");
drag->load_chat(20,({
"Graymore says: So you think you can Venquish me huh?\n",
"Graymore grunts: You will die for waking me!\n",
"Graymore falls down laughing saying: You are too puny!!\n",
}));
drag->set_short("Graymore the Mighty");
drag->set_long("This is a very large and powerful dragon\n");
drag->set_level(random(17)+17);
drag->set_dead_ob(this_object());
move_object(drag,this_object());
}

if (arg) return;
set_light(0);
short_desc="Dragon room";
long_desc="There is a large creature snoring in the corner.\n"+
          "Try not to wake him...Oops too late. He gets up and \n"+
          "looks at you. He looks mad.\n";
dest_dir=({
"/players/warlord/quest/dungeon/below7","up",
});
}
monster_died(drag) {
  if (!present("orb")) {
orb=clone_object("obj/thing");
orb->set_name("black orb");
orb->set_alias("orb");
orb->set_alt_name("quest_object_warlord");
orb->set_short("Black Orb");
orb->set_long("This is a black orb, it seems to be magical.\n");
orb->set_weight(2);
orb->set_value(0);
move_object(orb,this_object());
write("The ground shakes and the dragon's dead body disappears. In its \n"+
      "place is a black orb\n");
}

/* Changed by Herp: 
   1) destruct the monster
   2) return 1 to indicate that no corpse has to be cloned
*/

destruct(drag);
return 1;

}
