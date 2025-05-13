#define ALPH ({ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" })

inherit "room/room";

string *phrase;

reset(arg) {
  if(!present("demon")) {
    object t,o;
    move_object(t=clone_object("obj/monster"),this_object());
    t->set_name("demon");
    t->set_alias("fire demon");
    t->set_short("A massive fire demon guards his furnace");
    t->set_long("This is a massive fire demon. His skin seems almost to be burning itself,\n"
	+ "and he seems unbothered by the tremendous heat of the room in which he stands.\n");
    t->set_male();
    t->set_level(40);
    t->set_hp(2500);
    t->set_wc(40);
    t->set_chance(25);
    t->set_spell_dam(60);
    t->set_aggressive(1);
    t->set_al(-500);
    t->set_spell_mess1("Demon throws fire at his attacker.");
    t->set_spell_mess2("Demon throws fire at you.");
    move_object(o=clone_object("obj/armour"),t);
    o->set_type("ring");
    o->set_name("ring of fire");
    o->set_short("The Ring of Fire");
    o->set_long("This ring is reputed to protect against fire.\n");
    o->set_ac(1);
    o->set_weight(2);
    o->set_value(500);
    move_object(o=clone_object("obj/armour"),t);
    o->set_type("helmet");
    o->set_name("helmet");
    o->set_short("A large heavy helmet");
    o->set_long("This helmet is covered in sigils.\n");
    o->set_ac(1);
    o->set_weight(4);
    o->set_value(1000);
    move_object(o=clone_object("obj/weapon"),t);
    o->set_name("trident");
    o->set_short("A large flaming trident");
    o->set_long("This is a trident with the power of fire.\n");
    o->set_class(20);
    o->set_weight(7);
    o->set_value(4500);
    o->set_hit_func(this_object());
  }
  if(arg) return;
  set_light(1);
  short_desc="A huge fire-lit room";
  long_desc="The focus of this room is undoubtably a huge\n"
	+ "furnace that blows smoke and hot air everywhere.\n";
  dest_dir=({ "players/moonchild/cave/c12", "north",
	"players/moonchild/cave/c32", "south" });
  phrase=({ "Lightning is the power of God",
	"In death, one finds life",
	"The power of love is the power of life",
	"Earth, fire, air and water",
	"Fire Mountain is the source of the power of this world",
	"Ice is the symbol of purity",
	"The earthquake is a sign of God's wrath",
	"Insects are God's creatures too",
	"Humility is a lesson that cannot be learned too soon",
	"Tomorrow is just the day after today",
	"Hurrying is a way to hasten death",
	"An optimist is one who has yet to think about life",
	"Do not let anything come in the way of love",
	"The earth renews itself with gratitude",
	"The truth is unkind but necessary",
	"Purity is a virtue much underrated",
	"Fire is the destroyer, but also the creator",
	"Anything of power is also dangerous",
	"Only the impotent are free",
	"Being loved is a precious thing",
	"To sleep, perchance to dream",
	"Self-knowledge comes before self-doubt",
	"The power to do good is in the hands of the evil",
	"Silence and loneliness are ways to an end",
	"If music be the food of love, play on",
	"The end is never to be reached" });
}

id(str) { return str=="fire" || str=="furnace"; }

long(str) {
  if(str!="fire" && str!="furnace") return ::long(str);
  write("You see words forming in the " + str + ", reading:\n"
	+ query_password() + ".\n");
  return 1;
}

query_password() {
  return phrase[member_array(this_player()->query_real_name()[0..0],ALPH)];
}

weapon_hit(ob) {
  if(random(4)) return;
  write("The trident gushes forth fire.\n");
  say(ob->query_name() + " is hit by a blast of fire!\n");
  return 8;
}
